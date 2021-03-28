/**
 * \file   cache_mmu_app.c
 *
 * \brief  This sample application demonstrates the cache and mmu 
 *         configurations and usage.
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "chipdb.h"
#include "soc_control.h"
#include "cpu.h"
#include "mmu.h"
#include "cache.h"
#include "example_utils_mmu.h"
#include "cache_mmu_app.h"
#include "console_utils.h"

#ifdef OUTER_CACHE_ENABLE
 #include "pl310.h"
 #include "pl310_config.h"
#endif /* OUTER_CACHE_ENABLE */
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* \brief  Cache line align boundary. For ARM cortex A8 - 64 bytes, 
 *         cortex A9 - 32 bytes. 
 */
#define CACHE_LINE_ALIGN    (64U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#ifdef __TMS470__

/** \brief Buffer to be transmitted to demonstrate the cache operations. */
    #pragma DATA_ALIGN(buffer, CACHE_LINE_ALIGN);
    volatile uint8_t buffer[DATA_BUFFER_SIZE];
    
#elif defined(__IAR_SYSTEMS_ICC__)

    #pragma data_alignment=CACHE_LINE_ALIGN
    volatile uint8_t  buffer[DATA_BUFFER_SIZE];
    
#elif defined(gcc)

    volatile uint8_t buffer[DATA_BUFFER_SIZE]
     __attribute__((aligned(CACHE_LINE_ALIGN)));
     
#else
    #error "Unsupported Compiler. \r\n"
#endif

#ifdef OUTER_CACHE_ENABLE

/** \brief Array to hold the dummy data which can be used to fill full cache.*/
uint8_t dummyArrayCache[PL310_AM43XX_L2_CACHE_SIZE] = {0};
/** \brief Array to hold the dummy data which can be used to fill the 
           cache line. */
uint8_t dummyArrayLine[CACHE_LINE_ALIGN]             = {0};

