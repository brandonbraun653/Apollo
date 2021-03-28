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
#ifndef CSLR_DMM_CORE_H_
#define CSLR_DMM_CORE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
/**************************************************************************
* Register Overlay Structure for PAT_AREAS
**************************************************************************/
typedef struct {
    volatile Uint32 PAT_DESCR;
    volatile Uint32 PAT_AREA;
    volatile Uint32 PAT_CTRL;
    volatile Uint32 PAT_DATA;
} CSL_Dmm_corePat_areasRegs;


/**************************************************************************
* Register Overlay Structure for Trailer
**************************************************************************/
typedef struct {
    volatile Uint32 PEG_HWINFO;
    volatile Uint8  RSVD0[20];
    volatile Uint32 PEG_PRIO[8];
    volatile Uint32 PEG_PRIO_PAT;
} CSL_Dmm_coreTrailerRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint32 HWINFO;
    volatile Uint32 LISA_HWINFO;
    volatile Uint8  RSVD1[4];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD2[8];
    volatile Uint32 LISA_LOCK;
    volatile Uint32 EMERGENCY;
    volatile Uint8  RSVD3[28];
    volatile Uint32 LISA_MAP[4];
    volatile Uint8  RSVD4[440];
    volatile Uint32 TILER_HWINFO;
    volatile Uint8  RSVD5[20];
    volatile Uint32 TILER_OR[2];
    volatile Uint8  RSVD6[480];
    volatile Uint32 PAT_HWINFO;
    volatile Uint32 PAT_GEOMETRY;
    volatile Uint32 PAT_CONFIG;
    volatile Uint8  RSVD7[12];
    volatile Uint32 PAT_VIEW[2];
    volatile Uint8  RSVD8[24];
    volatile Uint32 PAT_VIEW_MAP[4];
    volatile Uint8  RSVD9[16];
    volatile Uint32 PAT_VIEW_MAP_BASE;
    volatile Uint8  RSVD10[20];
    volatile Uint32 PAT_IRQ_EOI;
    volatile Uint8  RSVD11[4];
    volatile Uint32 PAT_IRQSTS_RAW;
    volatile Uint8  RSVD12[12];
    volatile Uint32 PAT_IRQSTS;
    volatile Uint8  RSVD13[12];
    volatile Uint32 PAT_IRQEN_SET;
    volatile Uint8  RSVD14[12];
    volatile Uint32 PAT_IRQEN_CLR;
    volatile Uint8  RSVD15[12];
    volatile Uint32 PAT_STS[4];
    volatile Uint8  RSVD16[48];
    CSL_Dmm_corePat_areasRegs	PAT_AREAS[4];
    volatile Uint8  RSVD17[200];
    CSL_Dmm_coreTrailerRegs	TRAILER;
} CSL_DMM_CORERegs;




/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_DMM_CORE_REVISION                                   (0x0U)
#define CSL_DMM_CORE_HWINFO                                     (0x4U)
#define CSL_DMM_CORE_LISA_HWINFO                                (0x8U)
#define CSL_DMM_CORE_SYSCONFIG                                  (0x10U)
/* CSL Aliased modification for PRCM compatibility */
#define DMM_SYSCONFIG                    (CSL_DMM_CORE_SYSCONFIG)
#define CSL_DMM_CORE_LISA_LOCK                                  (0x1CU)
#define CSL_DMM_CORE_EMERGENCY                                  (0x20U)
#define CSL_DMM_CORE_LISA_MAP(i)                                (0x40U + ((i) * 4U))
#define CSL_DMM_CORE_TILER_HWINFO                               (0x208U)
#define CSL_DMM_CORE_TILER_OR(i)                                (0x220U + ((i) * 4U))
#define CSL_DMM_CORE_PAT_HWINFO                                 (0x408U)
#define CSL_DMM_CORE_PAT_GEOMETRY                               (0x40CU)
#define CSL_DMM_CORE_PAT_CONFIG                                 (0x410U)
#define CSL_DMM_CORE_PAT_VIEW(i)                                (0x420U + ((i) * 4U))
#define CSL_DMM_CORE_PAT_VIEW_MAP(i)                            (0x440U + ((i) * 4U))
#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE                          (0x460U)
#define CSL_DMM_CORE_PAT_IRQ_EOI                                (0x478U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW                             (0x480U)
#define CSL_DMM_CORE_PAT_IRQSTS                                 (0x490U)
#define CSL_DMM_CORE_PAT_IRQEN_SET                              (0x4A0U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR                              (0x4B0U)
#define CSL_DMM_CORE_PAT_STS(i)                                 (0x4C0U + ((i) * 4U))
#define CSL_DMM_CORE_PAT_DESCR(n)                               (0x500U + ((n) * 10U))
#define CSL_DMM_CORE_PAT_AREA(n)                                (0x504U + ((n) * 10U))
#define CSL_DMM_CORE_PAT_CTRL(n)                                (0x508U + ((n) * 10U))
#define CSL_DMM_CORE_PAT_DATA(n)                                (0x50CU + ((n) * 10U))
#define CSL_DMM_CORE_PEG_HWINFO                                 (0x608U)
#define CSL_DMM_CORE_PEG_PRIO(i)                                (0x620U + ((i) * 4U))
#define CSL_DMM_CORE_PEG_PRIO_PAT                               (0x640U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_DMM_CORE_REVISION_SCHEME_MASK                       (0xC0000000U)
#define CSL_DMM_CORE_REVISION_SCHEME_SHIFT                      (0x0000001EU)
#define CSL_DMM_CORE_REVISION_SCHEME_RESETVAL                   (0x00000001U)
#define CSL_DMM_CORE_REVISION_SCHEME_H08                        (0x00000001U)

#define CSL_DMM_CORE_REVISION_FUNC_MASK                         (0x0FFF0000U)
#define CSL_DMM_CORE_REVISION_FUNC_SHIFT                        (0x00000010U)
#define CSL_DMM_CORE_REVISION_FUNC_RESETVAL                     (0x00000000U)
#define CSL_DMM_CORE_REVISION_FUNC_MAX                          (0x00000fffU)

#define CSL_DMM_CORE_REVISION_R_RTL_MASK                        (0x0000F800U)
#define CSL_DMM_CORE_REVISION_R_RTL_SHIFT                       (0x0000000BU)
#define CSL_DMM_CORE_REVISION_R_RTL_RESETVAL                    (0x00000000U)
#define CSL_DMM_CORE_REVISION_R_RTL_MAX                         (0x0000001fU)

#define CSL_DMM_CORE_REVISION_X_MAJOR_MASK                      (0x00000700U)
#define CSL_DMM_CORE_REVISION_X_MAJOR_SHIFT                     (0x00000008U)
#define CSL_DMM_CORE_REVISION_X_MAJOR_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_REVISION_X_MAJOR_MAX                       (0x00000007U)

