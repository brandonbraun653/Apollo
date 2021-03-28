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
#ifndef CSLR_MLBIP_H_
#define CSLR_MLBIP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for mmr_generated_address_block
**************************************************************************/
typedef struct {
    volatile Uint32 MLBC0;
    volatile Uint8  RSVD0[4];
    volatile Uint32 MLBPC0;
    volatile Uint32 MS0;
    volatile Uint8  RSVD1[4];
    volatile Uint32 MS1;
    volatile Uint8  RSVD2[8];
    volatile Uint32 MSS;
    volatile Uint32 MSD;
    volatile Uint8  RSVD3[4];
    volatile Uint32 MIEN;
    volatile Uint8  RSVD4[4];
    volatile Uint32 MLBPC2;
    volatile Uint32 MLBPC1;
    volatile Uint32 MLBC1;
    volatile Uint8  RSVD5[64];
    volatile Uint32 HCTL;
    volatile Uint8  RSVD6[4];
    volatile Uint32 HCMR0;
    volatile Uint32 HCMR1;
    volatile Uint32 HCER0;
    volatile Uint32 HCER1;
    volatile Uint32 HCBR0;
    volatile Uint32 HCBR1;
    volatile Uint8  RSVD7[32];
    volatile Uint32 MDAT0;
    volatile Uint32 MDAT1;
    volatile Uint32 MDAT2;
    volatile Uint32 MDAT3;
    volatile Uint32 MDWE0;
    volatile Uint32 MDWE1;
    volatile Uint32 MDWE2;
    volatile Uint32 MDWE3;
    volatile Uint32 MCTL;
    volatile Uint32 MADR;
    volatile Uint8  RSVD8[728];
    volatile Uint32 ACTL;
    volatile Uint8  RSVD9[12];
    volatile Uint32 ACSR0;
    volatile Uint32 ACSR1;
    volatile Uint32 ACMR0;
    volatile Uint32 ACMR1;
} CSL_MlbIpRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* MediaLB Control 0 Register */
#define CSL_MLBIP_MLBC0                                         (0x0U)

/* MediaLB 6-pin Control 0 Register */
#define CSL_MLBIP_MLBPC0                                        (0x8U)

/* MediaLB Channel Status 0 Register */
#define CSL_MLBIP_MS0                                           (0xCU)

/* MediaLB Channel Status 1 Register */
#define CSL_MLBIP_MS1                                           (0x14U)

/* MediaLB System Status Register */
#define CSL_MLBIP_MSS                                           (0x20U)

/* MediaLB System Data Register (Read-only) */
#define CSL_MLBIP_MSD                                           (0x24U)

/* MediaLB Interrupt Enable Register */
#define CSL_MLBIP_MIEN                                          (0x2CU)

/* MediaLB 6-pin Control 2 Register */
#define CSL_MLBIP_MLBPC2                                        (0x34U)

/* MediaLB 6-pin Control 1 Register */
#define CSL_MLBIP_MLBPC1                                        (0x38U)

/* MediaLB Control 1 Register */
#define CSL_MLBIP_MLBC1                                         (0x3CU)

/* HBI Control Register */
#define CSL_MLBIP_HCTL                                          (0x80U)

/* HBI Channel Mask 0 Register */
#define CSL_MLBIP_HCMR0                                         (0x88U)

/* HBI Channel Mask 1 Register */
#define CSL_MLBIP_HCMR1                                         (0x8CU)

/* HBI Channel Error 0 Register */
#define CSL_MLBIP_HCER0                                         (0x90U)

/* HBI Channel Error 1 Register */
#define CSL_MLBIP_HCER1                                         (0x94U)

/* HBI Channel Busy 0 Register */
#define CSL_MLBIP_HCBR0                                         (0x98U)

/* HBI Channel Busy 1 Register */
#define CSL_MLBIP_HCBR1                                         (0x9CU)

/* MIF Data 0 Register */
#define CSL_MLBIP_MDAT0                                         (0xC0U)

/* MIF Data 1 Register */
#define CSL_MLBIP_MDAT1                                         (0xC4U)

/* MIF Data 2 Register */
#define CSL_MLBIP_MDAT2                                         (0xC8U)

/* MIF Data 3 Register */
#define CSL_MLBIP_MDAT3                                         (0xCCU)

/* MIF Data Write Enable 0 Register */
#define CSL_MLBIP_MDWE0                                         (0xD0U)

/* MIF Data Write Enable 1 Register */
#define CSL_MLBIP_MDWE1                                         (0xD4U)

/* MIF Data Write Enable 2 Register */
#define CSL_MLBIP_MDWE2                                         (0xD8U)

/* MIF Data Write Enable 3 Register */
#define CSL_MLBIP_MDWE3                                         (0xDCU)

/* MIF Control Register */
#define CSL_MLBIP_MCTL                                          (0xE0U)

/* MIF Address Register */
#define CSL_MLBIP_MADR                                          (0xE4U)

/* AHB Control Register */
#define CSL_MLBIP_ACTL                                          (0x3C0U)

