/*
 * Auto-generated CSL section
 */
/*
 *
 * Copyright (C) 2011 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef CSLR_SOC_IN_H
#define CSLR_SOC_IN_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/soc/am572x/src/cslr_interrupt.h>
#include <ti/csl/soc/am572x/src/cslr_soc_dsp_baseaddress.h>
#include <ti/csl/soc/am572x/src/cslr_soc_eve_baseaddress.h>
#include <ti/csl/soc/am572x/src/cslr_soc_ipu_baseaddress.h>
#include <ti/csl/soc/am572x/src/cslr_soc_mpu_baseaddress.h>
#include <ti/csl/soc/am572x/src/cslr_cam_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_cam_prm.h>
#include <ti/csl/soc/am572x/src/cslr_ckgen_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_ckgen_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_ckgen_prm.h>
#include <ti/csl/soc/am572x/src/cslr_control_core.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_sec.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_wkup.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_wkup_pad.h>
#include <ti/csl/soc/am572x/src/cslr_control_intr_dma.h>
#include <ti/csl/soc/am572x/src/cslr_core_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_core_prm.h>
#include <ti/csl/soc/am572x/src/cslr_coreaon_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_coreaon_prm.h>
#include <ti/csl/soc/am572x/src/cslr_custefuse_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_custefuse_prm.h>
#include <ti/csl/soc/am572x/src/cslr_device_prm.h>
#include <ti/csl/soc/am572x/src/cslr_dsp1_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_dsp1_prm.h>
#include <ti/csl/soc/am572x/src/cslr_dsp2_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_dsp2_prm.h>
#include <ti/csl/soc/am572x/src/cslr_dsp_l2_fnoc.h>
#include <ti/csl/soc/am572x/src/cslr_dss_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_dss_prm.h>
#include <ti/csl/soc/am572x/src/cslr_emu_cm.h>
#include <ti/csl/soc/am572x/src/cslr_emu_prm.h>
#include <ti/csl/soc/am572x/src/cslr_eve1_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_eve1_prm.h>
#include <ti/csl/soc/am572x/src/cslr_eve2_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_eve2_prm.h>
#include <ti/csl/soc/am572x/src/cslr_eve3_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_eve3_prm.h>
#include <ti/csl/soc/am572x/src/cslr_eve4_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_eve4_prm.h>
#include <ti/csl/soc/am572x/src/cslr_gpu_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_gpu_prm.h>
#include <ti/csl/soc/am572x/src/cslr_iodelayconfig.h>
#include <ti/csl/soc/am572x/src/cslr_ipu_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_ipu_prm.h>
#include <ti/csl/soc/am572x/src/cslr_iva_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_iva_prm.h>
/* #include <ti/csl/soc/am572x/src/cslr_iva_sys.h> */
/* #include <ti/csl/soc/am572x/src/cslr_kbd.h> */
#include <ti/csl/soc/am572x/src/cslr_l2_fnoc_eve.h>
#include <ti/csl/soc/am572x/src/cslr_l3_noc_avatar.h>
#include <ti/csl/soc/am572x/src/cslr_l3init_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_l3init_prm.h>
#include <ti/csl/soc/am572x/src/cslr_l4per_cm_core_component.h>
#include <ti/csl/soc/am572x/src/cslr_l4per_prm.h>
#include <ti/csl/soc/am572x/src/cslr_mpu_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_mpu_prm.h>
#include <ti/csl/src/ip/ocmc/V0/cslr_ocmc_ecc.h>
#include <ti/csl/soc/am572x/src/cslr_ocp2scp.h>
#include <ti/csl/soc/am572x/src/cslr_ocp_socket_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_ocp_socket_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_ocp_socket_prm.h>
#include <ti/csl/soc/am572x/src/cslr_ocp_wp_noc_c1.h>
#include <ti/csl/soc/am572x/src/cslr_prcm_mpu_cm_c0.h>
#include <ti/csl/soc/am572x/src/cslr_prcm_mpu_cm_c1.h>
#include <ti/csl/soc/am572x/src/cslr_prcm_mpu_prm_c0.h>
#include <ti/csl/soc/am572x/src/cslr_prcm_mpu_prm_c1.h>
#include <ti/csl/soc/am572x/src/cslr_restore_cm_core.h>
#include <ti/csl/soc/am572x/src/cslr_restore_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_rtc_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_rtc_prm.h>
#include <ti/csl/soc/am572x/src/cslr_vpe_cm_core_aon.h>
#include <ti/csl/soc/am572x/src/cslr_vpe_prm.h>
#include <ti/csl/soc/am572x/src/cslr_watchdogocp2.h>
#include <ti/csl/soc/am572x/src/cslr_wkupaon_cm.h>
#include <ti/csl/soc/am572x/src/cslr_wkupaon_prm.h>
#include <ti/csl/soc/am572x/src/cslr_wugen_local_prcm.h>
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>
#ifndef CSL_MODIFICATION
#include <ti/csl/soc/am572x/src/csl_device_common.h>
#endif
#include <ti/csl/soc/am572x/src/cslr_soc_aliases.h>
#include <ti/csl/soc/am572x/src/hw_ctrl_core.h>
#include <ti/csl/soc/am572x/src/hw_ctrl_wkup.h>
#include <ti/csl/soc/am572x/src/hw_ctrl_core_sec.h>
#include <ti/csl/soc/am572x/src/hw_mpu_prcm_prmc0.h>
#include <ti/csl/soc/am572x/src/hw_mpu_prcm_prmc1.h>
#include <ti/csl/soc/am572x/src/hw_sysconfig.h>
#include <ti/csl/soc/am572x/src/cslr_prcm_mpu_device.h>
#include <ti/csl/soc/am572x/src/hw_mpu_prcm_cmc0.h>
#include <ti/csl/soc/am572x/src/hw_mpu_prcm_cmc1.h>
#include <ti/csl/soc/am572x/src/hw_ipu_wugen_local_prcm.h>
#include <ti/csl/soc/am572x/src/hw_ipu_m4_nvic.h>

