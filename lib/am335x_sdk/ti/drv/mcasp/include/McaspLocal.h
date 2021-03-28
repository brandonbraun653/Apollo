/*
 * McaspLocal.h
 *
 * McASP Driver internal header file
 *
 * Copyright (C) 2007 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/*
 *  ======== mcasp/include/McaspLocal.h ========
 */

#ifndef MCASPLOCAL_H
#define MCASPLOCAL_H




#include <ti/drv/mcasp/mcasp_drv.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <ti/csl/cslr_mcasp.h>
#include <ti/csl/csl_mcasp.h>
/* Since SYS/BIOS does not support PWRM, presently this is commented out!!	  */

/* #if ((defined(CHIP_C6748) || defined(CHIP_OMAPL138)) && (!defined(BIOS_PWRM_ENABLE)))
 #error "Use Bios PWRM module only for the SoC"
 #else
    #include <ti/sysbios/family/c674/Power.h>
 #endif

 #if ((defined(CHIP_C6747) || defined(CHIP_OMAPL137)) && defined(BIOS_PWRM_ENABLE))
 #error "Do not use Bios PWRM module for this SoC"
 #endif
*/
#ifdef BIOS_PWRM_ENABLE
#include <ti/sysbios/family/c674/Power.h>
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#include <ti/csl/cslr_device.h>

#if defined(MCASP_UDMA_ENABLED)
#include <ti/drv/udma/include/udma_types.h>
#include <ti/drv/udma/udma.h>
#else
  #if defined(MCASP_EDMA_ENABLED)
    #include <ti/sdo/edma3/drv/edma3_drv.h>
  #endif
#endif

/* -------- constants -------- */

#define Mcasp_NUMSERIALIZERS      (16u)
/**<  This variable sets a limit on the maximum number of serializers that are*
 * possible in a given Mcasp instance.                                        */

#define Mcasp_MAX_NUM_CHANS       (0x02)
/**<  Maximum number of channels supported by the Mcasp instance              */

#define Mcasp_MAX_PACKET_SIZE     (32768u)
/**<  Maximum packet size in bytes                                            */

#define Mcasp_MAXLINKCNT          (2u)
/**<  Maximum number of EDMA jobs linked at a time (Must be 2).               */

#define Mcasp_TXEVENTQUE          (0u)
/**<  Transmit EDMA channel event queue number                                */

#define Mcasp_RXEVENTQUE          (1u)
/**<  Receive EDMA channel event queue number                                 */

#define MAX_FIFO_ALLOWED          (20U)
/*! The maximum FIFO depth that can be used                                   */
#define Mcasp_SM_RESET            (0u)
/**<  Reset value of xmt/rcv state m/c and frame sync                         */

#define Mcasp_TWO_PKTS_QUEUED     (2u)
/**<  When xmt is taken out of reset, it needs two words to                   *
 *  service it. This is used to keep tally of this requirement.               */

#define Mcasp_MAX_AFIFO_SIZE      (256U)
/*! The maximum depth of AFIFO in bytes                                       */

#define Mcasp_STATUS_INVALID      (0xFFFF)
/**<  Generic invalidate status                                               */

#define Mcasp_STATUS_VALID        (0x1)
/**<  Generic validate status                                                 */

#define Mcasp_DATA_RDY            (0x20u)
/**<  Interrupt due to: Data Ready                                            */

#define Mcasp_DMAERR              (0x80u)
/**<  Interrupt due to: DMA channel error                                     */

#define Mcasp_XMT_UNDERRUN        (0x1u)
/**<  Interrupt due to: Transmit Buffer Underrun                              */

#define Mcasp_RCV_OVERRUN         (0x1u)
/**<  Interrupt due to: Receive Buffer Overrun                                */

#define Mcasp_RSTAT_ERROR         (0x100u)
/**< Bit field to indicate if any receive error has occured                   */

#define Mcasp_XSTAT_ERROR         (0x100u)
/**< Bit field to indicate if any transmit error has occured                  */

#define Mcasp_TX_CLK_FAIL         (0x04u)
/**< Interrupt due to transmit clock failure                                  */

#define Mcasp_RX_CLK_FAIL         (0x04u)
/**< Interrupt due to receive clock failure                                   */

#define Mcasp_SYNCERR             (0x2u)
/**<  Interrupt due to: Transmit/Receive Sync Error                           */

#define Mcasp_OPT_TCINTEN_SHIFT   (0x00000014u)
/**<  Interrupt enable bit in OPT register for edma                           */

#define Mcasp_OPT_SYNCDIM_SHIFT   (0x00000002u)
/**<  Sync Type AB set bit of OPT register for edma                           */

#define Mcasp_OPT_TCC_SHIFT       (0x0000000Cu)
/**<  TCC set bit in OPT register for edma                                    */

#define Mcasp_OPT_TCC_MASK        (0x0003F000u)
/**<  Tcc mask in OPT register for edma                                       */

#define Mcasp_OPT_TCCMOD_SHIFT    (0x0000000Bu)
/**< Transfer completion selection bit                                        */

