/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 *
 * \file  evmk2g_gpmc.c
 *
 * \brief This contains gpmc functions.
 *
 ******************************************************************************/

#include "platform_internal.h"

/**
* \brief   This function reads the IP revision code of GPMC.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  ipRev          IP revision code of GPMC.\n
*/
Uint32  GPMCRevisionGet(gpmcHandle hGpmc)
{
    Uint32 ipRev;

	ipRev =  CSL_FEXT(hGpmc->REVISION, GPMC_REVISION_REV);

    return (ipRev);
}

/**
* \brief   This function sets the idle mode for gpmc.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   mode           Idle mode.\n
*                         This can take one of the following values :\n
*                         GPMC_IDLEMODE_FORCEIDLE -- for force-idle. \n
*                         GPMC_IDLEMODE_NOIDLE    -- for no-idle. \n
*                         GPMC_IDLEMODE_SMARTIDLE -- for smart-idle.\n
*/
void  GPMCIdleModeSelect(gpmcHandle hGpmc, Uint32 mode)
{
	CSL_FINS(hGpmc->SYSCONFIG, GPMC_SYSCONFIG_SIDLEMODE, mode);
}

/**
* \brief   This function configs the internal OCP clock gating strategy.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   configVal      Config value.\n
*                         This can take one of the following values :\n
*                         GPMC_AUTOIDLE_FREERUN -- When Interface clock is
*                                                  free-running. \n
*                         GPMC_AUTOIDLE_AUTORUN -- When Automatic Interface clk
*                                                  gating strategy is applied.\n
*
* \return  none.\n
*/
void  GPMCAutoIdleConfig(gpmcHandle hGpmc, Uint32 configVal)
{
    CSL_FINS(hGpmc->SYSCONFIG, GPMC_SYSCONFIG_SIDLEMODE,
             configVal);
}

/**
* \brief   This function resets the GPMC.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*/
void  GPMCModuleSoftReset(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->SYSCONFIG, GPMC_SYSCONFIG_SOFTRESET,
	         GPMC_BIT_SET_HIGH);
}

/**
* \brief   This function gets the software resets status of GPMC.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  status         Reset status : \n
*                            0 : Module reset is on-going.\n
*                            1 : Module reset is completed.\n
*/
Uint32  GPMCModuleResetStatusGet(gpmcHandle hGpmc)
{
    Uint32 resetStat;

	resetStat = CSL_FEXT(hGpmc->SYSSTS, GPMC_SYSSTS_RESETDONE);

    return (resetStat);
}

/**
* \brief   This function gets Interrupt status of interrupt passed.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag for which interrupt status has to get.\n
*                         This can take one of the following values :\n
*                         GPMC_FIFOEVENT_STATUS         : For FIFOEvent
*                                                         interrupt status.\n
*                         GPMC_TERMINALCOUNT_STATUS     : For TerminalCountEvent
*                                                         interrupt status.\n
*                         GPMC_WAIT0EDGEDETECTION_STATUS: For Wait0 Edge
*                                                         Detection interrupt
*                                                         status.\n
*                         GPMC_WAIT1EDGEDETECTION_STATUS: For Wait1 Edge
*                                                         Detection interrupt
*                                                         status.\n
*
*
* \return  intSts         Interrupt Status. Return value meaning depends on the
*                         interrupt flag passed. \n
*                         if flag is GPMC_FIFOEVENT_STATUS, then \n
*                            0 : Less than FIFOTHRESHOLD bytes are available in
*                                prefetch/read mode.\n
*                                Less than FIFOTHRESHOLD byte free spaces are
*                                available in write-posting/write mode. \n
*                            1 : Atleast FIFOTHRESHOLD bytes are available in
*                                prefetch/read mode.\n
*                                Atlease FIFOTHRESHOLD byte free places are
*                                available in write-posting/write mode.\n
*                         if flag is GPMC_TERMINALCOUNT_STATUS, then \n
*                            0 : CountValue is greater than 0.\n
*                            1 : CountValue is equal to 0.\n
*                         if flag is GPMC_WAIT0EDGEDETECTION_STATUS, then \n
*                            0 : A transition on WAIT0 input pin has not been
*                                detected.\n
*                            1 : A transition on WAIT0 input pin has been
*                                detected.\n
*                         if flag is GPMC_WAIT1EDGEDETECTION_STATUS, then \n
*                            0 : A transition on WAIT1 input pin has not been
*                                detected.\n
*                            1 : A transition on WAIT1 input pin has been
*                                detected.\n
*
*/
Uint32  GPMCIntStatusGet(gpmcHandle hGpmc, Uint32 flag)
{
    Uint32 retVal;

    retVal = 0;

    switch(flag)
    {
        case GPMC_FIFOEVENT_STATUS:
             retVal = CSL_FEXT(hGpmc->IRQSTS,
                               GPMC_IRQSTS_FIFOEVTSTS);
        break;
        case GPMC_TERMINALCOUNT_STATUS:
             retVal = CSL_FEXT(hGpmc->IRQSTS,
                               GPMC_IRQSTS_TERMINALCOUNTSTS);
        break;
        case GPMC_WAIT0EDGEDETECTION_STATUS:
             retVal = CSL_FEXT(hGpmc->IRQSTS,
                               GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS);
        break;
        case GPMC_WAIT1EDGEDETECTION_STATUS:
             retVal = CSL_FEXT(hGpmc->IRQSTS,
                               GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS);
        break;
    }

    return (retVal);
}

/**
* \brief   This function clears/resets the interrupt status.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag for which interrupt status has to reset.\n
*                         This can take one of the following values :\n
*                         GPMC_FIFOEVENT_STATUS         : For FIFOEvent
*                                                         interrupt status.\n
*                         GPMC_TERMINALCOUNT_STATUS     : For TerminalCountEvent
*                                                         interrupt status.\n
*                         GPMC_WAIT0EDGEDETECTION_STATUS: For Wait1 Edge
*                                                         Detection interrupt
*                                                         status.\n
*                         GPMC_WAIT1EDGEDETECTION_STATUS: For Wait1 Edge
*                                                         Detection interrupt
*                                                         status.\n
*
* \return  None.
*
*/
void  GPMCIntStatusClear(gpmcHandle hGpmc, Uint32 flag)
{
    switch(flag)
    {
        case GPMC_FIFOEVENT_STATUS:
			CSL_FINS(hGpmc->IRQSTS,
                     GPMC_IRQSTS_FIFOEVTSTS, GPMC_BIT_SET_HIGH);
        break;
        case GPMC_TERMINALCOUNT_STATUS:
			CSL_FINS(hGpmc->IRQSTS,
                     GPMC_IRQSTS_TERMINALCOUNTSTS, GPMC_BIT_SET_HIGH);
        break;
        case GPMC_WAIT0EDGEDETECTION_STATUS:
			CSL_FINS(hGpmc->IRQSTS,
                     GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS,
                     GPMC_BIT_SET_HIGH);
        break;
        case GPMC_WAIT1EDGEDETECTION_STATUS:
			CSL_FINS(hGpmc->IRQSTS,
                     GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS,
                     GPMC_BIT_SET_HIGH);
        break;
    }
}

