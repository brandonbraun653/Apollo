/*
 *  Copyright (C) 2017 Texas Instruments Incorporated
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

/**
 *  \file   interrupt.c
 *
 *  \brief  Interrupt related APIs.
 *
 *   This file contains the APIs for configuring AINTC
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stddef.h>
#include <ti/csl/arch/csl_arch.h>
#include <interrupt.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/arch/a53/csl_a53.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/src/ip/arm_gic/V2/csl_gic.h>

/* ========================================================================== */
/*                                 Macros & typedefs                          */
/* ========================================================================== */
#define ti_csl_arm_gicv3_writeSystemReg(regName, val) \
    {                                                                \
        __asm__ __volatile__ (                                       \
            "msr " #regName ", %0"                                   \
            :: "r" (val)                                             \
        );                                                           \
    }

#define ti_csl_arm_gicv3_readSystemReg(regName, val)  \
    {                                                                \
        __asm__ __volatile__ (                                       \
            "mrs %0, " #regName                                      \
            : "=r" (val)                                             \
        );                                                           \
    }

#if defined (SOC_AM65XX)
#define GIC_BASE_ADDR               (CSL_GIC0_DISTRIBUTOR_BASE)
#else
#define GIC_BASE_ADDR               (CSL_COMPUTE_CLUSTER0_GIC_DISTRIBUTOR_BASE)
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint64_t gCslA53InitControllerStatus = 0;
IntrFuncPtr    gFnRAMVectors[NUM_INTERRUPTS];
void          *gArgArray[NUM_INTERRUPTS] = {0};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *
 * The Default Interrupt Handler.
 *
 * This is the default interrupt handler for all interrupts.  It simply loops
 * forever so that the system state is preserved for observation by a
 * debugger.  Since interrupts should be disabled before unregistering the
 * corresponding handler, this should never be called.
 *
 *
 **/
void IntDefaultHandler(void *dummy)
{
    /* Go into an infinite loop.*/
    volatile uint32_t loop = 1U;
    while (1U == loop)
    {
        ;
    }
}

/**
 *
 * The Common Interrupt Handler.
 *
 * This is the common interrupt handler for all interrupts.
 *
 *
 **/
void IntCommonHandler(void)
{
    uint64_t     curIntId, intNum;
    uint64_t     isSpurious = 0U;

    /* Acknowledge Interrupt */
    ti_csl_arm_gicv3_readSystemReg(s3_0_c12_c12_0, curIntId); /* icc_iar1_el1 */

    /* Ignore spurious ints */
    if ((curIntId >= 1020) && (curIntId <= 1023))
    {
        isSpurious = 1U;
    }

    if (isSpurious == 0U)
    {
        intNum = curIntId;

        /* Process only pending interrupt */
        curIntId &= 0x3FF;

        /* Call user ISR function in system mode and then return back to IRQ mode */
        (gFnRAMVectors[intNum])(gArgArray[intNum]);

        /* Signal End of Interrupt */
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_1, intNum); /* icc_eoir1_el1 */
    }
}


void Intc_IntRegister(uint16_t intrNum, IntrFuncPtr fptr, void *fun_arg)
{
    /* Assign ISR */
    gFnRAMVectors[intrNum] = fptr;
    gArgArray[intrNum] = fun_arg;
    return;
}

int32_t Intc_IntAssignLevelIntType(uint16_t intrNum)
{
  CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);
  return(CSL_gicAssignLevelSPIIntType(gicdRegs, (uint32_t)intrNum));
}

int32_t Intc_IntAssignEdgeIntType(uint16_t intrNum)
{
  CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);
  return(CSL_gicAssignEdgeSPIIntType(gicdRegs, (uint32_t)intrNum));
}

void Intc_IntUnregister(uint16_t intrNum)
{
    uintptr_t IntDefaultHandler_t = (uintptr_t) (&IntDefaultHandler);
    /* Assign default ISR */
    gFnRAMVectors[intrNum] = (IntrFuncPtr) IntDefaultHandler_t;
    gArgArray[intrNum]     = NULL;
    return;
}

