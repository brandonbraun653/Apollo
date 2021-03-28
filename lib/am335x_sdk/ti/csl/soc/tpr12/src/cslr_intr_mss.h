/********************************************************************
*
* MSS INTR Map Header file
*
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
*/
#ifndef CSLR_INTR_MSS_H_
#define CSLR_INTR_MSS_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* List of intr sources for receiver: MSS */
#define CSL_MSS_INTR_MSS_ESM_LO                       0           /* ESM Low Priority Interrupt */
#define CSL_MSS_INTR_MSS_ESM_HI                       1           /* ESM High Priority Interrupt */
#define CSL_MSS_INTR_RESERVED2                        2           /* RESERVED */
#define CSL_MSS_INTR_MSS_RTIA_INT0                    3           /* RTIA compare interrupt */
#define CSL_MSS_INTR_MSS_RTIA_INT1                    4           /* RTIA compare interrupt */
#define CSL_MSS_INTR_MSS_RTIA_INT2                    5           /* RTIA compare interrupt */
#define CSL_MSS_INTR_MSS_RTIA_INT3                    6           /* RTIA compare interrupt */
#define CSL_MSS_INTR_MSS_RTIA_OVERFLOW_INT0           7           /* RTIA overflow interrupt */
#define CSL_MSS_INTR_MSS_RTIA_OVERFLOW_INT1           8           /* RTIA overflow interrupt */
#define CSL_MSS_INTR_MSS_RTIB_INT0                    9           /* RTIB compare interrupt */
#define CSL_MSS_INTR_MSS_RTIB_INT1                    10          /* RTIB compare interrupt */
#define CSL_MSS_INTR_MSS_RTIB_OVERFLOW_INT0           11          /* RTIB overflow interrupt */
#define CSL_MSS_INTR_MSS_RTIB_OVERFLOW_INT1           12          /* RTIB overflow interrupt */
#define CSL_MSS_INTR_MSS_RTIC_INT0                    13          /* RTIC compare interrupt */
#define CSL_MSS_INTR_MSS_RTIC_INT1                    14          /* RTIC compare interrupt */
#define CSL_MSS_INTR_MSS_RTIC_OVERFLOW_INT0           15          /* RTIC overflow interrupt */
#define CSL_MSS_INTR_MSS_RTIC_OVERFLOW_INT1           16          /* RTIC overflow interrupt */
#define CSL_MSS_INTR_MSS_WDT_INT0                     17          /* WDT compare interrupt */
#define CSL_MSS_INTR_MSS_WDT_INT1                     18          /* WDT compare interrupt */
#define CSL_MSS_INTR_MSS_WDT_INT2                     19          /* WDT compare interrupt */
#define CSL_MSS_INTR_MSS_WDT_INT3                     20          /* WDT compare interrupt */
#define CSL_MSS_INTR_MSS_WDT_OVERFLOW_INT0            21          /* WDT over flow interrupt */
#define CSL_MSS_INTR_MSS_WDT_OVERFLOW_INT1            22          /* WDT over flow interrupt */
#define CSL_MSS_INTR_MSS_WDT_TB_INT                   23          /* WDT time base interrupt */
#define CSL_MSS_INTR_MSS_MCRC_INT                     24          /* Interrupt from MCRC */
#define CSL_MSS_INTR_MSS_DCCA_INT                     25          /* MSS_DCCA Clock compare done interrupt */
#define CSL_MSS_INTR_MSS_DCCB_INT                     26          /* MSS_DCCB  Clock compare done interrupt */
#define CSL_MSS_INTR_MSS_DCCC_INT                     27          /* MSS_DCCC  Clock compare done interrupt */
#define CSL_MSS_INTR_MSS_DCCD_INT                     28          /* MSS_DCCD  Clock compare done interrupt */
#define CSL_MSS_INTR_MSS_CCCA_INT                     29          /* MSS_CCCA dual clock compare done interrupt */
#define CSL_MSS_INTR_MSS_CCCB_INT                     30          /* MSS_CCCB dual clock compare done interrupt */
#define CSL_MSS_INTR_MSS_SPIA_INT0                    31          /* MSS_SPIA level 0 interrupt */
#define CSL_MSS_INTR_MSS_SPIA_INT1                    32          /* MSS_SPIA level 1 interrupt */
#define CSL_MSS_INTR_MSS_SPIB_INT0                    33          /* MSS_SPIB level 0 interrupt */
#define CSL_MSS_INTR_MSS_SPIB_INT1                    34          /* MSS_SPIB level 1 interrupt */
#define CSL_MSS_INTR_MSS_QSPI_INT                     35          /* MSS_QSPI interrupt */
#define CSL_MSS_INTR_MSS_GIO_INT0                     36          /* MSS_GIO high-level Interrupt  */
#define CSL_MSS_INTR_MSS_GIO_INT1                     37          /* MSS_GIO low-level interrupt  */
#define CSL_MSS_INTR_MSS_ETPWMA_INT0                  38          /* MSS_ETPWMA Interrupt  0 which is a output to pad  */
#define CSL_MSS_INTR_MSS_ETPWMA_INT1                  39          /* MSS_ETPWMA Interrupt  1 which is a output to pad  */
#define CSL_MSS_INTR_MSS_ETPWMB_INT0                  40          /* MSS_ETPWMB Interrupt  0 which is a output to pad  */
#define CSL_MSS_INTR_MSS_ETPWMB_INT1                  41          /* MSS_ETPWMB Interrupt  1 which is a output to pad  */
#define CSL_MSS_INTR_MSS_ETPWMC_INT0                  42          /* MSS_ETPWMC Interrupt  0 which is a output to pad  */
#define CSL_MSS_INTR_MSS_ETPWMC_INT1                  43          /* MSS_ETPWMC Interrupt  1 which is a output to pad  */
#define CSL_MSS_INTR_MSS_MCANA_INT0                   44          /* MSS_MCANA first interrupt */
#define CSL_MSS_INTR_MSS_MCANA_INT1                   45          /* MSS_MCANA second interrupt */
#define CSL_MSS_INTR_MSS_MCANA_FE_INT0                46          /* MSS_MCANA message filter interrupt0 */
#define CSL_MSS_INTR_MSS_MCANA_FE_INT1                47          /* MSS_MCANA message filter interrupt1 */
#define CSL_MSS_INTR_MSS_MCANB_INT0                   48          /* MSS_MCANB first interrupt */
#define CSL_MSS_INTR_MSS_MCANB_INT1                   49          /* MSS_MCANB second interrupt */
#define CSL_MSS_INTR_MSS_MCANB_FE_INT0                50          /* MSS_MCANB message filter interrupt0 */
#define CSL_MSS_INTR_MSS_MCANB_FE_INT1                51          /* MSS_MCANB message filter interrupt1 */
#define CSL_MSS_INTR_MSS_I2C_INT                      52          /* MSS_I2C interrupt */
#define CSL_MSS_INTR_MSS_SCIA_INT0                    53          /* MSS_SCIA level0 input */
#define CSL_MSS_INTR_MSS_SCIA_INT1                    54          /* MSS_SCIA level1 input */
#define CSL_MSS_INTR_MSS_SCIB_INT0                    55          /* MSS_SCIB level0 input */
#define CSL_MSS_INTR_MSS_SCIB_INT1                    56          /* MSS_SCIB level1 input */
#define CSL_MSS_INTR_TOP_PBIST_DONE_INT               57          /* TOP_PBIST done interrupt */
#define CSL_MSS_INTR_MSS_GIO_PAD_INT0                 58          /* Interrupt Triger from GIO[0][0] */
#define CSL_MSS_INTR_MSS_GIO_PAD_INT1                 59          /* Interrupt Triger from GIO[0][1] */
#define CSL_MSS_INTR_MSS_GIO_PAD_INT2                 60          /* Interrupt Triger from GIO[0][2] */
#define CSL_MSS_INTR_RESERVED61                       61          /* RESERVED */
#define CSL_MSS_INTR_RESERVED62                       62          /* RESERVED */
#define CSL_MSS_INTR_MSS_MCANA_FE_INT2                63          /* MSS_MCANA message filter interrupt2 */
#define CSL_MSS_INTR_MSS_MCANB_FE_INT2                64          /* MSS_MCANB message filter interrupt2 */
#define CSL_MSS_INTR_RESERVED65                       65          /* RESERVED */
#define CSL_MSS_INTR_RESERVED66                       66          /* RESERVED */
#define CSL_MSS_INTR_MSS_TPCC_A_INTAGG                67          /* MSS_TPCC_A Aggregated Functional Interrupt */
#define CSL_MSS_INTR_MSS_TPCC_B_INTAGG                68          /* MSS_TPCC_B Aggregated Functional Interrupt */
#define CSL_MSS_INTR_RESERVED69                       69          /* RESERVED */
#define CSL_MSS_INTR_MSS_GPADC_IFM_DONE               70          /* MSS_GPADC ifm done interrupt */
#define CSL_MSS_INTR_RESERVED71                       71          /* RESERVED */
#define CSL_MSS_INTR_MSS_CPSW_TH_TRSH_INT             72          /* MSS CPSW T-host threshold interrupt */
#define CSL_MSS_INTR_MSS_CPSW_TH_INT                  73          /* MSS CPSW T-host interrupt */
#define CSL_MSS_INTR_MSS_CPSW_FH_INT                  74          /* MSS CPSW F-host interrupt */
#define CSL_MSS_INTR_MSS_CPSW_MISC_INT                75          /* MSS CPSW interrupt */
#define CSL_MSS_INTR_RESERVED76                       76          /* RESERVED */
#define CSL_MSS_INTR_MSS_CR5A_MBOX_READ_REQ           77          /* Aggregated interrupt to MSS CR5A from other processor asking it to read */
#define CSL_MSS_INTR_MSS_CR5A_MBOX_READ_ACK           78          /* Aggregated interrupt to MSS CR5A from other processor saying the reading from their mailbox is done. */
#define CSL_MSS_INTR_MSS_CR5B_MBOX_READ_REQ           79          /* Aggregated interrupt to MSS CR5B from other processor asking it to read */
#define CSL_MSS_INTR_MSS_CR5B_MBOX_READ_ACK           80          /* Aggregated interrupt to MSS CR5B from other processor saying the reading from their mailbox is done. */
#define CSL_MSS_INTR_RESERVED81                       81          /* RESERVED */
#define CSL_MSS_INTR_TOP_DEBUGSS_TXDATA_AVAIL         82          /* Interrupt from TOP_DEBUGSS */
#define CSL_MSS_INTR_MSS_CR5A_PMU_INT                 83          /* Pmu Interrupt from MSS_CR5A */
#define CSL_MSS_INTR_MSS_CR5B_PMU_INT                 84          /* Pmu Interrupt from MSS_CR5B */
#define CSL_MSS_INTR_MSS_CR5A_FPU_INT                 85          /* Floating point expection from MSS_CR5A */
#define CSL_MSS_INTR_MSS_CR5B_FPU_INT                 86          /* Floating point expection from MSS_CR5B */
#define CSL_MSS_INTR_RESERVED87                       87          /* RESERVED */
#define CSL_MSS_INTR_RESERVED88                       88          /* RESERVED */
#define CSL_MSS_INTR_RESERVED89                       89          /* RESERVED */
#define CSL_MSS_INTR_RESERVED90                       90          /* RESERVED */
#define CSL_MSS_INTR_MSS_SW_INT0                      91          /* Software Interrupt from MSS_CTRL */
#define CSL_MSS_INTR_MSS_SW_INT1                      92          /* Software Interrupt from MSS_CTRL */
#define CSL_MSS_INTR_MSS_SW_INT2                      93          /* Software Interrupt from MSS_CTRL */
#define CSL_MSS_INTR_MSS_SW_INT3                      94          /* Software Interrupt from MSS_CTRL */
#define CSL_MSS_INTR_MSS_SW_INT4                      95          /* Software Interrupt from MSS_CTRL */
//#define CSL_MSS_INTR_RESERVED                         96 to 119   /* RESERVED */
#define CSL_MSS_INTR_DSS_TPCC_A_INTAGG                120         /* DSS_TPCC_A Aggregated Functional Interrupt */
#define CSL_MSS_INTR_DSS_TPCC_A_ERRAGG                121         /* DSS_TPCC_A Agregated Error Interrupt */
#define CSL_MSS_INTR_DSS_TPCC_B_INTAGG                122         /* DSS_TPCC_B_Aggregated Functional Interrupt */
#define CSL_MSS_INTR_DSS_TPCC_B_ERRAGG                123         /* DSS_TPCC_B Agregated Error Interrupt */
#define CSL_MSS_INTR_DSS_TPCC_C_INTAGG                124         /* DSS_TPCC_C Aggregated Functional Interrupt */
#define CSL_MSS_INTR_DSS_TPCC_C_ERRAGG                125         /* DSS_TPCC_C Agregated Error Interrupt */
#define CSL_MSS_INTR_RESERVED126                      126         /* RESERVED */
#define CSL_MSS_INTR_RESERVED127                      127         /* RESERVED */
#define CSL_MSS_INTR_RESERVED128                      128         /* RESERVED */
#define CSL_MSS_INTR_DSS_DSP_PBIST_CTRL_DONE          129         /* DSS DSP PBIST Controller Done Interrupt */
#define CSL_MSS_INTR_DSS_SW_INT0                      130         /* SW interrupt generated by writing 0x1 to register  DSS_CTRL.DSS_SW_INT[0] */
#define CSL_MSS_INTR_DSS_SW_INT1                      131         /* SW interrupt generated by writing 0x1 to register  DSS_CTRL.DSS_SW_INT[1] */
#define CSL_MSS_INTR_DSS_SW_INT2                      132         /* SW interrupt generated by writing 0x1 to register  DSS_CTRL.DSS_SW_INT[2] */
#define CSL_MSS_INTR_DSS_SW_INT3                      133         /* SW interrupt generated by writing 0x1 to register  DSS_CTRL.DSS_SW_INT[3] */
#define CSL_MSS_INTR_RESERVED134                      134         /* RESERVED */
#define CSL_MSS_INTR_RESERVED135                      135         /* RESERVED */
#define CSL_MSS_INTR_DSS_MCRC_INT                     136         /* DSS MCRC Interrupt */
#define CSL_MSS_INTR_DSS_DSP_STC_DONE                 137         /* DSS DSP STC Done Interrupt */
#define CSL_MSS_INTR_DSS_DSP_PBIST_DONE               138         /* DSS DSP PBIST Done Interrupt */
#define CSL_MSS_INTR_DSS_SCIA_INT0                    139         /* DSS SCIA Interrupt 0 */
#define CSL_MSS_INTR_DSS_SCIA_INT1                    140         /* DSS SCIA Interrupt 1 */
#define CSL_MSS_INTR_DSS_SCIB_INT0                    141         /* DSS SCIA Interrupt 0 */
#define CSL_MSS_INTR_DSS_SCIB_INT1                    142         /* DSS SCIA Interrupt 1 */
#define CSL_MSS_INTR_DSS_CBUFF_INT                    143         /* DSS CBUFF Interrupt */
#define CSL_MSS_INTR_DSS_CBUFF_INT_ERR                144         /* DSSCBUFF Error Interrupt  */
#define CSL_MSS_INTR_RCSS_CSI2A_INT                   145         /* RCSS CSI2 A Receiver Interrupt */
#define CSL_MSS_INTR_RCSS_CSI2B_INT                   146         /* RCSS CSI2 B Receiver Interrupt */
#define CSL_MSS_INTR_RCSS_SPIA_INT0                   147         /* RCSS SPI A Interrupt 0 */
#define CSL_MSS_INTR_RCSS_SPIA_INT1                   148         /* RCSS SPI A Interrupt 1 */
#define CSL_MSS_INTR_RCSS_SPIB_INT0                   149         /* RCSS SPI B Interrupt 0 */
#define CSL_MSS_INTR_RCSS_SPIB_INT1                   150         /* RCSS SPI B Interrupt 1 */
#define CSL_MSS_INTR_RCSS_TPCC_A_INTAGG               151         /* RCSS_TPCC_A Aggregated Functional Interrupt */
#define CSL_MSS_INTR_RCSS_TPCC_A_ERRAGG               152         /* RCSS_TPCC_A Aggregated Error Interrupt */
#define CSL_MSS_INTR_RCSS_ECAP_INT                    153         /* RCSS ECAP Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPA_TX_INT               154         /* RCSS McASP A Tx Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPB_TX_INT               155         /* RCSS McASP B Tx Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPC_TX_INT               156         /* RCSS McASP C Tx Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPA_RX_INT               157         /* RCSS McASP A Rx Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPB_RX_INT               158         /* RCSS McASP B Rx Interrupt */
#define CSL_MSS_INTR_RCSS_MCASPC_RX_INT               159         /* RCSS McASP C Rx Interrupt */
#define CSL_MSS_INTR_RESERVED160                      160         /* RESERVED */
#define CSL_MSS_INTR_RESERVED161                      161         /* RESERVED */
#define CSL_MSS_INTR_DSS_WDT_TB_INT                   162         /* DSS WDT Time Base Interrupt */
#define CSL_MSS_INTR_DSS_HWA_INTAGG                   163         /* DSS HWA Aggregated Interrupt */
#define CSL_MSS_INTR_DSS DCCA_INT                     164         /* DSS DCCA Interrupt */
#define CSL_MSS_INTR_DSS_DCCB_INT                     165         /* DSS DCCB Interrupt */
#define CSL_MSS_INTR_DSS_RTIA_OVERFLOW_0              166         /* DSS_RTIA Overflow 0 */
#define CSL_MSS_INTR_DSS_RTIA_OVERFLOW_1              167         /* DSS_RTIA Overflow 1 */
#define CSL_MSS_INTR_DSS_RTIA_0                       168         /* DSS_RTIA Interrupt 0 */
#define CSL_MSS_INTR_DSS_RTIA_1                       169         /* DSS_RTIA Interrupt 1 */
#define CSL_MSS_INTR_DSS_RTIA_2                       170         /* DSS_RTIA Interrupt 2 */
#define CSL_MSS_INTR_DSS_RTIA_3                       171         /* DSS_RTIA Interrupt 3 */
#define CSL_MSS_INTR_DSS_RTIB_OVERFLOW_0              172         /* DSS_RTIB Overflow 0 */
#define CSL_MSS_INTR_DSS_RTIB_OVERFLOW_1              173         /* DSS_RTIB Overflow 1 */
#define CSL_MSS_INTR_DSS_RTIB_0                       174         /* DSS_RTIB Interrupt 0 */
#define CSL_MSS_INTR_DSS_RTIB_1                       175         /* DSS_RTIB Interrupt 1 */
#define CSL_MSS_INTR_DSS_RTIB_2                       176         /* DSS_RTIB Interrupt 2 */
#define CSL_MSS_INTR_DSS_RTIB_3                       177         /* DSS_RTIB Interrupt 3 */
#define CSL_MSS_INTR_DSS_WDT_OVERFLOW_0               178         /* DSS_WDT Overflow 0 */
#define CSL_MSS_INTR_DSS_WDT_OVERFLOW_1               179         /* DSS_WDT Overflow 1 */
#define CSL_MSS_INTR_DSS_WDT_0                        180         /* DSS_WDT Interrupt 0 */
#define CSL_MSS_INTR_DSS_WDT_1                        181         /* DSS_WDT Interrupt 1 */
#define CSL_MSS_INTR_DSS_WDT_2                        182         /* DSS_WDT Interrupt 2 */
#define CSL_MSS_INTR_DSS_WDT_3                        183         /* DSS_WDT Interrupt 3 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT0             184         /* RCSS ICSSM Host Interrupt 0 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT1             185         /* RCSS ICSSM Host Interrupt 1 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT2             186         /* RCSS ICSSM Host Interrupt 2 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT3             187         /* RCSS ICSSM Host Interrupt 3 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT4             188         /* RCSS ICSSM Host Interrupt 4 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT5             189         /* RCSS ICSSM Host Interrupt 5 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT6             190         /* RCSS ICSSM Host Interrupt 6 */
#define CSL_MSS_INTR_RCSS_ICSSM_HOST_INT7             191         /* RCSS ICSSM Host Interrupt 7 */
#define CSL_MSS_INTR_RCSS_I2CA_INT                    192         /* RCSS I2C A Interrupt */
#define CSL_MSS_INTR_RCSS_I2CB_INT                    193         /* RCSS I2C B Interrupt */
#define CSL_MSS_INTR_RESERVED193                      194         /* RESERVED */
#define CSL_MSS_INTR_RESERVED194                      195         /* RESERVED */
#define CSL_MSS_INTR_DSS_DSP_MBOX_READ_REQ            196         /* DSS DSP Mailbox Read Request */
#define CSL_MSS_INTR_DSS_DSP_MBOX_READ_ACK            197         /* DSS DSP Mailbox Read Acknowledge */
//#define CSL_MSS_INTR_RESERVED                         198 to 255  /* RESERVED */