/**
* \brief   This function enables the interrupts.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag for which interrupt has to enable.
*                         This can take one of the following values :\n
*                         GPMC_FIFOEVENT_INT          : For FIFOEvent interrupt.\n
*                         GPMC_TERMINALCOUNT_INT      : For TerminalCountEvent
*                                                       interrupt.\n
*                         GPMC_WAIT0EDGEDETECTION_INT : For Wait0 Edge
*                                                       Detection interrupt.\n
*                         GPMC_WAIT1EDGEDETECTION_INT : For Wait1 Edge
*                                                       Detection interrupt.\n
*
*
* \return  None. \n
*
*/
void  GPMCIntEnable(gpmcHandle hGpmc, Uint32 flag)
{
    switch(flag)
    {
        case GPMC_FIFOEVENT_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_FIFOEVTEN, GPMC_BIT_ENABLE);
        break;
        case GPMC_TERMINALCOUNT_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_TERMINALCOUNTEVTEN,
                     GPMC_BIT_ENABLE);
        break;
        case GPMC_WAIT0EDGEDETECTION_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_WAIT0EDGEDETECTIONEN,
                     GPMC_BIT_ENABLE);
        break;
        case GPMC_WAIT1EDGEDETECTION_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_WAIT1EDGEDETECTIONEN,
                     GPMC_BIT_ENABLE);
        break;
    }
}

/**
* \brief   This function disable/masks the interrupts.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag for which interrupt has to mask.\n
*                         This can take one of the following values :\n
*                         GPMC_FIFOEVENT_INT          : For FIFOEvent interrupt.\n
*                         GPMC_TERMINALCOUNT_INT      : For TerminalCountEvent
*                                                       interrupt.\n
*                         GPMC_WAIT0EDGEDETECTION_INT : For Wait1 Edge
*                                                       Detection interrupt.\n
*                         GPMC_WAIT1EDGEDETECTION_INT : For Wait1 Edge
*                                                       Detection interrupt. \n
*
* \return  None.\n
*
*/
void  GPMCIntDisable(gpmcHandle hGpmc, Uint32 flag)
{
    switch(flag)
    {
        case GPMC_FIFOEVENT_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_FIFOEVTEN, GPMC_BIT_DISABLE);
        break;
        case GPMC_TERMINALCOUNT_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_TERMINALCOUNTEVTEN,
                     GPMC_BIT_DISABLE);
        break;
        case GPMC_WAIT0EDGEDETECTION_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_WAIT0EDGEDETECTIONEN,
                     GPMC_BIT_DISABLE);
        break;
        case GPMC_WAIT1EDGEDETECTION_INT:
			CSL_FINS(hGpmc->IRQEN,
                     GPMC_IRQEN_WAIT1EDGEDETECTIONEN,
                     GPMC_BIT_DISABLE);
        break;
    }
}

/**
* \brief   This function sets the start timeout value(TIMEOUTSTARTVALUE)
*          of the timeout counter.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   timoutVal      Timeout start Value in GPMC_FCLK cycles.\n
*
* \return  None. \n
*
*/
void  GPMCTimeOutStartValSet(gpmcHandle hGpmc, Uint32 timeoutVal)
{
    CSL_FINS(hGpmc->TIMEOUT_CTRL,
             GPMC_TIMEOUT_CTRL_TIMEOUTSTARTVALUE, timeoutVal);
}

/**
* \brief   This function configures the timeout feature.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag to indicate whether to enable or disable the
*                         feature.\n
*                         This can take one of the following values :\n
*                         GPMC_TIMEOUTFEATURE_ENABLE  - To enable the timout
*                                                       feature.\n
*                         GPMC_TIMEOUTFEATURE_DISABLE - To disable the timout
*                                                       feature.\n
* \return  None. \n
*
*/
void  GPMCTimeOutFeatureConfig(gpmcHandle hGpmc, Uint32 flag)
{
    if(flag == GPMC_TIMEOUTFEATURE_ENABLE)
    {
		CSL_FINS(hGpmc->TIMEOUT_CTRL,
		         GPMC_TIMEOUT_CTRL_TIMEOUTEN, GPMC_BIT_ENABLE);
    }
    else if (flag == GPMC_TIMEOUTFEATURE_DISABLE)
    {
		CSL_FINS(hGpmc->TIMEOUT_CTRL,
		         GPMC_TIMEOUT_CTRL_TIMEOUTEN, GPMC_BIT_DISABLE);
    }
}

/**
* \brief   This function returns the address of illegal access when an error
*          occures.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  illegalAddrVal Address of illegal access. \n
*
*/
Uint32  GPMCErrAddrGet(gpmcHandle hGpmc)
{
    Uint32 retVal;

	retVal = CSL_FEXT(hGpmc->ERR_ADDR, GPMC_ERR_ADDR_ILLEGALADD);

    return (retVal);
}

/**
* \brief   This function returns the status of error validity.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  ErrValstatus   Error validity status. \n
*                         0 : Error fields are no longer valid.\n
*                         1 : Error detected and logged in the
*                             other error fields.\n
*
*/
Uint32  GPMCErrValStatusGet(gpmcHandle hGpmc)
{
    Uint32 status;

	status = CSL_FEXT(hGpmc->ERR_TYPE, GPMC_ERR_TYPE_ERRORVALID);

    return (status);
}

/**
* \brief   This function returns the System Command of the transaction
*          that caused the error.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  errCmd         System Command that caused the error. \n
*
*/
Uint32  GPMCErrSysCmdGet(gpmcHandle hGpmc)
{
    Uint32 cmd;

	cmd = CSL_FEXT(hGpmc->ERR_TYPE, GPMC_ERR_TYPE_ILLEGALMCMD);

    return (cmd);
}

/**
* \brief   This function returns whether passed error is occured or not.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   errFlag        Type of the error.\n
*                         This can take one of the following values :\n
*                         GPMC_TIMEOUT_ERROR     -- For timeout error.\n
*                         GPMC_NOTSUPPMCMD_ERROR -- For non-supported cmd error.\n
*                         GPMC_NOTSUPPADD_ERROR  -- For non-supported add error.\n
*
* \return  ErrStatus \n
*
*                         1 : If passed argument type of error occured.\n
*                         0 : If passed argument type of error doesn't occured.\n
*
*/
Uint32  GPMCErrStatusGet(gpmcHandle hGpmc, Uint32 err)
{
    Uint32 retVal;

    retVal = 0;

    switch(err)
    {
        case GPMC_TIMEOUT_ERROR:
             retVal = CSL_FEXT(hGpmc->ERR_TYPE,
                      GPMC_ERR_TYPE_ERRORTIMEOUT);
        break;
        case GPMC_NOTSUPPMCMD_ERROR:
             retVal = CSL_FEXT(hGpmc->ERR_TYPE,
                      GPMC_ERR_TYPE_ERRORNOTSUPPMCMD);
        break;
        case GPMC_NOTSUPPADD_ERROR:
             retVal = CSL_FEXT(hGpmc->ERR_TYPE,
                      GPMC_ERR_TYPE_ERRORNOTSUPPADD);
        break;
    }
    return (retVal);
}

