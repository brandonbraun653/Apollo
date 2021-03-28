/* =============================================================================
 *  (C) Copyright 2017-2018, Texas Instruments, Inc.
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

/**
 *  \file   csl_psilcfg.c
 *
 *  \brief  This is the implementation file for the Packet Streaming Interface
 *          Link (PSI-L) configuration CSL-FL.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/csl_psilcfg.h>

#define CSL_PSILCFG_DST_THREAD      (0x8000U)   /* Logically or'd with thread ID to identify it as a destination thread */

static bool CSL_psilcfgIsCmdBusy( const CSL_psilcfgRegs *pRegs );
static bool CSL_psilcfgIsCmdTimedOut( const CSL_psilcfgRegs *pRegs );
static uint32_t CSL_psilcfgReadData( const CSL_psilcfgRegs *pRegs );
bool CSL_psilcfgIsThreadIdle( const CSL_psilcfgRegs *pRegs, uint32_t threadId );

/*=============================================================================
 *  Internal functions
 *===========================================================================*/
static bool CSL_psilcfgIsCmdBusy( const CSL_psilcfgRegs *pRegs )
{
    return (CSL_REG32_FEXT(&pRegs->CMDA, PSILCFG_CMDA_BUSY) == 0U) ? (bool)false : (bool)true;
}

static bool CSL_psilcfgIsCmdTimedOut( const CSL_psilcfgRegs *pRegs )
{
    return (CSL_REG32_FEXT(&pRegs->CMDA, PSILCFG_CMDA_TO) == 0U) ? (bool)false : (bool)true;
}

static uint32_t CSL_psilcfgReadData( const CSL_psilcfgRegs *pRegs )
{
    return CSL_REG32_RD(&pRegs->RDATA);
}

/*=============================================================================
 *  API functions
 *===========================================================================*/
uint32_t CSL_psilcfgGetRevision( const CSL_psilcfgRegs *pRegs )
{
    return( CSL_REG32_RD(&pRegs->REVISION) );
}

bool CSL_psilcfgWrite( const CSL_psilcfgRegs *pRegs, uint32_t threadId, uint32_t regId, uint32_t data )
{
    bool bRetVal = (bool)true;

    if( !CSL_psilcfgIsCmdBusy(pRegs) )
    {
        /*---------------------------------------------------------------------
         *  Submit the write command
         *-------------------------------------------------------------------*/
        CSL_REG32_WR(&pRegs->CMDA,
            CSL_FMK(PSILCFG_CMDA_DIR, (uint32_t)CSL_PSILCFG_CMDA_DIR_VAL_WRITE)   |
            CSL_FMK(PSILCFG_CMDA_THREAD_ID, threadId) );
        CSL_REG32_WR(&pRegs->CMDB,
            CSL_FMK(PSILCFG_CMDB_BYTEN, (uint32_t)0xFU)   |
            CSL_FMK(PSILCFG_CMDB_ADDRESS, (uint32_t)regId) );
        CSL_REG32_WR(&pRegs->WDATA, data);
        /*---------------------------------------------------------------------
         *  Wait for command to complete
         *-------------------------------------------------------------------*/
        while( CSL_psilcfgIsCmdBusy( pRegs ) == (bool)true ) { }
        /*---------------------------------------------------------------------
         *  If the command timed out, clear the tout bit in the PSIL_TO
         *  register and set the return value to false.
         *-------------------------------------------------------------------*/
        if( CSL_psilcfgIsCmdTimedOut( pRegs ) == (bool)true )
        {
            CSL_REG32_FINS( &pRegs->PSIL_TO, PSILCFG_PSIL_TO_TOUT, (uint32_t)0U );
            bRetVal = (bool)false;
        }
    }
    else
    {
        bRetVal = (bool)false;
    }
    return bRetVal;
}

bool CSL_psilcfgRead( const CSL_psilcfgRegs *pRegs, uint32_t threadId, uint32_t regId, uint32_t *pData )
{
    bool bRetVal = (bool)true;

    if( !CSL_psilcfgIsCmdBusy(pRegs) )
    {
        /*---------------------------------------------------------------------
         *  Submit the read command
         *-------------------------------------------------------------------*/
        CSL_REG32_WR(&pRegs->CMDA,
            CSL_FMK(PSILCFG_CMDA_DIR, (uint32_t)CSL_PSILCFG_CMDA_DIR_VAL_READ)   |
            CSL_FMK(PSILCFG_CMDA_THREAD_ID, threadId) );
        CSL_REG32_WR(&pRegs->CMDB,
            CSL_FMK(PSILCFG_CMDB_BYTEN, (uint32_t)0xFU)   |
            CSL_FMK(PSILCFG_CMDB_ADDRESS, (uint32_t)regId) );
        /*---------------------------------------------------------------------
         *  Wait for command to complete
         *-------------------------------------------------------------------*/
        while( CSL_psilcfgIsCmdBusy( pRegs ) == (bool)true ) { }
        /*---------------------------------------------------------------------
         *  If the command timed out, clear the tout bit in the PSIL_TO
         *  register and set the return value to false. Otherwise, capture
         *  the data read.
         *-------------------------------------------------------------------*/
        if( CSL_psilcfgIsCmdTimedOut( pRegs ) == (bool)true )
        {
            CSL_REG32_FINS( &pRegs->PSIL_TO, PSILCFG_PSIL_TO_TOUT, (uint32_t)0U );
            bRetVal = (bool)false;
        }
        else
        {
            *pData = CSL_psilcfgReadData( pRegs );
        }
    }
    else
    {
        bRetVal = (bool)false;
    }
    return bRetVal;
}

