/**
 *  \file  sbl_am43xx_platform.c
 *
 * \brief  This file contain functions to configure the platform.
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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
#include "am437x.h"
#include "hw_cm_wkup.h"
#include "hw_control_am43xx.h"
#include "console_utils.h"
#include "sbl_am43xx_platform_ddr.h"
#include "sbl_am43xx_platform_pll.h"
#include "sbl_platform.h"
#include "device.h"
#include "pmic_device.h"

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

extern int32_t PMICDeviceTps65218RegWrite(uint32_t devId,
                                   uint32_t devInst,
                                   uint32_t regAddr,
                                   uint32_t regVal);

void SBLPlatformConfig(void)
{
    uint32_t status = E_FAIL;
    boardInitParams_t boardInitPrms;

    status = BOARDInit(NULL);
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    boardInitPrms.boardId = BOARDGetId();

    if(BOARD_UNKNOWN == boardInitPrms.boardId)
    {
        /*
         * If UNKNOWN board is detected force it to GP EVM.
         */
        boardInitPrms.boardId = BOARD_GPEVM;
        boardInitPrms.baseBoardRev = BOARD_REV_UNKNOWN;
        boardInitPrms.dcBoardRev = BOARD_REV_UNKNOWN;
        CONSOLEUtilsPrintf("UNKNOWN Board detected. Forcing to GP EVM...\n");
        status = BOARDInit(&boardInitPrms);
        CONSOLEUtilsPrintf("Forced BOARDInit status [0x%x]\n", status);
    }

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* TODO: Enable WDT module clock in prcm */
    HW_WR_REG32((SOC_WDT1_REG + WDT_WSPR) , 0xAAAAU);
    while(HW_RD_REG32(SOC_WDT1_REG + WDT_WWPS) != 0x00U);

    HW_WR_REG32((SOC_WDT1_REG + WDT_WSPR) , 0x5555U);
    while(HW_RD_REG32(SOC_WDT1_REG + WDT_WWPS) != 0x00U);

    /* Set the PLL0 to generate 300MHz for ARM */
    SBLPlatformPllInit(boardInitPrms.boardId);

    /* Enable the control module */
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_WKUP_CTRL_CLKCTRL) ,
            PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_ENABLE);
    /* TODO: Need to wait till the module is enabled */

    if(BOARD_GPEVM == boardInitPrms.boardId)
    {
        status = PMICInit();
        if (S_PASS == status)
        {
            /* The default voltage in the DCDC3 rail of PMIC is 1.5V for GPEVM.
             * Changing the rail voltage to 1.35V by updating the DCDC3 control register
             * with 0x12U will set the voltage to 1.35V
             */
            PMICDeviceTps65218RegWrite(DEVICE_ID_PMIC_TPS65218, 0, DCDC3_CONTROL_REG,
                    DCDC3_OUTPUT_1_35V);
        }
    }

    /* DDR Initialization */
    SBLPlatformDdrInit(boardInitPrms.boardId);
}

void SBLPlatformConfigPostBoot(void)
{
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
