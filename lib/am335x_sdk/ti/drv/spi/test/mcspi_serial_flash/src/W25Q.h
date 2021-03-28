/**
 *  \file   W25Q.h
 *
 *  \brief  Header file for W25QFL serial Flash driver.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef __W25QFL_H
#define __W25QFL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>

/** \brief Below are the commands and status values used by Winbond
           W25Q64BV flash. */
#define FLASH_WRITE_IN_PROGRESS          (0x01U)
#define FLASH_SECTOR_ADD_HIGH            (0x3FU)
#define FLASH_SECTOR_ADD_LOW             (0x00U)
#define FLASH_SECTOR_ADD_MID             (0x00U)
#define FLASH_READ_STAT_REG1             (0x05U)
#define FLASH_WRITE_ENABLE               (0x06U)
#define FLASH_SECTOR_ERASE               (0x20U)
#define FLASH_PAGE_PROGRAM               (0x02U)
#define FLASH_DUMMY_BYTE                 (0xFFU)
#define FLASH_DATA_READ                  (0x03U)


/*!
 *  @brief Flash object containing flash attributes.
 */
typedef struct W25QFL_Object {
    SPI_Handle       spiHandle;     /* Handle for SPI object */
}W25QFL_Object;

/*!
 *  @brief A handle that is returned from a W25QFL_open() call.
 */
typedef W25QFL_Object *W25QFL_Handle;

extern void W25QFL_close(W25QFL_Handle handle);
extern W25QFL_Handle W25QFL_open(unsigned int index, SPI_Params *params);
extern void W25QFL_FlashStatus(W25QFL_Handle handle);
extern void W25QFL_IsFlashBusy(W25QFL_Handle handle);
extern void W25QFL_SectorErase(W25QFL_Handle flashHandle);
extern void W25QFL_WriteEnable(W25QFL_Handle flashHandle);
extern uint32_t W25QFL_IsWriteSuccess(W25QFL_Handle flashHandle);
extern void W25QFL_WriteToFlash(W25QFL_Handle flashHandle);
extern void W25QFL_ReadFromFlash(W25QFL_Handle flashHandle);
extern bool W25QFL_VerifyData(void);

#ifdef __cplusplus
}
#endif

#endif /* __W25QFL_H */