#define Mcasp_CNT_MAX_VAL         (0xFFFFu)
/**<  Max possible value of aCnt, bCnt and cCnt                               */

#define Mcasp_SWI_PRIORITY         0x01
/**< Priority of the swi thread which handles the interrupts                  */

#define Mcasp_MAX_PWRM_EVENTS      (Power_INVALIDEVENT)
/**< Max number of PWRM events for which the mcasp will register              */

#define Mcasp_MAX_PWRM_CONSTRAINTS (Power_DISALLOWEDSLEEPSTATE_MASK)
/**< Max number of constraints for which a moudule can register               */

/**
 * \def    Mcasp_POLLED_RETRYCOUNT
 *         This macro specifies the default retry count to be used by the Mcasp
 *         driver when polling for any hardware bit to be set or reset.
 *
 * \note   This default value used by the driver can be changed by an IOCTL
 *         "Mcasp_Ioctl_SET_TIMEOUT".
 */
#define Mcasp_POLLED_RETRYCOUNT   (0xFFFFu)

/* -------- enums -------- */

/**
 *  \brief Enumeration for channel mode
 */
typedef enum Mcasp_ChanMode_e
{
    Mcasp_ChanMode_FREE    = 0,       /**<  Channel not allocated             */
    Mcasp_ChanMode_XMT_DIT = 1u,      /**<  Transmit channel: DIT mode        */
    Mcasp_ChanMode_XMT_TDM = 2u,      /**<  Transmit channel: TDM mode        */
    Mcasp_ChanMode_RCV     = 3u       /**<  Receive channel                   */
}Mcasp_ChanMode;

/**
 *  \brief Enumeration for DIT channel index
 */
typedef enum Mcasp_DITRegIndex_e {
    Mcasp_DITRegIndex_0 = 0,
    /**<  1st DIT (channel/user data), (left/right) Register                  */
    Mcasp_DITRegIndex_1 = 1,
    /**<  2nd DIT (channel/user data), (left/right) Register                  */
    Mcasp_DITRegIndex_2 = 2,
    /**<  3rd DIT (channel/user data), (left/right) Register                  */
    Mcasp_DITRegIndex_3 = 3,
    /**<  4th DIT (channel/user data), (left/right) Register                  */
    Mcasp_DITRegIndex_4 = 4,
    /**<  5th DIT (channel/user data), (left/right) Register                  */
    Mcasp_DITRegIndex_5 = 5
    /**<  6th DIT (channel/user data), (left/right) Register                  */
}Mcasp_DITRegIndex;

/**
 *  \brief Mcasp driver state
 *
 *  Mcasp driver state enums used to track the driver state
 */
typedef enum Mcasp_DriverState_e {
    Mcasp_DriverState_DELETED,
    Mcasp_DriverState_CREATED,
    Mcasp_DriverState_INITIALIZED,
    Mcasp_DriverState_OPENED,
    Mcasp_DriverState_CLOSED,
    Mcasp_DriverState_DEINITIALIZED,
    Mcasp_DriverState_POWERED_DOWN,
    Mcasp_DriverState_PWRM_SUSPEND
}Mcasp_DriverState;

/**
 *  \brief Enumeration for the serializer mode
 */
typedef enum Mcasp_SerMode_e {
    Mcasp_SerMode_INACTIVE = 0,                /**< Serializer is inactive    */
    Mcasp_SerMode_XMT      = 1,                /**< Serializer is transmitter */
    Mcasp_SerMode_RCV      = 2                 /**< Serializer is receiver    */
}Mcasp_SerMode;

/**
 *  \brief Enumeration for serializer status
 */
typedef enum Mcasp_SerializerStatus_e {
    Mcasp_SerializerStatus_FREE = (0),/**< Serializer not allocated          */
    Mcasp_SerializerStatus_XMT  = (1),/**< Serializer configured to transmit */
    Mcasp_SerializerStatus_RCV  = (2) /**< Serializer configured to receive  */
}Mcasp_SerializerStatus;

/* -------- structs -------- */

/**
 *  \brief Enumeration for Hardware status commands
 */
