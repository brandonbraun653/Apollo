/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
 * \file hw_pmhal_prmdata.c
 *
 * \brief   PRCM Interrupt Internal API Implementation specific to the device.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/csl/hw_types.h>
#include "pm_types.h"
#include "pmhal_prcm.h"
#include "pmhal_prcm_includes.h"
#include "common/hw_pmhal_prmdata.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmErrCode_t PmhalPrmIntGetIrqEnAddrShift(pmhalPrcmSocCpuId_t cpuId,
                                         pmhalPrcmPrmIntId_t intId,
                                         uint32_t           *addr,
                                         uint32_t           *shift)
{
    pmErrCode_t status = PM_SUCCESS;

    switch (cpuId)
    {
        case PMHAL_PRCM_SOC_CPU_ID_MPU:
            *addr = SOC_OCP_SOCKET_RAM_REGS + PRCM_OCP_SOCKET_PRM_IRQEN_MPU;
            *shift = (uint32_t) intId;
            break;
        default:
            status = PM_INPUT_PARAM_BAD_CPU_ID;
            break;
    }

    return status;
}

pmErrCode_t PmhalPrmIntGetIrqStAddrShift(pmhalPrcmSocCpuId_t cpuId,
                                         pmhalPrcmPrmIntId_t intId,
                                         uint32_t           *addr,
                                         uint32_t           *shift)
{
    pmErrCode_t status = PM_SUCCESS;

    switch (cpuId)
    {
        case PMHAL_PRCM_SOC_CPU_ID_MPU:
            *addr = SOC_OCP_SOCKET_RAM_REGS + PRCM_OCP_SOCKET_PRM_IRQSTS_MPU;

            if (intId == PMHAL_PRCM_PRM_INT_DPLL_DISP_RECAL)
            {
                *shift = (uint32_t) intId - 2U;
            }
            else if (intId == PMHAL_PRCM_PRM_INT_DPLL_PER_RECAL)
            {
                *shift = (uint32_t) intId + 2U;
            }
            else
            {
                *shift = (uint32_t) intId;
            }
            break;
        default:
            status = PM_INPUT_PARAM_BAD_CPU_ID;
            break;
    }
    return status;
}

pmErrCode_t PmhalPrmIntGetIrqEnAddr(pmhalPrcmSocCpuId_t cpuId,
                                    uint32_t           *addr)
{
    pmErrCode_t status = PM_SUCCESS;

    switch (cpuId)
    {
        case PMHAL_PRCM_SOC_CPU_ID_MPU:
            *addr = SOC_OCP_SOCKET_RAM_REGS + PRCM_OCP_SOCKET_PRM_IRQEN_MPU;
            break;
        default:
            status = PM_INPUT_PARAM_BAD_CPU_ID;
            break;
    }

    return status;
}

pmErrCode_t PmhalPrmIntGetIrqStAddr(pmhalPrcmSocCpuId_t cpuId,
                                    uint32_t           *addr)
{
    pmErrCode_t status = PM_SUCCESS;

    switch (cpuId)
    {
        case PMHAL_PRCM_SOC_CPU_ID_MPU:
            *addr = SOC_OCP_SOCKET_RAM_REGS + PRCM_OCP_SOCKET_PRM_IRQSTS_MPU;
            break;
        default:
            status = PM_INPUT_PARAM_BAD_CPU_ID;
            break;
    }

    return status;
}

void PmhalPrmIntGetEnabledInts(uint32_t cpuId, uint32_t addr,
                               uint64_t *interrupts)
{
    uint32_t regVal = HW_RD_REG32(addr);
    *interrupts |= (uint64_t) regVal;
}

void PmhalPrmIntConfigRegister(uint32_t cpuId, uint32_t addr, uint32_t regVal)
{
    HW_WR_REG32(addr, regVal);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

