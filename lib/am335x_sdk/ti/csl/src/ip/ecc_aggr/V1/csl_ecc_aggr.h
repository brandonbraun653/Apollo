/**
 * @file  V1/csl_ecc_aggr.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the ECC Aggregator Ip.
 *
 *      
 *  @n   (C) Copyright 2015-2019, Texas Instruments, Inc.
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
#ifndef CSL_ECC_AGGR_H
#define CSL_ECC_AGGR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_ecc_aggr.h>

/** 
 *
 * @defgroup CSL_ECC_AGGR_API ECC Aggregator (ECC_AGGR)
 *
 *
 * To increase functional safety and system reliability the memories (for example,
 * FIFOs, queues, SRAMs and others) in many device modules and subsystems are
 * protected by error correcting code (ECC). This is accomplished through an 
 * ECC aggregator and ECC wrapper. The ECC aggregator is connected to
 * these memories (hereinafter ECC RAMs) and involved in the ECC process.
 * Each memory is surrounded by an ECC wrapper which performs the ECC detection
 * and correction. The wrapper communicates via serial interface with the
 * aggregator which has memory mapped configuration interface.
 * The ECC aggregator is also connected to interconnect ECC components that
 * protect the command, address and data buses of the system interconnect.
 * ECC is calculated for the data bus and parity and redundancy for the command
 * and address buses. Each interconnect ECC component has the same serial
 * interface for communication with the aggregator as the ECC wrapper.
 * An ECC aggregator may be connected to both endpoints the ECC wrapper and
 * interconnect ECC component.
 * The ECC aggregator, ECC wrapper and interconnect ECC component are considered
 * as single entity and are hereinafter referred to as ECC aggregator unless
 * otherwise explicitly specified.
 * The design focusses on CSL function layer providing the configuration for
 * ECC RAM ID, force ECC ram error, ECC aggregator interrupt handling features. 
 *
 */
/**
@defgroup CSL_ECC_AGGR_DATASTRUCT  ECC_AGGR Data Structures
@ingroup CSL_ECC_AGGR_API
*/
/**
@defgroup CSL_ECC_AGGR_FUNCTION  ECC_AGGR Functions
@ingroup CSL_ECC_AGGR_API
*/
/**
@defgroup CSL_ECC_AGGR_ENUM ECC_AGGR Enumerated Data Types
@ingroup CSL_ECC_AGGR_API
*/

/** 
 *  @addtogroup CSL_ECC_AGGR_ENUM
    @{
 * 
 */

/** 
 * @brief This enumerator defines the types of possible ECC errors
 *
 * 
 */
typedef uint32_t CSL_Ecc_AggrIntrSrc;
    /** No interrupt */
#define CSL_ECC_AGGR_INTR_SRC_NONE                      ((uint32_t) 0U)
    /** Single-bit Error Correcting (SEC) */
#define CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT                ((uint32_t) 1U)
    /** Double-bit Error Detection (DED) */
#define CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT                ((uint32_t) 2U)
    /** Two or more successive SEC errors */
#define CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS  ((uint32_t) 3U)
    /** Denotes an invalid interrupt source */
#define CSL_ECC_AGGR_INTR_SRC_INVALID                   ((uint32_t) 4U)

/** 
 * @brief This defines the types of possible ECC error controller instances
 *
 *
 */
#define CSL_ECC_AGGR_SELECT_ERR_CTRL1   (0U)
    /** Error controller instance 1 */
#define CSL_ECC_AGGR_SELECT_ERR_CTRL2   (1U)
    /** Error Controller instance 2 */
#define CSL_ECC_AGGR_MAX_NUM_RAM_ERR_CTRL   (2U)
    /** Maximum number of RAM Error Controller registers */

/** 
 * @brief This defines the types of possible ECC error status instances
 *
 *
 */
#define CSL_ECC_AGGR_SELECT_ERR_STAT1   (0U)
    /** Error Status instance 1 */
