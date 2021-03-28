/**
 *  \file  board.c
 *
 * \brief  This file contains the implementation of board information for
 *         AM335x based boards.
 *
 *  \copyright Copyright (C) 2018-2019 Texas Instruments Incorporated -
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

#include "board_cfg.h"

#include "types.h"
#include "error.h"
#include "hw_types.h"
#include "hw_emif4d.h"
#include "soc_am335x.h"
#include "hw_cm_per.h"
#include "hw_cm_device.h"
#include "hw_control_am335x.h"
#include "board.h"
#include "soc.h"
#include "device.h"

#include <ti/starterware/include/board.h>
#include <ti/starterware/include/hw/hw_wdt.h>
#include <ti/starterware/include/am335x/hw_cm_wkup.h>

#define BOARD_AM335X_GPEVM_BOARD_NAME	"A33515BB"
#define BOARD_AM335X_ICEV2_BOARD_NAME	"A335_ICE"
#define BOARD_AM335X_AMIC110_BOARD_NAME	"ICE110"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

Board_IDInfo gboardInfo;

/* ========================================================================== */
/*                          Internal Function Definitions                     */
/* ========================================================================== */

extern Board_STATUS Board_getIDInfo(Board_IDInfo *info);
extern void socPlatformPllInit(uint32_t boardId);

void socPlatformConfig(void)
{
	uint32_t deviceVersion = 0U;
    boardInitParams_t boardInitPrms;
	Board_STATUS status;

	boardInitPrms.boardId = BOARD_UNKNOWN;

    deviceVersion = (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_DEVICE_ID) >>
                    CONTROL_DEVICE_ID_DEVREV_SHIFT);
	status = Board_getIDInfo(&gboardInfo);
	if (S_PASS == status)
	{
		/* Set NULL character as the last character for the name. */
		gboardInfo.boardName
						[20 - 1] = '\0';
		/* Check if the board is GPEVM */
		if (!(strcmp(BOARD_AM335X_GPEVM_BOARD_NAME,
                    (char *)gboardInfo.boardName)))
			boardInitPrms.boardId = BOARD_GPEVM;
		/* Check if the board is ICEV2AM335x */	
		else if (!(strcmp(BOARD_AM335X_ICEV2_BOARD_NAME,
                    (char *)gboardInfo.boardName)))
			boardInitPrms.boardId = BOARD_ICEV2;
			/* Check if the board is ICEAMIC110 */	
		else if (!(strcmp(BOARD_AM335X_AMIC110_BOARD_NAME,
                    (char *)gboardInfo.boardName)))
			boardInitPrms.boardId = BOARD_AMIC110;
	}
    HW_WR_REG32((SOC_WDT_1_REGS + WDT_WSPR) , 0xAAAAU);
    while(HW_RD_REG32(SOC_WDT_1_REGS + WDT_WWPS) != 0x00U);

    HW_WR_REG32((SOC_WDT_1_REGS + WDT_WSPR) , 0x5555U);
    while(HW_RD_REG32(SOC_WDT_1_REGS + WDT_WWPS) != 0x00U);

    /* Set the PLL0 to generate 300MHz for ARM */
    socPlatformPllInit(boardInitPrms.boardId);

    /* Enable the control module */
    HW_WR_REG32((SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL) ,
            CM_WKUP_CONTROL_CLKCTRL_MODULEMODE_ENABLE);

    /* Enable clock for Timer4 for SYS/BIOS application usage */
    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER4_CLKCTRL,
                 CM_PER_L4LS_CLKSTCTRL,
                 CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER4_GCLK);
}	
