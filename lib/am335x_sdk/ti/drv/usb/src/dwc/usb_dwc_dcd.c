/**
 *  \file  usb_dwc_dcd.c
 *
 *  \brief DWC3 device controller driver. This is the lowest layer driver
 *         which interacts directly with the hardware.
 *
 *  \copyright Copyright (C) 2013-2016 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the fosllowing disclaimer.
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "usb_dwc_dcd.h"
#include "usb_osal.h"
#include "usblib.h"


/* field for error handling */
#include "error.h"
#include "debug.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define DWC_BULK_OUT_PHY_EP      (2)
#define DWC_BULK_IN_PHY_EP       (3)
#define DWC_INTR_IN_PHY_EP       (4)
#define DWC_MAX_EP_NUMBER        (16)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the number of events
 *        for a selected buffer
 *
 * \param dwc3 pointer to the dwc3 device object.
 * \param evntId ID of the event buffer.
 */
uint32_t usbDwcDcdGetEvntCount(usbDwcDcdDevice_t *dwc3, uint32_t evntId);

/**
 * \brief Setup Event buffer required by the device control driver.
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param pUsbEvnt pointer to the USB event buffer
 * \param evntSize size of the USB event buffer
 * \param count count of the USB buffers
 * \param eventId ID of the event buffer
 */
void usbDwcDcdSetupEvntBuf(usbDwcDcdDevice_t *dwc3,
                           usbDwcDcdEvnt_t * pUsbEvnt,
                           uint32_t evntSize,
                           uint32_t count,
                           uint32_t eventId);

/**
 * \brief USB DWC3 device controller drive core reset API
 *
 * \param dwc3 pointer to the dwc3 device object.
 */

void usbDwcDcdCoreInit(usbDwcDcdDevice_t *dwc3);

/**
 * \brief This API is used to run Device endpoint command
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param phEpId Id of the physical endpoint
 * \param usbDEpCmd Endpoint command to be issued
 * \param pDEpCmdParm Endpoint command parameters
 * \param rscIdx Resource Idx value for Set New config command
 *        0 for RSCIDX = 0
 *        2 for RSCIDX = 2
 *        -1 Don't Care
 */
void usbDwcDcdRunDEpCmd(usbDwcDcdDevice_t *dwc3,
                        uint32_t phEpId,
                        usbDEpCmdType_t pDEpCmdType,
                        usbDwcDcdDEpCmdParms_t * pDEpCmdParm,
                        int32_t rscIdx,
                        uint8_t *pStatus);

/**
 * \brief This API prepare a buffer for setup packet,
 *        initialise a setup TRB and starts the transfer
 *
 * \param dwc3 pointer to the dwc3 device object.
 */
void usbDwcDcdRunSetupXfer(usbDwcDcdDevice_t *dwc3);

/**
 * \brief Run a start transfer command for single TRB
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param phEpId target physical endpoint ID
 * \param pTrb pointer to the TRB
 * \param pBuf pointer to the data buffer
 * \param bufSize Size of the data buffer
 * \param xferType Transfer type
 */
void usbDwcDcdRunXferSingle(usbDwcDcdDevice_t *dwc3,
                            uint32_t phEpId,
                            usbDEpTrb_t *pTrb,
                            void * pBuf,
                            uint32_t bufSize,
                            usbDwcDcdTrbCtrl_t xferType);

/**
 * \brief Runs a start transfer core command with the provided
 *        transfer descriptor.
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param phEpId Physical endpoint ID
 * \param pDEpTrb Pointer to the Endpoint TRB
 */
void usbDwcDcdStartXfer(usbDwcDcdDevice_t *dwc3,
                        uint32_t phEpId,
                        usbDEpTrb_t * pDEpTrb);

/**
 * \brief Perform the core operations required
 *        on receiving USB reset Event
 *
 * \param dwc3 pointer to the dwc3 device object
 */
void usbDwcDcdRstEvntHandler(usbDwcDcdDevice_t *dwc3);

/**
 * \brief Perform the core operations required
 *        on receiving USB Disconnect Event
 *
 * \param dwc3 pointer to the dwc3 device object
 */
void usbDwcDcdDiscEvntHandler(usbDwcDcdDevice_t *dwc3);

/**
 * \brief Perform the operations required on connect
 *        done event.
 *
 * \param dwc3 Pointer to the dwc3 device object
 */
void usbDwcDcdCnctDoneEvntHandler(usbDwcDcdDevice_t *dwc3);

/**
 * \brief EP0 interrupt handler(Default control endpoint)
 *        All other endpoint interrupts are handled separetely.
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param usbDwcDcdEvnt The event which is to be processed
 */
void usbDwcDcdEp0EvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt);

/**
 * \brief usb endpoint event handler which handles the various endpoint
 *        events of the DWC3 controler.
 *
 * \param dwc3 pointer to the dwc3 device object.
 * \param usbDwcDcdEvnt pointer to the DWC3 endpoint event which has occured.
 *
 */
void usbDwcDcdEpEvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt);

/**
 * \brief usb device event handler which handler the various events
 *        of the DWC3 controller.
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param usbDwcDcdEvnt pointer to the DWC3 device event which has occured.
 */
void usbDwcDcdDevEvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt);

/**
 * \brief This function sets or clear endpoint stall.
 *
 * \param dwc3 pointer to the dwc3 device object
 * \param phEpId Physical endpoint number for which the stall has to be
 *        set or cleared.
 * \param flag - TRUE - set stall
 *        flag - FLASE - clear stall
 */
void usbDwcDcdSetEpStall(usbDwcDcdDevice_t *dwc3, uint32_t phEpId, uint32_t flag);

