/**
 * \file   a53_startup.c
 *
 * \brief  Interrupt vector is copied to the internal Ram. After that the
 *         control is given to the application.
 *
 *  \copyright Copyright (C) 2017-2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/tistdtypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ti/csl/arch/a53/interrupt.h>
#include <ti/csl/arch/a53/csl_a53v8cache.h>
#include <ti/csl/arch/a53/csl_a53v8misc.h>
#include <ti/csl/arch/a53/csl_a53.h>
#include <ti/csl/arch/a53/src/startup/aarch64/boot_defs.h>

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */
extern void (*__init_array_start []) (void);
extern void (*__init_array_end []) (void);
extern unsigned int __bss_start__, __bss_end__;
extern unsigned int __data_load__, __data_start__, __data_end__;
extern int main();
uint64_t TTBR3_BASE_ADDR, TTBR2_BASE_ADDR, TTBR1_BASE_ADDR;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/* None */

/**
 * \brief   This function does two operations:\n
 *          1> Copies an array which contains vector table values to the
 *             processor's vector table space.\n
 *          2> Then it calls the main() function.\n
 *
 * \param   None.
 *
 * \retval  None.
 *
 * \note    This function is the first function that needs to be called in a
 *          system. This should be set as the entry point in the linker script
 *          file if the ELF executable is to loaded via a debugger on the
 *          target. This function never returns, but gives control to the
 *          application entry point.
 **/
uint32_t start_boot(void); /*for misra warnings*/
uint32_t start_boot(void)
{
    unsigned int * bs;
    unsigned int * be;
    unsigned int * dl;
    unsigned int * ds;
    unsigned int * de;
    uint64_t      cpuId;
    uint8_t       coreId;

    cpuId = CSL_a53v8GetCpuId();
    coreId = (uint8_t) cpuId & (uint8_t)0xFFU;

    /* initiailize .bss to zero */
    bs = & __bss_start__;
    be = & __bss_end__;
    while (bs < be) {
        *bs = 0;
        bs++;
    }

    /* relocate the .data section */
    dl = & __data_load__;
    ds = & __data_start__;
    de = & __data_end__;
    if (dl != ds) {
        while (ds < de) {
            *ds = *dl;
            dl++;
            ds++;
        }
    }

    /* Default: initialize mmu and cache */
    /* Set CPUECTLR.SMPEN bit to enable data coherency */
    CSL_a53v8EnableDataCoherency();
    CSL_mmuStartup();

    /* Initialize the GIC V3 */
    Intc_Init(coreId);

    /* Calling the main */
    main();

#if defined (SOC_J721E)
    CSL_a53Exit();
#endif

    return(0);
}

/* Nothing past this point */
