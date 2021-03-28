/********************************************************************
 * Copyright (C) 2013-2016 Texas Instruments Incorporated.
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
#ifndef CSLR_UART_H
#define CSLR_UART_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for TOP_LEVEL
**************************************************************************/
typedef struct {
    volatile Uint32 RBR;
    volatile Uint32 IER;
    volatile Uint32 IIR;
    volatile Uint32 LCR;
    volatile Uint32 MCR;
    volatile Uint32 LSR;
    volatile Uint32 MSR;
    volatile Uint32 SCR;
    volatile Uint32 DLL;
    volatile Uint32 DLH;
    volatile Uint32 REVID1;
    volatile Uint32 REVID2;
    volatile Uint32 PWREMU_MGMT;
    volatile Uint32 MDR;
} CSL_UartRegs;


#ifndef CSL_MODIFICATION    

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_UartRegs             *CSL_UartRegsOvly;

/* Following 2 lines are added due to CSL3.x tools limitations */
#define THR RBR   /* RBR & THR have same offset */
#define FCR IIR   /* IIR & FCR have same offset */
#endif

/**************************************************************************
* Register Macros
**************************************************************************/

/* RBR */
#define CSL_UART_RBR                                            ((uint32_t)0x0U)

/* IER */
#define CSL_UART_IER                                            ((uint32_t)0x4U)

/* IIR */
#define CSL_UART_IIR                                            ((uint32_t)0x8U)

/* LCR */
#define CSL_UART_LCR                                            ((uint32_t)0xCU)

/* MCR */
#define CSL_UART_MCR                                            ((uint32_t)0x10U)

/* LSR */
#define CSL_UART_LSR                                            ((uint32_t)0x14U)

/* MSR */
#define CSL_UART_MSR                                            ((uint32_t)0x18U)

/* SCR */
#define CSL_UART_SCR                                            ((uint32_t)0x1CU)

/* DLL */
#define CSL_UART_DLL                                            ((uint32_t)0x20U)

/* DLH */
#define CSL_UART_DLH                                            ((uint32_t)0x24U)

/* REVID1 */
#define CSL_UART_REVID1                                         ((uint32_t)0x28U)

/* REVID2 */
#define CSL_UART_REVID2                                         ((uint32_t)0x2CU)

/* PWREMU_MGMT */
#define CSL_UART_PWREMU_MGMT                                    ((uint32_t)0x30U)

/* MDR */
#define CSL_UART_MDR                                            ((uint32_t)0x34U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* RBR */

#define CSL_UART_RBR_DATA_MASK                                  ((uint32_t)0x000000FFU)
#define CSL_UART_RBR_DATA_SHIFT                                 ((uint32_t)0U)
#define CSL_UART_RBR_DATA_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_RBR_DATA_MAX                                   ((uint32_t)0x000000ffU)

#define CSL_UART_RBR_TBR_DATA_MASK                              ((uint32_t)0x0001FF00U)
#define CSL_UART_RBR_TBR_DATA_SHIFT                             ((uint32_t)8U)
#define CSL_UART_RBR_TBR_DATA_RESETVAL                          ((uint32_t)0x00000000U)
#define CSL_UART_RBR_TBR_DATA_MAX                               ((uint32_t)0x000001ffU)

#define CSL_UART_RBR_RESETVAL                                   ((uint32_t)0x00000000U)
#ifndef CSL_MODIFICATION    

/* THR */


#define CSL_UART_THR_DATA_MASK           ((uint32_t)0x000000FFu)
#define CSL_UART_THR_DATA_SHIFT          ((uint32_t)0x00000000u)
#define CSL_UART_THR_DATA_RESETVAL       ((uint32_t)0x00000000u)

#define CSL_UART_THR_RESETVAL            ((uint32_t)0x00000000u)
#endif


/* IER */

#define CSL_UART_IER_ERBI_MASK                                  ((uint32_t)0x00000001U)
#define CSL_UART_IER_ERBI_SHIFT                                 ((uint32_t)0U)
#define CSL_UART_IER_ERBI_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_IER_ERBI_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_IER_ERBI_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_IER_ETBEI_MASK                                 ((uint32_t)0x00000002U)
#define CSL_UART_IER_ETBEI_SHIFT                                ((uint32_t)1U)
#define CSL_UART_IER_ETBEI_RESETVAL                             ((uint32_t)0x00000000U)
#define CSL_UART_IER_ETBEI_DISABLE                              ((uint32_t)0x00000000U)
#define CSL_UART_IER_ETBEI_ENABLE                               ((uint32_t)0x00000001U)

