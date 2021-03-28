/*
 * Mcasp_drv.h
 *
 * This file contains Application programming interface for the McASP driver and 
 * command/macro definitions used by the McASP driver.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \defgroup DRV_MCASP_MODULE MCASP Driver
 *
 *  @{
 */
 /* @} */
 
 /**
 *  \ingroup DRV_MCASP_MODULE
 *  \defgroup DRV_MCASP_API_MODULE MCASP Driver API
 *            MCASP driver interface
 *
 *  @{
 */
 
 /**
 * \file        mcasp_drv.h
 *
 * \brief       McASP driver interface definition file
 *
 *              This file contains the interfaces, data types and symbolic
 *              definitions that are needed by the application to utilize the
 *              services of the McASP device driver.
 *
 *              (C) Copyright 2019, Texas Instruments, Inc
 *
 */
 
#ifndef MCASP_H
#define MCASP_H

#include "mcasp_types.h"
#include <ti/osal/osal.h>
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*/
/*                         MACRO TYPES                                        */
/*============================================================================*/

#define Mcasp_CACHE_LENGTH  (128u)
/**< cache line length                                                        */

#define Mcasp_NUMSERIALIZERS (16u)
/**< Number of serializers on mcasp                                           */

#define Mcasp_GBLCTL_TIMEOUT  (30000U)
/**< The time to try (in Msec) before the GBLCTL register setting timeouts    *
 *   if the setting/resetting is done in a context other than a task this will*
 *   be used as a retry count rather than the MSec timeout                    */

/* McASP return values */
#define  MCASP_EBADIO        (-(1))      /* Generic failure condition */
#define  MCASP_ETIMEOUT      (-(2))      /* Timeout occurred */
#define  MCASP_ENOPACKETS    (-(3))      /* No packets available for I/O */
#define  MCASP_EFREE         (-(4))      /* Unable to free resources */
#define  MCASP_EALLOC        (-(5))      /* Unable to alloc resource */
#define  MCASP_EABORT        (-(6))      /* I/O was aborted before completed */
#define  MCASP_EBADMODE      (-(7))      /* Illegal device mode */
#define  MCASP_EOF           (-(8))      /* End-of-File was encountered */
#define  MCASP_ENOTIMPL      (-(9))      /* Operation not implemented or supported */
#define  MCASP_EBADARGS      (-(10))     /* Illegal arguments specified */
#define  MCASP_ETIMEOUTUNREC (-(11))     /* Unrecoverable timeout occurred */
#define  MCASP_EINUSE        (-(12))     /* Device already in use */
#define  MCASP_EINVALIDVAL   (-(13))     /* Invalid value encountered (Unexpected) */
#define  MCASP_COMPLETED     (0)       /* I/O completed successfully */
#define  MCASP_PENDING       (1)       /* I/O queued and pending */

/*
 * I/O request flushed. Queued writes will be completed w/ MCASP_COMPLETED.
 *   Queued read requests return w/ MCASP_FLUSHED.
 */
#define  MCASP_FLUSHED      2
/*
 * I/O aborted. Non-completed read or write requests return w/ MCASP_ABORTED.
 */
#define  MCASP_ABORTED      3
/*============================================================================*/
/*                         ENUMERATED DATA TYPES                              */
/*============================================================================*/
/**
 *  \brief enumerated constants for the channel modes supported by Mcasp
 */
typedef enum Mcasp_chanMode_e {
   MCASP_INPUT    = 0x0001,  /**< McASP channel receives data                */
   MCASP_OUTPUT   = 0x0002,  /**< McASP channel transmits data               */ 
   MCASP_INOUT    = (MCASP_INPUT | MCASP_OUTPUT)  /**< McASP channel transmits & recieves data  */ 
} Mcasp_chanMode_e;

/**
 *  \brief enumerated constants for the commands supported by Mcasp
 */
typedef enum Mcasp_IOcmd_e {
  MCASP_READ       = 0,  /**< Command to perform Read data             */
  MCASP_WRITE      = 1,  /**< Command to perform Write data            */
  MCASP_ABORT      = 2,  /**< Command to abort local transactions      */
  MCASP_FLUSH      = 3   /**< Command to flush transactions            */
}Mcasp_IOcmd_e;
/**
 *  \brief enumerated constants for the Transfer modes supported by Mcasp
 */
