/*
 * Copyright (c) 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== TaskP_tirtos.c ========
 */
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include "TaskP.h"
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/osal/src/tirtos/tirtos_config.h>
/*
 *  ======== TaskP_create ========
 */
TaskP_Handle TaskP_create(void *taskfxn, const TaskP_Params *params)
{
    Task_Handle taskHandle;
    Task_Params taskParams;
    Error_Block       *pErrBlk = (Error_Block *) NULL_PTR;

    Task_Params_init(&taskParams);

    if(params != NULL_PTR)
    {
        taskParams.stackSize = params->stacksize;
        taskParams.priority = params->priority;
        taskParams.arg0 = (UArg)(params->arg0);
        taskParams.arg1 = (UArg)(params->arg1);
        taskParams.instance->name = (char *)(params->name);
        if(params->stack!=NULL_PTR)
        {
            taskParams.stack = params->stack;
        }
        pErrBlk = (Error_Block *) params->pErrBlk;
    }

    if (pErrBlk !=  NULL_PTR)
    {
        Error_init(pErrBlk);
    }

    taskHandle = Task_create((Task_FuncPtr)taskfxn, &taskParams, pErrBlk);

    return ((TaskP_Handle)taskHandle);
}

/*
 *  ======== TaskP_delete ========
 */
TaskP_Status TaskP_delete(TaskP_Handle *handle)
{
    Task_delete((Task_Handle *)handle);
    return TaskP_OK;
}

/*
 *  ======== TaskP_Params_init ========
 */
void TaskP_Params_init(TaskP_Params *params)
{
    Task_Params taskParams;
    Task_Params_init(&taskParams);
    params->priority = (int8_t)taskParams.priority;
    params->stacksize = (uint32_t)taskParams.stackSize;
    params->arg0 = (void *)(taskParams.arg0);
    params->arg1 = (void *)(taskParams.arg1);
    params->name = (uint8_t *)(taskParams.instance->name);
    params->stack = NULL_PTR;
    params->pErrBlk = NULL_PTR;
}

void TaskP_sleep(uint32_t timeout)
{
    Task_sleep(timeout);
}

void TaskP_sleepInMsecs(uint32_t timeoutInMsecs)
{
    uint32_t ticks;

    /* Clock_tickPeriod is in units of usecs */
    ticks = (uint32_t)((uint64_t)timeoutInMsecs * 1000U) / Clock_tickPeriod;

    TaskP_sleep(ticks);
}

void TaskP_setPrio(TaskP_Handle handle, uint32_t priority)
{
    (void)Task_setPri((Task_Handle)handle, (int16_t)priority);
}

TaskP_Handle TaskP_self(void)
{
    return ((TaskP_Handle)Task_self());
}

TaskP_Handle TaskP_selfmacro(void)
{
    return ((TaskP_Handle)Task_selfMacro());
}

void TaskP_yield(void) {
    Task_yield();
}

uint32_t TaskP_isTerminated(TaskP_Handle handle)
{
    uint32_t isTaskTerminated = 0;

    if(Task_getMode((Task_Handle)handle)!=Task_Mode_TERMINATED)
    {
        isTaskTerminated = 0;
    }
    else
    {
        isTaskTerminated = 1;
    }
    return isTaskTerminated;
}

/* Nothing past this point */
