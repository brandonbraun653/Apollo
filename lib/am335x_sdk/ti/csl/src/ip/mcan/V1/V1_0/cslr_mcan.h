/********************************************************************
 *   Copyright (C) Texas Instruments Incorporated 2019
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
#ifndef CSLR_MCAN_H_
#define CSLR_MCAN_H_

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
    volatile uint32_t ICS;                       /* Interrupt Clear Shadow Register */
    volatile uint32_t IRS;                       /* Interrupt Raw Status Register */
    volatile uint32_t IECS;                      /* Interrupt Enable Clear Shadow Register */
    volatile uint32_t IE;                        /* Interrupt Enable Register */
    volatile uint32_t IES;                       /* Interrupt Enable Status */
    volatile uint32_t EOI;                       /* End Of Interrupt */
    volatile uint32_t EXT_TS_PRESCALER;          /* External TimeStamp PreScaler 0 */
    volatile uint32_t EXT_TS_UNSERVICED_INTR_CNTR;   /* External TimeStamp PreScaler 0 */
} CSL_mcanRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MCAN_PID                                                           (0x00000000U)
#define CSL_MCAN_CTRL                                                          (0x00000004U)
#define CSL_MCAN_STAT                                                          (0x00000008U)
#define CSL_MCAN_ICS                                                           (0x0000000CU)
#define CSL_MCAN_IRS                                                           (0x00000010U)
#define CSL_MCAN_IECS                                                          (0x00000014U)
#define CSL_MCAN_IE                                                            (0x00000018U)
#define CSL_MCAN_IES                                                           (0x0000001CU)
#define CSL_MCAN_EOI                                                           (0x00000020U)
#define CSL_MCAN_EXT_TS_PRESCALER                                              (0x00000024U)
#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR                                   (0x00000028U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_MCAN_PID_MINOR_MASK                                                (0x0000003FU)
#define CSL_MCAN_PID_MINOR_SHIFT                                               (0x00000000U)
#define CSL_MCAN_PID_MINOR_RESETVAL                                            (0x00000001U)
#define CSL_MCAN_PID_MINOR_MAX                                                 (0x0000003FU)

#define CSL_MCAN_PID_CUSTOM_MASK                                               (0x000000C0U)
#define CSL_MCAN_PID_CUSTOM_SHIFT                                              (0x00000006U)
#define CSL_MCAN_PID_CUSTOM_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_PID_CUSTOM_MAX                                                (0x00000003U)

#define CSL_MCAN_PID_MAJOR_MASK                                                (0x00000700U)
#define CSL_MCAN_PID_MAJOR_SHIFT                                               (0x00000008U)
#define CSL_MCAN_PID_MAJOR_RESETVAL                                            (0x00000001U)
#define CSL_MCAN_PID_MAJOR_MAX                                                 (0x00000007U)

#define CSL_MCAN_PID_RTL_MASK                                                  (0x0000F800U)
#define CSL_MCAN_PID_RTL_SHIFT                                                 (0x0000000BU)
#define CSL_MCAN_PID_RTL_RESETVAL                                              (0x00000000U)
#define CSL_MCAN_PID_RTL_MAX                                                   (0x0000001FU)

#define CSL_MCAN_PID_MODULE_ID_MASK                                            (0x0FFF0000U)
#define CSL_MCAN_PID_MODULE_ID_SHIFT                                           (0x00000010U)
#define CSL_MCAN_PID_MODULE_ID_RESETVAL                                        (0x000008E0U)
#define CSL_MCAN_PID_MODULE_ID_MAX                                             (0x00000FFFU)

#define CSL_MCAN_PID_BU_MASK                                                   (0x30000000U)
#define CSL_MCAN_PID_BU_SHIFT                                                  (0x0000001CU)
#define CSL_MCAN_PID_BU_RESETVAL                                               (0x00000002U)
#define CSL_MCAN_PID_BU_MAX                                                    (0x00000003U)

#define CSL_MCAN_PID_SCHEME_MASK                                               (0xC0000000U)
#define CSL_MCAN_PID_SCHEME_SHIFT                                              (0x0000001EU)
#define CSL_MCAN_PID_SCHEME_RESETVAL                                           (0x00000001U)
#define CSL_MCAN_PID_SCHEME_MAX                                                (0x00000003U)

#define CSL_MCAN_PID_RESETVAL                                                  (0x68E00101U)

/* CTRL */

#define CSL_MCAN_CTRL_RESET_MASK                                               (0x00000001U)
#define CSL_MCAN_CTRL_RESET_SHIFT                                              (0x00000000U)
#define CSL_MCAN_CTRL_RESET_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_CTRL_RESET_MAX                                                (0x00000001U)

#define CSL_MCAN_CTRL_CLKFACK_MASK                                             (0x00000002U)
#define CSL_MCAN_CTRL_CLKFACK_SHIFT                                            (0x00000001U)
#define CSL_MCAN_CTRL_CLKFACK_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CTRL_CLKFACK_MAX                                              (0x00000001U)

#define CSL_MCAN_CTRL_DBGSUSP_SOFT_MASK                                        (0x00000004U)
#define CSL_MCAN_CTRL_DBGSUSP_SOFT_SHIFT                                       (0x00000002U)
#define CSL_MCAN_CTRL_DBGSUSP_SOFT_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CTRL_DBGSUSP_SOFT_MAX                                         (0x00000001U)

#define CSL_MCAN_CTRL_DBGSUSP_FREE_MASK                                        (0x00000008U)
#define CSL_MCAN_CTRL_DBGSUSP_FREE_SHIFT                                       (0x00000003U)
#define CSL_MCAN_CTRL_DBGSUSP_FREE_RESETVAL                                    (0x00000001U)
#define CSL_MCAN_CTRL_DBGSUSP_FREE_MAX                                         (0x00000001U)

#define CSL_MCAN_CTRL_WAKEUPREQEN_MASK                                         (0x00000010U)
#define CSL_MCAN_CTRL_WAKEUPREQEN_SHIFT                                        (0x00000004U)
#define CSL_MCAN_CTRL_WAKEUPREQEN_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CTRL_WAKEUPREQEN_MAX                                          (0x00000001U)

#define CSL_MCAN_CTRL_AUTOWAKEUP_MASK                                          (0x00000020U)
#define CSL_MCAN_CTRL_AUTOWAKEUP_SHIFT                                         (0x00000005U)
#define CSL_MCAN_CTRL_AUTOWAKEUP_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CTRL_AUTOWAKEUP_MAX                                           (0x00000001U)

#define CSL_MCAN_CTRL_EXT_TS_CNTR_EN_MASK                                      (0x00000040U)
#define CSL_MCAN_CTRL_EXT_TS_CNTR_EN_SHIFT                                     (0x00000006U)
#define CSL_MCAN_CTRL_EXT_TS_CNTR_EN_RESETVAL                                  (0x00000000U)
#define CSL_MCAN_CTRL_EXT_TS_CNTR_EN_MAX                                       (0x00000001U)

#define CSL_MCAN_CTRL_RESETVAL                                                 (0x00000008U)

/* STAT */

#define CSL_MCAN_STAT_RESET_MASK                                               (0x00000001U)
#define CSL_MCAN_STAT_RESET_SHIFT                                              (0x00000000U)
#define CSL_MCAN_STAT_RESET_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_STAT_RESET_MAX                                                (0x00000001U)

#define CSL_MCAN_STAT_MEM_INIT_DONE_MASK                                       (0x00000002U)
#define CSL_MCAN_STAT_MEM_INIT_DONE_SHIFT                                      (0x00000001U)
#define CSL_MCAN_STAT_MEM_INIT_DONE_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_STAT_MEM_INIT_DONE_MAX                                        (0x00000001U)

#define CSL_MCAN_STAT_ENABLE_FDOE_MASK                                         (0x00000004U)
#define CSL_MCAN_STAT_ENABLE_FDOE_SHIFT                                        (0x00000002U)
#define CSL_MCAN_STAT_ENABLE_FDOE_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_STAT_ENABLE_FDOE_MAX                                          (0x00000001U)

#define CSL_MCAN_STAT_STATE_MASK                                               (0x00000038U)
#define CSL_MCAN_STAT_STATE_SHIFT                                              (0x00000003U)
#define CSL_MCAN_STAT_STATE_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_STAT_STATE_MAX                                                (0x00000007U)

#define CSL_MCAN_STAT_RESETVAL                                                 (0x00000000U)

/* ICS */

#define CSL_MCAN_ICS_EXT_TS_CNTR_OVFL_MASK                                     (0x00000001U)
#define CSL_MCAN_ICS_EXT_TS_CNTR_OVFL_SHIFT                                    (0x00000000U)
#define CSL_MCAN_ICS_EXT_TS_CNTR_OVFL_RESETVAL                                 (0x00000000U)
#define CSL_MCAN_ICS_EXT_TS_CNTR_OVFL_MAX                                      (0x00000001U)

#define CSL_MCAN_ICS_RESETVAL                                                  (0x00000000U)

/* IRS */

#define CSL_MCAN_IRS_EXT_TS_CNTR_OVFL_MASK                                     (0x00000001U)
#define CSL_MCAN_IRS_EXT_TS_CNTR_OVFL_SHIFT                                    (0x00000000U)
#define CSL_MCAN_IRS_EXT_TS_CNTR_OVFL_RESETVAL                                 (0x00000000U)
#define CSL_MCAN_IRS_EXT_TS_CNTR_OVFL_MAX                                      (0x00000001U)

#define CSL_MCAN_IRS_RESETVAL                                                  (0x00000000U)

/* IECS */

#define CSL_MCAN_IECS_EXT_TS_CNTR_OVFL_MASK                                    (0x00000001U)
#define CSL_MCAN_IECS_EXT_TS_CNTR_OVFL_SHIFT                                   (0x00000000U)
#define CSL_MCAN_IECS_EXT_TS_CNTR_OVFL_RESETVAL                                (0x00000000U)
#define CSL_MCAN_IECS_EXT_TS_CNTR_OVFL_MAX                                     (0x00000001U)

#define CSL_MCAN_IECS_RESETVAL                                                 (0x00000000U)

/* IE */

#define CSL_MCAN_IE_EXT_TS_CNTR_OVFL_MASK                                      (0x00000001U)
#define CSL_MCAN_IE_EXT_TS_CNTR_OVFL_SHIFT                                     (0x00000000U)
#define CSL_MCAN_IE_EXT_TS_CNTR_OVFL_RESETVAL                                  (0x00000000U)
#define CSL_MCAN_IE_EXT_TS_CNTR_OVFL_MAX                                       (0x00000001U)

#define CSL_MCAN_IE_RESETVAL                                                   (0x00000000U)

/* IES */

#define CSL_MCAN_IES_EXT_TS_CNTR_OVFL_MASK                                     (0x00000001U)
#define CSL_MCAN_IES_EXT_TS_CNTR_OVFL_SHIFT                                    (0x00000000U)
#define CSL_MCAN_IES_EXT_TS_CNTR_OVFL_RESETVAL                                 (0x00000000U)
#define CSL_MCAN_IES_EXT_TS_CNTR_OVFL_MAX                                      (0x00000001U)

#define CSL_MCAN_IES_RESETVAL                                                  (0x00000000U)

/* EOI */

#define CSL_MCAN_EOI_EOI_MASK                                                  (0x000000FFU)
#define CSL_MCAN_EOI_EOI_SHIFT                                                 (0x00000000U)
#define CSL_MCAN_EOI_EOI_RESETVAL                                              (0x00000000U)
#define CSL_MCAN_EOI_EOI_MAX                                                   (0x000000FFU)

#define CSL_MCAN_EOI_RESETVAL                                                  (0x00000000U)

/* EXT_TS_PRESCALER */

#define CSL_MCAN_EXT_TS_PRESCALER_PRESCALER_MASK                               (0x00FFFFFFU)
#define CSL_MCAN_EXT_TS_PRESCALER_PRESCALER_SHIFT                              (0x00000000U)
#define CSL_MCAN_EXT_TS_PRESCALER_PRESCALER_RESETVAL                           (0x00000000U)
#define CSL_MCAN_EXT_TS_PRESCALER_PRESCALER_MAX                                (0x00FFFFFFU)

#define CSL_MCAN_EXT_TS_PRESCALER_RESETVAL                                     (0x00000000U)

/* EXT_TS_UNSERVICED_INTR_CNTR */

#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_MASK             (0x0000001FU)
#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_SHIFT            (0x00000000U)
#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_RESETVAL         (0x00000000U)
#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR_EXT_TS_INTR_CNTR_MAX              (0x0000001FU)

#define CSL_MCAN_EXT_TS_UNSERVICED_INTR_CNTR_RESETVAL                          (0x00000000U)

