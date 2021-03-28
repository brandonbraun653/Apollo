/*
 *  Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
*  Copyright (C) 2017 Arasan Chip Systems Inc
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
/***************************************************************************
*
*  Description     : This header file contains function prototypes to read/write the host controller
*                          registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017   PB              0.1                 File structure creation
*  12-July-2017    PB              0.2                 Added function prototypes for CQ APIs
*  14-July-2017    PB              0.3                 Added macros for CQ APIs that are exposed to app
*  15-July-2017    PB              0.4                 Added function headers for CQ APIs
*  16-July-2017    PB              0.5                 Modified SD API function header information
*  18-July-2017    PB              0.6                 Added additional prototypes of SD APIs for ease
*                                                                 of configuration
*  28-July-2017    PB              1.0                 Modified for 64-bit addressing
*  11-Aug-2017    PB              1.1                 Added macros available to application for configuration
*  25-Aug-2017    PB              1.2                 Added macros for interrupt flags required for configuration
*                                                                 and modified structure members for stSDMMCHCCapability
*
***************************************************************************/
 /**
 *  \file   mmcsd.h
 *
 *  \brief  HS MMC/SD APIs and macros.
 *
 *   This file contains the driver API prototypes and macro definitions.
 */

#ifndef HS_MMCSD_H_
#define HS_MMCSD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Include Files                              */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_mmc.h>

/* ========================================================================== */
/*                            Macros                               */
/* ========================================================================== */

/*
* \brief Macros that can be used for forming the MMC/SD command
* Here\n
** cmd     : SD/MMC command number enumeration
** type    : specifies suspend upon CMD52 or resume upon CMD52 or abort upon
**           CMD52/12 or normal CMD
** restype : no response, or response with or without busy
** rw      : direction of data transfer
* @{
*/
#define HS_MMCSD_CMD(cmd, type, restype, rw)    ((cmd) << MMC_CMD_INDX_SHIFT | \
                                                 (type << MMC_CMD_CMD_TYPE_SHIFT) | (restype << MMC_CMD_RSP_TYPE_SHIFT) | (rw << MMC_CMD_DDIR_SHIFT))

#define HS_MMCSD_NO_RESPONSE            (MMC_CMD_RSP_TYPE_NORSP << \
                                         MMC_CMD_RSP_TYPE_SHIFT)
#define HS_MMCSD_136BITS_RESPONSE       (MMC_CMD_RSP_TYPE_LGHT36 << \
                                         MMC_CMD_RSP_TYPE_SHIFT)
#define HS_MMCSD_48BITS_RESPONSE        (MMC_CMD_RSP_TYPE_LGHT48 << \
                                         MMC_CMD_RSP_TYPE_SHIFT)
#define HS_MMCSD_48BITS_BUSY_RESPONSE   (MMC_CMD_RSP_TYPE_LGHT48B << \
                                         MMC_CMD_RSP_TYPE_SHIFT)

#define HS_MMCSD_CMD_TYPE_NORMAL        (MMC_CMD_CMD_TYPE_NORMAL << \
                                         MMC_CMD_CMD_TYPE_SHIFT)
#define HS_MMCSD_CMD_TYPE_SUSPEND       (MMC_CMD_CMD_TYPE_SUSPEND << \
                                         MMC_CMD_CMD_TYPE_SHIFT)
#define HS_MMCSD_CMD_TYPE_FUNCSEL       (MMC_CMD_CMD_TYPE_RESUME << \
                                         MMC_CMD_CMD_TYPE_SHIFT)
#define HS_MMCSD_CMD_TYPE_ABORT         (MMC_CMD_CMD_TYPE_ABORT << \
                                         MMC_CMD_CMD_TYPE_SHIFT)

#define HS_MMCSD_CMD_DIR_READ           (MMC_CMD_DDIR_READ << \
                                         MMC_CMD_DDIR_SHIFT)
#define HS_MMCSD_CMD_DIR_WRITE          (MMC_CMD_DDIR_WRITE << \
                                         MMC_CMD_DDIR_SHIFT)
#define HS_MMCSD_CMD_DIR_DONTCARE       (MMC_CMD_DDIR_WRITE << \
                                         MMC_CMD_DDIR_SHIFT)
/* @} */

/*
* \brief Macros that can be used for checking the present state of the host controller
* @{
*/
#define HS_MMCSD_CARD_WRITEPROT        (MMC_PSTATE_WP_MASK)
#define HS_MMCSD_CARD_INSERTED         (MMC_PSTATE_CINS_MASK)
#define HS_MMCSD_CARD_STABLE           (MMC_PSTATE_CSS_MASK)
#define HS_MMCSD_BUFFER_READABLE       (MMC_PSTATE_BRE_MASK)
#define HS_MMCSD_BUFFER_WRITEABLE      (MMC_PSTATE_BWE_MASK)
#define HS_MMCSD_READ_INPROGRESS       (MMC_PSTATE_RTA_MASK)
#define HS_MMCSD_WRITE_INPROGRESS      (MMC_PSTATE_WTA_MASK)
/* @} */

/*
* \brief Macros that can be used for configuring the power and transfer parameters
* @{
*/
#define HS_MMCSD_BUS_VOLT_1P8          (MMC_HCTL_SDVS_1V8)
#define HS_MMCSD_BUS_VOLT_3P0          (MMC_HCTL_SDVS_3V0)
#define HS_MMCSD_BUS_VOLT_3P3          (MMC_HCTL_SDVS_3V3)
#define HS_MMCSD_BUS_POWER_ON          (MMC_HCTL_SDBP_PWRON)
#define HS_MMCSD_BUS_POWER_OFF         (MMC_HCTL_SDBP_PWROFF)
#define HS_MMCSD_BUS_HIGHSPEED         (MMC_HCTL_HSPE_HIGHSPEED)
#define HS_MMCSD_BUS_STDSPEED          (MMC_HCTL_HSPE_NORMALSPEED)
/* @} */

/*
* \brief Macros that can be used for setting the clock, timeout values
* @{
*/
#define HS_MMCSD_DATA_TIMEOUT(n)        (((n) - 13) & 0xF)
#define HS_MMCSD_CLK_DIVIDER(n)         (((n) & 0x3FF) << MMC_SYSCTL_CLKD_SHIFT)
#define HS_MMCSD_CARDCLOCK_ENABLE       (MMC_SYSCTL_CEN_ENABLE)
#define HS_MMCSD_CARDCLOCK_DISABLE      (MMC_SYSCTL_CEN_DISABLE)
#define HS_MMCSD_INTCLOCK_ON            (MMC_SYSCTL_ICE_OSCILLATE)
#define HS_MMCSD_INTCLOCK_OFF           (MMC_SYSCTL_ICE_STOP)
/* @} */

/*
* \brief Macros that can be used for resetting controller lines
* @{
*/
#define HS_MMCSD_DATALINE_RESET         (MMC_SYSCTL_SRD_MASK)
#define HS_MMCSD_CMDLINE_RESET          (MMC_SYSCTL_SRC_MASK)
#define HS_MMCSD_ALL_RESET              (MMC_SYSCTL_SRA_MASK)
/* @} */

/*
* \brief Macros that can be used for interrupt enable/disable and status get
* operations
* @{
*/
#define HS_MMCSD_INTR_TARGETRESPERR	(MMC_STAT_TRERR_MASK)
#define HS_MMCSD_INTR_TUNINGERR		(MMC_STAT_TE_MASK)
#define HS_MMCSD_INTR_ADMAERROR         (MMC_STAT_ADMAE_MASK)
#define HS_MMCSD_INTR_ACMDERR         (MMC_STAT_ACE_MASK)
#define HS_MMCSD_INTR_DATABITERR        (MMC_STAT_DEB_MASK)
#define HS_MMCSD_INTR_DATACRCERR        (MMC_STAT_DCRC_MASK)
#define HS_MMCSD_INTR_DATATIMEOUT       (MMC_STAT_DTO_MASK)
#define HS_MMCSD_INTR_CMDINDXERR        (MMC_STAT_CIE_MASK)
#define HS_MMCSD_INTR_CMDBITERR         (MMC_STAT_CEB_MASK)
#define HS_MMCSD_INTR_CMDCRCERR         (MMC_STAT_CCRC_MASK)
#define HS_MMCSD_INTR_CMDTIMEOUT        (MMC_STAT_CTO_MASK)
#define HS_MMCSD_INTR_ERRINTR			(MMC_STAT_ERRI_MASK)
#define HS_MMCSD_INTR_BOOTTERMINATE	(MMC_STAT_BTI_MASK)
#define HS_MMCSD_INTR_BOOTACK		(MMC_STAT_BAR_MASK)
#define HS_MMCSD_INTR_RETUNE			(MMC_STAT_RTE_MASK)
#define HS_MMCSD_INTR_INTC			(MMC_STAT_INTC_MASK)
#define HS_MMCSD_INTR_INTB			(MMC_STAT_INTB_MASK)
#define HS_MMCSD_INTR_INTA			(MMC_STAT_INTA_MASK)
#define HS_MMCSD_INTR_CARDINTR		(MMC_STAT_CIRQ_MASK)
#define HS_MMCSD_INTR_CARDREMOVE		(MMC_STAT_CREM_MASK)
#define HS_MMCSD_INTR_CARDINS           (MMC_STAT_CINS_MASK)
#define HS_MMCSD_INTR_BUFRDRDY          (MMC_STAT_BRR_MASK)
#define HS_MMCSD_INTR_BUFWRRDY          (MMC_STAT_BWR_MASK)
#define HS_MMCSD_INTR_DMAINTR		(MMC_STAT_DMA_MASK)
#define HS_MMCSD_INTR_BLKGAPEVNT		(MMC_STAT_BGE_MASK)
#define HS_MMCSD_INTR_TRNFCOMP          (MMC_STAT_TC_MASK)
#define HS_MMCSD_INTR_CMDCOMP           (MMC_STAT_CC_MASK)
#define HS_MMCSD_INTR_ALL				((uint32_t)0x17ffffffU)

