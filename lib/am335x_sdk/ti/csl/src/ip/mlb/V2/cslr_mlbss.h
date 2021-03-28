/********************************************************************
 * Copyright (C) 2013-2015 Texas Instruments Incorporated.
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
*/
#ifndef CSLR_MLBSS_H_
#define CSLR_MLBSS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Global Control Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CTRL;                      /* Control Register */
    volatile uint32_t STAT;                      /* Status Regsiter */
    volatile uint32_t DMA_CTRL;                  /* DMA Control Regsiter */
} CSL_mlbssRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MLBSS_PID                                                          (0x00000000U)
#define CSL_MLBSS_CTRL                                                         (0x00000004U)
#define CSL_MLBSS_STAT                                                         (0x00000008U)
#define CSL_MLBSS_DMA_CTRL                                                     (0x0000000CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_MLBSS_PID_MINOR_MASK                                               (0x0000003FU)
#define CSL_MLBSS_PID_MINOR_SHIFT                                              (0x00000000U)
#define CSL_MLBSS_PID_MINOR_RESETVAL                                           (0x00000000U)
#define CSL_MLBSS_PID_MINOR_MAX                                                (0x0000003FU)

#define CSL_MLBSS_PID_CUSTOM_MASK                                              (0x000000C0U)
#define CSL_MLBSS_PID_CUSTOM_SHIFT                                             (0x00000006U)
#define CSL_MLBSS_PID_CUSTOM_RESETVAL                                          (0x00000000U)
#define CSL_MLBSS_PID_CUSTOM_MAX                                               (0x00000003U)

#define CSL_MLBSS_PID_MAJOR_MASK                                               (0x00000700U)
#define CSL_MLBSS_PID_MAJOR_SHIFT                                              (0x00000008U)
#define CSL_MLBSS_PID_MAJOR_RESETVAL                                           (0x00000002U)
#define CSL_MLBSS_PID_MAJOR_MAX                                                (0x00000007U)

#define CSL_MLBSS_PID_RTL_MASK                                                 (0x0000F800U)
#define CSL_MLBSS_PID_RTL_SHIFT                                                (0x0000000BU)
#define CSL_MLBSS_PID_RTL_RESETVAL                                             (0x00000009U)
#define CSL_MLBSS_PID_RTL_MAX                                                  (0x0000001FU)

#define CSL_MLBSS_PID_FUNC_MASK                                                (0x0FFF0000U)
#define CSL_MLBSS_PID_FUNC_SHIFT                                               (0x00000010U)
#define CSL_MLBSS_PID_FUNC_RESETVAL                                            (0x000008D0U)
#define CSL_MLBSS_PID_FUNC_MAX                                                 (0x00000FFFU)

#define CSL_MLBSS_PID_BU_MASK                                                  (0x30000000U)
#define CSL_MLBSS_PID_BU_SHIFT                                                 (0x0000001CU)
#define CSL_MLBSS_PID_BU_RESETVAL                                              (0x00000002U)
#define CSL_MLBSS_PID_BU_MAX                                                   (0x00000003U)

#define CSL_MLBSS_PID_SCHEME_MASK                                              (0xC0000000U)
#define CSL_MLBSS_PID_SCHEME_SHIFT                                             (0x0000001EU)
#define CSL_MLBSS_PID_SCHEME_RESETVAL                                          (0x00000001U)
#define CSL_MLBSS_PID_SCHEME_MAX                                               (0x00000003U)

#define CSL_MLBSS_PID_RESETVAL                                                 (0x68D04A00U)

/* CTRL */

#define CSL_MLBSS_CTRL_RESET_MASK                                              (0x00000001U)
#define CSL_MLBSS_CTRL_RESET_SHIFT                                             (0x00000000U)
#define CSL_MLBSS_CTRL_RESET_RESETVAL                                          (0x00000000U)
#define CSL_MLBSS_CTRL_RESET_MAX                                               (0x00000001U)

#define CSL_MLBSS_CTRL_CLKFACK_MASK                                            (0x00000002U)
#define CSL_MLBSS_CTRL_CLKFACK_SHIFT                                           (0x00000001U)
#define CSL_MLBSS_CTRL_CLKFACK_RESETVAL                                        (0x00000000U)
#define CSL_MLBSS_CTRL_CLKFACK_MAX                                             (0x00000001U)

#define CSL_MLBSS_CTRL_WAKEUPREQEN_MASK                                        (0x00000004U)
#define CSL_MLBSS_CTRL_WAKEUPREQEN_SHIFT                                       (0x00000002U)
#define CSL_MLBSS_CTRL_WAKEUPREQEN_RESETVAL                                    (0x00000000U)
#define CSL_MLBSS_CTRL_WAKEUPREQEN_MAX                                         (0x00000001U)

#define CSL_MLBSS_CTRL_RESETVAL                                                (0x00000000U)

/* STAT */

#define CSL_MLBSS_STAT_RESET_MASK                                              (0x00000001U)
#define CSL_MLBSS_STAT_RESET_SHIFT                                             (0x00000000U)
#define CSL_MLBSS_STAT_RESET_RESETVAL                                          (0x00000000U)
#define CSL_MLBSS_STAT_RESET_MAX                                               (0x00000001U)

#define CSL_MLBSS_STAT_INIT_MASK                                               (0x00000002U)
#define CSL_MLBSS_STAT_INIT_SHIFT                                              (0x00000001U)
#define CSL_MLBSS_STAT_INIT_RESETVAL                                           (0x00000000U)
#define CSL_MLBSS_STAT_INIT_MAX                                                (0x00000001U)

#define CSL_MLBSS_STAT_RESETVAL                                                (0x00000000U)

/* DMA_CTRL */

#define CSL_MLBSS_DMA_CTRL_PRIORITY_MASK                                       (0x00000007U)
#define CSL_MLBSS_DMA_CTRL_PRIORITY_SHIFT                                      (0x00000000U)
#define CSL_MLBSS_DMA_CTRL_PRIORITY_RESETVAL                                   (0x00000000U)
#define CSL_MLBSS_DMA_CTRL_PRIORITY_MAX                                        (0x00000007U)

#define CSL_MLBSS_DMA_CTRL_RESETVAL                                            (0x00000000U)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t MLBC0;                     /* MediaLB Control 0 */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t MLBPC0;                    /* MediaLB 6-pin Control 0 */
    volatile uint32_t MS0;                       /* MediaLB Channel Status 0 */
    volatile uint8_t  Resv_20[4];
    volatile uint32_t MS1;                       /* MediaLB Channel Status 1 */
    volatile uint8_t  Resv_32[8];
    volatile uint32_t MSS;                       /* MediaLB System Status */
    volatile uint32_t MSD;                       /* MediaLB System Data */
    volatile uint8_t  Resv_44[4];
    volatile uint32_t MIEN;                      /* MediaLB Interrupt Enable */
    volatile uint8_t  Resv_52[4];
    volatile uint32_t MLBPC2;                    /* MediaLB 6-pin Control 2 */
    volatile uint32_t MLBPC1;                    /* MediaLB 6-pin Control 1 */
    volatile uint32_t MLBC1;                     /* MediaLB Control 1 */
    volatile uint8_t  Resv_128[64];
    volatile uint32_t HCTL;                      /* HBI Control */
    volatile uint8_t  Resv_136[4];
    volatile uint32_t HCMR0;                     /* HBI Channel Mask 0 */
    volatile uint32_t HCMR1;                     /* HBI Channel Mask 1 */
    volatile uint32_t HCER0;                     /* HBI Channel Error 0 */
    volatile uint32_t HCER1;                     /* HBI Channel Error 1 */
    volatile uint32_t HCBR0;                     /* HBI Channel Busy 0 */
    volatile uint32_t HCBR1;                     /* HBI Channel Busy 1 */
    volatile uint8_t  Resv_192[32];
    volatile uint32_t MDAT0;                     /* MIF Data 0 */
    volatile uint32_t MDAT1;                     /* MIF Data 1 */
    volatile uint32_t MDAT2;                     /* MIF Data 2 */
    volatile uint32_t MDAT3;                     /* MIF Data 3 */
    volatile uint32_t MDWE0;                     /* MIF Data Write Enable 0 */
    volatile uint32_t MDWE1;                     /* MIF Data Write Enable 1 */
    volatile uint32_t MDWE2;                     /* MIF Data Write Enable 2 */
    volatile uint32_t MDWE3;                     /* MIF Data Write Enable 3 */
    volatile uint32_t MCTL;                      /* MIF Control */
    volatile uint32_t MADR;                      /* MIF Address */
    volatile uint8_t  Resv_960[728];
    volatile uint32_t ACTL;                      /* AHB Control */
    volatile uint8_t  Resv_976[12];
    volatile uint32_t ACSR0;                     /* AHB Channel Status 0 */
    volatile uint32_t ACSR1;                     /* AHB Channel Status 1 */
    volatile uint32_t ACMR0;                     /* AHB Channel Mask 0 */
    volatile uint32_t ACMR1;                     /* AHB Channel Mask 1 */
} CSL_mlbdimRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MLBDIM_MLBC0                                                       (0x00000000U)
#define CSL_MLBDIM_MLBPC0                                                      (0x00000008U)
#define CSL_MLBDIM_MS0                                                         (0x0000000CU)
#define CSL_MLBDIM_MS1                                                         (0x00000014U)
#define CSL_MLBDIM_MSS                                                         (0x00000020U)
#define CSL_MLBDIM_MSD                                                         (0x00000024U)
#define CSL_MLBDIM_MIEN                                                        (0x0000002CU)
#define CSL_MLBDIM_MLBPC2                                                      (0x00000034U)
#define CSL_MLBDIM_MLBPC1                                                      (0x00000038U)
#define CSL_MLBDIM_MLBC1                                                       (0x0000003CU)
#define CSL_MLBDIM_HCTL                                                        (0x00000080U)
#define CSL_MLBDIM_HCMR0                                                       (0x00000088U)
#define CSL_MLBDIM_HCMR1                                                       (0x0000008CU)
#define CSL_MLBDIM_HCER0                                                       (0x00000090U)
#define CSL_MLBDIM_HCER1                                                       (0x00000094U)
#define CSL_MLBDIM_HCBR0                                                       (0x00000098U)
#define CSL_MLBDIM_HCBR1                                                       (0x0000009CU)
#define CSL_MLBDIM_MDAT0                                                       (0x000000C0U)
#define CSL_MLBDIM_MDAT1                                                       (0x000000C4U)
#define CSL_MLBDIM_MDAT2                                                       (0x000000C8U)
#define CSL_MLBDIM_MDAT3                                                       (0x000000CCU)
#define CSL_MLBDIM_MDWE0                                                       (0x000000D0U)
#define CSL_MLBDIM_MDWE1                                                       (0x000000D4U)
#define CSL_MLBDIM_MDWE2                                                       (0x000000D8U)
#define CSL_MLBDIM_MDWE3                                                       (0x000000DCU)
#define CSL_MLBDIM_MCTL                                                        (0x000000E0U)
#define CSL_MLBDIM_MADR                                                        (0x000000E4U)
#define CSL_MLBDIM_ACTL                                                        (0x000003C0U)
#define CSL_MLBDIM_ACSR0                                                       (0x000003D0U)
#define CSL_MLBDIM_ACSR1                                                       (0x000003D4U)
#define CSL_MLBDIM_ACMR0                                                       (0x000003D8U)
#define CSL_MLBDIM_ACMR1                                                       (0x000003DCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MLBC0 */

#define CSL_MLBDIM_MLBC0_MLBEN_MASK                                            (0x00000001U)
#define CSL_MLBDIM_MLBC0_MLBEN_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_MLBC0_MLBEN_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBC0_MLBEN_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MLBC0_RSV0_MASK                                             (0x00000002U)
#define CSL_MLBDIM_MLBC0_RSV0_SHIFT                                            (0x00000001U)
#define CSL_MLBDIM_MLBC0_RSV0_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_RSV0_MAX                                              (0x00000001U)

#define CSL_MLBDIM_MLBC0_MLBCLK_MASK                                           (0x0000001CU)
#define CSL_MLBDIM_MLBC0_MLBCLK_SHIFT                                          (0x00000002U)
#define CSL_MLBDIM_MLBC0_MLBCLK_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MLBC0_MLBCLK_MAX                                            (0x00000007U)

#define CSL_MLBDIM_MLBC0_MLBPEN_MASK                                           (0x00000020U)
#define CSL_MLBDIM_MLBC0_MLBPEN_SHIFT                                          (0x00000005U)
#define CSL_MLBDIM_MLBC0_MLBPEN_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MLBC0_MLBPEN_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MLBC0_RSV1_MASK                                             (0x00000040U)
#define CSL_MLBDIM_MLBC0_RSV1_SHIFT                                            (0x00000006U)
#define CSL_MLBDIM_MLBC0_RSV1_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_RSV1_MAX                                              (0x00000001U)

#define CSL_MLBDIM_MLBC0_MLBLK_MASK                                            (0x00000080U)
#define CSL_MLBDIM_MLBC0_MLBLK_SHIFT                                           (0x00000007U)
#define CSL_MLBDIM_MLBC0_MLBLK_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBC0_MLBLK_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MLBC0_RSV2_MASK                                             (0x00000F00U)
#define CSL_MLBDIM_MLBC0_RSV2_SHIFT                                            (0x00000008U)
#define CSL_MLBDIM_MLBC0_RSV2_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_RSV2_MAX                                              (0x0000000FU)

#define CSL_MLBDIM_MLBC0_ASYRETRY_MASK                                         (0x00001000U)
#define CSL_MLBDIM_MLBC0_ASYRETRY_SHIFT                                        (0x0000000CU)
#define CSL_MLBDIM_MLBC0_ASYRETRY_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MLBC0_ASYRETRY_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MLBC0_RSV3_MASK                                             (0x00002000U)
#define CSL_MLBDIM_MLBC0_RSV3_SHIFT                                            (0x0000000DU)
#define CSL_MLBDIM_MLBC0_RSV3_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_RSV3_MAX                                              (0x00000001U)

#define CSL_MLBDIM_MLBC0_CTLRETRY_MASK                                         (0x00004000U)
#define CSL_MLBDIM_MLBC0_CTLRETRY_SHIFT                                        (0x0000000EU)
#define CSL_MLBDIM_MLBC0_CTLRETRY_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MLBC0_CTLRETRY_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MLBC0_FCNT_MASK                                             (0x00038000U)
#define CSL_MLBDIM_MLBC0_FCNT_SHIFT                                            (0x0000000FU)
#define CSL_MLBDIM_MLBC0_FCNT_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_FCNT_MAX                                              (0x00000007U)

#define CSL_MLBDIM_MLBC0_RSV4_MASK                                             (0x7FFC0000U)
#define CSL_MLBDIM_MLBC0_RSV4_SHIFT                                            (0x00000012U)
#define CSL_MLBDIM_MLBC0_RSV4_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC0_RSV4_MAX                                              (0x00001FFFU)

#define CSL_MLBDIM_MLBC0_RESETVAL                                              (0x00000000U)

/* MLBPC0 */

#define CSL_MLBDIM_MLBPC0_RSV0_MASK                                            (0x00000001U)
#define CSL_MLBDIM_MLBPC0_RSV0_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_MLBPC0_RSV0_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC0_RSV0_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MLBPC0_MLBCMRES_MASK                                        (0x00000002U)
#define CSL_MLBDIM_MLBPC0_MLBCMRES_SHIFT                                       (0x00000001U)
#define CSL_MLBDIM_MLBPC0_MLBCMRES_RESETVAL                                    (0x00000000U)
#define CSL_MLBDIM_MLBPC0_MLBCMRES_MAX                                         (0x00000001U)

#define CSL_MLBDIM_MLBPC0_RSV1_MASK                                            (0x000007FCU)
#define CSL_MLBDIM_MLBPC0_RSV1_SHIFT                                           (0x00000002U)
#define CSL_MLBDIM_MLBPC0_RSV1_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC0_RSV1_MAX                                             (0x000001FFU)

#define CSL_MLBDIM_MLBPC0_MCLKHYS_MASK                                         (0x00000800U)
#define CSL_MLBDIM_MLBPC0_MCLKHYS_SHIFT                                        (0x0000000BU)
#define CSL_MLBDIM_MLBPC0_MCLKHYS_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MLBPC0_MCLKHYS_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MLBPC0_RSV2_MASK                                            (0xFFFFF000U)
#define CSL_MLBDIM_MLBPC0_RSV2_SHIFT                                           (0x0000000CU)
#define CSL_MLBDIM_MLBPC0_RSV2_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC0_RSV2_MAX                                             (0x000FFFFFU)

#define CSL_MLBDIM_MLBPC0_RESETVAL                                             (0x00000000U)

/* MS0 */

#define CSL_MLBDIM_MS0_MCS_MASK                                                (0xFFFFFFFFU)
#define CSL_MLBDIM_MS0_MCS_SHIFT                                               (0x00000000U)
#define CSL_MLBDIM_MS0_MCS_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MS0_MCS_MAX                                                 (0xFFFFFFFFU)

#define CSL_MLBDIM_MS0_RESETVAL                                                (0x00000000U)

/* MS1 */

#define CSL_MLBDIM_MS1_MCS_MASK                                                (0xFFFFFFFFU)
#define CSL_MLBDIM_MS1_MCS_SHIFT                                               (0x00000000U)
#define CSL_MLBDIM_MS1_MCS_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MS1_MCS_MAX                                                 (0xFFFFFFFFU)

#define CSL_MLBDIM_MS1_RESETVAL                                                (0x00000000U)

/* MSS */

#define CSL_MLBDIM_MSS_RSTSYSCMD_MASK                                          (0x00000001U)
#define CSL_MLBDIM_MSS_RSTSYSCMD_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_MSS_RSTSYSCMD_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MSS_RSTSYSCMD_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MSS_LKSYSCMD_MASK                                           (0x00000002U)
#define CSL_MLBDIM_MSS_LKSYSCMD_SHIFT                                          (0x00000001U)
#define CSL_MLBDIM_MSS_LKSYSCMD_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MSS_LKSYSCMD_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MSS_ULKSYSCMD_MASK                                          (0x00000004U)
#define CSL_MLBDIM_MSS_ULKSYSCMD_SHIFT                                         (0x00000002U)
#define CSL_MLBDIM_MSS_ULKSYSCMD_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MSS_ULKSYSCMD_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MSS_CSSYSCMD_MASK                                           (0x00000008U)
#define CSL_MLBDIM_MSS_CSSYSCMD_SHIFT                                          (0x00000003U)
#define CSL_MLBDIM_MSS_CSSYSCMD_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MSS_CSSYSCMD_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MSS_SWSYSCMD_MASK                                           (0x00000010U)
#define CSL_MLBDIM_MSS_SWSYSCMD_SHIFT                                          (0x00000004U)
#define CSL_MLBDIM_MSS_SWSYSCMD_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MSS_SWSYSCMD_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MSS_SERVREQ_MASK                                            (0x00000020U)
#define CSL_MLBDIM_MSS_SERVREQ_SHIFT                                           (0x00000005U)
#define CSL_MLBDIM_MSS_SERVREQ_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MSS_SERVREQ_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MSS_RSV0_MASK                                               (0xFFFFFFC0U)
#define CSL_MLBDIM_MSS_RSV0_SHIFT                                              (0x00000006U)
#define CSL_MLBDIM_MSS_RSV0_RESETVAL                                           (0x00000000U)
#define CSL_MLBDIM_MSS_RSV0_MAX                                                (0x03FFFFFFU)

#define CSL_MLBDIM_MSS_RESETVAL                                                (0x00000000U)

/* MSD */

#define CSL_MLBDIM_MSD_SD0_MASK                                                (0x000000FFU)
#define CSL_MLBDIM_MSD_SD0_SHIFT                                               (0x00000000U)
#define CSL_MLBDIM_MSD_SD0_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MSD_SD0_MAX                                                 (0x000000FFU)

#define CSL_MLBDIM_MSD_SD1_MASK                                                (0x0000FF00U)
#define CSL_MLBDIM_MSD_SD1_SHIFT                                               (0x00000008U)
#define CSL_MLBDIM_MSD_SD1_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MSD_SD1_MAX                                                 (0x000000FFU)

#define CSL_MLBDIM_MSD_SD2_MASK                                                (0x00FF0000U)
#define CSL_MLBDIM_MSD_SD2_SHIFT                                               (0x00000010U)
#define CSL_MLBDIM_MSD_SD2_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MSD_SD2_MAX                                                 (0x000000FFU)

