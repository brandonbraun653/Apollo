/**
 * \file   camera_device.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         camera sensors and global structure containing the camera sensor
 *         parameters.
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
#include "device.h"
#include "camera_device.h"

#include "console_utils.h"
#include "i2c_utils.h"
#include "i2c.h"
#include "display_utils.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Macro indicating the i2c time out value. */
#define BOARD_I2C_TIMEOUT_VAL           (1000000U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API reads the value from the specified camera sensor register.
 *          The read will be done using I2C interface.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 * \param   addr        Camera sensor register address from which data has to
 *                      be read.
 *
 * \retval  S_PASS      Camera read is successful.
 * \retval  E_FAIL      Camera read is failed.
 */
uint32_t CAMERARead(uint32_t cameraInst, uint32_t i2cInstNum, uint16_t addr);

/**
 * \brief   This API writes value to the specified camera sensor register.
 *          The write will be done using I2C interface.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 * \param   addr        Camera sensor register address to which data has to
 *                      be written.
 * \param   data        configuration data that has to be written.
 *
 * \retval  S_PASS      Camera write is successful.
 * \retval  E_FAIL      Camera write is failed.
 */
void CAMERAWrite(uint32_t cameraInst,
                 uint32_t i2cInstNum,
                 uint16_t addr,
                 uint8_t data);

/**
 * \brief   This API configures the frame size and timing parameters of the
 *          camera sensor to generated required output frame size.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 * \param   frmWidth    Input image frame width in number of pixels per line.
 * \param   frmHeight   Input image height in number of liner per panel.
 */
static void Camera0v2569FrameConfig(uint32_t cameraInst,
                                    uint32_t i2cInstNum,
                                    uint32_t frmWidth,
                                    uint32_t frmHeight);

/**
 * \brief   This API configures the frame size and timing parameters of the
 *          camera sensor to generated required output frame size.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 * \param   frmFormat   Input pixel format.
 */
static void CameraOv2659FrmFmtConfig(uint32_t cameraInst,
                                     uint32_t i2cInstNum,
                                     uint32_t frmFormat);

/**
 * \brief   This API configures the frame size and timing parameters of the
 *          camera sensor to generated required output frame size.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659GammaCorrectionConfig(uint32_t camInst,
                                              uint32_t i2cInstNum);

/**
 * \brief   This API configures the Lens correction parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659LensCorrectionConfig(uint32_t camInst,
                                             uint32_t i2cInstNum);

/**
 * \brief   This API configures the color matrix conversion configurations.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659CmcConfig(uint32_t camInst, uint32_t i2cInstNum);

/**
 * \brief   This API configures color interpolation(cip), dns and shapen control
 *          parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659CipDnsSharpenConfig(uint32_t camInst,
                                            uint32_t i2cInstNum);

/**
 * \brief   This API configures the special digital effects parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659SdeConfig(uint32_t camInst, uint32_t i2cInstNum);

/**
 * \brief   This API configures the automatic exposure control parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659AecConfig(uint32_t camInst, uint32_t i2cInstNum);

/**
 * \brief   This API configures Y component averaging parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659YAvgConfig(uint32_t camInst, uint32_t i2cInstNum);

/**
 * \brief   This API configures Auto White balance parameters.
 *
 * \param   cameraInst  Instance of the camera used.
 * \param   i2cInstNum  I2C instance number to which sensor control interface is
 *                      connected.
 */
static void CameraOv2659AwbConfig(uint32_t camInst, uint32_t i2cInstNum);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Structure holding the supported CAMERA sensor device ids. */
uint32_t gCameraDeviceIdList[] =
{
    DEVICE_ID_CAMERA_OV2659,
    /**< Camera sensor device. */
    DEVICE_ID_INVALID
    /**< Invalid device ID. */
};

