/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
 * 
 * 
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

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/src/v5/emac_mdio.h>

extern EMAC_MCB_V5_T      emac_mcb;

/*
 *  Note that NWAYSTART falls through to NWAYWAIT which falls through
 *  to LINKWAIT. The timeout is not reset progressing from one state
 *  to the next, so the system has 5 seconds total to find a link.
 */




static void EMAC_mdioInitStateMachine( EMAC_MDIO_DEVICE_T *pd );


/*
 *  ======== EMAC_mdioOpen ========
 *  Opens the MDIO peripheral and initialize the MDIO state machine
 */
void EMAC_mdioOpen(uint32_t portNum, int instNum, uint32_t phyAddr, emacMdioHandle hMDIO)
{
    EMAC_MDIO_DEVICE_T     *pMdioDev = (EMAC_MDIO_DEVICE_T *)hMDIO;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: phy addr: %d ENTER",portNum, phyAddr);
    pMdioDev->regId  = instNum;
    pMdioDev->phyAddr = phyAddr;
    pMdioDev->modeFlags = EMAC_MDIO_MODEFLG_SPECPHYADDR;
    /* Setup the MDIO state machine */
    EMAC_mdioInitStateMachine(pMdioDev);
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",portNum);
}

/*
 *  ======== EMAC_mdioClose ========
 *  Close the MDIO peripheral anddisable further operation.
 */
void EMAC_mdioClose( emacMdioHandle hMDIO )
{

    EMAC_MDIO_DEVICE_T *pd = (EMAC_MDIO_DEVICE_T *)hMDIO;
    CSL_MdioRegs *pBaseAddr = (CSL_MdioRegs*)pd->mdioBaseAddr;

    if (CSL_MDIO_isPhyAlive(pBaseAddr,pd->phyAddr))
    {
        CSL_MDIO_phyRegWrite2(pBaseAddr, pd->phyAddr, 0,EMAC_PHYREG_CONTROL,
                                                        EMAC_PHYREG_CONTROL_ISOLATE |  EMAC_PHYREG_CONTROL_POWERDOWN);
    }
}

/*
 *  ======== EMAC_mdioGetStatus ========
 * Get status specified  with PHY address
 */
void EMAC_mdioGetStatus( emacMdioHandle hMDIO, uint32_t *pPhy, uint32_t *pLinkStatus )
{
    EMAC_MDIO_DEVICE_T *pd = (EMAC_MDIO_DEVICE_T *)hMDIO;

    if(pPhy)
    {
        *pPhy = pd->phyAddr;
    }
    if(pLinkStatus)
    {
        *pLinkStatus = pd->linkStatus;
    }
}

void EMAC_mdioCheckResults(CSL_MdioRegs* pBaseAddr, EMAC_MDIO_DEVICE_T* pd)
{
    uint16_t      tmp1;

    CSL_MDIO_phyRegRead2(pBaseAddr, 0,pd->phyAddr, EMAC_PHYREG_PHYSTS, &tmp1);
    if((tmp1 & EMAC_PHYREG_PHYSTS_FD1000) == EMAC_PHYREG_PHYSTS_FD1000 )
        pd->linkStatus = EMAC_MDIO_LINKSTATUS_FD1000;
    else if((tmp1 & EMAC_PHYREG_PHYSTS_FD100) == EMAC_PHYREG_PHYSTS_FD100 )
        pd->linkStatus = EMAC_MDIO_LINKSTATUS_FD100;
    else if((tmp1 & EMAC_PHYREG_PHYSTS_HD100) == EMAC_PHYREG_PHYSTS_HD100 )
        pd->linkStatus = EMAC_MDIO_LINKSTATUS_HD100;
    else if((tmp1 & EMAC_PHYREG_PHYSTS_FD10) == EMAC_PHYREG_PHYSTS_FD10 )
        pd->linkStatus = EMAC_MDIO_LINKSTATUS_FD10;
    else if((tmp1 & EMAC_PHYREG_PHYSTS_HD10) == EMAC_PHYREG_PHYSTS_HD10 )
        pd->linkStatus = EMAC_MDIO_LINKSTATUS_HD10;
}

