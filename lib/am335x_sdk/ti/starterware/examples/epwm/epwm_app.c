/**
 * \file   epwm_app.c
 *
 * \brief  Source file containing the EPWM IP related configuration functions.
 *         These functions will be called by example application.
 *
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
#include "chipdb.h"
#include "pinmux.h"
#include "epwm.h"
#include "error.h"
#include "console_utils.h"
#include "soc_control.h"

/* Application header files */
#include "epwm_app.h"
#include "prcm.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* TODO: This macro is not needed. This value should be provided by PRCM info. */
/** \brief Functional clock to the PWMSS. */
#define SOC_EHRPWM_2_MODULE_FREQ      (100U * FREQ_MHZ)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API configures the ePWM module
 *
 * \param   pObj             pointer to the ePwm object data structure.
 */
static void EpwmAppPwmCfg(epwmAppPwmObj_t *pObj);

/**
 * \brief   This API configures the Timebase Sub-module.
 *
 * \param   baseAddr           Base address of PWMSS instance used
 * \param   pwmFuncClk         PWM functional clock value in Hz
 * \param   epwmTimebaseCfg_t  Pointer to the Time base sub-module configuration
 *                             data structure
 */
static void EpwmAppTimebaseModuleCfg(uint32_t baseAddr,
                                     uint32_t pwmFuncClk,
                                     epwmTimebaseCfg_t *pTbCfg);

/**
 * \brief   This API configures the Counter-Comparator Sub-module.
 *
 * \param   baseAddr             Base address of PWMSS instance used
 * \param   epwmCounterCmpCfg_t  Pointer to the Counter-Comparator Sub-module
 *                               configuration data structure
 */
static void EpwmAppCounterComparatorCfg(uint32_t baseAddr,
                                        epwmCounterCmpCfg_t *pCcCfg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief IP default configuration */
epwmAppPwmObj_t EPWMAPPPWMOBJ_DEFAULT =
{
    0U, /* pwmCh*/
    0U, /* instNum*/
    0U, /* instAddr*/
    0U, /* funcClk*/
    FALSE, /* enableDeadband */
    FALSE, /* enableChopper */
    FALSE, /* enableTripzone */
    FALSE, /* enableEventTrigger */
    FALSE, /* enableHighResolution */
    {
        {
            10U * FREQ_MHZ, /* tbClk */
            0U, /* pwmtbCounterFreqPrd */
            EPWM_TB_COUNTER_DIR_UP, /* tbCntrDirection */
            FALSE, /* enableSynchronization */
            0U, /* cntDirAfterSync */
            0U, /* phsCountAfterSync */
            0U  /* syncOutSrc */
        }, /* epwmTimebaseCfg_t */
        {
            0U, /* cmpAValue */
            0U  /* cmpBValue */
        }, /* epwmCounterCmpCfg_t */
        {
            EPWM_AQ_ACTION_DONOTHING, /* zeroAction */
            EPWM_AQ_ACTION_DONOTHING, /* prdAction */
            EPWM_AQ_ACTION_DONOTHING, /* cmpAUpAction */
            EPWM_AQ_ACTION_DONOTHING, /* cmpADownAction */
            EPWM_AQ_ACTION_DONOTHING, /* cmpBUpAction */
            EPWM_AQ_ACTION_DONOTHING  /* cmpBDownAction */
        }, /* epwmAqActionCfg_t */
        {
            0U, /* inputMode */
            0U, /* outputMode */
            0U, /* polaritySelect */
            0U, /* risingEdgeDelay */
            0U  /* fallingEdgeDelay */
        }, /* epwmDeadbandCfg_t*/
        {
            0U, /* dutyCycle */
            0U, /* clkFrequency */
            0U  /* oneShotPulseWidth */
        }, /* epwmChopperCfg_t */
        {
            0U, /* tripAction */
            0U, /* tripEvtType */
            0U, /* tripPin */
            0U  /* enableTripIntr */
        }, /* epwmTripzoneCfg_t */
        {
            0U, /* intrEvtSource */
            0U  /* intrPrd */
        }  /* epwmEtCfg_t */
    } /* epwmAppPwmCfg_t*/
}; /* epwmAppPwmObj_t */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t EPWMAppInit(epwmAppPwmObj_t *pPwm)
{
    int32_t status = S_PASS;
	uint16_t ePwmSubmodType = PINMUX_SS_PWMSS_EHRPWM0;

    /* Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_PWMSS, pPwm->instNum, 0);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n FAILURE!!! Clock Configuration failed !\n");
    }
    else
    {
        /* PinMux Configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_PWMSS, pPwm->instNum, &ePwmSubmodType);
        if(S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n FAILURE!!! Pin Muxing failed !\n");
        }
        else
        {
            /* Get the functional clock value of PWMSS */
            /* TODO: This value has to be provided by the PRCM data base */
            pPwm->funcClk = SOC_EHRPWM_2_MODULE_FREQ;

            /* Enable clocks for EPWM module inside the PWM sub system. */
            EHRPWMClockEnable(pPwm->instAddr);

            /* Enable Time base clock for PWMSS module */
            SOCCtrlPwmssTimebaseClkEnable(pPwm->instNum);

            /* EPWM channel configuration */
            EpwmAppPwmCfg(pPwm);
        }
    }

    return status;
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void EpwmAppPwmCfg(epwmAppPwmObj_t *pObj)
{
    uint32_t baseAddr = pObj->instAddr;
    uint32_t pwmCh    = pObj->pwmCh;
    uint32_t pwmFuncClk = pObj->funcClk;
    epwmAppPwmCfg_t *pPwm = &pObj->pwmCfg;

    /* Configure the Time base Sub-Module */
    EpwmAppTimebaseModuleCfg(baseAddr, pwmFuncClk, &pPwm->tbCfg);

    /* Counter-Comparator Sub-Module Configuration */
    EpwmAppCounterComparatorCfg(baseAddr, &pPwm->ccCfg);

    /* Configure Action Qualifier */
    EPWMAqActionOnOutputCfg(baseAddr, pwmCh, &pPwm->aqCfg);

    /* Dead band sub-module configuration */
    if(TRUE == pObj->enableDeadband)
    {
       /* Enable and configure dead band sub module */
       EPWMDeadbandCfg(baseAddr, &pPwm->dbCfg);
    }
    else
    {
        /* Bypass dead band sub module */
        EPWMDeadbandBypass(baseAddr);
    }

    /* Chopper sub-module configuration */
    if(TRUE == pObj->enableChopper)
    {
        /* Configure chopper sub - module */
        EPWMChopperCfg(baseAddr, &pPwm->chpCfg);

        /* Enable Chopper */
        EPWMChopperEnable(baseAddr, TRUE);
    }
    else
    {
        /* Disable Chopper */
        EPWMChopperEnable(baseAddr, FALSE);
    }

    /* Trip Zone Sub-Module Configuration */
    if(TRUE == pObj->enableTripZone)
    {
        /* Configure the Trip action */
        EPWMTzTriggerTripAction(baseAddr, EPWM_TZ_TRIP_ACTION_HIGH, pwmCh);

        /* Enable the Trip event */
        EPWMTzTripEventEnable(baseAddr, pPwm->tzCfg.tripEvtType,
            pPwm->tzCfg.tripPin);
    }
    else
    {
        /* Disable trip zone event handling and ignore all trip zone events */
        EPWMTzTripEventDisable(baseAddr, EPWM_TZ_EVENT_ONE_SHOT,
            pPwm->tzCfg.tripPin);
        EPWMTzTripEventDisable(baseAddr, EPWM_TZ_EVENT_CYCLE_BY_CYCLE,
            pPwm->tzCfg.tripPin);
    }

    /* Event trigger sub - module configuration */
    if(TRUE == pObj->enableEventTrigger)
    {
        /* Configure the Event trigger processing */
        EPWMEtIntrCfg(baseAddr, pPwm->etCfg.intrEvtSource, pPwm->etCfg.intrPrd);
    }
    else
    {
        /* Disable Event trigger interrupts */
        EPWMEtIntrDisable(baseAddr);
    }

    /**
     * High resolution feature is supported only on PWM A channel. If channel
     * is A then proceed with High Resolution processing.
     */
    if(EPWM_OUTPUT_CH_A == pwmCh)
    {
        if(TRUE == pObj->enableHighResolution)
        {
            /* configure high resolution feature */
            EHRPWMConfigHR(baseAddr, pPwm->hrCfg.delayBusSelect,
                pPwm->hrCfg.delayMode);

            if(EPWM_HR_DELAY_BUS_SEL_CMPAHR == pPwm->hrCfg.delayBusSelect)
            {
                /* Load comparator A High-resolution counter value */
                EPWMHrLoadCmpAHrValue(baseAddr, pPwm->hrCfg.cmpAHighResVal,
                    EPWM_HR_REG_ACT_LOAD_CNT_ZRO_PULSE);
            }
            else  /* EPWM_HR_DELAY_BUS_SEL_TBPHSHR */
            {
                /* Load Timebase phase high resolution value */
                EHRPWMLoadTBPHSHR(baseAddr,
                    pPwm->hrCfg.tbPhaseHighResVal);
            }
        }
        else
        {
            /* Disable High Resolution Feature */
            EHRPWMHRDisable(baseAddr);
        }
    }
}


