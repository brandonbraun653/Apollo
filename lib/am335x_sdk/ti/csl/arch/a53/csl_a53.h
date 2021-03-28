#ifndef _CSL_A53_H_
#define _CSL_A53_H_

/**
 *  @file csl_a53.h
 *
 *  @brief
 *     ARM General Maintainence Functions
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
#include <ti/csl/arch/a53/csl_a53v8misc.h>
#include <ti/csl/arch/a53/csl_a53v8cache.h>

#ifdef __cplusplus
extern "C" {
#endif


    /** ===========================================================================
     *
     * @defgroup CSL_A53_API (ARM64 Genearl Functions)
     * @ingroup CSL_A53_API
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
       @defgroup CSL_A53_DATASTRUCT ARM 64 Bit Mode General Data Structures
       @ingroup CSL_A53_API
    */
    /**
       @defgroup CSL_A53_FUNCTION ARM 64 Bit Mode General Functions
       @ingroup CSL_A53_API
    */
    /**
       @defgroup CSL_A53_ENUM ARM 64 Bit Mode General Enumerated Data Types
       @ingroup CSL_A53_API
    */


    /*Function Prototypes */

    /*/////////////////////////////////////////////////////////////////////////// */
    /*  Data Cache Enable and Disable Operations */
    /*////////////////////////////////////////////////////////////////////////// */

    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53DisableDcacheEl3
     *
     * @b Description
     * @n  Disables the entire D Cache for EL3 Level
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
     *   CSL_a53DisableDcacheEl3();
     * @endverbatim
     */


    void CSL_a53DisableDcacheEl3();






    /**
     * @n@b CSL_a53DisableDcacheEl2
     *
     * @b Description
     * @n  Disables the entire D Cache for EL2 Level
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
     *   CSL_a53DisableDcacheEl2();
     * @endverbatim
     */


    void CSL_a53DisableDcacheEl2();






    /**
     * @n@b CSL_a53DisableDcacheEl1
     *
     * @b Description
     * @n  Disables the entire D Cache for EL1 Level
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
     *   CSL_a53DisableDcacheEl1();
     * @endverbatim
     */


    void CSL_a53DisableDcacheEl1();







    /**
     * @n@b CSL_a53DisableDcacheAllLev
     *
     * @b Description
     * @n  Disables the entire D Cache for All Levels
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
     *   CSL_a53DisableDcacheAllLev();
     * @endverbatim
     */


    void CSL_a53DisableDcacheAllLev();











    /**
     * @n@b CSL_a53EnableDcacheEl3
     *
     * @b Description
     * @n  Enables the entire D Cache for EL3 Level
     *
     *
     *
     * @b Arguments
     * @n  uint64_t     l2size
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
     *   CSL_a53EnableDcacheEl3();
     * @endverbatim
     */


    void CSL_a53EnableDcacheEl3();






    /**
     * @n@b CSL_a53EnableDcacheEl2
     *
     * @b Description
     * @n  Enables the entire D Cache for EL2 Level
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
     *   CSL_a53EnableDcacheEl2();
     * @endverbatim
     */


    void CSL_a53EnableDcacheEl2();






    /**
     * @n@b CSL_a53EnableDcacheEl1
     *
     * @b Description
     * @n  Enables the entire D Cache for EL1 Level
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
     *   CSL_a53EnableDcacheEl1();
     * @endverbatim
     */


    void CSL_a53EnableDcacheEl1();







    /**
     * @n@b CSL_a53EnableDcacheAllLev
     *
     * @b Description
     * @n  Enables the entire D Cache for All Levels
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
     *   CSL_a53EnableDcacheAllLev();
     * @endverbatim
     */


    void CSL_a53EnableDcacheAllLev();









    /*/////////////////////////////////////////////////////////////////////////// */
    /*/  Instruction Cache Enable and Disable Operations */
    /*////////////////////////////////////////////////////////////////////////// */









    /**
     * @n@b CSL_a53EnableIcacheEl3
     *
     * @b Description
     * @n  Enables the entire I Cache for EL3 Levels
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
     *   CSL_a53EnableIcacheEl3();
     * @endverbatim
     */


    void CSL_a53EnableIcacheEl3();







    /**
     * @n@b CSL_a53EnableIcacheEl2
     *
     * @b Description
     * @n  Enables the entire I Cache for EL2 Levels
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
     *   CSL_a53EnableIcacheEl2();
     * @endverbatim
     */


    void CSL_a53EnableIcacheEl2();







    /**
     * @n@b CSL_a53EnableIcacheEl1
     *
     * @b Description
     * @n  Enables the entire I Cache for EL1 Levels
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
     *   CSL_a53EnableIcacheEl1();
     * @endverbatim
     */


    void CSL_a53EnableIcacheEl1();









    /**
     * @n@b CSL_a53EnableIcacheAllLev
     *
     * @b Description
     * @n  Enables the entire I Cache for All Levels
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
     *   CSL_a53EnableIcacheAllLev();
     * @endverbatim
     */


    void CSL_a53EnableIcacheAllLev();



    /** ==========================================================================
        @addtogroup CSL_A53FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53DisableDataCoherency
     *
     * @b Description
     * @n  Disables the data coherency
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
     *   CSL_a53DisableDataCoherency();
     * @endverbatim
     */

    /** @} */
    void CSL_a53DisableDataCoherency();



    /*////////////////////////////////////////////////////////////////////////// */
    /* Data Cache Clean and Invalidate Operations */
    /*////////////////////////////////////////////////////////////////////////// */







    /**
     * @n@b CSL_a53CleanInvalidateL1DcacheSetWay
     *
     * @b Description
     * @n  Cleans and Invalidates L1 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanInvalidateL1DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanInvalidateL1DcacheSetWay(uint64_t setway);







    /**
     * @n@b CSL_a53CleanInvalidateL2DcacheSetWay
     *
     * @b Description
     * @n  Cleans and Invalidates L2 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanInvalidateL2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanInvalidateL2DcacheSetWay(uint64_t setway);








    /**
     * @n@b CSL_a53CleanInvalidateL1L2DcacheSetWay
     *
     * @b Description
     * @n  Cleans and Invalidates L1 and L2 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanInvalidateL1L2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanInvalidateL1L2DcacheSetWay(uint64_t setway);










    /**
     * @n@b CSL_a53CleanL1DcacheSetWay
     *
     * @b Description
     * @n  Cleans L1 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanL1DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanL1DcacheSetWay(uint64_t setway);







    /**
     * @n@b CSL_a53CleanL2DcacheSetWay
     *
     * @b Description
     * @n  Cleans and  L2 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanL2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanL2DcacheSetWay(uint64_t setway);








    /**
     * @n@b CSL_a53CleanL1L2DcacheSetWay
     *
     * @b Description
     * @n  Cleans and  L1 and L2 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53CleanL1L2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53CleanL1L2DcacheSetWay(uint64_t setway);











    /**
     * @n@b CSL_a53InvalidateL1DcacheSetWay
     *
     * @b Description
     * @n   Invalidates L1 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53InvalidateL1DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53InvalidateL1DcacheSetWay(uint64_t setway);







    /**
     * @n@b CSL_a53InvalidateL2DcacheSetWay
     *
     * @b Description
     * @n   Invalidates L2 D Cache by Set Way
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
     *   uin642_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53InvalidateL2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53InvalidateL2DcacheSetWay(uint64_t setway);








    /**
     * @n@b CSL_a53InvalidateL1L2DcacheSetWay
     *
     * @b Description
     * @n   Invalidates L1 and L2 D Cache by Set Way
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
     *   uint64_t      setway;
     *
     *   setway = 0x11;

     *   CSL_a53InvalidateL1L2DcacheSetWay(setway);
     * @endverbatim
     */


    void CSL_a53InvalidateL1L2DcacheSetWay(uint64_t setway);








    /**
     * @n@b CSL_a53CleanInvalidateDcacheMvaPoC
     *
     * @b Description
     * @n   Cleans Invalidates D Cache Line by Virtual Address to POC(v8), L1&L2(v7)
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
     *   uint64_t      mva;
     *
     *
     *   CSL_a53CleanInvalidateDcacheMvaPoC(mva);
     * @endverbatim
     */


    void CSL_a53CleanInvalidateDcacheMvaPoC(uint64_t mva);








    /**
     * @n@b CSL_a53InvalidateDcacheMvaPoC
     *
     * @b Description
     * @n   Invalidates D Cache Line by Virtual Address to POC(v8), L1&L2(v7)
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
     *   uint64_t      mva;
     *
     *
     *   CSL_a53InvalidateDcacheMvaPoC(mva);
     * @endverbatim
     */

    void CSL_a53InvalidateDcacheMvaPoC(uint64_t mva);


    /** @} */


    /** ==========================================================================
        @addtogroup CSL_a53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53CleanDcacheMvaPoC
     *
     * @b Description
     * @n   Invalidates D Cache Line by Virtual Address to POC(v8), L1&L2(v7)
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
     *   uint64_t      mva;
     *
     *
     *   CSL_a53CleanDcacheMvaPoC(mva);
     * @endverbatim
     */

    /** @} */
    void CSL_a53CleanDcacheMvaPoC(uint64_t mva);



    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53InvalidateDcacheMvaPoC
     *
     * @b Description
     * @n   Invalidates D Cache Line by Virtual Address to POC(v8), L1&L2(v7)
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
     *   uint64_t      mva;
     *
     *
     *   CSL_a53InvalidateDcacheMvaPoC(mva);
     * @endverbatim
     */

    /** @} */
    void CSL_a53CleanDcacheMvaPoU(uint64_t mva);



    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53InvalidateL1Dcache
     *
     * @b Description
     * @n   Invalidates L1D Cache
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
     *
     *   CSL_a53InvalidateL1DCache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53InvalidateL1DCache();



    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53InvalidateL2cache
     *
     * @b Description
     * @n   Invalidates L2 Cache
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
     *
     *   CSL_a53InvalidateL2Cache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53InvalidateL2Cache();


    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53InvalidateL3cache
     *
     * @b Description
     * @n   Invalidates L3 Cache
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
     *
     *   CSL_a53InvalidateL3Cache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53InvalidateL3Cache();


    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53CleanL1DCache
     *
     * @b Description
     * @n   Cleans the L1D Cache
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
     *
     *   CSL_a53CleanL1DCache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53CleanL1DCache();




    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53CleanL2Cache
     *
     * @b Description
     * @n   Cleans the L2 Cache
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
     *
     *   CSL_a53CleanL2Cache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53CleanL2Cache();



    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53CleanL3Cache
     *
     * @b Description
     * @n   Cleans the L3 Cache
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
     *
     *   CSL_a53CleanL3Cache();
     * @endverbatim
     */

    /** @} */
    void CSL_a53CleanL3Cache();


    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_cacheEnable
     *
     * @b Description
     * @n  Instruction and Data Cache Enable
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
     *   CSL_cacheStartup();
     * @endverbatim
     */

    void CSL_cacheEnable(void);


    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_cacheDisable
     *
     * @b Description
     * @n  Instruction and Data Cache Disable
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
     *   CSL_cacheStartup();
     * @endverbatim
     */

    void CSL_cacheDisable(void);

    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53Isb
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
     *   CSL_a53Isb();
     * @endverbatim
     */


    void CSL_a53Isb();







    /**
     * @n@b CSL_a53DmIshLdS
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
     *   CSL_a53DmIshLdS();
     * @endverbatim
     */


    void CSL_a53DmIshLdS();








    /**
     * @n@b CSL_a53DmOshLdS
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
     *   CSL_a53DmOshLdS();
     * @endverbatim
     */


    void CSL_a53DmOshLdS();








    /**
     * @n@b CSL_a53DmNshLdS
     *
     * @b Description
     * @n  Data Memory Barrier Non Sharable Load/Store
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
     *   CSL_a53DmNshLdS();
     * @endverbatim
     */


    void CSL_a53DmNshLdS();








    /**
     * @n@b CSL_a53DmLd
     *
     * @b Description
     * @n  Data Memory Barrier System Load
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
     *   CSL_a53DmLd();
     * @endverbatim
     */


    void CSL_a53DmLd();







    /**
     * @n@b CSL_a53DsIshLd
     *
     * @b Description
     * @n  Data Synshornization Barrier Inner Shareable Load
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
     *   CSL_a53DsIshLd();
     * @endverbatim
     */


    void CSL_a53DsIshLd();








    /**
     * @n@b CSL_a53DsOshLd
     *
     * @b Description
     * @n  Data Memory Synchronization Inner Shareable Load
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
     *   CSL_a53DsOshLd();
     * @endverbatim
     */


    void CSL_a53DsOshLd();








    /**
     * @n@b CSL_a53DsNshLd
     *
     * @b Description
     * @n  Data Memory Synchronization Non Shareable Load
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
     *   CSL_a53DsNshLd();
     * @endverbatim
     */


    void CSL_a53DsNshLd();








    /**
     * @n@b CSL_a53DShSyLd
     *
     * @b Description
     * @n  Data Memory Syncrhonization Shareable System Load
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
     *   CSL_a53DShSyLd();
     * @endverbatim
     */


    void CSL_a53DsShSyLd();







    /**
     * @n@b CSL_a53DsYLd
     *
     * @b Description
     * @n  Data Memory Syncrhonization System All
     * @n  NOTE:::: this is the only C7x barrier available
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
     *   CSL_a53DsYLd();
     * @endverbatim
     */

    void CSL_a53DsYLd();

   /**
     * @n@b CSL_a53WaitFi
     *
     * @b Description
     * @n  CPU is put into halt mode waiting for interrupt
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
     *   CSL_a53WaitFi();
     * @endverbatim
     */

    void CSL_a53WaitFi();



    /** ==========================================================================
        @addtogroup CSL_A53_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53GetCpuId
     *
     * @b Description
     * @n  CPU ID Read
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint64_t    cpuid
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
     *   uint64_t cpuid;
     *
     *   cpuid = CSL_a53GetCpuId();
     * @endverbatim
     */


    uint64_t CSL_a53GetCpuId();


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuInitLevel1Desc
     *
     * @b Description
     * @n  prepares the mmu level1 descriptor
     *
     *
     *
     * @b Arguments
     * @n  uint64_t                 phyAddr
     * @n  CSL_a53MmuDescAttrs      attrs
     *
     * <b> Return Value </b>
     * @n uint64_t    desc
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
     *   uint64_t desc;
     *
     *   desc = CSL_mmuInitLevel1Desc();
     * @endverbatim
     */


    uint64_t CSL_mmuInitLevel1Desc(uint64_t phyAddr, CSL_a53MmuDescAttrs *attrs);

    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuInitLeve21Desc
     *
     * @b Description
     * @n  prepares the mmu level2 descriptor
     *
     *
     *
     * @b Arguments
     * @n  uint64_t                 phyAddr
     * @n  CSL_a53MmuDescAttrs      attrs
     *
     * <b> Return Value </b>
     * @n uint64_t    desc
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
     *   uint64_t desc;
     *
     *   desc = CSL_mmuInitLeve21Desc();
     * @endverbatim
     */

    uint64_t CSL_mmuInitLevel2Desc(uint64_t phyAddr, CSL_a53MmuDescAttrs *attrs);

    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuSetMAIR
     *
     * @b Description
     * @n  sets MAIR register for EL1
     *
     *
     *
     * @b Arguments
     * @n  uint8_t                  idx
     * @n  uint16_t                 attr
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
     * CSL_mmuSetMAIR(0, 0x44);
     * @endverbatim
     */

    void CSL_mmuSetMAIR(uint8_t idx, uint16_t attr);

    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuInit
     *
     * @b Description
     * @n  initializes the MMU for EL1
     *
     *
     *
     * @b Arguments
     * @n  uintptr_t                tableAddr
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
     * uintptr_t tableAddr;
     *
     * tableAddr = (uintptr_t) &levl1TableAddr[0];
     * CSL_mmuInit(tableAddr);
     * @endverbatim
     */

    void CSL_mmuInit(uintptr_t tableAddr);

    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuSetTCR
     *
     * @b Description
     * @n  sets the EL1 TCR register
     *
     *
     *
     * @b Arguments
     * @n  uint64_t               tcr
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
     * CSL_mmuInit(tcr);
     * @endverbatim
     */

    void CSL_mmuSetTCR(uint64_t tcr);

    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_mmuStartup
     *
     * @b Description
     * @n  starts the default MMU initialization
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
     * CSL_mmuStartup();
     * @endverbatim
     */

    void CSL_mmuStartup(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_enablePmu
     *
     * @b Description
     * @n  Enables PMU
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
     * CSL_enablePmu();
     * @endverbatim
     */

     void CSL_enablePmu(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_disablePmu
     *
     * @b Description
     * @n  disables PMU
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
     * CSL_enablePmu();
     * @endverbatim
     */

     void CSL_disablePmu(void);



    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_initPmu
     *
     * @b Description
     * @n  initializes PMU
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
     * CSL_initPMU();
     * @endverbatim
     */

     void CSL_initPmu(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_stopPmuCycleCounter
     *
     * @b Description
     * @n  stops PMU cycle counter
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
     * CSL_stopPmuCycleCounter();
     * @endverbatim
     */

     void CSL_stopPmuCycleCounter(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_startPmuCycleCounter
     *
     * @b Description
     * @n  starts PMU cycle counter
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
     * CSL_startPmuCycleCounter();
     * @endverbatim
     */

     void CSL_startPmuCycleCounter(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_clearPmuCycleCounter
     *
     * @b Description
     * @n  clears PMU cycle counter
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
     * CSL_clearPmuCycleCounter();
     * @endverbatim
     */

     void CSL_clearPmuCycleCounter(void);


    /** ==========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  ===========================================================================
      */
    /**
     * @n@b CSL_resetPmuCycleCounter
     *
     * @b Description
     * @n  resets PMU cycle counter
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
     * CSL_resetPmuCycleCounter();
     * @endverbatim
     */

     void CSL_resetPmuCycleCounter(void);


    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_resetPmuEventCounter
     *
     * @b Description
     * @n  resets PMU event counter
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
     * CSL_resetPmuEventCounter();
     * @endverbatim
     */

     void CSL_resetPmuEventCounter(void);


    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_stopAllPmuCounters
     *
     * @b Description
     * @n  stops all PMU counters
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
     * CSL_stopAllPmuCounters();
     * @endverbatim
     */

     void CSL_stopAllPmuCounters(void);


    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_getPmuCycleCount
     *
     * @b Description
     * @n  get PMU cycle count
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint64_t   cycle_count
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
     * uint64_t cycle_count;
     * cycle_count = CSL_getPmuCycleCount();
     * @endverbatim
     */

     uint64_t CSL_getPmuCycleCount(void);


    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_getPmuCycleCountOverhead
     *
     * @b Description
     * @n  get PMU cycle count
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
     * uint64_t overhead;
     * overhead = CSL_getPmuCycleCountOverhead();
     * @endverbatim
     */

     uint64_t  CSL_getPmuCycleCountOverhead(void);

    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_initGTC
     *
     * @b Description
     * @n  This initializes ARM v8 Generic TImer Comparator (GTC)
     *     GTC clock is different than the PMU clock
     *     This function assumes the clock is set by GEL or DMSC
     *     Make sure to check the frequency used for the SoC. (default = 200MHz)
     *
     *     This register
     *
     * @b Arguments
     * @n  uint32_t gtcCntVal
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
     * CSL_initGTC(void);
     * @endverbatim
     */

     void  CSL_initGTC(void);


    /** ========================================================================
      @addtogroup CSL_A53_FUNCTION
      @{
      *  =======================================================================
      */
    /**
     * @n@b CSL_getGTCcount
     *
     * @b Description
     * @n  get GTC cycle count
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
     * uint64_t count;
     * count = CSL_getGTCcount();
     * @endverbatim
     */

     uint64_t  CSL_getGTCcount(void);

    /** @} */



/**
  * @brief CPU definitions
  */

#define CSL_A53_CPUID_CLUSTER0_CORE0  (0ul)
#define CSL_A53_CPUID_CLUSTER0_CORE1  (001ul)
#define CSL_A53_CPUID_CLUSTER1_CORE0  (0x100ul)
#define CSL_A53_CPUID_CLUSTER1_CORE1  (0x101ul)
#define CSL_A53_GTC_DEBUG_HALT        (1u << 1u)
#define CSL_A53_GTC_ENABLE            (1u)

#ifdef __cplusplus
}
#endif

#endif             /* end of _CSL_ARM64FUNCTION_H_ definition */
