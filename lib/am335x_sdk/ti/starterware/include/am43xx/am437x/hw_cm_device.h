/*
* hw_cm_device.h
*
* Register-level header file for CM_DEVICE
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

#ifndef HW_CM_DEVICE_H_
#define HW_CM_DEVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_CM_CLKOUT1_CTRL                                        (0x0U)
#define PRCM_CM_DLL_CTRL                                            (0x4U)
#define PRCM_CM_CLKOUT2_CTRL                                        (0x8U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SHIFT                                    (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_MASK                                     (0x00000007U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL0                                      (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL1                                      (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL2                                      (2U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL3                                      (3U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL4                                      (4U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL5                                      (5U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_SHIFT                                      (4U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_MASK                                       (0x00000070U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV1                                        (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV2                                        (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV3                                        (2U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV4                                        (3U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV5                                        (4U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV6                                        (5U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV7                                        (6U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV8                                        (7U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SHIFT                                        (24U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_MASK                                         (0x01000000U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SEL0                                          (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SEL1                                          (1U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SHIFT                                        (16U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_MASK                                         (0x00030000U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL0                                          (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL1                                          (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL2                                          (2U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL3                                          (3U)

#define PRCM_CM_CLKOUT1_CTRL_RSVD1_SHIFT                                                (18U)
#define PRCM_CM_CLKOUT1_CTRL_RSVD1_MASK                                                 (0x000c0000U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_SHIFT                                       (20U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_MASK                                        (0x00300000U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV1                                         (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV2                                         (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV3                                         (2U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV4                                         (3U)

#define PRCM_CM_CLKOUT1_CTRL_RSVD2_SHIFT                                                (22U)
#define PRCM_CM_CLKOUT1_CTRL_RSVD2_MASK                                                 (0x00400000U)

#define PRCM_CM_CLKOUT1_CTRL_RSVD3_SHIFT                                                (25U)
#define PRCM_CM_CLKOUT1_CTRL_RSVD3_MASK                                                 (0xfe000000U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_SHIFT                                      (8U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_MASK                                       (0x00000700U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV1                                    (0U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV2                                    (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV4                                    (2U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV8                                    (3U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV16                                   (4U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_RESVD2                                      (6U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_RESVD3                                      (7U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV32                                   (5U)

#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1EN_SHIFT                                            (23U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1EN_MASK                                             (0x00800000U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1EN_EN                                                (1U)
#define PRCM_CM_CLKOUT1_CTRL_CLKOUT1EN_DIS                                               (0U)

#define PRCM_CM_DLL_CTRL_OVERRIDE_SHIFT                                                 (0U)
#define PRCM_CM_DLL_CTRL_OVERRIDE_MASK                                                  (0x00000001U)
#define PRCM_CM_DLL_CTRL_OVERRIDE_NO_OVR                                                 (0U)
#define PRCM_CM_DLL_CTRL_OVERRIDE_OVR                                                    (1U)

#define PRCM_CM_DLL_CTRL_RESET_SHIFT                                                    (1U)
#define PRCM_CM_DLL_CTRL_RESET_MASK                                                     (0x00000002U)
#define PRCM_CM_DLL_CTRL_RESET_NORESET                                                   (0U)
#define PRCM_CM_DLL_CTRL_RESET                                                           (1U)

#define PRCM_CM_DLL_CTRL_READYST_SHIFT                                                  (2U)
#define PRCM_CM_DLL_CTRL_READYST_MASK                                                   (0x00000004U)
#define PRCM_CM_DLL_CTRL_READYST_READY                                                   (1U)
#define PRCM_CM_DLL_CTRL_READYST_NOT_READY                                               (0U)

#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SHIFT                                        (0U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_MASK                                         (0x00000007U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL0                                          (0U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL1                                          (1U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL2                                          (2U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL3                                          (3U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL4                                          (4U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL5                                          (5U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL6                                          (6U)

#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_SHIFT                                           (4U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_MASK                                            (0x00000070U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV1                                             (0U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV2                                             (1U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV3                                             (2U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV4                                             (3U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV5                                             (4U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV6                                             (5U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV7                                             (6U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV8                                             (7U)

#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2EN_SHIFT                                            (16U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2EN_MASK                                             (0x00010000U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2EN_EN                                                (1U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2EN_DIS                                               (0U)

#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_SHIFT                                       (8U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_MASK                                        (0x00000700U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV1                                     (0U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV2                                     (1U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV4                                     (2U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV8                                     (3U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV16                                    (4U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_RESVD2                                       (6U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_RESVD3                                       (7U)
#define PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV32                                    (5U)

#define PRCM_CM_CLKOUT2_CTRL_RSVD1_SHIFT                                                (3U)
#define PRCM_CM_CLKOUT2_CTRL_RSVD1_MASK                                                 (0x00000008U)

#define PRCM_CM_CLKOUT2_CTRL_RSVD2_SHIFT                                                (7U)
#define PRCM_CM_CLKOUT2_CTRL_RSVD2_MASK                                                 (0x00000080U)

#define PRCM_CM_CLKOUT2_CTRL_RSVD3_SHIFT                                                (11U)
#define PRCM_CM_CLKOUT2_CTRL_RSVD3_MASK                                                 (0x0000f800U)

#define PRCM_CM_CLKOUT2_CTRL_RSVD4_SHIFT                                                (17U)
#define PRCM_CM_CLKOUT2_CTRL_RSVD4_MASK                                                 (0xfffe0000U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CM_DEVICE_H_ */

