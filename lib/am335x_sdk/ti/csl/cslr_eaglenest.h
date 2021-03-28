/********************************************************************
* Copyright (C) 2003-2008 Texas Instruments Incorporated.
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
*********************************************************************
* file: cslr_eaglenest.h
*
* Brief: This file contains the Register Description for eaglenest
*
*********************************************************************/
#ifndef CSLR_EAGLENEST_H_
#define CSLR_EAGLENEST_H_


#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 ENPID;
    volatile Uint8 RSVD0[28];
    volatile Uint32 ENCMDPRI;
    volatile Uint8 RSVD1[12];
    volatile Uint32 ENCPUEND0;
    volatile Uint32 ENCPUEND1;
    volatile Uint32 ENCPUEND2;
    volatile Uint32 ENCPUEND3;
} CSL_EaglenestRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ENPID */

#define CSL_EAGLENEST_ENPID_Y_MASK       (0x0000003Fu)
#define CSL_EAGLENEST_ENPID_Y_SHIFT      (0x00000000u)
#define CSL_EAGLENEST_ENPID_Y_RESETVAL   (0x00000000u)

#define CSL_EAGLENEST_ENPID_CUSTOM_MASK  (0x000000C0u)
#define CSL_EAGLENEST_ENPID_CUSTOM_SHIFT (0x00000006u)
#define CSL_EAGLENEST_ENPID_CUSTOM_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENPID_X_MASK       (0x00000700u)
#define CSL_EAGLENEST_ENPID_X_SHIFT      (0x00000008u)
#define CSL_EAGLENEST_ENPID_X_RESETVAL   (0x00000000u)

#define CSL_EAGLENEST_ENPID_R_MASK       (0x0000F800u)
#define CSL_EAGLENEST_ENPID_R_SHIFT      (0x0000000Bu)
#define CSL_EAGLENEST_ENPID_R_RESETVAL   (0x00000000u)

#define CSL_EAGLENEST_ENPID_FUNC_MASK    (0x0FFF0000u)
#define CSL_EAGLENEST_ENPID_FUNC_SHIFT   (0x00000010u)
#define CSL_EAGLENEST_ENPID_FUNC_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENPID_BU_MASK      (0x30000000u)
#define CSL_EAGLENEST_ENPID_BU_SHIFT     (0x0000001Cu)
#define CSL_EAGLENEST_ENPID_BU_RESETVAL  (0x00000000u)

#define CSL_EAGLENEST_ENPID_SCHEME_MASK  (0xC0000000u)
#define CSL_EAGLENEST_ENPID_SCHEME_SHIFT (0x0000001Eu)
#define CSL_EAGLENEST_ENPID_SCHEME_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENPID_RESETVAL     (0x00000000u)

/* ENCMDPRI */

#define CSL_EAGLENEST_ENCMDPRI_PRI_MASK  (0x00000007u)
#define CSL_EAGLENEST_ENCMDPRI_PRI_SHIFT (0x00000000u)
#define CSL_EAGLENEST_ENCMDPRI_PRI_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCMDPRI__RESV1_MASK (0xFFFFFFF8u)
#define CSL_EAGLENEST_ENCMDPRI__RESV1_SHIFT (0x00000003u)
#define CSL_EAGLENEST_ENCMDPRI__RESV1_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCMDPRI_RESETVAL  (0x00000000u)

/* ENCPUEND0 */

#define CSL_EAGLENEST_ENCPUEND0_LENDIAN_MASK (0xFFFFFFFFu)
#define CSL_EAGLENEST_ENCPUEND0_LENDIAN_SHIFT (0x00000000u)
#define CSL_EAGLENEST_ENCPUEND0_LENDIAN_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCPUEND0_RESETVAL (0x00000000u)

/* ENCPUEND1 */

#define CSL_EAGLENEST_ENCPUEND1_LENDIAN_MASK (0xFFFFFFFFu)
#define CSL_EAGLENEST_ENCPUEND1_LENDIAN_SHIFT (0x00000000u)
#define CSL_EAGLENEST_ENCPUEND1_LENDIAN_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCPUEND1_RESETVAL (0x00000000u)

/* ENCPUEND2 */

#define CSL_EAGLENEST_ENCPUEND2_LENDIAN_MASK (0xFFFFFFFFu)
#define CSL_EAGLENEST_ENCPUEND2_LENDIAN_SHIFT (0x00000000u)
#define CSL_EAGLENEST_ENCPUEND2_LENDIAN_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCPUEND2_RESETVAL (0x00000000u)

/* ENCPUEND3 */

#define CSL_EAGLENEST_ENCPUEND3_LENDIAN_MASK (0xFFFFFFFFu)
#define CSL_EAGLENEST_ENCPUEND3_LENDIAN_SHIFT (0x00000000u)
#define CSL_EAGLENEST_ENCPUEND3_LENDIAN_RESETVAL (0x00000000u)

#define CSL_EAGLENEST_ENCPUEND3_RESETVAL (0x00000000u)

#endif
