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
 *  Name        : cslr_flexray.h
*/
#ifndef CSLR_FLEXRAY_H_
#define CSLR_FLEXRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_FLEXRAY_CFG_REGS_BASE                                              (0x00000000U)
#define CSL_FLEXRAY_ECC_AGGR_REGS_BASE                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_REGS_BASE                                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_REGS_BASE                                          (0x00000000U)
#define CSL_FLEXRAY_RAM_REGS_BASE                                              (0x00000000U)
#define CSL_FLEXRAY_RAT_REGS_BASE                                              (0x00000000U)


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
    volatile uint32_t ICS;                       /* Interrupt Clear Shadow Register */
    volatile uint32_t IRS;                       /* Interrupt Raw Status Register */
    volatile uint32_t IECS;                      /* Interrupt Enable Clear Shadow Register */
    volatile uint32_t IE;                        /* Interrupt Enable Register */
    volatile uint32_t IES;                       /* Interrupt Enable Status */
    volatile uint32_t EOI;                       /* End Of Interrupt */
} CSL_flexray_cfgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FLEXRAY_CFG_PID                                                    (0x00000000U)
#define CSL_FLEXRAY_CFG_CTRL                                                   (0x00000004U)
#define CSL_FLEXRAY_CFG_STAT                                                   (0x00000008U)
#define CSL_FLEXRAY_CFG_ICS                                                    (0x0000000CU)
#define CSL_FLEXRAY_CFG_IRS                                                    (0x00000010U)
#define CSL_FLEXRAY_CFG_IECS                                                   (0x00000014U)
#define CSL_FLEXRAY_CFG_IE                                                     (0x00000018U)
#define CSL_FLEXRAY_CFG_IES                                                    (0x0000001CU)
#define CSL_FLEXRAY_CFG_EOI                                                    (0x00000020U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_FLEXRAY_CFG_PID_MINOR_MASK                                         (0x0000003FU)
#define CSL_FLEXRAY_CFG_PID_MINOR_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_CFG_PID_MINOR_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_CFG_PID_MINOR_MAX                                          (0x0000003FU)

#define CSL_FLEXRAY_CFG_PID_CUSTOM_MASK                                        (0x000000C0U)
#define CSL_FLEXRAY_CFG_PID_CUSTOM_SHIFT                                       (0x00000006U)
#define CSL_FLEXRAY_CFG_PID_CUSTOM_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_CFG_PID_CUSTOM_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_CFG_PID_MAJOR_MASK                                         (0x00000700U)
#define CSL_FLEXRAY_CFG_PID_MAJOR_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_CFG_PID_MAJOR_RESETVAL                                     (0x00000001U)
#define CSL_FLEXRAY_CFG_PID_MAJOR_MAX                                          (0x00000007U)

#define CSL_FLEXRAY_CFG_PID_RTL_MASK                                           (0x0000F800U)
#define CSL_FLEXRAY_CFG_PID_RTL_SHIFT                                          (0x0000000BU)
#define CSL_FLEXRAY_CFG_PID_RTL_RESETVAL                                       (0x00000002U)
#define CSL_FLEXRAY_CFG_PID_RTL_MAX                                            (0x0000001FU)

#define CSL_FLEXRAY_CFG_PID_MODULE_ID_MASK                                     (0x0FFF0000U)
#define CSL_FLEXRAY_CFG_PID_MODULE_ID_SHIFT                                    (0x00000010U)
#define CSL_FLEXRAY_CFG_PID_MODULE_ID_RESETVAL                                 (0x000008B0U)
#define CSL_FLEXRAY_CFG_PID_MODULE_ID_MAX                                      (0x00000FFFU)

#define CSL_FLEXRAY_CFG_PID_BU_MASK                                            (0x30000000U)
#define CSL_FLEXRAY_CFG_PID_BU_SHIFT                                           (0x0000001CU)
#define CSL_FLEXRAY_CFG_PID_BU_RESETVAL                                        (0x00000002U)
#define CSL_FLEXRAY_CFG_PID_BU_MAX                                             (0x00000003U)

#define CSL_FLEXRAY_CFG_PID_SCHEME_MASK                                        (0xC0000000U)
#define CSL_FLEXRAY_CFG_PID_SCHEME_SHIFT                                       (0x0000001EU)
#define CSL_FLEXRAY_CFG_PID_SCHEME_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_CFG_PID_SCHEME_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_CFG_PID_RESETVAL                                           (0x68B01100U)

/* CTRL */

#define CSL_FLEXRAY_CFG_CTRL_SYS_ODD_PARITY_MASK                               (0x00000001U)
#define CSL_FLEXRAY_CFG_CTRL_SYS_ODD_PARITY_SHIFT                              (0x00000000U)
#define CSL_FLEXRAY_CFG_CTRL_SYS_ODD_PARITY_RESETVAL                           (0x00000000U)
#define CSL_FLEXRAY_CFG_CTRL_SYS_ODD_PARITY_MAX                                (0x00000001U)

#define CSL_FLEXRAY_CFG_CTRL_RESETVAL                                          (0x00000000U)

/* STAT */

#define CSL_FLEXRAY_CFG_STAT_MEM_INIT_DONE_MASK                                (0x00000001U)
#define CSL_FLEXRAY_CFG_STAT_MEM_INIT_DONE_SHIFT                               (0x00000000U)
#define CSL_FLEXRAY_CFG_STAT_MEM_INIT_DONE_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_STAT_MEM_INIT_DONE_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_STAT_RESETVAL                                          (0x00000000U)

/* ICS */

#define CSL_FLEXRAY_CFG_ICS_TBF1_PRTY_ERR_MASK                                 (0x00000001U)
#define CSL_FLEXRAY_CFG_ICS_TBF1_PRTY_ERR_SHIFT                                (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_TBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_TBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_OBF1_PRTY_ERR_MASK                                 (0x00000002U)
#define CSL_FLEXRAY_CFG_ICS_OBF1_PRTY_ERR_SHIFT                                (0x00000001U)
#define CSL_FLEXRAY_CFG_ICS_OBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_OBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_FTURAM_PRTY_ERR_MASK                               (0x00000004U)
#define CSL_FLEXRAY_CFG_ICS_FTURAM_PRTY_ERR_SHIFT                              (0x00000002U)
#define CSL_FLEXRAY_CFG_ICS_FTURAM_PRTY_ERR_RESETVAL                           (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_FTURAM_PRTY_ERR_MAX                                (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_MBF_PRTY_ERR_MASK                                  (0x00000008U)
#define CSL_FLEXRAY_CFG_ICS_MBF_PRTY_ERR_SHIFT                                 (0x00000003U)
#define CSL_FLEXRAY_CFG_ICS_MBF_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_MBF_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_TBF2_PRTY_ERR_MASK                                 (0x00000010U)
#define CSL_FLEXRAY_CFG_ICS_TBF2_PRTY_ERR_SHIFT                                (0x00000004U)
#define CSL_FLEXRAY_CFG_ICS_TBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_TBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_IBF2_PRTY_ERR_MASK                                 (0x00000020U)
#define CSL_FLEXRAY_CFG_ICS_IBF2_PRTY_ERR_SHIFT                                (0x00000005U)
#define CSL_FLEXRAY_CFG_ICS_IBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_IBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_IBF1_PRTY_ERR_MASK                                 (0x00000040U)
#define CSL_FLEXRAY_CFG_ICS_IBF1_PRTY_ERR_SHIFT                                (0x00000006U)
#define CSL_FLEXRAY_CFG_ICS_IBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_IBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_OBF2_PRTY_ERR_MASK                                 (0x00000080U)
#define CSL_FLEXRAY_CFG_ICS_OBF2_PRTY_ERR_SHIFT                                (0x00000007U)
#define CSL_FLEXRAY_CFG_ICS_OBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_ICS_OBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_ICS_RESETVAL                                           (0x00000000U)

/* IRS */

#define CSL_FLEXRAY_CFG_IRS_TBF1_PRTY_ERR_MASK                                 (0x00000001U)
#define CSL_FLEXRAY_CFG_IRS_TBF1_PRTY_ERR_SHIFT                                (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_TBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_TBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_OBF1_PRTY_ERR_MASK                                 (0x00000002U)
#define CSL_FLEXRAY_CFG_IRS_OBF1_PRTY_ERR_SHIFT                                (0x00000001U)
#define CSL_FLEXRAY_CFG_IRS_OBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_OBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_FTURAM_PRTY_ERR_MASK                               (0x00000004U)
#define CSL_FLEXRAY_CFG_IRS_FTURAM_PRTY_ERR_SHIFT                              (0x00000002U)
#define CSL_FLEXRAY_CFG_IRS_FTURAM_PRTY_ERR_RESETVAL                           (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_FTURAM_PRTY_ERR_MAX                                (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_MBF_PRTY_ERR_MASK                                  (0x00000008U)
#define CSL_FLEXRAY_CFG_IRS_MBF_PRTY_ERR_SHIFT                                 (0x00000003U)
#define CSL_FLEXRAY_CFG_IRS_MBF_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_MBF_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_TBF2_PRTY_ERR_MASK                                 (0x00000010U)
#define CSL_FLEXRAY_CFG_IRS_TBF2_PRTY_ERR_SHIFT                                (0x00000004U)
#define CSL_FLEXRAY_CFG_IRS_TBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_TBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_IBF2_PRTY_ERR_MASK                                 (0x00000020U)
#define CSL_FLEXRAY_CFG_IRS_IBF2_PRTY_ERR_SHIFT                                (0x00000005U)
#define CSL_FLEXRAY_CFG_IRS_IBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_IBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_IBF1_PRTY_ERR_MASK                                 (0x00000040U)
#define CSL_FLEXRAY_CFG_IRS_IBF1_PRTY_ERR_SHIFT                                (0x00000006U)
#define CSL_FLEXRAY_CFG_IRS_IBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_IBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_OBF2_PRTY_ERR_MASK                                 (0x00000080U)
#define CSL_FLEXRAY_CFG_IRS_OBF2_PRTY_ERR_SHIFT                                (0x00000007U)
#define CSL_FLEXRAY_CFG_IRS_OBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IRS_OBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IRS_RESETVAL                                           (0x00000000U)

/* IECS */

#define CSL_FLEXRAY_CFG_IECS_TBF1_PRTY_ERR_MASK                                (0x00000001U)
#define CSL_FLEXRAY_CFG_IECS_TBF1_PRTY_ERR_SHIFT                               (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_TBF1_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_TBF1_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_OBF1_PRTY_ERR_MASK                                (0x00000002U)
#define CSL_FLEXRAY_CFG_IECS_OBF1_PRTY_ERR_SHIFT                               (0x00000001U)
#define CSL_FLEXRAY_CFG_IECS_OBF1_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_OBF1_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_FTURAM_PRTY_ERR_MASK                              (0x00000004U)
#define CSL_FLEXRAY_CFG_IECS_FTURAM_PRTY_ERR_SHIFT                             (0x00000002U)
#define CSL_FLEXRAY_CFG_IECS_FTURAM_PRTY_ERR_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_FTURAM_PRTY_ERR_MAX                               (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_MBF_PRTY_ERR_MASK                                 (0x00000008U)
#define CSL_FLEXRAY_CFG_IECS_MBF_PRTY_ERR_SHIFT                                (0x00000003U)
#define CSL_FLEXRAY_CFG_IECS_MBF_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_MBF_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_TBF2_PRTY_ERR_MASK                                (0x00000010U)
#define CSL_FLEXRAY_CFG_IECS_TBF2_PRTY_ERR_SHIFT                               (0x00000004U)
#define CSL_FLEXRAY_CFG_IECS_TBF2_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_TBF2_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_IBF2_PRTY_ERR_MASK                                (0x00000020U)
#define CSL_FLEXRAY_CFG_IECS_IBF2_PRTY_ERR_SHIFT                               (0x00000005U)
#define CSL_FLEXRAY_CFG_IECS_IBF2_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_IBF2_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_IBF1_PRTY_ERR_MASK                                (0x00000040U)
#define CSL_FLEXRAY_CFG_IECS_IBF1_PRTY_ERR_SHIFT                               (0x00000006U)
#define CSL_FLEXRAY_CFG_IECS_IBF1_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_IBF1_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_OBF2_PRTY_ERR_MASK                                (0x00000080U)
#define CSL_FLEXRAY_CFG_IECS_OBF2_PRTY_ERR_SHIFT                               (0x00000007U)
#define CSL_FLEXRAY_CFG_IECS_OBF2_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IECS_OBF2_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IECS_RESETVAL                                          (0x00000000U)

/* IE */

#define CSL_FLEXRAY_CFG_IE_TBF1_PRTY_ERR_MASK                                  (0x00000001U)
#define CSL_FLEXRAY_CFG_IE_TBF1_PRTY_ERR_SHIFT                                 (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_TBF1_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_TBF1_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_OBF1_PRTY_ERR_MASK                                  (0x00000002U)
#define CSL_FLEXRAY_CFG_IE_OBF1_PRTY_ERR_SHIFT                                 (0x00000001U)
#define CSL_FLEXRAY_CFG_IE_OBF1_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_OBF1_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_FTURAM_PRTY_ERR_MASK                                (0x00000004U)
#define CSL_FLEXRAY_CFG_IE_FTURAM_PRTY_ERR_SHIFT                               (0x00000002U)
#define CSL_FLEXRAY_CFG_IE_FTURAM_PRTY_ERR_RESETVAL                            (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_FTURAM_PRTY_ERR_MAX                                 (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_MBF_PRTY_ERR_MASK                                   (0x00000008U)
#define CSL_FLEXRAY_CFG_IE_MBF_PRTY_ERR_SHIFT                                  (0x00000003U)
#define CSL_FLEXRAY_CFG_IE_MBF_PRTY_ERR_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_MBF_PRTY_ERR_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_TBF2_PRTY_ERR_MASK                                  (0x00000010U)
#define CSL_FLEXRAY_CFG_IE_TBF2_PRTY_ERR_SHIFT                                 (0x00000004U)
#define CSL_FLEXRAY_CFG_IE_TBF2_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_TBF2_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_IBF2_PRTY_ERR_MASK                                  (0x00000020U)
#define CSL_FLEXRAY_CFG_IE_IBF2_PRTY_ERR_SHIFT                                 (0x00000005U)
#define CSL_FLEXRAY_CFG_IE_IBF2_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_IBF2_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_IBF1_PRTY_ERR_MASK                                  (0x00000040U)
#define CSL_FLEXRAY_CFG_IE_IBF1_PRTY_ERR_SHIFT                                 (0x00000006U)
#define CSL_FLEXRAY_CFG_IE_IBF1_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_IBF1_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_OBF2_PRTY_ERR_MASK                                  (0x00000080U)
#define CSL_FLEXRAY_CFG_IE_OBF2_PRTY_ERR_SHIFT                                 (0x00000007U)
#define CSL_FLEXRAY_CFG_IE_OBF2_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IE_OBF2_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IE_RESETVAL                                            (0x00000000U)

/* IES */

#define CSL_FLEXRAY_CFG_IES_TBF1_PRTY_ERR_MASK                                 (0x00000001U)
#define CSL_FLEXRAY_CFG_IES_TBF1_PRTY_ERR_SHIFT                                (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_TBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_TBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_OBF1_PRTY_ERR_MASK                                 (0x00000002U)
#define CSL_FLEXRAY_CFG_IES_OBF1_PRTY_ERR_SHIFT                                (0x00000001U)
#define CSL_FLEXRAY_CFG_IES_OBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_OBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_FTURAM_PRTY_ERR_MASK                               (0x00000004U)
#define CSL_FLEXRAY_CFG_IES_FTURAM_PRTY_ERR_SHIFT                              (0x00000002U)
#define CSL_FLEXRAY_CFG_IES_FTURAM_PRTY_ERR_RESETVAL                           (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_FTURAM_PRTY_ERR_MAX                                (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_MBF_PRTY_ERR_MASK                                  (0x00000008U)
#define CSL_FLEXRAY_CFG_IES_MBF_PRTY_ERR_SHIFT                                 (0x00000003U)
#define CSL_FLEXRAY_CFG_IES_MBF_PRTY_ERR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_MBF_PRTY_ERR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_TBF2_PRTY_ERR_MASK                                 (0x00000010U)
#define CSL_FLEXRAY_CFG_IES_TBF2_PRTY_ERR_SHIFT                                (0x00000004U)
#define CSL_FLEXRAY_CFG_IES_TBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_TBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_IBF2_PRTY_ERR_MASK                                 (0x00000020U)
#define CSL_FLEXRAY_CFG_IES_IBF2_PRTY_ERR_SHIFT                                (0x00000005U)
#define CSL_FLEXRAY_CFG_IES_IBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_IBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_IBF1_PRTY_ERR_MASK                                 (0x00000040U)
#define CSL_FLEXRAY_CFG_IES_IBF1_PRTY_ERR_SHIFT                                (0x00000006U)
#define CSL_FLEXRAY_CFG_IES_IBF1_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_IBF1_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_OBF2_PRTY_ERR_MASK                                 (0x00000080U)
#define CSL_FLEXRAY_CFG_IES_OBF2_PRTY_ERR_SHIFT                                (0x00000007U)
#define CSL_FLEXRAY_CFG_IES_OBF2_PRTY_ERR_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_CFG_IES_OBF2_PRTY_ERR_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_CFG_IES_RESETVAL                                           (0x00000000U)

/* EOI */

#define CSL_FLEXRAY_CFG_EOI_VAL_MASK                                           (0x000000FFU)
#define CSL_FLEXRAY_CFG_EOI_VAL_SHIFT                                          (0x00000000U)
#define CSL_FLEXRAY_CFG_EOI_VAL_RESETVAL                                       (0x00000000U)
#define CSL_FLEXRAY_CFG_EOI_VAL_MAX                                            (0x000000FFU)

#define CSL_FLEXRAY_CFG_EOI_RESETVAL                                           (0x00000000U)

