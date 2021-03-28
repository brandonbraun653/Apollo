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
#ifndef CSLR_CSTF_H_
#define CSLR_CSTF_H_

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
    volatile Uint32 FCTL;
    volatile Uint32 PCTL;
    volatile Uint8  RSVD0[3812];
    volatile Uint32 ITATBDATA0;
    volatile Uint32 ITATBCTR2;
    volatile Uint32 ITATBCTR1;
    volatile Uint32 ITATBCTR0;
    volatile Uint8  RSVD1[4];
    volatile Uint32 ITCTRL;
    volatile Uint8  RSVD2[156];
    volatile Uint32 CLAIMSET;
    volatile Uint32 CLAIMCLR;
    volatile Uint8  RSVD3[8];
    volatile Uint32 LOCKACCESS;
    volatile Uint32 LOCKSTS;
    volatile Uint32 AUTHSTS;
    volatile Uint8  RSVD4[12];
    volatile Uint32 DEVID;
    volatile Uint32 DEVTYPE;
    volatile Uint32 PERIPHID4;
    volatile Uint32 PERIPHID5;
    volatile Uint32 PERIPHID6;
    volatile Uint32 PERIPHID7;
    volatile Uint32 PERIPHID0;
    volatile Uint32 PERIPHID1;
    volatile Uint32 PERIPHID2;
    volatile Uint32 PERIPHID3;
    volatile Uint32 COMPONID0;
    volatile Uint32 COMPONID1;
    volatile Uint32 COMPONID2;
    volatile Uint32 COMPONID3;
} CSL_CstfRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Funnel Control Register */
#define CSL_CSTF_FCTL                                           (0x0U)

/* Priority Control Register */
#define CSL_CSTF_PCTL                                           (0x4U)

/* Integration Register */
#define CSL_CSTF_ITATBDATA0                                     (0xEECU)

/* Integration Register */
#define CSL_CSTF_ITATBCTR2                                      (0xEF0U)

/* Integration Register */
#define CSL_CSTF_ITATBCTR1                                      (0xEF4U)

/* Integration Register */
#define CSL_CSTF_ITATBCTR0                                      (0xEF8U)

/* Integration Mode Control Register */
#define CSL_CSTF_ITCTRL                                         (0xF00U)

/* Claim Tag Set */
#define CSL_CSTF_CLAIMSET                                       (0xFA0U)

/* Claim Tag Clear */
#define CSL_CSTF_CLAIMCLR                                       (0xFA4U)

/* Lock Access */
#define CSL_CSTF_LOCKACCESS                                     (0xFB0U)

/* Lock Status */
#define CSL_CSTF_LOCKSTS                                        (0xFB4U)

/* Authentification status */
#define CSL_CSTF_AUTHSTS                                        (0xFB8U)

/* Device ID */
#define CSL_CSTF_DEVID                                          (0xFC8U)

/* Device type identifier */
#define CSL_CSTF_DEVTYPE                                        (0xFCCU)

/* Peripheral ID4 */
#define CSL_CSTF_PERIPHID4                                      (0xFD0U)

/* Peripheral ID5 */
#define CSL_CSTF_PERIPHID5                                      (0xFD4U)

/* Peripheral ID6 */
#define CSL_CSTF_PERIPHID6                                      (0xFD8U)

/* Peripheral ID7 */
#define CSL_CSTF_PERIPHID7                                      (0xFDCU)

/* Peripheral ID0 */
#define CSL_CSTF_PERIPHID0                                      (0xFE0U)

/* Peripheral ID1 */
#define CSL_CSTF_PERIPHID1                                      (0xFE4U)

/* Peripheral ID2 */
#define CSL_CSTF_PERIPHID2                                      (0xFE8U)

/* Peripheral ID3 */
#define CSL_CSTF_PERIPHID3                                      (0xFECU)

/* Component ID0 */
#define CSL_CSTF_COMPONID0                                      (0xFF0U)

/* Component ID1 */
#define CSL_CSTF_COMPONID1                                      (0xFF4U)

/* Component ID2 */
#define CSL_CSTF_COMPONID2                                      (0xFF8U)