typedef enum Mcasp_OpMode_e {
    Mcasp_OpMode_TDM = 0,                /**< TDM Mode for channel operation  */
    Mcasp_OpMode_DIT = 1                 /**< DIT Mode for channel operation  */
}Mcasp_OpMode;

/**
 *  \brief Enumeration for the MCASP serializer numbers
 */
typedef enum Mcasp_SerializerNum_e {
    Mcasp_SerializerNum_0  = 0,           /**< Serializer 0                   */
    Mcasp_SerializerNum_1  = 1,           /**< Serializer 1                   */
    Mcasp_SerializerNum_2  = 2,           /**< Serializer 2                   */
    Mcasp_SerializerNum_3  = 3,           /**< Serializer 3                   */
    Mcasp_SerializerNum_4  = 4,           /**< Serializer 4                   */
    Mcasp_SerializerNum_5  = 5,           /**< Serializer 5                   */
    Mcasp_SerializerNum_6  = 6,           /**< Serializer 6                   */
    Mcasp_SerializerNum_7  = 7,           /**< Serializer 7                   */
    Mcasp_SerializerNum_8  = 8,           /**< Serializer 8                   */
    Mcasp_SerializerNum_9  = 9,           /**< Serializer 9                   */
    Mcasp_SerializerNum_10 = 10,          /**< Serializer 10                  */
    Mcasp_SerializerNum_11 = 11,          /**< Serializer 11                  */
    Mcasp_SerializerNum_12 = 12,          /**< Serializer 12                  */
    Mcasp_SerializerNum_13 = 13,          /**< Serializer 13                  */
    Mcasp_SerializerNum_14 = 14,          /**< Serializer 14                  */
    Mcasp_SerializerNum_15 = 15           /**< Serializer 15                  */
}Mcasp_SerializerNum;

/**
 *  \brief Enumerated constant for wordlength supported by the MCASP device
 */
typedef enum Mcasp_WordLength_e {
    Mcasp_WordLength_8  = 8u,           /**< Word length of 8 bits            */
    Mcasp_WordLength_12 = 12u,          /**< Word length of 12 bits           */
    Mcasp_WordLength_16 = 16u,          /**< Word length of 16 bits           */
    Mcasp_WordLength_20 = 20u,          /**< Word length of 20 bits           */
    Mcasp_WordLength_24 = 24u,          /**< Word length of 24 bits           */
    Mcasp_WordLength_32 = 32u           /**< Word length of 32 bits           */
}Mcasp_WordLength;

/**
 *  \brief Enumerated constant for selecting MSB/LSB word in the slot bits
 */
typedef enum Mcasp_WordBitsSelect_e {
    Mcasp_WordBitsSelect_LSB  = 0u,           /**< Select the Least significant 'word' sized bits in the slot bits */
    Mcasp_WordBitsSelect_MSB  = 1u           /**< Select the  Most significant 'word' sized  bits in the slot  */
}Mcasp_WordBitsSelect;
/**
 * \brief  PLL domain to be used by the device
 */
typedef enum Mcasp_pllDomain_t
{
    Mcasp_pllDomain_0 = 0,
    /**< PLL domain 0          */

    Mcasp_pllDomain_1 = 1,
    /**< PLL domain 1          */

    Mcasp_pllDomain_NONE = 2
    /**< Not in any pll domain */

}Mcasp_pllDomain;


/**
 * \brief Enum to specify the supported buffer formats.
 *
 * Interleaved and non-interleaved is standard format, this enumeration
 * captures the standard and custom data formats.
 */
