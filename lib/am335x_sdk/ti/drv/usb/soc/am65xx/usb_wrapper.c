/**
 *  \file     am65xx/usb_wrapper.c
 *
 *  \brief    This file contains APIs for manipulating the SOC specific wrapper. 
 *            As the name suggests this file implements the USB wrapper as
 *            impemented by AM6x .
 *
 *  \copyright Copyright (C) 2018-2019 Texas Instruments Incorporated -
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
#include "usb_drv.h"
#include "debug.h"
#include <ti/csl/csl_serdes.h>
#include <ti/csl/csl_serdes_usb.h>

/* ========================================================================== */
/*                 extern Function Prototypes                                 */
/* ========================================================================== */
extern void USBHCDTerm(uint32_t ulIndex);
extern void CSL_serdesWaitForCMUOK(uint32_t baseAddr);

extern USB_Config USB_config[3];

/* ========================================================================== */
/*                 Prototypes                                                 */
/* ========================================================================== */
int32_t usbClockSSCfg(void);

/* ========================================================================== */
/*                            Macros                                          */
/* ========================================================================== */
#define KICK0 0x68EF3490ull
#define KICK1 0xD172BC5Aull

/* ========================================================================== */
/*                            Functions                                       */
/* ========================================================================== */

void USBWrapperIntDisable(uint32_t baseAddr)
{
    /* clear IRQ enable (i.e disable) */
}


void USBWrapperIntClear(uint32_t baseAddr)
{
}

void usbHostIntrHandler(void* drvData)
{
    /* we don't use interrupt in host mode yet.*/
}

/* turn on the USB PHY and do its settings */
void usbPhyOn(uint32_t instanceNumber, uint32_t invertPolarity)
{
}


void usb3_phy_reset(uint32_t portNumber)
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
    return 0;
}




/* setting up USB clocks for USB instance #portNumber 
 * which is either 0 or 1 
 */
void usbClockCfg(uint32_t portNumber)
{
    uint32_t regVal = 0;
    uint32_t phyBase = 0;

#ifndef DOING_SERDES_AFTER_CORE_INIT
    USB_Config* usbConfig = &USB_config[portNumber];

    /* enable USB2.0 clocks */
    /* nothing need to be done for USB2.0 clocks */
 
    /* if the USB application requires Super Speed 
       enable USB3 Phy serdes */
    if ((portNumber == 0) && /* only port #0 supports SS */
       (usbConfig->usb30Enabled == TRUE) /* user asks for USB3.0  */)
    {
        if (usbClockSSCfg() != 0)
        {
            debug_printf("Error when enabling Super Speed\n");
        }
    }
#endif

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
    regVal = HW_RD_REG32(phyBase + CSL_USB3_PHY2_ANA_CONFIG1);
    regVal |= ((1U<<31));    /*DISCON_DETECT_BYPASS */
    HW_WR_REG32(phyBase + CSL_USB3_PHY2_ANA_CONFIG1, regVal);


    /* usb3_phy_reset(portNumber); */
} /* usbClockCfg */


/* setting up clock for USB3.0 Super speed 
 * On AM6/Maxwell, only USBSS0 is SS capable
 * Am6 USB3 SS PHY is a SB serdes. Using CSL to init
 * return 0 if success.
 */
