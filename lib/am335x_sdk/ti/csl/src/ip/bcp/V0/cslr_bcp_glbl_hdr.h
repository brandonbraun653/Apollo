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
* file: cslr_glbl_hdr.h
*
* Brief: This file contains the Register Description for glbl_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_GLBL_HDR_H_
#define CSLR_BCP_GLBL_HDR_H_

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
    volatile Uint32 WORD0; /* BCP Global Header */
    volatile Uint32 WORD1; /* BCP Global Tag */
} CSL_Glbl_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */


#define CSL_GLBL_HDR_WORD0_FLOW_ID_MASK  (0x3F000000u)
#define CSL_GLBL_HDR_WORD0_FLOW_ID_SHIFT (0x00000018u)
#define CSL_GLBL_HDR_WORD0_FLOW_ID_RESETVAL (0x00000000u)

#define CSL_GLBL_HDR_WORD0_GHDR_END_PTR_MASK (0x00FF0000u)
#define CSL_GLBL_HDR_WORD0_GHDR_END_PTR_SHIFT (0x00000010u)
#define CSL_GLBL_HDR_WORD0_GHDR_END_PTR_RESETVAL (0x00000000u)


#define CSL_GLBL_HDR_WORD0_RADIO_STANDARD_MASK (0x00000700u)
#define CSL_GLBL_HDR_WORD0_RADIO_STANDARD_SHIFT (0x00000008u)
#define CSL_GLBL_HDR_WORD0_RADIO_STANDARD_RESETVAL (0x00000000u)


#define CSL_GLBL_HDR_WORD0_HALT_MASK     (0x00000020u)
#define CSL_GLBL_HDR_WORD0_HALT_SHIFT    (0x00000005u)
#define CSL_GLBL_HDR_WORD0_HALT_RESETVAL (0x00000000u)

#define CSL_GLBL_HDR_WORD0_DROP_MASK     (0x00000010u)
#define CSL_GLBL_HDR_WORD0_DROP_SHIFT    (0x00000004u)
#define CSL_GLBL_HDR_WORD0_DROP_RESETVAL (0x00000000u)

#define CSL_GLBL_HDR_WORD0_FLUSH_MASK    (0x00000008u)
#define CSL_GLBL_HDR_WORD0_FLUSH_SHIFT   (0x00000003u)
#define CSL_GLBL_HDR_WORD0_FLUSH_RESETVAL (0x00000000u)


#define CSL_GLBL_HDR_WORD0_PKT_TYPE_MASK (0x00000003u)
#define CSL_GLBL_HDR_WORD0_PKT_TYPE_SHIFT (0x00000000u)
#define CSL_GLBL_HDR_WORD0_PKT_TYPE_RESETVAL (0x00000000u)

#define CSL_GLBL_HDR_WORD0_RESETVAL      (0x00000000u)

/* Word 1 */

#define CSL_GLBL_HDR_WORD1_GLBL_TAG_MASK (0xFFFFFFFFu)
#define CSL_GLBL_HDR_WORD1_GLBL_TAG_SHIFT (0x00000000u)
#define CSL_GLBL_HDR_WORD1_GLBL_TAG_RESETVAL (0x00000000u)

#define CSL_GLBL_HDR_WORD1_RESETVAL      (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
