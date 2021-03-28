/**
 *  \file     dra72x/usb_wrapper.c
 *
 *  \brief    This file contains APIs for manipulating the SOC specific wrapper. 
 *            As the name suggests this file implements the USB wrapper as
 *            impemented by DRA7xx .
 *
 *  \copyright Copyright (C) 2017 - 2018 Texas Instruments Incorporated -
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

#include "usb_wrapper.h"

/* ========================================================================== */
/*                 extern Function Prototypes                                 */
/* ========================================================================== */
extern void USBHCDTerm(uint32_t ulIndex);

/* ========================================================================== */
/*                 Prototypes                                                 */
/* ========================================================================== */
static void USBOTGSS_USBPHY_PowerSequence_VAYU(uint32_t portNum);
static int32_t usb3_wrapper_config(uint32_t portNumber);
static int32_t USBOTGSS_CLKCONFIG_Vayu_DPLL_USB_OTG_SS(void);
static int32_t ocp2scp_reset(uint32_t base);
static void ocp2scp_set_timing(uint32_t base);
static void USBOTGSS_WRAPPER_ForceVbus(uint32_t portNumber, uint32_t isDeviceMode);
static void usb3_phy_reset(uint32_t portNumber);

/* ========================================================================== */
/*                            Macros                                          */
/* ========================================================================== */
#define CM_CLKMODE_DPLL_USB                             ((uint32_t)0x4A008180U)
#define CM_AUTOIDLE_DPLL_USB                            ((uint32_t)0x4A008188U)
#define CM_CLKSEL_DPLL_USB                              ((uint32_t)0x4A00818CU)
#define CM_DIV_M2_DPLL_USB                              ((uint32_t)0x4A008190U)
#define CM_IDLETEST_DPLL_USB                            ((uint32_t)0x4A008184U)

#define CM_L3INIT_CLKSTCTRL                             ((uint32_t)0x4A009300U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL                      ((uint32_t)0x4A0093E0U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL                      ((uint32_t)0x4A0093E8U)

#define CM_L3INIT_USB_OTG_SS2_CLKCTRL                   ((uint32_t)0x4A009340U)
#define CM_L3INIT_USB_OTG_SS1_CLKCTRL                   ((uint32_t)0x4A0093F0U)

#define CM_COREAON_CLKSTCTRL                            ((uint32_t)0x4A008600U)
#define CM_COREAON_USB_PHY1_CORE_CLKCTRL                ((uint32_t)0x4A008640U)
#define CM_COREAON_USB_PHY2_CORE_CLKCTRL                ((uint32_t)0x4A008688U)
#define CM_COREAON_USB_PHY3_CORE_CLKCTRL                ((uint32_t)0x4A008698U)
#define CM_COREAON_L3INIT_60M_GFCLK_CLKCTRL             ((uint32_t)0x4A0086C0U)

#define CTRL_CORE_PHY_POWER_USB                         ((uint32_t)0x4A002370U)
#define CTRL_CORE_SRCOMP_NORTH_SIDE                     ((uint32_t)0x4A002e74U)
#define CTRL_CORE_DEV_CONF                              ((uint32_t)0x4A002300U)
#define CTRL_CORE_PAD_USB1_DRVVBUS                      ((uint32_t)0x4A003680U)
#define CTRL_CORE_PAD_USB2_DRVVBUS                      ((uint32_t)0x4A003684U)

#define CM_L3INIT_USB_OTG_SSn_CLKCTRL(n)                (((n)==0)?(CM_L3INIT_USB_OTG_SS1_CLKCTRL):\
                                                            (CM_L3INIT_USB_OTG_SS2_CLKCTRL))
#define CM_COREAON_USB_PHYn_CORE_CLKCTRL(n)             (((n)==0)?(CM_COREAON_USB_PHY1_CORE_CLKCTRL):\
                                                            (CM_COREAON_USB_PHY2_CORE_CLKCTRL))


#define DPLLCTRL_USB_OTG_SS                             ((uint32_t)0x4A084C00U)

