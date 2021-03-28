/**
 * @file  csl_emif.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the EMIF IP.
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015-2017, Texas Instruments, Inc.
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
#ifndef CSL_EMIF_H_
#define CSL_EMIF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_emif.h>

/** ===========================================================================
 *
 * @defgroup CSL_EMIF_API External Memory Interface API
 *
 *  This is the CSL-FL for the EMIF controller/PUB. It provides the structures
 *  and APIs needed to configure and initialize the EMIF controller/PUB and
 *  attached DDR SDRAM devices. Once the EMIF and DDR SDRAM devices are
 *  initialized, additional API functions are available to implement low-power
 *  modes of operation.
 *
 *  The following lists the steps required to use this CSL-FL:
 *
 *  1. Allocate and initialize a #CSL_EmifConfig structure. This structure
 *     provides all controller, PUB, and DDR SDRAM configuration information
 *     required to properly initialize them.
 *
 *  2. Call the #CSL_emifConfig function. This function uses configuration
 *     information provided in the #CSL_EmifConfig structure to initialize
 *     the controller, PUB, and DDR SDRAM.
 *
 *  3. Read/write to the DDR SDRAM memory.
 *
 *  ===========================================================================
 */
/**
@defgroup CSL_EMIF_DATASTRUCT  EMIF Data Structures
@ingroup CSL_EMIF_API
*/
/**
@defgroup CSL_EMIF_FUNCTION  EMIF Functions
@ingroup CSL_EMIF_API
*/
/**
@defgroup CSL_EMIF_ENUM EMIF Enumerated Data Types
@ingroup CSL_EMIF_API
*/

/**
 *  \addtogroup CSL_EMIF_ENUM
 *  @{
 */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible types of EMIF address bits
 *
 *  \anchor CSL_EmifSdramAddrBits
 *  \name EMIF SDRAM address bits
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifSdramAddrBits;
    /** Column type */
#define CSL_EMIF_SDRAM_ADDR_BITS_COLUMN     ((uint32_t) 0U)
    /** Row type */
#define CSL_EMIF_SDRAM_ADDR_BITS_ROW        ((uint32_t) 1U)
    /** Bank type */
#define CSL_EMIF_SDRAM_ADDR_BITS_BANK       ((uint32_t) 2U)
    /** Rank type */
#define CSL_EMIF_SDRAM_ADDR_BITS_RANK       ((uint32_t) 3U)
    /** Group type */
#define CSL_EMIF_SDRAM_ADDR_BITS_GROUP      ((uint32_t) 4U)
    /** Invalid */
#define CSL_EMIF_SDRAM_ADDR_BITS_INVALID    ((uint32_t) 5U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible EMIF controller operating modes
 *
 *  \anchor CSL_EmifOperatingMode
 *  \name EMIF operating mode
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifOperatingMode;
    /** In initialization mode */
#define CSL_EMIF_OPERATING_MODE_INIT            ((uint32_t) 0U)
    /** Normal operating mode */
#define CSL_EMIF_OPERATING_MODE_NORMAL          ((uint32_t) 1U)
    /** Power down mode */
#define CSL_EMIF_OPERATING_MODE_POWER_DOWN      ((uint32_t) 2U)
    /** Self refresh mode */
#define CSL_EMIF_OPERATING_MODE_SELF_REFRESH    ((uint32_t) 3U)
    /** Invalid */
#define CSL_EMIF_OPERATING_MODE_INVALID         ((uint32_t) 4U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible SDRAM types
 *
 *  \anchor CSL_EmifSdramType
 *  \name EMIF SDRAM type
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifSdramType;
    /** DDR3 */
#define CSL_EMIF_SDRAM_TYPE_DDR3        ((uint32_t) 0U)
    /** LPDDR2 */
#define CSL_EMIF_SDRAM_TYPE_LPDDR2      ((uint32_t) 1U)
    /** LPDDR3 */
#define CSL_EMIF_SDRAM_TYPE_LPDDR3      ((uint32_t) 2U)
    /** DDR4 */
