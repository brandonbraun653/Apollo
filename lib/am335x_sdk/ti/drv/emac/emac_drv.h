/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - http://www.ti.com/
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

/**  @mainpage Ethernet MAC Low Level Driver
 *  
 *  @section into Introduction
 *
 *  EMAC driver provides a well defined API layer which allows applications to use the EMAC peripheral to control the flow 
 *  of packet data from the processor to the PHY and the MDIO module to control PHY configuration and status monitoring .
 *  For a complete list of APIs supported refer to @ref emaclld_api_functions.
 *  
 */

/**
 *  @file       emac_drv.h
 *
 *  @brief      EMAC driver interface
 *
 *  This API header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/emac/emac_drv.h>
 *  @endcode
 *
 */
#ifndef EMAC_DRV_H_
#define EMAC_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#if defined (SOC_AM65XX)
#include <ti/utils/trace/trace.h>
#endif

/* Define EMAC LLD as a master group in Doxygen format and add all EMAC LLD APIs
   definitions to this group. */
/** @defgroup emaclld_module EMAC LLD Module API
 *  @{
 */
/** @} */

/** @defgroup emaclld_api_functions EMAC LLD Functions 
 *  @ingroup emaclld_module
 */

/** @defgroup emaclld_api_structures EMAC LLD Data Structures
 *  @ingroup emaclld_module
 */

/** @defgroup emaclld_api_constants EMAC LLD Constants (enums and constants)
 *  @ingroup emaclld_module
 */

/** @defgroup emaclld_api_ioctl_macros EMAC LLD IOCTL Macros 
 *  @ingroup emaclld_module
 */

/** @defgroup emaclld_callback_functions EMAC LLD Callback Functions
 *  @ingroup emaclld_module
 */


/**
 * @brief Big enough to hold the mandatory fields of the host descriptor
 */
#define         EMAC_SIZE_HOST_DESC              128

/**
 * @brief   Max packet descriptors for EMAC TX and RX queue per port,  max sized for K2G
 */
#define MAX_EMAC_INIT_PKT_DESC                   1024


/**
 * @ingroup emaclld_api_constants
  *@brief EMAC API return codes
  */
typedef enum EMAC_DrvError_e
{
    EMAC_DRV_RESULT_OK                                      =   0,
    /**< Success                                                            */
    EMAC_DRV_RESULT_GENERAL_ERR                             = (-(int32_t)1),
    /**< An unspecified error                                               */
    EMAC_DRV_RESULT_INVALID_PORT                            = (-(int32_t)2),
    /**< Invalid EMAC port number error                                     */
    EMAC_DRV_RESULT_NO_CHAN_AVAIL                           = (-(int32_t)3), 
    /**< No channel available error                                         */
    EMAC_DRV_RESULT_NO_MEM_AVAIL                            = (-(int32_t)4),
    /**< Out of memory error                                                */
    EMAC_DRV_RESULT_OPEN_PORT_ERR                           = (-(int32_t)5),
    /**< Open EMAC port error                                               */
    EMAC_DRV_RESULT_CLOSE_PORT_ERR                          = (-(int32_t)6),
    /**< Close EMAC port error                                              */
    EMAC_DRV_RESULT_CONFIG_PORT_ERR                         = (-(int32_t)7),
    /**< Config EMAC port error                                             */
    EMAC_DRV_RESULT_SEND_ERR                                = (-(int32_t)8),
    /**< Send packet error                                                  */
    EMAC_DRV_RESULT_POLL_ERR                                = (-(int32_t)9),
    /**< Poll link status error                                             */
    EMAC_DRV_RESULT_GET_STATS_ERR                           = (-(int32_t)10),
    /**< Poll stats error                                                   */
    EMAC_DRV_RESULT_ISR_ERR                                 = (-(int32_t)11),
    /**< Interrupt service error                                            */
    EMAC_DRV_RESULT_IOCTL_ERR                               = (-(int32_t)12),
    /**< IOCTL command error                                                */
    EMAC_DRV_RESULT_IOCTL_ERR_IN_PROGRESS                   = (-(int32_t)13),
    /**< IOCTL command error, IOCLT command already in progress             */
    EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID               = (-(int32_t)14),
    /**< IOCTL command error, VLAN ID not valid                             */
    EMAC_DRV_RESULT_IOCTL_ERR_PORT_CLOSED                   = (-(int32_t)15),
    /**< IOCTL command error, port is closed                                */
    EMAC_DRV_RESULT_ERR_PORT_CLOSED                         = EMAC_DRV_RESULT_IOCTL_ERR_PORT_CLOSED,
    /**< Port is closed                                */
    EMAC_DRV_RESULT_IOCTL_ERR_SEND_MGMT_MSG                 = (-(int32_t)16),
    /**< IOCTL command error, error when sending MGMT message over PSI I/F to FW                        */
    EMAC_DRV_RESULT_IOCTL_ERR_NO_FREE_DESC                  = (-(int32_t)17),
    /**< IOCTL command error, no free descriptor available for sending MGMT message over PSI I/F to FW  */
    EMAC_DRV_RESULT_ERR_NO_FREE_DESC                        = EMAC_DRV_RESULT_IOCTL_ERR_NO_FREE_DESC,
    /**< No free descriptor available when calling emac_send    */
    EMAC_DRV_RESULT_TX_PORT_QUEUE_SIZE_ERR                  = (-(int32_t)18),
    /**< Size of TX port queue is not big enough to setup all the FW port queues    */
    EMAC_DRV_RESULT_ERR_INVALID_PHY_ADDR                    = (-(int32_t)19),
    /**< Invalid phy address specified                                              */
    EMAC_DRV_RESULT_ERR_UDMA_TX_CHAN_SETUP                  = (-(int32_t)20),
    /**< Error in settting up UDMA TX channel                                       */
    EMAC_DRV_RESULT_ERR_UDMA_RX_CHAN_SETUP                  = (-(int32_t)21),
    /**< Error in settting up UDMA RX channel                                       */
    EMAC_DRV_RESULT_ERR_UDMA_FLOW_SETUP                     = (-(int32_t)22),
    /**< Error in settting up UDMA flow                                             */
    EMAC_DRV_RESULT_ERR_INVALID_CHANNEL                     = (-(int32_t)23),
    /**< Invalid channel number specified                                           */
    EMAC_DRV_RESULT_ERR_UDMA_RING_ENQUEUE                   = (-(int32_t)24),
    /**< Error during Udma RING enqueue                                             */
    EMAC_DRV_RESULT_IOCTL_IN_PROGRESS                       = ((int32_t)1),
    /**< IOCTL command in progress                                                  */
} EMAC_DrvError;

typedef EMAC_DrvError EMAC_DRV_ERR_E;

#ifndef _TRACE_H
/**
 * @brief Trace level indicating fatal error
 */
