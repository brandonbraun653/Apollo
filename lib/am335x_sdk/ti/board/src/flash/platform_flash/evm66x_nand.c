/*
 * Copyright (c) 2010-2018, Texas Instruments Incorporated
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
 * \file  evm66x_nand.c
 *
 * \brief This contains TCI66xK2x specific nand functions.
 *
 *
 ******************************************************************************/
#include "platform_internal.h"

#if (PLATFORM_NAND_IN)

/************************
 * Include Files
 ************************/

/************************
 * Globals
 ************************/

/************************
 * Defines and Macros
 ************************/
#ifndef __cplusplus
#pragma DATA_SECTION(nandPageBuf,"platform_lib");
#else
#pragma DATA_SECTION("platform_lib");
#endif
static uint8_t nandPageBuf[BYTES_PER_PAGE + SPARE_BYTES_PER_PAGE];

#if (PLATFORM_NAND_ECC_IN)

// Both RBL and Linux offsets are set for 8-bit BCH ECC
/*
 * RBL ECC placement structure for each 512 byte block:
 *
 * 0    1 	2	 3    4    5    6    7    8    9   10   11   12    13    14    15
 * Unused ECC0 ECC1 ECC2 ECC3 ECC4 ECC5 ECC6 ECC7 ECC8 ECC9 ECC10 ECC11 ECC12 Unused
 */
static const uint8_t rbl_eccLoc[4*NAND_MAX_NUM_ECC_BYTES] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
};

/*
 * U-Boot ECC placement structure:
 *
 *  The first 2 bytes are used for Bad block marker - 0xFFFF => Good block
 *  The next 'N' bytes is used for BCH bytes
 *
 *  N = B * <Number of 512-byte sectors in a page>
 *
 *  B = 8 bytes per 512 byte sector in BCH4
 *  B = 14 bytes per 512 byte sector in BCH8
 *  B = 26 bytes per 512 byte sector in BCH16
 *
 */
static const uint8_t linux_eccLoc[4*NAND_MAX_NUM_ECC_BYTES] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
};

#endif // #if (PLATFORM_NAND_ECC_IN)

NandInfo_t gNandInfo;
NandCtrlInfo_t gNandCtrlInfo;
NandEccInfo_t gNandEccInfo;
NandTimingInfo_t gNandTimingInfo;

/******************************************************************************
 *
 * Function:    NandCmdSet
 *
 * Description: This function is used to indicate command cycle occurring
 *              and to send command to NAND device
 *
 * Parameters:  uint32_t cmd - Command to NAND
 *
 * Return Value: None
 *
 *****************************************************************************/
static void NandCmdSet(uint32_t cmd)
{
    uint16_t *cle_addr  = (uint16_t *) NAND_CMD_ADDR;

    *cle_addr = (uint16_t) cmd;
}

/******************************************************************************
 *
 * Function:    NandAleSet
 *
 * Description: This function is used to indicate Address cycle occurring
 *              and to send address value to NAND device
 *
 * Parameters:  uint32_t addr - Address to NAND
 *
 * Return Value: None
 *
 *****************************************************************************/
static void NandAleSet(uint32_t addr)
{
      uint16_t *ale_addr  = (uint16_t *) NAND_ALE_ADDR;

      *ale_addr = (uint16_t) addr;

      return;
}

/******************************************************************************
 *
 * Function:    NandProgAddr
 *
 * Description: This function is used to send the column, page and block
 *              address to the NAND device using NandAleSet
 *
 * Parameters:  NAND_ADDR addr - Address to NAND
 *
 * Return Value: None
 *
 *****************************************************************************/
static void NandProgAddr(NAND_ADDR addr)
{
    /*
     * Send address of the block + page to be read
     * Address cycles = 5
     */
    NandAleSet((addr.uiColumnAddr >>  0u) & 0xFF);   // CA0 -CA7  1st Cycle; Column addr
    NandAleSet((addr.uiColumnAddr >>  8u) & 0x07);   // CA8 -CA10 2nd Cycle; Column addr
    NandAleSet(((addr.uiBlockAddr <<  6u) & 0xC0) |  // BA6 -BA7  3rd Cycle; Block  addr
               ((addr.uiPageAddr  >>  0u) & 0x3F));  // PA0 -PA5  3rd Cycle; Page   addr
    NandAleSet((addr.uiBlockAddr  >>  2u) & 0xFF);   // BA8 -BA15 4th Cycle; Block  addr
    NandAleSet((addr.uiBlockAddr  >> 10u) & 0x01);   // BA16      5th Cycle; Block  addr
}

