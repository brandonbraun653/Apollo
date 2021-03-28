/**
 *   @file  evmDRA7xx_pinmux.c
 *
 *   @brief
 *      This is the pin configuration for evmDRA7xx.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2018, Texas Instruments, Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \par
*/

#include <ti/csl/cslr_device.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include "evmDRA7xx_pinmux.h"
#include "board_internal.h"
#include "iodelay_config.h"

#define IO_DELAY
#define IO_DELAY_STACK_SIZE 128
extern void Board_ioStack(void *sp, void(fn)(const boardPadDelayCfg_t * pPadCfgData,
                                             uint32_t padArraySize), const boardPadDelayCfg_t *pPadCfgData,
                          uint32_t padArraySize);

/**
 * \brief  Temporary stack used for IO delay code
 */
#if defined(_TMS320C6X)
#    pragma DATA_SECTION (ioStack, "BOARD_IO_DELAY_DATA");
far uint32_t ioStack[IO_DELAY_STACK_SIZE];
#elif defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (ioStack, "BOARD_IO_DELAY_DATA");
uint32_t ioStack[IO_DELAY_STACK_SIZE];
#else
uint32_t ioStack[IO_DELAY_STACK_SIZE] __attribute__((section("BOARD_IO_DELAY_DATA")));
#endif

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (boardGetPinmuxCfg, "BOARD_IO_DELAY_CODE");
mmcBoardPadCfgTable_t *boardGetPinmuxCfg(mmcBoardPadCfgTable_t *ptr, int32_t mode);
#else
mmcBoardPadCfgTable_t *boardGetPinmuxCfg(mmcBoardPadCfgTable_t *ptr, int32_t mode)
__attribute__((section("BOARD_IO_DELAY_CODE")));
#endif


extern const boardPadDelayCfg_t pad_1_0[];
extern const boardPadDelayCfg_t pad_2_0[];
const boardPadDelayCfg_t *pad;

Board_STATUS Board_pinmuxConfig(void)
{
    uint32_t size, regVal;
    volatile uint32_t siliconRev = Board_getSiliconRev();

    /* i890: MMC1 IOs and PBIAS Must Be Powered-Up before Isolation:
     * Power-up the MMC1 IOs and PBIAS before starting the Isolation Sequence. This can be
     * done by setting the CTRL_CORE_CONTROL_PBIAS[27] SDCARD_BIAS_PWRDNZ
     * and CTRL_CORE_CONTROL_PBIAS[26] SDCARD_IO_PWRDNZ bits to 1.
     */
    CSL_control_core_padRegs *hCtrlCorePad =
        (CSL_control_core_padRegs *)SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE;
    regVal     = hCtrlCorePad->CONTROL_PBIAS;
    CSL_FINST(regVal, CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ, DISABLE);
    CSL_FINST(regVal, CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_IO_PWRDNZ, DISABLE);
    hCtrlCorePad->CONTROL_PBIAS = regVal;

    /* Check to make sure IO Delay stack and functions are in local memory */
    if (((uint32_t) & ioStack >= 0x80000000) ||
        ((uint32_t)BoardCtrlPadIoDelayConfig >= 0x80000000))
    {
        return BOARD_PINMUX_BAD_MEM_REGION;
    }

    pad = boardPadGetCfg(&size);

#if defined (_TMS320C6X) || defined (__TI_ARM_V7M4__)
    Board_ioStack(ioStack + IO_DELAY_STACK_SIZE, BoardCtrlPadIoDelayConfig, pad, size);
#else /* __ARM_ARCH_7A__ */
    asm ("STR r13, [%0]\n" ::"r" (&ioStack[IO_DELAY_STACK_SIZE - 1]));
    asm ("MOV r13, %0\n" ::"r" (&ioStack[IO_DELAY_STACK_SIZE - 2]));
    /* Configure the pinmux and virtual/manual timing modes for all pads. */
    BoardCtrlPadIoDelayConfig(pad, size);
    asm ("MOV r13, %0\n" ::"r" (ioStack[IO_DELAY_STACK_SIZE - 1]));
#endif /* End of IO Delay config with relocation */

    /* Disable RGMII half cycle delay for ES2.0 silicon */
    if (2U <= siliconRev)
    {
#if  defined (SOC_DRA72x) || defined (SOC_DRA75x)
        HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                      CTRL_CORE_SMA_SW_1,
                      CTRL_CORE_SMA_SW_1_RGMII2_ID_MODE_N,
                      0x1U);

        HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                      CTRL_CORE_SMA_SW_1,
                      CTRL_CORE_SMA_SW_1_RGMII1_ID_MODE_N,
                      0x1U);