/**
 * \brief This API is called when the set configuration request comes from the
 *        host driver.
 *
 * \param dwc3 pointer to the dwc3 device object
 */
void usbDwcDcdSetConfiguration(usbDwcDcdDevice_t *dwc3);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#define ALIGNED_SIZE    (32U)

/** \brief usb endpoint command parameters */
static usbDwcDcdDEpCmdParms_t dEpCmdParm __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief TRB for transfer of control data */
static usbDEpTrb_t ctrlDataTrb __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief TRB for control status commands */
static usbDEpTrb_t ctrlStatusTrb __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief TRB for bulk in transfers */
static usbDEpTrb_t bulkInTrb __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief TRB for bulk out transfers */
static usbDEpTrb_t bulkOutTrb __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief USB event buffer */
static usbDwcDcdEvnt_t usbEvnt[USB_DCD_DWC_EVNT_BUF_MAX] __attribute__ ((aligned (ALIGNED_SIZE)));

/** \brief Control data buffer */
static uint32_t usbCtrlDataBuf[32U] __attribute__ ((aligned (ALIGNED_SIZE)));
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t USBDwcDcdInit(struct usbDcd *pDcdObject)
{
    volatile uint32_t regVal;

    /* Retrieve private data from core object */
    usbDwcDcdDevice_t *dwc3 = (usbDwcDcdDevice_t *)(pDcdObject->privateData);

    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCTL, DWC_USB_DCTL_RUNSTOP, DWC_USB_DCTL_RUNSTOP_STOP);

    while(0U == HW_RD_FIELD32(dwc3->baseAddr + DWC_USB_DSTS, DWC_USB_DSTS_DEVCTRLHLT));

    /* Perform the core soft reset */
    usbDwcDcdCoreInit(dwc3);

    /* Read the value of DWC_USB_GUSB2PHYCFG) */
    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GUSB2PHYCFG);

    HW_SET_FIELD(regVal, DWC_USB_GUSB2PHYCFG_PHYSOFTRST, 
                 DWC_USB_GUSB2PHYCFG_PHYSOFTRST_INACTIVE);

    HW_SET_FIELD(regVal, DWC_USB_GUSB2PHYCFG_ENBLSLPM, 
                 DWC_USB_GUSB2PHYCFG_ENBLSLPM_NO);

    HW_SET_FIELD(regVal, DWC_USB_GUSB2PHYCFG_SUSPHY, 
                 DWC_USB_GUSB2PHYCFG_SUSPHY_0);

    /* Bring USB 2 phy out of reset */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GUSB2PHYCFG, regVal);

    /* Bring USB 3 phy out of reset */
    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GUSB3PIPECTL);

    HW_SET_FIELD(regVal, DWC_USB_GUSB3PIPECTL_SUSPENDEN, 
                 DWC_USB_GUSB3PIPECTL_SUSPENDEN_0);

    HW_SET_FIELD(regVal, DWC_USB_GUSB3PIPECTL_PHYSOFTRST, 
                 DWC_USB_GUSB3PIPECTL_PHYSOFTRST_INACTIVE);

    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GUSB3PIPECTL, regVal);

    /* Connect as high speed device */
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCFG, DWC_USB_DCFG_DEVSPD, 
                  DWC_USB_DCFG_DEVSPD_HS);

    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCFG, DWC_USB_DCFG_NUMP, 4U);

    /* Write to GCTL register */
    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GCTL);

    HW_SET_FIELD(regVal, DWC_USB_GCTL_U2RSTECN, 0U);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_FRMSCLDWN, DWC_USB_GCTL_FRMSCLDWN_0);
    /* Set mode of DWC3 device controller as device mode */
    HW_SET_FIELD(regVal, DWC_USB_GCTL_PRTCAPDIR, DWC_USB_GCTL_PRTCAPDIR_DEV);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_DBGATTACH, 0U);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_CORESOFTRESET, DWC_USB_GCTL_CORESOFTRESET_NO);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_RAMCLKSEL, DWC_USB_GCTL_RAMCLKSEL_BUS);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_DISSCRAMBLE, 0U);
    HW_SET_FIELD(regVal, DWC_USB_GCTL_DSBLCLKGTNG, 0U);

    /* Write value to GCTL register */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GCTL, regVal);

    /* Setup event buffer of event Zero */
    usbDwcDcdSetupEvntBuf(dwc3,
                          usbEvnt,
                          USB_DCD_DWC_EVNT_BUF_MAX * sizeof(usbDwcDcdEvnt_t),
                          0U,
                          1U);

    /* Set current event pointer to first entry of event buffer */
    dwc3->pCurrEvntAddr = usbEvnt;

    /* Enable USB reset event  and connect done event*/
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DEVTEN, DWC_USB_DEVTEN_USBRSTEN, 1U);

    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DEVTEN, DWC_USB_DEVTEN_CONNECTDONEEN, 1U);
    /* Enabling the USB disconnect event also */
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DEVTEN, DWC_USB_DEVTEN_DISCONNEVTEN, 1U);

    /* Initialise the transfer resource Allocation
     * This is in accordance with the device initialisation
     * mentioned in the DWC3 device controller data sheet
     */

    /* No command is to be passed for start new config */
    usbDwcDcdRunDEpCmd(dwc3,
                       0U,
                       USB_D_EP_CMD_STARTCFG,
                       NULL,
                       0U,
                       NULL);
    /* Set endpoint configuration for Physical endpoint 0 */

    /* Set command parameters as 0 initially*/
    dEpCmdParm.parm0 = 0;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;

    /* Set the required command parameters */
    /* Parm 0 */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE, 
                 DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_CTRL);

    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS, 512U);

    /* Parm 1 */
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN, 
                 DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN);

    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER, 0U);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN, 
                 DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN);

    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, 
                 DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_OUT);


    usbDwcDcdRunDEpCmd(dwc3,
                       0U,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, 
                 DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN);

    /* Set endpoint configuration for physical endpoint 1 */
    usbDwcDcdRunDEpCmd(dwc3,
                       1U,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* Set Command parameters for  Xfer config command */
    dEpCmdParm.parm0 = 1;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;
    /* Set endpoint transfer resource configuration for endpoint 0 */
    usbDwcDcdRunDEpCmd(dwc3,
                       0U,
                       USB_D_EP_CMD_SETEPXFERRESCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* Set endpoint transfer resource configuration for endpoint 1 */
    usbDwcDcdRunDEpCmd(dwc3,
                       1U,
                       USB_D_EP_CMD_SETEPXFERRESCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* Prepare a buffer for setup packet, initialise a setup TRB and issue
     * start transfer command fo rphysical endpoint 0.
     */
    /* Set the EP0 state to be in SETUP state */
    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;
    usbDwcDcdRunSetupXfer(dwc3);

    /* Enable physical endpoints 0 and 1 and disable all other endpoints */
    regVal = 0;
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_OUT, 1U);
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_IN, 1U);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_DALEPENA, regVal);

   /* Set DCTL.runStop = 1 */
   HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCTL, DWC_USB_DCTL_RUNSTOP, 
                 DWC_USB_DCTL_RUNSTOP_START);

   /* At this point, the device is ready to receive SOF packets,
    * respond to control transfers on control endpoint 0, and generate
    * events.
    */
    return S_PASS;
}

