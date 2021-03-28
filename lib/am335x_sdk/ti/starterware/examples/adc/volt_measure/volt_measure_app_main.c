/**
 * \file   volt_measure_app_main.c
 *
 * \brief  Example application main source file, which configures the ADC IP
 *         and executes the voltage measure use-case.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *            http://www.ti.com/
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
#include "soc.h"
#include "types.h"
#include "error.h"
#include "board.h"
#include "device.h"
#include "chipdb.h"
#include "adc_app.h"
#include "tsc_adc_ss.h"
#include "console_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/**
 * \name    Macros used by the application.
 */

/** @{ */
/* Macro representing the voltage resolution. */
#define VOLTAGE_RESOLUTION       (439U)

/* Macro representing the module clock of TSCADC. */
#define TSCADC_MODULE_CLOCK      (24000000U)

/* Macro representing the AFE clock of TSCADC. */
#define TSCADC_AFE_CLOCK         (3000000U)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Fetch the ADC instance address.
 *
 * \param     pObj       Pointer to the ADC application configuration
 *                       structure.
 *
 * \retval    #S_PASS - ADC instance is present.
 * \retVal    #E_FAIL - ADC instance is not present.
 */
static int32_t AdcAppSocInfoGet(adcAppCfgObj_t *pObj);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Application default configuration */
static const adcAppCfgObj_t ADCAPPVOLTMEASURE_DEFAULT =
{
    0U,                           /* instNum */
    0U,                           /* instAddr */
    24000000U,                    /* modClk */
    3000000U,                     /* afeInClk */
    NULL,                         /* pSample */
    {
        FALSE,                    /* diffCtrl */
        0U                        /* fifoSel */
    },
    {
        INTC_TRIG_HIGH_LEVEL,     /* trigType */
        0U,                       /* intrLine */
        16U,                      /* intrPriority */
        FALSE,                    /* isIntrSecure */
        0U,                       /* endOfSeqIntr */
        NULL                      /* pFnIntrHandler */
    },
    {
        ADC_GP_MODE_ENABLE        /* adcMode. */
    }
};

/** \brief Global object for the ADC volt measure application. */
static adcAppCfgObj_t gVoltMeasureAppCfg;

/** \brief Variable to hold the sample values. */
static uint32_t gVoltMeasureAppSampleVal[2U];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;
    uint32_t chan1, chan2 = 0U;

    gVoltMeasureAppCfg = ADCAPPVOLTMEASURE_DEFAULT;
    gVoltMeasureAppCfg.pSample = gVoltMeasureAppSampleVal;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare ADC voltage measure application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    status = AdcAppSocInfoGet(&gVoltMeasureAppCfg);

    if (S_PASS == status)
    {
        /* Initialize the ADC application. */
        status = ADCAppInit(&gVoltMeasureAppCfg);

        if (S_PASS == status)
        {
            /* Wait till the ADC processes the analog lines. */
            while(1U != gVoltMeasureAppCfg.appIntrCfg.endOfSeqIntr);

            /* Read the sample data from the FIFO. */
            gVoltMeasureAppSampleVal[0U] =
                   TSCADCFIFOADCDataRead(gVoltMeasureAppCfg.instAddr,
                       TSCADC_FIFO_SEL_0);

            gVoltMeasureAppSampleVal[1U] =
                   TSCADCFIFOADCDataRead(gVoltMeasureAppCfg.instAddr,
                       TSCADC_FIFO_SEL_1);

            chan1 = (gVoltMeasureAppSampleVal[0U] * VOLTAGE_RESOLUTION) / 1000U;

            chan2 = (gVoltMeasureAppSampleVal[1U] * VOLTAGE_RESOLUTION) / 1000U;

            CONSOLEUtilsPrintf("Voltage sensed on the AN0 line :");

            CONSOLEUtilsPrintf("%dmV\r\n", chan1);

            CONSOLEUtilsPrintf("Voltage sensed on the AN1 line :");

            CONSOLEUtilsPrintf("%dmV\r\n", chan2);
        }
        else
        {
            CONSOLEUtilsPrintf("TSCADC initialization failed\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Exiting from the application\n");
    }

    return (S_PASS);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t AdcAppSocInfoGet(adcAppCfgObj_t *pObj)
{
    int32_t status = E_FAIL;

    pObj->instNum = 0U;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_ADC0, pObj->instNum))
    {
        /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pObj->appIntrCfg.intrLine = 48U;
        }
        else if(SOC_FAMILY_ID_AM335X == SOCGetSocFamilyId())
        {
            pObj->appIntrCfg.intrLine = 16U;
        }
        else
        {
            CONSOLEUtilsPrintf("ADC interrupts not supported on the SOC.\n");
        }

        /* TODO: Need to update the interrupt Numberdata base of ChipDB */
        /*
        pObj->appIntrCfg.intrLine = ChipDBInterruptNum(CHIPDB_MOD_ID_ADC0,
                                          0, 0);
        */

        /* Read the ADC instance number. */
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_ADC0, 0U);

        status = S_PASS;
    }
    else
    {
        CONSOLEUtilsPrintf("ADC instance is not present on the SOC.\n");
    }

    return(status);
}
