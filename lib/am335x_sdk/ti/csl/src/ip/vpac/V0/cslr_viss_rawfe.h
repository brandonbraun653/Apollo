/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_viss_rawfe.h
*/
#ifndef CSLR_VISS_RAWFE_H_
#define CSLR_VISS_RAWFE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_VISS_RAWFE_RAWFE_CFG_REGS_BASE                                     (0x00000000U)
#define CSL_VISS_RAWFE_RAWFE_DATA_IN_REGS_BASE                                 (0x00000000U)
#define CSL_VISS_RAWFE_RAWFE_DPC_LRAM_REGS_BASE                                (0x00004000U)
#define CSL_VISS_RAWFE_RAWFE_DPC_LUT_RAM_REGS_BASE                             (0x00003000U)
#define CSL_VISS_RAWFE_RAWFE_H3A_ARAM_REGS_BASE                                (0x00010000U)
#define CSL_VISS_RAWFE_RAWFE_H3A_CFG_REGS_BASE                                 (0x00000400U)
#define CSL_VISS_RAWFE_RAWFE_H3A_LRAM_REGS_BASE                                (0x00012000U)
#define CSL_VISS_RAWFE_RAWFE_H3A_LUT_RAM_REGS_BASE                             (0x00002800U)
#define CSL_VISS_RAWFE_RAWFE_LSC_LUT_RAM_REGS_BASE                             (0x00008000U)
#define CSL_VISS_RAWFE_RAWFE_PWL_LUT1_RAM_REGS_BASE                            (0x00001800U)
#define CSL_VISS_RAWFE_RAWFE_PWL_LUT2_RAM_REGS_BASE                            (0x00001000U)
#define CSL_VISS_RAWFE_RAWFE_PWL_LUT3_RAM_REGS_BASE                            (0x00000800U)
#define CSL_VISS_RAWFE_RAWFE_WDR_LUT_RAM_REGS_BASE                             (0x00002000U)


#ifdef __cplusplus
}
#endif
#endif