#define CSL_MLBDIM_MSD_SD3_MASK                                                (0xFF000000U)
#define CSL_MLBDIM_MSD_SD3_SHIFT                                               (0x00000018U)
#define CSL_MLBDIM_MSD_SD3_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MSD_SD3_MAX                                                 (0x000000FFU)

#define CSL_MLBDIM_MSD_RESETVAL                                                (0x00000000U)

/* MIEN */

#define CSL_MLBDIM_MIEN_ISOC_PE_MASK                                           (0x00000001U)
#define CSL_MLBDIM_MIEN_ISOC_PE_SHIFT                                          (0x00000000U)
#define CSL_MLBDIM_MIEN_ISOC_PE_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MIEN_ISOC_PE_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MIEN_ISOC_BUFO_MASK                                         (0x00000002U)
#define CSL_MLBDIM_MIEN_ISOC_BUFO_SHIFT                                        (0x00000001U)
#define CSL_MLBDIM_MIEN_ISOC_BUFO_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MIEN_ISOC_BUFO_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MIEN_RSV0_MASK                                              (0x0000FFFCU)
#define CSL_MLBDIM_MIEN_RSV0_SHIFT                                             (0x00000002U)
#define CSL_MLBDIM_MIEN_RSV0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MIEN_RSV0_MAX                                               (0x00003FFFU)

#define CSL_MLBDIM_MIEN_SYNC_PE_MASK                                           (0x00010000U)
#define CSL_MLBDIM_MIEN_SYNC_PE_SHIFT                                          (0x00000010U)
#define CSL_MLBDIM_MIEN_SYNC_PE_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_MIEN_SYNC_PE_MAX                                            (0x00000001U)

#define CSL_MLBDIM_MIEN_ARX_DONE_MASK                                          (0x00020000U)
#define CSL_MLBDIM_MIEN_ARX_DONE_SHIFT                                         (0x00000011U)
#define CSL_MLBDIM_MIEN_ARX_DONE_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MIEN_ARX_DONE_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MIEN_ARX_PE_MASK                                            (0x00040000U)
#define CSL_MLBDIM_MIEN_ARX_PE_SHIFT                                           (0x00000012U)
#define CSL_MLBDIM_MIEN_ARX_PE_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MIEN_ARX_PE_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MIEN_ARX_BREAK_MASK                                         (0x00080000U)
#define CSL_MLBDIM_MIEN_ARX_BREAK_SHIFT                                        (0x00000013U)
#define CSL_MLBDIM_MIEN_ARX_BREAK_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MIEN_ARX_BREAK_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MIEN_ATX_DONE_MASK                                          (0x00100000U)
#define CSL_MLBDIM_MIEN_ATX_DONE_SHIFT                                         (0x00000014U)
#define CSL_MLBDIM_MIEN_ATX_DONE_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MIEN_ATX_DONE_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MIEN_ATX_PE_MASK                                            (0x00200000U)
#define CSL_MLBDIM_MIEN_ATX_PE_SHIFT                                           (0x00000015U)
#define CSL_MLBDIM_MIEN_ATX_PE_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MIEN_ATX_PE_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MIEN_ATX_BREAK_MASK                                         (0x00400000U)
#define CSL_MLBDIM_MIEN_ATX_BREAK_SHIFT                                        (0x00000016U)
#define CSL_MLBDIM_MIEN_ATX_BREAK_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MIEN_ATX_BREAK_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MIEN_RSV1_MASK                                              (0x00800000U)
#define CSL_MLBDIM_MIEN_RSV1_SHIFT                                             (0x00000017U)
#define CSL_MLBDIM_MIEN_RSV1_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MIEN_RSV1_MAX                                               (0x00000001U)

#define CSL_MLBDIM_MIEN_CRX_DONE_MASK                                          (0x01000000U)
#define CSL_MLBDIM_MIEN_CRX_DONE_SHIFT                                         (0x00000018U)
#define CSL_MLBDIM_MIEN_CRX_DONE_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MIEN_CRX_DONE_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MIEN_CRX_PE_MASK                                            (0x02000000U)
#define CSL_MLBDIM_MIEN_CRX_PE_SHIFT                                           (0x00000019U)
#define CSL_MLBDIM_MIEN_CRX_PE_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MIEN_CRX_PE_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MIEN_CRX_BREAK_MASK                                         (0x04000000U)
#define CSL_MLBDIM_MIEN_CRX_BREAK_SHIFT                                        (0x0000001AU)
#define CSL_MLBDIM_MIEN_CRX_BREAK_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MIEN_CRX_BREAK_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MIEN_CTX_DONE_MASK                                          (0x08000000U)
#define CSL_MLBDIM_MIEN_CTX_DONE_SHIFT                                         (0x0000001BU)
#define CSL_MLBDIM_MIEN_CTX_DONE_RESETVAL                                      (0x00000000U)
#define CSL_MLBDIM_MIEN_CTX_DONE_MAX                                           (0x00000001U)

#define CSL_MLBDIM_MIEN_CTX_PE_MASK                                            (0x10000000U)
#define CSL_MLBDIM_MIEN_CTX_PE_SHIFT                                           (0x0000001CU)
#define CSL_MLBDIM_MIEN_CTX_PE_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MIEN_CTX_PE_MAX                                             (0x00000001U)

#define CSL_MLBDIM_MIEN_CTX_BREAK_MASK                                         (0x20000000U)
#define CSL_MLBDIM_MIEN_CTX_BREAK_SHIFT                                        (0x0000001DU)
#define CSL_MLBDIM_MIEN_CTX_BREAK_RESETVAL                                     (0x00000000U)
#define CSL_MLBDIM_MIEN_CTX_BREAK_MAX                                          (0x00000001U)

#define CSL_MLBDIM_MIEN_RSV2_MASK                                              (0xC0000000U)
#define CSL_MLBDIM_MIEN_RSV2_SHIFT                                             (0x0000001EU)
#define CSL_MLBDIM_MIEN_RSV2_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MIEN_RSV2_MAX                                               (0x00000003U)

#define CSL_MLBDIM_MIEN_RESETVAL                                               (0x00000000U)

/* MLBPC2 */

#define CSL_MLBDIM_MLBPC2_UCFG_MASK                                            (0x0000FFFFU)
#define CSL_MLBDIM_MLBPC2_UCFG_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_MLBPC2_UCFG_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC2_UCFG_MAX                                             (0x0000FFFFU)

#define CSL_MLBDIM_MLBPC2_RSV0_MASK                                            (0xFFFF0000U)
#define CSL_MLBDIM_MLBPC2_RSV0_SHIFT                                           (0x00000010U)
#define CSL_MLBDIM_MLBPC2_RSV0_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC2_RSV0_MAX                                             (0x0000FFFFU)

#define CSL_MLBDIM_MLBPC2_RESETVAL                                             (0x00000000U)

/* MLBPC1 */

#define CSL_MLBDIM_MLBPC1_SDRCVBIAS_MASK                                       (0x0000000FU)
#define CSL_MLBDIM_MLBPC1_SDRCVBIAS_SHIFT                                      (0x00000000U)
#define CSL_MLBDIM_MLBPC1_SDRCVBIAS_RESETVAL                                   (0x00000000U)
#define CSL_MLBDIM_MLBPC1_SDRCVBIAS_MAX                                        (0x0000000FU)

#define CSL_MLBDIM_MLBPC1_SDXMTBIAS_MASK                                       (0x000000F0U)
#define CSL_MLBDIM_MLBPC1_SDXMTBIAS_SHIFT                                      (0x00000004U)
#define CSL_MLBDIM_MLBPC1_SDXMTBIAS_RESETVAL                                   (0x00000000U)
#define CSL_MLBDIM_MLBPC1_SDXMTBIAS_MAX                                        (0x0000000FU)

#define CSL_MLBDIM_MLBPC1_CKRCVBIAS_MASK                                       (0x00000F00U)
#define CSL_MLBDIM_MLBPC1_CKRCVBIAS_SHIFT                                      (0x00000008U)
#define CSL_MLBDIM_MLBPC1_CKRCVBIAS_RESETVAL                                   (0x00000000U)
#define CSL_MLBDIM_MLBPC1_CKRCVBIAS_MAX                                        (0x0000000FU)

#define CSL_MLBDIM_MLBPC1_RSV0_MASK                                            (0xFFFFF000U)
#define CSL_MLBDIM_MLBPC1_RSV0_SHIFT                                           (0x0000000CU)
#define CSL_MLBDIM_MLBPC1_RSV0_RESETVAL                                        (0x00000000U)
#define CSL_MLBDIM_MLBPC1_RSV0_MAX                                             (0x000FFFFFU)

#define CSL_MLBDIM_MLBPC1_RESETVAL                                             (0x00000000U)

/* MLBC1 */

#define CSL_MLBDIM_MLBC1_RSV0_MASK                                             (0x0000003FU)
#define CSL_MLBDIM_MLBC1_RSV0_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MLBC1_RSV0_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC1_RSV0_MAX                                              (0x0000003FU)

#define CSL_MLBDIM_MLBC1_LOCK_MASK                                             (0x00000040U)
#define CSL_MLBDIM_MLBC1_LOCK_SHIFT                                            (0x00000006U)
#define CSL_MLBDIM_MLBC1_LOCK_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC1_LOCK_MAX                                              (0x00000001U)

#define CSL_MLBDIM_MLBC1_CLKM_MASK                                             (0x00000080U)
#define CSL_MLBDIM_MLBC1_CLKM_SHIFT                                            (0x00000007U)
#define CSL_MLBDIM_MLBC1_CLKM_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC1_CLKM_MAX                                              (0x00000001U)

#define CSL_MLBDIM_MLBC1_NDA_MASK                                              (0x0000FF00U)
#define CSL_MLBDIM_MLBC1_NDA_SHIFT                                             (0x00000008U)
#define CSL_MLBDIM_MLBC1_NDA_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MLBC1_NDA_MAX                                               (0x000000FFU)

#define CSL_MLBDIM_MLBC1_RSV1_MASK                                             (0xFFFF0000U)
#define CSL_MLBDIM_MLBC1_RSV1_SHIFT                                            (0x00000010U)
#define CSL_MLBDIM_MLBC1_RSV1_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MLBC1_RSV1_MAX                                              (0x0000FFFFU)

#define CSL_MLBDIM_MLBC1_RESETVAL                                              (0x00000000U)

/* HCTL */

#define CSL_MLBDIM_HCTL_RST0_MASK                                              (0x00000001U)
#define CSL_MLBDIM_HCTL_RST0_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_HCTL_RST0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCTL_RST0_MAX                                               (0x00000001U)

#define CSL_MLBDIM_HCTL_RST1_MASK                                              (0x00000002U)
#define CSL_MLBDIM_HCTL_RST1_SHIFT                                             (0x00000001U)
#define CSL_MLBDIM_HCTL_RST1_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCTL_RST1_MAX                                               (0x00000001U)

#define CSL_MLBDIM_HCTL_RSV0_MASK                                              (0x00007FFCU)
#define CSL_MLBDIM_HCTL_RSV0_SHIFT                                             (0x00000002U)
#define CSL_MLBDIM_HCTL_RSV0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCTL_RSV0_MAX                                               (0x00001FFFU)

#define CSL_MLBDIM_HCTL_EN_MASK                                                (0x00008000U)
#define CSL_MLBDIM_HCTL_EN_SHIFT                                               (0x0000000FU)
#define CSL_MLBDIM_HCTL_EN_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_HCTL_EN_MAX                                                 (0x00000001U)

#define CSL_MLBDIM_HCTL_RSV1_MASK                                              (0xFFFF0000U)
#define CSL_MLBDIM_HCTL_RSV1_SHIFT                                             (0x00000010U)
#define CSL_MLBDIM_HCTL_RSV1_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCTL_RSV1_MAX                                               (0x0000FFFFU)

#define CSL_MLBDIM_HCTL_RESETVAL                                               (0x00000000U)

/* HCMR0 */

#define CSL_MLBDIM_HCMR0_CHM_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_HCMR0_CHM_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_HCMR0_CHM_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCMR0_CHM_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_HCMR0_RESETVAL                                              (0x00000000U)

/* HCMR1 */

#define CSL_MLBDIM_HCMR1_CHM_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_HCMR1_CHM_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_HCMR1_CHM_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCMR1_CHM_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_HCMR1_RESETVAL                                              (0x00000000U)

/* HCER0 */

#define CSL_MLBDIM_HCER0_CERR_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_HCER0_CERR_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_HCER0_CERR_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_HCER0_CERR_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_HCER0_RESETVAL                                              (0x00000000U)

/* HCER1 */

#define CSL_MLBDIM_HCER1_CERR_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_HCER1_CERR_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_HCER1_CERR_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_HCER1_CERR_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_HCER1_RESETVAL                                              (0x00000000U)

/* HCBR0 */

#define CSL_MLBDIM_HCBR0_CHB_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_HCBR0_CHB_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_HCBR0_CHB_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCBR0_CHB_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_HCBR0_RESETVAL                                              (0x00000000U)

/* HCBR1 */

#define CSL_MLBDIM_HCBR1_CHB_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_HCBR1_CHB_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_HCBR1_CHB_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_HCBR1_CHB_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_HCBR1_RESETVAL                                              (0x00000000U)

/* MDAT0 */

#define CSL_MLBDIM_MDAT0_DATA_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDAT0_DATA_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDAT0_DATA_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDAT0_DATA_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDAT0_RESETVAL                                              (0x00000000U)

/* MDAT1 */

#define CSL_MLBDIM_MDAT1_DATA_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDAT1_DATA_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDAT1_DATA_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDAT1_DATA_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDAT1_RESETVAL                                              (0x00000000U)

/* MDAT2 */

#define CSL_MLBDIM_MDAT2_DATA_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDAT2_DATA_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDAT2_DATA_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDAT2_DATA_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDAT2_RESETVAL                                              (0x00000000U)

/* MDAT3 */

#define CSL_MLBDIM_MDAT3_DATA_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDAT3_DATA_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDAT3_DATA_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDAT3_DATA_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDAT3_RESETVAL                                              (0x00000000U)

/* MDWE0 */

#define CSL_MLBDIM_MDWE0_MASK_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDWE0_MASK_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDWE0_MASK_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDWE0_MASK_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDWE0_RESETVAL                                              (0x00000000U)

/* MDWE1 */

#define CSL_MLBDIM_MDWE1_MASK_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDWE1_MASK_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDWE1_MASK_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDWE1_MASK_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDWE1_RESETVAL                                              (0x00000000U)

/* MDWE2 */

#define CSL_MLBDIM_MDWE2_MASK_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDWE2_MASK_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDWE2_MASK_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDWE2_MASK_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDWE2_RESETVAL                                              (0x00000000U)

/* MDWE3 */

#define CSL_MLBDIM_MDWE3_MASK_MASK                                             (0xFFFFFFFFU)
#define CSL_MLBDIM_MDWE3_MASK_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MDWE3_MASK_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MDWE3_MASK_MAX                                              (0xFFFFFFFFU)

#define CSL_MLBDIM_MDWE3_RESETVAL                                              (0x00000000U)

/* MCTL */

#define CSL_MLBDIM_MCTL_XCMP_MASK                                              (0x00000001U)
#define CSL_MLBDIM_MCTL_XCMP_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_MCTL_XCMP_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MCTL_XCMP_MAX                                               (0x00000001U)

#define CSL_MLBDIM_MCTL_RSV0_MASK                                              (0xFFFFFFFEU)
#define CSL_MLBDIM_MCTL_RSV0_SHIFT                                             (0x00000001U)
#define CSL_MLBDIM_MCTL_RSV0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MCTL_RSV0_MAX                                               (0x7FFFFFFFU)

#define CSL_MLBDIM_MCTL_RESETVAL                                               (0x00000000U)

/* MADR */

#define CSL_MLBDIM_MADR_ADDR0_MASK                                             (0x000000FFU)
#define CSL_MLBDIM_MADR_ADDR0_SHIFT                                            (0x00000000U)
#define CSL_MLBDIM_MADR_ADDR0_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MADR_ADDR0_MAX                                              (0x000000FFU)

#define CSL_MLBDIM_MADR_ADDR1_MASK                                             (0x00003F00U)
#define CSL_MLBDIM_MADR_ADDR1_SHIFT                                            (0x00000008U)
#define CSL_MLBDIM_MADR_ADDR1_RESETVAL                                         (0x00000000U)
#define CSL_MLBDIM_MADR_ADDR1_MAX                                              (0x0000003FU)

#define CSL_MLBDIM_MADR_RSV0_MASK                                              (0x3FFFC000U)
#define CSL_MLBDIM_MADR_RSV0_SHIFT                                             (0x0000000EU)
#define CSL_MLBDIM_MADR_RSV0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_MADR_RSV0_MAX                                               (0x0000FFFFU)

#define CSL_MLBDIM_MADR_TB_MASK                                                (0x40000000U)
#define CSL_MLBDIM_MADR_TB_SHIFT                                               (0x0000001EU)
#define CSL_MLBDIM_MADR_TB_RESETVAL                                            (0x00000000U)
#define CSL_MLBDIM_MADR_TB_MAX                                                 (0x00000001U)

#define CSL_MLBDIM_MADR_WNR_MASK                                               (0x80000000U)
#define CSL_MLBDIM_MADR_WNR_SHIFT                                              (0x0000001FU)
#define CSL_MLBDIM_MADR_WNR_RESETVAL                                           (0x00000000U)
#define CSL_MLBDIM_MADR_WNR_MAX                                                (0x00000001U)

#define CSL_MLBDIM_MADR_RESETVAL                                               (0x00000000U)

/* ACTL */

#define CSL_MLBDIM_ACTL_SCE_MASK                                               (0x00000001U)
#define CSL_MLBDIM_ACTL_SCE_SHIFT                                              (0x00000000U)
#define CSL_MLBDIM_ACTL_SCE_RESETVAL                                           (0x00000000U)
#define CSL_MLBDIM_ACTL_SCE_MAX                                                (0x00000001U)

#define CSL_MLBDIM_ACTL_SMX_MASK                                               (0x00000002U)
#define CSL_MLBDIM_ACTL_SMX_SHIFT                                              (0x00000001U)
#define CSL_MLBDIM_ACTL_SMX_RESETVAL                                           (0x00000000U)
#define CSL_MLBDIM_ACTL_SMX_MAX                                                (0x00000001U)

#define CSL_MLBDIM_ACTL_DMAMODE_MASK                                           (0x00000004U)
#define CSL_MLBDIM_ACTL_DMAMODE_SHIFT                                          (0x00000002U)
#define CSL_MLBDIM_ACTL_DMAMODE_RESETVAL                                       (0x00000000U)
#define CSL_MLBDIM_ACTL_DMAMODE_MAX                                            (0x00000001U)

#define CSL_MLBDIM_ACTL_RSV0_MASK                                              (0x00000008U)
#define CSL_MLBDIM_ACTL_RSV0_SHIFT                                             (0x00000003U)
#define CSL_MLBDIM_ACTL_RSV0_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACTL_RSV0_MAX                                               (0x00000001U)

#define CSL_MLBDIM_ACTL_MPB_MASK                                               (0x00000010U)
#define CSL_MLBDIM_ACTL_MPB_SHIFT                                              (0x00000004U)
#define CSL_MLBDIM_ACTL_MPB_RESETVAL                                           (0x00000000U)
#define CSL_MLBDIM_ACTL_MPB_MAX                                                (0x00000001U)

#define CSL_MLBDIM_ACTL_RSV1_MASK                                              (0x1FFFFFFE0U)
#define CSL_MLBDIM_ACTL_RSV1_SHIFT                                             (0x00000005U)
#define CSL_MLBDIM_ACTL_RSV1_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACTL_RSV1_MAX                                               (0x0FFFFFFFU)

#define CSL_MLBDIM_ACTL_RESETVAL                                               (0x00000000U)

/* ACSR0 */

#define CSL_MLBDIM_ACSR0_CHS_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_ACSR0_CHS_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_ACSR0_CHS_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACSR0_CHS_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_ACSR0_RESETVAL                                              (0x00000000U)

/* ACSR1 */

#define CSL_MLBDIM_ACSR1_CHS_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_ACSR1_CHS_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_ACSR1_CHS_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACSR1_CHS_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_ACSR1_RESETVAL                                              (0x00000000U)

