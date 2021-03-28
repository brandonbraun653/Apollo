/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
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

/**
 *
 * \file    board_flash.c
 *
 * \brief   This contains board flash common APIs.
 *
 ******************************************************************************/

#include "board_cfg.h"
#include "board_flash.h"

/* This structure holds information about the flash devices on the board */
Board_FlashInfo Board_flashInfo[MAX_BOARD_FLASH_INSTANCE_NUM] =
{
    {0, },
};

static uint32_t Board_getFlashIntf(uint32_t deviceId)
{
    uint32_t flashIntf = 0;

    switch(deviceId)
    {
        case BOARD_FLASH_ID_NORN25Q128:
        case BOARD_FLASH_ID_NORN25Q128A13ESF40F:
        case BOARD_FLASH_ID_W25X32VSFIG:
        {
            flashIntf = BOARD_FLASH_NOR_SPI;
            break;
        }

        case BOARD_FLASH_ID_MT25QU512ABB:
        case BOARD_FLASH_ID_S25FL512S:
        case BOARD_FLASH_ID_S25FL256S:
        {
            flashIntf = BOARD_FLASH_NOR_QSPI;
            break;
        }

        case BOARD_FLASH_ID_MT29W160EB:
        {
            flashIntf = BOARD_FLASH_NOR_GPMC;
            break;
        }

        case BOARD_FLASH_ID_MT29F4G08ABAEAWP:
        {
            flashIntf = BOARD_FLASH_NAND_GPMC;
            break;
        }

        case BOARD_FLASH_ID_MT35XU512ABA1G12:
        {
            flashIntf = BOARD_FLASH_NOR_OSPI;
            break;
        }

        case BOARD_FLASH_ID_S71KS512S:
        {
            flashIntf = BOARD_FLASH_NOR_HPF;
            break;
        }

        default:
        break;
    }

    return (flashIntf);
}
/******************************************************************************
 * BOARD_flashOpen
 ******************************************************************************/
