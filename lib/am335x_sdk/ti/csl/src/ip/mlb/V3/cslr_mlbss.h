/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_mlbss.h
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
* Module Base Offset Values
**************************************************************************/

#define CSL_MLBSS_ECC_AGGR_REGS_BASE                                        (0x00000000U)
#define CSL_MLBSS_MLBDIM_CFG_REGS_BASE                                      (0x00000000U)
#define CSL_MLBSS_MLBSS_CFG_REGS_BASE                                       (0x00000000U)
#define CSL_MLBSS_RAT_REGS_BASE                                             (0x00000000U)


/**************************************************************************
* Hardware Region  : Global Control Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t STAT;                      /* Status Regsiter */
    volatile uint32_t DMA_CTRL;                  /* DMA Control Regsiter */
} CSL_mlbss_cfgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MLBSS_CFG_PID                                                      (0x00000000U)
#define CSL_MLBSS_CFG_STAT                                                     (0x00000008U)
#define CSL_MLBSS_CFG_DMA_CTRL                                                 (0x0000000CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_MLBSS_CFG_PID_MINOR_MASK                                           (0x0000003FU)
#define CSL_MLBSS_CFG_PID_MINOR_SHIFT                                          (0x00000000U)
#define CSL_MLBSS_CFG_PID_MINOR_MAX                                            (0x0000003FU)

#define CSL_MLBSS_CFG_PID_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_MLBSS_CFG_PID_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_MLBSS_CFG_PID_CUSTOM_MAX                                           (0x00000003U)

#define CSL_MLBSS_CFG_PID_MAJOR_MASK                                           (0x00000700U)
#define CSL_MLBSS_CFG_PID_MAJOR_SHIFT                                          (0x00000008U)
#define CSL_MLBSS_CFG_PID_MAJOR_MAX                                            (0x00000007U)

#define CSL_MLBSS_CFG_PID_RTL_MASK                                             (0x0000F800U)
#define CSL_MLBSS_CFG_PID_RTL_SHIFT                                            (0x0000000BU)
#define CSL_MLBSS_CFG_PID_RTL_MAX                                              (0x0000001FU)

#define CSL_MLBSS_CFG_PID_MODULE_ID_MASK                                       (0x0FFF0000U)
#define CSL_MLBSS_CFG_PID_MODULE_ID_SHIFT                                      (0x00000010U)
#define CSL_MLBSS_CFG_PID_MODULE_ID_MAX                                        (0x00000FFFU)

#define CSL_MLBSS_CFG_PID_BU_MASK                                              (0x30000000U)
#define CSL_MLBSS_CFG_PID_BU_SHIFT                                             (0x0000001CU)
#define CSL_MLBSS_CFG_PID_BU_MAX                                               (0x00000003U)

#define CSL_MLBSS_CFG_PID_SCHEME_MASK                                          (0xC0000000U)
#define CSL_MLBSS_CFG_PID_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_MLBSS_CFG_PID_SCHEME_MAX                                           (0x00000003U)

/* STAT */

#define CSL_MLBSS_CFG_STAT_MEM_INIT_DONE_MASK                                  (0x00000002U)
#define CSL_MLBSS_CFG_STAT_MEM_INIT_DONE_SHIFT                                 (0x00000001U)
#define CSL_MLBSS_CFG_STAT_MEM_INIT_DONE_MAX                                   (0x00000001U)

/* DMA_CTRL */