/**************************************************************************
* Hardware Region  : MCAN Core Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t CREL;                      /* Core Release Register */
    volatile uint32_t ENDN;                      /* Endian Register */
    volatile uint32_t CUST;                      /* Customer Register */
    volatile uint32_t DBTP;                      /* Data Bit Timing & Prescaler Register */
    volatile uint32_t TEST;                      /* Test Register */
    volatile uint32_t RWD;                       /* RAM Watchdog */
    volatile uint32_t CCCR;                      /* CC Control Register */
    volatile uint32_t NBTP;                      /* Nominal Bit Timing & Prescaler Register */
    volatile uint32_t TSCC;                      /* Timestamp Counter Configuration */
    volatile uint32_t TSCV;                      /* Timestamp Counter Value */
    volatile uint32_t TOCC;                      /* Timeout Counter Configuration */
    volatile uint32_t TOCV;                      /* Timeout Counter Value */
    volatile uint32_t RESERVED00;                /* Reserved */
    volatile uint32_t RESERVED11;                /* Reserved */
    volatile uint32_t RESERVED22;                /* Reserved */
    volatile uint32_t RESERVED33;                /* Reserved */
    volatile uint32_t ECR;                       /* Error Counter Register */
    volatile uint32_t PSR;                       /* Protocol Status Register */
    volatile uint32_t TDCR;                      /* Transmitter Delay Comensation Register */
    volatile uint32_t RESERVED44;                /* Reserved */
    volatile uint32_t IR;                        /* Interrupt Register */
    volatile uint32_t IE;                        /* Interrupt Enable */
    volatile uint32_t ILS;                       /* Interrupt Line Select */
    volatile uint32_t ILE;                       /* Interrupt Line Enable */
    volatile uint32_t RESERVED55;                /* Reserved */
    volatile uint32_t RESERVED66;                /* Reserved */
    volatile uint32_t RESERVED77;                /* Reserved */
    volatile uint32_t RESERVED88;                /* Reserved */
    volatile uint32_t RESERVED99;                /* Reserved */
    volatile uint32_t RESERVED1010;              /* Reserved */
    volatile uint32_t RESERVED1111;              /* Reserved */
    volatile uint32_t RESERVED1212;              /* Reserved */
    volatile uint32_t GFC;                       /* Global Filter Configuration */
    volatile uint32_t SIDFC;                     /* Standard ID Filter Configuration */
    volatile uint32_t XIDFC;                     /* Extended ID Filter Configuration */
    volatile uint32_t RESERVED1313;              /* Reserved */
    volatile uint32_t XIDAM;                     /* Extended ID AND Mask */
    volatile uint32_t HPMS;                      /* High Priority Message Status */
    volatile uint32_t NDAT1;                     /* New Data 1 */
    volatile uint32_t NDAT2;                     /* New Data 2 */
    volatile uint32_t RXF0C;                     /* Rx FIFO 0 Configuration */
    volatile uint32_t RXF0S;                     /* Rx FIFO 0 Status */
    volatile uint32_t RXF0A;                     /* Rx FIFO 0 Acknowledge */
    volatile uint32_t RXBC;                      /* Rx Buffer Configuration */
    volatile uint32_t RXF1C;                     /* Rx FIFO 1 Configuration */
    volatile uint32_t RXF1S;                     /* Rx FIFO 1 Status */
    volatile uint32_t RXF1A;                     /* Rx FIFO 1 Acknowledge */
    volatile uint32_t RXESC;                     /* Rx Buffer / FIFO Element Size Configuration */
    volatile uint32_t TXBC;                      /* Tx Buffer Configuration */
    volatile uint32_t TXFQS;                     /* Tx FIFO/Queue Status */
    volatile uint32_t TXESC;                     /* Tx Buffer Element Size Configuration */
    volatile uint32_t TXBRP;                     /* Tx Buffer Request Pending */
    volatile uint32_t TXBAR;                     /* Tx Buffer Add Request */
    volatile uint32_t TXBCR;                     /* Tx Buffer Cancellation Request */
    volatile uint32_t TXBTO;                     /* Tx Buffer Transmission Occurred */
    volatile uint32_t TXBCF;                     /* Tx Buffer Cancellation Finished */
    volatile uint32_t TXBTIE;                    /* Tx Buffer Transmission Interrupt Enable */
    volatile uint32_t TXBCIE;                    /* Tx Buffer Cancellation Finished Interrupt Enable */
    volatile uint32_t RESERVED1414;              /* Reserved */
    volatile uint32_t RESERVED1515;              /* Reserved */
    volatile uint32_t TXEFC;                     /* Tx Event FIFO Configuration */
    volatile uint32_t TXEFS;                     /* Tx Event FIFO Status */
    volatile uint32_t TXEFA;                     /* Tx Event FIFO Acknowledge */
    volatile uint32_t RESERVED1616;              /* Reserved */
} CSL_mcan_coreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MCAN_CORE_CREL                                                     (0x00000000U)
#define CSL_MCAN_CORE_ENDN                                                     (0x00000004U)
#define CSL_MCAN_CORE_CUST                                                     (0x00000008U)
#define CSL_MCAN_CORE_DBTP                                                     (0x0000000CU)
#define CSL_MCAN_CORE_TEST                                                     (0x00000010U)
#define CSL_MCAN_CORE_RWD                                                      (0x00000014U)
#define CSL_MCAN_CORE_CCCR                                                     (0x00000018U)
#define CSL_MCAN_CORE_NBTP                                                     (0x0000001CU)
#define CSL_MCAN_CORE_TSCC                                                     (0x00000020U)
#define CSL_MCAN_CORE_TSCV                                                     (0x00000024U)
#define CSL_MCAN_CORE_TOCC                                                     (0x00000028U)
#define CSL_MCAN_CORE_TOCV                                                     (0x0000002CU)
#define CSL_MCAN_CORE_RESERVED00                                               (0x00000030U)
#define CSL_MCAN_CORE_RESERVED11                                               (0x00000034U)
#define CSL_MCAN_CORE_RESERVED22                                               (0x00000038U)
#define CSL_MCAN_CORE_RESERVED33                                               (0x0000003CU)
#define CSL_MCAN_CORE_ECR                                                      (0x00000040U)
#define CSL_MCAN_CORE_PSR                                                      (0x00000044U)
#define CSL_MCAN_CORE_TDCR                                                     (0x00000048U)
#define CSL_MCAN_CORE_RESERVED44                                               (0x0000004CU)
#define CSL_MCAN_CORE_IR                                                       (0x00000050U)
#define CSL_MCAN_CORE_IE                                                       (0x00000054U)
#define CSL_MCAN_CORE_ILS                                                      (0x00000058U)
#define CSL_MCAN_CORE_ILE                                                      (0x0000005CU)
#define CSL_MCAN_CORE_RESERVED55                                               (0x00000060U)
#define CSL_MCAN_CORE_RESERVED66                                               (0x00000064U)
#define CSL_MCAN_CORE_RESERVED77                                               (0x00000068U)
#define CSL_MCAN_CORE_RESERVED88                                               (0x0000006CU)
#define CSL_MCAN_CORE_RESERVED99                                               (0x00000070U)
#define CSL_MCAN_CORE_RESERVED1010                                             (0x00000074U)
#define CSL_MCAN_CORE_RESERVED1111                                             (0x00000078U)
#define CSL_MCAN_CORE_RESERVED1212                                             (0x0000007CU)
#define CSL_MCAN_CORE_GFC                                                      (0x00000080U)
#define CSL_MCAN_CORE_SIDFC                                                    (0x00000084U)
#define CSL_MCAN_CORE_XIDFC                                                    (0x00000088U)
#define CSL_MCAN_CORE_RESERVED1313                                             (0x0000008CU)
#define CSL_MCAN_CORE_XIDAM                                                    (0x00000090U)
#define CSL_MCAN_CORE_HPMS                                                     (0x00000094U)
#define CSL_MCAN_CORE_NDAT1                                                    (0x00000098U)
#define CSL_MCAN_CORE_NDAT2                                                    (0x0000009CU)
#define CSL_MCAN_CORE_RXF0C                                                    (0x000000A0U)
#define CSL_MCAN_CORE_RXF0S                                                    (0x000000A4U)
#define CSL_MCAN_CORE_RXF0A                                                    (0x000000A8U)
#define CSL_MCAN_CORE_RXBC                                                     (0x000000ACU)
#define CSL_MCAN_CORE_RXF1C                                                    (0x000000B0U)
#define CSL_MCAN_CORE_RXF1S                                                    (0x000000B4U)
#define CSL_MCAN_CORE_RXF1A                                                    (0x000000B8U)
#define CSL_MCAN_CORE_RXESC                                                    (0x000000BCU)
#define CSL_MCAN_CORE_TXBC                                                     (0x000000C0U)
#define CSL_MCAN_CORE_TXFQS                                                    (0x000000C4U)
#define CSL_MCAN_CORE_TXESC                                                    (0x000000C8U)
#define CSL_MCAN_CORE_TXBRP                                                    (0x000000CCU)
#define CSL_MCAN_CORE_TXBAR                                                    (0x000000D0U)
#define CSL_MCAN_CORE_TXBCR                                                    (0x000000D4U)
#define CSL_MCAN_CORE_TXBTO                                                    (0x000000D8U)
#define CSL_MCAN_CORE_TXBCF                                                    (0x000000DCU)
#define CSL_MCAN_CORE_TXBTIE                                                   (0x000000E0U)
#define CSL_MCAN_CORE_TXBCIE                                                   (0x000000E4U)
#define CSL_MCAN_CORE_RESERVED1414                                             (0x000000E8U)
#define CSL_MCAN_CORE_RESERVED1515                                             (0x000000ECU)
#define CSL_MCAN_CORE_TXEFC                                                    (0x000000F0U)
#define CSL_MCAN_CORE_TXEFS                                                    (0x000000F4U)
#define CSL_MCAN_CORE_TXEFA                                                    (0x000000F8U)
#define CSL_MCAN_CORE_RESERVED1616                                             (0x000000FCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CREL */

#define CSL_MCAN_CORE_CREL_DAY_MASK                                            (0x000000FFU)
#define CSL_MCAN_CORE_CREL_DAY_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_CREL_DAY_RESETVAL                                        (0x00000020U)
#define CSL_MCAN_CORE_CREL_DAY_MAX                                             (0x000000FFU)

#define CSL_MCAN_CORE_CREL_MON_MASK                                            (0x0000FF00U)
#define CSL_MCAN_CORE_CREL_MON_SHIFT                                           (0x00000008U)
#define CSL_MCAN_CORE_CREL_MON_RESETVAL                                        (0x00000003U)
#define CSL_MCAN_CORE_CREL_MON_MAX                                             (0x000000FFU)

#define CSL_MCAN_CORE_CREL_YEAR_MASK                                           (0x000F0000U)
#define CSL_MCAN_CORE_CREL_YEAR_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_CREL_YEAR_RESETVAL                                       (0x00000005U)
#define CSL_MCAN_CORE_CREL_YEAR_MAX                                            (0x0000000FU)

#define CSL_MCAN_CORE_CREL_SUBSTEP_MASK                                        (0x00F00000U)
#define CSL_MCAN_CORE_CREL_SUBSTEP_SHIFT                                       (0x00000014U)
#define CSL_MCAN_CORE_CREL_SUBSTEP_RESETVAL                                    (0x00000001U)
#define CSL_MCAN_CORE_CREL_SUBSTEP_MAX                                         (0x0000000FU)

#define CSL_MCAN_CORE_CREL_STEP_MASK                                           (0x0F000000U)
#define CSL_MCAN_CORE_CREL_STEP_SHIFT                                          (0x00000018U)
#define CSL_MCAN_CORE_CREL_STEP_RESETVAL                                       (0x00000002U)
#define CSL_MCAN_CORE_CREL_STEP_MAX                                            (0x0000000FU)

#define CSL_MCAN_CORE_CREL_REL_MASK                                            (0xF0000000U)
#define CSL_MCAN_CORE_CREL_REL_SHIFT                                           (0x0000001CU)
#define CSL_MCAN_CORE_CREL_REL_RESETVAL                                        (0x00000003U)
#define CSL_MCAN_CORE_CREL_REL_MAX                                             (0x0000000FU)

#define CSL_MCAN_CORE_CREL_RESETVAL                                            (0x32150320U)

/* ENDN */

#define CSL_MCAN_CORE_ENDN_ETV_MASK                                            (0xFFFFFFFFU)
#define CSL_MCAN_CORE_ENDN_ETV_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_ENDN_ETV_RESETVAL                                        (0x87654321U)
#define CSL_MCAN_CORE_ENDN_ETV_MAX                                             (0xFFFFFFFFU)

#define CSL_MCAN_CORE_ENDN_RESETVAL                                            (0x87654321U)

/* CUST */

#define CSL_MCAN_CORE_CUST_RESETVAL                                            (0x00000000U)

/* DBTP */

#define CSL_MCAN_CORE_DBTP_DSJW_MASK                                           (0x0000000FU)
#define CSL_MCAN_CORE_DBTP_DSJW_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_DBTP_DSJW_RESETVAL                                       (0x00000003U)
#define CSL_MCAN_CORE_DBTP_DSJW_MAX                                            (0x0000000FU)

#define CSL_MCAN_CORE_DBTP_DTSEG2_MASK                                         (0x000000F0U)
#define CSL_MCAN_CORE_DBTP_DTSEG2_SHIFT                                        (0x00000004U)
#define CSL_MCAN_CORE_DBTP_DTSEG2_RESETVAL                                     (0x00000003U)
#define CSL_MCAN_CORE_DBTP_DTSEG2_MAX                                          (0x0000000FU)

#define CSL_MCAN_CORE_DBTP_DTSEG1_MASK                                         (0x00001F00U)
#define CSL_MCAN_CORE_DBTP_DTSEG1_SHIFT                                        (0x00000008U)
#define CSL_MCAN_CORE_DBTP_DTSEG1_RESETVAL                                     (0x0000000AU)
#define CSL_MCAN_CORE_DBTP_DTSEG1_MAX                                          (0x0000001FU)

#define CSL_MCAN_CORE_DBTP_DBRP_MASK                                           (0x001F0000U)
#define CSL_MCAN_CORE_DBTP_DBRP_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_DBTP_DBRP_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_DBTP_DBRP_MAX                                            (0x0000001FU)

#define CSL_MCAN_CORE_DBTP_TDC_MASK                                            (0x00800000U)
#define CSL_MCAN_CORE_DBTP_TDC_SHIFT                                           (0x00000017U)
#define CSL_MCAN_CORE_DBTP_TDC_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_DBTP_TDC_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_DBTP_RESETVAL                                            (0x00000A33U)

/* TEST */

#define CSL_MCAN_CORE_TEST_LBCK_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_TEST_LBCK_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_TEST_LBCK_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TEST_LBCK_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TEST_TX_MASK                                             (0x00000060U)
#define CSL_MCAN_CORE_TEST_TX_SHIFT                                            (0x00000005U)
#define CSL_MCAN_CORE_TEST_TX_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_TEST_TX_MAX                                              (0x00000003U)

#define CSL_MCAN_CORE_TEST_RX_MASK                                             (0x00000080U)
#define CSL_MCAN_CORE_TEST_RX_SHIFT                                            (0x00000007U)
#define CSL_MCAN_CORE_TEST_RX_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_TEST_RX_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_TEST_RESETVAL                                            (0x00000000U)

/* RWD */

#define CSL_MCAN_CORE_RWD_WDC_MASK                                             (0x000000FFU)
#define CSL_MCAN_CORE_RWD_WDC_SHIFT                                            (0x00000000U)
#define CSL_MCAN_CORE_RWD_WDC_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_RWD_WDC_MAX                                              (0x000000FFU)

#define CSL_MCAN_CORE_RWD_WDV_MASK                                             (0x0000FF00U)
#define CSL_MCAN_CORE_RWD_WDV_SHIFT                                            (0x00000008U)
#define CSL_MCAN_CORE_RWD_WDV_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_RWD_WDV_MAX                                              (0x000000FFU)

#define CSL_MCAN_CORE_RWD_RESETVAL                                             (0x00000000U)

/* CCCR */

#define CSL_MCAN_CORE_CCCR_INIT_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_CCCR_INIT_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_CCCR_INIT_RESETVAL                                       (0x00000001U)
#define CSL_MCAN_CORE_CCCR_INIT_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_CCE_MASK                                            (0x00000002U)
#define CSL_MCAN_CORE_CCCR_CCE_SHIFT                                           (0x00000001U)
#define CSL_MCAN_CORE_CCCR_CCE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_CCE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_ASM_MASK                                            (0x00000004U)
#define CSL_MCAN_CORE_CCCR_ASM_SHIFT                                           (0x00000002U)
#define CSL_MCAN_CORE_CCCR_ASM_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_ASM_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_CSA_MASK                                            (0x00000008U)
#define CSL_MCAN_CORE_CCCR_CSA_SHIFT                                           (0x00000003U)
#define CSL_MCAN_CORE_CCCR_CSA_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_CSA_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_CSR_MASK                                            (0x00000010U)
#define CSL_MCAN_CORE_CCCR_CSR_SHIFT                                           (0x00000004U)
#define CSL_MCAN_CORE_CCCR_CSR_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_CSR_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_MON_MASK                                            (0x00000020U)
#define CSL_MCAN_CORE_CCCR_MON_SHIFT                                           (0x00000005U)
#define CSL_MCAN_CORE_CCCR_MON_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_MON_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_DAR_MASK                                            (0x00000040U)
#define CSL_MCAN_CORE_CCCR_DAR_SHIFT                                           (0x00000006U)
#define CSL_MCAN_CORE_CCCR_DAR_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_DAR_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_TEST_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_CCCR_TEST_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_CCCR_TEST_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_CCCR_TEST_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_FDOE_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_CCCR_FDOE_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_CCCR_FDOE_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_CCCR_FDOE_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_BRSE_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_CCCR_BRSE_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_CCCR_BRSE_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_CCCR_BRSE_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_PXHD_MASK                                           (0x00001000U)
#define CSL_MCAN_CORE_CCCR_PXHD_SHIFT                                          (0x0000000CU)
#define CSL_MCAN_CORE_CCCR_PXHD_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_CCCR_PXHD_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_EFBI_MASK                                           (0x00002000U)
#define CSL_MCAN_CORE_CCCR_EFBI_SHIFT                                          (0x0000000DU)
#define CSL_MCAN_CORE_CCCR_EFBI_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_CCCR_EFBI_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_CCCR_TXP_MASK                                            (0x00004000U)
#define CSL_MCAN_CORE_CCCR_TXP_SHIFT                                           (0x0000000EU)
#define CSL_MCAN_CORE_CCCR_TXP_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_CCCR_TXP_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_CCCR_RESETVAL                                            (0x00000001U)