typedef enum Mcasp_HwStatusQuery_e {
    /**
     * @brief   Return current transmit slot being transmitted
     * @param   (uint16_t *)
     */
    Mcasp_HwStatusQuery_CURRENT_XSLOT  = 1,
    /**
     * @brief   Return current receive slot being received
     * @param   (uint16_t *)
     */
    Mcasp_HwStatusQuery_CURRENT_RSLOT  = 2,
    /**
     * @brief   Return transmit error status bit
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_XSTAT_XERR     = 3,
    /**
     * @brief   Return transmit clock failure flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_XSTAT_XCLKFAIL = 4,
    /**
     * @brief   Return unexpected transmit frame sync flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_XSTAT_XSYNCERR = 5,
    /**
     * @brief   Return transmit underrun flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_XSTAT_XUNDRN   = 6,
    /**
     * @brief   Return transmit data ready flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_XSTAT_XDATA    = 7,
    /**
     * @brief   Return receive error status bit
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_RSTAT_RERR     = 8,
    /**
     * @brief   Return receive clock failure flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_RSTAT_RCLKFAIL = 9,
    /**
     * @brief   Return unexpected receive frame sync flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_RSTAT_RSYNCERR = 10,
    /**
     * @brief   Return receive overrun flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_RSTAT_ROVRN    = 11,
    /**
     * @brief   Return receive data ready flag status
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_RSTAT_RDATA    = 12,
    /**
     * @brief   Return whether the serializer is ready to receive or not
     * @param   (McaspSerQuery *)
     */
    Mcasp_HwStatusQuery_SRCTL_RRDY     = 13,
    /**
     * @brief   Return status whether the serializer is ready to transmit
     *          or not
     * @param   (SerQuery *)
     */
    Mcasp_HwStatusQuery_SRCTL_XRDY     = 14,
    /**
     * @brief   Return status whether serializer is configured to
     *          transmit/receive/inactive
     * @param   (SerQuery *)
     */
    Mcasp_HwStatusQuery_SRCTL_SRMOD    = 15,
    /**
     * @brief   Return the value of transmitter status register.
     * @param   (uint16_t *)
     */
    Mcasp_HwStatusQuery_XSTAT          = 16,
    /**
     * @brief   Return the value of receiver status register.
     * @param   (uint16_t *)
     */
    Mcasp_HwStatusQuery_RSTAT          = 17,
    /**
     * @brief   Return the transmit state machine and transmit frame sync
     *          generator values in transmitter global control register
     * @param   (uint8_t *)
     * @li          0x00 - Both transmit frame generator sync and transmit
     *                     state machine are reset.
     * @li          0x1  - Only transmit state machine is active.
     * @li          0x10 - Only transmit frame sync generator is active.
     * @li          0x11 - Both transmit frame generator sync and transmit
     *                     state machine are active.
     */
    Mcasp_HwStatusQuery_SM_FS_XMT      = 18,
    /**
     * @brief   Return the receive state machine and receive frame sync
     *          generator values in receiver global control register
     * @param   (uint8_t *)
     * @li          0x00 - Both receive frame generator sync and receive
     *                     state machine are reset.
     * @li          0x1  - Only receive state machine is active.
     * @li          0x10 - Only receive frame sync generator is active.
     * @li          0x11 - Both receive frame generator sync and receive
     *                     state machine are active.
     */
    Mcasp_HwStatusQuery_SM_FS_RCV      = 19,
    /**
     * @brief   Queries whether DIT mode is set or not
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_DIT_MODE       = 20,
    /**
     * @brief   Queries and returns the value in AMUTE register
     * @param   (Bool *)
     */
    Mcasp_HwStatusQuery_AMUTE          = 21,
    /**
     * @brief max number of queries
     */
    Mcasp_HwStatusQuery_MAX            = 22
}Mcasp_HwStatusQuery;

#if defined(MCASP_UDMA_ENABLED)
//=============================================================================
//  TX Function and Data Checker
//=============================================================================
typedef enum
{
	TX_CHAN,
	RX_CHAN
} TR_CHAN;

typedef enum
{
	TR0,
	TR1,
	TR2,
	TR3,
	TR9,
	TR15
} TR_TYPES;

typedef enum
{
	NAVSS_TRTYPE_TR0 = CSL_UDMAP_TR_FLAGS_TYPE_1D_DATA_MOVE,
	NAVSS_TRTYPE_TR1 = CSL_UDMAP_TR_FLAGS_TYPE_2D_DATA_MOVE,
	NAVSS_TRTYPE_TR2 = CSL_UDMAP_TR_FLAGS_TYPE_3D_DATA_MOVE,
	NAVSS_TRTYPE_TR3 = CSL_UDMAP_TR_FLAGS_TYPE_4D_DATA_MOVE,
	NAVSS_TRTYPE_TR4 = CSL_UDMAP_TR_FLAGS_TYPE_4D_DATA_MOVE_FORMATTING,
	NAVSS_TRTYPE_TR9 = CSL_UDMAP_TR_FLAGS_TYPE_4D_BLOCK_MOVE_REPACKING,
	NAVSS_TRTYPE_TR15 = CSL_UDMAP_TR_FLAGS_TYPE_4D_BLOCK_MOVE_REPACKING_INDIRECTION 
} NAVSS_TR_Type_e;

typedef enum
{
	NAVSS_TRANSFERTYPE_TR,
	NAVSS_TRANSFERTYPE_HOST,
	NAVSS_TRANSFERTYPE_MONOLITHIC,
} NAVSS_transferType_e;

typedef struct NAVSS_transferParams_s {
	void* transferConfig;
} NAVSS_transferParams ;


/*!
 *  @brief    
 */
typedef struct NAVSS_TR_DescParams_s {
   CSL_UdmapCppi5TRPD cppi5Desc;
	union {
	CSL_UdmapTR0  TR0;
	CSL_UdmapTR1  TR1;
	CSL_UdmapTR2  TR2;
	CSL_UdmapTR3  TR3;
	CSL_UdmapTR4  TR4;
	CSL_UdmapTR5  TR5;
	CSL_UdmapTR8  TR8;
	CSL_UdmapTR9  TR9;
	CSL_UdmapTR10 TR10;
	CSL_UdmapTR11 TR11;
	CSL_UdmapTR  generic;
  } u;
} NAVSS_TR_DescParams;

