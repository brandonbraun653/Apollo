/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <interrupt.h>
#include <csl_arm_r5.h>
#include <csl_vim.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** \brief Base address of VIM */
uint32_t gVimBaseAddr;
void       *argArray[R5_VIM_INTR_NUM]       = {0};
IntrFuncPtr fxnArray[R5_VIM_INTR_NUM]       = {0};
uint32_t    intrSrcType[R5_VIM_INTR_NUM]    = {(uint32_t)CSL_VIM_INTR_TYPE_LEVEL};
uint16_t    intrPri[R5_VIM_INTR_NUM]        = {0};
uint8_t     intrMap[R5_VIM_INTR_NUM]        = {0};
CSL_R5ExptnHandlers gExptnHandlers          = {NULL};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

__attribute__((interrupt("IRQ")))     void masterIsr(void);
__attribute__((interrupt("UDEF")))   void undefInstructionExptnHandler(void);
__attribute__((interrupt("SWI")))     void swIntrExptnHandler(void);
__attribute__((interrupt("PABT")))   void prefetchAbortExptnHandler(void);
__attribute__((interrupt("DABT")))   void dataAbortExptnHandler(void);
__attribute__((interrupt("IRQ")))     void irqExptnHandler(void);
__attribute__((interrupt("FIQ")))     void fiqExptnHandler(void);

/**
 *  Below ifdef __cplusplus is added so that C++ build passes without
 *  typecasting. This is because the prototype is build as C type
 *  whereas this file is build as CPP file. Hence we get C++ build error.
 *  Also if typecasting is used, then we get MisraC error Rule 11.1.
 */
#ifdef __cplusplus
extern "C" {
#endif
static void IntDefaultHandler(void *dummy);
#ifdef __cplusplus
}
#endif

static void IntDefaultHandler(void *dummy)
{
    /* Go into an infinite loop.*/
    volatile uint32_t loop = 1U;
    while (1U == loop)
    {
        ;
    }
}

void Intc_IntClrPend(uint16_t intrNum)
{
    CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intrNum );
    CSL_vimAckIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, (CSL_VimIntrMap)intrMap[intrNum] );
}

void Intc_Init(void)
{
    uint32_t loopCnt;
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        gVimBaseAddr = (info.cpuID == CSL_ARM_R5_CPU_ID_0)?
                                      CSL_MCU_DOMAIN_VIM_BASE_ADDR0:
                                      CSL_MCU_DOMAIN_VIM_BASE_ADDR1;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        gVimBaseAddr = (info.cpuID == CSL_ARM_R5_CPU_ID_0)?
                                      CSL_MAIN_DOMAIN_VIM_BASE_ADDR0:
                                      CSL_MAIN_DOMAIN_VIM_BASE_ADDR1;
    }
    /* Initialize interrupt source type for each interrupt */
    for (loopCnt = 0U ; loopCnt < R5_VIM_INTR_NUM ; loopCnt++)
    {
        intrSrcType[loopCnt] = (uint32_t)CSL_VIM_INTR_TYPE_LEVEL;
        intrPri[loopCnt] = 0;
        intrMap[loopCnt] = 0;
    }
}

void Intc_IntSetSrcType(uint16_t intrNum, uint32_t type)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        intrSrcType[intrNum] = type;
    }
}

void Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority, uint8_t hostIntRoute)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        intrPri[intrNum] = priority;
        intrMap[intrNum] = hostIntRoute;
    }
}

void Intc_IntRegister(uint16_t intrNum, IntrFuncPtr fptr, void *fun_arg)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        fxnArray[intrNum] = fptr;
        argArray[intrNum] = fun_arg;
        CSL_vimCfgIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intrNum, intrPri[intrNum], (CSL_VimIntrMap)intrMap[intrNum], (CSL_VimIntrType)intrSrcType[intrNum], (uint32_t)&masterIsr );
    }
}

void Intc_IntUnregister(uint16_t intrNum)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        fxnArray[intrNum] = &IntDefaultHandler;
        argArray[intrNum] = NULL;
        CSL_vimCfgIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intrNum, 0, CSL_VIM_INTR_MAP_IRQ, CSL_VIM_INTR_TYPE_PULSE, (uint32_t)&masterIsr );
    }
}

void Intc_IntEnable(uint16_t intrNum)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        CSL_vimSetIntrEnable( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intrNum, true );    /* Enable interrupt in vim */
    }
}

void Intc_IntDisable(uint16_t intrNum)
{
    if( intrNum < R5_VIM_INTR_NUM )
    {
        CSL_vimSetIntrEnable( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intrNum, false );   /* Disable interrupt in vim */
    }
}


