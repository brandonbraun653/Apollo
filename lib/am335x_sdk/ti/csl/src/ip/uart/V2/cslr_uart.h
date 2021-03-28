/********************************************************************
 * Copyright (C) 2020 Texas Instruments Incorporated.
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
 *  Name        : cslr_uart.h
*/
#ifndef CSLR_UART_H_
#define CSLR_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t UARTDR;
    volatile uint32_t UARTRSR_ECR;
    volatile uint8_t  Resv_24[16];
    volatile uint32_t UARTFR;
    volatile uint8_t  Resv_32[4];
    volatile uint32_t UARTILPR;
    volatile uint32_t UARTIBRD;
    volatile uint32_t UARTFBRD;
    volatile uint32_t UARTLCR_H;
    volatile uint32_t UARTCR;
    volatile uint32_t UARTIFLS;
    volatile uint32_t UARTIMSC;
    volatile uint32_t UARTRIS;
    volatile uint32_t UARTMIS;
    volatile uint32_t UARTICR;
    volatile uint32_t UARTDMACR;
    volatile uint8_t  Resv_4064[3988];
    volatile uint32_t UARTPERIPHID0;
    volatile uint32_t UARTPERIPHID1;
    volatile uint32_t UARTPERIPHID2;
    volatile uint32_t UARTPERIPHID3;
    volatile uint32_t UARTPCELLID0;
    volatile uint32_t UARTPCELLID1;
    volatile uint32_t UARTPCELLID2;
    volatile uint32_t UARTPCELLID3;
} CSL_rcss_sciRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_UART_DR                                                    (0x00000000U)
#define CSL_UART_RSR_ECR                                               (0x00000004U)
#define CSL_UART_FR                                                    (0x00000018U)
#define CSL_UART_ILPR                                                  (0x00000020U)
#define CSL_UART_IBRD                                                  (0x00000024U)
#define CSL_UART_FBRD                                                  (0x00000028U)
#define CSL_UART_LCR_H                                                 (0x0000002CU)
#define CSL_UART_CR                                                    (0x00000030U)
#define CSL_UART_IFLS                                                  (0x00000034U)
#define CSL_UART_IMSC                                                  (0x00000038U)
#define CSL_UART_RIS                                                   (0x0000003CU)
#define CSL_UART_MIS                                                   (0x00000040U)
#define CSL_UART_ICR                                                   (0x00000044U)
#define CSL_UART_DMACR                                                 (0x00000048U)
#define CSL_UART_PERIPHID0                                             (0x00000FE0U)
#define CSL_UART_PERIPHID1                                             (0x00000FE4U)
#define CSL_UART_PERIPHID2                                             (0x00000FE8U)
#define CSL_UART_PERIPHID3                                             (0x00000FECU)
#define CSL_UART_PCELLID0                                              (0x00000FF0U)
#define CSL_UART_PCELLID1                                              (0x00000FF4U)
#define CSL_UART_PCELLID2                                              (0x00000FF8U)
#define CSL_UART_PCELLID3                                              (0x00000FFCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DR */

#define CSL_UART_DR_DATA_MASK                                          (0x000000FFU)
#define CSL_UART_DR_DATA_SHIFT                                         (0x00000000U)
#define CSL_UART_DR_DATA_RESETVAL                                      (0x00000000U)
#define CSL_UART_DR_DATA_MAX                                           (0x000000FFU)

#define CSL_UART_DR_FE_MASK                                            (0x00000100U)
#define CSL_UART_DR_FE_SHIFT                                           (0x00000008U)
#define CSL_UART_DR_FE_RESETVAL                                        (0x00000000U)
#define CSL_UART_DR_FE_MAX                                             (0x00000001U)

#define CSL_UART_DR_PE_MASK                                            (0x00000200U)
#define CSL_UART_DR_PE_SHIFT                                           (0x00000009U)
#define CSL_UART_DR_PE_RESETVAL                                        (0x00000000U)
#define CSL_UART_DR_PE_MAX                                             (0x00000001U)

#define CSL_UART_DR_BE_MASK                                            (0x00000400U)
#define CSL_UART_DR_BE_SHIFT                                           (0x0000000AU)
#define CSL_UART_DR_BE_RESETVAL                                        (0x00000000U)
#define CSL_UART_DR_BE_MAX                                             (0x00000001U)

#define CSL_UART_DR_OE_MASK                                            (0x00000800U)
#define CSL_UART_DR_OE_SHIFT                                           (0x0000000BU)
#define CSL_UART_DR_OE_RESETVAL                                        (0x00000000U)
#define CSL_UART_DR_OE_MAX                                             (0x00000001U)

#define CSL_UART_DR_NU0_MASK                                           (0xFFFFF000U)
#define CSL_UART_DR_NU0_SHIFT                                          (0x0000000CU)
#define CSL_UART_DR_NU0_RESETVAL                                       (0x00000000U)
#define CSL_UART_DR_NU0_MAX                                            (0x000FFFFFU)

#define CSL_UART_DR_RESETVAL                                           (0x00000000U)

/* RSR_ECR */

