/*
 *  Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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
 */
/**
 *  \file     dcan_loopback_app_main.c
 *
 *  \brief    This file contains DCAN external loopback test mode
 *
 *  \details  DCAN external loopback which tests the internal feedback
 *            from Tx output to Rx input. Transmitted messages are treated as
 *            received messages and can be stored into message objects if they
 *            pass acceptance filtering.
 *
 *  \copyright Copyright (C) 2014 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "stdint.h"
#include <string.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_dcan.h>
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief DCAN bit time calculation maximum error value. */
#define DCAN_APP_CALC_MAX_ERROR         (50U)

/** \brief Macro used to extract bit rate prescaler value. */
#define DCAN_APP_EXTRACT_BRPE_VAL       (0x3C0U)

/** \brief Shift value used for bit rate prescaler. */
#define DCAN_APP_BRPE_SHIFT             (6U)

/** \brief DCAN input clock - 20MHz */
#define DCAN_APP_INPUT_CLK              (20000000U)
/** \brief DCAN output bit rate - 1MHz */
#define DCAN_APP_BIT_RATE               (1000000U)

/** \brief DCAN TX message object used */
#define DCAN_TX_MSG_OBJ                 (0x1U)
/** \brief DCAN RX message object used */
#define DCAN_RX_MSG_OBJ                 (0x2U)

/** \brief DCAN TX interface register used */
#define DCAN_APP_TX_IF_REG              (DCAN_IF_REG_NUM_1)
/** \brief DCAN RX interface register used */
#define DCAN_APP_RX_IF_REG              (DCAN_IF_REG_NUM_2)

#if !defined (SOC_K2G)
/** \brief Offset of DRM SUSPEND_CTRL1 register */
#define DRM_SUSPEND_CTRL1               (0x204)
/** \brief DRM_SUSPEND_CTRL1 is mapped to DCAN1 Suspend Output line */
#define DRM_SUSPEND_CTRL_DCAN1          (SOC_I_DRM_BASE + DRM_SUSPEND_CTRL1)

/** \brief Offset of DRM SUSPEND_CTRL2 register */
#define DRM_SUSPEND_CTRL2               (0x208)
/** \brief DRM_SUSPEND_CTRL2 is mapped to DCAN2 Suspend Output line */
#define DRM_SUSPEND_CTRL_DCAN2          (SOC_I_DRM_BASE + DRM_SUSPEND_CTRL2)

/** \brief DRM SUSPEND Source as A15 */
#define DRM_SUSPEND_SRC_MPU_C0          (0x5)
/** \brief DRM SUSPEND Source as M4 */
#define DRM_SUSPEND_SRC_IPU1_C0         (0x3)
#endif

/** \brief DCAN Message Object */
#define DCAN_MSG_OBJ                    (0x1)

/** \brief DCAN Message Object RAM Address */
#define DCAN_MSG_OBJ_RAM_ADDR           ((SOC_DCAN1_MESSAGERAM_BASE) + \
                                         (DCAN_MSG_OBJ * DCAN_MSG_OBJ_SIZE))

#define DCAN_EXT_LOOPBACK_TEST      ('1')
#define DCAN_INT_LOOPBACK_TEST      ('2')
#define DCAN_ECC_TEST               ('3')
#define EXIT(opt)                   (('x' == opt) || ('X' == opt))

/*To use UARTConfigPuts function for prints*/
#if (defined (SOC_AM572x)) || (defined (SOC_AM571x)) || (defined (SOC_AM574x))
uint32_t uartBaseAddr = CSL_MPU_UART1_REGS;
/** \brief DCAN instance used */
#define DCAN1_APP_INST                   (CSL_MPU_DCAN1_REGS)
#define DCAN2_APP_INST                   (CSL_MPU_DCAN2_REGS)
#undef SOC_I_DRM_BASE
#define SOC_I_DRM_BASE CSL_MPU_I_DRM_REGS
#endif
#if defined (SOC_TDA2EX) || defined (SOC_TDA2XX) || defined (SOC_DRA75x)
uint32_t uartBaseAddr = SOC_UART1_BASE;
#define DCAN1_APP_INST                   (SOC_DCAN1_BASE)
#define DCAN2_APP_INST                   (SOC_DCAN2_BASE)
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
uint32_t uartBaseAddr = SOC_UART3_BASE;
#define DCAN1_APP_INST                   (SOC_DCAN1_BASE)
#define DCAN2_APP_INST                   (SOC_DCAN2_BASE)
#endif