#define CSL_UART_IER_ELSI_MASK                                  ((uint32_t)0x00000004U)
#define CSL_UART_IER_ELSI_SHIFT                                 ((uint32_t)2U)
#define CSL_UART_IER_ELSI_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_IER_ELSI_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_IER_ELSI_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_IER_EDSSI_MASK                                 ((uint32_t)0x00000008U)
#define CSL_UART_IER_EDSSI_SHIFT                                ((uint32_t)3U)
#define CSL_UART_IER_EDSSI_RESETVAL                             ((uint32_t)0x00000000U)
#define CSL_UART_IER_EDSSI_DISABLE                              ((uint32_t)0x00000000U)
#define CSL_UART_IER_EDSSI_ENABLE                               ((uint32_t)0x00000001U)

#define CSL_UART_IER_RESETVAL                                   ((uint32_t)0x00000000U)

/* IIR */

#define CSL_UART_IIR_IPEND_MASK                                 ((uint32_t)0x00000001U)
#define CSL_UART_IIR_IPEND_SHIFT                                ((uint32_t)0U)
#define CSL_UART_IIR_IPEND_RESETVAL                             ((uint32_t)0x00000000U)
#define CSL_UART_IIR_IPEND_PEND                                 ((uint32_t)0x00000000U)
#define CSL_UART_IIR_IPEND_NO_PEND                              ((uint32_t)0x00000001U)

#define CSL_UART_IIR_INITD_MASK                                 ((uint32_t)0x0000000EU)
#define CSL_UART_IIR_INITD_SHIFT                                ((uint32_t)1U)
#define CSL_UART_IIR_INITD_RESETVAL                             ((uint32_t)0x00000000U)
#define CSL_UART_IIR_INITD_MODSTAT                              ((uint32_t)0x00000000U)
#define CSL_UART_IIR_INITD_THRE                                 ((uint32_t)0x00000001U)
#define CSL_UART_IIR_INITD_RDA                                  ((uint32_t)0x00000002U)
#define CSL_UART_IIR_INITD_RLS                                  ((uint32_t)0x00000003U)
#define CSL_UART_IIR_INITD_CTI                                  ((uint32_t)0x00000006U)

#define CSL_UART_IIR_FIFOEN_MASK                                ((uint32_t)0x000000C0U)
#define CSL_UART_IIR_FIFOEN_SHIFT                               ((uint32_t)6U)
#define CSL_UART_IIR_FIFOEN_RESETVAL                            ((uint32_t)0x00000000U)
#define CSL_UART_IIR_FIFOEN_DISABLE                             ((uint32_t)0x00000000U)
#define CSL_UART_IIR_FIFOEN_ENABLE                              ((uint32_t)0x00000001U)

#define CSL_UART_IIR_FIFO_ENABLE_MASK                           ((uint32_t)0x00000100U)
#define CSL_UART_IIR_FIFO_ENABLE_SHIFT                          ((uint32_t)8U)
#define CSL_UART_IIR_FIFO_ENABLE_RESETVAL                       ((uint32_t)0x00000000U)
#define CSL_UART_IIR_FIFO_ENABLE_MAX                            ((uint32_t)0x00000001U)

#define CSL_UART_IIR_RCVR_FIFO_RESET_MASK                       ((uint32_t)0x00000200U)
#define CSL_UART_IIR_RCVR_FIFO_RESET_SHIFT                      ((uint32_t)9U)
#define CSL_UART_IIR_RCVR_FIFO_RESET_RESETVAL                   ((uint32_t)0x00000000U)
#define CSL_UART_IIR_RCVR_FIFO_RESET_MAX                        ((uint32_t)0x00000001U)

#define CSL_UART_IIR_TRAN_FIFO_RESET_MASK                       ((uint32_t)0x00000400U)
#define CSL_UART_IIR_TRAN_FIFO_RESET_SHIFT                      ((uint32_t)10U)
#define CSL_UART_IIR_TRAN_FIFO_RESET_RESETVAL                   ((uint32_t)0x00000000U)
#define CSL_UART_IIR_TRAN_FIFO_RESET_MAX                        ((uint32_t)0x00000001U)

