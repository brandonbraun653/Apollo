#ifndef _PMVER_H_
#define _PMVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================= */
/**
 *   @file  pmver.h
 *
 *   path  ti/drv/pm/pmver.h
 *
 *   @brief  PM Driver Version Definitions
 *
 *  ============================================================
 *  Copyright (c) Texas Instruments Incorporated 2016-2017
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
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
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
 *
*/

/**
 * @brief   This is the PM Driver Version. Versions numbers are encoded in the
 * following format:
 *  0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD)
 */
#define PM_DRV_VERSION_ID                     (0x01040005)

/**
 * @brief   This is the version string which describes the PM driver along with
 * the date and build information.
 */
#define PM_DRV_VERSION_STR                    "PM Driver Revision: 01.04.00.05"

#ifdef __cplusplus
}
#endif

#endif  /* _PMVER_H_ */