/******************************************************************************
  *
  * Function:    NandWaitRdy
  *
  * Description: This function waits for the NAND status to be ready
  *
  * Parameters:  uint32_t in_timeout - time out value in micro seconds
  *
  * Return Value: Failure if Ready Pin is not high for prescribed time
  *
  *****************************************************************************/
 static uint32_t NandWaitRdy(uint32_t in_timeout)
 {
     uint32_t count = 0;

     do
     {
        platform_delay(1);

        if (((nandWaitPinStatusGet(&gNandInfo)) & 1) == 1)
        {
            break;
        }

        count++;

     } while (count < in_timeout);

     if (count >= in_timeout)
     {
        return FAIL;
	 }
     else
     {
        return SUCCESS;
	 }
 }

#if (PLATFORM_NAND_READ_IN | PLATFORM_NAND_WRITE_IN)

 /******************************************************************************
  *
  * Function:    NandReadDataByte
  *
  * Description: This function is used to read Nand data byte
  *
  * Parameters:  uint8_t* puchValue - Pointer to data buffer
  *
  * Return Value: None
  *
  *****************************************************************************/
static void NandReadDataByte(uint8_t* puchValue)
 {
    /*8-bit NAND*/
    uint8_t *data_addr  = (uint8_t *) NAND_DATA_ADDR;

    *puchValue = *data_addr;
 }

 /******************************************************************************
  *
  * Function:    NandReadDataBytes
  *
  * Description: This function is used to read data bytes from the NAND device
  *
  * Parameters:  uiNumBytes - Number of bytes to be read
  *              pBuffer - Data buffer
  *
  * Return Value: Error/Success codes
  *
  *****************************************************************************/
 static uint32_t NandReadDataBytes(uint32_t uiNumBytes, uint8_t *pBuffer)
 {
     uint32_t i;

     /* 8-bit NAND */
     for (i = 0; i < uiNumBytes; i++)
     {
         /* NANDRead done directly without checking for nand width */
         NandReadDataByte((uint8_t *)pBuffer);
         pBuffer++;
     }
     return SUCCESS;
 }

  /******************************************************************************
   *
   * Function:    NandReadDataWord
   *
   * Description: This function is used to read Nand data word
   *
   * Parameters:  uint16_t* pushValue - Pointer to data buffer
   *
   * Return Value: None
   *
   *****************************************************************************/
 static void NandReadDataWord(uint16_t* pushValue)
  {
     uint16_t *data_addr  = (uint16_t *) NAND_DATA_ADDR;

     *pushValue = *data_addr;
  }

  /******************************************************************************
   *
   * Function:    NandReadDataWords
   *
   * Description: This function is used to read data words from the NAND device
   *
   * Parameters:  uiNumBytes - Number of bytes to be read
   *              pBuffer    - Data buffer
   *
   * Return Value: Error/Success codes
   *
   *****************************************************************************/
static uint32_t NandReadDataWords(uint32_t uiNumBytes, uint16_t *pBuffer)
{
      uint32_t i;

      for (i = 0; i < uiNumBytes/2; i++)
      {
          NandReadDataWord(pBuffer);
          pBuffer++;
      }

      return SUCCESS;
}

static uint32_t NandReadData(PLATFORM_DEVICE_info *p_device, uint32_t uiNumBytes, uint8_t *pBuffer)
{
    uint16_t *ptrData;
    uint32_t retVal;

    if(p_device->width == 8)
    {
		/* 8-bit NAND */
        retVal = NandReadDataBytes(uiNumBytes, pBuffer);
    }
    else
    {
		/* 16-bit NAND */
        ptrData = (uint16_t *)pBuffer;
        retVal = NandReadDataWords(uiNumBytes, ptrData);
    }

    return (retVal);
}

/******************************************************************************
  *
  * Function:    NandReadSpareArea
  *
  * Description: Function to read Nand spare area
  *
  * Parameters:  uiBlkAddr - Block Address
  *              uiPage - Page Number
  *              pBuffer - Data Buffer
  *
  * Return Value: Error/Success codes
  *
  *****************************************************************************/
