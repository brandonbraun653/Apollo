/**
 * @file   errorcodes.h
 *
 */
/*
 * Copyright (c) 2017-2018, Texas Instruments Incorporated
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
 *
*/

#ifndef _ERRORCODES_H_
#define _ERRORCODES_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Base address for errorcodes (for each module) */
#define ERROR_BASE_INIT_MODULE			(0x1000)
#define ERROR_BASE_CCXML_MODULE			(0x2000)
#define ERROR_BASE_FLASH_MODULE			(0x3000)
#define ERROR_BASE_HTTPD_MODULE			(0x4000)
#define ERROR_BASE_TELNET_MODULE		(0x5000)

/* General errorcodes */
#define ERROR_SUCCESS					(0)
#define ERROR_MEMORY_ALLOC				(-1)
#define ERROR_PARAMETERS				(-2)
#define ERROR_TASK_CREATE				(-3)
#define ERROR_MUTEX_CREATE				(-4)
#define ERROR_SEMA_CREATE				(-5)
#define ERROR_NOT_INITIALIZED			(-6)
#define ERROR_ALREADY_INITIALIZED		(-7)
#define ERROR_NULL_POINTER				(-8)
#define ERROR_MAILBOX_CREATE			(-9)

#ifdef __cplusplus
}
#endif

#endif /* _ERRORCODES_H_ */