#define CSL_UART_RSR_ECR_FE_MASK                                       (0x00000001U)
#define CSL_UART_RSR_ECR_FE_SHIFT                                      (0x00000000U)
#define CSL_UART_RSR_ECR_FE_RESETVAL                                   (0x00000000U)
#define CSL_UART_RSR_ECR_FE_MAX                                        (0x00000001U)

#define CSL_UART_RSR_ECR_PE_MASK                                       (0x00000002U)
#define CSL_UART_RSR_ECR_PE_SHIFT                                      (0x00000001U)
#define CSL_UART_RSR_ECR_PE_RESETVAL                                   (0x00000000U)
#define CSL_UART_RSR_ECR_PE_MAX                                        (0x00000001U)

#define CSL_UART_RSR_ECR_BE_MASK                                       (0x00000004U)
#define CSL_UART_RSR_ECR_BE_SHIFT                                      (0x00000002U)
#define CSL_UART_RSR_ECR_BE_RESETVAL                                   (0x00000000U)
#define CSL_UART_RSR_ECR_BE_MAX                                        (0x00000001U)

#define CSL_UART_RSR_ECR_OE_MASK                                       (0x00000008U)
#define CSL_UART_RSR_ECR_OE_SHIFT                                      (0x00000003U)
#define CSL_UART_RSR_ECR_OE_RESETVAL                                   (0x00000000U)
#define CSL_UART_RSR_ECR_OE_MAX                                        (0x00000001U)

#define CSL_UART_RSR_ECR_NU1_MASK                                      (0xFFFFFFF0U)
#define CSL_UART_RSR_ECR_NU1_SHIFT                                     (0x00000004U)
#define CSL_UART_RSR_ECR_NU1_RESETVAL                                  (0x00000000U)
#define CSL_UART_RSR_ECR_NU1_MAX                                       (0x0FFFFFFFU)

#define CSL_UART_RSR_ECR_RESETVAL                                      (0x00000000U)

/* FR */

#define CSL_UART_FR_CTS_MASK                                           (0x00000001U)
#define CSL_UART_FR_CTS_SHIFT                                          (0x00000000U)
#define CSL_UART_FR_CTS_RESETVAL                                       (0x00000000U)
#define CSL_UART_FR_CTS_MAX                                            (0x00000001U)

#define CSL_UART_FR_DSR_MASK                                           (0x00000002U)
#define CSL_UART_FR_DSR_SHIFT                                          (0x00000001U)
#define CSL_UART_FR_DSR_RESETVAL                                       (0x00000000U)
#define CSL_UART_FR_DSR_MAX                                            (0x00000001U)

#define CSL_UART_FR_DCD_MASK                                           (0x00000004U)
#define CSL_UART_FR_DCD_SHIFT                                          (0x00000002U)
#define CSL_UART_FR_DCD_RESETVAL                                       (0x00000000U)
#define CSL_UART_FR_DCD_MAX                                            (0x00000001U)

#define CSL_UART_FR_BUSY_MASK                                          (0x00000008U)
#define CSL_UART_FR_BUSY_SHIFT                                         (0x00000003U)
#define CSL_UART_FR_BUSY_RESETVAL                                      (0x00000000U)
#define CSL_UART_FR_BUSY_MAX                                           (0x00000001U)

#define CSL_UART_FR_RXFE_MASK                                          (0x00000010U)
#define CSL_UART_FR_RXFE_SHIFT                                         (0x00000004U)
#define CSL_UART_FR_RXFE_RESETVAL                                      (0x00000000U)
#define CSL_UART_FR_RXFE_MAX                                           (0x00000001U)

#define CSL_UART_FR_TXFF_MASK                                          (0x00000020U)
#define CSL_UART_FR_TXFF_SHIFT                                         (0x00000005U)
#define CSL_UART_FR_TXFF_RESETVAL                                      (0x00000000U)
#define CSL_UART_FR_TXFF_MAX                                           (0x00000001U)

#define CSL_UART_FR_RXFF_MASK                                          (0x00000040U)
#define CSL_UART_FR_RXFF_SHIFT                                         (0x00000006U)
#define CSL_UART_FR_RXFF_RESETVAL                                      (0x00000000U)
#define CSL_UART_FR_RXFF_MAX                                           (0x00000001U)

#define CSL_UART_FR_TXFE_MASK                                          (0x00000080U)
#define CSL_UART_FR_TXFE_SHIFT                                         (0x00000007U)
#define CSL_UART_FR_TXFE_RESETVAL                                      (0x00000000U)
#define CSL_UART_FR_TXFE_MAX                                           (0x00000001U)

#define CSL_UART_FR_RI_MASK                                            (0x00000100U)
#define CSL_UART_FR_RI_SHIFT                                           (0x00000008U)
#define CSL_UART_FR_RI_RESETVAL                                        (0x00000000U)
#define CSL_UART_FR_RI_MAX                                             (0x00000001U)

