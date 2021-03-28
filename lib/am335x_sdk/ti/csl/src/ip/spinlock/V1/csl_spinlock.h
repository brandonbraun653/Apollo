/**
 * @file  csl_spinlock.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the SPINLOCK IP.
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
#ifndef CSL_SPINLOCK_H_
#define CSL_SPINLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/cslr_spinlock.h>

/** ===========================================================================
 *
 * @defgroup CSL_SPINLOCK_API (SPINLOCK)
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 *
 * @subsection References
 *    -# Spinlock Functional Specification, version 1.0.1
 * ============================================================================
 */

/**
@defgroup CSL_SPINLOCK_FUNCTION  SPINLOCK Functions
@ingroup CSL_SPINLOCK_API
*/

#define CSL_SPINLOCK_ERROR_RETURN   ((uint32_t)-1)

/** ===========================================================================
 *  @addtogroup CSL_SPINLOCK_FUNCTION
    @{
 * ============================================================================
 */

/**
 * \brief   This API provides the SPINLOCK_REVISION of the SPINLOCK module.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \return  Revision Number.\n
 *
 */
extern uint32_t SPINLOCKRevision(uint32_t baseAddr);

/**
 * \brief   This API provides returns the number of locks supported.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \return  Number of locks.\n
 *
 */
extern uint32_t SPINLOCKGetNumLocks(uint32_t baseAddr);

/**
 * \brief   This API provides the status of each bank of 32 locks that
 *         can be read from the SPINLOCK_SYSTATUS register.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \return  Current Status of the lock.\n
 *          Reset done status :\n
 *                  Read 0x0: Reset in progress.\n
 *                  Read 0x1: Reset is completed.\n
 *
 */
extern uint32_t SPINLOCKSystatus(uint32_t baseAddr);

/**
 * \brief   This API provides the lock status of the Spinlock module.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \return  Lock status.\n
 *          In-Use flag 0, covering lock registers 0 - 31.\n
 *          Read 0x0: All lock registers 0-31 are in the Not Taken
 *                    state.(Free)\n
 *          Read 0x1: At least one of the lock registers 0-31 is in the Taken
 *                    state.\n
 *
 */
extern uint32_t SPINLOCKSystatusIU0(uint32_t baseAddr);

/**
 * \brief   This API provides the lock status of the specified group
 *          of lock registers.\n
 *
 * \param   baseAddr    Memory address of SPINLOCK module.\n
 *
 * \param   lockGroup   The lock group. Each lock group contains 32 lock
 *                      registers. Group 0 contains lock registers 0-31,
 *                      group 1 contains lock registers 32-63, etc.
 *                      There are a maximum of 8 lock groups.\n
 *
 * \return  Lock status.\n
 *          Read 0x0: All lock registers in the lock group are in the Not
 *                    Taken state.(Free)\n
 *          Read 0x1: At least one of the lock registers in the lock group
 *                    is in the Takenstate.\n
 *          Read CSL_SPINLOCK_ERROR_RETURN: lockGroup is invalid
 *                    (out of range).\n
 *
 */
extern uint32_t SPINLOCKSystatusIU(uint32_t baseAddr, uint32_t lockGroup);

/**
 * \brief   This API performs the module reset of the Spinlock module. It also
 *          waits until the reset process is complete.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \return  None.\n
 *
 */
extern void SPINLOCKModuleReset(uint32_t baseAddr);

/**
 * \brief   This API performs the Read operation for Lock status of the
 *          SPINLOCK_LOCK_REG, in order to acquire a Spinlock.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \param   lockNumber    Lock number in Spinlock module that should be
 *                        acquired.\n
 *
 * \return  Status of the Lock Register.\n
 *          Lock state :\n
 *              Read 0x0: Lock was previously NOT Taken(Free). The requester is
 *                        granted the lock.\n
 *              Read 0x1: Lock was previously Taken(Not Free). The requester is
 *                        not granted the lock and must retry.\n
 *              Read CSL_SPINLOCK_ERROR_RETURN: lockNumber is invalid
 *          `             (out of range).\n
 *
 */
extern uint32_t SPINLOCKLockStatusSet(uint32_t baseAddr, uint32_t lockNumber);

/**
 * \brief   This API performs the write operation for Lock status of the
 *          SPINLOCK_LOCK_REG, in order to Free the lock.\n
 *          If lockNumber is invalid (out of range), no operation is performed.\n
 *          Lock state :\n
 *             Write 0x0: Set the lock to Not Taken(Free).\n
 *             Write 0x1: No update to the lock value.\n
 *
 * \param   baseAddr       Memory address of SPINLOCK module.\n
 *
 * \param   lockNumber    Lock number in Spinlock module that should be
 *                        released.\n
 *
 * \return  None.\n
 *
 */
extern void SPINLOCKLockStatusFree(uint32_t baseAddr, uint32_t lockNumber);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
