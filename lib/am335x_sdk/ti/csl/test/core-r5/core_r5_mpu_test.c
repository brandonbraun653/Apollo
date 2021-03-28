/* Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     core_r5_mpuTest.c
 *
 *  \brief    This file contains mpu API test code for R5 core.
 *
 *  \details  MPU read/write and configuration tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <core_r5_test.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
#define   CSL_TEST_R5_MPU_ENABLE                   ((uint32_t) 1u)
#define   CSL_TEST_R5_MPU_DISABLE                  ((uint32_t) 0u)
#define   CSL_TEST_MPU_NUM_CONF_REGIONS            ((uint32_t) 7u)
/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/

/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/


/*===========================================================================*/
/*                        Test Function definitions                          */
/*===========================================================================*/


/* For the unit test we are using the CSL startup library to reach to main()
 * since the CSl startup library initialize the default mpu, we should prevent
 * the initialization from CSl startup library
 * the way to prevent the MPU initialization from CSL is to define a dummy
 * __mpu_init() function here
*/

void __mpu_init(void)
{
   /* Do not implement anything here as anything here would be invoked
    * during CSL startup code
    */
}

/* Implement the App mpu init sample code here */
int32_t CSL_r5_Test_mpu_init(void)
{
    int32_t                   region, chk, testResult = CSL_APP_TEST_PASS;
    uint32_t                  numRegions, loopCnt;
    cslCoreR5TestMpuRegion_t  mpuRegionDefault, mpuRegion[CSL_TEST_MPU_NUM_CONF_REGIONS];
    uint32_t                  regAddr, mpuVerifyCheckInDetail = 1u;
    CSL_ArmR5CPUInfo          info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        regAddr = CSL_MCU_DOMAIN_VIM_BASE_ADDR;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        regAddr = CSL_MAIN_DOMAIN_VIM_BASE_ADDR;
    }

/* Below code is for custom MPU configuration
 - this configuration varies from usecase to usecase
*/

