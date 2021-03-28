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

#ifndef __XMODEM_H_
#define __XMODEM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr_device.h>
#include <ti/drv/uart/UART.h>
#if defined(SOC_K2G) || defined(SOC_OMAPL137)
#include <ti/csl/src/ip/uart/V0/uart.h>
#else
#include <ti/csl/src/ip/uart/V1/uart.h>
#endif
#include <string.h>

/**********************************************************************
************************** Macros ************************************
**********************************************************************/
#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#define DDR_FLASH_ADDR		(0xC0000000U)
#elif !defined(SOC_AM335x) && !defined(SOC_AM437x)
#define DDR_FLASH_ADDR		(0x82000000U)
#else
#define DDR_FLASH_ADDR		(0x80000000U)
#endif

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
 *	\brief		This function receives the binary over UART
 *				from Apploader using xmodem protocol.
 */
int xmodemReceive(unsigned char *dest, int destsz);

#ifdef __cplusplus
}
#endif

#endif /* _XMODEM_H_ */
