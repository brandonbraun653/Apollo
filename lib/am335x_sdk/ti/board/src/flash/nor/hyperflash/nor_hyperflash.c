/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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

#include <ti/board/src/flash/nor/hyperflash/nor_hyperflash.h>

static NOR_HANDLE Nor_hpfOpen(uint32_t norIntf, uint32_t portNum, void *params);
static void Nor_hpfClose(NOR_HANDLE handle);
static NOR_STATUS Nor_hpfRead(NOR_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_hpfWrite(NOR_HANDLE handle, uint32_t addr,
                                uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_hpfErase(NOR_HANDLE handle, int32_t block, bool erase);
static NOR_STATUS Nor_hpfWaitDevReady(NOR_HANDLE handle, uint32_t timeOut);

/* NOR function table for NOR Hyperflash implementation */
const NOR_FxnTable Nor_hpfFxnTable =
{
    &Nor_hpfOpen,
    &Nor_hpfClose,
    &Nor_hpfRead,
    &Nor_hpfWrite,
    &Nor_hpfErase,
};

/* This structure contains information about the NOR hyperflash device */
NOR_Info Nor_hpfInfo =
{
    0,                          /* hwHandle */
    0,                          /* manufacturerId */
    0,                          /* deviceId */
    0,                          /* busWidth */
    NOR_NUM_SECTORS,            /* sectorCnt */
    NOR_NUM_PAGES_PER_SECTOR,   /* pageCnt */
    NOR_PAGE_SIZE               /* pageSize */
};

/* Default hyperflash configuration params */
HPF_Params HPF_defaultParams = {
    0,
    CSL_MCU_FSS0_DAT_REG1_BASE,
    0,
    {0}
};

/* Global hyperflash object */
HPF_Object gHpfObject;

/**
 * \brief   This function checks the device ready status within the time period.
 *
 * \param   handle  [IN] Flash handle
 * \param   timeOut [IN] Timeout period to wait for device ready status
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
static NOR_STATUS Nor_hpfWaitDevReady(NOR_HANDLE handle, uint32_t timeOut)
{
    NOR_STATUS  retVal = NOR_TIMEOUT;
    NOR_Info *norInfoHandle;
    HPF_Object *hpfObject;
    uint8_t status = 0;

    norInfoHandle = (NOR_Info *)handle;
    hpfObject = (HPF_Object *)norInfoHandle->hwHandle;

    while(1)
    {
        HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_READ_DEV_STS);
        status = HW_RD_REG16(hpfObject->baseAddr);
        if (status == NOR_DEV_READY_STATUS)
        {
            retVal = NOR_PASS;
            break;
        }

        timeOut--;
        if(!timeOut)
        {
            break;
        }
    }

    return retVal;
}

/**
 * \brief   Nor HyperFlash ID read function.
 *
 *  This function is used to read device ID and manufacturer ID of
 *  hyperflash device.
 *
 * \param   Nor_hpfInfo [IN]  Hyperflash device Info structure
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
static NOR_STATUS Nor_hpfReadId(NOR_Info *Nor_hpfInfo)
{
    NOR_STATUS retVal = NOR_FAIL;
    HPF_Object *hpfObject;
    uint16_t manfID, devID;
    uint16_t queryStr[3];
    uint32_t count = 0;

    hpfObject = (HPF_Object *)Nor_hpfInfo->hwHandle;

    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_WRITE_UNLOCK1);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR2), NOR_CMD_WRITE_UNLOCK2);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_CFI_ENTRY);

    /* To confirm the DLL lock, Reading CFI registers for maximum 20 times */
    while(count < NOR_HPF_DLL_LOCK_MAX_CHECK)
    {
        queryStr[0] = HW_RD_REG16(hpfObject->baseAddr + NOR_HPF_QUERY_REG1);
        queryStr[1] = HW_RD_REG16(hpfObject->baseAddr + NOR_HPF_QUERY_REG2);
        queryStr[2] = HW_RD_REG16(hpfObject->baseAddr + NOR_HPF_QUERY_REG3);

        manfID = HW_RD_REG16(hpfObject->baseAddr + NOR_HPF_MANF_ID_ADDR);
        devID = HW_RD_REG16(hpfObject->baseAddr + NOR_HPF_DEV_ID_ADDR);

        if ((manfID == NOR_MANF_ID) && (devID == NOR_DEVICE_ID)
            && queryStr[0] == 'P' && queryStr[1] == 'R' && queryStr[2] == 'I')
        {
            Nor_hpfInfo->manufacturerId = manfID;
            Nor_hpfInfo->deviceId = devID;
            retVal = NOR_PASS;
            break;
        }
        count++;
    }

    HW_WR_REG16((hpfObject->baseAddr), NOR_CMD_RESET);

    return(retVal);
}

/**
 * \brief   This function is used to open hyperflash handle.
 *
 * \param   norIntf     [IN]    Type of Nor device
 * \param   portNum     [IN]    Instance number
 * \param   params      [IN]    Hyperflash configuration parameter
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
NOR_HANDLE Nor_hpfOpen(uint32_t norIntf, uint32_t portNum, void *params)
{
    NOR_HANDLE              hpfHandle = 0;
    HPF_Params              hpfParams;  /* HyperFlash params structure */
    CSL_hyperbus_coreRegs   *hpbCoreRegs = (CSL_hyperbus_coreRegs *)CSL_FSS0_HPB_CTRL_BASE;
    int32_t retVal;

    if (gHpfObject.isOpen != TRUE)
    {
        /* Enabling hyperbus in FSS0 */
        CSL_REG32_WR(MCU_FSS0_SYSCONFIG, ENABLE_FSS0_HPB);

        if (params)
        {
            memcpy(&hpfParams, params, sizeof(HPF_Params));
        }
        else
        {
            hpfParams = HPF_defaultParams;
        }

        retVal = CSL_hyperbusSetCSBaseAddr(hpbCoreRegs,
                                           hpfParams.chipSelect,
                                           hpfParams.baseAddress);
        if (retVal != CSL_PASS)
        {
            return hpfHandle;
        }

        retVal = CSL_hyperbusSetMemTiming(hpbCoreRegs,
                                          hpfParams.chipSelect,
                                          &(hpfParams.hyperbusTimingConfig));
        if (retVal != CSL_PASS)
        {
            return hpfHandle;
        }

        gHpfObject.baseAddr = hpfParams.regionAddress + hpfParams.baseAddress;
        gHpfObject.cs = hpfParams.chipSelect;
        Nor_hpfInfo.hwHandle = (NOR_HANDLE)(&gHpfObject);
        if (Nor_hpfReadId(&Nor_hpfInfo) == NOR_PASS)
        {
            gHpfObject.isOpen = 1;
            hpfHandle = (NOR_HANDLE)(&Nor_hpfInfo);
        }

        return (hpfHandle);
    }

    return hpfHandle;
}

