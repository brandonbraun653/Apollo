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
#ifndef CSLR_DSSVID_H_
#define CSLR_DSSVID_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for VID_ALL
**************************************************************************/
typedef struct {
    volatile Uint32 ACCUH[2];
    volatile Uint32 ACCUH2[2];
    volatile Uint32 ACCUV[2];
    volatile Uint32 ACCUV2[2];
    volatile Uint32 ATTRIBUTES;
    volatile Uint32 ATTRIBUTES2;
    volatile Uint32 BA[2];
    volatile Uint32 BA_UV[2];
    volatile Uint32 BUF_SIZE_STATUS;
    volatile Uint32 BUF_THRESHOLD;
    volatile Uint32 CONV_COEF0;
    volatile Uint32 CONV_COEF1;
    volatile Uint32 CONV_COEF2;
    volatile Uint32 CONV_COEF3;
    volatile Uint32 CONV_COEF4;
    volatile Uint32 CONV_COEF5;
    volatile Uint32 CONV_COEF6;
    volatile Uint32 FIRH;
    volatile Uint32 FIRH2;
    volatile Uint32 FIRV;
    volatile Uint32 FIRV2;
    volatile Uint32 FIR_COEF_H0[9];
    volatile Uint32 FIR_COEF_H0_C[9];
    volatile Uint32 FIR_COEF_H12[16];
    volatile Uint32 FIR_COEF_H12_C[16];
    volatile Uint32 FIR_COEF_V0[9];
    volatile Uint32 FIR_COEF_V0_C[9];
    volatile Uint32 FIR_COEF_V12[16];
    volatile Uint32 FIR_COEF_V12_C[16];
    volatile Uint32 GLOBAL_ALPHA;
    volatile Uint32 IRQENABLE;
    volatile Uint32 IRQSTATUS;
    volatile Uint32 MFLAG_THRESHOLD;
    volatile Uint32 PICTURE_SIZE;
    volatile Uint32 PIXEL_INC;
    volatile Uint32 POSITION;
    volatile Uint32 PRELOAD;
    volatile Uint32 ROW_INC;
    volatile Uint32 SIZE;
    volatile Uint32 CLUT;
} CSL_DssVidRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* The register configures the resize accumulator init values for horizontal 
 * up/down-sampling of the video window (DISPC_VIDx_ACCU__0 & 
 * DISPC_VIDx_ACCU__1 for ping-pong mechanism with external trigger, based on 
 * the field polarity) It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_ACCUH(i)                                     (0x0U + ((i) * (0x4U)))

/* The register configures the resize accumulator init value for horizontal 
 * up/down-sampling of the video window (DISPC_VID#n_ACCU2__0 & 
 * DISPC_VID#n_ACCU2__1 for ping-pong mechanism with external trigger, based 
 * on the field polarity) It is used for Cb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_ACCUH2(i)                                    (0x8U + ((i) * (0x4U)))

/* The register configures the resize accumulator init values for horizontal 
 * and vertical up/down-sampling of the video window (DISPC_VIDx_ACCU__0 & 
 * DISPC_VIDx_ACCU__1 for ping-pong mechanism with external trigger, based on 
 * the field polarity) It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_ACCUV(i)                                     (0x10U + ((i) * (0x4U)))

/* The register configures the resize accumulator init value for vertical 
 * up/down-sampling of the video window (DISPC_VID1_ACCU2__0 & 
 * DISPC_VID1_ACCU2__1 for ping-pong mechanism with external trigger, based on 
 * the field polarity) It is used for Cb and Cr setting. It is used only when 
 * the pixel format at the input of the filter is one of the YUV formats. If 
 * the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_ACCUV2(i)                                    (0x18U + ((i) * (0x4U)))

/* The register configures the attributes of the video window. Shadow 
 * register. */
#define CSL_DSSVID_ATTRIBUTES                                   (0x20U)

/* The register configures the attributes of the video window. Shadow 
 * register. */
#define CSL_DSSVID_ATTRIBUTES2                                  (0x24U)

/* The register configures the base address of the video buffer for the video 
 * window (DISPC_VID1_BA__0 & DISPC_VID1_BA__1 for ping-pong mechanism with 
 * external trigger, based on the field polarity otherwise only 
 * DISPC_VID1_BA__0 is used). Shadow register. */
#define CSL_DSSVID_BA(i)                                        (0x28U + ((i) * (0x4U)))

/* The register configures the base address of the UV buffer for the video 
 * window. (DISPC_VID1_BA_UV__0 & DISPC_VID1_BA_UV__1 for ping-pong mechanism 
 * with external trigger, based on the field polarity otherwise only 
 * DISPC_VID1_BA_UV__0 is used)). The register is also used to configure the 
 * RGB plane BA for RGB565A8 format Shadow register. */
#define CSL_DSSVID_BA_UV(i)                                     (0x30U + ((i) * (0x4U)))

/* The register defines the Video buffer size for the video pipeline. */
#define CSL_DSSVID_BUF_SIZE_STATUS                              (0x38U)

/* The register configures the video buffer associated with the video 
 * pipeline. Shadow register. */
#define CSL_DSSVID_BUF_THRESHOLD                                (0x3CU)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF0                                   (0x40U)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF1                                   (0x44U)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF2                                   (0x48U)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF3                                   (0x4CU)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF4                                   (0x50U)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF5                                   (0x54U)