/**
* \brief   This function sets/selects the waitpin polarity.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   pin            Wait pin.\n
*                         This can take one of the following values :\n
*                         GPMC_WAIT_PIN0   -- For WAITPIN0.\n
*                         GPMC_WAIT_PIN1   -- For WAITPIN1.\n
*
* \param  polarity        Wait pin polarity.\n
*                         This can take one of the following values :\n
*                         GPMC_WAIT_PIN_POLARITY_LOW  -- for active low.\n
*                         GPMC_WAIT_PIN_POLARITY_HIGH -- for active high.\n
*
* \return  None.\n
*
*/
void  GPMCWaitPinPolaritySelect(gpmcHandle hGpmc, Uint32 pin,
                                Uint32 polarity)
{
    if(pin == GPMC_WAIT_PIN0)
    {
        if(polarity == GPMC_WAIT_PIN_POLARITY_HIGH)
        {
			CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WAIT0PINPOLARITY,
			         GPMC_BIT_SET_HIGH);
        }
        else if(polarity == GPMC_WAIT_PIN_POLARITY_LOW)
        {
			CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WAIT0PINPOLARITY,
			         GPMC_BIT_SET_LOW);
        }
    }
    else if(pin == GPMC_WAIT_PIN1)
    {
        if(polarity == GPMC_WAIT_PIN_POLARITY_HIGH)
        {
			CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WAIT1PINPOLARITY,
			         GPMC_BIT_SET_HIGH);
        }
        else if(polarity == GPMC_WAIT_PIN_POLARITY_LOW)
        {
			CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WAIT1PINPOLARITY,
			         GPMC_BIT_SET_LOW);
        }
    }
}

/**
* \brief   This function controls the write protect output pin level.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   pinLevel       Write Protect pin level.\n
*                         This can take one of the following values :\n
*                         GPMC_WP_PIN_LEVEL_LOW  -- for level low.\n
*                         GPMC_WP_PIN_LEVEL_HIGH -- for level high.\n
*
* \return  None.\n
*
*/
void  GPMCWriteProtectPinLevelCtrl(gpmcHandle hGpmc, Uint32 pinLevel)
{
    if(pinLevel == GPMC_WP_PIN_LEVEL_HIGH)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WRITEPROTECT,
				 GPMC_BIT_SET_HIGH);
    }
    else if(pinLevel == GPMC_WP_PIN_LEVEL_LOW)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_WRITEPROTECT,
				 GPMC_BIT_SET_LOW);
    }
}

/**
* \brief   This function configs the limited address device support.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag to indicate whether to enable/disable the
*                         Limited Address device support.\n
*                         This can take one of the following values :\n
*                         GPMC_LIMITEDADDRESS_SUPPORT_ENABLE  -- To enable
*                                                                the support.\n
*                         GPMC_LIMITEDADDRESS_SUPPORT_DISABLE -- To disable
*                                                                the support.\n
*
* \return  None.\n
*
*/
void  GPMCLimitedAddrDevSupportConfig(gpmcHandle hGpmc, Uint32 flag)
{
    if(flag == GPMC_LIMITEDADDRESS_SUPPORT_ENABLE)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_LIMITEDADDR,
				 GPMC_BIT_ENABLE);
    }
    else if(flag == GPMC_LIMITEDADDRESS_SUPPORT_DISABLE)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_LIMITEDADDR,
				 GPMC_BIT_DISABLE);
    }
}

/**
* \brief   This function configs the Force Posted Write feature to NAND
*          Cmd/Add/Data location.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag to indicate whether to enable/disable the
*                         Force Posted Write feature.\n
*                         This can take one of the following values :\n
*                         GPMC_FORCEPOSTEDWRITE_ENABLE  -- To enable the
*                                                          feature.\n
*                         GPMC_FORCEPOSTEDWRITE_DISABLE -- To disable
*                                                          the feature.\n
*
* \return  None.\n
*
*/
void  GPMCNANDForcePostedWriteFeatureConfig(gpmcHandle hGpmc,
                                            Uint32 flag)
{
    if(flag == GPMC_FORCEPOSTEDWRITE_ENABLE)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_NANDFORCEPOSTEDWRITE,
				 GPMC_BIT_ENABLE);
    }
    else if(flag == GPMC_FORCEPOSTEDWRITE_DISABLE)
    {
		CSL_FINS(hGpmc->CONFIG, GPMC_CONFIG_NANDFORCEPOSTEDWRITE,
				 GPMC_BIT_DISABLE);
    }
}

/**
* \brief   This function gets the waitpin status.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   pin            Wait pin.\n
*                         This can take one of the following values :\n
*                         GPMC_WAIT_PIN0   -- For WAITPIN0.\n
*                         GPMC_WAIT_PIN1   -- For WAITPIN1.\n
*
* \return  pinStatus      Pin Status.\n
*                            0 : If the status is active low.\n
*                            1 : If the status is active high.\n
*
*/
Uint32  GPMCWaitPinStatusGet(gpmcHandle hGpmc, Uint32 pin)
{
    Uint32 pinStatus;

    pinStatus = 0;

    if(pin == GPMC_WAIT_PIN0)
    {
		pinStatus = CSL_FEXT(hGpmc->STS, GPMC_STS_WAIT0STS);
    }
    else if(pin == GPMC_WAIT_PIN1)
    {
		pinStatus = CSL_FEXT(hGpmc->STS, GPMC_STS_WAIT1STS);
    }

    return (pinStatus);
}

/**
* \brief   This function gets the empty write buffer status.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  Status         Empty buffer status.\n
*                            0 : If the Write Buffer is not empty.\n
*                            1 : If the Write Buffer is empty.\n
*
*/
Uint32  GPMCEmptyWriteBuffStatusGet(gpmcHandle hGpmc)
{
    Uint32 status;

    status = CSL_FEXT(hGpmc->STS,
                      GPMC_STS_EMPTYWRITEBUFFERSTS);
    return (status);
}

/**
* \brief   This function selects the FCLK DIVIDER for the chip select passed.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   divideVal      FCLK Divice value.\n
*                         This can take one of the following values :\n
*                         GPMC_FCLK_DIV_BY_1 -- For GPMC_CLK = (GPMC_FCLK / 1)\n
*                         GPMC_FCLK_DIV_BY_2 -- For GPMC_CLK = (GPMC_FCLK / 2)\n
*                         GPMC_FCLK_DIV_BY_3 -- For GPMC_CLK = (GPMC_FCLK / 3)\n
*                         GPMC_FCLK_DIV_BY_4 -- For GPMC_CLK = (GPMC_FCLK / 4)\n
* \return  None.\n
*
*/
void  GPMCFclkDividerSelect(gpmcHandle hGpmc, Uint32 csNum,
                            Uint32 divideVal)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_GPMCFCLKDIVIDER, divideVal);
}

/**
* \brief   This function selects the signals timing latencies scalar factor
*          for the chip select.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   scaleftr       Scalar factor.\n
*                         This can take one of the following values :\n
*                         GPMC_TIMEPARAGRANULARITY_X1 -- For x1 latencies\n
*                         GPMC_TIMEPARAGRANULARITY_X2 -- For x2 latencies\n
* \return  None.\n
*
*/
void  GPMCTimeParaGranularitySelect(gpmcHandle hGpmc, Uint32 csNum,
                                    Uint32 scaleftr)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_TIMEPARAGRANULARITY, scaleftr);
}

/**
* \brief   This function selects the Address and data multiplexed protocol
*          for the device connected to csNum.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   protocol       Protocol type.\n
*                         This can take one of the following values :\n
*                         GPMC_MUXADDDATA_AADMUX    -- For Address, address and
*                                                      data(AAD) muxed protocol.\n
*                         GPMC_MUXADDDATA_NOMUX     -- For Non-muxed prorocol.\n
*                         GPMC_MUXADDDATA_ADMUX     -- For Address & Data muxed
*                                                      protocol.\n
* \return  None.\n
*
*/
void  GPMCAddrDataMuxProtocolSelect(gpmcHandle hGpmc, Uint32 csNum,
                                    Uint32 protocol)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_MUXADDDATA, protocol);
}