/* Component ID3 */
#define CSL_CSTF_COMPONID3                                      (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* FCTL */

#define CSL_CSTF_FCTL_ENS0_MASK                                 (0x00000001U)
#define CSL_CSTF_FCTL_ENS0_SHIFT                                (0U)
#define CSL_CSTF_FCTL_ENS0_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS0_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS1_MASK                                 (0x00000002U)
#define CSL_CSTF_FCTL_ENS1_SHIFT                                (1U)
#define CSL_CSTF_FCTL_ENS1_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS1_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS2_MASK                                 (0x00000004U)
#define CSL_CSTF_FCTL_ENS2_SHIFT                                (2U)
#define CSL_CSTF_FCTL_ENS2_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS2_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS3_MASK                                 (0x00000008U)
#define CSL_CSTF_FCTL_ENS3_SHIFT                                (3U)
#define CSL_CSTF_FCTL_ENS3_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS3_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS4_MASK                                 (0x00000010U)
#define CSL_CSTF_FCTL_ENS4_SHIFT                                (4U)
#define CSL_CSTF_FCTL_ENS4_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS4_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS5_MASK                                 (0x00000020U)
#define CSL_CSTF_FCTL_ENS5_SHIFT                                (5U)
#define CSL_CSTF_FCTL_ENS5_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS5_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS6_MASK                                 (0x00000040U)
#define CSL_CSTF_FCTL_ENS6_SHIFT                                (6U)
#define CSL_CSTF_FCTL_ENS6_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS6_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_ENS7_MASK                                 (0x00000080U)
#define CSL_CSTF_FCTL_ENS7_SHIFT                                (7U)
#define CSL_CSTF_FCTL_ENS7_RESETVAL                             (0x00000000U)
#define CSL_CSTF_FCTL_ENS7_MAX                                  (0x00000001U)

#define CSL_CSTF_FCTL_HT_MASK                                   (0x00000F00U)
#define CSL_CSTF_FCTL_HT_SHIFT                                  (8U)
#define CSL_CSTF_FCTL_HT_RESETVAL                               (0x00000003U)
#define CSL_CSTF_FCTL_HT_MAX                                    (0x0000000fU)

#define CSL_CSTF_FCTL_RESETVAL                                  (0x00000300U)

/* PCTL */

#define CSL_CSTF_PCTL_PRIPORT0_MASK                             (0x00000007U)
#define CSL_CSTF_PCTL_PRIPORT0_SHIFT                            (0U)
#define CSL_CSTF_PCTL_PRIPORT0_RESETVAL                         (0x00000000U)
#define CSL_CSTF_PCTL_PRIPORT0_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT1_MASK                             (0x00000038U)
#define CSL_CSTF_PCTL_PRIPORT1_SHIFT                            (3U)
#define CSL_CSTF_PCTL_PRIPORT1_RESETVAL                         (0x00000001U)
#define CSL_CSTF_PCTL_PRIPORT1_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT2_MASK                             (0x000001C0U)
#define CSL_CSTF_PCTL_PRIPORT2_SHIFT                            (6U)
#define CSL_CSTF_PCTL_PRIPORT2_RESETVAL                         (0x00000002U)
#define CSL_CSTF_PCTL_PRIPORT2_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT3_MASK                             (0x00000E00U)
#define CSL_CSTF_PCTL_PRIPORT3_SHIFT                            (9U)
#define CSL_CSTF_PCTL_PRIPORT3_RESETVAL                         (0x00000003U)
#define CSL_CSTF_PCTL_PRIPORT3_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT4_MASK                             (0x00007000U)
#define CSL_CSTF_PCTL_PRIPORT4_SHIFT                            (12U)
#define CSL_CSTF_PCTL_PRIPORT4_RESETVAL                         (0x00000004U)
#define CSL_CSTF_PCTL_PRIPORT4_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT5_MASK                             (0x00038000U)
#define CSL_CSTF_PCTL_PRIPORT5_SHIFT                            (15U)
#define CSL_CSTF_PCTL_PRIPORT5_RESETVAL                         (0x00000005U)
#define CSL_CSTF_PCTL_PRIPORT5_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT6_MASK                             (0x001C0000U)
#define CSL_CSTF_PCTL_PRIPORT6_SHIFT                            (18U)
#define CSL_CSTF_PCTL_PRIPORT6_RESETVAL                         (0x00000006U)
#define CSL_CSTF_PCTL_PRIPORT6_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_PRIPORT7_MASK                             (0x00E00000U)
#define CSL_CSTF_PCTL_PRIPORT7_SHIFT                            (21U)
#define CSL_CSTF_PCTL_PRIPORT7_RESETVAL                         (0x00000007U)
#define CSL_CSTF_PCTL_PRIPORT7_MAX                              (0x00000007U)

