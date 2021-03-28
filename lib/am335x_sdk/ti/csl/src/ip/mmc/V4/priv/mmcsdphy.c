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
*  Creation Date : May 12, 2019
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

#include <ti/csl/src/ip/mmc/V4/mmcsdphy.h>
#include <ti/csl/src/ip/mmc/V4/priv/low_level_hw.h>
#include <ti/csl/src/ip/mmc/V4/mmcsd.h>

/*    Globals    */



/*    Function Definitions    */

static int32_t HSMMCSDPhyValidateBaseAddress(uintptr_t baseAddr)
{
	int32_t status = STW_SOK;

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

int32_t HSMMCSDPhyInit (uintptr_t baseAddr)
{
	int32_t status=STW_SOK;
	uint32_t en_rtrim=0,cal_done=0,regValue;
	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{

	  /* Configure PHY_CONTROL_1_REG: DLL Trim PHY_DLL_TRIM */
	  status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);

	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_DLL_TRIM_ICP_SHIFT,
				MMC_PHY_CTRL1_DLL_TRIM_ICP_MASK, PHY_DLL_TRIM_ICP_8);

	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);

	  /* Configure PHY_CONTROL_2_REG: to reset value 0*/
	  SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL2_REG_OFFSET, 0);
	  /*Configure PHY_CONTROL_2_REG */


	  /*Configure PHY_CONTROL_3_REG */
	  SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL3_REG_OFFSET, 0x10FF10FF);

      /**************************** Do the calibration if not done **********************************/
      /* Check the CALDONE bit */
	/* Enable the calibration sequence */
	  status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_EN_RTRIM_SHIFT,
				MMC_PHY_CTRL1_EN_RTRIM_MASK, 1);
	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);

		/* Wait for EN_RTRIM bit to be set */
	   do {
		 en_rtrim = SdhcRegisterReadFieldDWord(baseAddr + MMC_PHY_CTRL1_REG_OFFSET ,MMC_PHY_CTRL1_EN_RTRIM_MASK,MMC_PHY_CTRL1_EN_RTRIM_SHIFT);
	   } while(en_rtrim!=1);

		/* Set PDB to rigger calibration */
	  status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_PDB_SHIFT,
				MMC_PHY_CTRL1_PDB_MASK, MMC_PHY_CTRL1_PDB_ENABLE);
	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);

	   do {
		 cal_done = SdhcRegisterReadFieldDWord(baseAddr + MMC_PHY_STS_1_REG_OFFSET ,MMC_PHY_STS_1_CALDONE_MASK,MMC_PHY_STS_1_CALDONE_SHIFT);
	  } while(cal_done!=1);

    }
    return status;
}

/* Returns the PHY otap delay select and otap delay value according to the modes */
void HSMMCSDPhy_get_otap(uint32_t *otapdelaysel_ptr, uint32_t *otapdelayval_ptr,uint32_t mode)
{
	uint32_t otapdelaysel=0, otapdelayval=0;
	switch(mode) {
		case MODE_DS:
		case MODE_HS:
		    otapdelaysel=0;
			otapdelayval=0;
			break;
	    case MODE_SDR50:
	    case MODE_HSSDR50:
		    otapdelaysel=1;
	        otapdelayval=8;
	        break;
	    case MODE_HS200:
	    case MODE_SDR104:
		    otapdelaysel=1;
	        otapdelayval=6;
	        break;
	    case MODE_DDR50:
		    otapdelaysel=1;
	        otapdelayval=5;
	        break;
	    case MODE_HS400:
		    otapdelaysel=1;
	        otapdelayval=2;
	        break;
        default:
            break;
	}

	*otapdelaysel_ptr = otapdelaysel;
	*otapdelayval_ptr = otapdelayval;

}

/* Returns the 'soft' PHY otap delay select and otap delay value according to the modes */
void HSMMCSDSoftPhy_get_otap(uint32_t *otapdelaysel_ptr, uint32_t *otapdelayval_ptr,uint32_t mode)
{
	uint32_t otapdelaysel=0, otapdelayval=0;
	switch(mode) {
		case MODE_DS:
		case MODE_HS:
		    otapdelaysel=0;
			otapdelayval=0;
			break;
	    case MODE_SDR12:
	    case MODE_SDR25:
		    otapdelaysel=1;
			otapdelayval=5;
	    case MODE_SDR50:
	    case MODE_HSSDR50:
		    otapdelaysel=1;
	        otapdelayval=12;
           break;
	    case MODE_HS200:
	    case MODE_SDR104:
		    otapdelaysel=1;
	        otapdelayval=5;
	        break;
	    case MODE_DDR50:
		    otapdelaysel=1;
	        otapdelayval=12;
	        break;
	    case MODE_HS400:
		    otapdelaysel=1;
	        otapdelayval=0;
	        break;
        default:
            break;
	}


	*otapdelaysel_ptr = otapdelaysel;
	*otapdelayval_ptr = otapdelayval;


}

/* Initializes the 'soft' PHY  */
int32_t HSMMCSDSoftPhyInit (uintptr_t baseAddr)
{
	int32_t status=STW_SOK;
    uint32_t regValue;
	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
    /* Nothing to be done for soft phy */
	if(STW_SOK == status)
	{
        status = SdhcPhyRegisterRead(baseAddr, MMC_SOFT_PHY_CTRL4_REG_OFFSET, &regValue);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL4_OTAPDLYENA_SHIFT,
		MMC_SOFT_PHY_CTRL4_OTAPDLYENA_MASK, MMC_SOFT_PHY_CTRL4_OTAPDLYENA_ENABLED);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_SHIFT,
						MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_MASK,2);
        status = SdhcPhyRegisterWrite(baseAddr, MMC_SOFT_PHY_CTRL4_REG_OFFSET, regValue);

	}
    return status;
}

