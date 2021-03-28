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

#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGicAux.h>
#include "icss_emac_startup.h"

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

#define MMU_PAGETABLE_ALIGN_SIZE                           (16U * 1024U)

void CopyVectorTable(void);

void systemInit(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Vector table */
static Uint32 const vecTbl[14]=
{
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF014,    /* Opcode for loading PC with the contents of [PC + 0x14] */
    0xE24FF008,    /* Opcode for loading PC with (PC - 8) (eq. to while(1)) */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    (Uint32)Entry,
    (Uint32)UndefInstHandler,
    (Uint32)SVC_Handler,
    (Uint32)AbortHandler,
    (Uint32)IRQHandler,
    (Uint32)FIQHandler
};

CSL_ArmGicDistIntrf distrIntrf;
CSL_ArmGicCpuIntrf gCpuIntrf;

/** \brief Page table configuration.*/
#if 0 /* Enable to use short descriptor */
#elif 0 /* Enable to use short descriptor */

/** \brief Page tables to hold physical to virtual address mapping. The start
           address of the page table must be aligned at 16K boundary */
    #pragma DATA_ALIGN(mmuobj, MMU_PAGETABLE_ALIGN_SIZE);
    CSL_A15MmuShortDescObj mmuobj;
    CSL_A15MmuShortDescObj mmuobj
     __attribute__((aligned(MMU_PAGETABLE_ALIGN_SIZE)));

    CSL_A15MmuShortDescAttr mmuAttr0;
    CSL_A15MmuShortDescAttr mmuAttr1;
    CSL_A15MmuShortDescAttr mmuAttr2;
    CSL_A15MmuShortDescAttr mmuAttr3;
#else

/** \brief Page tables to hold physical to virtual address mapping. The start
           address of the page table must be aligned at 16K boundary */
    CSL_A15MmuLongDescObj mmuObj
     __attribute__((aligned(MMU_PAGETABLE_ALIGN_SIZE)));

    CSL_A15MmuLongDescAttr mmuAttr0;
    CSL_A15MmuLongDescAttr mmuAttr1;
    CSL_A15MmuLongDescAttr mmuAttr2;
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

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
void CopyVectorTable(void)
{
    Uint32 vectorBase = 0x40300000U;
    Uint32 ocmcRamSize = 512U * 1024U;

    vectorBase = vectorBase + ocmcRamSize - 0x400U;

    Uint32 *dest = (Uint32 *)vectorBase;
    Uint32 *src =  (Uint32 *)vecTbl;
    Uint32 count;

    CSL_a15SetVectorTable(vectorBase);

    for(count = 0; count < sizeof(vecTbl)/sizeof(vecTbl[0]); count++)
    {
        dest[count] = src[count];
    }
}

void systemInit(void)
{
    uint32_t phyAddr = 0U;

#if 0 /* Enable to use short descriptor */
#elif 0 /* Enable to use short descriptor */
    mmuobj.numFirstLvlEntires = CSL_A15_MMU_SHORT_DESC_LVL1_ENTIRES;
    CSL_a15InitMmuShortDesc(&mmuobj);

    CSL_a15InitMmuShortDescAttrs(&mmuAttr0);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr1);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr2);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr3);

    mmuAttr0.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr0.accPerm = 0U;

    for (phyAddr = 0x00000000U; phyAddr < 0x80000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr0);
    }

    mmuAttr1.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr1.bufferable = 1U;
    mmuAttr1.accPerm = 3U;
    mmuAttr1.tex = 5U;
    mmuAttr1.nonSecure = 1U;

    for (phyAddr = 0x80000000U; phyAddr < 0xA0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr1);
    }

    mmuAttr2.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr2.accPerm = 0U;

    for (phyAddr = 0xA0000000U; phyAddr < 0xC0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr2);
    }

    mmuAttr3.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr3.accPerm = 0U;

    for (phyAddr = 0xC0000000U; phyAddr < 0xE0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr3);
    }

    CSL_a15EnableMmu();
    CSL_a15EnableCache();
//#else
    mmuObj.numFirstLvlEntires = CSL_A15_MMU_LONG_DESC_LVL1_ENTIRES;
    mmuObj.numSecondLvlEntires = CSL_A15_MMU_LONG_DESC_LVL2_ENTIRES;
    mmuObj.mairEntires = CSL_A15_MMU_MAIR_LEN_BYTES;
    mmuObj.mairAttr[0] = 0x44U;
    mmuObj.mairAttr[1] = 0x0U;
    mmuObj.mairAttr[2] = 0xFFU;
    CSL_a15InitMmuLongDesc(&mmuObj);

    CSL_a15InitMmuLongDescAttrs(&mmuAttr0);
    CSL_a15InitMmuLongDescAttrs(&mmuAttr1);
    CSL_a15InitMmuLongDescAttrs(&mmuAttr2);

    mmuObj.mairAttr[0] = 0x44U;
    mmuObj.mairAttr[1] = 0x0U;
    mmuObj.mairAttr[2] = 0xFFU;
    CSL_a15SetMmuMair(0, mmuObj.mairAttr[0]);
    CSL_a15SetMmuMair(1, mmuObj.mairAttr[1]);
    CSL_a15SetMmuMair(2, mmuObj.mairAttr[2]);

    mmuAttr0.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr0.accPerm = 0U;
    mmuAttr1.shareable = 2U;
    mmuAttr0.attrIndx = 1U;

    for (phyAddr = 0x00000000U; phyAddr < 0x60000000U; phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr0);
    }

    mmuAttr1.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr1.accPerm = 0U;
    mmuAttr1.shareable = 2U;
    mmuAttr1.attrIndx = 2U;

    for (phyAddr = 0x80000000; phyAddr < 0xA0000000; phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr1);
    }

    mmuAttr2.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr2.accPerm = 0U;
    mmuAttr2.attrIndx = 0U;

    for (mmuAttr2.phyAddr[0U] = 0xA0000000; mmuAttr2.phyAddr[0U] < 0xB0000000;
        mmuAttr2.phyAddr[0U] += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr2);
    }

    CSL_a15EnableMmu();
    CSL_a15EnableCache();
#endif

    gCpuIntrf.gicDist = &distrIntrf;
    gCpuIntrf.cpuIntfBasePtr = (void *)0x48212000U;
    distrIntrf.distBasePtr = (void *)0x48211000U;
    gCpuIntrf.initStatus = FALSE;
    gCpuIntrf.gicDist->initStatus = FALSE;
    gCpuIntrf.pDefaultIntrHandlers = NULL;
    gCpuIntrf.pDefaultUserParameter = NULL;

    CSL_armGicInit(&gCpuIntrf);
}
