/**
 *  \file  usb_hcd_xhci.h
 *
 *  \brief Generic eXtensible Host Controller Interface driver -
 *         This file implements a generic XHCI driver and is not tied to 
 *         any System-O-Chip. Please not that this is not a DAL file and is
 *         implemented more on the lines of a driver. 
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
 *             http://www.ti.com/ 
 */

/*
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

#ifndef USB_HCD_XHCI_H_
#define USB_HCD_XHCI_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "usb_spec_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */


#define INTERUPTER1             1
#define INTERUPTER2             2
#define INTERUPTER3             3
#define INTERUPTER4             4


#define NO_OF_SLOTS  0x2

#define EVENT_RING_SEGMENTS_SIZE    0x1

#define USBCMD_INTERRUPT_ENABLED    0x4
#define USBCMD_RUN                  0x1
#define IMAN_INTERRUPT_ENABLED      0x2

#define TRB_TYPE_BITMASK            (0xfc00)
#define TRB_FIELD_TO_TYPE(p)        (((p) & TRB_TYPE_BITMASK) >> 10)
#define TRB_TYPE(p)                 ((p) << 10)

#define TRB_PSC                     34
#define TRB_ENABLE_SLOT             0x9
#define TRB_DISABLE_SLOT            0xA
#define TRB_RESET_DEVICE            0x11

#define TRB_ADDRESS_DEVICE          0xB
#define TRB_COMMAND_COMPLETION      0x21
#define TRB_TRANSFER                32
#define TRB_EVAL_CONTEXT            13
#define TRB_CONFIG_EP               12

#define SET_A0                      1
 
#define IMOD_INTERVAL_MASK          (0xffff)
#define IMOD_COUNTER_MASK           (0xffff << 16)
#define IMODC(p)                    (((p) & 0xffff) << 16)

#define TRB_TO_SLOT_ID(p)           (((p) & (0xffU << 24)) >> 24)
#define SLOT_ID_FOR_TRB(p)          (((p) & 0xffU) << 24)

#define CSZ_1                       1 /*In Aegis HCCPARAMS CSZ is 1 */

/* Slot Context Data Structure - 6.2.2 - Figure 74 */
struct xhci_slot_context {
    uint32_t    device_info0;
    uint32_t    device_info1;
    uint32_t    ttinfo;
    uint32_t    SlotState_Devadd;
    uint32_t    reserved[4];
#ifdef CSZ_1
    uint32_t    ExtraReserved[8];
#endif
};

#define LAST_CTX(p)         ((p) << 27)
#define ROOT_HUB_PORT(p)    (((p) & 0xff) << 16)
#define NUM_HUB_PORTS(n)    (((n) & 0xff) << 24)

#define XHCI_PORT_SPEED_LS  (2)
#define XHCI_PORT_SPEED_FS  (1)
#define XHCI_PORT_SPEED_HS  (3)
#define XHCI_PORT_SPEED_SS  (4)

#define XDEV_FS             (XHCI_PORT_SPEED_FS << 10)
#define XDEV_LS             (XHCI_PORT_SPEED_LS << 10)
#define XDEV_HS             (XHCI_PORT_SPEED_HS << 10)
#define XDEV_SS             (XHCI_PORT_SPEED_SS << 10)
#define SLOT_SPEED_FS       (XDEV_FS << 10)
#define SLOT_SPEED_LS       (XDEV_LS << 10)
#define SLOT_SPEED_HS       (XDEV_HS << 10)
#define SLOT_SPEED_SS       (XDEV_SS << 10)

/* XHCI register Set */

typedef struct xhciCapRegs
{
    volatile uint32_t hcCapLength    :8;    /* Offset: 0x0 */
    volatile uint32_t hcCapRsvd      :8;    /* Offset: 0x0 */
    volatile uint32_t hcCapHciVersion:16;   /* Offset: 0x0 */
    volatile uint32_t hcsParams1;           /* Offset: 0x4 */
    volatile uint32_t hcsParams2;           /* Offset: 0x8 */
    volatile uint32_t hcsParams3;           /* Offset: 0xc */
    volatile uint32_t hccParams;            /* Offset: 0x10 */
    volatile uint32_t dbOff;                /* Offset: 0x14 */
    volatile uint32_t rtsOff;               /* Offset: 0x18 */
    volatile uint8_t  rsvd[4];  
}xhciCapRegs_t;



