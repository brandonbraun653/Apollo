/*
 *  Copyright (c) 2017, Texas Instruments Incorporated
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/*
 * ======== exceptionHandler.asm ========
 */

#include <ti/csl/arch/a53/intMacros.h>

        .global CSL_armGicDispatchIRQ
        .global CSL_armGicDefaultExcHandler
        .global IntCommonHandler
        .global IntDefaultHandler

        .align  2

/*
 *  ======== CSL_armGicDispatchIRQ ========
 *
 *  Void CSL_armGicDispatchIRQ(Bool usingEL0Stack);
 */

        .section .text.CSL_armGicDispatchIRQ, "ax"
        .func CSL_armGicDispatchIRQ

CSL_armGicDispatchIRQ:
        mov     x19, x0              /* copy 'usingEL0Stack' argument */
        mrs     x0, spsr_el1
        mrs     x1, elr_el1
        stp     x0, x1, [sp, #-16]!  /* save spsr_el1 and elr_el1 */
#if defined(__ARM_FP)
        mrs     x0, fpcr
        mrs     x1, fpsr
        stp     x0, x1, [sp, #-16]!  /* save fpcr and fpsr */
#endif

        /* call dispatchIRQC */
        mrs     x0, elr_el1          /* pass IRP to dispatchIRQC() */
        ldr     x1, =IntCommonHandler
        blr     x1

                                    /* returns with interrupts disabled */
#if defined(__ARM_FP)
        ldp     x0, x1, [sp], #16
        msr     fpcr, x0
        msr     fpsr, x1
#endif
        ldp     x0, x1, [sp], #16
        msr     spsr_el1, x0
        msr     elr_el1, x1
#if defined(__ARM_FP)
        POP_CALLER_SAVE_FPU_REGS sp  /* restore vfp scratch regs */
#endif
        POP_CALLER_SAVE_CPU_REGS sp  /* restore cpu scratch regs */
        eret
        .endfunc

/*
 *  ======== CSL_armGicDefaultExcHandler ========
 *
 *  Void CSL_armGicDefaultExcHandler(Bool usingEL0Stack);
 */

        .section .text.CSL_armGicDefaultExcHandler, "ax"
        .func CSL_armGicDefaultExcHandler

CSL_armGicDefaultExcHandler:

        mov     x19, x0              /* copy 'usingEL0Stack' argument */
        mrs     x0, spsr_el1
        mrs     x1, elr_el1
        stp     x0, x1, [sp, #-16]!  /* save spsr_el1 and elr_el1 */
#if defined(__ARM_FP)
        mrs     x0, fpcr
        mrs     x1, fpsr
        stp     x0, x1, [sp, #-16]!  /* save fpcr and fpsr */
#endif

        /* call dispatch default handler */
        mrs     x0, elr_el1          /* pass IRP to dispatchIRQC() */
        ldr     x1, =IntDefaultHandler
        blr     x1

                                    /* returns with interrupts disabled */
#if defined(__ARM_FP)
        ldp     x0, x1, [sp], #16
        msr     fpcr, x0
        msr     fpsr, x1
#endif
        ldp     x0, x1, [sp], #16
        msr     spsr_el1, x0
        msr     elr_el1, x1
#if defined(__ARM_FP)
        POP_CALLER_SAVE_FPU_REGS sp  /* restore vfp scratch regs */
#endif
        POP_CALLER_SAVE_CPU_REGS sp  /* restore cpu scratch regs */
        eret
        .endfunc