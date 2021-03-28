/*
 *  Copyright (C) 2013-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stddef.h>
#include <c6x.h>
#include <ti/csl/soc.h>
#include <interrupt.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_types.h>
#if defined (TI814X_BUILD) || defined (TI8149_BUILD) || defined (TI811X_BUILD)
/* not required */
#else
#include <ti/csl/arch/csl_arch.h>
#endif

/* ========================================================================== */
/*                                 Macros & typedefs                          */
/* ========================================================================== */
/* number of DSP interrupt handlers 0..127*/
#define INTH_INT_TABLE_SIZE     128U

/* Max interrupt number*/
#define INTH_INT_NUM_MAX     (INTH_INT_TABLE_SIZE - 1U)

/* ISR table Handler size*/
#define ISR_HANDLER_SIZE       (8U)

typedef void (*InterIsrFuncPtr)(void);

typedef struct NmiIrqPrams
{
    IntrFuncPtr fPtr;
    void *args;
}NmiIrqPrams_t;

/* ========================================================================== */
/*                      External Function Declarations                        */
/* ========================================================================== */
extern void init_regs(void);

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/* static __inline uint32_t get_int_evtflag(uint32_t i); */
/* static __inline void set_int_evt(uint32_t i, uint32_t val); */
static __inline uint32_t get_int_mevtflag(uint32_t i);
static __inline void clr_int_evt(uint32_t i, uint32_t val);
static __inline uint32_t get_int_evtmask(uint32_t i);
static __inline void set_int_evtmask(uint32_t i, uint32_t val);

#if 0 /* Unused Functions */
/*
 * \brief Macro to get the status of the events
 * \Param i  = register index for the register index passed
 *       i = 0 Get status of register DSP_EVTFLAG0
 *       i = 1 Get status of register DSP_EVTFLAG1
 *       i = 2 Get status of register DSP_EVTFLAG2
 *       i = 3 Get status of register DSP_EVTFLAG3
 */
static __inline uint32_t get_int_evtflag(uint32_t i)
{
    uint32_t retval;

    retval = HW_RD_REG32(SOC_DSP_ICFG_BASE + DSP_EVTFLAG0 + \
                         ((i) << 2U));
    return retval;
}

/*
 * \brief Macro to set the event for the register index passed
 * \Param i  = register index
 *       i = 0 Set event in register DSP_EVTSET0
 *       i = 1 Set event in register DSP_EVTSET1
 *       i = 2 Set event in register DSP_EVTSET2
 *       i = 3 Set event in register DSP_EVTSET3
 *
 *       val = value to be written to register
 */

static __inline void set_int_evt(uint32_t i, uint32_t val)
{
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_EVTSET0 + \
                 ((i) << 2U)), (val));
}

#endif

static __inline uint32_t get_int_mevtflag(uint32_t i)
{
    uint32_t retval;

    retval = HW_RD_REG32(SOC_DSP_ICFG_BASE + \
                         DSP_MEVTFLAG0 +     \
                         ((i) << 2U));
    return retval;
}

/*
 * \brief Macro to clear the event for the register index passed
 * \Param i  = register index
 *       i = 0 clear event by writting to register DSP_EVTCLR0
 *       i = 1 clear event by writting to register DSP_EVTCLR1
 *       i = 2 clear event by writting to register DSP_EVTCLR2
 *       i = 3 clear event by writting to register DSP_EVTCLR3
 *
 *       val = value to be written to register
 */

static __inline void clr_int_evt(uint32_t i, uint32_t val)
{
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_EVTCLR0 + \
                 ((i) << 2U)), (val));
}

/*
 * \brief Get Masked event status for the register index passed
 * \Param i  = register index
 *       i = 0 Get event mask for register DSP_EVTMASK0
 *       i = 1 Get event mask for register DSP_EVTMASK1
 *       i = 2 Get event mask for register DSP_EVTMASK2
 *       i = 3 Get event mask for register DSP_EVTMASK3
 *
 */
static __inline uint32_t get_int_evtmask(uint32_t i)
{
    uint32_t retval;

    retval = HW_RD_REG32(SOC_DSP_ICFG_BASE + DSP_EVTMASK0 + \
                         ((i) << 2U));
    return retval;
}

