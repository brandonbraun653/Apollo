/**
 *  \file   OSAL_log.h
 *
 *  \brief  This file contains the prototypes for the log print functions. By
            default the prints will be directed to serial console using UART.
 *
 */

/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef OSAL_LOG_H
#define OSAL_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#if !defined(SOC_TPR12)
#define UART_CONSOLE
#endif

#if defined(UART_CONSOLE)
#if defined(SOC_J721E)&&(defined(BUILD_C66X_1)||defined(BUILD_C66X_2)||defined(BUILD_C7X_1))
#define OSAL_log                printf
#else
/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
extern void UART_printf(const char *pcString, ...);
extern void ConsoleUtilsInit(void);

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#define OSAL_log                UART_printf
#endif
#else
#if defined(BARE_METAL)
#define OSAL_log                printf
#else
#define OSAL_log                System_printf
#endif /* BARE_METAL */
#endif /* UART_CONSOLE */

#ifdef __cplusplus
}
#endif

#endif /* OSAL_LOG_H */
