/**
 *  \file   timer_test.h
 *
 *  \brief  Example application header file.
 *
 *
 */

/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _TIMER_TEST_H_
#define _TIMER_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/csl_armGic.h>

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <chipdb_defs.h>
#include <interrupt.h>
#include <hw_cm_wkup.h>
#include <hw_cm_dpll.h>
#include <soc_control.h>
#endif

#if defined (SOC_AM335x)
#include <soc_am335x.h>
#endif

#if defined (SOC_AM437x)
#include <am437x.h>
#endif

#include "board.h"
#include "board_cfg.h"

#if defined (SOC_AM572x) || defined (SOC_AM571x)
#define TIMER_BASE_ADDR                     (CSL_MPU_TIMER1_REGS)
#define TIMER_INTR_NUM                      (37)
#else
#if defined (SOC_AM437x)
#define TIMER_BASE_ADDR                     (SOC_DMTIMER1_1MS_REG)
#define TIMER_INTR_NUM                      (99)
#else
#define TIMER_BASE_ADDR                     (SOC_DMTIMER_1_REGS)
#define TIMER_INTR_NUM                      (67)
#endif
#endif

#define INTR_MASK_COUNT                     (0)

#define TIMER_INITIAL_COUNT                 (0xFFFFFFE0)
#define TIMER_RLD_COUNT                     (0xFFFFFFE0)
#define TPIR_VALUE                          (0x38a40)
#define TNIR_VALUE                          (0xfff44800)

/* Test wait time for interrupt completion in msecs */
#define TIMER_1MS_TICK_DURATION             (2000)

/** \brief Successful completion of the functionality.  */
#define S_PASS                  (0)
/** \brief Generic failure code.                        */
#define E_FAIL                  (-1)

extern void CSL_A15_INIT_copyVectorTable(void);
extern void CopyVectorTable(void);

/**
 * \brief   Set up the Timer Module for Countdown timer operation.
 *
 *
 */
void BoardDiag_TimerSetup(void);

/**
 * \brief    Function to demonstrate the working of Timer module.
 *
 * \retval   S_PASS    on success.
 * \retval   E_FAIL    on failure.
 */
int BoardDiag_TimerTest(void);

/**
 * \brief    Function Starts the Timer and tracks the count.
 *
 */
void BoardDiag_TimerRun(void);

/**
 * \brief    Function to initialize ARM interrupt module
  *
 */
void BoardDiag_TimerIntrInit(void);

/**
 * \brief    Function configures the Interrupt Controller for Timer module
 *           operation.
 *
 */
void BoardDiag_TimerIntrConfig(void);

/**
 * \brief    This is the OVERFLOW ISR for the Count down timer.
 *
 * \param    pUserParam - Param passed by user to the interrupt handler
 */
#if defined (SOC_AM572x) || defined (SOC_AM571x)
void BoardDiag_TimerIsr(void* pUserParam);
#else
void BoardDiag_TimerIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#endif

#endif /* _TIMER_TEST_H_ */