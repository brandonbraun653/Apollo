/**
 * @file  csl_vim.c
 *
 * @brief
 *  C implementation file for the VIM module CSL-FL.
 *
 *  Contains the different control command and status query functions definitions
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
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
#include <stdint.h>
#include <csl_vim.h>
#include <csl_error.h>
#include <csl_types.h>

#define         CSL_MCU_ARMSS_VIM_NULL_ADDR           ((void *) 0 )

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetRevision( CSL_vimRegs *pRegs )
{
    void       *pChkRegs = (void *) pRegs;
    uint32_t    regVal = ((uint32_t) (0u));

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
          regVal   = CSL_REG32_RD (&pRegs->PID );
    }
    return (regVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetNumIntrs( CSL_vimRegs *pRegs )
{
    void       *pChkRegs = (void *) pRegs;
    uint32_t    regVal = ((uint32_t) (0u));

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        regVal =  CSL_REG32_FEXT( &pRegs->INFO, VIM_INFO_INTERRUPTS );
    }
    return (regVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1698)
 *  Design: did_csl_vim_configure
 */
int32_t CSL_vimCfgIntr( CSL_vimRegs *pRegs, uint32_t intrNum, uint32_t pri, CSL_VimIntrMap intrMap, CSL_VimIntrType intrType, uint32_t vecAddr )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, regVal, regMask;
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        retVal = CSL_EFAIL;
    }

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    if( (groupNum < CSL_VIM_MAX_INTR_GROUPS)              &&
        (pri <= CSL_VIM_PRI_INT_VAL_MAX)                  &&
        (intrMap <= CSL_VIM_INTR_MAP_FIQ)                 &&
        (intrType <= CSL_VIM_INTR_TYPE_PULSE)             &&
        ((vecAddr & CSL_VIM_VEC_INT_VAL_MASK) == vecAddr) &&
        (retVal == CSL_PASS) )
    {
        bitNum = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);

        /* Configure INTMAP */
        regMask = (uint32_t)(1U) << bitNum;
        regVal = CSL_REG32_RD( &pRegs->GRP[groupNum].INTMAP );
        regVal &= ~regMask;
        regVal |= intrMap;
        CSL_REG32_WR( &pRegs->GRP[groupNum].INTMAP, regVal );

        /* Configure INTTYPE */
        regMask = (uint32_t)(1U) << bitNum;
        regVal = CSL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE );
        regVal &= ~regMask;
        regVal |= intrType;
        CSL_REG32_WR( &pRegs->GRP[groupNum].INTTYPE, regVal );

        /* Configure PRI */
        CSL_REG32_WR( &pRegs->PRI[intrNum].INT, CSL_FMK( VIM_PRI_INT_VAL, pri ) );

        /* Configure VEC */
        CSL_REG32_WR( &pRegs->VEC[intrNum].INT, vecAddr );
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_readback
 */
