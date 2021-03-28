/**
 * @file  csl_intr_router.c
 *
 * @brief
 *  Implementation file for the Intr_Router module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2018, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorpopated nor the names of
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
#include <ti/csl/csl_intr_router.h>
#include <stdbool.h>

/*=============================================================================
 *  CSL-F functions
 *===========================================================================*/

uint32_t CSL_intrRouterGetRevision(const CSL_IntrRouterCfg *pCfg)
{
    return CSL_REG32_RD(&pCfg->pIntrRouterRegs->PID);
}

int32_t CSL_intrRouterSetIntdBypassEnable(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bBypassEnable)
{
    int32_t retVal = 0;

    if(outputIntrNum < pCfg->numOutputIntrs)
    {
        uint32_t regVal = 0;
        if( bBypassEnable == (bool)true )
        {
            regVal = 1U;
        }
        CSL_REG32_FINS(&pCfg->pIntrRouterRegs->MUXCNTL[outputIntrNum], INTR_ROUTER_CFG_MUXCNTL_BYPASS, regVal);
    }
    else
    {
        retVal = -1;
    }
    return retVal;
}

#define INTR_ROUTER_CFG_MUXCNTL_INT_ENABLE      ((uint32_t)1U << 16)

int32_t CSL_intrRouterCfgMux(CSL_IntrRouterCfg *pCfg, uint32_t inputIntrNum, uint32_t outputIntrNum)
{
    int32_t retVal = 0;

    if((outputIntrNum < pCfg->numOutputIntrs) && (inputIntrNum < pCfg->numInputIntrs))
    {
        uint32_t regVal;

        /*---------------------------------------------------------------------
         *  An interrupt enable bit (bit 16) was added to version 1.0.16.0
         *  of the interrupt router that enables generation of the external
         *  interrupt. The following sequence is required when configuring
         *  the mux to insure glitch-free operation.
         *
         *  Note that disabling/enabling the interrupt has no affect on ealier
         *  versions of the interrupt router, so we perform these operations
         *  regardless of IP version.
         *-------------------------------------------------------------------*/
        regVal = CSL_REG32_RD( &pCfg->pIntrRouterRegs->MUXCNTL[outputIntrNum] );
        /* Disable interrupt output */
        regVal &= ~INTR_ROUTER_CFG_MUXCNTL_INT_ENABLE;
        CSL_REG32_WR( &pCfg->pIntrRouterRegs->MUXCNTL[outputIntrNum], regVal );
        /* Configure mux value */
        CSL_FINS( regVal, INTR_ROUTER_CFG_MUXCNTL_ENABLE, inputIntrNum );
        CSL_REG32_WR( &pCfg->pIntrRouterRegs->MUXCNTL[outputIntrNum], regVal );
        /* Enable interrupt output */
        regVal |= INTR_ROUTER_CFG_MUXCNTL_INT_ENABLE;
        CSL_REG32_WR( &pCfg->pIntrRouterRegs->MUXCNTL[outputIntrNum], regVal );
    }
    else
    {
        retVal = -1;
    }
    return retVal;
}

int32_t CSL_intrRouterSetIntrEnable(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bEnable)
{
    int32_t retVal = 0;

    if( pCfg->pIntdRegs != NULL)
    {
        if(outputIntrNum < pCfg->numOutputIntrs)
        {
            if( bEnable == (bool)true )
            {
                CSL_REG32_FINS( &pCfg->pIntdRegs->INTR[outputIntrNum].ENABLE_SET, INTR_ROUTER_INTD_CFG_INTR_ENABLE_SET_VAL, 1U );
            }
            else
            {
                CSL_REG32_FINS( &pCfg->pIntdRegs->INTR[outputIntrNum].ENABLE_CLR, INTR_ROUTER_INTD_CFG_INTR_ENABLE_CLR_VAL, 1U );
            }
        }
        else
        {
            retVal = -1;    /* outputIntrNum out of range */
        }
    }
    else
    {
        retVal = -2;        /* Function is not supported */
    }
    return retVal;
}

int32_t CSL_intrRouterIsIntrPending(const CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum)
{
    int32_t retVal = 0;

    if( pCfg->pIntdRegs != NULL )
    {
        if(outputIntrNum < pCfg->numOutputIntrs)
        {
            retVal = (int32_t)CSL_REG32_FEXT( &pCfg->pIntdRegs->INTR[outputIntrNum].STATUS_SET, INTR_ROUTER_INTD_CFG_INTR_STATUS_SET_VAL );
        }
        else
        {
            retVal = -1;    /* outputIntrNum out of range */
        }
    }
    else
    {
        retVal = -2;        /* Function is not supported */
    }
    return retVal;
}

int32_t CSL_intrRouterSetIntrPendingStatus(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bPend)
{
    int32_t retVal = 0;

    if( pCfg->pIntdRegs != NULL )
    {
        if(outputIntrNum < pCfg->numOutputIntrs)
        {
            if( bPend == (bool)true )
            {
                CSL_REG32_FINS( &pCfg->pIntdRegs->INTR[outputIntrNum].STATUS_SET, INTR_ROUTER_INTD_CFG_INTR_STATUS_SET_VAL, 1U );
            }
            else
            {
                CSL_REG32_FINS( &pCfg->pIntdRegs->INTR[outputIntrNum].STATUS_CLR, INTR_ROUTER_INTD_CFG_INTR_STATUS_CLR_VAL, 1U );
            }
        }
        else
        {
            retVal = -1;    /* outputIntrNum out of range */
        }
    }
    else
    {
        retVal = -2;        /* Function is not supported */
    }
    return retVal;
}

int32_t CSL_intrRouterAckIntr(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum)
{
    int32_t retVal = 0;

    if( pCfg->pIntdRegs != NULL )
    {
        if(outputIntrNum < pCfg->numOutputIntrs)
        {
            CSL_REG32_FINS( &pCfg->pIntdRegs->INTR[outputIntrNum].EOI, INTR_ROUTER_INTD_CFG_INTR_EOI_VAL, 1U );
        }
        else
        {
            retVal = -1;    /* outputIntrNum out of range */
        }
    }
    else
    {
        retVal = -2;        /* Function is not supported */
    }
    return retVal;
}
