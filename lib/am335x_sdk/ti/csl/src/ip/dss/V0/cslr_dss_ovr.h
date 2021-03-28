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
#ifndef CSLR_DSSOVR_H_
#define CSLR_DSSOVR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for OVR_ALL
**************************************************************************/
typedef struct {
    volatile Uint32 CONFIG;
    volatile Uint32 CONTROL;
    volatile Uint32 DEFAULT_COLOR;
    volatile Uint32 DEFAULT_COLOR2;
    volatile Uint32 TRANS_COLOR_MAX;
    volatile Uint32 TRANS_COLOR_MAX2;
    volatile Uint32 TRANS_COLOR_MIN;
    volatile Uint32 TRANS_COLOR_MIN2;
} CSL_DssOvrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* The control register configures the Display Controller module for the VP 
 * output. Shadow register. */
#define CSL_DSSOVR_CONFIG                                       (0x0U)

/* The control register configures the Display Controller module for the VP 
 * output. */
#define CSL_DSSOVR_CONTROL                                      (0x4U)

/* The control register configures the default solid background color [31:0] 
 * Shadow register. */
#define CSL_DSSOVR_DEFAULT_COLOR                                (0x8U)

/* The control register configures the default solid background color [47:32] 
 * Shadow register. */
#define CSL_DSSOVR_DEFAULT_COLOR2                               (0xCU)

/* The register sets the max transparency color value for the overlays. Shadow 
 * register. */
#define CSL_DSSOVR_TRANS_COLOR_MAX                              (0x10U)

/* The register sets the max transparency color value for the overlays. Shadow 
 * register. */
#define CSL_DSSOVR_TRANS_COLOR_MAX2                             (0x14U)

/* The register sets the min transparency color value for the overlays. Shadow 
 * register. */
#define CSL_DSSOVR_TRANS_COLOR_MIN                              (0x18U)

/* The register sets the min transparency color value for the overlays. Shadow 
 * register. */
#define CSL_DSSOVR_TRANS_COLOR_MIN2                             (0x1CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CONFIG */

#define CSL_DSSOVR_CONFIG_TCKLCDENABLE_MASK                     (0x00000400U)
#define CSL_DSSOVR_CONFIG_TCKLCDENABLE_SHIFT                    (10U)
#define CSL_DSSOVR_CONFIG_TCKLCDENABLE_RESETVAL                 (0x00000000U)
#define CSL_DSSOVR_CONFIG_TCKLCDENABLE_DISTCK                   (0x00000000U)
#define CSL_DSSOVR_CONFIG_TCKLCDENABLE_ENBTCK                   (0x00000001U)

#define CSL_DSSOVR_CONFIG_TCKLCDSELECTION_MASK                  (0x00000800U)
#define CSL_DSSOVR_CONFIG_TCKLCDSELECTION_SHIFT                 (11U)
#define CSL_DSSOVR_CONFIG_TCKLCDSELECTION_RESETVAL              (0x00000000U)
#define CSL_DSSOVR_CONFIG_TCKLCDSELECTION_GDTK                  (0x00000000U)
#define CSL_DSSOVR_CONFIG_TCKLCDSELECTION_VSTK                  (0x00000001U)

#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_MASK                (0x00000300U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_SHIFT               (8U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_RESETVAL            (0x00000000U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_NOINTERLEAVING      (0x00000000U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_RESERVED            (0x00000001U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_LINEINTERLEAVING    (0x00000002U)
#define CSL_DSSOVR_CONFIG_INTERLEAVED3DMODE_PIXELINTERLEAVING   (0x00000003U)

#define CSL_DSSOVR_CONFIG_GLBCEEN_MASK                          (0x00001000U)
#define CSL_DSSOVR_CONFIG_GLBCEEN_SHIFT                         (12U)
#define CSL_DSSOVR_CONFIG_GLBCEEN_RESETVAL                      (0x00000000U)
#define CSL_DSSOVR_CONFIG_GLBCEEN_GLBCEDIS                      (0x00000000U)
#define CSL_DSSOVR_CONFIG_GLBCEEN_GLBCEEN                       (0x00000001U)

#define CSL_DSSOVR_CONFIG_GLBCESEL_MASK                         (0x00002000U)
#define CSL_DSSOVR_CONFIG_GLBCESEL_SHIFT                        (13U)
#define CSL_DSSOVR_CONFIG_GLBCESEL_RESETVAL                     (0x00000000U)
#define CSL_DSSOVR_CONFIG_GLBCESEL_GLBCE_0                      (0x00000000U)
#define CSL_DSSOVR_CONFIG_GLBCESEL_GLBCE_1                      (0x00000001U)

#define CSL_DSSOVR_CONFIG_RESETVAL                              (0x00000000U)

/* CONTROL */

