/**
 * @file  csl_cpsw_ale_9g_tblcfg.h
 *
 * @brief
 *  API Auxilary header file for Ethernet switch module CSL for ALE 9G.
 *
 *  Contains the different functions for configuration of ALE 9 port switch
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2014, Texas Instruments, Inc.
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

#ifndef CSL_CPSW_ALE_9G_TBLCFG_H_
#define CSL_CPSW_ALE_9G_TBLCFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief This is to disable HW_SYNC_BARRIER for J7 due to performance
 *        requirement
 */
#if defined (SOC_J721E) || defined (SOC_J7200)
#define MEM_BARRIER_DISABLE
#endif

#include <stdbool.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/csl_cpswitch.h>

/** ============================================================================
 *   @n@b CSL_CPSW_getALEEntryType
 *
 *   @b Description
 *   @n This function returns the ALE entry type for any given ALE table
 *      entry index.
 * =============================================================================
 */
CSL_CPSW_ALE_ENTRYTYPE CSL_CPSW_getALEEntryType_9G(CSL_AleRegs *hCpswAleRegs,
                                                   Uint32      index);

/** ============================================================================
 *   @n@b CSL_CPSW_getALEAddressType
 *
 *   @b Description
 *   @n This function returns the address type of an ALE entry.
 *
 * =============================================================================
 */
CSL_CPSW_ALE_ADDRTYPE CSL_CPSW_getALEAddressType_9G(CSL_AleRegs *hCpswAleRegs,
                                                    Uint32      index);

/** ============================================================================
 *   @n@b CSL_CPSW_getALEPolicerEntryType
 *
 *   @b Description
 *   @n This function returns the entry type of an ALE Policer entry.
 *
 * =============================================================================
 */
CSL_CPSW_ALE_POLICER_ENTRYTYPE CSL_CPSW_getALEPolicerEntryType_9G(CSL_AleRegs *hCpswAleRegs,
                                                                  Uint32      index);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleMcastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Multicast address configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleMcastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                      Uint32      index,
                                      CSL_CPSW_ALE_MCASTADDR_ENTRY* pMcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleMcastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      Multicast address configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleMcastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                      Uint32      index,
                                      CSL_CPSW_ALE_MCASTADDR_ENTRY* pMcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanMcastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN Multicast address configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleVlanMcastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                          Uint32      index,
                                          CSL_CPSW_ALE_VLANMCASTADDR_ENTRY*   pVlanMcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanMcastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      VLAN Multicast address configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleVlanMcastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                         Uint32                              index,
                         CSL_CPSW_ALE_VLANMCASTADDR_ENTRY*   pVlanMcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleUnicastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Unicast address configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleUnicastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                     Uint32                              index,
                                     CSL_CPSW_ALE_UNICASTADDR_ENTRY*     pUcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleUnicastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      unicast address configuration specified here.
 * =============================================================================
 */
void CSL_CPSW_setAleUnicastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                     Uint32      index,
                                     CSL_CPSW_ALE_UNICASTADDR_ENTRY*  pUcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleOUIAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with OUI address configuration
 *      read from the hardware.
 * =============================================================================
 */
void CSL_CPSW_getAleOUIAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                    Uint32      index,
                                    CSL_CPSW_ALE_OUIADDR_ENTRY* pOUIAddrCfg);
/** ============================================================================
 *   @n@b CSL_CPSW_setAleOUIAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      OUI address configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleOUIAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                    Uint32      index,
                                    CSL_CPSW_ALE_OUIADDR_ENTRY*   pOUIAddrCfg);


/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanUnicastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN Unicast address configuration
 *      read from the hardware.
 * =============================================================================
 */
void CSL_CPSW_getAleVlanUnicastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                         Uint32      index,
                         CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY* pVlanUcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanUnicastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      VLAN unicast address configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleVlanUnicastAddrEntry_9G(CSL_AleRegs *hCpswAleRegs,
                         Uint32                         index,
                         CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY* pVlanUcastAddrCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleVlanEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                 Uint32                              index,
                                 CSL_CPSW_ALE_VLAN_ENTRY*            pVlanCfg);

