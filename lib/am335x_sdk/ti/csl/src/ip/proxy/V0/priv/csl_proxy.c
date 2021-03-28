/**
 * @file  csl_proxy.c
 *
 * @brief
 *  Implementation file for the proxy module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2020, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorpoproxyed nor the names of
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
#include <ti/csl/csl_proxy.h>

#define CSL_PROXY_TARGET_CHAN_SIZE      ((uint32_t) 4096U)
#define CSL_PROXY_TARGET_MAX_MSG_SIZE   ((uint32_t) 512U)

/*=============================================================================
 *  Internal functions
 *===========================================================================*/
static uint32_t bIsPowerOfTwo(uint32_t x);
static uint32_t min( uint32_t x, uint32_t y );

static uint32_t bIsPowerOfTwo(uint32_t x)
{
  return ((x==0U) || ((x & (x - 1U))==0U)) ? (uint32_t)1U : (uint32_t)0U;
}

static uint32_t min( uint32_t x, uint32_t y )
{
    uint32_t minRet = x;
    if( y < x ) { minRet = y; }
    return minRet;
}

/*=============================================================================
 *  CSL-FL functions
 *===========================================================================*/

uint32_t CSL_proxyGetRevision( const CSL_ProxyCfg *pProxyCfg )
{
    return CSL_REG32_RD( &pProxyCfg->pGlbRegs->PID );
}

uint32_t CSL_proxyGetNumThreads( const CSL_ProxyCfg *pProxyCfg )
{
    return (uint32_t)CSL_REG32_FEXT( &pProxyCfg->pGlbRegs->CONFIG, PROXY_CONFIG_THREADS );
}

int32_t CSL_proxyCfgGlobalErrEvtNum( const CSL_ProxyCfg *pProxyCfg, uint32_t globalErrEvtNum )
{
    int32_t retVal;
#ifdef CSL_PROXY_GLB_EVT_ERR_EVENT_MASK
    CSL_REG32_FINS( &pProxyCfg->pGlbRegs->GLB_EVT, PROXY_GLB_EVT_ERR_EVENT, globalErrEvtNum );
    retVal = 0;
#else
    retVal = -1;
#endif
    return retVal;
}

int32_t CSL_proxyCfgThread( CSL_ProxyCfg *pProxyCfg, uint32_t targetNum, uint32_t threadNum, const CSL_ProxyThreadCfg *pThreadCfg )
{
    int32_t retVal = 0;
    uint32_t regVal;
    CSL_ProxyTargetParams *pProxyTargetParams = &((pProxyCfg->pProxyTargetParams)[targetNum]);

    if( (targetNum < pProxyCfg->numTargets)                 &&
        (threadNum < CSL_proxyGetNumThreads(pProxyCfg))     &&
        (pThreadCfg->elSz >= 4U)                            &&
        (pThreadCfg->elSz <= 512U)                          &&
        (bIsPowerOfTwo(pThreadCfg->elSz) == (uint32_t)1U)   &&
        (pThreadCfg->queueNum < pProxyTargetParams->numChns) )
    {

        regVal = CSL_FMK( PROXY_TARGET0_PROXY_CTL_ELSIZE,   CSL_proxyEncodeElementSize(pThreadCfg->elSz) )  |
                 CSL_FMK( PROXY_TARGET0_PROXY_CTL_MODE,     pThreadCfg->mode )                          |
                 CSL_FMK( PROXY_TARGET0_PROXY_CTL_QUEUE,    pThreadCfg->queueNum );
        CSL_REG32_WR( &pProxyTargetParams->pTargetRegs->PROXY[threadNum].CTL, regVal );
    }
    else
    {
        retVal = -1;
    }
    return retVal;
}

int32_t CSL_proxyCfgThreadErrEvtNum( CSL_ProxyCfg *pProxyCfg, uint32_t targetNum, uint32_t threadNum, uint32_t errEvtNum )
{
    int32_t retVal = 0;

    if( (targetNum < pProxyCfg->numTargets)                 &&
        (threadNum < CSL_proxyGetNumThreads(pProxyCfg)) )
    {
        uint32_t regVal;
        
        regVal = CSL_FMK( PROXY_CFG_PROXY_EVT_REG_ERR_EVENT, errEvtNum );
        CSL_REG32_WR( &pProxyCfg->pCfgRegs->PROXY[threadNum].EVT_REG, regVal );
    }
    else
    {
        retVal = -1;
    }
    return retVal;
}

uint32_t CSL_proxyGetMaxMsgSize( const CSL_ProxyCfg *pProxyCfg, uint32_t targetNum )
{
    uint32_t maxXferSizeBytes = 0U;

    if( targetNum < pProxyCfg->numTargets )
    {
        CSL_ProxyTargetParams *pProxyTargetParams = &((pProxyCfg->pProxyTargetParams)[targetNum]);

        maxXferSizeBytes = min( pProxyCfg->bufferSizeBytes, pProxyTargetParams->chnSizeBytes );
    }
    return maxXferSizeBytes;
}

uintptr_t CSL_proxyGetDataAddr( const CSL_ProxyCfg *pProxyCfg, uint32_t targetNum, uint32_t threadNum, uint32_t numBytes )
{
    uintptr_t dataAddr;
    CSL_ProxyTargetParams *pProxyTargetParams = &((pProxyCfg->pProxyTargetParams)[targetNum]);

    dataAddr =  (uintptr_t)pProxyTargetParams->pTargetRegs->PROXY[threadNum].DATA;
    dataAddr += (uintptr_t)CSL_PROXY_TARGET_MAX_MSG_SIZE - (uintptr_t)numBytes;
    return dataAddr;
}

void CSL_proxyAccessTarget( CSL_ProxyCfg *pProxyCfg, uint32_t targetNum, uint32_t threadNum, uint8_t *pData, uint32_t numBytes, CSL_ProxyMemAccessCbFxnPtr fpMemAccess )
{
    uintptr_t proxyDataAddr;

    proxyDataAddr = CSL_proxyGetDataAddr( pProxyCfg, targetNum, threadNum, numBytes );
    fpMemAccess( proxyDataAddr, pData, 1, numBytes );
}
