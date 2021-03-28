/**********************************************************************
 * Copyright (C) 2012-2019 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************
 * WARNING: This file is auto-generated using api-generator utility.
 *          api-generator: 13.04.5beed88
 *          Do not edit it manually.
 **********************************************************************
 * Cadence Core Driver for USB SSP DRD
 **********************************************************************/

/* parasoft-begin-suppress METRICS-18-3 "Follow the Cyclomatic Complexity limit of 10, DRV-4789" */
/* parasoft-begin-suppress METRICS-36-3 "A function should not be called from more than 5 different functions, DRV-3823" */
/* parasoft-begin-suppress METRICS-39-3 "The value of VOCF metric for a function should not be higher than 4, DRV-4790" */
/* parasoft-begin-suppress METRICS-41-3 "Number of blocks of comments per statement, DRV-4926" */
/* parasoft-begin-suppress MISRA2012-RULE-8_7 "Functions and objects should not be defined with external linkage if they are referenced in only one translation unit, DRV-4139" */

/**
 * This file contains sanity API functions. The purpose of sanity functions
 * is to check input parameters validity. They take the same parameters as
 * original API functions and return 0 on success or CDN_EINVAL on wrong parameter
 * value(s).
 */

#include "cdn_stdtypes.h"
#include "cdn_errno.h"
#include "cdn_xhci_if.h"
#include "cdn_xhci_structs_if.h"
#include "cusbd_if.h"
#include "cusbd_structs_if.h"
#include "usb_ssp_drd_structs_if.h"
#include "cdn_xhci_sanity.h"
#include "cusbd_sanity.h"
#include "usb_ssp_drd_sanity.h"

/**
 * Function to validate struct Config
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t USB_SSP_DRD_ConfigSF(const USB_SSP_DRD_Config *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to validate struct Callbacks
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t USB_SSP_DRD_CallbacksSF(const USB_SSP_DRD_Callbacks *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to validate struct PrivData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t USB_SSP_DRD_PrivDataSF(const USB_SSP_DRD_PrivData *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[out] sysReq Returns the memory requirements for given configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction1(const USB_SSP_DRD_SysReq* sysReq)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (sysReq == NULL)
    {
        ret = CDN_EINVAL;
    }


    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object.
 * @param[in] config Specifies driver/hardware configuration.
 * @param[in] callbacks Event Handlers and Callbacks.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction2(const USB_SSP_DRD_PrivData* privData, const USB_SSP_DRD_Config* config, const USB_SSP_DRD_Callbacks* callbacks)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (USB_SSP_DRD_ConfigSF(config) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (USB_SSP_DRD_CallbacksSF(callbacks) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object filled by init.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction3(const USB_SSP_DRD_PrivData* privData)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] isReady Will tell if controller is ready.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction7(const USB_SSP_DRD_PrivData* privData, const bool* isReady)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (isReady == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] strapMode Will tell how controller is strapped.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction8(const USB_SSP_DRD_PrivData* privData, const USB_SSP_DRD_Mode* strapMode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (strapMode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object.
 * @param[in] operationMode Mode of operation that should be set for controller.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction10(const USB_SSP_DRD_PrivData* privData, const USB_SSP_DRD_Mode operationMode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (operationMode != USB_SSP_DRD_DRD) &&
        (operationMode != USB_SSP_DRD_HOST) &&
        (operationMode != USB_SSP_DRD_DEV) &&
        (operationMode != USB_SSP_DRD_ILLEGAL)
    )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}


/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] interruptVect Interrupt Vector value.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t USB_SSP_DRD_SanityFunction11(const USB_SSP_DRD_PrivData* privData, const uint32_t* interruptVect)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (interruptVect == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (USB_SSP_DRD_PrivDataSF(privData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/* parasoft-end-suppress MISRA2012-RULE-8_7 */
/* parasoft-end-suppress METRICS-41-3 */
/* parasoft-end-suppress METRICS-39-3 */
/* parasoft-end-suppress METRICS-36-3 */
/* parasoft-end-suppress METRICS-18-3 */
