/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008, 2009
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

/** ============================================================================
 *   @file  csl_aif2GetHwStatusAux.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @brief  API Auxilary header file for Antenna Interface 2 set HW status
 *
 */

/* =============================================================================
 * Revision History
 * ===============
 *  03-Jun-2009 Albert  File Created.
 *  
 *
 * =============================================================================
 */

#ifndef CSL_AIF2GETHWSTATUSAUX_H
#define CSL_AIF2GETHWSTATUSAUX_H
 
#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/src/ip/aif2/V0/csl_aif2.h>

/**
 *  Get Hardware Status Functions of Antenna Interface 2
 */

/** ============================================================================
 *   @n@b CSL_aif2GetVersion
 *
 *   @b Description
 *   @n This function returns AIF2 version 
 *
 *   @b Arguments
 *   @verbatim

            hAif2        Handle to the aif2 instance
            version     Pointer to get the version instance.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.

 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_AIF2_PID_MINOR,AIF2_AIF2_PID_CUSTOM,AIF2_AIF2_PID_MAJOR,
 *        AIF2_AIF2_PID_RTL,AIF2_AIF2_PID_FUNC,AIF2_AIF2_PID_SCHEME
 *   @b Example
 *   @verbatim
        CSL_Aif2PidStatus   version;
        CSL_aif2GetVersion (hAif2,  &version);
     @endverbatim
 * ===========================================================================
 */
static inline void CSL_aif2GetVersion (CSL_Aif2Handle   hAif2, CSL_Aif2PidStatus*   version); /*for misra warnings*/
static inline void CSL_aif2GetVersion (CSL_Aif2Handle   hAif2, CSL_Aif2PidStatus*   version)
{
	Uint32 tmpReg;
	tmpReg = hAif2->regs->AIF2_PID;	
	version->minor = CSL_FEXT(tmpReg, AIF2_AIF2_PID_MINOR);
 	version->custom = CSL_FEXT(tmpReg, AIF2_AIF2_PID_CUSTOM);
	version->major = CSL_FEXT(tmpReg, AIF2_AIF2_PID_MAJOR);
	version->RTL = CSL_FEXT(tmpReg, AIF2_AIF2_PID_RTL);
 	version->func = CSL_FEXT(tmpReg, AIF2_AIF2_PID_FUNC);
	version->scheme = CSL_FEXT(tmpReg, AIF2_AIF2_PID_SCHEME);
}


/** ============================================================================
 *   @n@b CSL_aif2GetVcStat
 *
 *   @b Description
 *   @n This function return the status of VC emu status
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance 
                       
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_VC_STAT_EMU_HALT
 *        
 *
 *   @b Example
 *   @verbatim
        Bool emu_sts;
        emu_sts = CSL_aif2GetVcStat (hAif2);
     @endverbatim
 * ===========================================================================
 */
static inline Bool CSL_aif2GetVcStat(CSL_Aif2Handle   hAif2); /*for misra warnings*/
static inline Bool CSL_aif2GetVcStat(CSL_Aif2Handle   hAif2)
{
	return CSL_FEXT(hAif2->regs->VC_STAT, AIF2_VC_STAT_EMU_HALT) ? TRUE : FALSE;
}


