/*
 * Copyright (c) 2010-2015, Texas Instruments Incorporated
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
 * \file  evmc66x_i2c_eeprom.c
 *
 * \brief Provides a polling i2c driver.
 *
 ******************************************************************************/

/************************
 * Include Files
 ************************/
#include "platform_internal.h"

#if (PLATFORM_I2C_EEPROM_IN)

/************************
 * Globals
 ************************/
uint8_t gI2cBlock[68];

/******************************************************************************
 *
 * Function:	i2cEepromWriteBlock
 *
 * Description:	Writes a specified number of bytes to EEPROM. 2 bytes of write
 *              offset is expected in the first location of 'puiData'.
 *              Data will be written to EEPROM with MSB first. 'uiNumBytes' is
 *              expected to be actual number of data bytes plus write offset
 *              length (2bytes)
 *
 * Parameters:	uint8_t uchEepromI2cAddress - i2c address of EEPROM
 * 				uint32_t *puiData           - Pointer to buffer base address
 * 				uint32_t uiNumBytes         - Number of bytes of buffer
 * 				uint32_t uiEndBusState      - State on which bus should be left
 * 				uint8_t i2cportnumber       - i2c port number
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromWriteBlock( uint8_t uchEepromI2cAddress, uint32_t *puiData,
		                     uint32_t uiNumBytes, uint32_t uiEndBusState,
		                     uint8_t i2cportnumber)
{
	I2C_RET  uiReturnValue;
	uint32_t writeOffset;

	writeOffset = *puiData++;

	uiReturnValue = i2cWriteLong(i2cportnumber, uchEepromI2cAddress,
		                         puiData, writeOffset, 2, (uiNumBytes-2),
		                         uiEndBusState);

  	return (uiReturnValue);

} // i2cEepromWriteBlock

/******************************************************************************
 *
 * Function:	i2cEepromRead
 *
 * Description:	Reads a fixed number of bytes from an I2C EEPROM. The read
 *              consists of a master write of 2 bytes (forming a 16 bit address,
 *              msb transmitted first), followed by a master read of the
 *              input number of bytes.
 *
 * Parameters:	uint8_t uchEepromI2cAddress - i2c address of EEPROM
 * 				uint8_t *puiData            - Pointer to buffer base address
 * 				uint32_t uiNumBytes         - Number of bytes of buffer
 * 				uint32_t uiEndBusState      - State on which bus should be left
 * 				uint8_t i2cportnumber       - i2c port number
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromRead ( uint32_t byte_addr, uint32_t uiNumBytes,
		                uint8_t *puiData, uint8_t uchEepromI2cAddress,
		                uint8_t i2cportnumber)
{
  	I2C_RET uiReturnValue;

  	uiReturnValue = i2cRead (i2cportnumber, uchEepromI2cAddress, puiData,
                             byte_addr, 2, uiNumBytes);

  	return (uiReturnValue);

} // i2cEepromRead

/******************************************************************************
 *
 * Function:	i2cEepromWrite
 *
 * Description:	Writes specified number of bytes to the I2C EEPROM. 2 bytes of
 *              write offset is expected in the first location of 'puiData'.
 *              'uiNumBytes' is expected to be number of data bytes in 'puiData'
 *              excluding the first location.
 *              Data will be written to EEPROM with MSB first.
 *
 * Parameters:	uint8_t uchEepromI2cAddress - i2c address of EEPROM
 * 				uint32_t *puiData           - Pointer to buffer base address
 * 				uint32_t uiNumBytes         - Number of bytes of buffer
 * 				uint32_t uiEndBusState      - State on which bus should be left
 * 				uint8_t i2cportnumber       - i2c port number
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromWrite( uint16_t uchEepromI2cAddress, uint32_t *puiData,
		                uint32_t uiNumBytes, uint32_t uiEndBusState,
		                uint8_t i2cportnumber)
{
  	uint32_t uiBytesWritten;
  	uint32_t uiBlockCount;
  	uint32_t uiSizeBytes;
  	uint32_t uiAddress;
  	I2C_RET  iret;

  	uiSizeBytes    = uiNumBytes;
  	uiAddress      = *puiData;
  	uiBytesWritten = 0;

	puiData++;
  	/* Block the data into 64 byte blocks, perform a write */
  	do{
    	/* Get the number of bytes in the current block */
    	uiBlockCount = uiSizeBytes - uiBytesWritten;
    	if (uiBlockCount > 64)
    	{
      		uiBlockCount = 64;
		}

    	if (uiBlockCount == 0)
    	{
      		break;
		}

		iret = i2cWriteLong(i2cportnumber, uchEepromI2cAddress,
		                    (puiData + uiBytesWritten/4), uiAddress,
		                    2, uiBlockCount, uiEndBusState);
    	if (iret != I2C_RET_OK)
    	{
      		return (iret);
		}

		i2cDelay(DELAY_CONST);

    	uiBytesWritten = uiBytesWritten + uiBlockCount;
    	uiAddress = uiAddress + uiBlockCount;

  	} while (uiBlockCount);

  	return (I2C_RET_OK);
} // i2cEepromWrite

