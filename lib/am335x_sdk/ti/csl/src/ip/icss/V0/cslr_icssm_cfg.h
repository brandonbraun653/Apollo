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
#ifndef CSLR_ICSSM_CFG_H_
#define CSLR_ICSSM_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for cfgaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 REVID;
    volatile Uint32 SYSCFG;
    volatile Uint32 GPCFG0;
    volatile Uint32 GPCFG1;
    volatile Uint32 CGR;
    volatile Uint32 ISRP;
    volatile Uint32 ISP;
    volatile Uint32 IESP;
    volatile Uint32 IECP;
    volatile Uint32 SCRP;
    volatile Uint32 PMAO;
    volatile Uint32 MII_RT;
    volatile Uint32 IEPCLK;
    volatile Uint32 SPP;
    volatile Uint8  RSVD0[8];
    volatile Uint32 PIN_MX;
} CSL_icssm_cfgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ICSSM_CFG_REVID                                     (0x0U)
#define CSL_ICSSM_CFG_SYSCFG                                    (0x4U)
#define CSL_ICSSM_CFG_GPCFG0                                    (0x8U)
#define CSL_ICSSM_CFG_GPCFG1                                    (0xCU)
#define CSL_ICSSM_CFG_CGR                                       (0x10U)
#define CSL_ICSSM_CFG_ISRP                                      (0x14U)
#define CSL_ICSSM_CFG_ISP                                       (0x18U)
#define CSL_ICSSM_CFG_IESP                                      (0x1CU)
#define CSL_ICSSM_CFG_IECP                                      (0x20U)
#define CSL_ICSSM_CFG_SCRP                                      (0x24U)
#define CSL_ICSSM_CFG_PMAO                                      (0x28U)
#define CSL_ICSSM_CFG_MII_RT                                    (0x2CU)
#define CSL_ICSSM_CFG_IEPCLK                                    (0x30U)
#define CSL_ICSSM_CFG_SPP                                       (0x34U)
#define CSL_ICSSM_CFG_PIN_MX                                    (0x40U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVID */

#define CSL_ICSSM_CFG_REVID_REVID_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_CFG_REVID_REVID_SHIFT                         (0x00000000U)
#define CSL_ICSSM_CFG_REVID_REVID_RESETVAL                      (0x47000100U)
#define CSL_ICSSM_CFG_REVID_REVID_MAX                           (0xffffffffU)

#define CSL_ICSSM_CFG_REVID_RESETVAL                            (0x47000100U)

/* SYSCFG */

#define CSL_ICSSM_CFG_SYSCFG_SUB_MWAIT_MASK                     (0x00000020U)
#define CSL_ICSSM_CFG_SYSCFG_SUB_MWAIT_SHIFT                    (0x00000005U)
#define CSL_ICSSM_CFG_SYSCFG_SUB_MWAIT_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_SYSCFG_SUB_MWAIT_MAX                      (0x00000001U)

#define CSL_ICSSM_CFG_SYSCFG_STANDBY_INIT_MASK                  (0x00000010U)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_INIT_SHIFT                 (0x00000004U)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_INIT_RESETVAL              (0x00000001U)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_INIT_MAX                   (0x00000001U)

#define CSL_ICSSM_CFG_SYSCFG_STANDBY_MODE_MASK                  (0x0000000CU)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_MODE_SHIFT                 (0x00000002U)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_MODE_RESETVAL              (0x00000002U)
#define CSL_ICSSM_CFG_SYSCFG_STANDBY_MODE_MAX                   (0x00000003U)

#define CSL_ICSSM_CFG_SYSCFG_IDLE_MODE_MASK                     (0x00000003U)
#define CSL_ICSSM_CFG_SYSCFG_IDLE_MODE_SHIFT                    (0x00000000U)
#define CSL_ICSSM_CFG_SYSCFG_IDLE_MODE_RESETVAL                 (0x00000002U)
#define CSL_ICSSM_CFG_SYSCFG_IDLE_MODE_MAX                      (0x00000003U)

#define CSL_ICSSM_CFG_SYSCFG_RESETVAL                           (0x0000001aU)

