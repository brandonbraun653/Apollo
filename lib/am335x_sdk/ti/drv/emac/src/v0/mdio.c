/*
 * Copyright (C) 2002-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/** ============================================================================
 *   @file  mdio.c
 *
 *   PATH:  \$(PDK_INSTALL_PATH)\ti\drv\emac\src\v0
 *
 *   @brief  MDIO Implementation on DSP side
 *
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  25-Aug-03 xxx Modified to introduce ~(100 to 200) ms delay in PHY reset.
 *                Also checks ACK value on reading back PHY reset status
 *  10-Mar-06 xxx Ported to TCI6488
 * =============================================================================
 */

#include <ti/csl/csl_mdio.h>
#include "inc/emac_loc.h"

/**
 *  \brief  Tick counts for timeout of each state
 *
 *  Note that NWAYSTART falls through to NWAYWAIT which falls through
 *  to LINKWAIT. The timeout is not reset progressing from one state
 *  to the next, so the system has 5 seconds total to find a link.
 */
static uint32_t PhyStateTimeout[] = {
                                2,    /**< PHYSTATE_MDIOINIT   - min-delay  */
                                6,    /**< PHYSTATE_RESET      - 0.5 sec max*/
                                41,   /**< PHYSTATE_NWAYSTART  - 4 seconds  */
                                41,   /**< PHYSTATE_NWAYWAIT   - 4 seconds  */
                                51,   /**< PHYSTATE_LINKWAIT   - 5 seconds  */
                                0     /**< PHYSTATE_LINKED     - no timeout */
                                };

static void MDIO_initStateMachine( MDIO_Device *pd );
static uint32_t MDIO_initContinue( MDIO_Device *pd );

/**< Curent selection of MAC */
static uint32_t		macsel;

void PHYREG_read(uint32_t id, uint32_t regadr, uint32_t phyadr )
{
    if (id==1) 
        PHYREG1_read(regadr, phyadr);
    else
        PHYREG0_read(regadr, phyadr);
}

void PHYREG_write(uint32_t id, uint32_t regadr, uint32_t phyadr, Uint16 data )
{
    if (id==1) 
        PHYREG1_write(regadr, phyadr, data);
    else
        PHYREG0_write(regadr, phyadr, data);
}

void PHYREG_wait(uint32_t id)
{
    if (id==1) 
        PHYREG1_wait();
    else
        PHYREG0_wait();
}

void PHYREG_waitResults(uint32_t id, Uint16* results)
{
    if (id==1)
    { 
        PHYREG1_waitResults( *results );
    }
    else
    {
        PHYREG0_waitResults( *results );
    }
}

void PHYREG_waitResultsAck(uint32_t id, Uint16* results, Uint16* ack)
{
    if (id==1)
    { 
        PHYREG1_waitResultsAck( *results, *ack );
    }
    else
    {
        PHYREG0_waitResultsAck( *results, *ack );
    }
}

/* ============================================================================
 *  @n@b MDIO_initStateMachine()
 *
 *  @b Description
 *  @n Internal function to initialize the state machine. It is referred to
 *     often in the code as it is called in case of a PHY error
 *
 *  @b Arguments
 *  @verbatim
        pd  pointer to MDIO device object
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  MDIO_Device Structure members are initialized means that MDIO state
 *      machine default values are set.
 *
 *  @b  Example:
 *  @verbatim
        MDIO_Device localDev;

        MDIO_initStateMachine( &localDev );
    @endverbatim
 * ============================================================================
 */