/* The register configures the color space conversion matrix coefficients for 
 * the video pipeline. Shadow register. */
#define CSL_DSSVID_CONV_COEF6                                   (0x58U)

/* The register configures the resize factor for horizontal up/down-sampling 
 * of the video window. It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIRH                                         (0x5CU)

/* The register configures the resize factor for horizontal up/down-sampling 
 * of the video window. It is used for Crb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIRH2                                        (0x60U)

/* The register configures the resize factor for vertical up/down-sampling of 
 * the video window. It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIRV                                         (0x64U)

/* The register configures the resize factor for vertical up/down-sampling of 
 * the video window. It is used for Crb and Cr setting. It is used only when 
 * the pixel format at the input of the filter is one of the YUV formats. If 
 * the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIRV2                                        (0x68U)

/* The bank of registers configure the up/down-scaling coefficients for the 
 * horizontal resize of the video picture associated with the video window for 
 * the 16 phases It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIR_COEF_H0(i)                               (0x6CU + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * horizontal resize of the video picture associated with the video window for 
 * the phases from 0 to 15. It is used for Crb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIR_COEF_H0_C(i)                             (0x90U + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * horizontal resize of the video picture associated with the video window for 
 * the 16 phases It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIR_COEF_H12(i)                              (0xB4U + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * horizontal resize of the video picture associated with the video window for 
 * the phases from 0 to 15. It is used for Crb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIR_COEF_H12_C(i)                            (0xF4U + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * vertical resize of the video picture associated with the video window for 
 * the 16 phases It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIR_COEF_V0(i)                               (0x134U + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * vertical resize of the video picture associated with the video window for 
 * the phases from 0 to 15. It is used for Crb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIR_COEF_V0_C(i)                             (0x158U + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * vertical resize of the video picture associated with the video window for 
 * the 16 phases It is used for ARGB and Y setting. Shadow register. */
#define CSL_DSSVID_FIR_COEF_V12(i)                              (0x17CU + ((i) * (0x4U)))

/* The bank of registers configure the up/down-scaling coefficients for the 
 * vertical resize of the video picture associated with the video window for 
 * the phases from 0 to 15. It is used for Crb and Cr setting. It is used only 
 * when the pixel format at the input of the filter is one of the YUV formats. 
 * If the pixel format at the input of the filter is ARGB (all ARGB, RGB, RGBA 
 * are converted to ARGB32-8888 by the color space conversion before going to 
 * the filter is the color space conversion is done before the filter). When 
 * the register is not used by the HW, any value can be used for the 
 * bit-fields. Shadow register. */
#define CSL_DSSVID_FIR_COEF_V12_C(i)                            (0x1BCU + ((i) * (0x4U)))

/* The register defines the global alpha value for the video pipeline. Shadow 
 * register. */
#define CSL_DSSVID_GLOBAL_ALPHA                                 (0x1FCU)

/* This register allows to mask/unmask the module internal sources of 
 * interrupt, on an event-by-event basis */
#define CSL_DSSVID_IRQENABLE                                    (0x200U)

/* This register regroups all the status of the module internal events that 
 * generate an interrupt. Write 1 to a given bit resets this bit */
#define CSL_DSSVID_IRQSTATUS                                    (0x204U)

/* MFLAG_THRESHOLD */
#define CSL_DSSVID_MFLAG_THRESHOLD                              (0x208U)

/* The register configures the size of the video picture associated with the 
 * video layer before up/down-scaling. Shadow register. */
#define CSL_DSSVID_PICTURE_SIZE                                 (0x20CU)

/* The register configures the number of bytes to increment between two pixels 
 * for the buffer associated with the video window. The register is used only 
 * when the TILER is not present in the system in order to perform low 
 * performance rotation. When the TILER IP is present it is highly recommanded 
 * to use it for performing the rotation. Shadow register. */
#define CSL_DSSVID_PIXEL_INC                                    (0x210U)

/* The register configures the position of the video window. Shadow register. */
#define CSL_DSSVID_POSITION                                     (0x214U)

/* The register configures the DMA buffer of the video pipeline. Shadow 
 * register. */
#define CSL_DSSVID_PRELOAD                                      (0x218U)

/* The register configures the number of bytes to increment at the end of the 
 * row for the buffer associated with the video window. Shadow register. */
#define CSL_DSSVID_ROW_INC                                      (0x21CU)

/* The register configures the size of the video window. Shadow register. */
#define CSL_DSSVID_SIZE                                         (0x220U)

/* The register configures the Color Look Up Table (CLUT) for VID pipeline. 
 * CLUT is used in conjunction with bitmap formats */
#define CSL_DSSVID_CLUT                                         (0x224U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ACCUH */

#define CSL_DSSVID_ACCUH_HORIZONTALACCU_MASK                    (0x00FFFFFFU)
#define CSL_DSSVID_ACCUH_HORIZONTALACCU_SHIFT                   (0U)
#define CSL_DSSVID_ACCUH_HORIZONTALACCU_RESETVAL                (0x00000000U)
#define CSL_DSSVID_ACCUH_HORIZONTALACCU_MAX                     (0x00ffffffU)