#ifdef __ARP32__
#include <ti/csl/soc/am572x/arp32/soc.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************\
 * Peripheral Instance count
 \******************************************************************************/

/** @brief Number of VPS VIP instances                                        */
#define CSL_VPS_VIP_PER_CNT             (3U)

/** @brief Number of VPS VPE instances                                        */
#define CSL_VPS_VPE_PER_CNT             (1U)

/** @brief Number of VPS DSS instances                                        */
#define CSL_VPS_DSS_PER_CNT             (1U)

/** @brief Number of VPS VIP instances                                        */
#define CSL_VPS_VIP_TOP_PER_CNT         (CSL_VPS_VIP_PER_CNT)

/** @brief Number of VPS VIP-PORT instances                                   */
#define CSL_VPS_VIP_PORT_PER_CNT        (CSL_VPS_VIP_PER_CNT * 4U)

/** @brief Number of VPS VPDMA instances                                      */
#define CSL_VPS_VPDMA_PER_CNT           (CSL_VPS_VIP_PER_CNT + \
                                            CSL_VPS_VPE_PER_CNT)

/** @brief Number of VPS CHRUS instances                                      */
#define CSL_VPS_CHRUS_PER_CNT           (CSL_VPS_VPE_PER_CNT * 3U)

/** @brief Number of VPS CSC instances                                        */
#define CSL_VPS_CSC_PER_CNT             ((CSL_VPS_VIP_PER_CNT * 2U) + \
                                            CSL_VPS_VPE_PER_CNT)

/** @brief Number of VPS VPE instances                                        */
#define CSL_VPS_VPE_TOP_PER_CNT         (CSL_VPS_VPE_PER_CNT)