#define HS_MMCSD_STAT_TARGETRESPERR	(MMC_IE_TRERR_ENABLE_MASK)
#define HS_MMCSD_STAT_TUNINGERR		(MMC_IE_TE_ENABLE_MASK)
#define HS_MMCSD_STAT_ADMAERROR         (MMC_IE_ADMAE_ENABLE_MASK)
#define HS_MMCSD_STAT_ACMDERR         (MMC_IE_ACE_ENABLE_MASK)
#define HS_MMCSD_STAT_DATABITERR        (MMC_IE_DEB_ENABLE_MASK)
#define HS_MMCSD_STAT_DATACRCERR        (MMC_IE_DCRC_ENABLE_MASK)
#define HS_MMCSD_STAT_DATATIMEOUT       (MMC_IE_DTO_ENABLE_MASK)
#define HS_MMCSD_STAT_CMDINDXERR        (MMC_IE_CIE_ENABLE_MASK)
#define HS_MMCSD_STAT_CMDBITERR         (MMC_IE_CEB_ENABLE_MASK)
#define HS_MMCSD_STAT_CMDCRCERR         (MMC_IE_CCRC_ENABLE_MASK)
#define HS_MMCSD_STAT_CMDTIMEOUT        (MMC_IE_CTO_ENABLE_MASK)
#define HS_MMCSD_STAT_BOOTTERMINATE	(MMC_IE_BTI_ENABLE_MASK)
#define HS_MMCSD_STAT_BOOTACK		(MMC_IE_BAR_ENABLE_MASK)
#define HS_MMCSD_STAT_RETUNE			(MMC_IE_RTE_ENABLE_MASK)
#define HS_MMCSD_STAT_INTC			(MMC_IE_INTC_ENABLE_MASK)
#define HS_MMCSD_STAT_INTB			(MMC_IE_INTB_ENABLE_MASK)
#define HS_MMCSD_STAT_INTA			(MMC_IE_INTA_ENABLE_MASK)
#define HS_MMCSD_STAT_CARDINTR		(MMC_IE_CIRQ_ENABLE_MASK)
#define HS_MMCSD_STAT_CARDREMOVE	(MMC_IE_CREM_ENABLE_MASK)
#define HS_MMCSD_STAT_CARDINS           (MMC_IE_CINS_ENABLE_MASK)
#define HS_MMCSD_STAT_BUFRDRDY          (MMC_IE_BRR_ENABLE_MASK)
#define HS_MMCSD_STAT_BUFWRRDY          (MMC_IE_BWR_ENABLE_MASK)
#define HS_MMCSD_STAT_DMAINTR		(MMC_IE_DMA_ENABLE_MASK)
#define HS_MMCSD_STAT_BLKGAPEVNT		(MMC_IE_BGE_ENABLE_MASK)
#define HS_MMCSD_STAT_TRNFCOMP          (MMC_IE_TC_ENABLE_MASK)
#define HS_MMCSD_STAT_CMDCOMP           (MMC_IE_CC_ENABLE_MASK)
#define HS_MMCSD_STAT_ALL				((uint32_t)0x17ffffffU)

#define HS_MMCSD_SIGEN_TARGETRESPERR	(MMC_ISE_TRERR_SIGEN_MASK)
#define HS_MMCSD_SIGEN_TUNINGERR		(MMC_ISE_TE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_ADMAERROR        (MMC_ISE_ADMAE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_ACMD12ERR        (MMC_ISE_ACE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_DATABITERR       (MMC_ISE_DEB_SIGEN_MASK)
#define HS_MMCSD_SIGEN_DATACRCERR       (MMC_ISE_DCRC_SIGEN_MASK)
#define HS_MMCSD_SIGEN_DATATIMEOUT      (MMC_ISE_DTO_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CMDINDXERR       (MMC_ISE_CIE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CMDBITERR        (MMC_ISE_CEB_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CMDCRCERR        (MMC_ISE_CCRC_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CMDTIMEOUT       (MMC_ISE_CTO_SIGEN_MASK)
#define HS_MMCSD_SIGEN_BOOTTERMINATE	(MMC_ISE_BTI_SIGEN_MASK)
#define HS_MMCSD_SIGEN_BOOTACK		(MMC_ISE_BAR_SIGEN_MASK)
#define HS_MMCSD_SIGEN_RETUNE		(MMC_ISE_RTE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_INTC			(MMC_ISE_INTC_SIGEN_MASK)
#define HS_MMCSD_SIGEN_INTB			(MMC_ISE_INTB_SIGEN_MASK)
#define HS_MMCSD_SIGEN_INTA			(MMC_ISE_INTA_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CARDINTR		(MMC_ISE_CIRQ_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CARDREMOVE	(MMC_ISE_CREM_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CARDINS          (MMC_ISE_CINS_SIGEN_MASK)
#define HS_MMCSD_SIGEN_BUFRDRDY         (MMC_ISE_BRR_SIGEN_MASK)
#define HS_MMCSD_SIGEN_BUFWRRDY         (MMC_ISE_BWR_SIGEN_MASK)
#define HS_MMCSD_SIGEN_DMAINTR		(MMC_ISE_DMA_SIGEN_MASK)
#define HS_MMCSD_SIGEN_BLKGAPEVNT	(MMC_ISE_BGE_SIGEN_MASK)
#define HS_MMCSD_SIGEN_TRNFCOMP         (MMC_ISE_TC_SIGEN_MASK)
#define HS_MMCSD_SIGEN_CMDCOMP          (MMC_ISE_CC_SIGEN_MASK)
#define HS_MMCSD_SIGEN_ALL			((uint32_t)0x17ffffffU)
/* @} */

/*
* \brief Macros that can be used for ACMD interrupt status get
* operations
* @{
*/
#define HS_MMCSD_STAT_ACMD_NOEXECUTE    	(MMC_AC12_ACNE_MASK)
#define HS_MMCSD_STAT_ACMD_TIMEOUT		(MMC_AC12_ACTO_MASK)
#define HS_MMCSD_STAT_ACMD_CRCERR		(MMC_AC12_ACCE_MASK)
#define HS_MMCSD_STAT_ACMD_ENDBITERR	(MMC_AC12_ACEB_MASK)
#define HS_MMCSD_STAT_ACMD_INDEXERR		(MMC_AC12_ACIE_MASK)
#define HS_MMCSD_STAT_ACMD_NOCMD		(MMC_AC12_CNI_MASK)
#define HS_MMCSD_STAT_ACMD_ALL			((uint32_t)0x9fU)
/* @} */


/*
* \brief Macros that can be used for checking the capabilites of the controller
* @{
*/
#define HS_MMCSD_SUPPORT_VOLT_1P8       (MMC_CAPA_VS18_MASK)
#define HS_MMCSD_SUPPORT_VOLT_3P0       (MMC_CAPA_VS30_MASK)
#define HS_MMCSD_SUPPORT_VOLT_3P3       (MMC_CAPA_VS33_MASK)
#define HS_MMCSD_SUPPORT_HIGHSPEED      (MMC_CAPA_HSS_MASK)
#define HS_MMCSD_SUPPORT_BLOCKLEN       (MMC_CAPA_MBL_MASK)
/* @} */

/*
* \brief Macros that can be used for selecting the bus/data width
* @{
*/
#define HS_MMCSD_BUS_WIDTH_4BIT    (0x4U)
#define HS_MMCSD_BUS_WIDTH_8BIT    (0x8U)
#define HS_MMCSD_BUS_WIDTH_1BIT    (0x1U)
/* @} */

/*
* \brief Macros that can be used for selecting the UHS mode
* @{
*/
#define HS_MMCSD_UHS_MODE_SDR12                                (MMC_AC12_UHSMS_SDR12)
#define HS_MMCSD_UHS_MODE_SDR25                                (MMC_AC12_UHSMS_SDR25)
#define HS_MMCSD_UHS_MODE_SDR50                                (MMC_AC12_UHSMS_SDR50)
#define HS_MMCSD_UHS_MODE_SDR104                              (MMC_AC12_UHSMS_SDR104)
#define HS_MMCSD_UHS_MODE_DDR50                                (MMC_AC12_UHSMS_DDR50)
#define HS_MMCSD_UHS_MODE_HS400                                (MMC_AC12_UHSMS_HS400)
/* @} */

/*
* \brief Macros that can be used for boot mode configuration
* @{
*/
#define HS_MMCSD_BOOT_MODE_NORMAL                   ((uint32_t)0U)
#define HS_MMCSD_BOOT_MODE_BOOT                        ((uint32_t)1U)
#define HS_MMCSD_BOOT_MODE_ALTBOOT                  ((uint32_t)2U)

#define HS_MMCSD_BOOT_ACK_WAIT                          (MMC_HCTL_WAIT_BOOT_ACK)
#define HS_MMCSD_BOOT_ACK_NOWAIT                     (MMC_HCTL_NOWAIT_BOOT_ACK)
/* @} */