/** \brief Page table configuration for DDR marked with L1 as non cache-able.*/
mmuMemRegionConfig_t regionDdrL1UnCached =
            {   
                START_ADDR_DDR, 
                NUM_SECTIONS_DDR, /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_NORMAL_NON_SHAREABLE,
                MMU_CACHE_POLICY_NON_CACHEABLE, /* Inner */
                MMU_CACHE_POLICY_WB_WA, /* Outer */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* Demonstrate usage of L2 as SRAM. */
void CACHEAppL2SramDemo(void)
{
    uint32_t index = 0;
    uint32_t* startAddr = (uint32_t*)CHIPDBBaseAddress(
                                                CHIPDB_MOD_ID_MPU_L2_CACHE, 0);
    uint32_t length = L2_SRAM_MEM_SIZE/(sizeof(startAddr));

    CONSOLEUtilsPuts("L2 SRAM DEMO:\r\n");
    CONSOLEUtilsPuts("-------------------\r\n");
    CONSOLEUtilsPuts("Write to memory !!!\r\n");

    for(index = 0; (index < length); index++)
    {
        startAddr[index] = L2_SRAM_TEST_PATTERN;
    }

    CONSOLEUtilsPuts("Read and compare !!!\r\n");
    for(index = 0; (index < length); index++)
    {
        if(L2_SRAM_TEST_PATTERN != startAddr[index])
        {
            CONSOLEUtilsPuts("L2 SRAM memory test FAILED.\r\n");
            return;
        }
    }
    CONSOLEUtilsPuts("L2 SRAM memory test PASSED.\r\n");
}

#endif /* OUTER_CACHE_ENABLE */

void CACHEAppInitBuffer(void)
{
    /* Populate the buffer (with a-z) whose data will be transferred by DMA */
    CACHEAppUpdateBuffer('a');
    buffer[TX_DATA_LENGTH] = '\0';
}

/* Demonstrate Cache invalidate operation. */
void CACHEAppInvalidateDemo(void)
{
    CONSOLEUtilsPuts("CACHE INVALIDATION:\r\n");
    CONSOLEUtilsPuts("-------------------\r\n");

    CONSOLEUtilsPuts("The initial buffer contents in Main Memory.\r\n");
    CACHEAppUartTransfer((uint8_t*)buffer, TX_DATA_LENGTH);

    CONSOLEUtilsPuts("\r\n\r\nUpdating buffer contents to A-Z.\r\n");

    /* Populate the buffer which is used by DMA for data transfer */
    CACHEAppUpdateBuffer('A');

    CONSOLEUtilsPuts("\r\nBuffer contents(in Cache): Before invalidation\r\n");
    CONSOLEUtilsPuts((char *)buffer);

    CACHEDataInvRange((uint32_t*)buffer, DATA_BUFFER_SIZE);

    CONSOLEUtilsPuts("\r\n\r\nBuffer contents(in main mem): After invalidation\r\n");
    CONSOLEUtilsPuts((char *)buffer);
}

/* Demonstrate Cache clean operation. */
void CACHEAppCleanDemo(void)
{
    CONSOLEUtilsPuts("\r\n\r\nCACHE CLEAN:\r\n");
    CONSOLEUtilsPuts("--------------\r\n");

    CONSOLEUtilsPuts("Updating buffer contents (to A-Z).\r\n");

    /* Populate the buffer which is used by DMA for data transfer */
    CACHEAppUpdateBuffer('A');

    CONSOLEUtilsPuts("\r\nBuffer contents in main memory (Cache not cleaned).\r\n");
    CACHEAppUartTransfer((uint8_t*)buffer, TX_DATA_LENGTH);

    /* Clean cache to achieve coherence between cached memory and main memory */
    CACHEDataCleanRange((uint32_t*)buffer, 27);

    CONSOLEUtilsPuts("\r\n\r\nThe buffer contents in main memory (Cache cleaned).\r\n");
    CACHEAppUartTransfer((uint8_t*)buffer, TX_DATA_LENGTH);
}


#ifdef OUTER_CACHE_ENABLE
/*
** Demonstrate Cache lock and unlock operation.
*/
void CACHEAppLockDemo(void)
{
    uint32_t index;
    volatile uint32_t readvalue = 0;

    /* Disable cache */
    CACHEDisable(CACHE_IDCACHE, CACHE_INNER_OUTER);
    /* L1 - un-cached to demonstrate PL310 Cache lock feature. */
    MMUMemRegionMap(&regionDdrL1UnCached, (uint32_t*)pageTable);
    /* Enable cache */
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    CONSOLEUtilsPuts("\r\n\r\nCACHE LOCK:\r\n");
    CONSOLEUtilsPuts("-----------\r\n");

    CONSOLEUtilsPuts("Updating buffer contents (to A-Z).\r\n");
    CACHEAppUpdateBuffer('A');

    CONSOLEUtilsPuts("\r\nLocking buffer to cache - (Cleans before locking)\r\n");

    CACHELockByWay(PL310_LOCK_WAY(0), (uint32_t *)buffer, TX_DATA_LENGTH);

    CONSOLEUtilsPuts("Updating buffer contents (to a-z).\r\n");
    CACHEAppUpdateBuffer('a');

    /* Print contents (from cache) */
    CONSOLEUtilsPuts("\r\nBuffer contents (from cache)\r\n");
    CONSOLEUtilsPuts((char *)buffer);

    /* Lock other ways to ensure the cache fill below goes to the way under 
       demo */
    CACHELockByWay(0xFFFE, (uint32_t *)dummyArrayLine, CACHE_LINE_ALIGN);

    /* Load data to cache (data size > cache size) */
    CONSOLEUtilsPuts("\r\n\r\nTrying to fill cache with dummy data\r\n");
    for(index = 0; (index < PL310_AM43XX_L2_CACHE_SIZE); index += CACHE_LINE_ALIGN)
    {
        dummyArrayCache[index] = readvalue;
    }

    /* Print contents (from main memory) using DMA */
    CONSOLEUtilsPuts("\r\nBuffer contents (from main mem) - Cache contents not evicted\r\n");
    CACHEAppUartTransfer((uint8_t*)buffer, TX_DATA_LENGTH);

    CONSOLEUtilsPuts("\r\n\r\nCACHE UNLOCK:\r\n");
    CONSOLEUtilsPuts("-------------\r\n");

    /* Unlock cache */
    CACHEUnlockByWay(PL310_LOCK_WAY(0));

    /* Load data to cache (data size > cache size) */
    CONSOLEUtilsPuts("Trying to fill cache with dummy data\r\n");
    for(index = 0; (index < PL310_AM43XX_L2_CACHE_SIZE); index += 
                                                             CACHE_LINE_ALIGN)
    {
        readvalue = dummyArrayCache[index];
    }

    /* Print contents (from main memory) using DMA */
    CONSOLEUtilsPuts("\r\nBuffer contents (from main mem) - Cache contents evicted\r\n");
    CACHEAppUartTransfer((uint8_t*)buffer, TX_DATA_LENGTH);

}
#endif /* OUTER_CACHE_ENABLE */

void CACHEAppUpdateBuffer(uint8_t alphabet)
{
    uint32_t index = 0;

    /* Populate the buffer which is used by DMA for data transfer */
    for(index = 0; index < TX_DATA_LENGTH; index++)
    {
         buffer[index] = alphabet++;
    }
}
