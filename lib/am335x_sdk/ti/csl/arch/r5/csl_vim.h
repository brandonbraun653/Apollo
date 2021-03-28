/**
 * @file  csl_vim.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the VIM IP.
 *  ============================================================================
 *  @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
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
#ifndef CSL_VIM_H
#define CSL_VIM_H

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/arch/r5/cslr_vim.h>

#ifdef __cplusplus
extern "C" {
#endif

/** 
 *
 * @defgroup CSL_VIM_API VIM API
 *
 * The Vectored Interrupt Manager (VIM) aggregates interrupts to a CPU.
 * It is intended for use with a Cortex R5 from ARM in either split or lockstep
 * configuration. The VIM has up to 1024 interrupt inputs per CPU,
 * which may be either level or pulse. Each interrupt has a programmable priority
 * (0- highestthrough 15-lowest). Each interrupt may also be mapped as an
 * IRQ or FIQ (FIQ is also often denoted as Non-Maskable Interrupt, or NMI).
 * 
 */
/**
@defgroup CSL_VIM_DATASTRUCT  VIM Data Structures
@ingroup CSL_VIM_API
*/
/**
@defgroup CSL_VIM_FUNCTION  VIM Functions
@ingroup CSL_VIM_API
*/
/**
@defgroup CSL_VIM_MACROS VIM Macros
@ingroup CSL_VIM_API
*/

/**
 *  @addtogroup CSL_VIM_MACROS
    @{
 *
 */

/**
 *  \anchor CSL_vimIntGroups
 *  \name   vim interrupt groups.
 *  @{
 */

/** This enumerator defines the maximum interrupt groups in VIM.*/
#define CSL_VIM_MAX_INTR_GROUPS     (32U)

/** This enumerator defines the number of interrupts per group in VIM. */
#define CSL_VIM_NUM_INTRS_PER_GROUP (32U)
/* @} */


/**
 * @brief This enumerator defines the possible interrupt types. Each source
 *        interrupt is either an active high level or active high pulse.
 *
 *
 */
typedef uint32_t CSL_VimIntrType;

/**
 *  \anchor CSL_vimIntTypes
 *  \name   vim interrupt types
 *  @{
 */

/** Interrupt source is a level interrupt type */
#define CSL_VIM_INTR_TYPE_LEVEL ((uint32_t)0U)

/** Interrupt source is a pulse interrupt type */
#define CSL_VIM_INTR_TYPE_PULSE ((uint32_t)1U)
/* @} */

/**
 * @brief This enumerator defines the possible output interrupt types. Each
 *        source interrupt can be configured to drive either the IRQ or FIQ
 *        output signal.
 *
 *
 */
typedef uint32_t CSL_VimIntrMap;

/**
 *  \anchor CSL_vimIntMaps
 *  \name   vim interrupt maps
 *  @{
 */

/** Output interrupt is mapped to IRQ  */
#define CSL_VIM_INTR_MAP_IRQ    ((uint32_t)0U)  

/** Output interrupt is mapped to FIQ  */
#define CSL_VIM_INTR_MAP_FIQ    ((uint32_t)1U)

/** Output interrupt is mapped to IRQ or FIQ */
#define CSL_VIM_INTR_MAP_ALL    ((uint32_t)2U)
/* @} */

/* @} */

/**
 *  \addtogroup CSL_VIM_DATASTRUCT
 *  @{
 */

/**
 * @brief This structure defines the group registers identified for VIM static
 * registers
 *
 *
 */
typedef struct {
    volatile uint32_t INTR_EN_SET;               /** Interrupt Enable Set Register */
    volatile uint32_t INTR_EN_CLR;               /** Interrupt Enabled Clear Register */
    volatile uint32_t INTMAP;                    /** Interrupt Map Register */
    volatile uint32_t INTTYPE;                   /** Interrupt Type Register */
} CSL_vimStaticRegs_GRP;

/**
  * @brief This structure defines the static register groups identified for VIM
 *
 *
 */
typedef struct {
    CSL_vimStaticRegs_GRP GRP[CSL_VIM_MAX_INTR_GROUPS]; /** Group Registers */
    CSL_vimRegs_PRI PRI[CSL_VIM_MAX_INTR_GROUPS*CSL_VIM_NUM_INTRS_PER_GROUP]; /** Priority Regs */
    CSL_vimRegs_VEC VEC[CSL_VIM_MAX_INTR_GROUPS*CSL_VIM_NUM_INTRS_PER_GROUP]; /** Vec addr regs */
    volatile uint32_t PID;                       /** Revision Register */
    volatile uint32_t INFO;                      /** Info Register */
    volatile uint32_t IRQVEC;                    /** IRQ Vector Address Register */
    volatile uint32_t FIQVEC;                    /** FIQ Vector Address Register */
    volatile uint32_t DEDVEC;                    /** DED Vector Address Register */
} CSL_vimStaticRegs;

