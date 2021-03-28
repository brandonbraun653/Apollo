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
#ifndef CSLR_DESHDCP_H_
#define CSLR_DESHDCP_H_

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
    volatile Uint8  RSVD0[32];
    volatile Uint32 CTRL;
    volatile Uint32 DATA_L;
    volatile Uint32 DATA_H;
    volatile Uint32 REV;
    volatile Uint32 MASK;
    volatile Uint32 SYSSTS;
    volatile Uint8  RSVD1[8];
    volatile Uint32 MEM[80];
} CSL_DesHdcpRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* deshdcp Control register. */
#define CSL_DESHDCP_CTRL                                        (0x20U)

/* deshdcp data register to read/write encrypted/decrypted data. When
 * decryption, reading this registers returns 0. */
#define CSL_DESHDCP_DATA_L                                      (0x24U)

/* deshdcp data register to read/write encrypted/decrypted data. When
 * decryption, reading this registers returns 0. */
#define CSL_DESHDCP_DATA_H                                      (0x28U)

/* deshdcp Revision number register */
#define CSL_DESHDCP_REV                                         (0x2CU)

/* deshdcp Mask register. */
#define CSL_DESHDCP_MASK                                        (0x30U)

/* deshdcp System status register */
#define CSL_DESHDCP_SYSSTS                                      (0x34U)

/* deshdcp registers to hold the data decrypted or any data written through
 * host interface. */
#define CSL_DESHDCP_MEM(i)                                      (0x40U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

#define CSL_DESHDCP_RESERVED_RESETVAL                           (0x00000000U)

/* CTRL */

#define CSL_DESHDCP_CTRL_DIRECTION_MASK                         (0x00000004U)
#define CSL_DESHDCP_CTRL_DIRECTION_SHIFT                        (2U)
#define CSL_DESHDCP_CTRL_DIRECTION_RESETVAL                     (0x00000000U)
#define CSL_DESHDCP_CTRL_DIRECTION_DEC                          (0x00000000U)
#define CSL_DESHDCP_CTRL_DIRECTION_ENC                          (0x00000001U)

#define CSL_DESHDCP_CTRL_INPUT_READY_MASK                       (0x00000002U)
#define CSL_DESHDCP_CTRL_INPUT_READY_SHIFT                      (1U)
#define CSL_DESHDCP_CTRL_INPUT_READY_RESETVAL                   (0x00000001U)
#define CSL_DESHDCP_CTRL_INPUT_READY_INPUTREADY                 (0x00000001U)
#define CSL_DESHDCP_CTRL_INPUT_READY_NOINPUTREADY               (0x00000000U)

#define CSL_DESHDCP_CTRL_OUTPUT_READY_MASK                      (0x00000001U)
#define CSL_DESHDCP_CTRL_OUTPUT_READY_SHIFT                     (0U)
#define CSL_DESHDCP_CTRL_OUTPUT_READY_RESETVAL                  (0x00000000U)
#define CSL_DESHDCP_CTRL_OUTPUT_READY_OUTPUTREADY               (0x00000001U)
#define CSL_DESHDCP_CTRL_OUTPUT_READY_NOUTOUTREADY              (0x00000000U)

#define CSL_DESHDCP_CTRL_RESETVAL                               (0x00000002U)

/* DATA_L */

#define CSL_DESHDCP_DATA_L_DHDCP_DATA_L_MASK                    (0xFFFFFFFFU)
#define CSL_DESHDCP_DATA_L_DHDCP_DATA_L_SHIFT                   (0U)
#define CSL_DESHDCP_DATA_L_DHDCP_DATA_L_RESETVAL                (0x00000000U)
#define CSL_DESHDCP_DATA_L_DHDCP_DATA_L_MAX                     (0xffffffffU)

#define CSL_DESHDCP_DATA_L_RESETVAL                             (0x00000000U)

/* DATA_H */

