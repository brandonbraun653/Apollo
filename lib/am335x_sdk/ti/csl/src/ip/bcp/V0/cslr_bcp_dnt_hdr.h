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
* file: cslr_dnt_hdr.h
*
* Brief: This file contains the Register Description for dnt_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_DNT_HDR_H_
#define CSLR_BCP_DNT_HDR_H_

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
    volatile Uint32 WORD0; /* Generic Register description */
    volatile Uint32 WORD1; /* Generic Register description */
    volatile Uint32 WORD2; /* Generic Register description */
    volatile Uint32 WORD3; /* Generic Register description */
    volatile Uint32 WORD4; /* Generic Register description */
    volatile Uint32 WORD5; /* Generic Register description */
    volatile Uint32 WORD6; /* Generic Register description */
    volatile Uint32 WORD7; /* Generic Register description */
    volatile Uint32 WORD8; /* Generic Register description */
} CSL_Dnt_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */

#define CSL_DNT_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x000000FFu)
#define CSL_DNT_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_DNT_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_DNT_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)

// TODO: It looks like from the spec the PPB config is having same bit filed
//          configuration for local header and MOD ID. So, added the old
//          defintions here as workaround. Check with spec owner to confirm.
// #define CSL_DNT_HDR_WORD0_PPB_HEADER_MASK (0x0000FFFFu)
// #define CSL_DNT_HDR_WORD0_PPB_HEADER_SHIFT (0x00000000u)
// #define CSL_DNT_HDR_WORD0_PPB_HEADER_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD0__RESV_MASK     (0xFFFF0000u)
#define CSL_DNT_HDR_WORD0__RESV_SHIFT    (0x00000010u)
#define CSL_DNT_HDR_WORD0__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */

#define CSL_DNT_HDR_WORD1_NUM_CONSTELLATION_MASK (0x00000003u)
#define CSL_DNT_HDR_WORD1_NUM_CONSTELLATION_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD1_NUM_CONSTELLATION_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD1__RESV_MASK     (0x000000FCu)
#define CSL_DNT_HDR_WORD1__RESV_SHIFT    (0x00000002u)
#define CSL_DNT_HDR_WORD1__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD1_NUM_FRAME_COUNT_MASK (0x00001F00u)
#define CSL_DNT_HDR_WORD1_NUM_FRAME_COUNT_SHIFT (0x00000008u)
#define CSL_DNT_HDR_WORD1_NUM_FRAME_COUNT_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD1__RESV2_MASK    (0x0000E000u)
#define CSL_DNT_HDR_WORD1__RESV2_SHIFT   (0x0000000Du)
#define CSL_DNT_HDR_WORD1__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD1_NUM_DESCRAMBLE_MASK (0xFFFF0000u)
#define CSL_DNT_HDR_WORD1_NUM_DESCRAMBLE_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD1_NUM_DESCRAMBLE_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */

#define CSL_DNT_HDR_WORD2_NUM_DATA_VALUE_MASK (0x00FFFFFFu)
#define CSL_DNT_HDR_WORD2_NUM_DATA_VALUE_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD2_NUM_DATA_VALUE_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD2__RESV_MASK     (0xFF000000u)
#define CSL_DNT_HDR_WORD2__RESV_SHIFT    (0x00000018u)
#define CSL_DNT_HDR_WORD2__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */

#define CSL_DNT_HDR_WORD3_NUM_R2_LENGTH_0_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD3_NUM_R2_LENGTH_0_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD3_NUM_R2_LENGTH_0_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD3_NUM_DUMMY_0_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD3_NUM_DUMMY_0_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD3_NUM_DUMMY_0_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD3__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD3__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD3__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD3_NUM_DATA_FORMAT_0_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD3_NUM_DATA_FORMAT_0_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD3_NUM_DATA_FORMAT_0_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD3__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD3__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD3__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */

#define CSL_DNT_HDR_WORD4_NUM_R2_LENGTH_1_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD4_NUM_R2_LENGTH_1_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD4_NUM_R2_LENGTH_1_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD4_NUM_DUMMY_1_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD4_NUM_DUMMY_1_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD4_NUM_DUMMY_1_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD4__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD4__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD4__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD4_NUM_DATA_FORMAT_1_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD4_NUM_DATA_FORMAT_1_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD4_NUM_DATA_FORMAT_1_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD4__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD4__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD4__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD4_RESETVAL       (0x00000000u)

/* Word 5 */

#define CSL_DNT_HDR_WORD5_NUM_R2_LENGTH_2_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD5_NUM_R2_LENGTH_2_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD5_NUM_R2_LENGTH_2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD5_NUM_DUMMY_2_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD5_NUM_DUMMY_2_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD5_NUM_DUMMY_2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD5__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD5__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD5__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD5_NUM_DATA_FORMAT_2_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD5_NUM_DATA_FORMAT_2_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD5_NUM_DATA_FORMAT_2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD5__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD5__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD5__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD5_RESETVAL       (0x00000000u)

/* Word 6 */

#define CSL_DNT_HDR_WORD6_NUM_R2_LENGTH_3_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD6_NUM_R2_LENGTH_3_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD6_NUM_R2_LENGTH_3_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD6_NUM_DUMMY_3_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD6_NUM_DUMMY_3_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD6_NUM_DUMMY_3_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD6__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD6__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD6__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD6_NUM_DATA_FORMAT_3_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD6_NUM_DATA_FORMAT_3_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD6_NUM_DATA_FORMAT_3_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD6__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD6__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD6__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD6_RESETVAL       (0x00000000u)

/* Word 7 */

#define CSL_DNT_HDR_WORD7_NUM_R2_LENGTH_4_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD7_NUM_R2_LENGTH_4_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD7_NUM_R2_LENGTH_4_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD7_NUM_DUMMY_4_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD7_NUM_DUMMY_4_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD7_NUM_DUMMY_4_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD7__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD7__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD7__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD7_NUM_DATA_FORMAT_4_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD7_NUM_DATA_FORMAT_4_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD7_NUM_DATA_FORMAT_4_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD7__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD7__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD7__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD7_RESETVAL       (0x00000000u)

/* Word 8 */

#define CSL_DNT_HDR_WORD8_NUM_R2_LENGTH_5_MASK (0x0000FFFFu)
#define CSL_DNT_HDR_WORD8_NUM_R2_LENGTH_5_SHIFT (0x00000000u)
#define CSL_DNT_HDR_WORD8_NUM_R2_LENGTH_5_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD8_NUM_DUMMY_5_MASK (0x001F0000u)
#define CSL_DNT_HDR_WORD8_NUM_DUMMY_5_SHIFT (0x00000010u)
#define CSL_DNT_HDR_WORD8_NUM_DUMMY_5_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD8__RESV_MASK     (0x00E00000u)
#define CSL_DNT_HDR_WORD8__RESV_SHIFT    (0x00000015u)
#define CSL_DNT_HDR_WORD8__RESV_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD8_NUM_DATA_FORMAT_5_MASK (0x3F000000u)
#define CSL_DNT_HDR_WORD8_NUM_DATA_FORMAT_5_SHIFT (0x00000018u)
#define CSL_DNT_HDR_WORD8_NUM_DATA_FORMAT_5_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD8__RESV2_MASK    (0xC0000000u)
#define CSL_DNT_HDR_WORD8__RESV2_SHIFT   (0x0000001Eu)
#define CSL_DNT_HDR_WORD8__RESV2_RESETVAL (0x00000000u)

#define CSL_DNT_HDR_WORD8_RESETVAL       (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif