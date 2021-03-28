/**
 * \file  interrupt.c
 *
 * \brief Contains DSP interrupt related APIs.
 */

/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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

#include <c6x.h>

#include <ti/csl/hw_types.h>

/* DSP System Defines */
#include <hw_c67x_intc.h>

/* DSP INTC APIs */
#include <interrupt.h>

#include <ti/csl/soc/omapl137/src/cslr_soc_baseaddress.h>


/******************************************************************************
**                      INTERNAL DEFINES
******************************************************************************/
#define C674X_NMI 1
#define C674X_GEE 2
#define C674X_XEN 3
#define C674X_INT_COUNT 16
#define NUM_SYS_EVENTS 128


/******************************************************************************
**                      EXTERNALLY DEFINED FUNCTIONS
******************************************************************************/
extern void intcVectorTable (void);


/******************************************************************************
**                      STATIC VARIABLES/FUNCTIONS
******************************************************************************/
static c674xISR c674xISRtbl[C674X_INT_COUNT];
static c674xISR c674xECMtbl[NUM_SYS_EVENTS];

static void IntDefaultHandler (void);
static void IntEventCombineIsr0 (void);
static void IntEventCombineIsr1 (void);
static void IntEventCombineIsr2 (void);
static void IntEventCombineIsr3 (void);
static void IntEventCombinerDispatch (unsigned int evtReg);


/******************************************************************************
**                      API INTERRUPT FUNCTIONS
******************************************************************************/
/**
 * \function IntDSPINTCInit
 *
 * \brief    This API is used to setup the DSP Interrupt Controller (INTC)
 *           and should be called before using the DSP INTC. All CPU
 *           maskable interrupts will be disabled after calling this API and
 *           the user should proceed to setup the required interrupts for
 *           processing.
 *
 * \param    None
 *
 * \return   None
 */
 void Intc_Init (void)
{
    unsigned int step = 0;

    /* Set ISRs to default "do-nothing" routine */
    while(step != C674X_INT_COUNT)
        c674xISRtbl[step++] = IntDefaultHandler;

    /* Set interrupt service table pointer to the vector table */
    ISTP = (unsigned int)intcVectorTable;

    /* Clear pending CPU maskable interrupts (if any) */
    ICR = 0xFFF0;

    /* Enable NMIE bit to allow CPU maskable interrupts */
    IER = (1 << C674X_NMI);
}

/**
 * \function IntRegister
 *
 * \brief    Registers an interrupt service routine in the interrupt
 *           vector table for CPU maskable interrupts, NMI, or
 *           reserved interrupts.
 *
 * \param    cpuINT - CPU maskable interrupt number (4-15), NMI (1),
 *           or reserved interrupt (2-3)
 * \param    userISR - Function pointer to the ISR
 *
 * \return   None
 */
void Intc_IntRegister (unsigned int cpuINT, void (*userISR)(void))
{
    /* Assign the user's ISR to the CPU maskable interrupt */
    c674xISRtbl[cpuINT] = userISR;
}

/**
 * \function IntUnRegister
 *
 * \brief    Unregisters an interrupt.
 *
 * \param    cpuINT - CPU maskable interrupt number (4-15), NMI (1),
 *           or reserved interrupt (2-3)
 *
 * \return   None
 */
void Intc_IntUnregister (unsigned int cpuINT)
{
    /* Assign the default "do-nothing" routine to the CPU maskable interrupt */
    c674xISRtbl[cpuINT] = IntDefaultHandler;
}

/**
 * \function IntEventMap
 *
 * \brief    This API maps a system event to a CPU maskable interrupt.
 *
 * \param    cpuINT - CPU maskable interrupt number
 * \param    sysINT - System event number
 *
 * \return   None
 */
void IntEventMap (unsigned int cpuINT, unsigned int sysINT)
{
    unsigned int dspintcREG, restoreVal;

    /* Get the address of the correct interrupt mux register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_INTMUX((cpuINT >> 2));

    /* Disable interrupts */
    restoreVal = Intc_SystemDisable();

    /* Clear and set INTSELx with system event number */
    HWREG(dspintcREG) = (HWREG(dspintcREG) &
            ~DSPINTC_INTMUX_INTSEL(cpuINT)) |
            (sysINT << DSPINTC_INTMUX_INTSEL_SHIFT(cpuINT));

    /* Clear any residual interrupt */
    ICR = (1 << cpuINT);

    /* Restore interrupts */
    IntGlobalRestore(restoreVal);
}