/**************************************************************************
* Hardware Region  : Eray Core Communicator Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint8_t  Resv_16[16];
    volatile uint32_t TEST1;                     /* Test Register 1 */
    volatile uint32_t TEST2;                     /* Test Register 2 */
    volatile uint8_t  Resv_28[4];
    volatile uint32_t LCK;                       /* Lock Register */
    volatile uint32_t EIR;                       /* Error Interrupt Register */
    volatile uint32_t SIR;                       /* Status Interrupt Register */
    volatile uint32_t EILS;                      /* Error Interrupt Line Select */
    volatile uint32_t SILS;                      /* Status Interrupt Line Select */
    volatile uint32_t EIES;                      /* Error Interrupt Enable Set */
    volatile uint32_t EIER;                      /* Error Interrupt Enable Reset */
    volatile uint32_t SIES;                      /* Status Interrupt Enable Set */
    volatile uint32_t SIER;                      /* Status Interrupt Enable Reset */
    volatile uint32_t ILE;                       /* Interrupt Line Enable */
    volatile uint32_t T0C;                       /* Timer 0 Configuration */
    volatile uint32_t T1C;                       /* Timer 1 Configuration */
    volatile uint32_t STPW1;                     /* Stop Watch Register 1 */
    volatile uint32_t STPW2;                     /* Stop Watch Register 2 */
    volatile uint8_t  Resv_128[44];
    volatile uint32_t SUCC1;                     /* SUC Configuration Register 1 */
    volatile uint32_t SUCC2;                     /* SUC Configuration Register 2 */
    volatile uint32_t SUCC3;                     /* SUC Configuration Register 3 */
    volatile uint32_t NEMC;                      /* NEM Configuration Register */
    volatile uint32_t PRTC1;                     /* PRT Configuration Register 1 */
    volatile uint32_t PRTC2;                     /* PRT Configuration Register 2 */
    volatile uint32_t MHDC;                      /* MHD Configuration Register */
    volatile uint8_t  Resv_160[4];
    volatile uint32_t GTUC1;                     /* GTU Configuration Register 1 */
    volatile uint32_t GTUC2;                     /* GTU Configuration Register 2 */
    volatile uint32_t GTUC3;                     /* GTU Configuration Register 3 */
    volatile uint32_t GTUC4;                     /* GTU Configuration Register 4 */
    volatile uint32_t GTUC5;                     /* GTU Configuration Register 5 */
    volatile uint32_t GTUC6;                     /* GTU Configuration Register 6 */
    volatile uint32_t GTUC7;                     /* GTU Configuration Register 7 */
    volatile uint32_t GTUC8;                     /* GTU Configuration Register 8 */
    volatile uint32_t GTUC9;                     /* GTU Configuration Register 9 */
    volatile uint32_t GTUC10;                    /* GTU Configuration Register 10 */
    volatile uint32_t GTUC11;                    /* GTU Configuration Register 11 */
    volatile uint8_t  Resv_256[52];
    volatile uint32_t CCSV;                      /* CC Status Vector */
    volatile uint32_t CCEV;                      /* CC Error Vector */
    volatile uint8_t  Resv_272[8];
    volatile uint32_t SCV;                       /* Slot Counter Value */
    volatile uint32_t MTCCV;                     /* Macrotick and Cycle Counter Value */
    volatile uint32_t RCV;                       /* Rate Correction Value */
    volatile uint32_t OCV;                       /* Offset Correction Value */
    volatile uint32_t SFS;                       /* Sync Frame Status */
    volatile uint32_t SWNIT;                     /* Symbol Window and NIT Status */
    volatile uint32_t ACS;                       /* Aggregated Channel Status */
    volatile uint8_t  Resv_304[4];
    volatile uint32_t ESID1;                     /* Even Sync ID 1 */
    volatile uint32_t ESID2;                     /* Even Sync ID 2 */
    volatile uint32_t ESID3;                     /* Even Sync ID 3 */
    volatile uint32_t ESID4;                     /* Even Sync ID 4 */
    volatile uint32_t ESID5;                     /* Even Sync ID 5 */
    volatile uint32_t ESID6;                     /* Even Sync ID 6 */
    volatile uint32_t ESID7;                     /* Even Sync ID 7 */
    volatile uint32_t ESID8;                     /* Even Sync ID 8 */
    volatile uint32_t ESID9;                     /* Even Sync ID 9 */
    volatile uint32_t ESID10;                    /* Even Sync ID 10 */
    volatile uint32_t ESID11;                    /* Even Sync ID 11 */
    volatile uint32_t ESID12;                    /* Even Sync ID 12 */
    volatile uint32_t ESID13;                    /* Even Sync ID 13 */
    volatile uint32_t ESID14;                    /* Even Sync ID 14 */
    volatile uint32_t ESID15;                    /* Even Sync ID 15 */
    volatile uint8_t  Resv_368[4];
    volatile uint32_t OSID1;                     /* Odd Sync ID 1 */
    volatile uint32_t OSID2;                     /* Odd Sync ID 2 */
    volatile uint32_t OSID3;                     /* Odd Sync ID 3 */
    volatile uint32_t OSID4;                     /* Odd Sync ID 4 */
    volatile uint32_t OSID5;                     /* Odd Sync ID 5 */
    volatile uint32_t OSID6;                     /* Odd Sync ID 6 */
    volatile uint32_t OSID7;                     /* Odd Sync ID 7 */
    volatile uint32_t OSID8;                     /* Odd Sync ID 8 */
    volatile uint32_t OSID9;                     /* Odd Sync ID 9 */
    volatile uint32_t OSID10;                    /* Odd Sync ID 10 */
    volatile uint32_t OSID11;                    /* Odd Sync ID 11 */
    volatile uint32_t OSID12;                    /* Odd Sync ID 12 */
    volatile uint32_t OSID13;                    /* Odd Sync ID 13 */
    volatile uint32_t OSID14;                    /* Odd Sync ID 14 */
    volatile uint32_t OSID15;                    /* Odd Sync ID 15 */
    volatile uint8_t  Resv_432[4];
    volatile uint32_t NMV1;                      /* Network Management Vector 1 */
    volatile uint32_t NMV2;                      /* Network Management Vector 2 */
    volatile uint32_t NMV3;                      /* Network Management Vector 3 */
    volatile uint8_t  Resv_768[324];
    volatile uint32_t MRC;                       /* Message RAM Configuration */
    volatile uint32_t FRF;                       /* FIFO Rejection Filter */
    volatile uint32_t FRFM;                      /* FIFO Rejection Filter Mask */
    volatile uint32_t FCL;                       /* FIFO Critical Level */
    volatile uint32_t MHDS;                      /* Message Handler Status */
    volatile uint32_t LDTS;                      /* Last Dynamic Transmit Slot */
    volatile uint32_t FSR;                       /* FIFO Status Register */
    volatile uint32_t MHDF;                      /* Message Handler Failure */
    volatile uint32_t TXRQ1;                     /* Transmission Request Register 1 */
    volatile uint32_t TXRQ2;                     /* Transmission Request Register 2 */
    volatile uint32_t TXRQ3;                     /* Transmission Request Register 3 */
    volatile uint32_t TXRQ4;                     /* Transmission Request Register 4 */
    volatile uint32_t NDAT1;                     /* New Data Register 1 */
    volatile uint32_t NDAT2;                     /* New Data Register 2 */
    volatile uint32_t NDAT3;                     /* New Data Register 3 */
    volatile uint32_t NDAT4;                     /* New Data Register 4 */
    volatile uint32_t MBSC1;                     /* Message Buffer Status Changed 1 */
    volatile uint32_t MBSC2;                     /* Message Buffer Status Changed 2 */
    volatile uint32_t MBSC3;                     /* Message Buffer Status Changed 3 */
    volatile uint32_t MBSC4;                     /* Message Buffer Status Changed 4 */
    volatile uint8_t  Resv_1008[160];
    volatile uint32_t CREL;                      /* Core Release Register */
    volatile uint32_t ENDN;                      /* Endian Register */
    volatile uint8_t  Resv_1024[8];
    volatile uint32_t WRDS1;                     /* Write Data Section 1 */
    volatile uint32_t WRDS2;                     /* Write Data Section 2 */
    volatile uint32_t WRDS3;                     /* Write Data Section 3 */
    volatile uint32_t WRDS4;                     /* Write Data Section 4 */
    volatile uint32_t WRDS5;                     /* Write Data Section 5 */
    volatile uint32_t WRDS6;                     /* Write Data Section 6 */
    volatile uint32_t WRDS7;                     /* Write Data Section 7 */
    volatile uint32_t WRDS8;                     /* Write Data Section 8 */
    volatile uint32_t WRDS9;                     /* Write Data Section 9 */
    volatile uint32_t WRDS10;                    /* Write Data Section 10 */
    volatile uint32_t WRDS11;                    /* Write Data Section 11 */
    volatile uint32_t WRDS12;                    /* Write Data Section 12 */
    volatile uint32_t WRDS13;                    /* Write Data Section 13 */
    volatile uint32_t WRDS14;                    /* Write Data Section 14 */
    volatile uint32_t WRDS15;                    /* Write Data Section 15 */
    volatile uint32_t WRDS16;                    /* Write Data Section 16 */
    volatile uint32_t WRDS17;                    /* Write Data Section 17 */
    volatile uint32_t WRDS18;                    /* Write Data Section 18 */
    volatile uint32_t WRDS19;                    /* Write Data Section 19 */
    volatile uint32_t WRDS20;                    /* Write Data Section 20 */
    volatile uint32_t WRDS21;                    /* Write Data Section 21 */
    volatile uint32_t WRDS22;                    /* Write Data Section 22 */
    volatile uint32_t WRDS23;                    /* Write Data Section 23 */
    volatile uint32_t WRDS24;                    /* Write Data Section 24 */
    volatile uint32_t WRDS25;                    /* Write Data Section 25 */
    volatile uint32_t WRDS26;                    /* Write Data Section 26 */
    volatile uint32_t WRDS27;                    /* Write Data Section 27 */
    volatile uint32_t WRDS28;                    /* Write Data Section 28 */
    volatile uint32_t WRDS29;                    /* Write Data Section 29 */
    volatile uint32_t WRDS30;                    /* Write Data Section 30 */
    volatile uint32_t WRDS31;                    /* Write Data Section 31 */
    volatile uint32_t WRDS32;                    /* Write Data Section 32 */
    volatile uint32_t WRDS33;                    /* Write Data Section 33 */
    volatile uint32_t WRDS34;                    /* Write Data Section 34 */
    volatile uint32_t WRDS35;                    /* Write Data Section 35 */
    volatile uint32_t WRDS36;                    /* Write Data Section 36 */
    volatile uint32_t WRDS37;                    /* Write Data Section 37 */
    volatile uint32_t WRDS38;                    /* Write Data Section 38 */
    volatile uint32_t WRDS39;                    /* Write Data Section 39 */
    volatile uint32_t WRDS40;                    /* Write Data Section 40 */
    volatile uint32_t WRDS41;                    /* Write Data Section 41 */
    volatile uint32_t WRDS42;                    /* Write Data Section 42 */
    volatile uint32_t WRDS43;                    /* Write Data Section 43 */
    volatile uint32_t WRDS44;                    /* Write Data Section 44 */
    volatile uint32_t WRDS45;                    /* Write Data Section 45 */
    volatile uint32_t WRDS46;                    /* Write Data Section 46 */
    volatile uint32_t WRDS47;                    /* Write Data Section 47 */
    volatile uint32_t WRDS48;                    /* Write Data Section 48 */
    volatile uint32_t WRDS49;                    /* Write Data Section 49 */
    volatile uint32_t WRDS50;                    /* Write Data Section 50 */
    volatile uint32_t WRDS51;                    /* Write Data Section 51 */
    volatile uint32_t WRDS52;                    /* Write Data Section 52 */
    volatile uint32_t WRDS53;                    /* Write Data Section 53 */
    volatile uint32_t WRDS54;                    /* Write Data Section 54 */
    volatile uint32_t WRDS55;                    /* Write Data Section 55 */
    volatile uint32_t WRDS56;                    /* Write Data Section 56 */
    volatile uint32_t WRDS57;                    /* Write Data Section 57 */
    volatile uint32_t WRDS58;                    /* Write Data Section 58 */
    volatile uint32_t WRDS59;                    /* Write Data Section 59 */
    volatile uint32_t WRDS60;                    /* Write Data Section 60 */
    volatile uint32_t WRDS61;                    /* Write Data Section 61 */
    volatile uint32_t WRDS62;                    /* Write Data Section 62 */
    volatile uint32_t WRDS63;                    /* Write Data Section 63 */
    volatile uint32_t WRDS64;                    /* Write Data Section 64 */
    volatile uint32_t WRHS1;                     /* Write Header Section 1 */
    volatile uint32_t WRHS2;                     /* Write Header Section 2 */
    volatile uint32_t WRHS3;                     /* Write Header Section 3 */
    volatile uint8_t  Resv_1296[4];
    volatile uint32_t IBCM;                      /* Input Buffer Command Mask */
    volatile uint32_t IBCR;                      /* Input Buffer Command Request */
    volatile uint8_t  Resv_1536[232];
    volatile uint32_t RDDS1;                     /* Read Data Section 1 */
    volatile uint32_t RDDS2;                     /* Read Data Section 2 */
    volatile uint32_t RDDS3;                     /* Read Data Section 3 */
    volatile uint32_t RDDS4;                     /* Read Data Section 4 */
    volatile uint32_t RDDS5;                     /* Read Data Section 5 */
    volatile uint32_t RDDS6;                     /* Read Data Section 6 */
    volatile uint32_t RDDS7;                     /* Read Data Section 7 */
    volatile uint32_t RDDS8;                     /* Read Data Section 8 */
    volatile uint32_t RDDS9;                     /* Read Data Section 9 */
    volatile uint32_t RDDS10;                    /* Read Data Section 10 */
    volatile uint32_t RDDS11;                    /* Read Data Section 11 */
    volatile uint32_t RDDS12;                    /* Read Data Section 12 */
    volatile uint32_t RDDS13;                    /* Read Data Section 13 */
    volatile uint32_t RDDS14;                    /* Read Data Section 14 */
    volatile uint32_t RDDS15;                    /* Read Data Section 15 */
    volatile uint32_t RDDS16;                    /* Read Data Section 16 */
    volatile uint32_t RDDS17;                    /* Read Data Section 17 */
    volatile uint32_t RDDS18;                    /* Read Data Section 18 */
    volatile uint32_t RDDS19;                    /* Read Data Section 19 */
    volatile uint32_t RDDS20;                    /* Read Data Section 20 */
    volatile uint32_t RDDS21;                    /* Read Data Section 21 */
    volatile uint32_t RDDS22;                    /* Read Data Section 22 */
    volatile uint32_t RDDS23;                    /* Read Data Section 23 */
    volatile uint32_t RDDS24;                    /* Read Data Section 24 */
    volatile uint32_t RDDS25;                    /* Read Data Section 25 */
    volatile uint32_t RDDS26;                    /* Read Data Section 26 */
    volatile uint32_t RDDS27;                    /* Read Data Section 27 */
    volatile uint32_t RDDS28;                    /* Read Data Section 28 */
    volatile uint32_t RDDS29;                    /* Read Data Section 29 */
    volatile uint32_t RDDS30;                    /* Read Data Section 30 */
    volatile uint32_t RDDS31;                    /* Read Data Section 31 */
    volatile uint32_t RDDS32;                    /* Read Data Section 32 */
    volatile uint32_t RDDS33;                    /* Read Data Section 33 */
    volatile uint32_t RDDS34;                    /* Read Data Section 34 */
    volatile uint32_t RDDS35;                    /* Read Data Section 35 */
    volatile uint32_t RDDS36;                    /* Read Data Section 36 */
    volatile uint32_t RDDS37;                    /* Read Data Section 37 */
    volatile uint32_t RDDS38;                    /* Read Data Section 38 */
    volatile uint32_t RDDS39;                    /* Read Data Section 39 */
    volatile uint32_t RDDS40;                    /* Read Data Section 40 */
    volatile uint32_t RDDS41;                    /* Read Data Section 41 */
    volatile uint32_t RDDS42;                    /* Read Data Section 42 */
    volatile uint32_t RDDS43;                    /* Read Data Section 43 */
    volatile uint32_t RDDS44;                    /* Read Data Section 44 */
    volatile uint32_t RDDS45;                    /* Read Data Section 45 */
    volatile uint32_t RDDS46;                    /* Read Data Section 46 */
    volatile uint32_t RDDS47;                    /* Read Data Section 47 */
    volatile uint32_t RDDS48;                    /* Read Data Section 48 */
    volatile uint32_t RDDS49;                    /* Read Data Section 49 */
    volatile uint32_t RDDS50;                    /* Read Data Section 50 */
    volatile uint32_t RDDS51;                    /* Read Data Section 51 */
    volatile uint32_t RDDS52;                    /* Read Data Section 52 */
    volatile uint32_t RDDS53;                    /* Read Data Section 53 */
    volatile uint32_t RDDS54;                    /* Read Data Section 54 */
    volatile uint32_t RDDS55;                    /* Read Data Section 55 */
    volatile uint32_t RDDS56;                    /* Read Data Section 56 */
    volatile uint32_t RDDS57;                    /* Read Data Section 57 */
    volatile uint32_t RDDS58;                    /* Read Data Section 58 */
    volatile uint32_t RDDS59;                    /* Read Data Section 59 */
    volatile uint32_t RDDS60;                    /* Read Data Section 60 */
    volatile uint32_t RDDS61;                    /* Read Data Section 61 */
    volatile uint32_t RDDS62;                    /* Read Data Section 62 */
    volatile uint32_t RDDS63;                    /* Read Data Section 63 */
    volatile uint32_t RDDS64;                    /* Read Data Section 64 */
    volatile uint32_t RDHS1;                     /* Read Header Section 1 */
    volatile uint32_t RDHS2;                     /* Read Header Section 2 */
    volatile uint32_t RDHS3;                     /* Read Header Section 3 */
    volatile uint32_t MBS;                       /* Message Buffer Status */
    volatile uint32_t OBCM;                      /* Output Buffer Command Mask */
    volatile uint32_t OBCR;                      /* Output Buffer Command Request */
} CSL_flexray_erayRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FLEXRAY_ERAY_TEST1                                                 (0x00000010U)
#define CSL_FLEXRAY_ERAY_TEST2                                                 (0x00000014U)
#define CSL_FLEXRAY_ERAY_LCK                                                   (0x0000001CU)
#define CSL_FLEXRAY_ERAY_EIR                                                   (0x00000020U)
#define CSL_FLEXRAY_ERAY_SIR                                                   (0x00000024U)
#define CSL_FLEXRAY_ERAY_EILS                                                  (0x00000028U)
#define CSL_FLEXRAY_ERAY_SILS                                                  (0x0000002CU)
#define CSL_FLEXRAY_ERAY_EIES                                                  (0x00000030U)
#define CSL_FLEXRAY_ERAY_EIER                                                  (0x00000034U)
#define CSL_FLEXRAY_ERAY_SIES                                                  (0x00000038U)
#define CSL_FLEXRAY_ERAY_SIER                                                  (0x0000003CU)
#define CSL_FLEXRAY_ERAY_ILE                                                   (0x00000040U)
#define CSL_FLEXRAY_ERAY_T0C                                                   (0x00000044U)
#define CSL_FLEXRAY_ERAY_T1C                                                   (0x00000048U)
#define CSL_FLEXRAY_ERAY_STPW1                                                 (0x0000004CU)
#define CSL_FLEXRAY_ERAY_STPW2                                                 (0x00000050U)
#define CSL_FLEXRAY_ERAY_SUCC1                                                 (0x00000080U)
#define CSL_FLEXRAY_ERAY_SUCC2                                                 (0x00000084U)
#define CSL_FLEXRAY_ERAY_SUCC3                                                 (0x00000088U)
#define CSL_FLEXRAY_ERAY_NEMC                                                  (0x0000008CU)
#define CSL_FLEXRAY_ERAY_PRTC1                                                 (0x00000090U)
#define CSL_FLEXRAY_ERAY_PRTC2                                                 (0x00000094U)
#define CSL_FLEXRAY_ERAY_MHDC                                                  (0x00000098U)
#define CSL_FLEXRAY_ERAY_GTUC1                                                 (0x000000A0U)
#define CSL_FLEXRAY_ERAY_GTUC2                                                 (0x000000A4U)
#define CSL_FLEXRAY_ERAY_GTUC3                                                 (0x000000A8U)
#define CSL_FLEXRAY_ERAY_GTUC4                                                 (0x000000ACU)
#define CSL_FLEXRAY_ERAY_GTUC5                                                 (0x000000B0U)
#define CSL_FLEXRAY_ERAY_GTUC6                                                 (0x000000B4U)
#define CSL_FLEXRAY_ERAY_GTUC7                                                 (0x000000B8U)
#define CSL_FLEXRAY_ERAY_GTUC8                                                 (0x000000BCU)
#define CSL_FLEXRAY_ERAY_GTUC9                                                 (0x000000C0U)
#define CSL_FLEXRAY_ERAY_GTUC10                                                (0x000000C4U)
#define CSL_FLEXRAY_ERAY_GTUC11                                                (0x000000C8U)
#define CSL_FLEXRAY_ERAY_CCSV                                                  (0x00000100U)
#define CSL_FLEXRAY_ERAY_CCEV                                                  (0x00000104U)
#define CSL_FLEXRAY_ERAY_SCV                                                   (0x00000110U)
#define CSL_FLEXRAY_ERAY_MTCCV                                                 (0x00000114U)
#define CSL_FLEXRAY_ERAY_RCV                                                   (0x00000118U)
#define CSL_FLEXRAY_ERAY_OCV                                                   (0x0000011CU)
#define CSL_FLEXRAY_ERAY_SFS                                                   (0x00000120U)
#define CSL_FLEXRAY_ERAY_SWNIT                                                 (0x00000124U)
#define CSL_FLEXRAY_ERAY_ACS                                                   (0x00000128U)
#define CSL_FLEXRAY_ERAY_ESID1                                                 (0x00000130U)
#define CSL_FLEXRAY_ERAY_ESID2                                                 (0x00000134U)
#define CSL_FLEXRAY_ERAY_ESID3                                                 (0x00000138U)
#define CSL_FLEXRAY_ERAY_ESID4                                                 (0x0000013CU)
#define CSL_FLEXRAY_ERAY_ESID5                                                 (0x00000140U)
#define CSL_FLEXRAY_ERAY_ESID6                                                 (0x00000144U)
#define CSL_FLEXRAY_ERAY_ESID7                                                 (0x00000148U)
#define CSL_FLEXRAY_ERAY_ESID8                                                 (0x0000014CU)
#define CSL_FLEXRAY_ERAY_ESID9                                                 (0x00000150U)
#define CSL_FLEXRAY_ERAY_ESID10                                                (0x00000154U)
#define CSL_FLEXRAY_ERAY_ESID11                                                (0x00000158U)
#define CSL_FLEXRAY_ERAY_ESID12                                                (0x0000015CU)
#define CSL_FLEXRAY_ERAY_ESID13                                                (0x00000160U)
#define CSL_FLEXRAY_ERAY_ESID14                                                (0x00000164U)
#define CSL_FLEXRAY_ERAY_ESID15                                                (0x00000168U)
#define CSL_FLEXRAY_ERAY_OSID1                                                 (0x00000170U)
#define CSL_FLEXRAY_ERAY_OSID2                                                 (0x00000174U)
#define CSL_FLEXRAY_ERAY_OSID3                                                 (0x00000178U)
#define CSL_FLEXRAY_ERAY_OSID4                                                 (0x0000017CU)
#define CSL_FLEXRAY_ERAY_OSID5                                                 (0x00000180U)
#define CSL_FLEXRAY_ERAY_OSID6                                                 (0x00000184U)
#define CSL_FLEXRAY_ERAY_OSID7                                                 (0x00000188U)
#define CSL_FLEXRAY_ERAY_OSID8                                                 (0x0000018CU)
#define CSL_FLEXRAY_ERAY_OSID9                                                 (0x00000190U)
#define CSL_FLEXRAY_ERAY_OSID10                                                (0x00000194U)
#define CSL_FLEXRAY_ERAY_OSID11                                                (0x00000198U)
#define CSL_FLEXRAY_ERAY_OSID12                                                (0x0000019CU)
#define CSL_FLEXRAY_ERAY_OSID13                                                (0x000001A0U)
#define CSL_FLEXRAY_ERAY_OSID14                                                (0x000001A4U)
#define CSL_FLEXRAY_ERAY_OSID15                                                (0x000001A8U)
#define CSL_FLEXRAY_ERAY_NMV1                                                  (0x000001B0U)
#define CSL_FLEXRAY_ERAY_NMV2                                                  (0x000001B4U)
#define CSL_FLEXRAY_ERAY_NMV3                                                  (0x000001B8U)
#define CSL_FLEXRAY_ERAY_MRC                                                   (0x00000300U)
#define CSL_FLEXRAY_ERAY_FRF                                                   (0x00000304U)
#define CSL_FLEXRAY_ERAY_FRFM                                                  (0x00000308U)
#define CSL_FLEXRAY_ERAY_FCL                                                   (0x0000030CU)
#define CSL_FLEXRAY_ERAY_MHDS                                                  (0x00000310U)
#define CSL_FLEXRAY_ERAY_LDTS                                                  (0x00000314U)
#define CSL_FLEXRAY_ERAY_FSR                                                   (0x00000318U)
#define CSL_FLEXRAY_ERAY_MHDF                                                  (0x0000031CU)
#define CSL_FLEXRAY_ERAY_TXRQ1                                                 (0x00000320U)
#define CSL_FLEXRAY_ERAY_TXRQ2                                                 (0x00000324U)
#define CSL_FLEXRAY_ERAY_TXRQ3                                                 (0x00000328U)
#define CSL_FLEXRAY_ERAY_TXRQ4                                                 (0x0000032CU)
#define CSL_FLEXRAY_ERAY_NDAT1                                                 (0x00000330U)
#define CSL_FLEXRAY_ERAY_NDAT2                                                 (0x00000334U)
#define CSL_FLEXRAY_ERAY_NDAT3                                                 (0x00000338U)
#define CSL_FLEXRAY_ERAY_NDAT4                                                 (0x0000033CU)
#define CSL_FLEXRAY_ERAY_MBSC1                                                 (0x00000340U)
#define CSL_FLEXRAY_ERAY_MBSC2                                                 (0x00000344U)
#define CSL_FLEXRAY_ERAY_MBSC3                                                 (0x00000348U)
#define CSL_FLEXRAY_ERAY_MBSC4                                                 (0x0000034CU)
#define CSL_FLEXRAY_ERAY_CREL                                                  (0x000003F0U)
#define CSL_FLEXRAY_ERAY_ENDN                                                  (0x000003F4U)
#define CSL_FLEXRAY_ERAY_WRDS1                                                 (0x00000400U)
#define CSL_FLEXRAY_ERAY_WRDS2                                                 (0x00000404U)
#define CSL_FLEXRAY_ERAY_WRDS3                                                 (0x00000408U)
#define CSL_FLEXRAY_ERAY_WRDS4                                                 (0x0000040CU)
#define CSL_FLEXRAY_ERAY_WRDS5                                                 (0x00000410U)
#define CSL_FLEXRAY_ERAY_WRDS6                                                 (0x00000414U)
#define CSL_FLEXRAY_ERAY_WRDS7                                                 (0x00000418U)
#define CSL_FLEXRAY_ERAY_WRDS8                                                 (0x0000041CU)
#define CSL_FLEXRAY_ERAY_WRDS9                                                 (0x00000420U)
#define CSL_FLEXRAY_ERAY_WRDS10                                                (0x00000424U)
#define CSL_FLEXRAY_ERAY_WRDS11                                                (0x00000428U)
#define CSL_FLEXRAY_ERAY_WRDS12                                                (0x0000042CU)
#define CSL_FLEXRAY_ERAY_WRDS13                                                (0x00000430U)
#define CSL_FLEXRAY_ERAY_WRDS14                                                (0x00000434U)
#define CSL_FLEXRAY_ERAY_WRDS15                                                (0x00000438U)
#define CSL_FLEXRAY_ERAY_WRDS16                                                (0x0000043CU)
#define CSL_FLEXRAY_ERAY_WRDS17                                                (0x00000440U)
#define CSL_FLEXRAY_ERAY_WRDS18                                                (0x00000444U)
#define CSL_FLEXRAY_ERAY_WRDS19                                                (0x00000448U)
#define CSL_FLEXRAY_ERAY_WRDS20                                                (0x0000044CU)
#define CSL_FLEXRAY_ERAY_WRDS21                                                (0x00000450U)
#define CSL_FLEXRAY_ERAY_WRDS22                                                (0x00000454U)
#define CSL_FLEXRAY_ERAY_WRDS23                                                (0x00000458U)
#define CSL_FLEXRAY_ERAY_WRDS24                                                (0x0000045CU)
#define CSL_FLEXRAY_ERAY_WRDS25                                                (0x00000460U)
#define CSL_FLEXRAY_ERAY_WRDS26                                                (0x00000464U)
#define CSL_FLEXRAY_ERAY_WRDS27                                                (0x00000468U)
#define CSL_FLEXRAY_ERAY_WRDS28                                                (0x0000046CU)
#define CSL_FLEXRAY_ERAY_WRDS29                                                (0x00000470U)
#define CSL_FLEXRAY_ERAY_WRDS30                                                (0x00000474U)
#define CSL_FLEXRAY_ERAY_WRDS31                                                (0x00000478U)
#define CSL_FLEXRAY_ERAY_WRDS32                                                (0x0000047CU)
#define CSL_FLEXRAY_ERAY_WRDS33                                                (0x00000480U)
#define CSL_FLEXRAY_ERAY_WRDS34                                                (0x00000484U)
#define CSL_FLEXRAY_ERAY_WRDS35                                                (0x00000488U)
#define CSL_FLEXRAY_ERAY_WRDS36                                                (0x0000048CU)
#define CSL_FLEXRAY_ERAY_WRDS37                                                (0x00000490U)
#define CSL_FLEXRAY_ERAY_WRDS38                                                (0x00000494U)
#define CSL_FLEXRAY_ERAY_WRDS39                                                (0x00000498U)
#define CSL_FLEXRAY_ERAY_WRDS40                                                (0x0000049CU)
#define CSL_FLEXRAY_ERAY_WRDS41                                                (0x000004A0U)
#define CSL_FLEXRAY_ERAY_WRDS42                                                (0x000004A4U)
#define CSL_FLEXRAY_ERAY_WRDS43                                                (0x000004A8U)
#define CSL_FLEXRAY_ERAY_WRDS44                                                (0x000004ACU)
#define CSL_FLEXRAY_ERAY_WRDS45                                                (0x000004B0U)
#define CSL_FLEXRAY_ERAY_WRDS46                                                (0x000004B4U)
#define CSL_FLEXRAY_ERAY_WRDS47                                                (0x000004B8U)
#define CSL_FLEXRAY_ERAY_WRDS48                                                (0x000004BCU)
#define CSL_FLEXRAY_ERAY_WRDS49                                                (0x000004C0U)
#define CSL_FLEXRAY_ERAY_WRDS50                                                (0x000004C4U)
#define CSL_FLEXRAY_ERAY_WRDS51                                                (0x000004C8U)
#define CSL_FLEXRAY_ERAY_WRDS52                                                (0x000004CCU)
#define CSL_FLEXRAY_ERAY_WRDS53                                                (0x000004D0U)
#define CSL_FLEXRAY_ERAY_WRDS54                                                (0x000004D4U)
#define CSL_FLEXRAY_ERAY_WRDS55                                                (0x000004D8U)
#define CSL_FLEXRAY_ERAY_WRDS56                                                (0x000004DCU)
#define CSL_FLEXRAY_ERAY_WRDS57                                                (0x000004E0U)
#define CSL_FLEXRAY_ERAY_WRDS58                                                (0x000004E4U)
#define CSL_FLEXRAY_ERAY_WRDS59                                                (0x000004E8U)
#define CSL_FLEXRAY_ERAY_WRDS60                                                (0x000004ECU)
#define CSL_FLEXRAY_ERAY_WRDS61                                                (0x000004F0U)
#define CSL_FLEXRAY_ERAY_WRDS62                                                (0x000004F4U)
#define CSL_FLEXRAY_ERAY_WRDS63                                                (0x000004F8U)
#define CSL_FLEXRAY_ERAY_WRDS64                                                (0x000004FCU)
#define CSL_FLEXRAY_ERAY_WRHS1                                                 (0x00000500U)
#define CSL_FLEXRAY_ERAY_WRHS2                                                 (0x00000504U)
#define CSL_FLEXRAY_ERAY_WRHS3                                                 (0x00000508U)
#define CSL_FLEXRAY_ERAY_IBCM                                                  (0x00000510U)
#define CSL_FLEXRAY_ERAY_IBCR                                                  (0x00000514U)
#define CSL_FLEXRAY_ERAY_RDDS1                                                 (0x00000600U)
#define CSL_FLEXRAY_ERAY_RDDS2                                                 (0x00000604U)
#define CSL_FLEXRAY_ERAY_RDDS3                                                 (0x00000608U)
#define CSL_FLEXRAY_ERAY_RDDS4                                                 (0x0000060CU)
#define CSL_FLEXRAY_ERAY_RDDS5                                                 (0x00000610U)
#define CSL_FLEXRAY_ERAY_RDDS6                                                 (0x00000614U)
#define CSL_FLEXRAY_ERAY_RDDS7                                                 (0x00000618U)
#define CSL_FLEXRAY_ERAY_RDDS8                                                 (0x0000061CU)
#define CSL_FLEXRAY_ERAY_RDDS9                                                 (0x00000620U)
#define CSL_FLEXRAY_ERAY_RDDS10                                                (0x00000624U)
#define CSL_FLEXRAY_ERAY_RDDS11                                                (0x00000628U)
#define CSL_FLEXRAY_ERAY_RDDS12                                                (0x0000062CU)
#define CSL_FLEXRAY_ERAY_RDDS13                                                (0x00000630U)
#define CSL_FLEXRAY_ERAY_RDDS14                                                (0x00000634U)
#define CSL_FLEXRAY_ERAY_RDDS15                                                (0x00000638U)
#define CSL_FLEXRAY_ERAY_RDDS16                                                (0x0000063CU)
#define CSL_FLEXRAY_ERAY_RDDS17                                                (0x00000640U)
#define CSL_FLEXRAY_ERAY_RDDS18                                                (0x00000644U)
#define CSL_FLEXRAY_ERAY_RDDS19                                                (0x00000648U)
#define CSL_FLEXRAY_ERAY_RDDS20                                                (0x0000064CU)
#define CSL_FLEXRAY_ERAY_RDDS21                                                (0x00000650U)
#define CSL_FLEXRAY_ERAY_RDDS22                                                (0x00000654U)
#define CSL_FLEXRAY_ERAY_RDDS23                                                (0x00000658U)
#define CSL_FLEXRAY_ERAY_RDDS24                                                (0x0000065CU)
#define CSL_FLEXRAY_ERAY_RDDS25                                                (0x00000660U)
#define CSL_FLEXRAY_ERAY_RDDS26                                                (0x00000664U)
#define CSL_FLEXRAY_ERAY_RDDS27                                                (0x00000668U)
#define CSL_FLEXRAY_ERAY_RDDS28                                                (0x0000066CU)
#define CSL_FLEXRAY_ERAY_RDDS29                                                (0x00000670U)
#define CSL_FLEXRAY_ERAY_RDDS30                                                (0x00000674U)
#define CSL_FLEXRAY_ERAY_RDDS31                                                (0x00000678U)
#define CSL_FLEXRAY_ERAY_RDDS32                                                (0x0000067CU)
#define CSL_FLEXRAY_ERAY_RDDS33                                                (0x00000680U)
#define CSL_FLEXRAY_ERAY_RDDS34                                                (0x00000684U)
#define CSL_FLEXRAY_ERAY_RDDS35                                                (0x00000688U)
#define CSL_FLEXRAY_ERAY_RDDS36                                                (0x0000068CU)
#define CSL_FLEXRAY_ERAY_RDDS37                                                (0x00000690U)
#define CSL_FLEXRAY_ERAY_RDDS38                                                (0x00000694U)
#define CSL_FLEXRAY_ERAY_RDDS39                                                (0x00000698U)
#define CSL_FLEXRAY_ERAY_RDDS40                                                (0x0000069CU)
#define CSL_FLEXRAY_ERAY_RDDS41                                                (0x000006A0U)
#define CSL_FLEXRAY_ERAY_RDDS42                                                (0x000006A4U)
#define CSL_FLEXRAY_ERAY_RDDS43                                                (0x000006A8U)
#define CSL_FLEXRAY_ERAY_RDDS44                                                (0x000006ACU)
#define CSL_FLEXRAY_ERAY_RDDS45                                                (0x000006B0U)
#define CSL_FLEXRAY_ERAY_RDDS46                                                (0x000006B4U)
#define CSL_FLEXRAY_ERAY_RDDS47                                                (0x000006B8U)
#define CSL_FLEXRAY_ERAY_RDDS48                                                (0x000006BCU)
#define CSL_FLEXRAY_ERAY_RDDS49                                                (0x000006C0U)
#define CSL_FLEXRAY_ERAY_RDDS50                                                (0x000006C4U)
#define CSL_FLEXRAY_ERAY_RDDS51                                                (0x000006C8U)
#define CSL_FLEXRAY_ERAY_RDDS52                                                (0x000006CCU)
#define CSL_FLEXRAY_ERAY_RDDS53                                                (0x000006D0U)
#define CSL_FLEXRAY_ERAY_RDDS54                                                (0x000006D4U)
#define CSL_FLEXRAY_ERAY_RDDS55                                                (0x000006D8U)
#define CSL_FLEXRAY_ERAY_RDDS56                                                (0x000006DCU)
#define CSL_FLEXRAY_ERAY_RDDS57                                                (0x000006E0U)
#define CSL_FLEXRAY_ERAY_RDDS58                                                (0x000006E4U)
#define CSL_FLEXRAY_ERAY_RDDS59                                                (0x000006E8U)
#define CSL_FLEXRAY_ERAY_RDDS60                                                (0x000006ECU)
#define CSL_FLEXRAY_ERAY_RDDS61                                                (0x000006F0U)
#define CSL_FLEXRAY_ERAY_RDDS62                                                (0x000006F4U)
#define CSL_FLEXRAY_ERAY_RDDS63                                                (0x000006F8U)
#define CSL_FLEXRAY_ERAY_RDDS64                                                (0x000006FCU)
#define CSL_FLEXRAY_ERAY_RDHS1                                                 (0x00000700U)
#define CSL_FLEXRAY_ERAY_RDHS2                                                 (0x00000704U)
#define CSL_FLEXRAY_ERAY_RDHS3                                                 (0x00000708U)
#define CSL_FLEXRAY_ERAY_MBS                                                   (0x0000070CU)
#define CSL_FLEXRAY_ERAY_OBCM                                                  (0x00000710U)
#define CSL_FLEXRAY_ERAY_OBCR                                                  (0x00000714U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* TEST1 */

