/*
 * Copyright (c) 2010-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *  @file   board.h
 *
 *  @brief  The Board Library is a thin utility
 *  layer on top of  CSL and other board utilities. It provides uniform APIs
 *  for all supported boards. It aims to assist user to quickly write portable
 *  applications for its supported boards by hiding board level details
 *  from the user.
 *
 *
 */

#ifndef BOARD_UTILS_H_
#define BOARD_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \defgroup BOARD_LIB_MODULE Board Library
 *
 *  @{
 *
 *  Board library provides set of APIs to initialize the interfaces
 *  on a given HW platform. It takes care of configuring and enabling different
 *  modules like PLL, clocks inside SoC and HW components like DDR, pinmux
 *  on the board which are required to make sure board is ready for running the
 *  application software.
 *
 *  A common standard API Board_init() is exposed to the applications to invoke
 *  different board initialization routines. This function is common across the
 *  platforms maintaining the portability and can receive different input
 *  configuration flags based on the board capabilities allowing extendibility.
 *
 *  Board library eliminates the use of any additional configurations like
 *  GEL files to initialize the board except the cases like DDR initialization
 *  for loading the code into DDR before calling the Board init function.
 *  Given this limitation, applications invoking board library functions to
 *  initialize PLL, DDR and pinmux are supposed to run from SoC internal memory.
 *
 *  Additional functionality for configuring the devices like Ethernet PHYs,
 *  Flash devices and IO expanders etc is provided based on the platform need.
 *  Refer to the device/platform specific library documentation for more details.
 *
 */
/* @} */


/**
 * \ingroup BOARD_LIB_MODULE
 *
 * @defgroup  BOARD_LIB_MODULE_TYPES  Board Data Types
 */
/*@{*/
/**
 *  @brief  Board Library uses basic C99 data types. The basic types used are
 *          uint32_t, int32_t, uint8_t, int8_t, uint16_t and int16_t. The standard
 *          C char is used for strings. Complex types (or typdefs) if used are defined
 *          within this header file.
 */
#include <stdint.h>

#include <ti/csl/hw_types.h>

/**
  * @brief  The following definitions are for handling cache alignment on the board.
  *
  *         MAX_CACHE_LINE must be set to the cache line size of the board.
  *
  *         When allocating memory that must be cache aligned, it must be a multiple of
  *         the cache line size. Use board_roundup to get the appropriate size.
  *
  *         As an example to allocate a cache aligned block of memory you would do
  *         something like:
  *
  *             buffer_len_aligned = board_roundup (buffer_len, MAX_CACHE_LINE)
  *             Malloc (buffer_len_aligned)
  *
  */
/* w should be power of 2 */
#define BOARD_CACHE_LINE_SIZE (128)
#define board_roundup(n,w) (((n) + (w) - 1) & ~((w) - 1))

/*************************************************************
 * Return/Error values                                       *
 *************************************************************/

/**
 * @brief   The return type for board library API calls
 *
 * @details Board library function calls will return this value, which contains
 *          information as to whether the function succeeded or encountered an
 *          error.
 */
typedef int32_t Board_STATUS;

#include <ti/board/board_cfg.h>

/** Board status OK */
#define BOARD_SOK                           0
/** Error code for invalid parameters */
#define BOARD_INVALID_PARAM                 -1
/** Error code for unsupported feature */
#define BOARD_UNSUPPORTED_FEATURE           -2
/** I2C handle open failed */
#define BOARD_I2C_OPEN_FAIL                 -3
/** I2C transfer call failed */
#define BOARD_I2C_TRANSFER_FAIL             -4
/** IO Delay region not in internal memory */
#define BOARD_PINMUX_BAD_MEM_REGION         -5
/** Error code for init clock module */
#define BOARD_INIT_CLOCK_FAIL               -6
/** Error code for init DDR */
#define BOARD_INIT_DDR_FAIL                 -7
/** Runtime pinmux configuration mode */
#define BOARD_PINMUX_INVALID_MODE           -8
/** Board status FAIL */
#define BOARD_FAIL                          -10

/*************************************************************
 * Init/Info Definitons                                      *
 *************************************************************/

/* Max number of characters per ID entry field */
#define BOARD_MAX_ID_STR_LEN    20

#define BOARD_BOARD_NAME_LEN     (16U)
#define BOARD_DESIGN_REV_LEN     (2U)
#define BOARD_PROC_NUM_LEN       (4U)
#define BOARD_VARIANT_LEN        (2U)
#define BOARD_PCBREV_LEN         (2U)
#define BOARD_SCHMBOM_REV_LEN    (2U)
#define BOARD_SWREV_LEN          (2U)
#define BOARD_VENDORID_LEN       (2U)
#define BOARD_BUILD_WEEK_LEN     (2U)
#define BOARD_BUILD_YEAR_LEN     (2U)
#define BOARD_BOARDID_LEN        (6U)
#define BOARD_SERIAL_NUM_LEN     (4U)
#define BOARD_MAC_ADDR_LEN       (192U)


/*************************************************************
 * SoC Info Definitons                                      *
 *************************************************************/

/* Default system clock value */
#define BOARD_SYS_CLK_DEFAULT  (0xFFFFFFFFU)

/**
 *  @brief This structure contains board specific information
 *
 *  This is the first generation (v1) of board ID info structure
 *  which is applicable to all the platforms prior to Keystone-III.
 */
typedef struct {

    /* Header ID of the SOC */
    char header[BOARD_MAX_ID_STR_LEN];

    /* Name of the board */
    char boardName[BOARD_MAX_ID_STR_LEN];

    /* Board version/revision info */
    char version[BOARD_MAX_ID_STR_LEN];

    /* Board serial number */
    char serialNum[BOARD_MAX_ID_STR_LEN];

    /* Board configuration codes */
    char configCodes[2*BOARD_MAX_ID_STR_LEN];

    /* Industrial Ethernet MAC address 0 */
    char indEthMacID0[BOARD_MAX_ID_STR_LEN];

    /* Industrial Ethernet MAC address 3 */
    char indEthMacID3[BOARD_MAX_ID_STR_LEN];

} Board_IDInfo;

typedef struct
{
    uint8_t  macStructType;
    uint16_t macLength;
    uint16_t macControl;
    uint8_t  macAddress[BOARD_MAC_ADDR_LEN];
} __attribute__((packed)) Board_macInfo;

typedef struct
{
    uint8_t  ddrStructType;
    uint16_t ddrStructLen;
    uint16_t ddrCtrl;
} __attribute__((packed)) Board_ddrInfo;

typedef struct
{
    uint8_t  boardInfoStructType;
    uint16_t boardInfoLength;
    char     boardName[BOARD_BOARD_NAME_LEN];
    char     designRev[BOARD_DESIGN_REV_LEN];
    char     procNum[BOARD_PROC_NUM_LEN];
    char     variant[BOARD_VARIANT_LEN];
    char     pcbRev[BOARD_PCBREV_LEN];
    char     schbomRev[BOARD_SCHMBOM_REV_LEN];
    char     swRev[BOARD_SWREV_LEN];
    char     vendorID[BOARD_VENDORID_LEN];
    char     buildWeek[BOARD_BUILD_WEEK_LEN];
    char     buildYear[BOARD_BUILD_YEAR_LEN];
    char     boardID[BOARD_BOARDID_LEN];
    char     serialNum[BOARD_SERIAL_NUM_LEN];
} __attribute__((packed)) Board_boardInfo;

typedef struct
{
    uint32_t magicNumber;
    uint8_t  headerStructType;
    uint16_t payloadSize;
} __attribute__((packed)) Board_headerInfo;

/**
 *  @brief This structure contains board specific information
 *
 *  This is the second generation (v2) of board ID info structure
 *  which is applicable to the platforms from Keystone-III and later.
 */
typedef struct
{
    /* Header info of the board */
    Board_headerInfo headerInfo;

    /* Board id Info of the board */
    Board_boardInfo boardInfo;

    /* DDR info of the board */
    Board_ddrInfo ddrInfo;

    /* Mac Info of the board */
    Board_macInfo macInfo;

    /* End of the structure */
    uint8_t endList;

}  __attribute__((packed)) Board_IDInfo_v2;

/**
 *  @brief This structure contains SoC specific information
 */
typedef struct {

    /* System clock value in Hz */
    uint32_t sysClock;

} Board_SoCInfo;

/** ---------------------------------------------------------------------------
 * \brief Enumeration of reported temperature event types
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** Temperature alert event occurred */
    BOARD_DDR_TEMP_EVENT_TEMP_ALERT = 1,
    /** Low temperature alarm event occurred */
    BOARD_DDR_TEMP_EVENT_LOW_TEMP_ALARM = 2,
    /** Temperature change event occurred: Needs 4 x refresh */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_4X_REFRESH = 3,
    /** Temperature change event occurred: Needs 2 x refresh */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_2X_REFRESH = 4,
    /** Temperature change event occurred: Needs 1 x refresh */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_1X_REFRESH = 5,
    /** Temperature change event occurred: Needs 0.5 x refresh */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_1_BY_2_REFRESH = 6,
    /** Temperature change event occurred: Needs 0.25 x refresh */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_1_BY_4_REFRESH = 7,
    /** Temperature change event occurred: Needs 0.25 x refresh and derating */
    BOARD_DDR_TEMP_EVENT_TEMP_CHANGE_1_BY_4_REFRESH_WITH_DERATING = 8,
    /** High temperature alarm event occurred */
    BOARD_DDR_TEMP_EVENT_HIGH_TEMP_ALARM = 9,
} Board_DDRTempEventType;