#define PLLCTRL__PLL_STATUS                             ((uint32_t)0x00000004U)
#define PLLCTRL__PLL_STATUS__PLLCTRL_RESET_DONE__RDONE  (uint32_t)(1<<0)
#define PLLCTRL__PLL_STATUS__PLL_LOCK                   (uint32_t)(1<<1)
#define PLLCTRL__PLL_GO                                 ((uint32_t)0x00000008U)
#define PLLCTRL__PLL_CONFIGURATION1                     ((uint32_t)0x0000000CU)
#define PLLCTRL__PLL_CONFIGURATION2                     ((uint32_t)0x00000010U)
#define PLLCTRL__PLL_CONFIGURATION2__PLL_SELFREQDCO     ((uint32_t)1U)
#define PLLCTRL__PLL_CONFIGURATION2__PLL_LOCKSEL        ((uint32_t)9U)
#define PLLCTRL__PLL_CONFIGURATION3                     ((uint32_t)0x00000014U)
#define PLLCTRL__PLL_CONFIGURATION3__PLL_SD             ((uint32_t)10U)
#define PLLCTRL__PLL_CONFIGURATION4                     ((uint32_t)0x00000020U)
#define PLLCTRL__PLL_CONFIGURATION4__PLL_REGM2          ((uint32_t)0U)
#define PLLCTRL__PLL_CONFIGURATION4__PLL_REGM_F         ((uint32_t)0U)


/* OCPSCP registers */
#define OCP2SCP1_BASE                                   ((uint32_t)0x4A080000U)
#define OCP2SCP3_BASE                                   ((uint32_t)0x4A090000U)

#define OCP2SCP__OCP2SCP_SYSCONFIG                      ((uint32_t)0x10U)
#define OCP2SCP__OCP2SCP_SYSSTATUS                      ((uint32_t)0x14U)
#define OCP2SCP__OCP2SCP_TIMING                         ((uint32_t)0x18U)

#define OCP2SCP_TIMEOUT                                 ((uint32_t)0x10000U)


/* ========================================================================== */
/*                            Functions                                       */
/* ========================================================================== */

void USBWrapperIntDisable(uint32_t baseAddr)
{
    /* clear IRQ enable (i.e disable) */
    HW_WR_FIELD32((baseAddr + USB_WRAPPER_IRQENABLE_CLR_0),
                   USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN, 
                   USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_CLEAR);         
}


void USBWrapperIntClear(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + USB_WRAPPER_IRQSTATUS_0,
                 USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST, 0x1);

    HW_WR_FIELD32((baseAddr + USB_WRAPPER_IRQ_EOI),
                 USB_WRAPPER_IRQ_EOI_EOI0, 0x1);
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

    /* clear the Intr pending bit in DWC_USB_USBSTS */
    XHCIIsrEntryActions(xhciData->usbInstance);

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
void usbPhyOn(uint32_t instanceNumber, uint32_t invertPolarity)
{
    uint32_t regVal = 0;

    /* USB PADCONF
       CTRL_MODULE_CORE_CTRL_CORE_PAD_USB1_DRVVBUS */     
    HW_WR_REG32(CTRL_CORE_PAD_USB1_DRVVBUS, 0x000C0000U);
    HW_WR_REG32(CTRL_CORE_PAD_USB2_DRVVBUS, 0x000C0000U);

    if (instanceNumber == 0) 
    {
        regVal = HW_RD_REG32(CTRL_CORE_DEV_CONF);
        regVal = regVal & (uint32_t)(~((uint32_t)1<<(uint32_t)0));    /* USB2_PHY1 - USBPHY_PD */
        HW_WR_REG32(CTRL_CORE_DEV_CONF, regVal);
    } 
    else if (instanceNumber == 1) 
    {
        /* USBOTGSS_CLKCONFIG_USB2PhyOn  */
        regVal = HW_RD_REG32(CTRL_CORE_SRCOMP_NORTH_SIDE);
        regVal = regVal & (~(1U<<28U));   /* USB2PHY2_PD */
        HW_WR_REG32(CTRL_CORE_SRCOMP_NORTH_SIDE, regVal);
    }
}