/**
* \brief   This function selects the device type for the device connected to
*          csNum.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   devType        Device Type.\n
*                         This can take one of the following values :\n
*                         GPMC_DEVICETYPE_NANDLIKE  -- For NAND flash like
*                                                      devices.\n
*                         GPMC_DEVICETYPE_NORLIKE   -- For NOR flash like
*                                                      devices.\n
* \return  None.\n
*
*/
void  GPMCDevTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                        Uint32 devType)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_DEVICETYPE, devType);
}

/**
* \brief   This function selects the device size for the device connected to
*          csNum.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   devSize        Device Size.\n
*                         This can take one of the following values :\n
*                         GPMC_DEVICESIZE_8BITS   -- For 8-bit device.\n
*                         GPMC_DEVICESIZE_16BITS  -- For 16-bit device.\n
* \return  None.\n
*
*/
void  GPMCDevSizeSelect(gpmcHandle hGpmc, Uint32 csNum,
                        Uint32 devSize)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_DEVICESIZE, devSize);
}

/**
* \brief   This function selects the WAIT PIN for the device connected to
*          csNum.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   waitPin        Wait Pin.\n
*                         This can take one of the following values :\n
*                         GPMC_WAIT_PIN0  -- To Select WAITPIN0.\n
*                         GPMC_WAIT_PIN1  -- To Select WAITPIN1.\n
* \return  None.\n
*
*/
void  GPMCWaitPinSelect(gpmcHandle hGpmc, Uint32 csNum,
                        Uint32 waitPin)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WAITPINSELECT, waitPin);
}

/**
* \brief   This function configs/selects the wait monitoring time for the device
*          connected to csNum.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   flag           Flag to indicate the wait monitoring time.\n
*                         This can take one of the following values :\n
*                         GPMC_WAITMONITORINGTIME_WITH_VALIDDATA  -- For wait
*                                               pin monitoring with valid data.\n
*                         GPMC_WAITMONITORINGTIME_ONECLKB4_VALIDDATA  -- For
*                                               wait pin monitoring one GPMC_CLK
*                                               before valid data. \n
*                         GPMC_WAITMONITORINGTIME_TWOCLKB4_VALIDDATA  -- For
*                                               wait pin monitoring two GPMC_CLK
*                                               before valid data. \n
* \return  None.\n
*
*/
void  GPMCWaitMonitoringTimeSelect(gpmcHandle hGpmc, Uint32 csNum,
                                   Uint32 flag)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WAITMONITORINGTIME, flag);
}

/**
* \brief   This function configs the wait pin monitoring for read and write
*          access.
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   mode           Mode for which wait monitoring has to config.\n
*                         This can take one of the following values :\n
*                         GPMC_MODE_READ   -- To config the  wait
*                                              monitoring for READ.\n
*                         GPMC_MODE_WRITE  -- To config the  wait
*                                              monitoring for WRITE.\n
*
* \param   flag           Flag to indicate whether to enable/disable the wait
*                         monitoring.\n
*                         This can take one of the following values :\n
*                         GPMC_WAITMONITORING_ENABLE  -- To enable the wait
*                         monitoring.\n
*                         GPMC_WAITMONITORING_DISABLE -- To disable the wait
*                         monitoring.\n
* \return  None.\n
*
*/
void  GPMCWaitPinMonitoringConfig(gpmcHandle hGpmc, Uint32 csNum,
                                  Uint32 mode, Uint32 flag)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

    if(mode == GPMC_MODE_WRITE)
    {
		CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WAITWRITEMONITORING, flag);
    }
    else if(mode == GPMC_MODE_READ)
    {
		CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WAITREADMONITORING, flag);
   }
}

/**
* \brief   This function configs the output GPMC_CLK activation time.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   flag           Flag to indicate the activation time of GPMC_CLK.\n
*                         This can take one of the following values :\n
*                         GPMC_CLKACTIVATIONTIME_ATSTART     -- For First rising
*                                                           edge of GPMC_CLK at
*                                                           start access time.\n
*                         GPMC_CLKACTIVATIONTIME_ONECLK_AFTR -- For First rising
*                                                           edge of GPMC_CLK one
*                                                           GPMC_FCLK cycle aftr
*                                                           start access time.\n
*                         GPMC_CLKACTIVATIONTIME_TWOCLK_AFTR -- For First rising
*                                                           edge of GPMC_CLK two
*                                                           GPMC_FCLK cycle aftr
*                                                            start access time.\n
* \return  None.\n
*
*/
void  GPMCClkActivationTimeConfig(gpmcHandle hGpmc, Uint32 csNum,
                                  Uint32 flag)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_CLKACTIVATIONTIME, flag);
}

/**
* \brief   This function sets the device page length.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   pageLen        Device Page Length.\n
*                         This can take one of the following values :\n
*                         GPMC_DEV_PAGELENGTH_FOUR    -- For 4 words page
*                                                        length.\n
*                         GPMC_DEV_PAGELENGTH_EIGHT   -- For 8 words page
*                                                        length.\n
*                         GPMC_DEV_PAGELENGTH_SIXTEEN -- For 16 words page
*                                                        length. \n
* \return  None.\n
*
*/
void  GPMCDevPageLenSet(gpmcHandle hGpmc, Uint32 csNum, Uint32 pageLen)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH, pageLen);
}

/**
* \brief   This function selects the write type.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   writeType      writeType for the write mode operation.\n
*                         This can take one of the following values :\n
*                         GPMC_WRITETYPE_ASYNC -- For write asynchronous.\n
*                         GPMC_WRITETYPE_SYNC  -- For write synchronous.\n
*
* \return  None.\n
*
*/
void  GPMCWriteTypeSelect(gpmcHandle hGpmc, Uint32 csNum, Uint32 writeType)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WRITETYPE, writeType);
}

/**
* \brief   This function selects the read type.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   readType       readType for the read mode operation.\n
*                         This can take one of the following values :\n
*                         GPMC_READTYPE_ASYNC -- For read asynchronous.\n
*                         GPMC_READTYPE_SYNC  -- For read synchronous.\n
*
* \return  None.\n
*
*/
void  GPMCReadTypeSelect(gpmcHandle hGpmc, Uint32 csNum, Uint32 readType)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_READTYPE, readType);
}

/**
* \brief   This function configs the access type for read and write.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   mode           Mode for which access type has to config.\n
*                         This can take one of the following values :\n
*                         GPMC_MODE_READ   -- To config access
*                                             type for READ.\n
*                         GPMC_MODE_WRITE  -- To config access
*                                             type for WRITE.\n
* \param   AccessType     Access Type.\n
*                         This can take one of the following values :\n
*                         GPMC_ACCESSTYPE_SINGLE   -- For single access.\n
*                         GPMC_ACCESSTYPE_MULTIPLE -- For multiple access.\n
*
* \return  None.\n
*
*/
void  GPMCAccessTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                           Uint32 mode, Uint32 accessType)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

    if(mode == GPMC_MODE_WRITE)
    {
		CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WRITEMULTIPLE, accessType);
    }
    else if(mode == GPMC_MODE_READ)
    {
		CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_READMULTIPLE, accessType);
    }
}

