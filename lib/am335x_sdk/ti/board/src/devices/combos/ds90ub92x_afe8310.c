/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
 *
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
 *****************************************************************************/

/**
 *   \file    ds90ub92x_afe8310.c
 *
 *   \brief   This file contains the default API's for initializing the
 *            FPD module for the communicating with the remote slave device.
 *
 */

#include "ds90ub92x_afe8310.h"

/**
 * \brief      Board_ub92xTunerCfg
 *
 * This function is used to configure the fpd module
 * to enable the tuner path.
 *
 * \param   handle          [IN] pointer to the i2c handle
 * \param   fpdModuleParams [IN] structure holding the device params.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */

Board_STATUS Board_ub92xTunerCfg(void *handle,
                                 Board_FpdModuleObj *fpdModuleParams)
{
    Board_STATUS ret;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    BOARD_DEVICES_STS_LOG("Setting Deserializer configuration\n");

    BOARD_DEVICES_STS_LOG("Disabling auto load from forward channel\n");
    ret = Board_fpdUb926SetI2SChBOverrideModeCtrl(handle,
                                                  fpdModuleParams,
                                                  BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Disabling auto load from forward channel failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Enabling Pass RGB independent of DE\n");
    ret = Board_fpdUb926SetPassRGBModeCtrl(handle,
                                           fpdModuleParams,
                                           BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Enabling Pass RGB independent of DE failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);
    
    BOARD_DEVICES_STS_LOG("Enabling not to sent packetized audio on RGB\n");
    ret = Board_fpdUb926SetI2SGenModeCtrl(handle,
                                          fpdModuleParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Enabling not to sent packetized audio on RGB failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Setting I2S forward channel frame transport mode\n");
    ret = Board_fpdUb926SetI2STransportSelModeCtrl(handle,
                                                   fpdModuleParams,
                                                   BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting I2S forward channel frame transport mode failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Enabling RGB 18-bit mode\n");
    ret = Board_fpdUb926SetRGB18bitModeCtrl(handle,
                                            fpdModuleParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting RGB 18-bit mode failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Setting Serializer configuration\n");

    BOARD_DEVICES_STS_LOG("Disabling Gate RGB dependent of DE\n");
    ret = Board_fpdUb925SetRGBGateDEModeCtrl(handle,
                                             fpdModuleParams,
                                             BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Disabling Gate RGB independent of DE failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Setting I2S forward channel frame transport mode\n");
    ret = Board_fpdUb925SetI2STransSelModeCtrl(handle,
                                               fpdModuleParams,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting I2S forward channel frame transport mode failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Enabling RGB 18-bit mode\n");
    ret = Board_fpdUb925SetRGB18bitModeCtrl(handle,
                                            fpdModuleParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting RGB 18-bit mode failed\n");
        ret = -1;
        return ret;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    return ret;
}

/**
 * \brief      Board_ub926DesInit
 *
 * This function is used to initialize the deserializer
 * connected to host controller.
 *
 * \param   handle          [IN] pointer to the i2c handle
 * \param   fpdModuleParams [IN] structure holding the device params.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */

Board_STATUS Board_ub926DesInit(void *handle,
                                Board_FpdModuleObj *fpdModuleParams)
{
    int8_t boardStatus;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    BOARD_DEVICES_STS_LOG("Disabling the Deserializer Auto power down mode...\n\r");
    boardStatus = Board_fpdUb926SetRmtAutoPwrDwnModeCtrl(handle,
                                                         fpdModuleParams,
                                                         BOARD_FPD_MODE_DISABLE);
    if(boardStatus != 0)
    {
        BOARD_DEVICES_ERR_LOG("Disabling the Deserializer Auto power down mode failed\n\r");
        return boardStatus;
    }

    BOARD_DEVICES_STS_LOG("Resetting the Deserializer...\n\r");
    boardStatus = Board_fpdUb926SetDigitalRst1ModeCtrl(handle,
                                                       fpdModuleParams,
                                                       BOARD_FPD_MODE_RESET);
    if(boardStatus != 0)
    {
        BOARD_DEVICES_ERR_LOG("Resetting the Deserializer failed\n\r");
        return boardStatus;
    }

    BOARD_DEVICES_STS_LOG("Disabling the BC Enable...\n\r");
    boardStatus = Board_fpdUb926SetBackChModeCtrl(handle,
                                                  fpdModuleParams,
                                                  BOARD_FPD_MODE_ENABLE);
    if(boardStatus != 0)
    {
        BOARD_DEVICES_ERR_LOG("Disabling the BC Enable failed\n\r");
        return boardStatus;
    }

    BOARD_DEVICES_STS_LOG("Setting the Deserailizer bus frequency to 400kbits/sec...\n\r");
    boardStatus = Board_fpdUb926SetI2CBusFreq(handle,
                                              fpdModuleParams,
                                              BOARD_FPD_KBPS_400);
    if(boardStatus != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting the Deserailizer bus frequency to 400kbits/sec failed\n\r");
        return boardStatus;
    }

    return 0;
}

/**
 * \brief      Board_fpdUb926RmtSlvDevAccEn
 *
 * This function is used to initialize the fpd ub926
 * module to enable the access to the remote slave.
 *
 * \param   handle          [IN] pointer to the i2c handle
 * \param   rmtSlvParams    [IN] structure holding the fpd params
 * \param   fpdModuleParams [IN] structure holding the device params.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */

Board_STATUS Board_fpdUb926RmtSlvDevAccEn(void *handle,
                                          Board_FpdRmtDevObj *fpdRmtDevParams,
                                          Board_FpdModuleObj *fpdModuleParams)
{
    int8_t ret;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    BOARD_DEVICES_STS_LOG("Enabling the I2C Pass-Through Mode...\n");
    ret = Board_fpdUb926SetI2CPassThrModeCtrl(handle,
	                                          fpdModuleParams,
                                              BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Enabling the I2C Pass-Through Mode failed\n");
        return -1;
    }
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Enabling the I2C Pass-Through All Transactions...\n");
    ret = Board_fpdUb926SetI2CPassThrAllModeCtrl(handle,
	                                             fpdModuleParams,
                                                 BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Enabling the I2C Pass-Through All Transactions failed\n");
        return -1;
    } 
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Setting the remote slave Alias addresses...\n");
    ret = Board_fpdUb926RmtSerSlvDevAliasIdCfg(handle,
                                               fpdModuleParams,
                                               fpdRmtDevParams);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Setting the remote slave Alias address failed\n");
        return -1;
    } 
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);

    BOARD_DEVICES_STS_LOG("Disabling the I2C Pass-Through All Transactions...\n");
    ret = Board_fpdUb926SetI2CPassThrAllModeCtrl(handle,
                                                 fpdModuleParams,
                                                 BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Disabling the I2C Pass-Through All Transactions failed\n");
        return -1;
    } 
    Board_delay(BOARD_FPD_I2C_CFG_DELAY);
    
    return 0;
}

