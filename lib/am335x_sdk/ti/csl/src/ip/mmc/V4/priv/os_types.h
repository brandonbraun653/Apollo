/*
 *  Copyright (C) 2016-2020 Texas Instruments Incorporated - http://www.ti.com/
*  Copyright (C) 2017 Arasan Chip Systems Inc
 *
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
/*********************************************************************
*  Copyright (C) 2017 Arasan Chip Systems Inc
*  Name             : os_types.h
*  Creation Date : June 14, 2017
*  Description     : This file contains datatypes that are commonly used
*
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017      PB              0.1                 File structure creation
*  26-June-2017      PB              1.0                 Added data types definitions
*
*********************************************************************/
/**
 *  \file os_types.h
 *
 *  \brief File with macros defined for os specific types.
 *
**/
#ifndef LINUX_TYPES_H_
#define LINUX_TYPES_H_

#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C" {
#endif
#if 0
#ifndef int8_t
typedef signed char int8_t;
#endif

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

#ifndef int16_t
typedef short int16_t;
#endif

#ifndef uint16_t
typedef unsigned short uint16_t;
#endif

#ifndef int32_t
typedef int int32_t;
#endif

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

#ifndef uintptr_t
typedef unsigned long	uintptr_t;
#endif

#ifndef uint64_t
typedef unsigned long long uint64_t;
#endif

#endif
#ifndef FALSE
#define FALSE	0U
#ifndef TRUE
#define TRUE		!FALSE
#endif /*#ifndef TRUE*/
#endif /*#ifndef FALSE*/

#ifndef char_t
typedef char char_t;
#endif

#ifndef ULONG
typedef unsigned long ULONG;
#endif

#define OS_NULL ((void *)0U)

//#define OS_64BIT

#ifdef OS_64BIT
typedef unsigned long long UADR;
typedef unsigned long RDBASEADDR;
typedef unsigned long WRBASEADDR;
#define ADR_SPECIFIER "llx"
#else
typedef unsigned int UADR;
typedef unsigned int  RDBASEADDR;
typedef unsigned int  WRBASEADDR;
#define ADR_SPECIFIER "x"
#endif

#ifdef __cplusplus
}
#endif

#endif /*#ifndef LINUX_TYPES_H_ */
