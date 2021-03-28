/********************************************************************
 * Copyright (C) 2003-2011 Texas Instruments Incorporated.
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

#include "cslr_usimocp.h"
CSL_UsimocpRegs CSL_Usimocp_ResetVals;


/* for misra warnings */
void *Usimocp_Reset_Val_Read(void);
void *Usimocp_Reset_Val_Read(void)
{
    CSL_Usimocp_ResetVals.__ALL__.REVISION = CSL_USIMOCP_REVISION_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.IDENT = CSL_USIMOCP_IDENT_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.SYSCONFIG = CSL_USIMOCP_SYSCONFIG_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.SYSSTATUS = CSL_USIMOCP_SYSSTATUS_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.IRQSTATUS = CSL_USIMOCP_IRQSTATUS_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.IRQENABLE = CSL_USIMOCP_IRQENABLE_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.WAKEUPEN = CSL_USIMOCP_WAKEUPEN_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIMCMD = CSL_USIMOCP_USIMCMD_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIMSTAT = CSL_USIMOCP_USIMSTAT_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIMCONF1 = CSL_USIMOCP_USIMCONF1_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIMCONF2 = CSL_USIMOCP_USIMCONF2_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIMCONF3 = CSL_USIMOCP_USIMCONF3_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_DRX = CSL_USIMOCP_USIM_DRX_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_DTX = CSL_USIMOCP_USIM_DTX_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_FIFOS = CSL_USIMOCP_USIM_FIFOS_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_CGT = CSL_USIMOCP_USIM_CGT_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_CWT = CSL_USIMOCP_USIM_CWT_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_BWT = CSL_USIMOCP_USIM_BWT_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.DEBUG_REG = CSL_USIMOCP_DEBUG_REG_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.CONF_SAM1_DIV = CSL_USIMOCP_CONF_SAM1_DIV_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.CONF4_REG = CSL_USIMOCP_CONF4_REG_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.ATR_CLK_PRD_NBS = CSL_USIMOCP_ATR_CLK_PRD_NBS_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.CONF_ETU_DIV = CSL_USIMOCP_CONF_ETU_DIV_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.CONF5_REG = CSL_USIMOCP_CONF5_REG_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.TC_GUARD_TIME_ADD = CSL_USIMOCP_TC_GUARD_TIME_ADD_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_RXFIFO_LEVEL = CSL_USIMOCP_USIM_RXFIFO_LEVEL_RESETVAL;
    CSL_Usimocp_ResetVals.__ALL__.USIM_RXFIFO_BYTECNT = CSL_USIMOCP_USIM_RXFIFO_BYTECNT_RESETVAL;
    return ((void *)&CSL_Usimocp_ResetVals);
}