bool CSL_psilcfgSetThreadEnable( const CSL_psilcfgRegs *pRegs, uint32_t threadId, bool bEnable )
{
    uint32_t    regVal;
    bool        bTransOk;

    bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_ENABLE, &regVal );
    if( bTransOk == (bool)true )
    {
        uint32_t fieldVal;

        if( bEnable == (bool)true ) { fieldVal = 1U; } else { fieldVal = 0; }
        CSL_FINS( regVal, PSILCFG_REG_ENABLE_ENABLE, fieldVal );
        bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_ENABLE, regVal );     /* Enable/disable thread */
    }
    return bTransOk;
}

bool CSL_psilcfgSetThreadRealtimeEnable( const CSL_psilcfgRegs *pRegs, uint32_t threadId, bool bEnable )
{
    uint32_t    regVal;
    bool        bTransOk;

    bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
    if( bTransOk == (bool)true )
    {
        uint32_t fieldVal;

        if( bEnable == (bool)true ) { fieldVal = 1U; } else { fieldVal = 0; }
        CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_ENABLE, fieldVal );
        bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, regVal );  /* Enable/disable realtime thread */
    }
    return bTransOk;
}

bool CSL_psilcfgIsThreadIdle( const CSL_psilcfgRegs *pRegs, uint32_t threadId )
{
    uint32_t    regVal;
    bool        bTransOk;

    bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
    if( bTransOk == (bool)true )
    {
       bTransOk = (CSL_FEXT( regVal, PSILCFG_REG_RT_ENABLE_IDLE ) == 0U) ? (bool)false : (bool)true;
    }
    return bTransOk;
}

bool CSL_psilcfgTeardownThread( const CSL_psilcfgRegs *pRegs, uint32_t threadId )
{
    uint32_t    regVal;
    bool        bTransOk;

    if( (threadId & CSL_PSILCFG_DST_THREAD) == 0U )
    {
        /* Teardown should only be set in source threads */
        bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
        if( bTransOk == (bool)true )
        {
            CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_TDOWN, (uint32_t)1U );
            bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, regVal );     /* Teardown thread */
            if( bTransOk == (bool)true )
            {
                /* Wait for thread to be idle */
                while( CSL_psilcfgIsThreadIdle( pRegs, threadId ) == (bool)false ) { }
            }
        }
        bTransOk = CSL_psilcfgSetThreadRealtimeEnable( pRegs, threadId, (bool)false );
    }
    else
    {
        /* Teardown should not be set in destination threads. In this case, return false. */
        bTransOk = (bool)false;
    }
    return bTransOk;
}

bool CSL_psilcfgClrTeardown( const CSL_psilcfgRegs *pRegs, uint32_t threadId )
{
    uint32_t    regVal;
    bool        bTransOk;

    bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
    if( bTransOk == (bool)true )
    {
        CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_TDOWN, (uint32_t)0U );
        CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_FLUSH, (uint32_t)0U );
        bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, regVal );
    }
    return bTransOk;
}

bool CSL_psilcfgFlushThread( const CSL_psilcfgRegs *pRegs, uint32_t threadId )
{
    uint32_t    regVal;
    bool        bTransOk;

    if( (threadId & CSL_PSILCFG_DST_THREAD)!= 0U )
    {
        /* Flush should only be set in destination threads */
        bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
        if( bTransOk == (bool)true )
        {
          CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_FLUSH, (uint32_t)1U );
          bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, regVal );     /* Flush thread */
        }
    }
    else
    {
        bTransOk = (bool)false;
    }
    return bTransOk;
}

bool CSL_psilcfgSetThreadPause( const CSL_psilcfgRegs *pRegs, uint32_t threadId, bool bPause )
{
    uint32_t    regVal;
    bool        bTransOk;

    bTransOk = CSL_psilcfgRead( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, &regVal );
    if( bTransOk == (bool)true )
    {
        uint32_t fieldVal;

        if( bPause == (bool)true ) { fieldVal = 1U; } else { fieldVal = 0; }
        CSL_FINS( regVal, PSILCFG_REG_RT_ENABLE_PAUSE, fieldVal );
        bTransOk = CSL_psilcfgWrite( pRegs, threadId, CSL_PSILCFG_REG_RT_ENABLE, regVal );     /* Pause/un-pause thread */
    }
    return bTransOk;
}

