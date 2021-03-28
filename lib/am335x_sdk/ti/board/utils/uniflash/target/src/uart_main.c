/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file		uart_main.c
 *
 *  \brief		This file receives image with header from uart uniflash
 *				and flash on device mentioned in the header.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <xmodem.h>
#include <ti/board/utils/uniflash/target/soc/soc.h>

#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#ifdef SPI_FLASH
#include <spi.h>
#endif
#ifdef QSPI_FLASH
#include <qspi.h>
#endif
#ifdef OSPI_FLASH
#include <ospi.h>
#endif
#ifdef EMMC_FLASH
#include <emmc.h>
#endif
#ifdef HPF_FLASH
#include <hyperflash.h>
#endif

#if defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_evm)
#include <ti/osal/CacheP.h>
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

extern uint32_t DELAY;
extern uint8_t uart_inst;

static uint32_t gMaxBaudRate = UFP_BAUDRATE_115200;
static UART_Params gUartParams;
static UART_Handle gUartHanlde = NULL;
uint32_t gUfpBaudRateList[UFP_BAUDRATE_LIST_COUNT] = 
                                { UFP_BAUDRATE_115200,
                                  UFP_BAUDRATE_230400,
                                  UFP_BAUDRATE_460800,
                                  UFP_BAUDRATE_500000,
                                  UFP_BAUDRATE_576000,
                                  UFP_BAUDRATE_921600,
                                  UFP_BAUDRATE_1000000,
                                  UFP_BAUDRATE_1152000,
                                  UFP_BAUDRATE_1500000,
                                  UFP_BAUDRATE_2000000,
                                  UFP_BAUDRATE_2500000,
                                  UFP_BAUDRATE_3000000,
                                  UFP_BAUDRATE_3500000,
                                  UFP_BAUDRATE_4000000,
                                  UFP_BAUDRATE_6000000};

UFP_flashConfig UPF_flashFxnPtr[FLASH_DEVICE_MAX] = {
    { NULL }, /* Reserved for NAND Flash */

#if defined(SPI_FLASH)
    { &UFP_spiFxnTable },
#else
    { NULL },
#endif

#if defined(QSPI_FLASH)
    { &UFP_qspiFxnTable },
#else
    { NULL },
#endif

#if defined(OSPI_FLASH)
    { &UFP_ospiFxnTable },
#else
    { NULL },
#endif

#if defined(EMMC_FLASH)
    { &UFP_emmcFxnTable },
#else
    { NULL },
#endif

#if defined(HPF_FLASH)
    { &UFP_hpfFxnTable },
#else
    { NULL },
#endif

};

#if defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_evm)
#pragma DATA_SECTION(gSysFirmware, ".firmware")
uint32_t gSysFirmware[1];
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *	\brief		This function parses the received header based on the command.
 *
 *  \param      hdrBuf      [IN]    Header packet
 *  \param		offset		[OUT]   Pointer to store the address to flash.
 *	\param		eraseLen	[OUT]   Pointer to store the length to erased
 *									in flash erase.
 *	\param		devType		[OUT]   Pointer to store the device type to flash.
 *  \param		imgType  	[OUT]   Pointer to store the image type.
 *
 *	\return		int8_t
 *					0 	- in case of success
 *				   -1	- in case of failure
 *				   -2	- if it didn't receive header from uniflash
 *						  within timeout.
 *
 */
static int8_t UFP_parseHeader(unsigned char *hdrBuf,
                              uint8_t  *cmd,
                              uint32_t *offset,
                              uint32_t *eraseLen,
                              uint8_t *devType,
                              uint8_t *imgType)
{
    int16_t c;

    *cmd = hdrBuf[1];

	switch (hdrBuf[1])
    {
        case UFP_CMD_ERASE:
            *devType = hdrBuf[2] - '0';
            *offset = ((hdrBuf[7] << 24) | (hdrBuf[6] << 16) |
                       (hdrBuf[5] << 8) | (hdrBuf[4]));
            *eraseLen = ((hdrBuf[11] << 24) | (hdrBuf[10] << 16) |
                         (hdrBuf[9] << 8) | (hdrBuf[8]));
            if(*eraseLen == 0)
            {
                return -1;
            }
            break;
        case UFP_CMD_GET_MAX_BAUDRATE:
            outbyte(MAX_BAUDRATE_SUPPORTED);
            c = inbyte(DELAY);
#if defined(j721e_evm) || defined(am65xx_evm) || defined(am65xx_idk)
            if (c == XMODEM_STS_NSUP)
            {
                outbyte(MAX_BAUDRATE_SUPPORTED_LINUX);
                c = inbyte(DELAY);
            }
#endif
            if (c != XMODEM_STS_ACK)
                return -1;
            break;
        case UFP_CMD_PROGRAM:
            *devType = hdrBuf[2] - '0';
            *offset = ((hdrBuf[7] << 24) | (hdrBuf[6] << 16) |
                       (hdrBuf[5] << 8) | (hdrBuf[4]));
            *imgType = hdrBuf[3] - '0';
            break;
        case UFP_CMD_SET_BAUDRATE:
            gMaxBaudRate = gUfpBaudRateList[hdrBuf[2]];
            outbyte(XMODEM_STS_ACK);
            break;
        default:
            return -1;
    }

    c = inbyte(DELAY);
    if (c == XMODEM_CMD_EOT)
    {
        outbyte(XMODEM_STS_ACK);
    }
    else
    {
        return -1;
    }
    return 0;
}

