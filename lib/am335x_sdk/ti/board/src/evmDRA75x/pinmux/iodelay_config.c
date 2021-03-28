/**
 *  \file   iodelay_config.c
 *
 *  \brief  This file contain main function, call the Soc Init
 *          functions & slave core boot-up functions in sequence.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdint.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/soc/dra75x/cslr_device_prm.h>
#include <ti/csl/soc/am572x/src/cslr_control_core.h>
#include <ti/csl/soc/am572x/src/cslr_iodelayconfig.h>
#include "iodelay_config.h"

/**
* \brief   This function configures the SoC PAD Mux as given by Pinmux tool
*          with Virtual and Manual mode delays.
*
* \param   pPadCfgData     Pointer to the global data structure.
*
*/
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (BoardCtrlPadMux, "BOARD_IO_DELAY_CODE");
void BoardCtrlPadMux(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize);
#else
void BoardCtrlPadMux(const boardPadDelayCfg_t *pPadCfgData,
                     uint32_t padArraySize) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

/**
 * \brief   This function calculates the final value to be written to
 *          configuration register using aDelay and gDelay values.
 *
 * \param   aDelay          Value of A delay.
 * \param   gDelay          Value of G Delay.
 * \param   cpde            CPDE Value as previously calculated
 * \param   fpde            FPDE value as previously calculated
 *
 * \return  configRegValue  Calculated Config Register Value
 */
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (calculateConfigRegister, "BOARD_IO_DELAY_CODE");
static uint32_t calculateConfigRegister(uint32_t aDelay, uint32_t gDelay, uint32_t cpde, uint32_t fpde);
#else
static uint32_t calculateConfigRegister(uint32_t aDelay, uint32_t gDelay, uint32_t cpde,
                                        uint32_t fpde) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

/**
 * \brief   This function calculates the delay value for CPDE and FDPE.
 *
 * \param   configRegOffset   Offset Address of Config Register.
 *                            Possible Values:CONFIG_REG_3/CONFIG_REG_4
 * \param   divisorValue      Value of the divisor
 *                            Possible Values: 88  for CONFIG_REG_3
 *                                           264 for CONFIG_REG_4
 *
 * \return  delayVal          Calculated Delay Value
 */
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (calculateDelay, "BOARD_IO_DELAY_CODE");
static uint32_t calculateDelay(uint32_t configRegValue, uint32_t divisorValue);
#else
static uint32_t calculateDelay(uint32_t configRegValue,
                               uint32_t divisorValue) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

/**
 * \brief   This function initiates the steps required to perform IO isolation
 *          during IO Delay recalibration sequence.
 *
 */
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (boardPadIoIsolation, "BOARD_IO_DELAY_CODE");
static void boardPadIoIsolation(void);
#else
static void boardPadIoIsolation(void) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

/**
 * \brief   This function initiates the steps required to perform IO de-isolation
 *          during IO Delay recalibration sequence.
 */
#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma CODE_SECTION (boardPadIoDeIsolation, "BOARD_IO_DELAY_CODE");
static void boardPadIoDeIsolation(void);
#else
static void boardPadIoDeIsolation(void) __attribute__((section("BOARD_IO_DELAY_CODE")));
#endif

