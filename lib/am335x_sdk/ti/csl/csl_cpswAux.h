/**  
 * @file  csl_cpsw_Aux.h
 *
 * @brief  
 *  API Auxilary header file for Ethernet switch module CSL. 
 *
 *  Contains the different control command and status query functions definations
 *   
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2017, Texas Instruments, Inc.
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

#ifndef CSL_CPSW_AUX_H_
#define CSL_CPSW_AUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#include <ti/csl/soc.h>
        

/**
@defgroup CSL_CPSW_SYMBOL  CPSW Symbols Defined
@ingroup CSL_CPSW_API
*/
/**
@defgroup CSL_CPSW_DATASTRUCT  CPSW Data Structures
@ingroup CSL_CPSW_API
*/
/**
@defgroup CSL_CPSW_FUNCTION  CPSW Functions
@ingroup CSL_CPSW_API
*/
/**
@defgroup CSL_CPSW_ENUM CPSW Enumerated Data Types
@ingroup CSL_CPSW_API
*/

/**
@addtogroup CSL_CPSW_SYMBOL
@{
*/

/**
@}
*/

/** @addtogroup CSL_CPSW_DATASTRUCT
 @{ */

/** @brief ALE control register configuration definitions */       

/**  Enable Broadcast/Multicast rate limit */	
#define    CSL_CPSW_ALECONTROL_RATELIMIT_EN      (1 << 0u) 

/**  MAC auhorization mode enable */	
#define    CSL_CPSW_ALECONTROL_AUTHMODE_EN       (1 << 1u) 

/**  VLAN Aware Mode enable */	
#define    CSL_CPSW_ALECONTROL_VLANAWARE_EN      (1 << 2u) 

/**  Tx rate limit enable */	
#define    CSL_CPSW_ALECONTROL_RATELIMIT_TX_EN   (1 << 3u) 

/**  OUI deny enable */	
#define    CSL_CPSW_ALECONTROL_OUIDENY_EN        (1 << 5u) 

/**  VID0 mode enable */	
#define    CSL_CPSW_ALECONTROL_VID0MODE_EN       (1 << 6u) 

/**  Learn no VID enable */	
#define    CSL_CPSW_ALECONTROL_LEARN_NO_VID_EN   (1 << 7u) 

/**  Age out now enable */	
#define    CSL_CPSW_ALECONTROL_AGEOUT_NOW_EN     (1 << 29u) 

/**  Clear table enable */	
#define    CSL_CPSW_ALECONTROL_CLRTABLE_EN       (1 << 30u) 

/**  ALE enable */	
#define    CSL_CPSW_ALECONTROL_ALE_EN            (1 << 31u) 

/** @brief Port Mask definitions */       

/**  Port 0 Enable */	
#define    CSL_CPSW_PORTMASK_PORT0_EN            (1 << 0u) 

/**  Port 1 Enable */	
#define    CSL_CPSW_PORTMASK_PORT1_EN            (1 << 1u) 

/**  Port 2 Enable */	
#define    CSL_CPSW_PORTMASK_PORT2_EN            (1 << 2u) 

/**  Port 3 Enable */	
#define    CSL_CPSW_PORTMASK_PORT3_EN            (1 << 3u) 

/**  Port 4 Enable */	
#define    CSL_CPSW_PORTMASK_PORT4_EN            (1 << 4u) 

/**  Port 5 Enable */	
#define    CSL_CPSW_PORTMASK_PORT5_EN            (1 << 5u) 

/**  Port 6 Enable */	
#define    CSL_CPSW_PORTMASK_PORT6_EN            (1 << 6u) 

/**  Port 7 Enable */	
#define    CSL_CPSW_PORTMASK_PORT7_EN            (1 << 7u) 

        

/** @brief      
 *
 *  Holds the Time sync submodule's version info. 
 */        
typedef struct {
	/**  Minor version value */	
	Uint32      minorVer;

	/**  Major version value */	
	Uint32      majorVer;

	/**  RTL version value */	
	Uint32      rtlVer;

	/**  Identification value */	
	Uint32      id;
} CSL_CPSW_VERSION;        

/** @brief      
 *
 *  Holds CPSW control register contents. 
 */        
