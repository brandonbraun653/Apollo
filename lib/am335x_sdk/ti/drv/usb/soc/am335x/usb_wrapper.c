/**
 * \file   am335x/usb_wrapper.c
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
#include "soc_am335x.h"
#include "hw_control_am335x.h"
#include "hw_usbphyGS70.h"
#include "hw_soc.h"
#include "hw_types.h"
#include "hw_cm_per.h"
#include "hw_cm_wkup.h"
#include "usb_drv.h"
#include "usb_osal.h"
#include "hw_usb.h"
#include "musb.h"
#include "usblib.h"
#include "usb_musb_dcd.h"
#include "cppi41dma.h"

#include "usbdaudio.h"
#include "debug.h"

/* extern functions */
void USBHostIntHandlerInternal(uint32_t ulIndex, 
                               uint32_t ulStatus, 
                               uint32_t *endPStatus);
void usbMusbDcdCoreIntrHandler(uint32_t intrId,
                               uint32_t cpuId,
                               void* pUserParam);


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
	HWREG(ulBase + USB_0_IRQ_ENABLE_SET_0) = 0xFFFFFFFF;
	HWREG(ulBase + USB_0_IRQ_ENABLE_SET_1) = 0xFFFFFFFF;
#ifdef DMA_MODE
	HWREG(USBSS_BASE + USBSS_IRQ_ENABLE_SET) = 0xFFFFFFFF;
#endif
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
	HWREG(baseAddr + USB_0_IRQ_STATUS_1) = ulStatus;
	/* Clear the EP interrupt status. */
	HWREG(baseAddr + USB_0_IRQ_STATUS_0) = epStatus;
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
	/*config module clock */
	HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKDCOLDO_DPLL_PER) |= 
		CM_WKUP_CM_CLKDCOLDO_DPLL_PER_DPLL_CLKDCOLDO_GATE_CTRL ; 

    /* same clock system for both USB modules */
    if ((ulIndex==0) || (ulIndex == 1)) 
    {
    	HWREG(SOC_PRCM_REGS + CM_PER_USB0_CLKCTRL) |=
                             CM_PER_USB0_CLKCTRL_MODULEMODE_ENABLE;

        while((HWREG(SOC_PRCM_REGS + CM_PER_USB0_CLKCTRL) &
          CM_PER_USB0_CLKCTRL_MODULEMODE) != CM_PER_USB0_CLKCTRL_MODULEMODE_ENABLE);

        /*
        ** Waiting for IDLEST field in CM_PER_USB0_CLKCTRL register to attain the
        ** desired value.
        */
        while((CM_PER_USB0_CLKCTRL_IDLEST_FUNC <<
               CM_PER_USB0_CLKCTRL_IDLEST_SHIFT)!=
              (HWREG(SOC_CM_PER_REGS + CM_PER_USB0_CLKCTRL) &
               CM_PER_USB0_CLKCTRL_IDLEST));

    } 
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
    if ((ulIndex==0) || (ulIndex ==1)) 
    {
	    HWREG(SOC_PRCM_REGS + CM_PER_USB0_CLKCTRL) |=
                             CM_PER_USB0_CLKCTRL_MODULEMODE_DISABLE;
    }
}



/**  
 * \brief  This API  enables the USB Interrupts through subsystem specific wrapper
 *	       registers
 * \param  Base address
 * \return None
 */
void USBWrapperEnableInt(uint32_t ulBase)
{
	HWREG(ulBase + USB_0_IRQ_ENABLE_SET_0) = 0xFFFFFFFF;
	HWREG(ulBase + USB_0_IRQ_ENABLE_SET_1) = 0xFFFFFFFF;
#ifdef DMA_MODE
	HWREG(USBSS_BASE + USBSS_IRQ_ENABLE_SET) = 0xF04;
	HWREG(USBSS_BASE + USBSS_IRQ_DMA_ENABLE_0) = 0xFFFEFFFE;
#endif
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

    usbphycfg = HWREG(uiPHYConfigRegAddr);
    usbphycfg &= ~(USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN);
    usbphycfg |= (USBPHY_OTGVDET_EN | USBPHY_OTGSESSEND_EN);

    HWREG(uiPHYConfigRegAddr) = usbphycfg;
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
    usbphycfg |= (USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN);
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

    if (ulIndex == 0)
    {
        uiSubBaseAddr = USB_0_OTGBASE;        
    } else if (ulIndex == 1)
    {
        uiSubBaseAddr = USB_1_OTGBASE;        
    } else
    {
        /* we shouldn't get here */
        while(1);
    }


    ulStatus = HWREG(uiSubBaseAddr + USB_0_IRQ_STATUS_1);
    epStatus = HWREG(uiSubBaseAddr + USB_0_IRQ_STATUS_0);

#ifdef DMA_MODE    
    HWREG(USBSS_BASE + USBSS_IRQ_STATUS) = HWREG(USBSS_BASE + USBSS_IRQ_STATUS);
#endif

    USBHostIntHandlerInternal(ulIndex, ulStatus, &epStatus);

    /* clear the interrupts */
    HWREG(uiSubBaseAddr + USB_0_IRQ_STATUS_1) = ulStatus;
    HWREG(uiSubBaseAddr + USB_0_IRQ_STATUS_0) = epStatus;

    HWREG(uiSubBaseAddr + USB_0_IRQ_EOI) = 0;

#ifdef DMA_MODE
    HWREG(USBSS_BASE + USBSS_IRQ_EOI) = 0;
#endif

}

