/**
 *  \file  sbl_am335x_platform.c
 *
 * \brief  This file contain functions which compute ASCII for standard
 *         operations.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "soc_control.h"
#include "board.h"
#include "soc.h"
#include "wdt.h"
#include "soc_am335x.h"
#include "hw_cm_wkup.h"
#include "hw_cm_per.h"
#include "hw_control_am335x.h"
#include "console_utils.h"
#include "sbl_am335x_platform_ddr.h"
#include "sbl_am335x_platform_pll.h"
#include "sbl_platform.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#ifdef PRU_WKUP
static void PRU_ICSS_PRCM_Enable(void);
#endif

void SBLPlatformConfig(void)
{
    uint32_t deviceVersion = 0U;
    uint32_t dynPwrDown = FALSE;
    uint32_t status = E_FAIL;
    boardInitParams_t boardInitPrms;

    deviceVersion = (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_DEVICE_ID) >>
                    CONTROL_DEVICE_ID_DEVREV_SHIFT);

    if(deviceVersion > 1U)
    {
        dynPwrDown = TRUE;
    }

    status = BOARDInit(NULL);
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    boardInitPrms.boardId = BOARDGetId();

    if(BOARD_UNKNOWN == boardInitPrms.boardId)
    {
        /*
         * TBD: If UNKNOWN board is detected?.
         */
    }

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

	/* TODO: Enable WDT module clock in prcm */
    HW_WR_REG32((SOC_WDT_1_REGS + WDT_WSPR) , 0xAAAAU);
    while(HW_RD_REG32(SOC_WDT_1_REGS + WDT_WWPS) != 0x00U);

    HW_WR_REG32((SOC_WDT_1_REGS + WDT_WSPR) , 0x5555U);
    while(HW_RD_REG32(SOC_WDT_1_REGS + WDT_WWPS) != 0x00U);

    /* Set the PLL0 to generate 300MHz for ARM */
    SBLPlatformPllInit(boardInitPrms.boardId);

    /* Enable the control module */
    HW_WR_REG32((SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL) ,
            CM_WKUP_CONTROL_CLKCTRL_MODULEMODE_ENABLE);

    /* DDR Initialization */
#ifndef DDRLESS
    SBLPlatformDdrInit(dynPwrDown,boardInitPrms.boardId);
#endif 

#ifdef PRU_WKUP
	PRU_ICSS_PRCM_Enable();
#endif

    /* Enable clock for Timer4 for SYS/BIOS application usage */
    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER4_CLKCTRL,
                 CM_PER_L4LS_CLKSTCTRL,
                 CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER4_GCLK);
}

#ifdef PRU_WKUP
static void PRU_ICSS_PRCM_Enable(void)
{
	const void * prussPruDramBase = (void *)SOC_PRU_ICSS_DATA_RAM0;
	const void * prussSharedDramBase = (void *)SOC_PRU_ICSS_SHARED_RAM;

	/* Reset the PRU ICSS and enable clock */
	PRCMModuleEnable(CHIPDB_MOD_ID_PRU_ICSS, 0, FALSE);
	memset((void *)prussPruDramBase, 0, (16*1024));
	memset((void *)prussSharedDramBase, 0, (12*1024));
}
#endif

/*
 * \brief This function does any post boot setup/init
 *
 * \param  none
 *
 * \return none
*/
void SBLPlatformConfigPostBoot(void)
{
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
