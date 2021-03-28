/**
 * @file  startup.c
 *
 * @brief
 *  ARM R5 start-up code
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2020, Texas Instruments, Inc.
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
#include <startup.h>
#include <csl_error.h>
#include <csl_types.h>

#pragma SET_CODE_SECTION(".startupCode")
#pragma SET_DATA_SECTION(".startupData")

#define CSL_MCU_ARMSS_STARTUP_VIM_NULL_ADDR           ((void *) 0 )

#define CSL_FMK(PER_REG_FIELD, val)                                         \
    (((val) << CSL_##PER_REG_FIELD##_SHIFT) & CSL_##PER_REG_FIELD##_MASK)

/*  Declarations    */
/**
 * \brief  TEX[2:0], C and B values.
 *         CSL_ArmR5MemAttr is used as intex here.
 *         gMemAttr[x][0]: TEX[2:0] values
 *         gMemAttr[x][1]: C bit value
 *         gMemAttr[x][2]: B bit value
 */
static const uint32_t gMemAttr[CSL_ARM_R5_MEM_ATTR_MAX][3U] =
{
/*    TEX[2:0], C,     B bits */
    {   0x0U,   0x0U,  0x0U,}, /* Strongly-ordered.*/
    {   0x0U,   0x0U,  0x1U,}, /* Shareable Device.*/
    {   0x0U,   0x1U,  0x0U,}, /* Outer and Inner write-through, no write-allocate. */
    {   0x0U,   0x1U,  0x1U,}, /* Outer and Inner write-back, no write-allocate. */
    {   0x1U,   0x0U,  0x0U,}, /* Outer and Inner Non-cacheable. */
    {   0x1U,   0x1U,  0x1U,}, /* Outer and Inner write-back, write-allocate.*/
    {   0x2U,   0x0U,  0x0U,}, /* Non-shareable Device.*/
};

