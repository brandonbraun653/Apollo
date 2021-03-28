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
#ifndef CSLR_DSSVP_H_
#define CSLR_DSSVP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for VP_ALL
**************************************************************************/
typedef struct {
    volatile Uint32 CONFIG;
    volatile Uint32 CONTROL;
    volatile Uint32 CPR_COEF_B;
    volatile Uint32 CPR_COEF_G;
    volatile Uint32 CPR_COEF_R;
    volatile Uint32 DATA_CYCLE[3];
    volatile Uint32 GAMMA_TABLE;
    volatile Uint8  RSVD0[24];
    volatile Uint32 IRQENABLE;
    volatile Uint32 IRQSTATUS;
    volatile Uint32 LINE_NUMBER;
    volatile Uint8  RSVD1[4];
    volatile Uint32 POL_FREQ;
    volatile Uint32 SIZE_SCREEN;
    volatile Uint32 TIMING_H;
    volatile Uint32 TIMING_V;
} CSL_DssVpRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* The control register configures the Display Controller module for the VP 
 * output. Shadow register. */
#define CSL_DSSVP_CONFIG                                        (0x0U)

/* The control register configures the Display Controller module for the VP 
 * output. */
#define CSL_DSSVP_CONTROL                                       (0x4U)

/* The register configures the color phase rotation matrix coefficients for 
 * the Blue component. Shadow register. */
#define CSL_DSSVP_CPR_COEF_B                                    (0x8U)

/* The register configures the color phase rotation matrix coefficients for 
 * the Green component. Shadow register. */
#define CSL_DSSVP_CPR_COEF_G                                    (0xCU)

/* The register configures the color phase rotation matrix coefficients for 
 * the Red component. Shadow register. */
#define CSL_DSSVP_CPR_COEF_R                                    (0x10U)

/* The control register configures the output data format over up to 3 cycles. 
 * Shadow register. */
#define CSL_DSSVP_DATA_CYCLE(i)                                 (0x14U + ((i) * (0x4U)))

/* The register configures the gamma table on VP output. */
#define CSL_DSSVP_GAMMA_TABLE                                   (0x20U)

/* This register allows to mask/unmask the module internal sources of 
 * interrupt, on an event-by-event basis */
#define CSL_DSSVP_IRQENABLE                                     (0x3CU)

/* This register regroups all the status of the module internal events that 
 * generate an interrupt. Write 1 to a given bit resets this bit */
#define CSL_DSSVP_IRQSTATUS                                     (0x40U)

/* The control register indicates the panel display line number for the 
 * interrupt and the DMA request. Shadow register. */
#define CSL_DSSVP_LINE_NUMBER                                   (0x44U)

/* The register configures the signal configuration. Shadow register. */
#define CSL_DSSVP_POL_FREQ                                      (0x4CU)

/* The register configures the panel size (horizontal and vertical). Shadow 
 * register. A delta value is used to indicate if the odd field has same 
 * vertical size as the even field or +/- one line. */
#define CSL_DSSVP_SIZE_SCREEN                                   (0x50U)

/* The register configures the timing logic for the HSYNC signal. Shadow 
 * register. */
#define CSL_DSSVP_TIMING_H                                      (0x54U)

/* The register configures the timing logic for the VSYNC signal. Shadow 
 * register. */
#define CSL_DSSVP_TIMING_V                                      (0x58U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CONFIG */

#define CSL_DSSVP_CONFIG_PIXELDATAGATED_MASK                    (0x00000010U)
#define CSL_DSSVP_CONFIG_PIXELDATAGATED_SHIFT                   (4U)
#define CSL_DSSVP_CONFIG_PIXELDATAGATED_RESETVAL                (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELDATAGATED_PDGDIS                  (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELDATAGATED_PDGENB                  (0x00000001U)

#define CSL_DSSVP_CONFIG_HSYNCGATED_MASK                        (0x00000040U)
#define CSL_DSSVP_CONFIG_HSYNCGATED_SHIFT                       (6U)
#define CSL_DSSVP_CONFIG_HSYNCGATED_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONFIG_HSYNCGATED_HGDIS                       (0x00000000U)
#define CSL_DSSVP_CONFIG_HSYNCGATED_HGENB                       (0x00000001U)