/* AHB Channel Status 0 Register */
#define CSL_MLBIP_ACSR0                                         (0x3D0U)

/* AHB Channel Status 1 Register */
#define CSL_MLBIP_ACSR1                                         (0x3D4U)

/* AHB Channel Mask 0 Register */
#define CSL_MLBIP_ACMR0                                         (0x3D8U)

/* AHB Channel Mask 1 Register */
#define CSL_MLBIP_ACMR1                                         (0x3DCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* MLBC0 */

#define CSL_MLBIP_MLBC0_MLBEN_MASK                              (0x00000001U)
#define CSL_MLBIP_MLBC0_MLBEN_SHIFT                             (0U)
#define CSL_MLBIP_MLBC0_MLBEN_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_MLBEN_MAX                               (0x00000001U)

#define CSL_MLBIP_MLBC0_RSVD1_MASK                              (0x00000002U)
#define CSL_MLBIP_MLBC0_RSVD1_SHIFT                             (1U)
#define CSL_MLBIP_MLBC0_RSVD1_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_RSVD1_MAX                               (0x00000001U)

#define CSL_MLBIP_MLBC0_MLBCLK_MASK                             (0x0000001CU)
#define CSL_MLBIP_MLBC0_MLBCLK_SHIFT                            (2U)
#define CSL_MLBIP_MLBC0_MLBCLK_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MLBC0_MLBCLK_MAX                              (0x00000007U)

#define CSL_MLBIP_MLBC0_MLBPEN_MASK                             (0x00000020U)
#define CSL_MLBIP_MLBC0_MLBPEN_SHIFT                            (5U)
#define CSL_MLBIP_MLBC0_MLBPEN_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MLBC0_MLBPEN_MAX                              (0x00000001U)

#define CSL_MLBIP_MLBC0_RSVD2_MASK                              (0x00000040U)
#define CSL_MLBIP_MLBC0_RSVD2_SHIFT                             (6U)
#define CSL_MLBIP_MLBC0_RSVD2_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_RSVD2_MAX                               (0x00000001U)

#define CSL_MLBIP_MLBC0_MLBLK_MASK                              (0x00000080U)
#define CSL_MLBIP_MLBC0_MLBLK_SHIFT                             (7U)
#define CSL_MLBIP_MLBC0_MLBLK_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_MLBLK_MAX                               (0x00000001U)

#define CSL_MLBIP_MLBC0_RSVD3_MASK                              (0x00000F00U)
#define CSL_MLBIP_MLBC0_RSVD3_SHIFT                             (8U)
#define CSL_MLBIP_MLBC0_RSVD3_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_RSVD3_MAX                               (0x0000000fU)

#define CSL_MLBIP_MLBC0_ASYRETRY_MASK                           (0x00001000U)
#define CSL_MLBIP_MLBC0_ASYRETRY_SHIFT                          (12U)
#define CSL_MLBIP_MLBC0_ASYRETRY_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MLBC0_ASYRETRY_MAX                            (0x00000001U)

#define CSL_MLBIP_MLBC0_RSVD4_MASK                              (0x00002000U)
#define CSL_MLBIP_MLBC0_RSVD4_SHIFT                             (13U)
#define CSL_MLBIP_MLBC0_RSVD4_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_RSVD4_MAX                               (0x00000001U)

#define CSL_MLBIP_MLBC0_CTLRETRY_MASK                           (0x00004000U)
#define CSL_MLBIP_MLBC0_CTLRETRY_SHIFT                          (14U)
#define CSL_MLBIP_MLBC0_CTLRETRY_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MLBC0_CTLRETRY_MAX                            (0x00000001U)

#define CSL_MLBIP_MLBC0_FCNT_MASK                               (0x00038000U)
#define CSL_MLBIP_MLBC0_FCNT_SHIFT                              (15U)
#define CSL_MLBIP_MLBC0_FCNT_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MLBC0_FCNT_MAX                                (0x00000007U)

#define CSL_MLBIP_MLBC0_RSVD5_MASK                              (0xFFFC0000U)
#define CSL_MLBIP_MLBC0_RSVD5_SHIFT                             (18U)
#define CSL_MLBIP_MLBC0_RSVD5_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC0_RSVD5_MAX                               (0x00003fffU)

#define CSL_MLBIP_MLBC0_RESETVAL                                (0x00000000U)

/* MLBPC0 */

#define CSL_MLBIP_MLBPC0_RSVD1_MASK                             (0x00000001U)
#define CSL_MLBIP_MLBPC0_RSVD1_SHIFT                            (0U)
#define CSL_MLBIP_MLBPC0_RSVD1_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MLBPC0_RSVD1_MAX                              (0x00000001U)

#define CSL_MLBIP_MLBPC0_MLBCMRES_MASK                          (0x00000002U)
#define CSL_MLBIP_MLBPC0_MLBCMRES_SHIFT                         (1U)
#define CSL_MLBIP_MLBPC0_MLBCMRES_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_MLBPC0_MLBCMRES_MAX                           (0x00000001U)