#define CSL_DSSVID_ACCUH_RESETVAL                               (0x00000000U)

/* ACCUH2 */

#define CSL_DSSVID_ACCUH2_HORIZONTALACCU_MASK                   (0x00FFFFFFU)
#define CSL_DSSVID_ACCUH2_HORIZONTALACCU_SHIFT                  (0U)
#define CSL_DSSVID_ACCUH2_HORIZONTALACCU_RESETVAL               (0x00000000U)
#define CSL_DSSVID_ACCUH2_HORIZONTALACCU_MAX                    (0x00ffffffU)

#define CSL_DSSVID_ACCUH2_RESETVAL                              (0x00000000U)

/* ACCUV */

#define CSL_DSSVID_ACCUV_VERTICALACCU_MASK                      (0x00FFFFFFU)
#define CSL_DSSVID_ACCUV_VERTICALACCU_SHIFT                     (0U)
#define CSL_DSSVID_ACCUV_VERTICALACCU_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_ACCUV_VERTICALACCU_MAX                       (0x00ffffffU)

#define CSL_DSSVID_ACCUV_RESETVAL                               (0x00000000U)

/* ACCUV2 */

#define CSL_DSSVID_ACCUV2_VERTICALACCU_MASK                     (0x00FFFFFFU)
#define CSL_DSSVID_ACCUV2_VERTICALACCU_SHIFT                    (0U)
#define CSL_DSSVID_ACCUV2_VERTICALACCU_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_ACCUV2_VERTICALACCU_MAX                      (0x00ffffffU)

#define CSL_DSSVID_ACCUV2_RESETVAL                              (0x00000000U)

/* ATTRIBUTES */

#define CSL_DSSVID_ATTRIBUTES_SELFREFRESHAUTO_MASK              (0x00020000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESHAUTO_SHIFT             (17U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESHAUTO_RESETVAL          (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESHAUTO_SELFREFRESHAUTODIS  (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESHAUTO_SELFREFRESHAUTOEN  (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_FULLRANGE_MASK                    (0x00000800U)
#define CSL_DSSVID_ATTRIBUTES_FULLRANGE_SHIFT                   (11U)
#define CSL_DSSVID_ATTRIBUTES_FULLRANGE_RESETVAL                (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_FULLRANGE_LIMRANGE                (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_FULLRANGE_FULLRANGE               (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_CHANNELOUT_MASK                   (0x0001C000U)
#define CSL_DSSVID_ATTRIBUTES_CHANNELOUT_SHIFT                  (14U)
#define CSL_DSSVID_ATTRIBUTES_CHANNELOUT_RESETVAL               (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_CHANNELOUT_VP1SEL                 (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_CHANNELOUT_WBSEL                  (0x00000004U)

#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_MASK                 (0x00000180U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_SHIFT                (7U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_RESETVAL             (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_RESIZEPROC           (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_HRESIZE              (0x00000001U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_VRESIZE              (0x00000002U)
#define CSL_DSSVID_ATTRIBUTES_RESIZEENABLE_HVRESIZE             (0x00000003U)

#define CSL_DSSVID_ATTRIBUTES_COLORCONVENABLE_MASK              (0x00000200U)
#define CSL_DSSVID_ATTRIBUTES_COLORCONVENABLE_SHIFT             (9U)
#define CSL_DSSVID_ATTRIBUTES_COLORCONVENABLE_RESETVAL          (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_COLORCONVENABLE_COLSPCDIS         (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_COLORCONVENABLE_COLSPCENB         (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_ENABLE_MASK                       (0x00000001U)
#define CSL_DSSVID_ATTRIBUTES_ENABLE_SHIFT                      (0U)
#define CSL_DSSVID_ATTRIBUTES_ENABLE_RESETVAL                   (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ENABLE_VIDEODIS                   (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ENABLE_VIDEOENB                   (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_FORMAT_MASK                       (0x0000007EU)
#define CSL_DSSVID_ATTRIBUTES_FORMAT_SHIFT                      (1U)
#define CSL_DSSVID_ATTRIBUTES_FORMAT_RESETVAL                   (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_FORMAT_MAX                        (0x0000003fU)

#define CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_MASK                   (0x00080000U)
#define CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_SHIFT                  (19U)
#define CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_RESETVAL               (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_DEFVAL                 (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_HIGHTHRES              (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_VERTICALTAPS_MASK                 (0x00200000U)
#define CSL_DSSVID_ATTRIBUTES_VERTICALTAPS_SHIFT                (21U)
#define CSL_DSSVID_ATTRIBUTES_VERTICALTAPS_RESETVAL             (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_VERTICALTAPS_TAPS3                (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_VERTICALTAPS_TAPS5                (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_SELFREFRESH_MASK                  (0x01000000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESH_SHIFT                 (24U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESH_RESETVAL              (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESH_SELFREFRESHDIS        (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_SELFREFRESH_SELFREFRESHENB        (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_ARBITRATION_MASK                  (0x00800000U)
#define CSL_DSSVID_ATTRIBUTES_ARBITRATION_SHIFT                 (23U)
#define CSL_DSSVID_ATTRIBUTES_ARBITRATION_RESETVAL              (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ARBITRATION_NORMALPRIO            (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ARBITRATION_HIGHPRIO              (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_ZORDER_MASK                       (0x0E000000U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_SHIFT                      (25U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_RESETVAL                   (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER0                    (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER1                    (0x00000001U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER2                    (0x00000002U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER3                    (0x00000003U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER4                    (0x00000004U)
#define CSL_DSSVID_ATTRIBUTES_ZORDER_ZORDER5                    (0x00000005U)

