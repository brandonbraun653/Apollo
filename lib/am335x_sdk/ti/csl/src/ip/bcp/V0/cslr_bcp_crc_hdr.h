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
* file: cslr_crc_hdr.h
*
* Brief: This file contains the Register Description for crc_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_CRC_HDR_H_
#define CSLR_BCP_CRC_HDR_H_

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
    volatile Uint32 WORD0; /* CRC local header */
    volatile Uint32 WORD1; /* CRC scrambler init */
    volatile Uint32 WORD2; /* CRC method2 */
    volatile Uint32 WORD3; /* CRC descriptor */
    volatile Uint32 WORD4; /* CRC descriptor */
    volatile Uint32 WORD5; /* CRC descriptor */
    volatile Uint32 WORD6; /* CRC descriptor */
    volatile Uint32 WORD7; /* CRC descriptor */
    volatile Uint32 WORD8; /* CRC descriptor */
} CSL_Crc_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */

// TODO: It looks like from the spec this field does not exist. Check with spec
//          owner to confirm.
// #define CSL_CRC_HDR_WORD0_SCRAM_COEFF_SEL_MASK (0x04000000u)
// #define CSL_CRC_HDR_WORD0_SCRAM_COEFF_SEL_SHIFT (0x0000001Au)
// #define CSL_CRC_HDR_WORD0_SCRAM_COEFF_SEL_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD0_DTX_FORMAT_MASK (0x02000000u)
#define CSL_CRC_HDR_WORD0_DTX_FORMAT_SHIFT (0x00000019u)
#define CSL_CRC_HDR_WORD0_DTX_FORMAT_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD0_LTE_ORDER_MASK (0x01000000u)
#define CSL_CRC_HDR_WORD0_LTE_ORDER_SHIFT (0x00000018u)
#define CSL_CRC_HDR_WORD0_LTE_ORDER_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD0_FILLER_BITS_MASK (0x00FF0000u)
#define CSL_CRC_HDR_WORD0_FILLER_BITS_SHIFT (0x00000010u)
#define CSL_CRC_HDR_WORD0_FILLER_BITS_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_CRC_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_CRC_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000007Fu)
#define CSL_CRC_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */

#define CSL_CRC_HDR_WORD1_NUM_SCRAMBLE_SYS_MASK (0xFFFFFFFFu)
#define CSL_CRC_HDR_WORD1_NUM_SCRAMBLE_SYS_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD1_NUM_SCRAMBLE_SYS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */

#define CSL_CRC_HDR_WORD2_METHOD2_ID_MASK (0xFFFFFFFFu)
#define CSL_CRC_HDR_WORD2_METHOD2_ID_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD2_METHOD2_ID_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */

#define CSL_CRC_HDR_WORD3_VA_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD3_VA_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD3_VA_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD3_VA_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD3_VA_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD3_VA_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD3_VA_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD3_VA_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD3_VA_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */

#define CSL_CRC_HDR_WORD4_VB_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD4_VB_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD4_VB_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD4_VB_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD4_VB_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD4_VB_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD4_VB_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD4_VB_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD4_VB_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD4_RESETVAL       (0x00000000u)

/* Word 5 */

#define CSL_CRC_HDR_WORD5_VC_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD5_VC_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD5_VC_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD5_VC_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD5_VC_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD5_VC_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD5_VC_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD5_VC_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD5_VC_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD5_RESETVAL       (0x00000000u)

/* Word 6 */

#define CSL_CRC_HDR_WORD6_D1_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD6_D1_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD6_D1_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD6_D1_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD6_D1_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD6_D1_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD6_D1_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD6_D1_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD6_D1_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD6_RESETVAL       (0x00000000u)

/* Word 7 */

#define CSL_CRC_HDR_WORD7_D2_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD7_D2_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD7_D2_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD7_D2_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD7_D2_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD7_D2_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD7_D2_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD7_D2_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD7_D2_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD7_RESETVAL       (0x00000000u)

/* Word 8 */

#define CSL_CRC_HDR_WORD8_DC_BLK_LEN_MASK (0x000FFFFFu)
#define CSL_CRC_HDR_WORD8_DC_BLK_LEN_SHIFT (0x00000000u)
#define CSL_CRC_HDR_WORD8_DC_BLK_LEN_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD8_DC_CRC_MASK    (0x00700000u)
#define CSL_CRC_HDR_WORD8_DC_CRC_SHIFT   (0x00000014u)
#define CSL_CRC_HDR_WORD8_DC_CRC_RESETVAL (0x00000000u)


#define CSL_CRC_HDR_WORD8_DC_BLKS_MASK   (0xFF000000u)
#define CSL_CRC_HDR_WORD8_DC_BLKS_SHIFT  (0x00000018u)
#define CSL_CRC_HDR_WORD8_DC_BLKS_RESETVAL (0x00000000u)

#define CSL_CRC_HDR_WORD8_RESETVAL       (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