/* NBTP */

#define CSL_MCAN_CORE_NBTP_NTSEG2_MASK                                         (0x0000007FU)
#define CSL_MCAN_CORE_NBTP_NTSEG2_SHIFT                                        (0x00000000U)
#define CSL_MCAN_CORE_NBTP_NTSEG2_RESETVAL                                     (0x00000003U)
#define CSL_MCAN_CORE_NBTP_NTSEG2_MAX                                          (0x0000007FU)

#define CSL_MCAN_CORE_NBTP_NTSEG1_MASK                                         (0x0000FF00U)
#define CSL_MCAN_CORE_NBTP_NTSEG1_SHIFT                                        (0x00000008U)
#define CSL_MCAN_CORE_NBTP_NTSEG1_RESETVAL                                     (0x0000000AU)
#define CSL_MCAN_CORE_NBTP_NTSEG1_MAX                                          (0x000000FFU)

#define CSL_MCAN_CORE_NBTP_NBRP_MASK                                           (0x01FF0000U)
#define CSL_MCAN_CORE_NBTP_NBRP_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_NBTP_NBRP_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NBTP_NBRP_MAX                                            (0x000001FFU)

#define CSL_MCAN_CORE_NBTP_NSJW_MASK                                           (0xFE000000U)
#define CSL_MCAN_CORE_NBTP_NSJW_SHIFT                                          (0x00000019U)
#define CSL_MCAN_CORE_NBTP_NSJW_RESETVAL                                       (0x00000003U)
#define CSL_MCAN_CORE_NBTP_NSJW_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_NBTP_RESETVAL                                            (0x06000A03U)

/* TSCC */

#define CSL_MCAN_CORE_TSCC_TSS_MASK                                            (0x00000003U)
#define CSL_MCAN_CORE_TSCC_TSS_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_TSCC_TSS_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_TSCC_TSS_MAX                                             (0x00000003U)

#define CSL_MCAN_CORE_TSCC_TCP_MASK                                            (0x000F0000U)
#define CSL_MCAN_CORE_TSCC_TCP_SHIFT                                           (0x00000010U)
#define CSL_MCAN_CORE_TSCC_TCP_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_TSCC_TCP_MAX                                             (0x0000000FU)

#define CSL_MCAN_CORE_TSCC_RESETVAL                                            (0x00000000U)

/* TSCV */

#define CSL_MCAN_CORE_TSCV_TSC_MASK                                            (0x0000FFFFU)
#define CSL_MCAN_CORE_TSCV_TSC_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_TSCV_TSC_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_TSCV_TSC_MAX                                             (0x0000FFFFU)

#define CSL_MCAN_CORE_TSCV_RESETVAL                                            (0x00000000U)

/* TOCC */

#define CSL_MCAN_CORE_TOCC_ETOC_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_TOCC_ETOC_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TOCC_ETOC_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TOCC_ETOC_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TOCC_TOS_MASK                                            (0x00000006U)
#define CSL_MCAN_CORE_TOCC_TOS_SHIFT                                           (0x00000001U)
#define CSL_MCAN_CORE_TOCC_TOS_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_TOCC_TOS_MAX                                             (0x00000003U)

#define CSL_MCAN_CORE_TOCC_TOP_MASK                                            (0xFFFF0000U)
#define CSL_MCAN_CORE_TOCC_TOP_SHIFT                                           (0x00000010U)
#define CSL_MCAN_CORE_TOCC_TOP_RESETVAL                                        (0x0000FFFFU)
#define CSL_MCAN_CORE_TOCC_TOP_MAX                                             (0x0000FFFFU)

#define CSL_MCAN_CORE_TOCC_RESETVAL                                            (0xFFFF0000U)

/* TOCV */

#define CSL_MCAN_CORE_TOCV_TOC_MASK                                            (0x0000FFFFU)
#define CSL_MCAN_CORE_TOCV_TOC_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_TOCV_TOC_RESETVAL                                        (0x0000FFFFU)
#define CSL_MCAN_CORE_TOCV_TOC_MAX                                             (0x0000FFFFU)

#define CSL_MCAN_CORE_TOCV_RESETVAL                                            (0x0000FFFFU)

/* RESERVED00 */

#define CSL_MCAN_CORE_RESERVED00_RESETVAL                                      (0x00000000U)

/* RESERVED11 */

#define CSL_MCAN_CORE_RESERVED11_RESETVAL                                      (0x00000000U)

/* RESERVED22 */

#define CSL_MCAN_CORE_RESERVED22_RESETVAL                                      (0x00000000U)

/* RESERVED33 */

#define CSL_MCAN_CORE_RESERVED33_RESETVAL                                      (0x00000000U)

/* ECR */

#define CSL_MCAN_CORE_ECR_TEC_MASK                                             (0x000000FFU)
#define CSL_MCAN_CORE_ECR_TEC_SHIFT                                            (0x00000000U)
#define CSL_MCAN_CORE_ECR_TEC_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ECR_TEC_MAX                                              (0x000000FFU)

#define CSL_MCAN_CORE_ECR_REC_MASK                                             (0x00007F00U)
#define CSL_MCAN_CORE_ECR_REC_SHIFT                                            (0x00000008U)
#define CSL_MCAN_CORE_ECR_REC_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ECR_REC_MAX                                              (0x0000007FU)

#define CSL_MCAN_CORE_ECR_RP_MASK                                              (0x00008000U)
#define CSL_MCAN_CORE_ECR_RP_SHIFT                                             (0x0000000FU)
#define CSL_MCAN_CORE_ECR_RP_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_ECR_RP_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_ECR_CEL_MASK                                             (0x00FF0000U)
#define CSL_MCAN_CORE_ECR_CEL_SHIFT                                            (0x00000010U)
#define CSL_MCAN_CORE_ECR_CEL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ECR_CEL_MAX                                              (0x000000FFU)

#define CSL_MCAN_CORE_ECR_RESETVAL                                             (0x00000000U)

/* PSR */

#define CSL_MCAN_CORE_PSR_LEC_MASK                                             (0x00000007U)
#define CSL_MCAN_CORE_PSR_LEC_SHIFT                                            (0x00000000U)
#define CSL_MCAN_CORE_PSR_LEC_RESETVAL                                         (0x00000007U)
#define CSL_MCAN_CORE_PSR_LEC_MAX                                              (0x00000007U)

#define CSL_MCAN_CORE_PSR_ACT_MASK                                             (0x00000018U)
#define CSL_MCAN_CORE_PSR_ACT_SHIFT                                            (0x00000003U)
#define CSL_MCAN_CORE_PSR_ACT_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_PSR_ACT_MAX                                              (0x00000003U)

#define CSL_MCAN_CORE_PSR_EP_MASK                                              (0x00000020U)
#define CSL_MCAN_CORE_PSR_EP_SHIFT                                             (0x00000005U)
#define CSL_MCAN_CORE_PSR_EP_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_PSR_EP_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_PSR_EW_MASK                                              (0x00000040U)
#define CSL_MCAN_CORE_PSR_EW_SHIFT                                             (0x00000006U)
#define CSL_MCAN_CORE_PSR_EW_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_PSR_EW_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_PSR_BO_MASK                                              (0x00000080U)
#define CSL_MCAN_CORE_PSR_BO_SHIFT                                             (0x00000007U)
#define CSL_MCAN_CORE_PSR_BO_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_PSR_BO_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_PSR_DLEC_MASK                                            (0x00000700U)
#define CSL_MCAN_CORE_PSR_DLEC_SHIFT                                           (0x00000008U)
#define CSL_MCAN_CORE_PSR_DLEC_RESETVAL                                        (0x00000007U)
#define CSL_MCAN_CORE_PSR_DLEC_MAX                                             (0x00000007U)

#define CSL_MCAN_CORE_PSR_RESI_MASK                                            (0x00000800U)
#define CSL_MCAN_CORE_PSR_RESI_SHIFT                                           (0x0000000BU)
#define CSL_MCAN_CORE_PSR_RESI_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_PSR_RESI_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_PSR_RBRS_MASK                                            (0x00001000U)
#define CSL_MCAN_CORE_PSR_RBRS_SHIFT                                           (0x0000000CU)
#define CSL_MCAN_CORE_PSR_RBRS_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_PSR_RBRS_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_PSR_RFDF_MASK                                            (0x00002000U)
#define CSL_MCAN_CORE_PSR_RFDF_SHIFT                                           (0x0000000DU)
#define CSL_MCAN_CORE_PSR_RFDF_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_PSR_RFDF_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_PSR_PXE_MASK                                             (0x00004000U)
#define CSL_MCAN_CORE_PSR_PXE_SHIFT                                            (0x0000000EU)
#define CSL_MCAN_CORE_PSR_PXE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_PSR_PXE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_PSR_TDCV_MASK                                            (0x007F0000U)
#define CSL_MCAN_CORE_PSR_TDCV_SHIFT                                           (0x00000010U)
#define CSL_MCAN_CORE_PSR_TDCV_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_PSR_TDCV_MAX                                             (0x0000007FU)

#define CSL_MCAN_CORE_PSR_RESETVAL                                             (0x00000707U)

/* TDCR */

#define CSL_MCAN_CORE_TDCR_TDCF_MASK                                           (0x0000007FU)
#define CSL_MCAN_CORE_TDCR_TDCF_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TDCR_TDCF_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TDCR_TDCF_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_TDCR_TDCO_MASK                                           (0x00007F00U)
#define CSL_MCAN_CORE_TDCR_TDCO_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_TDCR_TDCO_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TDCR_TDCO_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_TDCR_RESETVAL                                            (0x00000000U)

/* RESERVED44 */

#define CSL_MCAN_CORE_RESERVED44_RESETVAL                                      (0x00000000U)

/* IR */

#define CSL_MCAN_CORE_IR_RF0N_MASK                                             (0x00000001U)
#define CSL_MCAN_CORE_IR_RF0N_SHIFT                                            (0x00000000U)
#define CSL_MCAN_CORE_IR_RF0N_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF0N_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF0W_MASK                                             (0x00000002U)
#define CSL_MCAN_CORE_IR_RF0W_SHIFT                                            (0x00000001U)
#define CSL_MCAN_CORE_IR_RF0W_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF0W_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF0F_MASK                                             (0x00000004U)
#define CSL_MCAN_CORE_IR_RF0F_SHIFT                                            (0x00000002U)
#define CSL_MCAN_CORE_IR_RF0F_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF0F_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF0L_MASK                                             (0x00000008U)
#define CSL_MCAN_CORE_IR_RF0L_SHIFT                                            (0x00000003U)
#define CSL_MCAN_CORE_IR_RF0L_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF0L_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF1N_MASK                                             (0x00000010U)
#define CSL_MCAN_CORE_IR_RF1N_SHIFT                                            (0x00000004U)
#define CSL_MCAN_CORE_IR_RF1N_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF1N_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF1W_MASK                                             (0x00000020U)
#define CSL_MCAN_CORE_IR_RF1W_SHIFT                                            (0x00000005U)
#define CSL_MCAN_CORE_IR_RF1W_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF1W_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF1F_MASK                                             (0x00000040U)
#define CSL_MCAN_CORE_IR_RF1F_SHIFT                                            (0x00000006U)
#define CSL_MCAN_CORE_IR_RF1F_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF1F_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_RF1L_MASK                                             (0x00000080U)
#define CSL_MCAN_CORE_IR_RF1L_SHIFT                                            (0x00000007U)
#define CSL_MCAN_CORE_IR_RF1L_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_RF1L_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_HPM_MASK                                              (0x00000100U)
#define CSL_MCAN_CORE_IR_HPM_SHIFT                                             (0x00000008U)
#define CSL_MCAN_CORE_IR_HPM_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_HPM_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_TC_MASK                                               (0x00000200U)
#define CSL_MCAN_CORE_IR_TC_SHIFT                                              (0x00000009U)
#define CSL_MCAN_CORE_IR_TC_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_CORE_IR_TC_MAX                                                (0x00000001U)

#define CSL_MCAN_CORE_IR_TCF_MASK                                              (0x00000400U)
#define CSL_MCAN_CORE_IR_TCF_SHIFT                                             (0x0000000AU)
#define CSL_MCAN_CORE_IR_TCF_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_TCF_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_TFE_MASK                                              (0x00000800U)
#define CSL_MCAN_CORE_IR_TFE_SHIFT                                             (0x0000000BU)
#define CSL_MCAN_CORE_IR_TFE_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_TFE_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_TEFN_MASK                                             (0x00001000U)
#define CSL_MCAN_CORE_IR_TEFN_SHIFT                                            (0x0000000CU)
#define CSL_MCAN_CORE_IR_TEFN_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_TEFN_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_TEFW_MASK                                             (0x00002000U)
#define CSL_MCAN_CORE_IR_TEFW_SHIFT                                            (0x0000000DU)
#define CSL_MCAN_CORE_IR_TEFW_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_TEFW_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_TEFF_MASK                                             (0x00004000U)
#define CSL_MCAN_CORE_IR_TEFF_SHIFT                                            (0x0000000EU)
#define CSL_MCAN_CORE_IR_TEFF_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_TEFF_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_TEFL_MASK                                             (0x00008000U)
#define CSL_MCAN_CORE_IR_TEFL_SHIFT                                            (0x0000000FU)
#define CSL_MCAN_CORE_IR_TEFL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_TEFL_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_TSW_MASK                                              (0x00010000U)
#define CSL_MCAN_CORE_IR_TSW_SHIFT                                             (0x00000010U)
#define CSL_MCAN_CORE_IR_TSW_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_TSW_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_MRAF_MASK                                             (0x00020000U)
#define CSL_MCAN_CORE_IR_MRAF_SHIFT                                            (0x00000011U)
#define CSL_MCAN_CORE_IR_MRAF_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IR_MRAF_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IR_TOO_MASK                                              (0x00040000U)
#define CSL_MCAN_CORE_IR_TOO_SHIFT                                             (0x00000012U)
#define CSL_MCAN_CORE_IR_TOO_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_TOO_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_DRX_MASK                                              (0x00080000U)
#define CSL_MCAN_CORE_IR_DRX_SHIFT                                             (0x00000013U)
#define CSL_MCAN_CORE_IR_DRX_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_DRX_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_BEC_MASK                                              (0x00100000U)
#define CSL_MCAN_CORE_IR_BEC_SHIFT                                             (0x00000014U)
#define CSL_MCAN_CORE_IR_BEC_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_BEC_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_BEU_MASK                                              (0x00200000U)
#define CSL_MCAN_CORE_IR_BEU_SHIFT                                             (0x00000015U)
#define CSL_MCAN_CORE_IR_BEU_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_BEU_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_ELO_MASK                                              (0x00400000U)
#define CSL_MCAN_CORE_IR_ELO_SHIFT                                             (0x00000016U)
#define CSL_MCAN_CORE_IR_ELO_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_ELO_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_EP_MASK                                               (0x00800000U)
#define CSL_MCAN_CORE_IR_EP_SHIFT                                              (0x00000017U)
#define CSL_MCAN_CORE_IR_EP_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_CORE_IR_EP_MAX                                                (0x00000001U)