#define CSL_MLBIP_MLBPC0_RSVD2_MASK                             (0x000007FCU)
#define CSL_MLBIP_MLBPC0_RSVD2_SHIFT                            (2U)
#define CSL_MLBIP_MLBPC0_RSVD2_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MLBPC0_RSVD2_MAX                              (0x000001ffU)

#define CSL_MLBIP_MLBPC0_MCLKHYS_MASK                           (0x00000800U)
#define CSL_MLBIP_MLBPC0_MCLKHYS_SHIFT                          (11U)
#define CSL_MLBIP_MLBPC0_MCLKHYS_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MLBPC0_MCLKHYS_MAX                            (0x00000001U)

#define CSL_MLBIP_MLBPC0_RSVD3_MASK                             (0xFFFFF000U)
#define CSL_MLBIP_MLBPC0_RSVD3_SHIFT                            (12U)
#define CSL_MLBIP_MLBPC0_RSVD3_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MLBPC0_RSVD3_MAX                              (0x000fffffU)

#define CSL_MLBIP_MLBPC0_RESETVAL                               (0x00000000U)

/* MS0 */

#define CSL_MLBIP_MS0_MCS_31_0_MASK                             (0xFFFFFFFFU)
#define CSL_MLBIP_MS0_MCS_31_0_SHIFT                            (0U)
#define CSL_MLBIP_MS0_MCS_31_0_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MS0_MCS_31_0_MAX                              (0xffffffffU)

#define CSL_MLBIP_MS0_RESETVAL                                  (0x00000000U)

/* MS1 */

#define CSL_MLBIP_MS1_MCS_63_32_MASK                            (0xFFFFFFFFU)
#define CSL_MLBIP_MS1_MCS_63_32_SHIFT                           (0U)
#define CSL_MLBIP_MS1_MCS_63_32_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MS1_MCS_63_32_MAX                             (0xffffffffU)

#define CSL_MLBIP_MS1_RESETVAL                                  (0x00000000U)

/* MSS */

#define CSL_MLBIP_MSS_RSTSYSCMD_MASK                            (0x00000001U)
#define CSL_MLBIP_MSS_RSTSYSCMD_SHIFT                           (0U)
#define CSL_MLBIP_MSS_RSTSYSCMD_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MSS_RSTSYSCMD_MAX                             (0x00000001U)

#define CSL_MLBIP_MSS_LKSYSCMD_MASK                             (0x00000002U)
#define CSL_MLBIP_MSS_LKSYSCMD_SHIFT                            (1U)
#define CSL_MLBIP_MSS_LKSYSCMD_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MSS_LKSYSCMD_MAX                              (0x00000001U)

#define CSL_MLBIP_MSS_ULKSYSCMD_MASK                            (0x00000004U)
#define CSL_MLBIP_MSS_ULKSYSCMD_SHIFT                           (2U)
#define CSL_MLBIP_MSS_ULKSYSCMD_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MSS_ULKSYSCMD_MAX                             (0x00000001U)

#define CSL_MLBIP_MSS_CSSYSCMD_MASK                             (0x00000008U)
#define CSL_MLBIP_MSS_CSSYSCMD_SHIFT                            (3U)
#define CSL_MLBIP_MSS_CSSYSCMD_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MSS_CSSYSCMD_MAX                              (0x00000001U)

#define CSL_MLBIP_MSS_SWSYSCMD_MASK                             (0x00000010U)
#define CSL_MLBIP_MSS_SWSYSCMD_SHIFT                            (4U)
#define CSL_MLBIP_MSS_SWSYSCMD_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MSS_SWSYSCMD_MAX                              (0x00000001U)

#define CSL_MLBIP_MSS_SERVREQ_MASK                              (0x00000020U)
#define CSL_MLBIP_MSS_SERVREQ_SHIFT                             (5U)
#define CSL_MLBIP_MSS_SERVREQ_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MSS_SERVREQ_MAX                               (0x00000001U)

#define CSL_MLBIP_MSS_RSVD_MASK                                 (0xFFFFFFC0U)
#define CSL_MLBIP_MSS_RSVD_SHIFT                                (6U)
#define CSL_MLBIP_MSS_RSVD_RESETVAL                             (0x00000000U)
#define CSL_MLBIP_MSS_RSVD_MAX                                  (0x03ffffffU)

#define CSL_MLBIP_MSS_RESETVAL                                  (0x00000000U)

/* MSD */

#define CSL_MLBIP_MSD_SD0_MASK                                  (0x000000FFU)
#define CSL_MLBIP_MSD_SD0_SHIFT                                 (0U)
#define CSL_MLBIP_MSD_SD0_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_MSD_SD0_MAX                                   (0x000000ffU)

#define CSL_MLBIP_MSD_SD1_MASK                                  (0x0000FF00U)
#define CSL_MLBIP_MSD_SD1_SHIFT                                 (8U)
#define CSL_MLBIP_MSD_SD1_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_MSD_SD1_MAX                                   (0x000000ffU)

