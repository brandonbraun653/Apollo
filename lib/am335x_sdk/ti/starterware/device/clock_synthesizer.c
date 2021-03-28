/**
 * \file   clock_synthesizer.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         Clock Synthesizer CDCE913.
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
#include "error.h"
#include "device.h"
#include "ethernet.h"
#include "cpsw.h"
#include "chipdb_defs.h"
#include "chipdb.h"
#include "i2c_utils.h"
#include "board.h"
#include "console_utils.h"
#include "delay_utils.h"
#include "clock_synthesizer.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Macro indicating the i2c time out value. */
#define I2C_TIMEOUT_VAL           (1000000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t ClockSynthesizerRegRead(uint8_t registerAddr, uint8_t *readBuf)
{
    uint32_t retVal = S_PASS;
    uint32_t instNum = 0U;
    i2cUtilsTxRxParams_t i2cClkSynthTxRxParams;

    registerAddr |= 0x80U;

    i2cClkSynthTxRxParams.slaveAddr   = CLOCK_SYNTHESIZER_I2C_ADDR;
    i2cClkSynthTxRxParams.pOffset     = (uint8_t *)&registerAddr;
    i2cClkSynthTxRxParams.offsetSize  = 1U;
    i2cClkSynthTxRxParams.bufLen      = 1U;
    i2cClkSynthTxRxParams.pBuffer     = (uint8_t *)readBuf;

    /* Send the Command Byte via I2C write call */
    retVal = I2CUtilsWrite(instNum, &i2cClkSynthTxRxParams, I2C_TIMEOUT_VAL);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Failed to send command to clock Synthesizer ");
    }

    /* Read data */
    retVal = I2CUtilsRead(instNum, &i2cClkSynthTxRxParams, I2C_TIMEOUT_VAL);

    return retVal;
}

uint32_t ClockSynthesizerRegWrite(uint8_t registerAddr, uint8_t writeData)
{
    uint32_t retVal = S_PASS;
    uint8_t cmd[2];
    uint32_t instNum = 0U;
    i2cUtilsTxRxParams_t i2cClkSynthTxRxParams;

    /* Register Address */
    cmd[0] = (registerAddr | 0x80U);
    /* Register Data */
    cmd[1] = writeData;

    i2cClkSynthTxRxParams.slaveAddr   = CLOCK_SYNTHESIZER_I2C_ADDR;
    i2cClkSynthTxRxParams.pOffset     = (uint8_t *)&registerAddr;
    i2cClkSynthTxRxParams.offsetSize  = 1U;
    i2cClkSynthTxRxParams.bufLen      = 2U;
    i2cClkSynthTxRxParams.pBuffer     = (uint8_t *)&cmd;

    /* Send register address and data */
    retVal = I2CUtilsWrite(instNum, &i2cClkSynthTxRxParams, I2C_TIMEOUT_VAL);

    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer:Send Reg Address&Data:Failed");
    }

    return retVal;
}

uint32_t ClockSynthesizerSetup()
{
    uint32_t retVal = E_FAIL;
    uint8_t regValue = 0U;
    uint32_t instNum = 0U;

    i2cUtilsInitParams_t i2cClockSynthParams = I2CUTILSINITPARAMS_DEFAULT;

    /* Initialize the I2C Bus */
    retVal = I2CUtilsInit(instNum, &i2cClockSynthParams);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Initialization: Failed");
    }

    retVal = ClockSynthesizerRegRead(CLOCK_SYNTHESIZER_ID_REG, &regValue);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Read: Failed");
    }

    if((regValue & 0x81U)!= 0x81U)
    {
        return E_FAIL;
    }

    /** CDCE913 Clock Synthesizer configuration for RMII Clock = 50 MHz
     * fout = fin/Pdiv x N/M
     * fout = 50 MHz
     * fin  = 25 MHz
     * Pdiv = 2
     * N    = 4
     * M    = 1
     */

    /* Crystal load Capacitor Selection - 18pF: 0x12h(bits 7:3) */
    retVal = ClockSynthesizerRegWrite(CLOCK_SYNTHESIZER_XCSEL, 0x90U);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Write: Failed");
    }

    /* PLL1 Multiplexer b7:0 (PLL1) */
    retVal = ClockSynthesizerRegWrite(CLOCK_SYNTHESIZER_MUX_REG, 0x6DU);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Write: Failed");
    }

    /** b7-0(PLL1 SSC down selection by default),
     *  b6:0-0x02h(7-bit Y2-Output-Divider Pdiv2)
     */
    retVal = ClockSynthesizerRegWrite(CLOCK_SYNTHESIZER_PDIV2_REG, 0x02U);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Write: Failed");
    }

    /* b6:0-0x02h(7-bit Y3-Output-Divider Pdiv3) */
    retVal = ClockSynthesizerRegWrite(CLOCK_SYNTHESIZER_PDIV3_REG, 0x02U);
    if (E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("\n Clock synthesizer: Write: Failed");
    }
    return retVal;
}
