/*
* hw_icss_uart.h
*
* Register-level header file for HW_ICSS_UART
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
#ifndef HW_ICSS_UART_H_
#define HW_ICSS_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_UART_RBR_TBR                                   (0x0U)
#define HW_ICSS_UART_IER                                       (0x4U)
#define HW_ICSS_UART_IIR_FCR                                   (0x8U)
#define HW_ICSS_UART_LCR                                       (0xcU)
#define HW_ICSS_UART_MCR                                       (0x10U)
#define HW_ICSS_UART_LSR                                       (0x14U)
#define HW_ICSS_UART_MSR                                       (0x18U)
#define HW_ICSS_UART_SCR                                       (0x1cU)
#define HW_ICSS_UART_DLL                                       (0x20U)
#define HW_ICSS_UART_DLH                                       (0x24U)
#define HW_ICSS_UART_PID                                       (0x28U)
#define HW_ICSS_UART_PWREMU_MGMT                               (0x30U)
#define HW_ICSS_UART_MDR                                       (0x34U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_UART_RBR_TBR_RBR_DATA_SHIFT                    (0U)
#define HW_ICSS_UART_RBR_TBR_RBR_DATA_MASK                     (0x000000ffU)

#define HW_ICSS_UART_RBR_TBR_TBR_DATA_SHIFT                    (8U)
#define HW_ICSS_UART_RBR_TBR_TBR_DATA_MASK                     (0x0003ff00U)

#define HW_ICSS_UART_IER_ERBI_SHIFT                            (0U)
#define HW_ICSS_UART_IER_ERBI_MASK                             (0x00000001U)

#define HW_ICSS_UART_IER_ETBEI_SHIFT                           (1U)
#define HW_ICSS_UART_IER_ETBEI_MASK                            (0x00000002U)

#define HW_ICSS_UART_IER_ELSI_SHIFT                            (2U)
#define HW_ICSS_UART_IER_ELSI_MASK                             (0x00000004U)

#define HW_ICSS_UART_IER_EDSSI_SHIFT                           (3U)
#define HW_ICSS_UART_IER_EDSSI_MASK                            (0x00000008U)

#define HW_ICSS_UART_IIR_FCR_IIR_IPEND_SHIFT                   (0U)
#define HW_ICSS_UART_IIR_FCR_IIR_IPEND_MASK                    (0x00000001U)

#define HW_ICSS_UART_IIR_FCR_IIR_INTID_SHIFT                   (1U)
#define HW_ICSS_UART_IIR_FCR_IIR_INTID_MASK                    (0x0000000eU)

#define HW_ICSS_UART_IIR_FCR_IIR_FIFOEN_SHIFT                  (6U)
#define HW_ICSS_UART_IIR_FCR_IIR_FIFOEN_MASK                   (0x000000c0U)

#define HW_ICSS_UART_IIR_FCR_FCR_FIFOEN_SHIFT                  (8U)
#define HW_ICSS_UART_IIR_FCR_FCR_FIFOEN_MASK                   (0x00000100U)

#define HW_ICSS_UART_IIR_FCR_FCR_RXCLR_SHIFT                   (9U)
#define HW_ICSS_UART_IIR_FCR_FCR_RXCLR_MASK                    (0x00000200U)

#define HW_ICSS_UART_IIR_FCR_FCR_TXCLR_SHIFT                   (10U)
#define HW_ICSS_UART_IIR_FCR_FCR_TXCLR_MASK                    (0x00000400U)

#define HW_ICSS_UART_IIR_FCR_FCR_DMAMODE1_SHIFT                (11U)
#define HW_ICSS_UART_IIR_FCR_FCR_DMAMODE1_MASK                 (0x00000800U)

#define HW_ICSS_UART_IIR_FCR_FCR_RXFIFTL_SHIFT                 (14U)
#define HW_ICSS_UART_IIR_FCR_FCR_RXFIFTL_MASK                  (0x0000c000U)

#define HW_ICSS_UART_LCR_WLS0_SHIFT                            (0U)
#define HW_ICSS_UART_LCR_WLS0_MASK                             (0x00000001U)

#define HW_ICSS_UART_LCR_WLS1_SHIFT                            (1U)
#define HW_ICSS_UART_LCR_WLS1_MASK                             (0x00000002U)

#define HW_ICSS_UART_LCR_STB_SHIFT                             (2U)
#define HW_ICSS_UART_LCR_STB_MASK                              (0x00000004U)

#define HW_ICSS_UART_LCR_PEN_SHIFT                             (3U)
#define HW_ICSS_UART_LCR_PEN_MASK                              (0x00000008U)

#define HW_ICSS_UART_LCR_EPS_SHIFT                             (4U)
#define HW_ICSS_UART_LCR_EPS_MASK                              (0x00000010U)

#define HW_ICSS_UART_LCR_SP_SHIFT                              (5U)
#define HW_ICSS_UART_LCR_SP_MASK                               (0x00000020U)

#define HW_ICSS_UART_LCR_BC_SHIFT                              (6U)
#define HW_ICSS_UART_LCR_BC_MASK                               (0x00000040U)

#define HW_ICSS_UART_LCR_DLAB_SHIFT                            (7U)
#define HW_ICSS_UART_LCR_DLAB_MASK                             (0x00000080U)

#define HW_ICSS_UART_MCR_RTS_SHIFT                             (1U)
#define HW_ICSS_UART_MCR_RTS_MASK                              (0x00000002U)

#define HW_ICSS_UART_MCR_OUT1_SHIFT                            (2U)
#define HW_ICSS_UART_MCR_OUT1_MASK                             (0x00000004U)

#define HW_ICSS_UART_MCR_OUT2_SHIFT                            (3U)
#define HW_ICSS_UART_MCR_OUT2_MASK                             (0x00000008U)

#define HW_ICSS_UART_MCR_LOOP_SHIFT                            (4U)
#define HW_ICSS_UART_MCR_LOOP_MASK                             (0x00000010U)

#define HW_ICSS_UART_MCR_AFE_SHIFT                             (5U)
#define HW_ICSS_UART_MCR_AFE_MASK                              (0x00000020U)

#define HW_ICSS_UART_LSR_DR_SHIFT                              (0U)
#define HW_ICSS_UART_LSR_DR_MASK                               (0x00000001U)

#define HW_ICSS_UART_LSR_OE_SHIFT                              (1U)
#define HW_ICSS_UART_LSR_OE_MASK                               (0x00000002U)

#define HW_ICSS_UART_LSR_PE_SHIFT                              (2U)
#define HW_ICSS_UART_LSR_PE_MASK                               (0x00000004U)

#define HW_ICSS_UART_LSR_FE_SHIFT                              (3U)
#define HW_ICSS_UART_LSR_FE_MASK                               (0x00000008U)

#define HW_ICSS_UART_LSR_BI_SHIFT                              (4U)
#define HW_ICSS_UART_LSR_BI_MASK                               (0x00000010U)

#define HW_ICSS_UART_LSR_THRE_SHIFT                            (5U)
#define HW_ICSS_UART_LSR_THRE_MASK                             (0x00000020U)

#define HW_ICSS_UART_LSR_TEMT_SHIFT                            (6U)
#define HW_ICSS_UART_LSR_TEMT_MASK                             (0x00000040U)

#define HW_ICSS_UART_LSR_RXFIFOE_SHIFT                         (7U)
#define HW_ICSS_UART_LSR_RXFIFOE_MASK                          (0x00000080U)

#define HW_ICSS_UART_MSR_DCTS_SHIFT                            (0U)
#define HW_ICSS_UART_MSR_DCTS_MASK                             (0x00000001U)

#define HW_ICSS_UART_MSR_DDSR_SHIFT                            (1U)
#define HW_ICSS_UART_MSR_DDSR_MASK                             (0x00000002U)

#define HW_ICSS_UART_MSR_TERI_SHIFT                            (2U)
#define HW_ICSS_UART_MSR_TERI_MASK                             (0x00000004U)

#define HW_ICSS_UART_MSR_DCD_SHIFT                             (3U)
#define HW_ICSS_UART_MSR_DCD_MASK                              (0x00000008U)

#define HW_ICSS_UART_MSR_CTS_SHIFT                             (4U)
#define HW_ICSS_UART_MSR_CTS_MASK                              (0x00000010U)

#define HW_ICSS_UART_MSR_DSR_SHIFT                             (5U)
#define HW_ICSS_UART_MSR_DSR_MASK                              (0x00000020U)

#define HW_ICSS_UART_MSR_RI_SHIFT                              (6U)
#define HW_ICSS_UART_MSR_RI_MASK                               (0x00000040U)

#define HW_ICSS_UART_MSR_CD_SHIFT                              (7U)
#define HW_ICSS_UART_MSR_CD_MASK                               (0x00000080U)

#define HW_ICSS_UART_SCR_DATA_SHIFT                            (0U)
#define HW_ICSS_UART_SCR_DATA_MASK                             (0x000000ffU)

#define HW_ICSS_UART_DLL_SHIFT                                 (0U)
#define HW_ICSS_UART_DLL_MASK                                  (0x000000ffU)

#define HW_ICSS_UART_DLH_SHIFT                                 (0U)
#define HW_ICSS_UART_DLH_MASK                                  (0x000000ffU)

#define HW_ICSS_UART_PID_SHIFT                                 (0U)
#define HW_ICSS_UART_PID_MASK                                  (0xffffffffU)

#define HW_ICSS_UART_PWREMU_MGMT_FREE_SHIFT                    (0U)
#define HW_ICSS_UART_PWREMU_MGMT_FREE_MASK                     (0x00000001U)

#define HW_ICSS_UART_PWREMU_MGMT_URRST_SHIFT                   (13U)
#define HW_ICSS_UART_PWREMU_MGMT_URRST_MASK                    (0x00002000U)

#define HW_ICSS_UART_PWREMU_MGMT_UTRST_SHIFT                   (14U)
#define HW_ICSS_UART_PWREMU_MGMT_UTRST_MASK                    (0x00004000U)

#define HW_ICSS_UART_MDR_OSM_SEL_SHIFT                         (0U)
#define HW_ICSS_UART_MDR_OSM_SEL_MASK                          (0x00000001U)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_UART_H_ */