typedef struct {
	/**  FIFO loopback mode */	
	Uint32      fifoLb;

	/**  Vlan aware mode */	
	Uint32      vlanAware;

	/** Port 0 Enable */	
	Uint32      p0Enable;

	/**  Port 0 Pass Priority Tagged */	
	Uint32      p0PassPriTag;

	/**  Port 1 Pass Priority Tagged */	
	Uint32      p1PassPriTag;

	/**  Port 2 Pass Priority Tagged */	
	Uint32      p2PassPriTag;
    
	/**  Port 3 Pass Priority Tagged */	
	Uint32      p3PassPriTag;
    
	/**  Port 4 Pass Priority Tagged */	
	Uint32      p4PassPriTag;
    
	/**  Port 5 Pass Priority Tagged */	
	Uint32      p5PassPriTag;
    
	/**  Port 6 Pass Priority Tagged */	
	Uint32      p6PassPriTag;
    
	/**  Port 7 Pass Priority Tagged */	
	Uint32      p7PassPriTag;
    
	/**  Port 8 Pass Priority Tagged */	
	Uint32      p8PassPriTag;
    
    /**  Port 0 Transmit CRC remove */
    Uint32      p0TxCrcRemove;
    
    /**  Port 0 Receive Short Packet Pad
         0 - short packets are dropped
         1 - short packets are padded to 64-bytes (with pad and added CRC)
             if the CRC is not passed in.  Short packets are dropped if the CRC is
             passed (in the Info0 word).
      */
    Uint32      p0RxPad; 
    
    /**  Port 0 Pass Received CRC errors */
    Uint32      p0RxPassCrcErr;
    
    /**  Energy Efficient Ethernet enable */
    Uint32      eeeEnable;
    
} CSL_CPSW_CONTROL;

/** @brief      
 *
 *  Holds Priority type register contents. 
 */        
typedef struct {
	/**  Escalate priority load value */	
	Uint32      escPriLdVal;

	/**  Port 0 Priority type escalate */	
	Uint32      p0PtypeEsc;

	/**  Port 1 Priority type escalate */	
	Uint32      p1PtypeEsc;

	/**  Port 2 Priority type escalate */	
	Uint32      p2PtypeEsc;
    
	/**  Port 3 Priority type escalate */	
	Uint32      p3PtypeEsc;
    
	/**  Port 4 Priority type escalate */	
	Uint32      p4PtypeEsc;
    
	/**  Port 5 Priority type escalate */	
	Uint32      p5PtypeEsc;
    
	/**  Port 6 Priority type escalate */	
	Uint32      p6PtypeEsc;
    
	/**  Port 7 Priority type escalate */	
	Uint32      p7PtypeEsc;
    
	/**  Port 8 Priority type escalate */	
	Uint32      p8PtypeEsc;
    
} CSL_CPSW_PTYPE;

/** @brief      
 *
 *  Holds flow control register contents. 
 */        
typedef struct {
	/**  Port 0 flow control enable */	
	Uint32      p0FlowEnable;

	/**  Port 1 flow control enable */	
	Uint32      p1FlowEnable;

	/**  Port 2 flow control enable */	
	Uint32      p2FlowEnable;
    
	/**  Port 3 flow control enable */	
	Uint32      p3FlowEnable;
    
	/**  Port 4 flow control enable */	
	Uint32      p4FlowEnable;
    
	/**  Port 5 flow control enable */	
	Uint32      p5FlowEnable;
    
	/**  Port 6 flow control enable */	
	Uint32      p6FlowEnable;
    
	/**  Port 7 flow control enable */	
	Uint32      p7FlowEnable;
    
	/**  Port 8 flow control enable */	
	Uint32      p8FlowEnable;
    
} CSL_CPSW_FLOWCNTL;

/** @brief      
 *
 *  Holds the ALE submodule's version info. 
 */        
typedef struct {
	/**  Minor version value */	
	Uint32      minorVer;

	/**  Major version value */	
	Uint32      majorVer;

	/**  RTL version value */	
	Uint32      rtlVer;

	/**  Identification value */	
	Uint32      id;
} CSL_CPSW_ALE_VERSION;

/** @brief      
 *
 *  Defines ALE port states
 */        
typedef enum {
    ALE_PORTSTATE_DISABLED = 0,
    ALE_PORTSTATE_BLOCKED,
    ALE_PORTSTATE_LEARN,
    ALE_PORTSTATE_FORWARD
} CSL_CPSW_ALE_PORTSTATE;

/** @brief      
 *
 *  Holds the ALE Port control register info. 
 */        
