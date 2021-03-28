/**
 * \file   capture_display_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case of capturing the data from camera interface
 *         and displaying it on LCD using DSS.
 *
 * \details This application captures the input video data from a camera
 *          sensor through VPFE interface and displays the video data on the
 *          LCD using the display sub system.
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
#include "display_utils.h"
#include "interrupt.h"
#include "lcd_device.h"
#include "camera_device.h"
#include "misc.h"
#include "vpfe.h"

/* Application header files */
#include "vpfe_app.h"
#include "capture_display_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief LCD device instance number. */
#define VPFE_CAMERA_INST_NUM    (0U)

/** \brief Input image frame width in number of pixels per line. */
#define IMAGE_X_SIZE            (800U)

/** \brief Input image frame height in number of lines per panel. */
#define IMAGE_Y_SIZE            (480U)

/** \brief Number of bytes per pixel. */
#define VPFE_APP_BPP            (4U)

/** \brief Alignment size in number of bytes. */
#define VPFE_APP_ALIGNMENT_SIZE_256      (0x100U)

/** \brief Macro to shift data shift by 0 bits. */
#define VPFE_APP_DATA_SHIFT_0        (0U)

/** \brief Macro to shift data shift by 2 bits. */
#define VPFE_APP_DATA_SHIFT_2        (2U)

/** \brief Macro to shift data shift by 8 bits. */
#define VPFE_APP_DATA_SHIFT_8        (8U)

/** \brief Macro to shift data shift by 16 bits. */
#define VPFE_APP_DATA_SHIFT_16       (16U)

/** \brief Macro to shift data shift by 24 bits. */
#define VPFE_APP_DATA_SHIFT_24       (24U)

/** \brief Line offset that defines the number of bytes between two output
           data lines. */
#define LINE_OFFSET              (((IMAGE_X_SIZE * VPFE_APP_BPP) & 0xFF) ? \
    (((IMAGE_X_SIZE * VPFE_APP_BPP) + 0x100) & ~(0xFF)) : \
    (((IMAGE_X_SIZE * VPFE_APP_BPP) + 0x000) & ~(0xFF)))

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
 * \param   pObj        Pointer to the vpfe object.
 *
 * \retval  S_PASS      Board info successful retrieved. Camera sensor is
 *                      connected to VPFE on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - Camera sensor device may not be available on this
 *                        board Or even if the camera sensor device is present
 *                        it is not connected to VPFE on this board.
 */
static int32_t VpfeAppBoardInfoGet(vpfeAppObj_t *pObj);


/**
 * \brief   This API gets the soc info - base address of VPFE instance and
 *          interrupt number of vpfe.
 *
 * \param   pObj        Pointer to the vpfe object.
 *
 * \retval  S_PASS      Soc info is successfully retrieved.
 * \retval  E_FAIL      Soc info retrieval is failed.
 */
static int32_t VpfeAppSocInfoGet(vpfeAppObj_t *pObj);


/**
 * \brief   This API updates the device data, use case parameter values in the
 *          IP configuration data structure.
 *
 * \param   pObj      Pointer to the vpfe object.
 * \param   pfrm      Pointer to the structure holding the frame buffer params.
 * \param   pRaster   Pointer to the raster use case data structure.
 */
static void VpfeAppUpdateIpConfigParams(vpfeAppObj_t *pVpfe,
                                        vpfeAppFrmBufCfg_t *pfrm,
                                        vpfeAppRasterCfg_t *pRaster);


/**
 * \brief   This API configures the system interrupt controller and enables the
 *          vpfe system interrupt.
 *
 * \param   intrNum       VPFE System interrupt number
 */
static int32_t VpfeAppInterruptConfig(uint32_t intrNum);


/**
 * \brief   VPFE's interrupt service routine.
 *
 * \details This interrupt service routine will update the next empty buffer
 *          address. Since this register is a shadow register, this will be
 *          taken into effect at next VFP. When the current buffer is filled
 *          with data, the data will be filled in the above configured empty
 *          buffer.
 *
 * \param   intrId       VPFE System interrupt number
 * \param   cpuId        CPU Id.
 * \param   pUserParam   Pointer to the structure containing the IP info.
 */
void VpfeAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);


/**
 * \brief   Display Utils ISR call back function. This function returns the
 *          address of the frame buffer which needs to be displayed next.
 *
 * \param   currBufAddr  Address of frame buffer that is displaying currently.
 *
 * \retval  nextBufAddr  Address of next buffer that needs to be displayed.
 */