#ifdef DMA_MODE
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
    usbMusbDcdDevice_t* musb;

    musb = (usbMusbDcdDevice_t*)pUsbParam;

    musb->dmaStatus = HWREG(USBSS_BASE + USBSS_IRQ_STATUS);

    /* Clear USBSS INT */
    HWREG(USBSS_BASE + USBSS_IRQ_STATUS) = musb->dmaStatus;

    usbMusbDcdCoreIntrHandler(0, 0, (void*)pUsbParam);

    /* Clear CPPI DMA Intr */
    /* so that any other ISR don't act on false DMA events */
    musb->dmaStatus = 0;

    HWREG(USBSS_BASE + USBSS_IRQ_EOI) = 0;

}

/**
 *
 * Register DMA Interrupt
 * \param    The USB params
 *
 * \return   None
 *
  **/
void USBDmaIntEnable(void* USBparams)
{
	USB_Params *params = (USB_Params*)USBparams;
    HwiP_Params hwiInputParams;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
	hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)params->drvData;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;
    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */

    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(SYS_INT_USBSSINT,
                              (HwiP_Fxn)usbDmaIntrHandler,
                              &hwiInputParams);

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
    ulRegister |= USB_TXCSRH1_DMAMOD;

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
        musbPtr->controllerId = instanceNo;
	}
    else if (instanceNo == 1)
    {
        strcpy(musbPtr->name, "MUSB1");

        /* USB core address */
        musbPtr->baseAddr = USB1_BASE;

        /* USB controller address */
        musbPtr->uiSubBaseAddr = USB_1_OTGBASE;

        /* PHY control registers */
        musbPtr->phyBaseAddr   = CFGCHIP2_USB1PHYCTRL;
        musbPtr->controllerId = instanceNo;
    }
}

/**
 *
 * Initial Configuration of USB Host object
 * \param    musb (tUSBInstanceObject)
 * \param    USB Instance
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
        usbPtr->uiSubInterruptNum = SYS_INT_USBSSINT;
        usbPtr->uiPHYConfigRegAddr = CFGCHIP2_USBPHYCTRL;
	}
	else if(index == 1)
	{
		usbPtr->uiUSBInstance = index;
        usbPtr->uiBaseAddr = USB1_BASE;
        usbPtr->uiSubBaseAddr = USB_1_OTGBASE;
        usbPtr->uiInterruptNum = SYS_INT_USB1;
        usbPtr->uiSubInterruptNum = SYS_INT_USBSSINT;
        usbPtr->uiPHYConfigRegAddr = CFGCHIP2_USB1PHYCTRL;
	}
}

/**
 *
 * Returns the Interrupt Status of the controller
 * \param    base address
 * \param    Interrupt status Flag
 * \param    Endpoint status
 *
 * \return   None
 *
  **/
