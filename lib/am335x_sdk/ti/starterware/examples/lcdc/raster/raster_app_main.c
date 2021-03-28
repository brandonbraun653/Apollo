/**
 * \file   raster_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case.
 *
 * \details This application displays the static image on LCD using display
 *          sub system. The input image will be provided in a header file. LCD
 *          will be connected to LCDC through parallel interface.
 *
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
#ifdef RTOS_BUILD
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/osal/RegisterIntr.h>
#endif
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "mmu.h"
#include "example_utils_mmu.h"
#include "console_utils.h"
#include "interrupt.h"
#include "lcd_device.h"
#include "misc.h"

/* Application header files */
#include "lcdc_app.h"
#include "raster_app.h"

#ifdef LCD_EVM
#include "raster_input_image_800x480x24.h"
#endif /* ifdef LCD_EVM */

#ifdef LCD_LCD4_DCARD
#include "raster_input_image_480x272x16.h"
#endif /* ifdef LCD_LCD4_DCARD */



/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief LCD device instance number. */
#define LCDC_LCD_INST_NUM    (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the board info like device id, and calls device
 *          selection and device power on functions.
 *
 * \param   pObj        Pointer to the LCDC object.
 *
 * \retval  S_PASS      Board info successful retrieved. LCD is connected to
 *                      LCDC on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - LCD device may not be available on this board.
 *                      - LCD may not be connected to LCDC on this board.
 */
static int32_t LcdcAppBoardInfoGet(lcdcAppObj_t *pObj);


/**
 * \brief   This API gets the soc info - base address of LCDC instance and
 *          interrupt number of display sub system.
 *
 * \param   pObj        Pointer to the LCDC object.
 *
 * \retval  S_PASS      Soc info is successfully retrieved.
 * \retval  E_FAIL      Soc info retrieval is failed.
 */
static int32_t LcdcAppSocInfoGet(lcdcAppObj_t *pObj);


/**
 * \brief   This API updates the device data, use case parameter values in the
 *          IP configuration data structure.
 *
 * \param   pObj        Pointer to the LCDC object.
 * \param   pLcdData    Pointer to the structure holding the LCD panel data.
 * \param   pRaster     Pointer to the raster use case data structure.
 */
static void LcdcAppUpdateIpConfigParams(lcdcAppObj_t *pObj,
                                       lcdDeviceData_t *pLcdData,
                                       lcdcAppRasterCfg_t *pRaster);


/**
 * \brief   This API configures the system interrupt controller and enables the
 *          LCDC system interrupt.
 *
 * \param   intrNum       LCDC System interrupt number
 */
static int32_t LcdcAppInterruptConfig(uint32_t intrNum);


/**
 * \brief   LCDC's interrupt service routine.
 *
 * \param   intrId       LCDC System interrupt number
 * \param   cpuId        CPU Id.
 * \param   pUserParam   Pointer to the structure containing the IP info.
 */
 #ifndef RTOS_BUILD
void LcdcAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#else
void LcdcAppIsr(uintptr_t pUserParam);
#endif


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/** \brief Default values of raster use case data structure. */
lcdcAppRasterCfg_t LCDCAPPRASTERCFG_DEFAULT =
{
    (uint8_t *)&inputImage[0],            /* pInputBuf */
    sizeof(inputImage),                    /* inputBufSize */
    800U,                                  /* inputWidth */
    480U,                                  /* inputHeight */
    LCDC_PIXEL_FORMAT_RGB24_UNPACKED       /* inputPixelFmt */
};


/** \brief Global data structure holding the LCDC IP configuration parameters. */
static lcdcAppObj_t gLcdc;

/** \brief Global data structure holding the raster use case parameters. */
static lcdcAppRasterCfg_t gRaster;


/** \brief Counter indicating the number of under flow interrupts. */
volatile uint32_t gLcdcUnderflowCnt = 0U;

/** \brief Counter indicating the number of sync lost interrupts. */
volatile uint32_t gLcdcSyncLostCnt  = 0U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#ifndef RTOS_BUILD
int main()
#else
/*
 *  ======== lcdcTestTask ========
 */
Void lcdcTestTask(UArg a0, UArg a1)
#endif
{
    int32_t status = S_PASS;
    lcdDeviceData_t *lcdDeviceData;

    /*
     * Initialize the global IP configuration and use case data structure
     * objects with default values.
     */
    gLcdc = LCDCAPPOBJ_DEFAULT;
    gRaster = LCDCAPPRASTERCFG_DEFAULT;

#ifndef RTOS_BUILD
    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);
#endif

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare LCDC Raster Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    
    DCARDInit();
    
#ifndef RTOS_BUILD   
    /* Clean Data cache. */
    CACHEDataCleanAll();