/**
* \brief   This function configs the wrapping burst capability.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   flag           Flag to indicate whether to enable/disable
*                         Synchronous wrapping burst capability.\n
*                         This can take one of the following values :\n
*                         GPMC_WRAPBURST_ENABLE   -- To enable the wrap burst
*                                                     capability.\n
*                         GPMC_WRAPBURST_DISABLE  -- To disable the wrap burst
*                                                     capability.\n
*
* \return  None.\n
*
*/
void  GPMCSyncWrapBurstConfig(gpmcHandle hGpmc, Uint32 csNum, Uint32 flag)
{
	volatile Uint32 *gpmcCfg1;

	gpmcCfg1 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG1_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg1, GPMC_CONFIG1_0_WRAPBURST, flag);
}

/**
* \brief   This function configs the timing parameters for Chip Select signal.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Configuration value for chip select timing parameters
*                         Use the GPMC_CS_TIMING_CONFIG macro to get the value
*                         of conf. \n
*
* \return  None.\n
*
*/
void  GPMCCSTimingConfig(gpmcHandle hGpmc, Uint32 csNum, Uint32 conf)
{
	volatile Uint32 *gpmcCfg2;

	gpmcCfg2 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG2_0 + (csNum * 0x30));

	*gpmcCfg2 = conf;
}

/**
* \brief   This function configs the timing parameters for ADV# signal.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Configuration value for ADV# signal timing parameters
*                         Use the GPMC_ADV_TIMING_CONFIG macro to get the value
*                         of conf. \n
*
* \return  None.\n
*
*/
void  GPMCADVTimingConfig(gpmcHandle hGpmc, Uint32 csNum, Uint32 conf)
{
	volatile Uint32 *gpmcCfg3;

	gpmcCfg3 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG3_0 + (csNum * 0x30));

    *gpmcCfg3 = conf;
}

/**
* \brief   This function configs the timing parameters for WE# and OE# signal.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Configuration value for WE# and OE# signal timing
*                         Parameters. Use the GPMC_WE_OE_TIMING_CONFIG macro to
*                         get the value of conf. \n
*
* \return  None.\n
*
*/
void  GPMCWEAndOETimingConfig(gpmcHandle hGpmc, Uint32 csNum, Uint32 conf)
{
	volatile Uint32 *gpmcCfg4;

	gpmcCfg4 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG4_0 + (csNum * 0x30));

    *gpmcCfg4 = conf;
}

/**
* \brief   This function configs the RdAccessTime and CycleTime timing
*          parameters.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Configuration value for RdAccessTime and CycleTime
*                         timing parameters. Use the
*                         GPMC_RDACCESS_CYCLETIME_TIMING_CONFIG macro to
*                         get the value of conf. \n
*
* \return  None.\n
*
*/
void  GPMCRdAccessAndCycleTimeTimingConfig(gpmcHandle hGpmc,
                                           Uint32 csNum,
                                           Uint32 conf)
{
	volatile Uint32 *gpmcCfg5;

	gpmcCfg5 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG5_0 + (csNum * 0x30));

    *gpmcCfg5 = conf;
}

/**
* \brief   This function configs the WrAccessTime, Cycle2Cycle and BusTurnAround
*          timing parameters.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   wrAccessTime   Write Access Time(Delay from StartAccessTime to the
*                         GPMC_FCLK rising edge corresponding the GPMC_CLK
*                         rising edge used by the attached memory for the
*                         first data capture) in GPMC_FCLK cycles.\n
*
*        wrDataOnADmuxBus Specifies on which GPMC_FCLK rising edge the first
*                         data of the synchronous burst write is driven in the
*                         add/data multiplexed bus.\n
*
* \return  None.\n
*
*/
void  GPMCWrAccessAndWrDataOnADMUXBusTimingConfig(gpmcHandle hGpmc,
                                                  Uint32 csNum,
                                                  Uint32 wrAccessTime,
                                                  Uint32 wrDataOnADmuxBus)
{
    Uint32          conf;
  	volatile Uint32 *gpmcCfg6;

	gpmcCfg6 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG6_0 + (csNum * 0x30));

    conf = ( ((wrAccessTime << CSL_GPMC_CONFIG6_0_WRACCESSTIME_SHIFT) &
             CSL_GPMC_CONFIG6_0_WRACCESSTIME_MASK) |
             ((wrDataOnADmuxBus << CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_SHIFT) &
             CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_MASK));

    *gpmcCfg6 |= conf;
}

/**
* \brief   This function configs the Cycle2Cycle and BusTurnAround  timing
*          parameters.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Configuration value for Cycle2Cycle and BusTurnAround
*                         timing parameters. Use the
*                         GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG macro to
*                         get the value of conf. \n
*
* \return  None.\n
*
*/
void  GPMCycle2CycleAndTurnArndTimeTimingConfig(gpmcHandle hGpmc,
                                                Uint32 csNum,
                                                Uint32 conf)
{
  	volatile Uint32 *gpmcCfg6;

	gpmcCfg6 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG6_0 + (csNum * 0x30));

    *gpmcCfg6 |= conf;
}

/**
* \brief   This function enables/disables the chip select. This function
*          is called during the chip select configuration.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   conf           Flag to indicate whether to enable or disable
*                         the Chip select.\n
*                         This can take one of the following values :\n
*                         GPMC_CS_ENABLE  -- To enable the chip select.\n
*                         GPMC_CS_DISABLE -- To disable the chip select.\n
*
* \return  None.\n
*
*/
void  GPMCCSConfig(gpmcHandle hGpmc, Uint32 csNum, Uint32 conf)
{
  	volatile Uint32 *gpmcCfg7;

	gpmcCfg7 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG7_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg7, GPMC_CONFIG7_0_CSVALID, conf);
}

/**
* \brief   This function sets the base address for the chip select spcified.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param   addr           Chip Select Base address.Value can range from
*                         0 to 0x3F\n
*
* \return  None.\n
*
*/
void  GPMCBaseAddrSet(gpmcHandle hGpmc, Uint32 csNum, Uint32 addr)
{
  	volatile Uint32 *gpmcCfg7;

	gpmcCfg7 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG7_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg7, GPMC_CONFIG7_0_BASEADDR, addr);
}

/**
* \brief   This function sets the chip select mask address or size.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param  addrMask        Address Mask to set. \n
*                         This can take one of the following values :\n
*                         GPMC_CS_SIZE_256MB  -- For Chip-select size of 256 MB.\n
*                         GPMC_CS_SIZE_128MB  -- For Chip-select size of 128 MB.\n
*                         GPMC_CS_SIZE_64MB   -- For Chip-select size of 64 MB.\n
*                         GPMC_CS_SIZE_32MB   -- For Chip-select size of 32 MB.\n
*                         GPMC_CS_SIZE_16MB   -- For Chip-select size of 16 MB.\n
*
* \return  None.\n
*
*/
void  GPMCMaskAddrSet(gpmcHandle hGpmc, Uint32 csNum, Uint32 addrMask)
{
  	volatile Uint32 *gpmcCfg7;

	gpmcCfg7 = (Uint32 *)((uintptr_t)&hGpmc->CONFIG7_0 + (csNum * 0x30));

	CSL_FINS(*gpmcCfg7, GPMC_CONFIG7_0_MASKADDR, addrMask);
}

/**
* \brief   This function writes the NAND command to COMMAND register.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number for which NAND is interfaced.
*                         This can take one of the following values :
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param  cmd             COMMAND to write.
*
* \return  None.\n
*
*/
void  GPMCSNANDCmdWrite(gpmcHandle hGpmc, Uint32 csNum, Uint32 cmd)
{
  	volatile Uint32 *nandCmd;

	nandCmd = (Uint32 *)((uintptr_t)&hGpmc->NAND_COMMAND_0 + (csNum * (0x30)));

    *nandCmd = cmd;
}