/* turn on USB DPLL */
static int32_t USBOTGSS_CLKCONFIG_Vayu_DPLL_USB_OTG_SS(void) 
{
    uint32_t done;
    uint32_t regVal;

    /* Check if PLL is out of reset */
    do {
        done = HW_RD_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_STATUS);
    } while ((done & PLLCTRL__PLL_STATUS__PLLCTRL_RESET_DONE__RDONE) == 0);


    /*----------------------------------*/
    /* Set DPLL factors When SSC is OFF */
    /*----------------------------------*/
    /*INFO(fprintf(UARTW, "[USBOTGSS_CLOCKCONFIG] : Setting DPLL - SSC OFF \r\n");) */
    
    /* PLL_REGN = 7; PLL_REGM = 1000 */
    HW_WR_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_CONFIGURATION1, (7<<1) | (1000<<9));


    regVal = HW_RD_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_CONFIGURATION2);

    /*PLLCTRL__PLL_CONFIGURATION2__PLL_SELFREQDCO = 4 */
    /*PLL_LOCKSEL = 0; // phase Lock = 1; */
    regVal |= ((4<<PLLCTRL__PLL_CONFIGURATION2__PLL_SELFREQDCO) |
               (0<<PLLCTRL__PLL_CONFIGURATION2__PLL_LOCKSEL));

    HW_WR_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_CONFIGURATION2, regVal);
    
    /* PLLCTRL__PLL_CONFIGURATION3__PLL_SD */
    HW_WR_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_CONFIGURATION3, 
                (10<<PLLCTRL__PLL_CONFIGURATION3__PLL_SD));
                
    
    HW_WR_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_GO, (1<<0));  /* turn on GO bit */

    /* wait for LOCK */
    do {
        done = HW_RD_REG32(DPLLCTRL_USB_OTG_SS + PLLCTRL__PLL_STATUS);
    } while ((done & PLLCTRL__PLL_STATUS__PLL_LOCK) == 0);


    return 0;
}


static void USBOTGSS_USBPHY_PowerSequence_VAYU(uint32_t portNum)
{         
    uint32_t reg;   
    uint32_t dwc3BaseAddr;

    dwc3BaseAddr = USB_DWC3_WRAPPER_BASE_ADDR(portNum) + USB_DWC_CORE_OFFSET;

    /* Assert PHY Reset */
    reg = HW_RD_REG32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL);
    reg = reg | (1U<<31);

    HW_WR_REG32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL, reg);


    /* Powerup both RX and TX in the same time */
    /* Communicate SYS_CLK value to the power seq */

    /* FREQ value is 0x14 for 20MHz sysclk. */
    /* CLK_CMD presumebly is (3 << 14) to enable both RX & TX */
    reg =  HW_RD_REG32(CTRL_CORE_PHY_POWER_USB);
    reg |= (3<<14);
    HW_WR_REG32(CTRL_CORE_PHY_POWER_USB, reg);
    reg |= ((uint32_t)0x14<<22);
    HW_WR_REG32(CTRL_CORE_PHY_POWER_USB, reg);
 
    /* Deassert PHY reset */
    reg = HW_RD_REG32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL);
    reg = reg & (~(1U<<31));
    HW_WR_REG32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL, reg);
}



static void usb3_phy_reset(uint32_t portNumber)
{
    volatile uint32_t loop;
    uint32_t dwc3BaseAddr;

    dwc3BaseAddr = USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + USB_DWC_CORE_OFFSET;

    /*
     * PHYs Reset
     */
    /* USB 2 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr + DWC_USB_GUSB2PHYCFG,
                  DWC_USB_GUSB2PHYCFG_PHYSOFTRST,
                  DWC_USB_GUSB2PHYCFG_PHYSOFTRST_ACTIVE);

    /* USB 3 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL,
                  DWC_USB_GUSB3PIPECTL_PHYSOFTRST,
                  DWC_USB_GUSB3PIPECTL_PHYSOFTRST_ACTIVE);

    /* USB 3 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr + DWC_USB_GCTL,
                  DWC_USB_GCTL_CORESOFTRESET,
                  DWC_USB_GCTL_CORESOFTRESET_RESET);

    for (loop = 0; loop < 0x10000; loop++);

    /* USB 2 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr +  DWC_USB_GUSB2PHYCFG,
                  DWC_USB_GUSB2PHYCFG_PHYSOFTRST,
                  DWC_USB_GUSB2PHYCFG_PHYSOFTRST_INACTIVE);

    /* USB 3 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr + DWC_USB_GUSB3PIPECTL,
                  DWC_USB_GUSB3PIPECTL_PHYSOFTRST,
                  DWC_USB_GUSB3PIPECTL_PHYSOFTRST_INACTIVE);

    for (loop = 0; loop < 0x10000; loop++);

    /* USB 3 PHY Reset */
    HW_WR_FIELD32(dwc3BaseAddr + DWC_USB_GCTL,
                  DWC_USB_GCTL_CORESOFTRESET,
                  DWC_USB_GCTL_CORESOFTRESET_NO);

}

static int32_t usb3_wrapper_config(uint32_t portNumber)

