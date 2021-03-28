/*
 *  Copyright (c) Texas Instruments Incorporated 2020
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
 *  \file     epwm_app.c
 *
 *  \brief    This file contains PWM test application which sets a particular
 *            duty cycle in PWMSS1 output A (EHRPWM1A) which can be verified
 *            through external pin probing.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "epwm_app.h"

#if defined (SOC_AM65XX)
/** \brief Pad configuration settings. */
#define PADCFG_GPI_SELECT_MASK          (0xFFFFFFF0)    /* no write to PULLUDEN */
#define PADCFG_GPI_INPUT_ENABLE         (0x01240000)    /* PULLUDEN=1 => disabled */
#define PADCFG_GPO_SELECT_MASK          (0xFFDAFFF0)    /* PULLUDEN=0 => enabled */
#define PADCFG_GPO_OUTPUT_ENABLE        (0x00000000)    /* no write to PULLUDEN */
#define CTRLMMR_PADCONFIG33_MMODE       ( 5 )           /* EHRPWM0_A pad mux mode setting */

/** \brief ePWM instance IDs */
#define APP_EPWM0_INST_ID   ( 0 )
#define APP_EPWM1_INST_ID   ( 1 )
#define APP_EPWM2_INST_ID   ( 2 )
#define APP_EPWM3_INST_ID   ( 3 )
#define APP_EPWM4_INST_ID   ( 4 )
#define APP_EPWM5_INST_ID   ( 5 )

/** \brief Kick0 protection register unlock value. */
#define KICK0_UNLOCK_VAL    ( 0x68EF3490 )
/** \brief Kick1 protection register unlock value. */
#define KICK1_UNLOCK_VAL    ( 0xD172BC5A )

/** \brief Enable clocks to epwm. */
#define APP_MAIN_CTRL_MMR_CFG0_EPWM0_CTRL_TB_CLKEN_EN   ( 0x1U )

/* Configure EPWM pads */
static void EpwmAppCfgEPwmPads(void);
/* Enable ePWM clock */
static void EpwmAppTbClockEnable(uint32_t pwmId);

#if defined (BUILD_MCU)
/* Status codes */
#define CFG_HOST_INTR_ERR_NERR              (  0 )  /* no error */
#define CFG_HOST_INTR_ERR_CFG_INTR_RTR      ( -1 )  /* interrupt router configuration error */

/* MAIN2MCU_PLS_INTRTR0 EPWM_0_INT input interrupt */
#define MAIN2MCU_PLS_INTR0_IN_EPWM_0_INT    ( 2 )

/* MAIN2MCU_PLS_INTRTR0 output interrupt */
#define MAIN2MCU_PLS_INTR0_OUT              ( 0 )
/* VIM input interrupt */
#define MCU0_INTR_IN_EPWM0_INT              ( CSL_MCU0_INTR_MAIN2MCU_PULSE_INTR0_OUTP_0 + MAIN2MCU_PLS_INTR0_OUT )
/* VIM interrupt priority, 0...15 (0:high, 15:low) */
#define MCU0_INTR_IN_EPWM0_INT_PRI          ( 0 )

/*
    Determines how MAIN2MCU Interrupt Router is configured.
    
     Defined: use CSL-FL for MAIN2MCU Interrupt Router configuration.
   Undefined: use Sciclient() for MAIN2MCU Interrupt Router configuration. 
   
    Note on Defined case:
        Using CSL-FL for Interrupt Router configuration because of SYSFW bug 
        SYSFW-3397. Under normal circumstances, Sciclient() should be used 
        for Interrupt Router configuration. If using updated SYSFW 
        (i.e. fixed for SYSFW-3397), then should switch to Undefined case.
*/
#define DEBUG_CSL_INTR_RTR_CFG

#if defined (DEBUG_CSL_INTR_RTR_CFG)
/* MAIN2MCU_PLS_INTRTR0 input interrupt */
#define MAIN2MCU_PLS_INTR0_IN               ( MAIN2MCU_PLS_INTR0_IN_EPWM_0_INT )

/* MAIN2MCU_PLS_INTRTR0 number of input interrupts */
#define NUM_MAIN2MCU_PLS_INTR0_IN           ( 32 )
/* MAIN2MCU_PLS_INTRTR0 number of output interrupts */
#define NUM_MAIN2MCU_PLS_INTR0_OUT          ( 48 )

/* Configure MAIN2MCU_PLS_INTRTR0 interrupt router */
int32_t configureIntrRouter(
    uint32_t intrRtrInIntNum, 
    uint32_t intrRtrOutIntNum
);