#define CSL_DSSVP_CONFIG_PIXELCLOCKGATED_MASK                   (0x00000020U)
#define CSL_DSSVP_CONFIG_PIXELCLOCKGATED_SHIFT                  (5U)
#define CSL_DSSVP_CONFIG_PIXELCLOCKGATED_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELCLOCKGATED_PCGDIS                 (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELCLOCKGATED_PCGENB                 (0x00000001U)

#define CSL_DSSVP_CONFIG_VSYNCGATED_MASK                        (0x00000080U)
#define CSL_DSSVP_CONFIG_VSYNCGATED_SHIFT                       (7U)
#define CSL_DSSVP_CONFIG_VSYNCGATED_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONFIG_VSYNCGATED_VGDIS                       (0x00000000U)
#define CSL_DSSVP_CONFIG_VSYNCGATED_VGENB                       (0x00000001U)

#define CSL_DSSVP_CONFIG_PIXELGATED_MASK                        (0x00000001U)
#define CSL_DSSVP_CONFIG_PIXELGATED_SHIFT                       (0U)
#define CSL_DSSVP_CONFIG_PIXELGATED_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELGATED_PCLKTOGA                    (0x00000000U)
#define CSL_DSSVP_CONFIG_PIXELGATED_PCLKTOGV                    (0x00000001U)

#define CSL_DSSVP_CONFIG_BT656ENABLE_MASK                       (0x00100000U)
#define CSL_DSSVP_CONFIG_BT656ENABLE_SHIFT                      (20U)
#define CSL_DSSVP_CONFIG_BT656ENABLE_RESETVAL                   (0x00000000U)
#define CSL_DSSVP_CONFIG_BT656ENABLE_DISABLE                    (0x00000000U)
#define CSL_DSSVP_CONFIG_BT656ENABLE_ENABLE                     (0x00000001U)

#define CSL_DSSVP_CONFIG_BT1120ENABLE_MASK                      (0x00200000U)
#define CSL_DSSVP_CONFIG_BT1120ENABLE_SHIFT                     (21U)
#define CSL_DSSVP_CONFIG_BT1120ENABLE_RESETVAL                  (0x00000000U)
#define CSL_DSSVP_CONFIG_BT1120ENABLE_DISABLE                   (0x00000000U)
#define CSL_DSSVP_CONFIG_BT1120ENABLE_ENABLE                    (0x00000001U)

#define CSL_DSSVP_CONFIG_OUTPUTMODEENABLE_MASK                  (0x00400000U)
#define CSL_DSSVP_CONFIG_OUTPUTMODEENABLE_SHIFT                 (22U)
#define CSL_DSSVP_CONFIG_OUTPUTMODEENABLE_RESETVAL              (0x00000000U)
#define CSL_DSSVP_CONFIG_OUTPUTMODEENABLE_DISABLE               (0x00000000U)
#define CSL_DSSVP_CONFIG_OUTPUTMODEENABLE_ENABLE                (0x00000001U)

#define CSL_DSSVP_CONFIG_CPR_MASK                               (0x00008000U)
#define CSL_DSSVP_CONFIG_CPR_SHIFT                              (15U)
#define CSL_DSSVP_CONFIG_CPR_RESETVAL                           (0x00000000U)
#define CSL_DSSVP_CONFIG_CPR_CPRDIS                             (0x00000000U)
#define CSL_DSSVP_CONFIG_CPR_CPRENB                             (0x00000001U)

#define CSL_DSSVP_CONFIG_FIDFIRST_MASK                          (0x00800000U)
#define CSL_DSSVP_CONFIG_FIDFIRST_SHIFT                         (23U)
#define CSL_DSSVP_CONFIG_FIDFIRST_RESETVAL                      (0x00000000U)
#define CSL_DSSVP_CONFIG_FIDFIRST_EVEN                          (0x00000000U)
#define CSL_DSSVP_CONFIG_FIDFIRST_ODD                           (0x00000001U)

#define CSL_DSSVP_CONFIG_COLORCONVENABLE_MASK                   (0x01000000U)
#define CSL_DSSVP_CONFIG_COLORCONVENABLE_SHIFT                  (24U)
#define CSL_DSSVP_CONFIG_COLORCONVENABLE_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONFIG_COLORCONVENABLE_COLSPCDIS              (0x00000000U)
#define CSL_DSSVP_CONFIG_COLORCONVENABLE_COLSPCENB              (0x00000001U)

