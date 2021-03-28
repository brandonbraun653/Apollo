/**
 *  \file   GPMC_drv.c
 *
 *  \brief  GPMC Driver high level APIs.
 *
 *   This file contains the driver APIs for GPMC.
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/drv/gpmc/GPMC.h>
#include <stdint.h>
#include <stdlib.h>
#include <ti/drv/gpmc/src/GPMC_osal.h>


/* Externs */
extern const GPMC_config_list GPMC_config;

/* Used to check status and initialization */
static int32_t GPMC_count = -1;

/* Default GPMC parameters structure */
const GPMC_Params GPMC_defaultParams =
{
    GPMC_MODE_BLOCKING, /* transferMode */
    0U,                 /* transferTimeout */
    NULL                /* transferCallbackFxn */
};

/*
 *  ======== GPMC_init ========
 */
void GPMC_init(void)
{
    if (GPMC_count == -1) {
        /* Call each driver's init function */
        for (GPMC_count = 0; GPMC_config[GPMC_count].fxnTablePtr != NULL; GPMC_count++) {
            GPMC_config[GPMC_count].fxnTablePtr->initFxn((GPMC_Handle)&(GPMC_config[GPMC_count]));
        }
    }
}

/*
 *  ======== GPMC_open ========
 */
GPMC_Handle GPMC_open(uint32_t index, GPMC_Params *params)
{
    GPMC_Handle handle;

    /* Get handle for this driver instance */
    handle = (GPMC_Handle)&(GPMC_config[index]);
    if (handle != NULL)
    {
        handle = handle->fxnTablePtr->openFxn(handle, params);
    }

    return (handle);
}

/*
 *  ======== GPMC_close ========
 */
void GPMC_close(GPMC_Handle handle)
{
    if (handle != NULL)
    {
        handle->fxnTablePtr->closeFxn(handle);
    }
}

/*
 *  ======== GPMC_Params_init ========
 */
void GPMC_Params_init(GPMC_Params *params)
{
    if (params != NULL)
    {
        *params = GPMC_defaultParams;
    }
}

/*
 *  ======== GPMC_transfer ========
 */
bool GPMC_transfer(GPMC_Handle handle, GPMC_Transaction *transaction)
{
    bool retVal = (bool)false;
    
    if ((handle != NULL) && (transaction != NULL))
    {
        retVal = handle->fxnTablePtr->transferFxn(handle, transaction);
    }

    return (retVal);
}

/*
 *  ======== GPMC_control ========
 */
int32_t GPMC_control(GPMC_Handle handle, uint32_t cmd, void *arg)
{
    int32_t retVal = GPMC_STATUS_ERROR;

    if (handle != NULL)
    {
        retVal = handle->fxnTablePtr->controlFxn(handle, cmd, arg);
    }

    return (retVal);
}