/** \brief Structure holding the parameters of different Camera sensors. */
cameraDeviceData_t gCameraDeviceData[] =
{
    {
        /* Data for CAMERA Sensor OV2659 */
        DEVICE_ID_CAMERA_OV2659,  /* devId */
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

cameraDeviceData_t *CAMERAGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gCameraDeviceData) / sizeof(cameraDeviceData_t);
    uint32_t devIndex = 0U;
    cameraDeviceData_t *cameraDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gCameraDeviceData[devIndex].devId)
        {
            /* Device Found */
            cameraDeviceData = &gCameraDeviceData[devIndex];
            break;
        }
    }
    return cameraDeviceData;
}


uint32_t * CAMERAGetDeviceIdList(void)
{
    return gCameraDeviceIdList;
}


int32_t CAMERADeviceInit(uint32_t camInst,
                         uint32_t i2cInstNum,
                         uint32_t devId,
                         uint32_t frmWidth,
                         uint32_t frmHeight,
                         uint32_t frmFormat)
{
    uint32_t status = E_FAIL;
    uint32_t dataHigh = 0U;
    uint32_t dataLow = 0U;
    uint32_t data;
    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;

    status = I2CUtilsInit(i2cInstNum, &i2cUtilsParams);

    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n I2C Utils initialization failed. \n");
    }

    switch (devId)
    {
        case DEVICE_ID_CAMERA_OV2659:
        {
            dataHigh = CAMERARead(camInst, i2cInstNum, OV2659_SC_CHIP_ID_H);
            dataLow  = CAMERARead(camInst, i2cInstNum, OV2659_SC_CHIP_ID_L);

            data = (dataHigh << 8U) | (dataLow << 0U);
            if (0x2656 == data)
            {
                CONSOLEUtilsPrintf("\n Sensor is read . \n");
            }
            else
            {
                CONSOLEUtilsPrintf("\n Sensor is not correct. \n");
            }

            /* Software reset */
            CAMERAWrite(camInst, i2cInstNum, OV2659_SOFTWARE_RESET, 0x01);

            /* IO control configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_IO_CTRL00, 0x03);
            CAMERAWrite(camInst, i2cInstNum, OV2659_IO_CTRL01, 0xff);
            CAMERAWrite(camInst, i2cInstNum, OV2659_IO_CTRL02, 0xe0);
            CAMERAWrite(camInst, i2cInstNum, 0x3633, 0x3d);
            CAMERAWrite(camInst, i2cInstNum, 0x3620, 0x02);
            CAMERAWrite(camInst, i2cInstNum, 0x3631, 0x11);
            CAMERAWrite(camInst, i2cInstNum, 0x3612, 0x04);
            CAMERAWrite(camInst, i2cInstNum, 0x3630, 0x20);
            CAMERAWrite(camInst, i2cInstNum, 0x4702, 0x02);
            CAMERAWrite(camInst, i2cInstNum, 0x370c, 0x34);

            /* PLL configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_SC_PLL_CTRL1, 0x10);
            /* pixel clock = 34*input clock/12 (ePOS ~= 70.83MHz; GP ~= 34MHz)*/
            CAMERAWrite(camInst, i2cInstNum, OV2659_SC_PLL_CTRL2, 0x22);

            /* Frame configuration */
            Camera0v2569FrameConfig(camInst, i2cInstNum, frmWidth, frmHeight);

            /* Auto exposure control and Auto Gain control configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x02), 0x02);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x03), 0x68);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x08), 0x00);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x09), 0x5c);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x0a), 0x00);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x0b), 0x4d);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x0d), 0x08);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x0e), 0x06);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x14), 0x02);
            CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x15), 0x28);


            /* Digital video port (DVP) configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_DVP_CTRL02, 0x01);


            CAMERAWrite(camInst, i2cInstNum, 0x3623, 0x00);
            CAMERAWrite(camInst, i2cInstNum, 0x3634, 0x76);
            CAMERAWrite(camInst, i2cInstNum, 0x3701, 0x44);
            CAMERAWrite(camInst, i2cInstNum, 0x3702, 0x18);
            CAMERAWrite(camInst, i2cInstNum, 0x3703, 0x24);
            CAMERAWrite(camInst, i2cInstNum, 0x3704, 0x24);
            CAMERAWrite(camInst, i2cInstNum, 0x3705, 0x0c);


            CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VERT_FORMAT, 0x81);
            CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HORIZ_FORMAT, 0x01);
            CAMERAWrite(camInst, i2cInstNum, 0x370a, 0x52);

            /* Video fifo control configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_VFIFO_READ_START_H, 0x00);
            CAMERAWrite(camInst, i2cInstNum, OV2659_VFIFO_READ_START_L, 0x80);

            /* Frame format configuration */
            CameraOv2659FrmFmtConfig(camInst, i2cInstNum, frmFormat);

            CAMERAWrite(camInst, i2cInstNum, 0x5086, 0x02);

            /* Image Sensor Processor configurations */
            CAMERAWrite(camInst, i2cInstNum, OV2659_ISP_CTRL00, 0xfb);
            CAMERAWrite(camInst, i2cInstNum, OV2659_ISP_CTRL01, 0x1f);
            CAMERAWrite(camInst, i2cInstNum, OV2659_ISP_CTRL02, 0x00);

            /* Gamma curve correction configurations */
            CameraOv2659GammaCorrectionConfig(camInst, i2cInstNum);

            /* Color matrix conversion(CMC) configurations */
            CameraOv2659CmcConfig(camInst, i2cInstNum);

            /* Auto White balance control configurations */
            CameraOv2659AwbConfig(camInst, i2cInstNum);

            /* Lens Correction (LENC) configuration */
            CameraOv2659LensCorrectionConfig(camInst, i2cInstNum);

            /* Color Interpolation(CIP)/DNS()/Sharpen control configurations */
            CameraOv2659CipDnsSharpenConfig(camInst, i2cInstNum);

            /* SDE(Special Digital Effects) configurations */
            CameraOv2659SdeConfig(camInst, i2cInstNum);

            /* AEC Control configurations */
            CameraOv2659AecConfig(camInst, i2cInstNum);

            /* Y Average control */
            CameraOv2659YAvgConfig(camInst, i2cInstNum);

            /* To enable Test Pattern color bar use config value of 0x80 */
            /* CAMERAWrite(camInst, i2cInstNum, OV2659_ISP_PRE_CTRL00, 0x80); */
            CAMERAWrite(camInst, i2cInstNum, OV2659_ISP_PRE_CTRL00, 0x00);

            CAMERAWrite(camInst, i2cInstNum, OV2659_SOFTWARE_STANDBY, 0x01);
        }
        break;

        default:
        break;

    }

    return status;
}

