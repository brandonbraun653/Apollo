#ifndef _CSL_ARMCACHE32_H_
#define _CSL_ARMCACHE32_H_

/**
 *  @file csl_armcache32.h
 *
 *  @brief
 *     Cache Management Instructions
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
 */



#ifdef __cplusplus
extern "C" {
#endif

    /** ===========================================================================
     *
     * @defgroup CSL_a53v7_API (ARM32 CACHE)
     * @ingroup CSL_ARMCAHCE32_API
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
       @defgroup CSL_a53v7_DATASTRUCT ARM 32 Bit Cache Data Structures
       @ingroup CSL_a53v7_API
    */
    /**
       @defgroup CSL_a53v7_FUNCTION ARM 32 Bit Cache Functions
       @ingroup CSL_a53v7_API
    */
    /**
       @defgroup CSL_a53v7_ENUM ARM 32 Bit Cache Enumerated Data Types
       @ingroup CSL_a53v7_API
    */



    /*Function Prototypes*/
    /** ==========================================================================
        @addtogroup CSL_a53v7_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b CSL_a53v7_enableIcache
     *
     * @b Description
     * @n  Disables the entire I Cache
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
     *   CSL_a53v7EnableIcache();
     * @endverbatim
     */


    void CSL_a53v7EnableIcache();








    /**
     * @n@b CSL_a53v7_disableIcache
     *
     * @b Description
     * @n  Disables the entire I Cache
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
     *   CSL_a53v7DisableIcache();
     * @endverbatim
     */


    void CSL_a53v7DisableIcache();



    /*Function Prototypes*/





    /**
     * @n@b CSL_a53v7EnableDcache
     *
     * @b Description
     * @n  Disables the entire D Cache
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
     *   CSL_a53v7EnableDcache();
     * @endverbatim
     */


    void CSL_a53v7EnableDcache();








    /**
     * @n@b CSL_a53v7DisableDcache
     *
     * @b Description
     * @n  Disables the entire D Cache
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
     *   CSL_a53v7DisableDcache();
     * @endverbatim
     */


    void CSL_a53v7DisableDcache();










    /**
     * @n@b CSL_a53v7EnableMmu
     *
     * @b Description
     * @n Enable the MMU
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
     *   CSL_a53v7EnableMmu();
     * @endverbatim
     */


    void CSL_a53v7DisableMmu();






    /**
     * @n@b CSL_a53v7DisableMmu
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7DisableMmu();
     * @endverbatim
     */


    void CSL_a53v7DisableMmu();





    /*Hyper Visor Level Operations*/






    /**
     * @n@b CSL_a53v7EnableIcacheH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7EnableIcacheH();
     * @endverbatim
     */


    void CSL_a53v7EnableIcacheH();






    /**
     * @n@b CSL_a53v7DisableIcacheH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7DisableIcacheH();
     * @endverbatim
     */


    void CSL_a53v7DisableIcacheH();







    /**
     * @n@b CSL_a53v7EnableDcacheH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7EnableDcacheH();
     * @endverbatim
     */


    void CSL_a53v7EnableDcacheH();






    /**
     * @n@b CSL_a53v7DisableDcacheH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7DisableDcacheH();
     * @endverbatim
     */


    void CSL_a53v7DisableDcacheH();







    /**
     * @n@b CSL_a53v7EnableMmuH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7EnableMmuH();
     * @endverbatim
     */


    void CSL_a53v7EnableMmuH();






    /**
     * @n@b CSL_a53v7DisableMmuH
     *
     * @b Description
     * @n  Disable the MMU
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
     *   CSL_a53v7DisableMmuH();
     * @endverbatim
     */

    void CSL_a53v7DisableMmuH();




    /**
     * @n@b CSL_a53v7CleanL1DcacheMva
     *
     * @b Description
     * @n  Cleans L1D cache by virtual address
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
     * uint32_t   address;
     *
     *   CSL_a53v7CleanL1DcacheMva(address);
     *
     * @endverbatim
     */

    void  CSL_a53v7CleanL1DcacheMva(uint32_t address);




    /**
     * @n@b CSL_a53v7CleanL1DcacheSetWay
     *
     * @b Description
     * @n  Cleans L1D cahce by set and way
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
     * uint32_t   setway;
     *
     *   CSL_a53v7CleanL1DcacheSetWay(setway);
     * @endverbatim
     */

    void CSL_a53v7CleanL1DcacheSetWay(uint32_t setway);





    /**
     * @n@b CSL_a53v7CleanInvalidateL1DcacheMva
     *
     * @b Description
     * @n  Cleans L1D cache by virtual address
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
     * uint32_t   address;
     *
     *   CSL_a53v7CleanInvalidateL1DcacheMva(address);
     *
     * @endverbatim
     */

    void  CSL_a53v7CleanInvalidateL1DcacheMva(uint32_t address);




    /**
     * @n@b CSL_a53v7CleanInvalidateL1DcacheSetWay
     *
     * @b Description
     * @n  Cleans L1D cahce by set and way
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
     * uint32_t   setway;
     *
     *   CSL_a53v7CleanInvalidateL1DcacheSetWay(setway);
     * @endverbatim
     */

    void CSL_a53v7CleanInvalidateL1DcacheSetWay(uint32_t setway);














    /**
     * @n@b CSL_a53v7CleanL2DcacheMva
     *
     * @b Description
     * @n  Cleans L2D cache by virtual address
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
     * uint32_t   address;
     *
     *   CSL_a53v7CleanL2DcacheMva(address);
     *
     * @endverbatim
     */

    void  CSL_a53v7CleanL2DcacheMva(uint32_t address);




    /**
     * @n@b CSL_a53v7CleanL2DcacheSetWay
     *
     * @b Description
     * @n  Cleans L2D cahce by set and way
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
     * uint32_t   setway;
     *
     *   CSL_a53v7CleanL2DcacheSetWay(setway);
     * @endverbatim
     */

    void CSL_a53v7CleanL2DcacheSetWay(uint32_t setway);







    /**
     * @n@b CSL_a53v7CleanInvalidateL2DcacheMva
     *
     * @b Description
     * @n  Cleans L2D cache by virtual address
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
     * uint32_t   address;
     *
     *   CSL_a53v7CleanInvalidateL2DcacheMva(address);
     *
     * @endverbatim
     */

    void  CSL_a53v7CleanInvalidateL2DcacheMva(uint32_t address);




    /**
     * @n@b CSL_a53v7CleanInvalidateL2DcacheSetWay
     *
     * @b Description
     * @n  Cleans L2D cahce by set and way
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
     * uint32_t   setway;
     *
     *   CSL_a53v7CleanInvalidateL2DcacheSetWay(setway);
     * @endverbatim
     */

    void CSL_a53v7CleanInvalidateL2DcacheSetWay(uint32_t setway);




    /**
     * @n@b CSL_a53v7IvalidateIcacheMva
     *
     * @b Description
     * @n  Cleans L2D cahce by set and way
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
     * uint32_t   address
     *
     *   CSL_a53v7IvalidateIcacheMva(address);
     * @endverbatim
     */

    void CSL_a53v7IvalidateIcacheMva(uint32_t adddress);














        /** @} */









#ifdef __cplusplus
}
#endif

#endif             /* end of _CSL_a53v7_H_ definition*/
