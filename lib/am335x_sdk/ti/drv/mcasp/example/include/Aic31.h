/*
 * Aic31.h
 *
 * This file contains Application programming interface for the Aic3106 codec 
 * driver and command/macro definitions used by the Aic3106 Codec driver.
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

/*
 *  ======== platforms/codec/include/Aic31.h ========
 */


#ifndef _AIC31_H_
#define _AIC31_H_

#include <xdc/std.h>
#include <ti/sysbios/io/IOM.h>
#include <ICodec.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------- constants -------- */
#define Aic31_I2CTIMEOUT  (0xFFFFFFFF)

/**
 *  \brief  Aic31 Ioctl commands
 *
 *  Aic31 Ioctl commands
 */
typedef enum Aic31_ioctlCmd {
    Aic31_AC_IOCTL_MUTE_ON = 128,
    Aic31_AC_IOCTL_MUTE_OFF,
    Aic31_AC_IOCTL_SET_VOLUME,
    Aic31_AC_IOCTL_SET_LOOPBACK,
    Aic31_AC_IOCTL_SET_SAMPLERATE,
    Aic31_AC_IOCTL_REG_WRITE,
    Aic31_AC_IOCTL_REG_READ,
    Aic31_AC_IOCTL_REG_WRITE_MULTIPLE,
    Aic31_AC_IOCTL_REG_READ_MULTIPLE,
    Aic31_AC_IOCTL_SELECT_OUTPUT_SOURCE,
    Aic31_AC_IOCTL_SELECT_INPUT_SOURCE,
    Aic31_AC_IOCTL_GET_CODEC_INFO
}Aic31_ioctlCmd;

/* -------- per-instance configs -------- */
/**
 *  \brief Aic31_Params
 *
 *   This structure contains the parameters required during the creation of the
 *   codec driver,
 */

typedef struct Aic31_Params 
{
    ICodec_CodecType        acType;
    /**< Audio codec type (Aic31/Aic33 etc)                                   */

    ICodec_ControlBusType   acControlBusType;
    /**< Control bus to be used for the configuring of the codec              */

    String                  acCtrlBusName;
    /**< Name of the control bus driver in the driver table                   */

    ICodec_OpMode           acOpMode;
    /**< Operational mode of the codec (Master or slave)                      */

    ICodec_DataType         acSerialDataType;
    /**< Data transport format to be used (TDM/DSP etc)                       */

    uint32_t                  acSlotWidth;
    /**< Slot width of the data to be used                                    */

    ICodec_DataPath         acDataPath;
    /**< Mode in which the codec has to be used (TX/RX/ RXTX)                 */

    Bool                    isRxTxClockIndependent;
    /**<
     * Variable to indicate whether the RX and TX clock are to be independent or
     * synchronous to each other.
     */
    uint8_t                   acCtrlBusInstNum;
    /**< I2C instance used to configure codec                                 */

    uint32_t                  acBaseAddress;
    /**< CtrlBus Base Address used to configure codec                         */

}Aic31_Params;


/**
 *  \brief Default Aic31_Params struct
 *
 *  Aic31_Params Aic31_PARAMS = {
 *
 *      ICodec_CodecType_AIC31,                 acType
 *
 *      ICodec_ControlBusType_I2C,              acControlBusType
 *
 *     "NONE",                                  acCtrlBusName
 *
 *      ICodec_OpMode_MASTER,                   acOpMode
 *
 *      ICodec_DataType_DSP,                    acSerialDataType
 *
 *      (uint32_t)0x20,                           acSlotWidth
 *
 *      ICodec_DataPath_TXRX,                   acDataPath
 *
 *      0,                                      isRxTxClockIndependent
 *
 *  };
 */
extern const Aic31_Params Aic31_PARAMS;

/**
 *  \brief Aic31 IOM_Fxns table
 *
 *  Driver function table to be used by applications.
 */
extern const IOM_Fxns Aic31_IOMFXNS;

/**
 *  \brief    Initializes Aic31 instances which are statically allocated
 *
 *  This function needs to ve be called at part of BIOS initialization by
 *  setting initFxn for that particular UDEV instance or by calling this
 *  function as part of user specific initFxn.
 */
Void Aic31_init(Void);
 
 
 Int aic31MdBindDev(Ptr *devp, Int devId, Ptr devParams);
 Int aic31MdUnBindDev(Ptr devp);
 Int aic31MdCreateChan(
                    Ptr                 *chanp,
                    Ptr                 devp,
                    String              name,
                    Int                 mode,
                    Ptr                 chanParams,
                    IOM_TiomCallback    cbFxn,
                    Ptr                 cbArg
                    );
 Int aic31MdDeleteChan(Ptr chanp);
 Int aic31MdSubmitChan(Ptr chanp, IOM_Packet *ioPacket);
 Int aic31MdControlChan(Ptr chanp, Uns cmd, Ptr cmdArgs);

#ifdef __cplusplus
}
#endif

#endif /*_AIC31_H_ */