#define CSL_UART_IIR_DMA_MODE_SELECT_MASK                       ((uint32_t)0x00000800U)
#define CSL_UART_IIR_DMA_MODE_SELECT_SHIFT                      ((uint32_t)11U)
#define CSL_UART_IIR_DMA_MODE_SELECT_RESETVAL                   ((uint32_t)0x00000000U)
#define CSL_UART_IIR_DMA_MODE_SELECT_MAX                        ((uint32_t)0x00000001U)

#define CSL_UART_IIR_RCVR_TRIG_LSB_MASK                         ((uint32_t)0x00004000U)
#define CSL_UART_IIR_RCVR_TRIG_LSB_SHIFT                        ((uint32_t)14U)
#define CSL_UART_IIR_RCVR_TRIG_LSB_RESETVAL                     ((uint32_t)0x00000000U)
#define CSL_UART_IIR_RCVR_TRIG_LSB_MAX                          ((uint32_t)0x00000001U)

#define CSL_UART_IIR_RCVR_TRIG_MSB_MASK                         ((uint32_t)0x00008000U)
#define CSL_UART_IIR_RCVR_TRIG_MSB_SHIFT                        ((uint32_t)15U)
#define CSL_UART_IIR_RCVR_TRIG_MSB_RESETVAL                     ((uint32_t)0x00000000U)
#define CSL_UART_IIR_RCVR_TRIG_MSB_MAX                          ((uint32_t)0x00000001U)

#define CSL_UART_IIR_RESETVAL                                   ((uint32_t)0x00000000U)
#ifndef CSL_MODIFICATION    

/* FCR */


#define CSL_UART_FCR_RXFIFTL_MASK        ((uint32_t)0x000000C0u)
#define CSL_UART_FCR_RXFIFTL_SHIFT       ((uint32_t)0x00000006u)
#define CSL_UART_FCR_RXFIFTL_RESETVAL    ((uint32_t)0x00000000u)
/*----RXFIFTL Tokens----*/
#define CSL_UART_FCR_RXFIFTL_CHAR1       ((uint32_t)0x00000000u)
#define CSL_UART_FCR_RXFIFTL_CHAR4       ((uint32_t)0x00000001u)
#define CSL_UART_FCR_RXFIFTL_CHAR8       ((uint32_t)0x00000002u)
#define CSL_UART_FCR_RXFIFTL_CHAR14      ((uint32_t)0x00000003u)


#define CSL_UART_FCR_DMAMODE1_MASK       ((uint32_t)0x00000008u)
#define CSL_UART_FCR_DMAMODE1_SHIFT      ((uint32_t)0x00000003u)
#define CSL_UART_FCR_DMAMODE1_RESETVAL   ((uint32_t)0x00000000u)
/*----DMAMODE1 Tokens----*/
#define CSL_UART_FCR_DMAMODE1_DISABLE    ((uint32_t)0x00000000u)
#define CSL_UART_FCR_DMAMODE1_ENABLE     ((uint32_t)0x00000001u)

#define CSL_UART_FCR_TXCLR_MASK          ((uint32_t)0x00000004u)
#define CSL_UART_FCR_TXCLR_SHIFT         ((uint32_t)0x00000002u)
#define CSL_UART_FCR_TXCLR_RESETVAL      ((uint32_t)0x00000000u)
/*----TXCLR Tokens----*/
#define CSL_UART_FCR_TXCLR_CLR           ((uint32_t)0x00000001u)

#define CSL_UART_FCR_RXCLR_MASK          ((uint32_t)0x00000002u)
#define CSL_UART_FCR_RXCLR_SHIFT         ((uint32_t)0x00000001u)
#define CSL_UART_FCR_RXCLR_RESETVAL      ((uint32_t)0x00000000u)
/*----RXCLR Tokens----*/
#define CSL_UART_FCR_RXCLR_CLR           ((uint32_t)0x00000001u)

#define CSL_UART_FCR_FIFOEN_MASK         ((uint32_t)0x00000001u)
#define CSL_UART_FCR_FIFOEN_SHIFT        ((uint32_t)0x00000000u)
#define CSL_UART_FCR_FIFOEN_RESETVAL     ((uint32_t)0x00000000u)
/*----FIFOEN Tokens----*/
#define CSL_UART_FCR_FIFOEN_DISABLE      ((uint32_t)0x00000000u)
#define CSL_UART_FCR_FIFOEN_ENABLE       ((uint32_t)0x00000001u)