#define CSL_CSTF_PCTL_RESETVAL                                  (0x00fac688U)

/* ITATBDATA0 */

#define CSL_CSTF_ITATBDATA0_ATDATA0_MASK                        (0x00000001U)
#define CSL_CSTF_ITATBDATA0_ATDATA0_SHIFT                       (0U)
#define CSL_CSTF_ITATBDATA0_ATDATA0_RESETVAL                    (0x00000000U)
#define CSL_CSTF_ITATBDATA0_ATDATA0_MAX                         (0x00000001U)

#define CSL_CSTF_ITATBDATA0_ATDATA7_MASK                        (0x00000002U)
#define CSL_CSTF_ITATBDATA0_ATDATA7_SHIFT                       (1U)
#define CSL_CSTF_ITATBDATA0_ATDATA7_RESETVAL                    (0x00000000U)
#define CSL_CSTF_ITATBDATA0_ATDATA7_MAX                         (0x00000001U)

#define CSL_CSTF_ITATBDATA0_ATDATA15_MASK                       (0x00000004U)
#define CSL_CSTF_ITATBDATA0_ATDATA15_SHIFT                      (2U)
#define CSL_CSTF_ITATBDATA0_ATDATA15_RESETVAL                   (0x00000000U)
#define CSL_CSTF_ITATBDATA0_ATDATA15_MAX                        (0x00000001U)

#define CSL_CSTF_ITATBDATA0_ATDATA23_MASK                       (0x00000008U)
#define CSL_CSTF_ITATBDATA0_ATDATA23_SHIFT                      (3U)
#define CSL_CSTF_ITATBDATA0_ATDATA23_RESETVAL                   (0x00000000U)
#define CSL_CSTF_ITATBDATA0_ATDATA23_MAX                        (0x00000001U)

#define CSL_CSTF_ITATBDATA0_ATDATA31_MASK                       (0x00000010U)
#define CSL_CSTF_ITATBDATA0_ATDATA31_SHIFT                      (4U)
#define CSL_CSTF_ITATBDATA0_ATDATA31_RESETVAL                   (0x00000000U)
#define CSL_CSTF_ITATBDATA0_ATDATA31_MAX                        (0x00000001U)

#define CSL_CSTF_ITATBDATA0_RESETVAL                            (0x00000000U)

/* ITATBCTR2 */

#define CSL_CSTF_ITATBCTR2_ATREADY_MASK                         (0x00000001U)
#define CSL_CSTF_ITATBCTR2_ATREADY_SHIFT                        (0U)
#define CSL_CSTF_ITATBCTR2_ATREADY_RESETVAL                     (0x00000000U)
#define CSL_CSTF_ITATBCTR2_ATREADY_MAX                          (0x00000001U)

#define CSL_CSTF_ITATBCTR2_AFVALID_MASK                         (0x00000002U)
#define CSL_CSTF_ITATBCTR2_AFVALID_SHIFT                        (1U)
#define CSL_CSTF_ITATBCTR2_AFVALID_RESETVAL                     (0x00000000U)
#define CSL_CSTF_ITATBCTR2_AFVALID_MAX                          (0x00000001U)

#define CSL_CSTF_ITATBCTR2_RESETVAL                             (0x00000000U)

/* ITATBCTR1 */

