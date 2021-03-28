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
* file: cslr_dio_hdr.h
*
* Brief: This file contains the Register Description for dio_hdr
*
*********************************************************************/
#ifndef CSLR_BCP_DIO_HDR_H_
#define CSLR_BCP_DIO_HDR_H_

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
    volatile Uint32 WORD0; /* DIO local header */
    volatile Uint32 WORD1; /* DIO DMA block 0 address control */
    volatile Uint32 WORD2; /* length of block in bytes */
    volatile Uint32 WORD3; /* DIO DMA block 0 address control */
    volatile Uint32 WORD4; /* length of block in bytes */
    volatile Uint32 WORD5; /* DIO DMA block 0 address control */
    volatile Uint32 WORD6; /* length of block in bytes */
    volatile Uint32 WORD7; /* DIO DMA block 0 address control */
    volatile Uint32 WORD8; /* length of block in bytes */
    volatile Uint32 WORD9; /* DIO DMA block 0 address control */
    volatile Uint32 WORD10; /* length of block in bytes */
    volatile Uint32 WORD11; /* DIO DMA block 0 address control */
    volatile Uint32 WORD12; /* length of block in bytes */
} CSL_Dio_hdrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* Word 0 */


#define CSL_DIO_HDR_WORD0_DIO_BLK_CNT_MASK (0x0E000000u)
#define CSL_DIO_HDR_WORD0_DIO_BLK_CNT_SHIFT (0x00000019u)
#define CSL_DIO_HDR_WORD0_DIO_BLK_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD0_DIO_RD_WR_MASK (0x01000000u)
#define CSL_DIO_HDR_WORD0_DIO_RD_WR_SHIFT (0x00000018u)
#define CSL_DIO_HDR_WORD0_DIO_RD_WR_RESETVAL (0x00000000u)


#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_MASK (0x00180000u)
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_SHIFT (0x00000013u)
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_RESETVAL (0x00000000u)
/*----DIO_ENDIAN Tokens----*/
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_NOSWAP (0x00000000u)
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_32BIT (0x00000001u)
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_16BIT (0x00000002u)
#define CSL_DIO_HDR_WORD0_DIO_ENDIAN_8BIT (0x00000003u)


#define CSL_DIO_HDR_WORD0_MOD_ID_MASK    (0x00000F00u)
#define CSL_DIO_HDR_WORD0_MOD_ID_SHIFT   (0x00000008u)
#define CSL_DIO_HDR_WORD0_MOD_ID_RESETVAL (0x00000000u)


#define CSL_DIO_HDR_WORD0_LOCAL_HDR_LEN_MASK (0x0000007Fu)
#define CSL_DIO_HDR_WORD0_LOCAL_HDR_LEN_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD0_LOCAL_HDR_LEN_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD0_RESETVAL       (0x00000000u)

/* Word 1 */

#define CSL_DIO_HDR_WORD1_DIO_ADDR_MASK  (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD1_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD1_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD1_RESETVAL       (0x00000000u)

/* Word 2 */


#define CSL_DIO_HDR_WORD2_DIO_CNT_MASK   (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD2_DIO_CNT_SHIFT  (0x00000000u)
#define CSL_DIO_HDR_WORD2_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD2_RESETVAL       (0x00000000u)

/* Word 3 */

#define CSL_DIO_HDR_WORD3_DIO_ADDR_MASK  (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD3_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD3_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD3_RESETVAL       (0x00000000u)

/* Word 4 */


#define CSL_DIO_HDR_WORD4_DIO_CNT_MASK   (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD4_DIO_CNT_SHIFT  (0x00000000u)
#define CSL_DIO_HDR_WORD4_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD4_RESETVAL       (0x00000000u)

/* Word 5 */

#define CSL_DIO_HDR_WORD5_DIO_ADDR_MASK  (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD5_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD5_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD5_RESETVAL       (0x00000000u)

/* Word 6 */


#define CSL_DIO_HDR_WORD6_DIO_CNT_MASK   (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD6_DIO_CNT_SHIFT  (0x00000000u)
#define CSL_DIO_HDR_WORD6_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD6_RESETVAL       (0x00000000u)

/* Word 7 */

#define CSL_DIO_HDR_WORD7_DIO_ADDR_MASK  (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD7_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD7_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD7_RESETVAL       (0x00000000u)

/* Word 8 */


#define CSL_DIO_HDR_WORD8_DIO_CNT_MASK   (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD8_DIO_CNT_SHIFT  (0x00000000u)
#define CSL_DIO_HDR_WORD8_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD8_RESETVAL       (0x00000000u)

/* Word 9 */

#define CSL_DIO_HDR_WORD9_DIO_ADDR_MASK  (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD9_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD9_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD9_RESETVAL       (0x00000000u)

/* Word 10 */


#define CSL_DIO_HDR_WORD10_DIO_CNT_MASK  (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD10_DIO_CNT_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD10_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD10_RESETVAL      (0x00000000u)

/* Word 11 */

#define CSL_DIO_HDR_WORD11_DIO_ADDR_MASK (0xFFFFFFFFu)
#define CSL_DIO_HDR_WORD11_DIO_ADDR_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD11_DIO_ADDR_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD11_RESETVAL      (0x00000000u)

/* Word 12 */


#define CSL_DIO_HDR_WORD12_DIO_CNT_MASK  (0x01FFFFFFu)
#define CSL_DIO_HDR_WORD12_DIO_CNT_SHIFT (0x00000000u)
#define CSL_DIO_HDR_WORD12_DIO_CNT_RESETVAL (0x00000000u)

#define CSL_DIO_HDR_WORD12_RESETVAL      (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