#define CSL_UART_FR_NU2_MASK                                           (0xFFFFFE00U)
#define CSL_UART_FR_NU2_SHIFT                                          (0x00000009U)
#define CSL_UART_FR_NU2_RESETVAL                                       (0x00000000U)
#define CSL_UART_FR_NU2_MAX                                            (0x007FFFFFU)

#define CSL_UART_FR_RESETVAL                                           (0x00000000U)

/* ILPR */

#define CSL_UART_ILPR_ILPDVSR_MASK                                     (0x000000FFU)
#define CSL_UART_ILPR_ILPDVSR_SHIFT                                    (0x00000000U)
#define CSL_UART_ILPR_ILPDVSR_RESETVAL                                 (0x00000000U)
#define CSL_UART_ILPR_ILPDVSR_MAX                                      (0x000000FFU)

#define CSL_UART_ILPR_NU3_MASK                                         (0xFFFFFF00U)
#define CSL_UART_ILPR_NU3_SHIFT                                        (0x00000008U)
#define CSL_UART_ILPR_NU3_RESETVAL                                     (0x00000000U)
#define CSL_UART_ILPR_NU3_MAX                                          (0x00FFFFFFU)

#define CSL_UART_ILPR_RESETVAL                                         (0x00000000U)

/* IBRD */

#define CSL_UART_IBRD_BAUD_DIVINT_MASK                                 (0x000000FFU)
#define CSL_UART_IBRD_BAUD_DIVINT_SHIFT                                (0x00000000U)
#define CSL_UART_IBRD_BAUD_DIVINT_RESETVAL                             (0x00000000U)
#define CSL_UART_IBRD_BAUD_DIVINT_MAX                                  (0x000000FFU)

#define CSL_UART_IBRD_NU4_MASK                                         (0xFFFFFF00U)
#define CSL_UART_IBRD_NU4_SHIFT                                        (0x00000008U)
#define CSL_UART_IBRD_NU4_RESETVAL                                     (0x00000000U)
#define CSL_UART_IBRD_NU4_MAX                                          (0x00FFFFFFU)

#define CSL_UART_IBRD_RESETVAL                                         (0x00000000U)

/* FBRD */

#define CSL_UART_FBRD_BAUD_DIVFRAC_MASK                                (0x0000003FU)
#define CSL_UART_FBRD_BAUD_DIVFRAC_SHIFT                               (0x00000000U)
#define CSL_UART_FBRD_BAUD_DIVFRAC_RESETVAL                            (0x00000000U)
#define CSL_UART_FBRD_BAUD_DIVFRAC_MAX                                 (0x0000003FU)

#define CSL_UART_FBRD_NU5_MASK                                         (0xFFFFFFC0U)
#define CSL_UART_FBRD_NU5_SHIFT                                        (0x00000006U)
#define CSL_UART_FBRD_NU5_RESETVAL                                     (0x00000000U)
#define CSL_UART_FBRD_NU5_MAX                                          (0x03FFFFFFU)

#define CSL_UART_FBRD_RESETVAL                                         (0x00000000U)

/* LCR_H */

#define CSL_UART_LCR_H_BRK_MASK                                        (0x00000001U)
#define CSL_UART_LCR_H_BRK_SHIFT                                       (0x00000000U)
#define CSL_UART_LCR_H_BRK_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_BRK_MAX                                         (0x00000001U)

#define CSL_UART_LCR_H_PEN_MASK                                        (0x00000002U)
#define CSL_UART_LCR_H_PEN_SHIFT                                       (0x00000001U)
#define CSL_UART_LCR_H_PEN_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_PEN_MAX                                         (0x00000001U)

#define CSL_UART_LCR_H_EPS_MASK                                        (0x00000004U)
#define CSL_UART_LCR_H_EPS_SHIFT                                       (0x00000002U)
#define CSL_UART_LCR_H_EPS_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_EPS_MAX                                         (0x00000001U)

#define CSL_UART_LCR_H_STP2_MASK                                       (0x00000008U)
#define CSL_UART_LCR_H_STP2_SHIFT                                      (0x00000003U)
#define CSL_UART_LCR_H_STP2_RESETVAL                                   (0x00000000U)
#define CSL_UART_LCR_H_STP2_MAX                                        (0x00000001U)

#define CSL_UART_LCR_H_FEN_MASK                                        (0x00000010U)
#define CSL_UART_LCR_H_FEN_SHIFT                                       (0x00000004U)
#define CSL_UART_LCR_H_FEN_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_FEN_MAX                                         (0x00000001U)

#define CSL_UART_LCR_H_WLEN_MASK                                       (0x00000060U)
#define CSL_UART_LCR_H_WLEN_SHIFT                                      (0x00000005U)
#define CSL_UART_LCR_H_WLEN_RESETVAL                                   (0x00000000U)
#define CSL_UART_LCR_H_WLEN_MAX                                        (0x00000003U)

#define CSL_UART_LCR_H_SPS_MASK                                        (0x00000080U)
#define CSL_UART_LCR_H_SPS_SHIFT                                       (0x00000007U)
#define CSL_UART_LCR_H_SPS_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_SPS_MAX                                         (0x00000001U)