#define                UTIL_TRACE_LEVEL_FATAL_ERR            1

/**
 * @brief Trace level indicating error
 */
#define                UTIL_TRACE_LEVEL_ERR                  2

/**
 * @brief Trace level indicating warning
 */
#define                UTIL_TRACE_LEVEL_WARN                 3

/**
 * @brief Trace level indicating unexpected condition
 */
#define                UTIL_TRACE_LEVEL_UNEXPECTED           4
/**
 * @brief Trace level for info
 */
#define                UTIL_TRACE_LEVEL_INFO                 5

typedef void UTIL_TRACE_CB_T(uint8_t traceLevel, const char* traceString, ...);

/* turn off to disable trace utility */
#define UTILS_PDK_TRACE_ENABLE
#ifdef UTILS_PDK_TRACE_ENABLE
#define UTILS_trace(dbg_level, trace_fxn, fmt, ...)  if(trace_fxn) { trace_fxn(dbg_level, "func: %s line:%d: " fmt,__FUNCTION__, __LINE__, __VA_ARGS__); } 
#else
#define UTILS_trace(dbg_level, trace_fxn, fmt, ...)
#endif
#endif

/**
 * @ingroup emaclld_api_constants
 * @brief Set of constants used in emac_poll_ctrl API to specify which rx packet rings to poll
 *        when using @ref emac_poll_ctrl
 */
typedef enum EMAC_POLL_RX_PKT_RINGS_e{
    EMAC_POLL_RX_PKT_RING1      = 0x1,                              /**< Poll rx pkt ring 1 associated with default flow */
    EMAC_POLL_RX_PKT_RING2      = (EMAC_POLL_RX_PKT_RING1) << 1,    /**< Poll rx pkt ring 2 */
    EMAC_POLL_RX_PKT_RING3      = (EMAC_POLL_RX_PKT_RING2) << 1,    /**< Poll rx pkt ring 3 */
    EMAC_POLL_RX_PKT_RING4      = (EMAC_POLL_RX_PKT_RING3) << 1,    /**< Poll rx pkt ring 4 */
    EMAC_POLL_RX_PKT_RING5      = (EMAC_POLL_RX_PKT_RING4) << 1,    /**< Poll rx pkt ring 5 */
    EMAC_POLL_RX_PKT_RING6      = (EMAC_POLL_RX_PKT_RING5) << 1,    /**< Poll rx pkt ring 6 */
    EMAC_POLL_RX_PKT_RING7      = (EMAC_POLL_RX_PKT_RING6) << 1,    /**< Poll rx pkt ring 7 */
    EMAC_POLL_RX_PKT_RING8      = (EMAC_POLL_RX_PKT_RING7) << 1,    /**< Poll rx pkt ring 8 */
    EMAC_POLL_RX_PKT_RING9      = (EMAC_POLL_RX_PKT_RING8) << 1,    /**< Poll rx pkt ring 9 */
    EMAC_POLL_RX_PKT_RING_ALL   = 0x1FF                             /**< Poll all of the rx pkt rings */
} EMAC_POLL_RX_PKT_RINGS;

/**
 * @ingroup emaclld_api_constants
 * @brief Set of constants used in emac_poll_ctrl API to specify which rx management rings to poll
 *        when using @ref emac_poll_ctrl
 */
typedef enum EMAC_POLL_RX_MGMT_RINGS_e{
    EMAC_POLL_RX_MGMT_RING1      = 0x1,                             /**< Poll rx mgmt ring 1, associated with default flow*/
    EMAC_POLL_RX_MGMT_RING2      = (EMAC_POLL_RX_MGMT_RING1) << 1,  /**< Poll rx mgmt ring 2, used for get rx mgmt response from FW */
    EMAC_POLL_RX_MGMT_RING3      = (EMAC_POLL_RX_MGMT_RING2) << 1,  /**< Poll rx mgmt ring 3, used for get tx timestamp response from FW */
    EMAC_POLL_RX_MGMT_RING_ALL   =  0x7                             /**< Poll all of the rx mgmt rings */
} EMAC_POLL_RX_MGMT_RINGS;

/**
 * @ingroup emaclld_api_constants
 * @brief Set of constants used in emac_poll_ctrl API to specify which tx completion rings to poll to recycle TX descriptors
          and recycle applicaiton buffer when using @ref emac_poll_ctrl
 */
typedef enum EMAC_POLL_TX_COMPL_RINGS_e{
    EMAC_POLL_TX_COMPLETION_RING1      = 0x1,                                   /**< Poll tx completion ring for channel 1, lowest priority TX channel */
    EMAC_POLL_TX_COMPLETION_RING2      = (EMAC_POLL_TX_COMPLETION_RING1) << 1,  /**< Poll tx completion ring for channel 2 */
    EMAC_POLL_TX_COMPLETION_RING3      = (EMAC_POLL_TX_COMPLETION_RING2) << 1,  /**< Poll tx completion ring for channel 3 */
    EMAC_POLL_TX_COMPLETION_RING4      = (EMAC_POLL_TX_COMPLETION_RING3) << 1,  /**< Poll tx completion ring for channel 4, highest priority TX channel */
    EMAC_POLL_TX_COMPLETION_RING_ALL   = 0xF                                    /**< Poll all of the tx completion rings */
} EMAC_POLL_TX_COMPL_RINGS;

/**
 * @brief Specification of EMAC_PKT_FLAG_T
 *
 * The EMAC_PKT_FLAG_T is used to provide packet flags in Flags field of 
 * @ref EMAC_PKT_DESC_T at time of emac_send API.
 */
typedef uint32_t EMAC_PKT_FLAG_T;

/**
 *  @def  EMAC_PKT_FLAG_SOP
 *        Start of packet flag indication in Flags field of @ref EMAC_PKT_DESC_T
 *  @note Not applicable for  am65xx SOC
 */
#define EMAC_PKT_FLAG_SOP              0x80000000U

/**
 *  @def  EMAC_PKT_FLAG_EOP
 *        End of packet flag indication in Flags field of @ref EMAC_PKT_DESC_T
 *  @note Not applicable for  am65xx SOC
 */
#define EMAC_PKT_FLAG_EOP              0x40000000U

/**
 *  @def  EMAC_PKT_FLAG_TX_TS_REQ
 *        Transmit packet timestamp request in Flags field of  @ref EMAC_PKT_DESC_T
    @note ONLY supported for am65xx SOC
 */
#define EMAC_PKT_FLAG_TX_TS_REQ              0x20000000U


/**
 * @brief   Maximum number of phy address
 */
#define EMAC_MAX_NUM_PHY_ADDR               32