#define CSL_MLBSS_CFG_DMA_CTRL_PRIORITY_MASK                                   (0x00000007U)
#define CSL_MLBSS_CFG_DMA_CTRL_PRIORITY_SHIFT                                  (0x00000000U)
#define CSL_MLBSS_CFG_DMA_CTRL_PRIORITY_MAX                                    (0x00000007U)

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
    volatile uint8_t  Resv_252[20];
    volatile uint32_t PID;                       /* MLBDIM Revision ID */
    volatile uint8_t  Resv_960[704];
    volatile uint32_t ACTL;                      /* AHB Control */
    volatile uint8_t  Resv_976[12];
    volatile uint32_t ACSR0;                     /* AHB Channel Status 0 */
    volatile uint32_t ACSR1;                     /* AHB Channel Status 1 */
    volatile uint32_t ACMR0;                     /* AHB Channel Mask 0 */
    volatile uint32_t ACMR1;                     /* AHB Channel Mask 1 */
} CSL_mlbdim_cfgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MLBDIM_CFG_MLBC0                                                   (0x00000000U)
#define CSL_MLBDIM_CFG_MLBPC0                                                  (0x00000008U)
#define CSL_MLBDIM_CFG_MS0                                                     (0x0000000CU)
#define CSL_MLBDIM_CFG_MS1                                                     (0x00000014U)
#define CSL_MLBDIM_CFG_MSS                                                     (0x00000020U)
#define CSL_MLBDIM_CFG_MSD                                                     (0x00000024U)
#define CSL_MLBDIM_CFG_MIEN                                                    (0x0000002CU)
#define CSL_MLBDIM_CFG_MLBPC2                                                  (0x00000034U)
#define CSL_MLBDIM_CFG_MLBPC1                                                  (0x00000038U)
#define CSL_MLBDIM_CFG_MLBC1                                                   (0x0000003CU)
#define CSL_MLBDIM_CFG_HCTL                                                    (0x00000080U)
#define CSL_MLBDIM_CFG_HCMR0                                                   (0x00000088U)
#define CSL_MLBDIM_CFG_HCMR1                                                   (0x0000008CU)
#define CSL_MLBDIM_CFG_HCER0                                                   (0x00000090U)
#define CSL_MLBDIM_CFG_HCER1                                                   (0x00000094U)
#define CSL_MLBDIM_CFG_HCBR0                                                   (0x00000098U)
#define CSL_MLBDIM_CFG_HCBR1                                                   (0x0000009CU)
#define CSL_MLBDIM_CFG_MDAT0                                                   (0x000000C0U)
#define CSL_MLBDIM_CFG_MDAT1                                                   (0x000000C4U)
#define CSL_MLBDIM_CFG_MDAT2                                                   (0x000000C8U)
#define CSL_MLBDIM_CFG_MDAT3                                                   (0x000000CCU)
#define CSL_MLBDIM_CFG_MDWE0                                                   (0x000000D0U)
#define CSL_MLBDIM_CFG_MDWE1                                                   (0x000000D4U)
#define CSL_MLBDIM_CFG_MDWE2                                                   (0x000000D8U)
#define CSL_MLBDIM_CFG_MDWE3                                                   (0x000000DCU)
#define CSL_MLBDIM_CFG_MCTL                                                    (0x000000E0U)
#define CSL_MLBDIM_CFG_MADR                                                    (0x000000E4U)
#define CSL_MLBDIM_CFG_PID                                                     (0x000000FCU)
#define CSL_MLBDIM_CFG_ACTL                                                    (0x000003C0U)
#define CSL_MLBDIM_CFG_ACSR0                                                   (0x000003D0U)
#define CSL_MLBDIM_CFG_ACSR1                                                   (0x000003D4U)
#define CSL_MLBDIM_CFG_ACMR0                                                   (0x000003D8U)
#define CSL_MLBDIM_CFG_ACMR1                                                   (0x000003DCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MLBC0 */

#define CSL_MLBDIM_CFG_MLBC0_MLBEN_MASK                                        (0x00000001U)
#define CSL_MLBDIM_CFG_MLBC0_MLBEN_SHIFT                                       (0x00000000U)
#define CSL_MLBDIM_CFG_MLBC0_MLBEN_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_RSV0_MASK                                         (0x00000002U)
#define CSL_MLBDIM_CFG_MLBC0_RSV0_SHIFT                                        (0x00000001U)
#define CSL_MLBDIM_CFG_MLBC0_RSV0_MAX                                          (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_MLBCLK_MASK                                       (0x0000001CU)
#define CSL_MLBDIM_CFG_MLBC0_MLBCLK_SHIFT                                      (0x00000002U)
#define CSL_MLBDIM_CFG_MLBC0_MLBCLK_MAX                                        (0x00000007U)

#define CSL_MLBDIM_CFG_MLBC0_MLBPEN_MASK                                       (0x00000020U)
#define CSL_MLBDIM_CFG_MLBC0_MLBPEN_SHIFT                                      (0x00000005U)
#define CSL_MLBDIM_CFG_MLBC0_MLBPEN_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_RSV1_MASK                                         (0x00000040U)
#define CSL_MLBDIM_CFG_MLBC0_RSV1_SHIFT                                        (0x00000006U)
#define CSL_MLBDIM_CFG_MLBC0_RSV1_MAX                                          (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_MLBLK_MASK                                        (0x00000080U)
#define CSL_MLBDIM_CFG_MLBC0_MLBLK_SHIFT                                       (0x00000007U)
#define CSL_MLBDIM_CFG_MLBC0_MLBLK_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_RSV2_MASK                                         (0x00000F00U)
#define CSL_MLBDIM_CFG_MLBC0_RSV2_SHIFT                                        (0x00000008U)
#define CSL_MLBDIM_CFG_MLBC0_RSV2_MAX                                          (0x0000000FU)