#define CSL_UART_LCR_H_NU6_MASK                                        (0xFFFFFF00U)
#define CSL_UART_LCR_H_NU6_SHIFT                                       (0x00000008U)
#define CSL_UART_LCR_H_NU6_RESETVAL                                    (0x00000000U)
#define CSL_UART_LCR_H_NU6_MAX                                         (0x00FFFFFFU)

#define CSL_UART_LCR_H_RESETVAL                                        (0x00000000U)

/* CR */

#define CSL_UART_CR_UARTEN_MASK                                        (0x00000001U)
#define CSL_UART_CR_UARTEN_SHIFT                                       (0x00000000U)
#define CSL_UART_CR_UARTEN_RESETVAL                                    (0x00000000U)
#define CSL_UART_CR_UARTEN_MAX                                         (0x00000001U)

#define CSL_UART_CR_SIREN_MASK                                         (0x00000002U)
#define CSL_UART_CR_SIREN_SHIFT                                        (0x00000001U)
#define CSL_UART_CR_SIREN_RESETVAL                                     (0x00000000U)
#define CSL_UART_CR_SIREN_MAX                                          (0x00000001U)

#define CSL_UART_CR_SIRLP_MASK                                         (0x00000004U)
#define CSL_UART_CR_SIRLP_SHIFT                                        (0x00000002U)
#define CSL_UART_CR_SIRLP_RESETVAL                                     (0x00000000U)
#define CSL_UART_CR_SIRLP_MAX                                          (0x00000001U)

#define CSL_UART_CR_NU6_MASK                                           (0x00000078U)
#define CSL_UART_CR_NU6_SHIFT                                          (0x00000003U)
#define CSL_UART_CR_NU6_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_NU6_MAX                                            (0x0000000FU)

#define CSL_UART_CR_LBE_MASK                                           (0x00000080U)
#define CSL_UART_CR_LBE_SHIFT                                          (0x00000007U)
#define CSL_UART_CR_LBE_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_LBE_MAX                                            (0x00000001U)

#define CSL_UART_CR_TXE_MASK                                           (0x00000100U)
#define CSL_UART_CR_TXE_SHIFT                                          (0x00000008U)
#define CSL_UART_CR_TXE_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_TXE_MAX                                            (0x00000001U)

#define CSL_UART_CR_RXE_MASK                                           (0x00000200U)
#define CSL_UART_CR_RXE_SHIFT                                          (0x00000009U)
#define CSL_UART_CR_RXE_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_RXE_MAX                                            (0x00000001U)

#define CSL_UART_CR_DTR_MASK                                           (0x00000400U)
#define CSL_UART_CR_DTR_SHIFT                                          (0x0000000AU)
#define CSL_UART_CR_DTR_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_DTR_MAX                                            (0x00000001U)

#define CSL_UART_CR_RTS_MASK                                           (0x00000800U)
#define CSL_UART_CR_RTS_SHIFT                                          (0x0000000BU)
#define CSL_UART_CR_RTS_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_RTS_MAX                                            (0x00000001U)

#define CSL_UART_CR_OUT1_MASK                                          (0x00001000U)
#define CSL_UART_CR_OUT1_SHIFT                                         (0x0000000CU)
#define CSL_UART_CR_OUT1_RESETVAL                                      (0x00000000U)
#define CSL_UART_CR_OUT1_MAX                                           (0x00000001U)

#define CSL_UART_CR_OUT2_MASK                                          (0x00002000U)
#define CSL_UART_CR_OUT2_SHIFT                                         (0x0000000DU)
#define CSL_UART_CR_OUT2_RESETVAL                                      (0x00000000U)
#define CSL_UART_CR_OUT2_MAX                                           (0x00000001U)

#define CSL_UART_CR_RTSEN_MASK                                         (0x00004000U)
#define CSL_UART_CR_RTSEN_SHIFT                                        (0x0000000EU)
#define CSL_UART_CR_RTSEN_RESETVAL                                     (0x00000000U)
#define CSL_UART_CR_RTSEN_MAX                                          (0x00000001U)

#define CSL_UART_CR_CTSEN_MASK                                         (0x00008000U)
#define CSL_UART_CR_CTSEN_SHIFT                                        (0x0000000FU)
#define CSL_UART_CR_CTSEN_RESETVAL                                     (0x00000000U)
#define CSL_UART_CR_CTSEN_MAX                                          (0x00000001U)

#define CSL_UART_CR_NU7_MASK                                           (0xFFFF0000U)
#define CSL_UART_CR_NU7_SHIFT                                          (0x00000010U)
#define CSL_UART_CR_NU7_RESETVAL                                       (0x00000000U)
#define CSL_UART_CR_NU7_MAX                                            (0x0000FFFFU)

#define CSL_UART_CR_RESETVAL                                           (0x00000000U)

/* IFLS */

#define CSL_UART_IFLS_TXIFLSEL_MASK                                    (0x00000007U)
#define CSL_UART_IFLS_TXIFLSEL_SHIFT                                   (0x00000000U)
#define CSL_UART_IFLS_TXIFLSEL_RESETVAL                                (0x00000000U)
#define CSL_UART_IFLS_TXIFLSEL_MAX                                     (0x00000007U)

