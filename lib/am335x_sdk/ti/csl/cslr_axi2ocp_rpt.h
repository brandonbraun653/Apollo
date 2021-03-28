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
#ifndef CSLR_AXI2OCPRPT_H_
#define CSLR_AXI2OCPRPT_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 RPT_ENABLE;
    volatile Uint32 RPT_STATUS;
    volatile Uint32 RPT_OPCODE16;
    volatile Uint32 RPT_OPCODE32;
    volatile Uint32 RPT_OPCODE_CTRL;
    volatile Uint32 RPT_ADDRESS[16];
} CSL_Axi2ocpRptRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Enable for Rom Patch Only secure-previleged access are allowed This
 * register can be written only one after reset (Write-Once) */
#define CSL_AXI2OCPRPT_RPT_ENABLE                               (0x0U)

/* Rom patch Address hit Status register Only secure-previleged read are
 * allowed */
#define CSL_AXI2OCPRPT_RPT_STATUS                               (0x4U)

/* OPCODE16 register to hold Thumb mode Instruction Only secure-previleged
 * access are allowed This register can be written only one after reset
 * (Write-Once) */
#define CSL_AXI2OCPRPT_RPT_OPCODE16                             (0x8U)

/* OPCODE32 register to hold ARM mode Instruction Only secure-previleged
 * access are allowed This register can be written only one after reset
 * (Write-Once) */
#define CSL_AXI2OCPRPT_RPT_OPCODE32                             (0xCU)

/* OPCODE CTRL Register Only secure-previleged access are allowed This
 * register can be written only one after reset (Write-Once) */
#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL                          (0x10U)

/* Rom patch Address Register Only secure-previleged access are allowed This
 * register can be written only one after reset (Write-Once) */
#define CSL_AXI2OCPRPT_RPT_ADDRESS(i)                           (0x14U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* RPT_ENABLE */

#define CSL_AXI2OCPRPT_RPT_ENABLE_RPT_ENABLE_MASK               (0x0000FFFFU)
#define CSL_AXI2OCPRPT_RPT_ENABLE_RPT_ENABLE_SHIFT              (0U)
#define CSL_AXI2OCPRPT_RPT_ENABLE_RPT_ENABLE_RESETVAL           (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_ENABLE_RPT_ENABLE_MAX                (0x0000ffffU)

#define CSL_AXI2OCPRPT_RPT_ENABLE_RESETVAL                      (0x00000000U)

/* RPT_STATUS */

#define CSL_AXI2OCPRPT_RPT_STATUS_RPT_STATUS_MASK               (0x0000FFFFU)
#define CSL_AXI2OCPRPT_RPT_STATUS_RPT_STATUS_SHIFT              (0U)
#define CSL_AXI2OCPRPT_RPT_STATUS_RPT_STATUS_RESETVAL           (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_STATUS_RPT_STATUS_MAX                (0x0000ffffU)

#define CSL_AXI2OCPRPT_RPT_STATUS_RESETVAL                      (0x00000000U)

/* RPT_OPCODE16 */

#define CSL_AXI2OCPRPT_RPT_OPCODE16_RPT_OPCODE_16_MASK          (0xFFFFFFFFU)
#define CSL_AXI2OCPRPT_RPT_OPCODE16_RPT_OPCODE_16_SHIFT         (0U)
#define CSL_AXI2OCPRPT_RPT_OPCODE16_RPT_OPCODE_16_RESETVAL      (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_OPCODE16_RPT_OPCODE_16_MAX           (0xffffffffU)

#define CSL_AXI2OCPRPT_RPT_OPCODE16_RESETVAL                    (0x00000000U)

/* RPT_OPCODE32 */

#define CSL_AXI2OCPRPT_RPT_OPCODE32_RPT_OPCODE32_MASK           (0xFFFFFFFFU)
#define CSL_AXI2OCPRPT_RPT_OPCODE32_RPT_OPCODE32_SHIFT          (0U)
#define CSL_AXI2OCPRPT_RPT_OPCODE32_RPT_OPCODE32_RESETVAL       (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_OPCODE32_RPT_OPCODE32_MAX            (0xffffffffU)

#define CSL_AXI2OCPRPT_RPT_OPCODE32_RESETVAL                    (0x00000000U)

/* RPT_OPCODE_CTRL */

#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL_RPT_OPCODE_CTRL_MASK     (0x0000FFFFU)
#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL_RPT_OPCODE_CTRL_SHIFT    (0U)
#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL_RPT_OPCODE_CTRL_RESETVAL  (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL_RPT_OPCODE_CTRL_MAX      (0x0000ffffU)

#define CSL_AXI2OCPRPT_RPT_OPCODE_CTRL_RESETVAL                 (0x00000000U)

/* RPT_ADDRESS */

#define CSL_AXI2OCPRPT_RPT_ADDRESS_ADDRESS_MASK                 (0xFFFFFFFFU)
#define CSL_AXI2OCPRPT_RPT_ADDRESS_ADDRESS_SHIFT                (0U)
#define CSL_AXI2OCPRPT_RPT_ADDRESS_ADDRESS_RESETVAL             (0x00000000U)
#define CSL_AXI2OCPRPT_RPT_ADDRESS_ADDRESS_MAX                  (0xffffffffU)

#define CSL_AXI2OCPRPT_RPT_ADDRESS_RESETVAL                     (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
