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
#ifndef CSLR_CPPIDMA_RX_CHANNEL_CONFIG_H_
#define CSLR_CPPIDMA_RX_CHANNEL_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for RX_CHANNEL_GLOBAL_CONFIG
**************************************************************************/
typedef struct {
    volatile Uint32 RX_CHANNEL_GLOBAL_CONFIG_REG;
    volatile Uint8  RSVD0[28];
} CSL_Cppidma_rx_channel_configRx_channel_global_configRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_Cppidma_rx_channel_configRx_channel_global_configRegs	RX_CHANNEL_GLOBAL_CONFIG[129];
} CSL_Cppidma_rx_channel_configRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* RX_CHANNEL_GLOBAL_CONFIG_REG */
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG(n)  (0x0U + ((n) * (0x20U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* RX_CHANNEL_GLOBAL_CONFIG_REG */

#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_PAUSE_MASK  (0x20000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_PAUSE_SHIFT  (29U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_PAUSE_RESETVAL  (0x00000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_PAUSE_MAX  (0x00000001U)

#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_TEARDOWN_MASK  (0x40000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_TEARDOWN_SHIFT  (30U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_TEARDOWN_RESETVAL  (0x00000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_TEARDOWN_MAX  (0x00000001U)

#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_ENABLE_MASK  (0x80000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_ENABLE_SHIFT  (31U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RX_ENABLE_MAX  (0x00000001U)

#define CSL_CPPIDMA_RX_CHANNEL_CONFIG_RX_CHANNEL_GLOBAL_CONFIG_REG_RESETVAL  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
