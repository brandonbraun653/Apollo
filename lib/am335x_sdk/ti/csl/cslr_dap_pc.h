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
#ifndef CSLR_DAPPC_H_
#define CSLR_DAPPC_H_

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
    volatile Uint32 CAPABILITIES;
    volatile Uint32 CTRL_REG_0;
    volatile Uint32 REVISION;
    volatile Uint32 CTRL_REG_1;
} CSL_DapPcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* CAPABILITIES */
#define CSL_DAPPC_CAPABILITIES                                  (0x0U)

/* Control reg 1/2 */
#define CSL_DAPPC_CTRL_REG_0                                    (0x4U)

/* Revision register */
#define CSL_DAPPC_REVISION                                      (0x8U)

/* Control reg 1/2 */
#define CSL_DAPPC_CTRL_REG_1                                    (0xCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CAPABILITIES */

#define CSL_DAPPC_CAPABILITIES_NUM_DBG_CORES_MASK               (0x0000000FU)
#define CSL_DAPPC_CAPABILITIES_NUM_DBG_CORES_SHIFT              (0U)
#define CSL_DAPPC_CAPABILITIES_NUM_DBG_CORES_RESETVAL           (0x00000001U)
#define CSL_DAPPC_CAPABILITIES_NUM_DBG_CORES_MAX                (0x0000000fU)

#define CSL_DAPPC_CAPABILITIES_RESETVAL                         (0x00000001U)

/* CTRL_REG_0 */

#define CSL_DAPPC_CTRL_REG_0_COREPRESENT_MASK                   (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_COREPRESENT_SHIFT                  (0U)
#define CSL_DAPPC_CTRL_REG_0_COREPRESENT_RESETVAL               (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_COREPRESENT_MAX                    (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_COREACCESSIBLE_MASK                (0x00000002U)
#define CSL_DAPPC_CTRL_REG_0_COREACCESSIBLE_SHIFT               (1U)
#define CSL_DAPPC_CTRL_REG_0_COREACCESSIBLE_RESETVAL            (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_COREACCESSIBLE_MAX                 (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_CLOCK_MASK                         (0x00000004U)
#define CSL_DAPPC_CTRL_REG_0_CLOCK_SHIFT                        (2U)
#define CSL_DAPPC_CTRL_REG_0_CLOCK_RESETVAL                     (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_CLOCK_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_FORCEACTIVE_MASK                   (0x00000008U)
#define CSL_DAPPC_CTRL_REG_0_FORCEACTIVE_SHIFT                  (3U)
#define CSL_DAPPC_CTRL_REG_0_FORCEACTIVE_RESETVAL               (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_FORCEACTIVE_MAX                    (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_CLOCKDOWNDESIRED_MASK              (0x00000010U)
#define CSL_DAPPC_CTRL_REG_0_CLOCKDOWNDESIRED_SHIFT             (4U)
#define CSL_DAPPC_CTRL_REG_0_CLOCKDOWNDESIRED_RESETVAL          (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_CLOCKDOWNDESIRED_MAX               (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_POWER_MASK                         (0x00000020U)
#define CSL_DAPPC_CTRL_REG_0_POWER_SHIFT                        (5U)
#define CSL_DAPPC_CTRL_REG_0_POWER_RESETVAL                     (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_POWER_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_POWERDOWNDESIRED_MASK              (0x00000080U)
#define CSL_DAPPC_CTRL_REG_0_POWERDOWNDESIRED_SHIFT             (7U)
#define CSL_DAPPC_CTRL_REG_0_POWERDOWNDESIRED_RESETVAL          (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_POWERDOWNDESIRED_MAX               (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_DBGATTENTION_MASK                  (0x00000400U)
#define CSL_DAPPC_CTRL_REG_0_DBGATTENTION_SHIFT                 (10U)
#define CSL_DAPPC_CTRL_REG_0_DBGATTENTION_RESETVAL              (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_DBGATTENTION_MAX                   (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_DBGMODE_MASK                       (0x00001800U)
#define CSL_DAPPC_CTRL_REG_0_DBGMODE_SHIFT                      (11U)
#define CSL_DAPPC_CTRL_REG_0_DBGMODE_RESETVAL                   (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_DBGMODE_MAX                        (0x00000003U)

#define CSL_DAPPC_CTRL_REG_0_DBGEN_MASK                         (0x00002000U)
#define CSL_DAPPC_CTRL_REG_0_DBGEN_SHIFT                        (13U)
#define CSL_DAPPC_CTRL_REG_0_DBGEN_RESETVAL                     (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_DBGEN_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_RESETCTRL_MASK                     (0x0001C000U)
#define CSL_DAPPC_CTRL_REG_0_RESETCTRL_SHIFT                    (14U)
#define CSL_DAPPC_CTRL_REG_0_RESETCTRL_RESETVAL                 (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_RESETCTRL_MAX                      (0x00000007U)