#define CSL_CSTF_ITATBCTR1_ATID_MASK                            (0x0000007FU)
#define CSL_CSTF_ITATBCTR1_ATID_SHIFT                           (0U)
#define CSL_CSTF_ITATBCTR1_ATID_RESETVAL                        (0x00000000U)
#define CSL_CSTF_ITATBCTR1_ATID_MAX                             (0x0000007fU)

#define CSL_CSTF_ITATBCTR1_RESETVAL                             (0x00000000U)

/* ITATBCTR0 */

#define CSL_CSTF_ITATBCTR0_ATVALIDS_MASK                        (0x00000001U)
#define CSL_CSTF_ITATBCTR0_ATVALIDS_SHIFT                       (0U)
#define CSL_CSTF_ITATBCTR0_ATVALIDS_RESETVAL                    (0x00000000U)
#define CSL_CSTF_ITATBCTR0_ATVALIDS_MAX                         (0x00000001U)

#define CSL_CSTF_ITATBCTR0_AFREADYS_MASK                        (0x00000002U)
#define CSL_CSTF_ITATBCTR0_AFREADYS_SHIFT                       (1U)
#define CSL_CSTF_ITATBCTR0_AFREADYS_RESETVAL                    (0x00000000U)
#define CSL_CSTF_ITATBCTR0_AFREADYS_MAX                         (0x00000001U)

#define CSL_CSTF_ITATBCTR0_ATBYTES_MASK                         (0x00000300U)
#define CSL_CSTF_ITATBCTR0_ATBYTES_SHIFT                        (8U)
#define CSL_CSTF_ITATBCTR0_ATBYTES_RESETVAL                     (0x00000000U)
#define CSL_CSTF_ITATBCTR0_ATBYTES_MAX                          (0x00000003U)

#define CSL_CSTF_ITATBCTR0_RESETVAL                             (0x00000000U)

/* ITCTRL */

#define CSL_CSTF_ITCTRL_ITCTRL_MASK                             (0x00000001U)
#define CSL_CSTF_ITCTRL_ITCTRL_SHIFT                            (0U)
#define CSL_CSTF_ITCTRL_ITCTRL_RESETVAL                         (0x00000000U)
#define CSL_CSTF_ITCTRL_ITCTRL_MAX                              (0x00000001U)

#define CSL_CSTF_ITCTRL_RESETVAL                                (0x00000000U)

/* CLAIMSET */

#define CSL_CSTF_CLAIMSET_CLAIMTAGSET_MASK                      (0x0000000FU)
#define CSL_CSTF_CLAIMSET_CLAIMTAGSET_SHIFT                     (0U)
#define CSL_CSTF_CLAIMSET_CLAIMTAGSET_RESETVAL                  (0x0000000fU)
#define CSL_CSTF_CLAIMSET_CLAIMTAGSET_MAX                       (0x0000000fU)

#define CSL_CSTF_CLAIMSET_RESETVAL                              (0x0000000fU)

/* CLAIMCLR */

#define CSL_CSTF_CLAIMCLR_CLAIMTAGCLR_MASK                      (0x0000000FU)
#define CSL_CSTF_CLAIMCLR_CLAIMTAGCLR_SHIFT                     (0U)
#define CSL_CSTF_CLAIMCLR_CLAIMTAGCLR_RESETVAL                  (0x00000000U)
#define CSL_CSTF_CLAIMCLR_CLAIMTAGCLR_MAX                       (0x0000000fU)

#define CSL_CSTF_CLAIMCLR_RESETVAL                              (0x00000000U)

/* LOCKACCESS */

#define CSL_CSTF_LOCKACCESS_WRITEACCESSCODE_MASK                (0xFFFFFFFFU)
#define CSL_CSTF_LOCKACCESS_WRITEACCESSCODE_SHIFT               (0U)
#define CSL_CSTF_LOCKACCESS_WRITEACCESSCODE_RESETVAL            (0x00000000U)
#define CSL_CSTF_LOCKACCESS_WRITEACCESSCODE_MAX                 (0xffffffffU)

#define CSL_CSTF_LOCKACCESS_RESETVAL                            (0x00000000U)

/* LOCKSTS */

