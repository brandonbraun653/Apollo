/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef _I2C_TEST_UTILS_H
#define _I2C_TEST_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/board.h>
#include "I2C_log.h"

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

#define I2C_EEPROM_ADDR_SIZE            (2)           /* in bytes */
#define I2C_EEPROM_TEST_LENGTH          (10)          /* Read (and write) test in bytes */

#define I2C_EEPROM_INSTANCE             (0)
#define I2C_EEPROM_ADDR                 (0x50)
#define I2C_SMBUS_DEV_ADDR              (0x22)
#define WRITE_SMBUS_COMMAND_CODE        (0x84)
#define READ_SMBUS_COMMAND_CODE         (0x80)
#define I2C_EEPROM_TEST_ADDR            (0x0001)      /* Read and write test start address */

#define I2C_TRANSACTION_TIMEOUT         (10000U)

#if defined(idkAM572x) || defined(idkAM574x)
#define I2C_TEST_INSTANCE1            (5U)           /* in bytes */
#elif defined(icev2AM335x) || defined(bbbAM335x)
#define I2C_TEST_INSTANCE1            (3U)           /* in bytes */
#elif defined(idkAM437x)
#define I2C_TEST_INSTANCE1            (3U)           /* in bytes */
#define I2C_TEST_INSTANCE2            (4U)           /* in bytes */
#endif

#define Sleep Task_sleep
/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Data compare function */
bool CompareData(char *expData, char *rxData, unsigned int length);

/* function to test each features of i2c fw */
int32_t i2c_feature_test(uint32_t i2cInst, I2C_BitRate dataRate, uint32_t slaveAddr, bool smbusEnable);
void printTestCase(uint32_t testId, uint32_t i2cInst, I2C_BitRate dataRate);

#if defined(idkAM437x)
/* Configure pin mux for unused I2C PRU GPI/GPO pins */
void pruGpioMuxConfigI2cUnused(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _I2C_TEST_UTILS_H */
