/**
 * \file   omapl137/usb_wrapper.c
 *
 * \brief  This file contains the board specific code for enabling the use of
 *         usb driver.
 */

/*
* Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include "types.h"
#include "hw_usbphyGS60.h"
#include "hw_soc.h"
#include "hw_types.h"
#include "usb_drv.h"
#include "usb_osal.h"
#include "hw_usb.h"
#include "musb.h"
#include "usblib.h"
#include "usb_musb_dcd.h"
#include "cppi41dma.h"
#include "usbdaudio.h"

/* extern functions */
void USBHostIntHandlerInternal(uint32_t ulIndex,
                               uint32_t ulStatus,
                               uint32_t *endPStatus);


/**
 * \brief  This API returns a unique number which identifies itself
 *         with the USB IP in AM335x SoC.
 * \param  None
 * \return This returns a number '2' which is unique to USB IP in AM335x.
 */
uint32_t USBVersionGet(void)
{
    return 2;
}

/**
 * \brief  This API  enables the USB Interrupts through subsystem specific wrapper
 *	       registers
 * \param  Base address
 * \return None
 */
void USBEnableInt(uint32_t ulBase)
{
	/* Enable the controller interrupt status. */
	HWREG(ulBase + USB_0_INTR_MASK_SET) = 0x01FF1E1F;
}

/**
 * \brief  This API  Clear  the USB Interrupts through subsystem specific wrapper
 *	       registers
 * \param  Base address
 * \param  Interrupt Status Flag
 * \param  Endpoint Status Flag
 * \return None
 */
void USBClearInt(uint32_t baseAddr, uint32_t ulStatus, uint32_t epStatus)
{
	/* Clear the controller interrupt status. */
	HWREG(baseAddr + USB_0_INTR_SRC_CLEAR) = ulStatus;
}

/**
 * \brief  This API  enables the USB Module clock
 *	       registers
 * \param  USB Instance
 * \param  Base address
 * \return None
 */
 void USBModuleClkEnable(uint32_t ulIndex, uint32_t ulBase)
{

}

/**
 * \brief  This API Disables the module clock
 *	       registers
 * \param  USB Instance
 * \param  Base address
 * \return None
 */
void USBModuleClkDisable(uint32_t ulIndex, uint32_t ulBase)
{
	/*Disables the  module clock */
}



/**
 * \brief  This API  enables the USB Interrupts through subsystem specific wrapper
 *	       registers
 * \param  Base address
 * \return None
 */
void USBWrapperEnableInt(uint32_t ulBase)
{
    HWREG(ulBase + USB_0_INTR_MASK_SET) = 0x01FF1E1F;
}


/**
 * \brief  configure USB clock and clock domains
 *	       registers
 * \param  USB instance number
 * \return None
 */
void usbClockCfg(uint32_t portNo)
{
    USBModuleClkEnable(portNo, 0);
}

/**
 * \brief  turn on USB PHY
 *
**/
void UsbPhyOn(uint32_t uiPHYConfigRegAddr)
{
    uint32_t usbphycfg = 0;
    uint32_t i;

    usbphycfg = HWREG(uiPHYConfigRegAddr);

    usbphycfg |= (USBPHY_RESET);
    HWREG(uiPHYConfigRegAddr) = usbphycfg;

    for(i=0; i<50; i++);
    usbphycfg &= 0xFFFF7FFF;
    HWREG(uiPHYConfigRegAddr) = usbphycfg;

    usbphycfg &= 0xFFFF9FFF;
    HWREG(uiPHYConfigRegAddr) = usbphycfg;


    usbphycfg &= ~(USBPHY_PHY_PWRDN | USBPHY_OTG_PWRDN);
    usbphycfg |= (USBPHY_PHY_PLLON);
    usbphycfg |= (USBPHY_REFFREQ_24MHZ) | USBPHY_VBDTCTEN;
    HWREG(uiPHYConfigRegAddr) = usbphycfg;

	while(! (HWREG(uiPHYConfigRegAddr) & USBPHY_CLKGD));
}

/**
 * \brief This function will switch off  the USB Phy
 *
 *
 * \param    None
 *
 * \return   None
 *
  **/
void UsbPhyOff(uint32_t uiPHYConfigRegAddr)
{
    uint32_t  usbphycfg = 0;

    usbphycfg = HWREG(uiPHYConfigRegAddr);

	/** Ensure that USB 1.1 reference clock is not being sourced from
			* USB 2.0 PHY.	Otherwise do not power down the PHY.*/

	if (!( usbphycfg & USBPHY_USB1PHYCLKMUX) && ( usbphycfg & USBPHY_USB1SUSPENDM))
	{
	   return;
	}

    usbphycfg |= (USBPHY_PHY_PWRDN | USBPHY_OTG_PWRDN);
    HWREG(uiPHYConfigRegAddr) = usbphycfg;
}

/**
 * Main USB Host interrupt handler
 *
 *
 * \param    The USB params
 *
 * \return   None
 *
  **/