uint32_t USBGetEndpointIntrStatus(uint32_t baseAddr, uint32_t *ulStatus, uint32_t *epStatus)
{
	uint32_t ulIntrStat = 0;

	/* Get the controller interrupt status. */

    /* These registers are wrapper register - 
       USB0 / USB1 Controller Registers in TRM */
	ulIntrStat = HWREG(baseAddr + USB_0_IRQ_STATUS_1);
    *ulStatus = ulIntrStat;
	 /* Get the EP interrupt status. */
	*epStatus = HWREG(baseAddr + USB_0_IRQ_STATUS_0);

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

	if((musbPtr->dmaStatus & 0xF07))
	{
		usbMusbDcdEpEvntHandler((void *)musbPtr);
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
    uint32_t tx_eps = 0;
    uint32_t rx_eps = 0;
    uint32_t comp_eps = 0;

	usbMusbDcdDevice_t* musb = (usbMusbDcdDevice_t*)musbPtr;
    usbDevRequest_t*    req  = 0;

    lengthTransferedByEp = 0;   /* TODO: figure out where to get this info */
                                /* currently MSC app doesn't need this */
    uint32_t    epNum, epNo;

    if ((musb->epIrqStatus == 0) || (musb->epIrqStatus == 1))
    {
        /* if we get here, the interrupt is from DMA engine. 
         * we can find which endpoint this interrupt is for by looking at the queue
         * pend registers and find which queue it comes from. The queue - ep mapping
         * is mentioned in table 16-27 in TRM */
        debug_printf("No EP IRQ Status. Using DMA to find EP!\n");

        comp_eps = CppiDmaGetEpNumber(musb->controllerId);
    }
    else
    {
        /* find which endpoint this interrupt is for */
        comp_eps = musb->epIrqStatus;
    }

    debug_printf("comp_eps=0x%x\n", comp_eps);

    tx_eps = comp_eps & 0xFFFE;
    rx_eps = (comp_eps & 0xFFFE0000)>>16;

    /* MUSB can have one interrupt for many EPs at the same time. 
       Find out which EP this interrupt belongs to by looking at 
       which bit is set. 
       Since USB only has 16 eps, bitmaps should be a 16 bit number
       We handle EP0 separately so here the EPs we are interested in are 
       only from 1 to 15 */
    for (epNo = 1; epNo<15; epNo++)
    {
        if (tx_eps & (1<<epNo))
        {
            /* This is a request for in transfer complete */
            req = &(musb->pDcdCore->pGadgetObject->requestbuf[epNo]);

            if (epNo == req->deviceEndptInfo.endpointNumber)
            {
                /* we're actually waiting for this transaction. Process it */
                /* Update length to be equal to length transferred */
                req->length = req->length - lengthTransferedByEp;

        #if DMA_MODE
                /* handle DMA completion for IN transaction here */
                dmaTxCompletion(musb->controllerId, INDEX_TO_USB_EP(epNo));
        #endif

                req->reqComplete(musb->pDcdCore->pGadgetObject, req);
            }
            else
            {
                /* cant find the request associted with this IRQ 
                 * must be the ISOC ep. Pass it to application. */
                debug_printf("\n\n*** ISOC IN EP %d. dmaStatus=0x%x.\n", 
                                epNo, musb->dmaStatus);

                /* the function actually handles the DMA transaction, so length = 0 */ 
                musb->pDcdCore->pGadgetObject->usbClass.classAction.
                    epHandler(musb->pDcdCore->pGadgetObject,
	                          USB_GENERIC_EVENT_DATA_IN_COMPLETE, epNo, 0);
            }
        }

        if (rx_eps & (1<<epNo))
        {
            req = &(musb->pDcdCore->pGadgetObject->requestbuf[epNo]);

            if (epNo == req->deviceEndptInfo.endpointNumber)
            {
                epNum = INDEX_TO_USB_EP(epNo);

        #ifdef DMA_MODE
                /* handling DMA completion for OUT transaction */
                dmaRxCompletion(musb->controllerId, epNum, &(req->length));

                /* data should have been written by DMA. no need to copy them out now.
                   Data buffer was associated to DMA transfer in USBMusbDcdEpReq() */
        #else
                USBEndpointDataGet(musb->baseAddr, epNum,
                                   req->pbuf,
                                   &(req->length));

                USBDevEndpointDataAck(musb->baseAddr, epNum, false);
        #endif

                req->length = req->length - lengthTransferedByEp;
                req->reqComplete(musb->pDcdCore->pGadgetObject, req);
            }
            else
            {
                /* there wasn't a matched request for this IRQ. Must be from ISOC EP */
                debug_printf("\n\n*** RX ISOC EP %d. dmaStatus=0x%x\n", 
                             epNo, musb->dmaStatus);

                /* call class spesific event handler */
                musb->pDcdCore->pGadgetObject->usbClass.classAction.
                        epHandler(musb->pDcdCore->pGadgetObject,
	                            USB_GENERIC_EVENT_DATA_OUT_COMPLETE, epNo, 0);
            }
        }   /* rx_eps */
    } /* for epNo */
} /* usbMusbDcdEpEvntHandler */

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

