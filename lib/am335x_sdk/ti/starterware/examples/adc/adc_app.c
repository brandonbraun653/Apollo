/**
 * \file   adc_app.c
 *
 * \brief  Source file containing the ADC IP related configuration functions.
 *         These functions will be called by example application.
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
#include "tsc_adc_ss.h"
#include "adc_app.h"
#include "error.h"
#include "prcm.h"
#include "pinmux.h"
#include "console_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the ADC interrupts to interrupt controller.
 *
 * \param   pCfgAdc        Pointer to the ADC configuration structure.
 *
 * \retval  S_PASS         Interrupt configuration successful.
 * \retVal  E_FAIL         Interrupt configuration failed.
 *
 */
static int32_t AdcAppIntrConfig(adcAppCfgObj_t *pCfgAdc);

/**
 * \brief   ADC Interrupt Service Routine. This function will read and clear the
 *          status of the Tx/Rx interrupts when generated. Will read the data
 *          from the ADC Fifo.
 *
 * \param   intrId         Interrupt ID.
 * \param   cpuId          CPU ID.
 * \param   pUserParam     User parameters.
 */
static void AdcAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t ADCAppInit(adcAppCfgObj_t *pCfgAdc)
{
    uint32_t fifoNum[2U];
    uint32_t index;
    int32_t status = S_PASS;

    tscAdcStepCfg_t adcStepCfg;

    /* Clock Configuration. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_ADC0, pCfgAdc->instNum, FALSE);

    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock Configuration failed !\n");
    }
    else
    {
        /* Configure the ADC AFE clock. */
        TSCADCClkDivConfig(pCfgAdc->instAddr,
                           pCfgAdc->modClk,
                           pCfgAdc->afeInClk);

        /* Enable the step ID tag. */
        TSCADCStepIdTagEnable(pCfgAdc->instAddr, TRUE);

        /* Disable the write protection for Step config registers. */
        TSCADCStepConfigProtectionEnable(pCfgAdc->instAddr, FALSE);

        /* Configure the ADC interrupts. */
        AdcAppIntrConfig(pCfgAdc);

        if (ADC_GP_MODE_ENABLE == pCfgAdc->appCtrl.adcMode)
        {
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
        else if (ADC_TS_MODE_ENABLE == pCfgAdc->appCtrl.adcMode)
        {
            /* Touchscreen configurations to be put here. */
            CONSOLEUtilsPrintf("Touchscreen mode is not supported!!!\r\n");
        }
        else
        {
            CONSOLEUtilsPrintf("Please select the proper value to select GP-ADC");
            CONSOLEUtilsPrintf(" mode or Touchscreen mode.\r\n");
        }
    }

    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t AdcAppIntrConfig(adcAppCfgObj_t *pCfgAdc)
{
    int32_t retVal = S_PASS;
    intcIntrParams_t gAdcIntrParams;

    INTCInit(FALSE);

    gAdcIntrParams.triggerType = pCfgAdc->appIntrCfg.trigType;
    gAdcIntrParams.priority = pCfgAdc->appIntrCfg.intrPriority;
    gAdcIntrParams.pFnIntrHandler = AdcAppIsr;
    gAdcIntrParams.pUserParam = pCfgAdc;
    gAdcIntrParams.isIntrSecure = pCfgAdc->appIntrCfg.isIntrSecure;

    if(S_PASS != INTCConfigIntr(pCfgAdc->appIntrCfg.intrLine,
                                &gAdcIntrParams, FALSE))
    {
        CONSOLEUtilsPrintf("FAILURE!!!.\r\n");
        CONSOLEUtilsPrintf("Configuration failed for ADC interrupt.\r\n");

        retVal = E_FAIL;
    }

    return (retVal);
}

/* Reads the data from FIFO 0 and FIFO 1 */
static void AdcAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
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

        /* Disable the end of sequence interrupt. */
        TSCADCEventInterruptDisable(instObj->instAddr, TSCADC_INTR_MASK_END_OF_SEQUENCE);

        /* Set the interrupt flag. */
        instObj->appIntrCfg.endOfSeqIntr = 1U;
    }
}