/*
* \brief Macros that can be used for host controller capabilities
* @{
*/
#define HS_MMCSD_TIMEOUT_CLK_FREQ                     (MMC_CAPA_TCF_MASK)
#define HS_MMCSD_TIMEOUT_CLK_UNIT                     (MMC_CAPA_TCU_MASK)
#define HS_MMCSD_BASE_CLK_FREQ_SD                     (MMC_CAPA_BCF_MASK)
#define HS_MMCSD_MAX_BLOCK_LENGTH                    (MMC_CAPA_MBL_MASK)
#define HS_MMCSD_EXTENDED_MEDIA_BUS               (MMC_CAPA_EMBS_MASK)
#define HS_MMCSD_ADMA2_SUPPORT                          (MMC_CAPA_AD2S_MASK)
#define HS_MMCSD_HS_SUPPORT                                 (MMC_CAPA_HSS_MASK)
#define HS_MMCSD_SDMA_SUPPORT                            (MMC_CAPA_SDMAS_MASK)
#define HS_MMCSD_SUSPEND_RESUME_SUPPORT        (MMC_CAPA_SRS_MASK)
#define HS_MMCSD_VOLT_3V3_SUPPORT                     (MMC_CAPA_VS33_MASK)
#define HS_MMCSD_VOLT_3V0_SUPPORT                     (MMC_CAPA_VS30_MASK)
#define HS_MMCSD_VOLT_1V8_SUPPORT                     (MMC_CAPA_VS18_MASK)
#define HS_MMCSD_64BIT_SYSTEMBUS_SUPPORT       (MMC_CAPA_BIT64_MASK)
#define HS_MMCSD_ASYNC_INTR_SUPPORT                 (MMC_CAPA_AIS_MASK)
#define HS_MMCSD_SLOT_TYPE                                   (MMC_CAPA_SLOT_TYPE_MASK)
#define HS_MMCSD_SDR50_SUPPORT                           (MMC_CAPA2_SDR50_MASK)
#define HS_MMCSD_SDR104_SUPPORT                         (MMC_CAPA2_SDR104_MASK)
#define HS_MMCSD_DDR50_SUPPORT                           (MMC_CAPA2_DDR50_MASK)
#define HS_MMCSD_DRIVER_TYPEA_SUPPORT             (MMC_CAPA2_DTA_MASK)
#define HS_MMCSD_DRIVER_TYPEC_SUPPORT             (MMC_CAPA2_DTC_MASK)
#define HS_MMCSD_DRIVER_TYPED_SUPPORT             (MMC_CAPA2_DTD_MASK)
#define HS_MMCSD_DRIVER_TYPE4_SUPPORT             (MMC_CAPA2_DT4_MASK)
#define HS_MMCSD_TIMER_COUNT_RETUNING            (MMC_CAPA2_TCRT_MASK)
#define HS_MMCSD_USE_TUNING_SDR50                    (MMC_CAPA2_TSDR50_MASK)
#define HS_MMCSD_RETUNING_MODES                        (MMC_CAPA2_RTM_MASK)
#define HS_MMCSD_CLOCK_MULTIPLIER                      (MMC_CAPA2_CM_MASK)
#define HS_MMCSD_SPI_MODE                                     (MMC_CAPA2_SPI_MODE_MASK)
#define HS_MMCSD_SPI_BLOCK_MODE                         (MMC_CAPA2_SPI_BMODE_MASK)
#define HS_MMCSD_HS400_SUPPORT                           (MMC_CAPA2_HS400S_MASK)
#define HS_MMCSD_CAPA_ALL                                      ((uint32_t)0xffffffffU)
/* @} */


/*
* \brief Macros that are used for Command Queuing
* @{
*/
#define HS_MMCSD_CQ_ENABLE                        (MMC_CQCFG_CQEN_ENABLE)
#define HS_MMCSD_CQ_DISABLE                      (MMC_CQCFG_CQEN_DISABLE)
#define HS_MMCSD_CQ_DESC_128BIT              ((uint32_t)128U)
#define HS_MMCSD_CQ_DESC_64BIT                ((uint32_t)64U)

#define HS_MMCSD_CQ_CLEAR_ALL_TASK        ((uint32_t)32U)

#define HS_MMCSD_CQ_INTR_HALT_COMPLETE                   (MMC_CQIS_HAC_MASK)
#define HS_MMCSD_CQ_INTR_TASK_COMPLETE                   (MMC_CQIS_TCC_MASK)
#define HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED             (MMC_CQIS_RED_MASK)
#define HS_MMCSD_CQ_INTR_TASK_CLEARED                     (MMC_CQIS_TCL_MASK)
#define HS_MMCSD_CQ_INTR_ALL                                        ((uint32_t)0xfU)

#define HS_MMCSD_CQ_IC_ENABLE                                      (MMC_CQIC_ICEN_ENABLE)
#define HS_MMCSD_CQ_IC_DISABLE                                     (MMC_CQIC_ICEN_DISABLE)

#define HS_MMCSD_CQ_IC_MIN_COUNT                               ((uint32_t)0U)
#define HS_MMCSD_CQ_IC_MAX_COUNT                               ((uint32_t)32U)
#define HS_MMCSD_CQ_IC_MIN_TIMEOUT                           ((uint32_t)0U)
#define HS_MMCSD_CQ_IC_MAX_TIMEOUT                           ((uint32_t)0x7fU)

#define HS_MMCSD_CQ_SSC_MIN_COUNT                             ((uint32_t)0U)
#define HS_MMCSD_CQ_SSC_MAX_COUNT                            ((uint32_t)15U)
#define HS_MMCSD_CQ_SSC_MIN_TIMER                              ((uint32_t)1U)
#define HS_MMCSD_CQ_SSC_MAX_TIMER                             ((uint32_t)0xffffU)
#define HS_MMCSD_CQ_SSC_MIN_RCA                                 ((uint32_t)1U)
#define HS_MMCSD_CQ_SSC_MAX_RCA                                 ((uint32_t)0xffffU)
/* @} */

/*
* \brief Macros that are used for Block gap configuration
* @{
*/
#define HS_MMCSD_BLOCKGAP_STOP_REQ_ENABLE     ((uint32_t)1U)
#define HS_MMCSD_BLOCKGAP_STOP_REQ_DISABLE    ((uint32_t)0U)
#define HS_MMCSD_BLOCKGAP_CONT_REQ_ENABLE     ((uint32_t)2U)
#define HS_MMCSD_BLOCKGAP_RD_WAIT_ENABLE       ((uint32_t)3U)
#define HS_MMCSD_BLOCKGAP_RD_WAIT_DISABLE      ((uint32_t)4U)
/* @} */

/*
* \brief Macros that are used for Asynchornous interrupt configuration
* @{
*/
#define HS_MMCSD_ASYN_INTR_ENABLE                      (MMC_AC12_AI_ENABLE_ENABLED)
#define HS_MMCSD_ASYN_INTR_DISABLE                    (MMC_AC12_AI_ENABLE_DISABLED)
/* @} */

/*
* \brief Macros that are used for HS400 strobe
* @{
*/
#define HS_MMCSD_VREG_STROBE_ENABLE                 (MMC_VREG_STROBE_ENABLE)
#define HS_MMCSD_VREG_STROBE_DISABLE               (MMC_VREG_STROBE_DISABLE)
/* @} */

/*
* \brief Macros that are used for bus signal configuration
* @{
*/
#define HS_MMCSD_SIGNAL_VOLT_1V8                       (MMC_AC12_V1V8_SIGEN_1V8)
#define HS_MMCSD_SIGNAL_VOLT_3V3                       (MMC_AC12_V1V8_SIGEN_3V3)
/* @} */

/*
* \brief Macros that are used for re-tuning
* @{
*/
#define HS_MMCSD_EXEC_TUNING_ENABLE                 (MMC_AC12_ET_EXECUTE)
#define HS_MMCSD_EXEC_TUNING_DISABLE               (MMC_AC12_ET_COMPLETED)
#define HS_MMCSD_CLCK_SELECT_ENABLE                  (MMC_AC12_SCLK_SEL_TUNED)
#define HS_MMCSD_CLCK_SELECT_DISABLE                (MMC_AC12_SCLK_SEL_FIXED)
/* @} */

/*
* \brief Macros that are used for hard resetting emmc card
* @{
*/
#define HS_MMCSD_EMMC_HARD_RESET_ENABLE		(MMC_HCTL_EMMC_HW_RST_SET)
#define HS_MMCSD_EMMC_HARD_RESET_DISABLE		(MMC_HCTL_EMMC_HW_RST_CLEAR)
/* @} */

/*
* \brief Macros that are used for sdma configuration
* @{
*/
#define HS_MMCSD_DMA_TYPE_SDMA					(MMC_HCTL_DMAS_SDMA)
#define HS_MMCSD_DMA_TYPE_ADMA2_32BIT			(MMC_HCTL_DMAS_ADMA2_32BIT)
#define HS_MMCSD_DMA_TYPE_ADMA2_64BIT			(MMC_HCTL_DMAS_ADMA2_64BIT)
/* @} */

/*
* \brief Macros that are used for return status
* @{
*/
#define STW_EPRECONDITION_FAIL          (-((int32_t) 8))
/* @} */


/* ========================================================================== */
/*                          Structure Definitions                             */
/* ========================================================================== */

/*
* \brief Structure to read the host controller version data for sd and cq
* @{
*/
typedef struct {
	uint8_t vendorVer;
	uint8_t specVer;
	uint8_t cqMajorVer;
	uint8_t cqMinorVer;
	uint8_t cqSuffixVer;
} stSDMMCHCVersion;
/* @} */

