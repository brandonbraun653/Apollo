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
* file: cslr_rm_lte_hdr.h
*
* Brief: This file contains the Register Description for rm_lte_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_RM_LTE_HDR_H_
#define CSLR_BCP_RM_LTE_HDR_H_

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
    volatile Uint32 WORD0; /* rate matching local header */
    volatile Uint32 WORD1; /* misc config word */
    volatile Uint32 WORD2; /* buffer wrap output config */
    volatile Uint32 WORD3; /* code block1 input config */
    volatile Uint32 WORD4; /* code block1 output config */
    volatile Uint32 WORD5; /* code block2 input config */
    volatile Uint32 WORD6; /* code block2 output config */
} CSL_Rm_lte_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */



#define CSL_RM_LTE_HDR_WORD0_MOD_ID_MASK (0x00000F00u)
#define CSL_RM_LTE_HDR_WORD0_MOD_ID_SHIFT (0x00000008u)
#define CSL_RM_LTE_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000003Fu)
#define CSL_RM_LTE_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD0_RESETVAL    (0x00000000u)

/* Word 1 */


#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN2_MASK (0x07F00000u)
#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN2_SHIFT (0x00000014u)
#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN2_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN1_MASK (0x0007F000u)
#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN1_SHIFT (0x0000000Cu)
#define CSL_RM_LTE_HDR_WORD1_RV_START_COLUMN1_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD1_NUM_FILLER_BITS_F_MASK (0x000003F0u)
#define CSL_RM_LTE_HDR_WORD1_NUM_FILLER_BITS_F_SHIFT (0x00000004u)
#define CSL_RM_LTE_HDR_WORD1_NUM_FILLER_BITS_F_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD1_OUTPUT_BIT_FORMAT_MASK (0x00000004u)
#define CSL_RM_LTE_HDR_WORD1_OUTPUT_BIT_FORMAT_SHIFT (0x00000002u)
#define CSL_RM_LTE_HDR_WORD1_OUTPUT_BIT_FORMAT_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD1_INPUT_BIT_FORMAT_MASK (0x00000002u)
#define CSL_RM_LTE_HDR_WORD1_INPUT_BIT_FORMAT_SHIFT (0x00000001u)
#define CSL_RM_LTE_HDR_WORD1_INPUT_BIT_FORMAT_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD1_CHANNEL_TYPE_MASK (0x00000001u)
#define CSL_RM_LTE_HDR_WORD1_CHANNEL_TYPE_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD1_CHANNEL_TYPE_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD1_RESETVAL    (0x00000000u)

/* Word 2 */

#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_ROW_MASK (0xFFC00000u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_ROW_SHIFT (0x00000016u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_ROW_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_COLUMN_MASK (0x001F0000u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_COLUMN_SHIFT (0x00000010u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB2_COLUMN_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_ROW_MASK (0x0000FFC0u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_ROW_SHIFT (0x00000006u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_ROW_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_COLUMN_MASK (0x0000001Fu)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_COLUMN_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD2_PARAM_NCB1_COLUMN_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD2_RESETVAL    (0x00000000u)

/* Word 3 */


#define CSL_RM_LTE_HDR_WORD3_BLOCK_SIZE_K1_MASK (0x3FFF0000u)
#define CSL_RM_LTE_HDR_WORD3_BLOCK_SIZE_K1_SHIFT (0x00000010u)
#define CSL_RM_LTE_HDR_WORD3_BLOCK_SIZE_K1_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD3_NUM_CODE_BLOCKS_C1_MASK (0x0000003Fu)
#define CSL_RM_LTE_HDR_WORD3_NUM_CODE_BLOCKS_C1_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD3_NUM_CODE_BLOCKS_C1_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD3_RESETVAL    (0x00000000u)

/* Word 4 */

#define CSL_RM_LTE_HDR_WORD4_BLOCK_SIZE_E1_MASK (0xFFFF0000u)
#define CSL_RM_LTE_HDR_WORD4_BLOCK_SIZE_E1_SHIFT (0x00000010u)
#define CSL_RM_LTE_HDR_WORD4_BLOCK_SIZE_E1_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD4_NUM_CODE_BLOCKS_CE1_MASK (0x0000003Fu)
#define CSL_RM_LTE_HDR_WORD4_NUM_CODE_BLOCKS_CE1_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD4_NUM_CODE_BLOCKS_CE1_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD4_RESETVAL    (0x00000000u)

/* Word 5 */


#define CSL_RM_LTE_HDR_WORD5_BLOCK_SIZE_K2_MASK (0x3FFF0000u)
#define CSL_RM_LTE_HDR_WORD5_BLOCK_SIZE_K2_SHIFT (0x00000010u)
#define CSL_RM_LTE_HDR_WORD5_BLOCK_SIZE_K2_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD5_NUM_CODE_BLOCKS_C2_MASK (0x0000003Fu)
#define CSL_RM_LTE_HDR_WORD5_NUM_CODE_BLOCKS_C2_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD5_NUM_CODE_BLOCKS_C2_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD5_RESETVAL    (0x00000000u)

/* Word 6 */

#define CSL_RM_LTE_HDR_WORD6_BLOCK_SIZE_E2_MASK (0xFFFF0000u)
#define CSL_RM_LTE_HDR_WORD6_BLOCK_SIZE_E2_SHIFT (0x00000010u)
#define CSL_RM_LTE_HDR_WORD6_BLOCK_SIZE_E2_RESETVAL (0x00000000u)


#define CSL_RM_LTE_HDR_WORD6_NUM_CODE_BLOCKS_CE2_MASK (0x0000003Fu)
#define CSL_RM_LTE_HDR_WORD6_NUM_CODE_BLOCKS_CE2_SHIFT (0x00000000u)
#define CSL_RM_LTE_HDR_WORD6_NUM_CODE_BLOCKS_CE2_RESETVAL (0x00000000u)

#define CSL_RM_LTE_HDR_WORD6_RESETVAL    (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