#define CSL_UART_FCR_RESETVAL            ((uint32_t)0x00000000u)
#endif

/* LCR */

#define CSL_UART_LCR_WLS_MASK                                   ((uint32_t)0x00000003U)
#define CSL_UART_LCR_WLS_SHIFT                                  ((uint32_t)0U)
#define CSL_UART_LCR_WLS_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_LCR_WLS__5BITS                                 ((uint32_t)0x00000000U)
#define CSL_UART_LCR_WLS__6BITS                                 ((uint32_t)0x00000001U)
#define CSL_UART_LCR_WLS__7BITS                                 ((uint32_t)0x00000002U)
#define CSL_UART_LCR_WLS__8BITS                                 ((uint32_t)0x00000003U)

#define CSL_UART_LCR_STB_MASK                                   ((uint32_t)0x00000004U)
#define CSL_UART_LCR_STB_SHIFT                                  ((uint32_t)2U)
#define CSL_UART_LCR_STB_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_LCR_STB__1BIT                                  ((uint32_t)0x00000000U)
#define CSL_UART_LCR_STB_WLS                                    ((uint32_t)0x00000001U)

#define CSL_UART_LCR_PEN_MASK                                   ((uint32_t)0x00000008U)
#define CSL_UART_LCR_PEN_SHIFT                                  ((uint32_t)3U)
#define CSL_UART_LCR_PEN_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_LCR_PEN_DISABLE                                ((uint32_t)0x00000000U)
#define CSL_UART_LCR_PEN_ENABLE                                 ((uint32_t)0x00000001U)

#define CSL_UART_LCR_EPS_MASK                                   ((uint32_t)0x00000010U)
#define CSL_UART_LCR_EPS_SHIFT                                  ((uint32_t)4U)
#define CSL_UART_LCR_EPS_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_LCR_EPS_ODD                                    ((uint32_t)0x00000000U)
#define CSL_UART_LCR_EPS_EVEN                                   ((uint32_t)0x00000001U)

#define CSL_UART_LCR_SP_MASK                                    ((uint32_t)0x00000020U)
#define CSL_UART_LCR_SP_SHIFT                                   ((uint32_t)5U)
#define CSL_UART_LCR_SP_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LCR_SP_DISABLE                                 ((uint32_t)0x00000000U)
#define CSL_UART_LCR_SP_ENABLE                                  ((uint32_t)0x00000001U)

#define CSL_UART_LCR_BC_MASK                                    ((uint32_t)0x00000040U)
#define CSL_UART_LCR_BC_SHIFT                                   ((uint32_t)6U)
#define CSL_UART_LCR_BC_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LCR_BC_DISABLE                                 ((uint32_t)0x00000000U)
#define CSL_UART_LCR_BC_ENABLE                                  ((uint32_t)0x00000001U)

#define CSL_UART_LCR_DLAB_MASK                                  ((uint32_t)0x00000080U)
#define CSL_UART_LCR_DLAB_SHIFT                                 ((uint32_t)7U)
#define CSL_UART_LCR_DLAB_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_LCR_DLAB_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_LCR_DLAB_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_LCR_RESETVAL                                   ((uint32_t)0x00000000U)

/* MCR */

#define CSL_UART_MCR_DTR_MASK                                   ((uint32_t)0x00000001U)
#define CSL_UART_MCR_DTR_SHIFT                                  ((uint32_t)0U)
#define CSL_UART_MCR_DTR_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_DTR_DISABLE                                ((uint32_t)0x00000000U)
#define CSL_UART_MCR_DTR_ENABLE                                 ((uint32_t)0x00000001U)

#define CSL_UART_MCR_RTS_MASK                                   ((uint32_t)0x00000002U)
#define CSL_UART_MCR_RTS_SHIFT                                  ((uint32_t)1U)
#define CSL_UART_MCR_RTS_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_RTS_DISABLE                                ((uint32_t)0x00000000U)
#define CSL_UART_MCR_RTS_ENABLE                                 ((uint32_t)0x00000001U)