typedef struct Mcasp_DmaTransfer_t {
   void *hostAddr; 
   int32_t aCnt;
   int32_t bCnt;
   int32_t cCnt;
   
   int32_t bIndex;
   int32_t cIndex;
   
   uint32_t length;	
} Mcasp_MemTransferParams_t;

/*!
 *  @brief    Basic NAVSS Parameters
 */
typedef struct NAVSS_TR_Params_s {
	Mcasp_MemTransferParams_t hostMemTransferParams;
    NAVSS_TR_Type_e type;
	NAVSS_TR_DescParams descParams;
} NAVSS_TR_Params;


/* Data structure to capture the DMA transfer parameters */
typedef struct Mcasp_DMATranfer_Params_s {
	NAVSS_transferParams NAVSStransferParams;
	int loop;
}Mcasp_DMATranfer_Params_t;

#endif

/**
 *  \brief  McASP frame object params
 *
 *          Mcasp_IOBuf structures are managed by the driver. MCASP
 *          buffers are the basis for all I/O operations. 'cmd' field
 *          contains the command id for the driver. 'status' is filled
 *          in by the driver and contains the status of the commmand.
 */
typedef struct Mcasp_descQueueEntry_s
{
    Mcasp_QueueElem     link;
    /**< queue link                */

    void *descMem;
    /**< descriptor memory      */
} Mcasp_descQueueEntry_t;

/**
 *  \brief Channel Object
 *
 *  This structure maintains the current channel state. It also holds
 *  information on DMA channel being used and holds the application
 *  callback function to be called in case of an interrupt.
 *
 *  This structure is initialized by mdCreateChan and a pointer to this
 *  is passed down to all other channel related functions. Lifetime of
 *  the data structure is from its creation by mdCreateChan till it
 *  is invalidated by mdDeleteChan.
 */
