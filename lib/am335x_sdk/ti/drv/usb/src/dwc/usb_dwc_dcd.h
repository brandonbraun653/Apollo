/**
 *  \file  usb_dwc_dcd.h
 *
 *  \brief Device Abstraction layer header for USB DWC3 device
 *         contoller driver.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef USB_DCD_DWC_H_
#define USB_DCD_DWC_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_dwc_usb.h"

/* Hardware header files */
#include "hw_trb_device.h"
#include "hw_depcmdpar.h"

/* USB core and protocol specific files */
#include "usb_dcd_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 * \brief Macro to contain the maximum number of elements in  a buffer
 */
#define USB_DCD_DWC_EVNT_BUF_MAX    (32U)
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief This structure contains the device endpoint specific
 *        event details.
 */
typedef struct usbDwcDcdDEpEvnt
{
    uint32_t epSpecEvnt : 1U;
    /**< Specifies if it is an endpoint specific event */
    uint32_t phEpNum : 5U;
    /**< Physical endpoint number */
    uint32_t evntType : 4U;
    /**< Type of the event */
    uint32_t rsvd1 : 2U;
    /** reserved bit field */
    uint32_t evntSts : 4U;
    /**< Status of the event */
    uint32_t evntParams : 16;
    /**< Event parameters */
}usbDwcDcdDEpEvnt_t;

/**
 * \brief This structure contains the device specific event
 *        buffer details.
 */
typedef struct usbDwcDcdDEvnt
{
    uint32_t epSpecEvnt : 1U;
    /**< Specifies if it is an endpoint specific event
         or not */
    uint32_t devSpecEvnt : 7U;
    /**< Device specific event */
    uint32_t evntType : 4U;
    /**< Type of the event */
    uint32_t rsvd1 : 4U;
    /**< Reserved */
    uint32_t evntInfo : 8U;
    /**< Device specific event information */
    uint32_t rsvd2 : 8U;
    /**< Reserved */
} usbDwcDcdDEvnt_t;

/**
 * \brief This union contains the Event buffer description.
 *        The events can be of two types:
 *        - Device endpoint specific event.
 *        - Device specific event.
 */
typedef union usbDwcDcdEvnt
{
    usbDwcDcdDEpEvnt_t dEpEvnt;
    /**< Device endpoint specific event */
    usbDwcDcdDEvnt_t dEvnt;
    /**< Device specific event */
}usbDwcDcdEvnt_t;

/**
 * \brief Device physical endpoint Command parameters
 */
typedef struct usbDwcDcdDEpCmdParms
{
    volatile uint32_t parm0;
    /**< Parameter 0 of the endpoint command to be issued */
    volatile uint32_t parm1;
    /**< Parameter 1 of the endpoint command to be issues */
    volatile uint32_t parm2;
    /** < parameter 2 of the command to be issued */
}usbDwcDcdDEpCmdParms_t;

/**
 * \brief This enum contains the types of commands that can be
 *        issued by the DWC3 device controller
 */
typedef enum usbDEpCmdType
{
    USB_D_EP_CMD_SETEPCFG = DWC_USB_DEPCMD_0_CMDTYP_DEPCFG,
    /**< Set endpoint configuration */
    USB_D_EP_CMD_SETEPXFERRESCFG = DWC_USB_DEPCMD_0_CMDTYP_DEPXFERCFG,
    /**< Set endpoint transfer resource configuration */
    USB_D_EP_CMD_GETEPSTATE = DWC_USB_DEPCMD_0_CMDTYP_DEPGETDSEQ,
    /**< Get endpoint device state */
    USB_D_EP_CMD_SETSTALL = DWC_USB_DEPCMD_0_CMDTYP_DEPSETSTALL,
    /**< Set endpoint stall */
    USB_D_EP_CMD_CLRSTALL = DWC_USB_DEPCMD_0_CMDTYP_DEPCSTALL,
    /**< Clear Endpoint stall */
    USB_D_EP_CMD_STRTXFER = DWC_USB_DEPCMD_0_CMDTYP_DEPSTRTXFER,
    /**< Start transfer command */
    USB_D_EP_CMD_UPDXFER = DWC_USB_DEPCMD_0_CMDTYP_DEPUPDXFER,
    /**< Update transfer command */
    USB_D_EP_CMD_ENDXFER = DWC_USB_DEPCMD_0_CMDTYP_DEPENDXFER,
    /**< End transfer Command */
    USB_D_EP_CMD_STARTCFG = DWC_USB_DEPCMD_0_CMDTYP_DEPSTARTCFG
    /**< Start Endpoint configuration */
}usbDEpCmdType_t;

