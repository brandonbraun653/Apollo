/**
 * \file       dcan.h
 *
 * \brief      This file contains the function prototypes for the device
 *             abstraction layer of DCAN. It also contains necessary
 *             structure, enum and macro definitions.
 *
 * \details    Programming sequence of DCAN is as follows:
 *             -# Initialization and configuration
 *                -# Configure the system clocks for DCAN peripheral.
 *                -# Perform pinmux for DCAN Tx and Rx pins.
 *                -# Configure the DCAN message RAM.
 *                -# Place the DCAN in software reset by calling the
 *                   API DCANReset.
 *                -# Place DCAN in initialization mode by calling the
 *                   API DCANSetMode.
 *                -# Configure the bit-time value of DCAN by calling
 *                   the API DCANBitTimeConfig.
 *                -# To enable acceptance filtering for a receive message object
 *                   DCANAcceptanceMaskEnable and DCANMsgObjectMaskConfig
 *                   APIs can be used.
 *                -# Invalidate a message object by calling the API
 *                   DCANInvalidateMsgObj.
 *                -# Validate a message object by calling the API
 *                   DCANValidateMsgObj.
 *                -# Program the command register by calling the API
 *                   DCANSetCommand.
 *                -# Set the DCAN message ID by calling the API DCANSetMsgId.
 *                   Configure a receive message object with ID = 0,
 *                   if CAN frames of any valid IDs(Standard/Extended) should
 *                   be accepted.
 *                -# Set the DCAN message direction by calling the API
 *                   DCANSetMsgDirection.
 *                -# Set the DCAN data length code by calling the API
 *                   DCANSetDataLengthCode.
 *                -# Program the DCAN data to be transmitted by calling the API
 *                   DCANWriteData.
 *                -# Fifo end of block feature can be enabled/disabled by
 *                   calling the API DCANFifoEndOfBlockEnable.
 *                -# Read the DCAN transmit request status by calling the API
 *                   DCANTxRqstLeastMsgObjStatus.
 *                -# Check the message valid status of a message object by
 *                   calling the API DCANMsgValidStatus.
 *                -# DCAN test modes can be enabled by calling the API
 *                   DCANTestModeEnable.
 *                -# Enable/disable the auto bus on feature by calling the API
 *                   DCANAutoBusOnEnable.
 *                -# Configure the auto bus on time value by calling the API
 *                   DCANSetAutoBusOnTimeVal.
 *                -# Read the DCAN message object data by calling the API
 *                   DCANReadData.
 *                -# DCAN interrupts can be enabled by calling the
 *                   API DCANIntrEnable.
 *                -# DCAN interrupt lines can be enabled by calling the API
 *                   DCANIntrLineEnable.
 *                -# Enable the DCAN message object interrupts by calling the API
 *                   DCANMsgObjIntrEnable.
 *                -# DCAN interrupt status can be read by calling the
 *                   API DCANIntrStatus.
 *                -# Error and status information can be read by calling the API
 *                   DCANGetErrorStatus.
 *                -# Enable/Disable the auto bus on feature by calling the API
 *                   DCANAutoBusOnEnable.
 *                -# Read the received CAN data by calling the API DCANReadData.
 *             -# Communication
 *                -# Place DCAN in normal mode of operation by calling the API
 *                   DCANSetMode.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

#ifndef DCAN_H_
#define DCAN_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_dcan.h"
#include "misc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define	DCANIntEnable                 DCANIntrEnable
#define	DCANIntDisable                DCANIntrDisable
#define	DCANIntRegStatusGet           DCANIntrStatus
#define	DCANErrAndStatusRegInfoGet    DCANErrorAndStatusInfoGet
#define	DCANErrCntrRegStatusGet       DCANErrorCounterStatus
#define	DCANParityErrCdRegStatusGet   DCANParityErrorStatus
#define	DCANAutoBusOnTimeValSet       DCANSetAutoBusOnTimeVal
#define	DCANAutoBusOnTimeValGet       DCANGetAutoBusOnTimeVal
#define	DCANTxRqstXStatusGet          DCANTxRequestXStatus
#define	DCANTxRqstStatusGet           DCANTxRequestStatus
#define	DCANTxRqstStatGet             DCANTxRqstLeastMsgObjStatus
#define	DCANNewDataXStatusGet         DCANNewDataXStatus
#define	DCANNewDataStatusGet          DCANNewDataStatus
#define	DCANNewDataStatGet            DCANNewDataLeastMsgObjStatus
#define	DCANIntPendingXStatusGet      DCANIntrPendingXStatus
#define	DCANIntPendingStatusGet       DCANIntrPendingStatus
#define	DCANMsgValidXStatusGet        DCANMsgValidXStatus
#define	DCANMsgValidStatusGet         DCANMsgValidStatus
#define	DCANMsgObjValidate            DCANValidateMsgObj
#define	DCANCommandRegSet             DCANSetCommand
#define	DCANMsgIdSet                  DCANSetMsgId
#define	DCANMsgDirectionSet           DCANSetMsgDirection
#define	DCANDataWrite                 DCANWriteData
#define	DCANDataRead                  DCANReadData
#define	DCANDataLengthCodeSet         DCANSetDataLengthCode
#define	DCANMsgObjIntEnable           DCANMsgObjIntrEnable
#define	DCANMsgObjIntDisable          DCANMsgObjIntrDisable
#define	DCANMsgObjectMskConfig        DCANMsgObjectMaskConfig
#define	DCANIF3RegUpdateEnableSet     DCANSetIf3RegUpdateEnable
#define	DCANIF3ObservationFlagSet     DCANSetIf3ObservationSet
#define	DCANIF3ObservationFlagClear   DCANClearIf3Observation
#define	DCANIF3ObservationFlagStatGet DCANIf3ObservationStatus
#define	DCANIFMaskStatusGet           DCANIfMaskStatus
#define	DCANIFArbStatusGet            DCANIfArbitrationStatus
#define	DCANClrIntPnd                 DCANClearPendingIntr
#define	DCANUseAcceptanceMaskControl  DCANAcceptanceMaskEnable
#define	DCANTransmitRequestControl    DCANTransmitRequestEnable
#define	DCANNewDataControl            DCANNewDataConfig
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \name    Macros to read status.
 */

