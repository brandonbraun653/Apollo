/**
 *   @file  icss_emacDrv.h
 *   @brief
 *      Include file for ICSS_EMAC RX/TX functions and queue structures
 */

/* Copyright (C) {2016-2019} Texas Instruments Incorporated - http://www.ti.com/ 
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



#ifndef ICSS_EMACDRV__H
#define ICSS_EMACDRV__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/hw_types.h>


#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/icss_emac/icss_emacDrv_Def.h>

#include <ti/drv/icss_emac/icss_emacCommon.h>
#include <ti/drv/icss_emac/icss_emacLearning.h>
#include <ti/drv/icss_emac/icss_emacFwLearning.h>
#include <ti/drv/icss_emac/icss_emacFwInit.h>
#include <ti/drv/icss_emac/icss_emacStatistics.h>
#include <ti/drv/icss_emac/icss_emacStormControl.h>
#include <ti/drv/icss_emac/src/icss_emac_osal.h>

#include <ti/drv/icss_emac/src/phy.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \defgroup   ErrCodes    STANDARD ERROR CODES
 *  @{
 */
/** Internal functions return error codes */
#define ICSS_EMAC_SWITCH_INSTANCE_CODE                        ((uint32_t)0u)
/**< Switch Instance Code                                              */
#define ICSS_EMAC_SWITCH_ERROR_BASE                           ((uint32_t)0x200001Fu)
/**< Switch Error Base                                              */
#define ICSS_EMAC_SWITCH_ERROR_CODE                           ((ICSS_EMAC_SWITCH_ERROR_BASE | ((ICSS_EMAC_SWITCH_INSTANCE_CODE) << 16)))
/**< Switch Error Code                                              */
#define ICSS_EMAC_SWITCH_ERROR_INFO                           (ICSS_EMAC_SWITCH_ERROR_CODE)
/**< Switch Error/Informational                                              */
#define ICSS_EMAC_SWITCH_ERROR_WARNING                        (ICSS_EMAC_SWITCH_ERROR_CODE | 0x10000000u)
/**< Switch Error/Warning                                              */
#define ICSS_EMAC_SWITCH_ERROR_MINOR                          (ICSS_EMAC_SWITCH_ERROR_CODE | 0x20000000u)
/**< Switch Error Minor                                              */
#define ICSS_EMAC_SWITCH_ERROR_MAJOR                          (ICSS_EMAC_SWITCH_ERROR_CODE | 0x30000000u)
/**< Switch Error Major                                              */
#define ICSS_EMAC_SWITCH_ERROR_CRITICAL                       (ICSS_EMAC_SWITCH_ERROR_CODE | 0x40000000u)
/**< Switch Error Critical                                              */

/**  Success code */
#define ICSS_EMAC_SWITCH_SUCCESS                              (0u)

/**  Error codes */
#define ICSS_EMAC_ERR_DEV_ALREADY_INSTANTIATED(instID)  (0x30000000u + ICSS_EMAC_SWITCH_ERROR_BASE + ((instId) << 16) )
/**< Device with same instance ID already created. */
#define ICSS_EMAC_ERR_DEV_NOT_INSTANTIATED              (ICSS_EMAC_SWITCH_ERROR_MAJOR + 1u)
/**< Device is not instantiated yet.                                        */
#define ICSS_EMAC_ERR_SWITCH_INVALID_PARAM                            (ICSS_EMAC_SWITCH_ERROR_MAJOR + 2u)
/**< Function or calling parameter is invalid                               */
#define ICSS_EMAC_ERR_CH_INVALID                        (ICSS_EMAC_SWITCH_ERROR_CRITICAL + 3u)
/**< Channel number invalid                                                 */
#define ICSS_EMAC_ERR_CH_ALREADY_INIT                   (ICSS_EMAC_SWITCH_ERROR_MAJOR + 4u)
/**< Channel already initialized and setup                                  */
#define ICSS_EMAC_ERR_TX_CH_ALREADY_CLOSED              (ICSS_EMAC_SWITCH_ERROR_MAJOR + 5u)
/**< Tx Channel already  closed. Channel close failed                       */
#define ICSS_EMAC_ERR_TX_CH_NOT_OPEN                   (ICSS_EMAC_SWITCH_ERROR_MAJOR + 6u)
/**< Tx Channel not open.                                                   */
#define ICSS_EMAC_ERR_TX_NO_LINK                       (ICSS_EMAC_SWITCH_ERROR_MAJOR + 7u)
/**< Tx Link not up.                                                        */
#define ICSS_EMAC_ERR_TX_OUT_OF_BD                     (ICSS_EMAC_SWITCH_ERROR_MAJOR + 8u)
/**< Tx ran out of Buffer descriptors to use.                               */
#define ICSS_EMAC_ERR_RX_CH_INVALID                    (ICSS_EMAC_SWITCH_ERROR_CRITICAL + 9u)
/**< Rx Channel invalid number.                                             */
#define ICSS_EMAC_ERR_RX_CH_ALREADY_INIT               (ICSS_EMAC_SWITCH_ERROR_MAJOR + 10u)
/**< Rx Channel already setup.                                              */
#define ICSS_EMAC_ERR_RX_CH_ALREADY_CLOSED             (ICSS_EMAC_SWITCH_ERROR_MAJOR + 11u)
/**< Rx Channel already closed. Channel close failed.                       */
#define ICSS_EMAC_ERR_RX_CH_NOT_OPEN                   (ICSS_EMAC_SWITCH_ERROR_MAJOR + 12u)
/**< Rx Channel not open yet.                                               */
#define ICSS_EMAC_ERR_DEV_ALREADY_CREATED              (ICSS_EMAC_SWITCH_ERROR_MAJOR + 13u)
/**< EMAC device already created.                                           */
#define ICSS_EMAC_ERR_DEV_NOT_OPEN                     (ICSS_EMAC_SWITCH_ERROR_MAJOR + 14u)
/**< Device is not open or not ready                                        */
#define ICSS_EMAC_ERR_DEV_ALREADY_CLOSED               (ICSS_EMAC_SWITCH_ERROR_MAJOR + 15u)
/**< Device close failed. Device already closed.                            */
#define ICSS_EMAC_ERR_DEV_ALREADY_OPEN                 (ICSS_EMAC_SWITCH_ERROR_MAJOR + 16u)
/**< Device open failed. Device already open.                               */
#define ICSS_EMAC_ERR_RX_BUFFER_ALLOC_FAIL             (ICSS_EMAC_SWITCH_ERROR_CRITICAL +17u)
/**< Rx Buffer Descriptor allocation failed.                                */
#define ICSS_EMAC_SWITCH_INTERNAL_FAILURE                     (ICSS_EMAC_SWITCH_ERROR_MAJOR + 18u)
/**< EMAC Internal failure.                                                 */
#define ICSS_EMAC_SWITCH_VLAN_UNAWARE_MODE          (ICSS_EMAC_SWITCH_ERROR_MAJOR + 19u)
/**< VLAN support not enabled in EMAC                                       */
#define ICSS_EMAC_SWITCH_ALE_TABLE_FULL             (ICSS_EMAC_SWITCH_ERROR_MAJOR + 20u)
/**< ALE Table full.                                               */
#define ICSS_EMAC_SWITCH_ADDR_NOTFOUND              (ICSS_EMAC_SWITCH_ERROR_MAJOR + 21u)
/**< Multicast/Unicast/OUI Address not found in ALE.                        */
#define ICSS_EMAC_SWITCH_INVALID_VLANID             (ICSS_EMAC_SWITCH_ERROR_MAJOR + 22u)
/**< Invalid VLAN Id.                                                       */
#define ICSS_EMAC_SWITCH_INVALID_PORT               (ICSS_EMAC_SWITCH_ERROR_MAJOR + 23u)
/**< Invalid Port Specified.                                                */
#define ICSS_EMAC_SWITCH_BD_ALLOC_FAIL              (ICSS_EMAC_SWITCH_ERROR_MAJOR + 24u)
/**< Buffer Descriptor Allocation failure. OOM                              */
#define ICSS_EMAC_ERR_BADPACKET                        (ICSS_EMAC_SWITCH_ERROR_MAJOR + 25u)
/**< Supplied packet was invalid  */
#define ICSS_EMAC_ERR_COLLISION_FAIL                   (ICSS_EMAC_SWITCH_ERROR_MAJOR + 26u)
/**< Collision queue was full                             */
#define ICSS_EMAC_ERR_MACFATAL                         (ICSS_EMAC_SWITCH_ERROR_CRITICAL + 26u)
/**< Fatal Error - EMACClose() required                                    */
/* @} */