#if defined (SOC_K2G)
uint32_t uartBaseAddr = CSL_UART_0_REGS;
#define DCAN1_APP_INST                   (CSL_DCAN_0_DATA)
#define DCAN2_APP_INST                   (CSL_DCAN_1_DATA)
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief    Enumerates the values used to represent the DCAN bit time
 *            calculation error values.
 */
typedef enum dcanBitTimeCalcErrType
{
    DCAN_BIT_RATE_ERR_MAX = 1,
    /**< Bitrate error maximum value */
    DCAN_BIT_RATE_ERR_WARN = 2,
    /**< Bitrate error warning value */
    DCAN_BIT_RATE_ERR_NONE = 3
                             /**< No bit rate error */
} dcanBitTimeCalcErrType_t;

/** \brief Structure holding Bit Time parameters for DCAN application. */
typedef struct dcanBitTimeParamsLocal
{
    uint32_t samplePnt;
    uint32_t timeQuanta;
    uint32_t propSeg;
    uint32_t phaseSeg1;
    uint32_t phaseSeg2;
    uint32_t syncJumpWidth;
    uint32_t bitRatePrescaler;
    uint32_t tseg1Min;
    uint32_t tseg1Max;
    uint32_t tseg2Min;
    uint32_t tseg2Max;
    uint32_t syncJumpWidthMax;
    uint32_t bitRatePrescalerMin;
    uint32_t bitRatePrescalerMax;
    uint32_t bitRatePrescalerInc;
    uint32_t bitRate;
} dcanBitTimeParamsLocal_t;

/*TODO PDK: hardcoded*/
typedef enum
{
    CPU_MPUSS,
    CPU_IPU1,
    CPU_DSP1,
#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75x)
    CPU_DSP2,
    CPU_EVE1,
    CPU_EVE2,
    CPU_EVE3,
    CPU_EVE4,
#endif
    CPU_PRUSS1
} cpu_id_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static uint32_t DCANAppBitTimeCalculator(
    dcanBitTimeParamsLocal_t *pBitTimeParam,
    uint32_t                  clkFreq);

static int32_t DCANAppUpdateSamplePnt(dcanBitTimeParamsLocal_t *pBitTimeParam,
                                      int32_t                   samplePnt,
                                      int32_t                   tseg,
                                      int32_t                  *tseg1,
                                      int32_t                  *tseg2);

static void DCANAppInitParams(dcanCfgParams_t       *pDcanCfgPrms,
                              dcanMsgObjCfgParams_t *pDcanTxCfgPrms,
                              dcanMsgObjCfgParams_t *pDcanRxCfgPrms,
                              dcanTxParams_t        *pDcanTxPrms);

static void DCANAppWaitForIfReg(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief   This function takes I/P Clk frequency, required bit-rate on the
 *          CAN bus and calculates the value to be programmed for DCAN BTR
 *          register. This API doesn't to the actual programming. This is
 *          intended to be used as a utility function. And the application
 *          should call the #DCANSetBitTime function to do the actual
 *          programming.
 *
 * \param   clkFreq        I/P clock frequency to DCAN controller in Hz.
 * \param   bitRate        Required bit-rate on the CAN bus in bits per second.
 * \param   pBitTimePrms   Pointer to params where the calculated register
 *                         fields are populated
 *
 * \return  errVal         Returns Bit Time calculation error of type enum
 *                         dcanBitTimeCalcErrType_t
 */
static uint32_t DCANCalculateBitTimeParams(uint32_t             clkFreq,
                                           uint32_t             bitRate,
                                           dcanBitTimeParams_t *pBitTimePrms);

void mainMenu(char *option);

static int32_t dcanLoopbackTest(void);

volatile unsigned char gTxDoneFlag = 0, gRxDoneFlag = 0;
char     gMainMenuOption;
uint32_t gDcanAppInstance;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x) || defined (SOC_AM574x)
uint32_t GetSiliconRev(void)
{
    uint32_t siliconRev;

    siliconRev = HW_RD_REG32(SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE +
                             CTRL_WKUP_ID_CODE);

    siliconRev = (siliconRev & 0xF0000000U) >> 28U;

    return (siliconRev);
}
#endif

void padConfig_prcmEnable()
{
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
/*Pad configurations */
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART1_TXD,0x00000000);
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75x)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00000000);
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
#endif
}