uint32_t NandReadSpareArea(PLATFORM_DEVICE_info *p_device, uint32_t uiBlkAddr, uint32_t uiPage, uint8_t *pBuffer)
{
    uint32_t ret_val = SUCCESS;
    uint8_t status;
    NAND_ADDR address;


     /* Read the data to the destination buffer and detect error */
    address.uiColumnAddr = p_device->column;
    address.uiPageAddr = uiPage;
    address.uiBlockAddr = uiBlkAddr;

     /* Send 0x50h command to read the spare area */
    NandCmdSet(NAND_PAGE_READ); // First cycle send 0
    platform_delay(10);

    /* Send address */
    NandProgAddr(address);

    NandCmdSet(0x30); // Last  cycle send 30h command
    platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

    // Wait for Ready Busy Pin to go HIGH
    ret_val = NandWaitRdy(NAND_PROG_TIMEOUT);

    if (ret_val != SUCCESS) {
    	platform_errno = PLATFORM_ERRNO_DEV_BUSY;
 		IFPRINT(platform_write("NandReadSpareArea: Device timeout.\n"));
        return FAIL;
    }

    /* Read the data to the destination buffer and detect error */
    NandReadData(p_device, p_device->spare_size, pBuffer);
    printf("[1] pBuffer: 0x%08x, *pBuffer: %x\n",(uint32_t) pBuffer, *pBuffer);
    printf("[2] pBuffer: 0x%08x, *pBuffer: %x\n",(uint32_t) pBuffer, *pBuffer+4);
    printf("[3] pBuffer: 0x%08x, *pBuffer: %x\n",(uint32_t) pBuffer, *pBuffer+8);
    printf("[4] pBuffer: 0x%08x, *pBuffer: %x\n",(uint32_t) pBuffer, *pBuffer+12);

    NandCmdSet(NAND_STATUS);
    platform_delay(10);
    NandReadDataByte(&status);

    if ((status & 0x01) == 1) {
        /* if SR0 bit is set to 1, there is Error - operation failed */
     	platform_errno = PLATFORM_ERRNO_DEV_FAIL;
		IFPRINT(platform_write("NandReadSpareArea: Status (0x%x) has error bit set.\n", status));
        return FAIL;
    }

    return SUCCESS;
}
#endif


 /******************************************************************************
  *
  * Function:    readNandPage
  *
  * Description: This function reads a page from NAND flash and detects and
  *              corrects the bit errors if ECC is enabled
  *
  * Parameters:  NAND_ADDR address - Block Address/Page address of NAND flash
  *              uint8_t* puchBuffer - Pointer to buffer
  *
  * Return Value: status
  *
  * Assumptions: puchBuffer points to a 2KB buffer
  *
  ******************************************************************************/
#if (PLATFORM_NAND_READ_IN)
uint32_t readNandPage(PLATFORM_DEVICE_info *p_device, NAND_ADDR address, uint8_t* puchBuffer)
{
    int32_t i = 0;
    int32_t index;
    uint32_t byte_count;
    uint8_t *puchSpareAreaBuf;
    uint8_t *pBuffer_loc;
    uint32_t ret_val = SUCCESS;
    uint8_t  status;

#if (PLATFORM_NAND_ECC_IN)
    /* ECC locations for the micron nand device */
    const uint8_t   *eccLoc = (p_device->flags == NAND_FLAG_RBL) ? rbl_eccLoc : linux_eccLoc;
    uint8_t   eccCode[4*NAND_MAX_NUM_ECC_BYTES];
#endif

    if(puchBuffer == NULL)
        return NULL_POINTER_ERROR;

    pBuffer_loc = nandPageBuf;
    puchSpareAreaBuf = nandPageBuf + BYTES_PER_PAGE;
    ret_val = NandReadSpareArea(p_device, address.uiBlockAddr, address.uiPageAddr, puchSpareAreaBuf);

    if(ret_val != SUCCESS)
        return FAIL;

    platform_delay(10);

    NandCmdSet(NAND_PAGE_READ);
    platform_delay(10);

    /* Send address */
    NandProgAddr(address);

    NandCmdSet(0x30); // Last cycle send 30h command
    platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

    /* Wait for Ready Busy Pin to go HIGH */
    ret_val = NandWaitRdy(NAND_PROG_TIMEOUT);

    if(ret_val != SUCCESS) {
        platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;
        return FAIL;
    }

#if (PLATFORM_NAND_ECC_IN)
	nandECCReadSet(&gNandInfo);
	nandECCDisable(&gNandInfo);
#endif

    for(byte_count = 0, index = 0; byte_count < p_device->page_size; pBuffer_loc += ECC_BLOCK_SIZE, index++, byte_count += ECC_BLOCK_SIZE)
    {
#if (PLATFORM_NAND_ECC_IN)
        /* Start 4-bit ECC HW calculation for read */
        nandECCEnable(&gNandInfo);
#endif

        /* Read the data to the destination buffer and detect error */
        NandReadData(p_device, ECC_BLOCK_SIZE, pBuffer_loc);
        platform_delay(10);

#if (PLATFORM_NAND_ECC_IN)

        /* Read Parity - read parity stored in spare NAND flash */
        for(i = 0; i < NAND_MAX_NUM_ECC_BYTES; i++)
        {
            eccCode[i + (index * NAND_MAX_NUM_ECC_BYTES)] = puchSpareAreaBuf[eccLoc[i + (index * NAND_MAX_NUM_ECC_BYTES)]];
        }

		if(nandECCCheckAndCorrect(&gNandInfo, &eccCode[index * NAND_MAX_NUM_ECC_BYTES], pBuffer_loc) != NAND_STATUS_PASSED)
        {
            return FAIL;
        }

        nandECCDisable(&gNandInfo);
#endif
    }

    NandCmdSet(NAND_STATUS);
    platform_delay(10);

    NandReadDataByte(&status);

    if ((status & 0x01) == 1) {
        /* if SR0 bit is set to 1, there is Error - operation failed */
    	platform_errno = PLATFORM_ERRNO_DEV_FAIL;
        return FAIL;
    }

    memcpy(puchBuffer, nandPageBuf, gDeviceNand.page_size);

    return SUCCESS;
}
#endif

 /******************************************************************************
  *
  * Function:    NandWriteDataBytes
  *
  * Description: This function is used to write data bytes to the NAND device
  *
  * Parameters:  uiNumBytes - Number of bytes to be written
  *              pBuffer - Data buffer
  *
  * Return Value: Error/Success codes
  *
  *****************************************************************************/