typedef uint32_t Board_initCfg;
#define BOARD_INIT_ALL                  (0xFFFFFFFFU)
#define BOARD_INIT_UNLOCK_MMR           (1 << 1U)
#define BOARD_INIT_PLL                  (1 << 2U)
#define BOARD_INIT_PLL_MCU              (1 << 3U)
#define BOARD_INIT_PLL_MAIN             (1 << 4U)
#define BOARD_INIT_MODULE_CLOCK         (1 << 5U)
#define BOARD_INIT_MODULE_CLOCK_MCU     (1 << 6U)
#define BOARD_INIT_MODULE_CLOCK_MAIN    (1 << 7U)
#define BOARD_INIT_DDR                  (1 << 8U)
#define BOARD_INIT_WATCHDOG_DISABLE     (1 << 9U)
#define BOARD_INIT_PINMUX_CONFIG        (1 << 10U)
#define BOARD_INIT_UART_STDIO           (1 << 11U)
#define BOARD_INIT_ICSS_PINMUX          (1 << 12U)
#define BOARD_INIT_ETH_PHY              (1 << 13U)
#define BOARD_INIT_ECC                  (1 << 14U)
#define BOARD_INIT_PLL_OPP_HIGH         (1 << 15U)
#define BOARD_INIT_PLL_OPP_OD           (1 << 16U)
#define BOARD_INIT_PLL_OPP_NOM          (1 << 17U)
/* iceK2G requires board specific Ethernet configurations for
   proper operation of Ethernet interfaces. Applications
   using NSS(Gigabit) or ICSS(10/100mbps) Ethernet inteface
   should call Board_init() with config control macro
   'BOARD_INIT_ETH_PHY' for initializing Gigabit Ethernet PHY and
   'BOARD_INIT_ICSS_ETH_PHY' to invoke the PRU_ICSS Ethernet PHY
   initialization */
