/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/** \file board_clocks.c
 *
 *  \brief AM65x EVM Board library clock config file.
 *
 *  PSC(Power Sleep Controller) provides user with an 
 *  interface to control several important power and clock operations.
 *
 *  To minimize device power consumption, the clocks can be gated 
 *  (turned off), or the power to the modules can be switched off, when they
 *  are not in use. Independent power and clock control of modules allows
 *  turning ON and OFF specific sections of the device without affecting
 *  other parts.
 *
 *  Features: 1.) Provides software interface to
 *                  - Control module power ON or OFF and
 *                  - Control module clock ON or OFF.
 *
 *            2.) Supports emulation features: power, clock, and reset.
 *
 *  PSC: The Power Sleep Controller is the device has several power domains
 *  that can be turned ON for operation or OFF to minimize power dissipation,
 *  which includes a Global Power Sleep Controller(GPSC) and Local Power
 *  Sleep Controller(LPSC).
 * 
 *  GPSC: Global Power Sleep Controller, is used to control the power gating
 *  of various power domains.
 * 
 *  LPSC: Local Power Sleep Controller, manages the clock gating for to each 
 *  logic block. For modules with a dedicated clock or multiple clocks, the 
 *  LPSC communicates with the PLL controller to enable and disable that
 *  module's clock(s) at the source. For modules that share a clock with
 *  other modules, the LPSC controls the clock gating logic for each module.    
 */

#include "board_clock.h"
#include <ti/drv/sciclient/sciclient.h>

#ifdef DISABLE_SCI_CLK_CONFIG
/**
 *  \brief    This function is used to set the requested power domain state
 *            and module state for the requested power domain and module
 *            respectively of the main Power Sleep Controller(PSC).
 *
 *  \param    pdId      [IN]   Power Domain ID.
 *  \param    mdId      [IN]   Module ID.
 *  \param    pdState   [IN]   This parameter is used to configure power 
 *                             domian states i.e; either to OFF state (or)
 *                             ON state.
 *  \param    mdState   [IN]   This parameter is used to configure module 
 *                             states i.e; either to SwRstDisable state (or)
 *                             Enable state.
 *
 * \return    bool
 * \n         true   -  power domain state and module state got changed
 * \n         false  -  power domain state and module state not changed
 */
static bool set_main_psc_State(uint32_t pdId, uint32_t mdId,
            uint32_t pdState, uint32_t mdState)
{
    volatile uint32_t *mdCtl;
    volatile uint32_t *mdStat;
    volatile uint32_t *pdCtl;
    volatile uint32_t *pdStat;
	
	volatile uint32_t loopCnt = 0;
    uint32_t addressOffset = 0;
    
    if (*((uint32_t*)MAIN_PSC_BASE) != PSC_PID)
    {
        addressOffset = MAIN_PSC_ADDR_OFFSET;
    }

	mdCtl  = (volatile uint32_t *)(MAIN_PSC_MDCTL_BASE  + ( 4 * mdId ) + addressOffset);
	mdStat = (volatile uint32_t *)(MAIN_PSC_MDSTAT_BASE + ( 4 * mdId ) + addressOffset);
	pdCtl  = (volatile uint32_t *)(MAIN_PSC_PDCTL_BASE  + ( 4 * pdId ) + addressOffset);
	pdStat = (volatile uint32_t *)(MAIN_PSC_PDSTAT_BASE + ( 4 * pdId ) + addressOffset);

	/* If state is already set, do nothing */
	if ( (( *pdStat & 0x1 ) == pdState) && (( *mdStat & 0x1f ) == mdState) )
	{        
		return true;
	}

	/* Wait for GOSTAT to clear */
	while( (loopCnt < PSC_TIMEOUT) &&
    (*(volatile uint32_t*)(MAIN_PSC_PTSTAT + addressOffset) & (0x1 << pdId)) != 0 )
	{
		loopCnt++;
	}
	
	/* Check if we got timeout error while waiting */
	if (loopCnt >= PSC_TIMEOUT)
	{
		return false;
	}
	
	/* Set pdCtl NEXT to new state */
	*pdCtl = ((*pdCtl) & ~(0x1)) | pdState;	

	/* Set mdCtl NEXT to new state */
	*mdCtl = ((*mdCtl) & ~(0x1f)) | mdState;
	
	/* Start power transition by setting PTCMD GO to 1 */
	*((uint32_t*)(MAIN_PSC_PTCMD+addressOffset)) =
    (*(uint32_t*)(MAIN_PSC_PTCMD + addressOffset)) | (0x1<<pdId);
	
	loopCnt = 0;

	/* Wait for PTSTAT GOSTAT to clear */
	while( (loopCnt < PSC_TIMEOUT) &&
           (*(volatile uint32_t*)(MAIN_PSC_PTSTAT + addressOffset) & (0x1 << pdId)) != 0)
	{
		loopCnt++;
	}			

	/* Check if we got timeout error while waiting */
	if (loopCnt >= PSC_TIMEOUT)
	{
		return false;		
	}

	/* Verify power domain and module domain state got changed */
	if ((( *pdStat & 0x1 ) == pdState) && (( *mdStat & 0x1f ) == mdState))
	{
		return true;
	}

	return false;
}