#define CSL_EMIF_SDRAM_TYPE_DDR4        ((uint32_t) 3U)
    /** LPDDR4 */
#define CSL_EMIF_SDRAM_TYPE_LPDDR4      ((uint32_t) 4U)
    /** Invalid */
#define CSL_EMIF_SDRAM_TYPE_INVALID     ((uint32_t) 5U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the SDRAM storage width in bits
 *
 *  \anchor CSL_EmifSdramConfig
 *  \name EMIF SDRAM configuration
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifSdramConfig;
    /** 4 bits */
#define CSL_EMIF_SDRAM_CONFIG_X4        ((uint32_t) 0U)
    /** 8 bits */
#define CSL_EMIF_SDRAM_CONFIG_X8        ((uint32_t) 1U)
    /** 16 bits */
#define CSL_EMIF_SDRAM_CONFIG_X16       ((uint32_t) 2U)
    /** 32 bits */
#define CSL_EMIF_SDRAM_CONFIG_X32       ((uint32_t) 3U)
    /** Invalid */
#define CSL_EMIF_SDRAM_CONFIG_INVALID   ((uint32_t) 4U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible power saving modes
 *
 *  \anchor CSL_EmifPowerSavingMode
 *  \name EMIF power saving mode
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifPowerSavingMode;
    /** Pre-charge power down mode */
#define CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN   (((uint32_t)1U) << 0)
    /** Self-refresh mode */
#define CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH (((uint32_t)1U) << 1)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible clock types
 *
 *  \anchor CSL_EmifClockType
 *  \name EMIF clock type
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifClockType;
    /** Configuration clock */
#define CSL_EMIF_CLOCK_TYPE_CFG         ((uint32_t) 0U)
    /** Controller clock */
#define CSL_EMIF_CLOCK_TYPE_CTL         ((uint32_t) 1U)
    /** PHY clock */
#define CSL_EMIF_CLOCK_TYPE_PHY         ((uint32_t) 2U)
    /** Invalid */
#define CSL_EMIF_CLOCK_TYPE_INVALID     ((uint32_t) 3U)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible data training types
 *
 *  \anchor CSL_EmifDataTrainingType
 *  \name EMIF data training type
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifDataTrainingType;
    /** Executes a PUB write leveling routine */
#define CSL_EMIF_DATA_TRAINING_WRITE_LEVELING           ((uint32_t) CSL_EMIF_PHYCFG_PIR_WL_MASK)
    /** Executes a PUB training routine to determine the optimum position of the read data DQS strobe for maximum system timing margins (LPDDR4, DDR4, DDR3 only) */
#define CSL_EMIF_DATA_TRAINING_READ_DQS_GATE            ((uint32_t) CSL_EMIF_PHYCFG_PIR_QSGATE_MASK)
    /** Executes a PUB training routine that readjusts the write latency used during write in case the write leveling routine changed the expected latency */
#define CSL_EMIF_DATA_TRAINING_WRITE_LEVELING_ADJUST    ((uint32_t) CSL_EMIF_PHYCFG_PIR_WLADJ_MASK)
    /** Executes a PUB training routine to deskew the DQ bits during read */
#define CSL_EMIF_DATA_TRAINING_READ_DATA_BIT_DESKEW     ((uint32_t) CSL_EMIF_PHYCFG_PIR_RDDSKW_MASK)
    /** Executes a PUB training routine to deskew the DQ bits during write */
#define CSL_EMIF_DATA_TRAINING_WRITE_DATA_BIT_DESKEW    ((uint32_t) CSL_EMIF_PHYCFG_PIR_WRDSKW_MASK)
    /** Executes a PUB training routine to maximize the read data eye */
#define CSL_EMIF_DATA_TRAINING_READ_DATA_EYE            ((uint32_t) CSL_EMIF_PHYCFG_PIR_RDEYE_MASK)
    /** Executes a PUB training routine to maximize the write data eye */
