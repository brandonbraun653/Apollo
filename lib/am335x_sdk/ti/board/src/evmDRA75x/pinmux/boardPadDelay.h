/**
 * \file  boardPadDelay.h
 *
 * \brief   This file contains runtime timing configuration structure declarations. For details on timing and
 *          switching configuratio refer to "Timing Requirements and Switching Characteristics" subsection
 *          in the device Data Manual.
 *
 * \copyright Copyright (CU) 2018 Texas Instruments Incorporated -
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

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \brief This structure defines the delay configuration for IO Delay Config
 *         Registers: CFG_X_IN, CFG_X_OUT and CFG_X_OEN.
 */
typedef struct boardDelayCfg
{
    uint16_t offset;
    /**< Offset for Delay Configuration Register */
    uint16_t aDelay;
    /**< Value of Process Agnostic(Unaware) Delay */
    uint16_t gDelay;
    /**< Value of Process Gnostic(Aware) Delay */
} boardDelayCfg_t;

/**
 *  \brief This structure defines the delay configuration associated with a
 *         particular pad as given by PinMux.
 */
typedef struct boardPadDelayCfg
{
    uint16_t        offset;
    /**< Offset for Pad Configuration Register */
    uint32_t        regVal;
    /**< Value of Pad configuration Register as given by the PinMux */
    boardDelayCfg_t delayConfigIn;
    /**< Delay Configuration of CFG_X_IN register */
    boardDelayCfg_t delayConfigOen;
    /**< Delay Configuration of CFG_X_OEN register */
    boardDelayCfg_t delayConfigOut;
    /**< Delay Configuration of CFG_X_OUT register */
} boardPadDelayCfg_t;

/**
 *  \brief This structure defines the alternate muxing configuration associated with a
 *         particular pad as given by PinMux.
 */
typedef struct boardPadDelayAltGpCfg
{
    uint32_t regAddr;
    /**< Register address of alternate Pad Configuration Register */
    uint32_t regVal;
    /**< Value of Alternate Pad configuration Register as given by the PinMux */
} boardPadDelayAltGpCfg_t;

/**
 *  \brief Structure defining the mapping of MMC operational mode to its
 *         corresponding pad configuration structure.
 */
typedef struct mmcBoardPadCfgTable
{
    int32_t                   mmcMode;
    /**< MMC operational mode. */
    const boardPadDelayCfg_t *mmcPadCfg;
    /**< Pointer to the structure containing the pad configuration data for an
         MMC interface */
    uint16_t                  noPins;
    /**< Value to indicate the number of pins. */
} mmcBoardPadCfgTable_t;

/**
 *  \brief Enumerates the different operating modes defined for an MMC device.
 *         This enum to include all the modes of all instances.
 */
typedef enum mmcMode
{
    MMC1_DEFAULT_PLB,
    /**< Default Pad Loopback mode of MMC1. */
    MMC1_HS_ILB,
    /**< High speed Internal Loopback mode of MMC1. */
    MMC1_HS_PLB,
    /**< High speed Pad Loopback mode of MMC1. */
    MMC1_SDR12_PLB,
    /**< SDR12 Pad Loopback mode of MMC1. */
    MMC1_SDR12_ILB,
    /**< SDR12 Internal Loopback mode of MMC1. */
    MMC1_SDR25_ILB,
    /**< SDR25 Internal Loopback mode of MMC1. */
    MMC1_SDR50_ILB,
    /**< SDR50 Internal Loopback mode of MMC1. */
    MMC1_SDR50_PLB,
    /**< SDR50 Pad Loopback mode of MMC1. */
    MMC1_DS_ILB,
    /**< Default speed Internal Loopback mode of MMC1. */
    MMC1_DDR50_ILB,
    /**< DDR50 Internal Loopback mode of MMC1. */
    MMC1_DDR50_PLB,
    /**< DDR50 Pad Loopback mode of MMC1. */
    MMC1_SDR104,
    /**< SDR104 mode of MMC1. */
    MMC2_DEFAULT_HS_PLB,
    /**< Default High Speed Pad Loopback mode of MMC2. */
    MMC2_DEFAULT_STD_PLB,
    /**< Default Standard Pad Loopback mode of MMC2. */
    MMC2_DDR_ILB,
    /**< DDR Internal Loopback mode of MMC2. */
    MMC2_DDR_PLB,
    /**< DDR Pad Loopback mode of MMC2. */
    MMC2_HS200,
    /**< HS200 mode of MMC2. */
    MMC2_STD_ILB,
    /**< Standard Internal Loopback mode of MMC2. */
    MMC2_HS_ILB,
    /**< High speed Internal Loopback mode of MMC2. */
    MMC3_DS,
    /**< Default speed mode of MMC3. */
    MMC3_HS,
    /**< High speed mode of MMC3. */
    MMC3_SDR12,
    /**< SDR12 mode of MMC3. */
    MMC3_SDR25,
    /**< SDR25 mode of MMC3. */
    MMC3_SDR50,
    /**< SDR50 mode of MMC3. */
    MMC4_DS,
    /**< Default speed mode of MMC4. */
    MMC4_HS,
    /**< High speed mode of MMC4. */
    MMC4_SDR12,
    /**< SDR12 mode of MMC4. */
    MMC4_SDR25,
    /**< SDR25 mode of MMC4. */
    MMC_MODE_INVALID = -1
    /**< Invalid MMC Mode */
} mmcMode_t;

/**
 *  \brief Function to return the pad config array and size.
 */
const boardPadDelayCfg_t *boardPadGetCfg(uint32_t *size);

/**
 *  \brief    Function to return the runtime pinmux config table for the MMCSD
 *            instance.
 */
mmcBoardPadCfgTable_t *BoardGetMmcCtrlPadPinmuxTable(uint32_t instance);

#ifdef __cplusplus
}
#endif
