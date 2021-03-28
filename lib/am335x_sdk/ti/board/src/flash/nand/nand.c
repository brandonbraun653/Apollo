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
 *
 */

#include <ti/board/src/flash/nand/nand.h>
#include <ti/board/src/flash/include/board_flash.h>

uint32_t Nand_intf;

#if defined (evmAM437x)
NAND_Config Nand_config[BOARD_FLASH_NAND_INTF_MAX] =
{
    {
        &Nand_gpmcFxnTable
    },
    {
        NULL
    }
};
#else
NAND_Config Nand_config[BOARD_FLASH_NAND_INTF_MAX] =
{
    {
        NULL
    },
    {
        NULL
    }
};
#endif

NAND_HANDLE NAND_open(uint32_t nandIntf, uint32_t portNum, void *params)
{
    NAND_HANDLE handle = 0;

    if ((nandIntf < BOARD_FLASH_NAND_INTF_MAX) && Nand_config[nandIntf].fxnTablePtr)
    {
        handle = Nand_config[nandIntf].fxnTablePtr->openFxn(nandIntf, portNum, params);
        if (handle)
        {
            Nand_intf = nandIntf;
        }
    }

    return handle;
}

/*
 *  ======== NAND_close ========
 */
void NAND_close(NAND_HANDLE handle)
{
    Nand_config[Nand_intf].fxnTablePtr->closeFxn(handle);
}

/*
 *  ======== NAND_read ========
 */
NAND_STATUS NAND_read(NAND_HANDLE handle, uint32_t addr,
                            uint32_t len, uint8_t *buf)
{
    return (Nand_config[Nand_intf].fxnTablePtr->readFxn(handle, addr, len, buf));
}


/*
 *  ======== NAND_write ========
 */
NAND_STATUS NAND_write(NAND_HANDLE handle, uint32_t addr,
                       uint32_t len, uint8_t *buf)
{
    return (Nand_config[Nand_intf].fxnTablePtr->writeFxn(handle, addr, len, buf));
}


NAND_STATUS NAND_erase(NAND_HANDLE handle, int32_t blk)
{
    return (Nand_config[Nand_intf].fxnTablePtr->eraseFxn(handle, blk));
}

