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

/**
 *  \file   uart_stress_test.h
 *
 *  \brief  UART diagnostic stress test header file.
 *
 */
 
#ifndef _UART_STRESS_TEST_H_
#define _UART_STRESS_TEST_H_

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <tistdtypes.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"

#include "board_i2c_io_exp.h"

#define BAUDRATE_MAX     (115200)
#define TEST_DATA_LEN    (10*1024*1024)   /* 10MB of transmit data */
#define FIFO_SIZE        (256)


/**
 * \brief  UART stress test function
 *
 * This function initializes the specified UART instance for running
 * the stress test, based on a configuration parameters specified.
 * Writes data from the data buffer to the transmitter FIFO of UART
 * and reads data from the receiver FIFO to read buffer in the receiver.
 * Compares the read and write buffers to verify the data.
 *
 * \param   uartInstance  [IN]  UART instance
 *          setPort       [IN]  Variable to set the port number
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_UartStressTest(uint32_t uartInstance, uint8_t setPort);

#endif /* _UART_STRESS_TEST_H_ */
