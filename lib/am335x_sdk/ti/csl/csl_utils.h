/* Copyright (c) Texas Instruments Incorporated 2017
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

/** ============================================================================
 *   @file  csl_utils.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the pragma support for C/C++ styles
 *
 */

#ifndef CSL_UTILS_H
#define CSL_UTILS_H


/* remove c++'s implicit static built into const */
#ifdef __cplusplus
#define CSL_PUBLIC_CONST                extern const
#else
#define CSL_PUBLIC_CONST                const
#endif

#if defined(__GNUC__) && !defined(__ti__)
/* GCC */
#define CSL_SET_DSECT(section_name)     __attribute__((section(section_name)))
#define CSL_SET_DALIGN(x)               __attribute__((aligned(x)))
#define CSL_SET_CSECT(section_name)     __attribute__((section(section_name)))
#else
/* non GCC */
#define PRAGMA(x) _Pragma(#x)
#ifdef __cplusplus
#define CSL_SET_CSECT(f,s)            PRAGMA(CODE_SECTION(s))
#define CSL_SET_DSECT(f,s)            PRAGMA(DATA_SECTION(s))
#define CSL_SET_DALIGN(d,s)           PRAGMA(DATA_ALIGN(s))
#else
#define CSL_SET_CSECT(f,s)            PRAGMA(CODE_SECTION(f, s))
#define CSL_SET_DSECT(f,s)            PRAGMA(DATA_SECTION(f, s))
#define CSL_SET_DALIGN(d,s)           PRAGMA(DATA_ALIGN(d, s))
#endif /* __cplusplus */
#endif /*  defined(__GNUC__) && !defined(__ti__) */
#endif /* CSL_UTILS_H */
/* Nothing past this point */
