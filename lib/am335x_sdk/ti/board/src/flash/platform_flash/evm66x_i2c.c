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
 * \file  evm66x_i2c.c
 *
 * \brief This contains C66x specific i2c functions.
 *
 ******************************************************************************/

 /* I2C modules */
#include "platform_internal.h"

#define CUSTOM_DELAY	0x100

#if (PLATFORM_I2C_IN)

/******************************************************************************
 *
 * Function:	i2c_check_bus_busy
 *
 * Description:	Checks the bus busy state of I2C device
 *
 * Parameters:	CSL_I2cRegs *i2cReg - I2C register base address
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
static I2C_RET i2c_check_bus_busy(CSL_I2cRegs *i2cReg)
{
  	uint32_t    timeoutCounter;
  	uint32_t    pollingStatus;

	if(i2cReg == NULL)
	{
		IFPRINT(platform_write("i2c_check_bus_busy: Invalid Register Base Address\n"));
		return (I2C_RET_INVALID_PARAM);
	}

  	/* Check for the bus busy signal */
  	timeoutCounter = 0;

  	do
  	{
    	pollingStatus = CSL_FEXT(i2cReg->ICSTR, I2C_ICSTR_BB);

    	if (pollingStatus)
    	{
      		i2cDelay (I2C_MASTER_TRANSMITTER_BUS_ACCESS_DELAY_US);

      		timeoutCounter += 1;
      		if (timeoutCounter >= I2C_MAX_MASTER_TRANSMITTER_BUS_ACCESS_TIMEOUT)
      		{
      			/* Return to slave receiver, clear nack and bus busy */
        		i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
                platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

                IFPRINT(platform_write("i2c_check_bus_busy: I2C Busy Timeout.\n"));

        		return (I2C_RET_IDLE_TIMEOUT);
      		}
    	}
    	else
    	{
    		/* The bus is free */
      		timeoutCounter = 0;
    	}
  	} while (timeoutCounter != 0);

  	return (I2C_RET_OK);

} // i2c_check_bus_busy

/******************************************************************************
 *
 * Function:	i2c_send_stop
 *
 * Description:	Sends stop bit on I2C bus
 *
 * Parameters:	CSL_I2cRegs *i2cReg - I2C register base address
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
static I2C_RET i2c_send_stop(CSL_I2cRegs *i2cReg)
{
  	uint32_t    timeoutCounter;
  	uint32_t    statusReg;

	/* Wait for the ardy bit to go high */
	timeoutCounter = 0;
	do
	{
		statusReg = i2cReg->ICSTR;
		if (I2C_REG_STR_FIELD_ARDY(statusReg))
		{
			i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMTSTOP;
			i2cReg->ICSTR = I2C_VAL_REG_STR_CLR_BUSY;
			i2cDelay (DELAY_CONST);
			timeoutCounter = 0;
		}
		else
		{
			/* Registers not ready for access */
			timeoutCounter += 1;

			if (timeoutCounter >= I2C_MAX_MASTER_TRANSMITTER_ARDY_TIMEOUT)
			{
				/* On timeout put the peripheral into reset, wait, then
				* take it out of reset */
				i2cReg->ICMDR = I2C_VAL_REG_MDR_RESET;
				i2cDelay (DELAY_CONST);
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

				IFPRINT(platform_write("i2c_send_stop: I2C Device Timeout - ARDY Not Set\n"));

				return (I2C_RET_IDLE_TIMEOUT);
			}

			i2cDelay (DELAY_CONST);
		}
	} while (timeoutCounter != 0);

  	return (I2C_RET_OK);

} // i2c_send_stop