Board_flashHandle Board_flashOpen(uint32_t deviceId, uint32_t portNum, void *params)
{
    uint32_t           count;
    Board_FlashInfo   *flashInfo;
    uint32_t           flashIntf;

    for (count = 0; count < MAX_BOARD_FLASH_INSTANCE_NUM; count++)
    {
        if (Board_flashInfo[count].flashHandle == 0)
        {
            flashInfo = &Board_flashInfo[count];
            break;
        }
    }

    if (count == MAX_BOARD_FLASH_INSTANCE_NUM)
    {
        return (0U);
    }

    flashIntf = Board_getFlashIntf(deviceId);

#if defined (BOARD_NOR_FLASH_IN)
    NOR_HANDLE         flashHandle;
    NOR_Info          *norInfo;

    if (                                                    \
        (deviceId == BOARD_FLASH_ID_S25FL512S)           || \
        (deviceId == BOARD_FLASH_ID_S25FL256S)           || \
        (deviceId == BOARD_FLASH_ID_MT29W160EB)          || \
        (deviceId == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (deviceId == BOARD_FLASH_ID_NORN25Q128)          || \
        (deviceId == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (deviceId == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (deviceId == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (deviceId == BOARD_FLASH_ID_S71KS512S)
       )
    {
        /* Open the NOR flash */
        flashHandle = NOR_open(flashIntf, portNum, params);
        if (!flashHandle)
        {
            return 0;
        }

        norInfo = (NOR_Info *)flashHandle;
        if (deviceId != norInfo->deviceId)
        {

            NOR_close(flashHandle);
            return 0;
        }

        flashInfo->flashHandle     = flashHandle;
        flashInfo->manufacturer_id = norInfo->manufacturerId;
        flashInfo->device_id       = norInfo->deviceId;
        flashInfo->type            = BOARD_FLASH_NOR;
        flashInfo->block_count     = norInfo->blockCnt;
        flashInfo->page_count      = norInfo->pageCnt;
        flashInfo->page_size       = norInfo->pageSize;
        flashInfo->sector_size     = norInfo->sectorSize;
        flashInfo->blkErase_flag   = true; /* Default set to Block Erase */

        return (Board_flashHandle)&(Board_flashInfo);
    }
#elif defined (BOARD_NAND_FLASH_IN)
    NAND_HANDLE        flashHandle;
    NAND_Info         *nandInfo;

    if (deviceId == BOARD_FLASH_ID_MT29F4G08ABAEAWP)
    {
        /* Open the Nand flash */
        flashHandle = NAND_open(flashIntf, portNum, params);
        if (!flashHandle)
        {
            return 0;
        }
        nandInfo = (NAND_Info *)flashHandle;

        if (deviceId != nandInfo->deviceId)
        {
            NAND_close(flashHandle);
            return 0;
        }

        flashInfo->flashHandle     = flashHandle;
        flashInfo->manufacturer_id = nandInfo->manufacturerId;
        flashInfo->device_id       = nandInfo->deviceId;
        flashInfo->type            = BOARD_FLASH_NAND;
        flashInfo->block_count     = nandInfo->blockCnt;
        flashInfo->page_count      = nandInfo->pageCnt;
        flashInfo->page_size       = nandInfo->pageSize;
        flashInfo->spare_size      = nandInfo->spareSize;
        flashInfo->bboffset        = nandInfo->bbOffset;
        flashInfo->bblist          = nandInfo->bbList;

        return (Board_flashHandle)(flashInfo);
    }
#endif

    return 0;
}

/******************************************************************************
 * BOARD_flashClose
 ******************************************************************************/
Board_flash_STATUS Board_flashClose(Board_flashHandle handle)
{
    Board_FlashInfo *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

#if defined(BOARD_NOR_FLASH_IN)
    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        NOR_close(flashInfo->flashHandle);
    }
#elif defined (BOARD_NAND_FLASH_IN)
    if (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)
    {
        NAND_close(flashInfo->flashHandle);
    }
#endif

    flashInfo->flashHandle = 0;

    return BOARD_FLASH_EOK;
}

/******************************************************************************
 * BOARD_flashRead
 ******************************************************************************/
Board_flash_STATUS Board_flashRead(Board_flashHandle  handle,
                                   uint32_t           offset,
                                   uint8_t           *buf,
                                   uint32_t           len,
                                   void              *params)
{
    Board_FlashInfo   *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

    if (buf == NULL || len == 0)
    {
        return BOARD_FLASH_EINVALID;
    }

#if defined(BOARD_NOR_FLASH_IN)
    uint32_t readMode = 0;

    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        if (params)
        {
            readMode = *((uint32_t *)params);
        }

        if (NOR_read(flashInfo->flashHandle, offset, len, buf, readMode) \
		    != NOR_PASS)
        {
            return (BOARD_FLASH_EFAIL);
        }
        return BOARD_FLASH_EOK;
    }
#elif defined (BOARD_NAND_FLASH_IN)
    if (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)
    {
        if (NAND_read(flashInfo->flashHandle, offset, len, buf) \
            != NAND_PASS)
        {
            return (BOARD_FLASH_EFAIL);
        }
        return BOARD_FLASH_EOK;
    }
#endif

    return BOARD_FLASH_EUNSUPPORTED;
}

 /**
 *  \brief		This function computes the sector and page based on an offset
 *              This function also sets the blkErase_flag to false to support
 *              Sector erase. This flag is used by the Board_flashEraseBlk()
 *              to determine the erase type
 *
 *	\param		handle		        [IN]   	Pointer to Board_FlashHandle.
 *              offset		        [IN]   	Flash Offset to be computed to Sector
 *              sector              [IN]    Computed Sector number
 *              page                [IN]    Computed page number
 *              hybridSector_flag   [IN]   	Flag to enable Hybrid Sector Erase
 *
 *  \return		Returns Board_flash_STATUS
 *
 */
Board_flash_STATUS Board_flashOffsetToSectorPage(Board_flashHandle  handle,
                                              uint32_t           offset,
                                              uint32_t          *sector,
                                              uint32_t          *page,
                                              bool              hybridSector_flag)
{
    uint32_t leftover, block_count, sector_count, page_size, page_count;
    Board_FlashInfo *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }
    if ((flashInfo->device_id == BOARD_FLASH_ID_S25FL256S) && (hybridSector_flag == false))
    {
        /* In case of S25FL256S device if hybridSector_flag is not set indicating
        uniform sector erase of 64KB, which is handled by Block erase */
        return Board_flashOffsetToBlkPage(handle, offset, sector, page);
    }

    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)    || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)
       )
    {
        block_count = flashInfo->block_count;
        page_size	= flashInfo->page_size;
        page_count 	= flashInfo->page_count;
	}
    else
    {
        return BOARD_FLASH_EUNSUPPORTED;
    }

    sector_count = (page_count * page_size * block_count) / flashInfo->sector_size;

    *sector   = offset / flashInfo->sector_size;
    leftover  = offset % flashInfo->sector_size;
    *page 	  = leftover / page_size;
    if (leftover % page_size)
    {
        /* All writes must be page aligned for now */
        return BOARD_FLASH_EUNSUPPORTED;
    }
    if (*sector > sector_count)
    {
        return BOARD_FLASH_EINVALID;
    }
    if (*page > page_count)
    {
        return BOARD_FLASH_EINVALID;
    }

    flashInfo->blkErase_flag = false; /* This flag to be set false for Sector erase */

    return BOARD_FLASH_EOK;
}

