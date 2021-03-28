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
* file: cslr_pa_splitter.h
*
* Brief: This file contains the Register Description for pa_splitter
*
*********************************************************************/
#ifndef CSLR_PA_SPLITTER_H_
#define CSLR_PA_SPLITTER_H_

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
    volatile Uint32 REVISION; /* The Revision Register contains the ID and revision information. */
    volatile Uint8 RSVD0[12];
    volatile Uint32 SOP_CTRL; /* The Splitter SOP Control Register specifies the maximum size of the SOP portion of the packet. */
    volatile Uint32 EOP_CTRL; /* The Splitter EOP Control Register specifies the maximum size of the EOP portion of the packet. */
    volatile Uint8 RSVD1[8];
    volatile Uint32 MOP_BUF_SIZE; /* The Splitter MOP Buffer Pointer Register specifies the starting address to the MOP buffer. */
    volatile Uint32 MOP_BUF_PTR; /* The Splitter MOP Buffer Pointer Register specifies the starting address to the MOP buffer. */
} CSL_Pa_splitterRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION */

#define CSL_PA_SPLITTER_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_PA_SPLITTER_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_SPLITTER_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_PA_SPLITTER_REVISION_MODID_MASK (0x0FFF0000u)
#define CSL_PA_SPLITTER_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_PA_SPLITTER_REVISION_MODID_RESETVAL (0x00000E5Cu)

#define CSL_PA_SPLITTER_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_PA_SPLITTER_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_PA_SPLITTER_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_PA_SPLITTER_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_PA_SPLITTER_REVISION_REVMAJ_RESETVAL (0x00000002u)

#define CSL_PA_SPLITTER_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_PA_SPLITTER_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_PA_SPLITTER_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_PA_SPLITTER_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_PA_SPLITTER_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_REVISION_RESETVAL (0x4E5C0200u)

/* SOP_CTRL */

#define CSL_PA_SPLITTER_SOP_CTRL_ENABLE_MASK (0x80000000u)
#define CSL_PA_SPLITTER_SOP_CTRL_ENABLE_SHIFT (0x0000001Fu)
#define CSL_PA_SPLITTER_SOP_CTRL_ENABLE_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_SOP_CTRL_MAX_SIZE_MASK (0x0001FFFFu)
#define CSL_PA_SPLITTER_SOP_CTRL_MAX_SIZE_SHIFT (0x00000000u)
#define CSL_PA_SPLITTER_SOP_CTRL_MAX_SIZE_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_SOP_CTRL_RESETVAL (0x00000000u)

/* EOP_CTRL */

#define CSL_PA_SPLITTER_EOP_CTRL_MAX_SIZE_MASK (0x000000FFu)
#define CSL_PA_SPLITTER_EOP_CTRL_MAX_SIZE_SHIFT (0x00000000u)
#define CSL_PA_SPLITTER_EOP_CTRL_MAX_SIZE_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_EOP_CTRL_RESETVAL (0x00000000u)

/* MOP_BUF_SIZE */

#define CSL_PA_SPLITTER_MOP_BUF_SIZE_VALUE_MASK (0x0003FFFFu)
#define CSL_PA_SPLITTER_MOP_BUF_SIZE_VALUE_SHIFT (0x00000000u)
#define CSL_PA_SPLITTER_MOP_BUF_SIZE_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_MOP_BUF_SIZE_RESETVAL (0x00000000u)

/* MOP_BUF_PTR */

#define CSL_PA_SPLITTER_MOP_BUF_PTR_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_SPLITTER_MOP_BUF_PTR_VALUE_SHIFT (0x00000000u)
#define CSL_PA_SPLITTER_MOP_BUF_PTR_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_SPLITTER_MOP_BUF_PTR_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