#define CSL_CSTF_LOCKSTS_IMP_MASK                               (0x00000001U)
#define CSL_CSTF_LOCKSTS_IMP_SHIFT                              (0U)
#define CSL_CSTF_LOCKSTS_IMP_RESETVAL                           (0x00000000U)
#define CSL_CSTF_LOCKSTS_IMP_MAX                                (0x00000001U)

#define CSL_CSTF_LOCKSTS_STS_MASK                               (0x00000002U)
#define CSL_CSTF_LOCKSTS_STS_SHIFT                              (1U)
#define CSL_CSTF_LOCKSTS_STS_RESETVAL                           (0x00000000U)
#define CSL_CSTF_LOCKSTS_STS_MAX                                (0x00000001U)

#define CSL_CSTF_LOCKSTS_EIGHT_BIT_MASK                         (0x00000004U)
#define CSL_CSTF_LOCKSTS_EIGHT_BIT_SHIFT                        (2U)
#define CSL_CSTF_LOCKSTS_EIGHT_BIT_RESETVAL                     (0x00000000U)
#define CSL_CSTF_LOCKSTS_EIGHT_BIT_MAX                          (0x00000001U)

#define CSL_CSTF_LOCKSTS_RESETVAL                               (0x00000000U)

/* AUTHSTS */

#define CSL_CSTF_AUTHSTS_NS_INVASIVE_DBG_MASK                   (0x00000003U)
#define CSL_CSTF_AUTHSTS_NS_INVASIVE_DBG_SHIFT                  (0U)
#define CSL_CSTF_AUTHSTS_NS_INVASIVE_DBG_RESETVAL               (0x00000000U)
#define CSL_CSTF_AUTHSTS_NS_INVASIVE_DBG_MAX                    (0x00000003U)

#define CSL_CSTF_AUTHSTS_NS_NONINVASIVE_DBG_MASK                (0x0000000CU)
#define CSL_CSTF_AUTHSTS_NS_NONINVASIVE_DBG_SHIFT               (2U)
#define CSL_CSTF_AUTHSTS_NS_NONINVASIVE_DBG_RESETVAL            (0x00000000U)
#define CSL_CSTF_AUTHSTS_NS_NONINVASIVE_DBG_MAX                 (0x00000003U)

#define CSL_CSTF_AUTHSTS_SECURE_INVASIVE_DBG_MASK               (0x00000030U)
#define CSL_CSTF_AUTHSTS_SECURE_INVASIVE_DBG_SHIFT              (4U)
#define CSL_CSTF_AUTHSTS_SECURE_INVASIVE_DBG_RESETVAL           (0x00000000U)
#define CSL_CSTF_AUTHSTS_SECURE_INVASIVE_DBG_MAX                (0x00000003U)

#define CSL_CSTF_AUTHSTS_SECURE_NONINVASIVE_DBG_MASK            (0x000000C0U)
#define CSL_CSTF_AUTHSTS_SECURE_NONINVASIVE_DBG_SHIFT           (6U)
#define CSL_CSTF_AUTHSTS_SECURE_NONINVASIVE_DBG_RESETVAL        (0x00000000U)
#define CSL_CSTF_AUTHSTS_SECURE_NONINVASIVE_DBG_MAX             (0x00000003U)

#define CSL_CSTF_AUTHSTS_RESETVAL                               (0x00000000U)

/* DEVID */

#define CSL_CSTF_DEVID_DEVICEID_MASK                            (0xFFFFFFFFU)
#define CSL_CSTF_DEVID_DEVICEID_SHIFT                           (0U)
#define CSL_CSTF_DEVID_DEVICEID_RESETVAL                        (0x00000028U)
#define CSL_CSTF_DEVID_DEVICEID_MAX                             (0xffffffffU)

#define CSL_CSTF_DEVID_RESETVAL                                 (0x00000028U)

/* DEVTYPE */

#define CSL_CSTF_DEVTYPE_MAIN_TYPE_CLASS_MASK                   (0x0000000FU)
#define CSL_CSTF_DEVTYPE_MAIN_TYPE_CLASS_SHIFT                  (0U)
#define CSL_CSTF_DEVTYPE_MAIN_TYPE_CLASS_RESETVAL               (0x00000002U)
#define CSL_CSTF_DEVTYPE_MAIN_TYPE_CLASS_MAX                    (0x0000000fU)