#define CSL_DSSVP_CONFIG_FULLRANGE_MASK                         (0x02000000U)
#define CSL_DSSVP_CONFIG_FULLRANGE_SHIFT                        (25U)
#define CSL_DSSVP_CONFIG_FULLRANGE_RESETVAL                     (0x00000000U)
#define CSL_DSSVP_CONFIG_FULLRANGE_LIMRANGE                     (0x00000000U)
#define CSL_DSSVP_CONFIG_FULLRANGE_FULLRANGE                    (0x00000001U)

#define CSL_DSSVP_CONFIG_DATAENABLEGATED_MASK                   (0x00000002U)
#define CSL_DSSVP_CONFIG_DATAENABLEGATED_SHIFT                  (1U)
#define CSL_DSSVP_CONFIG_DATAENABLEGATED_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONFIG_DATAENABLEGATED_DEGDIS                 (0x00000000U)
#define CSL_DSSVP_CONFIG_DATAENABLEGATED_DEGENB                 (0x00000001U)

#define CSL_DSSVP_CONFIG_GAMMAENABLE_MASK                       (0x00000004U)
#define CSL_DSSVP_CONFIG_GAMMAENABLE_SHIFT                      (2U)
#define CSL_DSSVP_CONFIG_GAMMAENABLE_RESETVAL                   (0x00000000U)
#define CSL_DSSVP_CONFIG_GAMMAENABLE_GAMMADIS                   (0x00000000U)
#define CSL_DSSVP_CONFIG_GAMMAENABLE_GAMMAENB                   (0x00000001U)

#define CSL_DSSVP_CONFIG_BUFFERHANDSHAKE_MASK                   (0x00010000U)
#define CSL_DSSVP_CONFIG_BUFFERHANDSHAKE_SHIFT                  (16U)
#define CSL_DSSVP_CONFIG_BUFFERHANDSHAKE_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONFIG_BUFFERHANDSHAKE_HANDCHECKDIS           (0x00000000U)
#define CSL_DSSVP_CONFIG_BUFFERHANDSHAKE_HANDCHECKENB           (0x00000001U)

#define CSL_DSSVP_CONFIG_HDMIMODE_MASK                          (0x00000008U)
#define CSL_DSSVP_CONFIG_HDMIMODE_SHIFT                         (3U)
#define CSL_DSSVP_CONFIG_HDMIMODE_RESETVAL                      (0x00000000U)
#define CSL_DSSVP_CONFIG_HDMIMODE_HDMIMODEDIS                   (0x00000000U)
#define CSL_DSSVP_CONFIG_HDMIMODE_HDMIMODEEN                    (0x00000001U)

#define CSL_DSSVP_CONFIG_EXTERNALSYNCEN_MASK                    (0x00000100U)
#define CSL_DSSVP_CONFIG_EXTERNALSYNCEN_SHIFT                   (8U)
#define CSL_DSSVP_CONFIG_EXTERNALSYNCEN_RESETVAL                (0x00000000U)
#define CSL_DSSVP_CONFIG_EXTERNALSYNCEN_DISABLE                 (0x00000000U)
#define CSL_DSSVP_CONFIG_EXTERNALSYNCEN_ENABLE                  (0x00000001U)

#define CSL_DSSVP_CONFIG_RESETVAL                               (0x00000000U)

/* CONTROL */

#define CSL_DSSVP_CONTROL_STDITHERENABLE_MASK                   (0x00000080U)
#define CSL_DSSVP_CONTROL_STDITHERENABLE_SHIFT                  (7U)
#define CSL_DSSVP_CONTROL_STDITHERENABLE_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONTROL_STDITHERENABLE_STDITHDIS              (0x00000000U)
#define CSL_DSSVP_CONTROL_STDITHERENABLE_STDITHENB              (0x00000001U)

#define CSL_DSSVP_CONTROL_DATALINES_MASK                        (0x00000700U)
#define CSL_DSSVP_CONTROL_DATALINES_SHIFT                       (8U)
#define CSL_DSSVP_CONTROL_DATALINES_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB12B                    (0x00000000U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB16B                    (0x00000001U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB18B                    (0x00000002U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB24B                    (0x00000003U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB30B                    (0x00000004U)
#define CSL_DSSVP_CONTROL_DATALINES_OALSB36B                    (0x00000005U)