typedef enum Mcasp_BufferFormat_e
{
    /* This mode is used for buffer containing the data in continous      *
     * memory locations where each sample is  "wordWidth" long. This      *
     * format is supported for following configurations                   *
     *
     * Single serializer in DSP mode.DIT mode also can use this format    *
     *                                                                    *
     * Note : interleaved and non interleaved does not apply for this     *
     * buffer format                                                      */
    Mcasp_BufferFormat_1SER_1SLOT,

    /* This is used for transfer of data on a single serializer with      *
     * multiple slots.please note that the slot data is not interleaved   *
     * in this format.                                                    *
     *                                                                    *
     * TDM with single serializer and slots > 1 uses this format.DIT can  *
     * also use this format                                               */
    Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED,
    /* This is used for transfer of data on a single serializer with      *
     * multiple slots.please note that the slot data is interleaved       *
     * in this format.                                                    *
     *                                                                    *
     * TDM with single serializer and slots > 1 uses this format. DIT     *
     * mode can also be supported here                                    */
    Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED,

    /* This is used for transfer of data on a single slot with  multiple  *
     * serializers enabled.please note that the serializer data is        *
     * interleaved in this format.                                        *
     *                                                                    *
     * DSP and DIT mode with multiple serializer uses this format         */
    Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED,

    /* This is used for transfer of data on a single slot with  multiple  *
     * serializers enabled.please note that the serializer data is        *
     * interleaved in this format.                                        *
     *                                                                    *
     * DSP and DIT mode with multiple serializer uses this format         */
    Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED,

    /* This is used for transfer of data with  multiple serializers and   *
     * also multiple slots enabled.please note that the serializer data is*
     * interleaved in this format. The slot data is also interleaved      *
     * Refer to the user guide to view the sample data format.            *
     *
     * TDM and DIT mode with multiple serializer and multiple slots uses  *
     * this format                                                        */
    Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1,

    /* This is used for transfer of data with  multiple serializers and   *
     * also multiple slots enabled.please note that the serializer data is*
     * NOT interleaved in this format. The slot data is interleaved       *
     * Refer to the user guide to view the sample data format.            *
     *
     * TDM and DIT mode with multiple serializer and multiple slots uses  *
     * this format                                                        */
    Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2

    /* we are unable to support this buffer format because the MCASP gives*
     * tx underrun error.
     * When 2 serializers are configured in 2 slot mode each. The MCASP   *
     * even though it receives two 16 bit samples it considers it as only *
     * one 32 bit sample because of which it will always give an underrun *
     * error. Hence this buffer format cannot be supported                *
     * This is used for transfer of data with  multiple serializers and   *
     * also multiple slots enabled.please note that the slot data is      *
     * NOT interleaved in this format. The serializer data is interleaved *
     * Refer to the user guide to view the sample data format.            *
     *
     * TDM and DIT mode with multiple serializer and multiple slots uses  *
     * this format                                                        *
    BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_3,
     */
}Mcasp_BufferFormat;

/* -------- typedefs -------- */
/**
 *  \brief structure to hold the error condition and the status
 *
 *  This is the structure which holds the error condition and also the error
 *  status. Depending on the error status the application can take the decision
 *  to recover from the error
 */
typedef struct
{
    bool  isDMAErr;
    /**< DMA Error           */
    bool  isRcvOvrRunOrTxUndRunErr;
    /**< Receive OverRun on Transmir UnderRun Error           */
    bool  isClkFailErr;
    /**< Clock Fail Error           */
    bool  isSyncErr;
    /**< Sync Error           */
    uint32_t retVal;
    /**< return value           */
}Mcasp_errCbStatus;
/**
 *  \brief Global error callback function protype
 *
 *  This is the global error callback function for the McASP driver.
 *  This function is called directly called from ISR context in
 *  case of error.
 */
typedef void (*Mcasp_GblCallback)(Mcasp_errCbStatus errCbStat);

/**
 *  \brief Mcasp Interrupt service routine
 *
 *  This is Function pointer to the McASP ISR. Interrupt registration takes
 *  place by hooking the ISR to the interrrupt number.
 */
typedef void (*Mcasp_Isr)(void *arg);

/* -------- structs -------- */

/**
 *  \brief Hardware setup data clock structure
 */
typedef struct Mcasp_HwSetupDataClk_s {
    uint32_t clkSetupClk;             /**< Clock details ACLK(R/X)CTL           */
    uint32_t clkSetupHiClk;           /**< High clock details AHCLK(R/X)CTL     */
    uint32_t clkChk;                  /**< Configures RX/TX CLK fail detect     */
}Mcasp_HwSetupDataClk;

/**
 *  \brief Hardware setup global structure
 */