#define CSL_ECC_AGGR_SELECT_ERR_STAT2   (1U)
    /** Error Status instance 2 */
#define CSL_ECC_AGGR_SELECT_ERR_STAT3   (2U)
    /** Error Status instance 3 */
#define CSL_ECC_AGGR_MAX_NUM_RAM_ERR_STAT   (3U)
    /** Maximum number of RAM Error Status registers */

/** 
 * @brief This defines the number of enable registers
 *
 *
 */
#define CSL_ECC_AGGR_NUM_ENABLE_REGISTERS   (8U)
/** @} */

/** 
 *  @addtogroup CSL_ECC_AGGR_DATASTRUCT
    @{
 * 
 */

/** 
 * @brief   This structure contains error status information returned by the
 *          CSL_ecc_aggrGetEccRamGetErrorStatus function, and error forcing
 *          information used by the CSL_ecc_aggrForceEccRamError function.
 *
 *
 */
typedef struct
{
    /** Identifies the interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT, or CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS) */
    CSL_Ecc_AggrIntrSrc intrSrc;
    /** Error status: Not used. Error forcing: If true, the force_sec/force_ded will inject an error to the specified row only once. */
    bool                bOneShotMode;
    /** Error status: Indicates the row/address where the error occurred. Error forcing: Row address where SEC or DED needs to be applied (ignored if bNextRow is true). */
    uint32_t            eccRow;
    /** Error status: Indicates the data bit that is in error. Error forcing: Bit position of SEC or 1st bit position for DED */
    uint32_t            eccBit1;
    /** Error status: Not used. Error forcing: 2nd bit position for DED. */
    uint32_t            eccBit2;
    /** Error status: Not used. Error forcing: Force single or double-bit error on the next RAM row (the eccRow field is ignored). */
    bool                bNextRow;
} CSL_Ecc_AggrErrorInfo;

/** 
 * @brief   This structure contains the static register group for Ecc aggregator
 *          used by the CSL_ecc_aggrReadStaticRegs function.
 *
 *
 */
typedef struct {
    /** Aggregator Revision Register */
    uint32_t REV;
    /** ECC Control register */
    uint32_t ECC_CTRL;
    /** ECC Err Control1 register */
    uint32_t ECC_ERR_CTRL1;
    /** ECC Err Control2 register */
    uint32_t ECC_ERR_CTRL2;
    /** ECC_SEC_ENABLE_SET_REG registers */
    uint32_t ECC_SEC_ENABLE_SET_REG[CSL_ECC_AGGR_NUM_ENABLE_REGISTERS];
    /** ECC_SEC_ENABLE_SET_REG registers */
    uint32_t ECC_SEC_ENABLE_CLR_REG[CSL_ECC_AGGR_NUM_ENABLE_REGISTERS];
    /** ECC_DED_ENABLE_SET_REG registers */
    uint32_t ECC_DED_ENABLE_SET_REG[CSL_ECC_AGGR_NUM_ENABLE_REGISTERS];
    /** ECC_DED_ENABLE_SET_REG registers */
    uint32_t ECC_DED_ENABLE_CLR_REG[CSL_ECC_AGGR_NUM_ENABLE_REGISTERS];
} CSL_ecc_aggrStaticRegs;

/** @} */

/** 
 *  @addtogroup CSL_ECC_AGGR_FUNCTION
    @{
 *     
 */

