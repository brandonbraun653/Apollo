/**
 * \file   pm_app.c
 *
 * \brief  Source file containing the PM related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
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
#include "pm_app.h"
#include "pmic_device.h"
#include "hw_cm_wkup.h"
#include "am437x.h"
#include "hw_cm_wkup.h"
#include "pm_app_types.h"
#include "i2c.h"
#include "chipdb.h"
#include "prcm.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define PM_APP_CTRL_NUM_IOPAD_REGS          (295U)

#define PM_APP_UTILS_NUM_PIN                (2U)

#define PM_APP_PIN_UART0_RXD                (0x0970U)

#define PM_APP_PIN_UART0_TXD                (0x0974U)

#define PM_APP_PIN_I2C0_SDA                 (0x0988U)

#define PM_APP_PIN_I2C0_SCL                 (0x098cU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*
** Structure to map selection of IO Pad for power down configuration
*/
typedef struct pmAppIoPadMap
{
    uint32_t ioPad;
    uint32_t sel;
}pmAppIoPadMap_t;

/*
** Structure to store the control register context. More registers
** can be added to this if need to be saved.
*/
typedef struct pmAppCtrlRegCntxt
{
    uint32_t uartConsolePin[PM_APP_UTILS_NUM_PIN];
    uint32_t i2cPins[PM_APP_UTILS_NUM_PIN];
    pmAppIoPadMap_t ioPadMap[PM_APP_CTRL_NUM_IOPAD_REGS];
}pmAppCtrlRegCntxt_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void PmAppSaveCtrlRegCntxt(pmAppCtrlRegCntxt_t *pIoPadCntxt);

void PmAppRestoreCtrlRegCntxt(pmAppCtrlRegCntxt_t *pIoPadCntxt);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

pmAppOppTable_t gPmAppAm43xxOppTable[] =
{
    {300U, 950U, PM_APP_OPP_50},
    {600U, 1100U, PM_APP_OPP_100},
    {720U, 1200U, PM_APP_OPP_120},
    {800U, 1260U, PM_APP_OPP_TURBO},
    {1000U, 1325U, PM_APP_OPP_NITRO}
};

pmAppCtrlRegCntxt_t gPmAppIoPadCntxt;

i2cCtx_t gI2CCntxt;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void PMAppMinOppConfig()
{
    pmAppOppTable_t *pPmAppMinOpp;

    /* Get the Minimum OPP for the device. */
    pPmAppMinOpp = PMAppGetOpp(PM_APP_OPP_MIN);

    /* Reduce the MPU frequencey to lower the system OPP.*/
    PMAppSetMpuFreq(pPmAppMinOpp->mpuFreq);

    /* Set the voltage for the VDD_MPU */
    PMICSetRailVoltage(PMIC_DEVICE_RAIL_TYPE_MPU, pPmAppMinOpp->voltage);

    /* Set the voltage for the VDD_CORE */
    PMICSetRailVoltage(PMIC_DEVICE_RAIL_TYPE_CORE, pPmAppMinOpp->voltage);
}

void PMAppSetMpuFreq(uint32_t mpuFreq)
{
    volatile uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU,
        PRCM_CM_CLKMODE_DPLL_MPU_EN, PRCM_CM_CLKMODE_DPLL_MPU_EN_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */
    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU,
        PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS));

    /* Clear the MULT and DIV field of DPLL_MPU register */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_MPU_MULT, mpuFreq);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_MPU_DIV, 25U);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_MPU,
        PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT, 1U);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU,
        PRCM_CM_CLKMODE_DPLL_MPU_EN, PRCM_CM_CLKMODE_DPLL_MPU_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU,
        PRCM_CM_IDLEST_DPLL_MPU_ST_CLK));
}

void PMAppOppConfig(uint32_t oppVal)
{
    pmAppOppTable_t *pPmAppOpp;

    /* Get the voltage and frequency pair for the OPP value. */
    pPmAppOpp = PMAppGetOpp(oppVal);

    /* Set the voltage for the VDD_MPU */
    PMICSetRailVoltage(PMIC_DEVICE_RAIL_TYPE_MPU, pPmAppOpp->voltage);

    /* Set the voltage for the VDD_CORE */
    PMICSetRailVoltage(PMIC_DEVICE_RAIL_TYPE_CORE, pPmAppOpp->voltage);

    /* Restore the MPU frequencey to system OPP.*/
    PMAppSetMpuFreq(pPmAppOpp->mpuFreq);
}

