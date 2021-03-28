/********************************************************************
*
* MCU_R5 MEMORYMAP header file
*
* Copyright (C) 2020 Texas Instruments Incorporated.
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
#ifndef CSLR_SOC_DSP_BASEADDRESS_H_
#define CSLR_SOC_DSP_BASEADDRESS_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

#define CSL_DSP_L2_U_BASE                  (0x800000ul)
#define CSL_DSP_L1P_U_BASE                 (0xE00000ul)
#define CSL_DSP_L1D_U_BASE                 (0xF00000ul)
#define CSL_DSP_ICFG_U_BASE                (0x1800000ul)
#define CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS  (CSL_DSP_ICFG_U_BASE)

/* EDMA related base addresses */
/* CC0 defines */
#define EDMA_DSS_CC0_BASE_ADDRESS           CSL_DSS_TPCC_A_U_BASE
#define EDMA_DSS_CC0_TC0_BASE_ADDRESS       CSL_DSS_TPTC_A0_U_BASE
#define EDMA_DSS_CC0_TC1_BASE_ADDRESS       CSL_DSS_TPTC_A1_U_BASE

/* CC1 defines */
#define EDMA_DSS_CC1_BASE_ADDRESS           CSL_DSS_TPCC_B_U_BASE
#define EDMA_DSS_CC1_TC0_BASE_ADDRESS       CSL_DSS_TPTC_B0_U_BASE
#define EDMA_DSS_CC1_TC1_BASE_ADDRESS       CSL_DSS_TPTC_B1_U_BASE

/* CC2 defines */
#define EDMA_DSS_CC2_BASE_ADDRESS           CSL_DSS_TPCC_C_U_BASE
#define EDMA_DSS_CC2_TC0_BASE_ADDRESS       CSL_DSS_TPTC_C0_U_BASE
#define EDMA_DSS_CC2_TC1_BASE_ADDRESS       CSL_DSS_TPTC_C1_U_BASE

/* CC3 defines */
#define EDMA_DSS_CC3_BASE_ADDRESS           CSL_RCSS_TPCC_A_U_BASE
#define EDMA_DSS_CC3_TC0_BASE_ADDRESS       CSL_RCSS_TPTC_A0_U_BASE
#define EDMA_DSS_CC3_TC1_BASE_ADDRESS       CSL_RCSS_TPTC_A1_U_BASE

#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_DSP_BASEADDRESS_H_ */