/**
* \brief   This function writes the NAND address to ADDRESS register.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number for which NAND is interfaced.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param  addr            ADDRESS to write. \n
*
* \return  None.\n
*
*/
void  GPMCNANDAddrWrite(gpmcHandle hGpmc, Uint32 csNum, Uint32 addr)
{
  	volatile Uint32 *nandAddr;

	nandAddr = (Uint32 *)((uintptr_t)&hGpmc->NAND_ADDR_0 + (csNum * (0x30)));

    *nandAddr = addr;
}

/**
* \brief   This function writes the NAND data to DATA register.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number for which NAND is interfaced.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \param  data            data to write. \n
*
* \return  None.\n
*
*/
void  GPMCNANDDataWrite(gpmcHandle hGpmc, Uint32 csNum, Uint32 data)
{
  	volatile Uint32 *nandData;

	nandData = (Uint32 *)((uintptr_t)&hGpmc->NAND_DATA_0 + (csNum * (0x30)));

	*nandData = data;
}

/**
* \brief   This function reads the data from NAND DATA register.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select Number for which NAND is interfaced.\n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \return  Read NAND data.\n
*
*/
Uint32  GPMCNANDDataRead(gpmcHandle hGpmc, Uint32 csNum)
{
  	volatile Uint32 *nandData;
  	Uint32          data;

	nandData = (Uint32 *)((uintptr_t)&hGpmc->NAND_DATA_0 + (csNum * (0x30)));

    data = *nandData;

    return (data);
}

/**
* \brief   This function selects the access mode of the prefetch engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   accessMode     Access mode of prefetch engine.\n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_ACCESSMODE_READ  -- For READ Access
*                                                           mode.\n
*                         GPMC_PREFETCH_ACCESSMODE_WRITE -- For WRITE Access
*                                                            mode.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchAccessModeSelect(gpmcHandle hGpmc, Uint32 accessMode)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_ACCESSMODE, accessMode);
}

/**
* \brief   This function select the synchronization type to use on FIFO
*          threshold crossing.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   syncType       Synchronization type.\n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_SYNCTYPE_DMA  -- For DMA sync mode \n
*                         GPMC_PREFETCH_SYNCTYPE_INT  -- For INTERRUPT sync
*                                                        mode.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchSyncTypeSelect(gpmcHandle hGpmc, Uint32 syncType)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_DMAMODE, syncType);
}

/**
* \brief   This function congigs when the PREFETCH engine has to start the
*          access to CS.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   flag           Flag to specify when PREFETCH engine has to start
*                         the access to CS.\n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_ACCESSCS_AT_START       --  To start the
*                                                                   access as
*                                                                   soon as
*                                                                   STARTENGINE
*                                                                   is set.\n
*                         GPMC_PREFETCH_ACCESSCS_AT_STARTANDWAIT -- To start the
*                                                                   access as
*                                                                   soon as
*                                                                   STARTENGINE
*                                                                   is set and
*                                                                   non wait
*                                                                   edge
*                                                                   detection
*                                                                   on the
*                                                                   selected
*                                                                   wait pin.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchSyncModeConfig(gpmcHandle hGpmc, Uint32 flag)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_SYNCHROMODE, flag);
}

/**
* \brief   This function selects the wait pin edge detector to start the
*          PREFETCH engine in synchronized mode.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   waitPin        Wait pin to use for edge detector. \n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_WAITPINSELECTOR_W0 -- To Selects
*                                                             Wait0EdgeDetection\n
*                         GPMC_PREFETCH_WAITPINSELECTOR_W1 -- To Selects
*                                                             Wait1EdgeDetection\n
*
* \return  None.\n
*
*/
void GPMCPrefetchWaitPinSelect(gpmcHandle hGpmc, Uint32 waitPin)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR, waitPin);
}

/**
* \brief   This function enables the PREFETCH POSTWRITE engine. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchEngineEnable(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_ENENGINE, GPMC_BIT_ENABLE);
}

/**
* \brief   This function disable the PREFETCH POSTWRITE engine. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchEngineDisable(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_ENENGINE, GPMC_BIT_DISABLE);
}

/**
* \brief   This function sets the FIFOTHRESHOLD (maximum number of bytes read
*          from the FIFO or written to the FIFO by the host on a DMA or
*          interrupt request) value for the PREFETCH and POSTWRITE engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   fifoThrsld     FIFO threshold value. \n
*
* \return  None.\n
*
*/
void GPMCPrefetchFifoThrldValSet(gpmcHandle hGpmc, Uint32 fifoThrsld)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_FIFOTHR, fifoThrsld);
}

/**
* \brief   This function selects the chip select(CS) where Prefetch Postwrite
*          engine is active.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select. \n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchCSSelect(gpmcHandle hGpmc, Uint32 csNum)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR, csNum);
}

/**
* \brief   This function configs the access cycle optimization for PREFETCH
*          engine. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   configVal      access cycle optimization config value.\n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_OPTIMIZED_ACCESS_ENABLE  -- To enable
*                                                                   the access
*                                                                   optimization\n
*                         GPMC_PREFETCH_OPTIMIZED_ACCESS_DISABLE -- To disable
*                                                                   the access
*                                                                   optimization\n
*
* \return  None.\n
*
*/
void GPMCPrefetchAccessCycleOptConfig(gpmcHandle hGpmc,
                                      Uint32 configVal)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS, configVal);
}

/**
* \brief   This function sets the number of GPMC_FCLK cycles to be substracted
*          from RdCycleTime,WrCycleTime, AccessTime, CSRdOffTime, CSWrOffTime,
*          ADVRdOffTime,ADVWrOffTime, OEOffTime, WEOffTime for PREFETCH
*          engine cycle optimization. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   cleOptVal      Cycle optimization value. This can take value from
*                         0 to 7.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchCycleOptValSet(gpmcHandle hGpmc, Uint32 cleOptVal)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION, cleOptVal);
}

/**
* \brief   This function configs the PREFETCH and POSTWRITE ROUND
*          ROBIN arbitration. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   configVal      Round Robin arbitration config value.\n
*                         This can take one of the following values :\n
*                         GPMC_PREFETCH_RR_ARBITRATION_ENABLE   -- To enable
*                                                                  the Round
*                                                                  robin
*                                                                  arbitration\n
*                         GPMC_PREFETCH_RR_ARBITRATION_DISABLE  -- To disable
*                                                                  the Round
*                                                                  robin
*                                                                  arbitration\n
*
* \return  None.\n
*
*/
void GPMCPrefetchRRArbitrationConfig(gpmcHandle hGpmc,
                                     Uint32 configVal)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN, configVal);
}

/**
* \brief   This function sets the number of access to be granted to PREFETCH
*          engine when ROUND ROBIN arbitration. i.e When an arbitration occurs
*          between a direct memory access and a PFPW engine access, the direct
*          memory access is always serviced. If the PFPWEnRoundRobin is enabled
*          value set by this function plus one number of access is granted to
*          the PREFETCH and WRITE POST engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   accessVal      Access value to set. \n
*
* \return  None.\n
*
*/
void GPMCPrefetchWeightedPrioSet(gpmcHandle hGpmc, Uint32 accessVal)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG1,
	         GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO, accessVal);
}

