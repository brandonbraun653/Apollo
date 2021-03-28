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
 */

#ifndef BOARD_FLASH_H_
#define BOARD_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <ti/csl/tistdtypes.h>

#if defined(BOARD_NOR_FLASH_IN)
#include <ti/board/src/flash/nor/nor.h>
#elif defined (BOARD_NAND_FLASH_IN)
#include <ti/board/src/flash/nand/nand.h>
#else
#endif

/**
 *
 *  \ingroup BOARD_LIB_MODULE 
 *
 *  \defgroup BOARD_LIB_FLASH Board Flash Library
 *
 *  Provides access to different flash devices.
 *
 *  @{
 *
 */
/* @} */

/**
 * \ingroup BOARD_LIB_FLASH 
 * @defgroup  BOARD_LIB_FLASH_TYPES Data Types 
 */
/*@{*/

/**
 *  @brief 	This type defines the opaque handle returned to a flash device that is opened.
 *  		The handle must be used in all subsequent operations.
 *
 */
typedef uintptr_t Board_flashHandle;

/**
 * Error codes used by Board flash functions. Negative values are errors,
 * while positive values indicate success.
 */
typedef int32_t Board_flash_STATUS;       /** Board Flash API return type */

#define BOARD_FLASH_EINVALID      -3      /**< Error code for invalid parameters */
#define BOARD_FLASH_EUNSUPPORTED  -2      /**< Error code for unsupported feature */
#define BOARD_FLASH_EFAIL         -1      /**< General failure code */
#define BOARD_FLASH_EOK           0       /**< General success code */

/**
 * @brief 	Device Identifiers. These are used in the Open call to allow access to a specific
 * 			memory device.
 *
 */
#define	BOARD_FLASH_ID_MT29F1G08ABCHC      0x2CA1 /**< 128MB NAND Flash */
#define BOARD_FLASH_ID_NAND512R3A2D        0x2036 /**< 64MB NAND Flash */
#define BOARD_FLASH_ID_MT29F4G08ABADA      0x2CDC /**< 512MB NAND Flash */
#define BOARD_FLASH_ID_MT29F16G08ADBCAH4C  0x2CA5 /**< 16Gb,1.8v,x8 */
#define BOARD_FLASH_ID_MT29F2G16ABAFA      0x2CCA /**< 2Gb, x16, 3.3V */
#define BOARD_FLASH_ID_NORN25Q128          0xBB18 /**< 16MB NOR Flash */
#define BOARD_FLASH_ID_NORN25Q128A13ESF40F 0xBA18 /**< 16MB, 3.3v NOR Flash */
#define BOARD_FLASH_ID_W25X32VSFIG		   0x4016 /**< w25x32 SPI Flash Device ID */
#define BOARD_FLASH_ID_NORN25Q032A	       0xBB16 /**< 4MB NOR Flash */
#define BOARD_FLASH_ID_EEPROM50            0x50   /**< EEPROM @ slave address 0x50  */
#define BOARD_FLASH_ID_EEPROM51            0x51   /**< EEPROM @ slave address 0x51  */
#define BOARD_FLASH_ID_EMMC                0xFF00 /**< eMMC device Id  */
#define BOARD_FLASH_ID_SD                  0xFF01 /**< Micro SD device Id  */
#define BOARD_FLASH_ID_QSPIFLASH_S25FL512S 0x0220 /**< QSPI flash device Id  - S25FL512S*/
#define BOARD_FLASH_ID_QSPIFLASH_S25FL256S 0x0219 /**< QSPI flash device Id - S25FL256S */
#define BOARD_FLASH_ID_S25FL512S           (0x0220U)  /**< Spansion 64MB NOR flash */
#define BOARD_FLASH_ID_S25FL256S           (0x0219U)  /**< Spansion 32MB NOR flash */
#define BOARD_FLASH_ID_MT29W160EB          (0x2249U) /**< Micron 2MB NOR flash */
#define BOARD_FLASH_ID_MT29F4G08ABAEAWP    (0xDC90U) /**< Micron 512MB NAND flash */
#if defined(j721e_sim)
#define BOARD_FLASH_ID_MT35XU512ABA1G12    (0x2018U) /**< J7 VLAB  */
#else
#define BOARD_FLASH_ID_MT35XU512ABA1G12    (0x5B1AU) /**< Micro 512Mb NOR flash device Id  */
#define BOARD_FLASH_ID_MT25QU512ABB        (0xBB20) /**< 64MB NOR Flash */
#endif
#define BOARD_FLASH_ID_S71KS512S           (0x007EU)  /**< 512 Mb cypress Hyperflash device Id  */


/**
 * @brief 	Board specific Flash Device Identifiers.
 *
 */
