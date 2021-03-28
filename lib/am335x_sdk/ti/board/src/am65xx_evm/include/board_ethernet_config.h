/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * \brief  board_ethernet_config.h
 *
 * This file contains the Ethernet PHY configurations for AM65XX board
 *
 */

#ifndef _BOARD_ETHERNET_CONFIG_H_
#define _BOARD_ETHERNET_CONFIG_H_

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief  Board specific configurations for ICSS EMAC Ethernet PHYs
 *
 * This function takes care of configuring the internal delays for ICSS
 * Ethernet PHY
 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void);

/**
 * \brief  Board specific configurations for MCU Ethernet PHY
 *
 * This function takes care of configuring the internal delays for MCU gigabit
 * Ethernet PHY
 *
 * \return  none
 */
Board_STATUS Board_mcuEthConfig(void);

/**
 * \brief  Function to configure the Ethernet PHY speed
 *
 * This function takes care of configuring the speed of the
 * Ethernet ports connected to MCU and ICSSG MAC ports.
 *
 * Below are the ports supported on AM65xx EVM
 *
 * ICSS2 PRU 0  - port 4
 * ICSS2 PRU 1  - port 5
 * MCU Ethernet - port 6
 * port 0 to 3 are not valid for AM65xx EVM
 *
 * \param   port [IN]    Ethernet PHY Port number (check above table)
 * \param   speed [IN]   Speed selection
 *                       0 -  100 mpbs
 *                       1 -  1000 mpbs
 *
 * \return  none
 */
Board_STATUS Board_ethPhySpeedConfig(int8_t port, uint8_t speed);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_ETHERNET_CONFIG_H_ */
