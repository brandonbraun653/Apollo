/**
 *   @file nimu_icssEthDriver.h
 *   @brief
 *      Contains structures and definitions that are used for remote input output control
 */

/*Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef NIMU_ICSS_IOCTL_H
#define NIMU_ICSS_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* IOCTL are classified by their type which is further qualified by opcodes within that type  */

/* IOCTL command code type */
/**
* @def ICSS_IOCTL_SWITCH_CMD
*      Ioctl Switch Command
*/
#define ICSS_IOCTL_SWITCH_CMD   1u
/**
* @def ICSS_IOCTL_STAT_CMD
*      Ioctl Statistics Command
*/
#define ICSS_IOCTL_STAT_CMD       2u

/* IOCTL Opcodes for type Switch Command */
/**
* @def ICSS_IOCTL_BASE
*      Ioctl Switch command base
*/
#define ICSS_IOCTL_BASE                                         0u
/**
* @def ICSS_IOCTL_RATELIMIT
*      Ioctl Ratelimit Command
*/
#define ICSS_IOCTL_RATELIMIT                      (ICSS_IOCTL_BASE + 1u)
/**
* @def ICSS_IOCTL_GET_PORT_CONFIG
*      Ioctl Get Port Config Command
*/
#define ICSS_IOCTL_GET_PORT_CONFIG                (ICSS_IOCTL_BASE + 2u)
/**
* @def ICSS_IOCTL_SET_PORT_CONFIG
*      Ioctl Set Port Config Command
*/
#define ICSS_IOCTL_SET_PORT_CONFIG                (ICSS_IOCTL_BASE + 3u)



/* Opcode definition for switch command */
/**
* @def ICSS_IOCTL_STAT_BASE
*      Ioctl Statistics command base
*/
#define ICSS_IOCTL_STAT_BASE         0u
/**
* @def ICSS_IOCTL_STAT_CLEAR
*      Ioctl Clear Statistics command
*/
#define ICSS_IOCTL_STAT_CLEAR      (ICSS_IOCTL_STAT_BASE +1u)
/**
* @def ICSS_IOCTL_STAT_GET
*      Ioctl Get Statistics command
*/
#define ICSS_IOCTL_STAT_GET        (ICSS_IOCTL_STAT_BASE +2u)


/** make the s/w  stats counters 64-bit wide */
typedef unsigned long long STATCTR;


/**
 * @brief  ICSS Statistics
 *         Statistics counters: Reflect cumulative statistics of enabled ports .
 */
typedef struct NIMU_IcssStatistics_s
{
    volatile STATCTR txUcast;            /**Number of Tx unicast packets*/
    volatile STATCTR txBcast;            /**Number of Tx unicast packets*/
    volatile STATCTR txMcast;            /**Number of Tx unicast packets*/
    volatile STATCTR txGoodFrames;        /**Number of Tx unicast packets*/
    volatile STATCTR txNetOctets;        /**Number of Tx unicast packets*/
    volatile STATCTR rxUcast;            /**Number of unicast packets rcvd*/
    volatile STATCTR rxBcast;            /**Number of broadcast packets rcvd*/
    volatile STATCTR rxMcast;            /**Number of multicast packets rcvd*/
    volatile STATCTR rxGoodFrames;        /**Total number of good frames rcvd*/
    volatile STATCTR rxNetOctets;        /**Total number of bytes rcvd*/
    volatile STATCTR rxUnknownProtocol;    /**Number of unknown protocol packets rcvd*/
    volatile STATCTR droppedPackets;    /**Number of dropped Broadcast packets*/
    volatile STATCTR rxErrorFrames;        /**Number of RX Error Frames*/
    volatile STATCTR txDiscards;        /**Tx Queue under flow count*/
    volatile STATCTR txErrors;            /**Number of TX Errors*/
    volatile STATCTR lateColl;            /**Current Tx queue level*/
    volatile STATCTR excessColl;        /**Number of excess collisions(Half Duplex)*/
    volatile STATCTR singleColl;        /**Number of single collisions (Half Duplex)*/
    volatile STATCTR multiColl;            /**Number of cut through unicast bytes*/
    volatile STATCTR defTx;                /**Number of transmissions deferred*/
    volatile STATCTR CSError;            /**Number of carrier sense errors*/
    volatile STATCTR macTxError;        /**Number of MAC transmit errors*/
    volatile STATCTR macRxError;        /**Number of MAC receive errors*/
    volatile STATCTR sqeTestError;        /**Number of MAC receive errors*/
} NIMU_IcssStatistics;