#define CSL_MCAN_CORE_IR_EW_MASK                                               (0x01000000U)
#define CSL_MCAN_CORE_IR_EW_SHIFT                                              (0x00000018U)
#define CSL_MCAN_CORE_IR_EW_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_CORE_IR_EW_MAX                                                (0x00000001U)

#define CSL_MCAN_CORE_IR_BO_MASK                                               (0x02000000U)
#define CSL_MCAN_CORE_IR_BO_SHIFT                                              (0x00000019U)
#define CSL_MCAN_CORE_IR_BO_RESETVAL                                           (0x00000000U)
#define CSL_MCAN_CORE_IR_BO_MAX                                                (0x00000001U)

#define CSL_MCAN_CORE_IR_WDI_MASK                                              (0x04000000U)
#define CSL_MCAN_CORE_IR_WDI_SHIFT                                             (0x0000001AU)
#define CSL_MCAN_CORE_IR_WDI_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_WDI_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_PEA_MASK                                              (0x08000000U)
#define CSL_MCAN_CORE_IR_PEA_SHIFT                                             (0x0000001BU)
#define CSL_MCAN_CORE_IR_PEA_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_PEA_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_PED_MASK                                              (0x10000000U)
#define CSL_MCAN_CORE_IR_PED_SHIFT                                             (0x0000001CU)
#define CSL_MCAN_CORE_IR_PED_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_PED_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_ARA_MASK                                              (0x20000000U)
#define CSL_MCAN_CORE_IR_ARA_SHIFT                                             (0x0000001DU)
#define CSL_MCAN_CORE_IR_ARA_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IR_ARA_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IR_RESETVAL                                              (0x00000000U)

/* IE */

#define CSL_MCAN_CORE_IE_RF0NE_MASK                                            (0x00000001U)
#define CSL_MCAN_CORE_IE_RF0NE_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_IE_RF0NE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF0NE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF0WE_MASK                                            (0x00000002U)
#define CSL_MCAN_CORE_IE_RF0WE_SHIFT                                           (0x00000001U)
#define CSL_MCAN_CORE_IE_RF0WE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF0WE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF0FE_MASK                                            (0x00000004U)
#define CSL_MCAN_CORE_IE_RF0FE_SHIFT                                           (0x00000002U)
#define CSL_MCAN_CORE_IE_RF0FE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF0FE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF0LE_MASK                                            (0x00000008U)
#define CSL_MCAN_CORE_IE_RF0LE_SHIFT                                           (0x00000003U)
#define CSL_MCAN_CORE_IE_RF0LE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF0LE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF1NE_MASK                                            (0x00000010U)
#define CSL_MCAN_CORE_IE_RF1NE_SHIFT                                           (0x00000004U)
#define CSL_MCAN_CORE_IE_RF1NE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF1NE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF1WE_MASK                                            (0x00000020U)
#define CSL_MCAN_CORE_IE_RF1WE_SHIFT                                           (0x00000005U)
#define CSL_MCAN_CORE_IE_RF1WE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF1WE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF1FE_MASK                                            (0x00000040U)
#define CSL_MCAN_CORE_IE_RF1FE_SHIFT                                           (0x00000006U)
#define CSL_MCAN_CORE_IE_RF1FE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF1FE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_RF1LE_MASK                                            (0x00000080U)
#define CSL_MCAN_CORE_IE_RF1LE_SHIFT                                           (0x00000007U)
#define CSL_MCAN_CORE_IE_RF1LE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_RF1LE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_HPME_MASK                                             (0x00000100U)
#define CSL_MCAN_CORE_IE_HPME_SHIFT                                            (0x00000008U)
#define CSL_MCAN_CORE_IE_HPME_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_HPME_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_TCE_MASK                                              (0x00000200U)
#define CSL_MCAN_CORE_IE_TCE_SHIFT                                             (0x00000009U)
#define CSL_MCAN_CORE_IE_TCE_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IE_TCE_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IE_TCFE_MASK                                             (0x00000400U)
#define CSL_MCAN_CORE_IE_TCFE_SHIFT                                            (0x0000000AU)
#define CSL_MCAN_CORE_IE_TCFE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_TCFE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_TFEE_MASK                                             (0x00000800U)
#define CSL_MCAN_CORE_IE_TFEE_SHIFT                                            (0x0000000BU)
#define CSL_MCAN_CORE_IE_TFEE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_TFEE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_TEFNE_MASK                                            (0x00001000U)
#define CSL_MCAN_CORE_IE_TEFNE_SHIFT                                           (0x0000000CU)
#define CSL_MCAN_CORE_IE_TEFNE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_TEFNE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_TEFWE_MASK                                            (0x00002000U)
#define CSL_MCAN_CORE_IE_TEFWE_SHIFT                                           (0x0000000DU)
#define CSL_MCAN_CORE_IE_TEFWE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_TEFWE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_TEFFE_MASK                                            (0x00004000U)
#define CSL_MCAN_CORE_IE_TEFFE_SHIFT                                           (0x0000000EU)
#define CSL_MCAN_CORE_IE_TEFFE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_TEFFE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_TEFLE_MASK                                            (0x00008000U)
#define CSL_MCAN_CORE_IE_TEFLE_SHIFT                                           (0x0000000FU)
#define CSL_MCAN_CORE_IE_TEFLE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_TEFLE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_TSWE_MASK                                             (0x00010000U)
#define CSL_MCAN_CORE_IE_TSWE_SHIFT                                            (0x00000010U)
#define CSL_MCAN_CORE_IE_TSWE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_TSWE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_MRAFE_MASK                                            (0x00020000U)
#define CSL_MCAN_CORE_IE_MRAFE_SHIFT                                           (0x00000011U)
#define CSL_MCAN_CORE_IE_MRAFE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_IE_MRAFE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_IE_TOOE_MASK                                             (0x00040000U)
#define CSL_MCAN_CORE_IE_TOOE_SHIFT                                            (0x00000012U)
#define CSL_MCAN_CORE_IE_TOOE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_TOOE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_DRX_MASK                                              (0x00080000U)
#define CSL_MCAN_CORE_IE_DRX_SHIFT                                             (0x00000013U)
#define CSL_MCAN_CORE_IE_DRX_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IE_DRX_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IE_BECE_MASK                                             (0x00100000U)
#define CSL_MCAN_CORE_IE_BECE_SHIFT                                            (0x00000014U)
#define CSL_MCAN_CORE_IE_BECE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_BECE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_BEUE_MASK                                             (0x00200000U)
#define CSL_MCAN_CORE_IE_BEUE_SHIFT                                            (0x00000015U)
#define CSL_MCAN_CORE_IE_BEUE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_BEUE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_ELOE_MASK                                             (0x00400000U)
#define CSL_MCAN_CORE_IE_ELOE_SHIFT                                            (0x00000016U)
#define CSL_MCAN_CORE_IE_ELOE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_ELOE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_EPE_MASK                                              (0x00800000U)
#define CSL_MCAN_CORE_IE_EPE_SHIFT                                             (0x00000017U)
#define CSL_MCAN_CORE_IE_EPE_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IE_EPE_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IE_EWE_MASK                                              (0x01000000U)
#define CSL_MCAN_CORE_IE_EWE_SHIFT                                             (0x00000018U)
#define CSL_MCAN_CORE_IE_EWE_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IE_EWE_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IE_BOE_MASK                                              (0x02000000U)
#define CSL_MCAN_CORE_IE_BOE_SHIFT                                             (0x00000019U)
#define CSL_MCAN_CORE_IE_BOE_RESETVAL                                          (0x00000000U)
#define CSL_MCAN_CORE_IE_BOE_MAX                                               (0x00000001U)

#define CSL_MCAN_CORE_IE_WDIE_MASK                                             (0x04000000U)
#define CSL_MCAN_CORE_IE_WDIE_SHIFT                                            (0x0000001AU)
#define CSL_MCAN_CORE_IE_WDIE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_WDIE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_PEAE_MASK                                             (0x08000000U)
#define CSL_MCAN_CORE_IE_PEAE_SHIFT                                            (0x0000001BU)
#define CSL_MCAN_CORE_IE_PEAE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_PEAE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_PEDE_MASK                                             (0x10000000U)
#define CSL_MCAN_CORE_IE_PEDE_SHIFT                                            (0x0000001CU)
#define CSL_MCAN_CORE_IE_PEDE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_PEDE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_ARAE_MASK                                             (0x20000000U)
#define CSL_MCAN_CORE_IE_ARAE_SHIFT                                            (0x0000001DU)
#define CSL_MCAN_CORE_IE_ARAE_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_IE_ARAE_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_IE_RESETVAL                                              (0x00000000U)

/* ILS */

#define CSL_MCAN_CORE_ILS_RF0NL_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_ILS_RF0NL_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF0NL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF0NL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF0WL_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_ILS_RF0WL_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_ILS_RF0WL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF0WL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF0FL_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_ILS_RF0FL_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_ILS_RF0FL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF0FL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF0LL_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_ILS_RF0LL_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_ILS_RF0LL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF0LL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF1NL_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_ILS_RF1NL_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_ILS_RF1NL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF1NL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF1WL_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_ILS_RF1WL_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_ILS_RF1WL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF1WL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF1FL_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_ILS_RF1FL_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_ILS_RF1FL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF1FL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_RF1LL_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_ILS_RF1LL_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_ILS_RF1LL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_RF1LL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_HPML_MASK                                            (0x00000100U)
#define CSL_MCAN_CORE_ILS_HPML_SHIFT                                           (0x00000008U)
#define CSL_MCAN_CORE_ILS_HPML_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_HPML_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_TCL_MASK                                             (0x00000200U)
#define CSL_MCAN_CORE_ILS_TCL_SHIFT                                            (0x00000009U)
#define CSL_MCAN_CORE_ILS_TCL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ILS_TCL_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_ILS_TCFL_MASK                                            (0x00000400U)
#define CSL_MCAN_CORE_ILS_TCFL_SHIFT                                           (0x0000000AU)
#define CSL_MCAN_CORE_ILS_TCFL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_TCFL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_TFEL_MASK                                            (0x00000800U)
#define CSL_MCAN_CORE_ILS_TFEL_SHIFT                                           (0x0000000BU)
#define CSL_MCAN_CORE_ILS_TFEL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_TFEL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_TEFNL_MASK                                           (0x00001000U)
#define CSL_MCAN_CORE_ILS_TEFNL_SHIFT                                          (0x0000000CU)
#define CSL_MCAN_CORE_ILS_TEFNL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_TEFNL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_TEFWL_MASK                                           (0x00002000U)
#define CSL_MCAN_CORE_ILS_TEFWL_SHIFT                                          (0x0000000DU)
#define CSL_MCAN_CORE_ILS_TEFWL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_TEFWL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_TEFFL_MASK                                           (0x00004000U)
#define CSL_MCAN_CORE_ILS_TEFFL_SHIFT                                          (0x0000000EU)
#define CSL_MCAN_CORE_ILS_TEFFL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_TEFFL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_TEFLL_MASK                                           (0x00008000U)
#define CSL_MCAN_CORE_ILS_TEFLL_SHIFT                                          (0x0000000FU)
#define CSL_MCAN_CORE_ILS_TEFLL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_TEFLL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_TSWL_MASK                                            (0x00010000U)
#define CSL_MCAN_CORE_ILS_TSWL_SHIFT                                           (0x00000010U)
#define CSL_MCAN_CORE_ILS_TSWL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_TSWL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_MRAFL_MASK                                           (0x00020000U)
#define CSL_MCAN_CORE_ILS_MRAFL_SHIFT                                          (0x00000011U)
#define CSL_MCAN_CORE_ILS_MRAFL_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILS_MRAFL_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILS_TOOL_MASK                                            (0x00040000U)
#define CSL_MCAN_CORE_ILS_TOOL_SHIFT                                           (0x00000012U)
#define CSL_MCAN_CORE_ILS_TOOL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_TOOL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_DRXL_MASK                                            (0x00080000U)
#define CSL_MCAN_CORE_ILS_DRXL_SHIFT                                           (0x00000013U)
#define CSL_MCAN_CORE_ILS_DRXL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_DRXL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_BECL_MASK                                            (0x00100000U)
#define CSL_MCAN_CORE_ILS_BECL_SHIFT                                           (0x00000014U)
#define CSL_MCAN_CORE_ILS_BECL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_BECL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_BEUL_MASK                                            (0x00200000U)
#define CSL_MCAN_CORE_ILS_BEUL_SHIFT                                           (0x00000015U)
#define CSL_MCAN_CORE_ILS_BEUL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_BEUL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_ELOL_MASK                                            (0x00400000U)
#define CSL_MCAN_CORE_ILS_ELOL_SHIFT                                           (0x00000016U)
#define CSL_MCAN_CORE_ILS_ELOL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_ELOL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_EPL_MASK                                             (0x00800000U)
#define CSL_MCAN_CORE_ILS_EPL_SHIFT                                            (0x00000017U)
#define CSL_MCAN_CORE_ILS_EPL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ILS_EPL_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_ILS_EWL_MASK                                             (0x01000000U)
#define CSL_MCAN_CORE_ILS_EWL_SHIFT                                            (0x00000018U)
#define CSL_MCAN_CORE_ILS_EWL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ILS_EWL_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_ILS_BOL_MASK                                             (0x02000000U)
#define CSL_MCAN_CORE_ILS_BOL_SHIFT                                            (0x00000019U)
#define CSL_MCAN_CORE_ILS_BOL_RESETVAL                                         (0x00000000U)
#define CSL_MCAN_CORE_ILS_BOL_MAX                                              (0x00000001U)

#define CSL_MCAN_CORE_ILS_WDIL_MASK                                            (0x04000000U)
#define CSL_MCAN_CORE_ILS_WDIL_SHIFT                                           (0x0000001AU)
#define CSL_MCAN_CORE_ILS_WDIL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_WDIL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_PEAL_MASK                                            (0x08000000U)
#define CSL_MCAN_CORE_ILS_PEAL_SHIFT                                           (0x0000001BU)
#define CSL_MCAN_CORE_ILS_PEAL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_PEAL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_PEDL_MASK                                            (0x10000000U)
#define CSL_MCAN_CORE_ILS_PEDL_SHIFT                                           (0x0000001CU)
#define CSL_MCAN_CORE_ILS_PEDL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_PEDL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_ARAL_MASK                                            (0x20000000U)
#define CSL_MCAN_CORE_ILS_ARAL_SHIFT                                           (0x0000001DU)
#define CSL_MCAN_CORE_ILS_ARAL_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_ILS_ARAL_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_ILS_RESETVAL                                             (0x00000000U)

/* ILE */

#define CSL_MCAN_CORE_ILE_EINT0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_ILE_EINT0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_ILE_EINT0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILE_EINT0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILE_EINT1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_ILE_EINT1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_ILE_EINT1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_ILE_EINT1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_ILE_RESETVAL                                             (0x00000000U)