uint32_t USBDwcDcdConfigDevChara( struct usbDcd * pDcdObject,
    usbDevChara_t *pDevCharecteristic)
{
    /* Retrieve private data from core object */
    usbDwcDcdDevice_t *dwc3 = (usbDwcDcdDevice_t *)(pDcdObject->privateData);

    switch(pDevCharecteristic->configparam)
    {
        case USB_DEVICE_DCD_CHARA_SPEED:
            /* This will be handled later */
            break;
        case USB_DEVICE_DCD_CHARA_ADDRESS:
            /* Set the address of the device */
            dwc3->devAddr = pDevCharecteristic->deviceAddress;
            dwc3->deviceNewAddrValidFlag = 1U;
            break;
        case USB_DEVICE_DCD_EP_CONFIG:
            /* Set endpoint configurations */
            dwc3->configNo =  (uint8_t)pDevCharecteristic->epConfigNo;
            usbDwcDcdSetConfiguration(dwc3);
            break;
        default :
            /* error condition on default */
            break;
    }
    return S_PASS;
}

uint32_t USBDwcDcdEp0Req( struct usbDcd *pDcdObject,
                          usbEndpt0Request_t* req)
{
    /* Retrieve private data from core object */
    usbDwcDcdDevice_t *dwc3 = (usbDwcDcdDevice_t *)(pDcdObject->privateData);

    debug_printf("%s:%d. ep0State=%d\n",
                __FUNCTION__, __LINE__, dwc3->ep0State);

    /* Check which kind of transfer has been requested */
    switch(dwc3->ep0State)
    {
        case USB_DWC_DCD_EP0_STATE_SETUP:
            if(1U == req->zeroLengthPacket)
            {
                /* It is a 2 state request, no data phase */
                dwc3->ep0State = USB_DWC_DCD_EP0_STATE_STATUS2;
            }
            else
            {
                /* This is a 2 state request */
                if(USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
                {
                    /* This is a in data request */
                    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_DATA_IN;
                    usbDwcDcdRunXferSingle(dwc3,
                                           1U,
                                           &ctrlDataTrb,
                                           req->pbuf,
                                           req->length,
                                           USB_DWC_DCD_TRB_CTRL_CTRL_DATA1);

                } else if(USB_TOKEN_TYPE_OUT == req->deviceEndptInfo.endpointDirection)
                {
                    /* This is a out data request */
                    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_DATA_OUT;
                    usbDwcDcdRunXferSingle(dwc3,
                                           0U,
                                           &ctrlDataTrb,
                                           req->pbuf,
                                           req->length,
                                           USB_DWC_DCD_TRB_CTRL_CTRL_DATA1);
                }
            }
            break;
        case USB_DWC_DCD_EP0_STATE_DATA_IN:
        case USB_DWC_DCD_EP0_STATE_DATA_OUT:
            dwc3->ep0State = USB_DWC_DCD_EP0_STATE_STATUS3_IN;
            break;
        case USB_DWC_DCD_EP0_STATE_STATUS2:
        case USB_DWC_DCD_EP0_STATE_STATUS3_IN:
        case USB_DWC_DCD_EP0_STATE_STATUS3_OUT:
            break;
        default:
            /* This condition is not taken care of, error */
            break;
    }
    return S_PASS;
}

uint32_t USBDwcDcdEpReq( struct usbDcd * pDcdObject,
                         usbEndptRequest_t* req)
{
    uint32_t epNum = 0;

    /* Retrieve private data from core object */
    usbDwcDcdDevice_t *dwc3 = (usbDwcDcdDevice_t *)(pDcdObject->privateData);

    epNum = req->deviceEndptInfo.endpointNumber;

    if (epNum > DWC_MAX_EP_NUMBER)
    {
        /* TODO: changes all API to return int32_t instead */
        return (uint32_t)E_FAIL;
    }

    /* The request uses logical EP# from higher application. We need to translate
       it to the configured physical EP# */
    epNum = dwc3->ep_to_phyep[epNum];

    /* Run a command to make a transfer as requested by the upper layer */
    if(USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
    {
        /* Set up the TRB for next transfer and start transfer */
        usbDwcDcdRunXferSingle(dwc3,
                               epNum,
                               &bulkInTrb,
                               req->pbuf,
                               req->length,
                               USB_DWC_DCD_TRB_CTRL_NORMAL);
    }
    else
    {
        /* Setup the TRB for next transfer and start the transfer */
        usbDwcDcdRunXferSingle(dwc3,
                               epNum,
                               &bulkOutTrb,
                               req->pbuf,
                               req->length,
                               USB_DWC_DCD_TRB_CTRL_NORMAL);
    }
    return S_PASS;
}

uint32_t USBDwcDcdIntrHandler(usbDwcDcdDevice_t *dwc3)
{
    uint32_t evntCount = 0;
    uint32_t numEvnts, i;


    /* Get the number of events for the selected event buffer */
    evntCount = usbDwcDcdGetEvntCount(dwc3, 1U);
    /* Event count mask */
    evntCount &= 0xFFFC;

    if(evntCount != 0U)
    {
        usb_osalCacheInvalidate(usbEvnt, sizeof(usbEvnt));

        /* Event count is not null means some event has to be processed */
        /* Compute number of events */
        numEvnts = evntCount / sizeof(usbDwcDcdEvnt_t);
        for(i = 0U; i < numEvnts; i++)
        {
            /* Process the current event */
            if((1U == dwc3->pCurrEvntAddr->dEvnt.epSpecEvnt) &&
               (0U == dwc3->pCurrEvntAddr->dEvnt.devSpecEvnt))
            {
                /* event is device specific event */
                usbDwcDcdDevEvntHandler(dwc3, dwc3->pCurrEvntAddr);
            }
            else if(0U == dwc3->pCurrEvntAddr->dEvnt.epSpecEvnt)
            {
                /* The event is endpoint event */
                usbDwcDcdEpEvntHandler(dwc3, dwc3->pCurrEvntAddr);
            }
            else
            {
                /* This event is not handled */
                /* Raise an error */
            }

            if(dwc3->pCurrEvntAddr == usbEvnt + (USB_DCD_DWC_EVNT_BUF_MAX - 1))
            {
                /* Point current event address to first event */
                dwc3->pCurrEvntAddr = usbEvnt;
            }
            else
            {
                /* Increement event address by 1 */
                dwc3->pCurrEvntAddr++;
            }
            /* Update global event counter with number of events processed
             * Hardware decreements the value by count written.
             */
            HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_GEVNTCOUNT(1U),
                          DWC_USB_GEVNTCOUNT_EVNTCOUNT,
                          4U);
        }

       HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_GEVNTSIZ(1U),
                     DWC_USB_GEVNTSIZ_EVNTINTRPTMASK,
                     0U);
    }
    return evntCount;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void usbDwcDcdRunDEpCmd(usbDwcDcdDevice_t *dwc3,
                        uint32_t phEpId,
                        usbDEpCmdType_t pDEpCmdType,
                        usbDwcDcdDEpCmdParms_t * pDEpCmdParm,
                        int32_t rscIdx,
                        uint8_t *pStatus)
{
    /* Temporary variables*/
    uint32_t dEpCmd = 0U, pollCmdAct = 0U;

    /* Set the command type to be issued */
    HW_SET_FIELD(dEpCmd, DWC_USB_DEPCMD_0_CMDTYP, pDEpCmdType);

    /* Set the resource IDX field if required*/
    if(-1 != rscIdx)
    {
        dEpCmd &= ~(0x1F0000);
        dEpCmd |= ((rscIdx << 16U) & 0x1F0000U);
    }

    /* No interrupt on command completion */
    HW_SET_FIELD(dEpCmd, DWC_USB_DEPCMD_0_CMDIOC, DWC_USB_DEPCMD_0_CMDIOC_NO);

    /* CmdAct = 1, triggers command execution */
    HW_SET_FIELD(dEpCmd, DWC_USB_DEPCMD_0_CMDACT, DWC_USB_DEPCMD_0_CMDACT_ACTIVE);

    /* Setup command parameters */
    if(pDEpCmdParm != NULL)
    {
        /* Set param0, param1 and param 2*/
        HW_WR_REG32(dwc3->baseAddr + DWC_USB_DEPCMDPAR0_0(phEpId + 1), pDEpCmdParm->parm0);
        HW_WR_REG32(dwc3->baseAddr + DWC_USB_DEPCMDPAR1_0(phEpId + 1), pDEpCmdParm->parm1);
        HW_WR_REG32(dwc3->baseAddr + DWC_USB_DEPCMDPAR2_0(phEpId + 1), pDEpCmdParm->parm2);

        usb_osalCacheWb(pDEpCmdParm, sizeof(usbDwcDcdDEpCmdParms_t));
    }


    /* Issue the command */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_DEPCMD_0(phEpId + 1), dEpCmd);

    /* Poll while the command is not complete */
    do
    {
        /* Poll for the cmd Act field in the command register for the
         * endpoint for which the command was issued.
         */
        pollCmdAct = HW_RD_FIELD32(dwc3->baseAddr + DWC_USB_DEPCMD_0(phEpId + 1), DWC_USB_DEPCMD_0_CMDACT);
    } while(DWC_USB_DEPCMD_0_CMDACT_DONE != pollCmdAct);

    /* If output command status pointer is valid */
    if(pStatus != NULL)
    {
        /* Extract status field for command completion */
        *pStatus = HW_RD_FIELD32(dwc3->baseAddr + DWC_USB_DEPCMD_0(phEpId + 1), DWC_USB_DEPCMD_0_CMDACT);
    }
}

