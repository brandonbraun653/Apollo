/**
 *  \file     am437x/usb_wrapper.c
 *
 *  \brief    This file contains APIs for manipulating the SOC specific wrapper. 
 *            As the name suggests this file implements the USB wrapper as
 *            impemented by AM43xx .
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
#include "usb_misc.h"

#include "hw_usbotgss_c2_wrapper.h"
#include "usb_hcd_xhci.h"
#include "usb_dwc_dcd.h"

#include "hw_cm_per.h"
#include "hw_cm_wkup.h"
#include "hw_control_am43xx.h"
#include "hw_usb.h"

#include "usb_wrapper.h"

#define AM43XX_CONTROL_MODULE_BASE_ADRESS    0x44E10000
#define SOC_CONTROL_MODULE_BASE_ADRESS       AM43XX_CONTROL_MODULE_BASE_ADRESS

#define AM43XX_CLOCK_MODULE_PER_REG_BASE_ADRESS    0x44df8800
#define SOC_CM_PER_REG_BASE_ADRESS       AM43XX_CLOCK_MODULE_PER_REG_BASE_ADRESS

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* ========================================================================== */
/*                 extern Function Prototypes                                 */
/* ========================================================================== */
extern void USBHCDTerm(uint32_t ulIndex);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


void USBWrapperIntDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr +
        USBOTGSS_C2_WRAPPER_IRQENABLE_CLR_MAIN_0(1)),
        USBOTGSS_C2_WRAPPER_IRQENABLE_CLR_MAIN_0_COREIRQ_EN, 
        USBOTGSS_C2_WRAPPER_IRQENABLE_CLR_MAIN_0_COREIRQ_EN_CLEAR);         
    
}


void USBWrapperIntClear(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + USBOTGSS_C2_WRAPPER_IRQSTATUS_MAIN_0(1U)),
                 USBOTGSS_C2_WRAPPER_IRQSTATUS_MAIN_0_COREIRQ_ST, USB_SET_BIT_1);

    HW_WR_FIELD32((baseAddr + USBOTGSS_C2_WRAPPER_IRQ_EOI_MAIN),
                 USBOTGSS_C2_WRAPPER_IRQ_EOI_MAIN_EOI0, USB_SET_BIT_1);
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




void usbPhyOn(uint32_t instanceNumber, uint32_t invertPolarity)
{
    if (instanceNumber == 1) 
    {
        /* This Powers on the PHY */
        /* This is not for OTG Analog macro in Aegis but for DRVVBUS */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_OTG_PWRDN, 0U);
                
        /* controls the PD input signal of PHY should be 0 for normal operation */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_CM_PWRDN, 0U);            
                
        /* Voltage comparators enables as in DV Testcase flow */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_OTGSESSENDEN, 1U);             

        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_OTGVDET_EN, 1U);   

        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_DPPULLUP, 1U);       
        
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_DMPULLDN, 1U);     
            
        if(invertPolarity)
        {
            HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                          CTRL_USB_CTRL1_DATAPOLARITY_INV, 1U);                   
        }
    } 
    else if (instanceNumber == 0)
    {
        /* This Powers on the PHY */
        /* This is not for OTG Analog macro in Aegis but for DRVVBUS */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                      CTRL_USB_CTRL0_OTG_PWRDN, 0U);
                
        /* controls the PD input signal of PHY should be 0 for normal operation */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                      CTRL_USB_CTRL0_CM_PWRDN, 0U);            
                
        /* Voltage comparators enables as in DV Testcase flow */
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                      CTRL_USB_CTRL0_OTGSESSENDEN, 1U);             

        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                      CTRL_USB_CTRL0_OTGVDET_EN, 1U);   

        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                      CTRL_USB_CTRL0_DPPULLUP, 1U);       
        
        HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL1, 
                      CTRL_USB_CTRL1_DMPULLDN, 1U);     
            
        if(invertPolarity)
        {
            HW_WR_FIELD32(SOC_CONTROL_MODULE_BASE_ADRESS + CTRL_USB_CTRL0, 
                          CTRL_USB_CTRL0_DATAPOLARITY_INV, 1U);                   
        }
    }
    else
    {
       /* wrong instance Number */
       while(1);
    }
}

