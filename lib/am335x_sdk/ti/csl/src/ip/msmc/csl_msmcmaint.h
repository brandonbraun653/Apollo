#ifndef MSMCMAINT_H_
#define MSMCMAINT_H_
/**
 *  @file csl_msmcmaint.h
 *
 *  @brief
 *     MSMC Maintainence Functions
 *  \par
 *   ================================================================================
 *
 *   @n   (C)  Copyright 2017 Texas Instruments Incorporated
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

#include <stdint.h>
#include <cslr_msmc.h>


    /* MSMC VBUSMC Control port */
    /* MSMCCFG must be defined based upon the architecture*/
    /*#define MSMCCFGS0REGS (*(volatile CSL_msmc_cfgs0Regs * )(uintptr_t) MSMCCFG)*/






    /** ===========================================================================
     *
     * @defgroup CSL_MSMCMAINT_API (MSMC Maintainence Operations)
     * @ingroup CSL_MSMCMAINT_API
     *
     * @section Introduction
     *
     * @subsection xxx Overview
     *
     * @subsection References
     *    -# MSMC Functional Specification
     * ============================================================================
     */


    /**
       @defgroup CSL_MSMCMAINT_DATASTRUCT ARM 64 Bit Mode Cache Data Structures
       @ingroup CSL_MSMCMAINT_API
    */
    /**
       @defgroup CSL_MSMCMAINT_FUNCTION ARM 64 Bit Mode Cache Functions
       @ingroup CSL_MSMCMAINT_API
    */
    /**
       @defgroup CSL_MSMCMATIN_ENUM ARM 64 Bit Mode Cache Enumerated Data Types
       @ingroup CSL_msmc_API
    */



/** ============================================================================
 *  @addtogroup CSL_MSMCMAINT_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains parameters to pass for starvation bounds
 *          in the setup of the DRU channels
 * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
 * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
 * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
 * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
 * ----------------------------------------------------------------------------
 */
    typedef struct {
        uint8_t  sbndmnrt;
        uint8_t  sbndenrt;
        uint8_t  sbndmrt;
        uint8_t  sbndert;
    } csl_msmcmaint_stv_t;



/** ============================================================================
 *  @addtogroup CSL_MSMCMAINT_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains parameters to pass for starvation bounds
 *          in the setup of the DRU channels
 * @n  uint8_t   way            way select
 * @n  uint8_t   index          index select
 * @n  uint8_t   bank           pyhsical bank select
 * @n  uint8_t   l3cache        level 3 cahce tag select
 * ----------------------------------------------------------------------------
 */
    typedef struct {
        uint8_t    way;
        uint8_t    index;
        uint8_t    bank;
        uint8_t    l3cache;
    } csl_msmcmain_dbgtagctl_t;





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetPid
     *
     * @b Description
     * @n  Sets the cache size of the L3 Cache in MSMC
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint64_t   size    -  size of the L3 cache
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
     *  msmcptr = MSMCCFG;
     *   uint64_t
     *
     *
     *   CSL_msmcGetPid((CSL_msmc_cfgs0Regs * )msmcptr);
     * @endverbatim
     */




    uint64_t CSL_msmcGetPid(
                    CSL_msmc_cfgs0Regs *ptr
                    );


    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetCohCtrl
     *
     * @b Description
     * @n  Sets the Coherence Control bit to value passed
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t        val    1 = enable 0 = disable
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   val = 1;
     *
     *
     *   CSL_msmcSetCohCtrl((CSL_msmc_cfgs0Regs * )msmcptr,val);
     * @endverbatim
     */