/* Config control bit definition for 10/100 Ethernet PHY intialization */
#define BOARD_INIT_ICSS_ETH_PHY         (1 << 18U)
/* Flag to enable EMIF pin mux configuration during Board_init.
   EMIF pin mux is done as part of default pin mux as configuring EMIF pinmux
   while system is running from SDRAM/DDR can corrupt the memory.
   Use this flag only from the applications which are not running from SDRAM/DDR
*/
#define BOARD_INIT_EMIF_PINMUX          (1 << 19U)
/* Applies only to devices with DDR ECC support */
#define BOARD_INIT_DDR_ECC              (1 << 20U)
/* Initializes SerDes module */
#define BOARD_INIT_SERDES_PHY           (1 << 21U)
/* Initializes I2C controller instances used by the board */
#define BOARD_INIT_I2C                  (1 << 22U)
/* De-Initializes I2C controller instances used by the board */
#define BOARD_DEINIT_I2C                (1 << 23U)
#define BOARD_INIT_CPSW9G_ETH_PHY       (1 << 24U)

/* Configures ENET Control(mac mode, delay settings) for CPSW/ICCS ports */
#define BOARD_INIT_ENETCTRL_CPSW2G      (1 << 25U)
#define BOARD_INIT_ENETCTRL_CPSW9G      (1 << 26U)
#define BOARD_INIT_ENETCTRL_ICSS        (1 << 27U)
#define BOARD_INIT_DEFAULT              BOARD_INIT_ALL