/**
 * \function IntEventSet
 *
 * \brief    This API manually sets a system event in the event flag
 *           register.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void IntEventSet (unsigned int sysINT)
{
    unsigned int dspintcREG;

    /* Get the address of the correct event register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EVTSET((sysINT >> 5));

    /* Set the corresponding bit within the event flag register */
    HWREG(dspintcREG) = DSPINTC_EVTSET_ES(sysINT);
}

/**
 * \function IntEventClear
 *
 * \brief    This API clears the system interrupt status in the DSP
 *           interrupt controller.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void IntEventClear(unsigned int sysINT)
{
    unsigned int dspintcREG;

    /* Get the address of the correct event register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EVTCLR((sysINT >> 5));

    /* Clear the corresponding bit within the event clear register */
    HWREG(dspintcREG) = DSPINTC_EVTCLR_EC(sysINT);
}

/**
 * \function IntEventCombineInit
 *
 * \brief    This API removes all system events from the ECM, assigns
 *           the event ISRs to a default handler, registers the ECM
 *           ISR to the corresponding CPU interrupt, maps the ECM
 *           system event to the corresponding CPU interrupt, and enables
 *           the CPU interrupt.
 *
 * \param    ecmINT0 - CPU interrupt number to be used for ECM0 system event
 * \param    ecmINT1 - CPU interrupt number to be used for ECM1 system event
 * \param    ecmINT2 - CPU interrupt number to be used for ECM2 system event
 * \param    ecmINT3 - CPU interrupt number to be used for ECM3 system event
 *
 * \return   None
 */
void IntEventCombineInit(int ecmINT0, int ecmINT1, int ecmINT2, int ecmINT3)
{
    unsigned int step = 0;

    while(step < NUM_SYS_EVENTS)
    {
        /* Remove system event from ECM */
        IntEventCombineRemove(step);

        /* Set ISR to default "do-nothing" routine */
        c674xECMtbl[step++] = IntDefaultHandler;
    }

    if(ecmINT0 >= 4)
    {
        /* Register the ECM ISR to the CPU interrupt */
        Intc_IntRegister(ecmINT0, IntEventCombineIsr0);

        /* Map the ECM system event to the CPU interrupt */
        IntEventMap(ecmINT0, SYS_INT_EVT0);

        /* Enable the CPU interrupt */
        Intc_IntEnable(ecmINT0);
    }

    if(ecmINT1 >= 4)
    {
        /* Register the ECM ISR to the CPU interrupt */
        Intc_IntRegister(ecmINT1, IntEventCombineIsr1);

        /* Map the ECM system event to the CPU interrupt */
        IntEventMap(ecmINT1, SYS_INT_EVT1);

        /* Enable the CPU interrupt */
        Intc_IntEnable(ecmINT1);
    }

    if(ecmINT2 >= 4)
    {
        /* Register the ECM ISR to the CPU interrupt */
        Intc_IntRegister(ecmINT2, IntEventCombineIsr2);

        /* Map the ECM system event to the CPU interrupt */
        IntEventMap(ecmINT2, SYS_INT_EVT2);

        /* Enable the CPU interrupt */
        Intc_IntEnable(ecmINT2);
    }

    if(ecmINT3 >= 4)
    {
        /* Register the ECM ISR to the CPU interrupt */
        Intc_IntRegister(ecmINT3, IntEventCombineIsr3);

        /* Map the ECM system event to the CPU interrupt */
        IntEventMap(ecmINT3, SYS_INT_EVT3);

        /* Enable the CPU interrupt */
        Intc_IntEnable(ecmINT3);
    }
}