/** ============================================================================
 *   @n@b CSL_aif2GetSdRxLinkStatus
 *
 *   @b Description
 *   @n This function return the status of SD Rx link status
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance
           CSL_Aif2SdRxStatus*       pSdRxStat          
     @endverbatim
 *
 *   <b> Return Value </b> void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_SD_RX_STS_RXSYNC,AIF2_SD_RX_STS_RXLOSS_OF_SIGNAL,
 *         AIF2_SD_RX_STS_RXADAPT_DONE
 *   @b Example
 *   @verbatim
        CSL_Aif2SdRxStatus       SdRxStat;
        .....
        CSL_aif2GetSdRxLinkStatus (hAif2, &SdRxStat );
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetSdRxLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2SdRxStatus*       pSdRxStat
);
static inline
void CSL_aif2GetSdRxLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2SdRxStatus*       pSdRxStat
)
{
    pSdRxStat->sdRxSync = CSL_FEXT(hAif2->regs->SD_LK[hAif2->arg_link].SD_RX_STS,AIF2_SD_RX_STS_RXSYNC) ? TRUE : FALSE;
    pSdRxStat->sdRxLosDetect = CSL_FEXT(hAif2->regs->SD_LK[hAif2->arg_link].SD_RX_STS,AIF2_SD_RX_STS_RXLOSS_OF_SIGNAL) ? TRUE : FALSE;
    pSdRxStat->sdRxAdaptDone = CSL_FEXT(hAif2->regs->SD_LK[hAif2->arg_link].SD_RX_STS,AIF2_SD_RX_STS_RXADAPT_DONE) ? TRUE : FALSE;
}


/** ============================================================================
 *   @n@b CSL_aif2GetSdB8PllLock
 *
 *   @b Description
 *   @n This function return the status of B8 PLL lock 
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance 
                       
     @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_SD_PLL_B8_STS_B8PLL_LOCK
 *        
 *
 *   @b Example
 *   @verbatim
        Uint8 lock_sts;
        lock_sts = CSL_aif2GetSdB8PllLock (hAif2);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetSdB8PllLock (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetSdB8PllLock (
        CSL_Aif2Handle   hAif2
)
{
	return (Uint8)CSL_FEXT(hAif2->regs->SD_PLL_B8_STS, AIF2_SD_PLL_B8_STS_B8PLL_LOCK);
}


/** ============================================================================
 *   @n@b CSL_aif2GetSdB4PllLock
 *
 *   @b Description
 *   @n This function return the status of B4 PLL lock 
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance 
                       
     @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_SD_PLL_B4_STS_B4PLL_LOCK
 *        
 *
 *   @b Example
 *   @verbatim
        Uint8 lock_sts;
        lock_sts = CSL_aif2GetSdB4PllLock (hAif2);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetSdB4PllLock (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetSdB4PllLock (
        CSL_Aif2Handle   hAif2
)
{
	return (Uint8)CSL_FEXT(hAif2->regs->SD_PLL_B4_STS, AIF2_SD_PLL_B4_STS_B4PLL_LOCK);
}


/** ============================================================================
 *   @n@b CSL_aif2GetRmLinkStatus0
 *
 *   @b Description
 *   @n This function gets the  RM  link Status 0
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           CSL_Aif2RmStatus0       Pointer to the RM link Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RM_LK_STS0_SYNC_STATUS,AIF2_RM_LK_STS0_LOS,AIF2_RM_LK_STS0_NUM_LOS_DET,
 *        AIF2_RM_LK_STS0_LOC,AIF2_RM_LK_STS0_FIFO_OVF
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2RmStatus0     RmStat;
         hAif2->arg_link = 1; //get link1 status
        CSL_aif2GetRmLinkStatus0 (hAif2, &RmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRmLinkStatus0 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus0*    pRmStat
);
static inline
void CSL_aif2GetRmLinkStatus0 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus0*    pRmStat
)
{   
    pRmStat->rmSyncStatus = (CSL_Aif2RmSyncState)CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS0,AIF2_RM_LK_STS0_SYNC_STATUS);
    pRmStat->rmLos = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS0,AIF2_RM_LK_STS0_LOS) ? TRUE : FALSE;
    pRmStat->rmNumLosDetect = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS0,AIF2_RM_LK_STS0_NUM_LOS_DET) ? TRUE : FALSE;
    pRmStat->rmLoc = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS0,AIF2_RM_LK_STS0_LOC) ? TRUE : FALSE;
    pRmStat->rmFifoOverflow = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS0,AIF2_RM_LK_STS0_FIFO_OVF) ? TRUE : FALSE;
    
}


/** ============================================================================
 *   @n@b CSL_aif2GetRmLinkStatus1
 *
 *   @b Description
 *   @n This function gets the  RM  link Status 1
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           CSL_Aif2RmStatus1       Pointer to the RM link Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RM_LK_STS1_NUM_LOS,AIF2_RM_LK_STS1_LCV_CNTR_VALUE
 *        
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2RmStatus1     RmStat;
         hAif2->arg_link = 1; //get link1 status
        CSL_aif2GetRmLinkStatus1 (hAif2, &RmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRmLinkStatus1 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus1*    pRmStat
);
static inline
void CSL_aif2GetRmLinkStatus1 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus1*    pRmStat
)
{   
    pRmStat->rmNumLos = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS1,AIF2_RM_LK_STS1_NUM_LOS);
    pRmStat->rmLcvCountValue = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS1,AIF2_RM_LK_STS1_LCV_CNTR_VALUE);
    
}


/** ============================================================================
 *   @n@b CSL_aif2GetRmLinkStatus2
 *
 *   @b Description
 *   @n This function gets the  RM  link Status 2
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           CSL_Aif2RmStatus2       Pointer to the RM link Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RM_LK_STS2_CLK_QUAL,AIF2_RM_LK_STS2_SCR_VALUE
 *        
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2RmStatus2     RmStat;
         hAif2->arg_link = 1; //get link1 status
        CSL_aif2GetRmLinkStatus2 (hAif2, &RmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRmLinkStatus2 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus2*    pRmStat
);
static inline
void CSL_aif2GetRmLinkStatus2 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus2*    pRmStat
)
{   
    pRmStat->rmClockQuality = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS2,AIF2_RM_LK_STS2_CLK_QUAL);
    pRmStat->rmScrValue = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS2,AIF2_RM_LK_STS2_SCR_VALUE);
    
}

/** ============================================================================
 *   @n@b CSL_aif2GetRmLinkStatus3
 *
 *   @b Description
 *   @n This function gets the  RM  link Status 3
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           CSL_Aif2RmStatus3       Pointer to the RM link Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RM_LK_STS3_HFN,AIF2_RM_LK_STS3_BFN_LOW,AIF2_RM_LK_STS3_BFN_HIGH,
 *        AIF2_RM_LK_STS3_HFSYNC_STATE,AIF2_RM_LK_STS3_LOF_STATE
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2RmStatus3     RmStat;
         hAif2->arg_link = 1; //get link1 status
        CSL_aif2GetRmLinkStatus3 (hAif2, &RmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRmLinkStatus3 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus3*    pRmStat
);
static inline
void CSL_aif2GetRmLinkStatus3 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus3*    pRmStat
)
{   
    pRmStat->rmHfn = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS3,AIF2_RM_LK_STS3_HFN);
    pRmStat->rmBfnLow = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS3,AIF2_RM_LK_STS3_BFN_LOW);
    pRmStat->rmBfnHigh = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS3,AIF2_RM_LK_STS3_BFN_HIGH);
    pRmStat->rmHfsyncState = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS3,AIF2_RM_LK_STS3_HFSYNC_STATE) ? TRUE : FALSE;
    pRmStat->rmLofState = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS3,AIF2_RM_LK_STS3_LOF_STATE) ? TRUE : FALSE;
    
}


/** ============================================================================
 *   @n@b CSL_aif2GetRmLinkStatus4
 *
 *   @b Description
 *   @n This function gets the  RM  link Status 4
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           CSL_Aif2RmStatus4       Pointer to the RM link Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RM_LK_STS4_L1_VERSION,AIF2_RM_LK_STS4_L1_START_UP,AIF2_RM_LK_STS4_L1_RCVD_RST,
 *        AIF2_RM_LK_STS4_L1_RCVD_RAI,AIF2_RM_LK_STS4_L1_RCVD_SDI,AIF2_RM_LK_STS4_L1_RCVD_LOS,
 *        AIF2_RM_LK_STS4_L1_RCVD_LOF,AIF2_RM_LK_STS4_L1_PNTR_P
 *   @b Example
 *   @verbatim
         CSL_Aif2RmStatus4     RmStat;
         hAif2->arg_link = 1; //get link1 status
        CSL_aif2GetRmLinkStatus4 (hAif2, &RmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRmLinkStatus4 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus4*    pRmStat
);
static inline
void CSL_aif2GetRmLinkStatus4 (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RmStatus4*    pRmStat
)
{   
    pRmStat->rmL1Version = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_VERSION);
    pRmStat->rmL1Startup = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_START_UP);
    pRmStat->rmL1RST = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_RCVD_RST) ? TRUE : FALSE;
    pRmStat->rmL1RAI = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_RCVD_RAI) ? TRUE : FALSE;
    pRmStat->rmL1SDI = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_RCVD_SDI) ? TRUE : FALSE;
    pRmStat->rmL1LOS = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_RCVD_LOS) ? TRUE : FALSE;
    pRmStat->rmL1LOF = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_RCVD_LOF) ? TRUE : FALSE;
    pRmStat->rmL1PointerP = CSL_FEXT(hAif2->regs->G_RM_LKS[hAif2->arg_link].RM_LK_STS4,AIF2_RM_LK_STS4_L1_PNTR_P) ? TRUE : FALSE;
    
}


/** ============================================================================
 *   @n@b CSL_aif2GetTmCpriHfnStatus
 *
 *   @b Description
 *   @n This function return the status of TM CPRI HFN status
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance. should use arg_link to select link 
                       
     @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_TM_LK_HFN_HFN
 *        
 *
 *   @b Example
 *   @verbatim
        Uint8 hfn_sts;
        hAif2->arg_link = LINK1;
        hfn_sts = CSL_aif2GetTmCpriHfnStatus (hAif2);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetTmCpriHfnStatus (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetTmCpriHfnStatus (
        CSL_Aif2Handle   hAif2
)
{
	return (Uint8)CSL_FEXT(hAif2->regs->G_TM_LKS[hAif2->arg_link].TM_LK_HFN, AIF2_TM_LK_HFN_HFN);
}


/** ============================================================================
 *   @n@b CSL_aif2GetTmLinkStatus
 *
 *   @b Description
 *   @n This function gets the  TM  link Status
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance. should use arg_link to select link
           pTmStat       Pointer to the TM link Status instance.
            
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_TM_LK_STAT_TM_FAIL,AIF2_TM_LK_STAT_FIFO_UNFL,
 *        AIF2_TM_LK_STAT_FRM_MISALIGN,AIF2_TM_LK_STAT_FRM_STATE
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2TmStatus     TmStat;
         hAif2->arg_link = 1; //get Tm link1 status
        CSL_aif2GetTmLinkStatus (hAif2, &TmStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetTmLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2TmStatus*    pTmStat
);
static inline
void CSL_aif2GetTmLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2TmStatus*    pTmStat
)
{   
    pTmStat->tmFail = CSL_FEXT(hAif2->regs->G_TM_LKS[hAif2->arg_link].TM_LK_STAT,AIF2_TM_LK_STAT_TM_FAIL) ? TRUE : FALSE;
    pTmStat->tmFifoUnderflow = CSL_FEXT(hAif2->regs->G_TM_LKS[hAif2->arg_link].TM_LK_STAT,AIF2_TM_LK_STAT_FIFO_UNFL) ? TRUE : FALSE;
    pTmStat->tmFrameMisalign = CSL_FEXT(hAif2->regs->G_TM_LKS[hAif2->arg_link].TM_LK_STAT,AIF2_TM_LK_STAT_FRM_MISALIGN) ? TRUE : FALSE;
    pTmStat->tmFrameStatus = (CSL_Aif2TmSyncState)CSL_FEXT(hAif2->regs->G_TM_LKS[hAif2->arg_link].TM_LK_STAT,AIF2_TM_LK_STAT_FRM_STATE);
    
}


/** ============================================================================
 *   @n@b CSL_aif2GetRtFifoDepthStatus
 *
 *   @b Description
 *   @n RT Internal FIFO depth Status.
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link 
     @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RT_LK_DPTH_RT_DEPTH
 *        
 *   @b Example
 *   @verbatim
        Uint8 depth;
        hAif2->arg_link = LINK1;
        depth = CSL_aif2GetRtFifoDepthStatus (hAif2);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetRtFifoDepthStatus (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetRtFifoDepthStatus (
        CSL_Aif2Handle   hAif2
)
{
	return (Uint8)CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_DPTH, AIF2_RT_LK_DPTH_RT_DEPTH);
}


/** ============================================================================
 *   @n@b CSL_aif2GetRtHeaderStatus
 *
 *   @b Description
 *   @n This function gets the  Retransmitter  link Status
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           pRtStat       Pointer to the retransmitter header Status instance.
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RT_HDR_ERR_DMA_CHAN,AIF2_RT_HDR_ERR_HDR_ERR
 *        
 *   @b Example
 *   @verbatim
         CSL_Aif2RtHeaderStatus     RtStat;
         hAif2->arg_link = 1; //get Rt link1 status
        CSL_aif2GetRtHeaderStatus (hAif2, &RtStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRtHeaderStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RtHeaderStatus*    pRtStat
);
static inline
void CSL_aif2GetRtHeaderStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RtHeaderStatus*    pRtStat
)
{   
    pRtStat->HeaderError = CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_HDR_ERR,AIF2_RT_HDR_ERR_HDR_ERR) ? TRUE : FALSE;
    pRtStat->DmaChannel = CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_HDR_ERR,AIF2_RT_HDR_ERR_DMA_CHAN);
}


/** ============================================================================
 *   @n@b CSL_aif2GetRtLinkStatus
 *
 *   @b Description
 *   @n This function gets the  Retransmitter  link Status
 *
 *   @b Arguments
 *   @verbatim

           hAif2      Handle to the aif2 instance. should use arg_link to select link
           pRtStat       Pointer to the retransmitter link Status instance.
            
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_RT_LK_STAT_RT_HDR_ERR_STS,AIF2_RT_LK_STAT_RT_EM_STS,
 *        AIF2_RT_LK_STAT_RT_UNFL_STS,AIF2_RT_LK_STAT_RT_OVFL_STS,
 *        AIF2_RT_LK_STAT_RT_FRM_ERR_STS
 *   @b Example
 *   @verbatim
         CSL_Aif2RtStatus     RtStat;
         hAif2->arg_link = 1; //get Rt link1 status
        CSL_aif2GetRtLinkStatus (hAif2, &RtStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetRtLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RtStatus*    pRtStat
);
static inline
void CSL_aif2GetRtLinkStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2RtStatus*    pRtStat
)
{   
    pRtStat->rtHeaderError = CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_STAT,AIF2_RT_LK_STAT_RT_HDR_ERR_STS) ? TRUE : FALSE;
    pRtStat->rtEmptyMessage = CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_STAT,AIF2_RT_LK_STAT_RT_EM_STS) ? TRUE : FALSE;
    pRtStat->rtFifoUnderflow = CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_STAT,AIF2_RT_LK_STAT_RT_UNFL_STS) ? TRUE : FALSE;
    pRtStat->rtFifoOverflow= CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_STAT,AIF2_RT_LK_STAT_RT_OVFL_STS) ? TRUE : FALSE;
    pRtStat->rtFrameError= CSL_FEXT(hAif2->regs->G_RT_LKS[hAif2->arg_link].RT_LK_STAT,AIF2_RT_LK_STAT_RT_FRM_ERR_STS) ? TRUE : FALSE;
}


/** ============================================================================
 *   @n@b CSL_aif2GetPdChannelStatus
 *
 *   @b Description
 *   @n This function get PD 128 Channel Status.
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           Uint32*       Pointer to the PD channel Status instance.       
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_PD_CHAN_STS_CHAN_ON
 *        
 *   @b Example
 *   @verbatim
         Uint32     PdChanStat[4];
         
        CSL_aif2GetPdChannelStatus (hAif2, &PdChanStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetPdChannelStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          ChanStat
);
static inline
void CSL_aif2GetPdChannelStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          ChanStat
)
{   
    ChanStat[0] = CSL_FEXT(hAif2->regs->PD_CHAN_STS[0],AIF2_PD_CHAN_STS_CHAN_ON);
    ChanStat[1] = CSL_FEXT(hAif2->regs->PD_CHAN_STS[1],AIF2_PD_CHAN_STS_CHAN_ON);
    ChanStat[2] = CSL_FEXT(hAif2->regs->PD_CHAN_STS[2],AIF2_PD_CHAN_STS_CHAN_ON);
    ChanStat[3] = CSL_FEXT(hAif2->regs->PD_CHAN_STS[3],AIF2_PD_CHAN_STS_CHAN_ON);
}


/** ============================================================================
 *   @n@b CSL_aif2GetPdPacketStatus
 *
 *   @b Description
 *   @n This function get PD packet status for 128 Channels.
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           Uint32*       Pointer to the PD packet Status instance. bit 0: out packet  bit 1: in packet       
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_PD_PKT_STS_CHAN_PKT
 *        
 *   @b Example
 *   @verbatim
         Uint32     PdPacketStat[4];
         
        CSL_aif2GetPdPacketStatus (hAif2, &PdPacketStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetPdPacketStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          PacketStat
);
static inline
void CSL_aif2GetPdPacketStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          PacketStat
)
{   
    PacketStat[0] = CSL_FEXT(hAif2->regs->PD_PKT_STS[0],AIF2_PD_PKT_STS_CHAN_PKT);
    PacketStat[1] = CSL_FEXT(hAif2->regs->PD_PKT_STS[1],AIF2_PD_PKT_STS_CHAN_PKT);
    PacketStat[2] = CSL_FEXT(hAif2->regs->PD_PKT_STS[2],AIF2_PD_PKT_STS_CHAN_PKT);
    PacketStat[3] = CSL_FEXT(hAif2->regs->PD_PKT_STS[3],AIF2_PD_PKT_STS_CHAN_PKT);
}


/** ============================================================================
 *   @n@b CSL_aif2GetPeChannelStatus
 *
 *   @b Description
 *   @n This function get PE 128 Channel Status.
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           Uint32*       Pointer to the PE channel Status instance.       
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_PE_CHAN_STS_CHAN_ON_STS
 *        
 *   @b Example
 *   @verbatim
         Uint32     PeChanStat[4];
         
        CSL_aif2GetPeChannelStatus (hAif2, &PeChanStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetPeChannelStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          ChanStat
);
static inline
void CSL_aif2GetPeChannelStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          ChanStat
)
{   
    ChanStat[0] = CSL_FEXT(hAif2->regs->PE_CHAN_STS[0],AIF2_PE_CHAN_STS_CHAN_ON_STS);
    ChanStat[1] = CSL_FEXT(hAif2->regs->PE_CHAN_STS[1],AIF2_PE_CHAN_STS_CHAN_ON_STS);
    ChanStat[2] = CSL_FEXT(hAif2->regs->PE_CHAN_STS[2],AIF2_PE_CHAN_STS_CHAN_ON_STS);
    ChanStat[3] = CSL_FEXT(hAif2->regs->PE_CHAN_STS[3],AIF2_PE_CHAN_STS_CHAN_ON_STS);
}


/** ============================================================================
 *   @n@b CSL_aif2GetPePacketStatus
 *
 *   @b Description
 *   @n This function get PE packet status for 128 Channels.
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance. should use arg_link to select link
           Uint32*       Pointer to the PE packet Status instance. bit 0: out packet  bit 1: in packet       
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_PE_PKT_STS_PKT_STS
 *        
 *   @b Example
 *   @verbatim
         Uint32     PePacketStat[4];
         
        CSL_aif2GetPePacketStatus (hAif2, &PePacketStat);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetPePacketStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          PacketStat
);
static inline
void CSL_aif2GetPePacketStatus (
        CSL_Aif2Handle   hAif2,
        Uint32*          PacketStat
)
{   
    PacketStat[0] = CSL_FEXT(hAif2->regs->PE_PKT_STS[0],AIF2_PE_PKT_STS_PKT_STS);
    PacketStat[1] = CSL_FEXT(hAif2->regs->PE_PKT_STS[1],AIF2_PE_PKT_STS_PKT_STS);
    PacketStat[2] = CSL_FEXT(hAif2->regs->PE_PKT_STS[2],AIF2_PE_PKT_STS_PKT_STS);
    PacketStat[3] = CSL_FEXT(hAif2->regs->PE_PKT_STS[3],AIF2_PE_PKT_STS_PKT_STS);
}


 /** ============================================================================
 *   @n@b CSL_aif2GetInDbDebugOffsetData
 *
 *   @b Description
 *   @n Get Write and Read Offset Value at address in DB_IDB_DEBUG_OFS
 *
 *   @b Arguments
 *   @verbatim
 
           hAif2            Handle to the aif2 instance     
           Uint8*          pointer to write and read offset data 
     @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_DB_IDB_DEBUG_OFS_DAT_WOFF
 *
 *   @b Example
 *   @verbatim
        Uint8  offset[2];
        
        CSL_aif2GetInDbDebugOffsetData(hAif2, &offset[0]);

        Uint8 write_offset = offset[0];
        Uint8 read_offset = offset[1];
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetInDbDebugOffsetData (
        CSL_Aif2Handle   hAif2,
        Uint8*                offset
);
static inline
void CSL_aif2GetInDbDebugOffsetData (
        CSL_Aif2Handle   hAif2,
        Uint8*                offset
)
{ 
	
     offset[0] = CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_OFS_DAT,AIF2_DB_IDB_DEBUG_OFS_DAT_WOFF);
	 offset[1] = CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_OFS_DAT,AIF2_DB_IDB_DEBUG_OFS_DAT_ROFF);
}


/** ============================================================================
 *   @n@b CSL_aif2GetEDbDebugData
 *
 *   @b Description
 *   @n Get Debug data written to Egress DB RAM (128 bit)
 *
 *   @b Arguments
 *   @verbatim

            hAif2    Handle to the aif2 instance
            
            *Uint32   pointer to 128 bit Debug data 

     @endverbatim
 *
 *   <b> Return Value </b>  void
 *
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n AIF2_DB_EDB_DEBUG_D0_DATA
 *
 *   @b Example
 *   @verbatim
        Uint32    DebugData[4];
       
        CSL_aif2GetEDbDebugData(hAif2, &DebugData[0]);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEDbDebugData(
    CSL_Aif2Handle    hAif2,
    Uint32*                debug_data
);
static inline
void CSL_aif2GetEDbDebugData(
    CSL_Aif2Handle    hAif2,
    Uint32*                debug_data
)
{
    debug_data[0] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_D0, AIF2_DB_EDB_DEBUG_D0_DATA);  
    debug_data[1] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_D1, AIF2_DB_EDB_DEBUG_D1_DATA);  
    debug_data[2] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_D2, AIF2_DB_EDB_DEBUG_D2_DATA);  
    debug_data[3] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_D3, AIF2_DB_EDB_DEBUG_D3_DATA);  
}
 


/** ============================================================================
 *   @n@b CSL_aif2GetEDbDebugSideData
 *
 *   @b Description
 *   @n Get Egress DB debug side band data (sop, eop, xcnt only)
 *
 *   @b Arguments
 *   @verbatim

            hAif2    Handle to the aif2 instance
            
            CSL_Aif2DbSideData     Side data structure for debug

     @endverbatim
 *
 *   <b> Return Value </b>  void
 *
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n 
 *        AIF2_DB_EDB_DEBUG_SBND_SOP,AIF2_DB_EDB_DEBUG_SBND_EOP,
 *        AIF2_DB_EDB_DEBUG_SBND_XCNT,AIF2_DB_EDB_DEBUG_SBND_SYMBOL
 *
 *   @b Example
 *   @verbatim
        CSL_Aif2DbSideData   SideData;
         
        CSL_aif2GetEDbDebugSideData(hAif2, &SideData);

        SideData.bSop = ...;
        SideData.bEop = ...;
        SideData.xcnt = ...;
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEDbDebugSideData(
    CSL_Aif2Handle    hAif2,
    CSL_Aif2DbSideData*          side_data
);
static inline
void CSL_aif2GetEDbDebugSideData(
    CSL_Aif2Handle    hAif2,
    CSL_Aif2DbSideData*          side_data
)
{
     side_data->bSop =     CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_SBND,AIF2_DB_EDB_DEBUG_SBND_SOP) ? TRUE : FALSE;
     side_data->bEop =     CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_SBND,AIF2_DB_EDB_DEBUG_SBND_EOP) ? TRUE : FALSE;
     side_data->xcnt  =     CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_SBND,AIF2_DB_EDB_DEBUG_SBND_XCNT);
     /*side_data->Symbol=       CSL_FEXT(hAif2->regs->DB_IDB_DEBUG_SBND,AIF2_DB_EDB_DEBUG_SBND_SYMBOL);*/
}

 /** ============================================================================
 *   @n@b CSL_aif2GetEDbDebugOffsetData
 *
 *   @b Description
 *   @n Get Write and Read Offset Value at address in DB_EDB_DEBUG_OFS
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           Uint8 *         ponter to write and read offset data 
     @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_DB_EDB_DEBUG_OFS_DAT_WOFF
 *
 *   @b Example
 *   @verbatim
        Uint8  offset[2];
        
        CSL_aif2GetEDbDebugOffsetData(hAif2, &offset[0]);

        Uint8 write_offset = offset[0];
        Uint8 read_offset = offset[1];
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEDbDebugOffsetData (
        CSL_Aif2Handle   hAif2,
        Uint8*                 offset
);
static inline
void CSL_aif2GetEDbDebugOffsetData (
        CSL_Aif2Handle   hAif2,
        Uint8*                 offset
)
{ 
        offset[0] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_OFS_DAT,AIF2_DB_EDB_DEBUG_OFS_DAT_WOFF);
	 offset[1] = CSL_FEXT(hAif2->regs->DB_EDB_DEBUG_OFS_DAT,AIF2_DB_EDB_DEBUG_OFS_DAT_ROFF);
}


/** ============================================================================
 *   @n@b CSL_aif2GetEgrEopCount
 *
 *   @b Description
 *   @n Get Egress EOP count from DB
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_DB_EDB_EOP_CNT_EOP_CNT
 *
 *   @b Example
 *   @verbatim
        Uint32  eop_cnt;
        
        eop_cnt = CSL_aif2GetEgrEopCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetEgrEopCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetEgrEopCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->DB_EDB_EOP_CNT ,AIF2_DB_EDB_EOP_CNT_EOP_CNT);
}


/** ============================================================================
 *   @n@b CSL_aif2GetIngrEopCount
 *
 *   @b Description
 *   @n Get Ingress EOP count
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AD_ISCH_EOP_CNT_EOP_CNT
 *
 *   @b Example
 *   @verbatim
        Uint32  eop_cnt;
        
        eop_cnt = CSL_aif2GetIngrEopCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetIngrEopCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetIngrEopCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AD_ISCH_EOP_CNT ,AIF2_AD_ISCH_EOP_CNT_EOP_CNT);
}


/** ============================================================================
 *   @n@b CSL_aif2GetAtLinkPiCapture
 *
 *   @b Description
 *   @n Get Aif2 timer Pi captured value for link
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance    should use hAif2->arg_link to select link
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32  
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_PIVALUE_LK_PICAPTURED_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  pi;
        hAif2->arg_link = LINK0;
        pi = CSL_aif2GetAtLinkPiCapture(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtLinkPiCapture (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtLinkPiCapture (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->PI_DATA[hAif2->arg_link].AT_PIVALUE_LK,AIF2_AT_PIVALUE_LK_PICAPTURED_VALUE);
}


/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtCapture
 *
 *   @b Description
 *   @n Get Aif2 Rad timer captured clock, symbol, frame count value upon a phyt frame boundary
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           CSL_Aif2AtCaptRadt    Radt clock, symbol and frame value structure
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_CAPTRADT_RADTCLOCKCOUNT_CAPTURE,AIF2_AT_CAPTRADT_RADTSYMBOLCOUNT_CAPTURE,
 *         AIF2_AT_CAPTRADT_RADTFRAMECOUNT_CAPTURE
 *   @b Example
 *   @verbatim
        CSL_Aif2AtCaptRadt  radt_count;
        
        CSL_aif2GetAtRadtCapture(hAif2,&radt_count);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetAtRadtCapture (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtCaptRadt*     radt
);
static inline
void CSL_aif2GetAtRadtCapture (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtCaptRadt*     radt
)
{ 
        radt->clock=  CSL_FEXT(hAif2->regs->AT_CAPTRADT, AIF2_AT_CAPTRADT_RADTCLOCKCOUNT_CAPTURE);
	 radt->symbol=  CSL_FEXT(hAif2->regs->AT_CAPTRADT, AIF2_AT_CAPTRADT_RADTSYMBOLCOUNT_CAPTURE);
	 radt->frame =  CSL_FEXT(hAif2->regs->AT_CAPTRADT, AIF2_AT_CAPTRADT_RADTFRAMECOUNT_CAPTURE);
}
 
 /** ============================================================================
 *   @n@b CSL_aif2GetAtRp1TypeCapture
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 type capture value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint8  
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED
 *
 *   @b Example
 *   @verbatim
        Uint8  type;
        
        type = CSL_aif2GetAtRp1TypeCapture(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetAtRp1TypeCapture (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetAtRp1TypeCapture (
        CSL_Aif2Handle   hAif2
)
{ 
        return (Uint8)CSL_FEXT(hAif2->regs->AT_RP1_TYPE_CAPTURE,AIF2_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1TodCaptureLsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 TOD capture value lsb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  tod_lo;
        
        tod_lo = CSL_aif2GetAtRp1TodCaptureLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1TodCaptureLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1TodCaptureLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_TOD_CAPTURE_L,AIF2_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1TodCaptureMsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 TOD capture value msb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_TOD_CAPTURE_HRP1TOD_CAPTURE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  tod_hi;
        
        tod_hi = CSL_aif2GetAtRp1TodCaptureMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1TodCaptureMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1TodCaptureMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_TOD_CAPTURE_H,AIF2_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1Rp3CaptureLsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 RP3 capture value lsb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  RP3Lo;
        
        RP3Lo = CSL_aif2GetAtRp1Rp3CaptureLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1Rp3CaptureLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1Rp3CaptureLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_RP3_CAPTURE_L,AIF2_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1Rp3CaptureMsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 RP3 capture value msb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_RP3_CAPTURE_HRP1RP3_CAPTURE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  RP3Hi;
        
        RP3Hi = CSL_aif2GetAtRp1Rp3CaptureMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1Rp3CaptureMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1Rp3CaptureMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_RP3_CAPTURE_H,AIF2_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1RadCaptureLsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 RAD capture value lsb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  RADLo;
        
        RADLo = CSL_aif2GetAtRp1RadCaptureLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1RadCaptureLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1RadCaptureLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_RAD_CAPTURE_L,AIF2_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRp1RadCaptureMsb
 *
 *   @b Description
 *   @n Get Aif2 timer RP1 Radio system capture value msb
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RP1_RAD_CAPTURE_HRP1RADIO_SYSTEM_CAPTURE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  RADHi;
        
        RADHi = CSL_aif2GetAtRp1RadCaptureMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRp1RadCaptureMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRp1RadCaptureMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RP1_RAD_CAPTURE_H,AIF2_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtPhytClkCount
 *
 *   @b Description
 *   @n Get Aif2 Phy timer clock count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtPhytClkCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtPhytClkCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtPhytClkCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_PHYT_CLKCNT_VALUE,AIF2_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtPhytFrameLsb
 *
 *   @b Description
 *   @n Get Aif2 Phy timer frame count lsb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtPhytFrameLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtPhytFrameLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtPhytFrameLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_PHYT_FRM_VALUE_LSBS, AIF2_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtPhytFrameMsb
 *
 *   @b Description
 *   @n Get Aif2 Phy timer frame count msb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtPhytFrameMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtPhytFrameMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtPhytFrameMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_PHYT_FRM_VALUE_MSBS, AIF2_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS);
}


/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtClkCount
 *
 *   @b Description
 *   @n Get Aif2 Rad timer clock count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_VALUE_LSBS_RADTCLOCK_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtRadtClkCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRadtClkCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRadtClkCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RADT_VALUE_LSBS,AIF2_AT_RADT_VALUE_LSBS_RADTCLOCK_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtSymCount
 *
 *   @b Description
 *   @n Get Aif2 Rad timer symbol count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint8  count;
        
        count = CSL_aif2GetAtRadtSymCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetAtRadtSymCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetAtRadtSymCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return (Uint8)CSL_FEXT(hAif2->regs->AT_RADT_VALUE_LSBS,AIF2_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtFrameLsb
 *
 *   @b Description
 *   @n Get Aif2 Rad timer frame count lsb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtRadtFrameLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRadtFrameLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRadtFrameLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RADT_VALUE_MID, AIF2_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtFrameMsb
 *
 *   @b Description
 *   @n Get Aif2 Rad timer frame count msb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtRadtFrameMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRadtFrameMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRadtFrameMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RADT_VALUE_MSBS, AIF2_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtUlRadtClkCount
 *
 *   @b Description
 *   @n Get Aif2 UL Rad timer clock count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_ULRADT_VALUE_LSBS_ULRADTCLOCK_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtUlRadtClkCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtUlRadtClkCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtUlRadtClkCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_ULRADT_VALUE_LSBS,AIF2_AT_ULRADT_VALUE_LSBS_ULRADTCLOCK_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtUlRadtSymCount
 *
 *   @b Description
 *   @n Get Aif2 UL Rad timer symbol count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint8  count;
        
        count = CSL_aif2GetAtUlRadtSymCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline Uint8 CSL_aif2GetAtUlRadtSymCount (CSL_Aif2Handle   hAif2);
static inline Uint8 CSL_aif2GetAtUlRadtSymCount (CSL_Aif2Handle   hAif2)
{ 
        return (Uint8)CSL_FEXT(hAif2->regs->AT_ULRADT_VALUE_LSBS,AIF2_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtUlRadtFrameLsb
 *
 *   @b Description
 *   @n Get Aif2 UL Rad timer frame count lsb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtUlRadtFrameLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtUlRadtFrameLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtUlRadtFrameLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_ULRADT_VALUE_MID, AIF2_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtUlRadtFrameMsb
 *
 *   @b Description
 *   @n Get Aif2 UL Rad timer frame count msb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtUlRadtFrameMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtUlRadtFrameMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtUlRadtFrameMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_ULRADT_VALUE_MSBS, AIF2_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtDlRadtClkCount
 *
 *   @b Description
 *   @n Get Aif2 DL Rad timer clock count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtDlRadtClkCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtDlRadtClkCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtDlRadtClkCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_DLRADT_VALUE_LSBS,AIF2_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtDlRadtSymCount
 *
 *   @b Description
 *   @n Get Aif2 DL Rad timer symbol count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint8
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint8  count;
        
        count = CSL_aif2GetAtDlRadtSymCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint8 CSL_aif2GetAtDlRadtSymCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint8 CSL_aif2GetAtDlRadtSymCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return (Uint8)CSL_FEXT(hAif2->regs->AT_DLRADT_VALUE_LSBS,AIF2_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtDlRadtFrameLsb
 *
 *   @b Description
 *   @n Get Aif2 DL Rad timer frame count lsb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtDlRadtFrameLsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtDlRadtFrameLsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtDlRadtFrameLsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_DLRADT_VALUE_MID, AIF2_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtDlRadtFrameMsb
 *
 *   @b Description
 *   @n Get Aif2 DL Rad timer frame count msb value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtDlRadtFrameMsb(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtDlRadtFrameMsb (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtDlRadtFrameMsb (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_DLRADT_VALUE_MSBS, AIF2_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtWcdmaValue
 *
 *   @b Description
 *   @n Get Aif2 Rad timer wcdma count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           CSL_Aif2AtWcdmaCount     WCDMA chip, slot and frame value structure
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_WCDMA_VALUE_CHIPVALUE,AIF2_AT_RADT_WCDMA_VALUE_SLOTVALUE,
 *         AIF2_AT_RADT_WCDMA_VALUE_FRAMEVALUE
 *   @b Example
 *   @verbatim
        CSL_Aif2AtWcdmaCount  wcdma_count;
        
        CSL_aif2GetAtRadtWcdmaValue(hAif2,&wcdma_count);

        wcdma_count.chip = ....
        wcdma_count.slot = .....
        wcdma_count.frame = ....
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetAtRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
);
static inline
void CSL_aif2GetAtRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
)
{ 
        wcdma->chip =  CSL_FEXT(hAif2->regs->AT_RADT_WCDMA_VALUE, AIF2_AT_RADT_WCDMA_VALUE_CHIPVALUE);
	 wcdma->slot =  CSL_FEXT(hAif2->regs->AT_RADT_WCDMA_VALUE, AIF2_AT_RADT_WCDMA_VALUE_SLOTVALUE);
	 wcdma->frame =  CSL_FEXT(hAif2->regs->AT_RADT_WCDMA_VALUE, AIF2_AT_RADT_WCDMA_VALUE_FRAMEVALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtUlRadtWcdmaValue
 *
 *   @b Description
 *   @n Get Aif2 Ul Rad timer wcdma count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           CSL_Aif2AtWcdmaCount     WCDMA chip, slot and frame value structure
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_ULRADT_WCDMA_VALUE_CHIPVALUE,AIF2_AT_ULRADT_WCDMA_VALUE_SLOTVALUE,
 *         AIF2_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE
 *   @b Example
 *   @verbatim
        CSL_Aif2AtWcdmaCount  wcdma_count;
        
        CSL_aif2GetAtUlRadtWcdmaValue(hAif2,&wcdma_count);

        wcdma_count.chip = ....
        wcdma_count.slot = .....
        wcdma_count.frame = ....
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetAtUlRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
);
static inline
void CSL_aif2GetAtUlRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
)
{ 
        wcdma->chip =  CSL_FEXT(hAif2->regs->AT_ULRADT_WCDMA_VALUE, AIF2_AT_ULRADT_WCDMA_VALUE_CHIPVALUE);
	 wcdma->slot =  CSL_FEXT(hAif2->regs->AT_ULRADT_WCDMA_VALUE, AIF2_AT_ULRADT_WCDMA_VALUE_SLOTVALUE);
	 wcdma->frame =  CSL_FEXT(hAif2->regs->AT_ULRADT_WCDMA_VALUE, AIF2_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtDlRadtWcdmaValue
 *
 *   @b Description
 *   @n Get Aif2 Dl Rad timer wcdma count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           CSL_Aif2AtWcdmaCount     WCDMA chip, slot and frame value structure
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_DLRADT_WCDMA_VALUE_CHIPVALUE,AIF2_AT_DLRADT_WCDMA_VALUE_SLOTVALUE,
 *         AIF2_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE
 *   @b Example
 *   @verbatim
        CSL_Aif2AtWcdmaCount  wcdma_count;
        
        CSL_aif2GetAtDlRadtWcdmaValue(hAif2,&wcdma_count);

        wcdma_count.chip = ....
        wcdma_count.slot = .....
        wcdma_count.frame = ....
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetAtDlRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
);
static inline
void CSL_aif2GetAtDlRadtWcdmaValue (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtWcdmaCount*     wcdma
)
{ 
        wcdma->chip =  CSL_FEXT(hAif2->regs->AT_DLRADT_WCDMA_VALUE, AIF2_AT_DLRADT_WCDMA_VALUE_CHIPVALUE);
	 wcdma->slot =  CSL_FEXT(hAif2->regs->AT_DLRADT_WCDMA_VALUE, AIF2_AT_DLRADT_WCDMA_VALUE_SLOTVALUE);
	 wcdma->frame =  CSL_FEXT(hAif2->regs->AT_DLRADT_WCDMA_VALUE, AIF2_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE);
}


/** ============================================================================
 *   @n@b CSL_aif2GetAtRadtTstampClkCount
 *
 *   @b Description
 *   @n Get Aif2 Rad timer time stamp count value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
      @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE
 *
 *   @b Example
 *   @verbatim
        Uint32  count;
        
        count = CSL_aif2GetAtRadtTstampClkCount(hAif2);
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
Uint32 CSL_aif2GetAtRadtTstampClkCount (
        CSL_Aif2Handle   hAif2
);
static inline
Uint32 CSL_aif2GetAtRadtTstampClkCount (
        CSL_Aif2Handle   hAif2
)
{ 
        return CSL_FEXT(hAif2->regs->AT_RADT_TSTAMP_VALUE, AIF2_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE);
}

/** ============================================================================
 *   @n@b CSL_aif2GetAtGsmTcount
 *
 *   @b Description
 *   @n Get Aif2 GSM Tcount value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     
           CSL_Aif2AtWcdmaCount     WCDMA chip, slot and frame value structure
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_AT_GSM_TCOUNT_VALUE_T1,AIF2_AT_GSM_TCOUNT_VALUE_T2,
 *         AIF2_AT_GSM_TCOUNT_VALUE_T3
 *   @b Example
 *   @verbatim
        CSL_Aif2AtGsmTCount  tcount;
        
        CSL_aif2GetAtGsmTcount(hAif2,&tcount);

        tcount.t1 = ....
        tcount.t2 = .....
        tcount.t3 = ....
        
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetAtGsmTcount (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtGsmTCount*     tcount
);
static inline
void CSL_aif2GetAtGsmTcount (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2AtGsmTCount*     tcount
)
{ 
        tcount->t1 =  CSL_FEXT(hAif2->regs->AT_GSM_TCOUNT_VALUE, AIF2_AT_GSM_TCOUNT_VALUE_T1);
	 tcount->t2 =  CSL_FEXT(hAif2->regs->AT_GSM_TCOUNT_VALUE, AIF2_AT_GSM_TCOUNT_VALUE_T2);
	 tcount->t3 =  CSL_FEXT(hAif2->regs->AT_GSM_TCOUNT_VALUE, AIF2_AT_GSM_TCOUNT_VALUE_T3);
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeDbIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE DB interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeDbInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_DB_IRS_DB_EE_I_TRC_RAM_OVFL_ERR,       AIF2_EE_DB_IRS_DB_EE_I_TOKEN_OVFL_ERR,
 *         AIF2_EE_DB_IRS_DB_EE_I_FIFO_OVFL_ERR,              AIF2_EE_DB_IRS_DB_EE_I_PD2DB_FULL_ERR,
 *         AIF2_EE_DB_IRS_DB_EE_E_PS_AXC_ERR,                 AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_ERR,
 *         AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_TYPE_ERR;
 *
 *         AIF2_EE_DB_EN_EV0_DB_EE_I_TRC_RAM_OVFL_ERR,       AIF2_EE_DB_EN_EV0_DB_EE_I_TOKEN_OVFL_ERR,
 *         AIF2_EE_DB_EN_EV0_DB_EE_I_FIFO_OVFL_ERR,              AIF2_EE_DB_EN_EV0_DB_EE_I_PD2DB_FULL_ERR,
 *         AIF2_EE_DB_EN_EV0_DB_EE_E_PS_AXC_ERR,                 AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_ERR,
 *         AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_TYPE_ERR;
 *
 *         AIF2_EE_DB_EN_EV1_DB_EE_I_TRC_RAM_OVFL_ERR,       AIF2_EE_DB_EN_EV1_DB_EE_I_TOKEN_OVFL_ERR,
 *         AIF2_EE_DB_EN_EV1_DB_EE_I_FIFO_OVFL_ERR,              AIF2_EE_DB_EN_EV1_DB_EE_I_PD2DB_FULL_ERR,
 *         AIF2_EE_DB_EN_EV1_DB_EE_E_PS_AXC_ERR,                 AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_ERR,
 *         AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_TYPE_ERR;
 *
 *         AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TRC_RAM_OVFL_ERR,       AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TOKEN_OVFL_ERR,
 *         AIF2_EE_DB_EN_STS_EV0_DB_EE_I_FIFO_OVFL_ERR,              AIF2_EE_DB_EN_STS_EV0_DB_EE_I_PD2DB_FULL_ERR,
 *         AIF2_EE_DB_EN_STS_EV0_DB_EE_E_PS_AXC_ERR,                 AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_ERR,
 *         AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_TYPE_ERR;
 *
 *         AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TRC_RAM_OVFL_ERR,       AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TOKEN_OVFL_ERR,
 *         AIF2_EE_DB_EN_STS_EV1_DB_EE_I_FIFO_OVFL_ERR,              AIF2_EE_DB_EN_STS_EV1_DB_EE_I_PD2DB_FULL_ERR,
 *         AIF2_EE_DB_EN_STS_EV1_DB_EE_E_PS_AXC_ERR,                 AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_ERR,
 *         AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_TYPE_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EeDbInt  DbInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeDbIntStatus(hAif2,&DbInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeDbIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeDbInt*     DbInt
);
static inline
void CSL_aif2GetEeDbIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeDbInt*     DbInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 DbInt->db_ee_i_trc_ram_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_I_TRC_RAM_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_token_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_I_TOKEN_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_fifo_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_I_FIFO_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_pd2db_full_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_I_PD2DB_FULL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_ps_axc_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_E_PS_AXC_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_err =  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_type_err=  CSL_FEXT(hAif2->regs->EE_DB_IRS, AIF2_EE_DB_IRS_DB_EE_E_CD_DATA_TYPE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 DbInt->db_ee_i_trc_ram_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_I_TRC_RAM_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_token_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_I_TOKEN_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_fifo_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_I_FIFO_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_pd2db_full_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_I_PD2DB_FULL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_ps_axc_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_E_PS_AXC_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_type_err=  CSL_FEXT(hAif2->regs->EE_DB_EN_EV0, AIF2_EE_DB_EN_EV0_DB_EE_E_CD_DATA_TYPE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 DbInt->db_ee_i_trc_ram_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_I_TRC_RAM_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_token_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_I_TOKEN_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_fifo_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_I_FIFO_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_pd2db_full_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_I_PD2DB_FULL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_ps_axc_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_E_PS_AXC_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_type_err=  CSL_FEXT(hAif2->regs->EE_DB_EN_EV1, AIF2_EE_DB_EN_EV1_DB_EE_E_CD_DATA_TYPE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 DbInt->db_ee_i_trc_ram_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TRC_RAM_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_token_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_I_TOKEN_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_fifo_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_I_FIFO_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_pd2db_full_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_I_PD2DB_FULL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_ps_axc_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_E_PS_AXC_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_type_err=  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV0, AIF2_EE_DB_EN_STS_EV0_DB_EE_E_CD_DATA_TYPE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 DbInt->db_ee_i_trc_ram_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TRC_RAM_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_token_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_I_TOKEN_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_fifo_ovfl_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_I_FIFO_OVFL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_i_pd2db_full_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_I_PD2DB_FULL_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_ps_axc_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_E_PS_AXC_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_ERR) ? TRUE : FALSE;
	 DbInt->db_ee_e_cd_data_type_err =  CSL_FEXT(hAif2->regs->EE_DB_EN_STS_EV1, AIF2_EE_DB_EN_STS_EV1_DB_EE_E_CD_DATA_TYPE_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeAdIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE AD interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeAdInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_AD_IRS_AD_EE_I_CD_DATA_ERR,       AIF2_EE_AD_IRS_AD_EE_E_CD_SCH_ERR,
 *         AIF2_EE_AD_IRS_AD_EE_I_DMA_0_ERR,            AIF2_EE_AD_IRS_AD_EE_I_DMA_1_ERR,
 *         AIF2_EE_AD_IRS_AD_EE_I_DMA_2_ERR,            AIF2_EE_AD_IRS_AD_EE_E_DMA_0_ERR,
 *         AIF2_EE_AD_IRS_AD_EE_E_DMA_1_ERR,            AIF2_EE_AD_IRS_AD_EE_E_DMA_2_ERR;
 *
 *         AIF2_EE_AD_EN_EV0_AD_EE_I_CD_DATA_ERR,       AIF2_EE_AD_EN_EV0_AD_EE_E_CD_SCH_ERR,
 *         AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_0_ERR,            AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_1_ERR,
 *         AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_2_ERR,            AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_0_ERR,
 *         AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_1_ERR,            AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_2_ERR;
 *
 *         AIF2_EE_AD_EN_EV1_AD_EE_I_CD_DATA_ERR,       AIF2_EE_AD_EN_EV1_AD_EE_E_CD_SCH_ERR,
 *         AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_0_ERR,            AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_1_ERR,
 *         AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_2_ERR,            AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_0_ERR,
 *         AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_1_ERR,            AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_2_ERR;
 *
 *         AIF2_EE_AD_EN_STS_EV0_AD_EE_I_CD_DATA_ERR,       AIF2_EE_AD_EN_STS_EV0_AD_EE_E_CD_SCH_ERR,
 *         AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_0_ERR,            AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_1_ERR,
 *         AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_2_ERR,            AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_0_ERR,
 *         AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_1_ERR,            AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_2_ERR;
 *
 *         AIF2_EE_AD_EN_STS_EV1_AD_EE_I_CD_DATA_ERR,       AIF2_EE_AD_EN_STS_EV1_AD_EE_E_CD_SCH_ERR,
 *         AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_0_ERR,            AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_1_ERR,
 *         AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_2_ERR,            AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_0_ERR,
 *         AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_1_ERR,            AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_2_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EeAdInt  AdInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeAdIntStatus(hAif2,&AdInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeAdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAdInt*     AdInt
);
static inline
void CSL_aif2GetEeAdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAdInt*     AdInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 AdInt->ad_ee_i_cd_data_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_I_CD_DATA_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_cd_sch_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_E_CD_SCH_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_I_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_I_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_I_DMA_2_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_E_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_E_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_IRS, AIF2_EE_AD_IRS_AD_EE_E_DMA_2_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 AdInt->ad_ee_i_cd_data_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_I_CD_DATA_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_cd_sch_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_E_CD_SCH_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_I_DMA_2_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV0, AIF2_EE_AD_EN_EV0_AD_EE_E_DMA_2_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 AdInt->ad_ee_i_cd_data_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_I_CD_DATA_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_cd_sch_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_E_CD_SCH_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_I_DMA_2_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_EV1, AIF2_EE_AD_EN_EV1_AD_EE_E_DMA_2_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 AdInt->ad_ee_i_cd_data_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_I_CD_DATA_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_cd_sch_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_E_CD_SCH_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_I_DMA_2_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV0, AIF2_EE_AD_EN_STS_EV0_AD_EE_E_DMA_2_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 AdInt->ad_ee_i_cd_data_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_I_CD_DATA_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_cd_sch_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_E_CD_SCH_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_i_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_I_DMA_2_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_0_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_0_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_1_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_1_ERR) ? TRUE : FALSE;
	 AdInt->ad_ee_e_dma_2_err =  CSL_FEXT(hAif2->regs->EE_AD_EN_STS_EV1, AIF2_EE_AD_EN_STS_EV1_AD_EE_E_DMA_2_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeCdIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE CD(PKTDMA) interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeCdInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_CD_IRS_CD_EE_SOP_DESC_STARVE_ERR,       AIF2_EE_CD_IRS_CD_EE_MOP_DESC_STARVE_ERR;
 *
 *         AIF2_EE_CD_EN_EV_CD_EE_SOP_DESC_STARVE_ERR,       AIF2_EE_CD_EN_EV_CD_EE_MOP_DESC_STARVE_ERR;
 *
 *         AIF2_EE_CD_EN_STS_EV_CD_EE_SOP_DESC_STARVE_ERR,       AIF2_EE_CD_EN_STS_EV_CD_EE_MOP_DESC_STARVE_ERR;
 *
 *   @b Example
 *   @verbatim
        CSL_Aif2EeCdInt  CdInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeCdIntStatus(hAif2,&CdInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeCdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeCdInt*     CdInt
);
static inline
void CSL_aif2GetEeCdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeCdInt*     CdInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 CdInt->cd_ee_sop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_IRS, AIF2_EE_CD_IRS_CD_EE_SOP_DESC_STARVE_ERR) ? TRUE : FALSE;
	 CdInt->cd_ee_mop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_IRS, AIF2_EE_CD_IRS_CD_EE_MOP_DESC_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
        CdInt->cd_ee_sop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_EN_EV, AIF2_EE_CD_EN_EV_CD_EE_SOP_DESC_STARVE_ERR) ? TRUE : FALSE;
	 CdInt->cd_ee_mop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_EN_EV, AIF2_EE_CD_EN_EV_CD_EE_MOP_DESC_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
        CdInt->cd_ee_sop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_EN_STS_EV, AIF2_EE_CD_EN_STS_EV_CD_EE_SOP_DESC_STARVE_ERR) ? TRUE : FALSE;
	 CdInt->cd_ee_mop_desc_starve_err =  CSL_FEXT(hAif2->regs->EE_CD_EN_STS_EV, AIF2_EE_CD_EN_STS_EV_CD_EE_MOP_DESC_STARVE_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeSdIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE SD interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeSdInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_SD_IRS_SD_EE_STSPLL_B4_ERR,       AIF2_EE_SD_IRS_SD_EE_STSPLL_B8_ERR;
 *
 *       AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B4_ERR,       AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B8_ERR;
 *       AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B4_ERR,    AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B8_ERR;
 * 
 *       AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B4_ERR,       AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B8_ERR;
 *       AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B4_ERR,    AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B8_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EeSdInt  SdInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeSdIntStatus(hAif2,&SdInt);
     @endverbatim
 * ===========================================================================
 */