/**Dual MAC Mode. Both Ports Enabled  */
#define ICSS_EMAC_MODE_DUALMAC   (4U)
/**Switch Mode  */
#define ICSS_EMAC_MODE_SWITCH    (3U)
/**Single EMAC Mode. Port 1 Enabled  */
#define ICSS_EMAC_MODE_MAC1      (1U)
/**Single EMAC Mode. Port 2 Enabled  */
#define ICSS_EMAC_MODE_MAC2      (2U)

/**Driver-based Learning Mode Disabled  */
#define ICSS_EMAC_LEARNING_DIS   (0U)
/**Driver-based Learning Mode Enabled  */
#define ICSS_EMAC_LEARNING_EN    (1U)
/**Firmware-based Learning Mode Enabled  */
#define ICSS_EMAC_FW_LEARNING_EN (2U)

/** Number of Ports in a single ICSS  */
#define ICSS_EMAC_MAX_PORTS_PER_INSTANCE     2

/**Total Queues available*/
#define ICSS_EMAC_NUMQUEUES ((uint32_t)17U)
/**Priority Queue 1*/
#define ICSS_EMAC_QUEUE1 ((uint32_t)0U)
/**Priority Queue 2*/
#define ICSS_EMAC_QUEUE2 ((uint32_t)1U)
/**Priority Queue 3*/
#define ICSS_EMAC_QUEUE3 ((uint32_t)2U)
/**Priority Queue 4*/
#define ICSS_EMAC_QUEUE4 ((uint32_t)3U)
/**Priority Queue 5*/
#define ICSS_EMAC_QUEUE5 ((uint32_t)4U)
/**Priority Queue 6*/
#define ICSS_EMAC_QUEUE6 ((uint32_t)5U)
/**Priority Queue 7*/
#define ICSS_EMAC_QUEUE7 ((uint32_t)6U)
/**Priority Queue 8*/
#define ICSS_EMAC_QUEUE8 ((uint32_t)7U)
/**Priority Queue 9*/
#define ICSS_EMAC_QUEUE9 ((uint32_t)8U)
/**Priority Queue 10*/
#define ICSS_EMAC_QUEUE10 ((uint32_t)9U)
/**Priority Queue 11*/
#define ICSS_EMAC_QUEUE11 ((uint32_t)10U)
/**Priority Queue 12*/
#define ICSS_EMAC_QUEUE12 ((uint32_t)11U)
/**Priority Queue 13*/
#define ICSS_EMAC_QUEUE13 ((uint32_t)12U)
/**Priority Queue 14*/
#define ICSS_EMAC_QUEUE14 ((uint32_t)13U)
/**Priority Queue 15*/
#define ICSS_EMAC_QUEUE15 ((uint32_t)14U)
/**Priority Queue 16*/
#define ICSS_EMAC_QUEUE16 ((uint32_t)15U)