#define BOARD_DEINIT_ALL                (0xFFFFFFFFU)
#define BOARD_DEINIT_LOCK_MMR           (1 << 1U)
#define BOARD_DEINIT_MODULE_CLOCK       (1 << 2U)
#define BOARD_DEINIT_UART_STDIO         (1 << 3U)
#define BOARD_DEINIT_DEFAULT            BOARD_DEINIT_ALL

typedef void (*Board_thermalMgmtCallbackFunction_t)(Board_DDRTempEventType DDRTempEventType);

/* @} */

/**
 * \ingroup BOARD_LIB_MODULE
 *
 * @defgroup  BOARD_LIB_MODULE_APIS  Board Standard APIs
 */
/*@{*/

/*************************************************************
 * APIs                                                      *
 *************************************************************/

/**
 *  @brief      Get board information.
 *
 *  @param[out] info
 *    This structure will have board information on return
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_getIDInfo(Board_IDInfo *info);

/**
 *  @brief      Get board information - v2
 *
 *  @param[out] info
 *    This structure will have board information on return
 *  @param[in] slaveAddress
 *    I2C slave address of EEPROM to be read
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_getIDInfo_v2(Board_IDInfo_v2 *info, uint8_t slaveAddress);

/**
 *  @brief      Set board information - v2
 *
 *  @param[in] info
 *    This structure will have board information
 *  @param[in] slaveAddress
 *    I2C slave address of EEPROM to be write
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_writeIDInfo_v2(Board_IDInfo_v2 *info, uint8_t slaveAddress);

/**
 *  @brief      Get SoC information.
 *
 *  @param[out] socInfo
 *    This structure will have SoC information on return
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_getSoCInfo(Board_SoCInfo *socInfo);

/**
 *  @brief      Initialization functions for a specific board.
 *
 *  @param[in] cfg
 *    Param to indicate what to initialize when calling Board_init()
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_init(Board_initCfg cfg);

/**
 * @brief  Board library deinitialization function
 *
 *  BOARD_DEINIT_UART_STDIO -
 *      Deinitializes the UART module.
 *
 * @param   cfg [IN]    Board configuration flags
 *
 * @return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_deinit(Board_initCfg cfg);

/**
 *  @brief      Initialize Board DDR Temperature monitoring.
 *
 *  @param[in] callbackFunction
 *    Callback function to be called with thermal events
 *
 *  @return Board_STATUS Returns status on API call
 *
 */
Board_STATUS Board_DDRTempMonitoringInit(Board_thermalMgmtCallbackFunction_t callbackFunction);

#ifdef __cplusplus
}
#endif

#endif
/* @} */