/*
 * \brief Mask the events for the register index passed with mask val
 * \Param i  = register index
 *       i = 0 Set event mask for register DSP_EVTMASK0
 *       i = 1 Set event mask for register DSP_EVTMASK1
 *       i = 2 Set event mask for register DSP_EVTMASK2
 *       i = 3 Set event mask for register DSP_EVTMASK3
 *
 */
static __inline void set_int_evtmask(uint32_t i, uint32_t val)
{
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_EVTMASK0 + \
                 ((i) << 2U)), (val));
}

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* L2 Interrupt Vector Table */
#ifdef __cplusplus
#pragma DATA_SECTION(".l2_int")
#else
#pragma DATA_SECTION(inth_IrqHandler, ".l2_int")
#endif  /* #ifdef __cplusplus */
IntrFuncPtr     inth_IrqHandler[INTH_INT_TABLE_SIZE];

void           *argArray[INTH_INT_TABLE_SIZE] = {0};
uint32_t        INTH_intRouting[16];

#ifdef __cplusplus
#pragma DATA_SECTION(".vects")
#else
#pragma DATA_SECTION(__ISR_Table, ".vects")
#pragma DATA_ALIGN(__ISR_Table, 1024)
#endif  /* #ifdef __cplusplus */
uint32_t        __ISR_Table[(16U)*ISR_HANDLER_SIZE];

/* array of interrupt counter */
static uint32_t inth_IrqCount[INTH_INT_TABLE_SIZE];

NmiIrqPrams_t gL1IrqQ1Handler = {NULL, NULL};
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void Intc_IntInstallIrqHandler(uint32_t *vec, InterIsrFuncPtr ptr);
static void Intc_IntInstallRstIrqHandler(uint32_t *vec, InterIsrFuncPtr ptr);
static void scanCombined(uint8_t *intNo, uint32_t flag, uint32_t combNo);
void INTH_IRQHandler(uint8_t l1intNumber);

interrupt void NmiHandler(void);
interrupt void INTH_L1IRQ4Handler(void);
interrupt void INTH_L1IRQ5Handler(void);
interrupt void INTH_L1IRQ6Handler(void);
interrupt void INTH_L1IRQ7Handler(void);
interrupt void INTH_L1IRQ8Handler(void);
interrupt void INTH_L1IRQ9Handler(void);
interrupt void INTH_L1IRQ10Handler(void);
interrupt void INTH_L1IRQ11Handler(void);
interrupt void INTH_L1IRQ12Handler(void);
interrupt void INTH_L1IRQ13Handler(void);
interrupt void INTH_L1IRQ14Handler(void);
interrupt void INTH_L1IRQ15Handler(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void Intc_IntRegister(uint16_t intrNum, IntrFuncPtr fptr, void *fun_arg)
{
    if (1U == intrNum)
    {
        gL1IrqQ1Handler.fPtr = fptr;
        gL1IrqQ1Handler.args = fun_arg;
        /* Register Exception Handler */
        Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(1U)]),
                                   &NmiHandler);
    }
    else if (intrNum > 3U)
    {
        /* reset counter and install handler */
        inth_IrqCount[intrNum]   = 0;
        inth_IrqHandler[intrNum] = fptr;
        argArray[intrNum]        = fun_arg;
    }
    else
    {
        /* Nothing */
    }
} /* EVE_HOST_INTH_InterruptSetup() */

void Intc_SystemEnable(uint16_t intrNum)
{
    uint32_t uTmp;
    uint32_t rgs;
    uint32_t tempVal;

    uTmp = (uint32_t) intrNum >> 5;

    rgs     = get_int_evtmask(uTmp);
    tempVal = (~(uint32_t) ((uint32_t) 1U << ((uint32_t) intrNum & 0x1FU)));
    rgs    &= (uint32_t) tempVal;
    set_int_evtmask(uTmp, rgs);
#if defined (TI814X_BUILD) || defined (TI8149_BUILD) || defined (TI811X_BUILD) || defined (SOC_K2G) || \
     defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)|| \
     defined(SOC_C6678)||defined(SOC_C6657)||defined(SOC_J721E)||defined(SOC_TPR12)
/* not required */
#else
    DSP_WUGEN_IRQ_Enable(intrNum);
#endif
}

