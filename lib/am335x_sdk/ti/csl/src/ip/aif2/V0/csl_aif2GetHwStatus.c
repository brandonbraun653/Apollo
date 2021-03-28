/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008,  2009
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
 *   @file  csl_aif2GetHwStatus.c
 *
 *   @path  $(CSLPATH)\aif2\src
 *
 *   @brief  Antenna Interface 2 get hardware status function
 *
 */


/* =============================================================================
 * Revision History
 * ===============
 *  03-Jun-2009  Albert  File Created.
 *  
 *
 * =============================================================================
 */

#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_aif2GetHwStatus
 *
 *   @b Description
 *   @n This function is used to get the value of various parameters of the
 *      aif2 instance. The value returned depends on the query passed.
 *
 *   @b Arguments
 *   @verbatim
            hAif2      Handle to the aif2 instance
 
            Query         Query to be performed 
 
            response      Pointer to buffer to return the data requested by
                          the query passed
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Successful completion of the
 *                                               query
 *
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   @li                    CSL_ESYS_INVQUERY  - Query command not supported
 *
 *   @li                    CSL_ESYS_FAIL      - Generic failure
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_aif2Init(), CSL_aif2Open()
 *
 *   <b> Post Condition </b>
 *       Data requested by query is returned through the variable "response"
 *
 *   @b Writes
 *   @n The input argument "response" is modified
 *
 *   @b Example
 *   @verbatim
        
        #define CSL_AIF2_MAX_RX_MASTER_FRAME_OFFSET         256   
 
        CSL_Aif2Handle hAif2;
        // other link related declarations
        ...
        // ctrl argument for hw command
        Bool ctrlArg;
        // query response
        Uint16 response;

        // Open handle  - for use 
        hAif2 = CSL_aif2Open(&Aif2Obj, CSL_AIF2, &aif2Param, &status);

        if ((hAif2 == NULL) || (status != CSL_SOK)) 
        {
           printf ("\nError opening CSL_AIF2");
           exit(1);
        }

        // Do config for link 0 
        Config.globalSetup = &gblCfg;
        ...
         
        //Do setup for link - 0
        CSL_aif2HwSetup(hAif2, &Config);

        ctrlArg = CSL_AIF2_CTRL_RX_LINK_ENABLE;
        hAif2->arg_link = CSL_AIF2_LINK_0; //link 0 enable
        
        // Send hw control command to enable Tx/Rx of link 0 
        CSL_aif2HwControl(hAif2, CSL_AIF2_CMD_ENABLE_DISABLE_RX_LINK, (void *)&ctrlArg);
        ...
        wait(100); //wait for a sufficient length of time, so Rx link has enough 
                     time to sync; 100 cycles wait time is arbitrarily chosen 
    
        // Get status of Rx master frame offset  
        hAif2->arg_link = CSL_AIF2_LINK_0; //get link 0 status
        CSL_aif2GetHwStatus(hAif2, CSL_AIF2_QUERY_RM_LINK_RCVD_MSTR_FRAME_OFFSET, (void *)&response);
   
        if (response > CSL_AIF2_MAX_RX_MASTER_FRAME_OFFSET)
        {
           printf("\nRx Master Frame Offset exceeds bounds");
        }

     @endverbatim
 * =============================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2GetHwStatus, ".text:csl_section:aif2")
#endif

