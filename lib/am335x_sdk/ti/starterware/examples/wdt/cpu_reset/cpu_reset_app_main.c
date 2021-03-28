/**
 * \file   cpu_reset_app_main.c
 *
 * \brief  Example application main source file, which configures the WDT IP
 *         and executes the CPU reset use case. On overflow of the Watchdog
 *         timer a reset will occur on the CPU.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *            http://www.ti.com/
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
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "wdt.h"
#include "console_utils.h"

/* Application header files */
#include "wdt_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/**
 * \name    Macros used by the WDT CPU reset application.
 */

/** @{ */
/** \brief Counter value to be programmed. */
#define INITIAL_COUNT_VALUE          (0xFFFE0000u)

/** \brief Reload count value to be programmed. */
#define RELOAD_COUNT_VALUE           (0xFFFE0000u)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Fetch the WDT instance address.
 *
 * \param     pObj       Pointer to the WDT application configuration
 *                       structure.
 *                       #wdtAppCfgObj_t
 *
 * \retval    #S_PASS - WDT instance is present.
 * \retVal    #E_FAIL - WDT instance is not present.
 */
static int32_t WdtAppSocInfoGet(wdtAppCfgObj_t *pObj);

/**
 * \brief     WDT CPU reset.
 *
 * \details   This function shall accept a character from the user and on doing
 *            this the WDT counter shall be reloaded. If a key is not pressed
 *            within 4 seconds then the counter will overflow and cause a reset
 *            on the CPU.
 *
 * \param     pObj       Pointer to the WDT application configuration
 *                       structure.
 *                       #wdtAppCfgObj_t
 */
static void WdtAppCpuReset(wdtAppCfgObj_t *pObj);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Application default configuration */
static const wdtAppCfgObj_t WDTAPPCPURESET_DEFAULT =
{
    1U,                                      /* instNum.*/
    0U,                                      /* instAddr.*/
    WDT_PRESCALER_CLK_DIV_1,                 /* prescaler.*/
    INITIAL_COUNT_VALUE,                     /* counterVal.*/
    RELOAD_COUNT_VALUE,                      /* reloadVal.*/
    {
        TRUE                                 /* enablePrescaler.*/
    }
};

/** \brief Global object for the WDT CPU reset application. */
static wdtAppCfgObj_t gCpuResetAppCfg;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = E_FAIL;

    gCpuResetAppCfg = WDTAPPCPURESET_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare WDT CPU Reset Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    if (S_PASS == status)
    {
        /* Print SoC & Board Information. */
        SOCPrintInfo();
        BOARDPrintInfo();

        /* Get board info */
        status = WdtAppSocInfoGet(&gCpuResetAppCfg);

        if (S_PASS == status)
        {
            /* Initialize the WDT application. */
            WDTAppInit(&gCpuResetAppCfg);

            /* CPU Reset logic. */
            WdtAppCpuReset(&gCpuResetAppCfg);
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\r\nFAILURE!!!\r\n");
        CONSOLEUtilsPrintf("This example is not supported on this board\n");
    }

    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t WdtAppSocInfoGet(wdtAppCfgObj_t *pObj)
{
    int32_t status = E_FAIL;
    uint32_t maxNumInst = CHIPDBModuleMaxInstanceNumber(CHIPDB_MOD_ID_WDT);

    CONSOLEUtilsPrintf("\r\nTotal WDT instances present = %d\n", maxNumInst);

    while (maxNumInst > 0)
    {
        if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_WDT, (maxNumInst - 1U)))
        {
            pObj->instNum = (maxNumInst - 1U);
            status = S_PASS;
            break;
        }
        else
        {
            --maxNumInst;
        }
    }

    if (S_PASS == status)
    {
        if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_WDT, pObj->instNum))
        {
            /* Read the WDT instance base address. */
            pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_WDT, pObj->instNum);
            CONSOLEUtilsPrintf("The instance address is %x\n", pObj->instAddr);

            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\r\nFAILURE!!!\r\n");
        CONSOLEUtilsPrintf("The WDT instance number %d ", pObj->instNum);
        CONSOLEUtilsPrintf("is not present on the SOC\n");
    }

    return(status);
}

static void WdtAppCpuReset(wdtAppCfgObj_t *pObj)
{
    uint32_t trigVal = 0u;
    uint32_t inputVal = 0u;

    /* Send the message to UART console */
    CONSOLEUtilsPrintf("Program Reset!");
    CONSOLEUtilsPrintf("Input ENTER key at least once in every 4 seconds");
    CONSOLEUtilsPrintf(" to avoid a further reset.\n\r");

    while(1)
    {
        /* Wait for an input through console. If no input is given,
        ** the WDT will timeout and reset will occur.
        */
        if(S_PASS == CONSOLEUtilsScanf("%c", &inputVal))
        {
            trigVal += 1;

            /* Write into the trigger register. This will load the value from the
            ** load register into the counter register and hence timer will start
            ** from the initial count.
            */
            WatchdogTimerTriggerSet(pObj->instAddr, trigVal);
        }
    }
}