#define CSL_FLEXRAY_ERAY_TEST1_WRTEN_MASK                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_TEST1_WRTEN_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_WRTEN_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_WRTEN_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_ELBE_MASK                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_TEST1_ELBE_SHIFT                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_TEST1_ELBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_ELBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_TMC_MASK                                        (0x00000030U)
#define CSL_FLEXRAY_ERAY_TEST1_TMC_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_TEST1_TMC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_TMC_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_TEST1_AOA_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_TEST1_AOA_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_TEST1_AOA_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_TEST1_AOA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_AOB_MASK                                        (0x00000200U)
#define CSL_FLEXRAY_ERAY_TEST1_AOB_SHIFT                                       (0x00000009U)
#define CSL_FLEXRAY_ERAY_TEST1_AOB_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_TEST1_AOB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_RXA_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_TEST1_RXA_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_TEST1_RXA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_RXA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_RXB_MASK                                        (0x00020000U)
#define CSL_FLEXRAY_ERAY_TEST1_RXB_SHIFT                                       (0x00000011U)
#define CSL_FLEXRAY_ERAY_TEST1_RXB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_RXB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_TXA_MASK                                        (0x00040000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXA_SHIFT                                       (0x00000012U)
#define CSL_FLEXRAY_ERAY_TEST1_TXA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_TXB_MASK                                        (0x00080000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXB_SHIFT                                       (0x00000013U)
#define CSL_FLEXRAY_ERAY_TEST1_TXB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_TXENA_MASK                                      (0x00100000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENA_SHIFT                                     (0x00000014U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_TXENB_MASK                                      (0x00200000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENB_SHIFT                                     (0x00000015U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_TXENB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST1_CERA_MASK                                       (0x0F000000U)
#define CSL_FLEXRAY_ERAY_TEST1_CERA_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_TEST1_CERA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_CERA_MAX                                        (0x0000000FU)

#define CSL_FLEXRAY_ERAY_TEST1_CERB_MASK                                       (0xF0000000U)
#define CSL_FLEXRAY_ERAY_TEST1_CERB_SHIFT                                      (0x0000001CU)
#define CSL_FLEXRAY_ERAY_TEST1_CERB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST1_CERB_MAX                                        (0x0000000FU)

#define CSL_FLEXRAY_ERAY_TEST1_RESETVAL                                        (0x00000300U)

/* TEST2 */

#define CSL_FLEXRAY_ERAY_TEST2_RS_MASK                                         (0x00000007U)
#define CSL_FLEXRAY_ERAY_TEST2_RS_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST2_RS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST2_RS_MAX                                          (0x00000007U)

#define CSL_FLEXRAY_ERAY_TEST2_SSEL_MASK                                       (0x00000070U)
#define CSL_FLEXRAY_ERAY_TEST2_SSEL_SHIFT                                      (0x00000004U)
#define CSL_FLEXRAY_ERAY_TEST2_SSEL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST2_SSEL_MAX                                        (0x00000007U)

#define CSL_FLEXRAY_ERAY_TEST2_WRPB_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_TEST2_WRPB_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_TEST2_WRPB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST2_WRPB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST2_RDPB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_TEST2_RDPB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_TEST2_RDPB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TEST2_RDPB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TEST2_RESETVAL                                        (0x00000000U)

/* LCK */

#define CSL_FLEXRAY_ERAY_LCK_CLK_MASK                                          (0x000000FFU)
#define CSL_FLEXRAY_ERAY_LCK_CLK_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_LCK_CLK_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_LCK_CLK_MAX                                           (0x000000FFU)

#define CSL_FLEXRAY_ERAY_LCK_TMK_MASK                                          (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_LCK_TMK_SHIFT                                         (0x00000008U)
#define CSL_FLEXRAY_ERAY_LCK_TMK_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_LCK_TMK_MAX                                           (0x000000FFU)

#define CSL_FLEXRAY_ERAY_LCK_RESETVAL                                          (0x00000000U)

/* EIR */

#define CSL_FLEXRAY_ERAY_EIR_PEMC_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIR_PEMC_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_PEMC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_PEMC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_CNA_MASK                                          (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIR_CNA_SHIFT                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIR_CNA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_CNA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_SFBM_MASK                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIR_SFBM_SHIFT                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIR_SFBM_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_SFBM_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_SFO_MASK                                          (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIR_SFO_SHIFT                                         (0x00000003U)
#define CSL_FLEXRAY_ERAY_EIR_SFO_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_SFO_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_CCF_MASK                                          (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIR_CCF_SHIFT                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIR_CCF_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_CCF_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_CCL_MASK                                          (0x00000020U)
#define CSL_FLEXRAY_ERAY_EIR_CCL_SHIFT                                         (0x00000005U)
#define CSL_FLEXRAY_ERAY_EIR_CCL_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_CCL_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_PERR_MASK                                         (0x00000040U)
#define CSL_FLEXRAY_ERAY_EIR_PERR_SHIFT                                        (0x00000006U)
#define CSL_FLEXRAY_ERAY_EIR_PERR_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_PERR_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_RFO_MASK                                          (0x00000080U)
#define CSL_FLEXRAY_ERAY_EIR_RFO_SHIFT                                         (0x00000007U)
#define CSL_FLEXRAY_ERAY_EIR_RFO_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_RFO_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_EFA_MASK                                          (0x00000100U)
#define CSL_FLEXRAY_ERAY_EIR_EFA_SHIFT                                         (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIR_EFA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_EFA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_IIBA_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_EIR_IIBA_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_EIR_IIBA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_IIBA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_IOBA_MASK                                         (0x00000400U)
#define CSL_FLEXRAY_ERAY_EIR_IOBA_SHIFT                                        (0x0000000AU)
#define CSL_FLEXRAY_ERAY_EIR_IOBA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_IOBA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_MHF_MASK                                          (0x00000800U)
#define CSL_FLEXRAY_ERAY_EIR_MHF_SHIFT                                         (0x0000000BU)
#define CSL_FLEXRAY_ERAY_EIR_MHF_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_MHF_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_EDA_MASK                                          (0x00010000U)
#define CSL_FLEXRAY_ERAY_EIR_EDA_SHIFT                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIR_EDA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_EDA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_LTVA_MASK                                         (0x00020000U)
#define CSL_FLEXRAY_ERAY_EIR_LTVA_SHIFT                                        (0x00000011U)
#define CSL_FLEXRAY_ERAY_EIR_LTVA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_LTVA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_TABA_MASK                                         (0x00040000U)
#define CSL_FLEXRAY_ERAY_EIR_TABA_SHIFT                                        (0x00000012U)
#define CSL_FLEXRAY_ERAY_EIR_TABA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_TABA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_EDB_MASK                                          (0x01000000U)
#define CSL_FLEXRAY_ERAY_EIR_EDB_SHIFT                                         (0x00000018U)
#define CSL_FLEXRAY_ERAY_EIR_EDB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_EDB_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_LTVB_MASK                                         (0x02000000U)
#define CSL_FLEXRAY_ERAY_EIR_LTVB_SHIFT                                        (0x00000019U)
#define CSL_FLEXRAY_ERAY_EIR_LTVB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_LTVB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_TABB_MASK                                         (0x04000000U)
#define CSL_FLEXRAY_ERAY_EIR_TABB_SHIFT                                        (0x0000001AU)
#define CSL_FLEXRAY_ERAY_EIR_TABB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIR_TABB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIR_RESETVAL                                          (0x00000000U)

/* SIR */

#define CSL_FLEXRAY_ERAY_SIR_WST_MASK                                          (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIR_WST_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_WST_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_WST_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_CAS_MASK                                          (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIR_CAS_SHIFT                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIR_CAS_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_CAS_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_CYCS_MASK                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIR_CYCS_SHIFT                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIR_CYCS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_CYCS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_TXI_MASK                                          (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIR_TXI_SHIFT                                         (0x00000003U)
#define CSL_FLEXRAY_ERAY_SIR_TXI_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_TXI_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_RXI_MASK                                          (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIR_RXI_SHIFT                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIR_RXI_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_RXI_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_RFNE_MASK                                         (0x00000020U)
#define CSL_FLEXRAY_ERAY_SIR_RFNE_SHIFT                                        (0x00000005U)
#define CSL_FLEXRAY_ERAY_SIR_RFNE_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_RFNE_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_RFCL_MASK                                         (0x00000040U)
#define CSL_FLEXRAY_ERAY_SIR_RFCL_SHIFT                                        (0x00000006U)
#define CSL_FLEXRAY_ERAY_SIR_RFCL_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_RFCL_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_NMVC_MASK                                         (0x00000080U)
#define CSL_FLEXRAY_ERAY_SIR_NMVC_SHIFT                                        (0x00000007U)
#define CSL_FLEXRAY_ERAY_SIR_NMVC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_NMVC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_TI_MASK                                           (0x00000300U)
#define CSL_FLEXRAY_ERAY_SIR_TI_SHIFT                                          (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIR_TI_RESETVAL                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_TI_MAX                                            (0x00000003U)

#define CSL_FLEXRAY_ERAY_SIR_TIBC_MASK                                         (0x00000400U)
#define CSL_FLEXRAY_ERAY_SIR_TIBC_SHIFT                                        (0x0000000AU)
#define CSL_FLEXRAY_ERAY_SIR_TIBC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_TIBC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_TOBC_MASK                                         (0x00000800U)
#define CSL_FLEXRAY_ERAY_SIR_TOBC_SHIFT                                        (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SIR_TOBC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_TOBC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_SWE_MASK                                          (0x00001000U)
#define CSL_FLEXRAY_ERAY_SIR_SWE_SHIFT                                         (0x0000000CU)
#define CSL_FLEXRAY_ERAY_SIR_SWE_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_SWE_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_SUCS_MASK                                         (0x00002000U)
#define CSL_FLEXRAY_ERAY_SIR_SUCS_SHIFT                                        (0x0000000DU)
#define CSL_FLEXRAY_ERAY_SIR_SUCS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_SUCS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_MBSI_MASK                                         (0x00004000U)
#define CSL_FLEXRAY_ERAY_SIR_MBSI_SHIFT                                        (0x0000000EU)
#define CSL_FLEXRAY_ERAY_SIR_MBSI_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_MBSI_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_SDS_MASK                                          (0x00008000U)
#define CSL_FLEXRAY_ERAY_SIR_SDS_SHIFT                                         (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SIR_SDS_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_SDS_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_WUPA_MASK                                         (0x00010000U)
#define CSL_FLEXRAY_ERAY_SIR_WUPA_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIR_WUPA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_WUPA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_MTSA_MASK                                         (0x00020000U)
#define CSL_FLEXRAY_ERAY_SIR_MTSA_SHIFT                                        (0x00000011U)
#define CSL_FLEXRAY_ERAY_SIR_MTSA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_MTSA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_WUPB_MASK                                         (0x01000000U)
#define CSL_FLEXRAY_ERAY_SIR_WUPB_SHIFT                                        (0x00000018U)
#define CSL_FLEXRAY_ERAY_SIR_WUPB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_WUPB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_MTSB_MASK                                         (0x02000000U)
#define CSL_FLEXRAY_ERAY_SIR_MTSB_SHIFT                                        (0x00000019U)
#define CSL_FLEXRAY_ERAY_SIR_MTSB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIR_MTSB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIR_RESETVAL                                          (0x00000000U)

/* EILS */

#define CSL_FLEXRAY_ERAY_EILS_PEMCL_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EILS_PEMCL_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_PEMCL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_PEMCL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_CNAL_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_EILS_CNAL_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EILS_CNAL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_CNAL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_SFBML_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EILS_SFBML_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_EILS_SFBML_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_SFBML_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_SFOL_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_EILS_SFOL_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_EILS_SFOL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_SFOL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_CCFL_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_EILS_CCFL_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EILS_CCFL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_CCFL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_CCLL_MASK                                        (0x00000020U)
#define CSL_FLEXRAY_ERAY_EILS_CCLL_SHIFT                                       (0x00000005U)
#define CSL_FLEXRAY_ERAY_EILS_CCLL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_CCLL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_PERRL_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_EILS_PERRL_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_EILS_PERRL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_PERRL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_RFOL_MASK                                        (0x00000080U)
#define CSL_FLEXRAY_ERAY_EILS_RFOL_SHIFT                                       (0x00000007U)
#define CSL_FLEXRAY_ERAY_EILS_RFOL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_RFOL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_EFAL_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_EILS_EFAL_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_EILS_EFAL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_EFAL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_IIBAL_MASK                                       (0x00000200U)
#define CSL_FLEXRAY_ERAY_EILS_IIBAL_SHIFT                                      (0x00000009U)
#define CSL_FLEXRAY_ERAY_EILS_IIBAL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_IIBAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_IOBAL_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_EILS_IOBAL_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_EILS_IOBAL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_IOBAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_MHFL_MASK                                        (0x00000800U)
#define CSL_FLEXRAY_ERAY_EILS_MHFL_SHIFT                                       (0x0000000BU)
#define CSL_FLEXRAY_ERAY_EILS_MHFL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_MHFL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_EDAL_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_EILS_EDAL_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_EILS_EDAL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_EDAL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_LTVAL_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_EILS_LTVAL_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_EILS_LTVAL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_LTVAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_TABAL_MASK                                       (0x00040000U)
#define CSL_FLEXRAY_ERAY_EILS_TABAL_SHIFT                                      (0x00000012U)
#define CSL_FLEXRAY_ERAY_EILS_TABAL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_TABAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_EDBL_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_EILS_EDBL_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_EILS_EDBL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_EDBL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_LTVBL_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_EILS_LTVBL_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_EILS_LTVBL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_LTVBL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_TABBL_MASK                                       (0x04000000U)
#define CSL_FLEXRAY_ERAY_EILS_TABBL_SHIFT                                      (0x0000001AU)
#define CSL_FLEXRAY_ERAY_EILS_TABBL_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EILS_TABBL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EILS_RESETVAL                                         (0x00000000U)

/* SILS */

#define CSL_FLEXRAY_ERAY_SILS_WSTL_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_WSTL_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SILS_WSTL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_WSTL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_CASL_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_SILS_CASL_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_CASL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_CASL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_CYCSL_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SILS_CYCSL_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_SILS_CYCSL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_CYCSL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_TXIL_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SILS_TXIL_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_SILS_TXIL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_TXIL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_RXIL_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SILS_RXIL_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SILS_RXIL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_RXIL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_RFNEL_MASK                                       (0x00000020U)
#define CSL_FLEXRAY_ERAY_SILS_RFNEL_SHIFT                                      (0x00000005U)
#define CSL_FLEXRAY_ERAY_SILS_RFNEL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_RFNEL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_RFCLL_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_SILS_RFCLL_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_SILS_RFCLL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_RFCLL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_NMVCL_MASK                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_SILS_NMVCL_SHIFT                                      (0x00000007U)
#define CSL_FLEXRAY_ERAY_SILS_NMVCL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_NMVCL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_TI0_MASK                                         (0x00000100U)
#define CSL_FLEXRAY_ERAY_SILS_TI0_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SILS_TI0_RESETVAL                                     (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_TI0_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_TI1_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_SILS_TI1_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_SILS_TI1_RESETVAL                                     (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_TI1_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_TIBCL_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_SILS_TIBCL_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_SILS_TIBCL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_TIBCL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_TOBCL_MASK                                       (0x00000800U)
#define CSL_FLEXRAY_ERAY_SILS_TOBCL_SHIFT                                      (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SILS_TOBCL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_TOBCL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_SWEL_MASK                                        (0x00001000U)
#define CSL_FLEXRAY_ERAY_SILS_SWEL_SHIFT                                       (0x0000000CU)
#define CSL_FLEXRAY_ERAY_SILS_SWEL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_SWEL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_SUCSL_MASK                                       (0x00002000U)
#define CSL_FLEXRAY_ERAY_SILS_SUCSL_SHIFT                                      (0x0000000DU)
#define CSL_FLEXRAY_ERAY_SILS_SUCSL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_SUCSL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_MBSIL_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_SILS_MBSIL_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_SILS_MBSIL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_MBSIL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_SDSL_MASK                                        (0x00008000U)
#define CSL_FLEXRAY_ERAY_SILS_SDSL_SHIFT                                       (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SILS_SDSL_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_SDSL_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_WUPAL_MASK                                       (0x00010000U)
#define CSL_FLEXRAY_ERAY_SILS_WUPAL_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_SILS_WUPAL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_WUPAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_MTSAL_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_SILS_MTSAL_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_SILS_MTSAL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_MTSAL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_WUPBL_MASK                                       (0x01000000U)
#define CSL_FLEXRAY_ERAY_SILS_WUPBL_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_SILS_WUPBL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_WUPBL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_MTSBL_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_SILS_MTSBL_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_SILS_MTSBL_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SILS_MTSBL_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SILS_RESETVAL                                         (0x0303FFFFU)

/* EIES */