/**
 *  \brief    This function is used to set the requested power domain state
 *            and module state for the requested power domain and module
 *            respectively of the wakeup Power Sleep Controller(PSC).
 *
 *  \param    pdId      [IN]   Power Domain ID.
 *  \param    mdId      [IN]   Module ID.
 *  \param    pdState   [IN]   This parameter is used to configure power 
 *                             domian states i.e; either to OFF state (or)
 *                             ON state.
 *  \param    mdState   [IN]   This parameter is used to configure module 
 *                             states i.e; either to SwRstDisable state (or)
 *                             Enable state.
 *
 * \return    bool
 * \n         true   -  power domain state and module state got changed
 * \n         false  -  power domain state and module state not changed
 */
static uint32_t set_wkup_psc_state(uint32_t pdId, uint32_t mdId,
                uint32_t pdState, uint32_t mdState)
{
    volatile uint32_t *mdCtl;
    volatile uint32_t *mdStat;
    volatile uint32_t *pdCtl;
    volatile uint32_t *pdStat;
	
	volatile uint32_t loopCnt = 0;
    
    uint32_t addressOffset = 0;
    
    if (*((uint32_t*)WAKEUP_PSC_BASE) != PSC_PID)
    {
        addressOffset = WAKEUP_PSC_ADDR_OFFSET;
    }

	mdCtl  = (volatile uint32_t *)(WAKEUP_PSC_MDCTL_BASE  + ( 4 * mdId ) +
             addressOffset);
	mdStat = (volatile uint32_t *)(WAKEUP_PSC_MDSTAT_BASE + ( 4 * mdId ) +
             addressOffset);
	pdCtl  = (volatile uint32_t *)(WAKEUP_PSC_PDCTL_BASE  + ( 4 * pdId ) +
             addressOffset);
	pdStat = (volatile uint32_t *)(WAKEUP_PSC_PDSTAT_BASE + ( 4 * pdId ) +
             addressOffset);	

	/* If state is already set, do nothing */
	if ((( *pdStat & 0x1 ) == pdState) && (( *mdStat & 0x1f ) == mdState))
	{
		return true;
	}

	/* Wait for GOSTAT to clear */
	while((loopCnt < PSC_TIMEOUT) && (*((volatile uint32_t*)(WAKEUP_PSC_PTSTAT +
         addressOffset)) & (0x1 << pdId)) != 0)
	{
		loopCnt++;
	}
	
	/* Check if we got timeout error while waiting */
	if (loopCnt >= PSC_TIMEOUT)
	{        
		return false;
	}
	
	/* Set pdCtl NEXT to new state */
	*pdCtl = ((*pdCtl) & ~(0x1)) | pdState;	

	/* Set mdCtl NEXT to new state */
	*mdCtl = ((*mdCtl) & ~(0x1f)) | mdState;
	
	/* Start power transition by setting PTCMD GO to 1 */
	(*(uint32_t*)(WAKEUP_PSC_PTCMD + addressOffset)) =
    (*(uint32_t*)(WAKEUP_PSC_PTCMD + addressOffset)) | (0x1<<pdId);
	
	loopCnt = 0;

	/* Wait for PTSTAT GOSTAT to clear */
	while((loopCnt < PSC_TIMEOUT) && (*((volatile uint32_t*)(WAKEUP_PSC_PTSTAT +
         addressOffset)) & (0x1 << pdId)) != 0 )
	{
		loopCnt++;
	}			

	/* Check if we got timeout error while waiting */
	if (loopCnt >= PSC_TIMEOUT)
	{
		return false;		
	}

	/* Verify power domain and module domain state got changed */
	if ( (( *pdStat & 0x1 ) == pdState) && (( *mdStat & 0x1f ) == mdState) )
	{
        return true;
	}

    return false;
}

/**
 * \brief clock Initialization function
 *
 * Enables different power domains and peripheral clocks of the SoC.
 * Some of the power domains and peripherals will be OFF by default.
 * Enabling the power domains is mandatory before accessing using
 * board interfaces connected to those peripherals.
 *
 * \return  BOARD_SOK              - Clock initialization sucessful. 
 *          BOARD_INIT_CLOCK_FAIL  - Clock initialization failed.
 *
 */