void DCAN1Prcm_clck_ram()
{
    uint32_t status;
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
    /*CM_WKUPAON_DCAN1_CLKCTRL*/
    HW_WR_FIELD32(CSL_MPU_WKUPAON_CM_REGS + CM_WKUPAON_DCAN1_CLKCTRL,
              CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE,
              CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_ENABLE);

    while ((HW_RD_FIELD32(CSL_MPU_WKUPAON_CM_REGS + CM_WKUPAON_DCAN1_CLKCTRL,
                     CM_WKUPAON_DCAN1_CLKCTRL_IDLEST)) ==
                    CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_DISABLE)
               {
                ;
               }

    /*pin mux for dcan1*/
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_DCAN1_TX,0x000E0000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_WAKEUP0,0x00010001);

               /* Clear the start bit so that pulse is generated
             * when run second time */
    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                0U);

    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0);
    status =((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_MASK;

    while (status !=((status &
                     HW_RD_REG32(CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

            /* Write one to clear done bit */
    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE,
                1U);
#endif

#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75x)
    /*CM_WKUPAON_DCAN1_CLKCTRL*/
    HW_WR_FIELD32(SOC_WKUPAON_CM_BASE + CM_WKUPAON_DCAN1_CLKCTRL,
               CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE,
               CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_ENABLE);

    while ((HW_RD_FIELD32(SOC_WKUPAON_CM_BASE + CM_WKUPAON_DCAN1_CLKCTRL,
                    CM_WKUPAON_DCAN1_CLKCTRL_IDLEST)) ==
                    CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_DISABLE)
               {
                ;
               }
    /*pin mux for dcan1*/
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_TX,0x000E0000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_WAKEUP0,0x00010001);

   /* Clear the start bit so that pulse is generated
             * when run second time */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                0U);

            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0);
            status =
                ((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_MASK;

            while (status !=
                   ((status &
                     HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

            /* Write one to clear done bit */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE,
                1U);
#endif

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /*CM_WKUPAON_DCAN1_CLKCTRL*/
    HW_WR_FIELD32(SOC_WKUPAON_CM_BASE + CM_WKUPAON_DCAN1_CLKCTRL,
               CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE,
               CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_ENABLE);

 while ((HW_RD_FIELD32(SOC_WKUPAON_CM_BASE + CM_WKUPAON_DCAN1_CLKCTRL,
                       CM_WKUPAON_DCAN1_CLKCTRL_IDLEST)) ==
        CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_DISABLE)
 {
     ;
 }
    /*pin mux for dcan1*/
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_DCAN1_TX,0x000E0000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_DCAN1_RX,0x000E0000);

   /* Clear the start bit so that pulse is generated
             * when run second time */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                0U);

            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPENANDNONEEDFORSWTOWRITE0);

            status =
                ((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_MASK;

            while (status !=
                   ((status &
                     HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

            /* Write one to clear done bit */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE,
                1U);
#endif
}

void DCAN2Prcm_clck_ram()
{
    uint32_t status;

#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
    /*CM_L4PER2_DCAN2_CLKCTRL*/
    HW_WR_FIELD32(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_DCAN2_CLKCTRL,
              CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE,
              CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_ENABLE);

    while ((HW_RD_FIELD32(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_DCAN2_CLKCTRL,
                      CM_L4PER2_DCAN2_CLKCTRL_IDLEST)) ==
       CM_L4PER2_DCAN2_CLKCTRL_IDLEST_DISABLE)
           {
               ;
           }
   /*pin mux for dcan2*/
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPIO6_14,0x2);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPIO6_15,0x2);

               /* Clear the start bit so that pulse is generated
             * when run second time */
    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                0U);

    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0);
    status =((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_MASK;

    while (status !=((status &
                     HW_RD_REG32(CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

    /* Write one to clear done bit */
    HW_WR_FIELD32((uint32_t) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE,1U);
#endif

#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75x)
    /*CM_L4PER2_DCAN2_CLKCTRL*/
    HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_DCAN2_CLKCTRL,
               CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE,
               CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_ENABLE);

    while ((HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_DCAN2_CLKCTRL,
                       CM_L4PER2_DCAN2_CLKCTRL_IDLEST)) ==
        CM_L4PER2_DCAN2_CLKCTRL_IDLEST_DISABLE)
        {
        ;
        }
    /*pin mux for dcan2*/
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_GPIO6_14,0x2);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_GPIO6_15,0x2);

    /* Clear the start bit so that pulse is generated
             * when run second time */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                0U);

            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0);
            status =
                ((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_MASK;

            while (status !=
                   ((status &
                     HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

            /* Write one to clear done bit */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE,
                1U);
#endif

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /*CM_WKUPAON_DCAN2_CLKCTRL*/
    HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_DCAN2_CLKCTRL,
              CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE,
              CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_ENABLE);

    while ((HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_DCAN2_CLKCTRL,
                    CM_L4PER2_DCAN2_CLKCTRL_IDLEST)) ==
                    CM_L4PER2_DCAN2_CLKCTRL_IDLEST_DISABLE)
            {
                ;
            }
    /*pin mux for dcan2*/
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_RXD,0xc);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_TXD,0xc);

    /* Clear the start bit so that pulse is generated
             * when run second time */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                0U);

            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPENANDNONEEDFORSWTOWRITE0);
            status =
                ((uint32_t) 0x1 <<
                 CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_SHIFT) &
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_MASK;

            while (status !=
                   ((status &
                     HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                                 CTRL_CORE_CONTROL_IO_2))))
            {
                ;
            }

            /* Write one to clear done bit */
            HW_WR_FIELD32(
                (uint32_t) SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                CTRL_CORE_CONTROL_IO_2,
                CTRL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE,
                1U);