/** @brief Number of VPS DEI instances                                        */
#define CSL_VPS_DEI_PER_CNT             (CSL_VPS_VPE_PER_CNT * 1U)

/** @brief Number of VPS SC instances                                         */
#define CSL_VPS_SC_PER_CNT              ((CSL_VPS_VIP_PER_CNT * 2U) \
                                            + CSL_VPS_VPE_PER_CNT)

/** @brief Number of VPS DSS-Video + Graphics instances */
#define CSL_VPS_DSS_VID_PIPE_PER_CNT    (4U)

/** @brief Number of VPS WB instances */
#define CSL_VPS_DSS_WB_PIPE_PER_CNT     (1U)

/** @brief Number of VPS CAPT ISS Pipelines  */
#define CSL_VPS_ISS_CAPT_PIPE_PER_CNT   (0U)

/** @brief Number of VPS DSS-Overlay manager instances                        */
#define CSL_VPS_DSS_OVLY_MGR_PER_CNT    (4U)

/******************************************************************************\
 * Interrupt Event IDs
\******************************************************************************/

#ifdef CSL_MODIFICATION
/* VPS interrupt                                                              */
#define CSL_INTC_EVENTID_VIP1INT0       (27U)
#define CSL_INTC_EVENTID_VIP2INT0       (28U)
#define CSL_INTC_EVENTID_VIP3INT0       (29U)
#define CSL_INTC_EVENTID_VPEINT0        (30U)
#define CSL_INTC_EVENTID_DSS_DISPC      (23U)
#else
/* VPS interrupt                                                              */
#if defined (__TI_ARM_V7M4__)
#define CSL_INTC_EVENTID_VIP1INT0       (27U)
#define CSL_INTC_EVENTID_VIP2INT0       (28U)
#define CSL_INTC_EVENTID_VIP3INT0       (29U)
#define CSL_INTC_EVENTID_VPEINT0        (30U)
#define CSL_INTC_EVENTID_DSS_DISPC      (23U)

#elif defined (__ARM_ARCH_7A__)
#define CSL_INTC_EVENTID_VIP1INT0       (49U + 32U)
#define CSL_INTC_EVENTID_VIP2INT0       (50U + 32U)
#define CSL_INTC_EVENTID_VIP3INT0       (51U + 32U)
#define CSL_INTC_EVENTID_VPEINT0        (52U + 32U)
#define CSL_INTC_EVENTID_DSS_DISPC      (25U + 32U)

#elif defined (_TMS320C6X)
#define CSL_INTC_EVENTID_VIP1INT0       (44U)
#define CSL_INTC_EVENTID_VIP2INT0       (45U)
#define CSL_INTC_EVENTID_VIP3INT0       (46U)
#define CSL_INTC_EVENTID_VPEINT0        (47U)
#define CSL_INTC_EVENTID_DSS_DISPC      (51U)
#endif
#endif /* CSL_MODIFICATION */

#define CSL_VPS_INTC_NUM                (0U)

/** @brief Number of McASP instances                                          */
#define CSL_MCASP_PER_CNT                   (8U)

/** @brief Number of UART instances                                           */
#define CSL_UART_PER_CNT                    (10U)

/** @brief Number of MCSPI instances                                          */
#define CSL_MCSPI_PER_CNT                   (4U)

/******************************************************************************\
 * Peripheral Instance definitions.
\******************************************************************************/
/** @brief Peripheral Instances of McASP instances                            */
#define CSL_MCASP_0                         (0)

/** @brief Peripheral Instances of UART instances                             */
#define CSL_UART_0                          (0)
#define CSL_UART_1                          (1)
#define CSL_UART_2                          (2)
#define CSL_UART_3                          (3)
#define CSL_UART_4                          (4)
#define CSL_UART_5                          (5)

typedef enum {
    UART1_INST = 0,
    UART2_INST,
    UART3_INST,
    UART4_INST,
    UART5_INST,
    UART6_INST,
    UART7_INST,
    UART8_INST,
    UART9_INST,
    UART10_INST
}UART_INST_t;