void usbHostIntrHandler(void* usbParams)
{
    uint32_t ulStatus = 0;
    uint32_t epStatus = 0;
    uint32_t uiSubBaseAddr = 0;
    uint32_t ulIndex;

    ulIndex = ((USB_Params*)usbParams)->instanceNo;

    uiSubBaseAddr = USB_0_OTGBASE;

    ulStatus = HWREG(uiSubBaseAddr + USB_0_INTR_SRC);
    epStatus = 0xFFFF & ulStatus;

	HWREG(uiSubBaseAddr + USB_0_INTR_SRC_CLEAR) = ulStatus;

    USBHostIntHandlerInternal(ulIndex, (ulStatus >> 16), &epStatus);

    HWREG(uiSubBaseAddr + USB_0_IRQ_EOI) = 0;
}

#ifdef DMA_MODE
/**
 *
 * Register DMA Interrupt
 * \param    The USB params
 *
 * \return   None
 *
  **/
void USBDmaIntEnable(void* params)
{

}

/**
 *
 * CPPI DMA interrupt handler
 * \param    the musb obj (usbMusbDcdDevice_t)
 *
 * \return   None
 *
  **/
void usbDmaIntrHandler(uint32_t* pUsbParam)
{

}
#endif

/**
 *
 * Enable CPPI DMA Mode
 * \param    Base Address
 * \param    DMA Mode Flag
 * \param    Register value
 * \param    Endpoint offset
 *
 * \return   None
 *
  **/
void USBDMAModeTXEnable(uint32_t ulBase, uint32_t ulFlags, uint32_t ulRegister, uint32_t ulEndpoint)
{
    if(ulFlags & USB_EP_DMA_MODE_1)
    {
        ulRegister |= USB_TXCSRH1_DMAEN | USB_TXCSRH1_DMAMOD;
    }
    else if(ulFlags & USB_EP_DMA_MODE_0)
    {
        ulRegister |= USB_TXCSRH1_DMAEN;
    }

	/* Write out the transmit control value. */
    HWREGB(ulBase + ulEndpoint + USB_O_TXCSRH1) =
         (unsigned char)ulRegister;
}

/**
 *
 * Initial Configuration of USB Device object
 * \param    musb (usbMusbDcdDevice_t)
 * \param    USB instance
 *
 * \return   None
 *
  **/
void USBInitMUSBDevCfg(void *musb, uint32_t instanceNo)
{
	usbMusbDcdDevice_t *musbPtr = (usbMusbDcdDevice_t*)musb;
	if (instanceNo == 0)
	{
        strcpy(musbPtr->name, "MUSB0");

        /* the "USB0 Core Registers" base address */
        musbPtr->baseAddr = USB0_BASE;

        /* the "USB0 Controller Registers" base address */
        musbPtr->uiSubBaseAddr = USB_0_OTGBASE;

        /* PHY control registers */
        musbPtr->phyBaseAddr   = CFGCHIP2_USBPHYCTRL;
	}
}

/**
 *
 * Initial Configuration of USB Host object
 * \param    musb (tUSBInstanceObject)
 * \param    USB instance
 *
 * \return   None
 *
  **/
void USBInitMUSBHostCfg(void *usb, uint32_t index)
{
	tUSBInstanceObject *usbPtr = (tUSBInstanceObject *)usb;

	if(index == 0)
	{
		usbPtr->uiUSBInstance = index;
        usbPtr->uiBaseAddr = USB0_BASE;
        usbPtr->uiSubBaseAddr = USB_0_OTGBASE;
        usbPtr->uiInterruptNum = SYS_INT_USB0;
        usbPtr->uiPHYConfigRegAddr = CFGCHIP2_USBPHYCTRL;
	}
}

/**
 *
 * Returns the Interrupt Status of the controller
 * \param    base address
 * \param    Interrupt status Flag pointer
 * \param    Endpoint status pointer
 *
 * \return   Endpoint Interrupt status
 *
  **/
uint32_t USBGetEndpointIntrStatus(uint32_t baseAddr, uint32_t *ulStatus, uint32_t *epStatus)
{
	uint32_t ulIntrStat = 0;

	/* Get the controller interrupt status. */
	ulIntrStat = HWREG(baseAddr + USB_0_INTR_SRC);
	 /* Get the EP interrupt status. */
	*epStatus = 0xFFFF & ulIntrStat;
	*ulStatus = (ulIntrStat >> 16);

	return ulIntrStat;
}

#ifdef DMA_MODE
/**
 *
 * Handles the CDMA Queue Pend Status for any reception or transmission
 * \param    musb (tUSBInstanceObject)
 *
 * \return   None
 *
 **/
void DMAQueuePendHandler(void *musb)
{
	usbMusbDcdDevice_t *musbPtr = (usbMusbDcdDevice_t*)musb;

	/* Get the Starvation interrupt status */
	CppiDmaGetINTD0Status(musbPtr->controllerId);

    /* Get the DMA Interrupt status */
	musbPtr->dmaStatus = CppiDmaGetPendStatus(musbPtr->controllerId);

	if(musbPtr->dmaStatus & CPDMA_TX_PENDING)
	{
		usbMusbDcdEpEvntHandler((void *)musbPtr);
	}
	while(musbPtr->dmaStatus & CPDMA_RX_PENDING)
	{
		usbMusbDcdEpEvntHandler((void *)musbPtr);
		musbPtr->dmaStatus = CppiDmaGetPendStatus(musbPtr->controllerId);
	}
}
#endif