#define CSL_FLEXRAY_ERAY_EIES_PEMCE_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIES_PEMCE_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_PEMCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_PEMCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_CNAE_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIES_CNAE_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIES_CNAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_CNAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_SFBME_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIES_SFBME_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIES_SFBME_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_SFBME_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_SFOE_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIES_SFOE_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_EIES_SFOE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_SFOE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_CCFE_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIES_CCFE_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIES_CCFE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_CCFE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_CCLE_MASK                                        (0x00000020U)
#define CSL_FLEXRAY_ERAY_EIES_CCLE_SHIFT                                       (0x00000005U)
#define CSL_FLEXRAY_ERAY_EIES_CCLE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_CCLE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_PERRE_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_EIES_PERRE_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_EIES_PERRE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_PERRE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_RFOE_MASK                                        (0x00000080U)
#define CSL_FLEXRAY_ERAY_EIES_RFOE_SHIFT                                       (0x00000007U)
#define CSL_FLEXRAY_ERAY_EIES_RFOE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_RFOE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_EFAE_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_EIES_EFAE_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIES_EFAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_EFAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_IIBAE_MASK                                       (0x00000200U)
#define CSL_FLEXRAY_ERAY_EIES_IIBAE_SHIFT                                      (0x00000009U)
#define CSL_FLEXRAY_ERAY_EIES_IIBAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_IIBAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_IOBAE_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_EIES_IOBAE_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_EIES_IOBAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_IOBAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_MHFE_MASK                                        (0x00000800U)
#define CSL_FLEXRAY_ERAY_EIES_MHFE_SHIFT                                       (0x0000000BU)
#define CSL_FLEXRAY_ERAY_EIES_MHFE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_MHFE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_EDAE_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_EIES_EDAE_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIES_EDAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_EDAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_LTVAE_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_EIES_LTVAE_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_EIES_LTVAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_LTVAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_TABAE_MASK                                       (0x00040000U)
#define CSL_FLEXRAY_ERAY_EIES_TABAE_SHIFT                                      (0x00000012U)
#define CSL_FLEXRAY_ERAY_EIES_TABAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_TABAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_EDBE_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_EIES_EDBE_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_EIES_EDBE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_EDBE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_LTVBE_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_EIES_LTVBE_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_EIES_LTVBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_LTVBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_TABBE_MASK                                       (0x04000000U)
#define CSL_FLEXRAY_ERAY_EIES_TABBE_SHIFT                                      (0x0000001AU)
#define CSL_FLEXRAY_ERAY_EIES_TABBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIES_TABBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIES_RESETVAL                                         (0x00000000U)

/* EIER */

#define CSL_FLEXRAY_ERAY_EIER_PEMCE_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIER_PEMCE_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_PEMCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_PEMCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_CNAE_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIER_CNAE_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_EIER_CNAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_CNAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_SFBME_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIER_SFBME_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_EIER_SFBME_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_SFBME_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_SFOE_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIER_SFOE_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_EIER_SFOE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_SFOE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_CCFE_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIER_CCFE_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_EIER_CCFE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_CCFE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_CCLE_MASK                                        (0x00000020U)
#define CSL_FLEXRAY_ERAY_EIER_CCLE_SHIFT                                       (0x00000005U)
#define CSL_FLEXRAY_ERAY_EIER_CCLE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_CCLE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_PERRE_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_EIER_PERRE_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_EIER_PERRE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_PERRE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_RFOE_MASK                                        (0x00000080U)
#define CSL_FLEXRAY_ERAY_EIER_RFOE_SHIFT                                       (0x00000007U)
#define CSL_FLEXRAY_ERAY_EIER_RFOE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_RFOE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_EFAE_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_EIER_EFAE_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_EIER_EFAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_EFAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_IIBAE_MASK                                       (0x00000200U)
#define CSL_FLEXRAY_ERAY_EIER_IIBAE_SHIFT                                      (0x00000009U)
#define CSL_FLEXRAY_ERAY_EIER_IIBAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_IIBAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_IOBAE_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_EIER_IOBAE_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_EIER_IOBAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_IOBAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_MHFE_MASK                                        (0x00000800U)
#define CSL_FLEXRAY_ERAY_EIER_MHFE_SHIFT                                       (0x0000000BU)
#define CSL_FLEXRAY_ERAY_EIER_MHFE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_MHFE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_EDAE_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_EIER_EDAE_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_EIER_EDAE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_EDAE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_LTVAE_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_EIER_LTVAE_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_EIER_LTVAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_LTVAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_TABAE_MASK                                       (0x00040000U)
#define CSL_FLEXRAY_ERAY_EIER_TABAE_SHIFT                                      (0x00000012U)
#define CSL_FLEXRAY_ERAY_EIER_TABAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_TABAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_EDBE_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_EIER_EDBE_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_EIER_EDBE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_EDBE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_LTVBE_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_EIER_LTVBE_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_EIER_LTVBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_LTVBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_TABBE_MASK                                       (0x04000000U)
#define CSL_FLEXRAY_ERAY_EIER_TABBE_SHIFT                                      (0x0000001AU)
#define CSL_FLEXRAY_ERAY_EIER_TABBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_EIER_TABBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_EIER_RESETVAL                                         (0x00000000U)

/* SIES */

#define CSL_FLEXRAY_ERAY_SIES_WSTE_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIES_WSTE_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_WSTE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_WSTE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_CASE_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIES_CASE_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIES_CASE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_CASE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_CYCSE_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIES_CYCSE_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIES_CYCSE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_CYCSE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_TXIE_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIES_TXIE_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_SIES_TXIE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_TXIE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_RXIE_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIES_RXIE_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIES_RXIE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_RXIE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_RFNEE_MASK                                       (0x00000020U)
#define CSL_FLEXRAY_ERAY_SIES_RFNEE_SHIFT                                      (0x00000005U)
#define CSL_FLEXRAY_ERAY_SIES_RFNEE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_RFNEE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_RFCLE_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_SIES_RFCLE_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_SIES_RFCLE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_RFCLE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_NMVCE_MASK                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_SIES_NMVCE_SHIFT                                      (0x00000007U)
#define CSL_FLEXRAY_ERAY_SIES_NMVCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_NMVCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_TI0_MASK                                         (0x00000100U)
#define CSL_FLEXRAY_ERAY_SIES_TI0_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIES_TI0_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_TI0_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_TI1_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_SIES_TI1_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_SIES_TI1_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_TI1_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_TIBCE_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_SIES_TIBCE_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_SIES_TIBCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_TIBCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_TOBCE_MASK                                       (0x00000800U)
#define CSL_FLEXRAY_ERAY_SIES_TOBCE_SHIFT                                      (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SIES_TOBCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_TOBCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_SWEE_MASK                                        (0x00001000U)
#define CSL_FLEXRAY_ERAY_SIES_SWEE_SHIFT                                       (0x0000000CU)
#define CSL_FLEXRAY_ERAY_SIES_SWEE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_SWEE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_SUCSE_MASK                                       (0x00002000U)
#define CSL_FLEXRAY_ERAY_SIES_SUCSE_SHIFT                                      (0x0000000DU)
#define CSL_FLEXRAY_ERAY_SIES_SUCSE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_SUCSE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_MBSIE_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_SIES_MBSIE_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_SIES_MBSIE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_MBSIE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_SDSE_MASK                                        (0x00008000U)
#define CSL_FLEXRAY_ERAY_SIES_SDSE_SHIFT                                       (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SIES_SDSE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_SDSE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_WUPAE_MASK                                       (0x00010000U)
#define CSL_FLEXRAY_ERAY_SIES_WUPAE_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIES_WUPAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_WUPAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_MTSAE_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_SIES_MTSAE_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_SIES_MTSAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_MTSAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_WUPBE_MASK                                       (0x01000000U)
#define CSL_FLEXRAY_ERAY_SIES_WUPBE_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_SIES_WUPBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_WUPBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_MTSBE_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_SIES_MTSBE_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_SIES_MTSBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIES_MTSBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIES_RESETVAL                                         (0x00000000U)

/* SIER */

#define CSL_FLEXRAY_ERAY_SIER_WSTE_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIER_WSTE_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_WSTE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_WSTE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_CASE_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIER_CASE_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_SIER_CASE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_CASE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_CYCSE_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIER_CYCSE_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_SIER_CYCSE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_CYCSE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_TXIE_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIER_TXIE_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_SIER_TXIE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_TXIE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_RXIE_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIER_RXIE_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SIER_RXIE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_RXIE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_RFNEE_MASK                                       (0x00000020U)
#define CSL_FLEXRAY_ERAY_SIER_RFNEE_SHIFT                                      (0x00000005U)
#define CSL_FLEXRAY_ERAY_SIER_RFNEE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_RFNEE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_RFCLE_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_SIER_RFCLE_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_SIER_RFCLE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_RFCLE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_NMVCE_MASK                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_SIER_NMVCE_SHIFT                                      (0x00000007U)
#define CSL_FLEXRAY_ERAY_SIER_NMVCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_NMVCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_TI0_MASK                                         (0x00000100U)
#define CSL_FLEXRAY_ERAY_SIER_TI0_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SIER_TI0_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_TI0_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_TI1_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_SIER_TI1_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_SIER_TI1_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_TI1_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_TIBCE_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_SIER_TIBCE_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_SIER_TIBCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_TIBCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_TOBCE_MASK                                       (0x00000800U)
#define CSL_FLEXRAY_ERAY_SIER_TOBCE_SHIFT                                      (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SIER_TOBCE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_TOBCE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_SWEE_MASK                                        (0x00001000U)
#define CSL_FLEXRAY_ERAY_SIER_SWEE_SHIFT                                       (0x0000000CU)
#define CSL_FLEXRAY_ERAY_SIER_SWEE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_SWEE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_SUCSE_MASK                                       (0x00002000U)
#define CSL_FLEXRAY_ERAY_SIER_SUCSE_SHIFT                                      (0x0000000DU)
#define CSL_FLEXRAY_ERAY_SIER_SUCSE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_SUCSE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_MBSIE_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_SIER_MBSIE_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_SIER_MBSIE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_MBSIE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_SDSE_MASK                                        (0x00008000U)
#define CSL_FLEXRAY_ERAY_SIER_SDSE_SHIFT                                       (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SIER_SDSE_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_SDSE_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_WUPAE_MASK                                       (0x00010000U)
#define CSL_FLEXRAY_ERAY_SIER_WUPAE_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_SIER_WUPAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_WUPAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_MTSAE_MASK                                       (0x00020000U)
#define CSL_FLEXRAY_ERAY_SIER_MTSAE_SHIFT                                      (0x00000011U)
#define CSL_FLEXRAY_ERAY_SIER_MTSAE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_MTSAE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_WUPBE_MASK                                       (0x01000000U)
#define CSL_FLEXRAY_ERAY_SIER_WUPBE_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_SIER_WUPBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_WUPBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_MTSBE_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_SIER_MTSBE_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_SIER_MTSBE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SIER_MTSBE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SIER_RESETVAL                                         (0x00000000U)

/* ILE */

#define CSL_FLEXRAY_ERAY_ILE_EINT_MASK                                         (0x00000003U)
#define CSL_FLEXRAY_ERAY_ILE_EINT_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_ILE_EINT_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ILE_EINT_MAX                                          (0x00000003U)

#define CSL_FLEXRAY_ERAY_ILE_RESETVAL                                          (0x00000000U)

/* T0C */

#define CSL_FLEXRAY_ERAY_T0C_T0RC_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_T0C_T0RC_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_T0C_T0RC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T0C_T0RC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_T0C_T0MS_MASK                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_T0C_T0MS_SHIFT                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_T0C_T0MS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T0C_T0MS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_T0C_T0CC_MASK                                         (0x00007F00U)
#define CSL_FLEXRAY_ERAY_T0C_T0CC_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_T0C_T0CC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T0C_T0CC_MAX                                          (0x0000007FU)

#define CSL_FLEXRAY_ERAY_T0C_T0MO_MASK                                         (0x3FFF0000U)
#define CSL_FLEXRAY_ERAY_T0C_T0MO_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_T0C_T0MO_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T0C_T0MO_MAX                                          (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_T0C_RESETVAL                                          (0x00000000U)

/* T1C */

#define CSL_FLEXRAY_ERAY_T1C_T1RC_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_T1C_T1RC_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_T1C_T1RC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T1C_T1RC_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_T1C_T1MS_MASK                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_T1C_T1MS_SHIFT                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_T1C_T1MS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T1C_T1MS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_T1C_T1MC_MASK                                         (0x3FFF0000U)
#define CSL_FLEXRAY_ERAY_T1C_T1MC_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_T1C_T1MC_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_T1C_T1MC_MAX                                          (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_T1C_RESETVAL                                          (0x00000000U)

/* STPW1 */

#define CSL_FLEXRAY_ERAY_STPW1_ESWT_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_STPW1_ESWT_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_ESWT_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_ESWT_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_STPW1_SWMS_MASK                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_STPW1_SWMS_SHIFT                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_STPW1_SWMS_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_SWMS_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_STPW1_EDGE_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_STPW1_EDGE_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_STPW1_EDGE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_EDGE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_STPW1_SSWT_MASK                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_STPW1_SSWT_SHIFT                                      (0x00000003U)
#define CSL_FLEXRAY_ERAY_STPW1_SSWT_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_SSWT_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_STPW1_EETP_MASK                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_STPW1_EETP_SHIFT                                      (0x00000004U)
#define CSL_FLEXRAY_ERAY_STPW1_EETP_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_EETP_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_STPW1_EINT_MASK                                       (0x00000060U)
#define CSL_FLEXRAY_ERAY_STPW1_EINT_SHIFT                                      (0x00000005U)
#define CSL_FLEXRAY_ERAY_STPW1_EINT_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_EINT_MAX                                        (0x00000003U)

#define CSL_FLEXRAY_ERAY_STPW1_SCCV_MASK                                       (0x00003F00U)
#define CSL_FLEXRAY_ERAY_STPW1_SCCV_SHIFT                                      (0x00000008U)
#define CSL_FLEXRAY_ERAY_STPW1_SCCV_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_SCCV_MAX                                        (0x0000003FU)

#define CSL_FLEXRAY_ERAY_STPW1_SMTV_MASK                                       (0x3FFF0000U)
#define CSL_FLEXRAY_ERAY_STPW1_SMTV_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_STPW1_SMTV_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW1_SMTV_MAX                                        (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_STPW1_RESETVAL                                        (0x00000000U)

/* STPW2 */

#define CSL_FLEXRAY_ERAY_STPW2_SSCVA_MASK                                      (0x000007FFU)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVA_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVA_MAX                                       (0x000007FFU)

#define CSL_FLEXRAY_ERAY_STPW2_SSCVB_MASK                                      (0x07FF0000U)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVB_SHIFT                                     (0x00000010U)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_STPW2_SSCVB_MAX                                       (0x000007FFU)

#define CSL_FLEXRAY_ERAY_STPW2_RESETVAL                                        (0x00000000U)

/* SUCC1 */

#define CSL_FLEXRAY_ERAY_SUCC1_CMD_MASK                                        (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SUCC1_CMD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_CMD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_CMD_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SUCC1_PBSY_MASK                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_SUCC1_PBSY_SHIFT                                      (0x00000007U)
#define CSL_FLEXRAY_ERAY_SUCC1_PBSY_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SUCC1_PBSY_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_TXST_MASK                                       (0x00000100U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXST_SHIFT                                      (0x00000008U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXST_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXST_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_TXSY_MASK                                       (0x00000200U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXSY_SHIFT                                      (0x00000009U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXSY_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_TXSY_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_CSA_MASK                                        (0x0000F800U)
#define CSL_FLEXRAY_ERAY_SUCC1_CSA_SHIFT                                       (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SUCC1_CSA_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_SUCC1_CSA_MAX                                         (0x0000001FU)

#define CSL_FLEXRAY_ERAY_SUCC1_PTA_MASK                                        (0x001F0000U)
#define CSL_FLEXRAY_ERAY_SUCC1_PTA_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_SUCC1_PTA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_PTA_MAX                                         (0x0000001FU)

#define CSL_FLEXRAY_ERAY_SUCC1_WUCS_MASK                                       (0x00200000U)
#define CSL_FLEXRAY_ERAY_SUCC1_WUCS_SHIFT                                      (0x00000015U)
#define CSL_FLEXRAY_ERAY_SUCC1_WUCS_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_WUCS_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_TSM_MASK                                        (0x00400000U)
#define CSL_FLEXRAY_ERAY_SUCC1_TSM_SHIFT                                       (0x00000016U)
#define CSL_FLEXRAY_ERAY_SUCC1_TSM_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SUCC1_TSM_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_HCSE_MASK                                       (0x00800000U)
#define CSL_FLEXRAY_ERAY_SUCC1_HCSE_SHIFT                                      (0x00000017U)
#define CSL_FLEXRAY_ERAY_SUCC1_HCSE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_HCSE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_MTSA_MASK                                       (0x01000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSA_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_MTSB_MASK                                       (0x02000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSB_SHIFT                                      (0x00000019U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_MTSB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_CCHA_MASK                                       (0x04000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHA_SHIFT                                      (0x0000001AU)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHA_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_CCHB_MASK                                       (0x08000000U)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHB_SHIFT                                      (0x0000001BU)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHB_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_SUCC1_CCHB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SUCC1_RESETVAL                                        (0x0C401080U)

/* SUCC2 */

#define CSL_FLEXRAY_ERAY_SUCC2_LT_MASK                                         (0x001FFFFFU)
#define CSL_FLEXRAY_ERAY_SUCC2_LT_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC2_LT_RESETVAL                                     (0x00000504U)
#define CSL_FLEXRAY_ERAY_SUCC2_LT_MAX                                          (0x001FFFFFU)

#define CSL_FLEXRAY_ERAY_SUCC2_LTN_MASK                                        (0x0F000000U)
#define CSL_FLEXRAY_ERAY_SUCC2_LTN_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_SUCC2_LTN_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_SUCC2_LTN_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SUCC2_RESETVAL                                        (0x01000504U)

/* SUCC3 */

#define CSL_FLEXRAY_ERAY_SUCC3_WCP_MASK                                        (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SUCC3_WCP_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC3_WCP_RESETVAL                                    (0x00000011U)
#define CSL_FLEXRAY_ERAY_SUCC3_WCP_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SUCC3_WCF_MASK                                        (0x000000F0U)
#define CSL_FLEXRAY_ERAY_SUCC3_WCF_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SUCC3_WCF_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_SUCC3_WCF_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SUCC3_RESETVAL                                        (0x00000011U)

/* NEMC */

#define CSL_FLEXRAY_ERAY_NEMC_NML_MASK                                         (0x0000000FU)
#define CSL_FLEXRAY_ERAY_NEMC_NML_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_NEMC_NML_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_NEMC_NML_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_NEMC_RESETVAL                                         (0x00000000U)

/* PRTC1 */

#define CSL_FLEXRAY_ERAY_PRTC1_TSST_MASK                                       (0x0000000FU)
#define CSL_FLEXRAY_ERAY_PRTC1_TSST_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_PRTC1_TSST_RESETVAL                                   (0x00000003U)
#define CSL_FLEXRAY_ERAY_PRTC1_TSST_MAX                                        (0x0000000FU)

#define CSL_FLEXRAY_ERAY_PRTC1_CASM_MASK                                       (0x000003F0U)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM_SHIFT                                      (0x00000004U)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM_RESETVAL                                   (0x00000023U)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM_MAX                                        (0x0000003FU)

#define CSL_FLEXRAY_ERAY_PRTC1_CASM6_MASK                                      (0x00000400U)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM6_SHIFT                                     (0x0000000AU)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM6_RESETVAL                                  (0x00000001U)
#define CSL_FLEXRAY_ERAY_PRTC1_CASM6_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_PRTC1_SPP_MASK                                        (0x00003000U)
#define CSL_FLEXRAY_ERAY_PRTC1_SPP_SHIFT                                       (0x0000000CU)
#define CSL_FLEXRAY_ERAY_PRTC1_SPP_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_PRTC1_SPP_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_PRTC1_BRP_MASK                                        (0x0000C000U)
#define CSL_FLEXRAY_ERAY_PRTC1_BRP_SHIFT                                       (0x0000000EU)
#define CSL_FLEXRAY_ERAY_PRTC1_BRP_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_PRTC1_BRP_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_PRTC1_RXW_MASK                                        (0x01FF0000U)
#define CSL_FLEXRAY_ERAY_PRTC1_RXW_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_PRTC1_RXW_RESETVAL                                    (0x0000004CU)
#define CSL_FLEXRAY_ERAY_PRTC1_RXW_MAX                                         (0x000001FFU)

#define CSL_FLEXRAY_ERAY_PRTC1_RWP_MASK                                        (0xFC000000U)
#define CSL_FLEXRAY_ERAY_PRTC1_RWP_SHIFT                                       (0x0000001AU)
#define CSL_FLEXRAY_ERAY_PRTC1_RWP_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_PRTC1_RWP_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_PRTC1_RESETVAL                                        (0x084C0633U)

/* PRTC2 */

#define CSL_FLEXRAY_ERAY_PRTC2_RXI_MASK                                        (0x0000003FU)
#define CSL_FLEXRAY_ERAY_PRTC2_RXI_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_PRTC2_RXI_RESETVAL                                    (0x0000000EU)
#define CSL_FLEXRAY_ERAY_PRTC2_RXI_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_PRTC2_RXL_MASK                                        (0x00003F00U)
#define CSL_FLEXRAY_ERAY_PRTC2_RXL_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_PRTC2_RXL_RESETVAL                                    (0x0000000AU)
#define CSL_FLEXRAY_ERAY_PRTC2_RXL_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_PRTC2_TXI_MASK                                        (0x00FF0000U)
#define CSL_FLEXRAY_ERAY_PRTC2_TXI_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_PRTC2_TXI_RESETVAL                                    (0x0000002DU)
#define CSL_FLEXRAY_ERAY_PRTC2_TXI_MAX                                         (0x000000FFU)

#define CSL_FLEXRAY_ERAY_PRTC2_TXL_MASK                                        (0x3F000000U)
#define CSL_FLEXRAY_ERAY_PRTC2_TXL_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_PRTC2_TXL_RESETVAL                                    (0x0000000FU)
#define CSL_FLEXRAY_ERAY_PRTC2_TXL_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_PRTC2_RESETVAL                                        (0x0F2D0A0EU)

/* MHDC */

#define CSL_FLEXRAY_ERAY_MHDC_SFDL_MASK                                        (0x0000007FU)
#define CSL_FLEXRAY_ERAY_MHDC_SFDL_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDC_SFDL_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDC_SFDL_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_MHDC_SLT_MASK                                         (0x1FFF0000U)
#define CSL_FLEXRAY_ERAY_MHDC_SLT_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_MHDC_SLT_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDC_SLT_MAX                                          (0x00001FFFU)

#define CSL_FLEXRAY_ERAY_MHDC_RESETVAL                                         (0x00000000U)

/* GTUC1 */

#define CSL_FLEXRAY_ERAY_GTUC1_UT_MASK                                         (0x000FFFFFU)
#define CSL_FLEXRAY_ERAY_GTUC1_UT_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC1_UT_RESETVAL                                     (0x00000280U)
#define CSL_FLEXRAY_ERAY_GTUC1_UT_MAX                                          (0x000FFFFFU)

#define CSL_FLEXRAY_ERAY_GTUC1_RESETVAL                                        (0x00000280U)

/* GTUC2 */

#define CSL_FLEXRAY_ERAY_GTUC2_MPC_MASK                                        (0x00003FFFU)
#define CSL_FLEXRAY_ERAY_GTUC2_MPC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC2_MPC_RESETVAL                                    (0x0000000AU)
#define CSL_FLEXRAY_ERAY_GTUC2_MPC_MAX                                         (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_GTUC2_SNM_MASK                                        (0x000F0000U)
#define CSL_FLEXRAY_ERAY_GTUC2_SNM_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC2_SNM_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC2_SNM_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_GTUC2_RESETVAL                                        (0x0002000AU)

/* GTUC3 */

#define CSL_FLEXRAY_ERAY_GTUC3_UIOA_MASK                                       (0x000000FFU)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOA_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOA_MAX                                        (0x000000FFU)

#define CSL_FLEXRAY_ERAY_GTUC3_UIOB_MASK                                       (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOB_SHIFT                                      (0x00000008U)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC3_UIOB_MAX                                        (0x000000FFU)

#define CSL_FLEXRAY_ERAY_GTUC3_MIOA_MASK                                       (0x007F0000U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOA_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOA_RESETVAL                                   (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOA_MAX                                        (0x0000007FU)

#define CSL_FLEXRAY_ERAY_GTUC3_MIOB_MASK                                       (0x7F000000U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOB_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOB_RESETVAL                                   (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC3_MIOB_MAX                                        (0x0000007FU)

#define CSL_FLEXRAY_ERAY_GTUC3_RESETVAL                                        (0x02020000U)

/* GTUC4 */

