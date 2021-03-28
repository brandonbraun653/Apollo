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
#ifndef CSLR_SATA_H_
#define CSLR_SATA_H_

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
    volatile Uint32 SYSCONFIG;
    volatile Uint32 CDRLOCK;
} CSL_SataRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register is to control the idle and standby modes of Highlander 08
 * modules */
#define CSL_SATA_SYSCONFIG                                      (0x0U)

/* Programmable delay for CDR lock indication */
#define CSL_SATA_CDRLOCK                                        (0x4U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SYSCONFIG */

#define CSL_SATA_SYSCONFIG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_SATA_SYSCONFIG_IDLEMODE_SHIFT                       (2U)
#define CSL_SATA_SYSCONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_SATA_SYSCONFIG_IDLEMODE_FORCE                       (0x00000000U)
#define CSL_SATA_SYSCONFIG_IDLEMODE_NO                          (0x00000001U)
#define CSL_SATA_SYSCONFIG_IDLEMODE_SMART                       (0x00000002U)
#define CSL_SATA_SYSCONFIG_IDLEMODE_SMARTWAKEUP                 (0x00000003U)

#define CSL_SATA_SYSCONFIG_STANDBYMODE_MASK                     (0x00000030U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_SHIFT                    (4U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_RESETVAL                 (0x00000002U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_FORCE                    (0x00000000U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_NO                       (0x00000001U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_SMART                    (0x00000002U)
#define CSL_SATA_SYSCONFIG_STANDBYMODE_SMART_WAKEUP             (0x00000003U)

#define CSL_SATA_SYSCONFIG_OVERRIDE0_MASK                       (0x00010000U)
#define CSL_SATA_SYSCONFIG_OVERRIDE0_SHIFT                      (16U)
#define CSL_SATA_SYSCONFIG_OVERRIDE0_RESETVAL                   (0x00000000U)
#define CSL_SATA_SYSCONFIG_OVERRIDE0_NORMAL                     (0x00000000U)
#define CSL_SATA_SYSCONFIG_OVERRIDE0_OVERRIDE                   (0x00000001U)

#define CSL_SATA_SYSCONFIG_RESETVAL                             (0x00000028U)

/* CDRLOCK */

#define CSL_SATA_CDRLOCK_CDR_LOCK_DELAY_MASK                    (0x00000FFFU)
#define CSL_SATA_CDRLOCK_CDR_LOCK_DELAY_SHIFT                   (0U)
#define CSL_SATA_CDRLOCK_CDR_LOCK_DELAY_RESETVAL                (0x000007d0U)
#define CSL_SATA_CDRLOCK_CDR_LOCK_DELAY_MAX                     (0x00000fffU)

#define CSL_SATA_CDRLOCK_RESETVAL                               (0x000007d0U)

#ifdef __cplusplus
}
#endif
#endif