/*
* \brief Structure to read the host controller capabilities data.
* flag1 corresponds to Host Capability Register1 and flag2 corresponds to Host Capability Register2
* The capability flag to be read is set in flag1 and flag2.
* The data corresponding to flag1 is returned in retValue1 and data corresponding to flag2 is returned in retValue2
* @{
*/
typedef struct {
	uint32_t flag1; //Capability1 to be read from host controller register CAPA1
	uint32_t flag2; //Capability2 to be read from host controller register CAPA2
	uint32_t retValue1;  //variable filled with value of capability1
	uint32_t retValue2;  //variable filled with value of capability2
}stSDMMCHCCapability;
/* @} */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Read version of Host controller.
 *
 *	This API fetches the version information for SD Host controller and CQ.
 *	The format of the structure is: \n
 *  struct{ \n
 *			uint8_t vendorVer; \n
 *			uint8_t specVer; \n
 *			uint8_t cqMajorVer; \n
 *			uint8_t cqMinorVer; \n
 *			uint8_t cqSufficVer; \n
 *			} stSDMMCHCVersion; \n
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   verInfo        Pointer to instance of stSDMMCHCVersion structure to be filled.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDHCVersion(uintptr_t baseAddr, stSDMMCHCVersion *verInfo);

/**
 * \brief   Soft reset the MMC/SD controller
 *
 *	This API soft resets the host controller except the card detection circuit.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSoftReset(uintptr_t baseAddr);

/**
 * \brief   Hard reset the eMMC card.
 *
 *	This API hard resets the eMMC card by driving the reset pin to the card.
 *	The application will need to first set and then clear the reset state for the
 *	hard reset to complete.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag          Value to set or clear driving of reset line to eMMC card. \n
 *
 * \range	for flag: \n   MMC_HCTL_EMMC_HW_RST_SET - 0x00000001 \n
 *					   	   MMC_HCTL_EMMC_HW_RST_CLEAR - 0x00000000
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDeMMCardHardReset(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Soft reset the MMC/SD controller lines.
 *
 *	This API allows soft reset of CMD, DATA or All circuits in the host
 *	controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag          32-bit value to reset CMD, DATA or All circuits. \n
 *
 * \range   for flag: \n  HS_MMCSD_DATALINE_RESET - 0x04000000 \n
 * 						  HS_MMCSD_CMDLINE_RESET - 0x02000000 \n
 * 						  HS_MMCSD_ALL_RESET - 0x01000000
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDLinesReset(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Configure the MMC/SD controller standby, idle and wakeup modes.
 *
 *	This API configures platform/systemconfiguration which is required prior
 *	to initializing the host controller. This API is to be defined by the
 *	platform vendor and is provided as a placeholder for platform specific
 *	configuration required for Host controller.
 *
 * \param   baseAddr      Base addressis platform specific and provided by the
 *							application.
 *
 * \param   config        Platform specific configuration value.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \note    The system configuration parameter structure is defined by the
 *           application platform.
 **/
int32_t HSMMCSDSystemConfig(uintptr_t baseAddr, const uint32_t *config);

/**
 * \brief   Read Host Controller capabilities.
 *
 *	This API reads the host controller capability and returns its value. The
 *	format of the structure is: \n
 *	typedef struct { \n
 *					uint32_t flag1; \n
 *					uint32_t flag2; \n
 *					uint32_t retValue1; \n
 *					uint32_t retValue2; \n
 *					}stSDMMCHCCapability; \n
 *
 * \param   baseAddr      Base address is platform specific and provided by the
 *							application.
 *
 * \param   hcCapab      Pointer to structure of type stSDMMCHCCapability having
 *							following members: \n
 *							flag1 – Capability1 field flags which is to be read \n
 *							flag2 – Capability2 field flags which is to be read \n
 *							retValue1–Variable to be filled with capability1 field \n
 *							retValue2 – Variable to be filled with capability2 field. \n
 *
 * \range	for flag1: \n
 *						HS_MMCSD_TIMEOUT_CLK_FREQ - 0x0000003f \n
 *						HS_MMCSD_TIMEOUT_CLK_UNIT - 0x00000080 \n
 *						HS_MMCSD_BASE_CLK_FREQ_SD - 0x0000ff00 \n
 *						HS_MMCSD_MAX_BLOCK_LENGTH - 0x00030000 \n
 *						HS_MMCSD_EXTENDED_MEDIA_BUS - 0x00040000 \n
 *						HS_MMCSD_ADMA2_SUPPORT - 0x00080000 \n
 *						HS_MMCSD_HS_SUPPORT - 0x00200000 \n
 *						HS_MMCSD_SDMA_SUPPORT - 0x00400000 \n
 *						HS_MMCSD_SUSPEND_RESUME_SUPPORT - 0x00800000 \n
 *						HS_MMCSD_VOLT_3V3_SUPPORT - 0x01000000 \n
 *						HS_MMCSD_VOLT_3V0_SUPPORT - 0x02000000 \n
 *						HS_MMCSD_VOLT_1V8_SUPPORT - 0x04000000 \n
 *						HS_MMCSD_64BIT_SYSTEMBUS_SUPPORT - 0x10000000 \n
 *						HS_MMCSD_ASYNC_INTR_SUPPORT - 0x20000000 \n
 *						HS_MMCSD_SLOT_TYPE - 0xc0000000	\n
 *						HS_MMCSD_CAPA_ALL - 0xffffffff \n \n
 *     	   for flag2: \n
 *						HS_MMCSD_SDR50_SUPPORT - 0x00000001 \n
 *						HS_MMCSD_SDR104_SUPPORT - 0x00000002 \n
 *						HS_MMCSD_DDR50_SUPPORT - 0x00000004 \n
 *						HS_MMCSD_DRIVER_TYPEA_SUPPORT - 0x00000010 \n
 * 						HS_MMCSD_DRIVER_TYPEC_SUPPORT - 0x00000020 \n
 *						HS_MMCSD_DRIVER_TYPED_SUPPORT - 0x00000040 \n
 *						HS_MMCSD_DRIVER_TYPE4_SUPPORT - 0x00000080 \n
 *						HS_MMCSD_TIMER_COUNT_RETUNING - 0x00000f00 \n
 *						HS_MMCSD_USE_TUNING_SDR50 - 0x00002000 \n
 *						HS_MMCSD_RETUNING_MODES - 0x0000c000 \n
 *						HS_MMCSD_CLOCK_MULTIPLIER - 0x00ff0000 \n
 *						HS_MMCSD_SPI_MODE - 0x01000000 \n
 *						HS_MMCSD_SPI_BLOCK_MODE - 0x02000000 \n
 *						HS_MMCSD_HS400_SUPPORT - 0x80000000 \n
 *						HS_MMCSD_CAPA_ALL - 0xffffffff \n
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDHostCapabilityGet(uintptr_t baseAddr, stSDMMCHCCapability *hcCapab);
/**
 * \brief   Configure controller for signal voltage.
 *
 *	This API switches the signaling voltage in the host controller. The signaling
 *	voltage stabilizesafter 5ms of the change.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag           Signal voltage flag. \n
 *
 * \range   for flag: \n   MMC_AC12_V1V8_SIGEN_1V8 - 0x1 \n
 *						   MMC_AC12_V1V8_SIGEN_3V3 - 0x0
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSwitchSignalVoltage(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Configure UHS mode in controller.
 *
 *	This API configures the host controller in the specified UHS mode.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   mode            Value of UHS modes. \n
 *
 * \range	for mode: \n		   MMC_AC12_UHSMS_SDR12 - 0x0 \n
 *								   MMC_AC12_UHSMS_SDR25 - 0x1 \n
 *								   MMC_AC12_UHSMS_SDR50 - 0x2 \n
 *	   							   MMC_AC12_UHSMS_SDR104 - 0x3 \n
 *								   MMC_AC12_UHSMS_DDR50 - 0x4 \n
 *								   MMC_AC12_UHSMS_HS400 - 0x5
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDUhsModeSet(uintptr_t baseAddr, uint32_t mode);

/**
 * \brief   Configure Boot mode in controller
 *
 *	This API configures the host controller for boot mode settings.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   bootMode      Boot mode type.
 *
 * \param   bootAck       Boot Ack check enable / disable.
 *
 * \param   timeout       Boot mode data timeout value.
 *
 * \range	for bootMode: \n	 HS_MMCSD_BOOT_MODE_NORMAL - 0x0 \n
 *								 HS_MMCSD_BOOT_MODE_BOOT - 0x1 \n
 *								 HS_MMCSD_BOOT_MODE_ALTBOOT - 0x2 \n \n
 *   		for bootAck: \n      HS_MMCSD_BOOT_ACK_WAIT - 0x1 \n
 *								 HS_MMCSD_BOOT_ACK_NOWAIT - 0x0 \n \n
 * 			for timeout: \n      0x00000000 - 0xffffffff
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBootModeSet(uintptr_t baseAddr, uint32_t bootMode,
                                                            uint32_t bootAck, uint32_t timeout);

/**
 * \brief   Configure Block gap control in controller.
 *
 *	This API enables / disables the block gap control for a multi block data
 *	transfer request.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag          Control block gap request. \n
 *
 * \range    for flag: \n  HS_MMCSD_BLOCKGAP_STOP_REQ_DISABLE - 0x0 \n
 *						  HS_MMCSD_BLOCKGAP_STOP_REQ_ENABLE - 0x1 \n
 *						  HS_MMCSD_BLOCKGAP_CONT_REQ_ENABLE - 0x2 \n
 *						  HS_MMCSD_BLOCKGAP_RD_WAIT_ENABLE - 0x3 \n
 *						  HS_MMCSD_BLOCKGAP_RD_WAIT_DISABLE - 0x4
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBlockGapControl(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Wake up control control configure in controller.
 *
 *	This API configures the host controller for wake-up events on card
 *	interrupt, card removal and card insertion. The voltage on SD bus will
 *	need to be maintained when wakeup events are configured.
 *
 * \param   baseAddr       Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag            Wake up control bits. The bits can be OR’ed as per below table and
 *							then sent to the API by the application. E.g. 0x7 enables all the bits. \n
 *
 * \range   for flag: \n    Bit2 - 0x01 - Enable Wake up on SD card removal \n
 *										  0x00 - Disable Wake up on SD card removal	 \n
 *								   Bit1 - 0x01 - Enable Wake up on SD card insertion \n
 *										  0x00 - Disable Wake up on SD card insertion \n
 *								   Bit0 - 0x01 - Enable Wake up on card interrupt \n
 *										  0x00 - Disable Wake up on card interrupt
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDWakeUpControl(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Configure Async interrupt in controller.
 *
 *	This API configures the host controller for receiving asynchronous
 *	interrupts. Once async interrupt is enabled, the SDCLK can be stopped to
 *	save power but still receive interrupts from the card.
 *
 * \param   baseAddr     Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   state         Async interrupt enable / disable. \n
 *
 * \range   for state: \n MMC_AC12_AI_ENABLE_ENABLED - 0x1 \n
 *						  MMC_AC12_AI_ENABLE_DISABLED - 0x0
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDAsyncInterruptSet(uintptr_t baseAddr, uint32_t state);

/**
 * \brief   Configure the MMC/SD bus width.
 *
 *	This API configures the bus width on host controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   width         bus width. \n
 *
 * \range   for width: \n   HS_MMCSD_BUS_WIDTH_8BIT - 0x8 \n
 * 							HS_MMCSD_BUS_WIDTH_4BIT - 0x4 \n
 *    						HS_MMCSD_BUS_WIDTH_1BIT - 0x1
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBusWidthSet(uintptr_t baseAddr, uint32_t width);

/**
 * \brief   Configure the MMC/SD bus voltage.
 *
 *	This API configures bus voltage on host controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   volt          bus voltage value. \n
 *
 * \range   for volt: \n    HS_MMCSD_BUS_VOLT_1P8 - 0x5 \n
 *     					    HS_MMCSD_BUS_VOLT_3P0 - 0x6 \n
 *						    HS_MMCSD_BUS_VOLT_3P3 - 0x7
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBusVoltGet(uintptr_t baseAddr);
/**
 * \brief   Configure the MMC/SD bus voltage.
 *
 *	This API configures bus voltage on host controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   volt          bus voltage value. \n
 *
 * \range   for volt: \n    HS_MMCSD_BUS_VOLT_1P8 - 0x5 \n
 *     					    HS_MMCSD_BUS_VOLT_3P0 - 0x6 \n
 *						    HS_MMCSD_BUS_VOLT_3P3 - 0x7
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBusVoltSet(uintptr_t baseAddr, uint32_t volt);

/**
 * \brief   Turn MMC/SD bus power on / off.
 *
 *	This API configures bus power ON / OFF state on host controller.
 *
 * \param   baseAddr    host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   pwr         power value. \n
 *
 * \range   for pwr: \n    HS_MMCSD_BUS_POWER_ON - 0x1 \n
 *     					   HS_MMCSD_BUS_POWER_OFF - 0x0
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBusPower(uintptr_t baseAddr, uint32_t pwr);

/**
 * \brief   Turn Internal clocks on / off.
 *
 *	This API configures the internal clock state of the host controller.
 *
 * \param   baseAddr    host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   clkState    internal clock state. \n
 *
 * \range    for clkState: \n      HS_MMCSD_INTCLOCK_ON - 0x1 \n
 *     						       HS_MMCSD_INTCLOCK_OFF - 0x0
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDIntClock(uintptr_t baseAddr, uint32_t clkState);

/**
 * \brief   Get the internal clock stable status.
 *
 *	This API checks for stability of the Host controller’s internal clock.
 *
 * \param   baseAddr    host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retry       Retry count to wait for clock to be stable.
 *
 *
 * \return   Clock state or error codes as defined by macro STW_xxxx. \n
 *
 * \range    for return value: \n   MMC_SYSCTL_ICS_NOTREADY - 0x0 \n
 *				   					MMC_SYSCTL_ICS_READY - 0x1
 *
 * \note  if retry is zero the status is not polled. If it is non-zero status
 *        is polled for retry times.
 **/
