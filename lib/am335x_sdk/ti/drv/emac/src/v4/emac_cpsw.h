/**
 *   @file  emac_cpsw.h
 *   @brief
 *      Include file for CPSW   functions for EMAC
 */

/* Copyright (C) {2016-2017} Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef EMAC_CPSW_H
#define EMAC_CPSW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/hw_types.h>
#include <ti/csl/tistdtypes.h>
#include <ti/board/src/idkAM572x/device/enet_phy.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v4.h>


typedef void*       Handle;

#define EMAC_PORT_1                                   0x0U
#define EMAC_PORT_2                                   0x1U

/* MDIO input and output frequencies in Hz */
#define MDIO_FREQ_INPUT                          125000000U
#define MDIO_FREQ_OUTPUT                         1000000U

#define EMAC_BUF_DESC_OWNER                     ((uint32_t)0x20000000U)

#define EMAC_PKT_FLAG_EOQ                       ((uint32_t)0x10000000U)


#define LEN_MAC_ADDRESS         6U

#define EMAC_PHY_HALF_DUPLEX_MODE 0x0U

#define EMAC_PHY_FULL_DUPLEX_MODE 0x1U

#define EMAC_PHY_GIGABIT_MODE 0x2U

/* CPDMA teardown acknowledgement value */
#define EMAC_TEARDOWN_DESC  ((uint32_t)0xFFFFFFFCU)
/*
** Macros which can be passed as 'portState' to CPSWALEPortStateSet
*/
#define CPSW_ALE_PORT_STATE_FWD                (0x03U)
#define CPSW_ALE_PORT_STATE_LEARN              (0x02U)
#define CPSW_ALE_PORT_STATE_BLOCKED            (0x01U)
#define CPSW_ALE_PORT_STATE_DISABLED           (0x00U)


/**
 *  \defgroup   EMACDevice  EMAC
 *
 *  Constants, objects and interfaces for EMAC
 *  @{
 */
/**
 *  \defgroup   EMACConstants   EMAC Constants
 *  @{
 */

/* Board Specific Parameters
 *
 */
#define CPSW3G_MAX_INSTANCES                1U           /**< Max CPSW3G instances */
#define CPMAC_MIN_ETHERNET_PKT_SIZE         60U          /**< Minimum Ethernet packet size */

/*Default values for IDK    */
#define CPSW3G_DEFAULT_PORT_NO                30U
#define CPSW3G_DEFAULT_NUM_MAC_PORTS        1U           /**< MAC Port Count */
#define CPSW3G_DEFUAULT_MAC_MODE             (EMAC_CPSW_CONFIG_MODEFLG_GIGABIT | EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX)

#define CPSW3G_NUM_MAC_PORTS                2U
#define CPSW3G_NUM_PORTS                    3U


/*Use PHY1 or PHY0 on PG2.1*/

#define EMAC_CPDMA_MAX_CHANNELS                  8U           /**< Maximum num of channels supported by the DMA */

#define EMAC_CPSW3G_NUM_STAT_REGS                36U
#define CPSW3G_STAT_CLEAR                   0xFFFFFFFFU

#define CPDMA_MAX_DIR                       2U           /**< Number of DMA data directions (tx and rx) */


#define CPSW_NET_CH_DIR_TX                       0U
#define CPSW_NET_CH_DIR_RX                       1U


/**
 *  \defgroup   aleModeFlags Configuration Flags for ALE
 *
 * @{
 */
#define CPSW_CONFIG_ALE_ENABLE              ((uint32_t)0x00001U)
/**< Enable ALE                                                             */
#define CPSW_CONFIG_ALE_CLRTABLE            ((uint32_t)0x00002U)
/**< Clear ALE Address table.                                               */
#define CPSW_CONFIG_ALE_AGEOUTNOW           ((uint32_t)0x00004U)

/**
 *  \defgroup   cpswStatModeFlags Configuration Flags for CPSW STAT
 *
 * @{
 */
#define CPSW_CONFIG_STAT_ENABLE                ((uint32_t)0x00001U)

/**
 *  \defgroup   mdioModeFlags  MDIO Configuration Mode Flags
 *
 *  These flags determine how the MDIO module behaves
 *  @{
 */
#define CPSW_MDIO_MODEFLG_AUTONEG                ((uint32_t)0x0001U)
/**< Use Autonegotiation                                                    */

/* The following bits are used for manual and fallback configuration        */
#define CPSW_MDIO_MODEFLG_HD10                   ((uint32_t)0x0002U)
/**< Use 10Mb/s Half Duplex                                                 */
#define CPSW_MDIO_MODEFLG_FD10                   ((uint32_t)0x0004U)
/**< Use 10Mb/s Full Duplex                                                 */
#define CPSW_MDIO_MODEFLG_HD100                  ((uint32_t)0x0008U)
/**< Use 100Mb/s Half Duplex                                                */
#define CPSW_MDIO_MODEFLG_FD100                  ((uint32_t)0x0010U)
/**< Use 100Mb/s Full Duplex                                                */
#define CPSW_MDIO_MODEFLG_FD1000                 ((uint32_t)0x0020U)
/**< Use 1000Mb/s Full Duplex                                               */
#define CPSW_MDIO_MODEFLG_LOOPBACK               ((uint32_t)0x0040U)
/**< Use internal PHY Loopback                                              */
#define CPSW_MDIO_MODEFLG_NOPHY                  ((uint32_t)0x0080U)
/**< Use external SMA connectors instead of PHY                             */