typedef struct {
	/**  Port state */	
	CSL_CPSW_ALE_PORTSTATE  portState;

	/**  Drop non-VLAN tagged ingress packets?  */	
	Uint32                  dropUntaggedEnable;

	/**  VLAN ID Ingress check enable */	
	Uint32                  vidIngressCheckEnable;

	/**  No learn mode enable */	
	Uint32                  noLearnModeEnable;

	/**  No Source Address Update enable */	
	Uint32                  noSaUpdateEnable;

    /** MAC only mode enable: 
      * When set allows the port to be treated like 
      * a Mac port for the host. All traffic received 
      * is sent only to the host. The host must direct 
      * traffic to this port as the lookup engine will 
      * not send traffic to ports with macOnlyEnable 
      * and noLearnModeEnable is set.  
      * If macOnlyEnable is set and noLearnModeEnable 
      * is not set, the host can send non-directed packets 
      * to a lookup destination with macOnlyEnable set. 
      * It is also possible that the host can broadcast 
      * to all ports including Mac Only ports in this mode.
      */
    Uint32                  macOnlyEnable;
    
    /** Disable MAC Authorization Mode for this port 
      * @note: This field is only valid when CPSW
      *        MAC authentication is enabled.
      */
    Uint32                  macAuthDisable;
    
    /** Mac Only Copy All Frames:
      * Set: A Mac Only port will transfer all received 
      *       good frames to the host. 
      * Clear: A Mac Only port will transfer packets to 
      *        the host based on ALE destination address 
      *        lookup operation. 
      */
    Uint32                  macOnlyCafEnable;
    
	/**  Multicast packet rate limit */	
	Uint32                  mcastLimit;

	/**  Broadcast packet rate limit */	
	Uint32                  bcastLimit;
} CSL_CPSW_ALE_PORTCONTROL;

/** @brief      
 *
 *  Defines ALE Table Entry types
 */        
typedef enum {
    ALE_ENTRYTYPE_FREE = 0,
    ALE_ENTRYTYPE_ADDRESS,
    ALE_ENTRYTYPE_VLAN,
    ALE_ENTRYTYPE_VLANADDRESS
} CSL_CPSW_ALE_ENTRYTYPE;

/** @brief      
 *
 *  ALE Table entry type: MAC ADDRESS
 */        
#define  ALE_ENTRYTYPE_MAC_ADDR     ALE_ENTRYTYPE_ADDRESS

/** @brief      
 *
 *  ALE Table entry type: POLICER ENTRY
 */        
#define  ALE_ENTRYTYPE_POLICER      ALE_ENTRYTYPE_VLAN

/** @brief      
 *
 *  Defines ALE Unicast types
 */        
typedef enum {
    ALE_UCASTTYPE_UCAST_NOAGE = 0,
    ALE_UCASTTYPE_UCAST_AGENOTOUCH,
    ALE_UCASTTYPE_UCAST_OUI,
    ALE_UCASTTYPE_UCAST_AGETOUCH
} CSL_CPSW_ALE_UCASTTYPE;

/** @brief      
 *
 *  Defines ALE Address types
 */        
typedef enum {
    ALE_ADDRTYPE_UCAST = 0,
    ALE_ADDRTYPE_MCAST,
    ALE_ADDRTYPE_OUI
} CSL_CPSW_ALE_ADDRTYPE;


/** @brief      
 *
 *  Defines ALE Policer Entry  types
 */        
typedef enum {
    ALE_POLICER_ENTRYTYPE_VLAN = 0,     /** VLAN or Inner VLAN */
    ALE_POLICER_ENTRYTYPE_OVLAN,        /** Outer VLAN */
    ALE_POLICER_ENTRYTYPE_ETHERTYPE,    /** Ethertype */
    ALE_POLICER_ENTRYTYPE_IPV4,         /** IPv4 address */
    ALE_POLICER_ENTRYTYPE_IPV6          /** IPv6 address */
} CSL_CPSW_ALE_POLICER_ENTRYTYPE;

/** @brief      
 *
 *  Holds the ALE Multicast Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  Multicast address */	
	Uint8                       macAddress [6];

	/**  Multicast forward state  */	
	Uint32                      mcastFwdState;

	/**  Supervisory bit enable? */	
	Uint32                      superEnable;

	/**  Port Mask. */	
	Uint32                      portMask;
} CSL_CPSW_ALE_MCASTADDR_ENTRY;

/** @brief      
 *
 *  Holds the ALE VLAN/Multicast Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  Multicast address */	
	Uint8                       macAddress [6];

	/**  VLAN Id  */	
	Uint32                      vlanId;

	/**  Multicast forward state  */	
	Uint32                      mcastFwdState;

	/**  Supervisory bit enable? */	
	Uint32                      superEnable;

	/**  Port Mask. */	
	Uint32                      portMask;
} CSL_CPSW_ALE_VLANMCASTADDR_ENTRY;

