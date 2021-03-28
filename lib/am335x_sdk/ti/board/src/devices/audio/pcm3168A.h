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
 * \file  pcm3168A.h
 *
 * \brief The macro definitions and function prototypes for
 *        configuring PCM3168 codec.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_AUDIO
 *
 *  \defgroup BOARD_LIB_DEVICES_AUDIO_PCM3168 PCM3168 Audio Codec Library
 *
 *  Provides APIs for configuring the PCM3168 Audio Codec device
 *
 *  @{
 *
 */
/* @} */

#ifndef _PCM3168A_H_
#define _PCM3168A_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/board.h>
#include <ti/board/src/devices/common/common.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_AUDIO_PCM3168
 *
 *  \defgroup BOARD_LIB_DEVICES_AUDIO_PCM3168_TYPES Data Types
 *
 *  Data types used by PCM3168 Audio Codec library.
 *
 *  @{
 *
 */

/** ADC/DAC mode control register address */
#define BOARD_PCM3168_MODECTRL_REG_ADDR             (0x40U)

/** DAC Control 1 register address */
#define BOARD_PCM3168_DAC_PWR_MST_FMT_REG_ADDR      (0x41U)

/** DAC Control 2 register address */
#define BOARD_PCM3168_DAC_OP_FLT_REG_ADDR           (0x42U)

/** DAC Output Phase control register address */
#define BOARD_PCM3168_DAC_INV_REG_ADDR			    (0x43U)

/** DAC Soft Mute Control register address */
#define BOARD_PCM3168_DAC_MUTE_REG_ADDR			    (0x44U)

/** DAC Zero Flag register address */
#define BOARD_PCM3168_DAC_ZERO_REG_ADDR			    (0x45U)

/** DAC Control 3 register address */
#define BOARD_PCM3168_DAC_ATT_DEMP_ZF_REG_ADDR		(0x46U)

/** DAC master volume contol register address */
#define BOARD_PCM3168_DAC_VOL_MASTER_REG_ADDR		(0x47U)

/** DAC Channel0 volume control register address */
#define BOARD_PCM3168_DAC_VOL_CHAN_START_REG_ADDR	(0x48U)

/** ADC Sampling Mode control register address */
#define BOARD_PCM3168_ADC_SMODE_REG_ADDR			(0x50U)

/** ADC Control 1 register address */
#define BOARD_PCM3168_ADC_MST_FMT_REG_ADDR			(0x51U)

/** ADC Control 2 register address */
#define BOARD_PCM3168_ADC_PWR_HPFB_REG_ADDR			(0x52U)

/** ADC Input Configuration register address */
#define BOARD_PCM3168_ADC_SEAD_REG_ADDR			    (0x53U)

/** ADC Input Phase control register address */
#define BOARD_PCM3168_ADC_INV_REG_ADDR			    (0x54U)

/** ADC Soft Mute control register address */
#define BOARD_PCM3168_ADC_MUTE_REG_ADDR			    (0x55U)

/** ADC Overflow Flag register address */
#define BOARD_PCM3168_ADC_OV_REG_ADDR				(0x56U)

/** ADC Control 3 register address */
#define BOARD_PCM3168_ADC_ATT_OVF_REG_ADDR			(0x57U)

/** ADC master volume contol register address */
#define BOARD_PCM3168_ADC_VOL_MASTER_REG_ADDR		(0x58U)

/** ADC Channel0 volume control register address */
#define BOARD_PCM3168_ADC_VOL_CHAN_START_REG_ADDR	(0x59U)

/** I2C number of bytes */
#define BOARD_I2C_NUM_OF_BYTES_1                    (0x1U)

/** Reset control register bit fields */
#define BOARD_PCM3168_MRST_SHIFT_CNT    (0x07U)
#define BOARD_PCM3168_SRST_SHIFT_CNT    (0x06U)
#define BOARD_PCM3168_SRDA_SHIFT_CNT    (0x0U)

#define BOARD_PCM3168_MRST_BIT_MASK    (0x01 << BOARD_PCM3168_MRST_SHIFT_CNT)
#define BOARD_PCM3168_SRST_BIT_MASK    (0x01 << BOARD_PCM3168_SRST_SHIFT_CNT)
#define BOARD_PCM3168_SRDA_BIT_MASK    (0x03 << BOARD_PCM3168_SRDA_SHIFT_CNT)

/** DAC Power save mode select register bit fileds */
#define BOARD_PCM3168_PSMDA_SHIFT_CNT    (0x07U)
#define BOARD_PCM3168_MSDA_SHIFT_CNT     (0x04U)
#define BOARD_PCM3168_FMTDA_SHIFT_CNT    (0x0U)

#define BOARD_PCM3168_PSMDA_BIT_MASK    (0x01 << BOARD_PCM3168_PSMDA_SHIFT_CNT)
#define BOARD_PCM3168_MSDA_BIT_MASK     (0x07 << BOARD_PCM3168_MSDA_SHIFT_CNT)
#define BOARD_PCM3168_FMTDA_BIT_MASK    (0x0F << BOARD_PCM3168_FMTDA_SHIFT_CNT)

/** DAC operational control register bit fields */
#define BOARD_PCM3168_OPED_SHIFT_CNT     (0x04U)
#define BOARD_PCM3168_OPED_BIT_MASK      (0x0F << BOARD_PCM3168_PSMDA_SHIFT_CNT)

/** ADC Sampling Mode register bit fields */
#define BOARD_PCM3168_SRAD_SHIFT_CNT    (0x0U)

#define BOARD_PCM3168_SRAD_BIT_MASK     (0x03 << BOARD_PCM3168_SRAD_SHIFT_CNT)

/** ADC Control 1 register bit fields */
#define BOARD_PCM3168_MSAD_SHIFT_CNT     (0x04U)
#define BOARD_PCM3168_FMTAD_SHIFT_CNT    (0x0U)

#define BOARD_PCM3168_MSAD_BIT_MASK     (0x07 << BOARD_PCM3168_MSAD_SHIFT_CNT)
#define BOARD_PCM3168_FMTAD_BIT_MASK    (0x07 << BOARD_PCM3168_FMTAD_SHIFT_CNT)

/** ADC Control 2 register bit fields */
#define BOARD_PCM3168_PSVAD_SHIFT_CNT     (0x04U)

#define BOARD_PCM3168_PSVAD_BIT_MASK      (0x07 << BOARD_PCM3168_PSVAD_SHIFT_CNT)

/** Chaneel number */
#define BOARD_PCM3168_CHANNEL_0           (0x0U)

#define BOARD_PCM3168_CHANNEL_1           (0x1U)

#define BOARD_PCM3168_CHANNEL_2           (0x2U)

#define BOARD_PCM3168_CHANNEL_3           (0x3U)

#define BOARD_PCM3168_CHANNEL_4           (0x4U)

#define BOARD_PCM3168_CHANNEL_5           (0x5U)

#define BOARD_PCM3168_CHANNEL_6           (0x6U)

#define BOARD_PCM3168_CHANNEL_7           (0x7U)

#define BOARD_PCM3168_CHANNEL_8           (0x8U)

/**
 * \brief  Defines the codec config path
 */
/** Configure the DAC channel */
#define BOARD_PCM3168_CFG_DAC    (0U)
/** Configure the ADC channel */
#define BOARD_PCM3168_CFG_ADC    (1U)
/** Configure both ADC and DAC channels */
#define BOARD_PCM3168_CFG_ALL    (2U)

/**
 * \brief  Defines the codec mode control options
 */
/** Sets the codec to power down mode  */
#define BOARD_PCM3168_MODE_PWROFF    (0)
/** Sets the codec to normal operation mode */
#define BOARD_PCM3168_MODE_NORMAL    (1U)

/**
 * \brief  Defines the codec Sampling mode options
 */
/** Sampling mode is automatically set */
#define BOARD_PCM3168_SAMPLE_AUTO    (0)
/** Sets the single rate for 512 fS and 768 fS */
#define BOARD_PCM3168_SINGLE_RATE    (1U)
/** Sets the dual rate for 256 fS or 384 fS */
#define BOARD_PCM3168_DUAL_RATE      (2U)
/** Sets the quad rate for 128 fS and 192 fS */
#define BOARD_PCM3168_QUAD_RATE      (3U)

/**
 * \brief  Defines the DAC power save mode options
 */
/** Enable Power save mode */
#define BOARD_PCM3168_POWERSAVE_ENABLE     (0) 
/** Disable Power save mode */
#define BOARD_PCM3168_POWERSAVE_DISABLE    (1U)

/**
 * \brief  Defines the ADC power save mode options
 */
/** Normal mode */
#define BOARD_PCM3168_NORMAL_MODE        (0U)
 /** Enable Power save mode */
#define BOARD_PCM3168_POWERSAVE_MODE     (1U) 

/**
 * \brief  Defines the codec master slave configuration
 */
/** Configure the Codec in slave mode */
#define BOARD_PCM3168_SLAVE_MODE            (0)
/** Configure the Codec in Master mode with 768 fs*/
#define BOARD_PCM3168_MASTER_MODE_768FS     (1U)
/** Configure the Codec in Master mode with 512 fs*/
#define BOARD_PCM3168_MASTER_MODE_512FS     (2U)
/** Configure the Codec in Master mode with 384 fs*/
#define BOARD_PCM3168_MASTER MODE_384FS     (3U)
/** Configure the Codec in Master mode with 256 fs*/
#define BOARD_PCM3168_MASTER_MODE_256FS     (4U)
/** Configure the Codec in Master mode with 192 fs*/
#define BOARD_PCM3168_MASTER_MODE_192FS     (5U)
/** Configure the Codec in Master mode with 128 fs*/
#define BOARD_PCM3168_MASTER_MODE_128FS     (6U)

/**
 * \brief  Defines the codec data format
 */
/** Sets the codec data format to 24-bit I2S format */
#define BOARD_PCM3168_24B_I2S_FMT           (0)
/** Sets the codec data format to 24-bit left-justified format */
#define BOARD_PCM3168_24B_LJ_FMT            (1U)
/** Sets the codec data format to 24-bit right-justified format */
#define BOARD_PCM3168_24B_RJ_FMT            (2U)
/** Sets the codec data format to 16-bit right-justified format */
#define BOARD_PCM3168_16B_RJ_FMT            (3U)
/** Sets the codec data format to  24-bit I2S mode DSP format */
#define BOARD_PCM3168_24B_I2S_DSP_FMT       (4U)
/** Sets the codec data format to 24-bit left-justified mode DSP format */
#define BOARD_PCM3168_24B_LJ_DSP_FMT        (5U)
/** Sets the codec data format to 24-bit I2S mode TDM format */
#define BOARD_PCM3168_24B_I2S_TDM_FMT       (6U)
/** Sets the codec data format to 24-bit left-justified mode TDM format */
#define BOARD_PCM3168_24B_LJ_TDM_FMT        (7U)
/** Sets the codec data format to 24-bit high-speed I2S mode TDM format */
#define BOARD_PCM3168_24B_HS_I2S_TDM_FMT    (8U)
/** Sets the codec data format to 24-bit high-speed left-justified mode TDM format */
#define BOARD_PCM3168_24B_HS_LJ_TDM_FMT     (9U)

/**
 * \brief  Defines the DAC Operation mode
 */
/** Configures the DAC in normal operation mode */
#define BOARD_PCM3168_DAC_NORMAL_OPERATION    (0)
/** Diables the DAC operation with or with out Power save */
#define BOARD_PCM3168_DAC_OPERATION_DISABLE   (1U)

/**
 * \brief  Defines the Codec soft mute control
 */
/** Disables the codec soft mute function */
#define BOARD_PCM3168_MUTE_DISABLE    (0)
/** Enables the codec soft mute function */
#define BOARD_PCM3168_MUTE_ENABLE     (1U)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_AUDIO_PCM3168
 *
 *  \defgroup BOARD_LIB_DEVICES_AUDIO_PCM3168_APIS Application Interfaces
 *
 *  Application Interfaces provided by PCM3168 Audio Codec library.
 *
 *  @{
 *
 */

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
Board_STATUS Board_pcm3168Config(void *handle, uint8_t slaveAddr);

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
                                  uint8_t *regData);

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
                                   uint8_t *regData);

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
								   uint8_t modeCtrl);

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
							    uint8_t modeCtrl);

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
										  uint8_t cfgMode);

/**
 * \brief   This function is used to control the power save mode of DAC/ADC
 * 			operation
 *				0 - Power-save enable  mode
 *				1 - Power-save disable mode
 *
 * \n       DAC : DAC Control 1 register      - 0x41
 * \n		ADC : ADC Control 2 register      - 0x52
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
									     uint8_t pwrSaveMode);
                                         
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
                                            uint8_t pwrSaveMode);                                        

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
											 uint8_t cfgMode);

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
									  uint8_t cfgMode);
										 
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
								             uint8_t opMode);

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
									   uint8_t cfgMode);

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
									   uint8_t cfgMode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PCM3168_H_ */

/* @} */
