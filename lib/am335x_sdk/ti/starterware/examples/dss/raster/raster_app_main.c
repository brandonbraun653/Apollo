/**
 * \file   raster_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case.
 *
 * \details This application displays the static image on LCD using display
 *          sub system. The input image will be provided in a header file. LCD
 *          will be connected to DSS through parallel interface.
 *
 *  \copyright Copyright (C) 2013-2018 Texas Instruments Incorporated -
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
#include "dss_app.h"
#include "raster_app.h"
#include "raster_input_image.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief LCD device instance number. */
#define DSS_LCD_INST_NUM    (0U)

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
 * \param   pObj        Pointer to the dss object.
 *
 * \retval  S_PASS      Board info successful retrieved. LCD is connected to
 *                      DSS on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - LCD device may not be available on this board.
 *                      - LCD may not be connected to DSS on this board.
 */
static int32_t DssAppBoardInfoGet(dssAppObj_t *pObj);


/**
 * \brief   This API gets the soc info - base address of DSS instance and
 *          interrupt number of display sub system.
 *
 * \param   pObj        Pointer to the dss object.
 *
 * \retval  S_PASS      Soc info is successfully retrieved.
 * \retval  E_FAIL      Soc info retrieval is failed.
 */
static int32_t DssAppSocInfoGet(dssAppObj_t *pObj);


/**
 * \brief   This API updates the device data, use case parameter values in the
 *          IP configuration data structure.
 *
 * \param   pObj        Pointer to the dss object.
 * \param   pLcdData    Pointer to the structure holding the LCD panel data.
 * \param   pRaster     Pointer to the raster use case data structure.
 */
static void DssAppUpdateIpConfigParams(dssAppObj_t *pObj,
                                       lcdDeviceData_t *pLcdData,
                                       dssAppRasterCfg_t *pRaster);


/**
 * \brief   This API configures the system interrupt controller and enables the
 *          display sub system system interrupt.
 *
 * \param   intrNum       DSS System interrupt number
 */
static int32_t DssAppInterruptConfig(uint32_t intrNum);


/**
 * \brief   Display sub system's interrupt service routine.
 *
 * \param   intrId       DSS System interrupt number
 * \param   cpuId        CPU Id.
 * \param   pUserParam   Pointer to the structure containing the IP info.
 */
#ifndef RTOS_BUILD
void DssAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#else
void DssAppIsr(uintptr_t pUserParam);
#endif


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/** \brief Default values of raster use case data structure. */
dssAppRasterCfg_t DSSAPPRASTERCFG_DEFAULT =
{
    (uint32_t *)&inputImage[0],            /* pInputBuf */
    800U,                                  /* inputWidth */
    480U,                                  /* inputHeight */
    DSS_DISPC_VID_FMT_TYPE_RGB24_UNPACKED  /* inputPixelFmt */
};


/** \brief Global data structure holding the DSS IP configuration parameters. */
static dssAppObj_t gDss;


/** \brief Global data structure holding the raster use case parameters. */
static dssAppRasterCfg_t gRaster;


/** \brief Counter indicating the number of video under flow interrupts. */
volatile uint32_t gDssVidUnderflowCnt = 0U;

/** \brief Counter indicating the number of sync lost interrupts. */
volatile uint32_t gDssVidSyncLostCnt  = 0U;

/** \brief Flag used for software ping-pong of frame buffers. */
volatile uint32_t gDssAppBufSelectFlag = 1U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#ifndef RTOS_BUILD
int main()
#else
/*
 *  ======== dssTestTask ========
 */