#endif
    }


    return BOARD_SOK;
}

int32_t BoardMmcCtrlPadConfig(int32_t mode, uint32_t instance)
{
    mmcBoardPadCfgTable_t *pinmuxCfgTbl = NULL;
    mmcBoardPadCfgTable_t *ctrlPadCfg   = NULL;
    uint32_t regVal;

    /* Get the pointer to the table containing the MMC runtime config table */
    pinmuxCfgTbl = BoardGetMmcCtrlPadPinmuxTable(instance);

    /* Get the pointer to the MMC configuration mode pin mux configuration */
    ctrlPadCfg = boardGetPinmuxCfg(pinmuxCfgTbl, mode);

    if (ctrlPadCfg != NULL)
    {
        /* i890: MMC1 IOs and PBIAS Must Be Powered-Up before Isolation:
         * Power-up the MMC1 IOs and PBIAS before starting the Isolation Sequence. This can be
         * done by setting the CTRL_CORE_CONTROL_PBIAS[27] SDCARD_BIAS_PWRDNZ
         * and CTRL_CORE_CONTROL_PBIAS[26] SDCARD_IO_PWRDNZ bits to 1.
         */
        CSL_control_core_padRegs *hCtrlCorePad =
            (CSL_control_core_padRegs *)SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE;
        regVal     = hCtrlCorePad->CONTROL_PBIAS;

        CSL_FINST(regVal, CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ, DISABLE);
        CSL_FINST(regVal, CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_IO_PWRDNZ, DISABLE);
        hCtrlCorePad->CONTROL_PBIAS = regVal;

        /* Check to make sure IO Delay stack and functions are in local memory */
        if (((uint32_t)&ioStack >= 0x80000000) || ((uint32_t)BoardCtrlPadIoDelayConfig >= 0x80000000))
            return BOARD_PINMUX_BAD_MEM_REGION;

#if defined(_TMS320C6X) || defined (__TI_ARM_V7M4__)
        Board_ioStack(ioStack + IO_DELAY_STACK_SIZE,
                      BoardCtrlPadIoDelayConfig,
                      ctrlPadCfg->mmcPadCfg,
                      ctrlPadCfg->noPins);
#else /* __ARM_ARCH_7A__ */
        asm ("STR r13, [%0]\n" ::"r" (&ioStack[IO_DELAY_STACK_SIZE - 1]));
        asm ("MOV r13, %0\n" ::"r" (&ioStack[IO_DELAY_STACK_SIZE - 2]));
        /* Configure the pinmux and virtual/manual timing modes for all pads. */
        BoardCtrlPadIoDelayConfig(ctrlPadCfg->mmcPadCfg, ctrlPadCfg->noPins);
        asm ("MOV r13, %0\n" ::"r" (ioStack[IO_DELAY_STACK_SIZE - 1]));
#endif /* End of IO Delay config with relocation */
    }
    else
    {
        return BOARD_PINMUX_INVALID_MODE;
    }

    return BOARD_SOK;
}

mmcBoardPadCfgTable_t *boardGetPinmuxCfg(mmcBoardPadCfgTable_t *ptr, int32_t mode)
{
    mmcBoardPadCfgTable_t *padCfg = NULL;

    while (ptr->mmcMode != MMC_MODE_INVALID)
    {
        if ((mode == ptr->mmcMode) && (ptr->mmcPadCfg != NULL))
        {
            padCfg = ptr;
            break;
        }

        ptr++;
    }

    return padCfg;
}

