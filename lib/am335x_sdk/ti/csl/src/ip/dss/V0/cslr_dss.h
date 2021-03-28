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
#ifndef CSLR_DSS_H_V0
#define CSLR_DSS_H_V0

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for DSSMMR_ALL
**************************************************************************/
typedef struct {
    volatile Uint32 DSS_REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 DSS_SYSCONFIG;
    volatile Uint32 DSS_SYSSTATUS;
    volatile Uint32 DSS_RFBI_CTRL;
    volatile Uint32 DSS_DPI_CTRL;
    volatile Uint8  RSVD1[32];
    volatile Uint32 DSS_DEBUG_CFG;
} CSL_DssRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the Display subsystem revision number */
#define CSL_DSS_DSS_REVISION                                    (0x0U)

/* This register controls the various parameters of the OCP interface */
#define CSL_DSS_DSS_SYSCONFIG                                   (0x10U)

/* This register provides status information about the module */
#define CSL_DSS_DSS_SYSSTATUS                                   (0x14U)

/* This register contains control bits corresponding to the RFBI instance in 
 * DSS */
#define CSL_DSS_DSS_RFBI_CTRL                                   (0x18U)

/* This register contains control bits corresponding to the DPI interface in 
 * DSS */
#define CSL_DSS_DSS_DPI_CTRL                                    (0x1CU)

/* Debug configuration */
#define CSL_DSS_DSS_DEBUG_CFG                                   (0x40U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DSS_REVISION */

#define CSL_DSS_DSS_REVISION_REV_MASK                           (0x000000FFU)
#define CSL_DSS_DSS_REVISION_REV_SHIFT                          (0U)
#define CSL_DSS_DSS_REVISION_REV_RESETVAL                       (0x00000072U)
#define CSL_DSS_DSS_REVISION_REV_MAX                            (0x000000ffU)

#define CSL_DSS_DSS_REVISION_RESETVAL                           (0x00000072U)

/* DSS_SYSCONFIG */

#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_MASK                    (0x00000003U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_SHIFT                   (0U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_RESETVAL                (0x00000002U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_FIDLE                   (0x00000000U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_NIDLE                   (0x00000001U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_SIDLE                   (0x00000002U)
#define CSL_DSS_DSS_SYSCONFIG_SIDLEMODE_RES                     (0x00000003U)

#define CSL_DSS_DSS_SYSCONFIG_SCPMUXING_MASK                    (0x00010000U)
#define CSL_DSS_DSS_SYSCONFIG_SCPMUXING_SHIFT                   (16U)
#define CSL_DSS_DSS_SYSCONFIG_SCPMUXING_RESETVAL                (0x00000000U)
#define CSL_DSS_DSS_SYSCONFIG_SCPMUXING_HDMISCP                 (0x00000000U)
#define CSL_DSS_DSS_SYSCONFIG_SCPMUXING_DPSCP                   (0x00000001U)

#define CSL_DSS_DSS_SYSCONFIG_RESETVAL                          (0x00000002U)

/* DSS_SYSSTATUS */

#define CSL_DSS_DSS_SYSSTATUS_DSS_RESETDONE_MASK                (0x00000001U)
#define CSL_DSS_DSS_SYSSTATUS_DSS_RESETDONE_SHIFT               (0U)
#define CSL_DSS_DSS_SYSSTATUS_DSS_RESETDONE_RESETVAL            (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_DSS_RESETDONE_RSTCOMP             (0x00000001U)
#define CSL_DSS_DSS_SYSSTATUS_DSS_RESETDONE_RSTACT              (0x00000000U)

#define CSL_DSS_DSS_SYSSTATUS_DSI_A_RESETDONE_MASK              (0x00000002U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_A_RESETDONE_SHIFT             (1U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_A_RESETDONE_RESETVAL          (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_A_RESETDONE_MAX               (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_DSI_B_RESETDONE_MASK              (0x00000004U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_B_RESETDONE_SHIFT             (2U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_B_RESETDONE_RESETVAL          (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_DSI_B_RESETDONE_MAX               (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_HDMI_RESETDONE_MASK               (0x00000008U)
#define CSL_DSS_DSS_SYSSTATUS_HDMI_RESETDONE_SHIFT              (3U)
#define CSL_DSS_DSS_SYSSTATUS_HDMI_RESETDONE_RESETVAL           (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_HDMI_RESETDONE_MAX                (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_DP_A_RESETDONE_MASK               (0x00000010U)
#define CSL_DSS_DSS_SYSSTATUS_DP_A_RESETDONE_SHIFT              (4U)
#define CSL_DSS_DSS_SYSSTATUS_DP_A_RESETDONE_RESETVAL           (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_DP_A_RESETDONE_MAX                (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_DP_B_RESETDONE_MASK               (0x00000020U)
#define CSL_DSS_DSS_SYSSTATUS_DP_B_RESETDONE_SHIFT              (5U)
#define CSL_DSS_DSS_SYSSTATUS_DP_B_RESETDONE_RESETVAL           (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_DP_B_RESETDONE_MAX                (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_VENC_RESETDONE_MASK               (0x00000040U)
#define CSL_DSS_DSS_SYSSTATUS_VENC_RESETDONE_SHIFT              (6U)
#define CSL_DSS_DSS_SYSSTATUS_VENC_RESETDONE_RESETVAL           (0x00000000U)
#define CSL_DSS_DSS_SYSSTATUS_VENC_RESETDONE_MAX                (0x00000001U)

#define CSL_DSS_DSS_SYSSTATUS_RESETVAL                          (0x00000000U)

/* DSS_RFBI_CTRL */

#define CSL_DSS_DSS_RFBI_CTRL_RFBI_ENABLE_MASK                  (0x00000001U)
#define CSL_DSS_DSS_RFBI_CTRL_RFBI_ENABLE_SHIFT                 (0U)
#define CSL_DSS_DSS_RFBI_CTRL_RFBI_ENABLE_RESETVAL              (0x00000000U)
#define CSL_DSS_DSS_RFBI_CTRL_RFBI_ENABLE_DISABLE               (0x00000000U)
#define CSL_DSS_DSS_RFBI_CTRL_RFBI_ENABLE_ENABLE                (0x00000001U)

#define CSL_DSS_DSS_RFBI_CTRL_RESETVAL                          (0x00000000U)

/* DSS_DPI_CTRL */

#define CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_MASK                    (0x00000001U)
#define CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_SHIFT                   (0U)
#define CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_RESETVAL                (0x00000001U)
#define CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_DISABLE                 (0x00000000U)
#define CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_ENABLE                  (0x00000001U)

#define CSL_DSS_DSS_DPI_CTRL_RESETVAL                           (0x00000001U)

/* DSS_DEBUG_CFG */

#define CSL_DSS_DSS_DEBUG_CFG_CFG_MASK                          (0x00000007U)
#define CSL_DSS_DSS_DEBUG_CFG_CFG_SHIFT                         (0U)
#define CSL_DSS_DSS_DEBUG_CFG_CFG_RESETVAL                      (0x00000000U)
#define CSL_DSS_DSS_DEBUG_CFG_CFG_DISPC                         (0x00000000U)

#define CSL_DSS_DSS_DEBUG_CFG_RESETVAL                          (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