/** @brief Peripheral Instances of MCSPI instances                            */
#define CSL_MCSPI_0                         (0)
#define CSL_MCSPI_1                         (1)
#define CSL_MCSPI_2                         (2)
#define CSL_MCSPI_3                         (3)

/** @brief Peripheral Instances of MMC/SD instances
 *                           */
typedef enum {
    MMC1_INST = 0,
    MMC2_INST,
    MMC3_INST,
    MMC4_INST
}MMC_INST_t;

/******************************************************************************\
 * Interrupt Event IDs
 \*****************************************************************************/

/* I2C interrupt                                                              */
#define CSL_INTC_EVENTID_I2CINT1     (41U)
#define CSL_INTC_EVENTID_I2CINT3     (43U)
/*I2C4 Interrupt number is used by UART through cross bar and hence be cautious
 *while using this */
#define CSL_INTC_EVENTID_I2CINT4     (44U)


/*I2C2 Interrupt is mapped through cross bar and not used */
#define CSL_INTC_EVENTID_I2CINT2     (0U)
#define CSL_INTC_EVENTID_I2CINT5     (42U)


/* To get the ducati int mux number, the 'CSL_INTMUX_OFFSET' has to be
 * subttracted from the interrupt number (directly mapped)
 */
#define    CSL_INTMUX_OFFSET                (23U)

/* MCSPI interrupt                                                            */
#define    CSL_INTC_EVENTID_MCSPIINT0       (57)
#define    CSL_INTC_EVENTID_MCSPIINT1       (58)
/*Dummy and crossbar Mapped - please cross check before use */
#define    CSL_INTC_EVENTID_MCSPIINT2       (44)
#define    CSL_INTC_EVENTID_MCSPIINT3       (45)

/* UART interrupt                                                             */
/* All are crossbar mapped please cross check before use */
/*UART1 is being used in DMA Mode */
/*Instance Number Macro definitions are started from 0, it needs to be changed
 *to 1 later*/
#define    CSL_INTC_EVENTID_UARTINT0        (67U)
#define    CSL_INTC_EVENTID_UARTINT1        (60U)
#define    CSL_INTC_EVENTID_UARTINT2        (45U)
#define    CSL_INTC_EVENTID_UARTINT3        (61U)
#define    CSL_INTC_EVENTID_UARTINT4        (62U)
#define    CSL_INTC_EVENTID_UARTINT5        (63U)
#define    CSL_INTC_EVENTID_UARTINT6        (64U)
#define    CSL_INTC_EVENTID_UARTINT7        (65U)
#define    CSL_INTC_EVENTID_UARTINT8        (69U)
#define    CSL_INTC_EVENTID_UARTINT9        (70U)


/* McASP Interrupts
     All are crossbar mapped please cross check before use */

/* McASP1 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP0_RXINT        (58U)
/* McASP1 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP0_TXINT        (59U)
/* McASP2 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP1_RXINT        (60U)
/* McASP2 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP1_TXINT        (61U)
/* McASP3 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP2_RXINT        (91U)
/* McASP3 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP2_TXINT        (92U)
/* McASP4 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP3_RXINT        (74U)
/* McASP4 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP3_TXINT        (51U)
/* McASP5 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP4_RXINT        (79U)
/* McASP5 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP4_TXINT        (81U)
/* McASP6 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP5_RXINT        (86U)
/* McASP6 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP5_TXINT        (87U)
/* McASP7 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP6_RXINT        (88U)
/* McASP7 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP6_TXINT        (43U)
/* McASP8 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP7_RXINT        (48U)
/* McASP8 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP7_TXINT        (49U)


/*************************** EDMA RELATED DEFINES  ****************************/

/******************************************************************************\
 *  Parameterizable Configuration:- These are fed directly from the RTL
 *  parameters for the given SOC
 \******************************************************************************/

