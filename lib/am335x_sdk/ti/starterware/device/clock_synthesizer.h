/**
 *  \file  clock_synthesizer.h
 *
 *  \brief This file contains the use case specific function declarations.
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

#ifndef _CLOCK_SYNTHESIZER_H_
#define _CLOCK_SYNTHESIZER_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* I2C Instance Controlling Clock Synthesizer */
#define CLOCK_SYNTHESIZER_I2C_INST_NUM  0

/* Clock Synthesizer Device Address */
#define CLOCK_SYNTHESIZER_I2C_ADDR      0x65

#define CLOCK_SYNTHESIZER_ID_REG        0

/* Crystal load capacitor selection */
#define CLOCK_SYNTHESIZER_XCSEL         0x05

/* PLL1 Configuration Register */
#define CLOCK_SYNTHESIZER_MUX_REG       0x14

/* PDIV2 */
#define CLOCK_SYNTHESIZER_PDIV2_REG     0x16

/* PDIV3 */
#define CLOCK_SYNTHESIZER_PDIV3_REG     0x17

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This routine reads data from CDCE913 Clock Synthesizer device
 *          through I2C.
 *
 * \param   readBuf       Read data buffer
 * \param   registerAddr  Address
 *
 * \retval  S_PASS    on reading the data successfully
 * \retval  E_FAIL    on Error reading data
 **/
uint32_t ClockSynthesizerRegRead(uint8_t registerAddr, uint8_t *readBuf);


/**
 * \brief   This routine writes data to CDCE913 Clock Synthesizer.
 *          It takes the buffer to be written as a parameter and length
 *          of the buffer.
 *
 * \param   registerAddr   Register address for writing data
 * \param   writeData      Write data
 *
 * \retval  S_PASS    on reading the data successfully
 * \retval  E_FAIL    on Error reading data
 **/
uint32_t ClockSynthesizerRegWrite(uint8_t registerAddr, uint8_t writeData);


/**
 * \brief   Set up 50MHz clock for RMII Phy from Clock synthesizer which is
 *          Operated through I2C.
 *
 * \retval  S_PASS    on reading the data successfully
 * \retval  E_FAIL    on Error reading data
 **/
uint32_t ClockSynthesizerSetup();

#ifdef __cplusplus
}
#endif

#endif /* #ifndef __CLOCK_SYNTHESIZER_H_ */
