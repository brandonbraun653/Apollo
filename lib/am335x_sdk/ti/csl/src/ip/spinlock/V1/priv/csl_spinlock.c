/**
 * @file  csl_spinlock.c
 *
 * @brief
 *  Implementation file for the SPINLOCK module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2019, Texas Instruments, Inc.
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

#include <ti/csl/cslr_spinlock.h>
#include <ti/csl/csl_spinlock.h>

#define CSL_SPINLOCK_SYSCONFIG_SOFTRESET_DORESET                (0x00000001U)
#define CSL_SPINLOCK_SYSCONFIG_SOFTRESET_RESETDONE              (0x00000001U)
#define CSL_SPINLOCK_LOCK_REG_TAKEN_FREE                        (0x00000000U)
#define CSL_SPINLOCK_LOCK_REG_TAKEN_BUSY                        (0x00000001U)
#define CSL_SPINLOCK_SYSTATUS_MAX_LOCK_GROUPS                   (8U)

/*=============================================================================
 *    CSL-FL functions
 *===========================================================================*/
uint32_t SPINLOCKRevision(uint32_t baseAddr)
{
    uint32_t         ret;
    CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);

    ret = CSL_REG32_RD(&pSpinlockRegs->REVISION);

    return (ret);
}

uint32_t SPINLOCKGetNumLocks(uint32_t baseAddr)
{
    uint32_t         numLocks;
    CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);

    numLocks = CSL_REG32_FEXT(&pSpinlockRegs->SYSTATUS,
        SPINLOCK_SYSTATUS_NUMLOCKS);
    numLocks *= 32U;    /* # locks is 32 * field value read */

    return (numLocks);
}

uint32_t SPINLOCKSystatus(uint32_t baseAddr)
{
    /*-------------------------------------------------------------------------
     *  The prior CSL-FL returned the value of the RESETDONE field. The K3
     *  version of this IP does not have a RESETDONE field, so we will simply
     *  return 1 here.
     *  status = HW_RD_FIELD32(baseAddr + SPINLOCK_SYSTATUS,
     *      SPINLOCK_SYSTATUS_RESETDONE);
     *-----------------------------------------------------------------------*/
    return (CSL_SPINLOCK_SYSCONFIG_SOFTRESET_RESETDONE);
}

uint32_t SPINLOCKSystatusIU(uint32_t baseAddr, uint32_t lockGroup)
{
    uint32_t status = CSL_SPINLOCK_ERROR_RETURN;

    if( lockGroup < CSL_SPINLOCK_SYSTATUS_MAX_LOCK_GROUPS )
    {
        CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);
        status = CSL_REG32_RD(&pSpinlockRegs->SYSTATUS);
        status = (status >> lockGroup) & 1U;
    }
    return (status);
}

uint32_t SPINLOCKSystatusIU0(uint32_t baseAddr)
{
    return (SPINLOCKSystatusIU(baseAddr, 0));
}

void SPINLOCKModuleReset(uint32_t baseAddr)
{
    CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);
    /*
     * Set the SOFTRESET bit in System Configuration register.
     * Doing so would reset the Spinlock module.
     */
    CSL_REG32_FINS(&pSpinlockRegs->SYSCONFIG,
        SPINLOCK_SYSCONFIG_SOFTRESET,
        CSL_SPINLOCK_SYSCONFIG_SOFTRESET_DORESET);
}

uint32_t SPINLOCKLockStatusSet(uint32_t baseAddr, uint32_t lockNumber)
{
    uint32_t         lockStatus = (uint32_t)CSL_SPINLOCK_ERROR_RETURN;
    CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);

    if( lockNumber < SPINLOCKGetNumLocks(baseAddr) )
    {
        lockStatus = CSL_REG32_FEXT(&pSpinlockRegs->LOCK_REG[lockNumber],
            SPINLOCK_LOCK_REG_TAKEN);
    }
    return (lockStatus);
}

void SPINLOCKLockStatusFree(uint32_t baseAddr, uint32_t lockNumber)
{
    CSL_spinlockRegs *pSpinlockRegs = (CSL_spinlockRegs *)((uintptr_t)baseAddr);

    if( lockNumber < SPINLOCKGetNumLocks(baseAddr) )
    {
        CSL_REG32_FINS(&pSpinlockRegs->LOCK_REG[lockNumber],
            SPINLOCK_LOCK_REG_TAKEN,
            CSL_SPINLOCK_LOCK_REG_TAKEN_FREE);
    }
}