/* @} */

/**
 *  \defgroup   Descriptor memory selection Flags
 *
 * @{
 */
#define CPSW_DESC_BASE_L2                   0x00001U
/**< Use L2 as Descriptor memory                                            */
#define CPSW_DESC_BASE_CPPI                 0x00002U
/**< Use CPPI RAM as desriptor memory                                       */
#define CPSW_DESC_BASE_DDR                  0x00004U
/**< Use DDR as descriptor memory                                           */

/**
 *  \defgroup   ErrCodes    STANDARD ERROR CODES
 *  @{
 */

/** Internal functions return error codes */
#define CPSW3G_INSTANCE_CODE                        ((uint32_t)0U)
#define CPSW3G_ERROR_BASE                           ((uint32_t)(0x200001FU))

#define CPSW3G_ERROR_CODE                           ((CPSW3G_ERROR_BASE | (CPSW3G_INSTANCE_CODE << 16U)))
#define CPSW3G_ERROR_INFO                           (CPSW3G_ERROR_CODE)
#define CPSW3G_ERROR_WARNING                        (CPSW3G_ERROR_CODE | 0x10000000U)
#define CPSW3G_ERROR_MINOR                          (CPSW3G_ERROR_CODE | 0x20000000U)
#define CPSW3G_ERROR_MAJOR                          (CPSW3G_ERROR_CODE | 0x30000000U)
#define CPSW3G_ERROR_CRITICAL                       (CPSW3G_ERROR_CODE | 0x40000000U)

/* CPMAC Success code */
#define CPSW3G_SUCCESS                              ((uint32_t)0U)

/* CPSW3G Error codes */
#define CPSW3G_ERR_DEV_ALREADY_INSTANTIATED(instID) (((uint32_t)0x30000000U) + CPSW3G_ERROR_BASE + ((instId) << ((uin32_t)16U)))
/**< Device with same instance ID already created.                          */
#define CPSW3G_ERR_DEV_NOT_INSTANTIATED             (CPSW3G_ERROR_MAJOR + 1U)
/**< Device is not instantiated yet.                                        */
#define CPSW3G_INVALID_PARAM                        (CPSW3G_ERROR_MAJOR + 2U)
/**< Function or calling parameter is invalid                               */
#define CPSW3G_ERR_CH_INVALID                       (CPSW3G_ERROR_CRITICAL + 3U)
/**< Channel number invalid                                                 */
#define CPSW3G_ERR_CH_ALREADY_INIT                  (CPSW3G_ERROR_MAJOR + 4U)
/**< Channel already initialized and setup                                  */
#define CPSW3G_ERR_TX_CH_ALREADY_CLOSED             (CPSW3G_ERROR_MAJOR + 5U)
/**< Tx Channel already  closed. Channel close failed                       */
#define CPSW3G_ERR_TX_CH_NOT_OPEN                   (CPSW3G_ERROR_MAJOR + 6U)
/**< Tx Channel not open.                                                   */
#define CPSW3G_ERR_TX_NO_LINK                       (CPSW3G_ERROR_MAJOR + 7U)
/**< Tx Link not up.                                                        */
#define CPSW3G_ERR_TX_OUT_OF_BD                     (CPSW3G_ERROR_MAJOR + 8U)
/**< Tx ran out of Buffer descriptors to use.                               */
#define CPSW3G_ERR_RX_CH_INVALID                    (CPSW3G_ERROR_CRITICAL + 9U)
/**< Rx Channel invalid number.                                             */
#define CPSW3G_ERR_RX_CH_ALREADY_INIT               (CPSW3G_ERROR_MAJOR + 10U)
/**< Rx Channel already setup.                                              */
#define CPSW3G_ERR_RX_CH_ALREADY_CLOSED             (CPSW3G_ERROR_MAJOR + 11U)
/**< Rx Channel already closed. Channel close failed.                       */
#define CPSW3G_ERR_RX_CH_NOT_OPEN                   (CPSW3G_ERROR_MAJOR + 12U)
/**< Rx Channel not open yet.                                               */

