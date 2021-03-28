/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *  ======== V1 implementation of Crossbar mux for AM devices ========
 */

#include <ti/osal/MuxIntcP.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/src/tirtos/tirtos_config.h>

#include <xdc/std.h>
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined(SOC_TDA2XX) || defined(SOC_TDA2PX) || defined(SOC_TDA2EX) || defined(SOC_TDA3XX) || defined(SOC_DRA72x) || defined(SOC_DRA78x) || defined(SOC_DRA75x)
#include <ti/sysbios/family/shared/vayu/IntXbar.h>
#endif

/*
 *  ======== MuxIntcP_create ========
 */
MuxIntcP_Status MuxIntcP_create(MuxIntcP_inParams *inParams, MuxIntcP_outParams *outParams)
{


   if(inParams->muxNum!=MUXINTCP_CROSSBAR_MUXNUM_INVALID)
   {
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined(SOC_TDA2XX) || defined(SOC_TDA2PX) || defined(SOC_TDA2EX) || defined(SOC_TDA3XX) || defined(SOC_DRA72x) || defined(SOC_DRA78x) || defined(SOC_DRA75x)
     /* The muxInEvent is the crossbar instance number, and out event is the event which goes to the CPU */
     IntXbar_connect(inParams->muxOutEvent, inParams->muxInEvent);
#endif
     outParams->arg = inParams->arg;
     outParams->muxIntcFxn = inParams->muxIntcFxn;
   }
   return MuxIntcP_OK;
}

/*
 *  ======== MuxIntcP_enableInEvent ========
 */
void MuxIntcP_enableInEvent(int32_t muxNum, int32_t muxInEvent)
{
}

/*
 *  ======== MuxIntcP_disableInEvent ========
 */
void MuxIntcP_disableInEvent(int32_t muxNum, int32_t muxInEvent)
{
}

/*
 *  ======== MuxIntcP_clearInEvent ========
 */
void MuxIntcP_clearInEvent(int32_t muxNum, int32_t muxInEvent)
{
}

/*
 *  ======== MuxIntcP_enableOutEvent ========
 */
void MuxIntcP_enableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
}

/*
 *  ======== MuxIntcP_enableOutEvent ========
 */
void MuxIntcP_disableOutEvent(int32_t muxNum, int32_t muxOutEvent)
{
}
