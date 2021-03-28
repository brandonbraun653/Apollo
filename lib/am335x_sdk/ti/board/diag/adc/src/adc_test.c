/**
 * \file     adc_test.c
 *
 * \brief    This application demonstrates the configuration and usage of
 *           ADC.
 *
 */

/*
 * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdio.h>
#include <stdlib.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/starterware/include/tsc_adc_ss.h>
#include <ti/starterware/include/interrupt.h>

#include "board.h"
#include "board_cfg.h"

/******************************************************************************
**              INTERNAL MACRO DEFINITIONS
******************************************************************************/
#define VOLTAGE_RESOLUTION              (439U)

/* Macro representing the module clock of TSCADC. */
#define TSCADC_MODULE_CLOCK             (24000000U)

/* Macro representing the AFE clock of TSCADC. */
#define TSCADC_AFE_CLOCK                (3000000U)

/* Macro representing the base address of TSCADC module. */
#define TSCADC_BASE_ADDR                (0x44E0D000U)

/* Macro representing the interrupt numbers of ADC. */
#if defined(SOC_AM335x)
#define TSCADC_INTR_NUM                 (16U)
#elif defined(SOC_AM437x)
#define TSCADC_INTR_NUM                 (48U)
#endif

/** \brief Successful completion of the functionality.  */
#define S_PASS                  (0)
/** \brief Generic failure code.                        */
#define E_FAIL                  (-1)

#define TRUE     (1U)

#define FALSE    (0U)

/******************************************************************************
**              GLOBAL VARIABLE DEFINITIONS
******************************************************************************/

/** \brief Structure holding ADC interrupt configuration parameters. */
typedef struct adcAppIntrCfgObj
{
    intcTrigType_t trigType;
    /**< Type of interrupt Edge/Level. */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t intrPriority;
    /**< Interrupt priority level. */
    uint32_t isIntrSecure;
    /**< Secure Interrupt or not */
    volatile uint32_t endOfSeqIntr;
    /**< Variable to control the flow between application code and ISR when
         End of sequence interrupt occurs. */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this. If set to null then polling Mode is assumed
     */
}adcAppIntrCfgObj_t;

/**< \brief Structure holding the ADC object data structure. */
typedef struct adcAppCfgObj
{
    uint32_t instNum;
    /**< ADC instance number. */
    uint32_t instAddr;
    /**< ADC instance address. */
    uint32_t intrNum;
    /**< ADC interrupt number */
    uint32_t modClk;
    /**< ADC module clock. */
    uint32_t afeInClk;
    /**< Input clock to AFE. */
    volatile uint32_t endOfSeqIntr;
    /**< Variable to control the flow between application code and ISR when
         End of sequence interrupt occurs. */
}adcAppCfgObj_t;

/** \brief Global object for the ADC volt measure application. */
static adcAppCfgObj_t gVoltMeasureAppCfg;

/** \brief Variable to hold the sample values. */
static uint32_t gVoltMeasureAppSampleVal[2U];

/******************************************************************************
**              INTERNAL FUNCTION PROTOTYPES
******************************************************************************/

/**
 * \brief   ADC Interrupt Service Routine. This function will read and clear the
 *          status of the Tx/Rx interrupts when generated. Will read the data
 *          from the ADC Fifo.
 *
 * \param   intrId         Interrupt ID.
 * \param   cpuId          CPU ID.
 * \param   pUserParam     User parameters.
 */
static void BoardDiag_AdcIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/**
 * \brief   Configure the ADC interrupts to interrupt controller.
 *
 * \param   pCfgAdc        Pointer to the ADC configuration structure.
 *
 * \retval  S_PASS         Interrupt configuration successful.
 * \retVal  E_FAIL         Interrupt configuration failed.
 *
 */
static int32_t BoardDiag_AdcIntrConfig(adcAppCfgObj_t *pCfgAdc);

/**
 * \brief   Initialize the ADC including setting up interrupts and
 *          Step configurations.
 *
 * \param   pCfgAdc    Pointer to the ADC configuration structure.
 *
 */
static void BoardDiag_ADCConfigure(adcAppCfgObj_t *pCfgAdc);

/**
 * \brief   API to demonstrate the ADC diagnostic test use case.
 *
 *
 * \retval  S_PASS         if the Test is successful.
 * \retVal  E_FAIL         if the Test fails.
 */
int32_t BoardDiag_ADCTest();

/**
 * \brief   API to get SOC specific information like interrupt number and
 *          base addresses.
 *
 * \param   pCfgAdc    Pointer to the ADC configuration structure.
 *
 */
static void BoardDiag_AdcSocInfoGet(adcAppCfgObj_t *pObj);