#define CSL_MLBDIM_CFG_MLBC0_ASYRETRY_MASK                                     (0x00001000U)
#define CSL_MLBDIM_CFG_MLBC0_ASYRETRY_SHIFT                                    (0x0000000CU)
#define CSL_MLBDIM_CFG_MLBC0_ASYRETRY_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_RSV3_MASK                                         (0x00002000U)
#define CSL_MLBDIM_CFG_MLBC0_RSV3_SHIFT                                        (0x0000000DU)
#define CSL_MLBDIM_CFG_MLBC0_RSV3_MAX                                          (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_CTLRETRY_MASK                                     (0x00004000U)
#define CSL_MLBDIM_CFG_MLBC0_CTLRETRY_SHIFT                                    (0x0000000EU)
#define CSL_MLBDIM_CFG_MLBC0_CTLRETRY_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC0_FCNT_MASK                                         (0x00038000U)
#define CSL_MLBDIM_CFG_MLBC0_FCNT_SHIFT                                        (0x0000000FU)
#define CSL_MLBDIM_CFG_MLBC0_FCNT_MAX                                          (0x00000007U)

#define CSL_MLBDIM_CFG_MLBC0_RSV4_MASK                                         (0xFFFC0000U)
#define CSL_MLBDIM_CFG_MLBC0_RSV4_SHIFT                                        (0x00000012U)
#define CSL_MLBDIM_CFG_MLBC0_RSV4_MAX                                          (0x00003FFFU)

/* MLBPC0 */

#define CSL_MLBDIM_CFG_MLBPC0_RSV0_MASK                                        (0x00000001U)
#define CSL_MLBDIM_CFG_MLBPC0_RSV0_SHIFT                                       (0x00000000U)
#define CSL_MLBDIM_CFG_MLBPC0_RSV0_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MLBPC0_MLBCMRES_MASK                                    (0x00000002U)
#define CSL_MLBDIM_CFG_MLBPC0_MLBCMRES_SHIFT                                   (0x00000001U)
#define CSL_MLBDIM_CFG_MLBPC0_MLBCMRES_MAX                                     (0x00000001U)

#define CSL_MLBDIM_CFG_MLBPC0_RSV1_MASK                                        (0x000007FCU)
#define CSL_MLBDIM_CFG_MLBPC0_RSV1_SHIFT                                       (0x00000002U)
#define CSL_MLBDIM_CFG_MLBPC0_RSV1_MAX                                         (0x000001FFU)

#define CSL_MLBDIM_CFG_MLBPC0_MCLKHYS_MASK                                     (0x00000800U)
#define CSL_MLBDIM_CFG_MLBPC0_MCLKHYS_SHIFT                                    (0x0000000BU)
#define CSL_MLBDIM_CFG_MLBPC0_MCLKHYS_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MLBPC0_RSV2_MASK                                        (0xFFFFF000U)
#define CSL_MLBDIM_CFG_MLBPC0_RSV2_SHIFT                                       (0x0000000CU)
#define CSL_MLBDIM_CFG_MLBPC0_RSV2_MAX                                         (0x000FFFFFU)

/* MS0 */

#define CSL_MLBDIM_CFG_MS0_MCS_MASK                                            (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MS0_MCS_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_CFG_MS0_MCS_MAX                                             (0xFFFFFFFFU)

/* MS1 */

#define CSL_MLBDIM_CFG_MS1_MCS_MASK                                            (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MS1_MCS_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_CFG_MS1_MCS_MAX                                             (0xFFFFFFFFU)

/* MSS */

