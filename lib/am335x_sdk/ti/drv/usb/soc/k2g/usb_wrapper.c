/**
 *  \file     k2g/usb_wrapper.c
 *
 *  \brief    This file contains APIs for manipulating the SOC specific wrapper
 *            impemented by K2G .
 *
 *  \copyright Copyright (C) 2016 Texas Instruments Incorporated -
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "hw_types.h"
#include "error.h"

#include "usb_hcd_xhci.h"
#include "usb_dwc_dcd.h"
#include "hw_usb.h"

/* ========================================================================== */
/*                 extern Function Prototypes                                 */
/* ========================================================================== */
extern void USBHCDTerm(uint32_t ulIndex);

/* ========================================================================== */
/*                 Prototypes                                                 */
/* ========================================================================== */
static int32_t usb_wrapper_config(uint32_t portNumber);
/* ========================================================================== */
/*                            Macros                                          */
/* ========================================================================== */

/* ========================================================================== */
/*                            Functions                                       */
/* ========================================================================== */

void USBWrapperIntDisable(uint32_t baseAddr)
{
    /* clear IRQ enable (i.e disable) */
    HW_WR_FIELD32((baseAddr + CSL_USB3SS_IRQ_ENABLE_CLR_MAIN(0)),
                   CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_IRQ_ENABLE_CLR_MAIN, 0x1U);         
}


void USBWrapperIntClear(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + CSL_USB3SS_IRQ_STATUS_MAIN(0),
                 CSL_USB3SS_IRQ_STATUS_MAIN_IRQ_STATUS_MAIN, 0x1U);

    HW_WR_FIELD32((baseAddr + CSL_USB3SS_IRQ_EOI_MAIN),
                  CSL_USB3SS_IRQ_EOI_MAIN_EOI0, 0x1U);
}

void usbHostIntrHandler(void* drvData)
{
    uint32_t portStatus = 0;
    XHCI_DATA_S* xhciData = 0;

    xhciData = (XHCI_DATA_S*)drvData;

    /* disable interrupt */
    USBWrapperIntDisable(USB_DWC3_WRAPPER_BASE_ADDR(xhciData->usbInstance));
    
    /* clear interrupt? */
    USBWrapperIntClear(USB_DWC3_WRAPPER_BASE_ADDR(xhciData->usbInstance));

    /* clear the Intr pending bit in DWC_USB_USBSTS - this causes problem with K2G enumeration */
    /*XHCIIsrEntryActions(xhciData.usbInstance); */

    /* do interrupt task */
    portStatus = USBIntStatusControl(XhciRegBaseAddr(xhciData->usbInstance));
    if (portStatus == USB_DWC_INT_DISCONNECT) {
        /* quick and dirty restart */
        USBHCDTerm(xhciData->usbInstance);
        /*g_sUSBHCD[ulIndex].eDeviceState[0] = HCD_DEV_DISCONNECTED; */
        xhci_disable_slot(xhciData->usbInstance);
    }
    
    /* reenable is done when command_completion_handler is done clearing the interrupt. */
}

/* turn on the USB PHY and do its settings */
void usbPhyOn(uint32_t portNumber, uint32_t invertPolarity)
{
    uint32_t regVal;

    regVal = HW_RD_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + 
                         CSL_USB3SS_SYSCONFIG);

    /* enables all clocks & DMA */
    regVal &= ~((1<<0)   ||    /* soft reset */
                (0x7F00) ||    /* bit 8 - 14  */
                (3<<16));      /* bit 16, 17: DMA, RESET */

    HW_WR_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + 
                CSL_USB3SS_SYSCONFIG, regVal);

}


static int32_t usb_wrapper_config(uint32_t portNumber)
{
    /* nothing needed yet... */
    return 0;
}