/* @} */

/**
 *  \addtogroup CSL_VIM_FUNCTION
 *  @{
 */

/**
 *  \brief Return revision of the VIM module
 *
 *  This function returns the contents of the VIM revision register.
 *  Consult the VIM module documentation for a description of the
 *  contents of the revision register.
 *
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *
 *  \return The 32-bit revision register is returned.
 */
uint32_t CSL_vimGetRevision( CSL_vimRegs *pRegs );

/**
 *  \brief Get the number of interrupts supported by this VIM
 *
 *  This function returns the number of interrupts supported by this VIM.
 *  This value is always a multiple of 32.
 *
 *  The number of interrupt groups = number of interrupts / 32.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *
 *  \return The number of interrupts supported
 */
uint32_t CSL_vimGetNumIntrs( CSL_vimRegs *pRegs );

/**
 *  \brief Configure a source interrupt using VIM
 *
 *  This function configures the specified source interrupt per the provided
 *  parameters.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *  \param pri          [IN]    Interrupt priority (0(highest)..15(lowest))
 *  \param intrMap      [IN]    Interrupt mapping (CSL_VIM_INTR_MAP_IRQ
 *                              or CSL_VIM_INTR_MAP_FIQ, see #CSL_VimIntrMap)
 *  \param intrType     [IN]    Interrupt type (CSL_VIM_INTR_TYPE_LEVEL or
 *                              CSL_VIM_INTR_TYPE_PULSE, see #CSL_VimIntrType)
 *  \param vecAddr      [IN]    32-bit vector address (forced to 32-bit alignment)
 *
 *  \return  0 = success
 *          -1 = intrNum or pri parameters are out of range
 */
int32_t CSL_vimCfgIntr(
                                CSL_vimRegs     *pRegs,
                                uint32_t         intrNum,
                                uint32_t         pri,
                                CSL_VimIntrMap   intrMap,
                                CSL_VimIntrType  intrType,
                                uint32_t         vecAddr
);

/**
 *  \brief Read back Verify Configure a source interrupt
 *
 *  This function verifies the writetn configuration of
 *  interrupt for the specified source interrupt per the provided
 *  parameters.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *  \param pri          [IN]    Interrupt priority (0(highest)..15(lowest))
 *  \param intrMap      [IN]    Interrupt mapping (CSL_VIM_INTR_MAP_IRQ
 *                              or CSL_VIM_INTR_MAP_FIQ, see #CSL_VimIntrMap)
 *  \param intrType     [IN]    Interrupt type (CSL_VIM_INTR_TYPE_LEVEL or
 *                              CSL_VIM_INTR_TYPE_PULSE, see #CSL_VimIntrType)
 *  \param vecAddr      [IN]    32-bit vector address (forced to 32-bit alignment)
 *
 *  \return  0 = success (matches to expected values)
 *          -1 = VIM register configuration is not matching expected value
 */
int32_t CSL_vimVerifyCfgIntr(
                                CSL_vimRegs     *pRegs,
                                uint32_t         intrNum,
                                uint32_t         pri,
                                CSL_VimIntrMap   intrMap,
                                CSL_VimIntrType  intrType,
                                uint32_t         vecAddr
);


/**
 *  \brief Get the interrupt type
 *
 *  This function returns the interrupt type for the specified interrupt
 *  number.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *
 *  \return  0 = CSL_VIM_INTR_TYPE_LEVEL
 *           1 = CSL_VIM_INTR_TYPE_PULSE
 *          -1 = intrNum parameter is out of range
 */
int32_t CSL_vimGetIntrType( CSL_vimRegs *pRegs, uint32_t intrNum );

/**
 *  \brief Set the DED interrupt vector address
 *
 *  This function sets the 32-bit interrupt vector address (the address must
 *  be 32-bit aligned) of an interrupt to be used if an uncorrectable
 *  double-bit error (DED) is detected in any of the interrupt vector
 *  addresses. If there is a DED, the pVectorAddr argument of the
 *  #CSL_vimGetActivePendingIntr function will be populated with the value
 *  in this field instead of their normal vector.
 *
 *  \param pRegs            [IN]    Pointer to the CSL_vimRegs register structure
 *  \param dedVectorAddr    [IN]    The 32-bit DED interrupt vector address
 *
 *  \return  None
 */
