/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \file      evmc66x_elm.c
 *
 * \brief     This file contains APIs for ELM module.
 *
 */

/************************
 * Include Files
 ************************/
#include "platform_internal.h"

/*******************************************************************************
*                       API DEFINITIONS
*******************************************************************************/

/**
* \brief   This function reads the IP revision code of ELM.\n
*
* \param   hElm    ELM handle for accessing HW registers.\n
*
* \return  ipRev    IP revision code of ELM.\n
*/
Uint32 elmRevisionGet(elmHandle hElm)
{
    Uint32 ipRev;

    ipRev = CSL_FEXT(hElm->HEADER.REVISION, ELM_REVISION_REV_NUMBER);

    return (ipRev);
}

/**
* \brief   This function configs the Internal OCP clock gating strategy.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   configVal      Config value for OCP clk gating.\n
*                         This can take one of the following values :\n
*                         ELM_AUTOGATING_OCP_FREE   -- OCP clock is free-running\n
*                         ELM_AUTOGATING_OCP_GATING -- Automatic internal OCP
*                                                      clock gating strategy is
*                                                      applied based on the OCP
*                                                      interface activity.\n
*
* \return  none.\n
*/
void elmAutoGatingConfig(elmHandle hElm, Uint32 configVal)
{
	CSL_FINS(hElm->HEADER.SYSCONFIG, ELM_SYSCONFIG_AUTOGATING, configVal);
}

/**
* \brief   This function sets the idle mode for ELM.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   mode           Idle mode.\n
*                         This can take one of the following values :\n
*                         ELM_IDLEMODE_FORCEIDLE -- for force-idle. \n
*                         ELM_IDLEMODE_NOIDLE    -- for no-idle. \n
*                         ELM_IDLEMODE_SMARTIDLE -- for smart-idle.\n
*
* \return  none.\n
*/
void elmIdleModeSelect(elmHandle hElm, Uint32 mode)
{
	CSL_FINS(hElm->HEADER.SYSCONFIG, ELM_SYSCONFIG_SIDLEMODE, mode);
}

/**
* \brief   This function Resets the ELM.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \return  None.\n
*/
void elmModuleReset(elmHandle hElm)
{
	CSL_FINS(hElm->HEADER.SYSCONFIG, ELM_SYSCONFIG_SOFTRESET,
	         ELM_BIT_SET_HIGH);
}

/**
* \brief   This function sets the OCP Clock activity when module is in IDLE
*          mode.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   configVal      Config value.\n
*                         This can take one of the following values :\n
*                         ELM_CLOCKACTIVITYOCP_OCP_OFF -- OCP clock is swith off\n
*                         ELM_CLOCKACTIVITYOCP_OCP_ON  -- OCP Clock is
*                                                         maintained during
*                                                         wake up period.\n
*
* \return  none.\n
*/
void elmOCPClkActivityConfig(elmHandle hElm, Uint32 configVal)
{
	CSL_FINS(hElm->HEADER.SYSCONFIG, ELM_SYSCONFIG_CLOCKACTIVITYOCP,
	         configVal);
}

/**
* \brief   This function gets the software resets status of ELM.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \return  status     Reset status : \n
*                       0 : Module reset is on-going.\n
*                       1 : Module reset is completed.\n
*/
Uint32 elmModuleResetStatusGet(elmHandle hElm)
{
    Uint32 resetStat;

    resetStat = CSL_FEXT(hElm->HEADER.SYSSTS, ELM_SYSSTS_RESETDONE);

    return (resetStat);
}