void Intc_Init(uint8_t cpuId)
{
    CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);
    CSL_gic500_gicrRegs_core_control *gicrRegs;
    CSL_gic500_gicrRegs_core_sgi_ppi *gicsRegs;

    uint32_t i = 0, j = 0, intActiveReg = 0;
    uint32_t routingMode = 0;
    uint8_t  aff0 = 0, aff1 = 0;

    /* update the redistributor and sgi_ppi address */
    gicrRegs = (CSL_gic500_gicrRegs_core_control *) (GIC_BASE_ADDR + CSL_GIC500_GICR_CORE_CONTROL_CTLR(cpuId));
    gicsRegs = (CSL_gic500_gicrRegs_core_sgi_ppi *) ((uintptr_t)gicrRegs + (uintptr_t) 0x10000U);

    if (gCslA53InitControllerStatus == 1)
    {
        /* Interrupt controller is already initialized */
        return;
    }

    /* Initialize the Interrupt controller */
    {
        /* Disable IRQs */
        CSL_a53v8ArmGicv3HwiDisable();
        /* Enable interrupt controller system register access at EL1 */
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_5, 0x7); /* icc_sre_el1 */

        /*
         * Disable forwarding of interrupts in GIC Distributer and CPU interface
         * Controller.
         */
        gicdRegs->CTLR = 0x0U;
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_7, 0x0); /* icc_igrpen1_el1 */

        /*
         * Disable all interrupts at startup
         */
        gicsRegs->ICENABLER0 = 0xFFFFFFFF;
        for (i = 0; i < 30; i++)
        {
           gicdRegs->ICENABLER_SPI[i] = 0xFFFFFFFF;
        }

        /*
         * Enable forwarding of interrupts in GIC Distributor and CPU interface
         * Controller.
         */
        gicdRegs->CTLR = 0x2;
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_7, 0x1);   /* icc_igrpen1_el1 */

        /* Search for any previously active interrupts and acknowledge them */
        intActiveReg = gicsRegs->ICACTIVER0;
        if (intActiveReg)
        {
            for (j = 0; j < 32; j++)
            {
                if (intActiveReg & 0x1) {
                ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_1, j);   /* icc_eoir1_el1 */
                }
                intActiveReg = intActiveReg >> 1;
            }
        }

        for (i = 0; i < 30; i++)
        {
            intActiveReg = gicdRegs->ISACTIVER_SPI[i];
            if (intActiveReg) {
                for (j = 0; j < 32; j++) {
                    if (intActiveReg & 0x1) {
                        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_1, (i * 32) + j);
                                                 /* icc_eoir1_el1 */
                    }
                    intActiveReg = intActiveReg >> 1;
                }
            }
        }

        /*
         * Clear any currently pending enabled interrupts
         */
        gicsRegs->ICPENDR0  = 0xFFFFFFFF;
        for (i = 0; i < 30; i++) {
            gicdRegs->ICPENDR_SPI[i] = 0xFFFFFFFF;
        }

        /*
         * Clear all interrupt active status registers
         */
        gicsRegs->ICACTIVER0 = 0xFFFFFFFF;
        for (i = 0; i < 30; i++) {
            gicdRegs->ICACTIVER_SPI[i] = 0xFFFFFFFF;
        }
        /*
         * Initialize the interrupt routing registers for all
         * interrupts (32-1019).
         *
         * Interrupt number lower than 32 are not routed using these registers.
         */
         for (i = 0; i < 960; i++) {
             gicdRegs->IROUTER[i].LOWER =  (aff1 << 8 | aff0);
             gicdRegs->IROUTER[i].UPPER = routingMode;
         }

        /*
         * Initialize Binary Point Register
         */
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c12_c12_3, 3);   /* icc_bpr1_el1 */

        /*
         * Set preconfigured interrupt Sense and Priority for each
         * interrupt
         */
        for (i = 0; i < 8; i++)
        {
           gicsRegs->IPRIORITYR[i]=0x20202020;
           CSL_a53v8DsbSy();
        }
        for (i = 0; i < 240; i++)
        {
           gicdRegs->IPRIORITYR_SPI[i]= 0x20202020;
           CSL_a53v8DsbSy();
        }

        /*
         * Initialize Interrupt Priority Mask Register
         *
         * Initialize PMR with the minimum possible interrupt priority.
         */
        ti_csl_arm_gicv3_writeSystemReg(s3_0_c4_c6_0, 0xFF); /* icc_pmr_el1 */

        /*
         * Set trigger sensitivity of interrupts
         *
         * On the Cortex-A15:
         *  -   For SGI:
         *          The ICFGR bits are read-only and a bit-pair always reads as
         *          b10 because SGIs are edge-triggered.
         *  -   For PPI and SPI :
         *          The LSB of the bit-pair is read only and is always 0. MSB can
         *          be altered to change trigger sensitivity.
         *          b00    Interrupt is active-High level-sensitive
         *          b10    Interrupt is rising edge-sensitive
         */
        gicsRegs->ICFGR1 = 0;
        for (i = 0; i < (30 * 2); i++) {
           gicdRegs->ICFGR_SPI[i] = 0;
        }

    }

    /* record the initialization is done */
    gCslA53InitControllerStatus = 1;

    /* Register the default handlers */
    for(i = 0; i < NUM_INTERRUPTS; i++)
    {
      uintptr_t IntDefaultHandler_t = (uintptr_t) (&IntDefaultHandler);
      /* Assign default ISR */
      gFnRAMVectors[i] = (IntrFuncPtr) IntDefaultHandler_t;
      gArgArray[i]     = NULL;

    }
    return;
}