/**Collision Queue*/
#define ICSS_EMAC_COLQUEUE ((uint32_t)16U)

/* Max number of PRI-ICSS instances */
#define ICSS_EMAC_MAX_PRU_ICSS_INSTANCES ((uint32_t)2U)


/**< Firmware MemoryMap Init DONE */
#define ICSS_EMAC_FW_MMAP_INIT_DONE  ((uint32_t)0xABCD1234U)
/**
 * @brief CorePac specific Mux configuration parameters for interrupt initialization
 */
typedef struct {
    /* CorePac specific Event ID, input to CorePac interrupt controller */
    uint32_t          eventId;
    /* intc mux number, Keystone inc mux is Chip Interrupt Controller */
        
    int32_t           intcMuxNum;
    /* intc mux input event ID, for Keystone, it is the input event to CIC */

    int32_t           intcMuxInEvent;
    /* intc mux output event ID, for Keystone, it is the Host interrupt number */
    int32_t           intcMuxOutEvent;
} ICSS_EmacIntrMuxCfg;


/*
*  @brief     ICSS EMAC Init Configuration Structure
*/
typedef struct {
    /** Phy address of the ports.For mac each handle will have single port only
    *   And Two for Switch handle
    */
    uint32_t phyAddr[ICSS_EMAC_MAX_PORTS_PER_INSTANCE];
    /** Flag to enable Half duplex capability. Firmware support also is required to
    *     enable the functionality
    */
    uint8_t halfDuplexEnable;
    /** Flag to enable Interrupt pacing */
    uint8_t enableIntrPacing;
    /** Number of packets threshold for Pacing Mode1 */
    uint16_t pacingThreshold;
    /** Queue Priority separation for RT and NRT packets
    *     If packets are in Queue <=ethPrioQueue, they will be forwarded to NRT callback
    *     and others to RT callback
    */
    uint8_t ethPrioQueue;
    /** Flag to enable learning. Not applicable for Mac mode */
    uint8_t learningEn;
    /**Port Mask. Indication to LLD which ports to be used
    * Valid values:ICSS_EMAC_MODE_SWITCH,ICSS_EMAC_MODE_MAC1,ICSS_EMAC_MODE_MAC1
    */
    uint8_t portMask;
    /* Recieve Packet, DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t rxIntNum;
    /* Link Interrupt, DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t linkIntNum;
    /* Transmit Completion , DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t txIntNum;

    /**Macid to be used for the interface*/
    uint8_t* macId;
    /**Pacing mode to be used(MODE1/MODE2)*/
    uint8_t ICSS_EmacIntrPacingMode;
    /**Flag to enable TTS Cyclic Packet Insertion Notification Interrupt*/
    uint8_t	ICSS_EmacTTSEnableCycPktInterrupt;
    /**CorePac specific Mux configuration parameters for Rx packet interrupt*/
    ICSS_EmacIntrMuxCfg intrMuxCfgRxPkt;
    /**CorePac specific Mux configuration parameters for Tx completion  interrupt*/
    ICSS_EmacIntrMuxCfg intrMuxCfgTxComplete;
    /**CorePac specific Mux configuration parameters for Link interrupt*/
    ICSS_EmacIntrMuxCfg intrMuxCfgLink;
} ICSS_EmacInitConfig;

#define ICSSEMAC_InitConfig ICSS_EmacInitConfig


/**
 * @brief Queue Statistics
 */
typedef struct {
    /**queue raw count*/
    uint32_t rawCount;
    /**queue error count*/
    uint32_t errCount;
} ICSS_EmacQueueStats;


/**
 * @brief Queue Parameters
 */
typedef struct queParams {
    /**Queue statistics*/
    ICSS_EmacQueueStats  qStat;
    /**buffer  offset*/
    uint16_t    buffer_offset;
    /**buffer descriptor offset*/
    uint16_t    buffer_desc_offset;
    /**queue descriptor offset*/
    uint16_t    queue_desc_offset;
    /**queue size*/
    uint16_t    queue_size;
} ICSS_EmacQueueParams;

/**
 * @brief Port parameters
 */
typedef struct {
    /**pointer to PTCP packet mem*/
    uint8_t*            ptcpPktBuff;
    /**statistics   - raw*/
    uint32_t            rawCount;
    /**Error count*/
    uint32_t            errCount;
    /**Queues per port*/
    ICSS_EmacQueueParams        queue[ICSS_EMAC_NUMQUEUES];
} ICSS_EmacPortParams;


/**
 * @brief ICSS EMAC time triggered send offsets, local to LLD
 */
typedef struct ICSS_EmacTTSOffsets_s {
    uint32_t cycleStartOffset;
    uint32_t cyclePeriodOffset;
    uint32_t cfgTimeOffset;
    uint32_t statusOffset;
    uint32_t missedCycleCntOffset;
    uint32_t prevTxSof;
    uint32_t cycTxSof;
} ICSS_EmacTTSOffsets;

/**
 * @brief ICSS EMAC Static Firmware Memory Map offsets
 */