static void MDIO_initStateMachine( MDIO_Device *pd )
{
    /* Setup the state machine defaults */
    /* When user is not specifying a PHY address for monitoring, always start
       from PHY address 0. In this scenario, MDIO always monitors the first PHY
       found from address 0-31. Use the first set of MDIO User Access and PHY 
       Select Registers: USERACCESS0 and USERPHYSEL0 */
    if ( !(pd->ModeFlags & MDIO_MODEFLG_SPECPHYADDR))
    {
        pd->phyAddr = 0;                  /* The next PHY to try  */
        pd->regId   = 0;
    }
    pd->phyState      = PHYSTATE_MDIOINIT;  /* PHY State            */
    pd->phyStateTicks = 0;                  /* Ticks elapsed        */
    pd->LinkStatus    = MDIO_LINKSTATUS_NOLINK;
}

/** ============================================================================
 *  @n@b MDIO_open()
 *
 *  @b Description
 *  @n Opens the MDIO peripheral and initialize the MDIO state machine
 *
 *     It is assumed that the MDIO module is reset prior to calling this
 *     function.
 *
 *  @b Arguments
 *  @verbatim
        instNum         Instance number when user is specifying a PHY address for monitoring
                        i.e., MDIO_MODEFLG_SPECPHYADDR mode flag is set. 
                        It is hard-coded as 0 when MDIO_MODEFLG_SPECPHYADDR is not set.
        mdioModeFlags   Mode flags 
        phyAddr         PHY address user specifies for monitoring. It is bypassed when
                        MDIO_MODEFLG_SPECPHYADDR mode flag is not set.
        hMDIO           Handle to the MDIO device which needs to be initialized.
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n     MDIO_ERROR_INVALID   - A calling parameter is invalid

 *  <b> Pre Condition </b>
 *  @n  The MDIO module must be reset prior to calling this function.
 *
 *  <b> Post Condition </b>
 *  @n  Opens the MDIO peripheral and initialize the MDIO state machine.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK;
        uint32_t         mdioPhyAddr = 0;

        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);
    @endverbatim
 * ============================================================================
 */
uint32_t MDIO_open( int instNum, uint32_t mdioModeFlags, uint32_t phyAddr, Handle hMDIO,uint32_t macSel)
{
    MDIO_Device*        pMdioDev;

    if (!hMDIO)
        return (MDIO_ERROR_INVALID);

    pMdioDev = (MDIO_Device *)hMDIO;

	/* Find out what interface we are working with */
      macsel = macSel;
    /* Get the mode flags from the user - clear our reserved flag */
    pMdioDev->ModeFlags = mdioModeFlags & ~MDIO_MODEFLG_NWAYACTIVE;

    /* When user is specifying PHY address to be monitored, check and record the PHY address.
       In this situation, MDIO can monitor two PHY addresses at the same time. Select the set
       of MDIO User Access and PHY Select Registers according to the instance number        */
    if ( pMdioDev->ModeFlags & MDIO_MODEFLG_SPECPHYADDR)
    {
        pMdioDev->regId  = instNum;
        if(phyAddr < 32)
            pMdioDev->phyAddr = phyAddr;
        else
            return(MDIO_ERROR_INVALID);
    }

    /* Setup the MDIO state machine */
    MDIO_initStateMachine(pMdioDev);

    /* Enable MDIO and setup divider */
    MDIO_REGS->CONTROL = CSL_FMKT(MDIO_CONTROL_ENABLE,YES) |
                         CSL_FMK(MDIO_CONTROL_CLKDIV,VBUSCLK) ;

    /* We're done for now - all the rest is done via MDIO_event() */
    /* Return Success */
    return( 0 );
}


/** ============================================================================
 *  @n@b MDIO_close()
 *
 *  @b Description
 *  @n Close the  MDIO peripheral and disable further operation.
 *
 *  @b Arguments
 *  @verbatim
        hMDIO   handle to the opened MDIO instance
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset and opened before calling this function.
 *
 *  <b> Post Condition </b>
 *  @n  MDIO module is closed. No further operations are possible.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000      0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_close( &mdioDev );
    @endverbatim
 * ============================================================================
 */
