/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
 */

#include "diag_spi.h"
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/uart/UART_stdio.h>

extern const SPI_Config SPI_config[];

uint8_t wrBuf[MAX_DATA_BUFF_SIZE];
uint8_t rdBuf[MAX_DATA_BUFF_SIZE];

/* Function to copy framework image from SPI flash.
   This function reads the framework loader image from the SPI flash
   written at offset 'FL_IMAGE_OFFSET'.
   This function is similar to StarterWare SBL image copy function for
   SPI boot. Implemented here again to avoid the dependency on
   StarterWare SPI library APIs.*/
static int32_t spiImageCopy(uint32_t *pEntryPoint, uint32_t instNum)
{
	SPI_Params spiParams;                /* SPI params structure */
    SPI_Handle handle;                   /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction */
    ti_header imageHdr;
    bool retVal = false;                 /* return value */
    uint32_t i;
	uint32_t img_size, img_data_len;
	uint8_t  *pDestAddr;
	uint32_t img_offset;

	transaction.txBuf = &wrBuf[0];
	transaction.rxBuf = &rdBuf[0];

    /* Image copy is done in poll mode. Disable interrupts. */
	for (i=0; i<CSL_MCSPI_PER_CNT; i++)
    {
        ((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->enableIntr = false;
		((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->chNum = 0;
    }

    /* Initialize and configure SPI for flash access */
	SPI_init();
    SPI_Params_init(&spiParams);
  	handle = SPI_open(instNum, &spiParams);
	if(handle == NULL)
    {
        UART_printf("\r\n SPI Open Failed!\r\n");
        return (E_FAIL);
    }
    
    memset(wrBuf, 0, MAX_DATA_BUFF_SIZE);
    
    /* Read image header from the flash */
    img_offset = FL_IMAGE_OFFSET;	 
	wrBuf[0] = 0x03;
	wrBuf[1] = ((img_offset >> 16U));
	wrBuf[2] = ((img_offset >> 8U));
	wrBuf[3] = (img_offset);
	
    transaction.count = (WRITE_CMD_SIZE + IMG_HDR_SIZE);
	retVal = SPI_transfer(handle, &transaction);
    if(retVal != true)
    {
        UART_printf("\r\n SPI Data Transfer Failed!\r\n");
        return (E_FAIL);
    }
 
    memcpy((void*)&imageHdr, &rdBuf[4], IMG_HDR_SIZE);
    
	img_size     = (imageHdr.image_size - IMG_HDR_SIZE);
	pDestAddr    = (uint8_t *)imageHdr.load_addr;
	*pEntryPoint = imageHdr.load_addr;
	img_offset  += IMG_HDR_SIZE;

	/* Reading the image data from the flash */
	while(img_size > 0)
	{
        wrBuf[0] = 0x03;
        wrBuf[1] = ((img_offset >> 16U));
        wrBuf[2] = ((img_offset >> 8U));
        wrBuf[3] = (img_offset);
        
        transaction.count  = MAX_DATA_BUFF_SIZE;
        retVal = SPI_transfer(handle, &transaction);
        if(retVal != true)
        {
            UART_printf("\r\n SPI Data Transfer Failed!\r\n");
            return (E_FAIL);
        }
        
        if(img_size < APP_DATA_BUFF_SIZE)
        {
            img_data_len = img_size;
        }            
        else
        {
            img_data_len = APP_DATA_BUFF_SIZE;
        }           
        
        memcpy(pDestAddr, &rdBuf[4], img_data_len);

        pDestAddr  += img_data_len;
        img_offset += img_data_len;
        img_size   -= img_data_len;
	}
    
	SPI_close(handle);
    
    return (E_PASS);
}

/* Fucntion to parse the images on SPI flash */
int32_t SBL_MulticoreImageParse(sblEntryPoint_t *sblEntry)
{
    int32_t retStat = E_PASS;
    uint32_t *pEntryPoint = &sblEntry->entryPoint_MPU_CPU0;

	UART_printf("Copying application image from SPI FLASH to RAM\r\n");
	retStat = spiImageCopy(pEntryPoint, MCSPI_INSTANCE);
	if(E_PASS != retStat)
	{
		UART_printf("\r\n Error reading application file\r\n");
	}
    
    /* Return status */
    return retStat;
}