typedef struct Mcasp_HwSetupGbl_s {
    uint32_t pfunc;                      /**< Pin function register             */
    uint32_t pdir;                       /**< Pin direction register            */
    uint32_t ctl;                        /**< Global control register - GBLCTL  */
    uint32_t ditCtl;                     /**< whether McASP operates in DIT mode*/
    uint32_t dlbMode;                    /**< Digital loopback mode setup       */
    uint32_t amute;                      /**< Mute control register - AMUTE     */
    uint32_t serSetup[16u];              /**< Setup serializer control register */
}Mcasp_HwSetupGbl;

/**
 *  \brief Hardware setup data structure
 */
typedef struct Mcasp_HwSetupData_s {
    uint32_t mask;                     /**< To mask or not to mask - R/XMASK    */
    uint32_t fmt;                      /**< Format details as per  - R/XFMT     */
    uint32_t frSyncCtl;                /**< Configure the rcv/xmt frame sync    */
    uint32_t tdm;                      /**< Specifies which TDM slots are active*/
    uint32_t intCtl;                   /**< Controls generation of interrupts   */
    uint32_t stat;                     /**< Status register (controls writable  *
                                       * fields of STAT register)-R/XSTAT     */
    uint32_t evtCtl;                   /**< Event control register - R/XEVTCTL  */
    Mcasp_HwSetupDataClk clk;        /**< Clock settings for rcv/xmt          */
}Mcasp_HwSetupData;

/**
 *  \brief Hardware setup structure
 */
typedef struct Mcasp_HwSetup_s {
    Mcasp_HwSetupGbl glb;            /**< Value to be loaded in  (GLBCTL)     */
    Mcasp_HwSetupData rx;            /**< Receiver settings                   */
    Mcasp_HwSetupData tx;            /**< Transmitter settings                */
    uint32_t emu;                      /**< Power down emulation mode params    */
}Mcasp_HwSetup;


/*!
 *  \brief structure to store the audio device related information            */
typedef struct Mcasp_AudioDevData_s
{
    uint16_t            isMaster;
    /**< variable to store the current operation mode (Master/Slave).         */

}Mcasp_AudioDevData;

/*!
 *  \brief channel Parameters to initialize channel Object
 *
 *  This structure stores user supplied parameters
 */
typedef struct Mcasp_ChanParams_s {
    uint16_t noOfSerRequested;
    /**< Serializer requested by channel. Channel can ask for both.           */

    uint32_t indexOfSersRequested[16u];
    /**< Multi Serializer numbers requested by channel                        */

    Mcasp_HwSetupData* mcaspSetup;
    /**< Setup information for xmt/rcv sections of the McASP                  */

    uint16_t isDmaDriven;
    /**< This parameters determines whether channel operates in DMA mode      *
      * All DMA parameters would be read only if this is TRUE                 */

    Mcasp_OpMode channelMode;
    /**< channel operation mode TDM or DIT mode                               */

    uint16_t wordWidth;
    /**< The parameter informs the driver what is the width word              *
     * (not slot) and this help driver indirectly to decided no. of           *
     * bytes to be transfered into each serialer for each slot- This is       *
     * very important parameter - in case of invalid value default            *
     * value of 32 will be assumed by the driver                              */

    void * userLoopJobBuffer;
    /**< Buffer to be transferred when the loop job is running.it should      *
     * be noted that this buffer size should be n*userLoopjobLength           *
     * where n is the no of serialisers configured in the direction of        *
     * the channel we are creating                                            */

    uint16_t userLoopJobLength;
    /**< Number of bytes of the userloopjob buffer for each serialiser        *
     * Please note that this is no. of bytes and this should be               *
     * pre-calcuated properly for word width of slot - Please refer the       *
     *  wordWidth of this structure                                           */

    void *                  edmaHandle;
    /**< Handle to the EDMA Driver                                            */

    Mcasp_GblCallback    gblCbk;
    /**< callback required when global error occurs -                         *
     * must be callable  directly from the ISR context                        */

    uint32_t               noOfChannels;
    /**< No of channels of data to be transmitted after the frame sync        *
     * This input is valid only for TDM in DSP mode mode of                   *
     * communication E.g.--For Stereo data the value is 2 and for 6           *
     * channel dac taking all channel data through one serialiser the         *
     * value of this member will be 6 Note: But for same 6ch dac taking       *
     * stereo data though 3 seperate serialiser value should be 2             */

    Mcasp_BufferFormat   dataFormat;
    /**< Format of the application supplied buffer                            */

    uint16_t                 enableHwFifo;
    /**< Option to enable the Hardware FIFO                                   */

    uint16_t                 hwFifoEventDMARatio;
	/**<  This represents the ratio WNUMEVT/WNUMDMA	of the MCAPS FIFOCTL register *
	 *  In other words, this represents the DMA event(to/from Host) throttle factor
	 *  i.e a DMA event will be sent to Host (EDMA controller) only if 'hwFifoEventDMARatio'
	 *  events reach the McASP FIFO by the peripheral. This way the number of the DMA
	 *  events to/from the Host (EDMA controller) is reduced leading to reduced host overheads
	 *  due to a DMA transfer. For example, if hwFifoEventDMARatio=4, a DMA read/write event is
	 *  sent to the Host only when 4 such events reach the FIFO from the peripheral.    */
    uint16_t                 isDataPacked;
    /**< flag to indicate if the buffer data needs to be packed,i.e
     * the EDMA needs to be programmed for the exact slotwidth or a
     * rounded width of 32,16, or 8 Bit                                       */
    Mcasp_WordBitsSelect       wordBitsSelect;
    /**< Option to indicate the word alignment (MSB/LSB) if word size < slot size.
     * Mcasp_WordBitsSelect_LSB  = Select the Least significant 'word' sized bits in the slot bits
     * Mcasp_WordBitsSelect_MSB  = Select the Most  significant 'word' sized  bits in the slot  */
}Mcasp_ChanParams;