/** @{ */
/** \brief Read the DCAN TXRQ_X register status where
 *         1 <= n <= 8 can take these values.
 */
#define DCAN_TXRQST_X_REG(n)                (DCAN_TXRQ_X_TXRQSTREG1 <<  \
                                            (((n) - 1) * 2))

/** \brief Read the DCAN NEWDATA_X register status where
 *         1 <= n <= 8 can take these values.
 */
#define DCAN_NEWDAT_X_REG(n)                (DCAN_NWDAT_X_NEWDATREG1 << \
                                            (((n) - 1) * 2))

/** \brief Read the DCAN INTPND_X register status where
 *         1 <= n <= 8 can take these values.
 */
#define DCAN_INTRPEND_X_REG(n)              (DCAN_INTPND_X_INTPNDREG1 << \
                                            (((n) - 1) * 2))

/** \brief Read the DCAN MSGVAL_X register status where
 *         1 <= n <= 8 can take these values.
 */
#define DCAN_MSGVAL_X_REG(n)                (DCAN_MSGVAL_X_MSGVALREG1 << \
                                            (((n) - 1) * 2))
/** @} */


/**
 * \name    Macros used to configure the DCAN message object mask.
 */

/** @{ */
/** \brief Macros used to configure the Mask values to either 11 or 29 bit.
 *         Values that can be passed to 'DCAN_IDENTIFIER_MASK' macro as idType.
 */
#define DCAN_ID_MASK_11_BIT                  (18U)
#define DCAN_ID_MASK_29_BIT                  (0U)

/** \brief Macros used to configure the Mask values.
 *         'mask' can take values between 0 <= mask <= 0x1FFFFFFF
 *         'idType' can take the following values
 *         DCAN_ID_MASK_11_BIT - 11 bit identifier is used
 *         DCAN_ID_MASK_29_BIT - 29 bit identifier is used
 */
#define DCAN_IDENTIFIER_MASK(mask, idType)  (mask << idType)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief    Enumerates the values used to represent the DCAN mode of
 *            operation.
 */
typedef enum dcanMode
{
    DCAN_MODE_INIT = DCAN_CTL_INIT_INITMODE,
    /**< DCAN initialization mode. */
    DCAN_MODE_NORMAL = DCAN_CTL_INIT_NORMALOP
    /**< DCAN normal mode. */
} dcanMode_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN interrupts.
 */
typedef enum dcanIntrMask
{
    DCAN_INTR_MASK_ERROR = DCAN_CTL_EIE_MASK,
    /**< DCAN error interrupt mask. */
    DCAN_INTR_MASK_STATUS_CHANGE = DCAN_CTL_SIE_MASK
    /**< DCAN status change interrupt mask. */
} dcanIntrMask_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN interrupt lines.
 */
typedef enum dcanIntrLineNum
{
    DCAN_INTR_LINE_NUM_0 = 0U,
	/**< DCAN interrupt line 0. */
	DCAN_INTR_LINE_NUM_1 = 1U
	/**< DCAN interrupt line 1. */
} dcanIntrLineNum_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN interface
 *            registers.
 */
typedef enum dcanIfRegNum
{
    DCAN_IF_REG_NUM_1 = 1U,
	/**< DCAN IF register number 1. */
	DCAN_IF_REG_NUM_2 = 2U,
	/**< DCAN IF register number 2. */
	DCAN_IF_REG_NUM_3 = 3U
	/**< DCAN IF register number 3. */
} dcanIfRegNum_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN error and status
 *            values.
 */