#define CSL_DSSVP_CONTROL_STALLMODE_MASK                        (0x00000800U)
#define CSL_DSSVP_CONTROL_STALLMODE_SHIFT                       (11U)
#define CSL_DSSVP_CONTROL_STALLMODE_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONTROL_STALLMODE_NMODE                       (0x00000000U)
#define CSL_DSSVP_CONTROL_STALLMODE_RFBIMODE                    (0x00000001U)

#define CSL_DSSVP_CONTROL_GOBIT_MASK                            (0x00000020U)
#define CSL_DSSVP_CONTROL_GOBIT_SHIFT                           (5U)
#define CSL_DSSVP_CONTROL_GOBIT_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CONTROL_GOBIT_HFUISR                          (0x00000000U)
#define CSL_DSSVP_CONTROL_GOBIT_UFPSR                           (0x00000001U)

#define CSL_DSSVP_CONTROL_VPENABLE_MASK                         (0x00000001U)
#define CSL_DSSVP_CONTROL_VPENABLE_SHIFT                        (0U)
#define CSL_DSSVP_CONTROL_VPENABLE_RESETVAL                     (0x00000000U)
#define CSL_DSSVP_CONTROL_VPENABLE_LCDOPDIS                     (0x00000000U)
#define CSL_DSSVP_CONTROL_VPENABLE_LCDOPENB                     (0x00000001U)

#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_MASK   (0xC0000000U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_SHIFT  (30U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_RESETVAL  (0x00000000U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_ONEFRAME  (0x00000000U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_TWOFRAMES  (0x00000001U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_FOURFRAMES  (0x00000002U)
#define CSL_DSSVP_CONTROL_SPATIALTEMPORALDITHERINGFRAMES_RESERVED  (0x00000003U)

#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_MASK                    (0x06000000U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_SHIFT                   (25U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_RESETVAL                (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_LOWLEVEL                (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_HIGHLEVEL               (0x00000001U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_UNCHANGED               (0x00000002U)
#define CSL_DSSVP_CONTROL_TDMUNUSEDBITS_RES                     (0x00000003U)

#define CSL_DSSVP_CONTROL_TDMENABLE_MASK                        (0x00100000U)
#define CSL_DSSVP_CONTROL_TDMENABLE_SHIFT                       (20U)
#define CSL_DSSVP_CONTROL_TDMENABLE_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMENABLE_TDMDIS                      (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMENABLE_TDMENB                      (0x00000001U)

#define CSL_DSSVP_CONTROL_TDMPARALLELMODE_MASK                  (0x00600000U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE_SHIFT                 (21U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE_RESETVAL              (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE__8BPARAINT            (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE__9BPARAINT            (0x00000001U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE__12BPARAINT           (0x00000002U)
#define CSL_DSSVP_CONTROL_TDMPARALLELMODE__16BPARAINT           (0x00000003U)

#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT_MASK                   (0x01800000U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT_SHIFT                  (23U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT_RESETVAL               (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT__1CYCPERPIX            (0x00000000U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT__2CYCPERPIX            (0x00000001U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT__3CYCPERPIX            (0x00000002U)
#define CSL_DSSVP_CONTROL_TDMCYCLEFORMAT__3CYCPER2PIX           (0x00000003U)

#define CSL_DSSVP_CONTROL_HT_MASK                               (0x0001C000U)
#define CSL_DSSVP_CONTROL_HT_SHIFT                              (14U)
#define CSL_DSSVP_CONTROL_HT_RESETVAL                           (0x00000000U)
#define CSL_DSSVP_CONTROL_HT_MAX                                (0x00000007U)

#define CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_MASK           (0x00000002U)
#define CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_SHIFT          (1U)
#define CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_RESETVAL       (0x00000000U)
#define CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_MODDIS         (0x00000000U)
#define CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_MODEN          (0x00000001U)

#define CSL_DSSVP_CONTROL_MONOCOLOR_MASK                        (0x00000004U)
#define CSL_DSSVP_CONTROL_MONOCOLOR_SHIFT                       (2U)
#define CSL_DSSVP_CONTROL_MONOCOLOR_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_CONTROL_MONOCOLOR_COLOREN                     (0x00000000U)
#define CSL_DSSVP_CONTROL_MONOCOLOR_MONOEN                      (0x00000001U)

