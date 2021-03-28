/**  
 * @file  csl_cpswAux.h
 *
 * @brief  
 *  API Auxilary header file for Ethernet switch module CSL. 
 *
 *  Contains the different control command and status query functions definations
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

#ifndef CSL_CPSW_AUX_V2_H_
#define CSL_CPSW_AUX_V2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_ale.h>
#include <ti/csl/cslr_cpsw.h>

#include <ti/csl/csl_cpgmac_sl.h>

/** ============================================================================ 
 *
 * @defgroup CSL_CPSW_API_V2 Ethernet switch submodule (CPSW - V2)
 * @ingroup CSL_CPSW_API
 *
 * ============================================================================
 */

/**
@defgroup CSL_CPSW_SYMBOL  CPSW Symbols Defined
@ingroup CSL_CPSW_API_V2
*/
/**
@defgroup CSL_CPSW_DATASTRUCT  CPSW Data Structures
@ingroup CSL_CPSW_API_V2
*/
/**
@defgroup CSL_CPSW_FUNCTION  CPSW Functions
@ingroup CSL_CPSW_API_V2
*/
/**
@defgroup CSL_CPSW_ENUM CPSW Enumerated Data Types
@ingroup CSL_CPSW_API_V2
*/
/** @addtogroup CSL_CPSW_DATASTRUCT
 @{ */

/** Constants for passing parameters to the functions.
 */
/** @brief Pointer to the Ethernet Switch overlay registers */
#ifdef CSL_NSS_0_CFG_REGS
#define     hCpswAleRegs                            ((CSL_AleRegs *) (CSL_NSS_0_CFG_REGS  + 0x0023e000))
#endif

#ifdef CSL_MCU_CPSW0_NUSS_BASE
#define     hCpswAleRegs                            ((CSL_AleRegs *) (CSL_MCU_CPSW0_NUSS_BASE  + 0x0003e000))
#endif

/** @brief Number of statistic blocks. 
 *
 *  EMAC has multiple statistics blocks.
 *
 *  STATS0 holds statistics for Host/CPU port (Switch port 0).
 *  STATSn holds statistics for MAC ports (Switch ports n).
 */
 
#if defined(SOC_K2G) 
#define     CSL_CPSW_NUMSTATBLOCKS              2  
#define     CSL_CPSW_NUM_PORTS                  2  
#else
#define     CSL_CPSW_NUMSTATBLOCKS              9  
#define     CSL_CPSW_NUM_PORTS                  9  
#endif

/** @brief Number of hardware statistics registers */
#define     CSL_CPSW_NUMSTATS                   42        

/** @brief Maximum number of ALE entries that can be programmed */
#define     CSL_CPSW_NUMALE_ENTRIES             1024   


/** @brief      
 *
 *  Defines ALE Aging Timer Prescale
 */        
typedef enum {
    ALE_AGT_PRESACLE_1M = 0,  /** 1000,000 (default value) */
    ALE_AGT_PRESACLE_1000,    /** 1000 (test value) */
    ALE_AGT_PRESACLE_1        /** 1 (test value) */
} CSL_CPSW_ALE_AGT_PRESCALE_E;

/** @brief      
 *
 *  Holds Port Statistics Enable register contents. 
 */        
typedef struct {
	/**  Port 0 Statistics Enable bit */	
	Uint32      p0StatEnable;

	/**  Port 1 Statistics Enable bit */	
	Uint32      p1StatEnable;

	/**  Port 2 Statistics Enable bit */	
	Uint32      p2StatEnable;
    
	/**  Port 3 Statistics Enable bit */	
	Uint32      p3StatEnable;
    
	/**  Port 4 Statistics Enable bit */	
	Uint32      p4StatEnable;
    
	/**  Port 5 Statistics Enable bit */	
	Uint32      p5StatEnable;
    
	/**  Port 6 Statistics Enable bit */	
	Uint32      p6StatEnable;
    
	/**  Port 7 Statistics Enable bit */	
	Uint32      p7StatEnable;
    
	/**  Port 8 Statistics Enable bit */	
	Uint32      p8StatEnable;
    
} CSL_CPSW_PORTSTAT;

/** @brief      
 *
 *  Holds Port Time Sync Control register contents. 
 */        
typedef struct {
	/**  Port Time sync receive Annex D enable bit */	
	Uint32      tsRxAnnexDEnable;

	/**  Port Time sync receive Annex E enable bit */	
	Uint32      tsRxAnnexEEnable;

	/**  Port Time sync receive Annex F enable bit */	
	Uint32      tsRxAnnexFEnable;

	/**  Port Time sync receive VLAN LTYPE 1 enable bit */	
	Uint32      tsRxVlanLType1Enable;

	/**  Port Time sync receive VLAN LTYPE 2 enable bit */	
	Uint32      tsRxVlanLType2Enable;

	/**  Port Time sync transmit Annex D enable bit */	
	Uint32      tsTxAnnexDEnable;

	/**  Port Time sync transmit Annex E enable bit */	
	Uint32      tsTxAnnexEEnable;

	/**  Port Time sync transmit Annex F enable bit */	
	Uint32      tsTxAnnexFEnable;

	/**  Port Time sync transmit VLAN LTYPE 1 enable bit */	
	Uint32      tsTxVlanLType1Enable;

	/**  Port Time sync transmit VLAN LTYPE 2 enable bit */	
	Uint32      tsTxVlanLType2Enable;

	/**  Port Time sync transmit host timestamp enable bit */	
	Uint32      tsTxHostEnable;
    
	/**  Port Time sync transmit and receive LType2 enable bit */	
	Uint32      tsLType2Enable;
    
	/**  Port Time sync message type enable bits */	
	Uint32      tsMsgTypeEnable;
    
} CSL_CPSW_TSCNTL;


/** @brief      
 *
 *  Holds Port Time Sync Configuration contents. 
 */        
typedef struct {
	/**  Port Time sync receive Annex D enable */	
	Uint32      tsRxAnnexDEnable;

	/**  Port Time sync receive Annex E enable */	
	Uint32      tsRxAnnexEEnable;

	/**  Port Time sync receive Annex F enable */	
	Uint32      tsRxAnnexFEnable;

	/**  Port Time sync receive VLAN LTYPE 1 enable */	
	Uint32      tsRxVlanLType1Enable;

	/**  Port Time sync receive VLAN LTYPE 2 enable */	
	Uint32      tsRxVlanLType2Enable;

	/**  Port Time sync transmit Annex D enable */	
	Uint32      tsTxAnnexDEnable;

	/**  Port Time sync transmit Annex E enable */	
	Uint32      tsTxAnnexEEnable;

	/**  Port Time sync transmit Annex F enable */	
	Uint32      tsTxAnnexFEnable;

	/**  Port Time sync transmit VLAN LTYPE 1 enable */	
	Uint32      tsTxVlanLType1Enable;

	/**  Port Time sync transmit VLAN LTYPE 2 enable */	
	Uint32      tsTxVlanLType2Enable;

	/**  Port Time sync transmit host timestamp enable */	
	Uint32      tsTxHostEnable;
    
	/**  Port Time sync transmit and receive LType2 enable */	
	Uint32      tsLType2Enable;
    
	/**  Port Time sync message type enable bitmap */	
	Uint32      tsMsgTypeEnable;
    
    /**  Port Time Sync Unicast IP message enable  
         1: all IP address valid
         0: perform multicast address check, only multicast addresses which are enabled are valid 
      */
    Uint32      tsUniEnable;
    
    /**  Port Time Sync Destination IP Address 107 enable 
         IPv4: 224.0.0.107 
         IPv6: FF0M:0:0:0:0:0:0:006B
     */
    Uint32      ts107Enable;
    
    /**  Port Time Sync Destination IP Address 129 enable 
         IPv4: 224.0.0.129 
         IPv6: FF0M:0:0:0:0:0:0:0181
     */
    Uint32      ts129Enable;
    
    /**  Port Time Sync Destination IP Address 130 enable 
         IPv4: 224.0.0.130 
         IPv6: FF0M:0:0:0:0:0:0:0182
     */
    Uint32      ts130Enable;
    
    /**  Port Time Sync Destination IP Address 131 enable 
         IPv4: 224.0.0.130 
         IPv6: FF0M:0:0:0:0:0:0:0183
     */
    Uint32      ts131Enable;
    
    /**  Port Time Sync Destination IP Address 132 enable 
         IPv4: 224.0.0.131 
         IPv6: FF0M:0:0:0:0:0:0:0184
     */
    Uint32      ts132Enable;
    
    /**  Port Time Sync UDP Destination Port Number 319 enable */
    Uint32      ts319Enable;
    
    /**  Port Time Sync UDP Destination Port Number 320 enable */
    Uint32      ts320Enable;
    
	/**  Port Time sync message IPv6 Multicast Address FF0M enable */	
	Uint32      tsMcastTypeEnable;
    
	/**  Port Time Sync Time to Live Non-zero enable */	
    Uint32      tsTTLNonzeroEnable;
    
    /**  Port Time Sync LTYPE1 value for Annex F packets */
    Uint32      tsLType1;
    
    /**  Port Time Sync LTYPE2 value for Annex F packets */
    Uint32      tsLType2;
    
    /**  Port Time Sync VLAN LTYPE1 value for both Tx and Rx packets */
    Uint32      tsVlanLType1;
    
    /**  Port Time Sync VLAN LTYPE2 value for both Tx and Rx packets */
    Uint32      tsVlanLType2;
    
    /**  Port Time Sync Sequence ID field byte Offset in PTP message */
    Uint32      tsSeqIdOffset;
    
    /**  Port Time Sync Domain field byte Offset in PTP message */
    Uint32      tsDomainOffset;
    
} CSL_CPSW_TSCONFIG;


/** @brief      
 *
 *  Holds CPSW Port Control contents. 
 */        
typedef struct {
	/**  Eneregy Efficient Etherent (EEE) Transmit LPI clockstop enable
         for EMAC port only  
         1: The GMII or RGMII transmit clock is stopped in the EEE 
            LPI state.
         0: The GMII or RGMII transmit clock is not stopped in the 
            EEE LPI state.
      */
	Uint32      txLpiClkstopEnable;

	/**  IPv6 DSCP to priority mapping enable */	
	Uint32      dscpIpv6Enable;

	/**  IPv4 DSCP to priority mapping enable */	
	Uint32      dscpIpv4Enable;

} CSL_CPSW_PORT_CONTROL;


/** @brief      
 *
 *  Holds CPSW Port Rx Rate Limit Configuration for CPPI Port Ingress Rate Limitaion Operation. 
 */        
typedef struct {
	/**  Number of Rate Limitaion Channels. Rate limited channels must be the highest priority channels. 
         For example, if two rate limited channels are required then they must be channel with priority
         7 and 6 respectively. The BW of rate limitation channel is calcualted as 
         idleStep/(idleStep + sendStep)*Frequemcy*256 where frequency = the VBUSP_GCLK frequency (350 for 350Mhz)  
      */
	Uint32      numRLimChans;

	/**  Rate Limitaion Idle Step Array */	
	Uint32      idleStep[8];

	/**  Rate Limitaion Send Step Array  */	
	Uint32      sendStep[8];

} CSL_CPSW_RX_RATE_LIMIT_CONFIG;

/** @brief      
 *
 *  Holds CPSW EEE (Energy Efficient Ethernet)  Global Configuration. 
 */        
typedef struct {
    /**  Energy Efficient Ethernet enable */
    Uint32      enable;

	/**  Energy Efficient Ethernet Pre-scale count load value */	
	Uint32      prescale;

} CSL_CPSW_EEE_GLOB_CONFIG;

/** @brief      
 *
 *  Holds CPSW EEE (Energy Efficient Ethernet)  Per-Port Configuration. 
 */        
typedef struct {
	/**  EEE Transmit LPI clockstop enable
         for EMAC port only  
         1: The GMII or RGMII transmit clock is stopped in the EEE 
            LPI state.
         0: The GMII or RGMII transmit clock is not stopped in the 
            EEE LPI state.
      */
	Uint32      txLpiClkstopEnable;

	/**  EEE Idle to LPI counter load value - After EEE_CLKSTOP_REQ is asserted, 
         this value is loaded into the port idle to LPI counter on each clock 
         that the port transmit or receive is not idle.  Port enters the LPI 
         state when this count decrements to zero.  
         This count value should be large relative to switch operations */	
	Uint32      idle2lpi;

	/**  EEE LPI to wake counter load value - When the port is in the transmit 
         LPI state and the EEE_CLKSTOP_REQ signal is deasserted, this value is 
         loaded into the port 0 LPI to wake counter.  
         Transmit and receive packet operations may begin (resume) when 
         the LPI to wake count decrements to zero.  This is the time waited 
         before CPPI packet operations begin (resume after wakeup).  
         This count value should be large relative to switch operations. */	
	Uint32      lpi2wake;

} CSL_CPSW_EEE_PORT_CONFIG;


/** @brief      
 *
 *  Holds CPSW EEE (Energy Efficient Ethernet)  Per-Port STATUS. 
 */        
typedef struct {
	/**  CPSW port wait idle to LPI - asserted when port is counting the IDLE2LPI time */
	Uint32      wait_idle2lpi;

	/**  CPSW port receive LPI state - asserted when the port receive is in the LPI state */
	Uint32      rxLpi;

	/**  CPSW port transmit LPI state - asserted when the port transmit is in the LPI state */
	Uint32      txLpi;
    
    /**  CPSW port transmit wakeup - asserted when the port transmit is in the transmit 
         LPI2WAKE count time. */
    Uint32      txWake;    
    
    /**  CPSW port transmit FIFO hold - asserted in the LPI state and 
         during the LPI2WAKE count time. */
    Uint32      txFifoHold;
    
    /** CPSW port receive FIFO (switch ingress) is empty - contains no packets */
    Uint32      rxFifoEmpty;    

    /** CPSW port transmit FIFO (switch egress) is empty - contains no packets */
    Uint32      txFifoEmpty;    

} CSL_CPSW_EEE_PORT_STATUS;

/** @brief      
 *
 *  Defines ALE Update Bandwidth Control Value:
 *  The upd_bw_ctrl field within ALE control register specifies the rate in which adds, 
 *  updates, touches, writes, and aging updates can occur. At frequencies of 350Mhz, 
 *  the table update rate should be at its lowest or 5 Million updates per second. 
 *  When operating the switch core at frequencies or above, the upd_bw_ctrl can be 
 *  programmed more aggressive. 
 *  If the upd_bw_ctrl is set but the frequency of the switch subsystem is below the 
 *  associated value, ALE will drop packets due to insufficient time to complete 
 *  lookup under high traffic loads.
 */        
typedef enum {
    ALE_UPD_BW_350MHZ_5M = 0,           /** 0 - 350Mhz, 5M */
    ALE_UPD_BW_359MHZ_11M,              /** 1 - 359Mhz, 11M */
    ALE_UPD_BW_367MHZ_16M,              /** 2 - 367Mhz, 16M */
    ALE_UPD_BW_375MHZ_22M,              /** 3 - 375Mhz, 22M */
    ALE_UPD_BW_384MHZ_28M,              /** 4 - 384Mhz, 28M */
    ALE_UPD_BW_392MHZ_34M,              /** 5 - 392Mhz, 34M */
    ALE_UPD_BW_400MHZ_39M,              /** 6 - 400Mhz, 39M */
    ALE_UPD_BW_409MHZ_45M               /** 7 - 409Mhz, 45M */
} CSL_CPSW_ALE_UPD_BW;

/** @brief      
 *
 *  Holds CPSW Policer  Global Configuration. 
 */        
typedef struct {
    /**  Classification/Policing enable (not used) */
    Uint32      enable;
    
    /** ALE Policer Default Thread Enable: 
        Set: the aleDeafultThread is used for the CPPI transmit thread 
             if there are no matching classifiers.  
        Clear, the switch default thread is used for the CPPI transmit thread i
        f there are no matching classifiers.
     */
    
    Uint32      defThreadEnable; 

	/**  ALE Default Thread */	
	Uint32      defThread;

} CSL_CPSW_ALE_POLICER_GLOB_CONFIG;


/** @brief ALE Policer Entry configuration definitions */
/**  Input EMAC port is used for classification */	
#define    CSL_CPSW_ALE_POLICER_PORT_VALID       (1 << 0u) 

/**  VLAN Priority is used for classification */	
#define    CSL_CPSW_ALE_POLICER_PRI_VALID        (1 << 1u) 

/**  OUI is used for classification */	
#define    CSL_CPSW_ALE_POLICER_OUI_VALID        (1 << 2u) 

/**  Destination MAC is used for classification */	
#define    CSL_CPSW_ALE_POLICER_DST_MAC_VALID    (1 << 3u) 

/**  Source MAC is used for classification */	
#define    CSL_CPSW_ALE_POLICER_SRC_MAC_VALID    (1 << 4u) 

/**  Outer VLAN ID is used for classification */	
#define    CSL_CPSW_ALE_POLICER_OVLAN_VALID      (1 << 5u) 

/**  (Inner) VLAN ID is used for classification */	
#define    CSL_CPSW_ALE_POLICER_VLAN_VALID       (1 << 6u) 

/**  Ethertype is used for classification */	
#define    CSL_CPSW_ALE_POLICER_ETHERTYPE_VALID  (1 << 7u) 

/**  Source IP address is used for classification */	
#define    CSL_CPSW_ALE_POLICER_SRC_IP_VALID    ( 1 << 8u) 

/**  Destination IP address is used for classification */	
#define    CSL_CPSW_ALE_POLICER_DST_IP_VALID     (1 << 9u) 

/**  The specified thread value is used as the CPPI egress thread 
     for any packet that matches the classifier  */	
#define    CSL_CPSW_ALE_POLICER_THREAD_VALID    ( 1 << 10u) 


/** @brief      
 *
 *  Holds the ALE Policer Table entry configuration.
 */        
typedef struct {
    /**  Configuration control bitmap as defined above */
    Uint32                      validBitmap;
    
	/**  Ingress EMAC port */	
	Uint32                      port;

	/**  VLAN priority */	
	Uint32                      pri;

	/**  OUI entry index  */	
	Uint32                      ouiIdx;

	/**  Destination MAC address entry index  */	
	Uint32                      dstMacIdx;

	/**  Source MAC address entry index  */	
	Uint32                      srcMacIdx;

	/**  Outer VLAN entry index  */	
	Uint32                      ovlanIdx;

	/**  (Inner) VLAN entry index  */	
	Uint32                      vlanIdx;

	/**  Ethertype entry index  */	
	Uint32                      ethertypeIdx;

	/**  Source IP address entry index  */	
	Uint32                      srcIpIdx;

	/**  Destination IP address entry index  */	
	Uint32                      dstIpIdx;

	/**  CPPI Egress thread upon match  */	
	Uint32                      thread;

} CSL_CPSW_ALE_POLICER_ENTRY;

/** @brief      
 *  
 *  Holds the EMAC statistics.
 *
 *  The statistics structure is the used to retrieve the current count
 *  of various packet events in the system. These values represent the
 *  delta values from the last time the statistics were read.
 */
typedef struct {
    /** Good Frames Received                      */        
    Uint32      RxGoodFrames;     

    /** Good Broadcast Frames Received            */
    Uint32      RxBCastFrames;    

    /** Good Multicast Frames Received            */
    Uint32      RxMCastFrames;    

    /** PauseRx Frames Received                   */
    Uint32      RxPauseFrames;    

    /** Frames Received with CRC Errors           */
    Uint32      RxCRCErrors;      

    /** Frames Received with Alignment/Code Errors*/
    Uint32      RxAlignCodeErrors;

    /** Oversized Frames Received                 */
    Uint32      RxOversized;      

    /** Jabber Frames Received                    */
    Uint32      RxJabber;         

    /** Undersized Frames Received                */
    Uint32      RxUndersized;     

    /** Rx Frame Fragments Received               */
    Uint32      RxFragments;      

    /** Rx frames dropped by the ALE              */
    Uint32      RxAleDrop;         

    /** Rx overrun frames dropped by the ALE      */
    Uint32      RxAleOverrunDrop;      

    /** Total Received Bytes in Good Frames       */
    Uint32      RxOctets;         

    /** Good Frames Sent                          */
    Uint32      TxGoodFrames;     
    
    /** Good Broadcast Frames Sent                */
    Uint32      TxBCastFrames;    

    /** Good Multicast Frames Sent                */
    Uint32      TxMCastFrames;    

    /** PauseTx Frames Sent                       */
    Uint32      TxPauseFrames;    

    /** Frames Where Transmission was Deferred    */
    Uint32      TxDeferred;       

    /** Total Frames Sent With Collision          */
    Uint32      TxCollision;      

    /** Frames Sent with Exactly One Collision    */
    Uint32      TxSingleColl;     

    /** Frames Sent with Multiple Colisions       */
    Uint32      TxMultiColl;      

    /** Tx Frames Lost Due to Excessive Collisions*/
    Uint32      TxExcessiveColl;  

    /** Tx Frames Lost Due to a Late Collision    */
    Uint32      TxLateColl;       

    /** Rx inter-packet gap errors (10G only)     */
    Uint32      RxIpgError;       

    /** Tx Frames Lost Due to Carrier Sense Loss  */
    Uint32      TxCarrierSLoss;   

    /** Total Transmitted Bytes in Good Frames    */
    Uint32      TxOctets;         

    /** Total Tx&Rx with Octet Size of 64         */
    Uint32      Frame64;          

    /** Total Tx&Rx with Octet Size of 65 to 127  */
    Uint32      Frame65t127;      

    /** Total Tx&Rx with Octet Size of 128 to 255 */
    Uint32      Frame128t255;     

    /** Total Tx&Rx with Octet Size of 256 to 511 */
    Uint32      Frame256t511;     

    /** Total Tx&Rx with Octet Size of 512 to 1023*/
    Uint32      Frame512t1023;    

    /** Total Tx&Rx with Octet Size of >=1024     */
    Uint32      Frame1024tUp;     

    /** Sum of all Octets Tx or Rx on the Network */
    Uint32      NetOctets;        

    /** Total Rx bottom of FIFO dropped frames    */
    Uint32      RxDropBottom;    

    /** Total dropped frames due to portmask      */
    Uint32      PortmaskFrop;    

    /** Total Rx top of FIFO dropped frames       */
    Uint32      RxDropTop;    
    
    /** Total dropped frames due to ALE Rate Limiting */
    Uint32      AleRateLimitDrop;    

    /** Total dropped frames due to ALE VID Ingress   */
    Uint32      AleVidDrop;    

    /** Total dropped frames due to DA=SA             */
    Uint32      AleAddrEqDrop;    
      
    /** Unused Statistics registers                   */
    Uint32      Resv1[3];    

    /** Total ALE Unknown Unicast frames              */
    Uint32      AleUnKnUni;    
    
    /** Total ALE Unknown Unicast byte count          */
    Uint32      AleUnKnUniBytes;    

    /** Total ALE Unknown Multicast frames            */
    Uint32      AleUnKnMulti;    
    
    /** Total ALE Unknown Multicast byte count        */
    Uint32      AleUnKnMultiBytes;    

    /** Total ALE Unknown Broadcast frames            */
    Uint32      AleUnKnBCast;    
    
    /** Total ALE Unknown Broadcast byte count        */
    Uint32      AleUnKnBCastBytes;    

    /** Total ALE Policer Match frames                */
    Uint32      AlePolMatch;    
    
    /** Unused Statistics registers                   */
    Uint32      Resv2[46];    

    /** Total Tx Memory Protect CRC Error */
    Uint32      TxMemProtectErr;    
    
} CSL_CPSW_STATS;

