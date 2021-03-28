/**
 *  \file     j721e/usb_wrapper.c
 *
 *  \brief    This file contains APIs for manipulating the SOC specific wrapper.
 *            As the name suggests this file implements the USB wrapper as
 *            impemented by J7.
 *
 *  \copyright Copyright (C) 2019 Texas Instruments Incorporated -
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
#include "hw_usb.h"

#include "usb_wrapper.h"
#include "usb_drv.h"
#include "debug.h"
#include <ti/drv/usb/src/cdn/usb_cdn_dcd.h>

#include <ti/csl/csl_serdes.h>
#include <ti/csl/csl_serdes_usb.h>


/* USB uses Sierra SERDES */
#include <ti/csl/src/ip/serdes_cd/V0/cslr_wiz16b4m4cs.h>

/* ========================================================================== */
/*                 extern Function Prototypes                                 */
/* ========================================================================== */
extern void USBHCDTerm(uint32_t ulIndex);

extern USB_Config USB_config[3];

/* ========================================================================== */
/*                 Prototypes                                                 */
/* ========================================================================== */
int32_t usbClockSSCfg(uint32_t portNumber);

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

#ifndef USE_CDN_XHCI
void usbHostIntrHandler(void* drvData)
{
    /* we don't yet use interrupt in host mode with TI xHCI driver .*/
}
#endif

/* turn on the USB2 PHY clock and do its settings
   the clock freq needs to be updated while the USBSS is in reset */
void usbPhyOn(uint32_t portNumber, uint32_t invertPolarity)
{
    uint32_t usbCmnRegs = 0;
    USB_Config* usbConfig = &USB_config[portNumber];
    uint32_t pllRefSel = 0;
    uint32_t validPll = 1;

    if (portNumber == 0)
    {
        usbCmnRegs = CSL_USB0_MMR_MMRVBP_USBSS_CMN_BASE;
    }
    else
    {
        usbCmnRegs = CSL_USB1_MMR_MMRVBP_USBSS_CMN_BASE;
    }

    /*
     * assert reset to the USB controller to program the necessary bits
     * 0 to reset. 1 to release reset.
     */
    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_PWRUP_RST_N, 0);


    /* setting VBUS_SEL for external divider - J7 EVM has a voltage divider
     * for VBUS. Assuming everyone uses EVM has reference design.
     * If not, we can disable this setting by setting the USB config */
    if (usbConfig->vbusDivider == 1)
    {
        HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_STATIC_CONFIG,
                  CSL_USB3P0SS_CMN_STATIC_CONFIG_VBUS_SEL, 0x1);
    }

    /* setting PHY ref clock */
    switch (usbConfig->usb2PhyRefClkFreq)
    {
        case  9600: pllRefSel = 0x0; break;
        case 10000: pllRefSel = 0x1; break;
        case 12000: pllRefSel = 0x2; break;
        case 19200: pllRefSel = 0x3; break;
        case 20000: pllRefSel = 0x4; break;
        case 24000: pllRefSel = 0x5; break;
        case 25000: pllRefSel = 0x6; break;
        case 26000: pllRefSel = 0x7; break;
        case 38400: pllRefSel = 0x8; break;
        case 40000: pllRefSel = 0x9; break;
        case 48000: pllRefSel = 0xA; break;
        case 50000: pllRefSel = 0xB; break;
        case 52000: pllRefSel = 0xC; break;
        default:
            validPll = 0;
            break;
    }

    if (validPll)
    {
        HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_STATIC_CONFIG,
                  CSL_USB3P0SS_CMN_STATIC_CONFIG_PLL_REF_SEL, pllRefSel);
    }
    else
    {
        debug_printf("wrong pll selection\n");
    }

    /* configure the DM/DP polarity */
    if (invertPolarity <= 1)
    {
        HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_STATIC_CONFIG,
               CSL_USB3P0SS_CMN_STATIC_CONFIG_LANE_REVERSE, invertPolarity);
    }

    /* release reset */
    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_PWRUP_RST_N, 1);

}/* usbPhyOn */



/*
 * Setting up the USB wrapper for USB mode  (host or device mode)
 * on a controller(portNumber)
 * Also need to set the USB2.0 or USB3.0 mode depending on config
 *
 */
#define MODESTRAP_SEL_HOST_MODE     (1)
#define MODESTRAP_SEL_DEVICE_MODE   (2)
#define MODESTRAP_USES_MODE_S_SEL   (1)