#define CSL_UART_MCR_OUT1_MASK                                  ((uint32_t)0x00000004U)
#define CSL_UART_MCR_OUT1_SHIFT                                 ((uint32_t)2U)
#define CSL_UART_MCR_OUT1_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MCR_OUT1_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_OUT1_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_MCR_OUT2_MASK                                  ((uint32_t)0x00000008U)
#define CSL_UART_MCR_OUT2_SHIFT                                 ((uint32_t)3U)
#define CSL_UART_MCR_OUT2_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MCR_OUT2_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_OUT2_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_MCR_LOOP_MASK                                  ((uint32_t)0x00000010U)
#define CSL_UART_MCR_LOOP_SHIFT                                 ((uint32_t)4U)
#define CSL_UART_MCR_LOOP_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MCR_LOOP_DISABLE                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_LOOP_ENABLE                                ((uint32_t)0x00000001U)

#define CSL_UART_MCR_AFE_MASK                                   ((uint32_t)0x00000020U)
#define CSL_UART_MCR_AFE_SHIFT                                  ((uint32_t)5U)
#define CSL_UART_MCR_AFE_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MCR_AFE_DISABLE                                ((uint32_t)0x00000000U)
#define CSL_UART_MCR_AFE_ENABLE                                 ((uint32_t)0x00000001U)

#define CSL_UART_MCR_RESETVAL                                   ((uint32_t)0x00000000U)

/* LSR */

#define CSL_UART_LSR_DR_MASK                                    ((uint32_t)0x00000001U)
#define CSL_UART_LSR_DR_SHIFT                                   ((uint32_t)0U)
#define CSL_UART_LSR_DR_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_DR_NOTREADY                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_DR_READY                                   ((uint32_t)0x00000001U)

#define CSL_UART_LSR_OE_MASK                                    ((uint32_t)0x00000002U)
#define CSL_UART_LSR_OE_SHIFT                                   ((uint32_t)1U)
#define CSL_UART_LSR_OE_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_OE_NOERROR                                 ((uint32_t)0x00000000U)
#define CSL_UART_LSR_OE_ERROR                                   ((uint32_t)0x00000001U)

#define CSL_UART_LSR_PE_MASK                                    ((uint32_t)0x00000004U)
#define CSL_UART_LSR_PE_SHIFT                                   ((uint32_t)2U)
#define CSL_UART_LSR_PE_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_PE_NOERROR                                 ((uint32_t)0x00000000U)
#define CSL_UART_LSR_PE_ERROR                                   ((uint32_t)0x00000001U)

#define CSL_UART_LSR_FE_MASK                                    ((uint32_t)0x00000008U)
#define CSL_UART_LSR_FE_SHIFT                                   ((uint32_t)3U)
#define CSL_UART_LSR_FE_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_FE_NOERROR                                 ((uint32_t)0x00000000U)
#define CSL_UART_LSR_FE_ERROR                                   ((uint32_t)0x00000001U)

#define CSL_UART_LSR_BI_MASK                                    ((uint32_t)0x00000010U)
#define CSL_UART_LSR_BI_SHIFT                                   ((uint32_t)4U)
#define CSL_UART_LSR_BI_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_LSR_BI_NOBREAK                                 ((uint32_t)0x00000000U)
#define CSL_UART_LSR_BI_BREAK                                   ((uint32_t)0x00000001U)

#define CSL_UART_LSR_THRE_MASK                                  ((uint32_t)0x00000020U)
#define CSL_UART_LSR_THRE_SHIFT                                 ((uint32_t)5U)
#define CSL_UART_LSR_THRE_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_LSR_THRE_EMPTY                                 ((uint32_t)0x00000001U)
#define CSL_UART_LSR_THRE_FULL                                  ((uint32_t)0x00000000U)

#define CSL_UART_LSR_TEMT_MASK                                  ((uint32_t)0x00000040U)
#define CSL_UART_LSR_TEMT_SHIFT                                 ((uint32_t)6U)
#define CSL_UART_LSR_TEMT_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_LSR_TEMT_FULL                                  ((uint32_t)0x00000000U)
#define CSL_UART_LSR_TEMT_EMPTY                                 ((uint32_t)0x00000001U)

#define CSL_UART_LSR_RXFIFOE_MASK                               ((uint32_t)0x00000080U)
#define CSL_UART_LSR_RXFIFOE_SHIFT                              ((uint32_t)7U)
#define CSL_UART_LSR_RXFIFOE_RESETVAL                           ((uint32_t)0x00000000U)
#define CSL_UART_LSR_RXFIFOE_NOERROR                            ((uint32_t)0x00000000U)
#define CSL_UART_LSR_RXFIFOE_ERROR                              ((uint32_t)0x00000001U)