void usbDwcDcdRunSetupXfer(usbDwcDcdDevice_t *dwc3)
{
    /* Size of the transfer buffer is 8 bytes */
    usbDwcDcdRunXferSingle(dwc3,
                           0U,  /* phEpId */
                           &ctrlDataTrb,
                           &usbCtrlDataBuf,
                           8U,  /* bufSize */
                           USB_DWC_DCD_TRB_CTRL_SETUP);
}

void usbDwcDcdRunXferSingle(usbDwcDcdDevice_t *dwc3,
                            uint32_t phEpId,
                            usbDEpTrb_t *pTrb,
                            void * pBuf,
                            uint32_t bufSize,
                            usbDwcDcdTrbCtrl_t xferType)
{
    /* Setup the TRB and issue start transfer command */
    pTrb->bufPtrLow = (uint32_t) pBuf;
    pTrb->bufPtrHigh = 0;
    pTrb->bufSize = bufSize;
    pTrb->hwo = TRB_CONTROL_HWO_HW;
    pTrb->chn = TRB_CONTROL_CHN_END;
    pTrb->lst = TRB_CONTROL_LST_LAST;
    pTrb->csp = TRB_CONTROL_CSP_STOP;
    pTrb->trbCtrl = xferType;

    /* wb the data buffer for this transaction */
    if (pBuf != NULL)
    {
        usb_osalCacheWbInv(pBuf, bufSize);
    }

    /* Start the transfer*/
    usbDwcDcdStartXfer(dwc3, phEpId, pTrb);
}