#define CSL_CSTF_DEVTYPE_SUB_TYPE_MASK                          (0x000000F0U)
#define CSL_CSTF_DEVTYPE_SUB_TYPE_SHIFT                         (4U)
#define CSL_CSTF_DEVTYPE_SUB_TYPE_RESETVAL                      (0x00000001U)
#define CSL_CSTF_DEVTYPE_SUB_TYPE_MAX                           (0x0000000fU)

#define CSL_CSTF_DEVTYPE_RESETVAL                               (0x00000012U)

/* PERIPHID4 */

#define CSL_CSTF_PERIPHID4_JEP106_CONTINUATION_CODE_MASK        (0x0000000FU)
#define CSL_CSTF_PERIPHID4_JEP106_CONTINUATION_CODE_SHIFT       (0U)
#define CSL_CSTF_PERIPHID4_JEP106_CONTINUATION_CODE_RESETVAL    (0x00000004U)
#define CSL_CSTF_PERIPHID4_JEP106_CONTINUATION_CODE_MAX         (0x0000000fU)

#define CSL_CSTF_PERIPHID4_FOURKB_COUNT_MASK                    (0x000000F0U)
#define CSL_CSTF_PERIPHID4_FOURKB_COUNT_SHIFT                   (4U)
#define CSL_CSTF_PERIPHID4_FOURKB_COUNT_RESETVAL                (0x00000000U)
#define CSL_CSTF_PERIPHID4_FOURKB_COUNT_MAX                     (0x0000000fU)

#define CSL_CSTF_PERIPHID4_RESETVAL                             (0x00000004U)

/* PERIPHID5 */

#define CSL_CSTF_PERIPHID5_RESETVAL                             (0x00000000U)

/* PERIPHID6 */

#define CSL_CSTF_PERIPHID6_RESETVAL                             (0x00000000U)

/* PERIPHID7 */

#define CSL_CSTF_PERIPHID7_RESETVAL                             (0x00000000U)

/* PERIPHID0 */

#define CSL_CSTF_PERIPHID0_PART_NUMBER_0_MASK                   (0x000000FFU)
#define CSL_CSTF_PERIPHID0_PART_NUMBER_0_SHIFT                  (0U)
#define CSL_CSTF_PERIPHID0_PART_NUMBER_0_RESETVAL               (0x00000008U)
#define CSL_CSTF_PERIPHID0_PART_NUMBER_0_MAX                    (0x000000ffU)

#define CSL_CSTF_PERIPHID0_RESETVAL                             (0x00000008U)

/* PERIPHID1 */

#define CSL_CSTF_PERIPHID1_PART_NUMBER_1_MASK                   (0x0000000FU)
#define CSL_CSTF_PERIPHID1_PART_NUMBER_1_SHIFT                  (0U)
#define CSL_CSTF_PERIPHID1_PART_NUMBER_1_RESETVAL               (0x00000009U)
#define CSL_CSTF_PERIPHID1_PART_NUMBER_1_MAX                    (0x0000000fU)

#define CSL_CSTF_PERIPHID1_JEP106_IDENTITY_CODE_MASK            (0x000000F0U)
#define CSL_CSTF_PERIPHID1_JEP106_IDENTITY_CODE_SHIFT           (4U)
#define CSL_CSTF_PERIPHID1_JEP106_IDENTITY_CODE_RESETVAL        (0x0000000bU)
#define CSL_CSTF_PERIPHID1_JEP106_IDENTITY_CODE_MAX             (0x0000000fU)

#define CSL_CSTF_PERIPHID1_RESETVAL                             (0x000000b9U)

/* PERIPHID2 */

#define CSL_CSTF_PERIPHID2_JEP106_IDENTITY_MASK                 (0x00000007U)
#define CSL_CSTF_PERIPHID2_JEP106_IDENTITY_SHIFT                (0U)
#define CSL_CSTF_PERIPHID2_JEP106_IDENTITY_RESETVAL             (0x00000003U)
#define CSL_CSTF_PERIPHID2_JEP106_IDENTITY_MAX                  (0x00000007U)