#define CSL_MLBIP_MSD_SD2_MASK                                  (0x00FF0000U)
#define CSL_MLBIP_MSD_SD2_SHIFT                                 (16U)
#define CSL_MLBIP_MSD_SD2_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_MSD_SD2_MAX                                   (0x000000ffU)

#define CSL_MLBIP_MSD_SD3_MASK                                  (0xFF000000U)
#define CSL_MLBIP_MSD_SD3_SHIFT                                 (24U)
#define CSL_MLBIP_MSD_SD3_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_MSD_SD3_MAX                                   (0x000000ffU)

#define CSL_MLBIP_MSD_RESETVAL                                  (0x00000000U)

/* MIEN */

#define CSL_MLBIP_MIEN_ISOC_PE_MASK                             (0x00000001U)
#define CSL_MLBIP_MIEN_ISOC_PE_SHIFT                            (0U)
#define CSL_MLBIP_MIEN_ISOC_PE_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MIEN_ISOC_PE_MAX                              (0x00000001U)

#define CSL_MLBIP_MIEN_ISOC_BUFO_MASK                           (0x00000002U)
#define CSL_MLBIP_MIEN_ISOC_BUFO_SHIFT                          (1U)
#define CSL_MLBIP_MIEN_ISOC_BUFO_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MIEN_ISOC_BUFO_MAX                            (0x00000001U)

#define CSL_MLBIP_MIEN_RSVD1_MASK                               (0x0000FFFCU)
#define CSL_MLBIP_MIEN_RSVD1_SHIFT                              (2U)
#define CSL_MLBIP_MIEN_RSVD1_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MIEN_RSVD1_MAX                                (0x00003fffU)

#define CSL_MLBIP_MIEN_SYNC_PE_MASK                             (0x00010000U)
#define CSL_MLBIP_MIEN_SYNC_PE_SHIFT                            (16U)
#define CSL_MLBIP_MIEN_SYNC_PE_RESETVAL                         (0x00000000U)
#define CSL_MLBIP_MIEN_SYNC_PE_MAX                              (0x00000001U)

#define CSL_MLBIP_MIEN_ARX_DONE_MASK                            (0x00020000U)
#define CSL_MLBIP_MIEN_ARX_DONE_SHIFT                           (17U)
#define CSL_MLBIP_MIEN_ARX_DONE_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MIEN_ARX_DONE_MAX                             (0x00000001U)

#define CSL_MLBIP_MIEN_ARX_PE_MASK                              (0x00040000U)
#define CSL_MLBIP_MIEN_ARX_PE_SHIFT                             (18U)
#define CSL_MLBIP_MIEN_ARX_PE_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MIEN_ARX_PE_MAX                               (0x00000001U)

#define CSL_MLBIP_MIEN_ARX_BREAK_MASK                           (0x00080000U)
#define CSL_MLBIP_MIEN_ARX_BREAK_SHIFT                          (19U)
#define CSL_MLBIP_MIEN_ARX_BREAK_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MIEN_ARX_BREAK_MAX                            (0x00000001U)

#define CSL_MLBIP_MIEN_ATX_DONE_MASK                            (0x00100000U)
#define CSL_MLBIP_MIEN_ATX_DONE_SHIFT                           (20U)
#define CSL_MLBIP_MIEN_ATX_DONE_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MIEN_ATX_DONE_MAX                             (0x00000001U)

#define CSL_MLBIP_MIEN_ATX_PE_MASK                              (0x00200000U)
#define CSL_MLBIP_MIEN_ATX_PE_SHIFT                             (21U)
#define CSL_MLBIP_MIEN_ATX_PE_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MIEN_ATX_PE_MAX                               (0x00000001U)

#define CSL_MLBIP_MIEN_ATX_BREAK_MASK                           (0x00400000U)
#define CSL_MLBIP_MIEN_ATX_BREAK_SHIFT                          (22U)
#define CSL_MLBIP_MIEN_ATX_BREAK_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MIEN_ATX_BREAK_MAX                            (0x00000001U)

#define CSL_MLBIP_MIEN_RSVD2_MASK                               (0x00800000U)
#define CSL_MLBIP_MIEN_RSVD2_SHIFT                              (23U)
#define CSL_MLBIP_MIEN_RSVD2_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MIEN_RSVD2_MAX                                (0x00000001U)

#define CSL_MLBIP_MIEN_CRX_DONE_MASK                            (0x01000000U)
#define CSL_MLBIP_MIEN_CRX_DONE_SHIFT                           (24U)
#define CSL_MLBIP_MIEN_CRX_DONE_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MIEN_CRX_DONE_MAX                             (0x00000001U)

#define CSL_MLBIP_MIEN_CRX_PE_MASK                              (0x02000000U)
#define CSL_MLBIP_MIEN_CRX_PE_SHIFT                             (25U)
#define CSL_MLBIP_MIEN_CRX_PE_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MIEN_CRX_PE_MAX                               (0x00000001U)

#define CSL_MLBIP_MIEN_CRX_BREAK_MASK                           (0x04000000U)
#define CSL_MLBIP_MIEN_CRX_BREAK_SHIFT                          (26U)
#define CSL_MLBIP_MIEN_CRX_BREAK_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MIEN_CRX_BREAK_MAX                            (0x00000001U)