#define CSL_DAPPC_CTRL_REG_0_INRESET_MASK                       (0x00020000U)
#define CSL_DAPPC_CTRL_REG_0_INRESET_SHIFT                      (17U)
#define CSL_DAPPC_CTRL_REG_0_INRESET_RESETVAL                   (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_INRESET_MAX                        (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_UNNATURALRESET_MASK                (0x00040000U)
#define CSL_DAPPC_CTRL_REG_0_UNNATURALRESET_SHIFT               (18U)
#define CSL_DAPPC_CTRL_REG_0_UNNATURALRESET_RESETVAL            (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_UNNATURALRESET_MAX                 (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_COREPOWER_MASK                     (0x00080000U)
#define CSL_DAPPC_CTRL_REG_0_COREPOWER_SHIFT                    (19U)
#define CSL_DAPPC_CTRL_REG_0_COREPOWER_RESETVAL                 (0x00000001U)
#define CSL_DAPPC_CTRL_REG_0_COREPOWER_MAX                      (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_INHIBITSLEEP_MASK                  (0x00100000U)
#define CSL_DAPPC_CTRL_REG_0_INHIBITSLEEP_SHIFT                 (20U)
#define CSL_DAPPC_CTRL_REG_0_INHIBITSLEEP_RESETVAL              (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_INHIBITSLEEP_MAX                   (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_POWERLOSSDETECTED_MASK             (0x00200000U)
#define CSL_DAPPC_CTRL_REG_0_POWERLOSSDETECTED_SHIFT            (21U)
#define CSL_DAPPC_CTRL_REG_0_POWERLOSSDETECTED_RESETVAL         (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_POWERLOSSDETECTED_MAX              (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_RESETOCCURRED_MASK                 (0x00400000U)
#define CSL_DAPPC_CTRL_REG_0_RESETOCCURRED_SHIFT                (22U)
#define CSL_DAPPC_CTRL_REG_0_RESETOCCURRED_RESETVAL             (0x00000000U)
#define CSL_DAPPC_CTRL_REG_0_RESETOCCURRED_MAX                  (0x00000001U)

#define CSL_DAPPC_CTRL_REG_0_RESETVAL                           (0x00080027U)

/* REVISION */

#define CSL_DAPPC_REVISION_Y_MINOR_MASK                         (0x0000003FU)
#define CSL_DAPPC_REVISION_Y_MINOR_SHIFT                        (0U)
#define CSL_DAPPC_REVISION_Y_MINOR_RESETVAL                     (0x00000000U)
#define CSL_DAPPC_REVISION_Y_MINOR_MAX                          (0x0000003fU)

#define CSL_DAPPC_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_DAPPC_REVISION_CUSTOM_SHIFT                         (6U)
#define CSL_DAPPC_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_DAPPC_REVISION_CUSTOM_MAX                           (0x00000003U)

#define CSL_DAPPC_REVISION_X_MAJOR_MASK                         (0x00000700U)
#define CSL_DAPPC_REVISION_X_MAJOR_SHIFT                        (8U)
#define CSL_DAPPC_REVISION_X_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_DAPPC_REVISION_X_MAJOR_MAX                          (0x00000007U)

#define CSL_DAPPC_REVISION_R_RTL_MASK                           (0x0000F800U)
#define CSL_DAPPC_REVISION_R_RTL_SHIFT                          (11U)
#define CSL_DAPPC_REVISION_R_RTL_RESETVAL                       (0x00000000U)
#define CSL_DAPPC_REVISION_R_RTL_MAX                            (0x0000001fU)

#define CSL_DAPPC_REVISION_FUNC_MASK                            (0x0FFF0000U)
#define CSL_DAPPC_REVISION_FUNC_SHIFT                           (16U)
#define CSL_DAPPC_REVISION_FUNC_RESETVAL                        (0x00000009U)
#define CSL_DAPPC_REVISION_FUNC_MAX                             (0x00000fffU)

#define CSL_DAPPC_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_DAPPC_REVISION_SCHEME_SHIFT                         (30U)
#define CSL_DAPPC_REVISION_SCHEME_RESETVAL                      (0x00000001U)
#define CSL_DAPPC_REVISION_SCHEME_MAX                           (0x00000003U)

#define CSL_DAPPC_REVISION_RESETVAL                             (0x50090000U)

/* CTRL_REG_1 */