/******************************************************************************
 *
 * Function:	i2c_transfer
 *
 * Description:	Function to transfer a byte of data on I2C bus
 *
 * Parameters:	CSL_I2cRegs *i2cReg    - I2C register base address
 * 				uint8_t  *pData        - Pointer to the data byte
 * 				uint8_t  rdWrFlag      - Flag to indicate whether to read data
 *                                       from the bus or write data to bus
 *                                       I2C_TRANSFER_READ - Reads data
 *                                       I2C_TRANSFER_WRITE - Writes data
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
static I2C_RET i2c_transfer(CSL_I2cRegs *i2cReg, uint8_t *pData, uint8_t rdWrFlag)
{
    uint32_t    timeoutCounter = 0;
  	uint32_t    statusReg;

  	IFPRINT_I2CDEBUG(platform_write("%s\n", __FUNCTION__));
	do
	{
		/* Read status */
		statusReg = i2cReg->ICSTR;

		/* On Nack return failure */
		if (I2C_REG_STR_FIELD_NACK(statusReg))
		{
			/* Return to slave receiver, clear nack and bus busy */
			i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
			i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
			platform_errno = PLATFORM_ERRNO_DEV_NAK;

			IFPRINT(platform_write("i2c_transfer: I2C NAK Error\n"));

			return (I2C_RET_NO_ACK);
		}

		/* Check if bus is ready for data transfer */
		if ((rdWrFlag == I2C_TRANSFER_WRITE) &&
		    I2C_REG_STR_FIELD_XRDY(statusReg))
		{
			/* Write data Transmit Data Register */
			i2cReg->ICDXR = *pData;
			timeoutCounter = 0;
		}
		else if ((rdWrFlag == I2C_TRANSFER_READ) &&
		         I2C_REG_STR_FIELD_RRDY(statusReg))
		{
			*pData = i2cReg->ICDRR & 0x00ff;
			timeoutCounter = 0;
		}
		else
		{
			/* Bus is not ready for transfer */
			i2cDelay (DELAY_CONST);
			timeoutCounter += 1;

			if (timeoutCounter >= I2C_MAX_MASTER_TRANSFER_TIMEOUT)
			{
				/* Return to slave receiver, clear nack and bus busy */
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
				platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

				IFPRINT(platform_write("i2c_transfer: I2C Device Timeout - Not Ready for Data Transfer\n"));

				return (I2C_RET_IDLE_TIMEOUT);
			}
		}
	} while (timeoutCounter != 0);

  	return (I2C_RET_OK);

} // i2c_transfer

/******************************************************************************
 *
 * Function:    i2cGetRegBaseAddr
 *
 * Description: Returns base address of given I2C port number.
 *
 * Return Value: CSL_I2cRegs*
 ******************************************************************************/
CSL_I2cRegs* i2cGetRegBaseAddr(uint8_t i2cPortNumber)
{
	CSL_I2cRegs    *addr;

	switch(i2cPortNumber)
	{
		case I2C_PORT_0:
			addr = (CSL_I2cRegs *)CSL_I2C_0_DATA_CFG_REGS;
			break;

		case I2C_PORT_1:
			addr = (CSL_I2cRegs *)CSL_I2C_1_DATA_CFG_REGS;
			break;

		case I2C_PORT_2:
			addr = (CSL_I2cRegs *)CSL_I2C_2_DATA_CFG_REGS;
			break;

		default :
			IFPRINT(platform_write("i2cGetRegBaseAddr: Invalid I2C Port Number\n"));
			addr = NULL;
			break;
	}

	return (addr);
}  //i2cGetRegBaseAddr

/******************************************************************************
 *
 * Function:    evmI2CInit
 *
 * Description: This function initializes I2C module.
 *
 * Parameters:  uint8_t i2cportnumber - The i2c port number
 *
 * Return Value: void
 ******************************************************************************/
void evmI2CInit(uint8_t i2cportnumber)
{
	i2cConfig(i2cportnumber);
} //evmI2CInit

/******************************************************************************
 *
 * Function:    i2cConfig
 *
 * Description: This function configures I2C module.
 *
 * Parameters:  uint8_t i2cportnumber - The i2c port number
 *
 * Return Value: void
 ******************************************************************************/