#if defined(evmK2H) || defined(evmK2K) || defined(evmK2E) || defined(evmK2L) || defined(evmK2G) || defined(evmC6678) || defined(evmC6657) || defined(iceK2G)
#if defined(evmK2G) || defined(iceK2G)
#define BOARD_FLASH_DEV_ID         BOARD_FLASH_ID_NORN25Q128A13ESF40F
#else
#define BOARD_FLASH_DEV_ID         BOARD_FLASH_ID_NORN25Q128
#endif
#endif

#if defined(evmOMAPL137)
#define BOARD_FLASH_DEV_ID         BOARD_FLASH_ID_W25X32VSFIG
#endif


/**
 * @brief Indicates the type of NOR flash peripheral
 *
 */
typedef enum {
    BOARD_FLASH_NOR_SPI = 0,
    /**<NOR SPI peripheral interface */
    BOARD_FLASH_NOR_QSPI,
    /**<NOR QSPI peripheral interface */
    BOARD_FLASH_NOR_GPMC,
    /**<NOR GPMC peripheral interface */
    BOARD_FLASH_NOR_OSPI,
    /**<NOR GPMC peripheral interface */
	BOARD_FLASH_NOR_HPF,
    /**<NOR HyperBus peripheral interface */
    BOARD_FLASH_NOR_INTF_MAX
    /**<End of NOR peripheral interface */
} Board_flashNorPeriType;

/**
 * @brief Indicates the type of NAND flash peripheral
 *
 */
typedef enum {
    BOARD_FLASH_NAND_GPMC = 0,
    /**<NAND GPMC peripheral interface */
    BOARD_FLASH_NAND_EMIF16,
    /**<NAND EMIF16 peripheral interface */
    BOARD_FLASH_NAND_INTF_MAX
    /**<End of NAND peripheral interface */
} Board_flashNandPeriType;

/**
 * @brief Indicates the type of device
 *
 */
typedef enum {
    BOARD_FLASH_NAND,
    /**<NAND Flash*/
    BOARD_FLASH_NOR,
    /**<NOR Flash*/
    BOARD_FLASH_EEPROM,
    /**<EEPROM */
    BOARD_FLASH_SD,
    /**<SD Card*/
    BOARD_FLASH_EMMC,
    /**<eMMC Card*/
    BOARD_FLASH_QSPI_FLASH,
    /**<QSPI flash */
    BOARD_FLASH_MAX
    /**<End of devices*/
} Board_flashType;

/**
 * @brief Options to set qspi flash read/write access mode
 */
typedef enum {
    BOARD_FLASH_QSPI_IO_MODE_SINGLE,
    /**< QSPI flash read/write access on single I/O line */
    BOARD_FLASH_QSPI_IO_MODE_DUAL,
    /**< QSPI flash read/write access on two I/O lines */
    BOARD_FLASH_QSPI_IO_MODE_QUAD
    /**< QSPI flash read/write access on four I/O lines */
} Board_flashQspiIoMode;

/**
 *  @brief This structure contains information about the flash device on the board
 *
 *			The bblist points to an array of bytes where each position represents a
 *			block on the device. If the block is good it is marked as 0xFF. If the block
 *			is bad, it is marked as 0x00. For devices that do not support a bad block list this
 *			value will be NULL. The number of blocks in the bblist is determined by the block_count field.
 */
typedef struct
{
    uint32_t flashHandle;
    /**<Handle to the flash interface as returned by flash init function */
    int32_t  manufacturer_id;
    /**<manufacturer ID*/
    int32_t  device_id;
    /**<Manufacturers device ID*/
    Board_flashType type;
    /**<Type of device */
    int32_t  width;
    /**<Width in bits*/
    int32_t  block_count;
    /**<Total blocks. First block starts at 0. */
    int32_t  page_count;
    /**<Page count per block*/
    int32_t  page_size;
    /**<Number of bytes in a page */
    int32_t  spare_size;
    /**<Spare area size in bytes*/
    int32_t	 bboffset;
    /**<Offset into spare area to check for a bad block */
	uint32_t column;
	/**<Column for a NAND device */
    uint8_t *bblist;
    /** <Bad Block list or NULL if device does not support one  */
    uint32_t  sector_size;
    /**<Number of bytes in a sector */
    bool blkErase_flag;
    /**<Flag to be set false for Sector Erase and true for Block Erase */
} Board_FlashInfo;

/**
 *  @brief Maximum Board flash instance number that can be opened.
 */
#define MAX_BOARD_FLASH_INSTANCE_NUM     8

/* @} */

/**
 * \ingroup BOARD_LIB_FLASH 
 * @defgroup  BOARD_LIB_FLASH_API  Application Interfaces 
 */