/**
* \brief   This function gets Interrupt status.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   flag           Flag for which interrupt status has to get.\n
*                         This can take one of the following values :\n
*                         ELM_LOC_VALID_0_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 0.\n
*                         ELM_LOC_VALID_1_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 1.\n
*                         ELM_LOC_VALID_2_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 2.\n
*                         ELM_LOC_VALID_3_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 3.\n
*                         ELM_LOC_VALID_4_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 4.\n
*                         ELM_LOC_VALID_5_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 5.\n
*                         ELM_LOC_VALID_6_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 6.\n
*                         ELM_LOC_VALID_7_STATUS         : Error-location
*                                                          status for syndrome
*                                                          polynomial 7.\n
*                         ELM_PAGE_VALID_STATUS          : Error-location
*                                                          status for a full
*                                                          page. \n
*
* \return  intSts         Interrupt Status. Return value meaning depends on the
*                         param flag. \n
*                         If flag is ELM_LOC_VALID_i_STATUS where i = 0 to 7,
*                         then\n
*                            0 : No syndrome processed or process in progress.\n
*                            1 : Error-location process completed.\n
*
*                         If flag is ELM_PAGE_VALID_STATUS, then\n
*                            0 : Error locations invalid for all polynomials
*                                enabled.\n
*                            1 : All error locations valid.\n
*
*/
Uint32 elmIntStatusGet(elmHandle hElm, Uint32 flag)
{
    Uint32 retVal;

    retVal = 0;

    switch(flag)
    {
        case ELM_LOC_VALID_0_STATUS:
        	 retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_0);
        break;
        case ELM_LOC_VALID_1_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_1);
        break;
        case ELM_LOC_VALID_2_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_2);
        break;
        case ELM_LOC_VALID_3_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_3);
        break;
        case ELM_LOC_VALID_4_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_4);
        break;
        case ELM_LOC_VALID_5_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_5);
        break;
        case ELM_LOC_VALID_6_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_6);
        break;
        case ELM_LOC_VALID_7_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_7);
        break;
        case ELM_PAGE_VALID_STATUS:
             retVal = CSL_FEXT(hElm->HEADER.IRQSTS, ELM_IRQSTS_PAGE_VALID);
        break;
        default:
        /* Nothing to do here */
        break;
    }

    return (retVal);
}

/**
* \brief   This function clears the interrupt.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   flag           Flag for which interrupt status has to clear.\n
*                         This can take one of the following values :\n
*                         ELM_LOC_VALID_0_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 0.\n
*                         ELM_LOC_VALID_1_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 1.\n
*                         ELM_LOC_VALID_2_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 2.\n
*                         ELM_LOC_VALID_3_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 3.\n
*                         ELM_LOC_VALID_4_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 4.\n
*                         ELM_LOC_VALID_5_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 5.\n
*                         ELM_LOC_VALID_6_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 6.\n
*                         ELM_LOC_VALID_7_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 7.\n
*                         ELM_PAGE_VALID_STATUS         : Error-location
*                                                         interrupt for a full
*                                                         page.\n
*
* \return  None. \n
*
*/
void elmIntStatusClear(elmHandle hElm, Uint32 flag)
{
    switch(flag)
    {
        case ELM_LOC_VALID_0_STATUS:
        	 CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_0,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_1_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_1,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_2_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_2,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_3_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_3,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_4_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_4,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_5_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_5,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_6_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_6,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_LOC_VALID_7_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_LOC_VALID_7,
        	          ELM_BIT_SET_HIGH);
        break;
        case ELM_PAGE_VALID_STATUS:
             CSL_FINS(hElm->HEADER.IRQSTS, ELM_IRQSTS_PAGE_VALID,
        	          ELM_BIT_SET_HIGH);
        break;
        default:
        	 /* Nothing to do here */
        break;
    }
}

/**
* \brief   This function configs i.e enables or disables the interrupts.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   intflag        intFlag for which interrupt has to config.\n
*                         This can take one of the following values :\n
*                         ELM_LOC_VALID_0_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 0.\n
*                         ELM_LOC_VALID_1_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 1.\n
*                         ELM_LOC_VALID_2_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 2.\n
*                         ELM_LOC_VALID_3_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 3.\n
*                         ELM_LOC_VALID_4_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 4.\n
*                         ELM_LOC_VALID_5_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 5.\n
*                         ELM_LOC_VALID_6_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 6.\n
*                         ELM_LOC_VALID_7_STATUS        : Error-location
*                                                         interrupt for syndrome
*                                                         polynomial 7.\n
*                         ELM_PAGE_VALID_STATUS         : Error-location
*                                                         interrupt for a full
*                                                         page. \n
*
* \param   configVal     Config Value.\n
*                        This can take one of the following values :\n
*                        ELM_INT_ENALBLE                : To enble the interrupt\n
*                        ELM_INT_DISALBLE               : To disable the
*                                                         interrupt.\n
* \return  None. \n
*
*/
void elmIntConfig(elmHandle hElm, Uint32 intFlag, Uint32 configVal)
{
    switch(intFlag)
    {
        case ELM_LOC_VALID_0_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
				CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_0,
        	             ELM_BIT_ENABLE);
            }
            else
            {
				CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_0,
        	             ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_1_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
				CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_1,
        	             ELM_BIT_ENABLE);
            }
            else
            {
				CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_1,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_2_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_2,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_2,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_3_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_3,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_3,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_4_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_4,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_4,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_5_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_5,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_5,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_6_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_6,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_6,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_LOC_VALID_7_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_7,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_LOCATION_MASK_7,
                         ELM_BIT_DISABLE);
            }
        break;
        case ELM_PAGE_VALID_STATUS:
            if(configVal == ELM_INT_ENALBLE)
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_PAGE_MASK,
                         ELM_BIT_ENABLE);
            }
            else
            {
                CSL_FINS(hElm->HEADER.IRQEN, ELM_IRQEN_PAGE_MASK,
                         ELM_BIT_DISABLE);
            }
        break;
        default:
        	/* Nothing to do here */
        break;
    }
}