#define CSL_DMM_CORE_REVISION_CUSTOM_MASK                       (0x000000C0U)
#define CSL_DMM_CORE_REVISION_CUSTOM_SHIFT                      (0x00000006U)
#define CSL_DMM_CORE_REVISION_CUSTOM_RESETVAL                   (0x00000000U)
#define CSL_DMM_CORE_REVISION_CUSTOM_STD                        (0x00000000U)

#define CSL_DMM_CORE_REVISION_Y_MINOR_MASK                      (0x0000003FU)
#define CSL_DMM_CORE_REVISION_Y_MINOR_SHIFT                     (0x00000000U)
#define CSL_DMM_CORE_REVISION_Y_MINOR_RESETVAL                  (0x00000009U)
#define CSL_DMM_CORE_REVISION_Y_MINOR_MAX                       (0x0000003fU)

#define CSL_DMM_CORE_REVISION_RESETVAL                          (0x40000009U)

/* HWINFO */

#define CSL_DMM_CORE_HWINFO_ROBIN_CNT_MASK                      (0x000F0000U)
#define CSL_DMM_CORE_HWINFO_ROBIN_CNT_SHIFT                     (0x00000010U)
#define CSL_DMM_CORE_HWINFO_ROBIN_CNT_RESETVAL                  (0x00000002U)
#define CSL_DMM_CORE_HWINFO_ROBIN_CNT_MAX                       (0x0000000fU)

#define CSL_DMM_CORE_HWINFO_ELLA_CNT_MASK                       (0x00000F00U)
#define CSL_DMM_CORE_HWINFO_ELLA_CNT_SHIFT                      (0x00000008U)
#define CSL_DMM_CORE_HWINFO_ELLA_CNT_RESETVAL                   (0x00000000U)
#define CSL_DMM_CORE_HWINFO_ELLA_CNT_MAX                        (0x0000000fU)

#define CSL_DMM_CORE_HWINFO_TILER_CNT_MASK                      (0x0000000FU)
#define CSL_DMM_CORE_HWINFO_TILER_CNT_SHIFT                     (0x00000000U)
#define CSL_DMM_CORE_HWINFO_TILER_CNT_RESETVAL                  (0x00000002U)
#define CSL_DMM_CORE_HWINFO_TILER_CNT_MAX                       (0x0000000fU)

#define CSL_DMM_CORE_HWINFO_RESETVAL                            (0x00020002U)

/* LISA_HWINFO */

#define CSL_DMM_CORE_LISA_HWINFO_SDRC_CNT_MASK                  (0x00000F00U)
#define CSL_DMM_CORE_LISA_HWINFO_SDRC_CNT_SHIFT                 (0x00000008U)
#define CSL_DMM_CORE_LISA_HWINFO_SDRC_CNT_RESETVAL              (0x00000002U)
#define CSL_DMM_CORE_LISA_HWINFO_SDRC_CNT_MAX                   (0x0000000fU)

#define CSL_DMM_CORE_LISA_HWINFO_SECTION_CNT_MASK               (0x0000001FU)
#define CSL_DMM_CORE_LISA_HWINFO_SECTION_CNT_SHIFT              (0x00000000U)
#define CSL_DMM_CORE_LISA_HWINFO_SECTION_CNT_RESETVAL           (0x00000004U)
#define CSL_DMM_CORE_LISA_HWINFO_SECTION_CNT_MAX                (0x0000001fU)

#define CSL_DMM_CORE_LISA_HWINFO_RESETVAL                       (0x00000204U)

/* SYSCONFIG */

#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_MASK                   (0x0000000CU)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_SHIFT                  (0x00000002U)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_RESETVAL               (0x00000002U)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_SMART                  (0x00000002U)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_FORCE_IDLE             (0x00000000U)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_NO_IDLE                (0x00000001U)
#define CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_RESERVED3              (0x00000003U)

/* CSL Aliased modification for PRCM compatibility */
#define DMM_SYSCONFIG_IDLEMODE_SHIFT                     (CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_SHIFT)
#define DMM_SYSCONFIG_IDLEMODE_MASK                      (CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_MASK)
#define DMM_SYSCONFIG_IDLEMODE_SMART                     (CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_SMART)
#define DMM_SYSCONFIG_IDLEMODE_FORCE_IDLE                (CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_FORCE_IDLE)
#define DMM_SYSCONFIG_IDLEMODE_NO_IDLE                   (CSL_DMM_CORE_SYSCONFIG_IDLE_MODE_NO_IDLE)

#define CSL_DMM_CORE_SYSCONFIG_RESETVAL                         (0x00000008U)

/* LISA_LOCK */

#define CSL_DMM_CORE_LISA_LOCK_LOCK_MASK                        (0x00000001U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_SHIFT                       (0x00000000U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_RESETVAL                    (0x00000000U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_UNLOCKED                    (0x00000000U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_LOCKED                      (0x00000001U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_LOCKING                     (0x00000001U)
#define CSL_DMM_CORE_LISA_LOCK_LOCK_KEEP                        (0x00000000U)

#define CSL_DMM_CORE_LISA_LOCK_RESETVAL                         (0x00000000U)

/* EMERGENCY */

#define CSL_DMM_CORE_EMERGENCY_WEIGHT_MASK                      (0x001F0000U)
#define CSL_DMM_CORE_EMERGENCY_WEIGHT_SHIFT                     (0x00000010U)
#define CSL_DMM_CORE_EMERGENCY_WEIGHT_RESETVAL                  (0x00000004U)
#define CSL_DMM_CORE_EMERGENCY_WEIGHT_MAX                       (0x0000001fU)

#define CSL_DMM_CORE_EMERGENCY_EN_MASK                          (0x00000001U)
#define CSL_DMM_CORE_EMERGENCY_EN_SHIFT                         (0x00000000U)
#define CSL_DMM_CORE_EMERGENCY_EN_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_EMERGENCY_EN_MAX                           (0x00000001U)

#define CSL_DMM_CORE_EMERGENCY_RESETVAL                         (0x00040000U)

/* LISA_MAP */

#define CSL_DMM_CORE_LISA_MAP_SYS_ADDR_MASK                     (0xFF000000U)
#define CSL_DMM_CORE_LISA_MAP_SYS_ADDR_SHIFT                    (0x00000018U)
#define CSL_DMM_CORE_LISA_MAP_SYS_ADDR_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SYS_ADDR_MAX                      (0x000000ffU)

#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE_MASK                     (0x00700000U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE_SHIFT                    (0x00000014U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__16MB                    (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__32MB                    (0x00000001U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__64MB                    (0x00000002U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__128MB                   (0x00000003U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__256MB                   (0x00000004U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__512MB                   (0x00000005U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__1GB                     (0x00000006U)
#define CSL_DMM_CORE_LISA_MAP_SYS_SIZE__2GB                     (0x00000007U)

