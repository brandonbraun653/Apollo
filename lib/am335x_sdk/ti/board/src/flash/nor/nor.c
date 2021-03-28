/*
 * Copyright (c) 2016-2020, Texas Instruments Incorporated
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

#include <ti/board/src/flash/nor/nor.h>
#include <ti/board/src/flash/include/board_flash.h>

uint32_t Nor_intf;

#if defined (evmK2G)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        &Nor_spiFxnTable
    },
    {
        &Nor_qspiFxnTable
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    }
};
#elif defined (iceK2G)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        NULL
    },
    {
        &Nor_qspiFxnTable
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    }
};
#elif defined (am65xx_evm) || defined (am65xx_idk)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        &Nor_ospiFxnTable
    },
    {
        NULL
    }
};
#elif defined (j721e_sim) || defined (j721e_evm) || defined(j7200_evm)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        NULL
    },
    {
        &Nor_qspiFxnTable
    },
    {
        NULL
    },
    {
        &Nor_ospiFxnTable
    },
    {
        &Nor_hpfFxnTable
    }
};
#elif defined (icev2AM335x)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        NULL
    },
    {
        NULL
    },
    {
        &Nor_gpmcFxnTable
    },
    {
        NULL
    },
    {
        NULL
    }
};
#elif defined (evmK2H) || defined (evmK2K) || defined (evmK2L) ||  defined (evmK2E) || defined (evmC6678) || defined (evmC6657) || defined (evmOMAPL137)
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        &Nor_spiFxnTable
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    }
};
#else
NOR_Config Nor_config[BOARD_FLASH_NOR_INTF_MAX] =
{
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    },
    {
        NULL
    }
};
#endif

/*
 *  ======== NOR_open ========
 */
NOR_HANDLE NOR_open(uint32_t norIntf, uint32_t portNum, void *params)
{
    NOR_HANDLE handle = 0;

    if ((norIntf < BOARD_FLASH_NOR_INTF_MAX) && Nor_config[norIntf].fxnTablePtr)
    {
        handle = Nor_config[norIntf].fxnTablePtr->openFxn(norIntf, portNum, params);
        if (handle)
        {
            Nor_intf = norIntf;
        }
    }

    return handle;
}

/*
 *  ======== NOR_close ========
 */
void NOR_close(NOR_HANDLE handle)
{
    Nor_config[Nor_intf].fxnTablePtr->closeFxn(handle);
}

/*
 *  ======== NOR_read ========
 */
NOR_STATUS NOR_read(NOR_HANDLE handle, uint32_t addr,
                    uint32_t len, uint8_t *buf, uint32_t mode)
{
    return (Nor_config[Nor_intf].fxnTablePtr->readFxn(handle, addr, len, buf, mode));
}

/*
 *  ======== NOR_write ========
 */
NOR_STATUS NOR_write(NOR_HANDLE handle, uint32_t addr,
                     uint32_t len, uint8_t *buf, uint32_t mode)
{
    return (Nor_config[Nor_intf].fxnTablePtr->writeFxn(handle, addr, len, buf, mode));
}

/*
 *  ======== NOR_erase ========
 */
NOR_STATUS NOR_erase(NOR_HANDLE handle, int32_t blk, bool blkErase)
{
    return (Nor_config[Nor_intf].fxnTablePtr->eraseFxn(handle, blk, blkErase));
}