/**     
 *   @n@b CSL_ecc_aggrGetRevision
 *
 *   @b Description
 *   @n This function returns the revision information for the ECC Aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  pRev         A pointer (of type uint32_t) to hold the rev ID
 *                      value of the ECC Aggregator module
 *                      Revision information. See design specification for details.
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t rev;
 *      int32_t  retValue;
 *
 *      retValue CSL_ecc_aggrGetRevision(pEccAggrRegs, &rev);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrGetRevision(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t *pRev);

/**     
 *   @n@b CSL_ecc_aggrGetNumRams
 *
 *   @b Description
 *   @n This function returns the number of RAMs serviced by this ECC Aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  pNumRams     A pointer (of type uint32_t) to hold the value of
 *                      number of RAMs serviced by this ECC Aggregator
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t         NumRams;
 *      int32_t          retValue;
 *
 *      retValue CSL_ecc_aggrGetNumRams(pEccAggrRegs, &NumRams);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrGetNumRams(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t *pNumRams);

/**     
 *   @n@b CSL_ecc_aggrReadEccRamReg
 *
 *   @b Description
 *   @n This function reads the specified ECC wrapper register from the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  regOffset    Byte offset of the ECC wrapper register to read (must be in the
 *                      range of 0x10..0x24)
 *   @n  pRegVal      A pointer (of uint32_t) to hold the value of the 
 *                      specified ECC wrapper register
 *
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the arguments such as ramId and/or regOffset are invalid
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      uint32_t            EccWrapperRegVal;
 *      int32_t             retStatus;
 *
 *      retStatus CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_WRAP_REV, &EccWrapperRegVal);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrReadEccRamReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t regOffset, uint32_t *pRegVal );

/**     
 *   @n@b CSL_ecc_aggrReadEccRamWrapRevReg
 *
 *   @b Description
 *   @n This function reads the ECC wrapper revision register from the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *
 *   @n  pRegVal A pointer (of type uint32_t) to hold the
 *                value of the ECC wrapper revision register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      uint32_t            EccWrapperRegVal;
 *      uint32_t            cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrReadEccRamWrapRevReg(pEccAggrRegs, ramId, &EccWrapperRegVal);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrReadEccRamWrapRevReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t *pRegVal);

/**     
 *   @n@b CSL_ecc_aggrReadEccRamCtrlReg
 *
 *   @b Description
 *   @n This function reads the specified ECC wrapper control register from the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *
 *   @n  pRegVal A pointer (of type uint32_t) to hold the
 *                value of the ECC control register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      uint32_t            EccCtrlRegVal;
 *      int32_t             cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrReadEccRamCtrlReg(pEccAggrRegs, ramId, &EccCtrlRegVal);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrReadEccRamCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t *pRegVal);

/**     
 *   @n@b CSL_ecc_aggrReadEccRamErrCtrlReg
 *
 *   @b Description
 *   @n This function reads the specified ECC wrapper error control register from the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  instSelect   Instance selector (0..1) of the specified register to read
 *
 *   @n  pRegVal A pointer (of type uint32_t) to hold the
 *                value of the ECC Error control register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      uint32_t            regVal;
 *      int32_t             cslRetValue;
 *      cslRetValue CSL_ecc_aggrReadEccRamErrCtrlReg(pEccAggrRegs, ramId, 0, &regVal);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrReadEccRamErrCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t *pRegVal);

/**     
 *   @n@b CSL_ecc_aggrReadEccRamErrStatReg
 *
 *   @b Description
 *   @n This function reads the specified ECC wrapper error status register from the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  instSelect   Instance selector (0..1) of the specified register to read
 *
 *   @n  pRegVal A pointer (of type uint32_t) to hold the
 *                value of the ECC error status register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      uint32_t            regVal;
 *      int32_t             cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrReadEccRamErrStatReg(pEccAggrRegs, ramId, 1, &regVal);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrReadEccRamErrStatReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t *pRegVal);

/**     
 *   @n@b CSL_ecc_aggrWriteEccRamReg
 *
 *   @b Description
 *   @n This function writes a value into the specified ECC wrapper register in the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  regOffset    Byte offset of the ECC wrapper register to write (must be in the
 *                      range of 0x10..0x24)
 *   @n  val          The 32-bit value to write into the register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      cslRetValue CSL_ecc_aggrWriteEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_CTRL, 0);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrWriteEccRamReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t regOffset, uint32_t val);

/**     
 *   @n@b CSL_ecc_aggrWriteEccRamCtrlReg
 *
 *   @b Description
 *   @n This function write a value into the ECC wrapper control register in the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  val          The 32-bit value to write into the register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrWriteEccRamCtrlReg(pEccAggrRegs, ramId, 0);
 *   @endverbatim
 *     
 */