void Intc_SystemDisable(uint16_t intrNum)
{
    uint32_t uTmp;
    uint32_t rgs;
    uint32_t tempVal;

    uTmp = (uint32_t) intrNum >> 5;

    rgs     = get_int_evtmask(uTmp);
    tempVal = (uint32_t) ((uint32_t) 1U << (intrNum & 0x1FU));
    rgs    |= (uint32_t) tempVal;
    set_int_evtmask(uTmp, rgs);
#if defined (TI814X_BUILD) || defined (TI8149_BUILD) || defined (TI811X_BUILD) || defined (SOC_K2G) || \
     defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)|| \
     defined(SOC_C6678)||defined(SOC_C6657)||defined(SOC_J721E)||defined(SOC_TPR12)
/* not required */
#else
    DSP_WUGEN_IRQ_Disable(intrNum);
#endif
}

void INTH_IRQHandler(uint8_t l1intNumber)

{
    uint8_t  intNumber[32];

    uint32_t FlagLatch = 0;
    uint32_t pass;

    intNumber[0] = 0;

    switch (l1intNumber)
    {
        case (uint8_t) 4:
            FlagLatch = get_int_mevtflag((uint32_t) 0);
            clr_int_evt((uint32_t) 0, FlagLatch);
            scanCombined(intNumber, FlagLatch, (uint32_t) 0U);
            break;
        case (uint8_t) 5:
            FlagLatch = get_int_mevtflag((uint32_t) 1);
            clr_int_evt((uint32_t) 1, FlagLatch);
            scanCombined(intNumber, FlagLatch, (uint32_t) 1U);
            break;
        case (uint8_t) 6:
            FlagLatch = get_int_mevtflag((uint32_t) 2);
            clr_int_evt((uint32_t) 2, FlagLatch);
            scanCombined(intNumber, FlagLatch, (uint32_t) 2U);
            break;
        case (uint8_t) 7:
            FlagLatch = get_int_mevtflag((uint32_t) 3);
            clr_int_evt((uint32_t) 3, FlagLatch);
            scanCombined(intNumber, FlagLatch, (uint32_t) 3U);
            break;
        default:
            intNumber[0] = (uint8_t) INTH_intRouting[l1intNumber];
            intNumber[1] = 0;
            pass         = ((uint32_t) intNumber[0] >> 5U);
            clr_int_evt((uint32_t) pass,
                        ((uint32_t) 1U <<
                         ((uint32_t) intNumber[0] - (uint32_t) (pass << 5U))));
            break;
    }

    while (0U != FlagLatch)
    {
        /* Process all active interrupts */
        pass = 0;
        while (0 != intNumber[pass]) {
            /* increment interrupt counter */
            inth_IrqCount[intNumber[pass]]++;

            if (0 != inth_IrqHandler[intNumber[pass]])
            {
                /* call regitered interrupt handler */
                inth_IrqHandler[intNumber[pass]](argArray[intNumber[pass]]);
            }
            pass++;
        }

        switch (l1intNumber)
        {
            case (uint8_t) 4:
                FlagLatch = get_int_mevtflag((uint32_t) 0);
                clr_int_evt((uint32_t) 0, FlagLatch);
                scanCombined(intNumber, FlagLatch, (uint32_t) 0);
                break;
            case (uint8_t) 5:
                FlagLatch = get_int_mevtflag((uint32_t) 1);
                clr_int_evt((uint32_t) 1, FlagLatch);
                scanCombined(intNumber, FlagLatch, (uint32_t) 1);
                break;
            case (uint8_t) 6:
                FlagLatch = get_int_mevtflag((uint32_t) 2);
                clr_int_evt((uint32_t) 2, FlagLatch);
                scanCombined(intNumber, FlagLatch, (uint32_t) 2);
                break;
            case (uint8_t) 7:
                FlagLatch = get_int_mevtflag((uint32_t) 3);
                clr_int_evt((uint32_t) 3, FlagLatch);
                scanCombined(intNumber, FlagLatch, (uint32_t) 3);
                break;
            default:
                intNumber[0] = (uint8_t) INTH_intRouting[l1intNumber];
                intNumber[1] = 0;
                pass         = ((uint32_t) intNumber[0] >> 5U);
                clr_int_evt(pass,
                            ((uint32_t) 1U <<
                             ((uint32_t) intNumber[0] -
                              (uint32_t) (pass << 5U))));
                break;
        }
    }
}  /* INTH_IRQHandler() */

