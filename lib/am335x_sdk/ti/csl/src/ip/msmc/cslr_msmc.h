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
 *  Name        : cslr_msmc_deltam.h
*/
#ifndef CSLR_MSMC_DELTAM_H_
#define CSLR_MSMC_DELTAM_H_

#ifdef __cplusplus
extern "C"
{
#endif
    //#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_MSMC_DELTAM_CBASS_FW_REGS_BASE                                     (0x00000000U)
#define CSL_MSMC_DELTAM_CBASS_GLB_REGS_BASE                                    (0x00000000U)
#define CSL_MSMC_DELTAM_CFGS0_REGS_BASE                                        (0x0E000000U)
#define CSL_MSMC_DELTAM_CPU0_REGS_BASE                                         (0x00000000U)
#define CSL_MSMC_DELTAM_CPU10_REGS_BASE                                        (0x0A000000U)
#define CSL_MSMC_DELTAM_CPU11_REGS_BASE                                        (0x0B000000U)
#define CSL_MSMC_DELTAM_CPU12_REGS_BASE                                        (0x0C000000U)
#define CSL_MSMC_DELTAM_CPU1_REGS_BASE                                         (0x01000000U)
#define CSL_MSMC_DELTAM_CPU2_REGS_BASE                                         (0x02000000U)
#define CSL_MSMC_DELTAM_CPU3_REGS_BASE                                         (0x03000000U)
#define CSL_MSMC_DELTAM_CPU4_REGS_BASE                                         (0x04000000U)
#define CSL_MSMC_DELTAM_CPU5_REGS_BASE                                         (0x05000000U)
#define CSL_MSMC_DELTAM_CPU6_REGS_BASE                                         (0x06000000U)
#define CSL_MSMC_DELTAM_CPU7_REGS_BASE                                         (0x07000000U)
#define CSL_MSMC_DELTAM_CPU8_REGS_BASE                                         (0x08000000U)
#define CSL_MSMC_DELTAM_CPU9_REGS_BASE                                         (0x09000000U)
#define CSL_MSMC_DELTAM_DRU_REGS_BASE                                          (0x0D000000U)
#define CSL_MSMC_DELTAM_EMIF_32BIT_REGS_BASE                                   (0x00000000U)
#define CSL_MSMC_DELTAM_EMIF_REGS_BASE                                         (0x00000000U)
#define CSL_MSMC_DELTAM_FW_MAIN_FW_REGS_BASE                                   (0x00000000U)
#define CSL_MSMC_DELTAM_FW_MAIN_GLB_REGS_BASE                                  (0x00000000U)
#define CSL_MSMC_SRAM_REGS_BASE                                         (0x10000000U)
#define CSL_MSMC_UNALLOCATED0_REGS_BASE                                 (0x0F000000U)
#define CSL_MSMC_UNALLOCATED1_REGS_BASE                                 (0x14000000U)
#define CSL_MSMC_UNALLOCATED2_REGS_BASE                                 (0x18000000U)


/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint64_t PID;                       /* Peripheral ID Register */
    volatile uint8_t  Resv_4096[4088];
    volatile uint64_t CACHE_CTRL;                /* Cache Control Register */
    volatile uint64_t CACHE_STAT;                /* Cache Status Register */
    volatile uint64_t RT_WAY_SELECT;             /* Real Time Way Select */
    volatile uint64_t NRT_WAY_SELECT;            /* Non Real Time Way Select */
    volatile uint8_t  Resv_8264[4136];
    volatile uint64_t COHCTRL;                   /* Coherence Control Register */
    volatile uint8_t  Resv_12416[4144];
    volatile uint64_t SMEDCC;                    /* Scrub Rate Register */
    volatile uint8_t  Resv_20480[8056];
    volatile uint64_t SMESTAT;                   /* Interrupt Enabled Status register. ANDed value of SMIRSTAT and SMIESTAT */
    union {
        volatile uint64_t SMIRWS;                    /* set interrupt raw status register */
        volatile uint64_t SMIRSTAT;                  /* Interrupt raw status register */
    } u0;
    volatile uint64_t SMIRC;                     /* Interrupt clear register */
    union {
        volatile uint64_t SMIEWS;                    /* set interrupt raw status register */
        volatile uint64_t SMIESTAT;                  /* Interrupt raw status register */
    } u1;
    volatile uint64_t SMIEC;                     /* Interrupt clear register */
    volatile uint8_t  Resv_24576[4056];
    volatile uint64_t SBNDCOH0;                  /* Starvation Bound for Coherent Port 0 */
    volatile uint64_t SBNDCOH1;                  /* Starvation Bound for Coherent Port 1 */
    volatile uint64_t SBNDCOH2;                  /* Starvation Bound for Coherent Port 2 */
    volatile uint64_t SBNDCOH3;                  /* Starvation Bound for Coherent Port 3 */
    volatile uint64_t SBNDCOH4;                  /* Starvation Bound for Coherent Port 4 */
    volatile uint64_t SBNDCOH5;                  /* Starvation Bound for Coherent Port 5 */
    volatile uint64_t SBNDCOH6;                  /* Starvation Bound for Coherent Port 6 */
    volatile uint64_t SBNDCOH7;                  /* Starvation Bound for Coherent Port 7 */
    volatile uint64_t SBNDCOH8;                  /* Starvation Bound for Coherent Port 8 */
    volatile uint64_t SBNDCOH9;                  /* Starvation Bound for Coherent Port 9 */
    volatile uint64_t SBNDCOH10;                 /* Starvation Bound for Coherent Port 10 */
    volatile uint64_t SBNDCOH11;                 /* Starvation Bound for Coherent Port 11 */
    volatile uint64_t SBNDCOH12;                 /* Starvation Bound for Coherent Port 12 */
    volatile uint8_t  Resv_24832[152];
    volatile uint64_t SBNDDRU;                   /* Starvation Bound for Data Routing Unit */
    volatile uint8_t  Resv_25088[248];
    volatile uint64_t SBNDRESP;                  /* Starvation Bound for Read Response */
    volatile uint8_t  Resv_28672[3576];
    volatile uint64_t DBGTAGCTL;                 /* Debug Tag View Control */
    volatile uint8_t  Resv_28800[120];
    volatile uint64_t DBGTAGVIEW;                /* Debug Tag View Read */
    volatile uint8_t  Resv_40960[12152];
    volatile uint64_t NULL_SLV_STAT0;            /* Null Slave Status 0 */
    volatile uint64_t NULL_SLV_STAT1;            /* Null Slave Status 1 */
    volatile uint8_t  Resv_40984[8];
    volatile uint64_t NULL_SLV_CNT;              /* Null Slave Error Count */
} CSL_msmc_cfgs0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSMC_CFGS0_PID                                              (0x00000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL                                       (0x00001000U)
#define CSL_MSMC_CFGS0_CACHE_STAT                                       (0x00001008U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT                                    (0x00001010U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT                                   (0x00001018U)
#define CSL_MSMC_CFGS0_COHCTRL                                          (0x00002048U)
#define CSL_MSMC_CFGS0_SMEDCC                                           (0x00003080U)
#define CSL_MSMC_CFGS0_SMESTAT                                          (0x00005000U)
#define CSL_MSMC_CFGS0_SMIRWS                                           (0x00005008U)
#define CSL_MSMC_CFGS0_SMIRSTAT                                         (0x00005008U)
#define CSL_MSMC_CFGS0_SMIRC                                            (0x00005010U)
#define CSL_MSMC_CFGS0_SMIEWS                                           (0x00005018U)
#define CSL_MSMC_CFGS0_SMIESTAT                                         (0x00005018U)
#define CSL_MSMC_CFGS0_SMIEC                                            (0x00005020U)
#define CSL_MSMC_CFGS0_SBNDCOH0                                         (0x00006000U)
#define CSL_MSMC_CFGS0_SBNDCOH1                                         (0x00006008U)
#define CSL_MSMC_CFGS0_SBNDCOH2                                         (0x00006010U)
#define CSL_MSMC_CFGS0_SBNDCOH3                                         (0x00006018U)
#define CSL_MSMC_CFGS0_SBNDCOH4                                         (0x00006020U)
#define CSL_MSMC_CFGS0_SBNDCOH5                                         (0x00006028U)
#define CSL_MSMC_CFGS0_SBNDCOH6                                         (0x00006030U)
#define CSL_MSMC_CFGS0_SBNDCOH7                                         (0x00006038U)
#define CSL_MSMC_CFGS0_SBNDCOH8                                         (0x00006040U)
#define CSL_MSMC_CFGS0_SBNDCOH9                                         (0x00006048U)
#define CSL_MSMC_CFGS0_SBNDCOH10                                        (0x00006050U)
#define CSL_MSMC_CFGS0_SBNDCOH11                                        (0x00006058U)
#define CSL_MSMC_CFGS0_SBNDCOH12                                        (0x00006060U)
#define CSL_MSMC_CFGS0_SBNDDRU                                          (0x00006100U)
#define CSL_MSMC_CFGS0_SBNDRESP                                         (0x00006200U)
#define CSL_MSMC_CFGS0_DBGTAGCTL                                        (0x00007000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW                                       (0x00007080U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT0                                   (0x0000A000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1                                   (0x0000A008U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT                                     (0x0000A018U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_MSMC_CFGS0_PID_REVISION_MASK                                (0x00000000FFFFFFFFU)
#define CSL_MSMC_CFGS0_PID_REVISION_SHIFT                               (0x0000000000000000U)
#define CSL_MSMC_CFGS0_PID_REVISION_RESETVAL                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_PID_REVISION_MAX                                 (0x00000000FFFFFFFFU)

#define CSL_MSMC_CFGS0_PID_RSVD_MASK                                    (0xFFFFFFFF00000000U)
#define CSL_MSMC_CFGS0_PID_RSVD_SHIFT                                   (0x0000000000000020U)
#define CSL_MSMC_CFGS0_PID_RSVD_RESETVAL                                (0x0000000000000000U)
#define CSL_MSMC_CFGS0_PID_RSVD_MAX                                     (0x00000000FFFFFFFFU)

#define CSL_MSMC_CFGS0_PID_RESETVAL                                     (0x0000000000000000U)

/* CACHE_CTRL */

#define CSL_MSMC_CFGS0_CACHE_CTRL_CACHE_SIZE_MASK                       (0x000000000000000FU)
#define CSL_MSMC_CFGS0_CACHE_CTRL_CACHE_SIZE_SHIFT                      (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_CACHE_SIZE_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_CACHE_SIZE_MAX                        (0x000000000000000FU)

#define CSL_MSMC_CFGS0_CACHE_CTRL_REPLACEMENT_POLICY_MASK               (0x0000000000000100U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_REPLACEMENT_POLICY_SHIFT              (0x0000000000000008U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_REPLACEMENT_POLICY_RESETVAL           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_REPLACEMENT_POLICY_MAX                (0x0000000000000001U)

#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD0_MASK                            (0x00000000000000E0U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD0_SHIFT                           (0x0000000000000005U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD0_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD0_MAX                             (0x0000000000000007U)

#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD1_MASK                            (0xFFFFFFFFFFFFFE00U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD1_SHIFT                           (0x0000000000000009U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD1_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_RSVD1_MAX                             (0x007FFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_CACHE_CTRL_SZ_TRANSITION_MASK                    (0x0000000000000010U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_SZ_TRANSITION_SHIFT                   (0x0000000000000004U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_SZ_TRANSITION_RESETVAL                (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_CTRL_SZ_TRANSITION_MAX                     (0x0000000000000001U)

#define CSL_MSMC_CFGS0_CACHE_CTRL_RESETVAL                              (0x0000000000000000U)

/* CACHE_STAT */

#define CSL_MSMC_CFGS0_CACHE_STAT_RSVD_MASK                             (0xFFFFFFFFFFFFFFFFU)
#define CSL_MSMC_CFGS0_CACHE_STAT_RSVD_SHIFT                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_STAT_RSVD_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_CACHE_STAT_RSVD_MAX                              (0xFFFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_CACHE_STAT_RESETVAL                              (0x0000000000000000U)

/* RT_WAY_SELECT */

#define CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_MASK                      (0x0000000000000003U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_SHIFT                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_RESETVAL                  (0x0000000000000003U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_MAX                       (0x0000000000000003U)

#define CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_MASK                       (0x0000000000000060U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_SHIFT                      (0x0000000000000005U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_MAX                        (0x0000000000000003U)

#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD0_MASK                         (0x000000000000001CU)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD0_SHIFT                        (0x0000000000000002U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD0_RESETVAL                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD0_MAX                          (0x0000000000000007U)

#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD1_MASK                         (0xFFFFFFFFFFFFFF80U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD1_SHIFT                        (0x0000000000000007U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD1_RESETVAL                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RSVD1_MAX                          (0x01FFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_RT_WAY_SELECT_RESETVAL                           (0x0000000000000003U)

/* NRT_WAY_SELECT */

#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_MASK                     (0x0000000000000003U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_SHIFT                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_RESETVAL                 (0x0000000000000003U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_MAX                      (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_MASK                      (0x0000000000000060U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_SHIFT                     (0x0000000000000005U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_RESETVAL                  (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_MAX                       (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD0_MASK                        (0x000000000000001CU)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD0_SHIFT                       (0x0000000000000002U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD0_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD0_MAX                         (0x0000000000000007U)

#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD1_MASK                        (0xFFFFFFFFFFFFFF80U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD1_SHIFT                       (0x0000000000000007U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD1_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RSVD1_MAX                         (0x01FFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_NRT_WAY_SELECT_RESETVAL                          (0x0000000000000003U)

/* COHCTRL */

#define CSL_MSMC_CFGS0_COHCTRL_BCM_MASK                                 (0x0000000000000001U)
#define CSL_MSMC_CFGS0_COHCTRL_BCM_SHIFT                                (0x0000000000000000U)
#define CSL_MSMC_CFGS0_COHCTRL_BCM_RESETVAL                             (0x0000000000000000U)
#define CSL_MSMC_CFGS0_COHCTRL_BCM_MAX                                  (0x0000000000000001U)

#define CSL_MSMC_CFGS0_COHCTRL_RSVD0_MASK                               (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_COHCTRL_RSVD0_SHIFT                              (0x0000000000000001U)
#define CSL_MSMC_CFGS0_COHCTRL_RSVD0_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_COHCTRL_RSVD0_MAX                                (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_COHCTRL_RESETVAL                                 (0x0000000000000000U)

/* SMEDCC */

#define CSL_MSMC_CFGS0_SMEDCC_REFDEL_MASK                               (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SMEDCC_REFDEL_SHIFT                              (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMEDCC_REFDEL_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMEDCC_REFDEL_MAX                                (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SMEDCC_RSVD0_MASK                                (0x000000007FFFFF00U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD0_SHIFT                               (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD0_RESETVAL                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD0_MAX                                 (0x00000000007FFFFFU)

#define CSL_MSMC_CFGS0_SMEDCC_RSVD1_MASK                                (0xFFFFFFFF00000000U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD1_SHIFT                               (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD1_RESETVAL                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMEDCC_RSVD1_MAX                                 (0x00000000FFFFFFFFU)

#define CSL_MSMC_CFGS0_SMEDCC_SEN_MASK                                  (0x0000000080000000U)
#define CSL_MSMC_CFGS0_SMEDCC_SEN_SHIFT                                 (0x000000000000001FU)
#define CSL_MSMC_CFGS0_SMEDCC_SEN_RESETVAL                              (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMEDCC_SEN_MAX                                   (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMEDCC_RESETVAL                                  (0x0000000080000000U)

/* SMESTAT */

#define CSL_MSMC_CFGS0_SMESTAT_NULL_SLV_MASK                            (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMESTAT_NULL_SLV_SHIFT                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMESTAT_NULL_SLV_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMESTAT_NULL_SLV_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMESTAT_RSVD0_MASK                               (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMESTAT_RSVD0_SHIFT                              (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMESTAT_RSVD0_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMESTAT_RSVD0_MAX                                (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMESTAT_RESETVAL                                 (0x0000000000000000U)

/* SMIRWS */

#define CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_MASK                             (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_SHIFT                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_MAX                              (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIRWS_RSVD0_MASK                                (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIRWS_RSVD0_SHIFT                               (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRWS_RSVD0_RESETVAL                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRWS_RSVD0_MAX                                 (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIRWS_RESETVAL                                  (0x0000000000000000U)

/* SMIRSTAT */

#define CSL_MSMC_CFGS0_SMIRSTAT_NULL_SLV_MASK                           (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRSTAT_NULL_SLV_SHIFT                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRSTAT_NULL_SLV_RESETVAL                       (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRSTAT_NULL_SLV_MAX                            (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIRSTAT_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIRSTAT_RSVD0_SHIFT                             (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRSTAT_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRSTAT_RSVD0_MAX                               (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIRSTAT_RESETVAL                                (0x0000000000000000U)

/* SMIRC */

#define CSL_MSMC_CFGS0_SMIRC_NULL_SLV_MASK                              (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRC_NULL_SLV_SHIFT                             (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRC_NULL_SLV_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRC_NULL_SLV_MAX                               (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIRC_RSVD0_MASK                                 (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIRC_RSVD0_SHIFT                                (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIRC_RSVD0_RESETVAL                             (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIRC_RSVD0_MAX                                  (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIRC_RESETVAL                                   (0x0000000000000000U)

/* SMIEWS */

#define CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_MASK                             (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_SHIFT                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_MAX                              (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIEWS_RSVD0_MASK                                (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIEWS_RSVD0_SHIFT                               (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIEWS_RSVD0_RESETVAL                            (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEWS_RSVD0_MAX                                 (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIEWS_RESETVAL                                  (0x0000000000000000U)

/* SMIESTAT */

#define CSL_MSMC_CFGS0_SMIESTAT_NULL_SLV_MASK                           (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIESTAT_NULL_SLV_SHIFT                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIESTAT_NULL_SLV_RESETVAL                       (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIESTAT_NULL_SLV_MAX                            (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIESTAT_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIESTAT_RSVD0_SHIFT                             (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIESTAT_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIESTAT_RSVD0_MAX                               (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIESTAT_RESETVAL                                (0x0000000000000000U)

/* SMIEC */

#define CSL_MSMC_CFGS0_SMIEC_NULL_SLV_MASK                              (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIEC_NULL_SLV_SHIFT                             (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEC_NULL_SLV_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEC_NULL_SLV_MAX                               (0x0000000000000001U)

#define CSL_MSMC_CFGS0_SMIEC_RSVD0_MASK                                 (0xFFFFFFFFFFFFFFFEU)
#define CSL_MSMC_CFGS0_SMIEC_RSVD0_SHIFT                                (0x0000000000000001U)
#define CSL_MSMC_CFGS0_SMIEC_RSVD0_RESETVAL                             (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SMIEC_RSVD0_MAX                                  (0x7FFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_SMIEC_RESETVAL                                   (0x0000000000000000U)

/* SBNDCOH0 */

#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH0_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH1 */

#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH1_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH2 */

#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH2_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH3 */

#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH3_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH4 */

#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH4_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH5 */

#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH5_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH6 */

#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH6_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH7 */

#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH7_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH7_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH8 */

#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH8_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH9 */

#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH9_RESETVAL                                (0x003F003F003F003FU)

/* SBNDCOH10 */

#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD0_MASK                             (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD0_SHIFT                            (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD0_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD0_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD1_MASK                             (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD1_SHIFT                            (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD1_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD1_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD2_MASK                             (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD2_SHIFT                            (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD2_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD2_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD3_MASK                             (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD3_SHIFT                            (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD3_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_RSVD3_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_MASK                         (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_SHIFT                        (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_MASK                          (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_SHIFT                         (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_MASK                         (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_SHIFT                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_MASK                          (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_SHIFT                         (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH10_RESETVAL                               (0x003F003F003F003FU)

/* SBNDCOH11 */

#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD0_MASK                             (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD0_SHIFT                            (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD0_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD0_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD1_MASK                             (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD1_SHIFT                            (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD1_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD1_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD2_MASK                             (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD2_SHIFT                            (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD2_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD2_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD3_MASK                             (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD3_SHIFT                            (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD3_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_RSVD3_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_MASK                         (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_SHIFT                        (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_MASK                          (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_SHIFT                         (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_MASK                         (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_SHIFT                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_MASK                          (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_SHIFT                         (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH11_RESETVAL                               (0x003F003F003F003FU)

/* SBNDCOH12 */

#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD0_MASK                             (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD0_SHIFT                            (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD0_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD0_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD1_MASK                             (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD1_SHIFT                            (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD1_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD1_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD2_MASK                             (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD2_SHIFT                            (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD2_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD2_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD3_MASK                             (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD3_SHIFT                            (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD3_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_RSVD3_MAX                              (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_MASK                         (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_SHIFT                        (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_MASK                          (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_SHIFT                         (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_MASK                         (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_SHIFT                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_RESETVAL                     (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_MAX                          (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_MASK                          (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_SHIFT                         (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDCOH12_RESETVAL                               (0x003F003F003F003FU)

/* SBNDDRU */

#define CSL_MSMC_CFGS0_SBNDDRU_RSVD0_MASK                               (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD0_SHIFT                              (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD0_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD0_MAX                                (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_RSVD1_MASK                               (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD1_SHIFT                              (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD1_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD1_MAX                                (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_RSVD2_MASK                               (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD2_SHIFT                              (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD2_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD2_MAX                                (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_RSVD3_MASK                               (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD3_SHIFT                              (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD3_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_RSVD3_MAX                                (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_MASK                           (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_SHIFT                          (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_MASK                            (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_SHIFT                           (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_RESETVAL                        (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_MAX                             (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_MASK                           (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_SHIFT                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_MASK                            (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_SHIFT                           (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_RESETVAL                        (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_MAX                             (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDDRU_RESETVAL                                 (0x003F003F003F003FU)

/* SBNDRESP */

#define CSL_MSMC_CFGS0_SBNDRESP_RSVD0_MASK                              (0x000000000000FF00U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD0_SHIFT                             (0x0000000000000008U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD0_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD0_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_RSVD1_MASK                              (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD1_SHIFT                             (0x0000000000000018U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD1_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD1_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_RSVD2_MASK                              (0x0000FF0000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD2_SHIFT                             (0x0000000000000028U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD2_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD2_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_RSVD3_MASK                              (0xFF00000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD3_SHIFT                             (0x0000000000000038U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD3_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_RSVD3_MAX                               (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_NRT_MASK                          (0x0000000000FF0000U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_NRT_SHIFT                         (0x0000000000000010U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_RT_MASK                           (0x00FF000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_RT_SHIFT                          (0x0000000000000030U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDE_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_NRT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_NRT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_NRT_RESETVAL                      (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_NRT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_RT_MASK                           (0x000000FF00000000U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_RT_SHIFT                          (0x0000000000000020U)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_RT_RESETVAL                       (0x000000000000003FU)
#define CSL_MSMC_CFGS0_SBNDRESP_SBNDM_RT_MAX                            (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_SBNDRESP_RESETVAL                                (0x003F003F003F003FU)

/* DBGTAGCTL */

#define CSL_MSMC_CFGS0_DBGTAGCTL_BANK_MASK                              (0x0000000300000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_BANK_SHIFT                             (0x0000000000000020U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_BANK_RESETVAL                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_BANK_MAX                               (0x0000000000000003U)

#define CSL_MSMC_CFGS0_DBGTAGCTL_INDEX_MASK                             (0x000000003FFF0000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_INDEX_SHIFT                            (0x0000000000000010U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_INDEX_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_INDEX_MAX                              (0x0000000000003FFFU)

#define CSL_MSMC_CFGS0_DBGTAGCTL_L3CACHE_MASK                           (0x0000010000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_L3CACHE_SHIFT                          (0x0000000000000028U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_L3CACHE_RESETVAL                       (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_L3CACHE_MAX                            (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD0_MASK                             (0x000000000000FFE0U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD0_SHIFT                            (0x0000000000000005U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD0_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD0_MAX                              (0x00000000000007FFU)

#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD1_MASK                             (0x00000000C0000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD1_SHIFT                            (0x000000000000001EU)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD1_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD1_MAX                              (0x0000000000000003U)

#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD2_MASK                             (0x000000FC00000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD2_SHIFT                            (0x0000000000000022U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD2_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD2_MAX                              (0x000000000000003FU)

#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD3_MASK                             (0xFFFFFE0000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD3_SHIFT                            (0x0000000000000029U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD3_RESETVAL                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_RSVD3_MAX                              (0x00000000007FFFFFU)

#define CSL_MSMC_CFGS0_DBGTAGCTL_WAY_MASK                               (0x000000000000001FU)
#define CSL_MSMC_CFGS0_DBGTAGCTL_WAY_SHIFT                              (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_WAY_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGCTL_WAY_MAX                                (0x000000000000001FU)

#define CSL_MSMC_CFGS0_DBGTAGCTL_RESETVAL                               (0x0000000000000000U)

/* DBGTAGVIEW */

#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDR_VALID_MASK                       (0x0001000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDR_VALID_SHIFT                      (0x0000000000000030U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDR_VALID_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDR_VALID_MAX                        (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDRESS_MASK                          (0x0000FFFFFFFFFFFCU)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDRESS_SHIFT                         (0x0000000000000002U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDRESS_RESETVAL                      (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_ADDRESS_MAX                           (0x00003FFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_DATA_VALID_MASK                       (0x0004000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DATA_VALID_SHIFT                      (0x0000000000000032U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DATA_VALID_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DATA_VALID_MAX                        (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_DIRTY_MASK                            (0x0010000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DIRTY_SHIFT                           (0x0000000000000034U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DIRTY_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_DIRTY_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD0_MASK                            (0x0000000000000002U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD0_SHIFT                           (0x0000000000000001U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD0_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD0_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD1_MASK                            (0x0002000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD1_SHIFT                           (0x0000000000000031U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD1_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD1_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD2_MASK                            (0x0008000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD2_SHIFT                           (0x0000000000000033U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD2_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD2_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD3_MASK                            (0x0020000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD3_SHIFT                           (0x0000000000000035U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD3_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD3_MAX                             (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD4_MASK                            (0xF800000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD4_SHIFT                           (0x000000000000003BU)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD4_RESETVAL                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_RSVD4_MAX                             (0x000000000000001FU)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_SECURE_MASK                           (0x0000000000000001U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SECURE_SHIFT                          (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SECURE_RESETVAL                       (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SECURE_MAX                            (0x0000000000000001U)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_SF_MASK                               (0x07C0000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SF_SHIFT                              (0x0000000000000036U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SF_RESETVAL                           (0x0000000000000000U)
#define CSL_MSMC_CFGS0_DBGTAGVIEW_SF_MAX                                (0x000000000000001FU)

#define CSL_MSMC_CFGS0_DBGTAGVIEW_RESETVAL                              (0x0000000000000000U)

/* NULL_SLV_STAT0 */

#define CSL_MSMC_CFGS0_NULL_SLV_STAT0_ADDR_MASK                         (0xFFFFFFFFFFFFFFFFU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT0_ADDR_SHIFT                        (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT0_ADDR_RESETVAL                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT0_ADDR_MAX                          (0xFFFFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT0_RESETVAL                          (0x0000000000000000U)

/* NULL_SLV_STAT1 */

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_BYTECNT_MASK                      (0x00000000000003FFU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_BYTECNT_SHIFT                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_BYTECNT_RESETVAL                  (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_BYTECNT_MAX                       (0x00000000000003FFU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_EMU_MASK                          (0x0000100000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_EMU_SHIFT                         (0x000000000000002CU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_EMU_RESETVAL                      (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_EMU_MAX                           (0x0000000000000001U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_MEMTYPE_MASK                      (0x0000030000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_MEMTYPE_SHIFT                     (0x0000000000000028U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_MEMTYPE_RESETVAL                  (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_MEMTYPE_MAX                       (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_OPCODE_MASK                       (0x0000003F00000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_OPCODE_SHIFT                      (0x0000000000000020U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_OPCODE_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_OPCODE_MAX                        (0x000000000000003FU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIV_MASK                         (0x0030000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIV_SHIFT                        (0x0000000000000034U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIV_RESETVAL                     (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIV_MAX                          (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIVID_MASK                       (0x00000000FF000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIVID_SHIFT                      (0x0000000000000018U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIVID_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_PRIVID_MAX                        (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_ROUTEID_MASK                      (0x0000000000FFF000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_ROUTEID_SHIFT                     (0x000000000000000CU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_ROUTEID_RESETVAL                  (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_ROUTEID_MAX                       (0x0000000000000FFFU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD0_MASK                        (0x0000000000000C00U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD0_SHIFT                       (0x000000000000000AU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD0_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD0_MAX                         (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD1_MASK                        (0x000000C000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD1_SHIFT                       (0x0000000000000026U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD1_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD1_MAX                         (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD2_MASK                        (0x00000C0000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD2_SHIFT                       (0x000000000000002AU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD2_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD2_MAX                         (0x0000000000000003U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD3_MASK                        (0x0000E00000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD3_SHIFT                       (0x000000000000002DU)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD3_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD3_MAX                         (0x0000000000000007U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD4_MASK                        (0x000E000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD4_SHIFT                       (0x0000000000000031U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD4_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD4_MAX                         (0x0000000000000007U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD5_MASK                        (0xFFC0000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD5_SHIFT                       (0x0000000000000036U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD5_RESETVAL                    (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RSVD5_MAX                         (0x00000000000003FFU)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_SECURE_MASK                       (0x0001000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_SECURE_SHIFT                      (0x0000000000000030U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_SECURE_RESETVAL                   (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_SECURE_MAX                        (0x0000000000000001U)

#define CSL_MSMC_CFGS0_NULL_SLV_STAT1_RESETVAL                          (0x0000000000000000U)

/* NULL_SLV_CNT */

#define CSL_MSMC_CFGS0_NULL_SLV_CNT_COUNT_MASK                          (0x00000000000000FFU)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_COUNT_SHIFT                         (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_COUNT_RESETVAL                      (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_COUNT_MAX                           (0x00000000000000FFU)

#define CSL_MSMC_CFGS0_NULL_SLV_CNT_RSVD0_MASK                          (0xFFFFFFFFFFFFFF00U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_RSVD0_SHIFT                         (0x0000000000000008U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_RSVD0_RESETVAL                      (0x0000000000000000U)
#define CSL_MSMC_CFGS0_NULL_SLV_CNT_RSVD0_MAX                           (0x00FFFFFFFFFFFFFFU)

#define CSL_MSMC_CFGS0_NULL_SLV_CNT_RESETVAL                            (0x0000000000000000U)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t IMPLEMENTED_RAM[524288];   /*  MSMC SRAM  */
} CSL_msmc_deltam_sramRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSMC_SRAM_IMPLEMENTED_RAM(IMPLEMENTED_RAM)                  (0x00000000U+((IMPLEMENTED_RAM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* IMPLEMENTED_RAM */

#define CSL_MSMC_SRAM_IMPLEMENTED_RAM_RESETVAL                          (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
