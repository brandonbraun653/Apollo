/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
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
 *  ======== V0 implementation of CIC for Keystone devices ========
 */

#include <ti/osal/MuxIntcP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/src/nonos/Nonos_config.h>
#if !(defined(SOC_OMPAL137))
#include <ti/csl/csl_semAux.h>
#include <ti/csl/csl_cpIntcAux.h>
#include <ti/csl/csl_cpIntc.h>
#endif
/*
 *  ======== MuxIntcP_create ========
 */
MuxIntcP_Status MuxIntcP_create(MuxIntcP_inParams *inParams, MuxIntcP_outParams *outParams)
{
    CSL_CPINTC_Handle hnd;

    /* Map the CIC event to a Host interrupt on a CIC */
    hnd = CSL_CPINTC_open((uint32_t)inParams->muxNum);

    /* Disable all host interrupts. */
    CSL_CPINTC_disableAllHostInterrupt(hnd);

    /* Configure no nesting support in the CPINTC Module. */
    CSL_CPINTC_setNestingMode(hnd, CPINTC_NO_NESTING);

    /* Clear chip event interrupt */
    CSL_CPINTC_clearSysInterrupt(hnd, (uint32_t)inParams->muxInEvent);

    /* Enable chip event interrupt */
    CSL_CPINTC_enableSysInterrupt(hnd, (uint32_t)inParams->muxInEvent);
    CSL_CPINTC_mapSystemIntrToChannel (hnd, (uint32_t)inParams->muxInEvent, inParams->muxOutEvent);

    /* Enable host interrupt */
    CSL_CPINTC_enableHostInterrupt (hnd, (uint32_t)inParams->muxOutEvent);
    CSL_CPINTC_enableAllHostInterrupt(hnd);

    outParams->arg = inParams->arg;
    outParams->muxIntcFxn = inParams->muxIntcFxn;

    return MuxIntcP_OK;
}

/*
 *  ======== MuxIntcP_enableInEvent ========
 */
void MuxIntcP_enableInEvent(int32_t muxNum, int32_t muxInEvent)
{
    CSL_CPINTC_Handle hnd;

    hnd = CSL_CPINTC_open((uint32_t)muxNum);
    CSL_CPINTC_enableSysInterrupt(hnd, (uint32_t)muxInEvent);
}

/*
 *  ======== MuxIntcP_disableInEvent ========
 */
void MuxIntcP_disableInEvent(int32_t muxNum, int32_t muxInEvent)
{
    CSL_CPINTC_Handle hnd;

    hnd = CSL_CPINTC_open((uint32_t)muxNum);
    CSL_CPINTC_disableSysInterrupt(hnd, (uint32_t)muxInEvent);
}

/*
 *  ======== MuxIntcP_clearInEvent ========
 */
void MuxIntcP_clearInEvent(int32_t muxNum, int32_t muxInEvent)
{
    CSL_CPINTC_Handle hnd;

    hnd = CSL_CPINTC_open((uint32_t)muxNum);
    CSL_CPINTC_clearSysInterrupt(hnd, (uint32_t)muxInEvent);
}

/*
 *  ======== MuxIntcP_enableOutEvent ========
 */
void MuxIntcP_enableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
    CSL_CPINTC_Handle hnd;

    hnd = CSL_CPINTC_open((uint32_t)muxNum);
    CSL_CPINTC_enableHostInterrupt(hnd, (uint32_t)muxOutEvent);
}

/*
 *  ======== MuxIntcP_disableOutEvent ========
 */
void MuxIntcP_disableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
    CSL_CPINTC_Handle hnd;

    hnd = CSL_CPINTC_open((uint32_t)muxNum);
    CSL_CPINTC_disableHostInterrupt(hnd, (uint32_t)muxOutEvent);
}

