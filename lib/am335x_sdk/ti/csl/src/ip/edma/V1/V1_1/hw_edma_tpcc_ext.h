/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2020
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


/**
*
*  \file     hw_edma_tpcc_ext.h
*
*  \brief    register-level header file for EDMA_TPCC
*
**/

#ifndef HW_EDMA_TPCC_EXT_H_
#define HW_EDMA_TPCC_EXT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <ti/csl/src/ip/edma/V1/hw_edma_tpcc.h>

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

/* For BINDEX extension from 16-bit to 24-bit */
#define EDMA_TPCC_CCNT_SRCEBIDX_SHIFT                                                                     (16U)
#define EDMA_TPCC_CCNT_SRCEBIDX_MASK                                                                      (0x00ff0000U)
#define EDMA_TPCC_CCNT_DSTEBIDX_SHIFT                                                                     (24U)
#define EDMA_TPCC_CCNT_DSTEBIDX_MASK                                                                      (0xff000000U)

#ifdef __cplusplus
}
#endif
#endif  /* _HW_EDMA_TPCC_EXT_H_ */
