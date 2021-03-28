/*
* Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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
*/

/**
 * \file  pcm3168A.c
 *
 * \brief APIs to configure the pcm3168A codec.
 *
 */

#include "pcm3168A.h"
#include <ti/board/src/devices/common/common.h>

/** PCM codec default configurations */
uint8_t pcmConfigs[31][2] =
{
	{ BOARD_PCM3168_MODECTRL_REG_ADDR,               0xC0 },
	{ BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,        0x00 },
	{ BOARD_PCM3168_DAC_OP_FLT_REG_ADDR,             0x00 },
	{ BOARD_PCM3168_DAC_INV_REG_ADDR,                0x00 },
	{ BOARD_PCM3168_DAC_MUTE_REG_ADDR,               0x00 },
	{ BOARD_PCM3168_DAC_ZERO_REG_ADDR,               0x00 },
	{ BOARD_PCM3168_DAC_ATT_DEMP_ZF_REG_ADDR,        0x10 },
	{ BOARD_PCM3168_DAC_VOL_MASTER_REG_ADDR,         0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR,     0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 1, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 2, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 3, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 4, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 5, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 6, 0xff },
	{ BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR + 7, 0xff },
	{ BOARD_PCM3168_ADC_SMODE_REG_ADDR,              0x00 },
	{ BOARD_PCM3168_ADC_MST_FMT_REG_ADDR,            0x00 },
	{ BOARD_PCM3168_ADC_PWR_HPFB_REG_ADDR,           0x00 },
	{ BOARD_PCM3168_ADC_SEAD_REG_ADDR,               0x00 },
	{ BOARD_PCM3168_ADC_INV_REG_ADDR,                0x00 },
	{ BOARD_PCM3168_ADC_MUTE_REG_ADDR,               0x00 },
	{ BOARD_PCM3168_ADC_OV_REG_ADDR,                 0x00 },
	{ BOARD_PCM3168_ADC_ATT_OVF_REG_ADDR,            0x00 },
	{ BOARD_PCM3168_ADC_VOL_MASTER_REG_ADDR,         0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR,     0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR + 1, 0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR + 2, 0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR + 3, 0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR + 4, 0xd7 },
	{ BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR + 5, 0xd7 }
};

