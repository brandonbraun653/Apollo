/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   board_pinmux.h
 *
 * \brief  Board pinmux header files
 *
 */

#ifndef _BOARD_PIN_MUX_H_
#define _BOARD_PIN_MUX_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/board/src/j721e_evm/include/pinmux.h>
#include <ti/board/src/j721e_evm/J721E_pinmux.h>
#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_MODE_PIN_MASK            (0xFU)
#define BOARD_PINMUX_BIT_MASK          (0xFFF8FFF0U)
#define BOARD_GPIO_PIN_MUX_CFG         (0x50007U)

#define BOARD_PINMUX_CUSTOM             (0)  // Default
#define BOARD_PINMUX_AUTO               (1U)
#define BOARD_PINMUX_INFO_VOUT          (0)  // Default
#define BOARD_PINMUX_INFO_VPFE          (1U)
#define BOARD_PINMUX_GESI_ICSSG         (2U)
#define BOARD_PINMUX_GESI_CPSW9G        (3U)
#define BOARD_PINMUX_CSI_COMMON         (0)  // Default
#define BOARD_PINMUX_ENET_QSGMII        (0)  // Default
#define BOARD_PINMUX_FSS_OSPI           (0)  // Default
#define BOARD_PINMUX_FSS_HPB            (1)

/* Structure to set the board pinmux configuration */
typedef struct Board_PinmuxConfig_s
{
    /**
     * Pinmux auto config control
     *  BOARD_PINMUX_CUSTOM(0) - Pinmux is based on other add-on card
     *  settings of the pinmux config.
     *  BOARD_PINMUX_AUTO(1) - Pinmux is based on board detection by
     *  reading the board ID info from EEPROM.
     *  When auto mode is enabled, all other below fields of
     *  pinmux config will be ignored.
     */
    uint8_t autoCfg;

    /**
     * Pinmux config control for GESI/Infotainment expansion connector
     *  BOARD_PINMUX_GESI_ICSSG(0) - GESI Board (ICSSG RGMII)
     *  BOARD_PINMUX_GESI_CPSW9G(1) - GESI Board (CPSW9G RGMII)
     *  BOARD_PINMUX_INFOTAINMENT(2) - Infotainment Board
     */
    uint8_t gesiExp;

    /**
     * Pinmux config control for CSI expansion connector
     *  BOARD_PINMUX_CSI_FUSION(0) - Fusion-2 board
     *  BOARD_PINMUX_CSI_MV(1) - MV capture board
     *  BOARD_PINMUX_CSI_LI(2) - LI capture board
     */
    uint8_t csiExp;

    /**
     * Pinmux config control for ENET expansion connector
     *  BOARD_PINMUX_ENET_QSGMII(0) - ENET QSGMII board
     */
     uint8_t enetExp;

    /**
     * Pinmux config control for OSPI/Hyperflash mux
     *  BOARD_PINMUX_FSS_OSPI(0) - OSPI
     *  BOARD_PINMUX_FSS_HPB (1) - Hyperbus
     */
     uint8_t fssCfg;

} Board_PinmuxConfig_t;

/**
 *  \brief  Sets pinmux mode for a pin in main domain
 *
 *  Only pinmux mode is updated by this function. Other values of
 *  padconfig register remains unchanged after this function call.
 *
 *  \param    offset [IN]    Pad config offset of the pin
 *  \param    mode   [IN]    Pad config mux mode.
 *
 *  \return   None
 */
void Board_pinMuxSetMode(uint32_t offset, uint32_t mode);

/**
 *  \brief  Sets pinmux mode for a pin in wake-up domain
 *
 *  Only pinmux mode is updated by this function. Other values of
 *  padconfig register remains unchanged after this function call.
 *
 *  \param    offset [IN]    Pad config offset of the pin
 *  \param    mode   [IN]    Pad config mux mode.
 *
 *  \return   None
 */
void Board_pinMuxSetModeWkup(uint32_t offset, uint32_t mode);

/**
 *  \brief Sets padconfig register of a pin at given offset
 *
 *  Configures whole padconfig register of the pin at given offset
 *  with the value in 'muxData'.
 *
 *  \param   domain  [IN]  SoC domain for pinmux
 *  \n                      BOARD_SOC_MAIN_DOMAIN - Main domain
 *  \n                      BOARD_SOC_WKUP_DOMAIN - Wakeup domain
 *
 *  \param   offset  [IN]  Pad config offset of the pin
 *  \param   muxData [IN]  Value to be written to padconfig register
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxSetReg(uint8_t  domain,
                                uint32_t offset,
                                uint32_t muxData);

/**
 *  \brief Gets padconfig register of a pin at given offset
 *
 *  \param   domain  [IN]  SoC domain for pinmux
 *  \n                      BOARD_SOC_MAIN_DOMAIN - Main domain
 *  \n                      BOARD_SOC_WKUP_DOMAIN - Wakeup domain
 *  \param   offset  [IN]  Pad config offset of the pin
 *  \param   muxData [OUT] Value of padconfig register
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxGetReg(uint8_t  domain,
                                uint32_t offset,
                                uint32_t *muxData);

/**
 *  \brief Sets the board pinmux configuration.
 *
 *  There are multiple addon cards that can connected to baseboard and
 *  multiple addon cards can be connected to one expansion connector.
 *  Pinmux configured through Board_init will be set to a default
 *  combination of the boards which can be changed using this function.
 *
 *  \n Usage:
 *  \n - Call Board_pinmuxGetCfg to get default pinmux config
 *  \n - Call Board_pinmuxSetCfg to change pinmux config
 *  \n - Call Board_init with pinmux flag to apply the updated pinmux config
 *
 *  \param   pinmuxCfg [IN]  Pinmux configurations
 *
 *  \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxSetCfg(Board_PinmuxConfig_t *pinmuxCfg);

/**
 *  \brief Gets the board pinmux configuration.
 *
 *  There are multiple addon cards that can connected to baseboard and
 *  multiple addon cards can be connected to one expansion connector.
 *  Pinmux configured through Board_init will be set to a default
 *  combination of the boards which can be read using this function.
 *
 *  \param   pinmuxCfg [IN]  Pinmux configurations
 *
 *  \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxGetCfg(Board_PinmuxConfig_t *pinmuxCfg);

/**
 * \brief  Board pinmuxing update function
 *
 * Provides the option to configure/update the pinmux.
 * This function can be used to change the pinmux set by
 * Board_init by default.
 *
 * \param   pinmuxData [IN]  Pinmux data structure
 * \param   domain     [IN]  SoC domain for pinmux
 *  \n                        BOARD_SOC_MAIN_DOMAIN - Main domain
 *  \n                        BOARD_SOC_WKUP_DOMAIN - Wakeup domain
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxUpdate (pinmuxBoardCfg_t *pinmuxData,
                                 uint32_t domain);

/**
 * \brief  Board pinmuxing enable function
 *
 * Enables pinmux for the board interfaces. Pin mux is done based
 * on the default/primary functionality of the board. Any pins shared by
 * multiple interfaces need to be reconfigured to access the secondary
 * functionality.
 *
 * \param   void
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxConfig (void);

/**
 * \brief  Board UART Tx pinmuxing enable function
 *
 * Enables pinmux for the UART Tx pin of the default UART instance used
 * by ROM/SBL.
 *
 * \param   void
 *
 * \return  void
 *
 */
void Board_uartTxPinmuxConfig(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _BOARD_PIN_MUX_H_ */
