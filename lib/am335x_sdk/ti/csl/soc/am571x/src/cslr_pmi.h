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
#ifndef CSLR_PMI_H
#define CSLR_PMI_H

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
    volatile Uint32 IDENTICATION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYS_CONFIG;
    volatile Uint32 STS;
    volatile Uint8  RSVD1[12];
    volatile Uint32 CONFIG;
    volatile Uint32 CLASS_FILTERING;
    volatile Uint32 TRIGGERING;
    volatile Uint32 SAMPLING;
} CSL_PmiRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* PM profiling identification register */
#define CSL_PMI_IDENTICATION                                    (0x0U)

/* PM profiling system configuartion register */
#define CSL_PMI_SYS_CONFIG                                      (0x10U)

/* PM profiling status register */
#define CSL_PMI_STS                                             (0x14U)

/* PM profiling configuration register */
#define CSL_PMI_CONFIG                                          (0x24U)

/* PM profiling class filtering register */
#define CSL_PMI_CLASS_FILTERING                                 (0x28U)

/* PM profiling triggering control register */
#define CSL_PMI_TRIGGERING                                      (0x2CU)

/* PM profiling sampling window register */
#define CSL_PMI_SAMPLING                                        (0x30U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDENTICATION */

#define CSL_PMI_IDENTICATION_MINOR_MASK                         (0x0000003FU)
#define CSL_PMI_IDENTICATION_MINOR_SHIFT                        (0U)
#define CSL_PMI_IDENTICATION_MINOR_RESETVAL                     (0x00000000U)
#define CSL_PMI_IDENTICATION_MINOR_MAX                          (0x0000003fU)

#define CSL_PMI_IDENTICATION_CUSTOM_MASK                        (0x000000C0U)
#define CSL_PMI_IDENTICATION_CUSTOM_SHIFT                       (6U)
#define CSL_PMI_IDENTICATION_CUSTOM_RESETVAL                    (0x00000000U)
#define CSL_PMI_IDENTICATION_CUSTOM_MAX                         (0x00000003U)

#define CSL_PMI_IDENTICATION_MAJOR_MASK                         (0x00000700U)
#define CSL_PMI_IDENTICATION_MAJOR_SHIFT                        (8U)
#define CSL_PMI_IDENTICATION_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_PMI_IDENTICATION_MAJOR_MAX                          (0x00000007U)

#define CSL_PMI_IDENTICATION_RTL_MASK                           (0x0000F800U)
#define CSL_PMI_IDENTICATION_RTL_SHIFT                          (11U)
#define CSL_PMI_IDENTICATION_RTL_RESETVAL                       (0x00000009U)
#define CSL_PMI_IDENTICATION_RTL_MAX                            (0x0000001fU)

#define CSL_PMI_IDENTICATION_FUNC_MASK                          (0x0FFF0000U)
#define CSL_PMI_IDENTICATION_FUNC_SHIFT                         (16U)
#define CSL_PMI_IDENTICATION_FUNC_RESETVAL                      (0x00000005U)
#define CSL_PMI_IDENTICATION_FUNC_MAX                           (0x00000fffU)

#define CSL_PMI_IDENTICATION_SCHEME_MASK                        (0xC0000000U)
#define CSL_PMI_IDENTICATION_SCHEME_SHIFT                       (30U)
#define CSL_PMI_IDENTICATION_SCHEME_RESETVAL                    (0x00000001U)
#define CSL_PMI_IDENTICATION_SCHEME_MAX                         (0x00000003U)

#define CSL_PMI_IDENTICATION_RESETVAL                           (0x50054800U)

/* SYS_CONFIG */

#define CSL_PMI_SYS_CONFIG_SOFTRESET_MASK                       (0x00000001U)
#define CSL_PMI_SYS_CONFIG_SOFTRESET_SHIFT                      (0U)
#define CSL_PMI_SYS_CONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_PMI_SYS_CONFIG_SOFTRESET_MAX                        (0x00000001U)

#define CSL_PMI_SYS_CONFIG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_PMI_SYS_CONFIG_IDLEMODE_SHIFT                       (2U)
#define CSL_PMI_SYS_CONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_PMI_SYS_CONFIG_IDLEMODE_MAX                         (0x00000003U)

#define CSL_PMI_SYS_CONFIG_RESETVAL                             (0x00000008U)

/* STS */

#define CSL_PMI_STS_FIFOEMPTY_MASK                              (0x00000100U)
#define CSL_PMI_STS_FIFOEMPTY_SHIFT                             (8U)
#define CSL_PMI_STS_FIFOEMPTY_RESETVAL                          (0x00000001U)
#define CSL_PMI_STS_FIFOEMPTY_MAX                               (0x00000001U)

