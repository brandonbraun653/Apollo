/**
 *  \file   emac_cpsw.c
 *
 *  \brief  EMAC Driver APIs implementation specific to K2G.
 *
 *   The file implements the Ethernet Driver API which are local of the EMAC driver and 
 *   setup the CPSW sub-system.
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/
/* C Standard Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Chip Level definitions include */
#include <ti/csl/csl_chip.h>

/* CSL EMAC include */
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpsgmii.h>
#include <ti/csl/csl_cpsgmiiAux.h>
//#include <ti/csl/csl_mdioAux.h>

/* BootCfg module include */
#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>

#include <ti/csl/hw_types.h>


/* CPPI LLD include */
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

/* QMSS LLD include */
#include <ti/drv/qmss/qmss_drv.h>

/* EMAC Driver Local Header */
#include "ti/drv/emac/src/v1/emac_v1.h"







/** ============================================================================
 *   @n@b emac_init_mac
 *
 *   @b Description
 *   @n This API initializes the CPGMAC Sliver (MAC Port) port.
 *
 *   @param[in]
 *   @n macPortNum      MAC port number for which the initialization must be done.
 *
 *   @param[in]
 *   @n macAddress      MAC address to configure on this port.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on this port.
 *
 *   @return
 *   @n None
 * =============================================================================
 */

int emac_init_mac (uint32_t macPortNum, uint8_t macAddress[6], uint32_t mtu, uint32_t loop_back)
{

    CSL_CPSW_TSCONFIG  tsCfg;
    memset(&tsCfg, 0, sizeof(CSL_CPSW_TSCONFIG));

     /* Reset MAC Sliver 0 */
    CSL_CPGMAC_SL_resetMac (macPortNum);
    while (CSL_CPGMAC_SL_isMACResetDone (macPortNum) != TRUE);

    /* Setup the MAC Control Register for this port:
     *      (1) Enable Full duplex
     *      (2) Enable GMII
     *      (3) Enable Gigabit
     *      (4) Enable External Configuration. This enables
     *          the "Full duplex" and "Gigabit" settings to be
     *          controlled externally from SGMII
     *      (5) Don't enable any control/error frames
     *      (6) Enable short frames
     */
    CSL_CPGMAC_SL_enableFullDuplex (macPortNum);
    CSL_CPGMAC_SL_enableGMII (macPortNum);
    CSL_CPGMAC_SL_enableGigabit (macPortNum);

    if (loop_back)
        CSL_CPGMAC_SL_enableLoopback (macPortNum); 

    /* Adding these configurations to allow the switch not to ignore any packets */
    CSL_CPGMAC_SL_enableRxCSF(macPortNum);

    /* Configure the MAC address for this port */
    CSL_CPSW_setPortMACAddress (macPortNum, macAddress);

    /* Configure VLAN ID/CFI/Priority.
     *
     * For now, we are not using VLANs so just configure them
     * to all zeros.
     */
    CSL_CPSW_setPortVlanReg (macPortNum, 0, 0, 0);

    /* Configure the Receive Maximum length on this port,
     * i.e., the maximum size the port can receive without
     * any errors.
     *
     * Set the Rx Max length to the MTU configured for the
     * interface.
     */
     CSL_CPGMAC_SL_setRxMaxLen (macPortNum, mtu);
    
    /*
     * Enable Port Time sync transmit host timestamp
     */
    tsCfg.tsRxAnnexDEnable = 1;
    tsCfg.tsRxAnnexEEnable = 1;
    tsCfg.tsRxAnnexFEnable = 1;
    tsCfg.tsRxVlanLType1Enable = 1;
    tsCfg.tsRxVlanLType2Enable = 1;
    tsCfg.tsTxAnnexDEnable = 1;
    tsCfg.tsTxAnnexEEnable = 1;
    tsCfg.tsTxAnnexFEnable = 1;
    tsCfg.tsTxVlanLType1Enable = 1;
    tsCfg.tsTxVlanLType2Enable = 1;
    tsCfg.tsTxHostEnable = 1;
    tsCfg.tsLType2Enable = 1;
    tsCfg.tsMsgTypeEnable = 0xFFFF;
    tsCfg.tsLType1= 0x88f7;
    tsCfg.tsLType2= 0x88b8;
    tsCfg.tsVlanLType1= 0x88a8;
    tsCfg.tsVlanLType2= 0x8100;
    tsCfg.tsUniEnable = 1; /* All addresses are enabled, including multicast */
    tsCfg.ts319Enable = 1;    
    tsCfg.ts320Enable = 1;  
    tsCfg.tsTTLNonzeroEnable = 1;
    tsCfg.tsSeqIdOffset = 30;
    tsCfg.tsDomainOffset = 4;
    CSL_CPSW_setPortTimeSyncConfig (macPortNum+1, &tsCfg);
    
    /*
     * Map all input packet priority to 0 so that it will be delivered by CPPI flow 0
     */
    { 
        uint32_t rxPriMap[8];
        
        memset (rxPriMap, 0, sizeof(rxPriMap));
        CSL_CPSW_setPortRxPriMapReg(macPortNum+1, rxPriMap); 
    }               
    
    /* Done setting up the MAC port */
    return 0;
}