/**
* \brief   This function sets the Error correction level for BCH alogorithm.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   bchECCLevel    BCH error correction level.\n
*                         This can take one of the following values :\n
*                         ELM_ECC_BCH_LEVEL_16BITS    : For Upto 16 bits error
*                                                       correction.\n
*                         ELM_ECC_BCH_LEVEL_8BITS     : For Upto 8 bits error
*                                                       correction.\n
*                         ELM_ECC_BCH_LEVEL_4BITS     : For Upto 4 bits error
*                                                       correction.\n
*
* \return  None. \n
*
*/
void elmErrCorrectionLevelSet(elmHandle hElm, Uint32 bchECCLevel)
{
    CSL_FINS(hElm->HEADER.LOCATION_CONFIG, ELM_LOCATION_CONFIG_ECC_BCH_LEVEL,
             bchECCLevel);
}

/**
* \brief   This function sets the size of the buffers for which
*          the error-location engine is used.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \param   eccSize    eccSize in number of nibbles (i.e 4-bits entities).\n
*
* \return  None. \n
*
*/
void elmECCSizeSet(elmHandle hElm, Uint32 eccSize)
{
    CSL_FINS(hElm->HEADER.LOCATION_CONFIG, ELM_LOCATION_CONFIG_ECC_SIZE,
             eccSize);
}

/**
* \brief   This function sets mode of the ELM module.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
* \param   mode           mode of the ELM.\n
*                         This can take one of the following values :\n
*                         ELM_MODE_PAGE       -- For page mode.\n
*                         ELM_MODE_CONTINUOUS -- For continuous mode.\n
*
* \param   sectorNum      Sector number or syndrome polynomial number which has
*                         to select as part of the page in page mode.\n
*                         This can take one of the following values :\n
*                         ELM_PAGEMODE_SECTOR_0 -- For selecting syndrome
*                                                  polynomial 0 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_1 -- For selecting syndrome
*                                                  polynomial 1 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_2 -- For selecting syndrome
*                                                  polynomial 2 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_3 -- For selecting syndrome
*                                                  polynomial 3 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_4 -- For selecting syndrome
*                                                  polynomial 4 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_5 -- For selecting syndrome
*                                                  polynomial 5 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_6 -- For selecting syndrome
*                                                  polynomial 6 as part of the
*                                                  page in page mode.\n
*                         ELM_PAGEMODE_SECTOR_7 -- For selecting syndrome
*                                                  polynomial 7 as part of the
*                                                  page in page mode.\n

* \return  None. \n
*
*/
void elmModeSet(elmHandle hElm, Uint32 mode, Uint32 sectorNum)
{
    if(mode == ELM_MODE_CONTINUOUS)
    {
        hElm->HEADER.PAGE_CTRL &= ~( 1 << sectorNum );
    }
    else
    {
        hElm->HEADER.PAGE_CTRL |= ( mode << sectorNum );
    }
}

/**
* \brief   This function sets the fragments of syndrome polynomial for
*          error-location processing.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   synFrgmtId     Syndrome fragment ID.\n
*                         This can take one of the following values :\n
*                         ELM_SYNDROME_FRGMT_0 - For syndrome fragment 0.\n
*                         ELM_SYNDROME_FRGMT_1 - For syndrome fragment 1.\n
*                         ELM_SYNDROME_FRGMT_2 - For syndrome fragment 2.\n
*                         ELM_SYNDROME_FRGMT_3 - For syndrome fragment 3.\n
*                         ELM_SYNDROME_FRGMT_4 - For syndrome fragment 4.\n
*                         ELM_SYNDROME_FRGMT_5 - For syndrome fragment 5.\n
*                         ELM_SYNDROME_FRGMT_6 - For syndrome fragment 6.\n
* \param   synFrgmtVal    Syndrome fragment value.\n
*
* \param   csNum          Chip Select Number, 0 - 7.\n
*
* \return  None. \n
*
*/
void elmSyndromeFrgmtSet(elmHandle hElm, Uint32 synFrgmtId,
                         Uint32 synFrgmtVal, Uint32 csNum)
{
    volatile Uint32 *elmSynFrgmt;

    elmSynFrgmt = (Uint32 *)(&(hElm->SYNDROMES[csNum].SYNDROME_FRAGMENT_0) + 4*synFrgmtId);

    if(synFrgmtId != ELM_SYNDROME_FRGMT_6)
    {
        *elmSynFrgmt = synFrgmtVal;
    }
    else
    {
        *elmSynFrgmt = (synFrgmtVal & CSL_ELM_SYNDROME_FRAGMENT_6_SYNDROME_6_MASK);
    }
}

