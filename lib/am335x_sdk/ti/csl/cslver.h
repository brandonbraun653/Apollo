#ifndef CSLVER_H
#define CSLVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================= */
/**
 *   @file  cslver.h
 *
 *   path  ti/csl/cslver.h
 *
 *   @brief  Chip Support Library (CSL) Version Definitions
 *
 *  ============================================================
 *  Copyright (c) Texas Instruments Incorporated 2009-2020
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
 * @brief   This is the CSL Version. Versions numbers are encoded in the following 
 * format:
 *  0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD)
 */
#define CSL_VERSION_ID                   (0x03030011U)

/**
 * @brief   This is the version string which describes the CSL along with the
 * date and build information.
 */
#define CSL_VERSION_STR                  "CSL Revision: 03.03.00.17"


#ifdef __cplusplus
}
#endif
  

#endif  /* CSLVER_H */