/* ISOIN Field for CTRL_CORE_SMA_SW_0 */
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO_SHIFT        (2U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO_MASK         (0x00000004U)

#define CSL_CONFIG_REG_0_ROM_READ_MASK                      (0x00000002U)
#define CSL_CONFIG_REG_0_ROM_READ_SHIFT                     (1U)

/* Redefine CSL_IODELAYCONFIG_CONFIG_REG_8_GLOBAL_LOCK_BIT_MASK as it is
 * incorrectly defined in am57xx cslr_iodelayconfig.h
 */
#undef CSL_IODELAYCONFIG_CONFIG_REG_8_GLOBAL_LOCK_BIT_MASK
#define CSL_IODELAYCONFIG_CONFIG_REG_8_GLOBAL_LOCK_BIT_MASK (0x0000FFFFU)

/* Lock and Unlock values for Global lock : CONFIG_REG_8 */
#define CONFIG_REG_8_LOCK_GLOBAL_LOCK               (0x0000AAABU)
#define CONFIG_REG_8_UNLOCK_GLOBAL_LOCK             (0x0000AAAAU)

/* Lock and Unlock values for MMR_LOCK1 */
#define LOCK_MMR_LOCK1                              (0x1A1C8144U)
#define UNLOCK_MMR_LOCK1                            (0x2FF1AC2BU)

/* Lock and Unlock values for MMR_LOCK5 */
#define LOCK_MMR_LOCK5                              (0x143F832CU)
#define UNLOCK_MMR_LOCK5                            (0x6F361E05U)

/* Reference clock period for sysclk1 of 20 MHz */
#define REFCLK_PERIOD_SYSCLK1_20MHZ                 (0x00002710U)

/* Reference clock period for L4 ICLK of 66.5 MHz */
#define REFCLK_PERIOD_L4ICLK_66_5_MHZ               (0x000005DEU)

/* Reference clock period for L4 ICLK of 133 MHz */
#define REFCLK_PERIOD_L4ICLK_133_MHZ               (0x000002EFU)

void BoardCtrlPadIoDelayConfig(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize)
{
    CSL_IodelayconfigRegs *ioDelayCfg =
        (CSL_IodelayconfigRegs *)SOC_DELAYLINE_BASE;

    /* We avoid locking MMRs in the application for now. */
#if 0
    /* Unlock the MMR_LOCK1 */
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_MMR_LOCK_1,
                UNLOCK_MMR_LOCK1);

    /* Unlock the MMR_LOCK5 */
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_MMR_LOCK_5,
                UNLOCK_MMR_LOCK5);
#endif
    /* Unlock the global lock */
    CSL_FINS(ioDelayCfg->CONFIG_REG_8, IODELAYCONFIG_CONFIG_REG_8_GLOBAL_LOCK_BIT,
             CONFIG_REG_8_UNLOCK_GLOBAL_LOCK);

    /*
     * Update config_reg2 based on actual sysclk1 frequency.
     * Take sysclock1 period in ps and divide by 5 and write to register.
     * This ensures calibration logic assumes the correct clock reference.
     */
    CSL_FINS(ioDelayCfg->CONFIG_REG_2, IODELAYCONFIG_CONFIG_REG_2_REFCLK_PERIOD,
             REFCLK_PERIOD_L4ICLK_133_MHZ);

    /* Trigger the recalibration */
    CSL_FINS(ioDelayCfg->CONFIG_REG_0, IODELAYCONFIG_CONFIG_REG_0_CALIBRATION_START,
             0x1U);

    /*
     * Read CALIBRATION_START until it is read as 0,
     * indicating recalibration is complete.
     */
    while ((uint32_t)0U != CSL_FEXT(ioDelayCfg->CONFIG_REG_0,
                                    IODELAYCONFIG_CONFIG_REG_0_CALIBRATION_START))
    {}

    /* Begin the Isolation sequence to Isolate all the IOs */
    boardPadIoIsolation();

    /* Configure PAD mux for SoC along with Virtual and Manual Mode Delays */
    BoardCtrlPadMux(pPadCfgData, padArraySize);

    /* Begin the DeIsolation sequence to remove the Isolation on the IOs. */
    boardPadIoDeIsolation();
}