#endif

}

int main(void)
{
    int32_t           retVal   = STW_SOK;
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x) || defined (SOC_AM574x)
    uint32_t          siliconRev;
#endif
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 DCAN Test                 *\n");
    UART_printf  ("*********************************************\n");

    padConfig_prcmEnable();

#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
    siliconRev = GetSiliconRev();
    if (0U == siliconRev)
    {
        UART_printf("\nDCAN Loopback is not supported for Tda2xx PG1.0 Silicon...",-1);
        return 0;
    }
#endif
#if 1
    while (1)
    {
        mainMenu(&gMainMenuOption);
        if ((DCAN_EXT_LOOPBACK_TEST == gMainMenuOption) ||
            (DCAN_INT_LOOPBACK_TEST == gMainMenuOption))
        {
            if (DCAN_EXT_LOOPBACK_TEST == gMainMenuOption)
            {
                gDcanAppInstance = DCAN1_APP_INST;
            }
            else
            {
                gDcanAppInstance = DCAN2_APP_INST;
            }
            retVal = dcanLoopbackTest();
        }
        else
        {
            UART_printf("\nDCAN Application Test exiting...", -1);
            break;
        }
    }

#else
    gMainMenuOption = 1;
    gDcanAppInstance = DCAN1_APP_INST;
    retVal = dcanLoopbackTest();
    if (retVal != STW_SOK)
    {
        return retVal;
    }
    else
    {
        gMainMenuOption = 2;
        gDcanAppInstance = DCAN2_APP_INST;
        retVal = dcanLoopbackTest();
    }
#endif
    return retVal;
}