/**
@}
*/


/** @addtogroup CSL_CPSW_FUNCTION
@{ */

/********************************************************************************
************************* Ethernet Switch (CPSW) Submodule **********************
********************************************************************************/


/** ============================================================================
 *   @n@b CSL_CPSW_nGF_getCpswVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the CPSW identification and version information.
 *
 *   @b Arguments
     @verbatim
        pVersionInfo        CSL_CPSW_VERSION structure that needs to be populated
                            with the version info read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_ID_VER_REG_CPSW_5GF_MINOR_VER,
 *      XGE_CPSW_ID_VER_REG_CPSW_5GF_MAJ_VER,
 *      XGE_CPSW_ID_VER_REG_CPSW_5GF_RTL_VER,
 *      XGE_CPSW_ID_VER_REG_CPSW_5GF_IDENT
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_VERSION    versionInfo;

        CSL_CPSW_getCpswVersionInfo (&versionInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getCpswVersionInfo (
	CSL_CPSW_VERSION*       pVersionInfo     
)
{

    pVersionInfo->minorVer  =   CSL_FEXT (hCpswRegs->ID_VER_REG, XGE_CPSW_ID_VER_REG_MINOR_VER);
    pVersionInfo->majorVer  =   CSL_FEXT (hCpswRegs->ID_VER_REG, XGE_CPSW_ID_VER_REG_MAJOR_VER);
    pVersionInfo->rtlVer    =   CSL_FEXT (hCpswRegs->ID_VER_REG, XGE_CPSW_ID_VER_REG_RTL_VER);
    pVersionInfo->id        =   CSL_FEXT (hCpswRegs->ID_VER_REG, XGE_CPSW_ID_VER_REG_IDENT);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_isVlanAwareEnabled
 *
 *   @b Description
 *   @n This function indicates if VLAN aware mode is enabled in the CPSW
 *      control register.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   VLAN aware mode enabled. 
 *	 @n  FALSE                  VLAN aware mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_CONTROL_REG_VLAN_AWARE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isVlanAwareEnabled (portNum) == TRUE)
        {
            // VLAN aware mode enabled
        }
        else
        {
            // VLAN aware mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isVlanAwareEnabled (void)
{
    return CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_VLAN_AWARE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableVlanAware
 *
 *   @b Description
 *   @n This function configures the CPSW control register to enable VLAN aware
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_VLAN_AWARE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableVlanAware ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableVlanAware (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_VLAN_AWARE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableVlanAware
 *
 *   @b Description
 *   @n This function configures the CPSW control register to disable VLAN aware
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_VLAN_AWARE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableVlanAware ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableVlanAware (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_VLAN_AWARE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isPort0Enabled
 *
 *   @b Description
 *   @n This function indicates if CPPI Port (Port 0) is enabled in the CPSW
 *      control register.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Port 0 enabled. 
 *	 @n  FALSE                  Port 0 disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_CONTROL_REG_P0_ENABLE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isPort0Enabled (portNum) == TRUE)
        {
            // Port 0 enabled
        }
        else
        {
            // Port 0 disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isPort0Enabled (void)
{
    return CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_ENABLE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enablePort0
 *
 *   @b Description
 *   @n This function configures the CPSW control register to enable the Port 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P0_ENABLE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enablePort0 ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enablePort0 (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_ENABLE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disablePort0
 *
 *   @b Description
 *   @n This function configures the CPSW control register to disable the Port 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P0_ENABLE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disablePort0 ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disablePort0 (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_ENABLE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isPort0PassPriTagEnabled
 *
 *   @b Description
 *   @n This function indicates if priority tagging is enabled for Port 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Port 0 ingress priority tagging enabled. 
 *	 @n  FALSE                  Port 0 ingress priority tagging disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isPort0PassPriTagEnabled () == TRUE)
        {
            // Port 0 pass priority tagging enabled
        }
        else
        {
            // Port 0 pass priority tagging disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isPort0PassPriTagEnabled (void)
{
    return CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enablePort0PassPriTag
 *
 *   @b Description
 *   @n This function configures the CPSW control register to enable the Ingress
 *      priority tagging on Port 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enablePort0PassPriTag ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enablePort0PassPriTag (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disablePort0PassPriTag
 *
 *   @b Description
 *   @n This function configures the CPSW control register to disable the Ingress
 *      priority tagging on Port 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disablePort0PassPriTag ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disablePort0PassPriTag (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isPort1PassPriTagEnabled
 *
 *   @b Description
 *   @n This function indicates if priority tagging is enabled for Port 1.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Port 1 ingress priority tagging enabled. 
 *	 @n  FALSE                  Port 1 ingress priority tagging disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isPort1PassPriTagEnabled () == TRUE)
        {
            // Port 1 pass priority tagging enabled
        }
        else
        {
            // Port 1 pass priority tagging disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isPort1PassPriTagEnabled (void)
{
    return CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enablePort1PassPriTag
 *
 *   @b Description
 *   @n This function configures the CPSW control register to enable the Ingress
 *      priority tagging on Port 1.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enablePort1PassPriTag ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enablePort1PassPriTag (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disablePort1PassPriTag
 *
 *   @b Description
 *   @n This function configures the CPSW control register to disable the Ingress
 *      priority tagging on Port 1.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disablePort1PassPriTag ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disablePort1PassPriTag (void)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getCpswControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW Control register.
 *
 *   @b Arguments
     @verbatim
        pControlRegInfo     CSL_CPSW_CONTROL structure that needs to be populated
                            with the control register contents.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_CONTROL_REG_VLAN_AWARE,
 *      XGE_CPSW_CONTROL_REG_P0_ENABLE,
 *      XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED,
 *      XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED,
 *      XGE_CPSW_CONTROL_REG_P0_RX_PAD,
 *      XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR,
 *      XGE_CPSW_CONTROL_REG_EEE_ENABLE
 *      
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_CONTROL    controlRegInfo;

        CSL_CPSW_getCpswControlReg (&controlRegInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getCpswControlReg (
	CSL_CPSW_CONTROL*   pControlRegInfo     
)
{
    pControlRegInfo->fifoLb         =   0;
    pControlRegInfo->vlanAware      =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_VLAN_AWARE);
    pControlRegInfo->p0Enable       =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_ENABLE);
    pControlRegInfo->p0PassPriTag   =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED);
    pControlRegInfo->p1PassPriTag   =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED);
    pControlRegInfo->p0TxCrcRemove  =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE);
    pControlRegInfo->p0RxPad        =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_RX_PAD);
    pControlRegInfo->p0RxPassCrcErr =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR);
    pControlRegInfo->eeeEnable      =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_EEE_ENABLE);
    

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_setCpswControlReg
 *
 *   @b Description
 *   @n This function populates the contents of the CPSW Control register.
 *
 *   @b Arguments
     @verbatim
        pControlRegInfo     CSL_CPSW_CONTROL structure that holds the values 
                            that need to be configured to the CPSW control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  CPSW control register modified with values provided.
 *
 *   @b Writes
 *   @n XGE_CPSW_CONTROL_REG_VLAN_AWARE,
 *      XGE_CPSW_CONTROL_REG_P0_ENABLE,
 *      XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED,
 *      XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED,
 *      XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED,
 *      XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE,
 *      XGE_CPSW_CONTROL_REG_P0_RX_PAD,
 *      XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR,
 *      XGE_CPSW_CONTROL_REG_EEE_ENABLE
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_CONTROL    controlRegInfo;

        controlRegInfo.vlanAware    =   0;
        ...

        CSL_CPSW_setCpswControlReg (&controlRegInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setCpswControlReg (
	CSL_CPSW_CONTROL*   pControlRegInfo     
)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_VLAN_AWARE, pControlRegInfo->vlanAware);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_ENABLE, pControlRegInfo->p0Enable);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_PASS_PRI_TAGGED, pControlRegInfo->p0PassPriTag);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P1_PASS_PRI_TAGGED, pControlRegInfo->p1PassPriTag);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_TX_CRC_REMOVE, pControlRegInfo->p0TxCrcRemove);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_RX_PAD, pControlRegInfo->p0RxPad);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_P0_RX_PASS_CRC_ERR, pControlRegInfo->p0RxPassCrcErr);
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_EEE_ENABLE, pControlRegInfo->eeeEnable);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_getEmulationControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW Emulation Control register.
 *
 *   @b Arguments
     @verbatim
        pFree                   Emulation free bit read from the hardware.
        pSoft                   Emulation soft bit read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_EM_CONTROL_REG_FREE,
 *      XGE_CPSW_EM_CONTROL_REG_SOFT
 *
 *   @b Example
 *   @verbatim
        Uint32  free, soft;

        CSL_CPSW_getEmulationControlReg (&free, &soft);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getEmulationControlReg (
    Uint32*                     pFree,
    Uint32*                     pSoft
)
{

    *pFree      =   CSL_FEXT (hCpswRegs->EM_CONTROL_REG, XGE_CPSW_EM_CONTROL_REG_FREE);
    *pSoft      =   CSL_FEXT (hCpswRegs->EM_CONTROL_REG, XGE_CPSW_EM_CONTROL_REG_SOFT);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_setEmulationControlReg
 *
 *   @b Description
 *   @n This function sets up the contents of the CPSW Emulation Control register.
 *
 *   @b Arguments
     @verbatim
        free                   Emulation free bit configuration
        soft                   Emulation soft bit configuration
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_EM_CONTROL_REG_FREE,
 *      XGE_CPSW_EM_CONTROL_REG_SOFT
 *
 *   @b Example
 *   @verbatim
        Uint32 free, soft;

        free   =   0;
        soft   =   1;

        CSL_CPSW_setEmulationControlReg (free, soft);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setEmulationControlReg (
    Uint32                      free,
    Uint32                      soft
)
{

    CSL_FINS (hCpswRegs->EM_CONTROL_REG, XGE_CPSW_EM_CONTROL_REG_FREE, free);
    CSL_FINS (hCpswRegs->EM_CONTROL_REG, XGE_CPSW_EM_CONTROL_REG_SOFT, soft);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortStatsEnableReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW Port Statistics
 *      Enable register.
 *
 *   @b Arguments
     @verbatim
        pPortStatsCfg       CSL_XGE_CPSW_PORTSTAT structure that needs to be populated
                            with the port statistics enable register contents.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN,
 *      XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN,
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_PORTSTAT       portStatsCfg;

        CSL_CPSW_getPortStatsEnableReg (&portStatsCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortStatsEnableReg (
	CSL_CPSW_PORTSTAT*  pPortStatsCfg     
)
{
    pPortStatsCfg->p0StatEnable    =   CSL_FEXT (hCpswRegs->STAT_PORT_EN_REG, XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN);
    pPortStatsCfg->p1StatEnable    =   CSL_FEXT (hCpswRegs->STAT_PORT_EN_REG, XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortStatsEnableReg
 *
 *   @b Description
 *   @n This function sets up the contents of the CPSW Port Statistics
 *      Enable register.
 *
 *   @b Arguments
     @verbatim
        pPortStatsCfg       CSL_CPSW_PORTSTAT structure that contains the values
                            to be used to setup port statistics enable register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN,
 *      XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN,
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_PORTSTAT       portStatsCfg;

        portStatsCfg.p0StatEnable  =   1;
        portStatsCfg.p1StatEnable  =   1;
        ...

        CSL_CPSW_setPortStatsEnableReg (&portStatsCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortStatsEnableReg (
	CSL_CPSW_PORTSTAT*  pPortStatsCfg     
)
{
    CSL_FINS (hCpswRegs->STAT_PORT_EN_REG, XGE_CPSW_STAT_PORT_EN_REG_P0_STAT_EN, pPortStatsCfg->p0StatEnable);
    CSL_FINS (hCpswRegs->STAT_PORT_EN_REG, XGE_CPSW_STAT_PORT_EN_REG_P1_STAT_EN, pPortStatsCfg->p1StatEnable);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_isSoftIdle
 *
 *   @b Description
 *   @n This function indicates if the CPSW is at Software Idle mode where 
 *      no packets will be started to be unloaded from ports. 
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Software Idle mode enabled. 
 *	 @n  FALSE                  Software Idle mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isSoftIdle () == TRUE)
        {
            // Software Idle mode enabled
        }
        else
        {
            // Software Idle mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isSoftIdle (void)
{
    return CSL_FEXT (hCpswRegs->SOFT_IDLE_REG, XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableSoftIdle
 *
 *   @b Description
 *   @n This function configures the CPSW Soft Idle register to enable Software 
 *      Idle mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableSoftIdle ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableSoftIdle (void)
{
    CSL_FINS (hCpswRegs->SOFT_IDLE_REG, XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableSoftIdle
 *
 *   @b Description
 *   @n This function configures the CPSW Soft Idle register to disable Software 
 *      Idle mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableSoftIdle ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableSoftIdle (void)
{
    CSL_FINS (hCpswRegs->SOFT_IDLE_REG, XGE_CPSW_SOFT_IDLE_REG_SOFT_IDLE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port Control Register
 *      corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register contents
                                must be read and returned.
        pControlInfo            CSL_CPSW_PORT_CONTROL structure that needs to be populated
                                with the control register contents.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  none
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN,
 *      XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN,
 *
 *      XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN,
 *      XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN,
 *      XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN,
 *
 *
 *   @b Example
 *   @verbatim
 *      Uint32                      portNum;
        CSL_CPSW_PORT_CONTROL       controlInfo;
 
        portNum =   1;
 
        CSL_CPSW_getPortControlReg (portNum, &controlInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortControlReg (
    Uint32                      portNum,                
    CSL_CPSW_PORT_CONTROL*      pControlInfo                
)
{
    if (portNum == 0)
    {
        pControlInfo->dscpIpv4Enable     =   CSL_FEXT (hCpswRegs->P0_CONTROL_REG, XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN);
        pControlInfo->dscpIpv6Enable     =   CSL_FEXT (hCpswRegs->P0_CONTROL_REG, XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN);
        
    } else
    {
    
        pControlInfo->dscpIpv4Enable     =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN);
        pControlInfo->dscpIpv6Enable     =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN);
        pControlInfo->txLpiClkstopEnable =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortControlReg
 *
 *   @b Description
 *   @n This function sets up the contents of the Port Control Register
 *      corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register contents
                                must be read and returned.
        pControlInfo            CSL_CPSW_PORT_CONTROL structure that holds the values 
                                that need to be configured to the CPSW Port 
                                control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  none
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN,
 *      XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN,
 *
 *      XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN,
 *      XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN,
 *      XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN,
 *
 *
 *   @b Example
 *   @verbatim
 *      Uint32                      portNum;
        CSL_CPSW_PORT_CONTROL       controlInfo;
 
        portNum =   1;
        
        controlInfo.dscpIpv4Enable = 1;
        controlInfo.dscpIpv6Enable = 1;
        controlInfo.txLpiClkstopEnable = 0;
        
 
        CSL_CPSW_setPortControlReg (portNum, &controlInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortControlReg (
    Uint32                      portNum,                
    CSL_CPSW_PORT_CONTROL*      pControlInfo                
)
{
    if (portNum == 0)
    {
        CSL_FINS (hCpswRegs->P0_CONTROL_REG, XGE_CPSW_P0_CONTROL_REG_DSCP_IPV4_EN, pControlInfo->dscpIpv4Enable);
        CSL_FINS (hCpswRegs->P0_CONTROL_REG, XGE_CPSW_P0_CONTROL_REG_DSCP_IPV6_EN, pControlInfo->dscpIpv6Enable);
        
    } else
    {
    
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_DSCP_IPV4_EN, pControlInfo->dscpIpv4Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_DSCP_IPV6_EN, pControlInfo->dscpIpv6Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN, pControlInfo->txLpiClkstopEnable);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getCppiSourceIdReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPPI Source Identification
 *      register.
 *
 *   @b Arguments
     @verbatim
        pTxSrcId[8]         CPPI Info Word0 Source Id Value on Tx Ports respectively.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_SRC_ID_A_REG_PORT1
 *
 *   @b Example
 *   @verbatim
 *      Uint32      txSrcId[8];

        CSL_CPSW_getCppiSourceIdReg (txSrcId);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getCppiSourceIdReg (
    Uint32*                 pTxSrcId
)
{
    pTxSrcId[0]    =   CSL_FEXT (hCpswRegs->P0_SRC_ID_A_REG, XGE_CPSW_P0_SRC_ID_A_REG_PORT1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setCppiSourceIdReg
 *
 *   @b Description
 *   @n This function sets up the contents of the CPPI Source Identification
 *      register.
 *
 *   @b Arguments
     @verbatim
        pTxSrcId[8]         CPPI Info Word0 Source Id Value on Tx Ports respectively.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_SRC_ID_A_REG_PORT1
 *
 *   @b Example
 *   @verbatim
 *      Uint32      txSrcId[8];
 
        txSrcId[0]    =   1;
        ...

        CSL_CPSW_setCppiSourceIdReg (txSrcId);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setCppiSourceIdReg (
    Uint32*                 pTxSrcId
)
{
    CSL_FINS (hCpswRegs->P0_SRC_ID_A_REG, XGE_CPSW_P0_SRC_ID_A_REG_PORT1, pTxSrcId[0]);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPort0VlanReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port 0 VLAN Register.
 *
 *   @b Arguments
     @verbatim
        pPortVID                Port VLAN Id
        pPortCFI                Port CFI bit
        pPortPRI                Port VLAN priority (0-7, 7 is highest priority)
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portVID, portCFI, portPRI;
 
        CSL_CPSW_getPort0VlanReg (&portVID, &portCFI, &portPRI);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPort0VlanReg (
    Uint32*                     pPortVID,
    Uint32*                     pPortCFI,
    Uint32*                     pPortPRI
)
{
    *pPortVID   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID);
    *pPortCFI   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI);
    *pPortPRI   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPort0VlanReg
 *
 *   @b Description
 *   @n This function sets up the contents of the Port 0 VLAN Register.
 *
 *   @b Arguments
     @verbatim
        portVID                 Port VLAN Id to be configured
        portCFI                 Port CFI bit to be configured
        portPRI                 Port VLAN priority to be configured
                                (0-7, 7 is highest priority)
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portVID, portCFI, portPRI;
 
        portVID     =   1;
        portCFI     =   0;
        portPRI     =   7;

        CSL_CPSW_setPort0VlanReg (portVID, portCFI, portPRI);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPort0VlanReg (
    Uint32                      portVID,
    Uint32                      portCFI,
    Uint32                      portPRI
)
{
    CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID, portVID);
    CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI, portCFI);
    CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI, portPRI);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPort0RxPriMapReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port 0 Receive Packet
 *      Priority to Header Priority Mapping Register.
 *
 *   @b Arguments
     @verbatim
        pPortRxPriMap           Array of Port 0 Rx priority map priority values 
                                read from the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pPortRxPriMap' must be large enough to hold all
 *       the 8 priority values read from the register.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      port0RxPriMap [8];
 
        CSL_CPSW_getPort0RxPriMapReg (port0RxPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPort0RxPriMapReg (
    Uint32*                     pPortRxPriMap                
)
{
    pPortRxPriMap [0]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0);
    pPortRxPriMap [1]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1);
    pPortRxPriMap [2]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2);
    pPortRxPriMap [3]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3);
    pPortRxPriMap [4]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4);
    pPortRxPriMap [5]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5);
    pPortRxPriMap [6]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6);
    pPortRxPriMap [7]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPort0RxPriMapReg
 *
 *   @b Description
 *   @n This function sets up the contents of the Port 0 Receive Packet
 *      Priority to Header Priority Mapping Register.
 *
 *   @b Arguments
     @verbatim
        pPortRxPriMap           Array of Port 0 Rx priority map priority values 
                                that must be configured to the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      i, port0RxPriMap [8];

        for (i = 0; i < 8; i ++)
            port0RxPriMap [i] = i;

        CSL_CPSW_setPort0RxPriMapReg (port0RxPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPort0RxPriMapReg (
    Uint32*                     pPortRxPriMap                
)
{
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0, pPortRxPriMap [0]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1, pPortRxPriMap [1]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2, pPortRxPriMap [2]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3, pPortRxPriMap [3]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4, pPortRxPriMap [4]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5, pPortRxPriMap [5]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6, pPortRxPriMap [6]);
    CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7, pPortRxPriMap [7]);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPort0FlowIdOffset
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port 0 Flow ID Offset
 *      Register, which is added to the thread/Flow_ID in CPPI transmit PSI 
 *      Info Word 0.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE
 *
 *   @b Example
 *   @verbatim
 *      Uint32      flowIdOffset;
 
        flowIdOffset    =   CSL_CPSW_getPort0FlowIdOffset ();

	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getPort0FlowIdOffset (void)
{
    return CSL_FEXT (hCpswRegs->P0_FLOW_ID_OFFSET_REG, XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPort0FlowIdOffset
 *
 *   @b Description
 *   @n This function sets up the Port0 Flow ID Offset register.
 *      which is added to the thread/Flow_ID in CPPI transmit PSI 
 *      Info Word 0. 
 *
 *   @b Arguments
     @verbatim
        flowIdOffset            CPPI Flow ID offset to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE
 *
 *   @b Example
 *   @verbatim
 *      Uint32      flowIdOffset;
 
        flowIdOffset    =   0;            
 
        CSL_CPSW_setPort0FlowIdOffset (flowIdOffset);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPort0FlowIdOffset (
    Uint32                  flowIdOffset
)
{
    CSL_FINS (hCpswRegs->P0_FLOW_ID_OFFSET_REG, XGE_CPSW_P0_FLOW_ID_OFFSET_REG_VALUE, flowIdOffset);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPort0RxMaxLen
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port 0 Receive Maximum Length
 *      Register.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxMaxLen;
 
        rxMaxLen    =   CSL_CPSW_getPort0RxMaxLen ();

	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getPort0RxMaxLen (void)
{
    return CSL_FEXT (hCpswRegs->P0_RX_MAXLEN_REG, XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPort0RxMaxLen
 *
 *   @b Description
 *   @n This function sets up the Port0 Receive Maximum length register.
 *
 *   @b Arguments
     @verbatim
        rxMaxLen            Maximum receive frame length to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxMaxLen;
 
        rxMaxLen    =   1518;            
 
        CSL_CPSW_setPort0RxMaxLen (rxMaxLen);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPort0RxMaxLen (
    Uint32                  rxMaxLen
)
{
    CSL_FINS (hCpswRegs->P0_RX_MAXLEN_REG, XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN, rxMaxLen);

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_getPortBlockCountReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port Block Count register 
 *      corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the block count
                                must be retrieved.
        pRxBlkCnt               Receive block count usage read for this port.                                
        pTxBlkCnt               Transmit block count usage read for this port.                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT,
 *      XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT,
 *      XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT,
 *      XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT,
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxBlkCnt, txBlkCnt, portNum;

        portNum =   1;            
 
        CSL_CPSW_getPortBlockCountReg (portNum, &rxBlkCnt, &txBlkCnt);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortBlockCountReg (
    Uint32                      portNum,
    Uint32*                     pRxBlkCnt,
    Uint32*                     pTxBlkCnt
)
{
    if (portNum == 0)
    {
        *pRxBlkCnt  =   CSL_FEXT (hCpswRegs->P0_BLK_CNT_REG, XGE_CPSW_P0_BLK_CNT_REG_RX_BLK_CNT);
        *pTxBlkCnt  =   CSL_FEXT (hCpswRegs->P0_BLK_CNT_REG, XGE_CPSW_P0_BLK_CNT_REG_TX_BLK_CNT);
    } else
    {
        *pRxBlkCnt  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_BLK_CNT_REG, XGE_CPSW_PN_BLK_CNT_REG_RX_BLK_CNT);
        *pTxBlkCnt  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_BLK_CNT_REG, XGE_CPSW_PN_BLK_CNT_REG_TX_BLK_CNT);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortRxMaxLen
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW Port Receive Maximum Length
 *      Register.
 *
 *   @b Arguments
        portNum             CPSW port number for which the Receive Maximum Length
                            must be retrieved.
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN
 *      XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portNum, rxMaxLen;

        portNum = 1;
        rxMaxLen    =   CSL_CPSW_getPortRxMaxLen (portNum);

	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getPortRxMaxLen (
    Uint32                  portNum
)
{
    if(portNum == 0)
        return CSL_FEXT (hCpswRegs->P0_RX_MAXLEN_REG, XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN);
    else
        return CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_MAXLEN_REG, XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortRxMaxLen
 *
 *   @b Description
 *   @n This function sets up the Port Receive Maximum length register.
 *
 *   @b Arguments
     @verbatim
        portNum             CPSW port number for which the Receive Maximum Length
                            must be retrieved.
        rxMaxLen            Maximum receive frame length to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN
 *      XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portNum, rxMaxLen;

        portNum     =   1;
        rxMaxLen    =   1518;

        CSL_CPSW_setPortRxMaxLen (portNum, rxMaxLen);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortRxMaxLen (
    Uint32                  portNum,
    Uint32                  rxMaxLen
)
{
    if(portNum == 0)
    {
        CSL_FINS (hCpswRegs->P0_RX_MAXLEN_REG, XGE_CPSW_P0_RX_MAXLEN_REG_RX_MAXLEN, rxMaxLen);
    }
    else if (portNum <= 8)
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_MAXLEN_REG, XGE_CPSW_PN_RX_MAXLEN_REG_RX_MAXLEN, rxMaxLen);
    }

    return;
}



/** ============================================================================
 *   @n@b CSL_CPSW_getPortRxPriMapReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port Receive Packet
 *      Priority to Header Priority Mapping Register.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the block count
                                must be retrieved.
        pPortRxPriMap           Array of Port Rx priority map priority values
                                read from the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pPortRxPriMap' must be large enough to hold all
 *       the 8 priority values read from the register.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7,
 *
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portNum = 1;
 *      Uint32      portRxPriMap [8];

        CSL_CPSW_getPortRxPriMapReg (portNum, portRxPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortRxPriMapReg (
    Uint32                      portNum,
    Uint32*                     pPortRxPriMap
)
{
    if (portNum == 0)
    {
        pPortRxPriMap [0]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0);
        pPortRxPriMap [1]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1);
        pPortRxPriMap [2]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2);
        pPortRxPriMap [3]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3);
        pPortRxPriMap [4]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4);
        pPortRxPriMap [5]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5);
        pPortRxPriMap [6]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6);
        pPortRxPriMap [7]   =   CSL_FEXT (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7);
    }
    else if (portNum <= 8)
    {
        pPortRxPriMap [0]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0);
        pPortRxPriMap [1]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1);
        pPortRxPriMap [2]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2);
        pPortRxPriMap [3]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3);
        pPortRxPriMap [4]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4);
        pPortRxPriMap [5]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5);
        pPortRxPriMap [6]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6);
        pPortRxPriMap [7]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortRxPriMapReg
 *
 *   @b Description
 *   @n This function sets up the contents of the Port Receive Packet
 *      Priority to Header Priority Mapping Register.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the priority mapping
                                registers must be configured.
        pPortRxPriMap           Array of Port Rx priority map priority values
                                that must be configured to the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7,
 *
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6,
 *      XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portNum = 1;
 *      Uint32      i, port0RxPriMap [8];

        for (i = 0; i < 8; i ++)
            port0RxPriMap [i] = i;

        CSL_CPSW_setPortRxPriMapReg (port0RxPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortRxPriMapReg (
    Uint32                      portNum,
    Uint32*                     pPortRxPriMap
)
{
    if(portNum == 0)
    {
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI0, pPortRxPriMap [0]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI1, pPortRxPriMap [1]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI2, pPortRxPriMap [2]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI3, pPortRxPriMap [3]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI4, pPortRxPriMap [4]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI5, pPortRxPriMap [5]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI6, pPortRxPriMap [6]);
        CSL_FINS (hCpswRegs->P0_RX_PRI_MAP_REG, XGE_CPSW_P0_RX_PRI_MAP_REG_PRI7, pPortRxPriMap [7]);
    }
    else if (portNum <= 8)
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI0, pPortRxPriMap [0]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI1, pPortRxPriMap [1]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI2, pPortRxPriMap [2]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI3, pPortRxPriMap [3]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI4, pPortRxPriMap [4]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI5, pPortRxPriMap [5]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI6, pPortRxPriMap [6]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_PRI_MAP_REG, XGE_CPSW_PN_RX_PRI_MAP_REG_PRI7, pPortRxPriMap [7]);
    }
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortRxDscpMap
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port DSCP to Priority
 *      Mapping Registers corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the DSCP mapping 
                                registers must be retrieved.
        pRxDscpPriMap           Array of Port Rx DSCP to priority mapping values 
                                read from the registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pRxDscpPriMap' must be large enough to hold all
 *       the 64 priority values read from the register.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7,
 *
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7
 *
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxDscpPriMap [64], portNum;
 
        portNum = 1;
        CSL_CPSW_getPortRxDscpMap (portNum, rxDscpPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortRxDscpMap (
    Uint32                      portNum, 
    Uint32*                     pRxDscpPriMap                
)
{
    int i, j;

    if(portNum == 0)
    {
        for( i = 0, j = 0; i < 8; j+=8, i++)
        {
            pRxDscpPriMap [j+0]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0);
            pRxDscpPriMap [j+1]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1);
            pRxDscpPriMap [j+2]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2);
            pRxDscpPriMap [j+3]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3);
            pRxDscpPriMap [j+4]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4);
            pRxDscpPriMap [j+5]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5);
            pRxDscpPriMap [j+6]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6);
            pRxDscpPriMap [j+7]   =   CSL_FEXT (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7);
        }
    }
    else
    {
    
        for( i = 0, j = 0; i < 8; j+=8, i++)
        {
            pRxDscpPriMap [j+0]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0);
            pRxDscpPriMap [j+1]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1);
            pRxDscpPriMap [j+2]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2);
            pRxDscpPriMap [j+3]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3);
            pRxDscpPriMap [j+4]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4);
            pRxDscpPriMap [j+5]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5);
            pRxDscpPriMap [j+6]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6);
            pRxDscpPriMap [j+7]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7);
        }
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortRxDscpMap
 *
 *   @b Description
 *   @n This function sets up the contents of the Port DSCP to Priority
 *      Mapping Registers corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the DSCP mapping 
                                registers must be configured.
        pRxDscpPriMap           Array of Port Rx DSCP to priority mapping values 
                                that must be configured to the registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pRxDscpPriMap' must be large enough to hold all
 *       the 64 priority values read from the register.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6,
 *      XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7,
 *
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6,
 *      XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7
 *
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxDscpPriMap [64], portNum;
 
        portNum = 1;
        
        for (i = 0; i < 64; i ++)
            port0RxPriMap [i] = i/8;
        
        CSL_CPSW_setPortRxDscpMap (portNum, rxDscpPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortRxDscpMap (
    Uint32                      portNum, 
    Uint32*                     pRxDscpPriMap                
)
{
    int i, j;

    if(portNum == 0)
    {
        for( i = 0, j = 0; i < 8; j+=8, i++)
        {
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI0, pRxDscpPriMap [j+0]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI1, pRxDscpPriMap [j+1]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI2, pRxDscpPriMap [j+2]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI3, pRxDscpPriMap [j+3]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI4, pRxDscpPriMap [j+4]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI5, pRxDscpPriMap [j+5]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI6, pRxDscpPriMap [j+6]);
            CSL_FINS (hCpswRegs->P0_RX_DSCP_MAP_REG[i], XGE_CPSW_P0_RX_DSCP_MAP_REG_PRI7, pRxDscpPriMap [j+7]);
        }
    }
    else
    {
    
        for( i = 0, j = 0; i < 8; j+=8, i++)
        {
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI0, pRxDscpPriMap [j+0]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI1, pRxDscpPriMap [j+1]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI2, pRxDscpPriMap [j+2]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI3, pRxDscpPriMap [j+3]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI4, pRxDscpPriMap [j+4]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI5, pRxDscpPriMap [j+5]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI6, pRxDscpPriMap [j+6]);
            CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_RX_DSCP_MAP_REG[i], XGE_CPSW_PN_RX_DSCP_MAP_REG_PRI7, pRxDscpPriMap [j+7]);
        }
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getRxRLimConfig
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPPI Rx Rate Limitaion 
 *      Configuration from the corresponding registers
 *
 *   @b Arguments
     @verbatim
        pRLimConfig             CSL_CPSW_RX_RATE_LIMIT_CONFIG structure that needs to be populated
                                with the rate limitaion register contents.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  none
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM,
 *      XGE_CPSW_P0_PRI_SEND_REG_COUNT,
 *      XGE_CPSW_P0_PRI_IDLE_REG_COUNT
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_RX_RATE_LIMIT_CONFIG       rLimConfig;
 
        CSL_CPSW_getRxRLimConfig (&rLimConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getRxRLimConfig (
    CSL_CPSW_RX_RATE_LIMIT_CONFIG*      pRLimConfig                
)
{
    Uint32 value, i, j;
    
    value = CSL_FEXT (hCpswRegs->P0_PRI_CTL_REG, XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM);
    
    /* Find number of ones from the left */
    j = 0x80;
    i = 0;
    while (j)
    {
        if(value & j)
        {
            i++;
            j >>= 1;
        }
        else
            break;
    }
    
    pRLimConfig->numRLimChans = i;
    i = 8 - i;
    
    for(j = 7; j >= i; j--)
    {
        pRLimConfig->sendStep[j] = CSL_FEXT (hCpswRegs->P0_PRI_SEND_REG[j], XGE_CPSW_P0_PRI_SEND_REG_COUNT);
        pRLimConfig->idleStep[j] = CSL_FEXT (hCpswRegs->P0_PRI_IDLE_REG[j], XGE_CPSW_P0_PRI_IDLE_REG_COUNT);  
    }
    
    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_setRxRLimConfig
 *
 *   @b Description
 *   @n This function sets up the contents of the CPPI Port Rx Rate Limitaion 
 *      registers per user-specified Rate Limitation Configuration
 *
 *   @b Arguments
     @verbatim
        pRLimConfig*            CSL_CPSW_RX_RATE_LIMIT_CONFIG structure that needs to 
                                be configured to the rate limitaion register contents.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  none
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM,
 *      XGE_CPSW_P0_PRI_SEND_REG_COUNT,
 *      XGE_CPSW_P0_PRI_IDLE_REG_COUNT
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_RX_RATE_LIMIT_CONFIG       rLimConfig;
        
        rLimConfig.numRLimChans = 2;
        
        rLimConfig.sendStep[7] = 10;
        rLimConfig.sendStep[6] = 10;
        
        rLimConfig.idleStep[7] = 20;
        rLimConfig.idleStep[6] = 20;
 
        CSL_CPSW_setRxRLimConfig (&rLimConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setRxRLimConfig (
    CSL_CPSW_RX_RATE_LIMIT_CONFIG*      pRLimConfig                
)
{
    Uint8 rLim[9] = {0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};
    int i, j;
    
    if(pRLimConfig->numRLimChans > 8)
        pRLimConfig->numRLimChans = 8;
    
    CSL_FINS (hCpswRegs->P0_PRI_CTL_REG, XGE_CPSW_P0_PRI_CTL_REG_RX_RLIM, rLim[pRLimConfig->numRLimChans]);
    
    for(j =7, i = 8 - pRLimConfig->numRLimChans; j >= i; j--)
    {
        CSL_FINS (hCpswRegs->P0_PRI_SEND_REG[j], XGE_CPSW_P0_PRI_SEND_REG_COUNT, pRLimConfig->sendStep[j]);
        CSL_FINS (hCpswRegs->P0_PRI_IDLE_REG[j], XGE_CPSW_P0_PRI_IDLE_REG_COUNT, pRLimConfig->idleStep[j]);  
    }
    
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getEEEGlobConfig
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW EEE Global Configuration.
 *
 *   @b Arguments
     @verbatim
        pGlobConfig             CSL_CPSW_EEE_GLOB_CONFIG structure that needs to be populated
                                with the contents of the corresponging EEE global control 
                                registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE
 *      XGE_CPSW_CONTROL_REG_EEE_ENABLE
 *      
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_EEE_GLOB_CONFIG    globConfig;

        CSL_CPSW_getEEEGlobConfig (&globConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getEEEGlobConfig (
	CSL_CPSW_EEE_GLOB_CONFIG*   pGlobConfig     
)
{
    pGlobConfig->enable      =   CSL_FEXT (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_EEE_ENABLE);
    pGlobConfig->prescale    =   CSL_FEXT (hCpswRegs->EEE_PRESCALE_REG, XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_setEEEGlobConfig
 *
 *   @b Description
 *   @n This function sets up the contents of the CPSW EEE related global registers 
 *      per user-specified EEE Global Configuration.
 *
 *   @b Arguments
     @verbatim
        pGlobConfig         CSL_CPSW_EEE_GLOB_CONFIG structure that holds the values 
                            that need to be configured to the EEE global control 
                            registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  CPSW EEE Global control register modified with values provided.
 *
 *   @b Writes
 *   @n XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE
 *      XGE_CPSW_CONTROL_REG_EEE_ENABLE
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_EEE_GLOB_CONFIG    globConfig;

        globConfig.enable       =   1;
        globalConfig.prescale   =   100;
        ...

        CSL_CPSW_setEEEGlobConfig (&globConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setEEEGlobConfig (
	CSL_CPSW_EEE_GLOB_CONFIG*   pGlobConfig     
)
{
    CSL_FINS (hCpswRegs->CONTROL_REG, XGE_CPSW_CONTROL_REG_EEE_ENABLE, pGlobConfig->enable);
    CSL_FINS (hCpswRegs->EEE_PRESCALE_REG, XGE_CPSW_EEE_PRESCALE_REG_EEE_PRESCALE, pGlobConfig->prescale);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_getEEEPortConfig
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW EEE Port Configuration.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the EEE Port Control 
                                registers must be retrieved.
        pPortConfig             CSL_CPSW_EEE_PORT_CONFIG structure that needs to be populated
                                with the contents of the corresponging EEE port-specific control 
                                registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_IDLE2LPI_REG_COUNT
 *      XGE_CPSW_P0_LPI2WAKE_REG_COUNT
 *
 *      XGE_CPSW_PN_IDLE2LPI_REG_COUNT
 *      XGE_CPSW_PN_LPI2WAKE_REG_COUNT
 *      XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN
 *
 *   @b Example
 *   @verbatim
        Uint32                      portNum;
        CSL_CPSW_EEE_PORT_CONFIG    portConfig;

        portNum = 1;
        CSL_CPSW_getEEEPortConfig (portNum, &portConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getEEEPortConfig (
    Uint32                      portNum,
	CSL_CPSW_EEE_PORT_CONFIG*   pPortConfig     
)
{
    if(portNum == 0)
    {
        pPortConfig->idle2lpi    =   CSL_FEXT (hCpswRegs->P0_IDLE2LPI_REG, XGE_CPSW_P0_IDLE2LPI_REG_COUNT);
        pPortConfig->lpi2wake    =   CSL_FEXT (hCpswRegs->P0_LPI2WAKE_REG, XGE_CPSW_P0_LPI2WAKE_REG_COUNT);
    }
    else
    {
        pPortConfig->idle2lpi    =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_IDLE2LPI_REG, XGE_CPSW_PN_IDLE2LPI_REG_COUNT);
        pPortConfig->lpi2wake    =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_LPI2WAKE_REG, XGE_CPSW_PN_LPI2WAKE_REG_COUNT);
        pPortConfig->txLpiClkstopEnable =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN);
    }

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_setEEEPortConfig
 *
 *   @b Description
 *   @n This function sets up the contents of the CPSW EEE port-specific control 
 *      registers per user-specified EEE Port Configuration.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the EEE Port Control 
                                registers must be configured.
        pPortConfig             CSL_CPSW_EEE_PORT_CONFIG structure holds the value 
                                that needs to be configured to the EEE port-specific 
                                control registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_IDLE2LPI_REG_COUNT
 *      XGE_CPSW_P0_LPI2WAKE_REG_COUNT
 *
 *      XGE_CPSW_PN_IDLE2LPI_REG_COUNT
 *      XGE_CPSW_PN_LPI2WAKE_REG_COUNT
 *      XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN
 *
 *   @b Example
 *   @verbatim
        Uint32                      portNum;
        CSL_CPSW_EEE_PORT_CONFIG    portConfig;

        portNum = 1;
        portConfig.idle2lpi = 10;
        portConfig.lpi2wake = 10;
        portConfig.txLpiClkstopEnable = 1;
        CSL_CPSW_setEEEPortConfig (portNum, &portConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setEEEPortConfig (
    Uint32                      portNum,
	CSL_CPSW_EEE_PORT_CONFIG*   pPortConfig     
)
{
    if(portNum == 0)
    {
        CSL_FINS (hCpswRegs->P0_IDLE2LPI_REG, XGE_CPSW_P0_IDLE2LPI_REG_COUNT, pPortConfig->idle2lpi);
        CSL_FINS (hCpswRegs->P0_LPI2WAKE_REG, XGE_CPSW_P0_LPI2WAKE_REG_COUNT, pPortConfig->lpi2wake);
    }
    else
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_IDLE2LPI_REG, XGE_CPSW_PN_IDLE2LPI_REG_COUNT, pPortConfig->idle2lpi);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_LPI2WAKE_REG, XGE_CPSW_PN_LPI2WAKE_REG_COUNT, pPortConfig->lpi2wake);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_CONTROL_REG, XGE_CPSW_PN_CONTROL_REG_TX_LPI_CLKSTOP_EN, pPortConfig->txLpiClkstopEnable);
    }

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_getEEEPortStatus
 *
 *   @b Description
 *   @n This function retrieves the contents of the EEE port-specific Status register 
 *      corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the EEE status
                                must be retrieved.
        pPortStatus             CSL_CPSW_EEE_PORT_STATUS structure holds the EEE Port Status.                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI,
 *      XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI,
 *      XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI,
 *      XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE,
 *      XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD,
 *      XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY,
 *      XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY,
 *
 *      XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI,
 *      XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI,
 *      XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI,
 *      XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE,
 *      XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD,
 *      XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY,
 *      XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY
 *
 *
 *
 *   @b Example
 *   @verbatim
 *      Uint32                      portNum;
        CSL_CPSW_EEE_PORT_STATUS    portStatus;

        portNum =   1;            
 
        CSL_CPSW_getEEEPortStatus (portNum, &portStatus);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_EEEPortStatus (
    Uint32                      portNum,
    CSL_CPSW_EEE_PORT_STATUS*   pPortStatus
)
{
    if (portNum == 0)
    {
        pPortStatus->wait_idle2lpi  =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_WAIT_IDLE2LPI);
        pPortStatus->rxLpi          =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_RX_LPI);
        pPortStatus->txLpi          =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_TX_LPI);
        pPortStatus->txWake         =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_TX_WAKE);
        pPortStatus->txFifoHold     =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_HOLD);
        pPortStatus->txFifoEmpty    =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_TX_FIFO_EMPTY);
        pPortStatus->rxFifoEmpty    =   CSL_FEXT (hCpswRegs->P0_EEE_STATUS_REG, XGE_CPSW_P0_EEE_STATUS_REG_RX_FIFO_EMPTY);
        
    } else
    {
        pPortStatus->wait_idle2lpi  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_WAIT_IDLE2LPI);
        pPortStatus->rxLpi          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_RX_LPI);
        pPortStatus->txLpi          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_TX_LPI);
        pPortStatus->txWake         =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_TX_WAKE);
        pPortStatus->txFifoHold     =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_HOLD);
        pPortStatus->txFifoEmpty    =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_TX_FIFO_EMPTY);
        pPortStatus->rxFifoEmpty    =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_EEE_STATUS_REG, XGE_CPSW_PN_EEE_STATUS_REG_RX_FIFO_EMPTY);
    }

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_getPortVlanReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the VLAN Register corresponding
 *      to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the VLAN register 
                                contents must be read 
        pPortVID                Port VLAN Id
        pPortCFI                Port CFI bit
        pPortPRI                Port VLAN priority (0-7, 7 is highest priority)
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI,
 *
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI,
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portVID, portCFI, portPRI, portNum;
 
        portNum =   1;
 
        CSL_CPSW_getPortVlanReg (portNum, &portVID, &portCFI, &portPRI);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortVlanReg (
    Uint32                      portNum,                
    Uint32*                     pPortVID,
    Uint32*                     pPortCFI,
    Uint32*                     pPortPRI
)
{
    if(portNum == 0)
    {
        *pPortVID   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID);
        *pPortCFI   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI);
        *pPortPRI   =   CSL_FEXT (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI);
    }
    else
    {
        *pPortVID   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID);
        *pPortCFI   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI);
        *pPortPRI   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI);
    }

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_setPortVlanReg
 *
 *   @b Description
 *   @n This function sets up the contents of the VLAN Register corresponding to
 *      the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the VLAN register 
                                must be configured. 
        portVID                 Port VLAN Id to be configured
        portCFI                 Port CFI bit to be configured
        portPRI                 Port VLAN priority to be configured
                                (0-7, 7 is highest priority)
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI,
 *
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID,
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI,
 *      XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI,
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portVID, portCFI, portPRI, portNum;
    
        portNum     =   1;
        portVID     =   1;
        portCFI     =   0;
        portPRI     =   7;

        CSL_CPSW_setPortVlanReg (portNum, portVID, portCFI, portPRI);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortVlanReg (
    Uint32                      portNum,                
    Uint32                      portVID,
    Uint32                      portCFI,
    Uint32                      portPRI
)
{
    if (portNum == 0)
    {
        CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_VID, portVID);
        CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_CFI, portCFI);
        CSL_FINS (hCpswRegs->P0_PORT_VLAN_REG, XGE_CPSW_P0_PORT_VLAN_REG_PORT_PRI, portPRI);
    }
    else
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_VID, portVID);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_CFI, portCFI);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_PORT_VLAN_REG, XGE_CPSW_PN_PORT_VLAN_REG_PORT_PRI, portPRI);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortMaxBlksReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Port Maxmium Block register 
 *      corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the max block value
                                must be retrieved.
        pRxMaxBlks              Receive FIFO Maximum Blocks - This value is the 
                                maximum number of 1k memory blocks that may be 
                                allocated to the FIFO's logical receive queue.
                                This value must be greater than or equal to 0x3.  
                                The recommended value of rx_max_blks is 0x9

        pTxMaxBlks              Transmit FIFO Maximum Blocks - This value is the 
                                maximum number of 1k memory blocks that may be 
                                allocated to the FIFO's logical transmit 
                                priority queues.  The recommended value of 
                                tx_max_blks is 0x3.                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS,
 *      XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS,
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxMaxBlks, txMaxBlks, portNum;

        portNum =   1;            
 
        CSL_CPSW_getPortMaxBlksReg (portNum, &rxMaxBlks, &txMaxBlks);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortMaxBlksReg (
    Uint32                      portNum,
    Uint32*                     pRxMaxBlks,
    Uint32*                     pTxMaxBlks
)
{
    if ((portNum >= 1) && (portNum <= 8))
    {
        *pRxMaxBlks  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_MAX_BLKS_REG, XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS);
        *pTxMaxBlks  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_MAX_BLKS_REG, XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortMaxBlksReg
 *
 *   @b Description
 *   @n This function sets up the contents of the Port Maxmium Block register 
 *      corresponding to the CPSW port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the max block value
                                must be retrieved.
        rxMaxBlks               Receive FIFO Maximum Blocks - This value is the 
                                maximum number of 1k memory blocks that may be 
                                allocated to the FIFO's logical receive queue.
                                This value must be greater than or equal to 0x3.  
                                The recommended value of rx_max_blks is 0x9

        txMaxBlks               Transmit FIFO Maximum Blocks - This value is the 
                                maximum number of 1k memory blocks that may be 
                                allocated to the FIFO's logical transmit 
                                priority queues.  The recommended value of 
                                tx_max_blks is 0x3.                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS,
 *      XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS,
 *
 *   @b Example
 *   @verbatim
 *      Uint32      rxMaxBlks, txMaxBlks, portNum;

        portNum =   1;            
 
        CSL_CPSW_setPortMaxBlksReg (portNum, rxMaxBlks, txMaxBlks);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortMaxBlksReg (
    Uint32                      portNum,
    Uint32                      rxMaxBlks,
    Uint32                      txMaxBlks
)
{
    if ((portNum >= 1) && (portNum <= 8))
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_MAX_BLKS_REG, XGE_CPSW_PN_MAX_BLKS_REG_RX_MAX_BLKS, rxMaxBlks);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_MAX_BLKS_REG, XGE_CPSW_PN_MAX_BLKS_REG_TX_MAX_BLKS, txMaxBlks);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortMACAddress
 *
 *   @b Description
 *   @n This function retreives the source MAC address of the Tx Pause Frame corresponding to the 
 *      CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the source MAC address
                                must be read and returned. (1-8)
        pMacAddress             6 byte Source MAC address read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pMacAddres' must be large enough the 6 byte
 *       MAC address returned by this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0,
 *      XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40
 *
 *   @b Example
 *   @verbatim
 *      Uint8   macAddress [6], portNum;
 
        portNum =   1;
 
        CSL_CPSW_getPortMACAddress (portNum, macAddress);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortMACAddress (
    Uint32                      portNum,                
    Uint8*                      pMacAddress                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        pMacAddress [0]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_L_REG, XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0);
        pMacAddress [1]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_L_REG, XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8);
        pMacAddress [2]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16);
        pMacAddress [3]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24);
        pMacAddress [4]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32);
        pMacAddress [5]   =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortMACAddress
 *
 *   @b Description
 *   @n This function sets up the source MAC address the Tx Pause Frame corresponding to the 
 *      CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the source MAC address
                                must be setup. (1-8)
        pMacAddress             6 byte Source MAC address to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pMacAddres' is expected to be 6 bytes long.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0,
 *      XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32,
 *      XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40
 *
 *   @b Example
 *   @verbatim
 *      Uint8   macAddress [6], portNum;
 
        portNum         =   1;
        macAddress [0]  =   0x01;
        macAddress [1]  =   0x02;
        macAddress [2]  =   0x03;
        macAddress [3]  =   0x04;
        macAddress [4]  =   0x05;
        macAddress [5]  =   0x06;
 
        CSL_CPSW_setPortMACAddress (portNum, macAddress);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortMACAddress (
    Uint32                      portNum,                
    Uint8*                      pMacAddress                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_L_REG, XGE_CPSW_PN_SA_L_REG_MACSRCADDR_7_0,   pMacAddress [0]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_L_REG, XGE_CPSW_PN_SA_L_REG_MACSRCADDR_15_8,  pMacAddress [1]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_23_16, pMacAddress [2]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_31_24, pMacAddress [3]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_39_32, pMacAddress [4]);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_SA_H_REG, XGE_CPSW_PN_SA_H_REG_MACSRCADDR_47_40, pMacAddress [5]);
    }

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_getPortTimeSyncCntlReg
 *
 *   @b Description
 *   @n This function retreives the contents of Time sync control register  
 *      corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be read. (1-8)
        pTimeSyncCntlCfg        CSL_CPSW_TSCNTL that needs to be populated with 
                                contents of time sync control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum;
        CSL_CPSW_TSCNTL     tsCtlCfg;
 
        portNum =   1;
 
        CSL_CPSW_getPortTimeSyncCntlReg (portNum, &tsCtlCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortTimeSyncCntlReg (
    Uint32                  portNum,                
    CSL_CPSW_TSCNTL*        pTimeSyncCntlCfg                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        pTimeSyncCntlCfg->tsRxAnnexDEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN);
        pTimeSyncCntlCfg->tsRxAnnexEEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN);
        pTimeSyncCntlCfg->tsRxAnnexFEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN);
        pTimeSyncCntlCfg->tsRxVlanLType1Enable      =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN);
        pTimeSyncCntlCfg->tsRxVlanLType2Enable      =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN);
        pTimeSyncCntlCfg->tsTxAnnexDEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN);
        pTimeSyncCntlCfg->tsTxAnnexEEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN);
        pTimeSyncCntlCfg->tsTxAnnexFEnable          =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN);
        pTimeSyncCntlCfg->tsTxVlanLType1Enable      =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN);
        pTimeSyncCntlCfg->tsTxVlanLType2Enable      =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN);
        pTimeSyncCntlCfg->tsMsgTypeEnable           =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN);
        pTimeSyncCntlCfg->tsTxHostEnable            =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN);
        pTimeSyncCntlCfg->tsLType2Enable            =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortTimeSyncCntlReg
 *
 *   @b Description
 *   @n This function sets up the contents of Time sync control register  
 *      corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be 
                                configured.
        pTimeSyncCntlCfg        CSL_CPSW_TSCNTL containing settings for time
                                sync control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum;
        CSL_CPSW_TSCNTL     tsCtlCfg;
 
        portNum =   1;

        tsCtlCfg.tsRxVlanLType1Enable   =   0;
        tsCtlCfg.tsRxVlanLType2Enable   =   0;
        ...
 
        CSL_CPSW_setPortTimeSyncCntlReg (portNum, &tsCtlCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortTimeSyncCntlReg (
    Uint32                  portNum,                
    CSL_CPSW_TSCNTL*        pTimeSyncCntlCfg                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN, 
                  pTimeSyncCntlCfg->tsRxAnnexDEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN, 
                  pTimeSyncCntlCfg->tsRxAnnexEEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN, 
                  pTimeSyncCntlCfg->tsRxAnnexFEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN,
                  pTimeSyncCntlCfg->tsRxVlanLType1Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN,
                  pTimeSyncCntlCfg->tsRxVlanLType2Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN,
                  pTimeSyncCntlCfg->tsTxAnnexDEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN,
                  pTimeSyncCntlCfg->tsTxAnnexEEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN,
                  pTimeSyncCntlCfg->tsTxAnnexFEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN,
                  pTimeSyncCntlCfg->tsTxVlanLType1Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN,
                  pTimeSyncCntlCfg->tsTxVlanLType2Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN,
                  pTimeSyncCntlCfg->tsTxHostEnable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN,
                  pTimeSyncCntlCfg->tsLType2Enable);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG, XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN,
                  pTimeSyncCntlCfg->tsMsgTypeEnable);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortTimeSyncSeqIdReg
 *
 *   @b Description
 *   @n This function retreives the contents of Time Sync Sequence Id and   
 *      LTYPE register corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be read. (1-8)
        pTsLtype                Time sync LTYPE read.
        pTsSeqIdOffset          Time sync sequence Id offset read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1,
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum, tsLtype, tsSeqIdOffset;
 
        portNum =   1;
 
        CSL_CPSW_getPortTimeSyncSeqIdReg (portNum, &tsLtype, &tsSeqIdOffset);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortTimeSyncSeqIdReg (
    Uint32                      portNum,                
    Uint32*                     pTsLtype,                
    Uint32*                     pTsSeqIdOffset
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        *pTsLtype           =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG, 
                                          XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1);
        *pTsSeqIdOffset     =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG, 
                                          XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortTimeSyncSeqIdReg
 *
 *   @b Description
 *   @n This function sets up the contents of Time Sync Sequence Id and   
 *      LTYPE register corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be 
                                configured. (1-8)
        tsLtype                 Time sync LTYPE to be configured.
        tsSeqIdOffset           Time sync sequence Id offset to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1,
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum, tsLtype, tsSeqIdOffset;
 
        portNum         =   1;
        tsLtype         =   0;
        tsSeqIdOffset   =   30;
 
        CSL_CPSW_getPortTimeSyncSeqIdReg (portNum, tsLtype, tsSeqIdOffset);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortTimeSyncSeqIdReg (
    Uint32                      portNum,                
    Uint32                      tsLtype,                
    Uint32                      tsSeqIdOffset
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG, 
                  XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1, tsLtype);

        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG, 
                  XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET, tsSeqIdOffset);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortTimeSyncVlanLTypeReg
 *
 *   @b Description
 *   @n This function retreives the contents of Time Sync VLAN LTYPE   
 *      register corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be read. (1-8)
        pTsVlanLtype1           Time sync VLAN LTYPE1 value read.
        pTsVlanLtype2           Time sync VLAN LTYPE2 value read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1,
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum, tsLtype1, tsLtype2;
 
        portNum =   1;
 
        CSL_CPSW_getPortTimeSyncVlanLTypeReg (portNum, &tsLtype1, &tsLtype2);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getPortTimeSyncVlanLTypeReg (
    Uint32                      portNum,                
    Uint32*                     pTsVlanLtype1,                
    Uint32*                     pTsVlanLtype2
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        *pTsVlanLtype1  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG, 
                                      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1);
        *pTsVlanLtype2  =   CSL_FEXT (hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG, 
                                      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortTimeSyncVlanLTypeReg
 *
 *   @b Description
 *   @n This function sets up the contents of Time Sync VLAN LTYPE   
 *      register corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the register must be read. (1-8)
        tsVlanLtype1            Time sync VLAN LTYPE1 value to be configured.
        tsVlanLtype2            Time sync VLAN LTYPE2 value to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1,
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum, tsLtype1, tsLtype2;
 
        portNum     =   1;
        tsLtype1    =   0x8100;
        tsLtype2    =   0x8100;
 
        CSL_CPSW_setPortTimeSyncVlanLTypeReg (portNum, &tsLtype1, &tsLtype2);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortTimeSyncVlanLTypeReg (
    Uint32                      portNum,                
    Uint32                      tsVlanLtype1,                
    Uint32                      tsVlanLtype2
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG, 
                  XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1, tsVlanLtype1);
        CSL_FINS (hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG, 
                  XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2, tsVlanLtype2);
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getPortTimeSyncCntlReg
 *
 *   @b Description
 *   @n This function retreives the contents of Time sync configuration from  
 *      time sync control registers corresponding to the CPSW port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the registers must be read. (1-8)
        pTimeSyncConfig         CSL_CPSW_TSCONFIG that needs to be populated with 
                                contents of time sync control registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN,
 *      
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1,
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET,
 *
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1,
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2,
 *
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_330,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN,
 *
 *      XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN,
 *      XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum;
        CSL_CPSW_TSCONFIG   tsConfig;
 
        portNum =   1;
 
        CSL_CPSW_getPortTimeSyncCntlReg (portNum, &tsConfig);

	 @endverbatim
 * =============================================================================
 */
 
static inline void CSL_CPSW_getPortTimeSyncConfig (
    Uint32                  portNum,                
    CSL_CPSW_TSCONFIG*      pTimeSyncConfig                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        Uint32 value;
        
        /* Time Sync Control Register */
        value = hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG;
        
        pTimeSyncConfig->tsRxAnnexDEnable          =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN);
        pTimeSyncConfig->tsRxAnnexEEnable          =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN);
        pTimeSyncConfig->tsRxAnnexFEnable          =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN);
        pTimeSyncConfig->tsRxVlanLType1Enable      =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN);
        pTimeSyncConfig->tsRxVlanLType2Enable      =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN);
        pTimeSyncConfig->tsTxAnnexDEnable          =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN);
        pTimeSyncConfig->tsTxAnnexEEnable          =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN);
        pTimeSyncConfig->tsTxAnnexFEnable          =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN);
        pTimeSyncConfig->tsTxVlanLType1Enable      =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN);
        pTimeSyncConfig->tsTxVlanLType2Enable      =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN);
        pTimeSyncConfig->tsMsgTypeEnable           =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN);
        pTimeSyncConfig->tsTxHostEnable            =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN);
        pTimeSyncConfig->tsLType2Enable            =   CSL_FEXT (value, 
                                                                   XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN);
                                                                   
        /* Time Sync Sequence and LTYPE Register */
        value = hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG;
        
        pTimeSyncConfig->tsLType1                  =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1);
        pTimeSyncConfig->tsSeqIdOffset             =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET);
                                                                  
        /* Time Sync VLAN Register */
        value = hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG;
        
        pTimeSyncConfig->tsVlanLType1              =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1);
        pTimeSyncConfig->tsVlanLType2              =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2);
                                                                  
        /* Time Sync Control and LTYPE 2 Register */
        value = hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_LTYPE2_REG;
        
        pTimeSyncConfig->tsLType2                  =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2);
        pTimeSyncConfig->ts107Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107);
                                                                                                                              
        pTimeSyncConfig->ts129Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129);
                                                                                                                              
        pTimeSyncConfig->ts130Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130);
                                                                                                                              
        pTimeSyncConfig->ts131Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131);
                                                                                                                              
        pTimeSyncConfig->ts132Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132);
                                                                                                                              
        pTimeSyncConfig->ts319Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319);
                                                                                                                              
        pTimeSyncConfig->ts320Enable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320);
                                                                                                                              
        pTimeSyncConfig->tsTTLNonzeroEnable        =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO);
        
        pTimeSyncConfig->tsUniEnable               =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN);
        
        /* Time Sync Control 2 Register */
        value = hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL2_REG;
        
        pTimeSyncConfig->tsMcastTypeEnable         =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN);
        pTimeSyncConfig->tsDomainOffset            =   CSL_FEXT (value, 
                                                                  XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET);
        
                                                                   
    }

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setPortTimeSyncConfig
 *
 *   @b Description
 *   @n This function sets up the contents of Time sync control registers  
 *      corresponding to the CPSW port number specified per user configuration.
 *
 *   @b Arguments
     @verbatim
        portNum                 CPSW port number for which the registers must be 
                                configured.
        pTimeSyncConfig         CSL_CPSW_TSCONFIG containing settings for time
                                sync control registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN,
 *      XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN
 *
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1,
 *      XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET,
 *
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1,
 *      XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2,
 *
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_330,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO,
 *      XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN,
 *
 *      XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN,
 *      XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET
 *
 *   @b Example
 *   @verbatim
 *      Uint32              portNum;
        CSL_CPSW_TSCONFIG   tsConfig;
 
        portNum =   1;

        tsConfig.tsRxVlanLType1Enable   =   0;
        tsConfig.tsRxVlanLType2Enable   =   0;
        ...
 
        CSL_CPSW_setPortTimeSyncConfig (portNum, &tsConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setPortTimeSyncConfig (
    Uint32                  portNum,                
    CSL_CPSW_TSCONFIG*        pTimeSyncConfig                
)
{
    if ((portNum >= 1) &&  (portNum <= 8))
    {
        Uint32 value = 0;
        
        /* Time Sync Control Register */
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_D_EN, pTimeSyncConfig->tsRxAnnexDEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_E_EN, pTimeSyncConfig->tsRxAnnexEEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_RX_ANNEX_F_EN, pTimeSyncConfig->tsRxAnnexFEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE1_EN, pTimeSyncConfig->tsRxVlanLType1Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_RX_VLAN_LTYPE2_EN, pTimeSyncConfig->tsRxVlanLType2Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_D_EN, pTimeSyncConfig->tsTxAnnexDEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_E_EN, pTimeSyncConfig->tsTxAnnexEEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_ANNEX_F_EN, pTimeSyncConfig->tsTxAnnexFEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE1_EN, pTimeSyncConfig->tsTxVlanLType1Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_VLAN_LTYPE2_EN, pTimeSyncConfig->tsTxVlanLType2Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_TX_HOST_TS_EN, pTimeSyncConfig->tsTxHostEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_LTYPE2_EN, pTimeSyncConfig->tsLType2Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_REG_TS_MSG_TYPE_EN, pTimeSyncConfig->tsMsgTypeEnable);
        hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_REG = value;                   
                  
                  
        /* Time Sync Sequence and LTYPE Register */
        value = 0;
        
        CSL_FINS (value, XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_LTYPE1, pTimeSyncConfig->tsLType1);
        CSL_FINS (value, XGE_CPSW_PN_TS_SEQ_LTYPE_REG_TS_SEQ_ID_OFFSET, pTimeSyncConfig->tsSeqIdOffset);
        hCpswRegs->ENETPORT[portNum-1].PN_TS_SEQ_LTYPE_REG = value;
                                                                  
        /* Time Sync VLAN Register */
        value = 0;
        
        CSL_FINS (value, XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE1, pTimeSyncConfig->tsVlanLType1);
        CSL_FINS (value, XGE_CPSW_PN_TS_VLAN_LTYPE_REG_TS_VLAN_LTYPE2, pTimeSyncConfig->tsVlanLType2);
        hCpswRegs->ENETPORT[portNum-1].PN_TS_VLAN_LTYPE_REG = value;                                                                 
                                                                  
        /* Time Sync Control and LTYPE 2 Register */
        value = 0;
        
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_LTYPE2, pTimeSyncConfig->tsLType2);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_107, pTimeSyncConfig->ts107Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_129, pTimeSyncConfig->ts129Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_130, pTimeSyncConfig->ts130Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_131, pTimeSyncConfig->ts131Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_132, pTimeSyncConfig->ts132Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_319, pTimeSyncConfig->ts319Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_320, pTimeSyncConfig->ts320Enable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_TTL_NONZERO, pTimeSyncConfig->tsTTLNonzeroEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL_LTYPE2_REG_TS_UNI_EN, pTimeSyncConfig->tsUniEnable);
        hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL_LTYPE2_REG = value;
        
        /* Time Sync Control 2 Register */
        value = 0;
        
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL2_REG_TS_MCAST_TYPE_EN, pTimeSyncConfig->tsMcastTypeEnable);
        CSL_FINS (value, XGE_CPSW_PN_TS_CTL2_REG_TS_DOMAIN_OFFSET, pTimeSyncConfig->tsDomainOffset);
        hCpswRegs->ENETPORT[portNum-1].PN_TS_CTL2_REG = value;          
    }

    return;
}