/* Configures the PHY according to the mode */
int32_t HSMMCSDPhyConfigure(uintptr_t baseAddr, uint32_t mode, uint32_t clock, uint32_t driverType)
{
	int32_t status=STW_SOK;
	uint32_t dllrdy=0;
	uint32_t frqsel=0,strbsel=0,regValue;
	uint32_t otapdelaysel=0,otapdelayval=0;

	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{

      if(mode==MODE_HS400) {
		  strbsel=0x77;
	  }


      regValue = 0U;
      status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, &regValue);
      regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_STRBSEL_SHIFT,
						MMC_PHY_CTRL4_STRBSEL_MASK, strbsel);
	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, regValue);

      /* Disable DLL */
      status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);
      regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_ENDLL_SHIFT,
					MMC_PHY_CTRL1_ENDLL_MASK, MMC_PHY_CTRL1_ENDLL_DISABLE);
	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);

         /* Configure sel50/sel100 */
         if(clock == 200000000)
         {
			 frqsel=0;
         } else if(clock == 100000000)
		 {
			 frqsel=3;
         }
		 else if ( (clock == 50000000) || (clock == 52000000) )
		 {
			 frqsel=4;
		 } else {
			 /* Default 50Mhz */
			 frqsel=4;
		 }


	  /* Select the DLL frequency for high speed modes */
      status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL5_REG_OFFSET, &regValue);
	  regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL5_FRQSEL_SHIFT,
		MMC_PHY_CTRL5_FRQSEL_MASK, frqsel);


	  status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL5_REG_OFFSET, regValue);

	   /* Set the impedance val/driver strength */
       status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, &regValue);
        regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_DLL_TRIM_ICP_SHIFT,
				MMC_PHY_CTRL1_DLL_TRIM_ICP_MASK, PHY_DLL_TRIM_ICP_8);


	   regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_DR_TY_SHIFT,
					MMC_PHY_CTRL1_DR_TY_MASK, driverType);
      /* Enable DLL */
       regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL1_ENDLL_SHIFT,
					MMC_PHY_CTRL1_ENDLL_MASK, MMC_PHY_CTRL1_ENDLL_ENABLE);
       status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL1_REG_OFFSET, regValue);


	  HSMMCSDPhy_get_otap(&otapdelaysel, &otapdelayval,mode);

	  if(otapdelaysel) {
		regValue = 0U;
        status = SdhcPhyRegisterRead(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, &regValue);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_OTAPDLYENA_SHIFT,
		MMC_PHY_CTRL4_OTAPDLYENA_MASK, MMC_PHY_CTRL4_OTAPDLYENA_ENABLED);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_PHY_CTRL4_OTAPDLYSEL_SHIFT,
						MMC_PHY_CTRL4_OTAPDLYSEL_MASK, otapdelayval);


	     status = SdhcPhyRegisterWrite(baseAddr, MMC_PHY_CTRL4_REG_OFFSET, regValue);
      }

	  /* Wait until dllrdy bit is set to 1 in the Phy Status (0x30) register */
	  do {
		dllrdy = SdhcRegisterReadFieldDWord(baseAddr + MMC_PHY_STS_1_REG_OFFSET ,MMC_PHY_STS_1_DLLRDY_MASK,MMC_PHY_STS_1_DLLRDY_SHIFT);
	  } while(dllrdy!=PHY_DLL_CTRL_STS_DLL_RDY_TRUE);
    }
	return status;
}

int32_t HSMMCSDSoftPhyConfigure(uintptr_t baseAddr, uint32_t mode, uint32_t clock, uint32_t driverType)
{
	int32_t status=STW_SOK;
	uint32_t otapdelaysel=0,otapdelayval=0,regValue=0;

	status = HSMMCSDPhyValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
	  HSMMCSDSoftPhy_get_otap(&otapdelaysel, &otapdelayval,mode);

	  if(otapdelaysel)
	  {
		regValue = 0U;
        status = SdhcPhyRegisterRead(baseAddr, MMC_SOFT_PHY_CTRL4_REG_OFFSET, &regValue);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL4_OTAPDLYENA_SHIFT,
		MMC_SOFT_PHY_CTRL4_OTAPDLYENA_MASK, MMC_SOFT_PHY_CTRL4_OTAPDLYENA_ENABLED);
	    regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_SHIFT,
						MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_MASK, otapdelayval);
        status = SdhcPhyRegisterWrite(baseAddr, MMC_SOFT_PHY_CTRL4_REG_OFFSET, regValue);
      }

	  if((mode==MODE_SDR50) || (mode==MODE_DDR50))
	  {
	    /* Set CLKBUF SEL */
       status = SdhcPhyRegisterRead(baseAddr, MMC_SOFT_PHY_CTRL5_REG_OFFSET, &regValue);
	   regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL5_CLKBUFSEL_SHIFT,
					MMC_SOFT_PHY_CTRL5_CLKBUFSEL_MASK, 7);
	   regValue = SdhcSetFieldValueDWord(regValue,MMC_SOFT_PHY_CTRL5_SELDLYTXCLK_SHIFT,
		MMC_SOFT_PHY_CTRL5_SELDLYTXCLK_MASK, 1);
       status = SdhcPhyRegisterWrite(baseAddr, MMC_SOFT_PHY_CTRL5_REG_OFFSET, regValue);

	  }

    }
	return status;
 }
int32_t HSMMCSDPhyLDOSet(uintptr_t baseAddr, uint32_t state)
{
	int32_t status=STW_SOK;
	return status;
}