void MDIO_close( Handle hMDIO )
{
    uint32_t         ltmp1;
    uint32_t           i;

    MDIO_Device *pd = (MDIO_Device *)hMDIO;

    /*
     * We really don't care what state anything is in at this point,
     * but to be safe, we'll isolate all the PHY devices.
     */
    ltmp1 = MDIO_REGS->ALIVE;
    for( i=0; ltmp1; i++,ltmp1>>=1 )
    {
        if( ltmp1 & 1 )
        {
            PHYREG_write( pd->regId, PHYREG_CONTROL, i, PHYREG_CONTROL_ISOLATE |
                                             PHYREG_CONTROL_POWERDOWN );
            PHYREG_wait( pd->regId );
        }
    }
}


/** ============================================================================
 *  @n@b MDIO_getStatus()
 *
 *  @b Description
 *  @n Called to get the status of the MDIO/PHY
 *
 *  @b Arguments
 *  @verbatim
        hMDIO       handle to the opened MDIO instance
        pPhy        pointer to the physical address
        pLinkStatus pointer to the link status
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset and opened before calling this API
 *
 *  <b> Post Condition </b>
 *  @n  MDIO stauts is returned through the parameters paased in this API.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_getStatus( &mdioDev, &pPhy, &pLinkStatus );

    @endverbatim
 * ============================================================================
 */
void MDIO_getStatus( Handle hMDIO, uint32_t *pPhy, uint32_t *pLinkStatus )
{
    MDIO_Device *pd = (MDIO_Device *)hMDIO;

    if( pPhy )
        *pPhy = pd->phyAddr;
    if( pLinkStatus )
        *pLinkStatus = pd->LinkStatus;
    	//*pLinkStatus = MDIO_REGS->LINK;
}


/** ============================================================================
 *  @n@b MDIO_timerTick()
 *
 *  @b Description
 *  @n Called to signify that approx 100mS have elapsed
 *
 *  @b Arguments
 *  @verbatim
        hMDIO   Handle to the opened MDIO instance
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n MDIO event code (see MDIO Events).
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset and opened before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  Gets approximately 100mS delay
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_timerTick( &mdioDev );
    @endverbatim
 * ============================================================================
 */
