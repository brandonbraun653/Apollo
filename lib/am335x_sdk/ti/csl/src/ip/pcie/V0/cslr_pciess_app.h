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
#ifndef CSLR_PCIESS_APP_H
#define CSLR_PCIESS_APP_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for MSIX_IRQ
**************************************************************************/
typedef struct {
    volatile Uint32 MSI_IRQ_STATUS_RAW;
    volatile Uint32 MSI_IRQ_STATUS;
    volatile Uint32 MSI_IRQ_ENABLE_SET;
    volatile Uint32 MSI_IRQ_ENABLE_CLR;
} CSL_Pciess_appMsix_irqRegs;


/**************************************************************************
* Register Overlay Structure for LEGACY_X_IRQ
**************************************************************************/
typedef struct {
    volatile Uint32 LEGACY_IRQ_STATUS_RAW;
    volatile Uint32 LEGACY_IRQ_STATUS;
    volatile Uint32 LEGACY_IRQ_ENABLE_SET;
    volatile Uint32 LEGACY_IRQ_ENABLE_CLR;
} CSL_Pciess_appLegacy_x_irqRegs;


/**************************************************************************
* Register Overlay Structure for OUTBOUND_TRANSLATION
**************************************************************************/
typedef struct {
    volatile Uint32 OB_OFFSET_INDEX;
    volatile Uint32 OB_OFFSET_HI;
} CSL_Pciess_appOutbound_translationRegs;


/**************************************************************************
* Register Overlay Structure for INBOUND_TRANSLATION
**************************************************************************/
typedef struct {
    volatile Uint32 IB_BAR;
    volatile Uint32 IB_START_LO;
    volatile Uint32 IB_START_HI;
    volatile Uint32 IB_OFFSET;
} CSL_Pciess_appInbound_translationRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 PID;
    volatile Uint32 CMD_STATUS;
    volatile Uint32 CFG_SETUP;
    volatile Uint32 IOBASE;
    volatile Uint32 TLPCFG;
    volatile Uint32 RSTCMD;
    volatile Uint8  RSVD0[8];
    volatile Uint32 PMCMD;
#ifndef CSL_MODIFICATION
    volatile Uint32 PMCFG;
#else
    volatile Uint8  RSVD1[4];
#endif
    volatile Uint32 ACT_STATUS;
    volatile Uint8  RSVD2[4];
    volatile Uint32 OB_SIZE;
    volatile Uint32 DIAG_CTRL;
    volatile Uint32 ENDIAN;
    volatile Uint32 PRIORITY;
    volatile Uint8  RSVD3[16];
    volatile Uint32 IRQ_EOI;
    volatile Uint32 MSI_IRQ;
    volatile Uint8  RSVD4[12];
    volatile Uint32 EP_IRQ_SET;
    volatile Uint32 EP_IRQ_CLR;
    volatile Uint32 EP_IRQ_STATUS;
    volatile Uint32 GPR[4];
    volatile Uint8  RSVD5[128];
    CSL_Pciess_appMsix_irqRegs	MSIX_IRQ[8];
    CSL_Pciess_appLegacy_x_irqRegs	LEGACY_X_IRQ[4];
    volatile Uint32 ERR_IRQ_STATUS_RAW;
    volatile Uint32 ERR_IRQ_STATUS;
    volatile Uint32 ERR_IRQ_ENABLE_SET;
    volatile Uint32 ERR_IRQ_ENABLE_CLR;
    volatile Uint32 PMRST_IRQ_STATUS_RAW;
    volatile Uint32 PMRST_IRQ_STATUS;
    volatile Uint32 PMRST_ENABLE_SET;
    volatile Uint32 PMRST_ENABLE_CLR;
    volatile Uint8  RSVD6[32];
#ifndef CSL_MODIFICATION
    CSL_Pciess_appOutbound_translationRegs	OUTBOUND_TRANSLATION[32];
#else
    CSL_Pciess_appOutbound_translationRegs	OUTBOUND_TRANSLATION[8];
    volatile Uint8  RSVD7[192];
#endif
    CSL_Pciess_appInbound_translationRegs	INBOUND_TRANSLATION[4];
#ifndef CSL_MODIFICATION
    volatile Uint8 RSVD8[64];
    volatile Uint32 PCS_CFG0;
    volatile Uint32 PCS_CFG1;
    volatile Uint32 PCS_STATUS;
    volatile Uint8 RSVD9[4];
    volatile Uint32 SERDES_CFG0;
    volatile Uint32 SERDES_CFG1;
#endif
} CSL_Pciess_appRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* MSI Interrupt Raw Status Register */
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW(n)                    (0x100U + ((n) * (0x10U)))

/* MSI Interrupt Enabled Status Register */
#define CSL_PCIESS_APP_MSI_IRQ_STATUS(n)                        (0x104U + ((n) * (0x10U)))

/* MSI Interrupt Enable Set Register */
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET(n)                    (0x108U + ((n) * (0x10U)))

/* MSI Interrupt Enable Clear Register */
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR(n)                    (0x10CU + ((n) * (0x10U)))

/* Legacy Interrupt Raw Status Register */
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW(n)                 (0x180U + ((n) * (0x10U)))

/* Legacy Interrupt Enabled Status Register */
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS(n)                     (0x184U + ((n) * (0x10U)))

/* Legacy Interrupt Enable Set Register */
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET(n)                 (0x188U + ((n) * (0x10U)))

/* Legacy Interrupt Enable Clear Register */
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR(n)                 (0x18CU + ((n) * (0x10U)))

/* Outbound Translation Region N Offset Low and Index Register */
#define CSL_PCIESS_APP_OB_OFFSET_INDEX(n)                       (0x200U + ((n) * (0x8U)))

/* Outbound Translation Region N Offset High Register */
#define CSL_PCIESS_APP_OB_OFFSET_HI(n)                          (0x204U + ((n) * (0x8U)))