static void EpwmAppTimebaseModuleCfg(uint32_t baseAddr,
                                     uint32_t pwmFuncClk,
                                     epwmTimebaseCfg_t *pTbCfg)
{
    /* Configure Time base clock */
    EHRPWMTimebaseClkConfig(baseAddr, pTbCfg->tbClk, pwmFuncClk);

    /* Configure PWM time base counter frequency and direction */
    EPWMTbPwmFreqCfg(baseAddr, pTbCfg->tbClk,
        pTbCfg->pwmtbCounterFreqPrd, pTbCfg->tbCntrDirection,
        EPWM_SHADOW_REG_CTRL_DISABLE);

    if(TRUE == pTbCfg->enableSynchronization)
    {
        /* Enable Synchronization */
        EPWMTbSyncEnable(baseAddr, pTbCfg->phsCountAfterSync,
            pTbCfg->cntDirAfterSync);
    }
    else
    {
        /* Disable Synchronization */
        EHRPWMTimebaseSyncDisable(baseAddr);
    }

    /* Configure Sync out signal */
    EPWMTbSetSyncOutMode(baseAddr, pTbCfg->syncOutSrc);

    /* Configure the emulation behaviour */
    EPWMTbSetEmulationMode(baseAddr, EPWM_TB_EMU_MODE_STP_AFT_NEXT_CYCLE);
}

static void EpwmAppCounterComparatorCfg(uint32_t baseAddr,
                                     epwmCounterCmpCfg_t *pCcCfg)
{
    /* Counter Comparator A configuration */
    EPWMCounterComparatorCfg(baseAddr, EPWM_CC_CMP_A, pCcCfg->cmpAValue,
        EPWM_SHADOW_REG_CTRL_DISABLE, EPWM_CC_CMP_LOAD_MODE_NO_LOAD, TRUE);

    /* Counter Comparator B configuration */
    EPWMCounterComparatorCfg(baseAddr, EPWM_CC_CMP_B, pCcCfg->cmpBValue,
        EPWM_SHADOW_REG_CTRL_DISABLE, EPWM_CC_CMP_LOAD_MODE_NO_LOAD, TRUE);
}