void Intc_IntUnregister(uint16_t intrNum)
{
    uint32_t L1int;

    /* Find and clean interrupt entry in INTH_intRouting table */
    for (L1int = 8U; L1int < 16U; L1int++)
    {
        if (INTH_intRouting[L1int] == intrNum)
        {
            /*reset interrupt routing entry*/
            INTH_intRouting[L1int] = 0;

            /*reset counter and deinstall handler*/
            inth_IrqCount[intrNum]   = 0;
            inth_IrqHandler[intrNum] = NULL;
        }
    }
}

void Intc_IntEnable(uint32_t status)
{
    /* Set GIE */
    CSR |= (uint32_t) 0x1U;

}

uint32_t Intc_IntDisable(void)
{

    /* Clear GIE */
    CSR &= ~(uint32_t) 0x1U;

    return ((uint32_t) 0U);
}

void Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority,
                         uint8_t hostIntRoute)
{
    /* Dummy function in DSP */
}

static void scanCombined(uint8_t *intNo, uint32_t flag, uint32_t combNumber)
{
    volatile uint32_t  count;
    uint32_t     one = 1U, combNo, flag_hi, flag_lo;
    uint32_t     b0,   b1,  b2,  b3;
    uint32_t     b4,   b5,  b6,  b7;
    uint32_t     b8,   b9, b10, b11;
    uint32_t     b12, b13, b14, b15;
    uint32_t     b16, b17, b18, b19;
    uint32_t     b20, b21, b22, b23;
    uint32_t     b24, b25, b26, b27;
    uint32_t     b28, b29, b30, b31;

    /* Initialize Count to Zero, as below to eliminate Klocwork warnings */
    count  = (uint32_t) (0U);
    /* Combined Number can be only 0, 1, 2, 3 
     * Limit to one of those values to eliminate Klocwork warnings */
    combNo = combNumber & 3U;

/* The below implementation takes about 18000 Cycles
 * which is pretty high.. Hence the optimization is done for the below code
 * via loop unroll technique, which takes about only 300 cycles
 *
 *   if (0U == combNo)
 *   {
 *       i = 4U;
 *   }
 *   else
 *   {
 *       i = 0U;
 *   }
 *
 *   for (; i < 32U; i++)
 *   {
 *       if ((uint32_t) 0 != (flag & (uint32_t) ((uint32_t) 1U << i)))
 *       {
 *           intNo[count] = ((uint8_t) (i + (combNo << 5)));
 *           if (count < 31U)
 *           {
 *               count+=1U;
 *           }
 *       }
 *   }
 */

    /* Extract the hi and lo parts */
    flag_lo = (flag & (uint32_t) ((uint32_t) 0xFFFFU));
    flag_hi = (flag >> (uint32_t) ((uint32_t) 16U));

    /* Event Combiner 0 has 4 LSBs reserved for EVT0, EVT1, EVT2 and EVT3 */
    if (0U != combNo)
    {
        b0 = (flag_lo & (uint32_t) ((uint32_t) 1U));
        b1 = (flag_lo & (uint32_t) ((uint32_t) 2U));
        b2 = (flag_lo & (uint32_t) ((uint32_t) 4U));
        b3 = (flag_lo & (uint32_t) ((uint32_t) 8U));
        /* Prepare the intNo */
        if (b0 != 0U)  { intNo[count] = ((uint8_t) (0U + (combNo << 5))); count+=one;}
        if (b1 != 0U)  { intNo[count] = ((uint8_t) (1U + (combNo << 5))); count+=one;}
        if (b2 != 0U)  { intNo[count] = ((uint8_t) (2U + (combNo << 5))); count+=one;}
        if (b3 != 0U)  { intNo[count] = ((uint8_t) (3U + (combNo << 5))); count+=one;}
    }
    /* Remaining bit extract for rest of the bits */
    b4 = (flag_lo & (uint32_t) ((uint32_t) 16U));
    b5 = (flag_lo & (uint32_t) ((uint32_t) 32U));
    b6 = (flag_lo & (uint32_t) ((uint32_t) 64U));
    b7 = (flag_lo & (uint32_t) ((uint32_t) 128U));

    b8 = (flag_lo & (uint32_t) ((uint32_t) 256U));
    b9 = (flag_lo & (uint32_t) ((uint32_t) 512U));
    b10 = (flag_lo & (uint32_t) ((uint32_t) 1024U));
    b11 = (flag_lo & (uint32_t) ((uint32_t) 2048U));

    b12 = (flag_lo & (uint32_t) ((uint32_t) 4096U));
    b13 = (flag_lo & (uint32_t) ((uint32_t) 8192U));
    b14 = (flag_lo & (uint32_t) ((uint32_t) 16384U));
    b15 = (flag_lo & (uint32_t) ((uint32_t) 32768U));

    /* Prepare the intNo */
    if (b4 != 0U)  { intNo[count] = ((uint8_t) (4U + (combNo << 5))); count+=one;}
    if (b5 != 0U)  { intNo[count] = ((uint8_t) (5U + (combNo << 5))); count+=one;}
    if (b6 != 0U)  { intNo[count] = ((uint8_t) (6U + (combNo << 5))); count+=one;}
    if (b7 != 0U)  { intNo[count] = ((uint8_t) (7U + (combNo << 5))); count+=one;}
    if (b8 != 0U)  { intNo[count] = ((uint8_t) (8U + (combNo << 5))); count+=one;}
    if (b9 != 0U)  { intNo[count] = ((uint8_t) (9U + (combNo << 5))); count+=one;}
    if (b10 != 0U) { intNo[count] = ((uint8_t) (10U + (combNo << 5))); count+=one;}
    if (b11 != 0U) { intNo[count] = ((uint8_t) (11U + (combNo << 5))); count+=one;}
    if (b12 != 0U) { intNo[count] = ((uint8_t) (12U + (combNo << 5))); count+=one;}
    if (b13 != 0U) { intNo[count] = ((uint8_t) (13U + (combNo << 5))); count+=one;}
    if (b14 != 0U) { intNo[count] = ((uint8_t) (14U + (combNo << 5))); count+=one;}
    if (b15 != 0U) { intNo[count] = ((uint8_t) (15U + (combNo << 5))); count+=one;}

    /* Remaining bit extract for rest of the bits */
    b16 = (flag_hi & (uint32_t) ((uint32_t) 1U));
    b17 = (flag_hi & (uint32_t) ((uint32_t) 2U));
    b18 = (flag_hi & (uint32_t) ((uint32_t) 4U));
    b19 = (flag_hi & (uint32_t) ((uint32_t) 8U));

    b20 = (flag_hi & (uint32_t) ((uint32_t) 16U));
    b21 = (flag_hi & (uint32_t) ((uint32_t) 32U));
    b22 = (flag_hi & (uint32_t) ((uint32_t) 64U));
    b23 = (flag_hi & (uint32_t) ((uint32_t) 128U));

    b24 = (flag_hi & (uint32_t) ((uint32_t) 256U));
    b25 = (flag_hi & (uint32_t) ((uint32_t) 512U));
    b26 = (flag_hi & (uint32_t) ((uint32_t) 1024U));
    b27 = (flag_hi & (uint32_t) ((uint32_t) 2048U));

    b28 = (flag_hi & (uint32_t) ((uint32_t) 4096U));
    b29 = (flag_hi & (uint32_t) ((uint32_t) 8192U));
    b30 = (flag_hi & (uint32_t) ((uint32_t) 16384U));
    b31 = (flag_hi & (uint32_t) ((uint32_t) 32768U));

    /* Prepare the intNo */
    if (b16 != 0U)  { intNo[count] = ((uint8_t) (16U + (combNo << 5))); count+=one;}
    if (b17 != 0U)  { intNo[count] = ((uint8_t) (17U + (combNo << 5))); count+=one;}
    if (b18 != 0U)  { intNo[count] = ((uint8_t) (18U + (combNo << 5))); count+=one;}
    if (b19 != 0U)  { intNo[count] = ((uint8_t) (19U + (combNo << 5))); count+=one;}
    if (b20 != 0U)  { intNo[count] = ((uint8_t) (20U + (combNo << 5))); count+=one;}
    if (b21 != 0U)  { intNo[count] = ((uint8_t) (21U + (combNo << 5))); count+=one;}
    if (b22 != 0U)  { intNo[count] = ((uint8_t) (22U + (combNo << 5))); count+=one;}
    if (b23 != 0U)  { intNo[count] = ((uint8_t) (23U + (combNo << 5))); count+=one;}
    if (b24 != 0U)  { intNo[count] = ((uint8_t) (24U + (combNo << 5))); count+=one;}
    if (b25 != 0U)  { intNo[count] = ((uint8_t) (25U + (combNo << 5))); count+=one;}
    if (b26 != 0U)  { intNo[count] = ((uint8_t) (26U + (combNo << 5))); count+=one;}
    if (b27 != 0U)  { intNo[count] = ((uint8_t) (27U + (combNo << 5))); count+=one;}
    if (b28 != 0U)  { intNo[count] = ((uint8_t) (28U + (combNo << 5))); count+=one;}
    if (b29 != 0U)  { intNo[count] = ((uint8_t) (29U + (combNo << 5))); count+=one;}
    if (b30 != 0U)  { intNo[count] = ((uint8_t) (30U + (combNo << 5))); count+=one;}
    if (b31 != 0U)  { intNo[count]   = ((uint8_t) (31U + (combNo << 5)));}

    intNo[count] = (uint8_t)(0);
} /* scanCombined() */

