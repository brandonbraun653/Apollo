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
* file: cslr_ra_lut1_cfg.h
*
* Brief: This file contains the Register Description for ra_lut1_cfg
*
*********************************************************************/
#ifndef CSLR_RA_LUT1_CFG_H_
#define CSLR_RA_LUT1_CFG_H_

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
    volatile Uint32 CONTROL; /* The Control Register contains the controls for the module. */
    volatile Uint32 CONFIG; /* The Config Register contains the configuration parameter values for the module. The reset values are configuration dependent. */
    volatile Uint32 DEBUG_CONTROL; /* The Debug Control Register contains the debug access control for the module. */
} CSL_Ra_lut1_cfgRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION */

#define CSL_RA_LUT1_CFG_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_RA_LUT1_CFG_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_RA_LUT1_CFG_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_RA_LUT1_CFG_REVISION_MODID_MASK (0x0FFF0000u)
#define CSL_RA_LUT1_CFG_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_RA_LUT1_CFG_REVISION_MODID_RESETVAL (0x00000EF8u)

#define CSL_RA_LUT1_CFG_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_RA_LUT1_CFG_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_RA_LUT1_CFG_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_RA_LUT1_CFG_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_RA_LUT1_CFG_REVISION_REVMAJ_RESETVAL (0x00000001u)

#define CSL_RA_LUT1_CFG_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_RA_LUT1_CFG_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_RA_LUT1_CFG_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_RA_LUT1_CFG_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_RA_LUT1_CFG_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_REVISION_RESETVAL (0x4EF80100u)

/* CONTROL */

#define CSL_RA_LUT1_CFG_CONTROL_CLR_TABLE_MASK (0x80000000u)
#define CSL_RA_LUT1_CFG_CONTROL_CLR_TABLE_SHIFT (0x0000001Fu)
#define CSL_RA_LUT1_CFG_CONTROL_CLR_TABLE_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_CONTROL_RESETVAL (0x00000000u)

/* CONFIG */

#define CSL_RA_LUT1_CFG_CONFIG_NUM_TOTAL_BYTES_MASK (0xFF000000u)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_TOTAL_BYTES_SHIFT (0x00000018u)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_TOTAL_BYTES_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_CONFIG_NUM_KEY_BYTES_MASK (0x00FF0000u)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_KEY_BYTES_SHIFT (0x00000010u)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_KEY_BYTES_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_CONFIG_NUM_ENTRIES_MASK (0x0000FFFFu)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_ENTRIES_SHIFT (0x00000000u)
#define CSL_RA_LUT1_CFG_CONFIG_NUM_ENTRIES_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_CONFIG_RESETVAL  (0x00000000u)

/* DEBUG_CONTROL */

#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_FORCE_MASK (0x80000000u)
#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_FORCE_SHIFT (0x0000001Fu)
#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_FORCE_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_CNT_MASK (0x0000FFFFu)
#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_CNT_SHIFT (0x00000000u)
#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_CFG_CNT_RESETVAL (0x00000000u)

#define CSL_RA_LUT1_CFG_DEBUG_CONTROL_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