/**
 * @ingroup emaclld_api_structures
 * @brief Emac packet descriptor specification
 *
 * @details
 *  The packet structure defines the basic unit of memory used to hold data
 *  packets for the EMAC device.
 *
 *  A packet is comprised of one or more packet buffers. Each packet buffer
 *  contains a packet buffer header, and a pointer to the buffer data.
 *  The EMAC_Pkt structure defines the packet buffer header.
 *
 *  The pDataBuffer field points to the packet data. This is set when the
 *  buffer is allocated, and is not altered.
 *
 *  BufferLen holds the the total length of the data buffer that is used to
 *  store the packet (or packet fragment). This size is set by the entity
 *  that originally allocates the buffer, and is not altered.
 *
 *  The Flags field contains additional information about the packet
 *
 *  ValidLen holds the length of the valid data currently contained in the
 *  data buffer.
 *
 *  DataOffset is the byte offset from the start of the data buffer to the
 *  first byte of valid data. Thus (ValidLen+DataOffet)<=BufferLen.
 *
 *  Note that for receive buffer packets, the DataOffset field may be
 *  assigned before there is any valid data in the packet buffer. This allows
 *  the application to reserve space at the top of data buffer for private
 *  use. In all instances, the DataOffset field must be valid for all packets
 *  handled by EMAC.
 *
 *  The data portion of the packet buffer represents a packet or a fragment
 *  of a larger packet. This is determined by the Flags parameter. At the
 *  start of every packet, the SOP bit is set in Flags. If the EOP bit is
 *  also set, then the packet is not fragmented. Otherwise; the next packet
 *  structure pointed to by the pNext field will contain the next fragment in
 *  the packet. On either type of buffer, when the SOP bit is set in Flags,
 *  then the PktChannel, PktLength, and PktFrags fields must also be valid.
 *  These fields contain additional information about the packet.
 *
 *  The PktChannel field detetmines what channel the packet has arrived on,
 *  or what channel it should be transmitted on. The EMAC library supports
 *  only a single receive channel, but allows for up to eight transmit
 *  channels. Transmit channels can be treated as round-robin or priority
 *  queues.
 *
 *  The PktLength field holds the size of the entire packet. On single frag
 *  packets (both SOP and EOP set in BufFlags), PktLength and ValidLen will
 *  be equal.
 *
 *  The PktFrags field holds the number of fragments (EMAC_Pkt records) used
 *  to describe the packet. If more than 1 frag is present, the first record
 *  must have EMAC_PKT_FLAGS_SOP flag set, with corresponding fields validated.
 *  Each frag/record must be linked list using the pNext field, and the final
 *  frag/record must have EMAC_PKT_FLAGS_EOP flag set and pNext=0.
 *
 *  In systems where the packet resides in cacheable memory, the data buffer
 *  must start on a cache line boundary and be an even multiple of cache
 *  lines in size. The EMAC_Pkt header must not appear in the same cache line
 *  as the data portion of the packet. On multi-fragment packets, some packet
 *  fragments may reside in cacheable memory where others do not.
 *
 *  @verbatim
    <b> NOTE: It is up to the caller to assure that all packet buffers
    residing in cacheable memory are not currently stored in L1 or L2
    cache when passed to any EMAC function. </b>
    @endverbatim
 *
 *  Some of the packet Flags can only be set if the device is in the
 *  proper configuration to receive the corresponding frames. In order to
 *  enable these flags, the following modes must be set:
 *        RxCrc Flag  : RXCRC Mode in EMAC_Cpsw3gInitConfig
 *        RxErr Flags : PASSERROR Mode in EMAC_Cpsw3gInitConfig
 *        RxCtl Flags : PASSCONTROL Mode in EMAC_Cpsw3gInitConfig
 *        RxPrm Flag  : EMAC_RXFILTER_ALL in CPSW_setReceiveFilter()
 *
 */
typedef struct EMAC_PKT_DESC_s
{
    uintptr_t              AppPrivate;
    /**< For use by the application                                         */
    struct EMAC_PKT_DESC_s*    pPrev;
    /**< Previous descriptor pointer                                        */
    struct EMAC_PKT_DESC_s*    pNext;
    /**< Next descriptor pointer                                            */
    uint8_t*              pDataBuffer;
    /**< Pointer to Data Buffer (read only)                                 */
    uint32_t              BufferLen;
    /**< Physical Length of buffer (read only)                              */
    EMAC_PKT_FLAG_T     Flags;
    /**< Packet Flags, SOP, EOP, TX timestamp request                       */
    uint32_t              ValidLen;
    /**< Length of valid data in buffer                                     */
    uint32_t              DataOffset;
    /**< Byte offset to valid data                                          */
    uint32_t              PktChannel;
    /**< Tx/Rx Channel 0-7 (SOP only)                                       */
    uint32_t              PktLength;
    /**< Length of Packet (SOP only) (same as ValidLen on single frag Pkt)  */
    uint32_t              PktFrags;
    /**< No of frags in packet (SOP only), normally 1                       */
    uint64_t              RxTimeStamp;
    /**< Receive packet timestamp                                           */
    uint32_t              TxtimestampId;
    /**<Transmit timestamp id used to correleate request with response     */
    uint32_t              TxPktTc;
    /**<TX packet traffic class indicates which TX port queue the ICSSG FW should use the transmit the packet to the PHY */
    int32_t              RefCount;
    /**< reference count used for PG1.0/Interposercard TSN SWITCH un-directed packets use case, LLD internal use only*/
} EMAC_PKT_DESC_T;



/**
 * @brief Max size of response parameters returned in IOCTL command response
 */
#define EMAC_IOCTL_CMD_RESP_PARARM_LEN ((uint32_t)3U)

/**
 * @ingroup emaclld_api_structures
 * @brief Emac IOCTL command response specification
 *
 * @details
 *  The packet structure defines the format of the IOCTL reponse
 *  message and is provivded inthe callback 
 */
typedef struct EMAC_IOCTL_CMD_RESP_s {
    uint8_t              status;
    /**< Status for IOCTL cmd */
    uint8_t              seqNumber;
    /**<seqeunce number of command request, returned to application in response */
    uint32_t             respParamsLength;
    /**< number of bytes  in the respParams field, this is optional*/
    uint32_t             respParams[EMAC_IOCTL_CMD_RESP_PARARM_LEN];
    /**< optional response parameters */
} EMAC_IOCTL_CMD_RESP_T;

/**
 *@ingroup emaclld_callback_functions
 *  @brief  This function is used to call back the network application when a
 *          packet is received. Registered with driver at time of @ref emac_open.
 */
typedef void EMAC_RX_PKT_CALLBACK_FN_T
(
   uint32_t               port_num,
   /**< EMAC port number packet received on                                 */
   EMAC_PKT_DESC_T*     p_desc
   /**< Pointer to the received packet descriptor                           */
);

/**
 *@ingroup emaclld_callback_functions
 *@brief  This function is used to call back the network application to 
 *          allocate a packet descriptor with packet buffer allocated from the 
 *          application packet queue.Registered with driver at time of @ref emac_open.
 */
