/**
 * \file   cache_mmu_app_main.c
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
#include "soc_control.h"
#include "mmu.h"
#include "example_utils_mmu.h"
#include "cache.h"
#include "cache_mmu_app.h"
#include "prcm.h"
#include "chipdb.h"
#include "soc.h"
#include "board.h"
#include "console_utils.h"

#ifdef OUTER_CACHE_ENABLE
    #include "pl310.h"
    #include "pl310_config.h"
#endif /* OUTER_CACHE_ENABLE */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Uart instance number- to be fetched from board db and stored in 
           this variable.  */
uint32_t uartInstNum;
/** \brief EDMACC instance number- to be fetched from board db and stored in 
           this variable.  */
uint32_t edmaccInstNum;

/** \brief Demo use-case selection.
            L2_DEMO_AS_SRAM  - L2 as SRAM demo  
            L2_DEMO_AS_CACHE - L2 as cache demo
            CACHE_MMU_DEMO_INVAL
            CACHE_MMU_DEMO_LOCK
 */
uint32_t demoSelection = (L2_DEMO_AS_CACHE | CACHE_MMU_DEMO_CLEAN_INVAL | 
                                              CACHE_MMU_DEMO_LOCK);
    
/** \brief Page table configuration for DDR marked with L1 as non cache-able.*/
mmuMemRegionConfig_t regionL2Sram =
            {   
                START_ADDR_L2_SRAM, 
                NUM_SECTIONS_L2_SRAM, /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_NORMAL_NON_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner */
                MMU_CACHE_POLICY_WB_WA, /* Outer */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/** \brief   This API configures the dependent modules (Uart and EDMA). */
void platformInit(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    int32_t status = S_PASS;
	
    status = BOARDInit(NULL);
    if(S_PASS == status)
    {
	platformInit();
	
	MMUConfigAndEnable();
    
	#ifdef OUTER_CACHE_ENABLE
	PL310Init((uint32_t*)CHIPDBBaseAddress(CHIPDB_MOD_ID_MPU_PL310, 0),
		0xFFFFFFFF, PL310_AUX_CTRL_VAL, 0);
	/* ==== L2 demo as SRAM ==== */
	if(L2_DEMO_AS_SRAM == (demoSelection & L2_DEMO_AS_SRAM))
	{
		MMUMemRegionMap(&regionL2Sram, (uint32_t*)pageTable);
		SOCL2SramConfig(L2_CONFIG_AS_SRAM);
		CACHEAppL2SramDemo();
		/* Should not proceed with cache demo, so stopping here. */
		while(1);
	}
    
	/* ==== Cache operations demo ==== */
	SOCL2SramConfig(L2_CONFIG_AS_CACHE);
	#endif /* OUTER_CACHE_ENABLE */
    
	CACHEAppInitBuffer();
	CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);
    
	/* ==== Cache invalidate & clean demo ==== */
	if(CACHE_MMU_DEMO_CLEAN_INVAL == (demoSelection & 
		CACHE_MMU_DEMO_CLEAN_INVAL))
	{
		CACHEAppInvalidateDemo();
		CACHEAppCleanDemo();
	}
    
	#ifdef OUTER_CACHE_ENABLE
	/* ==== Cache lockdown demo ==== */
	if(CACHE_MMU_DEMO_LOCK == (demoSelection & CACHE_MMU_DEMO_LOCK))
	{
		CACHEAppLockDemo();
	}
	#endif /* OUTER_CACHE_ENABLE */
    }
    while(1);
}

/* Initialize the peripherals needed for this example. */
void platformInit(void)
{
    uartInstNum = 0; /* TODO - get from board db */
    edmaccInstNum = 0; /* TODO - get from chip db */
    
    /* Initialize the UART console */
    CONSOLEUtilsInit();
    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);
    CONSOLEUtilsPrintf("\nStarterWare Cache MMU Application!!\n\n");

    CACHEAppUartInitialize(uartInstNum); /* TODO */
}