int32_t usbClockSSCfg(void)
{
    CSL_SerdesResult    sdrc;
    uint32_t            numLanes = 1;
    uint32_t            baseAddr = CSL_SERDES0_BASE;
    CSL_SerdesRefClock  refClock = CSL_SERDES_REF_CLOCK_100M; 
    CSL_SerdesLinkRate  linkRate = CSL_SERDES_LINK_RATE_5G;
    int32_t             i;
    int32_t             rc;

	CSL_SerdesLaneEnableParams serdesLaneEnableParams;
	CSL_SerdesLaneEnableStatus laneRetVal = CSL_SERDES_LANE_ENABLE_NO_ERR;

    /* set SERDES0 refclock to MAIN_PLL */
    /* Unlock Lock1 Kick Registers */
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0) = KICK0;
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1) = KICK1;

    /* Unlock Lock2 Kick Registers */
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK0) = KICK0;
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK1) = KICK1;

    /* Select lane_func_sel based on the serdes type */
    /* change SERDES mux to do USB PHY */ 
    /* #define CSL_FINS(reg, PER_REG_FIELD, val) */
    CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + 
                           CSL_MAIN_CTRL_MMR_CFG0_SERDES0_CTRL),
                           MAIN_CTRL_MMR_CFG0_SERDES0_CTRL_LANE_FUNC_SEL, 
                           0x0); /* USB3 function */

    /* SERDES0_CTRL_CLKSEL */ 
    CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + 
                           CSL_MAIN_CTRL_MMR_CFG0_SERDES0_CTRL),
                           MAIN_CTRL_MMR_CFG0_SERDES0_CTRL_CLK_SEL, 
                           0x4); /* left input - which goes to clk mux */ 

    /* Set the serdes refclk input mux to main_pll_clkout */
    CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + 
                           CSL_MAIN_CTRL_MMR_CFG0_SERDES0_REFCLK_SEL),
                           MAIN_CTRL_MMR_CFG0_SERDES0_REFCLK_SEL_CLK_SEL, 
                           0x2); /* MAIN_PLL_CLKOUT */

    /* init the SERDES */
    sdrc = CSL_serdesUSBInit(baseAddr, numLanes, refClock, linkRate);
    if (sdrc == CSL_SERDES_NO_ERR)
    {
        rc = 0;
    }
    else
    {
        rc = sdrc;
    }

    if (rc == 0)
    {
        memset(&serdesLaneEnableParams, 0, sizeof(serdesLaneEnableParams));

        serdesLaneEnableParams.baseAddr     = baseAddr;
        serdesLaneEnableParams.refClock     = refClock;
        serdesLaneEnableParams.linkRate     = linkRate;
        serdesLaneEnableParams.numLanes     = numLanes;
        serdesLaneEnableParams.laneMask     = 0x1; /* all lanes */
        serdesLaneEnableParams.phyType      = CSL_SERDES_PHY_TYPE_USB;
        serdesLaneEnableParams.operatingMode= CSL_SERDES_FUNCTIONAL_MODE;
        serdesLaneEnableParams.forceAttBoost= CSL_SERDES_FORCE_ATT_BOOST_DISABLED;


        for(i=0; i< serdesLaneEnableParams.numLanes; i++)
        {
          serdesLaneEnableParams.laneCtrlRate[i] = CSL_SERDES_LANE_FULL_RATE;
          serdesLaneEnableParams.loopbackMode[i] = CSL_SERDES_LOOPBACK_DISABLED;
          serdesLaneEnableParams.rxCoeff.forceAttVal[i] = 7;
          serdesLaneEnableParams.rxCoeff.forceBoostVal[i] = 1;
        }

        /* Common Lane Enable API for lane enable, pll enable etc */
        laneRetVal = CSL_serdesLaneEnable(&serdesLaneEnableParams);

        if (laneRetVal == CSL_SERDES_LANE_ENABLE_NO_ERR)
        {
            rc = 0;

            /* force signal detect high for lane 0 - 11/14/2018 */
            debug_printf("Forcing serdes sig detect high for lane 0\n");
            CSL_serdesForceSigDetHigh(baseAddr, 0);
        }
        else
        {
            rc = laneRetVal;
        }
    }

    /* set PIPE3_TXB_CLK to PIPE3_TXB_CLK */
    CSL_FINSR(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + 
                            CSL_MAIN_CTRL_MMR_CFG0_SPARE_CTRL1), 0, 0, 0x0);


    return rc;
}



/* Enable all the interrupts for wrapper */
void usbDwcDcdEnableWrapperIntr(uint32_t baseAddr)
{
    /* No need to set anything on the wrapper to 
     * Enable USB main interrupts on AM65xx. 
     *
     * WR1 IRQ_STATUS_RAW_MAIN will trigger USB main interrupt
     * WR1 to IRQ_STATUS_MAIN to clear set interrupt.
     *
     * DWC core interrupt will still trigger interrupt no matter what.
     */

    /* USB misc interrupts enabling is still done through 
       IRQ_ENABLE_SET_MISC, but since we are not handling MISC interrupts 
       now so not enabling them */
}


/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup */
void usbDwcDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbDwcDcdDevice_t* dwc3;

    dwc3 = (usbDwcDcdDevice_t*)pUserParam;

    /* read the value of Misc interrupt status */
    uint32_t regVal = HW_RD_REG32(dwc3->wrapperAddr + CSL_USB3_GMOD_IRQ_MISC_STATUS);

    /* clear the misc interrupt */
    HW_WR_REG32(dwc3->wrapperAddr + CSL_USB3_GMOD_IRQ_MISC_STATUS, regVal);
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup */
void usbDwcDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    /* Call device interrupt handler */
    USBDwcDcdIntrHandler((usbDwcDcdDevice_t *)pUserParam);
}