bool CSL_psilcfgCreateRoute( const CSL_psilcfgRegs *pRegs, uint32_t srcThreadId, uint32_t dstThreadId )
{
    bool bTransOk;

    if( (srcThreadId & CSL_PSILCFG_DST_THREAD) != 0U )
    {
        bTransOk = (bool)false;         /* Return false if bit 15 of srcThreadId is set to 1 */
    }
    else
    {
        uint32_t    localDstThreadId = dstThreadId;
        uint32_t    regVal;

        localDstThreadId |= CSL_PSILCFG_DST_THREAD;     /* Force bit 15 of dstThreadId to 1 */
        bTransOk = CSL_psilcfgRead( pRegs, localDstThreadId, CSL_PSILCFG_REG_CAPABILITIES, &regVal );       /* Read destination thread capabilities */
        if( bTransOk == (bool)true )
        {
            uint32_t threadWidth, creditCnt;

            threadWidth = CSL_FEXT( regVal, PSILCFG_REG_CAPABILITIES_THREAD_WIDTH );
            creditCnt   = CSL_FEXT( regVal, PSILCFG_REG_CAPABILITIES_CREDIT_CNT );
            regVal      = CSL_FMK( PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH, threadWidth )    |
                          CSL_FMK( PSILCFG_REG_PEER_THREAD_ID_THREAD_ID, localDstThreadId );
            bTransOk = CSL_psilcfgWrite( pRegs, srcThreadId, CSL_PSILCFG_REG_PEER_THREAD_ID, regVal );      /* Configure Thread ID Register */
            if( bTransOk  == (bool)true )
            {
                regVal = CSL_FMK( PSILCFG_REG_PEER_CREDIT_CNT, creditCnt );
                bTransOk = CSL_psilcfgWrite( pRegs, srcThreadId, CSL_PSILCFG_REG_PEER_CREDIT, regVal );     /* Configure Credit Register */
            }
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadEnable( pRegs, localDstThreadId, (bool)true ); }           /* Enable destination thread */
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadEnable( pRegs, srcThreadId, (bool)true ); }                /* Enable source thread */
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadRealtimeEnable( pRegs, localDstThreadId, (bool)true ); }   /* Enable destination realtime thread */
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadRealtimeEnable( pRegs, srcThreadId, (bool)true ); }        /* Enable source realtime thread */
        }
    }
    return bTransOk;
}

bool CSL_psilcfgCreateLink( const CSL_psilcfgRegs *pRegs, uint32_t srcThreadId, uint32_t dstThreadId )
{
    bool bTransOk;

    if( (srcThreadId & CSL_PSILCFG_DST_THREAD) != 0U )
    {
        bTransOk = (bool)false;         /* Return false if bit 15 of srcThreadId is set to 1 */
    }
    else
    {
        uint32_t    localDstThreadId = dstThreadId;
        uint32_t    regVal;

        localDstThreadId |= CSL_PSILCFG_DST_THREAD;     /* Force bit 15 of dstThreadId to 1 */
        bTransOk = CSL_psilcfgRead( pRegs, localDstThreadId, CSL_PSILCFG_REG_CAPABILITIES, &regVal );       /* Read destination thread capabilities */
        if( bTransOk == (bool)true )
        {
            uint32_t threadWidth, creditCnt;

            threadWidth = CSL_FEXT( regVal, PSILCFG_REG_CAPABILITIES_THREAD_WIDTH );
            creditCnt   = CSL_FEXT( regVal, PSILCFG_REG_CAPABILITIES_CREDIT_CNT );
            regVal      = CSL_FMK( PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH, threadWidth )    |
                          CSL_FMK( PSILCFG_REG_PEER_THREAD_ID_THREAD_ID, localDstThreadId );
            bTransOk = CSL_psilcfgWrite( pRegs, srcThreadId, CSL_PSILCFG_REG_PEER_THREAD_ID, regVal );      /* Configure Thread ID Register */
            if( bTransOk  == (bool)true )
            {
                regVal = CSL_FMK( PSILCFG_REG_PEER_CREDIT_CNT, creditCnt );
                bTransOk = CSL_psilcfgWrite( pRegs, srcThreadId, CSL_PSILCFG_REG_PEER_CREDIT, regVal );     /* Configure Credit Register */
            }
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadEnable( pRegs, localDstThreadId, (bool)true ); }           /* Enable destination thread */
            if( bTransOk == (bool)true ) { bTransOk = CSL_psilcfgSetThreadEnable( pRegs, srcThreadId, (bool)true ); }                /* Enable source thread */
        }
    }
    return bTransOk;
}
