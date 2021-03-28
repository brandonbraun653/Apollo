/**
 * \file   flash_app_main.c
 *
 * \brief  Example application main source file, which configures the MCSPI IP
 *         and executes the flash use-case.
 *
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "mcspi.h"
#include "console_utils.h"
#include "serial_flash_w25q64bv.h"

/* Application header files */
#include "mcspi_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/** \brief MCSPI instance number to which flash is connected*/
#define MCSPI_FLASH_INST_NUM            (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Fetch board information.
 *
 * \details   This function will check if SPI flash is present on the board
 *            and accordingly provide the MCSPI controllers instance number
 *            and instance ID..
 *
 * \param     pObj       Pointer to the MCSPI application configuration
 *                       structure.
 *
 * \retval    #S_PASS - Flash support is present for the MCSPI instance.
 * \retVal    #E_FAIL - Flash support is not present for the MCSPI instance.
 */
static int32_t McspiAppBoardInfoGet(mcspiAppCfgObj_t *pObj);

/**
 * \brief     Fetch the MCSPI instance address.
 *
 * \param     pObj       Pointer to the MCSPI application configuration
 *                       structure.
 *
 * \retval    #S_PASS - MCSPI instance is present.
 * \retVal    #E_FAIL - MCSPI instance is not present.
 */
static int32_t McspiAppSocInfoGet(mcspiAppCfgObj_t *pObj);

/**
 * \brief   This function enables the flash to write data
 *          to it.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 */
