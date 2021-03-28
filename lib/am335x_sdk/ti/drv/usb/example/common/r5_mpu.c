/**
 * @file  r5_mpu.c
 *
 * @brief
 *  R5 MPU init for USB bare metal example
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2018, Texas Instruments, Inc.
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
#include <stdlib.h>
#include <stdint.h>
#include <csl_arm_r5.h>
#include <interrupt.h>

void USB_armR5EnableMPUandCache(void);

/*  Declarations    */
#pragma WEAK(__mpu_init)
void __mpu_init(void);

static void _enable_mpu()
{
    CSL_armR5CacheInvalidateAllCache();     /* Invalidate caches */
    USB_armR5EnableMPUandCache(); /* Custom cache and MPU config */
}

static void _enable_cache()
{
    CSL_armR5CacheEnableAllCache( 0 );      /* Disable I/D caches */
    CSL_armR5CacheEnableForceWrThru( 1 );   /* Enable force write-thru */
    CSL_armR5CacheInvalidateAllCache();     /* Invalidate I/D caches */
    CSL_armR5CacheEnableAllCache( 1 );      /* Enable I/D caches */
}


/*****************************************************************************/
/* \brief __MPU_INIT() - __mpu_init() is called in the C/C++ startup routine,*/
/* _c_int00(), and provides a mechanism for tailoring mpu init by device     */
/* prior to calling main().                                                  */
/*                                                                           */
/*****************************************************************************/
/*  Usage notes:
    On entry to this function from boot, R5F must be in System (privileged) mode. */
void __mpu_init(void)
{
    uint32_t loopCnt = 0U, regAddr;
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        regAddr = CSL_MCU_DOMAIN_VIM_BASE_ADDR;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        regAddr = CSL_MAIN_DOMAIN_VIM_BASE_ADDR;
    }

    _enable_mpu();              /* Enable MPU */
    _enable_cache();            /* Enable all caches */
    CSL_armR5FpuEnable( 1 );    /* Enable FPU */
    CSL_armR5IntrEnableVic(1);  /* Enable VIC */
    /* Disable/Clear pending Interrupts in VIM before enabling CPU Interrupts */
    /* This is done to prevent serving any bogus interrupt */
    for (loopCnt = 0U ; loopCnt < R5_VIM_INTR_NUM; loopCnt++)
    {
        /* Disable interrupt in vim */
        CSL_vimSetIntrEnable((CSL_vimRegs *)(uintptr_t)regAddr, loopCnt, false);
        /* Clear interrupt status */
        CSL_vimClrIntrPending((CSL_vimRegs *)(uintptr_t)regAddr, loopCnt);
    }
    CSL_armR5IntrEnableFiq(1);  /* Enable FIQ */
    CSL_armR5IntrEnableIrq(1);  /* Enable IRQ */
}



