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
* file: cslr_pa_lut2.h
*
* Brief: This file contains the Register Description for pa_lut2
*
*********************************************************************/
#ifndef CSLR_PA_LUT2_H_
#define CSLR_PA_LUT2_H_

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
    volatile Uint32 CLR_TABLE; /* The Clear Table bit is written in order to clear the contents of the LUT. */
    volatile Uint8 RSVD0[8];
    volatile Uint32 MAX_ENTRY_COUNT; /* The Maximum Entry Count Register indicates the maximum depth of the table in entries. */
    volatile Uint32 CURR_ENTRY_COUNT; /* The Current Entry Count Register indicates the current number of entries in the table. */
    volatile Uint8 RSVD1[8];
    volatile Uint32 ADD_DATA[4]; /* The Add Data N Register is written in order to initialize word N of the 128-bit data value which is to be added to the table for the specified key. */
    volatile Uint32 ADD_DEL_KEY[2]; /* The Add/Delete Key N Register is written in order to initialize word N of the key value that will be associated with the added or deleted data entry. For a delete, this key will be used to locate the entry in the table which is to be deleted using the normal lookup process. */
    volatile Uint32 ADD_DEL_CTL; /* The Add/Delete control register is used to initiate an add or delete operation into the table. The add or delete operation will not begin until byte 3 of this register is written. */
    volatile Uint8 RSVD2[36];
    volatile Uint32 DEBUG_MODE; /* The Debug Mode register is used to place the LUT2 into a mode where add and delete operations will be stalled. */
    volatile Uint32 DEBUG_CTL; /* The Debug Control register is used to control the debug read operation. */
    volatile Uint32 DEBUG_READ_KEY[2]; /* The Debug Read Key N Register contains word N of the key for the entry which was read from the LUT2 internal table during the debug read operation. */
    volatile Uint32 DEBUG_READ_DATA[4]; /* The Debug Read Data N Register contains word N of the data for the entry which was read from the LUT2 internal table during the debug read operation. */
} CSL_Pa_lut2Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION */

#define CSL_PA_LUT2_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_PA_LUT2_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_LUT2_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_PA_LUT2_REVISION_MODID_MASK  (0x0FFF0000u)
#define CSL_PA_LUT2_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_PA_LUT2_REVISION_MODID_RESETVAL (0x00000E5Cu)

#define CSL_PA_LUT2_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_PA_LUT2_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_PA_LUT2_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_PA_LUT2_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_PA_LUT2_REVISION_REVMAJ_RESETVAL (0x00000002u)

#define CSL_PA_LUT2_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_PA_LUT2_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_PA_LUT2_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_PA_LUT2_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_PA_LUT2_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_REVISION_RESETVAL    (0x4E5C0200u)

/* CLR_TABLE */

#define CSL_PA_LUT2_CLR_TABLE_GO_MASK    (0x00000001u)
#define CSL_PA_LUT2_CLR_TABLE_GO_SHIFT   (0x00000000u)
#define CSL_PA_LUT2_CLR_TABLE_GO_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_CLR_TABLE_RESETVAL   (0x00000000u)

/* MAX_ENTRY_COUNT */

#define CSL_PA_LUT2_MAX_ENTRY_COUNT_VALUE_MASK (0x000FFFFFu)
#define CSL_PA_LUT2_MAX_ENTRY_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_MAX_ENTRY_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_MAX_ENTRY_COUNT_RESETVAL (0x00000000u)

/* CURR_ENTRY_COUNT */

#define CSL_PA_LUT2_CURR_ENTRY_COUNT_VALUE_MASK (0x000FFFFFu)
#define CSL_PA_LUT2_CURR_ENTRY_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_CURR_ENTRY_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_CURR_ENTRY_COUNT_RESETVAL (0x00000000u)

/* ADD_DATA */

#define CSL_PA_LUT2_ADD_DATA_VALUE_MASK  (0xFFFFFFFFu)
#define CSL_PA_LUT2_ADD_DATA_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_ADD_DATA_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_ADD_DATA_RESETVAL    (0x00000000u)

/* ADD_DEL_KEY */

#define CSL_PA_LUT2_ADD_DEL_KEY_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_LUT2_ADD_DEL_KEY_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_ADD_DEL_KEY_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_ADD_DEL_KEY_RESETVAL (0x00000000u)

/* ADD_DEL_CTL */

#define CSL_PA_LUT2_ADD_DEL_CTL_GO_MASK  (0x80000000u)
#define CSL_PA_LUT2_ADD_DEL_CTL_GO_SHIFT (0x0000001Fu)
#define CSL_PA_LUT2_ADD_DEL_CTL_GO_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_ADD_DEL_CTL_OP_MASK  (0x40000000u)
#define CSL_PA_LUT2_ADD_DEL_CTL_OP_SHIFT (0x0000001Eu)
#define CSL_PA_LUT2_ADD_DEL_CTL_OP_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_ADD_DEL_CTL_RESETVAL (0x00000000u)

/* DEBUG_MODE */

#define CSL_PA_LUT2_DEBUG_MODE_HALT_OPS_MASK (0x80000000u)
#define CSL_PA_LUT2_DEBUG_MODE_HALT_OPS_SHIFT (0x0000001Fu)
#define CSL_PA_LUT2_DEBUG_MODE_HALT_OPS_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_DEBUG_MODE_RESETVAL  (0x00000000u)

/* DEBUG_CTL */

#define CSL_PA_LUT2_DEBUG_CTL_GO_MASK    (0x80000000u)
#define CSL_PA_LUT2_DEBUG_CTL_GO_SHIFT   (0x0000001Fu)
#define CSL_PA_LUT2_DEBUG_CTL_GO_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_DEBUG_CTL_ENTRY_MASK (0x0000FFFFu)
#define CSL_PA_LUT2_DEBUG_CTL_ENTRY_SHIFT (0x00000000u)
#define CSL_PA_LUT2_DEBUG_CTL_ENTRY_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_DEBUG_CTL_RESETVAL   (0x00000000u)

/* DEBUG_READ_KEY */

#define CSL_PA_LUT2_DEBUG_READ_KEY_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_LUT2_DEBUG_READ_KEY_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_DEBUG_READ_KEY_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_DEBUG_READ_KEY_RESETVAL (0x00000000u)

/* DEBUG_READ_DATA */

#define CSL_PA_LUT2_DEBUG_READ_DATA_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_LUT2_DEBUG_READ_DATA_VALUE_SHIFT (0x00000000u)
#define CSL_PA_LUT2_DEBUG_READ_DATA_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_LUT2_DEBUG_READ_DATA_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
