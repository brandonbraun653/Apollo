/**
 *  \file  read_write_app_main.c
 *
 *  \brief    This application code will demonstrate the reading and writing
 *            a Page of the NAND device. The written data is read back and
 *            verified for data integrity.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "board.h"
#include "chipdb.h"
#include "soc.h"
#include "device.h"
#include "console_utils.h"
#include "misc.h"
#include "example_utils_mmu.h"
#include "cache.h"
#include "mmu.h"
#include "nand_device.h"
#include "nand_lib.h"
#include "gpmc.h"
#include "prcm.h"
#include "pinmux.h"
#include "time_utils.h"

/* Application header files */
#include "read_write_app.h"


/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */

/** \brief NAND Flash instance number. */
#define NAND_FLASH_INST_NUM    (0U)

/** \brief NAND application Page Size. */
#define NAND_APP_PAGE_SIZE     (PAGE_SIZE)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the Board related information like Chip Select
 *          Waitpin number of the connected NAND device.
 *
 * \param   pNandObj   Pointer to the NAND object.
 *
 * \retval  S_PASS     On Success
 * \retval  E_FAIL     On Failure
 */
static int32_t NandAppBoardInfoGet(nandAppObj_t *pObj);

/**
 * \brief   This API updates the SOC related information like base address and
 *          interrupt line number.
 *
 * \param   pNandObj   Pointer to the NAND object.
 *
 * \retval  S_PASS     On Success
 * \retval  E_FAIL     On Failure
 */
static int32_t NandAppSocInfoGet(nandAppObj_t *pObj);

/**
 * \brief   NAND Application Initialization API. Initializes the clock
 *          and Pinmux for the GPMC and ELM modules.
 *
 * \param   pNandObj   Pointer to the NAND object.
 *
 * \retval  S_PASS Application init successful
 * \retval  E_FAIL Application init failed
 */
static int32_t NandAppInit(nandAppObj_t *pNandObj);

/**
 * \brief   The API updates the NAND device specific parameters from the
 *          device data based on the device detected.
 *
 * \param   pNandObj   Pointer to the NAND object.
 * \param   pDevData   Pointer to the NAND device data.
 *
 */
static void NandAppUpdateDeviceParams(nandAppObj_t *pObj,
                                      nandDeviceData_t *pDevData);

/**
 *  \brief   This API reads the user input regarding the NAND Address from
 *           where to read and write.
 */
static void NandAppGetUserInput();

/**
 *  \brief   This API compares the Data read from the NAND Page with the data
 *           previously written to the page and verifies it for correctness.
 */
static void NandAppDataCheck(void);

/**
 *  \brief   This API initializes the buffers before Programming the Page of
 *           the NAND device.
 */
