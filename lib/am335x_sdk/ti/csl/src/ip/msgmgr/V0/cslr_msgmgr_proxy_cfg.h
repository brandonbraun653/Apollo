/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_MSGMGRPROXY_H_
#define CSLR_MSGMGRPROXY_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for PROXY_CONFIG
**************************************************************************/
typedef struct {
    volatile Uint32 REG[1024];
    volatile Uint8  RSVD0[4092];
} CSL_MsgmgrproxyProxy_configRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_MsgmgrproxyProxy_configRegs	PROXY_CONFIG[32];
} CSL_MsgmgrProxyRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register holds the permissions for queue R. Disabling both the write 
 * and read permissions will disable the queue access for this proxy. 
 * Optionally, this register will also hold the physical queue translation for 
 * virtual queue R. */
#define CSL_MSGMGRPROXY_REG(n,i)                                (0x0U + ((n) * (0x1000U)) + (i * (0x4U))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REG */

#define CSL_MSGMGRPROXY_REG_R_MASK                              (0x02000000U)
#define CSL_MSGMGRPROXY_REG_R_SHIFT                             (25U)
#define CSL_MSGMGRPROXY_REG_R_RESETVAL                          (0x00000000U)
#define CSL_MSGMGRPROXY_REG_R_MAX                               (0x00000001U)

#define CSL_MSGMGRPROXY_REG_W_MASK                              (0x01000000U)
#define CSL_MSGMGRPROXY_REG_W_SHIFT                             (24U)
#define CSL_MSGMGRPROXY_REG_W_RESETVAL                          (0x00000000U)
#define CSL_MSGMGRPROXY_REG_W_MAX                               (0x00000001U)

#define CSL_MSGMGRPROXY_REG_PHYSICAL_QNUM_MASK                  (0x00FFFFFFU)
#define CSL_MSGMGRPROXY_REG_PHYSICAL_QNUM_SHIFT                 (0U)
#define CSL_MSGMGRPROXY_REG_PHYSICAL_QNUM_RESETVAL              (0x00000000U)
#define CSL_MSGMGRPROXY_REG_PHYSICAL_QNUM_MAX                   (0x00ffffffU)

#define CSL_MSGMGRPROXY_REG_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