typedef enum dcanStsErrCodeMask
{
    DCAN_STS_ERR_CODE_MASK_NO_ERROR = DCAN_ES_LEC_NOERROR,
	/**< LEC error code = No error. */
	DCAN_STS_ERR_CODE_MASK_STUFF_ERROR = DCAN_ES_LEC_STUFFERROR,
	/**< LEC error code = Stuff error. */
	DCAN_STS_ERR_CODE_MASK_FORM_ERROR = DCAN_ES_LEC_FORMERROR,
	/**< LEC error code = Form error. */
	DCAN_STS_ERR_CODE_MASK_ACK_ERROR = DCAN_ES_LEC_ACKERROR,
	/**< LEC error code = Ack error. */
	DCAN_STS_ERR_CODE_MASK_BIT1_ERROR = DCAN_ES_LEC_BIT1ERROR,
	/**< LEC error code = Bit1 error. */
	DCAN_STS_ERR_CODE_MASK_BIT0_ERROR = DCAN_ES_LEC_BIT0ERROR,
	/**< LEC error code = Bit0 error. */
	DCAN_STS_ERR_CODE_MASK_CRC_ERROR = DCAN_ES_LEC_CRCERROR,
	/**< LEC error code = CRC error. */
	DCAN_STS_ERR_CODE_MASK_NO_EVENT = DCAN_ES_LEC_NOEVENT,
	/**< LEC error code = No event detected. */
	DCAN_STS_ERR_CODE_MASK_TX_OK = DCAN_ES_TXOK_MASK,
	/**< DCAN transmitted a message successfully. */
	DCAN_STS_ERR_CODE_MASK_RX_OK = DCAN_ES_RXOK_MASK,
	/**< DCAN received a message successfully. */
	DCAN_STS_ERR_CODE_MASK_ERROR_PASSIVE = DCAN_ES_EPASS_MASK,
	/**< DCAN is in Error passive state. */
	DCAN_STS_ERR_CODE_MASK_ERROR_WARNING = DCAN_ES_EWARN_MASK,
	/**< DCAN has crossed the error warning limit. */
	DCAN_STS_ERR_CODE_MASK_BUS_OFF = DCAN_ES_BOFF_MASK,
	/**< DCAN is in bus-off state. */
	DCAN_STS_ERR_CODE_MASK_PARITY_ERROR = DCAN_ES_PER_MASK,
	/**< Parity error is detected. */
	DCAN_STS_ERR_CODE_MASK_WAKEUP_PENDING = DCAN_ES_WAKEUPPND_MASK,
	/**< Wakeup pending. */
	DCAN_STS_ERR_CODE_MASK_POWER_DOWN = DCAN_ES_PDA_MASK
	/**< DCAN is in local power down mode. */
} dcanStsErrCodeMask_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN error counter
 *            register values.
 */
typedef enum dcanCntrMask
{
    DCAN_CNTR_MASK_TX_ERROR = DCAN_ERRC_TEC_MASK,
	/**< DCAN transmit error counter mask. */
	DCAN_CNTR_MASK_RX_ERROR = DCAN_ERRC_REC_MASK,
	/**< DCAN receive error counter mask. */
	DCAN_CNTR_MASK_RX_ERROR_PASSIVE = DCAN_ERRC_RP_MASK
	/**< DCAN receive error passive. */
} dcanCntrMask_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN test modes.
 */
typedef enum dcanTestModeMask
{
    DCAN_TEST_MODE_MASK_SILENT = DCAN_TEST_SILENT_MASK,
	/**< DCAN Silent test mode. */
	DCAN_TEST_MODE_MASK_LPBACK = DCAN_TEST_LBACK_MASK,
	/**< DCAN loopback test mode. */
	DCAN_TEST_MODE_MASK_LPBACK_SILENT = (DCAN_TEST_SILENT_MASK | \
	                                     DCAN_TEST_LBACK_MASK),
    /**< DCAN loopback with silent test mode. */
	DCAN_TEST_MODE_MASK_EXT_LPBACK = DCAN_TEST_EXL_MASK,
	/**< DCAN external loopback test mode. */
	DCAN_TEST_MODE_MASK_RAM_DIRECT_ACCESS = DCAN_TEST_RDA_MASK
    /**< DCAN RAM direct access test mode. */
} dcanTestModeMask_t;

/**
 *  \brief    Enumerates the values used to represent the DCAN parity error
 *            status.
 */
typedef enum dcanParityErrSts
{
    DCAN_PARITY_ERR_STS_MSG_NUM = DCAN_PERR_MESSAGE_NUMBER_MASK,
	/**< Mask used to deduce the message number which caused the Parity
         error. */
	DCAN_PARITY_ERR_STS_WORD_NUM = DCAN_PERR_WORD_NUMBER_MASK,
	/**< Mask used to deduce the word number which caused the Parity
         error. */
} dcanParityErrSts_t;

/**
 *  \brief    Enumerates the command values used to configure the DCAN
 *            command register.
 */
typedef enum dcanCmd
{
    DCAN_CMD_DMA_ACTIVE = DCAN_IFCMD_DMAACTIVE_MASK,
    /**< Enable DMA feature. */
    DCAN_CMD_DAT_A_ACCESS = DCAN_IFCMD_DATAA_MASK,
	/**< Access data from IF DataA register. */
    DCAN_CMD_DAT_B_ACCESS = DCAN_IFCMD_DATAB_MASK,
    /**< Access data from IF dataB register. */
    DCAN_CMD_TXRQST_ACCESS = DCAN_IFCMD_TXRQST_NEWDAT_MASK,
    /**< Access the TxRqst bit. */
    DCAN_CMD_CLR_INTPND = DCAN_IFCMD_CLRINTPND_MASK,
    /**< Clear the interrupt pending bit. */
    DCAN_CMD_ACCESS_CTL_BITS = DCAN_IFCMD_CONTROL_MASK,
    /**< Access control bits. */
    DCAN_CMD_ACCESS_ARB_BITS = DCAN_IFCMD_ARB_MASK,
    /**< Access arbitration bits. */
    DCAN_CMD_ACCESS_MSK_BITS = DCAN_IFCMD_MASK_MASK,
    /**< Access mask bits. */
    DCAN_CMD_MSG_WRITE = DCAN_IFCMD_WR_RD_MASK,
    /**< Transfer direction is from IF registers to message RAM. */
    DCAN_CMD_MSG_READ = 0x00000000U
	/**< Transfer direction is from message RAM to IF registers. */
} dcanCmd_t;

/**
 *  \brief    Enumerates the DCAN ID length.
 */
