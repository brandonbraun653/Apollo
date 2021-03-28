/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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

/**
 * \file    PowerPMMC_deviceInit.c
 *
 * \brief   This file contains the utility functions to download the PMMC
 *          firmware and initialize the device modules via the PMMC.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>

#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>

#include <PowerPMMC_deviceInit.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

pmlibSysConfigPmmcPowerStateParams_t inputTable[] =
{{PMHAL_PMMC_MOD_PMMC,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MLB0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DSS0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MCBSP0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MCASP0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MCASP1,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MCASP2,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DCAN0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DCAN1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EMIF0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MMCHS0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MMCHS1,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_GPMC0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ELM0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SPI0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SPI1,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SPI2,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SPI3,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ICSS0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ICSS1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_USB0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_USB1,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_NSS0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_PCIE0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_OTP0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_GPIO0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_GPIO1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_0,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_1,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_2,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_3,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_4,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_5,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TIMER64_6,              MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SEC_MGR0,               MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MSGMGR0,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_BOOTCFG0,               MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ARM_BOOTROM0,           MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DSP_BOOTROM0,           MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DEBUGSS0,               MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_UART0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_UART1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_UART2,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM0,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM1,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM2,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM3,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM4,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EHRPWM5,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EQEP0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EQEP1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EQEP2,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ECAP0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ECAP1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_I2C0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_I2C1,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_I2C2,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_CP_TRACER0,             MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_CP_TRACER1,             MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EDMA0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EDMA1,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SEMAPHORE0,             MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_INTC0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_GIC0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_QSPI0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_ARM_64B_COUNTER0,       MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_TETRIS0,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_CGEM0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_MSMC0,                  MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_DFS_SS0,                MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_CBASS0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_SMARTREFLEX0,           MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_EFUSE0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_BOARD0,                 MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_CIC0,                   MSG_DEVICE_SW_STATE_ON},
 {PMHAL_PMMC_MOD_PSC0,                   MSG_DEVICE_SW_STATE_ON}
};

const uint32_t numTableEntries = sizeof (inputTable) /
                                 sizeof (pmlibSysConfigPmmcPowerStateParams_t);

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PMMC_InitModulePowerState()
{
    int32_t                       retVal = PM_SUCCESS;
    pmlibSysConfigPmmcErrReturn_t resultReturn[sizeof (inputTable) /
                                  sizeof(pmlibSysConfigPmmcPowerStateParams_t)];

    retVal = PMLIBSysConfigPmmcSetPowerState(inputTable,
                                             (uint32_t) numTableEntries,
                                             PM_TIMEOUT_INFINITE,
                                             resultReturn);

    return retVal;
}

int32_t PMMC_ConfigFirmware(const void *pImage, uint32_t imageSize)
{
    int32_t status = PM_SUCCESS;
    int32_t timeout = PMHAL_PMMC_TIMEOUT_DEFAULT;

    if ((pImage == NULL) || (imageSize == 0))
    {
        status = PM_BADARGS;
    }
    else
    {
        status = PMHALPmmcLoad(pImage, imageSize);

        if (status == PM_SUCCESS)
        {
            status = PMHALPmmcStart(timeout);
        }

        if (status == PM_SUCCESS)
        {
            status = PMHALPmmcInterfaceInit();
        }

        if (status == PM_SUCCESS)
        {
            status = PMHALMsgmgrInit();
        }

        if (status == PM_SUCCESS)
        {
            status = PMHALPmmcCommsValidate(timeout);
        }
    }

    return status;
}

int32_t PMMC_CleanupFirmware(void)
{
    int32_t status = PM_SUCCESS;

    status = PMHALPmmcInterfaceClose();

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


