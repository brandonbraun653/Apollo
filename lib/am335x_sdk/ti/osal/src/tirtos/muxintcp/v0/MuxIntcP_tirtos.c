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

#include <ti/osal/src/tirtos/tirtos_config.h>

#include <xdc/std.h>
#if defined (_TMS320C6X)
#include <ti/sysbios/family/c66/tci66xx/CpIntc.h>
#else
#include <ti/sysbios/family/arm/a15/tci66xx/CpIntc.h>
#endif

/*
 *  ======== MuxIntcP_create ========
 */
MuxIntcP_Status MuxIntcP_create(MuxIntcP_inParams *inParams, MuxIntcP_outParams *outParams)
{
    /* Map the CIC event to a Host interrupt on a CIC, the CIC  event is a device
       specific system event input to the CIC, the Host interrupt is a CorePac
       specific interrupt output from the CIC */
#if defined (_TMS320C6X)
    CpIntc_mapSysIntToHostInt((uint32_t)inParams->muxNum,
                              (uint32_t)inParams->muxInEvent,
                              (uint32_t)inParams->muxOutEvent);
    CpIntc_enableHostInt((uint32_t)inParams->muxNum,
                         (uint32_t)inParams->muxOutEvent);
#else
    CpIntc_mapSysIntToHostInt((uint32_t)inParams->muxInEvent,
                              (uint32_t)inParams->muxOutEvent);
    CpIntc_enableHostInt((uint32_t)inParams->muxOutEvent);
#endif
    CpIntc_dispatchPlug((uint32_t)inParams->muxInEvent,
                        (CpIntc_FuncPtr)inParams->muxIntcFxn, (UArg)inParams->arg, TRUE);

    /* Map the Host interrup to the CorePac specific primary Event ID (128 events) */
#if defined (_TMS320C6X)
    outParams->eventId = CpIntc_getEventId(inParams->muxOutEvent);
#else
    outParams->eventId = 0; /* Event ID not used in GIC */
#endif
    outParams->muxIntcFxn = (MuxIntcFxn)CpIntc_dispatch;
    outParams->arg = (uintptr_t)inParams->muxOutEvent;

    return MuxIntcP_OK;
}

/*
 *  ======== MuxIntcP_enableInEvent ========
 */
void MuxIntcP_enableInEvent(int32_t muxNum, int32_t muxInEvent)
{
#if defined (_TMS320C6X)
    CpIntc_enableSysInt((uint32_t)muxNum, (uint32_t)muxInEvent);
#else
    CpIntc_enableSysInt((uint32_t)muxInEvent);
#endif
}

/*
 *  ======== MuxIntcP_disableInEvent ========
 */
void MuxIntcP_disableInEvent(int32_t muxNum, int32_t muxInEvent)
{
#if defined (_TMS320C6X)
    CpIntc_disableSysInt((uint32_t)muxNum, (uint32_t)muxInEvent);
#else
    CpIntc_disableSysInt((uint32_t)muxInEvent);
#endif
}

/*
 *  ======== MuxIntcP_clearInEvent ========
 */
void MuxIntcP_clearInEvent(int32_t muxNum, int32_t muxInEvent)
{
#if defined (_TMS320C6X)
    CpIntc_clearSysInt((uint32_t)muxNum, (uint32_t)muxInEvent);
#else
    CpIntc_clearSysInt((uint32_t)muxInEvent);
#endif
}

/*
 *  ======== MuxIntcP_enableOutEvent ========
 */
void MuxIntcP_enableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
#if defined (_TMS320C6X)
    CpIntc_enableHostInt((uint32_t)muxNum, (uint32_t)muxOutEvent);
#else
    CpIntc_enableHostInt((uint32_t)muxOutEvent);
#endif
}

/*
 *  ======== MuxIntcP_enableOutEvent ========
 */
void MuxIntcP_disableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
#if defined (_TMS320C6X)
    CpIntc_disableHostInt((uint32_t)muxNum, (uint32_t)muxOutEvent);
#else
    CpIntc_disableHostInt((uint32_t)muxOutEvent);
#endif
}