#else /* DEBUG_CSL_INTR_RTR_CFG */
/* TISCI IRQ source index for EPWM0, bus_epwm_etint */
#define APP_TISCI_DEV_EHRPWM0_IRQ_SRC_IDX   ( 2 )

/* Configure MAIN2MCU_PLS_INTRTR0 interrupt router */
int32_t configureIntrRouter(
    uint32_t armss0cpu0InIrqNum
);
#endif /* DEBUG_CSL_INTR_RTR_CFG */
#endif /* BUILD_MCU */
#endif /* SOC_AM65XX */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Status codes */
#define APP_ERR_SOK                 (  0 )  /* no error */
#define APP_ERR_PAD_CFG_PM_ERR      ( -1 )  /* pad config, PM error */
#define APP_ERR_GET_FUNC_CLK        ( -2 )  /* get functional clock error */
#define APP_ERR_BOARD_INIT          ( -3 )  /* board init error */

/*
 * Configurable parameters
 */
/**
 *  \brief PWM instance base address.
 *
 *  Note: If changed to other instance, PRCM and pinmux changes needs to be
 *  taken care in the application.
 */
#if defined (SOC_AM65XX)
#define APP_EHRPWM_INST_BASE_ADDR       (CSL_EHRPWM0_EPWM_BASE)
#else
#define APP_EHRPWM_INST_BASE_ADDR       (SOC_PWMSS1_IPWMSS_BASE)
#endif

/**
 *  \brief Output channel - A or B.
 *
 *  Note: If changed to channel B, pinmux changes needs to be taken care
 *  in the application.
 */
#define APP_EHRPWM_OUTPUT_CH            (CSL_EPWM_OUTPUT_CH_A)

/** \brief Frequency of PWM output signal in Hz - 1 KHz is selected */
#define APP_EHRPWM_OUT_FREQ             (1U * 1000U)

/** \brief Duty Cycle of PWM output signal in % - give value from 0 to 100 */
#define APP_EHRPWM_DUTY_CYCLE           (25U)

/** \brief APP run time in seconds */
#define APP_RUN_TIME                    (10U)

/** \brief APP run count in event equal zero ISR count */
#define APP_RUN_TIME_ISRCOUNT           (APP_RUN_TIME * APP_EHRPWM_OUT_FREQ)

/**
 *  \brief Functional clock to the PWMSS.
 *  Fixed for the platform - can't be changed.
 */
#define SOC_EHRPWM_MODULE_FREQ          (133U * 1000U * 1000U)

/** \brief TB frequency in Hz - so that /4 divider is used */
#define APP_EHRPWM_TB_FREQ              (SOC_EHRPWM_MODULE_FREQ / 4U)

/**
 *  \brief PRD value - this determines the period
 *
 *  PRD = (TBCLK/PWM FREQ) / 2
 *  NOTE: /2 is added becasue up&down counter is selected. So period is 2 times
 */
#define APP_EHRPWM_PRD_VAL              ((APP_EHRPWM_TB_FREQ                   \
                                            / APP_EHRPWM_OUT_FREQ) / 2U)
/**
 *  \brief COMPA value - this determines the duty cycle
 *
 *  COMPA = (PRD - ((dutycycle * PRD) / 100)
 */
#define APP_EHRPWM_COMPA_VAL            (APP_EHRPWM_PRD_VAL -                  \
                                            ((APP_EHRPWM_DUTY_CYCLE *          \
                                                APP_EHRPWM_PRD_VAL) / 100U))