/********************************************************************************
*************************  Statistics (STATS) Submodule *************************
********************************************************************************/

/** ============================================================================
 *   @n@b CSL_CPSW_getStats
 *
 *   @b Description
 *   @n The CPSW stats are divided into 9 blocks, i.e., Stats for Host port (switch Port 0) 
 *      and Stats for CPSW ports (Port 1-8 ). This function
 *          - retreives hardware statistics for both the stat blocks.
 *          - Clear out the stats by the count being returned to application
 *          - Accumulates the stats count before returning to Application
 *      Function requires appplication to memset the stats (once before first
 *            use for accumulator, or once per use without accumulation)
 *      In the case of Linux ARM master use case all CPSW stats is recommended
 *      to be accessed from Linux.
 *      This function unconditionally clears the stats, so it requires the
 *      caller have exclusive ownership of the switch.  Otherwise, none of the
 *      callers (including Linux) will have complete accumulated stats.
 *      This function can be used to clear the stats by memesetting pCpswStats
 *      to 0 and discarding the returned stats.
 *
 *
 *   @b Arguments
     @verbatim
        pCpswStats              Array of CSL_CPSW_STATS structure that needs to be filled
                                with the stats read from the hardware. This function expects
                                that the array passed to it is big enough to hold the stats
                                for all stat blocks, i.e., size of array passed to this 
                                function must be 5 or 9 for 5/9 port switch respectively.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPSW_RXGOODFRAMES,
 *      CPSW_RXBROADCASTFRAMES,
 *      CPSW_RXMULTICASTFRAMES,
 *      CPSW_RXPAUSEFRAMES,
 *      CPSW_RXCRCERRORS,
 *      CPSW_RXALIGNCODEERRORS,
 *      CPSW_RXOVERSIZEDFRAMES,
 *      CPSW_RXJABBERFRAMES,
 *      CPSW_RXUNDERSIZEDFRAMES,
 *      CPSW_RXFRAGMENTS,
 *      CPSW_ALE_DROP,
 *      CPSW_ALE_OVERRUN_DROP,
 *      CPSW_RXOCTETS,
 *      CPSW_TXGOODFRAMES,
 *      CPSW_TXBROADCASTFRAMES,
 *      CPSW_TXMULTICASTFRAMES,
 *      CPSW_TXPAUSEFRAMES,
 *      CPSW_TXDEFERREDFRAMES,
 *      CPSW_TXCOLLISIONFRAMES,
 *      CPSW_TXSINGLECOLLFRAMES,
 *      CPSW_TXMULTCOLLFRAMES,
 *      CPSW_TXEXCESSIVECOLLISIONS,
 *      CPSW_TXLATECOLLISIONS,
 *      CPSW_TXUNDERRUN,
 *      CPSW_TXCARRIERSENSEERRORS,
 *      CPSW_TXOCTETS,
 *      CPSW_OCTETFRAMES64,
 *      CPSW_OCTETFRAMES65T127,
 *      CPSW_OCTETFRAMES128T255,
 *      CPSW_OCTETFRAMES256T511,
 *      CPSW_OCTETFRAMES512T1023,
 *      CPSW_OCTETFRAMES1024TUP,
 *      CPSW_NETOCTETS,
 *      CPSW_RX_BOTTOM_OF_FIFO_DROP,
 *      CPSW_PORTMASK_DROP,
 *      CPSW_RX_TOP_OF_FIFO_DROP,
 *      CPSW_ALE_ALE_RATE_LIMIT_DROP,
 *      CPSW_ALE_VID_INGRESS_DROP,
 *      CPSW_ALE_DA_EQ_SA_DROP,
 *      CPSW_ALE_UNKN_UNI,
 *      CPSW_ALE_UNKN_UNI_BCNT,
 *      CPSW_ALE_UNKN_MLT,
 *      CPSW_ALE_UNKN_MLT_BCNT,
 *      CPSW_ALE_UNKN_BRD,
 *      CPSW_ALE_UNKN_BRD_BCNT,
 *      CPSW_ALE_POLL_MATCH,
 *      CPSW_TX_MEMORY_PROTECT_ERROR
 *
 *   @b Affects
 *   @n CPSW_RXGOODFRAMES=0,
 *      CPSW_RXBROADCASTFRAMES=0,
 *      CPSW_RXMULTICASTFRAMES=0,
 *      CPSW_RXPAUSEFRAMES=0,
 *      CPSW_RXCRCERRORS=0,
 *      CPSW_RXALIGNCODEERRORS=0,
 *      CPSW_RXOVERSIZEDFRAMES=0,
 *      CPSW_RXJABBERFRAMES=0,
 *      CPSW_RXUNDERSIZEDFRAMES=0,
 *      CPSW_RXFRAGMENTS=0,
 *      CPSW_ALE_DROP=0,
 *      CPSW_ALE_OVERRUN_DROP=0,
 *      CPSW_RXOCTETS=0,
 *      CPSW_TXGOODFRAMES=0,
 *      CPSW_TXBROADCASTFRAMES=0,
 *      CPSW_TXMULTICASTFRAMES=0,
 *      CPSW_TXPAUSEFRAMES=0,
 *      CPSW_TXDEFERREDFRAMES=0,
 *      CPSW_TXCOLLISIONFRAMES=0,
 *      CPSW_TXSINGLECOLLFRAMES=0,
 *      CPSW_TXMULTCOLLFRAMES=0,
 *      CPSW_TXEXCESSIVECOLLISIONS=0,
 *      CPSW_TXLATECOLLISIONS=0,
 *      CPSW_TXUNDERRUN=0,
 *      CPSW_TXCARRIERSENSEERRORS=0,
 *      CPSW_TXOCTETS=0,
 *      CPSW_OCTETFRAMES64=0,
 *      CPSW_OCTETFRAMES65T127=0,
 *      CPSW_OCTETFRAMES128T255=0,
 *      CPSW_OCTETFRAMES256T511=0,
 *      CPSW_OCTETFRAMES512T1023=0,
 *      CPSW_OCTETFRAMES1024TUP=0,
 *      CPSW_NETOCTETS=0,
 *      CPSW_RX_BOTTOM_OF_FIFO_DROP=0,
 *      CPSW_PORTMASK_DROP=0,
 *      CPSW_RX_TOP_OF_FIFO_DROP=0,
 *      CPSW_ALE_ALE_RATE_LIMIT_DROP=0,
 *      CPSW_ALE_VID_INGRESS_DROP=0,
 *      CPSW_ALE_DA_EQ_SA_DROP=0,
 *      CPSW_ALE_UNKN_UNI=0,
 *      CPSW_ALE_UNKN_UNI_BCNT=0,
 *      CPSW_ALE_UNKN_MLT=0,
 *      CPSW_ALE_UNKN_MLT_BCNT=0,
 *      CPSW_ALE_UNKN_BRD=0,
 *      CPSW_ALE_UNKN_BRD_BCNT=0,
 *      CPSW_ALE_POLL_MATCH=0,
 *      CPSW_TX_MEMORY_PROTECT_ERROR=0
 *
 *   @b Example
 *   @verbatim
 *      CSL_CPSW_STATS     stats [9];
 
        CSL_CPSW_getStats (stats);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getStats (
    CSL_CPSW_STATS*         pCpswStats                
)
{
    Uint32                      numStats, numBlocks;
    volatile Uint32             *pRegAddr;
    Uint32                      *pStatAddr;
    Uint32                      statval;

    pStatAddr   =   (Uint32 *)(pCpswStats);

    /* Read the entire stats block for both the
     * Host and the MAC ports and reset the stats
     * block when done.
     */
    for (numBlocks = 0; numBlocks < CSL_CPSW_NUMSTATBLOCKS; numBlocks++)
    {
    	pRegAddr    =	&hCpswRegs->STATS[numBlocks].RXGOODFRAMES;    	
        for (numStats = 0; numStats < sizeof(CSL_CPSW_STATS)/sizeof(Uint32); numStats++)
        {
            statval         =   *pRegAddr;
            *pRegAddr++     =   statval;
            statval         +=  *pStatAddr;
            *pStatAddr++    =   statval;
        }
    }

    return;
}
/** ============================================================================
 *   @n@b CSL_CPSW_getRawStats
 *
 *   @b Description
 *   @n The CPSW stats are divided into 9 blocks, i.e., Stats for Host port (switch Port 0)
 *      and Stats for MAC ports (Port 1-8). This function retreives snapshot of
 *      hardware statistics for all the stat blocks. In the case of Linux ARM master
 *      use case all CPSW stats is recommended to be accessed from Linux.

 *      Since this function does not clear the stats, its possible to have
 *      non-exclusive ownership of the switch and use this function without
 *      corrupting other caller's view of the stats.
 *
 *      Additional Note: In order to avoid stats loss due to rollovers, application
 *      would need to poll the stats by determining the correct interval.
 *      The stat CPSW_NETOCTETS would be first one to roll over
 *      The software must poll and accumulate the stats faster than this rate.
 *      On a 1 gigabit network, it takes approximately
 *      (0x100000000/(1000000000/8)/2)=17 seconds to roll over (the /2 is because
 *      this stat contains both tx and rx, both of which run at gigabit).
 *      A good rule of thumb is to poll at twice this rate (8-9 seconds).
 *
 *      If it is really necessary for application to have multiple nonexclusive
 *      owners of the switch, it is possible for all callers to have a view of
 *      the accumulated statistics if they (including Linux) follows the
 *      differential accumulation of the stats defiened below:
 *      uint64_t accum_CPSW_NETOCTETS;
 *      uint32_t old_CPSW_NETOCTETS, new_CPSW_NETOCTETS, diff_CPSW_NETOCTETS;
 *
 *       diff_CPSW_NETOCTETS = new_CPSW_NETOCTETS - old_CPSW_NETOCTETS; // let rollover occur, no "if" required
 *       old_CPSW_NETOCTETS = new_CPSW_NETOCTETS;
 *       accum_CPSW_NETOCTETS += diff_CPSW_NETOCTETS
 *
 *   @b Arguments
     @verbatim
        pCpswStats              Array of CSL_CPSW_STATS structure that needs to be filled
                                with the stats read from the hardware. This function expects
                                that the array passed to it is big enough to hold the stats
                                for both stat blocks, i.e., size of array passed to this
                                function must be 5 or 9 for 5-port/9-port switch respectively.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPSW_RXGOODFRAMES,
 *      CPSW_RXBROADCASTFRAMES,
 *      CPSW_RXMULTICASTFRAMES,
 *      CPSW_RXPAUSEFRAMES,
 *      CPSW_RXCRCERRORS,
 *      CPSW_RXALIGNCODEERRORS,
 *      CPSW_RXOVERSIZEDFRAMES,
 *      CPSW_RXJABBERFRAMES,
 *      CPSW_RXUNDERSIZEDFRAMES,
 *      CPSW_RXFRAGMENTS,
 *      CPSW_ALE_DROP,
 *      CPSW_ALE_OVERRUN_DROP,
 *      CPSW_RXOCTETS,
 *      CPSW_TXGOODFRAMES,
 *      CPSW_TXBROADCASTFRAMES,
 *      CPSW_TXMULTICASTFRAMES,
 *      CPSW_TXPAUSEFRAMES,
 *      CPSW_TXDEFERREDFRAMES,
 *      CPSW_TXCOLLISIONFRAMES,
 *      CPSW_TXSINGLECOLLFRAMES,
 *      CPSW_TXMULTCOLLFRAMES,
 *      CPSW_TXEXCESSIVECOLLISIONS,
 *      CPSW_TXLATECOLLISIONS,
 *      CPSW_TXUNDERRUN,
 *      CPSW_TXCARRIERSENSEERRORS,
 *      CPSW_TXOCTETS,
 *      CPSW_OCTETFRAMES64,
 *      CPSW_OCTETFRAMES65T127,
 *      CPSW_OCTETFRAMES128T255,
 *      CPSW_OCTETFRAMES256T511,
 *      CPSW_OCTETFRAMES512T1023,
 *      CPSW_OCTETFRAMES1024TUP,
 *      CPSW_NETOCTETS,
 *      CPSW_RX_BOTTOM_OF_FIFO_DROP,
 *      CPSW_PORTMASK_DROP,
 *      CPSW_RX_TOP_OF_FIFO_DROP,
 *      CPSW_ALE_ALE_RATE_LIMIT_DROP,
 *      CPSW_ALE_VID_INGRESS_DROP,
 *      CPSW_ALE_DA_EQ_SA_DROP,
 *      CPSW_ALE_UNKN_UNI,
 *      CPSW_ALE_UNKN_UNI_BCNT,
 *      CPSW_ALE_UNKN_MLT,
 *      CPSW_ALE_UNKN_MLT_BCNT,
 *      CPSW_ALE_UNKN_BRD,
 *      CPSW_ALE_UNKN_BRD_BCNT,
 *      CPSW_ALE_POLL_MATCH,
 *      CPSW_TX_MEMORY_PROTECT_ERROR
 *
 *   @b Example
 *   @verbatim
 *      CSL_CPSW_STATS     stats [9];

        CSL_CPSW_getRawStats (stats);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getRawStats (
    CSL_CPSW_STATS*         pCpswStats
)
{
    Uint32                      numStats, numBlocks;
    volatile Uint32             *pRegAddr;
    Uint32                      *pStatAddr;

    pStatAddr   =   (Uint32 *)(pCpswStats);

    /* Read the entire stats block for both the
     * Host and the MAC ports
     */
    for (numBlocks = 0; numBlocks < CSL_CPSW_NUMSTATBLOCKS; numBlocks++)
    {
        pRegAddr    =	&hCpswRegs->STATS[numBlocks].RXGOODFRAMES;
        for (numStats = 0; numStats < sizeof(CSL_CPSW_STATS)/sizeof(Uint32); numStats++)
        {
            *pStatAddr++    =   *pRegAddr++;
        }
    }

    return;
}