void usbDwcDcdCoreInit(usbDwcDcdDevice_t *dwc3)
{
    uint32_t resetVal = 1U;
    /* Reset the device core */
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCTL,
                  DWC_USB_DCTL_CSFTRST,
                  DWC_USB_DCTL_CSFTRST_RESET);

    /* Wait till the soft reset is in progress */
    while(resetVal == HW_RD_FIELD32(dwc3->baseAddr + DWC_USB_DCTL, DWC_USB_DCTL_CSFTRST));

}

void usbDwcDcdSetupEvntBuf(usbDwcDcdDevice_t *dwc3,
                           usbDwcDcdEvnt_t * pUsbEvnt,
                           uint32_t evntSize,
                           uint32_t count,
                           uint32_t eventId)
{
    /* Write address low of the event buffer */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GEVNTADRLO(eventId), (uint32_t)pUsbEvnt);
    /* Address high is taken to be zero */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GEVNTADRHI(eventId), 0U);
    /* Event size as passed in the function parameter */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GEVNTSIZ(eventId), evntSize);
    /* Count of the total USB events */
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GEVNTCOUNT(eventId), count);
}

void usbDwcDcdStartXfer(usbDwcDcdDevice_t *dwc3,
                        uint32_t phEpId,
                        usbDEpTrb_t * pDEpTrb)
{
    /* Update the parameters required for the start transfer command */

    /* In 32 bit system, the upper 32 bits of the address are set to 0
     * In case the system supports more than 32 bits addressing, this
     * can be updated with the required address
     */
    dEpCmdParm.parm0 = 0;

    dEpCmdParm.parm1 = (uint32_t) pDEpTrb;

    debug_printf("%s:%d. ep0State=%d. TransferType=%d\n",
                __FUNCTION__, __LINE__, dwc3->ep0State, pDEpTrb->trbCtrl);

    usb_osalCacheWbInv(pDEpTrb, sizeof(usbDEpTrb_t));

    /* Parameter 2 is unused for this command */
    dEpCmdParm.parm2 = 0;
    usbDwcDcdRunDEpCmd(dwc3,
                       phEpId,
                       USB_D_EP_CMD_STRTXFER,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);
}

uint32_t usbDwcDcdGetEvntCount(usbDwcDcdDevice_t *dwc3, uint32_t evntId)
{
    uint32_t retVal;

    /* Read the event count for required buffer */
    retVal = HW_RD_FIELD32(dwc3->baseAddr + DWC_USB_GEVNTCOUNT(evntId), DWC_USB_GEVNTCOUNT_EVNTCOUNT);

    /* Mask the event interrupts */
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_GEVNTSIZ(evntId), DWC_USB_GEVNTSIZ_EVNTINTRPTMASK, 1U);

    return retVal;
}

void usbDwcDcdRstEvntHandler(usbDwcDcdDevice_t *dwc3)
{
    tDeviceInfo*        ptDeviceInfo;

    debug_printf("%s:%d \n", __FUNCTION__, __LINE__);

    /* Set Default device address to 0 */
    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCFG, DWC_USB_DCFG_DEVADDR, DWC_USB_DCFG_DEVADDR_DEF);

    /* update device state */
    dwc3->pDcdCore->pGadgetObject->devState = USB_DEVICE_STATE_RESET;

    /* calling application reset handler */
    ptDeviceInfo = (tDeviceInfo*)dwc3->pDcdCore->ptDeviceInfo;
    if (ptDeviceInfo->sCallbacks.pfnResetHandler)
    {
        ptDeviceInfo->sCallbacks.pfnResetHandler(ptDeviceInfo->pvInstance);
    }
}


