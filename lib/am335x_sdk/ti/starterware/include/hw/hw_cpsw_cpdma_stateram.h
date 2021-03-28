/*
* hw_cpsw_cpdma_stateram.h
*
* Register-level header file for CPDMA_STATERAM
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
*
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

#ifndef HW_CPSW_CPDMA_STATERAM_H_
#define HW_CPSW_CPDMA_STATERAM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_CPDMA_STATERAM_TX_CP(n)                                (0x40U + ((n) * 0x4U))
#define CPSW_CPDMA_STATERAM_TX_HDP(n)                               (0x0U + ((n) * 0x4U))
#define CPSW_CPDMA_STATERAM_RX_CP(n)                                (0x60U + ((n) * 0x4U))
#define CPSW_CPDMA_STATERAM_RX_HDP(n)                               (0x20U + ((n) * 0x4U))

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_CPDMA_STATERAM_TX_CP_TX_SHIFT                                              (0U)
#define CPSW_CPDMA_STATERAM_TX_CP_TX_MASK                                               (0xffffffffU)

#define CPSW_CPDMA_STATERAM_TX_HDP_TX_SHIFT                                             (0U)
#define CPSW_CPDMA_STATERAM_TX_HDP_TX_MASK                                              (0xffffffffU)

#define CPSW_CPDMA_STATERAM_RX_CP_RX_SHIFT                                              (0U)
#define CPSW_CPDMA_STATERAM_RX_CP_RX_MASK                                               (0xffffffffU)

#define CPSW_CPDMA_STATERAM_RX_HDP_RX_SHIFT                                             (0U)
#define CPSW_CPDMA_STATERAM_RX_HDP_RX_MASK                                              (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_CPDMA_STATERAM_H_ */