extern const CSL_ArmR5MpuRegionCfg __attribute__((weak)) gCslR5MpuCfg[CSL_ARM_R5F_MPU_REGIONS_MAX] =
{
#if defined (SOC_TPR12)
    {
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 0U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_4GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 1U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,
        .memAttr          = 0U,
    },
    {
        /* Region 1 configuration: 4M L3 */
        .regionId         = 1U,
        .enable           = 1U,
        .baseAddr         = 0x88000000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_4MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 2 configuration: 32 KB TCMA */
        .regionId         = 2U,
        .enable           = 1U,
        .baseAddr         = 0x00000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 3 configuration: 32 KB  TCMB */
        .regionId         = 3U,
        .enable           = 1U,
        .baseAddr         = 0x00080000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 4 configuration: 1 MB L2 RAM */
        .regionId         = 4U,
        .enable           = 1U,
        .baseAddr         = 0x10200000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_1MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
#else
    {
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 0U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_4GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 1U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,
        .memAttr          = 0U,
    },
    {
        /* Region 1 configuration: 128 bytes memory for exception vector execution */
        .regionId         = 1U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_128B,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 2 configuration: 512 KB OCMS RAM */
        .regionId         = 2U,
        .enable           = 1U,
        .baseAddr         = 0x41C00000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_512KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 3 configuration: 2 MB MCMS3 RAM */
        .regionId         = 3U,
        .enable           = 1U,
        .baseAddr         = 0x70000000,
#if defined (SOC_J721E)
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_8MB,
#else
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_2MB,
#endif
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 4 configuration: 2 GB DDR RAM */
        .regionId         = 4U,
        .enable           = 1U,
        .baseAddr         = 0x80000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_2GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 5 configuration: 32 KB BTCM */
        /* Address of ATCM/BTCM are configured via MCU_SEC_MMR registers
           It can either be '0x0' or '0x41010000'. Application/Boot-loader shall
           take care this configurations and linker command file shall be
           in sync with this. For either of the above configurations,
           MPU configurations will not changes as both regions will have same
           set of permissions in almost all scenarios.
           Application can chose to overwrite this MPU configuration if needed.
           The same is true for the region corresponding to ATCM. */
        .regionId         = 5U,
        .enable           = 1U,
        .baseAddr         = 0x41010000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
        .memAttr          = 0U,
    },
    {
        /* Region 6 configuration: 128 MB FSS DAT */
        .regionId         = 6U,
        .enable           = 0U,
        .baseAddr         = 0x50000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_128MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 7 configuration: 32 KB ATCM */
        .regionId         = 7U,
        .enable           = 1U,
        .baseAddr         = 0x0,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
        .memAttr          = 0U,
    },
#endif
};

#pragma SET_DATA_SECTION()

__attribute__((weak)) void __mpu_init(void);
int _system_pre_init(void);
void _system_post_cinit(void);
void CSL_armR5MPUCfg(void);

static void _enable_mpu()
{
    CSL_armR5MPUCfg();                      /* Custom MPU configuration */
}

static void _enable_cache()
{
    CSL_armR5StartupCacheEnableAllCache( 0 );      /* Disable I/D caches */
    CSL_armR5StartupCacheEnableForceWrThru( 0 );   /* Disable force write-thru */
    CSL_armR5StartupCacheInvalidateAllCache();     /* Invalidate I/D caches */
    CSL_armR5StartupCacheEnableAllCache( 1 );      /* Enable I/D caches */
}

void CSL_armR5MPUCfg(void)
{
    uint32_t loopCnt = 0U;
    uint32_t baseAddrRegVal = 0U, sizeRegVal = 0U, accessCtrlRegVal = 0U, tex;

    CSL_armR5StartupCacheInvalidateAllCache();     /* Invalidate caches */
    CSL_armR5StartupCacheEnableDCache(0);          /* Disable D-cache */

    /* Disable MPU */
    CSL_armR5StartupMpuEnable(0U);
    /* Disable all MPU regions */
    for (loopCnt = 0U ;
         loopCnt < CSL_ARM_R5F_MPU_REGIONS_MAX ;
         loopCnt++)
    {
        CSL_armR5StartupMpuCfgRegion(loopCnt,
                                     baseAddrRegVal,
                                     sizeRegVal,
                                     accessCtrlRegVal);
    }

    /* Configure MPU regions only for provided configuration */
    for (loopCnt = 0U ;
         loopCnt < CSL_ARM_R5F_MPU_REGIONS_MAX ;
         loopCnt++)
    {
        if (CSL_ARM_R5_MPU_REGION_SIZE_32B <= gCslR5MpuCfg[loopCnt].size)
        {
            baseAddrRegVal = 0U;
            sizeRegVal = 0U;
            accessCtrlRegVal = 0U;
            baseAddrRegVal   |= ( gCslR5MpuCfg[loopCnt].baseAddr &
                                    CSL_ARM_R5_MPU_REGION_BASE_ADDR_MASK);
            sizeRegVal       |= ( gCslR5MpuCfg[loopCnt].enable <<
                                    CSL_ARM_R5_MPU_REGION_SZEN_EN_SHIFT);
            sizeRegVal       |= ( gCslR5MpuCfg[loopCnt].size <<
                                    CSL_ARM_R5_MPU_REGION_SZEN_SZ_SHIFT);
            sizeRegVal       |= ( gCslR5MpuCfg[loopCnt].subRegionEnable <<
                                    CSL_ARM_R5_MPU_REGION_SZEN_SRD_SHIFT);
            accessCtrlRegVal |= ( gCslR5MpuCfg[loopCnt].exeNeverControl <<
                                   CSL_ARM_R5_MPU_REGION_AC_XN_SHIFT);
            accessCtrlRegVal |= ( gCslR5MpuCfg[loopCnt].accessPermission <<
                                   CSL_ARM_R5_MPU_REGION_AC_AP_SHIFT);
            accessCtrlRegVal |= ( gCslR5MpuCfg[loopCnt].shareable <<
                                   CSL_ARM_R5_MPU_REGION_AC_S_SHIFT);
            if (gCslR5MpuCfg[loopCnt].cacheable == (uint32_t)TRUE)
            {
                tex = (1U << 2U);
                tex |= (gCslR5MpuCfg[loopCnt].cachePolicy);
                accessCtrlRegVal |=
                                ( tex << CSL_ARM_R5_MPU_REGION_AC_TEX_SHIFT);
                accessCtrlRegVal |= ( gCslR5MpuCfg[loopCnt].cachePolicy <<
                                   CSL_ARM_R5_MPU_REGION_AC_CB_SHIFT);
            }
            else
            {
                tex = gMemAttr[gCslR5MpuCfg[loopCnt].memAttr][0U];
                accessCtrlRegVal |=
                                ( tex << CSL_ARM_R5_MPU_REGION_AC_TEX_SHIFT);
                accessCtrlRegVal |=
                                ( gMemAttr[gCslR5MpuCfg[loopCnt].memAttr][1U] <<
                                CSL_ARM_R5_MPU_REGION_AC_B_SHIFT);
                accessCtrlRegVal |=
                                ( gMemAttr[gCslR5MpuCfg[loopCnt].memAttr][2U] <<
                                CSL_ARM_R5_MPU_REGION_AC_C_SHIFT);
            }
            /* configure MPU region here */
            CSL_armR5StartupMpuCfgRegion(gCslR5MpuCfg[loopCnt].regionId,
                                         baseAddrRegVal,
                                         sizeRegVal,
                                         accessCtrlRegVal);
        }
    }

    CSL_armR5StartupCacheInvalidateAllCache();     /* Invalidate caches */
    CSL_armR5StartupCacheEnableDCache(0);          /* Disable D-cache */

    /* Enable MPU */
    CSL_armR5StartupMpuEnable(1U);
}

/*****************************************************************************/
/* \brief __MPU_INIT() - __mpu_init() is called in the C/C++ startup routine,*/
/* _c_int00(), and provides a mechanism for tailoring mpu init by device     */
/* prior to calling main().                                                  */
/*                                                                           */
/*****************************************************************************/
/*  Usage notes:
    On entry to this function from boot, R5F must be in System (privileged) mode. */
void __mpu_init(void)
{
    uint32_t loopCnt = 0U, regAddr;
    CSL_ArmR5CPUInfo info;

    CSL_armR5StartupGetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        regAddr = (info.cpuID == CSL_ARM_R5_CPU_ID_0)?
                                 CSL_MCU_DOMAIN_VIM_BASE_ADDR0:
                                 CSL_MCU_DOMAIN_VIM_BASE_ADDR1;

    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        regAddr = (info.cpuID == CSL_ARM_R5_CPU_ID_0)?
                                 CSL_MAIN_DOMAIN_VIM_BASE_ADDR0:
                                 CSL_MAIN_DOMAIN_VIM_BASE_ADDR1;

    }

    CSL_armR5SetDLFOBit();
    _enable_mpu();              /* Enable MPU */
    _enable_cache();            /* Enable all caches */
    CSL_armR5StartupFpuEnable( 1 );    /* Enable FPU */
    CSL_armR5StartupIntrEnableVic(1);  /* Enable VIC */
    /* Disable/Clear pending Interrupts in VIM before enabling CPU Interrupts */
    /* This is done to prevent serving any bogus interrupt */
    for (loopCnt = 0U ; loopCnt < R5_VIM_INTR_NUM; loopCnt++)
    {
        /* Disable interrupt in vim */
        CSL_startupVimSetIntrEnable((CSL_vimRegs *)(uintptr_t)regAddr,
                                    loopCnt,
                                    false);
        /* Clear interrupt status */
        CSL_startupVimClrIntrPending((CSL_vimRegs *)(uintptr_t)regAddr,
                                     loopCnt);
    }
    CSL_armR5StartupIntrEnableFiq(1);  /* Enable FIQ */
    CSL_armR5StartupIntrEnableIrq(1);  /* Enable IRQ */
}