/*
mpu_region_0_base .word 0x00000000                 ;The MPU Region Base Address Register
mpu_region_0_size .word (0x0<<8) | (0x1F<<1) | 0x1 ;Region Size and Enable bits (and Subre region enable )
mpu_region_0_permissions .word (1 << 12) | (3 << 8) | (2 << 3) | (0 << 2) | (0 << 0);The MPU Region Access Control

MPU region 1 is the created for the 2GB DDR address space starting with 0x80M to 0xA0M
; *
; *   attributes:  xn  = 0 (bit 12)    - execution permitted
; *                ap  = 3 (bits 10:8) - read/write full access, 3=> full access privilege and user
; *                tex = 1 (bits 5:3)  - Normal         7=> cacheable, write back, no write allocate
; *                S   = 0 (bit 2)     - non-shared     0=> marking non-shared to enable cache,
; *                CB  = 0 (bits 1:0)  - Noncache       3=>write back, no write allocate cache
; */

    mpuRegion[0].base        = (uint32_t) (0x00000000u);
    mpuRegion[0].size        = (uint32_t) ((0u << 8u) | (0x1Fu << 1u) | (1u) );
    mpuRegion[0].permissions = (uint32_t) ((1u << 12u) | (3u << 8u) | (2u << 3u) \
                                          | (0u << 2u) | (0u << 0u));

    mpuRegion[1].base        = (uint32_t) (0x80000000u);
    mpuRegion[1].size        = (uint32_t) ((0 << 8u) | (0x1E << 1u) | (1u) );
    mpuRegion[1].permissions = (uint32_t) ((0u<<12u) | (3u << 8u) | (1u << 3u) \
                                        | (0u << 2u) | (0u << 0u));

    mpuRegion[2].base        = (uint32_t) (0x41C00000);
    mpuRegion[2].size        = (uint32_t) ((0 << 8u) | (0x12 << 1u) | (1u) );
    mpuRegion[2].permissions = (uint32_t) ((0u<<12u) | (3u << 8u) | (1u << 3u) \
                                         | (0u << 2u) | (3u << 0u));

    mpuRegion[3].base        = (uint32_t) (0x70000000);
    mpuRegion[3].size        = (uint32_t) ((0u << 8u) | (0x14u << 1u) | (1u) );
    mpuRegion[3].permissions = (uint32_t) ((0u << 12u) | (3u << 8u) | (1u << 3u) \
                                          | (0u << 2u) | (3u << 0u));

    mpuRegion[4].base        = (uint32_t) (0x00000000u);
    mpuRegion[4].size        = (uint32_t) ((0u << 8u) | (0x1Eu << 1u) | (1u) );
    mpuRegion[4].permissions = (uint32_t) ((0u << 12u) | (3u << 8u) | (4u << 3u) \
                                          | (0u << 2u) | (0u << 0u));

    mpuRegion[5].base        = (uint32_t) (0x41010000);
    mpuRegion[5].size        = (uint32_t) ((0u << 8u) | (0xEu << 1u) | (1u) );
    mpuRegion[5].permissions = (uint32_t) ((0u << 12u) | (3u << 8u) | (4u << 3u) \
                                          | (0u << 2u) | (0u << 0u));

    mpuRegion[6].base        = (uint32_t) (0x50000000u);
    mpuRegion[6].size        = (uint32_t) ((0u << 8u) | (0x1Au << 1u) | (0u) );
    mpuRegion[6].permissions = (uint32_t) ((0u << 12u) | (3u << 8u) | (1u << 3u) \
                                          | (0u << 2u) | (3u << 0u));

    /* Default region */
    mpuRegionDefault.base    = (uint32_t) 0u;
    mpuRegionDefault.size    = (uint32_t) 0u;
    mpuRegionDefault.permissions = (uint32_t) 0u;

    numRegions = CSL_armR5MpuGetNumRegions();

    /* Disable the MPU first */
    CSL_armR5MpuEnable(CSL_TEST_R5_MPU_DISABLE);

    /* Set all the regions and verify the set regions */
    for (region =(numRegions-1u); region >= CSL_TEST_MPU_NUM_CONF_REGIONS; region--)
    {
       /* Set the regions */
       CSL_armR5MpuCfgRegion(region,
                             mpuRegionDefault.base,
                             mpuRegionDefault.size,
                             mpuRegionDefault.permissions);
       /* Code coverage for Verify cfg region */
       if (mpuVerifyCheckInDetail == 1u)
       {
           /* Verify the regions */
           /* tweak the region and expect failure */
           chk = CSL_armR5MpuVerifyCfgRegion(region + 2,
                                 mpuRegionDefault.base,
                                 mpuRegionDefault.size,
                                 mpuRegionDefault.permissions);
           if (chk == CSL_PASS)
           {
               testResult = CSL_APP_TEST_FAILED;
               break;
           }
           /* tweak the base and expect failure */
           chk = CSL_armR5MpuVerifyCfgRegion(region,
                                 0x200,
                                 mpuRegionDefault.size,
                                 mpuRegionDefault.permissions);
           if (chk == CSL_PASS)
           {
               testResult = CSL_APP_TEST_FAILED;
               break;
           }

           /* tweak the size and expect failure */
           chk = CSL_armR5MpuVerifyCfgRegion(region,
                                 mpuRegionDefault.base,
                                 0x200,
                                 mpuRegionDefault.permissions);
           if (chk == CSL_PASS)
           {
               testResult = CSL_APP_TEST_FAILED;
               break;
           }

           /* tweak the permission and expect failure */
           chk = CSL_armR5MpuVerifyCfgRegion(region,
                                 mpuRegionDefault.base,
                                 mpuRegionDefault.size,
                                 0x200);
           if (chk == CSL_PASS)
           {
               testResult = CSL_APP_TEST_FAILED;
               break;
           }
           mpuVerifyCheckInDetail = 0u;
       }

       /* Verify the regions */
       chk = CSL_armR5MpuVerifyCfgRegion(region,
                             mpuRegionDefault.base,
                             mpuRegionDefault.size,
                             mpuRegionDefault.permissions);
       if (chk != CSL_PASS)
       {
           testResult = CSL_APP_TEST_FAILED;
           break;
       }
    }

    if ( testResult == CSL_APP_TEST_PASS)
    {
        /* Configure the remaining regions and test */
        for (; region >= 0; region--)
        {
           /* Set the regions */
           CSL_armR5MpuCfgRegion(region,
                                 mpuRegion[region].base,
                                 mpuRegion[region].size,
                                 mpuRegion[region].permissions);
           /* Verify the regions */
           chk = CSL_armR5MpuVerifyCfgRegion(region,
                                 mpuRegion[region].base,
                                 mpuRegion[region].size,
                                 mpuRegion[region].permissions);
           if (chk != CSL_PASS)
           {
               testResult = CSL_APP_TEST_FAILED;
               break;
           }
        }
    }

    if ( testResult == CSL_APP_TEST_PASS)
    {
        /* Disable region and verify test */
        CSL_armR5MpuEnableRegion(0, CSL_TEST_R5_MPU_DISABLE);
        chk = CSL_armR5MpuVerifyEnableRegion(0, CSL_TEST_R5_MPU_DISABLE);

        /* Enable Region and verify test */
        if (chk == CSL_PASS)
        {
            /* Enable the MPU */
            CSL_armR5MpuEnableRegion(0, CSL_TEST_R5_MPU_ENABLE);
            chk = CSL_armR5MpuVerifyEnableRegion(0, CSL_TEST_R5_MPU_ENABLE);
            if (chk != CSL_PASS)
            {
                testResult = CSL_APP_TEST_FAILED;
            }
        }
        else
        {
            testResult = CSL_APP_TEST_FAILED;
        }
    }

    if (testResult == CSL_APP_TEST_PASS)
    {
       CSL_armR5MpuEnable(CSL_TEST_R5_MPU_ENABLE);
    }

    if (testResult == CSL_APP_TEST_PASS)
    {
        CSL_armR5FpuEnable( 1 );    /* Enable FPU */
        CSL_armR5IntrEnableVic(1);  /* Enable VIC */
        /* Disable/Clear pending Interrupts in VIM before enabling CPU Interrupts */
        /* This is done to prevent serving any bogus interrupt */
        for (loopCnt = 0U ; loopCnt < R5_VIM_INTR_NUM; loopCnt++)
        {
            /* Disable interrupt in vim */
            CSL_vimSetIntrEnable((CSL_vimRegs *)(uintptr_t)regAddr, loopCnt, false);
            /* Clear interrupt status */
            CSL_vimClrIntrPending((CSL_vimRegs *)(uintptr_t)regAddr, loopCnt);
        }
        CSL_armR5IntrEnableFiq(1);  /* Enable FIQ */
        CSL_armR5IntrEnableIrq(1);  /* Enable IRQ */
    }
    return (testResult);
}

/* PRSDK-1673: This test demonstrates the APIs to enable MPU
 */
 
int32_t cslcore_r5_mpuTest(void)
{
    /* Declarations of variables */
    int32_t    testResult;
    int32_t    numRegions;

    CSL_armR5CacheInvalidateAllCache();     /* Invalidate caches before MPU En*/
    testResult = CSL_r5_Test_mpu_init();
    numRegions = CSL_armR5MpuGetNumRegions();
    cslApp_print(" MPU API tests complete: number of regisions tested are : ");
    cslApp_printArg(numRegions);
    cslApp_print(" \n ");

   return (testResult);
}


/* Nothing past this point */