uint32_t CAMERARead(uint32_t cameraInst, uint32_t i2cInstNum, uint16_t addr)
{
    uint8_t tmp_addr[2U];
    uint32_t rxData = 0U;
    i2cUtilsTxRxParams_t i2cTxRxParams;
    int32_t status;

    /* set address(msb then lsb) */
    tmp_addr[0U] = (addr >> 8U) & 0xffU;
    tmp_addr[1U] = (addr >> 0U) & 0xffU;

    i2cTxRxParams.slaveAddr  = OV2659_CAMERA_SLAVE_ADDR;
    i2cTxRxParams.pOffset    = &tmp_addr[0U];
    i2cTxRxParams.offsetSize = 2U;
    i2cTxRxParams.bufLen = 1U;
    i2cTxRxParams.pBuffer = (uint8_t *) &rxData;

    status = I2CUtilsRead(i2cInstNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n I2C Read failed. \n = %d", status);
    }

    return rxData;
}


void CAMERAWrite(uint32_t cameraInst,
                 uint32_t i2cInstNum,
                 uint16_t addr,
                 uint8_t data)
{
    uint8_t tmp_data[3U];
    int32_t status;
    i2cUtilsTxRxParams_t i2cTxRxParams;

    /* set address(msb then lsb) */
    tmp_data[0U] = (addr >> 8U) & 0xffU;
    tmp_data[1U] = (addr >> 0U) & 0xffU;
    tmp_data[2U] = (uint8_t)data;

    i2cTxRxParams.slaveAddr  = OV2659_CAMERA_SLAVE_ADDR;
    i2cTxRxParams.pOffset    = &tmp_data[0U];
    i2cTxRxParams.offsetSize = 2U;
    i2cTxRxParams.bufLen     = 1U;
    i2cTxRxParams.pBuffer    = (uint8_t *)&tmp_data[2];

    status = I2CUtilsWrite(i2cInstNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n I2C Write failed. \n = %d", status);
    }
}