/* Inbound Translation Bar Match Register */
#define CSL_PCIESS_APP_IB_BAR(n)                                (0x300U + ((n) * (0x10U)))

/* Inbound Translation Start Address Low Register */
#define CSL_PCIESS_APP_IB_START_LO(n)                           (0x304U + ((n) * (0x10U)))

/* Inbound Translation Start Address High Register */
#define CSL_PCIESS_APP_IB_START_HI(n)                           (0x308U + ((n) * (0x10U)))

/* Inbound Translation Address Offset Register */
#define CSL_PCIESS_APP_IB_OFFSET(n)                             (0x30CU + ((n) * (0x10U)))

/* Peripheral Version and ID Register */
#define CSL_PCIESS_APP_PID                                      (0x0U)

/* Command Status Register */
#define CSL_PCIESS_APP_CMD_STATUS                               (0x4U)

/* Config Transaction Setup Register */
#define CSL_PCIESS_APP_CFG_SETUP                                (0x8U)

/* IO TLP Base Register */
#define CSL_PCIESS_APP_IOBASE                                   (0xCU)

/* TLP Attribute Configuration Register */
#define CSL_PCIESS_APP_TLPCFG                                   (0x10U)

/* Reset Command Register */
#define CSL_PCIESS_APP_RSTCMD                                   (0x14U)

/* Power Management Command Register */
#define CSL_PCIESS_APP_PMCMD                                    (0x20U)

/* Activity Status Register */
#define CSL_PCIESS_APP_ACT_STATUS                               (0x28U)

/* Outbound Size Register */
#define CSL_PCIESS_APP_OB_SIZE                                  (0x30U)

/* Diagnostic Control Register */
#define CSL_PCIESS_APP_DIAG_CTRL                                (0x34U)

/* Endian Mode Register */
#define CSL_PCIESS_APP_ENDIAN                                   (0x38U)

/* Endian Mode Register */
#define CSL_PCIESS_APP_PRIORITY                                 (0x3CU)

/* End of Interrupt Register */
#define CSL_PCIESS_APP_IRQ_EOI                                  (0x50U)

/* MSI Interrupt IRQ Register */
#define CSL_PCIESS_APP_MSI_IRQ                                  (0x54U)

/* Endpoint Interrupt Request Set Register */
#define CSL_PCIESS_APP_EP_IRQ_SET                               (0x64U)

/* Endpoint Interrupt Request Clear Register */
#define CSL_PCIESS_APP_EP_IRQ_CLR                               (0x68U)

/* Endpoint Interrupt Status Register */
#define CSL_PCIESS_APP_EP_IRQ_STATUS                            (0x6CU)

/* General Purpose Register */
#define CSL_PCIESS_APP_GPR(i)                                   (0x70U + ((i) * (0x4U)))

/* Raw ERR Interrupt Status Register */
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW                       (0x1C0U)

/* ERR Interrupt Enabled Status Register */
#define CSL_PCIESS_APP_ERR_IRQ_STATUS                           (0x1C4U)

/* ERR Interrupt Enable Set Register */
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET                       (0x1C8U)

/* ERR Interrupt Enable Clear Register */
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR                       (0x1CCU)

/* Power Management and Reset Interrupt Status Register */
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW                     (0x1D0U)

/* Power Management and Reset Interrupt Enabled Status Register */
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS                         (0x1D4U)

/* Power Management and Reset Interrupt Enable Set Register */
#define CSL_PCIESS_APP_PMRST_ENABLE_SET                         (0x1D8U)

