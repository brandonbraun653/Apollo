/**
 *  \file    sbl_mcspi.c
 *
 *  \brief   MCSPI Initialization functions. And a function to copy data from
 *           Serial Flash to the given address.
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
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
#include <string.h>
#include "types.h"
#include "console_utils.h"
#include "error.h"
#include "sbl_copy.h"
#include "sbl_mcspi.h"
#include "device.h"
#include "soc.h"
#include "board.h"
#include "pinmux.h"
#include "prcm.h"
#include "mcspi.h"
#include "sbl_flash_offset_cfg.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief MCSPI Flash instance number to fetch the data from board entries */
#define MCSPI_FLASH_INST_NUM            (0U)

/** \brief  flash data read command */
#define SBL_MCSPI_FLASH_READ_CMD          0x03U

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function copies the bootloader/application image to the DDR
 *         by reading the header info.
 *
 * \param  pEntryPoint  Entry address read from TI image header.
 *
 * \retval S_PASS         Image copy successful.
 * \retval E_FAIL         Image copy failed.
 */
static uint32_t SBLMcspiImageCopy(uint32_t *pEntryPoint);

#ifdef BIN_INSTALL
static uint32_t SBLMcspiBinDataCopy(uint32_t offset);
#endif

/**
 * \brief     Fetch board information.
 *
 * \details   This function will check if SPI flash is present on the board
 *            and accordingly provide the MCSPI controllers instance number
 *            and instance ID..
 *
 * \param     pObj       Pointer to the MCSPI bootloader configuration
 *                       structure.
 *
 * \retval    #S_PASS - Flash support is present for the MCSPI instance.
 * \retVal    #E_FAIL - Flash support is not present for the MCSPI instance.
 */
static int32_t SBLMcspiBoardInfoGet(sblMcspiCfgObj_t *pObj);

/**
 * \brief     Fetch the MCSPI instance address.
 *
 * \param     pObj       Pointer to the MCSPI configuration structure.
 *
 * \retval    #S_PASS - MCSPI instance is present.
 * \retVal    #E_FAIL - MCSPI instance is not present.
 */
static int32_t SBLMcspiSocInfoGet(sblMcspiCfgObj_t *pObj);

/**
 * \brief    MCSPI IP configuration initialization function.
 *
 * \details  This function configures the MCSPI controller with the user passed
 *           values.
 *
 * \param    pSblMcspiCfgObj     Pointer to the MCSPI configuration object.
 *
 * \retVal   S_PASS           MCSPI initialization successful.
 * \retVal   E_FAIL           MCSPI initialization failed.
 */
int32_t SBLMcspiInit(sblMcspiCfgObj_t *pSblMcspiCfgObj);

/**
 * \brief    MCSPI data transfer function.
 *
 * \details  This function will start the data transfer.
 *
 * \param    pSblMcspiCfgObj   Pointer to the MCSPI configuration object.
 * \param    pTx            Pointer to the Address for Transmit data.
 * \param    pRx            Pointer to the Address to Recieve data.
 * \param    len            Length of data to be transmitted.
 */
static void SBLMcspiTransfer(sblMcspiCfgObj_t *pSblMcspiCfgObj,
                             unsigned char *pTx,
                             unsigned char *pRx,
                             unsigned int len);


/**
 * \brief   This function will read the flash contents.
 *
 * \param   pSblMcspiCfgObj   Pointer to the MCSPI configuration structure.
 * \param   offset         offset of data on flash
 * \param   size           Size of data to read from flash
 * \param   dst            Destination address
 */
void SBLMcspiReadFlash (sblMcspiCfgObj_t *pSblMcspiCfgObj,
                        unsigned int offset,
                        unsigned int size,
                        unsigned char *dst);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/* Transmit buffer to hold data of 1 page. */
static uint8_t gSblMcspiTxBuffer[260U];

/* Receive buffer to hold data of 1 page. */
static uint8_t gSblMcspiRxBuffer[260U];

