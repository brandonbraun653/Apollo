/**
 * \file   board.h
 *
 * \brief  This file contains the APIs that abstract the board-specific details
 *         for StarterWare.
 * The key functionality of this module includes:
 * - Abstraction out of board specific information through APIs
 * - Auto-detection of board, including getting information about board type
 * - Definition of board specific data including:
 *   - Pinmux data
 *   - Clock source information
 *   - On-board devices list, including i2c information
 *   - IP instance availability on board
 *   - Board-level mux, power, IO expanders
 *
 * The Board module needs to be initialized before it can be used.
 *
 * The usual functions called would be:
 * #BOARDInit
 * #BOARDGetId
 *
 * To get information about connected devices in order to control them:
 * #BOARDIsDevicePresent
 * #BOARDGetDeviceCtrlModId
 * #BOARDGetDeviceCtrlModInstNum
 * #BOARDGetDeviceCtrlInfo
 * #BOARDGetDeviceDataModId
 * #BOARDGetDeviceDataModInstNum
 *
 *  \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
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

#ifndef BOARD_H_
#define BOARD_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "chipdb.h"
#include "pinmux.h"
#include "dcard.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Unknown board revision */
#define BOARD_REV_UNKNOWN       (0x0U)

/** \brief Indicates that the specific board information is to be auto-detected.
 */
#define BOARD_AUTO_DETECT       (0xFFU)

#ifndef DDRLESS
/**
 *  \brief EVM Board ID.
 */
typedef enum boardId
{
    BOARD_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_UNKNOWN = BOARD_MIN,
    /**< Unknown board. */
    BOARD_GPEVM = 0x1U,
    /**< General Purpose EVM */
    BOARD_EVMSK = 0x2U,
    /**< EVM - SK */
    BOARD_BEAGLEBONE = 0x3U,
    /**< Beagle Bone */
    BOARD_IDKEVM = 0x4U,
    /**< IDK EVM */
    BOARD_EPOSEVM = 0x5U,
    /**< EPOS EVM */
    BOARD_BEAGLEBONEBLACK = 0x6U,
    /**< Beagle Bone Black */
    BOARD_ICEV1 = 0x7U,
    /**< Industrial communications Engine Version 1 */
    BOARD_ICEV2 = 0x8U,
    /**< Industrial communications Engine Version 2 */
    BOARD_AMIC110 = 0x9U,
    /**< AMIC110 ICE board */
    BOARD_CUSTOM = 0x10U,
    /**< Any other custom board. */
    BOARD_MAX = BOARD_CUSTOM
    /**< Max board ID. */
} boardId_t;
#else
typedef enum boardId
{
    BOARD_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_UNKNOWN = BOARD_MIN,
    BOARD_AMIC110 = 1,
    /**< AMIC110 ICE board */
    BOARD_CUSTOM = 0x10U,
    /**< Any other custom board. */
    BOARD_MAX = BOARD_CUSTOM
    /**< Max board ID. */
} boardId_t;
#endif

/**
 *  \brief Board revision ID for GPEVM.
 */
typedef enum boardRevGpevm
{
    BOARD_REV_GPEVM_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_GPEVM_UNKNOWN = BOARD_REV_GPEVM_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_GPEVM_1_0X,
    /**< Board revision 1.0X. */
    BOARD_REV_GPEVM_1_1X,
    /**< Board revision 1.1X. */
    BOARD_REV_GPEVM_1_2X,
    /**< Board revision 1.2X. */
    BOARD_REV_GPEVM_1_5X,
    /**< Board revision 1.5X. */
    BOARD_REV_GPEVM_MAX = BOARD_REV_GPEVM_1_5X
    /**< Max board revision. */
} boardRevGpevm_t;

/**
 *  \brief Board revision ID for EVMSK.
 */