/* RESERVED55 */

#define CSL_MCAN_CORE_RESERVED55_RESETVAL                                      (0x00000000U)

/* RESERVED66 */

#define CSL_MCAN_CORE_RESERVED66_RESETVAL                                      (0x00000000U)

/* RESERVED77 */

#define CSL_MCAN_CORE_RESERVED77_RESETVAL                                      (0x00000000U)

/* RESERVED88 */

#define CSL_MCAN_CORE_RESERVED88_RESETVAL                                      (0x00000000U)

/* RESERVED99 */

#define CSL_MCAN_CORE_RESERVED99_RESETVAL                                      (0x00000000U)

/* RESERVED1010 */

#define CSL_MCAN_CORE_RESERVED1010_RESETVAL                                    (0x00000000U)

/* RESERVED1111 */

#define CSL_MCAN_CORE_RESERVED1111_RESETVAL                                    (0x00000000U)

/* RESERVED1212 */

#define CSL_MCAN_CORE_RESERVED1212_RESETVAL                                    (0x00000000U)

/* GFC */

#define CSL_MCAN_CORE_GFC_RRFE_MASK                                            (0x00000001U)
#define CSL_MCAN_CORE_GFC_RRFE_SHIFT                                           (0x00000000U)
#define CSL_MCAN_CORE_GFC_RRFE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_GFC_RRFE_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_GFC_RRFS_MASK                                            (0x00000002U)
#define CSL_MCAN_CORE_GFC_RRFS_SHIFT                                           (0x00000001U)
#define CSL_MCAN_CORE_GFC_RRFS_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_GFC_RRFS_MAX                                             (0x00000001U)

#define CSL_MCAN_CORE_GFC_ANFE_MASK                                            (0x0000000CU)
#define CSL_MCAN_CORE_GFC_ANFE_SHIFT                                           (0x00000002U)
#define CSL_MCAN_CORE_GFC_ANFE_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_GFC_ANFE_MAX                                             (0x00000003U)

#define CSL_MCAN_CORE_GFC_ANFS_MASK                                            (0x00000030U)
#define CSL_MCAN_CORE_GFC_ANFS_SHIFT                                           (0x00000004U)
#define CSL_MCAN_CORE_GFC_ANFS_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_GFC_ANFS_MAX                                             (0x00000003U)

#define CSL_MCAN_CORE_GFC_RESETVAL                                             (0x00000000U)

/* SIDFC */

#define CSL_MCAN_CORE_SIDFC_FLSSA_MASK                                         (0x0000FFFCU)
#define CSL_MCAN_CORE_SIDFC_FLSSA_SHIFT                                        (0x00000002U)
#define CSL_MCAN_CORE_SIDFC_FLSSA_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_SIDFC_FLSSA_MAX                                          (0x00003FFFU)

#define CSL_MCAN_CORE_SIDFC_LSS_MASK                                           (0x00FF0000U)
#define CSL_MCAN_CORE_SIDFC_LSS_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_SIDFC_LSS_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_SIDFC_LSS_MAX                                            (0x000000FFU)

#define CSL_MCAN_CORE_SIDFC_RESETVAL                                           (0x00000000U)

/* XIDFC */

#define CSL_MCAN_CORE_XIDFC_FLESA_MASK                                         (0x0000FFFCU)
#define CSL_MCAN_CORE_XIDFC_FLESA_SHIFT                                        (0x00000002U)
#define CSL_MCAN_CORE_XIDFC_FLESA_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_XIDFC_FLESA_MAX                                          (0x00003FFFU)

#define CSL_MCAN_CORE_XIDFC_LSE_MASK                                           (0x007F0000U)
#define CSL_MCAN_CORE_XIDFC_LSE_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_XIDFC_LSE_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_XIDFC_LSE_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_XIDFC_RESETVAL                                           (0x00000000U)

/* RESERVED1313 */

#define CSL_MCAN_CORE_RESERVED1313_RESETVAL                                    (0x00000000U)

/* XIDAM */

#define CSL_MCAN_CORE_XIDAM_EIDM_MASK                                          (0x1FFFFFFFU)
#define CSL_MCAN_CORE_XIDAM_EIDM_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_XIDAM_EIDM_RESETVAL                                      (0x1FFFFFFFU)
#define CSL_MCAN_CORE_XIDAM_EIDM_MAX                                           (0x1FFFFFFFU)

#define CSL_MCAN_CORE_XIDAM_RESETVAL                                           (0x1FFFFFFFU)

/* HPMS */

#define CSL_MCAN_CORE_HPMS_BIDX_MASK                                           (0x0000003FU)
#define CSL_MCAN_CORE_HPMS_BIDX_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_HPMS_BIDX_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_HPMS_BIDX_MAX                                            (0x0000003FU)

#define CSL_MCAN_CORE_HPMS_MSI_MASK                                            (0x000000C0U)
#define CSL_MCAN_CORE_HPMS_MSI_SHIFT                                           (0x00000006U)
#define CSL_MCAN_CORE_HPMS_MSI_RESETVAL                                        (0x00000000U)
#define CSL_MCAN_CORE_HPMS_MSI_MAX                                             (0x00000003U)

#define CSL_MCAN_CORE_HPMS_FIDX_MASK                                           (0x00007F00U)
#define CSL_MCAN_CORE_HPMS_FIDX_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_HPMS_FIDX_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_HPMS_FIDX_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_HPMS_FLST_MASK                                           (0x00008000U)
#define CSL_MCAN_CORE_HPMS_FLST_SHIFT                                          (0x0000000FU)
#define CSL_MCAN_CORE_HPMS_FLST_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_HPMS_FLST_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_HPMS_RESETVAL                                            (0x00000000U)

/* NDAT1 */

#define CSL_MCAN_CORE_NDAT1_ND0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_NDAT1_ND0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_NDAT1_ND1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_NDAT1_ND1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND2_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_NDAT1_ND2_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_NDAT1_ND2_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND2_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND3_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_NDAT1_ND3_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_NDAT1_ND3_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND3_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND4_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_NDAT1_ND4_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_NDAT1_ND4_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND4_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND5_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_NDAT1_ND5_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_NDAT1_ND5_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND5_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND6_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_NDAT1_ND6_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_NDAT1_ND6_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND6_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND7_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_NDAT1_ND7_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_NDAT1_ND7_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND7_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND8_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_NDAT1_ND8_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_NDAT1_ND8_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND8_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND9_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_NDAT1_ND9_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_NDAT1_ND9_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND9_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND10_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_NDAT1_ND10_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_NDAT1_ND10_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND10_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND11_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_NDAT1_ND11_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_NDAT1_ND11_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND11_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND12_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_NDAT1_ND12_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_NDAT1_ND12_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND12_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND13_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_NDAT1_ND13_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_NDAT1_ND13_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND13_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND14_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_NDAT1_ND14_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_NDAT1_ND14_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND14_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND15_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_NDAT1_ND15_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_NDAT1_ND15_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND15_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND16_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_NDAT1_ND16_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_NDAT1_ND16_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND16_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND17_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_NDAT1_ND17_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_NDAT1_ND17_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND17_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND18_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_NDAT1_ND18_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_NDAT1_ND18_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND18_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND19_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_NDAT1_ND19_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_NDAT1_ND19_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND19_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND20_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_NDAT1_ND20_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_NDAT1_ND20_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND20_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND21_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_NDAT1_ND21_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_NDAT1_ND21_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND21_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND22_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_NDAT1_ND22_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_NDAT1_ND22_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND22_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND23_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_NDAT1_ND23_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_NDAT1_ND23_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND23_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND24_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_NDAT1_ND24_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_NDAT1_ND24_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND24_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND25_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_NDAT1_ND25_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_NDAT1_ND25_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND25_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND26_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_NDAT1_ND26_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_NDAT1_ND26_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND26_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND27_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_NDAT1_ND27_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_NDAT1_ND27_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND27_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND28_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_NDAT1_ND28_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_NDAT1_ND28_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND28_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND29_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_NDAT1_ND29_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_NDAT1_ND29_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND29_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND30_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_NDAT1_ND30_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_NDAT1_ND30_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND30_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_ND31_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_NDAT1_ND31_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_NDAT1_ND31_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT1_ND31_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT1_RESETVAL                                           (0x00000000U)

/* NDAT2 */

#define CSL_MCAN_CORE_NDAT2_ND32_MASK                                          (0x00000001U)
#define CSL_MCAN_CORE_NDAT2_ND32_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND32_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND32_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND33_MASK                                          (0x00000002U)
#define CSL_MCAN_CORE_NDAT2_ND33_SHIFT                                         (0x00000001U)
#define CSL_MCAN_CORE_NDAT2_ND33_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND33_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND34_MASK                                          (0x00000004U)
#define CSL_MCAN_CORE_NDAT2_ND34_SHIFT                                         (0x00000002U)
#define CSL_MCAN_CORE_NDAT2_ND34_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND34_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND35_MASK                                          (0x00000008U)
#define CSL_MCAN_CORE_NDAT2_ND35_SHIFT                                         (0x00000003U)
#define CSL_MCAN_CORE_NDAT2_ND35_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND35_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND36_MASK                                          (0x00000010U)
#define CSL_MCAN_CORE_NDAT2_ND36_SHIFT                                         (0x00000004U)
#define CSL_MCAN_CORE_NDAT2_ND36_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND36_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND37_MASK                                          (0x00000020U)
#define CSL_MCAN_CORE_NDAT2_ND37_SHIFT                                         (0x00000005U)
#define CSL_MCAN_CORE_NDAT2_ND37_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND37_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND38_MASK                                          (0x00000040U)
#define CSL_MCAN_CORE_NDAT2_ND38_SHIFT                                         (0x00000006U)
#define CSL_MCAN_CORE_NDAT2_ND38_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND38_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND39_MASK                                          (0x00000080U)
#define CSL_MCAN_CORE_NDAT2_ND39_SHIFT                                         (0x00000007U)
#define CSL_MCAN_CORE_NDAT2_ND39_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND39_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND40_MASK                                          (0x00000100U)
#define CSL_MCAN_CORE_NDAT2_ND40_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_NDAT2_ND40_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND40_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND41_MASK                                          (0x00000200U)
#define CSL_MCAN_CORE_NDAT2_ND41_SHIFT                                         (0x00000009U)
#define CSL_MCAN_CORE_NDAT2_ND41_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND41_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND42_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_NDAT2_ND42_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_NDAT2_ND42_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND42_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND43_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_NDAT2_ND43_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_NDAT2_ND43_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND43_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND44_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_NDAT2_ND44_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_NDAT2_ND44_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND44_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND45_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_NDAT2_ND45_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_NDAT2_ND45_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND45_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND46_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_NDAT2_ND46_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_NDAT2_ND46_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND46_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND47_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_NDAT2_ND47_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_NDAT2_ND47_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND47_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND48_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_NDAT2_ND48_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_NDAT2_ND48_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND48_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND49_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_NDAT2_ND49_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_NDAT2_ND49_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND49_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND50_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_NDAT2_ND50_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_NDAT2_ND50_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND50_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND51_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_NDAT2_ND51_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_NDAT2_ND51_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND51_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND52_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_NDAT2_ND52_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_NDAT2_ND52_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND52_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND53_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_NDAT2_ND53_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_NDAT2_ND53_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND53_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND54_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_NDAT2_ND54_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_NDAT2_ND54_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND54_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND55_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_NDAT2_ND55_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_NDAT2_ND55_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND55_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND56_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_NDAT2_ND56_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_NDAT2_ND56_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND56_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND57_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_NDAT2_ND57_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_NDAT2_ND57_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND57_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND58_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_NDAT2_ND58_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_NDAT2_ND58_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND58_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND59_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_NDAT2_ND59_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_NDAT2_ND59_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND59_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND60_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_NDAT2_ND60_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_NDAT2_ND60_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND60_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND61_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_NDAT2_ND61_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_NDAT2_ND61_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND61_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND62_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_NDAT2_ND62_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_NDAT2_ND62_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND62_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_ND63_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_NDAT2_ND63_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_NDAT2_ND63_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_NDAT2_ND63_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_NDAT2_RESETVAL                                           (0x00000000U)

/* RXF0C */

#define CSL_MCAN_CORE_RXF0C_F0SA_MASK                                          (0x0000FFFCU)
#define CSL_MCAN_CORE_RXF0C_F0SA_SHIFT                                         (0x00000002U)
#define CSL_MCAN_CORE_RXF0C_F0SA_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0C_F0SA_MAX                                           (0x00003FFFU)

#define CSL_MCAN_CORE_RXF0C_F0S_MASK                                           (0x007F0000U)
#define CSL_MCAN_CORE_RXF0C_F0S_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_RXF0C_F0S_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXF0C_F0S_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_RXF0C_F0WM_MASK                                          (0x7F000000U)
#define CSL_MCAN_CORE_RXF0C_F0WM_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_RXF0C_F0WM_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0C_F0WM_MAX                                           (0x0000007FU)

#define CSL_MCAN_CORE_RXF0C_F0OM_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_RXF0C_F0OM_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_RXF0C_F0OM_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0C_F0OM_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_RXF0C_RESETVAL                                           (0x00000000U)

/* RXF0S */

#define CSL_MCAN_CORE_RXF0S_F0FL_MASK                                          (0x0000007FU)
#define CSL_MCAN_CORE_RXF0S_F0FL_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_F0FL_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_F0FL_MAX                                           (0x0000007FU)

#define CSL_MCAN_CORE_RXF0S_F0GI_MASK                                          (0x00003F00U)
#define CSL_MCAN_CORE_RXF0S_F0GI_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_RXF0S_F0GI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_F0GI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF0S_F0PI_MASK                                          (0x003F0000U)
#define CSL_MCAN_CORE_RXF0S_F0PI_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_RXF0S_F0PI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_F0PI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF0S_F0F_MASK                                           (0x01000000U)
#define CSL_MCAN_CORE_RXF0S_F0F_SHIFT                                          (0x00000018U)
#define CSL_MCAN_CORE_RXF0S_F0F_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_F0F_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_RXF0S_RF0L_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_RXF0S_RF0L_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_RXF0S_RF0L_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0S_RF0L_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_RXF0S_RESETVAL                                           (0x00000000U)

/* RXF0A */

#define CSL_MCAN_CORE_RXF0A_F0AI_MASK                                          (0x0000003FU)
#define CSL_MCAN_CORE_RXF0A_F0AI_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_RXF0A_F0AI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF0A_F0AI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF0A_RESETVAL                                           (0x00000000U)

/* RXBC */

#define CSL_MCAN_CORE_RXBC_RBSA_MASK                                           (0x0000FFFCU)
#define CSL_MCAN_CORE_RXBC_RBSA_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_RXBC_RBSA_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXBC_RBSA_MAX                                            (0x00003FFFU)

#define CSL_MCAN_CORE_RXBC_RESETVAL                                            (0x00000000U)

/* RXF1C */