/* ACMR0 */

#define CSL_MLBDIM_ACMR0_CHM_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_ACMR0_CHM_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_ACMR0_CHM_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACMR0_CHM_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_ACMR0_RESETVAL                                              (0x00000000U)

/* ACMR1 */

#define CSL_MLBDIM_ACMR1_CHM_MASK                                              (0xFFFFFFFFU)
#define CSL_MLBDIM_ACMR1_CHM_SHIFT                                             (0x00000000U)
#define CSL_MLBDIM_ACMR1_CHM_RESETVAL                                          (0x00000000U)
#define CSL_MLBDIM_ACMR1_CHM_MAX                                               (0xFFFFFFFFU)

#define CSL_MLBDIM_ACMR1_RESETVAL                                              (0x00000000U)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t REV;                       /* Aggregator Revision Register */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t VECTOR;                    /* ECC Vector Register */
    volatile uint32_t STAT;                      /* Misc Status */
    volatile uint32_t WRAP_REV;                  /* ECC Wrapper Revision Register */
    volatile uint32_t CTRL;                      /* ECC Control */
    volatile uint32_t ERR_CTRL1;                 /* ECC Error Control1 Register */
    volatile uint32_t ERR_CTRL2;                 /* ECC Error Control2 Register */
    volatile uint32_t ERR_STAT1;                 /* ECC Error Status1 Register */
    volatile uint32_t ERR_STAT2;                 /* ECC Error Status1 Register */
} CSL_ecc_aggrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_ECC_AGGR_REV                                                       (0x00000000U)
#define CSL_ECC_AGGR_VECTOR                                                    (0x00000008U)
#define CSL_ECC_AGGR_STAT                                                      (0x0000000CU)
#define CSL_ECC_AGGR_WRAP_REV                                                  (0x00000010U)
#define CSL_ECC_AGGR_CTRL                                                      (0x00000014U)
#define CSL_ECC_AGGR_ERR_CTRL1                                                 (0x00000018U)
#define CSL_ECC_AGGR_ERR_CTRL2                                                 (0x0000001CU)
#define CSL_ECC_AGGR_ERR_STAT1                                                 (0x00000020U)
#define CSL_ECC_AGGR_ERR_STAT2                                                 (0x00000024U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REV */

#define CSL_ECC_AGGR_REV_SCHEME_MASK                                           (0xC0000000U)
#define CSL_ECC_AGGR_REV_SCHEME_SHIFT                                          (0x0000001EU)
#define CSL_ECC_AGGR_REV_SCHEME_RESETVAL                                       (0x00000001U)
#define CSL_ECC_AGGR_REV_SCHEME_MAX                                            (0x00000003U)

#define CSL_ECC_AGGR_REV_MODULE_ID_MASK                                        (0x0FFF0000U)
#define CSL_ECC_AGGR_REV_MODULE_ID_SHIFT                                       (0x00000010U)
#define CSL_ECC_AGGR_REV_MODULE_ID_RESETVAL                                    (0x00000E10U)
#define CSL_ECC_AGGR_REV_MODULE_ID_MAX                                         (0x00000FFFU)

#define CSL_ECC_AGGR_REV_REVRTL_MASK                                           (0x0000F800U)
#define CSL_ECC_AGGR_REV_REVRTL_SHIFT                                          (0x0000000BU)
#define CSL_ECC_AGGR_REV_REVRTL_RESETVAL                                       (0x00000008U)
#define CSL_ECC_AGGR_REV_REVRTL_MAX                                            (0x0000001FU)

#define CSL_ECC_AGGR_REV_REVMAJ_MASK                                           (0x00000700U)
#define CSL_ECC_AGGR_REV_REVMAJ_SHIFT                                          (0x00000008U)
#define CSL_ECC_AGGR_REV_REVMAJ_RESETVAL                                       (0x00000002U)
#define CSL_ECC_AGGR_REV_REVMAJ_MAX                                            (0x00000007U)

#define CSL_ECC_AGGR_REV_CUSTOM_MASK                                           (0x000000C0U)
#define CSL_ECC_AGGR_REV_CUSTOM_SHIFT                                          (0x00000006U)
#define CSL_ECC_AGGR_REV_CUSTOM_RESETVAL                                       (0x00000000U)
#define CSL_ECC_AGGR_REV_CUSTOM_MAX                                            (0x00000003U)

#define CSL_ECC_AGGR_REV_REVMIN_MASK                                           (0x0000003FU)
#define CSL_ECC_AGGR_REV_REVMIN_SHIFT                                          (0x00000000U)
#define CSL_ECC_AGGR_REV_REVMIN_RESETVAL                                       (0x00000000U)
#define CSL_ECC_AGGR_REV_REVMIN_MAX                                            (0x0000003FU)

#define CSL_ECC_AGGR_REV_RESETVAL                                              (0x4E104200U)

/* VECTOR */

#define CSL_ECC_AGGR_VECTOR_ECC_VECTOR_MASK                                    (0x000007FFU)
#define CSL_ECC_AGGR_VECTOR_ECC_VECTOR_SHIFT                                   (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_ECC_VECTOR_RESETVAL                                (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_ECC_VECTOR_MAX                                     (0x000007FFU)

#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_MASK                                      (0x00008000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_SHIFT                                     (0x0000000FU)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_RESETVAL                                  (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_MAX                                       (0x00000001U)

#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_MASK                              (0x00FF0000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_SHIFT                             (0x00000010U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_RESETVAL                          (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_MAX                               (0x000000FFU)

#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_DONE_MASK                                 (0x01000000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_DONE_SHIFT                                (0x00000018U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_DONE_RESETVAL                             (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_RD_SVBUS_DONE_MAX                                  (0x00000001U)

#define CSL_ECC_AGGR_VECTOR_RESETVAL                                           (0x00000000U)

/* STAT */

#define CSL_ECC_AGGR_STAT_NUM_RAMS_MASK                                        (0x000007FFU)
#define CSL_ECC_AGGR_STAT_NUM_RAMS_SHIFT                                       (0x00000000U)
#define CSL_ECC_AGGR_STAT_NUM_RAMS_RESETVAL                                    (0x00000001U)
#define CSL_ECC_AGGR_STAT_NUM_RAMS_MAX                                         (0x000007FFU)

#define CSL_ECC_AGGR_STAT_RESETVAL                                             (0x00000001U)

/* WRAP_REV */

#define CSL_ECC_AGGR_WRAP_REV_SCHEME_MASK                                      (0xC0000000U)
#define CSL_ECC_AGGR_WRAP_REV_SCHEME_SHIFT                                     (0x0000001EU)
#define CSL_ECC_AGGR_WRAP_REV_SCHEME_RESETVAL                                  (0x00000001U)
#define CSL_ECC_AGGR_WRAP_REV_SCHEME_MAX                                       (0x00000003U)

#define CSL_ECC_AGGR_WRAP_REV_MODULE_ID_MASK                                   (0x0FFF0000U)
#define CSL_ECC_AGGR_WRAP_REV_MODULE_ID_SHIFT                                  (0x00000010U)
#define CSL_ECC_AGGR_WRAP_REV_MODULE_ID_RESETVAL                               (0x00000E11U)
#define CSL_ECC_AGGR_WRAP_REV_MODULE_ID_MAX                                    (0x00000FFFU)

#define CSL_ECC_AGGR_WRAP_REV_REVRTL_MASK                                      (0x0000F800U)
#define CSL_ECC_AGGR_WRAP_REV_REVRTL_SHIFT                                     (0x0000000BU)
#define CSL_ECC_AGGR_WRAP_REV_REVRTL_RESETVAL                                  (0x00000000U)
#define CSL_ECC_AGGR_WRAP_REV_REVRTL_MAX                                       (0x0000001FU)

#define CSL_ECC_AGGR_WRAP_REV_REVMAJ_MASK                                      (0x00000700U)
#define CSL_ECC_AGGR_WRAP_REV_REVMAJ_SHIFT                                     (0x00000008U)
#define CSL_ECC_AGGR_WRAP_REV_REVMAJ_RESETVAL                                  (0x00000000U)
#define CSL_ECC_AGGR_WRAP_REV_REVMAJ_MAX                                       (0x00000007U)

#define CSL_ECC_AGGR_WRAP_REV_CUSTOM_MASK                                      (0x000000C0U)
#define CSL_ECC_AGGR_WRAP_REV_CUSTOM_SHIFT                                     (0x00000006U)
#define CSL_ECC_AGGR_WRAP_REV_CUSTOM_RESETVAL                                  (0x00000000U)
#define CSL_ECC_AGGR_WRAP_REV_CUSTOM_MAX                                       (0x00000003U)

#define CSL_ECC_AGGR_WRAP_REV_REVMIN_MASK                                      (0x0000003FU)
#define CSL_ECC_AGGR_WRAP_REV_REVMIN_SHIFT                                     (0x00000000U)
#define CSL_ECC_AGGR_WRAP_REV_REVMIN_RESETVAL                                  (0x00000001U)
#define CSL_ECC_AGGR_WRAP_REV_REVMIN_MAX                                       (0x0000003FU)

#define CSL_ECC_AGGR_WRAP_REV_RESETVAL                                         (0x4E110001U)

/* CTRL */

#define CSL_ECC_AGGR_CTRL_ECC_ENABLE_MASK                                      (0x00000001U)
#define CSL_ECC_AGGR_CTRL_ECC_ENABLE_SHIFT                                     (0x00000000U)
#define CSL_ECC_AGGR_CTRL_ECC_ENABLE_RESETVAL                                  (0x00000001U)
#define CSL_ECC_AGGR_CTRL_ECC_ENABLE_MAX                                       (0x00000001U)

#define CSL_ECC_AGGR_CTRL_ECC_CHECK_MASK                                       (0x00000002U)
#define CSL_ECC_AGGR_CTRL_ECC_CHECK_SHIFT                                      (0x00000001U)
#define CSL_ECC_AGGR_CTRL_ECC_CHECK_RESETVAL                                   (0x00000001U)
#define CSL_ECC_AGGR_CTRL_ECC_CHECK_MAX                                        (0x00000001U)

#define CSL_ECC_AGGR_CTRL_ENABLE_RMW_MASK                                      (0x00000004U)
#define CSL_ECC_AGGR_CTRL_ENABLE_RMW_SHIFT                                     (0x00000002U)
#define CSL_ECC_AGGR_CTRL_ENABLE_RMW_RESETVAL                                  (0x00000001U)
#define CSL_ECC_AGGR_CTRL_ENABLE_RMW_MAX                                       (0x00000001U)

#define CSL_ECC_AGGR_CTRL_FORCE_SEC_MASK                                       (0x00000008U)
#define CSL_ECC_AGGR_CTRL_FORCE_SEC_SHIFT                                      (0x00000003U)
#define CSL_ECC_AGGR_CTRL_FORCE_SEC_RESETVAL                                   (0x00000000U)
#define CSL_ECC_AGGR_CTRL_FORCE_SEC_MAX                                        (0x00000001U)

#define CSL_ECC_AGGR_CTRL_FORCE_DED_MASK                                       (0x00000010U)
#define CSL_ECC_AGGR_CTRL_FORCE_DED_SHIFT                                      (0x00000004U)
#define CSL_ECC_AGGR_CTRL_FORCE_DED_RESETVAL                                   (0x00000000U)
#define CSL_ECC_AGGR_CTRL_FORCE_DED_MAX                                        (0x00000001U)

#define CSL_ECC_AGGR_CTRL_FORCE_N_ROW_MASK                                     (0x00000020U)
#define CSL_ECC_AGGR_CTRL_FORCE_N_ROW_SHIFT                                    (0x00000005U)
#define CSL_ECC_AGGR_CTRL_FORCE_N_ROW_RESETVAL                                 (0x00000000U)
#define CSL_ECC_AGGR_CTRL_FORCE_N_ROW_MAX                                      (0x00000001U)

#define CSL_ECC_AGGR_CTRL_ERROR_ONCE_MASK                                      (0x00000040U)
#define CSL_ECC_AGGR_CTRL_ERROR_ONCE_SHIFT                                     (0x00000006U)
#define CSL_ECC_AGGR_CTRL_ERROR_ONCE_RESETVAL                                  (0x00000000U)
#define CSL_ECC_AGGR_CTRL_ERROR_ONCE_MAX                                       (0x00000001U)

#define CSL_ECC_AGGR_CTRL_RESETVAL                                             (0x00000007U)

/* ERR_CTRL1 */

#define CSL_ECC_AGGR_ERR_CTRL1_ECC_ROW_MASK                                    (0x0000FFFFU)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_ROW_SHIFT                                   (0x00000000U)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_ROW_RESETVAL                                (0x00000000U)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_ROW_MAX                                     (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_CTRL1_ECC_BIT1_MASK                                   (0xFFFF0000U)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_BIT1_SHIFT                                  (0x00000010U)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_BIT1_RESETVAL                               (0x00000000U)
#define CSL_ECC_AGGR_ERR_CTRL1_ECC_BIT1_MAX                                    (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_CTRL1_RESETVAL                                        (0x00000000U)

/* ERR_CTRL2 */

#define CSL_ECC_AGGR_ERR_CTRL2_ECC_BIT2_MASK                                   (0x0000FFFFU)
#define CSL_ECC_AGGR_ERR_CTRL2_ECC_BIT2_SHIFT                                  (0x00000000U)
#define CSL_ECC_AGGR_ERR_CTRL2_ECC_BIT2_RESETVAL                               (0x00000000U)
#define CSL_ECC_AGGR_ERR_CTRL2_ECC_BIT2_MAX                                    (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_CTRL2_RESETVAL                                        (0x00000000U)

/* ERR_STAT1 */

#define CSL_ECC_AGGR_ERR_STAT1_ECC_SEC_MASK                                    (0x00000001U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_SEC_SHIFT                                   (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_SEC_RESETVAL                                (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_SEC_MAX                                     (0x00000001U)

#define CSL_ECC_AGGR_ERR_STAT1_ECC_DED_MASK                                    (0x00000002U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_DED_SHIFT                                   (0x00000001U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_DED_RESETVAL                                (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_DED_MAX                                     (0x00000001U)

#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_MASK                                (0x00000100U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_SHIFT                               (0x00000008U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_RESETVAL                            (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_MAX                                 (0x00000001U)

#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_MASK                                (0x00000200U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_SHIFT                               (0x00000009U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_RESETVAL                            (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_MAX                                 (0x00000001U)

#define CSL_ECC_AGGR_ERR_STAT1_ECC_ROW_MASK                                    (0xFFFF0000U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_ROW_SHIFT                                   (0x00000010U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_ROW_RESETVAL                                (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT1_ECC_ROW_MAX                                     (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_STAT1_RESETVAL                                        (0x00000000U)

/* ERR_STAT2 */

#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT1_MASK                                   (0x0000FFFFU)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT1_SHIFT                                  (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT1_RESETVAL                               (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT1_MAX                                    (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT2_MASK                                   (0xFFFF0000U)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT2_SHIFT                                  (0x00000010U)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT2_RESETVAL                               (0x00000000U)
#define CSL_ECC_AGGR_ERR_STAT2_ECC_BIT2_MAX                                    (0x0000FFFFU)

#define CSL_ECC_AGGR_ERR_STAT2_RESETVAL                                        (0x00000000U)