typedef enum boardRevEvmsk
{
    BOARD_REV_EVMSK_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_EVMSK_UNKNOWN = BOARD_REV_EVMSK_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_EVMSK_1_2X,
    /**< Board revision 1.2X. */
    BOARD_REV_EVMSK_1_3X,
    /**< Board revision 1.3X. */
    BOARD_REV_EVMSK_MAX = BOARD_REV_EVMSK_1_3X
    /**< Max board revision. */
} boardRevEvmsk_t;

/**
 *  \brief Board revision ID for BEAGLEBONE.
 */
typedef enum boardRevBeagleBone_t
{
    BOARD_REV_BEAGLEBONE_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_BEAGLEBONE_UNKNOWN = BOARD_REV_BEAGLEBONE_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_BEAGLEBONE_A1,
    /**< Board revision A1. */
    BOARD_REV_BEAGLEBONE_A2,
    /**< Board revision A2. */
    BOARD_REV_BEAGLEBONE_A3,
    /**< Board revision A3. */
    BOARD_REV_BEAGLEBONE_A5,
    /**< Board revision A6. */
    BOARD_REV_BEAGLEBONE_A6,
    /**< Board revision A6. */
    BOARD_REV_BEAGLEBONE_MAX = BOARD_REV_BEAGLEBONE_A6
    /**< Max board revision. */
} boardRevBeagleBone_t;

/**
 *  \brief Board revision ID for IDKEVM.
 */
typedef enum boardRevIdkevm
{
    BOARD_REV_IDKEVM_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_IDKEVM_UNKNOWN = BOARD_REV_IDKEVM_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_IDKEVM_1_0X,
    /**< Board revision 1.0X. */
    BOARD_REV_IDKEVM_MAX = BOARD_REV_IDKEVM_1_0X
    /**< Max board revision. */
} boardRevIdkevm_t;

/**
 *  \brief Board revision ID for EPOSEVM.
 */
typedef enum boardRevEposevm
{
    BOARD_REV_EPOSEVM_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_EPOSEVM_UNKNOWN = BOARD_REV_EPOSEVM_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_EPOSEVM_1_0X,
    /**< Board revision 1.0X. */
    BOARD_REV_EPOSEVM_1_1X,
    /**< Board revision 1.1X. */
    BOARD_REV_EPOSEVM_MAX = BOARD_REV_EPOSEVM_1_1X
    /**< Max board revision. */
} boardRevEposevm_t;

/**
 *  \brief Board revision ID for BEAGLEBONEBLACK.
 */
typedef enum boardRevBeagleBoneblack_t
{
    BOARD_REV_BEAGLEBONEBLACK_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_BEAGLEBONEBLACK_UNKNOWN = BOARD_REV_BEAGLEBONEBLACK_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_BEAGLEBONEBLACK_A4,
    /**< Board revision A4. */
    BOARD_REV_BEAGLEBONEBLACK_A6,
    /**< Board revision A6. */
    BOARD_REV_BEAGLEBONEBLACK_MAX = BOARD_REV_BEAGLEBONEBLACK_A6
    /**< Max board revision. */
} boardRevBeagleBoneblack_t;
/**
 *  \brief Board revision ID for Industrial Commn Eng Ver1 board.
 */
typedef enum boardRevIceV1
{
    BOARD_REV_ICEV1_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_ICEV1_UNKNOWN = BOARD_REV_ICEV1_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_ICEV1_A1,
    /**< Board revision A1. */
    BOARD_REV_ICEV1_A2,
    /**< Board revision A2. */
    BOARD_REV_ICEV1_A3,
    /**< Board revision A3. */
    BOARD_REV_ICEV1_A5,
    /**< Board revision A5. */
    BOARD_REV_ICEV1_A6,
    /**< Board revision A6. */
    BOARD_REV_ICEV1_MAX = BOARD_REV_ICEV1_A6
    /**< Max board revision. */
} boardRevIceV1_t;
/**
 *  \brief Board revision ID for Industrial Commn Eng Ver2 board.
 */