/** @brief      
 *
 *  Holds the ALE Unicast Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  Unicast address */	
	Uint8                       macAddress [6];

	/**  Unicast type  */	
	CSL_CPSW_ALE_UCASTTYPE      ucastType;

	/**  Secure bit enable?  */	
	Uint32                      secureEnable;

	/**  Block bit enable? */	
	Uint32                      blockEnable;

	/**  Port Number to forward matching packets to. */	
	Uint32                      portNumber;
} CSL_CPSW_ALE_UNICASTADDR_ENTRY;

/** @brief      
 *
 *  Holds the ALE OUI Unicast Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  OUI Unicast address */	
	Uint8                       ouiAddress [3];

	/**  Unicast type  */	
	CSL_CPSW_ALE_UCASTTYPE      ucastType;
} CSL_CPSW_ALE_OUIADDR_ENTRY;

/** @brief      
 *
 *  Holds the ALE VLAN Unicast Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  Unicast address */	
	Uint8                       macAddress [6];

	/**  VLAN Id  */	
	Uint32                      vlanId;

	/**  Unicast type  */	
	CSL_CPSW_ALE_UCASTTYPE      ucastType;

	/**  Secure bit enable?  */	
	Uint32                      secureEnable;

	/**  Block bit enable? */	
	Uint32                      blockEnable;

	/**  Port Number to forward matching packets to. */	
	Uint32                      portNumber;
} CSL_CPSW_ALE_VLANUNICASTADDR_ENTRY;

/** @brief      
 *
 *  Holds the ALE (Inner) VLAN Table entry configuration.
 */        
typedef struct {
	/**  VLAN Id  */	
	Uint32                      vlanId;

	/**  VLAN member list */	
	Uint32                      vlanMemList;

	/**  Unregistered Multicast Flood mask  */	
	Uint32                      unRegMcastFloodMask;

	/**  Registered Multicast Flood mask  */	
	Uint32                      regMcastFloodMask;

	/**  Force Untagged Packet Egress. */	
	Uint32                      forceUntaggedEgress;
} CSL_CPSW_ALE_VLAN_ENTRY;

/** @brief      
 *
 *  Holds the ALE Outer VLAN Table entry configuration.
 */        
typedef struct {
	/**  VLAN Id  */	
	Uint32                      vlanId;

} CSL_CPSW_ALE_OUTER_VLAN_ENTRY;

/** @brief      
 *
 *  Holds the ALE Ethertype Table entry configuration.
 */        
typedef struct {
	/**  Ethernet Type  */	
	Uint32                      ethertype;

} CSL_CPSW_ALE_ETHERTYPE_ENTRY;


/** @brief      
 *
 *  Holds the ALE IPv4 Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  IPv4 address */	
	Uint8                       address [4];

} CSL_CPSW_ALE_IPv4_ENTRY;

/** @brief      
 *
 *  Holds the ALE IPv6 Address Table entry
 *  configuration.
 */        
typedef struct {
	/**  IPv6 address */	
	Uint8                       address [16];

} CSL_CPSW_ALE_IPv6_ENTRY;


/** ============================================================================ 
 *
 * @defgroup CSL_CPSW_API Ethernet switch submodule (CPSW)
 * @ingroup CSL_CPSW_API
 *
 *
 * @subsection xxx Overview
 * CSL CPSW API  has implementation for multiple SoCs with below SoC map
 *      -# cpsw v0 - SOC_K2H/SOC_K2K
 *      -# cpsw v1 - SOC_K2E/SOC_K2L
 *      -# cpsw v2 - SOC_K2G
 *      -# cpsw v3 - SOC_AM574x/SOC_AM572x/SOC_AM571x/SOC_DRA75X/SOC_DRA78X
 *      -# cpsw v4 - SOC_C6678
 *
 * @note: there may not be any ip specific implementation for that soc, if it contains only cslr_* files
 *
 * ============================================================================
 */


#if defined(SOC_K2K)

#include <ti/csl/src/ip/cpsw/V0/csl_cpswAux.h>

#elif defined(SOC_K2H)

#include <ti/csl/src/ip/cpsw/V0/csl_cpswAux.h>

#elif defined(SOC_K2E)

#include <ti/csl/src/ip/cpsw/V1/csl_cpswAux.h>

#elif defined(SOC_K2L)

#include <ti/csl/src/ip/cpsw/V1/csl_cpswAux.h>

#elif defined(SOC_K2G) || defined(SOC_AM65XX)

#include <ti/csl/src/ip/cpsw/V2/csl_cpswAux.h>

#elif defined(SOC_AM574x) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x)

#include <ti/csl/src/ip/cpsw/V3/csl_cpswAux.h>

#elif defined(SOC_C6678)

#include <ti/csl/src/ip/cpsw/V4/csl_cpswAux.h>

#endif /* SOC_XXXXX */


/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
