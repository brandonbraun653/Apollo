/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_navss_mcu.h
*/
#ifndef CSLR_NAVSS_MCU_H_
#define CSLR_NAVSS_MCU_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_NAVSS_MCU_CBASS_FW_REGS_BASE                                           (0x00000000U)
#define CSL_NAVSS_MCU_CBASS_GLB_REGS_BASE                                          (0x00000000U)
#define CSL_NAVSS_MCU_CBASS_ISC_REGS_BASE                                          (0x00000000U)
#define CSL_NAVSS_MCU_CBASS_QOS_REGS_BASE                                          (0x00000000U)
#define CSL_NAVSS_MCU_ECCAGGR0_REGS_BASE                                           (0x28380000U)
#define CSL_NAVSS_MCU_ECC_AGGR_REGS_BASE                                           (0x28381000U)
#define CSL_NAVSS_MCU_INTAGGR_CFG_REGS_BASE                                        (0x283C0000U)
#define CSL_NAVSS_MCU_INTAGGR_GCNTCFG_REGS_BASE                                    (0x28480000U)
#define CSL_NAVSS_MCU_INTAGGR_GCNTRTI_REGS_BASE                                    (0x2A600000U)
#define CSL_NAVSS_MCU_INTAGGR_IMAP_REGS_BASE                                       (0x28560000U)
#define CSL_NAVSS_MCU_INTAGGR_INTR_REGS_BASE                                       (0x2A700000U)
#define CSL_NAVSS_MCU_INTAGGR_L2G_REGS_BASE                                        (0x28570000U)
#define CSL_NAVSS_MCU_INTAGGR_MCAST_REGS_BASE                                      (0x28580000U)
#define CSL_NAVSS_MCU_INTR_ROUTER_CFG_REGS_BASE                                    (0x28540000U)
#define CSL_NAVSS_MCU_MCRC64_REGS_BASE                                             (0x2A264000U)
#define CSL_NAVSS_MCU_MODSS_REGS_REGS_BASE                                         (0x28520000U)
#define CSL_NAVSS_MCU_PROXY_BUFFER_REGS_BASE                                       (0x285A0000U)
#define CSL_NAVSS_MCU_PROXY_CFG_REGS_BASE                                          (0x2A580000U)
#define CSL_NAVSS_MCU_PROXY_REGS_BASE                                              (0x28590000U)
#define CSL_NAVSS_MCU_PROXY_TARGET0_REGS_BASE                                      (0x2A500000U)
#define CSL_NAVSS_MCU_PROXY_TARGET_REGS_BASE                                       (0x2A480000U)
#define CSL_NAVSS_MCU_PSILCFG_REGS_BASE                                            (0x2A268000U)
#define CSL_NAVSS_MCU_PSILSS_REGS_BASE                                             (0x285E0000U)
#define CSL_NAVSS_MCU_REGION_NAV_MCU_SRC0_REGS_BASE                                (0x00000000U)
#define CSL_NAVSS_MCU_RINGACC_CFG_REGS_BASE                                        (0x28440000U)
#define CSL_NAVSS_MCU_RINGACC_FIFOS_REGS_BASE                                      (0x2B000000U)
#define CSL_NAVSS_MCU_RINGACC_GCFG_REGS_BASE                                       (0x285D0000U)
#define CSL_NAVSS_MCU_RINGACC_ISC_REGS_BASE                                        (0x00000000U)
#define CSL_NAVSS_MCU_RINGACC_MONITOR_REGS_BASE                                    (0x2A280000U)
#define CSL_NAVSS_MCU_RINGACC_RT_REGS_BASE                                         (0x2B800000U)
#define CSL_NAVSS_MCU_SEC_PROXY_REGS_BASE                                          (0x285B0000U)
#define CSL_NAVSS_MCU_SEC_PROXY_RT_REGS_BASE                                       (0x2A380000U)
#define CSL_NAVSS_MCU_SEC_PROXY_SCFG_REGS_BASE                                     (0x2A400000U)
#define CSL_NAVSS_MCU_UDMAP_GCFG_REGS_BASE                                         (0x285C0000U)
#define CSL_NAVSS_MCU_UDMAP_RXCCFG_REGS_BASE                                       (0x284C0000U)
#define CSL_NAVSS_MCU_UDMAP_RXCRT_REGS_BASE                                        (0x2A800000U)
#define CSL_NAVSS_MCU_UDMAP_RXFCFG_REGS_BASE                                       (0x28400000U)
#define CSL_NAVSS_MCU_UDMAP_TXCCFG_REGS_BASE                                       (0x284A0000U)
#define CSL_NAVSS_MCU_UDMAP_TXCRT_REGS_BASE                                        (0x2AA00000U)


#ifdef __cplusplus
}
#endif
#endif