int32_t HSMMCSDIsIntClockStable(uintptr_t baseAddr, uint32_t retry);

/**
 * \brief   Set the supported voltage list.
 *
 *	This API configures the Host controller to indicate the voltages
 *	supported.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   volt        Value to enable/disable voltage support in Host controller. \n
 *
 * \range	for volt: \n  	   HS_MMCSD_SUPPORT_VOLT_1P8 - 0x04000000  \n
 *     						   HS_MMCSD_SUPPORT_VOLT_3P0 - 0x02000000  \n
 *     						   HS_MMCSD_SUPPORT_VOLT_3P3 - 0x01000000
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSupportedVoltSet(uintptr_t baseAddr, uint32_t volt);

/**
 * \brief   Check if the controller supports high speed
 *
 *	This API checks Host controller for high speed mode.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return   High speed capability status or error codes as defined by macro STW_xxxx.  \n
 *
 * \range     for return value: \n   MMC_CAPA_HSS_NOTSUPPORTED - 0x0  \n
 *          						 MMC_CAPA_HSS_SUPPORTED - 0x1
 *
 **/
int32_t HSMMCSDIsHSupported(uintptr_t baseAddr);

/**
 * \brief   Configure the controller for high/normal speed.
 *
 *	This API configures the Host controller for high speed or normal modes.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag          HS mode enable / disable. \n
 *
 * \range   for flag: \n    MMC_HCTL_HSPE_HIGHSPEED - 0x1 \n
 *							MMC_HCTL_HSPE_NORMALSPEED - 0x0
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDHSModeSet(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Configure the controller for Host DMA mode.
 *
 *	This API configures the Host controller for specified DMA mode.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of DMA mode. \n
 *
 * \range   for flag: \n    MMC_HCTL_DMAS_SDMA - 0x0 \n
 *							MMC_HCTL_DMAS_ADMA2_32BIT - 0x2 \n
 *							MMC_HCTL_DMAS_ADMA2_64BIT - 0x3
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/

int32_t HSMMCSDDmaSelect(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief    Length (16 bit/26 bit).
 *
 *	This API configures the maximum ADMA transfer length (16/26 bit)
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.

 * \length_mode        length mode. (MMC_ADMA2_LENGTH_MODE_16/26BIT)
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDAdmaLengthSelect(uintptr_t baseAddr, uint32_t length_mode);

/**
 * \brief    Selects the VER4.x mode of MMC controller.
 *
 *	This API sets the version 4.x for the MMC controller
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.

 * \sel                MMC_AC12_HOSTVER4_ENABLE/DISABLE
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDHostVer4Select(uintptr_t baseAddr, uint32_t sel);

/**
 * \brief   Set data timeout value.
 *
 *	This API configures Host controller for DAT line timeout value.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.

 * \param   timeout     data line timeout value. \n
 *
 * \range   for timeout: \n   0x0 - 0xe
 *
 * \return  Success/Error code as defined by macro STW_xxxx.
 *
 * \note    Timeout value is the exponential of 2, as mentioned in the controller
 * reference manual. Please use HS_MMCSD_DATA_TIMEOUT(n) for setting this value\n
 * 13 <= n <= 27.
 *
 **/
int32_t HSMMCSDDataTimeoutSet(uintptr_t baseAddr, uint32_t timeout);

/**
 * \brief   Set output bus frequency.
 *
 *	This API configures the output bus frequency on the Host controller. If
 *	the frequency is set correctly, the clocks are enabled on the SD bus.
 *
 * \param   baseAddr        Host controller register set base address. This base address
 * 							is platform specific and provided by the application.
 *
 * \param   freq_in       The input reference frequency in Hz to the controller.
 *
 * \param   freq_out      The required output frequency in Hz on the bus.
 *
 * \param   bypass        If reference clock is to be bypassed on bus. \n
 *
 * \range    for bypass: \n   Bypass reference clock - 0x1 \n
 *							  Reference clock not bypassed - 0x0
 *
 * \return    Success/Error code as defined by macro STW_xxxx.
 *
 * \note  If the clock is set properly, the clocks are enabled to the card with
 * the return of this function.
 *
 **/
int32_t HSMMCSDBusFreqSet(uintptr_t baseAddr, uint32_t freq_in,
                          uint32_t freq_out, uint32_t bypass);


/**
 * \brief   Enables the controller events to set flags in status register.
 *
 *	This API enables the relevant interrupt status bit in the interrupt status
 * 	enable register.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of the interrupt to be enabled. The interrupt flags can be
 * 						Or’ed to enable multiple interrupts in single call.  \n
 *
 * \range   for flag: \n   Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002 \n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000 \n
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \note This function only enables the reflection of events in status
 * register. To enable events to generate a h/w interrupt request
 * \see HSMMCSDIntrEnable().
 *
 **/
int32_t HSMMCSDIntrStatusEnable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Disables the controller events to set flags in status register.
 *
 *	This API disables the relevant interrupt status bit in the interrupt status
 * 	enable register.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of the interrupt to be disabled. The interrupt flags can be
 * 						Or’ed to disable multiple interrupts in single call. \n
 *
 * \range   for flag: \n    Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002 \n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000 \n
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \note This function only enables the reflection of events in status
 * register. To enable events to generate a h/w interrupt request
 * \see HSMMCSDIntrEnable().
 *
 **/