#define CSL_DSSVID_ATTRIBUTES_PREMULTIPLYALPHA_MASK             (0x10000000U)
#define CSL_DSSVID_ATTRIBUTES_PREMULTIPLYALPHA_SHIFT            (28U)
#define CSL_DSSVID_ATTRIBUTES_PREMULTIPLYALPHA_RESETVAL         (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_PREMULTIPLYALPHA_NONPREMULTIPLIEDALPHA  (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_PREMULTIPLYALPHA_PREMULTIPLIEDALPHA  (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_DOUBLESTRIDE_MASK                 (0x00400000U)
#define CSL_DSSVID_ATTRIBUTES_DOUBLESTRIDE_SHIFT                (22U)
#define CSL_DSSVID_ATTRIBUTES_DOUBLESTRIDE_RESETVAL             (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_DOUBLESTRIDE_INITIAL              (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_DOUBLESTRIDE_DOUBLE               (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_BURSTTYPE_MASK                    (0x20000000U)
#define CSL_DSSVID_ATTRIBUTES_BURSTTYPE_SHIFT                   (29U)
#define CSL_DSSVID_ATTRIBUTES_BURSTTYPE_RESETVAL                (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_BURSTTYPE_INC                     (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_BURSTTYPE_BLCK                    (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_ROTATION_MASK                     (0x00003000U)
#define CSL_DSSVID_ATTRIBUTES_ROTATION_SHIFT                    (12U)
#define CSL_DSSVID_ATTRIBUTES_ROTATION_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_ROTATION_MAX                      (0x00000003U)

#define CSL_DSSVID_ATTRIBUTES_FORCE1DTILEDMODE_MASK             (0x00100000U)
#define CSL_DSSVID_ATTRIBUTES_FORCE1DTILEDMODE_SHIFT            (20U)
#define CSL_DSSVID_ATTRIBUTES_FORCE1DTILEDMODE_RESETVAL         (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_FORCE1DTILEDMODE_TILEDREGIONS2DACCESS  (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_FORCE1DTILEDMODE_TILEDREGIONS1DACCESS  (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_MASK                   (0x00000400U)
#define CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_SHIFT                  (10U)
#define CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_RESETVAL               (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_NIBBLEMODEDIS          (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_NIBBLEMODEEN           (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES_RESETVAL                          (0x00000000U)

/* ATTRIBUTES2 */

#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_Y_MASK                 (0x0000000EU)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_Y_SHIFT                (1U)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_Y_RESETVAL             (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_Y_MAX                  (0x00000007U)

#define CSL_DSSVID_ATTRIBUTES2_VC1ENABLE_MASK                   (0x00000001U)
#define CSL_DSSVID_ATTRIBUTES2_VC1ENABLE_SHIFT                  (0U)
#define CSL_DSSVID_ATTRIBUTES2_VC1ENABLE_RESETVAL               (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_VC1ENABLE_VC1DIS                 (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_VC1ENABLE_VC1ENB                 (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_CBCR_MASK              (0x00000070U)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_CBCR_SHIFT             (4U)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_CBCR_RESETVAL          (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_VC1_RANGE_CBCR_MAX               (0x00000007U)

#define CSL_DSSVID_ATTRIBUTES2_SECURE_MASK                      (0x00010000U)
#define CSL_DSSVID_ATTRIBUTES2_SECURE_SHIFT                     (16U)
#define CSL_DSSVID_ATTRIBUTES2_SECURE_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_SECURE_MAX                       (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES2_TAGS_MASK                        (0x7C000000U)
#define CSL_DSSVID_ATTRIBUTES2_TAGS_SHIFT                       (26U)
#define CSL_DSSVID_ATTRIBUTES2_TAGS_RESETVAL                    (0x0000001fU)
#define CSL_DSSVID_ATTRIBUTES2_TAGS_MAX                         (0x0000001fU)

#define CSL_DSSVID_ATTRIBUTES2_REGION_BASED_MASK                (0x01000000U)
#define CSL_DSSVID_ATTRIBUTES2_REGION_BASED_SHIFT               (24U)
#define CSL_DSSVID_ATTRIBUTES2_REGION_BASED_RESETVAL            (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_REGION_BASED_DISABLE             (0x00000000U)
#define CSL_DSSVID_ATTRIBUTES2_REGION_BASED_ENABLE              (0x00000001U)

#define CSL_DSSVID_ATTRIBUTES2_RESETVAL                         (0x7c000000U)

/* BA */

#define CSL_DSSVID_BA_BA_MASK                                   (0xFFFFFFFFU)
#define CSL_DSSVID_BA_BA_SHIFT                                  (0U)
#define CSL_DSSVID_BA_BA_RESETVAL                               (0x00000000U)
#define CSL_DSSVID_BA_BA_MAX                                    (0xffffffffU)