int32_t CSL_vimVerifyCfgIntr( CSL_vimRegs *pRegs, uint32_t intrNum, uint32_t pri, CSL_VimIntrMap intrMap, CSL_VimIntrType intrType, uint32_t vecAddr )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum;
    uint32_t intrMapVal, intrTypeVal, priVal, vecVal;
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        retVal = CSL_EFAIL;
    }

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    if( (groupNum < CSL_VIM_MAX_INTR_GROUPS)              &&
        (pri <= CSL_VIM_PRI_INT_VAL_MAX)                  &&
        (intrMap <= CSL_VIM_INTR_MAP_FIQ)                 &&
        (intrType <= CSL_VIM_INTR_TYPE_PULSE)             &&
        ((vecAddr & CSL_VIM_VEC_INT_VAL_MASK) == vecAddr) &&
        (retVal == CSL_PASS) )
    {
        bitNum = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);

        /* Read INTMAP */
        intrMapVal  = CSL_REG32_RD( &pRegs->GRP[groupNum].INTMAP );
        /* Get the interrupt map value */
        intrMapVal  = intrMapVal >> bitNum;
        intrMapVal &= (uint32_t)(0x1U);

        /* Read INTTYPE */
        intrTypeVal  = CSL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE );
        /* Get the interrupt type value */
        intrTypeVal  = intrTypeVal >> bitNum;
        intrTypeVal &= (uint32_t)(0x1U);

        /* Read PRI */
        priVal = CSL_REG32_RD( &pRegs->PRI[intrNum].INT);

        /* Read VEC */
        vecVal = CSL_REG32_RD( &pRegs->VEC[intrNum].INT);
    }
    else
    {
        retVal = CSL_EFAIL;
    }

    if (retVal != CSL_EFAIL)
    {
        /* verify if interrupt map bit matches */
        if (intrMapVal != intrMap)
        {
            retVal = CSL_EFAIL;
        }
    }

    if (retVal != CSL_EFAIL)
    {
        /* verify if interrupt type bit matches */
        if (intrTypeVal != (uint32_t)intrType)
        {
            retVal = CSL_EFAIL;
        }
    }

    if (retVal != CSL_EFAIL)
    {
        /* verify the read values for every register */
        if (priVal != pri)
        {
            retVal = CSL_EFAIL;
        }
    }

    if (retVal != CSL_EFAIL)
    {
        /* verify the read values for every register */
        if (vecVal != vecAddr)
        {
            retVal = CSL_EFAIL;
        }
    }

    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1702)
 *  Design: did_csl_vim_ded_configure
 */
