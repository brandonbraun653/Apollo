/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   ext_rtc_test.h
 *
 * \brief  This is the header file for RTC diagnostic test.
 *
 */
#ifndef _EXT_RTC_TEST_H_
#define _EXT_RTC_TEST_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/soc.h>

#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Time and Date Register Address */
#define SEC_REG 							(0x00U)
#define MIN_REG 							(0x01U)
#define HOUR_REG							(0x02U)
#define WEEK_REG 							(0x03U)
#define DATE_REG							(0x04U)
#define MONTH_REG 							(0x05U)
#define YEAR_REG							(0x06U)

/* Mask value */
#define SECOND_MASK_VALUE					(0x7FU)
#define MINUTES_MASK_VALUE					(0x7FU)
#define HOUR_MASK_VALUE						(0x1FU)
#define TIME_MODE_12_HOUR					(0x40U)
#define MERIDIEM_MASK						(0x20U)
#define WEEK_MASK_VALUE						(0x07U)
#define DATE_MASK_VALUE						(0x3FU)
#define MONTH_MASK_VALUE					(0x1FU)
#define YEAR_MASK_VALUE						(0xFFU)

#define DELAY								(100U)
#define MSEC_DELAY							(5000U)

typedef struct
{
    uint8_t seconds;
    /** Time value in minutes. */
    uint8_t minutes;
    /** Time value in seconds */
    uint8_t hour;
	/** Time value in hour */
    uint8_t timeMode;
	/** Hour Mode to represent either
        12 Hour mode or 24 Hour mode. */
    uint8_t meridiemMode;
	/** Meridiem type to indicate either AM mode or PM mode */
}rtcTimeObj;

typedef struct
{
	uint8_t day;
	/** Value to represent the day of the week */
    uint8_t date;
	/** Value to represent the Date. */
    uint8_t month;
	/** Value to represent the Month. */
    uint8_t year;    
	/** Value to represent the Year. */
}rtcDateObj;

/**
 *  \brief    This function is used to generate delays.
 *
 *  \param    delayValue          [IN]   Delay count.
 *
 */
#if (defined(SOC_AM65XX))
void BoardDiag_AppDelay(uint32_t delayVal);
#endif

/**
 *  \brief    This function performs RTC test by writing and on the time, date,
 *            week and year registers and displays it on the serial console.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_RtcTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _EXT_RTC_TEST_H_ */