#define CSL_DSSVID_BA_RESETVAL                                  (0x00000000U)

/* BA_UV */

#define CSL_DSSVID_BA_UV_BA_MASK                                (0xFFFFFFFFU)
#define CSL_DSSVID_BA_UV_BA_SHIFT                               (0U)
#define CSL_DSSVID_BA_UV_BA_RESETVAL                            (0x00000000U)
#define CSL_DSSVID_BA_UV_BA_MAX                                 (0xffffffffU)

#define CSL_DSSVID_BA_UV_RESETVAL                               (0x00000000U)

/* BUF_SIZE_STATUS */

#define CSL_DSSVID_BUF_SIZE_STATUS_BUFSIZE_MASK                 (0x0000FFFFU)
#define CSL_DSSVID_BUF_SIZE_STATUS_BUFSIZE_SHIFT                (0U)
#define CSL_DSSVID_BUF_SIZE_STATUS_BUFSIZE_RESETVAL             (0x00000a00U)
#define CSL_DSSVID_BUF_SIZE_STATUS_BUFSIZE_MAX                  (0x0000ffffU)

#define CSL_DSSVID_BUF_SIZE_STATUS_RESETVAL                     (0x00000a00U)

/* BUF_THRESHOLD */

#define CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_MASK           (0x0000FFFFU)
#define CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_SHIFT          (0U)
#define CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_RESETVAL       (0x000009f8U)
#define CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_MAX            (0x0000ffffU)

#define CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_MASK          (0xFFFF0000U)
#define CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_SHIFT         (16U)
#define CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_RESETVAL      (0x000009ffU)
#define CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_MAX           (0x0000ffffU)

#define CSL_DSSVID_BUF_THRESHOLD_RESETVAL                       (0x09ff09f8U)

/* CONV_COEF0 */

#define CSL_DSSVID_CONV_COEF0_RCR_MASK                          (0x07FF0000U)
#define CSL_DSSVID_CONV_COEF0_RCR_SHIFT                         (16U)
#define CSL_DSSVID_CONV_COEF0_RCR_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF0_RCR_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF0_RY_MASK                           (0x000007FFU)
#define CSL_DSSVID_CONV_COEF0_RY_SHIFT                          (0U)
#define CSL_DSSVID_CONV_COEF0_RY_RESETVAL                       (0x00000000U)
#define CSL_DSSVID_CONV_COEF0_RY_MAX                            (0x000007ffU)

#define CSL_DSSVID_CONV_COEF0_RESETVAL                          (0x00000000U)

/* CONV_COEF1 */

#define CSL_DSSVID_CONV_COEF1_GY_MASK                           (0x07FF0000U)
#define CSL_DSSVID_CONV_COEF1_GY_SHIFT                          (16U)
#define CSL_DSSVID_CONV_COEF1_GY_RESETVAL                       (0x00000000U)
#define CSL_DSSVID_CONV_COEF1_GY_MAX                            (0x000007ffU)

#define CSL_DSSVID_CONV_COEF1_RCB_MASK                          (0x000007FFU)
#define CSL_DSSVID_CONV_COEF1_RCB_SHIFT                         (0U)
#define CSL_DSSVID_CONV_COEF1_RCB_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF1_RCB_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF1_RESETVAL                          (0x00000000U)

/* CONV_COEF2 */

#define CSL_DSSVID_CONV_COEF2_GCB_MASK                          (0x07FF0000U)
#define CSL_DSSVID_CONV_COEF2_GCB_SHIFT                         (16U)
#define CSL_DSSVID_CONV_COEF2_GCB_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF2_GCB_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF2_GCR_MASK                          (0x000007FFU)
#define CSL_DSSVID_CONV_COEF2_GCR_SHIFT                         (0U)
#define CSL_DSSVID_CONV_COEF2_GCR_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF2_GCR_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF2_RESETVAL                          (0x00000000U)

/* CONV_COEF3 */

#define CSL_DSSVID_CONV_COEF3_BCR_MASK                          (0x07FF0000U)
#define CSL_DSSVID_CONV_COEF3_BCR_SHIFT                         (16U)
#define CSL_DSSVID_CONV_COEF3_BCR_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF3_BCR_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF3_BY_MASK                           (0x000007FFU)
#define CSL_DSSVID_CONV_COEF3_BY_SHIFT                          (0U)
#define CSL_DSSVID_CONV_COEF3_BY_RESETVAL                       (0x00000000U)
#define CSL_DSSVID_CONV_COEF3_BY_MAX                            (0x000007ffU)

#define CSL_DSSVID_CONV_COEF3_RESETVAL                          (0x00000000U)

/* CONV_COEF4 */

#define CSL_DSSVID_CONV_COEF4_BCB_MASK                          (0x000007FFU)
#define CSL_DSSVID_CONV_COEF4_BCB_SHIFT                         (0U)
#define CSL_DSSVID_CONV_COEF4_BCB_RESETVAL                      (0x00000000U)
#define CSL_DSSVID_CONV_COEF4_BCB_MAX                           (0x000007ffU)

#define CSL_DSSVID_CONV_COEF4_RESETVAL                          (0x00000000U)

/* CONV_COEF5 */

