/*
*  Copyright (C) 2017 Arasan Chip Systems Inc
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
 *    Neither the name of Arasan Chip Systems Incorporated nor the names of
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
/*********************************************************************
*  
*  Name             : mmcsdphy.c
*  Creation Date : Aug 28, 2017
*  Description     : This file contains functions to read / write the host controller
*                          phy registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  28-Aug-2017    PB              0.1                 File structure creation
*  01-Sept-2017   PB		   1.0		   Added Phy layer function definitions
*
*********************************************************************/
/**
 *  \file mmcsdphy.c
 *
 *  \brief File with mmc sd phy register read/write functions
 *
**/

/*   Includes    */

#include <ti/csl/src/ip/mmc/V3/mmcsdphy.h>
#include <ti/csl/src/ip/mmc/V3/priv/low_level_hw.h>
#include <ti/csl/src/ip/mmc/V3/mmcsd.h>

/*    Globals    */



/*    Function Definitions    */

static int32_t HSMMCSDPhyValidateBaseAddress(uintptr_t baseAddr)
{
	int32_t status = STW_SOK;

	/* TODO: Modify conditional check here as per requirement for validation of base address*/
	if(0x0U == baseAddr)
	{
		status = STW_EOUT_OF_RANGE;
	}

	return status;
}


static int32_t SdhcPhyRegisterWrite(uintptr_t baseAddr, uint32_t regOffset, uint32_t value)
{
	int32_t status = STW_SOK;
    SdhcRegisterWriteDWord(baseAddr + regOffset,value);
	return status;
}


static int32_t SdhcPhyRegisterRead(uintptr_t baseAddr, uint32_t regOffset, uint32_t *value)
{
	int32_t status = STW_SOK;
	*value = SdhcRegisterReadDWord(baseAddr + regOffset);
	return status;
}

int32_t HSMMCSDPhyDisableDLL (uintptr_t baseAddr)
{
	int32_t status=STW_SOK;   
   	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
       /* Disable DLL */
       SdhcRegisterWriteFieldDWord(baseAddr + MMC_PHY_CTRL1_REG_OFFSET,MMC_PHY_CTRL1_ENDLL_MASK,MMC_PHY_CTRL1_ENDLL_SHIFT,MMC_PHY_CTRL1_ENDLL_DISABLE);
    }	
    return status;
}

int32_t HSMMCSDPhyConfigure(uintptr_t baseAddr, uint32_t mode, uint32_t clock, uint32_t driverType)
{
	int32_t status=STW_SOK;
	uint32_t dllrdy=0;
	uint32_t sel50=0,sel100=0,strbsel=0,regValue;

	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
      regValue = 0U;
      status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, &regValue);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_OTAPDLYENA_SHIFT,
		MMC_PHY_CTRL4_OTAPDLYENA_MASK, MMC_PHY_CTRL4_OTAPDLYENA_ENABLED);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_OTAPDLYSEL_SHIFT,
						MMC_PHY_CTRL4_OTAPDLYSEL_MASK, PHY_OTAPDLY_CTRL_SEL_2);
      regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_STRBSEL_SHIFT,
						MMC_PHY_CTRL4_STRBSEL_MASK, strbsel);


	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, regValue);

           
         /* Configure sel50/sel100 */
         if(clock == 200000000)
         {
			 sel50=0;
			 sel100=0;
         } else if(clock == 100000000)
		 {
			 sel50=0;
			 sel100=1;
         }		 
		 else if ( (clock == 50000000) || (clock == 52000000) )
		 {
			 sel50=1;
			 sel100=0;
		 } else {
			 /* Default 50Mhz */
			 sel50=1;
			 sel100=0;
		 }
	  /* Select the DLL frequency for high speed modes */
      status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL5_REG_OFFSET, &regValue);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL5_SEL100_SHIFT,
		MMC_PHY_CTRL5_SEL100_MASK, sel100);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL5_SEL50_SHIFT,
		MMC_PHY_CTRL5_SEL50_MASK, sel50);
 	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL5_REG_OFFSET, regValue);


	  /*Configure DLL Trim PHY_DLL_TRIM */
	  status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);

	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_DLL_TRIM_ICP_SHIFT,
				MMC_PHY_CTRL1_DLL_TRIM_ICP_MASK, PHY_DLL_TRIM_ICP_8);
	            
	   /* Set the impedance val/driver strength */
	   regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_DR_TY_SHIFT,
					MMC_PHY_CTRL1_DR_TY_MASK, driverType);

      /* Enable DLL */
      regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_ENDLL_SHIFT,
					MMC_PHY_CTRL1_ENDLL_MASK, MMC_PHY_CTRL1_ENDLL_ENABLE);
	      
	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);

	  /* Wait until dllrdy bit is set to 1 in the Phy Status (0x30) register */
	  do {
		dllrdy = SdhcRegisterReadFieldDWord(baseAddr + MMC_PHY_STS_1_REG_OFFSET ,MMC_PHY_STS_1_DLLRDY_MASK,MMC_PHY_STS_1_DLLRDY_SHIFT);
	  } while(dllrdy!=PHY_DLL_CTRL_STS_DLL_RDY_TRUE);
    }
	return status;
}

int32_t HSMMCSDPhyLDOSet(uintptr_t baseAddr, uint32_t state)
{
	int32_t status=STW_SOK;
	return status;
}


int32_t HSMMCSDPhyInit(uintptr_t baseAddr)
{
	int32_t status=STW_SOK;
	return status;
}
