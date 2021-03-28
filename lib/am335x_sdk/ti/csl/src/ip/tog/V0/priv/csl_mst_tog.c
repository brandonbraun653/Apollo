/**
 * @file  csl_mst_tog.c
 *
 * @brief
 *  Implementation file for the VBUSM Master Timeout Gasket module CSL.
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
 *    Neither the name of Texas Instruments Incorpomst_toged nor the names of
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

#include <ti/csl/csl_tog.h>
#include <ti/csl/csl_types.h>

/* VBUSM Master Timeout control MMR fields */
#define CSL_MST_TOG_VAL_MASK        (0x00000007U)
#define CSL_MST_TOG_VAL_SHIFT       (0x00000000U)
#define CSL_MST_TOG_EN_MASK         (0x00008000U)
#define CSL_MST_TOG_EN_SHIFT        (0x0000000FU)
#define CSL_MST_TOG_FORCE_MASK      (0x00FF0000U)
#define CSL_MST_TOG_FORCE_SHIFT     (0x00000010U)

/* Magic value used to force a timeout */
#define CSL_MST_TOG_FORCE_KEY       ((uint32_t) 0x95U)

int32_t CSL_mstTogSetTimeoutVal( uintptr_t baseAddr, CSL_MstTogVal timeoutVal )
{
    int32_t retVal = CSL_EFAIL;
    uint32_t regVal;
    
    regVal = CSL_REG32_RD( baseAddr );
    /* Timeout value can only be changed when enable==0 */
    if( CSL_FEXT( regVal, MST_TOG_EN ) == 0U )
    {
        CSL_FINS( regVal, MST_TOG_VAL, timeoutVal );
        CSL_REG32_WR( baseAddr, regVal );
        retVal = CSL_PASS;
    }
    return retVal;
}

void CSL_mstTogStart( uintptr_t baseAddr )
{
    CSL_REG32_FINS( baseAddr, MST_TOG_EN, (uint32_t)1U );
}

void CSL_mstTogStop( uintptr_t baseAddr )
{
    CSL_REG32_FINS( baseAddr, MST_TOG_EN, (uint32_t)0U );
}

int32_t CSL_mstTogForceTimeout( uintptr_t baseAddr )
{
    int32_t retVal = CSL_EFAIL;
    uint32_t regVal;
    
    regVal = CSL_REG32_RD( baseAddr );
    /* Forcing a timeout is only applicable when enable==1 */
    if( CSL_FEXT( regVal, MST_TOG_EN ) == 1U )
    {
        CSL_FINS( regVal, MST_TOG_FORCE, CSL_MST_TOG_FORCE_KEY );
        CSL_REG32_WR( baseAddr, regVal );
        retVal = CSL_PASS;
    }
    return retVal;
}

void CSL_mstTogReset( uintptr_t baseAddr )
{
    uint32_t regVal;
    
    regVal = CSL_REG32_RD( baseAddr );
    CSL_FINS( regVal, MST_TOG_FORCE, (uint32_t)0U );
    CSL_FINS( regVal, MST_TOG_EN,    (uint32_t)0U );
    CSL_REG32_WR( baseAddr, regVal );
}