/* MSS EDMA Interrupts */
#define EDMA_MSS_CC0_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_MSS_TPCC_A_INTAGG
#define EDMA_MSS_CC0_AGGREGATED_ERRROR_INTR_ID   65 //TODO_TPR12: Not yet connected in RTL 0.6, fake it for now CSL_MSS_INTR_MSS_TPCC_A_ERRARG

#define EDMA_MSS_CC1_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_MSS_TPCC_B_INTAGG
#define EDMA_MSS_CC1_AGGREGATED_ERRROR_INTR_ID   66 //TODO_TPR12: Not yet connected in RTL 0.6, fake it for now CSL_MSS_INTR_MSS_TPCC_B_ERRARG

#define EDMA_MSS_CC2_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_DSS_TPCC_A_INTAGG
#define EDMA_MSS_CC2_AGGREGATED_ERRROR_INTR_ID   CSL_MSS_INTR_DSS_TPCC_A_ERRAGG

#define EDMA_MSS_CC3_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_DSS_TPCC_B_INTAGG
#define EDMA_MSS_CC3_AGGREGATED_ERRROR_INTR_ID   CSL_MSS_INTR_DSS_TPCC_B_ERRAGG

#define EDMA_MSS_CC4_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_DSS_TPCC_C_INTAGG
#define EDMA_MSS_CC4_AGGREGATED_ERRROR_INTR_ID   CSL_MSS_INTR_DSS_TPCC_C_ERRAGG

#define EDMA_MSS_CC5_TRANSFER_COMPLETE_INTR_ID   CSL_MSS_INTR_RCSS_TPCC_A_INTAGG
#define EDMA_MSS_CC5_AGGREGATED_ERRROR_INTR_ID   CSL_MSS_INTR_RCSS_TPCC_A_ERRAGG


#ifdef __cplusplus
}
#endif
#endif /* CSLR_INTR_MSS_H_*/