Void dssTestTask(UArg a0, UArg a1)
#endif
{
    int32_t status = S_PASS;
    lcdDeviceData_t *lcdDeviceData;

    /*
     * Initialize the global IP configuration and use case data structure
     * objects with default values.
     */
    gDss = DSSAPPOBJ_DEFAULT;
    gRaster = DSSAPPRASTERCFG_DEFAULT;

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

    CONSOLEUtilsPrintf("\n StarterWare DSS Raster Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();
#ifndef RTOS_BUILD
    /* Clean Data cache. */
    CACHEDataCleanAll();
#endif

    /* Get board info */
    status = DssAppBoardInfoGet(&gDss);
    if (S_PASS == status)
    {
        /* Get SoC info */
        status = DssAppSocInfoGet(&gDss);
        if(S_PASS == status)
        {
#ifndef RTOS_BUILD
            /* Enable CPU interrupts*/
            INTCEnableCpuIntr(0xC0U);
            /* Perform initialization of Interrupt controller*/
            INTCInit(FALSE);
#endif
            /* DSS Interrupt configuration */
            status = DssAppInterruptConfig(gDss.dssSysIntrNum);
            if(S_PASS == status)
            {
                /* Get the LCD panel data */
                lcdDeviceData = LCDGetDeviceData(gDss.dssLcdDeviceId);

                /* Update IP config parameters with device,use case values */
                DssAppUpdateIpConfigParams(&gDss, lcdDeviceData, &gRaster);

                /* GPIO clock/pin mux and IP configuration */
                status = DSSAppInit(&gDss);
                if(S_PASS == status)
                {
                    CONSOLEUtilsPrintf("\nNow Displaying image on LCD ...\n");
                    while(1)
                    {
                        /* Use Case Implementation */
                        if(0U != gDssVidUnderflowCnt)
                        {
                            CONSOLEUtilsPrintf
                                ("\n Video under flow Interrupt \n");
                            gDssVidUnderflowCnt = 0;
                        }
                        if(0U != gDssVidSyncLostCnt)
                        {
                            CONSOLEUtilsPrintf
                                ("\n Video Sync Lost Interrupt \n");
                            gDssVidSyncLostCnt = 0;
                        }
                    }
                }
                else
                {
                    CONSOLEUtilsPrintf("\nDSS IP configuration is failed \n");
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

static int32_t DssAppBoardInfoGet(dssAppObj_t *pObj)
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
            pObj->dssLcdDeviceId = lcdDeviceIdlist[devIndex];
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
        modId = BOARDGetDeviceCtrlModId(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Device is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_DSS == modId)
        {
            CONSOLEUtilsPrintf("Device is connected to DSS on this board!\n");

            /* Function to power on the device */
            BOARDPowerOnDevice(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM, TRUE);

            /* Function to select LCD/HDMI device */
            BOARDSelectDevice(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM);

            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to DSS!\n");
        }
    }

    return (status);
}


static int32_t DssAppSocInfoGet(dssAppObj_t *pObj)
{
    int32_t status = E_FAIL;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_DSS, 0U))
    {
        pObj->dssInstAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DSS, 0U);

        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            /*TODO: This interrupt number has to be provided by soc info */
            pObj->dssSysIntrNum = 159U;  /* 127 + 32 */
            status = S_PASS;
        }
        else
        {
            /* SOC is not AM43xx */
        }
    }
    else
    {
        CONSOLEUtilsPrintf("DSS IP is not present on this SOC!\n");
    }

    return status;
}


static void DssAppUpdateIpConfigParams(dssAppObj_t *pDss,
                                       lcdDeviceData_t *pLcdData,
                                       dssAppRasterCfg_t *pRaster)
{
    dssDispcLcdTimingCfg_t *pTiming = &pDss->dssCfg.lcd.timingCfg;
    dssDispcLcdPolarityCfg_t *pPol  = &pDss->dssCfg.lcd.polarityCfg;

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
        pLcdData->hSyncPolarity) ? DSS_DISPC_LCD_H_SYNC_POL_LOW :
        DSS_DISPC_LCD_H_SYNC_POL_HIGH;
    pPol->vSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->vSyncPolarity) ? DSS_DISPC_LCD_V_SYNC_POL_LOW :
        DSS_DISPC_LCD_V_SYNC_POL_HIGH;
    pPol->outputEnablePolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->outputEnablePolarity) ? DSS_DISPC_LCD_OUTPUT_ENABLE_POL_LOW :
        DSS_DISPC_LCD_OUTPUT_ENABLE_POL_HIGH;
    pPol->pixelClkPolarity = (LCD_ACTIVE_EDGE_RISING ==
        pLcdData->pixelClkPolarity) ? DSS_DISPC_LCD_PCLK_POL_RISING_EDGE :
        DSS_DISPC_LCD_PCLK_POL_FALLING_EDGE;
    pPol->syncEdge = (LCD_ACTIVE_EDGE_RISING == pLcdData->activeSyncEdge) ?
        DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_RISING :
        DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_FALLING;
    pPol->sycnEdgeCtrl = (LCD_SYNC_EDGE_CTRL_SAME_EDGE ==
    pLcdData->syncEdgeControl) ? DSS_DISPC_LCD_SYNC_PCLK_CTRL_OFF :
    DSS_DISPC_LCD_SYNC_PCLK_CTRL_ON;


    /* Update the video window and format configuration parameters. */
    pDss->dssCfg.vid.vidFmt.format = pRaster->inputPixelFmt;
    pDss->dssCfg.vid.vidWindow.inputWidth  = pRaster->inputWidth;
    pDss->dssCfg.vid.vidWindow.inputHeight = pRaster->inputHeight;
    /* Output size is configured to be same as input size. */
    pDss->dssCfg.vid.vidWindow.outputWidth = pRaster->inputWidth;
    pDss->dssCfg.vid.vidWindow.outputHeight = pRaster->inputHeight;

    /* Update the buffer pointer */
    pDss->pInputBuf = pRaster->pInputBuf;
}


