/*
 *  Copyright (C) 2016-2020 Texas Instruments Incorporated - http://www.ti.com/
*  Copyright (C) 2017 Arasan Chip Systems Inc
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
*/
/*********************************************************************
*  Copyright (C) 2017 Arasan Chip Systems Inc
*  Name             : low_level_hw.c
*  Creation Date : June 14, 2017
*  Description     : This file contains functions to read / write the host controller
*                          registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017   PB              0.1                 File structure creation
*  15-July-2017    PB              0.5                 Added function definition
*  28-July-2017    PB              1.0                 Modified for 64-bit addressing
*  28-Aug-2017    PB              1.1                 Added functions for register value manipulation
*                                                                 instead of macros for MisraC compliance
*  29-Aug-2017    PB              1.2                 Added function headers for register
*                                                                 manipulation functions
*
*********************************************************************/
/**
 *  \file low_level_hw.c
 *
 *  \brief File with low level hardware register manipulation functions
 *
**/

/*   Includes    */
#include <ti/csl/tistdtypes.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/src/ip/mmc/V4/priv/low_level_hw.h>

/*    Globals    */



/*    Function Definitions    */

/**
 * \brief   Read hardware register for Dword data
 *
 * \param   address      Address of the MMC/SD controller Register.
 *
 * \return   Dword value of the register
 **/
uint32_t SdhcRegisterReadDWord(uintptr_t address)
{
    return HW_RD_REG32(address);
}

/**
 * \brief   Read hardware register for Word data
 *
 * \param   address      Address of the MMC/SD controller Register.
 *
 * \return   Word value of the register
 **/
uint16_t SdhcRegisterReadWord(uintptr_t address)
{
    return HW_RD_REG16(address);
}

/**
 * \brief   Read hardware register for byte data
 *
 * \param   address      Address of the MMC/SD controller Register.
 *
 * \return   Byte value of the register
 **/
uint8_t SdhcRegisterReadByte(uintptr_t address)
{
    return HW_RD_REG8(address);
}

/**
 * \brief   Write hardware register with Dword value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u32Value      Value to be written to MMC/SD controller register
 *
 * \return   None
 **/
void SdhcRegisterWriteDWord(uintptr_t address, uint32_t u32Value)
{
    HW_WR_REG32(address, u32Value);
    return;
}

/**
 * \brief   Write hardware register with Word value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u16Value      Value to be written to MMC/SD controller register
 *
 * \return   None
 **/
void SdhcRegisterWriteWord(uintptr_t address, uint16_t u16Value)
{
    HW_WR_REG16(address, u16Value);
    return;
}

/**
 * \brief   Write hardware register with Byte value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u8Value      Value to be written to MMC/SD controller register
 *
 * \return   None
 **/
void SdhcRegisterWriteByte(uintptr_t address, uint8_t u8Value)
{
    HW_WR_REG8(address, u8Value);
    return;
}

/**
 * \brief   Read hardware register for Dword data and extract specified field value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u32Mask      Field mask value
 * \param   u32Shift      Field shift value
 *
 * \return   Dword value of the field
 **/
uint32_t SdhcRegisterReadFieldDWord(uintptr_t address, uint32_t u32Mask, uint32_t u32Shift)
{
    uint32_t u32RegisterValue = SdhcRegisterReadDWord(address);
    u32RegisterValue = (u32RegisterValue & u32Mask) >> u32Shift;

    return u32RegisterValue;
}

/**
 * \brief   Read hardware register for Word data and extract specified field value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u16Mask      Field mask value
 * \param   u32Shift      Field shift value
 *
 * \return   Word value of the field
 **/
uint16_t SdhcRegisterReadFieldWord(uintptr_t address, uint16_t u16Mask, uint32_t u32Shift)
{
    uint32_t u32TempVal;
    uint16_t u16RegisterValue = SdhcRegisterReadWord(address);
    u32TempVal = (((uint32_t) u16RegisterValue & (uint32_t) u16Mask) >> u32Shift);
    u16RegisterValue = (uint16_t) u32TempVal;

    return u16RegisterValue;
}

