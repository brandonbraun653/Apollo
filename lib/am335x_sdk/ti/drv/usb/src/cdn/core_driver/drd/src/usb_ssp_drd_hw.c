/******************************************************************************
 *
 * Copyright (C) 2012-2019 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#include "fsm_usb.h"

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"
#include "usb_ssp_drd_hw.h"
#include "usb_ssp_drd_regs.h"
#include "usb_ssp_drd_regs_macros.h"

#include <cps_drv.h>
#include <cdn_log.h>

#if !(defined USB_SSP_DRD_ID_PULLUP_DELAY)
#define USB_SSP_DRD_ID_PULLUP_DELAY 50000000U
#endif

uint32_t readDID(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    uint32_t didVal = 0U;
    /* Read register. */
    regVal = CPS_UncachedRead32(&(regsBase->CDNS_DID));
    /* Extract DID number. */
    didVal = CPS_FLD_READ(USB__CDNS_DID, DID, regVal);
    return didVal;
}

uint32_t readRID(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    uint32_t ridVal = 0U;
    /* Read register. */
    regVal = CPS_UncachedRead32(&(regsBase->CDNS_RID));
    /* Extract RID number. */
    ridVal = CPS_FLD_READ(USB__CDNS_RID, CDNS_RID, regVal);
    return ridVal;
}

/* This function transforms DRD Strap Mode represented with unsigned
 * integer to DRD Strap Mode represented with USB_SSP_DRD_Mode
 * type. */
static USB_SSP_DRD_Mode getDrdMode(uint32_t mode)
{
    USB_SSP_DRD_Mode drdMode;

    /* Transformation algorithm. */
    switch (mode) {
        /* Strapped to DRD Mode */
    case 0: {
        drdMode = USB_SSP_DRD_DRD;
        break;
    }
        /* Strapped to Host mode */
    case 1: {
        drdMode = USB_SSP_DRD_HOST;
        break;
    }
        /* Strapped to Device mode */
    case 2: {
        drdMode = USB_SSP_DRD_DEV;
        break;
    }
        /* Default Strap mode */
    default:
        drdMode = USB_SSP_DRD_ILLEGAL;
        break;
    }
    return drdMode;
}

USB_SSP_DRD_Mode readStrapMode(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set variable value to default. */
    USB_SSP_DRD_Mode strapMode = USB_SSP_DRD_DRD;
    /* Read register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGSTS));
    /* Extract strap mode. */
    strapMode = getDrdMode(CPS_FLD_READ(USB__OTGSTS, STRAP, regVal));
    return strapMode;
}

bool checkIfControllerIsReady(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set ready variable to default. */
    uint32_t notReady = 1U;
    bool ready = false;
    /* Read register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGSTS));
    /* Extract info if controller is ready. */
    notReady = CPS_FLD_READ(USB__OTGSTS, OTG_NRDY, regVal);
    /* Controller returns true if controller is not ready. */
    if (0U == notReady) {
        ready = 1U;
    }
    return ready;
}

void readIdVbus(USB_SspDrdRegs* regsBase, uint32_t* idVal, uint32_t* vBus)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Read register value.*/
    regVal = CPS_UncachedRead32(&(regsBase->OTGSTS));
    /* Extract value of ID. */
    *idVal = CPS_FLD_READ(USB__OTGSTS, ID_VALUE, regVal);
    /* Extract value of VBUS. */
    *vBus = CPS_FLD_READ(USB__OTGSTS, VBUS_VALID, regVal);
}

void enableAllInterrupts(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Write Interrupt Enable register. */
    CPS_UncachedWrite32(&(regsBase->OTGIEN), USB_SSP_DRD_ALL_INTERRUPTS);
}

void clearAllInterrupts(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Set every bit in Interrupt Vector register to clear
     * interrupts. */
    CPS_UncachedWrite32(&(regsBase->OTGIVECT), USB_SSP_DRD_ALL_INTERRUPTS);
}

