/*
* hw_icss_pru_debug.h
*
* Register-level header file for HW_ICSS_PRU_DEBUG
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*
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
#ifndef HW_ICSS_PRU_DEBUG_H_
#define HW_ICSS_PRU_DEBUG_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_PRU_DEBUG_GPR0                                 (0x0U)
#define HW_ICSS_PRU_DEBUG_GPR1                                 (0x4U)
#define HW_ICSS_PRU_DEBUG_GPR2                                 (0x8U)
#define HW_ICSS_PRU_DEBUG_GPR3                                 (0xcU)
#define HW_ICSS_PRU_DEBUG_GPR4                                 (0x10U)
#define HW_ICSS_PRU_DEBUG_GPR5                                 (0x14U)
#define HW_ICSS_PRU_DEBUG_GPR6                                 (0x18U)
#define HW_ICSS_PRU_DEBUG_GPR7                                 (0x1cU)
#define HW_ICSS_PRU_DEBUG_GPR8                                 (0x20U)
#define HW_ICSS_PRU_DEBUG_GPR9                                 (0x24U)
#define HW_ICSS_PRU_DEBUG_GPR10                                (0x28U)
#define HW_ICSS_PRU_DEBUG_GPR11                                (0x2cU)
#define HW_ICSS_PRU_DEBUG_GPR12                                (0x30U)
#define HW_ICSS_PRU_DEBUG_GPR13                                (0x34U)
#define HW_ICSS_PRU_DEBUG_GPR14                                (0x38U)
#define HW_ICSS_PRU_DEBUG_GPR15                                (0x3cU)
#define HW_ICSS_PRU_DEBUG_GPR16                                (0x40U)
#define HW_ICSS_PRU_DEBUG_GPR17                                (0x44U)
#define HW_ICSS_PRU_DEBUG_GPR18                                (0x48U)
#define HW_ICSS_PRU_DEBUG_GPR19                                (0x4cU)
#define HW_ICSS_PRU_DEBUG_GPR20                                (0x50U)
#define HW_ICSS_PRU_DEBUG_GPR21                                (0x54U)
#define HW_ICSS_PRU_DEBUG_GPR22                                (0x58U)
#define HW_ICSS_PRU_DEBUG_GPR23                                (0x5cU)
#define HW_ICSS_PRU_DEBUG_GPR24                                (0x60U)
#define HW_ICSS_PRU_DEBUG_GPR25                                (0x64U)
#define HW_ICSS_PRU_DEBUG_GPR26                                (0x68U)
#define HW_ICSS_PRU_DEBUG_GPR27                                (0x6cU)
#define HW_ICSS_PRU_DEBUG_GPR28                                (0x70U)
#define HW_ICSS_PRU_DEBUG_GPR29                                (0x74U)
#define HW_ICSS_PRU_DEBUG_GPR30                                (0x78U)
#define HW_ICSS_PRU_DEBUG_GPR31                                (0x7cU)
#define HW_ICSS_PRU_DEBUG_CTR0                                 (0x80U)
#define HW_ICSS_PRU_DEBUG_CTR1                                 (0x84U)
#define HW_ICSS_PRU_DEBUG_CTR2                                 (0x88U)
#define HW_ICSS_PRU_DEBUG_CTR3                                 (0x8cU)
#define HW_ICSS_PRU_DEBUG_CTR4                                 (0x90U)
#define HW_ICSS_PRU_DEBUG_CTR5                                 (0x94U)
#define HW_ICSS_PRU_DEBUG_CTR6                                 (0x98U)
#define HW_ICSS_PRU_DEBUG_CTR7                                 (0x9cU)
#define HW_ICSS_PRU_DEBUG_CTR8                                 (0xa0U)
#define HW_ICSS_PRU_DEBUG_CTR9                                 (0xa4U)
#define HW_ICSS_PRU_DEBUG_CTR10                                (0xa8U)
#define HW_ICSS_PRU_DEBUG_CTR11                                (0xacU)
#define HW_ICSS_PRU_DEBUG_CTR12                                (0xb0U)
#define HW_ICSS_PRU_DEBUG_CTR13                                (0xb4U)
#define HW_ICSS_PRU_DEBUG_CTR14                                (0xb8U)
#define HW_ICSS_PRU_DEBUG_CTR15                                (0xbcU)
#define HW_ICSS_PRU_DEBUG_CTR16                                (0xc0U)
#define HW_ICSS_PRU_DEBUG_CTR17                                (0xc4U)
#define HW_ICSS_PRU_DEBUG_CTR18                                (0xc8U)
#define HW_ICSS_PRU_DEBUG_CTR19                                (0xccU)
#define HW_ICSS_PRU_DEBUG_CTR20                                (0xd0U)
#define HW_ICSS_PRU_DEBUG_CTR21                                (0xd4U)
#define HW_ICSS_PRU_DEBUG_CTR22                                (0xd8U)
#define HW_ICSS_PRU_DEBUG_CTR23                                (0xdcU)
#define HW_ICSS_PRU_DEBUG_CTR24                                (0xe0U)
#define HW_ICSS_PRU_DEBUG_CTR25                                (0xe4U)
#define HW_ICSS_PRU_DEBUG_CTR26                                (0xe8U)
#define HW_ICSS_PRU_DEBUG_CTR27                                (0xecU)
#define HW_ICSS_PRU_DEBUG_CTR28                                (0xf0U)
#define HW_ICSS_PRU_DEBUG_CTR29                                (0xf4U)
#define HW_ICSS_PRU_DEBUG_CTR30                                (0xf8U)
#define HW_ICSS_PRU_DEBUG_CTR31                                (0xfcU)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_PRU_DEBUG_GPR0_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR0_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR1_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR1_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR2_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR2_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR3_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR3_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR4_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR4_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR5_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR5_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR6_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR6_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR7_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR7_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR8_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR8_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR9_GP_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_GPR9_GP_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR10_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR10_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR11_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR11_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR12_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR12_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR13_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR13_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR14_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR14_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR15_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR15_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR16_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR16_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR17_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR17_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR18_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR18_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR19_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR19_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR20_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR20_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR21_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR21_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR22_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR22_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR23_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR23_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR24_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR24_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR25_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR25_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR26_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR26_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR27_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR27_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR28_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR28_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR29_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR29_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR30_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR30_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_GPR31_GP_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_GPR31_GP_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR0_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR0_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR1_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR1_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR2_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR2_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR3_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR3_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR4_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR4_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR5_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR5_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR6_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR6_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR7_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR7_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR8_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR8_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR9_CT_SHIFT                        (0U)
#define HW_ICSS_PRU_DEBUG_CTR9_CT_MASK                         (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR10_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR10_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR11_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR11_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR12_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR12_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR13_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR13_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR14_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR14_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR15_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR15_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR16_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR16_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR17_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR17_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR18_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR18_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR19_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR19_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR20_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR20_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR21_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR21_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR22_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR22_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR23_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR23_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR24_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR24_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR25_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR25_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR26_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR26_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR27_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR27_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR28_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR28_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR29_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR29_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR30_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR30_CT_MASK                        (0xffffffffU)

#define HW_ICSS_PRU_DEBUG_CTR31_CT_SHIFT                       (0U)
#define HW_ICSS_PRU_DEBUG_CTR31_CT_MASK                        (0xffffffffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_PRU_DEBUG_H_ */