uint32_t MDIO_timerTick( Handle hMDIO )
{
    MDIO_Device *pd = (MDIO_Device *)hMDIO;
    Uint16      tmp1,tmp2,tmp1gig = 0, tmp2gig = 0, ack;
    volatile uint32_t      ltmp1;
    uint32_t        retVal = MDIO_EVENT_NOCHANGE;

    /*
     * If we are linked, we just check to see if we lost link. Otherwise;
     * we keep treking through our state machine.
     */
    if( pd->phyState == PHYSTATE_LINKED )
    {
        /*
         * Here we check for a "link-change" status indication or a link
         * down indication.
         */
        ltmp1 = MDIO_REGS->LINKINTRAW & (1<<pd->regId);
        MDIO_REGS->LINKINTRAW = ltmp1;
        if( ltmp1 || !(MDIO_REGS->LINK)&(1<<pd->phyAddr) )
        {
            /*
             * There has been a change in link (or it is down)
             * If we do not auto-neg, then we just wait for a new link
             * Otherwise, we enter NWAYSTART or NWAYWAIT
             */

            pd->LinkStatus = MDIO_LINKSTATUS_NOLINK;
            retVal = MDIO_EVENT_LINKDOWN;
            pd->phyStateTicks = 0;  /* Reset timeout */

            /* If not NWAY, just wait for link */
            if( !(pd->ModeFlags & MDIO_MODEFLG_NWAYACTIVE) )
                pd->phyState = PHYSTATE_LINKWAIT;
            else
            {
                /* Handle NWAY condition */

                /* First see if link is really down */
                PHYREG_read( pd->regId, PHYREG_STATUS, pd->phyAddr );
                PHYREG_wait( pd->regId );
                PHYREG_read( pd->regId, PHYREG_STATUS, pd->phyAddr );
                PHYREG_waitResultsAck( pd->regId, &tmp1, &ack );
                if( !ack )
                {
                    /* No PHY response, maybe it was unplugged */
                    MDIO_initStateMachine( pd );
                }
                else if( !(tmp1 & PHYREG_STATUS_LINKSTATUS) )
                {
                    /* No Link - restart NWAY */
                    pd->phyState = PHYSTATE_NWAYSTART;

                    PHYREG_write( pd->regId, PHYREG_CONTROL, pd->phyAddr,
                                  PHYREG_CONTROL_AUTONEGEN |
                                  PHYREG_CONTROL_AUTORESTART );
                    PHYREG_wait( pd->regId );
                }
                else
                {
                    /* We have a Link - re-read NWAY params  */
                    pd->phyState = PHYSTATE_NWAYWAIT;
                }
            }
        }
    }

    /*
     * If running in a non-linked state, execute the next
     * state of the state machine.
     */
    if( pd->phyState != PHYSTATE_LINKED )
    {
        /* Bump the time counter */
        pd->phyStateTicks++;

        /* Process differently based on state */
        switch( pd->phyState )
        {
        case PHYSTATE_RESET:
            /* Don't try to read reset status for the first 100 to 200 ms */
            if( pd->phyStateTicks < 2 )
                break;

            /* See if the PHY has come out of reset */
            PHYREG_read( pd->regId, PHYREG_CONTROL, pd->phyAddr );
            PHYREG_waitResultsAck( pd->regId, &tmp1, &ack );
            if( ack && !(tmp1 & PHYREG_CONTROL_RESET) )
            {
                /* PHY is not reset. If the PHY init is going well, break out */
                if( MDIO_initContinue( pd ) )
                    break;
                /* Else, this PHY is toast. Manually trigger a timeout */
                pd->phyStateTicks = PhyStateTimeout[pd->phyState];
            }

            /* Fall through to timeout check */

        case PHYSTATE_MDIOINIT:
CheckTimeout:
            /* Here we just check timeout and try to find a PHY */
            if( pd->phyStateTicks >= PhyStateTimeout[pd->phyState] )
            {
                if (pd->ModeFlags & MDIO_MODEFLG_SPECPHYADDR)
                {
                    ltmp1 = MDIO_REGS->ALIVE;
                    if( ltmp1 & (1<<pd->phyAddr) )
                    {
                       MDIO_initPHY( pd, pd->phyAddr );
                    }
                }
                else
                {
                    // Try the next PHY if anything but a MDIOINIT condition
                    if( pd->phyState != PHYSTATE_MDIOINIT )
                    {
                        if( ++pd->phyAddr == 32 )
                            pd->phyAddr = 0;
                    }
                    ltmp1 = MDIO_REGS->ALIVE;
                    for( tmp1=0; tmp1<32; tmp1++ )
                    {
                        if( ltmp1 & (1<<pd->phyAddr) )
                        {
                            if( MDIO_initPHY( pd, pd->phyAddr ) )
                                break;
                        }

                        if( ++pd->phyAddr == 32 )
                            pd->phyAddr = 0;
                    }

                    // If we didn't find a PHY, try again
                    if( tmp1 == 32 )
                    {
                        pd->phyAddr       = 0;
                        pd->phyState      = PHYSTATE_MDIOINIT;
                        pd->phyStateTicks = 0;
                        retVal = MDIO_EVENT_PHYERROR;
                    }
                }
            }
            break;

        case PHYSTATE_NWAYSTART:
            /*
             * Here we started NWAY. We check to see if NWAY is done.
             * If not done and timeout occured, we find another PHY.
             */

            /* Read the CONTROL reg to verify "restart" is not set */
            PHYREG_read( pd->regId, PHYREG_CONTROL, pd->phyAddr );
            PHYREG_waitResultsAck( pd->regId, &tmp1, &ack );
            if( !ack )
            {
                MDIO_initStateMachine( pd );
                break;
            }
            if( tmp1 & PHYREG_CONTROL_AUTORESTART )
                goto CheckTimeout;

            /* Flush latched "link status" from the STATUS reg */
            PHYREG_read( pd->regId, PHYREG_STATUS, pd->phyAddr );
            PHYREG_wait( pd->regId );

            pd->phyState = PHYSTATE_NWAYWAIT;

            /* Fallthrough */

        case PHYSTATE_NWAYWAIT:
            /*
             * Here we are waiting for NWAY to complete.
             */

            /* Read the STATUS reg to check for "complete" */
            PHYREG_read( pd->regId, PHYREG_STATUS, pd->phyAddr );
            PHYREG_waitResultsAck( pd->regId, &tmp1, &ack );
            if( !ack )
            {
                MDIO_initStateMachine( pd );
                break;
            }
            if( !(tmp1 & PHYREG_STATUS_AUTOCOMPLETE) )
                goto CheckTimeout;

            /* We can now check the negotiation results */

            if ( (macsel == GMII) || (macsel == RGMII) )
            {
                PHYREG_read( pd->regId, PHYREG_1000CONTROL, pd->phyAddr );
                PHYREG_waitResults( pd->regId,  &tmp1gig );
                PHYREG_read( pd->regId, PHYREG_1000STATUS, pd->phyAddr );
                PHYREG_waitResults( pd->regId, &tmp2gig );
            }

            PHYREG_read( pd->regId, PHYREG_ADVERTISE, pd->phyAddr );
            PHYREG_waitResults( pd->regId, &tmp1 );
            PHYREG_read( pd->regId, PHYREG_PARTNER, pd->phyAddr );
            PHYREG_waitResults( pd->regId, &tmp2 );
            /*
             * Use the "best" results
             */
            tmp2 &= tmp1;

            /* Check first for 1 Gigabit */
            if( (tmp1gig & PHYREG_ADVERTISE_FD1000) && (tmp2gig & PHYREG_PARTNER_FD1000) )
                pd->PendingStatus = MDIO_LINKSTATUS_FD1000;
            else if( tmp2 & PHYREG_ADVERTISE_FD100 )
                pd->PendingStatus = MDIO_LINKSTATUS_FD100;
            else if( tmp2 & PHYREG_ADVERTISE_HD100 )
                pd->PendingStatus = MDIO_LINKSTATUS_HD100;
            else if( tmp2 & PHYREG_ADVERTISE_FD10 )
                pd->PendingStatus = MDIO_LINKSTATUS_FD10;
            else if( tmp2 & PHYREG_ADVERTISE_HD10 )
                pd->PendingStatus = MDIO_LINKSTATUS_HD10;
            /*
             * If we get here the negotiation failed
             * We just use HD 100 or 10 - the best we think we can do
             */
            else if( tmp1 & PHYREG_ADVERTISE_HD100 )
                pd->PendingStatus = MDIO_LINKSTATUS_HD100;
            else
                pd->PendingStatus = MDIO_LINKSTATUS_HD10;

            pd->phyState = PHYSTATE_LINKWAIT;

            /* Fallthrough */

        case PHYSTATE_LINKWAIT:
            /*
             * Here we are waiting for LINK
             */

            /* Read the STATUS reg to check for "link" */
            PHYREG_read( pd->regId, PHYREG_STATUS, pd->phyAddr );
            PHYREG_waitResultsAck( pd->regId, &tmp1, &ack );
            if( !ack )
            {
                MDIO_initStateMachine( pd );
                break;
            }
            if( !(tmp1 & PHYREG_STATUS_LINKSTATUS) )
                goto CheckTimeout;

            /* Make sure we're linked in the MDIO module as well */
            ltmp1 = MDIO_REGS->LINK;
            if( !(ltmp1&(1<<pd->phyAddr)) )
                goto CheckTimeout;

            /* Start monitoring this PHY */
            if (pd->regId == 1)
              MDIO_REGS->USERPHYSEL1 = pd->phyAddr;
            else
              MDIO_REGS->USERPHYSEL0 = pd->phyAddr;

            /* Clear the link change flag so we can detect a "re-link" later */
            MDIO_REGS->LINKINTRAW = 1<<pd->regId;

            /* Setup our linked state */
            pd->phyState   = PHYSTATE_LINKED;
            pd->LinkStatus = pd->PendingStatus;
            retVal = MDIO_EVENT_LINKUP;

            break;
        }
    }

    return( retVal );
}


