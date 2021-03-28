/**
 *  \file   OSAL_board.h
 *
 *  \brief  OSAL Board header file
 *
 */

/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef OSAL_BOARD_H
#define OSAL_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Example/Board Header files */
#include <ti/board/board.h>

#undef OSAL_TEST_CPU_FREQ_KHZ

/* AM65XX Core CPU frequency */
#if defined (SOC_AM65XX) || defined (SOC_J721E)
#if defined (BUILD_MCU1_0) || defined(BUILD_MCU1_1)
  #define OSAL_TEST_CPU_FREQ_KHZ   (400000)
#else
  #define OSAL_TEST_CPU_FREQ_KHZ   (800000)
#endif
#endif

/* AM572x Core CPU frequency */
#if defined (SOC_AM572x)
#if defined (BUILD_A15_0) || defined(BUILD_IPU1_0)
  #define OSAL_TEST_CPU_FREQ_KHZ   (960000)
#endif
#if defined (_TMS320C6X)
  #define OSAL_TEST_CPU_FREQ_KHZ   (576000)
#endif
#endif

/* KeyStone parts Core CPU frequency */
#if defined (SOC_K2G) || defined(SOC_K2E)
#if defined (BUILD_A15_0)
  #define OSAL_TEST_CPU_FREQ_KHZ   (800000)
#endif
#if defined (_TMS320C6X)
  #define OSAL_TEST_CPU_FREQ_KHZ   (900000)
#endif
#endif

/* TPR Core CPU frequency */
#if defined (SOC_TPR12)
#if defined (_TMS320C6X)
  #define OSAL_TEST_CPU_FREQ_KHZ   (450000)
#else
  #define OSAL_TEST_CPU_FREQ_KHZ   (400000)
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* OSAL_BOARD_H */