/**
 * \brief   This function is used to close hyperflash handle.
 *
 * \param   handle      [IN]    Nor Handle
 *
 */
void Nor_hpfClose(NOR_HANDLE handle)
{
    NOR_Info *norInfoHandle;
    HPF_Object *hpfObject;

    norInfoHandle = (NOR_Info *)handle;
    hpfObject = (HPF_Object *)norInfoHandle->hwHandle;

    HW_WR_REG16(hpfObject->baseAddr, NOR_CMD_RESET);
    hpfObject->isOpen = FALSE;

    /* Disabling hyperbus in FSS0 */
    CSL_REG32_WR(MCU_FSS0_SYSCONFIG, DISABLE_FSS0_HPB);
}

/**
 * \brief   This function is used to read data from hyperflash memory.
 *
 * \param   handle      [IN]    Nor Handle
 * \param   addr        [IN]    Address to read
 * \param   len         [IN]    Number of bytes to read
 * \param   buf         [IN]    Pointer to store the data
 * \param   mode        [IN]    Read mode
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
NOR_STATUS Nor_hpfRead(NOR_HANDLE handle, uint32_t addr,
                       uint32_t len, uint8_t *buf, uint32_t mode)
{
    NOR_Info *norInfoHandle;
    HPF_Object *hpfObject;
    NOR_STATUS  retVal;
    uint32_t rdCnt;

    norInfoHandle = (NOR_Info *)handle;
    hpfObject = (HPF_Object *)norInfoHandle->hwHandle;

    /* Reading data from hyperflash */
    for(rdCnt = 0; rdCnt < len; rdCnt+=2)
    {
        buf[rdCnt] = HW_RD_REG16(hpfObject->baseAddr + addr + rdCnt);
        buf[rdCnt+1] = (HW_RD_REG16(hpfObject->baseAddr + addr + rdCnt) >> 8);
    }

    retVal = Nor_hpfWaitDevReady(handle, NOR_WRR_READ_TIMEOUT);

    return retVal;
}