{
    uint32_t reg;   

    reg = HW_RD_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + 
                      USB_WRAPPER_SYSCONFIG);

    /* smart standby: force no standby / no idle for debug */
    /*HW_WR_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + */
    /*            USB_WRAPPER_SYSCONFIG,  */
    /*            (reg | (1<<4) | (1<<2))); */

    /* smart standby smart idle */
    HW_WR_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) + 
                USB_WRAPPER_SYSCONFIG, 
                (reg | (3<<4) | (3<<2)));

    return 0;
}


static void USBOTGSS_WRAPPER_ForceVbus(uint32_t portNumber, uint32_t isDeviceMode)
{
    uint32_t reg;   

    reg = HW_RD_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) +
                      USB_WRAPPER_UTMI_OTG_STATUS);

    if (isDeviceMode)
    {
        reg |=  (1U<<31); /* SW_MODE */
        reg |=  (1<<9);  /* Powerpresent??? (do we need this for device mode?) */
        reg |=  (1<<4);  /* ID floating */
        reg |=  (1<<2);  /* SESSVALID, VBUS above sessionvalid threshold??? */
        
        reg |=  (1<<3);  /* SESSEND = 1 */
        reg |=  (1<<1);  /* VBUS_VALID = 1 */
    }
    else
    {
        reg |=  (1U<<31); /* SW_MODE */
        reg |=  (1<<9);  /* Powerpresent */
        reg &= ~(1<<4);  /* ID = 0; */
        reg |=  (1<<2);  /* SESSVALID, VBUS above sessionvalid threshold??? */
        reg |=  (1<<1);  /* VBUS_VALID = 1 */
    }

    HW_WR_REG32(USB_DWC3_WRAPPER_BASE_ADDR(portNumber) +  
                USB_WRAPPER_UTMI_OTG_STATUS, reg);
}



void usbClockCfg(uint32_t portNumber)
{
    uint32_t regVal = 0;
    uint32_t phyBase = 0;
    
    /* enable ocp2scp1 */
    /* write this to be able to read/write the PHY registers */
    HW_WR_REG32(CM_L3INIT_OCP2SCP1_CLKCTRL, 0x1);   /* AUTO mode */
    HW_WR_REG32(CM_L3INIT_OCP2SCP3_CLKCTRL, 0x1);   /* AUTO mode - might not need this */

    /* set OCP2SCP timing */
    ocp2scp_reset(OCP2SCP1_BASE);
    ocp2scp_set_timing(OCP2SCP1_BASE);
    /* done configurating ocp2scp1 */

    /* need this OTG_SS_CLKCLTRL before getting a DPLL_USB lock */
    regVal = HW_RD_REG32(CM_L3INIT_USB_OTG_SSn_CLKCTRL(portNumber));
    regVal |= 0x101U;   /*OPTFCLKEN_REFCLK960M | MODULEMODE__AUTO */
    HW_WR_REG32(CM_L3INIT_USB_OTG_SSn_CLKCTRL(portNumber), regVal);

    /*HW_WR_REG32(CM_L3INIT_CLKSTCTRL, 0x3); */
    /*HW_WR_REG32(CM_COREAON_CLKSTCTRL, 0x3); */

    /* only USB port 0 has USB3.0 PHY which requires a separate DPLL */
    if (portNumber==0){
        USBOTGSS_CLKCONFIG_Vayu_DPLL_USB_OTG_SS();      /* USB3 PLL - without PLL, Port never reaches U0 */
        USBOTGSS_USBPHY_PowerSequence_VAYU(portNumber);

    }

    HW_WR_REG32(CM_AUTOIDLE_DPLL_USB, (uint32_t)1);

    /* USB 2.0 clocks
       CM_CLKSEL_DPLL_USB. 
       DPLL_USB is type B and thus Fclkdcoldo = Fref * M / (N+1) = 960MHz
       Fclkdcoldo is fed to USB (refclk960m)
       {1344,  28-1,  4 },  // 20 MHz 
       DPLL_SD_DIV = 4; DPLL_MULT=1344, DPLL_DIV=28. Ref = 20MHz => F=960MHz
       SD_DIV = CEILING ((MUL/(DIV+1))*refClk/250) */
    HW_WR_REG32(CM_CLKSEL_DPLL_USB, ((4<<24)|(1344<<8)|(27)));
    /*HW_WR_REG32(CM_CLKSEL_DPLL_USB, 0x0401e009); */

    /* set the CLKOUT_M2??. Value - Fdpll/(2*M2) */
    HW_WR_REG32(CM_DIV_M2_DPLL_USB, (2<<0)); /* matching linux */

    /*CM_CLKMODE_DPLL_USB - start the PLL */
    HW_WR_REG32(CM_CLKMODE_DPLL_USB, 0x7U); /* 0x7 is DPLL in LOCK mode */

    /* wait for PLL lock */
    regVal = HW_RD_REG32(CM_IDLETEST_DPLL_USB);
    while((regVal & (1<<0)) != 1){
        regVal = HW_RD_REG32(CM_IDLETEST_DPLL_USB);
    }

    /* USB PHY optional 32K clock */
    HW_WR_REG32(CM_COREAON_USB_PHYn_CORE_CLKCTRL(portNumber), 0x100U);

    if (portNumber==0){
        usb3_phy_reset(portNumber);
    }

    /* turn on the L3INIT_480M_GFCLK bit in the CLKSTCTRL. 
       Must have for device mode. Doesn't hurt with host mode */
    HW_WR_REG32(CM_COREAON_L3INIT_60M_GFCLK_CLKCTRL, 0x100U); 


    /* configuring USB2 PHY registers that are only accessible after clocks
       have been set. */
    if (portNumber == 0) 
    {
        phyBase = USB0_USB_PHY_BASE_ADDR; 
    }
    else  
    {
        phyBase = USB1_USB_PHY_BASE_ADDR; 
    }

    /* USB2.0 only: set USB2PHY_ANA_CONFIG:31 DISCON_DETECT_BYPASS bit
       to fix some possible noise / ringing problems */
    regVal = HW_RD_REG32(phyBase + USB_USB2PHY_ANA_CONFIG1);
    regVal |= ((1U<<31));    /*DISCON_DETECT_BYPASS */
    HW_WR_REG32(phyBase + USB_USB2PHY_ANA_CONFIG1, regVal);

} /* usbClockCfg */