#define CSL_EDMA3_NUM_DMACH                 64
#define CSL_EDMA3_NUM_QDMACH                8
#define CSL_EDMA3_NUM_PARAMSETS             512
#define CSL_EDMA3_NUM_EVQUE                 4
#define CSL_EDMA3_CHMAPEXIST                0
#define CSL_EDMA3_NUM_REGIONS               4
#define CSL_EDMA3_MEMPROTECT                0

/******************************************************************************\
 * Channel Instance count
 \******************************************************************************/
#define CSL_EDMA3_CHA_CNT                   (CSL_EDMA3_NUM_DMACH + \
                                             CSL_EDMA3_NUM_QDMACH)

/* EDMA channel synchronization events                                        */

/* McASP0 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP0_RX             0
/* McASP0 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP0_TX             1
/* McASP1 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP1_RX             2
/* McASP1 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP1_TX             3
/* McASP2 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP2_RX             4
/* McASP2 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP2_TX             5
/* McASP3 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP3_RX             6
/* McASP3 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP3_TX             7
/* McASP4 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP4_RX             8
/* McASP4 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP4_TX             9
/* McASP5 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP5_RX             10
/* McASP5 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP5_TX             11
/* McASP6 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP6_RX             12
/* McASP6 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP6_TX             13
/* McASP7 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP7_RX             14
/* McASP7 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP7_TX             15

/*
 * *Instance Numbers starts from 1 in Vayu but keeping it to 0 to not change the
 * driver
 * Need to modify driver later for Instance Numbers
 */
/* UART0 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART0_RX              49
/* UART0 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART0_TX              48
/* UART1 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART1_RX              51
/* UART1 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART1_TX              50
/* UART2 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART2_RX              53
/* UART2 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART2_TX              52
/* UART3 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART3_RX              55
/* UART3 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART3_TX              54
/* UART4 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART4_RX              63
/* UART4 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART4_TX              62

/*
 * Below are Cross Bar Mapped Please redefine for any
 * simultaneous usecase in DMA Mode
 */

/* UART5 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART5_RX              51
/* UART5 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART5_TX              50
/* UART6 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART6_RX              51
/* UART6 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART6_TX              50
/* UART7 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART7_RX              51
/* UART7 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART7_TX              50
/* UART8 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART8_RX              51
/* UART8 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART8_TX              50
/* UART9 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART9_RX              51
/* UART9 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART9_TX              50

/* MCSPIx Channelx  */

/* MCSPI0 CHA0 Receive Event                                                  */
#define CSL_EDMA3_CHA0_MCSPI0_RX            35
/* MCSPI0 CHA0 Transmit Event                                                 */
#define CSL_EDMA3_CHA0_MCSPI0_TX            34
/* MCSPI0 CHA1 Receive Event                                                  */
#define CSL_EDMA3_CHA1_MCSPI0_RX            37
/* MCSPI0 CHA1 Transmit Event                                                 */
#define CSL_EDMA3_CHA1_MCSPI0_TX            36
/* MCSPI0 CHA2 Receive Event                                                  */
#define CSL_EDMA3_CHA2_MCSPI0_RX            39
/* MCSPI0 CHA2 Transmit Event                                                 */
#define CSL_EDMA3_CHA2_MCSPI0_TX            38
/* MCSPI0 CHA3 Receive Event                                                  */
#define CSL_EDMA3_CHA3_MCSPI0_RX            41
/* MCSPI0 CHA3 Transmit Event                                                 */
#define CSL_EDMA3_CHA3_MCSPI0_TX            40
/* MCSPI1 CHA0 Receive Event                                                  */
#define CSL_EDMA3_CHA0_MCSPI1_RX            43
/* MCSPI1 CHA0 Transmit Event                                                 */
#define CSL_EDMA3_CHA0_MCSPI1_TX            42
/* MCSPI1 CHA1 Receive Event                                                  */
#define CSL_EDMA3_CHA1_MCSPI1_RX            45
/* MCSPI1 CHA1 Transmit Event                                                 */
#define CSL_EDMA3_CHA1_MCSPI1_TX            44
/* MCSPI2 CHA0 Receive Event                                                  */
#define CSL_EDMA3_CHA0_MCSPI2_RX            15
/* MCSPI2 CHA0 Transmit Event                                                 */
#define CSL_EDMA3_CHA0_MCSPI2_TX            14
/* MCSPI2 CHA1 Receive Event                                                  */
#define CSL_EDMA3_CHA1_MCSPI2_RX            23
/* MCSPI2 CHA1 Transmit Event                                                 */
#define CSL_EDMA3_CHA1_MCSPI2_TX            22
/*
 * Cross Bar Mapped Please check before use
 */
