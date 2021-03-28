/*
 * Copyright (c) 2018 - 2019, Texas Instruments Incorporated
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
 *  ======== SwiP_tirtos.c ========
 */

#include <ti/osal/SwiP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/osal/src/tirtos/tirtos_config.h>


/*
 *  ======== SwiP_create ========
 */
SwiP_Handle SwiP_create(SwiP_Fxn swiFxn, const SwiP_Params *params)
{
    Error_Block eb;
    Swi_Params  swiParams;
    SwiP_Handle handle;

    Error_init(&eb);

    Swi_Params_init(&swiParams);
    swiParams.arg0 = (UArg)params->arg0;
    swiParams.arg1 = (UArg)params->arg1;

    handle = (SwiP_Handle)Swi_create(swiFxn, &swiParams, &eb);

    return (handle);
}

/*
 *  ======== SwiP_delete ========
 */
SwiP_Status SwiP_delete(SwiP_Handle *pHandle)
{
    SwiP_Status status;

    if (pHandle != NULL_PTR)
    {
        Swi_delete((Swi_Handle *)pHandle);
        status = SwiP_OK;
    }
    else
    {
        status = SwiP_FAILURE;
    }

    return (status);
}

/*
 *  ======== SwiP_Params_init ========
 */
void SwiP_Params_init(SwiP_Params *params)
{
    params->arg0 = (uintptr_t)0U;
    params->arg1 = (uintptr_t)0U;
}

/*
 *  ======== SwiP_postInterrupt ========
 */

SwiP_Status SwiP_post(SwiP_Handle handle)
{
    SwiP_Status status;

    if (handle != NULL_PTR)
    {
        Swi_post((Swi_Handle)handle);
        status = SwiP_OK;
    }
    else
    {
        status = SwiP_FAILURE;
    }
    
    return (status);
}