typedef enum dcanIdLength
{
    DCAN_ID_LENGTH_11_BIT = DCAN_IFARB_XTD_11_BIT,
	/**< DCAN ID length is 11 bit long. */
    DCAN_ID_LENGTH_29_BIT = DCAN_IFARB_XTD_29_BIT
	/**< DCAN ID length is 29 bit long. */
} dcanIdLength_t;

/**
 *  \brief    Enumerates the DCAN message transfer direction.
 */
typedef enum dcanMsgDir
{
    DCAN_MSG_DIR_TX = DCAN_IFARB_DIR_TRANSMIT,
	/**< DCAN transmit message. */
    DCAN_MSG_DIR_RX = DCAN_IFARB_DIR_RECEIVE
	/**< DCAN receive message. */
} dcanMsgDir_t;

/**
 *  \brief    Enumerates the DCAN message object interrupt type.
 */
typedef enum dcanMsgObjIntrMask
{
    DCAN_MSG_OBJ_INTR_MASK_TX = DCAN_IFMCTL_TXIE_MASK,
	/**< DCAN message object transmit interrupt mask value. */
	DCAN_MSG_OBJ_INTR_MASK_RX = DCAN_IFMCTL_RXIE_MASK
	/**< DCAN message object receive interrupt mask value. */
} dcanMsgObjIntrMask_t;

/**
 *  \brief    Enumerates the values used to configure the mask for message
 *            direction.
 */
typedef enum dcanMsgDirMask
{
    DCAN_MSG_DIR_MASK_USED = (DCAN_IFMSK_MDIR_USED << DCAN_IFMSK_MDIR_SHIFT),
	/**< DCAN message direction mask used. */
	DCAN_MSG_DIR_MASK_NOT_USED = (DCAN_IFMSK_MDIR_NOTUSED <<
                                  DCAN_IFMSK_MDIR_SHIFT)
	/**< DCAN message direction mask not used. */
} dcanMsgDirMask_t;

/**
 *  \brief    Enumerates the values used to configure the mask for extended
 *            identifier.
 */
typedef enum dcanExtIdMask
{
    DCAN_EXT_ID_MASK_USED = (DCAN_IFMSK_MXTD_USED << DCAN_IFMSK_MXTD_SHIFT),
	/**< DCAN extended identifier mask used. */
	DCAN_EXT_ID_MASK_NOT_USED = (DCAN_IFMSK_MXTD_NOTUSED <<
                                 DCAN_IFMSK_MXTD_SHIFT)
	/**< DCAN extended identifier mask not used. */
} dcanExtIdMask_t;

/**
 *  \brief    Enumerates the values used to configure the mask values
 *            for observation fields.
 */
typedef enum dcanObsFieldMask
{
    DCAN_OBS_FIELD_MASK = DCAN_IF3OBS_MASK_MASK,
	/**< DCAN Mask data read observation. */
    DCAN_OBS_FIELD_ARB = DCAN_IF3OBS_ARB_MASK,
	/**< DCAN arbitration data read observation. */
    DCAN_OBS_FIELD_CTRL = DCAN_IF3OBS_CTRL_MASK,
	/**< DCAN control read observation. */
    DCAN_OBS_FIELD_DAT_A = DCAN_IF3OBS_DATAA_MASK,
	/**< DCAN DATA A read observation. */
    DCAN_OBS_FIELD_DAT_B = DCAN_IF3OBS_DATAB_MASK
	/**< DCAN DATA B read observation. */
} dcanObsFieldMask_t;

/**
 *  \brief    Enumerates the values used to read the DCAN
 *            observation status.
 */
typedef enum dcanObsSts
{
    DCAN_OBS_STS_MASK = DCAN_IF3OBS_IF3SM_MASK,
	/**< DCAN observation mask status. */
	DCAN_OBS_STS_ARB = DCAN_IF3OBS_IF3SA_MASK,
	/**< DCAN observation arbitration status. */
	DCAN_OBS_STS_CTRL = DCAN_IF3OBS_IF3SC_MASK,
	/**< DCAN observation control status. */
	DCAN_OBS_STS_DATA_A = DCAN_IF3OBS_IF3SDA_MASK,
	/**< DCAN observation data A status. */
	DCAN_OBS_STS_DATA_B = DCAN_IF3OBS_IF3SDB_MASK,
	/**< DCAN observation data B status. */
	DCAN_OBS_STS_UPDATE = DCAN_IF3OBS_IF3UPD_MASK
	/**< DCAN observation update status. */
} dcanObsSts_t;

/**
 *  \brief    Enumerates the values used to read the DCAN
 *            mask status.
 */
typedef enum dcanMaskSts
{
    DCAN_MASK_STS_MASK = DCAN_IF3MSK_MSK_MASK,
    /**< DCAN Mask status. */
	DCAN_MASK_STS_MSG_DIR = DCAN_IF3MSK_MDIR_MASK,
    /**< DCAN Mask message direction status. */
	DCAN_MASK_STS_EXT_ID = DCAN_IF3MSK_MXTD_MASK
	/**< DCAN Mask extended ID status. */
} dcanMaskSts_t;

/**
 *  \brief   Enumerates the values used to read the DCAN
 *           arbitration status.
 */
typedef enum dcanArbSts
{
    DCAN_ARB_STS_MSG_ID = DCAN_IF3ARB_MSK_MASK,
	/**< DCAN arbitration status message identifier. */
    DCAN_ARB_STS_MSG_DIR = DCAN_IF3ARB_DIR_MASK,
	/**< DCAN arbitration status message direction. */
    DCAN_ARB_STS_EXT_ID = DCAN_IF3ARB_XTD_MASK,
	/**< DCAN arbitration status extended identifier. */
    DCAN_ARB_STS_MSG_VALID = DCAN_IF3ARB_MSGVAL_MASK
	/**< DCAN arbitration status message valid. */
} dcanArbSts_t;