/**
 *  \brief		This function computes the block and page number based on the
 *              offset. This function also sets the blkErase_flag to true to
 *              support Block erase. This flag is used by the
 *              Board_flashEraseBlk() to determine the erase type.
 *
 *	\param		handle		        [IN]   	Pointer to Board_FlashHandle.
 *              offset		        [IN]   	Flash Offset to be computed to Sector
 *              page                [IN]    Computed Page number
 *              page                [IN]    Computed page number
 *
 *  \return		Returns Board_flash_STATUS
 *
 */
Board_flash_STATUS Board_flashOffsetToBlkPage(Board_flashHandle  handle,
                                              uint32_t           offset,
                                              uint32_t          *block,
                                              uint32_t          *page)
{
    uint32_t leftover, block_size, block_count, page_size, page_count;
    Board_FlashInfo *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)    || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        block_count = flashInfo->block_count;
        page_size	= flashInfo->page_size;
        page_count 	= flashInfo->page_count;
	}
    else
    {
        return BOARD_FLASH_EUNSUPPORTED;
    }

    block_size = (page_count * page_size);

    *block 	  = offset / block_size;
    leftover  = offset % block_size;
    *page 	  = leftover / page_size;
    if (leftover % page_size)
    {
        /* All writes must be page aligned for now */
        return BOARD_FLASH_EUNSUPPORTED;
    }
    if (*block > block_count)
    {
        return BOARD_FLASH_EINVALID;
    }
    if (*page > page_count)
    {
        return BOARD_FLASH_EINVALID;
    }

    flashInfo->blkErase_flag = true; /* This flag to be set true for Block erase */
    return BOARD_FLASH_EOK;
}

/******************************************************************************
 * Computes a block and page based on an offset
 ******************************************************************************/
Board_flash_STATUS Board_flashBlkPageToOffset(Board_flashHandle  handle,
                                              uint32_t          *offset,
                                              uint32_t           block,
                                              uint32_t           page)
{
    uint32_t	     block_count, page_size, page_count;
    Board_FlashInfo *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)    || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        block_count = flashInfo->block_count;
        page_size	= flashInfo->page_size;
        page_count 	= flashInfo->page_count;
    }
    else
    {
        return BOARD_FLASH_EUNSUPPORTED;
    }

    if (block >block_count || page > page_count)
    {
        return BOARD_FLASH_EINVALID;
    }

    *offset =   (block * (page_count * page_size)) + (page * page_size);

    return BOARD_FLASH_EOK;
}

/******************************************************************************
 * BOARD_flashWrite
 ******************************************************************************/