I2C_RET i2cConfig(uint8_t i2cPortNumber)
{
	CSL_I2cRegs    *i2cReg;

	if(i2cPortNumber < CSL_I2C_CNT)
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2cConfig: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

    // Set I2C in reset
    i2cReg->ICMDR &= (~CSL_I2C_ICMDR_IRS_MASK);

    i2cDelay(100);

    // Set Own Address
    i2cReg->ICOAR = I2C_OWN_ADDR;

    // Set Default I2C High and Low Clock Hold
    i2cReg->ICPSC  = I2C_PRESCALER;
    i2cReg->ICCLKL = I2C_CLK_LOW;
    i2cReg->ICCLKH = I2C_CLK_HIGH;

    // Enable the Xmt, Master Mode
    i2cReg->ICMDR = ( CSL_I2C_ICMDR_MST_MASK |
    CSL_I2C_ICMDR_TRX_MASK |
    CSL_I2C_ICMDR_FREE_MASK );

    // Take I2C Out of Reset
    i2cReg->ICMDR |= CSL_I2C_ICMDR_IRS_MASK;

    i2cDelay(100);

    return (I2C_RET_OK);
} //i2cConfig

/******************************************************************************
 *
 * Function:	i2cWrite
 *
 * Description:	Enters master transmitter mode, writes a specified number
 *              of bytes to the given slave address.
 *
 * Note: It is expected that address offset of the I2C slave device to write
 * data is part of pData in the format expected by the device.
 *
 * Parameters:	uint8_t  i2cPortNumber - The i2c port number
 *              uint8_t  slaveAddress  - i2c slave device address
 * 				uint8_t *pData         - Pointer to the buffer base address
 * 				uint32_t numBytes      - Number of bytes of buffer
 * 				uint32_t endBusState   - The state on which bus should be left
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cWrite( uint8_t i2cPortNumber, uint8_t slaveAddress, uint8_t *pData,
		          uint32_t numBytes, uint32_t endBusState)
{
  	uint32_t    count;
  	I2C_RET     returnValue;
	CSL_I2cRegs *i2cReg;

	IFPRINT_I2CDEBUG(platform_write("i2cWrite: "
	                                "I2C Port Number - %d   "
	                                "I2C Slave Address - 0x%x   "
	                                "Bytes to Write - %d   "
	                                "End Bus State - %d\n",
	                                i2cPortNumber, slaveAddress,
	                                numBytes, endBusState));

	returnValue = I2C_RET_OK;

	if((i2cPortNumber < CSL_I2C_CNT) && (pData != NULL))
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2cWrite: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

  	/* Check for the bus busy signal */
	returnValue = i2c_check_bus_busy(i2cReg);
	if(returnValue != I2C_RET_OK)
	{
		IFPRINT(platform_write("i2cWrite: I2C Busy Check Failed\n"));
		return (returnValue);
	}

  	/* Enter master transmitter mode, set the slave address register */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMT;
  	i2cReg->ICCNT = numBytes;
  	i2cReg->ICSAR = slaveAddress;
  	i2cDelay (DELAY_CONST);

  	/* Set the start bit */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMTSTRT;

  	for (count = 0; count < numBytes; count++)
  	{
		returnValue = i2c_transfer(i2cReg, pData, I2C_TRANSFER_WRITE);
		if(returnValue != I2C_RET_OK)
		{
			IFPRINT(platform_write("i2cWrite: I2C Data Transfer Failed\n"));
			return (returnValue);
		}

		pData += 1;
  	} /* end for loop */

  	/* If releasing the bus, send a stop bit */
  	if (endBusState == I2C_RELEASE_BUS)
  	{
	    returnValue = i2c_send_stop(i2cReg);
	}

  	return (returnValue);

} // i2cWrite

