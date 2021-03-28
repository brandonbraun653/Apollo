/**
 *  \file   MMCSD_drv.c
 *
 *  \brief  MMC Driver high level APIs implementation.
 *
 *   This file contains the driver APIs for MMC controller.
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

#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/* Used to check status and initialization */
static int32_t MMCSD_count = -1;

/* Default MMC parameters structure */
const MMCSD_ConfigParams MMCSD_defaultConfigParams = {
    NULL                /* Custom argument used by driver implementation */
};

/*
 *  ======== MMCSD_close ========
 */
MMCSD_Error MMCSD_close(MMCSD_Handle handle)
{
    MMCSD_Error retVal = MMCSD_ERR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        retVal = ((MMCSD_Config *) handle)->fxnTablePtr->closeFxn(handle);
    }
    return (retVal);
}

/*
 *  ======== MMCSD_control ========
 */
MMCSD_Error MMCSD_control(MMCSD_Handle handle, uint32_t cmd, void *arg)
{
    MMCSD_Error retVal = MMCSD_ERR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        retVal = ((MMCSD_Config *) handle)->fxnTablePtr->controlFxn(handle, cmd, arg);
    }
    return (retVal);
}

/*
 *  ======== MMCSD_init ========
 */
MMCSD_Error MMCSD_init(void)
{
    MMCSD_Error retVal = MMCSD_OK;
    if (MMCSD_count == -1) {
        /* Call each driver's init function */
        for (MMCSD_count = 0; MMCSD_config[MMCSD_count].fxnTablePtr != NULL; MMCSD_count++) {
            MMCSD_config[MMCSD_count].fxnTablePtr->initFxn((MMCSD_Handle)&(MMCSD_config[MMCSD_count]));
        }
    }
#if defined (BUILD_MCU)
    retVal = MMCSD_socInit();
#endif
    return (retVal);
}

/*
 *  ======== MMCSD_open ========
 */
MMCSD_Error MMCSD_open(uint32_t index, MMCSD_Params params, MMCSD_Handle *handle)
{
    MMCSD_Error retVal = MMCSD_ERR;
    MMCSD_Handle mmcsdHandle = (MMCSD_Handle)&(MMCSD_config[index]);

    /* Input parameter validation */
    if ((mmcsdHandle != NULL) && (handle != NULL))
    {
        retVal = ((MMCSD_Config *)mmcsdHandle)->fxnTablePtr->openFxn(mmcsdHandle, params);

        if (MMCSD_OK == retVal)
        {
            /* Get handle for this driver instance */
            *handle = mmcsdHandle;
        }
    }
    return retVal;
}

/*
 *  ======== MMCSD_Params_init =======
 */
MMCSD_Error MMCSD_Params_init(MMCSD_Params params)
{
    MMCSD_Error retVal = MMCSD_ERR;

    /* Input parameter validation */
    if (params != NULL)
    {
        ((MMCSD_ConfigParams *) params)->custom = MMCSD_defaultConfigParams.custom;
        ((MMCSD_ConfigParams *) params)->cardDetectCallback = MMCSD_defaultConfigParams.cardDetectCallback;
        retVal = MMCSD_OK;
    }
    return (retVal);
}

/*
 *  ======== MMCSD_write ========
 */
MMCSD_Error MMCSD_write(MMCSD_Handle handle,
                        uint8_t *buf,
                        uint32_t block,
                        uint32_t numBlks)
{
    MMCSD_Error retVal = MMCSD_ERR;

    /* Input parameter validation */
    if ((handle != NULL) && (buf != NULL))
    {
        retVal = ((MMCSD_Config *) handle)->fxnTablePtr->writeFxn(handle, buf, block, numBlks);
    }
    return (retVal);
}

/*
 *  ======== MMCSD_read ========
 */
MMCSD_Error MMCSD_read(MMCSD_Handle handle,
                        uint8_t *buf,
                        uint32_t block,
                        uint32_t numBlks)
{
    MMCSD_Error retVal = MMCSD_ERR;

    /* Input parameter validation */
    if ((handle != NULL) && (buf != NULL))
    {
        retVal = ((MMCSD_Config *) handle)->fxnTablePtr->readFxn(handle, buf, block, numBlks);
    }
    return (retVal);
}