typedef struct xhciOpRegs
{
    volatile uint32_t usbCmd;           /* Offset: 0x20 */
    volatile uint32_t usbSts;           /* Offset: 0x24 */
    volatile uint32_t pageSize;         /* Offset: 0x28 */
    volatile uint8_t  rsvd0[8];
    volatile uint32_t dnCtrl;           /* Offset: 0x34 */
    volatile uint64_t crcr;             /* Offset: 0x38 */
    volatile uint8_t  rsvd1[16];
    volatile uint64_t dcbaaPtr;         /* Offset: 0x50 */
    volatile uint32_t config;       /* Offset: 0x58 */
    volatile uint8_t  rsvd2[964];
    volatile uint32_t DWC_PORTSC1;      /* Offset: 0x420 */
    volatile uint32_t DWC_PORTPMSC1;    /* Offset: 0x424 */
    volatile uint32_t DWC_PORTLI1;      /* Offset: 0x428 */
    volatile uint32_t DWC_PORTHLPMC1;   /* Offset: 0x42c */
    volatile uint32_t DWC_PORTSC2;      /* Offset: 0x430 */
    volatile uint32_t DWC_PORTPMSC2;    /* Offset: 0x434 */
    volatile uint32_t DWC_PORTLI2;      /* Offset: 0x438 */
    volatile uint32_t DWC_PORTHLPMC2;   /* Offset: 0 */
}xhciOpRegs_t;


/*Endpoint Context Data Structure */
struct xhci_ep_context {
    unsigned int epinfo0;
    unsigned int epinfo1;
    unsigned int TRDeqPtrLo;
    unsigned int TRDeqPtrHi;
    unsigned int TxInfo;
    /* offset 0x14 - 0x1f reserved for HC internal use */
    uint32_t    reserved[3];
#ifdef CSZ_1
    uint32_t ExtraReserved[8];
#endif
};

#define EP_INTERVAL(p)          (((p) & 0xff) << 16)
#define EP_TYPE(p)              ((p) << 3)
#define ISOC_OUT_EP             1
#define BULK_OUT_EP             2
#define INT_OUT_EP              3
#define CTRL_EP                 4
#define ISOC_IN_EP              5
#define BULK_IN_EP              6
#define INT_IN_EP               7
#define MAX_BURST(p)            (((p)&0xff) << 8)
#define MAX_PACKET(p)           (((p)&0xffff) << 16)
#define EP_CTX_CYCLE_MASK       (1 << 0)
#define ERROR_COUNT(p)          (((p) & 0x3) << 1)
#define MAX_PACKET_DECODED(p)   (((p) >> 16) & 0xffff)
#define MAX_PACKET_MASK         (0xffff << 16)

struct xhci_input_control_ctx {
    uint32_t    drop_flags;
    uint32_t    add_flags;
    uint32_t    rsvd2[6];
#ifdef CSZ_1
    uint32_t ExtraReserved[8];
#endif
};
#define EP_IS_ADDED(i)  (1 << (i + 1))
 
/*Event Ring Segment Table based on xHCI Spec Sec 6.5 */
struct xhci_erst_entry {
    /* 64-bit event ring segment address //64 byte address boundary */
    unsigned int    seg_addr_lo;
    unsigned int    seg_addr_hi; /* Second word */
    unsigned int    seg_size:16; /*Third word */
    unsigned int    RsvdZ1:16;
    unsigned int    RsvdZ2; /*Fourth word is reserved */
};
#define ERST_EHB        (1 << 3)
#define ERST_DEQP_MASK  0xf

/*Command Ring and Command Completion Event data types */
/*xHCI Spec sec 6.4.2.2 */
/*typedef struct xhci_event_cmd XHCI_EVENT_CMD_T */
struct xhci_event_cmd {
    unsigned int command_trb_ptr_lo; /*16byte aligned LSB 4 bits reserved */
    unsigned int command_trb_ptr_hi;
    unsigned int completioncode;
    unsigned int trb_slotid;/*Final word */
};

