/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== tirtos_config.h ========
 *  This file allows a user to modify the behavior of the TI-RTOS
 *  implementation for the driver RTOS port.
 */

#ifndef ti_osal_tirtos_config__include
#define ti_osal_tirtos_config__include

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/osal/osal.h>
#include <ti/osal/soc/osal_soc.h>
#if  defined(__ARM_ARCH_7A__)

#if defined(gnu_targets_arm_A15F) || defined(gnu_targets_arm_A9F)
#include <ti/sysbios/family/arm/gic/Hwi.h>
#elif defined(ti_targets_arm_elf_A8F) || \
      defined(ti_targets_arm_elf_A8Fnv) || \
      defined(gnu_targets_arm_A8F)
#include  <ti/sysbios/family/arm/a8/intcps/Hwi.h>
#endif

#elif defined(__aarch64__)
#include <ti/sysbios/family/arm/gicv3/Hwi.h>

#elif ((defined (SOC_OMAPL137) || defined (SOC_OMAPL138)) && (!defined(_TMS320C6X)))
    #include <ti/sysbios/family/arm/da830/Hwi.h>
#else
#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#elif defined(__TI_ARM_V7R4__)
#include <ti/sysbios/family/arm/v7r/keystone3/Hwi.h>
#else
#include <ti/sysbios/hal/Hwi.h>
#endif
#endif /* __ARM_ARCH_7A__ */

#ifndef OSAL_TARGET_PROC_MASK_DEFAULT
#define OSAL_TARGET_PROC_MASK_DEFAULT (0xFFFFU)
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0x0)
#endif

extern Osal_HwAttrs  gOsal_HwAttrs;

void OsalArch_compileTime_SizeChk(void);
void SemaphoreP_compileTime_SizeChk(void);
void HwiP_compileTime_SizeChk(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_tirtos_config__include */