#define CSL_UART_IFLS_RXIFLSEL_MASK                                    (0x00000038U)
#define CSL_UART_IFLS_RXIFLSEL_SHIFT                                   (0x00000003U)
#define CSL_UART_IFLS_RXIFLSEL_RESETVAL                                (0x00000000U)
#define CSL_UART_IFLS_RXIFLSEL_MAX                                     (0x00000007U)

#define CSL_UART_IFLS_NU8_MASK                                         (0xFFFFFFC0U)
#define CSL_UART_IFLS_NU8_SHIFT                                        (0x00000006U)
#define CSL_UART_IFLS_NU8_RESETVAL                                     (0x00000000U)
#define CSL_UART_IFLS_NU8_MAX                                          (0x03FFFFFFU)

#define CSL_UART_IFLS_RESETVAL                                         (0x00000000U)

/* IMSC */

#define CSL_UART_IMSC_RIMIM_MASK                                       (0x00000001U)
#define CSL_UART_IMSC_RIMIM_SHIFT                                      (0x00000000U)
#define CSL_UART_IMSC_RIMIM_RESETVAL                                   (0x00000000U)
#define CSL_UART_IMSC_RIMIM_MAX                                        (0x00000001U)

#define CSL_UART_IMSC_CTSMIM_MASK                                      (0x00000002U)
#define CSL_UART_IMSC_CTSMIM_SHIFT                                     (0x00000001U)
#define CSL_UART_IMSC_CTSMIM_RESETVAL                                  (0x00000000U)
#define CSL_UART_IMSC_CTSMIM_MAX                                       (0x00000001U)

#define CSL_UART_IMSC_DCDMIM_MASK                                      (0x00000004U)
#define CSL_UART_IMSC_DCDMIM_SHIFT                                     (0x00000002U)
#define CSL_UART_IMSC_DCDMIM_RESETVAL                                  (0x00000000U)
#define CSL_UART_IMSC_DCDMIM_MAX                                       (0x00000001U)

#define CSL_UART_IMSC_DSRMIM_MASK                                      (0x00000008U)
#define CSL_UART_IMSC_DSRMIM_SHIFT                                     (0x00000003U)
#define CSL_UART_IMSC_DSRMIM_RESETVAL                                  (0x00000000U)
#define CSL_UART_IMSC_DSRMIM_MAX                                       (0x00000001U)

#define CSL_UART_IMSC_RXIM_MASK                                        (0x00000010U)
#define CSL_UART_IMSC_RXIM_SHIFT                                       (0x00000004U)
#define CSL_UART_IMSC_RXIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_RXIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_TXIM_MASK                                        (0x00000020U)
#define CSL_UART_IMSC_TXIM_SHIFT                                       (0x00000005U)
#define CSL_UART_IMSC_TXIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_TXIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_RTIM_MASK                                        (0x00000040U)
#define CSL_UART_IMSC_RTIM_SHIFT                                       (0x00000006U)
#define CSL_UART_IMSC_RTIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_RTIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_FEIM_MASK                                        (0x00000080U)
#define CSL_UART_IMSC_FEIM_SHIFT                                       (0x00000007U)
#define CSL_UART_IMSC_FEIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_FEIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_PEIM_MASK                                        (0x00000100U)
#define CSL_UART_IMSC_PEIM_SHIFT                                       (0x00000008U)
#define CSL_UART_IMSC_PEIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_PEIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_BEIM_MASK                                        (0x00000200U)
#define CSL_UART_IMSC_BEIM_SHIFT                                       (0x00000009U)
#define CSL_UART_IMSC_BEIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_BEIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_OEIM_MASK                                        (0x00000400U)
#define CSL_UART_IMSC_OEIM_SHIFT                                       (0x0000000AU)
#define CSL_UART_IMSC_OEIM_RESETVAL                                    (0x00000000U)
#define CSL_UART_IMSC_OEIM_MAX                                         (0x00000001U)

#define CSL_UART_IMSC_NU9_MASK                                         (0xFFFFF800U)
#define CSL_UART_IMSC_NU9_SHIFT                                        (0x0000000BU)
#define CSL_UART_IMSC_NU9_RESETVAL                                     (0x00000000U)
#define CSL_UART_IMSC_NU9_MAX                                          (0x001FFFFFU)

#define CSL_UART_IMSC_RESETVAL                                         (0x00000000U)

/* RIS */

#define CSL_UART_RIS_RIRMIS_MASK                                       (0x00000001U)
#define CSL_UART_RIS_RIRMIS_SHIFT                                      (0x00000000U)
#define CSL_UART_RIS_RIRMIS_RESETVAL                                   (0x00000000U)
#define CSL_UART_RIS_RIRMIS_MAX                                        (0x00000001U)

#define CSL_UART_RIS_CTSRMIS_MASK                                      (0x00000002U)
#define CSL_UART_RIS_CTSRMIS_SHIFT                                     (0x00000001U)
#define CSL_UART_RIS_CTSRMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_RIS_CTSRMIS_MAX                                       (0x00000001U)

