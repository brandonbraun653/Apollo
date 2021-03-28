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
* file: cslr_mod_hdr.h
*
* Brief: This file contains the Register Description for mod_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_MOD_HDR_H_
#define CSLR_BCP_MOD_HDR_H_

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
    volatile Uint32 WORD0; /* Modulator control header */
    volatile Uint32 WORD1; /* Mode select */
    volatile Uint32 WORD2; /* Cinit value for scrambler */
    volatile Uint32 WORD3; /* RMUX and CQI configuration */
    volatile Uint32 WORD4; /* RI and ACK configuration */
} CSL_Mod_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */

#define CSL_MOD_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000007Fu)
#define CSL_MOD_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_MOD_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_MOD_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_MOD_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD0_UVA_VAL_MASK    (0xFFFF0000u)
#define CSL_MOD_HDR_WORD0_UVA_VAL_SHIFT   (0x00000010u)
#define CSL_MOD_HDR_WORD0_UVA_VAL_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */

#define CSL_MOD_HDR_WORD1_SH_MOD_SEL_MASK (0x00000003u)
#define CSL_MOD_HDR_WORD1_SH_MOD_SEL_SHIFT (0x00000000u)
#define CSL_MOD_HDR_WORD1_SH_MOD_SEL_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD1_SPLIT_MODE_EN_MASK (0x00000004u)
#define CSL_MOD_HDR_WORD1_SPLIT_MODE_EN_SHIFT (0x00000002u)
#define CSL_MOD_HDR_WORD1_SPLIT_MODE_EN_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD1_SCR_EN_MASK    (0x00000008u)
#define CSL_MOD_HDR_WORD1_SCR_EN_SHIFT   (0x00000003u)
#define CSL_MOD_HDR_WORD1_SCR_EN_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD1_MOD_TYPE_SEL_MASK (0x000000F0u)
#define CSL_MOD_HDR_WORD1_MOD_TYPE_SEL_SHIFT (0x00000004u)
#define CSL_MOD_HDR_WORD1_MOD_TYPE_SEL_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD1_CMUX_LN_MASK   (0x00000300u)
#define CSL_MOD_HDR_WORD1_CMUX_LN_SHIFT  (0x00000008u)
#define CSL_MOD_HDR_WORD1_CMUX_LN_RESETVAL (0x00000000u)

#define CSL_MOD_HDR_WORD1_Q_FORMAT_MASK  (0x00000C00u)
#define CSL_MOD_HDR_WORD1_Q_FORMAT_SHIFT (0x0000000Au)
#define CSL_MOD_HDR_WORD1_Q_FORMAT_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD1_B_TABLE_INDEX_MASK (0x007F0000u)
#define CSL_MOD_HDR_WORD1_B_TABLE_INDEX_SHIFT (0x00000010u)
#define CSL_MOD_HDR_WORD1_B_TABLE_INDEX_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD1_JACK_BIT_MASK  (0x01000000u)
#define CSL_MOD_HDR_WORD1_JACK_BIT_SHIFT (0x00000018u)
#define CSL_MOD_HDR_WORD1_JACK_BIT_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */

#define CSL_MOD_HDR_WORD2_CINIT_P2_MASK  (0x7FFFFFFFu)
#define CSL_MOD_HDR_WORD2_CINIT_P2_SHIFT (0x00000000u)
#define CSL_MOD_HDR_WORD2_CINIT_P2_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */

#define CSL_MOD_HDR_WORD3_RMUX_LN_MASK   (0x0000003Fu)
#define CSL_MOD_HDR_WORD3_RMUX_LN_SHIFT  (0x00000000u)
#define CSL_MOD_HDR_WORD3_RMUX_LN_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD3_CQI_LN_MASK    (0x7FFF0000u)
#define CSL_MOD_HDR_WORD3_CQI_LN_SHIFT   (0x00000010u)
#define CSL_MOD_HDR_WORD3_CQI_LN_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */

#define CSL_MOD_HDR_WORD4_RI_LN_MASK     (0x00003FFFu)
#define CSL_MOD_HDR_WORD4_RI_LN_SHIFT    (0x00000000u)
#define CSL_MOD_HDR_WORD4_RI_LN_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD4_ACK_LN_MASK    (0x3FFF0000u)
#define CSL_MOD_HDR_WORD4_ACK_LN_SHIFT   (0x00000010u)
#define CSL_MOD_HDR_WORD4_ACK_LN_RESETVAL (0x00000000u)


#define CSL_MOD_HDR_WORD4_RESETVAL       (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