/** \brief Application default configuration */
static const sblMcspiCfgObj_t SBL_MCSPIFLASH_DEFAULT =
{
    0U,                                      /* instNum.*/
    0U,                                      /* instAddr.*/
    48000000U,                               /* inClk.*/
    24000000U,                               /* outClk.*/
    0U,                                      /* channelNum.*/
    0U,                                      /* dataLength.*/
    gSblMcspiTxBuffer,                       /* pTx.*/
    gSblMcspiRxBuffer,                       /* rTx.*/
    {
        MCSPI_CH_SINGLE,                     /* channel.*/
        MCSPI_TRANSFER_MODE_TX_RX,           /* txRxMode.*/
        MCSPI_DATA_LINE_COMM_MODE_1,         /* pinMode. */
        MCSPI_CLK_MODE_0,                    /* clkMode.*/
        8U,                                  /* wordLength.*/
        MCSPI_CS_POL_LOW,                    /* csPolarity.*/
        TRUE,                                /* txFifoCfg.*/
        TRUE,                                /* rxFifoCfg.*/
        MCSPI_INTR_TX_EMPTY(0U) | \
        MCSPI_INTR_RX_FULL(0U)               /* interrupt.*/
    },
    {
        TRUE,                                /* csFlag.*/
        MCSPI_MODE_MASTER,                   /* modeFlag.*/
    }
};