/******************************************************************************
 *
 * Function:	i2cEepromWriteByteAddr
 *(Same as above function except it takes byte address as a parameter)
 *
 * Description:	Writes specified number of bytes from the I2C EEPROM
 *
 * Parameters:	uint8_t uchEepromI2cAddress - i2c address of EEPROM
 * 				uint8_t *puiData            - Pointer to buffer base address
 * 				uint32_t uiNumBytes         - Number of bytes of buffer
 * 				uint32_t uiEndBusState      - State on which bus should be left
 * 				uint8_t i2cportnumber       - i2c port number
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromWriteByteAddr( uint32_t byte_addr, uint16_t uchEepromI2cAddress,
                                uint8_t *puiData, uint32_t uiNumBytes,
                                uint32_t uiEndBusState, uint8_t i2cportnumber)
{
  	uint32_t uiBytesWritten;
  	uint32_t uiBlockCount;
  	uint32_t uiCount;
  	uint32_t uiSizeBytes;
  	uint32_t uiAddress;
  	I2C_RET  iret;

  	uiSizeBytes    = uiNumBytes;
  	uiAddress      = byte_addr;
  	uiBytesWritten = 0;

  	/* Block the data into 64 byte blocks, perform a write */
  	do{
    	/* Get the number of bytes in the current block */
    	uiBlockCount = uiSizeBytes - uiBytesWritten;
    	if (uiBlockCount > 64)
    	{
      		uiBlockCount = 64;
		}

    	if (uiBlockCount == 0)
    	{
      		break;
		}

		for (uiCount = 0; uiCount < uiBlockCount; uiCount++)
		{
			gI2cBlock[uiCount + 2] = puiData[uiBytesWritten + uiCount];
		}

		gI2cBlock[0] = (uiAddress >> 8) & 0xff;
		gI2cBlock[1] = uiAddress & 0xff;

		iret = i2cWrite(i2cportnumber, uchEepromI2cAddress, gI2cBlock,
		                (uiBlockCount+2), uiEndBusState);
    	if (iret != I2C_RET_OK)
    	{
      		return (iret);
    	}

		i2cDelay(0x100);

    	uiBytesWritten = uiBytesWritten + uiBlockCount;
    	uiAddress = uiAddress + uiBlockCount;

  	} while (uiBlockCount);

  	return (I2C_RET_OK);
} //i2cEepromWriteByteAddr

/******************************************************************************
 *
 * Function:  	i2cEepromMacWrite
 *
 * Description:	Writing MAC addresses to EEPROM.
 *
 * Parameters:	uint8_t *puchSrc - pointer to mac address
 * 				uint8_t i2cportnumber - The i2c port number
 * 				uint16_t macI2cAddress - i2c address of EEPROM block
 *                                       containing MAC address details
 * 				uint16_t macOffset     - Offset of MAC address in EEPROM
 * 				uint8_t macSize        - Size of MAC address
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromMacWrite( uint8_t *puchSrc, uint8_t i2cportnumber,
                           uint16_t macI2cAddress, uint16_t macOffset,
                           uint8_t macSize)
{
    uint32_t uiIndex;
    I2C_RET returnValue;

    for(uiIndex = 0; uiIndex < macSize; uiIndex++)
    {
    	gI2cBlock[uiIndex + 2] = puchSrc[uiIndex];
    }

    gI2cBlock[0] = ((macOffset & 0xFF00) >> 8);
    gI2cBlock[1] = (macOffset & 0xFF);

    returnValue = i2cWrite(i2cportnumber, macI2cAddress, gI2cBlock,
    		               (macSize + 2), I2C_RELEASE_BUS);

    return (returnValue);
}

/******************************************************************************
 *
 * Function:  	i2cEepromMacRead
 *
 * Description:	API to read MAC addresses from I2C EEPROM
 *
 * Parameters:  uint8_t *puchDst - pointer to buffer for reading mac address
 * 				uint8_t i2cportnumber    - The i2c port number
 * 				uint16_t macI2cAddress - i2c address of EEPROM block
 *                                       containing MAC address details
 * 				uint16_t macOffset     - Offset of MAC address in EEPROM
 * 				uint8_t macSize        - Size of MAC address
 *
 * Return Value:   I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cEepromMacRead(uint8_t *puchDst, uint8_t i2cportnumber,
                         uint16_t macI2cAddress, uint16_t macOffset,
                         uint8_t macSize)
{
    I2C_RET returnValue;

    returnValue = i2cRead (i2cportnumber, macI2cAddress, puchDst,
    		               macOffset, 2, macSize);

    return (returnValue);
}

#endif