#define CSL_MLBDIM_CFG_MSS_RSTSYSCMD_MASK                                      (0x00000001U)
#define CSL_MLBDIM_CFG_MSS_RSTSYSCMD_SHIFT                                     (0x00000000U)
#define CSL_MLBDIM_CFG_MSS_RSTSYSCMD_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_LKSYSCMD_MASK                                       (0x00000002U)
#define CSL_MLBDIM_CFG_MSS_LKSYSCMD_SHIFT                                      (0x00000001U)
#define CSL_MLBDIM_CFG_MSS_LKSYSCMD_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_ULKSYSCMD_MASK                                      (0x00000004U)
#define CSL_MLBDIM_CFG_MSS_ULKSYSCMD_SHIFT                                     (0x00000002U)
#define CSL_MLBDIM_CFG_MSS_ULKSYSCMD_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_CSSYSCMD_MASK                                       (0x00000008U)
#define CSL_MLBDIM_CFG_MSS_CSSYSCMD_SHIFT                                      (0x00000003U)
#define CSL_MLBDIM_CFG_MSS_CSSYSCMD_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_SWSYSCMD_MASK                                       (0x00000010U)
#define CSL_MLBDIM_CFG_MSS_SWSYSCMD_SHIFT                                      (0x00000004U)
#define CSL_MLBDIM_CFG_MSS_SWSYSCMD_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_SERVREQ_MASK                                        (0x00000020U)
#define CSL_MLBDIM_CFG_MSS_SERVREQ_SHIFT                                       (0x00000005U)
#define CSL_MLBDIM_CFG_MSS_SERVREQ_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MSS_RSV0_MASK                                           (0xFFFFFFC0U)
#define CSL_MLBDIM_CFG_MSS_RSV0_SHIFT                                          (0x00000006U)
#define CSL_MLBDIM_CFG_MSS_RSV0_MAX                                            (0x03FFFFFFU)

/* MSD */

#define CSL_MLBDIM_CFG_MSD_SD0_MASK                                            (0x000000FFU)
#define CSL_MLBDIM_CFG_MSD_SD0_SHIFT                                           (0x00000000U)
#define CSL_MLBDIM_CFG_MSD_SD0_MAX                                             (0x000000FFU)

#define CSL_MLBDIM_CFG_MSD_SD1_MASK                                            (0x0000FF00U)
#define CSL_MLBDIM_CFG_MSD_SD1_SHIFT                                           (0x00000008U)
#define CSL_MLBDIM_CFG_MSD_SD1_MAX                                             (0x000000FFU)

#define CSL_MLBDIM_CFG_MSD_SD2_MASK                                            (0x00FF0000U)
#define CSL_MLBDIM_CFG_MSD_SD2_SHIFT                                           (0x00000010U)
#define CSL_MLBDIM_CFG_MSD_SD2_MAX                                             (0x000000FFU)

#define CSL_MLBDIM_CFG_MSD_SD3_MASK                                            (0xFF000000U)
#define CSL_MLBDIM_CFG_MSD_SD3_SHIFT                                           (0x00000018U)
#define CSL_MLBDIM_CFG_MSD_SD3_MAX                                             (0x000000FFU)

/* MIEN */

#define CSL_MLBDIM_CFG_MIEN_ISOC_PE_MASK                                       (0x00000001U)
#define CSL_MLBDIM_CFG_MIEN_ISOC_PE_SHIFT                                      (0x00000000U)
#define CSL_MLBDIM_CFG_MIEN_ISOC_PE_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ISOC_BUFO_MASK                                     (0x00000002U)
#define CSL_MLBDIM_CFG_MIEN_ISOC_BUFO_SHIFT                                    (0x00000001U)
#define CSL_MLBDIM_CFG_MIEN_ISOC_BUFO_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_RSV0_MASK                                          (0x0000FFFCU)
#define CSL_MLBDIM_CFG_MIEN_RSV0_SHIFT                                         (0x00000002U)
#define CSL_MLBDIM_CFG_MIEN_RSV0_MAX                                           (0x00003FFFU)

