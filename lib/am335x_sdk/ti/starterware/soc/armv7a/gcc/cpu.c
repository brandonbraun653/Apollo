/**
 *  \file   cpu.c
 *
 *  \brief  CPU related definitions
 *
 *  This file contains the API definitions for configuring CPU
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

#include "types.h"
#include "cpu.h"
#include "interrupt.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 * \brief     This API can be used to switch from user mode to privileged mode
 *            The privilege mode will be system mode. System mode will share 
 *            the same resources as user mode, but with privileges.
 *
 * \param     None.
 *
 * \return    None.
 *
 * Note : All the access to system configuration which needs privileged access
 *        can be done after calling this API.
 **/
void CPUSwitchToPrivilegedMode(void)
{
    /* The constant passed here should match the constant used for checking in 
     * svc_handler (in exceptionhandler.S) 
     */
    asm("    SWI   1");
}

/**
 * \brief     This API can be used to switch from any privileged mode of ARM to 
 *            user mode. After this API is called, the program will continue
 *            to operate in non-privileged mode, until any exception occurs.
 *            After the exception is serviced, execution will continue in user
 *            mode.
 *
 * \param     None.
 *
 * \return    None.
 *
 * Note : All the access to system configuration which needs privileged access
 *        shall be done before this API is called.
 **/
void CPUSwitchToUserMode(void)
{
    asm("    mrs     r0, CPSR\n\t"
        "    bic     r0, #0x0F\n\t"
        "    orr     r0, #0x10\n\t "
        "    msr     CPSR, r0");
}

/**
 * \brief     This API is called when the CPU is aborted or during execution
 *            of any undefined instruction. Both IRQ and FIQ will be disabled
 *            when the CPU gets an abort and calls this API. 
 *
 * \param     None.
 *
 * \return    None.
 *
 * Note : The user can perform error handling such as an immediate reset 
 *        inside this API if required.
 **/
void CPUAbortHandler(void)
{
    while(1);
}
/**
 * \brief  This API returns the current status of interrupt configuration.
 *
 * \param    None
 *
 * \return   Status of the interrupts.
 *
 *  Note: This function call shall be done only in privileged mode of ARM
 **/
uint32_t CPUIntrStatus(void)
{
    uint32_t status;

    /* IRQ and FIQ in CPSR */
    asm("    mrs     r0, CPSR\n\t"
        "    and     %[result], r0, #0xC0" : 
                      [result] "=r" (status));
    
    return status;
}

/**
 * \brief  This API disables IRQ & FIQ and returns the current status.
 *
 * \param    None
 *
 * \return   Status of FIQ and IRQ before disabling the interrupts.
 *
 *  Note: This function call shall be done only in privileged mode of ARM
 **/
uint32_t CPUIntrDisable(void)
{
    volatile uint32_t status;

    /* Read the IRQ and FIQ status from CPSR */
    asm volatile ("    mrs     r0, CPSR\n\t"
                  "    mov     r1, r0\n\t"
                  "    and     %[result], r0, #0xC0" : 
                                [result] "=r" (status));
    asm volatile ("    orr     r1, #0xC0\n\t"
                  "    msr     CPSR, r1");

    status = (~status) & INTC_ARM_IRQ_FIQ_MASK;
    return status;
}

/**
 * \brief  Restore the interrupt configuration as indicated by the parameter.
 *         This does not affect the set of interrupts enabled/disabled in the
 *         external interrupt controller.
 *
 * \param    Intended configuration for IRQ and FIQ. In cases where the
 *           interrupts are disabled for critical code, the status parameter
 *           can be same as returned by the CpuIntDisable function.
 *
 * \return   None
 *
 *  Note: This function call shall be done only in privileged mode of ARM
 **/
void CPUIntrEnable(volatile uint32_t status)
{
     status = status & INTC_ARM_IRQ_FIQ_MASK;
     asm volatile ("    mrs     r0, CPSR\n\t"
                   "    bic     r0, r0, %[result]" : [result] "=r" (status));
     asm volatile ("    msr     CPSR, r0");
}