/**
 * \function IntEventCombineAdd
 *
 * \brief    This API adds the system event to the event combiner.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void IntEventCombineAdd(unsigned int sysINT)
{
    unsigned int dspintcREG, restoreValue;

    /* Get the address of the correct event combiner register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EVTMASK((sysINT >> 5));

    /* Disable interrupts */
    restoreValue = Intc_SystemDisable();

    /* Unmask system event number to be included in the combined event */
    HWREG(dspintcREG) &= ~DSPINTC_EVTMASK_EM(sysINT);

    /* Enable interrupts */
    IntGlobalRestore(restoreValue);
}

/**
 * \function IntEventCombineRemove
 *
 * \brief    This API removes the system event from the event combiner.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void IntEventCombineRemove(unsigned int sysINT)
{
    unsigned int dspintcREG, restoreValue;

    /* Get the address of the correct event combiner register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EVTMASK((sysINT >> 5));

    /* Disable interrupts */
    restoreValue = Intc_SystemDisable();

    /* Mask system event number to be removed from the combined event */
    HWREG(dspintcREG) |= DSPINTC_EVTMASK_EM(sysINT);

    /* Enable interrupts */
    IntGlobalRestore(restoreValue);
}

/**
 * \function IntEventCombineRegister
 *
 * \brief    Registers an interrupt service routine in the interrupt
 *           vector table for ECM system interrupts.
 *
 * \param    sysINT - System event number
 * \param    userISR - Function pointer to the ISR
 *
 * \return   None
 */
void IntEventCombineRegister(unsigned int sysINT, void (*userISR)(void))
{
    /* Assign the user's ISR to the system event */
    c674xECMtbl[sysINT] = userISR;
}

/**
 * \function IntEnable
 *
 * \brief    This API enables a CPU maskable interrupt.
 *
 * \param    cpuINT - CPU maskable interrupt number
 *
 * \return   None
 */
void Intc_IntEnable (unsigned int cpuINT)
{
    unsigned int restoreVal;

    /* Disable interrupts */
    restoreVal = Intc_SystemDisable();

    /* Enable CPU maskable interrupt */
    IER |= (1 << cpuINT);

    /* Restore interrupts */
    IntGlobalRestore(restoreVal);
}

/**
 * \function IntDisable
 *
 * \brief    This API disables a CPU maskable interrupt.
 *
 * \param    cpuINT - CPU maskable interrupt number
 *
 * \return   None
 */
void Intc_IntDisable (unsigned int cpuINT)
{
    unsigned int restoreVal;

    /* Disable interrupts */
    restoreVal = Intc_SystemDisable();

    /* Disable CPU maskable interrupt */
    IER &= ~(1 << cpuINT);

    /* Restore interrupts */
    IntGlobalRestore(restoreVal);
}

/**
 * \function IntReset
 *
 * \brief    This API disables all CPU maskable interrupts
 *
 * \param    None
 *
 * \return   None
 */
void IntReset (void)
{
    unsigned int restoreVal;

    /* Disable interrupts */
    restoreVal = Intc_SystemDisable();

    /* Disable CPU maskable interrupts */
    IER = 0x1;

    /* Restore interrupts */
    IntGlobalRestore(restoreVal);
}

/**
 * \function IntGlobalEnable
 *
 * \brief    Enable DSP CPU interrupts globally.
 *
 * \param    None
 *
 * \return   None
 */
void Intc_SystemEnable (void)
{
    _enable_interrupts();
}

/**
 * \function IntGlobalDisable
 *
 * \brief    Disable DSP CPU interrupts globally
 *
 * \param    None
 *
 * \return   DSP CPU interrupt state
 */
unsigned int Intc_SystemDisable (void)
{
    return (unsigned int)(_disable_interrupts());
}

/**
 * \function IntGlobalRestore
 *
 * \brief    Restore the DSP CPU interrupt state
 *
 * \param    Previous DSP CPU interrupt state
 *
 * \return   None
 */
void IntGlobalRestore (unsigned int restoreValue)
{
    _restore_interrupts(restoreValue);
}

/**
 * \function ExcGlobalEnable
 *
 * \brief    Enable DSP CPU exceptions globally.  Cannot be undone.
 *
 * \param    None
 *
 * \return   None
 */
void ExcGlobalEnable (void)
{
    /* clear all exceptions */
    ECR = ~0u;

    /* enable all exceptions */
    TSR |= ((1 << C674X_GEE) | (1 << C674X_XEN));
}