uint32_t VpfeAppdisplayUtilsIsrCb(uint32_t currBufAddr);


/**
 * \brief   This function performs initialization of VPFE application
 *          frame buffer configuration parameters.
 */
void VpfeAppFrameBufInit(void);

/**
 * \brief   This function handles the input frame data. This function will
 *          perform the conversion of received input data into YUV2 form and
 *          copies the data to the output buffer that will be used for display.
 */
void VpfeAppHandleFrameData(void);

/**
 * \brief   VPFE application ISR call back function. This function returns the
 *          address of the empty frame buffer, so that when next frame of data
 *          is received that data will be copied to the empty frame buffer.
 *
 * \param   currBufAddr  Address of frame buffer that is being filled.
 *
 * \retval  nextBufAddr  Address of next empty buffer.
 */
uint32_t VpfeAppIsrCb(uint32_t currBufAddr);


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of raster use case data structure. */
vpfeAppRasterCfg_t VPFEAPPRASTERCFG_DEFAULT =
{
    IMAGE_X_SIZE,                  /* inputFrmWidth */
    IMAGE_Y_SIZE,                  /* inputFrmHeight */
    DISPLAY_UTILS_PIXEL_FMT_YUV2,  /* inputFrmPixelFmt */
};


/** \brief Global data structure holding the DSS IP configuration parameters. */
static vpfeAppObj_t gVpfe;

/** \brief Global data structure holding the raster use case parameters. */
static vpfeAppRasterCfg_t gRaster;

/** \brief Global data structure holding the frame buffer parameters. */
static vpfeAppFrmBufCfg_t gFrmBuf;

/** \brief Output frame buffer 1. */
ALIGN_VAR(frameBufferYuv, VPFE_APP_ALIGNMENT_SIZE_256)
uint32_t frameBufferYuv[IMAGE_Y_SIZE][IMAGE_X_SIZE / 2U];

/** \brief Output frame buffer 2. */
ALIGN_VAR(frameBufferYuv1, VPFE_APP_ALIGNMENT_SIZE_256)
uint32_t frameBufferYuv1[IMAGE_Y_SIZE][IMAGE_X_SIZE / 2U];

/** \brief Input frame buffer 1. */
ALIGN_VAR(camBuffer, VPFE_APP_ALIGNMENT_SIZE_256)
uint32_t camBuffer[(IMAGE_Y_SIZE * LINE_OFFSET) / 4U];