#define CSL_DSSOVR_CONTROL_OVERLAYOPTIMIZATION_MASK             (0x00001000U)
#define CSL_DSSOVR_CONTROL_OVERLAYOPTIMIZATION_SHIFT            (12U)
#define CSL_DSSOVR_CONTROL_OVERLAYOPTIMIZATION_RESETVAL         (0x00000000U)
#define CSL_DSSOVR_CONTROL_OVERLAYOPTIMIZATION_GDBVWFM          (0x00000000U)
#define CSL_DSSOVR_CONTROL_OVERLAYOPTIMIZATION_GDBVWNFM         (0x00000001U)

#define CSL_DSSOVR_CONTROL_RESETVAL                             (0x00000000U)

/* DEFAULT_COLOR */

#define CSL_DSSOVR_DEFAULT_COLOR_DEFAULTCOLOR_MASK              (0xFFFFFFFFU)
#define CSL_DSSOVR_DEFAULT_COLOR_DEFAULTCOLOR_SHIFT             (0U)
#define CSL_DSSOVR_DEFAULT_COLOR_DEFAULTCOLOR_RESETVAL          (0x00000000U)
#define CSL_DSSOVR_DEFAULT_COLOR_DEFAULTCOLOR_MAX               (0xffffffffU)

#define CSL_DSSOVR_DEFAULT_COLOR_RESETVAL                       (0x00000000U)

/* DEFAULT_COLOR2 */

#define CSL_DSSOVR_DEFAULT_COLOR2_DEFAULTCOLOR_MASK             (0x0000FFFFU)
#define CSL_DSSOVR_DEFAULT_COLOR2_DEFAULTCOLOR_SHIFT            (0U)
#define CSL_DSSOVR_DEFAULT_COLOR2_DEFAULTCOLOR_RESETVAL         (0x00000000U)
#define CSL_DSSOVR_DEFAULT_COLOR2_DEFAULTCOLOR_MAX              (0x0000ffffU)

#define CSL_DSSOVR_DEFAULT_COLOR2_RESETVAL                      (0x00000000U)

/* TRANS_COLOR_MAX */

#define CSL_DSSOVR_TRANS_COLOR_MAX_TRANSCOLORKEY_MASK           (0xFFFFFFFFU)
#define CSL_DSSOVR_TRANS_COLOR_MAX_TRANSCOLORKEY_SHIFT          (0U)
#define CSL_DSSOVR_TRANS_COLOR_MAX_TRANSCOLORKEY_RESETVAL       (0x00000000U)
#define CSL_DSSOVR_TRANS_COLOR_MAX_TRANSCOLORKEY_MAX            (0xffffffffU)

#define CSL_DSSOVR_TRANS_COLOR_MAX_RESETVAL                     (0x00000000U)

/* TRANS_COLOR_MAX2 */

#define CSL_DSSOVR_TRANS_COLOR_MAX2_TRANSCOLORKEY_MASK          (0x0000000FU)
#define CSL_DSSOVR_TRANS_COLOR_MAX2_TRANSCOLORKEY_SHIFT         (0U)
#define CSL_DSSOVR_TRANS_COLOR_MAX2_TRANSCOLORKEY_RESETVAL      (0x00000000U)
#define CSL_DSSOVR_TRANS_COLOR_MAX2_TRANSCOLORKEY_MAX           (0x0000000fU)

#define CSL_DSSOVR_TRANS_COLOR_MAX2_RESETVAL                    (0x00000000U)

/* TRANS_COLOR_MIN */

#define CSL_DSSOVR_TRANS_COLOR_MIN_TRANSCOLORKEY_MASK           (0xFFFFFFFFU)
#define CSL_DSSOVR_TRANS_COLOR_MIN_TRANSCOLORKEY_SHIFT          (0U)
#define CSL_DSSOVR_TRANS_COLOR_MIN_TRANSCOLORKEY_RESETVAL       (0x00000000U)
#define CSL_DSSOVR_TRANS_COLOR_MIN_TRANSCOLORKEY_MAX            (0xffffffffU)

#define CSL_DSSOVR_TRANS_COLOR_MIN_RESETVAL                     (0x00000000U)

/* TRANS_COLOR_MIN2 */

#define CSL_DSSOVR_TRANS_COLOR_MIN2_TRANSCOLORKEY_MASK          (0x0000000FU)
#define CSL_DSSOVR_TRANS_COLOR_MIN2_TRANSCOLORKEY_SHIFT         (0U)
#define CSL_DSSOVR_TRANS_COLOR_MIN2_TRANSCOLORKEY_RESETVAL      (0x00000000U)
#define CSL_DSSOVR_TRANS_COLOR_MIN2_TRANSCOLORKEY_MAX           (0x0000000fU)

#define CSL_DSSOVR_TRANS_COLOR_MIN2_RESETVAL                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
