/**
 *  \file   aintc.c
 *
 *  \brief  Interrupt APIs implementation for ARM interrupt controller.
 *
 */

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_intc.h"
#include "interrupt.h"
#include "hw_types.h"
#include "soc_am335x.h"
#include "cpu.h"
#include "console_utils.h"
#include "error.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define REG_IDX_SHIFT                     (0x05U)
#define REG_BIT_MASK                      (0x1FU)
#define AINTC_MAX_INTR_NO                 (128U)
/* ========================================================================== */
/*                      Global variable Declarations                        */
/* ========================================================================== */

/** \brief Array of function pointers to hold call back functions for Interrupt
 *         handlers. This list will be used for calling the call back functions
 *         of interrupts.
 */
static void (*pIntrHandlers[AINTC_MAX_INTR_NO])(uint32_t intrId,
                                         uint32_t cpuId, void* pUserParam);
                                         
/** \brief Array to hold the user parameters passed during interrupt
 *         registration. The same will be passed to the corresponding interrupt
 *         handlers.
 */
static void* pUserParameter[AINTC_MAX_INTR_NO];
                                         
/** \brief Counter to hold the number of spurious interrupt occurred. */
static uint32_t spuriousIntrCnt = 0;

/** \brief Flag to indicate if the interrupt controller is already 
           initialized. */
static uint32_t isIntcInitialized = FALSE;
/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static void IntDefaultHandler(uint32_t intrId, uint32_t cpuId,
                                                         void* pUserParam);
/* ========================================================================== */
/*                         Function Declarations                              */
/* ========================================================================== */