/** ============================================================================
 *  @n@b MDIO_initPHY()
 *
 *  @b Description
 *  @n Force a switch to the specified PHY, and start the negotiation process.

 *  @b Arguments
 *  @verbatim
        hMDIO   handle to the opened MDIO instance
        phyAddr Physical address
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Returns 1 if the PHY selection completed OK,
 *  @n else 0
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset.
 *
 *  <b> Post Condition </b>
 *  @n  Initializes the specific PHY device.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_initPHY( &mdioDev, mdioPhyAddr );
    @endverbatim
 * ============================================================================
 */
uint32_t MDIO_initPHY( Handle hMDIO, volatile uint32_t phyAddr )
{
    MDIO_Device *pd = (MDIO_Device *)hMDIO;
#if defined(C6474) | defined(C6457) | defined(C6472)
    uint32_t         ltmp1;
    Uint16           i,ack;

    /* Switch the PHY */
    pd->phyAddr = phyAddr;

    /* There will be no link when we're done with this PHY */
    pd->LinkStatus = MDIO_LINKSTATUS_NOLINK;

    if ( !(pd->ModeFlags & MDIO_MODEFLG_SPECPHYADDR))
    {
        /* Shutdown all other PHYs */
        ltmp1 = MDIO_REGS->ALIVE ;
        for( i=0; ltmp1; i++,ltmp1>>=1 )
        {
            if( (ltmp1 & 1) && (i != phyAddr) )
            {
                PHYREG_write( pd->regId, PHYREG_CONTROL, i, PHYREG_CONTROL_ISOLATE |
                                                 PHYREG_CONTROL_POWERDOWN );
                PHYREG_wait( pd->regId );
            }
        }
    }

    /* Reset the PHY we plan to use */
    PHYREG_write( pd->regId, PHYREG_CONTROL, phyAddr, PHYREG_CONTROL_RESET );
    PHYREG_waitResultsAck( pd->regId, &i, &ack );

    /* If the PHY did not ACK the write, return zero */
    if( !ack )
        return(0);

/* This is for Broadcom phys */
    if ( macsel == RGMII )
    {
        //Put phy in copper mode
        PHYREG_write( pd->regId, PHYREG_ACCESS, phyAddr, PHYREG_ACCESS_COPPER );
        PHYREG_wait( pd->regId );

        PHYREG_write( pd->regId, 0x10, phyAddr, 0x0000 );  //GMII Interface
        PHYREG_wait( pd->regId );

        // Put phy in RGMII mode/in-band status data
        PHYREG_write(pd->regId, PHYREG_SHADOW, phyAddr, PHYREG_SHADOW_INBAND);
        PHYREG_waitResultsAck( pd->regId, &i, &ack );

        /* If the PHY did not ACK the write, return zero */
        if( !ack )
            return(0);

    }
#endif
    /* Setup for our next state */
    pd->phyState = PHYSTATE_RESET;
    pd->phyStateTicks = 0;  /* Reset timeout */

    return(1);
}

