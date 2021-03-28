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
* file: cslr_pa_lut1.h
*
* Brief: This file contains the Register Description for pa_lut1
*
*********************************************************************/
#ifndef CSLR_PA_LUT1_H_
#define CSLR_PA_LUT1_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for DEBUG_ENTRY_DATA
\**************************************************************************/
typedef struct  {
    volatile Uint32 ENTRY_BYTES[12]; /* Register N contains bytes N*4 to N*4+3. */
    volatile Uint32 BITMASK_SCORE; /* The Debug Entry Data Bitmask and Score Register contains the bitmask and score values. */
    volatile Uint32 CARE0; /* The Debug Entry Data Care Field Word 0 Register contains the Care Field Word 0 value. */
    volatile Uint32 CARE1; /* The Debug Entry Data Care Field Word 1 Register contains the Care Field Word 1 value. */
    volatile Uint32 RANGE_HIGH; /* The Debug Entry Data Range High Register contains the range high values. */
} CSL_Pa_lut1Debug_entry_dataRegs; /* The Debug Entry Data Registers contain the full data for an entry in the table. It is updated only after the Debug Control Register is written with the Read bit set. */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION; /* The Revision Register contains the ID and revision information. */
    volatile Uint32 CONTROL; /* The Control Register contains the controls for the module. */
    volatile Uint32 CONFIG; /* The Config Register contains the configuration parameter values for the module. The reset values are configuration dependent. */
    volatile Uint8 RSVD0[4];
    volatile Uint32 DEBUG_CONTROL; /* The Debug Control Register contains the controls for a debug access of the table. This register must be written before a debug read of the entry selected will occur. */
    volatile Uint8 RSVD1[44];
    CSL_Pa_lut1Debug_entry_dataRegs DEBUG_ENTRY_DATA;
    volatile Uint8 RSVD2[68];
    volatile Uint32 HASK_KEY[10]; /* The Hash Key Registers contain the key bytes for the RSS hash operation. The bytes are packed into the key left most first, so the leftmost word is Register 0 and the rightmost word is Register 9. */
} CSL_Pa_lut1Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ENTRY_BYTES */

#define CSL_PA_LUT1_ENTRY_BYTES_BYTE0_MASK (0xFF000000u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE0_SHIFT (0x00000018u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE0_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_ENTRY_BYTES_BYTE1_MASK (0x00FF0000u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE1_SHIFT (0x00000010u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE1_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_ENTRY_BYTES_BYTE2_MASK (0x0000FF00u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE2_SHIFT (0x00000008u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE2_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_ENTRY_BYTES_BYTE3_MASK (0x000000FFu)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE3_SHIFT (0x00000000u)
#define CSL_PA_LUT1_ENTRY_BYTES_BYTE3_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_ENTRY_BYTES_RESETVAL (0x00000000u)

/* BITMASK_SCORE */

#define CSL_PA_LUT1_BITMASK_SCORE_SCORE_MASK (0xFFFF0000u)
#define CSL_PA_LUT1_BITMASK_SCORE_SCORE_SHIFT (0x00000010u)
#define CSL_PA_LUT1_BITMASK_SCORE_SCORE_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_BITMASK_SCORE_BITMASK_MASK (0x0000FFFFu)
#define CSL_PA_LUT1_BITMASK_SCORE_BITMASK_SHIFT (0x00000000u)
#define CSL_PA_LUT1_BITMASK_SCORE_BITMASK_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_BITMASK_SCORE_RESETVAL (0x00000000u)

/* CARE0 */

#define CSL_PA_LUT1_CARE0_CARE0_MASK     (0xFFFFFFFFu)
#define CSL_PA_LUT1_CARE0_CARE0_SHIFT    (0x00000000u)
#define CSL_PA_LUT1_CARE0_CARE0_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CARE0_RESETVAL       (0x00000000u)

/* CARE1 */

