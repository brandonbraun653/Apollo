/**
 * \file   icss_emacStartup.c
 *
 * \brief  Interrupt vector is copied to the internal Ram. After that the
 *         control is given to the application.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#include "types.h"
#include "hw_types.h"
#include "cp15.h"
#include "cache.h"
#include "chipdb.h"
#include "misc.h"
#include "app_startup.h"
#include "example_utils_mmu.h"

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static void CopyVectorTable(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Vector table */
static uint32_t const vecTbl[14]=
{
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF014,    /* Opcode for loading PC with the contents of [PC + 0x14] */
    0xE24FF008,    /* Opcode for loading PC with (PC - 8) (eq. to while(1)) */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    (uint32_t)Entry,
    (uint32_t)UndefInstHandler,
    (uint32_t)SVC_Handler,
    (uint32_t)AbortHandler,
    (uint32_t)IRQHandler,
    (uint32_t)FIQHandler
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/******************************************************************************
@ This API sets the interrupt vector table base address 
@ r0 - Interrupt Vector Base Address
@******************************************************************************
*/
#ifdef __cplusplus
void VectorBaseAddrSet(uint32_t vectorBase)
#else
void VectorBaseAddrSet()
#endif
{
       asm("   MCR       p15, #0, r0, c12, c0, #0\n\t"
           "   DSB\n\t");
}

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
int32_t start_boot(void)
{
    /* Copy the vector table to desired location.  */
    CopyVectorTable();

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();

    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /* Calling the main */
    main();

    while(1)
    {}
}

/**
 * \brief   This function copies the vector table to a location in OCMC
 *          RAM and sets the vector base address register.
 *
 * \param   None.
 * \retval  None.
 *
 * Note: The default vector table base is in OCMC RAM, but can be moved to
 *       other locations, to make some more space in OCMC RAM for relocating any
 *       other code, if desired. The vector table can be placed anywhere in the
 *       memory map. If the entire code is intended to be run from DDR, it can be
 *       placed in DDR also. In this case, only vector base address register need
 *       to be set with the base address of the vector table.
 */
static void CopyVectorTable(void)
{
    uint32_t ocmcRamSize = 64U * 1024U;
    uint32_t vectorBase = 0x40300000U;

    vectorBase = vectorBase + ocmcRamSize - 0x400U;

    uint32_t *dest = (uint32_t *)vectorBase;
    uint32_t *src =  (uint32_t *)vecTbl;
    uint32_t count;

    VectorBaseAddrSet(vectorBase);

    for(count = 0; count < sizeof(vecTbl)/sizeof(vecTbl[0]); count++)
    {
        dest[count] = src[count];
    }
}

/* Nothing past this point */