/**
 *  \brief DIT channel status register structure
 */
typedef struct Mcasp_ChStatusRam_s {
    uint32_t chStatusLeft[6];
    /**< Left channel status registers (DITCSRA0-5)                           */

    uint32_t chStatusRight[6];
    /**< Right channel status register (DITCSRB0-5)                           */
}Mcasp_ChStatusRam;

/**
 *  \brief DIT channel user data register structure
 */
typedef struct Mcasp_UserDataRam_s {
    uint32_t userDataLeft[6];
    /**< Left channel user data registers (DITUDRA0-5)                        */

    uint32_t userDataRight[6];
    /**< Right channel user data registers (DITUDRB0-5)                       */
}Mcasp_UserDataRam;

/**
 *  \brief Structure passed through DriverTypes_Packet addr field
 *
 *  In order to pass data for the DIT Channel Status and
 *  User Data RAM registers, the addr field of the
 *  IOM_Packet is cast to Mcasp_PktAddrPayload. The
 *  addr field holds pointers to Mcasp_ChStatusRam and
 *  Mcasp_UserDataRam in addition to the DMA address to
 *  be programmed.
 *
 *  NOTE: The Mcasp_ChStatusRam and Mcasp_UserDataRam
 *  fields will be read only for a transmit channel
 *  operating in DIT mode.
 */
typedef struct Mcasp_PktAddrPayload_s {
    Mcasp_ChStatusRam* chStat;
    /**< Channel Status RAM innfo                                             */

    Mcasp_UserDataRam* userData;
    /**< User Data RAM info                                                   */

    uint16_t writeDitParams;
    /**< Determines whether Channel Status and User Data get                  *
     * written in case of interrupt mode                                      */

    uint32_t* addr;
    /**< Actual address to program DMA with                                   *
     * Address of data word if transactions are interrupt driven              */

}Mcasp_PktAddrPayload;

/**
 *  \brief  McASP queue element
 *
 *          Doubly linked list for queue elements.
 *          Required for Mcasp_IOBuf structure.
 */
typedef Osal_Queue_Elem Mcasp_QueueElem;
    
/**
 *  \brief  McASP frame object params
 *
 *          Mcasp_IOBuf structures are managed by the driver. MCASP
 *          buffers are the basis for all I/O operations. 'cmd' field
 *          contains the command id for the driver. 'status' is filled
 *          in by the driver and contains the status of the commmand.
 */
typedef struct Mcasp_IOBuf_t
{
    Mcasp_QueueElem     link;
    /**< queue link                */

    void*               addr;
    /**< buffer address            */

    uint32_t            size;
    /**< buffer size               */

    uintptr_t            arg;
    /**< arg to be used by end app */

    Mcasp_IOcmd_e       cmd;
    /**< command for driver - READ, WRITE, ABORT or FLUSH  */

    int32_t             status;
    /**< status of command         */

    uint32_t            misc;
    /**< reserved for driver       */
} MCASP_Packet;