/******************************************************************************
 *
 * Function:	i2cRead
 *
 * Description:	Reads a fixed number of bytes from an I2C device. The read
 *              consists of a master write of slave address (maximum 4 bytes)
 *              followed by a master read of the input number of bytes.
 *
 * Parameters:	uint8_t i2cPortNumber - The i2c port number
 *              uint8_t slaveAddress  - i2c slave device address
 * 				uint8_t *pData        - Pointer to the buffer base address
 * 				uint8_t readOffset    - Offset to read from
 * 				uint8_t OffsetLen     - Length of read offset in bytes (1 to 4)
 * 				uint32_t numBytes     - Number of bytes of buffer
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cRead ( uint8_t i2cPortNumber, uint8_t slaveAddress, uint8_t *pData,
                  uint32_t readOffset, uint32_t OffsetLen, uint32_t numBytes)
{

  	uint32_t    statusReg;
  	uint32_t    timeoutCounter;
  	uint32_t    count;
  	uint16_t    ushValue;
  	I2C_RET     returnValue;
  	uint8_t     offsetByte[4];
  	CSL_I2cRegs *i2cReg;

	IFPRINT_I2CDEBUG(platform_write("i2cRead: "
	                                "I2C Port Number - %d   "
	                                "I2C Slave Address - %d   "
	                                "Bytes to Read - %d   "
	                                "Read Offset - %d   "
	                                "Read Offset Length - %d\n",
	                                i2cPortNumber, slaveAddress,
	                                numBytes, readOffset, OffsetLen));

	if(i2cPortNumber < CSL_I2C_CNT)
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2cRead: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

	if((OffsetLen < I2C_MIN_OFFSET_LEN) ||
	   (OffsetLen > I2C_MAX_OFFSET_LEN))
	{
		IFPRINT(platform_write("i2cRead: Invalid Offset Length\n"));
		return (I2C_RET_INVALID_PARAM);
	}

	for (count = OffsetLen; count > 0; count--)
	{
		offsetByte[OffsetLen - count] = (readOffset >> (8*(count-1))) & 0xff;
	}

  	/* Write the byte address to the eeprom. Do not send a stop */
	returnValue = i2cWrite(i2cPortNumber, slaveAddress, offsetByte,
	                       OffsetLen, I2C_DO_NOT_RELEASE_BUS);
  	if (returnValue != I2C_RET_OK)
  	{
		IFPRINT(platform_write("i2cRead: Slave Address Write Failed\n"));
    	return (returnValue);
	}

  	/* Give the I2C prom 10ms to process the read command */
  	i2cDelay (DELAY_CONST);

  	/* Set the start bit, begin the master read */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTRCV;
  	i2cReg->ICCNT = numBytes;

 	for (count = 0; count < numBytes; count++)
 	{
 		returnValue = i2c_transfer(i2cReg, pData, I2C_TRANSFER_READ);
		if (returnValue != I2C_RET_OK)
		{
			IFPRINT(platform_write("i2cRead: I2C Data Read Failed\n"));
			return (returnValue);
		}
		pData++;
  	}

  	/* The data block has been read. Send the stop bit */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTRCVSTOP;

  	/* Wait for the rrdy and read the dummy byte */
  	timeoutCounter = 0;
  	do
  	{
    	statusReg = i2cReg->ICSTR;

    	/* Check for receive byte ready */
    	if (I2C_REG_STR_FIELD_RRDY(statusReg))
    	{
      		ushValue = i2cReg->ICDRR & 0x00ff;
      		ushValue = ushValue; // To avoid compilation warning!
      		timeoutCounter = 0;
    	}
    	else
    	{  /* rrdy not set */
      		i2cDelay (DELAY_CONST);
      		timeoutCounter += 1;

      		if (timeoutCounter >= I2C_MAX_MASTER_RECEIVE_TIMEOUT)
      		{
        		/* Return to slave receiver, clear nack and bus busy */
        		i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
                platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

                IFPRINT(platform_write("i2cRead: I2C Timeout While Reading Dummy Byte\n"));

        		return (I2C_RET_IDLE_TIMEOUT);
      		}
    	}
  	} while (timeoutCounter != 0);

  	return (I2C_RET_OK);

} // i2cRead

