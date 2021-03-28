/*
* hw_uart.h
*
* Register-level header file for UART
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

#ifndef HW_UART_H_
#define HW_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define UART_THR                                                    (0x0U)
#define UART_IER_IRDA                                               (0x4U)
#define UART_EFR                                                    (0x8U)
#define UART_LCR                                                    (0xcU)
#define UART_MCR                                                    (0x10U)
#define UART_XON2_ADDR2                                             (0x14U)
#define UART_TCR                                                    (0x18U)
#define UART_SPR                                                    (0x1cU)
#define UART_MDR1                                                   (0x20U)
#define UART_MDR2                                                   (0x24U)
#define UART_TXFLL                                                  (0x28U)
#define UART_RESUME                                                 (0x2cU)
#define UART_RXFLL                                                  (0x30U)
#define UART_SFREGH                                                 (0x34U)
#define UART_BLR                                                    (0x38U)
#define UART_ACREG                                                  (0x3cU)
#define UART_SCR                                                    (0x40U)
#define UART_SSR                                                    (0x44U)
#define UART_EBLR                                                   (0x48U)
#define UART_MVR                                                    (0x50U)
#define UART_SYSC                                                   (0x54U)
#define UART_SYSS                                                   (0x58U)
#define UART_WER                                                    (0x5cU)
#define UART_CFPS                                                   (0x60U)
#define UART_RXFIFO_LVL                                             (0x64U)
#define UART_TXFIFO_LVL                                             (0x68U)
#define UART_IER2                                                   (0x6cU)
#define UART_ISR2                                                   (0x70U)
#define UART_FREQ_SEL                                               (0x74U)
#define UART_MDR3                                                   (0x80U)
#define UART_TX_DMA_THR                                             (0x84U)
#define UART_RHR                                                    (0x0U)
#define UART_IER_CIR                                                (0x4U)
#define UART_IIR                                                    (0x8U)
#define UART_XON1_ADDR1                                             (0x10U)
#define UART_LSR_CIR                                                (0x14U)
#define UART_MSR                                                    (0x18U)
#define UART_TLR                                                    (0x1cU)
#define UART_SFLSR                                                  (0x28U)
#define UART_TXFLH                                                  (0x2cU)
#define UART_SFREGL                                                 (0x30U)
#define UART_RXFLH                                                  (0x34U)
#define UART_UASR                                                   (0x38U)
#define UART_DLL                                                    (0x0U)
#define UART_IER                                                    (0x4U)
#define UART_IIR_CIR                                                (0x8U)
#define UART_LSR_IRDA                                               (0x14U)
#define UART_XOFF1                                                  (0x18U)
#define UART_XOFF2                                                  (0x1cU)
#define UART_DLH                                                    (0x4U)
#define UART_FCR                                                    (0x8U)
#define UART_LSR                                                    (0x14U)
#define UART_IIR_IRDA                                               (0x8U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define UART_THR_SHIFT                                                                  (0U)
#define UART_THR_MASK                                                                   (0x000000ffU)

#define UART_IER_IRDA_RHRIT_SHIFT                                                       (0U)
#define UART_IER_IRDA_RHRIT_MASK                                                        (0x00000001U)
#define UART_IER_IRDA_RHRIT_DISABLE                                                      (0U)
#define UART_IER_IRDA_RHRIT_ENABLE                                                       (1U)

#define UART_IER_IRDA_THRIT_SHIFT                                                       (1U)
#define UART_IER_IRDA_THRIT_MASK                                                        (0x00000002U)
#define UART_IER_IRDA_THRIT_DISABLE                                                      (0U)
#define UART_IER_IRDA_THRIT_ENABLE                                                       (1U)

#define UART_IER_IRDA_LASTRXBYTEIT_SHIFT                                                (2U)
#define UART_IER_IRDA_LASTRXBYTEIT_MASK                                                 (0x00000004U)
#define UART_IER_IRDA_LASTRXBYTEIT_DISABLE                                               (0U)
#define UART_IER_IRDA_LASTRXBYTEIT_ENABLE                                                (1U)

#define UART_IER_IRDA_RXOVERRUNIT_SHIFT                                                 (3U)
#define UART_IER_IRDA_RXOVERRUNIT_MASK                                                  (0x00000008U)
#define UART_IER_IRDA_RXOVERRUNIT_DISABLE                                                (0U)
#define UART_IER_IRDA_RXOVERRUNIT_ENABLE                                                 (1U)

#define UART_IER_IRDA_STSFIFOTRIGIT_SHIFT                                               (4U)
#define UART_IER_IRDA_STSFIFOTRIGIT_MASK                                                (0x00000010U)
#define UART_IER_IRDA_STSFIFOTRIGIT_DISABLE                                              (0U)
#define UART_IER_IRDA_STSFIFOTRIGIT_ENABLE                                               (1U)

#define UART_IER_IRDA_TXSTSIT_SHIFT                                                     (5U)
#define UART_IER_IRDA_TXSTSIT_MASK                                                      (0x00000020U)
#define UART_IER_IRDA_TXSTSIT_DISABLE                                                    (0U)
#define UART_IER_IRDA_TXSTSIT_ENABLE                                                     (1U)

#define UART_IER_IRDA_LINESTSIT_SHIFT                                                   (6U)
#define UART_IER_IRDA_LINESTSIT_MASK                                                    (0x00000040U)
#define UART_IER_IRDA_LINESTSIT_DISABLE                                                  (0U)
#define UART_IER_IRDA_LINESTSIT_ENABLE                                                   (1U)

#define UART_IER_IRDA_EOFIT_SHIFT                                                       (7U)
#define UART_IER_IRDA_EOFIT_MASK                                                        (0x00000080U)
#define UART_IER_IRDA_EOFIT_DISABLE                                                      (0U)
#define UART_IER_IRDA_EOFIT_ENABLE                                                       (1U)

#define UART_EFR_SWFLOWCTRL_SHIFT                                                       (0U)
#define UART_EFR_SWFLOWCTRL_MASK                                                        (0x0000000fU)

#define UART_EFR_ENHANCEDEN_SHIFT                                                       (4U)
#define UART_EFR_ENHANCEDEN_MASK                                                        (0x00000010U)
#define UART_EFR_ENHANCEDEN_DISABLE                                                      (0U)
#define UART_EFR_ENHANCEDEN_ENABLE                                                       (1U)

#define UART_EFR_SPECIALCHARDETECT_SHIFT                                                (5U)
#define UART_EFR_SPECIALCHARDETECT_MASK                                                 (0x00000020U)
#define UART_EFR_SPECIALCHARDETECT_DISABLE                                               (0U)
#define UART_EFR_SPECIALCHARDETECT_ENABLE                                                (1U)

#define UART_EFR_AUTORTSEN_SHIFT                                                        (6U)
#define UART_EFR_AUTORTSEN_MASK                                                         (0x00000040U)
#define UART_EFR_AUTORTSEN_DISABLE                                                       (0U)
#define UART_EFR_AUTORTSEN_ENABLE                                                        (1U)

#define UART_EFR_AUTOCTSEN_SHIFT                                                        (7U)
#define UART_EFR_AUTOCTSEN_MASK                                                         (0x00000080U)
#define UART_EFR_AUTOCTSEN_DISABLE                                                       (0U)
#define UART_EFR_AUTOCTSEN_ENABLE                                                        (1U)

#define UART_LCR_CHAR_LENGTH_SHIFT                                                      (0U)
#define UART_LCR_CHAR_LENGTH_MASK                                                       (0x00000003U)
#define UART_LCR_CHAR_LENGTH_BITS_5                                                      (0U)
#define UART_LCR_CHAR_LENGTH_BITS_6                                                      (1U)
#define UART_LCR_CHAR_LENGTH_BITS_7                                                      (2U)
#define UART_LCR_CHAR_LENGTH_BITS_8                                                      (3U)

#define UART_LCR_NB_STOP_SHIFT                                                          (2U)
#define UART_LCR_NB_STOP_MASK                                                           (0x00000004U)
#define UART_LCR_NB_STOP_BITS_1                                                          (0U)
#define UART_LCR_NB_STOP_BITS_1_5                                                        (1U)

#define UART_LCR_PARITY_EN_SHIFT                                                        (3U)
#define UART_LCR_PARITY_EN_MASK                                                         (0x00000008U)
#define UART_LCR_PARITY_EN_NOT_GENERATED                                                 (0U)
#define UART_LCR_PARITY_EN_GENERATED                                                     (1U)

#define UART_LCR_PARITY_TYPE1_SHIFT                                                     (4U)
#define UART_LCR_PARITY_TYPE1_MASK                                                      (0x00000010U)
#define UART_LCR_PARITY_TYPE1_ODD                                                        (0U)
#define UART_LCR_PARITY_TYPE1_EVEN                                                       (1U)

#define UART_LCR_PARITY_TYPE2_SHIFT                                                     (5U)
#define UART_LCR_PARITY_TYPE2_MASK                                                      (0x00000020U)
#define UART_LCR_PARITY_TYPE2_LCR5_0                                                     (0U)
#define UART_LCR_PARITY_TYPE2_LCR5_1                                                     (1U)

#define UART_LCR_BREAK_EN_SHIFT                                                         (6U)
#define UART_LCR_BREAK_EN_MASK                                                          (0x00000040U)
#define UART_LCR_BREAK_EN_NORMAL                                                         (0U)
#define UART_LCR_BREAK_EN_FORCE_OUTPUT                                                   (1U)

#define UART_LCR_DIV_EN_SHIFT                                                           (7U)
#define UART_LCR_DIV_EN_MASK                                                            (0x00000080U)
#define UART_LCR_DIV_EN_NORMAL                                                           (0U)
#define UART_LCR_DIV_EN_ENABLE                                                           (1U)

#define UART_MCR_DTR_SHIFT                                                              (0U)
#define UART_MCR_DTR_MASK                                                               (0x00000001U)
#define UART_MCR_DTR_INACTIVE                                                            (0U)
#define UART_MCR_DTR_ACTIVE                                                              (1U)

#define UART_MCR_RTS_SHIFT                                                              (1U)
#define UART_MCR_RTS_MASK                                                               (0x00000002U)
#define UART_MCR_RTS_INACTIVE                                                            (0U)
#define UART_MCR_RTS_ACTIVE                                                              (1U)

#define UART_MCR_RISTSCH_SHIFT                                                          (2U)
#define UART_MCR_RISTSCH_MASK                                                           (0x00000004U)
#define UART_MCR_RISTSCH_INACTIVE                                                        (0U)
#define UART_MCR_RISTSCH_ACTIVE                                                          (1U)

#define UART_MCR_CDSTSCH_SHIFT                                                          (3U)
#define UART_MCR_CDSTSCH_MASK                                                           (0x00000008U)
#define UART_MCR_CDSTSCH_INPUT_HIGH                                                      (0U)
#define UART_MCR_CDSTSCH_INPUT_LOW                                                       (1U)

#define UART_MCR_LOOPBACKEN_SHIFT                                                       (4U)
#define UART_MCR_LOOPBACKEN_MASK                                                        (0x00000010U)
#define UART_MCR_LOOPBACKEN_NORMAL                                                       (0U)
#define UART_MCR_LOOPBACKEN_ENABLE                                                       (1U)

#define UART_MCR_XONEN_SHIFT                                                            (5U)
#define UART_MCR_XONEN_MASK                                                             (0x00000020U)
#define UART_MCR_XONEN_DISABLE                                                           (0U)
#define UART_MCR_XONEN_ENABLE                                                            (1U)

#define UART_MCR_TCRTLR_SHIFT                                                           (6U)
#define UART_MCR_TCRTLR_MASK                                                            (0x00000040U)
#define UART_MCR_TCRTLR_NO_ACTION                                                        (0U)
#define UART_MCR_TCRTLR_ENABLE                                                           (1U)

#define UART_XON2_ADDR2_XONWORD2_SHIFT                                                  (0U)
#define UART_XON2_ADDR2_XONWORD2_MASK                                                   (0x000000ffU)

#define UART_TCR_RXFIFOTRIGHALT_SHIFT                                                   (0U)
#define UART_TCR_RXFIFOTRIGHALT_MASK                                                    (0x0000000fU)

#define UART_TCR_RXFIFOTRIGSTART_SHIFT                                                  (4U)
#define UART_TCR_RXFIFOTRIGSTART_MASK                                                   (0x000000f0U)

#define UART_SPR_WORD_SHIFT                                                             (0U)
#define UART_SPR_WORD_MASK                                                              (0x000000ffU)

#define UART_MDR1_MODESELECT_SHIFT                                                      (0U)
#define UART_MDR1_MODESELECT_MASK                                                       (0x00000007U)
#define UART_MDR1_MODESELECT_MODE_16X                                                    (0U)
#define UART_MDR1_MODESELECT_MODE_SIR                                                    (1U)
#define UART_MDR1_MODESELECT_MODE_16X_AUTO_BAUD                                          (2U)
#define UART_MDR1_MODESELECT_MODE_13X                                                    (3U)
#define UART_MDR1_MODESELECT_MODE_MIR                                                    (4U)
#define UART_MDR1_MODESELECT_MODE_FIR                                                    (5U)
#define UART_MDR1_MODESELECT_MODE_CIR                                                    (6U)
#define UART_MDR1_MODESELECT_MODE_DISABLE                                                (7U)

#define UART_MDR1_IRSLEEP_SHIFT                                                         (3U)
#define UART_MDR1_IRSLEEP_MASK                                                          (0x00000008U)
#define UART_MDR1_IRSLEEP_DISABLE                                                        (0U)
#define UART_MDR1_IRSLEEP_ENABLE                                                         (1U)

#define UART_MDR1_SETTXIR_SHIFT                                                         (4U)
#define UART_MDR1_SETTXIR_MASK                                                          (0x00000010U)
#define UART_MDR1_SETTXIR_NO_ACTION                                                      (0U)
#define UART_MDR1_SETTXIR_FORCED_HIGH                                                    (1U)

#define UART_MDR1_SCT_SHIFT                                                             (5U)
#define UART_MDR1_SCT_MASK                                                              (0x00000020U)
#define UART_MDR1_SCT_START_WITH_THR_WRITE                                               (0U)
#define UART_MDR1_SCT_START_WITH_CTRL_OF_ACREG_2                                         (1U)

#define UART_MDR1_SIPMODE_SHIFT                                                         (6U)
#define UART_MDR1_SIPMODE_MASK                                                          (0x00000040U)
#define UART_MDR1_SIPMODE_MANUAL                                                         (0U)
#define UART_MDR1_SIPMODE_AUTOMATIC                                                      (1U)

#define UART_MDR1_FRMENDMODE_SHIFT                                                      (7U)
#define UART_MDR1_FRMENDMODE_MASK                                                       (0x00000080U)
#define UART_MDR1_FRMENDMODE_FRAME_LENGTH_METHOD                                         (0U)
#define UART_MDR1_FRMENDMODE_EOT_BIT_METHOD                                              (1U)

#define UART_MDR2_IRTXUNDERRUN_SHIFT                                                    (0U)
#define UART_MDR2_IRTXUNDERRUN_MASK                                                     (0x00000001U)
#define UART_MDR2_IRTXUNDERRUN_NO_ERROR                                                  (0U)
#define UART_MDR2_IRTXUNDERRUN_ERROR                                                     (1U)

#define UART_MDR2_STSFIFOTRIG_SHIFT                                                     (1U)
#define UART_MDR2_STSFIFOTRIG_MASK                                                      (0x00000006U)
#define UART_MDR2_STSFIFOTRIG_ENTRY_1                                                    (0U)
#define UART_MDR2_STSFIFOTRIG_ENTRY_4                                                    (1U)
#define UART_MDR2_STSFIFOTRIG_ENTRY_7                                                    (2U)
#define UART_MDR2_STSFIFOTRIG_ENTRY_8                                                    (3U)

#define UART_MDR2_UARTPULSE_SHIFT                                                       (3U)
#define UART_MDR2_UARTPULSE_MASK                                                        (0x00000008U)
#define UART_MDR2_UARTPULSE_NORMAL_MODE                                                  (0U)
#define UART_MDR2_UARTPULSE_PULSE_SHAPING_MODE                                           (1U)

#define UART_MDR2_CIRPULSEMODE_SHIFT                                                    (4U)
#define UART_MDR2_CIRPULSEMODE_MASK                                                     (0x00000030U)
#define UART_MDR2_CIRPULSEMODE_WIDTH_3                                                   (0U)
#define UART_MDR2_CIRPULSEMODE_WIDTH_4                                                   (1U)
#define UART_MDR2_CIRPULSEMODE_WIDTH_5                                                   (2U)
#define UART_MDR2_CIRPULSEMODE_WIDTH_6                                                   (3U)

#define UART_MDR2_IRRXINVERT_SHIFT                                                      (6U)
#define UART_MDR2_IRRXINVERT_MASK                                                       (0x00000040U)
#define UART_MDR2_IRRXINVERT_INVERSION                                                   (0U)
#define UART_MDR2_IRRXINVERT_NO_INVERSION                                                (1U)

#define UART_MDR2_SETTXIRALT_SHIFT                                                      (7U)
#define UART_MDR2_SETTXIRALT_MASK                                                       (0x00000080U)
#define UART_MDR2_SETTXIRALT_NORMAL                                                      (0U)
#define UART_MDR2_SETTXIRALT_ALTERNATE                                                   (1U)

#define UART_TXFLL_SHIFT                                                                (0U)
#define UART_TXFLL_MASK                                                                 (0x000000ffU)

#define UART_RESUME_SHIFT                                                               (0U)
#define UART_RESUME_MASK                                                                (0x000000ffU)

#define UART_RXFLL_SHIFT                                                                (0U)
#define UART_RXFLL_MASK                                                                 (0x000000ffU)

#define UART_SFREGH_SHIFT                                                               (0U)
#define UART_SFREGH_MASK                                                                (0x0000000fU)

#define UART_BLR_XBOFTYPE_SHIFT                                                         (6U)
#define UART_BLR_XBOFTYPE_MASK                                                          (0x00000040U)
#define UART_BLR_XBOFTYPE_PATTERN_FF                                                     (0U)
#define UART_BLR_XBOFTYPE_PATTERN_C0                                                     (1U)

#define UART_BLR_STSFIFORESET_SHIFT                                                     (7U)
#define UART_BLR_STSFIFORESET_MASK                                                      (0x00000080U)

#define UART_ACREG_EOTEN_SHIFT                                                          (0U)
#define UART_ACREG_EOTEN_MASK                                                           (0x00000001U)

#define UART_ACREG_ABORTEN_SHIFT                                                        (1U)
#define UART_ACREG_ABORTEN_MASK                                                         (0x00000002U)

#define UART_ACREG_SCTXEN_SHIFT                                                         (2U)
#define UART_ACREG_SCTXEN_MASK                                                          (0x00000004U)

#define UART_ACREG_SENDSIP_SHIFT                                                        (3U)
#define UART_ACREG_SENDSIP_MASK                                                         (0x00000008U)
#define UART_ACREG_SENDSIP_NO_ACTION                                                     (0U)
#define UART_ACREG_SENDSIP_PULSE                                                         (1U)

#define UART_ACREG_DISTXUNDERRUN_SHIFT                                                  (4U)
#define UART_ACREG_DISTXUNDERRUN_MASK                                                   (0x00000010U)
#define UART_ACREG_DISTXUNDERRUN_ENABLED                                                 (0U)
#define UART_ACREG_DISTXUNDERRUN_DISABLED                                                (1U)

#define UART_ACREG_DISIRRX_SHIFT                                                        (5U)
#define UART_ACREG_DISIRRX_MASK                                                         (0x00000020U)
#define UART_ACREG_DISIRRX_NORMAL                                                        (0U)
#define UART_ACREG_DISIRRX_DISABLE                                                       (1U)

#define UART_ACREG_SDMOD_SHIFT                                                          (6U)
#define UART_ACREG_SDMOD_MASK                                                           (0x00000040U)
#define UART_ACREG_SDMOD_HIGH                                                            (0U)
#define UART_ACREG_SDMOD_LOW                                                             (1U)

#define UART_ACREG_PULSETYPE_SHIFT                                                      (7U)
#define UART_ACREG_PULSETYPE_MASK                                                       (0x00000080U)
#define UART_ACREG_PULSETYPE_BAUD_RATE_3_16                                              (0U)
#define UART_ACREG_PULSETYPE_PULSE_TAYPE_VAL_1                                           (1U)

#define UART_SCR_DMAMODECTL_SHIFT                                                       (0U)
#define UART_SCR_DMAMODECTL_MASK                                                        (0x00000001U)
#define UART_SCR_DMAMODECTL_FCR_3                                                        (0U)
#define UART_SCR_DMAMODECTL_2_1                                                          (1U)

#define UART_SCR_DMAMODE2_SHIFT                                                         (1U)
#define UART_SCR_DMAMODE2_MASK                                                          (0x00000006U)
#define UART_SCR_DMAMODE2_MODE_0                                                         (0U)
#define UART_SCR_DMAMODE2_MODE_1                                                         (1U)
#define UART_SCR_DMAMODE2_MODE_2                                                         (2U)
#define UART_SCR_DMAMODE2_MODE_3                                                         (3U)

#define UART_SCR_TXEMPTYCTLIT_SHIFT                                                     (3U)
#define UART_SCR_TXEMPTYCTLIT_MASK                                                      (0x00000008U)
#define UART_SCR_TXEMPTYCTLIT_NORMAL                                                     (0U)
#define UART_SCR_TXEMPTYCTLIT_THR_INT                                                    (1U)

#define UART_SCR_RXCTSDSRWAKEUPEN_SHIFT                                                 (4U)
#define UART_SCR_RXCTSDSRWAKEUPEN_MASK                                                  (0x00000010U)
#define UART_SCR_RXCTSDSRWAKEUPEN_DISABLE_WKUP_INT                                       (0U)
#define UART_SCR_RXCTSDSRWAKEUPEN_WAIT_FOR_FALLING_EDGE                                  (1U)

#define UART_SCR_DSRIT_SHIFT                                                            (5U)
#define UART_SCR_DSRIT_MASK                                                             (0x00000020U)
#define UART_SCR_DSRIT_DISABLE                                                           (0U)
#define UART_SCR_DSRIT_ENABLE                                                            (1U)

#define UART_SCR_TXTRIGGRANU1_SHIFT                                                     (6U)
#define UART_SCR_TXTRIGGRANU1_MASK                                                      (0x00000040U)
#define UART_SCR_TXTRIGGRANU1_DISABLE                                                    (0U)
#define UART_SCR_TXTRIGGRANU1_ENABLE                                                     (1U)

#define UART_SCR_RXTRIGGRANU1_SHIFT                                                     (7U)
#define UART_SCR_RXTRIGGRANU1_MASK                                                      (0x00000080U)
#define UART_SCR_RXTRIGGRANU1_DISABLE                                                    (0U)
#define UART_SCR_RXTRIGGRANU1_ENABLE                                                     (1U)

#define UART_SSR_TXFIFOFULL_SHIFT                                                       (0U)
#define UART_SSR_TXFIFOFULL_MASK                                                        (0x00000001U)
#define UART_SSR_TXFIFOFULL_NOT_FULL                                                     (0U)
#define UART_SSR_TXFIFOFULL_FULL                                                         (1U)

#define UART_SSR_RXCTSDSRWAKEUPSTS_SHIFT                                                (1U)
#define UART_SSR_RXCTSDSRWAKEUPSTS_MASK                                                 (0x00000002U)
#define UART_SSR_RXCTSDSRWAKEUPSTS_NO_FALLING_EDGE_EVT                                   (0U)
#define UART_SSR_RXCTSDSRWAKEUPSTS_FALLING_EDGE_EVT                                      (1U)

#define UART_SSR_DMACTRRST_SHIFT                                                        (2U)
#define UART_SSR_DMACTRRST_MASK                                                         (0x00000004U)
#define UART_SSR_DMACTRRST_NOT_RESET                                                     (0U)
#define UART_SSR_DMACTRRST_RESET                                                         (1U)

#define UART_EBLR_SHIFT                                                                 (0U)
#define UART_EBLR_MASK                                                                  (0x000000ffU)
#define UART_EBLR_DISABLED                                                               (0U)
#define UART_EBLR_GEN_RXSTOP_INT_1                                                       (1U)
#define UART_EBLR_GEN_RXSTOP_INT_255                                                     (255U)

#define UART_MVR_MINORREV_SHIFT                                                         (0U)
#define UART_MVR_MINORREV_MASK                                                          (0x0000000fU)

#define UART_MVR_MAJORREV_SHIFT                                                         (4U)
#define UART_MVR_MAJORREV_MASK                                                          (0x000000f0U)

#define UART_SYSC_AUTOIDLE_SHIFT                                                        (0U)
#define UART_SYSC_AUTOIDLE_MASK                                                         (0x00000001U)
#define UART_SYSC_AUTOIDLE_RUNNING                                                       (0U)
#define UART_SYSC_AUTOIDLE_RSVD                                                          (1U)

#define UART_SYSC_SOFTRESET_SHIFT                                                       (1U)
#define UART_SYSC_SOFTRESET_MASK                                                        (0x00000002U)
#define UART_SYSC_SOFTRESET_NORMAL                                                       (0U)
#define UART_SYSC_SOFTRESET_RESET                                                        (1U)

#define UART_SYSC_ENAWAKEUP_SHIFT                                                       (2U)
#define UART_SYSC_ENAWAKEUP_MASK                                                        (0x00000004U)
#define UART_SYSC_ENAWAKEUP_DISABLED                                                     (0U)
#define UART_SYSC_ENAWAKEUP_ENABLED                                                      (1U)

#define UART_SYSC_IDLEMODE_SHIFT                                                        (3U)
#define UART_SYSC_IDLEMODE_MASK                                                         (0x00000018U)
#define UART_SYSC_IDLEMODE_FORCE_IDLE                                                    (0U)
#define UART_SYSC_IDLEMODE_NO_IDLE                                                       (1U)
#define UART_SYSC_IDLEMODE_SMART_IDLE                                                    (2U)
#define UART_SYSC_IDLEMODE_SMART_IDLE_WKUP                                               (3U)

#define UART_SYSS_RESETDONE_SHIFT                                                       (0U)
#define UART_SYSS_RESETDONE_MASK                                                        (0x00000001U)
#define UART_SYSS_RESETDONE_ONGOING                                                      (0U)
#define UART_SYSS_RESETDONE_COMPLETE                                                     (1U)

#define UART_WER_CTS_ACTIVITY_SHIFT                                                    (0U)
#define UART_WER_CTS_ACTIVITY_MASK                                                     (0x00000001U)
#define UART_WER_CTS_ACTIVITY_CANNOT_WKUP                                                (0U)
#define UART_WER_CTS_ACTIVITY_CAN_WKUP                                                   (1U)

#define UART_WER_DSR_ACTIVITY_SHIFT                                                     (1U)
#define UART_WER_DSR_ACTIVITY_MASK                                                      (0x00000002U)
#define UART_WER_DSR_ACTIVITY_CANNOT_WKUP                                                (0U)
#define UART_WER_DSR_ACTIVITY_CAN_WKUP                                                   (1U)

#define UART_WER_RI__ACTIVITY_SHIFT                                                     (2U)
#define UART_WER_RI__ACTIVITY_MASK                                                      (0x00000004U)
#define UART_WER_RI_ACTIVITY_CANNOT_WKUP                                                 (0U)
#define UART_WER_RI_ACTIVITY_CAN_WKUP                                                    (1U)

#define UART_WER_DCD_ACTIVITY_SHIFT                                                     (3U)
#define UART_WER_DCD_ACTIVITY_MASK                                                      (0x00000008U)
#define UART_WER_DCD_ACTIVITY_CANNOT_WKUP                                                (0U)
#define UART_WER_DCD_ACTIVITY_CAN_WKUP                                                   (1U)

#define UART_WER_RX__ACTIVITY_SHIFT                                                     (4U)
#define UART_WER_RX__ACTIVITY_MASK                                                      (0x00000010U)
#define UART_WER_RX_ACTIVITY_CANNOT_WKUP                                                 (0U)
#define UART_WER_RX_ACTIVITY_CAN_WKUP                                                    (1U)

#define UART_WER_RHR__INTR_SHIFT                                                        (5U)
#define UART_WER_RHR__INTR_MASK                                                         (0x00000020U)
#define UART_WER_RHR_INTR_CANNOT_WKUP                                                    (0U)
#define UART_WER_RHR_INTR_CAN_WKUP                                                       (1U)

#define UART_WER_RLS__INTR_SHIFT                                                        (6U)
#define UART_WER_RLS__INTR_MASK                                                         (0x00000040U)
#define UART_WER_RLS_INTR_CANNOT_WKUP                                                    (0U)
#define UART_WER_RLS_INTR_CAN_WKUP                                                       (1U)

#define UART_WER_TXWAKEUPEN_SHIFT                                                       (7U)
#define UART_WER_TXWAKEUPEN_MASK                                                        (0x00000080U)
#define UART_WER_TXWAKEUPEN_CANNOT_WKUP                                                  (0U)
#define UART_WER_TXWAKEUPEN_CAN_WKUP                                                     (1U)

#define UART_CFPS_SHIFT                                                                 (0U)
#define UART_CFPS_MASK                                                                  (0x000000ffU)

#define UART_RXFIFO_LVL_SHIFT                                                           (0U)
#define UART_RXFIFO_LVL_MASK                                                            (0x000000ffU)

#define UART_TXFIFO_LVL_SHIFT                                                           (0U)
#define UART_TXFIFO_LVL_MASK                                                            (0x000000ffU)

#define UART_IER2_EN_RXFIFO_EMPTY_SHIFT                                                 (0U)
#define UART_IER2_EN_RXFIFO_EMPTY_MASK                                                  (0x00000001U)
#define UART_IER2_EN_RXFIFO_EMPTY_DISABLE                                                (0U)
#define UART_IER2_EN_RXFIFO_EMPTY_ENABLE                                                 (1U)

#define UART_IER2_EN_TXFIFO_EMPTY_SHIFT                                                 (1U)
#define UART_IER2_EN_TXFIFO_EMPTY_MASK                                                  (0x00000002U)
#define UART_IER2_EN_TXFIFO_EMPTY_DISABLE                                                (0U)
#define UART_IER2_EN_TXFIFO_EMPTY_ENABLE                                                 (1U)

#define UART_ISR2_RXFIFO_EMPTY_STS_SHIFT                                                (0U)
#define UART_ISR2_RXFIFO_EMPTY_STS_MASK                                                 (0x00000001U)
#define UART_ISR2_RXFIFO_EMPTY_STS_NOT_PENDING                                           (0U)
#define UART_ISR2_RXFIFO_EMPTY_STS_PENDING                                               (1U)

#define UART_ISR2_TXFIFO_EMPTY_STS_SHIFT                                                (1U)
#define UART_ISR2_TXFIFO_EMPTY_STS_MASK                                                 (0x00000002U)
#define UART_ISR2_TXFIFO_EMPTY_STS_NOT_PENDING                                           (0U)
#define UART_ISR2_TXFIFO_EMPTY_STS_PENDING                                               (1U)

#define UART_FREQ_SEL_SHIFT                                                             (0U)
#define UART_FREQ_SEL_MASK                                                              (0x000000ffU)

#define UART_MDR3_DISABLE_CIR_RX_DEMOD_SHIFT                                            (0U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD_MASK                                             (0x00000001U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD_ENABLE                                            (0U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD                                                   (1U)

#define UART_MDR3_NONDEFAULT_FREQ_SHIFT                                                 (1U)
#define UART_MDR3_NONDEFAULT_FREQ_MASK                                                  (0x00000002U)
#define UART_MDR3_NONDEFAULT_FREQ_DISABLE                                                (0U)
#define UART_MDR3_NONDEFAULT_FREQ_ENABLE                                                 (1U)

#define UART_MDR3_SET_DMA_TX_THR_SHIFT                                                  (2U)
#define UART_MDR3_SET_DMA_TX_THR_MASK                                                   (0x00000004U)
#define UART_MDR3_SET_DMA_TX_THR_DISABLE                                                 (0U)
#define UART_MDR3_SET_DMA_TX_THR_ENABLE                                                  (1U)

#define UART_TX_DMA_THR_SHIFT                                                           (0U)
#define UART_TX_DMA_THR_MASK                                                            (0x0000003fU)

#define UART_RHR_SHIFT                                                                  (0U)
#define UART_RHR_MASK                                                                   (0x000000ffU)

#define UART_IER_CIR_RHRIT_SHIFT                                                        (0U)
#define UART_IER_CIR_RHRIT_MASK                                                         (0x00000001U)
#define UART_IER_CIR_RHRIT_DISABLE                                                       (0U)
#define UART_IER_CIR_RHRIT_ENABLE                                                        (1U)

#define UART_IER_CIR_THRIT_SHIFT                                                        (1U)
#define UART_IER_CIR_THRIT_MASK                                                         (0x00000002U)
#define UART_IER_CIR_THRIT_DISABLE                                                       (0U)
#define UART_IER_CIR_THRIT_ENABLE                                                        (1U)

#define UART_IER_CIR_RXSTOPIT_SHIFT                                                     (2U)
#define UART_IER_CIR_RXSTOPIT_MASK                                                      (0x00000004U)
#define UART_IER_CIR_RXSTOPIT_DISABLE                                                    (0U)
#define UART_IER_CIR_RXSTOPIT_ENABLE                                                     (1U)

#define UART_IER_CIR_RXOVERRUNIT_SHIFT                                                  (3U)
#define UART_IER_CIR_RXOVERRUNIT_MASK                                                   (0x00000008U)
#define UART_IER_CIR_RXOVERRUNIT_DISABLE                                                 (0U)
#define UART_IER_CIR_RXOVERRUNIT_ENABLE                                                  (1U)

#define UART_IER_CIR_TXSTSIT_SHIFT                                                      (5U)
#define UART_IER_CIR_TXSTSIT_MASK                                                       (0x00000020U)
#define UART_IER_CIR_TXSTSIT_DISABLE                                                     (0U)
#define UART_IER_CIR_TXSTSIT_ENABLE                                                      (1U)

#define UART_IIR_IT_PENDING_SHIFT                                                       (0U)
#define UART_IIR_IT_PENDING_MASK                                                        (0x00000001U)
#define UART_IIR_IT_PENDING_TRUE                                                         (0U)
#define UART_IIR_IT_PENDING_FALSE                                                        (1U)

#define UART_IIR_IT_TYPE_SHIFT                                                          (1U)
#define UART_IIR_IT_TYPE_MASK                                                           (0x0000003eU)
#define UART_IIR_IT_TYPE_MODEM                                                           (0U)
#define UART_IIR_IT_TYPE_THR                                                             (1U)
#define UART_IIR_IT_TYPE_RHR                                                             (2U)
#define UART_IIR_IT_TYPE_LINE_STS_ERR                                                    (3U)
#define UART_IIR_IT_TYPE_RSVD_1                                                          (4U)
#define UART_IIR_IT_TYPE_RSVD_2                                                          (5U)
#define UART_IIR_IT_TYPE_RX_TIMEOUT                                                      (6U)
#define UART_IIR_IT_TYPE_RSVD_3                                                          (7U)
#define UART_IIR_IT_TYPE_XOFF                                                            (8U)
#define UART_IIR_IT_TYPE_RSVD_4                                                          (9U)
#define UART_IIR_IT_TYPE_CTS_RTS_DSR                                                     (16U)
#define UART_IIR_IT_TYPE_RSVD_5                                                          (17U)

#define UART_IIR_FCR_MIRROR_SHIFT                                                       (6U)
#define UART_IIR_FCR_MIRROR_MASK                                                        (0x000000c0U)

#define UART_XON1_ADDR1_XONWORD1_SHIFT                                                  (0U)
#define UART_XON1_ADDR1_XONWORD1_MASK                                                   (0x000000ffU)

#define UART_LSR_CIR_RXFIFOE_SHIFT                                                      (0U)
#define UART_LSR_CIR_RXFIFOE_MASK                                                       (0x00000001U)
#define UART_LSR_CIR_RXFIFOE_ATLEAST_ONE_DATA_CHAR                                       (0U)
#define UART_LSR_CIR_RXFIFOE_NO_DATA                                                     (1U)

#define UART_LSR_CIR_RXSTOP_SHIFT                                                       (5U)
#define UART_LSR_CIR_RXSTOP_MASK                                                        (0x00000020U)
#define UART_LSR_CIR_RXSTOP_WAITING                                                      (0U)
#define UART_LSR_CIR_RXSTOP_COMPLETE                                                     (1U)

#define UART_LSR_CIR_THREMPTY_SHIFT                                                     (7U)
#define UART_LSR_CIR_THREMPTY_MASK                                                      (0x00000080U)
#define UART_LSR_CIR_THREMPTY_NOT_EMPTY                                                  (0U)
#define UART_LSR_CIR_THREMPTY_EMPTY                                                      (1U)

#define UART_MSR_CTS_STS_SHIFT                                                          (0U)
#define UART_MSR_CTS_STS_MASK                                                           (0x00000001U)
#define UART_MSR_CTS_STS_NO_CHANGE                                                       (0U)
#define UART_MSR_CTS_STS_CHANGE                                                          (1U)

#define UART_MSR_DSR_STS_SHIFT                                                          (1U)
#define UART_MSR_DSR_STS_MASK                                                           (0x00000002U)
#define UART_MSR_DSR_STS_NO_CHANGE                                                       (0U)
#define UART_MSR_DSR_STS_CHANGE                                                          (1U)

#define UART_MSR_RI_STS_SHIFT                                                           (2U)
#define UART_MSR_RI_STS_MASK                                                            (0x00000004U)
#define UART_MSR_RI_STS_NO_CHANGE                                                        (0U)
#define UART_MSR_RI_STS_CHANGE                                                           (1U)

#define UART_MSR_DCD_STS_SHIFT                                                          (3U)
#define UART_MSR_DCD_STS_MASK                                                           (0x00000008U)
#define UART_MSR_DCD_STS_NO_CHANGE                                                       (0U)
#define UART_MSR_DCD_STS_CHANGE                                                          (1U)

#define UART_MSR_NCTS_STS_SHIFT                                                         (4U)
#define UART_MSR_NCTS_STS_MASK                                                          (0x00000010U)

#define UART_MSR_NDSR_STS_SHIFT                                                         (5U)
#define UART_MSR_NDSR_STS_MASK                                                          (0x00000020U)

#define UART_MSR_NRI_STS_SHIFT                                                          (6U)
#define UART_MSR_NRI_STS_MASK                                                           (0x00000040U)

#define UART_MSR_NCD_STS_SHIFT                                                          (7U)
#define UART_MSR_NCD_STS_MASK                                                           (0x00000080U)

#define UART_TLR_TX_FIFO_TRIG_DMA_SHIFT                                                 (0U)
#define UART_TLR_TX_FIFO_TRIG_DMA_MASK                                                  (0x0000000fU)

#define UART_TLR_RX_FIFO_TRIG_DMA_SHIFT                                                 (4U)
#define UART_TLR_RX_FIFO_TRIG_DMA_MASK                                                  (0x000000f0U)

#define UART_SFLSR_CRC_ERROR_SHIFT                                                      (1U)
#define UART_SFLSR_CRC_ERROR_MASK                                                       (0x00000002U)
#define UART_SFLSR_CRC_ERROR_NO                                                          (0U)
#define UART_SFLSR_CRC_ERROR                                                             (1U)

#define UART_SFLSR_ABORT_DETECT_SHIFT                                                   (2U)
#define UART_SFLSR_ABORT_DETECT_MASK                                                    (0x00000004U)
#define UART_SFLSR_ABORT_DETECT_NO_ERROR                                                 (0U)
#define UART_SFLSR_ABORT_DETECT_ERROR                                                    (1U)

#define UART_SFLSR_FRM_TOO_LONG_ERROR_SHIFT                                             (3U)
#define UART_SFLSR_FRM_TOO_LONG_ERROR_MASK                                              (0x00000008U)
#define UART_SFLSR_FRM_TOO_LONG_ERROR_NO                                                 (0U)
#define UART_SFLSR_FRM_TOO_LONG_ERROR                                                    (1U)

#define UART_SFLSR_OE_ERROR_SHIFT                                                       (4U)
#define UART_SFLSR_OE_ERROR_MASK                                                        (0x00000010U)
#define UART_SFLSR_OE_ERROR_NO                                                           (0U)
#define UART_SFLSR_OE_ERROR                                                              (1U)

#define UART_TXFLH_SHIFT                                                                (0U)
#define UART_TXFLH_MASK                                                                 (0x0000001fU)

#define UART_SFREGL_SHIFT                                                               (0U)
#define UART_SFREGL_MASK                                                                (0x000000ffU)

#define UART_RXFLH_SHIFT                                                                (0U)
#define UART_RXFLH_MASK                                                                 (0x0000000fU)

#define UART_UASR_SPEED_SHIFT                                                           (0U)
#define UART_UASR_SPEED_MASK                                                            (0x0000001fU)
#define UART_UASR_SPEED_NONE_IDENTIFIED                                                  (0U)
#define UART_UASR_SPEED_BAUD_115200                                                      (1U)
#define UART_UASR_SPEED_BAUD_57600                                                       (2U)
#define UART_UASR_SPEED_BAUD_38400                                                       (3U)
#define UART_UASR_SPEED_BAUD_28800                                                       (4U)
#define UART_UASR_SPEED_BAUD_19200                                                       (5U)
#define UART_UASR_SPEED_BAUD_14400                                                       (6U)
#define UART_UASR_SPEED_BAUD_9600                                                        (7U)
#define UART_UASR_SPEED_BAUD_4800                                                        (8U)
#define UART_UASR_SPEED_BAUD_2400                                                        (9U)
#define UART_UASR_SPEED_BAUD_1200                                                        (10U)
#define UART_UASR_SPEED_RSVD                                                             (11U)

#define UART_UASR_BITBYCHAR_SHIFT                                                       (5U)
#define UART_UASR_BITBYCHAR_MASK                                                        (0x00000020U)
#define UART_UASR_BITBYCHAR_BIT_7                                                        (0U)
#define UART_UASR_BITBYCHAR_BIT_8                                                        (1U)

#define UART_UASR_PARITYTYPE_SHIFT                                                      (6U)
#define UART_UASR_PARITYTYPE_MASK                                                       (0x000000c0U)
#define UART_UASR_PARITYTYPE_NONE                                                        (0U)
#define UART_UASR_PARITYTYPE_SPACE                                                       (1U)
#define UART_UASR_PARITYTYPE_EVEN                                                        (2U)
#define UART_UASR_PARITYTYPE_ODD                                                         (3U)

#define UART_DLL_CLOCK_LSB_SHIFT                                                        (0U)
#define UART_DLL_CLOCK_LSB_MASK                                                         (0x000000ffU)

#define UART_IER_RHRIT_SHIFT                                                            (0U)
#define UART_IER_RHRIT_MASK                                                             (0x00000001U)
#define UART_IER_RHRIT_DISABLE                                                           (0U)
#define UART_IER_RHRIT_ENABLE                                                            (1U)

#define UART_IER_THRIT_SHIFT                                                            (1U)
#define UART_IER_THRIT_MASK                                                             (0x00000002U)
#define UART_IER_THRIT_DISABLE                                                           (0U)
#define UART_IER_THRIT_ENABLE                                                            (1U)

#define UART_IER_LINESTSIT_SHIFT                                                        (2U)
#define UART_IER_LINESTSIT_MASK                                                         (0x00000004U)
#define UART_IER_LINESTSIT_DISABLE                                                       (0U)
#define UART_IER_LINESTSIT_ENABLE                                                        (1U)

#define UART_IER_MODEMSTSIT_SHIFT                                                       (3U)
#define UART_IER_MODEMSTSIT_MASK                                                        (0x00000008U)
#define UART_IER_MODEMSTSIT_DISABLE                                                      (0U)
#define UART_IER_MODEMSTSIT_ENABLE                                                       (1U)

#define UART_IER_SLEEPMODE_SHIFT                                                        (4U)
#define UART_IER_SLEEPMODE_MASK                                                         (0x00000010U)
#define UART_IER_SLEEPMODE_DISABLE                                                       (0U)
#define UART_IER_SLEEPMODE_ENABLE                                                        (1U)

#define UART_IER_XOFFIT_SHIFT                                                           (5U)
#define UART_IER_XOFFIT_MASK                                                            (0x00000020U)
#define UART_IER_XOFFIT_DISABLE                                                          (0U)
#define UART_IER_XOFFIT_ENABLE                                                           (1U)

#define UART_IER_RTSIT_SHIFT                                                            (6U)
#define UART_IER_RTSIT_MASK                                                             (0x00000040U)
#define UART_IER_RTSIT_DISABLE                                                           (0U)
#define UART_IER_RTSIT_ENABLE                                                            (1U)

#define UART_IER_CTSIT_SHIFT                                                            (7U)
#define UART_IER_CTSIT_MASK                                                             (0x00000080U)
#define UART_IER_CTSIT_DISABLE                                                           (0U)
#define UART_IER_CTSIT_ENABLE                                                            (1U)

#define UART_IIR_CIR_RHRIT_SHIFT                                                        (0U)
#define UART_IIR_CIR_RHRIT_MASK                                                         (0x00000001U)
#define UART_IIR_CIR_RHRIT_EN_1_0X0                                                      (0U)
#define UART_IIR_CIR_RHRIT_EN_2_0X1                                                      (1U)

#define UART_IIR_CIR_THRIT_SHIFT                                                        (1U)
#define UART_IIR_CIR_THRIT_MASK                                                         (0x00000002U)
#define UART_IIR_CIR_THRIT_EN_1_0X0                                                      (0U)
#define UART_IIR_CIR_THRIT_EN_2_0X1                                                      (1U)

#define UART_IIR_CIR_RXSTOPIT_SHIFT                                                     (2U)
#define UART_IIR_CIR_RXSTOPIT_MASK                                                      (0x00000004U)
#define UART_IIR_CIR_RXSTOPIT_EN_1_0X0                                                   (0U)
#define UART_IIR_CIR_RXSTOPIT_EN_2_0X1                                                   (1U)

#define UART_IIR_CIR_RXOEIT_SHIFT                                                       (3U)
#define UART_IIR_CIR_RXOEIT_MASK                                                        (0x00000008U)
#define UART_IIR_CIR_RXOEIT_EN_1_0X0                                                     (0U)
#define UART_IIR_CIR_RXOEIT_EN_2_0X1                                                     (1U)

#define UART_IIR_CIR_TXSTSIT_SHIFT                                                      (5U)
#define UART_IIR_CIR_TXSTSIT_MASK                                                       (0x00000020U)
#define UART_IIR_CIR_TXSTSIT_EN_1_0X0                                                    (0U)
#define UART_IIR_CIR_TXSTSIT_EN_2_0X1                                                    (1U)

#define UART_LSR_IRDA_RX_FIFO_E_SHIFT                                                   (0U)
#define UART_LSR_IRDA_RX_FIFO_E_MASK                                                    (0x00000001U)
#define UART_LSR_IRDA_RX_FIFO_E_ATLEAST_ONE_DATA_CHAR                                    (0U)
#define UART_LSR_IRDA_RX_FIFO_E_NO_DATA                                                  (1U)

#define UART_LSR_IRDA_STS_FIFO_E_SHIFT                                                  (1U)
#define UART_LSR_IRDA_STS_FIFO_E_MASK                                                   (0x00000002U)
#define UART_LSR_IRDA_STS_FIFO_E_NOT_EMPTY                                               (0U)
#define UART_LSR_IRDA_STS_FIFO_E_EMPTY                                                   (1U)

#define UART_LSR_IRDA_CRC_SHIFT                                                         (2U)
#define UART_LSR_IRDA_CRC_MASK                                                          (0x00000004U)
#define UART_LSR_IRDA_CRC_NO_ERR                                                         (0U)
#define UART_LSR_IRDA_CRC_ERR                                                            (1U)

#define UART_LSR_IRDA_ABORT_SHIFT                                                       (3U)
#define UART_LSR_IRDA_ABORT_MASK                                                        (0x00000008U)
#define UART_LSR_IRDA_ABORT_NO_ERR                                                       (0U)
#define UART_LSR_IRDA_ABORT_ERR                                                          (1U)

#define UART_LSR_IRDA_FRM_TOO_LONG_SHIFT                                                (4U)
#define UART_LSR_IRDA_FRM_TOO_LONG_MASK                                                 (0x00000010U)
#define UART_LSR_IRDA_FRM_TOO_LONG_NO_FRAME_ERR                                          (0U)
#define UART_LSR_IRDA_FRM_TOO_LONG_FRAME_ERR                                             (1U)

#define UART_LSR_IRDA_RX_LAST_BYTE_SHIFT                                                (5U)
#define UART_LSR_IRDA_RX_LAST_BYTE_MASK                                                 (0x00000020U)
#define UART_LSR_IRDA_RX_LAST_BYTE_NO                                                    (0U)
#define UART_LSR_IRDA_RX_LAST_BYTE                                                       (1U)

#define UART_LSR_IRDA_STS_FIFO_FULL_SHIFT                                               (6U)
#define UART_LSR_IRDA_STS_FIFO_FULL_MASK                                                (0x00000040U)
#define UART_LSR_IRDA_STS_FIFO_FULL_NOT                                                  (0U)
#define UART_LSR_IRDA_STS_FIFO_FULL                                                      (1U)

#define UART_LSR_IRDA_THR_EMPTY_SHIFT                                                   (7U)
#define UART_LSR_IRDA_THR_EMPTY_MASK                                                    (0x00000080U)
#define UART_LSR_IRDA_THR_EMPTY_NOT                                                      (0U)
#define UART_LSR_IRDA_THR_EMPTY                                                          (1U)

#define UART_XOFF1_XOFFWORD1_SHIFT                                                      (0U)
#define UART_XOFF1_XOFFWORD1_MASK                                                       (0x000000ffU)

#define UART_XOFF2_XOFFWORD2_SHIFT                                                      (0U)
#define UART_XOFF2_XOFFWORD2_MASK                                                       (0x000000ffU)

#define UART_DLH_CLOCK_MSB_SHIFT                                                        (0U)
#define UART_DLH_CLOCK_MSB_MASK                                                         (0x0000003fU)

#define UART_FCR_FIFO_EN_SHIFT                                                          (0U)
#define UART_FCR_FIFO_EN_MASK                                                           (0x00000001U)
#define UART_FCR_FIFO_EN_DISABLE                                                         (0U)
#define UART_FCR_FIFO_EN_ENABLE                                                          (1U)

#define UART_FCR_RX_FIFO_CLR_SHIFT                                                      (1U)
#define UART_FCR_RX_FIFO_CLR_MASK                                                       (0x00000002U)
#define UART_FCR_RX_FIFO_CLR_NO_CHANGE                                                   (0U)
#define UART_FCR_RX_FIFO_CLR_CLEAR                                                       (1U)

#define UART_FCR_TX_FIFO_CLR_SHIFT                                                      (2U)
#define UART_FCR_TX_FIFO_CLR_MASK                                                       (0x00000004U)
#define UART_FCR_TX_FIFO_CLR_NO_CHANGE                                                   (0U)
#define UART_FCR_TX_FIFO_CLR_CLEAR                                                       (1U)

#define UART_FCR_DMA_MODE_SHIFT                                                         (3U)
#define UART_FCR_DMA_MODE_MASK                                                          (0x00000008U)
#define UART_FCR_DMA_MODE_0                                                              (0U)
#define UART_FCR_DMA_MODE_1                                                              (1U)

#define UART_FCR_TX_FIFO_TRIG_SHIFT                                                     (4U)
#define UART_FCR_TX_FIFO_TRIG_MASK                                                      (0x00000030U)
#define UART_FCR_TX_FIFO_TRIG_CHAR_8                                                     (0U)
#define UART_FCR_TX_FIFO_TRIG_CHAR_16                                                    (1U)
#define UART_FCR_TX_FIFO_TRIG_CHAR_32                                                    (2U)
#define UART_FCR_TX_FIFO_TRIG_CHAR_56                                                    (3U)

#define UART_FCR_RX_FIFO_TRIG_SHIFT                                                     (6U)
#define UART_FCR_RX_FIFO_TRIG_MASK                                                      (0x000000c0U)
#define UART_FCR_RX_FIFO_TRIG_CHAR_8                                                     (0U)
#define UART_FCR_RX_FIFO_TRIG_CHAR_16                                                    (1U)
#define UART_FCR_RX_FIFO_TRIG_CHAR_56                                                    (2U)
#define UART_FCR_RX_FIFO_TRIG_CHAR_60                                                    (3U)

#define UART_LSR_RXFIFOE_SHIFT                                                          (0U)
#define UART_LSR_RXFIFOE_MASK                                                           (0x00000001U)
#define UART_LSR_RXFIFOE_NO_DATA                                                         (0U)
#define UART_LSR_RXFIFOE_ATLEAST_ONE_DATA_CHAR                                           (1U)

#define UART_LSR_RXOE_SHIFT                                                             (1U)
#define UART_LSR_RXOE_MASK                                                              (0x00000002U)
#define UART_LSR_RXOE_NO_OVERRUN                                                         (0U)
#define UART_LSR_RXOE_OVERRUN                                                            (1U)

#define UART_LSR_RXPE_SHIFT                                                             (2U)
#define UART_LSR_RXPE_MASK                                                              (0x00000004U)
#define UART_LSR_RXPE_NO_PARITY_ERR                                                      (0U)
#define UART_LSR_RXPE_PARITY_ERR                                                         (1U)

#define UART_LSR_RXFE_SHIFT                                                             (3U)
#define UART_LSR_RXFE_MASK                                                              (0x00000008U)
#define UART_LSR_RXFE_NO_FRAMING_ERR                                                     (0U)
#define UART_LSR_RXFE_FRAMING_ERR                                                        (1U)

#define UART_LSR_RXBI_SHIFT                                                             (4U)
#define UART_LSR_RXBI_MASK                                                              (0x00000010U)
#define UART_LSR_RXBI_NO_BREAK                                                           (0U)
#define UART_LSR_RXBI_BREAK                                                              (1U)

#define UART_LSR_TXFIFOE_SHIFT                                                          (5U)
#define UART_LSR_TXFIFOE_MASK                                                           (0x00000020U)
#define UART_LSR_TXFIFOE_NOT_EMPTY                                                       (0U)
#define UART_LSR_TXFIFOE_EMPTY                                                           (1U)

#define UART_LSR_TXSRE_SHIFT                                                            (6U)
#define UART_LSR_TXSRE_MASK                                                             (0x00000040U)
#define UART_LSR_TXSRE_NOT_EMPTY                                                         (0U)
#define UART_LSR_TXSRE_EMPTY                                                             (1U)

#define UART_LSR_RXFIFOSTS_SHIFT                                                        (7U)
#define UART_LSR_RXFIFOSTS_MASK                                                         (0x00000080U)
#define UART_LSR_RXFIFOSTS_NORMAL                                                        (0U)
#define UART_LSR_RXFIFOSTS_PARITY_ERR                                                    (1U)

#define UART_IIR_IRDA_RHR_IT_SHIFT                                                      (0U)
#define UART_IIR_IRDA_RHR_IT_MASK                                                       (0x00000001U)
#define UART_IIR_IRDA_RHR_IT_INACTIVE                                                    (0U)
#define UART_IIR_IRDA_RHR_IT_ACTIVE                                                      (1U)

#define UART_IIR_IRDA_THR_IT_SHIFT                                                      (1U)
#define UART_IIR_IRDA_THR_IT_MASK                                                       (0x00000002U)
#define UART_IIR_IRDA_THR_IT_INACTIVE                                                    (0U)
#define UART_IIR_IRDA_THR_IT_ACTIVE                                                      (1U)

#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_SHIFT                                        (2U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_MASK                                         (0x00000004U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_INACTIVE                                      (0U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_ACTIVE                                        (1U)

#define UART_IIR_IRDA_RX_OE_IT_SHIFT                                                    (3U)
#define UART_IIR_IRDA_RX_OE_IT_MASK                                                     (0x00000008U)
#define UART_IIR_IRDA_RX_OE_IT_INACTIVE                                                  (0U)
#define UART_IIR_IRDA_RX_OE_IT_ACTIVE                                                    (1U)

#define UART_IIR_IRDA_STS_FIFO_IT_SHIFT                                                 (4U)
#define UART_IIR_IRDA_STS_FIFO_IT_MASK                                                  (0x00000010U)
#define UART_IIR_IRDA_STS_FIFO_IT_INACTIVE                                               (0U)
#define UART_IIR_IRDA_STS_FIFO_IT_ACTIVE                                                 (1U)

#define UART_IIR_IRDA_TX_STS_IT_SHIFT                                                   (5U)
#define UART_IIR_IRDA_TX_STS_IT_MASK                                                    (0x00000020U)
#define UART_IIR_IRDA_TX_STS_IT_INACTIVE                                                 (0U)
#define UART_IIR_IRDA_TX_STS_IT_ACTIVE                                                   (1U)

#define UART_IIR_IRDA_LINE_STS_IT_SHIFT                                                 (6U)
#define UART_IIR_IRDA_LINE_STS_IT_MASK                                                  (0x00000040U)
#define UART_IIR_IRDA_LINE_STS_IT_INACTIVE                                               (0U)
#define UART_IIR_IRDA_LINE_STS_IT_ACTIVE                                                 (1U)

#define UART_IIR_IRDA_EOF_IT_SHIFT                                                      (7U)
#define UART_IIR_IRDA_EOF_IT_MASK                                                       (0x00000080U)
#define UART_IIR_IRDA_EOF_IT_INACTIVE                                                    (0U)
#define UART_IIR_IRDA_EOF_IT_ACTIVE                                                      (1U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_UART_H_ */