/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static void Camera0v2569FrameConfig(uint32_t camInst,
                                    uint32_t i2cInstNum,
                                    uint32_t frmWidth,
                                    uint32_t frmHeight)
{
    uint32_t val = 0U;

    /* Horizontal and vertical timing configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HS_H, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HS_L, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VS_H, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VS_L, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HW_H, 0x06);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HW_L, 0x5f);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VH_H, 0x04);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VH_L, 0xb7);

    /* horizontal output */
    val = (frmWidth >> 8U) & 0xffU;
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_DVPHO_H, val);
    val = (frmWidth >> 0U) & 0xffU;
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_DVPHO_L, val);

    /* vertical output */
    val = (frmHeight >> 8U) & 0xffU;
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_DVPVO_H, val);
    val = (frmHeight >> 0U) & 0xff;
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_DVPVO_L, val);

    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HTS_H, 0x05);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HTS_L, 0x14);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VTS_H, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VTS_L, 0x68);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_HOFFS_L, 0x08);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_VOFFS_L, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_XINC, 0x31);
    CAMERAWrite(camInst, i2cInstNum, OV2659_TIMING_YINC, 0x31);
}

static void CameraOv2659FrmFmtConfig(uint32_t camInst,
                                     uint32_t i2cInstNum,
                                     uint32_t frmFormat)
{
    uint32_t val = 0x00;

    if(DISPLAY_UTILS_PIXEL_FMT_YUV2 == frmFormat)
    {
        val = 0x30;
    }
    CAMERAWrite(camInst, i2cInstNum, OV2659_FORMAT_CTRL00, val);
}

static void CameraOv2659GammaCorrectionConfig(uint32_t camInst,
                                              uint32_t i2cInstNum)
{
    /* Gamma curve control configuration */
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(1), 0x0e);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(2), 0x18);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(3), 0x34);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(4), 0x4c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(5), 0x62);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(6), 0x74);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(7), 0x85);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(8), 0x92);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(9), 0x9e);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(10), 0xb2);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(11), 0xc0);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(12), 0xcc);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(13), 0xe0);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(14), 0xee);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YST(15), 0xf6);
    CAMERAWrite(camInst, i2cInstNum, OV2659_GAMMA_YSLP, 0x11);
}