#define CPSW3G_ERR_DEV_ALREADY_CREATED              (CPSW3G_ERROR_MAJOR + 13U)
/**< EMAC device already created.                                           */
#define CPSW3G_ERR_DEV_NOT_OPEN                     (CPSW3G_ERROR_MAJOR + 14U)
/**< Device is not open or not ready                                        */
#define CPSW3G_ERR_DEV_ALREADY_CLOSED               (CPSW3G_ERROR_MAJOR + 15U)
/**< Device close failed. Device already closed.                            */
#define CPSW3G_ERR_DEV_ALREADY_OPEN                 (CPSW3G_ERROR_MAJOR + 16U)
/**< Device open failed. Device already open.                               */
#define CPSW3G_ERR_RX_BUFFER_ALLOC_FAIL             (CPSW3G_ERROR_CRITICAL +17U)
/**< Rx Buffer Descriptor allocation failed.                                */
#define CPSW3G_INTERNAL_FAILURE                     (CPSW3G_ERROR_MAJOR + 18U)
/**< EMAC Internal failure.                                                 */
#define CPSW3G_VLAN_UNAWARE_MODE                    (CPSW3G_ERROR_MAJOR + 19U)
/**< VLAN support not enabled in EMAC                                       */
#define CPSW3G_ALE_TABLE_FULL                       (CPSW3G_ERROR_MAJOR + 20U)
/**< ALE Table full.                                                        */
#define CPSW3G_ADDR_NOTFOUND                        (CPSW3G_ERROR_MAJOR + 21U)
/**< Multicast/Unicast/OUI Address not found in ALE.                        */
#define CPSW3G_INVALID_VLANID                       (CPSW3G_ERROR_MAJOR + 22U)
/**< Invalid VLAN Id.                                                       */
#define CPSW3G_INVALID_PORT                         (CPSW3G_ERROR_MAJOR + 23U)
/**< Invalid Port Specified.                                                */
#define CPSW3G_BD_ALLOC_FAIL                        (CPSW3G_ERROR_MAJOR + 24U)
/**< Buffer Descriptor Allocation failure. OOM                              */
#define CPSW3G_ERR_BADPACKET                        (CPSW3G_ERROR_MAJOR + 25U)
/**< Supplied packet was invalid                                            */
#define CPSW3G_ERR_MACFATAL                         (CPSW3G_ERROR_CRITICAL + 26U)
/**< Fatal Error - EMAC_cpswClose() required                                    */
/* @} */
#define CPSW_DEVMAGIC                       0x0aceface
/**< Device Magic number                                                    */
#define CPSW_HANDLE_VALUE                    0x12345678U
/**< Device Handle Value                                                    */
#define CPSW_NUMSTATS                       36U
/**< Number of statistics regs                                              */

/* Control Codes for internal control function*/
#define CPSW3G_PHY_STATUS_UPDATE            0U

/**
 * @brief
 *  EMAC_PKT_QUEUE_T Queue Data Structure
 *
 * @details
 *  Maintains the count of queued elements and head and tail to EMAC_PKT_QUEUE_T queue.
 */
typedef struct EMAC_PktQueue_s {
    /**
     * @brief   Number of packets in queue
     */
    uint32_t                Count;

    /**
     * @brief   Pointer to first packet
     */
    EMAC_PKT_DESC_T          *pHead;

    /**
     * @brief   Pointer to last packet
     */
    EMAC_PKT_DESC_T          *pTail;
} EMAC_PktQueue;


typedef EMAC_PktQueue EMAC_PKT_QUEUE_T;

/**
 * @brief
 *  EMAC Buffer descriptor format.
 *
 * @details
 *  The following is the format of a single buffer descriptor
 *  on the EMAC.
 */
typedef struct EMAC_Desc_s
{
    /**
    * @brief        Pointer to next descriptor in chain.
    */
    struct EMAC_Desc_s *pNext;
    /**
    * @brief        Pointer to data buffer.
    */
    uint8_t             *pBuffer;
    /**
    * @brief        Buffer Offset(MSW) and Length(LSW).
    */
    uint32_t            BufOffLen;
    /**
    * @brief        Packet Flags(MSW) and Length(LSW).
    */
    uint32_t            pktFlgLen;
} EMAC_Desc;
/**
 *  \brief Channel Info structure
 *
 */
typedef struct EMAC_CpswChInfo_s
{
    uint32_t            chNum;
    /**< Channel Number                                                     */
    uint32_t          chDir;
    /**< Channel Direction                                                  */
    uint32_t          numBD;
    /**< Maximum Number of Buffer Descriptors allocated for this channel    */
    uint32_t          bufSize;
    /**< Buffer size                                                        */
}EMAC_CpswChInfo;


/**
 *  \brief Transmit/Receive Descriptor Channel Structure
 *
 *  (One receive and up to 8 transmit in this example)
 */
typedef struct EMAC_DescCh_s {
    struct EMAC_Cpsw3gDevice_s *pd;
    /**< Pointer to parent structure                                        */
    EMAC_PKT_QUEUE_T            DescQueue;
    /**< Packets queued as desc                                             */
    EMAC_PKT_QUEUE_T            WaitQueue;
    /**< Packets waiting for TX desc                                        */
    EMAC_CpswChInfo    *chInfo;
    /**< Channel info                                                       */
    uint32_t          DescMax;
    /**< Max number of desc (buffs)                                         */
    uint32_t          DescCount;
    /**< Current number of desc                                             */
    EMAC_Desc       *pDescFirst;
    /**< First desc location                                                */
    EMAC_Desc       *pDescLast;
    /**< Last desc location                                                 */
    EMAC_Desc       *pDescRead;
    /**< Location to read next desc                                         */
    EMAC_Desc       *pDescWrite;
    /**< Location to write next desc                                        */
    uint32_t      dmaInProgress;
    /* Flag to indicate DMA transaction is in progress */
} EMAC_DescCh;

/**
 *  \brief Port structure
 *
 */