typedef struct Mcasp_ChannelObj_s
{
    Mcasp_DriverState      chanState;
    /**<  Current state of the channel (opened or closed)                     */

    uint32_t                 mode;
    /**<  mode for channel (i.e _INPUT or OUTPUT)                          */

    void *                    devHandle;
    /**<  Pointer to McASP device driver port structure                       */

    MCASP_TiomCallback       cbFxn;
    /**<    call back function to be called once a packet is processed     */

    void *                    cbArg;
    /**<  Callback Function argument                                          */

    Mcasp_QueueElem                queueReqList;
    /**<  Queue containing the pending requests received from application.    */

    Mcasp_QueueElem                queueFloatingList;
    /**<  list to manage floating packets in DMA                              */

    uint32_t frSyncCtl;
    /**< Frame Sync Control Register                                          */

    uint32_t fmt;                    
    /**< Bit Stream Format Register                                           */
    
    uint32_t noOfChannels;
    /**< No of channels of data to be transmitted after the frame sync        */

    uint32_t                 indexOfSersRequested[Mcasp_NUMSERIALIZERS];
    /**<  Multi Serializer numbers requested by channel                       */

    Mcasp_ChanMode         channelOpMode;
    /**<  Mode of operation: Transmit(DIT/TDM) or Receive                     */

    uint32_t                 intStatus;
    /**<  Holds id of McASP interrupt cause, if any
        used in interrupt mode                                                */

    MCASP_Packet             *dataPacket;
    /**<  Current data packet being serviced.                                 */

    MCASP_Packet             *tempPacket;
    /**<  Temp IOP holder                                                     */

    volatile Bool          isTempPacketValid;
    /**<  Valid packet flag in EDMA callback                                  */

    uint32_t                 userDataBufferSize;
    /**<  Size of the data buffer per serialiser, hence the buffer given by   *
     * the application should really be userDataBufferSize * no. of           *
     * serialisers allocated for that channel                                 */

    int32_t                  submitCount;
    /**<  Number of submit calls pending                                      */

    int32_t                 maxActiveSubmit;
    /**< Max number of active buffers to be recycled by DMA.  Any additional
     * buffers submitted by the application will get placed into the pending
     * queue.
     */

#ifdef MCASP_EDMA_ENABLED
    void *                    edmaHandle;
    /**<  Edma Handle                                                         */

    uint32_t                 xferChan;
    /**<  EDMA  ChannelID                                                     */

    uint32_t                 tcc;
    /**<  EDMA  tcc                                                           */

    uint32_t                 pramTbl[2u];
    /**<  Logical channel numbers of EDMA, which are used for linking         */

    uint32_t                 pramTblAddr[2u];
    /**<  Physical address of logical channel numbers of EDMA, which          *
         * are used for linking                                               */

    uint32_t                 nextLinkParamSetToBeUpdated;
    /**<  Used to store the next index of link param to be updated            */

    EDMA3_RM_TccCallback     edmaCallback;
    /**<  stores the edma call back function ptr - functions actual type is   *
     * EDMA3_RM_TccCallback                                                   */

#else
    Bool               firstPacket;
    /**<  first packet since reset                                      */

    Bool               udmaEnabled;
    /**<  If the UDMA/PDMA path is enabled                              */

    void *                nextTR;

    /**<  This member will hold the error status -normally updated from       *
     * cpu interrupt thread and is used in UDMA completion thread for         *
     * updating the error code in IOP                                         */

      NAVSS_TR_Params     trParams;
      Mcasp_QueueElem                queueFreeDesc;
      Mcasp_QueueElem                queueTransitDesc;
      Mcasp_descQueueEntry_t         freeDescMem[MCASP_NUM_FREE_DESCS];
      void   *dmaCallback;
#endif

    int32_t                 cpuEventNum;
    /**<  This hold the cpu event no. of this channel (TX/Rx) for this        *
     * instance                                                               */

    int32_t                 intNum;
    /**<  This hold the interrupt vector for this channel instance            */

    /**<  SOC Mux Configuration */
    int32_t                   muxNum;

    int32_t                   muxInEvent;

    int32_t                   muxOutEvent;

    void *                    loopJobBuffer;
    /**<  Buffer to be transferred when the loop job is running               */

    int32_t                  currentPacketErrorStatus;
    /**<  This member will hold the error status -normally updated from       *
     * cpu interrupt thread and is used in EDMA completion thread for         *
     * updating the error code in IOP                                         */

    Mcasp_GblCallback        gblErrCbk;
    /**<  callback required when the loop job is running must be callable     *
     * directly from the  layer                                            */

    Mcasp_BufferFormat       dataFormat;
    /**< Application supplied buffer format                                   */

    Mcasp_OpMode             channelMode;
    /**< channel operation mode TDM or DIT mode                               */

    Mcasp_WordBitsSelect       wordBitsSelect;
    /**< Option to indicate the word alignment (MSB/LSB) if word size < slot size.
     * Mcasp_WordAlign_LSB  = Select the Least significant 'word' sized bits in the slot bits
     * Mcasp_WordAlign_MSB  = Select the Most  significant 'word' sized  bits in the slot  */
     
    uint32_t                 userIntValue;
    /**< User supplied mask for the interrupts to be enabled                  */

    uint16_t                 noOfSerAllocated;
    /**<  no of Serializer(s) allocated                                       */

    uint16_t                 dataQueuedOnReset;
    /**<  McASP needs to service each serializer with two
        words when it awakes from reset                                       */

    uint16_t                 noOfSlots;
    /**< number of slots used by the mcasp                                    */

    uint16_t                 hwFifoEventDMARatio;
    /**<  This represents the ratio WNUMEVT/WNUMDMA of the MCAPS FIFOCTL register *
     *  In other words, this represents the DMA event(to/from Host) throttle factor
     *  i.e a DMA event will be sent to Host (EDMA controller) only if 'hwFifoEventDMARatio'
     *  events reach the McASP FIFO by the peripheral. This way the number of the DMA
     *  events to/from the Host (EDMA controller) is reduced leading to reduced host overheads
     *  due to a DMA transfer. For example, if hwFifoEventDMARatio=4, a DMA read/write event is
     *  sent to the Host only when 4 such events reach the FIFO from the peripheral.    */

    uint16_t                 loopJobLength;
    /**<  Length of userloop job for each serialiser                          */

    uint16_t                 userLoopJobLength;
    /**< Length of the user supplied loop job buffer                          */

    uint16_t                 roundedWordWidth;
    /**<  Word length bytes to be transferred for DMA transaction             */

    uint16_t                 currentDataSize;
    /**<  data packet size used for interrupt mode                            */

    Bool                   isDmaDriven;
    /**<  Determines whether data input is using DMA or not                   */

    volatile Bool          loopjobUpdatedinParamset;
    /**<  Used to prevent updating second paramset with loopjob for last      *
     * datapacket edma callback                                               */

    volatile Bool          xferinProgressIntmode;
    /**<  use to start int mode transfer from  0 packet status                */

    volatile Bool          bMuteON;
    /**<  True, if playback is muted                                          */

    volatile Bool          paused;
    /**<  TRUE, if pause Request is called                                    */

    volatile Bool          nextFlag;
    /**<  TRUE, if pause Request is called                                    */

    Bool                   enableHwFifo;
    /**< whether the FIFO has to be enabled for this channel                  */

    Bool                   isDataPacked;
    /**< flag to indicate if the buffer data needs to be packed               */

    Bool                   userLoopJob;
    /**< Option to indicate if the user loop job is used or driver loop job   */

     
}Mcasp_ChannelObj;

/**
 *  \brief Structure used to supply the information for the Mcasp setup
 */
typedef struct Mcasp_DevParams_s
{
    Bool            enablecache;
    /**< Submitted buffers are in cacheable memory                            */

    Bool            isDataBufferPayloadStructure;
    /**< Submitted buffers have payload information present or absent         */

    Mcasp_HwSetup   *mcaspHwSetup;
    /**<  Initial setup for the McASP                                         */

}Mcasp_DevParams;

/**
 *  \brief Hardware specific information structure
 */