#define CSL_MLBIP_MIEN_CTX_DONE_MASK                            (0x08000000U)
#define CSL_MLBIP_MIEN_CTX_DONE_SHIFT                           (27U)
#define CSL_MLBIP_MIEN_CTX_DONE_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MIEN_CTX_DONE_MAX                             (0x00000001U)

#define CSL_MLBIP_MIEN_CTX_PE_MASK                              (0x10000000U)
#define CSL_MLBIP_MIEN_CTX_PE_SHIFT                             (28U)
#define CSL_MLBIP_MIEN_CTX_PE_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MIEN_CTX_PE_MAX                               (0x00000001U)

#define CSL_MLBIP_MIEN_CTX_BREAK_MASK                           (0x20000000U)
#define CSL_MLBIP_MIEN_CTX_BREAK_SHIFT                          (29U)
#define CSL_MLBIP_MIEN_CTX_BREAK_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MIEN_CTX_BREAK_MAX                            (0x00000001U)

#define CSL_MLBIP_MIEN_RSVD3_MASK                               (0xC0000000U)
#define CSL_MLBIP_MIEN_RSVD3_SHIFT                              (30U)
#define CSL_MLBIP_MIEN_RSVD3_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MIEN_RSVD3_MAX                                (0x00000003U)

#define CSL_MLBIP_MIEN_RESETVAL                                 (0x00000000U)

/* MLBPC2 */

#define CSL_MLBIP_MLBPC2_UCFG_15_0_MASK                         (0x0000FFFFU)
#define CSL_MLBIP_MLBPC2_UCFG_15_0_SHIFT                        (0U)
#define CSL_MLBIP_MLBPC2_UCFG_15_0_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MLBPC2_UCFG_15_0_MAX                          (0x0000ffffU)

#define CSL_MLBIP_MLBPC2_RSVD_MASK                              (0xFFFF0000U)
#define CSL_MLBIP_MLBPC2_RSVD_SHIFT                             (16U)
#define CSL_MLBIP_MLBPC2_RSVD_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBPC2_RSVD_MAX                               (0x0000ffffU)

#define CSL_MLBIP_MLBPC2_RESETVAL                               (0x00000000U)

/* MLBPC1 */

#define CSL_MLBIP_MLBPC1_SDRCVBIAS_MASK                         (0x0000000FU)
#define CSL_MLBIP_MLBPC1_SDRCVBIAS_SHIFT                        (0U)
#define CSL_MLBIP_MLBPC1_SDRCVBIAS_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MLBPC1_SDRCVBIAS_MAX                          (0x0000000fU)

#define CSL_MLBIP_MLBPC1_SDXMTBIAS_MASK                         (0x000000F0U)
#define CSL_MLBIP_MLBPC1_SDXMTBIAS_SHIFT                        (4U)
#define CSL_MLBIP_MLBPC1_SDXMTBIAS_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MLBPC1_SDXMTBIAS_MAX                          (0x0000000fU)

#define CSL_MLBIP_MLBPC1_CKRCVBIAS_MASK                         (0x00000F00U)
#define CSL_MLBIP_MLBPC1_CKRCVBIAS_SHIFT                        (8U)
#define CSL_MLBIP_MLBPC1_CKRCVBIAS_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MLBPC1_CKRCVBIAS_MAX                          (0x0000000fU)

#define CSL_MLBIP_MLBPC1_RSVD_MASK                              (0xFFFFF000U)
#define CSL_MLBIP_MLBPC1_RSVD_SHIFT                             (12U)
#define CSL_MLBIP_MLBPC1_RSVD_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBPC1_RSVD_MAX                               (0x000fffffU)

#define CSL_MLBIP_MLBPC1_RESETVAL                               (0x00000000U)

/* MLBC1 */

#define CSL_MLBIP_MLBC1_RSVD1_MASK                              (0x0000003FU)
#define CSL_MLBIP_MLBC1_RSVD1_SHIFT                             (0U)
#define CSL_MLBIP_MLBC1_RSVD1_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC1_RSVD1_MAX                               (0x0000003fU)

#define CSL_MLBIP_MLBC1_LOCK_MASK                               (0x00000040U)
#define CSL_MLBIP_MLBC1_LOCK_SHIFT                              (6U)
#define CSL_MLBIP_MLBC1_LOCK_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MLBC1_LOCK_MAX                                (0x00000001U)

#define CSL_MLBIP_MLBC1_CLKM_MASK                               (0x00000080U)
#define CSL_MLBIP_MLBC1_CLKM_SHIFT                              (7U)
#define CSL_MLBIP_MLBC1_CLKM_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_MLBC1_CLKM_MAX                                (0x00000001U)

#define CSL_MLBIP_MLBC1_NDA_MASK                                (0x0000FF00U)
#define CSL_MLBIP_MLBC1_NDA_SHIFT                               (8U)
#define CSL_MLBIP_MLBC1_NDA_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_MLBC1_NDA_MAX                                 (0x000000ffU)