/**************************************************************************
* Hardware Region  : KSBUS Region-Based Address Translation
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t CTRL0;                     /* Region0 Control Register */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t BASE0;                     /* Region0 Base Register */
    volatile uint32_t SIZE0;                     /* Region0 Size Register */
    volatile uint32_t UPPER0;                    /* Region0 Upper Address */
    volatile uint32_t LOWER0;                    /* Region0 Lower Address */
    volatile uint32_t CTRL1;                     /* Region1 Control Register */
    volatile uint8_t  Resv_48[12];
    volatile uint32_t BASE1;                     /* Region1 Base Register */
    volatile uint32_t SIZE1;                     /* Region1 Size Register */
    volatile uint32_t UPPER1;                    /* Region1 Upper Address */
    volatile uint32_t LOWER1;                    /* Region1 Lower Address */
    volatile uint32_t CTRL2;                     /* Region2 Control Register */
    volatile uint8_t  Resv_80[12];
    volatile uint32_t BASE2;                     /* Region2 Base Register */
    volatile uint32_t SIZE2;                     /* Region2 Size Register */
    volatile uint32_t UPPER2;                    /* Region2 Upper Address */
    volatile uint32_t LOWER2;                    /* Region2 Lower Address */
    volatile uint32_t CTRL3;                     /* Region3 Control Register */
    volatile uint8_t  Resv_112[12];
    volatile uint32_t BASE3;                     /* Region3 Base Register */
    volatile uint32_t SIZE3;                     /* Region3 Size Register */
    volatile uint32_t UPPER3;                    /* Region3 Upper Address */
    volatile uint32_t LOWER3;                    /* Region3 Lower Address */
    volatile uint32_t CTRL4;                     /* Region4 Control Register */
    volatile uint8_t  Resv_144[12];
    volatile uint32_t BASE4;                     /* Region4 Base Register */
    volatile uint32_t SIZE4;                     /* Region4 Size Register */
    volatile uint32_t UPPER4;                    /* Region4 Upper Address */
    volatile uint32_t LOWER4;                    /* Region4 Lower Address */
    volatile uint32_t CTRL5;                     /* Region5 Control Register */
    volatile uint8_t  Resv_176[12];
    volatile uint32_t BASE5;                     /* Region5 Base Register */
    volatile uint32_t SIZE5;                     /* Region5 Size Register */
    volatile uint32_t UPPER5;                    /* Region5 Upper Address */
    volatile uint32_t LOWER5;                    /* Region5 Lower Address */
    volatile uint32_t CTRL6;                     /* Region6 Control Register */
    volatile uint8_t  Resv_208[12];
    volatile uint32_t BASE6;                     /* Region6 Base Register */
    volatile uint32_t SIZE6;                     /* Region6 Size Register */
    volatile uint32_t UPPER6;                    /* Region6 Upper Address */
    volatile uint32_t LOWER6;                    /* Region6 Lower Address */
    volatile uint32_t CTRL7;                     /* Region7 Control Register */
    volatile uint8_t  Resv_240[12];
    volatile uint32_t BASE7;                     /* Region7 Base Register */
    volatile uint32_t SIZE7;                     /* Region7 Size Register */
    volatile uint32_t UPPER7;                    /* Region7 Upper Address */
    volatile uint32_t LOWER7;                    /* Region7 Lower Address */
    volatile uint32_t CTRL8;                     /* Region8 Control Register */
    volatile uint8_t  Resv_272[12];
    volatile uint32_t BASE8;                     /* Region8 Base Register */
    volatile uint32_t SIZE8;                     /* Region8 Size Register */
    volatile uint32_t UPPER8;                    /* Region8 Upper Address */
    volatile uint32_t LOWER8;                    /* Region8 Lower Address */
    volatile uint32_t CTRL9;                     /* Region9 Control Register */
    volatile uint8_t  Resv_304[12];
    volatile uint32_t BASE9;                     /* Region9 Base Register */
    volatile uint32_t SIZE9;                     /* Region9 Size Register */
    volatile uint32_t UPPER9;                    /* Region9 Upper Address */
    volatile uint32_t LOWER9;                    /* Region9 Lower Address */
    volatile uint32_t CTRL10;                    /* Region10 Control Register */
    volatile uint8_t  Resv_336[12];
    volatile uint32_t BASE10;                    /* Region10 Base Register */
    volatile uint32_t SIZE10;                    /* Region10 Size Register */
    volatile uint32_t UPPER10;                   /* Region10 Upper Address */
    volatile uint32_t LOWER10;                   /* Region10 Lower Address */
    volatile uint32_t CTRL11;                    /* Region11 Control Register */
    volatile uint8_t  Resv_368[12];
    volatile uint32_t BASE11;                    /* Region11 Base Register */
    volatile uint32_t SIZE11;                    /* Region11 Size Register */
    volatile uint32_t UPPER11;                   /* Region11 Upper Address */
    volatile uint32_t LOWER11;                   /* Region11 Lower Address */
    volatile uint32_t CTRL12;                    /* Region12 Control Register */
    volatile uint8_t  Resv_400[12];
    volatile uint32_t BASE12;                    /* Region12 Base Register */
    volatile uint32_t SIZE12;                    /* Region12 Size Register */
    volatile uint32_t UPPER12;                   /* Region12 Upper Address */
    volatile uint32_t LOWER12;                   /* Region12 Lower Address */
    volatile uint32_t CTRL13;                    /* Region13 Control Register */
    volatile uint8_t  Resv_432[12];
    volatile uint32_t BASE13;                    /* Region13 Base Register */
    volatile uint32_t SIZE13;                    /* Region13 Size Register */
    volatile uint32_t UPPER13;                   /* Region13 Upper Address */
    volatile uint32_t LOWER13;                   /* Region13 Lower Address */
    volatile uint32_t CTRL14;                    /* Region14 Control Register */
    volatile uint8_t  Resv_464[12];
    volatile uint32_t BASE14;                    /* Region14 Base Register */
    volatile uint32_t SIZE14;                    /* Region14 Size Register */
    volatile uint32_t UPPER14;                   /* Region14 Upper Address */
    volatile uint32_t LOWER14;                   /* Region14 Lower Address */
    volatile uint32_t CTRL15;                    /* Region15 Control Register */
    volatile uint8_t  Resv_496[12];
    volatile uint32_t BASE15;                    /* Region15 Base Register */
    volatile uint32_t SIZE15;                    /* Region15 Size Register */
    volatile uint32_t UPPER15;                   /* Region15 Upper Address */
    volatile uint32_t LOWER15;                   /* Region15 Lower Address */
    volatile uint32_t CTRL16;                    /* Region16 Control Register */
    volatile uint8_t  Resv_528[12];
    volatile uint32_t BASE16;                    /* Region16 Base Register */
    volatile uint32_t SIZE16;                    /* Region16 Size Register */
    volatile uint32_t UPPER16;                   /* Region16 Upper Address */
    volatile uint32_t LOWER16;                   /* Region16 Lower Address */
    volatile uint32_t CTRL17;                    /* Region17 Control Register */
    volatile uint8_t  Resv_560[12];
    volatile uint32_t BASE17;                    /* Region17 Base Register */
    volatile uint32_t SIZE17;                    /* Region17 Size Register */
    volatile uint32_t UPPER17;                   /* Region17 Upper Address */
    volatile uint32_t LOWER17;                   /* Region17 Lower Address */
    volatile uint32_t CTRL18;                    /* Region18 Control Register */
    volatile uint8_t  Resv_592[12];
    volatile uint32_t BASE18;                    /* Region18 Base Register */
    volatile uint32_t SIZE18;                    /* Region18 Size Register */
    volatile uint32_t UPPER18;                   /* Region18 Upper Address */
    volatile uint32_t LOWER18;                   /* Region18 Lower Address */
    volatile uint32_t CTRL19;                    /* Region19 Control Register */
    volatile uint8_t  Resv_624[12];
    volatile uint32_t BASE19;                    /* Region19 Base Register */
    volatile uint32_t SIZE19;                    /* Region19 Size Register */
    volatile uint32_t UPPER19;                   /* Region19 Upper Address */
    volatile uint32_t LOWER19;                   /* Region19 Lower Address */
    volatile uint32_t CTRL20;                    /* Region20 Control Register */
    volatile uint8_t  Resv_656[12];
    volatile uint32_t BASE20;                    /* Region20 Base Register */
    volatile uint32_t SIZE20;                    /* Region20 Size Register */
    volatile uint32_t UPPER20;                   /* Region20 Upper Address */
    volatile uint32_t LOWER20;                   /* Region20 Lower Address */
    volatile uint32_t CTRL21;                    /* Region21 Control Register */
    volatile uint8_t  Resv_688[12];
    volatile uint32_t BASE21;                    /* Region21 Base Register */
    volatile uint32_t SIZE21;                    /* Region21 Size Register */
    volatile uint32_t UPPER21;                   /* Region21 Upper Address */
    volatile uint32_t LOWER21;                   /* Region21 Lower Address */
    volatile uint32_t CTRL22;                    /* Region22 Control Register */
    volatile uint8_t  Resv_720[12];
    volatile uint32_t BASE22;                    /* Region22 Base Register */
    volatile uint32_t SIZE22;                    /* Region22 Size Register */
    volatile uint32_t UPPER22;                   /* Region22 Upper Address */
    volatile uint32_t LOWER22;                   /* Region22 Lower Address */
    volatile uint32_t CTRL23;                    /* Region23 Control Register */
    volatile uint8_t  Resv_752[12];
    volatile uint32_t BASE23;                    /* Region23 Base Register */
    volatile uint32_t SIZE23;                    /* Region23 Size Register */
    volatile uint32_t UPPER23;                   /* Region23 Upper Address */
    volatile uint32_t LOWER23;                   /* Region23 Lower Address */
    volatile uint32_t CTRL24;                    /* Region24 Control Register */
    volatile uint8_t  Resv_784[12];
    volatile uint32_t BASE24;                    /* Region24 Base Register */
    volatile uint32_t SIZE24;                    /* Region24 Size Register */
    volatile uint32_t UPPER24;                   /* Region24 Upper Address */
    volatile uint32_t LOWER24;                   /* Region24 Lower Address */
    volatile uint32_t CTRL25;                    /* Region25 Control Register */
    volatile uint8_t  Resv_816[12];
    volatile uint32_t BASE25;                    /* Region25 Base Register */
    volatile uint32_t SIZE25;                    /* Region25 Size Register */
    volatile uint32_t UPPER25;                   /* Region25 Upper Address */
    volatile uint32_t LOWER25;                   /* Region25 Lower Address */
    volatile uint32_t CTRL26;                    /* Region26 Control Register */
    volatile uint8_t  Resv_848[12];
    volatile uint32_t BASE26;                    /* Region26 Base Register */
    volatile uint32_t SIZE26;                    /* Region26 Size Register */
    volatile uint32_t UPPER26;                   /* Region26 Upper Address */
    volatile uint32_t LOWER26;                   /* Region26 Lower Address */
    volatile uint32_t CTRL27;                    /* Region27 Control Register */
    volatile uint8_t  Resv_880[12];
    volatile uint32_t BASE27;                    /* Region27 Base Register */
    volatile uint32_t SIZE27;                    /* Region27 Size Register */
    volatile uint32_t UPPER27;                   /* Region27 Upper Address */
    volatile uint32_t LOWER27;                   /* Region27 Lower Address */
    volatile uint32_t CTRL28;                    /* Region28 Control Register */
    volatile uint8_t  Resv_912[12];
    volatile uint32_t BASE28;                    /* Region28 Base Register */
    volatile uint32_t SIZE28;                    /* Region28 Size Register */
    volatile uint32_t UPPER28;                   /* Region28 Upper Address */
    volatile uint32_t LOWER28;                   /* Region28 Lower Address */
    volatile uint32_t CTRL29;                    /* Region29 Control Register */
    volatile uint8_t  Resv_944[12];
    volatile uint32_t BASE29;                    /* Region29 Base Register */
    volatile uint32_t SIZE29;                    /* Region29 Size Register */
    volatile uint32_t UPPER29;                   /* Region29 Upper Address */
    volatile uint32_t LOWER29;                   /* Region29 Lower Address */
    volatile uint32_t CTRL30;                    /* Region30 Control Register */
    volatile uint8_t  Resv_976[12];
    volatile uint32_t BASE30;                    /* Region30 Base Register */
    volatile uint32_t SIZE30;                    /* Region30 Size Register */
    volatile uint32_t UPPER30;                   /* Region30 Upper Address */
    volatile uint32_t LOWER30;                   /* Region30 Lower Address */
    volatile uint32_t CTRL31;                    /* Region31 Control Register */
    volatile uint8_t  Resv_1008[12];
    volatile uint32_t BASE31;                    /* Region31 Base Register */
    volatile uint32_t SIZE31;                    /* Region31 Size Register */
    volatile uint32_t UPPER31;                   /* Region31 Upper Address */
    volatile uint32_t LOWER31;                   /* Region31 Lower Address */
    volatile uint32_t CTRL32;                    /* Region32 Control Register */
    volatile uint8_t  Resv_1040[12];
    volatile uint32_t BASE32;                    /* Region32 Base Register */
    volatile uint32_t SIZE32;                    /* Region32 Size Register */
    volatile uint32_t UPPER32;                   /* Region32 Upper Address */
    volatile uint32_t LOWER32;                   /* Region32 Lower Address */
    volatile uint32_t CTRL33;                    /* Region33 Control Register */
    volatile uint8_t  Resv_1072[12];
    volatile uint32_t BASE33;                    /* Region33 Base Register */
    volatile uint32_t SIZE33;                    /* Region33 Size Register */
    volatile uint32_t UPPER33;                   /* Region33 Upper Address */
    volatile uint32_t LOWER33;                   /* Region33 Lower Address */
    volatile uint32_t CTRL34;                    /* Region34 Control Register */
    volatile uint8_t  Resv_1104[12];
    volatile uint32_t BASE34;                    /* Region34 Base Register */
    volatile uint32_t SIZE34;                    /* Region34 Size Register */
    volatile uint32_t UPPER34;                   /* Region34 Upper Address */
    volatile uint32_t LOWER34;                   /* Region34 Lower Address */
    volatile uint32_t CTRL35;                    /* Region35 Control Register */
    volatile uint8_t  Resv_1136[12];
    volatile uint32_t BASE35;                    /* Region35 Base Register */
    volatile uint32_t SIZE35;                    /* Region35 Size Register */
    volatile uint32_t UPPER35;                   /* Region35 Upper Address */
    volatile uint32_t LOWER35;                   /* Region35 Lower Address */
    volatile uint32_t CTRL36;                    /* Region36 Control Register */
    volatile uint8_t  Resv_1168[12];
    volatile uint32_t BASE36;                    /* Region36 Base Register */
    volatile uint32_t SIZE36;                    /* Region36 Size Register */
    volatile uint32_t UPPER36;                   /* Region36 Upper Address */
    volatile uint32_t LOWER36;                   /* Region36 Lower Address */
    volatile uint32_t CTRL37;                    /* Region37 Control Register */
    volatile uint8_t  Resv_1200[12];
    volatile uint32_t BASE37;                    /* Region37 Base Register */
    volatile uint32_t SIZE37;                    /* Region37 Size Register */
    volatile uint32_t UPPER37;                   /* Region37 Upper Address */
    volatile uint32_t LOWER37;                   /* Region37 Lower Address */
    volatile uint32_t CTRL38;                    /* Region38 Control Register */
    volatile uint8_t  Resv_1232[12];
    volatile uint32_t BASE38;                    /* Region38 Base Register */
    volatile uint32_t SIZE38;                    /* Region38 Size Register */
    volatile uint32_t UPPER38;                   /* Region38 Upper Address */
    volatile uint32_t LOWER38;                   /* Region38 Lower Address */
    volatile uint32_t CTRL39;                    /* Region39 Control Register */
    volatile uint8_t  Resv_1264[12];
    volatile uint32_t BASE39;                    /* Region39 Base Register */
    volatile uint32_t SIZE39;                    /* Region39 Size Register */
    volatile uint32_t UPPER39;                   /* Region39 Upper Address */
    volatile uint32_t LOWER39;                   /* Region39 Lower Address */
    volatile uint32_t CTRL40;                    /* Region40 Control Register */
    volatile uint8_t  Resv_1296[12];
    volatile uint32_t BASE40;                    /* Region40 Base Register */
    volatile uint32_t SIZE40;                    /* Region40 Size Register */
    volatile uint32_t UPPER40;                   /* Region40 Upper Address */
    volatile uint32_t LOWER40;                   /* Region40 Lower Address */
    volatile uint32_t CTRL41;                    /* Region41 Control Register */
    volatile uint8_t  Resv_1328[12];
    volatile uint32_t BASE41;                    /* Region41 Base Register */
    volatile uint32_t SIZE41;                    /* Region41 Size Register */
    volatile uint32_t UPPER41;                   /* Region41 Upper Address */
    volatile uint32_t LOWER41;                   /* Region41 Lower Address */
    volatile uint32_t CTRL42;                    /* Region42 Control Register */
    volatile uint8_t  Resv_1360[12];
    volatile uint32_t BASE42;                    /* Region42 Base Register */
    volatile uint32_t SIZE42;                    /* Region42 Size Register */
    volatile uint32_t UPPER42;                   /* Region42 Upper Address */
    volatile uint32_t LOWER42;                   /* Region42 Lower Address */
    volatile uint32_t CTRL43;                    /* Region43 Control Register */
    volatile uint8_t  Resv_1392[12];
    volatile uint32_t BASE43;                    /* Region43 Base Register */
    volatile uint32_t SIZE43;                    /* Region43 Size Register */
    volatile uint32_t UPPER43;                   /* Region43 Upper Address */
    volatile uint32_t LOWER43;                   /* Region43 Lower Address */
    volatile uint32_t CTRL44;                    /* Region44 Control Register */
    volatile uint8_t  Resv_1424[12];
    volatile uint32_t BASE44;                    /* Region44 Base Register */
    volatile uint32_t SIZE44;                    /* Region44 Size Register */
    volatile uint32_t UPPER44;                   /* Region44 Upper Address */
    volatile uint32_t LOWER44;                   /* Region44 Lower Address */
    volatile uint32_t CTRL45;                    /* Region45 Control Register */
    volatile uint8_t  Resv_1456[12];
    volatile uint32_t BASE45;                    /* Region45 Base Register */
    volatile uint32_t SIZE45;                    /* Region45 Size Register */
    volatile uint32_t UPPER45;                   /* Region45 Upper Address */
    volatile uint32_t LOWER45;                   /* Region45 Lower Address */
    volatile uint32_t CTRL46;                    /* Region46 Control Register */
    volatile uint8_t  Resv_1488[12];
    volatile uint32_t BASE46;                    /* Region46 Base Register */
    volatile uint32_t SIZE46;                    /* Region46 Size Register */
    volatile uint32_t UPPER46;                   /* Region46 Upper Address */
    volatile uint32_t LOWER46;                   /* Region46 Lower Address */
    volatile uint32_t CTRL47;                    /* Region47 Control Register */
    volatile uint8_t  Resv_1520[12];
    volatile uint32_t BASE47;                    /* Region47 Base Register */
    volatile uint32_t SIZE47;                    /* Region47 Size Register */
    volatile uint32_t UPPER47;                   /* Region47 Upper Address */
    volatile uint32_t LOWER47;                   /* Region47 Lower Address */
    volatile uint32_t CTRL48;                    /* Region48 Control Register */
    volatile uint8_t  Resv_1552[12];
    volatile uint32_t BASE48;                    /* Region48 Base Register */
    volatile uint32_t SIZE48;                    /* Region48 Size Register */
    volatile uint32_t UPPER48;                   /* Region48 Upper Address */
    volatile uint32_t LOWER48;                   /* Region48 Lower Address */
    volatile uint32_t CTRL49;                    /* Region49 Control Register */
    volatile uint8_t  Resv_1584[12];
    volatile uint32_t BASE49;                    /* Region49 Base Register */
    volatile uint32_t SIZE49;                    /* Region49 Size Register */
    volatile uint32_t UPPER49;                   /* Region49 Upper Address */
    volatile uint32_t LOWER49;                   /* Region49 Lower Address */
    volatile uint32_t CTRL50;                    /* Region50 Control Register */
    volatile uint8_t  Resv_1616[12];
    volatile uint32_t BASE50;                    /* Region50 Base Register */
    volatile uint32_t SIZE50;                    /* Region50 Size Register */
    volatile uint32_t UPPER50;                   /* Region50 Upper Address */
    volatile uint32_t LOWER50;                   /* Region50 Lower Address */
    volatile uint32_t CTRL51;                    /* Region51 Control Register */
    volatile uint8_t  Resv_1648[12];
    volatile uint32_t BASE51;                    /* Region51 Base Register */
    volatile uint32_t SIZE51;                    /* Region51 Size Register */
    volatile uint32_t UPPER51;                   /* Region51 Upper Address */
    volatile uint32_t LOWER51;                   /* Region51 Lower Address */
    volatile uint32_t CTRL52;                    /* Region52 Control Register */
    volatile uint8_t  Resv_1680[12];
    volatile uint32_t BASE52;                    /* Region52 Base Register */
    volatile uint32_t SIZE52;                    /* Region52 Size Register */
    volatile uint32_t UPPER52;                   /* Region52 Upper Address */
    volatile uint32_t LOWER52;                   /* Region52 Lower Address */
    volatile uint32_t CTRL53;                    /* Region53 Control Register */
    volatile uint8_t  Resv_1712[12];
    volatile uint32_t BASE53;                    /* Region53 Base Register */
    volatile uint32_t SIZE53;                    /* Region53 Size Register */
    volatile uint32_t UPPER53;                   /* Region53 Upper Address */
    volatile uint32_t LOWER53;                   /* Region53 Lower Address */
    volatile uint32_t CTRL54;                    /* Region54 Control Register */
    volatile uint8_t  Resv_1744[12];
    volatile uint32_t BASE54;                    /* Region54 Base Register */
    volatile uint32_t SIZE54;                    /* Region54 Size Register */
    volatile uint32_t UPPER54;                   /* Region54 Upper Address */
    volatile uint32_t LOWER54;                   /* Region54 Lower Address */
    volatile uint32_t CTRL55;                    /* Region55 Control Register */
    volatile uint8_t  Resv_1776[12];
    volatile uint32_t BASE55;                    /* Region55 Base Register */
    volatile uint32_t SIZE55;                    /* Region55 Size Register */
    volatile uint32_t UPPER55;                   /* Region55 Upper Address */
    volatile uint32_t LOWER55;                   /* Region55 Lower Address */
    volatile uint32_t CTRL56;                    /* Region56 Control Register */
    volatile uint8_t  Resv_1808[12];
    volatile uint32_t BASE56;                    /* Region56 Base Register */
    volatile uint32_t SIZE56;                    /* Region56 Size Register */
    volatile uint32_t UPPER56;                   /* Region56 Upper Address */
    volatile uint32_t LOWER56;                   /* Region56 Lower Address */
    volatile uint32_t CTRL57;                    /* Region57 Control Register */
    volatile uint8_t  Resv_1840[12];
    volatile uint32_t BASE57;                    /* Region57 Base Register */
    volatile uint32_t SIZE57;                    /* Region57 Size Register */
    volatile uint32_t UPPER57;                   /* Region57 Upper Address */
    volatile uint32_t LOWER57;                   /* Region57 Lower Address */
    volatile uint32_t CTRL58;                    /* Region58 Control Register */
    volatile uint8_t  Resv_1872[12];
    volatile uint32_t BASE58;                    /* Region58 Base Register */
    volatile uint32_t SIZE58;                    /* Region58 Size Register */
    volatile uint32_t UPPER58;                   /* Region58 Upper Address */
    volatile uint32_t LOWER58;                   /* Region58 Lower Address */
    volatile uint32_t CTRL59;                    /* Region59 Control Register */
    volatile uint8_t  Resv_1904[12];
    volatile uint32_t BASE59;                    /* Region59 Base Register */
    volatile uint32_t SIZE59;                    /* Region59 Size Register */
    volatile uint32_t UPPER59;                   /* Region59 Upper Address */
    volatile uint32_t LOWER59;                   /* Region59 Lower Address */
    volatile uint32_t CTRL60;                    /* Region60 Control Register */
    volatile uint8_t  Resv_1936[12];
    volatile uint32_t BASE60;                    /* Region60 Base Register */
    volatile uint32_t SIZE60;                    /* Region60 Size Register */
    volatile uint32_t UPPER60;                   /* Region60 Upper Address */
    volatile uint32_t LOWER60;                   /* Region60 Lower Address */
    volatile uint32_t CTRL61;                    /* Region61 Control Register */
    volatile uint8_t  Resv_1968[12];
    volatile uint32_t BASE61;                    /* Region61 Base Register */
    volatile uint32_t SIZE61;                    /* Region61 Size Register */
    volatile uint32_t UPPER61;                   /* Region61 Upper Address */
    volatile uint32_t LOWER61;                   /* Region61 Lower Address */
    volatile uint32_t CTRL62;                    /* Region62 Control Register */
    volatile uint8_t  Resv_2000[12];
    volatile uint32_t BASE62;                    /* Region62 Base Register */
    volatile uint32_t SIZE62;                    /* Region62 Size Register */
    volatile uint32_t UPPER62;                   /* Region62 Upper Address */
    volatile uint32_t LOWER62;                   /* Region62 Lower Address */
    volatile uint32_t CTRL63;                    /* Region63 Control Register */
    volatile uint8_t  Resv_2032[12];
    volatile uint32_t BASE63;                    /* Region63 Base Register */
    volatile uint32_t SIZE63;                    /* Region63 Size Register */
    volatile uint32_t UPPER63;                   /* Region63 Upper Address */
    volatile uint32_t LOWER63;                   /* Region63 Lower Address */
} CSL_KSBUS_RATRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_KSBUS_RAT_CTRL0                                                    (0x00000000U)
#define CSL_KSBUS_RAT_BASE0                                                    (0x00000010U)
#define CSL_KSBUS_RAT_SIZE0                                                    (0x00000014U)
#define CSL_KSBUS_RAT_UPPER0                                                   (0x00000018U)
#define CSL_KSBUS_RAT_LOWER0                                                   (0x0000001CU)
#define CSL_KSBUS_RAT_CTRL1                                                    (0x00000020U)
#define CSL_KSBUS_RAT_BASE1                                                    (0x00000030U)
#define CSL_KSBUS_RAT_SIZE1                                                    (0x00000034U)
#define CSL_KSBUS_RAT_UPPER1                                                   (0x00000038U)
#define CSL_KSBUS_RAT_LOWER1                                                   (0x0000003CU)
#define CSL_KSBUS_RAT_CTRL2                                                    (0x00000040U)
#define CSL_KSBUS_RAT_BASE2                                                    (0x00000050U)
#define CSL_KSBUS_RAT_SIZE2                                                    (0x00000054U)
#define CSL_KSBUS_RAT_UPPER2                                                   (0x00000058U)
#define CSL_KSBUS_RAT_LOWER2                                                   (0x0000005CU)
#define CSL_KSBUS_RAT_CTRL3                                                    (0x00000060U)
#define CSL_KSBUS_RAT_BASE3                                                    (0x00000070U)
#define CSL_KSBUS_RAT_SIZE3                                                    (0x00000074U)
#define CSL_KSBUS_RAT_UPPER3                                                   (0x00000078U)
#define CSL_KSBUS_RAT_LOWER3                                                   (0x0000007CU)
#define CSL_KSBUS_RAT_CTRL4                                                    (0x00000080U)
#define CSL_KSBUS_RAT_BASE4                                                    (0x00000090U)
#define CSL_KSBUS_RAT_SIZE4                                                    (0x00000094U)
#define CSL_KSBUS_RAT_UPPER4                                                   (0x00000098U)
#define CSL_KSBUS_RAT_LOWER4                                                   (0x0000009CU)
#define CSL_KSBUS_RAT_CTRL5                                                    (0x000000A0U)
#define CSL_KSBUS_RAT_BASE5                                                    (0x000000B0U)
#define CSL_KSBUS_RAT_SIZE5                                                    (0x000000B4U)
#define CSL_KSBUS_RAT_UPPER5                                                   (0x000000B8U)
#define CSL_KSBUS_RAT_LOWER5                                                   (0x000000BCU)
#define CSL_KSBUS_RAT_CTRL6                                                    (0x000000C0U)
#define CSL_KSBUS_RAT_BASE6                                                    (0x000000D0U)
#define CSL_KSBUS_RAT_SIZE6                                                    (0x000000D4U)
#define CSL_KSBUS_RAT_UPPER6                                                   (0x000000D8U)
#define CSL_KSBUS_RAT_LOWER6                                                   (0x000000DCU)
#define CSL_KSBUS_RAT_CTRL7                                                    (0x000000E0U)
#define CSL_KSBUS_RAT_BASE7                                                    (0x000000F0U)
#define CSL_KSBUS_RAT_SIZE7                                                    (0x000000F4U)
#define CSL_KSBUS_RAT_UPPER7                                                   (0x000000F8U)
#define CSL_KSBUS_RAT_LOWER7                                                   (0x000000FCU)
#define CSL_KSBUS_RAT_CTRL8                                                    (0x00000100U)
#define CSL_KSBUS_RAT_BASE8                                                    (0x00000110U)
#define CSL_KSBUS_RAT_SIZE8                                                    (0x00000114U)
#define CSL_KSBUS_RAT_UPPER8                                                   (0x00000118U)
#define CSL_KSBUS_RAT_LOWER8                                                   (0x0000011CU)
#define CSL_KSBUS_RAT_CTRL9                                                    (0x00000120U)
#define CSL_KSBUS_RAT_BASE9                                                    (0x00000130U)
#define CSL_KSBUS_RAT_SIZE9                                                    (0x00000134U)
#define CSL_KSBUS_RAT_UPPER9                                                   (0x00000138U)
#define CSL_KSBUS_RAT_LOWER9                                                   (0x0000013CU)
#define CSL_KSBUS_RAT_CTRL10                                                   (0x00000140U)
#define CSL_KSBUS_RAT_BASE10                                                   (0x00000150U)
#define CSL_KSBUS_RAT_SIZE10                                                   (0x00000154U)
#define CSL_KSBUS_RAT_UPPER10                                                  (0x00000158U)
#define CSL_KSBUS_RAT_LOWER10                                                  (0x0000015CU)
#define CSL_KSBUS_RAT_CTRL11                                                   (0x00000160U)
#define CSL_KSBUS_RAT_BASE11                                                   (0x00000170U)
#define CSL_KSBUS_RAT_SIZE11                                                   (0x00000174U)
#define CSL_KSBUS_RAT_UPPER11                                                  (0x00000178U)
#define CSL_KSBUS_RAT_LOWER11                                                  (0x0000017CU)
#define CSL_KSBUS_RAT_CTRL12                                                   (0x00000180U)
#define CSL_KSBUS_RAT_BASE12                                                   (0x00000190U)
#define CSL_KSBUS_RAT_SIZE12                                                   (0x00000194U)
#define CSL_KSBUS_RAT_UPPER12                                                  (0x00000198U)
#define CSL_KSBUS_RAT_LOWER12                                                  (0x0000019CU)
#define CSL_KSBUS_RAT_CTRL13                                                   (0x000001A0U)
#define CSL_KSBUS_RAT_BASE13                                                   (0x000001B0U)
#define CSL_KSBUS_RAT_SIZE13                                                   (0x000001B4U)
#define CSL_KSBUS_RAT_UPPER13                                                  (0x000001B8U)
#define CSL_KSBUS_RAT_LOWER13                                                  (0x000001BCU)
#define CSL_KSBUS_RAT_CTRL14                                                   (0x000001C0U)
#define CSL_KSBUS_RAT_BASE14                                                   (0x000001D0U)
#define CSL_KSBUS_RAT_SIZE14                                                   (0x000001D4U)
#define CSL_KSBUS_RAT_UPPER14                                                  (0x000001D8U)
#define CSL_KSBUS_RAT_LOWER14                                                  (0x000001DCU)
#define CSL_KSBUS_RAT_CTRL15                                                   (0x000001E0U)
#define CSL_KSBUS_RAT_BASE15                                                   (0x000001F0U)
#define CSL_KSBUS_RAT_SIZE15                                                   (0x000001F4U)
#define CSL_KSBUS_RAT_UPPER15                                                  (0x000001F8U)
#define CSL_KSBUS_RAT_LOWER15                                                  (0x000001FCU)
#define CSL_KSBUS_RAT_CTRL16                                                   (0x00000200U)
#define CSL_KSBUS_RAT_BASE16                                                   (0x00000210U)
#define CSL_KSBUS_RAT_SIZE16                                                   (0x00000214U)
#define CSL_KSBUS_RAT_UPPER16                                                  (0x00000218U)
#define CSL_KSBUS_RAT_LOWER16                                                  (0x0000021CU)
#define CSL_KSBUS_RAT_CTRL17                                                   (0x00000220U)
#define CSL_KSBUS_RAT_BASE17                                                   (0x00000230U)
#define CSL_KSBUS_RAT_SIZE17                                                   (0x00000234U)
#define CSL_KSBUS_RAT_UPPER17                                                  (0x00000238U)
#define CSL_KSBUS_RAT_LOWER17                                                  (0x0000023CU)
#define CSL_KSBUS_RAT_CTRL18                                                   (0x00000240U)
#define CSL_KSBUS_RAT_BASE18                                                   (0x00000250U)
#define CSL_KSBUS_RAT_SIZE18                                                   (0x00000254U)
#define CSL_KSBUS_RAT_UPPER18                                                  (0x00000258U)
#define CSL_KSBUS_RAT_LOWER18                                                  (0x0000025CU)
#define CSL_KSBUS_RAT_CTRL19                                                   (0x00000260U)
#define CSL_KSBUS_RAT_BASE19                                                   (0x00000270U)
#define CSL_KSBUS_RAT_SIZE19                                                   (0x00000274U)
#define CSL_KSBUS_RAT_UPPER19                                                  (0x00000278U)
#define CSL_KSBUS_RAT_LOWER19                                                  (0x0000027CU)
#define CSL_KSBUS_RAT_CTRL20                                                   (0x00000280U)
#define CSL_KSBUS_RAT_BASE20                                                   (0x00000290U)
#define CSL_KSBUS_RAT_SIZE20                                                   (0x00000294U)
#define CSL_KSBUS_RAT_UPPER20                                                  (0x00000298U)
#define CSL_KSBUS_RAT_LOWER20                                                  (0x0000029CU)
#define CSL_KSBUS_RAT_CTRL21                                                   (0x000002A0U)
#define CSL_KSBUS_RAT_BASE21                                                   (0x000002B0U)
#define CSL_KSBUS_RAT_SIZE21                                                   (0x000002B4U)
#define CSL_KSBUS_RAT_UPPER21                                                  (0x000002B8U)
#define CSL_KSBUS_RAT_LOWER21                                                  (0x000002BCU)
#define CSL_KSBUS_RAT_CTRL22                                                   (0x000002C0U)
#define CSL_KSBUS_RAT_BASE22                                                   (0x000002D0U)
#define CSL_KSBUS_RAT_SIZE22                                                   (0x000002D4U)
#define CSL_KSBUS_RAT_UPPER22                                                  (0x000002D8U)
#define CSL_KSBUS_RAT_LOWER22                                                  (0x000002DCU)
#define CSL_KSBUS_RAT_CTRL23                                                   (0x000002E0U)
#define CSL_KSBUS_RAT_BASE23                                                   (0x000002F0U)
#define CSL_KSBUS_RAT_SIZE23                                                   (0x000002F4U)
#define CSL_KSBUS_RAT_UPPER23                                                  (0x000002F8U)
#define CSL_KSBUS_RAT_LOWER23                                                  (0x000002FCU)
#define CSL_KSBUS_RAT_CTRL24                                                   (0x00000300U)
#define CSL_KSBUS_RAT_BASE24                                                   (0x00000310U)
#define CSL_KSBUS_RAT_SIZE24                                                   (0x00000314U)
#define CSL_KSBUS_RAT_UPPER24                                                  (0x00000318U)
#define CSL_KSBUS_RAT_LOWER24                                                  (0x0000031CU)
#define CSL_KSBUS_RAT_CTRL25                                                   (0x00000320U)
#define CSL_KSBUS_RAT_BASE25                                                   (0x00000330U)
#define CSL_KSBUS_RAT_SIZE25                                                   (0x00000334U)
#define CSL_KSBUS_RAT_UPPER25                                                  (0x00000338U)
#define CSL_KSBUS_RAT_LOWER25                                                  (0x0000033CU)
#define CSL_KSBUS_RAT_CTRL26                                                   (0x00000340U)
#define CSL_KSBUS_RAT_BASE26                                                   (0x00000350U)
#define CSL_KSBUS_RAT_SIZE26                                                   (0x00000354U)
#define CSL_KSBUS_RAT_UPPER26                                                  (0x00000358U)
#define CSL_KSBUS_RAT_LOWER26                                                  (0x0000035CU)
#define CSL_KSBUS_RAT_CTRL27                                                   (0x00000360U)
#define CSL_KSBUS_RAT_BASE27                                                   (0x00000370U)
#define CSL_KSBUS_RAT_SIZE27                                                   (0x00000374U)
#define CSL_KSBUS_RAT_UPPER27                                                  (0x00000378U)
#define CSL_KSBUS_RAT_LOWER27                                                  (0x0000037CU)
#define CSL_KSBUS_RAT_CTRL28                                                   (0x00000380U)
#define CSL_KSBUS_RAT_BASE28                                                   (0x00000390U)
#define CSL_KSBUS_RAT_SIZE28                                                   (0x00000394U)
#define CSL_KSBUS_RAT_UPPER28                                                  (0x00000398U)
#define CSL_KSBUS_RAT_LOWER28                                                  (0x0000039CU)
#define CSL_KSBUS_RAT_CTRL29                                                   (0x000003A0U)
#define CSL_KSBUS_RAT_BASE29                                                   (0x000003B0U)
#define CSL_KSBUS_RAT_SIZE29                                                   (0x000003B4U)
#define CSL_KSBUS_RAT_UPPER29                                                  (0x000003B8U)
#define CSL_KSBUS_RAT_LOWER29                                                  (0x000003BCU)
#define CSL_KSBUS_RAT_CTRL30                                                   (0x000003C0U)
#define CSL_KSBUS_RAT_BASE30                                                   (0x000003D0U)
#define CSL_KSBUS_RAT_SIZE30                                                   (0x000003D4U)
#define CSL_KSBUS_RAT_UPPER30                                                  (0x000003D8U)
#define CSL_KSBUS_RAT_LOWER30                                                  (0x000003DCU)
#define CSL_KSBUS_RAT_CTRL31                                                   (0x000003E0U)
#define CSL_KSBUS_RAT_BASE31                                                   (0x000003F0U)
#define CSL_KSBUS_RAT_SIZE31                                                   (0x000003F4U)
#define CSL_KSBUS_RAT_UPPER31                                                  (0x000003F8U)
#define CSL_KSBUS_RAT_LOWER31                                                  (0x000003FCU)
#define CSL_KSBUS_RAT_CTRL32                                                   (0x00000400U)
#define CSL_KSBUS_RAT_BASE32                                                   (0x00000410U)
#define CSL_KSBUS_RAT_SIZE32                                                   (0x00000414U)
#define CSL_KSBUS_RAT_UPPER32                                                  (0x00000418U)
#define CSL_KSBUS_RAT_LOWER32                                                  (0x0000041CU)
#define CSL_KSBUS_RAT_CTRL33                                                   (0x00000420U)
#define CSL_KSBUS_RAT_BASE33                                                   (0x00000430U)
#define CSL_KSBUS_RAT_SIZE33                                                   (0x00000434U)
#define CSL_KSBUS_RAT_UPPER33                                                  (0x00000438U)
#define CSL_KSBUS_RAT_LOWER33                                                  (0x0000043CU)
#define CSL_KSBUS_RAT_CTRL34                                                   (0x00000440U)
#define CSL_KSBUS_RAT_BASE34                                                   (0x00000450U)
#define CSL_KSBUS_RAT_SIZE34                                                   (0x00000454U)
#define CSL_KSBUS_RAT_UPPER34                                                  (0x00000458U)
#define CSL_KSBUS_RAT_LOWER34                                                  (0x0000045CU)
#define CSL_KSBUS_RAT_CTRL35                                                   (0x00000460U)
#define CSL_KSBUS_RAT_BASE35                                                   (0x00000470U)
#define CSL_KSBUS_RAT_SIZE35                                                   (0x00000474U)
#define CSL_KSBUS_RAT_UPPER35                                                  (0x00000478U)
#define CSL_KSBUS_RAT_LOWER35                                                  (0x0000047CU)
#define CSL_KSBUS_RAT_CTRL36                                                   (0x00000480U)
#define CSL_KSBUS_RAT_BASE36                                                   (0x00000490U)
#define CSL_KSBUS_RAT_SIZE36                                                   (0x00000494U)
#define CSL_KSBUS_RAT_UPPER36                                                  (0x00000498U)
#define CSL_KSBUS_RAT_LOWER36                                                  (0x0000049CU)
#define CSL_KSBUS_RAT_CTRL37                                                   (0x000004A0U)
#define CSL_KSBUS_RAT_BASE37                                                   (0x000004B0U)
#define CSL_KSBUS_RAT_SIZE37                                                   (0x000004B4U)
#define CSL_KSBUS_RAT_UPPER37                                                  (0x000004B8U)
#define CSL_KSBUS_RAT_LOWER37                                                  (0x000004BCU)
#define CSL_KSBUS_RAT_CTRL38                                                   (0x000004C0U)
#define CSL_KSBUS_RAT_BASE38                                                   (0x000004D0U)
#define CSL_KSBUS_RAT_SIZE38                                                   (0x000004D4U)
#define CSL_KSBUS_RAT_UPPER38                                                  (0x000004D8U)
#define CSL_KSBUS_RAT_LOWER38                                                  (0x000004DCU)
#define CSL_KSBUS_RAT_CTRL39                                                   (0x000004E0U)
#define CSL_KSBUS_RAT_BASE39                                                   (0x000004F0U)
#define CSL_KSBUS_RAT_SIZE39                                                   (0x000004F4U)
#define CSL_KSBUS_RAT_UPPER39                                                  (0x000004F8U)
#define CSL_KSBUS_RAT_LOWER39                                                  (0x000004FCU)
#define CSL_KSBUS_RAT_CTRL40                                                   (0x00000500U)
#define CSL_KSBUS_RAT_BASE40                                                   (0x00000510U)
#define CSL_KSBUS_RAT_SIZE40                                                   (0x00000514U)
#define CSL_KSBUS_RAT_UPPER40                                                  (0x00000518U)
#define CSL_KSBUS_RAT_LOWER40                                                  (0x0000051CU)
#define CSL_KSBUS_RAT_CTRL41                                                   (0x00000520U)
#define CSL_KSBUS_RAT_BASE41                                                   (0x00000530U)
#define CSL_KSBUS_RAT_SIZE41                                                   (0x00000534U)
#define CSL_KSBUS_RAT_UPPER41                                                  (0x00000538U)
#define CSL_KSBUS_RAT_LOWER41                                                  (0x0000053CU)
#define CSL_KSBUS_RAT_CTRL42                                                   (0x00000540U)
#define CSL_KSBUS_RAT_BASE42                                                   (0x00000550U)
#define CSL_KSBUS_RAT_SIZE42                                                   (0x00000554U)
#define CSL_KSBUS_RAT_UPPER42                                                  (0x00000558U)
#define CSL_KSBUS_RAT_LOWER42                                                  (0x0000055CU)
#define CSL_KSBUS_RAT_CTRL43                                                   (0x00000560U)
#define CSL_KSBUS_RAT_BASE43                                                   (0x00000570U)
#define CSL_KSBUS_RAT_SIZE43                                                   (0x00000574U)
#define CSL_KSBUS_RAT_UPPER43                                                  (0x00000578U)
#define CSL_KSBUS_RAT_LOWER43                                                  (0x0000057CU)
#define CSL_KSBUS_RAT_CTRL44                                                   (0x00000580U)
#define CSL_KSBUS_RAT_BASE44                                                   (0x00000590U)
#define CSL_KSBUS_RAT_SIZE44                                                   (0x00000594U)
#define CSL_KSBUS_RAT_UPPER44                                                  (0x00000598U)
#define CSL_KSBUS_RAT_LOWER44                                                  (0x0000059CU)
#define CSL_KSBUS_RAT_CTRL45                                                   (0x000005A0U)
#define CSL_KSBUS_RAT_BASE45                                                   (0x000005B0U)
#define CSL_KSBUS_RAT_SIZE45                                                   (0x000005B4U)
#define CSL_KSBUS_RAT_UPPER45                                                  (0x000005B8U)
#define CSL_KSBUS_RAT_LOWER45                                                  (0x000005BCU)
#define CSL_KSBUS_RAT_CTRL46                                                   (0x000005C0U)
#define CSL_KSBUS_RAT_BASE46                                                   (0x000005D0U)
#define CSL_KSBUS_RAT_SIZE46                                                   (0x000005D4U)
#define CSL_KSBUS_RAT_UPPER46                                                  (0x000005D8U)
#define CSL_KSBUS_RAT_LOWER46                                                  (0x000005DCU)
#define CSL_KSBUS_RAT_CTRL47                                                   (0x000005E0U)
#define CSL_KSBUS_RAT_BASE47                                                   (0x000005F0U)
#define CSL_KSBUS_RAT_SIZE47                                                   (0x000005F4U)
#define CSL_KSBUS_RAT_UPPER47                                                  (0x000005F8U)
#define CSL_KSBUS_RAT_LOWER47                                                  (0x000005FCU)
#define CSL_KSBUS_RAT_CTRL48                                                   (0x00000600U)
#define CSL_KSBUS_RAT_BASE48                                                   (0x00000610U)
#define CSL_KSBUS_RAT_SIZE48                                                   (0x00000614U)
#define CSL_KSBUS_RAT_UPPER48                                                  (0x00000618U)
#define CSL_KSBUS_RAT_LOWER48                                                  (0x0000061CU)
#define CSL_KSBUS_RAT_CTRL49                                                   (0x00000620U)
#define CSL_KSBUS_RAT_BASE49                                                   (0x00000630U)
#define CSL_KSBUS_RAT_SIZE49                                                   (0x00000634U)
#define CSL_KSBUS_RAT_UPPER49                                                  (0x00000638U)
#define CSL_KSBUS_RAT_LOWER49                                                  (0x0000063CU)
#define CSL_KSBUS_RAT_CTRL50                                                   (0x00000640U)
#define CSL_KSBUS_RAT_BASE50                                                   (0x00000650U)
#define CSL_KSBUS_RAT_SIZE50                                                   (0x00000654U)
#define CSL_KSBUS_RAT_UPPER50                                                  (0x00000658U)
#define CSL_KSBUS_RAT_LOWER50                                                  (0x0000065CU)
#define CSL_KSBUS_RAT_CTRL51                                                   (0x00000660U)
#define CSL_KSBUS_RAT_BASE51                                                   (0x00000670U)
#define CSL_KSBUS_RAT_SIZE51                                                   (0x00000674U)
#define CSL_KSBUS_RAT_UPPER51                                                  (0x00000678U)
#define CSL_KSBUS_RAT_LOWER51                                                  (0x0000067CU)
#define CSL_KSBUS_RAT_CTRL52                                                   (0x00000680U)
#define CSL_KSBUS_RAT_BASE52                                                   (0x00000690U)
#define CSL_KSBUS_RAT_SIZE52                                                   (0x00000694U)
#define CSL_KSBUS_RAT_UPPER52                                                  (0x00000698U)
#define CSL_KSBUS_RAT_LOWER52                                                  (0x0000069CU)
#define CSL_KSBUS_RAT_CTRL53                                                   (0x000006A0U)
#define CSL_KSBUS_RAT_BASE53                                                   (0x000006B0U)
#define CSL_KSBUS_RAT_SIZE53                                                   (0x000006B4U)
#define CSL_KSBUS_RAT_UPPER53                                                  (0x000006B8U)
#define CSL_KSBUS_RAT_LOWER53                                                  (0x000006BCU)
#define CSL_KSBUS_RAT_CTRL54                                                   (0x000006C0U)
#define CSL_KSBUS_RAT_BASE54                                                   (0x000006D0U)
#define CSL_KSBUS_RAT_SIZE54                                                   (0x000006D4U)
#define CSL_KSBUS_RAT_UPPER54                                                  (0x000006D8U)
#define CSL_KSBUS_RAT_LOWER54                                                  (0x000006DCU)
#define CSL_KSBUS_RAT_CTRL55                                                   (0x000006E0U)
#define CSL_KSBUS_RAT_BASE55                                                   (0x000006F0U)
#define CSL_KSBUS_RAT_SIZE55                                                   (0x000006F4U)
#define CSL_KSBUS_RAT_UPPER55                                                  (0x000006F8U)
#define CSL_KSBUS_RAT_LOWER55                                                  (0x000006FCU)
#define CSL_KSBUS_RAT_CTRL56                                                   (0x00000700U)
#define CSL_KSBUS_RAT_BASE56                                                   (0x00000710U)
#define CSL_KSBUS_RAT_SIZE56                                                   (0x00000714U)
#define CSL_KSBUS_RAT_UPPER56                                                  (0x00000718U)
#define CSL_KSBUS_RAT_LOWER56                                                  (0x0000071CU)
#define CSL_KSBUS_RAT_CTRL57                                                   (0x00000720U)
#define CSL_KSBUS_RAT_BASE57                                                   (0x00000730U)
#define CSL_KSBUS_RAT_SIZE57                                                   (0x00000734U)
#define CSL_KSBUS_RAT_UPPER57                                                  (0x00000738U)
#define CSL_KSBUS_RAT_LOWER57                                                  (0x0000073CU)
#define CSL_KSBUS_RAT_CTRL58                                                   (0x00000740U)
#define CSL_KSBUS_RAT_BASE58                                                   (0x00000750U)
#define CSL_KSBUS_RAT_SIZE58                                                   (0x00000754U)
#define CSL_KSBUS_RAT_UPPER58                                                  (0x00000758U)
#define CSL_KSBUS_RAT_LOWER58                                                  (0x0000075CU)
#define CSL_KSBUS_RAT_CTRL59                                                   (0x00000760U)
#define CSL_KSBUS_RAT_BASE59                                                   (0x00000770U)
#define CSL_KSBUS_RAT_SIZE59                                                   (0x00000774U)
#define CSL_KSBUS_RAT_UPPER59                                                  (0x00000778U)
#define CSL_KSBUS_RAT_LOWER59                                                  (0x0000077CU)
#define CSL_KSBUS_RAT_CTRL60                                                   (0x00000780U)
#define CSL_KSBUS_RAT_BASE60                                                   (0x00000790U)
#define CSL_KSBUS_RAT_SIZE60                                                   (0x00000794U)
#define CSL_KSBUS_RAT_UPPER60                                                  (0x00000798U)
#define CSL_KSBUS_RAT_LOWER60                                                  (0x0000079CU)
#define CSL_KSBUS_RAT_CTRL61                                                   (0x000007A0U)
#define CSL_KSBUS_RAT_BASE61                                                   (0x000007B0U)
#define CSL_KSBUS_RAT_SIZE61                                                   (0x000007B4U)
#define CSL_KSBUS_RAT_UPPER61                                                  (0x000007B8U)
#define CSL_KSBUS_RAT_LOWER61                                                  (0x000007BCU)
#define CSL_KSBUS_RAT_CTRL62                                                   (0x000007C0U)
#define CSL_KSBUS_RAT_BASE62                                                   (0x000007D0U)
#define CSL_KSBUS_RAT_SIZE62                                                   (0x000007D4U)
#define CSL_KSBUS_RAT_UPPER62                                                  (0x000007D8U)
#define CSL_KSBUS_RAT_LOWER62                                                  (0x000007DCU)
#define CSL_KSBUS_RAT_CTRL63                                                   (0x000007E0U)
#define CSL_KSBUS_RAT_BASE63                                                   (0x000007F0U)
#define CSL_KSBUS_RAT_SIZE63                                                   (0x000007F4U)
#define CSL_KSBUS_RAT_UPPER63                                                  (0x000007F8U)
#define CSL_KSBUS_RAT_LOWER63                                                  (0x000007FCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CTRL0 */