/**
 * \brief   This function is used to configure the PCM3168A codec.
 *
 * All the registers of PCM code shall be configured to default
 * value by this function.
 *
 * \param   handle       [IN] I2C driver handle
 * \param	slaveAddr    [IN] Codec slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168Config(void *handle, uint8_t slaveAddr)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regCount = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    for(regCount=0; regCount<31; regCount++)
    {
        boardStatus = Board_pcm3168RegWrite(handle,
                                            slaveAddr,
                                            pcmConfigs[regCount][0],
                                            &(pcmConfigs[regCount][1]));
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }
    return boardStatus;
}

/**
 * \brief	This function is used to control the DAC sampling mode
 *				00 - Auto
 *				01 - Single rate
 *				10 - Dual rate
 *				11 - Quad rate
 *
 * \n       Reset Control register     - 0x40
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   samplingMode  [IN] Sampling mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
static Board_STATUS Board_pcm3168DACSamplingModeSel(void *handle,
                                                    uint8_t slaveAddr,
                                                    uint8_t samplingMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(samplingMode > BOARD_PCM3168_QUAD_RATE)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_MODECTRL_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_SRDA_BIT_MASK);
    regData |= (samplingMode << BOARD_PCM3168_SRDA_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_MODECTRL_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;  
}

/**
 * \brief	This function is used to control the ADC sampling mode
 *				00 - Auto
 *				01 - Single rate
 *				10 - Dual rate
 *				11 - Reserved
 *
 * \n       ADC Sampling Mode register - 0x50
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   samplingMode  [IN] Sampling mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
static Board_STATUS Board_pcm3168ADCSamplingModeSel(void *handle,
                                                    uint8_t slaveAddr,
                                                    uint8_t samplingMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(samplingMode > BOARD_PCM3168_DUAL_RATE)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_ADC_SMODE_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_SRAD_BIT_MASK);
    regData |= (samplingMode << BOARD_PCM3168_SRAD_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_ADC_SMODE_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
  
}

/**
 * \brief   This function is used to control the DAC audio interface mode.
 *
 *				000 - SlaveMode
 *				001 - Master mode, 768 fS
 *				010 - Master mode, 512 fS
 *				011 - Master mode, 384 fS
 *				100 - Master mode, 256 fS
 *              101 - Master mode, 192 fS
 * 				110 - Master mode, 128 fS
 *
 * \n       DAC Control 1 register - 0x41
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   mscfgMode     [IN] Master/slave mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
static Board_STATUS Board_pcm3168DACMasterSlaveModeSel(void    *handle,
                                                       uint8_t slaveAddr,
                                                       uint8_t mscfgMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(mscfgMode > BOARD_PCM3168_MASTER_MODE_128FS)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_MSDA_BIT_MASK);
    regData |= (mscfgMode << BOARD_PCM3168_MSDA_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   This function is used to control the ADC audio interface mode.
 *
 *				000 - SlaveMode
 *				001 - Master mode, 768 fS
 *				010 - Master mode, 512 fS
 *				011 - Master mode, 384 fS
 *				100 - Master mode, 256 fS
 *
 * \n       ADC Control 1 register - 0x51
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   mscfgMode     [IN] Master/slave mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
static Board_STATUS Board_pcm3168ADCMasterSlaveModeSel(void    *handle,
                                                       uint8_t slaveAddr,
                                                       uint8_t mscfgMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(mscfgMode > BOARD_PCM3168_MASTER_MODE_256FS)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_ADC_MST_FMT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_MSAD_BIT_MASK);
    regData |= (mscfgMode << BOARD_PCM3168_MSAD_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_ADC_MST_FMT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   This function is used to control the ADC audio interface format.
 *				000 - 24-bit I2S format
 *				001 - 24-bit left-justified format
 *				010 - 24-bit right-justified format
 *				011 - 16-bit right-justified format
 *				100 - 24-bit I2S mode DSP format
 *				101 - 24-bit left-justified mode DSP format
 *				110 - 24-bit I2S mode TDM format
 *              111 - 24-bit left-justified mode TDM format
 *
 * \n       ADC Control 1 register - 0x51
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param   fmt			  [IN] Audio format
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static Board_STATUS Board_pcm3168ADCAudioFmtSel(void    *handle,
                                                uint8_t slaveAddr,
                                                uint8_t fmt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(fmt > BOARD_PCM3168_24B_LJ_TDM_FMT)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_ADC_MST_FMT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_FMTAD_BIT_MASK);
    regData |= (fmt << BOARD_PCM3168_FMTAD_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_ADC_MST_FMT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;    
}

/**
 * \brief   This function is used to control the DAC audio interface format.
 *				0000 - 24-bit I2S format
 *				0001 - 24-bit left-justified format
 *				0010 - 24-bit right-justified format
 *				0011 - 16-bit right-justified format
 *				0100 - 24-bit I2S mode DSP format
 *				0101 - 24-bit left-justified mode DSP format
 *				0110 - 24-bit I2S mode TDM format
 *              0111 - 24-bit left-justified mode TDM format
 *              1000 - 24-bit high-speed I2S mode TDM format
 *              1001 - 24-bit high-speed left-justified mode TDM format
 *
 * \n       DAC: DAC Control 1 register - 0x41
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param   fmt			  [IN] Audio format
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static Board_STATUS Board_pcm3168DACAudioFmtSel(void    *handle,
                                                uint8_t slaveAddr,
                                                uint8_t fmt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(fmt > BOARD_PCM3168_24B_HS_LJ_TDM_FMT)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_FMTDA_BIT_MASK);
    regData |= (fmt << BOARD_PCM3168_FMTDA_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;    
}

/**
 * \brief   This function is used to enable or disable the Soft Mute
 *          function for the corresponding DAC outputs
 *				0  - Mute Disabled
 *              1  - Mute Enabled
 *
 * \n       DAC Soft Mute register - 0x44
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   muteCtrl	  [IN] Soft mute enable or disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static Board_STATUS Board_pcm3168DACSoftMuteCtrl(void    *handle,
									             uint8_t slaveAddr,
									             uint8_t chanNum,
								                 uint8_t muteCtrl)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(chanNum > BOARD_PCM3168_CHANNEL_8)
    {
        return BOARD_INVALID_PARAM;
    }
    
    if(chanNum == BOARD_PCM3168_CHANNEL_0)
    {
        if(muteCtrl == BOARD_PCM3168_MUTE_ENABLE)
        {
            regData = 0xFF;
        }
        boardStatus = Board_pcm3168RegWrite(handle,
                                            slaveAddr,
                                            BOARD_PCM3168_DAC_MUTE_REG_ADDR,
                                            &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }
    else
    {
        boardStatus = Board_pcm3168RegRead(handle,
                                           slaveAddr,
                                           BOARD_PCM3168_DAC_MUTE_REG_ADDR,
                                           &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }

        if(muteCtrl == BOARD_PCM3168_MUTE_DISABLE)
        {
           regData &= ~(1 <<(chanNum-1));
        }
        else
        {
           regData |= (1 << (chanNum-1));
        }
        boardStatus = Board_pcm3168RegWrite(handle,
                                            slaveAddr,
                                            BOARD_PCM3168_DAC_MUTE_REG_ADDR,
                                            &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    return boardStatus;     
}

/**
 * \brief   This function is used to enable or disable the Soft Mute
 *          function for the corresponding ADC outputs
 *				0  - Mute Disabled
 *              1  - Mute Enabled
 *
 * \n       ADC Soft Mute register - 0x55
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   muteCtrl	  [IN] Soft mute enable or disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static Board_STATUS Board_pcm3168ADCSoftMuteCtrl(void    *handle,
									             uint8_t slaveAddr,
									             uint8_t chanNum,
								                 uint8_t muteCtrl)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(chanNum > BOARD_PCM3168_CHANNEL_6)
    {
        return BOARD_INVALID_PARAM;
    }

    if(chanNum == BOARD_PCM3168_CHANNEL_0)
    {
        if(muteCtrl == BOARD_PCM3168_MUTE_ENABLE)
        {
            regData = 0x3F;
        }
        boardStatus = Board_pcm3168RegWrite(handle,
                                            slaveAddr,
                                            BOARD_PCM3168_ADC_MUTE_REG_ADDR,
                                            &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }
    else
    {
        boardStatus = Board_pcm3168RegRead(handle,
                                           slaveAddr,
                                           BOARD_PCM3168_ADC_MUTE_REG_ADDR,
                                           &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
        if(muteCtrl == BOARD_PCM3168_MUTE_DISABLE)
        {
           regData &= ~(1 << (chanNum-1));
        }
        else
        {
           regData |= (1 << (chanNum-1));
        }
        boardStatus = Board_pcm3168RegWrite(handle,
                                            slaveAddr,
                                            BOARD_PCM3168_ADC_MUTE_REG_ADDR,
                                            &regData);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }
    return boardStatus;     
}

/**
 * \brief   This function is used to set the DAC attenuation level for each
 *			channel independently.
 *
 * \n       DAC Attenuation register  -  0x47
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   attLevel	  [IN] Attenuation level 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */								   
static Board_STATUS Board_pcm3168DACAttnLevelSet(void    *handle,
									             uint8_t slaveAddr,
									             uint8_t chanNum,
									             uint8_t attLevel)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = attLevel;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(chanNum > BOARD_PCM3168_CHANNEL_8)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_DAC_VOL_MASTER_REG_ADDR + chanNum,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;    
}

