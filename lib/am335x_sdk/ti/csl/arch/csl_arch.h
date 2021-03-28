/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002-2018
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

/** ============================================================================
 *   \file  csl_arch.h
 *
 *   \brief This file contains the ARCH related API's
 *  ============================================================================
 */
#ifndef CSL_ARCH_TOP_H_
#define CSL_ARCH_TOP_H_

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>

#if defined (SOC_K2G) || defined (SOC_AM574x) || defined (SOC_AM572x) || defined(SOC_AM571x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_AM571x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x) || defined (SOC_TDA3XX) || defined (SOC_DRA78x) || defined (SOC_OMAPL137) || defined (SOC_OMAPL138) || \
             defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657)||defined(SOC_J721E)||defined(SOC_TPR12)

#if defined (__ARM_ARCH_7A__)
#include <ti/csl/arch/a15/hw_mpu_intc_dist.h>
#include <ti/csl/arch/a15/hw_mpu_wugen.h>
#include <ti/csl/arch/a15/hw_intc.h>
#include <ti/csl/arch/a15/hw_mpu_intc_phys.h>
#include <ti/csl/arch/a15/interrupt.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/arch/a15/mpu_wugen.h>
#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined (SOC_AM574x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
#include <ti/csl/arch/a15/cache_a15.h>
#include <ti/csl/arch/a15/cache_a15_gcc_asm.h>
#include <ti/csl/arch/a15/cp15.h>
#include <ti/csl/arch/a15/cpu.h>
#include <ti/csl/arch/a15/ecc_a15.h>
#include <ti/csl/arch/a15/ecc_a15_gcc_asm.h>
#include <ti/csl/arch/a15/mmu_a15.h>
#include <ti/csl/arch/a15/mmu_a15_gcc_asm.h>
#include <ti/csl/arch/a15/cache_a15_rom_api_calls_asm.h>
#endif
/* Need DSP SYSCONFIG for PM */
#include <ti/csl/arch/c66x/hw_dsp_system.h>
#endif

#if defined (__TI_ARM_V7M4__)
#include <ti/csl/arch/m4/interrupt.h>
#include <ti/csl/arch/m4/ipu_wugen.h>
#include <ti/csl/arch/m4/ammu.h>
#include <ti/csl/arch/m4/unicache.h>
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#include <ti/csl/arch/m4/ipu_ecc.h>
#endif
/* Need DSP SYSCONFIG for PM */
#include <ti/csl/arch/c66x/hw_dsp_system.h>
#endif

#if defined (_TMS320C6X)
#include <ti/csl/arch/c66x/hw_dsp_icfg.h>
#if !defined (SOC_TPR12)
#include <ti/csl/arch/c66x/hw_dsp_system.h>
#include <ti/csl/arch/c66x/dsp_config.h>
#include <ti/csl/arch/c66x/dsp_wugen.h>
#endif
#include <ti/csl/arch/c66x/interrupt.h>
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX)
#include <ti/csl/arch/c66x/hw_xmc.h>
#include <ti/csl/arch/c66x/dsp_xmc.h>
#endif
#if defined (SOC_K2G) || defined(SOC_AM571x) || defined(SOC_AM572x) || defined (SOC_AM574x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX) || \
     defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657) || \
     defined (SOC_J721E) || defined(SOC_TPR12)
#include <ti/csl/arch/c66x/dsp_ecc.h>
#include <ti/csl/arch/c66x/dsp_icfg.h>
#include <ti/csl/arch/c66x/dsp_usrSpvSupport.h>
#endif
#endif

#if defined (BUILD_ARP32)
#include <ti/csl/arch/arp32/arp32_wugen.h>
#include <ti/csl/arch/arp32/intctl.h>
#include <ti/csl/arch/arp32/interrupt.h>
#include <ti/csl/arch/arp32/inth.h>
/* Need DSP SYSCONFIG for PM */
#include <ti/csl/arch/c66x/hw_dsp_system.h>
#endif

#if defined (__TI_ARM_V5__)
#include <ti/csl/arch/arm9/interrupt.h>
#endif

#endif

#if defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_AM77X) || defined (SOC_J7200) || defined(SOC_TPR12)

#if defined (__aarch64__)
#include <ti/csl/arch/a53/csl_a53.h>
#include <ti/csl/arch/a53/csl_a53v8cache.h>
#include <ti/csl/arch/a53/csl_a53v8func.h>
#include <ti/csl/arch/a53/csl_a53v8misc.h>
#include <ti/csl/arch/a53/interrupt.h>
#endif
#if defined (__TI_ARM_V7R4__)
#include <ti/csl/arch/r5/csl_vim.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/csl_arm_r5_mpu.h>
#include <ti/csl/arch/r5/csl_arm_r5_pmu.h>
#include <ti/csl/arch/r5/csl_arm_r5_hard_err_cache.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/csl/arch/r5/csl_cache.h>
#include <ti/csl/arch/r5/csl_mcu_armss_ccmr5.h>
#endif
#if defined (__C7100__)
#include <ti/csl/arch/c7x/csl_c7x.h>
#include <ti/csl/arch/c7x/csl_c7xecr.h>
#include <ti/csl/arch/c7x/csl_c7x_misc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

static inline void CSL_archMemoryFence(void);
static inline void CSL_archMemoryFence(void)
{
#if defined (__aarch64__)
    CSL_a53v8DsbSy();
#endif
#if defined (__TI_ARM_V7R4__)
    CSL_armR5Dsb();
#endif
}

#ifdef __cplusplus
}
#endif

#endif

#endif

/**
 *  \defgroup CSL_ARCH CSL ARCH Module
 */