typedef struct ICSS_EmacFwStaticMmap_s {
    /* PRU0 and PRU1 DRAM   */
    uint32_t versionOffset;                 /* Version offset for release 1*/
    uint32_t version2Offset;                /* Version offset for release 2*/
    uint32_t featureOffset;                 /* Feature offset */
    uint32_t futureFeatureOffset;           /* Offset reserved for enhance features, future use*/
    uint32_t statisticsOffset;              /* Statistics offset */
    uint32_t statisticsSize;                /* Statistics block size */
    uint32_t stormPreventionOffsetBC;         /* Storm prevention offset */
    uint32_t phySpeedOffset;                /* Phy Speed Offset */
    uint32_t portStatusOffset;              /* Port Status Offset */
    uint32_t portControlAddr;               /* Port Control Addr offset */
    uint32_t portMacAddr;                   /* Port Mac Addr offset*/
    uint32_t rxInterruptStatusOffset;       /* RX Interrupt Status Offset */
    uint32_t stormPreventionOffsetMC;         /* Storm prevention offset (multicast)*/
    uint32_t stormPreventionOffsetUC;         /* Storm prevention offset (unicast)*/
    uint32_t p0QueueDescOffset;             /* Port 0 QueueDescOffset */
    uint32_t p0ColQueueDescOffset;          /* Port 0 Collision QueueDescOffset */
    uint32_t emacTtsConfigBaseOffset;       /* TTS Config Base Offset */
    uint32_t interfaceMacAddrOffset;        /* Interface Mac AddressrOffset */
    uint32_t colStatusAddr;                 /* Collision status address offset */
    uint32_t promiscuousModeOffset;         /* promiscuous mode feature control offset */
} ICSS_EmacFwStaticMmap;


/**
 * @brief ICSS EMAC Dynamic Firmware Memory Map offsets
 */
typedef struct ICSS_EmacFwDynamicMmap_s {
    uint32_t txQueueSize[ICSS_EMAC_NUMQUEUES-1U];       /* TX queue sizes, */
    uint32_t rxHostQueueSize[ICSS_EMAC_NUMQUEUES - 1U];   /* RX Host queue sizes */
    uint32_t collisionQueueSize;                  /* Collision queue size */
    /* Following are placed in ICSS Shared RAM */
    uint32_t  p0Q1BufferDescOffset;               /* Port 0 Queue1 Buffer Descriptor offset */
    uint32_t  p0ColBufferDescOffset;              /* Port 0 Collision Buffer Descriptor offset */
    /* Following are placed in L3/OCMC RAM */
    uint32_t  p0Q1BufferOffset;                   /* Port 0 Queue1 Buffer offset */
    uint32_t  transmitQueuesBufferOffset;         /* Transmit Queue Buffer offset */
    uint32_t  p0ColBufferOffset;                  /* Port 0 Collision Buffer offset */
    uint32_t  hostQ1RxContextOffset;              /* Receive Host Queue 1 Context offset */
    uint32_t  p1Q1SwitchTxContextOffset;            /* Port 1 queue 1 Switch TX Context offset */
    uint32_t  portQueueDescOffset;                    /* Port queue descriptor offset */
     uint32_t  q1EmacTxContextOffset;               /* Queueu1 Emac TX Context Offset */
     uint32_t numQueues;                                /* number of port queues */
   
} ICSS_EmacFwDynamicMmap;




/*
*  @brief     ICSSEMAC_Object
*             Handle containing pointers to all modules as well as Initialization Config
*/
typedef struct ICSS_EmacObject_s {
    /*! PRUICSS Handle details where the EMAC driver will be based on       */
    PRUICSS_Handle            pruIcssHandle;
    /*! Pointer to initial configuration structure                          */
    ICSS_EmacInitConfig       *emacInitcfg;
    /*! Mac Table Pointer for Learning module. Not applicable for Emac mode */
    HashTable_t               *macTablePtr;
    /*! FDB pointer for firmware-based Learning module. Not applicable for Emac mode */
    Fdb                       *fdb;
    /*! Pointer All Driver specific Callback  structure                     */
    ICSS_EmacCallBackObject   *callBackHandle;
    /*! Pointer to  Emac driver Firmware statistics structure               */
    void                      *pruStat;
    /*! Pointer to Emac Driver host statistics structure                    */
    void                      *hostStat;
    /*! Pointer to Storm Prevention structure */
    void                      *stormPrevPtr;
    /*! Rx Task Handle for the emac instance.Required for receiving packets */
    void                      *rxTaskHandle;
    /*! Tx Task Handle for the emac instance.Required for notification of Trasnmit Complete indication from  PRUICSS firmware */
    void                      *txTaskHandle;
    /*! TTS Cyclic Packet Notification Task Handle for the emac instance.Required for notification to insert cyclic packet from  PRUICSS firmware */
    void                      *ttsCycTaskHandle;
    /*! Rx Semaphore Handle for the emac instance.Required for receiving packets */
    void                      *rxSemaphoreHandle;
    /*! Tx Complete Semaphore Handle for the emac instance.Required for notification of Trasnmit Complete indication from  PRUICSS firmware */
    void                      *txSemaphoreHandle;
    /*! TTS Cyclic Packet Notification Semaphore Handle for the emac instance.Required for notification to insert cyclic packet from  PRUICSS firmware */
    void                      *ttsCycSemaphoreHandle;
    /*! Link Task Handle for the emac instance.Required for updating Phy speed and duplexity  */
    void                      *linkTaskHandle;
    /*! Link Semaphore Handle for the emac instance.Required for updating Phy speed and duplexity  */
    void                      *linkSemaphoreHandle;
    /*! Rx interrupt handler */
    void                      *rxintHandle;
    /*! Link interrupt handler */
    void                      *linkintHandle;
    /*! Tx Complete interrupt handler */
    void                      *txintHandle;
    /*! Pointer to store any data from High Level Driver  */
    void                      *pvtInfo;
    /*! Link status for the ports */
    uint8_t                   linkStatus[ICSS_EMAC_MAX_PORTS_PER_INSTANCE];
    /*! Previous Link status for the ports .Used to update port status*/
    uint8_t                   prevlinkStatus[ICSS_EMAC_MAX_PORTS_PER_INSTANCE];
    /*!    ICSS Revision Information - Major	*/
    uint8_t    icssRevisionMajor;
    /*!    ICSS Revision Information - Minor	*/
    uint8_t    icssRevisionMinor;

    ICSS_EmacCallBack port0ISRCall;
    ICSS_EmacCallBack port1ISRCall;

    ICSS_EmacCallBack icssEmacHwIntRx;
    ICSS_EmacCallBack icssEmacHwIntTx;
    ICSS_EmacCallBack icssEmacHwIntTTSCyc;
    void *port0ISRUser;
    void *port1ISRUser;
    ICSS_EmacPortParams switchPort[ICSS_EMAC_MAX_PORTS_PER_INSTANCE + 1];
    void* rxPacingTimerHandle;
    uint32_t fwMmapInitDone;
    ICSS_EmacFwStaticMmap fwStaticMMap;
    ICSS_EmacFwDynamicMmap fwDynamicMMap;

#ifdef __LINUX_USER_SPACE
    /* Only used for Linux user-space */
    /* Link interrupt file descriptor */
    uint32_t linkInt_fd;
    /* Rx interrupt file descriptor */
    uint32_t rxInt_fd;
    /* Tx interrupt file descriptor */
    uint32_t txInt_fd;
    /* TTS interrupt file descriptor */
    uint32_t ttsCycInt_fd;
    /* Handle for PRUSS virtual addresses */
    void *pruss_drv_handle;
#endif
} ICSS_EmacObject;