#define CSL_MLBIP_MLBC1_RSVD2_MASK                              (0xFFFF0000U)
#define CSL_MLBIP_MLBC1_RSVD2_SHIFT                             (16U)
#define CSL_MLBIP_MLBC1_RSVD2_RESETVAL                          (0x00000000U)
#define CSL_MLBIP_MLBC1_RSVD2_MAX                               (0x0000ffffU)

#define CSL_MLBIP_MLBC1_RESETVAL                                (0x00000000U)

/* HCTL */

#define CSL_MLBIP_HCTL_RST0_MASK                                (0x00000001U)
#define CSL_MLBIP_HCTL_RST0_SHIFT                               (0U)
#define CSL_MLBIP_HCTL_RST0_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_HCTL_RST0_MAX                                 (0x00000001U)

#define CSL_MLBIP_HCTL_RST1_MASK                                (0x00000002U)
#define CSL_MLBIP_HCTL_RST1_SHIFT                               (1U)
#define CSL_MLBIP_HCTL_RST1_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_HCTL_RST1_MAX                                 (0x00000001U)

#define CSL_MLBIP_HCTL_RSVD1_MASK                               (0x00007FFCU)
#define CSL_MLBIP_HCTL_RSVD1_SHIFT                              (2U)
#define CSL_MLBIP_HCTL_RSVD1_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_HCTL_RSVD1_MAX                                (0x00001fffU)

#define CSL_MLBIP_HCTL_EN_MASK                                  (0x00008000U)
#define CSL_MLBIP_HCTL_EN_SHIFT                                 (15U)
#define CSL_MLBIP_HCTL_EN_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_HCTL_EN_MAX                                   (0x00000001U)

#define CSL_MLBIP_HCTL_RSVD2_MASK                               (0xFFFF0000U)
#define CSL_MLBIP_HCTL_RSVD2_SHIFT                              (16U)
#define CSL_MLBIP_HCTL_RSVD2_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_HCTL_RSVD2_MAX                                (0x0000ffffU)

#define CSL_MLBIP_HCTL_RESETVAL                                 (0x00000000U)

/* HCMR0 */

#define CSL_MLBIP_HCMR0_CHM_31_0_MASK                           (0xFFFFFFFFU)
#define CSL_MLBIP_HCMR0_CHM_31_0_SHIFT                          (0U)
#define CSL_MLBIP_HCMR0_CHM_31_0_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_HCMR0_CHM_31_0_MAX                            (0xffffffffU)

#define CSL_MLBIP_HCMR0_RESETVAL                                (0x00000000U)

/* HCMR1 */

#define CSL_MLBIP_HCMR1_CHM_63_32_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_HCMR1_CHM_63_32_SHIFT                         (0U)
#define CSL_MLBIP_HCMR1_CHM_63_32_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_HCMR1_CHM_63_32_MAX                           (0xffffffffU)

#define CSL_MLBIP_HCMR1_RESETVAL                                (0x00000000U)

/* HCER0 */

#define CSL_MLBIP_HCER0_CERR_31_0_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_HCER0_CERR_31_0_SHIFT                         (0U)
#define CSL_MLBIP_HCER0_CERR_31_0_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_HCER0_CERR_31_0_MAX                           (0xffffffffU)

#define CSL_MLBIP_HCER0_RESETVAL                                (0x00000000U)

/* HCER1 */

#define CSL_MLBIP_HCER1_CERR_63_32_MASK                         (0xFFFFFFFFU)
#define CSL_MLBIP_HCER1_CERR_63_32_SHIFT                        (0U)
#define CSL_MLBIP_HCER1_CERR_63_32_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_HCER1_CERR_63_32_MAX                          (0xffffffffU)

#define CSL_MLBIP_HCER1_RESETVAL                                (0x00000000U)

/* HCBR0 */

#define CSL_MLBIP_HCBR0_CHB_31_0_MASK                           (0xFFFFFFFFU)
#define CSL_MLBIP_HCBR0_CHB_31_0_SHIFT                          (0U)
#define CSL_MLBIP_HCBR0_CHB_31_0_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_HCBR0_CHB_31_0_MAX                            (0xffffffffU)

#define CSL_MLBIP_HCBR0_RESETVAL                                (0x00000000U)

/* HCBR1 */

#define CSL_MLBIP_HCBR1_CHB_63_32_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_HCBR1_CHB_63_32_SHIFT                         (0U)
#define CSL_MLBIP_HCBR1_CHB_63_32_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_HCBR1_CHB_63_32_MAX                           (0xffffffffU)

#define CSL_MLBIP_HCBR1_RESETVAL                                (0x00000000U)

/* MDAT0 */

#define CSL_MLBIP_MDAT0_DATA_31_0_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_MDAT0_DATA_31_0_SHIFT                         (0U)
#define CSL_MLBIP_MDAT0_DATA_31_0_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_MDAT0_DATA_31_0_MAX                           (0xffffffffU)

#define CSL_MLBIP_MDAT0_RESETVAL                                (0x00000000U)