#define CSL_UART_LSR_RESETVAL                                   ((uint32_t)0x00000000U)

/* MSR */

#define CSL_UART_MSR_DCTS_MASK                                  ((uint32_t)0x00000001U)
#define CSL_UART_MSR_DCTS_SHIFT                                 ((uint32_t)0U)
#define CSL_UART_MSR_DCTS_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DCTS_NODCTS                                ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DCTS_DCTS                                  ((uint32_t)0x00000001U)

#define CSL_UART_MSR_DDSR_MASK                                  ((uint32_t)0x00000002U)
#define CSL_UART_MSR_DDSR_SHIFT                                 ((uint32_t)1U)
#define CSL_UART_MSR_DDSR_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DDSR_NODDSR                                ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DDSR_DDSR                                  ((uint32_t)0x00000001U)

#define CSL_UART_MSR_TERI_MASK                                  ((uint32_t)0x00000004U)
#define CSL_UART_MSR_TERI_SHIFT                                 ((uint32_t)2U)
#define CSL_UART_MSR_TERI_RESETVAL                              ((uint32_t)0x00000000U)
#define CSL_UART_MSR_TERI_NOTERI                                ((uint32_t)0x00000000U)
#define CSL_UART_MSR_TERI_TERI                                  ((uint32_t)0x00000001U)

#define CSL_UART_MSR_DCD_MASK                                   ((uint32_t)0x00000008U)
#define CSL_UART_MSR_DCD_SHIFT                                  ((uint32_t)3U)
#define CSL_UART_MSR_DCD_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DCD_NODCD                                  ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DCD_DCD                                    ((uint32_t)0x00000001U)

#define CSL_UART_MSR_CTS_MASK                                   ((uint32_t)0x00000010U)
#define CSL_UART_MSR_CTS_SHIFT                                  ((uint32_t)4U)
#define CSL_UART_MSR_CTS_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MSR_CTS_NOCTS                                  ((uint32_t)0x00000000U)
#define CSL_UART_MSR_CTS_CTS                                    ((uint32_t)0x00000001U)

#define CSL_UART_MSR_DSR_MASK                                   ((uint32_t)0x00000020U)
#define CSL_UART_MSR_DSR_SHIFT                                  ((uint32_t)5U)
#define CSL_UART_MSR_DSR_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DSR_NODSR                                  ((uint32_t)0x00000000U)
#define CSL_UART_MSR_DSR_DSR                                    ((uint32_t)0x00000001U)

#define CSL_UART_MSR_RI_MASK                                    ((uint32_t)0x00000040U)
#define CSL_UART_MSR_RI_SHIFT                                   ((uint32_t)6U)
#define CSL_UART_MSR_RI_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_MSR_RI_NORI                                    ((uint32_t)0x00000000U)
#define CSL_UART_MSR_RI_RI                                      ((uint32_t)0x00000001U)

#define CSL_UART_MSR_CD_MASK                                    ((uint32_t)0x00000080U)
#define CSL_UART_MSR_CD_SHIFT                                   ((uint32_t)7U)
#define CSL_UART_MSR_CD_RESETVAL                                ((uint32_t)0x00000000U)
#define CSL_UART_MSR_CD_CD                                      ((uint32_t)0x00000000U)
#define CSL_UART_MSR_CD_NOCD_1                                  ((uint32_t)0x00000001U)

#define CSL_UART_MSR_RESETVAL                                   ((uint32_t)0x00000000U)

/* SCR */

#define CSL_UART_SCR_SCR_MASK                                   ((uint32_t)0x000000FFU)
#define CSL_UART_SCR_SCR_SHIFT                                  ((uint32_t)0U)
#define CSL_UART_SCR_SCR_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_SCR_SCR_MAX                                    ((uint32_t)0x000000ffU)

#define CSL_UART_SCR_RESETVAL                                   ((uint32_t)0x00000000U)

/* DLL */

#define CSL_UART_DLL_DLL_MASK                                   ((uint32_t)0x000000FFU)
#define CSL_UART_DLL_DLL_SHIFT                                  ((uint32_t)0U)
#define CSL_UART_DLL_DLL_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_DLL_DLL_MAX                                    ((uint32_t)0x000000ffU)

#define CSL_UART_DLL_RESETVAL                                   ((uint32_t)0x00000000U)

/* DLH */

