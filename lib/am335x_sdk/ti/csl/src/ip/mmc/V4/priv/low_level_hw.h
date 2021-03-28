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
*  Name             : low_level_hw.h
*  Creation Date : June 14, 2017
*  Description     : This header file contains functions to read/write the host controller
*                          registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017   PB              0.1                 File structure creation
*  15-July-2017    PB              0.5                 Added macros definition and prototypes
*  28-July-2017    PB              1.0                 Modified for 64-bit addressing
*  28-Aug-2017    PB              1.1                 Added functions for register value manipulation
*                                                                 instead of macros for MisraC compliance
*
*********************************************************************/
/**
 *  \file low_level_hw.h
 *
 *  \brief File with low level hardware register manipulation function prototypes
 *
**/
#ifndef SDHC_LOW_LEVEL_HW_H_
#define SDHC_LOW_LEVEL_HW_H_

#ifdef __cplusplus
extern "C" {
#endif

/*    Includes    */

#include <ti/csl/src/ip/mmc/V4/priv/os_types.h>

/*   Typedefs and Defines    */


/*    Function Declaration    */

uint32_t SdhcRegisterReadDWord(uintptr_t address);
uint16_t SdhcRegisterReadWord(uintptr_t address);
uint8_t SdhcRegisterReadByte(uintptr_t address);

void SdhcRegisterWriteDWord(uintptr_t address, uint32_t u32Value);
void SdhcRegisterWriteWord(uintptr_t address, uint16_t u16Value);
void SdhcRegisterWriteByte(uintptr_t address, uint8_t u8Value);

uint32_t SdhcRegisterReadFieldDWord(uintptr_t address, uint32_t u32Mask, uint32_t u32Shift);
uint16_t SdhcRegisterReadFieldWord(uintptr_t address, uint16_t u16Mask, uint32_t u32Shift);
uint8_t SdhcRegisterReadFieldByte(uintptr_t address, uint8_t u8Mask, uint32_t u32Shift);

void SdhcRegisterWriteFieldDWord(uintptr_t address, uint32_t u32Mask, uint32_t u32Shift, uint32_t u32Value);
void SdhcRegisterWriteFieldWord(uintptr_t address, uint16_t u16Mask, uint32_t u32Shift, uint16_t u16Value);
void SdhcRegisterWriteFieldByte(uintptr_t address, uint8_t u8Mask, uint32_t u32Shift, uint8_t u8Value);

uint32_t SdhcGetFieldValueDWord(uint32_t u32RegisterValue, uint32_t u32Shift, uint32_t u32Mask);

uint32_t SdhcSetFieldValueDWord(uint32_t u32RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint32_t u32FieldValue);
uint16_t SdhcSetFieldValueWord(uint16_t u16RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint16_t u16FieldValue);
uint8_t SdhcSetFieldValueByte(uint8_t u8RegisterValue, uint32_t u32Shift, uint32_t u32Mask, uint8_t u8FieldValue);

void SdhcWriteRegisterFieldValueDWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint32_t u32FieldValue);
void SdhcWriteRegisterFieldValueWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint16_t u16FieldValue);
void SdhcWriteRegisterFieldValueByte(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask, uint8_t u8FieldValue);

uint32_t SdhcReadRegisterFieldValueDWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask);
uint16_t SdhcReadRegisterFieldValueWord(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask);
uint8_t SdhcReadRegisterFieldValueByte(uintptr_t registerAddress, uint32_t u32Shift, uint32_t u32Mask);


#ifdef __cplusplus
}
#endif

#endif /*#ifndef SDHC_LOW_LEVEL_HW_H_*/
