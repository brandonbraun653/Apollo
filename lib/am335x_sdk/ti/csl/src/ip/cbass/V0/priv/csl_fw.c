/**
 * @file csl_fw.c
 *
 * @brief
 * CSL-FL implementation file for the fw module.
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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
#include <ti/csl/cslr_cbass.h>
#include <ti/csl/csl_fw.h>
#include <ti/csl/csl_types.h>

uint32_t CSL_fwGetRevision( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    uint32_t retVal;
    retVal = CSL_REG32_RD( &pCbass_GlbRegs->PID);
    return retVal;
}

bool CSL_fwIsExceptionLoggingDisable( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F ) == CSL_FW_EXCEPTIONLOGGING_DISABLE )
    {
        retVal=true;
    }
    return retVal;
}

bool CSL_fwIsExceptionLoggingEnable( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F ) == CSL_FW_EXCEPTIONLOGGING_ENABLE )
    {
        retVal=true;
    }
    return retVal;
}

int32_t CSL_fwConfigureExceptionLogging( CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionLogging_t value )
{
    CSL_REG32_FINS( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F , value);
    return CSL_PASS;
}

bool CSL_fwIsExceptionLogPendingDisable( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND ) == CSL_FW_EXCEPTIONLOGPENDING_DISABLE )
    {
        retVal=true;
    }
    return retVal;
}

bool CSL_fwIsExceptionLogPendingEnable( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND ) == CSL_FW_EXCEPTIONLOGPENDING_ENABLE )
    {
        retVal=true;
    }
    return retVal;
}

int32_t CSL_fwConfigureExceptionLogPending( CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionLogPending_t value )
{
    CSL_REG32_FINS( &pCbass_GlbRegs->EXCEPTION_LOGGING_CONTROL, CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND , value);
    return CSL_PASS;
}

int32_t CSL_fwGetExceptionData( CSL_cbass_glbRegs *pCbass_GlbRegs, CSL_FwExceptionData_t *pCSL_FwExceptionData_t )
{
    pCSL_FwExceptionData_t->destId = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_HEADER0, CBASS_GLB_EXCEPTION_LOGGING_HEADER0_DEST_ID );
    pCSL_FwExceptionData_t->srcId = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_HEADER0, CBASS_GLB_EXCEPTION_LOGGING_HEADER0_SRC_ID );
    pCSL_FwExceptionData_t->typeF = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_HEADER0, CBASS_GLB_EXCEPTION_LOGGING_HEADER0_TYPE_F );
    pCSL_FwExceptionData_t->code = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_HEADER1, CBASS_GLB_EXCEPTION_LOGGING_HEADER1_CODE );
    pCSL_FwExceptionData_t->group = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_HEADER1, CBASS_GLB_EXCEPTION_LOGGING_HEADER1_GROUP );

    uint32_t var_0;
    uint32_t var_1;
    uint64_t var_2;
    var_0 = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA0, CBASS_GLB_EXCEPTION_LOGGING_DATA0_ADDR_L );
    var_1 = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA1, CBASS_GLB_EXCEPTION_LOGGING_DATA1_ADDR_H );
    var_2 = (((uint64_t)var_1)<<32u) | (var_0);
    pCSL_FwExceptionData_t->addr = var_2;

    pCSL_FwExceptionData_t->privId = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_ID );
    pCSL_FwExceptionData_t->secure = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_SECURE );
    pCSL_FwExceptionData_t->priv = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV );
    pCSL_FwExceptionData_t->cacheable = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_CACHEABLE );
    pCSL_FwExceptionData_t->debug = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_DEBUG );
    pCSL_FwExceptionData_t->read = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_READ );
    pCSL_FwExceptionData_t->write = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_WRITE );
    pCSL_FwExceptionData_t->routeid = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA2, CBASS_GLB_EXCEPTION_LOGGING_DATA2_ROUTEID );
    pCSL_FwExceptionData_t->bytecnt = CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_LOGGING_DATA3, CBASS_GLB_EXCEPTION_LOGGING_DATA3_BYTECNT );

    return CSL_PASS;
}

bool CSL_fwIsExceptionSet( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_PEND_SET, CBASS_GLB_EXCEPTION_PEND_SET_PEND_SET ) == CSL_FW_EXCEPTION_SET )
    {
        retVal=true;
    }
    return retVal;
}

bool CSL_fwIsExceptionCleared( CSL_cbass_glbRegs *pCbass_GlbRegs )
{
    bool retVal=false;
    if ( CSL_REG32_FEXT( &pCbass_GlbRegs->EXCEPTION_PEND_CLEAR, CBASS_GLB_EXCEPTION_PEND_CLEAR_PEND_CLR ) == CSL_FW_EXCEPTION_CLEARED )
    {
        retVal=true;
    }
    return retVal;
}

int32_t CSL_fwSetException( CSL_cbass_glbRegs *pCbass_GlbRegs)
{
    CSL_REG32_FINS( &pCbass_GlbRegs->EXCEPTION_PEND_SET, CBASS_GLB_EXCEPTION_PEND_SET_PEND_SET , CSL_FW_EXCEPTION_SET);
    return CSL_PASS;
}

int32_t CSL_fwClearException( CSL_cbass_glbRegs *pCbass_GlbRegs)
{
    CSL_REG32_FINS( &pCbass_GlbRegs->EXCEPTION_PEND_CLEAR, CBASS_GLB_EXCEPTION_PEND_CLEAR_PEND_CLR , CSL_FW_EXCEPTION_CLEAR);
    return CSL_PASS;
}

bool CSL_fwIsRegionEnable( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex )
{
    bool retVal=false;
    if ( regionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionEpIndex].REGION[regionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE ) == CSL_FW_REGION_ENABLE )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

bool CSL_fwIsRegionDisable( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex )
{
    bool retVal=false;
    if ( regionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionEpIndex].REGION[regionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE ) == CSL_FW_REGION_DISABLE )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

int32_t CSL_fwConfigureRegion( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionEpIndex, uint32_t regionRegionIndex, CSL_FwRegion_t value )
{
    if ( regionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionEpIndex].REGION[regionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE , value);
        }
    }
    return CSL_PASS;
}

bool CSL_fwIsRegionLockEnable( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex )
{
    bool retVal=false;
    if ( regionLockEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionLockRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionLockEpIndex].REGION[regionLockRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_LOCK ) == CSL_FW_REGIONLOCK_ENABLE )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

bool CSL_fwIsRegionLockDisable( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex )
{
    bool retVal=false;
    if ( regionLockEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionLockRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionLockEpIndex].REGION[regionLockRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_LOCK ) == CSL_FW_REGIONLOCK_DISABLE )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

int32_t CSL_fwConfigureRegionLock( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionLockEpIndex, uint32_t regionLockRegionIndex, CSL_FwRegionLock_t value )
{
    if ( regionLockEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionLockRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionLockEpIndex].REGION[regionLockRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_LOCK , value);
        }
    }
    return CSL_PASS;
}

bool CSL_fwIsBackgroundRegionSet( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex )
{
    bool retVal=false;
    if ( backgroundRegionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( backgroundRegionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[backgroundRegionEpIndex].REGION[backgroundRegionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_BACKGROUND ) == CSL_FW_BACKGROUNDREGION_SET )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

bool CSL_fwIsBackgroundRegionClear( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex )
{
    bool retVal=false;
    if ( backgroundRegionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( backgroundRegionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[backgroundRegionEpIndex].REGION[backgroundRegionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_BACKGROUND ) == CSL_FW_BACKGROUNDREGION_CLEAR )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

int32_t CSL_fwConfigureBackgroundRegion( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t backgroundRegionEpIndex, uint32_t backgroundRegionRegionIndex, CSL_FwBackgroundRegion_t value )
{
    if ( backgroundRegionEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( backgroundRegionRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            CSL_REG32_FINS( &pCbass_FwRegs->EP[backgroundRegionEpIndex].REGION[backgroundRegionRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_BACKGROUND , value);
        }
    }
    return CSL_PASS;
}

bool CSL_fwIsCacheableTransIgnore( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex )
{
    bool retVal=false;
    if ( cacheableTransEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( cacheableTransRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[cacheableTransEpIndex].REGION[cacheableTransRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_CACHE_MODE ) == CSL_FW_CACHEABLETRANS_IGNORE )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

bool CSL_fwIsCacheableTransCheck( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex )
{
    bool retVal=false;
    if ( cacheableTransEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( cacheableTransRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( CSL_REG32_FEXT( &pCbass_FwRegs->EP[cacheableTransEpIndex].REGION[cacheableTransRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_CACHE_MODE ) == CSL_FW_CACHEABLETRANS_CHECK )
            {
                retVal=true;
            }
        }
    }
    return retVal;
}

int32_t CSL_fwConfigureCacheableTrans( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t cacheableTransEpIndex, uint32_t cacheableTransRegionIndex, CSL_FwCacheableTrans_t value )
{
    if ( cacheableTransEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( cacheableTransRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            CSL_REG32_FINS( &pCbass_FwRegs->EP[cacheableTransEpIndex].REGION[cacheableTransRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_CACHE_MODE , value);
        }
    }
    return CSL_PASS;
}

int32_t CSL_fwGetRegionPermissions( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionPermissionsEpIndex, uint32_t regionPermissionsRegionIndex, uint32_t regionPermissionsPermissionIndex, CSL_FwRegionPermissions_t *pCSL_FwRegionPermissions_t )
{
    if ( regionPermissionsEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionPermissionsRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( regionPermissionsPermissionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION_PERMISSION )
            {
                pCSL_FwRegionPermissions_t->secSupvWrite = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE );
                pCSL_FwRegionPermissions_t->secSupvRead = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ );
                pCSL_FwRegionPermissions_t->secSupvCacheable = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE );
                pCSL_FwRegionPermissions_t->secSupvDebug = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG );
                pCSL_FwRegionPermissions_t->secUserWrite = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE );
                pCSL_FwRegionPermissions_t->secUserRead = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ );
                pCSL_FwRegionPermissions_t->secUserCacheable = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE );
                pCSL_FwRegionPermissions_t->secUserDebug = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG );
                pCSL_FwRegionPermissions_t->nonsecSupvWrite = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE );
                pCSL_FwRegionPermissions_t->nonsecSupvRead = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ );
                pCSL_FwRegionPermissions_t->nonsecSupvCacheable = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE );
                pCSL_FwRegionPermissions_t->nonsecSupvDebug = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG );
                pCSL_FwRegionPermissions_t->nonsecUserWrite = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE );
                pCSL_FwRegionPermissions_t->nonsecUserRead = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ );
                pCSL_FwRegionPermissions_t->nonsecUserCacheable = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE );
                pCSL_FwRegionPermissions_t->nonsecUserDebug = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG );
                pCSL_FwRegionPermissions_t->privId = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], CBASS_FW_EP_REGION_PERMISSION_PRIV_ID );
            }
        }
    }
    return CSL_PASS;
}

int32_t CSL_fwSetRegionPermissions( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionPermissionsEpIndex, uint32_t regionPermissionsRegionIndex, uint32_t regionPermissionsPermissionIndex, CSL_FwRegionPermissions_t *pCSL_FwRegionPermissions_t )
{
    if ( regionPermissionsEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionPermissionsRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            if ( regionPermissionsPermissionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION_PERMISSION )
            {
                uint32_t tmp;
                tmp = 0;
                tmp|=( pCSL_FwRegionPermissions_t->secSupvWrite << 0u );
                tmp|=( pCSL_FwRegionPermissions_t->secSupvRead << 1u );
                tmp|=( pCSL_FwRegionPermissions_t->secSupvCacheable << 2u );
                tmp|=( pCSL_FwRegionPermissions_t->secSupvDebug << 3u );
                tmp|=( pCSL_FwRegionPermissions_t->secUserWrite << 4u );
                tmp|=( pCSL_FwRegionPermissions_t->secUserRead << 5u );
                tmp|=( pCSL_FwRegionPermissions_t->secUserCacheable << 6u );
                tmp|=( pCSL_FwRegionPermissions_t->secUserDebug << 7u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecSupvWrite << 8u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecSupvRead << 9u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecSupvCacheable << 10u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecSupvDebug << 11u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecUserWrite << 12u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecUserRead << 13u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecUserCacheable << 14u );
                tmp|=( pCSL_FwRegionPermissions_t->nonsecUserDebug << 15u );
                tmp|=( pCSL_FwRegionPermissions_t->privId << 16u );
                CSL_REG32_WR( &pCbass_FwRegs->EP[regionPermissionsEpIndex].REGION[regionPermissionsRegionIndex].PERMISSION[regionPermissionsPermissionIndex], tmp );
            }
        }
    }
    return CSL_PASS;
}

int32_t CSL_fwGetRegionAddrRange( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionAddrRangeEpIndex, uint32_t regionAddrRangeRegionIndex, CSL_FwRegionAddrRange_t *pCSL_FwRegionAddrRange_t )
{
    if ( regionAddrRangeEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionAddrRangeRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            uint32_t var_0;
            uint32_t var_1;
            uint32_t var_2;
            uint64_t var_3;
            var_0 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_L, CBASS_FW_EP_REGION_START_ADDR_L_ADDR_LSB );
            var_1 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_L, CBASS_FW_EP_REGION_START_ADDR_L_ADDR_L );
            var_2 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_H, CBASS_FW_EP_REGION_START_ADDR_H_ADDR_H );
            var_3 = (((uint64_t)var_2)<<32u) | (((uint64_t)var_1)<<12u) | (var_0);
            pCSL_FwRegionAddrRange_t->startAddr = var_3;
            var_0 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_L, CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_LSB );
            var_1 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_L, CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_L );
            var_2 = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_H, CBASS_FW_EP_REGION_END_ADDR_H_END_ADDR_H );
            var_3 = (((uint64_t)var_2)<<32u) | (((uint64_t)var_1)<<12u) | (var_0);
            pCSL_FwRegionAddrRange_t->endAddr = var_3;
        }
    }
    return CSL_PASS;
}

int32_t CSL_fwSetRegionAddrRange( CSL_cbass_fwRegs *pCbass_FwRegs, uint32_t regionAddrRangeEpIndex, uint32_t regionAddrRangeRegionIndex, CSL_FwRegionAddrRange_t *pCSL_FwRegionAddrRange_t )
{
    if ( regionAddrRangeEpIndex < CSL_FW_NUM_CBASS_FW_EP )
    {
        if ( regionAddrRangeRegionIndex < CSL_FW_NUM_CBASS_FW_EP_REGION )
        {
            // Save the value of the enable field to a temporary.
            // We need this to restore the field value after the update.
            uint32_t tmp_enable;
            tmp_enable = CSL_REG32_FEXT( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE);
            // Execute pre-condition: Disable the firewall region
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE , 0U);

            uint32_t var_0;
            uint32_t var_1;
            uint32_t var_2;
            uint64_t var_3;
            var_3 = pCSL_FwRegionAddrRange_t->startAddr;
            var_0 = (uint32_t)(var_3);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_L, CBASS_FW_EP_REGION_START_ADDR_L_ADDR_LSB, var_0 );
            var_1 = (uint32_t)(var_3 >> 12);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_L, CBASS_FW_EP_REGION_START_ADDR_L_ADDR_L, var_1 );
            var_2 = (uint32_t)(var_3 >> 32);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].START_ADDR_H, CBASS_FW_EP_REGION_START_ADDR_H_ADDR_H, var_2 );
            var_3 = pCSL_FwRegionAddrRange_t->endAddr;
            var_0 = (uint32_t)(var_3);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_L, CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_LSB, var_0 );
            var_1 = (uint32_t)(var_3 >> 12);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_L, CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_L, var_1 );
            var_2 = (uint32_t)(var_3 >> 32);
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].END_ADDR_H, CBASS_FW_EP_REGION_END_ADDR_H_END_ADDR_H, var_2 );

            // Execute post-condition: Restore the firewall region status
            CSL_REG32_FINS( &pCbass_FwRegs->EP[regionAddrRangeEpIndex].REGION[regionAddrRangeRegionIndex].CONTROL, CBASS_FW_EP_REGION_CONTROL_ENABLE , tmp_enable);
        }
    }
    return CSL_PASS;
}