/********************************************************************************
********************  Address Lookup Engine (ALE) Submodule *********************
********************************************************************************/

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the ALE submodule identification and version 
 *      information.
 *
 *   @b Arguments
     @verbatim
        pVersionInfo        CSL_CPSW_ALE_VERSION structure that needs to be populated
                            with the ALE version info read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_IDVER_REG_MINOR_VER,
 *      ALE_IDVER_REG_MAJOR_VER,
 *      ALE_IDVER_REG_RTL_VER,
 *      ALE_IDVER_REG_IDENT
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_ALE_VERSION    versionInfo;

        CSL_CPSW_getAleVersionInfo (&versionInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleVersionInfo (
	CSL_CPSW_ALE_VERSION*       pVersionInfo     
)
{

    pVersionInfo->minorVer  =   CSL_FEXT (hCpswAleRegs->IDVER_REG, ALE_IDVER_REG_MINOR_VER);
    pVersionInfo->majorVer  =   CSL_FEXT (hCpswAleRegs->IDVER_REG, ALE_IDVER_REG_MAJOR_VER);
    pVersionInfo->rtlVer    =   CSL_FEXT (hCpswAleRegs->IDVER_REG, ALE_IDVER_REG_RTL_VER);
    pVersionInfo->id        =   CSL_FEXT (hCpswAleRegs->IDVER_REG, ALE_IDVER_REG_IDENT);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleRateLimitEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE Broadcast and Multicast Rate Limit is
 *      enabled.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE Broadcast and multicast rate limit enabled.
 *	                            Broadcast/multicast packet reception limited to
 *	                            port control register rate limit fields.
 *	 @n  FALSE                  ALE Broadcast and multicast rate limit disabled. 
 *	                            Broadcast/multicast rates not limited.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_ENABLE_RATE_LIMIT
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleRateLimitEnabled () == TRUE)
        {
            // ALE Broadcast/Multicast rate limit enabled
        }
        else
        {
            // ALE Broadcast/Multicast rate limit disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleRateLimitEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_RATE_LIMIT);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleRateLimit
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable multicast,
 *      broadcast rate limiting.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_RATE_LIMIT=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleRateLimit ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleRateLimit (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_RATE_LIMIT, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleRateLimit
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable multicast,
 *      broadcast rate limiting.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_RATE_LIMIT=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleRateLimit ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleRateLimit (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_RATE_LIMIT, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleMacAuthModeEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE MAC Authorization mode is enabled.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE  is in MAC authorization mode.
 *	 @n  FALSE                  ALE not in MAC authorization mode. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_ENABLE_AUTH_MODE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleMacAuthModeEnabled () == TRUE)
        {
            // ALE  is in MAC authorization mode
        }
        else
        {
            // ALE not in MAC authorization mode
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleMacAuthModeEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_AUTH_MODE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleMacAuthMode
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable MAC authorization
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_AUTH_MODE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleMacAuthMode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleMacAuthMode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_AUTH_MODE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleMacAuthMode
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable MAC authorization
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_AUTH_MODE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleMacAuthMode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleMacAuthMode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_AUTH_MODE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleVlanAwareEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to be VLAN aware.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE VLAN aware. ALE drops packets if VLAN not found.
 *	 @n  FALSE                  ALE not VLAN aware. Floods if VLAN not found.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_VLAN_AWARE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleVlanAwareEnabled () == TRUE)
        {
            // ALE VLAN aware
        }
        else
        {
            // ALE not VLAN aware
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleVlanAwareEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_VLAN_AWARE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleVlanAware
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable VLAN aware
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_VLAN_AWARE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleVlanAware ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleVlanAware (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_VLAN_AWARE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleVlanAware
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable VLAN aware
 *      mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_VLAN_AWARE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleVlanAware ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleVlanAware (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_VLAN_AWARE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleTxRateLimitEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to be Tx-port based multicast,
 *      broadcast rate limited.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE Tx rate limit enabled. Broadcast, multicast
 *	                            rate limit counters are transmit port based.
 *	 @n  FALSE                  ALE Tx rate limit disabled. Broadcast, multicast
 *	                            rate limit counters are receive port based.
 *
 *   <b> Pre Condition </b>
 *   @n  ALE_CONTROL_REG_ENABLE_RATE_LIMIT=1
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_RATE_LIMIT_TX
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleTxRateLimitEnabled () == TRUE)
        {
            // ALE Tx rate limit on
        }
        else
        {
            // ALE Tx rate limit off
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleTxRateLimitEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_RATE_LIMIT_TX);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleTxRateLimit
 *
 *   @b Description
 *   @n This function configures the ALE control register to select Tx-port based 
 *      multicast, broadcast rate limiting
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  ALE_CONTROL_REG_ENABLE_RATE_LIMIT=1
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_RATE_LIMIT_TX=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleTxRateLimit ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleTxRateLimit (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_RATE_LIMIT_TX, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleTxRateLimit
 *
 *   @b Description
 *   @n This function configures the ALE control register to select Rx-port based 
 *      multicast, broadcast rate limiting
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_RATE_LIMIT_TX=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleTxRateLimit ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleTxRateLimit (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_RATE_LIMIT_TX, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleBypassEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to be in Bypass mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE Bypass mode enabled.
 *	 @n  FALSE                  ALE Bypass mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_BYPASS
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleBypassEnabled () == TRUE)
        {
            // ALE Bypass mode on
        }
        else
        {
            // ALE Bypass mode off
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleBypassEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_BYPASS);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleBypass
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable Bypass mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_BYPASS=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleBypass ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleBypass (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_BYPASS, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleBypass
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable Bypass mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_BYPASS=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleBypass ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleBypass (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_BYPASS, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleOUIDenyModeEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to be in OUI deny mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE OUI deny mode enabled.
 *	 @n  FALSE                  ALE OUI deny mode disabled. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_ENABLE_OUI_DENY
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleOUIDenyModeEnabled () == TRUE)
        {
            // ALE OUI deny mode on
        }
        else
        {
            // ALE OUI deny mode off
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleOUIDenyModeEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_OUI_DENY);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleOUIDenyMode
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable OUI deny mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_OUI_DENY=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleOUIDenyMode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleOUIDenyMode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_OUI_DENY, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleOUIDenyMode
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable OUI deny mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE_OUI_DENY=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleOUIDenyMode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleOUIDenyMode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE_OUI_DENY, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleVID0ModeEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to be in VID0 (VLAN ID=0) mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE VID0 mode enabled. 
 *	                            Process the packet with VLAN Id = 0
 *	 @n  FALSE                  ALE VID0 mode disabled. Process the packet with 
 *	                            VLAN Id =PORT_VLAN[11-0]
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_EN_VID0_MODE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleVID0ModeEnabled () == TRUE)
        {
            // ALE VID0 mode on
        }
        else
        {
            // ALE VID0 mode off
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleVID0ModeEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_EN_VID0_MODE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleVID0Mode
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable VID0 mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_EN_VID0_MODE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleVID0Mode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleVID0Mode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_EN_VID0_MODE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleVID0Mode
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable VID0 mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_EN_VID0_MODE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleVID0Mode ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleVID0Mode (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_EN_VID0_MODE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleLearnNoVIDEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to not learn VLAN Ids.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE Learn no VID enabled. 
 *	                            VLAN Id is not learned with source address (source 
 *	                            address is not tied to VID)
 *	 @n  FALSE                  ALE VID learning mode enabled. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_LEARN_NO_VID
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleLearnNoVIDEnabled () == TRUE)
        {
            // ALE VID learning disabled
        }
        else
        {
            // ALE VID learning enabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleLearnNoVIDEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_LEARN_NO_VID);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleLearnNoVID
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable VLAN Id No
 *      Learn, i.e., disable VLAN Id learning.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_LEARN_NO_VID=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleLearnNoVID ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleLearnNoVID (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_LEARN_NO_VID, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleLearnNoVID
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable VLAN Id learning.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_LEARN_NO_VID=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleLearnNoVID ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleLearnNoVID (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_LEARN_NO_VID, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleUUNIToHostEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to forward unkown unicast
 *      packets to host.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Unknown unicast packets flood to host also. 
 *	 @n  FALSE                  Unknown unicast packets are dropped to the host. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_UNI_FLOOD_TO_HOST
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleUUNIToHostEnabled () == TRUE)
        {
            // ALE Unknown UNI packets forwarded to host
        }
        else
        {
            // ALE Unknown UNI packets dropped to host
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleUUNIToHostEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_UNI_FLOOD_TO_HOST);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleUUNIToHost
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable forwarding 
 *      unkown unicast packets to host.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_UNI_FLOOD_TO_HOST=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleUUNIToHost ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleUUNIToHost (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_UNI_FLOOD_TO_HOST, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleUUNIToHost
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable forwarding 
 *      unkown unicast packets to host.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_UNI_FLOOD_TO_HOST=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleUUNIToHost ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleUUNIToHost (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_UNI_FLOOD_TO_HOST, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleUVLANNoLearnEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE is programmed to disable learning of the 
 *      packets with unknown VLAN.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Unknown VLAN No Learn enabled. 
 *                              Source addresses of unknown VLANIDs are not added into 
 *                              the look up table even if learning is enabled. 
 *	 @n  FALSE                  Unknown VLAN No Learn disabled. 
 *                              Source addresses of unknown VLANIDs are added into 
 *                              the look up table if learning is enabled. 
 *
 *   <b> Pre Condition </b>
 *   @n  ALE_CONTROL_REG_ENABLE = 1 
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n 	ALE_CONTROL_REG_UVLAN_NO_LEARN
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleUVLANNoLearnEnabled () == TRUE)
        {
            // Unknown VLAN No Learn disabled
        }
        else
        {
            // Unknown VLAN No Learn enabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleUVLANNoLearnEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, 	ALE_CONTROL_REG_UVLAN_NO_LEARN);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAleUVLANNoLearn
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable 
 *      Unknown VLAN No Learn mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  ALE_CONTROL_REG_ENABLE = 1
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n 	ALE_CONTROL_REG_UVLAN_NO_LEARN=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAleUVLANNoLearn ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAleUVLANNoLearn (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, 	ALE_CONTROL_REG_UVLAN_NO_LEARN, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAleUVLANNoLearn
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable 
 *      unknown VLAN No Learn mode.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  ALE_CONTROL_REG_ENABLE = 1
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n 	ALE_CONTROL_REG_UVLAN_NO_LEARN=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAleUVLANNoLearn ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAleUVLANNoLearn (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, 	ALE_CONTROL_REG_UVLAN_NO_LEARN, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleUpdateBW
 *
 *   @b Description
 *   @n This function extracts the ALE Update Bandwidth of the ALE control register
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 aleUpdBW               ALE Update Bandwidth 
 *
 *   <b> Pre Condition </b>
 *   @n  None 
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n 	ALE_CONTROL_REG_UPD_BW_CTL
 *
 *   @b Example
 *   @verbatim
 
        Uint32  aleUpdBW;
        
        aleUpdBW = CSL_CPSW_getAleUpdateBW();
        
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getAleUpdateBW (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_UPD_BW_CTL);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleUpdateBW
 *
 *   @b Description
 *   @n This function configures the ALE Update Bandwidth of the ALE control 
 *      register. 
 *
 *   @b Arguments
 *   @n aleUpdBW               ALE Update Bandwidth
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n 	ALE_CONTROL_REG_UPD_BW_CTL
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_setAleUpdateBW ((Uint32)ALE_UPD_BW_350MHZ_5M);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleUpdateBW 
(
    Uint32                      aleUpdBW             
)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, 	ALE_CONTROL_REG_UPD_BW_CTL, aleUpdBW);

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_startAleAgeOutNow
 *
 *   @b Description
 *   @n This function configures the ALE control register to initiate an ALE
 *      ageable entry cleanup. This enables the ALE hardware to remove any
 *      ageable table entry that does not have a set touch bit.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_AGE_OUT_NOW=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_startAleAgeOutNow ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_startAleAgeOutNow (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_AGE_OUT_NOW, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleAgeOutDone
 *
 *   @b Description
 *   @n This function reads the ALE control register's AGE_OUT_NOW bit to check
 *      if the ALE ageable entry cleanup process is done.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE age out process done. 
 *	 @n  FALSE                  ALE age out process not yet completed.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_AGE_OUT_NOW
 *
 *   @b Example
 *   @verbatim
 
        if (CSL_CPSW_isAleAgeOutDone ();
	 
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleAgeOutDone (void)
{
    if ((CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_AGE_OUT_NOW) == 0))
    {
        return TRUE;
    }
    else
    {
        return FALSE;            
    }
}

/** ============================================================================
 *   @n@b CSL_CPSW_clearAleTable
 *
 *   @b Description
 *   @n This function initiates a full ALE table cleanup. The ALE hardware 
 *      clears all table entries. 
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_CLEAR_TABLE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_clearAleTable ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_clearAleTable (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_CLEAR_TABLE, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_isAleEnabled
 *
 *   @b Description
 *   @n This function indicates if ALE processing is enabled.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   ALE enabled. ALE packet processing will be done.
 *	 @n  FALSE                  ALE disabled. All packets are dropped by ALE.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG_ENABLE
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPSW_isAleEnabled () == TRUE)
        {
            // ALE enabled
        }
        else
        {
            // ALE disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_isAleEnabled (void)
{

    return CSL_FEXT (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_enableAle
 *
 *   @b Description
 *   @n This function configures the ALE control register to enable ALE processing.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_enableAle ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_enableAle (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE, (Uint32) 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_disableAle
 *
 *   @b Description
 *   @n This function configures the ALE control register to disable ALE processing.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG_ENABLE=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPSW_disableAle ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_disableAle (void)
{
    CSL_FINS (hCpswAleRegs->CONTROL_REG, ALE_CONTROL_REG_ENABLE, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE control register.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                ALE control register contents.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_CONTROL_REG
 *
 *   @b Example
 *   @verbatim
        Uint32      aleCtrlVal;
 
        aleCtrlVal  =   CSL_CPSW_getAleControlReg ();
	 
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getAleControlReg (void)
{
    return hCpswAleRegs->CONTROL_REG;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleControlReg
 *
 *   @b Description
 *   @n This function sets up the contents of the ALE control register.
 *
 *   @b Arguments
     @verbatim
        aleCtrlVal          Value to be configured to the ALE control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_CONTROL_REG
 *
 *   @b Example
 *   @verbatim
 *      Uint32          aleCtrlVal = 0;

        aleCtrlVal      =   CSL_CPSW_getAleControlReg ();
        aleCtrlVal      |=  CSL_XGE_CPSW_ALECONTROL_CLRTABLE_EN;

        CSL_CPSW_setAleControlReg (&aleCtrlRegInfo);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleControlReg 
(
    Uint32                      aleCtrlVal
)
{
    hCpswAleRegs->CONTROL_REG  =   aleCtrlVal;

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleStatusReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE Status register.
 *
 *   @b Arguments
     @verbatim
        pNumPolicers            Number of policers the ALE implements (multiple of 8)
        pNumEntries             Number of total table entries supported (multiple of 1024).
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_STATUS_REG_ENTRIES_DIV_1024
 *      ALE_STATUS_REG_POLICERS_DIV_8
 *
 *   @b Example
 *   @verbatim
        Uint32      numPolicers, numEntries;
 
        CSL_CPSW_getAleStatusReg (&numPolicers, 
                                  &numEntries);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleStatusReg
(
    Uint32*                        pNumPolicers,
    Uint32*                        pNumEntries
)
{
    *pNumPolicers     =   CSL_FEXT(hCpswAleRegs->STATUS_REG, ALE_STATUS_REG_POLICERS_DIV_8) << 3;
    *pNumEntries      =   CSL_FEXT(hCpswAleRegs->STATUS_REG, ALE_STATUS_REG_ENTRIES_DIV_1024) << 10;
}


/** ============================================================================
 *   @n@b CSL_CPSW_getAlePrescaleReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE Prescale register.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                ALE prescale register contents.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_PRESCALE_REG_PRESCALE
 *
 *   @b Example
 *   @verbatim
        Uint32      alePrescaleVal;
 
        alePrescaleVal  =   CSL_CPSW_getAlePrescaleReg ();
	 
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPSW_getAlePrescaleReg (void)
{
    return CSL_FEXT(hCpswAleRegs->PRESCALE_REG, ALE_PRESCALE_REG_PRESCALE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAlePrescaleReg
 *
 *   @b Description
 *   @n This function sets up the contents of the ALE prescale register.
 *
 *   @b Arguments
     @verbatim
        alePrescaleVal      Value to be configured to the ALE Prescale register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_PRESCALE_REG_PRESCALE
 *
 *   @b Example
 *   @verbatim
 *      Uint32          alePrescaleVal = 0;

        alePrescaleVal  =   10;

        CSL_CPSW_setAlePrescaleReg (&aleCtrlRegInfo);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAlePrescaleReg 
(
    Uint32                      alePrescaleVal
)
{
    CSL_FINS (hCpswAleRegs->PRESCALE_REG, ALE_PRESCALE_REG_PRESCALE, alePrescaleVal);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleAgingTimerReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE Aging Timer register.
 *
 *   @b Arguments
     @verbatim
        pAgingPrescale          Aging Timer prescale (1, 1000, 1000000)
        pAgingPeriod            Aging period in units of prescale.
                                When non-zero, auto-aging is enabled.  
                                This value (minus 1) times prescale is the number 
                                of clock cycles after which auto-aging will automatically 
                                be initiated.  
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_AGING_TIMER_REG_AGING_TIMER
 *      ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE
 *      ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE
 *
 *   @b Example
 *   @verbatim
        Uint32      aleAgingPrescale;
        Uint32      aleAgingPeriod
 
        CSL_CPSW_getAleAgingTimerReg (&aleAgingPrescale,
                                      &aleAgingPeriod);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleAgingTimerReg 
(
    Uint32*                        pAgingPrescale,
    Uint32*                        pAgingPeriod
)
{
    Uint32 prescale1Dis, prescale2Dis;
    
    prescale1Dis = CSL_FEXT(hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE);
    prescale2Dis = CSL_FEXT(hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE);
    
    if(prescale1Dis && prescale2Dis)
    {
        *pAgingPrescale = (Uint32)ALE_AGT_PRESACLE_1;
    }
    else if (prescale1Dis && prescale2Dis)
    {
        *pAgingPrescale = (Uint32)ALE_AGT_PRESACLE_1000;
    }else
    {
        *pAgingPrescale = (Uint32)ALE_AGT_PRESACLE_1M;
    }
    
    *pAgingPeriod = CSL_FEXT(hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_AGING_TIMER);
    
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleAgingTimerReg
 *
 *   @b Description
 *   @n This function sets up the contents of the ALE Aging Timer register.
 *
 *   @b Arguments
     @verbatim
        agingPrescale           Aging Timer prescale (1, 1000, 1000000)
        agingPeriod             Aging period in units of prescale.
                                When non-zero, auto-aging is enabled.  
                                This value (minus 1) times prescale is the number 
                                of clock cycles after which auto-aging will automatically 
                                be initiated.  
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_AGING_TIMER_REG_AGING_TIMER
 *      ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE
 *      ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE
 *
 *   @b Example
 *   @verbatim
        Uint32      aleAgingPrescale;
        Uint32      aleAgingPeriod;
        
        aleAgingPrescale = (Uint32)ALE_AGT_PRESACLE_1M;
        aleAgingPeriod = 1000; 
 
        CSL_CPSW_setAleAgingTimerReg (aleAgingPrescale,
                                      aleAgingPeriod);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleAgingTimerReg 
(
    Uint32                         agingPrescale,
    Uint32                         agingPeriod
)
{
    if(agingPeriod == (Uint32)ALE_AGT_PRESACLE_1M)
    {
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE, (Uint32) 0);
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE, (Uint32) 0);
    }
    if(agingPeriod == (Uint32)ALE_AGT_PRESACLE_1000)
    {
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE, (Uint32) 1);
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE, (Uint32) 0);
    }
    else
    {
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE, (Uint32) 1);
        CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE, (Uint32) 1);
    }
    
    CSL_FINS (hCpswAleRegs->AGING_TIMER_REG, ALE_AGING_TIMER_REG_AGING_TIMER, agingPeriod);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleUnkownVlanReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE Unknown VLAN and etc registers.
 *
 *   @b Arguments
     @verbatim
        pUnVlanMemList          Unknown VLAN member list.
        pUnMcastFloodMask       Unknown VLAN Multicast flood mask.
        pUnRegMcastFloodMask    Unknown VLAN Registered Multicast Flood mask.
        pUnForceUntagEgress     Unknown VLAN Force Untagged Egress.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_UNKNOWN_VLAN_REG_UNKNOWN_LIST,       
 *      ALE_UNKNOWN_MCAST_FLOOD_REG_MASK,
 *      ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK,
 *      ALE_FORCE_UNTAGGED_EGRESS_REG_MASK
 *
 *   @b Example
 *   @verbatim
        Uint32      unVlanMemList, unMcastFloodMask, unRegMcastFloodMask, unForceUntagEgress;
 
        CSL_CPSW_getAleUnkownVlanReg (&unVlanMemList, 
                                      &unMcastFloodMask,
                                      &unRegMcastFloodMask,
                                      &unForceUntagEgress);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleUnkownVlanReg
(
    Uint32*                        pUnVlanMemList,
    Uint32*                        pUnMcastFloodMask,
    Uint32*                        pUnRegMcastFloodMask,
    Uint32*                        pUnForceUntagEgress
)
{
    *pUnVlanMemList         =   CSL_FEXT(hCpswAleRegs->UNKNOWN_VLAN_REG, ALE_UNKNOWN_VLAN_REG_LIST);
    *pUnMcastFloodMask      =   CSL_FEXT(hCpswAleRegs->UNKNOWN_MCAST_FLOOD_REG, ALE_UNKNOWN_MCAST_FLOOD_REG_MASK);
    *pUnRegMcastFloodMask   =   CSL_FEXT(hCpswAleRegs->UNKNOWN_REG_MCAST_FLOOD_REG, ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK);
    *pUnForceUntagEgress    =   CSL_FEXT(hCpswAleRegs->FORCE_UNTAGGED_EGRESS_REG, ALE_FORCE_UNTAGGED_EGRESS_REG_MASK);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleUnkownVlanReg
 *
 *   @b Description
 *   @n This function sets up the contents of the ALE Unknown VLAN and etc. register.
 *
 *   @b Arguments
     @verbatim
        unVlanMemList           Unknown VLAN member list.
        unMcastFloodMask        Unknown VLAN Multicast flood mask.
        unRegMcastFloodMask     Unknown VLAN Registered Multicast Flood mask.
        unForceUntagEgress      Unknown VLAN Force Untagged Egress.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_UNKNOWN_VLAN_REG_UNKNOWN_LIST,
 *      ALE_UNKNOWN_MCAST_FLOOD_REG_MASK,
 *      ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK,
 *      ALE_FORCE_UNTAGGED_EGRESS_REG_MASK
 *
 *   @b Example
 *   @verbatim
        Uint32      unVlanMemList, unMcastFloodMask, unRegMcastFloodMask, unForceUntagEgress;

        unVlanMemList           =   0;
        unMcastFloodMask        =   3;
        unRegMcastFloodMask     =   0;
        unForceUntagEgress      =   0;
 
        CSL_CPSW_setAleUnkownVlanReg (unVlanMemList, 
                                      unMcastFloodMask,
                                      unRegMcastFloodMask,
                                      unForceUntagEgress);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleUnkownVlanReg
(
    Uint32                      unVlanMemList,
    Uint32                      unMcastFloodMask,
    Uint32                      unRegMcastFloodMask,
    Uint32                      unForceUntagEgress
)
{
    CSL_FINS (hCpswAleRegs->UNKNOWN_VLAN_REG, ALE_UNKNOWN_VLAN_REG_LIST, unVlanMemList);
    CSL_FINS (hCpswAleRegs->UNKNOWN_MCAST_FLOOD_REG, ALE_UNKNOWN_MCAST_FLOOD_REG_MASK, unMcastFloodMask);
    CSL_FINS (hCpswAleRegs->UNKNOWN_REG_MCAST_FLOOD_REG, ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK, unRegMcastFloodMask);
    CSL_FINS (hCpswAleRegs->FORCE_UNTAGGED_EGRESS_REG, ALE_FORCE_UNTAGGED_EGRESS_REG_MASK, unForceUntagEgress);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanMaskMuxReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the ALE VLAN Mask Mux registers.
 *
 *   @b Arguments
     @verbatim
        vlanMaskMux             Array of VLAN Mask Mux which is indexed by
                                the unreg_mcast_flood_index and reg_mcast_flood_
                                index values from the VLAN table entry to determine 
                                the registered and unregistered multicast flood masks                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_VLAN_MASK_MUX_REG_MASK
 *
 *   @b Example
 *   @verbatim
        Uint32      vlanMaskMux[4];
 
        CSL_CPSW_getAleVlanMaskMuxReg (vlanMaskMux); 
	 
     @endverbatim
 *
 * @note: The value of VLAN_Mask_MUX_0 is read only and all ones (all ports are one).  
 * =============================================================================
 */
static inline void CSL_CPSW_getAleVlanMaskMuxReg
(
    Uint32*                        vlanMaskMux
)
{
    int i;
    
    for(i = 0; i < 4; i++)
        vlanMaskMux[i] =  CSL_FEXT(hCpswAleRegs->VLAN_MASK_MUX_REG[i], ALE_UNKNOWN_VLAN_REG_LIST);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanMaskMuxReg
 *
 *   @b Description
 *   @n This function sets up the contents of the ALE VLAN Mask Mux registers.
 *
 *   @b Arguments
     @verbatim
        vlanMaskMux             Array of VLAN Mask Mux which is indexed by
                                the unreg_mcast_flood_index and reg_mcast_flood_
                                index values from the VLAN table entry to determine 
                                the registered and unregistered multicast flood masks                                
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_VLAN_MASK_MUX_REG_MASK
 *
 *   @b Example
 *   @verbatim
        Uint32      vlanMaskMux[4];
        
        vlanMaskMux[0] = 0x3;
        vlanMaskMux[1] = 0;
        ...
 
        CSL_CPSW_setAleVlanMaskMuxReg (vlanMaskMux); 
	 
     @endverbatim
 * @note: The value of VLAN_Mask_MUX_0 is read only and all ones (all ports are one).  
 * =============================================================================
 */
static inline void CSL_CPSW_setAleVlanMaskMuxReg
(
    Uint32*                        vlanMaskMux
)
{
    int i;
    
    for(i = 1; i < 4; i++)
        CSL_FINS (hCpswAleRegs->VLAN_MASK_MUX_REG[i], ALE_VLAN_MASK_MUX_REG_MASK, vlanMaskMux[i]);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleTableEntry
 *
 *   @b Description
 *   @n This function retrieves an ALE table entry corresponding to the 
 *      ALE entry index specified in 'index' input parameter. The ALE
 *      entry values corresponding to the ALE_TBLW0, ALE_TBLW1 and
 *      ALE_TBLW2 registers are returned in 'pAleInfoWd0', 'pAleInfoWd1', 'pAleInfoWd2'
 *      output parameters.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pAleInfoWd0             Contents of ALE Table Word 0 Register (ALE_TBLW0).
        pAleInfoWd1             Contents of ALE Table Word 1 Register (ALE_TBLW1).
        pAleInfoWd2             Contents of ALE Table Word 2 Register (ALE_TBLW2).
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0_REG_ENTRY_31_0,
 *      ALE_TABLE_WORD1_REG_ENTRY_63_32,
 *      ALE_TABLE_WORD2_REG_ENTRY_71_64
 *
 *   @b Example
 *   @verbatim
        Uint32      index, info0, info1, info2;

        index   =   0;
 
        CSL_CPSW_getAleTableEntry (index, 
                                   &info0,
                                   &info1,
                                   &info2);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleTableEntry
(
    Uint32                      index,
    Uint32*                     pAleInfoWd0,
    Uint32*                     pAleInfoWd1,
    Uint32*                     pAleInfoWd2
)
{
    Uint32                      aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;

    /* Read the ALE table word registers */
    *pAleInfoWd0            =   CSL_FEXT(hCpswAleRegs->TABLE_WORD0_REG, ALE_TABLE_WORD0_REG_ENTRY_31_0);
    *pAleInfoWd1            =   CSL_FEXT(hCpswAleRegs->TABLE_WORD1_REG, ALE_TABLE_WORD1_REG_ENTRY_63_32);
    *pAleInfoWd2            =   CSL_FEXT(hCpswAleRegs->TABLE_WORD2_REG, ALE_TABLE_WORD2_REG_ENTRY_71_64);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleTableEntry
 *
 *   @b Description
 *   @n This function sets up an ALE table entry corresponding to the 
 *      ALE entry index specified in 'index' input parameter. The ALE
 *      entry values corresponding to the ALE_TBLW0, ALE_TBLW1 and
 *      ALE_TBLW2 registers msut be specified in 'aleInfoWd0', 'aleInfoWd1', 'aleInfoWd2'
 *      input parameters.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be written.
        aleInfoWd0              Value to write to ALE Table Word 0 Register (ALE_TBLW0).
        aleInfoWd1              Value to write to ALE Table Word 1 Register (ALE_TBLW1).
        aleInfoWd2              Value to write to ALE Table Word 2 Register (ALE_TBLW2).
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_WORD0_REG_ENTRY_31_0,
 *      ALE_TABLE_WORD1_REG_ENTRY_63_32,
 *      ALE_TABLE_WORD2_REG_ENTRY_71_64,
 *      ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      
 *
 *   @b Example
 *   @verbatim
        Uint32      index, info0, info1, info2;

        index   =   0;
        info0   =   ...;
        info1   =   ...;
        info2   =   ...;
 
        CSL_CPSW_setAleTableEntry (index, 
                                          info0,
                                          info1,
                                          info2);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleTableEntry
(
    Uint32                      index,
    Uint32                      aleInfoWd0,
    Uint32                      aleInfoWd1,
    Uint32                      aleInfoWd2
)
{
    Uint32                      aleTblCtrlVal   =   0;

    /* Set the ALE table word registers */
    CSL_FINS (hCpswAleRegs->TABLE_WORD0_REG, ALE_TABLE_WORD0_REG_ENTRY_31_0, aleInfoWd0);
    CSL_FINS (hCpswAleRegs->TABLE_WORD1_REG, ALE_TABLE_WORD1_REG_ENTRY_63_32, aleInfoWd1);
    CSL_FINS (hCpswAleRegs->TABLE_WORD2_REG, ALE_TABLE_WORD2_REG_ENTRY_71_64, aleInfoWd2);

    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getALEEntryType
 *
 *   @b Description
 *   @n This function returns the ALE entry type for any given ALE table
 *      entry index.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>  CSL_CPSW_ALE_ENTRYTYPE
 *	 @n	 ALE_ENTRYTYPE_FREE             ALE entry is free.
 *	 @n  ALE_ENTRYTYPE_ADDRESS          ALE entry contains a unicast/multicast address.
 *	 @n  ALE_ENTRYTYPE_VLAN             ALE entry contains a VLAN.
 *	 @n  ALE_ENTRYTYPE_VLANADDRESS      ALE entry contains a VLAN and a unicast/multicast address. 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD1_REG
 *
 *   @b Example
 *   @verbatim
 *      Uint32      index = 0;
        if (CSL_CPSW_getALEEntryType () == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry free
        }
	 @endverbatim
 * =============================================================================
 */
static inline CSL_CPSW_ALE_ENTRYTYPE CSL_CPSW_getALEEntryType 
(
    Uint32                      index
)
{
    Uint32                      aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;

    return (CSL_CPSW_ALE_ENTRYTYPE) CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getALEAddressType
 *
 *   @b Description
 *   @n This function returns the address type of an ALE entry.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>  CSL_CPSW_ALE_ADDRTYPE
 *	 @n	 ALE_ADDRTYPE_UCAST         Address at this entry is unicast
 *	 @n  ALE_ADDRTYPE_MCAST         Address at this entry is multicast 
 *	 @n  ALE_ADDRTYPE_OUI           Address at this entry is OUI address
 *
 *   <b> Pre Condition </b>
 *   @n  This function must be called only for an ALE address entry, i.e., 
 *       if @a CSL_XGE_CPSW_getALEEntryType () returns ALE_ENTRYTYPE_ADDRESS
 *       or ALE_ENTRYTYPE_VLANADDRESS only.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0_REG,
 *      ALE_TABLE_WORD1_REG
 *
 *   @b Example
 *   @verbatim
 *      Uint32      index = 0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_ADDRESS)
        {
            // ALE entry has an address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_UCAST)
            {
                // Unicast address
            }
        }
        else
        {
            // Do nothing
        }

        ...
	 @endverbatim
 * =============================================================================
 */
static inline CSL_CPSW_ALE_ADDRTYPE CSL_CPSW_getALEAddressType 
(
    Uint32                      index
)
{
    Uint32                      aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;

    if (CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 23, 0) == 0)            
    {
        /* Lower 24 bits of Word 0 are all zeros for an OUI address */            
        return  ALE_ADDRTYPE_OUI;             
    }

    if (hCpswAleRegs->TABLE_WORD1_REG & (1 << 8))            
    {
        /* 40th bit of MAC address is 1 for a multicast address. */
        return  ALE_ADDRTYPE_MCAST;
    }
    else
    {
        return  ALE_ADDRTYPE_UCAST;
    }
}

/** ============================================================================
 *   @n@b CSL_CPSW_getALEPolicerEntryType
 *
 *   @b Description
 *   @n This function returns the entry type of an ALE Policer entry.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>  CSL_CPSW_ALE_POLICER_ENTRYTYPE
 *	 @n	 ALE_POLICER_ENTRYTYPE_VLAN         (Inner) VLAN Entry
 *	 @n  ALE_POLICER_ENTRYTYPE_OVLAN        Outer VLAN entry 
 *	 @n  ALE_POLICER_ENTRYTYPE_ETHERTYPEI   Ether Type entry
 *   @n  ALE_POLICER_ENTRYTYPE_IPV4         IPv4 Address entry
 *   @n  ALE_POLICER_ENTRYTYPE_IPV6         IPv6 Address entry
 *
 *   <b> Pre Condition </b>
 *   @n  This function must be called only for an ALE address entry, i.e., 
 *       if @a CSL_XGE_CPSW_getALEEntryType () returns ALE_ENTRYTYPE_POLICER.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD1_REG,
 *      ALE_TABLE_WORD2_REG
 *
 *   @b Example
 *   @verbatim
 *      Uint32      index = 0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_POLICER)
        {
            // ALE entry has an address

            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_IPV4)
            {
                // IPv4 address
            }
            
        }
        else
        {
            // Do nothing
        }

        ...
	 @endverbatim
 * =============================================================================
 */
static inline CSL_CPSW_ALE_POLICER_ENTRYTYPE CSL_CPSW_getALEPolicerEntryType 
(
    Uint32                      index
)
{
    Uint32                      aleTblCtrlVal   =   0;
    Uint32                      entryType;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;
    
    entryType = (CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0) << 2) +
                 CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 31, 30);
                 
    if(entryType & 1)
    {
        return(ALE_POLICER_ENTRYTYPE_IPV6);
    }
    else
    {
        return((CSL_CPSW_ALE_POLICER_ENTRYTYPE)(entryType >> 1));
    }             
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleMcastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Multicast address configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pMcastAddrCfg           ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                     index;
        CSL_ALE_MCASTADDR_ENTRY    mcastAddrCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_ADDRESS)
        {
            // ALE entry has an address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_MCAST)
            {
                // Read Multicast address config from hardware
                CSL_CPSW_getAleMcastAddrEntry (index, &mcastAddrCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleMcastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_MCASTADDR_ENTRY*       pMcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pMcastAddrCfg->macAddress[0]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8);
    pMcastAddrCfg->macAddress[1]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0);
    pMcastAddrCfg->macAddress[2]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24);
    pMcastAddrCfg->macAddress[3]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16);
    pMcastAddrCfg->macAddress[4]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8);
    pMcastAddrCfg->macAddress[5]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0);
    pMcastAddrCfg->mcastFwdState        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30);    
    pMcastAddrCfg->superEnable          =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1);
    pMcastAddrCfg->portMask             =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleMcastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      Multicast address configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pMcastAddrCfg           ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                              index;
        CSL_CPSW_ALE_MCASTADDR_ENTRY    mcastAddrCfg;

        index   =   0;
        mcastAddrCfg.macAddress [0] = 0x00;
        mcastAddrCfg.macAddress [1] = 0x01;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add Multicast address entry
            CSL_CPSW_setAleMcastAddrEntry (index, &mcastAddrCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleMcastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_MCASTADDR_ENTRY*       pMcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the multicast address configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8, pMcastAddrCfg->macAddress[0]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0, pMcastAddrCfg->macAddress[1]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24, pMcastAddrCfg->macAddress[2]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16, pMcastAddrCfg->macAddress[3]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8, pMcastAddrCfg->macAddress[4]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0, pMcastAddrCfg->macAddress[5]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30, pMcastAddrCfg->mcastFwdState);    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1, pMcastAddrCfg->superEnable);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2, pMcastAddrCfg->portMask);

    /* set entry type to address entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 1);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanMcastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN Multicast address configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pVlanMcastAddrCfg       ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLANMCASTADDR_ENTRY    vlanMcastAddrCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_VLANADDRESS)
        {
            // ALE entry has a VLAN address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_MCAST)
            {
                // Read VLAN Multicast address config from hardware
                CSL_CPSW_getAleVlanMcastAddrEntry (index, &vlanMcastAddrCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleVlanMcastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLANMCASTADDR_ENTRY*   pVlanMcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pVlanMcastAddrCfg->macAddress[0]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8);
    pVlanMcastAddrCfg->macAddress[1]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0);
    pVlanMcastAddrCfg->macAddress[2]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24);
    pVlanMcastAddrCfg->macAddress[3]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16);
    pVlanMcastAddrCfg->macAddress[4]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8);
    pVlanMcastAddrCfg->macAddress[5]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0);
    pVlanMcastAddrCfg->vlanId               =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16);
    pVlanMcastAddrCfg->mcastFwdState        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30);    
    pVlanMcastAddrCfg->superEnable          =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1);
    pVlanMcastAddrCfg->portMask             =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanMcastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      VLAN Multicast address configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pVlanMcastAddrCfg       ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLANMCASTADDR_ENTRY    vlanMcastAddrCfg;

        index   =   0;
        vlanMcastAddrCfg.macAddress [0] = 0x00;
        vlanMcastAddrCfg.macAddress [1] = 0x01;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add VLAN Multicast address entry
            CSL_CPSW_setAleVlanMcastAddrEntry (index, &vlanMcastAddrCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleVlanMcastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLANMCASTADDR_ENTRY*   pVlanMcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the VLAN multicast address configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8, pVlanMcastAddrCfg->macAddress[0]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0, pVlanMcastAddrCfg->macAddress[1]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24, pVlanMcastAddrCfg->macAddress[2]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16, pVlanMcastAddrCfg->macAddress[3]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8, pVlanMcastAddrCfg->macAddress[4]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0, pVlanMcastAddrCfg->macAddress[5]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16, pVlanMcastAddrCfg->vlanId);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30, pVlanMcastAddrCfg->mcastFwdState);    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1, pVlanMcastAddrCfg->superEnable);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2, pVlanMcastAddrCfg->portMask);
    
    /* set entry type to VLAN address entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 3);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleUnicastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Unicast address configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pUcastAddrCfg           ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_UNICASTADDR_ENTRY      ucastAddrCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_ADDRESS)
        {
            // ALE entry has an address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_UCAST)
            {
                // Read Unicast address config from hardware
                CSL_CPSW_getAleUnicastAddrEntry (index, &ucastAddrCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleUnicastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_UNICASTADDR_ENTRY*     pUcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pUcastAddrCfg->macAddress[0]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8);
    pUcastAddrCfg->macAddress[1]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0);
    pUcastAddrCfg->macAddress[2]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24);
    pUcastAddrCfg->macAddress[3]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16);
    pUcastAddrCfg->macAddress[4]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8);
    pUcastAddrCfg->macAddress[5]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0);
    pUcastAddrCfg->ucastType            =   (CSL_CPSW_ALE_UCASTTYPE) CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30);
    pUcastAddrCfg->secureEnable         =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0);    
    pUcastAddrCfg->blockEnable          =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1);
    pUcastAddrCfg->portNumber           =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleUnicastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      unicast address configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pUcastAddrCfg           ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_UNICASTADDR_ENTRY      ucastAddrCfg;

        index   =   0;
        ucastAddrCfg.macAddress [0] = 0x00;
        ucastAddrCfg.macAddress [1] = 0x01;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add Unicast address entry
            CSL_CPSW_setAleUnicastAddrEntry (index, &ucastAddrCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleUnicastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_UNICASTADDR_ENTRY*     pUcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the Unicast address configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8, pUcastAddrCfg->macAddress[0]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0, pUcastAddrCfg->macAddress[1]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24, pUcastAddrCfg->macAddress[2]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16, pUcastAddrCfg->macAddress[3]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8, pUcastAddrCfg->macAddress[4]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0, pUcastAddrCfg->macAddress[5]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30, pUcastAddrCfg->ucastType);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0, pUcastAddrCfg->secureEnable);    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1, pUcastAddrCfg->blockEnable);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2, pUcastAddrCfg->portNumber);
    
    /* set entry type to address entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 1);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleOUIAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with OUI address configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pOUIAddrCfg             ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_OUIADDR_ENTRY          ouiAddrCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_ADDRESS)
        {
            // ALE entry has an address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_OUI)
            {
                // Read Unicast address config from hardware
                CSL_CPSW_getAleOUIAddrEntry (index, &ouiAddrCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleOUIAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_OUIADDR_ENTRY*         pOUIAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pOUIAddrCfg->ouiAddress[0]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8);
    pOUIAddrCfg->ouiAddress[1]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0);
    pOUIAddrCfg->ouiAddress[2]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24);
    pOUIAddrCfg->ucastType            =   (CSL_CPSW_ALE_UCASTTYPE) CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleOUIAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      OUI address configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pOUIAddrCfg             ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_OUIADDR_ENTRY          ouiAddrCfg;

        index   =   0;
        ouiAddrCfg.ouiAddress [0] = 0x00;
        ouiAddrCfg.ouiAddress [1] = 0x01;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add OUI address entry
            CSL_CPSW_setAleOUIAddrEntry (index, &ouiAddrCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleOUIAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_OUIADDR_ENTRY*         pOUIAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the Unicast address configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8, pOUIAddrCfg->ouiAddress[0]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0, pOUIAddrCfg->ouiAddress[1]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24, pOUIAddrCfg->ouiAddress[2]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30, pOUIAddrCfg->ucastType);
    
    /* set entry type to address entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 1);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanUnicastAddrEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN Unicast address configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pVlanUcastAddrCfg       ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY  vlanUcastAddrCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_VLANADDRESS)
        {
            // ALE entry has a VLAN address

            if (CSL_CPSW_getALEAddressType (index) ==  ALE_ADDRTYPE_UCAST)
            {
                // Read VLAN Unicast address config from hardware
                CSL_CPSW_getAleVlanUnicastAddrEntry (index, &ucvlanUcastAddrCfgastAddrCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleVlanUnicastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY* pVlanUcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pVlanUcastAddrCfg->macAddress[0]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8);
    pVlanUcastAddrCfg->macAddress[1]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0);
    pVlanUcastAddrCfg->macAddress[2]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24);
    pVlanUcastAddrCfg->macAddress[3]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16);
    pVlanUcastAddrCfg->macAddress[4]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8);
    pVlanUcastAddrCfg->macAddress[5]        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0);
    pVlanUcastAddrCfg->vlanId               =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16);
    pVlanUcastAddrCfg->ucastType            =   (CSL_CPSW_ALE_UCASTTYPE) CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30);
    pVlanUcastAddrCfg->secureEnable         =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0);    
    pVlanUcastAddrCfg->blockEnable          =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1);
    pVlanUcastAddrCfg->portNumber           =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanUnicastAddrEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      VLAN unicast address configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pVlanUcastAddrCfg       ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY  vlanUcastAddrCfg;

        index   =   0;
        vlanUcastAddrCfg.macAddress [0] = 0x00;
        vlanUcastAddrCfg.macAddress [1] = 0x01;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add VLAN Unicast address entry
            CSL_CPSW_setAleVlanUnicastAddrEntry (index, &vlanUcastAddrCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleVlanUnicastAddrEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY* pVlanUcastAddrCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the VLAN Unicast address configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 15, 8, pVlanUcastAddrCfg->macAddress[0]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 7, 0, pVlanUcastAddrCfg->macAddress[1]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 24, pVlanUcastAddrCfg->macAddress[2]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 23, 16, pVlanUcastAddrCfg->macAddress[3]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 15, 8, pVlanUcastAddrCfg->macAddress[4]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 7, 0, pVlanUcastAddrCfg->macAddress[5]);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16, pVlanUcastAddrCfg->vlanId);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 30, pVlanUcastAddrCfg->ucastType);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0, pVlanUcastAddrCfg->secureEnable);    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 1, 1, pVlanUcastAddrCfg->blockEnable);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 5, 2, pVlanUcastAddrCfg->portNumber);
    
    /* set entry type to address entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 3);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleVlanEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with VLAN configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pVlanCfg                ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLAN_ENTRY             vlanCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_VLAN)
        {
            // ALE entry has a VLAN configuration
            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_VLAN)
            {
                // Read (Inner) VLAN config from hardware
                CSL_CPSW_getAleVlanEntry (index, &vlanCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleVlanEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLAN_ENTRY*            pVlanCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the multicast address configuration */
    pVlanCfg->vlanMemList                   =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 2, 0);
    pVlanCfg->unRegMcastFloodMask           =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 10, 8);
    pVlanCfg->regMcastFloodMask             =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 18, 16);
    pVlanCfg->forceUntaggedEgress           =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 26, 24);
    pVlanCfg->vlanId                        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleVlanEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      VLAN configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pVlanCfg                ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_VLAN_ENTRY             vlanCfg;

        index   =   0;
        vlanCfg.vlanId  = 0x10;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add VLAN entry
            CSL_CPSW_setAleVlanEntry (index, &vlanCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleVlanEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_VLAN_ENTRY*            pVlanCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the (Inner) VLAN configuration */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 2, 0, pVlanCfg->vlanMemList);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 10, 8, pVlanCfg->unRegMcastFloodMask);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 18, 16, pVlanCfg->regMcastFloodMask);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 26, 24, pVlanCfg->forceUntaggedEgress);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16, pVlanCfg->vlanId);
    
    /* set entry type to VLAN entry */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 29, 28, 2);
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleOutValnEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Outer VLAN configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pOutValnCfg             ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD1
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_OUTER_VLAN_ENTRY           outVlanCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_POLICER)
        {
            // ALE entry has a plicer entry
            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_OVLAN)
            {
                // Read outer VALN config from hardware
                CSL_CPSW_getAleOutValnEntry (index, &outVlanCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleOutValnEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_OUTER_VLAN_ENTRY*      pOutValnCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the outer valn configuration */
    pOutValnCfg->vlanId        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleOutValnEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      Outer VLAN configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pOutValnCfg             ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_OUTER_VLAN_ENTRY           outVlanCfg;

        index   =   0;
        outVlanCfg.vlanId = 0x0123;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add Outer VLAN entry
            CSL_CPSW_setAleOutValnEntry (index, &outVlanCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleOutValnEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_OUTER_VLAN_ENTRY*      pOutValnCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the Outer VLAN configuration */
    hCpswAleRegs->TABLE_WORD0_REG = 0;
    hCpswAleRegs->TABLE_WORD1_REG = 0;
    hCpswAleRegs->TABLE_WORD2_REG = 0;
    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 27, 16, pOutValnCfg->vlanId);
    
    /* set entry type (10) to address entry */
    /* set policer type (010) */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 28, 0x22);  
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleEthertypeEntry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Ethertype configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pEthertypeCfg           ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_ETHERTYPE_ENTRY            ethertypeCfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_POLICER)
        {
            // ALE entry has a plicer entry
            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_ETHERTYPE)
            {
                // Read Ethertype config from hardware
                CSL_CPSW_getAleEthertypeEntry (index, &ethertypeCfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleEthertypeEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_ETHERTYPE_ENTRY*       pEthertypeCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the Ethertype configuration */
    pEthertypeCfg->ethertype        =   CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 15, 0);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleEthertypeEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      Ethertype configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pEthertypeCfg           ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_ETHERTYPE_ENTRY            ethertypeCfg;

        index   =   0;
        ethertypeCfg.ethertype = 0x0800;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add Ethertype entry
            CSL_CPSW_setAleEthertypeEntry (index, &ethertypeCfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleEthertypeEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_ETHERTYPE_ENTRY*       pEthertypeCfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Setup the Ethertype configuration */
    hCpswAleRegs->TABLE_WORD0_REG = 0;
    hCpswAleRegs->TABLE_WORD1_REG = 0;
    hCpswAleRegs->TABLE_WORD2_REG = 0;
    
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 15, 0, pEthertypeCfg->ethertype);
    
    /* set entry type (10) to address entry */
    /* set policer type (100) */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 28, 0x02);  
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0, 1);  
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleIPv4Entry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with IPv4 configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pIPv4Cfg                ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_IPv4_ENTRY                 ipv4Cfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_POLICER)
        {
            // ALE entry has a plicer entry
            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_IPV4)
            {
                // Read IPv4 config from hardware
                CSL_CPSW_getAleIPv4Entry (index, &ipv4Cfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleIPv4Entry
(
    Uint32                              index,
    CSL_CPSW_ALE_IPv4_ENTRY*            pIPv4Cfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;
    Uint32                                  address;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the IPv4 configuration */
    address = hCpswAleRegs->TABLE_WORD0_REG;
    pIPv4Cfg->address[0]          =   CSL_FEXTR (address, 31, 24);
    pIPv4Cfg->address[1]          =   CSL_FEXTR (address, 23, 16);
    pIPv4Cfg->address[2]          =   CSL_FEXTR (address, 15, 8);
    pIPv4Cfg->address[3]          =   CSL_FEXTR (address, 7, 0);
                
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleIPv4Entry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      IPv4 configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pIPv4Cfg                ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_IPv4_ENTRY                 ipv4Cfg;

        index   =   0;
        ipv4Cfg.ethertype = 0x0800;
        ...
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE)
        {
            // ALE entry is free

            // Add IPv4 entry
            CSL_CPSW_setAleIPv4Entry (index, &ipv4Cfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleIPv4Entry
(
    Uint32                              index,
    CSL_CPSW_ALE_IPv4_ENTRY*            pIPv4Cfg
)
{
    Uint32                                  aleTblCtrlVal   =   0;
    Uint32                                  address; 
    /* Setup the IPv4 configuration */
    address = (pIPv4Cfg->address[0] << 24) |
              (pIPv4Cfg->address[1] << 16) |
              (pIPv4Cfg->address[2] << 8)  |
              (pIPv4Cfg->address[3] << 0); 
    
    
    hCpswAleRegs->TABLE_WORD0_REG = address;
    hCpswAleRegs->TABLE_WORD1_REG = 0;
    hCpswAleRegs->TABLE_WORD2_REG = 0;
    
    /* set entry type (10) to address entry */
    /* set policer type (110) */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 28, 0x22);  
    CSL_FINSR (hCpswAleRegs->TABLE_WORD2_REG, 0, 0, 1);  
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAleIPv6Entry
 *
 *   @b Description
 *   @n This function reads the ALE table entry for the index specified and
 *      fills the output parameter structure with Ipv6 configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index to be read.
        pIPv6Cfg                ALE entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=0
 *
 *   @b Reads
 *   @n ALE_TABLE_WORD0
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_IPv6_ENTRY                 ipv6Cfg;

        index   =   0;
 
        if (CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_POLICER)
        {
            // ALE entry has a plicer entry
            if (CSL_CPSW_getALEPolicerEntryType (index) ==  ALE_POLICER_ENTRYTYPE_IPV6)
            {
                // Read Ipv6 config from hardware
                CSL_CPSW_getAleIPv6Entry (index, &ipv6Cfg);
            }
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAleIPv6Entry
(
    Uint32                              index,
    CSL_CPSW_ALE_IPv6_ENTRY*            pIPv6Cfg
)
{
    Uint32      aleTblCtrlVal   =   0;
    Uint32      address[4];
    int         i;                   

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;

    /* Read the IPv6 configuration */
    address[0] = (CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 0) << 4) +
                 (CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 31, 28) >> 28);  
    address[1] = (CSL_FEXTR (hCpswAleRegs->TABLE_WORD0_REG, 27, 0) << 4);
    
    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal  =  CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index+1) |
                      CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, 0);

    hCpswAleRegs->TABLE_CONTROL_REG =   aleTblCtrlVal;
    address[1] += (CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 6, 3) >> 3);
    address[2] =  (CSL_FEXTR (hCpswAleRegs->TABLE_WORD2_REG, 2, 0) << 29)   +
                  (CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 31, 31) << 28) +
                  (CSL_FEXTR (hCpswAleRegs->TABLE_WORD1_REG, 27, 0));
    address[3] = hCpswAleRegs->TABLE_WORD0_REG;          
    
    for(i = 0; i < 4; i++)    
    {
        pIPv6Cfg->address[4*i]         =   CSL_FEXTR (address[i], 31, 24);
        pIPv6Cfg->address[4*i+1]       =   CSL_FEXTR (address[i], 23, 16);
        pIPv6Cfg->address[4*i+2]       =   CSL_FEXTR (address[i], 15, 8);
        pIPv6Cfg->address[4*i+3]       =   CSL_FEXTR (address[i], 7, 0);
    }
        
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAleIPv6Entry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      IPv6 configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pIPv6Cfg                ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0,
 *      ALE_TABLE_WORD1,
 *      ALE_TABLE_WORD2
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_IPv6_ENTRY                 ipv4Cfg;

        index   =   0;
        ipv4Cfg.ethertype = 0x0800;
        ...
 
        if ((CSL_CPSW_getALEEntryType (index) == ALE_ENTRYTYPE_FREE &&
            (CSL_CPSW_getALEEntryType (index+1) == ALE_ENTRYTYPE_FREE))
        {
            // ALE entry is free

            // Add IPv6 entry
            CSL_CPSW_setAleIPv6Entry (index, &ipv4Cfg);
        }
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAleIPv6Entry
(
    Uint32                              index,
    CSL_CPSW_ALE_IPv6_ENTRY*            pIPv6Cfg
)
{
    Uint32          aleTblCtrlVal   =   0;
    Uint32          address[4]; 
    int             i;
    
    /* Setup the IPv6 configuration */
    for(i = 0; i < 4; i++)    
    {
        address[i] = (pIPv6Cfg->address[4*i]   << 24) |
                     (pIPv6Cfg->address[4*i+1] << 16) |
                     (pIPv6Cfg->address[4*i+2] << 8)  |
                     (pIPv6Cfg->address[4*i+3] << 0); 
    }
    
    /* Update the first record */
    hCpswAleRegs->TABLE_WORD0_REG = address[1] >> 4;
    CSL_FINSR (hCpswAleRegs->TABLE_WORD0_REG, 31, 28, (address[0] & 0x0F));  
    hCpswAleRegs->TABLE_WORD1_REG = address[0] >> 4;
    hCpswAleRegs->TABLE_WORD2_REG = 0;
    
    /* set entry type (10) to address entry */
    /* set policer type (xx1) */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 30, 28, 0x12);  
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;   
    
    /* Update the second record */
    hCpswAleRegs->TABLE_WORD0_REG = address[3];
    hCpswAleRegs->TABLE_WORD1_REG = address[2] & 0x0FFFFFFFF;
    hCpswAleRegs->TABLE_WORD2_REG = ((address[1] & 0x0F) << 3) + 
                                    (address[2] >> 29);
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 31, 31, ((address[2] >> 28) & 0x01));  
    
    /* set entry type (10) to address entry */
    /* set policer type (xx1) */
    CSL_FINSR (hCpswAleRegs->TABLE_WORD1_REG, 30, 28, 0x12);  
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index+1) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    
     

    return;
}


