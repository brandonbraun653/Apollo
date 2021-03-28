/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *  \file  evmc66x_qspi.h
 *
 *  \brief This file contains QSPI specific structure, typedefs, function
 *		   prototypes.
 *
 ******************************************************************************/

#ifndef	_EVMC66X_QSPI_H_
#define	_EVMC66X_QSPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Handle to access QSPI registers */
typedef CSL_QspiRegs * hQspiHandle;


/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Operation timeout value */
#define QSPI_TIMEOUT_US                        (5000 * 1000)/**In Microsecond */
#define QSPI_POLL_IDLE_RETRY                   (3)
#define QSPI_REG_RETRY                         (10000)
#define QSPI_FIFO_WIDTH                        (4)

/** QSPI return type macros */
#define QSPI_ERR                               (-1)
#define QSPI_SUCCESS                           (0)

/** Macro to access QSPI_AHB_BASE */
#define   QSPI_0_DATA                          (*((volatile uint32_t *) (CSL_QSPI_0_DATA)))

/** Instruction type */
#define QSPI_INST_TYPE_SINGLE                  (0)
#define QSPI_INST_TYPE_DUAL                    (1)
#define QSPI_INST_TYPE_QUAD                    (2)

/** Controller sram size in word */
#define QSPI_REG_SRAM_SIZE_WORD                (128)
#define QSPI_REG_SRAM_RESV_WORDS               (2)
#define QSPI_REG_SRAM_PARTITION_WR             (1)
#define QSPI_REG_SRAM_PARTITION_RD                             \
	(QSPI_REG_SRAM_SIZE_WORD - QSPI_REG_SRAM_RESV_WORDS)
#define QSPI_REG_SRAM_THRESHOLD_WORDS          (50)

/** Chip selection Macros */
#define QSPI_DECODER_SEL                      (0)
#define QSPI_CS0                              (~(1 << 0))
#define QSPI_CS1                              (~(1 << 1))
#define QSPI_CS2                              (~(1 << 2))
#define QSPI_CS3                              (~(1 << 3))
#define QSPI_CS_NONE                          (~0x0)

/** QSPI function return status */
#define QSPI_STATUS              int8_t

/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 * \brief     To initialize QSPI module.This function should be called before
 *            using any other QSPI functions.
 *
 * \param     FlashpageSize : Page size of the FLASH device connected.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 */
QSPI_STATUS qspiInit(uint32_t FlashpageSize);

/**
 * \brief     To perform STIG write.It sends command and writes data into
 *            FLASH device.This is used for sending commands WRR,WREN, WRDI, BE,
 *            SE etc..
 *
 * \param     cmdBuf [IN] : Command sent to FLASH device.
 * \param     cmdLen [IN] : Length of the command in bytes.
 * \param     txBuf  [IN] : Pointer to the data to be transferred.
 * \param     txLen  [IN] : Length of the data to be transferred in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiCommandWrite(uint8_t *cmdBuf, uint32_t cmdLen, uint8_t *txBuf,
			                 uint32_t txLen);

/**
 * \brief     To perform STIG read.It sends command and recieves the response
 *            data from FLASH device.This is used for sending command RDID,RDSR.
 *
 * \param     cmdBuf [IN] : Command sent to FLASH device.
 * \param     cmdLen [IN] : Length of the command in bytes.
 * \param     rxBuf  [IN] : Pointer to the received data.
 * \param     rxLen  [IN] : Length of the received data in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiCommandRead(uint8_t *cmdBuf, uint32_t cmdLen, uint8_t *rxBuf,
		                    uint32_t rxLen);

/**
 * \brief     To perform Indirect Write Transfer.
 *
 * \param     addr    [IN] : FLASH device start address from where indirect
 *                           access will commence its write operation.
 * \param     cmd     [IN] : Command sent to FLASH device.
 * \param     txBuf   [IN] : Pointer to the data to be transferred.
 * \param     txLen   [IN] : Length of the data to be transferred in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiWrite(uint32_t addr, uint8_t* cmd, uint8_t* txBuf,
                      uint32_t txLen);

/**
 * \brief     To perform Indirect Read Transfer.
 *
 * \param     addr    [IN] : FLASH device start address from where indirect
 *                           access will commence its read operation.
 * \param     cmd     [IN] : Command sent to FLASH device.
 * \param     rxBuf   [IN] : Pointer to the received data.
 * \param     rxLen   [IN] : Length of the received data in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiRead(uint32_t addr, uint8_t* cmd, uint8_t* rxBuf,
                     uint32_t rxLen);

#ifdef __cplusplus
}
#endif

#endif // _EVMC66X_QSPI_H_

/* Nothing past this point */