typedef struct EMAC_Cpsw3GPort_s
{
  uint32_t            portNum;
  /**< Port number 0-2                                                  */
  uint32_t            chNum;
  /**< Ch number 0-7 (currently unused - may not need it)               */
} EMAC_Cpsw3GPort;

/**
 *  \brief  Gigabit MAC Info Instance Structure
 *
 */
typedef struct EMAC_CPGMacObj_s
{
    /**< MII-MDIO module device structure */
    ENETPHY_DEVICE  PhyDev;
    /**< State of each port */
    uint32_t          portState;
    /**< Link status: 1=Linked, 0=No link */
    uint32_t          PhyLinked;
    /**< Duplex status: 1=Full Duplex, 0=Half Duplex */
    uint32_t          PhyDuplex;
    /**< Link Speed = 2= 1000 mbps, 1= 100 mbps, 0= 10 mbps */
    uint32_t          PhySpeed;
    /**< Phy number - useful if phy number is discovered                */
    uint32_t          PhyNum;
    /**< Flag to indicate if this is an internal PHY                    */
    bool            intPhy;
}EMAC_CPGMacObj;

/**
 *  \brief  CPDMA CPPI 3.0 Compliant Interface Instance Structure
 *
 */
typedef struct EMAC_CpdmaObj_s
{
    EMAC_DescCh  txCppi[EMAC_CPDMA_MAX_CHANNELS];
    /**< Tx Control struct ptrs                                         */
    EMAC_DescCh  rxCppi[EMAC_CPDMA_MAX_CHANNELS];
    /**< Rx Control struct ptrs                                         */
    bool            chIsInit[CPDMA_MAX_DIR][EMAC_CPDMA_MAX_CHANNELS];
    /**< channel initialized ?                                          */
    bool            chIsOpen[CPDMA_MAX_DIR][EMAC_CPDMA_MAX_CHANNELS];
    /**< channel open ?                                                 */
    bool            tdPending[CPDMA_MAX_DIR][EMAC_CPDMA_MAX_CHANNELS];
    /**< teardown pending ?                                             */
    int32_t             txIntThreshold[EMAC_CPDMA_MAX_CHANNELS];
    /**< TX  Completion Threshold count                                 */
    uint32_t          portState;
    /**< State of each port                                             */

    /* Status related fields */
    uint32_t          hwStatus;
    /**< Either NO_ERROR or combination of error bits from above status codes */
    uint32_t          hwErrInfo;
    /**< If error, contains DMASTATUS register contents                 */
}EMAC_CpdmaObj;

/**
 *  \brief MAC addresses configuration Structure
 *
 */
typedef struct EMAC_CpswAddrConfig_s {
    uint8_t ChannelNum;
    /* Receive Channel number to which the MAC address to be assigned */
    uint8_t Addr[6];
    /* MAC address specific to channel */
} EMAC_CpswAddrConfig;

/**
 *  \brief CPGMAC SL Init Configuration
 *
 *  Configuration information provided during initialization.
 *  The config info can come from various sources - static compiled in info,
 *  boot time (Flash) info etc. Currently static compiled values supported.
 */
typedef struct EMAC_CPGMacConfig_s
{
  uint32_t      PhyMask;
  /**< Phy Mask for this CPMAC Phy                                          */
  uint32_t      MLinkMask;
  /**< MLink Mask for this CPMAC Phy                                        */
  uint32_t      phyMode;
  /**< Phy mode settings - Speed,Duplex                                     */
  uint32_t      macModeFlags;

  /**< Configuation Mode Flags                                              */
  uint32_t      mdioModeFlags;
  /**< MDIO configuration flags for this MAC port                           */
} EMAC_CPGMacConfig;

/**
 *  \brief CPGMAC_SL PHY Status values
 *
 *  Provides PHY status of the device.
 *
 */
typedef struct EMAC_CPGMacStatus_s
{
  uint32_t      PhyLinked;
  /**< Link status: 1=Linked, 0=No link                                     */
  uint32_t      PhyDuplex;
  /**< Duplex status: 1=Full Duplex, 0=Half Duplex                          */
  uint32_t      PhySpeed;
  /**< Link Speed = 2= 1000 mbps, 1= 100 mbps, 0= 10 mbps                   */
  uint32_t      PhyNum;
  /**< Phy number - useful if phy number is discovered                      */
} EMAC_CPGMacStatus;


/**
 *  \brief EMAC CPDMA Init Configuration
 *
 *  Configuration information provided during initialization.
 *  The config info can come from various sources - static compiled in info,
 *  boot time (Flash) info etc. Currently static compiled values supported.
 */
typedef struct EMAC_CpdmaConfig_s
{
  uint8_t         portPri;
  /**< Port VLAN priority (7 is highest)                                    */
  bool          portCfi;
  /**< Port CFI bit                                                         */
  uint32_t        portVID;
  /**< Port CFI bit                                                         */
  uint32_t        rxBufferOffset;
  /**< Receive buffer offset                                                */
  uint32_t        numChannels[CPDMA_MAX_DIR];
  /**< Number of Channels supported in each dir                             */

} EMAC_CpdmaConfig;

/**
 *  \brief EMAC ALE configuration
 *
 *  This data structure contains configuration items related to the
 *  ALE_CONTROL register fields.
 */
