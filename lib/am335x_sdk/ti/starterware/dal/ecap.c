/**
 *  \file   ecap.c
 *
 *  \brief  This file contains the device abstraction layer API implementation
 *          corresponding to ECAP module.
 *
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "hw_types.h"
#include "ecap.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* TODO: This sub-module offset has to be auto-generated. This will be removed
         later. */
/** \brief Enable clocks to ecap sub-module inside the pwm sub system. */
#define PWMSS_CLKCONFIG_ECAPCLK_ENABLE   (0x1U)

/** \brief Disable clocks to ecap sub-module inside the pwm sub system. */
#define PWMSS_CLK_CFG_ECAP_CLK_STOP     (0x1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None. */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None. */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None. */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t ECAPGetRevision(uint32_t baseAddr)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_REVID);

    return regVal;
}

void ECAPClkEnable(uint32_t baseAddr, uint32_t enableClk)
{
    if(TRUE == enableClk)
    {
        HW_WR_FIELD32(((baseAddr + PWMSS_PWMSS_OFFSET) + PWMSS_CLKCONFIG),
            PWMSS_CLKCONFIG_ECAPCLK_EN, PWMSS_CLKCONFIG_ECAPCLK_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(((baseAddr + PWMSS_PWMSS_OFFSET) + PWMSS_CLKCONFIG),
            PWMSS_CLKCONFIG_ECAPCLK_EN, PWMSS_CLK_CFG_ECAP_CLK_STOP);
    }
}

void ECAPSetOperMode(uint32_t baseAddr, uint32_t operMode)
{
    HW_WR_FIELD32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_CAP_APWM, operMode);
}

void ECAPSetCaptureMode(uint32_t baseAddr, uint32_t captMode)
{
    HW_WR_FIELD32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_CONT_ONESHT, captMode);
}

void ECAPCaptureLoadEnable(uint32_t baseAddr, uint32_t enableCaptLoad)
{
    if(TRUE == enableCaptLoad)
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
            PWMSS_ECAP_ECCTL1_CAPLDEN, PWMSS_ECAP_ECCTL1_CAPLDEN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
            PWMSS_ECAP_ECCTL1_CAPLDEN, PWMSS_ECAP_ECCTL1_CAPLDEN_DISABLE);
    }

}

void ECAPSetEvtPrescale(uint32_t baseAddr, uint32_t prescaleVal)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
        PWMSS_ECAP_ECCTL1_PRESCALE, prescaleVal);
}

uint32_t ECAPGetTimeStamp(uint32_t baseAddr, uint32_t captEvtNum)
{
    return (HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) + captEvtNum));
}

void ECAPSetCounterTimeBase(uint32_t baseAddr, uint32_t timeBaseVal)
{
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_TSCTR),
        timeBaseVal);
}

void ECAPTimeStampCounterEnable(uint32_t baseAddr, uint32_t enableCounter)
{
    if(TRUE == enableCounter)
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
            PWMSS_ECAP_ECCTL2_TSCTRSTOP,
            PWMSS_ECAP_ECCTL2_TSCTRSTOP_FREE_RUNNING);
    }
    else
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
            PWMSS_ECAP_ECCTL2_TSCTRSTOP, PWMSS_ECAP_ECCTL2_TSCTRSTOP_STOPPED);
    }
}

void ECAPSetCaptEvtPol(uint32_t baseAddr,
                       uint32_t captEvt,
                       uint32_t evtPol)
{
    switch(captEvt)
    {
        case ECAP_CAPT_EVT_1:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                PWMSS_ECAP_ECCTL1_CAP1POL, evtPol);
            break;
        }

        case ECAP_CAPT_EVT_2:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                PWMSS_ECAP_ECCTL1_CAP2POL, evtPol);
            break;
        }

        case ECAP_CAPT_EVT_3:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                PWMSS_ECAP_ECCTL1_CAP3POL, evtPol);
            break;
        }

        case ECAP_CAPT_EVT_4:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                PWMSS_ECAP_ECCTL1_CAP4POL, evtPol);
            break;
        }

        default:
        break;
    }
}

void ECAPCaptEvtCounterResetConfig(uint32_t baseAddr,
                                   uint32_t captEvtNum,
                                   uint32_t counterCfg)
{
    switch(captEvtNum)
    {
        case ECAP_CAPT_EVT_1:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                        PWMSS_ECAP_ECCTL1_CTRRST1, counterCfg);
            break;
        }

        case ECAP_CAPT_EVT_2:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                        PWMSS_ECAP_ECCTL1_CTRRST2, counterCfg);
            break;
        }

        case ECAP_CAPT_EVT_3:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                        PWMSS_ECAP_ECCTL1_CTRRST3, counterCfg);
            break;
        }

        case ECAP_CAPT_EVT_4:
        {
            HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
                        PWMSS_ECAP_ECCTL1_CTRRST4, counterCfg);
            break;
        }

        default:
        break;
    }
}

void ECAPSetStopWrapVal(uint32_t baseAddr, uint32_t stopWrapVal)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_STOP_WRAP, stopWrapVal);
}

void ECAPSetOneShotReArmingMode(uint32_t baseAddr)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_RE_ARM, PWMSS_ECAP_ECCTL2_RE_ARM_ARMS);
}

void ECAPSetApwmOutputPol(uint32_t baseAddr, uint32_t outputPol)
{
     HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_APWMPOL, outputPol);
}