#define CSL_FLEXRAY_ERAY_GTUC4_NIT_MASK                                        (0x00003FFFU)
#define CSL_FLEXRAY_ERAY_GTUC4_NIT_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC4_NIT_RESETVAL                                    (0x00000007U)
#define CSL_FLEXRAY_ERAY_GTUC4_NIT_MAX                                         (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_GTUC4_OCS_MASK                                        (0x3FFF0000U)
#define CSL_FLEXRAY_ERAY_GTUC4_OCS_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC4_OCS_RESETVAL                                    (0x00000008U)
#define CSL_FLEXRAY_ERAY_GTUC4_OCS_MAX                                         (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_GTUC4_RESETVAL                                        (0x00080007U)

/* GTUC5 */

#define CSL_FLEXRAY_ERAY_GTUC5_DCA_MASK                                        (0x000000FFU)
#define CSL_FLEXRAY_ERAY_GTUC5_DCA_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC5_DCA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC5_DCA_MAX                                         (0x000000FFU)

#define CSL_FLEXRAY_ERAY_GTUC5_DCB_MASK                                        (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_GTUC5_DCB_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_GTUC5_DCB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC5_DCB_MAX                                         (0x000000FFU)

#define CSL_FLEXRAY_ERAY_GTUC5_CDD_MASK                                        (0x001F0000U)
#define CSL_FLEXRAY_ERAY_GTUC5_CDD_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC5_CDD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC5_CDD_MAX                                         (0x0000001FU)

#define CSL_FLEXRAY_ERAY_GTUC5_DEC_MASK                                        (0xFF000000U)
#define CSL_FLEXRAY_ERAY_GTUC5_DEC_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_GTUC5_DEC_RESETVAL                                    (0x0000000EU)
#define CSL_FLEXRAY_ERAY_GTUC5_DEC_MAX                                         (0x000000FFU)

#define CSL_FLEXRAY_ERAY_GTUC5_RESETVAL                                        (0x0E000000U)

/* GTUC6 */

#define CSL_FLEXRAY_ERAY_GTUC6_ASR_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_GTUC6_ASR_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC6_ASR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC6_ASR_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_GTUC6_MOD_MASK                                        (0x07FF0000U)
#define CSL_FLEXRAY_ERAY_GTUC6_MOD_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC6_MOD_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC6_MOD_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_GTUC6_RESETVAL                                        (0x00020000U)

/* GTUC7 */

#define CSL_FLEXRAY_ERAY_GTUC7_SSL_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_GTUC7_SSL_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC7_SSL_RESETVAL                                    (0x00000004U)
#define CSL_FLEXRAY_ERAY_GTUC7_SSL_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_GTUC7_NSS_MASK                                        (0x03FF0000U)
#define CSL_FLEXRAY_ERAY_GTUC7_NSS_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC7_NSS_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC7_NSS_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_GTUC7_RESETVAL                                        (0x00020004U)

/* GTUC8 */

#define CSL_FLEXRAY_ERAY_GTUC8_MSL_MASK                                        (0x0000003FU)
#define CSL_FLEXRAY_ERAY_GTUC8_MSL_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC8_MSL_RESETVAL                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC8_MSL_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_GTUC8_NMS_MASK                                        (0x1FFF0000U)
#define CSL_FLEXRAY_ERAY_GTUC8_NMS_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC8_NMS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC8_NMS_MAX                                         (0x00001FFFU)

#define CSL_FLEXRAY_ERAY_GTUC8_RESETVAL                                        (0x00000002U)

/* GTUC9 */

#define CSL_FLEXRAY_ERAY_GTUC9_APO_MASK                                        (0x0000003FU)
#define CSL_FLEXRAY_ERAY_GTUC9_APO_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC9_APO_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_GTUC9_APO_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_GTUC9_MAPO_MASK                                       (0x00001F00U)
#define CSL_FLEXRAY_ERAY_GTUC9_MAPO_SHIFT                                      (0x00000008U)
#define CSL_FLEXRAY_ERAY_GTUC9_MAPO_RESETVAL                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_GTUC9_MAPO_MAX                                        (0x0000001FU)

#define CSL_FLEXRAY_ERAY_GTUC9_DSI_MASK                                        (0x00030000U)
#define CSL_FLEXRAY_ERAY_GTUC9_DSI_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC9_DSI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC9_DSI_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_GTUC9_RESETVAL                                        (0x00000101U)

/* GTUC10 */

#define CSL_FLEXRAY_ERAY_GTUC10_MOC_MASK                                       (0x00003FFFU)
#define CSL_FLEXRAY_ERAY_GTUC10_MOC_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC10_MOC_RESETVAL                                   (0x00000005U)
#define CSL_FLEXRAY_ERAY_GTUC10_MOC_MAX                                        (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_GTUC10_MRC_MASK                                       (0x07FF0000U)
#define CSL_FLEXRAY_ERAY_GTUC10_MRC_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC10_MRC_RESETVAL                                   (0x00000002U)
#define CSL_FLEXRAY_ERAY_GTUC10_MRC_MAX                                        (0x000007FFU)

#define CSL_FLEXRAY_ERAY_GTUC10_RESETVAL                                       (0x00020005U)

/* GTUC11 */

#define CSL_FLEXRAY_ERAY_GTUC11_EOCC_MASK                                      (0x00000003U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOCC_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOCC_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOCC_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_GTUC11_ERCC_MASK                                      (0x00000300U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERCC_SHIFT                                     (0x00000008U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERCC_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERCC_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_GTUC11_EOC_MASK                                       (0x00070000U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOC_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOC_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_EOC_MAX                                        (0x00000007U)

#define CSL_FLEXRAY_ERAY_GTUC11_ERC_MASK                                       (0x07000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERC_SHIFT                                      (0x00000018U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERC_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_GTUC11_ERC_MAX                                        (0x00000007U)

#define CSL_FLEXRAY_ERAY_GTUC11_RESETVAL                                       (0x00000000U)

/* CCSV */

#define CSL_FLEXRAY_ERAY_CCSV_POCS_MASK                                        (0x0000003FU)
#define CSL_FLEXRAY_ERAY_CCSV_POCS_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_POCS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_POCS_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_CCSV_FSI_MASK                                         (0x00000040U)
#define CSL_FLEXRAY_ERAY_CCSV_FSI_SHIFT                                        (0x00000006U)
#define CSL_FLEXRAY_ERAY_CCSV_FSI_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_FSI_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_CCSV_HRQ_MASK                                         (0x00000080U)
#define CSL_FLEXRAY_ERAY_CCSV_HRQ_SHIFT                                        (0x00000007U)
#define CSL_FLEXRAY_ERAY_CCSV_HRQ_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_HRQ_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_CCSV_SLM_MASK                                         (0x00000300U)
#define CSL_FLEXRAY_ERAY_CCSV_SLM_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_CCSV_SLM_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_SLM_MAX                                          (0x00000003U)

#define CSL_FLEXRAY_ERAY_CCSV_CSNI_MASK                                        (0x00001000U)
#define CSL_FLEXRAY_ERAY_CCSV_CSNI_SHIFT                                       (0x0000000CU)
#define CSL_FLEXRAY_ERAY_CCSV_CSNI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_CSNI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_CCSV_CSAI_MASK                                        (0x00002000U)
#define CSL_FLEXRAY_ERAY_CCSV_CSAI_SHIFT                                       (0x0000000DU)
#define CSL_FLEXRAY_ERAY_CCSV_CSAI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_CSAI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_CCSV_CSI_MASK                                         (0x00004000U)
#define CSL_FLEXRAY_ERAY_CCSV_CSI_SHIFT                                        (0x0000000EU)
#define CSL_FLEXRAY_ERAY_CCSV_CSI_RESETVAL                                     (0x00000001U)
#define CSL_FLEXRAY_ERAY_CCSV_CSI_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_CCSV_WSV_MASK                                         (0x00070000U)
#define CSL_FLEXRAY_ERAY_CCSV_WSV_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_CCSV_WSV_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_WSV_MAX                                          (0x00000007U)

#define CSL_FLEXRAY_ERAY_CCSV_RCA_MASK                                         (0x00F80000U)
#define CSL_FLEXRAY_ERAY_CCSV_RCA_SHIFT                                        (0x00000013U)
#define CSL_FLEXRAY_ERAY_CCSV_RCA_RESETVAL                                     (0x00000002U)
#define CSL_FLEXRAY_ERAY_CCSV_RCA_MAX                                          (0x0000001FU)

#define CSL_FLEXRAY_ERAY_CCSV_PSL_MASK                                         (0x3F000000U)
#define CSL_FLEXRAY_ERAY_CCSV_PSL_SHIFT                                        (0x00000018U)
#define CSL_FLEXRAY_ERAY_CCSV_PSL_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCSV_PSL_MAX                                          (0x0000003FU)

#define CSL_FLEXRAY_ERAY_CCSV_RESETVAL                                         (0x00104000U)

/* CCEV */

#define CSL_FLEXRAY_ERAY_CCEV_CCFC_MASK                                        (0x0000000FU)
#define CSL_FLEXRAY_ERAY_CCEV_CCFC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCEV_CCFC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCEV_CCFC_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_CCEV_ERRM_MASK                                        (0x000000C0U)
#define CSL_FLEXRAY_ERAY_CCEV_ERRM_SHIFT                                       (0x00000006U)
#define CSL_FLEXRAY_ERAY_CCEV_ERRM_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCEV_ERRM_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_CCEV_PTAC_MASK                                        (0x00001F00U)
#define CSL_FLEXRAY_ERAY_CCEV_PTAC_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_CCEV_PTAC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_CCEV_PTAC_MAX                                         (0x0000001FU)

#define CSL_FLEXRAY_ERAY_CCEV_RESETVAL                                         (0x00000000U)

/* SCV */

#define CSL_FLEXRAY_ERAY_SCV_SCCA_MASK                                         (0x000007FFU)
#define CSL_FLEXRAY_ERAY_SCV_SCCA_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_SCV_SCCA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SCV_SCCA_MAX                                          (0x000007FFU)

#define CSL_FLEXRAY_ERAY_SCV_SCCB_MASK                                         (0x07FF0000U)
#define CSL_FLEXRAY_ERAY_SCV_SCCB_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SCV_SCCB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SCV_SCCB_MAX                                          (0x000007FFU)

#define CSL_FLEXRAY_ERAY_SCV_RESETVAL                                          (0x00000000U)

/* MTCCV */

#define CSL_FLEXRAY_ERAY_MTCCV_MTV_MASK                                        (0x00003FFFU)
#define CSL_FLEXRAY_ERAY_MTCCV_MTV_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MTCCV_MTV_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MTCCV_MTV_MAX                                         (0x00003FFFU)

#define CSL_FLEXRAY_ERAY_MTCCV_CCV_MASK                                        (0x003F0000U)
#define CSL_FLEXRAY_ERAY_MTCCV_CCV_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_MTCCV_CCV_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MTCCV_CCV_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_MTCCV_RESETVAL                                        (0x00000000U)

/* RCV */

#define CSL_FLEXRAY_ERAY_RCV_RCV_MASK                                          (0x00000FFFU)
#define CSL_FLEXRAY_ERAY_RCV_RCV_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_RCV_RCV_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_RCV_RCV_MAX                                           (0x00000FFFU)

#define CSL_FLEXRAY_ERAY_RCV_RESETVAL                                          (0x00000000U)

/* OCV */

#define CSL_FLEXRAY_ERAY_OCV_OCV_MASK                                          (0x0007FFFFU)
#define CSL_FLEXRAY_ERAY_OCV_OCV_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_OCV_OCV_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OCV_OCV_MAX                                           (0x0007FFFFU)

#define CSL_FLEXRAY_ERAY_OCV_RESETVAL                                          (0x00000000U)

/* SFS */

#define CSL_FLEXRAY_ERAY_SFS_VSAE_MASK                                         (0x0000000FU)
#define CSL_FLEXRAY_ERAY_SFS_VSAE_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_VSAE_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_VSAE_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SFS_VSAO_MASK                                         (0x000000F0U)
#define CSL_FLEXRAY_ERAY_SFS_VSAO_SHIFT                                        (0x00000004U)
#define CSL_FLEXRAY_ERAY_SFS_VSAO_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_VSAO_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SFS_VSBE_MASK                                         (0x00000F00U)
#define CSL_FLEXRAY_ERAY_SFS_VSBE_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_SFS_VSBE_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_VSBE_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SFS_VSBO_MASK                                         (0x0000F000U)
#define CSL_FLEXRAY_ERAY_SFS_VSBO_SHIFT                                        (0x0000000CU)
#define CSL_FLEXRAY_ERAY_SFS_VSBO_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_VSBO_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_SFS_MOCS_MASK                                         (0x00010000U)
#define CSL_FLEXRAY_ERAY_SFS_MOCS_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_SFS_MOCS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_MOCS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SFS_OCLR_MASK                                         (0x00020000U)
#define CSL_FLEXRAY_ERAY_SFS_OCLR_SHIFT                                        (0x00000011U)
#define CSL_FLEXRAY_ERAY_SFS_OCLR_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_OCLR_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SFS_MRCS_MASK                                         (0x00040000U)
#define CSL_FLEXRAY_ERAY_SFS_MRCS_SHIFT                                        (0x00000012U)
#define CSL_FLEXRAY_ERAY_SFS_MRCS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_MRCS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SFS_RCLR_MASK                                         (0x00080000U)
#define CSL_FLEXRAY_ERAY_SFS_RCLR_SHIFT                                        (0x00000013U)
#define CSL_FLEXRAY_ERAY_SFS_RCLR_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_SFS_RCLR_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_SFS_RESETVAL                                          (0x00000000U)

/* SWNIT */

#define CSL_FLEXRAY_ERAY_SWNIT_SESA_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESA_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SBSA_MASK                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSA_SHIFT                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_TCSA_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSA_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SESB_MASK                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESB_SHIFT                                      (0x00000003U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SESB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SBSB_MASK                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSB_SHIFT                                      (0x00000004U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBSB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_TCSB_MASK                                       (0x00000020U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSB_SHIFT                                      (0x00000005U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_TCSB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_MTSA_MASK                                       (0x00000040U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSA_SHIFT                                      (0x00000006U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_MTSB_MASK                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSB_SHIFT                                      (0x00000007U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_MTSB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SENA_MASK                                       (0x00000100U)
#define CSL_FLEXRAY_ERAY_SWNIT_SENA_SHIFT                                      (0x00000008U)
#define CSL_FLEXRAY_ERAY_SWNIT_SENA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SENA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SBNA_MASK                                       (0x00000200U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNA_SHIFT                                      (0x00000009U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SENB_MASK                                       (0x00000400U)
#define CSL_FLEXRAY_ERAY_SWNIT_SENB_SHIFT                                      (0x0000000AU)
#define CSL_FLEXRAY_ERAY_SWNIT_SENB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SENB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_SBNB_MASK                                       (0x00000800U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNB_SHIFT                                      (0x0000000BU)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_SWNIT_SBNB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_SWNIT_RESETVAL                                        (0x00000000U)

/* ACS */

#define CSL_FLEXRAY_ERAY_ACS_VFRA_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_ACS_VFRA_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_VFRA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_VFRA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_SEDA_MASK                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_ACS_SEDA_SHIFT                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_ACS_SEDA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_SEDA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_CEDA_MASK                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_ACS_CEDA_SHIFT                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_ACS_CEDA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_CEDA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_CIA_MASK                                          (0x00000008U)
#define CSL_FLEXRAY_ERAY_ACS_CIA_SHIFT                                         (0x00000003U)
#define CSL_FLEXRAY_ERAY_ACS_CIA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_CIA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_SBVA_MASK                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_ACS_SBVA_SHIFT                                        (0x00000004U)
#define CSL_FLEXRAY_ERAY_ACS_SBVA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_SBVA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_VFRB_MASK                                         (0x00000100U)
#define CSL_FLEXRAY_ERAY_ACS_VFRB_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_ACS_VFRB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_VFRB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_SEDB_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_ACS_SEDB_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_ACS_SEDB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_SEDB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_CEDB_MASK                                         (0x00000400U)
#define CSL_FLEXRAY_ERAY_ACS_CEDB_SHIFT                                        (0x0000000AU)
#define CSL_FLEXRAY_ERAY_ACS_CEDB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_CEDB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_CIB_MASK                                          (0x00000800U)
#define CSL_FLEXRAY_ERAY_ACS_CIB_SHIFT                                         (0x0000000BU)
#define CSL_FLEXRAY_ERAY_ACS_CIB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_CIB_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_SBVB_MASK                                         (0x00001000U)
#define CSL_FLEXRAY_ERAY_ACS_SBVB_SHIFT                                        (0x0000000CU)
#define CSL_FLEXRAY_ERAY_ACS_SBVB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_ACS_SBVB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_ACS_RESETVAL                                          (0x00000000U)

/* ESID1 */

#define CSL_FLEXRAY_ERAY_ESID1_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID1_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID1_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID1_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID1_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID1_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID1_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID1_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID1_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID1_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID1_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID1_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID1_RESETVAL                                        (0x00000000U)

/* ESID2 */

#define CSL_FLEXRAY_ERAY_ESID2_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID2_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID2_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID2_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID2_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID2_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID2_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID2_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID2_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID2_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID2_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID2_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID2_RESETVAL                                        (0x00000000U)

/* ESID3 */

#define CSL_FLEXRAY_ERAY_ESID3_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID3_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID3_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID3_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID3_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID3_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID3_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID3_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID3_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID3_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID3_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID3_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID3_RESETVAL                                        (0x00000000U)

/* ESID4 */

#define CSL_FLEXRAY_ERAY_ESID4_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID4_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID4_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID4_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID4_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID4_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID4_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID4_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID4_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID4_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID4_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID4_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID4_RESETVAL                                        (0x00000000U)

/* ESID5 */

#define CSL_FLEXRAY_ERAY_ESID5_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID5_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID5_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID5_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID5_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID5_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID5_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID5_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID5_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID5_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID5_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID5_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID5_RESETVAL                                        (0x00000000U)

/* ESID6 */

#define CSL_FLEXRAY_ERAY_ESID6_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID6_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID6_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID6_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID6_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID6_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID6_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID6_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID6_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID6_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID6_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID6_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID6_RESETVAL                                        (0x00000000U)

/* ESID7 */

#define CSL_FLEXRAY_ERAY_ESID7_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID7_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID7_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID7_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID7_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID7_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID7_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID7_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID7_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID7_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID7_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID7_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID7_RESETVAL                                        (0x00000000U)

/* ESID8 */

#define CSL_FLEXRAY_ERAY_ESID8_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID8_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID8_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID8_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID8_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID8_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID8_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID8_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID8_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID8_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID8_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID8_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID8_RESETVAL                                        (0x00000000U)

/* ESID9 */

#define CSL_FLEXRAY_ERAY_ESID9_EID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID9_EID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID9_EID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID9_EID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID9_RXEA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID9_RXEA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID9_RXEA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID9_RXEA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID9_RXEB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID9_RXEB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID9_RXEB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID9_RXEB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID9_RESETVAL                                        (0x00000000U)

/* ESID10 */

#define CSL_FLEXRAY_ERAY_ESID10_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID10_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID10_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID10_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID10_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID10_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID10_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID10_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID10_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID10_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID10_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID10_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID10_RESETVAL                                       (0x00000000U)

/* ESID11 */

#define CSL_FLEXRAY_ERAY_ESID11_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID11_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID11_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID11_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID11_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID11_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID11_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID11_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID11_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID11_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID11_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID11_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID11_RESETVAL                                       (0x00000000U)

/* ESID12 */

#define CSL_FLEXRAY_ERAY_ESID12_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID12_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID12_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID12_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID12_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID12_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID12_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID12_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID12_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID12_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID12_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID12_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID12_RESETVAL                                       (0x00000000U)

/* ESID13 */

#define CSL_FLEXRAY_ERAY_ESID13_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID13_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID13_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID13_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID13_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID13_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID13_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID13_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID13_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID13_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID13_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID13_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID13_RESETVAL                                       (0x00000000U)

/* ESID14 */

#define CSL_FLEXRAY_ERAY_ESID14_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID14_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID14_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID14_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID14_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID14_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID14_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID14_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID14_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID14_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID14_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID14_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID14_RESETVAL                                       (0x00000000U)

/* ESID15 */

#define CSL_FLEXRAY_ERAY_ESID15_EID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_ESID15_EID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID15_EID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID15_EID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_ESID15_RXEA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_ESID15_RXEA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_ESID15_RXEA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID15_RXEA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID15_RXEB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_ESID15_RXEB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_ESID15_RXEB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_ESID15_RXEB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_ESID15_RESETVAL                                       (0x00000000U)

/* OSID1 */

#define CSL_FLEXRAY_ERAY_OSID1_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID1_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID1_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID1_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID1_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID1_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID1_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID1_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID1_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID1_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID1_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID1_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID1_RESETVAL                                        (0x00000000U)

/* OSID2 */

#define CSL_FLEXRAY_ERAY_OSID2_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID2_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID2_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID2_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID2_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID2_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID2_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID2_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID2_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID2_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID2_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID2_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID2_RESETVAL                                        (0x00000000U)

/* OSID3 */

#define CSL_FLEXRAY_ERAY_OSID3_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID3_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID3_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID3_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID3_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID3_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID3_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID3_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID3_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID3_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID3_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID3_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID3_RESETVAL                                        (0x00000000U)

/* OSID4 */

#define CSL_FLEXRAY_ERAY_OSID4_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID4_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID4_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID4_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID4_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID4_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID4_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID4_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID4_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID4_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID4_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID4_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID4_RESETVAL                                        (0x00000000U)

/* OSID5 */

#define CSL_FLEXRAY_ERAY_OSID5_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID5_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID5_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID5_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID5_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID5_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID5_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID5_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID5_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID5_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID5_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID5_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID5_RESETVAL                                        (0x00000000U)

/* OSID6 */

#define CSL_FLEXRAY_ERAY_OSID6_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID6_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID6_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID6_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID6_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID6_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID6_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID6_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID6_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID6_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID6_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID6_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID6_RESETVAL                                        (0x00000000U)

/* OSID7 */

#define CSL_FLEXRAY_ERAY_OSID7_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID7_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID7_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID7_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID7_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID7_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID7_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID7_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID7_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID7_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID7_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID7_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID7_RESETVAL                                        (0x00000000U)

/* OSID8 */

#define CSL_FLEXRAY_ERAY_OSID8_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID8_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID8_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID8_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID8_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID8_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID8_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID8_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID8_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID8_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID8_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID8_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID8_RESETVAL                                        (0x00000000U)

/* OSID9 */

#define CSL_FLEXRAY_ERAY_OSID9_OID_MASK                                        (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID9_OID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID9_OID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID9_OID_MAX                                         (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID9_RXOA_MASK                                       (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID9_RXOA_SHIFT                                      (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID9_RXOA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID9_RXOA_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID9_RXOB_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID9_RXOB_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID9_RXOB_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID9_RXOB_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID9_RESETVAL                                        (0x00000000U)

/* OSID10 */

#define CSL_FLEXRAY_ERAY_OSID10_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID10_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID10_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID10_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID10_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID10_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID10_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID10_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID10_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID10_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID10_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID10_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID10_RESETVAL                                       (0x00000000U)

/* OSID11 */

#define CSL_FLEXRAY_ERAY_OSID11_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID11_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID11_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID11_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID11_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID11_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID11_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID11_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID11_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID11_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID11_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID11_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID11_RESETVAL                                       (0x00000000U)

/* OSID12 */

#define CSL_FLEXRAY_ERAY_OSID12_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID12_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID12_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID12_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID12_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID12_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID12_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID12_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID12_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID12_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID12_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID12_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID12_RESETVAL                                       (0x00000000U)

/* OSID13 */

#define CSL_FLEXRAY_ERAY_OSID13_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID13_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID13_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID13_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID13_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID13_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID13_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID13_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID13_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID13_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID13_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID13_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID13_RESETVAL                                       (0x00000000U)

/* OSID14 */

#define CSL_FLEXRAY_ERAY_OSID14_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID14_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID14_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID14_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID14_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID14_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID14_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID14_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID14_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID14_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID14_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID14_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID14_RESETVAL                                       (0x00000000U)