/** ============================================================================
 *   @n@b emac_init_CPTS
 *
 *   @b Description
 *   @n Init and configure CPTS module
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void emac_init_CPTS (void)
{
    CSL_CPTS_CONTROL    ctrl;
    uint32_t            refClockSelect = 0;
    
    memset(&ctrl, 0, sizeof(CSL_CPTS_CONTROL));
    ctrl.cptsEn = 1;
    ctrl.tstampEn = 1;
    ctrl.seqEn = 0;
    ctrl.ts64bMode = 1;
    
    CSL_CPTS_disableCpts();
    
    CSL_CPTS_setRFTCLKSelectReg (refClockSelect);
    
    CSL_CPTS_setCntlReg(&ctrl);
    
    /* Return success. */
    return;
}



/** ============================================================================
 *   @n@b emac_init_switch
 *
 *   @b Description
 *   @n This API sets up the ethernet switch subsystem and its Address Lookup
 *      Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on the switch.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void emac_init_switch (uint32_t mtu)
{

    CSL_CPSW_PORTSTAT               portStatCfg;

    uint32_t  rx_max_len = mtu + EMAC_ETHHDR_SIZE + 4; /* 4 bytes of FCS */
    CSL_CPSW_ALE_PORTCONTROL    alePortCtrl;

    /* Enable the CPPI port, i.e., port 0 that does all
     * the data streaming in/out of EMAC.
     */
    CSL_CPSW_enablePort0 ();
    CSL_CPSW_disableVlanAware ();
    CSL_CPSW_setPort0VlanReg (0, 0, 0);
    CSL_CPSW_setPort0RxMaxLen (rx_max_len);
    /* Enable statistics on both the port groups:
     *
     * MAC Sliver ports -   Port 1
     * CPPI Port        -   Port 0
     */
    portStatCfg.p0StatEnable    =   1;
    portStatCfg.p1StatEnable    =   1;
    CSL_CPSW_setPortStatsEnableReg (&portStatCfg);

    /* Setup the Address Lookup Engine (ALE) Configuration:
     *      (1) Enable ALE.
     *      (2) Clear stale ALE entries.
     *      (3) Disable VLAN Aware lookups in ALE since
     *          we are not using VLANs by default.
     *      (4) No Flow control
     *      (5) Configure the Unknown VLAN processing
     *          properties for the switch, i.e., which
     *          ports to send the packets to.
     */

    CSL_CPSW_enableAle ();
    CSL_CPSW_clearAleTable ();

    CSL_CPSW_disableAleVlanAware ();
    CSL_CPSW_disableAleTxRateLimit ();
    CSL_CPSW_setAlePrescaleReg (125000000u/1000u);
    CSL_CPSW_setAleUnkownVlanReg (7, 3, 3, 7);

    memset(&alePortCtrl, 0, sizeof(CSL_CPSW_ALE_PORTCONTROL));
    alePortCtrl.portState = ALE_PORTSTATE_DISABLED;
    CSL_CPSW_setAlePortControlReg(1, &alePortCtrl);

    CSL_CPSW_enableAleBypass();
    /* Done with switch configuration */
    return;
}


/** ============================================================================
 *   @n@b emac_cpsw_set_ale_port_cfg
 *
 *   @b Description
 *   @n This API add/delete entries in the Address Lookup Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n portNum         Switch port number.

 *   @param[in]
 *   @n macAddress      MAC address to configure on the switch.
 *
 *   @param[in]
 *   @n add             0:add; 1:delete.
 *
 *   @param[in]
 *   @n loopback             0:disable loopback; 1:enable loopback.
 *   @return
 *   @n None
 *
 *   @Note  It supports "add" operation only now.
 * =============================================================================
 */
int emac_cpsw_set_ale_port_cfg (uint32_t portNum, uint16_t add)
{
    CSL_CPSW_ALE_PORTCONTROL        alePortControlCfg;

    memset(&alePortControlCfg, 0, sizeof(CSL_CPSW_ALE_PORTCONTROL));
    /* Configure the address in "Learning"/"Forward" state */
    alePortControlCfg.portState             =   ALE_PORTSTATE_FORWARD;
    alePortControlCfg.dropUntaggedEnable    =   0;
    alePortControlCfg.vidIngressCheckEnable =   0;
    alePortControlCfg.noLearnModeEnable     =   1;
    alePortControlCfg.mcastLimit            =   0;
    alePortControlCfg.bcastLimit            =   0;


    CSL_CPSW_setAlePortControlReg (portNum, &alePortControlCfg);

    /* Done with upading address */
    return 0;
}



/** ============================================================================
 *   @n@b emac_init_cpsw
 *
 *   @b Description
 *   @n This API sets up the entire ethernet subsystem and all its associated
 *      components.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
int32_t emac_init_cpsw (uint32_t mtu, EMAC_MAC_ADDR_T* pMacAddr, Bool loop_back)
{

    /* Select RGMII as EMAC interface */
    HW_WR_REG32((CSL_BOOT_CFG_REGS + CSL_BOOTCFG_ETHERNET_CFG),CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RGMII);
    emac_init_mac (0, pMacAddr->addr, mtu,loop_back);

    emac_init_CPTS ();

    /* Setup the Ethernet switch finally. */
    emac_init_switch (mtu);

    emac_cpsw_set_ale_port_cfg(0,0);

    emac_cpsw_set_ale_port_cfg(1, 0);

    return 0;
}