/* MDAT1 */

#define CSL_MLBIP_MDAT1_DATA_63_32_MASK                         (0xFFFFFFFFU)
#define CSL_MLBIP_MDAT1_DATA_63_32_SHIFT                        (0U)
#define CSL_MLBIP_MDAT1_DATA_63_32_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MDAT1_DATA_63_32_MAX                          (0xffffffffU)

#define CSL_MLBIP_MDAT1_RESETVAL                                (0x00000000U)

/* MDAT2 */

#define CSL_MLBIP_MDAT2_DATA_95_64_MASK                         (0xFFFFFFFFU)
#define CSL_MLBIP_MDAT2_DATA_95_64_SHIFT                        (0U)
#define CSL_MLBIP_MDAT2_DATA_95_64_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MDAT2_DATA_95_64_MAX                          (0xffffffffU)

#define CSL_MLBIP_MDAT2_RESETVAL                                (0x00000000U)

/* MDAT3 */

#define CSL_MLBIP_MDAT3_DATA_127_96_MASK                        (0xFFFFFFFFU)
#define CSL_MLBIP_MDAT3_DATA_127_96_SHIFT                       (0U)
#define CSL_MLBIP_MDAT3_DATA_127_96_RESETVAL                    (0x00000000U)
#define CSL_MLBIP_MDAT3_DATA_127_96_MAX                         (0xffffffffU)

#define CSL_MLBIP_MDAT3_RESETVAL                                (0x00000000U)

/* MDWE0 */

#define CSL_MLBIP_MDWE0_MASK_31_0_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_MDWE0_MASK_31_0_SHIFT                         (0U)
#define CSL_MLBIP_MDWE0_MASK_31_0_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_MDWE0_MASK_31_0_MAX                           (0xffffffffU)

#define CSL_MLBIP_MDWE0_RESETVAL                                (0x00000000U)

/* MDWE1 */

#define CSL_MLBIP_MDWE1_MASK_63_32_MASK                         (0xFFFFFFFFU)
#define CSL_MLBIP_MDWE1_MASK_63_32_SHIFT                        (0U)
#define CSL_MLBIP_MDWE1_MASK_63_32_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MDWE1_MASK_63_32_MAX                          (0xffffffffU)

#define CSL_MLBIP_MDWE1_RESETVAL                                (0x00000000U)

/* MDWE2 */

#define CSL_MLBIP_MDWE2_MASK_95_64_MASK                         (0xFFFFFFFFU)
#define CSL_MLBIP_MDWE2_MASK_95_64_SHIFT                        (0U)
#define CSL_MLBIP_MDWE2_MASK_95_64_RESETVAL                     (0x00000000U)
#define CSL_MLBIP_MDWE2_MASK_95_64_MAX                          (0xffffffffU)

#define CSL_MLBIP_MDWE2_RESETVAL                                (0x00000000U)

/* MDWE3 */

#define CSL_MLBIP_MDWE3_MASK_127_96_MASK                        (0xFFFFFFFFU)
#define CSL_MLBIP_MDWE3_MASK_127_96_SHIFT                       (0U)
#define CSL_MLBIP_MDWE3_MASK_127_96_RESETVAL                    (0x00000000U)
#define CSL_MLBIP_MDWE3_MASK_127_96_MAX                         (0xffffffffU)

#define CSL_MLBIP_MDWE3_RESETVAL                                (0x00000000U)

/* MCTL */

#define CSL_MLBIP_MCTL_XCMP_MASK                                (0x00000001U)
#define CSL_MLBIP_MCTL_XCMP_SHIFT                               (0U)
#define CSL_MLBIP_MCTL_XCMP_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_MCTL_XCMP_MAX                                 (0x00000001U)

#define CSL_MLBIP_MCTL_RSVD_MASK                                (0xFFFFFFFEU)
#define CSL_MLBIP_MCTL_RSVD_SHIFT                               (1U)
#define CSL_MLBIP_MCTL_RSVD_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_MCTL_RSVD_MAX                                 (0x7fffffffU)

#define CSL_MLBIP_MCTL_RESETVAL                                 (0x00000000U)

/* MADR */

#define CSL_MLBIP_MADR_ADDR_7_0_MASK                            (0x000000FFU)
#define CSL_MLBIP_MADR_ADDR_7_0_SHIFT                           (0U)
#define CSL_MLBIP_MADR_ADDR_7_0_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_MADR_ADDR_7_0_MAX                             (0x000000ffU)

#define CSL_MLBIP_MADR_ADDR_13_8_MASK                           (0x00003F00U)
#define CSL_MLBIP_MADR_ADDR_13_8_SHIFT                          (8U)
#define CSL_MLBIP_MADR_ADDR_13_8_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_MADR_ADDR_13_8_MAX                            (0x0000003fU)

#define CSL_MLBIP_MADR_RSVD_MASK                                (0x3FFFC000U)
#define CSL_MLBIP_MADR_RSVD_SHIFT                               (14U)
#define CSL_MLBIP_MADR_RSVD_RESETVAL                            (0x00000000U)
#define CSL_MLBIP_MADR_RSVD_MAX                                 (0x0000ffffU)

