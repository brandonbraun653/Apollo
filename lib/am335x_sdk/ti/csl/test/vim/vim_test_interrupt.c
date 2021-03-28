/*
 *  Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   vim_test_interrupt.c
 *
 *  \brief  Interrupt related APIs for configuring VIM.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stddef.h>
#include <vim_test_interrupt.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/csl_vim.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** \brief Base address of VIM */
uint32_t    gTestVimBaseAddr;
void       *gTestArgArray[VIM_TEST_R5_VIM_INTR_NUM]       = {0};
vimTestIntrFuncPtr gTestFxnArray[VIM_TEST_R5_VIM_INTR_NUM]       = {0};
uint32_t    gTestIntrSrcType[VIM_TEST_R5_VIM_INTR_NUM]    = {(uint32_t)CSL_VIM_INTR_TYPE_LEVEL};
uint16_t    gTestIntrPri[VIM_TEST_R5_VIM_INTR_NUM]        = {0};
uint8_t     gTestIntrMap[VIM_TEST_R5_VIM_INTR_NUM]        = {0};
VIMTest_R5ExptnHandlers gTestExptnHandlers          = {NULL};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

__attribute__((interrupt("IRQ")))     void vimTest_masterIsr(void);
__attribute__((interrupt("UDEF")))   void vimTest_undefInstructionExptnHandler(void);
__attribute__((interrupt("SWI")))     void vimTest_swIntrExptnHandler(void);
__attribute__((interrupt("PABT")))   void vimTest_prefetchAbortExptnHandler(void);
__attribute__((interrupt("DABT")))   void vimTest_dataAbortExptnHandler(void);
__attribute__((interrupt("IRQ")))     void vimTest_irqExptnHandler(void);
__attribute__((interrupt("FIQ")))     void vimTest_fiqExptnHandler(void);

/**
 *  Below ifdef __cplusplus is added so that C++ build passes without
 *  typecasting. This is because the prototype is build as C type
 *  whereas this file is build as CPP file. Hence we get C++ build error.
 *  Also if typecasting is used, then we get MisraC error Rule 11.1.
 */
#ifdef __cplusplus
extern "C" {
#endif
static void vimTest_IntDefaultHandler(void *dummy);
#ifdef __cplusplus
}
#endif

static void vimTest_IntDefaultHandler(void *dummy)
{
    /* Go into an infinite loop.*/
    volatile uint32_t loop = 1U;
    while (1U == loop)
    {
        ;
    }
}

void vimTest_Intc_IntClrPend(uint16_t intrNum)
{
    CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, intrNum );
    CSL_vimAckIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
                    (CSL_VimIntrMap)gTestIntrMap[intrNum] );
}

void vimTest_Intc_Init(void)
{
    uint32_t loopCnt;
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        gTestVimBaseAddr = VIM_TEST_MCU_DOMAIN_VIM_BASE_ADDR;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        gTestVimBaseAddr = VIM_TEST_MAIN_DOMAIN_VIM_BASE_ADDR;
    }
    /* Initialize interrupt source type for each interrupt */
    for (loopCnt = 0U ; loopCnt < VIM_TEST_R5_VIM_INTR_NUM ; loopCnt++)
    {
        gTestIntrSrcType[loopCnt] = (uint32_t)CSL_VIM_INTR_TYPE_LEVEL;
        gTestIntrPri[loopCnt] = 0;
        gTestIntrMap[loopCnt] = 0;
    }

    /* initialize the default handlers */
    vimTest_Intc_InitExptnHandlers(&gTestExptnHandlers);
}

void vimTest_Intc_IntSetSrcType(uint16_t intrNum, uint32_t type)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        gTestIntrSrcType[intrNum] = type;
    }
}

void vimTest_Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority, \
                                 uint8_t hostIntRoute)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        gTestIntrPri[intrNum] = priority;
        gTestIntrMap[intrNum] = hostIntRoute;
    }
}

void vimTest_Intc_IntRegister(uint16_t intrNum, vimTestIntrFuncPtr fptr, void *fun_arg)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        gTestFxnArray[intrNum] = fptr;
        gTestArgArray[intrNum] = fun_arg;
        CSL_vimCfgIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, intrNum, \
                         gTestIntrPri[intrNum], \
                         (CSL_VimIntrMap)gTestIntrMap[intrNum], \
                         (CSL_VimIntrType)gTestIntrSrcType[intrNum],\
                         (uint32_t)&vimTest_masterIsr );
    }
}

void vimTest_Intc_IntUnregister(uint16_t intrNum)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        gTestFxnArray[intrNum] = &vimTest_IntDefaultHandler;
        gTestArgArray[intrNum] = NULL;
        CSL_vimCfgIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
                        intrNum, 0, CSL_VIM_INTR_MAP_IRQ, \
                        CSL_VIM_INTR_TYPE_PULSE, (uint32_t)&vimTest_masterIsr );
    }
}

void vimTest_Intc_IntEnable(uint16_t intrNum)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        CSL_vimSetIntrEnable( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
                              intrNum, true );    /* Enable interrupt in vim */
    }
}

void vimTest_Intc_IntDisable(uint16_t intrNum)
{
    if( intrNum < VIM_TEST_R5_VIM_INTR_NUM )
    {
        CSL_vimSetIntrEnable( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
                               intrNum, false );   /* Disable interrupt in vim */
    }
}