#define CSL_PMI_STS_RESETVAL                                    (0x00000100U)

/* CONFIG */

#define CSL_PMI_CONFIG_EVT_CAPT_EN_MASK                         (0x00000080U)
#define CSL_PMI_CONFIG_EVT_CAPT_EN_SHIFT                        (7U)
#define CSL_PMI_CONFIG_EVT_CAPT_EN_RESETVAL                     (0x00000000U)
#define CSL_PMI_CONFIG_EVT_CAPT_EN_MAX                          (0x00000001U)

#define CSL_PMI_CONFIG_CLAIM_1_MASK                             (0x10000000U)
#define CSL_PMI_CONFIG_CLAIM_1_SHIFT                            (28U)
#define CSL_PMI_CONFIG_CLAIM_1_RESETVAL                         (0x00000000U)
#define CSL_PMI_CONFIG_CLAIM_1_MAX                              (0x00000001U)

#define CSL_PMI_CONFIG_CLAIM_2_MASK                             (0x20000000U)
#define CSL_PMI_CONFIG_CLAIM_2_SHIFT                            (29U)
#define CSL_PMI_CONFIG_CLAIM_2_RESETVAL                         (0x00000001U)
#define CSL_PMI_CONFIG_CLAIM_2_MAX                              (0x00000001U)

#define CSL_PMI_CONFIG_CLAIM_3_MASK                             (0xC0000000U)
#define CSL_PMI_CONFIG_CLAIM_3_SHIFT                            (30U)
#define CSL_PMI_CONFIG_CLAIM_3_RESETVAL                         (0x00000000U)
#define CSL_PMI_CONFIG_CLAIM_3_MAX                              (0x00000003U)

#define CSL_PMI_CONFIG_RESETVAL                                 (0x20000000U)

/* CLASS_FILTERING */

#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MASK            (0x00000001U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_00_SHIFT           (0U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_00_RESETVAL        (0x00000000U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MAX             (0x00000001U)

#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MASK            (0x00000002U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_01_SHIFT           (1U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_01_RESETVAL        (0x00000000U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MAX             (0x00000001U)

#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MASK            (0x00000004U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_02_SHIFT           (2U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_02_RESETVAL        (0x00000000U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MAX             (0x00000001U)

#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MASK            (0x00000008U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_03_SHIFT           (3U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_03_RESETVAL        (0x00000000U)
#define CSL_PMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MAX             (0x00000001U)

#define CSL_PMI_CLASS_FILTERING_RESETVAL                        (0x00000000U)

/* TRIGGERING */

#define CSL_PMI_TRIGGERING_TRIG_START_EN_MASK                   (0x00000001U)
#define CSL_PMI_TRIGGERING_TRIG_START_EN_SHIFT                  (0U)
#define CSL_PMI_TRIGGERING_TRIG_START_EN_RESETVAL               (0x00000000U)
#define CSL_PMI_TRIGGERING_TRIG_START_EN_MAX                    (0x00000001U)

#define CSL_PMI_TRIGGERING_TRIG_STOP_EN_MASK                    (0x00000002U)
#define CSL_PMI_TRIGGERING_TRIG_STOP_EN_SHIFT                   (1U)
#define CSL_PMI_TRIGGERING_TRIG_STOP_EN_RESETVAL                (0x00000000U)
#define CSL_PMI_TRIGGERING_TRIG_STOP_EN_MAX                     (0x00000001U)

#define CSL_PMI_TRIGGERING_RESETVAL                             (0x00000000U)

/* SAMPLING */

#define CSL_PMI_SAMPLING_SAMP_WIND_SIZE_MASK                    (0x000000FFU)
#define CSL_PMI_SAMPLING_SAMP_WIND_SIZE_SHIFT                   (0U)
#define CSL_PMI_SAMPLING_SAMP_WIND_SIZE_RESETVAL                (0x00000000U)
#define CSL_PMI_SAMPLING_SAMP_WIND_SIZE_MAX                     (0x000000ffU)

#define CSL_PMI_SAMPLING_FCLK_DIV_FACOR_MASK                    (0x000F0000U)
#define CSL_PMI_SAMPLING_FCLK_DIV_FACOR_SHIFT                   (16U)
#define CSL_PMI_SAMPLING_FCLK_DIV_FACOR_RESETVAL                (0x00000000U)
#define CSL_PMI_SAMPLING_FCLK_DIV_FACOR_MAX                     (0x0000000fU)

#define CSL_PMI_SAMPLING_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
