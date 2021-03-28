/**
 *  \file   cpu.h
 *
 *  \brief  CPU related function prototypes
 *
 *  This file contains the API prototypes for configuring CPU
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/*
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

#ifndef CPU_H_
#define CPU_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Function Declarations                              */
/* ========================================================================== */

/**
 * \brief   This API enables the ARM core interrupt.
 *
 * \param   intrType Interrupt type to be enabled - IRQ or FIQ or 
 *                   both (IRQ and FIQ).
 **/
void CPUIntrEnable(uint32_t intrType);

/**
 * \brief   This API disables the ARM core interrupt.
 *
 * \retval  intrType Previous status of the interrupts.
 **/
uint32_t CPUIntrDisable(void);

/**
 * \brief   This API returns the ARM core interrupt status.
 *
 * \retval  intrType State of the ARM core interrupts.
 **/
uint32_t CPUIntrStatus(void);

/**
 * \brief   This API changes the mode of ARM core to user mode. After mode 
 *          change the stack pointer and shadow registers of user mode will be
 *          used.
 **/
void CPUSwitchToUserMode(void);

/**
 * \brief   This API changes the mode of ARM core to privilege mode. After mode
 *          change the stack pointer and shadow registers of privilege mode 
 *          will be used.
 **/
void CPUSwitchToPrivilegedMode(void);

/**
 * \brief   CPU Abort handler. This API will handle the abort exception from CPU.
 *          The handler will wait in while(1) loop.
 **/
void CPUAbortHandler(void);

#ifdef __cplusplus
}
#endif
#endif /* __CPU_H__ */