#define CSL_MLBDIM_CFG_MIEN_SYNC_PE_MASK                                       (0x00010000U)
#define CSL_MLBDIM_CFG_MIEN_SYNC_PE_SHIFT                                      (0x00000010U)
#define CSL_MLBDIM_CFG_MIEN_SYNC_PE_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ARX_DONE_MASK                                      (0x00020000U)
#define CSL_MLBDIM_CFG_MIEN_ARX_DONE_SHIFT                                     (0x00000011U)
#define CSL_MLBDIM_CFG_MIEN_ARX_DONE_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ARX_PE_MASK                                        (0x00040000U)
#define CSL_MLBDIM_CFG_MIEN_ARX_PE_SHIFT                                       (0x00000012U)
#define CSL_MLBDIM_CFG_MIEN_ARX_PE_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ARX_BREAK_MASK                                     (0x00080000U)
#define CSL_MLBDIM_CFG_MIEN_ARX_BREAK_SHIFT                                    (0x00000013U)
#define CSL_MLBDIM_CFG_MIEN_ARX_BREAK_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ATX_DONE_MASK                                      (0x00100000U)
#define CSL_MLBDIM_CFG_MIEN_ATX_DONE_SHIFT                                     (0x00000014U)
#define CSL_MLBDIM_CFG_MIEN_ATX_DONE_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ATX_PE_MASK                                        (0x00200000U)
#define CSL_MLBDIM_CFG_MIEN_ATX_PE_SHIFT                                       (0x00000015U)
#define CSL_MLBDIM_CFG_MIEN_ATX_PE_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_ATX_BREAK_MASK                                     (0x00400000U)
#define CSL_MLBDIM_CFG_MIEN_ATX_BREAK_SHIFT                                    (0x00000016U)
#define CSL_MLBDIM_CFG_MIEN_ATX_BREAK_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_RSV1_MASK                                          (0x00800000U)
#define CSL_MLBDIM_CFG_MIEN_RSV1_SHIFT                                         (0x00000017U)
#define CSL_MLBDIM_CFG_MIEN_RSV1_MAX                                           (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CRX_DONE_MASK                                      (0x01000000U)
#define CSL_MLBDIM_CFG_MIEN_CRX_DONE_SHIFT                                     (0x00000018U)
#define CSL_MLBDIM_CFG_MIEN_CRX_DONE_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CRX_PE_MASK                                        (0x02000000U)
#define CSL_MLBDIM_CFG_MIEN_CRX_PE_SHIFT                                       (0x00000019U)
#define CSL_MLBDIM_CFG_MIEN_CRX_PE_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CRX_BREAK_MASK                                     (0x04000000U)
#define CSL_MLBDIM_CFG_MIEN_CRX_BREAK_SHIFT                                    (0x0000001AU)
#define CSL_MLBDIM_CFG_MIEN_CRX_BREAK_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CTX_DONE_MASK                                      (0x08000000U)
#define CSL_MLBDIM_CFG_MIEN_CTX_DONE_SHIFT                                     (0x0000001BU)
#define CSL_MLBDIM_CFG_MIEN_CTX_DONE_MAX                                       (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CTX_PE_MASK                                        (0x10000000U)
#define CSL_MLBDIM_CFG_MIEN_CTX_PE_SHIFT                                       (0x0000001CU)
#define CSL_MLBDIM_CFG_MIEN_CTX_PE_MAX                                         (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_CTX_BREAK_MASK                                     (0x20000000U)
#define CSL_MLBDIM_CFG_MIEN_CTX_BREAK_SHIFT                                    (0x0000001DU)
#define CSL_MLBDIM_CFG_MIEN_CTX_BREAK_MAX                                      (0x00000001U)

#define CSL_MLBDIM_CFG_MIEN_RSV2_MASK                                          (0xC0000000U)
#define CSL_MLBDIM_CFG_MIEN_RSV2_SHIFT                                         (0x0000001EU)
#define CSL_MLBDIM_CFG_MIEN_RSV2_MAX                                           (0x00000003U)

/* MLBPC2 */

#define CSL_MLBDIM_CFG_MLBPC2_UCFG_MASK                                        (0x0000FFFFU)
#define CSL_MLBDIM_CFG_MLBPC2_UCFG_SHIFT                                       (0x00000000U)
#define CSL_MLBDIM_CFG_MLBPC2_UCFG_MAX                                         (0x0000FFFFU)

#define CSL_MLBDIM_CFG_MLBPC2_RSV0_MASK                                        (0xFFFF0000U)
#define CSL_MLBDIM_CFG_MLBPC2_RSV0_SHIFT                                       (0x00000010U)
#define CSL_MLBDIM_CFG_MLBPC2_RSV0_MAX                                         (0x0000FFFFU)

/* MLBPC1 */

#define CSL_MLBDIM_CFG_MLBPC1_SDRCVBIAS_MASK                                   (0x0000000FU)
#define CSL_MLBDIM_CFG_MLBPC1_SDRCVBIAS_SHIFT                                  (0x00000000U)
#define CSL_MLBDIM_CFG_MLBPC1_SDRCVBIAS_MAX                                    (0x0000000FU)