void usb_wrapper_force_vbus(uint32_t portNumber, uint32_t isDeviceMode)
{
    uint32_t reg;   
    uint32_t baseAddr = USB_DWC3_WRAPPER_BASE_ADDR(portNumber);

    reg = HW_RD_REG32(baseAddr + CSL_USB3SS_UTMI_OTG_STATUS);

    if (isDeviceMode)
    {
        reg |=  (1<<31); /* SW_MODE */
        reg |=  (1<<9);  /* Powerpresent??? (do we need this for device mode?) */
        reg |=  (1<<4);  /* ID floating */
        reg |=  (1<<2);  /* SESSVALID, VBUS above sessionvalid threshold??? */
        
        reg |=  (1<<3);  /* SESSEND = 1 */
        reg |=  (1<<1);  /* VBUS_VALID = 1 */
    }
    else
    {
        /* host mode */
        reg |=  (1<<31); /* SW_MODE */
        reg &= ~(1<<9);  /* Powerpresent */
        reg |=  (1<<4);  /* ID = 1;  */
        reg &= ~(1<<2);  /* SESSVALID, VBUS above sessionvalid threshold??? */
        reg &= ~(1<<1);  /* VBUS_VALID = 1 */
    }

    HW_WR_REG32(baseAddr + CSL_USB3SS_UTMI_OTG_STATUS, reg);

    /* turn on VBUS for host mode */
    if (!isDeviceMode)
    {
        reg = HW_RD_REG32(baseAddr + CSL_USB3SS_UTMI_OTG_CTRL);
        reg |= (1<<5);  /* DRVVBUS */
        HW_WR_REG32(baseAddr + CSL_USB3SS_UTMI_OTG_CTRL, reg);

        /* turn on PHY_OTG_DFT_VAL_DRVVBUS - OTG_DFT_SEL_IDDIG */
        HW_WR_REG32(USB_BOOTCFG_USB_PHYCTL(portNumber, 1), (0x300000 | (1<<22))); 
    }
    else 
    {
        /* in device mode. enable the pull up resistor on D+ */
        reg = HW_RD_REG32(USB_BOOTCFG_USB_PHYCTL(portNumber, 0));
        reg |= (2<<1); /* bit 2, value 1. VBUSVLDEXT */
        HW_WR_REG32(USB_BOOTCFG_USB_PHYCTL(portNumber, 0), reg);
    }
}



void usbClockCfg(uint32_t portNumber)
{
    uint32_t regVal;
    volatile uint32_t delay;
    
    /* USB core clock */
    regVal = 0;
    regVal &= ~(  1 << 1);   /* Set the divider load enable (bit 1) */
    regVal &= ~(  1 << 0);   /* select UART PLL output (bit 0 = 0) */
    regVal |=  (0xF << 8);   /* bit 8-12: clkCore div - will be ignored due to divider bit */

    HW_WR_REG32(USB_BOOTCFG_USB_CLKCTL(portNumber), regVal);
    
    for (delay=0; delay<(100000U); delay++);

    /*PHY CTRL regs */
    regVal = HW_RD_REG32(USB_BOOTCFG_USB_PHYCTL(portNumber, 4));

    HW_SET_FIELD(regVal, CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_OTGDISABLE, 1);  /* power down OTG block */
    HW_SET_FIELD(regVal, CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL, 0); 
    HW_SET_FIELD(regVal, CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_REFCLKSEL, 0x2); /* internal clock */
    HW_SET_FIELD(regVal, CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_FSEL, 0x5);      /* 24MHz */

    HW_WR_REG32(USB_BOOTCFG_USB_PHYCTL(portNumber, 4), regVal);


} /*usbClockCfg */





/* Enable all the interrupts for wrapper */
void usbDwcDcdEnableWrapperIntr(uint32_t baseAddr)
{
    /* Enable main interrupts */
    uint32_t regVal = 1U;
    HW_WR_REG32(baseAddr + CSL_USB3SS_IRQ_ENABLE_SET_MAIN(0), regVal);
}


/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup */
void usbDwcDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* read the value of Misc interrupt status */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr +  CSL_USB3SS_IRQ_STATUS_MISC);

    /* clear the misc interrupt */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_STATUS_MISC, regVal);
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup */
void usbDwcDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* disable interrupt */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_ENABLE_CLR_MAIN(0), 0x1U);

    /* read the value of main interrupt status
     * IRQ_STATUS_MAIN is cleared if ENABLE_CLR_MAIN is set
     */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_STATUS_RAW_MAIN(0x0U));

    /*
     * Clear the interrupt which occured
     *    This has to be done before the DWC core interrupt handler
     *
     * Kepler/Lamarr/Edision/Galileo DWC interrupt is a level interrupt in device mode
     * but pulse interrupt in host mode.
     *
     * For K2 devices in device mode we must write to IRQ_STATUS_MAIN before
     * clearing the DWC interrupts (gEventCount)
     *
     */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_STATUS_MAIN(0x0U), regVal);

    /* Call DWC device mode interrupt handler */
    USBDwcDcdIntrHandler((usbDwcDcdDevice_t *)pUserParam);

    /* enable IRQ again */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_ENABLE_SET_MAIN(0), 0x1U);

    /* end of IRQ */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3SS_IRQ_EOI_MAIN, 0x1U);
}


void usb_wrapper_setup_device_mode(uint32_t portNum)
{
    uint32_t isDeviceMode = 1;  /* device mode */
    usb_wrapper_force_vbus(portNum, isDeviceMode);
    usb_wrapper_config(portNum);
}


void usb_wrapper_setup_host_mode(uint32_t portNum)
{
    uint32_t isDeviceMode = 0;  /* host mode. */
    usb_wrapper_force_vbus(portNum, isDeviceMode);
    usb_wrapper_config(portNum);

}


