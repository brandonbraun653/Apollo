/*
 * Copyright 2018 Georges Menie (www.menie.org)
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of California, Berkeley nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _XMODEM_H_
#define _XMODEM_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SOC_K2G
#include <ti/csl/src/ip/uart/V0/uart.h>
#else
#include <ti/csl/src/ip/uart/V1/uart.h>
#endif

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/csl/tistdtypes.h>

#include <flash_programmer.h>

#define DATA_BUFF_LEN           (4*1024U)
#define MAXRETRANS              (500U)

#define XMODEM_CMD_SOH          (0x01U)
#define XMODEM_CMD_STX          (0x02U)
#define XMODEM_CMD_EOT          (0x04U)
#define XMODEM_CMD_CAN          (0x18U)
#define XMODEM_STS_ACK          (0x06U)
#define XMODEM_STS_NAK          (0x15U)
#define XMODEM_STS_NSUP         (0x29U)
#define XMODEM_STS_SUCCESS      (0x2AU)
#define XMODEM_STS_FAILURE      (0x2BU)

/**
 *	\brief		This function generates delay in msec.
 *
 */
void delay(uint16_t delay_val);

/**
 *	\brief		This function reads a character from UART
 *				until a specified timeout.
 */
int32_t inbyte(uint32_t msec);

/**
 *  \brief		This function writes a character on UART
 */
void outbyte(uint8_t c);

/**
 *	\brief		This function receive the header information of the image
 *				from uniflash using xmodem protocol.
 */
int8_t UFP_xModemHeaderReceive(unsigned char *xbuff);

/**
 *	\brief		This function receives the image from uniflash and copies
 *				to the specified location of DDR using xmodem protocol.
 */
int8_t UFP_xModemFileReceive(uint32_t offset, uint8_t devType);

uint32_t UFP_xModemFirmwareReceive(unsigned char *dest, uint32_t destsz);

#ifdef __cplusplus
}
#endif

#endif /* _XMODEM_H_ */