#define CSL_MCAN_CORE_RXF1C_F1SA_MASK                                          (0x0000FFFCU)
#define CSL_MCAN_CORE_RXF1C_F1SA_SHIFT                                         (0x00000002U)
#define CSL_MCAN_CORE_RXF1C_F1SA_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1C_F1SA_MAX                                           (0x00003FFFU)

#define CSL_MCAN_CORE_RXF1C_F1S_MASK                                           (0x007F0000U)
#define CSL_MCAN_CORE_RXF1C_F1S_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_RXF1C_F1S_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXF1C_F1S_MAX                                            (0x0000007FU)

#define CSL_MCAN_CORE_RXF1C_F1WM_MASK                                          (0x7F000000U)
#define CSL_MCAN_CORE_RXF1C_F1WM_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_RXF1C_F1WM_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1C_F1WM_MAX                                           (0x0000007FU)

#define CSL_MCAN_CORE_RXF1C_F1OM_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_RXF1C_F1OM_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_RXF1C_F1OM_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1C_F1OM_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_RXF1C_RESETVAL                                           (0x00000000U)

/* RXF1S */

#define CSL_MCAN_CORE_RXF1S_F1FL_MASK                                          (0x0000007FU)
#define CSL_MCAN_CORE_RXF1S_F1FL_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_F1FL_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_F1FL_MAX                                           (0x0000007FU)

#define CSL_MCAN_CORE_RXF1S_F1GI_MASK                                          (0x00003F00U)
#define CSL_MCAN_CORE_RXF1S_F1GI_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_RXF1S_F1GI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_F1GI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF1S_F1PI_MASK                                          (0x003F0000U)
#define CSL_MCAN_CORE_RXF1S_F1PI_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_RXF1S_F1PI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_F1PI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF1S_F1F_MASK                                           (0x01000000U)
#define CSL_MCAN_CORE_RXF1S_F1F_SHIFT                                          (0x00000018U)
#define CSL_MCAN_CORE_RXF1S_F1F_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_F1F_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_RXF1S_RF1L_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_RXF1S_RF1L_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_RXF1S_RF1L_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_RF1L_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_RXF1S_DMS_MASK                                           (0xC0000000U)
#define CSL_MCAN_CORE_RXF1S_DMS_SHIFT                                          (0x0000001EU)
#define CSL_MCAN_CORE_RXF1S_DMS_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_RXF1S_DMS_MAX                                            (0x00000003U)

#define CSL_MCAN_CORE_RXF1S_RESETVAL                                           (0x00000000U)

/* RXF1A */

#define CSL_MCAN_CORE_RXF1A_F1AI_MASK                                          (0x0000003FU)
#define CSL_MCAN_CORE_RXF1A_F1AI_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_RXF1A_F1AI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXF1A_F1AI_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_RXF1A_RESETVAL                                           (0x00000000U)

/* RXESC */

#define CSL_MCAN_CORE_RXESC_F0DS_MASK                                          (0x00000007U)
#define CSL_MCAN_CORE_RXESC_F0DS_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_RXESC_F0DS_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXESC_F0DS_MAX                                           (0x00000007U)

#define CSL_MCAN_CORE_RXESC_F1DS_MASK                                          (0x00000070U)
#define CSL_MCAN_CORE_RXESC_F1DS_SHIFT                                         (0x00000004U)
#define CSL_MCAN_CORE_RXESC_F1DS_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXESC_F1DS_MAX                                           (0x00000007U)

#define CSL_MCAN_CORE_RXESC_RBDS_MASK                                          (0x00000700U)
#define CSL_MCAN_CORE_RXESC_RBDS_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_RXESC_RBDS_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_RXESC_RBDS_MAX                                           (0x00000007U)

#define CSL_MCAN_CORE_RXESC_RESETVAL                                           (0x00000000U)

/* TXBC */

#define CSL_MCAN_CORE_TXBC_TBSA_MASK                                           (0x0000FFFCU)
#define CSL_MCAN_CORE_TXBC_TBSA_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBC_TBSA_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBC_TBSA_MAX                                            (0x00003FFFU)

#define CSL_MCAN_CORE_TXBC_NDTB_MASK                                           (0x003F0000U)
#define CSL_MCAN_CORE_TXBC_NDTB_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_TXBC_NDTB_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBC_NDTB_MAX                                            (0x0000003FU)

#define CSL_MCAN_CORE_TXBC_TFQS_MASK                                           (0x3F000000U)
#define CSL_MCAN_CORE_TXBC_TFQS_SHIFT                                          (0x00000018U)
#define CSL_MCAN_CORE_TXBC_TFQS_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBC_TFQS_MAX                                            (0x0000003FU)

#define CSL_MCAN_CORE_TXBC_TFQM_MASK                                           (0x40000000U)
#define CSL_MCAN_CORE_TXBC_TFQM_SHIFT                                          (0x0000001EU)
#define CSL_MCAN_CORE_TXBC_TFQM_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBC_TFQM_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBC_RESETVAL                                            (0x00000000U)

/* TXFQS */

#define CSL_MCAN_CORE_TXFQS_TFFL_MASK                                          (0x0000003FU)
#define CSL_MCAN_CORE_TXFQS_TFFL_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_TXFQS_TFFL_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXFQS_TFFL_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_TXFQS_TFGI_MASK                                          (0x00001F00U)
#define CSL_MCAN_CORE_TXFQS_TFGI_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_TXFQS_TFGI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXFQS_TFGI_MAX                                           (0x0000001FU)

#define CSL_MCAN_CORE_TXFQS_TFQPI_MASK                                         (0x001F0000U)
#define CSL_MCAN_CORE_TXFQS_TFQPI_SHIFT                                        (0x00000010U)
#define CSL_MCAN_CORE_TXFQS_TFQPI_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXFQS_TFQPI_MAX                                          (0x0000001FU)

#define CSL_MCAN_CORE_TXFQS_TFQF_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_TXFQS_TFQF_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_TXFQS_TFQF_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXFQS_TFQF_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXFQS_RESETVAL                                           (0x00000000U)

/* TXESC */

#define CSL_MCAN_CORE_TXESC_TBDS_MASK                                          (0x00000007U)
#define CSL_MCAN_CORE_TXESC_TBDS_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_TXESC_TBDS_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXESC_TBDS_MAX                                           (0x00000007U)

#define CSL_MCAN_CORE_TXESC_RESETVAL                                           (0x00000000U)

/* TXBRP */

#define CSL_MCAN_CORE_TXBRP_TRP0_MASK                                          (0x00000001U)
#define CSL_MCAN_CORE_TXBRP_TRP0_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP0_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP0_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP1_MASK                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBRP_TRP1_SHIFT                                         (0x00000001U)
#define CSL_MCAN_CORE_TXBRP_TRP1_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP1_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP2_MASK                                          (0x00000004U)
#define CSL_MCAN_CORE_TXBRP_TRP2_SHIFT                                         (0x00000002U)
#define CSL_MCAN_CORE_TXBRP_TRP2_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP2_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP3_MASK                                          (0x00000008U)
#define CSL_MCAN_CORE_TXBRP_TRP3_SHIFT                                         (0x00000003U)
#define CSL_MCAN_CORE_TXBRP_TRP3_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP3_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP4_MASK                                          (0x00000010U)
#define CSL_MCAN_CORE_TXBRP_TRP4_SHIFT                                         (0x00000004U)
#define CSL_MCAN_CORE_TXBRP_TRP4_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP4_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP5_MASK                                          (0x00000020U)
#define CSL_MCAN_CORE_TXBRP_TRP5_SHIFT                                         (0x00000005U)
#define CSL_MCAN_CORE_TXBRP_TRP5_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP5_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP6_MASK                                          (0x00000040U)
#define CSL_MCAN_CORE_TXBRP_TRP6_SHIFT                                         (0x00000006U)
#define CSL_MCAN_CORE_TXBRP_TRP6_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP6_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP7_MASK                                          (0x00000080U)
#define CSL_MCAN_CORE_TXBRP_TRP7_SHIFT                                         (0x00000007U)
#define CSL_MCAN_CORE_TXBRP_TRP7_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP7_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP8_MASK                                          (0x00000100U)
#define CSL_MCAN_CORE_TXBRP_TRP8_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_TXBRP_TRP8_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP8_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP9_MASK                                          (0x00000200U)
#define CSL_MCAN_CORE_TXBRP_TRP9_SHIFT                                         (0x00000009U)
#define CSL_MCAN_CORE_TXBRP_TRP9_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP9_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP10_MASK                                         (0x00000400U)
#define CSL_MCAN_CORE_TXBRP_TRP10_SHIFT                                        (0x0000000AU)
#define CSL_MCAN_CORE_TXBRP_TRP10_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP10_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP11_MASK                                         (0x00000800U)
#define CSL_MCAN_CORE_TXBRP_TRP11_SHIFT                                        (0x0000000BU)
#define CSL_MCAN_CORE_TXBRP_TRP11_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP11_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP12_MASK                                         (0x00001000U)
#define CSL_MCAN_CORE_TXBRP_TRP12_SHIFT                                        (0x0000000CU)
#define CSL_MCAN_CORE_TXBRP_TRP12_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP12_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP13_MASK                                         (0x00002000U)
#define CSL_MCAN_CORE_TXBRP_TRP13_SHIFT                                        (0x0000000DU)
#define CSL_MCAN_CORE_TXBRP_TRP13_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP13_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP14_MASK                                         (0x00004000U)
#define CSL_MCAN_CORE_TXBRP_TRP14_SHIFT                                        (0x0000000EU)
#define CSL_MCAN_CORE_TXBRP_TRP14_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP14_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP15_MASK                                         (0x00008000U)
#define CSL_MCAN_CORE_TXBRP_TRP15_SHIFT                                        (0x0000000FU)
#define CSL_MCAN_CORE_TXBRP_TRP15_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP15_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP16_MASK                                         (0x00010000U)
#define CSL_MCAN_CORE_TXBRP_TRP16_SHIFT                                        (0x00000010U)
#define CSL_MCAN_CORE_TXBRP_TRP16_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP16_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP17_MASK                                         (0x00020000U)
#define CSL_MCAN_CORE_TXBRP_TRP17_SHIFT                                        (0x00000011U)
#define CSL_MCAN_CORE_TXBRP_TRP17_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP17_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP18_MASK                                         (0x00040000U)
#define CSL_MCAN_CORE_TXBRP_TRP18_SHIFT                                        (0x00000012U)
#define CSL_MCAN_CORE_TXBRP_TRP18_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP18_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP19_MASK                                         (0x00080000U)
#define CSL_MCAN_CORE_TXBRP_TRP19_SHIFT                                        (0x00000013U)
#define CSL_MCAN_CORE_TXBRP_TRP19_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP19_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP20_MASK                                         (0x00100000U)
#define CSL_MCAN_CORE_TXBRP_TRP20_SHIFT                                        (0x00000014U)
#define CSL_MCAN_CORE_TXBRP_TRP20_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP20_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP21_MASK                                         (0x00200000U)
#define CSL_MCAN_CORE_TXBRP_TRP21_SHIFT                                        (0x00000015U)
#define CSL_MCAN_CORE_TXBRP_TRP21_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP21_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP22_MASK                                         (0x00400000U)
#define CSL_MCAN_CORE_TXBRP_TRP22_SHIFT                                        (0x00000016U)
#define CSL_MCAN_CORE_TXBRP_TRP22_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP22_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP23_MASK                                         (0x00800000U)
#define CSL_MCAN_CORE_TXBRP_TRP23_SHIFT                                        (0x00000017U)
#define CSL_MCAN_CORE_TXBRP_TRP23_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP23_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP24_MASK                                         (0x01000000U)
#define CSL_MCAN_CORE_TXBRP_TRP24_SHIFT                                        (0x00000018U)
#define CSL_MCAN_CORE_TXBRP_TRP24_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP24_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP25_MASK                                         (0x02000000U)
#define CSL_MCAN_CORE_TXBRP_TRP25_SHIFT                                        (0x00000019U)
#define CSL_MCAN_CORE_TXBRP_TRP25_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP25_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP26_MASK                                         (0x04000000U)
#define CSL_MCAN_CORE_TXBRP_TRP26_SHIFT                                        (0x0000001AU)
#define CSL_MCAN_CORE_TXBRP_TRP26_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP26_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP27_MASK                                         (0x08000000U)
#define CSL_MCAN_CORE_TXBRP_TRP27_SHIFT                                        (0x0000001BU)
#define CSL_MCAN_CORE_TXBRP_TRP27_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP27_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP28_MASK                                         (0x10000000U)
#define CSL_MCAN_CORE_TXBRP_TRP28_SHIFT                                        (0x0000001CU)
#define CSL_MCAN_CORE_TXBRP_TRP28_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP28_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP29_MASK                                         (0x20000000U)
#define CSL_MCAN_CORE_TXBRP_TRP29_SHIFT                                        (0x0000001DU)
#define CSL_MCAN_CORE_TXBRP_TRP29_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP29_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP30_MASK                                         (0x40000000U)
#define CSL_MCAN_CORE_TXBRP_TRP30_SHIFT                                        (0x0000001EU)
#define CSL_MCAN_CORE_TXBRP_TRP30_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP30_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_TRP31_MASK                                         (0x80000000U)
#define CSL_MCAN_CORE_TXBRP_TRP31_SHIFT                                        (0x0000001FU)
#define CSL_MCAN_CORE_TXBRP_TRP31_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBRP_TRP31_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBRP_RESETVAL                                           (0x00000000U)

/* TXBAR */

#define CSL_MCAN_CORE_TXBAR_AR0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_TXBAR_AR0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_TXBAR_AR1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_TXBAR_AR1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR2_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_TXBAR_AR2_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBAR_AR2_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR2_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR3_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_TXBAR_AR3_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_TXBAR_AR3_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR3_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR4_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_TXBAR_AR4_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_TXBAR_AR4_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR4_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR5_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_TXBAR_AR5_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_TXBAR_AR5_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR5_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR6_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_TXBAR_AR6_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_TXBAR_AR6_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR6_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR7_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_TXBAR_AR7_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_TXBAR_AR7_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR7_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR8_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_TXBAR_AR8_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_TXBAR_AR8_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR8_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR9_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_TXBAR_AR9_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_TXBAR_AR9_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR9_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR10_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_TXBAR_AR10_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_TXBAR_AR10_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR10_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR11_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_TXBAR_AR11_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_TXBAR_AR11_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR11_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR12_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_TXBAR_AR12_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_TXBAR_AR12_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR12_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR13_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_TXBAR_AR13_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_TXBAR_AR13_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR13_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR14_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_TXBAR_AR14_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_TXBAR_AR14_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR14_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR15_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_TXBAR_AR15_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_TXBAR_AR15_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR15_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR16_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_TXBAR_AR16_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_TXBAR_AR16_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR16_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR17_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_TXBAR_AR17_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_TXBAR_AR17_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR17_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR18_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_TXBAR_AR18_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_TXBAR_AR18_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR18_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR19_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_TXBAR_AR19_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_TXBAR_AR19_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR19_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR20_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_TXBAR_AR20_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_TXBAR_AR20_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR20_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR21_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_TXBAR_AR21_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_TXBAR_AR21_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR21_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR22_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_TXBAR_AR22_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_TXBAR_AR22_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR22_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR23_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_TXBAR_AR23_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_TXBAR_AR23_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR23_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR24_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_TXBAR_AR24_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_TXBAR_AR24_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR24_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR25_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_TXBAR_AR25_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_TXBAR_AR25_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR25_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR26_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_TXBAR_AR26_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_TXBAR_AR26_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR26_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR27_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_TXBAR_AR27_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_TXBAR_AR27_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR27_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR28_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_TXBAR_AR28_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_TXBAR_AR28_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR28_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR29_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_TXBAR_AR29_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_TXBAR_AR29_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR29_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR30_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_TXBAR_AR30_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_TXBAR_AR30_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR30_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_AR31_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_TXBAR_AR31_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_TXBAR_AR31_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBAR_AR31_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBAR_RESETVAL                                           (0x00000000U)