#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL_MASK                    (0x000C0000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL_SHIFT                   (0x00000012U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL_RESETVAL                (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL_NONE                    (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL__128B                   (0x00000001U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL__256B                   (0x00000002U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_INTL__512B                   (0x00000003U)

#define CSL_DMM_CORE_LISA_MAP_SDRC_MAP_MASK                     (0x00000300U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_MAP_SHIFT                    (0x00000008U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_MAP_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_MAP_MAX                      (0x00000003U)

#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDRSPC_MASK                 (0x00030000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDRSPC_SHIFT                (0x00000010U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDRSPC_RESETVAL             (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDRSPC_MAX                  (0x00000003U)

#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDR_MASK                    (0x000000FFU)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDR_SHIFT                   (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDR_RESETVAL                (0x00000000U)
#define CSL_DMM_CORE_LISA_MAP_SDRC_ADDR_MAX                     (0x000000ffU)

#define CSL_DMM_CORE_LISA_MAP_RESETVAL                          (0x00000000U)

/* TILER_HWINFO */

#define CSL_DMM_CORE_TILER_HWINFO_OR_CNT_MASK                   (0x0000007FU)
#define CSL_DMM_CORE_TILER_HWINFO_OR_CNT_SHIFT                  (0x00000000U)
#define CSL_DMM_CORE_TILER_HWINFO_OR_CNT_RESETVAL               (0x00000010U)
#define CSL_DMM_CORE_TILER_HWINFO_OR_CNT_MAX                    (0x0000007fU)

#define CSL_DMM_CORE_TILER_HWINFO_RESETVAL                      (0x00000010U)

/* TILER_OR */

#define CSL_DMM_CORE_TILER_OR_W7_MASK                           (0x80000000U)
#define CSL_DMM_CORE_TILER_OR_W7_SHIFT                          (0x0000001FU)
#define CSL_DMM_CORE_TILER_OR_W7_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W7_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W7_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR7_MASK                          (0x70000000U)
#define CSL_DMM_CORE_TILER_OR_OR7_SHIFT                         (0x0000001CU)
#define CSL_DMM_CORE_TILER_OR_OR7_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR7_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W6_MASK                           (0x08000000U)
#define CSL_DMM_CORE_TILER_OR_W6_SHIFT                          (0x0000001BU)
#define CSL_DMM_CORE_TILER_OR_W6_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W6_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W6_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR6_MASK                          (0x07000000U)
#define CSL_DMM_CORE_TILER_OR_OR6_SHIFT                         (0x00000018U)
#define CSL_DMM_CORE_TILER_OR_OR6_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR6_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W5_MASK                           (0x00800000U)
#define CSL_DMM_CORE_TILER_OR_W5_SHIFT                          (0x00000017U)
#define CSL_DMM_CORE_TILER_OR_W5_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W5_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W5_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR5_MASK                          (0x00700000U)
#define CSL_DMM_CORE_TILER_OR_OR5_SHIFT                         (0x00000014U)
#define CSL_DMM_CORE_TILER_OR_OR5_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR5_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W4_MASK                           (0x00080000U)
#define CSL_DMM_CORE_TILER_OR_W4_SHIFT                          (0x00000013U)
#define CSL_DMM_CORE_TILER_OR_W4_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W4_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W4_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR4_MASK                          (0x00070000U)
#define CSL_DMM_CORE_TILER_OR_OR4_SHIFT                         (0x00000010U)
#define CSL_DMM_CORE_TILER_OR_OR4_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR4_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W3_MASK                           (0x00008000U)
#define CSL_DMM_CORE_TILER_OR_W3_SHIFT                          (0x0000000FU)
#define CSL_DMM_CORE_TILER_OR_W3_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W3_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W3_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR3_MASK                          (0x00007000U)
#define CSL_DMM_CORE_TILER_OR_OR3_SHIFT                         (0x0000000CU)
#define CSL_DMM_CORE_TILER_OR_OR3_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR3_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W2_MASK                           (0x00000800U)
#define CSL_DMM_CORE_TILER_OR_W2_SHIFT                          (0x0000000BU)
#define CSL_DMM_CORE_TILER_OR_W2_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W2_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W2_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR2_MASK                          (0x00000700U)
#define CSL_DMM_CORE_TILER_OR_OR2_SHIFT                         (0x00000008U)
#define CSL_DMM_CORE_TILER_OR_OR2_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR2_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W1_MASK                           (0x00000080U)
#define CSL_DMM_CORE_TILER_OR_W1_SHIFT                          (0x00000007U)
#define CSL_DMM_CORE_TILER_OR_W1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W1_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W1_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR1_MASK                          (0x00000070U)
#define CSL_DMM_CORE_TILER_OR_OR1_SHIFT                         (0x00000004U)
#define CSL_DMM_CORE_TILER_OR_OR1_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR1_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_W0_MASK                           (0x00000008U)
#define CSL_DMM_CORE_TILER_OR_W0_SHIFT                          (0x00000003U)
#define CSL_DMM_CORE_TILER_OR_W0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_W0_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_TILER_OR_W0_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_TILER_OR_OR0_MASK                          (0x00000007U)
#define CSL_DMM_CORE_TILER_OR_OR0_SHIFT                         (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR0_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_TILER_OR_OR0_MAX                           (0x00000007U)

#define CSL_DMM_CORE_TILER_OR_RESETVAL                          (0x00000000U)

/* PAT_HWINFO */

#define CSL_DMM_CORE_PAT_HWINFO_VIEW_CNT_MASK                   (0x0000007FU)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_CNT_SHIFT                  (0x00000000U)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_CNT_RESETVAL               (0x00000010U)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_CNT_MAX                    (0x0000007fU)

#define CSL_DMM_CORE_PAT_HWINFO_ENGINE_CNT_MASK                 (0x1F000000U)
#define CSL_DMM_CORE_PAT_HWINFO_ENGINE_CNT_SHIFT                (0x00000018U)
#define CSL_DMM_CORE_PAT_HWINFO_ENGINE_CNT_RESETVAL             (0x00000004U)
#define CSL_DMM_CORE_PAT_HWINFO_ENGINE_CNT_MAX                  (0x0000001fU)

#define CSL_DMM_CORE_PAT_HWINFO_LUT_CNT_MASK                    (0x001F0000U)
#define CSL_DMM_CORE_PAT_HWINFO_LUT_CNT_SHIFT                   (0x00000010U)
#define CSL_DMM_CORE_PAT_HWINFO_LUT_CNT_RESETVAL                (0x00000001U)
#define CSL_DMM_CORE_PAT_HWINFO_LUT_CNT_MAX                     (0x0000001fU)

