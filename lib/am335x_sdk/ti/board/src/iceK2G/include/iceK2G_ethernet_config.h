/**
 *   @file  iceK2G_ethernet_config.h
 *
 *   @brief
 *      This file contains the Ethernet PHY configurations for K2G ICE board
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2017, Texas Instruments, Inc.
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
 *  \par
*/

#ifndef _ICEK2G_ETHERNET_CONFIG_H_
#define _ICEK2G_ETHERNET_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_SWITCH_DEFAULT_MDIOBUSFREQ      (2200000u)
#define BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ    (200000000u)
#define BOARD_PHYCFG_DELAY                    (100u)
#define BOARD_GIGPHY_MADIO_ADDR               (CSL_NSS_0_CFG_REGS + 0x00200F00)

#define BOARD_ICSS_ETHPHY_STRAP_PIN_COUNT     (28)

#define BOARD_PR0_MII0_RESET_PADCONFIG         (PADCONFIG_PIN_NUM(23))
#define BOARD_PR0_MII0_RESET_GPIO_PIN          (23)
#define BOARD_PR0_MII0_RESET_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR0_MII1_RESET_PADCONFIG         (PADCONFIG_PIN_NUM(21))
#define BOARD_PR0_MII1_RESET_GPIO_PIN          (21)
#define BOARD_PR0_MII1_RESET_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR1_MII0_RESET_PADCONFIG         (PADCONFIG_PIN_NUM(20))
#define BOARD_PR1_MII0_RESET_GPIO_PIN          (20)
#define BOARD_PR1_MII0_RESET_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR1_MII1_RESET_PADCONFIG         (PADCONFIG_PIN_NUM(24))
#define BOARD_PR1_MII1_RESET_GPIO_PIN          (24)
#define BOARD_PR1_MII1_RESET_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_MUX_MII_CTL_PRU0MII0_PADCONFIG         (PADCONFIG_PIN_NUM(117))
#define BOARD_MUX_MII_CTL_PRU0MII0_GPIO_PIN          (106)
#define BOARD_MUX_MII_CTL_PRU0MII0_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_MUX_MII_CTL_PRU0MII1_PADCONFIG         (PADCONFIG_PIN_NUM(118))
#define BOARD_MUX_MII_CTL_PRU0MII1_GPIO_PIN          (107)
#define BOARD_MUX_MII_CTL_PRU0MII1_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_OE_PRU0MII0_1_PADCONFIG         (PADCONFIG_PIN_NUM(137))
#define BOARD_OE_PRU0MII0_1_GPIO_PIN          (66)
#define BOARD_OE_PRU0MII0_1_GPIO_PORT         (GPIO_PORT_1)

#define BOARD_OE_PRU0MII0_2_PADCONFIG         (PADCONFIG_PIN_NUM(138))
#define BOARD_OE_PRU0MII0_2_GPIO_PIN          (67)
#define BOARD_OE_PRU0MII0_2_GPIO_PORT         (GPIO_PORT_1)

#define BOARD_OE_PRU0MII1_1_PADCONFIG         (PADCONFIG_PIN_NUM(127))
#define BOARD_OE_PRU0MII1_1_GPIO_PIN          (56)
#define BOARD_OE_PRU0MII1_1_GPIO_PORT         (GPIO_PORT_1)

#define BOARD_OE_PRU0MII1_2_PADCONFIG         (PADCONFIG_PIN_NUM(128))
#define BOARD_OE_PRU0MII1_2_GPIO_PIN          (57)
#define BOARD_OE_PRU0MII1_2_GPIO_PORT         (GPIO_PORT_1)

#define BOARD_PR0_MII0_INT_PADCONFIG         (PADCONFIG_PIN_NUM(28))
#define BOARD_PR0_MII0_INT_GPIO_PIN          (28)
#define BOARD_PR0_MII0_INT_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR0_MII1_INT_PADCONFIG         (PADCONFIG_PIN_NUM(29))
#define BOARD_PR0_MII1_INT_GPIO_PIN          (29)
#define BOARD_PR0_MII1_INT_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR1_MII0_INT_PADCONFIG         (PADCONFIG_PIN_NUM(17))
#define BOARD_PR1_MII0_INT_GPIO_PIN          (17)
#define BOARD_PR1_MII0_INT_GPIO_PORT         (GPIO_PORT_0)

#define BOARD_PR1_MII1_INT_PADCONFIG         (PADCONFIG_PIN_NUM(22))
#define BOARD_PR1_MII1_INT_GPIO_PIN          (22)
#define BOARD_PR1_MII1_INT_GPIO_PORT         (GPIO_PORT_0)

Board_STATUS Board_gigEthConfig(void);
Board_STATUS Board_icssEthConfig(void);

#ifdef __cplusplus
}
#endif

#endif /* _ICEK2G_ETHERNET_CONFIG_H_ */