/* TXBCR */

#define CSL_MCAN_CORE_TXBCR_CR0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_TXBCR_CR0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_TXBCR_CR1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_TXBCR_CR1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR2_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_TXBCR_CR2_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBCR_CR2_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR2_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR3_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_TXBCR_CR3_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_TXBCR_CR3_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR3_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR4_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_TXBCR_CR4_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_TXBCR_CR4_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR4_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR5_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_TXBCR_CR5_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_TXBCR_CR5_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR5_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR6_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_TXBCR_CR6_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_TXBCR_CR6_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR6_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR7_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_TXBCR_CR7_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_TXBCR_CR7_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR7_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR8_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_TXBCR_CR8_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_TXBCR_CR8_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR8_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR9_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_TXBCR_CR9_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_TXBCR_CR9_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR9_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR10_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_TXBCR_CR10_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_TXBCR_CR10_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR10_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR11_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_TXBCR_CR11_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_TXBCR_CR11_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR11_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR12_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_TXBCR_CR12_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_TXBCR_CR12_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR12_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR13_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_TXBCR_CR13_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_TXBCR_CR13_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR13_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR14_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_TXBCR_CR14_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_TXBCR_CR14_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR14_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR15_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_TXBCR_CR15_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_TXBCR_CR15_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR15_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR16_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_TXBCR_CR16_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_TXBCR_CR16_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR16_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR17_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_TXBCR_CR17_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_TXBCR_CR17_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR17_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR18_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_TXBCR_CR18_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_TXBCR_CR18_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR18_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR19_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_TXBCR_CR19_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_TXBCR_CR19_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR19_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR20_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_TXBCR_CR20_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_TXBCR_CR20_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR20_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR21_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_TXBCR_CR21_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_TXBCR_CR21_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR21_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR22_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_TXBCR_CR22_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_TXBCR_CR22_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR22_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR23_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_TXBCR_CR23_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_TXBCR_CR23_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR23_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR24_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_TXBCR_CR24_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_TXBCR_CR24_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR24_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR25_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_TXBCR_CR25_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_TXBCR_CR25_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR25_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR26_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_TXBCR_CR26_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_TXBCR_CR26_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR26_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR27_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_TXBCR_CR27_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_TXBCR_CR27_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR27_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR28_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_TXBCR_CR28_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_TXBCR_CR28_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR28_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR29_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_TXBCR_CR29_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_TXBCR_CR29_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR29_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR30_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_TXBCR_CR30_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_TXBCR_CR30_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR30_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_CR31_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_TXBCR_CR31_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_TXBCR_CR31_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCR_CR31_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCR_RESETVAL                                           (0x00000000U)

/* TXBTO */

#define CSL_MCAN_CORE_TXBTO_TO0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_TXBTO_TO0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_TXBTO_TO1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_TXBTO_TO1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO2_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_TXBTO_TO2_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBTO_TO2_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO2_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO3_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_TXBTO_TO3_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_TXBTO_TO3_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO3_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO4_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_TXBTO_TO4_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_TXBTO_TO4_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO4_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO5_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_TXBTO_TO5_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_TXBTO_TO5_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO5_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO6_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_TXBTO_TO6_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_TXBTO_TO6_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO6_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO7_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_TXBTO_TO7_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_TXBTO_TO7_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO7_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO8_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_TXBTO_TO8_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_TXBTO_TO8_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO8_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO9_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_TXBTO_TO9_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_TXBTO_TO9_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO9_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO10_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_TXBTO_TO10_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_TXBTO_TO10_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO10_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO11_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_TXBTO_TO11_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_TXBTO_TO11_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO11_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO12_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_TXBTO_TO12_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_TXBTO_TO12_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO12_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO13_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_TXBTO_TO13_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_TXBTO_TO13_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO13_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO14_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_TXBTO_TO14_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_TXBTO_TO14_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO14_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO15_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_TXBTO_TO15_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_TXBTO_TO15_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO15_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO16_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_TXBTO_TO16_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_TXBTO_TO16_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO16_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO17_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_TXBTO_TO17_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_TXBTO_TO17_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO17_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO18_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_TXBTO_TO18_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_TXBTO_TO18_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO18_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO19_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_TXBTO_TO19_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_TXBTO_TO19_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO19_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO20_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_TXBTO_TO20_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_TXBTO_TO20_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO20_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO21_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_TXBTO_TO21_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_TXBTO_TO21_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO21_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO22_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_TXBTO_TO22_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_TXBTO_TO22_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO22_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO23_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_TXBTO_TO23_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_TXBTO_TO23_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO23_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO24_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_TXBTO_TO24_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_TXBTO_TO24_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO24_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO25_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_TXBTO_TO25_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_TXBTO_TO25_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO25_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO26_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_TXBTO_TO26_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_TXBTO_TO26_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO26_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO27_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_TXBTO_TO27_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_TXBTO_TO27_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO27_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO28_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_TXBTO_TO28_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_TXBTO_TO28_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO28_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO29_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_TXBTO_TO29_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_TXBTO_TO29_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO29_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO30_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_TXBTO_TO30_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_TXBTO_TO30_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO30_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_TO31_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_TXBTO_TO31_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_TXBTO_TO31_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBTO_TO31_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBTO_RESETVAL                                           (0x00000000U)

/* TXBCF */

#define CSL_MCAN_CORE_TXBCF_CF0_MASK                                           (0x00000001U)
#define CSL_MCAN_CORE_TXBCF_CF0_SHIFT                                          (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF0_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF0_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF1_MASK                                           (0x00000002U)
#define CSL_MCAN_CORE_TXBCF_CF1_SHIFT                                          (0x00000001U)
#define CSL_MCAN_CORE_TXBCF_CF1_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF1_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF2_MASK                                           (0x00000004U)
#define CSL_MCAN_CORE_TXBCF_CF2_SHIFT                                          (0x00000002U)
#define CSL_MCAN_CORE_TXBCF_CF2_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF2_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF3_MASK                                           (0x00000008U)
#define CSL_MCAN_CORE_TXBCF_CF3_SHIFT                                          (0x00000003U)
#define CSL_MCAN_CORE_TXBCF_CF3_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF3_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF4_MASK                                           (0x00000010U)
#define CSL_MCAN_CORE_TXBCF_CF4_SHIFT                                          (0x00000004U)
#define CSL_MCAN_CORE_TXBCF_CF4_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF4_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF5_MASK                                           (0x00000020U)
#define CSL_MCAN_CORE_TXBCF_CF5_SHIFT                                          (0x00000005U)
#define CSL_MCAN_CORE_TXBCF_CF5_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF5_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF6_MASK                                           (0x00000040U)
#define CSL_MCAN_CORE_TXBCF_CF6_SHIFT                                          (0x00000006U)
#define CSL_MCAN_CORE_TXBCF_CF6_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF6_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF7_MASK                                           (0x00000080U)
#define CSL_MCAN_CORE_TXBCF_CF7_SHIFT                                          (0x00000007U)
#define CSL_MCAN_CORE_TXBCF_CF7_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF7_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF8_MASK                                           (0x00000100U)
#define CSL_MCAN_CORE_TXBCF_CF8_SHIFT                                          (0x00000008U)
#define CSL_MCAN_CORE_TXBCF_CF8_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF8_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF9_MASK                                           (0x00000200U)
#define CSL_MCAN_CORE_TXBCF_CF9_SHIFT                                          (0x00000009U)
#define CSL_MCAN_CORE_TXBCF_CF9_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF9_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF10_MASK                                          (0x00000400U)
#define CSL_MCAN_CORE_TXBCF_CF10_SHIFT                                         (0x0000000AU)
#define CSL_MCAN_CORE_TXBCF_CF10_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF10_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF11_MASK                                          (0x00000800U)
#define CSL_MCAN_CORE_TXBCF_CF11_SHIFT                                         (0x0000000BU)
#define CSL_MCAN_CORE_TXBCF_CF11_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF11_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF12_MASK                                          (0x00001000U)
#define CSL_MCAN_CORE_TXBCF_CF12_SHIFT                                         (0x0000000CU)
#define CSL_MCAN_CORE_TXBCF_CF12_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF12_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF13_MASK                                          (0x00002000U)
#define CSL_MCAN_CORE_TXBCF_CF13_SHIFT                                         (0x0000000DU)
#define CSL_MCAN_CORE_TXBCF_CF13_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF13_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF14_MASK                                          (0x00004000U)
#define CSL_MCAN_CORE_TXBCF_CF14_SHIFT                                         (0x0000000EU)
#define CSL_MCAN_CORE_TXBCF_CF14_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF14_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF15_MASK                                          (0x00008000U)
#define CSL_MCAN_CORE_TXBCF_CF15_SHIFT                                         (0x0000000FU)
#define CSL_MCAN_CORE_TXBCF_CF15_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF15_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF16_MASK                                          (0x00010000U)
#define CSL_MCAN_CORE_TXBCF_CF16_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_TXBCF_CF16_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF16_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF17_MASK                                          (0x00020000U)
#define CSL_MCAN_CORE_TXBCF_CF17_SHIFT                                         (0x00000011U)
#define CSL_MCAN_CORE_TXBCF_CF17_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF17_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF18_MASK                                          (0x00040000U)
#define CSL_MCAN_CORE_TXBCF_CF18_SHIFT                                         (0x00000012U)
#define CSL_MCAN_CORE_TXBCF_CF18_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF18_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF19_MASK                                          (0x00080000U)
#define CSL_MCAN_CORE_TXBCF_CF19_SHIFT                                         (0x00000013U)
#define CSL_MCAN_CORE_TXBCF_CF19_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF19_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF20_MASK                                          (0x00100000U)
#define CSL_MCAN_CORE_TXBCF_CF20_SHIFT                                         (0x00000014U)
#define CSL_MCAN_CORE_TXBCF_CF20_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF20_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF21_MASK                                          (0x00200000U)
#define CSL_MCAN_CORE_TXBCF_CF21_SHIFT                                         (0x00000015U)
#define CSL_MCAN_CORE_TXBCF_CF21_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF21_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF22_MASK                                          (0x00400000U)
#define CSL_MCAN_CORE_TXBCF_CF22_SHIFT                                         (0x00000016U)
#define CSL_MCAN_CORE_TXBCF_CF22_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF22_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF23_MASK                                          (0x00800000U)
#define CSL_MCAN_CORE_TXBCF_CF23_SHIFT                                         (0x00000017U)
#define CSL_MCAN_CORE_TXBCF_CF23_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF23_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF24_MASK                                          (0x01000000U)
#define CSL_MCAN_CORE_TXBCF_CF24_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_TXBCF_CF24_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF24_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF25_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_TXBCF_CF25_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_TXBCF_CF25_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF25_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF26_MASK                                          (0x04000000U)
#define CSL_MCAN_CORE_TXBCF_CF26_SHIFT                                         (0x0000001AU)
#define CSL_MCAN_CORE_TXBCF_CF26_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF26_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF27_MASK                                          (0x08000000U)
#define CSL_MCAN_CORE_TXBCF_CF27_SHIFT                                         (0x0000001BU)
#define CSL_MCAN_CORE_TXBCF_CF27_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF27_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF28_MASK                                          (0x10000000U)
#define CSL_MCAN_CORE_TXBCF_CF28_SHIFT                                         (0x0000001CU)
#define CSL_MCAN_CORE_TXBCF_CF28_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF28_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF29_MASK                                          (0x20000000U)
#define CSL_MCAN_CORE_TXBCF_CF29_SHIFT                                         (0x0000001DU)
#define CSL_MCAN_CORE_TXBCF_CF29_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF29_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF30_MASK                                          (0x40000000U)
#define CSL_MCAN_CORE_TXBCF_CF30_SHIFT                                         (0x0000001EU)
#define CSL_MCAN_CORE_TXBCF_CF30_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF30_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_CF31_MASK                                          (0x80000000U)
#define CSL_MCAN_CORE_TXBCF_CF31_SHIFT                                         (0x0000001FU)
#define CSL_MCAN_CORE_TXBCF_CF31_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXBCF_CF31_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXBCF_RESETVAL                                           (0x00000000U)

/* TXBTIE */