#define CSL_MLBDIM_CFG_MLBPC1_SDXMTBIAS_MASK                                   (0x000000F0U)
#define CSL_MLBDIM_CFG_MLBPC1_SDXMTBIAS_SHIFT                                  (0x00000004U)
#define CSL_MLBDIM_CFG_MLBPC1_SDXMTBIAS_MAX                                    (0x0000000FU)

#define CSL_MLBDIM_CFG_MLBPC1_CKRCVBIAS_MASK                                   (0x00000F00U)
#define CSL_MLBDIM_CFG_MLBPC1_CKRCVBIAS_SHIFT                                  (0x00000008U)
#define CSL_MLBDIM_CFG_MLBPC1_CKRCVBIAS_MAX                                    (0x0000000FU)

#define CSL_MLBDIM_CFG_MLBPC1_RSV0_MASK                                        (0xFFFFF000U)
#define CSL_MLBDIM_CFG_MLBPC1_RSV0_SHIFT                                       (0x0000000CU)
#define CSL_MLBDIM_CFG_MLBPC1_RSV0_MAX                                         (0x000FFFFFU)

/* MLBC1 */

#define CSL_MLBDIM_CFG_MLBC1_RSV0_MASK                                         (0x0000003FU)
#define CSL_MLBDIM_CFG_MLBC1_RSV0_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MLBC1_RSV0_MAX                                          (0x0000003FU)

#define CSL_MLBDIM_CFG_MLBC1_LOCK_MASK                                         (0x00000040U)
#define CSL_MLBDIM_CFG_MLBC1_LOCK_SHIFT                                        (0x00000006U)
#define CSL_MLBDIM_CFG_MLBC1_LOCK_MAX                                          (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC1_CLKM_MASK                                         (0x00000080U)
#define CSL_MLBDIM_CFG_MLBC1_CLKM_SHIFT                                        (0x00000007U)
#define CSL_MLBDIM_CFG_MLBC1_CLKM_MAX                                          (0x00000001U)

#define CSL_MLBDIM_CFG_MLBC1_NDA_MASK                                          (0x0000FF00U)
#define CSL_MLBDIM_CFG_MLBC1_NDA_SHIFT                                         (0x00000008U)
#define CSL_MLBDIM_CFG_MLBC1_NDA_MAX                                           (0x000000FFU)

#define CSL_MLBDIM_CFG_MLBC1_RSV1_MASK                                         (0xFFFF0000U)
#define CSL_MLBDIM_CFG_MLBC1_RSV1_SHIFT                                        (0x00000010U)
#define CSL_MLBDIM_CFG_MLBC1_RSV1_MAX                                          (0x0000FFFFU)

/* HCTL */

#define CSL_MLBDIM_CFG_HCTL_RST0_MASK                                          (0x00000001U)
#define CSL_MLBDIM_CFG_HCTL_RST0_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_HCTL_RST0_MAX                                           (0x00000001U)

#define CSL_MLBDIM_CFG_HCTL_RST1_MASK                                          (0x00000002U)
#define CSL_MLBDIM_CFG_HCTL_RST1_SHIFT                                         (0x00000001U)
#define CSL_MLBDIM_CFG_HCTL_RST1_MAX                                           (0x00000001U)

#define CSL_MLBDIM_CFG_HCTL_RSV0_MASK                                          (0x00007FFCU)
#define CSL_MLBDIM_CFG_HCTL_RSV0_SHIFT                                         (0x00000002U)
#define CSL_MLBDIM_CFG_HCTL_RSV0_MAX                                           (0x00001FFFU)

#define CSL_MLBDIM_CFG_HCTL_EN_MASK                                            (0x00008000U)
#define CSL_MLBDIM_CFG_HCTL_EN_SHIFT                                           (0x0000000FU)
#define CSL_MLBDIM_CFG_HCTL_EN_MAX                                             (0x00000001U)

#define CSL_MLBDIM_CFG_HCTL_RSV1_MASK                                          (0xFFFF0000U)
#define CSL_MLBDIM_CFG_HCTL_RSV1_SHIFT                                         (0x00000010U)
#define CSL_MLBDIM_CFG_HCTL_RSV1_MAX                                           (0x0000FFFFU)

/* HCMR0 */

