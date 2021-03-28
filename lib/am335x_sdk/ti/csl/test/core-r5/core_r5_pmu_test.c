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
 *  \file     core_r5_pmu_test.c
 *
 *  \brief    This file contains PMU test code for R5 core.
 *
 *  \details  PMU register read/write and configuration tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <core_r5_test.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/


/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
#define PMU_CNTR_NUM_BRANCH             (2u)
#define PMU_CNTR_NUM_ICACHE_MISS        (1u)
#define PMU_CNTR_NUM_DCAHCE_MISS        (0u)

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/
static uint32_t csl_pmu_test_get_dCache_miss(void);
static uint32_t csl_pmu_test_get_iCache_miss(void);
static uint32_t csl_pmu_test_get_branch(void);
static uint32_t csl_pmu_test_get_cycle(void);

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/

/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/


/*===========================================================================*/
/*                        Test Function definitions                          */
/*===========================================================================*/


static void csl_pmu_test_init_pmu(void)
{
    uint32_t val;

    CSL_armR5PmuCfg(0, 0, 1);
    /* Clear the overflow */
    val = CSL_armR5PmuReadCntrOverflowStatus();
    val &= 0x80000007;
    CSL_armR5PmuClearCntrOverflowStatus(val);
    CSL_armR5PmuCfgCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, CSL_ARM_R5_PMU_EVENT_TYPE_CYCLE_CNT);
    /* I-Cache */
    CSL_armR5PmuCfgCntr(PMU_CNTR_NUM_ICACHE_MISS, CSL_ARM_R5_PMU_EVENT_TYPE_ICACHE_MISS);
    /* D-Cache */
    CSL_armR5PmuCfgCntr(PMU_CNTR_NUM_DCAHCE_MISS, CSL_ARM_R5_PMU_EVENT_TYPE_DCACHE_MISS);
    /* Branch */
    CSL_armR5PmuCfgCntr(PMU_CNTR_NUM_BRANCH, CSL_ARM_R5_PMU_EVENT_TYPE_B_IMMEDIATE);
    CSL_armR5PmuEnableAllCntrs(0);
    CSL_armR5PmuResetCycleCnt();      /* Set PMCR C-bit */
    CSL_armR5PmuResetCntrs();

    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_BRANCH, 1);
    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_ICACHE_MISS, 1);
    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_DCAHCE_MISS, 1);
    CSL_armR5PmuEnableAllCntrs(1);
    CSL_armR5PmuEnableCntrOverflowIntr(PMU_CNTR_NUM_BRANCH, 1U);
    CSL_armR5PmuEnableCntrOverflowIntr(PMU_CNTR_NUM_BRANCH, 0U);
}

static uint32_t csl_pmu_test_get_iCache_miss(void)
{
    uint32_t    temp;
    temp = CSL_armR5PmuReadCntr(PMU_CNTR_NUM_ICACHE_MISS);
    return temp;
}

static uint32_t csl_pmu_test_get_dCache_miss(void)
{
    uint32_t    temp;
    temp = CSL_armR5PmuReadCntr(PMU_CNTR_NUM_ICACHE_MISS);
    return temp;
}

static uint32_t csl_pmu_test_get_branch(void)
{
    uint32_t    temp;
    temp = CSL_armR5PmuReadCntr(PMU_CNTR_NUM_BRANCH);
    return temp;
}

unsigned int csl_pmu_test_get_cycle(void) {
    uint32_t    temp;
    temp = CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
    return temp;
}

/* PRSDK-1660: This test demonstrates the APIs to enable the use of
 *             PMU counters
 */
int32_t cslcore_r5_pmuTest(void)
{
    uint32_t   numCntrs, dCacheMissCnt, iCacheMissCnt, branchCnt, cycleCnt;
    /* Declarations of variables */
    int32_t    testResult = CSL_APP_TEST_PASS;

    /* Some negative tests for code coverage on PMU */
    CSL_armR5PmuCfg(1, 1, 0);
    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_BRANCH, 0);
    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_ICACHE_MISS, 0);
    CSL_armR5PmuEnableCntr(PMU_CNTR_NUM_DCAHCE_MISS, 0);
    CSL_armR5PmuEnableAllCntrs(0);

    csl_pmu_test_init_pmu();

   /* Report number of counters implemented */
    numCntrs = CSL_armR5PmuGetNumCntrs();
    cslApp_print("Number of PMU counters implemented is: ");
    cslApp_printArg(numCntrs);
    cslApp_print(" \n ");

   /* Report number of branch, icache miss and dcache miss */
   dCacheMissCnt = csl_pmu_test_get_dCache_miss();
   iCacheMissCnt = csl_pmu_test_get_iCache_miss();
   branchCnt     = csl_pmu_test_get_branch();
   cycleCnt      = csl_pmu_test_get_cycle();

   cslApp_print("iCacheMissCnt is: ");
   cslApp_printArg(iCacheMissCnt);
   cslApp_print(" \n ");

   cslApp_print("dCacheMissCnt is: ");
   cslApp_printArg(dCacheMissCnt);
   cslApp_print(" \n ");

   cslApp_print("branchCnt is: ");
   cslApp_printArg(branchCnt);
   cslApp_print(" \n ");

   cslApp_print("cycleCnt is: ");
   cslApp_printArg(cycleCnt);
   cslApp_print(" \n ");


   cslApp_print("Setting all PMU counters to new values: ");
   cslApp_print(" \n ");

   /* Set and Read the Counter */
   CSL_armR5PmuSetCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 0x3000U );
   CSL_armR5PmuSetCntr(PMU_CNTR_NUM_ICACHE_MISS, 1U );
   CSL_armR5PmuSetCntr(PMU_CNTR_NUM_DCAHCE_MISS, 1U );
   CSL_armR5PmuSetCntr(PMU_CNTR_NUM_BRANCH, 1U );

   dCacheMissCnt = csl_pmu_test_get_dCache_miss();
   iCacheMissCnt = csl_pmu_test_get_iCache_miss();
   branchCnt     = csl_pmu_test_get_branch();
   cycleCnt      = csl_pmu_test_get_cycle();

   cslApp_print("New iCacheMissCnt is: ");
   cslApp_printArg(iCacheMissCnt);
   cslApp_print(" \n ");

   cslApp_print("New dCacheMissCnt is: ");
   cslApp_printArg(dCacheMissCnt);
   cslApp_print(" \n ");

   cslApp_print("New branchCnt is: ");
   cslApp_printArg(branchCnt);
   cslApp_print(" \n ");

   cslApp_print("New cycleCnt is: ");
   cslApp_printArg(cycleCnt);
   cslApp_print(" \n ");


   return (testResult);
}


/* Nothing past this point */
