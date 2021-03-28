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
#ifndef CSLR_CMI_H_
#define CSLR_CMI_H_

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
    volatile Uint32 CMI_IDENTICATION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 CMI_SYS_CONFIG;
    volatile Uint32 CMI_STATUS;
    volatile Uint8  RSVD1[12];
    volatile Uint32 CMI_CONFIGURATION;
    volatile Uint32 CMI_CLASS_FILTERING;
    volatile Uint32 CMI_TRIGGERING;
    volatile Uint32 CMI_SAMPLING;
} CSL_CMIRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_CMI_CMI_IDENTICATION                                (0x0U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION                  (CSL_CMI_CMI_IDENTICATION)

#define CSL_CMI_CMI_SYS_CONFIG                                  (0x10U)
/* Below define for backward compatibility */
#define CMI_SYS_CONFIG                    (CSL_CMI_CMI_SYS_CONFIG)

#define CSL_CMI_CMI_STATUS                                      (0x14U)
/* Below define for backward compatibility */
#define CMI_STATUS                        (CSL_CMI_CMI_STATUS)

#define CSL_CMI_CMI_CONFIGURATION                               (0x24U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION                 (CSL_CMI_CMI_CONFIGURATION)

#define CSL_CMI_CMI_CLASS_FILTERING                             (0x28U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING               (CSL_CMI_CMI_CLASS_FILTERING)

#define CSL_CMI_CMI_TRIGGERING                                  (0x2CU)
/* Below define for backward compatibility */
#define CMI_TRIGGERING                    (CSL_CMI_CMI_TRIGGERING)

#define CSL_CMI_CMI_SAMPLING                                    (0x30U)
/* Below define for backward compatibility */
#define CMI_SAMPLING                      (CSL_CMI_CMI_SAMPLING)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CMI_IDENTICATION */
#define CSL_CMI_CMI_IDENTICATION_SCHEME_MASK                    (0xC0000000U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_SCHEME_MASK                  (CSL_CMI_CMI_IDENTICATION_SCHEME_MASK)

#define CSL_CMI_CMI_IDENTICATION_SCHEME_RESETVAL                (0x00000001U)


#define CSL_CMI_CMI_IDENTICATION_SCHEME_SHIFT                   (30U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_SCHEME_SHIFT                 (CSL_CMI_CMI_IDENTICATION_SCHEME_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_SCHEME_MAX                     (0x00000003U)
#define CSL_CMI_CMI_IDENTICATION_FUNC_MASK                      (0x0FFF0000U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_FUNC_MASK                    (CSL_CMI_CMI_IDENTICATION_FUNC_MASK)

#define CSL_CMI_CMI_IDENTICATION_FUNC_RESETVAL                  (0x00000005U)


#define CSL_CMI_CMI_IDENTICATION_FUNC_SHIFT                     (16U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_FUNC_SHIFT                   (CSL_CMI_CMI_IDENTICATION_FUNC_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_FUNC_MAX                       (0x00000fffU)
#define CSL_CMI_CMI_IDENTICATION_RTL_MASK                       (0x0000F800U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_RTL_MASK                     (CSL_CMI_CMI_IDENTICATION_RTL_MASK)

#define CSL_CMI_CMI_IDENTICATION_RTL_RESETVAL                   (0x00000009U)


#define CSL_CMI_CMI_IDENTICATION_RTL_SHIFT                      (11U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_RTL_SHIFT                    (CSL_CMI_CMI_IDENTICATION_RTL_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_RTL_MAX                        (0x0000001fU)
#define CSL_CMI_CMI_IDENTICATION_MAJOR_MASK                     (0x00000700U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_MAJOR_MASK                   (CSL_CMI_CMI_IDENTICATION_MAJOR_MASK)

#define CSL_CMI_CMI_IDENTICATION_MAJOR_RESETVAL                 (0x00000000U)


#define CSL_CMI_CMI_IDENTICATION_MAJOR_SHIFT                    (8U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_MAJOR_SHIFT                  (CSL_CMI_CMI_IDENTICATION_MAJOR_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_MAJOR_MAX                      (0x00000007U)
#define CSL_CMI_CMI_IDENTICATION_CUSTOM_MASK                    (0x000000C0U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_CUSTOM_MASK                  (CSL_CMI_CMI_IDENTICATION_CUSTOM_MASK)

#define CSL_CMI_CMI_IDENTICATION_CUSTOM_RESETVAL                (0x00000000U)


#define CSL_CMI_CMI_IDENTICATION_CUSTOM_SHIFT                   (6U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_CUSTOM_SHIFT                 (CSL_CMI_CMI_IDENTICATION_CUSTOM_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_CUSTOM_MAX                     (0x00000003U)
#define CSL_CMI_CMI_IDENTICATION_MINOR_MASK                     (0x0000003FU)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_MINOR_MASK                   (CSL_CMI_CMI_IDENTICATION_MINOR_MASK)

#define CSL_CMI_CMI_IDENTICATION_MINOR_RESETVAL                 (0x00000000U)


#define CSL_CMI_CMI_IDENTICATION_MINOR_SHIFT                    (0U)
/* Below define for backward compatibility */
#define CMI_IDENTICATION_MINOR_SHIFT                  (CSL_CMI_CMI_IDENTICATION_MINOR_SHIFT)

#define CSL_CMI_CMI_IDENTICATION_MINOR_MAX                      (0x0000003fU)

#define CSL_CMI_CMI_IDENTICATION_RESETVAL                       (0x50054800U)

/* CMI_SYS_CONFIG */
#define CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_MASK                    (0x0000000CU)
/* Below define for backward compatibility */
#define CMI_SYS_CONFIG_IDLEMODE_MASK                  (CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_MASK)

#define CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_RESETVAL                (0x00000002U)


#define CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_SHIFT                   (2U)
/* Below define for backward compatibility */
#define CMI_SYS_CONFIG_IDLEMODE_SHIFT                 (CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_SHIFT)

#define CSL_CMI_CMI_SYS_CONFIG_IDLEMODE_MAX                     (0x00000003U)
#define CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_MASK                   (0x00000001U)
/* Below define for backward compatibility */
#define CMI_SYS_CONFIG_SOFTRESET_MASK                 (CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_MASK)

#define CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_RESETVAL               (0x00000000U)


#define CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_SHIFT                  (0U)
/* Below define for backward compatibility */
#define CMI_SYS_CONFIG_SOFTRESET_SHIFT                (CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_SHIFT)

#define CSL_CMI_CMI_SYS_CONFIG_SOFTRESET_MAX                    (0x00000001U)

#define CSL_CMI_CMI_SYS_CONFIG_RESETVAL                         (0x00000008U)

/* CMI_STATUS */
#define CSL_CMI_CMI_STATUS_FIFOEMPTY_MASK                       (0x00000100U)
/* Below define for backward compatibility */
#define CMI_STATUS_FIFOEMPTY_MASK                     (CSL_CMI_CMI_STATUS_FIFOEMPTY_MASK)

#define CSL_CMI_CMI_STATUS_FIFOEMPTY_RESETVAL                   (0x00000001U)


#define CSL_CMI_CMI_STATUS_FIFOEMPTY_SHIFT                      (8U)
/* Below define for backward compatibility */
#define CMI_STATUS_FIFOEMPTY_SHIFT                    (CSL_CMI_CMI_STATUS_FIFOEMPTY_SHIFT)

#define CSL_CMI_CMI_STATUS_FIFOEMPTY_MAX                        (0x00000001U)

#define CSL_CMI_CMI_STATUS_RESETVAL                             (0x00000100U)

/* CMI_CONFIGURATION */
#define CSL_CMI_CMI_CONFIGURATION_CLAIM_3_MASK                  (0xC0000000U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_3_MASK                (CSL_CMI_CMI_CONFIGURATION_CLAIM_3_MASK)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_3_RESETVAL              (0x00000000U)


#define CSL_CMI_CMI_CONFIGURATION_CLAIM_3_SHIFT                 (30U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_3_SHIFT               (CSL_CMI_CMI_CONFIGURATION_CLAIM_3_SHIFT)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_3_MAX                   (0x00000003U)
#define CSL_CMI_CMI_CONFIGURATION_CLAIM_2_MASK                  (0x20000000U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_2_MASK                (CSL_CMI_CMI_CONFIGURATION_CLAIM_2_MASK)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_2_RESETVAL              (0x00000001U)


#define CSL_CMI_CMI_CONFIGURATION_CLAIM_2_SHIFT                 (29U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_2_SHIFT               (CSL_CMI_CMI_CONFIGURATION_CLAIM_2_SHIFT)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_2_MAX                   (0x00000001U)
#define CSL_CMI_CMI_CONFIGURATION_CLAIM_1_MASK                  (0x10000000U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_1_MASK                (CSL_CMI_CMI_CONFIGURATION_CLAIM_1_MASK)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_1_RESETVAL              (0x00000000U)


#define CSL_CMI_CMI_CONFIGURATION_CLAIM_1_SHIFT                 (28U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_CLAIM_1_SHIFT               (CSL_CMI_CMI_CONFIGURATION_CLAIM_1_SHIFT)

#define CSL_CMI_CMI_CONFIGURATION_CLAIM_1_MAX                   (0x00000001U)
#define CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_MASK               (0x00008000U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_MOD_ACT_EN_MASK             (CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_MASK)

#define CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_RESETVAL           (0x00000000U)


#define CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_SHIFT              (15U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_MOD_ACT_EN_SHIFT            (CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_SHIFT)

#define CSL_CMI_CMI_CONFIGURATION_MOD_ACT_EN_MAX                (0x00000001U)
#define CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_MASK              (0x00000080U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_EVT_CAPT_EN_MASK            (CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_MASK)

#define CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_RESETVAL          (0x00000000U)


#define CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_SHIFT             (7U)
/* Below define for backward compatibility */
#define CMI_CONFIGURATION_EVT_CAPT_EN_SHIFT           (CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_SHIFT)

#define CSL_CMI_CMI_CONFIGURATION_EVT_CAPT_EN_MAX               (0x00000001U)

#define CSL_CMI_CMI_CONFIGURATION_RESETVAL                      (0x20000000U)

/* CMI_CLASS_FILTERING */
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_MASK        (0x80000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_SHIFT       (31U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1F_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_MASK        (0x40000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_SHIFT       (30U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1E_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_MASK        (0x20000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_SHIFT       (29U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1D_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_MASK        (0x10000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_SHIFT       (28U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1C_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_MASK        (0x08000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_SHIFT       (27U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1B_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_MASK        (0x04000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_SHIFT       (26U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_1A_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_MASK        (0x02000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_SHIFT       (25U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_19_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_MASK        (0x01000000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_SHIFT       (24U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_18_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_MASK        (0x00800000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_SHIFT       (23U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_17_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_MASK        (0x00400000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_SHIFT       (22U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_16_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_MASK        (0x00200000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_SHIFT       (21U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_15_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_MASK        (0x00100000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_SHIFT       (20U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_14_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_MASK        (0x00080000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_SHIFT       (19U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_13_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_MASK        (0x00040000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_SHIFT       (18U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_12_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_MASK        (0x00020000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_SHIFT       (17U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_11_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_MASK        (0x00010000U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_SHIFT       (16U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_10_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MASK        (0x00000008U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_SHIFT       (3U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_03_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MASK        (0x00000004U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_SHIFT       (2U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_02_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MASK        (0x00000002U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_SHIFT       (1U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_01_MAX         (0x00000001U)
#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MASK        (0x00000001U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MASK      (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MASK)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_RESETVAL    (0x00000000U)


#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_SHIFT       (0U)
/* Below define for backward compatibility */
#define CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_SHIFT     (CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_SHIFT)

#define CSL_CMI_CMI_CLASS_FILTERING_SNAP_CAPT_EN_00_MAX         (0x00000001U)

#define CSL_CMI_CMI_CLASS_FILTERING_RESETVAL                    (0x00000000U)

/* CMI_TRIGGERING */
#define CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_MASK                (0x00000002U)
/* Below define for backward compatibility */
#define CMI_TRIGGERING_TRIG_STOP_EN_MASK              (CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_MASK)

#define CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_RESETVAL            (0x00000000U)


#define CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_SHIFT               (1U)
/* Below define for backward compatibility */
#define CMI_TRIGGERING_TRIG_STOP_EN_SHIFT             (CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_SHIFT)

#define CSL_CMI_CMI_TRIGGERING_TRIG_STOP_EN_MAX                 (0x00000001U)
#define CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_MASK               (0x00000001U)
/* Below define for backward compatibility */
#define CMI_TRIGGERING_TRIG_START_EN_MASK             (CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_MASK)

#define CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_RESETVAL           (0x00000000U)


#define CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_SHIFT              (0U)
/* Below define for backward compatibility */
#define CMI_TRIGGERING_TRIG_START_EN_SHIFT            (CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_SHIFT)

#define CSL_CMI_CMI_TRIGGERING_TRIG_START_EN_MAX                (0x00000001U)

#define CSL_CMI_CMI_TRIGGERING_RESETVAL                         (0x00000000U)

/* CMI_SAMPLING */
#define CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_MASK                (0x000F0000U)
/* Below define for backward compatibility */
#define CMI_SAMPLING_FCLK_DIV_FACOR_MASK              (CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_MASK)

#define CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_RESETVAL            (0x00000000U)


#define CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_SHIFT               (16U)
/* Below define for backward compatibility */
#define CMI_SAMPLING_FCLK_DIV_FACOR_SHIFT             (CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_SHIFT)

#define CSL_CMI_CMI_SAMPLING_FCLK_DIV_FACOR_MAX                 (0x0000000fU)
#define CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_MASK                (0x000000FFU)
/* Below define for backward compatibility */
#define CMI_SAMPLING_SAMP_WIND_SIZE_MASK              (CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_MASK)

#define CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_RESETVAL            (0x00000000U)


#define CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_SHIFT               (0U)
/* Below define for backward compatibility */
#define CMI_SAMPLING_SAMP_WIND_SIZE_SHIFT             (CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_SHIFT)

#define CSL_CMI_CMI_SAMPLING_SAMP_WIND_SIZE_MAX                 (0x000000ffU)

#define CSL_CMI_CMI_SAMPLING_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