#define CSL_DSSVID_CONV_COEF5_ROFFSET_MASK                      (0x0000FFF8U)
#define CSL_DSSVID_CONV_COEF5_ROFFSET_SHIFT                     (3U)
#define CSL_DSSVID_CONV_COEF5_ROFFSET_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_CONV_COEF5_ROFFSET_MAX                       (0x00001fffU)

#define CSL_DSSVID_CONV_COEF5_GOFFSET_MASK                      (0xFFF80000U)
#define CSL_DSSVID_CONV_COEF5_GOFFSET_SHIFT                     (19U)
#define CSL_DSSVID_CONV_COEF5_GOFFSET_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_CONV_COEF5_GOFFSET_MAX                       (0x00001fffU)

#define CSL_DSSVID_CONV_COEF5_RESETVAL                          (0x00000000U)

/* CONV_COEF6 */

#define CSL_DSSVID_CONV_COEF6_BOFFSET_MASK                      (0x0000FFF8U)
#define CSL_DSSVID_CONV_COEF6_BOFFSET_SHIFT                     (3U)
#define CSL_DSSVID_CONV_COEF6_BOFFSET_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_CONV_COEF6_BOFFSET_MAX                       (0x00001fffU)

#define CSL_DSSVID_CONV_COEF6_RESETVAL                          (0x00000000U)

/* FIRH */

#define CSL_DSSVID_FIRH_FIRHINC_MASK                            (0x00FFFFFFU)
#define CSL_DSSVID_FIRH_FIRHINC_SHIFT                           (0U)
#define CSL_DSSVID_FIRH_FIRHINC_RESETVAL                        (0x00200000U)
#define CSL_DSSVID_FIRH_FIRHINC_MAX                             (0x00ffffffU)

#define CSL_DSSVID_FIRH_RESETVAL                                (0x00200000U)

/* FIRH2 */

#define CSL_DSSVID_FIRH2_FIRHINC_MASK                           (0x00FFFFFFU)
#define CSL_DSSVID_FIRH2_FIRHINC_SHIFT                          (0U)
#define CSL_DSSVID_FIRH2_FIRHINC_RESETVAL                       (0x00200000U)
#define CSL_DSSVID_FIRH2_FIRHINC_MAX                            (0x00ffffffU)

#define CSL_DSSVID_FIRH2_RESETVAL                               (0x00200000U)

/* FIRV */

#define CSL_DSSVID_FIRV_FIRVINC_MASK                            (0x00FFFFFFU)
#define CSL_DSSVID_FIRV_FIRVINC_SHIFT                           (0U)
#define CSL_DSSVID_FIRV_FIRVINC_RESETVAL                        (0x00200000U)
#define CSL_DSSVID_FIRV_FIRVINC_MAX                             (0x00ffffffU)

#define CSL_DSSVID_FIRV_RESETVAL                                (0x00200000U)

/* FIRV2 */

#define CSL_DSSVID_FIRV2_FIRVINC_MASK                           (0x00FFFFFFU)
#define CSL_DSSVID_FIRV2_FIRVINC_SHIFT                          (0U)
#define CSL_DSSVID_FIRV2_FIRVINC_RESETVAL                       (0x00200000U)
#define CSL_DSSVID_FIRV2_FIRVINC_MAX                            (0x00ffffffU)

#define CSL_DSSVID_FIRV2_RESETVAL                               (0x00200000U)

/* FIR_COEF_H0 */

#define CSL_DSSVID_FIR_COEF_H0_FIRHC0_MASK                      (0x000003FFU)
#define CSL_DSSVID_FIR_COEF_H0_FIRHC0_SHIFT                     (0U)
#define CSL_DSSVID_FIR_COEF_H0_FIRHC0_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H0_FIRHC0_MAX                       (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H0_RESETVAL                         (0x00000000U)

/* FIR_COEF_H0_C */

#define CSL_DSSVID_FIR_COEF_H0_C_FIRHC0_MASK                    (0x000003FFU)
#define CSL_DSSVID_FIR_COEF_H0_C_FIRHC0_SHIFT                   (0U)
#define CSL_DSSVID_FIR_COEF_H0_C_FIRHC0_RESETVAL                (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H0_C_FIRHC0_MAX                     (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H0_C_RESETVAL                       (0x00000000U)

/* FIR_COEF_H12 */

#define CSL_DSSVID_FIR_COEF_H12_FIRHC2_MASK                     (0x3FF00000U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC2_SHIFT                    (20U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC2_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC2_MAX                      (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H12_FIRHC1_MASK                     (0x000FFC00U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC1_SHIFT                    (10U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC1_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H12_FIRHC1_MAX                      (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H12_RESETVAL                        (0x00000000U)

/* FIR_COEF_H12_C */

#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC2_MASK                   (0x3FF00000U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC2_SHIFT                  (20U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC2_RESETVAL               (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC2_MAX                    (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC1_MASK                   (0x000FFC00U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC1_SHIFT                  (10U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC1_RESETVAL               (0x00000000U)
#define CSL_DSSVID_FIR_COEF_H12_C_FIRHC1_MAX                    (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_H12_C_RESETVAL                      (0x00000000U)

/* FIR_COEF_V0 */

