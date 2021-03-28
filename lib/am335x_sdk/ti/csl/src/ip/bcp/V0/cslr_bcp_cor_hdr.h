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
* file: cslr_cor_hdr.h
*
* Brief: This file contains the Register Description for cor_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_COR_HDR_H_
#define CSLR_BCP_COR_HDR_H_

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
    volatile Uint32 WORD0; /* COR local header */
    volatile Uint32 WORD1; /* PUCCH Config */
    volatile Uint32 WORD2; /* DESPREAD Config0 */
    volatile Uint32 WORD3; /* DESPREAD Config1 */
    volatile Uint32 WORD4; /* DESPREAD Config2 */
    volatile Uint32 WORD5; /* DESPREAD Config3 */
    volatile Uint32 WORD6; /* DESPREAD Config4 */
    volatile Uint32 WORD7; /* DESPREAD Config5 */
} CSL_Cor_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */


#define CSL_COR_HDR_WORD0_SCR_EXTN_MASK  (0x00F00000u)
#define CSL_COR_HDR_WORD0_SCR_EXTN_SHIFT (0x00000014u)
#define CSL_COR_HDR_WORD0_SCR_EXTN_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD0_DESPREAD_FLAG_CPLX_MASK (0x00020000u)
#define CSL_COR_HDR_WORD0_DESPREAD_FLAG_CPLX_SHIFT (0x00000011u)
#define CSL_COR_HDR_WORD0_DESPREAD_FLAG_CPLX_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD0_PUCCH_DESPREAD_SEL_MASK (0x00010000u)
#define CSL_COR_HDR_WORD0_PUCCH_DESPREAD_SEL_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD0_PUCCH_DESPREAD_SEL_RESETVAL (0x00000000u)


#define CSL_COR_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_COR_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_COR_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)


#define CSL_COR_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000003Fu)
#define CSL_COR_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */


#define CSL_COR_HDR_WORD1_PUCCH_MODE_MASK (0x30000000u)
#define CSL_COR_HDR_WORD1_PUCCH_MODE_SHIFT (0x0000001Cu)
#define CSL_COR_HDR_WORD1_PUCCH_MODE_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD1_PUCCH_NR_MASK  (0x0F000000u)
#define CSL_COR_HDR_WORD1_PUCCH_NR_SHIFT (0x00000018u)
#define CSL_COR_HDR_WORD1_PUCCH_NR_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD1_PUCCH_SCR_SEQ_MASK (0x00FFFFF0u)
#define CSL_COR_HDR_WORD1_PUCCH_SCR_SEQ_SHIFT (0x00000004u)
#define CSL_COR_HDR_WORD1_PUCCH_SCR_SEQ_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD1_PUCCH_A_MASK   (0x0000000Fu)
#define CSL_COR_HDR_WORD1_PUCCH_A_SHIFT  (0x00000000u)
#define CSL_COR_HDR_WORD1_PUCCH_A_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */


#define CSL_COR_HDR_WORD2_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD2_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD2_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD2_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD2_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD2_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */


#define CSL_COR_HDR_WORD3_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD3_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD3_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD3_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD3_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD3_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */


#define CSL_COR_HDR_WORD4_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD4_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD4_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD4_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD4_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD4_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD4_RESETVAL       (0x00000000u)

/* Word 5 */


#define CSL_COR_HDR_WORD5_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD5_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD5_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD5_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD5_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD5_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD5_RESETVAL       (0x00000000u)

/* Word 6 */


#define CSL_COR_HDR_WORD6_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD6_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD6_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD6_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD6_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD6_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD6_RESETVAL       (0x00000000u)

/* Word 7 */


#define CSL_COR_HDR_WORD7_SF_RATIO_MASK  (0x00070000u)
#define CSL_COR_HDR_WORD7_SF_RATIO_SHIFT (0x00000010u)
#define CSL_COR_HDR_WORD7_SF_RATIO_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD7_DESPREAD_LENGTH_MASK (0x0000FFFFu)
#define CSL_COR_HDR_WORD7_DESPREAD_LENGTH_SHIFT (0x00000000u)
#define CSL_COR_HDR_WORD7_DESPREAD_LENGTH_RESETVAL (0x00000000u)

#define CSL_COR_HDR_WORD7_RESETVAL       (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