#if (PLATFORM_NAND_WRITE_IN)
 static void NandWriteDataByte(uint8_t uchData)
 {
     volatile uint8_t* dest;

     /* Data is written to the data register on the rising edge of WE# when
           CE#, CLE, and ALE are LOW, and
		   the device is not busy. */
     dest = (volatile uint8_t *)(NAND_DATA_ADDR);
     *dest = uchData;
 }

uint32_t NandWriteDataBytes(uint32_t uiNumBytes, uint8_t *pBuffer)
 {
     uint32_t i;

	 for (i = 0; i < uiNumBytes; i++)
	 {
		 /* NAND Write done directly without checking for nand width */
		 NandWriteDataByte( (uint8_t) *pBuffer );
		 pBuffer++;
	 }

     return SUCCESS;
 }

  static void NandWriteDataWord(uint16_t ushData)
  {
      volatile uint16_t* dest;

      /* Data is written to the data register on the rising edge of WE# when
            CE#, CLE, and ALE are LOW, and
 		   the device is not busy. */
      dest = (volatile uint16_t *)(NAND_DATA_ADDR);
      *dest = ushData;
  }

 uint32_t NandWriteDataWords(uint32_t uiNumBytes, uint16_t *pBuffer)
  {
      uint32_t i;

	  for (i = 0; i < uiNumBytes/2; i++)
	  {
		  /* NAND Write done directly without checking for nand width */
		  NandWriteDataWord(*pBuffer);
		  pBuffer++;
	  }

      return SUCCESS;
 }

uint32_t NandWriteData(PLATFORM_DEVICE_info *p_device, uint32_t uiNumBytes, uint8_t *pBuffer)
{
	uint16_t* pshData;
	uint32_t  retVal;

	if (p_device->width == 8)
	{
		/* 8-bit NAND */
		retVal = NandWriteDataBytes(uiNumBytes, pBuffer);
	}
	else
	{
		/* 16-bit NAND */
		pshData = (uint16_t* )pBuffer;
		retVal = NandWriteDataWords(uiNumBytes, pshData);
	}

	return (retVal);
}

#endif

 /******************************************************************************
  *
  * Function:    writeNandPage
  *
  * Description: This function a page to NAND flash. It computes ECC and
  *              and writes it to spare area if ECC is enabled
  *
  * Parameters:  NAND_ADDR address - Block Address/Page address of NAND flash
  *              uint8_t* puchBuffer - Pointer to buffer
  *
  * Return Value: status
  *
  * Assumptions: puchBuffer points to a 2KB buffer
  *
  ******************************************************************************/