MMCSD_Error MMCSD_iodelayFxn(uint32_t instanceNum, MMCSD_v1_IodelayParams *iodelayParams)
{
    Int32 mmcMode = MMC_MODE_INVALID;

    switch (instanceNum)
    {
        case 1:

            if ((MMCSD_LOOPBACK_ANY == iodelayParams->loopBackType) ||
                (MMCSD_LOOPBACK_PAD == iodelayParams->loopBackType))
            {
                if (MMCSD_TRANSPEED_DEFAULT == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_DEFAULT_PLB;
                }
                else if (MMCSD_TRANSPEED_HS == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_HS_PLB;
                }
                else if (MMCSD_TRANSPEED_SDR12 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR12_PLB;
                }
                else if (MMCSD_TRANSPEED_SDR50 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR50_PLB;
                }
                else if (MMCSD_TRANSPEED_DDR50 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_DDR50_PLB;
                }
                else if (MMCSD_TRANSPEED_SDR104 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR104;
                }
            }

            if (MMCSD_LOOPBACK_INTERNAL == iodelayParams->loopBackType)
            {
                if (MMCSD_TRANSPEED_DDR50 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_DDR50_ILB;
                }
                else if (MMCSD_TRANSPEED_DEFAULT == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_DS_ILB;
                }
                else if (MMCSD_TRANSPEED_HS == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_HS_ILB;
                }
                else if (MMCSD_TRANSPEED_SDR12 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR12_ILB;
                }
                else if (MMCSD_TRANSPEED_SDR25 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR25_ILB;
                }
                else if (MMCSD_TRANSPEED_SDR50 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC1_SDR50_ILB;
                }
            }

            break;

        case 2:

            if ((MMCSD_LOOPBACK_ANY == iodelayParams->loopBackType) ||
                (MMCSD_LOOPBACK_PAD == iodelayParams->loopBackType))
            {
                if (MMCSD_TRANSPEED_DEFAULT == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC2_DEFAULT_STD_PLB;
                }
                else if (MMCSD_TRANSPEED_HS == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC2_DEFAULT_HS_PLB;
                }
                else if (MMCSD_TRANSPEED_HS200 == iodelayParams->transferSpeed)
                {
                    mmcMode = MMC2_HS200;
                }
            }

            if (MMCSD_LOOPBACK_INTERNAL == iodelayParams->loopBackType)
            {
                mmcMode = MMC2_DDR_ILB;
            }
            else
            {
                mmcMode = MMC2_DDR_PLB;
            }

            break;

        case 3:

            if (MMCSD_TRANSPEED_DEFAULT == iodelayParams->transferSpeed)
            {
                mmcMode = MMC3_DS;
            }
            else if (MMCSD_TRANSPEED_HS == iodelayParams->transferSpeed)
            {
                mmcMode = MMC3_HS;
            }
            else if (MMCSD_TRANSPEED_SDR12 == iodelayParams->transferSpeed)
            {
                mmcMode = MMC3_SDR12;
            }
            else if (MMCSD_TRANSPEED_SDR25 == iodelayParams->transferSpeed)
            {
                mmcMode = MMC3_SDR25;
            }
            else if (MMCSD_TRANSPEED_DDR50 == iodelayParams->transferSpeed)
            {
                mmcMode = MMC3_SDR50;
            }

            break;

        case 4:

            if (MMCSD_TRANSPEED_DEFAULT == iodelayParams->transferSpeed)
            {
                mmcMode = MMC4_DS;
            }
            else if (MMCSD_TRANSPEED_HS == iodelayParams->transferSpeed)
            {
                mmcMode = MMC4_HS;
            }
            else if (MMCSD_TRANSPEED_SDR12 == iodelayParams->transferSpeed)
            {
                mmcMode = MMC4_SDR12;
            }
            else if (MMCSD_TRANSPEED_SDR25 == iodelayParams->transferSpeed)
            {
                mmcMode = MMC4_SDR25;
            }

            break;

        default:
            break;
    }

    if (MMC_MODE_INVALID != mmcMode)
    {
        BoardMmcCtrlPadConfig(mmcMode, instanceNum - 1);
    }

    return MMCSD_OK;
}