/*
 *  ======== EMAC_mdiocheckForLinkUp ========
 */
void EMAC_mdiocheckForLinkUp(CSL_mdioHandle  mdioHandle, EMAC_MDIO_DEVICE_T *pd, uint32_t *pRetVal)
{
    CSL_MdioRegs *pBaseAddr =    (CSL_MdioRegs*)pd->mdioBaseAddr;

    if (CSL_MDIO_isPhyLinked(mdioHandle, pd->phyAddr))
    {
        /* We can now check the negotiation results */
        EMAC_mdioCheckResults(pBaseAddr, pd);
        /* Clear the link change flag so we can detect a "re-link" later */
        CSL_MDIO_clearUnmaskedLinkStatusChangeInt(mdioHandle, pd->regId);
        /* Setup our linked state */
        pd->phyState   = EMAC_PHYSTATE_LINKED;
        *pRetVal = EMAC_MDIO_EVENT_LINKUP;
    }
    else
    {
        pd->phyState = EMAC_PHYSTATE_LINKWAIT;
    }
}

/*
 *  ======== EMAC_mdioTimerTick ========
 */
uint32_t EMAC_mdioTimerTick(emacMdioHandle hMDIO )
{
    EMAC_MDIO_DEVICE_T *pd = (EMAC_MDIO_DEVICE_T *)hMDIO;

    volatile uint32_t      temp;
    uint32_t        retVal = EMAC_MDIO_EVENT_NOCHANGE;
    CSL_MdioRegs *pBaseAddr =    (CSL_MdioRegs*)pd->mdioBaseAddr;
    CSL_mdioHandle  mdioHandle = (CSL_mdioHandle)pBaseAddr;
    /*
     * If we are linked, we just check to see if we lost link. Otherwise;
     * we keep treking through our state machine.
     */
    if( pd->phyState == EMAC_PHYSTATE_LINKED)
    {
        /*
         * Here we check for a "link-change" status indication or a link
         * down indication.
         */
        temp = CSL_MDIO_isUnmaskedLinkStatusChangeIntSet(mdioHandle, pd->regId);
        if( temp || !(CSL_MDIO_isPhyLinked(mdioHandle, pd->phyAddr)))
        {
            /** Link is down */
            pd->linkStatus = EMAC_MDIO_LINKSTATUS_NOLINK;
            retVal = EMAC_MDIO_EVENT_LINKDOWN;
            pd->phyState = EMAC_PHYSTATE_LINKWAIT;
        }
    }
    /*
     * If running in a non-linked state, execute the next
     * state of the state machine.
     */
    if( pd->phyState != EMAC_PHYSTATE_LINKED )
    {
        /* Bump the time counter */

        /* Process differently based on state */
        switch( pd->phyState )
        {
        case EMAC_PHYSTATE_MDIOINIT:
            if (CSL_MDIO_isPhyAlive(mdioHandle,pd->phyAddr))
            {
                EMAC_mdiocheckForLinkUp(mdioHandle, pd, &retVal);
            }
            break;
        case EMAC_PHYSTATE_LINKWAIT:
            EMAC_mdiocheckForLinkUp(mdioHandle, pd, &retVal);
            break;
        }
    }
    return( retVal );
}

/*
 *  ======== EMAC_mdioInitStateMachine ========
 *  Init MDIO state machine.
 */
static void EMAC_mdioInitStateMachine( EMAC_MDIO_DEVICE_T *pd )
{
    /* Setup the state machine defaults */
    pd->phyState      = EMAC_PHYSTATE_MDIOINIT;
    pd->linkStatus    = EMAC_MDIO_LINKSTATUS_NOLINK;
}