/* For backward compatibility */
#define ICSSEMAC_Object ICSS_EmacObject
/**
 * @brief Handle containing base addresses for all memories and modules
 */
typedef struct ICSS_EmacHwAttrs_s {
    ICSS_EmacBaseAddressHandle_T emacBaseAddrCfg;
}ICSS_EmacHwAttrs;
/* For backward compatibility */
#define ICSSEMAC_HwAttrs ICSS_EmacHwAttrs

/**
 * @brief Base EMAC handle containing pointers to all modules required for driver to work
 */
typedef struct ICSS_EmacConfig_s {
    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;

} ICSS_EmacConfig;

/**
 * @brief Rx packet processing information block that needs to passed into  call to ICSS_EmacRxPktGet
 */
typedef struct
{
    ICSS_EmacHandle icssEmacHandle; /*! handle to ICSS_EMAC Instance*/
    uint32_t destAddress; /*! Base address of data buffer where received frame has to be stored */
    uint8_t queueNumber;    /*!Receive queue from which frame has to be copied */
    uint8_t port;   /*!Returns port number on which frame was received */
    uint32_t more;  /*!Returns more which is set to 1 if there are more frames in the queue */
} ICSS_EmacRxArgument;

/**
 * @brief Tx packet processing information block that needs to passed into  call to ICSS_EmacTxPacket
 */
typedef struct
{
    ICSS_EmacHandle icssEmacHandle; /*! handle to ICSS_EMAC Instance*/
    const uint8_t *srcAddress;  /*! Base address of the buffer where the frame to be transmitted resides */
    uint8_t portNumber; /*!  Port on which frame has to be transmitted */
    uint8_t queuePriority;  /*! Queue number in which frame will be  queued for transmission */
    uint16_t lengthOfPacket;    /*! length of the frame in bytes */
} ICSS_EmacTxArgument;

/* For backward compatibility */
#define ICSSEMAC_Config ICSS_EmacConfig

/**
 * @brief ICSS EMAC time triggered send configuration structure.
 */
typedef struct ICSS_EmacTTSConfig_s {
    /*	EMAC handle for TTS	*/
    ICSSEMAC_Handle icssEmacHandle;
    /*	Port number */
    uint8_t portNumber;
    /*	Cycle start time (trigger instant)	*/
    uint64_t cycleStartTime;
    /*	Cycle period for TTS	*/
    uint32_t cyclePeriod;
    /*	Configuration time for TTS cycle	*/
    uint32_t configTime;
    /*	TTS status (enable/disable)	*/
    uint8_t statusTTS;
    /*	Store cyclic packet Tx SOF (enable/disable)	*/
    uint8_t cycTxSOFStatus;
} ICSS_EmacTTSConfig;

/**
 * @brief ICSS EMAC time triggered send query structure.
 */
typedef struct ICSS_EmacTTSQuery_s {
    /*	EMAC handle for TTS Status	*/
    ICSSEMAC_Handle icssEmacHandle;
    /*	Port number */
    uint8_t portNumber;
    /*	TTS status (enabled/disabled)	*/
    uint8_t statusTTS;
    /*	Missed Cycle (true/false)	*/
    uint8_t missedCycle;
    /*	Notification for application to insert cyclic frame (set/clear)	*/
    uint8_t insertCycFrameNotification;
    /*	Store cyclic packet Tx SOF (enabled/disabled)	*/
    uint8_t cycTxSOFStatus;
    /*	Missed Cycle Counter	*/
    uint32_t missedCycleCounter;
    /*	Previous cyclic frame Tx SOF	*/
    uint64_t cycTxSOF;
} ICSS_EmacTTSQuery;
/**
 * @brief ICSS EMAC Rx Pkt Info  structure.
 */
typedef struct ICSS_EmacPktInfo_s {
    /*!  port number where frame was received */
    uint32_t portNumber;
    /*! host queue where the received frame is queued*/
    uint32_t queueNumber;
    /*! address of read buffer in L3 address space*/
    uint32_t rdBufferL3Addr;
    /*! FDB lookup was succssful in firmware. FW Learning Only. */
    uint32_t fdbLookupSuccess;
    /*! Packet was flooded. FW Learning Only. */
    uint32_t flooded;
} ICSS_EmacPktInfo;


/**
* @brief Enum for enableIntrPacing
*/
typedef enum {
    ICSS_EMAC_ENABLE_PACING = 0,       /**< Interrupt pacing enabled*/
    ICSS_EMAC_DISABLE_PACING           /**< Interrupt pacing disabled*/
} intrPacing;