#define CSL_EMIF_DATA_TRAINING_WRITE_DATA_EYE           ((uint32_t) CSL_EMIF_PHYCFG_PIR_WREYE_MASK)
    /** Executes a PUB training routine for DRAM and HOST DQ I/O VREF values to enhance the write and read eye position (LPDDR4, DDR4 only) */
#define CSL_EMIF_DATA_TRAINING_VREF                     ((uint32_t) CSL_EMIF_PHYCFG_PIR_VREF_MASK)
    /** Executes a PUB training routine that compensates the clock tree delay (tDQS2DQ) in memory devices (LPDDR4 only) */
#define CSL_EMIF_DATA_TRAINING_WRITE_DQS2DQ             ((uint32_t) CSL_EMIF_PHYCFG_PIR_DQS2DQ_MASK)
/* @} */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible return values from the
 * CSL_emifConfig function
 *
 *  \anchor CSL_EmifConfigReturn
 *  \name EMIF config function return value
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_EmifConfigReturn;
    /** Success */
#define CSL_EMIF_CONFIG_RETURN_OK                       ((int32_t) 0)
    /** An invalid value was detected in the specified configuration parameters */
#define CSL_EMIF_CONFIG_RETURN_INVALID_CFG              ((int32_t) -1)
    /** Write leveling data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_WL       ((int32_t) -2)
    /** QS gate data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_QSGATE   ((int32_t) -3)
    /** DQS2DQ data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_DQS2DQ   ((int32_t) -4)
    /** Write leveling adjust data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_WLA      ((int32_t) -5)
    /** Read skew data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_RDSKEW   ((int32_t) -6)
    /** Write skew data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_WRSKEW   ((int32_t) -7)
    /** Read eye data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_RDEYE    ((int32_t) -8)
    /** Write eye data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_WREYE    ((int32_t) -9)
    /** VREF data training failed */
#define CSL_EMIF_CONFIG_RETURN_DATA_TRAIN_FAIL_VREF     ((int32_t) -10)
    /** PHY initialization failed */
#define CSL_EMIF_CONFIG_RETURN_PHY_INIT_FAIL            ((int32_t) -11)

/* @} */

/* @} */

/**
 *  \addtogroup CSL_EMIF_DATASTRUCT
 *  @{
 */

/** \brief Power saving configuration structure
 *
 *  This structure provides configuration settings for power saving support.
 *  If default settings are desired, this structure can be ommitted in function
 *  calls and the indicated default values will be used.
 *
 */
typedef struct {
  uint32_t  modes;                      /**< [IN] Power saving mode(s). Multiple modes can be specified by logically OR'ing them together. For valid modes, see \ref CSL_EmifPowerSavingMode. (default: CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN | CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH) */
  uint32_t  timeoutClocksPowerDown;     /**< [IN] The SDRAM is automatically put into power-down after this many clocks of the EMIF command channel being idle. (default: 512)*/
  uint32_t  timeoutClocksSelfRefresh;   /**< [IN] The SDRAM is automatically put into self-refresh after this many clocks of the EMIF command channel being idle. (default: 2048) */
  bool      bDisableSdramClk;           /**< [IN] If true, disables the clock to the sdram whenever a clock is not required. (default: true) */
} CSL_EmifPowerSavingCfg;

/** \brief PHY configuration structure
 *
 *  This structure provides configuration settings for PHY support.
 *  A pointer to this structure is specified in the #CSL_EmifConfig
 *  structure. If default settings are desired, a NULL pointer can be specified
 *  in which case the indicated default values will be used.
 *
 */