static int32_t dcanLoopbackTest(void)
{
    int32_t               retVal    = STW_SOK;
    int32_t               errStatus = STW_SOK;
    dcanCfgParams_t       appDcanCfgPrms;
    dcanMsgObjCfgParams_t appDcanTxCfgPrms;
    dcanMsgObjCfgParams_t appDcanRxCfgPrms;
    dcanTxParams_t        appDcanTxPrms;
    dcanBitTimeParams_t   appDcanBitTimePrms;
    dcanRxParams_t        appDcanRxPrms;
    uint32_t              timeOut             = 100U;
    uint32_t              dataLength          = 0U;
    uint32_t              msgLstErrCnt        = 0U;
    uint32_t              dataMissMatchErrCnt = 0U;

    gTxDoneFlag = 0;
    gRxDoneFlag = 0;

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        UART_printf(
            "\nDCAN External Loopback Test App: DCAN1 MSG OBJ 1 (TX) to DCAN1 MSG OBJ 2 (RX)\n",
            -1);
#if !defined (SOC_K2G)
#if defined (__TI_ARM_V7M4__)
        /* DRM_SUSPEND_CTRL_DCAN1 - SUSPEND_SEL(Suspend source selection) as
         * IPU1_C0
         * & SENS_CTRL(Sensitivity control) as 1 means suspend signal must reach
         * the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN1,
                    ((DRM_SUSPEND_SRC_IPU1_C0 << 4) | 0x1));
#elif defined (__ARM_ARCH_7A__)
        /* DRM_SUSPEND_CTRL_DCAN1 - SUSPEND_SEL(Suspend source selection) as
         * MPU_C0
         * & SENS_CTRL(Sensitivity control) as 1 means suspend signal must reach
         * the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN1,
                    ((DRM_SUSPEND_SRC_MPU_C0 << 4) | 0x1));
#endif
#endif
    }
    else
    {
        UART_printf(
            "\nDCAN Internal Loopback Test App: DCAN2 MSG OBJ 1 (TX) to DCAN2 MSG OBJ 2 (RX)\n",
            -1);
#if !defined (SOC_K2G)
#if defined (__TI_ARM_V7M4__)
        /* DRM_SUSPEND_CTRL_DCAN2 - SUSPEND_SEL(Suspend source selection) as
         * IPU1_C0 & SENS_CTRL(Sensitivity control) as 1 means suspend signal
         *  must reach the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN2,
                    ((DRM_SUSPEND_SRC_IPU1_C0 << 4) | 0x1));
#elif defined (__ARM_ARCH_7A__)
        /* DRM_SUSPEND_CTRL_DCAN2 - SUSPEND_SEL(Suspend source selection) as
         * MPU_C0 & SENS_CTRL(Sensitivity control) as 1 means suspend signal
         * must reach the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN2,
                    ((DRM_SUSPEND_SRC_MPU_C0 << 4) | 0x1));
#endif
#endif
    }
    DCANAppInitParams(&appDcanCfgPrms,
                      &appDcanTxCfgPrms,
                      &appDcanRxCfgPrms,
                      &appDcanTxPrms);

    if (gDcanAppInstance == DCAN1_APP_INST)
    {

        DCAN1Prcm_clck_ram();
    }
    else
    {
        DCAN2Prcm_clck_ram();
    }

    /* Reset the DCAN IP */
    retVal = DCANReset(gDcanAppInstance, timeOut);
    if (retVal == STW_SOK)
    {
        /* Set the desired bit rate based on input clock */
        DCANSetMode(gDcanAppInstance, DCAN_MODE_INIT);
        errStatus = DCANCalculateBitTimeParams(DCAN_APP_INPUT_CLK,
                                               DCAN_APP_BIT_RATE,
                                               &appDcanBitTimePrms);
        if (errStatus != DCAN_BIT_RATE_ERR_NONE)
        {
            return errStatus;
        }
        DCANSetBitTime(gDcanAppInstance, &appDcanBitTimePrms);
        DCANSetMode(gDcanAppInstance, DCAN_MODE_NORMAL);

        /* Configure DCAN controller */
        DCANConfig(gDcanAppInstance, &appDcanCfgPrms);
        /*
         * Enable message object interrupt to route interrupt line 1
         */
    }
    if (retVal == STW_SOK)
    {
        /* Wait for interface to become free */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
        retVal = DCANConfigMsgObj(gDcanAppInstance,
                                  DCAN_RX_MSG_OBJ,
                                  DCAN_APP_RX_IF_REG,
                                  &appDcanRxCfgPrms);
        /* Wait for config to be copied to internal message RAM */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
    }

    if (retVal == STW_SOK)
    {
        /* Wait for interface to become free */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
        retVal = DCANConfigMsgObj(gDcanAppInstance,
                                  DCAN_TX_MSG_OBJ,
                                  DCAN_APP_TX_IF_REG,
                                  &appDcanTxCfgPrms);
        /* Wait for config to be copied to internal message RAM */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
    }

    if (retVal == STW_SOK)
    {
        /* Wait for interface to become free */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
        retVal = DCANTransmitData(gDcanAppInstance,
                                  DCAN_TX_MSG_OBJ,
                                  DCAN_APP_TX_IF_REG,
                                  &appDcanTxPrms,
                                  timeOut);
        /* Wait for config to be copied to internal message RAM */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
    }

    if (retVal == STW_SOK)
    {
        /* Wait for transmit interrupt */
        while (DCANIsTxMsgPending(gDcanAppInstance,
                                  DCAN_TX_MSG_OBJ)==TRUE) ;
    }

    if (retVal == STW_SOK)
    {
        /* Wait for receive interrupt */
        while (DCANHasRxMsgArrived(gDcanAppInstance,
                                  DCAN_RX_MSG_OBJ)==FALSE) ;
    }

    if (retVal == STW_SOK)
    {
        /* Clear RX structure */
        memset(&appDcanRxPrms, 0, sizeof (appDcanRxPrms));

        /* Wait for interface to become free */
        DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
        retVal = DCANGetData(gDcanAppInstance,
                             DCAN_RX_MSG_OBJ,
                             DCAN_APP_RX_IF_REG,
                             &appDcanRxPrms,
                             timeOut);
    }

    if (retVal == STW_SOK)
    {
        /* Check if sent data is lost or not */
        if (appDcanRxPrms.msgLostFlag == TRUE)
        {
            msgLstErrCnt++;
        }

        /* Check if sent data has been received */
        if (appDcanRxPrms.dataLength == appDcanTxPrms.dataLength)
        {
            while (dataLength < appDcanRxPrms.dataLength)
            {
                if (appDcanRxPrms.msgData[dataLength] !=
                    appDcanTxPrms.msgData[dataLength])
                {
                    retVal = STW_EFAIL;
                    dataMissMatchErrCnt++;
                }
                dataLength++;
            }
        }
        else
        {
            retVal = STW_EFAIL;
        }
    }
    if (((msgLstErrCnt == 0) &&
         (dataMissMatchErrCnt == 0)) && (retVal == STW_SOK))
    {
        if (gMainMenuOption == DCAN_EXT_LOOPBACK_TEST)
        {
            UART_printf("\nDCAN -- External Loopback Testmode test Passed!! \n",
                     -1);
        }
        else
        {
            UART_printf("\nDCAN -- Internal Loopback Testmode test Passed!! \n",
                     -1);
        }
    }
    else
    {
        if (gMainMenuOption == DCAN_EXT_LOOPBACK_TEST)
        {
            UART_printf("\nDCAN -- External Loopback Testmode test Failed!! \n",
                     -1);
        }
        else
        {
            UART_printf("\nDCAN -- Internal Loopback Testmode test Failed!! \n",
                     -1);
        }
    }
    return retVal;
}