/* MCSPI3 CHA0 Receive Event                                                  */
#define CSL_EDMA3_CHA0_MCSPI3_RX            23
/* MCSPI3 CHA0 Transmit Event                                                 */
#define CSL_EDMA3_CHA0_MCSPI3_TX            22

/** Peripheral related Info
 *
 *
 */

/*  MCSPI   */
#define CSL_MCSPI_0_NumOfPhyChannels       (4U)
#define CSL_MCSPI_1_NumOfPhyChannels       (2U)
#define CSL_MCSPI_2_NumOfPhyChannels       (2U)
#define CSL_MCSPI_3_NumOfPhyChannels       (1U)

#define CSL_MCASP_0_NumSerializers         (16)
#define CSL_MCASP_1_NumSerializers         (16)
#define CSL_MCASP_2_NumSerializers         (4)
#define CSL_MCASP_3_NumSerializers         (4)
#define CSL_MCASP_4_NumSerializers         (4)
#define CSL_MCASP_5_NumSerializers         (4)
#define CSL_MCASP_6_NumSerializers         (4)
#define CSL_MCASP_7_NumSerializers         (4)

/** @brief Enumeration for peripheral frequencies
 *
 *
 */

/** I2C      */
#define CSL_I2C_0_MODULE_FREQ               (96000000)
#define CSL_I2C_1_MODULE_FREQ               (96000000)
#define CSL_I2C_2_MODULE_FREQ               (96000000)
#define CSL_I2C_3_MODULE_FREQ               (96000000)
#define CSL_I2C_4_MODULE_FREQ               (96000000)

/** MCSPI      */
#define CSL_MCSPI_0_MODULE_FREQ             (48000000)
#define CSL_MCSPI_1_MODULE_FREQ             (48000000)
#define CSL_MCSPI_2_MODULE_FREQ             (48000000)
#define CSL_MCSPI_3_MODULE_FREQ             (48000000)

/** UART     */
#define CSL_UART_0_MODULE_FREQ              (48000000)
#define CSL_UART_1_MODULE_FREQ              (48000000)
#define CSL_UART_2_MODULE_FREQ              (48000000)
#define CSL_UART_3_MODULE_FREQ              (48000000)
#define CSL_UART_4_MODULE_FREQ              (48000000)
#define CSL_UART_5_MODULE_FREQ              (48000000)
#define CSL_UART_6_MODULE_FREQ              (48000000)
#define CSL_UART_7_MODULE_FREQ              (48000000)
#define CSL_UART_8_MODULE_FREQ              (48000000)
#define CSL_UART_9_MODULE_FREQ              (48000000)

#ifndef CSL_MODIFICATION
#define SOC_DSP_L1P_BASE                    (CSL_DSP_DSP_L1P_REGS)
#define SOC_DSP_L1D_BASE                    (CSL_DSP_DSP_L1D_REGS)
#define SOC_DSP_L2_BASE                     (CSL_DSP_DSP_L2_REGS)
#endif

#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_H */
