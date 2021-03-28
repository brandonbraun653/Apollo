#ifndef CSL_ARMCACHE64_H_
#define CSL_ARMCACHE64_H_

/**
 *  @file csl_armcache64.h
 *
 *  @brief
 *     ARM Cache Maintainence Operations
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

#ifdef __cplusplus
extern "C" {
#endif

    /** ===========================================================================
     *
     * @defgroup CSL_a53v8_API (ARM64 CACHE)
     * @ingroup CSL_ARMCAHCE64_API
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
       @defgroup CSL_a53v8_DATASTRUCT ARM 64 Bit Mode Cache Data Structures
       @ingroup CSL_a53v8_API
    */
    /**
       @defgroup CSL_a53v8_FUNCTION ARM 64 Bit Mode Cache Functions
       @ingroup CSL_a53v8_API
    */
    /**
       @defgroup CSL_a53v8_ENUM ARM 64 Bit Mode Cache Enumerated Data Types
       @ingroup CSL_a53v8_API
    */

    /*Defines */
#define CLIDR_EL1_CTYPE_NOCACHE              (0U)
#define CLIDR_EL1_CTYPE_ICACHE               (1U)
#define CLIDR_EL1_CTYPE_DCACHE               (2U)
#define CLIDR_EL1_CTYPE_IDCACHE              (3U)
#define CLIDR_EL1_CTYPE_UCACHE               (4U)



    /*Function Prototypes */

    /** ==========================================================================
        @addtogroup CSL_a53v8_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_a53v8EnableInstEl1
     *
     * @b Description
     * @n  Enable the Instruction Cache in SCTLR_EL1
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
     *   CSL_a53v8EnableInstEl1();
     * @endverbatim
     */



    void CSL_a53v8EnableInstEl1();
    /** ==========================================================================
        @addtogroup CSL_a53v8_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_a53v8EnableInstEl2
     *
     * @b Description
     * @n  Enable the Instruction Cache in SCTLR_EL2
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
     * CSL_ARMCACH64EnableInstSctlrEL2();
     * @endverbatim
     */


    void CSL_a53v8EnableInstEl2();


    /**
     * @n@b  CSL_a53v8EnableInstEl3
     *
     * @b Description
     * @n Enable the Instruction Cache in SCTLR_EL3
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
     * CSL_a53v8EnableInstEl3();
     * @endverbatim
     */


    void CSL_a53v8EnableInstEl3();


    /**
     * @n@b  CSL_a53v8DisableInstEL1
     *
     * @b Description
     * @n Disable the Instruction Cache in SCTLR_EL1
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
     * CSL_a53v8DisableInstEl1();
     * @endverbatim
     */


    void CSL_a53v8DisableInstEl1();


    /**
     * @n@b  CSL_a53v8DisableInstEl2
     *
     * @b Description
     * @n Disable the Instruction Cache in SCTLR_EL2
     *
     *
     *
     * @b Arguments
     * @n
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
     * CSL_a53v8DisableInstEl2();
     * @endverbatim
     */


    void CSL_a53v8DisableInstEl2();






    /**
     * @n@b  CSL_a53v8DisableInstEl3
     *
     * @b Description
     * @n Disable the Instruction Cache in SCTLR_EL3
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
     * CSL_a53v8DisableInstEl3();
     * @endverbatim
     */


    void CSL_a53v8DisableInstEl3();






    /**
     * @n@b  CSL_a53v8EnableDcacheEl1
     *
     * @b Description
     * @n Enables Data Cache in SCTLR_EL1
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
     * CSL_a53v8EnableDcacheEl1();
     * @endverbatim
     */


    void CSL_a53v8EnableDcacheEl1();






    /**
     * @n@b  CSL_a53v8EnableDcacheEl2
     *
     * @b Description
     * @n Enable the Data Cache in SCTLR_EL2
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
     * CSL_a53v8EnableDcacheEl2();
     * @endverbatim
     */


    void CSL_a53v8EnableDcacheEl2();






    /**
     * @n@b  CSL_a53v8EnableDcacheEl3
     *
     * @b Description
     * @n Enable the Data Cache in SCTLR_EL3
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
     * CSL_a53v8EnableDcacheEl3();
     * @endverbatim
     */


    void CSL_a53v8EnableDcacheEl3();






    /**
     * @n@b  CSL_a53v8DisableDcacheEL1
     *
     * @b Description
     * @n Disable the Data Cache in SCTLR_EL1
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
     * CSL_a53v8DisableDcacheEL1();
     * @endverbatim
     */



     void CSL_a53v8DisableDcacheEl1();







    /**
     * @n@b  CSL_a53v8DisableDcacheEl2
     *
     * @b Description
     * @n Disable the Data Cache in SCTLR_EL2
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
     * CSL_a53v8DisableDcacheEl2();
     * @endverbatim
     */


    void CSL_a53v8DisableDcacheEl2();






    /**
     * @n@b  CSL_a53v8DisableDcacheEl3
     *
     * @b Description
     * @n Disable the Data Cache SCTLR_EL3
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
     * CSL_a53v8DisableDcacheEl3();
     * @endverbatim
     */


    void CSL_a53v8DisableDcacheEl3();






    /**
     * @n@b  CSL_a53v8EnableMmuEL1
     *
     * @b Description
     * @n Enable the MMU in SCTLR_EL1
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
     * CSL_a53v8EnableMmuEL1();
     * @endverbatim
     */


    void CSL_a53v8EnableMmuEL1();






    /**
     * @n@b  CSL_a53v8EnableMmuEl2
     *
     * @b Description
     * @n Enable the MMU in SCTLR_EL2
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
     * CSL_a53v8EnableMmuEl2();
     * @endverbatim
     */


    void CSL_a53v8EnableMmuEl2();






    /**
     * @n@b  CSL_a53v8EnableMmuEl3
     *
     * @b Description
     * @n Enable the MMU in SCTLR_EL3
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
     * CSL_a53v8EnableMmuEl3();
     * @endverbatim
     */


    void CSL_a53v8EnableMmuEl3();






    /**
     * @n@b  CSL_a53v8DisableMmuEL1
     *
     * @b Description
     * @n Disable the MMU in  SCTLR_EL1
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
     * CSL_a53v8DisableMmuEL1();
     * @endverbatim
     */


    void CSL_a53v8DisableMmuEL1();






    /**
     * @n@b  CSL_a53v8DisableMmuEl2
     *
     * @b Description
     * @n Disable the MMU in SCTLR_EL2
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
     * CSL_a53v8DisableMmuEl2();
     * @endverbatim
     */


    void CSL_a53v8DisableMmuEl2();






    /**
     * @n@b  CSL_a53v8DisableMmuEl3
     *
     * @b Description
     * @n Disable the MMU in SCTLR_EL3
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
     * CSL_a53v8DisableMmuEl3();
     * @endverbatim
     */


    void CSL_a53v8DisableMmuEl3();






    /**
     * @n@b  CSL_a53v8DisableMmuEl3
     *
     * @b Description
     * @n Disable the MMU in SCTLR_EL3
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
     * CSL_a53v8DisableDataCoherency();
     * @endverbatim
     */

    /** @} */
    void CSL_a53v8DisableDataCoherency();



    /**
     * @n@b  CSL_a53v8EnableMmuEl3
     *
     * @b Description
     * @n Enable Cache Coherency in CPUECTLR_EL1
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
     * CSL_a53v8EnableDataCoherency();
     * @endverbatim
     */

    /** @} */
    void CSL_a53v8EnableDataCoherency();


    /** ==========================================================================
        @addtogroup CSL_a53v8_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_a53v8CleanDcacheSetWay
     *
     * @b Description
     * @n Clean the DCache by Set/Way
     *
     *
     *
     * @b Arguments
     * @n
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
     * uint64_t         setway;
     *
     * CSL_a53v8CleanDcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53v8CleanDcacheSetWay(uint64_t setway);






    /**
     * @n@b  CSL_a53v8CleanDcacheMva
     *
     * @b Description
     * @n This function writes out the data needed for a TR to the monitor
     *
     *
     *
     * @b Arguments
     * @n
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
     * @endverbatim
     */


    void CSL_a53v8CleanDcacheMva(uint64_t mva);






    /**
     * @n@b  CSL_a53v8CleanDcacheLineSetWay
     *
     * @b Description
     * @n Clean the DCache Line by Set/Way
     *
     *
     *
     * @b Arguments
     * @n  setway
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
     * uint64_t             setway;
     *
     * CSL_a53v8CleanDcacheLineSetWay
     * @endverbatim
     */


    void CSL_ARMCACH64CleanDcacheLineSetWay(uint64_t setway);






    /**
     * @n@b  CSL_a53v8CleanDcacheMvaPoC
     *
     * @b Description
     * @n Clean the Dcache Line by Virtual Address to Pont of Coherence
     *
     *
     *
     * @b Arguments
     * @n  mva   -  virtual address
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
     * uint64_t         mva;
     *
     * CSL_a53v8CleanDcacheMvaPoC(mva);
     * @endverbatim
     */


    void CSL_a53v8CleanDcacheMvaPoC(uint64_t mva);






    /**
     * @n@b  CSL_a53v8CleanDcacheMvaPoU
     *
     * @b Description
     * @n Clean Dcache Line by Virtual Address to Point of Unification
     *
     *
     *
     * @b Arguments
     * @n  mva            - virtual address
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
     * uint64_t               mva;
     *
     *CSL_a53v8CleanDcacheMvaPoU(mva);
     * @endverbatim
     */



    void CSL_a53v8CleanDcacheMvaPoU(uint64_t mva);






    /**
     * @n@b  CSL_a53v8InvalidateDcacheSetWay
     *
     * @b Description
     * @n Invalidate Data Cache Line by Set/Way
     *
     *
     *
     * @b Arguments
     * @n
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
     * uint64_t     setway;
     *
     * CSL_a53v8InvalidateDcacheSetWay(setway);
     *
     * @endverbatim
     */



    void CSL_a53v8InvalidateDcacheSetWay(uint64_t setway);






    /**
     * @n@b  CSL_a53v8CleanInvalidateDcacheMvaPoC
     *
     * @b Description
     * @n Invalidate Data Cache Line by Virtual Address to Point of Coherence
     *
     *
     *
     * @b Arguments
     * @n  mva   -     virtual address
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
     * uint64_t      mva;
     *
     * CSL_a53v8CleanInvalidateDcacheMvaPoC(mva);
     *
     * @endverbatim
     */



    void CSL_a53v8CleanInvalidateDcacheMvaPoC(uint64_t mva);



   /**
     * @n@b  CSL_a53v8InvalidateDcacheMvaPoC
     *
     * @b Description
     * @n Invalidate Data Cache Line by Virtual Address to Point of Coherence
     *
     *
     *
     * @b Arguments
     * @n  mva   -     virtual address
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
     * uint64_t      mva;
     *
     * CSL_a53v8InvalidateDcacheLineMvaPoC(mva);
     *
     * @endverbatim
     */



    void CSL_a53v8InvalidateDcacheMvaPoC(uint64_t mva);






    /**
     * @n@b  CSL_a53v8_zeroDcaheMva
     *
     * @b Description
     * @n This function writes out the data needed for a TR to the monitor
     *
     *
     *
     * @b Arguments
     * @n  mva          -     virtual address
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
     * uint64_t      mva;
     *
     * CSL_a53v8_zeroDcaheMva(mva);
     *
     * @endverbatim
     */



    void CSL_a53v8_zeroDcaheMva(uint64_t mva);






    /**
     * @n@b  CSL_a53v8InvalidateIcacheAllPoU
     *
     * @b Description
     * @n Invalidate Instruction Cache All Lines to Point of Unification
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
     *
     * CSL_a53v8InvalidateIcacheAllPoU();
     *
     * @endverbatim
     */



    void CSL_a53v8InvalidateIcacheAllPoU();






    /**
     * @n@b  CSL_a53v8InvalidateIcacheAllPoUIs
     *
     * @b Description
     * @n This function writes out the data needed for a TR to the monitor
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
     *
     * CSL_a53v8InvalidateIcacheAllPoUIs();
     *
     * @endverbatim
     */



    void CSL_a53v8InvalidateIcacheAllPoUIs();






    /**
     * @n@b  CSL_a53v8InvalidateIcacheLineMvaPoU
     *
     * @b Description
     * @n Invalidate Instruction Cache Line by Virtual Address to Point of Unification
     *
     *
     *
     * @b Arguments
     * @n  mva        -     Virtual Address
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
     * uint64_t        mva;
     *
     * CSL_a53v8InvalidateIcacheLineMvaPoU(mva);
     *
     * @endverbatim
     */



    void CSL_a53v8InvalidateIcacheLineMvaPoU(uint64_t mva);






    /**
     * @n@b  CSL_a53v8InvalidateDcache
     *
     * @b Description
     * @n Invalidate Data Cache
     *
     *
     *
     * @b Arguments
     * @n  uint64_t cache num
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
     * uint64_t        mva;
     *
     * CSL_a53v8InvalidateDcache(cache_num);
     *
     * @endverbatim
     */

    /** @} */

    void CSL_a53v8InvalidateDcache(uint64_t cache_num);


    /** ==========================================================================
        @addtogroup CSL_a53v8_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_a53v8InitIDCacheMmuEl1
     *
     * @b Description
     * @n Initializes Instruction and Data Caches and MMU for EL1
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
     *
     * uint64_t        mva;
     *
     * CSL_a53v8InitIDCacheMmuEl1();
     *
     * @endverbatim
     */



    void CSL_a53v8InitIDCacheMmuEl1();






    /**
     * @n@b  CSL_a53v8InitIDCacheMmuEl2
     *
     * @b Description
     * @n Initializes Instruction and Data Caches and MMU for EL2
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
     *
     * uint64_t        mva;
     *
     * CSL_a53v8InitIDCacheMmuEl2();
     *
     * @endverbatim
     */



    void CSL_a53v8InitIDCacheMmuEl2();






    /**
     * @n@b  CSL_a53v8InitIDCacheMmuEl3
     *
     * @b Description
     * @n Initializes Instruction and Data Caches and MMU for EL3
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
     *
     * uint64_t        mva;
     *
     * CSL_a53v8InitIDCacheMmuEl3();
     *
     * @endverbatim
     */



    void CSL_a53v8InitIDCacheMmuEl3();






    /**
     * @n@b  CSL_a53v8EnableMairEl3
     *
     * @b Description
     * @n Programs the MAIR Register for EL3 With SetTransaction Types
     * @n           Attribute 0 = 0
     * @n           Attribute 1 = 1
     * @n           Attribute 2 = 2
     * @n           Attribute 3 = 3
     * @n           Attribute 4 = 4
     * @n           Attribute 5 = 5
     * @n           Attribute 6 = 6
     * @n           Attribute 7 = 7
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
     * @n External Variable is Set for TTBR3_BASE_ADDR
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
     *
     * CSL_a53v8EnableMairEl3();
     *
     * @endverbatim
     */



    void CSL_a53v8EnableMairEl3();







    /**
     * @n@b  CSL_a53v8_enabeMairEl2
     *
     * @b Description
     * @n Programs the MAIR Register for EL2 With SetTransaction Types
     * @n           Attribute 0 = 0
     * @n           Attribute 1 = 1
     * @n           Attribute 2 = 2
     * @n           Attribute 3 = 3
     * @n           Attribute 4 = 4
     * @n           Attribute 5 = 5
     * @n           Attribute 6 = 6
     * @n           Attribute 7 = 7
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
     * @n External Variable is Set for TTBR2_BASE_ADDR
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
     *
     * CSL_a53v8EnableMairEl2();
     *
     * @endverbatim
     */



    void CSL_a53v8EnableMairEl2();






    /**
     * @n@b  CSL_a53v8_enabeMairEl1
     *
     * @b Description
     * @n Programs the MAIR Register for EL1 With SetTransaction Types
     * @n           Attribute 0 = 0
     * @n           Attribute 1 = 1
     * @n           Attribute 2 = 2
     * @n           Attribute 3 = 3
     * @n           Attribute 4 = 4
     * @n           Attribute 5 = 5
     * @n           Attribute 6 = 6
     * @n           Attribute 7 = 7
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
     * @n External Variable is Set for TTBR1_BASE_ADDR
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
     *
     * CSL_a53v8EnableMairEl1();
     *
     * @endverbatim
     */



    void CSL_a53v8EnableMairEl1();







    /**
     * @n@b  CSL_a53v8_enabeCohCpuEctrlEl1
     *
     * @b Description
     * @n Programs the MAIR Register for EL1 With SetTransaction Types

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
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint64_t        mva;
     *
     * CSL_a53v8EnableCohCpuEctrlEl1();
     *
     * @endverbatim
     */



    void CSL_a53v8EnableCpuEctrlEl1();








    /**
     * @n@b  CSL_a53v8GetCacheLevelId
     *
     * @b Description
     * @n Fetches the Contents of the Cache Level ID Register

     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint32_t   Cache Level ID Register Contents (D8.2.15 ARM Beta)
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint32_t        CacheLevelID;
     *
     * CacheLevelID = CSL_a53v8GetCacheLevelId();
     *
     * @endverbatim
     */



    uint32_t CSL_a53v8GetCacheLevelId();









    /**
     * @n@b  CSL_a53v8SetCacheLevelInD
     *
     * @b Description
     * @n Selects Cache Level and Cache Type (D8.2.20 ARM Beta)

     *
     *
     * @b Arguments
     * @n  LevelInD   -   concationation of {Level,InD} [3:1,0]
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint32_t        Level;
     * uint32_t        InD
     * uint32_t        LevelInD;
     *
     * LevelInD = (Level << 1) | InD;
     *
     * CacheLevelID = CSL_a53v8SetCacheLevelInD(LevelInD);
     *
     * @endverbatim
     */



    void CSL_a53v8SetCacheLevelInD(uint32_t LevelInD);








    /**
     * @n@b  CSL_a53v8GetCacheLevelInD
     *
     * @b Description
     * @n Reads Cache Level and Cache Type (D8.2.20 ARM Beta)

     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n  LevelInD   -   concationation of {Level,InD} [3:1,0]
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint32_t        Level;
     * uint32_t        InD
     * uint32_t        LevelInD;
     *
     *
     * CacheLevelID = CSL_a53v8GetCacheLevelInD();
     *
     * Level = (LevelInD & 0x0000000EU) >> 1;
     * InD = LevelInD & 0x00000001U;
     *
     * @endverbatim
     */



    uint32_t CSL_a53v8GetCacheLevelInD();








    /**
     * @n@b  CSL_a53v8GetCurrentCacheSize
     *
     * @b Description
     * @n Reads the Current Cache Size (NumSets,Associativity,LineSize)

     *
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n  CurrCachSz     -   concationation of {WT,WB,RA,WA,NumSets,Associtivit,LineSize}
     * @n                                            31,30,29,28, 27:13 ,    12:3   ,  2:0
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint8_t         Modes
     * uint16_t        NumSets
     * uint16_t        Assoc
     * uint8_t         LineSize
     * uint32_t        CurrCachSz
     *
     *
     * CurrCachSz = CSL_a53v8GetCurrentCacheSize();
     *
     * Modes = (CurrCachSz & 0xF0000000U) >> 28;
     * NumSets = (CurrCachSz & 0x0FFFE000U) >> 13;
     * Assoc = (CurrCachSz & 0x00001FF8U) >> 3;
     * LineSize = (CurrCachSz & 0x00000007U);
     *
     * @endverbatim
     */



    uint32_t CSL_a53v8GetCurrentCacheSize();









    /**
     * @n@b  CSL_a53v8InvalidateCacheLevelType
     *
     * @b Description
     * @n Invalidates cache based upon type and level for all set/way values

     *
     *
     * @b Arguments
     * @n level           -      Cache level from 1 to 7
     * @n type            -      Cache type 0 = none, 001 i only, 010 d only 011 separate i and d 100 unified
     *
     * <b> Return Value </b>
     * @n  success        - 1 if cache exists, 0 if it does not exist
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint8_t         level
     * uint8_t         type
     * uint8_t         success
     *
     *
     * success = CSL_a53v8InvalidateCacheLevelType(level,type);
     *
     *
     * @endverbatim
     */



    uint32_t CSL_a53v8InvalidateCacheLevelType(uint8_t level, uint8_t type);








    /**
     * @n@b  CSL_a53v8FindNumLeadZeros
     *
     * @b Description
     * @n Finds the number of leading 0s in a 32 bit value, for Cache Maintainence computation

     *
     *
     * @b Arguments
     * @n uint32_t param    -     Reference value

     *
     * <b> Return Value </b>
     * @n uint32_t count   -      Number of leading 0s in 32 data value
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint32_t        param;
     * uint32_t        zerocount;
     *
     *
     * zerocount = CSL_a53v8_findNumLeadZeros(param);
     *
     *
     * @endverbatim
     */


    uint32_t CSL_a53v8FindNumLeadZeros(uint32_t param);


    /**
     * @n@b  CSL_a53v8EnableMMUEl1
     *
     * @b Description
     * @n Enables the MMU for Execution level 1
     *
     *
     * @b Arguments
     * @n none

     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *
     *
     * CSL_a53v8EnableMMUEl1(void);
     *
     *
     * @endverbatim
     */

    void CSL_a53v8EnableMMUEl1(void);


    /**
     * @n@b  CSL_a53v8SetMAIR
     *
     * @b Description
     * @n Sets MAIR for EL1
     *
     *
     * @b Arguments
     * @n idx             -      MAIR index
     * @n attr            -      attributes
     *
     * <b> Return Value </b>
     * @n  None
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint8_t         idx;
     * uint16_t        attr;
     *
     *
     * CSL_a53v8SetMAIR(level,type);
     *
     *
     * @endverbatim
     */


    void CSL_a53v8SetMAIR(uint8_t idx, uint16_t attr);

    /**
     * @n@b  CSL_a53v8InvTLB
     *
     * @b Description
     * @n Invalidates the MMU TLB
     *
     *
     * @b Arguments
     * @n none
     *
     * <b> Return Value </b>
     * @n  None
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *
     * CSL_a53v8InvTLB();
     *
     *
     * @endverbatim
     */


    void CSL_a53v8InvTLB(void);


    /**
     * @n@b  CSL_a53v8SetMAIREL3
     *
     * @b Description
     * @n Sets MAIR for EL3
     *
     *
     * @b Arguments
     * @n idx             -      MAIR index
     * @n attr            -      attributes
     *
     * <b> Return Value </b>
     * @n  None
     *
     * <b> Pre Condition </b>
     * @n None
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     *
     * uint8_t         idx;
     * uint16_t        attr;
     *
     *
     * CSL_a53v8SetMAIREL3(level,type);
     *
     *
     * @endverbatim
     */

    void CSL_a53v8SetMAIREL3(uint8_t idx, uint16_t attr);
    /** @} */









#ifdef __cplusplus
}
#endif

#endif             /* end of _CSL_a53v8_H_ definition */
