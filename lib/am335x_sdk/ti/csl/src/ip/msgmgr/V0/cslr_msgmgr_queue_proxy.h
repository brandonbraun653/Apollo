/********************************************************************
 * Copyright (C) 2013-2017 Texas Instruments Incorporated.
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
#ifndef CSLR_MSGMGRQUEUEPROXY_H_
#define CSLR_MSGMGRQUEUEPROXY_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for QUEUE
**************************************************************************/
typedef struct {
    volatile Uint32 REG[32];
    volatile Uint8  RSVD0[124];
} CSL_MsgmgrqueueproxyQueueRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_MsgmgrqueueproxyQueueRegs	QUEUE[64];
} CSL_MsgmgrQueueProxyRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register holds the contents for Queue Register R. */
#define CSL_MSGMGRQUEUEPROXY_REG(p,q,i)    (0x0U + ((p) * (0x10000U)) + \
                                                   ((q) * (0x80U)) + \
                                                   ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REG */

#define CSL_MSGMGRQUEUEPROXY_REG_DATA_MASK                      (0xFFFFFFFFU)
#define CSL_MSGMGRQUEUEPROXY_REG_DATA_SHIFT                     (0U)
#define CSL_MSGMGRQUEUEPROXY_REG_DATA_RESETVAL                  (0x00000000U)
#define CSL_MSGMGRQUEUEPROXY_REG_DATA_MAX                       (0xffffffffU)

#define CSL_MSGMGRQUEUEPROXY_REG_RESETVAL                       (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