/* for misra warnings*/
static inline
void CSL_aif2GetEeSdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeSdInt*     SdInt
);
static inline
void CSL_aif2GetEeSdIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeSdInt*     SdInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 SdInt->sd_ee_stspll_b4_err =  CSL_FEXT(hAif2->regs->EE_SD_IRS, AIF2_EE_SD_IRS_SD_EE_STSPLL_B4_ERR) ? TRUE : FALSE;
	 SdInt->sd_ee_stspll_b8_err =  CSL_FEXT(hAif2->regs->EE_SD_IRS, AIF2_EE_SD_IRS_SD_EE_STSPLL_B8_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 SdInt->sd_ee_stspll_b4_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_EV0, AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B4_ERR) ? TRUE : FALSE;
	 SdInt->sd_ee_stspll_b8_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_EV0, AIF2_EE_SD_EN_EV0_SD_EE_STSPLL_B8_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
     SdInt->sd_ee_stspll_b4_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_STS_EV0, AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B4_ERR) ? TRUE : FALSE;
	 SdInt->sd_ee_stspll_b8_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_STS_EV0, AIF2_EE_SD_EN_STS_EV0_SD_EE_STSPLL_B8_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 SdInt->sd_ee_stspll_b4_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_EV1, AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B4_ERR) ? TRUE : FALSE;
	 SdInt->sd_ee_stspll_b8_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_EV1, AIF2_EE_SD_EN_EV1_SD_EE_STSPLL_B8_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
     SdInt->sd_ee_stspll_b4_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_STS_EV1, AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B4_ERR) ? TRUE : FALSE;
	 SdInt->sd_ee_stspll_b8_err =  CSL_FEXT(hAif2->regs->EE_SD_EN_STS_EV1, AIF2_EE_SD_EN_STS_EV1_SD_EE_STSPLL_B8_ERR) ? TRUE : FALSE;
        }
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeVcIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE VC interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeVcInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_VC_IRS_VC_EE_VBUS_ERR;  AIF2_EE_VC_EN_EV0_VC_EE_VBUS_ERR;
 *         AIF2_EE_VC_EN_STS_EV0_VC_EE_VBUS_ERR;  AIF2_EE_VC_EN_EV1_VC_EE_VBUS_ERR;
 *         AIF2_EE_VC_EN_STS_EV1_VC_EE_VBUS_ERR
 *   @b Example
 *   @verbatim
        CSL_Aif2EeVcInt  VcInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeVcIntStatus(hAif2,&VcInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeVcIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeVcInt*     VcInt
);
static inline
void CSL_aif2GetEeVcIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeVcInt*     VcInt
)
{ 
     if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS)
     {
     	VcInt->vc_ee_vbus_err =  CSL_FEXT(hAif2->regs->EE_VC_IRS, AIF2_EE_VC_IRS_VC_EE_VBUS_ERR) ? TRUE : FALSE;
     } 
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0)
     {
	 VcInt->vc_ee_vbus_err =  CSL_FEXT(hAif2->regs->EE_VC_EN_EV0, AIF2_EE_VC_EN_EV0_VC_EE_VBUS_ERR) ? TRUE : FALSE;
     } 
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0)
     {
        VcInt->vc_ee_vbus_err =  CSL_FEXT(hAif2->regs->EE_VC_EN_STS_EV0, AIF2_EE_VC_EN_STS_EV0_VC_EE_VBUS_ERR) ? TRUE : FALSE;
     } 
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1)
     {
	 VcInt->vc_ee_vbus_err =  CSL_FEXT(hAif2->regs->EE_VC_EN_EV1, AIF2_EE_VC_EN_EV1_VC_EE_VBUS_ERR) ? TRUE : FALSE;
     } 
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1)
     {
        VcInt->vc_ee_vbus_err =  CSL_FEXT(hAif2->regs->EE_VC_EN_STS_EV1, AIF2_EE_VC_EN_STS_EV1_VC_EE_VBUS_ERR) ? TRUE : FALSE;
     }
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeAif2RunStatus
 *
 *   @b Description
 *   @n Get Aif2 EE AIF2 run status value 
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance    
           CSL_Aif2EeAif2Run     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN,  AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN;
 *         
 *   @b Example
 *   @verbatim
        CSL_Aif2EeAif2Run  Aif2Run;
        
        CSL_aif2GetEeAif2RunStatus(hAif2,&Aif2Run);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeAif2RunStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAif2Run*     Aif2Run
);
static inline
void CSL_aif2GetEeAif2RunStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAif2Run*     Aif2Run
)
{ 
	 Aif2Run->aif2_phy_run =  CSL_FEXT(hAif2->regs->EE_AIF2_RUN_STS, AIF2_EE_AIF2_RUN_STS_AIF2_PHY_RUN) ? TRUE : FALSE;
	 Aif2Run->aif2_global_run =  CSL_FEXT(hAif2->regs->EE_AIF2_RUN_STS, AIF2_EE_AIF2_RUN_STS_AIF2_GLOBAL_RUN) ? TRUE : FALSE;
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeAif2Origination
 *
 *   @b Description
 *   @n Get Aif2 EE error or alarm origination status 
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance    
           CSL_Aif2EeOrigin     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A1,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B1,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A2,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B2,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A3,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B3,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A4,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B4,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A5,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B5,
 *         AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0,  AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0,
 *         AIF2_EE_ERR_ALRM_ORGN_AT_EN_STS,AIF2_EE_ERR_ALRM_ORGN_SD_EN_STS,
 *         AIF2_EE_ERR_ALRM_ORGN_DB_EN_STS,AIF2_EE_ERR_ALRM_ORGN_AD_EN_STS,
 *         AIF2_EE_ERR_ALRM_ORGN_VC_EN_STS
 *   @b Example
 *   @verbatim
        CSL_Aif2EeOrigin  Aif2Origin;
        
        CSL_aif2GetEeAif2Origination(hAif2,&Aif2Origin);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeAif2Origination (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeOrigin*     Aif2Origin
);
static inline
void CSL_aif2GetEeAif2Origination (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeOrigin*     Aif2Origin
)
{ 
	 Aif2Origin->lk_en_sts_a0=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A0) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b0=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B0) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_a1=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A1) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b1=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B1) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_a2=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A2) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b2=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B2) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_a3=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A3) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b3=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B3) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_a4=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A4) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b4=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B4) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_a5=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_A5) ? TRUE : FALSE;
	 Aif2Origin->lk_en_sts_b5=  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_LK_EN_STS_B5) ? TRUE : FALSE;
	 Aif2Origin->at_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_AT_EN_STS) ? TRUE : FALSE;
	 Aif2Origin->sd_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_SD_EN_STS) ? TRUE : FALSE;
	 Aif2Origin->db_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_DB_EN_STS) ? TRUE : FALSE;
	 Aif2Origin->ad_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_AD_EN_STS) ? TRUE : FALSE;
	 Aif2Origin->cd_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_CD_EN_STS) ? TRUE : FALSE;
	 Aif2Origin->vc_en_sts =  CSL_FEXT(hAif2->regs->EE_ERR_ALRM_ORGN, AIF2_EE_ERR_ALRM_ORGN_VC_EN_STS) ? TRUE : FALSE;
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeLinkAIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE Link A interrupt  status value 
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function and hAif2->arg_link to select link
           CSL_Aif2EeLinkAInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_LK_IRS_A_RM_EE_SYNC_STATUS_CHANGE_ERR,      AIF2_EE_LK_IRS_A_RM_EE_NUM_LOS_DET_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_LCV_DET_ERR,                            AIF2_EE_LK_IRS_A_RM_EE_FRAME_BNDRY_DET_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_BLOCK_BNDRY_DET_ERR,            AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P5_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P7_ERR,                 AIF2_EE_LK_IRS_A_RM_EE_K30P7_DET_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_LOC_DET_ERR,                           AIF2_EE_LK_IRS_A_RM_EE_RX_FIFO_OVF_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOS_ERR,                         AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOF_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_RCVD_RAI_ERR,                         AIF2_EE_LK_IRS_A_RM_EE_RCVD_SDI_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_LOS_ERR,                                   AIF2_EE_LK_IRS_A_RM_EE_LOF_ERR,
 *         AIF2_EE_LK_IRS_A_RM_EE_HFNSYNC_STATE_ERR,                AIF2_EE_LK_IRS_A_RM_EE_LOF_STATE_ERR,
 *         AIF2_EE_LK_IRS_A_TM_EE_FRM_MISALIGN_ERR,                   AIF2_EE_LK_IRS_A_TM_EE_FIFO_STARVE_ERR;
 *
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR,      AIF2_EE_LK_EN_A_EV0_RM_EE_NUM_LOS_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_LCV_DET_ERR,                            AIF2_EE_LK_EN_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR,            AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P5_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P7_ERR,                 AIF2_EE_LK_EN_A_EV0_RM_EE_K30P7_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_LOC_DET_ERR,                           AIF2_EE_LK_EN_A_EV0_RM_EE_RX_FIFO_OVF_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOS_ERR,                         AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOF_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_RAI_ERR,                         AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_SDI_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_LOS_ERR,                                   AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_ERR,
 *         AIF2_EE_LK_EN_A_EV0_RM_EE_HFNSYNC_STATE_ERR,                AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_STATE_ERR,
 *         AIF2_EE_LK_EN_A_EV0_TM_EE_FRM_MISALIGN_ERR,                   AIF2_EE_LK_EN_A_EV0_TM_EE_FIFO_STARVE_ERR;
 *
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR,      AIF2_EE_LK_EN_A_EV1_RM_EE_NUM_LOS_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_LCV_DET_ERR,                            AIF2_EE_LK_EN_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR,            AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P5_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P7_ERR,                 AIF2_EE_LK_EN_A_EV1_RM_EE_K30P7_DET_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_LOC_DET_ERR,                           AIF2_EE_LK_EN_A_EV1_RM_EE_RX_FIFO_OVF_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOS_ERR,                         AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOF_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_RAI_ERR,                         AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_SDI_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_LOS_ERR,                                   AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_ERR,
 *         AIF2_EE_LK_EN_A_EV1_RM_EE_HFNSYNC_STATE_ERR,                AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_STATE_ERR,
 *         AIF2_EE_LK_EN_A_EV1_TM_EE_FRM_MISALIGN_ERR,                   AIF2_EE_LK_EN_A_EV1_TM_EE_FIFO_STARVE_ERR;
 *
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR,      AIF2_EE_LK_EN_STS_A_EV0_RM_EE_NUM_LOS_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LCV_DET_ERR,                            AIF2_EE_LK_EN_STS_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR,            AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P5_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P7_ERR,                 AIF2_EE_LK_EN_STS_A_EV0_RM_EE_K30P7_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOC_DET_ERR,                           AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RX_FIFO_OVF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOS_ERR,                         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_RAI_ERR,                         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_SDI_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOS_ERR,                                   AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_RM_EE_HFNSYNC_STATE_ERR,                AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_STATE_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FRM_MISALIGN_ERR,                   AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FIFO_STARVE_ERR;
 *
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR,      AIF2_EE_LK_EN_STS_A_EV1_RM_EE_NUM_LOS_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LCV_DET_ERR,                            AIF2_EE_LK_EN_STS_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR,            AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P5_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P7_ERR,                 AIF2_EE_LK_EN_STS_A_EV1_RM_EE_K30P7_DET_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOC_DET_ERR,                           AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RX_FIFO_OVF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOS_ERR,                         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_RAI_ERR,                         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_SDI_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOS_ERR,                                   AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_RM_EE_HFNSYNC_STATE_ERR,                AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_STATE_ERR,
 *         AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FRM_MISALIGN_ERR,                   AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FIFO_STARVE_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EeLinkAInt  LinkAInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        hAif2->arg_link = 0;//link0
        
        CSL_aif2GetEeLinkAIntStatus(hAif2,&LinkAInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeLinkAIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeLinkAInt*     LinkAInt
); 
static inline
void CSL_aif2GetEeLinkAIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeLinkAInt*     LinkAInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 LinkAInt->rm_ee_sync_status_change_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_SYNC_STATUS_CHANGE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_num_los_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_NUM_LOS_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lcv_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_LCV_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_frame_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_FRAME_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_block_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_BLOCK_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p5_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P5_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p7_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_MISSING_K28P7_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_k30p7_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_K30P7_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_loc_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_LOC_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rx_fifo_ovf_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_RX_FIFO_OVF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_RCVD_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_rai_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_RCVD_RAI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_sdi_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_RCVD_SDI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_hfnsync_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_HFNSYNC_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_RM_EE_LOF_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_frm_misalign_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_TM_EE_FRM_MISALIGN_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_fifo_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_A, AIF2_EE_LK_IRS_A_TM_EE_FIFO_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 LinkAInt->rm_ee_sync_status_change_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_num_los_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_NUM_LOS_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lcv_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_LCV_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_frame_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_block_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p5_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P5_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p7_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_MISSING_K28P7_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_k30p7_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_K30P7_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_loc_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_LOC_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rx_fifo_ovf_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_RX_FIFO_OVF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_rai_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_RAI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_sdi_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_RCVD_SDI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_hfnsync_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_HFNSYNC_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_RM_EE_LOF_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_frm_misalign_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_TM_EE_FRM_MISALIGN_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_fifo_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV0, AIF2_EE_LK_EN_A_EV0_TM_EE_FIFO_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 LinkAInt->rm_ee_sync_status_change_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_num_los_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_NUM_LOS_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lcv_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_LCV_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_frame_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_block_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p5_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P5_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p7_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_MISSING_K28P7_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_k30p7_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_K30P7_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_loc_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_LOC_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rx_fifo_ovf_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_RX_FIFO_OVF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_rai_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_RAI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_sdi_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_RCVD_SDI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_hfnsync_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_HFNSYNC_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_RM_EE_LOF_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_frm_misalign_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_TM_EE_FRM_MISALIGN_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_fifo_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_A_EV1, AIF2_EE_LK_EN_A_EV1_TM_EE_FIFO_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 LinkAInt->rm_ee_sync_status_change_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_SYNC_STATUS_CHANGE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_num_los_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_NUM_LOS_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lcv_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LCV_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_frame_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_FRAME_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_block_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_BLOCK_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p5_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P5_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p7_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_MISSING_K28P7_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_k30p7_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_K30P7_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_loc_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOC_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rx_fifo_ovf_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RX_FIFO_OVF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_rai_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_RAI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_sdi_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_RCVD_SDI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_hfnsync_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_HFNSYNC_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_RM_EE_LOF_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_frm_misalign_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FRM_MISALIGN_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_fifo_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV0, AIF2_EE_LK_EN_STS_A_EV0_TM_EE_FIFO_STARVE_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 LinkAInt->rm_ee_sync_status_change_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_SYNC_STATUS_CHANGE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_num_los_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_NUM_LOS_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lcv_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LCV_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_frame_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_FRAME_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_block_bndry_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_BLOCK_BNDRY_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p5_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P5_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_missing_k28p7_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_MISSING_K28P7_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_k30p7_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_K30P7_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_loc_det_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOC_DET_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rx_fifo_ovf_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RX_FIFO_OVF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_rai_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_RAI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_rcvd_sdi_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_RCVD_SDI_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_los_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOS_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_hfnsync_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_HFNSYNC_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->rm_ee_lof_state_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_RM_EE_LOF_STATE_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_frm_misalign_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FRM_MISALIGN_ERR) ? TRUE : FALSE;
	 LinkAInt->tm_ee_fifo_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_A_EV1, AIF2_EE_LK_EN_STS_A_EV1_TM_EE_FIFO_STARVE_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeLinkBIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE Link B interrupt  status value 
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function and hAif2->arg_link to select link
           CSL_Aif2EeLinkBInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_LK_IRS_B_PD_EE_EOP_ERR,                           AIF2_EE_LK_IRS_B_PD_EE_CRC_ERR,
 *         AIF2_EE_LK_IRS_B_PD_EE_CPRI_FRAME_ERR,              AIF2_EE_LK_IRS_B_PD_EE_AXC_FAIL_ERR,
 *         AIF2_EE_LK_IRS_B_PD_EE_SOP_ERR,                           AIF2_EE_LK_IRS_B_PD_EE_OBSAI_FRM_ERR,
 *         AIF2_EE_LK_IRS_B_PD_EE_WR2DB_ERR,                      AIF2_EE_LK_IRS_B_PE_EE_MODRULE_ERR,
 *         AIF2_EE_LK_IRS_B_PE_EE_SYM_ERR,                           AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_OVERFLOW_ERR,
 *         AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_UNDERFLOW_ERR, AIF2_EE_LK_IRS_B_PE_EE_DB_STARVE_ERR,
 *         AIF2_EE_LK_IRS_B_PE_EE_RT_IF_ERR,                         AIF2_EE_LK_IRS_B_PE_EE_PKT_STARVE_ERR,
 *         AIF2_EE_LK_IRS_B_RT_EE_FRM_ERR,                           AIF2_EE_LK_IRS_B_RT_EE_OVFL_ERR,
 *         AIF2_EE_LK_IRS_B_RT_EE_UNFL_ERR,                          AIF2_EE_LK_IRS_B_RT_EE_EM_ERR,
 *         AIF2_EE_LK_IRS_B_RT_EE_HDR_ERR;                                 
 *
 *         AIF2_EE_LK_EN_B_EV0_PD_EE_EOP_ERR,                          AIF2_EE_LK_EN_B_EV0_PD_EE_CRC_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PD_EE_CPRI_FRAME_ERR,             AIF2_EE_LK_EN_B_EV0_PD_EE_AXC_FAIL_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PD_EE_SOP_ERR,                          AIF2_EE_LK_EN_B_EV0_PD_EE_OBSAI_FRM_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PD_EE_WR2DB_ERR,                     AIF2_EE_LK_EN_B_EV0_PE_EE_MODRULE_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PE_EE_SYM_ERR,                           AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR, AIF2_EE_LK_EN_B_EV0_PE_EE_DB_STARVE_ERR,
 *         AIF2_EE_LK_EN_B_EV0_PE_EE_RT_IF_ERR,                         AIF2_EE_LK_EN_B_EV0_PE_EE_PKT_STARVE_ERR,
 *         AIF2_EE_LK_EN_B_EV0_RT_EE_FRM_ERR,                           AIF2_EE_LK_EN_B_EV0_RT_EE_OVFL_ERR,
 *         AIF2_EE_LK_EN_B_EV0_RT_EE_UNFL_ERR,                          AIF2_EE_LK_EN_B_EV0_RT_EE_EM_ERR,
 *         AIF2_EE_LK_EN_B_EV0_RT_EE_HDR_ERR;                                 
 *
 *         AIF2_EE_LK_EN_B_EV1_PD_EE_EOP_ERR,                           AIF2_EE_LK_EN_B_EV1_PD_EE_CRC_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PD_EE_CPRI_FRAME_ERR,              AIF2_EE_LK_EN_B_EV1_PD_EE_AXC_FAIL_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PD_EE_SOP_ERR,                           AIF2_EE_LK_EN_B_EV1_PD_EE_OBSAI_FRM_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PD_EE_WR2DB_ERR,                      AIF2_EE_LK_EN_B_EV1_PE_EE_MODRULE_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PE_EE_SYM_ERR,                           AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR, AIF2_EE_LK_EN_B_EV1_PE_EE_DB_STARVE_ERR,
 *         AIF2_EE_LK_EN_B_EV1_PE_EE_RT_IF_ERR,                         AIF2_EE_LK_EN_B_EV1_PE_EE_PKT_STARVE_ERR,
 *         AIF2_EE_LK_EN_B_EV1_RT_EE_FRM_ERR,                           AIF2_EE_LK_EN_B_EV1_RT_EE_OVFL_ERR,
 *         AIF2_EE_LK_EN_B_EV1_RT_EE_UNFL_ERR,                          AIF2_EE_LK_EN_B_EV1_RT_EE_EM_ERR,
 *         AIF2_EE_LK_EN_B_EV1_RT_EE_HDR_ERR;      
 *
 *         AIF2_EE_LK_EN_STS_B_EV0_PD_EE_EOP_ERR,                           AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CRC_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CPRI_FRAME_ERR,              AIF2_EE_LK_EN_STS_B_EV0_PD_EE_AXC_FAIL_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PD_EE_SOP_ERR,                           AIF2_EE_LK_EN_STS_B_EV0_PD_EE_OBSAI_FRM_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PD_EE_WR2DB_ERR,                      AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MODRULE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PE_EE_SYM_ERR,                           AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_DB_STARVE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_PE_EE_RT_IF_ERR,                         AIF2_EE_LK_EN_STS_B_EV0_PE_EE_PKT_STARVE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_RT_EE_FRM_ERR,                           AIF2_EE_LK_EN_STS_B_EV0_RT_EE_OVFL_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_RT_EE_UNFL_ERR,                          AIF2_EE_LK_EN_STS_B_EV0_RT_EE_EM_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV0_RT_EE_HDR_ERR;                                 
 *
 *         AIF2_EE_LK_EN_STS_B_EV1_PD_EE_EOP_ERR,                           AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CRC_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CPRI_FRAME_ERR,              AIF2_EE_LK_EN_STS_B_EV1_PD_EE_AXC_FAIL_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PD_EE_SOP_ERR,                           AIF2_EE_LK_EN_STS_B_EV1_PD_EE_OBSAI_FRM_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PD_EE_WR2DB_ERR,                      AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MODRULE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PE_EE_SYM_ERR,                           AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_DB_STARVE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_PE_EE_RT_IF_ERR,                         AIF2_EE_LK_EN_STS_B_EV1_PE_EE_PKT_STARVE_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_RT_EE_FRM_ERR,                           AIF2_EE_LK_EN_STS_B_EV1_RT_EE_OVFL_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_RT_EE_UNFL_ERR,                          AIF2_EE_LK_EN_STS_B_EV1_RT_EE_EM_ERR,
 *         AIF2_EE_LK_EN_STS_B_EV1_RT_EE_HDR_ERR;      
 *   @b Example
 *   @verbatim
        CSL_Aif2EeLinkBInt  LinkBInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        hAif2->arg_link = 0;//link0
        
        CSL_aif2GetEeLinkBIntStatus(hAif2,&LinkBInt);
     @endverbatim
 * ===========================================================================
 */