typedef EMAC_PKT_DESC_T* EMAC_ALLOC_PKT_CALLBACK_FN_T
(
   uint32_t               port_num,   
   /**< EMAC port number                                                    */
   uint32_t               pkt_size    
   /**< Size of the packet buffer to be allocated                                  */
);

/**
 *@ingroup emaclld_callback_functions
 *  @brief  This function is used to call back the network application to 
 *          free a packet descriptor to the application packet queue.
 *          Registered with driver at time of @ref emac_open.
 */
typedef void EMAC_FREE_PKT_CALLBACK_FN_T
(
   uint32_t               port_num,   
   /**< EMAC port number                                                    */
   EMAC_PKT_DESC_T*     p_desc      
   /**< Pointer to the received packet descriptor                           */
);


/**
 *@ingroup emaclld_callback_functions
 *  @brief  This function is used to call back the network application when a
 *          management message response is received from ICSSG FW.
 *          Registered with driver at time of @ref emac_open.
 */
typedef void EMAC_RX_MGMT_CALLBACK_FN_T
(
   uint32_t               port_num,
   /**< EMAC port number                                                    */
   EMAC_IOCTL_CMD_RESP_T*     pCmdResp
   /**< Pointer to the IOCTL command reponse                           */
);

/**
 *@ingroup emaclld_callback_functions
 *  @brief  This function is used to call back the network application when a
 *          TX Timestamp response is received from the ICSSG firmware.
 *          Registered with driver at time of @ref emac_open.
 *  @note Only supported for am65xx SOC
 */
typedef void EMAC_TX_TS_CALLBACK_FN_T
(
   uint32_t               port_num,
    /**< EMAC port number                                                   */
   uint32_t ts_id,
    /**< timestamp id to correleate Timestamp response with timestamp request */
   uint64_t ts,
    /**< 64 bit timestamp provided by ICSSG FW                              */
    bool isValid
    /**< flag to indicate if packet was transmitted and timestamp is valid */
);



/**
 * @ingroup emaclld_api_structures
 * @brief       UAC address specification
 *
 * @details This type is used to pass MAC addresses to the driver. 
 */
#define EMAC_MAC_ADDR_LENTH     6U
/**
 * @brief MAC address specification
 */
typedef struct EMAC_MAC_ADDR_tag
{
    uint8_t   addr[EMAC_MAC_ADDR_LENTH];
    /**< MAC address specific to channel                                    */
} EMAC_MAC_ADDR_T;


/**
 * @ingroup emaclld_api_structures
 * @brief       Used to Initialize the Emac Driver Instance with mac addresses
 *              and channel information
 *
 * @details This configuration structure is a field of EMAC_OPEN_CONFIG_INFO_T and
 * used to configure the driver with  channel and mac addreses information
 */

typedef struct EMAC_CHAN_MAC_ADDR_tag
{
    uint32_t               chan_num;
    /**< channel number configured for this core                            */
    uint32_t               num_of_mac_addrs;
   /**< Total number of MAC addresses configured for this channel           */
    EMAC_MAC_ADDR_T*     p_mac_addr;
   /**< Pointer to the MAC addresses configured for this channel @ref EMAC_MAC_ADDR_T             */
} EMAC_CHAN_MAC_ADDR_T;


/**
 * @ingroup emaclld_api_structures
 * @brief       Used to Initialize the Emac Driver Instance at time of emac_open
 *
 * @details TThis configuration structure is used to initialize the Emac Driver Instance.
 * This configuration information is passed while opening the DRV instance
 */
typedef struct EMAC_OpenConfigInfo_s
{
    bool                            master_core_flag;
    /**< True: master core configuration                                    */
    bool                            mdio_flag;
    /**< True: configure MDIO                                               */
    uint32_t                          phy_addr;
    /**< Physical layer transceiver address mapped to the EMAC port
         valid address range is 0 - (EMAC_MAX_NUM_PHY_ADDR-1).
         if a valid address is specified, EMAC driver will check the link
         status only on the application specifid phy address; if an invalid 
         phy_addr is specified, EMAC driver will search the phy address that 
         can be used by itself                                              */
    bool                            loop_back;
    /**< True: packets loop back                                            */
    uint32_t                          num_of_tx_pkt_desc;
    /**< Total # of pkt desc initialized for all the TX chans in TX queues  */
    uint32_t                          num_of_rx_pkt_desc;
    /**< Total # of pkt desc initialized for all the RX chans in RX queues  */
    uint32_t                          max_pkt_size;
    /**< Maximum size of the packet in bytes                                */
    uint32_t                          num_of_chans;
    /**< Total number of TX/RX channels configured for this core, only applicable for SOC_C6657 */
    EMAC_CHAN_MAC_ADDR_T*           p_chan_mac_addr;
   /**< Application needs to provide the MAC address configurations; 
        EMAC driver will allocate the channels if available and 
        return the channel info to the application                          */
    EMAC_RX_PKT_CALLBACK_FN_T*      rx_pkt_cb;
    /**< EMAC RX call back function                                         */
    EMAC_ALLOC_PKT_CALLBACK_FN_T*   alloc_pkt_cb;
    /**< EMAC allocate packet call back function                            */
    EMAC_FREE_PKT_CALLBACK_FN_T*    free_pkt_cb;
    /**< EMAC free packet call back function                                */
    EMAC_RX_MGMT_CALLBACK_FN_T*      rx_mgmt_response_cb;
    /**< EMAC receive call back function for management response from ICSSG FW   */
    EMAC_TX_TS_CALLBACK_FN_T*       tx_ts_cb;
    /**< EMAC transmit timestamp response callback function */
    void *hwAttrs;
    /**< Pointer to a driver specific hardware attributes structure */
    void *appPrivate; 
    /**< DEPRECATED: Application specific handle, not used by driver*/
    uint32_t mode_of_operation;
    /**< Default  Keystone 3 only settting: for receive packet is interrupt mode (0), can set to poll mode (1)*/
    void* udmaHandle;
    /**< Handle to UDMA driver */
    UTIL_TRACE_CB_T* drv_trace_cb;
} EMAC_OpenConfigInfo;


typedef EMAC_OpenConfigInfo EMAC_OPEN_CONFIG_INFO_T;

/**
 *  @brief Packet Filtering
 *
 *  Receive Packet Filtering Settings 
 *
 */
typedef uint32_t EMAC_PktFilter_T;
#define EMAC_PKTFLT_NOTHING           0
/**< Receive filter set to receive no packets                           */
#define EMAC_PKTFLT_DIRECT            1
/**< Receive filter set to receive direct unitcast packets              */
#define EMAC_PKTFLT_BROADCAST         2
/**< Receive filter set to receive broadcast/unitcast packets           */
#define EMAC_PKTFLT_MULTICAST         3
/**< Receive filter set to receive multicast/broadcast/unitcast packets */
#define EMAC_PKTFLT_ALLMULTICAST      4
/**< Receive filter set to receive alll Mcast/Bcast/Ucast packets       */
#define EMAC_PKTFLT_ALL               5
/**< Receive filter set to receive All packets                          */