/** \brief Global object for the MCSPI bootloader. */
static sblMcspiCfgObj_t gSblMcspiCfg;


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t SBLMcspiCopy(uint32_t *pEntryPoint, uint32_t instNum)
{
    int32_t status = S_PASS;
	uint32_t num_bin;
    volatile uint32_t count = 0x0FFFU;

    gSblMcspiCfg = SBL_MCSPIFLASH_DEFAULT;

    /* Get board info */
    status = SBLMcspiBoardInfoGet(&gSblMcspiCfg);

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = SBLMcspiSocInfoGet(&gSblMcspiCfg);

        if (S_PASS == status)
        {
            /* Initialize the MCSPI controller. */
            status = SBLMcspiInit(&gSblMcspiCfg);

            if(S_PASS == status)
            {
                /* Read data of 1 page size from flash.*/
                SBLMcspiImageCopy(pEntryPoint);

                /* Delay for read to happen from Flash. */
                while(count--);
#ifdef BIN_INSTALL
				for (num_bin = 0; num_bin < NUM_BIN_IMAGES; num_bin++)
				{
					count = 0x0FFFU;
					SBLMcspiBinDataCopy(sbl_binOffsets[num_bin]);
					while(count--);
				}
#endif
            }
            else
            {
                CONSOLEUtilsPrintf("MCSPI initialization failed!\n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("MCSPI instance is not present\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board!\n");
    }

    return (S_PASS);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
static uint32_t SBLMcspiImageCopy(uint32_t *pEntryPoint)
{
    ti_header imageHdr;
    int32_t status = S_PASS;

    /* function to read the header. */
    SBLMcspiReadFlash(&gSblMcspiCfg,
                      SBL_MCSPI_IMAGE_OFFSET,
                      sizeof(imageHdr),
                      (uint8_t *) &imageHdr);

    CONSOLEUtilsPrintf("\nCopying Header of the image ");
    *pEntryPoint = imageHdr.load_addr;
    CONSOLEUtilsPrintf("\nCopying image from flash to DDR\r\n");

    /* Copies image from flash to DDR RAM */
    SBLMcspiReadFlash(&gSblMcspiCfg,
                      SBL_MCSPI_IMAGE_OFFSET + sizeof(imageHdr),
                      imageHdr.image_size,
                      (uint8_t *)(imageHdr.load_addr));

    return status;
}

#ifdef BIN_INSTALL
static uint32_t SBLMcspiBinDataCopy(uint32_t offset)
{
    ti_header imageHdr;
    int32_t status = S_PASS;

    /* function to read the header. */
    SBLMcspiReadFlash(&gSblMcspiCfg,
                      offset,
                      sizeof(imageHdr),
                      (uint8_t *) &imageHdr);

    CONSOLEUtilsPrintf("\nCopying Header of the image ");
    //*pEntryPoint = imageHdr.load_addr;
    CONSOLEUtilsPrintf("\nCopying image from flash to DDR\r\n");

    /* Copies image from flash to DDR RAM */
    SBLMcspiReadFlash(&gSblMcspiCfg,
                      offset + sizeof(imageHdr),
                      imageHdr.image_size,
                      (uint8_t *)(imageHdr.load_addr));

    return status;
}
#endif

int32_t SBLMcspiInit(sblMcspiCfgObj_t *pSblMcspiCfgObj)
{
    int32_t status = S_PASS;

    /* Clock Configuration. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_MCSPI, pSblMcspiCfgObj->instNum, 0U);

    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock Configuration failed !\n");
    }
    else
    {
        /* Perform the MCSPI pinmux. */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_MCSPI,
                                    pSblMcspiCfgObj->instNum,
                                    NULL);

        if (S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
        }
        else
        {
            /* Reset the MCSPI instance.*/
            McSPIReset(pSblMcspiCfgObj->instAddr);

            if (TRUE == pSblMcspiCfgObj->pSblMcspiFlag.csFlag)
            {
                /* Enable CS. */
                MCSPICsEnable(pSblMcspiCfgObj->instAddr, TRUE);

                /* Set the CS polarity. */
                MCSPISetCsPol(pSblMcspiCfgObj->instAddr,
                              pSblMcspiCfgObj->channelNum,
                              pSblMcspiCfgObj->pSblMcspiCfg.csPolarity);
            }
            else if (FALSE == pSblMcspiCfgObj->pSblMcspiFlag.csFlag)
            {
                /**
                 *  Disable CS. In this scenario the CS will be handled
                 *  externally. E.g. would be using an external GPIO pin
                 *  or the CS pin of slave device is pulled to the required
                 *  polarity as default.
                 */
                 MCSPICsEnable(pSblMcspiCfgObj->instAddr, FALSE);
            }

            if (MCSPI_MODE_MASTER == pSblMcspiCfgObj->pSblMcspiFlag.modeFlag)
            {
                /* Perform the necessary configuration for master mode.*/
                MCSPIModeConfig(pSblMcspiCfgObj->instAddr,
                                pSblMcspiCfgObj->channelNum,
                                pSblMcspiCfgObj->pSblMcspiFlag.modeFlag,
                                pSblMcspiCfgObj->pSblMcspiCfg.channel,
                                pSblMcspiCfgObj->pSblMcspiCfg.txRxMode,
                                pSblMcspiCfgObj->pSblMcspiCfg.pinMode);

                /* Configure the clock speed on the bus. */
                MCSPIClkConfig(pSblMcspiCfgObj->instAddr,
                               pSblMcspiCfgObj->channelNum,
                               pSblMcspiCfgObj->inClk,
                               pSblMcspiCfgObj->outClk,
                               pSblMcspiCfgObj->pSblMcspiCfg.clkMode);
            }
            else if (MCSPI_MODE_SLAVE == pSblMcspiCfgObj->pSblMcspiFlag.modeFlag)
            {
                /* Perform the necessary configuration for slave mode.*/
                MCSPIModeConfig(pSblMcspiCfgObj->instAddr,
                                pSblMcspiCfgObj->channelNum,
                                pSblMcspiCfgObj->pSblMcspiFlag.modeFlag,
                                pSblMcspiCfgObj->pSblMcspiCfg.channel,
                                pSblMcspiCfgObj->pSblMcspiCfg.txRxMode,
                                pSblMcspiCfgObj->pSblMcspiCfg.pinMode);
            }

            /* Configure the word length. */
            McSPIWordLengthSet(pSblMcspiCfgObj->instAddr,
                               pSblMcspiCfgObj->channelNum,
                               pSblMcspiCfgObj->pSblMcspiCfg.wordLength);

            /* Enable/disable the Tx FIFO. */
            McSPITxFIFOConfig(pSblMcspiCfgObj->instAddr,
                              pSblMcspiCfgObj->channelNum,
                              pSblMcspiCfgObj->pSblMcspiCfg.txFifoCfg);

            /* Enable/disable the Rx FIFO. */
            McSPIRxFIFOConfig(pSblMcspiCfgObj->instAddr,
                              pSblMcspiCfgObj->channelNum,
                              pSblMcspiCfgObj->pSblMcspiCfg.rxFifoCfg);
        }

    }
    return status;
}

static int32_t SBLMcspiBoardInfoGet(sblMcspiCfgObj_t *pObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t mcspiInstNum;
    uint32_t mcspiCs;

    /* Get the MCSPI data for FLASH from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_W25Q64BV, MCSPI_FLASH_INST_NUM);

    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_MCSPI == modId)
    {
        /* Read the MCSPI instance number. */
        mcspiInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_W25Q64BV,
                                                    MCSPI_FLASH_INST_NUM);

        /* Read the MCSPI chip select number. */
        mcspiCs = BOARDGetDeviceCtrlInfo(DEVICE_ID_W25Q64BV,
                                         MCSPI_FLASH_INST_NUM);

        if ((INVALID_INST_NUM == mcspiInstNum) || (INVALID_INFO == mcspiCs))
        {
            CONSOLEUtilsPrintf("Invalid MCSPI board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("MCSPI Instance number: %d\n", mcspiInstNum);
            CONSOLEUtilsPrintf("Channel/Chip Select number: %d\n", mcspiCs);
            pObj->instNum = mcspiInstNum;
            pObj->channelNum  = mcspiCs;

            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to MCSPI!\n");
    }

    return(status);
}

static int32_t SBLMcspiSocInfoGet(sblMcspiCfgObj_t *pObj)
{
    int32_t status = E_FAIL;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_MCSPI, pObj->instNum))
    {
        /* Read the MCSPI instance base address. */
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_MCSPI, pObj->instNum);
        CONSOLEUtilsPrintf("The instance address is %x\n", pObj->instAddr);

        status = S_PASS;
    }
    else
    {
        CONSOLEUtilsPrintf("The MCSPI instance number %d ", pObj->instNum);
        CONSOLEUtilsPrintf("is not present on the SOC\n");
    }

    return(status);
}