#if (PLATFORM_NAND_WRITE_IN)
 uint32_t  writeNandPage(PLATFORM_DEVICE_info *p_device, NAND_ADDR address, uint8_t* puchBuffer)
 {
     int32_t iErrors = SUCCESS;
     int32_t i = 0;
     uint32_t byte_count, index;
     uint8_t puchSpareAreaBuf[SPARE_BYTES_PER_PAGE];
     uint8_t *pBuffer_loc;
     uint32_t ret_val = SUCCESS;
     uint8_t  status;

#if (PLATFORM_NAND_ECC_IN)
     /* ECC locations for the Numonyx nand device */
     const uint8_t  *eccLoc = (p_device->flags == NAND_FLAG_RBL) ? rbl_eccLoc : linux_eccLoc;
     uint8_t   eccCalc[4*NAND_MAX_NUM_ECC_BYTES];
#endif

     /* Init the buffer by reading the existing values in the spare area */
    iErrors = NandReadSpareArea(p_device, address.uiBlockAddr, address.uiPageAddr, puchSpareAreaBuf);
    if(iErrors != SUCCESS)
    {
        return iErrors;
    }

#if (PLATFORM_NAND_ECC_IN)
	nandECCWriteSet(&gNandInfo);
	nandECCDisable(&gNandInfo);
#endif

    pBuffer_loc = puchBuffer;
    for(byte_count = 0, index = 0; byte_count < p_device->page_size; pBuffer_loc += ECC_BLOCK_SIZE, index++, byte_count += ECC_BLOCK_SIZE)
    {
        NandCmdSet(NAND_PROG_PAGE);
        platform_delay(10);

        address.uiColumnAddr = byte_count/2;
        NandProgAddr(address);
        platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

#if (PLATFORM_NAND_ECC_IN)
        /* Start ECC HW calculation for write */
        nandECCEnable(&gNandInfo);
        platform_delay (10);
#endif

        /* Write the data */
        NandWriteData(p_device, ECC_BLOCK_SIZE, pBuffer_loc);

        platform_delay (10);

#if (PLATFORM_NAND_ECC_IN)

        /* Calculate the ECC bytes for write */
        nandECCDisable(&gNandInfo);
        nandECCCalculate(&gNandInfo, &eccCalc[index * NAND_MAX_NUM_ECC_BYTES]);

        /* Update the calculated ECC bytes to spare area data */
        for (i = 0; i < NAND_MAX_NUM_ECC_BYTES; i++)
        {
            puchSpareAreaBuf[eccLoc[i + (index * NAND_MAX_NUM_ECC_BYTES)]] = eccCalc[i + (index * NAND_MAX_NUM_ECC_BYTES)];
        }

#endif

        /* Wait for Ready Busy Pin to go HIGH  */
        NandCmdSet(NAND_CMD_10H);

        platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

        ret_val = NandWaitRdy(NAND_PROG_TIMEOUT*50);

        if (ret_val != SUCCESS) {
            platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;
            return FAIL;
        }

        NandCmdSet(NAND_STATUS);
        platform_delay(10);

        NandReadDataByte(&status);

        if ((status & 0x01) == 1) {
            /* if SR0 bit is set to 1, there is Error - operation failed */
            platform_errno = PLATFORM_ERRNO_DEV_FAIL;
            return FAIL;
        }
    }

    /* Write the spare data */
    ret_val = NandWriteSpareArea(p_device, address.uiBlockAddr, address.uiPageAddr, puchSpareAreaBuf);

    if (ret_val != SUCCESS)
        return FAIL;

    return SUCCESS;
 }
#endif

 /******************************************************************************
  *
 * Function:    NandWriteSpareArea
 *
 * Description: Function to write a spare area of the NAND
 *
 * Parameters:  uiBlkAddr - Block Address
 *              uiPage - Page Number
 *              pBuffer - Data Buffer
 *
 * Return Value: Error/Success codes
 *
 *****************************************************************************/
