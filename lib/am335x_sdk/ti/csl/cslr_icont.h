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
#ifndef CSLR_ICONT_H_
#define CSLR_ICONT_H_

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
    volatile Uint32 ICONT_REVISION;
    volatile Uint32 ICONT_HWINFO;
    volatile Uint8  RSVD0[8];
    volatile Uint32 ICONT_SYSCONFIG;
} CSL_IcontRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* ICONT Revision Identifier (X.Y.R) Used by software to track features, bugs,
 * and compatibility */
#define CSL_ICONT_ICONT_REVISION                                (0x0U)

/* Information about the IP module's hardware configuration. */
#define CSL_ICONT_ICONT_HWINFO                                  (0x4U)

/* Clock management configuration */
#define CSL_ICONT_ICONT_SYSCONFIG                               (0x10U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ICONT_REVISION */

#define CSL_ICONT_ICONT_REVISION_Y_MINOR_MASK                   (0x0000003FU)
#define CSL_ICONT_ICONT_REVISION_Y_MINOR_SHIFT                  (0U)
#define CSL_ICONT_ICONT_REVISION_Y_MINOR_RESETVAL               (0x00000000U)
#define CSL_ICONT_ICONT_REVISION_Y_MINOR_MAX                    (0x0000003fU)

#define CSL_ICONT_ICONT_REVISION_CUSTOM_MASK                    (0x000000C0U)
#define CSL_ICONT_ICONT_REVISION_CUSTOM_SHIFT                   (6U)
#define CSL_ICONT_ICONT_REVISION_CUSTOM_RESETVAL                (0x00000000U)
#define CSL_ICONT_ICONT_REVISION_CUSTOM_STANDARD                (0x00000000U)

#define CSL_ICONT_ICONT_REVISION_X_MAJOR_MASK                   (0x00000700U)
#define CSL_ICONT_ICONT_REVISION_X_MAJOR_SHIFT                  (8U)
#define CSL_ICONT_ICONT_REVISION_X_MAJOR_RESETVAL               (0x00000000U)
#define CSL_ICONT_ICONT_REVISION_X_MAJOR_MAX                    (0x00000007U)

#define CSL_ICONT_ICONT_REVISION_R_RTL_MASK                     (0x0000F800U)
#define CSL_ICONT_ICONT_REVISION_R_RTL_SHIFT                    (11U)
#define CSL_ICONT_ICONT_REVISION_R_RTL_RESETVAL                 (0x00000000U)
#define CSL_ICONT_ICONT_REVISION_R_RTL_MAX                      (0x0000001fU)

#define CSL_ICONT_ICONT_REVISION_FUNC_MASK                      (0x0FFF0000U)
#define CSL_ICONT_ICONT_REVISION_FUNC_SHIFT                     (16U)
#define CSL_ICONT_ICONT_REVISION_FUNC_RESETVAL                  (0x00000000U)
#define CSL_ICONT_ICONT_REVISION_FUNC_MAX                       (0x00000fffU)

#define CSL_ICONT_ICONT_REVISION_SCHEME_MASK                    (0xC0000000U)
#define CSL_ICONT_ICONT_REVISION_SCHEME_SHIFT                   (30U)
#define CSL_ICONT_ICONT_REVISION_SCHEME_RESETVAL                (0x00000001U)
#define CSL_ICONT_ICONT_REVISION_SCHEME_H08                     (0x00000001U)
#define CSL_ICONT_ICONT_REVISION_SCHEME_LEGACY                  (0x00000000U)

#define CSL_ICONT_ICONT_REVISION_RESETVAL                       (0x50000000U)

/* ICONT_HWINFO */

#define CSL_ICONT_ICONT_HWINFO_ICTM_SIZE_MASK                   (0x000000FFU)
#define CSL_ICONT_ICONT_HWINFO_ICTM_SIZE_SHIFT                  (0U)
#define CSL_ICONT_ICONT_HWINFO_ICTM_SIZE_RESETVAL               (0x00000020U)
#define CSL_ICONT_ICONT_HWINFO_ICTM_SIZE_MAX                    (0x000000ffU)

#define CSL_ICONT_ICONT_HWINFO_DTCM_SIZE_MASK                   (0x0000FF00U)
#define CSL_ICONT_ICONT_HWINFO_DTCM_SIZE_SHIFT                  (8U)
#define CSL_ICONT_ICONT_HWINFO_DTCM_SIZE_RESETVAL               (0x00000010U)
#define CSL_ICONT_ICONT_HWINFO_DTCM_SIZE_MAX                    (0x000000ffU)

#define CSL_ICONT_ICONT_HWINFO_NB_TASK_MASK                     (0x000F0000U)
#define CSL_ICONT_ICONT_HWINFO_NB_TASK_SHIFT                    (16U)
#define CSL_ICONT_ICONT_HWINFO_NB_TASK_RESETVAL                 (0x00000006U)
#define CSL_ICONT_ICONT_HWINFO_NB_TASK_MAX                      (0x0000000fU)

#define CSL_ICONT_ICONT_HWINFO_NB_LCH_MASK                      (0x00F00000U)
#define CSL_ICONT_ICONT_HWINFO_NB_LCH_SHIFT                     (20U)
#define CSL_ICONT_ICONT_HWINFO_NB_LCH_RESETVAL                  (0x00000004U)
#define CSL_ICONT_ICONT_HWINFO_NB_LCH_MAX                       (0x0000000fU)

#define CSL_ICONT_ICONT_HWINFO_RESETVAL                         (0x00461020U)

/* ICONT_SYSCONFIG */

#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_MASK                 (0x0000000CU)
#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_SHIFT                (2U)
#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_RESETVAL             (0x00000002U)
#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_FORCE                (0x00000000U)
#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_NO                   (0x00000001U)
#define CSL_ICONT_ICONT_SYSCONFIG_IDLEMODE_SMART                (0x00000002U)

#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_MASK              (0x00000030U)
#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_SHIFT             (4U)
#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_RESETVAL          (0x00000002U)
#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_FORCE             (0x00000000U)
#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_NO                (0x00000001U)
#define CSL_ICONT_ICONT_SYSCONFIG_STANDBYMODE_SMART             (0x00000002U)

#define CSL_ICONT_ICONT_SYSCONFIG_RESETVAL                      (0x00000028U)

#ifdef __cplusplus
}
#endif
#endif