/**
 * \brief This structure defines the bit fields required for
 *        USB endpoint TRB
 */
typedef struct usbDEpTrb
{
    uint32_t bufPtrLow;
    /**< Buffer pointer low address */
    uint32_t bufPtrHigh;
    /**< Buffer pointer high address */
    uint32_t bufSize : 24U;
    /**< Buffer size to be used */
    uint32_t packetCntM1 : 2U;
    /**< Packet count M1 */
    uint32_t rsvd1 : 2U;
    /**< Reserved fields */
    uint32_t trbSts: 4U;
    /**< TRB status */
    uint32_t hwo: 1U;
    /**< Hardware owner of descriptor */
    uint32_t lst : 1U;
    /**< Last TRB */
    uint32_t chn : 1U;
    /*chain buffers */
    uint32_t csp : 1U;
    /* continue on short packet */
    uint32_t trbCtrl : 6U;
    /**< TRB control */
    uint32_t ispImi : 1U;
    /**< Interrupt on short packet/ Missed ISOC */
    uint32_t ioc : 1U;
    /**< Interrupt on complete */
    uint32_t rsvd2 : 2U;
    /**< Reserved fields */
    uint32_t streamId : 16U;
    /**< Stream ID */
    uint32_t rsvd3: 2U;
    /**< Reserved fields */
} __attribute__((packed)) usbDEpTrb_t;

/**
 * \brief This enum indicates the type of the TRB being used
 */
typedef enum usbDwcDcdTrbCtrl
{
    USB_DWC_DCD_TRB_CTRL_NORMAL = TRB_CONTROL_TRBCTL_NORMAL,
    /**< Normal TRB for Control data2+, bulk and interrupt */
    USB_DWC_DCD_TRB_CTRL_SETUP = TRB_CONTROL_TRBCTL_CSET,
    /**< Control setup TRB */
    USB_DWC_DCD_TRB_CTRL_STATUS2 = TRB_CONTROL_TRBCTL_CSTS2,
    /**< Control status 2 */
    USB_DWC_DCD_TRB_CTRL_STATUS3 =  TRB_CONTROL_TRBCTL_CSTS3,
    /**< Control status 3 */
    USB_DWC_DCD_TRB_CTRL_CTRL_DATA1 = TRB_CONTROL_TRBCTL_CDAT1,
    /**< control data 1 */
    USB_DWC_DCD_TRB_CTRL_ISO_FIRST = TRB_CONTROL_TRBCTL_ISO1,
    /**< Isochronous First */
    USB_DWC_DCD_TRB_CTRL_ISO = TRB_CONTROL_TRBCTL_ISON,
    /** Isochronous TRB */
    USB_DWC_DCD_TRB_CTRL_LINK = TRB_CONTROL_TRBCTL_LINK
    /** Link TRB */
}usbDwcDcdTrbCtrl_t;

/**
 * \brief This enum contains the possible endpoint
 *        event
 */
typedef enum usbDwcDcdEvntType
{
    USB_DWC_DCD_EVNT_TYPE_XFERCOMPLETE = 1U,
    /**< Transfer complete event on a endpoint */
    USB_DWD_DCD_EVNT_TYPE_XFERNRDY = 3U
    /**< Transfer not ready even ton a endpoint */
}usbDwcDcdEvntType_t;