/** ============================================================================
 *  @n@b MDIO_initContinue()
 *
 *  @b Description
 *  @n Continues the initialization process started in MDIO_initPHY()
 *
 *  @b Arguments
 *  @verbatim
        pd  pointer to MDIO device object
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Returns 0 on an error,
 *  @n 1 on success
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO_initPHY function must be called before calling this API
 *
 *  <b> Post Condition </b>
 *  @n  Continues and completes the initialization process started in
 *      MDIO_initPHY()
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t    mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK;
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_initPHY( &mdioDev, mdioPhyAddr );

        MDIO_initContinue( (MDIO_Device *)&mdioDev );
    @endverbatim
 * ============================================================================
 */
static uint32_t MDIO_initContinue( MDIO_Device *pd )
{
    pd->ModeFlags |= MDIO_MODEFLG_NWAYACTIVE;
    pd->phyState = PHYSTATE_NWAYSTART;
    pd->phyStateTicks = 0;  /* Reset timeout */

    return(1);
}


/** ============================================================================
 *  @n@b MDIO_phyRegRead()
 *
 *  @b Description
 *  @n Raw data read of a PHY register.
 *
 *  @b Arguments
 *  @verbatim
        phyIdx  Physical Index
        phyReg  Physical register
        pData   Data read
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Returns 1 if the PHY ACK'd the read,
 *  @n else 0
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset and opened. PHY device must be initialized.
 *
 *  <b> Post Condition </b>
 *  @n  Raw data is read from a PHY register.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040

        volatile uint32_t phyIdx = PHYREG_CONTROL;
        volatile uint32_t phyReg;
        Uint16 pData;

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_initPHY( &mdioDev, mdioPhyAddr );

        MDIO_phyRegRead( phyIdx, ((MDIO_Device *)&mdioDev)->phyReg, pData );
    @endverbatim
 * ============================================================================
 */
