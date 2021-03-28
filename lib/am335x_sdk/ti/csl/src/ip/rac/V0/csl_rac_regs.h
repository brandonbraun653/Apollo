/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2006.
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
 *   @file  csl_rac_regs.h
 *
 *   @brief
 *      API header for RAC CSL_FL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */
#ifndef CSL_RAC_REGS_H
#define CSL_RAC_REGS_H

#include <ti/csl/csl.h>
#include <ti/csl/cslr_rac_cfg.h>
#include <ti/csl/cslr_gccp_cfg.h>
#include <ti/csl/cslr_rac_data.h>

/**
@defgroup CSL_RAC_API RAC Common Definitions
*/

/**
@defgroup CSL_RAC_DATASTRUCT RAC Common Data Structures
@ingroup CSL_RAC_API
*/

/**
@defgroup CSL_RAC_FUNCTION  RAC Functions
@ingroup CSL_RAC_API
*/

#ifndef _RACFL_TESTBENCH_HOST_BUILD_
#include <ti/csl/soc.h>

typedef volatile CSL_Rac2_cfgRegs    *CSL_Rac2CfgRegsOvly;
typedef volatile CSL_Gccp2_cfgRegs   *CSL_Gccp2CfgRegsOvly;
typedef volatile CSL_Rac2_dataRegs   *CSL_Rac2DataRegsOvly;

#else
/**
 * do not include soc64plus.h for racoh testbench if running on HOST
 *
 * must define the following in testbench code for RAC CSL to work
 *
 * volatile CSL_Rac_cfgRegs CSL_RAC_REGS_MEM;
 * volatile CSL_Rac_cfgRegs * CSL_RAC_REGS = &CSL_RAC_REGS_MEM;
 *
 * volatile CSL_Gccp_cfgRegs CSL_GCCP_REGS_MEM;
 * volatile CSL_Gccp_cfgRegs * CSL_GCCP_REGS = &CSL_GCCP_REGS_MEM;
 *
 * volatile CSL_Rac_dataRegs CSL_RAC_DATA_MEM;
 * volatile CSL_Rac_dataRegs * CSL_RAC_DATA = &CSL_RAC_DATA_MEM;
 *
 */

extern volatile CSL_Rac2_cfgRegs * CSL_RAC_A_REGS;
extern volatile CSL_Gccp2_cfgRegs * CSL_GCCP_A_REGS;
extern volatile CSL_Rac2_dataRegs * CSL_RAC_A_DATA;
extern volatile CSL_Rac2_cfgRegs * CSL_RAC_B_REGS;
extern volatile CSL_Gccp2_cfgRegs * CSL_GCCP_B_REGS;
extern volatile CSL_Rac2_dataRegs * CSL_RAC_B_DATA;

#endif

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************:
 *  RAC Macros
 ******************************************************************************/

/*******************************************************************************
 *  RAC global typedef declarations
 ******************************************************************************/

/**
 *  Handle to access RAC registers accessible through EDMA bus.
 */

/* Macros inspired by CSL original macros */
/* the Field WRIte macro */
#define CSL_FWRI(reg, PER_REG_FIELD, val)                                   \
    ((reg) = CSL_FMK(PER_REG_FIELD, (val)))

/* the Field WRIte (Token) macro */
#define CSL_FWRIT(reg, PER_REG_FIELD, TOKEN)                                \
    (CSL_FWRI((reg), PER_REG_FIELD, (CSL_##PER_REG_FIELD##_##TOKEN)))


/** @addtogroup CSL_RAC_DATASTRUCT
@{
*/


/**
 * This will have the base-address information for the peripheral instance
 */
typedef struct {
    /** Base-address of the RAC Config registers */
    CSL_Rac2CfgRegsOvly     cfgRegs;

    /** Base-address of the GCCP Configuration registers */
    CSL_Gccp2CfgRegsOvly    gccpCfgRegs;

    /** Base-address of the RAC Data registers */
    CSL_Rac2DataRegsOvly    dataRegs;
} CSL_RAC_BaseAddress;

/**
 * This structure/object holds the context of the instance of RAC2
 * opened using CSL_RAC_open () function.
 *
 * Pointer to this object is passed as RAC2 Handle to all RAC2 CSL APIs.
 * CSL_RAC_open () function intializes this structure based on the parameters
 * passed
 */
typedef struct CSL_RAC_Obj_s {
    /** Base-address of the RAC Config registers */
    CSL_Rac2CfgRegsOvly     cfgRegs;

    /** Base-address of the GCCP Configuration registers */
    CSL_Gccp2CfgRegsOvly    gccpCfgRegs;

    /** Base-address of the RAC Data registers */
    CSL_Rac2DataRegsOvly    dataRegs;

    /** Instance of RAC2 being referred by this object  */
    CSL_InstNum             perNum;
} CSL_RAC_Obj;

/** This is a pointer to CSL_RAC_Obj and is passed as the first
 *  parameter to all VCP2 CSL APIs
 */
typedef struct CSL_RAC_Obj_s  *CSL_RAC_Handle;

/**
@}
*/

/** @addtogroup CSL_RAC_FUNCTION
 @{ */

/******************************************************************************
 * RAC common function declarations
 *****************************************************************************/

extern CSL_RAC_Handle CSL_RAC_open (
    CSL_RAC_Obj     *pRac2Obj,
    int32_t             instNum, 
    int32_t             *pStatus
);

extern CSL_Status CSL_RAC_close (
    CSL_RAC_Handle  hRac2
);

extern CSL_Status CSL_RAC_getBaseAddr 
(
    CSL_InstNum                     racNum,
    CSL_RAC_BaseAddress*            pBaseAddress
);

/** 
 @} 
 */

#ifdef __cplusplus
}
#endif

#endif