void BoardCtrlPadMux(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize)
{
    uint32_t index   = 0U;
    uint32_t cpde, fpde, configRegValue, modeSelect;
    uint32_t address = 0U;

    CSL_IodelayconfigRegs *ioDelayCfg =
        (CSL_IodelayconfigRegs *)SOC_DELAYLINE_BASE;

    cpde = calculateDelay(ioDelayCfg->CONFIG_REG_3, (uint32_t)88);
    fpde = calculateDelay(ioDelayCfg->CONFIG_REG_4, (uint32_t)264);

    for (index = 0; index < padArraySize; index++)
    {
        address = (SOC_CORE_PAD_IO_REGISTERS_BASE +
                   ((uint32_t)(pPadCfgData + index)->offset));
        HW_WR_REG32(address, (pPadCfgData + index)->regVal);

        modeSelect = (pPadCfgData + index)->regVal &
                     CTRL_CORE_PAD_GPMC_AD0_MODE_SELECT_MASK;

        if ((0U != modeSelect) &&
            (0U != (pPadCfgData + index)->delayConfigIn.offset))
        {
            configRegValue = calculateConfigRegister(
                (pPadCfgData + index)->delayConfigIn.aDelay,
                (pPadCfgData + index)->delayConfigIn.gDelay,
                cpde,
                fpde);

            address = (SOC_DELAYLINE_BASE +
                       ((uint32_t)(pPadCfgData + index)->delayConfigIn.offset));
            HW_WR_REG32(address, configRegValue);
        }

        if ((0U != modeSelect) &&
            (0U != (pPadCfgData + index)->delayConfigOen.offset))
        {
            configRegValue = calculateConfigRegister(
                (pPadCfgData + index)->delayConfigOen.aDelay,
                (pPadCfgData + index)->delayConfigOen.gDelay,
                cpde,
                fpde);

            address = (SOC_DELAYLINE_BASE +
                       ((uint32_t)(pPadCfgData + index)->delayConfigOen.offset));
            HW_WR_REG32(address, configRegValue);
        }

        if ((0U != modeSelect) &&
            (0U != (pPadCfgData + index)->delayConfigOut.offset))
        {
            configRegValue = calculateConfigRegister(
                (pPadCfgData + index)->delayConfigOut.aDelay,
                (pPadCfgData + index)->delayConfigOut.gDelay,
                cpde,
                fpde);

            address = (SOC_DELAYLINE_BASE +
                       ((uint32_t)(pPadCfgData + index)->delayConfigOut.offset));
            HW_WR_REG32(address, configRegValue);
        }
    }
}

static void boardPadIoIsolation(void)
{
    volatile uint32_t dummyRead        = 0U;

    CSL_control_coreRegs *ctrlCoreRegs =
        (CSL_control_coreRegs *)SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE;

    CSL_IodelayconfigRegs *ioDelayCfg =
        (CSL_IodelayconfigRegs *)SOC_DELAYLINE_BASE;

    CSL_device_prmRegs *devPrm =
        (CSL_device_prmRegs *)SOC_DEVICE_PRM_BASE;

    /*
     * Isolate all the IO.
     */
    CSL_FINS(devPrm->PRM_IO_PMCTRL_REG, PRM_IO_PMCTRL_ISOCLK_OVERRIDE,
             PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE);

    while ((uint32_t)0x1U != CSL_FEXT(devPrm->PRM_IO_PMCTRL_REG,
                                      PRM_IO_PMCTRL_ISOCLK_STATUS))
    {}

    CSL_FINS(ctrlCoreRegs->SMA_SW_0,
             CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO, 0x1U);

    dummyRead = CSL_FEXT(ctrlCoreRegs->SMA_SW_0,
                         CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO);

    CSL_FINS(devPrm->PRM_IO_PMCTRL_REG, PRM_IO_PMCTRL_ISOCLK_OVERRIDE,
             PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE);

    while ((uint32_t)0x0U != CSL_FEXT(devPrm->PRM_IO_PMCTRL_REG,
                                      PRM_IO_PMCTRL_ISOCLK_STATUS))
        ;

    /* Update delay mechanism for each IO with recalibrated values */
    CSL_FINS(ioDelayCfg->CONFIG_REG_0, CONFIG_REG_0_ROM_READ, 0x1U);

    /*
     * Read ROM_READ until it is read as 0,
     * indicating reload is complete.
     */
    while ((uint32_t)0U != CSL_FEXT(ioDelayCfg->CONFIG_REG_0,
                                    CONFIG_REG_0_ROM_READ))
    {}

    /* Dummy read to remove compiler warning */
    dummyRead = dummyRead;
}