#define SLOT_ID_FOR_TRB(p)  (((p) & 0xffU) << 24)
#define LINK_TOGGLE (0x1<<1)
/* */
/*xHCI Spec Section : 6.4.1.2 defines this structure */
struct xhci_control_trb
{
    uint8_t  bmRequestType;
    uint8_t  bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
    unsigned int transfer_len;
    unsigned int flags;
};

/*Transfer Ring entry based on Normal TRB definition */
/*xHCI Spec sec 6.4.1.1 */
struct xhci_normal_trb {

    unsigned int bufferlo;
    unsigned int bufferhi;
    unsigned int transfer_len;
    unsigned int flags;
};

union xhci_transfer_event {
    struct xhci_control_trb control_trb;
    struct xhci_normal_trb normal_trb;
};

typedef enum
{
    USB_HOST_UNKNOWN = 0,
    USB_HOST_DEV_DETACHED,
    USB_HOST_DEV_CONNECTED,
    USB_HOST_PORT_RESET,
    USB_HOST_SLOT_ENABLED,
    USB_HOST_SLOT_ADDRESSED,
    USB_HOST_ENUMERATED,
    USB_HOST_CONFIGURED,
    USB_HOST_SLOT_DISABLED,
 } USB_HOST_CoreState_e;

 
#define TRB_TYPE(p)             ((p) << 10)
/* bulk, interrupt, isoc scatter/gather, and control data stage */
#define TRB_T_NORMAL            1
/* setup stage for control transfers */
#define TRB_SETUP               2
/* data stage for control transfers */
#define TRB_DATA                3
/* status stage for control transfers */
#define TRB_T_STATUS            4
#define TRB_LINK                6
#define TRB_ISP                 (1<<2)
#define TRB_IDT                 (1<<6)
#define TRB_IOC                 (1<<5)
#define TRB_CHAIN               (1<<4)

#define TRB_CYCLE               (1<<0)
#define TRB_DIR_IN              (1<<16)
#define TRB_TX_TYPE(p)          ((p) << 16)
#define TRB_DATA_OUT            2
#define TRB_DATA_IN             3
#define TRB_TO_EP_INDEX(p)      ((((p) & (0x1f << 16)) >> 16) - 1)
#define COMP_CODE_MASK          (0xffU << 24)
#define GET_COMP_CODE(p)        (((p) & COMP_CODE_MASK) >> 24)


/* Completion codes from XHI */
#define COMP_INVALID                0
#define COMP_SUCCESS                1
#define COMP_DATA_BUFF_ERR          2
#define COMP_BABBLE_DET_ERR         3
#define COMP_USB_TRANS_ERR          4
#define COMP_TRB_ERR                5
#define COMP_STALL_ERR              6
#define COMP_RESOURCE_ERR           7
#define COMP_BANDWIDTH_ERR          8
#define COMP_NO_SLOT_AVAIL_ERR      9
#define COMP_INV_STREAM_TYPE_ERR    10
#define COMP_SLOT_NOT_ENABLED_ERR   11  /* slot not enabled */
#define COMP_EP_NOT_ENABLED_ERR     12  /* end point not enabled */
#define COMP_SHORT_PACKET           13 
#define COMP_RING_UNDER_RUN         14
#define COMP_RING_OVER_RUN          15
#define COMP_VF_EVENT_RING_FULL_ERR 16
#define COMP_PARAM_ERR              17
#define COMP_BANDWIDTH_OVERRUN_ERR  18
#define COMP_CONTEXT_STATE_ERR      19
#define COMP_NO_PING_RESPONSE_ERR   20
#define COMP_EVENT_RING_FULL_ERR    21
#define COMP_INCOMPATIBLE_DEV_ERR   22
#define COMP_MISSED_SERVICE_ERR     23
#define COMP_CMD_RING_STOPPED       24
#define COMP_CMD_ABORTED            25
#define COMP_STOPPED                26
#define COMP_STOPPED_LEN_INVALID    27
#define COMP_STOPPED_SHORT_PACKET   28
#define COMP_MAX_EXIT_LATENCY_ERR   29
#define COMP_ISOC_BUFF_OVERRUN      31
#define COMP_EVENT_LOST_ERR         32
#define COMP_UNDEFINED_ERR          33
#define COMP_INV_STREAM_ID_ERR      34
#define COMP_SECONDARY_BW_ERR       35
#define COMP_SPLIT_TRANS_ERR        36


