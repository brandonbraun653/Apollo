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
#ifndef CSLR_MSGMGRPROXYGLOBAL_H_
#define CSLR_MSGMGRPROXYGLOBAL_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[32];
    volatile Uint32 INTR_RAW_STATUS_SET_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 INTR_ENABLED_STATUS_SET_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 INTR_ENABLE_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 INTR_CLEAR_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 EOI_REG;
    volatile Uint8  RSVD5[12];
    volatile Uint32 PROXY_ERROR_STATUS_REG;
} CSL_MsgmgrProxyGlobalRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* The Interrupt Raw Status/Set register shows the raw interrupt status before
 * enabling and allows for setting of the interrupt status. Each bit
 * corresponds to a permission error associated with a given proxy. */
#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG           (0x20U)

/* The Interrupt Enabled Status/Set register shows the interrupt enabled
 * status and allows clearing the interrupt status. Each bit corresponds to an
 * error associated with the proxy. */
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG       (0x28U)

/* The Interrupt Enable register allows setting the interrupt enable. Each bit
 * corresponds to a proxy. */
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG                   (0x30U)

/* The Interrupt Clear register allows clearing the interrupt enable. Each bit
 * corresponds to a proxy. */
#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG                    (0x38U)

/* The EOI register is used by software to write a vector associated with each
 * interrupt to indicate that the interrupt has been serviced. */
#define CSL_MSGMGRPROXYGLOBAL_EOI_REG                           (0x40U)

/* The Proxy Error Status register holds the proxy number and queue number for
 * the first transfer that resulted in a proxy error. */
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG            (0x50U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* INTR_RAW_STATUS_SET_REG */

#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG_PROXY_SHIFT  (0U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG_PROXY_RESETVAL  (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG_PROXY_MAX  (0xffffffffU)

#define CSL_MSGMGRPROXYGLOBAL_INTR_RAW_STATUS_SET_REG_RESETVAL  (0x00000000U)

/* INTR_ENABLED_STATUS_SET_REG */

#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG_PROXY_SHIFT  (0U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG_PROXY_RESETVAL  (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG_PROXY_MAX  (0xffffffffU)

#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLED_STATUS_SET_REG_RESETVAL  (0x00000000U)

/* INTR_ENABLE_REG */

#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG_PROXY_MASK        (0xFFFFFFFFU)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG_PROXY_SHIFT       (0U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG_PROXY_RESETVAL    (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG_PROXY_MAX         (0xffffffffU)

#define CSL_MSGMGRPROXYGLOBAL_INTR_ENABLE_REG_RESETVAL          (0x00000000U)

/* INTR_CLEAR_REG */

#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG_PROXY_MASK         (0xFFFFFFFFU)
#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG_PROXY_SHIFT        (0U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG_PROXY_RESETVAL     (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG_PROXY_MAX          (0xffffffffU)

#define CSL_MSGMGRPROXYGLOBAL_INTR_CLEAR_REG_RESETVAL           (0x00000000U)

/* EOI_REG */

#define CSL_MSGMGRPROXYGLOBAL_EOI_REG_VECTOR_MASK               (0x000000FFU)
#define CSL_MSGMGRPROXYGLOBAL_EOI_REG_VECTOR_SHIFT              (0U)
#define CSL_MSGMGRPROXYGLOBAL_EOI_REG_VECTOR_RESETVAL           (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_EOI_REG_VECTOR_MAX                (0x000000ffU)

#define CSL_MSGMGRPROXYGLOBAL_EOI_REG_RESETVAL                  (0x00000000U)

/* PROXY_ERROR_STATUS_REG */

#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_PROXY_NUM_MASK  (0xFF000000U)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_PROXY_NUM_SHIFT  (24U)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_PROXY_NUM_RESETVAL  (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_PROXY_NUM_MAX  (0x000000ffU)

#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_QUEUE_NUM_MASK  (0x00FFFFFFU)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_QUEUE_NUM_SHIFT  (0U)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_QUEUE_NUM_RESETVAL  (0x00000000U)
#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_QUEUE_NUM_MAX  (0x00ffffffU)

#define CSL_MSGMGRPROXYGLOBAL_PROXY_ERROR_STATUS_REG_RESETVAL   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
