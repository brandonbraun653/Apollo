/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
/*                         Include Files                                      */
/* ========================================================================== */

#include <ti/csl/tistdtypes.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
uint32_t CSL_getSocSiliconRev(void)
{
    uint32_t siliconRev = CSL_SOC_SILICON_REV_UNKNOWN;

    siliconRev = HW_RD_REG32(SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE +
                             CTRL_WKUP_ID_CODE);

    siliconRev = (siliconRev & 0xF0000000U) >> 28U;

    return (siliconRev);
}

/* Function to unlock MMR2 register */
uint8_t CSL_unlockMmrLock2(void)
{
    uint8_t unlockStatus = 0;
    CSL_control_coreRegs *ctrlCoreReg =
    (CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS;

    /* Unlock the MMR_LOCK2 register only when it is not in unlock state */
    if(ctrlCoreReg->MMR_LOCK_2 != CTRL_CORE_MMR_LOCK_2_MMR_LOCK_2_TOUNLOCK)
    {
        ctrlCoreReg->MMR_LOCK_2 = CTRL_CORE_MMR_LOCK_2_MMR_LOCK_2_TOUNLOCK;
        unlockStatus = (uint8_t)1U;
    }

    return (unlockStatus);
}

/* Function to lock MMR2 register.
 *
 *   Note: This function is intended be used in conjunction with CSL_unlockMmrLock2.
 *   Locking/Unlocking the MMR_LOCK2 register from different cores in multi-core
 *   environment can lead to race condition. To avoid such scenarios,
 *   CSL_unlockMmrLock2 does the unlock only when register is in lock state and
 *   lock will be done by CSL_lockMmrLock2 based on the state of previous
 *   unlock function.
 *
 *   Value returned by CSL_unlockMmrLock2 should be passed as 'unlockStatus'
 *   parameter to this function.
 *   Pass unlockStatus as '1' to force the lock irrespective of previous unlock.
*/
void CSL_lockMmrLock2(uint8_t unlockStatus)
{
    CSL_control_coreRegs *ctrlCoreReg =
    (CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS;

    if(unlockStatus == (uint8_t)1U)
    {
        ctrlCoreReg->MMR_LOCK_2 = CTRL_CORE_MMR_LOCK_2_MMR_LOCK_2_TOLOCK;
    }
}


