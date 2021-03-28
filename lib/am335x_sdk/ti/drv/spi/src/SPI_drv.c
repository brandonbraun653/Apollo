/**
 *  \file   SPI_drv.c
 *
 *  \brief  SPI Driver high level APIs.
 *
 *   This file contains the driver APIs for SPI.
 */

/*
 * Copyright (C) 2014-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/drv/spi/MCSPI.h>
#include <stdint.h>
#include <stdlib.h>
#include <ti/drv/spi/src/SPI_osal.h>


/* Externs */
extern const SPI_config_list SPI_config;
extern MCSPI_config_list MCSPI_config;

/* Used to check status and initialization */
static int32_t SPI_count = (-((int32_t)1));

static void   *spiMutex = NULL;

/* Default SPI parameters structure */
const SPI_Params SPI_defaultParams = {
    SPI_MODE_BLOCKING,  /* transferMode */
    0U,                 /* transferTimeout */
    NULL,               /* transferCallbackFxn */
    SPI_MASTER,         /* mode */
    1000000,            /* bitRate */
    8,                  /* dataSize */
    SPI_POL0_PHA0,      /* frameFormat */
    NULL                /* custom */
};

/* Default MCSPI parameters structure */
const MCSPI_Params MCSPI_defaultParams = {
    SPI_MODE_BLOCKING,  /* transferMode */
    0U,                 /* transferTimeout */
    NULL,               /* transferCallbackFxn */
    SPI_MASTER,         /* mode */
    1000000,            /* bitRate */
    8,                  /* dataSize */
    SPI_POL0_PHA0,      /* frameFormat */
    NULL                /* custom */
};

/*
 *  ======== SPI_close ========
 */
void SPI_close(SPI_Handle handle)
{
    if (handle != NULL)
    {
        if (spiMutex != NULL)
        {
            /* Acquire the the SPI driver semaphore */
            (void)SPI_osalPendLock(spiMutex, SemaphoreP_WAIT_FOREVER);
        }

        handle->fxnTablePtr->closeFxn(handle);

        if (spiMutex != NULL)
        {
            /* Release the the SPI driver semaphorel */
            (void)SPI_osalPostLock(spiMutex);
        }
    }
}

/*
 *  ======== SPI_control ========
 */
int32_t SPI_control(SPI_Handle handle, uint32_t cmd, void *arg)
{
    int32_t retVal = SPI_STATUS_ERROR;

    if (handle != NULL)
    {
        retVal = handle->fxnTablePtr->controlFxn(handle, cmd, arg);
    }

    return (retVal);
}

/*
 *  ======== SPI_init ========
 */
void SPI_init(void)
{
    SemaphoreP_Params     semParams;

    if (SPI_count == (-((int32_t)1))) {
        /* Call each driver's init function */
        for (SPI_count = 0; SPI_config[SPI_count].fxnTablePtr != NULL; SPI_count++) {
            SPI_config[SPI_count].fxnTablePtr->spiInitFxn((SPI_Handle)&(SPI_config[SPI_count]));
        }
    }

    /*
     * Construct thread safe handles for SPI driver level
     * Semaphore to provide exclusive access to the SPI APIs
     */
    if (spiMutex == NULL)
    {
        SPI_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        spiMutex = SPI_osalCreateBlockingLock(1U, &semParams);
    }
}

/*
 *  ======== SPI_open ========
 */
SPI_Handle SPI_open(uint32_t index, SPI_Params *params)
{
    SPI_Handle handle = NULL;

    if ((SPI_Handle)&(SPI_config[index]) != NULL)
    {
        /* Get handle for this driver instance */
        handle = (SPI_Handle)&(SPI_config[index]);

        if (spiMutex != NULL)
        {
            /* Acquire the the SPI driver semaphore */
            (void)SPI_osalPendLock(spiMutex, SemaphoreP_WAIT_FOREVER);
        }

        handle = handle->fxnTablePtr->openFxn(handle, params);

        if (spiMutex != NULL)
        {
            /* Release the the SPI driver semaphorel */
            (void)SPI_osalPostLock(spiMutex);
        }
    }

    return (handle);
}