static void NandAppBuffInit(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of NAND Read/Write case data structure. */
nandAppReadWriteObj_t NANDAPPREADWRITECFG_DEFAULT_DEFAULT =
{
    NAND_LIB_MEM_CTRLR_GPMC,                /* memCtrlr */
    NAND_LIB_ECC_ALGO_BCH_8BIT,             /* eccAlgo */
    NAND_LIB_XFER_MODE_POLLING,             /* xferMode */
    0U,                                     /* blockNum */
    0U                                      /* pageNum */
};

/** \brief  Global structure for NAND Device Configuration parameters for
            Read/Write Operations. */
static nandAppObj_t gNandObj;

/** \brief Global structure for holding the NAND Read/Write use case
           parameters. */
static nandAppReadWriteObj_t gNandReadWrite;

/** \brief Global variable to store Page data to be written to the flash. */
uint8_t gTxData[NAND_APP_PAGE_SIZE];

/** \brief Global variable to store data read from the Page of a NAND flash. */
uint8_t gRxData[NAND_APP_PAGE_SIZE];

/** \brief Global variable to instantiate the timer for providing a delay. */
timeUtilsObj_t freeRunTimer = {7U, TIME_CLOCK_SEL_24MHZ_EXT_CRY_OSC, TRUE, 0U};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    int32_t status = S_PASS;
    nandDeviceData_t *pNandDeviceData;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /* Initialize the use case data structure with default values. */
    gNandReadWrite = NANDAPPREADWRITECFG_DEFAULT_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();
    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare NAND Read Write Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Initialize the timer to make use of the delay functionality */
    TIMEUtilsInit(&freeRunTimer, 0U);

    /* Clean Data cache. */
    CACHEDataCleanAll();

    status = NandAppBoardInfoGet(&gNandObj);
    if(S_PASS == status)
    {
        status = NandAppSocInfoGet(&gNandObj);
        /* Get SoC Info */
        if(S_PASS == status)
        {
            pNandDeviceData = NANDGetDeviceData(gNandObj.nandFlashId);

            /* Update the device parameters of the connected NAND device. */
            NandAppUpdateDeviceParams(&gNandObj, pNandDeviceData);

            /* Perform the Pinmux and Clock configurations for GPMC and ELM. */
            status = NandAppInit(&gNandObj);

            if(S_PASS == status)
            {
                status = NANDLibInit(&gNandObj.nandLibInfo);

                if(NAND_LIB_PASS == status)
                {
                    /* Initialize the NAND buffers. */
                    NandAppBuffInit();

                    /* Get the User Input on Read Write address of the NAND device */
                    NandAppGetUserInput();

                    status = NANDLibBadBlockCheck(&gNandObj.nandLibInfo,
                        gNandReadWrite.blockNum);

                    if(NAND_LIB_BLOCK_GOOD != status)
                    {
                        CONSOLEUtilsPrintf("Block is Bad\r\n");
                    }
                    else
                    {
                        status = NANDLibBlockErase(&gNandObj.nandLibInfo,
                            gNandReadWrite.blockNum);

                        if(status != NAND_LIB_PASS)
                        {
                            NANDLibMarkBlockAsBad(&gNandObj.nandLibInfo,
                                gNandReadWrite.blockNum);
                        }
                        else
                        {
                            status = NANDLibPageWrite(&gNandObj.nandLibInfo,
                                gNandReadWrite.blockNum, gNandReadWrite.pageNum,
                                &gTxData[0]);

                            if(NAND_LIB_PASS == status)
                            {
                                status = NANDLibPageRead(&gNandObj.nandLibInfo,
                                    gNandReadWrite.blockNum,
                                    gNandReadWrite.pageNum, &gRxData[0]);

                                if(NAND_LIB_PASS == status)
                                {
                                    NandAppDataCheck();
                                }
                                else
                                {
                                    CONSOLEUtilsPrintf("Page Read failed\r\n");
                                }
                            }
                            else
                            {
                                CONSOLEUtilsPrintf("Page Write failed\r\n");
                            }
                        }
                    }
                }
            }
        }
    }
    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t NandAppBoardInfoGet(nandAppObj_t *pObj)
{
    uint32_t *pNandDeviceIdList;
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t devIndex = 0U;

    /* Check which NAND device is present on this board. */
    pNandDeviceIdList = NANDGetDeviceIdList();

    do {
        if(TRUE == BOARDIsDevicePresent(pNandDeviceIdList[devIndex]))
        {
            /* NAND device found */
            pObj->nandFlashId = pNandDeviceIdList[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != pNandDeviceIdList[devIndex]);

    if (DEVICE_ID_INVALID == pNandDeviceIdList[devIndex])
    {
        CONSOLEUtilsPrintf("No NAND Flash found \n");
    }
    else
    {
        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->nandFlashId, NAND_FLASH_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("NAND Flash is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_GPMC == modId)
        {
            CONSOLEUtilsPrintf("NAND flash is connected to GPMC on this board"
                "\n");

            /*
            ** Get the Chip Select of the GPMC to which the Flash is connected.
            */
            pObj->nandLibInfo.nandLibCtrlInfo.chipSel =
                BOARDGetDeviceCtrlModInstNum(pObj->nandFlashId,
                    NAND_FLASH_INST_NUM);

            /*
            ** Get the Wait Pin number connected to the Ready/Busy Pin of
            ** the device.
            */
            pObj->nandLibInfo.nandLibFlashInfo.waitPinNum =
                BOARDGetDeviceCtrlInfo(pObj->nandFlashId, NAND_FLASH_INST_NUM);
            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to GPMC!\n");
        }
    }

    return status;
}

static int32_t NandAppSocInfoGet(nandAppObj_t *pObj)
{
    int32_t status = S_PASS;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPMC, 0U))
    {
        /* Update the base address of GPMC and ELM module. */
        pObj->nandLibInfo.nandLibCtrlInfo.baseAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_GPMC, 0U);

        pObj->nandLibInfo.nandLibCtrlInfo.elmAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_ELM, 0U);
    }
    else
    {
        CONSOLEUtilsPrintf("GPMC IP is not present on this SOC!\n");
        status = E_FAIL;
    }

    return status;
}