#if (PLATFORM_NAND_WRITE_IN)
uint32_t NandWriteSpareArea (PLATFORM_DEVICE_info *p_device, uint32_t uiBlkAddr, uint32_t uiPage, uint8_t *pBuffer)
{
    uint32_t ret_val = SUCCESS;
    uint8_t  status;
    uint8_t *pBuffer_loc;
    NAND_ADDR address;

    /* Read the data to the destination buffer and detect error */
    address.uiColumnAddr = p_device->column;
    address.uiPageAddr   = uiPage;
    address.uiBlockAddr  = uiBlkAddr;

    /* Spare Area*/
    /*NandCmdSet(NAND_PAGE_READ);
    platform_delay(20);*/
    NandCmdSet(NAND_PROG_PAGE);
    platform_delay(10);

    /* Send address */
    NandProgAddr(address);
    platform_delay (NAND_WAIT_PIN_POLL_ST_DLY);

    /* Write the data */
    pBuffer_loc = pBuffer;
    NandWriteData(p_device, p_device->spare_size, (uint8_t *)pBuffer_loc);

    /* Wait for Ready Busy Pin to go HIGH  */
    NandCmdSet(NAND_CMD_10H);

    platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

    ret_val = NandWaitRdy(NAND_PROG_TIMEOUT*50);

    if (ret_val != SUCCESS) {
    	platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;
    	return FAIL;
    }

    NandCmdSet(NAND_STATUS);
    platform_delay(10);

    NandReadDataByte(&status);

    if ((status & 0x01) == 1) {
    	/* if SR0 bit is set to 1, there is Error - operation failed */
     	platform_errno = PLATFORM_ERRNO_DEV_FAIL;
    	return FAIL;
    }

    return SUCCESS;
}
#endif

 /******************************************************************************
  *
  * Function:    nandFlashBlockErase
  *
  * Description: This function erases the specified block of NAND flash
  *
  * Parameters:  NAND_ADDR address - Block Address of NAND flash
  *
  * Return Value: status
  *
  *****************************************************************************/
#if (PLATFORM_NAND_WRITE_IN)
 uint32_t nandFlashBlockErase(PLATFORM_DEVICE_info *p_device, uint32_t uiBlockNumber)
 {
     uint32_t ret_val = SUCCESS;
     uint8_t  status;

     NandCmdSet(NAND_BLOCK_ERASE); // Block erase command
     platform_delay(25);

     /*
      * Send address of the block + page to be read
      * Address cycles = 3
      */

     /* Properly adjust the shifts to match to the data sheet */

     NandAleSet((uiBlockNumber <<  6u) & 0xC0);  // B0 -B1  1st Cycle; Block addr
     platform_delay(25);
     NandAleSet((uiBlockNumber >>  2u) & 0xFF);  // B2 -B9  2nd Cycle; Block addr
     platform_delay(25);
     NandAleSet((uiBlockNumber >> 10u) & 0x01);  // B10-B11 3rd Cycle; Block addr
     platform_delay(1000);

     NandCmdSet(NAND_ERASE_CONFIRM); // Erase confirm
     platform_delay(NAND_WAIT_PIN_POLL_ST_DLY);

     /* Wait for erase operation to finish: 2msec  */
     ret_val = NandWaitRdy(NAND_BLOCK_ERASE_TIMEOUT);

     if (ret_val != SUCCESS) {
        platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;
         return FAIL;
     }

     NandCmdSet(NAND_STATUS);
     platform_delay(10);

     NandReadDataByte(&status);

     if ((status & 0x01) == 1) {
    	 /* if SR0 bit is set to 1, there is Error - operation failed */
    	 platform_errno = PLATFORM_ERRNO_DEV_FAIL;
    	 return FAIL;
     }

     return SUCCESS;

 }
#endif

