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
 * \file evmc66x_i2c.h
 *
 * \brief This contains i2c specific structure, typedefs, function
 *		  prototypes.
 *
 *
 ******************************************************************************/
#ifndef	_EVM66X_I2C_H_
#define	_EVM66X_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************
 * Include Files
 ************************/
#include "cslr_i2c.h"
#include "cslr_device.h"

/************************
 * Defines and Macros
 ************************/
#define I2C_OWN_ADDR                 (0x10)

// Interrupt
#define I2C_DISABLE_INTR    		 (0x00)

#ifdef CPU_1000MHZ_CLOCK

#ifdef _I2C_400KHZ_
// I2C prescalar set to 13 to get module freq (1000MHz/6)/14 = 11.9 MHz
#define I2C_PRESCALER 				 (13)
// Setting the divider to divide module freq 11.9MHz/((9+6)+(9+6)) = 396.67 KHz
#define I2C_CLK_LOW					 (9)
#define I2C_CLK_HIGH				 (9)
#else
// I2C prescalar set to 16 to get module freq (1000MHz/6)/17 = 9.8 MHz
#define I2C_PRESCALER 				 (16)
// Setting the divider to divide module freq 9.8MHz/((36+6)+(36+6)) = 116.67 KHz
#define I2C_CLK_LOW					 (36)
#define I2C_CLK_HIGH				 (36)
#endif

#else

#ifdef _I2C_400KHZ_
// I2C prescalar set to 9 to get module freq (600MHz/6)/10 = 10 MHz
#define I2C_PRESCALER 				 (9)
// Setting the divider to divide module freq 10MHz/((7+6)+(7+6)) = 384.61 KHz
#define I2C_CLK_LOW					 (7)
#define I2C_CLK_HIGH				 (7)
#else
// I2C prescalar set to 9 to get module freq (600MHz/6)/10 = 10 MHz
#define I2C_PRESCALER 				 (9)
// Setting the divider to divide module freq 10MHz/((44+6)+(44+6)) = 100 KHz
#define I2C_CLK_LOW					 (44)
#define I2C_CLK_HIGH				 (44)
#endif

#endif  /* #ifdef CPU_1000MHZ_CLOCK */

// I2C delay value
#define DELAY_CONST 			     (2)

// I2C ports available
#define I2C_PORT_0					 (CSL_I2C_0)
#define I2C_PORT_1					 (CSL_I2C_1)
#define I2C_PORT_2					 (CSL_I2C_2)

// Register values for specific	purpose
#define	I2C_VAL_REG_MDR_RESET		 (0x4000)
#define	I2C_VAL_REG_MDR_SLVRCV		 (0x40A0)
#define	I2C_VAL_REG_MDR_MSTRCV		 (0x64A0)
#define	I2C_VAL_REG_MDR_MSTRCVSTOP	 (0x4CA0)
#define	I2C_VAL_REG_MDR_MSTXMT		 (0x46A0)
#define	I2C_VAL_REG_MDR_MSTXMTSTRT	 (0x66A0)
#define	I2C_VAL_REG_MDR_MSTXMTSTOP	 (0x4CA0)

#define	I2C_VAL_REG_STR_RESET		 (0x0410)
#define	I2C_VAL_REG_STR_ON_FAIL		 (0x1002)  // Clear bus busy, clear nack
#define	I2C_VAL_REG_STR_CLR_BUSY	 (0x1000)  // Clear busy

// Bit field definitions
#define	BOOTBITMASK(x,y)			 ((( (1 << ((x)-(y)+1) )	- 1 )) << (y))
#define	BOOT_READ_BITFIELD(z,x,y)	 ((z) & BOOTBITMASK(x,y)) >> (y)
#define	I2C_REG_STR_FIELD_BB(x)		 BOOT_READ_BITFIELD((x),	12, 12)
#define	I2C_REG_STR_FIELD_NACK(x)	 BOOT_READ_BITFIELD((x),	 1,  1)
#define	I2C_REG_STR_FIELD_ARDY(x)	 BOOT_READ_BITFIELD((x),	 2,  2)
#define	I2C_REG_STR_FIELD_XRDY(x)	 BOOT_READ_BITFIELD((x),	 4,  4)
#define	I2C_REG_STR_FIELD_RRDY(x)	 BOOT_READ_BITFIELD((x),	 3,  3)

