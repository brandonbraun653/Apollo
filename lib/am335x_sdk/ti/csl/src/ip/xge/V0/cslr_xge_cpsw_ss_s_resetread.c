/********************************************************************
 * Copyright (C) 2003-2012 Texas Instruments Incorporated.
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
*********************************************************************/

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Header files are included as per RTSC guidelines
 */

#include <ti/csl/cslr_xge_cpsw_ss_s.h>

CSL_Xge_cpsw_ss_sRegs CSL_Xge_cpsw_ss_s_ResetVals;


/* for misra warnings */
void *Xge_cpsw_ss_s_Reset_Val_Read(void);
void *Xge_cpsw_ss_s_Reset_Val_Read(void)
{
    CSL_Xge_cpsw_ss_s_ResetVals.IDVER_REG = CSL_XGE_CPSW_SS_S_IDVER_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.SYNCE_COUNT_REG = CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.SYNCE_MUX_REG = CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.CONTROL_REG = CSL_XGE_CPSW_SS_S_CONTROL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].TX_CTL_REG = CSL_XGE_CPSW_SS_S_TX_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].TX_STATUS_REG = CSL_XGE_CPSW_SS_S_TX_STATUS_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].RX_CTL_REG = CSL_XGE_CPSW_SS_S_RX_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].RX_STATUS_REG = CSL_XGE_CPSW_SS_S_RX_STATUS_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].SEED_A_LO_REG = CSL_XGE_CPSW_SS_S_SEED_A_LO_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].SEED_A_HI_REG = CSL_XGE_CPSW_SS_S_SEED_A_HI_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].SEED_B_LO_REG = CSL_XGE_CPSW_SS_S_SEED_B_LO_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].SEED_B_HI_REG = CSL_XGE_CPSW_SS_S_SEED_B_HI_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].FEC_REG = CSL_XGE_CPSW_SS_S_FEC_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].CTL_REG = CSL_XGE_CPSW_SS_S_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].FEC_CNT_REG = CSL_XGE_CPSW_SS_S_FEC_CNT_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[0].ERR_FIFO_REG = CSL_XGE_CPSW_SS_S_ERR_FIFO_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].TX_CTL_REG = CSL_XGE_CPSW_SS_S_TX_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].TX_STATUS_REG = CSL_XGE_CPSW_SS_S_TX_STATUS_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].RX_CTL_REG = CSL_XGE_CPSW_SS_S_RX_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].RX_STATUS_REG = CSL_XGE_CPSW_SS_S_RX_STATUS_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].SEED_A_LO_REG = CSL_XGE_CPSW_SS_S_SEED_A_LO_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].SEED_A_HI_REG = CSL_XGE_CPSW_SS_S_SEED_A_HI_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].SEED_B_LO_REG = CSL_XGE_CPSW_SS_S_SEED_B_LO_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].SEED_B_HI_REG = CSL_XGE_CPSW_SS_S_SEED_B_HI_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].FEC_REG = CSL_XGE_CPSW_SS_S_FEC_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].CTL_REG = CSL_XGE_CPSW_SS_S_CTL_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].FEC_CNT_REG = CSL_XGE_CPSW_SS_S_FEC_CNT_REG_RESETVAL;
    CSL_Xge_cpsw_ss_s_ResetVals.PCSR[1].ERR_FIFO_REG = CSL_XGE_CPSW_SS_S_ERR_FIFO_REG_RESETVAL;
    return ((void *)&CSL_Xge_cpsw_ss_s_ResetVals);
}