#define CSL_DSSVID_FIR_COEF_V0_FIRVC0_MASK                      (0x000003FFU)
#define CSL_DSSVID_FIR_COEF_V0_FIRVC0_SHIFT                     (0U)
#define CSL_DSSVID_FIR_COEF_V0_FIRVC0_RESETVAL                  (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V0_FIRVC0_MAX                       (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V0_RESETVAL                         (0x00000000U)

/* FIR_COEF_V0_C */

#define CSL_DSSVID_FIR_COEF_V0_C_FIRVC0_MASK                    (0x000003FFU)
#define CSL_DSSVID_FIR_COEF_V0_C_FIRVC0_SHIFT                   (0U)
#define CSL_DSSVID_FIR_COEF_V0_C_FIRVC0_RESETVAL                (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V0_C_FIRVC0_MAX                     (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V0_C_RESETVAL                       (0x00000000U)

/* FIR_COEF_V12 */

#define CSL_DSSVID_FIR_COEF_V12_FIRVC1_MASK                     (0x000FFC00U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC1_SHIFT                    (10U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC1_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC1_MAX                      (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V12_FIRVC2_MASK                     (0x3FF00000U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC2_SHIFT                    (20U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC2_RESETVAL                 (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V12_FIRVC2_MAX                      (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V12_RESETVAL                        (0x00000000U)

/* FIR_COEF_V12_C */

#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC1_MASK                   (0x000FFC00U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC1_SHIFT                  (10U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC1_RESETVAL               (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC1_MAX                    (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC2_MASK                   (0x3FF00000U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC2_SHIFT                  (20U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC2_RESETVAL               (0x00000000U)
#define CSL_DSSVID_FIR_COEF_V12_C_FIRVC2_MAX                    (0x000003ffU)

#define CSL_DSSVID_FIR_COEF_V12_C_RESETVAL                      (0x00000000U)

/* GLOBAL_ALPHA */

#define CSL_DSSVID_GLOBAL_ALPHA_GLOBALALPHA_MASK                (0x000000FFU)
#define CSL_DSSVID_GLOBAL_ALPHA_GLOBALALPHA_SHIFT               (0U)
#define CSL_DSSVID_GLOBAL_ALPHA_GLOBALALPHA_RESETVAL            (0x000000ffU)
#define CSL_DSSVID_GLOBAL_ALPHA_GLOBALALPHA_MAX                 (0x000000ffU)

#define CSL_DSSVID_GLOBAL_ALPHA_RESETVAL                        (0x000000ffU)

/* IRQENABLE */

#define CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_MASK         (0x00000001U)
#define CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_SHIFT        (0U)
#define CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_RESETVAL     (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_MASKED       (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_GENINT       (0x00000001U)

#define CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_MASK               (0x00000002U)
#define CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_SHIFT              (1U)
#define CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_RESETVAL           (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_MASKED             (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_GENINT             (0x00000001U)

#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPESTART_EN_MASK    (0x00000004U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPESTART_EN_SHIFT   (2U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPESTART_EN_RESETVAL  (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPESTART_EN_MASKED  (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPESTART_EN_GENINT  (0x00000001U)

#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPEEND_EN_MASK      (0x00000008U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPEEND_EN_SHIFT     (3U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPEEND_EN_RESETVAL  (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPEEND_EN_MASKED    (0x00000000U)
#define CSL_DSSVID_IRQENABLE_VIDREGIONBASEDPIPEEND_EN_GENINT    (0x00000001U)

#define CSL_DSSVID_IRQENABLE_RESETVAL                           (0x00000000U)

/* IRQSTATUS */

#define CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_MASK        (0x00000001U)
#define CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_SHIFT       (0U)
#define CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_RESETVAL    (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_FALSE       (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_TRUE        (0x00000001U)

#define CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_MASK              (0x00000002U)
#define CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_SHIFT             (1U)
#define CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_RESETVAL          (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_FALSE             (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_TRUE              (0x00000001U)

#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPESTART_IRQ_MASK   (0x00000004U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPESTART_IRQ_SHIFT  (2U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPESTART_IRQ_RESETVAL  (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPESTART_IRQ_FALSE  (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPESTART_IRQ_TRUE   (0x00000001U)

#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPEEND_IRQ_MASK     (0x00000008U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPEEND_IRQ_SHIFT    (3U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPEEND_IRQ_RESETVAL  (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPEEND_IRQ_FALSE    (0x00000000U)
#define CSL_DSSVID_IRQSTATUS_VIDREGIONBASEDPIPEEND_IRQ_TRUE     (0x00000001U)

#define CSL_DSSVID_IRQSTATUS_RESETVAL                           (0x00000000U)

/* MFLAG_THRESHOLD */

#define CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_MASK                (0x0000FFFFU)
#define CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_SHIFT               (0U)
#define CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_RESETVAL            (0x00000000U)
#define CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_MAX                 (0x0000ffffU)

#define CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_MASK                (0xFFFF0000U)
#define CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_SHIFT               (16U)
#define CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_RESETVAL            (0x00000000U)
#define CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_MAX                 (0x0000ffffU)

#define CSL_DSSVID_MFLAG_THRESHOLD_RESETVAL                     (0x00000000U)

/* PICTURE_SIZE */

#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_MASK                   (0x0FFF0000U)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_SHIFT                  (16U)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_RESETVAL               (0x00000000U)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_MAX                    (0x00000fffU)

