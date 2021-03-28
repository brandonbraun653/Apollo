/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
#ifndef ti_osal_soc_dra72x_include
#define ti_osal_soc_dra72x_include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#undef  TimerP_numTimerDevices
#undef  TIMERP_ANY_MASK
#define TimerP_numTimerDevices        ((uint32_t) 16 )
#define TIMERP_ANY_MASK               ((uint32_t) 0xFFFF)
#define  EXTERNAL_CLOCK_KHZ_DEFAULT       (24000)

#undef   TIMERP_TIMER_FREQ_LO
#undef   TIMERP_TIMER_FREQ_HI
#define  TIMERP_TIMER_FREQ_LO   ((int32_t) 19200000)
#define  TIMERP_TIMER_FREQ_HI   ((int32_t) 0)

#if defined (_TMS320C6X)
  #define TIMERP_AVAILABLE_MASK       ((uint32_t)(0x0030))
#elif defined (__TI_ARM_V7M4__)
  #define TIMERP_AVAILABLE_MASK       ((uint32_t)(0x050C))
#else
  #define TIMERP_AVAILABLE_MASK       ((uint32_t)(0x0202))
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
/* nothing past this point */
