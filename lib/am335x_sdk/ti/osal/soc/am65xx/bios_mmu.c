/*
 *  Copyright (c) Texas Instruments Incorporated 2019
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
 */

/**
 *  \file bios_mmu.c
 *
 *  \brief This has the common default MMU setting function for A53
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <xdc/std.h>
#if defined (BUILD_MPU)
#include <ti/sysbios/family/arm/v8a/Mmu.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#if defined(BUILD_MPU)
void Osal_initMmuDefault(void)
{
    Mmu_MapAttrs    attrs;

    Mmu_initMapAttrs(&attrs);
    attrs.attrIndx = Mmu_AttrIndx_MAIR0;

    /* Register region */
    Mmu_map(0x00000000U, 0x00000000U, 0x20000000U, &attrs);
    Mmu_map(0x20000000U, 0x20000000U, 0x20000000U, &attrs);
    Mmu_map(0x40000000U, 0x40000000U, 0x20000000U, &attrs);
    Mmu_map(0x60000000U, 0x60000000U, 0x10000000U, &attrs);

    Mmu_map(0x400000000U, 0x400000000U, 0x400000000U, &attrs); /* FSS0 data   */

    attrs.attrIndx = Mmu_AttrIndx_MAIR7;
    Mmu_map(0x80000000U, 0x80000000U, 0x20000000U, &attrs); /* DDR */
    Mmu_map(0xA0000000U, 0xA0000000U, 0x20000000U, &attrs); /* DDR */
    Mmu_map(0x70000000U, 0x70000000U, 0x00200000U, &attrs); /* MSMC - 2MB */
    Mmu_map(0x41C00000U, 0x41C00000U, 0x00080000U, &attrs); /* OCMC - 512KB */

    /*
     * DDR range 0xA2000000 - 0xA2200000 : Used as RAM by multiple
     * remote cores, no need to mmp_map this range.
     * IPC VRing Buffer - uncached
     */
    attrs.attrIndx =  Mmu_AttrIndx_MAIR4;
    (void)Mmu_map(0xA2000000U, 0xA2000000U, 0x00200000U, &attrs);

    return;
}
#endif