void CSL_CPSW_setAlePolicerType_9G(CSL_AleRegs *hCpswAleRegs,
                                   CSL_CPSW_ALE_POLICER_ENTRYTYPE policerType);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      VLAN configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleVlanEntry_9G(CSL_AleRegs                       *hCpswAleRegs,
                                 Uint32                            index,
                                 CSL_CPSW_ALE_VLAN_ENTRY*          pVlanCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleOutVlanEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Outer VLAN configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleOutVlanEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                    Uint32      index,
                                    CSL_CPSW_ALE_OUTER_VLAN_ENTRY *     pOutVlanCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleOutVlanEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      Outer VLAN configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleOutVlanEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                    Uint32       index,
                                    CSL_CPSW_ALE_OUTER_VLAN_ENTRY*  pOutVlanCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleEthertypeEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Ethertype configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleEthertypeEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                  Uint32      index,
                                  CSL_CPSW_ALE_ETHERTYPE_ENTRY*  pEthertypeCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_setAleEthertypeEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      Ethertype configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleEthertypeEntry_9G(CSL_AleRegs *hCpswAleRegs,
                                  Uint32      index,
                                  CSL_CPSW_ALE_ETHERTYPE_ENTRY*  pEthertypeCfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleIPv4Entry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with IPv4 configuration
 *      read from the hardware.
 *
 * =============================================================================
 */
void CSL_CPSW_getAleIPv4Entry_9G(CSL_AleRegs *hCpswAleRegs,
                                 Uint32                              index,
                                 CSL_CPSW_ALE_IPv4_ENTRY*            pIPv4Cfg);
/** ============================================================================
 *   @n@b CSL_CPSW_setAleIPv4Entry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      IPv4 configuration specified here.
 * =============================================================================
 */
void CSL_CPSW_setAleIPv4Entry_9G(CSL_AleRegs *hCpswAleRegs,
                                 Uint32                              index,
                                 CSL_CPSW_ALE_IPv4_ENTRY*            pIPv4Cfg);

/** ============================================================================
 *   @n@b CSL_CPSW_getAleIPv6Entry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Ipv6 configuration
 *      read from the hardware.
 * =============================================================================
 */
void CSL_CPSW_getAleIPv6Entry_9G(CSL_AleRegs *hCpswAleRegs,
                                 Uint32                              index,
                                 CSL_CPSW_ALE_IPv6_ENTRY*            pIPv6Cfg);
/** ============================================================================
 *   @n@b CSL_CPSW_setAleIPv6Entry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with
 *      IPv6 configuration specified here.
 *
 * =============================================================================
 */
void CSL_CPSW_setAleIPv6Entry_9G(CSL_AleRegs *hCpswAleRegs,
                                 Uint32       index,
                                 CSL_CPSW_ALE_IPv6_ENTRY*   pIPv6Cfg);

/** ============================================================================
 *   @n@b CSL_CPSW_mapTableWord2MacAddr_9G
 *
 *   @b Description
 *   @n This function extracts the mac address from the ALE table word0 and
 *      word 1
 *
 * =============================================================================
 */
void CSL_CPSW_mapTableWord2MacAddr_9G(Uint32 word0,
                                      Uint32 word1,
                                      Uint8 *macAddr);

/** ============================================================================
 *   @n@b CSL_CPSW_mapMacAddr2TableWord_9G
 *
 *   @b Description
 *   @n This function populates the ALE table word 0 and word 1 with the
 *      mac address passed
 * =============================================================================
 */
void CSL_CPSW_mapMacAddr2TableWord_9G(Uint32 *word0,
                                      Uint32 *word1,
                                      Uint8  *macAddr);

/** ============================================================================
 *   @n@b CSL_CPSW_extractVid_9G
 *
 *   @b Description
 *   @n This function extracts the vlan id field from the ALE table word 1
 * =============================================================================
 */
Uint32 CSL_CPSW_extractVid_9G(Uint32             word1);


/** ============================================================================
 *   @n@b CSL_CPSW_getEthertypeMax_9G
 *
 *   @b Description
 *   @n This function returns the max value of EtherType field in ALE table
 * =============================================================================
 */
Uint32 CSL_CPSW_getEthertypeMax_9G(void);


/** ============================================================================
 *   @n@b CSL_CPSW_getIpv4IgnBitsMax_9G
 *
 *   @b Description
 *   @n This function returns the max value of IPv4 ignore bits field in ALE table
 * =============================================================================
 */
Uint32 CSL_CPSW_getIpv4IgnBitsMax_9G(void);


/** ============================================================================
 *   @n@b CSL_CPSW_getIpv6IgnBitsMax_9G
 *
 *   @b Description
 *   @n This function returns the max value of IPv6 ignore bits field in ALE table
 * =============================================================================
 */
Uint32 CSL_CPSW_getIpv6IgnBitsMax_9G(void);

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