#define APP_EHRPWM_INT                  (32U)
#define APP_EHRPWM_XBAR_CPU             (CSL_XBAR_IRQ_CPU_ID_IPU1)
#define APP_EHRPWM_XBAR_INST            (CSL_XBAR_INST_IPU1_IRQ_32)
#define APP_EHRPWM_XBAR_INTR_SOURCE     (CSL_XBAR_PWMSS1_IRQ_ePWM0INT)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief IP default configuration */
static CSL_EpwmAppPwmObj_t gAppPwmObj =
{
    APP_EHRPWM_OUTPUT_CH,                       /* pwmCh */
    APP_EHRPWM_INST_BASE_ADDR,                  /* instAddr */
    SOC_EHRPWM_MODULE_FREQ,                     /* funcClk */
    FALSE,                                      /* enableDeadband */
    FALSE,                                      /* enableChopper */
    FALSE,                                      /* enableTripzone */
    TRUE,                                       /* enableEventTrigger */
    FALSE,                                      /* enableHighResolution */
    /* CSL_EpwmAppPwmCfg_t*/
    {
        /* CSL_EpwmTimebaseCfg_t */
        {
            APP_EHRPWM_TB_FREQ,                 /* tbClk */
            APP_EHRPWM_OUT_FREQ,                /* pwmtbCounterFreqPrd */
            CSL_EPWM_TB_COUNTER_DIR_UP_DOWN,    /* tbCntrDirection */
            FALSE,                              /* enableSynchronization */
            PWMSS_EPWM_TBCTL_PHSDIR_COUNT_DOWN, /* cntDirAfterSync */
            0U,                                 /* phsCountAfterSync */
            PWMSS_EPWM_TBCTL_SYNCOSEL_EPWMXSYNC /* syncOutSrc */
        },
        /* CSL_EpwmCounterCmpCfg_t */
        {
            APP_EHRPWM_COMPA_VAL,               /* cmpAValue */
            APP_EHRPWM_COMPA_VAL                /* cmpBValue */
        },
        /* CSL_EpwmAqActionCfg_t */
        {
            CSL_EPWM_AQ_ACTION_DONOTHING,       /* zeroAction */
            CSL_EPWM_AQ_ACTION_DONOTHING,       /* prdAction */
            CSL_EPWM_AQ_ACTION_HIGH,            /* cmpAUpAction */
            CSL_EPWM_AQ_ACTION_LOW,             /* cmpADownAction */
            CSL_EPWM_AQ_ACTION_HIGH,            /* cmpBUpAction */
            CSL_EPWM_AQ_ACTION_LOW              /* cmpBDownAction */
        },
        /* CSL_EpwmDeadbandCfg_t */
        {
            CSL_EPWM_DB_IN_MODE_A_RED_A_FED,    /* inputMode */
            CSL_EPWM_DB_OUT_MODE_BYPASS,        /* outputMode */
            CSL_EPWM_DB_POL_SEL_ACTV_HIGH,      /* polaritySelect */
            0U,                                 /* risingEdgeDelay */
            0U                                  /* fallingEdgeDelay */
        },
        /* CSL_EpwmChopperCfg_t */
        {
            CSL_EPWM_CHP_DUTY_CYCLE_PERC_12PNT5,    /* dutyCycle */
            CSL_EPWM_CHP_CLK_FREQ_DIV_BY_1,         /* clkFrequency */
            CSL_EPWM_CHP_OSHT_WIDTH_1XSYSOUT_BY_8   /* oneShotPulseWidth */
        },
        /* CSL_EpwmTripzoneCfg_t */
        {
            CSL_EPWM_TZ_TRIP_ACTION_DO_NOTHING, /* tripAction */
            CSL_EPWM_TZ_EVENT_ONE_SHOT,         /* tripEvtType */
            0U,                                 /* tripPin */
            FALSE                               /* enableTripIntr */
        },
        /* CSL_EpwmEtCfg_t */
        {
            CSL_EPWM_ET_INTR_EVT_CNT_EQ_ZRO,    /* intrEvtSource */
            CSL_EPWM_ET_INTR_PERIOD_FIRST_EVT   /* intrPrd */
        }
    }
};

static volatile uint32_t gNumIsr = 0U;

#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
static uint32_t gUartBaseAddr = SOC_UART1_BASE;
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
static uint32_t gUartBaseAddr = SOC_UART3_BASE;
#endif


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static void AppPwmIntrISR(void *handle);

static void CSL_epwmAppPwmCfg(CSL_EpwmAppPwmObj_t *pObj);
static int32_t EPwmAppGetPwmFuncClock(CSL_EpwmAppPwmObj_t *pObj);
static void EpwmAppTimebaseModuleCfg(uint32_t baseAddr,
                                     uint32_t pwmFuncClk,
                                     CSL_EpwmTimebaseCfg_t *pTbCfg);
static void EpwmAppCounterComparatorCfg(uint32_t baseAddr,
                                        CSL_EpwmCounterCmpCfg_t *pCcCfg);

static int32_t padConfig_prcmEnable(void);

static int32_t EPwmAppBoardInit(void);
static void EPwmAppUartInit(void);
static void EPwmAppPrint(const char *str);

/* Unity functions */
void test_csl_epwm_duty_cycle_test_app_runner(void);
void test_csl_epwm_duty_cycle_test_app (void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}
#endif