/**
 * \brief   This function is used to write data onto hyperflash memory.
 *
 * \param   handle      [IN]    Nor Handle
 * \param   addr        [IN]    Address to write
 * \param   len         [IN]    Number of bytes to write
 * \param   buf         [IN]    Pointer to the data to be write
 * \param   mode        [IN]    Write mode
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
NOR_STATUS Nor_hpfWrite(NOR_HANDLE handle, uint32_t addr, uint32_t len,
                        uint8_t *buf, uint32_t mode)
{
    NOR_Info *norInfoHandle;
    HPF_Object *hpfObject;
    NOR_STATUS  retVal;
    uint32_t wrLength = 0;
    uint32_t wrCnt = 0;
    uint32_t bufLen = 0;

    norInfoHandle = (NOR_Info *)handle;
    hpfObject = (HPF_Object *)norInfoHandle->hwHandle;

    do
    {
        if (len > NOR_MAX_WRITE_LEN)
        {
            wrLength = NOR_MAX_WRITE_LEN;
        }
        else
        {
            wrLength = len;
        }

        HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_WRITE_UNLOCK1);
        HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR2), NOR_CMD_WRITE_UNLOCK2);
        HW_WR_REG16((hpfObject->baseAddr + addr), NOR_CMD_WRITE_BUFFER);
        HW_WR_REG16((hpfObject->baseAddr + addr), (wrLength/2) - 1);

        for (wrCnt = 0; wrCnt < wrLength; wrCnt += 2)
        {
            HW_WR_REG16(hpfObject->baseAddr + addr + wrCnt,
                        ((uint16_t)buf[bufLen + wrCnt + 1] << 8) | buf[bufLen + wrCnt]);
        }

        /* Confirm buffer write commence */
        HW_WR_REG16((hpfObject->baseAddr + addr), NOR_CMD_WRITE_COMMENCE);
        retVal = Nor_hpfWaitDevReady(handle, NOR_WRR_WRITE_TIMEOUT);
        if (retVal != NOR_PASS)
        {
            break;
        }

        addr += wrLength;
        bufLen += wrLength;
        len -= wrLength;

    } while(len != 0);

    return retVal;
}

/**
 * \brief   NOR HyperFlash erase function
 *
 *  This function is used to erase 4-KB parameter sector or a sector
 *  or the complete chip.
 *
 * \param   handle      [IN]    Nor Handle
 * \param   sector      [IN]    sector number to be erased
 *                              sector number - erase that sector
 *                                         -1 - chip erase.
 * \param   erase       [IN]    Need to update
 *
 * \return  NOR_PASS in case of success or appropriate error code.
 *
 */
NOR_STATUS Nor_hpfErase(NOR_HANDLE handle, int32_t sector, bool erase)
{
    NOR_Info *norInfoHandle;
    HPF_Object *hpfObject;
    NOR_STATUS retVal;
    uint32_t sectorAddr;

    norInfoHandle = (NOR_Info *)handle;
    hpfObject = (HPF_Object *)norInfoHandle->hwHandle;

    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_WRITE_UNLOCK1);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR2), NOR_CMD_WRITE_UNLOCK2);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_ERASE_CMD1);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_ERASE_CMD2);
    HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR2), NOR_CMD_ERASE_CMD3);

    if (sector == NOR_BE_SECTOR_NUM)
    {
        /* Chip erase */
        HW_WR_REG16((hpfObject->baseAddr + NOR_HPF_CMD_ADDR1), NOR_CMD_BULK_ERASE);
        retVal = Nor_hpfWaitDevReady(handle, NOR_BULK_ERASE_TIMEOUT);
    }
    else
    {
        sectorAddr = sector * NOR_SECTOR_SIZE;
        /* Sector erase */
        HW_WR_REG16((hpfObject->baseAddr + sectorAddr), NOR_CMD_SECTOR_ERASE);
        retVal = Nor_hpfWaitDevReady(handle, NOR_SECTOR_ERASE_TIMEOUT);
    }

    return retVal;
}