#define CSL_UART_RIS_DCDRMIS_MASK                                      (0x00000004U)
#define CSL_UART_RIS_DCDRMIS_SHIFT                                     (0x00000002U)
#define CSL_UART_RIS_DCDRMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_RIS_DCDRMIS_MAX                                       (0x00000001U)

#define CSL_UART_RIS_DSRRMIS_MASK                                      (0x00000008U)
#define CSL_UART_RIS_DSRRMIS_SHIFT                                     (0x00000003U)
#define CSL_UART_RIS_DSRRMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_RIS_DSRRMIS_MAX                                       (0x00000001U)

#define CSL_UART_RIS_RXRIS_MASK                                        (0x00000010U)
#define CSL_UART_RIS_RXRIS_SHIFT                                       (0x00000004U)
#define CSL_UART_RIS_RXRIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_RXRIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_TXRIS_MASK                                        (0x00000020U)
#define CSL_UART_RIS_TXRIS_SHIFT                                       (0x00000005U)
#define CSL_UART_RIS_TXRIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_TXRIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_RTRIS_MASK                                        (0x00000040U)
#define CSL_UART_RIS_RTRIS_SHIFT                                       (0x00000006U)
#define CSL_UART_RIS_RTRIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_RTRIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_FERIS_MASK                                        (0x00000080U)
#define CSL_UART_RIS_FERIS_SHIFT                                       (0x00000007U)
#define CSL_UART_RIS_FERIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_FERIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_PERIS_MASK                                        (0x00000100U)
#define CSL_UART_RIS_PERIS_SHIFT                                       (0x00000008U)
#define CSL_UART_RIS_PERIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_PERIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_OERIS_MASK                                        (0x00000200U)
#define CSL_UART_RIS_OERIS_SHIFT                                       (0x00000009U)
#define CSL_UART_RIS_OERIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_RIS_OERIS_MAX                                         (0x00000001U)

#define CSL_UART_RIS_NU10_MASK                                         (0xFFFFFC00U)
#define CSL_UART_RIS_NU10_SHIFT                                        (0x0000000AU)
#define CSL_UART_RIS_NU10_RESETVAL                                     (0x00000000U)
#define CSL_UART_RIS_NU10_MAX                                          (0x003FFFFFU)

#define CSL_UART_RIS_RESETVAL                                          (0x00000000U)

/* MIS */

#define CSL_UART_MIS_RIMMIS_MASK                                       (0x00000001U)
#define CSL_UART_MIS_RIMMIS_SHIFT                                      (0x00000000U)
#define CSL_UART_MIS_RIMMIS_RESETVAL                                   (0x00000000U)
#define CSL_UART_MIS_RIMMIS_MAX                                        (0x00000001U)

#define CSL_UART_MIS_CTSMMIS_MASK                                      (0x00000002U)
#define CSL_UART_MIS_CTSMMIS_SHIFT                                     (0x00000001U)
#define CSL_UART_MIS_CTSMMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_MIS_CTSMMIS_MAX                                       (0x00000001U)

#define CSL_UART_MIS_DCDMMIS_MASK                                      (0x00000004U)
#define CSL_UART_MIS_DCDMMIS_SHIFT                                     (0x00000002U)
#define CSL_UART_MIS_DCDMMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_MIS_DCDMMIS_MAX                                       (0x00000001U)

#define CSL_UART_MIS_DSRMMIS_MASK                                      (0x00000008U)
#define CSL_UART_MIS_DSRMMIS_SHIFT                                     (0x00000003U)
#define CSL_UART_MIS_DSRMMIS_RESETVAL                                  (0x00000000U)
#define CSL_UART_MIS_DSRMMIS_MAX                                       (0x00000001U)

#define CSL_UART_MIS_RXMIS_MASK                                        (0x00000010U)
#define CSL_UART_MIS_RXMIS_SHIFT                                       (0x00000004U)
#define CSL_UART_MIS_RXMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_RXMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_TXMIS_MASK                                        (0x00000020U)
#define CSL_UART_MIS_TXMIS_SHIFT                                       (0x00000005U)
#define CSL_UART_MIS_TXMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_TXMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_RTMIS_MASK                                        (0x00000040U)
#define CSL_UART_MIS_RTMIS_SHIFT                                       (0x00000006U)
#define CSL_UART_MIS_RTMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_RTMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_FEMIS_MASK                                        (0x00000080U)
#define CSL_UART_MIS_FEMIS_SHIFT                                       (0x00000007U)
#define CSL_UART_MIS_FEMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_FEMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_PEMIS_MASK                                        (0x00000100U)
#define CSL_UART_MIS_PEMIS_SHIFT                                       (0x00000008U)
#define CSL_UART_MIS_PEMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_PEMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_BEMIS_MASK                                        (0x00000200U)
#define CSL_UART_MIS_BEMIS_SHIFT                                       (0x00000009U)
#define CSL_UART_MIS_BEMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_BEMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_OEMIS_MASK                                        (0x00000400U)
#define CSL_UART_MIS_OEMIS_SHIFT                                       (0x0000000AU)
#define CSL_UART_MIS_OEMIS_RESETVAL                                    (0x00000000U)
#define CSL_UART_MIS_OEMIS_MAX                                         (0x00000001U)