static void CameraOv2659LensCorrectionConfig(uint32_t camInst,
                                             uint32_t i2cInstNum)
{
    /* LENC(Lens Correction) configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_X0_H, 0x03);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_X0_L, 0x20);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_Y0_H, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_Y0_L, 0x5c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_A1, 0x48);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_B1, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_RED_A2_B2, 0x66);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_X0_H, 0x03);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_X0_L, 0x30);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_Y0_H, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_Y0_L, 0x7c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_A1, 0x40);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_B1, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_GREEN_A2_B2, 0x66);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_X0_H, 0x03);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_X0_L, 0x10);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_Y0_H, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_Y0_L, 0x7c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_A1, 0x3a);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_B1, 0x00);
    CAMERAWrite(camInst, i2cInstNum, OV2659_LENC_BLUE_A2_B2, 0x66);
}

static void CameraOv2659CmcConfig(uint32_t camInst, uint32_t i2cInstNum)
{
    /* Color matrix conversion configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(1), 0x1c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(2), 0x5b);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(3), 0x05);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(4), 0x20);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(5), 0x94);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(6), 0xb4);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(7), 0xb4);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(8), 0xaf);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX(9), 0x05);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX_SIGN, 0x98);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX_MISC_CTRL, 0x21);
}

static void CameraOv2659AwbConfig(uint32_t camInst, uint32_t i2cInstNum)
{
    /* Auto White balance control configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL00, 0x6a);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL01, 0x11);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL02, 0x92);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL03, 0x21);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL04, 0xe1);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_LOCAL_LIMIT, 0x01);
    CAMERAWrite(camInst, i2cInstNum, 0x503c, 0x05);
    CAMERAWrite(camInst, i2cInstNum, 0x503d, 0x08);
    CAMERAWrite(camInst, i2cInstNum, 0x503e, 0x08);
    CAMERAWrite(camInst, i2cInstNum, 0x503f, 0x64);
    CAMERAWrite(camInst, i2cInstNum, 0x5040, 0x58);
    CAMERAWrite(camInst, i2cInstNum, 0x5041, 0x2a);
    CAMERAWrite(camInst, i2cInstNum, 0x5042, 0xc5);
    CAMERAWrite(camInst, i2cInstNum, 0x5043, 0x2e);
    CAMERAWrite(camInst, i2cInstNum, 0x5044, 0x3a);
    CAMERAWrite(camInst, i2cInstNum, 0x5045, 0x3c);
    CAMERAWrite(camInst, i2cInstNum, 0x5046, 0x44);
    CAMERAWrite(camInst, i2cInstNum, 0x5047, 0xf8);
    CAMERAWrite(camInst, i2cInstNum, 0x5048, 0x08);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL12, 0x70);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL13, 0xf0);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AWB_CTRL14, 0xf0);
}

static void CameraOv2659CipDnsSharpenConfig(uint32_t camInst,
                                            uint32_t i2cInstNum)
{
    /* Color Interpolation(CIP)/DNS()/Sharpen control configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_CIP_CTRL00, 0x44);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPENMT_THRESH1, 0x08);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPENMT_THRESH2, 0x10);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPENMT_OFFSET1, 0x12);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPENMT_OFFSET2, 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPEN_THRESH1, 0x08);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SHARPEN_THRESH2, 0x10);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CIP_CTRL01, 0xa6);
    CAMERAWrite(camInst, i2cInstNum, OV2659_DENOISE_THRESH1, 0x08);
    CAMERAWrite(camInst, i2cInstNum, OV2659_DENOISE_THRESH2, 0x10);
    CAMERAWrite(camInst, i2cInstNum, OV2659_DENOISE_OFFSET1, 0x04);
    CAMERAWrite(camInst, i2cInstNum, OV2659_DENOISE_OFFSET2, 0x12);
}

static void CameraOv2659SdeConfig(uint32_t camInst, uint32_t i2cInstNum)
{
    /* SDE(Special Digital Effects) configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_SDE_CTRL(0x3), 0x40);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SDE_CTRL(0x4), 0x20);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SDE_CTRL(0x0), 0x02);
    CAMERAWrite(camInst, i2cInstNum, OV2659_CMX_MISC_CTRL, 0x01);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SDE_CTRL(0x9), 0x0c);
    CAMERAWrite(camInst, i2cInstNum, OV2659_SDE_CTRL(0xA), 0x3e);
    CAMERAWrite(camInst, i2cInstNum, 0x5005, 0x80);
}

static void CameraOv2659AecConfig(uint32_t camInst, uint32_t i2cInstNum)
{
    /* AEC Control configurations */
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x0f), 0x30);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x10), 0x28);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x1b), 0x32);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x1e), 0x26);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x11), 0x60);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AEC_CTRL(0x1f), 0x14);
}

static void CameraOv2659YAvgConfig(uint32_t camInst, uint32_t i2cInstNum)
{
    /* Y Average control */
    CAMERAWrite(camInst, i2cInstNum, OV2659_AVG_CTRL(0), 0x69);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AVG_CTRL(1), 0x7d);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AVG_CTRL(2), 0x7d);
    CAMERAWrite(camInst, i2cInstNum, OV2659_AVG_CTRL(3), 0x69);
}