void test_csl_epwm_duty_cycle_test_app (void)
{
    /* @description:Test app for PWM tests

       @requirements: PRSDK-8319

       @cores: mpu1_0, mcu1_0 */
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;
    int32_t status;

    /* Initialize board */
    status = EPwmAppBoardInit();
    if (status < 0)
    {
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_FAIL();
#endif
        return;
    }

    /* Initialize UART */
    EPwmAppUartInit();

    /* Do PRCM enable and pad config for PWM */
    status = padConfig_prcmEnable();
    if (status < 0)
    {
        EPwmAppPrint("\nError: padConfig_prcmEnable() fail.\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_FAIL();
#endif
        return;
    }

    EPwmAppPrint("\nStarting EPWM duty cycle test application...\n");
    EPwmAppPrint("Probe the PWM signal to verify...\n");
    EPwmAppPrint("App will wait for 10 seconds (using  PWM period ISR)...\n");
    EPwmAppPrint("Probe ");
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
    EPwmAppPrint("VIN2A_VSYNC0 pin (RU19 pin 12) ");
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    EPwmAppPrint("GPMC_BEN0 pin (R9017/M1 of VISU connector) ");
#elif defined (SOC_AM65XX)
    EPwmAppPrint("R154 ");
#endif
    EPwmAppPrint("for 1KHz @ 25 percent duty cycle waveform...\n");

    /* Enable clocks for EPWM module inside the PWM sub system. */
    CSL_epwmClockEnable(pObj->instAddr);

    /* Get ePWM module functional clock */
    status = EPwmAppGetPwmFuncClock(pObj);
    if (status < 0)
    {
        EPwmAppPrint("\nError: EPwmAppGetPwmFuncClock() fail.\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_FAIL();
#endif
        return;
    }

    /* EPWM channel configuration */
    CSL_epwmAppPwmCfg(pObj);

    /* Wait for ISR count */
    while (gNumIsr < APP_RUN_TIME_ISRCOUNT);

    EPwmAppPrint("\nApplication is completed!!\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
    EPwmAppPrint("\n All tests have passed. \n");
    TEST_PASS();
#endif

}

static void AppPwmIntrISR(void *handle)
{
    volatile uint16_t status = CSL_epwmEtIntrStatus(APP_EHRPWM_INST_BASE_ADDR);
    status = status;
    CSL_epwmEtIntrClear(APP_EHRPWM_INST_BASE_ADDR);
    gNumIsr++;
    return;
}

/**
 * \brief   This API configures the ePWM module
 *
 * \param   pObj             pointer to the ePwm object data structure.
 */
static void CSL_epwmAppPwmCfg(CSL_EpwmAppPwmObj_t *pObj)
{
    uint32_t baseAddr = pObj->instAddr;
    uint32_t pwmCh    = pObj->pwmCh;
    uint32_t pwmFuncClk = pObj->funcClk;
    CSL_EpwmAppPwmCfg_t *pPwmCfg = &pObj->pwmCfg;

    /* Configure the Time base Sub-Module */
    EpwmAppTimebaseModuleCfg(baseAddr, pwmFuncClk, &pPwmCfg->tbCfg);

    /* Counter-Comparator Sub-Module Configuration */
    EpwmAppCounterComparatorCfg(baseAddr, &pPwmCfg->ccCfg);

    /* Configure Action Qualifier */
    CSL_epwmAqActionOnOutputCfg(baseAddr, pwmCh, &pPwmCfg->aqCfg);

    /* Dead band sub-module configuration */
    if (TRUE == pObj->enableDeadband)
    {
       /* Enable and configure dead band sub module */
       CSL_epwmDeadbandCfg(baseAddr, &pPwmCfg->dbCfg);
    }
    else
    {
        /* Bypass dead band sub module */
        CSL_epwmDeadbandBypass(baseAddr);
    }

    /* Chopper sub-module configuration */
    if (TRUE == pObj->enableChopper)
    {
        /* Configure chopper sub - module */
        CSL_epwmChopperCfg(baseAddr, &pPwmCfg->chpCfg);

        /* Enable Chopper */
        CSL_epwmChopperEnable(baseAddr, TRUE);
    }
    else
    {
        /* Disable Chopper */
        CSL_epwmChopperEnable(baseAddr, FALSE);
    }

    /* Trip Zone Sub-Module Configuration */
    if (TRUE == pObj->enableTripZone)
    {
        /* Configure the Trip action */
        CSL_epwmTzTriggerTripAction(
            baseAddr, CSL_EPWM_TZ_TRIP_ACTION_HIGH, pwmCh);

        /* Enable the Trip event */
        CSL_epwmTzTripEventEnable(
            baseAddr, pPwmCfg->tzCfg.tripEvtType, pPwmCfg->tzCfg.tripPin);
    }
    else
    {
        /* Disable trip zone event handling and ignore all trip zone events */
        CSL_epwmTzTripEventDisable(
            baseAddr, CSL_EPWM_TZ_EVENT_ONE_SHOT, pPwmCfg->tzCfg.tripPin);
        CSL_epwmTzTripEventDisable(
            baseAddr, CSL_EPWM_TZ_EVENT_CYCLE_BY_CYCLE, pPwmCfg->tzCfg.tripPin);
    }

    /* Event trigger sub - module configuration */
    if (TRUE == pObj->enableEventTrigger)
    {
        /* Configure the Event trigger processing */
        CSL_epwmEtIntrCfg(
            baseAddr, pPwmCfg->etCfg.intrEvtSource, pPwmCfg->etCfg.intrPrd);
        CSL_epwmEtIntrEnable(baseAddr);
    }
    else
    {
        /* Disable Event trigger interrupts */
        CSL_epwmEtIntrDisable(baseAddr);
    }

    /**
     * High resolution feature is supported only on PWM A channel. If channel
     * is A then proceed with High Resolution processing.
     */
    if (CSL_EPWM_OUTPUT_CH_A == pwmCh)
    {
        if (TRUE == pObj->enableHighResolution)
        {
            /* configure high resolution feature */
            CSL_epwmHighResolutionCfg(
                baseAddr,
                pPwmCfg->hrCfg.delayBusSelect,
                pPwmCfg->hrCfg.delayMode);

            if (CSL_EPWM_HR_DELAY_BUS_SEL_CMPAHR ==
               pPwmCfg->hrCfg.delayBusSelect)
            {
                /* Load comparator A High-resolution counter value */
                CSL_epwmHrLoadCmpAHrValue(
                    baseAddr,
                    pPwmCfg->hrCfg.cmpAHighResVal,
                    CSL_EPWM_HR_REG_ACT_LOAD_CNT_ZRO_PULSE);
            }
            else  /* CSL_EPWM_HR_DELAY_BUS_SEL_TBPHSHR */
            {
                /* Load Timebase phase high resolution value */
                CSL_epwmHrLoadTbPhaseHrValue(
                    baseAddr, pPwmCfg->hrCfg.tbPhaseHighResVal);
            }
        }
        else
        {
            /* Disable High Resolution Feature */
            CSL_epwmHighResolutionDisable(baseAddr);
        }
    }

    return;
}

/**
 * \brief   This API configures the Timebase Sub-module.
 *
 * \param   baseAddr        Base address of PWMSS instance used
 * \param   pwmFuncClk      PWM functional clock value in Hz
 * \param   pTbCfg          Pointer to the Time base sub-module configuration
 *                          data structure
 */
static void EpwmAppTimebaseModuleCfg(uint32_t baseAddr,
                                     uint32_t pwmFuncClk,
                                     CSL_EpwmTimebaseCfg_t *pTbCfg)
{
    /* Configure Time base clock */
    CSL_epwmTbTimebaseClkCfg(baseAddr, pTbCfg->tbClk, pwmFuncClk);

    /* Configure PWM time base counter frequency and direction */
    CSL_epwmTbPwmFreqCfg(
        baseAddr,
        pTbCfg->tbClk,
        pTbCfg->pwmtbCounterFreqPrd,
        pTbCfg->tbCntrDirection,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE);

    if (TRUE == pTbCfg->enableSynchronization)
    {
        /* Enable Synchronization */
        CSL_epwmTbSyncEnable(
            baseAddr, pTbCfg->phsCountAfterSync, pTbCfg->cntDirAfterSync);
    }
    else
    {
        /* Disable Synchronization */
        CSL_epwmTbSyncDisable(baseAddr);
    }

    /* Configure Sync out signal */
    CSL_epwmTbSetSyncOutMode(baseAddr, pTbCfg->syncOutSrc);

    /* Configure the emulation behaviour */
    CSL_epwmTbSetEmulationMode(baseAddr, EPWM_TB_EMU_MODE_FREE_RUN);

    return;
}

/**
 * \brief   This API configures the Counter-Comparator Sub-module.
 *
 * \param   baseAddr    Base address of PWMSS instance used
 * \param   pCcCfg      Pointer to the Counter-Comparator Sub-module
 *                      configuration data structure
 */
static void EpwmAppCounterComparatorCfg(uint32_t baseAddr,
                                        CSL_EpwmCounterCmpCfg_t *pCcCfg)
{
    /* Counter Comparator A configuration */
    CSL_epwmCounterComparatorCfg(
        baseAddr,
        CSL_EPWM_CC_CMP_A,
        pCcCfg->cmpAValue,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE,
        CSL_EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO,
        TRUE);

    /* Counter Comparator B configuration */
    CSL_epwmCounterComparatorCfg(
        baseAddr,
        CSL_EPWM_CC_CMP_B,
        pCcCfg->cmpBValue,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE,
        CSL_EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO,
        TRUE);

    return;
}

#if defined (SOC_AM65XX)
static int32_t padConfig_prcmEnable(void)
{
    int32_t status;
    
    /* Configure ePWM pads */
    EpwmAppCfgEPwmPads();

    /* Enable ePWM module */
    status = Sciclient_pmSetModuleState(TISCI_DEV_EHRPWM0,
        TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
        TISCI_MSG_FLAG_AOP |
        TISCI_MSG_FLAG_DEVICE_EXCLUSIVE |
        TISCI_MSG_FLAG_DEVICE_RESET_ISO,
        SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != CSL_PASS)
    {
        return APP_ERR_PAD_CFG_PM_ERR;
    }
    
    /* Enable EPWM module time base clock */
    EpwmAppTbClockEnable(APP_EPWM0_INST_ID);
    
    /* Configure interrupts */
#if defined (BUILD_MPU)
    /* Register & enable interrupt */
    Intc_Init(0);
    Intc_IntRegister(CSL_GIC0_INTR_EHRPWM0_BUS_EPWM_ETINT, 
        (IntrFuncPtr) AppPwmIntrISR, 0U);
    Intc_IntAssignEdgeIntType(CSL_GIC0_INTR_EHRPWM0_BUS_EPWM_ETINT);
    Intc_IntPrioritySet(CSL_GIC0_INTR_EHRPWM0_BUS_EPWM_ETINT, 1U, 0U);
    Intc_SystemEnable(CSL_GIC0_INTR_EHRPWM0_BUS_EPWM_ETINT);

#else /* BUILD_MPU */
#if defined (DEBUG_CSL_INTR_RTR_CFG)
    /* Configure interrupt router */
    status = configureIntrRouter(MAIN2MCU_PLS_INTR0_IN, MAIN2MCU_PLS_INTR0_OUT);
    if (status < 0)
    {
        return APP_ERR_PAD_CFG_PM_ERR;
    }
    
#else
    /* Configure interrupt router */
    status = configureIntrRouter(MCU0_INTR_IN_EPWM0_INT);
    if (status < 0)
    {
        return APP_ERR_PAD_CFG_PM_ERR;
    }
#endif

    /* Register & enable interrupt */
    Intc_Init();
    Intc_IntSetSrcType(MCU0_INTR_IN_EPWM0_INT, CSL_VIM_INTR_TYPE_PULSE);
    Intc_IntPrioritySet(MCU0_INTR_IN_EPWM0_INT, MCU0_INTR_IN_EPWM0_INT_PRI, 0U);
    Intc_IntRegister(MCU0_INTR_IN_EPWM0_INT, (IntrFuncPtr)AppPwmIntrISR, 0U);
    Intc_IntEnable(MCU0_INTR_IN_EPWM0_INT);
    Intc_SystemEnable();

#endif /* BUILD_MPU */

    return APP_ERR_SOK;
}
#else /* SOC_AM65XX */
static int32_t padConfig_prcmEnable(void)
{
    /* Configure ePWM pads */
    EpwmAppCfgEPwmPads();

    /* Enable PRCM for PWMSS1 */
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_PWMSS1_CLKCTRL, 0x2);
    while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE +
                        CM_L4PER2_PWMSS1_CLKCTRL) & (0x00030000)) != 0x0) ;

    /* Time base clock for PWMSS1 module */
    HW_WR_FIELD32(
        SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_CONTROL_IO_2,
        CTRL_CORE_CONTROL_IO_2_PWMSS1_TBCLKEN,
        1);

    /* XBar configuration */
    CSL_xbarIrqConfigure(
        APP_EHRPWM_XBAR_CPU, APP_EHRPWM_XBAR_INST, APP_EHRPWM_XBAR_INTR_SOURCE);

    /* Enable periodic interrupts for PWM period */
    Intc_Init();
    Intc_IntEnable(APP_EHRPWM_INT);

    /* Register ISR */
    Intc_IntRegister(APP_EHRPWM_INT, (IntrFuncPtr) AppPwmIntrISR, 0);
    Intc_IntPrioritySet(APP_EHRPWM_INT, 1, 0);
    Intc_SystemEnable(APP_EHRPWM_INT);

    return APP_ERR_SOK;
}
#endif /* SOC_AM65XX */