#define CSL_KSBUS_RAT_CTRL0_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL0_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL0_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL0_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL0_RESETVAL                                           (0x00000000U)

/* BASE0 */

#define CSL_KSBUS_RAT_BASE0_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE0_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE0_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE0_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE0_RESETVAL                                           (0x00000000U)

/* SIZE0 */

#define CSL_KSBUS_RAT_SIZE0_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE0_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE0_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE0_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE0_RESETVAL                                           (0x00000000U)

/* UPPER0 */

#define CSL_KSBUS_RAT_UPPER0_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER0_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER0_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER0_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER0_RESETVAL                                          (0x00000000U)

/* LOWER0 */

#define CSL_KSBUS_RAT_LOWER0_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER0_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER0_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER0_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER0_RESETVAL                                          (0x00000000U)

/* CTRL1 */

#define CSL_KSBUS_RAT_CTRL1_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL1_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL1_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL1_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL1_RESETVAL                                           (0x00000000U)

/* BASE1 */

#define CSL_KSBUS_RAT_BASE1_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE1_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE1_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE1_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE1_RESETVAL                                           (0x00000000U)

/* SIZE1 */

#define CSL_KSBUS_RAT_SIZE1_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE1_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE1_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE1_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE1_RESETVAL                                           (0x00000000U)

