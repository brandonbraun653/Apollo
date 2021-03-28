/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 * \file   evmk2g_pwm.h
 *
 * \brief  This is the header file for pwm driver
 *
 ******************************************************************************/

#ifndef _EVMK2G_PWM_H_
#define _EVMK2G_PWM_H_

/** Handle to access ECAP registers */
typedef CSL_EcapRegs *hEcapHandle;

/** Handle to access PWMSS registers */
typedef CSL_PwmssRegs *hPwmssHandle;


/*ECAP register offsets*/
#define ECAP_TSCTR		(0x00U)
#define ECAP_CTRPHS		(0x04U)
#define ECAP_CAP1		(0x08U)
#define ECAP_CAP2		(0x0CU)
#define ECAP_CAP3		(0x10U)
#define ECAP_CAP4		(0x14U)
#define ECAP_ECCTL1		(0x28U)
#define ECAP_ECCTL2		(0x2AU)
#define ECAP_ECEINT		(0x2CU)
#define ECAP_ECFLG		(0x2EU)
#define ECAP_ECCLR		(0x30U)
#define ECAP_ECFRC		(0x32U)
#define ECAP_REVID		(0x5CU)


/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

#define ECAP_ECCTL2_APWM_MODE	        (0x1U)
#define ECAP_ECCTL2_APWM_MODE_DISABLE   (0x0U)
#define ECAP_TSCTR_COUNT		        (0x10000U)
#define ECAP_ECCTL2_APWM_POLARITY       (0x1U)
#define ECAP_ECCTL2_FREERUN_ENABLE      (0x1U)
#define ECAP_CAP1_APRD_VALUE		    (0x1000U)
#define ECAP_CAP2_ACMP_VALUE		    (0x500U)
#define ECAP_ECCTL2_SYNCO_SEL_DISABLE	(0x3U)

/** Macros definitons for error and success */
#define ECAP_ERR			(-1)
#define ECAP_SUCCESS		(0)

#define PWM_ECAP_CLK_EN         (0x01)
#define ECAP_PRESCALE_6			(0x03)


/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

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
int8_t pwmInit(void);

/**
 *
 * \brief    This function is used to set the duty cycle of the PWM waveform.
 *
 * \param    dutyCycle [IN] : Value of the duty cycle to be set.
 *                      50  : 50% duty cycle.
 *                      75  : 75% duty cycle.
 *
 * \return   ECAP SUCESS	- On Success.
 *           ECAP_ERR		- On Failure.
 *
 */
int8_t pwmSetDutyCycle(uint8_t dutyCycle);

#endif /* _EVMK2G_PWM_H_ */
