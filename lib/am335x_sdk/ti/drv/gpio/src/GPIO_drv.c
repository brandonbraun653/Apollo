/**
 * @file   GPIO_drv.c
 *
 * @brief  This file contains the GPIO driver interface APIs
 *         These APIs are used for configuration of general
 *         purpose I/O instanace.
 */
/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== gpio_drv.c ========
 */

#include <stdint.h>
#include <ti/drv/gpio/GPIO.h>

#include <ti/drv/gpio/src/GPIO_osal.h>

/* Externs */
extern const GPIOConfigList GPIO_config;

/*
 *  ======== GPIO_clearInt ========
 */
void GPIO_clearInt(uint32_t index)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->clearIntFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->clearIntFxn(index);
    }
}

/*
 *  ======== GPIO_disableInt ========
 */
void GPIO_disableInt(uint32_t index)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->disableIntFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->disableIntFxn(index);
    }
}

/*
 *  ======== GPIO_enableInt ========
 */
void GPIO_enableInt(uint32_t index)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->enableIntFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->enableIntFxn(index);
    }
}

/*
 *  ======== GPIO_init ========
 */
void GPIO_init(void)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->initFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->initFxn();
    }
}

/*
 *  ======== GPIO_read ========
 */
uint32_t GPIO_read(uint32_t index)
{
    uint32_t ret_val = 0U;
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->readFxn != NULL))
    {
        ret_val = GPIO_config[0].fxnTablePtr->readFxn(index);
    }
    else
    {
        ret_val = 0U;
    }
    return ret_val;
}

/*
 *  ======== GPIO_setCallback ========
 */
void GPIO_setCallback(uint32_t index, GPIO_CallbackFxn callback)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->setCallbackFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->setCallbackFxn(index, callback);
    }
}

/*
 *  ======== GPIO_setConfig ========
 */
void GPIO_setConfig(uint32_t index, GPIO_PinConfig pinConfig)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->setConfigFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->setConfigFxn(index, pinConfig);
    }
}

/*
 *  ======== GPIO_toggle ========
 */
void GPIO_toggle(uint32_t index)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->toggleFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->toggleFxn(index);
    }
}

/*
 *  ======== GPIO_write ========
 */
void GPIO_write(uint32_t index, uint32_t value)
{
    if ((GPIO_config[0].fxnTablePtr != NULL) && (GPIO_config[0].fxnTablePtr->writeFxn != NULL))
    {
        GPIO_config[0].fxnTablePtr->writeFxn(index, value);
    }
}