static void DCANAppInitParams(dcanCfgParams_t       *pDcanCfgPrms,
                              dcanMsgObjCfgParams_t *pDcanTxCfgPrms,
                              dcanMsgObjCfgParams_t *pDcanRxCfgPrms,
                              dcanTxParams_t        *pDcanTxPrms)
{
    /*Intialize DCAN Config Params*/

        pDcanCfgPrms->parityEnable    = FALSE;
        pDcanCfgPrms->intrLine0Enable = TRUE;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
        pDcanCfgPrms->eccModeEnable = FALSE;
#endif
        pDcanCfgPrms->testModeEnable = TRUE;
        if (gMainMenuOption == DCAN_INT_LOOPBACK_TEST)
        {
            pDcanCfgPrms->testMode = DCAN_TEST_MODE_LPBACK;
        }
        else
        {
            pDcanCfgPrms->testMode = DCAN_TEST_MODE_EXT_LPBACK;
        }

    pDcanCfgPrms->autoRetransmitDisable = TRUE;
    pDcanCfgPrms->autoBusOnEnable       = FALSE;
    pDcanCfgPrms->intrLine1Enable       = FALSE;
    pDcanCfgPrms->errIntrEnable         = FALSE;
    pDcanCfgPrms->stsChangeIntrEnable   = FALSE;
    pDcanCfgPrms->autoBusOnTimerVal     = FALSE;
    pDcanCfgPrms->if1DmaEnable          = FALSE;
    pDcanCfgPrms->if2DmaEnable          = FALSE;
    pDcanCfgPrms->if3DmaEnable          = FALSE;
    pDcanCfgPrms->ramAccessEnable       = FALSE;

    /*Intialize DCAN tx Config Params*/
    pDcanTxCfgPrms->xIdFlagMask       = 0x1;
    pDcanTxCfgPrms->dirMask           = 0x1;
    pDcanTxCfgPrms->msgIdentifierMask = 0x1FFFFFFF;

    pDcanTxCfgPrms->msgValid      = TRUE;
    pDcanTxCfgPrms->xIdFlag       = TRUE;
    pDcanTxCfgPrms->direction     = DCAN_DIR_TX;
    pDcanTxCfgPrms->msgIdentifier = 0xC1;

    pDcanTxCfgPrms->uMaskUsed    = TRUE;
    pDcanTxCfgPrms->intEnable    = TRUE;
    pDcanTxCfgPrms->remoteEnable = FALSE;
    pDcanTxCfgPrms->fifoEOBFlag  = TRUE;

    /*Intialize DCAN Rx Config Params*/
    pDcanRxCfgPrms->xIdFlagMask       = 0x1;
    pDcanRxCfgPrms->msgIdentifierMask = 0x1FFFFFFF;
    pDcanRxCfgPrms->dirMask           = 0x1;

    pDcanRxCfgPrms->msgValid      = TRUE;
    pDcanRxCfgPrms->xIdFlag       = TRUE;
    pDcanRxCfgPrms->direction     = DCAN_DIR_RX;
    pDcanRxCfgPrms->msgIdentifier = 0xC1;

    pDcanRxCfgPrms->uMaskUsed    = TRUE;
    pDcanRxCfgPrms->intEnable    = TRUE;
    pDcanRxCfgPrms->remoteEnable = FALSE;
    pDcanRxCfgPrms->fifoEOBFlag  = TRUE;

    /*Intialize DCAN Tx transfer Params*/
    pDcanTxPrms->dataLength = DCAN_MAX_MSG_LENGTH;
    pDcanTxPrms->msgData[0] = 0xA5;
    pDcanTxPrms->msgData[1] = 0x5A;
    pDcanTxPrms->msgData[2] = 0xFF;
    pDcanTxPrms->msgData[3] = 0xFF;
    pDcanTxPrms->msgData[4] = 0xC3;
    pDcanTxPrms->msgData[5] = 0x3C;
    pDcanTxPrms->msgData[6] = 0xB4;
    pDcanTxPrms->msgData[7] = 0x4B;
}

