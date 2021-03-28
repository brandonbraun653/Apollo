/**
 *  \file   pl310.h
 *
 *  \brief  This file contains the structure, macros and APIs declarations
 *          of pl310 cache controller.
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

#ifndef PL310_H_
#define PL310_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_pl310.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure defining PL310 cache controller registers. */
typedef struct pl310Regs
{
    uint32_t auxCtrl;
    /**< Axillary control register */
    uint32_t tagLatency;
    /**< TAG ram latency control register */
    uint32_t dataLatency;
    /**< DATA ram latency control register */
    uint32_t filterStart;
    /**< Address filtering start address */
    uint32_t filterEnd;
    /**< Address filtering end address */
    uint32_t prefetchCtrl;
    /**< Address pre-fetch control register */
    uint32_t pwrCtrl;
    /**< Power control register */
    uint32_t ctrl;
    /**< Control register */
    uint32_t debugCfg;
    /**< Debug configuration register */
    uint32_t interruptMask;
    /**< Interrupt mask configuration */
}pl310Regs_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API initializes the PL310 cache controller. The different
 *          configuration parameters are to be passed by the user. It also
 *          initializes some of the properties (which are SoC specific) from
 *          configuration file (including latencies).
 *
 * \param   pPL310BaseAddr Base address of the PL310 cache controller.
 * \param   auxMask        Mask of bits which need to be changed
 * \param   auxVal         Properties to be configured which includes,
 *                          - cache behaviour
 *                          - event monitoring
 *                          - way size
 *                          - associativity
 * \param   isCpuSecure Security state of the CPU
 *
 * \retval  S_PASS PL310 is initialized successfully.
 * \retval  E_INVALID_OPERATION Parameter passed is invalid.
 **/
uint32_t PL310Init(uint32_t* pPL310BaseAddr, uint32_t auxMask, uint32_t auxVal,
                                                         uint32_t isCpuSecure);

/**
 * \brief   This API provides the interface to disable the cache. PL310 cache
 *          alone can be disabled while previous levels are enabled. This API
 *          can be called independent of previous levels.
 *
 * Note: The below sequence need rework if exclusive configuration is enabled.
 *       This implementation assumes that the prior cache levels are still
 *       enabled.
 **/														
void PL310Disable(void);

/**
 * \brief   This API is used to force specific cache behaviour required for debug.
 *
 * \param   dbgConfigVal Write-back and line-fill operation can be enabled/disabled.
 **/
void PL310DebugConfig(uint32_t dbgConfigVal);

/**
 * \brief   This API saves the context of PL310. This API has to be called
 *          before entering sleep state and before clock and power gating of
 *          PL310 module.
 **/
void PL310SaveContext(void);

/**
 * \brief   This API restores the context of PL310. This API has to be called
 *          after waking from sleep state and after power and clock un-gating.
 **/
void PL310RestoreContext(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* PL310_H_ */