/* Configure EPWM pads */
static void EpwmAppCfgEPwmPads(void)
{
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
    /* PWM Pad configurations - VIN2A_VSYNC0 -> EHRPWM1A */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_VIN2A_VSYNC0, 0x0000000A);

#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* PWM Pad configurations - GPMC_BEN0 -> EHRPWM1A */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_GPMC_BEN0, 0x00000004);

#elif defined (SOC_AM65XX)
    CSL_main_ctrl_mmr_cfg0Regs *pMainCtrlMmrCfg0Regs;
    volatile uint32_t *pMainCtrlMmrCfg0Reg;
    uint32_t regVal;
    
    pMainCtrlMmrCfg0Regs = (CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE;

    pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK7_KICK0;
    regVal = HW_RD_REG32(pMainCtrlMmrCfg0Reg);
    if (!(regVal & 0x1))
    {
        /* Unlock CTLR_MMR0 registers */
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK7_KICK0;
        HW_WR_REG32(pMainCtrlMmrCfg0Reg, KICK0_UNLOCK_VAL);
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK7_KICK1;
        HW_WR_REG32(pMainCtrlMmrCfg0Reg, KICK1_UNLOCK_VAL);
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK7_KICK0;
        do {
            regVal = HW_RD_REG32(pMainCtrlMmrCfg0Reg);
        } while (!(regVal & 0x1));
    }

    /* Configure pad for EHRPWM0_A */
    regVal = HW_RD_REG32(&pMainCtrlMmrCfg0Regs->PADCONFIG33);
    regVal &= PADCFG_GPO_SELECT_MASK;
    regVal |= PADCFG_GPO_OUTPUT_ENABLE;
    regVal |= CTRLMMR_PADCONFIG33_MMODE;
    HW_WR_REG32(&pMainCtrlMmrCfg0Regs->PADCONFIG33, regVal); 
#endif /* SOC_AM65XX */
}

