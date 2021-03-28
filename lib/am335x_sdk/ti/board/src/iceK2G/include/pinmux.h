/******************************************************************************
 * Copyright (c) 2017-2018 Texas Instruments Incorporated - http://www.ti.com
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

#ifndef PINMUX_H
#define PINMUX_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Below boundary check macros are not avaialable for C++ compilers */
#ifdef __cplusplus

#ifndef INT_MAX
#define INT_MAX       (0x7FFFFFFF)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX    (0xFFFFFFFFU)
#endif

#endif

/**
 * \brief Invalid Frequency
 */
#define CHIPDB_INVALID_FREQUENCY        (uint32_t)0x0U

/**
 * \brief Invalid Temperature
 */
#define CHIPDB_INVALID_TEMPERATURE      (int32_t)INT_MAX

/**
 * \brief Invalid Address
 */
#define CHIPDB_INVALID_ADDRESS          (uint32_t)UINT32_MAX

/**
 * \brief Invalid Interrupt Number
 */
#define CHIPDB_INVALID_INTERRUPT_NUM    (UINT32_MAX)

/**
 * \brief Invalid instance Number
 */
#define CHIPDB_INVALID_INSTANCE_NUM     (-1)

/**
 * \brief Invalid pinmux pin
 */
#define PINMUX_INVALID_PIN              (-1)

typedef enum
{
    CHIPDB_MOD_ID_PRU_ICSS,
    CHIPDB_MOD_ID_PWMSS,
    CHIPDB_MOD_ID_GPIO,
    CHIPDB_MOD_ID_UART,
    CHIPDB_MOD_ID_PCIE,
    CHIPDB_MOD_ID_MMCSD,
    CHIPDB_MOD_ID_DEBUGSS,
    CHIPDB_MOD_ID_EMAC,
    CHIPDB_MOD_ID_CPSW,
    CHIPDB_MOD_ID_DDR,
    CHIPDB_MOD_ID_MCSPI,
    CHIPDB_MOD_ID_SYSTEM,
    CHIPDB_MOD_ID_I2C,
    CHIPDB_MOD_ID_QSPI,
    CHIPDB_MOD_ID_INVALID = UINT32_MAX
} chipdbModuleID_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Structure defining the pin configuration parameters.
 *
 */
typedef struct pinmuxPerCfg
{
    int16_t pinOffset;
    /**< Register offset for configuring the pin */
    int16_t optParam;
    /**< Optional param to hold the peripheral specific data */
    int32_t pinSettings;
    /**< Value to be configured,
          - Active mode configurations like Mux mode, pull config, Rx enable &
            slew rate
          - Sleep mode configurations like Deep sleep enable, o/p value &
            pull config
          - Wake up enable/disable
        Refer TRM section "7.2.1 Pad Control Registers" for more details.
    */
}pinmuxPerCfg_t;

/**
 *  \brief Structure defining the pin configuration for different instances of
 *         a module.
 */
typedef struct pinmuxModuleCfg
{
    int16_t modInstNum;
    /**< Instance number of the ip */
    int16_t doPinConfig;
    /**< Flag indicating whether this instance has to be configured. This flag
         can be altered with separate API (PinMuxConfigEnable()).
         Default configuration will be set to TRUE, but can be altered for
         different scenarios (like power management). */
    pinmuxPerCfg_t* instPins;
    /**< Pointer to list of pins corresponding to this instance */
}pinmuxModuleCfg_t;

/**
 *  \brief Structure defining the pin configuration of a board.
 */
typedef struct pinmuxBoardCfg
{
    chipdbModuleID_t moduleId;
    /**< Module ID */
    pinmuxModuleCfg_t* modulePinCfg;
    /**< Pin config info of a module: #pinmuxModuleCfg_t */
}pinmuxBoardCfg_t;

#ifdef __cplusplus
}
#endif

#endif