void CSL_vimSetDedVectorAddr( CSL_vimRegs *pRegs, uint32_t dedVectorAddr )
{
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        CSL_REG32_WR( &pRegs->DEDVEC, (dedVectorAddr & CSL_VIM_DEDVEC_ADDR_MASK) );
    }
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
int32_t CSL_vimGetDedVectorAddr( CSL_vimRegs *pRegs, uint32_t *pDedVectorAddr )
{
    int32_t     retVal = CSL_PASS;
    uint32_t    dedVecAddr;
    void       *pChkDedVecAddr = (void *) pDedVectorAddr;
    void       *pChkRegs = (void *) pRegs;
    if ( (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR) ||
         (pChkDedVecAddr == CSL_MCU_ARMSS_VIM_NULL_ADDR))
    {
        retVal = CSL_EFAIL;
    }

    if (retVal == CSL_PASS)
    {
        dedVecAddr = CSL_REG32_RD( &pRegs->DEDVEC);
       *pDedVectorAddr = dedVecAddr;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
int32_t CSL_vimGetActivePendingIntr( CSL_vimRegs *pRegs, CSL_VimIntrMap intrMap, uint32_t *pIntrNum, uint32_t *pPri )
{
    int32_t  retVal = CSL_PASS;
    uint32_t regVal;
    void       *pChkIntNum = (void *) pIntrNum;
    void       *pChkRegs = (void *) pRegs;
    void       *pChkPri = (void *) pPri;

    if ( (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR) )
    {
        retVal = CSL_EFAIL;
    }

    if (retVal == CSL_EFAIL)
    {
       /* No action - API action fails */
    }
    else if( intrMap == CSL_VIM_INTR_MAP_IRQ )
    {
        regVal = CSL_REG32_RD( &pRegs->ACTIRQ );
    }
    else if( intrMap == CSL_VIM_INTR_MAP_FIQ )
    {
        regVal = CSL_REG32_RD( &pRegs->ACTFIQ );
    }
    else
    {
        retVal = CSL_EFAIL;
    }

    if( retVal == CSL_PASS )
    {
        /*---------------------------------------------------------------------
         * Note that the CSL FIELD macros are the same for the ACTIRQ and
         * ACTFIQ registers, so we will just use the ACTIRQ ones
         *-------------------------------------------------------------------*/
        if( CSL_FEXT( regVal, VIM_ACTIRQ_VALID ) == CSL_VIM_ACTIRQ_VALID_VAL_TRUE )
        {
             if ( (pChkIntNum != CSL_MCU_ARMSS_VIM_NULL_ADDR) )
             {
                 *pIntrNum     = CSL_FEXT( regVal, VIM_ACTIRQ_NUM );
             }
             if ( (pChkPri != CSL_MCU_ARMSS_VIM_NULL_ADDR) )
             {
                 *pPri         = CSL_FEXT( regVal, VIM_ACTIRQ_PRI );
             }
        }
        else
        {
            retVal = CSL_EFAIL;        /* No interrupt is pending */
        }
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1698)
 *  Design: did_csl_vim_configure
 */
int32_t CSL_vimSetIntrEnable( CSL_vimRegs *pRegs, uint32_t intrNum, bool bEnable )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, mask;
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        /* No actions - API fails functionality */
        retVal = CSL_EFAIL;
    }

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    if( ( groupNum < CSL_VIM_MAX_INTR_GROUPS ) &&
        ( retVal   == CSL_PASS) )
    {
        bitNum = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);
        mask   = (((uint32_t)(1U)) << bitNum);
        if( bEnable == (bool) true)
        {
            CSL_REG32_WR(&pRegs->GRP[groupNum].INTR_EN_SET, mask );
        }
        else
        {
            CSL_REG32_WR( &pRegs->GRP[groupNum].INTR_EN_CLR, mask );
        }
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
int32_t CSL_vimGetIntrType( CSL_vimRegs *pRegs, uint32_t intrNum )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, regVal;
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        /* No actions - API fails functionality */
        retVal = CSL_EFAIL;
    }

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    if( (groupNum < CSL_VIM_MAX_INTR_GROUPS ) &&
        (retVal == CSL_PASS) )
    {
        bitNum = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);
        regVal = CSL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE);
        regVal  = (((regVal) >> bitNum) & 1U);
        if (regVal == 1u)
        {
            retVal = ((int32_t)(1));
        }
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetIrqVectorAddress( CSL_vimRegs *pRegs )
{
    void       *pChkRegs = (void *) pRegs;
    uint32_t    regVal = ((uint32_t) (0u));

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        regVal = (uint32_t)CSL_REG32_RD( &pRegs->IRQVEC );
    }
    return (regVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetFiqVectorAddress( CSL_vimRegs *pRegs )
{
    void       *pChkRegs = (void *) pRegs;
    uint32_t    regVal = ((uint32_t) (0u));

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        regVal = (uint32_t)CSL_REG32_RD( &pRegs->FIQVEC );
    }
    return (regVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetGroupsIntrPending( CSL_vimRegs *pRegs, CSL_VimIntrMap intrMap )
{
    uint32_t    groupsStatus = ((uint32_t) (0u));
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        if( intrMap == CSL_VIM_INTR_MAP_IRQ )
        {
            groupsStatus = CSL_REG32_RD( &pRegs->IRQGSTS );
        }
        else
        {
            groupsStatus = CSL_REG32_RD( &pRegs->FIQGSTS );
        }
    }
    return groupsStatus;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
uint32_t CSL_vimGetGroupIntrPending(
                                                  CSL_vimRegs   *pRegs,
                                                  CSL_VimIntrMap intrMap,
                                                  uint32_t       groupNum,
                                                  bool           bMasked
)
{
    uint32_t    groupStatus = ((uint32_t) (0u));
    void       *pChkRegs = (void *) pRegs;

    if ( (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR) &&
         (groupNum < CSL_VIM_MAX_INTR_GROUPS ) )
    {
        if( bMasked == (bool) true)
        {
            if( intrMap == CSL_VIM_INTR_MAP_IRQ )
            {
                groupStatus = CSL_REG32_RD( &pRegs->GRP[groupNum].IRQSTS );
            }
            else if( intrMap == CSL_VIM_INTR_MAP_FIQ )
            {
                groupStatus = CSL_REG32_RD( &pRegs->GRP[groupNum].FIQSTS );
            }
            else
            {
                groupStatus = CSL_REG32_RD( &pRegs->GRP[groupNum].STS );
            }
        }
        else
        {
            groupStatus = CSL_REG32_RD( &pRegs->GRP[groupNum].RAW );
        }
    }
    return groupStatus;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1698)
 *  Design: did_csl_vim_configure
 */
int32_t CSL_vimSetIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, mask;
    void       *pChkRegs = (void *) pRegs;
    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;

    if ( (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR) &&
         (groupNum < CSL_VIM_MAX_INTR_GROUPS ) )
    {
        bitNum = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);
        mask   = (((uint32_t)(1U)) << bitNum);
        CSL_REG32_WR( &pRegs->GRP[groupNum].RAW, mask );
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1698)
 *  Design: did_csl_vim_configure
 */
int32_t CSL_vimClrIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, mask;
    void       *pChkRegs = (void *) pRegs;

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    bitNum   = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);
    mask   = (((uint32_t)(1U)) << bitNum);

    if ( (pChkRegs != CSL_MCU_ARMSS_VIM_NULL_ADDR) &&
         (groupNum < CSL_VIM_MAX_INTR_GROUPS ) )
    {
        CSL_REG32_WR( &pRegs->GRP[groupNum].STS, mask );
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1698)
 *  Design: did_csl_vim_configure
 */