/* OSID15 */

#define CSL_FLEXRAY_ERAY_OSID15_OID_MASK                                       (0x000003FFU)
#define CSL_FLEXRAY_ERAY_OSID15_OID_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID15_OID_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID15_OID_MAX                                        (0x000003FFU)

#define CSL_FLEXRAY_ERAY_OSID15_RXOA_MASK                                      (0x00004000U)
#define CSL_FLEXRAY_ERAY_OSID15_RXOA_SHIFT                                     (0x0000000EU)
#define CSL_FLEXRAY_ERAY_OSID15_RXOA_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID15_RXOA_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID15_RXOB_MASK                                      (0x00008000U)
#define CSL_FLEXRAY_ERAY_OSID15_RXOB_SHIFT                                     (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OSID15_RXOB_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_OSID15_RXOB_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_OSID15_RESETVAL                                       (0x00000000U)

/* NMV1 */

#define CSL_FLEXRAY_ERAY_NMV1_NM_MASK                                          (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NMV1_NM_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV1_NM_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV1_NM_MAX                                           (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NMV1_RESETVAL                                         (0x00000000U)

/* NMV2 */

#define CSL_FLEXRAY_ERAY_NMV2_NM_MASK                                          (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NMV2_NM_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV2_NM_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV2_NM_MAX                                           (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NMV2_RESETVAL                                         (0x00000000U)

/* NMV3 */

#define CSL_FLEXRAY_ERAY_NMV3_NM_MASK                                          (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NMV3_NM_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV3_NM_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_NMV3_NM_MAX                                           (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NMV3_RESETVAL                                         (0x00000000U)

/* MRC */

#define CSL_FLEXRAY_ERAY_MRC_FDB_MASK                                          (0x000000FFU)
#define CSL_FLEXRAY_ERAY_MRC_FDB_SHIFT                                         (0x00000000U)
#define CSL_FLEXRAY_ERAY_MRC_FDB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MRC_FDB_MAX                                           (0x000000FFU)

#define CSL_FLEXRAY_ERAY_MRC_FFB_MASK                                          (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_MRC_FFB_SHIFT                                         (0x00000008U)
#define CSL_FLEXRAY_ERAY_MRC_FFB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MRC_FFB_MAX                                           (0x000000FFU)

#define CSL_FLEXRAY_ERAY_MRC_LCB_MASK                                          (0x00FF0000U)
#define CSL_FLEXRAY_ERAY_MRC_LCB_SHIFT                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_MRC_LCB_RESETVAL                                      (0x00000080U)
#define CSL_FLEXRAY_ERAY_MRC_LCB_MAX                                           (0x000000FFU)

#define CSL_FLEXRAY_ERAY_MRC_SEC_MASK                                          (0x03000000U)
#define CSL_FLEXRAY_ERAY_MRC_SEC_SHIFT                                         (0x00000018U)
#define CSL_FLEXRAY_ERAY_MRC_SEC_RESETVAL                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_MRC_SEC_MAX                                           (0x00000003U)

#define CSL_FLEXRAY_ERAY_MRC_SPLM_MASK                                         (0x04000000U)
#define CSL_FLEXRAY_ERAY_MRC_SPLM_SHIFT                                        (0x0000001AU)
#define CSL_FLEXRAY_ERAY_MRC_SPLM_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MRC_SPLM_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MRC_RESETVAL                                          (0x01800000U)

/* FRF */

#define CSL_FLEXRAY_ERAY_FRF_CH_MASK                                           (0x00000003U)
#define CSL_FLEXRAY_ERAY_FRF_CH_SHIFT                                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_FRF_CH_RESETVAL                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_FRF_CH_MAX                                            (0x00000003U)

#define CSL_FLEXRAY_ERAY_FRF_FID_MASK                                          (0x00001FFCU)
#define CSL_FLEXRAY_ERAY_FRF_FID_SHIFT                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_FRF_FID_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_FRF_FID_MAX                                           (0x000007FFU)

#define CSL_FLEXRAY_ERAY_FRF_CYF_MASK                                          (0x007F0000U)
#define CSL_FLEXRAY_ERAY_FRF_CYF_SHIFT                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_FRF_CYF_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_FRF_CYF_MAX                                           (0x0000007FU)

#define CSL_FLEXRAY_ERAY_FRF_RSS_MASK                                          (0x00800000U)
#define CSL_FLEXRAY_ERAY_FRF_RSS_SHIFT                                         (0x00000017U)
#define CSL_FLEXRAY_ERAY_FRF_RSS_RESETVAL                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_FRF_RSS_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_FRF_RNF_MASK                                          (0x01000000U)
#define CSL_FLEXRAY_ERAY_FRF_RNF_SHIFT                                         (0x00000018U)
#define CSL_FLEXRAY_ERAY_FRF_RNF_RESETVAL                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_FRF_RNF_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_FRF_RESETVAL                                          (0x01800000U)

/* FRFM */

#define CSL_FLEXRAY_ERAY_FRFM_MFID_MASK                                        (0x00001FFCU)
#define CSL_FLEXRAY_ERAY_FRFM_MFID_SHIFT                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_FRFM_MFID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_FRFM_MFID_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_FRFM_RESETVAL                                         (0x00000000U)

/* FCL */

#define CSL_FLEXRAY_ERAY_FCL_CL_MASK                                           (0x000000FFU)
#define CSL_FLEXRAY_ERAY_FCL_CL_SHIFT                                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_FCL_CL_RESETVAL                                       (0x00000080U)
#define CSL_FLEXRAY_ERAY_FCL_CL_MAX                                            (0x000000FFU)

#define CSL_FLEXRAY_ERAY_FCL_RESETVAL                                          (0x00000080U)

/* MHDS */

#define CSL_FLEXRAY_ERAY_MHDS_PIBF_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_MHDS_PIBF_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_PIBF_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_PIBF_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_POBF_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_MHDS_POBF_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_MHDS_POBF_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_POBF_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_PMR_MASK                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_MHDS_PMR_SHIFT                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_MHDS_PMR_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_PMR_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_PTBF_MASK                                        (0x00000018U)
#define CSL_FLEXRAY_ERAY_MHDS_PTBF_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_MHDS_PTBF_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_PTBF_MAX                                         (0x00000003U)

#define CSL_FLEXRAY_ERAY_MHDS_FMBD_MASK                                        (0x00000020U)
#define CSL_FLEXRAY_ERAY_MHDS_FMBD_SHIFT                                       (0x00000005U)
#define CSL_FLEXRAY_ERAY_MHDS_FMBD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_FMBD_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_MFMB_MASK                                        (0x00000040U)
#define CSL_FLEXRAY_ERAY_MHDS_MFMB_SHIFT                                       (0x00000006U)
#define CSL_FLEXRAY_ERAY_MHDS_MFMB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_MFMB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_CRAM_MASK                                        (0x00000080U)
#define CSL_FLEXRAY_ERAY_MHDS_CRAM_SHIFT                                       (0x00000007U)
#define CSL_FLEXRAY_ERAY_MHDS_CRAM_RESETVAL                                    (0x00000001U)
#define CSL_FLEXRAY_ERAY_MHDS_CRAM_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDS_FMB_MASK                                         (0x00007F00U)
#define CSL_FLEXRAY_ERAY_MHDS_FMB_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_MHDS_FMB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_FMB_MAX                                          (0x0000007FU)

#define CSL_FLEXRAY_ERAY_MHDS_MBT_MASK                                         (0x007F0000U)
#define CSL_FLEXRAY_ERAY_MHDS_MBT_SHIFT                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_MHDS_MBT_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_MBT_MAX                                          (0x0000007FU)

#define CSL_FLEXRAY_ERAY_MHDS_MBU_MASK                                         (0x7F000000U)
#define CSL_FLEXRAY_ERAY_MHDS_MBU_SHIFT                                        (0x00000018U)
#define CSL_FLEXRAY_ERAY_MHDS_MBU_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDS_MBU_MAX                                          (0x0000007FU)

#define CSL_FLEXRAY_ERAY_MHDS_RESETVAL                                         (0x00000080U)

/* LDTS */

#define CSL_FLEXRAY_ERAY_LDTS_LDTA_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_LDTS_LDTA_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_LDTS_LDTA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_LDTS_LDTA_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_LDTS_LDTB_MASK                                        (0x07FF0000U)
#define CSL_FLEXRAY_ERAY_LDTS_LDTB_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_LDTS_LDTB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_LDTS_LDTB_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_LDTS_RESETVAL                                         (0x00000000U)

/* FSR */

#define CSL_FLEXRAY_ERAY_FSR_RFNE_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_FSR_RFNE_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_FSR_RFNE_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_FSR_RFNE_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_FSR_RFCL_MASK                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_FSR_RFCL_SHIFT                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_FSR_RFCL_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_FSR_RFCL_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_FSR_RFO_MASK                                          (0x00000004U)
#define CSL_FLEXRAY_ERAY_FSR_RFO_SHIFT                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_FSR_RFO_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_FSR_RFO_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_FSR_RFFL_MASK                                         (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_FSR_RFFL_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_FSR_RFFL_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_FSR_RFFL_MAX                                          (0x000000FFU)

#define CSL_FLEXRAY_ERAY_FSR_RESETVAL                                          (0x00000000U)

/* MHDF */

#define CSL_FLEXRAY_ERAY_MHDF_SNUA_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUA_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_SNUB_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUB_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_SNUB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_FNFA_MASK                                        (0x00000004U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFA_SHIFT                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_FNFB_MASK                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFB_SHIFT                                       (0x00000003U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_FNFB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_TBFA_MASK                                        (0x00000010U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFA_SHIFT                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_TBFB_MASK                                        (0x00000020U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFB_SHIFT                                       (0x00000005U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_TBFB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_TNSA_MASK                                        (0x00000040U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSA_SHIFT                                       (0x00000006U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_TNSB_MASK                                        (0x00000080U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSB_SHIFT                                       (0x00000007U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_TNSB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_WAHP_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_MHDF_WAHP_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_MHDF_WAHP_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MHDF_WAHP_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_MHDF_RESETVAL                                         (0x00000000U)

/* TXRQ1 */

#define CSL_FLEXRAY_ERAY_TXRQ1_TXR_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TXRQ1_TXR_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ1_TXR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ1_TXR_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TXRQ1_RESETVAL                                        (0x00000000U)

/* TXRQ2 */

#define CSL_FLEXRAY_ERAY_TXRQ2_TXR_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TXRQ2_TXR_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ2_TXR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ2_TXR_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TXRQ2_RESETVAL                                        (0x00000000U)

/* TXRQ3 */

#define CSL_FLEXRAY_ERAY_TXRQ3_TXR_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TXRQ3_TXR_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ3_TXR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ3_TXR_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TXRQ3_RESETVAL                                        (0x00000000U)

/* TXRQ4 */

#define CSL_FLEXRAY_ERAY_TXRQ4_TXR_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TXRQ4_TXR_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ4_TXR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TXRQ4_TXR_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TXRQ4_RESETVAL                                        (0x00000000U)

/* NDAT1 */

#define CSL_FLEXRAY_ERAY_NDAT1_ND_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NDAT1_ND_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT1_ND_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT1_ND_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NDAT1_RESETVAL                                        (0x00000000U)

/* NDAT2 */

#define CSL_FLEXRAY_ERAY_NDAT2_ND_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NDAT2_ND_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT2_ND_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT2_ND_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NDAT2_RESETVAL                                        (0x00000000U)

/* NDAT3 */

#define CSL_FLEXRAY_ERAY_NDAT3_ND_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NDAT3_ND_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT3_ND_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT3_ND_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NDAT3_RESETVAL                                        (0x00000000U)

/* NDAT4 */

#define CSL_FLEXRAY_ERAY_NDAT4_ND_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_NDAT4_ND_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT4_ND_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_NDAT4_ND_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_NDAT4_RESETVAL                                        (0x00000000U)

/* MBSC1 */

#define CSL_FLEXRAY_ERAY_MBSC1_MBC_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_MBSC1_MBC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC1_MBC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC1_MBC_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_MBSC1_RESETVAL                                        (0x00000000U)

/* MBSC2 */

#define CSL_FLEXRAY_ERAY_MBSC2_MBC_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_MBSC2_MBC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC2_MBC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC2_MBC_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_MBSC2_RESETVAL                                        (0x00000000U)

/* MBSC3 */

#define CSL_FLEXRAY_ERAY_MBSC3_MBC_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_MBSC3_MBC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC3_MBC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC3_MBC_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_MBSC3_RESETVAL                                        (0x00000000U)

/* MBSC4 */

#define CSL_FLEXRAY_ERAY_MBSC4_MBC_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_MBSC4_MBC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC4_MBC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBSC4_MBC_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_MBSC4_RESETVAL                                        (0x00000000U)

/* CREL */

#define CSL_FLEXRAY_ERAY_CREL_DAY_MASK                                         (0x000000FFU)
#define CSL_FLEXRAY_ERAY_CREL_DAY_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_CREL_DAY_RESETVAL                                     (0x00000006U)
#define CSL_FLEXRAY_ERAY_CREL_DAY_MAX                                          (0x000000FFU)

#define CSL_FLEXRAY_ERAY_CREL_MON_MASK                                         (0x0000FF00U)
#define CSL_FLEXRAY_ERAY_CREL_MON_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_CREL_MON_RESETVAL                                     (0x00000002U)
#define CSL_FLEXRAY_ERAY_CREL_MON_MAX                                          (0x000000FFU)

#define CSL_FLEXRAY_ERAY_CREL_YEAR_MASK                                        (0x000F0000U)
#define CSL_FLEXRAY_ERAY_CREL_YEAR_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_CREL_YEAR_RESETVAL                                    (0x00000009U)
#define CSL_FLEXRAY_ERAY_CREL_YEAR_MAX                                         (0x0000000FU)

#define CSL_FLEXRAY_ERAY_CREL_STEP_MASK                                        (0x0FF00000U)
#define CSL_FLEXRAY_ERAY_CREL_STEP_SHIFT                                       (0x00000014U)
#define CSL_FLEXRAY_ERAY_CREL_STEP_RESETVAL                                    (0x00000003U)
#define CSL_FLEXRAY_ERAY_CREL_STEP_MAX                                         (0x000000FFU)

#define CSL_FLEXRAY_ERAY_CREL_REL_MASK                                         (0xF0000000U)
#define CSL_FLEXRAY_ERAY_CREL_REL_SHIFT                                        (0x0000001CU)
#define CSL_FLEXRAY_ERAY_CREL_REL_RESETVAL                                     (0x00000001U)
#define CSL_FLEXRAY_ERAY_CREL_REL_MAX                                          (0x0000000FU)

#define CSL_FLEXRAY_ERAY_CREL_RESETVAL                                         (0x10390206U)

/* ENDN */

#define CSL_FLEXRAY_ERAY_ENDN_ETV_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_ENDN_ETV_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_ENDN_ETV_RESETVAL                                     (0x87654321U)
#define CSL_FLEXRAY_ERAY_ENDN_ETV_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_ENDN_RESETVAL                                         (0x87654321U)

/* WRDS1 */

#define CSL_FLEXRAY_ERAY_WRDS1_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS1_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS1_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS1_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS1_RESETVAL                                        (0x00000000U)

/* WRDS2 */

#define CSL_FLEXRAY_ERAY_WRDS2_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS2_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS2_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS2_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS2_RESETVAL                                        (0x00000000U)

/* WRDS3 */

#define CSL_FLEXRAY_ERAY_WRDS3_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS3_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS3_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS3_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS3_RESETVAL                                        (0x00000000U)

/* WRDS4 */

#define CSL_FLEXRAY_ERAY_WRDS4_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS4_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS4_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS4_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS4_RESETVAL                                        (0x00000000U)

/* WRDS5 */

#define CSL_FLEXRAY_ERAY_WRDS5_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS5_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS5_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS5_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS5_RESETVAL                                        (0x00000000U)

/* WRDS6 */

#define CSL_FLEXRAY_ERAY_WRDS6_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS6_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS6_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS6_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS6_RESETVAL                                        (0x00000000U)

/* WRDS7 */

#define CSL_FLEXRAY_ERAY_WRDS7_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS7_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS7_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS7_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS7_RESETVAL                                        (0x00000000U)

/* WRDS8 */

#define CSL_FLEXRAY_ERAY_WRDS8_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS8_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS8_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS8_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS8_RESETVAL                                        (0x00000000U)

/* WRDS9 */

#define CSL_FLEXRAY_ERAY_WRDS9_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS9_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS9_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS9_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS9_RESETVAL                                        (0x00000000U)

/* WRDS10 */

#define CSL_FLEXRAY_ERAY_WRDS10_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS10_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS10_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS10_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS10_RESETVAL                                       (0x00000000U)

/* WRDS11 */

#define CSL_FLEXRAY_ERAY_WRDS11_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS11_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS11_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS11_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS11_RESETVAL                                       (0x00000000U)

/* WRDS12 */

#define CSL_FLEXRAY_ERAY_WRDS12_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS12_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS12_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS12_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS12_RESETVAL                                       (0x00000000U)

/* WRDS13 */

#define CSL_FLEXRAY_ERAY_WRDS13_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS13_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS13_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS13_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS13_RESETVAL                                       (0x00000000U)

/* WRDS14 */

#define CSL_FLEXRAY_ERAY_WRDS14_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS14_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS14_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS14_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS14_RESETVAL                                       (0x00000000U)

/* WRDS15 */

#define CSL_FLEXRAY_ERAY_WRDS15_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS15_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS15_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS15_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS15_RESETVAL                                       (0x00000000U)

/* WRDS16 */

#define CSL_FLEXRAY_ERAY_WRDS16_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS16_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS16_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS16_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS16_RESETVAL                                       (0x00000000U)

/* WRDS17 */

#define CSL_FLEXRAY_ERAY_WRDS17_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS17_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS17_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS17_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS17_RESETVAL                                       (0x00000000U)

/* WRDS18 */

#define CSL_FLEXRAY_ERAY_WRDS18_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS18_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS18_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS18_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS18_RESETVAL                                       (0x00000000U)

/* WRDS19 */

#define CSL_FLEXRAY_ERAY_WRDS19_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS19_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS19_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS19_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS19_RESETVAL                                       (0x00000000U)

/* WRDS20 */

#define CSL_FLEXRAY_ERAY_WRDS20_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS20_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS20_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS20_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS20_RESETVAL                                       (0x00000000U)

/* WRDS21 */

#define CSL_FLEXRAY_ERAY_WRDS21_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS21_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS21_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS21_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS21_RESETVAL                                       (0x00000000U)

/* WRDS22 */

#define CSL_FLEXRAY_ERAY_WRDS22_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS22_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS22_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS22_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS22_RESETVAL                                       (0x00000000U)

/* WRDS23 */

#define CSL_FLEXRAY_ERAY_WRDS23_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS23_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS23_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS23_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS23_RESETVAL                                       (0x00000000U)

/* WRDS24 */

#define CSL_FLEXRAY_ERAY_WRDS24_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS24_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS24_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS24_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS24_RESETVAL                                       (0x00000000U)

/* WRDS25 */

#define CSL_FLEXRAY_ERAY_WRDS25_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS25_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS25_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS25_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS25_RESETVAL                                       (0x00000000U)

/* WRDS26 */

#define CSL_FLEXRAY_ERAY_WRDS26_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS26_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS26_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS26_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS26_RESETVAL                                       (0x00000000U)

/* WRDS27 */

#define CSL_FLEXRAY_ERAY_WRDS27_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS27_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS27_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS27_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS27_RESETVAL                                       (0x00000000U)

/* WRDS28 */

#define CSL_FLEXRAY_ERAY_WRDS28_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS28_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS28_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS28_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS28_RESETVAL                                       (0x00000000U)

/* WRDS29 */

#define CSL_FLEXRAY_ERAY_WRDS29_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS29_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS29_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS29_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS29_RESETVAL                                       (0x00000000U)

/* WRDS30 */

#define CSL_FLEXRAY_ERAY_WRDS30_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS30_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS30_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS30_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS30_RESETVAL                                       (0x00000000U)

/* WRDS31 */

#define CSL_FLEXRAY_ERAY_WRDS31_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS31_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS31_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS31_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS31_RESETVAL                                       (0x00000000U)

/* WRDS32 */

#define CSL_FLEXRAY_ERAY_WRDS32_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS32_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS32_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS32_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS32_RESETVAL                                       (0x00000000U)

/* WRDS33 */

#define CSL_FLEXRAY_ERAY_WRDS33_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS33_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS33_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS33_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS33_RESETVAL                                       (0x00000000U)

/* WRDS34 */

#define CSL_FLEXRAY_ERAY_WRDS34_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS34_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS34_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS34_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS34_RESETVAL                                       (0x00000000U)

/* WRDS35 */

#define CSL_FLEXRAY_ERAY_WRDS35_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS35_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS35_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS35_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS35_RESETVAL                                       (0x00000000U)

/* WRDS36 */

#define CSL_FLEXRAY_ERAY_WRDS36_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS36_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS36_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS36_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS36_RESETVAL                                       (0x00000000U)

/* WRDS37 */

#define CSL_FLEXRAY_ERAY_WRDS37_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS37_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS37_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS37_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS37_RESETVAL                                       (0x00000000U)

/* WRDS38 */

#define CSL_FLEXRAY_ERAY_WRDS38_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS38_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS38_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS38_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS38_RESETVAL                                       (0x00000000U)

/* WRDS39 */

#define CSL_FLEXRAY_ERAY_WRDS39_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS39_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS39_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS39_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS39_RESETVAL                                       (0x00000000U)

/* WRDS40 */

#define CSL_FLEXRAY_ERAY_WRDS40_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS40_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS40_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS40_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS40_RESETVAL                                       (0x00000000U)

/* WRDS41 */

#define CSL_FLEXRAY_ERAY_WRDS41_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS41_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS41_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS41_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS41_RESETVAL                                       (0x00000000U)

/* WRDS42 */

#define CSL_FLEXRAY_ERAY_WRDS42_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS42_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS42_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS42_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS42_RESETVAL                                       (0x00000000U)

/* WRDS43 */

#define CSL_FLEXRAY_ERAY_WRDS43_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS43_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS43_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS43_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS43_RESETVAL                                       (0x00000000U)

/* WRDS44 */

#define CSL_FLEXRAY_ERAY_WRDS44_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS44_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS44_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS44_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS44_RESETVAL                                       (0x00000000U)

/* WRDS45 */

#define CSL_FLEXRAY_ERAY_WRDS45_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS45_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS45_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS45_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS45_RESETVAL                                       (0x00000000U)

/* WRDS46 */

#define CSL_FLEXRAY_ERAY_WRDS46_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS46_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS46_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS46_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS46_RESETVAL                                       (0x00000000U)

/* WRDS47 */

#define CSL_FLEXRAY_ERAY_WRDS47_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS47_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS47_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS47_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS47_RESETVAL                                       (0x00000000U)

/* WRDS48 */

#define CSL_FLEXRAY_ERAY_WRDS48_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS48_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS48_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS48_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS48_RESETVAL                                       (0x00000000U)

/* WRDS49 */

#define CSL_FLEXRAY_ERAY_WRDS49_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS49_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS49_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS49_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS49_RESETVAL                                       (0x00000000U)

/* WRDS50 */

#define CSL_FLEXRAY_ERAY_WRDS50_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS50_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS50_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS50_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS50_RESETVAL                                       (0x00000000U)

/* WRDS51 */

#define CSL_FLEXRAY_ERAY_WRDS51_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS51_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS51_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS51_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS51_RESETVAL                                       (0x00000000U)

/* WRDS52 */

#define CSL_FLEXRAY_ERAY_WRDS52_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS52_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS52_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS52_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS52_RESETVAL                                       (0x00000000U)

/* WRDS53 */

#define CSL_FLEXRAY_ERAY_WRDS53_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS53_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS53_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS53_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS53_RESETVAL                                       (0x00000000U)

/* WRDS54 */

#define CSL_FLEXRAY_ERAY_WRDS54_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS54_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS54_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS54_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS54_RESETVAL                                       (0x00000000U)

/* WRDS55 */

#define CSL_FLEXRAY_ERAY_WRDS55_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS55_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS55_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS55_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS55_RESETVAL                                       (0x00000000U)

/* WRDS56 */

#define CSL_FLEXRAY_ERAY_WRDS56_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS56_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS56_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS56_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS56_RESETVAL                                       (0x00000000U)

/* WRDS57 */

#define CSL_FLEXRAY_ERAY_WRDS57_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS57_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS57_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS57_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS57_RESETVAL                                       (0x00000000U)

/* WRDS58 */

#define CSL_FLEXRAY_ERAY_WRDS58_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS58_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS58_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS58_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS58_RESETVAL                                       (0x00000000U)

/* WRDS59 */