typedef struct EMAC_AleConfig_s
{
  /* ALE Control fields                                                     */
  uint32_t        aleModeFlags;
  /**< ALE Prescale                                                         */
  uint32_t        alePrescale;
} EMAC_AleConfig;

/**
 *  \brief EMAC ALE Port configuration
 *
 *  This data structure contains configuration items related to the
 *  ALE_Port_Control register fields.
 */
typedef struct EMAC_AlePortConfig_s
{
  uint32_t         portState;
  /**< Port State: 0-disabled, 1-blocked, 2-learn, 3-forward                */
} EMAC_AlePortConfig;

/**
 *  \brief CPSW configuration
 *
 *  This data structure contains configuration items related to the
 *  CPSW_CONTROL and PTYPE register fields.
 */
typedef struct EMAC_Cpsw3GConfig_s
{
  /* CPSW_CONTROL                                                           */

  /* Stat_Port_en register                                                  */
  uint32_t        cpswStatModeFlags;
  /**< Configuration Mode flags for Switch Stat                             */

  uint32_t        mdioBusFrequency;
  /**< Bus frequency for the MII module                                     */
  uint32_t        mdioClockFrequency;

} EMAC_Cpsw3GConfig;


/**
 *  \brief  NIMU_BaseConfig
 *
 *  The status structure contains information about the Base addresses
 *  for different registers
 *
 *  The following is a short description of the configuration fields:
 *
 *  ss_base -- CPSW_SS Base
 *
 *  mdio_base -- CPSW_MDIO Base
 *
 *  wrpr_base -- CPSW_WR BAse
 */

typedef struct EMAC_BaseConfig_s {
    uint32_t ss_base;
    uint32_t mdio_base;
    uint32_t wrpr_base;
    uint32_t ale_base;
    uint32_t cpdma_base;
    uint32_t cppi_ram_base;
    uint32_t host_port_base;
    uint32_t stat_base;
    uint32_t numPorts;

     /* Slave port information */
     EMAC_CpswPorts port[CPSW3G_NUM_MAC_PORTS];
}EMAC_BaseConfig;



/**
 *  \brief  EMAC_Cpsw3gInitConfig
 *
 *  The config structure defines how the EMAC device should operate. It is
 *  passed to the device when the device is opened, and remains in effect
 *  until the device is closed.
 *
 *  The following is a short description of the configuration fields:
 *
 *  UseMdio      - Uses MDIO configuration if required. In case of SGMII
 *                 MAC to MAC communication MDIO is not required. If this
 *                 field is one (1) configures MDIO
 *                          zero (0) does not configure MDIO
 *
 *  ModeFlags    - Specify the Fixed Operating Mode of the Device:
 *      - EMAC_CONFIG_MODEFLG_CHPRIORITY  - Treat TX channels as Priority Levels
 *                                   (Channel 7 is highest, 0 is lowest)
 *      - EMAC_CONFIG_MODEFLG_MACLOOPBACK - Set MAC in Internal Loopback for
 *                                          Testing
 *      - EMAC_CONFIG_MODEFLG_RXCRC       - Include the 4 byte EtherCRC in RX
 *                                          frames
 *      - EMAC_CONFIG_MODEFLG_TXCRC       - Assume TX Frames Include 4 byte
 *                                          EtherCRC
 *      - EMAC_CONFIG_MODEFLG_PASSERROR   - Receive Error Frames for Testing
 *      - EMAC_CONFIG_MODEFLG_PASSCONTROL - Receive Control Frames for
 *                                          Testing
 *
 *  MdioModeFlags - Specify the MDIO/PHY Operation (See csl_MDIO.H)
 *
 *  TxChannels    - Number of TX Channels to use (1-8, usually 1)
 *
 *  MacAddr       - Device MAC address
 *
 *  RxMaxPktPool  - Max Rx packet buffers to get from pool
 *                  (Must be in the range of 8 to 192)
 *
 *  A list of callback functions is used to register callback functions with
 *  a particular instance of the EMAC peripheral. Callback functions are
 *  used by EMAC to communicate with the application. These functions are
 *  REQUIRED for operation. The same callback table can be used for multiple
 *  driver instances.
 *
 *  The callback functions can be used by EMAC during any EMAC function, but
 *  mostly occur during calls to EMAC_statusIsr() and EMAC_statusPoll().
 *
 *  <b>pfcbGetPacket </b> -  Called by EMAC to get a free packet buffer from
 *                   the application layer for receive data. This function
 *                   should return NULL is no free packets are available.
 *                   The size of the packet buffer must be large enough
 *                   to accommodate a full sized packet (1514 or 1518
 *                   depending on the EMAC_CONFIG_MODEFLG_RXCRC flag), plus
 *                   any application buffer padding (DataOffset).
 *
 *  <b>pfcbFreePacket </b> - Called by EMAC to give a free packet buffer back
 *                   to the application layer. This function is used to
 *                   return transmit packets. Note that at the time of the
 *                   call, structure fields other than pDataBuffer and
 *                   BufferLen are in an undefined state.
 *
 *  <b>pfcbRxPacket </b>   - Called to give a received data packet to the
 *                   application layer. The applicaiton must accept the packet.
 *                   When the application is finished with the packet, it
 *                   can return it to its own free queue. This function also
 *                   returns a pointer to a free packet to replace the received
 *                   packet on the EMAC free list. It returns NULL when no free
 *                   packets are available. The return packet is the same as
 *                   would be returned by pfcbGetPacket. Thus if a newly
 *                   received packet is not desired, it can simply be returned
 *                   to EMAC via the return value.
 *
 *
 *  The hApplication calling calling argument is the application's handle
 *  as supplied to the EMAC device in the EMAC_cpswOpen() function.
 */