/**
 *  \brief   Returns maximum baudrate configured by host
 *
 */
uint32_t UFP_getMaxBaudrate(void)
{
    return (gMaxBaudRate);
}

/**
 *  \brief   Initializes UART module
 *
 */
void UFP_uartInit(void)
{
    UART_Params_init(&gUartParams);
    UART_init();
}

/**
 *  \brief   Configures the UART instance with given baudrate
 *
 *  \return
 *				 0	- in case of success
 *				-1	- in case of failure.
 *
 */
int8_t UFP_uartConfig(uint32_t baudrate)
{
    UART_HwAttrs uartCfg;

    /*
     * UART configuration is needed for the first time or
     * when there is baudrate change needed
     */
    if((gUartParams.baudRate != baudrate) ||
       (gUartHanlde == NULL))
    {
        /* Close UART in case reconfiguring baudrate */
        UFP_uartClose();

        UART_socGetInitCfg(uart_inst, &uartCfg);
        uartCfg.enableInterrupt = FALSE;
        UART_socSetInitCfg(uart_inst, &uartCfg);

        gUartParams.baudRate = baudrate;
        gUartHanlde = UART_open(uart_inst, &gUartParams);
        if(gUartHanlde == NULL)
        {
            return -1;
        }
    }

    return 0;
}

/**
 *  \brief   Closes UART module
 *
 */
void UFP_uartClose(void)
{
    if(gUartHanlde != NULL)
    {
        UART_close(gUartHanlde);
        gUartHanlde = NULL;
    }
}

/**
 *  \brief   UART flash programmer main function.
 *
 *  \return  int - UART flash programmer status.
 *				 0	- in case of success
 *				-1	- in case of failure.
 *
 */
int main(void)
{
	uint32_t offset;
	uint32_t eraseLength;
	int16_t c;
    uint8_t command;
    uint8_t imgType;
	uint8_t devType;
	int8_t ret;
    unsigned char headerBuff[UFP_HEADER_PKT_SIZE];

    UFP_uartInit();

    if (UFP_socInit(NULL))
    {
		return -1;
    }

	while(1)
	{
		/* Receive header */
        ret = UFP_xModemHeaderReceive(&headerBuff[0]);
        if(ret != 0)
        {
            if (ret == -2)
                return 0; /* Didn't receive header from uniflash */
            outbyte(XMODEM_CMD_CAN);
            outbyte(XMODEM_CMD_CAN);
            return -1; /* Error while receiving header */
        }

        /* Header parsing */
        imgType = 0;
        ret = UFP_parseHeader(&headerBuff[0], &command, &offset, &eraseLength,
                              &devType, &imgType);
        if (ret != 0)
        {
            return -1;
        }

        /* Image type is system firmware.
           No need to flash onto boot device */
        if (imgType == UFP_IMAGE_SYSFW)
        {
#if defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_evm)
            offset = UFP_xModemFirmwareReceive((unsigned char *)gSysFirmware,
                                               UFP_SYSFW_SIZE);
            if(offset != 0)
            {
                CacheP_wbInv((void *)gSysFirmware, (int32_t)UFP_SYSFW_SIZE);
                ret = UFP_loadSysFW((void *)gSysFirmware);
                if (ret != 0)
                {
                    return -1;
                }
                continue;
            }
#endif
        }

        if((command == UFP_CMD_ERASE) || (command == UFP_CMD_PROGRAM))
        {
            if (UPF_flashFxnPtr[devType].UPF_fxnTablePtr->UFP_flashInit == NULL)
            {
                outbyte(XMODEM_CMD_CAN);
                outbyte(XMODEM_CMD_CAN);
                return -1;
            }
            else
            {
                ret = UPF_flashFxnPtr[devType].UPF_fxnTablePtr->UFP_flashInit();
                if (ret != 0)
                {
                    outbyte(XMODEM_CMD_CAN);
                    outbyte(XMODEM_CMD_CAN);
                    return -1;
                }
            }

            if (command == UFP_CMD_ERASE)
            {
                ret = UPF_flashFxnPtr[devType].UPF_fxnTablePtr->
                                               UFP_flashErase(offset, eraseLength);
            }
            else
            {
                ret = UFP_xModemFileReceive(offset, devType);
            }

            UPF_flashFxnPtr[devType].UPF_fxnTablePtr->UFP_flashClose();

            for (;;)
            {
                if (ret == 0)
                {
                    outbyte(XMODEM_STS_SUCCESS);
                }
                else
                {
                    outbyte(XMODEM_STS_FAILURE);
                }

                c = inbyte(DELAY);
                if(c == XMODEM_STS_ACK)
                {
                    break;
                }
            }
        }
	}
}