/**
* @brief Enum for ICSS_EmacIntrPacingMode
*/
typedef enum {
    ICSS_EMAC_INTR_PACING_MODE1 = 0,    /**< Frame Count based Interrupt pacing*/
    ICSS_EMAC_INTR_PACING_MODE2         /**< Timer based Interrupt pacing*/
} ICSS_EmacIntrPacingMode_e;


/**
* @brief Enum for Poll modes 
*/
typedef enum {
    ICSS_EMAC_POLL_MODE_RX_PKT = 0x1U,                  /**< Poll the driver for received packets*/
    ICSS_EMAC_POLL_MODE_LINK = 0x2U,                    /**< Poll the driver for link status */
    ICSS_EMAC_POLL_MODE_TX_COMPLETE = 0x4U,             /**< Poll the driver for trasmit complete notification */
} ICSS_EmacIntrPollMode_e;

/**Maximum Valid size (incl header + VLAN TAG..., no CRC)*/
#define ICSS_EMAC_MAXMTU  (1518U)
/**Minimum Valid size ( DA + SA + Ethertype)*/
#define ICSS_EMAC_MINMTU  (14U)

/**
 *  @def  ICSS_EMAC_PORT_0
 *        Used to specify host side port
 */
#define ICSS_EMAC_PORT_0 (0)

/**
 *  @def  ICSS_EMAC_PORT_1
 *        Used to specify physical port 1 MII 0 (tx)
 */
#define ICSS_EMAC_PORT_1 (1U)

/**
 *  @def  ICSS_EMAC_PORT_2
 *        Used to specify physical port 2 MII 1 (tx)
 */
#define ICSS_EMAC_PORT_2 (2U)

/**
 *  @def  ICSS_EMAC_TTS_ENABLE
 *        Used to specify time triggered send enable
 */
#define ICSS_EMAC_TTS_ENABLE (1U)

/**
 *  @def  ICSS_EMAC_TTS_DISABLE
 *        Used to specify time triggered send disable
 */
#define ICSS_EMAC_TTS_DISABLE (0)

/**
 *  @def  ICSS_EMAC_TTS_CYC_TXSOF_ENABLE
 *        Used to specify TTS cyclic packet Tx SOF store enable
 */
#define ICSS_EMAC_TTS_CYC_TXSOF_ENABLE (1U)

/**
 *  @def  ICSS_EMAC_TTS_CYC_TXSOF_DISABLE
 *        Used to specify TTS cyclic packet Tx SOF store disable
 */
#define ICSS_EMAC_TTS_CYC_TXSOF_DISABLE (0)

/**
 *  @def  ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE
 *        Used to specify TTS cyclic packet insertion interrupt as enabled
 */
#define ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE (1U)

/**
 *  @def  ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE
 *        Used to specify TTS cyclic packet insertion interrupt as disabled
 */
#define ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE (0)

/**
 *  @def  ICSS_EMAC_TTS_INSERT_CYC_FRAME_SET
 *        Used to specify TTS event set for inserting cyclic frame
 */
#define ICSS_EMAC_TTS_INSERT_CYC_FRAME_SET (1U)

/**
 *  @def  ICSS_EMAC_TTS_INSERT_CYC_FRAME_CLEAR
 *        Used to specify TTS event clear for inserting cyclic frame
 */
#define ICSS_EMAC_TTS_INSERT_CYC_FRAME_CLEAR (0)

/**
* @def ICSS_EMAC_TTS_IEP_MAX_VAL
*      1s, for 32-bit IEP wraparound
*/
/*    EMAC Time Triggered Send Constants	*/
#define ICSS_EMAC_TTS_IEP_MAX_VAL                                       (0x3B9ACA00U)

/**
* @def ICSS_EMAC_TTS_FIRST_CST_SAFETY_MARGIN
*      15us, safety margin for first cycle start time provided
*/
#define ICSS_EMAC_TTS_FIRST_CST_SAFETY_MARGIN           (0x3A98U)


/**
 *  @def  ICSS_REVISION_MAJOR_MASK
 *        Mask for MAJOR bits in ICSS Revision
 */
#define ICSS_REVISION_MAJOR_MASK (0x700U)

/**
 *  @def  ICSS_REVISION_MINOR_MASK
 *        Mask for MINOR bits in ICSS Revision
 */
#define ICSS_REVISION_MINOR_MASK (0x3FU)

/**
* @def MAX_NUM_PROTOCOL_IMPLEMENTED
*       Max Number of protocols
*/
#define MAX_NUM_PROTOCOL_IMPLEMENTED   (50U)
/**
* @def NUM_PROTOCOLS_IMPLEMENTED
*      Number of protocols supported
*/
#define NUM_PROTOCOLS_IMPLEMENTED  (2U)
/**
* @def IP4_PROT_TYPE
*      IP4 Protcol type
*/
#define IP4_PROT_TYPE    (0x800)
/**
* @def ARP_PROT_TYPE
*      ARP protocol type
*/
#define ARP_PROT_TYPE    (0x806)


/**
 *  @b Description
 *  @n
 *      Receive frame interrupt service routine
 *
 *  @param[in]  args parameter list to interrupt service routine
 *  @retval     none
 */
void ICSS_EmacRxInterruptHandler(void *args);



/**
*  \name ICSS_EmacTxInterruptHandler
*  @brief Main TX interrupt service routine
*      	Handles TX Completion and TTS Cyclic Packet
*      	Insertion Notification interrupts
*
*  @param args arguments if any
*
*  @retval
*       void
*
*/
void ICSS_EmacTxInterruptHandler(void *args);



/**
* @brief Link change status interrupt for Port 0 and Port 1
*         calls a user callback if defined to provide link info to stack
*
* @param arg
*
* @retval none
*/
void ICSS_EmacLinkISR(void* arg);