typedef struct Mcasp_HwObj_s
{
	uint32_t regs;
    /**< Pointer to the register overlay structure for the peripheral         */

    CSL_AfifoRegsOvly    fifoRegs;
    /**< pointer to the register overlay structure for the FIFO               */

    volatile void *         dataAddr;
    /**< Instance Data Address                                                */

    Bool                 ditStatus;
    /**< Support for DIT mode  in hardware                                    */

    uint16_t               numOfSerializers;
    /**< Number of serializers                                                */

    int32_t               cpuTxEventNum;
    /**< This holds the CPU event no. of Tx                                   */

    int32_t               cpuRxEventNum;
    /**< This holds the CPU event no. of Rx                                   */

    uint32_t               dmaTxEventNum;
    /**< dma Transmit event number                                           */

    uint32_t               dmaRxEventNum;
    /**< dma Receive event number                                            */
	
	int32_t               txIntNum;
    /**< Interrupt vector number Tx */

    int32_t               rxIntNum;
   /**< Interrupt vector number Rx */

    int32_t   muxNum;
   /**< SOC Mux Configuration for Interrupts  */

    int32_t   txMuxInEvent;
    /**< This holds the Tx Mux Input event                                    */
    
    int32_t   txMuxOutEvent;
    /**< This holds the Tx Mux Output event                                   */
    
    int32_t   rxMuxInEvent;
    /**< This holds the Rx Mux In Event Rx                                    */
    
    int32_t   rxMuxOutEvent;
    /**< This holds the Rx Mux Out Event Rx                                   */

    uint32_t               pwrmLpscId;
    /**< LPSC number for this instance                                        */

    uint32_t               pscInstance;
    /**< Instance of the PSC which controls this module's instance            */
    
#if defined(MCASP_UDMA_ENABLED)
    Mcasp_dmaInfo_t dmaInfo;
    /* DMA info used for UDMA configuration */
#endif

    void*         dmaHandle;
    /* DMA handle to be provided at run-time via application */
}Mcasp_HwObj;

/**
 * \brief structure holding the information required for the ISR to service the
 *        appropriate instance.
 */
typedef struct Mcasp_IsrObject_s
{
    Bool          isIsrRegistered[Mcasp_MAX_NUM_CHANS];
    /**< Hardware instance number of the device registering the interrupt   */

    Bool           chanEnabled[Mcasp_MAX_NUM_CHANS];
    /**< variable to indicate whether the channel has registered interrupts */

    struct Mcasp_Object_s  *instHandle;
    /**< pointer to the driver instance object                              */

    /* Swi_Handle     isrSwiTaskHandle; */
    void * isrSwiTaskHandle;
    /**< Handle to the SWI tasklet that will be handling all the interrupts */

}Mcasp_IsrObject;

/**
 *  \brief Module specific parameters. Present implementation doesn't have
 *  any module specific parameters.
 */
typedef struct Mcasp_HwParam_s
{
    uint16_t flags;
    /**<
     *  Bit mask to be used for module specific parameters.
     *  The below declaration is just a place-holder for future
     *  implementation.
     */
}Mcasp_HwParam;

/**
 *  \brief The following structure will be used in
 *  MCASP_HwStatusQuery_SRCTL_SRMOD
 */
typedef struct Mcasp_SerModeQuery_s {
    Mcasp_SerializerNum   serNum;
    /**< Serializer number                                                    */
    Mcasp_SerMode         serMode;
    /**< Serializer mode                                                      */
}Mcasp_SerModeQuery;

/**
 *  \brief The following structure will be used in
 *  MCASP_HwStatusQuery_SRCTL_RRDY, and MCASP_HwStatusQuery_SRCTL_XRDY
 */
typedef struct Mcasp_SerQuery_s {
    Mcasp_SerializerNum   serNum;
    /**< Serializer number                                                    */
    Bool                  serStatus;
    /**< Return value of the query                                            */
}Mcasp_SerQuery;

/**
 *  \brief Loopjob buffers used in EDMA mode
 */
typedef struct Mcasp_TempBuffer_s
{
    uint8_t   scratchBuf[(4u) + Mcasp_CACHE_LENGTH];
    /* This buffer will be aligned and also the same buffer will be used      *
     * for all serializers and also only 4 bytes are required because the     *
     * max wordwidth is 4 and the cache length is used for alignment          */
    uintptr_t *scratchBuffer;
}Mcasp_TempBuffer;


#ifdef BIOS_PWRM_ENABLE
/**
 * \brief   Strcuture to hold the information related to the PWRM.
 */
typedef struct Mcasp_pwrmInfo_t_s
{
    Mcasp_pllDomain        pllDomain;
    /**< Pll domain to be used for the device                                 */

    Bool                   ioSuspend;
    /**< whether the driver is in IO suspend mode (PWRM change is in progress)*/

    Power_Event             pwrmEvent;
    /**< Current pwrm event being processed                                   */

    uint32_t                 constraintMask;
    /**< Constraint mask (for information only)                               */

    uint32_t                 dependencyCount;
    /**< Current dependency count when the driver is going for sleep or
     * deepsleep                                                              */

    Power_NotifyHandle      notifyHandle[Mcasp_MAX_PWRM_EVENTS];
    /**< Handles required for unregistering of the events with PWRM           */

    Fxn                    delayedCompletionFxn[Mcasp_MAX_PWRM_EVENTS];
    /**< delayed completion callback function pointer                         */

    Power_ConstraintHandle  constraintHandle[Mcasp_MAX_PWRM_CONSTRAINTS];
    /**< Handles required for unregistering of the constraints with PWRM      */
}Mcasp_pwrmInfo;
#endif