uint32_t MDIO_phyRegRead( volatile uint32_t phyIdx, volatile uint32_t phyReg, Uint16 *pData )
{
    Uint16 data,ack;

    PHYREG_read(0, phyReg, phyIdx );
    PHYREG_waitResultsAck(0, &data, &ack );

    if( !ack )
        return(0);
    if( pData )
        *pData = data;
    return(1);
}


/** ============================================================================
 *  @n@b MDIO_phyRegWrite()
 *
 *  @b Description
 *  @n Raw data write of a PHY register.
 *
 *  @b Arguments
 *  @verbatim
        phyIdx  Physical Index
        phyReg  Physical register
        pData   Data written
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Returns 1 if the PHY ACK'd the write,
 *  @n else 0
 *
 *  <b> Pre Condition </b>
 *  @n  MDIO module must be reset and opened. PHY device must be initialized.
 *
 *  <b> Post Condition </b>
 *  @n  Raw data is written to a PHY register.
 *
 *  @b  Example:
 *  @verbatim
        #define MDIO_MODEFLG_FD1000         0x0020
        #define MDIO_MODEFLG_LOOPBACK       0x0040
        #define PHYREG_SHADOW_EXTLOOPBACK   0x8400

        volatile uint32_t phyIdx = PHYREG_CONTROL;
        volatile uint32_t phyReg;
        Uint16 pData = PHYREG_SHADOW_EXTLOOPBACK;

        MDIO_Device    mdioDev;
        int            instNum = 0;
        uint32_t         mdioModeFlags = MDIO_MODEFLG_FD1000 | MDIO_MODEFLG_LOOPBACK; 
        uint32_t         mdioPhyAddr = 0;

        //Open the MDIO module
        MDIO_open(instNum, mdioModeFlags, mdioPhyAddr, &mdioDev);

        MDIO_initPHY( &mdioDev, mdioPhyAddr );

        MDIO_phyRegWrite( phyIdx, ((MDIO_Device *)&mdioDev)->phyReg, pData );
    @endverbatim
 * ============================================================================
 */
uint32_t MDIO_phyRegWrite( volatile uint32_t phyIdx, volatile uint32_t phyReg, Uint16 data )
{
    Uint16 ack;

    PHYREG_write(0, phyReg, phyIdx, data );
    PHYREG_waitResultsAck(0, &data, &ack );

    if( !ack )
        return(0);
    return(1);
}

