/**  
 * @file  csl_cptsAux.h
 *
 * @brief  
 *  API Auxilary header file for Ethernet Time Synchronization module CSL. 
 *
 *  Contains the different control command and status query functions definations
 *   
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2014, Texas Instruments, Inc.
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

#ifndef CSL_CPTSAUX_V2_H_
#define CSL_CPTSAUX_V2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_cpts.h>

/** @addtogroup CSL_CPTS_DATASTRUCT
 @{ */

/** @brief      
 *
 *  Defines CPTS timestamp output bits
 */        
typedef enum {
    CPTS_TS_OUTPUT_BIT_DISABLED = 0,
    CPTS_TS_OUTPUT_BIT_17,
    CPTS_TS_OUTPUT_BIT_18,
    CPTS_TS_OUTPUT_BIT_19,
    CPTS_TS_OUTPUT_BIT_20,
    CPTS_TS_OUTPUT_BIT_21,
    CPTS_TS_OUTPUT_BIT_22,
    CPTS_TS_OUTPUT_BIT_23,
    CPTS_TS_OUTPUT_BIT_24,
    CPTS_TS_OUTPUT_BIT_25,
    CPTS_TS_OUTPUT_BIT_26,
    CPTS_TS_OUTPUT_BIT_27,
    CPTS_TS_OUTPUT_BIT_28,
    CPTS_TS_OUTPUT_BIT_29,
    CPTS_TS_OUTPUT_BIT_30,
    CPTS_TS_OUTPUT_BIT_31
} CSL_CPTS_TS_OUTPUT_BIT;

/** @brief      
 *
 *  Holds the CPTS control register info. 
 */        
typedef struct {
	/**  Time Sync Enable:  When disabled (cleared to zero), the RCLK domain is
         held in reset. */	
	Uint32                  cptsEn;

	/**  Interrupt Test: When set, this bit allows the raw interrupt to be written to
         facilitate interrupt test. */	
	Uint32                  intTest;

	/**  TS_COMP Polarity: 0 - TS_COMP is asserted low; 1: TS_COMP is asserted high */	
	Uint32                  tsCompPolarity;

	/**  Host Receive Timestamp Enable: When set, Timestamps enabled on received packets to host */	
	Uint32                  tstampEn;

	/**  Sequence Enable:
         0: The timestamp value increments with the selected RFTCLK
         1: The timestamp for received packets is the sequence number of the received packet
      */	
	Uint32                  seqEn;
    
    /** 64-bit mode:
        0: The timestamp is 32-bits with the upper 32-bits forced to zero.
        1: The timestamp is 64-bits.
      */  
	Uint32                  ts64bMode;
    
	/**  TS_COMP Toggle mode - 0: TS_COMP is in non-toggle mode; 1: TS_COMP is in toggle mode */	
	Uint32                  tsCompToggle;
    
	/**  Hardware push 1-8 enable */
	Uint32                  tsHwPushEn[8];
    
	/**  TS_SYNC output timestamp counter bit select */	
	CSL_CPTS_TS_OUTPUT_BIT  tsOutputBitSel;

} CSL_CPTS_CONTROL;

/**
@}
*/


/** @addtogroup CSL_CPTS_FUNCTION
@{ */

/********************************************************************************
********************** Time Synchronization (CPTS) Submodule ********************
********************************************************************************/