static int32_t DssAppInterruptConfig(uint32_t intrNum)
{
    int32_t status = S_PASS;
#ifndef RTOS_BUILD
    intcIntrParams_t dssIntrParams;

    dssIntrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
    dssIntrParams.priority       = 0x00;
    dssIntrParams.pFnIntrHandler = &DssAppIsr;
    dssIntrParams.isIntrSecure   = FALSE;
    dssIntrParams.pUserParam     = &gDss;

    /* Configure the interrupt controller */
    status = INTCConfigIntr(intrNum, &dssIntrParams, FALSE);
#else
	OsalRegisterIntrParams_t interruptRegParams;
    HwiP_Handle hwiPHandlePtr;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.arg=(uintptr_t) &gDss;
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.isrRoutine=&DssAppIsr;
    interruptRegParams.corepacConfig.priority = 0x00;
    interruptRegParams.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    interruptRegParams.corepacConfig.intVecNum=intrNum;
    /* Register interrupts */
    Osal_RegisterInterrupt(&interruptRegParams, &hwiPHandlePtr);
#endif
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf(" Interrupt controller configuration failed \n ");
    }

    return status;
}

#ifndef RTOS_BUILD
void DssAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#else
void DssAppIsr(uintptr_t pUserParam)
#endif
{
    dssAppObj_t *pObj = (dssAppObj_t *)&pUserParam;
    uint32_t dssBaseAddr = pObj->dssInstAddr;
    uint32_t intrStatus = 0U;

    intrStatus = DSSDispcIntrStatus(dssBaseAddr);

    if(0 != intrStatus)
    {
        if(intrStatus & DSS_DISPC_INTR_MASK_VSYNC)
        {
            /* Previous frame has been transferred to LCD. Set the address
               of frame buffer from which next frame has to be taken for
               transfer. */

            if(1U == gDssAppBufSelectFlag)
            {
                DSSDispcGfxSetBufAddr(dssBaseAddr, (uint32_t)inputImage,
                    DSS_DISPC_FRM_BUF_ID_0);

                gDssAppBufSelectFlag = 2U;
            }
            else
            {
                DSSDispcGfxSetBufAddr(dssBaseAddr, (uint32_t)inputImage,
                    DSS_DISPC_FRM_BUF_ID_0);

                gDssAppBufSelectFlag = 1U;

            }

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr, DSS_DISPC_INTR_MASK_VSYNC);

            /*
             * Set the GoLCD bit so that new buffer address will be
             * taken at next VFP.
             */
            DSSDispcShadowCfgEnable(dssBaseAddr);
        }
        else if (intrStatus & DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW)
        {
            gDssVidUnderflowCnt++;

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr,
                DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW);

        }
        else if (intrStatus & DSS_DISPC_INTR_MASK_SYNC_LOST_LCD)
        {
            gDssVidSyncLostCnt++;

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr,
                DSS_DISPC_INTR_MASK_SYNC_LOST_LCD);
        }
        else
        {
            /* This will not occur as no other interrupts are enabled. */
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

    task = Task_create(dssTestTask, NULL, &eb);
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