#define CSL_DMM_CORE_PAT_HWINFO_VIEW_MAP_CNT_MASK               (0x00000F00U)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_MAP_CNT_SHIFT              (0x00000008U)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_MAP_CNT_RESETVAL           (0x00000004U)
#define CSL_DMM_CORE_PAT_HWINFO_VIEW_MAP_CNT_MAX                (0x0000000fU)

#define CSL_DMM_CORE_PAT_HWINFO_RESETVAL                        (0x04010410U)

/* PAT_GEOMETRY */

#define CSL_DMM_CORE_PAT_GEOMETRY_ADDR_RANGE_MASK               (0x00003F00U)
#define CSL_DMM_CORE_PAT_GEOMETRY_ADDR_RANGE_SHIFT              (0x00000008U)
#define CSL_DMM_CORE_PAT_GEOMETRY_ADDR_RANGE_RESETVAL           (0x00000010U)
#define CSL_DMM_CORE_PAT_GEOMETRY_ADDR_RANGE_MAX                (0x0000003fU)

#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_HGHT_MASK                (0x0F000000U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_HGHT_SHIFT               (0x00000018U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_HGHT_RESETVAL            (0x00000008U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_HGHT_MAX                 (0x0000000fU)

#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_WDTH_MASK                (0x000F0000U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_WDTH_SHIFT               (0x00000010U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_WDTH_RESETVAL            (0x00000008U)
#define CSL_DMM_CORE_PAT_GEOMETRY_CONT_WDTH_MAX                 (0x0000000fU)

#define CSL_DMM_CORE_PAT_GEOMETRY_PAGE_SZ_MASK                  (0x0000001FU)
#define CSL_DMM_CORE_PAT_GEOMETRY_PAGE_SZ_SHIFT                 (0x00000000U)
#define CSL_DMM_CORE_PAT_GEOMETRY_PAGE_SZ_RESETVAL              (0x00000001U)
#define CSL_DMM_CORE_PAT_GEOMETRY_PAGE_SZ_MAX                   (0x0000001fU)

#define CSL_DMM_CORE_PAT_GEOMETRY_RESETVAL                      (0x08081001U)

/* PAT_CONFIG */

#define CSL_DMM_CORE_PAT_CONFIG_MODE15_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE15_SHIFT                    (0x0000000FU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE15_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE15_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE15_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE14_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE14_SHIFT                    (0x0000000EU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE14_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE14_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE14_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE13_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE13_SHIFT                    (0x0000000DU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE13_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE13_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE13_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE12_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE12_SHIFT                    (0x0000000CU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE12_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE12_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE12_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE11_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE11_SHIFT                    (0x0000000BU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE11_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE11_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE11_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE10_MASK                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE10_SHIFT                    (0x0000000AU)
#define CSL_DMM_CORE_PAT_CONFIG_MODE10_RESETVAL                 (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE10_PROG                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE10_BYPASS                   (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE9_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE9_SHIFT                     (0x00000009U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE9_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE9_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE9_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE8_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE8_SHIFT                     (0x00000008U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE8_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE8_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE8_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE7_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE7_SHIFT                     (0x00000007U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE7_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE7_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE7_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE6_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE6_SHIFT                     (0x00000006U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE6_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE6_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE6_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE5_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE5_SHIFT                     (0x00000005U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE5_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE5_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE5_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE4_MASK                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE4_SHIFT                     (0x00000004U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE4_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE4_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE4_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE3_MASK                      (0x00000008U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE3_SHIFT                     (0x00000003U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE3_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE3_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE3_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE2_MASK                      (0x00000004U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE2_SHIFT                     (0x00000002U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE2_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE2_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE2_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE1_MASK                      (0x00000002U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE1_SHIFT                     (0x00000001U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE1_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE1_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE1_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_MODE0_MASK                      (0x00000001U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE0_SHIFT                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE0_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE0_PROG                      (0x00000000U)
#define CSL_DMM_CORE_PAT_CONFIG_MODE0_BYPASS                    (0x00000001U)

#define CSL_DMM_CORE_PAT_CONFIG_RESETVAL                        (0x00000000U)

/* PAT_VIEW */

#define CSL_DMM_CORE_PAT_VIEW_W7_MASK                           (0x80000000U)
#define CSL_DMM_CORE_PAT_VIEW_W7_SHIFT                          (0x0000001FU)
#define CSL_DMM_CORE_PAT_VIEW_W7_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W7_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W7_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V7_MASK                           (0x30000000U)
#define CSL_DMM_CORE_PAT_VIEW_V7_SHIFT                          (0x0000001CU)
#define CSL_DMM_CORE_PAT_VIEW_V7_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V7_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W6_MASK                           (0x08000000U)
#define CSL_DMM_CORE_PAT_VIEW_W6_SHIFT                          (0x0000001BU)
#define CSL_DMM_CORE_PAT_VIEW_W6_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W6_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W6_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V6_MASK                           (0x03000000U)
#define CSL_DMM_CORE_PAT_VIEW_V6_SHIFT                          (0x00000018U)
#define CSL_DMM_CORE_PAT_VIEW_V6_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V6_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W5_MASK                           (0x00800000U)
#define CSL_DMM_CORE_PAT_VIEW_W5_SHIFT                          (0x00000017U)
#define CSL_DMM_CORE_PAT_VIEW_W5_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W5_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W5_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V5_MASK                           (0x00300000U)
#define CSL_DMM_CORE_PAT_VIEW_V5_SHIFT                          (0x00000014U)
#define CSL_DMM_CORE_PAT_VIEW_V5_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V5_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W4_MASK                           (0x00080000U)
#define CSL_DMM_CORE_PAT_VIEW_W4_SHIFT                          (0x00000013U)
#define CSL_DMM_CORE_PAT_VIEW_W4_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W4_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W4_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V4_MASK                           (0x00030000U)
#define CSL_DMM_CORE_PAT_VIEW_V4_SHIFT                          (0x00000010U)
#define CSL_DMM_CORE_PAT_VIEW_V4_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V4_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W3_MASK                           (0x00008000U)
#define CSL_DMM_CORE_PAT_VIEW_W3_SHIFT                          (0x0000000FU)
#define CSL_DMM_CORE_PAT_VIEW_W3_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W3_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W3_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V3_MASK                           (0x00003000U)
#define CSL_DMM_CORE_PAT_VIEW_V3_SHIFT                          (0x0000000CU)
#define CSL_DMM_CORE_PAT_VIEW_V3_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V3_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W2_MASK                           (0x00000800U)
#define CSL_DMM_CORE_PAT_VIEW_W2_SHIFT                          (0x0000000BU)
#define CSL_DMM_CORE_PAT_VIEW_W2_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W2_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W2_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V2_MASK                           (0x00000300U)
#define CSL_DMM_CORE_PAT_VIEW_V2_SHIFT                          (0x00000008U)
#define CSL_DMM_CORE_PAT_VIEW_V2_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V2_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W1_MASK                           (0x00000080U)
#define CSL_DMM_CORE_PAT_VIEW_W1_SHIFT                          (0x00000007U)
#define CSL_DMM_CORE_PAT_VIEW_W1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W1_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W1_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V1_MASK                           (0x00000030U)
#define CSL_DMM_CORE_PAT_VIEW_V1_SHIFT                          (0x00000004U)
#define CSL_DMM_CORE_PAT_VIEW_V1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V1_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_W0_MASK                           (0x00000008U)
#define CSL_DMM_CORE_PAT_VIEW_W0_SHIFT                          (0x00000003U)
#define CSL_DMM_CORE_PAT_VIEW_W0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_W0_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PAT_VIEW_W0_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PAT_VIEW_V0_MASK                           (0x00000003U)
#define CSL_DMM_CORE_PAT_VIEW_V0_SHIFT                          (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_V0_MAX                            (0x00000003U)

