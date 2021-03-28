/********************************************************************
 * Copyright (C) 2003-2018 Texas Instruments Incorporated.
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
* file: cslr_qmss.h
*
* Brief: This file contains the Register Description for qmss
*
*********************************************************************/
#ifndef CSLR_QMSS_V0_H_
#define CSLR_QMSS_V0_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION_REG;
} CSL_QmssRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION_REG */

#define CSL_QMSS_REVISION_REG_SCHEME_MASK (0xC0000000u)
#define CSL_QMSS_REVISION_REG_SCHEME_SHIFT (0x0000001Eu)
#define CSL_QMSS_REVISION_REG_SCHEME_RESETVAL (0x00000001u)

#define CSL_QMSS_REVISION_REG_FUNCTION_MASK (0x0FFF0000u)
#define CSL_QMSS_REVISION_REG_FUNCTION_SHIFT (0x00000010u)
#define CSL_QMSS_REVISION_REG_FUNCTION_RESETVAL (0x00000E60u)

#define CSL_QMSS_REVISION_REG_REVRTL_MASK (0x0000F800u)
#define CSL_QMSS_REVISION_REG_REVRTL_SHIFT (0x0000000Bu)
#define CSL_QMSS_REVISION_REG_REVRTL_RESETVAL (0x00000000u)

#define CSL_QMSS_REVISION_REG_REVMAJ_MASK (0x00000700u)
#define CSL_QMSS_REVISION_REG_REVMAJ_SHIFT (0x00000008u)
#define CSL_QMSS_REVISION_REG_REVMAJ_RESETVAL (0x00000001u)

#define CSL_QMSS_REVISION_REG_REVCUSTOM_MASK (0x000000C0u)
#define CSL_QMSS_REVISION_REG_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_QMSS_REVISION_REG_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_QMSS_REVISION_REG_REVMIN_MASK (0x0000003Fu)
#define CSL_QMSS_REVISION_REG_REVMIN_SHIFT (0x00000000u)
#define CSL_QMSS_REVISION_REG_REVMIN_RESETVAL (0x00000005u)

#define CSL_QMSS_REVISION_REG_RESETVAL   (0x4E600105u)


#ifdef __cplusplus
}
#endif

#endif