/**
 * \brief   Read hardware register for byte data and extract specified field value
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u8Mask      Field mask value
 * \param   u32Shift      Field shift value
 *
 * \return   Byte value of the field
 **/
uint8_t SdhcRegisterReadFieldByte(uintptr_t address, uint8_t u8Mask, uint32_t u32Shift)
{
    uint32_t u32TempVal;
    uint8_t u8RegisterValue = SdhcRegisterReadByte(address);
    u32TempVal = (((uint32_t) u8RegisterValue & (uint32_t) u8Mask) >> u32Shift);
    u8RegisterValue = (uint8_t) u32TempVal;

    return u8RegisterValue;
}

/**
 * \brief   Write hardware register for Dword value to specified SD/MMC field
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u32Mask      Field mask value
 * \param   u32Shift      Field shift value
 * \param   u32Value      Field value
 *
 * \return   None
 **/
void SdhcRegisterWriteFieldDWord(uintptr_t address, uint32_t u32Mask, uint32_t u32Shift, uint32_t u32Value)
{
    uint32_t u32RegisterValue = SdhcRegisterReadDWord(address);
    u32RegisterValue &= (~u32Mask);
    u32RegisterValue |= (u32Value << u32Shift) & u32Mask;
    SdhcRegisterWriteDWord(address, u32RegisterValue);

    return;
}

/**
 * \brief   Write hardware register for Word value to specified SD/MMC field
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u16Mask      Field mask value
 * \param   u32Shift      Field shift value
 * \param   u16Value      Field value
 *
 * \return   None
 **/
void SdhcRegisterWriteFieldWord(uintptr_t address, uint16_t u16Mask, uint32_t u32Shift, uint16_t u16Value)
{
    uint32_t u32TempVal;
    uint16_t u16RegisterValue = SdhcRegisterReadWord(address);
    u32TempVal = ((uint32_t) u16RegisterValue);
    u32TempVal &=  (~((uint32_t) u16Mask));
    u32TempVal |= (((uint32_t) u16Value) << u32Shift) & ((uint32_t) u16Mask);
    u16RegisterValue = (uint16_t) u32TempVal;
    SdhcRegisterWriteWord(address, u16RegisterValue);

    return;
}

/**
 * \brief   Write hardware register for byte value to specified SD/MMC field
 *
 * \param   address      Address of the MMC/SD controller Register.
 * \param   u8Mask      Field mask value
 * \param   u32Shift      Field shift value
 * \param   u8Value      Field value
 *
 * \return   None
 **/
void SdhcRegisterWriteFieldByte(uintptr_t address, uint8_t u8Mask, uint32_t u32Shift, uint8_t u8Value)
{
    uint32_t u32TempVal;
    uint8_t u8RegisterValue = SdhcRegisterReadByte(address);
    u32TempVal = ((uint32_t) u8RegisterValue);
    u32TempVal &=  (~((uint32_t) u8Mask));
    u32TempVal |= (((uint32_t) u8Value) << u32Shift) & ((uint32_t) u8Mask);
    u8RegisterValue = (uint8_t) u32TempVal;
    SdhcRegisterWriteByte(address, u8RegisterValue);

    return;
}

/**
 * \brief   Extract a value from dword value based on its position
 *
 * \param   u32RegisterValue      Dword value from which the value is extracted.
 * \param   u32Shift      Field mask for the value to be extracted
 * \param   u32Mask      Field shift for the value to be extracted
 *
 * \return   Dword value of the field
 **/
uint32_t SdhcGetFieldValueDWord(uint32_t u32RegisterValue, uint32_t u32Shift, uint32_t u32Mask)
{
	return ((u32RegisterValue & u32Mask) >> u32Shift);
}