#define CSL_DSSVP_CONTROL_STN_MASK                              (0x00000008U)
#define CSL_DSSVP_CONTROL_STN_SHIFT                             (3U)
#define CSL_DSSVP_CONTROL_STN_RESETVAL                          (0x00000000U)
#define CSL_DSSVP_CONTROL_STN_STNDIS                            (0x00000000U)
#define CSL_DSSVP_CONTROL_STN_STNEN                             (0x00000001U)

#define CSL_DSSVP_CONTROL_M8B_MASK                              (0x00000010U)
#define CSL_DSSVP_CONTROL_M8B_SHIFT                             (4U)
#define CSL_DSSVP_CONTROL_M8B_RESETVAL                          (0x00000000U)
#define CSL_DSSVP_CONTROL_M8B_M8BDIS                            (0x00000000U)
#define CSL_DSSVP_CONTROL_M8B_M8BEN                             (0x00000001U)

#define CSL_DSSVP_CONTROL_RESETVAL                              (0x00000000U)

/* CPR_COEF_B */

#define CSL_DSSVP_CPR_COEF_B_BB_MASK                            (0x000003FFU)
#define CSL_DSSVP_CPR_COEF_B_BB_SHIFT                           (0U)
#define CSL_DSSVP_CPR_COEF_B_BB_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_B_BB_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_B_BR_MASK                            (0xFFC00000U)
#define CSL_DSSVP_CPR_COEF_B_BR_SHIFT                           (22U)
#define CSL_DSSVP_CPR_COEF_B_BR_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_B_BR_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_B_BG_MASK                            (0x001FF800U)
#define CSL_DSSVP_CPR_COEF_B_BG_SHIFT                           (11U)
#define CSL_DSSVP_CPR_COEF_B_BG_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_B_BG_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_B_RESETVAL                           (0x00000000U)

/* CPR_COEF_G */

#define CSL_DSSVP_CPR_COEF_G_GB_MASK                            (0x000003FFU)
#define CSL_DSSVP_CPR_COEF_G_GB_SHIFT                           (0U)
#define CSL_DSSVP_CPR_COEF_G_GB_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_G_GB_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_G_GR_MASK                            (0xFFC00000U)
#define CSL_DSSVP_CPR_COEF_G_GR_SHIFT                           (22U)
#define CSL_DSSVP_CPR_COEF_G_GR_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_G_GR_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_G_GG_MASK                            (0x001FF800U)
#define CSL_DSSVP_CPR_COEF_G_GG_SHIFT                           (11U)
#define CSL_DSSVP_CPR_COEF_G_GG_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_G_GG_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_G_RESETVAL                           (0x00000000U)

/* CPR_COEF_R */

#define CSL_DSSVP_CPR_COEF_R_RB_MASK                            (0x000003FFU)
#define CSL_DSSVP_CPR_COEF_R_RB_SHIFT                           (0U)
#define CSL_DSSVP_CPR_COEF_R_RB_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_R_RB_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_R_RR_MASK                            (0xFFC00000U)
#define CSL_DSSVP_CPR_COEF_R_RR_SHIFT                           (22U)
#define CSL_DSSVP_CPR_COEF_R_RR_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_R_RR_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_R_RG_MASK                            (0x001FF800U)
#define CSL_DSSVP_CPR_COEF_R_RG_SHIFT                           (11U)
#define CSL_DSSVP_CPR_COEF_R_RG_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_CPR_COEF_R_RG_MAX                             (0x000003ffU)

#define CSL_DSSVP_CPR_COEF_R_RESETVAL                           (0x00000000U)

/* DATA_CYCLE */

#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL2_MASK                  (0x001F0000U)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL2_SHIFT                 (16U)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL2_RESETVAL              (0x00000000U)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL2_MAX                   (0x0000001fU)

#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL1_MASK            (0x00000F00U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL1_SHIFT           (8U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL1_RESETVAL        (0x00000000U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL1_MAX             (0x0000000fU)

#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL1_MASK                  (0x0000001FU)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL1_SHIFT                 (0U)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL1_RESETVAL              (0x00000000U)
#define CSL_DSSVP_DATA_CYCLE_NBBITSPIXEL1_MAX                   (0x0000001fU)

#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL2_MASK            (0x0F000000U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL2_SHIFT           (24U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL2_RESETVAL        (0x00000000U)
#define CSL_DSSVP_DATA_CYCLE_BITALIGNMENTPIXEL2_MAX             (0x0000000fU)

#define CSL_DSSVP_DATA_CYCLE_RESETVAL                           (0x00000000U)

/* GAMMA_TABLE */