/*
 *  ======== SPI_Params_init ========
 */
void SPI_Params_init(SPI_Params *params)
{
    if (params != NULL)
    {
        *params = SPI_defaultParams;
    }
}

/*
 *  ======== SPI_serviceISR ========
 */
void SPI_serviceISR(SPI_Handle handle)
{
    if (handle != NULL)
    {
        handle->fxnTablePtr->serviceISRFxn(handle);
    }
}

/*
 *  ======== SPI_transfer ========
 */
bool SPI_transfer(SPI_Handle handle, SPI_Transaction *transaction)
{
    bool retVal = (bool)false;

    if ((handle != NULL) && (transaction != NULL))
    {
        retVal = handle->fxnTablePtr->transferFxn(handle, transaction);
    }

    return (retVal);
}

/*
 *  ======== SPI_transferCancel ========
 */
void SPI_transferCancel(SPI_Handle handle)
{
    if (handle != NULL)
    {
        handle->fxnTablePtr->transferCancelFxn(handle);
    }
}

/*
 *  ======== MCSPI_close ========
 */
void MCSPI_close(MCSPI_Handle handle)
{
    if (handle != NULL)
    {
        if (spiMutex != NULL)
        {
            /* Acquire the the SPI driver semaphore */
            (void)SPI_osalPendLock(spiMutex, SemaphoreP_WAIT_FOREVER);
        }

        handle->fxnTablePtr->closeFxn(handle);

        if (spiMutex != NULL)
        {
            /* Release the the SPI driver semaphorel */
            (void)SPI_osalPostLock(spiMutex);
        }
    }
}

/*
 *  ======== MCSPI_control ========
 */
int32_t MCSPI_control(MCSPI_Handle handle, uint32_t cmd, void *arg)
{
    int32_t retVal = SPI_STATUS_ERROR;

    if (handle != NULL)
    {
        retVal = handle->fxnTablePtr->controlFxn(handle, cmd, arg);
    }

    return (retVal);
}

/*
 *  ======== MCSPI_init ========
 */
void MCSPI_init(void)
{
    SPI_init();
}

/*
 *  ======== MCSPI_open ========
 */
MCSPI_Handle MCSPI_open(uint32_t index, uint32_t channel, MCSPI_Params *params)
{
    MCSPI_Handle handle = NULL;

    if ((MCSPI_Handle)&(MCSPI_config[index][channel]) != NULL)
    {
        /* Get handle for this driver instance */
        handle = (MCSPI_Handle)&(MCSPI_config[index][channel]);

        if (spiMutex != NULL)
        {
            /* Acquire the the SPI driver semaphore */
            (void)SPI_osalPendLock(spiMutex, SemaphoreP_WAIT_FOREVER);
        }

        handle = handle->fxnTablePtr->openFxn(handle, params);

        if (spiMutex != NULL)
        {
            /* Release the the SPI driver semaphorel */
            (void)SPI_osalPostLock(spiMutex);
        }
    }

    return (handle);
}

/*
 *  ======== MCSPI_Params_init ========
 */
void MCSPI_Params_init(MCSPI_Params *params)
{
    if (params != NULL)
    {
        *params = MCSPI_defaultParams;
    }
}

/*
 *  ======== _transfer ========
 */
bool MCSPI_transfer(MCSPI_Handle handle, SPI_Transaction *transaction)
{
    bool retVal = (bool)false;

    if ((handle != NULL) && (transaction != NULL))
    {
        retVal = handle->fxnTablePtr->transferFxn(handle, transaction);
    }

    return (retVal);
}

/*
 *  ======== _transferCancel ========
 */
void MCSPI_transferCancel(MCSPI_Handle handle)
{
    if (handle != NULL)
    {
        handle->fxnTablePtr->transferCancelFxn(handle);
    }
}