#define CSL_MCAN_CORE_TXBTIE_TIE0_MASK                                         (0x00000001U)
#define CSL_MCAN_CORE_TXBTIE_TIE0_SHIFT                                        (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE0_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE0_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE1_MASK                                         (0x00000002U)
#define CSL_MCAN_CORE_TXBTIE_TIE1_SHIFT                                        (0x00000001U)
#define CSL_MCAN_CORE_TXBTIE_TIE1_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE1_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE2_MASK                                         (0x00000004U)
#define CSL_MCAN_CORE_TXBTIE_TIE2_SHIFT                                        (0x00000002U)
#define CSL_MCAN_CORE_TXBTIE_TIE2_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE2_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE3_MASK                                         (0x00000008U)
#define CSL_MCAN_CORE_TXBTIE_TIE3_SHIFT                                        (0x00000003U)
#define CSL_MCAN_CORE_TXBTIE_TIE3_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE3_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE4_MASK                                         (0x00000010U)
#define CSL_MCAN_CORE_TXBTIE_TIE4_SHIFT                                        (0x00000004U)
#define CSL_MCAN_CORE_TXBTIE_TIE4_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE4_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE5_MASK                                         (0x00000020U)
#define CSL_MCAN_CORE_TXBTIE_TIE5_SHIFT                                        (0x00000005U)
#define CSL_MCAN_CORE_TXBTIE_TIE5_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE5_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE6_MASK                                         (0x00000040U)
#define CSL_MCAN_CORE_TXBTIE_TIE6_SHIFT                                        (0x00000006U)
#define CSL_MCAN_CORE_TXBTIE_TIE6_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE6_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE7_MASK                                         (0x00000080U)
#define CSL_MCAN_CORE_TXBTIE_TIE7_SHIFT                                        (0x00000007U)
#define CSL_MCAN_CORE_TXBTIE_TIE7_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE7_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE8_MASK                                         (0x00000100U)
#define CSL_MCAN_CORE_TXBTIE_TIE8_SHIFT                                        (0x00000008U)
#define CSL_MCAN_CORE_TXBTIE_TIE8_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE8_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE9_MASK                                         (0x00000200U)
#define CSL_MCAN_CORE_TXBTIE_TIE9_SHIFT                                        (0x00000009U)
#define CSL_MCAN_CORE_TXBTIE_TIE9_RESETVAL                                     (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE9_MAX                                          (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE10_MASK                                        (0x00000400U)
#define CSL_MCAN_CORE_TXBTIE_TIE10_SHIFT                                       (0x0000000AU)
#define CSL_MCAN_CORE_TXBTIE_TIE10_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE10_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE11_MASK                                        (0x00000800U)
#define CSL_MCAN_CORE_TXBTIE_TIE11_SHIFT                                       (0x0000000BU)
#define CSL_MCAN_CORE_TXBTIE_TIE11_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE11_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE12_MASK                                        (0x00001000U)
#define CSL_MCAN_CORE_TXBTIE_TIE12_SHIFT                                       (0x0000000CU)
#define CSL_MCAN_CORE_TXBTIE_TIE12_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE12_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE13_MASK                                        (0x00002000U)
#define CSL_MCAN_CORE_TXBTIE_TIE13_SHIFT                                       (0x0000000DU)
#define CSL_MCAN_CORE_TXBTIE_TIE13_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE13_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE14_MASK                                        (0x00004000U)
#define CSL_MCAN_CORE_TXBTIE_TIE14_SHIFT                                       (0x0000000EU)
#define CSL_MCAN_CORE_TXBTIE_TIE14_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE14_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE15_MASK                                        (0x00008000U)
#define CSL_MCAN_CORE_TXBTIE_TIE15_SHIFT                                       (0x0000000FU)
#define CSL_MCAN_CORE_TXBTIE_TIE15_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE15_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE16_MASK                                        (0x00010000U)
#define CSL_MCAN_CORE_TXBTIE_TIE16_SHIFT                                       (0x00000010U)
#define CSL_MCAN_CORE_TXBTIE_TIE16_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE16_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE17_MASK                                        (0x00020000U)
#define CSL_MCAN_CORE_TXBTIE_TIE17_SHIFT                                       (0x00000011U)
#define CSL_MCAN_CORE_TXBTIE_TIE17_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE17_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE18_MASK                                        (0x00040000U)
#define CSL_MCAN_CORE_TXBTIE_TIE18_SHIFT                                       (0x00000012U)
#define CSL_MCAN_CORE_TXBTIE_TIE18_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE18_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE19_MASK                                        (0x00080000U)
#define CSL_MCAN_CORE_TXBTIE_TIE19_SHIFT                                       (0x00000013U)
#define CSL_MCAN_CORE_TXBTIE_TIE19_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE19_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE20_MASK                                        (0x00100000U)
#define CSL_MCAN_CORE_TXBTIE_TIE20_SHIFT                                       (0x00000014U)
#define CSL_MCAN_CORE_TXBTIE_TIE20_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE20_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE21_MASK                                        (0x00200000U)
#define CSL_MCAN_CORE_TXBTIE_TIE21_SHIFT                                       (0x00000015U)
#define CSL_MCAN_CORE_TXBTIE_TIE21_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE21_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE22_MASK                                        (0x00400000U)
#define CSL_MCAN_CORE_TXBTIE_TIE22_SHIFT                                       (0x00000016U)
#define CSL_MCAN_CORE_TXBTIE_TIE22_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE22_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE23_MASK                                        (0x00800000U)
#define CSL_MCAN_CORE_TXBTIE_TIE23_SHIFT                                       (0x00000017U)
#define CSL_MCAN_CORE_TXBTIE_TIE23_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE23_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE24_MASK                                        (0x01000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE24_SHIFT                                       (0x00000018U)
#define CSL_MCAN_CORE_TXBTIE_TIE24_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE24_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE25_MASK                                        (0x02000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE25_SHIFT                                       (0x00000019U)
#define CSL_MCAN_CORE_TXBTIE_TIE25_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE25_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE26_MASK                                        (0x04000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE26_SHIFT                                       (0x0000001AU)
#define CSL_MCAN_CORE_TXBTIE_TIE26_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE26_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE27_MASK                                        (0x08000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE27_SHIFT                                       (0x0000001BU)
#define CSL_MCAN_CORE_TXBTIE_TIE27_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE27_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE28_MASK                                        (0x10000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE28_SHIFT                                       (0x0000001CU)
#define CSL_MCAN_CORE_TXBTIE_TIE28_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE28_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE29_MASK                                        (0x20000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE29_SHIFT                                       (0x0000001DU)
#define CSL_MCAN_CORE_TXBTIE_TIE29_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE29_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE30_MASK                                        (0x40000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE30_SHIFT                                       (0x0000001EU)
#define CSL_MCAN_CORE_TXBTIE_TIE30_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE30_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_TIE31_MASK                                        (0x80000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE31_SHIFT                                       (0x0000001FU)
#define CSL_MCAN_CORE_TXBTIE_TIE31_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBTIE_TIE31_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBTIE_RESETVAL                                          (0x00000000U)

/* TXBCIE */

#define CSL_MCAN_CORE_TXBCIE_CFIE0_MASK                                        (0x00000001U)
#define CSL_MCAN_CORE_TXBCIE_CFIE0_SHIFT                                       (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE0_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE0_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE1_MASK                                        (0x00000002U)
#define CSL_MCAN_CORE_TXBCIE_CFIE1_SHIFT                                       (0x00000001U)
#define CSL_MCAN_CORE_TXBCIE_CFIE1_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE1_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE2_MASK                                        (0x00000004U)
#define CSL_MCAN_CORE_TXBCIE_CFIE2_SHIFT                                       (0x00000002U)
#define CSL_MCAN_CORE_TXBCIE_CFIE2_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE2_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE3_MASK                                        (0x00000008U)
#define CSL_MCAN_CORE_TXBCIE_CFIE3_SHIFT                                       (0x00000003U)
#define CSL_MCAN_CORE_TXBCIE_CFIE3_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE3_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE4_MASK                                        (0x00000010U)
#define CSL_MCAN_CORE_TXBCIE_CFIE4_SHIFT                                       (0x00000004U)
#define CSL_MCAN_CORE_TXBCIE_CFIE4_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE4_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE5_MASK                                        (0x00000020U)
#define CSL_MCAN_CORE_TXBCIE_CFIE5_SHIFT                                       (0x00000005U)
#define CSL_MCAN_CORE_TXBCIE_CFIE5_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE5_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE6_MASK                                        (0x00000040U)
#define CSL_MCAN_CORE_TXBCIE_CFIE6_SHIFT                                       (0x00000006U)
#define CSL_MCAN_CORE_TXBCIE_CFIE6_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE6_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE7_MASK                                        (0x00000080U)
#define CSL_MCAN_CORE_TXBCIE_CFIE7_SHIFT                                       (0x00000007U)
#define CSL_MCAN_CORE_TXBCIE_CFIE7_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE7_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE8_MASK                                        (0x00000100U)
#define CSL_MCAN_CORE_TXBCIE_CFIE8_SHIFT                                       (0x00000008U)
#define CSL_MCAN_CORE_TXBCIE_CFIE8_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE8_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE9_MASK                                        (0x00000200U)
#define CSL_MCAN_CORE_TXBCIE_CFIE9_SHIFT                                       (0x00000009U)
#define CSL_MCAN_CORE_TXBCIE_CFIE9_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE9_MAX                                         (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE10_MASK                                       (0x00000400U)
#define CSL_MCAN_CORE_TXBCIE_CFIE10_SHIFT                                      (0x0000000AU)
#define CSL_MCAN_CORE_TXBCIE_CFIE10_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE10_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE11_MASK                                       (0x00000800U)
#define CSL_MCAN_CORE_TXBCIE_CFIE11_SHIFT                                      (0x0000000BU)
#define CSL_MCAN_CORE_TXBCIE_CFIE11_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE11_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE12_MASK                                       (0x00001000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE12_SHIFT                                      (0x0000000CU)
#define CSL_MCAN_CORE_TXBCIE_CFIE12_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE12_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE13_MASK                                       (0x00002000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE13_SHIFT                                      (0x0000000DU)
#define CSL_MCAN_CORE_TXBCIE_CFIE13_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE13_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE14_MASK                                       (0x00004000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE14_SHIFT                                      (0x0000000EU)
#define CSL_MCAN_CORE_TXBCIE_CFIE14_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE14_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE15_MASK                                       (0x00008000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE15_SHIFT                                      (0x0000000FU)
#define CSL_MCAN_CORE_TXBCIE_CFIE15_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE15_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE16_MASK                                       (0x00010000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE16_SHIFT                                      (0x00000010U)
#define CSL_MCAN_CORE_TXBCIE_CFIE16_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE16_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE17_MASK                                       (0x00020000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE17_SHIFT                                      (0x00000011U)
#define CSL_MCAN_CORE_TXBCIE_CFIE17_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE17_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE18_MASK                                       (0x00040000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE18_SHIFT                                      (0x00000012U)
#define CSL_MCAN_CORE_TXBCIE_CFIE18_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE18_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE19_MASK                                       (0x00080000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE19_SHIFT                                      (0x00000013U)
#define CSL_MCAN_CORE_TXBCIE_CFIE19_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE19_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE20_MASK                                       (0x00100000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE20_SHIFT                                      (0x00000014U)
#define CSL_MCAN_CORE_TXBCIE_CFIE20_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE20_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE21_MASK                                       (0x00200000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE21_SHIFT                                      (0x00000015U)
#define CSL_MCAN_CORE_TXBCIE_CFIE21_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE21_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE22_MASK                                       (0x00400000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE22_SHIFT                                      (0x00000016U)
#define CSL_MCAN_CORE_TXBCIE_CFIE22_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE22_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE23_MASK                                       (0x00800000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE23_SHIFT                                      (0x00000017U)
#define CSL_MCAN_CORE_TXBCIE_CFIE23_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE23_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE24_MASK                                       (0x01000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE24_SHIFT                                      (0x00000018U)
#define CSL_MCAN_CORE_TXBCIE_CFIE24_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE24_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE25_MASK                                       (0x02000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE25_SHIFT                                      (0x00000019U)
#define CSL_MCAN_CORE_TXBCIE_CFIE25_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE25_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE26_MASK                                       (0x04000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE26_SHIFT                                      (0x0000001AU)
#define CSL_MCAN_CORE_TXBCIE_CFIE26_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE26_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE27_MASK                                       (0x08000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE27_SHIFT                                      (0x0000001BU)
#define CSL_MCAN_CORE_TXBCIE_CFIE27_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE27_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE28_MASK                                       (0x10000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE28_SHIFT                                      (0x0000001CU)
#define CSL_MCAN_CORE_TXBCIE_CFIE28_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE28_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE29_MASK                                       (0x20000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE29_SHIFT                                      (0x0000001DU)
#define CSL_MCAN_CORE_TXBCIE_CFIE29_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE29_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE30_MASK                                       (0x40000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE30_SHIFT                                      (0x0000001EU)
#define CSL_MCAN_CORE_TXBCIE_CFIE30_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE30_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_CFIE31_MASK                                       (0x80000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE31_SHIFT                                      (0x0000001FU)
#define CSL_MCAN_CORE_TXBCIE_CFIE31_RESETVAL                                   (0x00000000U)
#define CSL_MCAN_CORE_TXBCIE_CFIE31_MAX                                        (0x00000001U)

#define CSL_MCAN_CORE_TXBCIE_RESETVAL                                          (0x00000000U)

/* RESERVED1414 */

#define CSL_MCAN_CORE_RESERVED1414_RESETVAL                                    (0x00000000U)

/* RESERVED1515 */

#define CSL_MCAN_CORE_RESERVED1515_RESETVAL                                    (0x00000000U)

/* TXEFC */

#define CSL_MCAN_CORE_TXEFC_EFSA_MASK                                          (0x0000FFFCU)
#define CSL_MCAN_CORE_TXEFC_EFSA_SHIFT                                         (0x00000002U)
#define CSL_MCAN_CORE_TXEFC_EFSA_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFC_EFSA_MAX                                           (0x00003FFFU)

#define CSL_MCAN_CORE_TXEFC_EFS_MASK                                           (0x003F0000U)
#define CSL_MCAN_CORE_TXEFC_EFS_SHIFT                                          (0x00000010U)
#define CSL_MCAN_CORE_TXEFC_EFS_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXEFC_EFS_MAX                                            (0x0000003FU)

#define CSL_MCAN_CORE_TXEFC_EFWM_MASK                                          (0x3F000000U)
#define CSL_MCAN_CORE_TXEFC_EFWM_SHIFT                                         (0x00000018U)
#define CSL_MCAN_CORE_TXEFC_EFWM_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFC_EFWM_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_TXEFC_RESETVAL                                           (0x00000000U)

/* TXEFS */

#define CSL_MCAN_CORE_TXEFS_EFFL_MASK                                          (0x0000003FU)
#define CSL_MCAN_CORE_TXEFS_EFFL_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_EFFL_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_EFFL_MAX                                           (0x0000003FU)

#define CSL_MCAN_CORE_TXEFS_EFGI_MASK                                          (0x00001F00U)
#define CSL_MCAN_CORE_TXEFS_EFGI_SHIFT                                         (0x00000008U)
#define CSL_MCAN_CORE_TXEFS_EFGI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_EFGI_MAX                                           (0x0000001FU)

#define CSL_MCAN_CORE_TXEFS_EFPI_MASK                                          (0x001F0000U)
#define CSL_MCAN_CORE_TXEFS_EFPI_SHIFT                                         (0x00000010U)
#define CSL_MCAN_CORE_TXEFS_EFPI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_EFPI_MAX                                           (0x0000001FU)

#define CSL_MCAN_CORE_TXEFS_EFF_MASK                                           (0x01000000U)
#define CSL_MCAN_CORE_TXEFS_EFF_SHIFT                                          (0x00000018U)
#define CSL_MCAN_CORE_TXEFS_EFF_RESETVAL                                       (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_EFF_MAX                                            (0x00000001U)

#define CSL_MCAN_CORE_TXEFS_TEFL_MASK                                          (0x02000000U)
#define CSL_MCAN_CORE_TXEFS_TEFL_SHIFT                                         (0x00000019U)
#define CSL_MCAN_CORE_TXEFS_TEFL_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFS_TEFL_MAX                                           (0x00000001U)

#define CSL_MCAN_CORE_TXEFS_RESETVAL                                           (0x00000000U)

/* TXEFA */

#define CSL_MCAN_CORE_TXEFA_EFAI_MASK                                          (0x0000001FU)
#define CSL_MCAN_CORE_TXEFA_EFAI_SHIFT                                         (0x00000000U)
#define CSL_MCAN_CORE_TXEFA_EFAI_RESETVAL                                      (0x00000000U)
#define CSL_MCAN_CORE_TXEFA_EFAI_MAX                                           (0x0000001FU)

#define CSL_MCAN_CORE_TXEFA_RESETVAL                                           (0x00000000U)

/* RESERVED1616 */

#define CSL_MCAN_CORE_RESERVED1616_RESETVAL                                    (0x00000000U)

/**************************************************************************
* Hardware Region  : Message Memory
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t ARRAY[17408];              /* MCAN Message memory */
} CSL_mcan_msgmemRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MCAN_MSGMEM_ARRAY(ARRAY)                                           ((0x00000000U+(ARRAY)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* ARRAY */

#define CSL_MCAN_MSGMEM_ARRAY_DATA_MASK                                        (0xFFFFFFFFU)
#define CSL_MCAN_MSGMEM_ARRAY_DATA_SHIFT                                       (0x00000000U)
#define CSL_MCAN_MSGMEM_ARRAY_DATA_RESETVAL                                    (0x00000000U)
#define CSL_MCAN_MSGMEM_ARRAY_DATA_MAX                                         (0xFFFFFFFFU)

#define CSL_MCAN_MSGMEM_ARRAY_RESETVAL                                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