typedef struct
{
    bool            bZCAL;          /**< [IN] Run Impedence calibration (default: true) */
    bool            bCA;            /**< [IN] Run PHY LPDDR3 CA training (default: false) */
    bool            bPLLInit;       /**< [IN] Run PLL initialization sequence which includes correct driving of PLL power-down, reset and gear shift pins, and then waiting for the PHY PLLs to lock (default: true) */
    bool            bDCAL;          /**< [IN] Run Digital Delay Line (DDL) Calibration (default: true) */
    bool            bPhyReset;      /**< [IN] Resets the AC and DATX8 modules by asserting the AC/DATX8 reset pin (default: false) */
    bool            bDramReset;     /**< [IN] Issues a reset to the DRAM (by driving the DRAM reset pin low) and wait 200us (DDR4 and DDR3 only) (default: false) */
    bool            bPllBypass;     /**< [IN] If true, PUB/PHY are put into PLL bypass mode (default: false) */
} CSL_EmifPhyParms;

/** \brief SDRAM configuration structure
 *
 *  This structure provides configuration settings for the attached SDRAM
 *  device(s). A pointer to this structure is specified in the #CSL_EmifConfig
 *  structure.
 *
 */
typedef struct
{
    CSL_EmifSdramType       type;               /**< [IN] Type of SDRAM device */
    CSL_EmifSdramConfig     config;             /**< [IN] Configuration of SDRAM device */
    uint8_t                 numColBits;         /**< [IN] Number of SDRAM column bits */
    uint8_t                 numRowBits;         /**< [IN] Number of SDRAM row bits */
    uint8_t                 numBanks;           /**< [IN] Number of SDRAM banks */
    uint8_t                 numBankGroups;      /**< [IN] Number of SDRAM bank groups (DDR4 only) */
    uint8_t                 numRanks;           /**< [IN] Number of SDRAM ranks */
    uint16_t                sdramDataWidth;     /**< [IN] Width (in bits) of the SDRAM data bus (64, 32, or 16 (excludes ECC)) */
    uint8_t                 burstLength;        /**< [IN] Burst length in bytes */
    uint8_t                 casWriteLatency;    /**< [IN] CAS write latency */
    uint8_t                 casLatency;         /**< [IN] CAS latency */
    uint8_t                 additionalLatency;  /**< [IN] Additional latency */
} CSL_EmifSdramParms;

/** \brief Force memory ECC error configuration structure
 *
 *  This structure provides configuration settings used to force a memory ECC
 *  error via the #CSL_emifForceMemoryEccError function. A pointer to this
 *  structure (or NULL is not needed) is specified in the #CSL_EmifConfig
 *  structure.
 *
 */
typedef struct
{
    uint8_t     rankAddr;           /**< [IN] Rank address for ECC poisoning */
    uint8_t     bankGroupAddr;      /**< [IN] Bank Group address for ECC poisoning */
    uint8_t     bankAddr;           /**< [IN] Bank address for ECC poisoning */
    uint32_t    rowAddr;            /**< [IN] Row address for ECC poisoning */
    uint16_t    colAddr;            /**< [IN] Column address for ECC poisoning */
} CSL_EmifForceMemEccErrorCfg;


struct csl_emif_config_t;          /* Forward declare structure for callback function pointer typedef reference */

/**
 *  \brief User-provided DDR SDRAM controller configuration function
 *
 *  This is an optional user-provided function that performs additional DDR
 *  SDRAM controller configuration operations. The function pointer is
 *  specified in the #CSL_EmifConfig configuration structure and, if not
 *  NULL, is called by the #CSL_emifConfig function after completing its
 *  DDR SDRAM controller configuration operations.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return None
 */
typedef void (*CSL_EmifSdramCtrlCfgCbFxnPtr)(struct csl_emif_config_t *pCfg);

/**
 *  \brief User-provided DDR SDRAM PHY configuration function
 *
 *  This is an optional user-provided function that performs additional DDR
 *  SDRAM PHY configuration operations. The function pointer is
 *  specified in the #CSL_EmifConfig configuration structure and, if not
 *  NULL, is called by the #CSL_emifConfig function after completing its
 *  DDR SDRAM PHY configuration operations.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return None
 */
typedef void (*CSL_EmifSdramPhyCfgCbFxnPtr)(struct csl_emif_config_t *pCfg);

