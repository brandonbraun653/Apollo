/********************************************************************
*
* C66 BASEADDRESS header file
*
* Copyright (C) 2015-2018 Texas Instruments Incorporated.
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
#ifndef CSLR_C66_BASEADDRESS_H_
#define CSLR_C66_BASEADDRESS_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

#define CSL_C66_COREPAC_L2_BASE                                                                (0x800000U)
#define CSL_C66_COREPAC_L2_SIZE                                                                (0x48000U)
#define CSL_C66_COREPAC_L1P_BASE                                                               (0xe00000U)
#define CSL_C66_COREPAC_L1P_SIZE                                                               (0x8000U)
#define CSL_C66_COREPAC_L1D_BASE                                                               (0xf00000U)
#define CSL_C66_COREPAC_L1D_SIZE                                                               (0x8000U)
#define CSL_C66_COREPAC_ICFG_BASE                                                              (0x1000000U)
#define CSL_C66_COREPAC_ICFG_SIZE                                                              (0xc00000U)
#define CSL_C66_COREPAC_EXTERNAL_CFG_BASE                                                      (0x1c00000U)
#define CSL_C66_COREPAC_EXTERNAL_CFG_SIZE                                                      (0xa00000U)
#define CSL_C66_COREPAC_C66_RATCFG_BASE                                                        (0x7ff0000U)
#define CSL_C66_COREPAC_C66_RATCFG_SIZE                                                        (0x10000U)
#define CSL_C66_COREPAC_XMC_MMR_BASE                                                           (0x8000000U)
#define CSL_C66_COREPAC_XMC_MMR_SIZE                                                           (0x10000U)
#define CSL_C66_COREPAC_XMC_EDI_BASE                                                           (0x8010000U)
#define CSL_C66_COREPAC_XMC_EDI_SIZE                                                           (0x10000U)
#define CSL_C66_COREPAC_RAT_REGION_BASE                                                        (0x20000000U)
#define CSL_C66_COREPAC_RAT_REGION_SIZE                                                        (0xe0000000U)
#ifdef __cplusplus
}
#endif
#endif /* CSLR_C66_MEMORYMAP_H_ */