static int32_t usb3_wrapper_config(uint32_t portNumber, uint32_t isHostMode)
{
    uint32_t usbCmnRegs = 0;
    uint32_t modeStrap = 0;
    USB_Config* usbConfig = &USB_config[portNumber];

    if (portNumber == 0)
    {
        usbCmnRegs = CSL_USB0_MMR_MMRVBP_USBSS_CMN_BASE;
    }
    else
    {
        usbCmnRegs = CSL_USB1_MMR_MMRVBP_USBSS_CMN_BASE;
    }

    /*
     * assert reset to the USB controller to program the necessary bits
     * 0 to reset. 1 to release reset.
     */
    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_PWRUP_RST_N, 0);

    /* set the USB controller to host or device mode */
    if (isHostMode == 1)
    {
       modeStrap =  MODESTRAP_SEL_HOST_MODE;
    }
    else
    {
       modeStrap =  MODESTRAP_SEL_DEVICE_MODE;
    }

    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_MODESTRAP, modeStrap);

    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_MODESTRAP_SEL,
                  MODESTRAP_USES_MODE_S_SEL);

    /* set to USB2.0 only if USB3.0 is not enabled. i.e SERDES is not used */
    if (usbConfig->usb30Enabled == FALSE) /* user asks for USB2.0 only */
    {
        HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_USB2_ONLY_MODE, 0x1);
    }

    /* release reset */
    HW_WR_FIELD32(usbCmnRegs + CSL_USB3P0SS_CMN_USB3P0SS_W1,
                  CSL_USB3P0SS_CMN_USB3P0SS_W1_PWRUP_RST_N, 1);

    return 0;
}


/* setting up USB clocks for USB instance #portNumber
 * which is either 0 or 1
 *
 * EVM has HFOSC0 connected to 19.2MHz crystal on EVM
 * and this matches with the allowed frequency USB PHY clock. So we will set the
 * USB PHY to use this HFOSC0
 *
 */
#define USB_CLK_SEL_HFOSC0_CLKOUT   (0x0)
#define USB_CLK_SEL_HFOSC1_CLKOUT   (0x1)
#define USB_MAIN_PLL3_HSDIV4_CLKOUT (0x2)
#define USB_MAIN_PLL2_HSDIV4_CLKOUT (0x3)

void usbClockCfg(uint32_t portNumber)
{
    uint32_t mmrUsbClkSel;
    USB_Config* usbConfig = &USB_config[portNumber];

    if (portNumber == 0)
    {
        mmrUsbClkSel  = CSL_MAIN_CTRL_MMR_CFG0_USB0_CLKSEL;
    }
    else
    {
        mmrUsbClkSel  = CSL_MAIN_CTRL_MMR_CFG0_USB1_CLKSEL;
    }

    /* mux for usb2 ref clock */
    /* #define CSL_FINS(reg, PER_REG_FIELD, val) */
    CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + mmrUsbClkSel),
                           MAIN_CTRL_MMR_CFG0_USB0_CLKSEL_REFCLK_SEL,
                           USB_CLK_SEL_HFOSC0_CLKOUT); /* HF_OSC0 used */

    if (usbConfig->usb30Enabled)
    {
        if (usbClockSSCfg(portNumber) != 0)
        {
            debug_printf("Error when enabling Super Speed\n");
        }
    }

} /* usbClockCfg */


#define SERDES_NUMS   4
/*
 * Mapping the SERDES ID that can be used with the USB
 * USB uses SIERRA SERDES
 */
static CSL_SerdesInstance usbIdSerdesIdMap[SERDES_NUMS] = {CSL_SIERRA_SERDES0,
                                                           CSL_SIERRA_SERDES1,
                                                           CSL_SIERRA_SERDES2,
                                                           CSL_SIERRA_SERDES3};

/* mapping the Serdes ID to its base address */
static uint32_t usbSerdesBaseMap[SERDES_NUMS] = {CSL_SERDES_16G0_BASE,
                                                 CSL_SERDES_16G1_BASE,
                                                 CSL_SERDES_16G2_BASE,
                                                 CSL_SERDES_16G3_BASE};


/* setting up clock for USB3.0 Super speed
 * return 0 if success.
 */