void CSL_vimSetDedVectorAddr( CSL_vimRegs *pRegs, uint32_t dedVectorAddr );

/**
 *  \brief Get the DED interrupt vector address
 *
 *  This function sets the 32-bit interrupt vector address (the address must
 *  be 32-bit aligned) of an interrupt to be used if an uncorrectable
 *  double-bit error (DED) is detected in any of the interrupt vector
 *  addresses. If there is a DED, the pVectorAddr argument of the
 *  #CSL_vimGetActivePendingIntr function will be populated with the value
 *  in this field instead of their normal vector.
 *
 *  \param pRegs            [IN]    Pointer to the CSL_vimRegs register structure
 *  \param pDedVectorAddr   [OUT]   Pointer to the 32-bit DED interrupt vector address
 *
 *  \return  0 = Success
 *           CSL_ESYS_FAIL = Failure
 */
int32_t CSL_vimGetDedVectorAddr( CSL_vimRegs *pRegs, uint32_t *pDedVectorAddr );

/**
 *  \brief Get information on the current highest priority pending interrupt
 *
 *  This function returns information on the current highest priority
 *  pending interrupt. The #CSL_vimGetIrqVectorAddress or
 *  #CSL_vimGetFiqVectorAddress functions can be called to get the vector
 *  address associated with the pending interrupt.
 *
 *  There are two types of pending interrupts that can be queried:
 *  CSL_VIM_INTR_MAP_IRQ or CSL_VIM_INTR_MAP_FIQ (see #CSL_VimIntrMap).
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrMap      [IN]    Type of active interrupt to query (see #CSL_VimIntrMap)
 *  \param pIntrNum     [OUT]   Pointer where interrupt number is returned
 *  \param pPri         [OUT]   Pointer where priority of interrupt is returned
 *
 *  \return  0 = success
 *          -1 = no interrupt is currently pending
 */
int32_t CSL_vimGetActivePendingIntr(
                                           CSL_vimRegs    *pRegs,
                                           CSL_VimIntrMap  intrMap,
                                           uint32_t       *pIntrNum,
                                           uint32_t *pPri
);

/**
 *  \brief Get the current IRQ vector address
 *
 *  This function returns the 32-bit interrupt vector address of the currently
 *  pending IRQ interrupt.
 *
 *  Note that the vector address returned is valid only if there is a pending
 *  interrupt.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *
 *  \return Interrupt vector address of the currently pending IRQ interrupt
 */
uint32_t CSL_vimGetIrqVectorAddress( CSL_vimRegs *pRegs );

/**
 *  \brief Get the current FIQ vector address
 *
 *  This function returns the 32-bit interrupt vector address of the currently
 *  pending FIQ interrupt.
 *
 *  Note that the vector address returned is valid only if there is a pending
 *  interrupt.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *
 *  \return Interrupt vector address of the currently pending FIQ interrupt
 *          or 0 if there is no FIQ interrupt pending
 */
uint32_t CSL_vimGetFiqVectorAddress( CSL_vimRegs *pRegs );

/**
 *  \brief Get bit-mask of masked interrupt status for all interrupt groups
 *
 *  This function returns a 32-bit mask of the masked interrupt status for all
 *  interrupt groups, where bit # M in the mask indicates the masked interrupt
 *  status for interrupt group M (0 = no interrupt pending for that
 *  group, 1 = interrupt is pending for that group).
 *
 *  Group M aggregates the interrupt status for interrupt numbers
 *  32*M ... (32*M)+31. The #CSL_vimGetGroupIntrPending function can be called
 *  to return a bit-mask of the raw or masked interrupt status for all 32
 *  interrupts in a group.
 *
 *  There are two types of pending interrupts that can be queried:
 *  CSL_VIM_INTR_MAP_IRQ or CSL_VIM_INTR_MAP_FIQ (see #CSL_VimIntrMap).
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrMap      [IN]    Type of interrupt to query (see #CSL_VimIntrMap)
 *
 *  \return  A 32-bit mask indicates which groups of interrupts have pending, unmasked interrupts
 */
uint32_t CSL_vimGetGroupsIntrPending( CSL_vimRegs *pRegs, CSL_VimIntrMap intrMap );

