/*
 * Copyright (c) 2011-2017, Texas Instruments Incorporated
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
 * \file  evmc64x_i2c_eeprom.h
 *
 * \brief Provides definitions and	prototypes local to the	i2c module.
 *
 ******************************************************************************/

#ifndef	_EVM66X_I2C_EEPROM_H_
#define	_EVM66X_I2C_EEPROM_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************
 * Defines and Macros
 ************************/

// EEPROM salve address
#define EEPROM_SLAVE_ADDR_50   	(0x50)
#define EEPROM_SLAVE_ADDR_51   	(0x51)

/************************
 * Function declarations
 ************************/
I2C_RET	i2cEepromWriteBlock( uint8_t uchEepromI2cAddress, uint32_t *puiData,
							 uint32_t uiNumBytes, uint32_t uiEndBusState,
							 uint8_t i2cportnumber);

I2C_RET	i2cEepromRead ( uint32_t byte_addr, uint32_t uiNumBytes,
						uint8_t *puiData, uint8_t uchEepromI2cAddress,
						uint8_t i2cportnumber);

I2C_RET	i2cEepromWrite( uint16_t uchEepromI2cAddress, uint32_t *puiData,
						uint32_t uiNumBytes, uint32_t uiEndBusState,
						uint8_t i2cportnumber);

I2C_RET i2cEepromWriteByteAddr( uint32_t byte_addr, uint16_t uchEepromI2cAddress,
						        uint8_t *puiData, uint32_t uiNumBytes,
						        uint32_t uiEndBusState, uint8_t i2cportnumber);

I2C_RET i2cEepromMacWrite( uint8_t *puchSrc, uint8_t i2cportnumber,
                           uint16_t macI2cAddress, uint16_t macOffset,
                           uint8_t macSize);
I2C_RET i2cEepromMacRead(uint8_t *puchDst, uint8_t i2cportnumber,
                         uint16_t macI2cAddress, uint16_t macOffset,
                         uint8_t macSize);

#ifdef __cplusplus
}
#endif

#endif // _EVM66X_I2C_EEPROM_H_