/**
 *  \brief User-provided delay clock cycles function
 *
 *  This is a required user-provided function that performs a
 *  delay of the specified number of clock cycles per the frequency of the
 *  specified clock type. It is called by the #CSL_emifConfig function
 *  whenever a delay is required.
 *
 *  \param clockType        [IN]    Specifies the clock type. See \ref CSL_EmifClockType for details.
 *  \param numClockCycles   [IN]    Number of clock cycles to delay
 *
 *  \return None
 */
typedef void (*CSL_EmifDelayClockCyclesCbFxnPtr)(CSL_EmifClockType clockType, uint32_t numClockCycles);

/** \brief EMIF configuration structure
 *
 *  This structure provides the configuration settings for the EMIF.
 *  A pointer to this structure is passed to the #CSL_emifConfig function
 *  which performs the proper configuration sequence for the EMIF subsystem,
 *  SDRAM controller, and PHY.
 *
 */
typedef struct csl_emif_config_t
{
    CSL_emif_sscfgRegs                  *pEmifSsRegs;               /**< [IN] Pointer to DDR subsystem registers */
    CSL_emif_ctlcfgRegs                 *pEmifCtlRegs;              /**< [IN] Pointer to Synopsys DDR controller registers */
    CSL_emif_phycfgRegs                 *pEmifPhyRegs;              /**< [IN] Pointer to Synopsys PUB registers */
    CSL_EmifSdramParms                  *pSdramParms;               /**< [IN] Pointer to SDRAM parameters (if NULL, defaults are used) */
    CSL_EmifPhyParms                    *pPhyParms;                 /**< [IN] Pointer to PHY initialization parameters (if NULL, defaults are used) */
    CSL_EmifForceMemEccErrorCfg         *pForceMemEccErrorCfg;      /**< [IN] Pointer to memory ECC error forcing parameters (NULL if not needed) */
    CSL_EmifSdramCtrlCfgCbFxnPtr        sdramCtrlCfgCbFxnPtr;       /**< [IN] Pointer to a user-provided function that performs additional Sdram controller configuration (NULL if not needed) */
    CSL_EmifSdramPhyCfgCbFxnPtr         sdramPhyCfgCbFxnPtr;        /**< [IN] Pointer to a user-provided function that performs additional post PHY init configuration (NULL if not needed) */
    CSL_EmifDelayClockCyclesCbFxnPtr    delayClockCyclesCbFxnPtr;   /**< [IN] Pointer to a user-provided function that performs a delay of the specified number of clock cycles per the frequency of the specified clock type */
    uint16_t                            memcDramDataWidthBits;      /**< [IN] Width (in bits) of the controller's DRAM data bus (64, 32, or 16) */
    uint16_t                            sdramClkFreqMHz;            /**< [IN] Frequency (MHz) of clock to SDRAM device */
    bool                                bEnableMemoryECC;           /**< [IN] Enable memory ECC */
    bool                                bEnableBusECC;              /**< [IN] Enable bus ECC */
    uint32_t                            dataTraining;               /**< [IN] Specifies the data training operations to be performed. It is a logical-OR of available data training types. See \ref CSL_EmifDataTrainingType for a list of data training types.  */
} CSL_EmifConfig;

/* @} */

/**
 *  \addtogroup CSL_EMIF_FUNCTION
 *  @{
 */

/**
 *  \brief Return revision of the EMIF subsystem module.
 *
 *  This function returns the contents of the EMIF subsystem revision register.
 *  Consult the EMIF subsystem module documentation for a description of the
 *  contents of the revision register.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return The 32-bit revision register is returned.
 */
extern uint32_t CSL_emifGetRevision(CSL_EmifConfig *pCfg);