#define CSL_UART_MIS_NU11_MASK                                         (0xFFFFF800U)
#define CSL_UART_MIS_NU11_SHIFT                                        (0x0000000BU)
#define CSL_UART_MIS_NU11_RESETVAL                                     (0x00000000U)
#define CSL_UART_MIS_NU11_MAX                                          (0x001FFFFFU)

#define CSL_UART_MIS_RESETVAL                                          (0x00000000U)

/* ICR */

#define CSL_UART_ICR_RIMIC_MASK                                        (0x00000001U)
#define CSL_UART_ICR_RIMIC_SHIFT                                       (0x00000000U)
#define CSL_UART_ICR_RIMIC_RESETVAL                                    (0x00000000U)
#define CSL_UART_ICR_RIMIC_MAX                                         (0x00000001U)

#define CSL_UART_ICR_CTSMIC_MASK                                       (0x00000002U)
#define CSL_UART_ICR_CTSMIC_SHIFT                                      (0x00000001U)
#define CSL_UART_ICR_CTSMIC_RESETVAL                                   (0x00000000U)
#define CSL_UART_ICR_CTSMIC_MAX                                        (0x00000001U)

#define CSL_UART_ICR_DCDMIC_MASK                                       (0x00000004U)
#define CSL_UART_ICR_DCDMIC_SHIFT                                      (0x00000002U)
#define CSL_UART_ICR_DCDMIC_RESETVAL                                   (0x00000000U)
#define CSL_UART_ICR_DCDMIC_MAX                                        (0x00000001U)

#define CSL_UART_ICR_DSRMIC_MASK                                       (0x00000008U)
#define CSL_UART_ICR_DSRMIC_SHIFT                                      (0x00000003U)
#define CSL_UART_ICR_DSRMIC_RESETVAL                                   (0x00000000U)
#define CSL_UART_ICR_DSRMIC_MAX                                        (0x00000001U)

#define CSL_UART_ICR_RXIC_MASK                                         (0x00000010U)
#define CSL_UART_ICR_RXIC_SHIFT                                        (0x00000004U)
#define CSL_UART_ICR_RXIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_RXIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_TXIC_MASK                                         (0x00000020U)
#define CSL_UART_ICR_TXIC_SHIFT                                        (0x00000005U)
#define CSL_UART_ICR_TXIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_TXIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_RTIC_MASK                                         (0x00000040U)
#define CSL_UART_ICR_RTIC_SHIFT                                        (0x00000006U)
#define CSL_UART_ICR_RTIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_RTIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_FEIC_MASK                                         (0x00000080U)
#define CSL_UART_ICR_FEIC_SHIFT                                        (0x00000007U)
#define CSL_UART_ICR_FEIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_FEIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_PEIC_MASK                                         (0x00000100U)
#define CSL_UART_ICR_PEIC_SHIFT                                        (0x00000008U)
#define CSL_UART_ICR_PEIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_PEIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_BEIC_MASK                                         (0x00000200U)
#define CSL_UART_ICR_BEIC_SHIFT                                        (0x00000009U)
#define CSL_UART_ICR_BEIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_BEIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_OEIC_MASK                                         (0x00000400U)
#define CSL_UART_ICR_OEIC_SHIFT                                        (0x0000000AU)
#define CSL_UART_ICR_OEIC_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_OEIC_MAX                                          (0x00000001U)

#define CSL_UART_ICR_NU12_MASK                                         (0xFFFFF800U)
#define CSL_UART_ICR_NU12_SHIFT                                        (0x0000000BU)
#define CSL_UART_ICR_NU12_RESETVAL                                     (0x00000000U)
#define CSL_UART_ICR_NU12_MAX                                          (0x001FFFFFU)

#define CSL_UART_ICR_RESETVAL                                          (0x00000000U)

/* DMACR */

#define CSL_UART_DMACR_RXDMAE_MASK                                     (0x00000001U)
#define CSL_UART_DMACR_RXDMAE_SHIFT                                    (0x00000000U)
#define CSL_UART_DMACR_RXDMAE_RESETVAL                                 (0x00000000U)
#define CSL_UART_DMACR_RXDMAE_MAX                                      (0x00000001U)

#define CSL_UART_DMACR_TXDMAE_MASK                                     (0x00000002U)
#define CSL_UART_DMACR_TXDMAE_SHIFT                                    (0x00000001U)
#define CSL_UART_DMACR_TXDMAE_RESETVAL                                 (0x00000000U)
#define CSL_UART_DMACR_TXDMAE_MAX                                      (0x00000001U)

#define CSL_UART_DMACR_DMAONERR_MASK                                   (0x00000004U)
#define CSL_UART_DMACR_DMAONERR_SHIFT                                  (0x00000002U)
#define CSL_UART_DMACR_DMAONERR_RESETVAL                               (0x00000000U)
#define CSL_UART_DMACR_DMAONERR_MAX                                    (0x00000001U)