/* host driver error codes */
/* lower word of the error code is the xhci completion code */
#define NO_ERROR                            (0x00000000U)
#define ERR_USB_HOST_UNEXPECTED_TRB_TYPE    (0x00ff0000U)
#define ERR_USB_HOST_CONFIG_EP_FAILED       (0x00010000U)
#define ERR_USB_HOST_GET_DEV_DESC           (0x00020000U)
#define ERR_USB_HOST_GET_CONF_DESC          (0x00030000U) 
#define ERR_USB_HOST_WRITE                  (0x00040000U)
#define ERR_USB_HOST_READ                   (0x00050000U)
#define ERR_USB_HOST_SET_ADDRESS_FAILED     (0x00060000U)
#define ERR_USB_HOST_DISABLE_SLOT_FAILED    (0x00070000U)
#define ERR_USB_HOST_DEVICE_RESET_FAILED    (0x00080000U)
#define ERR_USB_HOST_DEVICE_CONNECT_FAILED  (0x00090000U)
#define ERR_USB_HOST_DEVICE_GET_SLOT_FAILED (0x000A0000U)
#define ERR_USB_HOST_SET_CONF_DESC          (0x000B0000U)
#define ERR_USB_HOST_CTRL_TRANSFER_FAILED   (0x000C0000U)
#define ERR_USB_HOST_BAD_DATA               (0x000D0000U)
#define ERR_USB_HOST_PSC_HANDLING_FAILED    (0x000E0000U)
#define ERROR_USB_HOST_DEVICE_NOTSUPPORTED  (0x000F0000U)
#define ERROR_USB_HOST_GET_INTERFACE_FAILED (0x00100000U)

struct xhci_dcbaa
{
        unsigned int slot0_addresslo;
        unsigned int slot0_addresshi;
        unsigned int slot1_addresslo;
        unsigned int slot1_addresshi;
        unsigned int slot2_addresslo;
        unsigned int slot2_addresshi;        
};

/*DoorBell defines used for Slot 1 Doorbell */
#define DB_VALUE(ep, stream)    ((((ep) + 1) & 0xff) | ((stream) << 16))
#define DB_VALUE_HOST           (0x00000000U)


#define USB_DWC_INT_CONNECT     (0x00000002U)
#define USB_DWC_INT_RESET       (0x00000004U)
#define USB_DWC_INT_DISCONNECT  ((uint32_t)0x00000008U)


#define MAX_XHCI_PORT           (0x2U)

/*
 * These defines define the no of entries for each ring
 */
#define EP0_TRANSFER_RING_SIZE      (16U)
#define BULKIN_TRANSFER_RING_SIZE   (16U)

#define BULKOUT_TRANSFER_RING_SIZE  (16U)
#define COMMAND_RING_SIZE           (16U)
#define EVENT_RING_SIZE             (16U)


/* dcbaa_context 
 * is called as Input Context - 3.2.5 or 6.2.5 
*/
typedef struct xhci_context_wrapper     
{
    struct xhci_input_control_ctx   Input_Control_Context;
    struct xhci_slot_context        Slot_Context;

    /* idx 0 is for EP0 */
    struct xhci_ep_context          EndPoint_Context[31];
} xhci_context_wrapper_t ;