typedef struct EMAC_Cpsw3gInitConfig_s {
    uint8_t               CoreNum;
    /**< This member is for core selction to does the EMAC configuration
          i.e user can select the specific core to configure EMAC one time  */
    uint8_t               DescBase;
    uint32_t              PktMTU;
    /**< MTU for the interfaces.                                            */

    /* Port specific items                                                  */
    EMAC_CPGMacConfig     macInitCfg[CPSW3G_NUM_MAC_PORTS];
    /**< CPGMAC SL Init Configuration                                       */
    EMAC_CpdmaConfig         dmaInitCfg;
    /**< DMA Init Configuration                                             */

    /* ALE specific items                                                   */
    EMAC_AleConfig           aleCfg;
    /**< ALE Init Configuration                                             */
    EMAC_AlePortConfig       alePortCfg[CPSW3G_NUM_PORTS];
    /**< ALE Port Configuration                                             */

    /* Switch specific items */
    EMAC_Cpsw3GConfig        cpswCfg;
    /**< This member is for descriptor memory selction to place the EMAC
         descriptors in CPPI RAM or  L2 RAM or DDR memory                   */

    /* Channel configuration - provision is made for max number of channels */
    EMAC_CpswChInfo        chInfo[CPDMA_MAX_DIR][EMAC_CPDMA_MAX_CHANNELS];
    /**< Channel configuration                                              */

    uint32_t              linkSpeed[CPSW3G_NUM_MAC_PORTS];
    /**<Link Speed                                                          */
    uint32_t              linkMode[CPSW3G_NUM_MAC_PORTS];
    /**<Link Mode                                                           */
    uint32_t              linkStatus[CPSW3G_NUM_MAC_PORTS];
    /**<Link Status                                                         */
    uint32_t                aleTicks;
    /**< Ticks for this timer                                               */
    uint32_t                 aleTimerActive;
    /**<ALE ageout timer active?                                            */

    uint8_t               totalNumMacAddrs;
    /**< Total number of MAC addresses to be assigned for all receive channels */
    EMAC_CpswAddrConfig     MacAddr[EMAC_NUM_MAX_MAC_PORTS];
    /**< Mac Addresses structure                                            */
    uint32_t              RxMaxPktPool;
    /**< Max Rx packet buffers to get from pool                             */
    uint32_t              RxFilter;
    /* Receive Filter settings                                              */

    EMAC_BaseConfig baseConfig;
    EMAC_PKT_DESC_T *          (*pfcbGetPacket)(Handle hApplication);

    /**< Get packet call back                                               */
    void                (*pfcbFreePacket)(Handle hApplication, EMAC_PKT_DESC_T*pPacket, uint32_t direction);
    /**< Free packet call back                                              */
    EMAC_PKT_DESC_T *          (*pfcbRxPacket)(Handle hApplication, EMAC_PKT_DESC_T *pPacket);
    /**< Receive packet call back                                           */
} EMAC_Cpsw3gInitConfig;


/**
 *  \brief  EMAC Main Device Instance Structure
 *
 */
typedef struct EMAC_Cpsw3gDevice_s {
    uint32_t              DevMagic;
    /**< Magic ID for this instance                                         */
    Handle              hApplication[CPSW3G_NUM_MAC_PORTS];
    /**< Calling Application's Handle                                       */
    uint32_t              PktMTU;
    /**< Max physical packet size                                           */
    uint32_t              FatalError;
    /**< Fatal Error Code                                                   */

    EMAC_CPGMacObj            cpgmacMac[CPSW3G_NUM_MAC_PORTS];
    /**<CPGMAC MAC Book keeping structures                                  */
    EMAC_CpdmaObj            cpdma;
    /**<CPDMA Book keeping structures                                       */
    EMAC_Cpsw3GPort            cpsw3gPort[CPSW3G_NUM_PORTS];
    /**<Port Mapping structures                                             */

    EMAC_Cpsw3gInitConfig    Config;
    /**< Original User Configuration                                        */

    /**< Current running statistics                                         */
    EMAC_STATISTICS_T Stats;
} EMAC_Cpsw3gDevice;