/* UPPER1 */

#define CSL_KSBUS_RAT_UPPER1_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER1_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER1_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER1_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER1_RESETVAL                                          (0x00000000U)

/* LOWER1 */

#define CSL_KSBUS_RAT_LOWER1_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER1_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER1_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER1_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER1_RESETVAL                                          (0x00000000U)

/* CTRL2 */

#define CSL_KSBUS_RAT_CTRL2_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL2_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL2_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL2_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL2_RESETVAL                                           (0x00000000U)

/* BASE2 */

#define CSL_KSBUS_RAT_BASE2_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE2_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE2_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE2_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE2_RESETVAL                                           (0x00000000U)

/* SIZE2 */

#define CSL_KSBUS_RAT_SIZE2_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE2_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE2_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE2_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE2_RESETVAL                                           (0x00000000U)

/* UPPER2 */

#define CSL_KSBUS_RAT_UPPER2_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER2_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER2_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER2_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER2_RESETVAL                                          (0x00000000U)

/* LOWER2 */

#define CSL_KSBUS_RAT_LOWER2_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER2_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER2_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER2_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER2_RESETVAL                                          (0x00000000U)

/* CTRL3 */

#define CSL_KSBUS_RAT_CTRL3_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL3_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL3_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL3_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL3_RESETVAL                                           (0x00000000U)

/* BASE3 */

#define CSL_KSBUS_RAT_BASE3_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE3_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE3_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE3_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE3_RESETVAL                                           (0x00000000U)

/* SIZE3 */

#define CSL_KSBUS_RAT_SIZE3_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE3_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE3_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE3_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE3_RESETVAL                                           (0x00000000U)

/* UPPER3 */

#define CSL_KSBUS_RAT_UPPER3_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER3_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER3_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER3_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER3_RESETVAL                                          (0x00000000U)

/* LOWER3 */

#define CSL_KSBUS_RAT_LOWER3_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER3_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER3_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER3_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER3_RESETVAL                                          (0x00000000U)

/* CTRL4 */

#define CSL_KSBUS_RAT_CTRL4_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL4_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL4_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL4_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL4_RESETVAL                                           (0x00000000U)

/* BASE4 */

#define CSL_KSBUS_RAT_BASE4_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE4_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE4_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE4_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE4_RESETVAL                                           (0x00000000U)

/* SIZE4 */

#define CSL_KSBUS_RAT_SIZE4_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE4_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE4_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE4_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE4_RESETVAL                                           (0x00000000U)

/* UPPER4 */

#define CSL_KSBUS_RAT_UPPER4_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER4_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER4_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER4_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER4_RESETVAL                                          (0x00000000U)

/* LOWER4 */

#define CSL_KSBUS_RAT_LOWER4_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER4_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER4_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER4_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER4_RESETVAL                                          (0x00000000U)

/* CTRL5 */

#define CSL_KSBUS_RAT_CTRL5_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL5_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL5_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL5_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL5_RESETVAL                                           (0x00000000U)

/* BASE5 */

#define CSL_KSBUS_RAT_BASE5_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE5_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE5_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE5_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE5_RESETVAL                                           (0x00000000U)

/* SIZE5 */

#define CSL_KSBUS_RAT_SIZE5_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE5_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE5_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE5_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE5_RESETVAL                                           (0x00000000U)

/* UPPER5 */

#define CSL_KSBUS_RAT_UPPER5_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER5_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER5_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER5_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER5_RESETVAL                                          (0x00000000U)

/* LOWER5 */

#define CSL_KSBUS_RAT_LOWER5_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER5_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER5_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER5_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER5_RESETVAL                                          (0x00000000U)

/* CTRL6 */

#define CSL_KSBUS_RAT_CTRL6_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL6_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL6_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL6_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL6_RESETVAL                                           (0x00000000U)

/* BASE6 */

#define CSL_KSBUS_RAT_BASE6_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE6_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE6_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE6_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE6_RESETVAL                                           (0x00000000U)

/* SIZE6 */

#define CSL_KSBUS_RAT_SIZE6_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE6_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE6_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE6_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE6_RESETVAL                                           (0x00000000U)

/* UPPER6 */

#define CSL_KSBUS_RAT_UPPER6_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER6_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER6_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER6_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER6_RESETVAL                                          (0x00000000U)

/* LOWER6 */

#define CSL_KSBUS_RAT_LOWER6_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER6_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER6_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER6_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER6_RESETVAL                                          (0x00000000U)

/* CTRL7 */

#define CSL_KSBUS_RAT_CTRL7_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL7_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL7_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL7_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL7_RESETVAL                                           (0x00000000U)

/* BASE7 */

#define CSL_KSBUS_RAT_BASE7_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE7_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE7_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE7_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE7_RESETVAL                                           (0x00000000U)

/* SIZE7 */

#define CSL_KSBUS_RAT_SIZE7_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE7_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE7_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE7_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE7_RESETVAL                                           (0x00000000U)

/* UPPER7 */

#define CSL_KSBUS_RAT_UPPER7_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER7_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER7_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER7_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER7_RESETVAL                                          (0x00000000U)

/* LOWER7 */

#define CSL_KSBUS_RAT_LOWER7_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER7_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER7_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER7_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER7_RESETVAL                                          (0x00000000U)

/* CTRL8 */

#define CSL_KSBUS_RAT_CTRL8_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL8_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL8_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL8_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL8_RESETVAL                                           (0x00000000U)

/* BASE8 */

#define CSL_KSBUS_RAT_BASE8_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE8_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE8_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE8_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE8_RESETVAL                                           (0x00000000U)

/* SIZE8 */

#define CSL_KSBUS_RAT_SIZE8_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE8_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE8_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE8_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE8_RESETVAL                                           (0x00000000U)

/* UPPER8 */

#define CSL_KSBUS_RAT_UPPER8_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER8_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER8_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER8_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER8_RESETVAL                                          (0x00000000U)

/* LOWER8 */

#define CSL_KSBUS_RAT_LOWER8_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER8_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER8_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER8_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER8_RESETVAL                                          (0x00000000U)

/* CTRL9 */

#define CSL_KSBUS_RAT_CTRL9_BASE_MASK                                          (0x00000001U)
#define CSL_KSBUS_RAT_CTRL9_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_CTRL9_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_CTRL9_BASE_MAX                                           (0x00000001U)

#define CSL_KSBUS_RAT_CTRL9_RESETVAL                                           (0x00000000U)

/* BASE9 */

#define CSL_KSBUS_RAT_BASE9_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE9_BASE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_BASE9_BASE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_BASE9_BASE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE9_RESETVAL                                           (0x00000000U)

/* SIZE9 */

#define CSL_KSBUS_RAT_SIZE9_SIZE_MASK                                          (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE9_SIZE_SHIFT                                         (0x00000000U)
#define CSL_KSBUS_RAT_SIZE9_SIZE_RESETVAL                                      (0x00000000U)
#define CSL_KSBUS_RAT_SIZE9_SIZE_MAX                                           (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE9_RESETVAL                                           (0x00000000U)

/* UPPER9 */

#define CSL_KSBUS_RAT_UPPER9_UPPER_MASK                                        (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER9_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_UPPER9_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_UPPER9_UPPER_MAX                                         (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER9_RESETVAL                                          (0x00000000U)

/* LOWER9 */

#define CSL_KSBUS_RAT_LOWER9_UPPER_MASK                                        (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER9_UPPER_SHIFT                                       (0x00000000U)
#define CSL_KSBUS_RAT_LOWER9_UPPER_RESETVAL                                    (0x00000000U)
#define CSL_KSBUS_RAT_LOWER9_UPPER_MAX                                         (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER9_RESETVAL                                          (0x00000000U)

/* CTRL10 */

#define CSL_KSBUS_RAT_CTRL10_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL10_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL10_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL10_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL10_RESETVAL                                          (0x00000000U)

/* BASE10 */

#define CSL_KSBUS_RAT_BASE10_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE10_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE10_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE10_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE10_RESETVAL                                          (0x00000000U)

/* SIZE10 */

#define CSL_KSBUS_RAT_SIZE10_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE10_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE10_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE10_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE10_RESETVAL                                          (0x00000000U)

/* UPPER10 */

#define CSL_KSBUS_RAT_UPPER10_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER10_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER10_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER10_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER10_RESETVAL                                         (0x00000000U)

/* LOWER10 */

#define CSL_KSBUS_RAT_LOWER10_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER10_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER10_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER10_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER10_RESETVAL                                         (0x00000000U)

/* CTRL11 */

#define CSL_KSBUS_RAT_CTRL11_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL11_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL11_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL11_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL11_RESETVAL                                          (0x00000000U)

/* BASE11 */

#define CSL_KSBUS_RAT_BASE11_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE11_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE11_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE11_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE11_RESETVAL                                          (0x00000000U)

/* SIZE11 */

#define CSL_KSBUS_RAT_SIZE11_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE11_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE11_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE11_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE11_RESETVAL                                          (0x00000000U)

/* UPPER11 */

#define CSL_KSBUS_RAT_UPPER11_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER11_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER11_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER11_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER11_RESETVAL                                         (0x00000000U)

/* LOWER11 */

#define CSL_KSBUS_RAT_LOWER11_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER11_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER11_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER11_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER11_RESETVAL                                         (0x00000000U)

/* CTRL12 */

#define CSL_KSBUS_RAT_CTRL12_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL12_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL12_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL12_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL12_RESETVAL                                          (0x00000000U)

/* BASE12 */

#define CSL_KSBUS_RAT_BASE12_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE12_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE12_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE12_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE12_RESETVAL                                          (0x00000000U)

/* SIZE12 */

#define CSL_KSBUS_RAT_SIZE12_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE12_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE12_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE12_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE12_RESETVAL                                          (0x00000000U)

/* UPPER12 */

#define CSL_KSBUS_RAT_UPPER12_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER12_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER12_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER12_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER12_RESETVAL                                         (0x00000000U)

/* LOWER12 */

#define CSL_KSBUS_RAT_LOWER12_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER12_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER12_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER12_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER12_RESETVAL                                         (0x00000000U)

/* CTRL13 */

#define CSL_KSBUS_RAT_CTRL13_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL13_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL13_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL13_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL13_RESETVAL                                          (0x00000000U)

/* BASE13 */

#define CSL_KSBUS_RAT_BASE13_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE13_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE13_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE13_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE13_RESETVAL                                          (0x00000000U)

/* SIZE13 */

#define CSL_KSBUS_RAT_SIZE13_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE13_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE13_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE13_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE13_RESETVAL                                          (0x00000000U)

/* UPPER13 */

#define CSL_KSBUS_RAT_UPPER13_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER13_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER13_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER13_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER13_RESETVAL                                         (0x00000000U)

/* LOWER13 */

#define CSL_KSBUS_RAT_LOWER13_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER13_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER13_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER13_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER13_RESETVAL                                         (0x00000000U)

/* CTRL14 */

#define CSL_KSBUS_RAT_CTRL14_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL14_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL14_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL14_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL14_RESETVAL                                          (0x00000000U)

/* BASE14 */

#define CSL_KSBUS_RAT_BASE14_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE14_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE14_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE14_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE14_RESETVAL                                          (0x00000000U)

/* SIZE14 */

#define CSL_KSBUS_RAT_SIZE14_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE14_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE14_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE14_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE14_RESETVAL                                          (0x00000000U)

/* UPPER14 */

#define CSL_KSBUS_RAT_UPPER14_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER14_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER14_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER14_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER14_RESETVAL                                         (0x00000000U)

/* LOWER14 */

#define CSL_KSBUS_RAT_LOWER14_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER14_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER14_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER14_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER14_RESETVAL                                         (0x00000000U)

/* CTRL15 */

#define CSL_KSBUS_RAT_CTRL15_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL15_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL15_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL15_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL15_RESETVAL                                          (0x00000000U)

/* BASE15 */

#define CSL_KSBUS_RAT_BASE15_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE15_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE15_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE15_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE15_RESETVAL                                          (0x00000000U)

/* SIZE15 */

#define CSL_KSBUS_RAT_SIZE15_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE15_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE15_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE15_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE15_RESETVAL                                          (0x00000000U)

/* UPPER15 */

