/**
 * @file   UART_drv.c
 *
 * @brief  This file contains the UART driver interface APIs
 *         These APIs are used for configuration of instance
 *         transmission and reception of data.
 */
/*
 * Copyright (c) 2014-2019, Texas Instruments Incorporated
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
 *  ======== uart_drv.c ========
 */

#include <stdint.h>
#include <ti/drv/uart/UART.h>

#include <ti/drv/uart/src/UART_osal.h>

/* Externs */
extern UART_Config UART_config[];
#if defined (BUILD_MCU)
extern void UART_socInit(void);
#endif

/* Used to check status and initialization */
static int32_t UART_count = (-((int32_t)1));

/* Default UART parameters structure */
const UART_Params UART_defaultParams = {
    UART_MODE_BLOCKING,           /* readMode */
    UART_MODE_BLOCKING,           /* writeMode */
    SemaphoreP_WAIT_FOREVER,      /* readTimeout */
    SemaphoreP_WAIT_FOREVER,      /* writeTimeout */
    NULL,                        /* readCallback */
    NULL,                 /* writeCallback */
    UART_RETURN_NEWLINE,  /* readReturnMode */
    UART_DATA_TEXT,       /* readDataMode */
    UART_DATA_TEXT,       /* writeDataMode */
    UART_ECHO_OFF,         /* readEcho */
    115200,               /* baudRate */
    UART_LEN_8,           /* dataLength */
    UART_STOP_ONE,        /* stopBits */
    UART_PAR_NONE,        /* parityType */
    NULL,                 /* readCallback2 */
    NULL,                 /* writeCallback2 */
#ifdef PRU_ICSS_FW // PRU UART FW only
    UART_FC_NONE,         /* Flow Control type */
    0                     /* Flow Control threshold */
#endif    
};

/* Default UART transaction parameters structure */
const UART_Transaction UART_defaultTransaction = {
	NULL,                         /* buf */
	UART_WAIT_FOREVER,            /* timeout */
    0,                            /* count */
	UART_TRANSFER_STATUS_SUCCESS, /* status */
};

/*
 *  ======== UART_close ========
 */
void UART_close(UART_Handle handle)
{

    handle->fxnTablePtr->closeFxn(handle);
}

/*
 *  ======== UART_control ========
 */
int32_t UART_control(UART_Handle handle, uint32_t cmd, void *arg)
{


    return (handle->fxnTablePtr->controlFxn(handle, cmd, arg));
}

/*
 *  ======== UART_init ========
 */
void UART_init(void)
{
    if (UART_count == (-((int32_t)1))) {
        /* Call each driver's init function */
        for (UART_count = 0; UART_config[UART_count].fxnTablePtr != NULL; UART_count++) {
            UART_config[UART_count].fxnTablePtr->uartInitFxn((UART_Handle)&(UART_config[UART_count]));
        }
    }

#if defined (BUILD_MCU)
    UART_socInit();
#endif
}

/*
 *  ======== UART_open ========
 */
UART_Handle UART_open(uint32_t index, UART_Params *params)
{
    UART_Handle         handle;



    /* Get handle for this driver instance */
    handle = (UART_Handle)&(UART_config[index]);

    return (handle->fxnTablePtr->openFxn(handle, params));
}

/*
 *  ======== UART_Params_init ========
 */
void UART_Params_init(UART_Params *params)
{

    *params = UART_defaultParams;
}

/*
 *  ======== UART_read ========
 */
int32_t UART_read(UART_Handle handle, void *buffer, size_t size)
{


    return (handle->fxnTablePtr->readFxn(handle, buffer, size));
}

/*
 *  ======== UART_read2 ========
 */
int32_t UART_read2(UART_Handle handle, UART_Transaction *transaction)
{


    return (handle->fxnTablePtr->readFxn2(handle, transaction));
}

/*
 *  ======== UART_readPolling ========
 */
int32_t UART_readPolling(UART_Handle handle, void *buffer, size_t size)
{


    return (handle->fxnTablePtr->readPollingFxn(handle, buffer, size));
}

/*
 *  ======== UART_readCancel ========
 */
void UART_readCancel(UART_Handle handle)
{


    handle->fxnTablePtr->readCancelFxn(handle);
}

/*
 *  ======== UART_write ========
 */
int32_t UART_write(UART_Handle handle, const void *buffer, size_t size)
{


    return (handle->fxnTablePtr->writeFxn(handle, buffer, size));
}

/*
 *  ======== UART_write2 ========
 */
int32_t UART_write2(UART_Handle handle, UART_Transaction *transaction)
{


    return (handle->fxnTablePtr->writeFxn2(handle, transaction));
}

/*
 *  ======== UART_writePolling ========
 */
int32_t UART_writePolling(UART_Handle handle, const void *buffer, size_t size)
{


    return (handle->fxnTablePtr->writePollingFxn(handle, buffer, size));
}

/*
 *  ======== UART_writeCancel ========
 */
void UART_writeCancel(UART_Handle handle)
{


    handle->fxnTablePtr->writeCancelFxn(handle);
}

/*
 *  ======== UART_transactionInit ========
 */
void UART_transactionInit(UART_Transaction *transaction)
{

    *transaction = UART_defaultTransaction;
}
