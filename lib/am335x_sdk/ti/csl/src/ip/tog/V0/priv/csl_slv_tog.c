/**
 * @file  csl_slv_tog.c
 *
 * @brief
 *  Implementation file for the VBUSM Slave Timeout Gasket module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2019, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorposlv_toged nor the names of
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

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/csl_tog.h>
#include <ti/csl/csl_types.h>

#define CSL_SLV_TOG_ENABLE_KEY      ((uint32_t) 0x0000000FU)
#define CSL_SLV_TOG_FLUSH_MODE_KEY  ((uint32_t) 0x0000000FU)

int32_t CSL_slvTogGetRevision( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pRev )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pRev != NULL) )
    {
        *pRev = CSL_REG32_RD( &pRegs->PID );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetCfg( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pTotalReads, uint32_t *pTotalWrites )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pTotalReads != NULL) && (pTotalWrites != NULL) )
    {
        uint32_t regVal;
        
        regVal = CSL_REG32_RD( &pRegs->CFG );
        *pTotalReads = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_CFG_NUM_READS );        
        *pTotalWrites = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_CFG_NUM_WRITES );        
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetStatus( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pCurrReads, uint32_t *pCurrWrites )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pCurrReads != NULL) && (pCurrWrites != NULL) )
    {
        uint32_t regVal;
        
        regVal = CSL_REG32_RD( &pRegs->INFO );
        *pCurrReads = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_INFO_CUR_READS );        
        *pCurrWrites = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_INFO_CUR_WRITES );        
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetErrInfo( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogErrInfo *pErrInfo )
{
    int32_t  retVal = CSL_EFAIL;
   
    if( (pRegs != NULL) && (pErrInfo != NULL) )
    {
        uint32_t regVal = CSL_REG32_RD( &pRegs->ERR_VAL );
        
        if( CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_VAL_VAL ) == 1U )
        {
            uint32_t regVal2;
            
            pErrInfo->routeId   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_VAL_RID );
            pErrInfo->orderId   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_VAL_OID );
            pErrInfo->dir   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_VAL_DIR );
            pErrInfo->type  = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_VAL_TYP );
            
            regVal = CSL_REG32_RD( &pRegs->ERR_TAG );
            pErrInfo->tag   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_TAG_TAG );
            pErrInfo->commandId   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_TAG_CID );
            
            regVal = CSL_REG32_RD( &pRegs->ERR_BYT );
            pErrInfo->orgByteCnt    = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_BYT_OBYTECNT );
            pErrInfo->currByteCnt   = CSL_FEXT( regVal, KSBUS_VBUSM_TO_GASKET_ERR_BYT_CBYTECNT );
            
            regVal  = CSL_REG32_RD( &pRegs->ERR_ADDR_L );
            regVal2 = CSL_REG32_RD( &pRegs->ERR_ADDR_U );
            pErrInfo->address = (((uint64_t)regVal2) << 32U) | ((uint64_t)regVal);
            retVal = CSL_PASS;            
        }
    }
    return retVal;
}

int32_t CSL_slvTogGetIntrPending( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pPendInts )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pPendInts != NULL) )
    {
        *pPendInts = CSL_REG32_RD( &pRegs->ERR );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetRawIntrPending( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pRawPendInts )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pRawPendInts != NULL) )
    {
        *pRawPendInts = CSL_REG32_RD( &pRegs->ERR_RAW );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogSetIntrPending( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (intrSrcs > 0U) && (intrSrcs <= CSL_SLV_TOG_INTRSRC_ALL) )
    {
        CSL_REG32_WR( &pRegs->ERR_RAW, intrSrcs );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogClrIntrPending( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (intrSrcs > 0U) && (intrSrcs <= CSL_SLV_TOG_INTRSRC_ALL) )
    {
        CSL_REG32_WR( &pRegs->ERR, intrSrcs );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogSetIntrEnable( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs, bool bEnable )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (intrSrcs > 0U) && (intrSrcs <= CSL_SLV_TOG_INTRSRC_ALL) )
    {
        if( bEnable == (bool)true )
        {
            CSL_REG32_WR( &pRegs->ERR_MSK_SET, intrSrcs );
        }
        else
        {
            CSL_REG32_WR( &pRegs->ERR_MSK_CLR, intrSrcs );            
        }
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetIntrCount( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrc, uint32_t *pIntrCnt )
{
    int32_t  retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pIntrCnt != NULL) )
    {
        if( intrSrc == CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT )
        {
            *pIntrCnt = CSL_REG32_RD( &pRegs->ERR_TM_INFO );
            retVal = CSL_PASS;
        }
        else if( intrSrc == CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE )
        {
            *pIntrCnt = CSL_REG32_RD( &pRegs->ERR_UN_INFO );
            retVal = CSL_PASS;
        }
        else
        {
        }
    }
    return retVal;
}

int32_t CSL_slvTogAckIntr( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrc, uint32_t ackCnt )
{
    int32_t  retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (ackCnt > 0U) )
    {
        uint32_t pendingIntrCnt;
        
        if( intrSrc == CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT )
        {
            CSL_slvTogGetIntrCount( pRegs, intrSrc, &pendingIntrCnt );
            if( ackCnt <= pendingIntrCnt )
            {
                CSL_REG32_WR( &pRegs->ERR_TM_INFO, CSL_FMK( KSBUS_VBUSM_TO_GASKET_ERR_TM_INFO_CNT, ackCnt ) );
                retVal = CSL_PASS;
            }
        }
        else if( intrSrc == CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE )
        {
            CSL_slvTogGetIntrCount( pRegs, intrSrc, &pendingIntrCnt );
            if( ackCnt <= pendingIntrCnt )
            {
                CSL_REG32_WR( &pRegs->ERR_UN_INFO, CSL_FMK( KSBUS_VBUSM_TO_GASKET_ERR_UN_INFO_CNT, ackCnt ) );
                retVal = CSL_PASS;
            }
        }
    }
    return retVal;
}

int32_t CSL_slvTogSetTimeoutVal( CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t timeoutVal )
{
    int32_t retVal = CSL_EFAIL;

    if( pRegs != NULL )
    {
        CSL_REG32_WR( &pRegs->TIMEOUT, CSL_FMK( KSBUS_VBUSM_TO_GASKET_TIMEOUT_TO, timeoutVal ) );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogStart( CSL_ksbus_vbusm_to_gasketRegs *pRegs )
{
    int32_t retVal = CSL_EFAIL;

    if( pRegs != NULL )
    {
        CSL_REG32_WR( &pRegs->ENABLE, CSL_FMK( KSBUS_VBUSM_TO_GASKET_ENABLE_EN, CSL_SLV_TOG_ENABLE_KEY ) );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogStop( CSL_ksbus_vbusm_to_gasketRegs *pRegs )
{
    int32_t retVal = CSL_EFAIL;

    if( pRegs != NULL )
    {
        CSL_REG32_WR( &pRegs->ENABLE, CSL_FMK( KSBUS_VBUSM_TO_GASKET_ENABLE_EN, 0U ) );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogReset( CSL_ksbus_vbusm_to_gasketRegs *pRegs )
{
    int32_t retVal = CSL_EFAIL;

    if( pRegs != NULL )
    {
        /* Stop timer */
        CSL_slvTogStop( pRegs );
        /* Reset timer counter and eon to 0 */
        CSL_REG32_FINS( &pRegs->TIMER, KSBUS_VBUSM_TO_GASKET_TIMER_CNTR, 0U );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogGetCurrTimerCnt( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pTimerCnt )
{
    int32_t retVal = CSL_EFAIL;

    if( (pRegs != NULL) && (pTimerCnt != NULL) )
    {
        *pTimerCnt = CSL_REG32_RD( &pRegs->TIMER );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_slvTogSetFlushModeEnable( CSL_ksbus_vbusm_to_gasketRegs *pRegs, bool bEnable )
{
    int32_t retVal = CSL_EFAIL;

    if( pRegs != NULL )
    {
        if( bEnable == (bool)true )
        {
            CSL_REG32_WR( &pRegs->FLUSH, CSL_FMK( KSBUS_VBUSM_TO_GASKET_FLUSH_FL, CSL_SLV_TOG_FLUSH_MODE_KEY ) );
        }
        else
        {
            CSL_REG32_WR( &pRegs->FLUSH, CSL_FMK( KSBUS_VBUSM_TO_GASKET_FLUSH_FL, 0U ) );
        }
        retVal = CSL_PASS;
    }
    return retVal;
}