/* -------- module-wide state -------- */
/**
 *  \brief module-wide state
 *
 *  inUse in module state points to an array whose size is soc specific
 *  Pointer used to match IDriver codebase.
 */
typedef struct Mcasp_Module_State_s
{
    Bool             *inUse;

    Mcasp_IsrObject  *isrObject;
} Mcasp_Module_State;

/* -------- per-instance state -------- */
/**
 *  \brief per-instance state
 */
typedef struct Mcasp_Object_s
{
    uint16_t                   instNum;
    /**< Preserve  instance number in port                                    */

    Mcasp_DriverState        devState;
    /**< stores the current state of the driver                               */

    Bool                     isDataBufferPayloadStructure;
    /**< Input request is a flat data buffer or a  payload                    *
     * structure                                                              */

    Mcasp_HwSetup            mcaspHwSetup;
    /**< Hw parmas to configure mcasp                                         */

    Bool                     enablecache;
    /**< Submitted buffers are in cacheable memory                            */

    Bool                     stopSmFsXmt;
    /**< Status of stoping state m/c for XMT                                  */

    Bool                     stopSmFsRcv;
    /**< Status of stoping state m/c for RCV                                  */

    Mcasp_ChannelObj         XmtObj;
    /**< Holds transmit channel to the McASP.                                 */

    Mcasp_ChannelObj         RcvObj;
    /**< Holds receive channel to the McASP.                                  */

    Mcasp_HwObj              hwInfo;
    /**< McASP handle for initial port configuration                          */

    Mcasp_SerializerStatus   serStatus[Mcasp_NUMSERIALIZERS];
    /**< Holds status information for both the serializers.                   *
     *  - Valid values are FREE, XMT and RCV                                  */
#ifdef BIOS_SWI
    Swi_Struct                  isrSwiObject;
    MCASP_Swi_Struct isrSwiObject;   */
    /**< SWI to handle the interrupts                                         */

    /*Swi_Struct                  fifoSwiObject;
    MCASP_Swi_Struct fifoSwiObject;     */
#endif
    /**< SWI object for the swi used to handle the FIFO not empty while the   *
     * last packet callback is in progress                                    */

    uint32_t                   retryCount;
    /**< The retry count value to be used when waiting for the TX empty to be *
     * set                                                                    */

    Bool                     loopJobMode;
    /**< Variable to check if the loop job mode is enabled or not             */

    Bool                     pscPwrmEnable;
    /**< Option to enable or disable the PSC control in the driver            */

    void *                 prcmHandle;
    /**< Handle to the prcm instance to be used to switch on the instance     */

    int32_t                   prcmDevId;
    /* prcm device ID */
#ifdef BIOS_PWRM_ENABLE
    Mcasp_pwrmInfo           pwrmInfo;
#endif
    /**< structure to hold the PWMR related information                       */

} Mcasp_Object;


/* -------- typedefs -------- */

typedef Mcasp_ChannelObj   *Mcasp_ChannelHandle;
typedef Mcasp_HwObj        *Mcasp_HwHandle;
#ifdef Mcasp_LOOPJOB_ENABLED
extern Mcasp_TempBuffer          Mcasp_loopDstBuf[MCASP_CNT];
extern Mcasp_TempBuffer          Mcasp_loopSrcBuf[MCASP_CNT];
#endif

extern int32_t Mcasp_localConfigRcvSection(Mcasp_Object       *instHandle,
                                         Mcasp_HwSetupData  *const rcvData);

extern int32_t Mcasp_localConfigXmtSection(Mcasp_Object       *instHandle,
                                         Mcasp_HwSetupData  *const xmtData);