typedef EMAC_PktFilter_T EMAC_PKT_FILTER_T;


/*!
 *  @brief  EMAC configuration data structure
 */

typedef struct EMAC_ConfigInfo_s
{
    EMAC_PKT_FILTER_T   rx_filter;
    /**< EMAC RX filter, e.g. broadcast, multicast, etc.                    */
    uint32_t              mcast_cnt;   
    /**< Multicast address count, if mcast_cnt=0, p_mcast_list can be NULL  */
    uint8_t*              p_mcast_list;
    /**< Pointer to the multicast list of which size is mcast_cnt*6 in bytes*/
} EMAC_ConfigInfo;

typedef EMAC_ConfigInfo EMAC_CONFIG_INFO_T;

/**
 *  @brief  EMAC Statistics
 *  The statistics structure is used to retrieve the current count
 *  of various packet events in the system. These values represent the
 *  delta values from the last time the statistics were read.
 */
 typedef struct EMAC_STATISTICS_tag
 {
    uint32_t      RxGoodFrames;     
    /**< Good Frames Received                                               */
    uint32_t      RxBCastFrames;    
    /**< Good Broadcast Frames Received                                     */
    uint32_t      RxMCastFrames;    
    /**< Good Multicast Frames Received                                     */
    uint32_t      RxPauseFrames;    
    /**< PauseRx Frames Received                                            */
    uint32_t      RxCRCErrors;      
    /**< Frames Received with CRC Errors                                    */
    uint32_t      RxAlignCodeErrors;
    /**< Frames Received with Alignment/Code Errors                         */
    uint32_t      RxOversized;      
    /**< Oversized Frames Received                                          */
    uint32_t      RxJabber;         
    /**< Jabber Frames Received                                             */
    uint32_t      RxUndersized;     
    /**< Undersized Frames Received                                         */
    uint32_t      RxFragments;      
    /**< Rx Frame Fragments Received                                        */
    uint32_t      RxFiltered;       
    /**< Rx Frames Filtered Based on Address                                */
    uint32_t      RxQOSFiltered;    
    /**< Rx Frames Filtered Based on QoS Filtering                          */
    uint32_t      RxOctets;         
    /**< Total Received Bytes in Good Frames                                */
    uint32_t      TxGoodFrames;     
    /**< Good Frames Sent                                                   */
    uint32_t      TxBCastFrames;    
    /**< Good Broadcast Frames Sent                                         */
    uint32_t      TxMCastFrames;    
    /**< Good Multicast Frames Sent                                         */
    uint32_t      TxPauseFrames;    
    /**< PauseTx Frames Sent                                                */
    uint32_t      TxDeferred;       
    /**< Frames Where Transmission was Deferred                             */
    uint32_t      TxCollision;      
    /**< Total Frames Sent With Collision                                   */
    uint32_t      TxSingleColl;     
    /**< Frames Sent with Exactly One Collision                             */
    uint32_t      TxMultiColl;      
    /**< Frames Sent with Multiple Colisions                                */
    uint32_t      TxExcessiveColl;  
    /**< Tx Frames Lost Due to Excessive Collisions                         */
    uint32_t      TxLateColl;       
    /**< Tx Frames Lost Due to a Late Collision                             */
    uint32_t      TxUnderrun;       
    /**< Tx Frames Lost with Tx Underrun Error                              */
    uint32_t      TxCarrierSLoss;   
    /**< Tx Frames Lost Due to Carrier Sense Loss                           */
    uint32_t      TxOctets;         
    /**< Total Transmitted Bytes in Good Frames                             */
    uint32_t      Frame64;          
    /**< Total Tx&Rx with Octet Size of 64                                  */
    uint32_t      Frame65t127;      
    /**< Total Tx&Rx with Octet Size of 65 to 127                           */
    uint32_t      Frame128t255;     
    /**< Total Tx&Rx with Octet Size of 128 to 255                          */
    uint32_t      Frame256t511;     
    /**< Total Tx&Rx with Octet Size of 256 to 511                          */
    uint32_t      Frame512t1023;    
    /**< Total Tx&Rx with Octet Size of 512 to 1023                         */
    uint32_t      Frame1024tUp;     
    /**< Total Tx&Rx with Octet Size of >=1024                              */
    uint32_t      NetOctets;        
    /**< Sum of all Octets Tx or Rx on the Network                          */
    uint32_t      RxSOFOverruns;    
    /**< Total Rx Start of Frame Overruns                                   */
    uint32_t      RxMOFOverruns;    
    /**< Total Rx Middle of Frame Overruns                                  */
    uint32_t      RxDMAOverruns;    
    /**< Total Rx DMA Overruns                                              */
} EMAC_STATISTICS_T;