#if defined (SOC_AM65XX)
/* Enable ePWM time base clock */
static void EpwmAppTbClockEnable(uint32_t pwmId)
{
    uint32_t regVal;
    
    CSL_main_ctrl_mmr_cfg0Regs *pMainCtrlMmrCfg0Regs;
    volatile uint32_t *pMainCtrlMmrCfg0Reg;

    pMainCtrlMmrCfg0Regs = (CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE;
    
    pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK1_KICK0;
    regVal = HW_RD_REG32(pMainCtrlMmrCfg0Reg);
    if (!(regVal & 0x1))
    {
        /* Unlock CTLR_MMR0 registers */
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK1_KICK0;
        HW_WR_REG32(pMainCtrlMmrCfg0Reg, KICK0_UNLOCK_VAL);
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK1_KICK1;
        HW_WR_REG32(pMainCtrlMmrCfg0Reg, KICK1_UNLOCK_VAL);
        pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->LOCK1_KICK0;
        do {
            regVal = HW_RD_REG32(pMainCtrlMmrCfg0Reg);
        } while (!(regVal & 0x1));
    }
    
    pMainCtrlMmrCfg0Reg = &pMainCtrlMmrCfg0Regs->EPWM0_CTRL + pwmId;    
    HW_WR_FIELD32(pMainCtrlMmrCfg0Reg,
        CSL_MAIN_CTRL_MMR_CFG0_EPWM0_CTRL_TB_CLKEN,
        APP_MAIN_CTRL_MMR_CFG0_EPWM0_CTRL_TB_CLKEN_EN);
}
#endif /* SOC_AM65XX */

/* Get ePWM module functional clock */
static int32_t EPwmAppGetPwmFuncClock(CSL_EpwmAppPwmObj_t *pObj)
{
#if !defined (SOC_AM65XX)
    return APP_ERR_SOK;

#else
    uint64_t respClkRate;
    uint32_t prdVal;
    int32_t status;

    /* Get ePWM0 module clock frequency */
    status = Sciclient_pmGetModuleClkFreq(TISCI_DEV_EHRPWM0,
        TISCI_DEV_EHRPWM0_BUS_VBUSP_CLK,
        &respClkRate,
        SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != CSL_PASS)
    {
        return APP_ERR_GET_FUNC_CLK;
    }
    
    /* Update object based on ePWM module frequency */
    pObj->funcClk = (uint32_t)respClkRate;
    pObj->pwmCfg.tbCfg.tbClk = pObj->funcClk / 4;
    prdVal = (pObj->pwmCfg.tbCfg.tbClk / pObj->pwmCfg.tbCfg.pwmtbCounterFreqPrd) / 2;
    pObj->pwmCfg.ccCfg.cmpAValue = prdVal - ((APP_EHRPWM_DUTY_CYCLE * prdVal)/ 100U);    
    pObj->pwmCfg.ccCfg.cmpBValue = pObj->pwmCfg.ccCfg.cmpAValue;
    
    return APP_ERR_SOK;
#endif
}

#if defined (DEBUG_CSL_INTR_RTR_CFG)
#if defined (SOC_AM65XX) && defined (BUILD_MCU)
/* Configure MAIN2MCU_LVL_INTRTR0 interrupt router */
int32_t configureIntrRouter(
    uint32_t intrRtrInIntNum, 
    uint32_t intrRtrOutIntNum
)
{
    CSL_IntrRouterCfg intrRouterMain2MCUCfg;
    int32_t retVal;

    /* Initialize Main to MCU Interrupt Router config structure */
    intrRouterMain2MCUCfg.pIntrRouterRegs = (CSL_intr_router_cfgRegs *)(uintptr_t)(CSL_MAIN2MCU_PLS_INTRTR0_CFG_BASE);
    intrRouterMain2MCUCfg.pIntdRegs       = (CSL_intr_router_intd_cfgRegs *)(uintptr_t)NULL;
    intrRouterMain2MCUCfg.numInputIntrs   = NUM_MAIN2MCU_PLS_INTR0_IN;
    intrRouterMain2MCUCfg.numOutputIntrs  = NUM_MAIN2MCU_PLS_INTR0_OUT;

    /* Route PRU INTC output interrupt to MAIN2MCU LEVEL interrupt router output */
    retVal = CSL_intrRouterCfgMux(&intrRouterMain2MCUCfg, intrRtrInIntNum, intrRtrOutIntNum);
    if (retVal < 0) 
    {
        return CFG_HOST_INTR_ERR_CFG_INTR_RTR;
    }
    
    return CFG_HOST_INTR_ERR_NERR;
}
#endif /* SOC_AM65XX && BUILD_MCU */

#else /* DEBUG_CSL_INTR_RTR_CFG */

#if defined (SOC_AM65XX) && defined (BUILD_MCU)
/* Configure MAIN2MCU_PLS_INTRTR0 interrupt router */
int32_t configureIntrRouter(
    uint32_t armss0cpu0InIrqNum
)
{
    struct tisci_msg_rm_irq_set_req rmIrqReq;
    struct tisci_msg_rm_irq_set_resp rmIrqResp;
    int32_t status;

    rmIrqReq.src_id = TISCI_DEV_EHRPWM0;
    rmIrqReq.src_index = APP_TISCI_DEV_EHRPWM0_IRQ_SRC_IDX;
    rmIrqReq.dst_id = TISCI_DEV_MCU_ARMSS0_CPU0;
    rmIrqReq.dst_host_irq = armss0cpu0InIrqNum;
    rmIrqReq.valid_params = 0x3;    /* bit mask for dst_id & dst_host_irq */
    status = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != CSL_PASS)
    {
        return CFG_HOST_INTR_ERR_CFG_INTR_RTR;
    }

    return CFG_HOST_INTR_ERR_NERR;    
}
#endif /* SOC_AM65XX && BUILD_MCU */