/* dealing with OCP2SCP registers */
static int32_t ocp2scp_reset(uint32_t base)
{   
    uint32_t loop;
    uint32_t done;

    
    /* soft reset OCP2SCP */
    /* OCP2SCP__OCP2SCP_SYSCONFIG__SOFTRESET; */
    HW_WR_REG32(base + OCP2SCP__OCP2SCP_SYSCONFIG, 1<<1);
            
    loop = 0;
    do {
        done = HW_RD_REG32(base + OCP2SCP__OCP2SCP_SYSSTATUS);

        /*OCP2SCP__OCP2SCP_SYSSTATUS__RESETDONE */
        done &= (1<<0);

        loop ++;
        if (loop == OCP2SCP_TIMEOUT)
            return -2;
    } while (1 != done);

    return 0;
}

static void ocp2scp_set_timing(uint32_t base)
{
    uint32_t regVal;

    regVal = 0 | (1<<7)  /*DIVISIONRATIO = 1 */
               | (0<<4)  /*SYNC1 = 0 */
               | ((uint32_t)0xF<<0); /*SYNC2 = F */

    HW_WR_REG32(base + OCP2SCP__OCP2SCP_TIMING, regVal);
    return;
}



/* Enable all the interrupts for wrapper */
void usbDwcDcdEnableWrapperIntr(uint32_t baseAddr)
{
    /* Enable main interrupts */
    uint32_t regVal = 1U;
    HW_WR_REG32(baseAddr + USB_WRAPPER_IRQENABLE_SET_0, regVal);
}


/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup */
void usbDwcDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* read the value of Misc interrupt status */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQSTATUS_1);

    /* clear the misc interrupt */
    HW_WR_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQSTATUS_1, regVal);
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup */
void usbDwcDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* turn off USB core interrupts - main 0 interrupts */
    HW_WR_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQENABLE_SET_0, 0U);

    /* read the value of main interrupt status */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQSTATUS_0);

    /* Call device interrupt handler */
    USBDwcDcdIntrHandler((usbDwcDcdDevice_t *)pUserParam);

    /* Clear the interrupt which occured */
    HW_WR_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQSTATUS_0, regVal);

    HW_WR_REG32(dwc3->wrapperAddr + USB_WRAPPER_IRQENABLE_SET_0, 1U);
}


void usb_wrapper_setup_device_mode(uint32_t portNum)
{
    uint32_t isDeviceMode = 1;  /* device mode */
    USBOTGSS_WRAPPER_ForceVbus(portNum, isDeviceMode);
    usb3_wrapper_config(portNum);
}


void usb_wrapper_setup_host_mode(uint32_t portNum)
{
    uint32_t isDeviceMode = 0;  /* host mode. */
    USBOTGSS_WRAPPER_ForceVbus(portNum, isDeviceMode);
    usb3_wrapper_config(portNum);

}