Board_flash_STATUS Board_flashWrite(Board_flashHandle  handle,
                                    uint32_t           offset,
                                    uint8_t           *buf,
                                    uint32_t           len,
                                    void              *params)
{
    Board_FlashInfo *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

    if (buf == NULL || len == 0)
    {
        return BOARD_FLASH_EINVALID;
    }

#if defined(BOARD_NOR_FLASH_IN)
    uint32_t writeMode = 0;

    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        if (params)
        {
            writeMode = *((uint32_t *)params);
        }

        if (NOR_write(flashInfo->flashHandle, offset, len, buf,
                 writeMode) != NOR_PASS)
        {
            return (BOARD_FLASH_EFAIL);
        }
        return BOARD_FLASH_EOK;
    }
#elif defined (BOARD_NAND_FLASH_IN)
    if (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)
    {
        if (NAND_write(flashInfo->flashHandle, offset, len, buf) != NAND_PASS)
        {
           return (BOARD_FLASH_EFAIL);
        }
        return BOARD_FLASH_EOK;
    }
#endif

    return BOARD_FLASH_EUNSUPPORTED;
}

/**
 *  \brief  platform_device_erase_block
 *
 *  Board_flashEraseBlk supports Block and Sector erase based on the blkErase_flag
 *  This API expects blkErase_flag to be set to the appropriate Boolean value to
 *  determine the type of erase.
 *
 *  blkErase_flag is set in one of the Board_flashOffsetToSectorPage() or
 *  Board_flashOffsetToBlkPage() APIs for sector or block erase respectively.
 *
 *  \param
 *  handle  - Handle to the flash device
 *  blk_num - Block number to be erased when blkErase_flag=true
 *            Sector number to be erased when blkErase_flag=false
 *
 *
 ********************************************************************************/
Board_flash_STATUS Board_flashEraseBlk(Board_flashHandle handle,
                                       uint32_t          blk_num)
{
    Board_FlashInfo    *flashInfo;

    if (!handle)
    {
        return BOARD_FLASH_EFAIL;
    }

    flashInfo = (Board_FlashInfo *)handle;
    if (!flashInfo->flashHandle)
    {
        return BOARD_FLASH_EFAIL;
    }

    if (flashInfo->blkErase_flag)
    {
        if (blk_num > flashInfo->block_count)
        {
            return BOARD_FLASH_EFAIL;
        }
    }

#if defined(BOARD_NOR_FLASH_IN)
    if (                                                                \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL512S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_S25FL256S)           || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT29W160EB)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_W25X32VSFIG)         || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128)          || \
        (flashInfo->device_id == BOARD_FLASH_ID_NORN25Q128A13ESF40F) || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT25QU512ABB)        || \
        (flashInfo->device_id == BOARD_FLASH_ID_MT35XU512ABA1G12)	 || \
        (flashInfo->device_id == BOARD_FLASH_ID_S71KS512S)
       )
    {
        if (NOR_erase (flashInfo->flashHandle, blk_num, flashInfo->blkErase_flag) != NOR_PASS)
        {
            return (BOARD_FLASH_EFAIL);
        }
        return BOARD_FLASH_EOK;
    }
#elif defined (BOARD_NAND_FLASH_IN)
    NAND_STATUS status;

    if (flashInfo->device_id == BOARD_FLASH_ID_MT29F4G08ABAEAWP)
    {
        if (flashInfo->bblist[blk_num] == NAND_BAD_BLOCK)
        {
            return (BOARD_FLASH_EFAIL);
        }

        status = NAND_erase(flashInfo->flashHandle, blk_num);
        if (status != NAND_PASS)
        {
            if (status == NAND_BLOCK_BAD)
            {
                flashInfo->bblist[blk_num] = NAND_BAD_BLOCK;
            }
            return (BOARD_FLASH_EFAIL);
        }
        else
        {
            return (BOARD_FLASH_EOK);
        }
    }
#endif

    return BOARD_FLASH_EUNSUPPORTED;
}

