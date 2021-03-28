/**
 *   @file  ecc_emif4_aliases.h
 *
 *   @brief   
 *      This is the main header file for the EMIF4F Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2019, Texas Instruments, Inc.
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

/** @defgroup CSL_EMIF4F_API EMIF4F
 *
 * @section Introduction
 *  The External Memory Interface (EMIF) is a TI developed re-usable IP component 
 *  targeted for SOC designs. The EMIF is a VBUSM slave peripheral providing an 
 *  interface to a wide variety of DDR SDRAM. This memory controller is a soft 
 *  macro and must be used with the DDR PHY hard macros to interface to the 
 *  DDR SDRAM. 
 *
 * @subsection References
 *   -# EMIF4F Functional Specification
 */

#ifndef CSL_EMIF4F_ALIASES_H
#define CSL_EMIF4F_ALIASES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr_emif4f.h>

#define EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_ONEBIT_ECC_ERR_SYS_MASK                  CSL_EMIF4FV_IRQENABLE_SET_SYS_REG_EN_1B_ECC_ERR_SYS_MASK
#define EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_TWOBIT_ECC_ERR_SYS_MASK                  CSL_EMIF4FV_IRQENABLE_SET_SYS_REG_EN_2B_ECC_ERR_SYS_MASK
#define EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_WR_ECC_ERR_SYS_MASK                      CSL_EMIF4FV_IRQENABLE_SET_SYS_REG_EN_WR_ECC_ERR_SYS_MASK
#define EMIF_SYSTEM_OCP_INTERRUPT_STATUS_TWOBIT_ECC_ERR_SYS_MASK                      CSL_EMIF4FV_IRQSTATUS_SYS_REG_2B_ECC_ERR_SYS_MASK
#define EMIF_SYSTEM_OCP_INTERRUPT_STATUS_WR_ECC_ERR_SYS_MASK                          CSL_EMIF4FV_IRQSTATUS_SYS_REG_WR_ECC_ERR_SYS_MASK



#ifdef __cplusplus
}
#endif
#endif /* CSL_EMIF4F_ALIASES_H */