/*****************************************************************************/
/* _SYSTEM_PRE_INIT() - _system_pre_init() is called in the C/C++ startup    */
/* routine (_c_int00()) and provides a mechanism for the user to             */
/* insert application specific low level initialization instructions prior   */
/* to calling main().  The return value of _system_pre_init() is used to     */
/* determine whether or not C/C++ global data initialization will be         */
/* performed (return value of 0 to bypass C/C++ auto-initialization).        */
/*                                                                           */
/* PLEASE NOTE THAT BYPASSING THE C/C++ AUTO-INITIALIZATION ROUTINE MAY      */
/* RESULT IN PROGRAM FAILURE.                                                */
/*                                                                           */
/*****************************************************************************/
int _system_pre_init(void)
{
    return 1;
}

/*****************************************************************************/
/* _SYSTEM_POST_CINIT() - _system_post_cinit() is a hook function called in  */
/* the C/C++ auto-initialization function after cinit() and before pinit().  */
/*                                                                           */
/*****************************************************************************/
void _system_post_cinit(void)
{

}

void CSL_armR5StartupGetCpuID( CSL_ArmR5CPUInfo *cpuInfo )
{
    uint32_t regVal;

    regVal = CSL_armR5StartupReadMpidrReg();
    cpuInfo->cpuID = (uint32_t)((regVal & CSL_R5_MPIDR_AFF0_MASK) >>
                                          CSL_R5_MPIDR_AFF0_SHIFT);
    cpuInfo->grpId = (uint32_t)((regVal & CSL_R5_MPIDR_AFF1_MASK) >>
                                          CSL_R5_MPIDR_AFF1_SHIFT);
    cpuInfo->multiprocessingExt = (uint32_t)(
                                (regVal & CSL_R5_MPIDR_MULEXT_MASK) >>
                                          CSL_R5_MPIDR_MULEXT_SHIFT);
}

int32_t CSL_startupVimSetIntrEnable( CSL_vimRegs *pRegs, uint32_t intrNum, bool bEnable )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, mask;
    void       *pChkRegs = (void *) pRegs;

    if (pChkRegs == CSL_MCU_ARMSS_STARTUP_VIM_NULL_ADDR)
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

int32_t CSL_startupVimClrIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum )
{
    int32_t  retVal = CSL_PASS;
    uint32_t bitNum, groupNum, mask;
    void       *pChkRegs = (void *) pRegs;

    groupNum = intrNum / CSL_VIM_NUM_INTRS_PER_GROUP;
    bitNum   = intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U);
    mask   = (((uint32_t)(1U)) << bitNum);

    if ( (pChkRegs != CSL_MCU_ARMSS_STARTUP_VIM_NULL_ADDR) &&
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

#pragma SET_CODE_SECTION()