void usbClockCfg(uint32_t portNumber)
{
    if (portNumber == 0)
    {
        /* port 0 only? */
        HW_WR_FIELD32(SOC_CM_PER_REG_BASE_ADRESS + PRCM_CM_PER_USBPHYOCP2SCP0_CLKCTRL, 
            PRCM_CM_PER_USBPHYOCP2SCP0_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_USBPHYOCP2SCP0_CLKCTRL_MODULEMODE_ENABLE);
        
        HW_WR_FIELD32(SOC_CM_PER_REG_BASE_ADRESS + PRCM_CM_PER_USB_OTG_SS0_CLKCTRL, 
            PRCM_CM_PER_USB_OTG_SS0_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_USB_OTG_SS0_CLKCTRL_MODULEMODE_ENABLE);
    } 
    else if (portNumber == 1)
    {
        HW_WR_FIELD32(SOC_CM_PER_REG_BASE_ADRESS + PRCM_CM_PER_USBPHYOCP2SCP1_CLKCTRL, 
            PRCM_CM_PER_USBPHYOCP2SCP1_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_USBPHYOCP2SCP1_CLKCTRL_MODULEMODE_ENABLE);
            
        HW_WR_FIELD32(SOC_CM_PER_REG_BASE_ADRESS + PRCM_CM_PER_USB_OTG_SS1_CLKCTRL, 
            PRCM_CM_PER_USB_OTG_SS1_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_USB_OTG_SS1_CLKCTRL_MODULEMODE_ENABLE);

        HW_WR_FIELD32(SOC_CM_PER_REG_BASE_ADRESS + PRCM_CM_PER_USB_OTG_SS1_CLKCTRL, 
            PRCM_CM_PER_USB_OTG_SS1_CLKCTRL_OPTFCLKEN_REFCLK960M,
            PRCM_CM_PER_USB_OTG_SS1_CLKCTRL_OPTFCLKEN_REFCLK960M_FCLK_EN);
     }
} /*usbClockCfg */




/* Enable all the interrupts for wrapper */
void usbDwcDcdEnableWrapperIntr(uint32_t baseAddr)
{
    /* Enable main interrupts */
    uint32_t regVal = 1U;
    HW_WR_REG32(baseAddr + USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MAIN_0(1), regVal);

    /* Enable misc interrupts */
    regVal = 0U;

    /* Enable all misc interrupts */
    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DRVVBUS_RISE_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DRVVBUS_RISE_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_CHRGVBUS_RISE_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_CHRGVBUS_RISE_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DISCHRGVBUS_RISE_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DISCHRGVBUS_RISE_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_IDPULLUP_RISE_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_IDPULLUP_RISE_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DRVVBUS_FALL_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DRVVBUS_FALL_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_CHRGVBUS_FALL_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_CHRGVBUS_FALL_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DISCHRGVBUS_FALL_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_DISCHRGVBUS_FALL_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_IDPULLUP_FALL_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_IDPULLUP_FALL_EN);

    HW_SET_FIELD(regVal, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_OEVT_EN, 
                 USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC_OEVT_EN);

    HW_WR_REG32(baseAddr + USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MISC, regVal);
}


/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup */
void usbDwcDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* read the value of Misc interrupt status */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr + 
                                   USBOTGSS_C2_WRAPPER_IRQSTATUS_MISC);

    /* clear the misc interrupt */
    HW_WR_REG32(dwc3->wrapperAddr + USBOTGSS_C2_WRAPPER_IRQSTATUS_MISC, regVal);
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup */
void usbDwcDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;
    uint32_t regVal;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* turn off USB core interrupts - main 0 interrupts */
    HW_WR_REG32(dwc3->wrapperAddr + 
                USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MAIN_0(0), 0U);

    /* read the value of main interrupt status */
    regVal = HW_RD_REG32(dwc3->wrapperAddr + 
                         USBOTGSS_C2_WRAPPER_IRQSTATUS_MAIN_0(0));

    /* Call device interrupt handler */
    USBDwcDcdIntrHandler((usbDwcDcdDevice_t *)pUserParam);

    /* Clear the interrupt which occured */
    HW_WR_REG32(dwc3->wrapperAddr + 
                USBOTGSS_C2_WRAPPER_IRQSTATUS_MAIN_0(0), regVal);

    HW_WR_REG32(dwc3->wrapperAddr + 
                USBOTGSS_C2_WRAPPER_IRQENABLE_SET_MAIN_0(0), 1U);
}



void usb_wrapper_setup_device_mode(uint32_t portNum)
{
    uint32_t baseAddr = 0;

    baseAddr = USB_DWC3_WRAPPER_BASE_ADDR(portNum);

    /* No software mode (use hw signal) */
    /* ID = 1 - floating - device mode */
    /* SESSEND = 1 */
    HW_WR_REG32(baseAddr + USBOTGSS_C2_WRAPPER_UTMI_OTG_STATUS, 0x18);
}


void usb_wrapper_setup_host_mode(uint32_t portNum)
{
    /*nothing to do for AM437x */
}