/*@{*/
/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 *  @brief       Opens a flash device for use
 *
 *  @param[in]   deviceId  Flash device ID to open
 *	@param[in]	 portNum   Peripheral port number attached to the flash device
 *  @param[in]   params    configuration parameters for the peripheral interface
 *
 *  @retval      NULL or Board_flashHandle.
 *
 *  @remark
 *               On success a handle is returned in which should be used in
 *				 all subsequent calls. As of now, the devices are not virtualized and only
 *				 one open may exist at a time for a particular device.
 *
 */
Board_flashHandle Board_flashOpen(uint32_t  deviceId,
                                  uint32_t  portNum,
                                  void     *params);

/**
 *  @brief       Closes the device
 *
 *  @param[in]   handle  Handle to the device as returned in the open call.
 *
 *  @retval      BOARD_FLASH_EOK on Success
 *
 */
Board_flash_STATUS Board_flashClose (Board_flashHandle handle);

/**
 *  @brief       Reads a page from the device
 *
 *  @param[in]   handle Flash device handle from the open
 *  @param[in]   offset Offset to start the read from
 *  @param[in]   buf	Pointer to a buffer to read the data into
 *  @param[in] 	 len    Amount of data to read
 *  @param[in] 	 params Pointer to read configuration parameters
 *                      for QSPI NOR, *params is used to set
 *                      the Board_flashQspiIoMode
 *
 *
 *  @retval      BOARD_FLASH_EOK on Success
 *
 *  @remark      The buffer size should be page_size + spare_size
 *               The application should not write into the spare area
 *
 */
Board_flash_STATUS Board_flashRead(Board_flashHandle  handle,
                                   uint32_t           offset,
                                   uint8_t           *buf,
                                   uint32_t           len,
                                   void              *params);

/**
 *  @brief      Write the data to the device
 *
 *  @param[in]  handle  Handle to the device as returned by open
 *  @param[in]  offset 		Offset to start writing the data at.
 *  @param[in] 	buf         Pointer to  data to write
 *  @param[in] 	len         Length of the data pointed to by buf
 *  @param[in] 	params      Pointer to write configuration parameters
 *                          for QSPI NOR, *params is used to set
 *                          the Board_flashQspiIoMode
 *
 *  @retval     BOARD_FLASH_EOK on Success
 *
 */
Board_flash_STATUS Board_flashWrite(Board_flashHandle  handle,
                                    uint32_t           offset,
                                    uint8_t           *buf,
                                    uint32_t           len,
                                    void              *params);

/**
 *  @brief      Convert the block and page number to offset
 *
 *  @param[in]  handle  Handle to the device as returned by open
 *  @param[in]  offset 		Offset to start writing the data at.
 *  @param[in] 	block       Block number
 *  @param[in] 	page        Page number
 *
 *  @retval     BOARD_FLASH_EOK on Success
 *
 *
 */
Board_flash_STATUS Board_flashBlkPageToOffset(Board_flashHandle  handle,
                                              uint32_t          *offset,
                                              uint32_t           block,
                                              uint32_t           page);


/**
 *  @brief      Convert the offset to block and page number
 *
 *  @param[in]  handle  Handle to the device as returned by open
 *
 *  @param[in]  offset 		Offset to start writing the data at.
 *
 *  @param[in] 	block       Pointer to the block number
 *
 *  @param[in] 	page        Pointer to the Page number
 *
 *  @retval     BOARD_FLASH_EOK on Success
 *
 *
 */
Board_flash_STATUS Board_flashOffsetToBlkPage(Board_flashHandle  handle,
                                              uint32_t           offset,
                                              uint32_t          *block,
                                              uint32_t          *page);

/**
 *  @brief      Convert the offset to sector and page number
 *
 *  @param[in]  handle              Handle to the device as returned by open
 *
 *  @param[in]  offset 		        Offset to start writing the data at.
 *
 *  @param[in] 	sector              Pointer to the sector number
 *
 *  @param[in] 	page                Pointer to the Page number
 *
 *  @param[in]  hybridSector_flag   Flag to enable Hybrid Sector Erase
 *
 *  @retval     BOARD_FLASH_EOK on Success
 *
 *
 */
Board_flash_STATUS Board_flashOffsetToSectorPage(Board_flashHandle  handle,
                                              uint32_t           offset,
                                              uint32_t          *sector,
                                              uint32_t          *page,
                                              bool              hybridSector_flag);

/**
 *  @brief       erase a block on the flash block
 *
 *  @param[in]   handle  Flash device handle from the open
 *
 *  @param[in]   block_number Block ID to erase
 *
 *  @retval      BOARD_FLASH_EOK on Success
 *
 */
Board_flash_STATUS Board_flashEraseBlk(Board_flashHandle handle,
                                       uint32_t          block_number);


#ifdef __cplusplus
}
#endif

#endif

/* @} */