/**
* \brief   This function sets the transfer count (number of bytes to be read or
*          written by the engine to the selected CS) for the PREFETCH engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   trnsCntVal     Tranfer count value. Value can range from 0 to 2000h
*                         i.e 8 KB.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchTrnsCntValSet(gpmcHandle hGpmc, Uint32 trnsCntVal)
{
	CSL_FINS(hGpmc->PREFETCH_CONFIG2,
	         GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT, trnsCntVal);
}

/**
* \brief   This function resets the FIFO pointer to 0 in prefetch mode
*           and 40h in postwrite mode starts the PREFETCH and POST WRITE engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchEngineStart(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->PREFETCH_CTRL,
	         GPMC_PREFETCH_CTRL_STARTENGINE, GPMC_BIT_SET_HIGH);
}

/**
* \brief   This function stops the PREFETCH and POST WRITE engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCPrefetchEngineStop(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->PREFETCH_CTRL,
	         GPMC_PREFETCH_CTRL_STARTENGINE, GPMC_BIT_SET_LOW);
}

/**
* \brief   This function gets the status of PREFETCH and POST WRITE engine.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  status         Prefetch engine status\n
*                            0 : If engine is stopped.\n
*                            1 : If engine is running.\n
*
*/
Uint32  GPMCPrefetchEngineStatusGet(gpmcHandle hGpmc)
{
    Uint32 status;

	status = CSL_FEXT(hGpmc->PREFETCH_CTRL,
	                  GPMC_PREFETCH_CTRL_STARTENGINE);

    return (status);
}

/**
* \brief   This function gets the number of remaining bytes to be read or to be
*          written by the engine according to the TransferCount value.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  count value.\n
*
*/
Uint32  GPMCPrefetchCountValGet(gpmcHandle hGpmc)
{
    Uint32 cntVal;

	cntVal = CSL_FEXT(hGpmc->PREFETCH_STS,
	                  GPMC_PREFETCH_STS_COUNTVALUE);

    return (cntVal);
}

/**
* \brief   This function gets the PREFETCH engine FIFO threshold status. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  stauts         Threshold status.\n
*                            1 : FIFO Pointer is greater than FIFO Threshold.\n
*                            0 : FIFO Pointer is smaller or equal to FIFO
*                                Threshold.\n
*
*/
Uint32  GPMCPrefetchFifoThrldStatusGet(gpmcHandle hGpmc)
{
    Uint32 status;

	status = CSL_FEXT(hGpmc->PREFETCH_STS,
	                  GPMC_PREFETCH_STS_FIFOTHRSTS);

    return (status);
}

/**
* \brief   This function gets the FIFO pointer value of PREFETCH engine.
*          FIFO pointer value indicates number of bytes available to be read
*          or number of free empty place to write.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  FIFO pointer value.\n
*
*/
Uint32 GPMCPrefetchFifoPtrValGet(gpmcHandle hGpmc)
{
    Uint32 fifoPtrVal;

	fifoPtrVal = CSL_FEXT(hGpmc->PREFETCH_STS,
	                      GPMC_PREFETCH_STS_FIFOPOINTER);

    return (fifoPtrVal);
}

/**
* \brief   This function selects the ECC algorithm to use for ECC error
*          detection and correction.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccAlgo        ECC algorithm to use.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_ALGORITHM_HAMMINGCODE -- For Hamming code.\n
*                         GPMC_ECC_ALGORITHM_BCH         -- For BCH.\n
* \return  None.\n
*
*/
void GPMCECCAlgoSelect(gpmcHandle hGpmc, Uint32 algo)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCALGORITHM, algo);
}

/**
* \brief   This function selects the Error correction capability used for BCH
*          ECC algorithm.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   errCorrCapVal  Error correction capability value.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_BCH_ERRCORRCAP_UPTO_4BITS  -- For Up to 4
*                                                                bits error
*                                                                 correction.\n
*                         GPMC_ECC_BCH_ERRCORRCAP_UPTO_8BITS  -- For Up to 8
*                                                                 bits error
*                                                                 correction.\n
*                         GPMC_ECC_BCH_ERRCORRCAP_UPTO_16BITS -- For Up to 16
*                                                                 bits error
*                                                                 correction.\n
*
* \return  None.\n
*
*/
void GPMCECCBCHErrCorrectionCapSelect(gpmcHandle hGpmc,
                                      Uint32 errCorrCapVal)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCBCHTSEL,
	         errCorrCapVal);
}

/**
* \brief   This function sets the wrap mode(Spare area organization definition)
*          for the ECC BCH algorithm.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   wrapModeVal    Wrap mode value. Value can range from 0x00 to 0x0F.\n
*
* \return  None.\n
*
*/
void GPMCECCBCHWrapModeValSet(gpmcHandle hGpmc, Uint32 wrapModeVal)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCWRAPMODE,
	         wrapModeVal);
}

/**
* \brief   This function selects number of columns to use for ECC calculation.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccColVal      ECC column value.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_COLUMNS_8   -- ECC calculated on 8 columns.\n
*                         GPMC_ECC_COLUMNS_16  -- ECC calculated on 16 columns.\n
*
* \return  None.\n
*
*/
void GPMCECCColumnSelect(gpmcHandle hGpmc, Uint32 eccColVal)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECC16B, eccColVal);
}

/**
* \brief   This function selects the number of sectors to process with the BCH
*          algorithm.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   numOfSects     Number of sectors.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_BCH_NUMOFSECTS_1  -- For 1 sector (512 bytes
*                                                       page).\n
*                         GPMC_ECC_BCH_NUMOFSECTS_2  -- For 2 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_3  -- For 3 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_4  -- For 4 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_5  -- For 5 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_6  -- For 6 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_7  -- For 7 sectors. \n
*                         GPMC_ECC_BCH_NUMOFSECTS_8  -- For 8 sectors
*                                                       (4KB page).\n
*
* \return  None.\n
*
*/
void GPMCECCBCHNumOfSectorsSelect(gpmcHandle hGpmc,
                                  Uint32 numOfSects)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCTOPSECTOR,
	         numOfSects);
}

/**
* \brief   This function selects the Chip-select where ECC is computed.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   csNum          Chip Select. \n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n
*
* \return  None.\n
*
*/
void GPMCECCCSSelect(gpmcHandle hGpmc, Uint32 csNum)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCCS, csNum);
}

/**
* \brief   This function Enables the ECC feature.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCECCEnable(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCEN,
	         GPMC_BIT_ENABLE);
}

/**
* \brief   This function disables the ECC feature.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCECCDisable(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->ECC_CONFIG, GPMC_ECC_CONFIG_ECCEN,
	         GPMC_BIT_DISABLE);
}

/**
* \brief   This function clears all ECC result registers.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
void GPMCECCResultRegClear(gpmcHandle hGpmc)
{
	CSL_FINS(hGpmc->ECC_CTRL, GPMC_ECC_CTRL_ECCCLR,
	         GPMC_BIT_SET_HIGH);
}

/**
* \brief   This function selects the ECC result register where the first
*          ECC computation will be stored.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccResReg      ECC result register.\n
*                         This can take one of the following values :\n
*                         GPMC_ECCPOINTER_RESULT_1 -- ECC pointer for result 1
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_2 -- ECC pointer for result 2
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_3 -- ECC pointer for result 3
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_4 -- ECC pointer for result 4
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_5 -- ECC pointer for result 5
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_6 -- ECC pointer for result 6
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_7 -- ECC pointer for result 7
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_8 -- ECC pointer for result 8
*                                                     register.\n
*                         GPMC_ECCPOINTER_RESULT_9 -- ECC pointer for result 9
*                                                     register.\n
*
* \return  None.\n
*
*/
void GPMCECCResultRegSelect(gpmcHandle hGpmc, Uint32 eccResReg)
{
	CSL_FINS(hGpmc->ECC_CTRL, GPMC_ECC_CTRL_ECCPOINTER,
	         eccResReg);
}