uint32_t readInterruptVector(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Read value of Interrupt Vector register to see which
     * interrupt has occured. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGIVECT));
    return regVal;
}

USB_SSP_DRD_Mode readDrdMode(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    USB_SSP_DRD_Mode drdMode = USB_SSP_DRD_DRD;
    /* Read whole value of OTG State register for extraction of DRD Mode. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGSTATE));
    /* Extract the value of drd_mode */
    drdMode = getDrdMode(CPS_FLD_READ(USB__OTGSTATE, APB_AXI_CTRL, regVal));
    return drdMode;
}

uint32_t enableIdPullup(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t retVal = CDN_EOK;
    uint32_t regVal = 0U;
    uint32_t idPullup = 0U;

    /* Read current value of Port Override register. */
    regVal = CPS_UncachedRead32(&(regsBase->OVERRIDE));
    /* Set ID pullup in the value of Port Override register. */
    regVal = CPS_FLD_SET(USB__OVERRIDE, IDPULLUP, regVal);
    /* Write Port Override register with ID pullup bit set. */
    CPS_UncachedWrite32(&(regsBase->OVERRIDE), regVal);

    /* Controller needs some time before ID pullup is valid. */
    CPS_DelayNs(USB_SSP_DRD_ID_PULLUP_DELAY);

    /* Test if ID pullup bit in Port Override register is set. */
    regVal = 0;
    /* Read whole register value. */
    regVal = CPS_UncachedRead32(&(regsBase->OVERRIDE));
    /* Extract ID pullup bit value. */
    idPullup = CPS_FLD_READ(USB__OVERRIDE, IDPULLUP, regVal);

    if (1U == idPullup) {
        /* ID pullup is set. */
        retVal = CDN_EOK;
    } else {
        /* ID pullup is not set. */
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
        retVal = CDN_EPROTO;
    }

    return retVal;
}

void enableHwAHost(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set only Host Bus Request bit in Command register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGCMD));
    regVal = CPS_FLD_SET(USB__OTGCMD, HOST_BUS_REQ, regVal);
    regVal = CPS_FLD_SET(USB__OTGCMD, OTG_DIS, regVal);
    /* Write register value. */
    CPS_UncachedWrite32(&(regsBase->OTGCMD), regVal);
}

void enableBPeripheral(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set only Dev Bus Request bit in Command register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGCMD));
    regVal = CPS_FLD_SET(USB__OTGCMD, DEV_BUS_REQ, regVal);
    regVal = CPS_FLD_SET(USB__OTGCMD, OTG_DIS, regVal);
    /* Write register value. */
    CPS_UncachedWrite32(&(regsBase->OTGCMD), regVal);
}

void disableHostDevice(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set only Host and Dev Bus Drop bits in Command register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGCMD));
    regVal = CPS_FLD_SET(USB__OTGCMD, HOST_BUS_DROP, regVal);
    regVal = CPS_FLD_SET(USB__OTGCMD, DEV_BUS_DROP, regVal);
    regVal = CPS_FLD_SET(USB__OTGCMD, DIS_VBUS_DROP, regVal);
    /* Write register value. */
    CPS_UncachedWrite32(&(regsBase->OTGCMD), regVal);
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
}

void enableFastSim(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set only Host and Dev Bus Drop bits in Command register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGCMD));
    regVal = CPS_FLD_SET(USB__OTGSIMULATE, OTG_CFG_FAST_SIMS, regVal);
    /* Write register value. */
    CPS_UncachedWrite32(&(regsBase->OTGSIMULATE), regVal);
}

void switchOtg2ToPeripheral(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t regVal = 0U;
    /* Set only OTG USB 2 Peripheral bit in Command register. */
    regVal = CPS_UncachedRead32(&(regsBase->OTGCMD));
    regVal = CPS_FLD_SET(USB__OTGCMD,
                         OTG2_SWITCH_TO_PERIPH,
                         regVal);
    /* Write register value. */
    CPS_UncachedWrite32(&(regsBase->OTGCMD), regVal);
}