/* handle USB cable disconnect event */
void usbDwcDcdDiscEvntHandler(usbDwcDcdDevice_t *dwc3)
{
    tDeviceInfo*        ptDeviceInfo;

    debug_printf("%s:%d \n", __FUNCTION__, __LINE__);

    /* Move the ep 0 state to setup state */
    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;

    /* calling application disconnect handler */
    ptDeviceInfo = (tDeviceInfo*)dwc3->pDcdCore->ptDeviceInfo;
    if (ptDeviceInfo->sCallbacks.pfnDisconnectHandler)
    {
        ptDeviceInfo->sCallbacks.pfnDisconnectHandler(ptDeviceInfo->pvInstance);
    }
}



/* handle USB cable connect complete event */
void usbDwcDcdCnctDoneEvntHandler(usbDwcDcdDevice_t *dwc3)
{
    uint32_t ctrlPacketSize;

    debug_printf("%s:%d \n", __FUNCTION__, __LINE__);

    /* Control packet size should be according to the speed
    For now keeping it to 64U for high speed and full speed */
    ctrlPacketSize = 64U;

    /* RamCLK Selection field */

    /* Set command parameters as 0 initially*/
    dEpCmdParm.parm0 = 0;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;

    /* Set the required command parameters */
    /* Parm 0 */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_CTRL);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS, ctrlPacketSize);
    /* Ignore sequence number bit */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM, DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_IGNORE);


    /* Parm 1 */
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER, 0U);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_OUT);


    usbDwcDcdRunDEpCmd(dwc3,
                       0U,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* Update parm1 */
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN);
    /* Set endpoint configuration for physical endpoint 1 */
    usbDwcDcdRunDEpCmd(dwc3,
                       1U,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);
}

void usbDwcDcdEp0EvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt)
{
    usbDevRequest_t*      req = 0;
    //usbSetupPkt_t * pSetup = 0;

    debug_printf("%s:%d. evntType=%d. ep0state=%d.phyEpId=%d\n", 
                __FUNCTION__, __LINE__,
                usbDwcDcdEvnt->dEpEvnt.evntType, 
                dwc3->ep0State,
                usbDwcDcdEvnt->dEpEvnt.phEpNum
                );

    /* retrieve request for EP0 */
    req = &(dwc3->pDcdCore->pGadgetObject->requestbuf[0]);

    /* invalidate cache on the buffers used in this function */
    usb_osalCacheInvalidate(usbCtrlDataBuf, sizeof(usbCtrlDataBuf));

    /* check the type of event which occured */
    switch(usbDwcDcdEvnt->dEpEvnt.evntType)
    {
        case USB_DWD_DCD_EVNT_TYPE_XFERNRDY:
            switch(dwc3->ep0State)
            {
                case USB_DWC_DCD_EP0_STATE_STATUS3_IN:
                    /* Prepare a control status 3 TRB for OUT transfer */
                    usbDwcDcdRunXferSingle(dwc3,
                       0U,      /* phEpId */
                       &ctrlStatusTrb,
                       NULL,    /* pBuff */
                       0U,      /* buffSize */
                       USB_DWC_DCD_TRB_CTRL_STATUS3);
                    break;
                case USB_DWC_DCD_EP0_STATE_STATUS3_OUT:
                    /* Prepare a control status 3 TRB for IN transfer */
                    usbDwcDcdRunXferSingle(dwc3,
                           1U,  /* phEpId */
                           &ctrlStatusTrb,
                           NULL,/* pBuff */
                           0U,  /* buffSize */
                           USB_DWC_DCD_TRB_CTRL_STATUS3);
                    break;
                case USB_DWC_DCD_EP0_STATE_DATA_IN:
                    /* Nothing to be done in this case */
                    break;
                case USB_DWC_DCD_EP0_STATE_DATA_OUT:
                    /* Nothing to be done in this case */
                    /* section 8.4.2 three-state control transfer programming model
                       says ignore and continue to wait for XFER complete event */
                    debug_printf("%s:%d. Need to wait for xfer complete event\n",
                                __FUNCTION__, __LINE__);
                    break;
                case USB_DWC_DCD_EP0_STATE_STATUS2:
                    if(1U == dwc3->deviceNewAddrValidFlag)
                    {
                    /* Set the device address*/
                    HW_WR_FIELD32(dwc3->baseAddr + DWC_USB_DCFG,
                                      DWC_USB_DCFG_DEVADDR,
                                  dwc3->devAddr);
                        /* Set the new device address flag to be 0 */
                    dwc3->deviceNewAddrValidFlag = 0U;
                    }
                    /* Prepare a control status 2 TRB */
                    usbDwcDcdRunXferSingle(dwc3,
                           1U,
                           &ctrlStatusTrb,
                           NULL,
                           0U,
                           USB_DWC_DCD_TRB_CTRL_STATUS2);
                    break;
                case USB_DWC_DCD_EP0_STATE_SETUP:
                    /* This indicates that the TRB has not been setup for
                    the setup phase, start a new transfer */
                    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;
                    usbDwcDcdRunSetupXfer(dwc3);
                    break;
                default:
                    /* Error condition, state not found */
                    break;
            }
            break;
        case USB_DWC_DCD_EVNT_TYPE_XFERCOMPLETE:
            /* Take action according to EP0 state */
            switch(dwc3->ep0State)
            {
                case USB_DWC_DCD_EP0_STATE_SETUP:
                    /* Parsing the setup command bytes */
                    /* Call the callback function */
                    dwc3->pDcdCore->gadgetObjCallBack.
                            pFnDevEndpt0Handler(dwc3->pDcdCore->pGadgetObject,
                                                USB_ENDPT0_EVENT_SETUP_PACKET_RECEIVED,
                                                (usbSetupPkt_t*)usbCtrlDataBuf);
                    break;
                case USB_DWC_DCD_EP0_STATE_STATUS2:
                case USB_DWC_DCD_EP0_STATE_STATUS3_IN:
                case USB_DWC_DCD_EP0_STATE_STATUS3_OUT:
                    /* completion of status phase of transfer */
                    /* EP0 is now idle */
                    req->reqComplete(dwc3->pDcdCore->pGadgetObject, req);
                    dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;
                    /* Setup a control TRB */
                    usbDwcDcdRunSetupXfer(dwc3);
                    break;
                case USB_DWC_DCD_EP0_STATE_DATA_IN:
                    /* The IN data transfer has completed */
                    req->reqComplete(dwc3->pDcdCore->pGadgetObject, req);
                    break;
                case USB_DWC_DCD_EP0_STATE_DATA_OUT:
                    /* The data transfer has completed for data out phase */
                    req->reqComplete(dwc3->pDcdCore->pGadgetObject, req);
                    break;
                default :
                    /* this stage is not supported for this type of event */
                    break;
            }
            break;
        default:
            break;
    }
}

void usbDwcDcdEpEvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt)
{
    usbDevRequest_t*      req = 0;
    uint8_t               phyEpNo = 0;
    uint8_t               epNum;

    debug_printf("%s:%d. evntType=%d. \n", 
                __FUNCTION__, __LINE__,
                usbDwcDcdEvnt->dEpEvnt.evntType
                );

    phyEpNo = usbDwcDcdEvnt->dEpEvnt.phEpNum;

    /* Logical endpoints 0 and 1 are handled seperately */
    if((1U == phyEpNo) ||
        (0U == phyEpNo))
    {
        usbDwcDcdEp0EvntHandler(dwc3, usbDwcDcdEvnt);
    }
    else
    {
        /* all other endpoint events are handled here */
        /* find the logical EP number */
        epNum = dwc3->phyep_to_ep[phyEpNo];

        if (epNum > MAX_NUM_REQUESTS)
        {
            /* something is wrong. shouldn't see bogus endpoint number here */
            return;
        }

        /* retrieve request for this endpoint */ 
        req = &(dwc3->pDcdCore->pGadgetObject->requestbuf[epNum]);

        switch(usbDwcDcdEvnt->dEpEvnt.evntType)
        {
            case USB_DWC_DCD_EVNT_TYPE_XFERCOMPLETE:
                if(DWC_BULK_IN_PHY_EP == usbDwcDcdEvnt->dEpEvnt.phEpNum)
                {
                    /* This is a request for in transfer complete */
                    /* Update length to be equal to length transferred */
                    usb_osalCacheInvalidate(&bulkInTrb, sizeof(usbDEpTrb_t));
                    req->length = req->length - bulkInTrb.bufSize;
                    req->reqComplete(dwc3->pDcdCore->pGadgetObject, req);
                }
                else if(DWC_BULK_OUT_PHY_EP == usbDwcDcdEvnt->dEpEvnt.phEpNum)
                {
                    usb_osalCacheInvalidate(&bulkOutTrb, sizeof(usbDEpTrb_t));
                    req->length = req->length - bulkOutTrb.bufSize;
					usb_osalCacheInvalidate((void *)bulkOutTrb.bufPtrLow, req->length);
                    req->reqComplete(dwc3->pDcdCore->pGadgetObject, req);
                }
                break;

            case USB_DWD_DCD_EVNT_TYPE_XFERNRDY:
            break;

            default:
            break;
        }
    }
}

void usbDwcDcdDevEvntHandler(usbDwcDcdDevice_t *dwc3, usbDwcDcdEvnt_t *usbDwcDcdEvnt)
{
    debug_printf("%s:%d. evntType=%d \n", 
                __FUNCTION__, __LINE__, usbDwcDcdEvnt->dEvnt.evntType);

    switch(usbDwcDcdEvnt->dEvnt.evntType)
    {
        case 0U:
            /* Disconnect event handler */
            usbDwcDcdDiscEvntHandler(dwc3);
        break;
        case 1U:/* Reset Event */
            usbDwcDcdRstEvntHandler(dwc3);
            break;
        case 2U: /* Connect done event */
            usbDwcDcdCnctDoneEvntHandler(dwc3);
            break;
        /** More events can be added when required */
        default: /* event is not handled */
            break;
    }
}

void usbDwcDcdSetEpStall(usbDwcDcdDevice_t *dwc3, uint32_t phEpId, uint32_t flag)
{
    if(TRUE == flag)
    {
        /* Set endpoint stall */
        usbDwcDcdRunDEpCmd(dwc3,
                       phEpId,
                       USB_D_EP_CMD_SETSTALL,
                       NULL,
                       -1,
                       NULL);
        if(0U == phEpId)
        {
            dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;
            /* Start a new transfer after issuing a stall*/
            usbDwcDcdRunSetupXfer(dwc3);
        }
    }
    else if(FALSE == flag)
    {
        /* Clear stall */
        usbDwcDcdRunDEpCmd(dwc3,
                       phEpId,
                       USB_D_EP_CMD_CLRSTALL,
                       NULL,
                       -1,
                       NULL);
        if(0U == phEpId)
        {
            dwc3->ep0State = USB_DWC_DCD_EP0_STATE_SETUP;
        }

    }
}


/* -------------------------------------------------------------------------- 
 * Configure the endpoint here. 
 *  TODO: Endpoint number should be taken from the configuration descriptors
 * --------------------------------------------------------------------------*/