/** ============================================================================
 *   @n@b CSL_CPSW_clearAleEntry
 *
 *   @b Description
 *   @n This function clears the ALE entry corresponding to the index 
 *      specified
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_TABLE_CONTROL_REG_ENTRY_POINTER,
 *      ALE_TABLE_CONTROL_REG_WRITE_RDZ=1
 *      ALE_TABLE_WORD0=0,
 *      ALE_TABLE_WORD1=0,
 *      ALE_TABLE_WORD2=0
 *
 *   @b Example
 *   @verbatim
        Uint32                              index;

        index   =   0;

        CSL_CPSW_clearAleEntry (index);
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_clearAleEntry
(
    Uint32                                  index
)
{
    Uint32                                  aleTblCtrlVal   =   0;

    /* Clear all the ALE words */
    hCpswAleRegs->TABLE_WORD0_REG   =   0;
    hCpswAleRegs->TABLE_WORD1_REG   =   0;
    hCpswAleRegs->TABLE_WORD2_REG   =   0;
    
    /* Set the index in the ALE table to "write" operation and let
     * the hardware set up the ALE table entry corresponding to index
     * specified.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_TABLE_CONTROL_REG_ENTRY_POINTER, index) |
                                CSL_FMK (ALE_TABLE_CONTROL_REG_WRITE_RDZ, (Uint32) 1);

    hCpswAleRegs->TABLE_CONTROL_REG    =   aleTblCtrlVal;    

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAlePortControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of ALE Port control register
 *      corresponding to the port number specified.
 *
 *   @b Arguments
     @verbatim
        portNo                  Port number for which the ALE port control register
                                must be read.
        pPortControlInfo        CSL_CPSW_ALE_PORTCONTROL structure that needs to be 
                                filled with Port control register info read from
                                the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_PORT_CONTROL_REG_PORT_STATE,
 *      ALE_PORT_CONTROL_REG_DROP_UNTAGGED,
 *      ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK,
 *      ALE_PORT_CONTROL_REG_NO_LEARN,
 *      ALE_PORT_CONTROL_REG_NO_SA_UPDATE,
 *      ALE_PORT_CONTROL_REG_MAC_ONLY,
 *      ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE,
 *      ALE_PORT_CONTROL_REG_MACONLY_CAF,
 *      ALE_PORT_CONTROL_REG_MCAST_LIMIT,
 *      ALE_PORT_CONTROL_REG_BCAST_LIMIT
 *
 *   @b Example
 *   @verbatim
        Uint32                          index;
        CSL_CPSW_ALE_PORTCONTROL    portControlInfo;

        index   =   0;
 
        CSL_CPSW_getAlePortControlReg (index, &portControlInfo);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAlePortControlReg
(
    Uint32                      portNo,
    CSL_CPSW_ALE_PORTCONTROL*   pPortControlInfo
)
{
    pPortControlInfo->portState             =   (CSL_CPSW_ALE_PORTSTATE) CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_PORT_STATE);
    pPortControlInfo->dropUntaggedEnable    =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_DROP_UNTAGGED);
    pPortControlInfo->vidIngressCheckEnable =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK);
    pPortControlInfo->noLearnModeEnable     =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_NO_LEARN);
    pPortControlInfo->noSaUpdateEnable      =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_NO_SA_UPDATE);
    pPortControlInfo->macOnlyEnable         =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_MAC_ONLY);
    pPortControlInfo->macAuthDisable        =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE);
    pPortControlInfo->macOnlyCafEnable      =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_MACONLY_CAF);
    pPortControlInfo->mcastLimit            =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_MCAST_LIMIT);
    pPortControlInfo->bcastLimit            =   CSL_FEXT (hCpswAleRegs->PORT_CONTROL_REG [portNo], 
                                                          ALE_PORT_CONTROL_REG_BCAST_LIMIT);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAlePortControlReg
 *
 *   @b Description
 *   @n This function sets up the contents of ALE Port control register
 *      corresponding to the port number specified.
 *
 *   @b Arguments
     @verbatim
        portNo                  Port number for which the ALE port control register
                                must be configured.
        pPortControlInfo        CSL_CPSW_ALE_PORTCONTROL structure that contains 
                                port control register settings to be written.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_PORT_CONTROL_REG_PORT_STATE,
 *      ALE_PORT_CONTROL_REG_DROP_UNTAGGED,
 *      ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK,
 *      ALE_PORT_CONTROL_REG_NO_LEARN,
 *      ALE_PORT_CONTROL_REG_NO_SA_UPDATE,
 *      ALE_PORT_CONTROL_REG_MAC_ONLY,
 *      ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE,
 *      ALE_PORT_CONTROL_REG_MACONLY_CAF,
 *      ALE_PORT_CONTROL_REG_MCAST_LIMIT,
 *      ALE_PORT_CONTROL_REG_BCAST_LIMIT
 *
 *   @b Example
 *   @verbatim
        Uint32                          index;
        CSL_CPSW_ALE_PORTCONTROL    portControlInfo;

        index   =   0;
        portControlInfo.portState   =   ALE_PORTSTATE_FORWARD |
                                        ALE_PORTSTATE_LEARN;
 
        CSL_CPSW_setAlePortControlReg (index, &portControlInfo);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAlePortControlReg
(
    Uint32                      portNo,
    CSL_CPSW_ALE_PORTCONTROL*   pPortControlInfo
)
{
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_PORT_STATE,
              pPortControlInfo->portState);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_DROP_UNTAGGED,
              pPortControlInfo->dropUntaggedEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK, 
              pPortControlInfo->vidIngressCheckEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_NO_LEARN, 
              pPortControlInfo->noLearnModeEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_NO_SA_UPDATE,
              pPortControlInfo->noSaUpdateEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_MAC_ONLY,
              pPortControlInfo->macOnlyEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE,
              pPortControlInfo->macAuthDisable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_MACONLY_CAF,
              pPortControlInfo->macOnlyCafEnable);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_MCAST_LIMIT, 
              pPortControlInfo->mcastLimit);
    CSL_FINS (hCpswAleRegs->PORT_CONTROL_REG [portNo], ALE_PORT_CONTROL_REG_BCAST_LIMIT,
              pPortControlInfo->bcastLimit);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAlePolicerGlobConfig
 *
 *   @b Description
 *   @n This function retrieves the contents of the CPSW ALE Policer/Classifier
 *        Global Configuration.
 *
 *   @b Arguments
     @verbatim
        pGlobConfig             CSL_CPSW_ALE_POLICER_GLOB_CONFIG structure that needs to 
                                be populated with the contents of the corresponging ALE Policer
                                global control registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n ALE_THREAD_DEF_REG_ENABLE,
 *      ALE_THREAD_DEF_REG_VALUE
 *      
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_ALE_POLICER_GLOB_CONFIG    globConfig;

        CSL_CPSW_getAlePolicerGlobConfig (&globConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAlePolicerGlobConfig (
	CSL_CPSW_ALE_POLICER_GLOB_CONFIG*   pGlobConfig     
)
{
    pGlobConfig->defThreadEnable    =   CSL_FEXT (hCpswAleRegs->THREAD_DEF_REG, ALE_THREAD_DEF_REG_ENABLE);
    pGlobConfig->defThread          =   CSL_FEXT (hCpswAleRegs->THREAD_DEF_REG, ALE_THREAD_DEF_REG_VALUE);
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAlePolicerGlobConfig
 *
 *   @b Description
 *   @n This function sets up the contents of the CPSW ALE Policer/Classifier
 *      global registers
 *      per user-specified ALE Policer Global Configuration.
 *
 *   @b Arguments
     @verbatim
        pGlobConfig         CSL_CPSW_ALE_POLICER_GLOB_CONFIG structure that holds the values 
                            that need to be configured to the ALE Policer global control 
                            registers.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  CPSW ALE Policer Global control register modified with values provided.
 *
 *   @b Writes
 *   @n ALE_THREAD_DEF_REG_ENABLE,
 *      ALE_THREAD_DEF_REG_VALUE
 *
 *   @b Example
 *   @verbatim
        CSL_CPSW_ALE_POLICER_GLOB_CONFIG    globConfig;

        globConfig.defThreadEnable  =   1;
        ...

        CSL_CPSW_setAlePolicerGlobConfig (&globConfig);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAlePolicerGlobConfig (
	CSL_CPSW_ALE_POLICER_GLOB_CONFIG*   pGlobConfig     
)
{

    CSL_FINS (hCpswAleRegs->THREAD_DEF_REG, ALE_THREAD_DEF_REG_ENABLE, pGlobConfig->enable);
    CSL_FINS (hCpswAleRegs->THREAD_DEF_REG, ALE_THREAD_DEF_REG_VALUE, pGlobConfig->defThread);
}

/** ============================================================================
 *   @n@b CSL_CPSW_getAlePolicerEntry
 *
 *   @b Description
 *   @n This function reads the ALE Policer table entry for the index specified and
 *      fills the output parameter structure with Policer configuration
 *      read from the hardware.
 *
 *   @b Arguments
     @verbatim
        index                   ALE Policer table index to be read.
        pPolCfg                 ALE Policer entry contents read.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX
 *      ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE=0
 *      ALE_THREAD_CTL_REG_ENTRY_PTR
 *
 *   @b Reads
 *   @n ALE_POLICER_PORT_OUI_REG_PORT_MEN,
 *      ALE_POLICER_PORT_OUI_REG_PORT_NUM,
 *      ALE_POLICER_PORT_OUI_REG_PRI_MEN,
 *      ALE_POLICER_PORT_OUI_REG_PRI_VAL,
 *      ALE_POLICER_PORT_OUI_REG_ONU_MEN,
 *      ALE_POLICER_PORT_OUI_REG_ONU_INDEX,
 *      ALE_POLICER_DA_SA_REG_DST_MEN,
 *      ALE_POLICER_DA_SA_REG_DST_INDEX,
 *      ALE_POLICER_DA_SA_REG_SRC_MEN,
 *      ALE_POLICER_DA_SA_REG_SRC_INDEX,
 *      ALE_POLICER_VLAN_REG_OVLAN_MEN,
 *      ALE_POLICER_VLAN_REG_OVLAN_INDEX,
 *      ALE_POLICER_VLAN_REG_IVLAN_MEN,
 *      ALE_POLICER_VLAN_REG_IVLAN_INDEX,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX,
 *      ALE_POLICER_IPDA_REG_IPDST_MEN,
 *      ALE_POLICER_IPDA_REG_IPDST_INDEX,
 *      ALE_THREAD_VAL_REG_ENABLE,
 *      ALE_THREAD_VAL_REG_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_POLICER_ENTRY              polCfg;

        index   =   0;
 
         // Read Policer Entry config from hardware
         CSL_CPSW_getAlePolicerEntry (index, &polCfg);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_getAlePolicerEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_POLICER_ENTRY*         pPolCfg
)
{
    Uint32                                  aleTblCtrlVal, value;

    /* Set the index in the ALE table to "read" operation and let
     * the hardware load the ALE table entry corresponding to index
     * specified into the ALE table word registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX, index) |
                                CSL_FMK (ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE, (Uint32) 0);

    hCpswAleRegs->POLICER_TBL_CTL_REG    =   aleTblCtrlVal;    


    pPolCfg->validBitmap = 0;
    /* Read the Policer Entry configuration */
    value  =  hCpswAleRegs->POLICER_PORT_OUI_REG;
    
    if(CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_PORT_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_PORT_VALID;
        pPolCfg->port = CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_PORT_NUM);
    }
    
    if(CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_PRI_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_PRI_VALID;
        pPolCfg->pri = CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_PRI_VAL);
    }
    
    if(CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_OUI_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_OUI_VALID;
        pPolCfg->ouiIdx = CSL_FEXT(value, ALE_POLICER_PORT_OUI_REG_OUI_INDEX);
    }
    
    value  =  hCpswAleRegs->POLICER_DA_SA_REG;
    
    if(CSL_FEXT(value, ALE_POLICER_DA_SA_REG_DST_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_DST_MAC_VALID;
        pPolCfg->dstMacIdx = CSL_FEXT(value, ALE_POLICER_DA_SA_REG_DST_INDEX);
    }
    
    if(CSL_FEXT(value, ALE_POLICER_DA_SA_REG_SRC_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_SRC_MAC_VALID;
        pPolCfg->srcMacIdx = CSL_FEXT(value, ALE_POLICER_DA_SA_REG_SRC_INDEX);
    }
    
    value  =  hCpswAleRegs->POLICER_VLAN_REG;
    
    if(CSL_FEXT(value, ALE_POLICER_VLAN_REG_OVLAN_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_OVLAN_VALID;
        pPolCfg->ovlanIdx = CSL_FEXT(value, ALE_POLICER_VLAN_REG_OVLAN_INDEX);
    }
    
    if(CSL_FEXT(value, ALE_POLICER_VLAN_REG_IVLAN_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_VLAN_VALID;
        pPolCfg->vlanIdx = CSL_FEXT(value, ALE_POLICER_VLAN_REG_IVLAN_INDEX);
    }
    
    value  =  hCpswAleRegs->POLICER_ETHERTYPE_IPSA_REG;
    
    if(CSL_FEXT(value, ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_ETHERTYPE_VALID;
        pPolCfg->ethertypeIdx = CSL_FEXT(value, ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX);
    }
    
    if(CSL_FEXT(value, ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_SRC_IP_VALID;
        pPolCfg->srcIpIdx = CSL_FEXT(value, ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX);
    }
    
    value  =  hCpswAleRegs->POLICER_IPDA_REG;
    
    if(CSL_FEXT(value, ALE_POLICER_IPDA_REG_IPDST_MEN))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_DST_IP_VALID;
        pPolCfg->dstIpIdx = CSL_FEXT(value, ALE_POLICER_IPDA_REG_IPDST_INDEX);
    }
    
    /* Read Thread value */
    aleTblCtrlVal           =   CSL_FMK (ALE_THREAD_CTL_REG_ENTRY_PTR, index);
                                
    hCpswAleRegs->THREAD_CTL_REG    =   aleTblCtrlVal;    
    
    value  =  hCpswAleRegs->THREAD_VAL_REG;
    
    if(CSL_FEXT(value, ALE_THREAD_VAL_REG_ENABLE))
    {
        pPolCfg->validBitmap |= CSL_CPSW_ALE_POLICER_THREAD_VALID;
        pPolCfg->thread = CSL_FEXT(value, ALE_THREAD_VAL_REG_VALUE);
    }
    
    return;
}

/** ============================================================================
 *   @n@b CSL_CPSW_setAlePolicerEntry
 *
 *   @b Description
 *   @n This function sets up the ALE table entry for the index specified with 
 *      VLAN configuration specified here.
 *
 *   @b Arguments
     @verbatim
        index                   ALE table index.
        pPolCfg                 ALE entry contents to be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX
 *      ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE=1
 *      ALE_THREAD_CTL_REG_ENTRY_PTR
 *      ALE_POLICER_PORT_OUI_REG_PORT_MEN,
 *      ALE_POLICER_PORT_OUI_REG_PORT_NUM,
 *      ALE_POLICER_PORT_OUI_REG_PRI_MEN,
 *      ALE_POLICER_PORT_OUI_REG_PRI_VAL,
 *      ALE_POLICER_PORT_OUI_REG_ONU_MEN,
 *      ALE_POLICER_PORT_OUI_REG_ONU_INDEX,
 *      ALE_POLICER_DA_SA_REG_DST_MEN,
 *      ALE_POLICER_DA_SA_REG_DST_INDEX,
 *      ALE_POLICER_DA_SA_REG_SRC_MEN,
 *      ALE_POLICER_DA_SA_REG_SRC_INDEX,
 *      ALE_POLICER_VLAN_REG_OVLAN_MEN,
 *      ALE_POLICER_VLAN_REG_OVLAN_INDEX,
 *      ALE_POLICER_VLAN_REG_IVLAN_MEN,
 *      ALE_POLICER_VLAN_REG_IVLAN_INDEX,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN,
 *      ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX,
 *      ALE_POLICER_IPDA_REG_IPDST_MEN,
 *      ALE_POLICER_IPDA_REG_IPDST_INDEX,
 *      ALE_THREAD_VAL_REG_ENABLE,
 *      ALE_THREAD_VAL_REG_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32                                  index;
        CSL_CPSW_ALE_POLICER_ENTRY              polCfg;

        index   =   0;
        polCfg.vlanId  = 0x10;
        ...
 
        // Add ALE Policer entry
        CSL_CPSW_setAlePolicerEntry (index, &polCfg);
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPSW_setAlePolicerEntry
(
    Uint32                              index,
    CSL_CPSW_ALE_POLICER_ENTRY*         pPolCfg
)
{
    Uint32                                  aleTblCtrlVal, value;

    /* Read the Policer Entry configuration */
    value = 0;
    if(pPolCfg->validBitmap & CSL_CPSW_ALE_POLICER_PORT_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_PORT_OUI_REG_PORT_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_PORT_OUI_REG_PORT_NUM, pPolCfg->port);
    }
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_PRI_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_PORT_OUI_REG_PRI_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_PORT_OUI_REG_PRI_VAL, pPolCfg->pri);
    }
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_OUI_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_PORT_OUI_REG_OUI_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_PORT_OUI_REG_OUI_INDEX, pPolCfg->ouiIdx);
    }
    
    hCpswAleRegs->POLICER_PORT_OUI_REG = value;
    
    value = 0;
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_DST_MAC_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_DA_SA_REG_DST_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_DA_SA_REG_DST_INDEX, pPolCfg->dstMacIdx);
    }
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_SRC_MAC_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_DA_SA_REG_SRC_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_DA_SA_REG_SRC_INDEX, pPolCfg->srcMacIdx);
    }
    
    hCpswAleRegs->POLICER_DA_SA_REG = value;
    
    value = 0;
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_OVLAN_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_VLAN_REG_OVLAN_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_VLAN_REG_OVLAN_INDEX, pPolCfg->ovlanIdx);
    }
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_VLAN_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_VLAN_REG_IVLAN_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_VLAN_REG_IVLAN_INDEX, pPolCfg->vlanIdx);
    }
    
    hCpswAleRegs->POLICER_VLAN_REG = value;
    
    value = 0;
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_ETHERTYPE_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX, pPolCfg->ethertypeIdx);
    }
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_SRC_IP_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX, pPolCfg->srcIpIdx);
    }
    
    hCpswAleRegs->POLICER_ETHERTYPE_IPSA_REG = value;
    
    value = 0;
    
    if(pPolCfg->validBitmap &  CSL_CPSW_ALE_POLICER_DST_IP_VALID)
    {
        value |= CSL_FMK (ALE_POLICER_IPDA_REG_IPDST_MEN, (Uint32) 1) |
                 CSL_FMK (ALE_POLICER_IPDA_REG_IPDST_INDEX, pPolCfg->dstIpIdx);
    }
    
    hCpswAleRegs->POLICER_IPDA_REG = value;
    
    /* Set the index in the ALE Policertable to "write" operation and let
     * the hardware load the ALE Policer entry corresponding to index
     * specified into the ALE Policer registers.
     */
    aleTblCtrlVal           =   CSL_FMK (ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX, index) |
                                CSL_FMK (ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE, (Uint32) 1);

    hCpswAleRegs->POLICER_TBL_CTL_REG    =   aleTblCtrlVal;    
    
    
    /* Write Thread value */
    if(pPolCfg->validBitmap & CSL_CPSW_ALE_POLICER_THREAD_VALID)
    {
    
        aleTblCtrlVal       =   CSL_FMK (ALE_THREAD_CTL_REG_ENTRY_PTR, index);
                                
        hCpswAleRegs->THREAD_CTL_REG    =   aleTblCtrlVal; 
        
        value =  CSL_FMK (ALE_THREAD_VAL_REG_ENABLE, (Uint32) 1) |
                 CSL_FMK (ALE_THREAD_VAL_REG_VALUE, pPolCfg->thread);
    
        hCpswAleRegs->THREAD_VAL_REG = value;
    
    }
    
    return;
}

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
