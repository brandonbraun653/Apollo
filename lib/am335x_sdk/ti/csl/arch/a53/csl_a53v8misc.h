#ifndef _CSL_a53v8H_
#define _CSL_a53v8H_

/**
 *  @file csl_misc.h
 *
 *  @brief
 *     ARM Misc Instructions
 *  \par
 *   ================================================================================
 *
 *   @n   (C)  Copyright 2015 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *      Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *      Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the
 *      distribution.
 *
 *      Neither the name of Texas Instruments Incorporated nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
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
 *  Code derived from ARM LTD examples and documentation found in the
 *  following documents.
 *
 *  ARM® Cortex® -A53 MPCore Processor
 *  Revision: r0p4
 *  Technical Reference Manual
 *
 *  ARM® Architecture Reference Manual
 *  ARMv8, for ARMv8-A architecture profile
 *  Beta
 */


    #include <stdint.h>
    #include <stdbool.h>
    #include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

    /** ===========================================================================
     *
     * @defgroup CSL_a53v8API (ARM64 Data/MMU Functions)
     * @ingroup CSL_a53v8API
     *
     * @section Introduction
     *
     * @subsection xxx Overview
     *
     * @subsection References
     *    -# ARM Functional Specification
     * ============================================================================
     */

    /**
       @defgroup CSL_a53v8_DATASTRUCT ARM 64 Bit Data/MMU Data Structures
       @ingroup CSL_a53v8API
    */
    /**
       @defgroup CSL_a53v8_FUNCTION ARM 64 Bit Data/MMU Functions
       @ingroup CSL_a53v8API
    */
    /**
       @defgroup CSL_a53v8_ENUM ARM 64 Bit Data/MMU Enumerated Data Types
       @ingroup CSL_a53v8API
    */



    /** ==========================================================================
        @addtogroup CSL_a53v8FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53v8DmbIsHld
     *
     * @b Description
     * @n  Data Memory Barrier Inner Sharable Load/Store
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DmbIsHld();
     * @endverbatim
     */


    void CSL_a53v8DmbIsHld();


    /** ==========================================================================
        @addtogroup CSL_a53v8FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53v8DmbIsHst
     *
     * @b Description
     * @n  Data Memory Barrier Inner Sharable Load/Store
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DmbIsHst();
     * @endverbatim
     */


    void CSL_a53v8DmbIsHst();




    /**
     * @n@b CSL_a53v8DmbOsHld
     *
     * @b Description
     * @n  Data Memory Barrier Outer Sharable Load/Store
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DmbOsHld();
     * @endverbatim
     */


    void CSL_a53v8DmbOsHld();






    /**
     * @n@b CSL_a53v8DmbNsHld
     *
     * @b Description
     * @n  Data Memory Barrier Non-Sharable Load/Store
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DmbNsHld();
     * @endverbatim
     */


    void CSL_a53v8DmbNsHld();






    /**
     * @n@b CSL_a53v8DmbLd
     *
     * @b Description
     * @n  Data Barrier Full System Load
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DmbLd();
     * @endverbatim
     */


    void CSL_a53v8DmbLd();






    /**
     * @n@b  CSL_a53v8DsbIsHld
     *
     * @b Description
     * @n  Data Barrier Innner Shareable Load
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DsbIsHld();
     * @endverbatim
     */


    void CSL_a53v8DsbIsHld();








    /**
     * @n@b CSL_a53v8DsbOsHld
     *
     * @b Description
     * @n  Data Barrier Outer Sharable Load
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DsbOsHld();
     * @endverbatim
     */


    void CSL_a53v8DsbOsHld();








    /**
     * @n@b CSL_a53v8DsbNdsHld
     *
     * @b Description
     * @n  Data Barrier Non-Sharable Load
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DsbNdsHld();
     * @endverbatim
     */


    void CSL_a53v8DsbNdsHld();







    /**
     * @n@b CSL_a53v8DsbLd
     *
     * @b Description
     * @n Data Memory Barrier Shareable System Load
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DsbLd();
     * @endverbatim
     */


    void CSL_a53v8DsbLd();









    /**
     * @n@b CSL_a53v8DsbSy
     *
     * @b Description
     * @n  Data Barrier System All
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8DsbSy();
     * @endverbatim
     */


    void CSL_a53v8DsbSy();







    /**
     * @n@b CSL_a53v8Isb
     *
     * @b Description
     * @n  Instruction Barrier
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8Isb();
     * @endverbatim
     */


    void CSL_a53v8Isb();


   /** ==========================================================================
        @addtogroup CSL_a53v8FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53v8WFI
     *
     * @b Description
     * @n  Instruction Barrier
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   CSL_a53v8WFI();
     * @endverbatim
     */

    /** @} */
    void CSL_a53v8WFI();








    /**
     * @n@b CSL_a53v8GetCpuId
     *
     * @b Description
     * @n  Returns the CPU ID value cluster.corepac.cpu
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   cpuid = CSL_a53v8GetCpuId();
     * @endverbatim
     */


    uint64_t CSL_a53v8GetCpuId();








    /**
     * @n@b CSL_a53v8WriteTtbr0El3
     *
     * @b Description
     * @n  Writes the page table location for EL3 to the TTBR0 Register
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   cpuid = CSL_a53v8_writeTtbr0El3(pagebase);
     * @endverbatim
     */


    void CSL_a53v8WriteTtbr0El3();







    /**
     * @n@b CSL_a53v8WriteTtbr0El2
     *
     * @b Description
     * @n  Writes the page table location for EL2 to the TTBR0 Register
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   cpuid = CSL_a53v8WriteTtbr0El2(pagebase);
     * @endverbatim
     */


    void CSL_a53v8WriteTtbr0El2();







    /**
     * @n@b CSL_a53v8WriteTtbr0El1
     *
     * @b Description
     * @n  Writes the page table location for EL1 to the TTBR0 Register
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   cpuid = CSL_a53v8WriteTtbr0El1(pagebase);
     * @endverbatim
     */


    void CSL_a53v8WriteTtbr0El1(uintptr_t tableAddr);



    /**
     * @n@b CSL_a53v8WriteTCREL1
     *
     * @b Description
     * @n  Writes the tcr value passed to TCR_EL1 Register
     *
     *
     *
     * @b Arguments
     * @n  tcr
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *   uint64_t tcr = <value>;
     *   CSL_a53v8WriteTCREL1(tcr);
     * @endverbatim
     */


    void CSL_a53v8WriteTCREL1(uint64_t tcr);

    /**
    * @n@b CSL_a53v8WriteTCREL1
    *
    * @b Description
    * @n  Writes the tcr value passed to TCR_EL1 Register
    *
    *
    *
    * @b Arguments
    * @n  tcr
    *
    * <b> Return Value </b>
    * @n None
    *
    * <b> Pre Condition </b>
    * @n None
    *
    * <b> Post Condition </n>
    * @n None
    *
    * @b Reads
    * @n None
    *
    * @b Example
    * @verbatim
    *   uint64_t tcr = <value>;
    *   CSL_a53v8WriteTCREL1(tcr);
    * @endverbatim
    */

    void CSL_a53v8WriteTCREL3(uint64_t tcr);





    /**
     * @n@b CSL_a53v8SwitchLevelEl3toEl2
     *
     * @b Description
     * @n  Changes the Exception Level from EL3 to El2
     *
     *
     *
     * @b Arguments
     * @n  uint64_t        el2entry
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el2entry;

     cpuid = CSL_a53v8SwitchLevelEl3toEl2(el2entry);
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl3toEl2(uint64_t el2entry);








    /**
     * @n@b CSL_a53v8SwitchLevelEl3toNsEl1
     *
     * @b Description
     * @n  Changes Exception Level from El3 to Non-Secure EL1
     *
     *
     *
     * @b Arguments
     * @n uint64_t     el1entry
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el1entry;

     cpuid = CSL_a53v8SwitchLevelEl3toNsEl1(el1entry);
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl3toNsEl1(uint64_t el1entry);







    /**
     * @n@b CSL_a53v8SwitchLevelEl3toSEl1
     *
     * @b Description
     * @n  Changes Exception Level from El3 to Secure EL1
     *
     *
     *
     * @b Arguments
     * @n uint64_t     el1entry
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el1entry;

     cpuid = CSL_a53v8SwitchLevelEl3toSEl1(el1entry);
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl3toSEl1(uint64_t el0entry);









    /**
     * @n@b CSL_a53v8SwitchLevelEl3toNsEl0
     *
     * @b Description
     * @n  Changes Exception Level from El3 to Non-Secure EL0
     *
     *
     *
     * @b Arguments
     * @n uint64_t     el0entry
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el0entry;

     cpuid = CSL_a53v8SwitchLevelEl3toNsEl0(el0entry);
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl3toNsEl0(uint64_t el0entry);









    /**
     * @n@b CSL_a53v8SwitchLevelEl3toSEl0
     *
     * @b Description
     * @n  Changes Exception Level from El3 to Secure EL0
     *
     *
     *
     * @b Arguments
     * @n uint64_t     el0entry
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el0entry;

     cpuid = CSL_a53v8SwitchLevelEl3toSEl0(el0entry);
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl3toSEl0(uint64_t el1entry);








    /**
     * @n@b CSL_a53v8SwitchLevelEl3
     *
     * @b Description
     * @n  Changes Exception Level to EL3
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el0entry;

     cpuid = CSL_a53v8SwitchLeveltoEl3();
     * @endverbatim
     */


    void CSL_a53v8SwitchLeveltoEl3();




    /**
     * @n@b CSL_a53v8SwitchLevelEl0toEl3
     *
     * @b Description
     * @n  Changes Exception Level from EL0 to EL3
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el0entry;

     cpuid = CSL_a53v8SwitchLevelEl0toEl3();
     * @endverbatim
     */


    void CSL_a53v8SwitchLevelEl0toEl3();








    /**
     * @n@b CSL_a53v8SwitchLevelEl2
     *
     * @b Description
     * @n  Changes Exception Level to EL2
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     el0entry;

     cpuid = CSL_a53v8SwitchLeveltoEl2();
     * @endverbatim
     */


    void CSL_a53v8SwitchLeveltoEl2();







    /**
     * @n@b CSL_a53v8GetCurrentEl
     *
     * @b Description
     * @n  Returns the Current EL Level
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n uint64_t      currentel
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t     currentel;

     currentel = CSL_a53v8GetCurrentEl();
     * @endverbatim
     */

    uint64_t CSL_a53v8GetCurrentEl();


    /**
     * @n@b CSL_a53v8ArmGicv3HwiDisable
     *
     * @b Description
     * @n  disables the hardware interrupts for GIC v3
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n returns the previous value of CPSR
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t key;
     key = CSL_a53v8ArmGicv3HwiDisable();
     * @endverbatim
     */

    uint64_t CSL_a53v8ArmGicv3HwiDisable(void);

    /**
     * @n@b CSL_a53v8ArmGicv3HwiEnable
     *
     * @b Description
     * @n  Enables the hardware interrupts for GIC v3
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n returns the previous value of CPSR
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t key;
     key = CSL_a53v8ArmGicv3HwiEnable();
     * @endverbatim
     */

    uint64_t CSL_a53v8ArmGicv3HwiEnable(void);

    /**
     * @n@b CSL_a53v8ArmGicv3HwiRestore
     *
     * @b Description
     * @n  Restores the hardware interrupts for GIC v3
     *
     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     uint64_t key;
     key = CSL_a53v8ArmGicv3HwiDisable();
     CSL_a53v8ArmGicv3HwiRestore(key);
     * @endverbatim
     */

    void CSL_a53v8ArmGicv3HwiRestore(uint64_t key);

    /**
     * @n@b CSL_a53Exit
     *
     * @b Description
     * @n  Baremetal Exit function called from startup after return
     *     from main()
     *     This function spins in a loop waiting for system reset/power cycle
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * CSL_a53Exit();
     * @endverbatim
     */

     void  CSL_a53Exit(void);