/**
 * \brief This enum contains the possible values of
 *        state of endpoint 0
 */
typedef enum usbDwcDcdEp0State
{
    USB_DWC_DCD_EP0_STATE_SETUP = 0,
    /**< Setup state for endpoint 0 */
    USB_DWC_DCD_EP0_STATE_DATA_IN,
    /**< Data in state for endpoint 0 */
    USB_DWC_DCD_EP0_STATE_DATA_OUT,
    /**< Data out phase for endpoint 0 */
    USB_DWC_DCD_EP0_STATE_STATUS2,
    /**< Status 2 state for endpoint 0 */
    USB_DWC_DCD_EP0_STATE_STATUS3_IN,
    /**< Status 3 in state for endpoint 0 */
    USB_DWC_DCD_EP0_STATE_STATUS3_OUT,
    /**< Status 3 out state for endpoint 0*/
    USB_DWC_DCD_EP0_STATE_STALL
    /**< Endpoint 0 in stalled state */
}usbDwcDcdEp0State_t;

/**
 * \brief Dwc3 device object used by the DWC3 driver
 */
typedef struct usbDwcDcdDevice
{
    uint32_t baseAddr;
    /**< Base address of the USB device controller */

    uint32_t wrapperAddr;
    /**< Base address of the USB wrapper controller */

    char name[10];
    /**< name of the device controller */
    uint32_t controllerId;
    /**< ID of the controllerr */
    uint32_t deviceNewAddrValidFlag;
    /**< Check if New device address has been assigned */
    uint32_t devAddr;
    /**< Device address */
    usbDcd_t *pDcdCore;
    /**< Pointer to the DCD code, used for callbacks to the core */
    usbDwcDcdEp0State_t ep0State;
    /**< Current state of endpoint 0 */
    uint32_t isConnected;
    /* Flag to tell whether USB is connected or not */

    usbDwcDcdEvnt_t * pCurrEvntAddr;
    /**< Current USB event Address */

    /* mapping between logical ep number to physical ep number 
     * index 0 is logical EP0, index 1 is logical EP1, etc. */
    uint8_t ep_to_phyep[MAX_NUM_REQUESTS];

    /* mapping between physical to logical endpoint */
    uint8_t phyep_to_ep[MAX_NUM_REQUESTS];

    /* current EP configuration */
    uint8_t configNo;   /* configuration request num */

}usbDwcDcdDevice_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief USB DWC3 device controller driver core init API.
 *
 * \param pDcdObject pointer to the USB device control driver object
 */
uint32_t USBDwcDcdInit(usbDcd_t * pDcdObject);

/**
 * \brief USB DWC3 device interrupt handler.
 *        This will get all the device and endpoint events for all the
 *        endpoints.
 *
 * \param dwc3 pointer to the dwc3 object
 */
uint32_t USBDwcDcdIntrHandler(usbDwcDcdDevice_t *dwc3);

/**
 * \brief This API sets the device characteristics
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param pDevCharacteristic pointer to the device characteristics
 *        structure.
 */
uint32_t USBDwcDcdConfigDevChara( usbDcd_t * pDcdObject,
    usbDevChara_t *pDevCharacteristic);

/**
 * \brief Endpoint 0 request for control endpoint
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint 0
 */
uint32_t USBDwcDcdEp0Req(usbDcd_t *pDcdObject,
    usbEndpt0Request_t* req);

/**
 * \brief Endpoint request for control bulk and isoch transfers
 *        for all endpoints other than endpoint 0.
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint other than
 *        endpoint 0.
 */
uint32_t USBDwcDcdEpReq( usbDcd_t * pDcdObject,
    usbEndptRequest_t* req);

/** \brief Enable all the wrapper interrupts
 *  \param baseAddr Baseaddress of USB wrapper register
 */
void usbDwcDcdEnableWrapperIntr(uint32_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_DCD_DWC_H_ */