/**
 *  \brief   Enumerates the values used to read the DCAN
 *           message control status.
 */
typedef enum dcanMsgCtlSts
{
    DCAN_MSG_CTL_STS_DAT_LEN_CODE = DCAN_IF3MCTL_DATALENGTHCODE_MASK,
	/**< DCAN data length code status. */
    DCAN_MSG_CTL_STS_END_OF_BLOCK = DCAN_IF3MCTL_EOB_MASK,
    /**< DCAN end of block status. */
    DCAN_MSG_CTL_STS_TXRQST = DCAN_IF3MCTL_TXRQST_MASK,
	/**< DCAN transmit request status. */
    DCAN_MSG_CTL_STS_RMT_ENABLE = DCAN_IF3MCTL_RMTEN_MASK,
	/**< DCAN remote enable status. */
    DCAN_MSG_CTL_STS_RX_INTR_ENABLE = DCAN_IF3MCTL_RXIE_MASK,
	/**< DCAN receive interrupt enable status. */
    DCAN_MSG_CTL_STS_TX_INTR_ENABLE = DCAN_IF3MCTL_TXIE_MASK,
	/**< DCAN transmit interrupt enable status. */
    DCAN_MSG_CTL_STS_UMASK = DCAN_IF3MCTL_UMASK_MASK,
	/**< DCAN Use acceptance mask status. */
    DCAN_MSG_CTL_STS_INTR_PND = DCAN_IF3MCTL_INTPND_MASK,
	/**< DCAN interrupt pending status. */
    DCAN_MSG_CTL_STS_MSG_LOST = DCAN_IF3MCTL_MSGLST_MASK,
	/**< DCAN message lost status. */
    DCAN_MSG_CTL_STS_NEW_DATA = DCAN_IF3MCTL_NEWDAT_MASK
} dcanMsgCtlSts_t;

/**
 *  \brief   Enumerates the values used to configure the DCAN
 *           new data values.
 */
typedef enum dcanNewDataCfg
{
    DCAN_NEW_DATA_CFG_SET = DCAN_IFMCTL_NEWDAT_NEWDATA,
	/**< Set the DCAN new data bit. */
	DCAN_NEW_DATA_CFG_CLR = DCAN_IFMCTL_NEWDAT_NONEWDATA
    /**< Clear the DCAN new data bit. */
} dcanNewDataCfg_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Reset DCAN.
 *
 * \param     baseAddr       Memory Address of the DCAN instance used.
 */
void DCANReset(uint32_t baseAddr);

/**
 * \brief     Configure the operating mode of DCAN.
 *
 * \details   This API can be called to configure DCAN in Normal/Init mode.
 *            In Init mode the communication on CAN bus is stopped and the
 *            controller needs to be placed in Init mode for initialization.
 *            To start communication on CAN bus please keep the DCAN controller
 *            in Normal mode of operation.
 *
 * \param     baseAddr       Memory Address of the DCAN instance used.
 * \param     mode           DCAN mode to be configured
 *            mode will contain values from the following enum.
 *            #dcanMode_t
 */
void DCANSetMode(uint32_t baseAddr, uint32_t mode);

/**
 * \brief     Configure the DCAN bit-time value.
 *
 * \param     baseAddr       Memory Address of the DCAN instance used.
 * \param     bitTimeVal     Bit-Time register value.
 *
 * \note      To configure CAN bit timing the DCAN controller should be in
 *            initialization mode.
 *            8 MHz is the minimum CAN clock frequency required to operate
 *            the DCAN at a bit rate of 1MBits/s.
 */
void DCANBitTimeConfig(uint32_t baseAddr, uint32_t bitTimeVal);

/**
 * \brief     Enable the interrupts of DCAN.
 *
 * \param     baseAddr       Memory Address of the DCAN instance used.
 * \param     intrMask       DCAN interrupts to be enabled.
 *            intrMask can take values from the following enum.
 *            #dcanIntrMask_t
 */
void DCANIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief     Disable the interrupts of DCAN.
 *
 * \param     baseAddr       Memory Address of the DCAN instance used.
 * \param     intrMask       DCAN interrupts to be disabled.
 *            intrMask can take values from the following enum.
 *            #dcanIntrMask_t
 */
void DCANIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief     Enable/disable the DCAN interrupt lines.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     intrLineNum      DCAN interrupt line number.
 *            intrLineNum can take values from the following enum.
 *            #dcanIntrLineNum_t
 * \param     enableIntrLine   Enable/disable DCAN interrupt line.
 *            enableIntrLine will take the following values.
 *            -# TRUE - Enable DCAN interrupt line.
 *            -# FALSE - Disable DCAN interrupt line.
 *
 * \note      The Error and Status change interrupts can only be routed to
 *            DCANINT0 line and message object interrupts can be routed to
 *            both lines. Hence DCANINT0 line has to be enabled if error and
 *            status change interrupts have to be serviced.
 */
void DCANIntrLineEnable(uint32_t baseAddr,
                        uint32_t intrLineNum,
                        uint32_t enableIntrLine);

/**
 * \brief     Enable/disable the DCAN DMA request line.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 * \param     enableDmaReq     Enable/disable DMA request line.
 *            enableDmaReq will take the following values.
 *            -# TRUE - Enable DMA request.
 *            -# FALSE - Disable DMA request.
 *
 */