static inline
void CSL_aif2GetEeLinkBIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeLinkBInt*     LinkBInt
); /*for misra warnings*/
static inline
void CSL_aif2GetEeLinkBIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeLinkBInt*     LinkBInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 LinkBInt->pd_ee_eop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_EOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_crc_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_CRC_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_cpri_frame_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_CPRI_FRAME_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_axc_fail_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_AXC_FAIL_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_sop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_SOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_obsai_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_OBSAI_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_wr2db_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PD_EE_WR2DB_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_modrule_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_MODRULE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_sym_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_SYM_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_overflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_OVERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_underflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_MF_FIFO_UNDERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_db_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_DB_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_rt_if_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_RT_IF_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_pkt_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_PE_EE_PKT_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_RT_EE_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_ovfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_RT_EE_OVFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_unfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_RT_EE_UNFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_em_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_RT_EE_EM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_hdr_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_IRS_B, AIF2_EE_LK_IRS_B_RT_EE_HDR_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 LinkBInt->pd_ee_eop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_EOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_crc_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_CRC_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_cpri_frame_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_CPRI_FRAME_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_axc_fail_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_AXC_FAIL_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_sop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_SOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_obsai_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_OBSAI_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_wr2db_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PD_EE_WR2DB_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_modrule_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_MODRULE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_sym_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_SYM_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_overflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_underflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_db_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_DB_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_rt_if_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_RT_IF_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_pkt_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_PE_EE_PKT_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_RT_EE_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_ovfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_RT_EE_OVFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_unfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_RT_EE_UNFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_em_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_RT_EE_EM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_hdr_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV0, AIF2_EE_LK_EN_B_EV0_RT_EE_HDR_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 LinkBInt->pd_ee_eop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_EOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_crc_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_CRC_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_cpri_frame_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_CPRI_FRAME_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_axc_fail_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_AXC_FAIL_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_sop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_SOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_obsai_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_OBSAI_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_wr2db_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PD_EE_WR2DB_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_modrule_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_MODRULE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_sym_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_SYM_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_overflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_underflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_db_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_DB_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_rt_if_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_RT_IF_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_pkt_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_PE_EE_PKT_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_RT_EE_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_ovfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_RT_EE_OVFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_unfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_RT_EE_UNFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_em_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_RT_EE_EM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_hdr_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_B_EV1, AIF2_EE_LK_EN_B_EV1_RT_EE_HDR_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 LinkBInt->pd_ee_eop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_EOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_crc_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CRC_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_cpri_frame_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_CPRI_FRAME_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_axc_fail_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_AXC_FAIL_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_sop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_SOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_obsai_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_OBSAI_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_wr2db_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PD_EE_WR2DB_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_modrule_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MODRULE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_sym_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_SYM_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_overflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_OVERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_underflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_MF_FIFO_UNDERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_db_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_DB_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_rt_if_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_RT_IF_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_pkt_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_PE_EE_PKT_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_RT_EE_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_ovfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_RT_EE_OVFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_unfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_RT_EE_UNFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_em_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_RT_EE_EM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_hdr_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV0, AIF2_EE_LK_EN_STS_B_EV0_RT_EE_HDR_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 LinkBInt->pd_ee_eop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_EOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_crc_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CRC_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_cpri_frame_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_CPRI_FRAME_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_axc_fail_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_AXC_FAIL_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_sop_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_SOP_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_obsai_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_OBSAI_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->pd_ee_wr2db_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PD_EE_WR2DB_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_modrule_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MODRULE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_sym_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_SYM_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_overflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_OVERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_mf_fifo_underflow_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_MF_FIFO_UNDERFLOW_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_db_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_DB_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_rt_if_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_RT_IF_ERR) ? TRUE : FALSE;
	 LinkBInt->pe_ee_pkt_starve_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_PE_EE_PKT_STARVE_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_frm_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_RT_EE_FRM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_ovfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_RT_EE_OVFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_unfl_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_RT_EE_UNFL_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_em_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_RT_EE_EM_ERR) ? TRUE : FALSE;
	 LinkBInt->rt_ee_hdr_err=  CSL_FEXT(hAif2->regs->EE_LK[hAif2->arg_link].EE_LK_EN_STS_B_EV1, AIF2_EE_LK_EN_STS_B_EV1_RT_EE_HDR_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEeAtIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE AT interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EeAtInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SYS_RCVD_ERR,       AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RP3_RCVD_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_TOD_RCVD_ERR,       AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_UNSEL_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SPARE_ERR,              AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RSVD_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_RP1_BIT_WIDTH_ERR,                AIF2_EE_AT_IRS_AT_EE_RP1_CRC_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_RP1_RP3_ERR,                           AIF2_EE_AT_IRS_AT_EE_RP1_SYS_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_PI0_ERR,AIF2_EE_AT_IRS_AT_EE_PI1_ERR,AIF2_EE_AT_IRS_AT_EE_PI2_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_PI3_ERR,AIF2_EE_AT_IRS_AT_EE_PI4_ERR,AIF2_EE_AT_IRS_AT_EE_PI5_ERR,
 *         AIF2_EE_AT_IRS_AT_EE_PHYT_SYNC_ERR,                      AIF2_EE_AT_IRS_AT_EE_RADT_SYNC_ERR;
 *
 *         AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR,       AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR,       AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_UNSEL_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SPARE_ERR,              AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RSVD_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_RP1_BIT_WIDTH_ERR,                AIF2_EE_AT_EN_EV0_AT_EE_RP1_CRC_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_RP1_RP3_ERR,                           AIF2_EE_AT_EN_EV0_AT_EE_RP1_SYS_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_PI0_ERR,AIF2_EE_AT_EN_EV0_AT_EE_PI1_ERR,AIF2_EE_AT_EN_EV0_AT_EE_PI2_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_PI3_ERR,AIF2_EE_AT_EN_EV0_AT_EE_PI4_ERR,AIF2_EE_AT_EN_EV0_AT_EE_PI5_ERR,
 *         AIF2_EE_AT_EN_EV0_AT_EE_PHYT_SYNC_ERR,                      AIF2_EE_AT_EN_EV0_AT_EE_RADT_SYNC_ERR;
 *
 *         AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR,       AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR,       AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_UNSEL_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SPARE_ERR,              AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RSVD_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_RP1_BIT_WIDTH_ERR,                AIF2_EE_AT_EN_EV1_AT_EE_RP1_CRC_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_RP1_RP3_ERR,                           AIF2_EE_AT_EN_EV1_AT_EE_RP1_SYS_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_PI0_ERR,AIF2_EE_AT_EN_EV1_AT_EE_PI1_ERR,AIF2_EE_AT_EN_EV1_AT_EE_PI2_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_PI3_ERR,AIF2_EE_AT_EN_EV1_AT_EE_PI4_ERR,AIF2_EE_AT_EN_EV1_AT_EE_PI5_ERR,
 *         AIF2_EE_AT_EN_EV1_AT_EE_PHYT_SYNC_ERR,                      AIF2_EE_AT_EN_EV1_AT_EE_RADT_SYNC_ERR;
 *
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR,       AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR,       AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_UNSEL_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SPARE_ERR,              AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RSVD_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_BIT_WIDTH_ERR,                AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_CRC_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_RP3_ERR,                           AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_SYS_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_PI0_ERR,AIF2_EE_AT_EN_STS_EV0_AT_EE_PI1_ERR,AIF2_EE_AT_EN_STS_EV0_AT_EE_PI2_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_PI3_ERR,AIF2_EE_AT_EN_STS_EV0_AT_EE_PI4_ERR,AIF2_EE_AT_EN_STS_EV0_AT_EE_PI5_ERR,
 *         AIF2_EE_AT_EN_STS_EV0_AT_EE_PHYT_SYNC_ERR,                      AIF2_EE_AT_EN_STS_EV0_AT_EE_RADT_SYNC_ERR;
 *
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR,       AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR,       AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_UNSEL_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SPARE_ERR,              AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RSVD_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_BIT_WIDTH_ERR,                AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_CRC_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_RP3_ERR,                           AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_SYS_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_PI0_ERR,AIF2_EE_AT_EN_STS_EV1_AT_EE_PI1_ERR,AIF2_EE_AT_EN_STS_EV1_AT_EE_PI2_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_PI3_ERR,AIF2_EE_AT_EN_STS_EV1_AT_EE_PI4_ERR,AIF2_EE_AT_EN_STS_EV1_AT_EE_PI5_ERR,
 *         AIF2_EE_AT_EN_STS_EV1_AT_EE_PHYT_SYNC_ERR,                      AIF2_EE_AT_EN_STS_EV1_AT_EE_RADT_SYNC_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EeAtInt  AtInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEeAtIntStatus(hAif2,&AtInt);
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline
void CSL_aif2GetEeAtIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAtInt*     AtInt
);
static inline
void CSL_aif2GetEeAtIntStatus (
        CSL_Aif2Handle   hAif2,
        CSL_Aif2EeAtInt*     AtInt
)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 AtInt->at_ee_rp1_type_sys_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SYS_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rp3_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RP3_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_tod_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_TOD_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_unsel_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_UNSEL_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_spare_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_SPARE_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rsvd_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_TYPE_RSVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_bit_width_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_BIT_WIDTH_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_crc_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_CRC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_rp3_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_RP3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_sys_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RP1_SYS_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi0_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI0_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi1_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI1_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi2_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI2_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi3_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi4_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI4_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi5_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PI5_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_phyt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_PHYT_SYNC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_radt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_IRS, AIF2_EE_AT_IRS_AT_EE_RADT_SYNC_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 AtInt->at_ee_rp1_type_sys_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rp3_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_tod_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_unsel_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_UNSEL_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_spare_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_SPARE_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rsvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_TYPE_RSVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_bit_width_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_BIT_WIDTH_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_crc_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_CRC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_rp3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_RP3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_sys_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RP1_SYS_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi0_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI0_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi1_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI1_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi2_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI2_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi4_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI4_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi5_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PI5_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_phyt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_PHYT_SYNC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_radt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV0, AIF2_EE_AT_EN_EV0_AT_EE_RADT_SYNC_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 AtInt->at_ee_rp1_type_sys_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rp3_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_tod_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_unsel_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_UNSEL_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_spare_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_SPARE_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rsvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_TYPE_RSVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_bit_width_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_BIT_WIDTH_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_crc_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_CRC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_rp3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_RP3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_sys_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RP1_SYS_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi0_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI0_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi1_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI1_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi2_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI2_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi4_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI4_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi5_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PI5_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_phyt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_PHYT_SYNC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_radt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_EV1, AIF2_EE_AT_EN_EV1_AT_EE_RADT_SYNC_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 AtInt->at_ee_rp1_type_sys_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SYS_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rp3_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RP3_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_tod_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_TOD_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_unsel_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_UNSEL_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_spare_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_SPARE_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rsvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_TYPE_RSVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_bit_width_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_BIT_WIDTH_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_crc_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_CRC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_rp3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_RP3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_sys_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RP1_SYS_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi0_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI0_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi1_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI1_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi2_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI2_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi4_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI4_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi5_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PI5_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_phyt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_PHYT_SYNC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_radt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV0, AIF2_EE_AT_EN_STS_EV0_AT_EE_RADT_SYNC_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 AtInt->at_ee_rp1_type_sys_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SYS_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rp3_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RP3_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_tod_rcvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_TOD_RCVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_unsel_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_UNSEL_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_spare_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_SPARE_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_type_rsvd_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_TYPE_RSVD_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_bit_width_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_BIT_WIDTH_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_crc_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_CRC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_rp3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_RP3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_rp1_sys_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RP1_SYS_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi0_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI0_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi1_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI1_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi2_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI2_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi3_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI3_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi4_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI4_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_pi5_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PI5_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_phyt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_PHYT_SYNC_ERR) ? TRUE : FALSE;
	 AtInt->at_ee_radt_sync_err=  CSL_FEXT(hAif2->regs->EE_AT_EN_STS_EV1, AIF2_EE_AT_EN_STS_EV1_AT_EE_RADT_SYNC_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEePdIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE PD common interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EePdInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_PD_COMMON_IRS_PD_EE_TS_WDOG_ERR;AIF2_EE_PD_COMMON_EN_EV0_PD_EE_TS_WDOG_ERR;
 *         AIF2_EE_PD_COMMON_EN_EV1_PD_EE_TS_WDOG_ERR;AIF2_EE_PD_COMMON_EN_STS_EV0_PD_EE_TS_WDOG_ERR;
 *         AIF2_EE_PD_COMMON_EN_STS_EV1_PD_EE_TS_WDOG_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EePdInt  PdInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEePdIntStatus(hAif2,&PdInt);
     @endverbatim
 * ===========================================================================
 */
static inline void CSL_aif2GetEePdIntStatus (CSL_Aif2Handle   hAif2, CSL_Aif2EePdInt*     PdInt);
static inline void CSL_aif2GetEePdIntStatus (CSL_Aif2Handle   hAif2, CSL_Aif2EePdInt*     PdInt)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 PdInt->pd_ee_ts_wdog_err=  CSL_FEXT(hAif2->regs->EE_PD_COMMON_IRS, AIF2_EE_PD_COMMON_IRS_PD_EE_TS_WDOG_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 PdInt->pd_ee_ts_wdog_err=  CSL_FEXT(hAif2->regs->EE_PD_COMMON_EN_EV0, AIF2_EE_PD_COMMON_EN_EV0_PD_EE_TS_WDOG_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 PdInt->pd_ee_ts_wdog_err=  CSL_FEXT(hAif2->regs->EE_PD_COMMON_EN_EV1, AIF2_EE_PD_COMMON_EN_EV1_PD_EE_TS_WDOG_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 PdInt->pd_ee_ts_wdog_err=  CSL_FEXT(hAif2->regs->EE_PD_COMMON_EN_STS_EV0, AIF2_EE_PD_COMMON_EN_STS_EV0_PD_EE_TS_WDOG_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 PdInt->pd_ee_ts_wdog_err=  CSL_FEXT(hAif2->regs->EE_PD_COMMON_EN_STS_EV1, AIF2_EE_PD_COMMON_EN_STS_EV1_PD_EE_TS_WDOG_ERR) ? TRUE : FALSE;
        }
	 
}


/** ============================================================================
 *   @n@b CSL_aif2GetEePeIntStatus
 *
 *   @b Description
 *   @n Get Aif2 EE PE common interrupt  status value
 *
 *   @b Arguments
 *   @verbatim
           hAif2      Handle to the aif2 instance     use hAif2->ee_arg to select function
           CSL_Aif2EePeInt     
      @endverbatim
 *
 *   <b> Return Value </b>  void
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before calling this function.
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n  AIF2_EE_PE_COMMON_IRS_PE_EE_RD2DB_ERR,AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_REQ_OVFL_ERR,
 *         AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_WR_ERR,AIF2_EE_PE_COMMON_IRS_PE_EE_DAT_REQ_OVFL_ERR;
 *         AIF2_EE_PE_COMMON_EN_EV0_PE_EE_RD2DB_ERR,AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_REQ_OVFL_ERR,
 *         AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_WR_ERR,AIF2_EE_PE_COMMON_EN_EV0_PE_EE_DAT_REQ_OVFL_ERR;
 *         AIF2_EE_PE_COMMON_EN_EV1_PE_EE_RD2DB_ERR,AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_REQ_OVFL_ERR,
 *         AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_WR_ERR,AIF2_EE_PE_COMMON_EN_EV1_PE_EE_DAT_REQ_OVFL_ERR;         
 *        AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_RD2DB_ERR,AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_REQ_OVFL_ERR,
 *        AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_WR_ERR,AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_DAT_REQ_OVFL_ERR;
 *        AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_RD2DB_ERR,AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_REQ_OVFL_ERR,
 *        AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_WR_ERR,AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_DAT_REQ_OVFL_ERR;
 *   @b Example
 *   @verbatim
        CSL_Aif2EePeInt  PeInt;
        hAif2->ee_arg = CSL_AIF2_EE_INT_RAW_STATUS;
        
        CSL_aif2GetEePeIntStatus(hAif2,&PeInt);
     @endverbatim
 * ===========================================================================
 */
static inline void CSL_aif2GetEePeIntStatus (CSL_Aif2Handle   hAif2, CSL_Aif2EePeInt*     PeInt);  /*for misra warnings*/
static inline void CSL_aif2GetEePeIntStatus (CSL_Aif2Handle   hAif2, CSL_Aif2EePeInt*     PeInt)
{ 
        if(hAif2->ee_arg == CSL_AIF2_EE_INT_RAW_STATUS){
	 PeInt->pe_ee_rd2db_err =               CSL_FEXT(hAif2->regs->EE_PE_COMMON_IRS, AIF2_EE_PE_COMMON_IRS_PE_EE_RD2DB_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_req_ovfl_err =  CSL_FEXT(hAif2->regs->EE_PE_COMMON_IRS, AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_REQ_OVFL_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_wr_err =          CSL_FEXT(hAif2->regs->EE_PE_COMMON_IRS, AIF2_EE_PE_COMMON_IRS_PE_EE_TOKEN_WR_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_dat_req_ovfl_err =     CSL_FEXT(hAif2->regs->EE_PE_COMMON_IRS, AIF2_EE_PE_COMMON_IRS_PE_EE_DAT_REQ_OVFL_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV0){
	 PeInt->pe_ee_rd2db_err =               CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV0, AIF2_EE_PE_COMMON_EN_EV0_PE_EE_RD2DB_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_req_ovfl_err =  CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV0, AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_REQ_OVFL_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_wr_err =          CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV0, AIF2_EE_PE_COMMON_EN_EV0_PE_EE_TOKEN_WR_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_dat_req_ovfl_err =     CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV0, AIF2_EE_PE_COMMON_EN_EV0_PE_EE_DAT_REQ_OVFL_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_EV1){
	 PeInt->pe_ee_rd2db_err =               CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV1, AIF2_EE_PE_COMMON_EN_EV1_PE_EE_RD2DB_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_req_ovfl_err =  CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV1, AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_REQ_OVFL_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_wr_err =          CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV1, AIF2_EE_PE_COMMON_EN_EV1_PE_EE_TOKEN_WR_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_dat_req_ovfl_err =     CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_EV1, AIF2_EE_PE_COMMON_EN_EV1_PE_EE_DAT_REQ_OVFL_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV0){
	 PeInt->pe_ee_rd2db_err =               CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV0, AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_RD2DB_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_req_ovfl_err =  CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV0, AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_REQ_OVFL_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_wr_err =          CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV0, AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_TOKEN_WR_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_dat_req_ovfl_err =     CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV0, AIF2_EE_PE_COMMON_EN_STS_EV0_PE_EE_DAT_REQ_OVFL_ERR) ? TRUE : FALSE;
        }
	 else if(hAif2->ee_arg == CSL_AIF2_EE_INT_EN_STATUS_EV1){
	 PeInt->pe_ee_rd2db_err =               CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV1, AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_RD2DB_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_req_ovfl_err =  CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV1, AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_REQ_OVFL_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_token_wr_err =          CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV1, AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_TOKEN_WR_ERR) ? TRUE : FALSE;
	 PeInt->pe_ee_dat_req_ovfl_err =     CSL_FEXT(hAif2->regs->EE_PE_COMMON_EN_STS_EV1, AIF2_EE_PE_COMMON_EN_STS_EV1_PE_EE_DAT_REQ_OVFL_ERR) ? TRUE : FALSE;
        }
	 
}



#ifdef __cplusplus
}
#endif
#endif /* CSL_aif2GetHwStatusAUX_H */