#endif

    /* Get board info */
    status = LcdcAppBoardInfoGet(&gLcdc);
    if (S_PASS == status)
    {
        /* Get SoC info */
        status = LcdcAppSocInfoGet(&gLcdc);
        if (S_PASS == status)
        {
#ifndef RTOS_BUILD
            /* Perform initialization of Interrupt controller*/
            INTCInit(FALSE);
#endif

            /* LCDC Interrupt configuration */
            status = LcdcAppInterruptConfig(gLcdc.lcdcSysIntrNum);
            if (S_PASS == status)
            {
                /* Get the LCD panel data */
                lcdDeviceData = LCDGetDeviceData(gLcdc.lcdcLcdDeviceId);

                /* Update IP config parameters with device,use case values */
                LcdcAppUpdateIpConfigParams(&gLcdc, lcdDeviceData, &gRaster);

                /* LCDC clock/pin mux and IP configuration */
                status = LCDCAppInit(&gLcdc);
                if (S_PASS == status)
                {
                    CONSOLEUtilsPrintf("\nNow Displaying image on LCD ...\n");
                    while(1)
                    {
                        /* Use Case Implementation */
                        if(0U != gLcdcUnderflowCnt)
                        {
                            CONSOLEUtilsPrintf
                                ("\n LCDC Under flow Interrupt \n");
                            gLcdcUnderflowCnt = 0U;
                        }
                        if(0U != gLcdcSyncLostCnt)
                        {
                            CONSOLEUtilsPrintf
                                ("\n LCDC Sync Lost Interrupt \n");
                            gLcdcSyncLostCnt = 0U;
                        }
                    }
                }
                else
                {
                    CONSOLEUtilsPrintf("\nLCDC IP configuration is failed \n");
                }
            }
            else
            {
                CONSOLEUtilsPrintf("\nInterrupt configuration failed ...\n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\nIP information is not present \n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board!\n");
    }
#ifndef RTOS_BUILD
    return (S_PASS);
#endif
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t LcdcAppBoardInfoGet(lcdcAppObj_t *pObj)
{
    uint32_t *lcdDeviceIdlist;
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t devIndex = 0U;

    /* Check which LCD device is present on this board */
    lcdDeviceIdlist = LCDGetDeviceIdList();

    do {
        if (TRUE == BOARDIsDevicePresent(lcdDeviceIdlist[devIndex]))
        {
            /* LCD device found */
            pObj->lcdcLcdDeviceId = lcdDeviceIdlist[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != lcdDeviceIdlist[devIndex]);

    if (DEVICE_ID_INVALID == lcdDeviceIdlist[devIndex])
    {
        CONSOLEUtilsPrintf("No LCD device found \n");
    }
    else
    {
        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->lcdcLcdDeviceId,
            LCDC_LCD_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Device is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_LCDC == modId)
        {
            CONSOLEUtilsPrintf("Device is connected to LCDC on this board!\n");

            /* Function to power on the device */
            BOARDPowerOnDevice(pObj->lcdcLcdDeviceId, LCDC_LCD_INST_NUM, TRUE);

            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to LCDC!\n");
        }
    }

    return (status);
}


static int32_t LcdcAppSocInfoGet(lcdcAppObj_t *pObj)
{
    int32_t status = E_FAIL;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_LCDC, 0U))
    {
        pObj->lcdcInstAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_LCDC, 0U);

        if (SOC_FAMILY_ID_AM335X == SOCGetSocFamilyId())
        {
            /*TODO: This interrupt number has to be provided by soc info */
            pObj->lcdcSysIntrNum = 36U;
            status = S_PASS;
        }
        else
        {
            /* SOC is not AM335x */
        }
    }
    else
    {
        CONSOLEUtilsPrintf("LCDC IP is not present on this SOC!\n");
    }

    return status;
}