/**
 * USB endpoint event handler which handles the various endpoint
 *        events of the Musb controler.
 *
 * \param Musb pointer to the Musb device object.
 *
 */
void usbMusbDcdEpEvntHandler(void *musbPtr)
{
    uint32_t lengthTransferedByEp;
#if DMA_MODE
	uint32_t rxBuffer;
#endif

	usbMusbDcdDevice_t *musb = (usbMusbDcdDevice_t*)musbPtr;

    lengthTransferedByEp = 0;   /* TODO: figure out where to get this info */
                                /* currently MSC app doesn't need this */
    uint32_t    epNum;

    if (musb->lastReqDirection == MUSB_DCD_EP_DIR_IN)
    {
        epNum = musb->inEpReq->deviceEndptInfo.endpointNumber;

        /* This is a request for in transfer complete */
        /* Update length to be equal to length transferred */
        musb->inEpReq->length = musb->inEpReq->length - lengthTransferedByEp;

#if DMA_MODE

        /* handle DMA completion for IN transaction here */
        dmaTxCompletion(musb->controllerId, INDEX_TO_USB_EP(epNum));
#endif

        musb->inEpReq->reqComplete(musb->pDcdCore->pGadgetObject, musb->inEpReq);
    }
    else if(musb->lastReqDirection == MUSB_DCD_EP_DIR_OUT)
    {

        epNum = musb->outEpReq->deviceEndptInfo.endpointNumber;
        epNum = INDEX_TO_USB_EP(epNum);

#ifdef DMA_MODE

        /* handling DMA completion for OUT transaction */
        rxBuffer = dmaRxCompletion(musb->controllerId, epNum, 
                                   &(musb->outEpReq->length));

        memcpy(musb->outEpReq->pbuf, (void*)rxBuffer, musb->outEpReq->length);

        cppiDmaFreeBuffer((uint32_t*)rxBuffer);

#else
        USBEndpointDataGet(musb->baseAddr, epNum,
                           musb->outEpReq->pbuf,
                           &(musb->outEpReq->length));

        USBDevEndpointDataAck(musb->baseAddr, epNum, false);

#endif

        musb->outEpReq->length = musb->outEpReq->length - lengthTransferedByEp;

        musb->outEpReq->reqComplete(musb->pDcdCore->pGadgetObject, musb->outEpReq);

    }
	else
    {
#ifdef DMA_MODE
	    /* ISO IN interrupt */
        if (musb->dmaStatus & CPDMA_TX_PENDING)
        {
            /* call class spesific event handler */
            musb->pDcdCore->pGadgetObject->usbClass.classAction.epHandler(musb->pDcdCore->pGadgetObject,
                                USB_GENERIC_EVENT_DATA_IN_COMPLETE,
                                ISOC_IN_ENDPOINT, musb->inEpReq->length);
        }

        /* ISO OUT interrupt */
        if (musb->dmaStatus & CPDMA_RX_PENDING)
        {
            /* call class spesific event handler */
            musb->pDcdCore->pGadgetObject->usbClass.classAction.epHandler(musb->pDcdCore->pGadgetObject,
                             USB_GENERIC_EVENT_DATA_OUT_COMPLETE, 
                             ISOC_OUT_ENDPOINT, musb->outEpReq->length);
        }
#else
        /* ISO OUT interrupt */
        epNum = USB_EP_TO_INDEX(ISOC_OUT_ENDPOINT);
        if ((musb->epIrqStatus) & (epNum << USB_RECEIVE_INTR_SHIFT) )
        {
	     /* call class spesific event handler */
	     musb->pDcdCore->pGadgetObject->usbClass.classAction.epHandler(musb->pDcdCore->pGadgetObject,
	                 USB_GENERIC_EVENT_DATA_OUT_COMPLETE, musb->outEpReq->length);
        }

        /* ISO IN interrupt */
        epNum = USB_EP_TO_INDEX(ISOC_IN_ENDPOINT);
        if (musb->epIrqStatus & (epNum << USB_TRANSMIT_INTR_SHIFT))
        {
	     /* call class spesific event handler */
	     musb->pDcdCore->pGadgetObject->usbClass.classAction.epHandler(musb->pDcdCore->pGadgetObject,
	                 USB_GENERIC_EVENT_DATA_IN_COMPLETE, musb->inEpReq->length);
        }
#endif

    }
}

/**
 * Init clocks and power domain for USB host
 *
 *
 * \param    USB instance number
 *
 * \return   None
 *
  **/
void USB_Host_Init(uint32_t ulIndex)
{
    /* dummy for AM335x */
}

/****************************** End Of File *********************************/
