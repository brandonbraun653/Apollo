/*
 * Copyright (C) 2002-2010 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/** ===========================================================================
 *   @file  csl_sgmii.c
 *
 *   @brief File containing functional layer API's of SGMII.
 *
 *   @path  $(CSLPATH)\src\SGMII
 *
 *   @desc  The function definition of the API's of SGMII.
 */

/* =============================================================================
 * Revision History
 * ===============
 *  01-May-2006 NS  updated the file for DOXYGEN compatibiliy
 *  12-Jan-2006 PSK file created
 * =============================================================================
 */


/*
 * SGMII module is not needed for OMAPL13x platform as Gigabit mode is not supported.
 * But buildlib.xs is picking all the source files inside v0 which causes the OMAPL13x
 * XDC make build failure. Excluding the code for OMAPL13x platform here as a
 * temporary workaroud.
*/
#if (!defined(SOC_OMAPL137) && !defined(SOC_OMAPL138))

#include <ti/csl/csl_cpsgmii.h>
#include <ti/csl/csl_emac.h>
#include <ti/csl/csl_bootcfg.h>
/* Hardware Platform Configuration Header. */
#include <ti/drv/emac/emac_hwcfg.h>
/* EMAC Driver API Header. */
#include <ti/drv/emac/emac_drv.h>
#include "inc/emac_loc.h"


Uint32 SGMII_reset ()
{
    CSL_FINST(SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_SOFT_RESET, YES);
    while (SGMII_REGS->SOFT_RESET != 0x00000000);

    return 0;
}


Uint32 SGMII_config (SGMII_Config *config)
{
    volatile Uint32 val, tempReg;

    if (!config) {
        return SGMII_ERROR_INVALID;
    }

	SGMII_REGS->SOFT_RESET = 0x00000003;
	while (SGMII_REGS->SOFT_RESET != 0x00000000);

    if (config->loopbackEn) {
		SGMII_REGS->CONTROL = 0x34;
		SGMII_REGS->MR_ADV_ABILITY = 0x9801;
        /*CSL_FINS(SGMII_REGS->CONTROL, SGMII_CONTROL_MR_AN_ENABLE, 0);
        CSL_FINST(SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_RT_SOFT_RESET, YES);
        CSL_FINST(SGMII_REGS->CONTROL, SGMII_CONTROL_LOOPBACK, YES);
        CSL_FINST(SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_RT_SOFT_RESET, NO);*/
    }else {
        if ((config->masterEn) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITH_AN)) {
            SGMII_REGS->MR_ADV_ABILITY = 0x9801; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT(SGMII_CONTROL_MASTER, MASTER) |
                                  CSL_FMKT(SGMII_CONTROL_MR_AN_ENABLE, YES);
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE);
        }else if ((!(config->masterEn)) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITH_AN)) {
            SGMII_REGS->MR_ADV_ABILITY = 0x01; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT(SGMII_CONTROL_MASTER, SLAVE) |
                                  CSL_FMKT(SGMII_CONTROL_MR_AN_ENABLE, YES);
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE);
        }else if ((config->masterEn) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITHOUT_AN)) {
            SGMII_REGS->MR_ADV_ABILITY = 0x9801; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT(SGMII_CONTROL_MASTER, MASTER) |
                                  CSL_FMK(SGMII_CONTROL_MR_AN_ENABLE, 0);
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE);
        }else {
            SGMII_REGS->MR_ADV_ABILITY = 0x01; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT(SGMII_CONTROL_MASTER, SLAVE) |
                                  CSL_FMKT(SGMII_CONTROL_MR_AN_ENABLE, YES);
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE);
        }
    }

    hBootCfg->SGMII_CFGPLL = config->auxConfig;

	/* wait for 2 usfor PLL to lock */
	for(val = 0; val < 1000; val++) asm(" NOP 5 ");

    hBootCfg->SGMII_CFGTX0 = config->txConfig;

	for(val = 0; val < 10; val++) asm(" NOP 5 ");

    hBootCfg->SGMII_CFGRX0 = config->rxConfig;

    return 0;
}


Uint32 SGMII_getStatus (SGMII_Status *status)
{
    if (!status) {
        return SGMII_ERROR_INVALID;
    }
    status->txCfgStatus = SGMII_REGS->TX_CFG;
    status->rxCfgStatus = SGMII_REGS->RX_CFG;
    status->auxCfgStatus = SGMII_REGS->AUX_CFG;
    return 0;
}


Uint32 SGMII_getLinkPartnerStatus ()
{

    if (CSL_FEXT(SGMII_REGS->STATUS, SGMII_STATUS_MR_AN_COMPLETE)){
        return (SGMII_REGS->MR_LP_ADV_ABILITY & 0xFFFF);
    }

    return SGMII_ERROR_DEVICE;
}


Uint32 SGMII_getAnErrorStatus ()
{
    return CSL_FEXT(SGMII_REGS->STATUS, SGMII_STATUS_AN_ERROR);
}


Uint32 SGMII_getStatusReg ()
{
    Uint32 status;

    status = SGMII_REGS->STATUS;
    return status;
}

#endif  /* #if (!defined(SOC_OMAPL137) || !defined(SOC_OMAPL138)) */