/** ============================================================================
 *   @n@b CSL_CPTS_getCptsVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the CPTS module identification and version 
 *      information.
 *
 *   @b Arguments
     @verbatim
        pVersionInfo        CSL_CPTS_VERSION structure that needs to be populated
                            with the version info read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_IDVER_REG_MINOR_VER,
 *      CPTS_IDVER_REG_MAJOR_VER,
 *      CPTS_IDVER_REG_RTL_VER,
 *      CPTS_IDVER_REG_TX_IDENT
 *
 *   @b Example
 *   @verbatim
        CSL_CPTS_VERSION    versionInfo;

        CSL_CPTS_getCptsVersionInfo (&versionInfo);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_getCptsVersionInfo 
(
	CSL_CPTS_VERSION*           pVersionInfo     
)
{

    pVersionInfo->minorVer  =   CSL_FEXT (hCptsRegs->IDVER_REG, CPTS_IDVER_REG_MINOR_VER);
    pVersionInfo->majorVer  =   CSL_FEXT (hCptsRegs->IDVER_REG, CPTS_IDVER_REG_MAJOR_VER);
    pVersionInfo->rtlVer    =   CSL_FEXT (hCptsRegs->IDVER_REG, CPTS_IDVER_REG_RTL_VER);
    pVersionInfo->id        =   CSL_FEXT (hCptsRegs->IDVER_REG, CPTS_IDVER_REG_TX_IDENT);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_isCptsEnabled
 *
 *   @b Description
 *   @n This function indicates if time sync is enabled or not.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   CPTS enabled.
 *	 @n  FALSE                  CPTS disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_CONTROL_REG_CPTS_EN
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPTS_isCptsEnabled () == TRUE)
        {
            // CPTS on
        }
        else
        {
            // CPTS off
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPTS_isCptsEnabled (void)
{

    return CSL_FEXT (hCptsRegs->CONTROL_REG, CPTS_CONTROL_REG_CPTS_EN);
}

/** ============================================================================
 *   @n@b CSL_CPTS_enableCpts
 *
 *   @b Description
 *   @n This function configures the CPTS control register to enable time sync.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_CONTROL_REG_CPTS_EN=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPTS_enableCpts ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_enableCpts (void)
{
    CSL_FINS (hCptsRegs->CONTROL_REG, CPTS_CONTROL_REG_CPTS_EN, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_disableCpts
 *
 *   @b Description
 *   @n This function configures the CPTS control register to disable time sync.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_CONTROL_REG_CPTS_EN=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPTS_disableCpts ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_disableCpts (void)
{
    CSL_FINS (hCptsRegs->CONTROL_REG, CPTS_CONTROL_REG_CPTS_EN, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_getCntllReg
 *
 *   @b Description
 *   @n This function retreives the contents of CPTS control register  
 *
 *   @b Arguments
     @verbatim
        pCntlCfg            CSL_CPTS_CONTROL that needs to be populated with 
                            contents of CPTS control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_CONTROL_REG_CPTS_EN
 *      CPTS_CONTROL_REG_INT_TEST   
 *      CPTS_CONTROL_REG_TS_COMP_POLARITY
 *      CPTS_CONTROL_REG_TSTAMP_EN
 *      CPTS_CONTROL_REG_SEQUENCE_EN
 *      CPTS_CONTROL_REG_MODE
 *      CPTS_CONTROL_REG_TS_COMP_TOG
 *      CPTS_CONTROL_REG_HW1_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW2_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW3_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW4_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW5_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW6_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW7_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW8_TS_PUSH_EN
 *      CPTS_CONTROL_REG_TS_SYNC_SEL
 *
 *   @b Example
 *   @verbatim
        CSL_CPTS_CONTROL     cntlCfg;
 
        CSL_CPTS_getCntlReg (&cntlCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_getCntlReg (
    CSL_CPTS_CONTROL*        pCntlCfg                
)
{
    Uint32 value = hCptsRegs->CONTROL_REG;
    
    pCntlCfg->cptsEn         = CSL_FEXT (value,  CPTS_CONTROL_REG_CPTS_EN);
    pCntlCfg->intTest        = CSL_FEXT (value,  CPTS_CONTROL_REG_INT_TEST);
    pCntlCfg->tsCompPolarity = CSL_FEXT (value,  CPTS_CONTROL_REG_TS_COMP_POLARITY);
    pCntlCfg->tstampEn       = CSL_FEXT (value,  CPTS_CONTROL_REG_TSTAMP_EN);
    pCntlCfg->seqEn          = CSL_FEXT (value,  CPTS_CONTROL_REG_SEQUENCE_EN);
    pCntlCfg->ts64bMode      = CSL_FEXT (value,  CPTS_CONTROL_REG_MODE);
    pCntlCfg->tsCompToggle   = CSL_FEXT (value,  CPTS_CONTROL_REG_TS_COMP_TOG);
    pCntlCfg->tsHwPushEn[0]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW1_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[1]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW2_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[2]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW3_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[3]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW4_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[4]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW5_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[5]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW6_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[6]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW7_TS_PUSH_EN);
    pCntlCfg->tsHwPushEn[7]  = CSL_FEXT (value,  CPTS_CONTROL_REG_HW8_TS_PUSH_EN);
    pCntlCfg->tsOutputBitSel = (CSL_CPTS_TS_OUTPUT_BIT) CSL_FEXT (value,  CPTS_CONTROL_REG_TS_SYNC_SEL);
    
    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_setCntllReg
 *
 *   @b Description
 *   @n This function sets up the contents of CPTS control register  
 *
 *   @b Arguments
     @verbatim
        pCntlCfg            CSL_CPTS_CONTROL contain settings for 
                            CPTS control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_CONTROL_REG_CPTS_EN
 *      CPTS_CONTROL_REG_INT_TEST   
 *      CPTS_CONTROL_REG_TS_COMP_POLARITY
 *      CPTS_CONTROL_REG_TSTAMP_EN
 *      CPTS_CONTROL_REG_SEQUENCE_EN
 *      CPTS_CONTROL_REG_MODE
 *      CPTS_CONTROL_REG_TS_COMP_TOG
 *      CPTS_CONTROL_REG_HW1_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW2_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW3_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW4_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW5_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW6_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW7_TS_PUSH_EN
 *      CPTS_CONTROL_REG_HW8_TS_PUSH_EN
 *      CPTS_CONTROL_REG_TS_SYNC_SEL
 *
 *   @b Example
 *   @verbatim
        CSL_CPTS_CONTROL     cntlCfg;
 
        CSL_CPTS_setCntlReg (&cntlCfg);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setCntlReg (
    CSL_CPTS_CONTROL*        pCntlCfg                
)
{
    Uint32 value = 0;
    
    CSL_FINS (value,  CPTS_CONTROL_REG_CPTS_EN, pCntlCfg->cptsEn);
    CSL_FINS (value,  CPTS_CONTROL_REG_INT_TEST, pCntlCfg->intTest);
    CSL_FINS (value,  CPTS_CONTROL_REG_TS_COMP_POLARITY, pCntlCfg->tsCompPolarity);
    CSL_FINS (value,  CPTS_CONTROL_REG_TSTAMP_EN, pCntlCfg->tstampEn);
    CSL_FINS (value,  CPTS_CONTROL_REG_SEQUENCE_EN, pCntlCfg->seqEn);
    CSL_FINS (value,  CPTS_CONTROL_REG_MODE, pCntlCfg->ts64bMode);
    CSL_FINS (value,  CPTS_CONTROL_REG_TS_COMP_TOG, pCntlCfg->tsCompToggle);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW1_TS_PUSH_EN, pCntlCfg->tsHwPushEn[0]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW2_TS_PUSH_EN, pCntlCfg->tsHwPushEn[1]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW3_TS_PUSH_EN, pCntlCfg->tsHwPushEn[2]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW4_TS_PUSH_EN, pCntlCfg->tsHwPushEn[3]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW5_TS_PUSH_EN, pCntlCfg->tsHwPushEn[4]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW6_TS_PUSH_EN, pCntlCfg->tsHwPushEn[5]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW7_TS_PUSH_EN, pCntlCfg->tsHwPushEn[6]);
    CSL_FINS (value,  CPTS_CONTROL_REG_HW8_TS_PUSH_EN, pCntlCfg->tsHwPushEn[7]);
    CSL_FINS (value,  CPTS_CONTROL_REG_TS_SYNC_SEL, (Uint32)pCntlCfg->tsOutputBitSel);
    hCptsRegs->CONTROL_REG = value;
    
    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_getRFTCLKSelectReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the reference clock select 
 *      register.
 *
 *   @b Arguments
     @verbatim
        pRefClockSelect         Reference clock select value read from hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_RFTCLK_SEL_REG_RFTCLK_SEL
 *
 *   @b Example
 *   @verbatim
        Uint32          refClockSelect;

        CSL_CPTS_getRFTCLKSelectReg (&refClockSelect);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_getRFTCLKSelectReg (
	Uint32*                     pRefClockSelect
)
{

    *pRefClockSelect    =   CSL_FEXT (hCptsRegs->RFTCLK_SEL_REG, CPTS_RFTCLK_SEL_REG_RFTCLK_SEL);

    return;        
}


/** ============================================================================
 *   @n@b CSL_CPTS_setRFTCLKSelectReg
 *
 *   @b Description
 *   @n This function sets up the reference clock select value. The Reference
 *      clock value can be setup only when the CPTS enable bit is cleared in
 *      the CPTS control register.
 *
 *   @b Arguments
     @verbatim
        refClockSetVal          Reference clock select value to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_CPTS_setTimeSyncControlReg () must be called to clear the
 *      CPTS enable bit before calling this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_RFTCLK_SEL_REG_RFTCLK_SEL
 *
 *   @b Example
 *   @verbatim
        Uint32          refClockSelect;

        refClockSelect  =   0;

        CSL_CPTS_setRFTCLKSelectReg (refClockSelect);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setRFTCLKSelectReg (
	Uint32                      refClockSetVal
)
{
    CSL_FINS (hCptsRegs->RFTCLK_SEL_REG, CPTS_RFTCLK_SEL_REG_RFTCLK_SEL, refClockSetVal);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_TSEventPush
 *
 *   @b Description
 *   @n This function writes an 1 to the Time Stamp Event Push register to 
 *      generate a timestamp event. The time stamp value is the time of the write 
 *      of this register, not the time of the event read. The time stamp value can then 
 *      be read on interrupt via the event registers.
 *
 *   @b Arguments
     @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_TS_PUSH_REG_TS_PUSH
 *
 *   @b Example
 *   @verbatim
        CSL_CPTS_TSEventPush ();
	 @endverbatim
 *
 *   @note: Software should not push a second time stamp event onto the event
 *          FIFO until the first time stamp value has been read from the event FIFO
 *          (there should be only one time stamp event in the event FIFO at any
 *          given time).    
 * =============================================================================
 */