uintptr_t vimTest_Intc_SystemDisable(void)
{
    uintptr_t cookie;

    cookie = CSL_armR5GetCpsrRegVal();
    /* Disable IRQ and FIQ */
    CSL_armR5DisableIrqFiq();

    return cookie;
}

void vimTest_Intc_SystemRestore(uintptr_t cookie)
{
    CSL_armR5EnableIrqFiq(cookie);
}

void vimTest_Intc_SystemEnable(void)
{
    CSL_armR5IntrEnableFiq(1);  /* Enable FIQ interrupt in R5 */
    CSL_armR5IntrEnableIrq(1);  /* Enable IRQ interrupt in R5 */
}

void vimTest_masterIsr(void)
{
    vimTestIntrFuncPtr        fxnPtr;
    volatile uint32_t  intNum;

    /* Process a pending FIQ interrupt before a pending IRQ interrupt */
    if( ( CSL_vimGetActivePendingIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
          CSL_VIM_INTR_MAP_FIQ, (uint32_t *)&intNum, (uint32_t *)0 ) == 0 )  || \
        ( CSL_vimGetActivePendingIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
          CSL_VIM_INTR_MAP_IRQ, (uint32_t *)&intNum, (uint32_t *)0 ) == 0 ) )
    {
        /* Clear pulse-type interrupt before calling ISR */
        if( gTestIntrSrcType[intNum] == (uint32_t)CSL_VIM_INTR_TYPE_PULSE )
        {
            CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, intNum );
        }
        /* Call ISR */
        if( gTestFxnArray[intNum] != NULL )
        {
            fxnPtr = gTestFxnArray[intNum];
            fxnPtr(gTestArgArray[intNum]);
        }
        /* Clear level-type interrupt after calling ISR */
        if( gTestIntrSrcType[intNum] == (uint32_t)CSL_VIM_INTR_TYPE_LEVEL )
        {
            CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, intNum );
        }
        /* Acknowledge interrupt servicing */
        CSL_vimAckIntr( (CSL_vimRegs *)(uintptr_t)gTestVimBaseAddr, \
                        (CSL_VimIntrMap)gTestIntrMap[intNum] );
    }
}

void vimTest_Intc_InitExptnHandlers(VIMTest_R5ExptnHandlers *handlers)
{
    handlers->udefExptnHandler = NULL;
    handlers->swiExptnHandler = NULL;
    handlers->pabtExptnHandler = NULL;
    handlers->dabtExptnHandler = NULL;
    handlers->irqExptnHandler = NULL;
    handlers->fiqExptnHandler = NULL;
    handlers->udefExptnHandlerArgs = NULL;
    handlers->swiExptnHandlerArgs = NULL;
    handlers->pabtExptnHandlerArgs = NULL;
    handlers->dabtExptnHandlerArgs = NULL;
    handlers->irqExptnHandlerArgs = NULL;
    handlers->fiqExptnHandlerArgs = NULL;
}

void vimTest_Intc_RegisterExptnHandlers(const VIMTest_R5ExptnHandlers *handlers)
{
    /* Copying exception handlers */
    gTestExptnHandlers.udefExptnHandler = handlers->udefExptnHandler;
    gTestExptnHandlers.swiExptnHandler = handlers->swiExptnHandler;
    gTestExptnHandlers.pabtExptnHandler = handlers->pabtExptnHandler;
    gTestExptnHandlers.dabtExptnHandler = handlers->dabtExptnHandler;
    gTestExptnHandlers.irqExptnHandler = handlers->irqExptnHandler;
    gTestExptnHandlers.fiqExptnHandler = handlers->fiqExptnHandler;
    gTestExptnHandlers.udefExptnHandlerArgs = handlers->udefExptnHandlerArgs;
    gTestExptnHandlers.swiExptnHandlerArgs = handlers->swiExptnHandlerArgs;
    gTestExptnHandlers.pabtExptnHandlerArgs = handlers->pabtExptnHandlerArgs;
    gTestExptnHandlers.dabtExptnHandlerArgs = handlers->dabtExptnHandlerArgs;
    gTestExptnHandlers.irqExptnHandlerArgs = handlers->irqExptnHandlerArgs;
    gTestExptnHandlers.fiqExptnHandlerArgs = handlers->fiqExptnHandlerArgs;
}

void vimTest_undefInstructionExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.udefExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.udefExptnHandler(gTestExptnHandlers.udefExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

void vimTest_swIntrExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.swiExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.swiExptnHandler(gTestExptnHandlers.swiExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

void vimTest_prefetchAbortExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.pabtExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.pabtExptnHandler(gTestExptnHandlers.pabtExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

void vimTest_dataAbortExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.dabtExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.dabtExptnHandler(gTestExptnHandlers.dabtExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

void vimTest_irqExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.irqExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.irqExptnHandler(gTestExptnHandlers.irqExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

void vimTest_fiqExptnHandler(void)
{
    /* Call registered call back */
    if (gTestExptnHandlers.fiqExptnHandler != (vimTestExptnHandlerPtr)NULL)
    {
        gTestExptnHandlers.fiqExptnHandler(gTestExptnHandlers.fiqExptnHandlerArgs);
    }
    else
    {
        /* Go into an infinite loop.*/
        volatile uint32_t loop = 1U;
        while (1U == loop)
        {
            ;
        }
    }
}

/********************************* End of file ******************************/
