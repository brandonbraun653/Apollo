/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_FUSEFARM_H
#define CSLR_FUSEFARM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for FusefarmRegisters
**************************************************************************/
typedef struct {
    volatile Uint32 SCFG_SYSSTATUS;
    volatile Uint32 OCP_LOWER;
    volatile Uint32 OCP_UPPER;
    volatile Uint8  RSVD0[4];
    volatile Uint32 SYS_CONFIG;
    volatile Uint8  RSVD1[1004];
} CSL_FusefarmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the lower 32-bits of contents to be written to a
 * efuse controller register. */
#define CSL_FUSEFARM_OCP_LOWER                                  (0x4U)

/* This register contains the 6-bit register address and the upper 4-bits of
 * the contents to be written to a efuse controller register */
#define CSL_FUSEFARM_OCP_UPPER                                  (0x8U)

/* Returns 0 always */
#define CSL_FUSEFARM_SCFG_SYSSTATUS                             (0x0U)

/* SYS_CONFIG */
#define CSL_FUSEFARM_SYS_CONFIG                                 (0x10U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* OCP_LOWER */

#define CSL_FUSEFARM_OCP_LOWER_LOWER_32_BIT_CONTENT_MASK        (0xFFFFFFFFU)
#define CSL_FUSEFARM_OCP_LOWER_LOWER_32_BIT_CONTENT_SHIFT       (0U)
#define CSL_FUSEFARM_OCP_LOWER_LOWER_32_BIT_CONTENT_RESETVAL    (0x00000000U)
#define CSL_FUSEFARM_OCP_LOWER_LOWER_32_BIT_CONTENT_MAX         (0xffffffffU)

#define CSL_FUSEFARM_OCP_LOWER_RESETVAL                         (0x00000000U)

/* OCP_UPPER */

#define CSL_FUSEFARM_OCP_UPPER_UPPER_4_BIT_CONTENT_MASK         (0x0000000FU)
#define CSL_FUSEFARM_OCP_UPPER_UPPER_4_BIT_CONTENT_SHIFT        (0U)
#define CSL_FUSEFARM_OCP_UPPER_UPPER_4_BIT_CONTENT_RESETVAL     (0x00000000U)
#define CSL_FUSEFARM_OCP_UPPER_UPPER_4_BIT_CONTENT_MAX          (0x0000000fU)

#define CSL_FUSEFARM_OCP_UPPER_ADDRESS_MASK                     (0x000003F0U)
#define CSL_FUSEFARM_OCP_UPPER_ADDRESS_SHIFT                    (4U)
#define CSL_FUSEFARM_OCP_UPPER_ADDRESS_RESETVAL                 (0x00000000U)
#define CSL_FUSEFARM_OCP_UPPER_ADDRESS_MAX                      (0x0000003fU)

#define CSL_FUSEFARM_OCP_UPPER_RESETVAL                         (0x00000000U)

/* SCFG_SYSSTATUS */

#define CSL_FUSEFARM_SCFG_SYSSTATUS_IMPLEMENTATION_MASK         (0xFFFFFFFFU)
#define CSL_FUSEFARM_SCFG_SYSSTATUS_IMPLEMENTATION_SHIFT        (0U)
#define CSL_FUSEFARM_SCFG_SYSSTATUS_IMPLEMENTATION_RESETVAL     (0x00000000U)
#define CSL_FUSEFARM_SCFG_SYSSTATUS_IMPLEMENTATION_MAX          (0xffffffffU)

#define CSL_FUSEFARM_SCFG_SYSSTATUS_RESETVAL                    (0x00000000U)

/* SYS_CONFIG */

#define CSL_FUSEFARM_SYS_CONFIG_IDLEMODE_CFG_MASK               (0x0000000CU)
#define CSL_FUSEFARM_SYS_CONFIG_IDLEMODE_CFG_SHIFT              (2U)
#define CSL_FUSEFARM_SYS_CONFIG_IDLEMODE_CFG_RESETVAL           (0x00000000U)
#define CSL_FUSEFARM_SYS_CONFIG_IDLEMODE_CFG_MAX                (0x00000003U)

#define CSL_FUSEFARM_SYS_CONFIG_RESETVAL                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
