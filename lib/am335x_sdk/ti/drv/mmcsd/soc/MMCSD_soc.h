/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       MMCSD_soc.h
 *
 *  @brief      MMC driver implementation for a am57x MMC controller.
 *
 *  The MMC header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/mmcsd/MMCSD.h>
 *  #include <ti/drv/mmcsd/soc/MMCSD_soc.h>
 *  @endcode
 *
 *
 *  ============================================================================
 */

#ifndef MMCSD_SOC__H
#define MMCSD_SOC__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_chip.h>
#include <ti/osal/osal.h>

#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x) || defined (SOC_AM335x) || defined (SOC_AM437x) || defined(SOC_K2G)
#include <ti/drv/mmcsd/soc/MMCSD_v1.h>
#elif defined (SOC_OMAPL137) || defined(SOC_OMAPL138)
#include <ti/drv/mmcsd/soc/MMCSD_v0.h>
#elif defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#include <ti/drv/mmcsd/soc/MMCSD_v2.h>
#endif


#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
   #define MMCSD_CNT CSL_MPU_MMCHS_CNT
#elif defined(SOC_AM437x) || defined (SOC_AM335x)
   #define MMCSD_CNT 3
#elif defined(SOC_DRA72x) || defined(SOC_DRA75x)
   #define MMCSD_CNT CSL_MMCHS_CNT
#elif defined(SOC_DRA78x)
   #define MMCSD_CNT 1
#elif defined(SOC_K2G)
   #define MMCSD_CNT CSL_MMCSD_CNT
#elif defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
	#define MMCSD_CNT CSL_MMCSD_CNT
#elif defined(SOC_AM65XX)
	#define MMCSD_CNT 2
#elif defined(SOC_J721E)
	#define MMCSD_CNT 3
#elif defined(SOC_J7200)
	#define MMCSD_CNT 2
#endif
#ifdef __cplusplus
}
#endif

/*
* This function converts the local L2 address to a global address and
* will be used for DMA transactions which needs a global address.
*/
uint32_t MMCSD_soc_l2_global_addr (uint32_t addr);

/*
* This function switches the voltage of the CMD & DAT lines of MMCSD instance (1.8V <-> 3.0V)
* during initialization if a UHS-1 card is found. This function is board specific and is implemented
* by the Board library.
*/
extern MMCSD_Error Board_mmc_voltageSwitchFxn(uint32_t instance, MMCSD_BusVoltage_e switch_voltage);

/* This function will configure the interrupt path to the destination CPU
*  using DMSC firmware via sciclient. if setIntrPath is set to TRUE, 
*  a path is set, else the interrupt path is released
*/
extern MMCSD_Error MMCSD_configSocIntrPath(const void *hwAttrs_ptr,bool setIntrPath);

/* This SOC function will initialize InitConfig[] as per the core/subsystem
* the driver is running on. This includes domain specific parameters such as
* intNum, baseAddress etc.
*/
extern MMCSD_Error MMCSD_socInit(void);
#endif /* _MMCSD_SOC_H */