#define CSL_KSBUS_RAT_UPPER15_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER15_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER15_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER15_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER15_RESETVAL                                         (0x00000000U)

/* LOWER15 */

#define CSL_KSBUS_RAT_LOWER15_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER15_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER15_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER15_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER15_RESETVAL                                         (0x00000000U)

/* CTRL16 */

#define CSL_KSBUS_RAT_CTRL16_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL16_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL16_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL16_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL16_RESETVAL                                          (0x00000000U)

/* BASE16 */

#define CSL_KSBUS_RAT_BASE16_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE16_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE16_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE16_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE16_RESETVAL                                          (0x00000000U)

/* SIZE16 */

#define CSL_KSBUS_RAT_SIZE16_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE16_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE16_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE16_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE16_RESETVAL                                          (0x00000000U)

/* UPPER16 */

#define CSL_KSBUS_RAT_UPPER16_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER16_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER16_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER16_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER16_RESETVAL                                         (0x00000000U)

/* LOWER16 */

#define CSL_KSBUS_RAT_LOWER16_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER16_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER16_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER16_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER16_RESETVAL                                         (0x00000000U)

/* CTRL17 */

#define CSL_KSBUS_RAT_CTRL17_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL17_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL17_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL17_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL17_RESETVAL                                          (0x00000000U)

/* BASE17 */

#define CSL_KSBUS_RAT_BASE17_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE17_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE17_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE17_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE17_RESETVAL                                          (0x00000000U)

/* SIZE17 */

#define CSL_KSBUS_RAT_SIZE17_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE17_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE17_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE17_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE17_RESETVAL                                          (0x00000000U)

/* UPPER17 */

#define CSL_KSBUS_RAT_UPPER17_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER17_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER17_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER17_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER17_RESETVAL                                         (0x00000000U)

/* LOWER17 */

#define CSL_KSBUS_RAT_LOWER17_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER17_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER17_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER17_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER17_RESETVAL                                         (0x00000000U)

/* CTRL18 */

#define CSL_KSBUS_RAT_CTRL18_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL18_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL18_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL18_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL18_RESETVAL                                          (0x00000000U)

/* BASE18 */

#define CSL_KSBUS_RAT_BASE18_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE18_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE18_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE18_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE18_RESETVAL                                          (0x00000000U)

/* SIZE18 */

#define CSL_KSBUS_RAT_SIZE18_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE18_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE18_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE18_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE18_RESETVAL                                          (0x00000000U)

/* UPPER18 */

#define CSL_KSBUS_RAT_UPPER18_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER18_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER18_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER18_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER18_RESETVAL                                         (0x00000000U)

/* LOWER18 */

#define CSL_KSBUS_RAT_LOWER18_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER18_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER18_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER18_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER18_RESETVAL                                         (0x00000000U)

/* CTRL19 */

#define CSL_KSBUS_RAT_CTRL19_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL19_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL19_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL19_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL19_RESETVAL                                          (0x00000000U)

/* BASE19 */

#define CSL_KSBUS_RAT_BASE19_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE19_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE19_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE19_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE19_RESETVAL                                          (0x00000000U)

/* SIZE19 */

#define CSL_KSBUS_RAT_SIZE19_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE19_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE19_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE19_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE19_RESETVAL                                          (0x00000000U)

/* UPPER19 */

#define CSL_KSBUS_RAT_UPPER19_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER19_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER19_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER19_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER19_RESETVAL                                         (0x00000000U)

/* LOWER19 */

#define CSL_KSBUS_RAT_LOWER19_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER19_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER19_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER19_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER19_RESETVAL                                         (0x00000000U)

/* CTRL20 */

#define CSL_KSBUS_RAT_CTRL20_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL20_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL20_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL20_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL20_RESETVAL                                          (0x00000000U)

/* BASE20 */

#define CSL_KSBUS_RAT_BASE20_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE20_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE20_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE20_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE20_RESETVAL                                          (0x00000000U)

/* SIZE20 */

#define CSL_KSBUS_RAT_SIZE20_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE20_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE20_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE20_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE20_RESETVAL                                          (0x00000000U)

/* UPPER20 */

#define CSL_KSBUS_RAT_UPPER20_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER20_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER20_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER20_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER20_RESETVAL                                         (0x00000000U)

/* LOWER20 */

#define CSL_KSBUS_RAT_LOWER20_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER20_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER20_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER20_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER20_RESETVAL                                         (0x00000000U)

/* CTRL21 */

#define CSL_KSBUS_RAT_CTRL21_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL21_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL21_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL21_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL21_RESETVAL                                          (0x00000000U)

/* BASE21 */

#define CSL_KSBUS_RAT_BASE21_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE21_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE21_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE21_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE21_RESETVAL                                          (0x00000000U)

/* SIZE21 */

#define CSL_KSBUS_RAT_SIZE21_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE21_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE21_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE21_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE21_RESETVAL                                          (0x00000000U)

/* UPPER21 */

#define CSL_KSBUS_RAT_UPPER21_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER21_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER21_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER21_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER21_RESETVAL                                         (0x00000000U)

/* LOWER21 */

#define CSL_KSBUS_RAT_LOWER21_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER21_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER21_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER21_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER21_RESETVAL                                         (0x00000000U)

/* CTRL22 */

#define CSL_KSBUS_RAT_CTRL22_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL22_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL22_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL22_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL22_RESETVAL                                          (0x00000000U)

/* BASE22 */

#define CSL_KSBUS_RAT_BASE22_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE22_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE22_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE22_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE22_RESETVAL                                          (0x00000000U)

/* SIZE22 */

#define CSL_KSBUS_RAT_SIZE22_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE22_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE22_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE22_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE22_RESETVAL                                          (0x00000000U)

/* UPPER22 */

#define CSL_KSBUS_RAT_UPPER22_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER22_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER22_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER22_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER22_RESETVAL                                         (0x00000000U)

/* LOWER22 */

#define CSL_KSBUS_RAT_LOWER22_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER22_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER22_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER22_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER22_RESETVAL                                         (0x00000000U)

/* CTRL23 */

#define CSL_KSBUS_RAT_CTRL23_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL23_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL23_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL23_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL23_RESETVAL                                          (0x00000000U)

/* BASE23 */

#define CSL_KSBUS_RAT_BASE23_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE23_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE23_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE23_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE23_RESETVAL                                          (0x00000000U)

/* SIZE23 */

#define CSL_KSBUS_RAT_SIZE23_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE23_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE23_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE23_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE23_RESETVAL                                          (0x00000000U)

/* UPPER23 */

#define CSL_KSBUS_RAT_UPPER23_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER23_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER23_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER23_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER23_RESETVAL                                         (0x00000000U)

/* LOWER23 */

#define CSL_KSBUS_RAT_LOWER23_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER23_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER23_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER23_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER23_RESETVAL                                         (0x00000000U)

/* CTRL24 */

#define CSL_KSBUS_RAT_CTRL24_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL24_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL24_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL24_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL24_RESETVAL                                          (0x00000000U)

/* BASE24 */

#define CSL_KSBUS_RAT_BASE24_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE24_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE24_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE24_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE24_RESETVAL                                          (0x00000000U)

/* SIZE24 */

#define CSL_KSBUS_RAT_SIZE24_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE24_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE24_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE24_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE24_RESETVAL                                          (0x00000000U)

/* UPPER24 */

#define CSL_KSBUS_RAT_UPPER24_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER24_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER24_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER24_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER24_RESETVAL                                         (0x00000000U)

/* LOWER24 */

#define CSL_KSBUS_RAT_LOWER24_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER24_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER24_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER24_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER24_RESETVAL                                         (0x00000000U)

/* CTRL25 */

#define CSL_KSBUS_RAT_CTRL25_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL25_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL25_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL25_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL25_RESETVAL                                          (0x00000000U)

/* BASE25 */

#define CSL_KSBUS_RAT_BASE25_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE25_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE25_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE25_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE25_RESETVAL                                          (0x00000000U)

/* SIZE25 */

#define CSL_KSBUS_RAT_SIZE25_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE25_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE25_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE25_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE25_RESETVAL                                          (0x00000000U)

/* UPPER25 */

#define CSL_KSBUS_RAT_UPPER25_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER25_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER25_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER25_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER25_RESETVAL                                         (0x00000000U)

/* LOWER25 */

#define CSL_KSBUS_RAT_LOWER25_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER25_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER25_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER25_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER25_RESETVAL                                         (0x00000000U)

/* CTRL26 */

#define CSL_KSBUS_RAT_CTRL26_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL26_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL26_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL26_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL26_RESETVAL                                          (0x00000000U)

/* BASE26 */

#define CSL_KSBUS_RAT_BASE26_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE26_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE26_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE26_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE26_RESETVAL                                          (0x00000000U)

/* SIZE26 */

#define CSL_KSBUS_RAT_SIZE26_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE26_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE26_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE26_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE26_RESETVAL                                          (0x00000000U)

/* UPPER26 */

#define CSL_KSBUS_RAT_UPPER26_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER26_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER26_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER26_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER26_RESETVAL                                         (0x00000000U)

/* LOWER26 */

#define CSL_KSBUS_RAT_LOWER26_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER26_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER26_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER26_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER26_RESETVAL                                         (0x00000000U)

/* CTRL27 */

#define CSL_KSBUS_RAT_CTRL27_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL27_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL27_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL27_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL27_RESETVAL                                          (0x00000000U)

/* BASE27 */

#define CSL_KSBUS_RAT_BASE27_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE27_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE27_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE27_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE27_RESETVAL                                          (0x00000000U)

/* SIZE27 */

#define CSL_KSBUS_RAT_SIZE27_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE27_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE27_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE27_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE27_RESETVAL                                          (0x00000000U)

/* UPPER27 */

#define CSL_KSBUS_RAT_UPPER27_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER27_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER27_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER27_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER27_RESETVAL                                         (0x00000000U)

/* LOWER27 */

#define CSL_KSBUS_RAT_LOWER27_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER27_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER27_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER27_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER27_RESETVAL                                         (0x00000000U)

/* CTRL28 */

#define CSL_KSBUS_RAT_CTRL28_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL28_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL28_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL28_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL28_RESETVAL                                          (0x00000000U)

/* BASE28 */

#define CSL_KSBUS_RAT_BASE28_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE28_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE28_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE28_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE28_RESETVAL                                          (0x00000000U)

/* SIZE28 */

#define CSL_KSBUS_RAT_SIZE28_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE28_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE28_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE28_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE28_RESETVAL                                          (0x00000000U)

/* UPPER28 */

#define CSL_KSBUS_RAT_UPPER28_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER28_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER28_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER28_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER28_RESETVAL                                         (0x00000000U)

/* LOWER28 */

#define CSL_KSBUS_RAT_LOWER28_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER28_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER28_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER28_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER28_RESETVAL                                         (0x00000000U)

/* CTRL29 */

#define CSL_KSBUS_RAT_CTRL29_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL29_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL29_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL29_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL29_RESETVAL                                          (0x00000000U)

/* BASE29 */

#define CSL_KSBUS_RAT_BASE29_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE29_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE29_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE29_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE29_RESETVAL                                          (0x00000000U)

/* SIZE29 */

#define CSL_KSBUS_RAT_SIZE29_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE29_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE29_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE29_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE29_RESETVAL                                          (0x00000000U)

/* UPPER29 */

#define CSL_KSBUS_RAT_UPPER29_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER29_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER29_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER29_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER29_RESETVAL                                         (0x00000000U)

/* LOWER29 */

#define CSL_KSBUS_RAT_LOWER29_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER29_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER29_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER29_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER29_RESETVAL                                         (0x00000000U)

/* CTRL30 */

#define CSL_KSBUS_RAT_CTRL30_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL30_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL30_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL30_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL30_RESETVAL                                          (0x00000000U)

/* BASE30 */

#define CSL_KSBUS_RAT_BASE30_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE30_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE30_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE30_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE30_RESETVAL                                          (0x00000000U)

/* SIZE30 */

#define CSL_KSBUS_RAT_SIZE30_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE30_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE30_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE30_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE30_RESETVAL                                          (0x00000000U)

/* UPPER30 */

#define CSL_KSBUS_RAT_UPPER30_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER30_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER30_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER30_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER30_RESETVAL                                         (0x00000000U)

/* LOWER30 */

#define CSL_KSBUS_RAT_LOWER30_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER30_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER30_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER30_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER30_RESETVAL                                         (0x00000000U)

/* CTRL31 */

#define CSL_KSBUS_RAT_CTRL31_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL31_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL31_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL31_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL31_RESETVAL                                          (0x00000000U)

/* BASE31 */

#define CSL_KSBUS_RAT_BASE31_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE31_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE31_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE31_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE31_RESETVAL                                          (0x00000000U)

/* SIZE31 */

#define CSL_KSBUS_RAT_SIZE31_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE31_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE31_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE31_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE31_RESETVAL                                          (0x00000000U)

/* UPPER31 */

#define CSL_KSBUS_RAT_UPPER31_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER31_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER31_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER31_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER31_RESETVAL                                         (0x00000000U)

/* LOWER31 */

#define CSL_KSBUS_RAT_LOWER31_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER31_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER31_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER31_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER31_RESETVAL                                         (0x00000000U)

/* CTRL32 */

#define CSL_KSBUS_RAT_CTRL32_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL32_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL32_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL32_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL32_RESETVAL                                          (0x00000000U)

/* BASE32 */

#define CSL_KSBUS_RAT_BASE32_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE32_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE32_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE32_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE32_RESETVAL                                          (0x00000000U)

/* SIZE32 */

#define CSL_KSBUS_RAT_SIZE32_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE32_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE32_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE32_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE32_RESETVAL                                          (0x00000000U)

/* UPPER32 */

#define CSL_KSBUS_RAT_UPPER32_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER32_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER32_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER32_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER32_RESETVAL                                         (0x00000000U)

/* LOWER32 */

#define CSL_KSBUS_RAT_LOWER32_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER32_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER32_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER32_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER32_RESETVAL                                         (0x00000000U)

/* CTRL33 */

#define CSL_KSBUS_RAT_CTRL33_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL33_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL33_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL33_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL33_RESETVAL                                          (0x00000000U)

/* BASE33 */

#define CSL_KSBUS_RAT_BASE33_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE33_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE33_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE33_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE33_RESETVAL                                          (0x00000000U)

/* SIZE33 */

#define CSL_KSBUS_RAT_SIZE33_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE33_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE33_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE33_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE33_RESETVAL                                          (0x00000000U)

/* UPPER33 */

#define CSL_KSBUS_RAT_UPPER33_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER33_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER33_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER33_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER33_RESETVAL                                         (0x00000000U)

/* LOWER33 */

#define CSL_KSBUS_RAT_LOWER33_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER33_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER33_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER33_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER33_RESETVAL                                         (0x00000000U)

/* CTRL34 */

#define CSL_KSBUS_RAT_CTRL34_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL34_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL34_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL34_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL34_RESETVAL                                          (0x00000000U)

/* BASE34 */

#define CSL_KSBUS_RAT_BASE34_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE34_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE34_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE34_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE34_RESETVAL                                          (0x00000000U)

/* SIZE34 */

#define CSL_KSBUS_RAT_SIZE34_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE34_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE34_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE34_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE34_RESETVAL                                          (0x00000000U)

/* UPPER34 */

#define CSL_KSBUS_RAT_UPPER34_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER34_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER34_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER34_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER34_RESETVAL                                         (0x00000000U)

/* LOWER34 */

#define CSL_KSBUS_RAT_LOWER34_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER34_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER34_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER34_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER34_RESETVAL                                         (0x00000000U)

/* CTRL35 */

#define CSL_KSBUS_RAT_CTRL35_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL35_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL35_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL35_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL35_RESETVAL                                          (0x00000000U)

/* BASE35 */

#define CSL_KSBUS_RAT_BASE35_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE35_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE35_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE35_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE35_RESETVAL                                          (0x00000000U)

/* SIZE35 */

#define CSL_KSBUS_RAT_SIZE35_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE35_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE35_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE35_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE35_RESETVAL                                          (0x00000000U)

/* UPPER35 */

#define CSL_KSBUS_RAT_UPPER35_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER35_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER35_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER35_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER35_RESETVAL                                         (0x00000000U)

/* LOWER35 */

#define CSL_KSBUS_RAT_LOWER35_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER35_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER35_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER35_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER35_RESETVAL                                         (0x00000000U)

/* CTRL36 */

#define CSL_KSBUS_RAT_CTRL36_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL36_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL36_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL36_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL36_RESETVAL                                          (0x00000000U)

/* BASE36 */

#define CSL_KSBUS_RAT_BASE36_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE36_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE36_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE36_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE36_RESETVAL                                          (0x00000000U)

/* SIZE36 */

#define CSL_KSBUS_RAT_SIZE36_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE36_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE36_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE36_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE36_RESETVAL                                          (0x00000000U)

/* UPPER36 */

#define CSL_KSBUS_RAT_UPPER36_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER36_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER36_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER36_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER36_RESETVAL                                         (0x00000000U)

/* LOWER36 */

#define CSL_KSBUS_RAT_LOWER36_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER36_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER36_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER36_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER36_RESETVAL                                         (0x00000000U)

/* CTRL37 */

#define CSL_KSBUS_RAT_CTRL37_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL37_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL37_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL37_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL37_RESETVAL                                          (0x00000000U)

/* BASE37 */

#define CSL_KSBUS_RAT_BASE37_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE37_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE37_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE37_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE37_RESETVAL                                          (0x00000000U)

/* SIZE37 */

#define CSL_KSBUS_RAT_SIZE37_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE37_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE37_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE37_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE37_RESETVAL                                          (0x00000000U)

/* UPPER37 */

#define CSL_KSBUS_RAT_UPPER37_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER37_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER37_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER37_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER37_RESETVAL                                         (0x00000000U)

/* LOWER37 */

#define CSL_KSBUS_RAT_LOWER37_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER37_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER37_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER37_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER37_RESETVAL                                         (0x00000000U)

/* CTRL38 */

#define CSL_KSBUS_RAT_CTRL38_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL38_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL38_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL38_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL38_RESETVAL                                          (0x00000000U)

/* BASE38 */

#define CSL_KSBUS_RAT_BASE38_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE38_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE38_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE38_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE38_RESETVAL                                          (0x00000000U)

/* SIZE38 */

#define CSL_KSBUS_RAT_SIZE38_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE38_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE38_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE38_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE38_RESETVAL                                          (0x00000000U)

/* UPPER38 */

#define CSL_KSBUS_RAT_UPPER38_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER38_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER38_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER38_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER38_RESETVAL                                         (0x00000000U)

/* LOWER38 */

#define CSL_KSBUS_RAT_LOWER38_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER38_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER38_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER38_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER38_RESETVAL                                         (0x00000000U)

/* CTRL39 */

#define CSL_KSBUS_RAT_CTRL39_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL39_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL39_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL39_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL39_RESETVAL                                          (0x00000000U)

/* BASE39 */

#define CSL_KSBUS_RAT_BASE39_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE39_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE39_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE39_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE39_RESETVAL                                          (0x00000000U)

/* SIZE39 */

#define CSL_KSBUS_RAT_SIZE39_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE39_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE39_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE39_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE39_RESETVAL                                          (0x00000000U)

/* UPPER39 */

#define CSL_KSBUS_RAT_UPPER39_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER39_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER39_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER39_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER39_RESETVAL                                         (0x00000000U)

/* LOWER39 */

#define CSL_KSBUS_RAT_LOWER39_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER39_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER39_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER39_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER39_RESETVAL                                         (0x00000000U)

/* CTRL40 */

#define CSL_KSBUS_RAT_CTRL40_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL40_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL40_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL40_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL40_RESETVAL                                          (0x00000000U)

/* BASE40 */

#define CSL_KSBUS_RAT_BASE40_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE40_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE40_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE40_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE40_RESETVAL                                          (0x00000000U)

/* SIZE40 */

#define CSL_KSBUS_RAT_SIZE40_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE40_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE40_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE40_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE40_RESETVAL                                          (0x00000000U)

