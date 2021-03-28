/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017 - 2018
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
#if defined (SOC_K2G)
#include <ti/csl/csl_emif4f.h>
#include <ti/csl/cslr_emif4f.h>
#include "ecc_emif4f_aliases.h"
#else
#include <ti/csl/csl_emif.h>
#endif

#include "ecc_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EMIF_ECC_NON_QUANTA_ALIGN_ADDR_ERR_TEST                          ('1')
#define EMIF_ECC_BYTECOUNT_WRITEACCESS_NOTMULTIPLE_ECCQUANTA_ERR_TEST    ('2')
#define EMIF_ECC_SEC_ERR_TEST                                            ('3')
#define EMIF_ECC_DED_ERR_TEST                                            ('4')

/** \brief EMIF instance used */
#if defined (SOC_K2G)
#define EMIF_APP_INST                     (CSL_DDR3_0_SLV_CFG_REGS)
#else
#define EMIF_APP_INST                     (SOC_EMIF1_CONF_REGS_BASE)
#endif
#define EMIF_START_ADDR                   (0x80000000)
#define EMIF_ECC_START_ADDR               (0x90000000)
#define EMIF_ECC_END_ADDR                 (0x9001FFFF)
/** \brief As Err address log FIFO size is 4 so EMIF_ECC_1B_ERR_THRSH_VAL is set
 *         as 2 to avoid missing of Err address log
 */
#define EMIF_ECC_1B_ERR_THRSH_VAL         (0x1)

#define EMIF_ECC_TEST_ADDR                (EMIF_ECC_START_ADDR + 0x100)
#define EMIF_ECC_TEST_ADDR_1              (EMIF_ECC_START_ADDR + 0x200)
#define EMIF_ECC_TEST_ADDR_2              (EMIF_ECC_START_ADDR + 0x3)

#if defined (SOC_K2G)

#define EMIF_COREPAC_PRIORITY             (0x20U)
#if defined (__ARM_ARCH_7A__)
#define EMIF_ECC_ERR_INT                  (123U + 32U)
#define EMIF_INTR_EDGE_TRIGGER            (0x3U)
#elif defined (_TMS320C6X)
#define EMIF_ECC_ERR_INT                  (0x34U)
#define EMIF_MUX_INPUT_EVENT              (198U)
#define EMIF_MUX_OUTPUT_EVENT             (36U)
#endif

#else
	
#if defined (__ARM_ARCH_7A__)
#define EMIF_ECC_ERR_INT                  (13U)
#define EMIF_ECC_ERR_INT_INDEX            (CSL_XBAR_INST_MPU_IRQ_13)
#elif defined (__TI_ARM_V7M4__)
#define EMIF_ECC_ERR_INT                  (35U)
#define EMIF_ECC_ERR_INT_INDEX            (CSL_XBAR_INST_IPU1_IRQ_35)
#elif defined (_TMS320C6X)
#define EMIF_ECC_ERR_INT                  (93U)
#define EMIF_ECC_ERR_INT_INDEX            (CSL_XBAR_INST_DSP1_IRQ_93)
#endif

#endif

void mainSubMenuEmifEccTest(char *option);
int32_t emifEccTest(void);

void isrEmifSecErr();
void isrEmifDedErr();
void isrEmifNonEccQuantaAlignAddrErr();
void isrEmifByteCntWRAccessNotMultEccQuantaErr();

#ifdef __cplusplus
}
#endif