static inline void CSL_CPTS_TSEventPush ( 
	void
)
{
    CSL_FINS (hCptsRegs->TS_PUSH_REG, CPTS_TS_PUSH_REG_TS_PUSH, 1);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_getTSLoadValReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the Time Stamp Load Value register.
 *
 *   @b Arguments
     @verbatim
        pTSLoadVal              Time stamp load value read from hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL
 *   @n CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL
 *
 *   @b Example
 *   @verbatim
        Uint32          tsLoadVal[2];

        CSL_CPTS_getTSLoadValReg (tsLoadVal);
	 @endverbatim
 *
 *   @note: When reading this register, the value read is not the time
 *          stamp, but is the value that was last written to this register.    
 * =============================================================================
 */
static inline void CSL_CPTS_getTSLoadValReg (
	Uint32*                     pTSLoadVal
)
{
    pTSLoadVal[0]     =   CSL_FEXT (hCptsRegs->TS_LOAD_LOW_VAL_REG, CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL);
    pTSLoadVal[1]     =   CSL_FEXT (hCptsRegs->TS_LOAD_HIGH_VAL_REG, CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL);
    
    return;        
}


/** ============================================================================
 *   @n@b CSL_CPTS_setTSLoadValReg
 *
 *   @b Description
 *   @n This function sets up the Time Stamp Load Value.
 *
 *   @b Arguments
     @verbatim
        tsLoadVal               Time stamp load value to configure.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL
 *   @n CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL
 *
 *   @b Example
 *   @verbatim
        Uint64          tsLoadVal;

        tsLoadVal   =   0;

        CSL_CPTS_setTSLoadValReg (tsLoadVal);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setTSLoadValReg 
(
	Uint32                      tsLoadValLo,
	Uint32                      tsLoadValHi
)
{
    CSL_FINS (hCptsRegs->TS_LOAD_LOW_VAL_REG, CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL, tsLoadValLo);
    CSL_FINS (hCptsRegs->TS_LOAD_HIGH_VAL_REG, CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL, tsLoadValHi);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_setTSVal
 *
 *   @b Description
 *   @n This function sets the Time Stamp Value.
 *
 *   @b Arguments
     @verbatim
        tsVal               Time stamp value to be loaded.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL
 *   @n CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL
 *   @n CPTS_TS_LOAD_EN_REG_TS_LOAD_EN
 *
 *   @b Example
 *   @verbatim
        Uint64          tsVal;

        tsVal   =   0;

        CSL_CPTS_setTSVal (tsVal);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setTSVal 
(
	Uint32                      tsValLo,
	Uint32                      tsValHi
)
{
    CSL_FINS (hCptsRegs->TS_LOAD_LOW_VAL_REG, CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL, tsValLo);
    CSL_FINS (hCptsRegs->TS_LOAD_HIGH_VAL_REG, CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL, tsValHi);
    CSL_FINS (hCptsRegs->TS_LOAD_EN_REG, CPTS_TS_LOAD_EN_REG_TS_LOAD_EN, 1);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_setTSCompVal
 *
 *   @b Description
 *   @n This function sets the Time Stamp Compare Value and triggers the Time Stamp
 *      Comparsion operation.
 *
 *   @b Arguments
     @verbatim
        tsCompVal               Time stamp compare value to be loaded.
        tsCompLen               Length of the TS_COMP output pluse in non-toggle mode
                                Half Period of the TS_COMP wave in toggle mode
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL
 *   @n CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL
 *   @n CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH
 *
 *   @b Example
 *   @verbatim
        Uint64          tsCompVal;
        Uint32          tsCompLen;

        tsCompVal   =   0x3000;
        tsCompLen   =   1000;

        CSL_CPTS_setTSCompVal (tsCompVal, tsCompLen);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setTSCompVal 
(
	Uint32                      tsCompValLo,
	Uint32                      tsCompValHi,
    Uint32                      tsCompLen
)
{
    CSL_FINS (hCptsRegs->TS_COMP_LEN_REG, CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH, 0);
    CSL_FINS (hCptsRegs->TS_COMP_LOW_VAL_REG, CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL, tsCompValLo);
    CSL_FINS (hCptsRegs->TS_COMP_HIGH_VAL_REG, CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL, tsCompValHi);
    CSL_FINS (hCptsRegs->TS_COMP_LEN_REG, CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH, tsCompLen);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_setTSCompNudge
 *
 *   @b Description
 *   @n This function sets the Time Stamp Compare Nudge Value to adjust the phase
 *      of time compare wave in Toggle mode. This two's complement number is added 
 *      to the ts_comp_length[23:0] value to increase or decrease the TS_COMP length 
 *      by the ts_comp_nudge amount. Only a single high or low time is adjusted
 *      and the tsCompNudge value is cleared to zero when the nudge has occurred.
 *
 *   @b Arguments
     @verbatim
        tsCompNudge             Time stamp compare nudge value [-128, 127]
 *       
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Affects
 *   @n CPTS_TS_COMP_NUDGE_REG_NUDGE
 *
 *   @b Example
 *   @verbatim
        Int32          tsCompNudge;

        tsCompNudge   =   -2;

        CSL_CPTS_setTSCompNudge (tsCompNudge);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_setTSCompNudge 
(
	Int32                       tsCompNudge
)
{
    CSL_FINS (hCptsRegs->TS_COMP_NUDGE_REG, CPTS_TS_COMP_NUDGE_REG_NUDGE, tsCompNudge);

    return;        
}

/** ============================================================================
 *   @n@b CSL_CPTS_isRawInterruptStatusBitSet
 *
 *   @b Description
 *   @n This function checks the Time Sync Raw Pending Interrupt Register to 
 *      determine if there is one or more events in the event FIFO.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   One or more events in FIFO. Raw interrupt status
 *	                            bit set.
 *	 @n  FALSE                  No events in FIFO. Raw interrupt status bit cleared.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_INTSTAT_RAW_REG_TS_PEND_RAW
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPTS_isRawInterruptStatusBitSet () == TRUE)
        {
           // interrupt set 
        }
        else
        {
            // interrupt bit not set
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPTS_isRawInterruptStatusBitSet (void)
{

    return CSL_FEXT (hCptsRegs->INTSTAT_RAW_REG, CPTS_INTSTAT_RAW_REG_TS_PEND_RAW);
}

/** ============================================================================
 *   @n@b CSL_CPTS_isMaskedInterruptStatusBitSet
 *
 *   @b Description
 *   @n This function checks the Time Sync Interrupt Status Masked Register to 
 *      determine if there is one or more events in the event FIFO.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   One or more events in FIFO. masked interrupt status
 *	                            bit set.
 *	 @n  FALSE                  No events in FIFO. masked interrupt status bit cleared.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_INTSTAT_MASKED_REG_TS_PEND
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPTS_isMaskedInterruptStatusBitSet () == TRUE)
        {
           // masked interrupt set 
        }
        else
        {
            // masked interrupt bit not set
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPTS_isMaskedInterruptStatusBitSet (void)
{

    return CSL_FEXT (hCptsRegs->INTSTAT_MASKED_REG, CPTS_INTSTAT_MASKED_REG_TS_PEND);
}

/** ============================================================================
 *   @n@b CSL_CPTS_isInterruptEnabled
 *
 *   @b Description
 *   @n This function indicates if Time sync interrupts are enabled.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Time sync interrupts enabled.
 *	 @n  FALSE                  Time sync interrupts disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_INT_ENABLE_REG_TS_PEND_EN
 *
 *   @b Example
 *   @verbatim
        if (CSL_CPTS_isInterruptEnabled () == TRUE)
        {
           // interrupts enabled 
        }
        else
        {
            // interrupts disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPTS_isInterruptEnabled (void)
{

    return CSL_FEXT (hCptsRegs->INT_ENABLE_REG, CPTS_INT_ENABLE_REG_TS_PEND_EN);
}

/** ============================================================================
 *   @n@b CSL_CPTS_enableInterrupt
 *
 *   @b Description
 *   @n This function enables the interrupts in Time sync submodule.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_INT_ENABLE_REG_TS_PEND_EN=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPTS_enableInterrupt ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_enableInterrupt (void)
{
    CSL_FINS (hCptsRegs->INT_ENABLE_REG, CPTS_INT_ENABLE_REG_TS_PEND_EN, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_disableInterrupt
 *
 *   @b Description
 *   @n This function disables the interrupts in Time sync submodule.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_INT_ENABLE_REG_TS_PEND_EN=0
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPTS_disableInterrupt ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_disableInterrupt (void)
{
    CSL_FINS (hCptsRegs->INT_ENABLE_REG, CPTS_INT_ENABLE_REG_TS_PEND_EN, 0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_popEvent
 *
 *   @b Description
 *   @n This function sets up the Event pop bit in Event pop register. This 
 *      initiates an event to be popped off the event FIFO. Popping an event discards 
 *      the event and causes the next event, if any, to be moved to the top of 
 *      the FIFO ready to be read by software on interrupt.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPTS_EVENT_POP_REG_EVENT_POP=1
 *
 *   @b Example
 *   @verbatim
 
        CSL_CPTS_popEvent ();
	 
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_popEvent (void)
{
    CSL_FINS (hCptsRegs->EVENT_POP_REG, CPTS_EVENT_POP_REG_EVENT_POP, 1);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPTS_getEventInfo
 *
 *   @b Description
 *   @n This function retrieves the contents of the Event Low, Event Middle and Event High
 *      registers.
 *
 *   @b Arguments
     @verbatim
        pEventInfo              CSL_CPTS_EVENTINFO structure that needs to be filled
                                with time sync event info read from hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPTS_EVENT_LOW_REG_TIME_STAMP,
 *      CPTS_EVENT_MIDDLE_REG_SEQUENCE_ID,
 *      CPTS_EVENT_MIDDLE_REG_MESSAGE_TYPE,
 *      CPTS_EVENT_MIDDLE_REG_EVENT_TYPE,
 *      CPTS_EVENT_MIDDLE_REG_PORT_NUMBER,
 *      CPTS_EVENT_HIGH_REG_DOMAIN
 *
 *   @b Example
 *   @verbatim
        CSL_CPTS_EVENTINFO          eventInfo;

        CSL_CPTS_getEventInfo (&eventInfo);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPTS_getEventInfo (
	CSL_CPTS_EVENTINFO*         pEventInfo
)
{
    pEventInfo->timeStamp   =   CSL_FEXT (hCptsRegs->EVENT_0_REG, CPTS_EVENT_0_REG_TIME_STAMP);
    pEventInfo->seqId       =   CSL_FEXT (hCptsRegs->EVENT_1_REG, CPTS_EVENT_1_REG_SEQUENCE_ID);
    pEventInfo->msgType     =   CSL_FEXT (hCptsRegs->EVENT_1_REG, CPTS_EVENT_1_REG_MESSAGE_TYPE);
    pEventInfo->eventType   =   CSL_FEXT (hCptsRegs->EVENT_1_REG, CPTS_EVENT_1_REG_EVENT_TYPE);
    pEventInfo->portNo      =   CSL_FEXT (hCptsRegs->EVENT_1_REG, CPTS_EVENT_1_REG_PORT_NUMBER);
    pEventInfo->domain      =   CSL_FEXT (hCptsRegs->EVENT_2_REG, CPTS_EVENT_2_REG_DOMAIN);
    pEventInfo->timeStampHi   =   CSL_FEXT (hCptsRegs->EVENT_3_REG, CPTS_EVENT_3_REG_TIME_STAMP);

    return;        
}

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
