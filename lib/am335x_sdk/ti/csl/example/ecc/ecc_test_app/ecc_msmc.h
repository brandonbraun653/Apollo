/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2019
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

#ifndef APP_ECC_MSMC_H
#define APP_ECC_MSMC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include "esm_app.h"
#include <ti/csl/csl_ecc_aggr.h>

#define MSMC_ECC_SEC_ERR_TEST                    ('1')
#define MSMC_ECC_DED_ERR_TEST                    ('2')
#define MSMC_ECC_EXIT                            ('x')

/* the Field INSert macro */
#define APP_TEST_FINS(reg, PER_REG_FIELD, val)                                   \
    ((reg) = ((reg) & ~APP_##PER_REG_FIELD##_MASK)                          \
      | (((val) << APP_##PER_REG_FIELD##_SHIFT) & APP_##PER_REG_FIELD##_MASK))



/* APP_TEST DEFINES */
#define APP_TEST_ECC_AGGR_CTRL_ECC_PATTERN_MASK                                           (0x00000F00U)
#define APP_TEST_ECC_AGGR_CTRL_ECC_PATTERN_SHIFT                                          (0x00000008U)

#define APP_TEST_ECC_AGGR_CTRL_ECC_CHK_MASK                                               (0x00000002U)
#define APP_TEST_ECC_AGGR_CTRL_ECC_CHK_SHIFT                                              (0x00000001U)

#define APP_TEST_ECC_AGGR_CTRL_FORCE_SE_MASK                                              (0x00000008U)
#define APP_TEST_ECC_AGGR_CTRL_FORCE_SE_SHIFT                                             (0x00000003U)

#define APP_TEST_ECC_AGGR_CTRL_FORCE_DE_MASK                                              (0x00000010U)
#define APP_TEST_ECC_AGGR_CTRL_FORCE_DE_SHIFT                                             (0x00000004U)

/* ERR1 register */
#define APP_TEST_ECC_AGGR_ERR1_ECC_GRP_MASK                                              (0x0000FFFFU)
#define APP_TEST_ECC_AGGR_ERR1_ECC_GRP_SHIFT                                             (0x00000000U)

#define APP_TEST_ECC_AGGR_ERR1_ECC_BIT1_MASK                                             (0x00FF0000U)
#define APP_TEST_ECC_AGGR_ERR1_ECC_BIT1_SHIFT                                            (0x00000010U)

/* ERR2 register */
#define APP_TEST_ECC_AGGR_ERR2_ECC_BIT2_MASK                                             (0x0000000FU)
#define APP_TEST_ECC_AGGR_ERR2_ECC_BIT2_SHIFT                                            (0x00000000U)


/* Group pattern to use */
#define MSMC_ECC_TEST_GROUP_PATTERN              (2u)

/* Test bit locations for introducing single and double bit errors */
#define MSMC_ECC_ERR_BIT_1                       (2u)
#define MSMC_ECC_ERR_BIT_2                       (8u)

/* Below Memory types for ECC are supported in the test
 * Please update the MAX Entries accordinly */
#define APP_ECC_MEMTYPE_MSMC                     (0u)

/* Max entries based on max mem type */
#define APP_ECC_AGGREGATOR_MAX_ENTRIES (APP_ECC_MEMTYPE_MSMC + 1u)

extern CSL_ecc_aggrRegs * const cslAppEccAggrAddrTable[APP_ECC_AGGREGATOR_MAX_ENTRIES];

/* MSMC RAM ID for Bank 1 is 56 : MSMC - rmw1_queue_busecc_0
   MSMC RAM ID for Bank 0 is 49 : MSMC - rmw0_queue_busecc_1
   This test demonstrates the MSMC ECC using Bank 1
*/
#if defined(SOC_AM65XX)
#define CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID      (56U)
#endif
#if defined(SOC_J721E)
#define CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID      (70U)
#endif

#define ECC_AGGR_UNKNOWN_RAM_ID                      (0xFFFFU)

/* ESM Base Addresses */
#if defined(SOC_AM65XX)
    #if defined(BUILD_MPU)
        #define ESM_CFG_BASE                (CSL_ESM0_CFG_BASE)
        #define ESM_LO_INT                  (CSL_GIC0_INTR_ESM0_BUS_ESM_INT_LOW_LVL)
        #define ESM_HI_INT                  (CSL_GIC0_INTR_ESM0_BUS_ESM_INT_HI_LVL)
        #define ESM_CFG_ERR_INT             (CSL_GIC0_INTR_ESM0_BUS_ESM_INT_CFG_LVL)
    #endif
#endif

int32_t msmcEccTest(void);
void cslAppChkIsExpectedRamId(uint32_t testId);

/* exteran variable references */
extern uint32_t gUartBaseAddr;

#ifdef __cplusplus
}
#endif

#endif