void SBLMcspiReadFlash (sblMcspiCfgObj_t *pSblMcspiCfgObj,
                        unsigned int offset,
                        unsigned int size,
                        unsigned char *dst)
{
    unsigned char txData;
    unsigned char rxData;
    unsigned char addr[3U];
    unsigned int len;

    CONSOLEUtilsPrintf("offset = 0x%x, size = 0x%x, dst = 0x%x\n", offset, size, (uint32_t *) dst);

    /* The process of reading the data from the flash involves asserting
     * proper chipselect line, asserting CSHOLD, selecting correct data format.
     * Then the flash needs a command to indicate start of read and then
     * any number of bytes can be read. After the required number of bytes
     * are read, the CS needs to be de-asserted to indicate the end of transfer
     */
    McSPICSAssert(pSblMcspiCfgObj->instAddr, pSblMcspiCfgObj->channelNum);

    /* Enable the MCSPI channel for communication.*/
    MCSPIChEnable(pSblMcspiCfgObj->instAddr, pSblMcspiCfgObj->channelNum, TRUE);

    /* Send read command to the flash (one byte) */
    txData =  SBL_MCSPI_FLASH_READ_CMD;
    SBLMcspiTransfer(pSblMcspiCfgObj, &txData, &rxData, 1U);

    /* Send the address to start reading from (3 bytes) */
    addr[0U] = (unsigned char)(offset >> 16U);
    addr[1U] = (unsigned char)(offset >> 8U);
    addr[2U] = (unsigned char)offset;
    len = 0U;

    while (len < sizeof(addr))
    {
        SBLMcspiTransfer(pSblMcspiCfgObj, &addr[len], &rxData, 1U);
        len++;
    }

    /* Read all the bytes */
    len = 0U;
    txData = 0U;

    while(len < size)
    {
        SBLMcspiTransfer(pSblMcspiCfgObj, &txData, dst, 1U);
        dst++;
        len++;
    }

    /* Force SPIEN line to the inactive state.*/
    McSPICSDeAssert(pSblMcspiCfgObj->instAddr, pSblMcspiCfgObj->channelNum);

    /* Disable the MCSPI channel.*/
    MCSPIChEnable(pSblMcspiCfgObj->instAddr, pSblMcspiCfgObj->channelNum, FALSE);
}

static void SBLMcspiTransfer(sblMcspiCfgObj_t *pSblMcspiCfgObj,
                             unsigned char *pTx,
                             unsigned char *pRx,
                             unsigned int len)
{
    while(len != 0U)
    {
        /* Wait till TX is empty. */
        while(MCSPI_INTR_TX_EMPTY(pSblMcspiCfgObj->channelNum)!=
              (McSPIIntStatusGet(pSblMcspiCfgObj->instAddr) &
              MCSPI_INTR_TX_EMPTY(pSblMcspiCfgObj->channelNum)));

        McSPITransmitData(pSblMcspiCfgObj->instAddr,
                          pSblMcspiCfgObj->channelNum,
                          *pTx);

        pTx++;

        /* Wait till the DATA in RX. */
        while(MCSPI_INTR_RX_FULL(pSblMcspiCfgObj->channelNum) !=
              (McSPIIntStatusGet(pSblMcspiCfgObj->instAddr) &
              MCSPI_INTR_RX_FULL(pSblMcspiCfgObj->channelNum)));

        *pRx = McSPIReceiveData(pSblMcspiCfgObj->instAddr,
                                pSblMcspiCfgObj->channelNum);

        pRx++;
        len--;
    }
}
