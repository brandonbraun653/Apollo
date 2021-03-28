#ifndef PDK_BUILD_VER_H
#define PDK_BUILD_VER_H

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================= */
/**
 *   @file  pdk_build_ver.h
 *
 *   path  ti/build/pdk_build_ver.h
 *
 *   @brief  PDK_BUILD infrastructure Version Definitions
 *
 *  ============================================================
 *  Copyright (c) Texas Instruments Incorporated 2016
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
 * @brief   This is the PDK_BUILD Version. Versions numbers are encoded in the following 
 * format:
 *  0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD)
 */
#define pdk_build_VERSION_ID                   (0x0100000DU)

/**
 * @brief   This is the version string which describes the PDK_BUILD along with the
 * date and build information.
 */
#define pdk_build_VERSION_STR                  "PDK_BUILD Revision: 01.00.00.13"


#ifdef __cplusplus
}
#endif
  

#endif  /* PDK_BUILD_VER_H */
