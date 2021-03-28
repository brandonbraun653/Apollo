/**
 *  \file   apploader_main.c
 *
 *  \brief  This file implements the UART Apploader fuctionality.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

/* Header Files */
#include <ti/board/board.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_a15.h>
#if !defined(SOC_AM335x) && !defined(SOC_AM437x)
#include <sbl_slave_core_boot.h>
#include <sbl_avs_config.h>
#include <sbl_ver.h>
#include <sbl_rprc_parse.h>
#endif
#include "xmodem.h"

/**********************************************************************
************************** Macros ************************************
**********************************************************************/
#define VERSION "Version 0.1"

/**********************************************************************
************************** Internal functions ************************
**********************************************************************/
typedef void (*EntryFunPtr_t)(void);
extern int8_t socInit(void);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
extern uint32_t uart_baseAddr;
uint32_t gUartBaseAddr;

#if !defined(SOC_AM335x) && !defined(SOC_AM437x)
sblEntryPoint_t entry;
#endif

/**
 *  \brief		This function receives binary image over UART
 *				and copies the image to DDR.
 *
 *	\param		ddr_addr - pointer to the load address
 *
 *  \return		uint32_t
 *					 0		- in case of success
 *					-1		- in case of failure.
 *
 */
uint32_t uartReceiveImage(uint32_t ddr_addr)
{
	uint32_t retVal = TRUE;
	uint32_t max_size=128U * 1024U * 1024U;
	int32_t  receivedSize = 0;
	UART_printf("\nPlease transfer file with XMODEM protocol...\n");

	receivedSize =  xmodemReceive((unsigned char *)ddr_addr, max_size);

	 if(receivedSize < 0)
    {
        UART_printf("\nXmodem receive error\n");
        retVal = FALSE;
    }

    if(TRUE == retVal)
    {
        UART_printf("\nXmodem received %d bytes\n", receivedSize);
        UART_printf("\nCopying application image from UART"
                           " to RAM is done\n");
    }

    return retVal;
}

/**
 *  \brief		This function read the data from source address
 *				and copies to the destination address and moves
 *              the pointer to the size of the data copied.
 *
 *	\param		buff	 - pointer to the destination address
 *				srcAddr  - pointer to the source address
 * 				size     - size to be copied
 *
 *  \return		int32_t
 *			    E_PASS   - success
 *
 */
int32_t Apploader_MemRead(void       *buff,
                          void *srcAddr,
                          uint32_t    size)
{
	memcpy(buff, *((uint32_t *) srcAddr), size);
	*((uint32_t *) srcAddr) += size;
	return E_PASS;
}

/**
 *  \brief		This function increments the pointer to the specific
 *				offset location
 *
 *	\param		srcAddr  - pointer to the source address
 * 				location - offset to be incremented
 *
 */
void Apploader_MemSeek(void *srcAddr, uint32_t location)
{
   srcAddr = srcAddr+location;
}

/**
 *
 *  \brief	Main Function
 *
 */
int main()
{
    void (*func_ptr)(void);
	int32_t retVal;
	uint32_t ddr_addr = DDR_FLASH_ADDR;
	uint32_t pEntryPoint;

    /* SOC Init. */
	if (socInit())
    {
		return -1;
    }

    UART_printf("********* PDK UART Apploader ********\n");
	UART_printf("%s (%s - %s)\n", VERSION, __DATE__, __TIME__);

	gUartBaseAddr = uart_baseAddr;
	/* Receiving image over UART and copying to DDR */
	uartReceiveImage(ddr_addr);

#if defined (SOC_AM335x) || (SOC_AM437x)
	pEntryPoint = ddr_addr;
	UART_printf("Jumping to user application...\n");
    /* Giving control to the application */
    func_ptr = (void (*)(void)) pEntryPoint;
    (*func_ptr)( );
#else
	fp_readData = &Apploader_MemRead;
	fp_seek     = &Apploader_MemSeek;

	UART_printf("Begin parsing user application \n");
	retVal =  SBL_MulticoreImageParse((void *) &ddr_addr, 0, &entry);

#if defined(SOC_K2G) || (SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
	/* Cache Write back after image copy to ensure the slave cores are brought
    ** out of reset correctly.
    */
    CSL_a15WbAllDataCache();
#endif

	if (retVal == E_PASS)
	{
		UART_printf("Jumping to user application...\n");
		core_Bringup(&entry);
#if defined(SOC_OMAPL137)
		/*Jump to DSP0 APP*/
		if (entry.entryPoint_DSP0 != 0)
		{
			func_ptr = (void *) entry.entryPoint_DSP0;
			(*func_ptr)();
		}
#else
		/*Jump to MPU APP*/
		if (entry.entryPoint_MPU_CPU0 != 0)
		{
			func_ptr = (void *) entry.entryPoint_MPU_CPU0;
#if defined(SOC_K2G) || (SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
            CSL_a15WbAllDataCache();
            CSL_a15InvAllInstrCache();
            __sync_synchronize();
#endif
			(*func_ptr)();
		}
#endif
		else
		{
			while(1);
		}
	}
	else if (retVal == E_FAIL)
	{
		UART_printf("Error Parsing user application!!!\n");
	}
#endif
    return 0;
}