#define CSL_FLEXRAY_ERAY_WRDS59_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS59_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS59_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS59_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS59_RESETVAL                                       (0x00000000U)

/* WRDS60 */

#define CSL_FLEXRAY_ERAY_WRDS60_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS60_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS60_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS60_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS60_RESETVAL                                       (0x00000000U)

/* WRDS61 */

#define CSL_FLEXRAY_ERAY_WRDS61_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS61_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS61_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS61_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS61_RESETVAL                                       (0x00000000U)

/* WRDS62 */

#define CSL_FLEXRAY_ERAY_WRDS62_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS62_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS62_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS62_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS62_RESETVAL                                       (0x00000000U)

/* WRDS63 */

#define CSL_FLEXRAY_ERAY_WRDS63_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS63_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS63_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS63_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS63_RESETVAL                                       (0x00000000U)

/* WRDS64 */

#define CSL_FLEXRAY_ERAY_WRDS64_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_WRDS64_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS64_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRDS64_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_WRDS64_RESETVAL                                       (0x00000000U)

/* WRHS1 */

#define CSL_FLEXRAY_ERAY_WRHS1_FID_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_WRHS1_FID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_FID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_FID_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_WRHS1_CYC_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CYC_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_WRHS1_CYC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CYC_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_WRHS1_CHA_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHA_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_CHB_MASK                                        (0x02000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHB_SHIFT                                       (0x00000019U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CHB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_CFG_MASK                                        (0x04000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CFG_SHIFT                                       (0x0000001AU)
#define CSL_FLEXRAY_ERAY_WRHS1_CFG_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_CFG_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_PPIT_MASK                                       (0x08000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_PPIT_SHIFT                                      (0x0000001BU)
#define CSL_FLEXRAY_ERAY_WRHS1_PPIT_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_PPIT_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_TXM_MASK                                        (0x10000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_TXM_SHIFT                                       (0x0000001CU)
#define CSL_FLEXRAY_ERAY_WRHS1_TXM_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_TXM_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_MBI_MASK                                        (0x20000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_MBI_SHIFT                                       (0x0000001DU)
#define CSL_FLEXRAY_ERAY_WRHS1_MBI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS1_MBI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_WRHS1_RESETVAL                                        (0x00000000U)

/* WRHS2 */

#define CSL_FLEXRAY_ERAY_WRHS2_CRC_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_WRHS2_CRC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS2_CRC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS2_CRC_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_WRHS2_PLC_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_WRHS2_PLC_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_WRHS2_PLC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS2_PLC_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_WRHS2_RESETVAL                                        (0x00000000U)

/* WRHS3 */

#define CSL_FLEXRAY_ERAY_WRHS3_DP_MASK                                         (0x000007FFU)
#define CSL_FLEXRAY_ERAY_WRHS3_DP_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS3_DP_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_WRHS3_DP_MAX                                          (0x000007FFU)

#define CSL_FLEXRAY_ERAY_WRHS3_RESETVAL                                        (0x00000000U)

/* IBCM */

#define CSL_FLEXRAY_ERAY_IBCM_LHSH_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSH_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSH_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_LDSH_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSH_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSH_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_STXRH_MASK                                       (0x00000004U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRH_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRH_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRH_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_LHSS_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSS_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_LHSS_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_LDSS_MASK                                        (0x00020000U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSS_SHIFT                                       (0x00000011U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_LDSS_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_STXRS_MASK                                       (0x00040000U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRS_SHIFT                                      (0x00000012U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRS_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCM_STXRS_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCM_RESETVAL                                         (0x00000000U)

/* IBCR */

#define CSL_FLEXRAY_ERAY_IBCR_IBRH_MASK                                        (0x0000007FU)
#define CSL_FLEXRAY_ERAY_IBCR_IBRH_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBRH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBRH_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_IBCR_IBSYH_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYH_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYH_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYH_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCR_IBRS_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBRS_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_IBCR_IBRS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBRS_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_IBCR_IBSYS_MASK                                       (0x80000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYS_SHIFT                                      (0x0000001FU)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYS_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_IBCR_IBSYS_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_IBCR_RESETVAL                                         (0x00000000U)

/* RDDS1 */

#define CSL_FLEXRAY_ERAY_RDDS1_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS1_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS1_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS1_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS1_RESETVAL                                        (0x00000000U)

/* RDDS2 */

#define CSL_FLEXRAY_ERAY_RDDS2_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS2_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS2_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS2_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS2_RESETVAL                                        (0x00000000U)

/* RDDS3 */

#define CSL_FLEXRAY_ERAY_RDDS3_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS3_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS3_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS3_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS3_RESETVAL                                        (0x00000000U)

/* RDDS4 */

#define CSL_FLEXRAY_ERAY_RDDS4_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS4_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS4_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS4_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS4_RESETVAL                                        (0x00000000U)

/* RDDS5 */

#define CSL_FLEXRAY_ERAY_RDDS5_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS5_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS5_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS5_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS5_RESETVAL                                        (0x00000000U)

/* RDDS6 */

#define CSL_FLEXRAY_ERAY_RDDS6_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS6_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS6_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS6_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS6_RESETVAL                                        (0x00000000U)

/* RDDS7 */

#define CSL_FLEXRAY_ERAY_RDDS7_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS7_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS7_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS7_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS7_RESETVAL                                        (0x00000000U)

/* RDDS8 */

#define CSL_FLEXRAY_ERAY_RDDS8_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS8_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS8_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS8_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS8_RESETVAL                                        (0x00000000U)

/* RDDS9 */

#define CSL_FLEXRAY_ERAY_RDDS9_MD_MASK                                         (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS9_MD_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS9_MD_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS9_MD_MAX                                          (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS9_RESETVAL                                        (0x00000000U)

/* RDDS10 */

#define CSL_FLEXRAY_ERAY_RDDS10_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS10_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS10_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS10_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS10_RESETVAL                                       (0x00000000U)

/* RDDS11 */

#define CSL_FLEXRAY_ERAY_RDDS11_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS11_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS11_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS11_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS11_RESETVAL                                       (0x00000000U)

/* RDDS12 */

#define CSL_FLEXRAY_ERAY_RDDS12_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS12_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS12_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS12_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS12_RESETVAL                                       (0x00000000U)

/* RDDS13 */

#define CSL_FLEXRAY_ERAY_RDDS13_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS13_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS13_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS13_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS13_RESETVAL                                       (0x00000000U)

/* RDDS14 */

#define CSL_FLEXRAY_ERAY_RDDS14_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS14_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS14_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS14_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS14_RESETVAL                                       (0x00000000U)

/* RDDS15 */

#define CSL_FLEXRAY_ERAY_RDDS15_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS15_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS15_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS15_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS15_RESETVAL                                       (0x00000000U)

/* RDDS16 */

#define CSL_FLEXRAY_ERAY_RDDS16_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS16_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS16_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS16_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS16_RESETVAL                                       (0x00000000U)

/* RDDS17 */

#define CSL_FLEXRAY_ERAY_RDDS17_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS17_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS17_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS17_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS17_RESETVAL                                       (0x00000000U)

/* RDDS18 */

#define CSL_FLEXRAY_ERAY_RDDS18_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS18_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS18_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS18_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS18_RESETVAL                                       (0x00000000U)

/* RDDS19 */

#define CSL_FLEXRAY_ERAY_RDDS19_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS19_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS19_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS19_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS19_RESETVAL                                       (0x00000000U)

/* RDDS20 */

#define CSL_FLEXRAY_ERAY_RDDS20_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS20_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS20_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS20_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS20_RESETVAL                                       (0x00000000U)

/* RDDS21 */

#define CSL_FLEXRAY_ERAY_RDDS21_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS21_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS21_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS21_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS21_RESETVAL                                       (0x00000000U)

/* RDDS22 */

#define CSL_FLEXRAY_ERAY_RDDS22_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS22_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS22_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS22_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS22_RESETVAL                                       (0x00000000U)

/* RDDS23 */

#define CSL_FLEXRAY_ERAY_RDDS23_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS23_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS23_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS23_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS23_RESETVAL                                       (0x00000000U)

/* RDDS24 */

#define CSL_FLEXRAY_ERAY_RDDS24_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS24_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS24_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS24_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS24_RESETVAL                                       (0x00000000U)

/* RDDS25 */

#define CSL_FLEXRAY_ERAY_RDDS25_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS25_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS25_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS25_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS25_RESETVAL                                       (0x00000000U)

/* RDDS26 */

#define CSL_FLEXRAY_ERAY_RDDS26_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS26_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS26_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS26_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS26_RESETVAL                                       (0x00000000U)

/* RDDS27 */

#define CSL_FLEXRAY_ERAY_RDDS27_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS27_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS27_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS27_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS27_RESETVAL                                       (0x00000000U)

/* RDDS28 */

#define CSL_FLEXRAY_ERAY_RDDS28_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS28_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS28_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS28_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS28_RESETVAL                                       (0x00000000U)

/* RDDS29 */

#define CSL_FLEXRAY_ERAY_RDDS29_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS29_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS29_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS29_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS29_RESETVAL                                       (0x00000000U)

/* RDDS30 */

#define CSL_FLEXRAY_ERAY_RDDS30_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS30_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS30_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS30_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS30_RESETVAL                                       (0x00000000U)

/* RDDS31 */

#define CSL_FLEXRAY_ERAY_RDDS31_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS31_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS31_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS31_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS31_RESETVAL                                       (0x00000000U)

/* RDDS32 */

#define CSL_FLEXRAY_ERAY_RDDS32_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS32_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS32_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS32_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS32_RESETVAL                                       (0x00000000U)

/* RDDS33 */

#define CSL_FLEXRAY_ERAY_RDDS33_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS33_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS33_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS33_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS33_RESETVAL                                       (0x00000000U)

/* RDDS34 */

#define CSL_FLEXRAY_ERAY_RDDS34_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS34_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS34_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS34_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS34_RESETVAL                                       (0x00000000U)

/* RDDS35 */

#define CSL_FLEXRAY_ERAY_RDDS35_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS35_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS35_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS35_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS35_RESETVAL                                       (0x00000000U)

/* RDDS36 */

#define CSL_FLEXRAY_ERAY_RDDS36_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS36_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS36_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS36_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS36_RESETVAL                                       (0x00000000U)

/* RDDS37 */

#define CSL_FLEXRAY_ERAY_RDDS37_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS37_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS37_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS37_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS37_RESETVAL                                       (0x00000000U)

/* RDDS38 */

#define CSL_FLEXRAY_ERAY_RDDS38_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS38_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS38_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS38_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS38_RESETVAL                                       (0x00000000U)

/* RDDS39 */

#define CSL_FLEXRAY_ERAY_RDDS39_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS39_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS39_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS39_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS39_RESETVAL                                       (0x00000000U)

/* RDDS40 */

#define CSL_FLEXRAY_ERAY_RDDS40_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS40_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS40_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS40_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS40_RESETVAL                                       (0x00000000U)

/* RDDS41 */

#define CSL_FLEXRAY_ERAY_RDDS41_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS41_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS41_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS41_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS41_RESETVAL                                       (0x00000000U)

/* RDDS42 */

#define CSL_FLEXRAY_ERAY_RDDS42_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS42_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS42_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS42_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS42_RESETVAL                                       (0x00000000U)

/* RDDS43 */

#define CSL_FLEXRAY_ERAY_RDDS43_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS43_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS43_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS43_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS43_RESETVAL                                       (0x00000000U)

/* RDDS44 */

#define CSL_FLEXRAY_ERAY_RDDS44_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS44_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS44_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS44_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS44_RESETVAL                                       (0x00000000U)

/* RDDS45 */

#define CSL_FLEXRAY_ERAY_RDDS45_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS45_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS45_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS45_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS45_RESETVAL                                       (0x00000000U)

/* RDDS46 */

#define CSL_FLEXRAY_ERAY_RDDS46_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS46_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS46_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS46_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS46_RESETVAL                                       (0x00000000U)

/* RDDS47 */

#define CSL_FLEXRAY_ERAY_RDDS47_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS47_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS47_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS47_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS47_RESETVAL                                       (0x00000000U)

/* RDDS48 */

#define CSL_FLEXRAY_ERAY_RDDS48_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS48_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS48_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS48_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS48_RESETVAL                                       (0x00000000U)

/* RDDS49 */

#define CSL_FLEXRAY_ERAY_RDDS49_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS49_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS49_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS49_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS49_RESETVAL                                       (0x00000000U)

/* RDDS50 */

#define CSL_FLEXRAY_ERAY_RDDS50_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS50_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS50_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS50_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS50_RESETVAL                                       (0x00000000U)

/* RDDS51 */

#define CSL_FLEXRAY_ERAY_RDDS51_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS51_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS51_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS51_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS51_RESETVAL                                       (0x00000000U)

/* RDDS52 */

#define CSL_FLEXRAY_ERAY_RDDS52_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS52_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS52_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS52_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS52_RESETVAL                                       (0x00000000U)

/* RDDS53 */

#define CSL_FLEXRAY_ERAY_RDDS53_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS53_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS53_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS53_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS53_RESETVAL                                       (0x00000000U)

/* RDDS54 */

#define CSL_FLEXRAY_ERAY_RDDS54_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS54_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS54_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS54_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS54_RESETVAL                                       (0x00000000U)

/* RDDS55 */

#define CSL_FLEXRAY_ERAY_RDDS55_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS55_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS55_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS55_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS55_RESETVAL                                       (0x00000000U)

/* RDDS56 */

#define CSL_FLEXRAY_ERAY_RDDS56_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS56_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS56_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS56_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS56_RESETVAL                                       (0x00000000U)

/* RDDS57 */

#define CSL_FLEXRAY_ERAY_RDDS57_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS57_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS57_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS57_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS57_RESETVAL                                       (0x00000000U)

/* RDDS58 */

#define CSL_FLEXRAY_ERAY_RDDS58_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS58_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS58_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS58_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS58_RESETVAL                                       (0x00000000U)

/* RDDS59 */

#define CSL_FLEXRAY_ERAY_RDDS59_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS59_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS59_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS59_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS59_RESETVAL                                       (0x00000000U)

/* RDDS60 */

#define CSL_FLEXRAY_ERAY_RDDS60_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS60_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS60_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS60_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS60_RESETVAL                                       (0x00000000U)

/* RDDS61 */

#define CSL_FLEXRAY_ERAY_RDDS61_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS61_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS61_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS61_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS61_RESETVAL                                       (0x00000000U)

/* RDDS62 */

#define CSL_FLEXRAY_ERAY_RDDS62_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS62_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS62_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS62_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS62_RESETVAL                                       (0x00000000U)

/* RDDS63 */

#define CSL_FLEXRAY_ERAY_RDDS63_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS63_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS63_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS63_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS63_RESETVAL                                       (0x00000000U)

/* RDDS64 */

#define CSL_FLEXRAY_ERAY_RDDS64_MD_MASK                                        (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_RDDS64_MD_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS64_MD_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDDS64_MD_MAX                                         (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_RDDS64_RESETVAL                                       (0x00000000U)

/* RDHS1 */

#define CSL_FLEXRAY_ERAY_RDHS1_FID_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_RDHS1_FID_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_FID_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_FID_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_RDHS1_CYC_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CYC_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_RDHS1_CYC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CYC_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_RDHS1_CHA_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHA_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHA_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHA_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_CHB_MASK                                        (0x02000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHB_SHIFT                                       (0x00000019U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHB_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CHB_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_CFG_MASK                                        (0x04000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CFG_SHIFT                                       (0x0000001AU)
#define CSL_FLEXRAY_ERAY_RDHS1_CFG_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_CFG_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_PPIT_MASK                                       (0x08000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_PPIT_SHIFT                                      (0x0000001BU)
#define CSL_FLEXRAY_ERAY_RDHS1_PPIT_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_PPIT_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_TXM_MASK                                        (0x10000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_TXM_SHIFT                                       (0x0000001CU)
#define CSL_FLEXRAY_ERAY_RDHS1_TXM_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_TXM_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_MBI_MASK                                        (0x20000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_MBI_SHIFT                                       (0x0000001DU)
#define CSL_FLEXRAY_ERAY_RDHS1_MBI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS1_MBI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS1_RESETVAL                                        (0x00000000U)

/* RDHS2 */

#define CSL_FLEXRAY_ERAY_RDHS2_CRC_MASK                                        (0x000007FFU)
#define CSL_FLEXRAY_ERAY_RDHS2_CRC_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS2_CRC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS2_CRC_MAX                                         (0x000007FFU)

#define CSL_FLEXRAY_ERAY_RDHS2_PLC_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLC_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLC_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_RDHS2_PLR_MASK                                        (0x7F000000U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLR_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLR_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS2_PLR_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_RDHS2_RESETVAL                                        (0x00000000U)

/* RDHS3 */

#define CSL_FLEXRAY_ERAY_RDHS3_DP_MASK                                         (0x000007FFU)
#define CSL_FLEXRAY_ERAY_RDHS3_DP_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_DP_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_DP_MAX                                          (0x000007FFU)

#define CSL_FLEXRAY_ERAY_RDHS3_RCC_MASK                                        (0x003F0000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCC_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCC_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCC_MAX                                         (0x0000003FU)

#define CSL_FLEXRAY_ERAY_RDHS3_RCI_MASK                                        (0x01000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCI_SHIFT                                       (0x00000018U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RCI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_SFI_MASK                                        (0x02000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_SFI_SHIFT                                       (0x00000019U)
#define CSL_FLEXRAY_ERAY_RDHS3_SFI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_SFI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_SYN_MASK                                        (0x04000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_SYN_SHIFT                                       (0x0000001AU)
#define CSL_FLEXRAY_ERAY_RDHS3_SYN_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_SYN_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_NFI_MASK                                        (0x08000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_NFI_SHIFT                                       (0x0000001BU)
#define CSL_FLEXRAY_ERAY_RDHS3_NFI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_NFI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_PPI_MASK                                        (0x10000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_PPI_SHIFT                                       (0x0000001CU)
#define CSL_FLEXRAY_ERAY_RDHS3_PPI_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_PPI_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_RES_MASK                                        (0x20000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RES_SHIFT                                       (0x0000001DU)
#define CSL_FLEXRAY_ERAY_RDHS3_RES_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_RDHS3_RES_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_RDHS3_RESETVAL                                        (0x00000000U)

/* MBS */

#define CSL_FLEXRAY_ERAY_MBS_VFRA_MASK                                         (0x00000001U)
#define CSL_FLEXRAY_ERAY_MBS_VFRA_SHIFT                                        (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_VFRA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_VFRA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_VFRB_MASK                                         (0x00000002U)
#define CSL_FLEXRAY_ERAY_MBS_VFRB_SHIFT                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_MBS_VFRB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_VFRB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SEOA_MASK                                         (0x00000004U)
#define CSL_FLEXRAY_ERAY_MBS_SEOA_SHIFT                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_MBS_SEOA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SEOA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SEOB_MASK                                         (0x00000008U)
#define CSL_FLEXRAY_ERAY_MBS_SEOB_SHIFT                                        (0x00000003U)
#define CSL_FLEXRAY_ERAY_MBS_SEOB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SEOB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_CEOA_MASK                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_MBS_CEOA_SHIFT                                        (0x00000004U)
#define CSL_FLEXRAY_ERAY_MBS_CEOA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_CEOA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_CEOB_MASK                                         (0x00000020U)
#define CSL_FLEXRAY_ERAY_MBS_CEOB_SHIFT                                        (0x00000005U)
#define CSL_FLEXRAY_ERAY_MBS_CEOB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_CEOB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SVOA_MASK                                         (0x00000040U)
#define CSL_FLEXRAY_ERAY_MBS_SVOA_SHIFT                                        (0x00000006U)
#define CSL_FLEXRAY_ERAY_MBS_SVOA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SVOA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SVOB_MASK                                         (0x00000080U)
#define CSL_FLEXRAY_ERAY_MBS_SVOB_SHIFT                                        (0x00000007U)
#define CSL_FLEXRAY_ERAY_MBS_SVOB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SVOB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_TCIA_MASK                                         (0x00000100U)
#define CSL_FLEXRAY_ERAY_MBS_TCIA_SHIFT                                        (0x00000008U)
#define CSL_FLEXRAY_ERAY_MBS_TCIA_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_TCIA_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_TCIB_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_MBS_TCIB_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_MBS_TCIB_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_TCIB_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_ESA_MASK                                          (0x00000400U)
#define CSL_FLEXRAY_ERAY_MBS_ESA_SHIFT                                         (0x0000000AU)
#define CSL_FLEXRAY_ERAY_MBS_ESA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_ESA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_ESB_MASK                                          (0x00000800U)
#define CSL_FLEXRAY_ERAY_MBS_ESB_SHIFT                                         (0x0000000BU)
#define CSL_FLEXRAY_ERAY_MBS_ESB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_ESB_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_MLST_MASK                                         (0x00001000U)
#define CSL_FLEXRAY_ERAY_MBS_MLST_SHIFT                                        (0x0000000CU)
#define CSL_FLEXRAY_ERAY_MBS_MLST_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_MLST_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_FTA_MASK                                          (0x00004000U)
#define CSL_FLEXRAY_ERAY_MBS_FTA_SHIFT                                         (0x0000000EU)
#define CSL_FLEXRAY_ERAY_MBS_FTA_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_FTA_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_FTB_MASK                                          (0x00008000U)
#define CSL_FLEXRAY_ERAY_MBS_FTB_SHIFT                                         (0x0000000FU)
#define CSL_FLEXRAY_ERAY_MBS_FTB_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_FTB_MAX                                           (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_CCS_MASK                                          (0x003F0000U)
#define CSL_FLEXRAY_ERAY_MBS_CCS_SHIFT                                         (0x00000010U)
#define CSL_FLEXRAY_ERAY_MBS_CCS_RESETVAL                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_CCS_MAX                                           (0x0000003FU)

#define CSL_FLEXRAY_ERAY_MBS_RCIS_MASK                                         (0x01000000U)
#define CSL_FLEXRAY_ERAY_MBS_RCIS_SHIFT                                        (0x00000018U)
#define CSL_FLEXRAY_ERAY_MBS_RCIS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_RCIS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SFIS_MASK                                         (0x02000000U)
#define CSL_FLEXRAY_ERAY_MBS_SFIS_SHIFT                                        (0x00000019U)
#define CSL_FLEXRAY_ERAY_MBS_SFIS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SFIS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_SYNS_MASK                                         (0x04000000U)
#define CSL_FLEXRAY_ERAY_MBS_SYNS_SHIFT                                        (0x0000001AU)
#define CSL_FLEXRAY_ERAY_MBS_SYNS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_SYNS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_NFIS_MASK                                         (0x08000000U)
#define CSL_FLEXRAY_ERAY_MBS_NFIS_SHIFT                                        (0x0000001BU)
#define CSL_FLEXRAY_ERAY_MBS_NFIS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_NFIS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_PPIS_MASK                                         (0x10000000U)
#define CSL_FLEXRAY_ERAY_MBS_PPIS_SHIFT                                        (0x0000001CU)
#define CSL_FLEXRAY_ERAY_MBS_PPIS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_PPIS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_RESS_MASK                                         (0x20000000U)
#define CSL_FLEXRAY_ERAY_MBS_RESS_SHIFT                                        (0x0000001DU)
#define CSL_FLEXRAY_ERAY_MBS_RESS_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_MBS_RESS_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_MBS_RESETVAL                                          (0x00000000U)

/* OBCM */

#define CSL_FLEXRAY_ERAY_OBCM_RHSS_MASK                                        (0x00000001U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSS_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSS_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCM_RDSS_MASK                                        (0x00000002U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSS_SHIFT                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSS_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCM_RHSH_MASK                                        (0x00010000U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSH_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCM_RHSH_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCM_RDSH_MASK                                        (0x00020000U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSH_SHIFT                                       (0x00000011U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCM_RDSH_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCM_RESETVAL                                         (0x00000000U)

/* OBCR */

#define CSL_FLEXRAY_ERAY_OBCR_OBRS_MASK                                        (0x0000007FU)
#define CSL_FLEXRAY_ERAY_OBCR_OBRS_SHIFT                                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBRS_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBRS_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_OBCR_VIEW_MASK                                        (0x00000100U)
#define CSL_FLEXRAY_ERAY_OBCR_VIEW_SHIFT                                       (0x00000008U)
#define CSL_FLEXRAY_ERAY_OBCR_VIEW_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_VIEW_MAX                                         (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCR_REQ_MASK                                         (0x00000200U)
#define CSL_FLEXRAY_ERAY_OBCR_REQ_SHIFT                                        (0x00000009U)
#define CSL_FLEXRAY_ERAY_OBCR_REQ_RESETVAL                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_REQ_MAX                                          (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCR_OBSYS_MASK                                       (0x00008000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBSYS_SHIFT                                      (0x0000000FU)
#define CSL_FLEXRAY_ERAY_OBCR_OBSYS_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBSYS_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_OBCR_OBRH_MASK                                        (0x007F0000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBRH_SHIFT                                       (0x00000010U)
#define CSL_FLEXRAY_ERAY_OBCR_OBRH_RESETVAL                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_OBCR_OBRH_MAX                                         (0x0000007FU)