#define CSL_PA_LUT1_CARE1_CARE1_MASK     (0xFFFFFFFFu)
#define CSL_PA_LUT1_CARE1_CARE1_SHIFT    (0x00000000u)
#define CSL_PA_LUT1_CARE1_CARE1_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CARE1_RESETVAL       (0x00000000u)

/* RANGE_HIGH */

#define CSL_PA_LUT1_RANGE_HIGH_RANGE1_MASK (0xFF000000u)
#define CSL_PA_LUT1_RANGE_HIGH_RANGE1_SHIFT (0x00000018u)
#define CSL_PA_LUT1_RANGE_HIGH_RANGE1_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_RANGE_HIGH_RANGE0_MASK (0x0000FFFFu)
#define CSL_PA_LUT1_RANGE_HIGH_RANGE0_SHIFT (0x00000000u)
#define CSL_PA_LUT1_RANGE_HIGH_RANGE0_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_RANGE_HIGH_RESETVAL  (0x00000000u)

/* REVISION */

#define CSL_PA_LUT1_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_PA_LUT1_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_LUT1_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_PA_LUT1_REVISION_MODID_MASK  (0x0FFF0000u)
#define CSL_PA_LUT1_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_PA_LUT1_REVISION_MODID_RESETVAL (0x00000EF4u)

#define CSL_PA_LUT1_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_PA_LUT1_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_PA_LUT1_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_PA_LUT1_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_PA_LUT1_REVISION_REVMAJ_RESETVAL (0x00000001u)

#define CSL_PA_LUT1_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_PA_LUT1_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_PA_LUT1_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_PA_LUT1_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_PA_LUT1_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_REVISION_RESETVAL    (0x4EF40100u)

/* CONTROL */

#define CSL_PA_LUT1_CONTROL_CLR_TABLE_MASK (0x80000000u)
#define CSL_PA_LUT1_CONTROL_CLR_TABLE_SHIFT (0x0000001Fu)
#define CSL_PA_LUT1_CONTROL_CLR_TABLE_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CONTROL_RESETVAL     (0x00000000u)

/* CONFIG */

#define CSL_PA_LUT1_CONFIG_NUM_TOTAL_BYTES_MASK (0xFF000000u)
#define CSL_PA_LUT1_CONFIG_NUM_TOTAL_BYTES_SHIFT (0x00000018u)
#define CSL_PA_LUT1_CONFIG_NUM_TOTAL_BYTES_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CONFIG_NUM_KEY_BYTES_MASK (0x00FF0000u)
#define CSL_PA_LUT1_CONFIG_NUM_KEY_BYTES_SHIFT (0x00000010u)
#define CSL_PA_LUT1_CONFIG_NUM_KEY_BYTES_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CONFIG_NUM_ENTRIES_MASK (0x0000FFFFu)
#define CSL_PA_LUT1_CONFIG_NUM_ENTRIES_SHIFT (0x00000000u)
#define CSL_PA_LUT1_CONFIG_NUM_ENTRIES_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_CONFIG_RESETVAL      (0x00000000u)

/* DEBUG_CONTROL */

#define CSL_PA_LUT1_DEBUG_CONTROL_READ_MASK (0x80000000u)
#define CSL_PA_LUT1_DEBUG_CONTROL_READ_SHIFT (0x0000001Fu)
#define CSL_PA_LUT1_DEBUG_CONTROL_READ_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_DEBUG_CONTROL_ENTRY_MASK (0x0000FFFFu)
#define CSL_PA_LUT1_DEBUG_CONTROL_ENTRY_SHIFT (0x00000000u)
#define CSL_PA_LUT1_DEBUG_CONTROL_ENTRY_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_DEBUG_CONTROL_RESETVAL (0x00000000u)

/* HASK_KEY */

#define CSL_PA_LUT1_HASK_KEY_KEYN_MASK   (0xFFFFFFFFu)
#define CSL_PA_LUT1_HASK_KEY_KEYN_SHIFT  (0x00000000u)
#define CSL_PA_LUT1_HASK_KEY_KEYN_RESETVAL (0x00000000u)

#define CSL_PA_LUT1_HASK_KEY_RESETVAL    (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