/**
 * \brief   This function is used to set the DAC attenuation level for each
 *			channel independently.
 *
 * \n       DAC Attenuation register  -  0x47
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   attLevel	  [IN] Attenuation level 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */								   
static Board_STATUS Board_pcm3168ADCAttnLevelSet(void    *handle,
									             uint8_t slaveAddr,
									             uint8_t chanNum,
									             uint8_t attLevel)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = attLevel;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(chanNum > BOARD_PCM3168_CHANNEL_6)
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_ADC_VOL_MASTER_REG_ADDR + chanNum,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   This function is used to read the Codec register value
 * 
 * \param   handle          [IN]     I2C instance handle.
 * \param   slaveAddr       [IN]     Codec Slave Address
 * \param   regAddr         [IN]     register Address of the Codec
 * \param   regData         [IN/OUT] register Data 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168RegRead(void *handle,
                                  uint8_t slaveAddr,
                                  uint8_t regAddr,
                                  uint8_t *regData)
{
    Board_STATUS boardStatus = BOARD_SOK;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
									 regAddr,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_1,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    return boardStatus;
}

/**
 * \brief   This function is used to write the register data to the
 *          PCM Codec.
 *
 * \param   handle          [IN] I2C instance handle.
 * \param   slaveAddr       [IN]  Codec Slave Address
 * \param   regAddr         [IN]  register Address of the Codec
 * \param   regData         [OUT] register Data
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168RegWrite(void *handle,
                                   uint8_t slaveAddr,
                                   uint8_t regAddr,
                                   uint8_t *regData)
{
    Board_STATUS boardStatus = BOARD_SOK;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_i2c8BitRegWr(handle,
									 slaveAddr,
									 regAddr,
									 regData,
                                     BOARD_I2C_NUM_OF_BYTES_1,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);

    return boardStatus;
}

/**
 * \brief   This function is used to set the mode control register reset to the
 * 			default value
 *				0  -  Writes default value to mode control register
 *				1  -  Normal operation
 *
 * \n       Reset Control register - 0x40
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   modeCtrl      [IN] Mode control register reset for the ADC and DAC
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_pcm3168ModeCtrl(void   *handle,
								   uint8_t slaveAddr,
								   uint8_t modeCtrl)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_MODECTRL_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_MRST_BIT_MASK);
    regData |= (modeCtrl << BOARD_PCM3168_MRST_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_MODECTRL_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}					   

/**
 * \brief  This function is used to control the  system reset
 *				0  - Restarts the system by resyncronizing the system clock and
 *				     sampling clock
 *				1  - Normal operation
 *
 * \n       Reset Control register - 0x40
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   modeCtrl      [IN] System reset for the ADC and DAC
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_pcm3168Reset(void    *handle,
								uint8_t slaveAddr,
							    uint8_t modeCtrl)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_MODECTRL_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_SRST_BIT_MASK);
    regData |= (modeCtrl << BOARD_PCM3168_SRST_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_MODECTRL_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief	This function is used to control the sampling mode of DAC/ADC
 *				00 - Auto
 *				01 - Single rate
 *				10 - Dual rate
 *				11 - Reserved for ADC
 *              11 - Quad rate for DAC
 *
 * \n        DAC : Reset Control register     - 0x40
 * \n		 ADC : ADC Sampling Mode register - 0x50
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   samplingMode  [IN] Sampling mode select
 * \param   cfgMode  	  [IN] Configure ADC/DAC channel
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_pcm3168SamplingModeSel(void    *handle,
									      uint8_t slaveAddr,
									      uint8_t samplingMode,
										  uint8_t cfgMode)
{
    Board_STATUS boardStatus = BOARD_SOK;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(cfgMode > BOARD_PCM3168_CFG_ALL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((cfgMode == BOARD_PCM3168_CFG_DAC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168DACSamplingModeSel(handle,
                                                      slaveAddr,
                                                      samplingMode);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;         
        }
    }

    if((cfgMode == BOARD_PCM3168_CFG_ADC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168ADCSamplingModeSel(handle,
                                                      slaveAddr,
                                                      samplingMode);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;         
        }        
    }

    return boardStatus;
}

/**
 * \brief   This function is used to control the power save mode of DAC
 * 			operation
 *				0 - Power-save enable  mode
 *				1 - Power-save disable mode
 *
 * \n       DAC Control 1 register  - 0x41
 *
 * \param   handle         [IN] I2C driver handle
 * \param   slaveAddr      [IN] Codec slave address
 * \param   pwrSaveMode    [IN] Power-save mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */											 