CSL_Status  CSL_aif2GetHwStatus(
   CSL_Aif2Handle                      hAif2,
   CSL_Aif2HwStatusQuery               Query,
   void                               *response
)
{
    CSL_Status status = CSL_SOK;
    
    if (hAif2 == NULL)
    {
        status = CSL_ESYS_BADHANDLE;
    }
    else
    {
        switch (Query) {
        
        /** returns VC AIF2 version */
        case CSL_AIF2_QUERY_VERSION:
            CSL_aif2GetVersion(hAif2, (CSL_Aif2PidStatus *)response);
            break;

         /** returns VC Emu status */
        case CSL_AIF2_QUERY_VC_STAT:
            *((Bool *)response) = CSL_aif2GetVcStat(hAif2);
            break;
        
        /* SERDES Rx link Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2SdRxStatus *) */
        case CSL_AIF2_QUERY_SD_RX_LINK_STATUS:
             CSL_aif2GetSdRxLinkStatus (hAif2, (CSL_Aif2SdRxStatus *)response);  
            break;
        
        /* Return the status of SERDES B8 PLL lock.   @param (Uint8 *)*/
        case CSL_AIF2_QUERY_SD_B8_PLL_LOCK:
            *((Uint8 *)response) = CSL_aif2GetSdB8PllLock (hAif2);  
            break;
        
        /* Return the status of SERDES B4 PLL lock.   @param (Uint8 *)*/
        case CSL_AIF2_QUERY_SD_B4_PLL_LOCK:
            *((Uint8 *)response) = CSL_aif2GetSdB4PllLock (hAif2);  
            break;

        /** RM link Status 0. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus0 *)*/
        case CSL_AIF2_QUERY_RM_LINK_STATUS_0:
            CSL_aif2GetRmLinkStatus0  (hAif2, (CSL_Aif2RmStatus0 *)response);
            break;

        /** RM link Status 1. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus1 *)*/
        case CSL_AIF2_QUERY_RM_LINK_STATUS_1:
            CSL_aif2GetRmLinkStatus1  (hAif2, (CSL_Aif2RmStatus1 *)response);
            break;

        /** RM link Status 2. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus2 *)*/
        case CSL_AIF2_QUERY_RM_LINK_STATUS_2:
            CSL_aif2GetRmLinkStatus2  (hAif2, (CSL_Aif2RmStatus2 *)response);
            break;

         /** RM link Status 3. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus3 *)*/
        case CSL_AIF2_QUERY_RM_LINK_STATUS_3:
            CSL_aif2GetRmLinkStatus3  (hAif2, (CSL_Aif2RmStatus3 *)response);
            break;

        /** RM link Status 4. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus4 *)*/
        case CSL_AIF2_QUERY_RM_LINK_STATUS_4:
            CSL_aif2GetRmLinkStatus4  (hAif2, (CSL_Aif2RmStatus4 *)response);
            break;
        
        /** Return TM link CPRI HFN Status. use hAif2->arg_link to choose link.  @param (Uint8 *)*/
        case CSL_AIF2_QUERY_TM_LINK_CPRI_HFN:
            *((Uint8 *)response) = CSL_aif2GetTmCpriHfnStatus (hAif2);  
            break;
        
         /** TM link Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2TmStatus *)*/
        case CSL_AIF2_QUERY_TM_LINK_STATUS:
            CSL_aif2GetTmLinkStatus  (hAif2, (CSL_Aif2TmStatus *)response);
            break;

        /** RT Internal FIFO depth Status. use hAif2->arg_link to choose link.  @param (Uint8 *)*/
        case CSL_AIF2_QUERY_RT_FIFO_DEPTH_STATUS:
            *((Uint8 *)response) = CSL_aif2GetRtFifoDepthStatus (hAif2);
            break;

        /** RT Header Error Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2RtHeaderStatus *)*/
        case CSL_AIF2_QUERY_RT_HEADER_ERROR_STATUS:
            CSL_aif2GetRtHeaderStatus (hAif2, (CSL_Aif2RtHeaderStatus *)response);
            break;
        
        /** RT link Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2RtStatus *)*/
        case CSL_AIF2_QUERY_RT_LINK_STATUS:
            CSL_aif2GetRtLinkStatus (hAif2, (CSL_Aif2RtStatus *)response);
            break;
        
         /** PD 128 Channel Status.  @param (Uint32 *)*/
        case CSL_AIF2_QUERY_PD_CHANNEL_STATUS:
            CSL_aif2GetPdChannelStatus  (hAif2, (Uint32 *)response);
            break;

         /** PD Packet Status for 128 channels if it is in or out of packet.  @param (Uint32 *)*/
        case CSL_AIF2_QUERY_PD_PACKET_STATUS:
            CSL_aif2GetPdPacketStatus  (hAif2, (Uint32 *)response);
            break;

        /** PE 128 Channel Status.  @param (Uint32 *)*/
        case CSL_AIF2_QUERY_PE_CHANNEL_STATUS:
            CSL_aif2GetPeChannelStatus  (hAif2, (Uint32 *)response);
            break;

         /** PE Packet Status for 128 channels if it is in or out of packet.  @param (Uint32 *)*/
        case CSL_AIF2_QUERY_PE_PACKET_STATUS:
            CSL_aif2GetPePacketStatus  (hAif2, (Uint32 *)response);
            break;
        
        /* Get Write and Read Offset Value at address in DB_IDB_DEBUG_OFS @param (Uint8 *) */
        case CSL_AIF2_QUERY_DB_IN_DEBUG_OFFSET_DATA:
            CSL_aif2GetInDbDebugOffsetData (hAif2, (Uint8 *)response);
            break;

        /** Debug data written to bits 128:0 of Egress DB RAM  @param ( Uint32 *) */
        case CSL_AIF2_QUERY_DB_E_DEBUG_DATA:
            CSL_aif2GetEDbDebugData(hAif2, (Uint32 *)response);
            break;
        
        /** Egress DB debug side band data setup  @param ( CSL_Aif2DbSideData *)  */
        case CSL_AIF2_QUERY_DB_E_DEBUG_SIDE_DATA:
            CSL_aif2GetEDbDebugSideData(hAif2, (CSL_Aif2DbSideData *)response);
            break;
        
        /* Get Write and Read Offset Value at address in DB_EDB_DEBUG_OFS  @param (Uint8 *) */
        case CSL_AIF2_QUERY_DB_E_DEBUG_OFFSET_DATA:
            CSL_aif2GetEDbDebugOffsetData (hAif2,(Uint8 *)response);
            break;

        /* Get Egress EOP count value   @param (Uint32 *) */
        case CSL_AIF2_QUERY_DB_E_EOP_COUNT:
            *((Uint32 *)response) = CSL_aif2GetEgrEopCount(hAif2);
            break;

        /* Get Inress EOP count value   @param (Uint32 *) */
        case CSL_AIF2_QUERY_AD_I_EOP_COUNT:
            *((Uint32 *)response) = CSL_aif2GetIngrEopCount(hAif2);
            break;

        /* Get Aif2 timer link Pi captured value. use hAif2->arg_link to choose link   @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_LINK_PI_CAPTURE:
            *((Uint32 *)response) = CSL_aif2GetAtLinkPiCapture (hAif2);
            break;

       /* Get Aif2 timer capture Radt values @param (CSL_Aif2AtCaptRadt  *) */
        case CSL_AIF2_QUERY_AT_RADT_CAPTURE:
            CSL_aif2GetAtRadtCapture (hAif2, (CSL_Aif2AtCaptRadt *)response);
            break;
        
        /* Get Aif2 timer RP1 type capture value @param (Uint8 *) */
        case CSL_AIF2_QUERY_AT_RP1_TYPE_CAPTURE:
            *((Uint8 *)response) = CSL_aif2GetAtRp1TypeCapture (hAif2);
            break;

        /* Get Aif2 timer RP1 tod capture lsb value    @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_TOD_CAPTURE_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1TodCaptureLsb (hAif2);
            break;

        /* Get Aif2 timer RP1 tod capture msb value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_TOD_CAPTURE_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1TodCaptureMsb (hAif2);
            break;

        /* Get Aif2 timer RP1 rp3 capture lsb value    @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_RP3_CAPTURE_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1Rp3CaptureLsb (hAif2);
            break;

        /* Get Aif2 timer RP1 rp3 capture msb value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_RP3_CAPTURE_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1Rp3CaptureMsb (hAif2);
            break;

        /* Get Aif2 timer RP1 rad capture lsb value    @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_RAD_CAPTURE_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1RadCaptureLsb (hAif2);
            break;

        /* Get Aif2 timer RP1 rad capture msb value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RP1_RAD_CAPTURE_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtRp1RadCaptureMsb (hAif2);
            break;
        /* Get Aif2 Phy timer clock count value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_PHY_CLOCK_COUNT:
            *((Uint32 *)response) = CSL_aif2GetAtPhytClkCount (hAif2);
            break;
        
        /* Get Aif2 Phy timer frame count value lsb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_PHY_FRAME_COUNT_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtPhytFrameLsb (hAif2);
            break;
        
        /* Get Aif2 Phy timer frame count value msb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_PHY_FRAME_COUNT_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtPhytFrameMsb (hAif2);
            break;

        /* Get Aif2 Rad timer clock count value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RAD_CLOCK_COUNT:
            *((Uint32 *)response) = CSL_aif2GetAtRadtClkCount (hAif2);
            break;

        /* Get Aif2 Rad timer symbol count value  @param (Uint8 *) */
        case CSL_AIF2_QUERY_AT_RAD_SYMBOL_COUNT:
            *((Uint8 *)response) = CSL_aif2GetAtRadtSymCount (hAif2);
            break;
        
        /* Get Aif2 Rad timer frame count value lsb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RAD_FRAME_COUNT_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtRadtFrameLsb (hAif2);
            break;
        
        /* Get Aif2 Rad timer frame count value msb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RAD_FRAME_COUNT_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtRadtFrameMsb (hAif2);
            break;

        /* Get Aif2 Ul Rad timer clock count value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_ULRAD_CLOCK_COUNT:
            *((Uint32 *)response) = CSL_aif2GetAtUlRadtClkCount (hAif2);
            break;

        /* Get Aif2 Ul Rad timer symbol count value  @param (Uint8 *) */
        case CSL_AIF2_QUERY_AT_ULRAD_SYMBOL_COUNT:
            *((Uint8 *)response) = CSL_aif2GetAtUlRadtSymCount (hAif2);
            break;
        
        /* Get Aif2 Ul Rad timer frame count value lsb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_ULRAD_FRAME_COUNT_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtUlRadtFrameLsb (hAif2);
            break;
        
        /* Get Aif2 Ul Rad timer frame count value msb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_ULRAD_FRAME_COUNT_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtUlRadtFrameMsb (hAif2);
            break;
        
        /* Get Aif2 Dl Rad timer clock count value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_DLRAD_CLOCK_COUNT:
            *((Uint32 *)response) = CSL_aif2GetAtDlRadtClkCount (hAif2);
            break;

        /* Get Aif2 Dl Rad timer symbol count value  @param (Uint8 *) */
        case CSL_AIF2_QUERY_AT_DLRAD_SYMBOL_COUNT:
            *((Uint8 *)response) = CSL_aif2GetAtDlRadtSymCount (hAif2);
            break;
        
        /* Get Aif2 Dl Rad timer frame count value lsb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_DLRAD_FRAME_COUNT_LSB:
            *((Uint32 *)response) = CSL_aif2GetAtDlRadtFrameLsb (hAif2);
            break;
        
        /* Get Aif2 Dl Rad timer frame count value msb @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_DLRAD_FRAME_COUNT_MSB:
            *((Uint32 *)response) = CSL_aif2GetAtDlRadtFrameMsb (hAif2);
            break;

        /* Get Aif2 Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
        case CSL_AIF2_QUERY_AT_RAD_WCDMA_VALUE:
        CSL_aif2GetAtRadtWcdmaValue (hAif2, (CSL_Aif2AtWcdmaCount *)response);
            break;

        /* Get Aif2 Ul Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
        case CSL_AIF2_QUERY_AT_ULRAD_WCDMA_VALUE:
        CSL_aif2GetAtUlRadtWcdmaValue (hAif2, (CSL_Aif2AtWcdmaCount *)response);
            break;

        /* Get Aif2 Dl Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
        case CSL_AIF2_QUERY_AT_DLRAD_WCDMA_VALUE:
        CSL_aif2GetAtDlRadtWcdmaValue (hAif2, (CSL_Aif2AtWcdmaCount *)response);
            break;

        /* Get Aif2 Rad timer time stamp clock count value  @param (Uint32 *) */
        case CSL_AIF2_QUERY_AT_RAD_TSTAMP_CLOCK_COUNT:
            *((Uint32 *)response) = CSL_aif2GetAtRadtTstampClkCount (hAif2);
            break;

        /* Get Aif2 GSM Tcount  value  @param (CSL_Aif2AtGsmTCount *) */
        case CSL_AIF2_QUERY_AT_GSM_TCOUNT_VALUE:
            CSL_aif2GetAtGsmTcount (hAif2, (CSL_Aif2AtGsmTCount *)response);
            break;

        /* Get Aif2 EE DB interrupt  status value  @param (CSL_Aif2EeDbInt *) use hAif2->ee_arg to select function  */
        case CSL_AIF2_QUERY_EE_DB_INT_STATUS:
            CSL_aif2GetEeDbIntStatus (hAif2, (CSL_Aif2EeDbInt *)response);
            break;

        /* Get Aif2 EE AD interrupt  status value  @param (CSL_Aif2EeAdInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_AD_INT_STATUS:
            CSL_aif2GetEeAdIntStatus (hAif2, (CSL_Aif2EeAdInt *)response);
            break;

        /* Get Aif2 EE CD(PKTDMA) interrupt  status value  @param (CSL_Aif2EeCdInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_CD_INT_STATUS:
            CSL_aif2GetEeCdIntStatus (hAif2, (CSL_Aif2EeCdInt *)response);
            break;

        /* Get Aif2 EE SD interrupt  status value  @param (CSL_Aif2EeSdInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_SD_INT_STATUS:
            CSL_aif2GetEeSdIntStatus (hAif2, (CSL_Aif2EeSdInt *)response);
            break;

        /* Get Aif2 EE VC interrupt  status value  @param (CSL_Aif2EeVcInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_VC_INT_STATUS:
            CSL_aif2GetEeVcIntStatus (hAif2, (CSL_Aif2EeVcInt *)response);
            break;

        /* Get Aif2 EE AIF2 run status value  @param (CSL_Aif2EeAif2Run *)  */
        case CSL_AIF2_QUERY_EE_AIF2_RUN_STATUS:
            CSL_aif2GetEeAif2RunStatus (hAif2, (CSL_Aif2EeAif2Run*)response);
            break;

        /* Get Aif2 EE error or alarm origination status  @param (CSL_Aif2EeAif2Run *)  */
        case CSL_AIF2_QUERY_EE_AIF2_ORIGINATION:
            CSL_aif2GetEeAif2Origination (hAif2, (CSL_Aif2EeOrigin*)response);
            break;

        /* Get Aif2 EE Link A interrupt  status value  @param (CSL_Aif2EeLinkAInt *) use hAif2->ee_arg to select function and hAif2->arg_link to select link */
        case CSL_AIF2_QUERY_EE_LINKA_INT_STATUS:
            CSL_aif2GetEeLinkAIntStatus (hAif2, (CSL_Aif2EeLinkAInt *)response);
            break;

        /* Get Aif2 EE Link B interrupt  status value  @param (CSL_Aif2EeLinkBInt *) use hAif2->ee_arg to select function and hAif2->arg_link to select link */
        case CSL_AIF2_QUERY_EE_LINKB_INT_STATUS:
            CSL_aif2GetEeLinkBIntStatus (hAif2, (CSL_Aif2EeLinkBInt *)response);
            break;

        /* Get Aif2 EE AT interrupt  status value  @param (CSL_Aif2EeAtInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_AT_INT_STATUS:
            CSL_aif2GetEeAtIntStatus (hAif2, (CSL_Aif2EeAtInt *)response);
            break;

        /* Get Aif2 EE PD common interrupt  status value  @param (CSL_Aif2EePdInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_PD_INT_STATUS:
            CSL_aif2GetEePdIntStatus (hAif2, (CSL_Aif2EePdInt *)response);
            break;

        /* Get Aif2 EE PE common interrupt  status value  @param (CSL_Aif2EePeInt *) use hAif2->ee_arg to select function */
        case CSL_AIF2_QUERY_EE_PE_INT_STATUS:
            CSL_aif2GetEePeIntStatus (hAif2, (CSL_Aif2EePeInt *)response);
            break;

        default:
            status = CSL_ESYS_INVQUERY;
            break;
        }
    }
    return status;
}