#define CSL_CSTF_PERIPHID2_JEP106_EN_MASK                       (0x00000008U)
#define CSL_CSTF_PERIPHID2_JEP106_EN_SHIFT                      (3U)
#define CSL_CSTF_PERIPHID2_JEP106_EN_RESETVAL                   (0x00000001U)
#define CSL_CSTF_PERIPHID2_JEP106_EN_MAX                        (0x00000001U)

#define CSL_CSTF_PERIPHID2_REVISION_MASK                        (0x000000F0U)
#define CSL_CSTF_PERIPHID2_REVISION_SHIFT                       (4U)
#define CSL_CSTF_PERIPHID2_REVISION_RESETVAL                    (0x00000000U)
#define CSL_CSTF_PERIPHID2_REVISION_MAX                         (0x0000000fU)

#define CSL_CSTF_PERIPHID2_RESETVAL                             (0x0000000bU)

/* PERIPHID3 */

#define CSL_CSTF_PERIPHID3_CUSTOMER_MODIFIED_MASK               (0x0000000FU)
#define CSL_CSTF_PERIPHID3_CUSTOMER_MODIFIED_SHIFT              (0U)
#define CSL_CSTF_PERIPHID3_CUSTOMER_MODIFIED_RESETVAL           (0x00000000U)
#define CSL_CSTF_PERIPHID3_CUSTOMER_MODIFIED_MAX                (0x0000000fU)

#define CSL_CSTF_PERIPHID3_REVAND_MASK                          (0x000000F0U)
#define CSL_CSTF_PERIPHID3_REVAND_SHIFT                         (4U)
#define CSL_CSTF_PERIPHID3_REVAND_RESETVAL                      (0x00000000U)
#define CSL_CSTF_PERIPHID3_REVAND_MAX                           (0x0000000fU)

#define CSL_CSTF_PERIPHID3_RESETVAL                             (0x00000000U)

/* COMPONID0 */

#define CSL_CSTF_COMPONID0_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSTF_COMPONID0_PREAMBLE_SHIFT                       (0U)
#define CSL_CSTF_COMPONID0_PREAMBLE_RESETVAL                    (0x0000000dU)
#define CSL_CSTF_COMPONID0_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSTF_COMPONID0_RESETVAL                             (0x0000000dU)

/* COMPONID1 */

#define CSL_CSTF_COMPONID1_PREAMBLE_MASK                        (0x0000000FU)
#define CSL_CSTF_COMPONID1_PREAMBLE_SHIFT                       (0U)
#define CSL_CSTF_COMPONID1_PREAMBLE_RESETVAL                    (0x00000000U)
#define CSL_CSTF_COMPONID1_PREAMBLE_MAX                         (0x0000000fU)

#define CSL_CSTF_COMPONID1_COMPONENT_CLASS_MASK                 (0x000000F0U)
#define CSL_CSTF_COMPONID1_COMPONENT_CLASS_SHIFT                (4U)
#define CSL_CSTF_COMPONID1_COMPONENT_CLASS_RESETVAL             (0x00000009U)
#define CSL_CSTF_COMPONID1_COMPONENT_CLASS_MAX                  (0x0000000fU)

#define CSL_CSTF_COMPONID1_RESETVAL                             (0x00000090U)

/* COMPONID2 */

#define CSL_CSTF_COMPONID2_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSTF_COMPONID2_PREAMBLE_SHIFT                       (0U)
#define CSL_CSTF_COMPONID2_PREAMBLE_RESETVAL                    (0x00000005U)
#define CSL_CSTF_COMPONID2_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSTF_COMPONID2_RESETVAL                             (0x00000005U)

/* COMPONID3 */

#define CSL_CSTF_COMPONID3_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSTF_COMPONID3_PREAMBLE_SHIFT                       (0U)
#define CSL_CSTF_COMPONID3_PREAMBLE_RESETVAL                    (0x000000b1U)
#define CSL_CSTF_COMPONID3_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSTF_COMPONID3_RESETVAL                             (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