Board_STATUS Board_pcm3168DACPwrSaveModeSel(void    *handle,
                                            uint8_t slaveAddr,
                                            uint8_t pwrSaveMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_PSMDA_BIT_MASK);
    regData |= (pwrSaveMode << BOARD_PCM3168_PSMDA_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
      
}

/**
 * \brief   This function is used to control the power save mode of ADC
 * 			operation
 *				0 - normal operation
 *				1 - power-save mode
 *
 * \n       ADC Control 2 register      - 0x52
 *
 * \param   handle         [IN] I2C driver handle
 * \param   slaveAddr      [IN] Codec slave address
 * \param   pwrSaveMode    [IN] Power-save mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */											 
Board_STATUS Board_pcm3168ADCPwrSaveModeSel(void    *handle,
                                            uint8_t slaveAddr,
                                            uint8_t pwrSaveMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_ADC_PWR_HPFB_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_PCM3168_PSVAD_BIT_MASK);
    regData |= (((pwrSaveMode == 1) ?  0x7 : 0x00) << BOARD_PCM3168_PSVAD_SHIFT_CNT);

    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_ADC_PWR_HPFB_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   This function is used to control the audio interface mode.
 *
 *				000 - SlaveMode
 *				001 - Master mode, 768 fS
 *				010 - Master mode, 512 fS
 *				011 - Master mode, 384 fS
 *				100 - Master mode, 256 fS
 *          Below modes supports only for DAC operation 
 *              101 - Master mode, 192 fS
 * 				110 - Master mode, 128 fS
 *
 * \n       DAC: DAC Control 1 register - 0x41
 * \n       ADC: ADC Control 1 register - 0x51
 *
 * \param   handle        [IN] I2C driver handle
 * \param   slaveAddr     [IN] Codec slave address
 * \param   mscfgMode     [IN] Master/slave mode select
 * \param   cfgMode  	  [IN] Configure ADC/DAC channel
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_pcm3168MasterSlaveModeSel(void    *handle,
									         uint8_t slaveAddr,
									         uint8_t mscfgMode,
											 uint8_t cfgMode)
{
     Board_STATUS boardStatus = BOARD_SOK;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(cfgMode > BOARD_PCM3168_CFG_ALL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((cfgMode == BOARD_PCM3168_CFG_DAC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168DACMasterSlaveModeSel(handle,
                                                         slaveAddr,
                                                         mscfgMode);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    if((cfgMode == BOARD_PCM3168_CFG_ADC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168ADCMasterSlaveModeSel(handle,
                                                         slaveAddr,
                                                         mscfgMode);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }   
    }

    return boardStatus;
}
                                               
/**
 * \brief   This function is used to control the audio interface format.
 *				000 - 24-bit I2S format
 *				001 - 24-bit left-justified format
 *				010 - 24-bit right-justified format
 *				011 - 16-bit right-justified format
 *				100 - 24-bit I2S mode DSP format
 *				101 - 24-bit left-justified mode DSP format
 *				110 - 24-bit I2S mode TDM format
 *              111 - 24-bit left-justified mode TDM format
 *          Below modes support only for DAC configuration
 *              1000 - 24-bit high-speed I2S mode TDM format
 *              1001 - 24-bit high-speed left-justified mode TDM format
 *
 * \n       DAC: DAC Control 1 register - 0x41
 * \n       ADC: ADC Control 1 register - 0x51
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param   fmt			  [IN] Audio format
 * \param   cfgMode  	  [IN] Configure ADC/DAC channel
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168AudioFmtSel(void    *handle,
									  uint8_t slaveAddr,
								      uint8_t fmt,
									  uint8_t cfgMode)
{
     Board_STATUS boardStatus = BOARD_SOK;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(cfgMode > BOARD_PCM3168_CFG_ALL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((cfgMode == BOARD_PCM3168_CFG_DAC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168DACAudioFmtSel(handle,
                                                  slaveAddr,
                                                  fmt);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    if((cfgMode == BOARD_PCM3168_CFG_ADC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168ADCAudioFmtSel(handle,
                                                  slaveAddr,
                                                  fmt);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    return boardStatus;
}

/**
 * \brief   This function is used to control the DAC operation mode.
 *
 *			In operation disable mode,the DAC output is cut off from DIN with
 *          a fade-out sequence, and the internal DAC data is reset.
 *			DAC output is forced into VCOMDA if PSMDA = 1
 *          DAC output is forced into AGNDDA and goes into a power-down state
 *			if PSMDA = 0.
 *		    In normal operating mode, a fade-in sequence is applied on the DAC
 *			output in resume process.
 *		    	   0 - Normal mode
 * 				   1 - Operation disable with or without power save
 *
 * \n       DAC Control 2 register -  0x42
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param   opMode	      [IN] Enable/Disable the power-save mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168DACOperationalCtrl(void    *handle,
								             uint8_t slaveAddr,
								             uint8_t opMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    boardStatus = Board_pcm3168RegRead(handle,
                                       slaveAddr,
									   BOARD_PCM3168_DAC_OP_FLT_REG_ADDR,
                                       &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    regData |= (((opMode == 1) ? 0x0F : 0) << BOARD_PCM3168_OPED_SHIFT_CNT);
    boardStatus = Board_pcm3168RegWrite(handle,
									    slaveAddr,
									    BOARD_PCM3168_DAC_OP_FLT_REG_ADDR,
									    &regData);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   This function is used to enable or disable the Soft Mute
 *          function for the corresponding DAC/ADC outputs
 *				0  - Mute Disabled
 *              1  - Mute Enabled
 *
 * \n       DAC: DAC Soft Mute register - 0x44
 * \n       ADC: ADC Soft Mute register - 0x55
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   muteCtrl	  [IN] Soft mute enable or disable
 * \param   cfgMode  	  [IN] Configure ADC/DAC channel
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_pcm3168SoftMuteCtrl(void    *handle,
									   uint8_t slaveAddr,
									   uint8_t chanNum,
								       uint8_t muteCtrl,
									   uint8_t cfgMode)
{
     Board_STATUS boardStatus = BOARD_SOK;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(cfgMode > BOARD_PCM3168_CFG_ALL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((cfgMode == BOARD_PCM3168_CFG_DAC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        
        boardStatus = Board_pcm3168DACSoftMuteCtrl(handle,
                                                   slaveAddr,
                                                   chanNum,
                                                   muteCtrl);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    if((cfgMode == BOARD_PCM3168_CFG_ADC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168ADCSoftMuteCtrl(handle,
                                                   slaveAddr,
                                                   chanNum,
                                                   muteCtrl);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    return boardStatus;
}

/**
 * \brief   This function is used to set the attenuation level for each channel
 *			independently.
 *
 * \n       DAC :DAC Attenuation register  -  0x47
 * \n       ADC :ADC Attenuation register  -  0x58
 *
 * \param   handle        [IN] I2C driver handle
 * \param	slaveAddr     [IN] Codec slave address
 * \param	chanNum	      [IN] Channel Number to configure
 *								0 - All channels by default 
 * \param   attLevel	  [IN] Attenuation level
 * \param   cfgMode  	  [IN] Configure ADC/DAC channel 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */								   
Board_STATUS Board_pcm3168AttnLevelSet(void    *handle,
									   uint8_t slaveAddr,
									   uint8_t chanNum,
									   uint8_t attLevel,
									   uint8_t cfgMode)
{
     Board_STATUS boardStatus = BOARD_SOK;

    if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    if(cfgMode > BOARD_PCM3168_CFG_ALL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((cfgMode == BOARD_PCM3168_CFG_DAC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168DACAttnLevelSet(handle,
                                                   slaveAddr,
                                                   chanNum,
                                                   attLevel);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    if((cfgMode == BOARD_PCM3168_CFG_ADC) || (cfgMode == BOARD_PCM3168_CFG_ALL))
    {
        boardStatus = Board_pcm3168ADCAttnLevelSet(handle,
                                                   slaveAddr,
                                                   chanNum,
                                                   attLevel);
        if(boardStatus != BOARD_SOK)
        {
            return boardStatus;
        }
    }

    return boardStatus;
}

/* End of file */
