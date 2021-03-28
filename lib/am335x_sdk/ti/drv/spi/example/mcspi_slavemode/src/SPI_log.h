/**
 *  \file   SPI_log.h
 *
 *  \brief  This file contains the prototypes for the log print functions. By
            default the prints will be directed to serial console using UART.
 *
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _SPI_LOG_H
#define _SPI_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
extern void UART_printf(const char *pcString, ...);
extern void ConsoleUtilsInit(void);

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define SPI_log                UART_printf
#else
#define SPI_log                printf
#endif

#ifdef __cplusplus
}
#endif

#endif /* _SPI_LOG_H */