static void McspiAppWriteEnable(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will check if the write enable command is
 *          successfully latched to the flash device.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 * \retVal  TRUE   Write enable command is latched.
 * \retVal  FALSE  Write enable command is not latched.
 */
static uint32_t McspiAppIsWriteSuccess(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will erase the sector of flash.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 */
static void McspiAppSectorErase(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will check if the flash is busy.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 */
static void McspiAppIsFlashBusy(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will read the status of flash.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 */
static void McspiAppFlashStatus(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will program the flash with valid data.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 */
static void McspiAppWriteToFlash(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will read the flash contents.
 *
 * \param   pCfgMcspi   Pointer to the MCSPI configuration structure.
 *
 */
static void McspiAppReadFromFlash(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   This function will verify the written and read data to the flash.
 *
 */
static void McspiAppVerifyData(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Transmit buffer to hold data of 1 page. */
static uint8_t gFlashAppTxBuffer[260U];
/* Receive buffer to hold data of 1 page. */
static uint8_t gFlashAppRxBuffer[260U];
/* Buffer used to verify the Written and read data. */
static uint8_t gFlashAppVerifyData[256U];

/** \brief Application default configuration */
static const mcspiAppCfgObj_t MCSPIAPPFLASH_DEFAULT =
{
    0U,                                      /* instNum.*/
    0U,                                      /* instAddr.*/
    48000000U,                               /* inClk.*/
    24000000U,                               /* outClk.*/
    0U,                                      /* channelNum.*/
    0U,                                      /* dataLength.*/
    gFlashAppTxBuffer,                       /* pTx.*/
    gFlashAppRxBuffer,                       /* rTx.*/
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
        INTC_TRIG_HIGH_LEVEL,                /* trigType.*/
        0U,                                  /* intrLine.*/
        10U,                                 /* intrPriority.*/
        FALSE,                               /* isIntrSecure.*/
        NULL,                                /* pTxBuf.*/
        NULL,                                /* pRxBuf.*/
        NULL                                 /* pFnIntrHandler.*/
    },
    {
        TRUE,                                /* csFlag.*/
        MCSPI_MODE_MASTER,                   /* modeFlag.*/
        MCSPI_INTERRUPT_MODE                 /* comFlag.*/
    }
};

/** \brief Global object for the MCSPI Flash application. */
static mcspiAppCfgObj_t gFlashAppCfg;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * TODO: 1) While loop based delay used in main(). To be replaced with delay
 *          utils once it is ready.
 *       2) Flash related functions are not generic currently.
 */

int main()
{
    int32_t status = S_PASS;
    volatile uint32_t count = 0x0FFFU;

    gFlashAppCfg = MCSPIAPPFLASH_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare MCSPI Flash Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get board info */
    status = McspiAppBoardInfoGet(&gFlashAppCfg);

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = McspiAppSocInfoGet(&gFlashAppCfg);

        if (S_PASS == status)
        {
            /* Initialize the MCSPI controller. */
            status = MCSPIAppInit(&gFlashAppCfg);

            if(S_PASS == status)
            {
                /* Enable flash for writing data. */
                McspiAppWriteEnable(&gFlashAppCfg);

                /*
                 * Wait until write enable command is successfully written to
                 * flash.
                 */
                while(FALSE == McspiAppIsWriteSuccess(&gFlashAppCfg));

                /* Erase a sector of flash.*/
                McspiAppSectorErase(&gFlashAppCfg);

                /* Pass the write enable command to flash.*/
                McspiAppWriteEnable(&gFlashAppCfg);

                /* Wait until write enable command is successfully written to flash.*/
                while(FALSE == McspiAppIsWriteSuccess(&gFlashAppCfg));

                /* Write data of 1 page size to flash.*/
                /* Currently the data is programmed for 256 bytes
                   and is not configurable.*/
                McspiAppWriteToFlash(&gFlashAppCfg);

                /* Delay for Write to happen to Flash. */
                while(count--);
                count = 0x0FFFU;

                /* Read data of 1 page size from flash.*/
                McspiAppReadFromFlash(&gFlashAppCfg);

                /* Delay for read to happen from Flash. */
                while(count--);

                /* Verify the data written to and read from flash are same or not.*/
                McspiAppVerifyData();
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

static int32_t McspiAppBoardInfoGet(mcspiAppCfgObj_t *pObj)
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

static int32_t McspiAppSocInfoGet(mcspiAppCfgObj_t *pObj)
{
    int32_t status = E_FAIL;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_MCSPI, pObj->instNum))
    {
        /* MCSPI interrupt line number. */
        pObj->intrCfg.intrLine = 65U;

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

static void McspiAppWriteEnable(mcspiAppCfgObj_t *pCfgMcspi)
{
    gFlashAppTxBuffer[0U] = FLASH_WRITE_ENABLE;

    pCfgMcspi->dataLength = 1U;

    MCSPIAppTransfer(pCfgMcspi);
}

static uint32_t McspiAppIsWriteSuccess(mcspiAppCfgObj_t *pCfgMcspi)
{
    unsigned int retVal = FALSE;

    gFlashAppTxBuffer[0U] = FLASH_READ_STAT_REG1;
    gFlashAppTxBuffer[1U] = FLASH_DUMMY_BYTE;

    pCfgMcspi->dataLength = 2U;

    MCSPIAppTransfer(pCfgMcspi);

    if(0x02U == gFlashAppRxBuffer[1U])
    {
        retVal = TRUE;
    }

    return retVal;
}

static void McspiAppSectorErase(mcspiAppCfgObj_t *pCfgMcspi)
{
    gFlashAppTxBuffer[0U] = FLASH_SECTOR_ERASE;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    pCfgMcspi->dataLength = 4U;

    MCSPIAppTransfer(pCfgMcspi);

    McspiAppIsFlashBusy(pCfgMcspi);
}

static void McspiAppIsFlashBusy(mcspiAppCfgObj_t *pCfgMcspi)
{
    do{
        McspiAppFlashStatus(pCfgMcspi);
      } while(gFlashAppRxBuffer[1U] & FLASH_WRITE_IN_PROGRESS);
}

static void McspiAppFlashStatus(mcspiAppCfgObj_t *pCfgMcspi)
{
    gFlashAppTxBuffer[0U] = FLASH_READ_STAT_REG1;
    gFlashAppTxBuffer[1U] = 0xFFU;

    pCfgMcspi->dataLength = 2U;

    MCSPIAppTransfer(pCfgMcspi);

}

static void McspiAppWriteToFlash(mcspiAppCfgObj_t *pCfgMcspi)
{
    unsigned int index = 0U;

    gFlashAppTxBuffer[0U] = FLASH_PAGE_PROGRAM;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    for(index = 0U; index < 256U; index++)
    {
        gFlashAppTxBuffer[index + 4U] = (uint8_t) index;
        gFlashAppVerifyData[index] = (uint8_t) index;
    }

    pCfgMcspi->dataLength = 260U;

    MCSPIAppTransfer(pCfgMcspi);
}

static void McspiAppReadFromFlash(mcspiAppCfgObj_t *pCfgMcspi)
{
    unsigned int index = 0U;

    gFlashAppTxBuffer[0U] = FLASH_DATA_READ;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    for(index = 4U; index < 260U; index++)
    {
        gFlashAppTxBuffer[index] = 0U;
    }

    pCfgMcspi->dataLength = 260U;

    MCSPIAppTransfer(pCfgMcspi);
}

static void McspiAppVerifyData(void)
{
    unsigned int index = 0U;

    for(index = 4U; index < 260U; index++)
    {
        if(gFlashAppRxBuffer[index] != gFlashAppVerifyData[index - 4U])
        {
            CONSOLEUtilsPrintf("\r\nFAILURE!!!\r\n");
            CONSOLEUtilsPrintf("VerifyData: Comparing the data");
            CONSOLEUtilsPrintf(" written to and read");
            CONSOLEUtilsPrintf(" from Flash.\r\nThe two data blocks are");
            CONSOLEUtilsPrintf(" unequal. Mismatch found at index ");
            CONSOLEUtilsPrintf("%d", index);
            CONSOLEUtilsPrintf("\r\n");

            break;
        }
    }

    if(260U == index)
    {
        CONSOLEUtilsPrintf("\r\nSUCCESS!!!\r\nThe data in the Flash ");
        CONSOLEUtilsPrintf("and the one written to it are equal.\r\n");

    }
}