int32_t HSMMCSDIntrStatusDisable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Enables the controller signal to generate a h/w interrupt request.
 *
 *	This API enables the hardware interrupt signal bit in the interrupt signal
 *	enable register.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of the interrupt to be enabled. The interrupt flags can be
 * 						Or’ed to enable multiple interrupts in single call. \n
 *
 * \range   for flag: \n   Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002 \n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000 \n
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDIntrEnable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Disables the controller signal to generate a h/w interrupt request.
 *
 *	This API disables the hardware interrupt signal bit in the interrupt signal
 *	enable register.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of the interrupt to be disabled. The interrupt flags can be
 * 						Or’ed to disable multiple interrupts in single call. \n
 *
 * \range   for flag: \n  Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002 \n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000 \n
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDIntrDisable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Gets the Interrupt enable register.
 *
 *	This API reads the interrupt enable register .
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \return    The value of the interrupt enable register.
 *
 **/
int32_t HSMMCSDIntrGet(uintptr_t baseAddr);

/**
 * \brief   Gets the status bits from the controller.
 *
 *	This API reads the host controller’s interrupt status register to check for
 *	any interrupt flag being set
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of the interrupt status to be read. The interrupt flags can be
 * 						Or’ed to read multiple interrupt status in single call. \n
 *
 * \range   for flag: \n   Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002 \n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000 \n
 *						All interrupts - 0xffffffff
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx. \n
 *
 * \return    Success/Error code as defined by macro STW_xxxx. \n
 *
 * \range     for return value: \n
 *				Interrupt not set corresponding to flag bit - 0x0 \n
 * 				Interrupt set corresponding to flag bit - 0x1
 *
 **/
int32_t HSMMCSDIntrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue);

/**
 * \brief   Clear the status bits from the controller.
 *
 *	This API clears the interrupt status bit in the interrupt status register
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag        Value of interrupt to be cleared. The interrupt flags can be
 * 						Or’ed to clear multiple interrupt signals in single call. \n
 *
 * \range   for flag: \n    Command complete - 0x00000001 \n
 * 						Transfer complete - 0x00000002\n
 *						Block gap event - 0x00000004 \n
 *						DMA Interrupt - 0x00000008 \n
 *						Buffer write ready - 0x00000010 \n
 * 						Buffer read ready - 0x00000020 \n
 *						Card Insertion - 0x00000040 \n
 * 						Card removal - 0x00000080 \n
 * 						Card interrupt - 0x00000100 \n
 *						INT_A - 0x00000200 \n
 *						INT_B - 0x00000400 \n
 *						INT_C - 0x00000800 \n
 *						Re-tuning event - 0x00001000 \n
 *						Boot Ack Received - 0x00002000 \n
 *						Boot terminate - 0x00004000 \n
 *						Command timeout error - 0x00010000 \n
 *						Command CRC error - 0x00020000 \n
 *						Command end bit error - 0x00040000 \n
 *						Command Index error - 0x00080000 \n
 *						Data Timeout error - 0x00100000 \n
 *						Data CRC error - 0x00200000 \n
 *						Data End bit error - 0x00400000 \n
 *						Current Limit error - 0x00800000 \n
 *						Auto CMD error - 0x01000000 \n
 *						ADMA error - 0x02000000 \n
 *						Tuning error - 0x04000000 \n
 *						Target Response error - 0x10000000
 * flag can take the following (or combination of) values HS_MMCSD_INTR_xxx.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDIntrStatusClear(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Gets the Auto CMD Error status from the controller.
 *
 *	This API reads the Auto Command Error status and return to application.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   flag          Auto Command Error status flag. \n
 *
 * \param   retValue    Variable pointer to be filled with AutoCMD error status. \n
 *
 * \range   for flag: \n    HS_MMCSD_STAT_ACMD_NOEXECUTE - 0x00000001 \n
 *							HS_MMCSD_STAT_ACMD_TIMEOUT - 0x00000002 \n
 *							HS_MMCSD_STAT_ACMD_CRCERR - 0x00000004 \n
 *							HS_MMCSD_STAT_ACMD_ENDBITERR - 0x00000008 \n
 *							HS_MMCSD_STAT_ACMD_INDEXERR - 0x00000010 \n
 *							HS_MMCSD_STAT_ACMD_NOCMD - 0x00000080 \n
 *							HS_MMCSD_STAT_ACMD_ALL -	0x0000009f \n
 *
 * \return    Success/Error code as defined by macro STW_xxxx.
 *
 * \range    for return value: \n
 * 				No error corresponding to flag bit - 0x0 \n
 *				Error corresponding to flag bit - 0x1
 *
 **/
int32_t HSMMCSDAutoCmdErrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue);

/**
 * \brief   Gets the ADMA Error status from the controller.
 *
 *	This API reads the ADMA error status and return to application.
 *
 * \param   baseAddr    Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retValue    Variable pointer to be filled with the error status. \n
 *
 * \range   for retValue: \n   Bit0 - Bit1: DMA State \n
 *						Stop DMA. Points to next of error descriptor - 0x00 \n
 *						Fetch Descriptor. Points to error descriptor - 0x01 \n
 * 						Transfer data. Points to next of error descriptor - 0x03 \n
 *						Bit2: ADMA Length Mismatch error - 0x1 \n
 *						No error - 0x0 \n
 *						Bit3 - Bit31: Reserved
 *
 * \return    Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDAdmaErrStatusGet(uintptr_t baseAddr, uint32_t *retValue);

/**
 * \brief   Checks if the command is complete.
 *
 *	This API checks for the completion of command sent to controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   retry         Iterations to wait for the command complete flag to be set. \n
 *
 * \range   for retry: \n 0x0 - 0xffff \n
 *
 * \return    Status of command or error codes as defined by macro STW_xxxx. \n
 *
 * \range   for return value: \n   Command not complete - 0x0	\n
 *					 			   Command complete - 0x1
 *
 **/
int32_t HSMMCSDIsCmdComplete(uintptr_t baseAddr, uint32_t retry);

/**
 * \brief   Checks if the transfer is complete.
 *
 *	This API checks for the completion of the transaction
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   retry         Iterations to wait for the transfer complete flag to be set. \n
 *
 * \range   for retry: \n    0x0 - 0xffff \n
 *
 * \return    Status of transaction or error codes as defined by macro STW_xxxx. \n
 *
 * \range 	 for return value: \n   Transaction not complete - 0x0	\n
 *					 			   Transaction complete - 0x1
 **/
int32_t HSMMCSDIsXferComplete(uintptr_t baseAddr, uint32_t retry);

/**
 * \brief   Set the SDMA buffer length/size for data transfer.
 *
 *	This API configures the length of SDMA contiguous buffer in data transfer.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   bufferLen         Length of SDMA buffer. \n
 *
 * \range   for bufferLen: \n    4Kbytes - 0x0  \n
 *								 8Kbytes - 0x1  \n
 *								 16Kbytes - 0x2 \n
 *								 32Kbytes - 0x3 \n
 *							 	 64Kbytes - 0x4 \n
 *							 	 128Kbytes - 0x5 \n
 *								 256Kbytes - 0x6 \n
 *								 512KBytes - 0x7
 *
 * \return    Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSdmaBufferLenSet(uintptr_t baseAddr, uint32_t bufferLen);

/**
 * \brief   Set the block length/size for data transfer.
 *
 *	This API configures the length of block for transferring in block mode
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   blklen        Length of transfer block. \n
 *
 * \range   for blklen: \n 0 - 2048 bytes
 *
 * \return    Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDBlkLenSet(uintptr_t baseAddr, uint32_t blklen);

/**
 * \brief    Pass the MMC/SD command to the controller/card.
 *
 *	This API sends a command to the host controller / card.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   cmd        	Command to be sent to host controller. The CMD is created as per
 * 						Host Specifications Command Register (0x0Eh).
 *
 * \param   cmdarg      Command arguments to be sent to host controller. The
 *						argument is created as per SD Physical Layer Specifications bit 39:9 for
 *						different commands.
 *
 * \param   dataPresent	 Indicate if command has data. \n
 *
 * \param   nblks      Data length in number of blocks. \n
 *
 * \param   dmaEn       DMA enable/disable flag for transfer.
 *
 * \param   autoCmd    Auto CMD enable.
 *
 * \range    for dataPresent: \n      No data in command - 0x0 \n
 *								   Data in command - 0x1 \n \n
 *			 for nblks: \n     0 to 0xFFFF. 0 is to stop count in case of continuous transfer. \n \n
 *			 for dmaEn: \n     DMA disable - 0x0 \n
 *							   DMA enable - 0x1 \n \n
 *			 for autoCmd: \n   AutoCmddisable - 0x0 \n
 *					    	   AutoCMD12 enable - 0x1 \n
 *					    	   AutoCMD23 enable - 0x2
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \note   Please use HS_MMCSD_CMD(cmd, type, restype, rw) to form command.
 **/
int32_t HSMMCSDCommandSend(uintptr_t baseAddr, uint32_t cmd,
                        uint32_t cmdarg, uint32_t dataPresent,
                        uint32_t nblks, uint32_t dmaEn, uint32_t autoCmd);