int32_t CSL_vimAckIntr( CSL_vimRegs *pRegs, CSL_VimIntrMap intrMap )
{
    int32_t  retVal = CSL_PASS;
    void    *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        /* No actions - API fails functionality */
        retVal = CSL_EFAIL;
    }
    else if( intrMap == CSL_VIM_INTR_MAP_IRQ )
    {
        CSL_REG32_WR( &pRegs->IRQVEC, ((uint32_t) (0u)) );
    }
    else if( intrMap == CSL_VIM_INTR_MAP_FIQ )
    {
        CSL_REG32_WR( &pRegs->FIQVEC, ((uint32_t) (0u)) );
    }
    else
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1699)
 *  Design: did_csl_vim_read
 */
int32_t CSL_vimReadBackStaticRegs( CSL_vimRegs *pRegs, CSL_vimStaticRegs *pStaticRegs)
{
    int32_t  retVal = CSL_PASS;
    uint32_t i, maxInts;
    void    *pChkRegs = (void *) pRegs;

    if ( (pChkRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR) ||
         (pStaticRegs == CSL_MCU_ARMSS_VIM_NULL_ADDR) )
    {
        /* No actions - API fails to read back */
        retVal = CSL_EFAIL;
    }

    if (retVal == CSL_PASS)
    {
        pStaticRegs->PID  = CSL_REG32_RD(&pRegs->PID);
        pStaticRegs->INFO = CSL_REG32_RD(&pRegs->INFO);
        pStaticRegs->IRQVEC = CSL_REG32_RD(&pRegs->IRQVEC);
        pStaticRegs->FIQVEC = CSL_REG32_RD(&pRegs->FIQVEC);

        for (i = ((uint32_t) (0u)); i < CSL_VIM_MAX_INTR_GROUPS; i++)
        {
            pStaticRegs->GRP[i].INTMAP      = CSL_REG32_RD(&pRegs->GRP[i].INTMAP);
            pStaticRegs->GRP[i].INTR_EN_CLR = CSL_REG32_RD(&pRegs->GRP[i].INTR_EN_CLR);
            pStaticRegs->GRP[i].INTR_EN_SET = CSL_REG32_RD(&pRegs->GRP[i].INTR_EN_SET);
            pStaticRegs->GRP[i].INTTYPE     = CSL_REG32_RD(&pRegs->GRP[i].INTTYPE);
        }

        maxInts = (CSL_VIM_MAX_INTR_GROUPS * CSL_VIM_NUM_INTRS_PER_GROUP);
        for (i = ((uint32_t) (0u)); i < maxInts; i++)
        {
            pStaticRegs->PRI[i].INT         = CSL_REG32_RD(&pRegs->PRI[i].INT);
            pStaticRegs->VEC[i].INT         = CSL_REG32_RD(&pRegs->VEC[i].INT);
        }
    }

    return (retVal);
}

/* nothing past this point */