Bool Intc_isInitialized(void)
{
  if (gCslA53InitControllerStatus != 0)
  {
    return ((Bool) TRUE);
  }
  else
  {
    return ((Bool) FALSE);
  }
}

void Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority,
                         uint8_t coreId)
{
    CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);
    CSL_gic500_gicrRegs *gicrRegs;

    /* update the redistributor and sgi_ppi address */
    gicrRegs = (CSL_gic500_gicrRegs *) (GIC_BASE_ADDR + CSL_GIC500_GICR_CORE_CONTROL_CTLR(0));

    if (intrNum < 32)
    {
        CSL_gicSetSgiPpiIntrPriority(gicrRegs, (uint32_t) coreId, (uint32_t) intrNum, (uint32_t) priority);
    }
    else if (intrNum < 960)
    {
        CSL_gicSetSpiIntrPriority(gicdRegs, (uint32_t)intrNum, (uint32_t)priority);
    }
    else
    {
      /* No action */
    }
    CSL_a53v8DsbSy();

    return;

}

uint32_t Intc_SystemEnable(uint16_t intrNum)
{
    uint32_t oldEnableState = 0U;
    uint64_t index, mask;
    uint64_t key;
    CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);

    key = CSL_a53v8ArmGicv3HwiDisable();
    index = intrNum / 32;
    mask = 1 << (intrNum & 0x1f);

    if (index > 0)
    {
      index--;
      oldEnableState = gicdRegs->ISENABLER_SPI[index] & mask;
      gicdRegs->ISENABLER_SPI[index] =  mask;
    }
    CSL_a53v8ArmGicv3HwiRestore(key);

    CSL_a53v8ArmGicv3HwiEnable();

    return oldEnableState;

}

uint32_t Intc_SystemDisable(uint16_t intrNum)
{
    uint64_t     key, index, mask;
    uint32_t     oldEnableState=0U;

    CSL_gic500_gicdRegs *gicdRegs = (CSL_gic500_gicdRegs *)(GIC_BASE_ADDR);

    key = CSL_a53v8ArmGicv3HwiDisable();
    index = intrNum / 32;
    mask = 1 << (intrNum & 0x1f);

    if (index > 0)
    {
      index--;
      oldEnableState = gicdRegs->ISENABLER_SPI[index] & mask;
      gicdRegs->ICENABLER_SPI[index] =  mask;
    }

    CSL_a53v8ArmGicv3HwiRestore(key);

    return oldEnableState;

}

void Intc_AbortHandler(uint64_t *excStack)
{
    /* Read the ESR_EL1 register */
    uint32_t esr_el1, exception_class;
    volatile uint32_t loop = 1U;
    esr_el1 = excStack[1];

    exception_class = (esr_el1 >> 26);

    switch (exception_class)
    {
        /* Instruction abort */
        case 0x20:
        case 0x21:
        /* Data abort */
        case 0x24:
        case 0x25:
        /* Illegal execution state or PC/SP alignment fault */
        case 0x0E:
        case 0x22:
        case 0x26:
        /* SVC */
        case 0x15:
        default:
            /* Go into an infinite loop.*/
            while (1U == loop)
            {
                ;
            }
            break;
    }
}

/********************************** End Of File ******************************/
