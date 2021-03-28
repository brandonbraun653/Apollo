/**
 *  \file   rom_config.h
 *
 *  \brief  This file contains the configurations which are defined by ROM. 
 *          These configurations can change between Soc's.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/*
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

#ifndef ROM_CONFIG_H_
#define ROM_CONFIG_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** SMC ID's for am43xx */
/** Base address of SMC ID's */
#define SMC_ID_BASE		        (0x100U)
/** SMC ID of debug register configuration */
#define SMC_ID_SET_DEBUG_REG            (SMC_ID_BASE + 0x0U)
/** SMC ID of cache clean and invalidate by physical address */
#define SMC_ID_CLEAN_INV_PHY_ADDR       (SMC_ID_BASE + 0x1U)
/** SMC ID of control register configuration */
#define SMC_ID_CTRL_REG                 (SMC_ID_BASE + 0x2U)
/** SMC ID of auxillary register configuration */
#define SMC_ID_AUX_CTRL_REG             (SMC_ID_BASE + 0x9U)
/** SMC ID of TAG RAM and DATA RAM configuration */
#define SMC_ID_TAG_DATA_RAM_LAT_CTRL    (SMC_ID_BASE + 0x12U)
/** SMC ID of pre-fetch control configuration */
#define SMC_ID_PREFETCH_CTRL_REG        (SMC_ID_BASE + 0x13U)
/** SMC ID of address filtering configuration */
#define SMC_ID_ADDR_FILTER_REG          (SMC_ID_BASE + 0x14U)
/** SMC ID of clean the cache by way */
#define SMC_ID_CLEAN_SET_WAY            (SMC_ID_BASE + 0x15U)
/** SMC ID to enable cache pre-fetch */
#define SMC_ID_L1_CACHE_PREFETCH_ENABLE (SMC_ID_BASE + 0x16U)
/** SMC ID to enable round robin cache replacement policy */
#define SMC_ID_SCTLR_ROUND_ROBIN_ENABLE (SMC_ID_BASE + 0x17U)
/** SMC ID to configure CP15 axillary control register */
#define SMC_ID_CP15_ACTLR_REG		(SMC_ID_BASE + 0x18U)

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ROM_CONFIG_H_ */
