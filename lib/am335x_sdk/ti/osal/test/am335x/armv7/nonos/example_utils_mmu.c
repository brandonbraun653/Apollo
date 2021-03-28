/**
 * \file   example_utils_mmu.c
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

#include <ti/starterware/include/types.h>
#include <ti/starterware/include/misc.h>
#include <ti/starterware/include/mmu.h>
#include <ti/starterware/include/chipdb.h>
#include "example_utils_mmu.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#ifdef __TMS470__

/** \brief Page tables to hold physical to virtual address mapping. The start
           address of the page table must be aligned at 16K boundary */
    #pragma DATA_ALIGN(pageTable, MMU_PAGETABLE_ALIGN_SIZE);
    volatile uint32_t pageTable[MMU_PAGETABLE_NUM_ENTRY];
    
#elif defined(__IAR_SYSTEMS_ICC__)

    #pragma data_alignment=MMU_PAGETABLE_ALIGN_SIZE
    volatile uint32_t pageTable[MMU_PAGETABLE_NUM_ENTRY];
    
#elif defined(gcc)

    volatile uint32_t pageTable[MMU_PAGETABLE_NUM_ENTRY]
     __attribute__((aligned(MMU_PAGETABLE_ALIGN_SIZE)));
     
#else
    #error "Unsupported Compiler. \r\n"
#endif

/** \brief  Define DDR memory region. DDR can be configured as Normal memory 
 *          with R/W access in user/privileged modes.
 */
mmuMemRegionConfig_t regionDdr =
            {   
                START_ADDR_DDR, 
                NUM_SECTIONS_DDR, /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_NORMAL_NON_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner */
                MMU_CACHE_POLICY_WB_WA, /* Outer */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

/** \brief Define OCMC RAM region. */
/* TODO: Get OCMC RAM base address and size from chipdb. */
mmuMemRegionConfig_t regionOcmc =
            {   
                0, 
                NUM_SECTIONS_OCMC, /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - Min 1MB */
                MMU_MEM_ATTR_NORMAL_NON_SHAREABLE,
                MMU_CACHE_POLICY_WT_NOWA, /* Inner */
                MMU_CACHE_POLICY_WB_WA, /* Outer */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

/** \brief Define Device Memory Region. The region between OCMC and DDR is
 *         configured as device memory, with R/W access in user/privileged 
 *         modes. Also, the region is marked 'Execute Never'.
 */
mmuMemRegionConfig_t regionDev =
            {   
                START_ADDR_DEV, 
                NUM_SECTIONS_DEV, /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_DEVICE_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner - Invalid here */
                MMU_CACHE_POLICY_WB_WA, /* Outer - Invalid here */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

mmuMemRegionConfig_t regionQspi =
            {
                START_ADDR_QSPI,
                NUM_SECTIONS_QSPI, /* Number of Pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_DEVICE_NON_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner - Irrelevant here */
                MMU_CACHE_POLICY_WB_WA, /* Outer - Irrelevant here */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* \brief  Function to set-up MMU. This function Maps three regions
 *           1. DDR
 *           2. OCMC and
 *           3. Device memory and 
 *         enables MMU.
 */
void MMUConfigAndEnable(void)
{

    /* Initialize the page table and MMU */
    MMUInit((uint32_t*)pageTable, MMU_PAGETABLE_NUM_ENTRY);
    
    regionOcmc.startAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_OCMCRAM, 0);

    /* Map the defined regions */
    MMUMemRegionMap(&regionDdr, (uint32_t*)pageTable);
    MMUMemRegionMap(&regionOcmc, (uint32_t*)pageTable);
    MMUMemRegionMap(&regionDev, (uint32_t*)pageTable);
    MMUMemRegionMap(&regionQspi, (uint32_t *)pageTable);
    /* Now Safe to enable MMU */
    MMUEnable((uint32_t*)pageTable);
}
