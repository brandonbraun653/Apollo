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

#include <ti/csl/cslr_xge_cpxmac_sl.h>

CSL_Xge_cpxmac_slRegs CSL_Xge_cpxmac_sl_ResetVals;

/* for misra warnings */
void *Xge_cpxmac_sl_Reset_Val_Read(void);
void *Xge_cpxmac_sl_Reset_Val_Read(void)
{
    CSL_Xge_cpxmac_sl_ResetVals.IDVER_REG = CSL_XGE_CPXMAC_SL_IDVER_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.MACCONTROL_REG = CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.MACSTATUS_REG = CSL_XGE_CPXMAC_SL_MACSTATUS_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.SOFT_RESET_REG = CSL_XGE_CPXMAC_SL_SOFT_RESET_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.RX_MAXLEN_REG = CSL_XGE_CPXMAC_SL_RX_MAXLEN_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.BOFFTEST_REG = CSL_XGE_CPXMAC_SL_BOFFTEST_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.RX_PAUSE_REG = CSL_XGE_CPXMAC_SL_RX_PAUSE_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.TX_PAUSE_REG = CSL_XGE_CPXMAC_SL_TX_PAUSE_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.EMCONTROL_REG = CSL_XGE_CPXMAC_SL_EMCONTROL_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.PRI_MAP_REG = CSL_XGE_CPXMAC_SL_PRI_MAP_REG_RESETVAL;
    CSL_Xge_cpxmac_sl_ResetVals.TX_GAP_REG = CSL_XGE_CPXMAC_SL_TX_GAP_REG_RESETVAL;
    return ((void *)&CSL_Xge_cpxmac_sl_ResetVals);
}