/**
 *  @b Description
 *  @n
 *      Retrieves a frame from a host queue and copies it
 *           in the allocated stack buffer
 *
 *  @param[in]  rxArg defined at @ref ICSS_EmacRxArgument
 *  @param[in]  userArg custom Rx packet callback packet options only required for custom RxPacket implementations,
                default to NULL when calling ICSS_EmacRxPktGet which is default Tx Packet API
 *  @retval     Length of the frame received in number of bytes or -1 on Failure
 */
int32_t ICSS_EmacRxPktGet(ICSS_EmacRxArgument *rxArg, void* userArg);


/**
 *  @b Description
 *  @n
 *      Finds the maximum fill level of the queue in terms of 32 byte blocks.
        For example, if there was only one 64 byte packet received when this
        API is called then it would return value of 2.
        It also returns number of times queue has overflown.
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found
 *  @param[in]  queueType   Rx/Tx Queue
 *  @param[out]  queueOverflowCount    Number of times queue has overflown

 *  @retval     The maximum fill level of the queue in terms of 32 byte blocks or
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacGetMaxQueueFillLevel(ICSS_EmacHandle icssEmacHandle,int32_t portNumber, int32_t queuePriority,uint8_t queueType, int32_t* queueOverflowCount);

/**
 *  @b Description
 *  @n returns the queueOverflowCount for a host/port queue
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found

 *  @retval     queueOverflowCount    Number of times queue has overflown
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacGetQueueOverflowCount(ICSS_EmacHandle icssEmacHandle, int32_t portNumber, int32_t queuePriority);

/**
 *  @b Description
 *  @n clear the queueOverflowCount for a host/port queue
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found

 *  @retval     ICSS_EMAC_SWITCH_SUCCESS    queueOverflowCount value cleared
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacResetQueueOverflowCount(ICSS_EmacHandle icssEmacHandle, int32_t portNumber, int32_t queuePriority);

/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt receive packet callback function
 *
 *  @param[in]  hwIntRx    hardware interrupt receive packet callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntRx (ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntRx);

/**
 *  @b Description
 *  @n
 *       API to retrieve the information about the received frame which
 *       is then used to dequeue the frame from the host queues
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[out]  portNumber    Return pointer of port number where frame was received
 *  @param[out]  queueNumber   Return pointer of host queue where the received frame is queued

 *  @retval     Length of packet or 0 if no packet found
 */
int32_t ICSS_EmacRxPktInfo(ICSS_EmacHandle icssEmacHandle,
                           int32_t* portNumber,
                           int32_t* queueNumber);

/**
 *  @b Description
 *  @n
 *       API to retrieve the information about the received frame which
 *       is then used to dequeue the frame from the host queues.
 *       This version fo the API also allows for pointer to the 
 *       address of read buffer in L3 address space to be returned
 *       as part of .ICSS_EmacPktInfo.
 *       This is an enhancement to the ICSS_EmacRxPktInfo API.
 * 
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[out]  pRxPktInfo    Return pointer of receive packet info which includes  
                        port number where frame was received,  host queue where the received frame is queued
                        and address of read buffer in L3 address space.

 *  @retval     Length of packet or 0 if no packet found
 */
int32_t ICSS_EmacRxPktInfo2(ICSS_EmacHandle icssEmacHandle,
                             ICSS_EmacPktInfo *pRxPktInfo);

/**
 *  @b Description
 *  @n
 *      API to queue a frame which has to be transmitted on the
 *      specified port queue
 *
 *  @param[in]  txArg defined at @ref ICSS_EmacTxArgument
 *  @param[in]  userArg custom Tx packet callback packet options only required for custom TxPacket implementations,
                default to NULL when calling ICSS_EmacTxPacket which is default Tx Packet API
 *  @retval     0 on scuess,  <0 on failure
 */
int32_t ICSS_EmacTxPacket(const ICSS_EmacTxArgument *txArg, void* userArg);
    					  
/**
 *  \name     ICSS_EmacTTS
 *  @brief
 *      	API to enable time triggered send for Queue 1 frames.
 *
 *  @param[in]  ttsConfig     	EMAC TTS Configfuration structure (ICSS_EmacTTSConfig *).
 *  @retval     int8_t    		0 on success, -1 on failure.
 */
int8_t ICSS_EmacTTS(const ICSS_EmacTTSConfig* ttsConfig);

/**
 *  \name     ICSS_EmacTTSGetStatus
 *  @brief
 *      	API to query time triggered send details from PRU firmware.
 *
 *  @param[in]  ttsQuery     	EMAC TTS Query structure (ICSS_EmacTTSQuery *).
 *  @retval     int8_t    		0 on success, -1 on failure.
 */
int8_t ICSS_EmacTTSGetStatus(ICSS_EmacTTSQuery* ttsQuery);

/**
@}
*/



/* Local Functions */
/** @brief  API to copy a packet from DDR to Tx Queue memory on L3 and synchronize with
 *  firmware
 *  @internal
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  srcAddress    Base address of the buffer where the frame to be transmitted resides
 *  @param[in]  portNumber   Port on which frame has to be transmitted.
 *                            Valid values are:
                              1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority    Queue number in which frame will be
 *                               queued for transmission
 *  @param[in] lengthOfPacket   length of the frame in bytes
 *  @retval     0 on scuess,  <0 on failure
 */
int32_t ICSS_EmacTxPacketEnqueue (ICSS_EmacHandle icssEmacHandle,
                                  const uint8_t* srcAddress,
                                  uint8_t portNumber,
                                  uint8_t queuePriority,
                                  uint16_t lengthOfPacket);