void usb_wrapper_setup_device_mode(uint32_t portNum)
{
    usb3_wrapper_config(portNum);

    if (portNum == 0)
    {
        *(uint64_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_USB0_CTRL) = 0x30;
    }
    else if (portNum == 1)
    {
        *(uint64_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_USB1_CTRL) = 0x30;
    }
}


void usb_wrapper_setup_host_mode(uint32_t portNum)
{
    usb3_wrapper_config(portNum);

}


#ifdef USB3_DEBUG

CSL_SerdesTbusDump      tbusLaneDump;
CSL_SerdesTbusDump      tbusCMUDump;

/* wait for LTSSM get to polling.active and dump the TBUS debug info 
 * Used only to debug USB3.0 SERDES on AM65xx 
 *
 * Note: do not enable this function during normal USB LLD operation when
 * USB2.0 devices are expected to be used. 
 *
 * This function is expected to be used during USB3.0 debug only. 
 * It will stall if USB3.0 fails or if USB2.0 device is plugged in.
 *
 */
void usb30Debug(void)
{
    uint32_t linkState = 0;
    uint32_t subState = 0;
    uint32_t regVal;
    volatile uint32_t att, boost;
    uint32_t baseAddr = CSL_USB3SS0_CORE_CAP_BASE; /* USB0_DWC_WRAPPER_BASE_ADDR + 0x10000; */

    while (1)
    {
        regVal = HW_RD_REG32(baseAddr +  DWC_USB_GDBGLTSSM);
        
        linkState = (regVal  >> 22) & 0xF;
        subState = (regVal >> 18) & 0xF;
        
        if ((linkState == DWC_USB_GDBGLTSSM_LTDBLINKSTATE_POLLING) && 
            (subState == 4 /* polling/active */))
        {
            CSL_serdesTbusLaneDump(CSL_SERDES0_BASE, &tbusLaneDump);
            CSL_serdesTbusCMUDump(CSL_SERDES0_BASE, &tbusCMUDump);

            debug_printf("got to config.active and finished dumping TBUS data\n\n");

            /* printing tbus data */
            debug_printf("TBUS: pma_ln_dlpf_bf_i[9:0] = %d\n", (tbusLaneDump.tbusData[41])&0x3FF);
            debug_printf("TBUS: ln_astat_i[5:0] = %d\n", (tbusLaneDump.tbusData[12])&0x3F);

            att = (CSL_serdesReadSelectedTbus(CSL_SERDES0_BASE, 0+1, 0x40) & 0x070) >> 4;
            boost = (CSL_serdesReadSelectedTbus(CSL_SERDES0_BASE, 0+1, 0x44) & 0x078) >> 3;

            debug_printf("\nAttenuation is %d\n", att );
            debug_printf("Boost is %d\n", boost );

            break;
        }
    }
}
#endif


void usb_controller_setup_host_mode(uint32_t portNum)
{
    uint32_t regVal;
    uint32_t baseAddr;

    baseAddr = XhciRegBaseAddr(portNum); 

    /*Setting the XHCI3 controller for Host mode operation */
    regVal = HW_RD_REG32(baseAddr + DWC_USB_GCTL); 
    regVal  &= ~(3 << DWC_USB_GCTL_PRTCAPDIR_SHIFT); /* prtcapdir clr - tt - This line seems crucial **** */

    HW_WR_REG32(baseAddr + DWC_USB_GCTL, regVal); 
    regVal |= (DWC_USB_GCTL_PRTCAPDIR_HST << DWC_USB_GCTL_PRTCAPDIR_SHIFT);
    HW_WR_REG32(baseAddr + DWC_USB_GCTL, regVal );

    /* USB3.0 */
    /*regVal = HW_RD_REG32(baseAddr + DWC_USB_GUSB3PIPECTL); */
    /*HW_WR_FIELD32(baseAddr + DWC_USB_GUSB3PIPECTL, DWC_USB_GUSB3PIPECTL_LFPSFILT, 1); */
    HW_WR_REG32(baseAddr + DWC_USB_GUSB3PIPECTL, 0x00040002); /* this value gives a much cleaner LSSM */
}