void DCANDmaRequestLineEnable(uint32_t baseAddr,
                              uint32_t ifRegNum,
                              uint32_t enableDmaReq);

/**
 * \brief     Set/Configure the DCAN command register.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     command          Commands to be configured
 *            command can take values from the following enum
 *            #dcanCmd_t.
 * \param     msgObjNum        Message object to be configured.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANSetCommand(uint32_t baseAddr,
                    uint32_t command,
                    uint32_t msgObjNum,
					uint32_t ifRegNum);

/**
 * \brief     Set the DCAN message ID.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgId            CAN message ID.
 * \param     idLength         CAN message ID length.
 *            idLength can take values from the following enum.
 *            #dcanIdLength_t.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANSetMsgId(uint32_t baseAddr,
                  uint32_t msgId,
                  uint32_t idLength,
				  uint32_t ifRegNum);

/**
 * \brief     Set the DCAN message direction.
 *
 * \details   This API will configure the direction of message transfer
 *            either to be transmit or receive.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgDir           Message direction.
 *            msgDir can take values from the following enum.
 *            #dcanMsgDir_t.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANSetMsgDirection(uint32_t baseAddr,
                         uint32_t msgDir,
                         uint32_t ifRegNum);

/**
 * \brief     Configure the DCAN data to be transferred.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     pDataVal         Pointer to a variable where data is stored.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANWriteData(uint32_t baseAddr,
                   uint32_t* pDataVal,
                   uint32_t ifRegNum);

/**
 * \brief     Read the received DCAN data.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     pDataVal         Pointer to a variable where data needs to be
 *                             stored.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANReadData(uint32_t baseAddr,
                  uint32_t* pDataVal,
                  uint32_t ifRegNum);

/**
 * \brief     Set the data length code for the CAN message.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     dataLengthCode   Data length code value.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANSetDataLengthCode(uint32_t baseAddr,
                           uint32_t dataLengthCode,
                           uint32_t ifRegNum);

/**
 * \brief     Enable the DCAN message object interrupts.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjIntrMask   DCAN message object interrupt mask values.
 *            msgObjIntrMask can take values from the following enum.
 *            #dcanMsgObjIntrMask_t
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANMsgObjIntrEnable(uint32_t baseAddr,
                          uint32_t msgObjIntrMask,
                          uint32_t ifRegNum);

/**
 * \brief     Disable the DCAN message object interrupts.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjIntrMask   DCAN message object interrupt mask values.
 *            msgObjIntrMask can take values from the following enum.
 *            #dcanMsgObjIntrMask_t
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANMsgObjIntrDisable(uint32_t baseAddr,
                           uint32_t msgObjIntrMask,
                           uint32_t ifRegNum);

/**
 * \brief     Enable/disable the auto re-transmission of unsuccessful messages
 *            of DCAN peripheral.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     enableAutoReTxn  Enable/disable setting for Auto re-transmision.
 *            enableAutoReTxn will take the following values.
 *            -# TRUE - Enable auto retransmission.
 *            -# FALSE - Disable auto retransmission.
 */
void DCANAutoReTransmissionEnable(uint32_t baseAddr, uint32_t enableAutoReTxn);

/**
 * \brief     Enable/disable the DCAN parity.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     enableParity     Enable/disable DCAN parity.
 *            enableParity will take the following values.
 *            -# TRUE - Enable DCAN parity.
 *            -# FALSE - Disable DCAN parity.
 */
void DCANParityEnable(uint32_t baseAddr, uint32_t enableParity);

/**
 * \brief     Read the interrupt line status of DCAN.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     intrLineNum      DCAN interrupt line number.
 *            intrLineNum can take values from the following enum.
 *            #dcanIntrLineNum_t
 *
 * \retval    intrLineSts      Interrupt line status.
 */
uint32_t DCANIntrStatus(uint32_t baseAddr, uint32_t intrLineNum);

/**
 * \brief     Read the error and status information of DCAN.
 *
 * \details   This register returns the error and status of DCAN controller.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    dcanErrSts       Returns the error and status values and user can
 *                             use values from the below enum
 *            #dcanStsErrCodeMask_t
 *
 * \note      Reading the error and status register will clear/set certain bits
 *            in the error and status register. For more information please
 *            refer the DCAN Technical Reference Manual(TRM). For debug support,
 *            the auto clear functionality of error and status register is
 *            disabled when in debug/suspend mode.
 */
uint32_t DCANGetErrorStatus(uint32_t baseAddr);

/**
 * \brief     Read the error counter status of DCAN.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    dcanErrCntrSts   Returns the error counter status values.
 *                             User can use values from the below enum
 *            #dcanCntrMask_t
 */
uint32_t DCANErrorCounterStatus(uint32_t baseAddr);

/**
 * \brief     Enable the test modes of DCAN.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     testMode         Select the DCAN test mode.
 *            testMode can take values from the following enum.
 *            #dcanTestModeMask_t
 * \param     enableTestMode   Enable/disable test mode of DCAN.
 *            enableTestMode will take the following values.
 *            -# TRUE - Enable test mode.
 *            -# FALSE - Disable test mode.
 */
void DCANTestModeEnable(uint32_t baseAddr,
                        uint32_t testMode,
                        uint32_t enableTestMode);

/**
 * \brief     Read the DCAN parity error status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    parityErrSts     Returns the DCAN parity error status.
 *            User can use entries from the below enum to check the status.
 *            #dcanParityErrSts_t
 */
uint32_t DCANParityErrorStatus(uint32_t baseAddr);