void CSL_msmcSetCohCtrl(
                        CSL_msmc_cfgs0Regs *ptr,
                        uint8_t val
                        );



    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetCohCtrl
     *
     * @b Description
     * @n  Sets the Coherence Control bit to value passed
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint64_t      COHCTRL contents
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   val = 1;
     *
     *
     *   CSL_msmcSetCohCtrl((CSL_msmc_cfgs0Regs * )msmcptr,val);
     * @endverbatim
     */




    uint64_t CSL_msmcGetCohCtrl(
                                CSL_msmc_cfgs0Regs *ptr
                                );









    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcEnableScrub
     *
     * @b Description
     * @n  Enables the memory scrubber while setting the clock interval
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   cnt    -  clock count (MSMC Spec 1.3.3
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   count = 0xE0;
     *
     *
     *   CSL_msmcEnableScrub((CSL_msmc_cfgs0Regs * )msmcptr,count);
     * @endverbatim
     */




void CSL_msmcEnableScrub(
                         CSL_msmc_cfgs0Regs *ptr,
                         uint8_t cnt
                         );



    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcDisableScrub
     *
     * @b Description
     * @n  Disables the memory scrubber
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
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
     *  msmcptr = MSMCCFG;
     *
     *
     *   CSL_msmcDisableScrub((CSL_msmc_cfgs0Regs * )msmcptr);
     * @endverbatim
     */




void CSL_msmcDisableScrub(
                          CSL_msmc_cfgs0Regs *ptr
                          );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetScrub
     *
     * @b Description
     * @n  Disables the memory scrubber
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  Struct pointer
     *
     * <b> Return Value </b>
     * @n uint64_t          SMEDCC contents
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
     *  msmcptr = MSMCCFG;
     *
     *  uint64_t    val
     *
     *   val = CSL_msmcGetScrub((CSL_msmc_cfgs0Regs * )msmcptr);
     * @endverbatim
     */




    uint64_t CSL_msmcGetScrub(
                                  CSL_msmc_cfgs0Regs *ptr
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetCacheSize
     *
     * @b Description
     * @n  Sets the cache size of the L3 Cache in MSMC
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint64_t   size    -  size of the L3 cache
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
     *  msmcptr = MSMCCFG;
     *   uint64_t   size;
     *
     *   size = 0x4U;
     *
     *   CSL_msmcSetCacheSize((CSL_msmc_cfgs0Regs * ),size);
     * @endverbatim
     */




void CSL_msmcSetCacheSize(
                          CSL_msmc_cfgs0Regs *ptr,
                          uint64_t size
                          );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetCacheSize
     *
     * @b Description
     * @n  Sets the cache size of the L3 Cache in MSMC
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     *
     * <b> Return Value </b>
     * @n uint64_t    CACHE_CTLR  contents
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
     *  msmcptr = MSMCCFG;
     *   uint64_t   size;
     *
     *
     *   size = CSL_msmcGetCacheSize((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t  CSL_msmcGetCacheSize(
                                   CSL_msmc_cfgs0Regs *ptr
                                   );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetRelTimWaySel
     *
     * @b Description
     * @n  Sets Real Time Way Select Value
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   andmask
     * @n  uint8_t   ormask
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   ormask;
     *   uint8_t   andmask;
     *
     *
     *
     *   CSL_msmcSetRelTimWaySel((CSL_msmc_cfgs0Regs * ),andmask,ormask);
     * @endverbatim
     */




    void CSL_msmcSetRelTimWaySe(
                                CSL_msmc_cfgs0Regs *ptr,
                                uint8_t andmask,
                                uint8_t ormask
                                );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetRelTimWaySel
     *
     * @b Description
     * @n  Get Real Time Way Select Value
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     *
     * <b> Return Value </b>
     * @n uint64_t value of RT_WAY_SEL
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
     *  msmcptr = MSMCCFG;
     *
     *
     *
     *   CSL_msmcGetRelTimWaySel((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t CSL_msmcGetRelTimWaySel (
                                  CSL_msmc_cfgs0Regs *ptr
                                  );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetNRelTimWaySel
     *
     * @b Description
     * @n  Sets Non Real Time Way Select Value
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   andmask
     * @n  uint8_t   ormask
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   ormask;
     *   uint8_t   andmask;
     *
     *
     *
     *   CSL_msmcSetNRelTimWaySel((CSL_msmc_cfgs0Regs * ),andmask,ormask);
     * @endverbatim
     */




    void CSL_msmcSetNRelTimWaySel(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  uint8_t andmask,
                                  uint8_t ormask
                                  );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetNRelTimWaySel
     *
     * @b Description
     * @n  Get Real Time Way Select Value
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     *
     * <b> Return Value </b>
     * @n uint64_t value of NREL_TIM_WAY register
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
     *  msmcptr = MSMCCFG;
     *
     *
     *
     *   CSL_msmcGetNRelTimWaySel((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t CSL_msmcGetNRelTimWaySel(
                                      CSL_msmc_cfgs0Regs *ptr
                                      );






    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetSmeStat
     *
     * @b Description
     * @n  Get Interrupt Enabled Status
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
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
     *  msmcptr = MSMCCFG;
     *
     *
     *
     *   CSL_msmcGetSmeStat((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t CSL_msmcGetNRelTimWaySel(
                                      CSL_msmc_cfgs0Regs *ptr
                                      );







    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetSmIrStat
     *
     * @b Description
     * @n  Get Interrupt Raw Status
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     *
     * <b> Return Value </b>
     * @n uint64_t   value of SMIRSTAT register
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
     *  msmcptr = MSMCCFG;
     *
     *
     *
     *   CSL_msmcGetSmIrStat((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t CSL_msmcGetSmIrStat(
                                      CSL_msmc_cfgs0Regs *ptr
                                      );










    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetSmIrWs
     *
     * @b Description
     * @n  Sets Interrypt Raw Status Register
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   val
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   val;
     *
     *   val = 1;
     *
     *   CSL_msmcSetSmIrWs((CSL_msmc_cfgs0Regs * ),val);
     * @endverbatim
     */




    void CSL_msmcSetSmIrWs(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  uint8_t val
                                  );






    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcClearInt
     *
     * @b Description
     * @n  Cleats Interrupt
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
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
     *  msmcptr = MSMCCFG;
     *
     *
     *   CSL_msmcClearInt((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    void CSL_msmcClearInt(
                                  CSL_msmc_cfgs0Regs *ptr
                                  );







    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcGetSmIeStat
     *
     * @b Description
     * @n  Get Interrupt Raw Status
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     *
     * <b> Return Value </b>
     * @n uint64_t   value of SMIESTAT register
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
     *  msmcptr = MSMCCFG;
     *
     *
     *
     *   CSL_msmcGetSmIeStat((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    uint64_t CSL_msmcGetSmIeStat(
                                      CSL_msmc_cfgs0Regs *ptr
                                      );








    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetSmIeWs
     *
     * @b Description
     * @n  Sets Interrupt Raw Status Register
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   val
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
     *  msmcptr = MSMCCFG;
     *   uint8_t   val;
     *
     *   val = 1;
     *
     *   CSL_msmcSetSmIeWs((CSL_msmc_cfgs0Regs * ),val);
     * @endverbatim
     */




    void CSL_msmcSetSmIeWs(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  uint8_t val
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcClearIent
     *
     * @b Description
     * @n  Cleats Interrupt
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
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
     *  msmcptr = MSMCCFG;
     *
     *
     *   CSL_msmcClearIent((CSL_msmc_cfgs0Regs * ));
     * @endverbatim
     */




    void CSL_msmcClearIent(
                           CSL_msmc_cfgs0Regs *ptr
                           );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @N@b  CSL_msmcSetStvBndCohPt0
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *  csl_msmcmaint_stv_t   stvbnds;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt0((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt0(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt1
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt1((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt1(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt2
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt2((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt2(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt3
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt3((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt3(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt4
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt4((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt4(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt5
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt5((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt5(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt6
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt6((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt6(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt7
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt7((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt7(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt8
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt8((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt8(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt9
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt9((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt9(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt10
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt10((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt10(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt11
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt11((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt11(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );





    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndCohPt12
     *
     * @b Description
     * @n  Sets starvation bounds for coherent port
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPt12((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndCohPt12(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );








    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndDRU
     *
     * @b Description
     * @n  Sets starvation bounds for DRU
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPtDRU((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndDRU(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );




    /** ==========================================================================
        @addtogroup CSL_msmc_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_msmcSetStvBndResp
     *
     * @b Description
     * @n  Sets starvation bounds for Read Response
     *
     *
     *
     * @b Arguments
     * @n  CSL_msmc_cfgs0Regs   ptr    pointer to structure location
     * @n  uint8_t   sbndmnrt     starvation bound for non-real-time on-chip memory
     * @n  uint8_t   sbndenrt     starvation bound for no-real-time external memory
     * @n  uint8_t   sbndmrt      starvation bound for real-tiem on-chip memory
     * @n  uint8_t   sbndert      starvation bound for rea-litme external memory
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
     *  msmcptr = MSMCCFG;
     *
     *  stvbnds.sbndmnrt = sbndmnrt;
     *  stvbnds.sbndenrt = sbndenrt;
     *  stvbnds.sbndmrt = sbndmrt;
     *  stvbnds.sbndert = sbndert;
     *
     *
     *   CSL_msmcSetStvBndCohPtResp((CSL_msmc_cfgs0Regs * ),stvbnds);
     * @endverbatim
     */




    void CSL_msmcSetStvBndResp(
                                  CSL_msmc_cfgs0Regs *ptr,
                                  csl_msmcmaint_stv_t *bnd_descriptor
                                  );








#ifdef __cplusplus
}
#endif /* extern "C"  */

#endif    /*end of MSMCMAINT_H_ */