#define CSL_DMM_CORE_PAT_VIEW_RESETVAL                          (0x00000000U)

/* PAT_VIEW_MAP */

#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_PAGE_MASK              (0x80000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_PAGE_SHIFT             (0x0000001FU)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_PAGE_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_PAGE_DIRECT            (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_PAGE_LUT               (0x00000001U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_32_MASK                (0x00800000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_32_SHIFT               (0x00000017U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_32_RESETVAL            (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_32_DIRECT              (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_32_LUT                 (0x00000001U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_16_MASK                (0x00008000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_16_SHIFT               (0x0000000FU)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_16_RESETVAL            (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_16_DIRECT              (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_16_LUT                 (0x00000001U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_8_MASK                 (0x00000080U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_8_SHIFT                (0x00000007U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_8_RESETVAL             (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_8_DIRECT               (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_ACCESS_8_LUT                  (0x00000001U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_PAGE_MASK                (0x07000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_PAGE_SHIFT               (0x00000018U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_PAGE_RESETVAL            (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_PAGE_MAX                 (0x00000007U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_32_MASK                  (0x00070000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_32_SHIFT                 (0x00000010U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_32_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_32_MAX                   (0x00000007U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_16_MASK                  (0x00000700U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_16_SHIFT                 (0x00000008U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_16_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_16_MAX                   (0x00000007U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_8_MASK                   (0x00000007U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_8_SHIFT                  (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_8_RESETVAL               (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_CONT_8_MAX                    (0x00000007U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_RESETVAL                      (0x00000000U)

/* PAT_VIEW_MAP_BASE */

#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE_BASE_ADDR_MASK           (0x80000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE_BASE_ADDR_SHIFT          (0x0000001FU)
#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE_BASE_ADDR_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE_BASE_ADDR_MAX            (0x00000001U)

#define CSL_DMM_CORE_PAT_VIEW_MAP_BASE_RESETVAL                 (0x00000000U)

/* PAT_IRQ_EOI */

#define CSL_DMM_CORE_PAT_IRQ_EOI_EOI_MASK                       (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQ_EOI_EOI_SHIFT                      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQ_EOI_EOI_RESETVAL                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQ_EOI_EOI_ACK                        (0x00000000U)

#define CSL_DMM_CORE_PAT_IRQ_EOI_RESETVAL                       (0x00000000U)

