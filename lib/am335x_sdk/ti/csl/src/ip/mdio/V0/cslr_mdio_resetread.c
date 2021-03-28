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

#include <ti/csl/cslr_mdio.h>

CSL_MdioRegs CSL_Mdio_ResetVals;


/* for misra warnings */
void *Mdio_Reset_Val_Read(void);
void *Mdio_Reset_Val_Read(void)
{
    CSL_Mdio_ResetVals.VERSION_REG = CSL_MDIO_VERSION_REG_RESETVAL;
    CSL_Mdio_ResetVals.CONTROL_REG = CSL_MDIO_CONTROL_REG_RESETVAL;
    CSL_Mdio_ResetVals.ALIVE_REG = CSL_MDIO_ALIVE_REG_RESETVAL;
    CSL_Mdio_ResetVals.LINK_REG = CSL_MDIO_LINK_REG_RESETVAL;
    CSL_Mdio_ResetVals.LINK_INT_RAW_REG = CSL_MDIO_LINK_INT_RAW_REG_RESETVAL;
    CSL_Mdio_ResetVals.LINK_INT_MASKED_REG = CSL_MDIO_LINK_INT_MASKED_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_INT_RAW_REG = CSL_MDIO_USER_INT_RAW_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_INT_MASKED_REG = CSL_MDIO_USER_INT_MASKED_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_INT_MASK_SET_REG = CSL_MDIO_USER_INT_MASK_SET_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_INT_MASK_CLEAR_REG = CSL_MDIO_USER_INT_MASK_CLEAR_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_GROUP[0].USER_ACCESS_REG = CSL_MDIO_USER_ACCESS_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_GROUP[0].USER_PHY_SEL_REG = CSL_MDIO_USER_PHY_SEL_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_GROUP[1].USER_ACCESS_REG = CSL_MDIO_USER_ACCESS_REG_RESETVAL;
    CSL_Mdio_ResetVals.USER_GROUP[1].USER_PHY_SEL_REG = CSL_MDIO_USER_PHY_SEL_REG_RESETVAL;
    return ((void *)&CSL_Mdio_ResetVals);
}