#define CSL_DSSVP_GAMMA_TABLE_VALUE_R_MASK                      (0x00FF0000U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_R_SHIFT                     (16U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_R_RESETVAL                  (0x00000000U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_R_MAX                       (0x000000ffU)

#define CSL_DSSVP_GAMMA_TABLE_INDEX_MASK                        (0xFF000000U)
#define CSL_DSSVP_GAMMA_TABLE_INDEX_SHIFT                       (24U)
#define CSL_DSSVP_GAMMA_TABLE_INDEX_RESETVAL                    (0x00000000U)
#define CSL_DSSVP_GAMMA_TABLE_INDEX_MAX                         (0x000000ffU)

#define CSL_DSSVP_GAMMA_TABLE_VALUE_G_MASK                      (0x0000FF00U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_G_SHIFT                     (8U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_G_RESETVAL                  (0x00000000U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_G_MAX                       (0x000000ffU)

#define CSL_DSSVP_GAMMA_TABLE_VALUE_B_MASK                      (0x000000FFU)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_B_SHIFT                     (0U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_B_RESETVAL                  (0x00000000U)
#define CSL_DSSVP_GAMMA_TABLE_VALUE_B_MAX                       (0x000000ffU)

#define CSL_DSSVP_GAMMA_TABLE_RESETVAL                          (0x00000000U)

/* IRQENABLE */

#define CSL_DSSVP_IRQENABLE_VPVSYNC_ODD_EN_MASK                 (0x00000004U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_ODD_EN_SHIFT                (2U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_ODD_EN_RESETVAL             (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_ODD_EN_MASKED               (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_ODD_EN_GENINT               (0x00000001U)

#define CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_MASK                 (0x00000001U)
#define CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_SHIFT                (0U)
#define CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_RESETVAL             (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_MASKED               (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_GENINT               (0x00000001U)

#define CSL_DSSVP_IRQENABLE_VPVSYNC_EN_MASK                     (0x00000002U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_EN_SHIFT                    (1U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_EN_RESETVAL                 (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_EN_MASKED                   (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPVSYNC_EN_GENINT                   (0x00000001U)

#define CSL_DSSVP_IRQENABLE_VPSYNCLOST_EN_MASK                  (0x00000010U)
#define CSL_DSSVP_IRQENABLE_VPSYNCLOST_EN_SHIFT                 (4U)
#define CSL_DSSVP_IRQENABLE_VPSYNCLOST_EN_RESETVAL              (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPSYNCLOST_EN_MASKED                (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPSYNCLOST_EN_GENINT                (0x00000001U)

#define CSL_DSSVP_IRQENABLE_VPPROGRAMMEDLINENUMBER_EN_MASK      (0x00000008U)
#define CSL_DSSVP_IRQENABLE_VPPROGRAMMEDLINENUMBER_EN_SHIFT     (3U)
#define CSL_DSSVP_IRQENABLE_VPPROGRAMMEDLINENUMBER_EN_RESETVAL  (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPPROGRAMMEDLINENUMBER_EN_MASKED    (0x00000000U)
#define CSL_DSSVP_IRQENABLE_VPPROGRAMMEDLINENUMBER_EN_GENINT    (0x00000001U)

#define CSL_DSSVP_IRQENABLE_ACBIASCOUNTSTATUS_EN_MASK           (0x00000020U)
#define CSL_DSSVP_IRQENABLE_ACBIASCOUNTSTATUS_EN_SHIFT          (5U)
#define CSL_DSSVP_IRQENABLE_ACBIASCOUNTSTATUS_EN_RESETVAL       (0x00000000U)
#define CSL_DSSVP_IRQENABLE_ACBIASCOUNTSTATUS_EN_MASKED         (0x00000000U)
#define CSL_DSSVP_IRQENABLE_ACBIASCOUNTSTATUS_EN_GENINT         (0x00000001U)

#define CSL_DSSVP_IRQENABLE_RESETVAL                            (0x00000000U)

/* IRQSTATUS */

