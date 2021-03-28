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

#ifndef _DIAG_SPI_H_
#define _DIAG_SPI_H_

#define AM335X_FAMILY_BUILD

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ti/csl/tistdtypes.h>

#include <ti/drv/uart/UART_stdio.h>

#include <ti/starterware/bootloader/include/sbl_copy.h>

#define E_PASS               (0)
#define E_FAIL               (-1)

/* Framework image resides at 0x40000 location */
#define FL_IMAGE_OFFSET      (256 * 1024U)
#define MCSPI_INSTANCE       (0)
#define CSL_MCSPI_PER_CNT    (1U)
#define APP_DATA_BUFF_SIZE   (256U)
#define WRITE_CMD_SIZE       (4U)
#define MAX_DATA_BUFF_SIZE   (APP_DATA_BUFF_SIZE + WRITE_CMD_SIZE)
#define IMG_HDR_SIZE         (8U)

typedef struct sblEntryPoint
{
    uint32_t    entryPoint_MPU_CPU0;
}sblEntryPoint_t;

int32_t SBL_MulticoreImageParse(sblEntryPoint_t *sblEntry);

#endif