#define CSL_DESHDCP_DATA_H_DHDCP_DATA_H_MASK                    (0xFFFFFFFFU)
#define CSL_DESHDCP_DATA_H_DHDCP_DATA_H_SHIFT                   (0U)
#define CSL_DESHDCP_DATA_H_DHDCP_DATA_H_RESETVAL                (0x00000000U)
#define CSL_DESHDCP_DATA_H_DHDCP_DATA_H_MAX                     (0xffffffffU)

#define CSL_DESHDCP_DATA_H_RESETVAL                             (0x00000000U)

/* REV */

#define CSL_DESHDCP_REV_REV_NB_MASK                             (0x000000FFU)
#define CSL_DESHDCP_REV_REV_NB_SHIFT                            (0U)
#define CSL_DESHDCP_REV_REV_NB_RESETVAL                         (0x00000001U)
#define CSL_DESHDCP_REV_REV_NB_MAX                              (0x000000ffU)

#define CSL_DESHDCP_REV_RESETVAL                                (0x00000001U)

/* MASK */

#define CSL_DESHDCP_MASK_AUTOIDLE_MASK                          (0x00000001U)
#define CSL_DESHDCP_MASK_AUTOIDLE_SHIFT                         (0U)
#define CSL_DESHDCP_MASK_AUTOIDLE_RESETVAL                      (0x00000001U)
#define CSL_DESHDCP_MASK_AUTOIDLE_AUTOIDE                       (0x00000001U)
#define CSL_DESHDCP_MASK_AUTOIDLE_NOAUTOIDLE                    (0x00000000U)

#define CSL_DESHDCP_MASK_SOFTRESET_MASK                         (0x00000002U)
#define CSL_DESHDCP_MASK_SOFTRESET_SHIFT                        (1U)
#define CSL_DESHDCP_MASK_SOFTRESET_RESETVAL                     (0x00000000U)
#define CSL_DESHDCP_MASK_SOFTRESET_NOSOFTRESET                  (0x00000000U)
#define CSL_DESHDCP_MASK_SOFTRESET_SOFTRESET                    (0x00000001U)

#define CSL_DESHDCP_MASK_SIDLE_MASK                             (0x000000C0U)
#define CSL_DESHDCP_MASK_SIDLE_SHIFT                            (6U)
#define CSL_DESHDCP_MASK_SIDLE_RESETVAL                         (0x00000000U)
#define CSL_DESHDCP_MASK_SIDLE_NOIDLE                           (0x00000001U)
#define CSL_DESHDCP_MASK_SIDLE_RESERVED                         (0x00000003U)
#define CSL_DESHDCP_MASK_SIDLE_FORCEIDLE                        (0x00000000U)
#define CSL_DESHDCP_MASK_SIDLE_SMARTIDLE                        (0x00000002U)

#define CSL_DESHDCP_MASK_RESETVAL                               (0x00000001U)

/* SYSSTS */

#define CSL_DESHDCP_SYSSTS_RESETDONE_MASK                       (0x00000001U)
#define CSL_DESHDCP_SYSSTS_RESETDONE_SHIFT                      (0U)
#define CSL_DESHDCP_SYSSTS_RESETDONE_RESETVAL                   (0x00000001U)
#define CSL_DESHDCP_SYSSTS_RESETDONE_MAX                        (0x00000001U)

#define CSL_DESHDCP_SYSSTS_RESETVAL                             (0x00000001U)

#define CSL_DESHDCP_RESERVED1_RESETVAL                          (0x00000000U)

/* MEM */

#define CSL_DESHDCP_MEM_DATA_MASK                               (0xFFFFFFFFU)
#define CSL_DESHDCP_MEM_DATA_SHIFT                              (0U)
#define CSL_DESHDCP_MEM_DATA_RESETVAL                           (0x00000000U)
#define CSL_DESHDCP_MEM_DATA_MAX                                (0xffffffffU)

#define CSL_DESHDCP_MEM_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
