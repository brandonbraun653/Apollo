/********************************************************************
 * Copyright (C) 2003-2011 Texas Instruments Incorporated.
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
 *  @file   csl_tac2_regs.h
 *
 *  @brief  This file contains the macros and the register overlay variable
 *          declarations.
 *
 *  @date   29-Sep-2011
 *  @author Vijay Pothukuchi
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par 
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  03-Feb-2009   RD    Added support for Tac2 Model
 *  09-Jan-2009   VP    File Created
 * =============================================================================
 */

/**
@defgroup CSL_TAC2_REGS TAC2 Register Datastructure Overlay Declarations
*/

/**
@defgroup CSL_TAC_BE_SYMBOL TAC CSL MACROS
@ingroup CSL_TAC_REGS
*/

#ifndef CSL_TAC2_REGS_H
#define CSL_TAC2_REGS_H

#ifdef USE_TAC_MODEL
#include <stdlib.h>
#endif

#include <ti/csl/csl.h>
#include <ti/csl/cslr_tac2_cfg.h>
#include <ti/csl/cslr_tac2_sgcp_cfg.h>
#include <ti/csl/cslr_tac2_data.h>

#if defined(USE_SIMULATED_TAC) && defined(USE_TAC_MODEL)
#error Cannot define both USE_SIMULATED_TAC and USE_TAC_MODEL
#endif

#ifndef USE_SIMULATED_TAC
#include <ti/csl/soc.h>
#else
extern volatile CSL_Tac_cfgRegs  * CSL_TAC_FEI_CFG_REGS;
extern volatile CSL_Sgcp_cfgRegs * CSL_TAC_SGCCP_0_CFG_REGS;
extern volatile CSL_Tac_dataRegs * CSL_TAC_DATA_BEI_REGS;
#endif /* USE_SIMULATED_TAC */

#ifdef USE_TAC_MODEL
#include <Tac.hpp>
extern Tac * tacPointer;
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup CSL_TAC_BE_SYMBOL
@{
*/

/**
 *  Handle to access TAC2 Front-End and Back-End registers.
 */
#define hTacRegs      ((CSL_Tac_cfgRegs*)CSL_TAC_FEI_CFG_REGS)

/**
 *  Handle to access TAC SGCP registers.
 */
#define hSgcpRegs     ((CSL_Sgcp_cfgRegs*)CSL_TAC_SGCCP_0_CFG_REGS)

/**
 *  Handle to access TAC Data registers.
 */
#define hTacData      ((CSL_Tac_dataRegs*)CSL_TAC_DATA_BEI_REGS)

/* Macros inspired by CSL original macros */

/**
 * The Field WRIte macro
 */
#define CSL_FWRI(reg, PER_REG_FIELD, val)                          \
    ((reg) = CSL_FMK(PER_REG_FIELD, (val)))

/**
 * Field WRIte (Token) macro
 */
#define CSL_FWRIT(reg, PER_REG_FIELD, TOKEN)                       \
    (CSL_FWRI((reg), PER_REG_FIELD, (CSL_##PER_REG_FIELD##_##TOKEN)))

/**
@}
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CSL_TAC2_REGS_H */

