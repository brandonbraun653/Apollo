/**
 * @file   osdrv_ndkdeviceconfig.c
 *
 * @brief  
 *
 * 
*/

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "osdrv_ndkdeviceconfig.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */ 

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint32_t nimuDeviceIndex = 0;
static HANDLE nimuEmacHandle[MAX_ICSSNIMU_TBL_ENTRIES];
NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[MAX_ICSSNIMU_TBL_ENTRIES];

/*
 * Desc
 * 		 This API adds initialization function to NDK device table,
 * 		  that will be executed by NDK on startup. This needs to be called before BIOS_Start
 * Params
 * 		 CPSW_NETIF_INIT - To initiate CPSW driver
 * 		 ICSS_NETIF_INIT - To initiate ICSS Netif driver
 * Return
 * 		0 - Failure
 * 		1 - Success
 *
 */
int32_t OSDRV_addNetifEntry(NIMUInitFn initFct,HANDLE emacHandle)
{

	 if(initFct == NULL)
		 return -1;

	 if(nimuDeviceIndex < MAX_ICSSNIMU_TBL_ENTRIES)
	 {
		 NIMUDeviceTable[nimuDeviceIndex].init =  initFct ;
		 nimuEmacHandle[nimuDeviceIndex++] = emacHandle;
		 NIMUDeviceTable[nimuDeviceIndex].init =  NULL ;
	 }
	 else
		 return -1;

	 return 1;
}

HANDLE OSDRV_getNetifHandle(uint32_t inst)
{
	return nimuEmacHandle[inst];
}