int32_t usbClockSSCfg(uint32_t portNumber)
{
    int32_t             rc = 0;
    int32_t             i;

    USB_Config*   usbConfig = &USB_config[portNumber];

    CSL_SerdesLaneEnableParams serdesLaneEnableParams;
    CSL_SerdesLaneEnableStatus laneRetVal = CSL_SERDES_LANE_ENABLE_NO_ERR;

    /* Unlock Lock1 Kick Registers - IP control / status regs */
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0) = KICK0;
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1) = KICK1;

    /* Unlock Lock2 Kick Registers - clock control / status regs */
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK0) = KICK0;
    *(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK1) = KICK1;

    /* find which SERDES instance we need to use and validate it
     * USBSS#0 can use SERDES#0 or SERDES#3
     * USBSS#1 can use SERDES#1 or SERDES#2
     */
    if ((portNumber == 0) && (!((usbConfig->serdesId == 0) || (usbConfig->serdesId == 3))))
    {
        rc = E_FAIL;
    }
    if ((portNumber == 1) && (!((usbConfig->serdesId == 1) || (usbConfig->serdesId == 2))))
    {
        rc = E_FAIL;
    }

    if (portNumber == 0)
    {
        if (usbConfig->serdesId == 3)
        {
            CSL_FINS(*(uint32_t *)(uintptr_t)
                    (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_USB0_CTRL),
                    MAIN_CTRL_MMR_CFG0_USB0_CTRL_SERDES_SEL, 0x1);

            CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES3_CLKSEL),
                    MAIN_CTRL_MMR_CFG0_SERDES3_CLKSEL_CORE_REFCLK_SEL,
                    USB_MAIN_PLL2_HSDIV4_CLKOUT); /* 100MHz */

            CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES3_CLK1SEL),
                    MAIN_CTRL_MMR_CFG0_SERDES3_CLKSEL_CORE_REFCLK_SEL,
                    USB_MAIN_PLL2_HSDIV4_CLKOUT); /* 100MHz */

            CSL_FINSR(*(volatile uint32_t *)(uintptr_t)
                      (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES3_LN0_CTRL),1,0,0x2);

            CSL_FINSR(*(volatile uint32_t *)(uintptr_t)
                      (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES3_LN1_CTRL),1,0,0x2);
        }
        else
        {
            /* serdesId == 0 */
            CSL_FINS(*(uint32_t *)(uintptr_t)
                    (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_USB0_CTRL),
                    MAIN_CTRL_MMR_CFG0_USB0_CTRL_SERDES_SEL, 0x0);

            CSL_FINS(*(uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_CLKSEL),
                    MAIN_CTRL_MMR_CFG0_SERDES0_CLKSEL_CORE_REFCLK_SEL,
                    USB_MAIN_PLL2_HSDIV4_CLKOUT); /* 100MHz */

            CSL_FINSR(*(volatile uint32_t *)(uintptr_t)
                      (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_LN0_CTRL),1,0,0x2);

            CSL_FINSR(*(volatile uint32_t *)(uintptr_t)
                      (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_LN1_CTRL),1,0,0x2);
        }
    }

    if (rc != E_FAIL)
    {
        memset(&serdesLaneEnableParams, 0, sizeof(serdesLaneEnableParams));

        serdesLaneEnableParams.serdesInstance = usbIdSerdesIdMap[usbConfig->serdesId];
        serdesLaneEnableParams.baseAddr       = usbSerdesBaseMap[usbConfig->serdesId];
        serdesLaneEnableParams.refClock       = CSL_SERDES_REF_CLOCK_100M;
        serdesLaneEnableParams.refClkSrc      = CSL_SERDES_REF_CLOCK_INT;
        serdesLaneEnableParams.linkRate       = CSL_SERDES_LINK_RATE_5G;
        serdesLaneEnableParams.numLanes       = 2; /* 2 lanes for USB-C laneswapping */
        serdesLaneEnableParams.laneMask       = 3; /* 2 lanes */
        serdesLaneEnableParams.phyType        = CSL_SERDES_PHY_TYPE_USB;
        /*serdesLaneEnableParams.pcieGenType    = CSL_SERDES_PCIE_GEN3; */
        serdesLaneEnableParams.operatingMode  = CSL_SERDES_FUNCTIONAL_MODE;
        serdesLaneEnableParams.phyInstanceNum = portNumber; /* USB controller ID */
        serdesLaneEnableParams.forceAttBoost  = CSL_SERDES_FORCE_ATT_BOOST_DISABLED;
        serdesLaneEnableParams.SSC_mode       = CSL_SERDES_NO_SSC; /*CSL_SERDES_EXTERNAL_SSC*/;
        serdesLaneEnableParams.refClkOut      = CSL_SERDES_REFCLK_OUT_DIS;

        for(i=0; i< serdesLaneEnableParams.numLanes; i++)
        {
            serdesLaneEnableParams.laneCtrlRate[i] = CSL_SERDES_LANE_FULL_RATE;
            serdesLaneEnableParams.loopbackMode[i] = CSL_SERDES_LOOPBACK_DISABLED;
        }


        /* selects the appropriate clocks for all serdes based on the protocol chosen */
        rc = CSL_serdesRefclkSel(CSL_CTRL_MMR0_CFG0_BASE,
                                 serdesLaneEnableParams.baseAddr,
                                 serdesLaneEnableParams.refClock,
                                 serdesLaneEnableParams.refClkSrc,
                                 serdesLaneEnableParams.serdesInstance,
                                 serdesLaneEnableParams.phyType);

        if (rc != CSL_SERDES_NO_ERR)
        {
            debug_printf("CSL_serdesRefclkSel failed!\n");
        }
    }


    if (rc == CSL_SERDES_NO_ERR)
    {
        /* load USB serdes config */
        rc = CSL_serdesUSBInit(&serdesLaneEnableParams);
    }

    if (rc == CSL_SERDES_NO_ERR)
    {
        /* Common Lane Enable API for lane enable, pll enable etc */
        laneRetVal = CSL_serdesLaneEnable(&serdesLaneEnableParams);

        if (laneRetVal == CSL_SERDES_LANE_ENABLE_NO_ERR)
        {
            rc = 0;
        }
        else
        {
            debug_printf("CSL_serdesRefclkSel failed!\n");
            rc = laneRetVal;
        }
    }

    return rc;
}

