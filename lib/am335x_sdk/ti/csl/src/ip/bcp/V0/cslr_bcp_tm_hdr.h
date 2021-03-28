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
* file: cslr_tm_hdr.h
*
* Brief: This file contains the Register Description for tm_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_TM_HDR_H_
#define CSLR_BCP_TM_HDR_H_

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
    volatile Uint32 WORD0; /* TM local header */
    volatile Uint32 TM_HDR_CTRL; /* tm_hdr_ctrl */
    volatile Uint32 TM_HDR_DATA[33]; /* Holds PS or INFO data if needed */
} CSL_Tm_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */


#define CSL_TM_HDR_WORD0_MOD_ID_MASK     (0x00000F00u)
#define CSL_TM_HDR_WORD0_MOD_ID_SHIFT    (0x00000008u)
#define CSL_TM_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)

#define CSL_TM_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x000000FFu)
#define CSL_TM_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_TM_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_TM_HDR_WORD0_RESETVAL        (0x00000000u)

/* tm_hdr_ctrl */


#define CSL_TM_HDR_TM_HDR_CTRL_INFO_DATA_SIZE_MASK (0x000001F0u)
#define CSL_TM_HDR_TM_HDR_CTRL_INFO_DATA_SIZE_SHIFT (0x00000004u)
#define CSL_TM_HDR_TM_HDR_CTRL_INFO_DATA_SIZE_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_CTRL_PS_DATA_SIZE_MASK (0x0000000Fu)
#define CSL_TM_HDR_TM_HDR_CTRL_PS_DATA_SIZE_SHIFT (0x00000000u)
#define CSL_TM_HDR_TM_HDR_CTRL_PS_DATA_SIZE_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_CTRL_RESETVAL  (0x00000000u)

/* tm_hdr_data */

#define CSL_TM_HDR_TM_HDR_DATA_DATA3_MASK (0xFF000000u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA3_SHIFT (0x00000018u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA3_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_DATA_DATA2_MASK (0x00FF0000u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA2_SHIFT (0x00000010u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA2_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_DATA_DATA1_MASK (0x0000FF00u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA1_SHIFT (0x00000008u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA1_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_DATA_DATA0_MASK (0x000000FFu)
#define CSL_TM_HDR_TM_HDR_DATA_DATA0_SHIFT (0x00000000u)
#define CSL_TM_HDR_TM_HDR_DATA_DATA0_RESETVAL (0x00000000u)

#define CSL_TM_HDR_TM_HDR_DATA_RESETVAL  (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