void usbDwcDcdSetConfiguration(usbDwcDcdDevice_t *dwc3)
{
    uint32_t bulkInFifoSize, ep0CtrlMps, epBulkMps;
    volatile uint32_t regVal;

    /* these two bulk eps are matching with what the confiugration descriptor for this 
     * USB device. We need to get them from the config descriptor, but defer it for now
     */
    uint32_t bulk_in_ep = 1;    
    uint32_t bulk_out_ep = 2;

    tDeviceInfo*        ptDeviceInfo;

    /* This has to be done based on the speed */
    /* Check this logic */
    bulkInFifoSize = ((2U * (1024U + 8U) + 8U) / 8U);
    ep0CtrlMps = 64U;
    epBulkMps = 512U;

    /* Disable all other endpoints except endpoint 0 */
    regVal = 0;
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_OUT, 1U);
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_IN, 1U);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_DALEPENA, regVal);

    /* Issue a depcfg command for endpoint 1 */
    dEpCmdParm.parm0 = 0;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;

    /* Set the required command parameters */
    /* Parm 0 */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_CTRL);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS, ep0CtrlMps);
    /* Ignore sequence number bit */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM, DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_IGNORE);

    /* Parm 1 */
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER, 0U);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN);


    usbDwcDcdRunDEpCmd(dwc3,
                       1U,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* Run a depstartconfig with xferRscIdx = 2 */
    usbDwcDcdRunDEpCmd(dwc3,
                       0U,
                       USB_D_EP_CMD_STARTCFG,
                       NULL,
                       2U,
                       NULL);

    /* Set default configurations for endpoint 2 */
    /* Set command parameters as 0 initially*/
    dEpCmdParm.parm0 = 0;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;

    /* Set the required command parameters */
    /* Parm 0  - BULK EP */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM, 1U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ, 0U);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE, DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_BULK);
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS, epBulkMps);

    /* Parm 1 - EP2 - OUT EP */
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN, DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER, bulk_out_ep);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_OUT);

    /*
     * Set configurations for endpoint 2: Bulk OUT EP. 
     * Logical EP# 2. Physical EP#:2 
     */
    usbDwcDcdRunDEpCmd(dwc3,
                       DWC_BULK_OUT_PHY_EP,
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

    /* update FIFO NUM for next EP */
    HW_SET_FIELD(dEpCmdParm.parm0, DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM, 2U);

    /* EP IN, EP#: 1*/
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN);
    HW_SET_FIELD(dEpCmdParm.parm1, DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER, bulk_in_ep);

    /*
     * Set configurations for endpoint 3: Bulk IN EP. 
     * Logical EP# 1. Physical EP#:3 
     */
    usbDwcDcdRunDEpCmd(dwc3,
                       DWC_BULK_IN_PHY_EP, /* phEpId */
                       USB_D_EP_CMD_SETEPCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1, /* rscIdx */
                       NULL);

    dEpCmdParm.parm0 = 1;
    dEpCmdParm.parm1 = 0;
    dEpCmdParm.parm2 = 0;

    /* Set Endpoint Transfer Resource Configuration for physical endpoint 2 */
    usbDwcDcdRunDEpCmd(dwc3,
                       DWC_BULK_OUT_PHY_EP,  /* phEpId */
                       USB_D_EP_CMD_SETEPXFERRESCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);

   /* Set Endpoint Transfer Resource Configuration for physical endpoint 3 */
    usbDwcDcdRunDEpCmd(dwc3,
                       DWC_BULK_IN_PHY_EP,  /* phEpId */
                       USB_D_EP_CMD_SETEPXFERRESCFG,
                       (usbDwcDcdDEpCmdParms_t *) &dEpCmdParm,
                       -1,
                       NULL);


    /* Adjust TX fifo RAM allocation based on the connect speed */
    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ0);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFSTADDR, 0U);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFDEP, 66U);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ0, regVal);

    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ1);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFSTADDR, 66U);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFDEP, bulkInFifoSize);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ1, regVal);

    regVal = HW_RD_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ2);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFSTADDR, 66U + 256U);
    HW_SET_FIELD(regVal, DWC_USB_GTXFIFOSIZ0_TXFDEP, bulkInFifoSize);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_GTXFIFOSIZ2, regVal);

    /* Enable physical endpoint 0, 1 and 2 (IN) */
    regVal = 0;
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_OUT, 1U);
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP0_IN, 1U);
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP2_OUT, 1U);
    HW_SET_FIELD(regVal, DWC_USB_DALEPENA_USBACTEP1_IN, 1U);
    HW_WR_REG32(dwc3->baseAddr + DWC_USB_DALEPENA, regVal);

    /* update the endpoint to physical endpoint mapping */
    dwc3->ep_to_phyep[bulk_in_ep] = DWC_BULK_IN_PHY_EP;
    dwc3->ep_to_phyep[bulk_out_ep] = DWC_BULK_OUT_PHY_EP;

    /* update physical endpoint to logical endpoint mapping */
    dwc3->phyep_to_ep[DWC_BULK_IN_PHY_EP] = bulk_in_ep;
    dwc3->phyep_to_ep[DWC_BULK_OUT_PHY_EP] = bulk_out_ep;

    /* If there is a configuration change callback then call it. */
    ptDeviceInfo = (tDeviceInfo*)dwc3->pDcdCore->ptDeviceInfo;
    if (ptDeviceInfo->sCallbacks.pfnConfigChange)
    {
        ptDeviceInfo->sCallbacks.
                pfnConfigChange(ptDeviceInfo->pvInstance,
                                1, /* hard-code to epconfig #1 for now */
                                /*dwc3->deviceInstance.ulConfiguration*/
                                dwc3->controllerId);
    }
}