/* UPPER40 */

#define CSL_KSBUS_RAT_UPPER40_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER40_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER40_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER40_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER40_RESETVAL                                         (0x00000000U)

/* LOWER40 */

#define CSL_KSBUS_RAT_LOWER40_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER40_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER40_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER40_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER40_RESETVAL                                         (0x00000000U)

/* CTRL41 */

#define CSL_KSBUS_RAT_CTRL41_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL41_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL41_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL41_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL41_RESETVAL                                          (0x00000000U)

/* BASE41 */

#define CSL_KSBUS_RAT_BASE41_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE41_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE41_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE41_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE41_RESETVAL                                          (0x00000000U)

/* SIZE41 */

#define CSL_KSBUS_RAT_SIZE41_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE41_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE41_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE41_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE41_RESETVAL                                          (0x00000000U)

/* UPPER41 */

#define CSL_KSBUS_RAT_UPPER41_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER41_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER41_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER41_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER41_RESETVAL                                         (0x00000000U)

/* LOWER41 */

#define CSL_KSBUS_RAT_LOWER41_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER41_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER41_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER41_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER41_RESETVAL                                         (0x00000000U)

/* CTRL42 */

#define CSL_KSBUS_RAT_CTRL42_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL42_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL42_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL42_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL42_RESETVAL                                          (0x00000000U)

/* BASE42 */

#define CSL_KSBUS_RAT_BASE42_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE42_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE42_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE42_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE42_RESETVAL                                          (0x00000000U)

/* SIZE42 */

#define CSL_KSBUS_RAT_SIZE42_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE42_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE42_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE42_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE42_RESETVAL                                          (0x00000000U)

/* UPPER42 */

#define CSL_KSBUS_RAT_UPPER42_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER42_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER42_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER42_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER42_RESETVAL                                         (0x00000000U)

/* LOWER42 */

#define CSL_KSBUS_RAT_LOWER42_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER42_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER42_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER42_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER42_RESETVAL                                         (0x00000000U)

/* CTRL43 */

#define CSL_KSBUS_RAT_CTRL43_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL43_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL43_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL43_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL43_RESETVAL                                          (0x00000000U)

/* BASE43 */

#define CSL_KSBUS_RAT_BASE43_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE43_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE43_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE43_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE43_RESETVAL                                          (0x00000000U)

/* SIZE43 */

#define CSL_KSBUS_RAT_SIZE43_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE43_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE43_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE43_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE43_RESETVAL                                          (0x00000000U)

/* UPPER43 */

#define CSL_KSBUS_RAT_UPPER43_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER43_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER43_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER43_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER43_RESETVAL                                         (0x00000000U)

/* LOWER43 */

#define CSL_KSBUS_RAT_LOWER43_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER43_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER43_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER43_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER43_RESETVAL                                         (0x00000000U)

/* CTRL44 */

#define CSL_KSBUS_RAT_CTRL44_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL44_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL44_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL44_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL44_RESETVAL                                          (0x00000000U)

/* BASE44 */

#define CSL_KSBUS_RAT_BASE44_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE44_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE44_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE44_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE44_RESETVAL                                          (0x00000000U)

/* SIZE44 */

#define CSL_KSBUS_RAT_SIZE44_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE44_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE44_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE44_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE44_RESETVAL                                          (0x00000000U)

/* UPPER44 */

#define CSL_KSBUS_RAT_UPPER44_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER44_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER44_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER44_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER44_RESETVAL                                         (0x00000000U)

/* LOWER44 */

#define CSL_KSBUS_RAT_LOWER44_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER44_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER44_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER44_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER44_RESETVAL                                         (0x00000000U)

/* CTRL45 */

#define CSL_KSBUS_RAT_CTRL45_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL45_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL45_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL45_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL45_RESETVAL                                          (0x00000000U)

/* BASE45 */

#define CSL_KSBUS_RAT_BASE45_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE45_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE45_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE45_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE45_RESETVAL                                          (0x00000000U)

/* SIZE45 */

#define CSL_KSBUS_RAT_SIZE45_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE45_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE45_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE45_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE45_RESETVAL                                          (0x00000000U)

/* UPPER45 */

#define CSL_KSBUS_RAT_UPPER45_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER45_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER45_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER45_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER45_RESETVAL                                         (0x00000000U)

/* LOWER45 */

#define CSL_KSBUS_RAT_LOWER45_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER45_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER45_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER45_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER45_RESETVAL                                         (0x00000000U)

/* CTRL46 */

#define CSL_KSBUS_RAT_CTRL46_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL46_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL46_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL46_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL46_RESETVAL                                          (0x00000000U)

/* BASE46 */

#define CSL_KSBUS_RAT_BASE46_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE46_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE46_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE46_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE46_RESETVAL                                          (0x00000000U)

/* SIZE46 */

#define CSL_KSBUS_RAT_SIZE46_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE46_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE46_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE46_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE46_RESETVAL                                          (0x00000000U)

/* UPPER46 */

#define CSL_KSBUS_RAT_UPPER46_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER46_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER46_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER46_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER46_RESETVAL                                         (0x00000000U)

/* LOWER46 */

#define CSL_KSBUS_RAT_LOWER46_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER46_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER46_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER46_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER46_RESETVAL                                         (0x00000000U)

/* CTRL47 */

#define CSL_KSBUS_RAT_CTRL47_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL47_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL47_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL47_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL47_RESETVAL                                          (0x00000000U)

/* BASE47 */

#define CSL_KSBUS_RAT_BASE47_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE47_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE47_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE47_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE47_RESETVAL                                          (0x00000000U)

/* SIZE47 */

#define CSL_KSBUS_RAT_SIZE47_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE47_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE47_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE47_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE47_RESETVAL                                          (0x00000000U)

/* UPPER47 */

#define CSL_KSBUS_RAT_UPPER47_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER47_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER47_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER47_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER47_RESETVAL                                         (0x00000000U)

/* LOWER47 */

#define CSL_KSBUS_RAT_LOWER47_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER47_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER47_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER47_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER47_RESETVAL                                         (0x00000000U)

/* CTRL48 */

#define CSL_KSBUS_RAT_CTRL48_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL48_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL48_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL48_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL48_RESETVAL                                          (0x00000000U)

/* BASE48 */

#define CSL_KSBUS_RAT_BASE48_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE48_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE48_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE48_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE48_RESETVAL                                          (0x00000000U)

/* SIZE48 */

#define CSL_KSBUS_RAT_SIZE48_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE48_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE48_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE48_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE48_RESETVAL                                          (0x00000000U)

/* UPPER48 */

#define CSL_KSBUS_RAT_UPPER48_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER48_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER48_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER48_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER48_RESETVAL                                         (0x00000000U)

/* LOWER48 */

#define CSL_KSBUS_RAT_LOWER48_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER48_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER48_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER48_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER48_RESETVAL                                         (0x00000000U)

/* CTRL49 */

#define CSL_KSBUS_RAT_CTRL49_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL49_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL49_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL49_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL49_RESETVAL                                          (0x00000000U)

/* BASE49 */

#define CSL_KSBUS_RAT_BASE49_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE49_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE49_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE49_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE49_RESETVAL                                          (0x00000000U)

/* SIZE49 */

#define CSL_KSBUS_RAT_SIZE49_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE49_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE49_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE49_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE49_RESETVAL                                          (0x00000000U)

/* UPPER49 */

#define CSL_KSBUS_RAT_UPPER49_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER49_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER49_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER49_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER49_RESETVAL                                         (0x00000000U)

/* LOWER49 */

#define CSL_KSBUS_RAT_LOWER49_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER49_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER49_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER49_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER49_RESETVAL                                         (0x00000000U)

/* CTRL50 */

#define CSL_KSBUS_RAT_CTRL50_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL50_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL50_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL50_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL50_RESETVAL                                          (0x00000000U)

/* BASE50 */

#define CSL_KSBUS_RAT_BASE50_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE50_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE50_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE50_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE50_RESETVAL                                          (0x00000000U)

/* SIZE50 */

#define CSL_KSBUS_RAT_SIZE50_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE50_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE50_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE50_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE50_RESETVAL                                          (0x00000000U)

/* UPPER50 */

#define CSL_KSBUS_RAT_UPPER50_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER50_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER50_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER50_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER50_RESETVAL                                         (0x00000000U)

/* LOWER50 */

#define CSL_KSBUS_RAT_LOWER50_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER50_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER50_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER50_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER50_RESETVAL                                         (0x00000000U)

/* CTRL51 */

#define CSL_KSBUS_RAT_CTRL51_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL51_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL51_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL51_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL51_RESETVAL                                          (0x00000000U)

/* BASE51 */

#define CSL_KSBUS_RAT_BASE51_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE51_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE51_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE51_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE51_RESETVAL                                          (0x00000000U)

/* SIZE51 */

#define CSL_KSBUS_RAT_SIZE51_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE51_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE51_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE51_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE51_RESETVAL                                          (0x00000000U)

/* UPPER51 */

#define CSL_KSBUS_RAT_UPPER51_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER51_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER51_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER51_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER51_RESETVAL                                         (0x00000000U)

/* LOWER51 */

#define CSL_KSBUS_RAT_LOWER51_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER51_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER51_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER51_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER51_RESETVAL                                         (0x00000000U)

/* CTRL52 */

#define CSL_KSBUS_RAT_CTRL52_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL52_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL52_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL52_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL52_RESETVAL                                          (0x00000000U)

/* BASE52 */

#define CSL_KSBUS_RAT_BASE52_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE52_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE52_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE52_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE52_RESETVAL                                          (0x00000000U)

/* SIZE52 */

#define CSL_KSBUS_RAT_SIZE52_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE52_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE52_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE52_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE52_RESETVAL                                          (0x00000000U)

/* UPPER52 */

#define CSL_KSBUS_RAT_UPPER52_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER52_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER52_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER52_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER52_RESETVAL                                         (0x00000000U)

/* LOWER52 */

#define CSL_KSBUS_RAT_LOWER52_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER52_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER52_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER52_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER52_RESETVAL                                         (0x00000000U)

/* CTRL53 */

#define CSL_KSBUS_RAT_CTRL53_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL53_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL53_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL53_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL53_RESETVAL                                          (0x00000000U)

/* BASE53 */

#define CSL_KSBUS_RAT_BASE53_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE53_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE53_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE53_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE53_RESETVAL                                          (0x00000000U)

/* SIZE53 */

#define CSL_KSBUS_RAT_SIZE53_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE53_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE53_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE53_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE53_RESETVAL                                          (0x00000000U)

/* UPPER53 */

#define CSL_KSBUS_RAT_UPPER53_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER53_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER53_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER53_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER53_RESETVAL                                         (0x00000000U)

/* LOWER53 */

#define CSL_KSBUS_RAT_LOWER53_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER53_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER53_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER53_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER53_RESETVAL                                         (0x00000000U)

/* CTRL54 */

#define CSL_KSBUS_RAT_CTRL54_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL54_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL54_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL54_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL54_RESETVAL                                          (0x00000000U)

/* BASE54 */

#define CSL_KSBUS_RAT_BASE54_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE54_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE54_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE54_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE54_RESETVAL                                          (0x00000000U)

/* SIZE54 */

#define CSL_KSBUS_RAT_SIZE54_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE54_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE54_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE54_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE54_RESETVAL                                          (0x00000000U)

/* UPPER54 */

#define CSL_KSBUS_RAT_UPPER54_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER54_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER54_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER54_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER54_RESETVAL                                         (0x00000000U)

/* LOWER54 */

#define CSL_KSBUS_RAT_LOWER54_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER54_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER54_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER54_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER54_RESETVAL                                         (0x00000000U)

/* CTRL55 */

#define CSL_KSBUS_RAT_CTRL55_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL55_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL55_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL55_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL55_RESETVAL                                          (0x00000000U)

/* BASE55 */

#define CSL_KSBUS_RAT_BASE55_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE55_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE55_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE55_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE55_RESETVAL                                          (0x00000000U)

/* SIZE55 */

#define CSL_KSBUS_RAT_SIZE55_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE55_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE55_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE55_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE55_RESETVAL                                          (0x00000000U)

/* UPPER55 */

#define CSL_KSBUS_RAT_UPPER55_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER55_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER55_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER55_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER55_RESETVAL                                         (0x00000000U)

/* LOWER55 */

#define CSL_KSBUS_RAT_LOWER55_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER55_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER55_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER55_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER55_RESETVAL                                         (0x00000000U)

/* CTRL56 */

#define CSL_KSBUS_RAT_CTRL56_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL56_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL56_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL56_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL56_RESETVAL                                          (0x00000000U)

/* BASE56 */

#define CSL_KSBUS_RAT_BASE56_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE56_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE56_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE56_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE56_RESETVAL                                          (0x00000000U)

/* SIZE56 */

#define CSL_KSBUS_RAT_SIZE56_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE56_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE56_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE56_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE56_RESETVAL                                          (0x00000000U)

/* UPPER56 */

#define CSL_KSBUS_RAT_UPPER56_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER56_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER56_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER56_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER56_RESETVAL                                         (0x00000000U)

/* LOWER56 */

#define CSL_KSBUS_RAT_LOWER56_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER56_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER56_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER56_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER56_RESETVAL                                         (0x00000000U)

/* CTRL57 */

#define CSL_KSBUS_RAT_CTRL57_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL57_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL57_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL57_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL57_RESETVAL                                          (0x00000000U)

/* BASE57 */

#define CSL_KSBUS_RAT_BASE57_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE57_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE57_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE57_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE57_RESETVAL                                          (0x00000000U)

/* SIZE57 */

#define CSL_KSBUS_RAT_SIZE57_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE57_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE57_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE57_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE57_RESETVAL                                          (0x00000000U)

/* UPPER57 */

#define CSL_KSBUS_RAT_UPPER57_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER57_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER57_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER57_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER57_RESETVAL                                         (0x00000000U)

/* LOWER57 */

#define CSL_KSBUS_RAT_LOWER57_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER57_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER57_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER57_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER57_RESETVAL                                         (0x00000000U)

/* CTRL58 */

#define CSL_KSBUS_RAT_CTRL58_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL58_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL58_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL58_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL58_RESETVAL                                          (0x00000000U)

/* BASE58 */

#define CSL_KSBUS_RAT_BASE58_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE58_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE58_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE58_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE58_RESETVAL                                          (0x00000000U)

/* SIZE58 */

#define CSL_KSBUS_RAT_SIZE58_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE58_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE58_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE58_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE58_RESETVAL                                          (0x00000000U)

/* UPPER58 */

#define CSL_KSBUS_RAT_UPPER58_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER58_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER58_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER58_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER58_RESETVAL                                         (0x00000000U)

/* LOWER58 */

#define CSL_KSBUS_RAT_LOWER58_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER58_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER58_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER58_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER58_RESETVAL                                         (0x00000000U)

/* CTRL59 */

#define CSL_KSBUS_RAT_CTRL59_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL59_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL59_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL59_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL59_RESETVAL                                          (0x00000000U)

/* BASE59 */

#define CSL_KSBUS_RAT_BASE59_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE59_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE59_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE59_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE59_RESETVAL                                          (0x00000000U)

/* SIZE59 */

#define CSL_KSBUS_RAT_SIZE59_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE59_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE59_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE59_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE59_RESETVAL                                          (0x00000000U)

/* UPPER59 */

#define CSL_KSBUS_RAT_UPPER59_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER59_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER59_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER59_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER59_RESETVAL                                         (0x00000000U)

/* LOWER59 */

#define CSL_KSBUS_RAT_LOWER59_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER59_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER59_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER59_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER59_RESETVAL                                         (0x00000000U)

/* CTRL60 */

#define CSL_KSBUS_RAT_CTRL60_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL60_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL60_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL60_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL60_RESETVAL                                          (0x00000000U)

/* BASE60 */

#define CSL_KSBUS_RAT_BASE60_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE60_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE60_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE60_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE60_RESETVAL                                          (0x00000000U)

/* SIZE60 */

#define CSL_KSBUS_RAT_SIZE60_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE60_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE60_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE60_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE60_RESETVAL                                          (0x00000000U)

/* UPPER60 */

#define CSL_KSBUS_RAT_UPPER60_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER60_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER60_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER60_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER60_RESETVAL                                         (0x00000000U)

/* LOWER60 */

#define CSL_KSBUS_RAT_LOWER60_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER60_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER60_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER60_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER60_RESETVAL                                         (0x00000000U)

/* CTRL61 */

#define CSL_KSBUS_RAT_CTRL61_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL61_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL61_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL61_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL61_RESETVAL                                          (0x00000000U)

/* BASE61 */

#define CSL_KSBUS_RAT_BASE61_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE61_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE61_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE61_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE61_RESETVAL                                          (0x00000000U)

/* SIZE61 */

#define CSL_KSBUS_RAT_SIZE61_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE61_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE61_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE61_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE61_RESETVAL                                          (0x00000000U)

/* UPPER61 */

#define CSL_KSBUS_RAT_UPPER61_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER61_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER61_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER61_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER61_RESETVAL                                         (0x00000000U)

/* LOWER61 */

#define CSL_KSBUS_RAT_LOWER61_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER61_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER61_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER61_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER61_RESETVAL                                         (0x00000000U)

/* CTRL62 */

#define CSL_KSBUS_RAT_CTRL62_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL62_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL62_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL62_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL62_RESETVAL                                          (0x00000000U)

/* BASE62 */

#define CSL_KSBUS_RAT_BASE62_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE62_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE62_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE62_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE62_RESETVAL                                          (0x00000000U)

/* SIZE62 */

#define CSL_KSBUS_RAT_SIZE62_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE62_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE62_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE62_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE62_RESETVAL                                          (0x00000000U)

/* UPPER62 */

#define CSL_KSBUS_RAT_UPPER62_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER62_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER62_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER62_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER62_RESETVAL                                         (0x00000000U)

/* LOWER62 */

#define CSL_KSBUS_RAT_LOWER62_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER62_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER62_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER62_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER62_RESETVAL                                         (0x00000000U)

/* CTRL63 */

#define CSL_KSBUS_RAT_CTRL63_BASE_MASK                                         (0x00000001U)
#define CSL_KSBUS_RAT_CTRL63_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_CTRL63_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_CTRL63_BASE_MAX                                          (0x00000001U)

#define CSL_KSBUS_RAT_CTRL63_RESETVAL                                          (0x00000000U)

/* BASE63 */

#define CSL_KSBUS_RAT_BASE63_BASE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_BASE63_BASE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_BASE63_BASE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_BASE63_BASE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_BASE63_RESETVAL                                          (0x00000000U)

/* SIZE63 */

#define CSL_KSBUS_RAT_SIZE63_SIZE_MASK                                         (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_SIZE63_SIZE_SHIFT                                        (0x00000000U)
#define CSL_KSBUS_RAT_SIZE63_SIZE_RESETVAL                                     (0x00000000U)
#define CSL_KSBUS_RAT_SIZE63_SIZE_MAX                                          (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_SIZE63_RESETVAL                                          (0x00000000U)

/* UPPER63 */

#define CSL_KSBUS_RAT_UPPER63_UPPER_MASK                                       (0x0000FFFFU)
#define CSL_KSBUS_RAT_UPPER63_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_UPPER63_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_UPPER63_UPPER_MAX                                        (0x0000FFFFU)

#define CSL_KSBUS_RAT_UPPER63_RESETVAL                                         (0x00000000U)

/* LOWER63 */

#define CSL_KSBUS_RAT_LOWER63_UPPER_MASK                                       (0xFFFFFFFFU)
#define CSL_KSBUS_RAT_LOWER63_UPPER_SHIFT                                      (0x00000000U)
#define CSL_KSBUS_RAT_LOWER63_UPPER_RESETVAL                                   (0x00000000U)
#define CSL_KSBUS_RAT_LOWER63_UPPER_MAX                                        (0xFFFFFFFFU)

#define CSL_KSBUS_RAT_LOWER63_RESETVAL                                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