extern int32_t Mcasp_localSmReset(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localSmSet(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localAbortReset(Mcasp_ChannelHandle chanHandle);

extern void Mcasp_localCompleteCurrentIo(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localResetXmt(Mcasp_HwHandle  hMcasp);

extern int32_t Mcasp_localResetRcv(Mcasp_HwHandle  hMcasp);

extern int32_t Mcasp_localDmaProcessPkt(void *chanp, MCASP_Packet *ioPacket);

extern int32_t Mcasp_localCancelAndAbortAllIo(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localSetupHwInfo(Mcasp_HwHandle        hMcasp,
                                   const Mcasp_HwSetup  *myHwSetup);

extern int32_t Mcasp_localActivateSmFsForBoth(const Mcasp_Object *instHandle);

extern int32_t Mcasp_localActivateSmFsForXmt(const Mcasp_Object *instHandle);

extern int32_t Mcasp_localActivateSmFsForRcv(const Mcasp_Object *instHandle);

extern int32_t Mcasp_localDeactivateSmFsForXmt(const Mcasp_Object *instHandle);

extern int32_t Mcasp_localDeactivateSmFsForRcv(const Mcasp_Object *instHandle);


extern int32_t Mcasp_localSubmitIoctl(Mcasp_ChannelHandle      chanHandle,
                                    Uns                      cmd,
                                    void *                      arg,
                                    void *                      param);

/* Below operations are used for DMA interface by driver */
void    Mcasp_initChanDmaObj(Mcasp_ChannelHandle chanHandle);
int32_t Mcasp_setupDmaDuringOpen(Mcasp_ChannelHandle chanHandle,
                                 Mcasp_HwObj *hwInfo);
int32_t Mcasp_enableDMA(Mcasp_ChannelHandle chanHandle);
int32_t Mcasp_disableDMA(Mcasp_ChannelHandle chanHandle);
int32_t Mcasp_submitPktToDma(Mcasp_ChannelHandle chanHandle,
                             MCASP_Packet *const ioPacket);
void    Mcasp_getDmaPosition(Mcasp_ChannelHandle chanHandle, uint32_t *dmaPos);
void    Mcasp_clearDmaErrors(Mcasp_ChannelHandle chanHandle);
int32_t Mcasp_setupDmaChan(Mcasp_ChannelHandle chanHandle);
void    Mcasp_initiateDummyDMAXfer(Mcasp_ChannelHandle chanHandle);
int32_t Mcasp_freeDmaChannel(Mcasp_ChannelHandle chan_handle);
void    Mcasp_triggerDMA(Mcasp_ChannelHandle chanHandle);
void    Mcasp_commonDmaCallback(Mcasp_ChannelHandle chanHandle, int32_t status);

#if defined(MCASP_UDMA_ENABLED)
/* UDMA internal functions */
void Mcasp_localUdmaCallback(Mcasp_ChannelHandle chanHandle,int32_t status,uint32_t size);
void Mcasp_localUdmaCallback_Tx(void *instHandle,int32_t status,uint32_t size);
void Mcasp_localUdmaCallback_Rx(void *instHandle,int32_t status,uint32_t size);
int32_t mcaspEnableUDMATransfer(Mcasp_ChannelHandle handle);
int32_t mcaspDisableUDMATransfer(Mcasp_ChannelHandle handle);
int32_t Mcasp_localUpdtDtPktToLnkPrms(Mcasp_ChannelHandle       chanHandle,
                                    MCASP_Packet *const         ioPacket);
int32_t Mcasp_localGetIndicesSyncType(Mcasp_ChannelHandle chanHandle,
                                    volatile int16_t     *bIndex,
                                    volatile int16_t     *cIndex,
                                    volatile uint16_t    *aCnt,
                                    volatile uint16_t    *bCnt,
                                    volatile uint16_t    *cCnt,
                                    uint32_t             *trType,
                                    Bool                forLoopJobBuf);
int32_t Mcasp_enableUDMA_PDMA_Channel(Mcasp_ChannelHandle chanHandle);
#else
/* EDMA internal functions */
extern void Mcasp_localEdmaCallback(uint32_t              tcc,
                                    EDMA3_RM_TccStatus  status,
                                    void *                 data);
extern int32_t Mcasp_localGetIndicesSyncType(Mcasp_ChannelHandle chanHandle,
                                           volatile int16_t     *bIndex,
                                           volatile int16_t     *cIndex,
                                           volatile uint16_t    *aCnt,
                                           volatile uint16_t    *bCnt,
                                           volatile uint16_t    *cCnt,
                                           EDMA3_DRV_SyncType *syncType,
                                           Bool                forLoopJobBuf);
#endif

extern int32_t Mcasp_localAbortRequests(void * handle,void * arg);

extern void Mcasp_localGetNextIndex(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localLpscOff(const Mcasp_Object *instHandle);

extern int32_t Mcasp_localIsValidPacket(Mcasp_ChannelHandle chanHandle);

extern int32_t Mcasp_localLpscOn(const Mcasp_Object *instHandle);

extern int32_t Mcasp_loadPendedIops(Mcasp_ChannelObj *chanHandle);

extern void Mcasp_localLoadPktToDma(Mcasp_ChannelObj *chanHandle,MCASP_Packet *ioPacket);

extern void Mcasp_localHandlePwrmEvent(Mcasp_Object     *instHandle,
                                       Mcasp_ChannelObj *chanHandle);
extern int32_t Mcasp_localCollectXmtErrorStats(Mcasp_ChannelHandle chanHandle,Mcasp_errCbStatus   *errStatus);

extern int32_t Mcasp_localCollectRcvErrorStats(Mcasp_ChannelHandle chanHandle,Mcasp_errCbStatus   *errStatus);

extern int32_t Mcasp_localCalcWordWidth(Mcasp_ChannelHandle chanHandle, 
                                        uint16_t wordWidth, 
                                        uint16_t *tempRoundedWordWidth);

#ifndef Mcasp_LOOPJOB_ENABLED
extern void Mcasp_swiTxFifo(void * arg0,void * arg1);
#endif

#ifdef __cplusplus
}
#endif
#endif  /*MCASPLOCAL_H */
