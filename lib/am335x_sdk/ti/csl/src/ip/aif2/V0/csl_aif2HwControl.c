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

/** ===========================================================================
 *   @file  csl_aif2HwControl.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  Antenna Interface 2 HW control 3.x function
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

/** ===========================================================================
 *   @n@b CSL_aif2HwControl
 *
 *   @b Description
 *   @n This function performs various control operations on aif2 link,
 *      based on the command passed.
 *
 *   @b Arguments
 *   @verbatim
            haif2        Handle to the aif2 instance and link number for an argument
 
            cmd         Operation to be performed on the aif2
 
            arg         Argument specific to the command 
 
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Command execution successful.
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVCMD    - Invalid command
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_aif2Init(), CSL_aif2Open()
 *
 *   <b> Post Condition </b>
 *   @n  Registers of aif2 instance are configured according to the command
 *       and the command arguments. The command determines which registers are
 *       modified.
 *
 *   @b Writes
 *   @n Registers determined by the command
 *
 *   @b Example
 *   @verbatim
        // handle for AIF2
        CSL_Aif2Handle hAif2;
        // other related declarations
        ...
        // ctrl argument for hw command
        Bool ctrlArg;

        // Open handle  - for use 
        hAif2 = CSL_aif2Open(&Aif2Obj, CSL_AIF2, &aif2Param, &status);

        if ((hAif2 == NULL) || (status != CSL_SOK)) 
        {
           printf ("\nError opening CSL_AIF2");
           exit(1);
        }

        // Do config 
        Config.globalSetup = &gblCfg;
        ...
        //Do setup 
        CSL_aif2HwSetup(handleAif2, &Config);

        ctrlArg = CSL_AIF2_CTRL_RX_LINK_ENABLE;
        hAif2->arg_link = CSL_AIF2_LINK_0; //link 0 enable

        // Send hw control command to enable Tx/Rx of link 0 
        CSL_aif2HwControl(hAif2, CSL_AIF2_CMD_ENABLE_DISABLE_RX_LINK, (void *)&ctrlArg);
     @endverbatim
 * ============================================================================
 */
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2HwControl, ".text:csl_section:aif2")
#endif
CSL_Status  CSL_aif2HwControl(
    CSL_Aif2Handle          hAif2,
    CSL_Aif2HwControlCmd    cmd,
    const void              *arg
)
{
    CSL_Status status = CSL_SOK ;      
    
    if (hAif2 == NULL)
    {
        status = CSL_ESYS_BADHANDLE;
    }
    else
    {
        switch (cmd) {
        
        /** Starts Rx link (use hAif2->arg_link to select link)  */
        case CSL_AIF2_CMD_ENABLE_DISABLE_RX_LINK:
            CSL_aif2EnDisRxLink (hAif2, *(Bool *)arg);
            break;
        /** Starts Tx link (use hAif2->arg_link to select link)  */    
        case CSL_AIF2_CMD_ENABLE_DISABLE_TX_LINK:
            CSL_aif2EnDisTxLink(hAif2, *(Bool *)arg);
            break;
         /** Control Aif2 Emulation (argument type:  CSL_Aif2VcEmu*)  */   
        case CSL_AIF2_CMD_VC_EMU_CONTROL:
            CSL_aif2VcEmuControl(hAif2, *(CSL_Aif2VcEmu *)arg);
            break;
        /** Enable SD B8 PLL */   
        case CSL_AIF2_CMD_ENABLE_DISABLE_SD_B8_PLL:
            CSL_aif2EnDisSdB8Pll(hAif2, *(Bool *)arg);
            break;
        /** Enable SD B4 PLL */   
        case CSL_AIF2_CMD_ENABLE_DISABLE_SD_B4_PLL:
            CSL_aif2EnDisSdB4Pll(hAif2, *(Bool *)arg);
            break;
        /** Force RM Sync State (argument type:  CSL_Aif2RmForceSyncState *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_RM_FORCE_STATE:
            CSL_aif2RmLinkForceRxState  (hAif2, *(CSL_Aif2RmForceSyncState *)arg);
            break;
        /** TM L1 Inband Control Signal Set (argument type:  Uint8 *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_TM_L1_INBAND_SET:
            CSL_aif2TmLinkL1InbandSet  (hAif2, *(Uint8 *)arg);
            break;
        /** Force TM Flush FIFO (argument type:  Bool *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_TM_FLUSH_FIFO:
            CSL_aif2ForceTmFlush (hAif2, *(Bool *)arg);
            break;
        /** Force TM Idle state (argument type:  Bool *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_TM_IDLE:
            CSL_aif2ForceTmIdle (hAif2, *(Bool *)arg);
            break;
         /** Force TM Resync state (argument type:  Bool *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_TM_RESYNC:
            CSL_aif2ForceTmReSync (hAif2, *(Bool *)arg);
            break;
        /** Dynamic configuration of PD CPRI id lut register (argument type:  CSL_Aif2PdCpriIdLut  *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_PD_CPRI_ID_LUT_SETUP:
            CSL_aif2PdCpriIdLutDynamicSetup (hAif2, *(CSL_Aif2PdCpriIdLut  *)arg);
            break;
        /** Dynamic configuration of PD CPRI Control Word lut register (argument type:  CSL_Aif2PdCpriCwLut  *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_PD_CPRI_CW_LUT_SETUP:
            CSL_aif2PdCpriCwLutDynamicSetup (hAif2, *(CSL_Aif2CpriCwLut  *)arg);
            break;
        /** Dynamic configuration of PD DBMR  (argument type:  CSL_Aif2DualbitMap  *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_PD_LINK_DBMR_SETUP:
            CSL_aif2PdLinkDbmDynamicSetup (hAif2, *(CSL_Aif2DualBitMap   *)arg);
            break;
        /** Dynamic configuration of PD channel config registers (argument type:  CSL_Aif2PdChannelConfig  *)  */   
        case CSL_AIF2_CMD_PD_CH_CONFIG_SETUP:
            CSL_aif2PdChConfigDynamicSetup (hAif2, *(CSL_Aif2PdChannelConfig  *)arg);
            break;
         /** Dynamic configuration of PE CPRI Control Word lut register (argument type:  CSL_Aif2CpriCwLut  *, use hAif2->arg_link to select link)  */   
        case CSL_AIF2_CMD_PE_CPRI_CW_LUT_SETUP:
            CSL_aif2PeCpriCwLutDynamicSetup (hAif2, *(CSL_Aif2CpriCwLut  *)arg);
            break;
        /** Dynamic configuration of PE obsai header register (argument type:  CSL_Aif2PeObsaiHeader  *)  */   
        case CSL_AIF2_CMD_PE_OBSAI_HEADER_SETUP:
            CSL_aif2PeObsaiHeaderSetup (hAif2, *(CSL_Aif2PeObsaiHeader  *)arg);
            break;
        /** Dynamic configuration of PE DBMR  (argument type:  CSL_Aif2PeDbmr  *)  */   
        case CSL_AIF2_CMD_PE_LINK_DBMR_SETUP:
            CSL_aif2PeDbmrDynamicSetup (hAif2, *(CSL_Aif2PeDbmr   *)arg);
            break;
        /** Dynamic configuration of PE Modulo rule  (argument type:  CSL_Aif2DualbitMap  *)  */   
        case CSL_AIF2_CMD_PE_MODULO_RULE_SETUP:
            CSL_aif2PeModuloTxRuleSetup (hAif2, *(CSL_Aif2PeModuloRule  *)arg);
            break;
        /** Dynamic configuration of PE channel config registers (argument type:  CSL_Aif2PeChannelConfig  *)  */   
        case CSL_AIF2_CMD_PE_CH_CONFIG_SETUP:
            CSL_aif2PeChConfigDynamicSetup (hAif2, *(CSL_Aif2PeChannelConfig  *)arg);
            break;
        /** Dynamic configuration of PE channel rule LUT config registers (argument type:  CSL_Aif2PeChRuleLut  *)  */   
        case CSL_AIF2_CMD_PE_CH_RULE_LUT_SETUP:
            CSL_aif2PeChRuleLutDynamicSetup (hAif2, *(CSL_Aif2PeChRuleLut  *)arg);
            break;
        /** Enables Trace data and framing data capture (use hAif2->arg_link to select link, argument type: Bool *) */ 
        case CSL_AIF2_CMD_ENABLE_DISABLE_LINK_DATA_CAPTURE:
            CSL_aif2EnRxLinkDataCapture(hAif2, *(Bool*)arg);
            break;
        /** Data Trace Sync Enable.  (argument type: Bool *) */
        case CSL_AIF2_CMD_ENABLE_DISABLE_DATA_TRACE_SYNC:
            CSL_aif2EnRxTraceDataSync(hAif2, *(Bool*)arg);
            break;
        /** Enables Ingress DB Debug mode (argument type: Bool *) */
        case CSL_AIF2_CMD_DB_IN_ENABLE_DISABLE_DEBUG_MODE:
            CSL_aif2InDbEnDisDebug(hAif2, *(Bool*)arg);
            break;
        /** Debug data written to bits 128:0 of Ingress DB RAM (argument type: Uint32 *) */
        case CSL_AIF2_CMD_DB_IN_DEBUG_DATA_SETUP:
            CSL_aif2InDbDebugDataSetup(hAif2, (Uint32*)arg);
            break;
        /** Ingress DB debug side band data setup (argument type: CSL_Aif2DbSideData *)  */
        case CSL_AIF2_CMD_DB_IN_DEBUG_SIDE_DATA_SETUP:
            CSL_aif2InDbDebugSideDataSetup(hAif2, *(CSL_Aif2DbSideData *)arg);
            break;
        /** Writes the data in the following registers into the Ingress DB and sideband RAMS
            DB_IDB_DEBUG_D0, DB_IDB_DEBUG_D1, DB_IDB_DEBUG_D2, DB_IDB_DEBUG_D3, DB_IDB_DEBUG_SBDN (argument type: Bool *)  */
        case CSL_AIF2_CMD_DB_IN_DEBUG_WRITE:
            CSL_aif2InDbDebugWrite(hAif2, *(Bool *)arg);
            break;
        /** Set Read and Write Address used to access write or read Offset RAM for DB Debug 
        (argument type: Uint8 * arg[0] : write offset addr  arg[1] : read offset addr)  */
        case CSL_AIF2_CMD_DB_IN_DEBUG_OFFSET_ADDR:
            CSL_aif2InDbDebugOffsetAddr(hAif2, (Uint8 *)arg);
            break;
        /** Enable or Disable Ingress DB channel to add or remove channel dynamically (argument type: Uint32 *)  */
        case CSL_AIF2_CMD_DB_IN_ENABLE_DISABLE_CHANNEL:
            CSL_aif2InDbChEnable(hAif2, (Uint32 *)arg);
            break;
        /** Setup Ingress DB channel to add or remove channel dynamically (argument type: CSL_Aif2DbChannel *)  */
        case CSL_AIF2_CMD_DB_IN_CHANNEL_SETUP:
            CSL_aif2InDbChannelSetup(hAif2, *(CSL_Aif2DbChannel *)arg);
            break;
        /** Enables Egress DB Debug mode (argument type: Bool *) */
        case CSL_AIF2_CMD_DB_E_ENABLE_DISABLE_DEBUG_MODE:
            CSL_aif2EDbEnDisDebug(hAif2, *(Bool*)arg);
            break;
        /** Setup Side band data control info like dio and fifo write enable and channel id and dio base address.(argument type: CSL_Aif2DbSideData *) */
        case CSL_AIF2_CMD_DB_E_DEBUG_READ_CONTROL:
            CSL_aif2EDbDebugReadControl(hAif2, *(CSL_Aif2DbSideData*)arg);
            break;
        /** the value loaded into DB_EDB_DEBUG_RD_CNTL.CH_ID being issued to the AxC Token FIFO.(argument type: Bool *) */
        case CSL_AIF2_CMD_DB_E_DEBUG_WRITE_TOKEN:
            CSL_aif2EDbDebugWrToken(hAif2, *(Bool *)arg);
            break;
        /** Reads the data in the following registers from the Egress DB and sideband RAMS
            DB_EDB_DEBUG_D0, DB_EDB_DEBUG_D1, DB_EDB_DEBUG_D2, DB_EDB_DEBUG_D3, DB_EDB_DEBUG_SBDN (argument type: Bool *)  */
        case CSL_AIF2_CMD_DB_E_DEBUG_READ:
            CSL_aif2EDbDebugRead(hAif2, *(Bool *)arg);
            break;
       	/** Set Read and Write Address used to access write or read Offset RAM for DB Debug 
       (argument type: Uint8 * arg[0] : write offset addr  arg[1] : read offset addr)  */
        case CSL_AIF2_CMD_DB_E_DEBUG_OFFSET_ADDR:
            CSL_aif2EDbDebugOffsetAddr(hAif2, (Uint8 *)arg);
            break;
       	/** Enable or Disable Egress DB channel to add or remove channel dynamically (argument type: Uint32 *)  */
        case CSL_AIF2_CMD_DB_E_ENABLE_DISABLE_CHANNEL:
            CSL_aif2EDbChEnable(hAif2, (Uint32 *)arg);
            break;
       	/** Setup Egress DB channel to add or remove channel dynamically (argument type: CSL_Aif2DbChannel *)  */
        case CSL_AIF2_CMD_DB_E_CHANNEL_SETUP:
            CSL_aif2EDbChannelSetup(hAif2, *(CSL_Aif2DbChannel *)arg);
            break;
       	/** Enable or Disable Global AD module dynamically (argument type: Bool *)  */
        case CSL_AIF2_CMD_AD_IN_ENABLE_DISABLE_GLOBAL:
            CSL_aif2AdInGlobalEnableDisable(hAif2, *(Bool *)arg);
            break;
        /** Enable or Disable Global AD module dynamically (argument type: Bool *)  */
        case CSL_AIF2_CMD_AD_E_ENABLE_DISABLE_GLOBAL:
            CSL_aif2AdEGlobalEnableDisable(hAif2, *(Bool *)arg);
            break;
        /** Enable or Disable Global Ingress DIO mode dynamically (argument type: Bool *)  */
        case CSL_AIF2_CMD_AD_IN_ENABLE_DISABLE_DIO_GLOBAL:
            CSL_aif2AdInDioGlobalEnableDisable(hAif2, *(Bool *)arg);
            break;
        /** Enable or Disable Global Egress DIO mode dynamically (argument type: Bool *)  */
        case CSL_AIF2_CMD_AD_E_ENABLE_DISABLE_DIO_GLOBAL:
            CSL_aif2AdEDioGlobalEnableDisable(hAif2, *(Bool *)arg);
            break;
       	/** Change Ingress DIO table selection dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_IN_DIO_TABLE_SELECT:
            CSL_aif2AdInDioTableSelect(hAif2, *(Uint8 *)arg);
            break;
       	/** Change Ingress DIO num of AxC dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_IN_DIO_NUM_AXC_CHANGE:
            CSL_aif2AdInDioNumAxC(hAif2, *(Uint8 *)arg);
            break;
       	/** Change Ingress DIO BCN table dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_IN_DIO_BCN_TABLE_CHANGE:
            CSL_aif2AdInDioBcnTableSetup(hAif2, (Uint8 *)arg);
            break;
       	/** Change Egress DIO table selection dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_E_DIO_TABLE_SELECT:
            CSL_aif2AdEDioTableSelect(hAif2, *(Uint8 *)arg);
            break;
       	/** Change Egress DIO num of AxC dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_E_DIO_NUM_AXC_CHANGE:
            CSL_aif2AdEDioNumAxC(hAif2, *(Uint8 *)arg);
            break;
       	/** Change Egress DIO BCN table dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
        case CSL_AIF2_CMD_AD_E_DIO_BCN_TABLE_CHANGE:
            CSL_aif2AdEDioBcnTableSetup(hAif2, (Uint8 *)arg);
            break;
       	/** Set Enable or disable Data trace DMA channel  (argument type: Bool *)  */
        case CSL_AIF2_CMD_AD_TRACE_DATA_DMA_CHANNEL_ON_OFF:
            CSL_aif2AdEnDisDtDmaCh(hAif2, *(Bool *)arg);
            CSL_aif2AdDataTraceBaseAddr(hAif2, *(Uint32 *)arg);
            break;
       	/** Set Trace data base address  (argument type: Uint32 *)  */
        case CSL_AIF2_CMD_AD_TRACE_DATA_BASE_ADDR:
            CSL_aif2AdDataTraceBaseAddr(hAif2, *(Uint32 *)arg);
            break;
       	/** Set Trace side data base address  (argument type: Uint32 *)  */
        case CSL_AIF2_CMD_AD_TRACE_FRAMING_DATA_BASE_ADDR:
            CSL_aif2AdFramingDataBaseAddr(hAif2, *(Uint32 *)arg);
            break;
        /** Sets the number of burst transfers before the destination address wraps back to the base address(argument type: Uint32 *)  */
        case CSL_AIF2_CMD_AD_TRACE_CPPI_DMA_BURST_WRAP:
            CSL_aif2AdDtDmaWrap(hAif2, *(Uint32 *)arg);
            break;
       	/** Sets AT External Rad timer event dynamically (argument type: CSL_Aif2AtEvent *)  */
        case CSL_AIF2_CMD_AT_EVENT_SETUP:
            CSL_aif2AtEventSetup(hAif2, *(CSL_Aif2AtEvent  *)arg);
            break;
       	/** Sets AT Delta offset  (use hAif2->arg_link to select link   argument type: CSL_Aif2AtEvent *)  */
        case CSL_AIF2_CMD_AT_DELTA_SETUP:
            CSL_aif2AtDeltaSetup(hAif2, *(Uint32  *)arg);
            break;
       	/** Sets AT Halt  timer  (argument type:  Bool  *)  */
        case CSL_AIF2_CMD_AT_HALT_TIMER:
            CSL_aif2AtHaltTimer(hAif2, *(Bool  *)arg);
            break;
       	/** Sets AT diable all events for debug purpose (argument type:  Bool  *)  */
        case CSL_AIF2_CMD_AT_DISABLE_ALL_EVENTS:
            CSL_aif2AtDisableAllEvents(hAif2, *(Bool  *)arg);
            break;
        /** Sets AT Arm timer  (argument type:  Bool  *)  */
        case CSL_AIF2_CMD_AT_ARM_TIMER:
            CSL_aif2AtArmTimer(hAif2, *(Bool  *)arg);
            break;
       	/** Sets AT Phy debug sync  (argument type:  Bool  *)  */
        case CSL_AIF2_CMD_AT_DEBUG_SYNC:
            CSL_aif2AtSwDebugSync(hAif2, *(Bool  *)arg);
            break;
        /** Sets AT radt wcdma clock divider terminal count  (argument type:  Uint8  *)  */
        case CSL_AIF2_CMD_AT_RAD_WCDMA_DIV:
            CSL_aif2AtRadWcdmaDiv(hAif2, *(Uint8  *)arg);
            break;
        /** Sets AT Rad terminal count  (argument type:  CSL_Aif2AtTcObj  *)  */
        case CSL_AIF2_CMD_AT_RAD_TC_SETUP:
            CSL_aif2AtRadTcSetup(hAif2, *(CSL_Aif2AtTcObj  *)arg);
            break;
        /** Sets AT GSM Tcount  (argument type:  CSL_Aif2AtGsmTCount  *)  */
        case CSL_AIF2_CMD_AT_GSM_TCOUNT_SETUP:
            CSL_aif2AtGsmTcountSetup(hAif2, *(CSL_Aif2AtGsmTCount  *)arg);
            break;
        /** Enable Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
        case CSL_AIF2_CMD_AT_ENABLE_EVENT:
            CSL_aif2AtEnableEvent(hAif2, *(CSL_Aif2AtEventIndex  *)arg);
            break;
        /** Disable Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
        case CSL_AIF2_CMD_AT_DISABLE_EVENT:
            CSL_aif2AtDisableEvent(hAif2, *(CSL_Aif2AtEventIndex  *)arg);
            break;
        /** Force set Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
        case CSL_AIF2_CMD_AT_FORCE_EVENT:
            CSL_aif2AtForceEvent(hAif2, *(CSL_Aif2AtEventIndex  *)arg);
            break;
        /** EE End of interrupt vector value setup  (argument type:  Uint8  *)  */
        case CSL_AIF2_CMD_EE_EOI_SETUP:
            CSL_aif2EeEoiSetup(hAif2, *(Uint8  *)arg);
            break;
        /** EE VB error interrupt set or clear (use hAif2->ee_arg to select between set and clear   argument type:  CSL_Aif2EeAif2Int  *)  */
        case CSL_AIF2_CMD_EE_AIF2_ERROR_INT:
            CSL_aif2EeAif2ErrorIntSetup(hAif2, *(CSL_Aif2EeAif2Int  *)arg);
            break;
        /** EE DB interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeDbInt  *)  */
        case CSL_AIF2_CMD_EE_DB_INT:
            CSL_aif2EeDbIntSetup(hAif2, *(CSL_Aif2EeDbInt  *)arg);
            break;
        /** EE AD interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeAdInt  *)  */
        case CSL_AIF2_CMD_EE_AD_INT:
            CSL_aif2EeAdIntSetup(hAif2, *(CSL_Aif2EeAdInt  *)arg);
            break;
        /** EE CD(PKTDMA) interrupt set, clear, enable set or clear for EV0  (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeCdInt  *)  */
        case CSL_AIF2_CMD_EE_CD_INT:
            CSL_aif2EeCdIntSetup(hAif2, *(CSL_Aif2EeCdInt  *)arg);
            break;
        /** EE SD interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeSdInt  *)  */
        case CSL_AIF2_CMD_EE_SD_INT:
            CSL_aif2EeSdIntSetup(hAif2, *(CSL_Aif2EeSdInt  *)arg);
            break;
        /** EE VC interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeVcInt  *)  */
        case CSL_AIF2_CMD_EE_VC_INT:
            CSL_aif2EeVcIntSetup(hAif2, *(CSL_Aif2EeVcInt  *)arg);
            break;
        /** EE Aif2 run control register setup (argument type:  CSL_Aif2EeAif2Run  *)  */
        case CSL_AIF2_CMD_EE_AIF2_RUN:
            CSL_aif2EeAif2RunSetup(hAif2, *(CSL_Aif2EeAif2Run  *)arg);
            break;
        /** EE Link A interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function  and hAif2->arg_link to select link argument type:  CSL_Aif2EeLinkAInt  *)  */
        case CSL_AIF2_CMD_EE_LINKA_INT:
            CSL_aif2EeLinkAIntSetup(hAif2, *(CSL_Aif2EeLinkAInt  *)arg);
            break;
        /** EE Link B interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function  and hAif2->arg_link to select link argument type:  CSL_Aif2EeLinkBInt  *)  */
        case CSL_AIF2_CMD_EE_LINKB_INT:
            CSL_aif2EeLinkBIntSetup(hAif2, *(CSL_Aif2EeLinkBInt  *)arg);
            break;
        /** EE AT interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeAtInt  *)  */
        case CSL_AIF2_CMD_EE_AT_INT:
            CSL_aif2EeAtIntSetup(hAif2, *(CSL_Aif2EeAtInt  *)arg);
            break;
        /** EE PD common interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EePdInt  *)  */
        case CSL_AIF2_CMD_EE_PD_INT:
            CSL_aif2EePdIntSetup(hAif2, *(CSL_Aif2EePdInt  *)arg);
            break;
        /** EE PE common interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EePeInt  *)  */
        case CSL_AIF2_CMD_EE_PE_INT:
            CSL_aif2EePeIntSetup(hAif2, *(CSL_Aif2EePeInt  *)arg);
            break;
        default:
        status = CSL_ESYS_INVCMD;
            break;
        }
    }
    return status;
}

