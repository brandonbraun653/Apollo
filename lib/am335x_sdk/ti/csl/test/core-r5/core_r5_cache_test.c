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
 *  \file     core_r5_cache_test.c
 *
 *  \brief    This file contains cache test code for R5 core.
 *
 *  \details  Cache APIs tests
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

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/
uint32_t cacheTestBuf[256];

/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/

/*===========================================================================*/
/*                        Test Function definitions                          */
/*===========================================================================*/

/* This function tests the Cache APIs */
int32_t cslcore_r5_cacheTest(void)
{
    /* Declarations of variables */
    int32_t    testResult = CSL_APP_TEST_PASS;
    uint32_t   icacheLineSize;

    CSL_armR5CacheEnableICache(0U);
    CSL_armR5CacheEnableDCache(0U);
    CSL_armR5CacheEnableICache(1U);
    CSL_armR5CacheEnableDCache(1U);

    CSL_armR5CacheInvalidateAllIcache();
    CSL_armR5CacheInvalidateAllDcache();

    CSL_armR5CacheWb((const void *)cacheTestBuf, sizeof(cacheTestBuf));
    CSL_armR5CacheWbInv((const void *)cacheTestBuf, sizeof(cacheTestBuf));
    CSL_armR5CacheInv((const void *)cacheTestBuf, sizeof(cacheTestBuf));

    CSL_armR5CacheInvalidateIcacheMva((uint32_t)cslcore_r5_cacheTest);
    CSL_armR5CacheInvalidateDcacheSetWay(0U, 0U);
    CSL_armR5CacheCleanDcacheSetWay(0U, 0U);
    CSL_armR5CacheCleanInvalidateDcacheSetWay(0U, 0U);

    CSL_armR5CacheDisableEcc();
    CSL_armR5CacheEnableAxiAccess();

    CSL_armR5Dsb();

    icacheLineSize = CSL_armR5CacheGetIcacheLineSize();

    cslApp_print("I-Cache Line Size is: ");
    cslApp_printArg(icacheLineSize);
    cslApp_print(" \n ");

   return (testResult);
}


/* Nothing past this point */