// Return values
#define	I2C_RET_OK					 (0)
#define	I2C_RET_LOST_ARB			 (1)
#define	I2C_RET_NO_ACK				 (2)
#define	I2C_RET_IDLE_TIMEOUT		 (3)
#define	I2C_RET_BAD_REQUEST			 (4)
#define	I2C_RET_CLOCK_STUCK_LOW		 (5)
#define	I2C_RET_NULL_PTR_ERROR		 (6)
#define	I2C_RET_INVALID_PARAM		 (7)
#define	I2C_RET_NO_ACK_READ			 (8)
#define	I2C_RET_GEN_ERROR			 (99)

// Desired frequency for module operation
#define	I2C_TARGET_MODULE_FREQ_MHZ	     (8)

// Timeout limit for master	transmitter/receiver.
// The units are in number of bits, so provide some overhead
#define	I2C_MAX_MASTER_TRANSFER_TIMEOUT  (24)   /* 3	bytes */

// Timeout limit for master	receiver. The units are
// in number of bits, so provide some overhead
#define	I2C_MAX_MASTER_RECEIVE_TIMEOUT	 (24)	/* 3 bytes */

// Timeout limit for the master transmitter	to get access
// to the bus. In 10ms units.
#define	I2C_MAX_MASTER_TRANSMITTER_BUS_ACCESS_TIMEOUT  (5)
#define	I2C_MASTER_TRANSMITTER_BUS_ACCESS_DELAY_US     (25)

/* Timeout limit after a master transmitter	operation is
 * complete, and waiting for access	to the MMRs. This should be on
 * the order of two bytes, for the last two that are being sent
 * (one in the shift register, one in the dxr. The units are in bits. */
#define	I2C_MAX_MASTER_TRANSMITTER_ARDY_TIMEOUT	  (32)	/* 4 bytes */

/* Timeout limit in	slave receiver mode. The unit is in
 * expected	bit periods, but is long since the master
 * may have	a long delay before beginning transmission. */
#define	I2C_MAX_SLAVE_RECEIVE_TIMEOUT	   (5000000)

// I2C slave address offset minimum and maximum length supported
#define I2C_MIN_OFFSET_LEN      (1)
#define I2C_MAX_OFFSET_LEN      (4)

// Flags to indicate I2C data transfer direction
#define I2C_TRANSFER_READ       (0)
#define I2C_TRANSFER_WRITE      (1)

//#define ENABLE_I2C_DEBUG        (1)

#if (ENABLE_I2C_DEBUG)
#define IFPRINT_I2CDEBUG(x)   (x)
#else
#define IFPRINT_I2CDEBUG(x)
#endif

/************************
 * Structures and Enums
 ************************/

// Bus release
enum {
  I2C_RELEASE_BUS,
  I2C_DO_NOT_RELEASE_BUS
};

typedef	uint16_t I2C_RET;

/************************
 * Function declarations
 ************************/

CSL_I2cRegs* i2cGetRegBaseAddr(uint8_t i2cPortNumber);
void evmI2CInit(uint8_t i2cportnumber );
I2C_RET i2cConfig(uint8_t i2cPortNumber);
I2C_RET i2cWrite( uint8_t i2cPortNumber, uint8_t slaveAddress, uint8_t *pData,
		          uint32_t numBytes, uint32_t endBusState);
I2C_RET i2cRead ( uint8_t i2cPortNumber, uint8_t slaveAddress, uint8_t *pData,
                  uint32_t readOffset, uint32_t OffsetLen, uint32_t numBytes);
I2C_RET i2cWriteLong( uint8_t i2cPortNumber, uint8_t slaveAddress,
		              uint32_t *pData, uint32_t writeOffset, uint32_t OffsetLen,
		              uint32_t numBytes, uint32_t endBusState);
void i2cDelay (uint32_t count);
I2C_RET i2cProbe (uint8_t i2cPortNumber, uint8_t slaveI2cAddress,
				  uint32_t offset, uint8_t *pData, uint32_t numBytes);

#ifdef __cplusplus
}
#endif

#endif // _EVM66X_I2C_H_