#define CSL_MLBIP_MADR_TB_MASK                                  (0x40000000U)
#define CSL_MLBIP_MADR_TB_SHIFT                                 (30U)
#define CSL_MLBIP_MADR_TB_RESETVAL                              (0x00000000U)
#define CSL_MLBIP_MADR_TB_MAX                                   (0x00000001U)

#define CSL_MLBIP_MADR_WNR_MASK                                 (0x80000000U)
#define CSL_MLBIP_MADR_WNR_SHIFT                                (31U)
#define CSL_MLBIP_MADR_WNR_RESETVAL                             (0x00000000U)
#define CSL_MLBIP_MADR_WNR_MAX                                  (0x00000001U)

#define CSL_MLBIP_MADR_RESETVAL                                 (0x00000000U)

/* ACTL */

#define CSL_MLBIP_ACTL_SCE_MASK                                 (0x00000001U)
#define CSL_MLBIP_ACTL_SCE_SHIFT                                (0U)
#define CSL_MLBIP_ACTL_SCE_RESETVAL                             (0x00000000U)
#define CSL_MLBIP_ACTL_SCE_MAX                                  (0x00000001U)

#define CSL_MLBIP_ACTL_SMX_MASK                                 (0x00000002U)
#define CSL_MLBIP_ACTL_SMX_SHIFT                                (1U)
#define CSL_MLBIP_ACTL_SMX_RESETVAL                             (0x00000000U)
#define CSL_MLBIP_ACTL_SMX_MAX                                  (0x00000001U)

#define CSL_MLBIP_ACTL_DMA_MODE_MASK                            (0x00000004U)
#define CSL_MLBIP_ACTL_DMA_MODE_SHIFT                           (2U)
#define CSL_MLBIP_ACTL_DMA_MODE_RESETVAL                        (0x00000000U)
#define CSL_MLBIP_ACTL_DMA_MODE_MAX                             (0x00000001U)

#define CSL_MLBIP_ACTL_RSVD1_MASK                               (0x00000008U)
#define CSL_MLBIP_ACTL_RSVD1_SHIFT                              (3U)
#define CSL_MLBIP_ACTL_RSVD1_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_ACTL_RSVD1_MAX                                (0x00000001U)

#define CSL_MLBIP_ACTL_MPB_MASK                                 (0x00000010U)
#define CSL_MLBIP_ACTL_MPB_SHIFT                                (4U)
#define CSL_MLBIP_ACTL_MPB_RESETVAL                             (0x00000000U)
#define CSL_MLBIP_ACTL_MPB_MAX                                  (0x00000001U)

#define CSL_MLBIP_ACTL_RSVD2_MASK                               (0xFFFFFFE0U)
#define CSL_MLBIP_ACTL_RSVD2_SHIFT                              (5U)
#define CSL_MLBIP_ACTL_RSVD2_RESETVAL                           (0x00000000U)
#define CSL_MLBIP_ACTL_RSVD2_MAX                                (0x07ffffffU)

#define CSL_MLBIP_ACTL_RESETVAL                                 (0x00000000U)

/* ACSR0 */

#define CSL_MLBIP_ACSR0_CHS_31_0_MASK                           (0xFFFFFFFFU)
#define CSL_MLBIP_ACSR0_CHS_31_0_SHIFT                          (0U)
#define CSL_MLBIP_ACSR0_CHS_31_0_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_ACSR0_CHS_31_0_MAX                            (0xffffffffU)

#define CSL_MLBIP_ACSR0_RESETVAL                                (0x00000000U)

/* ACSR1 */

#define CSL_MLBIP_ACSR1_CHS_63_32_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_ACSR1_CHS_63_32_SHIFT                         (0U)
#define CSL_MLBIP_ACSR1_CHS_63_32_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_ACSR1_CHS_63_32_MAX                           (0xffffffffU)

#define CSL_MLBIP_ACSR1_RESETVAL                                (0x00000000U)

/* ACMR0 */

#define CSL_MLBIP_ACMR0_CHM_31_0_MASK                           (0xFFFFFFFFU)
#define CSL_MLBIP_ACMR0_CHM_31_0_SHIFT                          (0U)
#define CSL_MLBIP_ACMR0_CHM_31_0_RESETVAL                       (0x00000000U)
#define CSL_MLBIP_ACMR0_CHM_31_0_MAX                            (0xffffffffU)

#define CSL_MLBIP_ACMR0_RESETVAL                                (0x00000000U)

/* ACMR1 */

#define CSL_MLBIP_ACMR1_CHM_63_32_MASK                          (0xFFFFFFFFU)
#define CSL_MLBIP_ACMR1_CHM_63_32_SHIFT                         (0U)
#define CSL_MLBIP_ACMR1_CHM_63_32_RESETVAL                      (0x00000000U)
#define CSL_MLBIP_ACMR1_CHM_63_32_MAX                           (0xffffffffU)

#define CSL_MLBIP_ACMR1_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
