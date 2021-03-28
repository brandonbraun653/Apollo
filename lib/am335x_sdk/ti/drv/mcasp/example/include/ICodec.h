/*
 * ICodec.h
 *
 * This file contains interface definition for a generic codec interface which 
 * can be used/implemented by various codec drivers.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
 *
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
*/

/**
 *  @file     ICodec.h    
 *
 *  @brief    ICodec Interface for codec drivers for BIOS 6.x
 *
*
 *  A Codec Driver manages a codec(s) that provide channels for input and
 *  output of audio data. All the instances of the same codec are managed 
 *  by a single driver. For example all the Aic31 codecs for a platform 
 *  are managed by a single driver(with a different driver instance
 * 
 *  The ICodec interface provides the generic data structures required by the 
 *  codec driver and also provides the list of the basic control commands that
 *  need to be provided by the codec drivers inheriting this interface.
 *
 *  This file contains the interfaces, data types and symbolic definitions
 *  that are needed by the application to utilize the serivces of the codec
 *  device driver.
 */
 
#ifndef ICodec_
#define ICodec_

#include <xdc/std.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------- typedef enums -------- */

typedef enum ICodec_Channel {
    ICodec_Channel_INPUT,
    ICodec_Channel_OUTPUT,
    ICodec_Channel_MAX
}ICodec_Channel;

/** 
 *  \brief Codec types defintion
 *
 *  This enum defines the audio codec types supported in the Audio Framework.
 */
typedef enum ICodec_CodecType {
    ICodec_CodecType_AIC12,     /**<  TI's AIC12 Audio Codec                  */
    ICodec_CodecType_AIC23,     /**<  TI's AIC23 Audio Codec                  */
    ICodec_CodecType_AIC31,     /**<  TI's AIC31 Audio Codec                  */
    ICodec_CodecType_AIC33,     /**<  TI's AIC33 Audio Codec                  */
    ICodec_CodecType_TYPE2,     /**<  User defined Audio Codec                */
    ICodec_CodecType_TYPE3,     /**<  User defined Audio Codec                */
    ICodec_CodecType_TYPE4,     /**<  User defined Audio Codec                */
    ICodec_CodecType_UNKNOWN    /**<  Delimiter Enum                          */
}ICodec_CodecType;

/** 
 *  \brief Control bus type to be used for configure the codec.
 *   
 *  This enum defines the audio codec control bus type.
 */
typedef enum ICodec_ControlBusType {
    ICodec_ControlBusType_I2C,      /**< Control Bus for Audio Codec is I2C   */
    ICodec_ControlBusType_SPI,      /**< Control Bus for Audio Codec is SPI   */
    ICodec_ControlBusType_UNKNOWN   /**< Delimiter Enum                       */
}ICodec_ControlBusType;

/** 
 *  \brief Data path to be used by the codec.
 *
 *  This enum defines the audio codec data paths possible.
 */
typedef enum ICodec_DataPath {
    ICodec_DataPath_TX,   /**< Only Tx path of audio codec is used            */
    ICodec_DataPath_RX,   /**< Only Rx path of audio codec is used            */
    ICodec_DataPath_TXRX  /**< Both Tx and Rx path of audio codec is used     */
}ICodec_DataPath;

/** 
 *  \brief Audio data type to be transferred.
 *
 *  This enum defines the audio codec serial data type.This is used to
 *  configure the data transfer type.
 */
typedef enum ICodec_DataType {
    ICodec_DataType_LEFTJ, /**<Audio Codec serial data type is left justified */
    ICodec_DataType_RIGHTJ,/**<Audio Codec serial data type is right justified*/
    ICodec_DataType_I2S,   /**<Audio Codec serial data type is I2S            */
    ICodec_DataType_DSP,   /**<Audio Codec serial data type is DSP            */
    ICodec_DataType_TDM    /**<Audio Codec serial data type is TDM            */
}ICodec_DataType;