/**
 * \brief   Set a field value in the dword value based on its position
 *
 * \param   u32RegisterValue      Dword value in which the field value is updated.
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u32FieldValue  Field value to be updated
 *
 * \return   Dword value with updated field value
 **/
uint32_t SdhcSetFieldValueDWord(uint32_t u32RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint32_t u32FieldValue)
{
	uint32_t u32Val;

	u32Val = (((u32RegisterValue) & (uint32_t) (~u32Mask)) |((((uint32_t)u32FieldValue) << (uint32_t)u32Shift) & (uint32_t)u32Mask));

	return u32Val;
}

/**
 * \brief   Set a field value in the word value based on its position
 *
 * \param   u16RegisterValue      Word (16bit) value in which the field value is updated
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u16FieldValue  Field value to be updated
 *
 * \return   Word value with updated field value
 **/
uint16_t SdhcSetFieldValueWord(uint16_t u16RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint16_t u16FieldValue)
{
	uint16_t u16Val;

	u16Val = (((u16RegisterValue) & (uint16_t) (~(uint16_t)u32Mask)) |((((uint16_t)u16FieldValue) << (uint16_t)u32Shift) & (uint16_t)u32Mask));

	return u16Val;
}

/**
 * \brief   Set a field value in the byte value based on its position
 *
 * \param   u8RegisterValue      Byte (8bit) value in which the field value is updated
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u8FieldValue  Field value to be updated
 *
 * \return   Byte value with updated field value
 **/
uint8_t SdhcSetFieldValueByte(uint8_t u8RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint8_t u8FieldValue)
{
	uint8_t u8Val;

	u8Val = (((u8RegisterValue) & (uint8_t) (~(uint8_t)u32Mask)) | ((((uint8_t)u8FieldValue) << (uint8_t)u32Shift) & (uint8_t)u32Mask));

	return u8Val;
}

/**
 * \brief   Write a field value in the 32bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u32FieldValue  Field value to be updated
 *
 * \return   none
 **/
void SdhcWriteRegisterFieldValueDWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint32_t u32FieldValue)
{
	SdhcRegisterWriteFieldDWord(registerAddress, u32Mask, u32Shift, u32FieldValue);
	return;
}

/**
 * \brief   Write a field value in the 16bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u16FieldValue  Field value to be updated
 *
 * \return   none
 **/
void SdhcWriteRegisterFieldValueWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint16_t u16FieldValue)
{
	SdhcRegisterWriteFieldWord(registerAddress, ((uint16_t) u32Mask), u32Shift, u16FieldValue);
	return;
}

/**
 * \brief   Write a field value in the 8bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 * \param   u8FieldValue  Field value to be updated
 *
 * \return   none
 **/
void SdhcWriteRegisterFieldValueByte(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint8_t u8FieldValue)
{
	SdhcRegisterWriteFieldByte(registerAddress, ((uint8_t)u32Mask), u32Shift, u8FieldValue);
	return;
}

/**
 * \brief   Read a field value from 32bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 *
 * \return   Field value in dword, read from the register
 **/
uint32_t SdhcReadRegisterFieldValueDWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask)
{
	return SdhcRegisterReadFieldDWord(registerAddress, u32Mask, u32Shift);
}

/**
 * \brief   Read a field value from 16bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 *
 * \return   Field value in word, read from the register
 **/
uint16_t SdhcReadRegisterFieldValueWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask)
{
	return SdhcRegisterReadFieldWord(registerAddress, ((uint16_t)u32Mask), u32Shift);
}

/**
 * \brief   Read a field value from 8bit register
 *
 * \param   registerAddress      Address of the SD/MMC register
 * \param   u32Shift      Field mask for the value to be updated
 * \param   u32Mask      Field shift for the value to be updated
 *
 * \return   Field value in byte, read from the register
 **/
uint8_t SdhcReadRegisterFieldValueByte(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask)
{
	return SdhcRegisterReadFieldByte(registerAddress, ((uint8_t)u32Mask), u32Shift);
}