void ECAPApwmOutputConfig(uint32_t baseAddr,
                          uint32_t compareVal,
                          uint32_t periodVal)
{
    /*
    ** Write the Capture 1 register with the active period value for generating
    ** the PWM output in APWM mode.
    */
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_CAP1), periodVal);

    /*
    ** Write the Capture 2 register with the active compare value for generating
    ** the PWM output in APWM mode.
    */
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_CAP2), compareVal);
}

void ECAPApwmShadowModeConfig(uint32_t baseAddr,
                              uint32_t compareVal,
                              uint32_t periodVal)
{
    /*
    ** Write the shadow register for the active period value for
    ** generating the PWM output in APWM mode.
    */
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_CAP3), periodVal);

    /*
    ** Write the shadow register for the active compare value for
    ** generating the PWM output in APWM mode.
    */
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_CAP4), compareVal);
}

void ECAPSetCounterPhaseVal(uint32_t baseAddr, uint32_t phaseVal)
{
    /* Write the counter phase value. */
    HW_WR_REG32(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_CTRPHS), phaseVal);
}

void ECAPSyncInEnable(uint32_t baseAddr, uint32_t enableSyncIn)
{
    if(TRUE == enableSyncIn)
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
            PWMSS_ECAP_ECCTL2_SYNCI_EN, PWMSS_ECAP_ECCTL2_SYNCI_EN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
            PWMSS_ECAP_ECCTL2_SYNCI_EN, PWMSS_ECAP_ECCTL2_SYNCI_EN_DISABLE);
    }
}

void ECAPSwSyncForceCounterEnable(uint32_t baseAddr)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_SWSYNC, PWMSS_ECAP_ECCTL2_SWSYNC_SHADOW_LOAD);
}

void ECAPSyncOutSignalCtrl(uint32_t baseAddr, uint32_t syncOutCtrl)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL2),
        PWMSS_ECAP_ECCTL2_SYNCO_SEL, syncOutCtrl);
}

void ECAPIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t regVal = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECEINT);
    regVal |= intrMask;
    HW_WR_REG16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECEINT), regVal);
}

void ECAPIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t regVal = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECEINT);
    /* Disable the specific interrupt by clearing the field. */
    regVal &= ~(intrMask);
    HW_WR_REG16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECEINT), regVal);
}

uint32_t ECAPIntrStatus(uint32_t baseAddr)
{
    return (HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECFLG));
}

void ECAPIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t regVal = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECCLR);
    /* Clear the specified interrupt and the Global interrupt. */
    regVal |= (intrMask | PWMSS_ECAP_ECCLR_INT_MASK);
    HW_WR_REG16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCLR), regVal);
}

void ECAPIntrTrigger(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t regVal = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECFRC);
    regVal |= intrMask;
    HW_WR_REG16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECFRC), regVal);
}

void ECAPSetEmuCtrlMode(uint32_t baseAddr, uint32_t emuCtrlMode)
{
    HW_WR_FIELD16(((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_ECAP_ECCTL1),
        PWMSS_ECAP_ECCTL1_FREE_SOFT, emuCtrlMode);
}

void ECAPContextSave(uint32_t baseAddr, ecapCtx_t *pCtx)
{
    /* Save the module register context. */
    pCtx->pwmssClkCfg = HW_RD_REG32(baseAddr + PWMSS_CLKCONFIG);
    pCtx->ecapCtrl1 = HW_RD_REG16(baseAddr + PWMSS_ECAP_ECCTL1);
    pCtx->ecapCtrl2 = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECCTL2);
    pCtx->ecapIntr = HW_RD_REG16((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_ECEINT);
    pCtx->ecapTimeCounter = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_TSCTR);
    pCtx->ecapCaptEvt1 = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_CAP1);
    pCtx->ecapCaptEvt2 = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_CAP2);
    pCtx->ecapCaptEvt3 = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_CAP3);
    pCtx->ecapCaptEvt4 = HW_RD_REG32((baseAddr + PWMSS_ECAP_OFFSET) +
                        PWMSS_ECAP_CAP4);
}

void ECAPContextRestore(uint32_t baseAddr, ecapCtx_t *pCtx)
{
    /* Restore the saved context. */
    HW_WR_REG32(baseAddr + PWMSS_CLKCONFIG, pCtx->pwmssClkCfg);
    HW_WR_REG16((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCtrl1);
    HW_WR_REG16((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCtrl2);
    HW_WR_REG16((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapIntr);
    HW_WR_REG32((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapTimeCounter);
    HW_WR_REG32((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCaptEvt1);
    HW_WR_REG32((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCaptEvt2);
    HW_WR_REG32((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCaptEvt3);
    HW_WR_REG32((baseAddr + PWMSS_ECAP_OFFSET) + PWMSS_CLKCONFIG,
        pCtx->ecapCaptEvt4);
}

/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */

uint32_t ECAPClockEnableStatusGet(uint32_t baseAddr)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + PWMSS_CLKSTATUS);
    return (HW_GET_FIELD(regVal, PWMSS_CLKSTATUS_ECAP_CLK_EN_ACK));
}

uint32_t ECAPClockDisableStatusGet(uint32_t baseAddr)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + PWMSS_CLKSTATUS);
    return (HW_GET_FIELD(regVal, PWMSS_CLKSTATUS_ECAP_CLKSTOP_ACK));
}