/**
 * \brief     Enable/disable the auto bus on feature of DCAN.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     enableAutoBusOn  Enable/disable test modes of DCAN.
 *            enableAutoBusOn will take the following values.
 *            -# TRUE - Enable Auto bus on.
 *            -# FALSE - Disable Auto bus on.
 */
void DCANAutoBusOnEnable(uint32_t baseAddr, uint32_t enableAutoBusOn);

/**
 * \brief     Set the DCAN auto bus on time value.
 *
 * \details   This API can be used to program the number of clock cycles before
 *            a bus-off recovery sequence is started.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     autoBusOnTimeVal Auto-bus on time value.
 *
 * \note      This API is valid only if the auto-bus-on feature is enabled using
 *            'DCANAutoBusOnEnable' API. On write access to the CAN control
 *            register while auto-bus-on timer is running, the auto-bus-on
 *            procedure will be aborted. During debug/suspend mode, running
 *            Auto-bus-on timer will be paused.
 */
void DCANSetAutoBusOnTimeVal(uint32_t baseAddr, uint32_t autoBusOnTimeVal);

/**
 * \brief     Get the DCAN auto bus on time value.
 *
 * \details   This API can be used to read the the number of clock cycles before
 *            a bus-off recovery sequence is started.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    autoBusOnTimeVal Auto-bus on time value.
 *
 * \note      This API is valid only if the auto-bus-on feature is enabled using
 *            'DCANAutoBusOnEnable' API. On write access to the CAN control
 *            register while auto-bus-on timer is running, the auto-bus-on
 *            procedure will be aborted. During debug/suspend mode, running
 *            Auto-bus-on timer will be paused.
 */
uint32_t DCANGetAutoBusOnTimeVal(uint32_t baseAddr);

/**
 * \brief     Read the DCAN transmit request X register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    txRqstXSts       Returns the Transmit request X register status.
 *            User can use the macro DCAN_TXRQST_X_REG(n) where n can take the
 *            following values.
 *            1 <= n <= 8.
 */
uint32_t DCANTxRequestXStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN transmit request register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjNum        Message object number whose Transmit request
 *                             status is to be returned.
 *
 * \retval    TRUE             If msgObjNum status is 1.
 * \retval    FALSE            if msgObjNum status is 0.
 */
uint32_t DCANTxRequestStatus(uint32_t baseAddr, uint32_t msgObjNum);

/**
 * \brief     This API will return the least message object number whose
 *            transmit request status is not set.
 *
 * \param     baseAddr           Base Address of the DCAN Module Registers.
 *
 * \retval    txRqstLstMsgObjSts Return the least message object number whose
 *                               transmit request is not set.
 */
uint32_t DCANTxRqstLeastMsgObjStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN New data X register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    newDataXSts      Returns the New data X register status.
 *            User can use the macro DCAN_NEWDAT_X_REG(n) where n can take the
 *            following values.
 *            1 <= n <= 8.
 */
uint32_t DCANNewDataXRegStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN new data register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjNum        Message object number whose New data
 *                             status is to be returned.
 *
 * \retval    TRUE             If msgObjNum status is 1.
 * \retval    FALSE            if msgObjNum status is 0.
 */
uint32_t DCANNewDataRegStatus(uint32_t baseAddr, uint32_t msgObjNum);

/**
 * \brief     This API will return the least message object number whose
 *            new data status is not set.
 *
 * \param     baseAddr            Base Address of the DCAN Module Registers.
 *
 * \retval    newDataLstMsgObjSts Return the new data status of least message
 *                                object.
 */
uint32_t DCANNewDataLeastMsgObjStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN Interrupt pending X register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    intrPendXSts     Returns the interrupt pending X register status.
 *            User can use the macro DCAN_INTRPEND_X_REG(n) where n can take the
 *            following values.
 *            1 <= n <= 8.
 */
uint32_t DCANIntrPendingXRegStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN interrupt pending register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjNum        Message object number whose interrupt pending
 *                             status is to be returned.
 *
 * \retval    TRUE             If msgObjNum status is 1.
 * \retval    FALSE            if msgObjNum status is 0.
 */
uint32_t DCANIntrPendingStatus(uint32_t baseAddr, uint32_t msgObjNum);

/**
 * \brief     Read the DCAN message valid X register status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 *
 * \retval    msgValidXSts     Returns the message valid X register status.
 *            User can use the macro DCAN_MSGVAL_X_REG(n) where n can take the
 *            following values.
 *            1 <= n <= 8.
 */
uint32_t DCANMsgValidXRegStatus(uint32_t baseAddr);

/**
 * \brief     Read the DCAN message valid status.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     msgObjNum        Message object number whose interrupt pending
 *                             status is to be returned.
 *
 * \retval    TRUE             If msgObjNum status is 1.
 * \retval    FALSE            if msgObjNum status is 0.
 */
uint32_t DCANMsgValidStatus(uint32_t baseAddr, uint32_t msgObjNum);

/**
 * \brief     This API will configure which interrupt line will be used to
 *            service interrupts from message objects.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     intrLineNum      Interrupt line number to be configured.
 *            intrLineNum can take values from the following enum.
 *            #dcanIntrLineNum_t
 * \param     msgObjNum        Message object number whose interrupt pending
 *                             status is to be returned.
 * \param     maxMsgObjects    Maximum message objects supported for the SOC.
 *            maxMsgObjects can take the following values - 16, 32, 64, 128.
 */