#define CSL_UART_DMACR_NU13_MASK                                       (0xFFFFFFF8U)
#define CSL_UART_DMACR_NU13_SHIFT                                      (0x00000003U)
#define CSL_UART_DMACR_NU13_RESETVAL                                   (0x00000000U)
#define CSL_UART_DMACR_NU13_MAX                                        (0x1FFFFFFFU)

#define CSL_UART_DMACR_RESETVAL                                        (0x00000000U)

/* PERIPHID0 */

#define CSL_UART_PERIPHID0_UARTPERIPHID0_MASK                          (0xFFFFFFFFU)
#define CSL_UART_PERIPHID0_UARTPERIPHID0_SHIFT                         (0x00000000U)
#define CSL_UART_PERIPHID0_UARTPERIPHID0_RESETVAL                      (0x00000000U)
#define CSL_UART_PERIPHID0_UARTPERIPHID0_MAX                           (0xFFFFFFFFU)

#define CSL_UART_PERIPHID0_RESETVAL                                    (0x00000000U)

/* PERIPHID1 */

#define CSL_UART_PERIPHID1_UARTPERIPHID1_MASK                          (0xFFFFFFFFU)
#define CSL_UART_PERIPHID1_UARTPERIPHID1_SHIFT                         (0x00000000U)
#define CSL_UART_PERIPHID1_UARTPERIPHID1_RESETVAL                      (0x00000000U)
#define CSL_UART_PERIPHID1_UARTPERIPHID1_MAX                           (0xFFFFFFFFU)

#define CSL_UART_PERIPHID1_RESETVAL                                    (0x00000000U)

/* PERIPHID2 */

#define CSL_UART_PERIPHID2_UARTPERIPHID2_MASK                          (0xFFFFFFFFU)
#define CSL_UART_PERIPHID2_UARTPERIPHID2_SHIFT                         (0x00000000U)
#define CSL_UART_PERIPHID2_UARTPERIPHID2_RESETVAL                      (0x00000000U)
#define CSL_UART_PERIPHID2_UARTPERIPHID2_MAX                           (0xFFFFFFFFU)

#define CSL_UART_PERIPHID2_RESETVAL                                    (0x00000000U)

/* PERIPHID3 */

#define CSL_UART_PERIPHID3_UARTPERIPHID3_MASK                          (0xFFFFFFFFU)
#define CSL_UART_PERIPHID3_UARTPERIPHID3_SHIFT                         (0x00000000U)
#define CSL_UART_PERIPHID3_UARTPERIPHID3_RESETVAL                      (0x00000000U)
#define CSL_UART_PERIPHID3_UARTPERIPHID3_MAX                           (0xFFFFFFFFU)

#define CSL_UART_PERIPHID3_RESETVAL                                    (0x00000000U)

/* PCELLID0 */

#define CSL_UART_PCELLID0_UARTPCELLID0_MASK                            (0xFFFFFFFFU)
#define CSL_UART_PCELLID0_UARTPCELLID0_SHIFT                           (0x00000000U)
#define CSL_UART_PCELLID0_UARTPCELLID0_RESETVAL                        (0x00000000U)
#define CSL_UART_PCELLID0_UARTPCELLID0_MAX                             (0xFFFFFFFFU)

#define CSL_UART_PCELLID0_RESETVAL                                     (0x00000000U)

/* PCELLID1 */

#define CSL_UART_PCELLID1_UARTPCELLID1_MASK                            (0xFFFFFFFFU)
#define CSL_UART_PCELLID1_UARTPCELLID1_SHIFT                           (0x00000000U)
#define CSL_UART_PCELLID1_UARTPCELLID1_RESETVAL                        (0x00000000U)
#define CSL_UART_PCELLID1_UARTPCELLID1_MAX                             (0xFFFFFFFFU)

#define CSL_UART_PCELLID1_RESETVAL                                     (0x00000000U)

/* PCELLID2 */

#define CSL_UART_PCELLID2_UARTPCELLID2_MASK                            (0xFFFFFFFFU)
#define CSL_UART_PCELLID2_UARTPCELLID2_SHIFT                           (0x00000000U)
#define CSL_UART_PCELLID2_UARTPCELLID2_RESETVAL                        (0x00000000U)
#define CSL_UART_PCELLID2_UARTPCELLID2_MAX                             (0xFFFFFFFFU)

#define CSL_UART_PCELLID2_RESETVAL                                     (0x00000000U)

/* PCELLID3 */

#define CSL_UART_PCELLID3_UARTPCELLID3_MASK                            (0xFFFFFFFFU)
#define CSL_UART_PCELLID3_UARTPCELLID3_SHIFT                           (0x00000000U)
#define CSL_UART_PCELLID3_UARTPCELLID3_RESETVAL                        (0x00000000U)
#define CSL_UART_PCELLID3_UARTPCELLID3_MAX                             (0xFFFFFFFFU)

#define CSL_UART_PCELLID3_RESETVAL                                     (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
