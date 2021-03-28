/**
 * \file   fl_main.c
 *
 * \brief  Framework loader main source file.
 *         For the pltforms with smaller internal RAM, two stage
 *         booting is used from SBL to accommodate both SBL and
 *         diagnostic framework in the internal RAM. SBL loads the
 *         framework loader which gets executed from DDR and loads
 *         the diagnostic framework to internal memory used by SBL.
 */

/**
 * \copyright Copyright (C) 2013-2018 Texas Instruments Incorporated -
 *            http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#if defined(SOC_AM335x) || defined(SOC_AM437x)
#ifdef iceAMIC110
#include "diag_spi.h"
#else
#include "diag_mmc.h"
#endif
#else
#include <stdio.h>
#include <ti/fs/fatfs/FATFS.h>
#include <ti/fs/fatfs/ff.h>

#include <ti/drv/uart/UART_stdio.h>

#include <ti/boot/sbl/src/rprc/sbl_rprc_parse.h>
#endif
#include "board.h"


#ifndef iceAMIC110

FATFS_Handle fatfsHandle;

int32_t FL_fread(void *buff, void *fileptr, uint32_t size);
void FL_fseek(void *fileptr, uint32_t location);

void FL_load()
{
    int32_t retVal;
    FIL fp;
    FRESULT fresult;
    sblEntryPoint_t pEntry;
    void (*func_ptr)();

    FATFS_init();

    FATFS_open(0U, 0U, &fatfsHandle);

#if defined(SOC_K2G) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
    fp_readData = &FL_fread;
    fp_seek = &FL_fseek;
#endif

    UART_printf("\nOpening framework from SD card...\n");
    fresult = f_open(&fp, "/framework", (uint8_t) FA_READ);
    if (fresult != FR_OK)
    {
        UART_printf("Failed to open framework\n");
        return;
    }
    else
    {
        UART_printf("Loading framework into memory...\n");
        retVal = SBL_MulticoreImageParse((void *) &fp, 0, &pEntry);
        f_close(&fp);
        if (retVal != E_PASS)
        {
            UART_printf("Error in parsing framework\n");
            return;
        }
        else
        {
            if (pEntry.entryPoint_MPU_CPU0 == 0)
            {
                UART_printf("Unable to get entry point\n");
                return;
            }
            else
            {
                UART_printf("Running framework\n");
                func_ptr = (void *) pEntry.entryPoint_MPU_CPU0;
#if defined(SOC_K2G) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
                CSL_a15WbAllDataCache();
                CSL_a15InvAllInstrCache();
                __sync_synchronize();
#endif
                (*func_ptr)();
            }
        }
    }
}

int32_t FL_fread(void *buff, void *fileptr, uint32_t size)
{
    FIL     *fp         = (FIL *) (fileptr);
    uint32_t i          = 0;
    uint32_t bytes_read = 0;
    uint32_t Max_read   = 0x400U;
    FRESULT  fresult    = FR_OK;

    for (i = 0; i < (size / Max_read); ++i)
    {
        fresult  = f_read(fp, buff, Max_read, &bytes_read);
        buff += bytes_read;
        if (fresult != FR_OK)
        {
            break;
        }
    }
    if (fresult == FR_OK)
    {
        fresult = f_read(fp, buff, (uint16_t) (size % Max_read), &bytes_read);
    }

    return fresult;
}

void FL_fseek(void *fileptr, uint32_t location)
{
    FIL *fp = (FIL *) (fileptr);
    f_lseek(fp, location);
}

#else
void FL_load()
{
    int32_t retVal;
    sblEntryPoint_t pEntry;
    void (*func_ptr)();

    UART_printf("Loading framework into memory...\n");
    retVal = SBL_MulticoreImageParse(&pEntry);
    if (retVal != E_PASS)
    {
        UART_printf("Error in parsing framework\n");
        return;
    }
    else
    {
        if (pEntry.entryPoint_MPU_CPU0 == 0)
        {
            UART_printf("Unable to get entry point\n");
            return;
        }
        else
        {
            UART_printf("Running framework\n");
            func_ptr = (void *) pEntry.entryPoint_MPU_CPU0;
            (*func_ptr)();
        }
    }
}
#endif  /* #ifndef iceAMIC110 */

int main()
{
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    FL_load();

    return 0;
}