static uint32_t DCANCalculateBitTimeParams(uint32_t             clkFreq,
                                           uint32_t             bitRate,
                                           dcanBitTimeParams_t *pBitTimePrms)
{
    uint32_t errVal;
    dcanBitTimeParamsLocal_t bitTimePrms;

    bitTimePrms.samplePnt           = 0U;
    bitTimePrms.timeQuanta          = 0U;
    bitTimePrms.propSeg             = 0U;
    bitTimePrms.phaseSeg1           = 0U;
    bitTimePrms.phaseSeg2           = 0U;
    bitTimePrms.syncJumpWidth       = 0U;
    bitTimePrms.bitRatePrescaler    = 0U;
    bitTimePrms.tseg1Min            = 1U;
    bitTimePrms.tseg1Max            = 16U;
    bitTimePrms.tseg2Min            = 1U;
    bitTimePrms.tseg2Max            = 8U;
    bitTimePrms.syncJumpWidthMax    = 4U;
    bitTimePrms.bitRatePrescalerMin = 1U;
    bitTimePrms.bitRatePrescalerMax = 1024U;
    bitTimePrms.bitRatePrescalerInc = 1U;
    bitTimePrms.bitRate             = bitRate;

    errVal = DCANAppBitTimeCalculator(&bitTimePrms, clkFreq);

    pBitTimePrms->baudRatePrescaler =
        ((bitTimePrms.bitRatePrescaler - 1U) & DCAN_BTR_BRP_MASK);
    pBitTimePrms->syncJumpWidth = bitTimePrms.syncJumpWidth;
    pBitTimePrms->timeSegment1  =
        (bitTimePrms.phaseSeg1 + bitTimePrms.propSeg - 1U);
    pBitTimePrms->timeSegment2         = (bitTimePrms.phaseSeg2 - 1U);
    pBitTimePrms->baudRatePrescalerExt =
        (((bitTimePrms.bitRatePrescaler -
           1U) & DCAN_APP_EXTRACT_BRPE_VAL) >> DCAN_APP_BRPE_SHIFT);

    return (errVal);
}