void Intc_Init(void)
{
    uint32_t count;
    uint32_t mask;

    /* Now, enable the 4,5,6, and 7 bits of IER
     *     These involve the default priority mode which uses the interrupt
     *       combiner */

    /* Clear all entries in L2 interrupt handler */
    for (count = 0U; count < INTH_INT_TABLE_SIZE; count++)
    {
        inth_IrqHandler[count] = NULL;
    }

    /* Clear Routing Table */
    for (count = 0U; count < 16U; count++)
    {
        INTH_intRouting[count] = 0;
    }

    /* Route combined inputs */
    INTH_intRouting[4] = ((uint32_t) INTH_INT_ID_EVT0);
    INTH_intRouting[5] = ((uint32_t) INTH_INT_ID_EVT1);
    INTH_intRouting[6] = ((uint32_t) INTH_INT_ID_EVT2);
    INTH_intRouting[7] = ((uint32_t) INTH_INT_ID_EVT3);

    /* Configure IC */
    /* Remove all inputs from combiner */
    for (count = 0U; count < 4U; count++)
    {
        clr_int_evt(count, 0xFFFFFFFFU);
        set_int_evtmask(count, 0xFFFFFFFFU);
    }

    /*Mask dropped interrupts*/
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_INTDMASK), (uint32_t) 0xFFF0U);

    /*
     * Program the interrupt selector here,
     * the first 4 interrupt output of the interrupt selector is
     * routed from the interrupt combiner
     * Each of these interrupt line cater to 32 event input lines
     *
     * Below is the mapping -
     * 0 bit -> 0-31 event lines
     * 1 bit -> 32-63 event lines
     * 2 bit -> 64-95 event lines
     * 3 bit -> 96-127 event lines
     *
     */
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_INTMUX1), 0x03020100U);

    /* Route unused EVT 119 to other interrupt inputs */
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_INTMUX2), 0x77777777U);
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_INTMUX3), 0x77777777U);

    ICR = 0xffffU;

    /*Setting vector table base address*/
    ISTP = (uint32_t)&(__ISR_Table[0]);

    /* Clear Dropped interrupts */
    HW_WR_REG32((SOC_DSP_ICFG_BASE + DSP_INTXCLR), (uint32_t) 0x1U);

     Intc_IntInstallRstIrqHandler(&(__ISR_Table[0]),  &init_regs);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(4U)]),
                               &INTH_L1IRQ4Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(5U)]),
                               &INTH_L1IRQ5Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(6U)]),
                               &INTH_L1IRQ6Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(7U)]),
                               &INTH_L1IRQ7Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(8U)]),
                               &INTH_L1IRQ8Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(9U)]),
                               &INTH_L1IRQ9Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(10U)]),
                               &INTH_L1IRQ10Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(11U)]),
                               &INTH_L1IRQ11Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(12U)]),
                               &INTH_L1IRQ12Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(13U)]),
                               &INTH_L1IRQ13Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(14U)]),
                               &INTH_L1IRQ14Handler);
    Intc_IntInstallIrqHandler(&(__ISR_Table[ISR_HANDLER_SIZE*(15U)]),
                               &INTH_L1IRQ15Handler);

    mask = 0x000000f2U;
    IER |= mask;

    /* Enable the Global Interrupt Enable bit in CSR register of GEM
     * Also enable Global Exception Enable and Maskable Exception Enable in TSR
     */
    CSR |= 0x00000001U;
    TSR |= 0x00000004U;
    TSR |= 0x00000008U;