#define CSL_FLEXRAY_ERAY_OBCR_RESETVAL                                         (0x00000000U)

/**************************************************************************
* Hardware Region  : Eray Core Transfer Unit Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t TTSMS;                     /* Trigger Transfer to System Memory Set */
    volatile uint32_t TTSMR;                     /* Trigger Transfer to System Memory Reset */
} CSL_flexray_eray_tuRegs_TTSM;


typedef struct {
    volatile uint32_t TTCCS;                     /* Trigger Transfer to Communication Controller Set */
    volatile uint32_t TTCCR;                     /* Trigger Transfer to Communication Controller Reset */
} CSL_flexray_eray_tuRegs_TTCC;


typedef struct {
    volatile uint32_t ETESMS;                    /* Enable Transfer on Event to System Memory Set */
    volatile uint32_t ETESMR;                    /* Enable Transfer on Event to System Memory Reset */
} CSL_flexray_eray_tuRegs_ETESM;


typedef struct {
    volatile uint32_t CESMS;                     /* Clear on Event to System Memory Set */
    volatile uint32_t CESMR;                     /* Clear on Event to System Memory Reset */
} CSL_flexray_eray_tuRegs_CESM;


typedef struct {
    volatile uint32_t TSMIES;                    /* Transfer to System Memory Interrupt Enable Set */
    volatile uint32_t TSMIER;                    /* Transfer to System Memory Interrupt Enable Reset */
} CSL_flexray_eray_tuRegs_TSMIE;


typedef struct {
    volatile uint32_t TCCIES;                    /* Transfer to Communication Controller Interrupt Enable Set */
    volatile uint32_t TCCIER;                    /* Transfer to Communication Controller Interrupt Enable Reset */
} CSL_flexray_eray_tuRegs_TCCIE;


typedef struct {
    volatile uint32_t GSN0;                      /* Global Static Number 0 */
    volatile uint32_t GSN1;                      /* Global Static Number 1 */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t GCS;                       /* Global Control Set */
    volatile uint32_t GCR;                       /* Global Control Reset */
    volatile uint32_t TSCB;                      /* Transfer Status Current Buffer */
    volatile uint32_t LTBCC;                     /* Last Transfered Buffer to Communication controller */
    volatile uint32_t LTBSM;                     /* Last Transferred Buffer to System Memory */
    volatile uint32_t TBA;                       /* Transfer base Address */
    volatile uint32_t NTBA;                      /* Next Transfer Base Address */
    volatile uint32_t BAMS;                      /* Base Address of Mirrored Status */
    volatile uint32_t SAMP;                      /* Start Address of memory Protection */
    volatile uint8_t  Resv_64[12];
    volatile uint32_t TSMO[4];                   /* Transfer to System Memory Occured */
    volatile uint32_t TCCO[4];                   /* Transfer to Communication Controller Occured */
    volatile uint32_t TOOFF;                     /* Transfer occured Offset */
    volatile uint8_t  Resv_108[8];
    volatile uint32_t TSBESTAT;                  /* TCR Single Bit Error Status */
    volatile uint32_t PEADR;                     /* Parity/ECC Error Address */
    volatile uint32_t TEIF;                      /* Transfer Error Interrupt Flag */
    volatile uint32_t TEIRES;                    /* Transfer Error Interrupt Enable Set */
    volatile uint32_t TEIRER;                    /* Transfer Error Interrupt Enable Reset */
    CSL_flexray_eray_tuRegs_TTSM TTSM[4];
    CSL_flexray_eray_tuRegs_TTCC TTCC[4];
    CSL_flexray_eray_tuRegs_ETESM ETESM[4];
    CSL_flexray_eray_tuRegs_CESM CESM[4];
    CSL_flexray_eray_tuRegs_TSMIE TSMIE[4];
    CSL_flexray_eray_tuRegs_TCCIE TCCIE[4];
} CSL_flexray_eray_tuRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FLEXRAY_ERAY_TU_GSN0                                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GSN1                                               (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_GCS                                                (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GCR                                                (0x00000014U)
#define CSL_FLEXRAY_ERAY_TU_TSCB                                               (0x00000018U)
#define CSL_FLEXRAY_ERAY_TU_LTBCC                                              (0x0000001CU)
#define CSL_FLEXRAY_ERAY_TU_LTBSM                                              (0x00000020U)
#define CSL_FLEXRAY_ERAY_TU_TBA                                                (0x00000024U)
#define CSL_FLEXRAY_ERAY_TU_NTBA                                               (0x00000028U)
#define CSL_FLEXRAY_ERAY_TU_BAMS                                               (0x0000002CU)
#define CSL_FLEXRAY_ERAY_TU_SAMP                                               (0x00000030U)
#define CSL_FLEXRAY_ERAY_TU_TSMO(TSMO)                                         (0x00000040U+((TSMO)*0x4U))
#define CSL_FLEXRAY_ERAY_TU_TCCO(TCCO)                                         (0x00000050U+((TCCO)*0x4U))
#define CSL_FLEXRAY_ERAY_TU_TOOFF                                              (0x00000060U)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT                                           (0x0000006CU)
#define CSL_FLEXRAY_ERAY_TU_PEADR                                              (0x00000070U)
#define CSL_FLEXRAY_ERAY_TU_TEIF                                               (0x00000074U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES                                             (0x00000078U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER                                             (0x0000007CU)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS(TTSM)                                   (0x00000080U+((TTSM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR(TTSM)                                   (0x00000084U+((TTSM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS(TTCC)                                   (0x000000A0U+((TTCC)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR(TTCC)                                   (0x000000A4U+((TTCC)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS(ETESM)                                (0x000000C0U+((ETESM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR(ETESM)                                (0x000000C4U+((ETESM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS(CESM)                                   (0x000000E0U+((CESM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR(CESM)                                   (0x000000E4U+((CESM)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES(TSMIE)                                (0x00000100U+((TSMIE)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER(TSMIE)                                (0x00000104U+((TSMIE)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES(TCCIE)                                (0x00000120U+((TCCIE)*0x8U))
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER(TCCIE)                                (0x00000124U+((TCCIE)*0x8U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* TTSMS */

#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS_TTSMS_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS_TTSMS_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS_TTSMS_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS_TTSMS_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMS_RESETVAL                                (0x00000000U)

/* TTSMR */

#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR_TTSMR_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR_TTSMR_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR_TTSMR_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR_TTSMR_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TTSM_TTSMR_RESETVAL                                (0x00000000U)

/* TTCCS */

#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS_TTCCS_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS_TTCCS_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS_TTCCS_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS_TTCCS_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCS_RESETVAL                                (0x00000000U)

/* TTCCR */

#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR_TTCCR_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR_TTCCR_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR_TTCCR_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR_TTCCR_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TTCC_TTCCR_RESETVAL                                (0x00000000U)

/* ETESMS */

#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS_ETESMS_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS_ETESMS_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS_ETESMS_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS_ETESMS_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMS_RESETVAL                              (0x00000000U)

/* ETESMR */

#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR_ETESMR_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR_ETESMR_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR_ETESMR_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR_ETESMR_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_ETESM_ETESMR_RESETVAL                              (0x00000000U)

/* CESMS */

#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS_CESMS_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS_CESMS_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS_CESMS_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS_CESMS_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_CESM_CESMS_RESETVAL                                (0x00000000U)

/* CESMR */

#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR_CESMR_MASK                              (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR_CESMR_SHIFT                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR_CESMR_RESETVAL                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR_CESMR_MAX                               (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_CESM_CESMR_RESETVAL                                (0x00000000U)

/* TSMIES */

#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES_TSMIES_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES_TSMIES_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES_TSMIES_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES_TSMIES_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIES_RESETVAL                              (0x00000000U)

/* TSMIER */

#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER_TSMIER_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER_TSMIER_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER_TSMIER_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER_TSMIER_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TSMIE_TSMIER_RESETVAL                              (0x00000000U)

/* TCCIES */

#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES_TCCIES_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES_TCCIES_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES_TCCIES_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES_TCCIES_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIES_RESETVAL                              (0x00000000U)

/* TCCIER */

#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER_TCCIER_MASK                           (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER_TCCIER_SHIFT                          (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER_TCCIER_RESETVAL                       (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER_TCCIER_MAX                            (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TCCIE_TCCIER_RESETVAL                              (0x00000000U)

/* GSN0 */

#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_B_MASK                                   (0x0000FFFFU)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_B_SHIFT                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_B_RESETVAL                               (0x0000ABCDU)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_B_MAX                                    (0x0000FFFFU)

#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_A_MASK                                   (0xFFFF0000U)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_A_SHIFT                                  (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_A_RESETVAL                               (0x00005432U)
#define CSL_FLEXRAY_ERAY_TU_GSN0_DATA_A_MAX                                    (0x0000FFFFU)

#define CSL_FLEXRAY_ERAY_TU_GSN0_RESETVAL                                      (0x5432ABCDU)

/* GSN1 */

#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_D_MASK                                   (0x0000FFFFU)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_D_SHIFT                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_D_RESETVAL                               (0x00005432U)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_D_MAX                                    (0x0000FFFFU)

#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_C_MASK                                   (0xFFFF0000U)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_C_SHIFT                                  (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_C_RESETVAL                               (0x0000ABCDU)
#define CSL_FLEXRAY_ERAY_TU_GSN1_DATA_C_MAX                                    (0x0000FFFFU)

#define CSL_FLEXRAY_ERAY_TU_GSN1_RESETVAL                                      (0xABCD5432U)

/* GCS */

#define CSL_FLEXRAY_ERAY_TU_GCS_TUE_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUE_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_TUH_MASK                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUH_SHIFT                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUH_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_TUH_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_EILE_MASK                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GCS_EILE_SHIFT                                     (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_GCS_EILE_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_EILE_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_SILE_MASK                                      (0x00000020U)
#define CSL_FLEXRAY_ERAY_TU_GCS_SILE_SHIFT                                     (0x00000005U)
#define CSL_FLEXRAY_ERAY_TU_GCS_SILE_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_SILE_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_STSM_MASK                                      (0x00000100U)
#define CSL_FLEXRAY_ERAY_TU_GCS_STSM_SHIFT                                     (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_GCS_STSM_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_STSM_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_M_MASK                                    (0x00001000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_M_SHIFT                                   (0x0000000CU)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_M_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_M_MAX                                     (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_C_MASK                                    (0x00002000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_C_SHIFT                                   (0x0000000DU)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_C_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CTTS_C_MAX                                     (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_CET_ESM_MASK                                   (0x00004000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CET_ESM_SHIFT                                  (0x0000000EU)
#define CSL_FLEXRAY_ERAY_TU_GCS_CET_ESM_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_CET_ESM_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_PEL_MASK                                       (0x000F0000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEL_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEL_RESETVAL                                   (0x00000005U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEL_MAX                                        (0x0000000FU)

#define CSL_FLEXRAY_ERAY_TU_GCS_PEFT_MASK                                      (0x00100000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEFT_SHIFT                                     (0x00000014U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEFT_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PEFT_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_PRIO_MASK                                      (0x00200000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PRIO_SHIFT                                     (0x00000015U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PRIO_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_PRIO_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_ENDP_MASK                                      (0x03000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDP_SHIFT                                     (0x00000018U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDP_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDP_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCS_ENDH_MASK                                      (0x0C000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDH_SHIFT                                     (0x0000001AU)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDH_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDH_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCS_ENDR_MASK                                      (0x30000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDR_SHIFT                                     (0x0000001CU)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDR_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_ENDR_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBS_MASK                                   (0x40000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBS_SHIFT                                  (0x0000001EU)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBS_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBS_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBM_MASK                                   (0x80000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBM_SHIFT                                  (0x0000001FU)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBM_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCS_END_VBM_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCS_RESETVAL                                       (0x00050000U)

/* GCR */

#define CSL_FLEXRAY_ERAY_TU_GCR_TUE_MASK                                       (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUE_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_TUH_MASK                                       (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUH_SHIFT                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUH_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_TUH_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_EILE_MASK                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GCR_EILE_SHIFT                                     (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_GCR_EILE_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_EILE_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_SILE_MASK                                      (0x00000020U)
#define CSL_FLEXRAY_ERAY_TU_GCR_SILE_SHIFT                                     (0x00000005U)
#define CSL_FLEXRAY_ERAY_TU_GCR_SILE_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_SILE_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_STSM_MASK                                      (0x00000100U)
#define CSL_FLEXRAY_ERAY_TU_GCR_STSM_SHIFT                                     (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_GCR_STSM_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_STSM_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_M_MASK                                    (0x00001000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_M_SHIFT                                   (0x0000000CU)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_M_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_M_MAX                                     (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_C_MASK                                    (0x00002000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_C_SHIFT                                   (0x0000000DU)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_C_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CTTS_C_MAX                                     (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_CET_ESM_MASK                                   (0x00004000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CET_ESM_SHIFT                                  (0x0000000EU)
#define CSL_FLEXRAY_ERAY_TU_GCR_CET_ESM_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_CET_ESM_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_PEL_MASK                                       (0x000F0000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEL_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEL_RESETVAL                                   (0x00000005U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEL_MAX                                        (0x0000000FU)

#define CSL_FLEXRAY_ERAY_TU_GCR_PEFT_MASK                                      (0x00100000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEFT_SHIFT                                     (0x00000014U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEFT_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PEFT_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_PRIO_MASK                                      (0x00200000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PRIO_SHIFT                                     (0x00000015U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PRIO_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_PRIO_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_ENDP_MASK                                      (0x03000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDP_SHIFT                                     (0x00000018U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDP_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDP_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCR_ENDH_MASK                                      (0x0C000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDH_SHIFT                                     (0x0000001AU)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDH_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDH_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCR_ENDR_MASK                                      (0x30000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDR_SHIFT                                     (0x0000001CU)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDR_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_ENDR_MAX                                       (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBS_MASK                                   (0x40000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBS_SHIFT                                  (0x0000001EU)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBS_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBS_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBM_MASK                                   (0x80000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBM_SHIFT                                  (0x0000001FU)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBM_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_GCR_END_VBM_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_GCR_RESETVAL                                       (0x00050000U)

/* TSCB */

#define CSL_FLEXRAY_ERAY_TU_TSCB_BN_MASK                                       (0x0000007FU)
#define CSL_FLEXRAY_ERAY_TU_TSCB_BN_SHIFT                                      (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_BN_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_BN_MAX                                        (0x0000007FU)

#define CSL_FLEXRAY_ERAY_TU_TSCB_IDLE_MASK                                     (0x00000100U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_IDLE_SHIFT                                    (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_IDLE_RESETVAL                                 (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_IDLE_MAX                                      (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TSCB_STUH_MASK                                     (0x00001000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_STUH_SHIFT                                    (0x0000000CU)
#define CSL_FLEXRAY_ERAY_TU_TSCB_STUH_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_STUH_MAX                                      (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TSCB_TSMS_MASK                                     (0x001F0000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_TSMS_SHIFT                                    (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_TSMS_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSCB_TSMS_MAX                                      (0x0000001FU)

#define CSL_FLEXRAY_ERAY_TU_TSCB_RESETVAL                                      (0x00000100U)

/* LTBCC */

#define CSL_FLEXRAY_ERAY_TU_LTBCC_BN_MASK                                      (0x0000007FU)
#define CSL_FLEXRAY_ERAY_TU_LTBCC_BN_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_LTBCC_BN_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_LTBCC_BN_MAX                                       (0x0000007FU)

#define CSL_FLEXRAY_ERAY_TU_LTBCC_RESETVAL                                     (0x00000000U)

/* LTBSM */

#define CSL_FLEXRAY_ERAY_TU_LTBSM_BN_MASK                                      (0x0000007FU)
#define CSL_FLEXRAY_ERAY_TU_LTBSM_BN_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_LTBSM_BN_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_LTBSM_BN_MAX                                       (0x0000007FU)

#define CSL_FLEXRAY_ERAY_TU_LTBSM_RESETVAL                                     (0x00000000U)

/* TBA */

#define CSL_FLEXRAY_ERAY_TU_TBA_TBA_MASK                                       (0xFFFFFFFCU)
#define CSL_FLEXRAY_ERAY_TU_TBA_TBA_SHIFT                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_TBA_TBA_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TBA_TBA_MAX                                        (0x3FFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TBA_RESETVAL                                       (0x00000000U)

/* NTBA */

#define CSL_FLEXRAY_ERAY_TU_NTBA_NTBA_MASK                                     (0xFFFFFFFCU)
#define CSL_FLEXRAY_ERAY_TU_NTBA_NTBA_SHIFT                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_NTBA_NTBA_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_NTBA_NTBA_MAX                                      (0x3FFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_NTBA_RESETVAL                                      (0x00000000U)

/* BAMS */

#define CSL_FLEXRAY_ERAY_TU_BAMS_BAMS_MASK                                     (0xFFFFFFFCU)
#define CSL_FLEXRAY_ERAY_TU_BAMS_BAMS_SHIFT                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_BAMS_BAMS_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_BAMS_BAMS_MAX                                      (0x3FFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_BAMS_RESETVAL                                      (0x00000000U)

/* SAMP */

#define CSL_FLEXRAY_ERAY_TU_SAMP_SAMP_MASK                                     (0xFFFFFFFCU)
#define CSL_FLEXRAY_ERAY_TU_SAMP_SAMP_SHIFT                                    (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_SAMP_SAMP_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_SAMP_SAMP_MAX                                      (0x3FFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_SAMP_RESETVAL                                      (0x00000000U)

/* TSMO */

#define CSL_FLEXRAY_ERAY_TU_TSMO_TSMO_MASK                                     (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TSMO_TSMO_SHIFT                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMO_TSMO_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSMO_TSMO_MAX                                      (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TSMO_RESETVAL                                      (0x00000000U)

/* TCCO */

#define CSL_FLEXRAY_ERAY_TU_TCCO_TCCO_MASK                                     (0xFFFFFFFFU)
#define CSL_FLEXRAY_ERAY_TU_TCCO_TCCO_SHIFT                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCO_TCCO_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TCCO_TCCO_MAX                                      (0xFFFFFFFFU)

#define CSL_FLEXRAY_ERAY_TU_TCCO_RESETVAL                                      (0x00000000U)

/* TOOFF */

#define CSL_FLEXRAY_ERAY_TU_TOOFF_OFF_MASK                                     (0x000000FFU)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_OFF_SHIFT                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_OFF_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_OFF_MAX                                      (0x000000FFU)

#define CSL_FLEXRAY_ERAY_TU_TOOFF_TDIR_MASK                                    (0x00000100U)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_TDIR_SHIFT                                   (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_TDIR_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TOOFF_TDIR_MAX                                     (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TOOFF_RESETVAL                                     (0x00000000U)

/* TSBESTAT */

#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_ADR_MASK                                  (0x000001FFU)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_ADR_SHIFT                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_ADR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_ADR_MAX                                   (0x000001FFU)

#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_SE_MASK                                   (0x80000000U)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_SE_SHIFT                                  (0x0000001FU)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_SE_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_SE_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TSBESTAT_RESETVAL                                  (0x00000000U)

/* PEADR */

#define CSL_FLEXRAY_ERAY_TU_PEADR_ADR_MASK                                     (0x000001FFU)
#define CSL_FLEXRAY_ERAY_TU_PEADR_ADR_SHIFT                                    (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_PEADR_ADR_RESETVAL                                 (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_PEADR_ADR_MAX                                      (0x000001FFU)

#define CSL_FLEXRAY_ERAY_TU_PEADR_RESETVAL                                     (0x00000000U)

/* TEIF */

#define CSL_FLEXRAY_ERAY_TU_TEIF_FAC_MASK                                      (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_FAC_SHIFT                                     (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_FAC_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_FAC_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_TNR_MASK                                      (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_TNR_SHIFT                                     (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_TNR_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_TNR_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_WSTAT_MASK                                    (0x00000030U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_WSTAT_SHIFT                                   (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_WSTAT_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_WSTAT_MAX                                     (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_RSTAT_MASK                                    (0x00000300U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_RSTAT_SHIFT                                   (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_RSTAT_RESETVAL                                (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_RSTAT_MAX                                     (0x00000003U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_PE_MASK                                       (0x00010000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_PE_SHIFT                                      (0x00000010U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_PE_RESETVAL                                   (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_PE_MAX                                        (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_MPV_MASK                                      (0x00020000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_MPV_SHIFT                                     (0x00000011U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_MPV_RESETVAL                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIF_MPV_MAX                                       (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIF_RESETVAL                                      (0x00000000U)

/* TEIRES */

#define CSL_FLEXRAY_ERAY_TU_TEIRES_FACE_MASK                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_FACE_SHIFT                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_FACE_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_FACE_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIRES_TNRE_MASK                                   (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_TNRE_SHIFT                                  (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_TNRE_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_TNRE_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIRES_WSTATE_MASK                                 (0x00000070U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_WSTATE_SHIFT                                (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_WSTATE_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_WSTATE_MAX                                  (0x00000007U)

#define CSL_FLEXRAY_ERAY_TU_TEIRES_RSTATE_MASK                                 (0x00000700U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_RSTATE_SHIFT                                (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_RSTATE_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRES_RSTATE_MAX                                  (0x00000007U)

#define CSL_FLEXRAY_ERAY_TU_TEIRES_RESETVAL                                    (0x00000000U)

/* TEIRER */

#define CSL_FLEXRAY_ERAY_TU_TEIRER_FACE_MASK                                   (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_FACE_SHIFT                                  (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_FACE_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_FACE_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIRER_TNRE_MASK                                   (0x00000002U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_TNRE_SHIFT                                  (0x00000001U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_TNRE_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_TNRE_MAX                                    (0x00000001U)

#define CSL_FLEXRAY_ERAY_TU_TEIRER_WSTATE_MASK                                 (0x00000070U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_WSTATE_SHIFT                                (0x00000004U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_WSTATE_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_WSTATE_MAX                                  (0x00000007U)

#define CSL_FLEXRAY_ERAY_TU_TEIRER_RSTATE_MASK                                 (0x00000700U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_RSTATE_SHIFT                                (0x00000008U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_RSTATE_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_ERAY_TU_TEIRER_RSTATE_MAX                                  (0x00000007U)

#define CSL_FLEXRAY_ERAY_TU_TEIRER_RESETVAL                                    (0x00000000U)

/**************************************************************************
* Hardware Region  : Eray Transfer Configuration Memory
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MEM[128];
} CSL_flexray_ramRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FLEXRAY_RAM_MEM(MEM)                               (0x00000000U+((MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MEM */

#define CSL_FLEXRAY_RAM_MEM_TSO_MASK                                   (0x00000FFFU)
#define CSL_FLEXRAY_RAM_MEM_TSO_SHIFT                                  (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_TSO_RESETVAL                               (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_TSO_MAX                                    (0x00000FFFU)

#define CSL_FLEXRAY_RAM_MEM_TPTCC_MASK                                 (0x00004000U)
#define CSL_FLEXRAY_RAM_MEM_TPTCC_SHIFT                                (0x0000000EU)
#define CSL_FLEXRAY_RAM_MEM_TPTCC_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_TPTCC_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_RAM_MEM_THTCC_MASK                                 (0x00008000U)
#define CSL_FLEXRAY_RAM_MEM_THTCC_SHIFT                                (0x0000000FU)
#define CSL_FLEXRAY_RAM_MEM_THTCC_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_THTCC_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_RAM_MEM_TPTSM_MASK                                 (0x00010000U)
#define CSL_FLEXRAY_RAM_MEM_TPTSM_SHIFT                                (0x00000010U)
#define CSL_FLEXRAY_RAM_MEM_TPTSM_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_TPTSM_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_RAM_MEM_THTSM_MASK                                 (0x00020000U)
#define CSL_FLEXRAY_RAM_MEM_THTSM_SHIFT                                (0x00000011U)
#define CSL_FLEXRAY_RAM_MEM_THTSM_RESETVAL                             (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_THTSM_MAX                                  (0x00000001U)

#define CSL_FLEXRAY_RAM_MEM_STXR_MASK                                  (0x00040000U)
#define CSL_FLEXRAY_RAM_MEM_STXR_SHIFT                                 (0x00000012U)
#define CSL_FLEXRAY_RAM_MEM_STXR_RESETVAL                              (0x00000000U)
#define CSL_FLEXRAY_RAM_MEM_STXR_MAX                                   (0x00000001U)

#define CSL_FLEXRAY_RAM_MEM_RESETVAL                                   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