Board_STATUS Board_moduleClockInit(void)
{
    uint32_t i;
    uint32_t numWkupConfigs, numMainConfigs;

    Board_unlockMMR();

    numWkupConfigs = Board_getNumWkupPscCconfigs();
    numMainConfigs = Board_getNumMainPscCconfigs();

    for (i = 0; i < numWkupConfigs; i++) {
        if (set_wkup_psc_state(wkupPscConfigs[i].domainNum,
           wkupPscConfigs[i].moduleNum, PSC_PD_ON, PSC_MODSTATE_ENABLE) == 0)
            return BOARD_INIT_CLOCK_FAIL;
    }

    for (i = 0; i < numMainConfigs; i++) {
        if (set_main_psc_State(mainPscConfigs[i].domainNum,
           mainPscConfigs[i].moduleNum, PSC_PD_ON, PSC_MODSTATE_ENABLE) == 0)
            return BOARD_INIT_CLOCK_FAIL;
    }

    return BOARD_SOK;
}

#else /* #ifdef DISABLE_SCI_CLK_CONFIG */

/**
 * \brief Enables module clock
 *
 * \return  BOARD_SOK   - Clock enable sucessful. 
 *          BOARD_FAIL  - Clock enable failed.
 *
 */
Board_STATUS Board_moduleClockEnable(uint32_t moduleId)
{
    Board_STATUS retVal = BOARD_SOK;
	int32_t      status = CSL_EFAIL;
    uint32_t     moduleState = 0U;
    uint32_t     resetState = 0U;
    uint32_t     contextLossState = 0U;
    
    /* Get the module state. 
       No need to change the module state if it
       is already ON 
     */
    status = Sciclient_pmGetModuleState(moduleId,
                                        &moduleState,
                                        &resetState,
                                        &contextLossState,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(moduleState == TISCI_MSG_VALUE_DEVICE_HW_STATE_OFF)
    {
        status = Sciclient_pmSetModuleState(moduleId, 
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            (TISCI_MSG_FLAG_AOP |
                                             TISCI_MSG_FLAG_DEVICE_RESET_ISO),
                                             SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status == CSL_PASS)
        {
            status = Sciclient_pmSetModuleRst (moduleId,
                                               0x0U,
                                               SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                retVal = BOARD_FAIL;
            }
        }
        else
        {
            retVal = BOARD_FAIL;
        }
    }

    return retVal;
}

/**
 * \brief clock Initialization function
 *
 * Enables different power domains and peripheral clocks of the SoC.
 * Some of the power domains and peripherals will be OFF by default.
 * Enabling the power domains is mandatory before accessing using
 * board interfaces connected to those peripherals.
 *
 * \return  BOARD_SOK              - Clock initialization sucessful. 
 *          BOARD_INIT_CLOCK_FAIL  - Clock initialization failed.
 *
 */
Board_STATUS Board_moduleClockInit(void)
{
	Board_STATUS  status = BOARD_SOK;
    uint32_t index;
    uint32_t loopCount;

    loopCount = Board_getNumClkConfigs();

    for(index = 0; index < loopCount; index++)
    {
        status = Board_moduleClockEnable(gBoardClkModuleID[index]);
        if(status != BOARD_SOK)
        {
            status = BOARD_INIT_CLOCK_FAIL;
            break;
        }
    }

#if defined(__TI_ARM_V7R4__)
    if(status == BOARD_SOK)
    {
        int32_t  ret;
        uint64_t mcuClkFreq;

        ret = Sciclient_pmGetModuleClkFreq(TISCI_DEV_MCU_ARMSS0_CPU0,
                                           TISCI_DEV_MCU_ARMSS0_CPU0_BUS_CPU_CLK,
                                           &mcuClkFreq,
                                           SCICLIENT_SERVICE_WAIT_FOREVER);
        if(ret == 0)
        {
            Osal_HwAttrs  hwAttrs;
            uint32_t      ctrlBitmap;

            ret = Osal_getHwAttrs(&hwAttrs);
            if(ret == 0)
            {
                /*
                 * Change the timer input clock frequency configuration
                   based on R5 CPU clock configured
                 */
                hwAttrs.cpuFreqKHz = (int32_t)(mcuClkFreq/1000U);
                ctrlBitmap         = OSAL_HWATTR_SET_CPU_FREQ;
                ret = Osal_setHwAttrs(ctrlBitmap, &hwAttrs);
            }
        }
        if(ret != 0)
        {
            status = BOARD_INIT_CLOCK_FAIL;
        }
    }
#endif

    return status;
}
#endif  /* #ifdef DISABLE_SCI_CLK_CONFIG */