static int32_t NandAppInit(nandAppObj_t *pNandObj)
{
    int32_t status = S_PASS;

    /* Enable the clocks for both GPMC and ELM modules. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_GPMC, 0U, FALSE);

    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_ELM, 0U, FALSE);

        if(S_PASS == status)
        {
            /* Perform the pinmux for the GPMC module. */
            status = PINMUXModuleConfig(CHIPDB_MOD_ID_GPMC, 0U, NULL);
        }
    }

    return status;
}

static void NandAppGetUserInput()
{
    CONSOLEUtilsPrintf("Please enter the block Number\r\n");
    CONSOLEUtilsScanf("%d", &gNandReadWrite.blockNum);
    CONSOLEUtilsPrintf("Please enter the Page Number\r\n");
    CONSOLEUtilsScanf("%d", &gNandReadWrite.pageNum);
}

static void NandAppDataCheck(void)
{
    uint32_t byteCnt;
    int32_t status = S_PASS;

    for(byteCnt = 0; byteCnt < NAND_APP_PAGE_SIZE; byteCnt++)
    {
        if(gTxData[byteCnt] != gRxData[byteCnt])
        {
            status = E_FAIL;
            break;
        }
    }

    if(E_FAIL == status)
    {
        CONSOLEUtilsPrintf("Data Integrity failed\r\n");
    }
    else
    {
        CONSOLEUtilsPrintf("Data Integrity Pass\r\n");
    }
}

static void NandAppUpdateDeviceParams(nandAppObj_t *pObj,
                                      nandDeviceData_t *pDevData)
{
    /* Update the NAND device specific data. */
    pObj->nandLibInfo.nandLibFlashInfo.busWidth = pDevData->busWidth;
    pObj->nandLibInfo.nandLibFlashInfo.waitPinPol = pDevData->waitPinPol;
    pObj->nandLibInfo.nandLibFlashInfo.writeProtectPinLvl =
        pDevData->writeProtectPinLvl;

    pObj->nandLibInfo.nandLibCtrlInfo.xferMode = gNandReadWrite.xferMode;
    pObj->nandLibInfo.nandLibCtrlInfo.eccAlgo = gNandReadWrite.eccAlgo;
    pObj->nandLibInfo.nandLibCtrlInfo.memCtrlr = gNandReadWrite.memCtrlr;


    /* Update the NAND device timing parameters. */
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csOnTime =
        pDevData->timingParams.csOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csRdOffTime =
        pDevData->timingParams.csRdOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csWrOffTime =
        pDevData->timingParams.csWrOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advOnTime =
        pDevData->timingParams.advOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advRdOffTime =
        pDevData->timingParams.advRdOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advWrOffTime =
        pDevData->timingParams.advWrOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.weOnTtime =
        pDevData->timingParams.weOnTtime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.weOffTime =
        pDevData->timingParams.weOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.oeOnTime =
        pDevData->timingParams.oeOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.oeOffTime =
        pDevData->timingParams.oeOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.pageBurstAccess =
        pDevData->timingParams.pageBurstAccess;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.rdAccessTime =
        pDevData->timingParams.rdAccessTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrAcessTime =
        pDevData->timingParams.wrAcessTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.rdCycleTime =
        pDevData->timingParams.rdCycleTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrCycleTime =
        pDevData->timingParams.wrCycleTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrDataOnMuxBusTime =
        pDevData->timingParams.wrDataOnMuxBusTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.cycleDelay =
        pDevData->timingParams.cycleDelay;
}

static void NandAppBuffInit()
{
    uint32_t index = 0U;
    /* Clears the buffers before programming the Page. */
    for(index = 0; index < NAND_APP_PAGE_SIZE; index++)
    {
        gRxData[index] = 0;
        gTxData[index] = 0;
    }

    /* Initialize the buffers with some data. */
    gTxData[0] = 'S';
    gTxData[1] = 'T';
    gTxData[2] = 'A';
    gTxData[3] = 'R';
    gTxData[4] = 'T';
    gTxData[5] = 'E';
    gTxData[6] = 'R';
    gTxData[7] = 'W';
    gTxData[8] = 'A';
    gTxData[9] = 'R';
    gTxData[10] = 'E';
}