/**
 * \brief   Set SDMA address for data transfer.
 *
 *	This API configures the SDMA address in host controller. The address
 *	should be configured before sending data transfer command. This API is
 *	also called when the SDMA buffer boundary is reached and the next
 *	buffer address is to be configured to continue data transfer.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   dmaAddr        Address ofSystem DMA buffer
 *
 * \return    Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSdmaAddressSet (uintptr_t baseAddr, uint32_t dmaAddr);

/**
 * \brief    Set ADMA2 address for data transfer.
 *
 *	This API configures the ADMA2 address in host controller. The address
 *	should be configured before sending data transfer command. If ADMA2
 *	32-bit mode is enabled, only the lowerDmaAddr is to be provided in the
 *	call.A brief of the ADMA2 structures is as follows. \n
 *
 *	typedef struct _sd_adma_list{ \n
 *								uint8_t *buffer; \n
 *								char_tattrib; \n
 *								int32_t bufferLen; \n
 *								int32_t link; \n
 *								}SD_ADMA_LIST; \n
 *
 *	typedef struct _sd_adma_desc{ \n
 *								SD_ADMA_LIST *admaList; \n
 *								uint32_t numEntries; \n
 *								}SD_ADMA_DESC; \n
 *
 *	struct _sd_adma_table{ \n
 * 						 SD_ADMA_DESC *desc; \n
 * 						 int32 numTables; \n
 *						 }SD_ADMA_TABLE;
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param    lowerDmaAddr    Lower 32bits of Address of DMA buffer
 *
 * \param    upperDmaAddr    Upper 32bits of Address of DMA buffer. Null if 32-bit
 *								DMA is required.
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDAdmaAddressSet(uintptr_t baseAddr, uint32_t lowerDmaAddr,
	                 uint32_t upperDmaAddr);

/**
 * \brief    Get the command response from the conntroller.
 *
 *	This API returns the response for all commands send to a host controller
 *	/ card. The size of the buffer should be max size of various responses. The
 *	response parsing is done by the application/protocol stack.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param    rsp         Pointer to a buffer holding the command response. The response
 *						buffer is decoded as per SD Physical layer specifications for command
 *						responses.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \note This function shall return the values from all response
 * registers. Hence, rsp, must be a pointer to memory which can hold max
 * response length. It is the responsibility of the caller to use only the
 * required/relevant parts of the response.
 *
 **/
int32_t HSMMCSDResponseGet(uintptr_t baseAddr, uint32_t *rsp);

/**
 * \brief    Read the data from the card to the controller.
 *
 *	This API reads the data from host controller for the specified length. This
 *	API is used for data transfer in Non-DMA mode.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param    data          Pointer to buffer to hold the data. Buffer should be multiple of 4
 *							byte in length
 *
 * \param    len         Length in bytes to be read from the card
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 * \note This function shall return the values from all response
 * registers. Hence, rsp, must be a pointer to memory which can hold max
 * response length. It is the responsibility of the caller to use only the
 * required/relevant parts of the response
 *
 **/
int32_t HSMMCSDDataGet(uintptr_t baseAddr, uint8_t *data, uint32_t len);

/**
 * \brief    Write the data from the controller to the card.
 *
 *	This API writes the data to host controller for the specified length. This
 *	API is used for data transfer in Non-DMA mode.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param    data          Pointer to buffer with data. Buffer should be multiple of 4
 *							byte in length
 *
 * \param    len         Length in bytes to write to the card
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 * \note This function shall return the values from all response
 * registers. Hence, rsp, must be a pointer to memory which can hold max
 * response length. It is the responsibility of the caller to use only the
 * required/relevant parts of the response
 *
 **/
int32_t HSMMCSDDataSet(uintptr_t baseAddr, const uint8_t *data, uint32_t len);

/**
 * \brief    Check if the card is inserted and detected.
 *
 *	This API checks for the presence of a card in the SD slot
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \return    Status of card insertion or error codes as defined by macro STW_xxxx. \n
 *
 * \range    for return value: \n    If the card is not inserted and detected - 0x0 \n
 *              					If the card is inserted and detected - 0x1
 *
 * \note This functional may not be available for all instances of the
 * controler. This function, is only useful of the controller has a dedicated
 * card detect pin. If not, the card detection mechanism is application
 * implementation specific
 *
 **/
int32_t HSMMCSDIsCardInserted(uintptr_t baseAddr);

/**
 * \brief    Check if the card is write protected.
 *
 *	This API checks for the write protection feature of card
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \return    Write protection status. \n
 *
 * \range    for return value: \n   If the card is not write protected - 0x0 \n
 *              					If the card is write protected - 0x1
 *
 * \note This functional may not be available for all instances of the
 * controler. This function, is only useful of the controller has a dedicated
 * write protect detect pin. If not, the write protect detection mechanism is
 * application implementation specific
 *
 **/
int32_t HSMMCSDIsCardWriteProtected(uintptr_t baseAddr);

/**
 * \brief    Tune / Re-tune the SD /MMC bus.
 *
 *	This API is used to start the re-tuning procedure fore the card / device.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   state          Re-tuning enable / disable. \n
 *
 * \param   samplingClock     Type of clock used to sample data. \n
 *
 * \range   for state: \n   HS_MMCSD_EXEC_TUNING_ENABLE - 0x1 \n
 *							HS_MMCSD_EXEC_TUNING_DISABLE - 0x0 \n \n
 *          for samplingClock: \n   HS_MMCSD_CLCK_SELECT_ENABLE - 0x1 \n
 *									HS_MMCSD_CLCK_SELECT_DISABLE - 0x0
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCardTuningSet(uintptr_t baseAddr, uint32_t state, uint32_t samplingClock);

/**
 * \brief    Read Tuning details of the SD /MMC bus.
 *
 *	This API is used to read the re-tuning procedure state and the sampling
 *  clock used.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   state          Variable pointer for filling the tuning state. \n
 *
 * \param   samplingClock     Variable pointer for filling the sampling clock type. \n
 *
 * \range   for state: \n     HS_MMCSD_EXEC_TUNING_ENABLE - 0x1 \n
 *							  HS_MMCSD_EXEC_TUNING_DISABLE - 0x0 \n \n
 *			for samplingClock: \n   HS_MMCSD_CLCK_SELECT_ENABLE - 0x1 \n
 *									HS_MMCSD_CLCK_SELECT_DISABLE - 0x0
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCardTuningGet(uintptr_t baseAddr, uint32_t *state, uint32_t *samplingClock);


/**
 * \brief    Configure enhanced strobe in host controller.
 *
 *	This API is used to configure enhanced strobe capability in the host
 * 	controller.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   state         Strobe state \n
 *
 * \range   for state: \n    MMC_VREG_STROBE_ENABLE - 0x1 \n
 *							 MMC_VREG_STROBE_DISABLE - 0x0
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDEnhancedStrobeSet(uintptr_t baseAddr, uint32_t state);

/**
 * \brief   Configures CQ for descriptor size and enabling CQ.
 *
 *	This API configures the CQ for descriptor size and enabling CQ
 *
 * \param   baseAddr      eMMC CQ  Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param   cqState         CQ enable/disable. \n
 *
 * \param   cqDescSize     CQ descriptor size. \n
 *
 * \range   for cqState: \n      HS_MMCSD_CQ_ENABLE - 0x1 \n
 *								 HS_MMCSD_CQ_DISABLE - 0x0 \n \n
 *			for cqDescSize: \n   HS_MMCSD_CQ_DESC_128BIT - 128bit \n
 *								 HS_MMCSD_CQ_DESC_64BIT - 64bit
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQConfigure(uintptr_t baseAddr, uint32_t cqState, uint32_t cqDescSize);

/**
 * \brief    Configures CQ to handle sending of CMD13 to device.
 *
 *	Configures CQ to handle sending of CMD13 to device
 *
 * \param   baseAddr      eMMC CQ  Host controller register set base address. This base address
 *						  is platform specific and provided by the application.
 *
 * \param    counter       block counter for CMD13.
 *
 * \param    timer          Idle timer for polling period.
 *
 * \param    rca             Relative card address of card.
 *
 * \range    for counter: \n    0 to 15   \n \n
 *			 for timer: \n      0x0001 - 0xffff \n \n
 * 			 for rca: \n		Starting from 0x0001 to max 0xffff
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQSendStatusConfig(uintptr_t baseAddr, uint32_t counter, uint32_t timer, uint32_t rca);

/**
 * \brief    Configures CQ with task descriptor list address.
 *
 *	This API configures the CQ with task descriptor list address. The task
 *	descriptor list format is defined in the eMMC specifications.
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \param    lowerAddress      lower 32 bits of the list address
 *
 * \param    upperAddress     upper 32 bits of the list address
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQTaskDescriptorListSet(uintptr_t baseAddr, uint32_t lowerAddress, uint32_t upperAddress);

/**
 * \brief    Triggers sending of a direct command in CQ.
 *
 *	This API triggers sending of a direct command in CQ. The task descriptor
 *	should be populated in the task descriptor list by the application before
 *	calling this API.
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQSendDirectCmd(uintptr_t baseAddr);

/**
 * \brief    Reads the response of a direct command.
 *
 *	This API reads the response of a direct command.
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \param    resp      32-bit Direct command response returned
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQReadDirectCmdResponse(uintptr_t baseAddr, uint32_t *resp);

/**
 * \brief    Triggers sending of a task in CQ.
 *
 *	This API triggers sending of a task in CQ. The task descriptor should be
 *	populated in the task descriptor list by the application before calling this
 *	API.
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \param    flag      32-bit value with each bit corresponding to a task slot in the 32 slot
 *						task list
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQSendTask(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief    This API halts the Command queue.
 *
 *	This API halts the CQ. The application should wait for the halt completion
 *	interrupt to bring the CQ to halt state.
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 * \note    The application should wait for the halt completion interrupt to bring
 *              the CQ to halt state
 *
 **/