/******************************************************************************
 *
 * Function:	i2cWriteLong
 *
 * Description:	Function to write long format (32 bit) data to I2C device.
 *              Enters master transmitter mode, writes a specified number
 *              of bytes to the given slave address. Data will be written
 *              with MSB first.
 *
 * Note: This function is provided for special use-cases to save CPU cycles
 * when the data buffers are available in long format. i2cWrite shall be used
 * for all the normal I2C data write requirements. Address to write the data
 * shall be provided separately to this function instead of adding at the
 * beginning of data buffer. This is to avoid aligning of address offset with
 * long data format as address offset will be 1 or 2 bytes in general.
 *
 * Parameters:	uint8_t  i2cPortNumber - The i2c port number
 *              uint8_t  slaveAddress  - i2c slave device address
 * 				uint32_t *pData        - Pointer to the buffer base address
 * 				uint8_t  writeOffset   - Offset to write data
 * 				uint8_t  OffsetLen     - Length of write offset in bytes(1 to 4)
 * 				uint32_t numBytes      - Number of bytes in 'pData'
 * 				uint32_t endBusState   - The state on which bus should be left
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cWriteLong( uint8_t i2cPortNumber, uint8_t slaveAddress,
		              uint32_t *pData, uint32_t writeOffset, uint32_t OffsetLen,
		              uint32_t numBytes, uint32_t endBusState)
{
  	uint32_t    count;
  	I2C_RET     returnValue = I2C_RET_OK;
  	uint8_t     byteCount;
  	uint8_t     data;
	CSL_I2cRegs *i2cReg;

	IFPRINT_I2CDEBUG(platform_write("i2cWriteLong: "
	                                "I2C Port Number - %d   "
	                                "I2C Slave Address - %d   "
	                                "Bytes to Write - %d   "
	                                "End Bus State - %d   ",
	                                "Write Offset - %d   ",
	                                "Write Offset Length - %d\n",
	                                i2cPortNumber, slaveAddress,
	                                numBytes, endBusState,
	                                writeOffset, OffsetLen));

	if((i2cPortNumber < CSL_I2C_CNT) && (pData != NULL))
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2cWriteLong: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

	if((OffsetLen < I2C_MIN_OFFSET_LEN) ||
	   (OffsetLen > I2C_MAX_OFFSET_LEN))
	{
		IFPRINT(platform_write("i2cWriteLong: Invalid Offset Length\n"));
		return (I2C_RET_INVALID_PARAM);
	}

  	/* Check for the bus busy signal */
	returnValue = i2c_check_bus_busy(i2cReg);
	if(returnValue != I2C_RET_OK)
	{
		IFPRINT(platform_write("i2cWriteLong: I2C Busy Check Failed\n"));
		return (returnValue);
	}

  	/* Enter master transmitter mode, set the slave address register */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMT;
  	i2cReg->ICSAR = slaveAddress;
  	i2cReg->ICCNT = numBytes + OffsetLen;
  	i2cDelay (DELAY_CONST);

  	/* Set the start bit */
  	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMTSTRT;

 	for (count = OffsetLen; count > 0; count--)
	{
		data = (writeOffset >> (8*(count-1))) & 0xff;
		returnValue = i2c_transfer(i2cReg, &data, I2C_TRANSFER_WRITE);
		if(returnValue != I2C_RET_OK)
		{
			IFPRINT(platform_write("i2cWriteLong: I2C Slave Write Failed\n"));
			return (returnValue);
		}
	}

  	for (count = 0; count < numBytes; )
  	{
		for(byteCount = 4; (byteCount > 0) && (count < numBytes); byteCount--)
		{
			data = (*pData >> (8*(byteCount-1))) & 0xff;
			returnValue = i2c_transfer(i2cReg, &data, I2C_TRANSFER_WRITE);
			if(returnValue != I2C_RET_OK)
			{
				IFPRINT(platform_write("i2cWriteLong: I2C Data Write Failed\n"));
				return (returnValue);
			}

			count += 1;
		}

		pData += 1;

  	} /* end for loop */

  	/* If releasing the bus, send a stop bit */
  	if (endBusState == I2C_RELEASE_BUS)
  	{
	    returnValue = i2c_send_stop(i2cReg);
	}

  	return (returnValue);

} // i2cWriteLong