#define CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_MASK                 (0x00000010U)
#define CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_SHIFT                (4U)
#define CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_RESETVAL             (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_FALSE                (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_TRUE                 (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_MASK     (0x00000008U)
#define CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_SHIFT    (3U)
#define CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_RESETVAL  (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_FALSE    (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_TRUE     (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_MASK                (0x00000001U)
#define CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_SHIFT               (0U)
#define CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_RESETVAL            (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_FALSE               (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_TRUE                (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_VPVSYNC_IRQ_MASK                    (0x00000002U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_IRQ_SHIFT                   (1U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_IRQ_RESETVAL                (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_IRQ_FALSE                   (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_IRQ_TRUE                    (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_VPVSYNC_ODD_IRQ_MASK                (0x00000004U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_ODD_IRQ_SHIFT               (2U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_ODD_IRQ_RESETVAL            (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_ODD_IRQ_FALSE               (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_VPVSYNC_ODD_IRQ_TRUE                (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_ACBIASCOUNTSTATUS_IRQ_MASK          (0x00000020U)
#define CSL_DSSVP_IRQSTATUS_ACBIASCOUNTSTATUS_IRQ_SHIFT         (5U)
#define CSL_DSSVP_IRQSTATUS_ACBIASCOUNTSTATUS_IRQ_RESETVAL      (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_ACBIASCOUNTSTATUS_IRQ_FALSE         (0x00000000U)
#define CSL_DSSVP_IRQSTATUS_ACBIASCOUNTSTATUS_IRQ_TRUE          (0x00000001U)

#define CSL_DSSVP_IRQSTATUS_RESETVAL                            (0x00000000U)

/* LINE_NUMBER */

#define CSL_DSSVP_LINE_NUMBER_LINENUMBER_MASK                   (0x00000FFFU)
#define CSL_DSSVP_LINE_NUMBER_LINENUMBER_SHIFT                  (0U)
#define CSL_DSSVP_LINE_NUMBER_LINENUMBER_RESETVAL               (0x00000000U)
#define CSL_DSSVP_LINE_NUMBER_LINENUMBER_MAX                    (0x00000fffU)

#define CSL_DSSVP_LINE_NUMBER_RESETVAL                          (0x00000000U)

/* POL_FREQ */

#define CSL_DSSVP_POL_FREQ_IHS_MASK                             (0x00002000U)
#define CSL_DSSVP_POL_FREQ_IHS_SHIFT                            (13U)
#define CSL_DSSVP_POL_FREQ_IHS_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IHS_LCKPINAH                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IHS_LCKPINAL                         (0x00000001U)

#define CSL_DSSVP_POL_FREQ_IEO_MASK                             (0x00008000U)
#define CSL_DSSVP_POL_FREQ_IEO_SHIFT                            (15U)
#define CSL_DSSVP_POL_FREQ_IEO_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IEO_ACBAHIGH                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IEO_ACBALOW                          (0x00000001U)

#define CSL_DSSVP_POL_FREQ_ONOFF_MASK                           (0x00020000U)
#define CSL_DSSVP_POL_FREQ_ONOFF_SHIFT                          (17U)
#define CSL_DSSVP_POL_FREQ_ONOFF_RESETVAL                       (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ONOFF_DOPEDPCK                       (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ONOFF_DBIT16                         (0x00000001U)

#define CSL_DSSVP_POL_FREQ_IVS_MASK                             (0x00001000U)
#define CSL_DSSVP_POL_FREQ_IVS_SHIFT                            (12U)
#define CSL_DSSVP_POL_FREQ_IVS_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IVS_FCKPINAH                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IVS_FCKPINAL                         (0x00000001U)

#define CSL_DSSVP_POL_FREQ_IPC_MASK                             (0x00004000U)
#define CSL_DSSVP_POL_FREQ_IPC_SHIFT                            (14U)
#define CSL_DSSVP_POL_FREQ_IPC_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IPC_DRPCK                            (0x00000000U)
#define CSL_DSSVP_POL_FREQ_IPC_DFPCK                            (0x00000001U)

#define CSL_DSSVP_POL_FREQ_RF_MASK                              (0x00010000U)
#define CSL_DSSVP_POL_FREQ_RF_SHIFT                             (16U)
#define CSL_DSSVP_POL_FREQ_RF_RESETVAL                          (0x00000000U)
#define CSL_DSSVP_POL_FREQ_RF_DFEDPCK                           (0x00000000U)
#define CSL_DSSVP_POL_FREQ_RF_DRIEDPCK                          (0x00000001U)

#define CSL_DSSVP_POL_FREQ_ALIGN_MASK                           (0x00040000U)
#define CSL_DSSVP_POL_FREQ_ALIGN_SHIFT                          (18U)
#define CSL_DSSVP_POL_FREQ_ALIGN_RESETVAL                       (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ALIGN_NOTALIGNED                     (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ALIGN_ALIGNED                        (0x00000001U)