static void LcdcAppUpdateIpConfigParams(lcdcAppObj_t *pLcdc,
                                       lcdDeviceData_t *pLcdData,
                                       lcdcAppRasterCfg_t *pRaster)
{
    lcdcRasterTimingCfg_t *pTiming = &pLcdc->lcdcCfg.lcd.timingCfg;
    lcdcRasterPolarityCfg_t *pPol  = &pLcdc->lcdcCfg.lcd.polarityCfg;
    lcdcRasterDisplayAttrCfg_t *pFmt = &pLcdc->lcdcCfg.lcd.attrCfg;
    lcdDeviceBoardData_t lcdDevBoardData;
    
    /* Update LCD timing parameters. */
    pTiming->pixelClk = pLcdData->pixelClk;
    pTiming->ppl      = pLcdData->pixelsPerLine;
    pTiming->hfp      = pLcdData->horzFrontPorch;
    pTiming->hbp      = pLcdData->horzBackPorch;
    pTiming->hsw      = pLcdData->horzSyncWidth;
    pTiming->lpp      = pLcdData->linesPerPanel;
    pTiming->vfp      = pLcdData->vertFrontPorch;
    pTiming->vbp      = pLcdData->vertBackPorch;
    pTiming->vsw      = pLcdData->vertSyncWidth;


    /* Update sync signal polarities */
    pPol->hSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->hSyncPolarity) ? LCDC_RASTER_H_SYNC_POL_LOW :
        LCDC_RASTER_H_SYNC_POL_HIGH;
    pPol->vSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->vSyncPolarity) ? LCDC_RASTER_V_SYNC_POL_LOW :
        LCDC_RASTER_V_SYNC_POL_HIGH;
    pPol->outputEnablePolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->outputEnablePolarity) ? LCDC_RASTER_OUTPUT_ENABLE_POL_LOW :
        LCDC_RASTER_OUTPUT_ENABLE_POL_HIGH;
    pPol->pixelClkPolarity = (LCD_ACTIVE_EDGE_RISING ==
        pLcdData->pixelClkPolarity) ? LCDC_RASTER_PCLK_POL_RISING_EDGE :
        LCDC_RASTER_PCLK_POL_FALLING_EDGE;
    pPol->syncEdge = (LCD_ACTIVE_EDGE_RISING == pLcdData->activeSyncEdge) ?
        LCDC_RASTER_ACTIVE_SYNC_EDGE_RISING :
        LCDC_RASTER_ACTIVE_SYNC_EDGE_FALLING;
    pPol->sycnEdgeCtrl = (LCD_SYNC_EDGE_CTRL_SAME_EDGE ==
    pLcdData->syncEdgeControl) ? LCDC_RASTER_SYNC_CTRL_INACTIVE :
    LCDC_RASTER_SYNC_CTRL_ACTIVE;

    /* Update the pixel format and palette mode based on the board */
    BOARDGetLcdDevData(pLcdData->devId, &lcdDevBoardData);
    
    pFmt->pixelFormat = lcdDevBoardData.pixelFormat;
    pFmt->paletteMode = lcdDevBoardData.paletteMode;
    
    /* Update the buffer pointer and buffer size */
    pLcdc->pInputBuf = pRaster->pInputBuf;
    pLcdc->inputBufSize = pRaster->inputBufSize;
}


static int32_t LcdcAppInterruptConfig(uint32_t intrNum)
{
    int32_t status = S_PASS;
#ifndef RTOS_BUILD
    intcIntrParams_t lcdcIntrParams;

    lcdcIntrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
    lcdcIntrParams.priority       = 0x20U;
    lcdcIntrParams.pFnIntrHandler = &LcdcAppIsr;
    lcdcIntrParams.isIntrSecure   = FALSE;
    lcdcIntrParams.pUserParam     = &gLcdc;

    /* Configure the interrupt controller */
    status = INTCConfigIntr(intrNum, &lcdcIntrParams, FALSE);
#else
	OsalRegisterIntrParams_t interruptRegParams;
    HwiP_Handle hwiPHandlePtr;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.arg=(uintptr_t)&gLcdc;
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.isrRoutine=&LcdcAppIsr;
    interruptRegParams.corepacConfig.priority = 0x00;
    interruptRegParams.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    interruptRegParams.corepacConfig.intVecNum=intrNum;
    /* Register interrupts */
    Osal_RegisterInterrupt(&interruptRegParams, &hwiPHandlePtr);
#endif
    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf(" Interrupt controller configuration failed \n ");
    }

    return status;
}

#ifndef RTOS_BUILD
void LcdcAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#else
void LcdcAppIsr(uintptr_t pUserParam)
#endif
{
    lcdcAppObj_t *pObj = (lcdcAppObj_t *)pUserParam;
    uint32_t lcdcBaseAddr = pObj->lcdcInstAddr;
    uint32_t intrStatus = 0U;

    intrStatus = LCDCIntrStatus(lcdcBaseAddr);

    if (0U != intrStatus)
    {
        if (intrStatus & LCDC_INTR_MASK_END_OF_FRAME_0)
        {
            LCDCDmaFrameBufConfig(lcdcBaseAddr, (uint32_t)pObj->pInputBuf,
                (uint32_t)pObj->pInputBuf + pObj->inputBufSize - 2U,
                LCDC_FRM_BUF_ID_0);

            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_END_OF_FRAME_0);
        }

        if (intrStatus & LCDC_INTR_MASK_END_OF_FRAME_1)
        {
            LCDCDmaFrameBufConfig(lcdcBaseAddr, (uint32_t)pObj->pInputBuf,
                (uint32_t)pObj->pInputBuf + pObj->inputBufSize - 2U,
                LCDC_FRM_BUF_ID_1);

            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_END_OF_FRAME_1);
        }

        if (intrStatus & LCDC_INTR_MASK_FIFO_UNDERFLOW)
        {
            gLcdcUnderflowCnt++;
            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_FIFO_UNDERFLOW);
        }

        if (intrStatus & LCDC_INTR_MASK_SYNC_LOST)
        {
            gLcdcSyncLostCnt++;
            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_SYNC_LOST);
        }
    }
}

#ifdef RTOS_BUILD
/*
 *  ======== main ========
 */
int main(void)
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(lcdcTestTask, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
    /* Start BIOS */
    BIOS_start();    /* does not return */
    return 0;
}
#endif
/* -------------------------------------------------------------------------- */
/*              Use-case specific Internal Function Definitions               */
/* -------------------------------------------------------------------------- */