/****************************************************************************/
/*             LOCAL FUNCTION DEFINITIONS                                   */
/****************************************************************************/

int main(void)
{
    Board_initCfg boardCfg;
    int32_t status = S_PASS;

#ifdef PDK_RAW_BOOT
    boardCfg = (BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO);
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    status = BoardDiag_ADCTest();

    if(S_PASS == status)
    {
        UART_printf("Test PASSED! \n");
    }
    else
    {
        UART_printf("Test Failed!\n");
    }

    return status;
}

int32_t BoardDiag_ADCTest()
{
    int32_t status = S_PASS;
    uint32_t chan1 = 0U, chan2 = 0U, fifoCount = 0U;

    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 ADC Test                  *\n");
    UART_printf  ("*********************************************\n");

    BoardDiag_AdcSocInfoGet(&gVoltMeasureAppCfg);

    /* Configure the ADC interrupts. */
    status = BoardDiag_AdcIntrConfig(&gVoltMeasureAppCfg);

    if (S_PASS == status)
    {
        /* Configure the ADC. */
        BoardDiag_ADCConfigure(&gVoltMeasureAppCfg);

        /* Wait till the ADC processes the analog lines. */
        while(1U != gVoltMeasureAppCfg.endOfSeqIntr);

        fifoCount = TSCADCGetFifoWordCount(gVoltMeasureAppCfg.instAddr,
                        TSCADC_FIFO_SEL_0);

        if (fifoCount != 0U)
        {
            /* Read the sample data from the FIFO0. */
            gVoltMeasureAppSampleVal[0U] =
               TSCADCFIFOADCDataRead(gVoltMeasureAppCfg.instAddr,
               TSCADC_FIFO_SEL_0);

            chan1 = (gVoltMeasureAppSampleVal[0U] * VOLTAGE_RESOLUTION) / 1000U;

            UART_printf("Voltage sensed on the AN0 line :");

            UART_printf("%dmV\r\n", chan1);

            fifoCount = TSCADCGetFifoWordCount(gVoltMeasureAppCfg.instAddr,
                        TSCADC_FIFO_SEL_1);

            if (fifoCount != 0U)
            {
                /* Read the sample data from the FIFO1. */
                gVoltMeasureAppSampleVal[1U] =
                       TSCADCFIFOADCDataRead(gVoltMeasureAppCfg.instAddr,
                           TSCADC_FIFO_SEL_1);

                chan2 = (gVoltMeasureAppSampleVal[1U] * VOLTAGE_RESOLUTION) / 1000U;

                UART_printf("Voltage sensed on the AN1 line :");

                UART_printf("%dmV\r\n", chan2);
            }
            else
            {
                status = E_FAIL;
            }
        }
        else
        {
            status = E_FAIL;
        }

        /* Disable the ADC. */
        TSCADCEnable(gVoltMeasureAppCfg.instAddr, FALSE);
    }
    else
    {
        /* ADC Initialization failed. */
        status = E_FAIL;
    }

    return status;
}

