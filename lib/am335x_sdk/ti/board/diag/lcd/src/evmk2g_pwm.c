/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 * \file    evmck2g_pwm.c
 *
 * \brief   This file contains functions for pwm driver
 *
 ******************************************************************************/

#include "platform_internal.h"

#if (PLATFORM_PWM_IN)

/******************************************************************************
 **                          GLOBAL DEFINITIONS
 ******************************************************************************/

hEcapHandle hEcap = (hEcapHandle)CSL_ECAP_0_CFG_REGS;
hPwmssHandle hPwmss = (hPwmssHandle)CSL_PWM_0_CFG_REGS;

#define CSL_ECAP_FIXED 0 //TODO Has to be revisited after fixing CSL.

#if !(CSL_ECAP_FIXED)
static void reg_wr_32(Uint32 baseAddr,Uint32 writeData)
{
  (*(Uint32 *) (baseAddr)) = writeData;
}

static Uint32 reg_rd_32(Uint32 baseAddr)
{
  Uint32 read_data;
  read_data = (*(Uint32 *) (baseAddr));
  return read_data;
}
#endif

/******************************************************************************
 **                      INTERNAL FUNCTION DEFINITIONS
 ******************************************************************************/

/**
 *
 * \brief    This function initializes the ECAP module and PWM driver.
 *           It also enables the backlight with 50% duty cycle.
 *
 * No parameters.
 *
 * \return   ECAP_SUCCESS	- On Success
 *           ECAP_ERR		- On Failure
 *
 */
int8_t pwmInit(void)
{
#if !(CSL_ECAP_FIXED)
	Uint32 baseAddr = 0;
	Uint32 value = 0;
#endif

    pinMuxSetMode(221, 4);

    /* TODO ECAP control registers and interrupt registers are 16 bit.
     * But its wrongly defined as 32 bit registers in cslr_ecap.h.
     * Until a fix for that is in place, we will hardcode the ECCTL registers
     */

#if !(CSL_ECAP_FIXED) //Comment the code after fixing CSL
    baseAddr = CSL_ECAP_0_CFG_REGS;

    value = reg_rd_32(baseAddr + ECAP_ECCTL1);
	value = value >> 16;
	value |= (ECAP_ECCTL2_APWM_MODE << 9) |
			(ECAP_ECCTL2_SYNCO_SEL_DISABLE << 6) |
			(ECAP_ECCTL2_APWM_POLARITY << 10) |
			(ECAP_ECCTL2_FREERUN_ENABLE << 4);

	reg_wr_32(baseAddr + ECAP_ECCTL1, value << 16);

	pwmSetDutyCycle(50);
#endif


#if (CSL_ECAP_FIXED) //TODO Uncomment the code after fixing CSL

	/* Configure ECAP module to operate in APWM mode */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE);

	/* Disable sync out */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_SYNCO_SEL, ECAP_ECCTL2_SYNCO_SEL_DISABLE);

	/* Configure ECAP to generate PWM waveform with 50% duty cycle. */
	pwmSetDutyCycle(50);

	/* Configures output polarity for APWM output. ECAP_PWM_OUT pin as High */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_APWMPOL, ECAP_ECCTL2_APWM_POLARITY);

	/* Disable APWM mode */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE_DISABLE);

	/* Configures counter to free running */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_TSCTRSTOP, ECAP_ECCTL2_FREERUN_ENABLE);

	/* Configure ECAP module to operate in APWM mode */
	CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE);
#endif

	return ECAP_SUCCESS;
}

/**
 *
 * \brief    This function is used to set the duty cycle of the PWM waveform.
 *
 * \param    dutyCycle [IN] : Value of the duty cycle to be set.
 *                      50  - 50% duty cycle.
 *                      75  - 75% duty cycle.
 *
 * \return   ECAP SUCCESS	- On Success.
 *           ECAP_ERR		- On Failure.
 *
 */
int8_t pwmSetDutyCycle(uint8_t dutyCycle)
{
	uint32_t acmpValue;

	if (dutyCycle <= 100)
	{
		acmpValue = ECAP_CAP1_APRD_VALUE;
		acmpValue = ((acmpValue * dutyCycle) / 100);

		/* Configure ECAP to generate PWM waveform with dutyCycle */
		CSL_FINS(hEcap->CAP1, ECAP_CAP1_CAP1, ECAP_CAP1_APRD_VALUE);
		CSL_FINS(hEcap->CAP2, ECAP_CAP2_CAP2, acmpValue);

		//platform_write("LCD brightness - %d percent\n", dutyCycle);
		return ECAP_SUCCESS;
	}

	IFPRINT (platform_write("pwmSetDutyCycle: Invalid input - "
	                        "dutyCycle is more than 100\n"));

	return ECAP_ERR;
}

#endif /* #if (PLATFORM_PWM_IN) */