int32_t CSL_ecc_aggrWriteEccRamCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t val);

/**     
 *   @n@b CSL_ecc_aggrWriteEccRamErrCtrlReg
 *
 *   @b Description
 *   @n This function writes a value into the specified ECC wrapper error control 
 *      register in the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  instSelect   Instance selector (0..1) of the specified register to write
 *   @n  val          The 32-bit value to write into the register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      int32_t             cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrWriteEccRamErrCtrlReg(pEccAggrRegs, ramId, 0, 0);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrWriteEccRamErrCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t val);

/**     
 *   @n@b CSL_ecc_aggrWriteEccRamErrStatReg
 *
 *   @b Description
 *   @n This function write a value into the specified ECC wrapper error status register in the specific ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                      address of the ECC Aggregator module
 *   @n  ramId        RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  instSelect   Instance selector (0..1) of the specified register to write
 *   @n  val          The 32-bit value to write into the register
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      int32_t             cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrWriteEccRamErrStatReg(pEccAggrRegs, ramId, 1, 0);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrWriteEccRamErrStatReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t val);

/**     
 *   @n@b CSL_ecc_aggrConfigEccRam
 *
 *   @b Description
 *   @n This function is used to configure the ECC capabilities of the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs   A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                        address of the ECC Aggregator module
 *   @n  ramId          RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  bEnable        If true, then enable ECC generation. ECC is completely bypassed if both fEnable and fEccCheck are 0.
 *   @n  bEccCheck      If true, then enable ECC check. ECC is completely bypassed if both fEnable and fEccCheck are 0.
 *   @n  bfEnableRMW    If true, then enable read-modify-write on partial word writes
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t      ramId 0;
 *      int32_t       cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrConfigEccRam(pEccAggrRegs, ramId, true, true, false);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrConfigEccRam(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool bEnable, bool bEccCheck, bool bEnableRMW);

/**     
 *   @n@b CSL_ecc_aggrVerifyConfigEccRam
 *
 *   @b Description
 *   @n This function is used to verify the configure the ECC capabilities of the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs   A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                        address of the ECC Aggregator module
 *   @n  ramId          RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  bEnable        If true, then enable ECC generation. ECC is completely bypassed if both fEnable and fEccCheck are 0.
 *   @n  bEccCheck      If true, then enable ECC check. ECC is completely bypassed if both fEnable and fEccCheck are 0.
 *   @n  bfEnableRMW    If true, then enable read-modify-write on partial word writes
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success, indicates the configuration is successful
 *   @n  CSL_EFAIL     Failure, indicates the expected configuration failed
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_ecc_aggrConfigEccRam() is called previously with the same arguments
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t      ramId 0;
 *      int32_t       cslRetValue;
 *
 *      cslRetValue CSL_ecc_aggrVerifyConfigEccRam(pEccAggrRegs, ramId, true, true, false);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrVerifyConfigEccRam(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool bEnable, bool bEccCheck, bool bEnableRMW);

/**     
 *   @n@b CSL_ecc_aggrGetEccRamGetErrorStatus
 *
 *   @b Description
 *   @n This function is used to get the error status of the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  pEccErrorStatus    A pointer to a CSL_Ecc_AggrIntrSrc structure containing
 *                            returned error information
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs      *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t              ramId 0;
 *      CSL_Ecc_AggrIntrSrc   ErrorStatus;
 *
 *      CSL_ecc_aggrGetEccRamGetErrorStatus(pEccAggrRegs, ramId, &ErrorStatus);
 *      printf( "Error type: %u\n", ErrorStatus.Type );
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrGetEccRamGetErrorStatus(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrErrorInfo *pEccErrorStatus);

/**     
 *   @n@b CSL_ecc_aggrForceEccRamError
 *
 *   @b Description
 *   @n This function is used to force an ECC error on the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  pEccForceError     A pointer to a CSL_Ecc_AggrIntrSrc structure containing
 *                            force error information
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs      *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t              ramId 0;
 *      CSL_Ecc_AggrIntrSrc   forceErrorInfo;
 *
 *      forceErrorInfo.Type         CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT;
 *      forceErrorInfo.Row          0;        // Ignored since bNextRow is true
 *      forceErrorInfo.Bit1         4;        // Force sec at bit 4
 *      forceErrorInfo.Bit2         0;        // Ignored since this is a sec forced error
 *      forceErrorInfo.bNextRow     true;
 *      forceErrorInfo.bOneShotMode true;
 *      CSL_ecc_aggrForceEccRamError(pEccAggrRegs, ramId, &forceErrorInfo);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrForceEccRamError(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, const CSL_Ecc_AggrErrorInfo *pEccForceError);

/**     
 *   @n@b CSL_ecc_aggrAckIntr
 *
 *   @b Description
 *   @n This function is used to acknowledged a pending interrupt and to send
 *      the next interrupt to the host
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT) to acknowledge
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *
 *      CSL_ecc_aggrAckIntr(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrAckIntr(CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrIsEccRamIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status of the specified interrupt
 *      source from the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT,
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT, or CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS)
 *
 *   @n  pIsPend            A Pointer (of type bool) to hold the state as below
 *     true               An interrupt of the specified type is pending
 *     false              An interrupt of the specified type is not pending, or the ramId and/or intrSrc
 *                            arguments are invalid
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *      bool                bIntrPending;
 *      int32_t             cslRetVal;
 *
 *      cslRetVal CSL_ecc_aggrIsEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT, &bIntrPending);
 *      printf("SEC interrupt for RAM ID %u is %s\n", ramId, bIntrPending ? "pending" : "not pending" );
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrIsEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool *pIsPend);

/**     
 *   @n@b CSL_ecc_aggrSetEccRamIntrPending
 *
 *   @b Description
 *   @n This function is used to forceably set the pending status of the
 *      specified interrupt source on the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT,
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT, or CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrSetEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrSetEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *      CSL_ecc_aggrSetEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrSetEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrClrEccRamIntrPending
 *
 *   @b Description
 *   @n This function is used to clear the pending status of the
 *      specified interrupt source on the specified ECC RAM
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT,
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT, or CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrClrEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrClrEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *      CSL_ecc_aggrClrEccRamIntrPending(pEccAggrRegs, ramId, CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrClrEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrIsIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status for the specified
 *      ECC interrupt source from the ECC RAM specified by ramId.
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT; valid only for the
 *                            CSL_ecc_aggrIsIntrPending function)
 *
 *   @n pIsPend            A pointer (of type bool) to hold the status as below
 *     true               An interrupt of the specified type is pending
 *     false              An interrupt of the specified type is not pending, or the ramId and/or intrSrc
 *                            arguments are invalid
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t             ramId 0;
 *      bool                 bIntrPending;
 *      int32_t              cslRetVal;
 *
 *      cslRetVal CSL_ecc_aggrIsIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT, &bIntrPending);
 *      printf("SEC interrupt for RAM ID %u is %s\n", ramId, bIntrPending ? "pending" : "not pending" );
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrIsIntrPending(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool *pIsPend);

/**     
 *   @n@b CSL_ecc_aggrIsAnyIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status for any
 *      interrupt source from the ECC RAM specified by ramId.
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t             ramId 0;
 *      bool                 bIntrPending;
 *
 *      cslRetVal CSL_ecc_aggrIsAnyIntrPending(pEccAggrRegs, ramId, &bIntrPending);
 *      printf("One or more interrupts are %s for RAM ID %u is %s\n", ramId, bIntrPending ? "pending" : "not pending" );
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrIsAnyIntrPending(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool *pIsPend);

/**     
 *   @n@b CSL_ecc_aggrEnableIntr
 *
 *   @b Description
 *   @n This function enables the interrupt for the specified
 *      interrupt source on the RAM specified by ramId
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrEnableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrEnableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrEnableIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrDisableIntr
 *
 *   @b Description
 *   @n This function disables the interrupt for the specified
 *      interrupt source on the RAM specified by ramId
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicate the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrDisableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrDisableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrDisableIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrEnableAllIntr
 *
 *   @b Description
 *   @n This function enables the interrupts for all of the available
 *      interrupt sources on the RAM specified by ramId
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrEnableAllIntr(pEccAggrRegs, ramId);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrEnableAllIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId);

/**     
 *   @n@b CSL_ecc_aggrDisableAllIntr
 *
 *   @b Description
 *   @n This function disables the interrupts for all of the available
 *      interrupt sources on the RAM specified by ramId
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  ramId              RAM identifier (0..CSL_ecc_aggrGetNumRams()-1)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      uint32_t            ramId 0;
 *
 *      CSL_ecc_aggrDisableAllIntr(pEccAggrRegs, ramId);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrDisableAllIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId);

/**     
 *   @n@b CSL_ecc_aggrEnableIntrs
 *
 *   @b Description
 *   @n This function enables the interrupt for the specified interrupt source on all
 *      ECC RAMs serviced by this aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *
 *      CSL_ecc_aggrEnableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrEnableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrEnableIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrDisableIntrs
 *
 *   @b Description
 *   @n This function disables the interrupts for the specified interrupt source on all
 *      ECC RAMs serviced by this aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  intrSrc            The interrupt source (CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT or
 *                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT)
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *
 *      CSL_ecc_aggrDisableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
 *      CSL_ecc_aggrDisableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrDisableIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc);

/**     
 *   @n@b CSL_ecc_aggrEnableAllIntrs
 *
 *   @b Description
 *   @n This function enables the interrupts for all of the available
 *      interrupt sources on all ECC RAMs serviced by this aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *
 *      CSL_ecc_aggrEnableAllIntrs(pEccAggrRegs);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrEnableAllIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs);

/**     
 *   @n@b CSL_ecc_aggrDisableAllIntrs
 *
 *   @b Description
 *   @n This function disables the interrupts for all of the available
 *      interrupt sources on all ECC RAMs serviced by this aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *
 *      CSL_ecc_aggrDisableAllIntrs(pEccAggrRegs);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrDisableAllIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs);

/**     
 *   @n@b CSL_ecc_aggrReadStaticRegs
 *
 *   @b Description
 *   @n This function reads the static registers for ECC aggregator
 *
 *   @b Arguments
 *   @n  pEccAggrRegs       A pointer (of type CSL_ecc_aggrRegs*) to the base
 *                            address of the ECC Aggregator module
 *   @n  pEccAggrStaticRegs  A pointer (of type CSL_ecc_aggrStaticRegs*) to
 *                             hold the static register values
 *
 *   <b> Return Value </b>
 *   @n  CSL_PASS      Success
 *   @n  CSL_EBADARGS  Failure, indicates the bad input arguments
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *
 *   @b Example
 *   @verbatim
 *      CSL_ecc_aggrRegs    *pEccAggrRegs (CSL_ecc_aggrRegs *)ECC_AGGR_BASE_ADDRESS;
 *      CSL_ecc_aggrStaticRegs  eccAggrStaticRegs;
 *
 *      cslRet CSL_ecc_aggrReadStaticRegs(pEccAggrRegs, &eccAggrStaticRegs);
 *   @endverbatim
 *    
 */
int32_t CSL_ecc_aggrReadStaticRegs(CSL_ecc_aggrRegs *pEccAggrRegs, CSL_ecc_aggrStaticRegs *pEccAggrStaticRegs);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