#define CSL_UART_DLH_DLH_MASK                                   ((uint32_t)0x000000FFU)
#define CSL_UART_DLH_DLH_SHIFT                                  ((uint32_t)0U)
#define CSL_UART_DLH_DLH_RESETVAL                               ((uint32_t)0x00000000U)
#define CSL_UART_DLH_DLH_MAX                                    ((uint32_t)0x000000ffU)

#define CSL_UART_DLH_RESETVAL                                   ((uint32_t)0x00000000U)

/* REVID1 */

#define CSL_UART_REVID1_REV_MASK                                ((uint32_t)0xFFFFFFFFU)
#define CSL_UART_REVID1_REV_SHIFT                               ((uint32_t)0U)
#define CSL_UART_REVID1_REV_RESETVAL                            ((uint32_t)0x00000000U)
#define CSL_UART_REVID1_REV_MAX                                 ((uint32_t)0xffffffffU)

#define CSL_UART_REVID1_RESETVAL                                ((uint32_t)0x00000000U)

/* REVID2 */

#define CSL_UART_REVID2_REV_MASK                                ((uint32_t)0xFFFFFFFFU)
#define CSL_UART_REVID2_REV_SHIFT                               ((uint32_t)0U)
#define CSL_UART_REVID2_REV_RESETVAL                            ((uint32_t)0x00000000U)
#define CSL_UART_REVID2_REV_MAX                                 ((uint32_t)0xffffffffU)

#define CSL_UART_REVID2_RESETVAL                                ((uint32_t)0x00000000U)

/* PWREMU_MGMT */

#define CSL_UART_PWREMU_MGMT_FREE_MASK                          ((uint32_t)0x00000001U)
#define CSL_UART_PWREMU_MGMT_FREE_SHIFT                         ((uint32_t)0U)
#define CSL_UART_PWREMU_MGMT_FREE_RESETVAL                      ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_FREE_STOP                          ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_FREE_RUN                           ((uint32_t)0x00000001U)

#define CSL_UART_PWREMU_MGMT_SOFT_MASK                          ((uint32_t)0x00000002U)
#define CSL_UART_PWREMU_MGMT_SOFT_SHIFT                         ((uint32_t)1U)
#define CSL_UART_PWREMU_MGMT_SOFT_RESETVAL                      ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_SOFT_MAX                           ((uint32_t)0x00000001U)

#define CSL_UART_PWREMU_MGMT_URRST_MASK                         ((uint32_t)0x00002000U)
#define CSL_UART_PWREMU_MGMT_URRST_SHIFT                        ((uint32_t)13U)
#define CSL_UART_PWREMU_MGMT_URRST_RESETVAL                     ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_URRST_RESET                        ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_URRST_ENABLE                       ((uint32_t)0x00000001U)

#define CSL_UART_PWREMU_MGMT_UTRST_MASK                         ((uint32_t)0x00004000U)
#define CSL_UART_PWREMU_MGMT_UTRST_SHIFT                        ((uint32_t)14U)
#define CSL_UART_PWREMU_MGMT_UTRST_RESETVAL                     ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_UTRST_RESET                        ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_UTRST_ENABLE                       ((uint32_t)0x00000001U)

#define CSL_UART_PWREMU_MGMT_URST_MASK                          ((uint32_t)0x00008000U)
#define CSL_UART_PWREMU_MGMT_URST_SHIFT                         ((uint32_t)15U)
#define CSL_UART_PWREMU_MGMT_URST_RESETVAL                      ((uint32_t)0x00000000U)
#define CSL_UART_PWREMU_MGMT_URST_MAX                           ((uint32_t)0x00000001U)

#define CSL_UART_PWREMU_MGMT_RESETVAL                           ((uint32_t)0x00000000U)

/* MDR */

#define CSL_UART_MDR_OSM_SEL_MASK                               ((uint32_t)0x00000001U)
#define CSL_UART_MDR_OSM_SEL_SHIFT                              ((uint32_t)0U)
#define CSL_UART_MDR_OSM_SEL_RESETVAL                           ((uint32_t)0x00000000U)
#define CSL_UART_MDR_OSM_SEL__16XOVERSAMPLING                   ((uint32_t)0x00000000U)
#define CSL_UART_MDR_OSM_SEL__13XOVERSAMPLING                   ((uint32_t)0x00000001U)

#define CSL_UART_MDR_RESETVAL                                   ((uint32_t)0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
