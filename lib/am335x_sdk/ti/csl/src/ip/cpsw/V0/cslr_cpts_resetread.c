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

#include <ti/csl/cslr_cpts.h>

CSL_CptsRegs CSL_Cpts_ResetVals;


/* for misra warnings */
void *Cpts_Reset_Val_Read(void);
void *Cpts_Reset_Val_Read(void)
{
    CSL_Cpts_ResetVals.IDVER_REG = CSL_CPTS_IDVER_REG_RESETVAL;
    CSL_Cpts_ResetVals.CONTROL_REG = CSL_CPTS_CONTROL_REG_RESETVAL;
    CSL_Cpts_ResetVals.RFTCLK_SEL_REG = CSL_CPTS_RFTCLK_SEL_REG_RESETVAL;
    CSL_Cpts_ResetVals.TS_PUSH_REG = CSL_CPTS_TS_PUSH_REG_RESETVAL;
    CSL_Cpts_ResetVals.TS_LOAD_VAL_REG = CSL_CPTS_TS_LOAD_VAL_REG_RESETVAL;
    CSL_Cpts_ResetVals.TS_LOAD_EN_REG = CSL_CPTS_TS_LOAD_EN_REG_RESETVAL;
    CSL_Cpts_ResetVals.TS_COMP_VAL_REG = CSL_CPTS_TS_COMP_VAL_REG_RESETVAL;
    CSL_Cpts_ResetVals.TS_COMP_LEN_REG = CSL_CPTS_TS_COMP_LEN_REG_RESETVAL;
    CSL_Cpts_ResetVals.INTSTAT_RAW_REG = CSL_CPTS_INTSTAT_RAW_REG_RESETVAL;
    CSL_Cpts_ResetVals.INTSTAT_MASKED_REG = CSL_CPTS_INTSTAT_MASKED_REG_RESETVAL;
    CSL_Cpts_ResetVals.EVENT_POP_REG = CSL_CPTS_EVENT_POP_REG_RESETVAL;
    CSL_Cpts_ResetVals.EVENT_LOW_REG = CSL_CPTS_EVENT_LOW_REG_RESETVAL;
    CSL_Cpts_ResetVals.EVENT_MIDDLE_REG = CSL_CPTS_EVENT_MIDDLE_REG_RESETVAL;
    CSL_Cpts_ResetVals.EVENT_HIGH_REG = CSL_CPTS_EVENT_HIGH_REG_RESETVAL;
    CSL_Cpts_ResetVals.INT_ENABLE_REG = CSL_CPTS_INT_ENABLE_REG_RESETVAL;
    return ((void *)&CSL_Cpts_ResetVals);
}