void DCANIntrMuxConfig(uint32_t baseAddr,
                       uint32_t intrLineNum,
                       uint32_t msgObjNum,
                       uint32_t maxMsgObjects);

/**
 * \brief     Validate the DCAN message object.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANValidateMsgObj(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief     Invalidate the DCAN message object.
 *
 * \param     baseAddr         Base Address of the DCAN Module Registers.
 * \param     ifRegNum         DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */

void DCANInvalidateMsgObj(uint32_t baseAddr, uint32_t ifRegNum);
/**
 * \brief     Enable/disable the FIFO end of block feature.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     fifoEndOfBlockEnable Enable/disable the Fifo end of block.
 *            fifoEndOfBlockEnable will take the following values.
 *            -# TRUE - Enable Fifo end of block.
 *            -# FALSE - Disable Fifo end of block.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANFifoEndOfBlockEnable(uint32_t baseAddr,
                              uint32_t fifoEndOfBlockEnable,
                              uint32_t ifRegNum);

/**
 * \brief     Perform the DCAN message object mask configuration.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     msgIdMask            DCAN message ID mask value.
 *            msgIdMask can take the following value.
 *            #DCAN_IDENTIFIER_MASK(mask, idType)
 * \param     msgDirMask           Message direction mask.
 *            msgDirMask can take values from the following enum
 *            #dcanMsgDirMask_t
 * \param     extIdMask            Extended identifier mask.
 *            extIdMask can take values from the following enum
 *            #dcanExtIdMask_t
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANMsgObjectMaskConfig(uint32_t baseAddr,
                             uint32_t msgIdMask,
                             uint32_t msgDirMask,
							 uint32_t extIdMask,
                             uint32_t ifRegNum);

/**
 * \brief     This API will configure IF3 register set so that it is
 *            automatically updated with the received value in message RAM.
 *            Where n = 12,34,56,78.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     msgNum               Message object number for which IF3 register
 *                                 set has to be updated.
 *            msgNum can take values from the range.
 *            1 <= msgNum <= 128
 */
void DCANSetIf3RegUpdateEnable(uint32_t baseAddr, uint32_t msgNum);

/**
 * \brief     This API will set the observation bits in the IF3
 *            observation register which are used to determine which data
 *            sections of the IF3 interface register set have to be read
 *            in order to complete a DMA read cycle.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     obsMask              Observation fields to be set.
 *            obsMask can take values from the following enum
 *            #dcanObsFieldMask_t
 */
void DCANSetIf3Observation(uint32_t baseAddr, uint32_t obsMask);

/**
 * \brief     This API will clear the observation bits in the IF3
 *            observation register which are used to determine which data
 *            sections of the IF3 interface register set have to be read
 *            in order to complete a DMA read cycle.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     obsMask              Observation fields to be set.
 *            obsMask can take values from the following enum
 *            #dcanObsFieldMask_t
 */
void DCANClearIf3Observation(uint32_t baseAddr, uint32_t obsMask);

/**
 * \brief     This API will return the status of DCAN observation register.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 *
 * \retval    if3ObsSts            IF3 observation status.
 *            User can use the values from the following enum to read the status
 *            #dcanObsSts_t
 */
uint32_t DCANIf3ObservationStatus(uint32_t baseAddr);

/**
 * \brief     This API will return the status of DCAN mask register.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 *
 * \retval    maskSts              DCAN mask register status.
 *            User can use the values from the following enum to read the status
 *            #dcanMaskSts_t
 */
uint32_t DCANIfMaskStatus(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief     This API will return the status of DCAN arbitration register.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 *
 * \retval    arbSts               DCAN arbitration register status.
 *            User can use the values from the following enum to read the status
 *            #dcanArbSts_t
 */
uint32_t DCANIfArbitrationStatus(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief     This API will return the status of DCAN message control register.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 *
 * \retval    msgCtlSts            DCAN message control register status.
 *            User can use the values from the following enum to read the status
 *            #dcanMsgCtlSts_t
 */
uint32_t DCANIfMsgCtlStatus(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief     This API will clear the pending interrupt of a message object.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANIntrClear(uint32_t baseAddr, uint32_t ifRegNum);

/**
 * \brief     This API will configure the New data for a message object.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     newData              Configure the new data value.
 *            newData will take values from the following enum.
 *            #dcanNewDataCfg_t.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANNewDataConfig(uint32_t baseAddr, uint32_t newData, uint32_t ifRegNum);

/**
 * \brief     This API will enable/disable the Acceptance mask for DCAN.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     enableMask           Enable/disable the acceptance mask for DCAN.
 *            enableMask will take the following values.
 *            -# TRUE - Enable acceptance mask.
 *            -# FALSE - Disable acceptance mask.
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANAcceptanceMaskEnable(uint32_t baseAddr,
                              uint32_t enableMask,
                              uint32_t ifRegNum);

/**
 * \brief     This API will enable/disable the transmit request for DCAN.
 *
 * \param     baseAddr             Base Address of the DCAN Module Registers.
 * \param     enableTxRqst         Enable/disable the transmit request for DCAN.
 *            enableTxRqst will take the following values.
 *            -# TRUE - Enable transmit request.
 *            -# FALSE - Disable transmit request .
 * \param     ifRegNum             DCAN interface register number.
 *            ifRegNum can take values from the following enum.
 *            #dcanIfRegNum_t
 */
void DCANTransmitRequestEnable(uint32_t baseAddr,
                               uint32_t enableTxRqst,
                               uint32_t ifRegNum);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef DCAN_H_ */
