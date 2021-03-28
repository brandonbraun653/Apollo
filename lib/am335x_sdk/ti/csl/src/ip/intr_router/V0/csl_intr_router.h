/**
 * @file  csl_intr_router.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the Interrupt Router IP.
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2017, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorpopated nor the names of
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
#ifndef CSL_INTR_ROUTER_H_
#define CSL_INTR_ROUTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_intr_router.h>

/** ===========================================================================
 *
 * @defgroup CSL_INTR_ROUTER_API Interrupt Router
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the Interrupt Router module.
 *
 * @subsection References
 *    - intr_router Module Specification, version 1.0.7
 *
 * ============================================================================
 */
/**
@defgroup CSL_INTR_ROUTER_DATASTRUCT  INTR_ROUTER Data Structures
@ingroup CSL_INTR_ROUTER_API
*/
/**
@defgroup CSL_INTR_ROUTER_FUNCTION  INTR_ROUTER Functions
@ingroup CSL_INTR_ROUTER_API
*/
/**
@defgroup CSL_INTR_ROUTER_ENUM INTR_ROUTER Enumerated Data Types
@ingroup CSL_INTR_ROUTER_API
*/

/** ===========================================================================
 *  @addtogroup CSL_INTR_ROUTER_ENUM
    @{
 * ============================================================================
 */

/** @} */

/** ============================================================================
 *  @addtogroup CSL_INTR_ROUTER_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains configuration parameters for the Interrupt Router
 *
 * ----------------------------------------------------------------------------
 */

typedef struct
{
    CSL_intr_router_cfgRegs         *pIntrRouterRegs;   /** Pointer to the interrupt router config registers */
    CSL_intr_router_intd_cfgRegs    *pIntdRegs;         /** Pointer to the interrupt distributor config registers (or NULL if the intd is not included) */
    uint32_t                        numInputIntrs;      /** Maximum # of input interrupts */
    uint32_t                        numOutputIntrs;     /** Maximum # of output interrupts */
} CSL_IntrRouterCfg;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_INTR_ROUTER_FUNCTION
    @{
 * ============================================================================
 */

/** ============================================================================
 *   @n@b CSL_intrRouterGetRevision
 *
 *   @b Description
 *   @n This function returns the revision information for the Intr Router
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *
 *   <b> Return Value </b>
 *   @n  Revision information. See design specification for details.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n PID
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       uint32_t rev;

       rev = CSL_intrRouterGetRevision(&pCfg);
     @endverbatim
 * =============================================================================
 */
extern uint32_t CSL_intrRouterGetRevision(const CSL_IntrRouterCfg *pCfg);

/** ============================================================================
 *   @n@b CSL_intrRouterSetIntdBypassEnable
 *
 *   @b Description
 *   @n This function enables or disables intd bypass for the particular output
 *      interrupt
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *   @n  bBypass        - If true, intd bypass is enabled, otherwise it is disabled
 *
 *   <b> Return Value </b>
 *   @n   0 = success
 *   @n  -1 = intrNum out of range
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n None
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       uint32_t intrNum = 8;

      CSL_intrRouterSetIntdBypassEnable(&pCfg, intrNum, true);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterSetIntdBypassEnable(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bBypass);

/** ============================================================================
 *   @n@b CSL_intrRouterCfgMux
 *
 *   @b Description
 *   @n This function configures the mux so that the specified input interrupt
 *      is mapped to the specified output interrupt
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  intrNum        - Interrupt number (0..(pCfg->numInputIntrs-1))
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *
 *   <b> Return Value </b>
 *   @n   0 = success
 *   @n  -1 = intrNum or outputIntrNum out of range
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n None
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       uint32_t inputIntrNum = 8;
       uint32_t outputIntrNum = 9;

      CSL_intrRouterCfgMux(&pCfg, inputIntrNum, outputIntrNum);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterCfgMux(CSL_IntrRouterCfg *pCfg, uint32_t inputIntrNum, uint32_t outputIntrNum);

/** ============================================================================
 *   @n@b CSL_intrRouterSetIntrEnable
 *
 *   @b Description
 *   @n This function enables or disables the specified output interrupt
 *
 *      Note: This function has no functionality if the interrupt router does
 *            not contain an intd IP.
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *   @n  bEnable        - If true, the interrupt is enabled, otherwise it is disabled
 *
 *   <b> Return Value </b>
 *   @n   0 = success
 *   @n  -1 = outputIntrNum out of range
 *   @n  -2 = function not supported (intd is not present in this intr_router)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n INTERRUPT_ENABLE_SET
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       unint32_t intrNum = 10;

       CSL_intrRouterSetIntrEnable(&pCfg, intrNum, true);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterSetIntrEnable(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bEnable);

/** ============================================================================
 *   @n@b CSL_intrRouterIsIntrPending
 *
 *   @b Description
 *   @n This function returns the pending interrupt status of the specified
 *      interrupt.
 *
 *      Note: This function has no functionality if the interrupt router does
 *            not contain an intd IP.
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *
 *   <b> Return Value </b>
 *   @n   1 = Interrupt is pending
 *   @n   0 = Interrupt is not pending
 *   @n  -1 = outputIntrNum out of range
 *   @n  -2 = function not supported (intd is not present in this intr_router)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n EXCEPTION_PEND_SET
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       bool bIntPending;
       uint32_t intrNum = 12;

       bIntPending = CSL_intrRouterIsIntrPending(&pCfg, intrNum);
       printf("Exception interrupt is %s\n", bIntPending ? "pending" : "not pending" );
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterIsIntrPending(const CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum);

/** ============================================================================
 *   @n@b CSL_intrRouterSetIntrPendingStatus
 *
 *   @b Description
 *   @n This function is used to set or clear the pending status of the
 *      specified interrupt.
 *
 *      Note: This function has no functionality if the interrupt router does
 *            not contain an intd IP.
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *   @n  bPend          - If true, the interrupt pending status is set,
 *                        otherwise it is cleared
 *
 *   <b> Return Value </b>
 *   @n   0 = success
 *   @n  -1 = outputIntrNum out of range
 *   @n  -2 = function not supported (intd is not present in this intr_router)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EXCEPTION_PEND_SET
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       uint32_t intrNum = 13;
       CSL_intrRouterSetIntrPendingStatus(&pCfg, intrNum, true);
     @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterSetIntrPendingStatus(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum, bool bPend);

/** ============================================================================
 *   @n@b CSL_intrRouterAckIntr
 *
 *   @b Description
 *   @n This function is used to acknowledge the specified interrupt source.
 *
 *      Note: This function has no functionality if the interrupt router does
 *            not contain an intd IP.
 *
 *   @b Arguments
 *   @n  pCfg           - A pointer (of type CSL_IntrRouterCfg*) to the
 *                        Interrupt Router configuration structure
 *   @n  outputIntrNum  - Output interrupt number (0..(pCfg->numOutputIntrs-1))
 *
 *   <b> Return Value </b>
 *   @n   0 = success
 *   @n  -1 = outputIntrNum out of range
 *   @n  -2 = function not supported (intd is not present in this intr_router)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n EOI_REG
 *
 *   @b Example
 *   @verbatim
       CSL_IntrRouterCfg pCfg;
       unint32_t intrNum = 15;
       CSL_intrRouterAckExceptionInt(&pCfg, intrNum);
    @endverbatim
 * =============================================================================
 */
extern int32_t CSL_intrRouterAckIntr(CSL_IntrRouterCfg *pCfg, uint32_t outputIntrNum);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