/******************************************************************************
 *
 * Function:	i2cDelay
 *
 * Description:	Creates a delay.
 *
 * Parameters:	uint32_t count - Counter for the loop
 *
 * Return Value: void
 *
 ******************************************************************************/
void i2cDelay (uint32_t count)
{
	uint32_t i;

  	for (i = 0; i < count; i++)
  	{
		platform_delaycycles(50000);
	}
}  //i2cDelay

/******************************************************************************
 *
 * Function:	i2c_force_release_bus
 *
 * Description:	Performs force release of I2C bus
 *
 * Parameters:	uint8_t  i2cPortNumber - The i2c port number
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
static I2C_RET i2c_force_release_bus(uint8_t i2cPortNumber)
{
	uint32_t  timeoutCounter;
	uint32_t  statusReg;
	CSL_I2cRegs *i2cReg;

	if(i2cPortNumber < CSL_I2C_CNT)
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2c_force_release_bus: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

	/* If releasing the bus, send a stop bit */
	/* Wait for the ardy bit to go high */
	timeoutCounter = 0;

	do
	{
		statusReg = i2cReg->ICSTR;
		if (I2C_REG_STR_FIELD_ARDY(statusReg))
		{
			i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTXMTSTOP;
			i2cReg->ICSTR = I2C_VAL_REG_STR_CLR_BUSY;
			i2cDelay (DELAY_CONST);

			if(I2C_REG_STR_FIELD_BB(i2cReg->ICSTR))
			{
				/* Some grave issue -- Issue reset*/
				i2cReg->ICMDR = I2C_VAL_REG_MDR_RESET;
				i2cDelay (0x100);
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
			}

			i2cDelay (DELAY_CONST);
			timeoutCounter = 0;
		}
		else
		{
			/* Registers not ready for access */
			timeoutCounter += 1;
			if (timeoutCounter >= I2C_MAX_MASTER_TRANSMITTER_ARDY_TIMEOUT)
			{
				/* On timeout put the peripheral into reset, wait, then
				 * take it out of reset */
				i2cReg->ICMDR = I2C_VAL_REG_MDR_RESET;
				i2cDelay (0x100);
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

				IFPRINT(platform_write("i2c_force_release_bus: I2C Device Timeout - ARDY Not Set\n"));

				return (I2C_RET_IDLE_TIMEOUT);
			}

			i2cDelay (DELAY_CONST);
		}
	} while (timeoutCounter != 0);

	return (I2C_RET_OK);
}  // i2c_force_release_bus

/******************************************************************************
 *
 * Function:	i2cProbe
 *
 * Description:	Function to probe I2C devices
 *
 * This function initiates data transfer with given I2C slave address and checks
 * if it responds with proper acknowledgement
 *
 * Parameters:	uint8_t  i2cPortNumber - The i2c port number
 *              uint8_t  slaveAddress  - i2c slave device address
 * 				uint8_t  offset        - Offset with in slave device
 * 				uint32_t *pData        - Pointer to the buffer base address
 * 				uint32_t numBytes      - Number of bytes in 'pData'
 *
 * Return Value: I2C_RET - status
 *
 ******************************************************************************/
