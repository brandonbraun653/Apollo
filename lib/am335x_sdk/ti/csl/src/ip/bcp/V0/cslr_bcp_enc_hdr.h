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
* file: cslr_enc_hdr.h
*
* Brief: This file contains the Register Description for enc_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_ENC_HDR_H_
#define CSLR_BCP_ENC_HDR_H_

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
    volatile Uint32 WORD0; /* ENC local header */
    volatile Uint32 WORD1; /* ENC block size 1 */
    volatile Uint32 WORD2; /* turbo code interleaver generator parameters */
    volatile Uint32 WORD3; /* turbo code interleaver generator parameters */
    volatile Uint32 WORD4; /* ENC block size 2 */
    volatile Uint32 WORD5; /* turbo code interleaver generator parameters */
    volatile Uint32 WORD6; /* turbo code interleaver generator parameters */
    volatile Uint32 WORD7; /* ENC block size 2 */
    volatile Uint32 WORD8; /* turbo code interleaver generator parameters */
    volatile Uint32 WORD9; /* turbo code interleaver generator parameters */
} CSL_Enc_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */


#define CSL_ENC_HDR_WORD0_CODE_RATE_FLAG_MASK (0x00080000u)
#define CSL_ENC_HDR_WORD0_CODE_RATE_FLAG_SHIFT (0x00000013u)
#define CSL_ENC_HDR_WORD0_CODE_RATE_FLAG_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD0_SCR_CRC_ENABLE_MASK (0x00060000u)
#define CSL_ENC_HDR_WORD0_SCR_CRC_ENABLE_SHIFT (0x00000011u)
#define CSL_ENC_HDR_WORD0_SCR_CRC_ENABLE_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD0_TURBO_CONV_SEL_MASK (0x00010000u)
#define CSL_ENC_HDR_WORD0_TURBO_CONV_SEL_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD0_TURBO_CONV_SEL_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_ENC_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_ENC_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000007Fu)
#define CSL_ENC_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */


#define CSL_ENC_HDR_WORD1_NUM_CODE_BLKS_MASK (0x01FF0000u)
#define CSL_ENC_HDR_WORD1_NUM_CODE_BLKS_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD1_NUM_CODE_BLKS_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD1_BLOCK_SIZE_1_MASK (0x00003FFFu)
#define CSL_ENC_HDR_WORD1_BLOCK_SIZE_1_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD1_BLOCK_SIZE_1_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */


#define CSL_ENC_HDR_WORD2_INTVPAR1_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD2_INTVPAR1_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD2_INTVPAR1_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD2_INTVPAR0_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD2_INTVPAR0_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD2_INTVPAR0_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */


#define CSL_ENC_HDR_WORD3_INTVPAR3_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD3_INTVPAR3_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD3_INTVPAR3_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD3_INTVPAR2_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD3_INTVPAR2_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD3_INTVPAR2_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */


#define CSL_ENC_HDR_WORD4_NUM_CODE_BLKS_MASK (0x003F0000u)
#define CSL_ENC_HDR_WORD4_NUM_CODE_BLKS_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD4_NUM_CODE_BLKS_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD4_BLOCK_SIZE_2_MASK (0x00003FFFu)
#define CSL_ENC_HDR_WORD4_BLOCK_SIZE_2_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD4_BLOCK_SIZE_2_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD4_RESETVAL       (0x00000000u)

/* Word 5 */


#define CSL_ENC_HDR_WORD5_INTVPAR1_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD5_INTVPAR1_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD5_INTVPAR1_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD5_INTVPAR0_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD5_INTVPAR0_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD5_INTVPAR0_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD5_RESETVAL       (0x00000000u)

/* Word 6 */


#define CSL_ENC_HDR_WORD6_INTVPAR3_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD6_INTVPAR3_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD6_INTVPAR3_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD6_INTVPAR2_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD6_INTVPAR2_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD6_INTVPAR2_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD6_RESETVAL       (0x00000000u)

/* Word 7 */


#define CSL_ENC_HDR_WORD7_NUM_CODE_BLKS_MASK (0x00010000u)
#define CSL_ENC_HDR_WORD7_NUM_CODE_BLKS_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD7_NUM_CODE_BLKS_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD7_BLOCK_SIZE_3_MASK (0x00003FFFu)
#define CSL_ENC_HDR_WORD7_BLOCK_SIZE_3_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD7_BLOCK_SIZE_3_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD7_RESETVAL       (0x00000000u)

/* Word 8 */


#define CSL_ENC_HDR_WORD8_INTVPAR1_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD8_INTVPAR1_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD8_INTVPAR1_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD8_INTVPAR0_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD8_INTVPAR0_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD8_INTVPAR0_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD8_RESETVAL       (0x00000000u)

/* Word 9 */


#define CSL_ENC_HDR_WORD9_INTVPAR3_MASK  (0x03FF0000u)
#define CSL_ENC_HDR_WORD9_INTVPAR3_SHIFT (0x00000010u)
#define CSL_ENC_HDR_WORD9_INTVPAR3_RESETVAL (0x00000000u)


#define CSL_ENC_HDR_WORD9_INTVPAR2_MASK  (0x000001FFu)
#define CSL_ENC_HDR_WORD9_INTVPAR2_SHIFT (0x00000000u)
#define CSL_ENC_HDR_WORD9_INTVPAR2_RESETVAL (0x00000000u)

#define CSL_ENC_HDR_WORD9_RESETVAL       (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
