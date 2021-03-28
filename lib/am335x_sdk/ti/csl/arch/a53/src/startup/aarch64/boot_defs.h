//******************************************************************************
//
//  Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES// LOSS OF USE,
//  DATA, OR PROFITS// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//******************************************************************************
#ifndef CSL_FAMILY_ARM_V8A_COREBOOT_H
#define CSL_FAMILY_ARM_V8A_COREBOOT_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined (SOC_AM65XX)
/* GIC_2_2  configuration */
#define CSL_GIC_BASE_ADDR   (0x1800000U)
#define CSL_GICR_BASE_ADDR  (0x1880000U)
#define CSL_GICS_BASE_ADDR  (0x1890000U)
#else
/* GIC_4_2  configuration */
#define CSL_GIC_BASE_ADDR   (0x1800000U)
#define CSL_GICR_BASE_ADDR  (0x1900000U)
#define CSL_GICS_BASE_ADDR  (0x1910000U)
#endif

#define CSL_GICX_OFFSET     0x0020000
#define CSL_TI_STACK_SIZE     0x10000
#define CSL_GTC_R10_CFG1    0xA90000
#define CSL_GTC_CNTCR_ADDR  (CSL_GTC_R10_CFG1 + 0x0)

#ifndef icc_igrpen1_el3
#define icc_igrpen1_el3 s3_6_c12_c12_7
#endif

#ifndef icc_pmr_el1
#define icc_pmr_el1     s3_0_c4_c6_0
#endif

#ifndef icc_sre_el2
#define icc_sre_el2     s3_4_c12_c9_5
#endif

#ifndef icc_sre_el3
#define icc_sre_el3     s3_6_c12_c12_5
#endif

#ifdef __cplusplus
}
#endif

#endif