/**
 *  \brief Configure EMIF
 *
 *  This function performs the proper configuration sequence for the SDRAM
 *  controller and PHY per the specified configuration parameters.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return    0 = success
 *            -1 = An invalid value was detected in the specified configuration parameters
 *            -2 = Write leveling data training failed
 *            -3 = QS gate data training failed
 *            -4 = DQS2DQ data training failed
 *            -5 = Write leveling adjust data training failed
 *            -6 = Read skew data training failed
 *            -7 = Write skew data training failed
 *            -8 = Read eye data training failed
 *            -9 = Write eye data training failed
 *           -10 = VREF data training failed
 *           -11 = PHY initialization failed
 */
extern int32_t CSL_emifConfig(CSL_EmifConfig *pCfg);

/**
 *  \brief Force memory ECC error
 *
 *  This function enables the forcing of a memory ECC error whenever
 *  a memory address is written to that matches the CSL_EmifForceMemEccErrorCfg
 *  parameters provided to the CSL_emifConfig function.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *  \param bSecType         [IN]    Specifies the type of DDR address bits being mapped. See \ref CSL_EmifSdramAddrBits for details.
 *
 *  \return None
 */
extern void CSL_emifForceMemoryEccError(CSL_EmifConfig *pCfg, bool bSecType);

/**
 *  \brief Map HIF to SDRAM address bits
 *
 *  This function maps HIF address bits (specified by a bitmask) to the specified
 *  type of SDRAM address bits.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *  \param ddrAddrBitType   [IN]    Specifies the type of SDRAM address bits being mapped. See \ref CSL_EmifSdramAddrBits for details.
 *  \param hifAddrBitMask   [IN]    Specifies the HIF address bits being mapped to the specified type of DDR address bits.
 *
 *  \return None
 */
extern void CSL_emifMapSdramAddrBits(CSL_EmifConfig *pCfg, CSL_EmifSdramAddrBits ddrAddrBitType, uint32_t hifAddrBitMask);

/**
 *  \brief Enable power saving support
 *
 *  This function enables power saving functionality. The desired power saving
 *  settings are provided in the #CSL_EmifPowerSavingCfg structure. If no
 *  CSL_EmifPowerSavingCfg structure is provided (pPowerSavingCfg is NULL),
 *  then the default power settings are used.
 *
 *  pPowerSavingCfg->modes may contain multiple modes logcally OR'd together.
 *
 *  Note that if both CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN and
 *  CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH modes are specified, then
 *  pPowerSavingCfg->timeoutClocksSelfRefresh must be >=
 *  pPowerSavingCfg->timeoutClocksPowerDown.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *  \param pPowerSavingCfg  [IN]    Pointer to a power saving configuration structure. If NULL, then default power settings are used. See #CSL_EmifPowerSavingCfg for details.
 *
 *  \return 0 on success or -1 if a parameter error is detected
 */
extern int32_t CSL_emifEnablePowerSaving( CSL_EmifConfig *pCfg, CSL_EmifPowerSavingCfg *pPowerSavingCfg );

/**
 *  \brief Disable power saving support
 *
 *  This function disables all sdram power saving functionality.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return None
 */
extern void CSL_emifDisablePowerSaving( CSL_EmifConfig *pCfg );

/**
 *  \brief Enter software self refresh mode
 *
 *  This function is used to enter software self refresh mode.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return None
 */
extern void CSL_emifEnterSelfRefresh( CSL_EmifConfig *pCfg );

/**
 *  \brief Exit software self refresh mode
 *
 *  This function is used to exit software self refresh mode.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return None
 */
extern void CSL_emifExitSelfRefresh( CSL_EmifConfig *pCfg );

/**
 *  \brief Return the current EMIF operating mode
 *
 *  This function returns the current operating mode of the EMIF controller.
 *  See \ref CSL_EmifOperatingMode for a list of valid operating modes.
 *
 *  \param pCfg             [IN]    Pointer to the EMIF configuration structure. See #CSL_EmifConfig for details.
 *
 *  \return Current operating mode
 */
extern CSL_EmifOperatingMode CSL_emifGetOperatingMode(CSL_EmifConfig *pCfg);

/* @} */

#ifdef __cplusplus
}
#endif  // extern "C"

#endif  // end of _CSL_EMIF_H_ definition