/* Power Management and Reset Interrupt Enable Clear Register */
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR                         (0x1DCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* MSI_IRQ_STATUS_RAW */

#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW_MSI_RAW_STATUS_MASK   (0x0000000FU)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW_MSI_RAW_STATUS_SHIFT  (0U)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW_MSI_RAW_STATUS_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW_MSI_RAW_STATUS_MAX    (0x0000000fU)

#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RAW_RESETVAL              (0x00000000U)

/* MSI_IRQ_STATUS */

#define CSL_PCIESS_APP_MSI_IRQ_STATUS_MSI_IRQ_STATUS_MASK       (0x0000000FU)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_MSI_IRQ_STATUS_SHIFT      (0U)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_MSI_IRQ_STATUS_RESETVAL   (0x00000000U)
#define CSL_PCIESS_APP_MSI_IRQ_STATUS_MSI_IRQ_STATUS_MAX        (0x0000000fU)

#define CSL_PCIESS_APP_MSI_IRQ_STATUS_RESETVAL                  (0x00000000U)

/* MSI_IRQ_ENABLE_SET */

#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET_MSI_IRQ_EN_SET_MASK   (0x0000000FU)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET_MSI_IRQ_EN_SET_SHIFT  (0U)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET_MSI_IRQ_EN_SET_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET_MSI_IRQ_EN_SET_MAX    (0x0000000fU)

#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_SET_RESETVAL              (0x00000000U)

/* MSI_IRQ_ENABLE_CLR */

#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR_MSI_IRQ_EN_CLR_MASK   (0x0000000FU)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR_MSI_IRQ_EN_CLR_SHIFT  (0U)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR_MSI_IRQ_EN_CLR_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR_MSI_IRQ_EN_CLR_MAX    (0x0000000fU)

#define CSL_PCIESS_APP_MSI_IRQ_ENABLE_CLR_RESETVAL              (0x00000000U)

/* LEGACY_IRQ_STATUS_RAW */

#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW_LEGACY_RAW_STATUS_MASK  (0x00000001U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW_LEGACY_RAW_STATUS_SHIFT  (0U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW_LEGACY_RAW_STATUS_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW_LEGACY_RAW_STATUS_MAX  (0x00000001U)

#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RAW_RESETVAL           (0x00000000U)

/* LEGACY_IRQ_STATUS */

#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_LEGACY_IRQ_STATUS_MASK  (0x00000001U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_LEGACY_IRQ_STATUS_SHIFT  (0U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_LEGACY_IRQ_STATUS_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_LEGACY_IRQ_STATUS_MAX  (0x00000001U)

#define CSL_PCIESS_APP_LEGACY_IRQ_STATUS_RESETVAL               (0x00000000U)

/* LEGACY_IRQ_ENABLE_SET */

#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET_LEGACY_IRQ_EN_SET_MASK  (0x00000001U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET_LEGACY_IRQ_EN_SET_SHIFT  (0U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET_LEGACY_IRQ_EN_SET_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET_LEGACY_IRQ_EN_SET_MAX  (0x00000001U)

#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_SET_RESETVAL           (0x00000000U)

/* LEGACY_IRQ_ENABLE_CLR */

#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR_LEGACY_IRQ_EN_CLR_MASK  (0x00000001U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR_LEGACY_IRQ_EN_CLR_SHIFT  (0U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR_LEGACY_IRQ_EN_CLR_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR_LEGACY_IRQ_EN_CLR_MAX  (0x00000001U)

#define CSL_PCIESS_APP_LEGACY_IRQ_ENABLE_CLR_RESETVAL           (0x00000000U)

/* OB_OFFSET_INDEX */

#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_OFFSET_LO_MASK        (0xFFF00000U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_OFFSET_LO_SHIFT       (20U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_OFFSET_LO_RESETVAL    (0x00000000U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_OFFSET_LO_MAX         (0x00000fffU)

#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_ENABLE_MASK           (0x00000001U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_ENABLE_SHIFT          (0U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_ENABLE_RESETVAL       (0x00000000U)
#define CSL_PCIESS_APP_OB_OFFSET_INDEX_OB_ENABLE_MAX            (0x00000001U)

#define CSL_PCIESS_APP_OB_OFFSET_INDEX_RESETVAL                 (0x00000000U)

/* OB_OFFSET_HI */

#define CSL_PCIESS_APP_OB_OFFSET_HI_OB_OFFSET_HI_MASK           (0xFFFFFFFFU)
#define CSL_PCIESS_APP_OB_OFFSET_HI_OB_OFFSET_HI_SHIFT          (0U)
#define CSL_PCIESS_APP_OB_OFFSET_HI_OB_OFFSET_HI_RESETVAL       (0x00000000U)
#define CSL_PCIESS_APP_OB_OFFSET_HI_OB_OFFSET_HI_MAX            (0xffffffffU)

#define CSL_PCIESS_APP_OB_OFFSET_HI_RESETVAL                    (0x00000000U)

/* IB_BAR */

#define CSL_PCIESS_APP_IB_BAR_IB_BAR_MASK                       (0x00000007U)
#define CSL_PCIESS_APP_IB_BAR_IB_BAR_SHIFT                      (0U)
#define CSL_PCIESS_APP_IB_BAR_IB_BAR_RESETVAL                   (0x00000000U)
#define CSL_PCIESS_APP_IB_BAR_IB_BAR_MAX                        (0x00000007U)

#define CSL_PCIESS_APP_IB_BAR_RESETVAL                          (0x00000000U)

/* IB_START_LO */

#define CSL_PCIESS_APP_IB_START_LO_IB_START_LO_MASK             (0xFFFFFF00U)
#define CSL_PCIESS_APP_IB_START_LO_IB_START_LO_SHIFT            (8U)
#define CSL_PCIESS_APP_IB_START_LO_IB_START_LO_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_IB_START_LO_IB_START_LO_MAX              (0x00ffffffU)

#define CSL_PCIESS_APP_IB_START_LO_RESETVAL                     (0x00000000U)

/* IB_START_HI */

#define CSL_PCIESS_APP_IB_START_HI_IB_START_HI_MASK             (0xFFFFFFFFU)
#define CSL_PCIESS_APP_IB_START_HI_IB_START_HI_SHIFT            (0U)
#define CSL_PCIESS_APP_IB_START_HI_IB_START_HI_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_IB_START_HI_IB_START_HI_MAX              (0xffffffffU)

#define CSL_PCIESS_APP_IB_START_HI_RESETVAL                     (0x00000000U)

/* IB_OFFSET */

#define CSL_PCIESS_APP_IB_OFFSET_IB_OFFSET_MASK                 (0xFFFFFF00U)
#define CSL_PCIESS_APP_IB_OFFSET_IB_OFFSET_SHIFT                (8U)
#define CSL_PCIESS_APP_IB_OFFSET_IB_OFFSET_RESETVAL             (0x00000000U)
#define CSL_PCIESS_APP_IB_OFFSET_IB_OFFSET_MAX                  (0x00ffffffU)

#define CSL_PCIESS_APP_IB_OFFSET_RESETVAL                       (0x00000000U)

/* PID */

#define CSL_PCIESS_APP_PID_SCHEME_MASK                          (0xC0000000U)
#define CSL_PCIESS_APP_PID_SCHEME_SHIFT                         (30U)
#define CSL_PCIESS_APP_PID_SCHEME_RESETVAL                      (0x00000000U)
#define CSL_PCIESS_APP_PID_SCHEME_MAX                           (0x00000003U)

#define CSL_PCIESS_APP_PID_FUNC_MASK                            (0x0FFF0000U)
#define CSL_PCIESS_APP_PID_FUNC_SHIFT                           (16U)
#define CSL_PCIESS_APP_PID_FUNC_RESETVAL                        (0x00000000U)
#define CSL_PCIESS_APP_PID_FUNC_MAX                             (0x00000fffU)

#define CSL_PCIESS_APP_PID_RTL_MASK                             (0x0000F800U)
#define CSL_PCIESS_APP_PID_RTL_SHIFT                            (11U)
#define CSL_PCIESS_APP_PID_RTL_RESETVAL                         (0x00000000U)
#define CSL_PCIESS_APP_PID_RTL_MAX                              (0x0000001fU)

#define CSL_PCIESS_APP_PID_MAJOR_MASK                           (0x00000700U)
#define CSL_PCIESS_APP_PID_MAJOR_SHIFT                          (8U)
#define CSL_PCIESS_APP_PID_MAJOR_RESETVAL                       (0x00000000U)
#define CSL_PCIESS_APP_PID_MAJOR_MAX                            (0x00000007U)

#define CSL_PCIESS_APP_PID_CUSTOM_MASK                          (0x000000C0U)
#define CSL_PCIESS_APP_PID_CUSTOM_SHIFT                         (6U)
#define CSL_PCIESS_APP_PID_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_PCIESS_APP_PID_CUSTOM_MAX                           (0x00000003U)

#define CSL_PCIESS_APP_PID_MINOR_MASK                           (0x0000003FU)
#define CSL_PCIESS_APP_PID_MINOR_SHIFT                          (0U)
#define CSL_PCIESS_APP_PID_MINOR_RESETVAL                       (0x00000000U)
#define CSL_PCIESS_APP_PID_MINOR_MAX                            (0x0000003fU)

#define CSL_PCIESS_APP_PID_RESETVAL                             (0x00000000U)

/* CMD_STATUS */

#define CSL_PCIESS_APP_CMD_STATUS_DBI_CS2_MASK                  (0x00000020U)
#define CSL_PCIESS_APP_CMD_STATUS_DBI_CS2_SHIFT                 (5U)
#define CSL_PCIESS_APP_CMD_STATUS_DBI_CS2_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_DBI_CS2_MAX                   (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_APP_RETRY_EN_MASK             (0x00000010U)
#define CSL_PCIESS_APP_CMD_STATUS_APP_RETRY_EN_SHIFT            (4U)
#define CSL_PCIESS_APP_CMD_STATUS_APP_RETRY_EN_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_APP_RETRY_EN_MAX              (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_POSTED_WR_EN_MASK             (0x00000008U)
#define CSL_PCIESS_APP_CMD_STATUS_POSTED_WR_EN_SHIFT            (3U)
#define CSL_PCIESS_APP_CMD_STATUS_POSTED_WR_EN_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_POSTED_WR_EN_MAX              (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_IB_XLT_EN_MASK                (0x00000004U)
#define CSL_PCIESS_APP_CMD_STATUS_IB_XLT_EN_SHIFT               (2U)
#define CSL_PCIESS_APP_CMD_STATUS_IB_XLT_EN_RESETVAL            (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_IB_XLT_EN_MAX                 (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_OB_XLT_EN_MASK                (0x00000002U)
#define CSL_PCIESS_APP_CMD_STATUS_OB_XLT_EN_SHIFT               (1U)
#define CSL_PCIESS_APP_CMD_STATUS_OB_XLT_EN_RESETVAL            (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_OB_XLT_EN_MAX                 (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_LTSSM_EN_MASK                 (0x00000001U)
#define CSL_PCIESS_APP_CMD_STATUS_LTSSM_EN_SHIFT                (0U)
#define CSL_PCIESS_APP_CMD_STATUS_LTSSM_EN_RESETVAL             (0x00000000U)
#define CSL_PCIESS_APP_CMD_STATUS_LTSSM_EN_MAX                  (0x00000001U)

#define CSL_PCIESS_APP_CMD_STATUS_RESETVAL                      (0x00000000U)

/* CFG_SETUP */

#define CSL_PCIESS_APP_CFG_SETUP_CFG_TYPE_MASK                  (0x01000000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_TYPE_SHIFT                 (24U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_TYPE_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_TYPE_MAX                   (0x00000001U)

#define CSL_PCIESS_APP_CFG_SETUP_CFG_BUS_MASK                   (0x00FF0000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_BUS_SHIFT                  (16U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_BUS_RESETVAL               (0x00000000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_BUS_MAX                    (0x000000ffU)

#define CSL_PCIESS_APP_CFG_SETUP_CFG_DEVICE_MASK                (0x00001F00U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_DEVICE_SHIFT               (8U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_DEVICE_RESETVAL            (0x00000000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_DEVICE_MAX                 (0x0000001fU)

#define CSL_PCIESS_APP_CFG_SETUP_CFG_FUNC_MASK                  (0x00000007U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_FUNC_SHIFT                 (0U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_FUNC_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_CFG_SETUP_CFG_FUNC_MAX                   (0x00000007U)

#define CSL_PCIESS_APP_CFG_SETUP_RESETVAL                       (0x00000000U)

/* IOBASE */

#define CSL_PCIESS_APP_IOBASE_IOBASE_MASK                       (0xFFFFF000U)
#define CSL_PCIESS_APP_IOBASE_IOBASE_SHIFT                      (12U)
#define CSL_PCIESS_APP_IOBASE_IOBASE_RESETVAL                   (0x00000000U)
#define CSL_PCIESS_APP_IOBASE_IOBASE_MAX                        (0x000fffffU)

#define CSL_PCIESS_APP_IOBASE_RESETVAL                          (0x00000000U)

/* TLPCFG */

#define CSL_PCIESS_APP_TLPCFG_RELAXED_MASK                      (0x00000002U)
#define CSL_PCIESS_APP_TLPCFG_RELAXED_SHIFT                     (1U)
#define CSL_PCIESS_APP_TLPCFG_RELAXED_RESETVAL                  (0x00000000U)
#define CSL_PCIESS_APP_TLPCFG_RELAXED_MAX                       (0x00000001U)

#define CSL_PCIESS_APP_TLPCFG_NO_SNOOP_MASK                     (0x00000001U)
#define CSL_PCIESS_APP_TLPCFG_NO_SNOOP_SHIFT                    (0U)
#define CSL_PCIESS_APP_TLPCFG_NO_SNOOP_RESETVAL                 (0x00000000U)
#define CSL_PCIESS_APP_TLPCFG_NO_SNOOP_MAX                      (0x00000001U)

#define CSL_PCIESS_APP_TLPCFG_RESETVAL                          (0x00000000U)

/* RSTCMD */

#define CSL_PCIESS_APP_RSTCMD_FLUSH_N_MASK                      (0x00010000U)
#define CSL_PCIESS_APP_RSTCMD_FLUSH_N_SHIFT                     (16U)
#define CSL_PCIESS_APP_RSTCMD_FLUSH_N_RESETVAL                  (0x00000000U)
#define CSL_PCIESS_APP_RSTCMD_FLUSH_N_MAX                       (0x00000001U)

#define CSL_PCIESS_APP_RSTCMD_INIT_RST_MASK                     (0x00000001U)
#define CSL_PCIESS_APP_RSTCMD_INIT_RST_SHIFT                    (0U)
#define CSL_PCIESS_APP_RSTCMD_INIT_RST_RESETVAL                 (0x00000000U)
#define CSL_PCIESS_APP_RSTCMD_INIT_RST_MAX                      (0x00000001U)

#define CSL_PCIESS_APP_RSTCMD_RESETVAL                          (0x00000000U)

/* PMCMD */

#define CSL_PCIESS_APP_PMCMD_PM_XMT_TURNOFF_MASK                (0x00000002U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_TURNOFF_SHIFT               (1U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_TURNOFF_RESETVAL            (0x00000000U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_TURNOFF_MAX                 (0x00000001U)

#define CSL_PCIESS_APP_PMCMD_PM_XMT_PME_MASK                    (0x00000001U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_PME_SHIFT                   (0U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_PME_RESETVAL                (0x00000000U)
#define CSL_PCIESS_APP_PMCMD_PM_XMT_PME_MAX                     (0x00000001U)

#define CSL_PCIESS_APP_PMCMD_RESETVAL                           (0x00000000U)

#ifndef CSL_MODIFICATION
/* PMCFG */

#define CSL_PCIESS_APP_PMCFG_ENTR_L23_MASK                      (0x00000001u)
#define CSL_PCIESS_APP_PMCFG_ENTR_L23_SHIFT                     (0x00000000u)
#define CSL_PCIESS_APP_PMCFG_ENTR_L23_RESETVAL                  (0x00000000u)

#define CSL_PCIESS_APP_PMCFG_RESETVAL                           (0x00000000u)
#endif

/* ACT_STATUS */

#define CSL_PCIESS_APP_ACT_STATUS_OB_NOT_EMPTY_MASK             (0x00000002U)
#define CSL_PCIESS_APP_ACT_STATUS_OB_NOT_EMPTY_SHIFT            (1U)
#define CSL_PCIESS_APP_ACT_STATUS_OB_NOT_EMPTY_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_ACT_STATUS_OB_NOT_EMPTY_MAX              (0x00000001U)

#define CSL_PCIESS_APP_ACT_STATUS_IB_NOT_EMPTY_MASK             (0x00000001U)
#define CSL_PCIESS_APP_ACT_STATUS_IB_NOT_EMPTY_SHIFT            (0U)
#define CSL_PCIESS_APP_ACT_STATUS_IB_NOT_EMPTY_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_ACT_STATUS_IB_NOT_EMPTY_MAX              (0x00000001U)

#define CSL_PCIESS_APP_ACT_STATUS_RESETVAL                      (0x00000000U)

/* OB_SIZE */

#define CSL_PCIESS_APP_OB_SIZE_OB_SIZE_MASK                     (0x00000007U)
#define CSL_PCIESS_APP_OB_SIZE_OB_SIZE_SHIFT                    (0U)
#define CSL_PCIESS_APP_OB_SIZE_OB_SIZE_RESETVAL                 (0x00000000U)
#define CSL_PCIESS_APP_OB_SIZE_OB_SIZE_MAX                      (0x00000007U)

#define CSL_PCIESS_APP_OB_SIZE_RESETVAL                         (0x00000000U)

/* DIAG_CTRL */

#define CSL_PCIESS_APP_DIAG_CTRL_INV_ECRC_MASK                  (0x00000002U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_ECRC_SHIFT                 (1U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_ECRC_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_ECRC_MAX                   (0x00000001U)

#define CSL_PCIESS_APP_DIAG_CTRL_INV_LCRC_MASK                  (0x00000001U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_LCRC_SHIFT                 (0U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_LCRC_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_DIAG_CTRL_INV_LCRC_MAX                   (0x00000001U)

#define CSL_PCIESS_APP_DIAG_CTRL_RESETVAL                       (0x00000000U)

/* ENDIAN */

#define CSL_PCIESS_APP_ENDIAN_ENDIAN_MODE_MASK                  (0x00000003U)
#define CSL_PCIESS_APP_ENDIAN_ENDIAN_MODE_SHIFT                 (0U)
#define CSL_PCIESS_APP_ENDIAN_ENDIAN_MODE_RESETVAL              (0x00000000U)
#define CSL_PCIESS_APP_ENDIAN_ENDIAN_MODE_MAX                   (0x00000003U)

#define CSL_PCIESS_APP_ENDIAN_RESETVAL                          (0x00000000U)

/* PRIORITY */

#define CSL_PCIESS_APP_PRIORITY_MST_PRIV_MASK                   (0x00010000U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIV_SHIFT                  (16U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIV_RESETVAL               (0x00000000U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIV_MAX                    (0x00000001U)

#define CSL_PCIESS_APP_PRIORITY_MST_PRIVID_MASK                 (0x00000F00U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIVID_SHIFT                (8U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIVID_RESETVAL             (0x00000000U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIVID_MAX                  (0x0000000fU)

#define CSL_PCIESS_APP_PRIORITY_MST_PRIORITY_MASK               (0x00000007U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIORITY_SHIFT              (0U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIORITY_RESETVAL           (0x00000000U)
#define CSL_PCIESS_APP_PRIORITY_MST_PRIORITY_MAX                (0x00000007U)

#define CSL_PCIESS_APP_PRIORITY_RESETVAL                        (0x00000000U)

/* IRQ_EOI */

#define CSL_PCIESS_APP_IRQ_EOI_EOI_MASK                         (0x0000000FU)
#define CSL_PCIESS_APP_IRQ_EOI_EOI_SHIFT                        (0U)
#define CSL_PCIESS_APP_IRQ_EOI_EOI_RESETVAL                     (0x00000000U)
#define CSL_PCIESS_APP_IRQ_EOI_EOI_MAX                          (0x0000000fU)

#define CSL_PCIESS_APP_IRQ_EOI_RESETVAL                         (0x00000000U)

/* MSI_IRQ */

#define CSL_PCIESS_APP_MSI_IRQ_MSI_IRQ_MASK                     (0xFFFFFFFFU)
#define CSL_PCIESS_APP_MSI_IRQ_MSI_IRQ_SHIFT                    (0U)
#define CSL_PCIESS_APP_MSI_IRQ_MSI_IRQ_RESETVAL                 (0x00000000U)
#define CSL_PCIESS_APP_MSI_IRQ_MSI_IRQ_MAX                      (0xffffffffU)

#define CSL_PCIESS_APP_MSI_IRQ_RESETVAL                         (0x00000000U)

/* EP_IRQ_SET */

#define CSL_PCIESS_APP_EP_IRQ_SET_EP_IRQ_SET_MASK               (0x00000001U)
#define CSL_PCIESS_APP_EP_IRQ_SET_EP_IRQ_SET_SHIFT              (0U)
#define CSL_PCIESS_APP_EP_IRQ_SET_EP_IRQ_SET_RESETVAL           (0x00000000U)
#define CSL_PCIESS_APP_EP_IRQ_SET_EP_IRQ_SET_MAX                (0x00000001U)

#define CSL_PCIESS_APP_EP_IRQ_SET_RESETVAL                      (0x00000000U)

/* EP_IRQ_CLR */

#define CSL_PCIESS_APP_EP_IRQ_CLR_EP_IRQ_CLR_MASK               (0x00000001U)
#define CSL_PCIESS_APP_EP_IRQ_CLR_EP_IRQ_CLR_SHIFT              (0U)
#define CSL_PCIESS_APP_EP_IRQ_CLR_EP_IRQ_CLR_RESETVAL           (0x00000000U)
#define CSL_PCIESS_APP_EP_IRQ_CLR_EP_IRQ_CLR_MAX                (0x00000001U)

#define CSL_PCIESS_APP_EP_IRQ_CLR_RESETVAL                      (0x00000000U)

/* EP_IRQ_STATUS */

#define CSL_PCIESS_APP_EP_IRQ_STATUS_EP_IRQ_STATUS_MASK         (0x00000001U)
#define CSL_PCIESS_APP_EP_IRQ_STATUS_EP_IRQ_STATUS_SHIFT        (0U)
#define CSL_PCIESS_APP_EP_IRQ_STATUS_EP_IRQ_STATUS_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_EP_IRQ_STATUS_EP_IRQ_STATUS_MAX          (0x00000001U)

#define CSL_PCIESS_APP_EP_IRQ_STATUS_RESETVAL                   (0x00000000U)

/* GPR */

#define CSL_PCIESS_APP_GPR_GENERIC_MASK                         (0xFFFFFFFFU)
#define CSL_PCIESS_APP_GPR_GENERIC_SHIFT                        (0U)
#define CSL_PCIESS_APP_GPR_GENERIC_RESETVAL                     (0x00000000U)
#define CSL_PCIESS_APP_GPR_GENERIC_MAX                          (0xffffffffU)

#define CSL_PCIESS_APP_GPR_RESETVAL                             (0x00000000U)

/* ERR_IRQ_STATUS_RAW */

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AER_MASK          (0x00000020U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AER_SHIFT         (5U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AER_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AER_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AXI_MASK          (0x00000010U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AXI_SHIFT         (4U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AXI_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_AXI_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_CORR_MASK         (0x00000008U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_CORR_SHIFT        (3U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_CORR_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_CORR_MAX          (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_NONFATAL_MASK     (0x00000004U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_NONFATAL_SHIFT    (2U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_NONFATAL_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_NONFATAL_MAX      (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_FATAL_MASK        (0x00000002U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_FATAL_SHIFT       (1U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_FATAL_RESETVAL    (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_FATAL_MAX         (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_SYS_MASK          (0x00000001U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_SYS_SHIFT         (0U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_SYS_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_ERR_SYS_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RAW_RESETVAL              (0x00000000U)

/* ERR_IRQ_STATUS */

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AER_MASK              (0x00000020U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AER_SHIFT             (5U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AER_RESETVAL          (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AER_MAX               (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AXI_MASK              (0x00000010U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AXI_SHIFT             (4U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AXI_RESETVAL          (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_AXI_MAX               (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_CORR_MASK             (0x00000008U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_CORR_SHIFT            (3U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_CORR_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_CORR_MAX              (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_NONFATAL_MASK         (0x00000004U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_NONFATAL_SHIFT        (2U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_NONFATAL_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_NONFATAL_MAX          (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_FATAL_MASK            (0x00000002U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_FATAL_SHIFT           (1U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_FATAL_RESETVAL        (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_FATAL_MAX             (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_SYS_MASK              (0x00000001U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_SYS_SHIFT             (0U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_SYS_RESETVAL          (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_STATUS_ERR_SYS_MAX               (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_STATUS_RESETVAL                  (0x00000000U)

/* ERR_IRQ_ENABLE_SET */

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AER_MASK          (0x00000020U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AER_SHIFT         (5U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AER_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AER_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AXI_MASK          (0x00000010U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AXI_SHIFT         (4U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AXI_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_AXI_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_CORR_MASK         (0x00000008U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_CORR_SHIFT        (3U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_CORR_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_CORR_MAX          (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_NONFATAL_MASK     (0x00000004U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_NONFATAL_SHIFT    (2U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_NONFATAL_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_NONFATAL_MAX      (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_FATAL_MASK        (0x00000002U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_FATAL_SHIFT       (1U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_FATAL_RESETVAL    (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_FATAL_MAX         (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_SYS_MASK          (0x00000001U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_SYS_SHIFT         (0U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_SYS_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_ERR_SYS_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_SET_RESETVAL              (0x00000000U)

/* ERR_IRQ_ENABLE_CLR */

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AER_MASK          (0x00000020U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AER_SHIFT         (5U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AER_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AER_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AXI_MASK          (0x00000010U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AXI_SHIFT         (4U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AXI_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_AXI_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_CORR_MASK         (0x00000008U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_CORR_SHIFT        (3U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_CORR_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_CORR_MAX          (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_NONFATAL_MASK     (0x00000004U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_NONFATAL_SHIFT    (2U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_NONFATAL_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_NONFATAL_MAX      (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_FATAL_MASK        (0x00000002U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_FATAL_SHIFT       (1U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_FATAL_RESETVAL    (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_FATAL_MAX         (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_SYS_MASK          (0x00000001U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_SYS_SHIFT         (0U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_SYS_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_ERR_SYS_MAX           (0x00000001U)

#define CSL_PCIESS_APP_ERR_IRQ_ENABLE_CLR_RESETVAL              (0x00000000U)

/* PMRST_IRQ_STATUS_RAW */

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_LINK_RST_REQ_MASK   (0x00000008U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_LINK_RST_REQ_SHIFT  (3U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_LINK_RST_REQ_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_LINK_RST_REQ_MAX    (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_PME_MASK         (0x00000004U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_PME_SHIFT        (2U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_PME_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_PME_MAX          (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TO_ACK_MASK      (0x00000002U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TO_ACK_SHIFT     (1U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TO_ACK_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TO_ACK_MAX       (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TURNOFF_MASK     (0x00000001U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TURNOFF_SHIFT    (0U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TURNOFF_RESETVAL  (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_PM_TURNOFF_MAX      (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RAW_RESETVAL            (0x00000000U)

/* PMRST_IRQ_STATUS */

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_LINK_RST_REQ_MASK       (0x00000008U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_LINK_RST_REQ_SHIFT      (3U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_LINK_RST_REQ_RESETVAL   (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_LINK_RST_REQ_MAX        (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_PME_MASK             (0x00000004U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_PME_SHIFT            (2U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_PME_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_PME_MAX              (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TO_ACK_MASK          (0x00000002U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TO_ACK_SHIFT         (1U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TO_ACK_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TO_ACK_MAX           (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TURNOFF_MASK         (0x00000001U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TURNOFF_SHIFT        (0U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TURNOFF_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_PM_TURNOFF_MAX          (0x00000001U)

#define CSL_PCIESS_APP_PMRST_IRQ_STATUS_RESETVAL                (0x00000000U)

/* PMRST_ENABLE_SET */

#define CSL_PCIESS_APP_PMRST_ENABLE_SET_LINK_RST_REQ_MASK       (0x00000008U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_LINK_RST_REQ_SHIFT      (3U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_LINK_RST_REQ_RESETVAL   (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_LINK_RST_REQ_MAX        (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_PME_MASK             (0x00000004U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_PME_SHIFT            (2U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_PME_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_PME_MAX              (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TO_ACK_MASK          (0x00000002U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TO_ACK_SHIFT         (1U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TO_ACK_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TO_ACK_MAX           (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TURNOFF_MASK         (0x00000001U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TURNOFF_SHIFT        (0U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TURNOFF_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_SET_PM_TURNOFF_MAX          (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_SET_RESETVAL                (0x00000000U)

/* PMRST_ENABLE_CLR */

#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_LINK_RST_REQ_MASK       (0x00000008U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_LINK_RST_REQ_SHIFT      (3U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_LINK_RST_REQ_RESETVAL   (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_LINK_RST_REQ_MAX        (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_PME_MASK             (0x00000004U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_PME_SHIFT            (2U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_PME_RESETVAL         (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_PME_MAX              (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TO_ACK_MASK          (0x00000002U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TO_ACK_SHIFT         (1U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TO_ACK_RESETVAL      (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TO_ACK_MAX           (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TURNOFF_MASK         (0x00000001U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TURNOFF_SHIFT        (0U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TURNOFF_RESETVAL     (0x00000000U)
#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_PM_TURNOFF_MAX          (0x00000001U)

#define CSL_PCIESS_APP_PMRST_ENABLE_CLR_RESETVAL                (0x00000000U)

#ifndef CSL_MODIFICATION
/* PCS_CFG0 */

#define CSL_PCIESS_APP_PCS_CFG0_PCS_SYNC_MASK (0x1F000000u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_SYNC_SHIFT (0x00000018u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_SYNC_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_HOLDOFF_MASK (0x00FF0000u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_HOLDOFF_SHIFT (0x00000010u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_HOLDOFF_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_RC_DELAY_MASK (0x00003000u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RC_DELAY_SHIFT (0x0000000Cu)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RC_DELAY_RESETVAL (0x00000002u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_DET_DELAY_MASK (0x00000F00u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_DET_DELAY_SHIFT (0x00000008u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_DET_DELAY_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_SHRT_TM_MASK (0x00000080u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_SHRT_TM_SHIFT (0x00000007u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_SHRT_TM_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_STAT186_MASK (0x00000040u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_STAT186_SHIFT (0x00000006u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_STAT186_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_TERM_MASK (0x00000020u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_TERM_SHIFT (0x00000005u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_TERM_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_STD_MASK (0x00000010u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_STD_SHIFT (0x00000004u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_FIX_STD_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_L2_ENIDL_OFF_MASK (0x00000008u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_L2_ENIDL_OFF_SHIFT (0x00000003u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_L2_ENIDL_OFF_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_L0S_RX_OFF_MASK (0x00000004u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_L0S_RX_OFF_SHIFT (0x00000002u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_L0S_RX_OFF_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_ON_MASK (0x00000002u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_ON_SHIFT (0x00000001u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_ON_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_RST_MASK (0x00000001u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_RST_SHIFT (0x00000000u)
#define CSL_PCIESS_APP_PCS_CFG0_PCS_RXTX_RST_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG0_RESETVAL (0x00002110u)

/* PCS_CFG1 */

#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_BIT_MASK (0x03FF0000u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_BIT_SHIFT (0x00000010u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_BIT_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_LN_MASK (0x00000300u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_LN_SHIFT (0x00000008u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_LN_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_MODE_MASK (0x00000003u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_MODE_SHIFT (0x00000000u)
#define CSL_PCIESS_APP_PCS_CFG1_PCS_ERR_MODE_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_CFG1_RESETVAL (0x00000000u)

/* PCS_STATUS */

#define CSL_PCIESS_APP_PCS_STATUS_PCS_REV_MASK (0x00007000u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_REV_SHIFT (0x0000000Cu)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_REV_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_PCS_STATUS_PCS_LN_EN_MASK (0x00000300u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_LN_EN_SHIFT (0x00000008u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_LN_EN_RESETVAL (0x00000003u)

#define CSL_PCIESS_APP_PCS_STATUS_PCS_TX_EN_MASK (0x00000030u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_TX_EN_SHIFT (0x00000004u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_TX_EN_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_STATUS_PCS_RX_EN_MASK (0x00000003u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_RX_EN_SHIFT (0x00000000u)
#define CSL_PCIESS_APP_PCS_STATUS_PCS_RX_EN_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_PCS_STATUS_RESETVAL (0x00001300u)

/* SERDES_CFG0 */

#define CSL_PCIESS_APP_SERDES_CFG0_TX_LOOPBACK_MASK (0x00180000u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_LOOPBACK_SHIFT (0x00000013u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG0_TX_MSYNC_MASK (0x00040000u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_MSYNC_SHIFT (0x00000012u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_MSYNC_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG0_TX_CM_MASK (0x00020000u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_CM_SHIFT (0x00000011u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_CM_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG0_TX_INVPAIR_MASK (0x00010000u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_INVPAIR_SHIFT (0x00000010u)
#define CSL_PCIESS_APP_SERDES_CFG0_TX_INVPAIR_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOOPBACK_MASK (0x0000C000u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOOPBACK_SHIFT (0x0000000Eu)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_ENOC_MASK (0x00002000u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_ENOC_SHIFT (0x0000000Du)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_ENOC_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_EQ_MASK (0x00001E00u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_EQ_SHIFT (0x00000009u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_EQ_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_CDR_MASK (0x000001C0u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_CDR_SHIFT (0x00000006u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_CDR_RESETVAL (0x00000002u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOS_MASK (0x00000038u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOS_SHIFT (0x00000003u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_LOS_RESETVAL (0x00000004u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_ALIGN_MASK (0x00000006u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_ALIGN_SHIFT (0x00000001u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_ALIGN_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG0_RX_INVPAIR_MASK (0x00000001u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_INVPAIR_SHIFT (0x00000000u)
#define CSL_PCIESS_APP_SERDES_CFG0_RX_INVPAIR_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG0_RESETVAL (0x000622A0u)

/* SERDES_CFG1 */

#define CSL_PCIESS_APP_SERDES_CFG1_TX_LOOPBACK_MASK (0x00180000u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_LOOPBACK_SHIFT (0x00000013u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_TX_MSYNC_MASK (0x00040000u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_MSYNC_SHIFT (0x00000012u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_MSYNC_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_TX_CM_MASK (0x00020000u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_CM_SHIFT (0x00000011u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_CM_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG1_TX_INVPAIR_MASK (0x00010000u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_INVPAIR_SHIFT (0x00000010u)
#define CSL_PCIESS_APP_SERDES_CFG1_TX_INVPAIR_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOOPBACK_MASK (0x0000C000u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOOPBACK_SHIFT (0x0000000Eu)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_ENOC_MASK (0x00002000u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_ENOC_SHIFT (0x0000000Du)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_ENOC_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_EQ_MASK (0x00001E00u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_EQ_SHIFT (0x00000009u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_EQ_RESETVAL (0x00000001u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_CDR_MASK (0x000001C0u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_CDR_SHIFT (0x00000006u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_CDR_RESETVAL (0x00000002u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOS_MASK (0x00000038u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOS_SHIFT (0x00000003u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_LOS_RESETVAL (0x00000004u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_ALIGN_MASK (0x00000006u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_ALIGN_SHIFT (0x00000001u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_ALIGN_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_RX_INVPAIR_MASK (0x00000001u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_INVPAIR_SHIFT (0x00000000u)
#define CSL_PCIESS_APP_SERDES_CFG1_RX_INVPAIR_RESETVAL (0x00000000u)

#define CSL_PCIESS_APP_SERDES_CFG1_RESETVAL (0x000222A0u)
#endif
#ifdef __cplusplus
}
#endif
#endif
