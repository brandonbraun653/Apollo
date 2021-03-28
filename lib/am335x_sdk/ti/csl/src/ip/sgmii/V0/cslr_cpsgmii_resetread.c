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

#include <ti/csl/cslr_cpsgmii.h>

CSL_CpsgmiiRegs CSL_Cpsgmii_ResetVals;


/* for misra warnings */
void *Cpsgmii_Reset_Val_Read(void);
void *Cpsgmii_Reset_Val_Read(void)
{
    CSL_Cpsgmii_ResetVals.IDVER_REG = CSL_CPSGMII_IDVER_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.SOFT_RESET_REG = CSL_CPSGMII_SOFT_RESET_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.CONTROL_REG = CSL_CPSGMII_CONTROL_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.STATUS_REG = CSL_CPSGMII_STATUS_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.MR_ADV_ABILITY_REG = CSL_CPSGMII_MR_ADV_ABILITY_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.MR_NP_TX_REG = CSL_CPSGMII_MR_NP_TX_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.MR_LP_ADV_ABILITY_REG = CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.MR_LP_NP_RX_REG = CSL_CPSGMII_MR_LP_NP_RX_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.TX_CFG_REG = CSL_CPSGMII_TX_CFG_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.RX_CFG_REG = CSL_CPSGMII_RX_CFG_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.AUX_CFG_REG = CSL_CPSGMII_AUX_CFG_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.DIAG_CLEAR_REG = CSL_CPSGMII_DIAG_CLEAR_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.DIAG_CONTROL_REG = CSL_CPSGMII_DIAG_CONTROL_REG_RESETVAL;
    CSL_Cpsgmii_ResetVals.DIAG_STATUS_REG = CSL_CPSGMII_DIAG_STATUS_REG_RESETVAL;
    return ((void *)&CSL_Cpsgmii_ResetVals);
}