/**
* \brief   This function sets the ECCSIZE1 value. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccSize        ECC size for which size has to set.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_SIZE_0 -- For ECC size 0.\n
*                         GPMC_ECC_SIZE_1 -- For ECC size 1.\n
*
* \param   eccSizeVal     ECC size value.\n
*
* \return  None.\n
*
*/
void GPMCECCSizeValSet(gpmcHandle hGpmc,Uint32 eccSize,
                       Uint32 eccSizeVal)
{
    if(eccSize == GPMC_ECC_SIZE_0)
    {
		CSL_FINS(hGpmc->ECC_SIZE_CONFIG, GPMC_ECC_SIZE_CONFIG_ECCSIZE0,
				 eccSizeVal);
    }
    else if(eccSize == GPMC_ECC_SIZE_1)
    {
		CSL_FINS(hGpmc->ECC_SIZE_CONFIG, GPMC_ECC_SIZE_CONFIG_ECCSIZE1,
				 eccSizeVal);
    }
}

/**
* \brief   This function selects the ECC size for the ECC result register. \n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccResReg      ECC result register for which ECC size has to select.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_RESULT_1 -- For ECC result 1 register.\n
*                         GPMC_ECC_RESULT_2 -- For ECC result 2 register.\n
*                         GPMC_ECC_RESULT_3 -- For ECC result 3 register.\n
*                         GPMC_ECC_RESULT_4 -- For ECC result 4 register.\n
*                         GPMC_ECC_RESULT_5 -- For ECC result 5 register.\n
*                         GPMC_ECC_RESULT_6 -- For ECC result 6 register.\n
*                         GPMC_ECC_RESULT_7 -- For ECC result 7 register.\n
*                         GPMC_ECC_RESULT_8 -- For ECC result 8 register.\n
*                         GPMC_ECC_RESULT_9 -- For ECC result 9 register.\n
*
* \param   eccSize        ECC size.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_SIZE_0 -- For ECC size 0.\n
*                         GPMC_ECC_SIZE_1 -- For ECC size 1.\n
*
 \return  None.\n
*
*/
void GPMCECCResultSizeSelect(gpmcHandle hGpmc, Uint32 eccResReg,
                             Uint32 eccSize)
{
    switch(eccResReg)
    {
        case GPMC_ECC_RESULT_1:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_2:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_3:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_4:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_5:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_6:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_7:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_8:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE, eccSize);
        break;
        case GPMC_ECC_RESULT_9:
			CSL_FINS(hGpmc->ECC_SIZE_CONFIG,
			         GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE, eccSize);
        break;
    }
}

/**
* \brief   This function gets the ECC result from the ECC register.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   eccResReg      ECC result register for from which ECC value has to
*                         retrive.\n
*                         This can take one of the following values :\n
*                         GPMC_ECC_RESULT_1 -- For ECC result 1 register.\n
*                         GPMC_ECC_RESULT_2 -- For ECC result 2 register.\n
*                         GPMC_ECC_RESULT_3 -- For ECC result 3 register.\n
*                         GPMC_ECC_RESULT_4 -- For ECC result 4 register.\n
*                         GPMC_ECC_RESULT_5 -- For ECC result 5 register.\n
*                         GPMC_ECC_RESULT_6 -- For ECC result 6 register.\n
*                         GPMC_ECC_RESULT_7 -- For ECC result 7 register.\n
*                         GPMC_ECC_RESULT_8 -- For ECC result 8 register.\n
*                         GPMC_ECC_RESULT_9 -- For ECC result 9 register.\n
*
* \return  ECC result.\n
*
*/
Uint32 GPMCECCResultGet(gpmcHandle hGpmc, Uint32 eccResReg)
{
    Uint32          res;
   	volatile Uint32 *eccRes;

   	eccRes = (Uint32 *)(&hGpmc->ECC1_RESULT + ((eccResReg - 1) * 0x4));

    res = *eccRes;

    return (res);
}

/**
* \brief   This function gets the BCH result.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   resIndex       BCH ECC result index.\n
*                         This can take one of the following values :\n
*                         GPMC_BCH_RESULT_0 -- For BCH result 0.\n
*                         GPMC_BCH_RESULT_1 -- For BCH result 1.\n
*                         GPMC_BCH_RESULT_2 -- For BCH result 2.\n
*                         GPMC_BCH_RESULT_3 -- For BCH result 3.\n
*                         GPMC_BCH_RESULT_4 -- For BCH result 4.\n
*                         GPMC_BCH_RESULT_5 -- For BCH result 5.\n
*                         GPMC_BCH_RESULT_6 -- For BCH result 6.\n
*
* \param   csNum          Chip Select. \n
*                         This can take one of the following values :\n
*                         GPMC_CHIP_SELECT_0 -- For Chip Select 0.\n
*                         GPMC_CHIP_SELECT_1 -- For Chip Select 1.\n
*                         GPMC_CHIP_SELECT_2 -- For Chip Select 2.\n
*                         GPMC_CHIP_SELECT_3 -- For Chip Select 3.\n
*                         GPMC_CHIP_SELECT_4 -- For Chip Select 4.\n
*                         GPMC_CHIP_SELECT_5 -- For Chip Select 5.\n
*                         GPMC_CHIP_SELECT_6 -- For Chip Select 6.\n
*                         GPMC_CHIP_SELECT_7 -- For Chip Select 7.\n

* \return  ECC result.\n
*
*/
Uint32 GPMCECCBCHResultGet(gpmcHandle hGpmc, Uint32 resIndex, Uint32 csNum)
{
    Uint32           res;
    volatile Uint32 *bchResReg;

    res = 0;

    switch(resIndex)
    {
        case GPMC_BCH_RESULT_0:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT0_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_1:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT1_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_2:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT2_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_3:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT3_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_4:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT4_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_5:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT5_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
        case GPMC_BCH_RESULT_6:
        	 bchResReg = (Uint32 *)((uintptr_t)&hGpmc->BCH_RESULT6_0 + (csNum * 0x10));
             res = *bchResReg;
        break;
    }

    return (res);
}

/**
* \brief   This function write the data to BCH_SWDATA register. This is used
*          to directly padd data to the BCH ECC calculator without accessing
*          the actual NAND flash interface.\n
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \param   bchData        BCH data to be included in the BCH calculation.
*                         Only bits 0 to 7 are taken into account, if
*                         the calculator is configured to use 8 bits data
*                         using GPMCECCColumnSelect function.\n
*
* \return  None.\n
*
*/
void GPMCECCBCHSWDataWrite(gpmcHandle hGpmc, Uint32 bchData)
{
	CSL_FINS(hGpmc->BCH_SWDATA, GPMC_BCH_SWDATA_BCH_DATA, bchData);
}

/**
* \brief   This function read the data from BCH_SWDATA register.
*
* \param   hGpmc          GPMC handle pointing to register base address.\n
*
* \return  None.\n
*
*/
Uint32 GPMCECCBCHSWDataRead(gpmcHandle hGpmc)
{
    Uint32 bchData;

    bchData = CSL_FEXT(hGpmc->BCH_SWDATA, GPMC_BCH_SWDATA_BCH_DATA);

    return (bchData);
}

/***************************** End Of File ***********************************/