#define CSL_MLBDIM_CFG_HCMR0_CHM_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCMR0_CHM_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_HCMR0_CHM_MAX                                           (0xFFFFFFFFU)

/* HCMR1 */

#define CSL_MLBDIM_CFG_HCMR1_CHM_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCMR1_CHM_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_HCMR1_CHM_MAX                                           (0xFFFFFFFFU)

/* HCER0 */

#define CSL_MLBDIM_CFG_HCER0_CERR_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCER0_CERR_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_HCER0_CERR_MAX                                          (0xFFFFFFFFU)

/* HCER1 */

#define CSL_MLBDIM_CFG_HCER1_CERR_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCER1_CERR_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_HCER1_CERR_MAX                                          (0xFFFFFFFFU)

/* HCBR0 */

#define CSL_MLBDIM_CFG_HCBR0_CHB_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCBR0_CHB_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_HCBR0_CHB_MAX                                           (0xFFFFFFFFU)

/* HCBR1 */

#define CSL_MLBDIM_CFG_HCBR1_CHB_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_HCBR1_CHB_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_HCBR1_CHB_MAX                                           (0xFFFFFFFFU)

/* MDAT0 */

#define CSL_MLBDIM_CFG_MDAT0_DATA_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDAT0_DATA_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDAT0_DATA_MAX                                          (0xFFFFFFFFU)

/* MDAT1 */

#define CSL_MLBDIM_CFG_MDAT1_DATA_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDAT1_DATA_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDAT1_DATA_MAX                                          (0xFFFFFFFFU)

/* MDAT2 */

#define CSL_MLBDIM_CFG_MDAT2_DATA_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDAT2_DATA_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDAT2_DATA_MAX                                          (0xFFFFFFFFU)

/* MDAT3 */

#define CSL_MLBDIM_CFG_MDAT3_DATA_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDAT3_DATA_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDAT3_DATA_MAX                                          (0xFFFFFFFFU)

/* MDWE0 */

#define CSL_MLBDIM_CFG_MDWE0_MASK_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDWE0_MASK_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDWE0_MASK_MAX                                          (0xFFFFFFFFU)

/* MDWE1 */

#define CSL_MLBDIM_CFG_MDWE1_MASK_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDWE1_MASK_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDWE1_MASK_MAX                                          (0xFFFFFFFFU)

/* MDWE2 */

#define CSL_MLBDIM_CFG_MDWE2_MASK_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDWE2_MASK_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDWE2_MASK_MAX                                          (0xFFFFFFFFU)

/* MDWE3 */

#define CSL_MLBDIM_CFG_MDWE3_MASK_MASK                                         (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_MDWE3_MASK_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MDWE3_MASK_MAX                                          (0xFFFFFFFFU)

/* MCTL */

#define CSL_MLBDIM_CFG_MCTL_XCMP_MASK                                          (0x00000001U)
#define CSL_MLBDIM_CFG_MCTL_XCMP_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_MCTL_XCMP_MAX                                           (0x00000001U)

#define CSL_MLBDIM_CFG_MCTL_RSV0_MASK                                          (0xFFFFFFFEU)
#define CSL_MLBDIM_CFG_MCTL_RSV0_SHIFT                                         (0x00000001U)
#define CSL_MLBDIM_CFG_MCTL_RSV0_MAX                                           (0x7FFFFFFFU)

/* MADR */

#define CSL_MLBDIM_CFG_MADR_ADDR0_MASK                                         (0x000000FFU)
#define CSL_MLBDIM_CFG_MADR_ADDR0_SHIFT                                        (0x00000000U)
#define CSL_MLBDIM_CFG_MADR_ADDR0_MAX                                          (0x000000FFU)

#define CSL_MLBDIM_CFG_MADR_ADDR1_MASK                                         (0x00003F00U)
#define CSL_MLBDIM_CFG_MADR_ADDR1_SHIFT                                        (0x00000008U)
#define CSL_MLBDIM_CFG_MADR_ADDR1_MAX                                          (0x0000003FU)

#define CSL_MLBDIM_CFG_MADR_RSV0_MASK                                          (0x3FFFC000U)
#define CSL_MLBDIM_CFG_MADR_RSV0_SHIFT                                         (0x0000000EU)
#define CSL_MLBDIM_CFG_MADR_RSV0_MAX                                           (0x0000FFFFU)

