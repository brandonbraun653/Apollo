/*
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/********************************************************************
* file: cslr_ra_lut1_dbg.h
*
* Brief: This file contains the Register Description for ra_lut1_dbg
*
*********************************************************************/
#ifndef CSLR_RA_LUT1_DBG_H_
#define CSLR_RA_LUT1_DBG_H_

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
    volatile Uint8 ENTRY[46]; /* Entry bytes */
    volatile Uint8 RANGE[4]; /* Range bytes */
    volatile Uint8 CARE[8]; /* Care bytes */
    volatile Uint8 RESERVED[6]; /* Reserved bytes */
} CSL_Ra_lut1_dbgRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ENTRY */

#define CSL_RA_LUT1_DBG_ENTRY_ENTRY_MASK (0xFFu)
#define CSL_RA_LUT1_DBG_ENTRY_ENTRY_SHIFT (0x00u)
#define CSL_RA_LUT1_DBG_ENTRY_ENTRY_RESETVAL (0x00u)

#define CSL_RA_LUT1_DBG_ENTRY_RESETVAL   (0x00u)

/* RANGE */

#define CSL_RA_LUT1_DBG_RANGE_RANGE_MASK (0xFFu)
#define CSL_RA_LUT1_DBG_RANGE_RANGE_SHIFT (0x00u)
#define CSL_RA_LUT1_DBG_RANGE_RANGE_RESETVAL (0x00u)

#define CSL_RA_LUT1_DBG_RANGE_RESETVAL   (0x00u)

/* CARE */

#define CSL_RA_LUT1_DBG_CARE_CARE_MASK   (0xFFu)
#define CSL_RA_LUT1_DBG_CARE_CARE_SHIFT  (0x00u)
#define CSL_RA_LUT1_DBG_CARE_CARE_RESETVAL (0x00u)

#define CSL_RA_LUT1_DBG_CARE_RESETVAL    (0x00u)

/* RESERVED */

#define CSL_RA_LUT1_DBG_RESERVED_RESERVED_MASK (0xFFu)
#define CSL_RA_LUT1_DBG_RESERVED_RESERVED_SHIFT (0x00u)
#define CSL_RA_LUT1_DBG_RESERVED_RESERVED_RESETVAL (0x00u)

#define CSL_RA_LUT1_DBG_RESERVED_RESETVAL (0x00u)


#ifdef __cplusplus
}
#endif

#endif
