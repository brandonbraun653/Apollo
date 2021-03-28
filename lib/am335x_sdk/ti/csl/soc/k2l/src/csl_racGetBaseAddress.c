/**
 *   @file  csl_rac2GetBaseAddress.c
 *
 *   @brief   
 *      The file contains routines which are RAC2 Device specific
 *      and need to be modified for each new device which has the 
 *      RAC2 IP module. 
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002-2013 Texas Instruments, Inc.
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
#include <ti/csl/soc.h>
#include <ti/csl/csl_rac.h>

/** ============================================================================
 *   @n@b CSL_RAC_getBaseAddr
 *
 *   @b Description
 *   @n  This function is used for getting the base-address of the peripheral
 *       instance. This function will be called inside the @ CSL_RAC_open () 
 *       function call. 
 *
 *       Note: This function is open for re-implementing if the user wants to 
 *       modify the base address of the peripheral object to point to a 
 *       different location and there by allow CSL initiated write/reads into 
 *       peripheral MMR's go to an alternate location.
 *
 *   @b Arguments
 *   @verbatim      
            racNum          Specifies the instance of the RAC2 peripheral to be opened.
            pBaseAddress    Pointer to baseaddress structure containing base 
                            address details.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Success - CSL_SOK
 *   @n Error   - CSL_ESYS_FAIL (RAC2 Instance is invalid)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Base Address structure is populated
 *
 *   @b Affects
 *   @n None.
 *
 *   @b Example
 *   @verbatim
        CSL_Status                  status;
        CSL_RAC_BaseAddress         baseAddress;

        // Get the RAC Instance A Information 
        status = CSL_RAC_getBaseAddr (0, &baseAddress);

    @endverbatim
 * ===========================================================================
 */
CSL_Status CSL_RAC_getBaseAddr 
(
    CSL_InstNum                     racNum,
    CSL_RAC_BaseAddress*            pBaseAddress
)
{
    CSL_Status                      status = CSL_SOK;

    if (pBaseAddress == NULL) {
        status = CSL_ESYS_INVPARAMS;
	}
    else {
        switch (racNum) {
#ifdef CSL_RAC_0
            case CSL_RAC_0:
            {
                /* Instance A: Populate the Base Address... */
                pBaseAddress->cfgRegs       =   (CSL_Rac2CfgRegsOvly) CSL_RAC_0_FEI_CFG_REGS;
                pBaseAddress->gccpCfgRegs   =   (CSL_Gccp2CfgRegsOvly) CSL_RAC_0_GCCP0_CFG_REGS;
                pBaseAddress->dataRegs      =   (CSL_Rac2DataRegsOvly) CSL_RAC_FEI_RAC_0_DATA_REGS;

                break;
            }
#endif /* CSL_RAC_0 */
#ifdef CSL_RAC_1
            case CSL_RAC_1:
            {
                /* Instance B: Populate the Base Address... */
                pBaseAddress->cfgRegs       =   (CSL_Rac2CfgRegsOvly) CSL_RAC_1_FEI_CFG_REGS;
                pBaseAddress->gccpCfgRegs   =   (CSL_Gccp2CfgRegsOvly) CSL_RAC_1_GCCP0_CFG_REGS;
                pBaseAddress->dataRegs      =   (CSL_Rac2DataRegsOvly) CSL_RAC_FEI_RAC_0_DATA_REGS;

                break;
            }
#endif /* CSL_RAC_1 */
#ifdef CSL_RAC_2
            case CSL_RAC_2:
            {
                /* Instance C: Populate the Base Address... */
                pBaseAddress->cfgRegs       =   (CSL_Rac2CfgRegsOvly) CSL_RAC_2_FEI_CFG_REGS;
                pBaseAddress->gccpCfgRegs   =   (CSL_Gccp2CfgRegsOvly) CSL_RAC_2_GCCP0_CFG_REGS;
                pBaseAddress->dataRegs      =   (CSL_Rac2DataRegsOvly) CSL_RAC_FEI_RAC_0_DATA_REGS;

                break;
            }
#endif /* CSL_RAC_2 */
#ifdef CSL_RAC_3
            case CSL_RAC_3:
            {
                /* Instance D: Populate the Base Address... */
                pBaseAddress->cfgRegs       =   (CSL_Rac2CfgRegsOvly) CSL_RAC_3_FEI_CFG_REGS;
                pBaseAddress->gccpCfgRegs   =   (CSL_Gccp2CfgRegsOvly) CSL_RAC_3_GCCP0_CFG_REGS;
                pBaseAddress->dataRegs      =   (CSL_Rac2DataRegsOvly) CSL_RAC_FEI_RAC_0_DATA_REGS;

                break;
            }
#endif /* CSL_RAC_3 */
            default:
            {
                /* Invalid RAC2 Instance Number. Return error */
                pBaseAddress->cfgRegs       =   (CSL_Rac2CfgRegsOvly) NULL;
                pBaseAddress->gccpCfgRegs   =   (CSL_Gccp2CfgRegsOvly) NULL;
                pBaseAddress->dataRegs      =   (CSL_Rac2DataRegsOvly) NULL;

                status = CSL_ESYS_FAIL;

                break;
            }
        }
    }
    return (status);
}

