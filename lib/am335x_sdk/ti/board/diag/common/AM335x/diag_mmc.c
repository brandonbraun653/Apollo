/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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

#include "diag_mmc.h"

/* MMCSD function table for MMCSD implementation */
FATFS_DrvFxnTable FATFS_drvFxnTable = {
    MMCSD_close,
    MMCSD_control,
    MMCSD_init,
    MMCSD_open,
    MMCSD_write,
    MMCSD_read
};

/* FATFS configuration structure */
FATFS_HwAttrs FATFS_initCfg[_VOLUMES] =
{
    {
        0U
    },
    {
        1U
    },
    {
        2U
    },
    {
        3U
    }
};

/* FATFS objects */
FATFS_Object FATFS_objects[_VOLUMES];

/* FATFS configuration structure */
const FATFS_Config FATFS_config[_VOLUMES + 1] = {
    {
        &FATFS_drvFxnTable,
        &FATFS_objects[0],
        &FATFS_initCfg[0]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[1],
         &FATFS_initCfg[1]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[2],
         &FATFS_initCfg[2]
    },

    {NULL, NULL, NULL},

    {NULL, NULL, NULL}
};

char gTmpBuf[SBL_MMCSD_DATA_BUF_SIZE] __attribute__ ((aligned (32U)));

int32_t SBL_MulticoreImageParse(FIL *fp, uint8_t dummy, sblEntryPoint_t *sblEntry)
{
    FRESULT fResult;
    uint32_t bytesRead = 0U;
    ti_header imageHdr;
    uint8_t *pDestAddr;
    int32_t retStat = E_PASS;
    uint32_t *pEntryPoint = &sblEntry->entryPoint_MPU_CPU0;
	UART_printf("Copying application image from MMC/SD card to RAM\r\n");
	fResult = f_read(fp, (uint8_t *)&imageHdr, 8U,
					 (uint32_t *)&bytesRead);

	if(FR_OK != fResult)
	{
		UART_printf("\r\n Error reading application file\r\n");
		retStat = E_FAIL;
	}

	if(8U != bytesRead)
	{
		retStat = E_FAIL;
	}

	pDestAddr = (uint8_t *)imageHdr.load_addr;
	*pEntryPoint = imageHdr.load_addr;   

    if(E_PASS == retStat)
    {
        /*
         * Enter a loop to repeatedly read data from the file and display it, until
         * the end of the file is reached.
         */
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in the
             * temporary buffer, including a space for the trailing null.
             */
            fResult = f_read(fp, gTmpBuf, sizeof(gTmpBuf) - 1,
                             (uint32_t *)&bytesRead);

            /*
             * If there was an error reading, then print a newline and return the
             * error to the user.
             */
            if(fResult != FR_OK)
            {
                UART_printf("\r\n Error reading application file\r\n");
                retStat = E_FAIL;
            }

            if(bytesRead >= sizeof(gTmpBuf))
            {
                retStat = E_FAIL;
            }

            /* Read the last chunk of the file that was received. */
            memcpy(pDestAddr, gTmpBuf, (sizeof(gTmpBuf) - 1));
            pDestAddr += (sizeof(gTmpBuf) - 1);
            /*
             * Continue reading until less than the full number of bytes are read.
             * That means the end of the buffer was reached.
             */
        }
        while((bytesRead == sizeof(gTmpBuf) - 1) && (E_PASS == retStat));
    }

    /* Return success. */
    return retStat;
}