#if defined (TI814X_BUILD) || defined (TI8149_BUILD) || defined (TI811X_BUILD) || defined (SOC_K2G) || \
     defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)|| \
     defined(SOC_C6678)||defined(SOC_C6657)||defined(SOC_J721E)||defined(SOC_TPR12)
/* not required */
#else
    DSP_WUGEN_IRQ_Init();
#endif
} /* INTH_InitIntTable() */

static void Intc_IntInstallIrqHandler(uint32_t *vec, InterIsrFuncPtr ptr)
{
   uint32_t low = (uint32_t)ptr & 0xffffU;
   uint32_t high = (uint32_t)ptr >> 16;

   vec[0] = 0x003C54F6U;                        /* STW.D2T2      B0,*B15--[2] */
   vec[1] = 0x0000002AU | ((low) << 7);         /* MVK.S2        #ptr,B0 */
   vec[2] = 0x0000006AU | ((high) << 7);        /* MVKH.S2       #ptr,B0 */
   vec[3] = 0x00000362U;                        /* B.S2          B0 */
   vec[4] = 0x003C52E6U;                        /* LDW.D2T2      *++B15[2],B0 */
   vec[5] = 0x00006000U;                        /* NOP 4 */
   vec[6] = 0x00000000U;                        /* NOP */
   vec[7] = 0x00000000U;                        /* NOP */
}

