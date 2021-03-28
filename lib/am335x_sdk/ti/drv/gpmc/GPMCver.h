#ifndef _GPMCVER_H
#define _GPMCVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================= */
/**
 *   @file  GPMCver.h
 *
 *   path  ti/drv/gpmc/GPMCver.h
 *
 *   @brief  gpmc Driver Version Definitions
 *
 *  ============================================================
 *  Copyright (c) Texas Instruments Incorporated 2016 - 2018
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

/**
 * @brief   This is the gpmc Driver Version. Versions numbers are encoded in the following
 * format:
 *  0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD)
 */
#define GPMC_DRV_VERSION_ID                     (0x01000003)

/**
 * @brief   This is the version string which describes the GPMC driver along with the
 * date and build information.
 */
#define GPMC_DRV_VERSION_STR                    "gpmc Driver Revision: 01.00.00.03"


#ifdef __cplusplus
}
#endif


#endif  /* _GPMCVER_H */