static uint32_t DCANAppBitTimeCalculator(
    dcanBitTimeParamsLocal_t *pBitTimeParam,
    uint32_t                  clkFreq)
{
    int32_t  samplePnt = 0U, samplePntErr = 1000U, tsegAll = 0U;
    int32_t  tseg      = 0U, tseg1 = 0U, tseg2 = 0U;
    int32_t  brp       = 0U, samplePntNew = 0U, bestTseg = 0U, bestBrp = 0U;
    long     err       = 0U, bestErr = 1000000000U;
    uint32_t errVal    = DCAN_BIT_RATE_ERR_NONE;
    uint32_t rate      = 0U, timeQuanta = 0U;

    if (pBitTimeParam->bitRate > 800000U)
    {
        samplePnt = 750U;
    }
    else if (pBitTimeParam->bitRate > 500000U)
    {
        samplePnt = 800U;
    }
    else
    {
        samplePnt = 875U;
    }

    for (tseg = (pBitTimeParam->tseg1Max + pBitTimeParam->tseg2Max) * 2 + 1;
         tseg >= (pBitTimeParam->tseg1Min + pBitTimeParam->tseg2Min) * 2;
         tseg--)
    {
        tsegAll = 1 + tseg / 2;

        /* Compute all possible tseg choices (tseg = tseg1+tseg2) */
        brp = clkFreq / (tsegAll * pBitTimeParam->bitRate) + tseg % 2;

        /* chose brp step which is possible in system */
        brp = (brp / pBitTimeParam->bitRatePrescalerInc) *
              pBitTimeParam->bitRatePrescalerInc;

        if ((brp < pBitTimeParam->bitRatePrescalerMin) ||
            (brp > pBitTimeParam->bitRatePrescalerMax))
        {
            continue;
        }

        rate = clkFreq / (brp * tsegAll);
        err  = pBitTimeParam->bitRate - rate;

        /* tseg brp biterror */
        if (err < 0)
        {
            err = -err;
        }
        if (err > bestErr)
        {
            continue;
        }
        bestErr = err;
        if (err == 0)
        {
            samplePntNew = DCANAppUpdateSamplePnt(pBitTimeParam,
                                                  samplePnt,
                                                  tseg / 2,
                                                  &tseg1,
                                                  &tseg2);

            err = samplePnt - samplePntNew;
            if (err < 0)
            {
                err = -err;
            }
            if (err > samplePntErr)
            {
                continue;
            }
            samplePntErr = err;
        }
        bestTseg = tseg / 2;
        bestBrp  = brp;
        if (err == 0)
        {
            break;
        }
    }

    if (bestErr)
    {
        /* Error in one-tenth of a percent */
        err = (bestErr * 1000) / pBitTimeParam->bitRate;
        if (err > DCAN_APP_CALC_MAX_ERROR)
        {
            errVal = DCAN_BIT_RATE_ERR_MAX;
        }
        else
        {
            errVal = DCAN_BIT_RATE_ERR_WARN;
        }
    }

    /* real sample point */
    pBitTimeParam->samplePnt = DCANAppUpdateSamplePnt(pBitTimeParam,
                                                      samplePnt,
                                                      bestTseg,
                                                      &tseg1,
                                                      &tseg2);

    /* Calculate the time quanta value. */
    timeQuanta = bestBrp * 1000000000UL;

    pBitTimeParam->timeQuanta       = timeQuanta;
    pBitTimeParam->propSeg          = tseg1 / 2;
    pBitTimeParam->phaseSeg1        = tseg1 - pBitTimeParam->propSeg;
    pBitTimeParam->phaseSeg2        = tseg2;
    pBitTimeParam->syncJumpWidth    = 1;
    pBitTimeParam->bitRatePrescaler = bestBrp;

    /* Real bit-rate */
    pBitTimeParam->bitRate =
        clkFreq / (pBitTimeParam->bitRatePrescaler * (tseg1 + tseg2 + 1));

    return (errVal);
}

static int32_t DCANAppUpdateSamplePnt(dcanBitTimeParamsLocal_t *pBitTimeParam,
                                      int32_t                   samplePnt,
                                      int32_t                   tseg,
                                      int32_t                  *tseg1,
                                      int32_t                  *tseg2)
{
    *tseg2 = tseg + 1 - (samplePnt * (tseg + 1)) / 1000;

    if (*tseg2 < pBitTimeParam->tseg2Min)
    {
        *tseg2 = pBitTimeParam->tseg2Min;
    }

    if (*tseg2 > pBitTimeParam->tseg2Max)
    {
        *tseg2 = pBitTimeParam->tseg2Max;
    }

    *tseg1 = tseg - *tseg2;

    if (*tseg1 > pBitTimeParam->tseg1Max)
    {
        *tseg1 = pBitTimeParam->tseg1Max;
        *tseg2 = tseg - *tseg1;
    }
    return (1000 * (tseg + 1 - *tseg2) / (tseg + 1));
}

static void DCANAppWaitForIfReg(uint32_t baseAddr, uint32_t ifRegNum)
{
    do
    {
        if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
        {
            break;
        }
    }
    while (1);
}

void mainMenu(char *option)
{
    while (1)
    {
        UART_printf("\n\n**** DCAN APPLICATION TEST ****", -1);
        UART_printf("\nMenu:", -1);
        UART_printf("\n1. DCAN External Loopback test - DCAN1 Instance", -1);
        UART_printf("\n2. DCAN Internal Loopback test - DCAN2 Instance", -1);
        UART_printf("\nx. Exit", -1);
        UART_printf("\nSelect DCAN APPLICATION TEST : ", -1);

        /* Get option */
        UART_scanFmt("%c", option);

        if ((DCAN_EXT_LOOPBACK_TEST == *option) ||
            (DCAN_ECC_TEST == *option) ||
            (DCAN_INT_LOOPBACK_TEST == *option) || EXIT(*option))
        {
            break;
        }
        else
        {
            UART_printf("\nEnter Valid option\n", -1);
        }
    }
}

