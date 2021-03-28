/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
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
/** ============================================================================
 *  @file       osal_soc.h
 *
 *  @brief      SOC specific includes for Osal
 *
 *
 *  ============================================================================
 */
#ifndef ti_osal_soc_k2k_include
#define ti_osal_soc_k2k_include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#undef  TimerP_numTimerDevices
#undef  TIMERP_ANY_MASK
#undef  TIMERP_AVAILABLE_MASK
#undef   TIMERP_TIMER_FREQ_LO
#undef   TIMERP_TIMER_FREQ_HI
#define  TIMERP_TIMER_FREQ_LO   ((int32_t)  20480000  )
#define  TIMERP_TIMER_FREQ_HI   ((int32_t)  0)
#define  EXTERNAL_CLOCK_KHZ_DEFAULT (122880)

#define TIMERP_AVAILABLE_MASK   ((uint32_t)(0x0FFF00))
#ifdef _TMS320C6X
  #define TimerP_numTimerDevices         16
  #define TIMERP_ANY_MASK            0xCFFF
  #define SOC_PLL_TYPE               (CSL_PLL_SYS)
#else
  #define TimerP_numTimerDevices         20
  #define TIMERP_ANY_MASK           0xFFF00
  #define SOC_PLL_TYPE               (CSL_PLL_ARM)
#endif

/* Max number of semaphores for NonOs */
#define OSAL_NONOS_MAX_SEMAPHOREP_PER_SOC   ((uint32_t) 80U)
#define OSAL_NONOS_MAX_HWIP_PER_SOC         ((uint32_t) 40U)
#define OSAL_NONOS_MAX_TIMERP_PER_SOC       (TimerP_numTimerDevices)

#define OSAL_TIRTOS_MAX_SEMAPHOREP_PER_SOC   ((uint32_t) 80U)
#define OSAL_TIRTOS_MAX_HWIP_PER_SOC         ((uint32_t) 40U)
#define OSAL_TIRTOS_MAX_TIMERP_PER_SOC       (TimerP_numTimerDevices)

#ifdef __cplusplus
}
#endif

#endif
/* Nothing past this point */