/* PAT_IRQSTS_RAW */

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_MASK          (0x80000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_SHIFT         (0x0000001FU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS3_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_MASK          (0x40000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_SHIFT         (0x0000001EU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA3_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_MASK          (0x20000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_SHIFT         (0x0000001DU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL3_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_MASK          (0x10000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_SHIFT         (0x0000001CU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA3_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_MASK              (0x02000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_SHIFT             (0x00000019U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST3_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_MASK          (0x08000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_SHIFT         (0x0000001BU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA3_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_MASK           (0x04000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_SHIFT          (0x0000001AU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_SET            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_NONE           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC3_HAPPEN         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_MASK              (0x01000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_SHIFT             (0x00000018U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC3_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_MASK          (0x00800000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_SHIFT         (0x00000017U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS2_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_MASK          (0x00400000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_SHIFT         (0x00000016U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA2_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_MASK          (0x00200000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_SHIFT         (0x00000015U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL2_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_MASK          (0x00100000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_SHIFT         (0x00000014U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA2_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_MASK              (0x00020000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_SHIFT             (0x00000011U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST2_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_MASK          (0x00080000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_SHIFT         (0x00000013U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA2_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_MASK           (0x00040000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_SHIFT          (0x00000012U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_SET            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_NONE           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC2_HAPPEN         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_MASK              (0x00010000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_SHIFT             (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC2_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_MASK          (0x00008000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_SHIFT         (0x0000000FU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS1_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_MASK          (0x00004000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_SHIFT         (0x0000000EU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA1_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_MASK          (0x00002000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_SHIFT         (0x0000000DU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL1_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_MASK          (0x00001000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_SHIFT         (0x0000000CU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA1_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_MASK              (0x00000200U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_SHIFT             (0x00000009U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST1_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_MASK          (0x00000800U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_SHIFT         (0x0000000BU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA1_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_MASK           (0x00000400U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_SHIFT          (0x0000000AU)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_SET            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_NONE           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC1_HAPPEN         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_MASK              (0x00000100U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_SHIFT             (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC1_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_MASK          (0x00000080U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_SHIFT         (0x00000007U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_LUT_MISS0_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_MASK          (0x00000040U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_SHIFT         (0x00000006U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_DATA0_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_MASK          (0x00000020U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_SHIFT         (0x00000005U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_CTRL0_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_MASK          (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_SHIFT         (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_UPD_AREA0_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_MASK              (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_SHIFT             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_LST0_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_MASK          (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_SHIFT         (0x00000003U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_RESETVAL      (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_KEEP          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_SET           (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_NONE          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DATA0_HAPPEN        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_MASK           (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_SHIFT          (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_SET            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_NONE           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_ERR_INV_DSC0_HAPPEN         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_MASK              (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_SHIFT             (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_SET               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_NOT               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_RAW_FILL_DSC0_DONE              (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RAW_RESETVAL                    (0x00000000U)

/* PAT_IRQSTS */

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_MASK              (0x80000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_SHIFT             (0x0000001FU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS3_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_MASK              (0x40000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_SHIFT             (0x0000001EU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA3_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_MASK              (0x20000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_SHIFT             (0x0000001DU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL3_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_MASK              (0x10000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_SHIFT             (0x0000001CU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA3_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_MASK              (0x08000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_SHIFT             (0x0000001BU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA3_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_MASK               (0x04000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_SHIFT              (0x0000001AU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_CLR                (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_NONE               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC3_HAPPEN             (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_MASK                  (0x02000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_SHIFT                 (0x00000019U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST3_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_MASK                  (0x01000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_SHIFT                 (0x00000018U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC3_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_MASK              (0x00800000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_SHIFT             (0x00000017U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS2_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_MASK              (0x00400000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_SHIFT             (0x00000016U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA2_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_MASK              (0x00200000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_SHIFT             (0x00000015U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL2_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_MASK              (0x00100000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_SHIFT             (0x00000014U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA2_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_MASK              (0x00080000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_SHIFT             (0x00000013U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA2_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_MASK               (0x00040000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_SHIFT              (0x00000012U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_CLR                (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_NONE               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC2_HAPPEN             (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_MASK                  (0x00020000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_SHIFT                 (0x00000011U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST2_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_MASK                  (0x00010000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_SHIFT                 (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC2_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_MASK              (0x00008000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_SHIFT             (0x0000000FU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS1_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_MASK              (0x00004000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_SHIFT             (0x0000000EU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA1_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_MASK              (0x00002000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_SHIFT             (0x0000000DU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL1_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_MASK              (0x00001000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_SHIFT             (0x0000000CU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA1_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_MASK              (0x00000800U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_SHIFT             (0x0000000BU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA1_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_MASK               (0x00000400U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_SHIFT              (0x0000000AU)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_CLR                (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_NONE               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC1_HAPPEN             (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_MASK                  (0x00000200U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_SHIFT                 (0x00000009U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST1_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_MASK                  (0x00000100U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_SHIFT                 (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC1_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_MASK              (0x00000080U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_SHIFT             (0x00000007U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_LUT_MISS0_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_MASK              (0x00000040U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_SHIFT             (0x00000006U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_DATA0_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_MASK              (0x00000020U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_SHIFT             (0x00000005U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_CTRL0_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_MASK              (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_SHIFT             (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_UPD_AREA0_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_MASK              (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_SHIFT             (0x00000003U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_RESETVAL          (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_KEEP              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_CLR               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_NONE              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DATA0_HAPPEN            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_MASK               (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_SHIFT              (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_CLR                (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_NONE               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_ERR_INV_DSC0_HAPPEN             (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_MASK                  (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_SHIFT                 (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_LST0_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_MASK                  (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_SHIFT                 (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_RESETVAL              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_KEEP                  (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_CLR                   (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_NOT                   (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQSTS_FILL_DSC0_DONE                  (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQSTS_RESETVAL                        (0x00000000U)

/* PAT_IRQEN_SET */

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_MASK           (0x80000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_SHIFT          (0x0000001FU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_MASK           (0x40000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_SHIFT          (0x0000001EU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_MASK           (0x20000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_SHIFT          (0x0000001DU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_MASK           (0x10000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_SHIFT          (0x0000001CU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_MASK           (0x08000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_SHIFT          (0x0000001BU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_MASK            (0x04000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_SHIFT           (0x0000001AU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_ENABLE          (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC3_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_MASK               (0x02000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_SHIFT              (0x00000019U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST3_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_MASK               (0x01000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_SHIFT              (0x00000018U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC3_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_MASK           (0x00800000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_SHIFT          (0x00000017U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_MASK           (0x00400000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_SHIFT          (0x00000016U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_MASK           (0x00200000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_SHIFT          (0x00000015U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_MASK           (0x00100000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_SHIFT          (0x00000014U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_MASK           (0x00080000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_SHIFT          (0x00000013U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_MASK            (0x00040000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_SHIFT           (0x00000012U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_ENABLE          (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC2_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_MASK               (0x00020000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_SHIFT              (0x00000011U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST2_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_MASK               (0x00010000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_SHIFT              (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC2_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_MASK           (0x00008000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_SHIFT          (0x0000000FU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_MASK           (0x00004000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_SHIFT          (0x0000000EU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_MASK           (0x00002000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_SHIFT          (0x0000000DU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_MASK           (0x00001000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_SHIFT          (0x0000000CU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_MASK           (0x00000800U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_SHIFT          (0x0000000BU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_MASK            (0x00000400U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_SHIFT           (0x0000000AU)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_ENABLE          (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC1_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_MASK               (0x00000200U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_SHIFT              (0x00000009U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST1_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_MASK               (0x00000100U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_SHIFT              (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC1_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_MASK           (0x00000080U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_SHIFT          (0x00000007U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_LUT_MISS0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_MASK           (0x00000040U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_SHIFT          (0x00000006U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_DATA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_MASK           (0x00000020U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_SHIFT          (0x00000005U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_CTRL0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_MASK           (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_SHIFT          (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_UPD_AREA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_MASK           (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_SHIFT          (0x00000003U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_ENABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DATA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_MASK            (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_SHIFT           (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_ENABLE          (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_ERR_INV_DSC0_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_MASK               (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_SHIFT              (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_LST0_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_MASK               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_SHIFT              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_ENABLE             (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_SET_FILL_DSC0_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_SET_RESETVAL                     (0x00000000U)

/* PAT_IRQEN_CLR */

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_MASK           (0x80000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_SHIFT          (0x0000001FU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_MASK           (0x40000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_SHIFT          (0x0000001EU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_MASK           (0x20000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_SHIFT          (0x0000001DU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_MASK           (0x10000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_SHIFT          (0x0000001CU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_MASK           (0x08000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_SHIFT          (0x0000001BU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA3_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_MASK            (0x04000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_SHIFT           (0x0000001AU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_DISABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC3_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_MASK               (0x02000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_SHIFT              (0x00000019U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST3_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_MASK               (0x01000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_SHIFT              (0x00000018U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC3_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_MASK           (0x00800000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_SHIFT          (0x00000017U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_MASK           (0x00400000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_SHIFT          (0x00000016U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_MASK           (0x00200000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_SHIFT          (0x00000015U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_MASK           (0x00100000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_SHIFT          (0x00000014U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_MASK           (0x00080000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_SHIFT          (0x00000013U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA2_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_MASK            (0x00040000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_SHIFT           (0x00000012U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_DISABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC2_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_MASK               (0x00020000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_SHIFT              (0x00000011U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST2_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_MASK               (0x00010000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_SHIFT              (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC2_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_MASK           (0x00008000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_SHIFT          (0x0000000FU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_MASK           (0x00004000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_SHIFT          (0x0000000EU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_MASK           (0x00002000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_SHIFT          (0x0000000DU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_MASK           (0x00001000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_SHIFT          (0x0000000CU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_MASK           (0x00000800U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_SHIFT          (0x0000000BU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA1_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_MASK            (0x00000400U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_SHIFT           (0x0000000AU)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_DISABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC1_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_MASK               (0x00000200U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_SHIFT              (0x00000009U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST1_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_MASK               (0x00000100U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_SHIFT              (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC1_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_MASK           (0x00000080U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_SHIFT          (0x00000007U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_LUT_MISS0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_MASK           (0x00000040U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_SHIFT          (0x00000006U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_DATA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_MASK           (0x00000020U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_SHIFT          (0x00000005U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_CTRL0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_MASK           (0x00000010U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_SHIFT          (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_UPD_AREA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_MASK           (0x00000008U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_SHIFT          (0x00000003U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_RESETVAL       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_KEEP           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_DISABLE        (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_DISABLED       (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DATA0_ENABLED        (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_MASK            (0x00000004U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_SHIFT           (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_RESETVAL        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_KEEP            (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_DISABLE         (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_DISABLED        (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_ERR_INV_DSC0_ENABLED         (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_MASK               (0x00000002U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_SHIFT              (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_LST0_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_MASK               (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_SHIFT              (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_RESETVAL           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_KEEP               (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_DISABLE            (0x00000001U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_DISABLED           (0x00000000U)
#define CSL_DMM_CORE_PAT_IRQEN_CLR_FILL_DSC0_ENABLED            (0x00000001U)

#define CSL_DMM_CORE_PAT_IRQEN_CLR_RESETVAL                     (0x00000000U)

/* PAT_STS */

#define CSL_DMM_CORE_PAT_STS_BYPASSED_MASK                      (0x00000080U)
#define CSL_DMM_CORE_PAT_STS_BYPASSED_SHIFT                     (0x00000007U)
#define CSL_DMM_CORE_PAT_STS_BYPASSED_RESETVAL                  (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_BYPASSED_MAX                       (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_LINKED_MASK                        (0x00000010U)
#define CSL_DMM_CORE_PAT_STS_LINKED_SHIFT                       (0x00000004U)
#define CSL_DMM_CORE_PAT_STS_LINKED_RESETVAL                    (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_LINKED_MAX                         (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_DONE_MASK                          (0x00000008U)
#define CSL_DMM_CORE_PAT_STS_DONE_SHIFT                         (0x00000003U)
#define CSL_DMM_CORE_PAT_STS_DONE_RESETVAL                      (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_DONE_MAX                           (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_ERROR_MASK                         (0x0000FC00U)
#define CSL_DMM_CORE_PAT_STS_ERROR_SHIFT                        (0x0000000AU)
#define CSL_DMM_CORE_PAT_STS_ERROR_RESETVAL                     (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_ERROR_MAX                          (0x0000003fU)

#define CSL_DMM_CORE_PAT_STS_CNT_MASK                           (0x01FF0000U)
#define CSL_DMM_CORE_PAT_STS_CNT_SHIFT                          (0x00000010U)
#define CSL_DMM_CORE_PAT_STS_CNT_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_CNT_MAX                            (0x000001ffU)

#define CSL_DMM_CORE_PAT_STS_VALID_MASK                         (0x00000002U)
#define CSL_DMM_CORE_PAT_STS_VALID_SHIFT                        (0x00000001U)
#define CSL_DMM_CORE_PAT_STS_VALID_RESETVAL                     (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_VALID_MAX                          (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_RUN_MASK                           (0x00000004U)
#define CSL_DMM_CORE_PAT_STS_RUN_SHIFT                          (0x00000002U)
#define CSL_DMM_CORE_PAT_STS_RUN_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_RUN_MAX                            (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_READY_MASK                         (0x00000001U)
#define CSL_DMM_CORE_PAT_STS_READY_SHIFT                        (0x00000000U)
#define CSL_DMM_CORE_PAT_STS_READY_RESETVAL                     (0x00000001U)
#define CSL_DMM_CORE_PAT_STS_READY_MAX                          (0x00000001U)

#define CSL_DMM_CORE_PAT_STS_RESETVAL                           (0x00000001U)

/* PAT_DESCR */

#define CSL_DMM_CORE_PAT_DESCR_ADDR_MASK                        (0xFFFFFFF0U)
#define CSL_DMM_CORE_PAT_DESCR_ADDR_SHIFT                       (0x00000004U)
#define CSL_DMM_CORE_PAT_DESCR_ADDR_RESETVAL                    (0x00000000U)
#define CSL_DMM_CORE_PAT_DESCR_ADDR_MAX                         (0x0fffffffU)

#define CSL_DMM_CORE_PAT_DESCR_RESETVAL                         (0x00000000U)

/* PAT_AREA */

#define CSL_DMM_CORE_PAT_AREA_Y1_MASK                           (0xFF000000U)
#define CSL_DMM_CORE_PAT_AREA_Y1_SHIFT                          (0x00000018U)
#define CSL_DMM_CORE_PAT_AREA_Y1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_AREA_Y1_MAX                            (0x000000ffU)

#define CSL_DMM_CORE_PAT_AREA_X1_MASK                           (0x00FF0000U)
#define CSL_DMM_CORE_PAT_AREA_X1_SHIFT                          (0x00000010U)
#define CSL_DMM_CORE_PAT_AREA_X1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_AREA_X1_MAX                            (0x000000ffU)

#define CSL_DMM_CORE_PAT_AREA_Y0_MASK                           (0x0000FF00U)
#define CSL_DMM_CORE_PAT_AREA_Y0_SHIFT                          (0x00000008U)
#define CSL_DMM_CORE_PAT_AREA_Y0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_AREA_Y0_MAX                            (0x000000ffU)

#define CSL_DMM_CORE_PAT_AREA_X0_MASK                           (0x000000FFU)
#define CSL_DMM_CORE_PAT_AREA_X0_SHIFT                          (0x00000000U)
#define CSL_DMM_CORE_PAT_AREA_X0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PAT_AREA_X0_MAX                            (0x000000ffU)

#define CSL_DMM_CORE_PAT_AREA_RESETVAL                          (0x00000000U)

/* PAT_CTRL */

#define CSL_DMM_CORE_PAT_CTRL_LUT_ID_MASK                       (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_LUT_ID_SHIFT                      (0x00000008U)
#define CSL_DMM_CORE_PAT_CTRL_LUT_ID_RESETVAL                   (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_LUT_ID_MAX                        (0x00000000U)

#define CSL_DMM_CORE_PAT_CTRL_INITIATOR_MASK                    (0xF0000000U)
#define CSL_DMM_CORE_PAT_CTRL_INITIATOR_SHIFT                   (0x0000001CU)
#define CSL_DMM_CORE_PAT_CTRL_INITIATOR_RESETVAL                (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_INITIATOR_MAX                     (0x0000000fU)

#define CSL_DMM_CORE_PAT_CTRL_SYNC_MASK                         (0x00010000U)
#define CSL_DMM_CORE_PAT_CTRL_SYNC_SHIFT                        (0x00000010U)
#define CSL_DMM_CORE_PAT_CTRL_SYNC_RESETVAL                     (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_SYNC_OFF                          (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_SYNC_ON                           (0x00000001U)

#define CSL_DMM_CORE_PAT_CTRL_DIRECTION_MASK                    (0x00000070U)
#define CSL_DMM_CORE_PAT_CTRL_DIRECTION_SHIFT                   (0x00000004U)
#define CSL_DMM_CORE_PAT_CTRL_DIRECTION_RESETVAL                (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_DIRECTION_MAX                     (0x00000007U)

#define CSL_DMM_CORE_PAT_CTRL_START_MASK                        (0x00000001U)
#define CSL_DMM_CORE_PAT_CTRL_START_SHIFT                       (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_START_RESETVAL                    (0x00000000U)
#define CSL_DMM_CORE_PAT_CTRL_START_MAX                         (0x00000001U)

#define CSL_DMM_CORE_PAT_CTRL_RESETVAL                          (0x00000000U)

/* PAT_DATA */

#define CSL_DMM_CORE_PAT_DATA_ADDR_MASK                         (0xFFFFFFF0U)
#define CSL_DMM_CORE_PAT_DATA_ADDR_SHIFT                        (0x00000004U)
#define CSL_DMM_CORE_PAT_DATA_ADDR_RESETVAL                     (0x00000000U)
#define CSL_DMM_CORE_PAT_DATA_ADDR_MAX                          (0x0fffffffU)

#define CSL_DMM_CORE_PAT_DATA_RESETVAL                          (0x00000000U)

/* PEG_HWINFO */

#define CSL_DMM_CORE_PEG_HWINFO_PRIO_CNT_MASK                   (0x0000007FU)
#define CSL_DMM_CORE_PEG_HWINFO_PRIO_CNT_SHIFT                  (0x00000000U)
#define CSL_DMM_CORE_PEG_HWINFO_PRIO_CNT_RESETVAL               (0x00000040U)
#define CSL_DMM_CORE_PEG_HWINFO_PRIO_CNT_MAX                    (0x0000007fU)

#define CSL_DMM_CORE_PEG_HWINFO_RESETVAL                        (0x00000040U)

/* PEG_PRIO */

#define CSL_DMM_CORE_PEG_PRIO_W7_MASK                           (0x80000000U)
#define CSL_DMM_CORE_PEG_PRIO_W7_SHIFT                          (0x0000001FU)
#define CSL_DMM_CORE_PEG_PRIO_W7_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W7_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W7_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P7_MASK                           (0x70000000U)
#define CSL_DMM_CORE_PEG_PRIO_P7_SHIFT                          (0x0000001CU)
#define CSL_DMM_CORE_PEG_PRIO_P7_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P7_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W6_MASK                           (0x08000000U)
#define CSL_DMM_CORE_PEG_PRIO_W6_SHIFT                          (0x0000001BU)
#define CSL_DMM_CORE_PEG_PRIO_W6_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W6_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W6_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P6_MASK                           (0x07000000U)
#define CSL_DMM_CORE_PEG_PRIO_P6_SHIFT                          (0x00000018U)
#define CSL_DMM_CORE_PEG_PRIO_P6_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P6_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W5_MASK                           (0x00800000U)
#define CSL_DMM_CORE_PEG_PRIO_W5_SHIFT                          (0x00000017U)
#define CSL_DMM_CORE_PEG_PRIO_W5_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W5_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W5_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P5_MASK                           (0x00700000U)
#define CSL_DMM_CORE_PEG_PRIO_P5_SHIFT                          (0x00000014U)
#define CSL_DMM_CORE_PEG_PRIO_P5_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P5_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W4_MASK                           (0x00080000U)
#define CSL_DMM_CORE_PEG_PRIO_W4_SHIFT                          (0x00000013U)
#define CSL_DMM_CORE_PEG_PRIO_W4_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W4_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W4_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P4_MASK                           (0x00070000U)
#define CSL_DMM_CORE_PEG_PRIO_P4_SHIFT                          (0x00000010U)
#define CSL_DMM_CORE_PEG_PRIO_P4_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P4_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W3_MASK                           (0x00008000U)
#define CSL_DMM_CORE_PEG_PRIO_W3_SHIFT                          (0x0000000FU)
#define CSL_DMM_CORE_PEG_PRIO_W3_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W3_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W3_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P3_MASK                           (0x00007000U)
#define CSL_DMM_CORE_PEG_PRIO_P3_SHIFT                          (0x0000000CU)
#define CSL_DMM_CORE_PEG_PRIO_P3_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P3_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W2_MASK                           (0x00000800U)
#define CSL_DMM_CORE_PEG_PRIO_W2_SHIFT                          (0x0000000BU)
#define CSL_DMM_CORE_PEG_PRIO_W2_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W2_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W2_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P2_MASK                           (0x00000700U)
#define CSL_DMM_CORE_PEG_PRIO_P2_SHIFT                          (0x00000008U)
#define CSL_DMM_CORE_PEG_PRIO_P2_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P2_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W1_MASK                           (0x00000080U)
#define CSL_DMM_CORE_PEG_PRIO_W1_SHIFT                          (0x00000007U)
#define CSL_DMM_CORE_PEG_PRIO_W1_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W1_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W1_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P1_MASK                           (0x00000070U)
#define CSL_DMM_CORE_PEG_PRIO_P1_SHIFT                          (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P1_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P1_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_W0_MASK                           (0x00000008U)
#define CSL_DMM_CORE_PEG_PRIO_W0_SHIFT                          (0x00000003U)
#define CSL_DMM_CORE_PEG_PRIO_W0_RESETVAL                       (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_W0_UPDATE                         (0x00000001U)
#define CSL_DMM_CORE_PEG_PRIO_W0_KEEP                           (0x00000000U)

#define CSL_DMM_CORE_PEG_PRIO_P0_MASK                           (0x00000007U)
#define CSL_DMM_CORE_PEG_PRIO_P0_SHIFT                          (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_P0_RESETVAL                       (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_P0_MAX                            (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_RESETVAL                          (0x44444444U)

/* PEG_PRIO_PAT */

#define CSL_DMM_CORE_PEG_PRIO_PAT_W_PAT_MASK                    (0x00000008U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_W_PAT_SHIFT                   (0x00000003U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_W_PAT_RESETVAL                (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_W_PAT_UPDATE                  (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_W_PAT_KEEP                    (0x00000001U)

#define CSL_DMM_CORE_PEG_PRIO_PAT_P_PAT_MASK                    (0x00000007U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_P_PAT_SHIFT                   (0x00000000U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_P_PAT_RESETVAL                (0x00000004U)
#define CSL_DMM_CORE_PEG_PRIO_PAT_P_PAT_MAX                     (0x00000007U)

#define CSL_DMM_CORE_PEG_PRIO_PAT_RESETVAL                      (0x00000004U)

#ifdef __cplusplus
}
#endif
#endif