int32_t HSMMCSDCQHalt(uintptr_t baseAddr);

/**
 * \brief   This API resumes the halted command queue.
 *
 *	This API resumes the CQ which was halted by HSMMCSDCQHalt(). The
 *	application should wait for the halt bit to clear before continuing with bus
 *	transactions
 *
 * \param    baseAddr    eMMC CQ host controller register base address.This base
 *						address is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQResume(uintptr_t baseAddr);

/**
 * \brief   Clear all tasks or task corresponding to task id from CQ.
 *
 *	This API clears all tasks or task corresponding to task id from CQ .
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   taskId       ID of the task to be cleared.
 *
 * \range    for taskId: \n 0 to 31 for individual tasks and 32 for all tasks
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQClearTask(uintptr_t baseAddr, uint32_t taskId);

/**
 * \brief   Enables the interrupt signal for relevant interrupt.
 *
 *	This API enables the interrupt signal for relevant interrupt .
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt signal to be enabled. The interrupt flags can be
 *						Or’ed to enable multiple interrupt signals in single call.
 *
 * \range   for flag: \n    HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *						    HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrEnable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Disables the interrupt signal for relevant interrupt.
 *
 *	This API disables the interrupt signal for relevant interrupt .
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt signal to be disabled. The interrupt flags can be
 *						Or’ed to enable multiple interrupt signals in single call. \n
 *
 * \range   for flag: \n     HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							 HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *							 HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							 HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrDisable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Enables the interrupt bit in interrupt status register.
 *
 *	This API enables the interrupt bit in interrupt status register .
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt to be enabled. The interrupt flags can be
 *						Or’ed to enable multiple interrupt signals in single call. \n
 *
 * \range:   for flag: \n	 HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							 HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *							 HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							 HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrStatusEnable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Disables the interrupt bit in interrupt status register.
 *
 *	This API disables the interrupt bit in interrupt status register.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt to be disabled. The interrupt flags can be
 *						Or’ed to enable multiple interrupt signals in single call. \n
 *
 * \range:  for flag: \n    HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *							HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrStatusDisable(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Reads the interrupt status register for the specified interrupt.
 *
 *	This API reads the interrupt status register for the specified interrupt.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt whose status is to be obtained. \n
 *
 * \range   for flag: \n    HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *							HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008 \n
 *							All interrupts - 0x00000000 \n
 *
 * \param   retValue      Variable pointer to be filled with return status. \n
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 * \range    for return value: \n
 * 				No interrupt corresponding to the flag bit - 0x0 \n
 *				Interrupt corresponding to the flag bit - 0x1
 *
 **/
int32_t HSMMCSDCQIntrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue);

/**
 * \brief   Clears the specified interrupt of its status.
 *
 *	This API clears the specified interrupt of its status in the interrupt status
 *	register.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag       Value of interrupt to be cleared. The interrupt flags can be
 *						Or’ed to enable multiple interrupt signals in single call. \n
 *
 * \range   for flag: \n    HS_MMCSD_CQ_INTR_HALT_COMPLETE - 0x00000001 \n
 *							HS_MMCSD_CQ_INTR_TASK_COMPLETE - 0x00000002 \n
 *							HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED - 0x00000004 \n
 *							HS_MMCSD_CQ_INTR_TASK_CLEARED - 0x00000008
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrStatusClear(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Reads the task completion status of the task indexes.
 *
 *	This API reads the task completion status of the task indexes.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retValue      Variable pointer to be filled with task completion status value.
 *
 * \range   for retValue: \n   It is a 32-bit value with each bit corresponding
 * 								to the task in the 32-slot task list.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQTaskCompletionStatusGet(uintptr_t baseAddr, uint32_t *retValue);

/**
 * \brief   Clears the task completion status of the task indexes.
 *
 *	This API clears the task completion status of the task indexes.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   flag      32-bit value with each bit corresponding to a task slot in the 32 slot
 *							task list.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQTaskCompletionStatusClear(uintptr_t baseAddr, uint32_t flag);

/**
 * \brief   Checks for the pending task list on the device.
 *
 *	This API checks for the pending task list on the device.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retValue      Variable pointer to be filled with device pending task list. \n
 *
 * \range   for retValue:  \n  It is a 32-bit value with each bit corresponding
 * 								to the task in the 32-slot task list.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQDevicePendingTaskGet(uintptr_t baseAddr, uint32_t *retValue);

/**
 * \brief   Checks for the status of device queue on the device.
 *
 *	This API checks for the status of device queue in the device.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retValue      Variable pointer to be filled with device queue status. \n
 *
 * \range   for retValue:  \n  It is a 32-bit value with each bit corresponding
 * 								to the task in the 32-slot task list.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQDeviceQueueStatus(uintptr_t baseAddr, uint32_t *retValue);

/**
 * \brief   Checks for the error information that may have happened during
 *             the execution of a task.
 *
 *	This API checks for the error information that may have happened during
 * 	the execution of a task in the task list.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   retValue      Variable pointer to be filled with task error status. \n
 *
 * \range   for retValue: \n    The 32-bit value is decoded as shown below \n
 * 								Bit0 - Bit5: Response mode error command index. \n
 *								Bit6 - Bit7: Response mode error task id \n
 *								Bit8 - Bit12: Reserved. \n
 *								Bit15: Response mode error field valid if 1 \n
 *								Bit16 - Bit21: Reserved. \n
 *								Bit22 - Bit23: Data transfer error command index \n
 *								Bit24 - Bit28: Data transfer error task Id \n
 *								Bit29 - Bit30: Reserved \n
 *								Bit31: Data transfer error field valid if 1.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQTaskErrorGet(uintptr_t baseAddr, uint32_t *retValue);

/**
 * \brief   Reads the index of the task for which a response is received.
 *
 *	This API reads the index of the task for which a response is received. This
 *	API is called during error recovery procedure by the application.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return   Error code as defined by macro STW_xxxx or Task index for which command
 *				response returned.
 *
 **/
int32_t HSMMCSDCQCmdResponseIndexGet(uintptr_t baseAddr);

/**
 * \brief   Reads the argument of the last command executed.
 *
 *	This API reads the argument of the last command executed. This API is
 * 	called during error recovery procedure by the application.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   resp      Variable pointer to be filled with the argument of the last
 *						command response.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQCmdResponseGet(uintptr_t baseAddr, uint32_t *resp);

/**
 * \brief    Configures the counter and timeout values in interrupt coalescing.
 *
 *	This API configures the counter and timeout values in interrupt coalescing
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param    counter       counter threshold value. \n
 *
 * \param    timeout       value of timeout. \n
 *
 * \range   for counter: \n    0 to 31 \n \n
 *          for timeout: \n    0x01 - 0x7f
 *
 * \return    Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQIntrCoalescingConfigure(uintptr_t baseAddr, uint32_t counter, uint32_t timeout);

/**
 * \brief   Configures the state of interrupt coalescing in CQ.
 *
 *	This API enables / disables interrupt coalescing in CQ.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \param   state       To enable/disable the state.
 *
 * \range   for state: \n    MMC_CQIC_ICEN_ENABLE - 0x00000001 \n
 *							 MMC_CQIC_ICEN_DISABLE - 0x00000000
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDCQIntrCoalescingStateSet(uintptr_t baseAddr, uint32_t state);

/**
 * \brief   Reads the interrupt coalescing bit to identify if any tasks have completed.
 *
 *	This API reads the interrupt coalescing bit to identify if any tasks have
 *	completed.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Error code as defined by macro STW_xxxx or Interrupt coalescing bit value \n
 *
 * \range   for return value: \n    At least one task completion bit counted - 0x1 \n
 *					   No task completions have occurred since last counter reset - 0x0
 *
 **/
int32_t HSMMCSDCQIntrCoalescingStatusGet(uintptr_t baseAddr);

/**
 * \brief   Resets the counter and the timer for interrupt coalescing.
 *
 *	This API resets the counter and the timer for interrupt coalescing.
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDCQIntrCoalescingReset(uintptr_t baseAddr);

/**
 * \brief   Disables the clock.
 *
 *	This API disables the clock
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDSDClockDisable(uintptr_t baseAddr);
/**
 * \brief   Enables the clock.
 *
 *	This API disables the clock
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Success/Error code as defined by macro STW_xxxx
 *
 **/

int32_t HSMMCSDSDClockEnable(uintptr_t baseAddr);

/**
 * \brief   Get the CMD signal level .
 *
 *	This API returns the command signal level
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Signal level (0/1)
 *
 **/

uint32_t HSMMCSDGetCmdSignalLevel(uintptr_t baseAddr);

/**
 * \brief   Get the Data signal level .
 *
 *	This API returns the data signal level
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Signal level (0-0xf)
 *
 **/

uint32_t HSMMCSDGetDataSignalLevel(uintptr_t baseAddr);

/**
 * \brief   Returns the presently configured signalling voltage.
 *
 *	This API returns the presently configured signalling voltage
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    Signal voltage (1.8/3.0/3.3V)
 *
 **/


int32_t HSMMCSDGetSignalVoltage(uintptr_t baseAddr);

/**
 * \brief   Sets the UHS driver strength
 *
 *	This API sets the driver strength in the controller register
 *
 * \param   baseAddr    eMMC CQ Host controller register set base address. This base address
 *						is platform specific and provided by the application.
 *
 * \return    STSW_OK if successful.
 *
 **/
int32_t HSMMCSDUhsDrvStrengthSet(uintptr_t baseAddr, uint32_t drvStrength);

#ifdef __cplusplus
}
#endif
#endif
/********************************* End of file ******************************/