/**
 *  @brief  EMAC Statistics for ICSS
 *  The statistics structure is used to retrieve the current count
 *  of various packet events in the PRU-ICSSG system.
 */
 typedef struct EMAC_STATISTICS_ICSSG_tag
 {
    uint32_t      RxGoodFrames;
    /**<RX Good Frame Count Inc on none min err max err crc err odd err, Wrt subtracts           */
    uint32_t      RxBCastFrames;
    /**< RX BC Frame Count Inc on BC type, Wrt subtracts                                         */
    uint32_t      RxMCastFrames;
    /**< RX MC Frame Count Inc on MC type, Wrt subtracts                                         */
    uint32_t      RxCRCErrors;
    /**< RX CRC Err Frame Count Inc on crc err, Wrt subtracts                                    */
    uint32_t      RxMIIErrors;
    /**< RX MII Err Frame Count Inc on mii sgmii rgmii err, Wrt subtracts                        */
    uint32_t      RXOddNibbleFrame;
    /**< RX Odd Nibble Frame Count Inc on odd nibble mii, Wrt subtracts                          */
    uint32_t      RXMaxSizeFrame;
    /**< RX Max Size Frame Count Limit                                                           */
    uint32_t      RXMaxSizeErrFrame;
    /**< RX MAX Size Err Frame Count Inc if > than Limit, Wrt subtracts                          */
    uint32_t      RXMinSizeFrame;
    /**< RX Min Size Frame Limit                                                                 */
    uint32_t      RXMinSizeErrFrame;
    /**< RX MIN Size Frame Count incremented  if < than limit                                    */
    uint32_t RXoverrunFrame;
     /**<  RX L1 FIFO overflow Frame Count                                                       */
    uint32_t RXClass0;
    /**< RX Class0 Hit Count                                                                     */
    uint32_t RXClass1;
    /**< RX Class1 Hit Count                                                                     */
    uint32_t RXClass2;
    /**< RX Class2 Hit Count                                                                     */
    uint32_t RXClass3;
    /**< RX Class3 Hit Count                                                                     */
    uint32_t RXClass4;
    /**< RX Class4 Hit Count                                                                     */
    uint32_t RXClass5;
    /**< RX Class5 Hit Count                                                                     */
    uint32_t RXClass6;
    /**< RX Class6 Hit Count                                                                     */
    uint32_t RXClass7;
    /**< RX Class7 Hit Count                                                                     */
    uint32_t RXClass8;
    /**< RX Class8 Hit Count                                                                     */
    uint32_t RXClass9;
    /**< RX Class9 Hit Count                                                                     */
    uint32_t RXClass10;
    /**< RX Class10 Hit Count                                                                    */
    uint32_t RXClass11;
    /**< RX Class11 Hit Count                                                                    */
    uint32_t RXClass12;
    /**< RX Class12 Hit Count                                                                    */
    uint32_t RXClass13;
    /**< RX Class13 Hit Count                                                                    */
    uint32_t RXClass14;
    /**< RX Class14 Hit Count                                                                    */
    uint32_t RXClass15;
    /**< RX Class15 Hit Count                                                                    */
    uint32_t RXSMDFragErr;
    /**< SMD FRAG  Frames Received with Errors                                                   */
    uint32_t RXBucket1SizeConfig;
    /**< RX Bucket1 Byte Size                                                                    */
    uint32_t RXBucket2SizeConfig;
    /**< RX Bucket2 Byte Size                                                                    */
    uint32_t RXBucket3SizeConfig;
    /**< RX Bucket3 Byte Size                                                                    */
    uint32_t RXBucket4SizeConfig;
    /**< RX Bucket4 Byte Size                                                                    */
    uint32_t RX64BSizedFrame;
    /**< RX 64Byte Frame Count                                                                   */
    uint32_t RXBucket1SizedFrame;
    /**< RX Bucket1 Frame Count Inc if <= than Bucket1 Byte Size                                 */
    uint32_t RXBucket2SizedFrame;
    /**< RX Bucket2 Frame Count Inc if <= than Bucket2 Byte Size and if > than Bucket1 Byte Size */
    uint32_t RXBucket3SizedFrame;
    /**< RX Bucket3 Frame Count Inc if <= than Bucket3 Byte Size and if > than Bucket2 Byte Size */
    uint32_t RXBucket4SizedFrame;
    /**< RX Bucket4 Frame Count Inc if <= than Bucket4 Byte Size and if > than Bucket3 Byte Size */
   uint32_t RXBucket5SizedFrame;
    /**< RX Bucket5 Frame Count Inc if > than Bucket4 Byte Size                                  */
    uint32_t RXTotalByte;
    /**< RX Total Byte Count                                                                     */
    uint32_t RX_TX_TotalByte;
    /**< RX and TX Total Byte Count                                                              */
    uint32_t      TXGoodFrame;
    /**< TX Good Frame Count Inc if no min size err max size err or mii odd nibble               */
    uint32_t      TXBCFrame;
    /**< TX BC Frame Count Inc if BC                                                             */
    uint32_t      TXMCFrame;
    /**< TX MC Frame Count Inc if MC                                                             */
    uint32_t      TXOddNibbleFrame;
    /**< TX Odd Nibble Frame Count Inc if mii odd nibble                                         */
    uint32_t    TXUnderFlowErr;
    /**< TX MAX Underflow Error Cnt                                                              */
    uint32_t    TXMaxSizeFrame;
    /**< TX MAX Size Frame Count Limit                                                           */
    uint32_t    TXMaxSizeErrFrame;
    /**< TX MAX Size Err Frame Count Inc if > max Limit                                          */
    uint32_t    TXMinSizeFrame;
    /**< TX MIN Size Frame Count Limit                                                           */
    uint32_t    TXMinSizeErrFrame;
    /**< TX MIN Size Err Frame Count Inc if < min Limit                                          */
    uint32_t    TXBucket1SizeConfig;
    /**< TX Bucket1 Byte Size                                                                    */
    uint32_t    TXBucket2SizeConfig;
    /**< TX Bucket2 Byte Size                                                                    */
    uint32_t    TXBucket3SizeConfig;
    /**< TX Bucket3 Byte Size                                                                    */
    uint32_t    TXBucket4SizeConfig;
    /**< TX Bucket4  Byte Size                                                                   */
    uint32_t    TX64BSizedFrame;
    /* TX 64Byte Frame Count Inc if 64B                                                          */
    uint32_t    TXBucket1SizedFrame;
    /* TX Bucket1 Frame Count if <= than Bucket1                                                 */
    uint32_t    TXBucket2SizedFrame;
    /* TX Bucket2 Frame Count if <= than Bucket2 Size  and > Bucket 1 Size                       */
    uint32_t    TXBucket3SizedFrame;
    /* TX Bucket3 Frame Count if <= than Bucket3 Size and > Bucket 2 Size                        */
    uint32_t    TXBucket4SizedFrame;
     /* TX Bucket4 Frame Count if <= than Bucket4 Size and > Bucket 3 Size                       */
    uint32_t    TXBucket5SizedFrame;
     /* TX Bucket5 Frame Count uf >Bucket 4 Size                                                 */
    uint32_t    TXTotalByte;
    /**< Total Bytes  Sent                                                                       */

} EMAC_STATISTICS_ICSSG_T;


/**
 * @brief type of EMAC port link status
 */
typedef uint32_t EMAC_LinkStatus_T;
#define EMAC_LINKSTATUS_NOLINK          ((uint32_t)0U)
/**< Link Status: No Link                                                   */
#define EMAC_LINKSTATUS_HD10            ((uint32_t)2U)
/**< Link Status: Half Duplex 10Mbps                                        */
#define EMAC_LINKSTATUS_FD10            ((uint32_t)3U)
/**< Link Status: Full Duplex 10Mbps                                        */
#define EMAC_LINKSTATUS_HD100           ((uint32_t)4U)
/**< Link Status: Half Duplex 100Mbps                                       */
#define EMAC_LINKSTATUS_FD100           ((uint32_t)5U)
/**< Link Status: Full Duplex 100Mbps                                       */
#define EMAC_LINKSTATUS_FD1000          ((uint32_t)7U)
/**< Link Status: Full Duplex 1000Mbps                                      */

typedef EMAC_LinkStatus_T EMAC_LINK_STATUS_T;

/**
 * @brief EMAC statistics and link status data structure
 *
 */
typedef struct EMAC_LinkInfo_s
{
    bool                    link_status_change;
    /**< True: link status changed, False: link status is not changed       */
    EMAC_LINK_STATUS_T      link_status;
    /**< PHY link status, only valid when link_status_change is TRUE        */

} EMAC_LinkInfo;