/*============================================================================*/
/*                           TYPEDEFS                                   */
/*============================================================================*/



/**
 *  \brief EDMA TC callback function prototype
 *   This function is the call back function provided by the application during 
 *   the mcaspCreateChannel(). This call back function is called every time a 
 *   TX or RX transaction is completed. The arguments to this function are defined
 *   as below.
 *
 *   arg - This callback argument is passed to the driver by the application during
 *         mcaspCreateChan(). The driver would pass this argument as is to the  
 *         call back function when the TX or RX transaction is completed.
 *         The application can then use this argument as they chose in their
 *         implementation of the call back function. If the application does not 
 *         want to use this call back argument, it can be set to NULL 
 *         during mcaspCreateChan().
 *
 *   packet -  This argument returns the MCASP_Packet * which was submitted as a 
 *         part of mcaspSubmitChan(). Once the transaction is completed, the application
 *         can use this to find the details of the transaction which just completed such as 
 *         the buffer address, size, cmd and other fields of MCASP_Packet.
 */
typedef void    (*MCASP_TiomCallback)(void * arg, MCASP_Packet *packet);

/*============================================================================*/
/*                           IOCTL COMMANDS                                   */
/*============================================================================*/

/**
 *  \brief  Mcasp Ioctl commands
 *
 *  Mcaspp Ioctl commands
 */
typedef enum Mcasp_ioctlCmd_e {
    /**< Reset Device, cmdArg = NONE                                          */
    MCASP_CHAN_RESET          = 0, 

    /**< Channel timeout, cmdArg = NONE                                      */
    MCASP_CHAN_TIMEDOUT       = 1,

    /**< Channel reset, cmdArg = NONE                                         */
    MCASP_DEVICE_RESET        = 2, 
    /**< Reset Device, cmdArg = NONE                                          */
    Mcasp_IOCTL_DEVICE_RESET = 128,

    /**< Enable/Disable mute, cmdArg = (uint32_t *) value for AMUTE register    */
    Mcasp_IOCTL_CNTRL_AMUTE,

    /**< Start Mcasp port, cmdArg = NONE                                      */
    Mcasp_IOCTL_START_PORT,

    /**< Stop Mcasp port, cmdArg = NONE                                       */
    Mcasp_IOCTL_STOP_PORT,

    /**< Query AMUTE register, cmdArg = (uint32_t *) variable to store value    */
    Mcasp_IOCTL_QUERY_MUTE,

    /**< Loop job modification, cmdArg = (Mcasp_ChanParams *)                 */
    Mcasp_IOCTL_CTRL_MODIFY_LOOPJOB,

    /**< Mute on, cmdArg = NONE                                               */
    Mcasp_IOCTL_CTRL_MUTE_ON,

    /**< Mute off, cmdArg = NONE                                              */
    Mcasp_IOCTL_CTRL_MUTE_OFF,

    /**< Pause data transfer, cmdArg = NONE                                   */
    Mcasp_IOCTL_PAUSE,

    /**< Resume data transfer, cmdArg = NONE                                  */
    Mcasp_IOCTL_RESUME,

    /**< Set DIT mode, cmdArg = (uint32_t *) value for DITCTL register          */
    Mcasp_IOCTL_SET_DIT_MODE,

    /**< Channel timeout, cmdArg = NONE                                       */
    Mcasp_IOCTL_CHAN_TIMEDOUT,

    /**< Channel reset, cmdArg = NONE                                         */
    Mcasp_IOCTL_CHAN_RESET,

    /**< Set channel format, cmdArg = (Mcasp_HwSetupData *)                   */
    Mcasp_IOCTL_CNTRL_SET_FORMAT_CHAN,

    /**< Get format channel info, cmdArg = (Mcasp_HwSetupdata *)              */
    Mcasp_IOCTL_CNTRL_GET_FORMAT_CHAN,

    /**< Set GBL register values, cmdArg = (Mcasp_HwSetup *)                  */
    Mcasp_IOCTL_CNTRL_SET_GBL_REGS,

    /**< Set digital loop back mode, cmdArg = (bool *)                          */
    Mcasp_IOCTL_SET_DLB_MODE,

    /**< Abort all queued requests, cmdArg = NONE                             */
    Mcasp_IOCTL_ABORT,

    /**< IOCTL to Set the sample rate cmdArg = (uint32_t *)                     */
    Mcasp_IOCTL_SET_SAMPLE_RATE,

    /**< Ioctl to query the Mcasp specific information.
         cmdArg = (Mcasp_AudioDevData *)                                      */
    Mcasp_IOCTL_GET_DEVINFO,

    /**< Ioctl to flush the receive FIFO                                      */
    Mcasp_IOCTL_FLUSH_RCV_FIFO,

    /**< Ioctl command to modify the timeout used by the driver for certain
     * wait operations. cmdArg = (uint32_t *)                                   */
    Mcasp_IOCTL_SET_TIMEOUT,

    /**< Ioctl command to check if the driver is compiled in loop job mode or
     * Not. cmdArg = (uint16_t *) TRUE = loop job mode,FALSE = loop job disabled  */
    Mcasp_IOCTL_QUERY_LOOPJOB_MODE,

    /**< Ioctl command to collect error stats 
     *           cmdArg = (Mcasp_errCbStatus *)                               */
    Mcasp_IOCTL_CHAN_QUERY_ERROR_STATS,
    
    /**< Ioctl command to reconfigure word width of the channel parameters:
     *   Mcasp_ChanParams.wordWidth.
     *           cmdArg = (Mcasp_ChanParams *).                                
     *   @remark Only wordWidth of the channel parameters in Mcasp_ChanParams 
     *           provided via cmdArg is used and all other parameters are ignored. */
    Mcasp_IOCTL_CHAN_PARAMS_WORD_WIDTH,
    
    /**< Ioctl command to read Tx channel bit clock divide ratio.
     * cmdArg = (uint32_t *) value read from ACLKXCTL:CLKXDIV register. */
    Mcasp_IOCTL_CNTRL_GET_FORMAT_CHAN_CLKXDIV,
    
    /**< Ioctl command to write Tx channel bit clock divide ratio.
     * cmdArg = (uint32_t *) value to write to ACLKXCTL:CLKXDIV register. 
     *   @remark This command should only be used on a Tx channel with no pending 
     *           or active transfers. Using the command on a Tx channel with 
     *           pending or active will produce unexpected results. */
    Mcasp_IOCTL_CNTRL_SET_FORMAT_CHAN_CLKXDIV
}Mcasp_ioctlCmd;