/* GPCFG0 */

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_SH_SEL_MASK               (0x02000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_SH_SEL_SHIFT              (0x00000019U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_SH_SEL_RESETVAL           (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_SH_SEL_MAX                (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV1_MASK                 (0x01F00000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV1_SHIFT                (0x00000014U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV1_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV1_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV0_MASK                 (0x000F8000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV0_SHIFT                (0x0000000FU)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV0_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_DIV0_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_MODE_MASK                 (0x00004000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_MODE_SHIFT                (0x0000000EU)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_MODE_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPO_MODE_MAX                  (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_SB_MASK                   (0x00002000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_SB_SHIFT                  (0x0000000DU)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_SB_RESETVAL               (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_SB_MAX                    (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV1_MASK                 (0x00001F00U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV1_SHIFT                (0x00000008U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV1_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV1_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV0_MASK                 (0x000000F8U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV0_SHIFT                (0x00000003U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV0_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_DIV0_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_CLK_MODE_MASK             (0x00000004U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_CLK_MODE_SHIFT            (0x00000002U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_CLK_MODE_RESETVAL         (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_CLK_MODE_MAX              (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_MODE_MASK                 (0x00000003U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_MODE_SHIFT                (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_MODE_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG0_PRU0_GPI_MODE_MAX                  (0x00000003U)

#define CSL_ICSSM_CFG_GPCFG0_RESETVAL                           (0x00000000U)

/* GPCFG1 */

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_SH_SEL_MASK               (0x02000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_SH_SEL_SHIFT              (0x00000019U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_SH_SEL_RESETVAL           (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_SH_SEL_MAX                (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV1_MASK                 (0x01F00000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV1_SHIFT                (0x00000014U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV1_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV1_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV0_MASK                 (0x000F8000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV0_SHIFT                (0x0000000FU)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV0_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_DIV0_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_MODE_MASK                 (0x00004000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_MODE_SHIFT                (0x0000000EU)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_MODE_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPO_MODE_MAX                  (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_SB_MASK                   (0x00002000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_SB_SHIFT                  (0x0000000DU)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_SB_RESETVAL               (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_SB_MAX                    (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV1_MASK                 (0x00001F00U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV1_SHIFT                (0x00000008U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV1_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV1_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV0_MASK                 (0x000000F8U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV0_SHIFT                (0x00000003U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV0_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_DIV0_MAX                  (0x0000001fU)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_CLK_MODE_MASK             (0x00000004U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_CLK_MODE_SHIFT            (0x00000002U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_CLK_MODE_RESETVAL         (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_CLK_MODE_MAX              (0x00000001U)

#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_MODE_MASK                 (0x00000003U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_MODE_SHIFT                (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_MODE_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_GPCFG1_PRU1_GPI_MODE_MAX                  (0x00000003U)

#define CSL_ICSSM_CFG_GPCFG1_RESETVAL                           (0x00000000U)

/* CGR */

#define CSL_ICSSM_CFG_CGR_IEP_CLK_EN_MASK                       (0x00020000U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_EN_SHIFT                      (0x00000011U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_EN_RESETVAL                   (0x00000001U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_EN_MAX                        (0x00000001U)

#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_ACK_MASK                 (0x00010000U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_ACK_SHIFT                (0x00000010U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_ACK_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_ACK_MAX                  (0x00000001U)

#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_REQ_MASK                 (0x00008000U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_REQ_SHIFT                (0x0000000FU)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_REQ_RESETVAL             (0x00000000U)
#define CSL_ICSSM_CFG_CGR_IEP_CLK_STOP_REQ_MAX                  (0x00000001U)

#define CSL_ICSSM_CFG_CGR_ECAP_CLK_EN_MASK                      (0x00004000U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_EN_SHIFT                     (0x0000000EU)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_EN_RESETVAL                  (0x00000001U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_EN_MAX                       (0x00000001U)

#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_ACK_MASK                (0x00002000U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_ACK_SHIFT               (0x0000000DU)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_ACK_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_ACK_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_REQ_MASK                (0x00001000U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_REQ_SHIFT               (0x0000000CU)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_REQ_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_ECAP_CLK_STOP_REQ_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_UART_CLK_EN_MASK                      (0x00000800U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_EN_SHIFT                     (0x0000000BU)
#define CSL_ICSSM_CFG_CGR_UART_CLK_EN_RESETVAL                  (0x00000001U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_EN_MAX                       (0x00000001U)

#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_ACK_MASK                (0x00000400U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_ACK_SHIFT               (0x0000000AU)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_ACK_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_ACK_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_REQ_MASK                (0x00000200U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_REQ_SHIFT               (0x00000009U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_REQ_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_UART_CLK_STOP_REQ_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_INTC_CLK_EN_MASK                      (0x00000100U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_EN_SHIFT                     (0x00000008U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_EN_RESETVAL                  (0x00000001U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_EN_MAX                       (0x00000001U)

#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_ACK_MASK                (0x00000080U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_ACK_SHIFT               (0x00000007U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_ACK_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_ACK_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_REQ_MASK                (0x00000040U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_REQ_SHIFT               (0x00000006U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_REQ_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_INTC_CLK_STOP_REQ_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU1_CLK_EN_MASK                      (0x00000020U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_EN_SHIFT                     (0x00000005U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_EN_RESETVAL                  (0x00000001U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_EN_MAX                       (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_ACK_MASK                (0x00000010U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_ACK_SHIFT               (0x00000004U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_ACK_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_ACK_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_REQ_MASK                (0x00000008U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_REQ_SHIFT               (0x00000003U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_REQ_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_PRU1_CLK_STOP_REQ_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU0_CLK_EN_MASK                      (0x00000004U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_EN_SHIFT                     (0x00000002U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_EN_RESETVAL                  (0x00000001U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_EN_MAX                       (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_ACK_MASK                (0x00000002U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_ACK_SHIFT               (0x00000001U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_ACK_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_ACK_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_REQ_MASK                (0x00000001U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_REQ_SHIFT               (0x00000000U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_REQ_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_CGR_PRU0_CLK_STOP_REQ_MAX                 (0x00000001U)

#define CSL_ICSSM_CFG_CGR_RESETVAL                              (0x00024924U)

/* ISRP */

#define CSL_ICSSM_CFG_ISRP_RAM_PE_RAW_MASK                      (0x000F0000U)
#define CSL_ICSSM_CFG_ISRP_RAM_PE_RAW_SHIFT                     (0x00000010U)
#define CSL_ICSSM_CFG_ISRP_RAM_PE_RAW_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_RAM_PE_RAW_MAX                       (0x0000000fU)

#define CSL_ICSSM_CFG_ISRP_PRU1_DMEM_PE_RAW_MASK                (0x0000F000U)
#define CSL_ICSSM_CFG_ISRP_PRU1_DMEM_PE_RAW_SHIFT               (0x0000000CU)
#define CSL_ICSSM_CFG_ISRP_PRU1_DMEM_PE_RAW_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_PRU1_DMEM_PE_RAW_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_ISRP_PRU1_IMEM_PE_RAW_MASK                (0x00000F00U)
#define CSL_ICSSM_CFG_ISRP_PRU1_IMEM_PE_RAW_SHIFT               (0x00000008U)
#define CSL_ICSSM_CFG_ISRP_PRU1_IMEM_PE_RAW_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_PRU1_IMEM_PE_RAW_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_ISRP_PRU0_DMEM_PE_RAW_MASK                (0x000000F0U)
#define CSL_ICSSM_CFG_ISRP_PRU0_DMEM_PE_RAW_SHIFT               (0x00000004U)
#define CSL_ICSSM_CFG_ISRP_PRU0_DMEM_PE_RAW_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_PRU0_DMEM_PE_RAW_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_ISRP_PRU0_IMEM_PE_RAW_MASK                (0x0000000FU)
#define CSL_ICSSM_CFG_ISRP_PRU0_IMEM_PE_RAW_SHIFT               (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_PRU0_IMEM_PE_RAW_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_ISRP_PRU0_IMEM_PE_RAW_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_ISRP_RESETVAL                             (0x00000000U)

/* ISP */

#define CSL_ICSSM_CFG_ISP_RAM_PE_MASK                           (0x000F0000U)
#define CSL_ICSSM_CFG_ISP_RAM_PE_SHIFT                          (0x00000010U)
#define CSL_ICSSM_CFG_ISP_RAM_PE_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_CFG_ISP_RAM_PE_MAX                            (0x0000000fU)

#define CSL_ICSSM_CFG_ISP_PRU1_DMEM_PE_MASK                     (0x0000F000U)
#define CSL_ICSSM_CFG_ISP_PRU1_DMEM_PE_SHIFT                    (0x0000000CU)
#define CSL_ICSSM_CFG_ISP_PRU1_DMEM_PE_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_ISP_PRU1_DMEM_PE_MAX                      (0x0000000fU)

#define CSL_ICSSM_CFG_ISP_PRU1_IMEM_PE_MASK                     (0x00000F00U)
#define CSL_ICSSM_CFG_ISP_PRU1_IMEM_PE_SHIFT                    (0x00000008U)
#define CSL_ICSSM_CFG_ISP_PRU1_IMEM_PE_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_ISP_PRU1_IMEM_PE_MAX                      (0x0000000fU)

#define CSL_ICSSM_CFG_ISP_PRU0_DMEM_PE_MASK                     (0x000000F0U)
#define CSL_ICSSM_CFG_ISP_PRU0_DMEM_PE_SHIFT                    (0x00000004U)
#define CSL_ICSSM_CFG_ISP_PRU0_DMEM_PE_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_ISP_PRU0_DMEM_PE_MAX                      (0x0000000fU)

#define CSL_ICSSM_CFG_ISP_PRU0_IMEM_PE_MASK                     (0x0000000FU)
#define CSL_ICSSM_CFG_ISP_PRU0_IMEM_PE_SHIFT                    (0x00000000U)
#define CSL_ICSSM_CFG_ISP_PRU0_IMEM_PE_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_ISP_PRU0_IMEM_PE_MAX                      (0x0000000fU)

#define CSL_ICSSM_CFG_ISP_RESETVAL                              (0x00000000U)

/* IESP */

#define CSL_ICSSM_CFG_IESP_RAM_PE_SET_MASK                      (0x000F0000U)
#define CSL_ICSSM_CFG_IESP_RAM_PE_SET_SHIFT                     (0x00000010U)
#define CSL_ICSSM_CFG_IESP_RAM_PE_SET_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_CFG_IESP_RAM_PE_SET_MAX                       (0x0000000fU)

#define CSL_ICSSM_CFG_IESP_PRU1_DMEM_PE_SET_MASK                (0x0000F000U)
#define CSL_ICSSM_CFG_IESP_PRU1_DMEM_PE_SET_SHIFT               (0x0000000CU)
#define CSL_ICSSM_CFG_IESP_PRU1_DMEM_PE_SET_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IESP_PRU1_DMEM_PE_SET_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IESP_PRU1_IMEM_PE_SET_MASK                (0x00000F00U)
#define CSL_ICSSM_CFG_IESP_PRU1_IMEM_PE_SET_SHIFT               (0x00000008U)
#define CSL_ICSSM_CFG_IESP_PRU1_IMEM_PE_SET_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IESP_PRU1_IMEM_PE_SET_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IESP_PRU0_DMEM_PE_SET_MASK                (0x000000F0U)
#define CSL_ICSSM_CFG_IESP_PRU0_DMEM_PE_SET_SHIFT               (0x00000004U)
#define CSL_ICSSM_CFG_IESP_PRU0_DMEM_PE_SET_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IESP_PRU0_DMEM_PE_SET_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IESP_PRU0_IMEM_PE_SET_MASK                (0x0000000FU)
#define CSL_ICSSM_CFG_IESP_PRU0_IMEM_PE_SET_SHIFT               (0x00000000U)
#define CSL_ICSSM_CFG_IESP_PRU0_IMEM_PE_SET_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IESP_PRU0_IMEM_PE_SET_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IESP_RESETVAL                             (0x00000000U)

/* IECP */

#define CSL_ICSSM_CFG_IECP_PRU1_DMEM_PE_CLR_MASK                (0x0000F000U)
#define CSL_ICSSM_CFG_IECP_PRU1_DMEM_PE_CLR_SHIFT               (0x0000000CU)
#define CSL_ICSSM_CFG_IECP_PRU1_DMEM_PE_CLR_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IECP_PRU1_DMEM_PE_CLR_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IECP_PRU1_IMEM_PE_CLR_MASK                (0x00000F00U)
#define CSL_ICSSM_CFG_IECP_PRU1_IMEM_PE_CLR_SHIFT               (0x00000008U)
#define CSL_ICSSM_CFG_IECP_PRU1_IMEM_PE_CLR_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IECP_PRU1_IMEM_PE_CLR_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IECP_PRU0_DMEM_PE_CLR_MASK                (0x000000F0U)
#define CSL_ICSSM_CFG_IECP_PRU0_DMEM_PE_CLR_SHIFT               (0x00000004U)
#define CSL_ICSSM_CFG_IECP_PRU0_DMEM_PE_CLR_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IECP_PRU0_DMEM_PE_CLR_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IECP_PRU0_IMEM_PE_CLR_MASK                (0x0000000FU)
#define CSL_ICSSM_CFG_IECP_PRU0_IMEM_PE_CLR_SHIFT               (0x00000000U)
#define CSL_ICSSM_CFG_IECP_PRU0_IMEM_PE_CLR_RESETVAL            (0x00000000U)
#define CSL_ICSSM_CFG_IECP_PRU0_IMEM_PE_CLR_MAX                 (0x0000000fU)

#define CSL_ICSSM_CFG_IECP_RESETVAL                             (0x00000000U)

/* SCRP */

#define CSL_ICSSM_CFG_SCRP_SCRP_18_MASK                         (0x00200000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_18_SHIFT                        (0x00000015U)
#define CSL_ICSSM_CFG_SCRP_SCRP_18_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_18_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_17_MASK                         (0x00100000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_17_SHIFT                        (0x00000014U)
#define CSL_ICSSM_CFG_SCRP_SCRP_17_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_17_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_16_MASK                         (0x00080000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_16_SHIFT                        (0x00000013U)
#define CSL_ICSSM_CFG_SCRP_SCRP_16_RESETVAL                     (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_16_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_15_MASK                         (0x00040000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_15_SHIFT                        (0x00000012U)
#define CSL_ICSSM_CFG_SCRP_SCRP_15_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_15_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_14_MASK                         (0x00020000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_14_SHIFT                        (0x00000011U)
#define CSL_ICSSM_CFG_SCRP_SCRP_14_RESETVAL                     (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_14_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_13_MASK                         (0x00010000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_13_SHIFT                        (0x00000010U)
#define CSL_ICSSM_CFG_SCRP_SCRP_13_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_13_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_12_MASK                         (0x00008000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_12_SHIFT                        (0x0000000FU)
#define CSL_ICSSM_CFG_SCRP_SCRP_12_RESETVAL                     (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_12_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_11_MASK                         (0x00004000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_11_SHIFT                        (0x0000000EU)
#define CSL_ICSSM_CFG_SCRP_SCRP_11_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_11_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_10_MASK                         (0x00002000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_10_SHIFT                        (0x0000000DU)
#define CSL_ICSSM_CFG_SCRP_SCRP_10_RESETVAL                     (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_10_MAX                          (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_9_MASK                          (0x00001000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_9_SHIFT                         (0x0000000CU)
#define CSL_ICSSM_CFG_SCRP_SCRP_9_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_9_MAX                           (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_8_MASK                          (0x00000800U)
#define CSL_ICSSM_CFG_SCRP_SCRP_8_SHIFT                         (0x0000000BU)
#define CSL_ICSSM_CFG_SCRP_SCRP_8_RESETVAL                      (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_8_MAX                           (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_7_MASK                          (0x00000400U)
#define CSL_ICSSM_CFG_SCRP_SCRP_7_SHIFT                         (0x0000000AU)
#define CSL_ICSSM_CFG_SCRP_SCRP_7_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_7_MAX                           (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_6_MASK                          (0x00000200U)
#define CSL_ICSSM_CFG_SCRP_SCRP_6_SHIFT                         (0x00000009U)
#define CSL_ICSSM_CFG_SCRP_SCRP_6_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_6_MAX                           (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_5_MASK                          (0x00000100U)
#define CSL_ICSSM_CFG_SCRP_SCRP_5_SHIFT                         (0x00000008U)
#define CSL_ICSSM_CFG_SCRP_SCRP_5_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_5_MAX                           (0x00000001U)

#define CSL_ICSSM_CFG_SCRP_SCRP_4_MASK                          (0x000000C0U)
#define CSL_ICSSM_CFG_SCRP_SCRP_4_SHIFT                         (0x00000006U)
#define CSL_ICSSM_CFG_SCRP_SCRP_4_RESETVAL                      (0x00000001U)
#define CSL_ICSSM_CFG_SCRP_SCRP_4_MAX                           (0x00000003U)

#define CSL_ICSSM_CFG_SCRP_SCRP_3_MASK                          (0x00000030U)
#define CSL_ICSSM_CFG_SCRP_SCRP_3_SHIFT                         (0x00000004U)
#define CSL_ICSSM_CFG_SCRP_SCRP_3_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_3_MAX                           (0x00000003U)

#define CSL_ICSSM_CFG_SCRP_SCRP_2_MASK                          (0x0000000CU)
#define CSL_ICSSM_CFG_SCRP_SCRP_2_SHIFT                         (0x00000002U)
#define CSL_ICSSM_CFG_SCRP_SCRP_2_RESETVAL                      (0x00000002U)
#define CSL_ICSSM_CFG_SCRP_SCRP_2_MAX                           (0x00000003U)

#define CSL_ICSSM_CFG_SCRP_SCRP_1_MASK                          (0x00000003U)
#define CSL_ICSSM_CFG_SCRP_SCRP_1_SHIFT                         (0x00000000U)
#define CSL_ICSSM_CFG_SCRP_SCRP_1_RESETVAL                      (0x00000003U)
#define CSL_ICSSM_CFG_SCRP_SCRP_1_MAX                           (0x00000003U)

#define CSL_ICSSM_CFG_SCRP_RESETVAL                             (0x000aa84bU)

/* PMAO */

#define CSL_ICSSM_CFG_PMAO_PMAO_PRU1_MASK                       (0x00000002U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU1_SHIFT                      (0x00000001U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU1_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU1_MAX                        (0x00000001U)

#define CSL_ICSSM_CFG_PMAO_PMAO_PRU0_MASK                       (0x00000001U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU0_SHIFT                      (0x00000000U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU0_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_CFG_PMAO_PMAO_PRU0_MAX                        (0x00000001U)

#define CSL_ICSSM_CFG_PMAO_RESETVAL                             (0x00000000U)

/* MII_RT */

#define CSL_ICSSM_CFG_MII_RT_MII_RT_EVENT_EN_MASK               (0x00000001U)
#define CSL_ICSSM_CFG_MII_RT_MII_RT_EVENT_EN_SHIFT              (0x00000000U)
#define CSL_ICSSM_CFG_MII_RT_MII_RT_EVENT_EN_RESETVAL           (0x00000001U)
#define CSL_ICSSM_CFG_MII_RT_MII_RT_EVENT_EN_MAX                (0x00000001U)

#define CSL_ICSSM_CFG_MII_RT_RESETVAL                           (0x00000001U)

/* IEPCLK */

#define CSL_ICSSM_CFG_IEPCLK_OCP_EN_MASK                        (0x00000001U)
#define CSL_ICSSM_CFG_IEPCLK_OCP_EN_SHIFT                       (0x00000000U)
#define CSL_ICSSM_CFG_IEPCLK_OCP_EN_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_CFG_IEPCLK_OCP_EN_MAX                         (0x00000001U)

#define CSL_ICSSM_CFG_IEPCLK_RESETVAL                           (0x00000000U)

/* SPP */

#define CSL_ICSSM_CFG_SPP_XFR_SHIFT_EN_MASK                     (0x00000002U)
#define CSL_ICSSM_CFG_SPP_XFR_SHIFT_EN_SHIFT                    (0x00000001U)
#define CSL_ICSSM_CFG_SPP_XFR_SHIFT_EN_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_CFG_SPP_XFR_SHIFT_EN_MAX                      (0x00000001U)

#define CSL_ICSSM_CFG_SPP_PRU1_PAD_HP_EN_MASK                   (0x00000001U)
#define CSL_ICSSM_CFG_SPP_PRU1_PAD_HP_EN_SHIFT                  (0x00000000U)
#define CSL_ICSSM_CFG_SPP_PRU1_PAD_HP_EN_RESETVAL               (0x00000000U)
#define CSL_ICSSM_CFG_SPP_PRU1_PAD_HP_EN_MAX                    (0x00000001U)

#define CSL_ICSSM_CFG_SPP_RESETVAL                              (0x00000000U)

/* PIN_MX */

#define CSL_ICSSM_CFG_PIN_MX_PIN_MUX_SEL_MASK                   (0x000000FFU)
#define CSL_ICSSM_CFG_PIN_MX_PIN_MUX_SEL_SHIFT                  (0x00000000U)
#define CSL_ICSSM_CFG_PIN_MX_PIN_MUX_SEL_RESETVAL               (0x00000000U)
#define CSL_ICSSM_CFG_PIN_MX_PIN_MUX_SEL_MAX                    (0x000000ffU)

#define CSL_ICSSM_CFG_PIN_MX_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