/** \brief Input frame buffer 2. */
ALIGN_VAR(camBuffer1, VPFE_APP_ALIGNMENT_SIZE_256)
uint32_t camBuffer1[(IMAGE_Y_SIZE * LINE_OFFSET) / 4U];


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;
    uint32_t camInst = 0U;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /*
     * Initialize the global objects of use case and IP configuration
     * data structures with default values.
     */
    gVpfe = VPFEAPPOBJ_DEFAULT;
    gRaster = VPFEAPPRASTERCFG_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare VPFE Capture Display Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get board info */
    status = VpfeAppBoardInfoGet(&gVpfe);

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = VpfeAppSocInfoGet(&gVpfe);
        if (S_PASS == status)
        {
            /* Perform initialization of Interrupt controller*/
            INTCInit(FALSE);

            /* VPFE Interrupt configuration */
            status = VpfeAppInterruptConfig(gVpfe.vpfeSysIntrNum);
            if (S_PASS == status)
            {
                /* Update IP config parameters with device,use case values */
                VpfeAppUpdateIpConfigParams(&gVpfe, &gFrmBuf, &gRaster);

                /* Initialize frame buffer configuration parameters. */
                VpfeAppFrameBufInit();

                /* Camera Sensor Init */
                camInst = gVpfe.vpfeInstNum;
                status = CAMERADeviceInit(camInst, gVpfe.cameraI2cInstNum,
                    gVpfe.vpfeCameraDeviceId, gVpfe.inputFrmWidth,
                    gVpfe.inputFrmHeight, gVpfe.inputPixelFmt);

                if (S_PASS == status)
                {
                    /* VPFE clock/pin mux and IP configuration */
                    status = VPFEAppInit(&gVpfe);
                    if (S_PASS == status)
                    {
                        /* Display Utils initialization */
                        status = DISPLAYUtilsInit();
                        if (S_PASS == status)
                        {
                            /* Display Utils configuration */
                            status = DISPLAYUtilsConfig(gVpfe.outputBufAddr,
                                gVpfe.outputBufSize, gVpfe.inputFrmWidth,
                                gVpfe.inputFrmHeight, gVpfe.inputPixelFmt,
                                VpfeAppdisplayUtilsIsrCb);

                            if (S_PASS == status)
                            {
                                /* Start the LCD display */
                                DISPLAYUtilsStartDisplay();

                                CONSOLEUtilsPrintf
                                    ("\nNow Displaying image on LCD ...\n");

                                while(1)
                                {
                                    /* Input frame data handling */
                                    VpfeAppHandleFrameData();
                                }
                            }
                            else
                            {
                                CONSOLEUtilsPrintf
                                    ("\nDisplay Utils config is failed \n");
                            }
                        }
                        else
                        {
                            CONSOLEUtilsPrintf
                                ("\nDisplay Utils initialization is failed \n");
                        }
                    }
                    else
                    {
                        CONSOLEUtilsPrintf
                            ("\nVPFE IP configuration is failed \n");
                    }
                }
                else
                {
                    CONSOLEUtilsPrintf
                        ("\nCamera Sensor configuration is failed \n");
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

    return (S_PASS);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t VpfeAppBoardInfoGet(vpfeAppObj_t *pObj)
{
    uint32_t *cameraDeviceIdlist;
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t devIndex = 0U;
    uint32_t vpfeInstNum;

    /* Check which Camera device is present on this board */
    cameraDeviceIdlist = CAMERAGetDeviceIdList();

    do {
        if (TRUE == BOARDIsDevicePresent(cameraDeviceIdlist[devIndex]))
        {
            /* Camera device found */
            pObj->vpfeCameraDeviceId = cameraDeviceIdlist[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != cameraDeviceIdlist[devIndex]);

    if (DEVICE_ID_INVALID == cameraDeviceIdlist[devIndex])
    {
        CONSOLEUtilsPrintf("No Camera Sensor device found \n");
    }
    else
    {
        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->vpfeCameraDeviceId,
            VPFE_CAMERA_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Device is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_VPFE == modId)
        {
            vpfeInstNum = BOARDGetDeviceCtrlModInstNum(pObj->vpfeCameraDeviceId,
                VPFE_CAMERA_INST_NUM);

            if (INVALID_INST_NUM == vpfeInstNum)
            {
                CONSOLEUtilsPrintf("Invalid VPFE board data!\n");
            }
            else
            {
                /* Get the i2c instance number to which sensor is connected. */
                pObj->cameraI2cInstNum = BOARDGetDeviceCtrlInfo(
                    pObj->vpfeCameraDeviceId, VPFE_CAMERA_INST_NUM);

                CONSOLEUtilsPrintf
                    ("Device is connected to VPFE on this board!\n");
                pObj->vpfeInstNum = vpfeInstNum;

                CONSOLEUtilsPrintf(
                    "\n device Id = %d  vpfeInst = %d , i2cInst = %d \n",
                    pObj->vpfeCameraDeviceId, pObj->vpfeInstNum,
                    pObj->cameraI2cInstNum);

                status = S_PASS;
            }
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to VPFE!\n");
        }
    }

    return (status);
}


static int32_t VpfeAppSocInfoGet(vpfeAppObj_t *pObj)
{
    int32_t status = E_FAIL;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_VPFE, pObj->vpfeInstNum))
    {
        pObj->vpfeInstAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_VPFE, pObj->vpfeInstNum);

        if (SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            /*TODO: This interrupt number has to be provided by soc info */
            if (0U == pObj->vpfeInstNum)
            {
                /* System interrupt number for VPFE instance 0 */
                pObj->vpfeSysIntrNum = 80U;  /* 48 + 32 */
            }
            if (1U == pObj->vpfeInstNum)
            {
                /* System interrupt number for VPFE instance 1 */
                pObj->vpfeSysIntrNum = 82U;  /* 50 + 32 */
            }
            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf
                ("\n This application is not supported on this SOC \n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("VPFE IP is not present on this SOC!\n");
    }

    return status;
}


static void VpfeAppUpdateIpConfigParams(vpfeAppObj_t *pVpfe,
                                        vpfeAppFrmBufCfg_t *pFrm,
                                        vpfeAppRasterCfg_t *pRaster)
{
    vpfeInputCfg_t *pInput = &pVpfe->vpfeCfg.ioCfg.inputCfg;
    vpfeOutputFrameResCfg_t *pFrmCfg = &pVpfe->vpfeCfg.ioCfg.outputCfg.frmCfg;
    vpfeLineOffsetCfg_t *pLnOfstCfg =
        &pVpfe->vpfeCfg.ioCfg.outputCfg.lnOffsetCfg;
    vpfeHvSyncCfg_t *syncCfg = &pVpfe->vpfeCfg.ioCfg.inputCfg.syncCfg;

    /* Update use case values in the IP configuration structure. */
    pVpfe->inputFrmWidth    = pRaster->inputFrmWidth;
    pVpfe->inputFrmHeight   = pRaster->inputFrmHeight;
    pVpfe->inputPixelFmt = pRaster->inputFrmPixelFmt;

    /* Configure default values. */
    pInput->inputMode = VPFE_INPUT_MODE_RAW;
    pInput->inputDataWidth = VPFE_IN_WIDTH_8_BITS;
    pInput->fieldMode = VPFE_FIELD_MODE_NON_INTERLACED;

    pFrmCfg->sph  = 0U;
    pFrmCfg->nph  = IMAGE_X_SIZE * 2U;
    pFrmCfg->slv0 = 0U;
    pFrmCfg->slv1 = 0U;
    pFrmCfg->nlv  = IMAGE_Y_SIZE;

    pLnOfstCfg->lnOffset = LINE_OFFSET;

    syncCfg->hSyncPolarity = VPFE_H_SYNC_POLARITY_POSITIVE;
    syncCfg->vSyncPolarity = VPFE_V_SYNC_POLARITY_POSITIVE;
    syncCfg->hvSyncDirection = VPFE_VDHD_DIR_INPUT;
}


static int32_t VpfeAppInterruptConfig(uint32_t intrNum)
{
    int32_t status = S_PASS;

    intcIntrParams_t vpfeIntrParams;

    vpfeIntrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
    vpfeIntrParams.priority       = 0x00;
    vpfeIntrParams.pFnIntrHandler = &VpfeAppIsr;
    vpfeIntrParams.isIntrSecure   = FALSE;
    vpfeIntrParams.pUserParam     = &gVpfe;

    /* Configure the interrupt controller */
    status = INTCConfigIntr(intrNum, &vpfeIntrParams, FALSE);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf(" Interrupt controller configuration failed \n ");
    }

    return status;
}



void VpfeAppFrameBufInit(void)
{
    vpfeAppFrmBufCfg_t *pFrmBuf = &gFrmBuf;

    /* Input Buffer pointer initialization */
    pFrmBuf->inputBufIdx = 0U;
    pFrmBuf->inputBufPtr[0U] = (uint32_t)&camBuffer[0U];
    pFrmBuf->inputBufPtr[1U] = (uint32_t)&camBuffer1[0U];

    /* Initialize input current and next frames */
    pFrmBuf->currInputBuf = (uint32_t)&camBuffer[0U];
    pFrmBuf->nextInputBuf = (uint32_t)&camBuffer[0U];

    /* Output Buffer pointer initialization */
    pFrmBuf->outputBufIdx = 0U;
    pFrmBuf->outputBufPtr[0U] = (uint32_t)&frameBufferYuv[0U][0U];
    pFrmBuf->outputBufPtr[1U] = (uint32_t)&frameBufferYuv1[0U][0U];
    pFrmBuf->outputReadyBufAddr = (uint32_t)&frameBufferYuv[0U][0U];

    /* ISR call back function pointer and input buffer initialization */
    gVpfe.pFnIsrCb = &VpfeAppIsrCb;
    gVpfe.inputBufAddr = (uint32_t)&camBuffer[0U];
    gVpfe.outputBufAddr = (uint32_t)&frameBufferYuv[0U][0U];
    gVpfe.outputBufSize = sizeof(frameBufferYuv);
}



void VpfeAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    vpfeAppObj_t *pObj = pUserParam;
    uint32_t vpfeBaseAddr = pObj->vpfeInstAddr;
    uint32_t intrStatus = 0U;
    vpfeAppFrmBufCfg_t *pFrmBuf = &gFrmBuf;

    intrStatus = VPFEIntrStatus(vpfeBaseAddr);

    if (intrStatus & VPFE_INTR_MASK_VD0)
    {
        if (pFrmBuf->currInputBuf != pFrmBuf->nextInputBuf)
        {
            pFrmBuf->inputBufReady = TRUE;
            pFrmBuf->inputReadyBufAddr = pFrmBuf->currInputBuf;
            pFrmBuf->currInputBuf = pFrmBuf->nextInputBuf;
        }

        VPFEIntrClear(vpfeBaseAddr, VPFE_INTR_MASK_VD0);
    }

    if (intrStatus & VPFE_INTR_MASK_VD1)
    {
        if (pFrmBuf->currInputBuf == pFrmBuf->nextInputBuf)
        {
            if(pObj->pFnIsrCb != NULL)
            {
                pFrmBuf->nextInputBuf = pObj->pFnIsrCb(pFrmBuf->currInputBuf);
                VPFESetBufAddr(vpfeBaseAddr, pFrmBuf->nextInputBuf);
            }
        }

        VPFEIntrClear(vpfeBaseAddr, VPFE_INTR_MASK_VD1);
    }

    VPFEIntrSetEoi(vpfeBaseAddr);
}

/* -------------------------------------------------------------------------- */
/*              Use-case specific Internal Function Definitions               */
/* -------------------------------------------------------------------------- */

void VpfeAppHandleFrameData(void)
{
    vpfeAppFrmBufCfg_t *pFrmBuf = &gFrmBuf;
    uint32_t *ptr;
    uint32_t *ptr1;
    uint32_t *pOut;
    uint32_t idx, idx1, val, y0, y1, cb, cr;

    if (TRUE == pFrmBuf->inputBufReady)
    {
        /* Get input buffer address */
        ptr  =  (uint32_t *)pFrmBuf->inputReadyBufAddr;
        ptr1 = ptr;

        pOut = (uint32_t *)pFrmBuf->outputBufPtr[pFrmBuf->outputBufIdx];

        /* Avoid over writing the output buffer */
        if (pOut != (uint32_t *)pFrmBuf->outputReadyBufAddr)
        {
            for(idx1 = 0U; idx1 < (IMAGE_Y_SIZE); idx1++)
            {
                ptr = (uint32_t *)(ptr1 + ((LINE_OFFSET * idx1) / 4U));
                for(idx = 0U; idx < (IMAGE_X_SIZE / 2U); idx++)
                {
                    val = *ptr++;
                    y0  = (val) & 0xffU;
                    cb  = (val >> VPFE_APP_DATA_SHIFT_16) & 0xffU;

                    val = *ptr++;
                    y1  = (val) & 0xffU;
                    cr  = (val >> VPFE_APP_DATA_SHIFT_16) & 0xffU;

                    *(pOut + idx1 * (IMAGE_X_SIZE / 2U)+ idx) =
                        (cr << VPFE_APP_DATA_SHIFT_24) |
                        (y1 << VPFE_APP_DATA_SHIFT_16) |
                        (cb << VPFE_APP_DATA_SHIFT_8) |
                        (y0 << VPFE_APP_DATA_SHIFT_0);
                }
            }
        }

        CACHEDataCleanInvAll();

        /* Input is copied to output. Clear the input ready flag */
        pFrmBuf->inputBufReady = FALSE;

        /* Output is copied ot buffer and is ready for display */
        pFrmBuf->outputReadyBufAddr =
            pFrmBuf->outputBufPtr[pFrmBuf->outputBufIdx];

        /* Update output buffer pointer for next copy. */
        pFrmBuf->outputBufIdx++;
        if(pFrmBuf->outputBufIdx == VPFE_APP_NUM_OUT_BUFS)
        {
            pFrmBuf->outputBufIdx = 0U;
        }
    }
}


uint32_t VpfeAppIsrCb(uint32_t currBufAddr)
{
    vpfeAppFrmBufCfg_t *pFrmBuf = &gFrmBuf;

    pFrmBuf->inputBufIdx++;
    if (pFrmBuf->inputBufIdx == VPFE_APP_NUM_IN_BUFS)
    {
        pFrmBuf->inputBufIdx = 0U;
    }

    return pFrmBuf->inputBufPtr[pFrmBuf->inputBufIdx];
}


uint32_t VpfeAppdisplayUtilsIsrCb(uint32_t currBufAddr)
{
    uint32_t nextBufAddr;

    if (currBufAddr != gFrmBuf.outputReadyBufAddr)
    {
        nextBufAddr = gFrmBuf.outputReadyBufAddr;
    }
    else
    {
        nextBufAddr = currBufAddr;
    }

    return nextBufAddr;
}