/* -------- per-instance configs -------- */

typedef struct Mcasp_Params_s
{

    uint16_t          enablecache;
    /**< Option to select whether to enable cache or not(default is TRUE)     */

    uint16_t          isDataBufferPayloadStructure;
    /**< This is useful during the operation of the Mcasp in DIT mode.This
     * parameter indicates if the data buffer has to be interpreted as a
     * payload structure,i.e whether the channel status and user data is also
     * included in the application buffer and hence has to be appropriately
     * interpreted.(Default is FALSE).                                        */

    Mcasp_HwSetup mcaspHwSetup;
    /**< Register information for initialising the Mcasp hardware.            */

    uint16_t          pscPwrmEnable;
    /**< Option to enable or disable the PSC control in the driver            */
}Mcasp_Params;


extern const Mcasp_Params Mcasp_PARAMS;

/**********************************************************************
 **************************** EXPORTED API ****************************
 **********************************************************************/

int32_t mcaspBindDev(void* *devp, int32_t devId, void* devParams);
int32_t mcaspUnBindDev(void* devp);
int32_t mcaspCreateChan(void* *chanp, void* devp, 
					Mcasp_chanMode_e mode, void* chanParams, MCASP_TiomCallback cbFxn, 
					void* cbArg);
int32_t mcaspSubmitChan(void* chanp, MCASP_Packet *ioPacket);
int32_t mcaspDeleteChan(void* chanp);
int32_t mcaspControlChan(void* chanp, Mcasp_ioctlCmd cmd, void* cmdArgs);

#ifdef __cplusplus
}
#endif

#endif /*MCASP_H */
/* @} */