static void Intc_IntInstallRstIrqHandler(uint32_t *vec, InterIsrFuncPtr ptr)
{
   uint32_t cst21 = ((uint32_t)ptr - (uint32_t)&vec[0]) >> 2;

   vec[0] = 0x00000012U | (cst21 << 7);         /* B.S2            #ptr */
   vec[1] = 0x00006000U;                        /* NOP 4 */
   vec[2] = 0x00006000U;                        /* NOP 4 */
   vec[3] = 0x00006000U;                        /* NOP 4 */
   vec[4] = 0x00006000U;                        /* NOP 4 */
   vec[5] = 0x00006000U;                        /* NOP 4 */
   vec[6] = 0x00006000U;                        /* NOP 4 */
   vec[7] = 0x00006000U;                        /* NOP 4 */
}

#ifdef __cplusplus
#pragma NMI_INTERRUPT
#else
#pragma NMI_INTERRUPT( NmiHandler )
#endif
void NmiHandler(void)
{
    if(gL1IrqQ1Handler.fPtr != NULL)
    {
        gL1IrqQ1Handler.fPtr(gL1IrqQ1Handler.args);
    }
    while(1)
    {
        /* Code is not expected to be returned after entering
        exception handler */
    }
}

interrupt void INTH_L1IRQ4Handler(void)
{
    INTH_IRQHandler((uint8_t) 4);
}

interrupt void INTH_L1IRQ5Handler(void)
{
    INTH_IRQHandler((uint8_t) 5);
}

interrupt void INTH_L1IRQ6Handler(void)
{
    INTH_IRQHandler((uint8_t) 6);
}

interrupt void INTH_L1IRQ7Handler(void)
{
    INTH_IRQHandler((uint8_t) 7);
}

interrupt void INTH_L1IRQ8Handler(void)
{
    INTH_IRQHandler((uint8_t) 8);
}

interrupt void INTH_L1IRQ9Handler(void)
{
    INTH_IRQHandler((uint8_t) 9);
}

interrupt void INTH_L1IRQ10Handler(void)
{
    INTH_IRQHandler((uint8_t) 10);
}

interrupt void INTH_L1IRQ11Handler(void)
{
    INTH_IRQHandler((uint8_t) 11);
}

interrupt void INTH_L1IRQ12Handler(void)
{
    INTH_IRQHandler((uint8_t) 12);
}

interrupt void INTH_L1IRQ13Handler(void)
{
    INTH_IRQHandler((uint8_t) 13);
}

interrupt void INTH_L1IRQ14Handler(void)
{
    INTH_IRQHandler((uint8_t) 14);
}

interrupt void INTH_L1IRQ15Handler(void)
{
    INTH_IRQHandler((uint8_t) 15);
}

/********************************* End of file ******************************/