#define CSL_MLBDIM_CFG_MADR_TB_MASK                                            (0x40000000U)
#define CSL_MLBDIM_CFG_MADR_TB_SHIFT                                           (0x0000001EU)
#define CSL_MLBDIM_CFG_MADR_TB_MAX                                             (0x00000001U)

#define CSL_MLBDIM_CFG_MADR_WNR_MASK                                           (0x80000000U)
#define CSL_MLBDIM_CFG_MADR_WNR_SHIFT                                          (0x0000001FU)
#define CSL_MLBDIM_CFG_MADR_WNR_MAX                                            (0x00000001U)

/* PID */

#define CSL_MLBDIM_CFG_PID_MINOR_MASK                                          (0x000000FFU)
#define CSL_MLBDIM_CFG_PID_MINOR_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_PID_MINOR_MAX                                           (0x000000FFU)

#define CSL_MLBDIM_CFG_PID_MAJOR_MASK                                          (0x0000FF00U)
#define CSL_MLBDIM_CFG_PID_MAJOR_SHIFT                                         (0x00000008U)
#define CSL_MLBDIM_CFG_PID_MAJOR_MAX                                           (0x000000FFU)

#define CSL_MLBDIM_CFG_PID_RSV0_MASK                                           (0xFFFF0000U)
#define CSL_MLBDIM_CFG_PID_RSV0_SHIFT                                          (0x00000010U)
#define CSL_MLBDIM_CFG_PID_RSV0_MAX                                            (0x0000FFFFU)

/* ACTL */

#define CSL_MLBDIM_CFG_ACTL_SCE_MASK                                           (0x00000001U)
#define CSL_MLBDIM_CFG_ACTL_SCE_SHIFT                                          (0x00000000U)
#define CSL_MLBDIM_CFG_ACTL_SCE_MAX                                            (0x00000001U)

#define CSL_MLBDIM_CFG_ACTL_SMX_MASK                                           (0x00000002U)
#define CSL_MLBDIM_CFG_ACTL_SMX_SHIFT                                          (0x00000001U)
#define CSL_MLBDIM_CFG_ACTL_SMX_MAX                                            (0x00000001U)

#define CSL_MLBDIM_CFG_ACTL_DMAMODE_MASK                                       (0x00000004U)
#define CSL_MLBDIM_CFG_ACTL_DMAMODE_SHIFT                                      (0x00000002U)
#define CSL_MLBDIM_CFG_ACTL_DMAMODE_MAX                                        (0x00000001U)

#define CSL_MLBDIM_CFG_ACTL_RSV0_MASK                                          (0x00000008U)
#define CSL_MLBDIM_CFG_ACTL_RSV0_SHIFT                                         (0x00000003U)
#define CSL_MLBDIM_CFG_ACTL_RSV0_MAX                                           (0x00000001U)

#define CSL_MLBDIM_CFG_ACTL_MPB_MASK                                           (0x00000010U)
#define CSL_MLBDIM_CFG_ACTL_MPB_SHIFT                                          (0x00000004U)
#define CSL_MLBDIM_CFG_ACTL_MPB_MAX                                            (0x00000001U)

#define CSL_MLBDIM_CFG_ACTL_RSV1_MASK                                          (0xFFFFFFE0U)
#define CSL_MLBDIM_CFG_ACTL_RSV1_SHIFT                                         (0x00000005U)
#define CSL_MLBDIM_CFG_ACTL_RSV1_MAX                                           (0x07FFFFFFU)

/* ACSR0 */

#define CSL_MLBDIM_CFG_ACSR0_CHS_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_ACSR0_CHS_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_ACSR0_CHS_MAX                                           (0xFFFFFFFFU)

/* ACSR1 */

#define CSL_MLBDIM_CFG_ACSR1_CHS_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_ACSR1_CHS_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_ACSR1_CHS_MAX                                           (0xFFFFFFFFU)

/* ACMR0 */

#define CSL_MLBDIM_CFG_ACMR0_CHM_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_ACMR0_CHM_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_ACMR0_CHM_MAX                                           (0xFFFFFFFFU)

/* ACMR1 */

#define CSL_MLBDIM_CFG_ACMR1_CHM_MASK                                          (0xFFFFFFFFU)
#define CSL_MLBDIM_CFG_ACMR1_CHM_SHIFT                                         (0x00000000U)
#define CSL_MLBDIM_CFG_ACMR1_CHM_MAX                                           (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