I2C_RET i2cProbe (uint8_t i2cPortNumber, uint8_t slaveAddress,
				  uint32_t offset, uint8_t *pData, uint32_t numBytes)
{
	uint32_t  statusReg;
	uint32_t  timeoutCounter;
	uint32_t  count;
	I2C_RET   returnValue;
	uint16_t  ushValue;
	uint8_t	  offsetPtr[4];
	uint8_t   offsetLen=0;
	uint32_t  index;
	CSL_I2cRegs *i2cReg;

	if(i2cPortNumber < CSL_I2C_CNT)
	{
		i2cReg = i2cGetRegBaseAddr(i2cPortNumber);
	}
	else
	{
		IFPRINT(platform_write("i2cProbe: Invalid I2C Port Number\n"));
		return (I2C_RET_INVALID_PARAM);
	}

	offsetLen = 1;

	for (index = 0; index < offsetLen; index++)
	{
		offsetPtr[offsetLen - index - 1] = ((offset >> (8*index)) & 0xFF);
	}

	/* Write the offset address to the I2C slave. Do not send a stop */
	returnValue = i2cWrite( i2cPortNumber, slaveAddress, offsetPtr,
								offsetLen, I2C_DO_NOT_RELEASE_BUS);
	if (returnValue != I2C_RET_OK)
	{
		IFPRINT(platform_write("i2cProbe: I2C Slave Address Write Failed\n"));
		return (returnValue);
	}

	/* Give the I2C prom 10ms to process the read command */
	i2cDelay (DELAY_CONST);
	i2cDelay (DELAY_CONST);

	/* Set the start bit, begin the master read */
	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTRCV;

	for (count = 0; count < numBytes; count++)
	{
		timeoutCounter = 0;

		do
		{
			/* Read status */
			statusReg = i2cReg->ICSTR;

			/* On Nack return failure */
			if (I2C_REG_STR_FIELD_NACK(statusReg))
			{
				/* Return to slave receiver, clear nack and bus busy */
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
				platform_errno = PLATFORM_ERRNO_DEV_NAK;

				IFPRINT(platform_write("i2cProbe: I2C NAK Error\n"));
				i2cDelay(CUSTOM_DELAY);
				i2c_force_release_bus(i2cPortNumber);
				i2cDelay(CUSTOM_DELAY);
				return (I2C_RET_NO_ACK_READ);
			}

			/* Check for receive byte ready */
			if (I2C_REG_STR_FIELD_RRDY(statusReg))
			{
				ushValue = i2cReg->ICDRR & 0x00ff;
				timeoutCounter = 0;
				*pData = ushValue;
				pData++;
			}
			else
			{   /* RRDY bit not set */
				i2cDelay (DELAY_CONST);
				timeoutCounter += 1;

				if (timeoutCounter >= I2C_MAX_MASTER_RECEIVE_TIMEOUT)
				{
					/* Return to slave receiver, clear nack and bus busy */
					i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
					i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
					platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

					IFPRINT(platform_write("i2cProbe: I2C Device Timeout\n"));
					i2cDelay(CUSTOM_DELAY);
					i2c_force_release_bus(i2cPortNumber);
					i2cDelay(CUSTOM_DELAY);
					return (I2C_RET_IDLE_TIMEOUT);
				}
			}
		} while (timeoutCounter != 0);
	} /* end for loop */

	/* The data block has been read. Send the stop bit */
	i2cReg->ICMDR = I2C_VAL_REG_MDR_MSTRCVSTOP;

	/* Wait for the rrdy and read the dummy byte */
	timeoutCounter = 0;

	do
	{
		statusReg = i2cReg->ICSTR;

		/* Check for receive byte ready */
		if (I2C_REG_STR_FIELD_RRDY(statusReg))
		{
			ushValue = i2cReg->ICDRR & 0x00ff;
			timeoutCounter = 0;
		}
		else
		{  /* rrdy not set */
			i2cDelay (DELAY_CONST);
			timeoutCounter += 1;
			if (timeoutCounter >= I2C_MAX_MASTER_RECEIVE_TIMEOUT)
			{
				/* Return to slave receiver, clear nack and bus busy */
				i2cReg->ICMDR = I2C_VAL_REG_MDR_SLVRCV;
				i2cReg->ICSTR = I2C_VAL_REG_STR_ON_FAIL;
				platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;

				IFPRINT(platform_write("i2cProbe: I2C Device Timeout - RRDY not set\n"));
				i2cDelay(CUSTOM_DELAY);
				i2c_force_release_bus(i2cPortNumber);
				i2cDelay(CUSTOM_DELAY);
				return (I2C_RET_IDLE_TIMEOUT);
			}
		}
	} while (timeoutCounter != 0);

	i2c_force_release_bus(i2cPortNumber);

	return (I2C_RET_OK);
}  // i2cProbe

#endif /* #if (PLATFORM_I2C_IN) */
/* Nothing past this point */