/**
* \brief   This function starts the error-location processing for the polynomial
*          set in the syndrome fragment registers.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \param   csNum      Chip Select Number, 0 - 7.\n
*
* \return  None. \n
*
*/
void elmErrLocProcessingStart(elmHandle hElm, Uint32 csNum)
{
    hElm->SYNDROMES[csNum].SYNDROME_FRAGMENT_6 |=
                           CSL_ELM_SYNDROME_FRAGMENT_6_SYNDROME_VALID_MASK;
}

/**
* \brief   This function gets the error-location processing status.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \param   csNum      Chip Select Number, 0 - 7.\n
*
* \return  status. \n
*          0 : ECC error-location process failed.\n
*          1 : ECC error-location process passed.\n
*
*/
Uint32 elmErrLocProcessingStatusGet(elmHandle hElm, Uint32 csNum)
{
    Uint32 status;

    status = CSL_FEXT(hElm->ERROR_LOCATIONS[csNum].LOCATION_STS,
                      ELM_LOCATION_STS_ECC_CORRECTBL);
    return (status);
}

/**
* \brief   This function gets the number of errors detected and located
*          during error-location processing.\n
*
* \param   hElm       ELM handle for accessing HW registers.\n
*
* \param   csNum      Chip Select Number, 0 - 7.\n
*
* \return  Number of errors detected and located.\n
*
*/
Uint32 elmNumOfErrsGet(elmHandle hElm, Uint32 csNum)
{
    Uint32 numOfErrs;

    numOfErrs = CSL_FEXT(hElm->ERROR_LOCATIONS[csNum].LOCATION_STS,
                      ELM_LOCATION_STS_ECC_NB_ERRORS);

    return (numOfErrs);
}

/**
* \brief   This function gets the Error-location bit address for the error
*          number passed.\n
*
* \param   hElm           ELM handle for accessing HW registers.\n
*
* \param   errNum         Error number.\n
*                         This can take one of the following values :\n
*                         ELM_ERROR_NUM_0 - For 0th error.\n
*                         ELM_ERROR_NUM_1 - For 1th error.\n
*                         ELM_ERROR_NUM_2 - For 2th error.\n
*                         ELM_ERROR_NUM_3 - For 3th error.\n
*                         ELM_ERROR_NUM_4 - For 4th error.\n
*                         ELM_ERROR_NUM_5 - For 5th error.\n
*                         ELM_ERROR_NUM_6 - For 6th error.\n
*                         ELM_ERROR_NUM_7 - For 7th error.\n
*                         ELM_ERROR_NUM_8 - For 8th error.\n
*                         ELM_ERROR_NUM_9 - For 9th error.\n
*                         ELM_ERROR_NUM_10 - For 10th error.\n
*                         ELM_ERROR_NUM_11 - For 11th error.\n
*                         ELM_ERROR_NUM_12 - For 12th error.\n
*                         ELM_ERROR_NUM_13 - For 13th error.\n
*                         ELM_ERROR_NUM_14 - For 14th error.\n
*                         ELM_ERROR_NUM_15 - For 15th error.\n
*
* \param   csNum      Chip Select Number, 0 - 7.\n
*
* \return  Bit address for the error number.\n
*
*/
Uint32 elmErrLocBitAddrGet(elmHandle hElm, Uint32 errNum, Uint32 csNum)
{
    volatile Uint32 *elmErrLoc;
    Uint32          bitAddr;

    elmErrLoc = (Uint32 *)(&(hElm->ERROR_LOCATIONS[csNum].ERROR_LOCATION_0) +
                           4*errNum);

    bitAddr = (*elmErrLoc & CSL_ELM_ERROR_LOCATION_0_ECC_ERROR_LOCATION_MASK);

    return (bitAddr);
}
/***************************** End Of File ***********************************/
