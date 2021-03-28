/* =============================================================================
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

/**
 * \file    pmlib_cpuidle_c66x.c
 *
 * \brief   This file declares the interface for DSP CPU Idle functionality.
 *          This is a low latency power saving mode which allows fast wakeup
 *          depending on the power mode set.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>

#include "c6x.h"

#include "pm_types.h"
#include "pmhal_pmmc.h"
#include "pmlib_cpuidle_pmmc.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief Execute IDLE instruction.
 *
 *        This function is called by CPU Idle API to execute IDLE.
 *
 * \param none
 *
 * \return none
 **/
static void PmlibDoWFI(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmErrCode_t PMLIBPmmcCpuIdle(void)
{
    pmErrCode_t status = PM_SUCCESS;

    /* Perform the DSP Idle sequence */
    PmlibDoWFI();

    return status;
}

pmErrCode_t PMLIBPmmcCpuModeModify(pmhalPmmcModuleId_t moduleId, uint32_t mode)
{
    pmErrCode_t status;

    status = PMHALPmmcModuleSetState(moduleId, mode,
                                     PMHAL_PMMC_TIMEOUT_DEFAULT);

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* The following sections are placed in the DSP L2 RAM to ensure that when the
 * DSP is going to power down state the DSP XMC does not prefetch any more
 * instructions from the external memories outside the DSP subsystem.
 */
#ifdef __cplusplus
#pragma CODE_SECTION(".pmIdleFunc")
#else
#pragma CODE_SECTION(PmlibDoWFI, ".pmIdleFunc")
#endif
static void PmlibDoWFI(void)
{
    /* The MFENCE instruction stalls the instruction fetch pipeline until
     * the memory system busy flag goes low.
     * Invalidate prefetch buffer contents.
     * INV = 1 invalidates both program and data prefetch buffers.
     * When invalidating the prefetch buffers, XMC blocks all incoming requests
     * until the prefetch buffers are completely idle. XMC waits for all
     * outstanding hits to resolve and all outstanding prefetches to return.
     * Once idle, XMC returns both buffers to their reset state.
     */
    asm (
        "IDLE_STEP:    dint                    ; Disable Interrupts GIE = 0    \n\t"
        "               mfence                  ; Stall Prefetch Pipeline       \n\t"
        "               mvk         0x0300,b5   ; Get the XPFCMD address        \n\t"
        "               mvkh        0x8000000,b5                                \n\t"
        "           ||  mvk         1,b4        ; Set INV = 1                   \n\t"
        "               stw         b4,*b5[0]                                   \n\t"
        "               add         4,b5,a3     ; Read XPFACS                   \n\t"
        "               ldw         *+a3[0],a3                                  \n\t"
        "               nop                     ; pad rest of fetch packet      \n\t"
        "               ; idle the CPU with a simultaneous interrupt enable     \n\t"
        "               ; (GIE=1)                                               \n\t"
        "               mvc csr, b4                                             \n\t"
        "               or 1, b4, b4            ; set GIE                       \n\t"
        "               mvc b4, csr             ; Parallel Execution of Setting \n\t"
        "           ||  idle                    ; GIE And IDLE instruction      \n\t"
        "               nop                     ; pad rest of fetch packet      \n\t"
        "               nop                                                     \n\t"
        );
}

