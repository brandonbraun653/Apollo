/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
/** ============================================================================
 *   @file  cslr_hpi.h
 *
 *   @path  $(CSLPATH)
 *
 *   @desc  This file contains the Register Descriptions for HPI
 *
 *  ============================================================================
 */
#ifndef CSLR_HPI_H_
#define CSLR_HPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVID;
    volatile Uint32 PWREMU_MGMT;
    volatile Uint8 RSVD0[40];
    volatile Uint32 HPIC;
    volatile Uint32 HPIAW;
    volatile Uint32 HPIAR;
} CSL_HpiRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_HpiRegs         *CSL_HpiRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVID */


#define CSL_HPI_REVID_REV_MASK         (0xFFFFFFFFu)
#define CSL_HPI_REVID_REV_SHIFT        (0x00000000u)
#define CSL_HPI_REVID_REV_RESETVAL     (0x4421210Au)

#define CSL_HPI_REVID_RESETVAL           (0x4421210Au)

/* PWREMU_MGMT */


#define CSL_HPI_PWREMU_MGMT_SOFT_MASK (0x00000002u)
#define CSL_HPI_PWREMU_MGMT_SOFT_SHIFT (0x00000001u)
#define CSL_HPI_PWREMU_MGMT_SOFT_RESETVAL (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_HPI_PWREMU_MGMT_SOFT_OFF (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_SOFT_ON (0x00000001u)

#define CSL_HPI_PWREMU_MGMT_FREE_MASK (0x00000001u)
#define CSL_HPI_PWREMU_MGMT_FREE_SHIFT (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_FREE_RESETVAL (0x00000000u)
/*----FREE Tokens----*/
#define CSL_HPI_PWREMU_MGMT_FREE_OFF (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_FREE_ON (0x00000001u)

#define CSL_HPI_PWREMU_MGMT_RESETVAL (0x00000000u)

/* HPIC */


#define CSL_HPI_HPIC_HPIASEL_MASK (0x00000800u)
#define CSL_HPI_HPIC_HPIASEL_SHIFT (0x0000000Bu)
#define CSL_HPI_HPIC_HPIASEL_RESETVAL (0x00000000u)
/*----HPIASEL Tokens----*/
#define CSL_HPI_HPIC_HPIASEL_WRITE (0x00000000u)
#define CSL_HPI_HPIC_HPIASEL_READ (0x00000001u)


#define CSL_HPI_HPIC_DUALHPIA_MASK (0x00000200u)
#define CSL_HPI_HPIC_DUALHPIA_SHIFT (0x00000009u)
#define CSL_HPI_HPIC_DUALHPIA_RESETVAL (0x00000000u)
/*----DUALHPIA Tokens----*/
#define CSL_HPI_HPIC_DUALHPIA_DISABLE (0x00000000u)
#define CSL_HPI_HPIC_DUALHPIA_ENABLE (0x00000001u)


#define CSL_HPI_HPIC_HWOBSTAT_MASK (0x00000100u)
#define CSL_HPI_HPIC_HWOBSTAT_SHIFT (0x00000008u)
#define CSL_HPI_HPIC_HWOBSTAT_RESETVAL (0x00000000u)
/*----HWOBSTAT Tokens----*/
#define CSL_HPI_HPIC_HWOBSTAT_LOGIC0 (0x00000000u)
#define CSL_HPI_HPIC_HWOBSTAT_LOGIC1 (0x00000001u)


#define CSL_HPI_HPIC_HPIRST_MASK (0x00000080u)
#define CSL_HPI_HPIC_HPIRST_SHIFT (0x00000007u)
#define CSL_HPI_HPIC_HPIRST_RESETVAL (0x00000001u)

#define CSL_HPI_HPIC_FETCH_MASK (0x00000010u)
#define CSL_HPI_HPIC_FETCH_SHIFT (0x00000004u)
#define CSL_HPI_HPIC_FETCH_RESETVAL (0x00000000u)

#define CSL_HPI_HPIC_HINT_MASK (0x00000004u)
#define CSL_HPI_HPIC_HINT_SHIFT (0x00000002u)
#define CSL_HPI_HPIC_HINT_RESETVAL (0x00000000u)
/*----HINT Tokens----*/
#define CSL_HPI_HPIC_HINT_ENABLE (0x00000001u)

#define CSL_HPI_HPIC_DSPINT_MASK (0x00000002u)
#define CSL_HPI_HPIC_DSPINT_SHIFT (0x00000001u)
#define CSL_HPI_HPIC_DSPINT_RESETVAL (0x00000000u)
/*----DSPINT Tokens----*/
#define CSL_HPI_HPIC_DSPINT_ENABLE (0x00000001u)

#define CSL_HPI_HPIC_HWOB_MASK (0x00000001u)
#define CSL_HPI_HPIC_HWOB_SHIFT (0x00000000u)
#define CSL_HPI_HPIC_HWOB_RESETVAL (0x00000000u)
/*----HWOB Tokens----*/
#define CSL_HPI_HPIC_HWOB_MS (0x00000000u)
#define CSL_HPI_HPIC_HWOB_LS (0x00000001u)

#define CSL_HPI_HPIC_RESETVAL (0x00000088u)

/* HPIAW */

#define CSL_HPI_HPIAW_HPIAW_MASK (0xFFFFFFFFu)
#define CSL_HPI_HPIAW_HPIAW_SHIFT (0x00000000u)
#define CSL_HPI_HPIAW_HPIAW_RESETVAL (0x00008000u)

#define CSL_HPI_HPIAW_RESETVAL (0x00008000u)

/* HPIAR */

#define CSL_HPI_HPIAR_HPIAR_MASK (0xFFFFFFFFu)
#define CSL_HPI_HPIAR_HPIAR_SHIFT (0x00000000u)
#define CSL_HPI_HPIAR_HPIAR_RESETVAL (0x00008000u)

#define CSL_HPI_HPIAR_RESETVAL (0x00008000u)

#ifdef __cplusplus
}
#endif

#endif