/******************************************************************************
*                                                                             *
* \brief  Function to initalize the NAND timing info.                         *
*                                                                             *
* \param  nandTimimgInfo : Pointer to structure containing                    *
*                          NAND timing info.                                  *
*                                                                             *
* \return none.                                                               *
*                                                                             *
******************************************************************************/
static void NandTimingInfoInit(NandTimingInfo_t *nandTimingInfo)
{
    nandTimingInfo->CSWrOffTime               = NAND_CSWROFFTIME;
    nandTimingInfo->CSRdOffTime               = NAND_CSRDOFFTIME;
    nandTimingInfo->CSExtDelayFlag            = GPMC_CS_EXTRA_NODELAY;
    nandTimingInfo->CSOnTime                  = NAND_CSONTIME;

    nandTimingInfo->ADVAADMuxWrOffTime        = NAND_ADVAADMUXWROFFTIME;
    nandTimingInfo->ADVAADMuxRdOffTime        = NAND_ADVAADMUXRDOFFTIME;
    nandTimingInfo->ADVWrOffTime              = NAND_ADVWROFFTIME;
    nandTimingInfo->ADVRdOffTime              = NAND_ADVRDOFFTIME;
    nandTimingInfo->ADVExtDelayFlag           = GPMC_ADV_EXTRA_NODELAY;
    nandTimingInfo->ADVAADMuxOnTime           = NAND_ADVAADMUXONTIME;
    nandTimingInfo->ADVOnTime                 = NAND_ADVONTIME;

    nandTimingInfo->WEOffTime                 = NAND_WEOFFTIME;
    nandTimingInfo->WEExtDelayFlag            = GPMC_WE_EXTRA_NODELAY;
    nandTimingInfo->WEOnTime                  = NAND_WEONTIME;
    nandTimingInfo->OEAADMuxOffTime           = NAND_OEAADMUXOFFTIME;
    nandTimingInfo->OEOffTime                 = NAND_OEOFFTIME;
    nandTimingInfo->OEExtDelayFlag            = GPMC_OE_EXTRA_NODELAY;
    nandTimingInfo->OEAADMuxOnTime            = NAND_OEAADMUXONTIME;
    nandTimingInfo->OEOnTime                  = NAND_OEONTIME;

    nandTimingInfo->rdCycleTime               = NAND_RDCYCLETIME;
    nandTimingInfo->wrCycleTime               = NAND_WRCYCLETIME;
    nandTimingInfo->rdAccessTime              = NAND_RDACCESSTIME;
    nandTimingInfo->pageBurstAccessTime       = NAND_PAGEBURSTACCESSTIME;

    nandTimingInfo->cycle2CycleDelay          = NAND_CYCLE2CYCLEDELAY;
    nandTimingInfo->cycle2CycleDelaySameCSCfg = NAND_CYCLE2CYCLESAMECSEN;
    nandTimingInfo->cycle2CycleDelayDiffCSCfg = NAND_CYCLE2CYCLEDIFFCSEN;
    nandTimingInfo->busTAtime                 = NAND_BUSTURNAROUND;

	nandTimingInfo->wrAccessTime              = NAND_WRACCESSTIME;
	nandTimingInfo->wrDataOnADMux             = NAND_WRDATAONADMUXBUS;
}

/******************************************************************************
*                                                                             *
* \brief  Function to initalize the NAND configuration info.                  *
*                                                                             *
* \param  nandTimimgInfo : Pointer to structure containing                    *
*                          NAND timing info.                                  *
*                                                                             *
* \return none.                                                               *
*                                                                             *
******************************************************************************/
static void NandInfoInit(NandInfo_t *nandInfo)
{
    NandCtrlInfo_t *hNandCtrlInfo = nandInfo->hNandCtrlInfo;
    NandEccInfo_t  *hNandEccInfo  = nandInfo->hNandEccInfo;

    /* Init the NAND Device Info */
    nandInfo->eccType                       = NAND_ECC_ALGO_BCH_8BIT;
    nandInfo->chipSelectCnt                 = 1;
    nandInfo->dieCnt                        = 1;
    nandInfo->chipSelects[0]                = NAND_CS;
    nandInfo->busWidth                      = NAND_BUSWIDTH_16BIT;
    nandInfo->pageSize                      = NAND_PAGESIZE_2048BYTES;
    nandInfo->blkSize                       = NAND_BLOCKSIZE_128KB;
	nandInfo->pagesPerBlk                   = PAGES_PER_BLOCK;

    /* Init the NAND Controller Info struct */
    hNandCtrlInfo->hNandTimingInfo          = &gNandTimingInfo;
    hNandCtrlInfo->hGpmc                    = (gpmcHandle)CSL_GPMC_0_CFG_REGS;
    hNandCtrlInfo->waitPin                  = GPMC_WAIT_PIN0;
    hNandCtrlInfo->waitPinPol               = GPMC_WAIT_PIN_POLARITY_LOW;
    hNandCtrlInfo->wpPinPol                 = GPMC_WP_PIN_LEVEL_HIGH;
    hNandCtrlInfo->chipSelectBaseAddr[0]    = NAND_CS0_BASEADDR;
    hNandCtrlInfo->chipSelectRegionSize[0]  = NAND_CS0_REGIONSIZE;
    hNandCtrlInfo->currChipSelect           = NAND_CS;

	hNandEccInfo->hElm                      = (elmHandle)CSL_ELM_0_CFG_REGS;
}

 /******************************************************************************
  *
  * Function:    NandConfig
  *
  * Description: This function is used to congigure the NAND Device
  *
  * Parameters:  None
  *
  * Return Value: Err Status
  *
  *****************************************************************************/