/**
 * \function ExcCombineAdd
 *
 * \brief    This API adds the system event to the exception combiner.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void ExcCombineAdd(unsigned int sysINT)
{
    unsigned int dspintcREG;

    /* Get the address of the correct event combiner register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EXPMASK((sysINT >> 5));

    /* Unmask system event number to be included in the combined event */
    HWREG(dspintcREG) &= ~DSPINTC_EVTMASK_EM(sysINT);
}

/**
 * \function ExcCombineRemove
 *
 * \brief    This API removes the system event from the exception combiner.
 *
 * \param    sysINT - System event number
 *
 * \return   None
 */
void ExcCombineRemove(unsigned int sysINT)
{
    unsigned int dspintcREG;

    /* Get the address of the correct event combiner register */
    dspintcREG = CSL_INTC_0_REGS + DSPINTC_EXPMASK((sysINT >> 5));

    /* Mask system event number to be removed from the combined event */
    HWREG(dspintcREG) |= DSPINTC_EVTMASK_EM(sysINT);
}

/******************************************************************************
**                 INTERRUPT SERVICE ROUTINES - Used Internally
******************************************************************************/
static void IntDefaultHandler (void)
{
    while(1);
}

static void IntEventCombineIsr0 (void)
{
    IntEventCombinerDispatch(SYS_INT_EVT0);
}

static void IntEventCombineIsr1 (void)
{
    IntEventCombinerDispatch(SYS_INT_EVT1);
}

static void IntEventCombineIsr2 (void)
{
    IntEventCombinerDispatch(SYS_INT_EVT2);
}

static void IntEventCombineIsr3 (void)
{
    IntEventCombinerDispatch(SYS_INT_EVT3);
}

static void IntEventCombinerDispatch (unsigned int evtReg)
{
    unsigned int dspintcMEFREG, dspintcECREG, evtRcv, evtIndex, offset;

    /* Get the address of the correct DSPINTC registers */
    dspintcMEFREG = CSL_INTC_0_REGS + DSPINTC_MEVTFLAG(evtReg);
    dspintcECREG = CSL_INTC_0_REGS + DSPINTC_EVTCLR(evtReg);

    offset = evtReg * 32;
    evtRcv = HWREG(dspintcMEFREG);

    while(evtRcv)
    {
        /* Clear system events */
        HWREG(dspintcECREG) = evtRcv;

        /* Service system events */
        do{
            evtIndex = 31 - _lmbd(1, evtRcv);
            evtRcv &= ~(1 << evtIndex);
            c674xECMtbl[evtIndex + offset]();
        }while(evtRcv);

        /* Check for new system events */
        evtRcv = HWREG(dspintcMEFREG);
    }
}

interrupt void c674x_nmi_isr (void)
{
    c674xISRtbl[1]();
}

interrupt void c674x_rsvd_int2_isr (void)
{
    c674xISRtbl[2]();
}

interrupt void c674x_rsvd_int3_isr (void)
{
    c674xISRtbl[3]();
}

interrupt void c674x_mask_int4_isr (void)
{
    c674xISRtbl[4]();
}

interrupt void c674x_mask_int5_isr (void)
{
    c674xISRtbl[5]();
}

interrupt void c674x_mask_int6_isr (void)
{
    c674xISRtbl[6]();
}

interrupt void c674x_mask_int7_isr (void)
{
    c674xISRtbl[7]();
}

interrupt void c674x_mask_int8_isr (void)
{
    c674xISRtbl[8]();
}

interrupt void c674x_mask_int9_isr (void)
{
    c674xISRtbl[9]();
}

interrupt void c674x_mask_int10_isr (void)
{
    c674xISRtbl[10]();
}

interrupt void c674x_mask_int11_isr (void)
{
    c674xISRtbl[11]();
}

interrupt void c674x_mask_int12_isr (void)
{
    c674xISRtbl[12]();
}

interrupt void c674x_mask_int13_isr (void)
{
    c674xISRtbl[13]();
}

interrupt void c674x_mask_int14_isr (void)
{
    c674xISRtbl[14]();
}

interrupt void c674x_mask_int15_isr (void)
{
    c674xISRtbl[15]();
}
