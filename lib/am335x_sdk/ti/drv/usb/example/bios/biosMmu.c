/**
 * \copyright  Copyright (C) 2018-2019 Texas Instruments Incorporated -
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
 */

/* 
 * This file contains mpu settings
 */
#include <stdio.h>
#include <xdc/runtime/System.h>

#if (defined (SOC_AM65XX) && defined (BUILD_MPU))

#include <ti/sysbios/family/arm/v8a/Mmu.h>
#include <ti/csl/soc.h>

/* the following MSMC definitions are for non-cache region. I
   it matches with the ti/build/am65xx linker files */
#define MSMC_NON_CACHE_START_ADDR   0x701F2000
#define MSMC_NON_CACHE_SIZE         0xe000

void InitMmu(void)
{
    Bool retVal;
    uint32_t     mapIdx = 0;
    Mmu_MapAttrs attrs;

    Mmu_initMapAttrs(&attrs);

    attrs.attrIndx = 0;

    retVal = Mmu_map(0x00100000, 0x00100000, 0x00900000, &attrs); /* Main MMR0 cfg  */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x00400000, 0x00400000, 0x00001000, &attrs); /* PSC0          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x01800000, 0x01800000, 0x00100000, &attrs); /* gicv3       */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }
    
    mapIdx++;
    retVal = Mmu_map(0x02400000, 0x02400000, 0x000c0000, &attrs); /* dmtimer     */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }
    
    mapIdx++;
    retVal = Mmu_map(0x02800000, 0x02800000, 0x00001000, &attrs); /* uart        */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02000000, 0x02000000, 0x00100000, &attrs); /* I2C            */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02100000, 0x02100000, 0x00080000, &attrs); /* McSPI          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x40F00000, 0x40F00000, 0x00020000, &attrs); /* MCU MMR0 CFG   */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x40d00000, 0x40d00000, 0x00002000, &attrs); /* PLL0 CFG       */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x43000000, 0x43000000, 0x00020000, &attrs); /* WKUP MMR0 cfg  */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x02C40000, 0x02C40000, 0x00100000, &attrs); /* pinmux ctrl    */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x2A430000, 0x2A430000, 0x00001000, &attrs); /* ctrcontrol0 */
    if (retVal == FALSE)
    {
        while (1);
    }

    mapIdx++;
    retVal = Mmu_map(0x30800000, 0x30800000, 0x0C000000, &attrs); /*  navss          */
    if(retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    retVal = Mmu_map(0x30000000ul, 0x30000000ul, 0x0F000000ul, &attrs); /* ctrcontrol0 */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;
    /* for CPSW */
    retVal = Mmu_map(CSL_MCU_CPSW0_NUSS_BASE, CSL_MCU_CPSW0_NUSS_BASE, 
                                    (CSL_MCU_CPSW0_NUSS_SIZE*2), &attrs); 
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    /* ICSS-G 0 */
    mapIdx++;
    retVal = Mmu_map(0xb000000ul, 0xb000000ul, 0x0100000ul, &attrs);
    if (retVal == FALSE)
   {
        goto mmu_exit;
   }

     /* ICSS-G 1 */
     mapIdx++;
     retVal = Mmu_map(0xb100000ul, 0xb100000ul, 0x0100000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }

     /* ICSS-G 2 */
     mapIdx++;
     retVal = Mmu_map(0xb200000ul, 0xb200000ul, 0x0100000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }

     /* PSC WKUP*/
     mapIdx++;
     retVal = Mmu_map(0x42000000ul, 0x42000000ul, 0x00001000ul, &attrs);
     if (retVal == FALSE)
    {
         goto mmu_exit;
    }

     /* USBSS's */
     mapIdx++;
     retVal = Mmu_map(0x04000000ul, 0x04000000ul, 0x00200000ul, &attrs);
     if (retVal == FALSE)
     {
         goto mmu_exit;
     }

    /* MSMC */
    attrs.attrIndx = 7;
    mapIdx++;
    retVal = Mmu_map(0x70000000, 0x70000000, 0x04000000, &attrs); /* msmc        */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    mapIdx++;

    /* 56K msmc no cache. Check with linker file in ti/build/am65xx  */
    attrs.attrIndx = 4;
    retVal = Mmu_map(0x701E2000, 0x701E2000, 0xE000, &attrs); 
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

    /* DDR */
    attrs.attrIndx = 7;
    mapIdx++;
    retVal = Mmu_map(0x80000000, 0x80000000, 0x10000000, &attrs); /* DDR        */
    if (retVal == FALSE)
    {
        goto mmu_exit;
    }

mmu_exit:
    if(retVal == FALSE)
    {
        printf("Mmu_map idx %d returned error %d", mapIdx, retVal);
        while(1);
    }


   
}

#endif

#ifdef SOC_J721E

#include <ti/sysbios/family/arm/v8a/Mmu.h>

/* copy of ti/osal/j721e/bios_mmu.c, but add the non-cache MSMC section for USB */
void InitMmu(void)
{
    Mmu_MapAttrs    attrs;

    Mmu_initMapAttrs(&attrs);
    attrs.attrIndx = Mmu_AttrIndx_MAIR0;    /* device memory */

    /* Register region */
    Mmu_map(0x00000000U, 0x00000000U, 0x20000000U, &attrs);
    Mmu_map(0x20000000U, 0x20000000U, 0x20000000U, &attrs);
    Mmu_map(0x40000000U, 0x40000000U, 0x20000000U, &attrs);
    Mmu_map(0x60000000U, 0x60000000U, 0x10000000U, &attrs);
    Mmu_map(0x78000000U, 0x78000000U, 0x08000000U, &attrs); /* CLEC */

#if defined(BUILD_MPU)
    Mmu_map(0x400000000U, 0x400000000U, 0x400000000U, &attrs); /* FSS0 data   */
#endif

    attrs.attrIndx = Mmu_AttrIndx_MAIR7;
    Mmu_map(0x80000000U, 0x80000000U, 0x20000000U, &attrs); /* DDR */
    Mmu_map(0xA0000000U, 0xA0000000U, 0x20000000U, &attrs); /* DDR */
    Mmu_map(0x70000000U, 0x70000000U, 0x00800000U, &attrs); /* MSMC - 8MB */

    Mmu_map(0x41C00000U, 0x41C00000U, 0x00080000U, &attrs); /* OCMC - 512KB */

    /*
     * DDR range 0xA0000000 - 0xAA000000 : Used as RAM by multiple
     * remote cores, no need to mmp_map this range.
     * IPC VRing Buffer - uncached
     */
    attrs.attrIndx =  Mmu_AttrIndx_MAIR4;
    Mmu_map(0xAA000000, 0xAA000000, 0x02000000, &attrs);

    Mmu_map(0x707D0000U, 0x707D0000U, 0x20000U, &attrs); /* MSMC no cache- 128KB */

    return;
}
#endif


/* end of file */