#define CSL_DSSVP_POL_FREQ_ACB_MASK                             (0x000000FFU)
#define CSL_DSSVP_POL_FREQ_ACB_SHIFT                            (0U)
#define CSL_DSSVP_POL_FREQ_ACB_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ACB_MAX                              (0x000000ffU)

#define CSL_DSSVP_POL_FREQ_ACBI_MASK                            (0x00000F00U)
#define CSL_DSSVP_POL_FREQ_ACBI_SHIFT                           (8U)
#define CSL_DSSVP_POL_FREQ_ACBI_RESETVAL                        (0x00000000U)
#define CSL_DSSVP_POL_FREQ_ACBI_MAX                             (0x0000000fU)

#define CSL_DSSVP_POL_FREQ_RESETVAL                             (0x00000000U)

/* SIZE_SCREEN */

#define CSL_DSSVP_SIZE_SCREEN_LPP_MASK                          (0x0FFF0000U)
#define CSL_DSSVP_SIZE_SCREEN_LPP_SHIFT                         (16U)
#define CSL_DSSVP_SIZE_SCREEN_LPP_RESETVAL                      (0x00000000U)
#define CSL_DSSVP_SIZE_SCREEN_LPP_MAX                           (0x00000fffU)

#define CSL_DSSVP_SIZE_SCREEN_PPL_MASK                          (0x00000FFFU)
#define CSL_DSSVP_SIZE_SCREEN_PPL_SHIFT                         (0U)
#define CSL_DSSVP_SIZE_SCREEN_PPL_RESETVAL                      (0x00000000U)
#define CSL_DSSVP_SIZE_SCREEN_PPL_MAX                           (0x00000fffU)

#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_MASK                    (0x0000C000U)
#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_SHIFT                   (14U)
#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_RESETVAL                (0x00000000U)
#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_SAME                    (0x00000000U)
#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_PLUSONE                 (0x00000001U)
#define CSL_DSSVP_SIZE_SCREEN_DELTA_LPP_MINUSONE                (0x00000002U)

#define CSL_DSSVP_SIZE_SCREEN_RESETVAL                          (0x00000000U)

/* TIMING_H */

#define CSL_DSSVP_TIMING_H_HBP_MASK                             (0xFFF00000U)
#define CSL_DSSVP_TIMING_H_HBP_SHIFT                            (20U)
#define CSL_DSSVP_TIMING_H_HBP_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_H_HBP_MAX                              (0x00000fffU)

#define CSL_DSSVP_TIMING_H_HFP_MASK                             (0x000FFF00U)
#define CSL_DSSVP_TIMING_H_HFP_SHIFT                            (8U)
#define CSL_DSSVP_TIMING_H_HFP_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_H_HFP_MAX                              (0x00000fffU)

#define CSL_DSSVP_TIMING_H_HSW_MASK                             (0x000000FFU)
#define CSL_DSSVP_TIMING_H_HSW_SHIFT                            (0U)
#define CSL_DSSVP_TIMING_H_HSW_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_H_HSW_MAX                              (0x000000ffU)

#define CSL_DSSVP_TIMING_H_RESETVAL                             (0x00000000U)

/* TIMING_V */

#define CSL_DSSVP_TIMING_V_VBP_MASK                             (0xFFF00000U)
#define CSL_DSSVP_TIMING_V_VBP_SHIFT                            (20U)
#define CSL_DSSVP_TIMING_V_VBP_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_V_VBP_MAX                              (0x00000fffU)

#define CSL_DSSVP_TIMING_V_VFP_MASK                             (0x000FFF00U)
#define CSL_DSSVP_TIMING_V_VFP_SHIFT                            (8U)
#define CSL_DSSVP_TIMING_V_VFP_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_V_VFP_MAX                              (0x00000fffU)

#define CSL_DSSVP_TIMING_V_VSW_MASK                             (0x000000FFU)
#define CSL_DSSVP_TIMING_V_VSW_SHIFT                            (0U)
#define CSL_DSSVP_TIMING_V_VSW_RESETVAL                         (0x00000000U)
#define CSL_DSSVP_TIMING_V_VSW_MAX                              (0x000000ffU)

#define CSL_DSSVP_TIMING_V_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
