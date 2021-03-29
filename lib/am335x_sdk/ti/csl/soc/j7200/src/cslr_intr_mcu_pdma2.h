/********************************************************************
*
* MCU_PDMA2 INTERRUPT MAP. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_MCU_PDMA2_INTERRUPT_MAP_H_
#define CSLR_MCU_PDMA2_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: MCU_PDMA2
*/

#define CSLR_MCU_PDMA2_MCANSS_MCU_1_FE_MCU_MCAN1_MCANSS_FE_0                                       (0U)
#define CSLR_MCU_PDMA2_MCANSS_MCU_1_TX_MCU_MCAN1_MCANSS_TX_DMA_0                                   (0U)
#define CSLR_MCU_PDMA2_USART_MCU_0_RX_MCU_UART0_USART_DMA_1                                        (0U)
#define CSLR_MCU_PDMA2_USART_MCU_0_TX_MCU_UART0_USART_DMA_0                                        (0U)
#define CSLR_MCU_PDMA2_MCANSS_MCU_1_FE_MCU_MCAN1_MCANSS_FE_1                                       (1U)
#define CSLR_MCU_PDMA2_MCANSS_MCU_1_TX_MCU_MCAN1_MCANSS_TX_DMA_1                                   (1U)
#define CSLR_MCU_PDMA2_MCANSS_MCU_1_FE_MCU_MCAN1_MCANSS_FE_2                                       (2U)
#define CSLR_MCU_PDMA2_MCANSS_MCU_1_TX_MCU_MCAN1_MCANSS_TX_DMA_2                                   (2U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_MCU_PDMA2_INTERRUPT_MAP_H_ */