typedef struct xhci_gdata 
{
    uint32_t    usbInstance;
    
    uint8_t     uDataReceived[0x200]; /* accomodating USB3.0 */
    uint8_t     uBulkINEPNum;
    uint8_t     uBulkOUTEPNum;
    uint8_t     uBulkINDB;
    uint8_t     uBulkOUTDB;

    uint8_t     bulkINRingCycleState;
    uint8_t     bulkOUTRingCycleState;

    uint8_t     Slot_ID;
    uint8_t     byCommandRingIndex;
    uint8_t     byCtrlTransferRingIndex;
    uint8_t     byEventRingIndex;
    uint8_t     byEpOUTRingIndex;
    uint8_t     byEpINRingIndex;
    uint32_t    countofINs;
    uint32_t    countofOUTs;
    uint32_t    countofCompletion;
    uint32_t    uBulkINCompletion;
    uint32_t    uBulkOUTCompletion;
    uint32_t    uBulkINSuccesfulCompletion;

    struct xhci_event_cmd*  PtrEvent;
    uint32_t                xhciPortNum;    /* root hub port number */
    uint32_t                xhciPortSpeed;
    uint16_t                ep0MaxPs;       /* ep0 max packet size */

    /* the state of each of the xhci ports */
    USB_HOST_CoreState_e    xhciPortState[MAX_XHCI_PORT];  

    /* the type of TRB response driver is expecting from XHCI */
    uint32_t                expectingTrbType;

    /* xhci rings and xhci own data strutures */
    xhci_context_wrapper_t      xhci_context    __attribute__((aligned(64)));

    union xhci_transfer_event   EP0_Transfer_Ring[EP0_TRANSFER_RING_SIZE] __attribute__ ((aligned (64))); /* EP0 */
    union xhci_transfer_event   BulkIN_Transfer_Ring[BULKIN_TRANSFER_RING_SIZE] __attribute__ ((aligned (64)));
    union xhci_transfer_event   BulkOUT_Transfer_Ring[BULKOUT_TRANSFER_RING_SIZE] __attribute__ ((aligned (64)));

    struct xhci_event_cmd       Command_Ring[COMMAND_RING_SIZE] __attribute__ ((aligned (64)));

    /* event ring for command completion or for events. */
    struct xhci_event_cmd       Command_Completion_Event[EVENT_RING_SIZE] __attribute__ ((aligned (64))); 

    struct xhci_dcbaa           dcbaa                       __attribute__ ((aligned (64)));
    struct xhci_erst_entry      Event_Ring_Segment_Entry    __attribute__ ((aligned (64)));

    uint32_t                    scratchPadPointer           __attribute__ ((aligned (64)));

    /* 8KB scratch pad buffer for an xHC implementation */
    uint8_t                     scratchpadBuffer [8*1024]  __attribute__ ((aligned (8*1024)));

} XHCI_DATA_S;




uint32_t xhci_main(uint32_t instanceNumber);

void XHCIIsrEntryActions (uint32_t instNum); 

void XHCIIsrExitActions (uint32_t instNum);


void XHCIIntrEnable (uint32_t instNum);

void XHCIIntrDisable (uint32_t instNum);

uint32_t USBSSGetGlobalHostIntrStatus(uint32_t instNum) ;
uint32_t USBSSGetGlobalDevIntrStatus(uint32_t instNum) ;
uint32_t USBSSGetGlobalOTGIntrStatus(uint32_t instNum) ;

/* TBD: Additional proototype dependency outside the source file */
void saveDeviceDescriptor(uint32_t ulIndex, uint8_t* buffer);
void saveConfigDescriptor(uint32_t ulIndex, uint8_t* buffer, uint32_t length);

void USB_Host_Init(uint32_t instanceNumber);
void usb_set_wrapper(uint32_t instanceNumber);
uint32_t xhci_enum(uint32_t instanceNumber);


uint32_t USBHostWrite(uint32_t instanceNumber, uint8_t uEndPoint, uint8_t *puData, uint32_t uSize);
uint32_t USBHostRead(uint32_t instanceNumber, uint8_t uEndPoint, uint8_t *puData, uint32_t uSize);
uint32_t  xhci_reset_device(uint32_t instanceNumber);
uint32_t USBHostControlTransfer(uint32_t instanceNumber, usbSetupPkt_t *pSetupPkt, uint8_t* pData, uint32_t uSize);

extern uint32_t USBIntStatusControl(uint32_t ulBase);
extern uint32_t XhciRegBaseAddr(uint32_t instNum);
extern uint32_t UsbWrapRegBaseAddr(uint32_t instNum);
uint32_t xhci_disable_slot(uint32_t instanceNumber);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_HCD_XHCI_H_ */