typedef EMAC_LinkInfo EMAC_LINK_INFO_T;


/**
 * @ingroup emaclld_api_constants
 * @brief EMAC IOCTL commands to be sued when calling calling @ref emac_ioctl API.
  */
typedef enum EMAC_IOCTL_CMD_E{
    EMAC_IOCTL_PROMISCOUS_MODE_CTRL,        /**< Promiscous mode enable/disable control ioctl*/
    EMAC_IOCTL_VLAN_CTRL,                   /**< VLAN control ioctl */
    EMAC_IOCTL_PORT_STATE_CTRL,             /**< PORT State control ioctl */
    EMAC_IOCTL_FDB_ENTRY_CTRL,              /**< FDB Entry ioctl */
    EMAC_IOCTL_PORT_PRIO_MAPPING_CTRL,      /**< Configure traffic class mapping to port queue ioctl */
    EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, /**< Configure Acceptable frame check control ioctl */
    EMAC_IOCTL_PRIO_REGEN_CTRL,             /**< Configure priority regen table ioctl*/
    EMAC_IOCTL_TEST_MULTI_FLOW,             /**< Test multi-flow support ioctl */
    EMAC_IOCTL_UC_FLOODING_CTRL,            /**< UC flooding control ioctl */
    EMAC_IOCTL_INTERFACE_MAC_CONFIG,        /**< interface mac config ioctl */
    EMAC_IOCTL_CUT_THROUGH_PREEMPT_SELECT,  /**< cut through or prempt select config ioctl */
    EMAC_IOCTL_SPECIAL_FRAME_PRIO_CONFIG,   /**< special packets default prio config ioctl */
    EMAC_IOCTL_FRAME_PREEMPTION_CTRL,       /**< premption control config ioctl */
    EMAC_IOCTL_FDB_AGEING_TIMEOUT_CTRL,     /**< configure FDB ageing timeout ioctl*/
    EMAC_IOCTL_SPEED_DUPLEXITY_CTRL        /**< configure link speed and duplexity ioctl */

} EMAC_IOCTL_CMD;

/**
 * @ingroup emaclld_api_structures
 * @brief IOCTL parameters field of @ref emac_ioctl API
 *
 * @details Specififies IOCTL command parameters
 */
typedef struct EMAC_IOCTL_PARAMS_S {
    uint32_t subCommand;            
    /**< optional sub-command for IOCTL command */
    uint8_t  seqNumber;             
    /**< required for asyncrnonuos IOCTL commands only, allows application to correlate
         IOCTL request and response, returned in IOCTL response to appliation*/
    void *ioctlVal;
    /**< IOCTL specific configuration structure */
} EMAC_IOCTL_PARAMS;

/*!
 *  @brief  Retrieves the version ID string.
 *
 *  @return Pointer of the version ID string
 */
const char*emac_get_version(void);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Opens and configures an EMAC port.
 *
 *     The calling application must supply a valid port number and open configuration
 *     data. After the port is opened successfully, the application will need to set 
 *     the RX filter configuration.
 *
 *     When a core is MASTER_CORE, the driver will do the common configurations
 *     of the port only when the port is first opened. The driver will do the channel 
 *     specific configurations for all the cores. 
 *
 *     In the open configuration, the alloc_pkt call back function will allow the 
 *     application to get a packet descriptor with allocated packet buffer, the 
 *     rx_pkt call back function will allow the application to enqueue received 
 *     packet to the application RX queue for post processing. The free_pkt 
 *     call back function will allow the application to free the packet buffer 
 *     when a packet is sent successfully .
 *
 *     The driver passes the channels assigned to the port to the
 *     application layer when the port is opened successfully.
 *
 *  @param  port_num      EMAC port number
 *  @param  p_config         Pointer to EMAC open config data
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 * 
 *  @pre    none
 */