/**
 * @brief Port VLAN command
 */
typedef struct NIMU_IcssAleVLANCmd_s
 {
    uint32_t  port;            /**Port*/
    uint32_t  vid;            /**VLAN identifier*/
    uint32_t  prio_port;        /**port priority 0 -7*/
    uint32_t  CFI_port;        /**port CFI  0 /1 */
    uint8_t   mem_port;        /**port number 0 - 2 */
    uint8_t   unreg_port;        /**unregistered multicast Egress Ports */
    uint8_t   regag_port;        /**register multicast Egress ports*/
    uint8_t   untag_port;        /** Untag ports */
    uint8_t   add[6];            /** Macid to Add */
    uint32_t  flag;            /** Flag */
    uint32_t  blocked;        /** Port to be blocked or not */
    uint32_t  secure;            /** Secure */
    uint32_t  ageable;        /** Ageable or not*/
    uint32_t  aleTimeout;        /**timeout Expressed in millisecs */
    uint8_t   aledump;        /**if 1 print ale table for debug purpose*/
 }NIMU_IcssAleVLANCmd;

/**
*  @brief Port command
*/
typedef struct NIMU_IcssPortCmd_s
{
    uint32_t  threshold;    /**Threshold*/
    uint8_t   port;        /**Port number*/
    uint32_t  value;        /**Value */
    uint32_t  bl;            /**broadcast limit */
    uint32_t  ml;            /**multicast limit */
    uint8_t   EnDis;        /**1 -enable/0- Disable */
    uint8_t   add[6];        /**Mac address */
    uint32_t  phyMode;    /**Autoneg status     */
}NIMU_IcssPortCmd;

/**
* @brief Packet priority structure
*/
typedef struct NIMU_IcssPrioCmd_s
{
    uint8_t port;                /**Port number*/
    uint8_t prio_rx;            /** Receiving packet priority */
    uint8_t prio_tx;            /** Transmitting packet priority */
    uint8_t prio_switch;        /** switch priority */
    uint8_t hostRxCh;            /** packet with switch priority receive on this channel */
    uint8_t hostRxChSuper;    /** supervisory packet receive on this channel */
}NIMU_IcssPrioCmd;

/**
* @brief Switch control The following structure is used as param for all IOCTL of type switch command
*/
typedef struct NIMU_IcssConsCmd_s
{
    uint32_t     opcode;                                /**opcode for switch control operation */
    NIMU_IcssAleVLANCmd         AleVlanCmd;    /**Vlan command*/
    NIMU_IcssPortCmd            PortCmd;    /**Port command*/
    NIMU_IcssPrioCmd            PrioCmd;    /**Priority command*/
    uint32_t ret_type;    /**Return  Success/Failure */
}NIMU_IcssConsCmd;

/**
* @brief The following structure is used as param for all IOCTL related to STATS
*/
typedef struct NIMU_IcssStatsCmd_s
{
    uint32_t opcode ;                        /**opcode for stats operations*/
    uint8_t portNum ;                        /**stats portnum*/
    NIMU_IcssStatistics  statsObj;        /**used with get stats command*/
}NIMU_IcssStatsCmd;


#ifdef __cplusplus
}
#endif

#endif /*NIMU_ICSS_IOCTL_H */