/* NUM_LEVEL1_ENTRIES */
#define CSL_a53Mmu_NUM_LEVEL1_ENTRIES (512U)

/**
  * @brief MMU descriptor types
  */
enum CSL_a53MmuDescType {
    CSL_a53Mmu_DescType_INVALID0 = 0u,
    CSL_a53Mmu_DescType_BLOCK = 1u,
    CSL_a53Mmu_DescType_INVALID1 = 2u,
    CSL_a53Mmu_DescType_TABLE = 3u
};

typedef enum CSL_a53MmuDescType CSL_a53MmuDescType;

/**
  * @brief MMU DescriptorAttrs
  */
typedef struct CSL_A53MmuDescAttrs_s {
    CSL_a53MmuDescType type;
    Bool nsTable;
    uint8_t apTable;
    Bool xnTable;
    Bool pxnTable;
    Bool noExecute;
    Bool privNoExecute;
    Bool contiguous;
    Bool notGlobal;
    Bool accessFlag;
    uint8_t shareable;
    uint8_t accPerm;
    Bool nonSecure;
    uint8_t attrIndx;
    uint8_t reserved;
}CSL_a53MmuDescAttrs;


    /** @} */

#ifdef __cplusplus
}
#endif

#endif             /* end of _CSL_ARMCACHE64_H_ definition */