EMAC_DRV_ERR_E
emac_open
(
    uint32_t                      port_num,
    EMAC_OPEN_CONFIG_INFO_T*    p_config
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Closes an opened EMAC port.
 *
 *     The driver closes the opened port and disables the RX/TX interrupts.
 *     The driver closes all the TX/RX channels allocated for this port
 *
 *  @param  port_num      EMAC port number
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open must be called prior to calling this API

 */

EMAC_DRV_ERR_E
emac_close
(
    uint32_t                  port_num
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Configures an opend EMAC port.
 *
 *     The driver configures the opened port, e.g. RX filter, etc.
 *
 *     For RX multicast configuration, this API is called to install a list 
 *     of multicast addresses for use in multicast address filtering. The new
 *     multicast list will replace the old multicast configuration. Thus
 *     a set with a list size of zero will remove all multicast addresses from 
 *     the device.
 *
 *     Note that the multicast list configuration is stateless in that the
 *     list of multicast addresses used to build the configuration is not
 *     retained. Thus it is impossible to examine a list of currently installed
 *     addresses.
 *
 *  @param  port_num      EMAC port number
 *  @param p_config       Pointer to EMAC  config data
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 * 
 *  @pre    emac_open must be called prior to calling this API
 *  @note: Currently not supported for am65xx SOC
 */

EMAC_DRV_ERR_E
emac_config
(
    uint32_t                  port_num,
    EMAC_CONFIG_INFO_T*     p_config
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Sends a packet on an opened EMAC port.
 *
 *     The calling application must supply a valid port number. The free_pkt 
 *     call back function will allow the application to free the packet buffer 
 *     when a packet is sent successfully .
 *
 *  @param  port_num      EMAC port number
 *  @param  p_desc        Pointer to a TX packet descriptor
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open and emac_poll_ctrl must be called prior to calling this API
 */

EMAC_DRV_ERR_E
emac_send
(
    uint32_t                  port_num,
    EMAC_PKT_DESC_T*        p_desc
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Polls the link status infomation on an opened EMAC port.
 *
 *     The calling application must supply a valid port number and the driver
 *     will return the link info to the application when called successfully .
 *
 *  @param  port_num      EMAC port number
 *  @param  p_info        Pointer to a EMAC_LINK_INFO_T to be populated by driver
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open must be called prior to calling this API
 */
EMAC_DRV_ERR_E
emac_poll
(
    uint32_t                  port_num,
    EMAC_LINK_INFO_T*       p_info
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief   Polls for received packets for port-number specified
 *
 *     The calling application must supply a valid port number.
 *
 *  @param  port_num      EMAC port number
 *
 *  @return None
 *
 *  @pre    emac_open must be called prior to calling this API
 */

EMAC_DRV_ERR_E
emac_poll_pkt
(
    uint32_t                  port_num
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Retrieve the statistics on an opened EMAC port.
 *
 *     The calling application must supply a valid port number.
 *
 *  @param  port_num      EMAC port number
 *  @param  p_stats      Pointer to  port number EMAC_STATISTICS_T to be populated by driver
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open must be called prior to calling this API
 */
EMAC_DRV_ERR_E
emac_get_statistics
(
    uint32_t                  port_num,
    EMAC_STATISTICS_T*      p_stats
);

/*!
 *  @brief  Services RX or TX interrupt for an opened EMAC port.
 *
 *     The calling application must supply a valid port number and RX/TX flag.
 *     The driver will service the interrupt and call back to application layer
 *     when there is a packet received.
 *
 *  @param  port_num      EMAC port number
 *
 *  @param  rx_flag      URE: RX interrupt; FALSE: TX interrupt
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success,EMAC_DRV_RESULT_ISR_ERR on failure
 *
 *  @pre    emac_open must be called prior to calling this API
 */

EMAC_DRV_ERR_E
emac_int_service
(
    uint32_t                  port_num,
    bool                      rx_flag
);


/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  Retrieve the statistics on an opened EMAC ICSSG port.
 *
 *     The calling application must supply a valid port number.
 *
 *  @param  port_num     EMAC ICSSG port number
 *  @param  p_stats      Pointer to  port number EMAC_STATISTICS_ICSSG_T to be populated by driver
 *  @param clear         clear statistics is set to TRUE
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open must be called prior to calling this API
 */
EMAC_DRV_ERR_E
emac_get_statistics_icssg
(
    uint32_t                  port_num,
    EMAC_STATISTICS_ICSSG_T*  p_stats,
    bool clear
);


/*!
 *  @ingroup emaclld_api_functions 
 *  @brief  API to configure various CPSW and ICSS EMAC Functionalities.
 *
 *     The calling application must supply a valid port number, IOCTL command 
 *     and IOCTL parameters.
 *
 *  @param  port_num        EMAC ICSSG port number
 *  @param  emacIoctlCmd    IOCTL Command @ref EMAC_IOCTL_CMD_E
 *  @param emacIoctlParams  IOCTL parameter @ref EMAC_IOCTL_PARAMS
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
  *  @pre    emac_open and emac_poll_ctrl must be called prior to calling this API
 */

EMAC_DRV_ERR_E
emac_ioctl
(
    uint32_t                  port_num,
    EMAC_IOCTL_CMD            emacIoctlCmd,
    EMAC_IOCTL_PARAMS         *emacIoctlParams
);

/*!
 *  @ingroup emaclld_api_functions 
 *  @brief   Polls UDMA rings for specified by requested ring parameters.
 *
 *     The calling application must supply a valid port number and ring bitmaps
 *
 *  @param  port_num      EMAC port number
 *  @param  rxPktRings    Bit map of receive packet rings to poll
 *  @param  rxCfgRings    Bit map of receive management rings to poll
 *  @param  txRings       Bit map of tx completion rings to poll
 *
 *  @return Returns EMAC_DRV_RESULT_OK on success, EMAC_DRV_ERR_E type on failure
 *
 *  @pre    emac_open must be called prior to calling this API
 */

EMAC_DRV_ERR_E
emac_poll_ctrl
(
    uint32_t                  port_num,
    uint32_t                  rxPktRings, 
    uint32_t                  rxCfgRings,
    uint32_t                  txRings
);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_open().
 */

typedef EMAC_DRV_ERR_E (*EMAC_OpenFxn)           (uint32_t port_num,
                                                                             EMAC_OPEN_CONFIG_INFO_T *p_config);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_config().
 */

typedef EMAC_DRV_ERR_E (*EMAC_ConfigFxn)           (uint32_t port_num,
                                                                             EMAC_CONFIG_INFO_T *p_config);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_CloseFxn().
 */
typedef EMAC_DRV_ERR_E      (*EMAC_CloseFxn)           (uint32_t port_num);
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_SendFxn().
 */
typedef EMAC_DRV_ERR_E        (*EMAC_SendFxn)           (uint32_t port_num, 
                                            EMAC_PKT_DESC_T* p_desc);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_PollFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_PollFxn)       (uint32_t port_num,
                        EMAC_LINK_INFO_T* p_info);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_GetStatsFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_GetStatsFxn)        (uint32_t port_num,
                        EMAC_STATISTICS_T*      p_stats);


/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_PollPktFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_PollPktFxn)       (uint32_t port_num);


/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_GetStatsIcssgFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_GetStatsIcssgFxn)        (uint32_t port_num,
                        EMAC_STATISTICS_ICSSG_T*      p_stats, bool clear);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_IoctlFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_IoctlFxn)        (uint32_t port_num,
                        EMAC_IOCTL_CMD emacIoctlCmd, EMAC_IOCTL_PARAMS *emacIoctlParams);


/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              EMAC_PollCtrlFxn().
 */
typedef EMAC_DRV_ERR_E     (*EMAC_PollCtrlFxn)        (uint32_t port_num,
                        uint32_t rxPktRings, uint32_t rxCfgRings, uint32_t txRings);

/*!
 *  @brief      The definition of a EMAC function table that contains the
 *              required set of functions to control a specific EMAC driver
 *              implementation.
 */
typedef struct EMAC_FxnTable_s {
    /*! Function to open the specified EMAC port */
    EMAC_OpenFxn           openFxn;
   /*! Function to config the specified EMAC port for RX filtering, multicast addresses */
    EMAC_ConfigFxn           configFxn;
    /*! Function to close the specified peripheral */
    EMAC_CloseFxn           closeFxn;
    /*! Function to send packet to network on specified EMAC port */
    EMAC_SendFxn            sendFxn;
    /*! Function to poll link status for specified EMAC port*/
    EMAC_PollFxn     pollFxn;
    /*! Function to get EMAC port statistics*/
    EMAC_GetStatsFxn     getStatsFxn;
    /*! Function to poll for receive packets  specified EMAC port*/
    EMAC_PollPktFxn     pollPktFxn;
    /*! Function to get EMAC ICSSG port statistics, only supportf for am65xx SOC*/
    EMAC_GetStatsIcssgFxn     getStatsIcssgFxn;
    /*! Function to send IOCTL command for specified port, only supportf for am65xx SOC*/
    EMAC_IoctlFxn       ioctlFxn;
    /*! Function to Poll the driver for specified flow/rings, only supportf for am65xx SOC*/
    EMAC_PollCtrlFxn       pollCtrl;

} EMAC_FxnTable;

/*! @brief EMAC configuration */
typedef struct EMAC_Config_s {
    /*! Pointer to a table of a driver-specific implementation of EMAC functions */
    EMAC_FxnTable const    *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;
} EMAC_Cfg;

typedef EMAC_Cfg EMAC_config_list[2];


/*!
 *  @cond NODOC
 *  Internally used by the driver bit shift
 */
#define EMAC_BIT(x) (((uint32_t)1U) << (x))
/*! @endcond */


#ifdef __cplusplus
}
#endif
#endif /* EMAC_DRV_H_ */