/**
 *  @brief  Task to enable copying of Rx data from queues to DDR. This is a function that calls
 *  another function to empty the queues
 *  @internal
 *  @param[in]  a0 Generic argument
 *  @param[in]  a1    Generic argument
 *  @retval     none
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsRxTaskFnc(void *a0);
#else
void ICSS_EMacOsRxTaskFnc(uint32_t a0, uint32_t a1);
#endif


#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsLinkTaskFnc(void *a0);
#else
void ICSS_EMacOsLinkTaskFnc(uint32_t a0, uint32_t a1);
#endif

/**
 *  @brief  Task to enable receiving Indication of transmit packet complete by PRU-ICSS firmware. 
 *  @internal
 *  @param[in]  a0 Generic argument
 *  @param[in]  a1    Generic argument
 *  @retval     none
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsTxTaskFnc(void *a0);
#else
void ICSS_EMacOsTxTaskFnc(uint32_t a0, uint32_t a1);
#endif

/**
 *  @brief  Task to enable receiving TTS Cyclic Packet Insertion Notification by PRU-ICSS firmware.
 *  @internal
 *  @param[in]  a0 Generic argument
 *  @param[in]  a1    Generic argument
 *  @retval     none
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsTTSCycTaskFnc(void *a0);
#else
void ICSS_EMacOsTTSCycTaskFnc(uint32_t a0, uint32_t a1);
#endif

/**
 *  @brief Function to initialize all Port Queue params
 *  @internal
 *  @retval 0 on success
 */
int32_t ICSS_EmacPortInit(ICSS_EmacHandle icssEmacHandle);

/**
 *  @brief Function to initialize Host Port Queue params
 *  @internal
 *  @param icssEmacHandle pointer to ICSS EMAC handle
 *  @retval 0 on success
 */
void ICSS_EmacHostInit(ICSS_EmacHandle icssEmacHandle);

/**
 *  @brief Function to initialize MAC Port Queue params
 *  @internal
 *  @param portNum Port number
 *  @retval 0 on success
 */
void ICSS_EmacMACInit(ICSS_EmacHandle icssEmacHandle, uint8_t portNum);
/**
 *  @brief Function to add Ether Type to approved list of protocols
 *  @internal
 *  @param icssEmacHandle pointer to ICSS EMAC handle
 *  @param protocolType 16 bit value indicating protocol type. IEEE format
 *  @retval 0 on success
 */
void addProtocolToList(uint16_t protocolType);
/**
 *  @brief Function to delete Rx semaphore and Task
 *  @internal
 *  @param icssEmacHandle pointer to ICSS EMAC handle
 *  @retval 0 on success
 */
int8_t ICSS_EmacOSDeInit(ICSS_EmacHandle icssEmacHandle);
/**

 *  @brief Function to initialize Rx semaphore and Task
 *  @internal
 *  @param icssEmacHandle pointer to ICSS EMAC handle
 *  @retval 0 on success
 */
int8_t ICSS_EmacOSInit(ICSS_EmacHandle icssEmacHandle);

/**
* @brief Callback function to process protocol specific handler for link status ISR
* @param icssEmacHandle pointer to ICSS EMAC handle
* @param callBack    Callback function pointer
* @param userArg    user specific parameter
*
* @retval none
*/
void ICSS_EmacRegisterPort0ISRCallback(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack callBack, void *userArg);
/**
* @brief Callback function to process protocol specific handler for link status ISR
*
* @param icssEmacHandle pointer to ICSS EMAC handle
* @param callBack    Callback function pointer
* @param userArg    user specific parameter
*
* @retval none
*/
void ICSS_EmacRegisterPort1ISRCallback(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack callBack, void *userArg);


/**
* @brief Function to status of Phy Link
*
* @param mdioBaseAddr       mdio subsystem base address
* @param phyAddr            physical address
* @param retries            retry count
*
* @retval 1 if phy link up, 0 phy link down
*/
uint32_t ICSS_EmacPhyLinkStatusGet(uint32_t mdioBaseAddr,
                                     uint32_t phyAddr,
                                     volatile uint32_t retries);


/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt for Transmit packet complete by PRU-ICSS firmware
 *
 *  @param[in]  hwIntRx    hardware interrupt transmit packet complete callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntTx( ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntTx);

/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt for TTS Cyclic Packet Insertion Notification by PRU-ICSS firmware
 *
 *  @param[in]  hwIntTTSCyc    hardware interrupt TTS cyclic packet insertion notification callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntTTSCyc(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntTTSCyc);

/**
 *  @b Description
 *  @n
 *      API Function to re-initialize all Port Queue params
 * 
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  portNumber number of the port to flush
 *  @retval None
 */
void ICSS_EmacPortFlush(ICSS_EmacHandle icssEmacHandle, int32_t portNumber);

/**
 *  @b Description
 *  @n
 *      Pacing Interrupt Handling routine for Rx packet 
 * 
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  args arguments if any
 *  @retval void
 */
void ICSS_EmacInterruptPacingISR(void *args);

/**
 *  @b Description
 *  @n
 *      API to poll driver for received packets, and/or link status, and/or 
        tranmission complete notification.
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  mode bitmap indicating poll type(s)  @ref ICSS_EmacIntrPollMode_e
 *  @retval     0 on scuess,  <0 on failure
 */
void ICSS_EmacPollControl(ICSS_EmacHandle icssEmacHandle, uint32_t mode);

/**
 *  \name ICSS_EmacUpdatePhyStatus
 *  @brief Update phy status for port number specified
 *
  *  @param  portNum port number 
 *  @param  icssEmacHandle handle to ICSS_EMAC Instance.
 *
 *  @retval none
 *
 */
void ICSS_EmacUpdatePhyStatus(uint8_t portNum,ICSS_EmacHandle icssEmacHandle);

#ifdef __cplusplus
}
#endif

#endif /* _ICSS_EMACDRV_H_ */