/** ============================================================================
 *  @n@b  EMAC_cpswOpen()
 *
 *  @b Description
 *  @n Opens the EMAC peripheral at the given physical index and initializes
 *     it to an embryonic state.
 *
 *     The calling application must supply a operating configuration that
 *     includes a callback function table. Data from this config structure is
 *     copied into the device's internal instance structure so the structure
 *     may be discarded after EMAC_cpswOpen() returns. In order to change an item
 *     in the configuration, the EMAC device must be closed and then
 *     re-opened with the new configuration.
 *
 *     The application layer may pass in an hApplication callback handle,
 *     that will be supplied by the EMAC device when making calls to the
 *     application callback functions.
 *
 *     An EMAC device handle is written to phEMAC. This handle must be saved
 *     by the caller and then passed to other EMAC device functions.
 *
 *     The default receive filter prevents normal packets from being received
 *     until the receive filter is specified by calling EMAC_receiveFilter().
 *
 *     A device reset is achieved by calling EMAC_cpswClose() followed by EMAC_cpswOpen().
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error codes include:
 *       CPSW3G_ERR_DEV_ALREADY_OPEN   - The device is already open
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        physicalIndex   physical index
        hApplication    application handle
        pEMACConfig     EMAC's configuration structure
        phEMAC          handle to the EMAC device
    @endverbatim
 *
 *
 *  <b> Return Value </b>  Success (0)
 *  @n     CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n     CPSW3G_ERR_DEV_ALREADY_OPEN   - The device is already open
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Opens the EMAC peripheral at the given physical index and initializes it.
 *
 *  @b Example
 *  @verbatim
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswOpen(int32_t physicalIndex, Handle hApplication,
                 EMAC_Cpsw3gInitConfig *pEMACConfig, Handle *phEMAC);

/** ============================================================================
 *  @n@b  EMAC_cpswClose()
 *
 *  @b Description
 *  @n Closed the EMAC peripheral indicated by the supplied instance handle.
 *     When called, the EMAC device will shutdown both send and receive
 *     operations, and free all pending transmit and receive packets.
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC   handle to opened the EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_cpswOpen function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  The EMAC device will shutdown both send and receive
 *      operations, and free all pending transmit and receive packets.
 *
 *  @b Example
 *  @verbatim
        EMAC_Cpsw3gInitConfig  ecfg;
        Handle       hEMAC = 0;
        //Open the EMAC peripheral
        EMAC_cpswOpen(1, (Handle)0x12345678, &ecfg, &hEMAC);

        //Close the EMAC peripheral
        EMAC_cpswClose( hEMAC );
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswClose( Handle hEMAC );


/** ============================================================================
 *  @n@b  EMAC_sendPacket()
 *
 *  @b Description
 *  @n Sends a Ethernet data packet out the EMAC device. On a non-error return,
 *     the EMAC device takes ownership of the packet. The packet is returned
 *     to the application's free pool once it has been transmitted.
 *
 *     The function returns zero on success, or an error code on failure.
 *     When an error code is returned, the EMAC device has not taken ownership
 *     of the packet.
 *
 *     Possible error codes include:
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *       CPSW3G_ERR_BADPACKET - The packet structure is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
        pPkt        EMAC packet structure
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n      CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n      CPSW3G_ERR_BADPACKET - The packet structure is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened and get a packet
 *      buffer from private queue
 *
 *  <b> Post Condition </b>
 *  @n  Sends a ethernet data packet out the EMAC device and is returned to the
 *      application,s free pool once it has been transmitted.
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_DIRECT       1
        #define EMAC_PKT_FLAGS_SOP         0x80000000u
        #define EMAC_PKT_FLAGS_EOP         0x40000000u

        EMAC_Cpsw3gInitConfig ecfg;
        EMAC_Pkt    *pPkt;
        Handle      hEMAC = 0;
        uint32_t      size, TxCount = 0;

        //open the EMAC device
        EMAC_cpswOpen( 1, (Handle)0x12345678, &ecfg, &hEMAC );

        //set the receive filter
        CPSW_setReceiveFilter( hEMAC, EMAC_RXFILTER_DIRECT );

        //Fill the packet options fields
        size = TxCount + 60;
        pPkt->Flags      = EMAC_PKT_FLAGS_SOP | EMAC_PKT_FLAGS_EOP;
        pPkt->ValidLen   = size;
        pPkt->DataOffset = 0;
        pPkt->PktChannel = 0;
        pPkt->PktLength  = size;
        pPkt->PktFrags   = 1;

        EMAC_sendPacket( hEMAC, pPkt );

    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_sendPacket(Handle hEMAC, EMAC_PKT_DESC_T *pPkt);

/** ============================================================================
 *  @n@b  EMAC_cpswRxServiceCheck()
 *
 *  @b Description
 *  @n This function should be called every time there is an EMAC device Rx
 *     interrupt. It maintains the status the EMAC.
 *
 *     Note that the application has the responsibility for mapping the
 *     physical device index to the correct EMAC_serviceCheck() function. If
 *     more than one EMAC device is on the same interrupt, the function must be
 *     called for each device.
 *
 *     Possible error codes include:
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *       CPSW3G_ERR_MACFATAL  - Fatal error in the MAC - Call EMAC_cpswClose()
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n     CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n     CPSW3G_ERR_MACFATAL  - Fatal error in the MAC - Call EMAC_cpswClose()
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_cpswOpen function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        static CSL_IntcContext context;
        static CSL_IntcEventHandlerRecord Record[13];
        static CSL_IntcObj intcEMACRx;
        static CSL_IntcHandle hIntcEMACRx;

        //CSL_IntcParam vectId1;
        CSL_IntcParam vectId2;

        CSL_IntcGlobalEnableState state;

        // Setup the global Interrupt
        context.numEvtEntries = 13;
        context.eventhandlerRecord = Record;

        // VectorID for the Event
        vectId2 = CSL_INTC_VECTID_6;

        CSL_intcInit(&context);
        // Enable NMIs
        CSL_intcGlobalNmiEnable();
        // Enable Global Interrupts
        CSL_intcGlobalEnable(&state);

        // Opening a handle for EMAC Rx interrupt
        hIntcEMACRx=CSL_intcOpen(&intcEMACRx,CSL_INTC_EVENTID_MACRXINT,&vectId2,NULL);

        //Hook the ISRs
        CSL_intcHookIsr(vectId2,&HwRxInt);

        CSL_intcHwControl(hIntcEMACRx, CSL_INTC_CMD_EVTENABLE, NULL);

        // This function is called when Rx interrupt occurs
        Void HwRxInt (void)
        {
            // Note : get the Emac Handle(hEMAC) by calling EMAC_cpswOpen function
            EMAC_cpswRxServiceCheck(hEMAC);
        }

    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswRxServiceCheck( Handle hEMAC);


/** ============================================================================
 *  @n@b  EMAC_cpswTxServiceCheck()
 *
 *  @b Description
 *  @n This function should be called every time there is an EMAC device Tx
 *     interrupt. It maintains the status the EMAC.
 *
 *     Note that the application has the responsibility for mapping the
 *     physical device index to the correct EMAC_serviceCheck() function. If
 *     more than one EMAC device is on the same interrupt, the function must be
 *     called for each device.
 *
 *     Possible error codes include:
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *       CPSW3G_ERR_MACFATAL  - Fatal error in the MAC - Call EMAC_cpswClose()
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n     CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n     CPSW3G_ERR_MACFATAL  - Fatal error in the MAC - Call EMAC_cpswClose()
 *
 *  <b> Pre Condition </b>
 *  @n EMAC_cpswOpen function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        static CSL_IntcContext context;
        static CSL_IntcEventHandlerRecord Record[13];
        static CSL_IntcObj intcEMACTx;
        static CSL_IntcHandle hIntcEMACTx;

        //CSL_IntcParam vectId1;
        CSL_IntcParam vectId2;

        CSL_IntcGlobalEnableState state;

        // Setup the global Interrupt
        context.numEvtEntries = 13;
        context.eventhandlerRecord = Record;

        // VectorID for the Event
        vectId2 = CSL_INTC_VECTID_6;

        CSL_intcInit(&context);
        // Enable NMIs
        CSL_intcGlobalNmiEnable();
        // Enable Global Interrupts
        CSL_intcGlobalEnable(&state);

        // Opening a handle for EMAC Tx interrupt
        hIntcEMACTx=CSL_intcOpen(&intcEMACTx,CSL_INTC_EVENTID_MACTXINT,&vectId2,NULL);

        //Hook the ISRs
        CSL_intcHookIsr(vectId2,&HwTxInt);

        CSL_intcHwControl(hIntcEMACTx, CSL_INTC_CMD_EVTENABLE, NULL);

        // This function is called when Rx interrupt occurs
        Void HwTxInt (void)
        {
            // Note : get the Emac Handle(hEMAC) by calling EMAC_cpswOpen function
            EMAC_cpswTxServiceCheck(hEMAC);
        }

    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswTxServiceCheck( Handle hEMAC);

/** ============================================================================
 *  @n@b EMAC_cpswUpdatePhyStatus()
 *
 *  @b Description
 *  @n This function configures the MACCONTROL register according to the user
 *  defined PHY speed, duplex link settings.
 *
 *  @b Arguments
 *  @verbatim
 *      gmacObject          GMAC Object whose PHY needs to be updated
 *      instanceNum         MAC port identifier
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  Always returns CPSW3G_SUCCESS
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the GMAC_MACCONTROL register
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswUpdatePhyStatus(EMAC_CPGMacObj* gmacObject , uint32_t instanceNum);

/** ============================================================================
 *  @n@b EMAC_cpswControlCb()
 *
 *  @b Description
 *  @n This function is called to update the local copy of device configuration
 *  with the updated Phy status and parameters.
 *
 *  @b Arguments
 *  @verbatim
 *      devPtr              CPSW3G device pointer to be updated
 *      cmd                 Type of update being received. Currently, only one
 *                          supported, i.e. CPSW3G_PHY_STATUS_UPDATE
 *      cmdArg              Command argument, pointer to the updated link parameters
 *      param               Pointer to MAC port object to update.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  Always returns CPSW3G_SUCCESS
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
void EMAC_cpswControlCb(EMAC_Cpsw3gDevice* devPtr,uint32_t cmd,Ptr cmdArg, Ptr param);
void EMAC_cpswRxEoiWrite(void);
void EMAC_cpswTxEoiWrite(void);
void EMAC_enqueueRx(EMAC_DescCh *pdc, uint32_t fRestart);
void EMAC_dequeueRx(EMAC_DescCh *pdc, const EMAC_Desc *pDescAck);
uint32_t EMAC_cpswStatsRead(uint32_t baseAddr, uint32_t reg);
/* @} */

/* @} */




#ifdef __cplusplus
}
#endif


#endif /* EMAC_CPSW_H */
