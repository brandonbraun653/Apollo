/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *
 * \file    adc_am65xx.h
 *
 * \brief  This is the header file for adc diagnostic test.
 *
 */

#ifndef _ADC_AM65XX_H_
#define _ADC_AM65XX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/csl/src/ip/adc/V0/adc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <soc.h>

#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"

#if defined(am65xx_evm)
#include "src/am65xx_evm/am65xx_evm_pinmux.h"
#elif defined(am65xx_idk)
#include "src/am65xx_idk/am65xx_idk_pinmux.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_OF_ADC            (2U)
#define ADC0_CHANNEL_NO        (8U)
#define ADC1_CHANNEL_NO        (1U)

#define ADC_MAX_RANGE       (0xFFF)
#define ADC_REF_VOLTAGE     (1800U) /* ref voltage level */

typedef struct adcDetails
{
    uint32_t baseAddress;
    uint8_t channelNo;
}adcDetails_t;

/**
 *  \brief    The function performs adc test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_ADCTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ADC_AM65XX_H_ */