#endif /* DEBUG_CSL_INTR_RTR_CFG */

/* Initialize board */
static int32_t EPwmAppBoardInit(void)
{
#if defined (SOC_AM65XX)
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_UNLOCK_MMR | 
               BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        return APP_ERR_BOARD_INIT;
    }
#endif
    return APP_ERR_SOK;
}

/* Initialize UART */
static void EPwmAppUartInit(void)
{
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
    /* UART Pad configurations */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD, 0x00040000);
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD, 0x00000000);

    /* PWM Pad configurations - VIN2A_VSYNC0 -> EHRPWM1A */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_VIN2A_VSYNC0, 0x0000000A);

#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* UART Pad configurations */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK, 0x00040001);
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0, 0x00000001);

    /* PWM Pad configurations - GPMC_BEN0 -> EHRPWM1A */
    HW_WR_REG32(
        SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_GPMC_BEN0, 0x00000004);
#endif

#if !defined (SOC_AM65XX)
    /* Initialize the UART Instance */
    UARTConfigInit(gUartBaseAddr, BAUD_RATE_115200,
                   UART_WORD_LENGTH_8, UART_STOP_BIT_1,
                   UART_NO_PARITY, UART_16x_MODE);

#endif
}

/* Print string to UART */
static void EPwmAppPrint(const char *str)
{
#if defined (SOC_AM65XX)
    UART_printf(str);
#else
    UARTConfigPuts(gUartBaseAddr, str, -1);
#endif
}


void test_csl_epwm_duty_cycle_test_app_runner(void)
{
    /* @description:Test runner for EPWM tests

       @requirements: PRSDK-8319

       @cores: mpu1_0, mcu1_0 */
#if defined(UNITY_INCLUDE_CONFIG_H)
    UNITY_BEGIN();
    RUN_TEST (test_csl_epwm_duty_cycle_test_app);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
#else
    test_csl_epwm_duty_cycle_test_app();
#endif
    return;
}

int32_t main(void)
{
 (void) test_csl_epwm_duty_cycle_test_app_runner();
  while (1)
  {
  }
}