/** 
 *  \brief Codec driver and channel status enumeration.
 *
 *  codec driver state enums used to track the current state of the driver
 *  and also the channels.
 */
typedef enum ICodec_DriverState {
    ICodec_DriverState_DELETED,
    ICodec_DriverState_CREATED,
    ICodec_DriverState_INITIALIZED,
    ICodec_DriverState_OPENED,
    ICodec_DriverState_CLOSED,
    ICodec_DriverState_DEINITIALIZED,
    ICodec_DriverState_POWERED_DOWN
}ICodec_DriverState;

/** 
 *  \brief Codec operating Mode
 *  
 *  This enum defines the audio codec operating mode.
 */
typedef enum ICodec_OpMode
{
    ICodec_OpMode_MASTER,  /**< Audio Codec operates in Master mode           */
    ICodec_OpMode_SLAVE    /**< Audio Codec operates in Slave mode            */
}ICodec_OpMode;


/*! Audio output selection
 *
 * This enum specifies the source to be used for the audio data output.
 */
enum ICodec_OutputDest
{
    ICodec_OutputDest_LINEOUT,  /*! Audio is output to the lineout pins       */
	ICodec_OutputDest_HPOUT,    /*! Audio is output to the HP out pins        */
	ICodec_OutputDest_BOTH      /*! Audio is output to both the pins          */
};


/** 
 * \brief  Audio input selection
 *
 *  This enum specifies the source to be used as the audio data input source.
 */
enum ICodec_InputDest
{
    ICodec_InputDest_MICIN,  /**< Audio is input from MIC in                  */
    ICodec_InputDest_LINEIN  /**< Audio is input from line in                 */
};



/*!
 * \brief  Audio codec data slot size.
 *
 * This enum specifies the Audio data slot width.This is used to configure
 * the individual channel slot width.
 */
enum ICodec_SlotWidth
{
   ICodec_SlotWidth_16,    /**< channel slotwidth is 16 bit                   */
   ICodec_SlotWidth_20,    /**< channel slotwidth is 20 bit                   */
   ICodec_SlotWidth_24,    /**< channel slotwidth is 24 bit                   */
   ICodec_SlotWidth_32     /**< channel slotwidth is 32 bit                   */
};


/* -------- typedef structs -------- */
/**
 *  \brief Channel parameters required during the channel opening
 *
 *  This structure defines the channel parameters. This parameter is
 *  supplied with the open call of the Audio Codec. This configures the
 *  parameters required by the channels.
 */
typedef struct ICodec_ChannelConfig {
    uint32_t samplingRate;  /**< Audio data sampling rate                       */
    uint32_t chanGain;      /**< The intial gain for the channel                */
    uint32_t bitClockFreq;  /**< Bit Clock speed                                */
    uint32_t numSlots;      /**< Number of slots                                */
}ICodec_ChannelConfig;

/** 
 *  \brief Structure used during read and write to the codec registers.
 *
 *  This structure specifies the codec register write or read
 *  information. The regIndex element specifies the starting index
 *  of the codec register. The regData element specifies the register
 *  data to be read/written. The regCount element specifies the
 *  total number of registers to be read/written.
 */ 
typedef struct ICodec_RegData {
    uint32_t  regIndex;       /**< Starting index and codec register            */
    Ptr     regData;        /**< Register data written/read                   */
    uint32_t  regCount;       /**< Number of registers written/read             */
}ICodec_RegData;


/**
 * \brief Structure used to pass information related to the codec to the audio
 *        layer.
 *
 * This structure contains the data that will be required by the audio 
 * interface layer.This infromation is required by the audio interface to 
 * interface with the codec and sending IOCTLs etc.
 */
typedef struct ICodec_CodecData
{
    ICodec_OpMode                          acOpMode;
    /**< Audio Codec operating mode                                           */

}ICodec_CodecData;

#ifdef __cplusplus
}
#endif

#endif