void INTCCommonIntrHandler(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * \brief   This API is used to initialize the interrupt controller. This API
 *          shall be called before using the interrupt controller.
 **/
int32_t INTCInit(uint32_t isCpuSecure)
{
    uint32_t intrNum;

    if(FALSE == isIntcInitialized)
    {
        /* Reset the ARM interrupt controller */
        HWREG(SOC_AINTC_REGS + INTC_SYSCONFIG) = INTC_SYSCONFIG_SOFTRESET;
        
        /* Wait for the reset to complete */
        while((HWREG(SOC_AINTC_REGS + INTC_SYSSTATUS)
              & INTC_SYSSTATUS_RESETDONE) != INTC_SYSSTATUS_RESETDONE);
        
        /* Enable any interrupt generation by setting priority threshold */
        HWREG(SOC_AINTC_REGS + INTC_THRESHOLD) =
                                           INTC_THRESHOLD_PRIORITYTHRESHOLD;
        
        /* Register the default handler for all interrupts */
        for(intrNum = 0; intrNum < AINTC_MAX_INTR_NO; intrNum++)
        {
            pIntrHandlers[intrNum] = IntDefaultHandler;
        }
        
        /* Enables protection mode for the interrupt controller register access.
         * When the protection is enabled, the registers will be accessible only
         * in privileged mode of the CPU.
         */
        HWREG(SOC_AINTC_REGS + INTC_PROTECTION) = INTC_PROTECTION_PROTECTION;
        isIntcInitialized = TRUE;
    }

    return S_PASS;
}

int32_t INTCConfigIntr(uint32_t intrNum, intcIntrParams_t *pIntrParams,
                                                        uint32_t isCpuSecure)
{
    int32_t status = S_PASS;
    
    if((TRUE != isCpuSecure) && (TRUE == pIntrParams->isIntrSecure))
    {
        status = E_FAIL;
    }
    else
    {
        /* Register interrupt handler */
        pIntrHandlers[intrNum] = pIntrParams->pFnIntrHandler;
        pUserParameter[intrNum] = pIntrParams->pUserParam;

        /* Set the priority and interrupt route (IRQ/FIQ) */
        HWREG(SOC_AINTC_REGS + INTC_ILR(intrNum)) =
                        ((pIntrParams->priority << INTC_ILR_PRIORITY_SHIFT) & 
                          INTC_ILR_PRIORITY) | pIntrParams->isIntrSecure ;
        
        /* Enable the system interrupt in AINTC. For the interrupt generation, 
         * make sure that the interrupt is enabled at the peripheral level 
         * also. Here the CLEAR register clears the mask (enabling the 
         * interrupt).*/
         HWREG(SOC_AINTC_REGS + INTC_MIR_CLEAR(intrNum >> REG_IDX_SHIFT))
                                   = (0x01 << (intrNum & REG_BIT_MASK));        
        
        /* Enable interrupt in CPU. Enable IRQ and FIQ in Secure mode, and only
           IRQ in Non-Secure mode. */
        if (TRUE == isCpuSecure)
            CPUIntrEnable(INTC_ARM_IRQ_FIQ_MASK);
        else
            CPUIntrEnable(INTC_ARM_IRQ_MASK);
    }
    return status;
}

int32_t INTCEnableIntr(uint32_t intrNum)
{
    int32_t status = S_PASS;
    
    if(intrNum < AINTC_MAX_INTR_NO)
    {
        __asm(" dsb");
        
        /* Enable the system interrupt in AINTC. For the interrupt generation, 
         * make sure that the interrupt is enabled at the peripheral level 
         * also. Here the CLEAR register clears the mask (enabling the 
         * interrupt).*/
         HWREG(SOC_AINTC_REGS + INTC_MIR_CLEAR(intrNum >> REG_IDX_SHIFT))
                                   = (0x01 << (intrNum & REG_BIT_MASK));        
    }
    else
    {
        status = E_INTR_NOT_SUPP;
    }
    return status;
}

int32_t INTCDisableIntr(uint32_t intrNum)
{
    int32_t status = S_PASS;
    
    if(intrNum < AINTC_MAX_INTR_NO)
    {
        __asm(" dsb");
        
        /* Disable the system interrupt in AINTC. Here the SET register sets 
         * the mask (disabling the interrupt).*/
         HWREG(SOC_AINTC_REGS + INTC_MIR_SET(intrNum >> REG_IDX_SHIFT))
                                   = (0x01 << (intrNum & REG_BIT_MASK));        
    }
    else
    {
        status = E_INTR_NOT_SUPP;
    }
    return status;
}

int32_t INTCEnableCpuIntr(uint32_t intrType)
{
    int32_t status = S_PASS;
    if ((INTC_ARM_IRQ_MASK == intrType) || (INTC_ARM_FIQ_MASK == intrType) ||
                                         (INTC_ARM_IRQ_FIQ_MASK == intrType))
    {
        CPUIntrEnable(intrType);
    }
    else
    {
        status = E_INVALID_PARAM;
    }
    return status;
}

uint32_t INTCDisableCpuIntr(void)
{
    return CPUIntrDisable();
}

int32_t INTCClearIntr(uint32_t intrNum)
{
    int32_t status = S_PASS;
    if(intrNum < AINTC_MAX_INTR_NO)
    {
        /* Clear the interrupt status. */
         HWREG(SOC_AINTC_REGS + INTC_ITR(intrNum >> REG_IDX_SHIFT))
                                   = (0x01 << (intrNum & REG_BIT_MASK));        
    }
    else
    {
        status = E_INTR_NOT_SUPP;
    }
    return status;
}

int32_t INTCTriggerSWIntr(uint32_t intrNum)
{
    int32_t status = S_PASS;
    if(intrNum < AINTC_MAX_INTR_NO)
    {
        /* Clear the interrupt status. */
        HWREG(SOC_AINTC_REGS + INTC_ISR_SET(intrNum >> REG_IDX_SHIFT))
                                   = (0x01 << (intrNum & REG_BIT_MASK));
    }
    else
    {
        status = E_INTR_NOT_SUPP;
    }
    return status;
}

int32_t INTCSaveContext(void)
{
    /* TODO */
    return 0;
}

int32_t INTCRestoreContext(void)
{
    /* TODO */
    return 0;
}

/**
 * \brief   This API is the common interrupt handler. On any interrupt this
 *          handler is called which will resolve and call the corresponding
 *          handler. At the end of interrupt handling, the EOI register is
 *          updated, so that each interrupt handler need not write to EOI.
 *
 *  Note:   The below method of calling common handler from IRQ/FIQ vector and
 *          then calling the specific interrupt handler involves function
 *          calling overhead. Since the processor will be running at higher
 *          frequencies the overhead is assumed to be negligible. Instead the
 *          specific interrupt handler can be called from IRQ/FIQ vector if the
 *          application requires lesser interrupt latency. But this will make
 *          the IRQ/FIQ vector tied to specific intr Controller, effectively
 *          reducing the portability of IRQ/FIQ vector code.
 *
 * \param   None
 *
 * \return  None
 **/
void INTCCommonIntrHandler(void)
{
    uint32_t intrAckVal = HW_RD_REG32(SOC_AINTC_REGS + INTC_SIR_IRQ);
    uint32_t activeIntrId = intrAckVal & INTC_SIR_IRQ_ACTIVEIRQ;
    uint32_t cpuId = 0; /* Singe core */

    /* Save the current threshold value in stack */
    uint32_t prevPriMask = HW_RD_REG32(SOC_AINTC_REGS + INTC_THRESHOLD);

    /*  Get the active IRQ priority and set this priority as the threshold value,
        so that only interrupts with higher priority can interrupt the CPU when
        the current interrupt us being serviced.
    */
    HW_WR_REG32((SOC_AINTC_REGS + INTC_THRESHOLD),
                            HW_RD_REG32(SOC_AINTC_REGS + INTC_IRQ_PRIORITY));

    /* Acknowledge the interrupt, so that nested interrupts can be generated. */
    HW_WR_REG32((SOC_AINTC_REGS + INTC_CONTROL), INTC_CONTROL_NEWIRQAGR);
                            
    /*
     * Enable IRQ and switch to system mode. Interrupt Service Routines will
     * execute in System Mode, so that nested interrupts can be handled.
     * Save user mode LR.
     */
    asm("    push    {r7}\n\t"
        "    mrs     r7, CPSR\n\t"
        "    orr     r7, r7, #0x1F\n\t"
        "    bic     r7, r7, #0x80\n\t"
        "    msr     CPSR, r7\n\t"
        "    STMFD   r13!, {r14}");

    /* Call the respective interrupt handler call back function */
    pIntrHandlers[activeIntrId](activeIntrId, cpuId,
                                                pUserParameter[activeIntrId]);

    /*
     * Disable IRQ and change back to IRQ mode.
     * Restore user mode LR.
     */
    asm("    LDMFD    r13!, {r14}\n\t"
        "    CPSID    i, 0x12\n\t"
        "    pop      {r7}");

    /* Reload original priority threshold value */
    HW_WR_REG32((SOC_AINTC_REGS + INTC_THRESHOLD), prevPriMask);
}

/* -------------------------------------------------------------------------- */
/*                       Internal Function Definitions                        */
/* -------------------------------------------------------------------------- */

 /**
 * \brief   The Default Interrupt Handler.
 *          This is the default interrupt handler for all interrupts. The control
 *          would reach here if the interrupt is not configured. So to bring to
 *          users attention a message will be printed and wait infinitely.
 *
 * \param   intrId    Interrupt number which is active currently
 * \param   cpuId     CPU ID of the processor which generated the SGI (Software
 *                    Generated Interrupt). This is valid only in multi-proc
 *                    environment (SMP).
 *
 * \return  None
 *
 **/
static void IntDefaultHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    /* Keeping the print under a macro to avoid console utils dependency.
    ** To enable the print define the macro.
    */
    #ifndef DEBUG_PRINT
    /* TODO: Can be updated to print interrupt number also. */
    CONSOLEUtilsPuts("\r\nDefault Interrupt Handler: Unregistered interrupt occurred");
    #endif

    /* Increment spurious interrupt counter */
    spuriousIntrCnt++;
}
