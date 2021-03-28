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
#ifndef CSLR_MLBSS_H_
#define CSLR_MLBSS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for ss_mmr_generated_address_block
**************************************************************************/
typedef struct {
    volatile Uint32 MLBSS_REVISION_REG;
    volatile Uint32 MLBSS_PWR_MGMT;
    volatile Uint8  RSVD0[248];
    volatile Uint32 MLBSS_PERFORMANCE;
} CSL_MlbSsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* MLBSS HL0.8 compliant Revision Register. */
#define CSL_MLBSS_MLBSS_REVISION_REG                            (0x0U)

/* MLBSS Powermanagement Register */
#define CSL_MLBSS_MLBSS_PWR_MGMT                                (0x4U)

/* MLBSS Performance Register */
#define CSL_MLBSS_MLBSS_PERFORMANCE                             (0x100U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* MLBSS_REVISION_REG */

#define CSL_MLBSS_MLBSS_REVISION_REG_MINOR_MASK                 (0x0000003FU)
#define CSL_MLBSS_MLBSS_REVISION_REG_MINOR_SHIFT                (0U)
#define CSL_MLBSS_MLBSS_REVISION_REG_MINOR_RESETVAL             (0x00000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_MINOR_MAX                  (0x0000003fU)

#define CSL_MLBSS_MLBSS_REVISION_REG_CUSTOM_MASK                (0x000000C0U)
#define CSL_MLBSS_MLBSS_REVISION_REG_CUSTOM_SHIFT               (6U)
#define CSL_MLBSS_MLBSS_REVISION_REG_CUSTOM_RESETVAL            (0x00000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_CUSTOM_MAX                 (0x00000003U)

#define CSL_MLBSS_MLBSS_REVISION_REG_MAJOR_MASK                 (0x00000700U)
#define CSL_MLBSS_MLBSS_REVISION_REG_MAJOR_SHIFT                (8U)
#define CSL_MLBSS_MLBSS_REVISION_REG_MAJOR_RESETVAL             (0x00000001U)
#define CSL_MLBSS_MLBSS_REVISION_REG_MAJOR_MAX                  (0x00000007U)

#define CSL_MLBSS_MLBSS_REVISION_REG_RTL_MASK                   (0x0000F800U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RTL_SHIFT                  (11U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RTL_RESETVAL               (0x00000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RTL_MAX                    (0x0000001fU)

#define CSL_MLBSS_MLBSS_REVISION_REG_FUNC_MASK                  (0x0FFF0000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_FUNC_SHIFT                 (16U)
#define CSL_MLBSS_MLBSS_REVISION_REG_FUNC_RESETVAL              (0x00000a08U)
#define CSL_MLBSS_MLBSS_REVISION_REG_FUNC_MAX                   (0x00000fffU)

#define CSL_MLBSS_MLBSS_REVISION_REG_RSVD_MASK                  (0x30000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RSVD_SHIFT                 (28U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RSVD_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_RSVD_MAX                   (0x00000003U)

#define CSL_MLBSS_MLBSS_REVISION_REG_SCHEME_MASK                (0xC0000000U)
#define CSL_MLBSS_MLBSS_REVISION_REG_SCHEME_SHIFT               (30U)
#define CSL_MLBSS_MLBSS_REVISION_REG_SCHEME_RESETVAL            (0x00000001U)
#define CSL_MLBSS_MLBSS_REVISION_REG_SCHEME_MAX                 (0x00000003U)

#define CSL_MLBSS_MLBSS_REVISION_REG_RESETVAL                   (0x4a080100U)

/* MLBSS_PWR_MGMT */

#define CSL_MLBSS_MLBSS_PWR_MGMT_MSTANDBY_MASK                  (0x00000001U)
#define CSL_MLBSS_MLBSS_PWR_MGMT_MSTANDBY_SHIFT                 (0U)
#define CSL_MLBSS_MLBSS_PWR_MGMT_MSTANDBY_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PWR_MGMT_MSTANDBY_MAX                   (0x00000001U)

#define CSL_MLBSS_MLBSS_PWR_MGMT_RSVD_MASK                      (0xFFFFFFFEU)
#define CSL_MLBSS_MLBSS_PWR_MGMT_RSVD_SHIFT                     (1U)
#define CSL_MLBSS_MLBSS_PWR_MGMT_RSVD_RESETVAL                  (0x00000000U)
#define CSL_MLBSS_MLBSS_PWR_MGMT_RSVD_MAX                       (0x7fffffffU)

#define CSL_MLBSS_MLBSS_PWR_MGMT_RESETVAL                       (0x00000000U)

/* MLBSS_PERFORMANCE */

#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_FLAG_MASK              (0x00000003U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_FLAG_SHIFT             (0U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_FLAG_RESETVAL          (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_FLAG_MAX               (0x00000003U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD1_MASK                  (0x0000000CU)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD1_SHIFT                 (2U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD1_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD1_MAX                   (0x00000003U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_FLAG_MASK             (0x00000030U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_FLAG_SHIFT            (4U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_FLAG_RESETVAL         (0x00000001U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_FLAG_MAX              (0x00000003U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD2_MASK                  (0x000000C0U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD2_SHIFT                 (6U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD2_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD2_MAX                   (0x00000003U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_PRI_MASK               (0x00000700U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_PRI_SHIFT              (8U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_PRI_RESETVAL           (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_SYNC_PRI_MAX                (0x00000007U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD3_MASK                  (0x00000800U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD3_SHIFT                 (11U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD3_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD3_MAX                   (0x00000001U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_PRI_MASK              (0x00007000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_PRI_SHIFT             (12U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_PRI_RESETVAL          (0x00000004U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_ASYNC_PRI_MAX               (0x00000007U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD4_MASK                  (0x00008000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD4_SHIFT                 (15U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD4_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD4_MAX                   (0x00000001U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_WRNP_MASK                   (0x00010000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_WRNP_SHIFT                  (16U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_WRNP_RESETVAL               (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_WRNP_MAX                    (0x00000001U)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD5_MASK                  (0xFFFE0000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD5_SHIFT                 (17U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD5_RESETVAL              (0x00000000U)
#define CSL_MLBSS_MLBSS_PERFORMANCE_RSVD5_MAX                   (0x00007fffU)

#define CSL_MLBSS_MLBSS_PERFORMANCE_RESETVAL                    (0x00004010U)

#ifdef __cplusplus
}
#endif
#endif
