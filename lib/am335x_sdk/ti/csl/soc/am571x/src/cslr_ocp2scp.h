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
#ifndef CSLR_OCP2SCP_H
#define CSLR_OCP2SCP_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint32 SYSSTS;
    volatile Uint32 TIMING;
} CSL_Ocp2scpRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier (X.Y.R) */
#define CSL_OCP2SCP_REVISION                                    (0x0U)

/* SYSTEM CONFIGURATION REGISTER */
#define CSL_OCP2SCP_SYSCONFIG                                   (0x10U)

/* System Status register. */
#define CSL_OCP2SCP_SYSSTS                                      (0x14U)

/* Interrupt Status Register (legacy) for first line of interrupt. */
#define CSL_OCP2SCP_TIMING                                      (0x18U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_OCP2SCP_REVISION_MINOR_MASK                         (0x0000003FU)
#define CSL_OCP2SCP_REVISION_MINOR_SHIFT                        (0U)
#define CSL_OCP2SCP_REVISION_MINOR_RESETVAL                     (0x00000001U)
#define CSL_OCP2SCP_REVISION_MINOR_MAX                          (0x0000003fU)

#define CSL_OCP2SCP_REVISION_CUSTOM_MASK                        (0x000000C0U)
#define CSL_OCP2SCP_REVISION_CUSTOM_SHIFT                       (6U)
#define CSL_OCP2SCP_REVISION_CUSTOM_RESETVAL                    (0x00000000U)
#define CSL_OCP2SCP_REVISION_CUSTOM_MAX                         (0x00000003U)

#define CSL_OCP2SCP_REVISION_MAJOR_MASK                         (0x00000700U)
#define CSL_OCP2SCP_REVISION_MAJOR_SHIFT                        (8U)
#define CSL_OCP2SCP_REVISION_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_OCP2SCP_REVISION_MAJOR_MAX                          (0x00000007U)

#define CSL_OCP2SCP_REVISION_RTL_MASK                           (0x0000F800U)
#define CSL_OCP2SCP_REVISION_RTL_SHIFT                          (11U)
#define CSL_OCP2SCP_REVISION_RTL_RESETVAL                       (0x00000000U)
#define CSL_OCP2SCP_REVISION_RTL_MAX                            (0x0000001fU)

#define CSL_OCP2SCP_REVISION_FUNC_MASK                          (0x0FFF0000U)
#define CSL_OCP2SCP_REVISION_FUNC_SHIFT                         (16U)
#define CSL_OCP2SCP_REVISION_FUNC_RESETVAL                      (0x00000006U)
#define CSL_OCP2SCP_REVISION_FUNC_MAX                           (0x00000fffU)

#define CSL_OCP2SCP_REVISION_SCHEME_MASK                        (0xC0000000U)
#define CSL_OCP2SCP_REVISION_SCHEME_SHIFT                       (30U)
#define CSL_OCP2SCP_REVISION_SCHEME_RESETVAL                    (0x00000001U)
#define CSL_OCP2SCP_REVISION_SCHEME_MAX                         (0x00000003U)

#define CSL_OCP2SCP_REVISION_RESETVAL                           (0x50060001U)

/* SYSCONFIG */

#define CSL_OCP2SCP_SYSCONFIG_AUTOIDLE_MASK                     (0x00000001U)
#define CSL_OCP2SCP_SYSCONFIG_AUTOIDLE_SHIFT                    (0U)
#define CSL_OCP2SCP_SYSCONFIG_AUTOIDLE_RESETVAL                 (0x00000001U)
#define CSL_OCP2SCP_SYSCONFIG_AUTOIDLE_FREERUN                  (0x00000000U)
#define CSL_OCP2SCP_SYSCONFIG_AUTOIDLE_AUTOMATIC                (0x00000001U)

#define CSL_OCP2SCP_SYSCONFIG_SOFTRESET_MASK                    (0x00000002U)
#define CSL_OCP2SCP_SYSCONFIG_SOFTRESET_SHIFT                   (1U)
#define CSL_OCP2SCP_SYSCONFIG_SOFTRESET_RESETVAL                (0x00000000U)
#define CSL_OCP2SCP_SYSCONFIG_SOFTRESET_NORMAL                  (0x00000000U)
#define CSL_OCP2SCP_SYSCONFIG_SOFTRESET_RESET                   (0x00000001U)

#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_MASK                     (0x00000018U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_SHIFT                    (3U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_RESETVAL                 (0x00000002U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_FORCEIDLE                (0x00000000U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_NOIDLE                   (0x00000001U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_SMARTIDLE                (0x00000002U)
#define CSL_OCP2SCP_SYSCONFIG_IDLEMODE_RESERVED                 (0x00000003U)

#define CSL_OCP2SCP_SYSCONFIG_RESETVAL                          (0x00000011U)

/* SYSSTS */

#define CSL_OCP2SCP_SYSSTS_RESETDONE_MASK                       (0x00000001U)
#define CSL_OCP2SCP_SYSSTS_RESETDONE_SHIFT                      (0U)
#define CSL_OCP2SCP_SYSSTS_RESETDONE_RESETVAL                   (0x00000001U)
#define CSL_OCP2SCP_SYSSTS_RESETDONE_INPROGRESS                 (0x00000000U)
#define CSL_OCP2SCP_SYSSTS_RESETDONE_COMPLETE                   (0x00000001U)

#define CSL_OCP2SCP_SYSSTS_RESETVAL                             (0x00000001U)

/* TIMING */

#define CSL_OCP2SCP_TIMING_SYNC2_MASK                           (0x0000000FU)
#define CSL_OCP2SCP_TIMING_SYNC2_SHIFT                          (0U)
#define CSL_OCP2SCP_TIMING_SYNC2_RESETVAL                       (0x00000001U)
#define CSL_OCP2SCP_TIMING_SYNC2_MAX                            (0x0000000fU)

#define CSL_OCP2SCP_TIMING_SYNC1_MASK                           (0x00000070U)
#define CSL_OCP2SCP_TIMING_SYNC1_SHIFT                          (4U)
#define CSL_OCP2SCP_TIMING_SYNC1_RESETVAL                       (0x00000000U)
#define CSL_OCP2SCP_TIMING_SYNC1_MAX                            (0x00000007U)

#define CSL_OCP2SCP_TIMING_DIVISIONRATIO_MASK                   (0x00000380U)
#define CSL_OCP2SCP_TIMING_DIVISIONRATIO_SHIFT                  (7U)
#define CSL_OCP2SCP_TIMING_DIVISIONRATIO_RESETVAL               (0x00000000U)
#define CSL_OCP2SCP_TIMING_DIVISIONRATIO_MAX                    (0x00000007U)

#define CSL_OCP2SCP_TIMING_RESETVAL                             (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