/* ADC is configured */
static void BoardDiag_ADCConfigure(adcAppCfgObj_t *pCfgAdc)
{
    uint32_t fifoNum[2U];
    uint32_t index;
    tscAdcStepCfg_t adcStepCfg;

    /* Configure the ADC AFE clock. */
    TSCADCClkDivConfig(pCfgAdc->instAddr,
                       pCfgAdc->modClk,
                       pCfgAdc->afeInClk);

    /* Enable the step ID tag. */
    TSCADCStepIdTagEnable(pCfgAdc->instAddr, TRUE);

    /* Disable the write protection for Step config registers. */
    TSCADCStepConfigProtectionEnable(pCfgAdc->instAddr, FALSE);

    adcStepCfg.adcNegativeInpRef = TSCADC_NEGATIVE_REF_VSSA;
        adcStepCfg.adcPositiveInpRef = TSCADC_POSITIVE_REF_VDDA;
        adcStepCfg.adcNegativeInpChan = TSCADC_INPUT_CHANNEL1;
        adcStepCfg.adcPositiveInpChan = TSCADC_INPUT_CHANNEL1;
        adcStepCfg.enableXppsw = TRUE;
        adcStepCfg.enableXnpsw = FALSE;
        adcStepCfg.enableYppsw = FALSE;
        adcStepCfg.enableXnnsw = TRUE;
        adcStepCfg.enableYpnsw = FALSE;
        adcStepCfg.enableYnnsw = FALSE;
        adcStepCfg.enableWpnsw = FALSE;

    /* Enable ADC for GP mode. */
    TSCADCTSModeConfig(pCfgAdc->instAddr, TSCADC_MODE_FOUR_WIRE);

    fifoNum[0U] = TSCADC_FIFO_SEL_0;
    fifoNum[1U] = TSCADC_FIFO_SEL_1;

    for (index = 0U; index < 2U; index++)
    {
        if (1U == index)
        {
            adcStepCfg.adcPositiveInpChan = TSCADC_INPUT_CHANNEL2;
        }

        /* Configure the ADC steps. */
        TSCADCStepConfig(pCfgAdc->instAddr, (index + 1U),
                         FALSE, &adcStepCfg);

        /* Configure the ADC FIFO. */
        TSCADCFIFOIRQThresholdLevelConfig(pCfgAdc->instAddr, (index + 1U),
                             fifoNum[index], 2U, TRUE);

        /* Configure the Step mode. */
        TSCADCStepMode(pCfgAdc->instAddr, (index + 1U),
                       TSCADC_STEP_MODE_SW_ENABLED_ONE_SHOT);

        /* Enable the ADC steps. */
        TSCADCConfigureStepEnable(pCfgAdc->instAddr, (index + 1U), TRUE);
    }

    TSCADCIntrClear(pCfgAdc->instAddr,
                    (TSCADC_INTR_MASK_HW_PEN_EVENT_ASYNC |
                    TSCADC_INTR_MASK_END_OF_SEQUENCE |
                    TSCADC_INTR_MASK_FIFO0_THRESHOLD |
                    TSCADC_INTR_MASK_FIFO0_OVERRUN |
                    TSCADC_INTR_MASK_FIFO0_UNDERFLOW |
                    TSCADC_INTR_MASK_FIFO1_THRESHOLD |
                    TSCADC_INTR_MASK_FIFO1_OVERRUN |
                    TSCADC_INTR_MASK_FIFO1_UNDERFLOW |
                    TSCADC_INTR_MASK_OUT_OF_RANGE |
                    TSCADC_INTR_MASK_PEN_UP_EVENT |
                    TSCADC_INTR_MASK_HW_PEN_EVENT_SYNC));

    TSCADCEventInterruptEnable(pCfgAdc->instAddr, TSCADC_INTR_MASK_END_OF_SEQUENCE);

    TSCADCEnable(pCfgAdc->instAddr, TRUE);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void BoardDiag_AdcSocInfoGet(adcAppCfgObj_t *pObj)
{
    /* Update SOC specific information for ADC module. */
    pObj->instAddr = TSCADC_BASE_ADDR;
    pObj->modClk = TSCADC_MODULE_CLOCK;
    pObj->afeInClk = TSCADC_AFE_CLOCK;
    pObj->intrNum = TSCADC_INTR_NUM;
}

static int32_t BoardDiag_AdcIntrConfig(adcAppCfgObj_t *pCfgAdc)
{
    int32_t retVal = S_PASS;
    intcIntrParams_t gAdcIntrCfg;

    INTCInit(FALSE);

    gAdcIntrCfg.triggerType = INTC_TRIG_HIGH_LEVEL;
    gAdcIntrCfg.priority = 0x20U;
    gAdcIntrCfg.pFnIntrHandler = BoardDiag_AdcIsr;
    gAdcIntrCfg.pUserParam = pCfgAdc;
    gAdcIntrCfg.isIntrSecure = FALSE;

    if(S_PASS != INTCConfigIntr(pCfgAdc->intrNum, &gAdcIntrCfg, FALSE))
    {
        UART_printf("FAILURE!!!.\r\n");
        UART_printf("Configuration failed for ADC interrupt.\r\n");
        retVal = E_FAIL;
    }

    return (retVal);
}

/* Reads the data from FIFO 0 and FIFO 1 */
static void BoardDiag_AdcIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    uint32_t status;
    adcAppCfgObj_t *instObj = (adcAppCfgObj_t *) pUserParam;

    /* Read the interrupt status. */
    status = TSCADCIntStatus(instObj->instAddr);

    /* Check if End of sequence interrupt. */
    if(status & TSCADC_INTR_MASK_END_OF_SEQUENCE)
    {
        /* Clear the Interrupt status for end of sequence interrupt. */
        TSCADCIntrClear(instObj->instAddr,
                                    TSCADC_INTR_MASK_END_OF_SEQUENCE);

        /*
        ** Disable the end of sequence interrupt. The interrupt can be re-enabled
        ** in the main function to capture the data signal in a real world use case.
        */
        TSCADCEventInterruptDisable(instObj->instAddr, TSCADC_INTR_MASK_END_OF_SEQUENCE);

        /* Set the interrupt flag. */
        instObj->endOfSeqIntr = 1U;
    }
}
