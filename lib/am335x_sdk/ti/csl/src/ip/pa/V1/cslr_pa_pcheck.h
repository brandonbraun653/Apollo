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
* file: cslr_pa_pcheck.h
*
* Brief: This file contains the Register Description for pa_pcheck
*
*********************************************************************/
#ifndef CSLR_PA_PCHECK_H_
#define CSLR_PA_PCHECK_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for recipe
\**************************************************************************/
typedef struct  {
    volatile Uint32 CONTROL; /* The Recipe N Control Register contains the controls for the CRC defined for recipe N */
    volatile Uint32 TABLE[15]; /* The Recipe N Table T Registers contain the table data for the CRC defined for recipe N */
} CSL_Pa_pcheckRecipeRegs; /* The Recipe Registers contain the controls for the CRC defined for each recipe */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION; /* Revision Register */
    volatile Uint8 RSVD0[60];
    CSL_Pa_pcheckRecipeRegs RECIPE[4];
} CSL_Pa_pcheckRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CONTROL */

#define CSL_PA_PCHECK_CONTROL_RSHIFT_MASK (0x00000002u)
#define CSL_PA_PCHECK_CONTROL_RSHIFT_SHIFT (0x00000001u)
#define CSL_PA_PCHECK_CONTROL_RSHIFT_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_CONTROL_FINAL_NOT_MASK (0x00000001u)
#define CSL_PA_PCHECK_CONTROL_FINAL_NOT_SHIFT (0x00000000u)
#define CSL_PA_PCHECK_CONTROL_FINAL_NOT_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_CONTROL_RESETVAL   (0x00000000u)

/* TABLE */

#define CSL_PA_PCHECK_TABLE_VALUE_MASK   (0xFFFFFFFFu)
#define CSL_PA_PCHECK_TABLE_VALUE_SHIFT  (0x00000000u)
#define CSL_PA_PCHECK_TABLE_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_TABLE_RESETVAL     (0x00000000u)

/* REVISION */

#define CSL_PA_PCHECK_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_PA_PCHECK_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_PCHECK_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_PA_PCHECK_REVISION_MODID_MASK (0x0FFF0000u)
#define CSL_PA_PCHECK_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_PA_PCHECK_REVISION_MODID_RESETVAL (0x00000EF1u)

#define CSL_PA_PCHECK_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_PA_PCHECK_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_PA_PCHECK_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_PA_PCHECK_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_PA_PCHECK_REVISION_REVMAJ_RESETVAL (0x00000001u)

#define CSL_PA_PCHECK_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_PA_PCHECK_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_PA_PCHECK_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_PA_PCHECK_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_PA_PCHECK_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_PA_PCHECK_REVISION_RESETVAL  (0x4EF10100u)


#ifdef __cplusplus
}
#endif

#endif
