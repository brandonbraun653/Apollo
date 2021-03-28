/**
 * \file      adc_app.h
 *
 * \brief     This file contains the function declarations and data structures
 *            corresponding to ADC.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef ADC_APP_H_
#define ADC_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 * \name    Macros to configure the TSCADC mode.
 *
 */

/** @{ */
/** \brief TSCADC Touchsceen mode enable. */
#define ADC_TS_MODE_ENABLE    (0x1U)

/** \brief TSCADC GP-ADC mode enable. */
#define ADC_GP_MODE_ENABLE    (0x2U)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding ADC configuration parameters. */
typedef struct adcAppCfg
{
    uint32_t diffCtrl;
    /**< Differential control. */
    uint32_t fifoSel;
    /**< Select FIFO to be configured. */
}adcAppCfg_t;

/** \brief Structure holding ADC control options. */
typedef struct adcAppCtrl
{
    uint32_t adcMode;
    /**< Select TSC/GP ADC mode. */
}adcAppCtrl_t;

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
    uint32_t modClk;
    /**< ADC module clock. */
    uint32_t afeInClk;
    /**< Input clock to AFE. */
    uint32_t *pSample;
    /**< Pointer to fetch sample data. */
    adcAppCfg_t appCfg;
    /**< McSPI configuration structure.*/
    adcAppIntrCfgObj_t appIntrCfg;
    /**< McSPI Interrupt configuration structure.*/
    adcAppCtrl_t appCtrl;
    /**< McSPI flag structure.*/
}adcAppCfgObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    ADC IP configuration initialization function.
 *
 * \details  This function configures the ADC controller with the user passed
 *           values.
 *
 * \param    pCfgAdc     Pointer to the ADC configuration object.
 *
 * \retval   S_PASS      ADC initialization successful.
 * \retval   E_FAIL      ADC initialization failed.
 */
int32_t ADCAppInit(adcAppCfgObj_t *pCfgAdc);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ADC_APP_H_ */