pmAppOppTable_t* PMAppGetOpp(uint32_t oppVal)
{
    uint32_t idx = 0U;
    uint32_t count = (sizeof(gPmAppAm43xxOppTable)/sizeof(gPmAppAm43xxOppTable[0]));
    pmAppOppTable_t *pOppPair;

    for(idx = 0; idx < count; idx++)
    {
        if(oppVal == gPmAppAm43xxOppTable[idx].oppVal)
        {
            pOppPair = &gPmAppAm43xxOppTable[idx];
        }
    }

    return pOppPair;
}

void PMAppSavePeripheralCntxt(uint32_t slpMode, uint32_t wakeSource)
{
    switch(slpMode)
    {
        case PM_APP_SLEEP_MODE_DS0:

            /* Save the Peripherals IO pin context. */
            PmAppSaveCtrlRegCntxt(&gPmAppIoPadCntxt);

            /* Save the system Utils Context.*/
            PmAppSaveUtilsCntxt();
            break;

        default:
        break;
    }
}

void PMAppRestorePeripheralCntxt(uint32_t slpMode, uint32_t wakeSource)
{
    switch(slpMode)
    {
        case PM_APP_SLEEP_MODE_DS0:

            /* Save the Peripherals IO pin context. */
            PmAppRestoreCtrlRegCntxt(&gPmAppIoPadCntxt);

            /* Save the system Utils Context.*/
            PmAppRestoreUtilsCntxt();
            break;

        default:
        break;
    }
}

void PmAppSaveUtilsCntxt(void)
{
    uint32_t i2cBaseAddr = 0U;

    /* Get the I2C module base Address. */
    i2cBaseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_I2C, 0U);

    /* Save the I2C context for the Utils */
    I2CContextSave(i2cBaseAddr, &gI2CCntxt);

    /* Save the IO pin context for I2C and UART utils. */
    gPmAppIoPadCntxt.uartConsolePin[0] = HW_RD_REG32(SOC_CONTROL_MODULE_REG +
                                            PM_APP_PIN_UART0_RXD);
    gPmAppIoPadCntxt.uartConsolePin[1] = HW_RD_REG32(SOC_CONTROL_MODULE_REG +
                                            PM_APP_PIN_UART0_TXD);
    gPmAppIoPadCntxt.i2cPins[0] = HW_RD_REG32(SOC_CONTROL_MODULE_REG +
                                            PM_APP_PIN_I2C0_SDA);
    gPmAppIoPadCntxt.i2cPins[1] = HW_RD_REG32(SOC_CONTROL_MODULE_REG +
                                            PM_APP_PIN_I2C0_SCL);
}

void PmAppRestoreUtilsCntxt(void)
{
    uint32_t i2cBaseAddr = 0U;

    /*Reenable the I2C module Clock. */
    PRCMModuleEnable(CHIPDB_MOD_ID_I2C, 0U, FALSE);

    /* Get the I2C module base Address. */
    i2cBaseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_I2C, 0U);

    /* Restore the I2C Context. */
    I2CContextRestore(i2cBaseAddr, &gI2CCntxt);

    /* Reenable the UART Module Clock */
    PRCMModuleEnable(CHIPDB_MOD_ID_UART, 0U, FALSE);

    /* Restore the Pinmux for UART console port */
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + PM_APP_PIN_UART0_RXD,
        gPmAppIoPadCntxt.uartConsolePin[0]);
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + PM_APP_PIN_UART0_TXD,
        gPmAppIoPadCntxt.uartConsolePin[1]);
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + PM_APP_PIN_I2C0_SDA,
        gPmAppIoPadCntxt.i2cPins[0]);
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + PM_APP_PIN_I2C0_SCL,
        gPmAppIoPadCntxt.i2cPins[1]);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void PmAppSaveCtrlRegCntxt(pmAppCtrlRegCntxt_t *pIoPadCntxt)
{
    uint32_t idx = 0U;

    for(idx = 0; idx < PM_APP_CTRL_NUM_IOPAD_REGS; idx++)
    {
        pIoPadCntxt->ioPadMap[idx].ioPad =
                                         HW_RD_REG32(SOC_CONTROL_MODULE_REG +
                                             (idx * 4));
    }
}

void PmAppRestoreCtrlRegCntxt(pmAppCtrlRegCntxt_t *pIoPadCntxt)
{
    uint32_t idx = 0U;

    for(idx = 0U; idx < PM_APP_CTRL_NUM_IOPAD_REGS; idx++)
    {
        HW_WR_REG32(SOC_CONTROL_MODULE_REG + (idx * 4),
            pIoPadCntxt->ioPadMap[idx].ioPad);
    }
}