#define CSL_DAPPC_CTRL_REG_1_COREPRESENT_MASK                   (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_COREPRESENT_SHIFT                  (0U)
#define CSL_DAPPC_CTRL_REG_1_COREPRESENT_RESETVAL               (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_COREPRESENT_MAX                    (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_COREACCESSIBLE_MASK                (0x00000002U)
#define CSL_DAPPC_CTRL_REG_1_COREACCESSIBLE_SHIFT               (1U)
#define CSL_DAPPC_CTRL_REG_1_COREACCESSIBLE_RESETVAL            (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_COREACCESSIBLE_MAX                 (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_CLOCK_MASK                         (0x00000004U)
#define CSL_DAPPC_CTRL_REG_1_CLOCK_SHIFT                        (2U)
#define CSL_DAPPC_CTRL_REG_1_CLOCK_RESETVAL                     (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_CLOCK_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_FORCEACTIVE_MASK                   (0x00000008U)
#define CSL_DAPPC_CTRL_REG_1_FORCEACTIVE_SHIFT                  (3U)
#define CSL_DAPPC_CTRL_REG_1_FORCEACTIVE_RESETVAL               (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_FORCEACTIVE_MAX                    (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_CLOCKDOWNDESIRED_MASK              (0x00000010U)
#define CSL_DAPPC_CTRL_REG_1_CLOCKDOWNDESIRED_SHIFT             (4U)
#define CSL_DAPPC_CTRL_REG_1_CLOCKDOWNDESIRED_RESETVAL          (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_CLOCKDOWNDESIRED_MAX               (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_POWER_MASK                         (0x00000020U)
#define CSL_DAPPC_CTRL_REG_1_POWER_SHIFT                        (5U)
#define CSL_DAPPC_CTRL_REG_1_POWER_RESETVAL                     (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_POWER_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_POWERDOWNDESIRED_MASK              (0x00000080U)
#define CSL_DAPPC_CTRL_REG_1_POWERDOWNDESIRED_SHIFT             (7U)
#define CSL_DAPPC_CTRL_REG_1_POWERDOWNDESIRED_RESETVAL          (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_POWERDOWNDESIRED_MAX               (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_DBGATTENTION_MASK                  (0x00000400U)
#define CSL_DAPPC_CTRL_REG_1_DBGATTENTION_SHIFT                 (10U)
#define CSL_DAPPC_CTRL_REG_1_DBGATTENTION_RESETVAL              (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_DBGATTENTION_MAX                   (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_DBGMODE_MASK                       (0x00001800U)
#define CSL_DAPPC_CTRL_REG_1_DBGMODE_SHIFT                      (11U)
#define CSL_DAPPC_CTRL_REG_1_DBGMODE_RESETVAL                   (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_DBGMODE_MAX                        (0x00000003U)

#define CSL_DAPPC_CTRL_REG_1_DBGEN_MASK                         (0x00002000U)
#define CSL_DAPPC_CTRL_REG_1_DBGEN_SHIFT                        (13U)
#define CSL_DAPPC_CTRL_REG_1_DBGEN_RESETVAL                     (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_DBGEN_MAX                          (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_RESETCTRL_MASK                     (0x0001C000U)
#define CSL_DAPPC_CTRL_REG_1_RESETCTRL_SHIFT                    (14U)
#define CSL_DAPPC_CTRL_REG_1_RESETCTRL_RESETVAL                 (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_RESETCTRL_MAX                      (0x00000007U)

#define CSL_DAPPC_CTRL_REG_1_INRESET_MASK                       (0x00020000U)
#define CSL_DAPPC_CTRL_REG_1_INRESET_SHIFT                      (17U)
#define CSL_DAPPC_CTRL_REG_1_INRESET_RESETVAL                   (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_INRESET_MAX                        (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_UNNATURALRESET_MASK                (0x00040000U)
#define CSL_DAPPC_CTRL_REG_1_UNNATURALRESET_SHIFT               (18U)
#define CSL_DAPPC_CTRL_REG_1_UNNATURALRESET_RESETVAL            (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_UNNATURALRESET_MAX                 (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_COREPOWER_MASK                     (0x00080000U)
#define CSL_DAPPC_CTRL_REG_1_COREPOWER_SHIFT                    (19U)
#define CSL_DAPPC_CTRL_REG_1_COREPOWER_RESETVAL                 (0x00000001U)
#define CSL_DAPPC_CTRL_REG_1_COREPOWER_MAX                      (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_INHIBITSLEEP_MASK                  (0x00100000U)
#define CSL_DAPPC_CTRL_REG_1_INHIBITSLEEP_SHIFT                 (20U)
#define CSL_DAPPC_CTRL_REG_1_INHIBITSLEEP_RESETVAL              (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_INHIBITSLEEP_MAX                   (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_POWERLOSSDETECTED_MASK             (0x00200000U)
#define CSL_DAPPC_CTRL_REG_1_POWERLOSSDETECTED_SHIFT            (21U)
#define CSL_DAPPC_CTRL_REG_1_POWERLOSSDETECTED_RESETVAL         (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_POWERLOSSDETECTED_MAX              (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_RESETOCCURRED_MASK                 (0x00400000U)
#define CSL_DAPPC_CTRL_REG_1_RESETOCCURRED_SHIFT                (22U)
#define CSL_DAPPC_CTRL_REG_1_RESETOCCURRED_RESETVAL             (0x00000000U)
#define CSL_DAPPC_CTRL_REG_1_RESETOCCURRED_MAX                  (0x00000001U)

#define CSL_DAPPC_CTRL_REG_1_RESETVAL                           (0x00080027U)

#ifdef __cplusplus
}
#endif
#endif