static void boardPadIoDeIsolation(void)
{
    volatile uint32_t dummyRead        = 0U;

    CSL_control_coreRegs *ctrlCoreRegs =
        (CSL_control_coreRegs *)SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE;

    CSL_IodelayconfigRegs *ioDelayCfg =
        (CSL_IodelayconfigRegs *)SOC_DELAYLINE_BASE;

    CSL_device_prmRegs *devPrm =
        (CSL_device_prmRegs *)SOC_DEVICE_PRM_BASE;

    /*
     * Remove all IOs from isolation.
     */
    CSL_FINS(devPrm->PRM_IO_PMCTRL_REG, PRM_IO_PMCTRL_ISOCLK_OVERRIDE,
             PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE);

    while ((uint32_t)0x1U != CSL_FEXT(devPrm->PRM_IO_PMCTRL_REG,
                                      PRM_IO_PMCTRL_ISOCLK_STATUS))
    {}

    CSL_FINS(ctrlCoreRegs->SMA_SW_0, CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO,
             0x0U);

    dummyRead = CSL_FEXT(ctrlCoreRegs->SMA_SW_0,
                         CONTROL_CORE_SMA_SW_0_SMA_SW_0_ISO);

    CSL_FINS(devPrm->PRM_IO_PMCTRL_REG, PRM_IO_PMCTRL_ISOCLK_OVERRIDE,
             PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE);

    while ((uint32_t)0x0U != CSL_FEXT(devPrm->PRM_IO_PMCTRL_REG,
                                      PRM_IO_PMCTRL_ISOCLK_STATUS))
    {}
#if 0
    /* Lock the MMR_LOCK1 */
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MMR_LOCK_1,
                LOCK_MMR_LOCK1);

    /* Lock the MMR_LOCK5 */
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MMR_LOCK_5,
                LOCK_MMR_LOCK5);
#endif
    /* Lock the global lock */
    CSL_FINS(ioDelayCfg->CONFIG_REG_8, IODELAYCONFIG_CONFIG_REG_8_GLOBAL_LOCK_BIT,
             CONFIG_REG_8_LOCK_GLOBAL_LOCK);

    /* Dummy read to remove compiler warning */
    dummyRead = dummyRead;
}

static uint32_t calculateConfigRegister(uint32_t aDelay, uint32_t gDelay, uint32_t cpde, uint32_t fpde)
{
    uint32_t gDelayCoarse, gDelayFine, aDelayCoarse, aDelayFine;
    uint32_t coarseElements, fineElements, totalDelay;
    uint32_t finalConfigRegValue = 0U;

    gDelayCoarse   = gDelay / 920U;
    gDelayFine     = ((gDelay % 920U) * 10U) / 60U;

    aDelayCoarse   = aDelay / cpde;
    aDelayFine     = ((aDelay % cpde) * 10U) / fpde;

    coarseElements = gDelayCoarse + aDelayCoarse;
    fineElements   = (gDelayFine + aDelayFine) / 10U;

    if (22U < fineElements)
    {
        totalDelay     = (coarseElements * cpde) + (fineElements * fpde);
        coarseElements = totalDelay / cpde;
        fineElements   = (totalDelay % cpde) / fpde;
    }

    finalConfigRegValue = (0x29400U ^ (coarseElements << 5U)) + fineElements;

    return finalConfigRegValue;
}

static uint32_t calculateDelay(uint32_t configRegValue, uint32_t divisorValue)
{
    uint32_t refclkPeriod, delayCount, refCount, q, r;
    CSL_IodelayconfigRegs *ioDelayCfg =
        (CSL_IodelayconfigRegs *)SOC_DELAYLINE_BASE;

    refclkPeriod = CSL_FEXT(ioDelayCfg->CONFIG_REG_2,
                            IODELAYCONFIG_CONFIG_REG_2_REFCLK_PERIOD);

    delayCount = CSL_FEXT(configRegValue,
                          IODELAYCONFIG_CONFIG_REG_3_COARSE_DELAY_COUNT);

    refCount = CSL_FEXT(configRegValue,
                        IODELAYCONFIG_CONFIG_REG_3_COARSE_REF_COUNT);

    /*
     * To avoid overflow and integer truncation, delay value
     * is calculated as quotient + remainder.
     */
#if 1
    q = 5 * ((refCount * refclkPeriod) / (delayCount * divisorValue));
    r = (10 * ((refCount * refclkPeriod) % (delayCount * divisorValue))) /
        (2 * delayCount * divisorValue);

    return q + r;
#else
    delayVal = (uint32_t)
               (((uint64_t)10 * (uint64_t)(refCount) *
                 (uint64_t)(refclkPeriod)) /
                ((uint64_t)2 * (uint64_t)(delayCount) *
                 (uint64_t)(divisorValue)));

    return delayVal;
#endif
}