/**
 *  \brief Get bit-mask of raw or masked interrupt status for all interrupts
 *         within a group
 *
 *  This function returns a 32-bit mask of the raw or masked interrupt status
 *  for all interrupts within the specified interrupt group, where bit # N in
 *  the mask indicates the pending interrupt status for interrupt source
 *  (32*groupNum)+N (0 = no interrupt pending, 1 = interrupt is pending).
 *
 *  The #CSL_vimGetGroupsIntrPending function can be called to return a
 *  bit-mask of the masked interrupt status for all 32 interrupt groups.
 *
 *  If bMasked is false, the raw interrupt status is returned. If bMasked is
 *  true, then intrMap determines the type of masked interrupt status
 *  returned as follows:
 *      CSL_VIM_INTR_MAP_IRQ = Masked IRQ interrupt status
 *      CSL_VIM_INTR_MAP_FIQ = Masked FIQ interrupt status
 *      CSL_VIM_INTR_MAP_ALL = Masked IRQ and FIQ interrupt status
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrMap      [IN]    Type of interrupt to query (see #CSL_VimIntrMap)
 *  \param groupNum     [IN]    Interrupt group number (0..31)
 *  \param bMasked      [IN]    false = return raw interrupt status
 *                              true  = return masked interrupt status
 *
 *  \return A 32-bit mask of the raw or masked interrupt status for all
 *          interrupts within the group specified by groupNum
 */
uint32_t CSL_vimGetGroupIntrPending(
                                                  CSL_vimRegs   *pRegs,
                                                  CSL_VimIntrMap intrMap,
                                                  uint32_t       groupNum,
                                                  bool           bMasked
);

/**
 *  \brief Set the raw interrupt status bit for the specified interrupt
 *
 *  This function forcibly sets the raw interrupt status bit for the specified
 *  interrupt number.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *
 *  \return  0 = success
 *          -1 = intrNum is out of range
 */
int32_t CSL_vimSetIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum );

/**
 *  \brief Clear the raw interrupt status bit for the specified interrupt
 *
 *  This function clears the raw interrupt status bit for the specified
 *  interrupt number.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *
 *  \return  0 = success
 *          -1 = intrNum is out of range
 */
int32_t CSL_vimClrIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum );

/**
 *  \brief Acknowledge servicing is complete for the specified interrupt type
 *
 *  The function is used to acknowlege that the specified interrupt type has been
 *  serviced. The VIM will then re-evaluate the new highest priority interrupt.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrMap      [IN]    Interrupt map type (see #CSL_VimIntrMap)
 *
 *  \return  0 = success
 *          -1 = intrMap is out of range
 */
int32_t CSL_vimAckIntr( CSL_vimRegs *pRegs, CSL_VimIntrMap intrMap );

/**
 *  \brief Enable or disable interrupt status mask for the specified interrupt
 *
 *  The function is used to enable or disable the interrupt status mask for the
 *  specified interrupt. Interrupt sources with an enabled mask are used in the
 *  generation of the output IRQ or FIQ interrupt. Interrupt sources with a
 *  disabled mask are not used in the generation of the output IRQ or FIQ
 *  interrupt.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param intrNum      [IN]    Interrupt number (0..#CSL_vimGetNumIntrs()-1)
 *  \param bEnable      [IN]    false = disable interrupt status mask
 *                              true  = enable interrupt status mask
 *
 *  \return  0 = success
 *          -1 = intrNum is out of range
 */
int32_t CSL_vimSetIntrEnable( CSL_vimRegs *pRegs, uint32_t intrNum, bool bEnable );

/**
 *  \brief Read back of static registers for VIM
 *
 *  The function is used to acknowlege that the specified interrupt type has been
 *  serviced. The VIM will then re-evaluate the new highest priority interrupt.
 *
 *  \param pRegs        [IN]    Pointer to the CSL_vimRegs register structure
 *  \param pStaticRegs  [IN]    Pointer to the CSL_vimStaticRegs structure to hold
 *                              the static register values
 *                              The static register set is defined to be the list
 *                              of registers that hardware does not update by itself
 *
 *  \return  0 = success
 *          -1 = failure (could not read back the static registers)
 */
int32_t CSL_vimReadBackStaticRegs( CSL_vimRegs *pRegs, CSL_vimStaticRegs *pStaticRegs);

/* @} */

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif  /* end of CSL_VIM_H_ definition */