uintptr_t Intc_SystemDisable(void)
{
    uintptr_t cookie;

    cookie = CSL_armR5GetCpsrRegVal();
    /* Disable IRQ and FIQ */
    CSL_armR5DisableIrqFiq();

    return cookie;
}

void Intc_SystemRestore(uintptr_t cookie)
{
    CSL_armR5EnableIrqFiq(cookie);
}

void Intc_SystemEnable(void)
{
    CSL_armR5IntrEnableFiq(1);  /* Enable FIQ interrupt in R5 */
    CSL_armR5IntrEnableIrq(1);  /* Enable IRQ interrupt in R5 */
}

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (masterIsr,32)
#endif  /* #ifdef __cplusplus */
void masterIsr(void)
{
    IntrFuncPtr        fxnPtr;
    volatile uint32_t  intNum;

    /* Process a pending FIQ interrupt before a pending IRQ interrupt */
    if( ( CSL_vimGetActivePendingIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, CSL_VIM_INTR_MAP_FIQ, (uint32_t *)&intNum, (uint32_t *)0 ) == 0 )       ||
        ( CSL_vimGetActivePendingIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, CSL_VIM_INTR_MAP_IRQ, (uint32_t *)&intNum, (uint32_t *)0 ) == 0 ) )
    {
        /* Clear pulse-type interrupt before calling ISR */
        if( intrSrcType[intNum] == (uint32_t)CSL_VIM_INTR_TYPE_PULSE )
        {
            CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intNum );
        }
        /* Call ISR */
        if( fxnArray[intNum] != NULL )
        {
            fxnPtr = fxnArray[intNum];
            fxnPtr(argArray[intNum]);
        }
        /* Clear level-type interrupt after calling ISR */
        if( intrSrcType[intNum] == (uint32_t)CSL_VIM_INTR_TYPE_LEVEL )
        {
            CSL_vimClrIntrPending( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, intNum );
        }
        /* Acknowledge interrupt servicing */
        CSL_vimAckIntr( (CSL_vimRegs *)(uintptr_t)gVimBaseAddr, (CSL_VimIntrMap)intrMap[intNum] );
    }
}

void Intc_InitExptnHandlers(CSL_R5ExptnHandlers *handlers)
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

void Intc_RegisterExptnHandlers(const CSL_R5ExptnHandlers *handlers)
{
    /* Copying exception handlers */
    gExptnHandlers.udefExptnHandler = handlers->udefExptnHandler;
    gExptnHandlers.swiExptnHandler = handlers->swiExptnHandler;
    gExptnHandlers.pabtExptnHandler = handlers->pabtExptnHandler;
    gExptnHandlers.dabtExptnHandler = handlers->dabtExptnHandler;
    gExptnHandlers.irqExptnHandler = handlers->irqExptnHandler;
    gExptnHandlers.fiqExptnHandler = handlers->fiqExptnHandler;
    gExptnHandlers.udefExptnHandlerArgs = handlers->udefExptnHandlerArgs;
    gExptnHandlers.swiExptnHandlerArgs = handlers->swiExptnHandlerArgs;
    gExptnHandlers.pabtExptnHandlerArgs = handlers->pabtExptnHandlerArgs;
    gExptnHandlers.dabtExptnHandlerArgs = handlers->dabtExptnHandlerArgs;
    gExptnHandlers.irqExptnHandlerArgs = handlers->irqExptnHandlerArgs;
    gExptnHandlers.fiqExptnHandlerArgs = handlers->fiqExptnHandlerArgs;
}

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (undefInstructionExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void undefInstructionExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.udefExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.udefExptnHandler(gExptnHandlers.udefExptnHandlerArgs);
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

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (swIntrExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void swIntrExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.swiExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.swiExptnHandler(gExptnHandlers.swiExptnHandlerArgs);
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

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (prefetchAbortExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void prefetchAbortExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.pabtExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.pabtExptnHandler(gExptnHandlers.pabtExptnHandlerArgs);
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

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (dataAbortExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void dataAbortExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.dabtExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.dabtExptnHandler(gExptnHandlers.dabtExptnHandlerArgs);
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

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (irqExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void irqExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.irqExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.irqExptnHandler(gExptnHandlers.irqExptnHandlerArgs);
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

#ifdef __cplusplus
#pragma CODE_STATE (32)
#else
#pragma CODE_STATE (fiqExptnHandler,32)
#endif  /* #ifdef __cplusplus */
void fiqExptnHandler(void)
{
    /* Call registered call back */
    if (gExptnHandlers.fiqExptnHandler != (exptnHandlerPtr)NULL)
    {
        gExptnHandlers.fiqExptnHandler(gExptnHandlers.fiqExptnHandlerArgs);
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