static uint32_t NandConfig ()
{
	NandStatus_t status;

	/* Initialize NAND info */
	NandInfoInit(&gNandInfo);

	/* Initialize NAND timing information */
	NandTimingInfoInit((NandTimingInfo_t *)gNandCtrlInfo.hNandTimingInfo);

	/* Initialize the controller */
	status = nandCtrlInit(&gNandInfo);
	if (status != NAND_STATUS_PASSED)
	{
		platform_errno =  PLATFORM_ERRNO_DEV_FAIL;
		IFPRINT(platform_write("NandConfig ... Nand Controller Init Failed \n"));
		return FAIL;
	}

    return SUCCESS;
}

 /******************************************************************************
  *
  * Function:    NandOpenDevice
  *
  * Description: This function is used to open the NAND device and configure it
  *
  * Parameters:  None
  *
  * Return Value: Error/Success codes
  *
  *****************************************************************************/
 static uint32_t NandOpenDevice(void)
 {
     uint8_t  status;

     /* Initialize NAND interface */
     if (NandConfig() != SUCCESS) {
    	IFPRINT(platform_write("NandOpenDevice ... could not initialize the Nand Interface. \n"));
     	return FAIL;
     }

#if (PLATFORM_NAND_ECC_IN)
     /* Initialize ECC module */
     if (nandECCInit(&gNandInfo) != NAND_STATUS_PASSED) {
    	IFPRINT(platform_write("nandECCInit ... could not initialize the Nand ECC Interface. \n"));
     	return FAIL;
     }
#endif

     /* Send reset command to NAND */
     NandCmdSet(NAND_RST);
     platform_delay (NAND_WAIT_PIN_POLL_ST_DLY);

     if (NandWaitRdy(NAND_RESET_TIMEOUT) != SUCCESS) {
     	platform_errno = PLATFORM_ERRNO_DEV_TIMEOUT;
    	IFPRINT(platform_write("NandOpenDevice ... Nand wait ready failed. \n"));
        return FAIL;
     }

     NandCmdSet(NAND_STATUS);
     platform_delay(10);

     NandReadDataByte(&status);

     if ((status & 0x01) == 1) {
        /* if SR0 bit is set to 1, there is Error - operation failed */
     	platform_errno =  PLATFORM_ERRNO_DEV_FAIL;
    	IFPRINT(platform_write("NandOpenDevice ... Nand status error bit was set. \n"));
         return FAIL;
     }

     return SUCCESS;
 }

 /******************************************************************************
  *
  * Function:    NandGetDetails
  *
  * Description: Get details of the NAND flash used from the id and the
  *              table of NAND
  *
  * Parameters:  pNandInfo - Pointer to Nand Info structure
  *
  * Return Value: Error/Success codes
  *
  *****************************************************************************/
 uint32_t NandGetDetails(PLATFORM_DEVICE_info *pNandInfo)
 {
	 uint32_t	i;
	 uint32_t 	uiStatus;
     NAND_ADDR  address;

     /* Clear the Information */
     pNandInfo->device_id = pNandInfo->manufacturer_id = 0x0;

     /* Read manufacturer ID and device ID */
     NandCmdSet(NAND_RDID);
     platform_delay(10);
     NandAleSet(NAND_ADD_00H);
     platform_delay(10);

     NandReadDataWord((uint16_t *)&pNandInfo->manufacturer_id);
     NandReadDataWord((uint16_t *)&pNandInfo->device_id);

     /* Get the bad block table */
     address.uiPageAddr 	= 0;
     address.uiColumnAddr 	= 0;

     for (i=0; i < BLOCKS_PER_DEVICE; i++) {
         address.uiBlockAddr     = i;

         /* Clear the Spare Area */
         memset(nandPageBuf, 0, SPARE_BYTES_PER_PAGE);

         // Read the spare area in to buffer
         uiStatus = NandReadSpareArea(pNandInfo, address.uiBlockAddr,
                                         address.uiPageAddr, nandPageBuf);
         if(uiStatus != SUCCESS) {
            return PLATFORM_ERRNO_NANDBBT;
         }
         else { // Success in reading the NAND spare area
             if (nandPageBuf[pNandInfo->bboffset] == 0xFF) {
            	 pNandInfo->bblist[i]  = 0xFF;
             } else {
            	 pNandInfo->bblist[i]  = 0x00;
             }
         }
     }
     return SUCCESS;
 }

 /******************************************************************************
  *
  * Function:    nandInit
  *
  * Description: This function initialize the EMIF16 NAND flash controller.
  *
  * Parameters:  None
  *
  * Return Value: status
  *
  ******************************************************************************/
uint32_t nandInit(void)
{
	uint32_t retVal;

	gNandInfo.hNandCtrlInfo = &gNandCtrlInfo;
	gNandInfo.hNandEccInfo  = &gNandEccInfo;

	/* Open the NAND Device */
	retVal = NandOpenDevice();

	return (retVal);
}

#endif /*(PLATFORM_NAND_IN)*/