#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_MASK                   (0x00000FFFU)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_SHIFT                  (0U)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_RESETVAL               (0x00000000U)
#define CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_MAX                    (0x00000fffU)

#define CSL_DSSVID_PICTURE_SIZE_RESETVAL                        (0x00000000U)

/* PIXEL_INC */

#define CSL_DSSVID_PIXEL_INC_PIXELINC_MASK                      (0x000000FFU)
#define CSL_DSSVID_PIXEL_INC_PIXELINC_SHIFT                     (0U)
#define CSL_DSSVID_PIXEL_INC_PIXELINC_RESETVAL                  (0x00000001U)
#define CSL_DSSVID_PIXEL_INC_PIXELINC_MAX                       (0x000000ffU)

#define CSL_DSSVID_PIXEL_INC_RESETVAL                           (0x00000001U)

/* POSITION */

#define CSL_DSSVID_POSITION_POSY_MASK                           (0x0FFF0000U)
#define CSL_DSSVID_POSITION_POSY_SHIFT                          (16U)
#define CSL_DSSVID_POSITION_POSY_RESETVAL                       (0x00000000U)
#define CSL_DSSVID_POSITION_POSY_MAX                            (0x00000fffU)

#define CSL_DSSVID_POSITION_POSX_MASK                           (0x00000FFFU)
#define CSL_DSSVID_POSITION_POSX_SHIFT                          (0U)
#define CSL_DSSVID_POSITION_POSX_RESETVAL                       (0x00000000U)
#define CSL_DSSVID_POSITION_POSX_MAX                            (0x00000fffU)

#define CSL_DSSVID_POSITION_RESETVAL                            (0x00000000U)

/* PRELOAD */

#define CSL_DSSVID_PRELOAD_PRELOAD_MASK                         (0x00000FFFU)
#define CSL_DSSVID_PRELOAD_PRELOAD_SHIFT                        (0U)
#define CSL_DSSVID_PRELOAD_PRELOAD_RESETVAL                     (0x00000100U)
#define CSL_DSSVID_PRELOAD_PRELOAD_MAX                          (0x00000fffU)

#define CSL_DSSVID_PRELOAD_RESETVAL                             (0x00000100U)

/* ROW_INC */

#define CSL_DSSVID_ROW_INC_ROWINC_MASK                          (0xFFFFFFFFU)
#define CSL_DSSVID_ROW_INC_ROWINC_SHIFT                         (0U)
#define CSL_DSSVID_ROW_INC_ROWINC_RESETVAL                      (0x00000001U)
#define CSL_DSSVID_ROW_INC_ROWINC_MAX                           (0xffffffffU)

#define CSL_DSSVID_ROW_INC_RESETVAL                             (0x00000001U)

/* SIZE */

#define CSL_DSSVID_SIZE_SIZEY_MASK                              (0x0FFF0000U)
#define CSL_DSSVID_SIZE_SIZEY_SHIFT                             (16U)
#define CSL_DSSVID_SIZE_SIZEY_RESETVAL                          (0x00000000U)
#define CSL_DSSVID_SIZE_SIZEY_MAX                               (0x00000fffU)

#define CSL_DSSVID_SIZE_SIZEX_MASK                              (0x00000FFFU)
#define CSL_DSSVID_SIZE_SIZEX_SHIFT                             (0U)
#define CSL_DSSVID_SIZE_SIZEX_RESETVAL                          (0x00000000U)
#define CSL_DSSVID_SIZE_SIZEX_MAX                               (0x00000fffU)

#define CSL_DSSVID_SIZE_RESETVAL                                (0x00000000U)

/* CLUT */

#define CSL_DSSVID_CLUT_VALUE_R_MASK                            (0x00FF0000U)
#define CSL_DSSVID_CLUT_VALUE_R_SHIFT                           (16U)
#define CSL_DSSVID_CLUT_VALUE_R_RESETVAL                        (0x00000000U)
#define CSL_DSSVID_CLUT_VALUE_R_MAX                             (0x000000ffU)

#define CSL_DSSVID_CLUT_INDEX_MASK                              (0xFF000000U)
#define CSL_DSSVID_CLUT_INDEX_SHIFT                             (24U)
#define CSL_DSSVID_CLUT_INDEX_RESETVAL                          (0x00000000U)
#define CSL_DSSVID_CLUT_INDEX_MAX                               (0x000000ffU)

#define CSL_DSSVID_CLUT_VALUE_G_MASK                            (0x0000FF00U)
#define CSL_DSSVID_CLUT_VALUE_G_SHIFT                           (8U)
#define CSL_DSSVID_CLUT_VALUE_G_RESETVAL                        (0x00000000U)
#define CSL_DSSVID_CLUT_VALUE_G_MAX                             (0x000000ffU)

#define CSL_DSSVID_CLUT_VALUE_B_MASK                            (0x000000FFU)
#define CSL_DSSVID_CLUT_VALUE_B_SHIFT                           (0U)
#define CSL_DSSVID_CLUT_VALUE_B_RESETVAL                        (0x00000000U)
#define CSL_DSSVID_CLUT_VALUE_B_MAX                             (0x000000ffU)

#define CSL_DSSVID_CLUT_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
