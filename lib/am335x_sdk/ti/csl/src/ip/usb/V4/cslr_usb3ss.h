/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_usb3ss.h
*/
#ifndef CSLR_USB3SS_H_
#define CSLR_USB3SS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_USB3SS_USB3_SLV0_BASE                                      (0x00000000U)
#define CSL_USB3SS_USB3_SLV0_RSEL1_BASE                                (0x00000000U)
#define CSL_USB3SS_USB3_SLV1_BASE                                      (0x00000000U)


/**************************************************************************
* Hardware Region  : Global Control Registers, offset 0x00000000
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_MAIN */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_MAIN */
    volatile uint8_t  Resv_16[8];
} CSL_usb3_gmodRegs_IRQ_MAIN;


typedef struct {
    volatile uint32_t EOI;                       /* IRQ_EOI_MISC */
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_MISC */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_MISC */
    volatile uint32_t ENABLE_SET;                /* IRQ_ENABLE_SET_MISC */
    volatile uint32_t ENABLE_CLR;                /* IRQ_ENABLE_CLR_MISC */
} CSL_usb3_gmodRegs_IRQ_MISC;


typedef struct {
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_OTG */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_OTG */
} CSL_usb3_gmodRegs_IRQ_OTG;


typedef struct {
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_ADP */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_ADP */
} CSL_usb3_gmodRegs_IRQ_ADP;


typedef struct {
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_BC */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_BC */
} CSL_usb3_gmodRegs_IRQ_BC;


typedef struct {
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW_PME_GEN */
    volatile uint32_t STATUS;                    /* IRQ_STATUS_PME_GEN */
} CSL_usb3_gmodRegs_IRQ_PME_GEN;


typedef struct {
    volatile uint32_t REVISION;                  /* REVISION */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t SYSCONFIG;                 /* SYSCONFIG */
    volatile uint8_t  Resv_32[12];
    CSL_usb3_gmodRegs_IRQ_MAIN IRQ_MAIN[16];
    volatile uint8_t  Resv_1068[780];
    CSL_usb3_gmodRegs_IRQ_MISC IRQ_MISC;
    volatile uint8_t  Resv_1104[16];
    CSL_usb3_gmodRegs_IRQ_OTG IRQ_OTG;
    volatile uint8_t  Resv_1120[8];
    CSL_usb3_gmodRegs_IRQ_ADP IRQ_ADP;
    volatile uint8_t  Resv_1136[8];
    CSL_usb3_gmodRegs_IRQ_BC IRQ_BC;
    volatile uint8_t  Resv_1152[8];
    CSL_usb3_gmodRegs_IRQ_PME_GEN IRQ_PME_GEN;
    volatile uint8_t  Resv_1556[396];
    volatile uint32_t VBUS_ID_FILTER;            /* VBUS ID filter */
    volatile uint32_t VBUS_ID_STAT;              /*  VBUS and ID Detect STATUS */
    volatile uint32_t USB2PHY_CTRL_STAT;         /* USB2PHY control and Statusr */
    volatile uint8_t  Resv_1792[224];
    volatile uint32_t MMRAM_OFFSET;              /* MMRAM_OFFSET */
    volatile uint32_t CORE_CTL;                  /* CORE_CTL */
    volatile uint32_t DEBUG_CFG;                 /* DEBUG_CFG */
    volatile uint32_t DEBUG_DATA;                /* DEBUG_DATA */
    volatile uint32_t DEV_EBC_EN;                /* DEV_EBC_EN */
    volatile uint32_t HOST_HUB_CTRL;             /* HOST_HUB_CTRL */
} CSL_usb3_gmodRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_GMOD_REVISION                                                 (0x00000000U)
#define CSL_USB3_GMOD_SYSCONFIG                                                (0x00000010U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW(IRQ_MAIN)                            (0x00000020U+((IRQ_MAIN)*0x10U))
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS(IRQ_MAIN)                                (0x00000024U+((IRQ_MAIN)*0x10U))
#define CSL_USB3_GMOD_IRQ_MISC_EOI                                             (0x0000042CU)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW                                      (0x00000430U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS                                          (0x00000434U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET                                      (0x00000438U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR                                      (0x0000043CU)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS_RAW                                       (0x00000450U)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS                                           (0x00000454U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS_RAW                                       (0x00000460U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS                                           (0x00000464U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS_RAW                                        (0x00000470U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS                                            (0x00000474U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_RAW                                   (0x00000480U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS                                       (0x00000484U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER                                           (0x00000614U)
#define CSL_USB3_GMOD_VBUS_ID_STAT                                             (0x00000618U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT                                        (0x0000061CU)
#define CSL_USB3_GMOD_MMRAM_OFFSET                                             (0x00000700U)
#define CSL_USB3_GMOD_CORE_CTL                                                 (0x00000704U)
#define CSL_USB3_GMOD_DEBUG_CFG                                                (0x00000708U)
#define CSL_USB3_GMOD_DEBUG_DATA                                               (0x0000070CU)
#define CSL_USB3_GMOD_DEV_EBC_EN                                               (0x00000710U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL                                            (0x00000714U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_IRQ_STATUS_RAW_MAIN_MASK             (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_IRQ_STATUS_RAW_MAIN_SHIFT            (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_IRQ_STATUS_RAW_MAIN_MAX              (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_RESERVED31_0_MASK                    (0xFFFFFFFEU)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_RESERVED31_0_SHIFT                   (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RAW_RESERVED31_0_MAX                     (0x7FFFFFFFU)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_IRQ_STATUS_MAIN_MASK                     (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_IRQ_STATUS_MAIN_SHIFT                    (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_IRQ_STATUS_MAIN_MAX                      (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RESERVED31_1_MASK                        (0xFFFFFFFEU)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RESERVED31_1_SHIFT                       (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MAIN_STATUS_RESERVED31_1_MAX                         (0x7FFFFFFFU)

/* EOI */

#define CSL_USB3_GMOD_IRQ_MISC_EOI_RESERVED31_1_MASK                           (0xFFFFFFFEU)
#define CSL_USB3_GMOD_IRQ_MISC_EOI_RESERVED31_1_SHIFT                          (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MISC_EOI_RESERVED31_1_MAX                            (0x7FFFFFFFU)

#define CSL_USB3_GMOD_IRQ_MISC_EOI_EOI_MISC_MASK                               (0x00000001U)
#define CSL_USB3_GMOD_IRQ_MISC_EOI_EOI_MISC_SHIFT                              (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MISC_EOI_EOI_MISC_MAX                                (0x00000001U)

/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED16_0_MASK                    (0x0003FFFFU)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED16_0_SHIFT                   (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED16_0_MAX                     (0x0003FFFFU)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AXI_ERROR_MASK                       (0x00040000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AXI_ERROR_SHIFT                      (0x00000012U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AXI_ERROR_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_SESSEND_CHANGE_MASK                  (0x00080000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_SESSEND_CHANGE_SHIFT                 (0x00000013U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_SESSEND_CHANGE_MAX                   (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_BVALID_CHANGE_MASK                   (0x00100000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_BVALID_CHANGE_SHIFT                  (0x00000014U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_BVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AVALID_CHANGE_MASK                   (0x00200000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AVALID_CHANGE_SHIFT                  (0x00000015U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_AVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_VBUSVALID_CHANGE_MASK                (0x00400000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_VBUSVALID_CHANGE_SHIFT               (0x00000016U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_VBUSVALID_CHANGE_MAX                 (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED31_23_MASK                   (0xFF800000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED31_23_SHIFT                  (0x00000017U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RAW_RESERVED31_23_MAX                    (0x000001FFU)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED16_0_MASK                        (0x0003FFFFU)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED16_0_SHIFT                       (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED16_0_MAX                         (0x0003FFFFU)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AXI_ERROR_MASK                           (0x00040000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AXI_ERROR_SHIFT                          (0x00000012U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AXI_ERROR_MAX                            (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_SESSEND_CHANGE_MASK                      (0x00080000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_SESSEND_CHANGE_SHIFT                     (0x00000013U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_SESSEND_CHANGE_MAX                       (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_BVALID_CHANGE_MASK                       (0x00100000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_BVALID_CHANGE_SHIFT                      (0x00000014U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_BVALID_CHANGE_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AVALID_CHANGE_MASK                       (0x00200000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AVALID_CHANGE_SHIFT                      (0x00000015U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_AVALID_CHANGE_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_VBUSVALID_CHANGE_MASK                    (0x00400000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_VBUSVALID_CHANGE_SHIFT                   (0x00000016U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_VBUSVALID_CHANGE_MAX                     (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED31_23_MASK                       (0xFF800000U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED31_23_SHIFT                      (0x00000017U)
#define CSL_USB3_GMOD_IRQ_MISC_STATUS_RESERVED31_23_MAX                        (0x000001FFU)

/* ENABLE_SET */

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED16_0_MASK                    (0x0003FFFFU)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED16_0_SHIFT                   (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED16_0_MAX                     (0x0003FFFFU)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AXI_ERROR_MASK                       (0x00040000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AXI_ERROR_SHIFT                      (0x00000012U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AXI_ERROR_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_SESSEND_CHANGE_MASK                  (0x00080000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_SESSEND_CHANGE_SHIFT                 (0x00000013U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_SESSEND_CHANGE_MAX                   (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_BVALID_CHANGE_MASK                   (0x00100000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_BVALID_CHANGE_SHIFT                  (0x00000014U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_BVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AVALID_CHANGE_MASK                   (0x00200000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AVALID_CHANGE_SHIFT                  (0x00000015U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_AVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_VBUSVALID_CHANGE_MASK                (0x00400000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_VBUSVALID_CHANGE_SHIFT               (0x00000016U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_VBUSVALID_CHANGE_MAX                 (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED31_23_MASK                   (0xFF800000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED31_23_SHIFT                  (0x00000017U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_SET_RESERVED31_23_MAX                    (0x000001FFU)

/* ENABLE_CLR */

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED16_0_MASK                    (0x0003FFFFU)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED16_0_SHIFT                   (0x00000000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED16_0_MAX                     (0x0003FFFFU)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AXI_ERROR_MASK                       (0x00040000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AXI_ERROR_SHIFT                      (0x00000012U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AXI_ERROR_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_SESSEND_CHANGE_MASK                  (0x00080000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_SESSEND_CHANGE_SHIFT                 (0x00000013U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_SESSEND_CHANGE_MAX                   (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_BVALID_CHANGE_MASK                   (0x00100000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_BVALID_CHANGE_SHIFT                  (0x00000014U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_BVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AVALID_CHANGE_MASK                   (0x00200000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AVALID_CHANGE_SHIFT                  (0x00000015U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_AVALID_CHANGE_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_VBUSVALID_CHANGE_MASK                (0x00400000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_VBUSVALID_CHANGE_SHIFT               (0x00000016U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_VBUSVALID_CHANGE_MAX                 (0x00000001U)

#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED31_23_MASK                   (0xFF800000U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED31_23_SHIFT                  (0x00000017U)
#define CSL_USB3_GMOD_IRQ_MISC_ENABLE_CLR_RESERVED31_23_MAX                    (0x000001FFU)

/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_OTG_STATUS_RAW_OTG_EVNT_MASK                         (0x00000001U)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS_RAW_OTG_EVNT_SHIFT                        (0x00000000U)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS_RAW_OTG_EVNT_MAX                          (0x00000001U)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_OTG_STATUS_OTG_EVNT_MASK                             (0x00000001U)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS_OTG_EVNT_SHIFT                            (0x00000000U)
#define CSL_USB3_GMOD_IRQ_OTG_STATUS_OTG_EVNT_MAX                              (0x00000001U)

/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_ADP_STATUS_RAW_ADP_EVNT_MASK                         (0x00000001U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS_RAW_ADP_EVNT_SHIFT                        (0x00000000U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS_RAW_ADP_EVNT_MAX                          (0x00000001U)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_ADP_STATUS_ADP_EVNT_MASK                             (0x00000001U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS_ADP_EVNT_SHIFT                            (0x00000000U)
#define CSL_USB3_GMOD_IRQ_ADP_STATUS_ADP_EVNT_MAX                              (0x00000001U)

/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_BC_STATUS_RAW_BC_EVNT_MASK                           (0x00000001U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS_RAW_BC_EVNT_SHIFT                          (0x00000000U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS_RAW_BC_EVNT_MAX                            (0x00000001U)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_BC_STATUS_BC_EVNT_MASK                               (0x00000001U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS_BC_EVNT_SHIFT                              (0x00000000U)
#define CSL_USB3_GMOD_IRQ_BC_STATUS_BC_EVNT_MAX                                (0x00000001U)

/* STATUS_RAW */

#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_RAW_PME_GEN_EVNT_MASK                 (0x00000001U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_RAW_PME_GEN_EVNT_SHIFT                (0x00000000U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_RAW_PME_GEN_EVNT_MAX                  (0x00000001U)

/* STATUS */

#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_PME_GEN_EVNT_MASK                     (0x00000001U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_PME_GEN_EVNT_SHIFT                    (0x00000000U)
#define CSL_USB3_GMOD_IRQ_PME_GEN_STATUS_PME_GEN_EVNT_MAX                      (0x00000001U)

/* REVISION */

#define CSL_USB3_GMOD_REVISION_Y_MINOR_MASK                                    (0x0000003FU)
#define CSL_USB3_GMOD_REVISION_Y_MINOR_SHIFT                                   (0x00000000U)
#define CSL_USB3_GMOD_REVISION_Y_MINOR_MAX                                     (0x0000003FU)

#define CSL_USB3_GMOD_REVISION_CUSTOM_MASK                                     (0x000000C0U)
#define CSL_USB3_GMOD_REVISION_CUSTOM_SHIFT                                    (0x00000006U)
#define CSL_USB3_GMOD_REVISION_CUSTOM_MAX                                      (0x00000003U)

#define CSL_USB3_GMOD_REVISION_X_MAJOR_MASK                                    (0x00000700U)
#define CSL_USB3_GMOD_REVISION_X_MAJOR_SHIFT                                   (0x00000008U)
#define CSL_USB3_GMOD_REVISION_X_MAJOR_MAX                                     (0x00000007U)

#define CSL_USB3_GMOD_REVISION_R_RTL_MASK                                      (0x0000F800U)
#define CSL_USB3_GMOD_REVISION_R_RTL_SHIFT                                     (0x0000000BU)
#define CSL_USB3_GMOD_REVISION_R_RTL_MAX                                       (0x0000001FU)

#define CSL_USB3_GMOD_REVISION_FUNC_MASK                                       (0x0FFF0000U)
#define CSL_USB3_GMOD_REVISION_FUNC_SHIFT                                      (0x00000010U)
#define CSL_USB3_GMOD_REVISION_FUNC_MAX                                        (0x00000FFFU)

#define CSL_USB3_GMOD_REVISION_BU_MASK                                         (0x30000000U)
#define CSL_USB3_GMOD_REVISION_BU_SHIFT                                        (0x0000001CU)
#define CSL_USB3_GMOD_REVISION_BU_MAX                                          (0x00000003U)

#define CSL_USB3_GMOD_REVISION_SCHEME_MASK                                     (0xC0000000U)
#define CSL_USB3_GMOD_REVISION_SCHEME_SHIFT                                    (0x0000001EU)
#define CSL_USB3_GMOD_REVISION_SCHEME_MAX                                      (0x00000003U)

/* SYSCONFIG */

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED0_MASK                                 (0x00000001U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED0_SHIFT                                (0x00000000U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED0_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED1_MASK                                 (0x00000002U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED1_SHIFT                                (0x00000001U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED1_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED7_2_MASK                               (0x000000FCU)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED7_2_SHIFT                              (0x00000002U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED7_2_MAX                                (0x0000003FU)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED8_MASK                                 (0x00000100U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED8_SHIFT                                (0x00000008U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED8_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED9_MASK                                 (0x00000200U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED9_SHIFT                                (0x00000009U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED9_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED10_MASK                                (0x00000400U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED10_SHIFT                               (0x0000000AU)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED10_MAX                                 (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED_11_MASK                               (0x00000800U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED_11_SHIFT                              (0x0000000BU)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED_11_MAX                                (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED12_MASK                                (0x00001000U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED12_SHIFT                               (0x0000000CU)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED12_MAX                                 (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOGZ_MASK                                  (0x00002000U)
#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOGZ_SHIFT                                 (0x0000000DU)
#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOGZ_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOA_MASK                                   (0x00004000U)
#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOA_SHIFT                                  (0x0000000EU)
#define CSL_USB3_GMOD_SYSCONFIG_CEGPIOA_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_HSIC_SEL_MASK                                  (0x00008000U)
#define CSL_USB3_GMOD_SYSCONFIG_HSIC_SEL_SHIFT                                 (0x0000000FU)
#define CSL_USB3_GMOD_SYSCONFIG_HSIC_SEL_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_PME_EN_MASK                                    (0x00010000U)
#define CSL_USB3_GMOD_SYSCONFIG_PME_EN_SHIFT                                   (0x00000010U)
#define CSL_USB3_GMOD_SYSCONFIG_PME_EN_MAX                                     (0x00000001U)

#define CSL_USB3_GMOD_SYSCONFIG_RESERVED31_17_MASK                             (0xFFFE0000U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED31_17_SHIFT                            (0x00000011U)
#define CSL_USB3_GMOD_SYSCONFIG_RESERVED31_17_MAX                              (0x00007FFFU)

/* VBUS_ID_FILTER */

#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_THRESH_MASK                     (0x00000003U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_THRESH_SHIFT                    (0x00000000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_THRESH_MAX                      (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_BYPASS_MASK                     (0x00000004U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_BYPASS_SHIFT                    (0x00000002U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_BYPASS_MAX                      (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_THRESH_MASK                        (0x00000018U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_THRESH_SHIFT                       (0x00000003U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_THRESH_MAX                         (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_BYPASS_MASK                        (0x00000020U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_BYPASS_SHIFT                       (0x00000005U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_AVALID_BYPASS_MAX                         (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_THRESH_MASK                        (0x000000C0U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_THRESH_SHIFT                       (0x00000006U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_THRESH_MAX                         (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_BYPASS_MASK                        (0x00000100U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_BYPASS_SHIFT                       (0x00000008U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_BVALID_BYPASS_MAX                         (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_THRESH_MASK                       (0x00000600U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_THRESH_SHIFT                      (0x00000009U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_THRESH_MAX                        (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_BYPASS_MASK                       (0x00000800U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_BYPASS_SHIFT                      (0x0000000BU)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_SESSEND_BYPASS_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_THRESH_MASK                         (0x00003000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_THRESH_SHIFT                        (0x0000000CU)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_THRESH_MAX                          (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_BYPASS_MASK                         (0x00004000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_BYPASS_SHIFT                        (0x0000000EU)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_IDDIG_BYPASS_MAX                          (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_THRESH_MASK                           (0x00018000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_THRESH_SHIFT                          (0x0000000FU)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_THRESH_MAX                            (0x00000003U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_BYPASS_MASK                           (0x00020000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_BYPASS_SHIFT                          (0x00000011U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_BYPASS_MAX                            (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_EN_MASK                               (0x00040000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_EN_SHIFT                              (0x00000012U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RID_EN_MAX                                (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_ANA_THRESH_MASK                 (0x00080000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_ANA_THRESH_SHIFT                (0x00000013U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_VBUSVALID_ANA_THRESH_MAX                  (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_FILTER_RESERVED31_20_MASK                        (0xFFF00000U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RESERVED31_20_SHIFT                       (0x00000014U)
#define CSL_USB3_GMOD_VBUS_ID_FILTER_RESERVED31_20_MAX                         (0x00000FFFU)

/* VBUS_ID_STAT */

#define CSL_USB3_GMOD_VBUS_ID_STAT_VBUSVALID_MASK                              (0x00000001U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_VBUSVALID_SHIFT                             (0x00000000U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_VBUSVALID_MAX                               (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_AVALID_MASK                                 (0x00000002U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_AVALID_SHIFT                                (0x00000001U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_AVALID_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_BVALID_MASK                                 (0x00000004U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_BVALID_SHIFT                                (0x00000002U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_BVALID_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_SESSEND_MASK                                (0x00000008U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_SESSEND_SHIFT                               (0x00000003U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_SESSEND_MAX                                 (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_IDDIG_MASK                                  (0x00000010U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_IDDIG_SHIFT                                 (0x00000004U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_IDDIG_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_A_MASK                                  (0x00000020U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_A_SHIFT                                 (0x00000005U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_A_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_B_MASK                                  (0x00000040U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_B_SHIFT                                 (0x00000006U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_B_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_C_MASK                                  (0x00000080U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_C_SHIFT                                 (0x00000007U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_C_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_GND_MASK                                (0x00000100U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_GND_SHIFT                               (0x00000008U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_GND_MAX                                 (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_FLOAT_MASK                              (0x00000200U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_FLOAT_SHIFT                             (0x00000009U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RID_FLOAT_MAX                               (0x00000001U)

#define CSL_USB3_GMOD_VBUS_ID_STAT_RESERVED31_25_MASK                          (0xFFFFFC00U)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RESERVED31_25_SHIFT                         (0x0000000AU)
#define CSL_USB3_GMOD_VBUS_ID_STAT_RESERVED31_25_MAX                           (0x003FFFFFU)

/* USB2PHY_CTRL_STAT */

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_AUTORESUME_EN_MASK                     (0x00000001U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_AUTORESUME_EN_SHIFT                    (0x00000000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_AUTORESUME_EN_MAX                      (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DISCHGDET_MASK                         (0x00000002U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DISCHGDET_SHIFT                        (0x00000001U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DISCHGDET_MAX                          (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_EXT_CTL_MASK                   (0x00000004U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_EXT_CTL_SHIFT                  (0x00000002U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_EXT_CTL_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDM_PD_CHGDET_EN_MASK                  (0x00000008U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDM_PD_CHGDET_EN_SHIFT                 (0x00000003U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDM_PD_CHGDET_EN_MAX                   (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDP_PU_CHGDET_EN_MASK                  (0x00000010U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDP_PU_CHGDET_EN_SHIFT                 (0x00000004U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RDP_PU_CHGDET_EN_MAX                   (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_VSRC_EN_MASK                       (0x00000020U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_VSRC_EN_SHIFT                      (0x00000005U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_VSRC_EN_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_ISINK_EN_MASK                      (0x00000040U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_ISINK_EN_SHIFT                     (0x00000006U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_ISINK_EN_MAX                       (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SINKONDP_MASK                          (0x00000080U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SINKONDP_SHIFT                         (0x00000007U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SINKONDP_MAX                           (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SRCONDM_MASK                           (0x00000100U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SRCONDM_SHIFT                          (0x00000008U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_SRCONDM_MAX                            (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESTARTCHGDET_MASK                     (0x00000200U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESTARTCHGDET_SHIFT                    (0x00000009U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESTARTCHGDET_MAX                      (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCPUEN_MASK                          (0x00000400U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCPUEN_SHIFT                         (0x0000000AU)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCPUEN_MAX                           (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCMODEEN_MASK                        (0x00000800U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCMODEEN_SHIFT                       (0x0000000BU)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_MCPCMODEEN_MAX                         (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATAPOLARITYN_MASK                     (0x00001000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATAPOLARITYN_SHIFT                    (0x0000000CU)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATAPOLARITYN_MAX                      (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CDP_NSDP_MASK                          (0x00002000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CDP_NSDP_SHIFT                         (0x0000000DU)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CDP_NSDP_MAX                           (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_STATUS_MASK                    (0x0001C000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_STATUS_SHIFT                   (0x0000000EU)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_STATUS_MAX                     (0x00000007U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DM_COMP_MASK                   (0x00020000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DM_COMP_SHIFT                  (0x00000011U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DM_COMP_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DP_COMP_MASK                   (0x00040000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DP_COMP_SHIFT                  (0x00000012U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHG_DET_DP_COMP_MAX                    (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATADET_MASK                           (0x00080000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATADET_SHIFT                          (0x00000013U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_DATADET_MAX                            (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETDONE_MASK                        (0x00100000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETDONE_SHIFT                       (0x00000014U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETDONE_MAX                         (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETECTED_MASK                       (0x00200000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETECTED_SHIFT                      (0x00000015U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_CHGDETECTED_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESERVED31_22_MASK                     (0xFFC00000U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESERVED31_22_SHIFT                    (0x00000016U)
#define CSL_USB3_GMOD_USB2PHY_CTRL_STAT_RESERVED31_22_MAX                      (0x000003FFU)

/* MMRAM_OFFSET */

#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_MSB_MASK                             (0x000F8000U)
#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_MSB_SHIFT                            (0x0000000FU)
#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_MSB_MAX                              (0x0000001FU)

#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_LSB_MASK                             (0x00007FFFU)
#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_LSB_SHIFT                            (0x00000000U)
#define CSL_USB3_GMOD_MMRAM_OFFSET_OFFSET_LSB_MAX                              (0x00007FFFU)

#define CSL_USB3_GMOD_MMRAM_OFFSET_RESERVED31_20_MASK                          (0xFFF00000U)
#define CSL_USB3_GMOD_MMRAM_OFFSET_RESERVED31_20_SHIFT                         (0x00000014U)
#define CSL_USB3_GMOD_MMRAM_OFFSET_RESERVED31_20_MAX                           (0x00000FFFU)

/* CORE_CTL */

#define CSL_USB3_GMOD_CORE_CTL_RESERVED26_21_MASK                              (0x07E00000U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED26_21_SHIFT                             (0x00000015U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED26_21_MAX                               (0x0000003FU)

#define CSL_USB3_GMOD_CORE_CTL_RESERVED20_0_MASK                               (0x001FFFFFU)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED20_0_SHIFT                              (0x00000000U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED20_0_MAX                                (0x001FFFFFU)

#define CSL_USB3_GMOD_CORE_CTL_HOST_U2_PORT_DISABLE_MASK                       (0x08000000U)
#define CSL_USB3_GMOD_CORE_CTL_HOST_U2_PORT_DISABLE_SHIFT                      (0x0000001BU)
#define CSL_USB3_GMOD_CORE_CTL_HOST_U2_PORT_DISABLE_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_CORE_CTL_HOST_U3_PORT_DISABLE_MASK                       (0x10000000U)
#define CSL_USB3_GMOD_CORE_CTL_HOST_U3_PORT_DISABLE_SHIFT                      (0x0000001CU)
#define CSL_USB3_GMOD_CORE_CTL_HOST_U3_PORT_DISABLE_MAX                        (0x00000001U)

#define CSL_USB3_GMOD_CORE_CTL_RESERVED29_MASK                                 (0x20000000U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED29_SHIFT                                (0x0000001DU)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED29_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_CORE_CTL_RESERVED30_MASK                                 (0x40000000U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED30_SHIFT                                (0x0000001EU)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED30_MAX                                  (0x00000001U)

#define CSL_USB3_GMOD_CORE_CTL_RESERVED31_MASK                                 (0x80000000U)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED31_SHIFT                                (0x0000001FU)
#define CSL_USB3_GMOD_CORE_CTL_RESERVED31_MAX                                  (0x00000001U)

/* DEBUG_CFG */

#define CSL_USB3_GMOD_DEBUG_CFG_SEL_DBG_MASK                                   (0x00000007U)
#define CSL_USB3_GMOD_DEBUG_CFG_SEL_DBG_SHIFT                                  (0x00000000U)
#define CSL_USB3_GMOD_DEBUG_CFG_SEL_DBG_MAX                                    (0x00000007U)

#define CSL_USB3_GMOD_DEBUG_CFG_RESERVED31_3_MASK                              (0xFFFFFFF8U)
#define CSL_USB3_GMOD_DEBUG_CFG_RESERVED31_3_SHIFT                             (0x00000003U)
#define CSL_USB3_GMOD_DEBUG_CFG_RESERVED31_3_MAX                               (0x1FFFFFFFU)

/* DEBUG_DATA */

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG0_MASK                                   (0x00000001U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG0_SHIFT                                  (0x00000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG0_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG1_MASK                                   (0x00000002U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG1_SHIFT                                  (0x00000001U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG1_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG2_MASK                                   (0x00000004U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG2_SHIFT                                  (0x00000002U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG2_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG3_MASK                                   (0x00000008U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG3_SHIFT                                  (0x00000003U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG3_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG4_MASK                                   (0x00000010U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG4_SHIFT                                  (0x00000004U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG4_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG5_MASK                                   (0x00000020U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG5_SHIFT                                  (0x00000005U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG5_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG6_MASK                                   (0x00000040U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG6_SHIFT                                  (0x00000006U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG6_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG7_MASK                                   (0x00000080U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG7_SHIFT                                  (0x00000007U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG7_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG8_MASK                                   (0x00000100U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG8_SHIFT                                  (0x00000008U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG8_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG9_MASK                                   (0x00000200U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG9_SHIFT                                  (0x00000009U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG9_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG10_MASK                                  (0x00000400U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG10_SHIFT                                 (0x0000000AU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG10_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG11_MASK                                  (0x00000800U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG11_SHIFT                                 (0x0000000BU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG11_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG12_MASK                                  (0x00001000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG12_SHIFT                                 (0x0000000CU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG12_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG13_MASK                                  (0x00002000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG13_SHIFT                                 (0x0000000DU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG13_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG14_MASK                                  (0x00004000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG14_SHIFT                                 (0x0000000EU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG14_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG15_MASK                                  (0x00008000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG15_SHIFT                                 (0x0000000FU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG15_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG16_MASK                                  (0x00010000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG16_SHIFT                                 (0x00000010U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG16_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG17_MASK                                  (0x00020000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG17_SHIFT                                 (0x00000011U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG17_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG18_MASK                                  (0x00040000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG18_SHIFT                                 (0x00000012U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG18_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG19_MASK                                  (0x00080000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG19_SHIFT                                 (0x00000013U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG19_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG20_MASK                                  (0x00100000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG20_SHIFT                                 (0x00000014U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG20_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG21_MASK                                  (0x00200000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG21_SHIFT                                 (0x00000015U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG21_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG22_MASK                                  (0x00400000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG22_SHIFT                                 (0x00000016U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG22_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG23_MASK                                  (0x00800000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG23_SHIFT                                 (0x00000017U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG23_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG24_MASK                                  (0x01000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG24_SHIFT                                 (0x00000018U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG24_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG25_MASK                                  (0x02000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG25_SHIFT                                 (0x00000019U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG25_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG26_MASK                                  (0x04000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG26_SHIFT                                 (0x0000001AU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG26_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG27_MASK                                  (0x08000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG27_SHIFT                                 (0x0000001BU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG27_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG28_MASK                                  (0x10000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG28_SHIFT                                 (0x0000001CU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG28_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG29_MASK                                  (0x20000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG29_SHIFT                                 (0x0000001DU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG29_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG30_MASK                                  (0x40000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG30_SHIFT                                 (0x0000001EU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG30_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG31_MASK                                  (0x80000000U)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG31_SHIFT                                 (0x0000001FU)
#define CSL_USB3_GMOD_DEBUG_DATA_DEBUG31_MAX                                   (0x00000001U)

/* DEV_EBC_EN */

#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED13_0_MASK                             (0x00003FFFU)
#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED13_0_SHIFT                            (0x00000000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED13_0_MAX                              (0x00003FFFU)

#define CSL_USB3_GMOD_DEV_EBC_EN_INEP14_MASK                                   (0x00004000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_INEP14_SHIFT                                  (0x0000000EU)
#define CSL_USB3_GMOD_DEV_EBC_EN_INEP14_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEV_EBC_EN_INEP15_MASK                                   (0x00008000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_INEP15_SHIFT                                  (0x0000000FU)
#define CSL_USB3_GMOD_DEV_EBC_EN_INEP15_MAX                                    (0x00000001U)

#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED29_16_MASK                            (0x3FFF0000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED29_16_SHIFT                           (0x00000010U)
#define CSL_USB3_GMOD_DEV_EBC_EN_RESERVED29_16_MAX                             (0x00003FFFU)

#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP14_MASK                                  (0x40000000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP14_SHIFT                                 (0x0000001EU)
#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP14_MAX                                   (0x00000001U)

#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP15_MASK                                  (0x80000000U)
#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP15_SHIFT                                 (0x0000001FU)
#define CSL_USB3_GMOD_DEV_EBC_EN_OUTEP15_MAX                                   (0x00000001U)

/* HOST_HUB_CTRL */

#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_MASK                  (0x00000003U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_SHIFT                 (0x00000000U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_MAX                   (0x00000003U)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_MASK       (0x00000004U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_SHIFT      (0x00000002U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_MAX        (0x00000001U)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED4_MASK                             (0x00000018U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED4_SHIFT                            (0x00000003U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED4_MAX                              (0x00000003U)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_XHC_BME_MASK                               (0x00000020U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_XHC_BME_SHIFT                              (0x00000005U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_XHC_BME_MAX                                (0x00000001U)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_MASK                  (0x000000C0U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_SHIFT                 (0x00000006U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_MAX                   (0x00000003U)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_BUS_FILTER_BYPASS_MASK                     (0x00000F00U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_BUS_FILTER_BYPASS_SHIFT                    (0x00000008U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_BUS_FILTER_BYPASS_MAX                      (0x0000000FU)

#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED31_12_MASK                         (0xFFFFF000U)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED31_12_SHIFT                        (0x0000000CU)
#define CSL_USB3_GMOD_HOST_HUB_CTRL_RESERVED31_12_MAX                          (0x000FFFFFU)

/**************************************************************************
* Hardware Region  : USB3 core RAM debug, offset 0x08000
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t USB3_CORE_RAM[8192];       /* USB3 core RAM */
} CSL_usb3_ramdbgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_RAMDBG_USB3_CORE_RAM(USB3_CORE_RAM)                           (0x00008000U+((USB3_CORE_RAM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* USB3_CORE_RAM */

#define CSL_USB3_RAMDBG_USB3_CORE_RAM_CORE_RAM_MASK                            (0xFFFFFFFFU)
#define CSL_USB3_RAMDBG_USB3_CORE_RAM_CORE_RAM_SHIFT                           (0x00000000U)
#define CSL_USB3_RAMDBG_USB3_CORE_RAM_CORE_RAM_MAX                             (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : RAM ECC aggregator
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REV;                       /* Aggregator Revision Register */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t VECTOR;                    /* ECC Vector Register */
    volatile uint32_t STAT;                      /* Misc Status */
    volatile uint32_t WRAP_REV;                  /* ECC Wrapper Revision Register */
    volatile uint32_t CTRL;                      /* ECC Control */
    volatile uint32_t ERR_CTRL1;                 /* ECC Error Control1 Register */
    volatile uint32_t ERR_CTRL2;                 /* ECC Error Control2 Register */
    volatile uint32_t ERR_STAT1;                 /* ECC Error Status1 Register */
    volatile uint32_t ERR_STAT2;                 /* ECC Error Status2 Register */
    volatile uint32_t ERR_STAT3;                 /* ECC Error Status3 Register */
    volatile uint8_t  Resv_60[16];
    volatile uint32_t SEC_EOI_REG;               /* EOI Register */
    volatile uint32_t SEC_STATUS_REG0;           /* Interrupt Status Register 0 */
    volatile uint8_t  Resv_128[60];
    volatile uint32_t SEC_ENABLE_SET_REG0;       /* Interrupt Enable Set Register 0 */
    volatile uint8_t  Resv_192[60];
    volatile uint32_t SEC_ENABLE_CLR_REG0;       /* Interrupt Enable Clear Register 0 */
    volatile uint8_t  Resv_316[120];
    volatile uint32_t DED_EOI_REG;               /* EOI Register */
    volatile uint32_t DED_STATUS_REG0;           /* Interrupt Status Register 0 */
    volatile uint8_t  Resv_384[60];
    volatile uint32_t DED_ENABLE_SET_REG0;       /* Interrupt Enable Set Register 0 */
    volatile uint8_t  Resv_448[60];
    volatile uint32_t DED_ENABLE_CLR_REG0;       /* Interrupt Enable Clear Register 0 */
    volatile uint8_t  Resv_512[60];
    volatile uint32_t AGGR_ENABLE_SET;           /* AGGR interrupt enable set Register */
    volatile uint32_t AGGR_ENABLE_CLR;           /* AGGR interrupt enable clear Register */
    volatile uint32_t AGGR_STATUS_SET;           /* AGGR interrupt status set Register */
    volatile uint32_t AGGR_STATUS_CLR;           /* AGGR interrupt status clear Register */
} CSL_usb3_ecc_aggrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_ECC_AGGR_REV                                                  (0x00000000U)
#define CSL_USB3_ECC_AGGR_VECTOR                                               (0x00000008U)
#define CSL_USB3_ECC_AGGR_STAT                                                 (0x0000000CU)
#define CSL_USB3_ECC_AGGR_WRAP_REV                                             (0x00000010U)
#define CSL_USB3_ECC_AGGR_CTRL                                                 (0x00000014U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL1                                            (0x00000018U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL2                                            (0x0000001CU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1                                            (0x00000020U)
#define CSL_USB3_ECC_AGGR_ERR_STAT2                                            (0x00000024U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3                                            (0x00000028U)
#define CSL_USB3_ECC_AGGR_SEC_EOI_REG                                          (0x0000003CU)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0                                      (0x00000040U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0                                  (0x00000080U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0                                  (0x000000C0U)
#define CSL_USB3_ECC_AGGR_DED_EOI_REG                                          (0x0000013CU)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0                                      (0x00000140U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0                                  (0x00000180U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0                                  (0x000001C0U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET                                      (0x00000200U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR                                      (0x00000204U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET                                      (0x00000208U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR                                      (0x0000020CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REV */

#define CSL_USB3_ECC_AGGR_REV_SCHEME_MASK                                      (0xC0000000U)
#define CSL_USB3_ECC_AGGR_REV_SCHEME_SHIFT                                     (0x0000001EU)
#define CSL_USB3_ECC_AGGR_REV_SCHEME_MAX                                       (0x00000003U)

#define CSL_USB3_ECC_AGGR_REV_BU_MASK                                          (0x30000000U)
#define CSL_USB3_ECC_AGGR_REV_BU_SHIFT                                         (0x0000001CU)
#define CSL_USB3_ECC_AGGR_REV_BU_MAX                                           (0x00000003U)

#define CSL_USB3_ECC_AGGR_REV_MODULE_ID_MASK                                   (0x0FFF0000U)
#define CSL_USB3_ECC_AGGR_REV_MODULE_ID_SHIFT                                  (0x00000010U)
#define CSL_USB3_ECC_AGGR_REV_MODULE_ID_MAX                                    (0x00000FFFU)

#define CSL_USB3_ECC_AGGR_REV_REVRTL_MASK                                      (0x0000F800U)
#define CSL_USB3_ECC_AGGR_REV_REVRTL_SHIFT                                     (0x0000000BU)
#define CSL_USB3_ECC_AGGR_REV_REVRTL_MAX                                       (0x0000001FU)

#define CSL_USB3_ECC_AGGR_REV_REVMAJ_MASK                                      (0x00000700U)
#define CSL_USB3_ECC_AGGR_REV_REVMAJ_SHIFT                                     (0x00000008U)
#define CSL_USB3_ECC_AGGR_REV_REVMAJ_MAX                                       (0x00000007U)

#define CSL_USB3_ECC_AGGR_REV_CUSTOM_MASK                                      (0x000000C0U)
#define CSL_USB3_ECC_AGGR_REV_CUSTOM_SHIFT                                     (0x00000006U)
#define CSL_USB3_ECC_AGGR_REV_CUSTOM_MAX                                       (0x00000003U)

#define CSL_USB3_ECC_AGGR_REV_REVMIN_MASK                                      (0x0000003FU)
#define CSL_USB3_ECC_AGGR_REV_REVMIN_SHIFT                                     (0x00000000U)
#define CSL_USB3_ECC_AGGR_REV_REVMIN_MAX                                       (0x0000003FU)

/* VECTOR */

#define CSL_USB3_ECC_AGGR_VECTOR_ECC_VECTOR_MASK                               (0x000007FFU)
#define CSL_USB3_ECC_AGGR_VECTOR_ECC_VECTOR_SHIFT                              (0x00000000U)
#define CSL_USB3_ECC_AGGR_VECTOR_ECC_VECTOR_MAX                                (0x000007FFU)

#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_MASK                                 (0x00008000U)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_SHIFT                                (0x0000000FU)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_MAX                                  (0x00000001U)

#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_MASK                         (0x00FF0000U)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_SHIFT                        (0x00000010U)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS_MAX                          (0x000000FFU)

#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_DONE_MASK                            (0x01000000U)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_DONE_SHIFT                           (0x00000018U)
#define CSL_USB3_ECC_AGGR_VECTOR_RD_SVBUS_DONE_MAX                             (0x00000001U)

/* STAT */

#define CSL_USB3_ECC_AGGR_STAT_NUM_RAMS_MASK                                   (0x000007FFU)
#define CSL_USB3_ECC_AGGR_STAT_NUM_RAMS_SHIFT                                  (0x00000000U)
#define CSL_USB3_ECC_AGGR_STAT_NUM_RAMS_MAX                                    (0x000007FFU)

/* WRAP_REV */

#define CSL_USB3_ECC_AGGR_WRAP_REV_SCHEME_MASK                                 (0xC0000000U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_SCHEME_SHIFT                                (0x0000001EU)
#define CSL_USB3_ECC_AGGR_WRAP_REV_SCHEME_MAX                                  (0x00000003U)

#define CSL_USB3_ECC_AGGR_WRAP_REV_BU_MASK                                     (0x30000000U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_BU_SHIFT                                    (0x0000001CU)
#define CSL_USB3_ECC_AGGR_WRAP_REV_BU_MAX                                      (0x00000003U)

#define CSL_USB3_ECC_AGGR_WRAP_REV_MODULE_ID_MASK                              (0x0FFF0000U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_MODULE_ID_SHIFT                             (0x00000010U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_MODULE_ID_MAX                               (0x00000FFFU)

#define CSL_USB3_ECC_AGGR_WRAP_REV_REVRTL_MASK                                 (0x0000F800U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVRTL_SHIFT                                (0x0000000BU)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVRTL_MAX                                  (0x0000001FU)

#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMAJ_MASK                                 (0x00000700U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMAJ_SHIFT                                (0x00000008U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMAJ_MAX                                  (0x00000007U)

#define CSL_USB3_ECC_AGGR_WRAP_REV_CUSTOM_MASK                                 (0x000000C0U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_CUSTOM_SHIFT                                (0x00000006U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_CUSTOM_MAX                                  (0x00000003U)

#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMIN_MASK                                 (0x0000003FU)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMIN_SHIFT                                (0x00000000U)
#define CSL_USB3_ECC_AGGR_WRAP_REV_REVMIN_MAX                                  (0x0000003FU)

/* CTRL */

#define CSL_USB3_ECC_AGGR_CTRL_ECC_ENABLE_MASK                                 (0x00000001U)
#define CSL_USB3_ECC_AGGR_CTRL_ECC_ENABLE_SHIFT                                (0x00000000U)
#define CSL_USB3_ECC_AGGR_CTRL_ECC_ENABLE_MAX                                  (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_ECC_CHECK_MASK                                  (0x00000002U)
#define CSL_USB3_ECC_AGGR_CTRL_ECC_CHECK_SHIFT                                 (0x00000001U)
#define CSL_USB3_ECC_AGGR_CTRL_ECC_CHECK_MAX                                   (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_ENABLE_RMW_MASK                                 (0x00000004U)
#define CSL_USB3_ECC_AGGR_CTRL_ENABLE_RMW_SHIFT                                (0x00000002U)
#define CSL_USB3_ECC_AGGR_CTRL_ENABLE_RMW_MAX                                  (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_FORCE_SEC_MASK                                  (0x00000008U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_SEC_SHIFT                                 (0x00000003U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_SEC_MAX                                   (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_FORCE_DED_MASK                                  (0x00000010U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_DED_SHIFT                                 (0x00000004U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_DED_MAX                                   (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_FORCE_N_ROW_MASK                                (0x00000020U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_N_ROW_SHIFT                               (0x00000005U)
#define CSL_USB3_ECC_AGGR_CTRL_FORCE_N_ROW_MAX                                 (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_ERROR_ONCE_MASK                                 (0x00000040U)
#define CSL_USB3_ECC_AGGR_CTRL_ERROR_ONCE_SHIFT                                (0x00000006U)
#define CSL_USB3_ECC_AGGR_CTRL_ERROR_ONCE_MAX                                  (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_CHECK_PARITY_MASK                               (0x00000080U)
#define CSL_USB3_ECC_AGGR_CTRL_CHECK_PARITY_SHIFT                              (0x00000007U)
#define CSL_USB3_ECC_AGGR_CTRL_CHECK_PARITY_MAX                                (0x00000001U)

#define CSL_USB3_ECC_AGGR_CTRL_CHECK_SVBUS_TIMEOUT_MASK                        (0x00000100U)
#define CSL_USB3_ECC_AGGR_CTRL_CHECK_SVBUS_TIMEOUT_SHIFT                       (0x00000008U)
#define CSL_USB3_ECC_AGGR_CTRL_CHECK_SVBUS_TIMEOUT_MAX                         (0x00000001U)

/* ERR_CTRL1 */

#define CSL_USB3_ECC_AGGR_ERR_CTRL1_ECC_ROW_MASK                               (0xFFFFFFFFU)
#define CSL_USB3_ECC_AGGR_ERR_CTRL1_ECC_ROW_SHIFT                              (0x00000000U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL1_ECC_ROW_MAX                                (0xFFFFFFFFU)

/* ERR_CTRL2 */

#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT1_MASK                              (0x0000FFFFU)
#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT1_SHIFT                             (0x00000000U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT1_MAX                               (0x0000FFFFU)

#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT2_MASK                              (0xFFFF0000U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT2_SHIFT                             (0x00000010U)
#define CSL_USB3_ECC_AGGR_ERR_CTRL2_ECC_BIT2_MAX                               (0x0000FFFFU)

/* ERR_STAT1 */

#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_SEC_MASK                               (0x00000003U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_SEC_SHIFT                              (0x00000000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_SEC_MAX                                (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_DED_MASK                               (0x0000000CU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_DED_SHIFT                              (0x00000002U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_DED_MAX                                (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_OTHER_MASK                             (0x00000010U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_OTHER_SHIFT                            (0x00000004U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_OTHER_MAX                              (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_PARITY_ERR_MASK                            (0x00000060U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_PARITY_ERR_SHIFT                           (0x00000005U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_PARITY_ERR_MAX                             (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CTR_REG_ERR_MASK                           (0x00000080U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CTR_REG_ERR_SHIFT                          (0x00000007U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CTR_REG_ERR_MAX                            (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_MASK                           (0x00000300U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_SHIFT                          (0x00000008U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_SEC_MAX                            (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_MASK                           (0x00000C00U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_SHIFT                          (0x0000000AU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_DED_MAX                            (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_OTHER_MASK                         (0x00001000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_OTHER_SHIFT                        (0x0000000CU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_ECC_OTHER_MAX                          (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_PARITY_ERR_MASK                        (0x00006000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_PARITY_ERR_SHIFT                       (0x0000000DU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_PARITY_ERR_MAX                         (0x00000003U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_CTRL_REG_ERR_MASK                      (0x00008000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_CTRL_REG_ERR_SHIFT                     (0x0000000FU)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_CLR_CTRL_REG_ERR_MAX                       (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_BIT1_MASK                              (0xFFFF0000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_BIT1_SHIFT                             (0x00000010U)
#define CSL_USB3_ECC_AGGR_ERR_STAT1_ECC_BIT1_MAX                               (0x0000FFFFU)

/* ERR_STAT2 */

#define CSL_USB3_ECC_AGGR_ERR_STAT2_ECC_ROW_MASK                               (0xFFFFFFFFU)
#define CSL_USB3_ECC_AGGR_ERR_STAT2_ECC_ROW_SHIFT                              (0x00000000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT2_ECC_ROW_MAX                                (0xFFFFFFFFU)

/* ERR_STAT3 */

#define CSL_USB3_ECC_AGGR_ERR_STAT3_WB_PEND_MASK                               (0x00000001U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_WB_PEND_SHIFT                              (0x00000000U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_WB_PEND_MAX                                (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT3_SVBUS_TIMEOUT_ERR_MASK                     (0x00000002U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_SVBUS_TIMEOUT_ERR_SHIFT                    (0x00000001U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_SVBUS_TIMEOUT_ERR_MAX                      (0x00000001U)

#define CSL_USB3_ECC_AGGR_ERR_STAT3_CLR_SVBUS_TIMEOUT_ERR_MASK                 (0x00000200U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_CLR_SVBUS_TIMEOUT_ERR_SHIFT                (0x00000009U)
#define CSL_USB3_ECC_AGGR_ERR_STAT3_CLR_SVBUS_TIMEOUT_ERR_MAX                  (0x00000001U)

/* SEC_EOI_REG */

#define CSL_USB3_ECC_AGGR_SEC_EOI_REG_EOI_WR_MASK                              (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_EOI_REG_EOI_WR_SHIFT                             (0x00000000U)
#define CSL_USB3_ECC_AGGR_SEC_EOI_REG_EOI_WR_MAX                               (0x00000001U)

/* SEC_STATUS_REG0 */

#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM0_PEND_MASK                       (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM0_PEND_SHIFT                      (0x00000000U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM0_PEND_MAX                        (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM1_PEND_MASK                       (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM1_PEND_SHIFT                      (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM1_PEND_MAX                        (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM2_PEND_MASK                       (0x00000004U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM2_PEND_SHIFT                      (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_STATUS_REG0_RAM2_PEND_MAX                        (0x00000001U)

/* SEC_ENABLE_SET_REG0 */

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM0_ENABLE_SET_MASK             (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM0_ENABLE_SET_SHIFT            (0x00000000U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM0_ENABLE_SET_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM1_ENABLE_SET_MASK             (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM1_ENABLE_SET_SHIFT            (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM1_ENABLE_SET_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM2_ENABLE_SET_MASK             (0x00000004U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM2_ENABLE_SET_SHIFT            (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_SET_REG0_RAM2_ENABLE_SET_MAX              (0x00000001U)

/* SEC_ENABLE_CLR_REG0 */

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_MASK             (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_SHIFT            (0x00000000U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_MASK             (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_SHIFT            (0x00000001U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_MASK             (0x00000004U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_SHIFT            (0x00000002U)
#define CSL_USB3_ECC_AGGR_SEC_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_MAX              (0x00000001U)

/* DED_EOI_REG */

#define CSL_USB3_ECC_AGGR_DED_EOI_REG_EOI_WR_MASK                              (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_EOI_REG_EOI_WR_SHIFT                             (0x00000000U)
#define CSL_USB3_ECC_AGGR_DED_EOI_REG_EOI_WR_MAX                               (0x00000001U)

/* DED_STATUS_REG0 */

#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM0_PEND_MASK                       (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM0_PEND_SHIFT                      (0x00000000U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM0_PEND_MAX                        (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM1_PEND_MASK                       (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM1_PEND_SHIFT                      (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM1_PEND_MAX                        (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM2_PEND_MASK                       (0x00000004U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM2_PEND_SHIFT                      (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_STATUS_REG0_RAM2_PEND_MAX                        (0x00000001U)

/* DED_ENABLE_SET_REG0 */

#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM0_ENABLE_SET_MASK             (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM0_ENABLE_SET_SHIFT            (0x00000000U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM0_ENABLE_SET_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM1_ENABLE_SET_MASK             (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM1_ENABLE_SET_SHIFT            (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM1_ENABLE_SET_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM2_ENABLE_SET_MASK             (0x00000004U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM2_ENABLE_SET_SHIFT            (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_SET_REG0_RAM2_ENABLE_SET_MAX              (0x00000001U)

/* DED_ENABLE_CLR_REG0 */

#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_MASK             (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_SHIFT            (0x00000000U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM0_ENABLE_CLR_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_MASK             (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_SHIFT            (0x00000001U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM1_ENABLE_CLR_MAX              (0x00000001U)

#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_MASK             (0x00000004U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_SHIFT            (0x00000002U)
#define CSL_USB3_ECC_AGGR_DED_ENABLE_CLR_REG0_RAM2_ENABLE_CLR_MAX              (0x00000001U)

/* AGGR_ENABLE_SET */

#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_PARITY_MASK                          (0x00000001U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_PARITY_SHIFT                         (0x00000000U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_PARITY_MAX                           (0x00000001U)

#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_TIMEOUT_MASK                         (0x00000002U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_TIMEOUT_SHIFT                        (0x00000001U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_SET_TIMEOUT_MAX                          (0x00000001U)

/* AGGR_ENABLE_CLR */

#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_PARITY_MASK                          (0x00000001U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_PARITY_SHIFT                         (0x00000000U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_PARITY_MAX                           (0x00000001U)

#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_TIMEOUT_MASK                         (0x00000002U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_TIMEOUT_SHIFT                        (0x00000001U)
#define CSL_USB3_ECC_AGGR_AGGR_ENABLE_CLR_TIMEOUT_MAX                          (0x00000001U)

/* AGGR_STATUS_SET */

#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_PARITY_MASK                          (0x00000003U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_PARITY_SHIFT                         (0x00000000U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_PARITY_MAX                           (0x00000003U)

#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_TIMEOUT_MASK                         (0x0000000CU)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_TIMEOUT_SHIFT                        (0x00000002U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_SET_TIMEOUT_MAX                          (0x00000003U)

/* AGGR_STATUS_CLR */

#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_PARITY_MASK                          (0x00000003U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_PARITY_SHIFT                         (0x00000000U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_PARITY_MAX                           (0x00000003U)

#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_TIMEOUT_MASK                         (0x0000000CU)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_TIMEOUT_SHIFT                        (0x00000002U)
#define CSL_USB3_ECC_AGGR_AGGR_STATUS_CLR_TIMEOUT_MAX                          (0x00000003U)

/**************************************************************************
* Hardware Region  : USB3 eXtensible Host Controller Capability Register Block, 0x10000
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CAPLENGTH;                 /* CAPLENGTH */
    volatile uint32_t HCSPARAMS1;                /* HCSPARAMS1 */
    volatile uint32_t HCSPARAMS2;                /* HCSPARAMS2 */
    volatile uint32_t HCSPARAMS3;                /* HCSPARAMS3 */
    volatile uint32_t HCCPARAMS1;                /* HCCPARAMS1 */
    volatile uint32_t DBOFF;                     /* DBOFF */
    volatile uint32_t RTSOFF;                    /* RTSOFF */
    volatile uint32_t HCCPARAMS2;                /* HCCPARAMS2 */
} CSL_usb3_capRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_CAP_CAPLENGTH                                                 (0x00010000U)
#define CSL_USB3_CAP_HCSPARAMS1                                                (0x00010004U)
#define CSL_USB3_CAP_HCSPARAMS2                                                (0x00010008U)
#define CSL_USB3_CAP_HCSPARAMS3                                                (0x0001000CU)
#define CSL_USB3_CAP_HCCPARAMS1                                                (0x00010010U)
#define CSL_USB3_CAP_DBOFF                                                     (0x00010014U)
#define CSL_USB3_CAP_RTSOFF                                                    (0x00010018U)
#define CSL_USB3_CAP_HCCPARAMS2                                                (0x0001001CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CAPLENGTH */

#define CSL_USB3_CAP_CAPLENGTH_CAPLENGTH_MASK                                  (0x000000FFU)
#define CSL_USB3_CAP_CAPLENGTH_CAPLENGTH_SHIFT                                 (0x00000000U)
#define CSL_USB3_CAP_CAPLENGTH_CAPLENGTH_MAX                                   (0x000000FFU)

#define CSL_USB3_CAP_CAPLENGTH_RESERVED_15_8_MASK                              (0x0000FF00U)
#define CSL_USB3_CAP_CAPLENGTH_RESERVED_15_8_SHIFT                             (0x00000008U)
#define CSL_USB3_CAP_CAPLENGTH_RESERVED_15_8_MAX                               (0x000000FFU)

#define CSL_USB3_CAP_CAPLENGTH_HCIVERSION_MASK                                 (0xFFFF0000U)
#define CSL_USB3_CAP_CAPLENGTH_HCIVERSION_SHIFT                                (0x00000010U)
#define CSL_USB3_CAP_CAPLENGTH_HCIVERSION_MAX                                  (0x0000FFFFU)

/* HCSPARAMS1 */

#define CSL_USB3_CAP_HCSPARAMS1_MAXSLOTS_MASK                                  (0x000000FFU)
#define CSL_USB3_CAP_HCSPARAMS1_MAXSLOTS_SHIFT                                 (0x00000000U)
#define CSL_USB3_CAP_HCSPARAMS1_MAXSLOTS_MAX                                   (0x000000FFU)

#define CSL_USB3_CAP_HCSPARAMS1_MAXINTRS_MASK                                  (0x0007FF00U)
#define CSL_USB3_CAP_HCSPARAMS1_MAXINTRS_SHIFT                                 (0x00000008U)
#define CSL_USB3_CAP_HCSPARAMS1_MAXINTRS_MAX                                   (0x000007FFU)

#define CSL_USB3_CAP_HCSPARAMS1_RESERVED_23_19_MASK                            (0x00F80000U)
#define CSL_USB3_CAP_HCSPARAMS1_RESERVED_23_19_SHIFT                           (0x00000013U)
#define CSL_USB3_CAP_HCSPARAMS1_RESERVED_23_19_MAX                             (0x0000001FU)

#define CSL_USB3_CAP_HCSPARAMS1_MAXPORTS_MASK                                  (0xFF000000U)
#define CSL_USB3_CAP_HCSPARAMS1_MAXPORTS_SHIFT                                 (0x00000018U)
#define CSL_USB3_CAP_HCSPARAMS1_MAXPORTS_MAX                                   (0x000000FFU)

/* HCSPARAMS2 */

#define CSL_USB3_CAP_HCSPARAMS2_IST_MASK                                       (0x0000000FU)
#define CSL_USB3_CAP_HCSPARAMS2_IST_SHIFT                                      (0x00000000U)
#define CSL_USB3_CAP_HCSPARAMS2_IST_MAX                                        (0x0000000FU)

#define CSL_USB3_CAP_HCSPARAMS2_ERSTMAX_MASK                                   (0x000000F0U)
#define CSL_USB3_CAP_HCSPARAMS2_ERSTMAX_SHIFT                                  (0x00000004U)
#define CSL_USB3_CAP_HCSPARAMS2_ERSTMAX_MAX                                    (0x0000000FU)

#define CSL_USB3_CAP_HCSPARAMS2_RESERVED_20_8_MASK                             (0x001FFF00U)
#define CSL_USB3_CAP_HCSPARAMS2_RESERVED_20_8_SHIFT                            (0x00000008U)
#define CSL_USB3_CAP_HCSPARAMS2_RESERVED_20_8_MAX                              (0x00001FFFU)

#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK                      (0x03E00000U)
#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT                     (0x00000015U)
#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MAX                       (0x0000001FU)

#define CSL_USB3_CAP_HCSPARAMS2_SPR_MASK                                       (0x04000000U)
#define CSL_USB3_CAP_HCSPARAMS2_SPR_SHIFT                                      (0x0000001AU)
#define CSL_USB3_CAP_HCSPARAMS2_SPR_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_MASK                         (0xF8000000U)
#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_SHIFT                        (0x0000001BU)
#define CSL_USB3_CAP_HCSPARAMS2_MAXSCRATCHPADBUFS_MAX                          (0x0000001FU)

/* HCSPARAMS3 */

#define CSL_USB3_CAP_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK                        (0x000000FFU)
#define CSL_USB3_CAP_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT                       (0x00000000U)
#define CSL_USB3_CAP_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MAX                         (0x000000FFU)

#define CSL_USB3_CAP_HCSPARAMS3_RESERVED_15_8_MASK                             (0x0000FF00U)
#define CSL_USB3_CAP_HCSPARAMS3_RESERVED_15_8_SHIFT                            (0x00000008U)
#define CSL_USB3_CAP_HCSPARAMS3_RESERVED_15_8_MAX                              (0x000000FFU)

#define CSL_USB3_CAP_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK                        (0xFFFF0000U)
#define CSL_USB3_CAP_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT                       (0x00000010U)
#define CSL_USB3_CAP_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MAX                         (0x0000FFFFU)

/* HCCPARAMS1 */

#define CSL_USB3_CAP_HCCPARAMS1_AC64_MASK                                      (0x00000001U)
#define CSL_USB3_CAP_HCCPARAMS1_AC64_SHIFT                                     (0x00000000U)
#define CSL_USB3_CAP_HCCPARAMS1_AC64_MAX                                       (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_BNC_MASK                                       (0x00000002U)
#define CSL_USB3_CAP_HCCPARAMS1_BNC_SHIFT                                      (0x00000001U)
#define CSL_USB3_CAP_HCCPARAMS1_BNC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_CSZ_MASK                                       (0x00000004U)
#define CSL_USB3_CAP_HCCPARAMS1_CSZ_SHIFT                                      (0x00000002U)
#define CSL_USB3_CAP_HCCPARAMS1_CSZ_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_PPC_MASK                                       (0x00000008U)
#define CSL_USB3_CAP_HCCPARAMS1_PPC_SHIFT                                      (0x00000003U)
#define CSL_USB3_CAP_HCCPARAMS1_PPC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_PIND_MASK                                      (0x00000010U)
#define CSL_USB3_CAP_HCCPARAMS1_PIND_SHIFT                                     (0x00000004U)
#define CSL_USB3_CAP_HCCPARAMS1_PIND_MAX                                       (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_LHRC_MASK                                      (0x00000020U)
#define CSL_USB3_CAP_HCCPARAMS1_LHRC_SHIFT                                     (0x00000005U)
#define CSL_USB3_CAP_HCCPARAMS1_LHRC_MAX                                       (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_LTC_MASK                                       (0x00000040U)
#define CSL_USB3_CAP_HCCPARAMS1_LTC_SHIFT                                      (0x00000006U)
#define CSL_USB3_CAP_HCCPARAMS1_LTC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_NSS_MASK                                       (0x00000080U)
#define CSL_USB3_CAP_HCCPARAMS1_NSS_SHIFT                                      (0x00000007U)
#define CSL_USB3_CAP_HCCPARAMS1_NSS_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_PAE_MASK                                       (0x00000100U)
#define CSL_USB3_CAP_HCCPARAMS1_PAE_SHIFT                                      (0x00000008U)
#define CSL_USB3_CAP_HCCPARAMS1_PAE_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_SPC_MASK                                       (0x00000200U)
#define CSL_USB3_CAP_HCCPARAMS1_SPC_SHIFT                                      (0x00000009U)
#define CSL_USB3_CAP_HCCPARAMS1_SPC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_SEC_MASK                                       (0x00000400U)
#define CSL_USB3_CAP_HCCPARAMS1_SEC_SHIFT                                      (0x0000000AU)
#define CSL_USB3_CAP_HCCPARAMS1_SEC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_CFC_MASK                                       (0x00000800U)
#define CSL_USB3_CAP_HCCPARAMS1_CFC_SHIFT                                      (0x0000000BU)
#define CSL_USB3_CAP_HCCPARAMS1_CFC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS1_MAXPSASIZE_MASK                                (0x0000F000U)
#define CSL_USB3_CAP_HCCPARAMS1_MAXPSASIZE_SHIFT                               (0x0000000CU)
#define CSL_USB3_CAP_HCCPARAMS1_MAXPSASIZE_MAX                                 (0x0000000FU)

#define CSL_USB3_CAP_HCCPARAMS1_XECP_MASK                                      (0xFFFF0000U)
#define CSL_USB3_CAP_HCCPARAMS1_XECP_SHIFT                                     (0x00000010U)
#define CSL_USB3_CAP_HCCPARAMS1_XECP_MAX                                       (0x0000FFFFU)

/* DBOFF */

#define CSL_USB3_CAP_DBOFF_RESERVED_1_0_MASK                                   (0x00000003U)
#define CSL_USB3_CAP_DBOFF_RESERVED_1_0_SHIFT                                  (0x00000000U)
#define CSL_USB3_CAP_DBOFF_RESERVED_1_0_MAX                                    (0x00000003U)

#define CSL_USB3_CAP_DBOFF_DOORBELL_ARRAY_OFFSET_MASK                          (0xFFFFFFFCU)
#define CSL_USB3_CAP_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT                         (0x00000002U)
#define CSL_USB3_CAP_DBOFF_DOORBELL_ARRAY_OFFSET_MAX                           (0x3FFFFFFFU)

/* RTSOFF */

#define CSL_USB3_CAP_RTSOFF_RESERVED_4_0_MASK                                  (0x0000001FU)
#define CSL_USB3_CAP_RTSOFF_RESERVED_4_0_SHIFT                                 (0x00000000U)
#define CSL_USB3_CAP_RTSOFF_RESERVED_4_0_MAX                                   (0x0000001FU)

#define CSL_USB3_CAP_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK                      (0xFFFFFFE0U)
#define CSL_USB3_CAP_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT                     (0x00000005U)
#define CSL_USB3_CAP_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MAX                       (0x07FFFFFFU)

/* HCCPARAMS2 */

#define CSL_USB3_CAP_HCCPARAMS2_U3C_MASK                                       (0x00000001U)
#define CSL_USB3_CAP_HCCPARAMS2_U3C_SHIFT                                      (0x00000000U)
#define CSL_USB3_CAP_HCCPARAMS2_U3C_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_CMC_MASK                                       (0x00000002U)
#define CSL_USB3_CAP_HCCPARAMS2_CMC_SHIFT                                      (0x00000001U)
#define CSL_USB3_CAP_HCCPARAMS2_CMC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_FSC_MASK                                       (0x00000004U)
#define CSL_USB3_CAP_HCCPARAMS2_FSC_SHIFT                                      (0x00000002U)
#define CSL_USB3_CAP_HCCPARAMS2_FSC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_CTC_MASK                                       (0x00000008U)
#define CSL_USB3_CAP_HCCPARAMS2_CTC_SHIFT                                      (0x00000003U)
#define CSL_USB3_CAP_HCCPARAMS2_CTC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_LEC_MASK                                       (0x00000010U)
#define CSL_USB3_CAP_HCCPARAMS2_LEC_SHIFT                                      (0x00000004U)
#define CSL_USB3_CAP_HCCPARAMS2_LEC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_CIC_MASK                                       (0x00000020U)
#define CSL_USB3_CAP_HCCPARAMS2_CIC_SHIFT                                      (0x00000005U)
#define CSL_USB3_CAP_HCCPARAMS2_CIC_MAX                                        (0x00000001U)

#define CSL_USB3_CAP_HCCPARAMS2_RESERVED_31_6_MASK                             (0xFFFFFFC0U)
#define CSL_USB3_CAP_HCCPARAMS2_RESERVED_31_6_SHIFT                            (0x00000006U)
#define CSL_USB3_CAP_HCCPARAMS2_RESERVED_31_6_MAX                              (0x03FFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Host Cntrl Oper Regs Block, 0x10020
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t USBCMD;                    /* USBCMD */
    volatile uint32_t USBSTS;                    /* USBSTS */
    volatile uint32_t PAGESIZE;                  /* PAGESIZE */
    volatile uint8_t  Resv_20[8];
    volatile uint32_t DNCTRL;                    /* DNCTRL */
    volatile uint32_t CRCR_LO;                   /* CRCR_LO */
    volatile uint32_t CRCR_HI;                   /* CRCR_HI */
    volatile uint8_t  Resv_48[16];
    volatile uint32_t DCBAAP_LO;                 /* DCBAAP_LO */
    volatile uint32_t DCBAAP_HI;                 /* DCBAAP_HI */
    volatile uint32_t CONFIG;                    /* CONFIG */
} CSL_usb3_operRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_OPER_USBCMD                                                   (0x00010020U)
#define CSL_USB3_OPER_USBSTS                                                   (0x00010024U)
#define CSL_USB3_OPER_PAGESIZE                                                 (0x00010028U)
#define CSL_USB3_OPER_DNCTRL                                                   (0x00010034U)
#define CSL_USB3_OPER_CRCR_LO                                                  (0x00010038U)
#define CSL_USB3_OPER_CRCR_HI                                                  (0x0001003CU)
#define CSL_USB3_OPER_DCBAAP_LO                                                (0x00010050U)
#define CSL_USB3_OPER_DCBAAP_HI                                                (0x00010054U)
#define CSL_USB3_OPER_CONFIG                                                   (0x00010058U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* USBCMD */

#define CSL_USB3_OPER_USBCMD_R_S_MASK                                          (0x00000001U)
#define CSL_USB3_OPER_USBCMD_R_S_SHIFT                                         (0x00000000U)
#define CSL_USB3_OPER_USBCMD_R_S_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBCMD_HCRST_MASK                                        (0x00000002U)
#define CSL_USB3_OPER_USBCMD_HCRST_SHIFT                                       (0x00000001U)
#define CSL_USB3_OPER_USBCMD_HCRST_MAX                                         (0x00000001U)

#define CSL_USB3_OPER_USBCMD_INTE_MASK                                         (0x00000004U)
#define CSL_USB3_OPER_USBCMD_INTE_SHIFT                                        (0x00000002U)
#define CSL_USB3_OPER_USBCMD_INTE_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_USBCMD_HSEE_MASK                                         (0x00000008U)
#define CSL_USB3_OPER_USBCMD_HSEE_SHIFT                                        (0x00000003U)
#define CSL_USB3_OPER_USBCMD_HSEE_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_USBCMD_RESERVED_6_4_MASK                                 (0x00000070U)
#define CSL_USB3_OPER_USBCMD_RESERVED_6_4_SHIFT                                (0x00000004U)
#define CSL_USB3_OPER_USBCMD_RESERVED_6_4_MAX                                  (0x00000007U)

#define CSL_USB3_OPER_USBCMD_LHCRST_MASK                                       (0x00000080U)
#define CSL_USB3_OPER_USBCMD_LHCRST_SHIFT                                      (0x00000007U)
#define CSL_USB3_OPER_USBCMD_LHCRST_MAX                                        (0x00000001U)

#define CSL_USB3_OPER_USBCMD_CSS_MASK                                          (0x00000100U)
#define CSL_USB3_OPER_USBCMD_CSS_SHIFT                                         (0x00000008U)
#define CSL_USB3_OPER_USBCMD_CSS_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBCMD_CRS_MASK                                          (0x00000200U)
#define CSL_USB3_OPER_USBCMD_CRS_SHIFT                                         (0x00000009U)
#define CSL_USB3_OPER_USBCMD_CRS_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBCMD_EWE_MASK                                          (0x00000400U)
#define CSL_USB3_OPER_USBCMD_EWE_SHIFT                                         (0x0000000AU)
#define CSL_USB3_OPER_USBCMD_EWE_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBCMD_EU3S_MASK                                         (0x00000800U)
#define CSL_USB3_OPER_USBCMD_EU3S_SHIFT                                        (0x0000000BU)
#define CSL_USB3_OPER_USBCMD_EU3S_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_USBCMD_RESERVED_12_MASK                                  (0x00001000U)
#define CSL_USB3_OPER_USBCMD_RESERVED_12_SHIFT                                 (0x0000000CU)
#define CSL_USB3_OPER_USBCMD_RESERVED_12_MAX                                   (0x00000001U)

#define CSL_USB3_OPER_USBCMD_CME_MASK                                          (0x00002000U)
#define CSL_USB3_OPER_USBCMD_CME_SHIFT                                         (0x0000000DU)
#define CSL_USB3_OPER_USBCMD_CME_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBCMD_RESERVED_31_14_MASK                               (0xFFFFC000U)
#define CSL_USB3_OPER_USBCMD_RESERVED_31_14_SHIFT                              (0x0000000EU)
#define CSL_USB3_OPER_USBCMD_RESERVED_31_14_MAX                                (0x0003FFFFU)

/* USBSTS */

#define CSL_USB3_OPER_USBSTS_HCH_MASK                                          (0x00000001U)
#define CSL_USB3_OPER_USBSTS_HCH_SHIFT                                         (0x00000000U)
#define CSL_USB3_OPER_USBSTS_HCH_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_RESERVED_1_MASK                                   (0x00000002U)
#define CSL_USB3_OPER_USBSTS_RESERVED_1_SHIFT                                  (0x00000001U)
#define CSL_USB3_OPER_USBSTS_RESERVED_1_MAX                                    (0x00000001U)

#define CSL_USB3_OPER_USBSTS_HSE_MASK                                          (0x00000004U)
#define CSL_USB3_OPER_USBSTS_HSE_SHIFT                                         (0x00000002U)
#define CSL_USB3_OPER_USBSTS_HSE_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_EINT_MASK                                         (0x00000008U)
#define CSL_USB3_OPER_USBSTS_EINT_SHIFT                                        (0x00000003U)
#define CSL_USB3_OPER_USBSTS_EINT_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_USBSTS_PCD_MASK                                          (0x00000010U)
#define CSL_USB3_OPER_USBSTS_PCD_SHIFT                                         (0x00000004U)
#define CSL_USB3_OPER_USBSTS_PCD_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_RESERVED_7_5_MASK                                 (0x000000E0U)
#define CSL_USB3_OPER_USBSTS_RESERVED_7_5_SHIFT                                (0x00000005U)
#define CSL_USB3_OPER_USBSTS_RESERVED_7_5_MAX                                  (0x00000007U)

#define CSL_USB3_OPER_USBSTS_SSS_MASK                                          (0x00000100U)
#define CSL_USB3_OPER_USBSTS_SSS_SHIFT                                         (0x00000008U)
#define CSL_USB3_OPER_USBSTS_SSS_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_RSS_MASK                                          (0x00000200U)
#define CSL_USB3_OPER_USBSTS_RSS_SHIFT                                         (0x00000009U)
#define CSL_USB3_OPER_USBSTS_RSS_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_SRE_MASK                                          (0x00000400U)
#define CSL_USB3_OPER_USBSTS_SRE_SHIFT                                         (0x0000000AU)
#define CSL_USB3_OPER_USBSTS_SRE_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_CNR_MASK                                          (0x00000800U)
#define CSL_USB3_OPER_USBSTS_CNR_SHIFT                                         (0x0000000BU)
#define CSL_USB3_OPER_USBSTS_CNR_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_HCE_MASK                                          (0x00001000U)
#define CSL_USB3_OPER_USBSTS_HCE_SHIFT                                         (0x0000000CU)
#define CSL_USB3_OPER_USBSTS_HCE_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_USBSTS_RESERVED_31_13_MASK                               (0xFFFFE000U)
#define CSL_USB3_OPER_USBSTS_RESERVED_31_13_SHIFT                              (0x0000000DU)
#define CSL_USB3_OPER_USBSTS_RESERVED_31_13_MAX                                (0x0007FFFFU)

/* PAGESIZE */

#define CSL_USB3_OPER_PAGESIZE_PAGE_SIZE_MASK                                  (0x0000FFFFU)
#define CSL_USB3_OPER_PAGESIZE_PAGE_SIZE_SHIFT                                 (0x00000000U)
#define CSL_USB3_OPER_PAGESIZE_PAGE_SIZE_MAX                                   (0x0000FFFFU)

#define CSL_USB3_OPER_PAGESIZE_RESERVED_31_16_MASK                             (0xFFFF0000U)
#define CSL_USB3_OPER_PAGESIZE_RESERVED_31_16_SHIFT                            (0x00000010U)
#define CSL_USB3_OPER_PAGESIZE_RESERVED_31_16_MAX                              (0x0000FFFFU)

/* DNCTRL */

#define CSL_USB3_OPER_DNCTRL_N0_N15_MASK                                       (0x0000FFFFU)
#define CSL_USB3_OPER_DNCTRL_N0_N15_SHIFT                                      (0x00000000U)
#define CSL_USB3_OPER_DNCTRL_N0_N15_MAX                                        (0x0000FFFFU)

#define CSL_USB3_OPER_DNCTRL_RESERVED_31_16_MASK                               (0xFFFF0000U)
#define CSL_USB3_OPER_DNCTRL_RESERVED_31_16_SHIFT                              (0x00000010U)
#define CSL_USB3_OPER_DNCTRL_RESERVED_31_16_MAX                                (0x0000FFFFU)

/* CRCR_LO */

#define CSL_USB3_OPER_CRCR_LO_RCS_MASK                                         (0x00000001U)
#define CSL_USB3_OPER_CRCR_LO_RCS_SHIFT                                        (0x00000000U)
#define CSL_USB3_OPER_CRCR_LO_RCS_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_CRCR_LO_CS_MASK                                          (0x00000002U)
#define CSL_USB3_OPER_CRCR_LO_CS_SHIFT                                         (0x00000001U)
#define CSL_USB3_OPER_CRCR_LO_CS_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_CRCR_LO_CA_MASK                                          (0x00000004U)
#define CSL_USB3_OPER_CRCR_LO_CA_SHIFT                                         (0x00000002U)
#define CSL_USB3_OPER_CRCR_LO_CA_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_CRCR_LO_CRR_MASK                                         (0x00000008U)
#define CSL_USB3_OPER_CRCR_LO_CRR_SHIFT                                        (0x00000003U)
#define CSL_USB3_OPER_CRCR_LO_CRR_MAX                                          (0x00000001U)

#define CSL_USB3_OPER_CRCR_LO_RESERVED_5_4_MASK                                (0x00000030U)
#define CSL_USB3_OPER_CRCR_LO_RESERVED_5_4_SHIFT                               (0x00000004U)
#define CSL_USB3_OPER_CRCR_LO_RESERVED_5_4_MAX                                 (0x00000003U)

#define CSL_USB3_OPER_CRCR_LO_CMD_RING_PNTR_MASK                               (0xFFFFFFC0U)
#define CSL_USB3_OPER_CRCR_LO_CMD_RING_PNTR_SHIFT                              (0x00000006U)
#define CSL_USB3_OPER_CRCR_LO_CMD_RING_PNTR_MAX                                (0x03FFFFFFU)

/* CRCR_HI */

#define CSL_USB3_OPER_CRCR_HI_CMD_RING_PNTR_MASK                               (0xFFFFFFFFU)
#define CSL_USB3_OPER_CRCR_HI_CMD_RING_PNTR_SHIFT                              (0x00000000U)
#define CSL_USB3_OPER_CRCR_HI_CMD_RING_PNTR_MAX                                (0xFFFFFFFFU)

/* DCBAAP_LO */

#define CSL_USB3_OPER_DCBAAP_LO_RESERVED_5_0_MASK                              (0x0000003FU)
#define CSL_USB3_OPER_DCBAAP_LO_RESERVED_5_0_SHIFT                             (0x00000000U)
#define CSL_USB3_OPER_DCBAAP_LO_RESERVED_5_0_MAX                               (0x0000003FU)

#define CSL_USB3_OPER_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK                       (0xFFFFFFC0U)
#define CSL_USB3_OPER_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT                      (0x00000006U)
#define CSL_USB3_OPER_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MAX                        (0x03FFFFFFU)

/* DCBAAP_HI */

#define CSL_USB3_OPER_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK                       (0xFFFFFFFFU)
#define CSL_USB3_OPER_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT                      (0x00000000U)
#define CSL_USB3_OPER_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MAX                        (0xFFFFFFFFU)

/* CONFIG */

#define CSL_USB3_OPER_CONFIG_MAXSLOTSEN_MASK                                   (0x000000FFU)
#define CSL_USB3_OPER_CONFIG_MAXSLOTSEN_SHIFT                                  (0x00000000U)
#define CSL_USB3_OPER_CONFIG_MAXSLOTSEN_MAX                                    (0x000000FFU)

#define CSL_USB3_OPER_CONFIG_U3E_MASK                                          (0x00000100U)
#define CSL_USB3_OPER_CONFIG_U3E_SHIFT                                         (0x00000008U)
#define CSL_USB3_OPER_CONFIG_U3E_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_CONFIG_CIE_MASK                                          (0x00000200U)
#define CSL_USB3_OPER_CONFIG_CIE_SHIFT                                         (0x00000009U)
#define CSL_USB3_OPER_CONFIG_CIE_MAX                                           (0x00000001U)

#define CSL_USB3_OPER_CONFIG_RESERVED_31_8_MASK                                (0xFFFFFC00U)
#define CSL_USB3_OPER_CONFIG_RESERVED_31_8_SHIFT                               (0x0000000AU)
#define CSL_USB3_OPER_CONFIG_RESERVED_31_8_MAX                                 (0x003FFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Host Cntrl Port Reg Set Block, 0x10420
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PORTSC_20;                 /* PORTSC_20 */
    volatile uint32_t PORTPMSC_20;               /* PORTPMSC_20 */
    volatile uint32_t PORTLI_20;                 /* PORTLI_20 */
    volatile uint32_t PORTHLPMC_20;              /* PORTHLPMC_20 */
} CSL_usb3_portRegs_usb2prt;


typedef struct {
    volatile uint32_t PORTSC_30;                 /* PORTSC_30 */
    volatile uint32_t PORTPMSC_30;               /* PORTPMSC_30 */
    volatile uint32_t PORTLI_30;                 /* PORTLI_30 */
    volatile uint32_t PORTHLPMC_30;              /* PORTHLPMC_30 */
} CSL_usb3_portRegs_usb3prt;


typedef struct {
    CSL_usb3_portRegs_usb2prt USB2PRT;
    CSL_usb3_portRegs_usb3prt USB3PRT;
} CSL_usb3_portRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_PORT_USB2PRT_PORTSC_20                                        (0x00010420U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20                                      (0x00010424U)
#define CSL_USB3_PORT_USB2PRT_PORTLI_20                                        (0x00010428U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20                                     (0x0001042CU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30                                        (0x00010430U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30                                      (0x00010434U)
#define CSL_USB3_PORT_USB3PRT_PORTLI_30                                        (0x00010438U)
#define CSL_USB3_PORT_USB3PRT_PORTHLPMC_30                                     (0x0001043CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PORTSC_20 */

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CCS_MASK                               (0x00000001U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CCS_SHIFT                              (0x00000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CCS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PED_MASK                               (0x00000002U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PED_SHIFT                              (0x00000001U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PED_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_2_MASK                        (0x00000004U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_2_SHIFT                       (0x00000002U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_2_MAX                         (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCA_MASK                               (0x00000008U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCA_SHIFT                              (0x00000003U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCA_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PR_MASK                                (0x00000010U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PR_SHIFT                               (0x00000004U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PR_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLS_MASK                               (0x000001E0U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLS_SHIFT                              (0x00000005U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLS_MAX                                (0x0000000FU)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PP_MASK                                (0x00000200U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PP_SHIFT                               (0x00000009U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PP_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PORTSPEED_MASK                         (0x00003C00U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PORTSPEED_SHIFT                        (0x0000000AU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PORTSPEED_MAX                          (0x0000000FU)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PIC_MASK                               (0x0000C000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PIC_SHIFT                              (0x0000000EU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PIC_MAX                                (0x00000003U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_LWS_MASK                               (0x00010000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_LWS_SHIFT                              (0x00000010U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_LWS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CSC_MASK                               (0x00020000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CSC_SHIFT                              (0x00000011U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CSC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PEC_MASK                               (0x00040000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PEC_SHIFT                              (0x00000012U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PEC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_19_MASK                       (0x00080000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_19_SHIFT                      (0x00000013U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_19_MAX                        (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCC_MASK                               (0x00100000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCC_SHIFT                              (0x00000014U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_OCC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PRC_MASK                               (0x00200000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PRC_SHIFT                              (0x00000015U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PRC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLC_MASK                               (0x00400000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLC_SHIFT                              (0x00000016U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_PLC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_23_MASK                       (0x00800000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_23_SHIFT                      (0x00000017U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_23_MAX                        (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CAS_MASK                               (0x01000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CAS_SHIFT                              (0x00000018U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_CAS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WCE_MASK                               (0x02000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WCE_SHIFT                              (0x00000019U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WCE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WDE_MASK                               (0x04000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WDE_SHIFT                              (0x0000001AU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WDE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WOE_MASK                               (0x08000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WOE_SHIFT                              (0x0000001BU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_WOE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_29_28_MASK                    (0x30000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_29_28_SHIFT                   (0x0000001CU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_29_28_MAX                     (0x00000003U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_DR_MASK                                (0x40000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_DR_SHIFT                               (0x0000001EU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_DR_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_31_MASK                       (0x80000000U)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_31_SHIFT                      (0x0000001FU)
#define CSL_USB3_PORT_USB2PRT_PORTSC_20_RESERVED_31_MAX                        (0x00000001U)

/* PORTPMSC_20 */

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1S_MASK                             (0x00000007U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1S_SHIFT                            (0x00000000U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1S_MAX                              (0x00000007U)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RWE_MASK                             (0x00000008U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RWE_SHIFT                            (0x00000003U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RWE_MAX                              (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HIRD_MASK                            (0x000000F0U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HIRD_SHIFT                           (0x00000004U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HIRD_MAX                             (0x0000000FU)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1DSLOT_MASK                         (0x0000FF00U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1DSLOT_SHIFT                        (0x00000008U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_L1DSLOT_MAX                          (0x000000FFU)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HLE_MASK                             (0x00010000U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HLE_SHIFT                            (0x00000010U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_HLE_MAX                              (0x00000001U)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RESERVED_27_17_MASK                  (0x0FFE0000U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RESERVED_27_17_SHIFT                 (0x00000011U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_RESERVED_27_17_MAX                   (0x000007FFU)

#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_PRTTSTCTRL_MASK                      (0xF0000000U)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_PRTTSTCTRL_SHIFT                     (0x0000001CU)
#define CSL_USB3_PORT_USB2PRT_PORTPMSC_20_PRTTSTCTRL_MAX                       (0x0000000FU)

/* PORTLI_20 */

#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_MASK                          (0x0000FFFFU)
#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_SHIFT                         (0x00000000U)
#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_MAX                           (0x0000FFFFU)

#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_31_16_MASK                    (0xFFFF0000U)
#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_31_16_SHIFT                   (0x00000010U)
#define CSL_USB3_PORT_USB2PRT_PORTLI_20_RESERVED_31_16_MAX                     (0x0000FFFFU)

/* PORTHLPMC_20 */

#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDM_MASK                          (0x00000003U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDM_SHIFT                         (0x00000000U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDM_MAX                           (0x00000003U)

#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_L1_TIMEOUT_MASK                     (0x000003FCU)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_L1_TIMEOUT_SHIFT                    (0x00000002U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_L1_TIMEOUT_MAX                      (0x000000FFU)

#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDD_MASK                          (0x00003C00U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDD_SHIFT                         (0x0000000AU)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_HIRDD_MAX                           (0x0000000FU)

#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_RESERVED_31_14_MASK                 (0xFFFFC000U)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_RESERVED_31_14_SHIFT                (0x0000000EU)
#define CSL_USB3_PORT_USB2PRT_PORTHLPMC_20_RESERVED_31_14_MAX                  (0x0003FFFFU)

/* PORTSC_30 */

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CCS_MASK                               (0x00000001U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CCS_SHIFT                              (0x00000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CCS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PED_MASK                               (0x00000002U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PED_SHIFT                              (0x00000001U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PED_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_2_MASK                        (0x00000004U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_2_SHIFT                       (0x00000002U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_2_MAX                         (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCA_MASK                               (0x00000008U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCA_SHIFT                              (0x00000003U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCA_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PR_MASK                                (0x00000010U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PR_SHIFT                               (0x00000004U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PR_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLS_MASK                               (0x000001E0U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLS_SHIFT                              (0x00000005U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLS_MAX                                (0x0000000FU)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PP_MASK                                (0x00000200U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PP_SHIFT                               (0x00000009U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PP_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PORTSPEED_MASK                         (0x00003C00U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PORTSPEED_SHIFT                        (0x0000000AU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PORTSPEED_MAX                          (0x0000000FU)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PIC_MASK                               (0x0000C000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PIC_SHIFT                              (0x0000000EU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PIC_MAX                                (0x00000003U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_LWS_MASK                               (0x00010000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_LWS_SHIFT                              (0x00000010U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_LWS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CSC_MASK                               (0x00020000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CSC_SHIFT                              (0x00000011U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CSC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PEC_MASK                               (0x00040000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PEC_SHIFT                              (0x00000012U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PEC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WRC_MASK                               (0x00080000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WRC_SHIFT                              (0x00000013U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WRC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCC_MASK                               (0x00100000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCC_SHIFT                              (0x00000014U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_OCC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PRC_MASK                               (0x00200000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PRC_SHIFT                              (0x00000015U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PRC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLC_MASK                               (0x00400000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLC_SHIFT                              (0x00000016U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_PLC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CEC_MASK                               (0x00800000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CEC_SHIFT                              (0x00000017U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CEC_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CAS_MASK                               (0x01000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CAS_SHIFT                              (0x00000018U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_CAS_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WCE_MASK                               (0x02000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WCE_SHIFT                              (0x00000019U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WCE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WDE_MASK                               (0x04000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WDE_SHIFT                              (0x0000001AU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WDE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WOE_MASK                               (0x08000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WOE_SHIFT                              (0x0000001BU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WOE_MAX                                (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_29_28_MASK                    (0x30000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_29_28_SHIFT                   (0x0000001CU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_RESERVED_29_28_MAX                     (0x00000003U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_DR_MASK                                (0x40000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_DR_SHIFT                               (0x0000001EU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_DR_MAX                                 (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WPR_MASK                               (0x80000000U)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WPR_SHIFT                              (0x0000001FU)
#define CSL_USB3_PORT_USB3PRT_PORTSC_30_WPR_MAX                                (0x00000001U)

/* PORTPMSC_30 */

#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U1_TIMEOUT_MASK                      (0x000000FFU)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U1_TIMEOUT_SHIFT                     (0x00000000U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U1_TIMEOUT_MAX                       (0x000000FFU)

#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U2_TIMEOUT_MASK                      (0x0000FF00U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U2_TIMEOUT_SHIFT                     (0x00000008U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_U2_TIMEOUT_MAX                       (0x000000FFU)

#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_FLA_MASK                             (0x00010000U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_FLA_SHIFT                            (0x00000010U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_FLA_MAX                              (0x00000001U)

#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_RESERVED_31_17_MASK                  (0xFFFE0000U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_RESERVED_31_17_SHIFT                 (0x00000011U)
#define CSL_USB3_PORT_USB3PRT_PORTPMSC_30_RESERVED_31_17_MAX                   (0x00007FFFU)

/* PORTLI_30 */

#define CSL_USB3_PORT_USB3PRT_PORTLI_30_LINK_ERROR_COUNT_MASK                  (0x0000FFFFU)
#define CSL_USB3_PORT_USB3PRT_PORTLI_30_LINK_ERROR_COUNT_SHIFT                 (0x00000000U)
#define CSL_USB3_PORT_USB3PRT_PORTLI_30_LINK_ERROR_COUNT_MAX                   (0x0000FFFFU)

#define CSL_USB3_PORT_USB3PRT_PORTLI_30_RESERVED_31_16_MASK                    (0xFFFF0000U)
#define CSL_USB3_PORT_USB3PRT_PORTLI_30_RESERVED_31_16_SHIFT                   (0x00000010U)
#define CSL_USB3_PORT_USB3PRT_PORTLI_30_RESERVED_31_16_MAX                     (0x0000FFFFU)

/* PORTHLPMC_30 */

#define CSL_USB3_PORT_USB3PRT_PORTHLPMC_30_RESERVED_31_0_MASK                  (0xFFFFFFFFU)
#define CSL_USB3_PORT_USB3PRT_PORTHLPMC_30_RESERVED_31_0_SHIFT                 (0x00000000U)
#define CSL_USB3_PORT_USB3PRT_PORTHLPMC_30_RESERVED_31_0_MAX                   (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Host Cntrl Runtime Regs Block, 0x10440
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MFINDEX;                   /* MFINDEX */
    volatile uint32_t RSVDZ;                     /* RsvdZ */
} CSL_usb3_runtimeRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_RUNTIME_MFINDEX                                               (0x00010440U)
#define CSL_USB3_RUNTIME_RSVDZ                                                 (0x00010444U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MFINDEX */

#define CSL_USB3_RUNTIME_MFINDEX_MICROFRAME_INDEX_MASK                         (0x00003FFFU)
#define CSL_USB3_RUNTIME_MFINDEX_MICROFRAME_INDEX_SHIFT                        (0x00000000U)
#define CSL_USB3_RUNTIME_MFINDEX_MICROFRAME_INDEX_MAX                          (0x00003FFFU)

#define CSL_USB3_RUNTIME_MFINDEX_RESERVED_31_14_MASK                           (0xFFFFC000U)
#define CSL_USB3_RUNTIME_MFINDEX_RESERVED_31_14_SHIFT                          (0x0000000EU)
#define CSL_USB3_RUNTIME_MFINDEX_RESERVED_31_14_MAX                            (0x0003FFFFU)

/* RSVDZ */

#define CSL_USB3_RUNTIME_RSVDZ_RESERVED_31_0_MASK                              (0xFFFFFFFFU)
#define CSL_USB3_RUNTIME_RSVDZ_RESERVED_31_0_SHIFT                             (0x00000000U)
#define CSL_USB3_RUNTIME_RSVDZ_RESERVED_31_0_MAX                               (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Interrupter Regs Block, 0x10460
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t IMAN;                      /* IMAN */
    volatile uint32_t IMOD;                      /* IMOD */
    volatile uint32_t ERSTSZ;                    /* ERSTSZ */
    volatile uint32_t RSVDP;                     /* RsvdP */
    volatile uint32_t ERSTBA_LO;                 /* ERSTBA_LO */
    volatile uint32_t ERSTBA_HI;                 /* ERSTBA_HI */
    volatile uint32_t ERDP_LO;                   /* ERDP_LO */
    volatile uint32_t ERDP_HI;                   /* ERDP_HI */
} CSL_usb3_intrRegs_intregs;


typedef struct {
    CSL_usb3_intrRegs_intregs INTREGS[16];
} CSL_usb3_intrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_INTR_INTREGS_IMAN(INTREGS)                                    (0x00010460U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_IMOD(INTREGS)                                    (0x00010464U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_ERSTSZ(INTREGS)                                  (0x00010468U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_RSVDP(INTREGS)                                   (0x0001046CU+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_ERSTBA_LO(INTREGS)                               (0x00010470U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_ERSTBA_HI(INTREGS)                               (0x00010474U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_ERDP_LO(INTREGS)                                 (0x00010478U+((INTREGS)*0x20U))
#define CSL_USB3_INTR_INTREGS_ERDP_HI(INTREGS)                                 (0x0001047CU+((INTREGS)*0x20U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* IMAN */

#define CSL_USB3_INTR_INTREGS_IMAN_IP_MASK                                     (0x00000001U)
#define CSL_USB3_INTR_INTREGS_IMAN_IP_SHIFT                                    (0x00000000U)
#define CSL_USB3_INTR_INTREGS_IMAN_IP_MAX                                      (0x00000001U)

#define CSL_USB3_INTR_INTREGS_IMAN_IE_MASK                                     (0x00000002U)
#define CSL_USB3_INTR_INTREGS_IMAN_IE_SHIFT                                    (0x00000001U)
#define CSL_USB3_INTR_INTREGS_IMAN_IE_MAX                                      (0x00000001U)

#define CSL_USB3_INTR_INTREGS_IMAN_RESERVED_31_2_MASK                          (0xFFFFFFFCU)
#define CSL_USB3_INTR_INTREGS_IMAN_RESERVED_31_2_SHIFT                         (0x00000002U)
#define CSL_USB3_INTR_INTREGS_IMAN_RESERVED_31_2_MAX                           (0x3FFFFFFFU)

/* IMOD */

#define CSL_USB3_INTR_INTREGS_IMOD_IMODI_MASK                                  (0x0000FFFFU)
#define CSL_USB3_INTR_INTREGS_IMOD_IMODI_SHIFT                                 (0x00000000U)
#define CSL_USB3_INTR_INTREGS_IMOD_IMODI_MAX                                   (0x0000FFFFU)

#define CSL_USB3_INTR_INTREGS_IMOD_IMODC_MASK                                  (0xFFFF0000U)
#define CSL_USB3_INTR_INTREGS_IMOD_IMODC_SHIFT                                 (0x00000010U)
#define CSL_USB3_INTR_INTREGS_IMOD_IMODC_MAX                                   (0x0000FFFFU)

/* ERSTSZ */

#define CSL_USB3_INTR_INTREGS_ERSTSZ_ERS_TABLE_SIZE_MASK                       (0x0000FFFFU)
#define CSL_USB3_INTR_INTREGS_ERSTSZ_ERS_TABLE_SIZE_SHIFT                      (0x00000000U)
#define CSL_USB3_INTR_INTREGS_ERSTSZ_ERS_TABLE_SIZE_MAX                        (0x0000FFFFU)

#define CSL_USB3_INTR_INTREGS_ERSTSZ_RESERVED_31_16_MASK                       (0xFFFF0000U)
#define CSL_USB3_INTR_INTREGS_ERSTSZ_RESERVED_31_16_SHIFT                      (0x00000010U)
#define CSL_USB3_INTR_INTREGS_ERSTSZ_RESERVED_31_16_MAX                        (0x0000FFFFU)

/* RSVDP */

#define CSL_USB3_INTR_INTREGS_RSVDP_RESERVED_31_0_MASK                         (0xFFFFFFFFU)
#define CSL_USB3_INTR_INTREGS_RSVDP_RESERVED_31_0_SHIFT                        (0x00000000U)
#define CSL_USB3_INTR_INTREGS_RSVDP_RESERVED_31_0_MAX                          (0xFFFFFFFFU)

/* ERSTBA_LO */

#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_RESERVED_5_0_MASK                      (0x0000003FU)
#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_RESERVED_5_0_SHIFT                     (0x00000000U)
#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_RESERVED_5_0_MAX                       (0x0000003FU)

#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_ERS_TABLE_BAR_MASK                     (0xFFFFFFC0U)
#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_ERS_TABLE_BAR_SHIFT                    (0x00000006U)
#define CSL_USB3_INTR_INTREGS_ERSTBA_LO_ERS_TABLE_BAR_MAX                      (0x03FFFFFFU)

/* ERSTBA_HI */

#define CSL_USB3_INTR_INTREGS_ERSTBA_HI_ERS_TABLE_BAR_MASK                     (0xFFFFFFFFU)
#define CSL_USB3_INTR_INTREGS_ERSTBA_HI_ERS_TABLE_BAR_SHIFT                    (0x00000000U)
#define CSL_USB3_INTR_INTREGS_ERSTBA_HI_ERS_TABLE_BAR_MAX                      (0xFFFFFFFFU)

/* ERDP_LO */

#define CSL_USB3_INTR_INTREGS_ERDP_LO_DESI_MASK                                (0x00000007U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_DESI_SHIFT                               (0x00000000U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_DESI_MAX                                 (0x00000007U)

#define CSL_USB3_INTR_INTREGS_ERDP_LO_EHB_MASK                                 (0x00000008U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_EHB_SHIFT                                (0x00000003U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_EHB_MAX                                  (0x00000001U)

#define CSL_USB3_INTR_INTREGS_ERDP_LO_ERD_PNTR_MASK                            (0xFFFFFFF0U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_ERD_PNTR_SHIFT                           (0x00000004U)
#define CSL_USB3_INTR_INTREGS_ERDP_LO_ERD_PNTR_MAX                             (0x0FFFFFFFU)

/* ERDP_HI */

#define CSL_USB3_INTR_INTREGS_ERDP_HI_ERD_PNTR_MASK                            (0xFFFFFFFFU)
#define CSL_USB3_INTR_INTREGS_ERDP_HI_ERD_PNTR_SHIFT                           (0x00000000U)
#define CSL_USB3_INTR_INTREGS_ERDP_HI_ERD_PNTR_MAX                             (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Doorbell Reg Block, 0x10660
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DB;                        /* DB */
} CSL_usb3_dbarrRegs_doorbells;


typedef struct {
    CSL_usb3_dbarrRegs_doorbells DOORBELLS[64];
} CSL_usb3_dbarrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_DBARR_DOORBELLS_DB(DOORBELLS)                                 (0x00010660U+((DOORBELLS)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DB */

#define CSL_USB3_DBARR_DOORBELLS_DB_DB_TARGET_MASK                             (0x000000FFU)
#define CSL_USB3_DBARR_DOORBELLS_DB_DB_TARGET_SHIFT                            (0x00000000U)
#define CSL_USB3_DBARR_DOORBELLS_DB_DB_TARGET_MAX                              (0x000000FFU)

#define CSL_USB3_DBARR_DOORBELLS_DB_RESERVED_15_8_MASK                         (0x0000FF00U)
#define CSL_USB3_DBARR_DOORBELLS_DB_RESERVED_15_8_SHIFT                        (0x00000008U)
#define CSL_USB3_DBARR_DOORBELLS_DB_RESERVED_15_8_MAX                          (0x000000FFU)

#define CSL_USB3_DBARR_DOORBELLS_DB_DB_STREAM_ID_MASK                          (0xFFFF0000U)
#define CSL_USB3_DBARR_DOORBELLS_DB_DB_STREAM_ID_SHIFT                         (0x00000010U)
#define CSL_USB3_DBARR_DOORBELLS_DB_DB_STREAM_ID_MAX                           (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : USB3 HC Extended Capability Register Block, 0x10a60
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t USBLEGSUP;                 /* USBLEGSUP */
    volatile uint32_t USBLEGCTLSTS;              /* USBLEGCTLSTS */
} CSL_usb3_extcapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_EXTCAP_USBLEGSUP                                              (0x00010A60U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS                                           (0x00010A64U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* USBLEGSUP */

#define CSL_USB3_EXTCAP_USBLEGSUP_CAPABILITY_ID_MASK                           (0x000000FFU)
#define CSL_USB3_EXTCAP_USBLEGSUP_CAPABILITY_ID_SHIFT                          (0x00000000U)
#define CSL_USB3_EXTCAP_USBLEGSUP_CAPABILITY_ID_MAX                            (0x000000FFU)

#define CSL_USB3_EXTCAP_USBLEGSUP_NEXT_CAPABILITY_POINTER_MASK                 (0x0000FF00U)
#define CSL_USB3_EXTCAP_USBLEGSUP_NEXT_CAPABILITY_POINTER_SHIFT                (0x00000008U)
#define CSL_USB3_EXTCAP_USBLEGSUP_NEXT_CAPABILITY_POINTER_MAX                  (0x000000FFU)

#define CSL_USB3_EXTCAP_USBLEGSUP_HC_BIOS_OWNED_MASK                           (0x00010000U)
#define CSL_USB3_EXTCAP_USBLEGSUP_HC_BIOS_OWNED_SHIFT                          (0x00000010U)
#define CSL_USB3_EXTCAP_USBLEGSUP_HC_BIOS_OWNED_MAX                            (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_23_17_MASK                          (0x00FE0000U)
#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_23_17_SHIFT                         (0x00000011U)
#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_23_17_MAX                           (0x0000007FU)

#define CSL_USB3_EXTCAP_USBLEGSUP_HC_OS_OWNED_MASK                             (0x01000000U)
#define CSL_USB3_EXTCAP_USBLEGSUP_HC_OS_OWNED_SHIFT                            (0x00000018U)
#define CSL_USB3_EXTCAP_USBLEGSUP_HC_OS_OWNED_MAX                              (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_31_25_MASK                          (0xFE000000U)
#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_31_25_SHIFT                         (0x00000019U)
#define CSL_USB3_EXTCAP_USBLEGSUP_RESERVED_31_25_MAX                           (0x0000007FU)

/* USBLEGCTLSTS */

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_USB_SMI_ENABLE_MASK                       (0x00000001U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_USB_SMI_ENABLE_SHIFT                      (0x00000000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_USB_SMI_ENABLE_MAX                        (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_3_1_MASK                         (0x0000000EU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_3_1_SHIFT                        (0x00000001U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_3_1_MAX                          (0x00000007U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_E_MASK                        (0x00000010U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_E_SHIFT                       (0x00000004U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_E_MAX                         (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_12_5_MASK                        (0x00001FE0U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_12_5_SHIFT                       (0x00000005U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_12_5_MAX                         (0x000000FFU)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_E_MASK                          (0x00002000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_E_SHIFT                         (0x0000000DU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_E_MAX                           (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_E_MASK                         (0x00004000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_E_SHIFT                        (0x0000000EU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_E_MAX                          (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_E_MASK                         (0x00008000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_E_SHIFT                        (0x0000000FU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_E_MAX                          (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_EVENT_MASK                         (0x00010000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_EVENT_SHIFT                        (0x00000010U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_EVENT_MAX                          (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_19_17_MASK                       (0x000E0000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_19_17_SHIFT                      (0x00000011U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_19_17_MAX                        (0x00000007U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_MASK                          (0x00100000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_SHIFT                         (0x00000014U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_HOST_MAX                           (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_28_21_MASK                       (0x1FE00000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_28_21_SHIFT                      (0x00000015U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_RESERVED_28_21_MAX                        (0x000000FFU)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_MASK                            (0x20000000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_SHIFT                           (0x0000001DU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_OS_MAX                             (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_MASK                           (0x40000000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_SHIFT                          (0x0000001EU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_PCI_MAX                            (0x00000001U)

#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_MASK                           (0x80000000U)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_SHIFT                          (0x0000001FU)
#define CSL_USB3_EXTCAP_USBLEGCTLSTS_SMI_ON_BAR_MAX                            (0x00000001U)

/**************************************************************************
* Hardware Region  : USB3 xHCI Supported Protocol Capability USB 2.0 Block, 0x10a70
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t SUPTPRT2_DW0;              /* SUPTPRT2_DW0 */
    volatile uint32_t SUPTPRT2_DW1;              /* SUPTPRT2_DW1 */
    volatile uint32_t SUPTPRT2_DW2;              /* SUPTPRT2_DW2 */
    volatile uint32_t SUPTPRT2_DW3;              /* SUPTPRT2_DW3 */
} CSL_usb3_supprtcap2Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0                                       (0x00010A70U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW1                                       (0x00010A74U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2                                       (0x00010A78U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3                                       (0x00010A7CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* SUPTPRT2_DW0 */

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_CAPABILITY_ID_MASK                    (0x000000FFU)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_CAPABILITY_ID_SHIFT                   (0x00000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_CAPABILITY_ID_MAX                     (0x000000FFU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MASK          (0x0000FF00U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_SHIFT         (0x00000008U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MAX           (0x000000FFU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MINOR_REVISION_MASK                   (0x00FF0000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MINOR_REVISION_SHIFT                  (0x00000010U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MINOR_REVISION_MAX                    (0x000000FFU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MAJOR_REVISION_MASK                   (0xFF000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MAJOR_REVISION_SHIFT                  (0x00000018U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW0_MAJOR_REVISION_MAX                    (0x000000FFU)

/* SUPTPRT2_DW1 */

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW1_NAME_STRING_MASK                      (0xFFFFFFFFU)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW1_NAME_STRING_SHIFT                     (0x00000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW1_NAME_STRING_MAX                       (0xFFFFFFFFU)

/* SUPTPRT2_DW2 */

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MASK           (0x000000FFU)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_SHIFT          (0x00000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MAX            (0x000000FFU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MASK            (0x0000FF00U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_SHIFT           (0x00000008U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MAX             (0x000000FFU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HSO_MASK                              (0x00020000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HSO_SHIFT                             (0x00000011U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HSO_MAX                               (0x00000001U)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_IHI_MASK                              (0x00040000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_IHI_SHIFT                             (0x00000012U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_IHI_MAX                               (0x00000001U)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HLC_MASK                              (0x00080000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HLC_SHIFT                             (0x00000013U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_HLC_MAX                               (0x00000001U)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_BLC_MASK                              (0x00100000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_BLC_SHIFT                             (0x00000014U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_BLC_MAX                               (0x00000001U)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_MHD_MASK                              (0x0E000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_MHD_SHIFT                             (0x00000019U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_MHD_MAX                               (0x00000007U)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_PSIC_MASK                             (0xF0000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_PSIC_SHIFT                            (0x0000001CU)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW2_PSIC_MAX                              (0x0000000FU)

/* SUPTPRT2_DW3 */

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_PROTCL_SLT_TY_MASK                    (0x0000001FU)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_PROTCL_SLT_TY_SHIFT                   (0x00000000U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_PROTCL_SLT_TY_MAX                     (0x0000001FU)

#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_RESERVED_31_5_MASK                    (0xFFFFFFE0U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_RESERVED_31_5_SHIFT                   (0x00000005U)
#define CSL_USB3_SUPPRTCAP2_SUPTPRT2_DW3_RESERVED_31_5_MAX                     (0x07FFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 xHCI Supported Protocol Capability USB 3.0 Block, 0x10a80
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t SUPTPRT3_DW0;              /* SUPTPRT3_DW0 */
    volatile uint32_t SUPTPRT3_DW1;              /* SUPTPRT3_DW1 */
    volatile uint32_t SUPTPRT3_DW2;              /* SUPTPRT3_DW2 */
    volatile uint32_t SUPTPRT3_DW3;              /* SUPTPRT3_DW3 */
} CSL_usb3_supprtcap3Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0                                       (0x00010A80U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW1                                       (0x00010A84U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2                                       (0x00010A88U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3                                       (0x00010A8CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* SUPTPRT3_DW0 */

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_CAPABILITY_ID_MASK                    (0x000000FFU)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_CAPABILITY_ID_SHIFT                   (0x00000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_CAPABILITY_ID_MAX                     (0x000000FFU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MASK          (0x0000FF00U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_SHIFT         (0x00000008U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MAX           (0x000000FFU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MINOR_REVISION_MASK                   (0x00FF0000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MINOR_REVISION_SHIFT                  (0x00000010U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MINOR_REVISION_MAX                    (0x000000FFU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MAJOR_REVISION_MASK                   (0xFF000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MAJOR_REVISION_SHIFT                  (0x00000018U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW0_MAJOR_REVISION_MAX                    (0x000000FFU)

/* SUPTPRT3_DW1 */

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW1_NAME_STRING_MASK                      (0xFFFFFFFFU)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW1_NAME_STRING_SHIFT                     (0x00000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW1_NAME_STRING_MAX                       (0xFFFFFFFFU)

/* SUPTPRT3_DW2 */

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MASK           (0x000000FFU)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_SHIFT          (0x00000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MAX            (0x000000FFU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MASK            (0x0000FF00U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_SHIFT           (0x00000008U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MAX             (0x000000FFU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_MHD_MASK                              (0x0E000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_MHD_SHIFT                             (0x00000019U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_MHD_MAX                               (0x00000007U)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_PSIC_MASK                             (0xF0000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_PSIC_SHIFT                            (0x0000001CU)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW2_PSIC_MAX                              (0x0000000FU)

/* SUPTPRT3_DW3 */

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_PROTCL_SLT_TY_MASK                    (0x0000001FU)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_PROTCL_SLT_TY_SHIFT                   (0x00000000U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_PROTCL_SLT_TY_MAX                     (0x0000001FU)

#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_RESERVED_31_5_MASK                    (0xFFFFFFE0U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_RESERVED_31_5_SHIFT                   (0x00000005U)
#define CSL_USB3_SUPPRTCAP3_SUPTPRT3_DW3_RESERVED_31_5_MAX                     (0x07FFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 Global Register Block, 0x1c100
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t GUSB2PHYCFG;               /* GUSB2PHYCFG */
} CSL_usb3_gblRegs_GUSB2PHYCFG_REGS;


typedef struct {
    volatile uint32_t GUSB2I2CCTL;               /* GUSB2I2CCTL */
} CSL_usb3_gblRegs_GUSB2I2CCTL_REGS;


typedef struct {
    volatile uint32_t GUSB2PHYACC_ULPI;          /* GUSB2PHYACC_ULPI */
} CSL_usb3_gblRegs_GUSB2PHYACC_REGS;


typedef struct {
    volatile uint32_t GUSB3PIPECTL;              /* GUSB3PIPECTL */
} CSL_usb3_gblRegs_GUSB3PIPECTL_REGS;


typedef struct {
    volatile uint32_t GTXFIFOSIZ0;               /* GTXFIFOSIZ0 */
    volatile uint32_t GTXFIFOSIZ1;               /* GTXFIFOSIZ1 */
    volatile uint32_t GTXFIFOSIZ2;               /* GTXFIFOSIZ2 */
    volatile uint32_t GTXFIFOSIZ3;               /* GTXFIFOSIZ3 */
    volatile uint32_t GTXFIFOSIZ4;               /* GTXFIFOSIZ4 */
    volatile uint32_t GTXFIFOSIZ5;               /* GTXFIFOSIZ5 */
    volatile uint32_t GTXFIFOSIZ6;               /* GTXFIFOSIZ6 */
    volatile uint32_t GTXFIFOSIZ7;               /* GTXFIFOSIZ7 */
    volatile uint32_t GTXFIFOSIZ8;               /* GTXFIFOSIZ8 */
    volatile uint32_t GTXFIFOSIZ9;               /* GTXFIFOSIZ9 */
    volatile uint32_t GTXFIFOSIZ10;              /* GTXFIFOSIZ10 */
    volatile uint32_t GTXFIFOSIZ11;              /* GTXFIFOSIZ11 */
    volatile uint32_t GTXFIFOSIZ12;              /* GTXFIFOSIZ12 */
    volatile uint32_t GTXFIFOSIZ13;              /* GTXFIFOSIZ13 */
    volatile uint32_t GTXFIFOSIZ14;              /* GTXFIFOSIZ14 */
    volatile uint32_t GTXFIFOSIZ15;              /* GTXFIFOSIZ15 */
} CSL_usb3_gblRegs_GTXFIFOSIZ_REGS;


typedef struct {
    volatile uint32_t GRXFIFOSIZ0;               /* GRXFIFOSIZ0 */
    volatile uint32_t GRXFIFOSIZ1;               /* GRXFIFOSIZ1 */
    volatile uint32_t GRXFIFOSIZ2;               /* GRXFIFOSIZ2 */
    volatile uint8_t  Resv_64[52];
} CSL_usb3_gblRegs_GRXFIFOSIZ_REGS;


typedef struct {
    volatile uint32_t GEVNTADRLO;                /* GEVNTADRLO */
    volatile uint32_t GEVNTADRHI;                /* GEVNTADRHI */
    volatile uint32_t GEVNTSIZ;                  /* GEVNTSIZ */
    volatile uint32_t GEVNTCOUNT;                /* GEVNTCOUNT */
} CSL_usb3_gblRegs_GEVNTADRLO_REGS;


typedef struct {
    volatile uint32_t GSBUSCFG0;                 /* GSBUSCFG0 */
    volatile uint32_t GSBUSCFG1;                 /* GSBUSCFG1 */
    volatile uint32_t GTXTHRCFG;                 /* GTXTHRCFG */
    volatile uint32_t GRXTHRCFG;                 /* GRXTHRCFG */
    volatile uint32_t GCTL;                      /* GCTL */
    volatile uint32_t GPMSTS;                    /* GPMSTS */
    volatile uint32_t GSTS;                      /* GSTS */
    volatile uint32_t GUCTL1;                    /* GUCTL1 */
    volatile uint32_t GSNPSID;                   /* GSNPSID */
    volatile uint32_t GGPIO;                     /* GGPIO */
    volatile uint32_t GUID;                      /* GUID */
    volatile uint32_t GUCTL;                     /* GUCTL */
    volatile uint32_t GBUSERRADDRLO;             /* GBUSERRADDRLO */
    volatile uint32_t GBUSERRADDRHI;             /* GBUSERRADDRHI */
    volatile uint32_t GPRTBIMAPLO;               /* GPRTBIMAPLO */
    volatile uint32_t GPRTBIMAPHI;               /* GPRTBIMAPHI */
    volatile uint32_t GHWPARAMS0;                /* GHWPARAMS0 */
    volatile uint32_t GHWPARAMS1;                /* GHWPARAMS1 */
    volatile uint32_t GHWPARAMS2;                /* GHWPARAMS2 */
    volatile uint32_t GHWPARAMS3;                /* GHWPARAMS3 */
    volatile uint32_t GHWPARAMS4;                /* GHWPARAMS4 */
    volatile uint32_t GHWPARAMS5;                /* GHWPARAMS5 */
    volatile uint32_t GHWPARAMS6;                /* GHWPARAMS6 */
    volatile uint32_t GHWPARAMS7;                /* GHWPARAMS7 */
    volatile uint32_t GDBGFIFOSPACE;             /* GDBGFIFOSPACE */
    volatile uint32_t GDBGLTSSM;                 /* GDBGLTSSM */
    volatile uint32_t GDBGLNMCC;                 /* GDBGLNMCC */
    volatile uint32_t GDBGBMU;                   /* GDBGBMU */
    volatile uint32_t GDBGLSPMUX_HST;            /* GDBGLSPMUX_HST */
    volatile uint32_t GDBGLSP;                   /* GDBGLSP */
    volatile uint32_t GDBGEPINFO0;               /* GDBGEPINFO0 */
    volatile uint32_t GDBGEPINFO1;               /* GDBGEPINFO1 */
    volatile uint32_t GPRTBIMAP_HSLO;            /* GPRTBIMAP_HSLO */
    volatile uint32_t GPRTBIMAP_HSHI;            /* GPRTBIMAP_HSHI */
    volatile uint32_t GPRTBIMAP_FSLO;            /* GPRTBIMAP_FSLO */
    volatile uint32_t GPRTBIMAP_FSHI;            /* GPRTBIMAP_FSHI */
    volatile uint8_t  Resv_148[4];
    volatile uint32_t RESERVED_94;               /* Reserved_94 */
    volatile uint32_t RESERVED_98;               /* Reserved_98 */
    volatile uint32_t GUCTL2;                    /* Global User Control Register 2:

This register provides a few options for the software to control the core behavior in the Host and device mode. Most of the options are used to improve inter-operability with different hosts and devices. */
    volatile uint8_t  Resv_256[96];
    CSL_usb3_gblRegs_GUSB2PHYCFG_REGS GUSB2PHYCFG_REGS;
    volatile uint8_t  Resv_320[60];
    CSL_usb3_gblRegs_GUSB2I2CCTL_REGS GUSB2I2CCTL_REGS;
    volatile uint8_t  Resv_384[60];
    CSL_usb3_gblRegs_GUSB2PHYACC_REGS GUSB2PHYACC_REGS;
    volatile uint8_t  Resv_448[60];
    CSL_usb3_gblRegs_GUSB3PIPECTL_REGS GUSB3PIPECTL_REGS;
    volatile uint8_t  Resv_512[60];
    CSL_usb3_gblRegs_GTXFIFOSIZ_REGS GTXFIFOSIZ_REGS;
    volatile uint8_t  Resv_640[64];
    CSL_usb3_gblRegs_GRXFIFOSIZ_REGS GRXFIFOSIZ_REGS;
    volatile uint8_t  Resv_768[64];
    CSL_usb3_gblRegs_GEVNTADRLO_REGS GEVNTADRLO_REGS[16];
    volatile uint8_t  Resv_1280[256];
    volatile uint32_t GHWPARAMS8;                /* GHWPARAMS8 */
    volatile uint8_t  Resv_1296[12];
    volatile uint32_t GTXFIFOPRIDEV;             /* GTXFIFOPRIDEV */
    volatile uint8_t  Resv_1304[4];
    volatile uint32_t GTXFIFOPRIHST;             /* GTXFIFOPRIHST */
    volatile uint32_t GRXFIFOPRIHST;             /* GRXFIFOPRIHST */
    volatile uint8_t  Resv_1316[4];
    volatile uint32_t GDMAHLRATIO;               /* GDMAHLRATIO */
    volatile uint8_t  Resv_1328[8];
    volatile uint32_t GFLADJ;                    /* GFLADJ */
} CSL_usb3_gblRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_GBL_GSBUSCFG0                                                 (0x0001C100U)
#define CSL_USB3_GBL_GSBUSCFG1                                                 (0x0001C104U)
#define CSL_USB3_GBL_GTXTHRCFG                                                 (0x0001C108U)
#define CSL_USB3_GBL_GRXTHRCFG                                                 (0x0001C10CU)
#define CSL_USB3_GBL_GCTL                                                      (0x0001C110U)
#define CSL_USB3_GBL_GPMSTS                                                    (0x0001C114U)
#define CSL_USB3_GBL_GSTS                                                      (0x0001C118U)
#define CSL_USB3_GBL_GUCTL1                                                    (0x0001C11CU)
#define CSL_USB3_GBL_GSNPSID                                                   (0x0001C120U)
#define CSL_USB3_GBL_GGPIO                                                     (0x0001C124U)
#define CSL_USB3_GBL_GUID                                                      (0x0001C128U)
#define CSL_USB3_GBL_GUCTL                                                     (0x0001C12CU)
#define CSL_USB3_GBL_GBUSERRADDRLO                                             (0x0001C130U)
#define CSL_USB3_GBL_GBUSERRADDRHI                                             (0x0001C134U)
#define CSL_USB3_GBL_GPRTBIMAPLO                                               (0x0001C138U)
#define CSL_USB3_GBL_GPRTBIMAPHI                                               (0x0001C13CU)
#define CSL_USB3_GBL_GHWPARAMS0                                                (0x0001C140U)
#define CSL_USB3_GBL_GHWPARAMS1                                                (0x0001C144U)
#define CSL_USB3_GBL_GHWPARAMS2                                                (0x0001C148U)
#define CSL_USB3_GBL_GHWPARAMS3                                                (0x0001C14CU)
#define CSL_USB3_GBL_GHWPARAMS4                                                (0x0001C150U)
#define CSL_USB3_GBL_GHWPARAMS5                                                (0x0001C154U)
#define CSL_USB3_GBL_GHWPARAMS6                                                (0x0001C158U)
#define CSL_USB3_GBL_GHWPARAMS7                                                (0x0001C15CU)
#define CSL_USB3_GBL_GDBGFIFOSPACE                                             (0x0001C160U)
#define CSL_USB3_GBL_GDBGLTSSM                                                 (0x0001C164U)
#define CSL_USB3_GBL_GDBGLNMCC                                                 (0x0001C168U)
#define CSL_USB3_GBL_GDBGBMU                                                   (0x0001C16CU)
#define CSL_USB3_GBL_GDBGLSPMUX_HST                                            (0x0001C170U)
#define CSL_USB3_GBL_GDBGLSP                                                   (0x0001C174U)
#define CSL_USB3_GBL_GDBGEPINFO0                                               (0x0001C178U)
#define CSL_USB3_GBL_GDBGEPINFO1                                               (0x0001C17CU)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO                                            (0x0001C180U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI                                            (0x0001C184U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO                                            (0x0001C188U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI                                            (0x0001C18CU)
#define CSL_USB3_GBL_RESERVED_94                                               (0x0001C194U)
#define CSL_USB3_GBL_RESERVED_98                                               (0x0001C198U)
#define CSL_USB3_GBL_GUCTL2                                                    (0x0001C19CU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG                              (0x0001C200U)
#define CSL_USB3_GBL_GUSB2I2CCTL_REGS_GUSB2I2CCTL                              (0x0001C240U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI                         (0x0001C280U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL                            (0x0001C2C0U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0                               (0x0001C300U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1                               (0x0001C304U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2                               (0x0001C308U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3                               (0x0001C30CU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4                               (0x0001C310U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5                               (0x0001C314U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6                               (0x0001C318U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7                               (0x0001C31CU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8                               (0x0001C320U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9                               (0x0001C324U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10                              (0x0001C328U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11                              (0x0001C32CU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12                              (0x0001C330U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13                              (0x0001C334U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14                              (0x0001C338U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15                              (0x0001C33CU)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0                               (0x0001C380U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1                               (0x0001C384U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2                               (0x0001C388U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRLO(GEVNTADRLO_REGS)               (0x0001C400U+((GEVNTADRLO_REGS)*0x10U))
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRHI(GEVNTADRLO_REGS)               (0x0001C404U+((GEVNTADRLO_REGS)*0x10U))
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ(GEVNTADRLO_REGS)                 (0x0001C408U+((GEVNTADRLO_REGS)*0x10U))
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT(GEVNTADRLO_REGS)               (0x0001C40CU+((GEVNTADRLO_REGS)*0x10U))
#define CSL_USB3_GBL_GHWPARAMS8                                                (0x0001C600U)
#define CSL_USB3_GBL_GTXFIFOPRIDEV                                             (0x0001C610U)
#define CSL_USB3_GBL_GTXFIFOPRIHST                                             (0x0001C618U)
#define CSL_USB3_GBL_GRXFIFOPRIHST                                             (0x0001C61CU)
#define CSL_USB3_GBL_GDMAHLRATIO                                               (0x0001C624U)
#define CSL_USB3_GBL_GFLADJ                                                    (0x0001C630U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* GUSB2PHYCFG */

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_TOUTCAL_MASK                 (0x00000007U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_TOUTCAL_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_TOUTCAL_MAX                  (0x00000007U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYIF_MASK                   (0x00000008U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYIF_SHIFT                  (0x00000003U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYIF_MAX                    (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK           (0x00000010U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_UTMI_SEL_SHIFT          (0x00000004U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_UTMI_SEL_MAX            (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_FSINTF_MASK                  (0x00000020U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_FSINTF_SHIFT                 (0x00000005U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_FSINTF_MAX                   (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_SUSPENDUSB20_MASK            (0x00000040U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_SUSPENDUSB20_SHIFT           (0x00000006U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_SUSPENDUSB20_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSEL_MASK                  (0x00000080U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSEL_SHIFT                 (0x00000007U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSEL_MAX                   (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ENBLSLPM_MASK                (0x00000100U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ENBLSLPM_SHIFT               (0x00000008U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ENBLSLPM_MAX                 (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_XCVRDLY_MASK                 (0x00000200U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_XCVRDLY_SHIFT                (0x00000009U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_XCVRDLY_MAX                  (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_USBTRDTIM_MASK               (0x00003C00U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_USBTRDTIM_SHIFT              (0x0000000AU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_USBTRDTIM_MAX                (0x0000000FU)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_14_MASK             (0x00004000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_14_SHIFT            (0x0000000EU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_14_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIAUTORES_MASK             (0x00008000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIAUTORES_SHIFT            (0x0000000FU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIAUTORES_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_16_MASK             (0x00010000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_16_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_16_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK          (0x00020000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSDRV_SHIFT         (0x00000011U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSDRV_MAX           (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_MASK    (0x00040000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_SHIFT   (0x00000012U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_MAX     (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSIPD_MASK                   (0x00380000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSIPD_SHIFT                  (0x00000013U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSIPD_MAX                    (0x00000007U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSTRD_MASK                   (0x01C00000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSTRD_SHIFT                  (0x00000016U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_LSTRD_MAX                    (0x00000007U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_25_MASK             (0x02000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_25_SHIFT            (0x00000019U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_RESERVED_25_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_INV_SEL_HSIC_MASK            (0x04000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_INV_SEL_HSIC_SHIFT           (0x0000001AU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_INV_SEL_HSIC_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_MASK      (0x18000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_SHIFT     (0x0000001BU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_MAX       (0x00000003U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_MASK (0x20000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_SHIFT (0x0000001DU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_MAX (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_U2_FREECLK_EXISTS_MASK       (0x40000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_U2_FREECLK_EXISTS_SHIFT      (0x0000001EU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_U2_FREECLK_EXISTS_MAX        (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSOFTRST_MASK              (0x80000000U)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSOFTRST_SHIFT             (0x0000001FU)
#define CSL_USB3_GBL_GUSB2PHYCFG_REGS_GUSB2PHYCFG_PHYSOFTRST_MAX               (0x00000001U)

/* GUSB2I2CCTL */

#define CSL_USB3_GBL_GUSB2I2CCTL_REGS_GUSB2I2CCTL_RESERVED_31_0_MASK           (0xFFFFFFFFU)
#define CSL_USB3_GBL_GUSB2I2CCTL_REGS_GUSB2I2CCTL_RESERVED_31_0_SHIFT          (0x00000000U)
#define CSL_USB3_GBL_GUSB2I2CCTL_REGS_GUSB2I2CCTL_RESERVED_31_0_MAX            (0xFFFFFFFFU)

/* GUSB2PHYACC_ULPI */

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGDATA_MASK            (0x000000FFU)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGDATA_SHIFT           (0x00000000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGDATA_MAX             (0x000000FFU)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_EXTREGADDR_MASK         (0x0000FF00U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_EXTREGADDR_SHIFT        (0x00000008U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_EXTREGADDR_MAX          (0x000000FFU)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGADDR_MASK            (0x003F0000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGADDR_SHIFT           (0x00000010U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGADDR_MAX             (0x0000003FU)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGWR_MASK              (0x00400000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGWR_SHIFT             (0x00000016U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_REGWR_MAX               (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSBSY_MASK            (0x00800000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSBSY_SHIFT           (0x00000017U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSBSY_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSDONE_MASK           (0x01000000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSDONE_SHIFT          (0x00000018U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_VSTSDONE_MAX            (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_NEWREGREQ_MASK          (0x02000000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_NEWREGREQ_SHIFT         (0x00000019U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_NEWREGREQ_MAX           (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_DISUIPIDRVR_MASK        (0x04000000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_DISUIPIDRVR_SHIFT       (0x0000001AU)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_DISUIPIDRVR_MAX         (0x00000001U)

#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_RESERVED_31_27_MASK     (0xF8000000U)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_RESERVED_31_27_SHIFT    (0x0000001BU)
#define CSL_USB3_GBL_GUSB2PHYACC_REGS_GUSB2PHYACC_ULPI_RESERVED_31_27_MAX      (0x0000001FU)

/* GUSB3PIPECTL */

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_MASK   (0x00000001U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_SHIFT  (0x00000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_MAX    (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_DE_EPPHASIS_MASK        (0x00000006U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_DE_EPPHASIS_SHIFT       (0x00000001U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_DE_EPPHASIS_MAX         (0x00000003U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_MARGIN_MASK             (0x00000038U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_MARGIN_SHIFT            (0x00000003U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_MARGIN_MAX              (0x00000007U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_SWING_MASK              (0x00000040U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_SWING_SHIFT             (0x00000006U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_TX_SWING_MAX               (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SSICEN_MASK                (0x00000080U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SSICEN_SHIFT               (0x00000007U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SSICEN_MAX                 (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_MASK (0x00000100U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_SHIFT (0x00000008U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_MAX (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSFILTER_MASK            (0x00000200U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSFILTER_SHIFT           (0x00000009U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSFILTER_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3EXSIGP2_MASK             (0x00000400U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3EXSIGP2_SHIFT            (0x0000000AU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3EXSIGP2_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3P2TRANOK_MASK            (0x00000800U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3P2TRANOK_SHIFT           (0x0000000BU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_P3P2TRANOK_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSP0ALGN_MASK            (0x00001000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSP0ALGN_SHIFT           (0x0000000CU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_LFPSP0ALGN_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SKIPRXDET_MASK             (0x00002000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SKIPRXDET_SHIFT            (0x0000000DU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SKIPRXDET_MAX              (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ABORTRXDETINU2_MASK        (0x00004000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ABORTRXDETINU2_SHIFT       (0x0000000EU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_ABORTRXDETINU2_MAX         (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DATWIDTH_MASK              (0x00018000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DATWIDTH_SHIFT             (0x0000000FU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DATWIDTH_MAX               (0x00000003U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SUSPENDENABLE_MASK         (0x00020000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SUSPENDENABLE_SHIFT        (0x00000011U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_SUSPENDENABLE_MAX          (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1TRANS_MASK          (0x00040000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1TRANS_SHIFT         (0x00000012U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1TRANS_MAX           (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1P2P3_MASK           (0x00380000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1P2P3_SHIFT          (0x00000013U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DELAYP1P2P3_MAX            (0x00000007U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETU3RXDET_MASK       (0x00400000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETU3RXDET_SHIFT      (0x00000016U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETU3RXDET_MAX        (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK     (0x00800000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_STARTRXDETU3RXDET_SHIFT    (0x00000017U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_STARTRXDETU3RXDET_MAX      (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_REQUEST_P1P2P3_MASK        (0x01000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_REQUEST_P1P2P3_SHIFT       (0x00000018U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_REQUEST_P1P2P3_MAX         (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK (0x02000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_SHIFT (0x00000019U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MAX  (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK   (0x04000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PING_ENHANCEMENT_EN_SHIFT  (0x0000001AU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MAX    (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK         (0x08000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_UX_EXIT_IN_PX_SHIFT        (0x0000001BU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_UX_EXIT_IN_PX_MAX          (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETP3_MASK            (0x10000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETP3_SHIFT           (0x0000001CU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_DISRXDETP3_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U2SSINACTP3OK_MASK         (0x20000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U2SSINACTP3OK_SHIFT        (0x0000001DU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_U2SSINACTP3OK_MAX          (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_HSTPRTCMPL_MASK            (0x40000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_HSTPRTCMPL_SHIFT           (0x0000001EU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_HSTPRTCMPL_MAX             (0x00000001U)

#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PHYSOFTRST_MASK            (0x80000000U)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PHYSOFTRST_SHIFT           (0x0000001FU)
#define CSL_USB3_GBL_GUSB3PIPECTL_REGS_GUSB3PIPECTL_PHYSOFTRST_MAX             (0x00000001U)

/* GTXFIFOSIZ0 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ0_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ1 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ1_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ2 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ2_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ3 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ3_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ4 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ4_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ5 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ5_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ6 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ6_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ7 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ7_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ8 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ8_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ9 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ9_TXFSTADDR_N_MAX               (0x0000FFFFU)

/* GTXFIFOSIZ10 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ10_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GTXFIFOSIZ11 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ11_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GTXFIFOSIZ12 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ12_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GTXFIFOSIZ13 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ13_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GTXFIFOSIZ14 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ14_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GTXFIFOSIZ15 */

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFDEP_N_MASK                (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFDEP_N_SHIFT               (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFDEP_N_MAX                 (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFSTADDR_N_MASK             (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFSTADDR_N_SHIFT            (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOSIZ_REGS_GTXFIFOSIZ15_TXFSTADDR_N_MAX              (0x0000FFFFU)

/* GRXFIFOSIZ0 */

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ0_RXFSTADDR_N_MAX               (0x0000FFFFU)

/* GRXFIFOSIZ1 */

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ1_RXFSTADDR_N_MAX               (0x0000FFFFU)

/* GRXFIFOSIZ2 */

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFDEP_N_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFDEP_N_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFDEP_N_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFSTADDR_N_MASK              (0xFFFF0000U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFSTADDR_N_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GRXFIFOSIZ_REGS_GRXFIFOSIZ2_RXFSTADDR_N_MAX               (0x0000FFFFU)

/* GEVNTADRLO */

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRLO_EVNTADRLO_MASK                 (0xFFFFFFFFU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRLO_EVNTADRLO_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRLO_EVNTADRLO_MAX                  (0xFFFFFFFFU)

/* GEVNTADRHI */

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRHI_EVNTADRHI_MASK                 (0xFFFFFFFFU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRHI_EVNTADRHI_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTADRHI_EVNTADRHI_MAX                  (0xFFFFFFFFU)

/* GEVNTSIZ */

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVENTSIZ_MASK                    (0x0000FFFFU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVENTSIZ_SHIFT                   (0x00000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVENTSIZ_MAX                     (0x0000FFFFU)

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_RESERVED_30_16_MASK              (0x7FFF0000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_RESERVED_30_16_SHIFT             (0x00000010U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_RESERVED_30_16_MAX               (0x00007FFFU)

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVNTINTRPTMASK_MASK              (0x80000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVNTINTRPTMASK_SHIFT             (0x0000001FU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTSIZ_EVNTINTRPTMASK_MAX               (0x00000001U)

/* GEVNTCOUNT */

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNTCOUNT_MASK                 (0x0000FFFFU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNTCOUNT_SHIFT                (0x00000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNTCOUNT_MAX                  (0x0000FFFFU)

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_RESERVED_30_16_MASK            (0x7FFF0000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_RESERVED_30_16_SHIFT           (0x00000010U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_RESERVED_30_16_MAX             (0x00007FFFU)

#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNT_HANDLER_BUSY_MASK         (0x80000000U)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNT_HANDLER_BUSY_SHIFT        (0x0000001FU)
#define CSL_USB3_GBL_GEVNTADRLO_REGS_GEVNTCOUNT_EVNT_HANDLER_BUSY_MAX          (0x00000001U)

/* GSBUSCFG0 */

#define CSL_USB3_GBL_GSBUSCFG0_INCRBRSTENA_MASK                                (0x00000001U)
#define CSL_USB3_GBL_GSBUSCFG0_INCRBRSTENA_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GSBUSCFG0_INCRBRSTENA_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR4BRSTENA_MASK                               (0x00000002U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR4BRSTENA_SHIFT                              (0x00000001U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR4BRSTENA_MAX                                (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR8BRSTENA_MASK                               (0x00000004U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR8BRSTENA_SHIFT                              (0x00000002U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR8BRSTENA_MAX                                (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR16BRSTENA_MASK                              (0x00000008U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR16BRSTENA_SHIFT                             (0x00000003U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR16BRSTENA_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR32BRSTENA_MASK                              (0x00000010U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR32BRSTENA_SHIFT                             (0x00000004U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR32BRSTENA_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR64BRSTENA_MASK                              (0x00000020U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR64BRSTENA_SHIFT                             (0x00000005U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR64BRSTENA_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR128BRSTENA_MASK                             (0x00000040U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR128BRSTENA_SHIFT                            (0x00000006U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR128BRSTENA_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_INCR256BRSTENA_MASK                             (0x00000080U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR256BRSTENA_SHIFT                            (0x00000007U)
#define CSL_USB3_GBL_GSBUSCFG0_INCR256BRSTENA_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_9_8_MASK                               (0x00000300U)
#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_9_8_SHIFT                              (0x00000008U)
#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_9_8_MAX                                (0x00000003U)

#define CSL_USB3_GBL_GSBUSCFG0_DESBIGEND_MASK                                  (0x00000400U)
#define CSL_USB3_GBL_GSBUSCFG0_DESBIGEND_SHIFT                                 (0x0000000AU)
#define CSL_USB3_GBL_GSBUSCFG0_DESBIGEND_MAX                                   (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_DATBIGEND_MASK                                  (0x00000800U)
#define CSL_USB3_GBL_GSBUSCFG0_DATBIGEND_SHIFT                                 (0x0000000BU)
#define CSL_USB3_GBL_GSBUSCFG0_DATBIGEND_MAX                                   (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_15_12_MASK                             (0x0000F000U)
#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_15_12_SHIFT                            (0x0000000CU)
#define CSL_USB3_GBL_GSBUSCFG0_RESERVED_15_12_MAX                              (0x0000000FU)

#define CSL_USB3_GBL_GSBUSCFG0_DESWRREQINFO_MASK                               (0x000F0000U)
#define CSL_USB3_GBL_GSBUSCFG0_DESWRREQINFO_SHIFT                              (0x00000010U)
#define CSL_USB3_GBL_GSBUSCFG0_DESWRREQINFO_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GSBUSCFG0_DATWRREQINFO_MASK                               (0x00F00000U)
#define CSL_USB3_GBL_GSBUSCFG0_DATWRREQINFO_SHIFT                              (0x00000014U)
#define CSL_USB3_GBL_GSBUSCFG0_DATWRREQINFO_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GSBUSCFG0_DESRDREQINFO_MASK                               (0x0F000000U)
#define CSL_USB3_GBL_GSBUSCFG0_DESRDREQINFO_SHIFT                              (0x00000018U)
#define CSL_USB3_GBL_GSBUSCFG0_DESRDREQINFO_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GSBUSCFG0_DATRDREQINFO_MASK                               (0xF0000000U)
#define CSL_USB3_GBL_GSBUSCFG0_DATRDREQINFO_SHIFT                              (0x0000001CU)
#define CSL_USB3_GBL_GSBUSCFG0_DATRDREQINFO_MAX                                (0x0000000FU)

/* GSBUSCFG1 */

#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_7_0_MASK                               (0x000000FFU)
#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_7_0_SHIFT                              (0x00000000U)
#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_7_0_MAX                                (0x000000FFU)

#define CSL_USB3_GBL_GSBUSCFG1_PIPETRANSLIMIT_MASK                             (0x00000F00U)
#define CSL_USB3_GBL_GSBUSCFG1_PIPETRANSLIMIT_SHIFT                            (0x00000008U)
#define CSL_USB3_GBL_GSBUSCFG1_PIPETRANSLIMIT_MAX                              (0x0000000FU)

#define CSL_USB3_GBL_GSBUSCFG1_EN1KPAGE_MASK                                   (0x00001000U)
#define CSL_USB3_GBL_GSBUSCFG1_EN1KPAGE_SHIFT                                  (0x0000000CU)
#define CSL_USB3_GBL_GSBUSCFG1_EN1KPAGE_MAX                                    (0x00000001U)

#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_31_13_MASK                             (0xFFFFE000U)
#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_31_13_SHIFT                            (0x0000000DU)
#define CSL_USB3_GBL_GSBUSCFG1_RESERVED_31_13_MAX                              (0x0007FFFFU)

/* GTXTHRCFG */

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_10_0_MASK                              (0x000007FFU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_10_0_SHIFT                             (0x00000000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_10_0_MAX                               (0x000007FFU)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_13_11_MASK                             (0x00003800U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_13_11_SHIFT                            (0x0000000BU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_13_11_MAX                              (0x00000007U)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_14_MASK                                (0x00004000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_14_SHIFT                               (0x0000000EU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_14_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_15_MASK                                (0x00008000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_15_SHIFT                               (0x0000000FU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_15_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK                          (0x00FF0000U)
#define CSL_USB3_GBL_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT                         (0x00000010U)
#define CSL_USB3_GBL_GTXTHRCFG_USBMAXTXBURSTSIZE_MAX                           (0x000000FFU)

#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNT_MASK                                (0x0F000000U)
#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNT_SHIFT                               (0x00000018U)
#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNT_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_28_MASK                                (0x10000000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_28_SHIFT                               (0x0000001CU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_28_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNTSEL_MASK                             (0x20000000U)
#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT                            (0x0000001DU)
#define CSL_USB3_GBL_GTXTHRCFG_USBTXPKTCNTSEL_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_30_MASK                                (0x40000000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_30_SHIFT                               (0x0000001EU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_30_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_31_MASK                                (0x80000000U)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_31_SHIFT                               (0x0000001FU)
#define CSL_USB3_GBL_GTXTHRCFG_RESERVED_31_MAX                                 (0x00000001U)

/* GRXTHRCFG */

#define CSL_USB3_GBL_GRXTHRCFG_RESVISOCOUTSPC_MASK                             (0x00001FFFU)
#define CSL_USB3_GBL_GRXTHRCFG_RESVISOCOUTSPC_SHIFT                            (0x00000000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESVISOCOUTSPC_MAX                              (0x00001FFFU)

#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_14_13_MASK                             (0x00006000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_14_13_SHIFT                            (0x0000000DU)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_14_13_MAX                              (0x00000003U)

#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_15_MASK                                (0x00008000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_15_SHIFT                               (0x0000000FU)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_15_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_18_16_MASK                             (0x00070000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_18_16_SHIFT                            (0x00000010U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_18_16_MAX                              (0x00000007U)

#define CSL_USB3_GBL_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK                          (0x00F80000U)
#define CSL_USB3_GBL_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT                         (0x00000013U)
#define CSL_USB3_GBL_GRXTHRCFG_USBMAXRXBURSTSIZE_MAX                           (0x0000001FU)

#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNT_MASK                                (0x0F000000U)
#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNT_SHIFT                               (0x00000018U)
#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNT_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_28_MASK                                (0x10000000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_28_SHIFT                               (0x0000001CU)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_28_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNTSEL_MASK                             (0x20000000U)
#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT                            (0x0000001DU)
#define CSL_USB3_GBL_GRXTHRCFG_USBRXPKTCNTSEL_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_31_30_MASK                             (0xC0000000U)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_31_30_SHIFT                            (0x0000001EU)
#define CSL_USB3_GBL_GRXTHRCFG_RESERVED_31_30_MAX                              (0x00000003U)

/* GCTL */

#define CSL_USB3_GBL_GCTL_DSBLCLKGTNG_MASK                                     (0x00000001U)
#define CSL_USB3_GBL_GCTL_DSBLCLKGTNG_SHIFT                                    (0x00000000U)
#define CSL_USB3_GBL_GCTL_DSBLCLKGTNG_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GCTL_GBLHIBERNATIONEN_MASK                                (0x00000002U)
#define CSL_USB3_GBL_GCTL_GBLHIBERNATIONEN_SHIFT                               (0x00000001U)
#define CSL_USB3_GBL_GCTL_GBLHIBERNATIONEN_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GCTL_U2EXIT_LFPS_MASK                                     (0x00000004U)
#define CSL_USB3_GBL_GCTL_U2EXIT_LFPS_SHIFT                                    (0x00000002U)
#define CSL_USB3_GBL_GCTL_U2EXIT_LFPS_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GCTL_DISSCRAMBLE_MASK                                     (0x00000008U)
#define CSL_USB3_GBL_GCTL_DISSCRAMBLE_SHIFT                                    (0x00000003U)
#define CSL_USB3_GBL_GCTL_DISSCRAMBLE_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GCTL_SCALEDOWN_MASK                                       (0x00000030U)
#define CSL_USB3_GBL_GCTL_SCALEDOWN_SHIFT                                      (0x00000004U)
#define CSL_USB3_GBL_GCTL_SCALEDOWN_MAX                                        (0x00000003U)

#define CSL_USB3_GBL_GCTL_RAMCLKSEL_MASK                                       (0x000000C0U)
#define CSL_USB3_GBL_GCTL_RAMCLKSEL_SHIFT                                      (0x00000006U)
#define CSL_USB3_GBL_GCTL_RAMCLKSEL_MAX                                        (0x00000003U)

#define CSL_USB3_GBL_GCTL_DEBUGATTACH_MASK                                     (0x00000100U)
#define CSL_USB3_GBL_GCTL_DEBUGATTACH_SHIFT                                    (0x00000008U)
#define CSL_USB3_GBL_GCTL_DEBUGATTACH_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GCTL_U1U2TIMERSCALE_MASK                                  (0x00000200U)
#define CSL_USB3_GBL_GCTL_U1U2TIMERSCALE_SHIFT                                 (0x00000009U)
#define CSL_USB3_GBL_GCTL_U1U2TIMERSCALE_MAX                                   (0x00000001U)

#define CSL_USB3_GBL_GCTL_SOFITPSYNC_MASK                                      (0x00000400U)
#define CSL_USB3_GBL_GCTL_SOFITPSYNC_SHIFT                                     (0x0000000AU)
#define CSL_USB3_GBL_GCTL_SOFITPSYNC_MAX                                       (0x00000001U)

#define CSL_USB3_GBL_GCTL_CORESOFTRESET_MASK                                   (0x00000800U)
#define CSL_USB3_GBL_GCTL_CORESOFTRESET_SHIFT                                  (0x0000000BU)
#define CSL_USB3_GBL_GCTL_CORESOFTRESET_MAX                                    (0x00000001U)

#define CSL_USB3_GBL_GCTL_PRTCAPDIR_MASK                                       (0x00003000U)
#define CSL_USB3_GBL_GCTL_PRTCAPDIR_SHIFT                                      (0x0000000CU)
#define CSL_USB3_GBL_GCTL_PRTCAPDIR_MAX                                        (0x00000003U)

#define CSL_USB3_GBL_GCTL_FRMSCLDWN_MASK                                       (0x0000C000U)
#define CSL_USB3_GBL_GCTL_FRMSCLDWN_SHIFT                                      (0x0000000EU)
#define CSL_USB3_GBL_GCTL_FRMSCLDWN_MAX                                        (0x00000003U)

#define CSL_USB3_GBL_GCTL_U2RSTECN_MASK                                        (0x00010000U)
#define CSL_USB3_GBL_GCTL_U2RSTECN_SHIFT                                       (0x00000010U)
#define CSL_USB3_GBL_GCTL_U2RSTECN_MAX                                         (0x00000001U)

#define CSL_USB3_GBL_GCTL_BYPSSETADDR_MASK                                     (0x00020000U)
#define CSL_USB3_GBL_GCTL_BYPSSETADDR_SHIFT                                    (0x00000011U)
#define CSL_USB3_GBL_GCTL_BYPSSETADDR_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GCTL_MASTERFILTBYPASS_MASK                                (0x00040000U)
#define CSL_USB3_GBL_GCTL_MASTERFILTBYPASS_SHIFT                               (0x00000012U)
#define CSL_USB3_GBL_GCTL_MASTERFILTBYPASS_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GCTL_PWRDNSCALE_MASK                                      (0xFFF80000U)
#define CSL_USB3_GBL_GCTL_PWRDNSCALE_SHIFT                                     (0x00000013U)
#define CSL_USB3_GBL_GCTL_PWRDNSCALE_MAX                                       (0x00001FFFU)

/* GPMSTS */

#define CSL_USB3_GBL_GPMSTS_U2WAKEUP_MASK                                      (0x000003FFU)
#define CSL_USB3_GBL_GPMSTS_U2WAKEUP_SHIFT                                     (0x00000000U)
#define CSL_USB3_GBL_GPMSTS_U2WAKEUP_MAX                                       (0x000003FFU)

#define CSL_USB3_GBL_GPMSTS_RESERVED_10_11_MASK                                (0x00000C00U)
#define CSL_USB3_GBL_GPMSTS_RESERVED_10_11_SHIFT                               (0x0000000AU)
#define CSL_USB3_GBL_GPMSTS_RESERVED_10_11_MAX                                 (0x00000003U)

#define CSL_USB3_GBL_GPMSTS_U3WAKEUP_MASK                                      (0x0001F000U)
#define CSL_USB3_GBL_GPMSTS_U3WAKEUP_SHIFT                                     (0x0000000CU)
#define CSL_USB3_GBL_GPMSTS_U3WAKEUP_MAX                                       (0x0000001FU)

#define CSL_USB3_GBL_GPMSTS_RESERVED_27_17_MASK                                (0x0FFE0000U)
#define CSL_USB3_GBL_GPMSTS_RESERVED_27_17_SHIFT                               (0x00000011U)
#define CSL_USB3_GBL_GPMSTS_RESERVED_27_17_MAX                                 (0x000007FFU)

#define CSL_USB3_GBL_GPMSTS_PORTSEL_MASK                                       (0xF0000000U)
#define CSL_USB3_GBL_GPMSTS_PORTSEL_SHIFT                                      (0x0000001CU)
#define CSL_USB3_GBL_GPMSTS_PORTSEL_MAX                                        (0x0000000FU)

/* GSTS */

#define CSL_USB3_GBL_GSTS_CURMOD_MASK                                          (0x00000003U)
#define CSL_USB3_GBL_GSTS_CURMOD_SHIFT                                         (0x00000000U)
#define CSL_USB3_GBL_GSTS_CURMOD_MAX                                           (0x00000003U)

#define CSL_USB3_GBL_GSTS_RESERVED_3_2_MASK                                    (0x0000000CU)
#define CSL_USB3_GBL_GSTS_RESERVED_3_2_SHIFT                                   (0x00000002U)
#define CSL_USB3_GBL_GSTS_RESERVED_3_2_MAX                                     (0x00000003U)

#define CSL_USB3_GBL_GSTS_BUSERRADDRVLD_MASK                                   (0x00000010U)
#define CSL_USB3_GBL_GSTS_BUSERRADDRVLD_SHIFT                                  (0x00000004U)
#define CSL_USB3_GBL_GSTS_BUSERRADDRVLD_MAX                                    (0x00000001U)

#define CSL_USB3_GBL_GSTS_CSRTIMEOUT_MASK                                      (0x00000020U)
#define CSL_USB3_GBL_GSTS_CSRTIMEOUT_SHIFT                                     (0x00000005U)
#define CSL_USB3_GBL_GSTS_CSRTIMEOUT_MAX                                       (0x00000001U)

#define CSL_USB3_GBL_GSTS_DEVICE_IP_MASK                                       (0x00000040U)
#define CSL_USB3_GBL_GSTS_DEVICE_IP_SHIFT                                      (0x00000006U)
#define CSL_USB3_GBL_GSTS_DEVICE_IP_MAX                                        (0x00000001U)

#define CSL_USB3_GBL_GSTS_HOST_IP_MASK                                         (0x00000080U)
#define CSL_USB3_GBL_GSTS_HOST_IP_SHIFT                                        (0x00000007U)
#define CSL_USB3_GBL_GSTS_HOST_IP_MAX                                          (0x00000001U)

#define CSL_USB3_GBL_GSTS_ADP_IP_MASK                                          (0x00000100U)
#define CSL_USB3_GBL_GSTS_ADP_IP_SHIFT                                         (0x00000008U)
#define CSL_USB3_GBL_GSTS_ADP_IP_MAX                                           (0x00000001U)

#define CSL_USB3_GBL_GSTS_BC_IP_MASK                                           (0x00000200U)
#define CSL_USB3_GBL_GSTS_BC_IP_SHIFT                                          (0x00000009U)
#define CSL_USB3_GBL_GSTS_BC_IP_MAX                                            (0x00000001U)

#define CSL_USB3_GBL_GSTS_OTG_IP_MASK                                          (0x00000400U)
#define CSL_USB3_GBL_GSTS_OTG_IP_SHIFT                                         (0x0000000AU)
#define CSL_USB3_GBL_GSTS_OTG_IP_MAX                                           (0x00000001U)

#define CSL_USB3_GBL_GSTS_SSIC_IP_MASK                                         (0x00000800U)
#define CSL_USB3_GBL_GSTS_SSIC_IP_SHIFT                                        (0x0000000BU)
#define CSL_USB3_GBL_GSTS_SSIC_IP_MAX                                          (0x00000001U)

#define CSL_USB3_GBL_GSTS_RESERVED_19_12_MASK                                  (0x000FF000U)
#define CSL_USB3_GBL_GSTS_RESERVED_19_12_SHIFT                                 (0x0000000CU)
#define CSL_USB3_GBL_GSTS_RESERVED_19_12_MAX                                   (0x000000FFU)

#define CSL_USB3_GBL_GSTS_CBELT_MASK                                           (0xFFF00000U)
#define CSL_USB3_GBL_GSTS_CBELT_SHIFT                                          (0x00000014U)
#define CSL_USB3_GBL_GSTS_CBELT_MAX                                            (0x00000FFFU)

/* GUCTL1 */

#define CSL_USB3_GBL_GUCTL1_LOA_FILTER_EN_MASK                                 (0x00000001U)
#define CSL_USB3_GBL_GUCTL1_LOA_FILTER_EN_SHIFT                                (0x00000000U)
#define CSL_USB3_GBL_GUCTL1_LOA_FILTER_EN_MAX                                  (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_OVRLD_L1_SUSP_COM_MASK                             (0x00000002U)
#define CSL_USB3_GBL_GUCTL1_OVRLD_L1_SUSP_COM_SHIFT                            (0x00000001U)
#define CSL_USB3_GBL_GUCTL1_OVRLD_L1_SUSP_COM_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_HC_PARCHK_DISABLE_MASK                             (0x00000004U)
#define CSL_USB3_GBL_GUCTL1_HC_PARCHK_DISABLE_SHIFT                            (0x00000002U)
#define CSL_USB3_GBL_GUCTL1_HC_PARCHK_DISABLE_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_HC_ERRATA_ENABLE_MASK                              (0x00000008U)
#define CSL_USB3_GBL_GUCTL1_HC_ERRATA_ENABLE_SHIFT                             (0x00000003U)
#define CSL_USB3_GBL_GUCTL1_HC_ERRATA_ENABLE_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MASK                        (0x000000F0U)
#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_FOR_HOST_SHIFT                       (0x00000004U)
#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MAX                         (0x0000000FU)

#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MASK                     (0x00000100U)
#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_SHIFT                    (0x00000008U)
#define CSL_USB3_GBL_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MAX                      (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DEV_HS_NYET_BULK_SPR_MASK                          (0x00000200U)
#define CSL_USB3_GBL_GUCTL1_DEV_HS_NYET_BULK_SPR_SHIFT                         (0x00000009U)
#define CSL_USB3_GBL_GUCTL1_DEV_HS_NYET_BULK_SPR_MAX                           (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_RESERVED_14_10_MASK                                (0x00007C00U)
#define CSL_USB3_GBL_GUCTL1_RESERVED_14_10_SHIFT                               (0x0000000AU)
#define CSL_USB3_GBL_GUCTL1_RESERVED_14_10_MAX                                 (0x0000001FU)

#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_FSLS_MASK                         (0x00008000U)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_FSLS_SHIFT                        (0x0000000FU)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_FSLS_MAX                          (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_HS_MASK                           (0x00010000U)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_HS_SHIFT                          (0x00000010U)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_HS_MAX                            (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_SS_MASK                           (0x00020000U)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_SS_SHIFT                          (0x00000011U)
#define CSL_USB3_GBL_GUCTL1_PARKMODE_DISABLE_SS_MAX                            (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_HS_MASK                                (0x00040000U)
#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_HS_SHIFT                               (0x00000012U)
#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_HS_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_FS_MASK                                (0x00080000U)
#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_FS_SHIFT                               (0x00000013U)
#define CSL_USB3_GBL_GUCTL1_NAK_PER_ENH_FS_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_MASK                         (0x00100000U)
#define CSL_USB3_GBL_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_SHIFT                        (0x00000014U)
#define CSL_USB3_GBL_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_MAX                          (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_IP_GAP_ADD_ON_MASK                                 (0x00E00000U)
#define CSL_USB3_GBL_GUCTL1_IP_GAP_ADD_ON_SHIFT                                (0x00000015U)
#define CSL_USB3_GBL_GUCTL1_IP_GAP_ADD_ON_MAX                                  (0x00000007U)

#define CSL_USB3_GBL_GUCTL1_DEV_L1_EXIT_BY_HW_MASK                             (0x01000000U)
#define CSL_USB3_GBL_GUCTL1_DEV_L1_EXIT_BY_HW_SHIFT                            (0x00000018U)
#define CSL_USB3_GBL_GUCTL1_DEV_L1_EXIT_BY_HW_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_P3_IN_U2_MASK                                      (0x02000000U)
#define CSL_USB3_GBL_GUCTL1_P3_IN_U2_SHIFT                                     (0x00000019U)
#define CSL_USB3_GBL_GUCTL1_P3_IN_U2_MAX                                       (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_MASK                   (0x04000000U)
#define CSL_USB3_GBL_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_SHIFT                  (0x0000001AU)
#define CSL_USB3_GBL_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_MAX                    (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DEV_TRB_OUT_SPR_IND_MASK                           (0x08000000U)
#define CSL_USB3_GBL_GUCTL1_DEV_TRB_OUT_SPR_IND_SHIFT                          (0x0000001BU)
#define CSL_USB3_GBL_GUCTL1_DEV_TRB_OUT_SPR_IND_MAX                            (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_TX_IPGAP_LINECHECK_DIS_MASK                        (0x10000000U)
#define CSL_USB3_GBL_GUCTL1_TX_IPGAP_LINECHECK_DIS_SHIFT                       (0x0000001CU)
#define CSL_USB3_GBL_GUCTL1_TX_IPGAP_LINECHECK_DIS_MAX                         (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_FILTER_SE0_FSLS_EOP_MASK                           (0x20000000U)
#define CSL_USB3_GBL_GUCTL1_FILTER_SE0_FSLS_EOP_SHIFT                          (0x0000001DU)
#define CSL_USB3_GBL_GUCTL1_FILTER_SE0_FSLS_EOP_MAX                            (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_MASK                        (0x40000000U)
#define CSL_USB3_GBL_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_SHIFT                       (0x0000001EU)
#define CSL_USB3_GBL_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_MAX                         (0x00000001U)

#define CSL_USB3_GBL_GUCTL1_DEV_DECOUPLE_L1L2_EVT_MASK                         (0x80000000U)
#define CSL_USB3_GBL_GUCTL1_DEV_DECOUPLE_L1L2_EVT_SHIFT                        (0x0000001FU)
#define CSL_USB3_GBL_GUCTL1_DEV_DECOUPLE_L1L2_EVT_MAX                          (0x00000001U)

/* GSNPSID */

#define CSL_USB3_GBL_GSNPSID_SYNOPSYSID_MASK                                   (0xFFFFFFFFU)
#define CSL_USB3_GBL_GSNPSID_SYNOPSYSID_SHIFT                                  (0x00000000U)
#define CSL_USB3_GBL_GSNPSID_SYNOPSYSID_MAX                                    (0xFFFFFFFFU)

/* GGPIO */

#define CSL_USB3_GBL_GGPIO_GPI_MASK                                            (0x0000FFFFU)
#define CSL_USB3_GBL_GGPIO_GPI_SHIFT                                           (0x00000000U)
#define CSL_USB3_GBL_GGPIO_GPI_MAX                                             (0x0000FFFFU)

#define CSL_USB3_GBL_GGPIO_GPO_MASK                                            (0xFFFF0000U)
#define CSL_USB3_GBL_GGPIO_GPO_SHIFT                                           (0x00000010U)
#define CSL_USB3_GBL_GGPIO_GPO_MAX                                             (0x0000FFFFU)

/* GUID */

#define CSL_USB3_GBL_GUID_USERID_MASK                                          (0xFFFFFFFFU)
#define CSL_USB3_GBL_GUID_USERID_SHIFT                                         (0x00000000U)
#define CSL_USB3_GBL_GUID_USERID_MAX                                           (0xFFFFFFFFU)

/* GUCTL */

#define CSL_USB3_GBL_GUCTL_DTFT_MASK                                           (0x000001FFU)
#define CSL_USB3_GBL_GUCTL_DTFT_SHIFT                                          (0x00000000U)
#define CSL_USB3_GBL_GUCTL_DTFT_MAX                                            (0x000001FFU)

#define CSL_USB3_GBL_GUCTL_DTCT_MASK                                           (0x00000600U)
#define CSL_USB3_GBL_GUCTL_DTCT_SHIFT                                          (0x00000009U)
#define CSL_USB3_GBL_GUCTL_DTCT_MAX                                            (0x00000003U)

#define CSL_USB3_GBL_GUCTL_INSRTEXTRFSBODI_MASK                                (0x00000800U)
#define CSL_USB3_GBL_GUCTL_INSRTEXTRFSBODI_SHIFT                               (0x0000000BU)
#define CSL_USB3_GBL_GUCTL_INSRTEXTRFSBODI_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GUCTL_EXTCAPSUPPTEN_MASK                                  (0x00001000U)
#define CSL_USB3_GBL_GUCTL_EXTCAPSUPPTEN_SHIFT                                 (0x0000000CU)
#define CSL_USB3_GBL_GUCTL_EXTCAPSUPPTEN_MAX                                   (0x00000001U)

#define CSL_USB3_GBL_GUCTL_ENOVERLAPCHK_MASK                                   (0x00002000U)
#define CSL_USB3_GBL_GUCTL_ENOVERLAPCHK_SHIFT                                  (0x0000000DU)
#define CSL_USB3_GBL_GUCTL_ENOVERLAPCHK_MAX                                    (0x00000001U)

#define CSL_USB3_GBL_GUCTL_USBHSTINAUTORETRYEN_MASK                            (0x00004000U)
#define CSL_USB3_GBL_GUCTL_USBHSTINAUTORETRYEN_SHIFT                           (0x0000000EU)
#define CSL_USB3_GBL_GUCTL_USBHSTINAUTORETRYEN_MAX                             (0x00000001U)

#define CSL_USB3_GBL_GUCTL_CMDEVADDR_MASK                                      (0x00008000U)
#define CSL_USB3_GBL_GUCTL_CMDEVADDR_SHIFT                                     (0x0000000FU)
#define CSL_USB3_GBL_GUCTL_CMDEVADDR_MAX                                       (0x00000001U)

#define CSL_USB3_GBL_GUCTL_RESBWHSEPS_MASK                                     (0x00010000U)
#define CSL_USB3_GBL_GUCTL_RESBWHSEPS_SHIFT                                    (0x00000010U)
#define CSL_USB3_GBL_GUCTL_RESBWHSEPS_MAX                                      (0x00000001U)

#define CSL_USB3_GBL_GUCTL_SPRSCTRLTRANSEN_MASK                                (0x00020000U)
#define CSL_USB3_GBL_GUCTL_SPRSCTRLTRANSEN_SHIFT                               (0x00000011U)
#define CSL_USB3_GBL_GUCTL_SPRSCTRLTRANSEN_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GUCTL_RESERVED_20_18_MASK                                 (0x001C0000U)
#define CSL_USB3_GBL_GUCTL_RESERVED_20_18_SHIFT                                (0x00000012U)
#define CSL_USB3_GBL_GUCTL_RESERVED_20_18_MAX                                  (0x00000007U)

#define CSL_USB3_GBL_GUCTL_NOEXTRDL_MASK                                       (0x00200000U)
#define CSL_USB3_GBL_GUCTL_NOEXTRDL_SHIFT                                      (0x00000015U)
#define CSL_USB3_GBL_GUCTL_NOEXTRDL_MAX                                        (0x00000001U)

#define CSL_USB3_GBL_GUCTL_REFCLKPER_MASK                                      (0xFFC00000U)
#define CSL_USB3_GBL_GUCTL_REFCLKPER_SHIFT                                     (0x00000016U)
#define CSL_USB3_GBL_GUCTL_REFCLKPER_MAX                                       (0x000003FFU)

/* GBUSERRADDRLO */

#define CSL_USB3_GBL_GBUSERRADDRLO_BUSERRADDR_MASK                             (0xFFFFFFFFU)
#define CSL_USB3_GBL_GBUSERRADDRLO_BUSERRADDR_SHIFT                            (0x00000000U)
#define CSL_USB3_GBL_GBUSERRADDRLO_BUSERRADDR_MAX                              (0xFFFFFFFFU)

/* GBUSERRADDRHI */

#define CSL_USB3_GBL_GBUSERRADDRHI_BUSERRADDR_MASK                             (0xFFFFFFFFU)
#define CSL_USB3_GBL_GBUSERRADDRHI_BUSERRADDR_SHIFT                            (0x00000000U)
#define CSL_USB3_GBL_GBUSERRADDRHI_BUSERRADDR_MAX                              (0xFFFFFFFFU)

/* GPRTBIMAPLO */

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM1_MASK                                   (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM1_SHIFT                                  (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM1_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM2_MASK                                   (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM2_SHIFT                                  (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM2_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM3_MASK                                   (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM3_SHIFT                                  (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM3_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM4_MASK                                   (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM4_SHIFT                                  (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM4_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM5_MASK                                   (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM5_SHIFT                                  (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM5_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM6_MASK                                   (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM6_SHIFT                                  (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM6_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM7_MASK                                   (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM7_SHIFT                                  (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM7_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM8_MASK                                   (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM8_SHIFT                                  (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAPLO_BINUM8_MAX                                    (0x0000000FU)

/* GPRTBIMAPHI */

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM9_MASK                                   (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM9_SHIFT                                  (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM9_MAX                                    (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM10_MASK                                  (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM10_SHIFT                                 (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM10_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM11_MASK                                  (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM11_SHIFT                                 (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM11_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM12_MASK                                  (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM12_SHIFT                                 (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM12_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM13_MASK                                  (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM13_SHIFT                                 (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM13_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM14_MASK                                  (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM14_SHIFT                                 (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM14_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM15_MASK                                  (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM15_SHIFT                                 (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAPHI_BINUM15_MAX                                   (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAPHI_RESERVED_31_28_MASK                           (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAPHI_RESERVED_31_28_SHIFT                          (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAPHI_RESERVED_31_28_MAX                            (0x0000000FU)

/* GHWPARAMS0 */

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_2_0_MASK                            (0x00000007U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_2_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_2_0_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_5_3_MASK                            (0x00000038U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_5_3_SHIFT                           (0x00000003U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_5_3_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_7_6_MASK                            (0x000000C0U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_7_6_SHIFT                           (0x00000006U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_7_6_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_15_8_MASK                           (0x0000FF00U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_15_8_SHIFT                          (0x00000008U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_15_8_MAX                            (0x000000FFU)

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_23_16_MASK                          (0x00FF0000U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_23_16_SHIFT                         (0x00000010U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_23_16_MAX                           (0x000000FFU)

#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_31_24_MASK                          (0xFF000000U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_31_24_SHIFT                         (0x00000018U)
#define CSL_USB3_GBL_GHWPARAMS0_GHWPARAMS0_31_24_MAX                           (0x000000FFU)

/* GHWPARAMS1 */

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_2_0_MASK                            (0x00000007U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_2_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_2_0_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_5_3_MASK                            (0x00000038U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_5_3_SHIFT                           (0x00000003U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_5_3_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_8_6_MASK                            (0x000001C0U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_8_6_SHIFT                           (0x00000006U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_8_6_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_11_9_MASK                           (0x00000E00U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_11_9_SHIFT                          (0x00000009U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_11_9_MAX                            (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_14_12_MASK                          (0x00007000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_14_12_SHIFT                         (0x0000000CU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_14_12_MAX                           (0x00000007U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_20_15_MASK                          (0x001F8000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_20_15_SHIFT                         (0x0000000FU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_20_15_MAX                           (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_22_21_MASK                          (0x00600000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_22_21_SHIFT                         (0x00000015U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_22_21_MAX                           (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_23_MASK                             (0x00800000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_23_SHIFT                            (0x00000017U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_23_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_25_24_MASK                          (0x03000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_25_24_SHIFT                         (0x00000018U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_25_24_MAX                           (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_26_MASK                             (0x04000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_26_SHIFT                            (0x0000001AU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_26_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_27_MASK                             (0x08000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_27_SHIFT                            (0x0000001BU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_27_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_28_MASK                             (0x10000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_28_SHIFT                            (0x0000001CU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_28_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_29_MASK                             (0x20000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_29_SHIFT                            (0x0000001DU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_29_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_30_MASK                             (0x40000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_30_SHIFT                            (0x0000001EU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_30_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_31_MASK                             (0x80000000U)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_31_SHIFT                            (0x0000001FU)
#define CSL_USB3_GBL_GHWPARAMS1_GHWPARAMS1_31_MAX                              (0x00000001U)

/* GHWPARAMS2 */

#define CSL_USB3_GBL_GHWPARAMS2_GHWPARAMS2_31_0_MASK                           (0xFFFFFFFFU)
#define CSL_USB3_GBL_GHWPARAMS2_GHWPARAMS2_31_0_SHIFT                          (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS2_GHWPARAMS2_31_0_MAX                            (0xFFFFFFFFU)

/* GHWPARAMS3 */

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_1_0_MASK                            (0x00000003U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_1_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_1_0_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_3_2_MASK                            (0x0000000CU)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_3_2_SHIFT                           (0x00000002U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_3_2_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_5_4_MASK                            (0x00000030U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_5_4_SHIFT                           (0x00000004U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_5_4_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_7_6_MASK                            (0x000000C0U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_7_6_SHIFT                           (0x00000006U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_7_6_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_9_8_MASK                            (0x00000300U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_9_8_SHIFT                           (0x00000008U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_9_8_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_10_MASK                             (0x00000400U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_10_SHIFT                            (0x0000000AU)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_10_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_11_MASK                             (0x00000800U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_11_SHIFT                            (0x0000000BU)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_11_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_17_12_MASK                          (0x0003F000U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_17_12_SHIFT                         (0x0000000CU)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_17_12_MAX                           (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_22_18_MASK                          (0x007C0000U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_22_18_SHIFT                         (0x00000012U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_22_18_MAX                           (0x0000001FU)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_30_23_MASK                          (0x7F800000U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_30_23_SHIFT                         (0x00000017U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_30_23_MAX                           (0x000000FFU)

#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_31_MASK                             (0x80000000U)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_31_SHIFT                            (0x0000001FU)
#define CSL_USB3_GBL_GHWPARAMS3_GHWPARAMS3_31_MAX                              (0x00000001U)

/* GHWPARAMS4 */

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_5_0_MASK                            (0x0000003FU)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_5_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_5_0_MAX                             (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_6_MASK                              (0x00000040U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_6_SHIFT                             (0x00000006U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_6_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_8_7_MASK                            (0x00000180U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_8_7_SHIFT                           (0x00000007U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_8_7_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_10_9_MASK                           (0x00000600U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_10_9_SHIFT                          (0x00000009U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_10_9_MAX                            (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_11_MASK                             (0x00000800U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_11_SHIFT                            (0x0000000BU)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_11_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_12_MASK                             (0x00001000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_12_SHIFT                            (0x0000000CU)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_12_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_16_13_MASK                          (0x0001E000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_16_13_SHIFT                         (0x0000000DU)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_16_13_MAX                           (0x0000000FU)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_20_17_MASK                          (0x001E0000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_20_17_SHIFT                         (0x00000011U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_20_17_MAX                           (0x0000000FU)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_21_MASK                             (0x00200000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_21_SHIFT                            (0x00000015U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_21_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_22_MASK                             (0x00400000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_22_SHIFT                            (0x00000016U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_22_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_23_MASK                             (0x00800000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_23_SHIFT                            (0x00000017U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_23_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_27_24_MASK                          (0x0F000000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_27_24_SHIFT                         (0x00000018U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_27_24_MAX                           (0x0000000FU)

#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_31_28_MASK                          (0xF0000000U)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_31_28_SHIFT                         (0x0000001CU)
#define CSL_USB3_GBL_GHWPARAMS4_GHWPARAMS4_31_28_MAX                           (0x0000000FU)

/* GHWPARAMS5 */

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_3_0_MASK                            (0x0000000FU)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_3_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_3_0_MAX                             (0x0000000FU)

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_9_4_MASK                            (0x000003F0U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_9_4_SHIFT                           (0x00000004U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_9_4_MAX                             (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_15_10_MASK                          (0x0000FC00U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_15_10_SHIFT                         (0x0000000AU)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_15_10_MAX                           (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_21_16_MASK                          (0x003F0000U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_21_16_SHIFT                         (0x00000010U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_21_16_MAX                           (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_27_22_MASK                          (0x0FC00000U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_27_22_SHIFT                         (0x00000016U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_27_22_MAX                           (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_31_28_MASK                          (0xF0000000U)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_31_28_SHIFT                         (0x0000001CU)
#define CSL_USB3_GBL_GHWPARAMS5_GHWPARAMS5_31_28_MAX                           (0x0000000FU)

/* GHWPARAMS6 */

#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_5_0_MASK                            (0x0000003FU)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_5_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_5_0_MAX                             (0x0000003FU)

#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_6_MASK                              (0x00000040U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_6_SHIFT                             (0x00000006U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_6_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_7_MASK                              (0x00000080U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_7_SHIFT                             (0x00000007U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_7_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_9_8_MASK                            (0x00000300U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_9_8_SHIFT                           (0x00000008U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_9_8_MAX                             (0x00000003U)

#define CSL_USB3_GBL_GHWPARAMS6_SRPSUPPORT_MASK                                (0x00000400U)
#define CSL_USB3_GBL_GHWPARAMS6_SRPSUPPORT_SHIFT                               (0x0000000AU)
#define CSL_USB3_GBL_GHWPARAMS6_SRPSUPPORT_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_HNPSUPPORT_MASK                                (0x00000800U)
#define CSL_USB3_GBL_GHWPARAMS6_HNPSUPPORT_SHIFT                               (0x0000000BU)
#define CSL_USB3_GBL_GHWPARAMS6_HNPSUPPORT_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_ADPSUPPORT_MASK                                (0x00001000U)
#define CSL_USB3_GBL_GHWPARAMS6_ADPSUPPORT_SHIFT                               (0x0000000CU)
#define CSL_USB3_GBL_GHWPARAMS6_ADPSUPPORT_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_OTG_SS_SUPPORT_MASK                            (0x00002000U)
#define CSL_USB3_GBL_GHWPARAMS6_OTG_SS_SUPPORT_SHIFT                           (0x0000000DU)
#define CSL_USB3_GBL_GHWPARAMS6_OTG_SS_SUPPORT_MAX                             (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_BCSUPPORT_MASK                                 (0x00004000U)
#define CSL_USB3_GBL_GHWPARAMS6_BCSUPPORT_SHIFT                                (0x0000000EU)
#define CSL_USB3_GBL_GHWPARAMS6_BCSUPPORT_MAX                                  (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_BUSFLTRSSUPPORT_MASK                           (0x00008000U)
#define CSL_USB3_GBL_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT                          (0x0000000FU)
#define CSL_USB3_GBL_GHWPARAMS6_BUSFLTRSSUPPORT_MAX                            (0x00000001U)

#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_31_16_MASK                          (0xFFFF0000U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_31_16_SHIFT                         (0x00000010U)
#define CSL_USB3_GBL_GHWPARAMS6_GHWPARAMS6_31_16_MAX                           (0x0000FFFFU)

/* GHWPARAMS7 */

#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_15_0_MASK                           (0x0000FFFFU)
#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_15_0_SHIFT                          (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_15_0_MAX                            (0x0000FFFFU)

#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_31_16_MASK                          (0xFFFF0000U)
#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_31_16_SHIFT                         (0x00000010U)
#define CSL_USB3_GBL_GHWPARAMS7_GHWPARAMS7_31_16_MAX                           (0x0000FFFFU)

/* GDBGFIFOSPACE */

#define CSL_USB3_GBL_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MASK                      (0x000001FFU)
#define CSL_USB3_GBL_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_SHIFT                     (0x00000000U)
#define CSL_USB3_GBL_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MAX                       (0x000001FFU)

#define CSL_USB3_GBL_GDBGFIFOSPACE_RESERVED_15_9_MASK                          (0x0000FE00U)
#define CSL_USB3_GBL_GDBGFIFOSPACE_RESERVED_15_9_SHIFT                         (0x00000009U)
#define CSL_USB3_GBL_GDBGFIFOSPACE_RESERVED_15_9_MAX                           (0x0000007FU)

#define CSL_USB3_GBL_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK                        (0xFFFF0000U)
#define CSL_USB3_GBL_GDBGFIFOSPACE_SPACE_AVAILABLE_SHIFT                       (0x00000010U)
#define CSL_USB3_GBL_GDBGFIFOSPACE_SPACE_AVAILABLE_MAX                         (0x0000FFFFU)

/* GDBGLTSSM */

#define CSL_USB3_GBL_GDBGLTSSM_TXONESZEROS_MASK                                (0x00000001U)
#define CSL_USB3_GBL_GDBGLTSSM_TXONESZEROS_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GDBGLTSSM_TXONESZEROS_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_RXTERMINATION_MASK                              (0x00000002U)
#define CSL_USB3_GBL_GDBGLTSSM_RXTERMINATION_SHIFT                             (0x00000001U)
#define CSL_USB3_GBL_GDBGLTSSM_RXTERMINATION_MAX                               (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_TXSWING_MASK                                    (0x00000004U)
#define CSL_USB3_GBL_GDBGLTSSM_TXSWING_SHIFT                                   (0x00000002U)
#define CSL_USB3_GBL_GDBGLTSSM_TXSWING_MAX                                     (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_LTDBCLKSTATE_MASK                               (0x00000038U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBCLKSTATE_SHIFT                              (0x00000003U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBCLKSTATE_MAX                                (0x00000007U)

#define CSL_USB3_GBL_GDBGLTSSM_TXDEEMPHASIS_MASK                               (0x000000C0U)
#define CSL_USB3_GBL_GDBGLTSSM_TXDEEMPHASIS_SHIFT                              (0x00000006U)
#define CSL_USB3_GBL_GDBGLTSSM_TXDEEMPHASIS_MAX                                (0x00000003U)

#define CSL_USB3_GBL_GDBGLTSSM_RXEQTRAIN_MASK                                  (0x00000100U)
#define CSL_USB3_GBL_GDBGLTSSM_RXEQTRAIN_SHIFT                                 (0x00000008U)
#define CSL_USB3_GBL_GDBGLTSSM_RXEQTRAIN_MAX                                   (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_POWERDOWN_MASK                                  (0x00000600U)
#define CSL_USB3_GBL_GDBGLTSSM_POWERDOWN_SHIFT                                 (0x00000009U)
#define CSL_USB3_GBL_GDBGLTSSM_POWERDOWN_MAX                                   (0x00000003U)

#define CSL_USB3_GBL_GDBGLTSSM_LTDBPHYCMDSTATE_MASK                            (0x00003800U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBPHYCMDSTATE_SHIFT                           (0x0000000BU)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBPHYCMDSTATE_MAX                             (0x00000007U)

#define CSL_USB3_GBL_GDBGLTSSM_TXDETRXLOOPBACK_MASK                            (0x00004000U)
#define CSL_USB3_GBL_GDBGLTSSM_TXDETRXLOOPBACK_SHIFT                           (0x0000000EU)
#define CSL_USB3_GBL_GDBGLTSSM_TXDETRXLOOPBACK_MAX                             (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_RXPOLARITY_MASK                                 (0x00008000U)
#define CSL_USB3_GBL_GDBGLTSSM_RXPOLARITY_SHIFT                                (0x0000000FU)
#define CSL_USB3_GBL_GDBGLTSSM_RXPOLARITY_MAX                                  (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_TXELECLDLE_MASK                                 (0x00010000U)
#define CSL_USB3_GBL_GDBGLTSSM_TXELECLDLE_SHIFT                                (0x00000010U)
#define CSL_USB3_GBL_GDBGLTSSM_TXELECLDLE_MAX                                  (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_ELASTICBUFFERMODE_MASK                          (0x00020000U)
#define CSL_USB3_GBL_GDBGLTSSM_ELASTICBUFFERMODE_SHIFT                         (0x00000011U)
#define CSL_USB3_GBL_GDBGLTSSM_ELASTICBUFFERMODE_MAX                           (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_LTDBSUBSTATE_MASK                               (0x003C0000U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBSUBSTATE_SHIFT                              (0x00000012U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBSUBSTATE_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GDBGLTSSM_LTDBLINKSTATE_MASK                              (0x03C00000U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBLINKSTATE_SHIFT                             (0x00000016U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBLINKSTATE_MAX                               (0x0000000FU)

#define CSL_USB3_GBL_GDBGLTSSM_LTDBTIMEOUT_MASK                                (0x04000000U)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBTIMEOUT_SHIFT                               (0x0000001AU)
#define CSL_USB3_GBL_GDBGLTSSM_LTDBTIMEOUT_MAX                                 (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_PRTDIRECTION_MASK                               (0x08000000U)
#define CSL_USB3_GBL_GDBGLTSSM_PRTDIRECTION_SHIFT                              (0x0000001BU)
#define CSL_USB3_GBL_GDBGLTSSM_PRTDIRECTION_MAX                                (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_MASK                        (0x10000000U)
#define CSL_USB3_GBL_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_SHIFT                       (0x0000001CU)
#define CSL_USB3_GBL_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_MAX                         (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_X3_XS_SWAPPING_MASK                             (0x20000000U)
#define CSL_USB3_GBL_GDBGLTSSM_X3_XS_SWAPPING_SHIFT                            (0x0000001DU)
#define CSL_USB3_GBL_GDBGLTSSM_X3_XS_SWAPPING_MAX                              (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_RXELECIDLE_MASK                                 (0x40000000U)
#define CSL_USB3_GBL_GDBGLTSSM_RXELECIDLE_SHIFT                                (0x0000001EU)
#define CSL_USB3_GBL_GDBGLTSSM_RXELECIDLE_MAX                                  (0x00000001U)

#define CSL_USB3_GBL_GDBGLTSSM_RESERVED_31_31_MASK                             (0x80000000U)
#define CSL_USB3_GBL_GDBGLTSSM_RESERVED_31_31_SHIFT                            (0x0000001FU)
#define CSL_USB3_GBL_GDBGLTSSM_RESERVED_31_31_MAX                              (0x00000001U)

/* GDBGLNMCC */

#define CSL_USB3_GBL_GDBGLNMCC_LNMCC_BERC_MASK                                 (0x000001FFU)
#define CSL_USB3_GBL_GDBGLNMCC_LNMCC_BERC_SHIFT                                (0x00000000U)
#define CSL_USB3_GBL_GDBGLNMCC_LNMCC_BERC_MAX                                  (0x000001FFU)

#define CSL_USB3_GBL_GDBGLNMCC_RESERVED_31_9_MASK                              (0xFFFFFE00U)
#define CSL_USB3_GBL_GDBGLNMCC_RESERVED_31_9_SHIFT                             (0x00000009U)
#define CSL_USB3_GBL_GDBGLNMCC_RESERVED_31_9_MAX                               (0x007FFFFFU)

/* GDBGBMU */

#define CSL_USB3_GBL_GDBGBMU_BMU_CCU_MASK                                      (0x0000000FU)
#define CSL_USB3_GBL_GDBGBMU_BMU_CCU_SHIFT                                     (0x00000000U)
#define CSL_USB3_GBL_GDBGBMU_BMU_CCU_MAX                                       (0x0000000FU)

#define CSL_USB3_GBL_GDBGBMU_BMU_DCU_MASK                                      (0x000000F0U)
#define CSL_USB3_GBL_GDBGBMU_BMU_DCU_SHIFT                                     (0x00000004U)
#define CSL_USB3_GBL_GDBGBMU_BMU_DCU_MAX                                       (0x0000000FU)

#define CSL_USB3_GBL_GDBGBMU_BMU_BCU_MASK                                      (0xFFFFFF00U)
#define CSL_USB3_GBL_GDBGBMU_BMU_BCU_SHIFT                                     (0x00000008U)
#define CSL_USB3_GBL_GDBGBMU_BMU_BCU_MAX                                       (0x00FFFFFFU)

/* GDBGLSPMUX_HST */

#define CSL_USB3_GBL_GDBGLSPMUX_HST_HOSTSELECT_MASK                            (0x00003FFFU)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_HOSTSELECT_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_HOSTSELECT_MAX                             (0x00003FFFU)

#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_15_14_MASK                        (0x0000C000U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_15_14_SHIFT                       (0x0000000EU)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_15_14_MAX                         (0x00000003U)

#define CSL_USB3_GBL_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_MASK                  (0x00FF0000U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_SHIFT                 (0x00000010U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_MAX                   (0x000000FFU)

#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_31_24_MASK                        (0xFF000000U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_31_24_SHIFT                       (0x00000018U)
#define CSL_USB3_GBL_GDBGLSPMUX_HST_RESERVED_31_24_MAX                         (0x000000FFU)

/* GDBGLSP */

#define CSL_USB3_GBL_GDBGLSP_LSPDEBUG_MASK                                     (0xFFFFFFFFU)
#define CSL_USB3_GBL_GDBGLSP_LSPDEBUG_SHIFT                                    (0x00000000U)
#define CSL_USB3_GBL_GDBGLSP_LSPDEBUG_MAX                                      (0xFFFFFFFFU)

/* GDBGEPINFO0 */

#define CSL_USB3_GBL_GDBGEPINFO0_EPDEBUG_MASK                                  (0xFFFFFFFFU)
#define CSL_USB3_GBL_GDBGEPINFO0_EPDEBUG_SHIFT                                 (0x00000000U)
#define CSL_USB3_GBL_GDBGEPINFO0_EPDEBUG_MAX                                   (0xFFFFFFFFU)

/* GDBGEPINFO1 */

#define CSL_USB3_GBL_GDBGEPINFO1_EPDEBUG_MASK                                  (0xFFFFFFFFU)
#define CSL_USB3_GBL_GDBGEPINFO1_EPDEBUG_SHIFT                                 (0x00000000U)
#define CSL_USB3_GBL_GDBGEPINFO1_EPDEBUG_MAX                                   (0xFFFFFFFFU)

/* GPRTBIMAP_HSLO */

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM1_MASK                                (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM1_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM1_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM2_MASK                                (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM2_SHIFT                               (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM2_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM3_MASK                                (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM3_SHIFT                               (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM3_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM4_MASK                                (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM4_SHIFT                               (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM4_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM5_MASK                                (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM5_SHIFT                               (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM5_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM6_MASK                                (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM6_SHIFT                               (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM6_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM7_MASK                                (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM7_SHIFT                               (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM7_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM8_MASK                                (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM8_SHIFT                               (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAP_HSLO_BINUM8_MAX                                 (0x0000000FU)

/* GPRTBIMAP_HSHI */

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM9_MASK                                (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM9_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM9_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM10_MASK                               (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM10_SHIFT                              (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM10_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM11_MASK                               (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM11_SHIFT                              (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM11_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM12_MASK                               (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM12_SHIFT                              (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM12_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM13_MASK                               (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM13_SHIFT                              (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM13_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM14_MASK                               (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM14_SHIFT                              (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM14_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM15_MASK                               (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM15_SHIFT                              (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_BINUM15_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_HSHI_RESERVED_31_28_MASK                        (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_RESERVED_31_28_SHIFT                       (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAP_HSHI_RESERVED_31_28_MAX                         (0x0000000FU)

/* GPRTBIMAP_FSLO */

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM1_MASK                                (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM1_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM1_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM2_MASK                                (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM2_SHIFT                               (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM2_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM3_MASK                                (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM3_SHIFT                               (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM3_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM4_MASK                                (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM4_SHIFT                               (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM4_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM5_MASK                                (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM5_SHIFT                               (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM5_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM6_MASK                                (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM6_SHIFT                               (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM6_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM7_MASK                                (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM7_SHIFT                               (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM7_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM8_MASK                                (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM8_SHIFT                               (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAP_FSLO_BINUM8_MAX                                 (0x0000000FU)

/* GPRTBIMAP_FSHI */

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM9_MASK                                (0x0000000FU)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM9_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM9_MAX                                 (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM10_MASK                               (0x000000F0U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM10_SHIFT                              (0x00000004U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM10_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM11_MASK                               (0x00000F00U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM11_SHIFT                              (0x00000008U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM11_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM12_MASK                               (0x0000F000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM12_SHIFT                              (0x0000000CU)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM12_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM13_MASK                               (0x000F0000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM13_SHIFT                              (0x00000010U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM13_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM14_MASK                               (0x00F00000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM14_SHIFT                              (0x00000014U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM14_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM15_MASK                               (0x0F000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM15_SHIFT                              (0x00000018U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_BINUM15_MAX                                (0x0000000FU)

#define CSL_USB3_GBL_GPRTBIMAP_FSHI_RESERVED_31_28_MASK                        (0xF0000000U)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_RESERVED_31_28_SHIFT                       (0x0000001CU)
#define CSL_USB3_GBL_GPRTBIMAP_FSHI_RESERVED_31_28_MAX                         (0x0000000FU)

/* RESERVED_94 */

#define CSL_USB3_GBL_RESERVED_94_RESERVED_31_0_MASK                            (0xFFFFFFFFU)
#define CSL_USB3_GBL_RESERVED_94_RESERVED_31_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_RESERVED_94_RESERVED_31_0_MAX                             (0xFFFFFFFFU)

/* RESERVED_98 */

#define CSL_USB3_GBL_RESERVED_98_RESERVED_31_0_MASK                            (0xFFFFFFFFU)
#define CSL_USB3_GBL_RESERVED_98_RESERVED_31_0_SHIFT                           (0x00000000U)
#define CSL_USB3_GBL_RESERVED_98_RESERVED_31_0_MAX                             (0xFFFFFFFFU)

/* GUCTL2 */

#define CSL_USB3_GBL_GUCTL2_TXPINGDURATION_MASK                                (0x0000001FU)
#define CSL_USB3_GBL_GUCTL2_TXPINGDURATION_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GUCTL2_TXPINGDURATION_MAX                                 (0x0000001FU)

#define CSL_USB3_GBL_GUCTL2_RXPINGDURATION_MASK                                (0x000007E0U)
#define CSL_USB3_GBL_GUCTL2_RXPINGDURATION_SHIFT                               (0x00000005U)
#define CSL_USB3_GBL_GUCTL2_RXPINGDURATION_MAX                                 (0x0000003FU)

#define CSL_USB3_GBL_GUCTL2_DISABLECFC_MASK                                    (0x00000800U)
#define CSL_USB3_GBL_GUCTL2_DISABLECFC_SHIFT                                   (0x0000000BU)
#define CSL_USB3_GBL_GUCTL2_DISABLECFC_MAX                                     (0x00000001U)

#define CSL_USB3_GBL_GUCTL2_ENABLEEPCACHEEVICT_MASK                            (0x00001000U)
#define CSL_USB3_GBL_GUCTL2_ENABLEEPCACHEEVICT_SHIFT                           (0x0000000CU)
#define CSL_USB3_GBL_GUCTL2_ENABLEEPCACHEEVICT_MAX                             (0x00000001U)

#define CSL_USB3_GBL_GUCTL2_RESERVED_31_13_MASK                                (0xFFFFE000U)
#define CSL_USB3_GBL_GUCTL2_RESERVED_31_13_SHIFT                               (0x0000000DU)
#define CSL_USB3_GBL_GUCTL2_RESERVED_31_13_MAX                                 (0x0007FFFFU)

/* GHWPARAMS8 */

#define CSL_USB3_GBL_GHWPARAMS8_GHWPARAMS8_32_0_MASK                           (0xFFFFFFFFU)
#define CSL_USB3_GBL_GHWPARAMS8_GHWPARAMS8_32_0_SHIFT                          (0x00000000U)
#define CSL_USB3_GBL_GHWPARAMS8_GHWPARAMS8_32_0_MAX                            (0xFFFFFFFFU)

/* GTXFIFOPRIDEV */

#define CSL_USB3_GBL_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK                          (0x0000FFFFU)
#define CSL_USB3_GBL_GTXFIFOPRIDEV_GTXFIFOPRIDEV_SHIFT                         (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MAX                           (0x0000FFFFU)

#define CSL_USB3_GBL_GTXFIFOPRIDEV_RESERVED_MASK                               (0xFFFF0000U)
#define CSL_USB3_GBL_GTXFIFOPRIDEV_RESERVED_SHIFT                              (0x00000010U)
#define CSL_USB3_GBL_GTXFIFOPRIDEV_RESERVED_MAX                                (0x0000FFFFU)

/* GTXFIFOPRIHST */

#define CSL_USB3_GBL_GTXFIFOPRIHST_GTXFIFOPRIHST_MASK                          (0x00000007U)
#define CSL_USB3_GBL_GTXFIFOPRIHST_GTXFIFOPRIHST_SHIFT                         (0x00000000U)
#define CSL_USB3_GBL_GTXFIFOPRIHST_GTXFIFOPRIHST_MAX                           (0x00000007U)

#define CSL_USB3_GBL_GTXFIFOPRIHST_RESERVED_31_16_MASK                         (0xFFFFFFF8U)
#define CSL_USB3_GBL_GTXFIFOPRIHST_RESERVED_31_16_SHIFT                        (0x00000003U)
#define CSL_USB3_GBL_GTXFIFOPRIHST_RESERVED_31_16_MAX                          (0x1FFFFFFFU)

/* GRXFIFOPRIHST */

#define CSL_USB3_GBL_GRXFIFOPRIHST_GRXFIFOPRIHST_MASK                          (0x00000007U)
#define CSL_USB3_GBL_GRXFIFOPRIHST_GRXFIFOPRIHST_SHIFT                         (0x00000000U)
#define CSL_USB3_GBL_GRXFIFOPRIHST_GRXFIFOPRIHST_MAX                           (0x00000007U)

#define CSL_USB3_GBL_GRXFIFOPRIHST_RESERVED_31_16_MASK                         (0xFFFFFFF8U)
#define CSL_USB3_GBL_GRXFIFOPRIHST_RESERVED_31_16_SHIFT                        (0x00000003U)
#define CSL_USB3_GBL_GRXFIFOPRIHST_RESERVED_31_16_MAX                          (0x1FFFFFFFU)

/* GDMAHLRATIO */

#define CSL_USB3_GBL_GDMAHLRATIO_HSTTXFIFO_MASK                                (0x0000001FU)
#define CSL_USB3_GBL_GDMAHLRATIO_HSTTXFIFO_SHIFT                               (0x00000000U)
#define CSL_USB3_GBL_GDMAHLRATIO_HSTTXFIFO_MAX                                 (0x0000001FU)

#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_7_5_MASK                             (0x000000E0U)
#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_7_5_SHIFT                            (0x00000005U)
#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_7_5_MAX                              (0x00000007U)

#define CSL_USB3_GBL_GDMAHLRATIO_HSTRXFIFO_MASK                                (0x00001F00U)
#define CSL_USB3_GBL_GDMAHLRATIO_HSTRXFIFO_SHIFT                               (0x00000008U)
#define CSL_USB3_GBL_GDMAHLRATIO_HSTRXFIFO_MAX                                 (0x0000001FU)

#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_31_13_MASK                           (0xFFFFE000U)
#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_31_13_SHIFT                          (0x0000000DU)
#define CSL_USB3_GBL_GDMAHLRATIO_RESERVED_31_13_MAX                            (0x0007FFFFU)

/* GFLADJ */

#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_MASK                                  (0x0000003FU)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_SHIFT                                 (0x00000000U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_MAX                                   (0x0000003FU)

#define CSL_USB3_GBL_GFLADJ_RESERVED_6_MASK                                    (0x00000040U)
#define CSL_USB3_GBL_GFLADJ_RESERVED_6_SHIFT                                   (0x00000006U)
#define CSL_USB3_GBL_GFLADJ_RESERVED_6_MAX                                     (0x00000001U)

#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MASK                        (0x00000080U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_SHIFT                       (0x00000007U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MAX                         (0x00000001U)

#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK                           (0x003FFF00U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_FLADJ_SHIFT                          (0x00000008U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_FLADJ_MAX                            (0x00003FFFU)

#define CSL_USB3_GBL_GFLADJ_RESERVED_22_MASK                                   (0x00400000U)
#define CSL_USB3_GBL_GFLADJ_RESERVED_22_SHIFT                                  (0x00000016U)
#define CSL_USB3_GBL_GFLADJ_RESERVED_22_MAX                                    (0x00000001U)

#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MASK                         (0x00800000U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_LPM_SEL_SHIFT                        (0x00000017U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MAX                          (0x00000001U)

#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MASK                     (0x7F000000U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_SHIFT                    (0x00000018U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MAX                      (0x0000007FU)

#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MASK                 (0x80000000U)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_SHIFT                (0x0000001FU)
#define CSL_USB3_GBL_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MAX                  (0x00000001U)

/**************************************************************************
* Hardware Region  : USB3 Device Register Block
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DEPCMDPAR2;                /* DEPCMDPAR2 */
    volatile uint32_t DEPCMDPAR1;                /* DEPCMDPAR1 */
    volatile uint32_t DEPCMDPAR0;                /* DEPCMDPAR0 */
    volatile uint32_t DEPCMD;                    /* DEPCMD */
} CSL_usb3_devRegs_DEPCMDPAR2_REGS;


typedef struct {
    volatile uint32_t DEV_IMOD;                  /* Device Interrupt Moderation Register (DEV_IMOD)

This register controls the Interrupt Moderation feature that allows the device software to throttle the interrupt rate.

Key Functions:
 - Interrupt Moderation is enabled only when the IMOD Interval is programmed to a non-zero value.
 - Interrupt is asserted whenever the IMOD (down) counter is 0, EVNT_HANDLER_BUSY is 0, and there are pending events (that is, event count is non-zero)
 - GEVNTCOUNT[EVNT_HANDLER_BUSY] is set by hardware when interrupt is asserted, and cleared by software when interrupt processing is completed.
 - The Interrupt line is de-asserted after the first write to the event count.
 - IMOD counter is loaded with IMOD interval whenever the Interrupt line is de-asserted. */
} CSL_usb3_devRegs_DEV_IMOD_REGS;


typedef struct {
    volatile uint32_t DCFG;                      /* DCFG */
    volatile uint32_t DCTL;                      /* DCTL */
    volatile uint32_t DEVTEN;                    /* DEVTEN */
    volatile uint32_t DSTS;                      /* DSTS */
    volatile uint32_t DGCMDPAR;                  /* DGCMDPAR */
    volatile uint32_t DGCMD;                     /* DGCMD */
    volatile uint8_t  Resv_32[8];
    volatile uint32_t DALEPENA;                  /* DALEPENA */
    volatile uint8_t  Resv_256[220];
    CSL_usb3_devRegs_DEPCMDPAR2_REGS DEPCMDPAR2_REGS[32];
    CSL_usb3_devRegs_DEV_IMOD_REGS DEV_IMOD_REGS[16];
} CSL_usb3_devRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_DEV_DCFG                                                      (0x0001C700U)
#define CSL_USB3_DEV_DCTL                                                      (0x0001C704U)
#define CSL_USB3_DEV_DEVTEN                                                    (0x0001C708U)
#define CSL_USB3_DEV_DSTS                                                      (0x0001C70CU)
#define CSL_USB3_DEV_DGCMDPAR                                                  (0x0001C710U)
#define CSL_USB3_DEV_DGCMD                                                     (0x0001C714U)
#define CSL_USB3_DEV_DALEPENA                                                  (0x0001C720U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR2(DEPCMDPAR2_REGS)               (0x0001C800U+((DEPCMDPAR2_REGS)*0x10U))
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR1(DEPCMDPAR2_REGS)               (0x0001C804U+((DEPCMDPAR2_REGS)*0x10U))
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR0(DEPCMDPAR2_REGS)               (0x0001C808U+((DEPCMDPAR2_REGS)*0x10U))
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD(DEPCMDPAR2_REGS)                   (0x0001C80CU+((DEPCMDPAR2_REGS)*0x10U))
#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD(DEV_IMOD_REGS)                     (0x0001CA00U+((DEV_IMOD_REGS)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DEPCMDPAR2 */

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR2_PARAMETER_MASK                 (0xFFFFFFFFU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR2_PARAMETER_SHIFT                (0x00000000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR2_PARAMETER_MAX                  (0xFFFFFFFFU)

/* DEPCMDPAR1 */

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR1_PARAMETER_MASK                 (0xFFFFFFFFU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR1_PARAMETER_SHIFT                (0x00000000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR1_PARAMETER_MAX                  (0xFFFFFFFFU)

/* DEPCMDPAR0 */

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR0_PARAMETER_MASK                 (0xFFFFFFFFU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR0_PARAMETER_SHIFT                (0x00000000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMDPAR0_PARAMETER_MAX                  (0xFFFFFFFFU)

/* DEPCMD */

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDTYP_MASK                        (0x0000000FU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDTYP_SHIFT                       (0x00000000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDTYP_MAX                         (0x0000000FU)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_7_4_MASK                  (0x000000F0U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_7_4_SHIFT                 (0x00000004U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_7_4_MAX                   (0x0000000FU)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDIOC_MASK                        (0x00000100U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDIOC_SHIFT                       (0x00000008U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDIOC_MAX                         (0x00000001U)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_9_MASK                    (0x00000200U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_9_SHIFT                   (0x00000009U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_RESERVED_9_MAX                     (0x00000001U)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDACT_MASK                        (0x00000400U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDACT_SHIFT                       (0x0000000AU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDACT_MAX                         (0x00000001U)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_HIPRI_FORCERM_MASK                 (0x00000800U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_HIPRI_FORCERM_SHIFT                (0x0000000BU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_HIPRI_FORCERM_MAX                  (0x00000001U)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDSTATUS_MASK                     (0x0000F000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDSTATUS_SHIFT                    (0x0000000CU)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_CMDSTATUS_MAX                      (0x0000000FU)

#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_COMMANDPARAM_MASK                  (0xFFFF0000U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_COMMANDPARAM_SHIFT                 (0x00000010U)
#define CSL_USB3_DEV_DEPCMDPAR2_REGS_DEPCMD_COMMANDPARAM_MAX                   (0x0000FFFFU)

/* DEV_IMOD */

#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODI_MASK                  (0x0000FFFFU)
#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODI_SHIFT                 (0x00000000U)
#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODI_MAX                   (0x0000FFFFU)

#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODC_MASK                  (0xFFFF0000U)
#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODC_SHIFT                 (0x00000010U)
#define CSL_USB3_DEV_DEV_IMOD_REGS_DEV_IMOD_DEVICE_IMODC_MAX                   (0x0000FFFFU)

/* DCFG */

#define CSL_USB3_DEV_DCFG_DEVSPD_MASK                                          (0x00000007U)
#define CSL_USB3_DEV_DCFG_DEVSPD_SHIFT                                         (0x00000000U)
#define CSL_USB3_DEV_DCFG_DEVSPD_MAX                                           (0x00000007U)

#define CSL_USB3_DEV_DCFG_DEVADDR_MASK                                         (0x000003F8U)
#define CSL_USB3_DEV_DCFG_DEVADDR_SHIFT                                        (0x00000003U)
#define CSL_USB3_DEV_DCFG_DEVADDR_MAX                                          (0x0000007FU)

#define CSL_USB3_DEV_DCFG_RESERVED_10_11_MASK                                  (0x00000C00U)
#define CSL_USB3_DEV_DCFG_RESERVED_10_11_SHIFT                                 (0x0000000AU)
#define CSL_USB3_DEV_DCFG_RESERVED_10_11_MAX                                   (0x00000003U)

#define CSL_USB3_DEV_DCFG_INTRNUM_MASK                                         (0x0001F000U)
#define CSL_USB3_DEV_DCFG_INTRNUM_SHIFT                                        (0x0000000CU)
#define CSL_USB3_DEV_DCFG_INTRNUM_MAX                                          (0x0000001FU)

#define CSL_USB3_DEV_DCFG_NUMP_MASK                                            (0x003E0000U)
#define CSL_USB3_DEV_DCFG_NUMP_SHIFT                                           (0x00000011U)
#define CSL_USB3_DEV_DCFG_NUMP_MAX                                             (0x0000001FU)

#define CSL_USB3_DEV_DCFG_LPMCAP_MASK                                          (0x00400000U)
#define CSL_USB3_DEV_DCFG_LPMCAP_SHIFT                                         (0x00000016U)
#define CSL_USB3_DEV_DCFG_LPMCAP_MAX                                           (0x00000001U)

#define CSL_USB3_DEV_DCFG_IGNSTRMPP_MASK                                       (0x00800000U)
#define CSL_USB3_DEV_DCFG_IGNSTRMPP_SHIFT                                      (0x00000017U)
#define CSL_USB3_DEV_DCFG_IGNSTRMPP_MAX                                        (0x00000001U)

#define CSL_USB3_DEV_DCFG_RESERVED_24_MASK                                     (0x01000000U)
#define CSL_USB3_DEV_DCFG_RESERVED_24_SHIFT                                    (0x00000018U)
#define CSL_USB3_DEV_DCFG_RESERVED_24_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DCFG_RESERVED_31_25_MASK                                  (0xFE000000U)
#define CSL_USB3_DEV_DCFG_RESERVED_31_25_SHIFT                                 (0x00000019U)
#define CSL_USB3_DEV_DCFG_RESERVED_31_25_MAX                                   (0x0000007FU)

/* DCTL */

#define CSL_USB3_DEV_DCTL_RESERVED_0_MASK                                      (0x00000001U)
#define CSL_USB3_DEV_DCTL_RESERVED_0_SHIFT                                     (0x00000000U)
#define CSL_USB3_DEV_DCTL_RESERVED_0_MAX                                       (0x00000001U)

#define CSL_USB3_DEV_DCTL_TSTCTL_MASK                                          (0x0000001EU)
#define CSL_USB3_DEV_DCTL_TSTCTL_SHIFT                                         (0x00000001U)
#define CSL_USB3_DEV_DCTL_TSTCTL_MAX                                           (0x0000000FU)

#define CSL_USB3_DEV_DCTL_ULSTCHNGREQ_MASK                                     (0x000001E0U)
#define CSL_USB3_DEV_DCTL_ULSTCHNGREQ_SHIFT                                    (0x00000005U)
#define CSL_USB3_DEV_DCTL_ULSTCHNGREQ_MAX                                      (0x0000000FU)

#define CSL_USB3_DEV_DCTL_ACCEPTU1ENA_MASK                                     (0x00000200U)
#define CSL_USB3_DEV_DCTL_ACCEPTU1ENA_SHIFT                                    (0x00000009U)
#define CSL_USB3_DEV_DCTL_ACCEPTU1ENA_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DCTL_INITU1ENA_MASK                                       (0x00000400U)
#define CSL_USB3_DEV_DCTL_INITU1ENA_SHIFT                                      (0x0000000AU)
#define CSL_USB3_DEV_DCTL_INITU1ENA_MAX                                        (0x00000001U)

#define CSL_USB3_DEV_DCTL_ACCEPTU2ENA_MASK                                     (0x00000800U)
#define CSL_USB3_DEV_DCTL_ACCEPTU2ENA_SHIFT                                    (0x0000000BU)
#define CSL_USB3_DEV_DCTL_ACCEPTU2ENA_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DCTL_INITU2ENA_MASK                                       (0x00001000U)
#define CSL_USB3_DEV_DCTL_INITU2ENA_SHIFT                                      (0x0000000CU)
#define CSL_USB3_DEV_DCTL_INITU2ENA_MAX                                        (0x00000001U)

#define CSL_USB3_DEV_DCTL_RESERVED_15_13_MASK                                  (0x0000E000U)
#define CSL_USB3_DEV_DCTL_RESERVED_15_13_SHIFT                                 (0x0000000DU)
#define CSL_USB3_DEV_DCTL_RESERVED_15_13_MAX                                   (0x00000007U)

#define CSL_USB3_DEV_DCTL_CSS_MASK                                             (0x00010000U)
#define CSL_USB3_DEV_DCTL_CSS_SHIFT                                            (0x00000010U)
#define CSL_USB3_DEV_DCTL_CSS_MAX                                              (0x00000001U)

#define CSL_USB3_DEV_DCTL_CRS_MASK                                             (0x00020000U)
#define CSL_USB3_DEV_DCTL_CRS_SHIFT                                            (0x00000011U)
#define CSL_USB3_DEV_DCTL_CRS_MAX                                              (0x00000001U)

#define CSL_USB3_DEV_DCTL_RESERVED_19_18_MASK                                  (0x000C0000U)
#define CSL_USB3_DEV_DCTL_RESERVED_19_18_SHIFT                                 (0x00000012U)
#define CSL_USB3_DEV_DCTL_RESERVED_19_18_MAX                                   (0x00000003U)

#define CSL_USB3_DEV_DCTL_LPM_NYET_THRES_MASK                                  (0x00F00000U)
#define CSL_USB3_DEV_DCTL_LPM_NYET_THRES_SHIFT                                 (0x00000014U)
#define CSL_USB3_DEV_DCTL_LPM_NYET_THRES_MAX                                   (0x0000000FU)

#define CSL_USB3_DEV_DCTL_HIRDTHRES_MASK                                       (0x1F000000U)
#define CSL_USB3_DEV_DCTL_HIRDTHRES_SHIFT                                      (0x00000018U)
#define CSL_USB3_DEV_DCTL_HIRDTHRES_MAX                                        (0x0000001FU)

#define CSL_USB3_DEV_DCTL_RESERVED_29_MASK                                     (0x20000000U)
#define CSL_USB3_DEV_DCTL_RESERVED_29_SHIFT                                    (0x0000001DU)
#define CSL_USB3_DEV_DCTL_RESERVED_29_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DCTL_CSFTRST_MASK                                         (0x40000000U)
#define CSL_USB3_DEV_DCTL_CSFTRST_SHIFT                                        (0x0000001EU)
#define CSL_USB3_DEV_DCTL_CSFTRST_MAX                                          (0x00000001U)

#define CSL_USB3_DEV_DCTL_RUN_STOP_MASK                                        (0x80000000U)
#define CSL_USB3_DEV_DCTL_RUN_STOP_SHIFT                                       (0x0000001FU)
#define CSL_USB3_DEV_DCTL_RUN_STOP_MAX                                         (0x00000001U)

/* DEVTEN */

#define CSL_USB3_DEV_DEVTEN_DISSCONNEVTEN_MASK                                 (0x00000001U)
#define CSL_USB3_DEV_DEVTEN_DISSCONNEVTEN_SHIFT                                (0x00000000U)
#define CSL_USB3_DEV_DEVTEN_DISSCONNEVTEN_MAX                                  (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_USBRSTEVTEN_MASK                                   (0x00000002U)
#define CSL_USB3_DEV_DEVTEN_USBRSTEVTEN_SHIFT                                  (0x00000001U)
#define CSL_USB3_DEV_DEVTEN_USBRSTEVTEN_MAX                                    (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_CONNECTDONEEVTEN_MASK                              (0x00000004U)
#define CSL_USB3_DEV_DEVTEN_CONNECTDONEEVTEN_SHIFT                             (0x00000002U)
#define CSL_USB3_DEV_DEVTEN_CONNECTDONEEVTEN_MAX                               (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_ULSTCNGEN_MASK                                     (0x00000008U)
#define CSL_USB3_DEV_DEVTEN_ULSTCNGEN_SHIFT                                    (0x00000003U)
#define CSL_USB3_DEV_DEVTEN_ULSTCNGEN_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_WKUPEVTEN_MASK                                     (0x00000010U)
#define CSL_USB3_DEV_DEVTEN_WKUPEVTEN_SHIFT                                    (0x00000004U)
#define CSL_USB3_DEV_DEVTEN_WKUPEVTEN_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_HIBERNATIONREQEVTEN_MASK                           (0x00000020U)
#define CSL_USB3_DEV_DEVTEN_HIBERNATIONREQEVTEN_SHIFT                          (0x00000005U)
#define CSL_USB3_DEV_DEVTEN_HIBERNATIONREQEVTEN_MAX                            (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_U3L2L1SUSPEN_MASK                                  (0x00000040U)
#define CSL_USB3_DEV_DEVTEN_U3L2L1SUSPEN_SHIFT                                 (0x00000006U)
#define CSL_USB3_DEV_DEVTEN_U3L2L1SUSPEN_MAX                                   (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_SOFTEVTEN_MASK                                     (0x00000080U)
#define CSL_USB3_DEV_DEVTEN_SOFTEVTEN_SHIFT                                    (0x00000007U)
#define CSL_USB3_DEV_DEVTEN_SOFTEVTEN_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_L1SUSPEN_MASK                                      (0x00000100U)
#define CSL_USB3_DEV_DEVTEN_L1SUSPEN_SHIFT                                     (0x00000008U)
#define CSL_USB3_DEV_DEVTEN_L1SUSPEN_MAX                                       (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_ERRTICERREVTEN_MASK                                (0x00000200U)
#define CSL_USB3_DEV_DEVTEN_ERRTICERREVTEN_SHIFT                               (0x00000009U)
#define CSL_USB3_DEV_DEVTEN_ERRTICERREVTEN_MAX                                 (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_RESERVED_10_MASK                                   (0x00000400U)
#define CSL_USB3_DEV_DEVTEN_RESERVED_10_SHIFT                                  (0x0000000AU)
#define CSL_USB3_DEV_DEVTEN_RESERVED_10_MAX                                    (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_RESERVED_11_MASK                                   (0x00000800U)
#define CSL_USB3_DEV_DEVTEN_RESERVED_11_SHIFT                                  (0x0000000BU)
#define CSL_USB3_DEV_DEVTEN_RESERVED_11_MAX                                    (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_VENDEVTSTRCVDEN_MASK                               (0x00001000U)
#define CSL_USB3_DEV_DEVTEN_VENDEVTSTRCVDEN_SHIFT                              (0x0000000CU)
#define CSL_USB3_DEV_DEVTEN_VENDEVTSTRCVDEN_MAX                                (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_L1WKUPEVTEN_MASK                                   (0x00004000U)
#define CSL_USB3_DEV_DEVTEN_L1WKUPEVTEN_SHIFT                                  (0x0000000EU)
#define CSL_USB3_DEV_DEVTEN_L1WKUPEVTEN_MAX                                    (0x00000001U)

#define CSL_USB3_DEV_DEVTEN_RESERVED_31_15_MASK                                (0xFFFF8000U)
#define CSL_USB3_DEV_DEVTEN_RESERVED_31_15_SHIFT                               (0x0000000FU)
#define CSL_USB3_DEV_DEVTEN_RESERVED_31_15_MAX                                 (0x0001FFFFU)

/* DSTS */

#define CSL_USB3_DEV_DSTS_CONNECTSPD_MASK                                      (0x00000007U)
#define CSL_USB3_DEV_DSTS_CONNECTSPD_SHIFT                                     (0x00000000U)
#define CSL_USB3_DEV_DSTS_CONNECTSPD_MAX                                       (0x00000007U)

#define CSL_USB3_DEV_DSTS_SOFFN_MASK                                           (0x0001FFF8U)
#define CSL_USB3_DEV_DSTS_SOFFN_SHIFT                                          (0x00000003U)
#define CSL_USB3_DEV_DSTS_SOFFN_MAX                                            (0x00003FFFU)

#define CSL_USB3_DEV_DSTS_RXFIFOEMPTY_MASK                                     (0x00020000U)
#define CSL_USB3_DEV_DSTS_RXFIFOEMPTY_SHIFT                                    (0x00000011U)
#define CSL_USB3_DEV_DSTS_RXFIFOEMPTY_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DSTS_USBLNKST_MASK                                        (0x003C0000U)
#define CSL_USB3_DEV_DSTS_USBLNKST_SHIFT                                       (0x00000012U)
#define CSL_USB3_DEV_DSTS_USBLNKST_MAX                                         (0x0000000FU)

#define CSL_USB3_DEV_DSTS_DEVCTRLHLT_MASK                                      (0x00400000U)
#define CSL_USB3_DEV_DSTS_DEVCTRLHLT_SHIFT                                     (0x00000016U)
#define CSL_USB3_DEV_DSTS_DEVCTRLHLT_MAX                                       (0x00000001U)

#define CSL_USB3_DEV_DSTS_COREIDLE_MASK                                        (0x00800000U)
#define CSL_USB3_DEV_DSTS_COREIDLE_SHIFT                                       (0x00000017U)
#define CSL_USB3_DEV_DSTS_COREIDLE_MAX                                         (0x00000001U)

#define CSL_USB3_DEV_DSTS_SSS_MASK                                             (0x01000000U)
#define CSL_USB3_DEV_DSTS_SSS_SHIFT                                            (0x00000018U)
#define CSL_USB3_DEV_DSTS_SSS_MAX                                              (0x00000001U)

#define CSL_USB3_DEV_DSTS_RSS_MASK                                             (0x02000000U)
#define CSL_USB3_DEV_DSTS_RSS_SHIFT                                            (0x00000019U)
#define CSL_USB3_DEV_DSTS_RSS_MAX                                              (0x00000001U)

#define CSL_USB3_DEV_DSTS_RESERVED_27_26_MASK                                  (0x0C000000U)
#define CSL_USB3_DEV_DSTS_RESERVED_27_26_SHIFT                                 (0x0000001AU)
#define CSL_USB3_DEV_DSTS_RESERVED_27_26_MAX                                   (0x00000003U)

#define CSL_USB3_DEV_DSTS_SRE_MASK                                             (0x10000000U)
#define CSL_USB3_DEV_DSTS_SRE_SHIFT                                            (0x0000001CU)
#define CSL_USB3_DEV_DSTS_SRE_MAX                                              (0x00000001U)

#define CSL_USB3_DEV_DSTS_DCNRD_MASK                                           (0x20000000U)
#define CSL_USB3_DEV_DSTS_DCNRD_SHIFT                                          (0x0000001DU)
#define CSL_USB3_DEV_DSTS_DCNRD_MAX                                            (0x00000001U)

#define CSL_USB3_DEV_DSTS_RESERVED_31_30_MASK                                  (0xC0000000U)
#define CSL_USB3_DEV_DSTS_RESERVED_31_30_SHIFT                                 (0x0000001EU)
#define CSL_USB3_DEV_DSTS_RESERVED_31_30_MAX                                   (0x00000003U)

/* DGCMDPAR */

#define CSL_USB3_DEV_DGCMDPAR_PARAMETER_MASK                                   (0xFFFFFFFFU)
#define CSL_USB3_DEV_DGCMDPAR_PARAMETER_SHIFT                                  (0x00000000U)
#define CSL_USB3_DEV_DGCMDPAR_PARAMETER_MAX                                    (0xFFFFFFFFU)

/* DGCMD */

#define CSL_USB3_DEV_DGCMD_CMDTYP_MASK                                         (0x000000FFU)
#define CSL_USB3_DEV_DGCMD_CMDTYP_SHIFT                                        (0x00000000U)
#define CSL_USB3_DEV_DGCMD_CMDTYP_MAX                                          (0x000000FFU)

#define CSL_USB3_DEV_DGCMD_CMDIOC_MASK                                         (0x00000100U)
#define CSL_USB3_DEV_DGCMD_CMDIOC_SHIFT                                        (0x00000008U)
#define CSL_USB3_DEV_DGCMD_CMDIOC_MAX                                          (0x00000001U)

#define CSL_USB3_DEV_DGCMD_RESERVED_9_MASK                                     (0x00000200U)
#define CSL_USB3_DEV_DGCMD_RESERVED_9_SHIFT                                    (0x00000009U)
#define CSL_USB3_DEV_DGCMD_RESERVED_9_MAX                                      (0x00000001U)

#define CSL_USB3_DEV_DGCMD_CMDACT_MASK                                         (0x00000400U)
#define CSL_USB3_DEV_DGCMD_CMDACT_SHIFT                                        (0x0000000AU)
#define CSL_USB3_DEV_DGCMD_CMDACT_MAX                                          (0x00000001U)

#define CSL_USB3_DEV_DGCMD_RESERVED_11_MASK                                    (0x00000800U)
#define CSL_USB3_DEV_DGCMD_RESERVED_11_SHIFT                                   (0x0000000BU)
#define CSL_USB3_DEV_DGCMD_RESERVED_11_MAX                                     (0x00000001U)

#define CSL_USB3_DEV_DGCMD_CMDSTATUS_MASK                                      (0x0000F000U)
#define CSL_USB3_DEV_DGCMD_CMDSTATUS_SHIFT                                     (0x0000000CU)
#define CSL_USB3_DEV_DGCMD_CMDSTATUS_MAX                                       (0x0000000FU)

#define CSL_USB3_DEV_DGCMD_RESERVED_31_16_MASK                                 (0xFFFF0000U)
#define CSL_USB3_DEV_DGCMD_RESERVED_31_16_SHIFT                                (0x00000010U)
#define CSL_USB3_DEV_DGCMD_RESERVED_31_16_MAX                                  (0x0000FFFFU)

/* DALEPENA */

#define CSL_USB3_DEV_DALEPENA_USBACTEP_MASK                                    (0xFFFFFFFFU)
#define CSL_USB3_DEV_DALEPENA_USBACTEP_SHIFT                                   (0x00000000U)
#define CSL_USB3_DEV_DALEPENA_USBACTEP_MAX                                     (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : USB3 OTG Register Block 0x0000cc00
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t OCFG;                      /* OCFG */
    volatile uint32_t OCTL;                      /* OCTL */
    volatile uint32_t OEVT;                      /* OEVT */
    volatile uint32_t OEVTEN;                    /* OEVTEN */
    volatile uint32_t OSTS;                      /* OSTS */
    volatile uint8_t  Resv_32[12];
    volatile uint32_t ADPCFG;                    /* ADPCFG */
    volatile uint32_t ADPCTL;                    /* ADPCTL */
    volatile uint32_t ADPEVT;                    /* ADPEVT */
    volatile uint32_t ADPEVTEN;                  /* ADPEVTEN */
} CSL_usb3_otgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_OTG_OCFG                                                      (0x0001CC00U)
#define CSL_USB3_OTG_OCTL                                                      (0x0001CC04U)
#define CSL_USB3_OTG_OEVT                                                      (0x0001CC08U)
#define CSL_USB3_OTG_OEVTEN                                                    (0x0001CC0CU)
#define CSL_USB3_OTG_OSTS                                                      (0x0001CC10U)
#define CSL_USB3_OTG_ADPCFG                                                    (0x0001CC20U)
#define CSL_USB3_OTG_ADPCTL                                                    (0x0001CC24U)
#define CSL_USB3_OTG_ADPEVT                                                    (0x0001CC28U)
#define CSL_USB3_OTG_ADPEVTEN                                                  (0x0001CC2CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* OCFG */

#define CSL_USB3_OTG_OCFG_SRPCAP_MASK                                          (0x00000001U)
#define CSL_USB3_OTG_OCFG_SRPCAP_SHIFT                                         (0x00000000U)
#define CSL_USB3_OTG_OCFG_SRPCAP_MAX                                           (0x00000001U)

#define CSL_USB3_OTG_OCFG_HNPCAP_MASK                                          (0x00000002U)
#define CSL_USB3_OTG_OCFG_HNPCAP_SHIFT                                         (0x00000001U)
#define CSL_USB3_OTG_OCFG_HNPCAP_MAX                                           (0x00000001U)

#define CSL_USB3_OTG_OCFG_OTGVERSION_MASK                                      (0x00000004U)
#define CSL_USB3_OTG_OCFG_OTGVERSION_SHIFT                                     (0x00000002U)
#define CSL_USB3_OTG_OCFG_OTGVERSION_MAX                                       (0x00000001U)

#define CSL_USB3_OTG_OCFG_OTGSFTRSTMSK_MASK                                    (0x00000008U)
#define CSL_USB3_OTG_OCFG_OTGSFTRSTMSK_SHIFT                                   (0x00000003U)
#define CSL_USB3_OTG_OCFG_OTGSFTRSTMSK_MAX                                     (0x00000001U)

#define CSL_USB3_OTG_OCFG_OTGHIBDISMASK_MASK                                   (0x00000010U)
#define CSL_USB3_OTG_OCFG_OTGHIBDISMASK_SHIFT                                  (0x00000004U)
#define CSL_USB3_OTG_OCFG_OTGHIBDISMASK_MAX                                    (0x00000001U)

#define CSL_USB3_OTG_OCFG_DISPRTPWRCUTOFF_MASK                                 (0x00000020U)
#define CSL_USB3_OTG_OCFG_DISPRTPWRCUTOFF_SHIFT                                (0x00000005U)
#define CSL_USB3_OTG_OCFG_DISPRTPWRCUTOFF_MAX                                  (0x00000001U)

#define CSL_USB3_OTG_OCFG_RESERVED_31_6_MASK                                   (0xFFFFFFC0U)
#define CSL_USB3_OTG_OCFG_RESERVED_31_6_SHIFT                                  (0x00000006U)
#define CSL_USB3_OTG_OCFG_RESERVED_31_6_MAX                                    (0x03FFFFFFU)

/* OCTL */

#define CSL_USB3_OTG_OCTL_HSTSETHNPEN_MASK                                     (0x00000001U)
#define CSL_USB3_OTG_OCTL_HSTSETHNPEN_SHIFT                                    (0x00000000U)
#define CSL_USB3_OTG_OCTL_HSTSETHNPEN_MAX                                      (0x00000001U)

#define CSL_USB3_OTG_OCTL_DEVSETHNPEN_MASK                                     (0x00000002U)
#define CSL_USB3_OTG_OCTL_DEVSETHNPEN_SHIFT                                    (0x00000001U)
#define CSL_USB3_OTG_OCTL_DEVSETHNPEN_MAX                                      (0x00000001U)

#define CSL_USB3_OTG_OCTL_TERMSELDLPULSE_MASK                                  (0x00000004U)
#define CSL_USB3_OTG_OCTL_TERMSELDLPULSE_SHIFT                                 (0x00000002U)
#define CSL_USB3_OTG_OCTL_TERMSELDLPULSE_MAX                                   (0x00000001U)

#define CSL_USB3_OTG_OCTL_SESREQ_MASK                                          (0x00000008U)
#define CSL_USB3_OTG_OCTL_SESREQ_SHIFT                                         (0x00000003U)
#define CSL_USB3_OTG_OCTL_SESREQ_MAX                                           (0x00000001U)

#define CSL_USB3_OTG_OCTL_HNPREQ_MASK                                          (0x00000010U)
#define CSL_USB3_OTG_OCTL_HNPREQ_SHIFT                                         (0x00000004U)
#define CSL_USB3_OTG_OCTL_HNPREQ_MAX                                           (0x00000001U)

#define CSL_USB3_OTG_OCTL_PRTPWRCTL_MASK                                       (0x00000020U)
#define CSL_USB3_OTG_OCTL_PRTPWRCTL_SHIFT                                      (0x00000005U)
#define CSL_USB3_OTG_OCTL_PRTPWRCTL_MAX                                        (0x00000001U)

#define CSL_USB3_OTG_OCTL_PERIMODE_MASK                                        (0x00000040U)
#define CSL_USB3_OTG_OCTL_PERIMODE_SHIFT                                       (0x00000006U)
#define CSL_USB3_OTG_OCTL_PERIMODE_MAX                                         (0x00000001U)

#define CSL_USB3_OTG_OCTL_OTG3_GOERR_MASK                                      (0x00000080U)
#define CSL_USB3_OTG_OCTL_OTG3_GOERR_SHIFT                                     (0x00000007U)
#define CSL_USB3_OTG_OCTL_OTG3_GOERR_MAX                                       (0x00000001U)

#define CSL_USB3_OTG_OCTL_RESERVED_31_8_MASK                                   (0xFFFFFF00U)
#define CSL_USB3_OTG_OCTL_RESERVED_31_8_SHIFT                                  (0x00000008U)
#define CSL_USB3_OTG_OCTL_RESERVED_31_8_MAX                                    (0x00FFFFFFU)

/* OEVT */

#define CSL_USB3_OTG_OEVT_OEVTERROR_MASK                                       (0x00000001U)
#define CSL_USB3_OTG_OEVT_OEVTERROR_SHIFT                                      (0x00000000U)
#define CSL_USB3_OTG_OEVT_OEVTERROR_MAX                                        (0x00000001U)

#define CSL_USB3_OTG_OEVT_SESREQSTS_MASK                                       (0x00000002U)
#define CSL_USB3_OTG_OEVT_SESREQSTS_SHIFT                                      (0x00000001U)
#define CSL_USB3_OTG_OEVT_SESREQSTS_MAX                                        (0x00000001U)

#define CSL_USB3_OTG_OEVT_HSTNEGSTS_MASK                                       (0x00000004U)
#define CSL_USB3_OTG_OEVT_HSTNEGSTS_SHIFT                                      (0x00000002U)
#define CSL_USB3_OTG_OEVT_HSTNEGSTS_MAX                                        (0x00000001U)

#define CSL_USB3_OTG_OEVT_BSESVLD_MASK                                         (0x00000008U)
#define CSL_USB3_OTG_OEVT_BSESVLD_SHIFT                                        (0x00000003U)
#define CSL_USB3_OTG_OEVT_BSESVLD_MAX                                          (0x00000001U)

#define CSL_USB3_OTG_OEVT_RESERVED_7_4_MASK                                    (0x000000F0U)
#define CSL_USB3_OTG_OEVT_RESERVED_7_4_SHIFT                                   (0x00000004U)
#define CSL_USB3_OTG_OEVT_RESERVED_7_4_MAX                                     (0x0000000FU)

#define CSL_USB3_OTG_OEVT_OTGBDEVVBUSCHNGEVNT_MASK                             (0x00000100U)
#define CSL_USB3_OTG_OEVT_OTGBDEVVBUSCHNGEVNT_SHIFT                            (0x00000008U)
#define CSL_USB3_OTG_OEVT_OTGBDEVVBUSCHNGEVNT_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGBDEVSESSVLDDETEVNT_MASK                           (0x00000200U)
#define CSL_USB3_OTG_OEVT_OTGBDEVSESSVLDDETEVNT_SHIFT                          (0x00000009U)
#define CSL_USB3_OTG_OEVT_OTGBDEVSESSVLDDETEVNT_MAX                            (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGBDEVHNPCHNGEVNT_MASK                              (0x00000400U)
#define CSL_USB3_OTG_OEVT_OTGBDEVHNPCHNGEVNT_SHIFT                             (0x0000000AU)
#define CSL_USB3_OTG_OEVT_OTGBDEVHNPCHNGEVNT_MAX                               (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGBDEVBHOSTENDEVNT_MASK                             (0x00000800U)
#define CSL_USB3_OTG_OEVT_OTGBDEVBHOSTENDEVNT_SHIFT                            (0x0000000BU)
#define CSL_USB3_OTG_OEVT_OTGBDEVBHOSTENDEVNT_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVT_RESERVED_15_12_MASK                                  (0x0000F000U)
#define CSL_USB3_OTG_OEVT_RESERVED_15_12_SHIFT                                 (0x0000000CU)
#define CSL_USB3_OTG_OEVT_RESERVED_15_12_MAX                                   (0x0000000FU)

#define CSL_USB3_OTG_OEVT_OTGADEVSESSENDDETEVNT_MASK                           (0x00010000U)
#define CSL_USB3_OTG_OEVT_OTGADEVSESSENDDETEVNT_SHIFT                          (0x00000010U)
#define CSL_USB3_OTG_OEVT_OTGADEVSESSENDDETEVNT_MAX                            (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGADEVSRPDETEVNT_MASK                               (0x00020000U)
#define CSL_USB3_OTG_OEVT_OTGADEVSRPDETEVNT_SHIFT                              (0x00000011U)
#define CSL_USB3_OTG_OEVT_OTGADEVSRPDETEVNT_MAX                                (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGADEVHNPCHNGEVNT_MASK                              (0x00040000U)
#define CSL_USB3_OTG_OEVT_OTGADEVHNPCHNGEVNT_SHIFT                             (0x00000012U)
#define CSL_USB3_OTG_OEVT_OTGADEVHNPCHNGEVNT_MAX                               (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGADEVHOSTEVNT_MASK                                 (0x00080000U)
#define CSL_USB3_OTG_OEVT_OTGADEVHOSTEVNT_SHIFT                                (0x00000013U)
#define CSL_USB3_OTG_OEVT_OTGADEVHOSTEVNT_MAX                                  (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGADEVBHOSTENDEVNT_MASK                             (0x00100000U)
#define CSL_USB3_OTG_OEVT_OTGADEVBHOSTENDEVNT_SHIFT                            (0x00000014U)
#define CSL_USB3_OTG_OEVT_OTGADEVBHOSTENDEVNT_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGADEVIDLEEVNT_MASK                                 (0x00200000U)
#define CSL_USB3_OTG_OEVT_OTGADEVIDLEEVNT_SHIFT                                (0x00000015U)
#define CSL_USB3_OTG_OEVT_OTGADEVIDLEEVNT_MAX                                  (0x00000001U)

#define CSL_USB3_OTG_OEVT_HRRINITNOTIFEVNT_MASK                                (0x00400000U)
#define CSL_USB3_OTG_OEVT_HRRINITNOTIFEVNT_SHIFT                               (0x00000016U)
#define CSL_USB3_OTG_OEVT_HRRINITNOTIFEVNT_MAX                                 (0x00000001U)

#define CSL_USB3_OTG_OEVT_HRRCONFNOTIFEVNT_MASK                                (0x00800000U)
#define CSL_USB3_OTG_OEVT_HRRCONFNOTIFEVNT_SHIFT                               (0x00000017U)
#define CSL_USB3_OTG_OEVT_HRRCONFNOTIFEVNT_MAX                                 (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGCONIDSTSCHNGEVNT_MASK                             (0x01000000U)
#define CSL_USB3_OTG_OEVT_OTGCONIDSTSCHNGEVNT_SHIFT                            (0x00000018U)
#define CSL_USB3_OTG_OEVT_OTGCONIDSTSCHNGEVNT_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGHIBENTRYEVNT_MASK                                 (0x02000000U)
#define CSL_USB3_OTG_OEVT_OTGHIBENTRYEVNT_SHIFT                                (0x00000019U)
#define CSL_USB3_OTG_OEVT_OTGHIBENTRYEVNT_MAX                                  (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGDEVRUNSTPSETEVNT_MASK                             (0x04000000U)
#define CSL_USB3_OTG_OEVT_OTGDEVRUNSTPSETEVNT_SHIFT                            (0x0000001AU)
#define CSL_USB3_OTG_OEVT_OTGDEVRUNSTPSETEVNT_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVT_OTGXHCIRUNSTPSETEVNT_MASK                            (0x08000000U)
#define CSL_USB3_OTG_OEVT_OTGXHCIRUNSTPSETEVNT_SHIFT                           (0x0000001BU)
#define CSL_USB3_OTG_OEVT_OTGXHCIRUNSTPSETEVNT_MAX                             (0x00000001U)

#define CSL_USB3_OTG_OEVT_RESERVED_30_28_MASK                                  (0x70000000U)
#define CSL_USB3_OTG_OEVT_RESERVED_30_28_SHIFT                                 (0x0000001CU)
#define CSL_USB3_OTG_OEVT_RESERVED_30_28_MAX                                   (0x00000007U)

#define CSL_USB3_OTG_OEVT_DEVICEMODE_MASK                                      (0x80000000U)
#define CSL_USB3_OTG_OEVT_DEVICEMODE_SHIFT                                     (0x0000001FU)
#define CSL_USB3_OTG_OEVT_DEVICEMODE_MAX                                       (0x00000001U)

/* OEVTEN */

#define CSL_USB3_OTG_OEVTEN_RESERVED_7_0_MASK                                  (0x000000FFU)
#define CSL_USB3_OTG_OEVTEN_RESERVED_7_0_SHIFT                                 (0x00000000U)
#define CSL_USB3_OTG_OEVTEN_RESERVED_7_0_MAX                                   (0x000000FFU)

#define CSL_USB3_OTG_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MASK                         (0x00000100U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_SHIFT                        (0x00000008U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MAX                          (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MASK                       (0x00000200U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_SHIFT                      (0x00000009U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MAX                        (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MASK                          (0x00000400U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVHNPCHNGEVNTEN_SHIFT                         (0x0000000AU)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MAX                           (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGBDEVBHOSTENDEVNTEN_MASK                         (0x00000800U)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVBHOSTENDEVNTEN_SHIFT                        (0x0000000BU)
#define CSL_USB3_OTG_OEVTEN_OTGBDEVBHOSTENDEVNTEN_MAX                          (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_RESERVED_15_12_MASK                                (0x0000F000U)
#define CSL_USB3_OTG_OEVTEN_RESERVED_15_12_SHIFT                               (0x0000000CU)
#define CSL_USB3_OTG_OEVTEN_RESERVED_15_12_MAX                                 (0x0000000FU)

#define CSL_USB3_OTG_OEVTEN_OTGADEVSESSENDDETEVNTEN_MASK                       (0x00010000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVSESSENDDETEVNTEN_SHIFT                      (0x00000010U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVSESSENDDETEVNTEN_MAX                        (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGADEVSRPDETEVNTEN_MASK                           (0x00020000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVSRPDETEVNTEN_SHIFT                          (0x00000011U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVSRPDETEVNTEN_MAX                            (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGADEVHNPCHNGEVNTEN_MASK                          (0x00040000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVHNPCHNGEVNTEN_SHIFT                         (0x00000012U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVHNPCHNGEVNTEN_MAX                           (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGADEVHOSTEVNTEN_MASK                             (0x00080000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVHOSTEVNTEN_SHIFT                            (0x00000013U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVHOSTEVNTEN_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGADEVBHOSTENDEVNTEN_MASK                         (0x00100000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVBHOSTENDEVNTEN_SHIFT                        (0x00000014U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVBHOSTENDEVNTEN_MAX                          (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGADEVIDLEEVNTEN_MASK                             (0x00200000U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVIDLEEVNTEN_SHIFT                            (0x00000015U)
#define CSL_USB3_OTG_OEVTEN_OTGADEVIDLEEVNTEN_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_HRRINITNOTIFEVNTEN_MASK                            (0x00400000U)
#define CSL_USB3_OTG_OEVTEN_HRRINITNOTIFEVNTEN_SHIFT                           (0x00000016U)
#define CSL_USB3_OTG_OEVTEN_HRRINITNOTIFEVNTEN_MAX                             (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_HRRCONFNOTIFEVNTEN_MASK                            (0x00800000U)
#define CSL_USB3_OTG_OEVTEN_HRRCONFNOTIFEVNTEN_SHIFT                           (0x00000017U)
#define CSL_USB3_OTG_OEVTEN_HRRCONFNOTIFEVNTEN_MAX                             (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MASK                         (0x01000000U)
#define CSL_USB3_OTG_OEVTEN_OTGCONIDSTSCHNGEVNTEN_SHIFT                        (0x00000018U)
#define CSL_USB3_OTG_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MAX                          (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGHIBENTRYEVNTEN_MASK                             (0x02000000U)
#define CSL_USB3_OTG_OEVTEN_OTGHIBENTRYEVNTEN_SHIFT                            (0x00000019U)
#define CSL_USB3_OTG_OEVTEN_OTGHIBENTRYEVNTEN_MAX                              (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGDEVRUNSTPSETEVNTEN_MASK                         (0x04000000U)
#define CSL_USB3_OTG_OEVTEN_OTGDEVRUNSTPSETEVNTEN_SHIFT                        (0x0000001AU)
#define CSL_USB3_OTG_OEVTEN_OTGDEVRUNSTPSETEVNTEN_MAX                          (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_MASK                        (0x08000000U)
#define CSL_USB3_OTG_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_SHIFT                       (0x0000001BU)
#define CSL_USB3_OTG_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_MAX                         (0x00000001U)

#define CSL_USB3_OTG_OEVTEN_RESERVED_31_28_MASK                                (0xF0000000U)
#define CSL_USB3_OTG_OEVTEN_RESERVED_31_28_SHIFT                               (0x0000001CU)
#define CSL_USB3_OTG_OEVTEN_RESERVED_31_28_MAX                                 (0x0000000FU)

/* OSTS */

#define CSL_USB3_OTG_OSTS_CONIDSTS_MASK                                        (0x00000001U)
#define CSL_USB3_OTG_OSTS_CONIDSTS_SHIFT                                       (0x00000000U)
#define CSL_USB3_OTG_OSTS_CONIDSTS_MAX                                         (0x00000001U)

#define CSL_USB3_OTG_OSTS_ASESVLD_MASK                                         (0x00000002U)
#define CSL_USB3_OTG_OSTS_ASESVLD_SHIFT                                        (0x00000001U)
#define CSL_USB3_OTG_OSTS_ASESVLD_MAX                                          (0x00000001U)

#define CSL_USB3_OTG_OSTS_BSESVLD_MASK                                         (0x00000004U)
#define CSL_USB3_OTG_OSTS_BSESVLD_SHIFT                                        (0x00000002U)
#define CSL_USB3_OTG_OSTS_BSESVLD_MAX                                          (0x00000001U)

#define CSL_USB3_OTG_OSTS_XHCIPRTPOWER_MASK                                    (0x00000008U)
#define CSL_USB3_OTG_OSTS_XHCIPRTPOWER_SHIFT                                   (0x00000003U)
#define CSL_USB3_OTG_OSTS_XHCIPRTPOWER_MAX                                     (0x00000001U)

#define CSL_USB3_OTG_OSTS_PERIPHERALSTATE_MASK                                 (0x00000010U)
#define CSL_USB3_OTG_OSTS_PERIPHERALSTATE_SHIFT                                (0x00000004U)
#define CSL_USB3_OTG_OSTS_PERIPHERALSTATE_MAX                                  (0x00000001U)

#define CSL_USB3_OTG_OSTS_RESERVED_7_5_MASK                                    (0x000000E0U)
#define CSL_USB3_OTG_OSTS_RESERVED_7_5_SHIFT                                   (0x00000005U)
#define CSL_USB3_OTG_OSTS_RESERVED_7_5_MAX                                     (0x00000007U)

#define CSL_USB3_OTG_OSTS_OTGSTATE_MASK                                        (0x00000F00U)
#define CSL_USB3_OTG_OSTS_OTGSTATE_SHIFT                                       (0x00000008U)
#define CSL_USB3_OTG_OSTS_OTGSTATE_MAX                                         (0x0000000FU)

#define CSL_USB3_OTG_OSTS_XHCIRUNSTP_MASK                                      (0x00001000U)
#define CSL_USB3_OTG_OSTS_XHCIRUNSTP_SHIFT                                     (0x0000000CU)
#define CSL_USB3_OTG_OSTS_XHCIRUNSTP_MAX                                       (0x00000001U)

#define CSL_USB3_OTG_OSTS_DEVRUNSTP_MASK                                       (0x00002000U)
#define CSL_USB3_OTG_OSTS_DEVRUNSTP_SHIFT                                      (0x0000000DU)
#define CSL_USB3_OTG_OSTS_DEVRUNSTP_MAX                                        (0x00000001U)

#define CSL_USB3_OTG_OSTS_RESERVED_31_14_MASK                                  (0xFFFFC000U)
#define CSL_USB3_OTG_OSTS_RESERVED_31_14_SHIFT                                 (0x0000000EU)
#define CSL_USB3_OTG_OSTS_RESERVED_31_14_MAX                                   (0x0003FFFFU)

/* ADPCFG */

#define CSL_USB3_OTG_ADPCFG_RESERVED_25_0_MASK                                 (0x03FFFFFFU)
#define CSL_USB3_OTG_ADPCFG_RESERVED_25_0_SHIFT                                (0x00000000U)
#define CSL_USB3_OTG_ADPCFG_RESERVED_25_0_MAX                                  (0x03FFFFFFU)

#define CSL_USB3_OTG_ADPCFG_PRBDSCHG_MASK                                      (0x0C000000U)
#define CSL_USB3_OTG_ADPCFG_PRBDSCHG_SHIFT                                     (0x0000001AU)
#define CSL_USB3_OTG_ADPCFG_PRBDSCHG_MAX                                       (0x00000003U)

#define CSL_USB3_OTG_ADPCFG_PRBDELTA_MASK                                      (0x30000000U)
#define CSL_USB3_OTG_ADPCFG_PRBDELTA_SHIFT                                     (0x0000001CU)
#define CSL_USB3_OTG_ADPCFG_PRBDELTA_MAX                                       (0x00000003U)

#define CSL_USB3_OTG_ADPCFG_PRBPER_MASK                                        (0xC0000000U)
#define CSL_USB3_OTG_ADPCFG_PRBPER_SHIFT                                       (0x0000001EU)
#define CSL_USB3_OTG_ADPCFG_PRBPER_MAX                                         (0x00000003U)

/* ADPCTL */

#define CSL_USB3_OTG_ADPCTL_RESERVED_23_0_MASK                                 (0x00FFFFFFU)
#define CSL_USB3_OTG_ADPCTL_RESERVED_23_0_SHIFT                                (0x00000000U)
#define CSL_USB3_OTG_ADPCTL_RESERVED_23_0_MAX                                  (0x00FFFFFFU)

#define CSL_USB3_OTG_ADPCTL_WB_MASK                                            (0x01000000U)
#define CSL_USB3_OTG_ADPCTL_WB_SHIFT                                           (0x00000018U)
#define CSL_USB3_OTG_ADPCTL_WB_MAX                                             (0x00000001U)

#define CSL_USB3_OTG_ADPCTL_ADPRES_MASK                                        (0x02000000U)
#define CSL_USB3_OTG_ADPCTL_ADPRES_SHIFT                                       (0x00000019U)
#define CSL_USB3_OTG_ADPCTL_ADPRES_MAX                                         (0x00000001U)

#define CSL_USB3_OTG_ADPCTL_ADPEN_MASK                                         (0x04000000U)
#define CSL_USB3_OTG_ADPCTL_ADPEN_SHIFT                                        (0x0000001AU)
#define CSL_USB3_OTG_ADPCTL_ADPEN_MAX                                          (0x00000001U)

#define CSL_USB3_OTG_ADPCTL_ENASNS_MASK                                        (0x08000000U)
#define CSL_USB3_OTG_ADPCTL_ENASNS_SHIFT                                       (0x0000001BU)
#define CSL_USB3_OTG_ADPCTL_ENASNS_MAX                                         (0x00000001U)

#define CSL_USB3_OTG_ADPCTL_ENAPRB_MASK                                        (0x10000000U)
#define CSL_USB3_OTG_ADPCTL_ENAPRB_SHIFT                                       (0x0000001CU)
#define CSL_USB3_OTG_ADPCTL_ENAPRB_MAX                                         (0x00000001U)

#define CSL_USB3_OTG_ADPCTL_RESERVED_31_29_MASK                                (0xE0000000U)
#define CSL_USB3_OTG_ADPCTL_RESERVED_31_29_SHIFT                               (0x0000001DU)
#define CSL_USB3_OTG_ADPCTL_RESERVED_31_29_MAX                                 (0x00000007U)

/* ADPEVT */

#define CSL_USB3_OTG_ADPEVT_RTIM_MASK                                          (0x0000FFFFU)
#define CSL_USB3_OTG_ADPEVT_RTIM_SHIFT                                         (0x00000000U)
#define CSL_USB3_OTG_ADPEVT_RTIM_MAX                                           (0x0000FFFFU)

#define CSL_USB3_OTG_ADPEVT_RESERVED_24_16_MASK                                (0x01FF0000U)
#define CSL_USB3_OTG_ADPEVT_RESERVED_24_16_SHIFT                               (0x00000010U)
#define CSL_USB3_OTG_ADPEVT_RESERVED_24_16_MAX                                 (0x000001FFU)

#define CSL_USB3_OTG_ADPEVT_ADPRSTCMPLTEVNT_MASK                               (0x02000000U)
#define CSL_USB3_OTG_ADPEVT_ADPRSTCMPLTEVNT_SHIFT                              (0x00000019U)
#define CSL_USB3_OTG_ADPEVT_ADPRSTCMPLTEVNT_MAX                                (0x00000001U)

#define CSL_USB3_OTG_ADPEVT_ADPTMOUTEVNT_MASK                                  (0x04000000U)
#define CSL_USB3_OTG_ADPEVT_ADPTMOUTEVNT_SHIFT                                 (0x0000001AU)
#define CSL_USB3_OTG_ADPEVT_ADPTMOUTEVNT_MAX                                   (0x00000001U)

#define CSL_USB3_OTG_ADPEVT_ADPSNSEVNT_MASK                                    (0x08000000U)
#define CSL_USB3_OTG_ADPEVT_ADPSNSEVNT_SHIFT                                   (0x0000001BU)
#define CSL_USB3_OTG_ADPEVT_ADPSNSEVNT_MAX                                     (0x00000001U)

#define CSL_USB3_OTG_ADPEVT_ADPPRBEVNT_MASK                                    (0x10000000U)
#define CSL_USB3_OTG_ADPEVT_ADPPRBEVNT_SHIFT                                   (0x0000001CU)
#define CSL_USB3_OTG_ADPEVT_ADPPRBEVNT_MAX                                     (0x00000001U)

#define CSL_USB3_OTG_ADPEVT_RESERVED_31_29_MASK                                (0xE0000000U)
#define CSL_USB3_OTG_ADPEVT_RESERVED_31_29_SHIFT                               (0x0000001DU)
#define CSL_USB3_OTG_ADPEVT_RESERVED_31_29_MAX                                 (0x00000007U)

/* ADPEVTEN */

#define CSL_USB3_OTG_ADPEVTEN_RESERVED_24_0_MASK                               (0x01FFFFFFU)
#define CSL_USB3_OTG_ADPEVTEN_RESERVED_24_0_SHIFT                              (0x00000000U)
#define CSL_USB3_OTG_ADPEVTEN_RESERVED_24_0_MAX                                (0x01FFFFFFU)

#define CSL_USB3_OTG_ADPEVTEN_ADPRSTCMPLTEVNTEN_MASK                           (0x02000000U)
#define CSL_USB3_OTG_ADPEVTEN_ADPRSTCMPLTEVNTEN_SHIFT                          (0x00000019U)
#define CSL_USB3_OTG_ADPEVTEN_ADPRSTCMPLTEVNTEN_MAX                            (0x00000001U)

#define CSL_USB3_OTG_ADPEVTEN_ADPTMOUTEVNTEN_MASK                              (0x04000000U)
#define CSL_USB3_OTG_ADPEVTEN_ADPTMOUTEVNTEN_SHIFT                             (0x0000001AU)
#define CSL_USB3_OTG_ADPEVTEN_ADPTMOUTEVNTEN_MAX                               (0x00000001U)

#define CSL_USB3_OTG_ADPEVTEN_ADPSNSEVNTEN_MASK                                (0x08000000U)
#define CSL_USB3_OTG_ADPEVTEN_ADPSNSEVNTEN_SHIFT                               (0x0000001BU)
#define CSL_USB3_OTG_ADPEVTEN_ADPSNSEVNTEN_MAX                                 (0x00000001U)

#define CSL_USB3_OTG_ADPEVTEN_ADPPRBEVNTEN_MASK                                (0x10000000U)
#define CSL_USB3_OTG_ADPEVTEN_ADPPRBEVNTEN_SHIFT                               (0x0000001CU)
#define CSL_USB3_OTG_ADPEVTEN_ADPPRBEVNTEN_MAX                                 (0x00000001U)

#define CSL_USB3_OTG_ADPEVTEN_RESERVED_31_29_MASK                              (0xE0000000U)
#define CSL_USB3_OTG_ADPEVTEN_RESERVED_31_29_SHIFT                             (0x0000001DU)
#define CSL_USB3_OTG_ADPEVTEN_RESERVED_31_29_MAX                               (0x00000007U)

/**************************************************************************
* Hardware Region  : USB3 BC Register Block
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t BCFG;                      /* BCFG */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t BCEVT;                     /* BCEVT */
    volatile uint32_t BCEVTEN;                   /* BCEVTEN */
} CSL_usb3_bcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_BC_BCFG                                                       (0x0001CC30U)
#define CSL_USB3_BC_BCEVT                                                      (0x0001CC38U)
#define CSL_USB3_BC_BCEVTEN                                                    (0x0001CC3CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* BCFG */

#define CSL_USB3_BC_BCFG_CHIRP_EN_MASK                                         (0x00000001U)
#define CSL_USB3_BC_BCFG_CHIRP_EN_SHIFT                                        (0x00000000U)
#define CSL_USB3_BC_BCFG_CHIRP_EN_MAX                                          (0x00000001U)

#define CSL_USB3_BC_BCFG_IDDIG_SEL_MASK                                        (0x00000002U)
#define CSL_USB3_BC_BCFG_IDDIG_SEL_SHIFT                                       (0x00000001U)
#define CSL_USB3_BC_BCFG_IDDIG_SEL_MAX                                         (0x00000001U)

#define CSL_USB3_BC_BCFG_RESERVED_31_2_MASK                                    (0xFFFFFFFCU)
#define CSL_USB3_BC_BCFG_RESERVED_31_2_SHIFT                                   (0x00000002U)
#define CSL_USB3_BC_BCFG_RESERVED_31_2_MAX                                     (0x3FFFFFFFU)

/* BCEVT */

#define CSL_USB3_BC_BCEVT_MULTVALIDBC_MASK                                     (0x0000001FU)
#define CSL_USB3_BC_BCEVT_MULTVALIDBC_SHIFT                                    (0x00000000U)
#define CSL_USB3_BC_BCEVT_MULTVALIDBC_MAX                                      (0x0000001FU)

#define CSL_USB3_BC_BCEVT_RESERVED_23_5_MASK                                   (0x00FFFFE0U)
#define CSL_USB3_BC_BCEVT_RESERVED_23_5_SHIFT                                  (0x00000005U)
#define CSL_USB3_BC_BCEVT_RESERVED_23_5_MAX                                    (0x0007FFFFU)

#define CSL_USB3_BC_BCEVT_MV_CHNGEVNT_MASK                                     (0x01000000U)
#define CSL_USB3_BC_BCEVT_MV_CHNGEVNT_SHIFT                                    (0x00000018U)
#define CSL_USB3_BC_BCEVT_MV_CHNGEVNT_MAX                                      (0x00000001U)

#define CSL_USB3_BC_BCEVT_RESERVED_31_25_MASK                                  (0xFE000000U)
#define CSL_USB3_BC_BCEVT_RESERVED_31_25_SHIFT                                 (0x00000019U)
#define CSL_USB3_BC_BCEVT_RESERVED_31_25_MAX                                   (0x0000007FU)

/* BCEVTEN */

#define CSL_USB3_BC_BCEVTEN_RESERVED_23_0_MASK                                 (0x00FFFFFFU)
#define CSL_USB3_BC_BCEVTEN_RESERVED_23_0_SHIFT                                (0x00000000U)
#define CSL_USB3_BC_BCEVTEN_RESERVED_23_0_MAX                                  (0x00FFFFFFU)

#define CSL_USB3_BC_BCEVTEN_MV_CHNGEVNTENA_MASK                                (0x01000000U)
#define CSL_USB3_BC_BCEVTEN_MV_CHNGEVNTENA_SHIFT                               (0x00000018U)
#define CSL_USB3_BC_BCEVTEN_MV_CHNGEVNTENA_MAX                                 (0x00000001U)

#define CSL_USB3_BC_BCEVTEN_RESERVED_31_25_MASK                                (0xFE000000U)
#define CSL_USB3_BC_BCEVTEN_RESERVED_31_25_SHIFT                               (0x00000019U)
#define CSL_USB3_BC_BCEVTEN_RESERVED_31_25_MAX                                 (0x0000007FU)

/**************************************************************************
* Hardware Region  : USB2 PHY Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t TERMINATION_CONTROL;       /* TERMINATION_CONTROL */
    volatile uint32_t RX_CALIB;                  /* RX_CALIB */
    volatile uint32_t DLLHS_2;                   /* DLLHS_2 */
    volatile uint32_t RX_TEST_2;                 /* RX_TEST_2 */
    volatile uint32_t TX_TEST_CHRG_DET;          /* TX_TEST_CHRG_DET */
    volatile uint32_t CHRG_DET;                  /* CHRG_DET */
    volatile uint32_t PWR_CNTL;                  /* PWR_CNTL */
    volatile uint32_t UTMI_INTERFACE_CNTL_1;     /* UTMI_INTERFACE_CNTL_1 */
    volatile uint32_t UTMI_INTERFACE_CNTL_2;     /* UTMI_INTERFACE_CNTL_2 */
    volatile uint32_t BIST;                      /* BIST */
    volatile uint32_t BIST_CRC;                  /* BIST_CRC */
    volatile uint32_t CDR_BIST2;                 /* CDR_BIST2 */
    volatile uint32_t GPIO;                      /* GPIO */
    volatile uint32_t USB2PHYCM_TRIM;            /* USB2PHYCM_TRIM */
    volatile uint32_t USB2PHYCM_CONFIG;          /* USB2PHYCM_CONFIG */
    volatile uint32_t USBOTG;                    /* USBOTG */
    volatile uint32_t AD_INTERFACE_REG1;         /* AD_INTERFACE_REG1 */
    volatile uint32_t AD_INTERFACE_REG2;         /* AD_INTERFACE_REG2 */
    volatile uint32_t AD_INTERFACE_REG3;         /* AD_INTERFACE_REG3 */
    volatile uint32_t ANA_CONFIG1;               /* ANA_CONFIG1 */
    volatile uint32_t ANA_CONFIG2;               /* ANA_CONFIG2 */
    volatile uint8_t  Resv_88[4];
    volatile uint32_t RX_CALIB_RD;               /* RX_CALIB_RD */
    volatile uint32_t TX_TEST_CHRG_DET_RD;       /* TX_TEST_CHRG_DET_RD */
    volatile uint32_t BIST_CRC_READ;             /* BIST_CRC_READ */
    volatile uint32_t GPIO_TRIM_RD;              /* GPIO_TRIM_RD */
    volatile uint32_t AD_INTERFACE_RD_REG1;      /* AD_INTERFACE_RD_REG1 */
    volatile uint32_t AD_INTERFACE_RD_REG3;      /* AD_INTERFACE_RD_REG3 */
    volatile uint32_t BIST_DATA1;                /* BIST_DATA1 */
    volatile uint32_t BIST_DATA2;                /* BIST_DATA2 */
    volatile uint32_t CEGPIO_REG;                /* CEGPIO_REG */
} CSL_usb3_phy2Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_USB3_PHY2_TERMINATION_CONTROL                                      (0x00000000U)
#define CSL_USB3_PHY2_RX_CALIB                                                 (0x00000004U)
#define CSL_USB3_PHY2_DLLHS_2                                                  (0x00000008U)
#define CSL_USB3_PHY2_RX_TEST_2                                                (0x0000000CU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET                                         (0x00000010U)
#define CSL_USB3_PHY2_CHRG_DET                                                 (0x00000014U)
#define CSL_USB3_PHY2_PWR_CNTL                                                 (0x00000018U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1                                    (0x0000001CU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2                                    (0x00000020U)
#define CSL_USB3_PHY2_BIST                                                     (0x00000024U)
#define CSL_USB3_PHY2_BIST_CRC                                                 (0x00000028U)
#define CSL_USB3_PHY2_CDR_BIST2                                                (0x0000002CU)
#define CSL_USB3_PHY2_GPIO                                                     (0x00000030U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM                                           (0x00000034U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG                                         (0x00000038U)
#define CSL_USB3_PHY2_USBOTG                                                   (0x0000003CU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1                                        (0x00000040U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2                                        (0x00000044U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3                                        (0x00000048U)
#define CSL_USB3_PHY2_ANA_CONFIG1                                              (0x0000004CU)
#define CSL_USB3_PHY2_ANA_CONFIG2                                              (0x00000050U)
#define CSL_USB3_PHY2_RX_CALIB_RD                                              (0x00000058U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD                                      (0x0000005CU)
#define CSL_USB3_PHY2_BIST_CRC_READ                                            (0x00000060U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD                                             (0x00000064U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1                                     (0x00000068U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3                                     (0x0000006CU)
#define CSL_USB3_PHY2_BIST_DATA1                                               (0x00000070U)
#define CSL_USB3_PHY2_BIST_DATA2                                               (0x00000074U)
#define CSL_USB3_PHY2_CEGPIO_REG                                               (0x00000078U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* TERMINATION_CONTROL */

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RTERM_RMX_MASK                       (0x0000003FU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RTERM_RMX_SHIFT                      (0x00000000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RTERM_RMX_MAX                        (0x0000003FU)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED8_6_MASK                     (0x000000C0U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED8_6_SHIFT                    (0x00000006U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED8_6_MAX                      (0x00000003U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_DISABLE_TEMP_TRACK_MASK          (0x00000100U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_DISABLE_TEMP_TRACK_SHIFT         (0x00000008U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_DISABLE_TEMP_TRACK_MAX           (0x00000001U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED10_9_MASK                    (0x00000600U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED10_9_SHIFT                   (0x00000009U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED10_9_MAX                     (0x00000003U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_HS_CODE_SEL_MASK                 (0x00003800U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_HS_CODE_SEL_SHIFT                (0x0000000BU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_HS_CODE_SEL_MAX                  (0x00000007U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED14_MASK                      (0x00004000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED14_SHIFT                     (0x0000000EU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED14_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTERM_RMX_MASK                   (0x001F8000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTERM_RMX_SHIFT                  (0x0000000FU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTERM_RMX_MAX                    (0x0000003FU)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTMEM_USE_RTERM_RMX_REG_MASK     (0x00200000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTMEM_USE_RTERM_RMX_REG_SHIFT    (0x00000015U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_RTMEM_USE_RTERM_RMX_REG_MAX      (0x00000001U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED23_22_MASK                   (0x00C00000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED23_22_SHIFT                  (0x00000016U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED23_22_MAX                    (0x00000003U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_FS_CODE_SEL_MASK                 (0x0F000000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_FS_CODE_SEL_SHIFT                (0x00000018U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_FS_CODE_SEL_MAX                  (0x0000000FU)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED28_MASK                      (0x10000000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED28_SHIFT                     (0x0000001CU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED28_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_ALWAYS_UPDATE_MASK               (0x20000000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_ALWAYS_UPDATE_SHIFT              (0x0000001DU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_MEM_ALWAYS_UPDATE_MAX                (0x00000001U)

#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED30_31_MASK                   (0xC0000000U)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED30_31_SHIFT                  (0x0000001EU)
#define CSL_USB3_PHY2_TERMINATION_CONTROL_RESERVED30_31_MAX                    (0x00000003U)

/* RX_CALIB */

#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_HSRX_CAL_MASK                       (0x80000000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_HSRX_CAL_SHIFT                      (0x0000001FU)
#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_HSRX_CAL_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_HS_OFF_REG_MASK                         (0x40000000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_HS_OFF_REG_SHIFT                        (0x0000001EU)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_HS_OFF_REG_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_HS_OFF_CODE_MASK                            (0x3F000000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_HS_OFF_CODE_SHIFT                           (0x00000018U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_HS_OFF_CODE_MAX                             (0x0000003FU)

#define CSL_USB3_PHY2_RX_CALIB_HSRX_COMP_OUT_MASK                              (0x00800000U)
#define CSL_USB3_PHY2_RX_CALIB_HSRX_COMP_OUT_SHIFT                             (0x00000017U)
#define CSL_USB3_PHY2_RX_CALIB_HSRX_COMP_OUT_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_HSRX_CAL_DONE_MASK                              (0x00400000U)
#define CSL_USB3_PHY2_RX_CALIB_HSRX_CAL_DONE_SHIFT                             (0x00000016U)
#define CSL_USB3_PHY2_RX_CALIB_HSRX_CAL_DONE_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC1_MASK                        (0x00200000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC1_SHIFT                       (0x00000015U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC1_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC1_MASK                       (0x001FC000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC1_SHIFT                      (0x0000000EU)
#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC1_MAX                        (0x0000007FU)

#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC2_MASK                        (0x00002000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC2_SHIFT                       (0x0000000DU)
#define CSL_USB3_PHY2_RX_CALIB_MEM_USE_SQ_OFF_DAC2_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC2_MASK                       (0x00001FC0U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC2_SHIFT                      (0x00000006U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_SQ_OFF_CODE_DAC2_MAX                        (0x0000007FU)

#define CSL_USB3_PHY2_RX_CALIB_RESERVED_MASK                                   (0x00000038U)
#define CSL_USB3_PHY2_RX_CALIB_RESERVED_SHIFT                                  (0x00000003U)
#define CSL_USB3_PHY2_RX_CALIB_RESERVED_MAX                                    (0x00000007U)

#define CSL_USB3_PHY2_RX_CALIB_SQ_COMP_OUT_MASK                                (0x00000004U)
#define CSL_USB3_PHY2_RX_CALIB_SQ_COMP_OUT_SHIFT                               (0x00000002U)
#define CSL_USB3_PHY2_RX_CALIB_SQ_COMP_OUT_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_SQ_CAL_DONE_MASK                                (0x00000002U)
#define CSL_USB3_PHY2_RX_CALIB_SQ_CAL_DONE_SHIFT                               (0x00000001U)
#define CSL_USB3_PHY2_RX_CALIB_SQ_CAL_DONE_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_SQ_CAL_MASK                         (0x00000001U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_SQ_CAL_SHIFT                        (0x00000000U)
#define CSL_USB3_PHY2_RX_CALIB_MEM_RESTART_SQ_CAL_MAX                          (0x00000001U)

/* DLLHS_2 */

#define CSL_USB3_PHY2_DLLHS_2_MEM_DLLHS_CNTRL_LDO_MASK                         (0xFF000000U)
#define CSL_USB3_PHY2_DLLHS_2_MEM_DLLHS_CNTRL_LDO_SHIFT                        (0x00000018U)
#define CSL_USB3_PHY2_DLLHS_2_MEM_DLLHS_CNTRL_LDO_MAX                          (0x000000FFU)

#define CSL_USB3_PHY2_DLLHS_2_DLLHS_STATUS_LDO_MASK                            (0x00FF0000U)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_STATUS_LDO_SHIFT                           (0x00000010U)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_STATUS_LDO_MAX                             (0x000000FFU)

#define CSL_USB3_PHY2_DLLHS_2_DLLHS_LOCK_MASK                                  (0x00008000U)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_LOCK_SHIFT                                 (0x0000000FU)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_LOCK_MAX                                   (0x00000001U)

#define CSL_USB3_PHY2_DLLHS_2_RESERVED14_MASK                                  (0x00004000U)
#define CSL_USB3_PHY2_DLLHS_2_RESERVED14_SHIFT                                 (0x0000000EU)
#define CSL_USB3_PHY2_DLLHS_2_RESERVED14_MAX                                   (0x00000001U)

#define CSL_USB3_PHY2_DLLHS_2_DLLHS_GENERATED_CODE_MASK                        (0x00003F00U)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_GENERATED_CODE_SHIFT                       (0x00000008U)
#define CSL_USB3_PHY2_DLLHS_2_DLLHS_GENERATED_CODE_MAX                         (0x0000003FU)

#define CSL_USB3_PHY2_DLLHS_2_RESERVED5_7_MASK                                 (0x000000E0U)
#define CSL_USB3_PHY2_DLLHS_2_RESERVED5_7_SHIFT                                (0x00000005U)
#define CSL_USB3_PHY2_DLLHS_2_RESERVED5_7_MAX                                  (0x00000007U)

#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_EN_MASK                   (0x00000010U)
#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_EN_SHIFT                  (0x00000004U)
#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_EN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_CNTL_MASK                 (0x0000000FU)
#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_CNTL_SHIFT                (0x00000000U)
#define CSL_USB3_PHY2_DLLHS_2_MEM_LINESTATE_DEBOUNCE_CNTL_MAX                  (0x0000000FU)

/* RX_TEST_2 */

#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSREVERSAL_MASK                          (0x80000000U)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSREVERSAL_SHIFT                         (0x0000001FU)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSREVERSAL_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSBITINVERSION_MASK                      (0x40000000U)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSBITINVERSION_SHIFT                     (0x0000001EU)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_HSOSBITINVERSION_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_RX_TEST_2_MEM_PHYCLKOUTINVERSION_MASK                    (0x20000000U)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_PHYCLKOUTINVERSION_SHIFT                   (0x0000001DU)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_PHYCLKOUTINVERSION_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_RX_TEST_2_RESERVED28_MASK                                (0x10000000U)
#define CSL_USB3_PHY2_RX_TEST_2_RESERVED28_SHIFT                               (0x0000001CU)
#define CSL_USB3_PHY2_RX_TEST_2_RESERVED28_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_RX_TEST_2_MEM_USEINTDATAOUT_MASK                         (0x08000000U)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_USEINTDATAOUT_SHIFT                        (0x0000001BU)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_USEINTDATAOUT_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_RX_TEST_2_MEM_INTDATAOUTREG_MASK                         (0x07FFF800U)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_INTDATAOUTREG_SHIFT                        (0x0000000BU)
#define CSL_USB3_PHY2_RX_TEST_2_MEM_INTDATAOUTREG_MAX                          (0x0000FFFFU)

#define CSL_USB3_PHY2_RX_TEST_2_RESERVED_MASK                                  (0x00000700U)
#define CSL_USB3_PHY2_RX_TEST_2_RESERVED_SHIFT                                 (0x00000008U)
#define CSL_USB3_PHY2_RX_TEST_2_RESERVED_MAX                                   (0x00000007U)

#define CSL_USB3_PHY2_RX_TEST_2_CDR_TESTOUT_MASK                               (0x000000FFU)
#define CSL_USB3_PHY2_RX_TEST_2_CDR_TESTOUT_SHIFT                              (0x00000000U)
#define CSL_USB3_PHY2_RX_TEST_2_CDR_TESTOUT_MAX                                (0x000000FFU)

/* TX_TEST_CHRG_DET */

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED31_MASK                         (0x80000000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED31_SHIFT                        (0x0000001FU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED31_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED30_15_MASK                      (0x7FFF8000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED30_15_SHIFT                     (0x0000000FU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED30_15_MAX                       (0x0000FFFFU)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED14_MASK                         (0x00004000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED14_SHIFT                        (0x0000000EU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED14_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED13_MASK                         (0x00002000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED13_SHIFT                        (0x0000000DU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED13_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHGDET_DPDMSW_MASK              (0x00001000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHGDET_DPDMSW_SHIFT             (0x0000000CU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHGDET_DPDMSW_MAX               (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW0EN_MASK                 (0x00000800U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW0EN_SHIFT                (0x0000000BU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW0EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW1EN_MASK                 (0x00000400U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW1EN_SHIFT                (0x0000000AU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DPSW1EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW0EN_MASK                 (0x00000200U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW0EN_SHIFT                (0x00000009U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW0EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW1EN_MASK                 (0x00000100U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW1EN_SHIFT                (0x00000008U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_CHGDET_DMSW1EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED7_MASK                          (0x00000080U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED7_SHIFT                         (0x00000007U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED7_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPDCHGDETEN_MASK                  (0x00000040U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPDCHGDETEN_SHIFT                 (0x00000006U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPDCHGDETEN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPDCHGDETEN_MASK                  (0x00000020U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPDCHGDETEN_SHIFT                 (0x00000005U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPDCHGDETEN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPUCHGDETEN_MASK                  (0x00000010U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPUCHGDETEN_SHIFT                 (0x00000004U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDPPUCHGDETEN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPUCHGDETEN_MASK                  (0x00000008U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPUCHGDETEN_SHIFT                 (0x00000003U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_RDMPUCHGDETEN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PU_REG_MASK             (0x00000004U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PU_REG_SHIFT            (0x00000002U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PU_REG_MAX              (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PD_REG_MASK             (0x00000002U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PD_REG_SHIFT            (0x00000001U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_MEM_USE_CHG_DET_PD_REG_MAX              (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED0_MASK                          (0x00000001U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED0_SHIFT                         (0x00000000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RESERVED0_MAX                           (0x00000001U)

/* CHRG_DET */

#define CSL_USB3_PHY2_CHRG_DET_RESERVED31_30_MASK                              (0xC0000000U)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED31_30_SHIFT                             (0x0000001EU)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED31_30_MAX                               (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_USE_CHG_DET_REG_MASK                        (0x20000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_USE_CHG_DET_REG_SHIFT                       (0x0000001DU)
#define CSL_USB3_PHY2_CHRG_DET_MEM_USE_CHG_DET_REG_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_DIS_CHG_DET_MASK                            (0x10000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_DIS_CHG_DET_SHIFT                           (0x0000001CU)
#define CSL_USB3_PHY2_CHRG_DET_MEM_DIS_CHG_DET_MAX                             (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_SRC_ON_DM_MASK                              (0x08000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_SRC_ON_DM_SHIFT                             (0x0000001BU)
#define CSL_USB3_PHY2_CHRG_DET_MEM_SRC_ON_DM_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_SINK_ON_DP_MASK                             (0x04000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_SINK_ON_DP_SHIFT                            (0x0000001AU)
#define CSL_USB3_PHY2_CHRG_DET_MEM_SINK_ON_DP_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_EXT_CTL_MASK                        (0x02000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_EXT_CTL_SHIFT                       (0x00000019U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_EXT_CTL_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_RESTART_CHG_DET_MASK                        (0x01000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_RESTART_CHG_DET_SHIFT                       (0x00000018U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_RESTART_CHG_DET_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_CHG_DET_DONE_MASK                               (0x00800000U)
#define CSL_USB3_PHY2_CHRG_DET_CHG_DET_DONE_SHIFT                              (0x00000017U)
#define CSL_USB3_PHY2_CHRG_DET_CHG_DET_DONE_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_CHG_DETECTED_MASK                               (0x00400000U)
#define CSL_USB3_PHY2_CHRG_DET_CHG_DETECTED_SHIFT                              (0x00000016U)
#define CSL_USB3_PHY2_CHRG_DET_CHG_DETECTED_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_DATA_DET_MASK                                   (0x00200000U)
#define CSL_USB3_PHY2_CHRG_DET_DATA_DET_SHIFT                                  (0x00000015U)
#define CSL_USB3_PHY2_CHRG_DET_DATA_DET_MAX                                    (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_RESERVED20_19_MASK                              (0x00180000U)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED20_19_SHIFT                             (0x00000013U)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED20_19_MAX                               (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_ISINK_EN_MASK                           (0x00040000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_ISINK_EN_SHIFT                          (0x00000012U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_ISINK_EN_MAX                            (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_VSRC_EN_MASK                            (0x00020000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_VSRC_EN_SHIFT                           (0x00000011U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_VSRC_EN_MAX                             (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_COMP_DP_MASK                                    (0x00010000U)
#define CSL_USB3_PHY2_CHRG_DET_COMP_DP_SHIFT                                   (0x00000010U)
#define CSL_USB3_PHY2_CHRG_DET_COMP_DP_MAX                                     (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_COMP_DM_MASK                                    (0x00008000U)
#define CSL_USB3_PHY2_CHRG_DET_COMP_DM_SHIFT                                   (0x0000000FU)
#define CSL_USB3_PHY2_CHRG_DET_COMP_DM_MAX                                     (0x00000001U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_OSC_CNTRL_MASK                      (0x00006000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_OSC_CNTRL_SHIFT                     (0x0000000DU)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_OSC_CNTRL_MAX                       (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_TIMER_MASK                          (0x00001F80U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_TIMER_SHIFT                         (0x00000007U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_TIMER_MAX                           (0x0000003FU)

#define CSL_USB3_PHY2_CHRG_DET_RESERVED6_5_MASK                                (0x00000060U)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED6_5_SHIFT                               (0x00000005U)
#define CSL_USB3_PHY2_CHRG_DET_RESERVED6_5_MAX                                 (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_ICTRL_MASK                          (0x00000018U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_ICTRL_SHIFT                         (0x00000003U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_ICTRL_MAX                           (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_VCTRL_MASK                          (0x00000006U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_VCTRL_SHIFT                         (0x00000001U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_CHG_DET_VCTRL_MAX                           (0x00000003U)

#define CSL_USB3_PHY2_CHRG_DET_MEM_FOR_CE_MASK                                 (0x00000001U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_FOR_CE_SHIFT                                (0x00000000U)
#define CSL_USB3_PHY2_CHRG_DET_MEM_FOR_CE_MAX                                  (0x00000001U)

/* PWR_CNTL */

#define CSL_USB3_PHY2_PWR_CNTL_RESETDONETCLK_MASK                              (0x80000000U)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONETCLK_SHIFT                             (0x0000001FU)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONETCLK_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_RESET_DONE_VMAIN_MASK                           (0x40000000U)
#define CSL_USB3_PHY2_PWR_CNTL_RESET_DONE_VMAIN_SHIFT                          (0x0000001EU)
#define CSL_USB3_PHY2_PWR_CNTL_RESET_DONE_VMAIN_MAX                            (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_VMAIN_GLOBAL_RESET_DONE_MASK                    (0x20000000U)
#define CSL_USB3_PHY2_PWR_CNTL_VMAIN_GLOBAL_RESET_DONE_SHIFT                   (0x0000001DU)
#define CSL_USB3_PHY2_PWR_CNTL_VMAIN_GLOBAL_RESET_DONE_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_RESETDONEMCLK_MASK                              (0x10000000U)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONEMCLK_SHIFT                             (0x0000001CU)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONEMCLK_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_RESETDONE_CHGDET_MASK                           (0x08000000U)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONE_CHGDET_SHIFT                          (0x0000001BU)
#define CSL_USB3_PHY2_PWR_CNTL_RESETDONE_CHGDET_MAX                            (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_LDOPWRCOUNTER_MASK                          (0x07FFF000U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_LDOPWRCOUNTER_SHIFT                         (0x0000000CU)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_LDOPWRCOUNTER_MAX                           (0x00007FFFU)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLSLOWCLK_MASK                        (0x00000800U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLSLOWCLK_SHIFT                       (0x0000000BU)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLSLOWCLK_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCELDOON_MASK                             (0x00000400U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCELDOON_SHIFT                            (0x0000000AU)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCELDOON_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLON_MASK                             (0x00000200U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLON_SHIFT                            (0x00000009U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_FORCEPLLON_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_RESERVED8_7_MASK                                (0x00000180U)
#define CSL_USB3_PHY2_PWR_CNTL_RESERVED8_7_SHIFT                               (0x00000007U)
#define CSL_USB3_PHY2_PWR_CNTL_RESERVED8_7_MAX                                 (0x00000003U)

#define CSL_USB3_PHY2_PWR_CNTL_PLLLOCK_MASK                                    (0x00000040U)
#define CSL_USB3_PHY2_PWR_CNTL_PLLLOCK_SHIFT                                   (0x00000006U)
#define CSL_USB3_PHY2_PWR_CNTL_PLLLOCK_MAX                                     (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_USEPLLLOCK_MASK                             (0x00000020U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USEPLLLOCK_SHIFT                            (0x00000005U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USEPLLLOCK_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_DATAPOLARITYN_REG_MASK                  (0x00000010U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_DATAPOLARITYN_REG_SHIFT                 (0x00000004U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_DATAPOLARITYN_REG_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_DATAPOLARITYN_MASK                          (0x00000008U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_DATAPOLARITYN_SHIFT                         (0x00000003U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_DATAPOLARITYN_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_PD_REG_MASK                             (0x00000004U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_PD_REG_SHIFT                            (0x00000002U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_USE_PD_REG_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_MEM_PD_MASK                                     (0x00000002U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_PD_SHIFT                                    (0x00000001U)
#define CSL_USB3_PHY2_PWR_CNTL_MEM_PD_MAX                                      (0x00000001U)

#define CSL_USB3_PHY2_PWR_CNTL_RESERVED1_MASK                                  (0x00000001U)
#define CSL_USB3_PHY2_PWR_CNTL_RESERVED1_SHIFT                                 (0x00000000U)
#define CSL_USB3_PHY2_PWR_CNTL_RESERVED1_MAX                                   (0x00000001U)

/* UTMI_INTERFACE_CNTL_1 */

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEUTMIDATAREG_MASK            (0x80000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEUTMIDATAREG_SHIFT           (0x0000001FU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEUTMIDATAREG_MAX             (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIDATAIN_MASK                (0x7FFF8000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIDATAIN_SHIFT               (0x0000000FU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIDATAIN_MAX                 (0x0000FFFFU)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_RESERVED_MASK                      (0x00004000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_RESERVED_SHIFT                     (0x0000000EU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_RESERVED_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEDATABUSREG_MASK             (0x00002000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEDATABUSREG_SHIFT            (0x0000000DU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEDATABUSREG_MAX              (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_DATABUS16OR8_MASK              (0x00001000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_DATABUS16OR8_SHIFT             (0x0000000CU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_DATABUS16OR8_MAX               (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEOPMODEREG_MASK              (0x00000800U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEOPMODEREG_SHIFT             (0x0000000BU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USEOPMODEREG_MAX               (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OPMODE_MASK                    (0x00000600U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OPMODE_SHIFT                   (0x00000009U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OPMODE_MAX                     (0x00000003U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDESUSRESET_MASK          (0x00000100U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDESUSRESET_SHIFT         (0x00000008U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDESUSRESET_MAX           (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_SUSPENDM_MASK                  (0x00000080U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_SUSPENDM_SHIFT                 (0x00000007U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_SUSPENDM_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIRESET_MASK                 (0x00000040U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIRESET_SHIFT                (0x00000006U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_UTMIRESET_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDEXCVRSEL_MASK           (0x00000020U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDEXCVRSEL_SHIFT          (0x00000005U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_OVERRIDEXCVRSEL_MAX            (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_XCVRSEL_MASK                   (0x00000018U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_XCVRSEL_SHIFT                  (0x00000003U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_XCVRSEL_MAX                    (0x00000003U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USETXVALIDREG_MASK             (0x00000004U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USETXVALIDREG_SHIFT            (0x00000002U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_USETXVALIDREG_MAX              (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALID_MASK                   (0x00000002U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALID_SHIFT                  (0x00000001U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALID_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALIDH_MASK                  (0x00000001U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALIDH_SHIFT                 (0x00000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_1_MEM_TXVALIDH_MAX                   (0x00000001U)

/* UTMI_INTERFACE_CNTL_2 */

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXRCV_MASK                         (0x80000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXRCV_SHIFT                        (0x0000001FU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXRCV_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDP_MASK                          (0x40000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDP_SHIFT                         (0x0000001EU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDP_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDM_MASK                          (0x20000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDM_SHIFT                         (0x0000001DU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXDM_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_HOSTDISCONNECT_MASK                (0x10000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_HOSTDISCONNECT_SHIFT               (0x0000001CU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_HOSTDISCONNECT_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_LINESTATE_MASK                     (0x0C000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_LINESTATE_SHIFT                    (0x0000001AU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_LINESTATE_MAX                      (0x00000003U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALID_MASK                       (0x02000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALID_SHIFT                      (0x00000019U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALID_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALIDH_MASK                      (0x01000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALIDH_SHIFT                     (0x00000018U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXVALIDH_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXACTIVE_MASK                      (0x00800000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXACTIVE_SHIFT                     (0x00000017U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXACTIVE_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXERROR_MASK                       (0x00400000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXERROR_SHIFT                      (0x00000016U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RXERROR_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_TXREADY_MASK                       (0x00200000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_TXREADY_SHIFT                      (0x00000015U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_TXREADY_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_UTMIRESETDONE_MASK                 (0x00100000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_UTMIRESETDONE_SHIFT                (0x00000014U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_UTMIRESETDONE_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEBITSTUFFREG_MASK            (0x00080000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEBITSTUFFREG_SHIFT           (0x00000013U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEBITSTUFFREG_MAX             (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLE_MASK          (0x00040000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLE_SHIFT         (0x00000012U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLE_MAX           (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLEH_MASK         (0x00020000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLEH_SHIFT        (0x00000011U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXBITSTUFFENABLEH_MAX          (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USETERMCONTROLREG_MASK         (0x00010000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USETERMCONTROLREG_SHIFT        (0x00000010U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USETERMCONTROLREG_MAX          (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TERMSEL_MASK                   (0x00008000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TERMSEL_SHIFT                  (0x0000000FU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TERMSEL_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DPPULLDOWN_MASK                (0x00004000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DPPULLDOWN_SHIFT               (0x0000000EU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DPPULLDOWN_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DMPULLDOWN_MASK                (0x00002000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DMPULLDOWN_SHIFT               (0x0000000DU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_DMPULLDOWN_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED12_10_MASK                 (0x00001C00U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED12_10_SHIFT                (0x0000000AU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED12_10_MAX                  (0x00000007U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEREGSERIALMODE_MASK          (0x00000200U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEREGSERIALMODE_SHIFT         (0x00000009U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_USEREGSERIALMODE_MAX           (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXSE0_MASK                     (0x00000100U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXSE0_SHIFT                    (0x00000008U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXSE0_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXDAT_MASK                     (0x00000080U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXDAT_SHIFT                    (0x00000007U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXDAT_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_FSLSSERIALMODE_MASK            (0x00000040U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_FSLSSERIALMODE_SHIFT           (0x00000006U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_FSLSSERIALMODE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXENABLEN_MASK                 (0x00000020U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXENABLEN_SHIFT                (0x00000005U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_TXENABLEN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED4_1_MASK                   (0x0000001EU)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED4_1_SHIFT                  (0x00000001U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_RESERVED4_1_MAX                    (0x0000000FU)

#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_BYPASS_SUSPENDMPULSE_INCR_MASK (0x00000001U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_BYPASS_SUSPENDMPULSE_INCR_SHIFT (0x00000000U)
#define CSL_USB3_PHY2_UTMI_INTERFACE_CNTL_2_MEM_BYPASS_SUSPENDMPULSE_INCR_MAX  (0x00000001U)

/* BIST */

#define CSL_USB3_PHY2_BIST_MEM_BIST_START_MASK                                 (0x80000000U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_START_SHIFT                                (0x0000001FU)
#define CSL_USB3_PHY2_BIST_MEM_BIST_START_MAX                                  (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_REDUCED_SWING_MASK                              (0x40000000U)
#define CSL_USB3_PHY2_BIST_MEM_REDUCED_SWING_SHIFT                             (0x0000001EU)
#define CSL_USB3_PHY2_BIST_MEM_REDUCED_SWING_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_BIST_CRC_CALC_EN_MASK                           (0x20000000U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_CRC_CALC_EN_SHIFT                          (0x0000001DU)
#define CSL_USB3_PHY2_BIST_MEM_BIST_CRC_CALC_EN_MAX                            (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_MASK                            (0x1FF00000U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_SHIFT                           (0x00000014U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_MAX                             (0x000001FFU)

#define CSL_USB3_PHY2_BIST_MEM_LOOPBACK_EN_MASK                                (0x00080000U)
#define CSL_USB3_PHY2_BIST_MEM_LOOPBACK_EN_SHIFT                               (0x00000013U)
#define CSL_USB3_PHY2_BIST_MEM_LOOPBACK_EN_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_BIST_OP_PHASE_SEL_MASK                          (0x00070000U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_OP_PHASE_SEL_SHIFT                         (0x00000010U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_OP_PHASE_SEL_MAX                           (0x00000007U)

#define CSL_USB3_PHY2_BIST_MEM_SWEEP_EN_MASK                                   (0x00008000U)
#define CSL_USB3_PHY2_BIST_MEM_SWEEP_EN_SHIFT                                  (0x0000000FU)
#define CSL_USB3_PHY2_BIST_MEM_SWEEP_EN_MAX                                    (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_SWEEP_MODE_MASK                                 (0x00007000U)
#define CSL_USB3_PHY2_BIST_MEM_SWEEP_MODE_SHIFT                                (0x0000000CU)
#define CSL_USB3_PHY2_BIST_MEM_SWEEP_MODE_MAX                                  (0x00000007U)

#define CSL_USB3_PHY2_BIST_BIST_PASS_MASK                                      (0x00000800U)
#define CSL_USB3_PHY2_BIST_BIST_PASS_SHIFT                                     (0x0000000BU)
#define CSL_USB3_PHY2_BIST_BIST_PASS_MAX                                       (0x00000001U)

#define CSL_USB3_PHY2_BIST_BIST_BUSY_MASK                                      (0x00000400U)
#define CSL_USB3_PHY2_BIST_BIST_BUSY_SHIFT                                     (0x0000000AU)
#define CSL_USB3_PHY2_BIST_BIST_BUSY_MAX                                       (0x00000001U)

#define CSL_USB3_PHY2_BIST_RESERVED_MASK                                       (0x00000300U)
#define CSL_USB3_PHY2_BIST_RESERVED_SHIFT                                      (0x00000008U)
#define CSL_USB3_PHY2_BIST_RESERVED_MAX                                        (0x00000003U)

#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_LSB_MASK                        (0x00000080U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_LSB_SHIFT                       (0x00000007U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_PKT_LENGTH_LSB_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_BIST_OPCODE_MASK                                (0x00000060U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_OPCODE_SHIFT                               (0x00000005U)
#define CSL_USB3_PHY2_BIST_MEM_BIST_OPCODE_MAX                                 (0x00000003U)

#define CSL_USB3_PHY2_BIST_MEM_RX_TEST_MODE_MASK                               (0x00000010U)
#define CSL_USB3_PHY2_BIST_MEM_RX_TEST_MODE_SHIFT                              (0x00000004U)
#define CSL_USB3_PHY2_BIST_MEM_RX_TEST_MODE_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_USE_BISTDATA_MASK                               (0x00000008U)
#define CSL_USB3_PHY2_BIST_MEM_USE_BISTDATA_SHIFT                              (0x00000003U)
#define CSL_USB3_PHY2_BIST_MEM_USE_BISTDATA_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_INTER_PKT_DELAY_TEST_MASK                       (0x00000004U)
#define CSL_USB3_PHY2_BIST_MEM_INTER_PKT_DELAY_TEST_SHIFT                      (0x00000002U)
#define CSL_USB3_PHY2_BIST_MEM_INTER_PKT_DELAY_TEST_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_HS_ALL_ONES_TEST_MASK                           (0x00000002U)
#define CSL_USB3_PHY2_BIST_MEM_HS_ALL_ONES_TEST_SHIFT                          (0x00000001U)
#define CSL_USB3_PHY2_BIST_MEM_HS_ALL_ONES_TEST_MAX                            (0x00000001U)

#define CSL_USB3_PHY2_BIST_MEM_USE_BIST_TX_PHASES_MASK                         (0x00000001U)
#define CSL_USB3_PHY2_BIST_MEM_USE_BIST_TX_PHASES_SHIFT                        (0x00000000U)
#define CSL_USB3_PHY2_BIST_MEM_USE_BIST_TX_PHASES_MAX                          (0x00000001U)

/* BIST_CRC */

#define CSL_USB3_PHY2_BIST_CRC_MEM_BIST_CRC_MASK                               (0xFFFFFFFFU)
#define CSL_USB3_PHY2_BIST_CRC_MEM_BIST_CRC_SHIFT                              (0x00000000U)
#define CSL_USB3_PHY2_BIST_CRC_MEM_BIST_CRC_MAX                                (0xFFFFFFFFU)

/* CDR_BIST2 */

#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_EN_MASK                            (0x80000000U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_EN_SHIFT                           (0x0000001FU)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_EN_MAX                             (0x00000001U)

#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_MODE_MASK                          (0x70000000U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_MODE_SHIFT                         (0x0000001CU)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_CDR_EXE_MODE_MAX                           (0x00000007U)

#define CSL_USB3_PHY2_CDR_BIST2_MEM_NUM_DECISIONS_MASK                         (0x0E000000U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_NUM_DECISIONS_SHIFT                        (0x00000019U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_NUM_DECISIONS_MAX                          (0x00000007U)

#define CSL_USB3_PHY2_CDR_BIST2_RESERVED_MASK                                  (0x01FFF000U)
#define CSL_USB3_PHY2_CDR_BIST2_RESERVED_SHIFT                                 (0x0000000CU)
#define CSL_USB3_PHY2_CDR_BIST2_RESERVED_MAX                                   (0x00001FFFU)

#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_START_ADDR_MASK                       (0x00000FC0U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_START_ADDR_SHIFT                      (0x00000006U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_START_ADDR_MAX                        (0x0000003FU)

#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_END_ADDR_MASK                         (0x0000003FU)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_END_ADDR_SHIFT                        (0x00000000U)
#define CSL_USB3_PHY2_CDR_BIST2_MEM_BIST_END_ADDR_MAX                          (0x0000003FU)

/* GPIO */

#define CSL_USB3_PHY2_GPIO_MEM_USEGPIOMODEREG_MASK                             (0x80000000U)
#define CSL_USB3_PHY2_GPIO_MEM_USEGPIOMODEREG_SHIFT                            (0x0000001FU)
#define CSL_USB3_PHY2_GPIO_MEM_USEGPIOMODEREG_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_GPIOMODE_MASK                                   (0x40000000U)
#define CSL_USB3_PHY2_GPIO_MEM_GPIOMODE_SHIFT                                  (0x0000001EU)
#define CSL_USB3_PHY2_GPIO_MEM_GPIOMODE_MAX                                    (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOGZ_MASK                                   (0x20000000U)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOGZ_SHIFT                                  (0x0000001DU)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOGZ_MAX                                    (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOGZ_MASK                                   (0x10000000U)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOGZ_SHIFT                                  (0x0000001CU)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOGZ_MAX                                    (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOA_MASK                                    (0x08000000U)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOA_SHIFT                                   (0x0000001BU)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOA_MAX                                     (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOA_MASK                                    (0x04000000U)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOA_SHIFT                                   (0x0000001AU)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOA_MAX                                     (0x00000001U)

#define CSL_USB3_PHY2_GPIO_DPGPIOY_MASK                                        (0x02000000U)
#define CSL_USB3_PHY2_GPIO_DPGPIOY_SHIFT                                       (0x00000019U)
#define CSL_USB3_PHY2_GPIO_DPGPIOY_MAX                                         (0x00000001U)

#define CSL_USB3_PHY2_GPIO_DMGPIOY_MASK                                        (0x01000000U)
#define CSL_USB3_PHY2_GPIO_DMGPIOY_SHIFT                                       (0x00000018U)
#define CSL_USB3_PHY2_GPIO_DMGPIOY_MAX                                         (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_GPIO1P8VCONFIG_MASK                             (0x00800000U)
#define CSL_USB3_PHY2_GPIO_MEM_GPIO1P8VCONFIG_SHIFT                            (0x00000017U)
#define CSL_USB3_PHY2_GPIO_MEM_GPIO1P8VCONFIG_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_GPIOCONFIG_MASK                                 (0x00700000U)
#define CSL_USB3_PHY2_GPIO_MEM_GPIOCONFIG_SHIFT                                (0x00000014U)
#define CSL_USB3_PHY2_GPIO_MEM_GPIOCONFIG_MAX                                  (0x00000007U)

#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOPIPD_MASK                                 (0x00080000U)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOPIPD_SHIFT                                (0x00000013U)
#define CSL_USB3_PHY2_GPIO_MEM_DMGPIOPIPD_MAX                                  (0x00000001U)

#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOPIPD_MASK                                 (0x00040000U)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOPIPD_SHIFT                                (0x00000012U)
#define CSL_USB3_PHY2_GPIO_MEM_DPGPIOPIPD_MAX                                  (0x00000001U)

#define CSL_USB3_PHY2_GPIO_RESERVED_MASK                                       (0x0003FFFFU)
#define CSL_USB3_PHY2_GPIO_RESERVED_SHIFT                                      (0x00000000U)
#define CSL_USB3_PHY2_GPIO_RESERVED_MAX                                        (0x0003FFFFU)

/* USB2PHYCM_TRIM */

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USEBGTRIM_MASK                        (0x80000000U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USEBGTRIM_SHIFT                       (0x0000001FU)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USEBGTRIM_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_BGTRIM_MASK                           (0x7FFF0000U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_BGTRIM_SHIFT                          (0x00000010U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_BGTRIM_MAX                            (0x00007FFFU)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED15_14_MASK                        (0x0000C000U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED15_14_SHIFT                       (0x0000000EU)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED15_14_MAX                         (0x00000003U)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USECURTRIM_MASK                       (0x00002000U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USECURTRIM_SHIFT                      (0x0000000DU)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_USECURTRIM_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_CURTRIM_MASK                          (0x00001F00U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_CURTRIM_SHIFT                         (0x00000008U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_MEM_CURTRIM_MAX                           (0x0000001FU)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED7_3_MASK                          (0x000000F8U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED7_3_SHIFT                         (0x00000003U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED7_3_MAX                           (0x0000001FU)

#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED2_0_MASK                          (0x00000007U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED2_0_SHIFT                         (0x00000000U)
#define CSL_USB3_PHY2_USB2PHYCM_TRIM_RESERVED2_0_MAX                           (0x00000007U)

/* USB2PHYCM_CONFIG */

#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_CONFIGURECM_MASK                    (0xFF000000U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_CONFIGURECM_SHIFT                   (0x00000018U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_CONFIGURECM_MAX                     (0x000000FFU)

#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_RESERVED_MASK                           (0x00FC0000U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_RESERVED_SHIFT                          (0x00000012U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_RESERVED_MAX                            (0x0000003FU)

#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_LDOCONFIG_MASK                      (0x0003FFFCU)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_LDOCONFIG_SHIFT                     (0x00000002U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_MEM_LDOCONFIG_MAX                       (0x0000FFFFU)

#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_LDOSTATUS_MASK                          (0x00000003U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_LDOSTATUS_SHIFT                         (0x00000000U)
#define CSL_USB3_PHY2_USB2PHYCM_CONFIG_LDOSTATUS_MAX                           (0x00000003U)

/* USBOTG */

#define CSL_USB3_PHY2_USBOTG_MEM_TESTOTGCONFIG_MASK                            (0xFFFF0000U)
#define CSL_USB3_PHY2_USBOTG_MEM_TESTOTGCONFIG_SHIFT                           (0x00000010U)
#define CSL_USB3_PHY2_USBOTG_MEM_TESTOTGCONFIG_MAX                             (0x0000FFFFU)

#define CSL_USB3_PHY2_USBOTG_TESTOTGSTATUS_MASK                                (0x0000FFC0U)
#define CSL_USB3_PHY2_USBOTG_TESTOTGSTATUS_SHIFT                               (0x00000006U)
#define CSL_USB3_PHY2_USBOTG_TESTOTGSTATUS_MAX                                 (0x000003FFU)

#define CSL_USB3_PHY2_USBOTG_RESERVED_MASK                                     (0x0000003FU)
#define CSL_USB3_PHY2_USBOTG_RESERVED_SHIFT                                    (0x00000000U)
#define CSL_USB3_PHY2_USBOTG_RESERVED_MAX                                      (0x0000003FU)

/* AD_INTERFACE_REG1 */

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_AD_DATA_REG_MASK               (0x80000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_AD_DATA_REG_SHIFT              (0x0000001FU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_AD_DATA_REG_MAX                (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_DATA_MASK                    (0x40000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_DATA_SHIFT                   (0x0000001EU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_DATA_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_TX_DATA_MASK                    (0x20000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_TX_DATA_SHIFT                   (0x0000001DU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_TX_DATA_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_PRE_EN_CNTRL_MASK             (0x10000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_PRE_EN_CNTRL_SHIFT            (0x0000001CU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_PRE_EN_CNTRL_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_PRE_EN_MASK                     (0x08000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_PRE_EN_SHIFT                    (0x0000001BU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_PRE_EN_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_PRE_EN_MASK                  (0x04000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_PRE_EN_SHIFT                 (0x0000001AU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_PRE_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_PRE_EN_MASK                  (0x02000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_PRE_EN_SHIFT                 (0x00000019U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_PRE_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_EN_CNTRL_MASK                 (0x01000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_EN_CNTRL_SHIFT                (0x00000018U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_EN_CNTRL_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_EN_MASK                      (0x00800000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_EN_SHIFT                     (0x00000017U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_TX_EN_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_RX_EN_MASK                      (0x00400000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_RX_EN_SHIFT                     (0x00000016U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FS_RX_EN_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED21_MASK                        (0x00200000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED21_SHIFT                       (0x00000015U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED21_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_EN_MASK                         (0x00100000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_EN_SHIFT                        (0x00000014U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_EN_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_EN_MASK                      (0x00080000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_EN_SHIFT                     (0x00000013U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_RX_EN_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_HS_MODE_MASK                  (0x00040000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_HS_MODE_SHIFT                 (0x00000012U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_HS_MODE_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_HV_SW_MASK                      (0x00020000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_HV_SW_SHIFT                     (0x00000011U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_HV_SW_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_CHIRP_MASK                      (0x00010000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_CHIRP_SHIFT                     (0x00000010U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_HS_CHIRP_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_FS_MODE_MASK                  (0x00008000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_FS_MODE_SHIFT                 (0x0000000FU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_FS_MODE_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_GZ_MASK                       (0x00004000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_GZ_SHIFT                      (0x0000000EU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_GZ_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_PRE_EN_MASK                   (0x00002000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_PRE_EN_SHIFT                  (0x0000000DU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_FSTX_PRE_EN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED12_MASK                        (0x00001000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED12_SHIFT                       (0x0000000CU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED12_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_SQ_CAL_CONTROL_MASK           (0x00000800U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_SQ_CAL_CONTROL_SHIFT          (0x0000000BU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_SQ_CAL_CONTROL_MAX            (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED_MASK                          (0x00000400U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED_SHIFT                         (0x0000000AU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN1_MASK                    (0x00000200U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN1_SHIFT                   (0x00000009U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN1_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN2_MASK                    (0x00000100U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN2_SHIFT                   (0x00000008U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_SQ_CAL_EN2_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_RTERM_CAL_CONTROL_MASK        (0x00000080U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_RTERM_CAL_CONTROL_SHIFT       (0x00000007U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_TEST_RTERM_CAL_CONTROL_MAX         (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_RTERM_CAL_EN_MASK                  (0x00000040U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_RTERM_CAL_EN_SHIFT                 (0x00000006U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_RTERM_CAL_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED5_MASK                         (0x00000020U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED5_SHIFT                        (0x00000005U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_RESERVED5_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_DISCON_DETECT_MASK                     (0x00000010U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_DISCON_DETECT_SHIFT                    (0x00000004U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_DISCON_DETECT_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_LSHOST_REG_MASK                (0x00000008U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_LSHOST_REG_SHIFT               (0x00000003U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_USE_LSHOST_REG_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_LSHOSTMODE_MASK                    (0x00000004U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_LSHOSTMODE_SHIFT                   (0x00000002U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_MEM_LSHOSTMODE_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_LSFS_RX_DATA_MASK                      (0x00000002U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_LSFS_RX_DATA_SHIFT                     (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_LSFS_RX_DATA_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG1_SQUELCH_MASK                           (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_SQUELCH_SHIFT                          (0x00000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG1_SQUELCH_MAX                            (0x00000001U)

/* AD_INTERFACE_REG2 */

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_SUSP_DRV_REG_MASK              (0x80000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_SUSP_DRV_REG_SHIFT             (0x0000001FU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_SUSP_DRV_REG_MAX               (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_DATA_MASK               (0x40000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_DATA_SHIFT              (0x0000001EU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_DATA_MAX                (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_EN_MASK                 (0x20000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_EN_SHIFT                (0x0000001DU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DP_EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_DATA_MASK               (0x10000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_DATA_SHIFT              (0x0000001CU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_DATA_MAX                (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_EN_MASK                 (0x08000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_EN_SHIFT                (0x0000001BU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SUS_DRV_DM_EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_DISCON_REG_MASK                (0x04000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_DISCON_REG_SHIFT               (0x0000001AU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_DISCON_REG_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_EN_MASK                     (0x02000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_EN_SHIFT                    (0x00000019U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_EN_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_PRE_EN_MASK                 (0x01000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_PRE_EN_SHIFT                (0x00000018U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DISCON_PRE_EN_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_RESERVED_MASK                          (0x00800000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_RESERVED_SHIFT                         (0x00000017U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_RESERVED_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SPARE_OUT_CORE_MASK                    (0x007C0000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SPARE_OUT_CORE_SHIFT                   (0x00000012U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SPARE_OUT_CORE_MAX                     (0x0000001FU)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DP_CORE_MASK                      (0x00020000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DP_CORE_SHIFT                     (0x00000011U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DP_CORE_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DM_CORE_MASK                      (0x00010000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DM_CORE_SHIFT                     (0x00000010U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_SERX_DM_CORE_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_HSRX_CAL_EN_REG_MASK           (0x00008000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_HSRX_CAL_EN_REG_SHIFT          (0x0000000FU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_HSRX_CAL_EN_REG_MAX            (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_HSRX_CAL_EN_MASK                   (0x00004000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_HSRX_CAL_EN_SHIFT                  (0x0000000EU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_HSRX_CAL_EN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_RPU_RPD_REG_MASK               (0x00002000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_RPU_RPD_REG_SHIFT              (0x0000000DU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_USE_RPU_RPD_REG_MAX                (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW1_EN_CORE_MASK            (0x00001000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW1_EN_CORE_SHIFT           (0x0000000CU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW1_EN_CORE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW2_EN_CORE_MASK            (0x00000800U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW2_EN_CORE_SHIFT           (0x0000000BU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DP_SW2_EN_CORE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW1_EN_CORE_MASK            (0x00000400U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW1_EN_CORE_SHIFT           (0x0000000AU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW1_EN_CORE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW2_EN_CORE_MASK            (0x00000200U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW2_EN_CORE_SHIFT           (0x00000009U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_RPU_DM_SW2_EN_CORE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DP_PULLDOWN_EN_CORE_MASK           (0x00000100U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DP_PULLDOWN_EN_CORE_SHIFT          (0x00000008U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DP_PULLDOWN_EN_CORE_MAX            (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DM_PULLDOWN_EN_CORE_MASK           (0x00000080U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DM_PULLDOWN_EN_CORE_SHIFT          (0x00000007U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_DM_PULLDOWN_EN_CORE_MAX            (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_DP_DM_5V_SHORT_MASK                    (0x00000040U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_DP_DM_5V_SHORT_SHIFT                   (0x00000006U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_DP_DM_5V_SHORT_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SPARE_IN_CORE_MASK                 (0x0000003EU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SPARE_IN_CORE_SHIFT                (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_MEM_SPARE_IN_CORE_MAX                  (0x0000001FU)

#define CSL_USB3_PHY2_AD_INTERFACE_REG2_PORZ_MASK                              (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_PORZ_SHIFT                             (0x00000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG2_PORZ_MAX                               (0x00000001U)

/* AD_INTERFACE_REG3 */

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HSOS_DATA_REG_MASK             (0x80000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HSOS_DATA_REG_SHIFT            (0x0000001FU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HSOS_DATA_REG_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HSOS_DATA_MASK                     (0x7F800000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HSOS_DATA_SHIFT                    (0x00000017U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HSOS_DATA_MAX                      (0x000000FFU)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_FS_REG3_MASK                   (0x00400000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_FS_REG3_SHIFT                  (0x00000016U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_FS_REG3_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_MODE_MASK                     (0x00200000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_MODE_SHIFT                    (0x00000015U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_MODE_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_SE0_MASK                      (0x00100000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_SE0_SHIFT                     (0x00000014U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_FSTX_SE0_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HS_TERM_RES_REG_MASK           (0x00080000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HS_TERM_RES_REG_SHIFT          (0x00000013U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_USE_HS_TERM_RES_REG_MAX            (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HS_TERM_RES_MASK                   (0x00040000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HS_TERM_RES_SHIFT                  (0x00000012U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_HS_TERM_RES_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_SPARE_IN_LDO_MASK                  (0x0003FC00U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_SPARE_IN_LDO_SHIFT                 (0x0000000AU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_MEM_SPARE_IN_LDO_MAX                   (0x000000FFU)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_SPARE_OUT_LDO_MASK                     (0x000003FCU)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_SPARE_OUT_LDO_SHIFT                    (0x00000002U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_SPARE_OUT_LDO_MAX                      (0x000000FFU)

#define CSL_USB3_PHY2_AD_INTERFACE_REG3_RESERVED_MASK                          (0x00000003U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_RESERVED_SHIFT                         (0x00000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_REG3_RESERVED_MAX                           (0x00000003U)

/* ANA_CONFIG1 */

#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_SQ_CTRL_REG_MASK                         (0xFFFE0000U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_SQ_CTRL_REG_SHIFT                        (0x00000011U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_SQ_CTRL_REG_MAX                          (0x00007FFFU)

#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_FS_SLEW_MASK                             (0x0001C000U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_FS_SLEW_SHIFT                            (0x0000000EU)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_FS_SLEW_MAX                              (0x00000007U)

#define CSL_USB3_PHY2_ANA_CONFIG1_RESERVED_MASK                                (0x00003000U)
#define CSL_USB3_PHY2_ANA_CONFIG1_RESERVED_SHIFT                               (0x0000000CU)
#define CSL_USB3_PHY2_ANA_CONFIG1_RESERVED_MAX                                 (0x00000003U)

#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_HSTX_TEST_MASK                           (0x00000FE0U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_HSTX_TEST_SHIFT                          (0x00000005U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_HSTX_TEST_MAX                            (0x0000007FU)

#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_PROTECT_TEST_MASK                        (0x0000001FU)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_PROTECT_TEST_SHIFT                       (0x00000000U)
#define CSL_USB3_PHY2_ANA_CONFIG1_MEM_PROTECT_TEST_MAX                         (0x0000001FU)

/* ANA_CONFIG2 */

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_RTERM_CAL_TEST_MASK                      (0xF8000000U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_RTERM_CAL_TEST_SHIFT                     (0x0000001BU)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_RTERM_CAL_TEST_MAX                       (0x0000001FU)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_REF_GEN_TEST_MASK                        (0x07F00000U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_REF_GEN_TEST_SHIFT                       (0x00000014U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_REF_GEN_TEST_MAX                         (0x0000007FU)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_FSRX_TEST_MASK                           (0x000F8000U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_FSRX_TEST_SHIFT                          (0x0000000FU)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_FSRX_TEST_MAX                            (0x0000001FU)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_DISCON_TEST_MASK                         (0x00007800U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_DISCON_TEST_SHIFT                        (0x0000000BU)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_DISCON_TEST_MAX                          (0x0000000FU)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_HSRX_TEST_MASK                           (0x000007C0U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_HSRX_TEST_SHIFT                          (0x00000006U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_HSRX_TEST_MAX                            (0x0000001FU)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_TEST_MASK                           (0x00000038U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_TEST_SHIFT                          (0x00000003U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_TEST_MAX                            (0x00000007U)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_HYST_CNTRL_MASK                     (0x00000006U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_HYST_CNTRL_SHIFT                    (0x00000001U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SERX_HYST_CNTRL_MAX                      (0x00000003U)

#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SQ_LPMODEZ_MASK                          (0x00000001U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SQ_LPMODEZ_SHIFT                         (0x00000000U)
#define CSL_USB3_PHY2_ANA_CONFIG2_MEM_SQ_LPMODEZ_MAX                           (0x00000001U)

/* RX_CALIB_RD */

#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED31_21_MASK                           (0xFFE00000U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED31_21_SHIFT                          (0x00000015U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED31_21_MAX                            (0x000007FFU)

#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC1_MASK                        (0x001FC000U)
#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC1_SHIFT                       (0x0000000EU)
#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC1_MAX                         (0x0000007FU)

#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED13_MASK                              (0x00002000U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED13_SHIFT                             (0x0000000DU)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED13_MAX                               (0x00000001U)

#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC2_MASK                        (0x00001FC0U)
#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC2_SHIFT                       (0x00000006U)
#define CSL_USB3_PHY2_RX_CALIB_RD_SQ_OFF_CODE_DAC2_MAX                         (0x0000007FU)

#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED5_3_MASK                             (0x00000038U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED5_3_SHIFT                            (0x00000003U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED5_3_MAX                              (0x00000007U)

#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED2_0_MASK                             (0x00000007U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED2_0_SHIFT                            (0x00000000U)
#define CSL_USB3_PHY2_RX_CALIB_RD_RESERVED2_0_MAX                              (0x00000007U)

/* TX_TEST_CHRG_DET_RD */

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED31_20_MASK                   (0xFFF00000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED31_20_SHIFT                  (0x00000014U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED31_20_MAX                    (0x00000FFFU)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_DIS_CHG_DET_MASK                     (0x00080000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_DIS_CHG_DET_SHIFT                    (0x00000013U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_DIS_CHG_DET_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SRC_ON_DM_MASK                       (0x00040000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SRC_ON_DM_SHIFT                      (0x00000012U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SRC_ON_DM_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SINK_ON_DP_MASK                      (0x00020000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SINK_ON_DP_SHIFT                     (0x00000011U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_SINK_ON_DP_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_DET_EXT_CTL_MASK                 (0x00010000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_DET_EXT_CTL_SHIFT                (0x00000010U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_DET_EXT_CTL_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESTART_CHG_DET_MASK                 (0x00008000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESTART_CHG_DET_SHIFT                (0x0000000FU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESTART_CHG_DET_MAX                  (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_ISINK_EN_MASK                    (0x00004000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_ISINK_EN_SHIFT                   (0x0000000EU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_ISINK_EN_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_VSRC_EN_MASK                     (0x00002000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_VSRC_EN_SHIFT                    (0x0000000DU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHG_VSRC_EN_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED12_MASK                      (0x00001000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED12_SHIFT                     (0x0000000CU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED12_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW0EN_MASK                  (0x00000800U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW0EN_SHIFT                 (0x0000000BU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW0EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW1EN_MASK                  (0x00000400U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW1EN_SHIFT                 (0x0000000AU)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DPSW1EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW0EN_MASK                  (0x00000200U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW0EN_SHIFT                 (0x00000009U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW0EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW1EN_MASK                  (0x00000100U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW1EN_SHIFT                 (0x00000008U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_CHGDET_DMSW1EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED7_MASK                       (0x00000080U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED7_SHIFT                      (0x00000007U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED7_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPDCHGDETEN_MASK                   (0x00000040U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPDCHGDETEN_SHIFT                  (0x00000006U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPDCHGDETEN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPDCHGDETEN_MASK                   (0x00000020U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPDCHGDETEN_SHIFT                  (0x00000005U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPDCHGDETEN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPUCHGDETEN_MASK                   (0x00000010U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPUCHGDETEN_SHIFT                  (0x00000004U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDPPUCHGDETEN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPUCHGDETEN_MASK                   (0x00000008U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPUCHGDETEN_SHIFT                  (0x00000003U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RDMPUCHGDETEN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED3_0_MASK                     (0x00000007U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED3_0_SHIFT                    (0x00000000U)
#define CSL_USB3_PHY2_TX_TEST_CHRG_DET_RD_RESERVED3_0_MAX                      (0x00000007U)

/* BIST_CRC_READ */

#define CSL_USB3_PHY2_BIST_CRC_READ_BIST_CRC_MASK                              (0xFFFFFFFFU)
#define CSL_USB3_PHY2_BIST_CRC_READ_BIST_CRC_SHIFT                             (0x00000000U)
#define CSL_USB3_PHY2_BIST_CRC_READ_BIST_CRC_MAX                               (0xFFFFFFFFU)

/* GPIO_TRIM_RD */

#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED31_MASK                             (0x80000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED31_SHIFT                            (0x0000001FU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED31_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIOMODE_MASK                               (0x40000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIOMODE_SHIFT                              (0x0000001EU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIOMODE_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOGZ_MASK                               (0x20000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOGZ_SHIFT                              (0x0000001DU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOGZ_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOGZ_MASK                               (0x10000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOGZ_SHIFT                              (0x0000001CU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOGZ_MAX                                (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOA_MASK                                (0x08000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOA_SHIFT                               (0x0000001BU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOA_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOA_MASK                                (0x04000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOA_SHIFT                               (0x0000001AU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOA_MAX                                 (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED25_24_MASK                          (0x03000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED25_24_SHIFT                         (0x00000018U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED25_24_MAX                           (0x00000003U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIO1P8VCONFIG_MASK                         (0x00800000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIO1P8VCONFIG_SHIFT                        (0x00000017U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_GPIO1P8VCONFIG_MAX                          (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOPIPD_MASK                             (0x00400000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOPIPD_SHIFT                            (0x00000016U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DPGPIOPIPD_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOPIPD_MASK                             (0x00200000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOPIPD_SHIFT                            (0x00000015U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_DMGPIOPIPD_MAX                              (0x00000001U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED19_18_MASK                          (0x00180000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED19_18_SHIFT                         (0x00000013U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RESERVED19_18_MAX                           (0x00000003U)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_RPUTRIM_CODE_MASK                           (0x00078000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RPUTRIM_CODE_SHIFT                          (0x0000000FU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_RPUTRIM_CODE_MAX                            (0x0000000FU)

#define CSL_USB3_PHY2_GPIO_TRIM_RD_BGTRIM_MASK                                 (0x00007FFFU)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_BGTRIM_SHIFT                                (0x00000000U)
#define CSL_USB3_PHY2_GPIO_TRIM_RD_BGTRIM_MAX                                  (0x00007FFFU)

/* AD_INTERFACE_RD_REG1 */

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DM_PULLDOWN_EN_CORE_MASK            (0x80000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DM_PULLDOWN_EN_CORE_SHIFT           (0x0000001FU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DM_PULLDOWN_EN_CORE_MAX             (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_DATA_MASK                     (0x40000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_DATA_SHIFT                    (0x0000001EU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_DATA_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_TX_DATA_MASK                     (0x20000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_TX_DATA_SHIFT                    (0x0000001DU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_TX_DATA_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_DATA_MASK                (0x10000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_DATA_SHIFT               (0x0000001CU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_DATA_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_PRE_EN_MASK                      (0x08000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_PRE_EN_SHIFT                     (0x0000001BU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_PRE_EN_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_PRE_EN_MASK                   (0x04000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_PRE_EN_SHIFT                  (0x0000001AU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_PRE_EN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_PRE_EN_MASK                   (0x02000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_PRE_EN_SHIFT                  (0x00000019U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_PRE_EN_MAX                    (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_EN_MASK                  (0x01000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_EN_SHIFT                 (0x00000018U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DP_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_EN_MASK                       (0x00800000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_EN_SHIFT                      (0x00000017U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_TX_EN_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_RX_EN_MASK                       (0x00400000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_RX_EN_SHIFT                      (0x00000016U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FS_RX_EN_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_DATA_MASK                (0x00200000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_DATA_SHIFT               (0x00000015U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_DATA_MAX                 (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_EN_MASK                          (0x00100000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_EN_SHIFT                         (0x00000014U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_EN_MAX                           (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_EN_MASK                       (0x00080000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_EN_SHIFT                      (0x00000013U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_RX_EN_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_EN_MASK                  (0x00040000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_EN_SHIFT                 (0x00000012U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SUS_DRV_DM_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_HV_SW_MASK                       (0x00020000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_HV_SW_SHIFT                      (0x00000011U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_HV_SW_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_CHIRP_MASK                       (0x00010000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_CHIRP_SHIFT                      (0x00000010U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HS_CHIRP_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED15_MASK                     (0x00008000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED15_SHIFT                    (0x0000000FU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED15_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_GZ_MASK                        (0x00004000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_GZ_SHIFT                       (0x0000000EU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_GZ_MAX                         (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_PRE_EN_MASK                    (0x00002000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_PRE_EN_SHIFT                   (0x0000000DU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_FSTX_PRE_EN_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED12_MASK                     (0x00001000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED12_SHIFT                    (0x0000000CU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED12_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_EN_MASK                      (0x00000800U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_EN_SHIFT                     (0x0000000BU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_EN_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED10_MASK                     (0x00000400U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED10_SHIFT                    (0x0000000AU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RESERVED10_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN1_MASK                     (0x00000200U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN1_SHIFT                    (0x00000009U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN1_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN2_MASK                     (0x00000100U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN2_SHIFT                    (0x00000008U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_SQ_CAL_EN2_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_PRE_EN_MASK                  (0x00000080U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_PRE_EN_SHIFT                 (0x00000007U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DISCON_PRE_EN_MAX                   (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HSRX_CAL_EN_MASK                    (0x00000040U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HSRX_CAL_EN_SHIFT                   (0x00000006U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_HSRX_CAL_EN_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW1_EN_CORE_MASK             (0x00000020U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW1_EN_CORE_SHIFT            (0x00000005U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW1_EN_CORE_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW2_EN_CORE_MASK             (0x00000010U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW2_EN_CORE_SHIFT            (0x00000004U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DP_SW2_EN_CORE_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW1_EN_CORE_MASK             (0x00000008U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW1_EN_CORE_SHIFT            (0x00000003U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW1_EN_CORE_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_LSHOSTMODE_MASK                     (0x00000004U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_LSHOSTMODE_SHIFT                    (0x00000002U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_LSHOSTMODE_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW2_EN_CORE_MASK             (0x00000002U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW2_EN_CORE_SHIFT            (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_RPU_DM_SW2_EN_CORE_MAX              (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DP_PULLDOWN_EN_CORE_MASK            (0x00000001U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DP_PULLDOWN_EN_CORE_SHIFT           (0x00000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG1_DP_PULLDOWN_EN_CORE_MAX             (0x00000001U)

/* AD_INTERFACE_RD_REG3 */

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED31_MASK                     (0x80000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED31_SHIFT                    (0x0000001FU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED31_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HSOS_DATA_MASK                      (0x7F800000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HSOS_DATA_SHIFT                     (0x00000017U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HSOS_DATA_MAX                       (0x000000FFU)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED22_MASK                     (0x00400000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED22_SHIFT                    (0x00000016U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED22_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_MODE_MASK                      (0x00200000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_MODE_SHIFT                     (0x00000015U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_MODE_MAX                       (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_SE0_MASK                       (0x00100000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_SE0_SHIFT                      (0x00000014U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_FSTX_SE0_MAX                        (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED19_MASK                     (0x00080000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED19_SHIFT                    (0x00000013U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED19_MAX                      (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HS_TERM_RES_MASK                    (0x00040000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HS_TERM_RES_SHIFT                   (0x00000012U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_HS_TERM_RES_MAX                     (0x00000001U)

#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED_MASK                       (0x0003FFFFU)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED_SHIFT                      (0x00000000U)
#define CSL_USB3_PHY2_AD_INTERFACE_RD_REG3_RESERVED_MAX                        (0x0003FFFFU)

/* BIST_DATA1 */

#define CSL_USB3_PHY2_BIST_DATA1_MEM_BIST_DATA1_MASK                           (0xFFFFFFFFU)
#define CSL_USB3_PHY2_BIST_DATA1_MEM_BIST_DATA1_SHIFT                          (0x00000000U)
#define CSL_USB3_PHY2_BIST_DATA1_MEM_BIST_DATA1_MAX                            (0xFFFFFFFFU)

/* BIST_DATA2 */

#define CSL_USB3_PHY2_BIST_DATA2_MEM_BIST_DATA2_MASK                           (0xFFFFFFFFU)
#define CSL_USB3_PHY2_BIST_DATA2_MEM_BIST_DATA2_SHIFT                          (0x00000000U)
#define CSL_USB3_PHY2_BIST_DATA2_MEM_BIST_DATA2_MAX                            (0xFFFFFFFFU)

/* CEGPIO_REG */

#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED31_26_MASK                            (0xFC000000U)
#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED31_26_SHIFT                           (0x0000001AU)
#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED31_26_MAX                             (0x0000003FU)

#define CSL_USB3_PHY2_CEGPIO_REG_MEM_SE0DET_CNT_MASK                           (0x03FF0000U)
#define CSL_USB3_PHY2_CEGPIO_REG_MEM_SE0DET_CNT_SHIFT                          (0x00000010U)
#define CSL_USB3_PHY2_CEGPIO_REG_MEM_SE0DET_CNT_MAX                            (0x000003FFU)

#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED_MASK                                 (0x00007FC0U)
#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED_SHIFT                                (0x00000006U)
#define CSL_USB3_PHY2_CEGPIO_REG_RESERVED_MAX                                  (0x000001FFU)

#define CSL_USB3_PHY2_CEGPIO_REG_MEM_CE_SELECT_MASK                            (0x0000003FU)
#define CSL_USB3_PHY2_CEGPIO_REG_MEM_CE_SELECT_SHIFT                           (0x00000000U)
#define CSL_USB3_PHY2_CEGPIO_REG_MEM_CE_SELECT_MAX                             (0x0000003FU)

/**************************************************************************
* Register Group Macro : slv0
**************************************************************************/

typedef struct {
    CSL_usb3_gmodRegs                        gmod;
    volatile uint8_t                         Resv_32768[30952];
    CSL_usb3_ramdbgRegs                      ramdbg;
    CSL_usb3_capRegs                         cap;
    CSL_usb3_operRegs                        oper;
    volatile uint8_t                         Resv_66592[964];
    CSL_usb3_portRegs                        port;
    CSL_usb3_runtimeRegs                     runtime;
    volatile uint8_t                         Resv_66656[24];
    CSL_usb3_intrRegs                        intr;
    CSL_usb3_dbarrRegs                       dbarr;
    volatile uint8_t                         Resv_68192[768];
    CSL_usb3_extcapRegs                      extcap;
    volatile uint8_t                         Resv_68208[8];
    CSL_usb3_supprtcap2Regs                  supprtcap2;
    CSL_usb3_supprtcap3Regs                  supprtcap3;
    volatile uint8_t                         Resv_114944[46704];
    CSL_usb3_gblRegs                         gbl;
    volatile uint8_t                         Resv_116480[204];
    CSL_usb3_devRegs                         dev;
    volatile uint8_t                         Resv_117760[448];
    CSL_usb3_otgRegs                         otg;
    CSL_usb3_bcRegs                          bc;
} CSL_usb3_slv0;

/**************************************************************************
* Register Group Macro : slv0_rsel1
**************************************************************************/

typedef struct {
    CSL_usb3_ecc_aggrRegs                    ecc_aggr;
} CSL_usb3_slv0_rsel1;

/**************************************************************************
* Register Group Macro : slv1
**************************************************************************/

typedef struct {
    CSL_usb3_phy2Regs                        phy2;
} CSL_usb3_slv1;

#ifdef __cplusplus
}
#endif
#endif
