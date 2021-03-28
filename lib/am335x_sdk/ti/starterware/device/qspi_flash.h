/**
 * \file       qspi_flash.h
 *
 * \brief      This file contains the device data for QSPI flash
 *             devices. It contains a structure which captures the
 *             data which is different for different flash devices.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

#ifndef QSPI_FLASH_H_
#define QSPI_FLASH_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                          Macros and typedefs                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief This structure contains the device data for different flash devices
 *        which can be connected to the QSPI controller.
 *        Only the flash device specific data is captured here
 */
typedef struct qspiFlashDeviceData
{
    uint32_t devId;
    /**< Device ID of the QSPI flash */
    uint32_t quadReadCmd;
    /**< The command to read the register where the quad enable bit has
     *   to be set */
    uint32_t quadWriteCmd;
    /**< The command to write to the register where the quad enable bit has
     *   to be set */
    uint32_t quadEnableBit;
    /**< The quad enable bit which needs to be set/reset in the register to enable
     *   the quad mode of the QSPI flash device */
    uint32_t quadValue;
    /**< The value to be written to enable quad functionality i.e. 0 or 1 */
}qspiFlashDeviceData_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the QSPI flash related data according to the
 *        flash device connected to the board.
 *
 * \param devId The device id of the device that is connected to QSPI
 *                   controller.
 *
 * \retval QSPI_Device_Data Pointer to the QSPI device data.
 */
qspiFlashDeviceData_t *QSPIFlashGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of QSPI flash devices
 *        available
 *
 * \retval QSPI_Flash_Device_Id_List Pointer to the QSPI flash device ID list
 */
uint32_t * QSPIFlashGetDeviceIdList(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef QSPI_FLASH_H_ */