typedef enum boardRevIceV2
{
    BOARD_REV_ICEV2_MIN,
    /**< Should be the first value of this enumeration. */
    BOARD_REV_ICEV2_UNKNOWN = BOARD_REV_ICEV2_MIN,
    /**< Unknown/unsupported board revision. */
    BOARD_REV_ICEV2_A1,
    /**< Board revision A1. */
    BOARD_REV_ICEV2_A2,
    /**< Board revision A2. */
    BOARD_REV_ICEV2_A3,
    /**< Board revision A3. */
    BOARD_REV_ICEV2_A5,
    /**< Board revision A5. */
    BOARD_REV_ICEV2_A6,
    /**< Board revision A6. */
    BOARD_REV_ICEV2_MAX = BOARD_REV_ICEV2_A6
    /**< Max board revision. */
} boardRevIceV2_t;

/** This is added to avoid lcd_device.h dependency **/
typedef struct lcdDeviceBoardData lcdDeviceBoardData_t;

/**
 *  \brief Function pointer typedef for board initialization
 */
typedef int32_t (*BOARDInitFxn)(void);

/**
 *  \brief Function pointer typedef for device select function per board.
 */
typedef int32_t (*BOARDSelectDeviceFxn)(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief Function pointer typedef for device reset function per board.
 */
typedef int32_t (*BOARDResetDeviceFxn)(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief Function pointer typedef for device power on funtion per board.
 */
typedef int32_t (*BOARDPowerOnDeviceFxn)(uint32_t devId,
                                         uint32_t devInstNum,
                                         uint32_t powerOn);

/**
 *  \brief Function pointer typedef for initializing board specific lcd 
 *         parameters like pixel format and palete mode based on lcd device ID.
 */
typedef int32_t (*BOARDLcdDevDataFxn)(uint32_t lcdDevId, 
                                       lcdDeviceBoardData_t *pLcdDeviceBoardData);                                         
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Board initialization parameters.
 */
typedef struct boardInitParams
{
    boardId_t  boardId;
    /**< Override board ID detection. Set this to #BOARD_AUTO_DETECT to allow
     *   auto detection of the board connected. Setting any other value will
     *   override the auto detect and force the board ID to the supplied
     *   value.
     *   Allowed values are from enum #boardId_t, or #BOARD_AUTO_DETECT
     */
    uint32_t baseBoardRev;
    /**< Override base board revision detection. Set this to #BOARD_AUTO_DETECT
     *   to allow auto detection of base board revision. Setting any other
     *   value will override the auto detect and force the revision to the
     *   supplied value.
     *   The values to be used vary depending on the type of base board:
     *   - #boardRevGpevm_t
     *   - #boardRevEvmsk_t
     *   - #boardRevBeagleBone_t
     *   - #boardRevBeagleBoneblack_t
     */
    uint32_t dcBoardRev;
    /**< Override daughter card board revision detection. Set this to
     *   #BOARD_AUTO_DETECT to allow auto detection of DC board revision.
     *   Setting any other value will override the auto detect and force
     *   the revision to the supplied value.
     */
} boardInitParams_t;

/**
 *  \brief Board specific per instance I2C related data.
 */
typedef struct boardI2cInstData
{
    uint32_t instNum;
    /**< I2C controller number. */
    uint32_t baseAddr;
    /**< I2C peripheral base address. */
    uint32_t intNum;
    /**< I2C Interrupt number. */
    uint32_t busClkKHz;
    /**< I2C bus clock in KHz. */
} boardI2cInstData_t;

/**
 *  \brief Board specific data.
 */
typedef struct boardI2cData
{
    uint32_t             numInst;
    /**< Number of I2C instance to initialize. */
    boardI2cInstData_t * pInstData;
    /**< Pointer to #numInst number of I2C board data. */
    uint32_t             probeInstNum;
    /**< I2C instance to use for board detect. */
} boardI2cData_t;

/**
 *  \brief Board specific per instance device related data.
 */
typedef struct boardDeviceData
{
    uint32_t              devId;
    /**< Device ID. */
    uint32_t              devInstNum;
    /**< Device instance number - 0 to max-1 in a board. */
    chipdbModuleID_t      ctrlModId;
    /**<
     * ID of the SoC module to which the device is connected for controlling it.
     * Usually, this will be either I2C, SPI, or GPIO.
     */
    uint32_t              ctrlModInstNum;
    /**<
     * Instance number of the SoC module to which the device is connected for
     * controlling it.
     * Usually, this will be the instance number of I2C, SPI or GPIO on the SoC.
     */
    uint32_t              ctrlInfo;
    /**<
     * Connection information between the SoC module and the device. For example
     * - For I2C, it is the I2C slave address.
     * - For SPI, it is the Chip Select.
     * - For GPIO, it is the GPIO pin number.
     */
    chipdbModuleID_t      dataModId;
    /**<
     * ID of the SoC module the device has a data connection to.
     * For example, McASP sends data to the codec device. In that case, the
     * dataModId would be set to the ID for McASP.
     */
    uint32_t              dataModInstNum;
    /**<
     * Instance number of the SoC module the device has a data connection to.
     * For example, McASP sends data to the codec device. In that case, the
     * instance number of the McASP would be set as the dataModInstNum.
     */
    BOARDSelectDeviceFxn  pFnSelectDev;
    /**< Select device function pointer. This function will power on the
     *   device, do the device reset sequence and also enable any board level
     *   mux for the provided device. */
    BOARDResetDeviceFxn   pFnResetDev;
    /**< Reset device function pointer. This function will do the device reset
     *   sequence as per the board information. */
    BOARDPowerOnDeviceFxn pFnPowerOnDev;
    /**< Power On device function pointer. This function will do the Powering on
     *   the device as per the board information. */
} boardDeviceData_t;

/**
 *  \brief Board specific data.
 */
typedef struct boardData
{
    uint32_t                  numDev;
    /**< Number of devices connected to the board. */
    const boardDeviceData_t * pDevData;
    /**< Pointer to #numDev number of device data. */
    const pinmuxBoardCfg_t  * pPinmuxData;
    /**< Pointer to #pinmuxBoardCfg_t data. */
    uint32_t                  numRevStrings;
    /**< Number of board revision string names. */
    const char             ** pRevStringTable;
    /**< Pointer to board revision string names table. */
    dCards_t                 *pDCards;
    /**< Pointer to board supported daughter cards. */    
    BOARDInitFxn              pFnBoardInit;
    /**< Pointer to board specific initialization for lcd device. */
    BOARDLcdDevDataFxn        pFnBoardLcdDevData;
} boardData_t;

typedef struct lcdDeviceBoardData
{
    /**< Type of display either color or monochromatic. This can take values
         from the following enum #lcdcRasterDisplayType_t. */
    uint32_t pixelFormat;
    /**< Input pixel format. This can take values from the following enum
         #lcdcPixelFormat_t. */
    uint32_t paletteMode;
}lcdDeviceBoardData_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/** \brief Provides defaults for board initialization parameters. */
extern const boardInitParams_t BOARDINITPARAMS_DEFAULT;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  Initialize the underlying board. Based on the type of SoC and board,
 *          this function does software initializations required for the current
 *          board. It does not actually do any initialization at the hardware
 *          level.
 *
 *  \param  pInitPrms   Board Initialization parameters. If passed as NULL,
 *                      default parameters are internally used.
 *                      Parameter pInitPrms is of type #boardInitParams_t
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t BOARDInit(const boardInitParams_t *pInitPrms);

/**
 *  \brief  De-init the underlying board. It performs any software level
 *          cleanup for the board module if required.
 *
 *  \param  args        Not used currently. Set to NULL.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t BOARDDeInit(void * args);

/**
 *  \brief  Probes and returns board ID. Usually the board data is read from
 *          EEPROM device.
 *
 *  \retval Board_ID        On success
 *  \retval BOARD_UNKNOWN   On failure, or if board ID is not known.
 *                          The following cases can potentially cause this
 *                          value to be returned:
 *                          - EEPROM device not connected / not ready
 *                          - Board information not present within EEPROM
 *                          - Board information in EEPROM does not match
 *                            known boards.
 */
boardId_t BOARDGetId(void);

/**
 *  \brief  Function to get the name of the board in printable string.
 *
 *  \retval Board_name  Returns a const pointer to the name. If the board is
 *                      not known, then it returns the string as "UNKNOWN".
 */
const char * BOARDGetBoardName(void);

/**
 *  \brief  Returns the base board revision.
 *
 *  \retval Base_board_revision On success, returns the base board revision.
 *                              Based on the type of board, the revision
 *                              value returned needs to be interpreted.
 *  \retval BOARD_REV_UNKNOWN   On failure, or if board rev ID is not known.
 *                              The following cases can potentially cause this
 *                              value to be returned:
 *                              - EEPROM device not connected / not ready
 *                              - Board information not present within EEPROM
 *                              - Board information in EEPROM does not match
 *                                known boards.
 */
uint32_t BOARDGetBaseBoardRev(void);

/**
 *  \brief  Function to get the name of the base board revision in printable
 *          string.
 *
 *  \retval Board_rev_string    Returns a const pointer to the string. If the
 *                              board revision is not known, then it returns the
 *                              string as "UNKNOWN".
 */
const char * BOARDGetBaseBoardRevName(void);

/**
 *  \brief  Returns the add-on or daughter card board revision.
 *
 *  \retval DC_Revision     On success, returns the add-on or daughter card
 *                          revision. Based on the type of board, the revision
 *                          value returned needs to be interpreted.
 */
uint32_t BOARDGetDcRev(void);

/**
 *  \brief  Function to get the name of the daughter card revision in printable
 *          string.
 *
 *  \retval Board_dcrev_string  Returns a const pointer to the string. If the
 *                              board daughter card revision is not known, then
 *                              it returns the string as "UNKNOWN".
 */
const char * BOARDGetDcRevName(void);

/**
 *  \brief  Returns I2C data.
 *
 *  \retval Board_I2C_Data      Board I2C data on success
 *  \retval NULL                On Failure
 */
const boardI2cData_t * BOARDGetI2cData(void);

/**
 *  \brief  Returns board specific data.
 *
 *  \retval Board_Data          Board data on success
 *  \retval NULL                On Failure
 */
const boardData_t * BOARDGetData(void);

/**
 *  \brief  Checks if the specified device is present on the board.
 *
 *  \param  devId        Device ID to get the information for.
 *
 *  \retval TRUE                   If device is present on the board
 *  \retval FALSE                  If device is not present on the board
 */
uint32_t BOARDIsDevicePresent(uint32_t devId);

/**
 *  \brief  Returns the number of instances of the specified device present on
 *          the board.
 *
 *  \param  devId        Device ID to get the information for.
 *
 *  \retval Num_Devices  If device is present on the board, returns the number
 *                       of instances of the device on the board.
 *  \retval 0            If device is not present on the board
 */
uint32_t BOARDGetNumDevices(uint32_t devId);

/**
 *  \brief  Returns the ID of the SoC module to which the device is connected
 *          for controlling it. Usually, this will be either I2C, SPI, or GPIO.s
 *
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval SoC_Ctrl_Mod_ID        If found, returns the SoC module ID which is
 *                                 used for controlling this device.
 *  \retval CHIPDB_MOD_ID_INVALID  If device is not found, returns invalid
 *                                 module ID.
 */
chipdbModuleID_t BOARDGetDeviceCtrlModId(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Returns the instance number of the SoC module to which the device is
 *          connected for controlling it. Usually, this will be the instance
 *          number of I2C, SPI or GPIO on the SoC.
 *
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval Ctrl_mod_inst_num       If device is found, returns the instance
 *                                  number of the SoC module to which the device
 *                                  is connected for controlling it.
 *  \retval INVALID_INST_NUM        If device is not found.
 */
uint32_t BOARDGetDeviceCtrlModInstNum(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Returns the connection information between the SoC module used for
 *          controlling the device, and the device. For example:
 *          - For I2C, it is the I2C slave address.
 *          - For SPI, it is the Chip Select.
 *          - For GPIO, it is the GPIO pin number.
 *
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval Control_information         If device is found
 *  \retval INVALID_INFO                If device is not found. INVALID_INFO is
 *                                      also returned if no relevant info is
 *                                      present, as may be the case if the
 *                                      module does not require any additional
 *                                      information for controlling the device.
 */
uint32_t BOARDGetDeviceCtrlInfo(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Returns the ID of the SoC peripheral the device has a data
 *          connection to. For example, McASP sends data to the codec device.
 *          In that case, the dataModId would be set to the ID for McASP.
 *
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval SoC_Data_Mod_ID        If found, returns the SoC module ID which is
 *                                 used for data transfer to/from this device.
 *  \retval CHIPDB_MOD_ID_INVALID  If device is not found, returns invalid
 *                                 module ID.
 */
chipdbModuleID_t BOARDGetDeviceDataModId(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Returns the instance number of the SoC module the device has a data
 *          connection to. For example, McASP sends data to the codec device.
 *          In that case, the instance number of the McASP would be returned as
 *          the dataModInstNum for that device.
 *
 *  \param  devId        Device ID to get the information for.
 *  \param  devInstNum   Device instance number to get the information for. Used
 *                       when multiple devices are present on a board.
 *
 *  \retval Data_mod_inst_num       If device is found, returns the instance
 *                                  number of the SoC module that has a data
 *                                  connection to this device.
 *  \retval INVALID_INST_NUM        If device is not found, or if no
 *                                  relevant information is present.
 */
uint32_t BOARDGetDeviceDataModInstNum(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Perform Power On for the provided device through GPIO or I2C IO
 *          expander. If Power On is not needed this function returns success
 *          without reporting error.
 *
 *  \param  devId        Device ID to power-on.
 *  \param  devInstNum   Device instance number. Used when multiple devices are
 *                       present in a board.
 *  \param  powerOn      TRUE - power on, FALSE - power down
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t BOARDPowerOnDevice(uint32_t devId,
                           uint32_t devInstNum,
                           uint32_t powerOn);

/**
 *  \brief  Enable board level mux for the provided device.
 *          If no muxing is needed, this function returns success without
 *          reporting error.
 *
 *  \param  devId        Device ID to select.
 *  \param  devInstNum   Device instance number. Used when multiple devices are
 *                       present in a board.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t BOARDSelectDevice(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Perform reset for the provided device through GPIO or I2C IO
 *          expander. If reset is not needed this function returns success
 *          without reporting error.
 *
 *  \param  devId        Device ID to reset.
 *  \param  devInstNum   Device instance number. Used when multiple devices are
 *                       present in a board.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t BOARDResetDevice(uint32_t devId, uint32_t devInstNum);

/**
 *  \brief  Funtion to print all the board information like board type,
 *          board revision etc...
 */
void BOARDPrintInfo(void);

/**
 *  \brief  Returns board specific daughter cards' data.
 *
 *  \retval Board_Data          Daughter cards' data
 *  \retval NULL                On Failure
 */
dCards_t * BOARDGetDCardsData(void);

/**
 *  \brief  Checks if the specified daughter card is present on the board.
 *
 *  \param  dCardId        Daughter Card ID
 *
 *  \retval TRUE           If daughter card is present for the board
 *  \retval FALSE          If daughter card is not present for the board
 */
uint32_t BOARDIsDCardPresent(uint32_t dCardId);

/**
 *  \brief  This function initializes board specific lcd 
 *         parameters like pixel format and palete mode based on lcd device ID. 
 *
 *  \param  lcdDevId                Lcd device ID.
 *  \param  pLcdDeviceBoardData     Pointer to the board specific LCD data.
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure 
 */                                                                 
int32_t BOARDGetLcdDevData(uint32_t lcdDevId, 
                           lcdDeviceBoardData_t *pLcdDeviceBoardData);
/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif  /* #ifndef BOARD_H_ */