/* Do USB-C lane swap when the USB-C cable is flipped */
int32_t usbcLaneSwap(uint32_t portNumber)
{
    int32_t             rc = 0;
    uint32_t            serdesBase;

    USB_Config*   usbConfig = &USB_config[portNumber];

    /* find which SERDES instance we need to use and validate it
     * USBSS#0 can use SERDES#0 or SERDES#3
     * USBSS#1 can use SERDES#1 or SERDES#2
     */
    if ((portNumber == 0) &&
        (!((usbConfig->serdesId == 0) || (usbConfig->serdesId == 3))))
    {
        rc = E_FAIL;
    }
    if ((portNumber == 1) &&
        (!((usbConfig->serdesId == 1) || (usbConfig->serdesId == 2))))
    {
        rc = E_FAIL;
    }

    if (rc != E_FAIL)
    {
        /* now that we have validated to find the proper SERDES instance we need
         * to work on, we perform the laneswap procedure by reset the PHY then
         * program the swap bit */

        /* find the SERDES base */
        serdesBase = usbSerdesBaseMap[usbConfig->serdesId];

        /* assert SERDES PHY reset - write 0 to reset */
        /* all SERDES registers are SIERRA SERDES (CS) */
        HW_WR_FIELD32(serdesBase + CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_RST,
                CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_RST_PHY_RESET_N, 0);

        /* write the swap bit */
        HW_WR_FIELD32(serdesBase + CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_TYPEC,
                      CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_TYPEC_LN10_SWAP, 0x1);

        /* clear the PHY reset condition */
        HW_WR_FIELD32(serdesBase + CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_RST,
                CSL_WIZ16B4M4CS_WIZ_CONFIG_SERDES_RST_PHY_RESET_N, 1);
    }

    return rc;
}

/* Enable all the interrupts for wrapper */
void usbCdncdEnableWrapperIntr(uint32_t baseAddr)
{
    /* No need to set anything on the wrapper to
     * Enable USB main interrupts on J7
     *
     * CDN core interrupts are wired directly to GIC or Int Router
     */

}


/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup */
void usbCdnDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup */
void usbCdnDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    /* Call device interrupt handler */
    USBCdnDcdCoreIntrHandler((usbCdnDcdDevice_t *)pUserParam);
}


void usb_wrapper_setup_device_mode(uint32_t portNum)
{
    uint32_t isHostMode = 0;    /* device mode */

    usb3_wrapper_config(portNum, isHostMode);
}


void usb_wrapper_setup_host_mode(uint32_t portNum)
{
    uint32_t isHostMode = 1;    /* host mode */

    usb3_wrapper_config(portNum, isHostMode);
}


/*Setting the USB controller for static Host mode operation */
void usb_controller_setup_host_mode(uint32_t portNum)
{
    /*Setting the XHCI3 controller for Host mode operation */
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

