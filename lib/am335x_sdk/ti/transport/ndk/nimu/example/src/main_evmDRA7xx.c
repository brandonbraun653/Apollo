/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/stkmain.h>
#include "ti/ndk/inc/os/osif.h"

/* EMAC Driver Header Files */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

/* UART Driver Header Files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* I2C Driver Header Files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/* Board Level Header Files */
#include <ti/board/board.h>


/* Enable the below macro to have prints on the IO Console */
/* #define IO_CONSOLE */
#ifndef IO_CONSOLE
#define NIMU_log                UART_printf
#else
#define NIMU_log                printf
#endif

/* Number of MAC ports and their PHY addresses */
#if defined(evmDRA72x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     3
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     0 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#elif defined(evmDRA75x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     2
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     3
#define DRA7XX_EVM_NUM_PORTS             2
#define NIMU_DUAL_MAC_MODE
#elif defined(evmDRA78x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     0
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     1 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#endif

/* NDK max table entries */
#define MAX_TABLE_ENTRIES                3

NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[MAX_TABLE_ENTRIES];

extern char *LocalIPAddr;

#ifdef NIMU_DUAL_MAC_MODE
/* Static IP Address settings for interface 2 */
const char *ip2Addr    = "192.168.2.4";
const char *ip2Mask    = "255.255.255.0";
const char *ip2Gateway = "192.168.2.1";
#endif

extern int CpswEmacInit(STKEVENT_Handle hEvent);


/**
 *  \name main
 *  \brief Main Function
 *  \param none
 *  \return none
 *
 */
int main()
{
    EMAC_HwAttrs_V4 cfg;
    int index = 0;

    /* Set pinmux, IRQ crossbar */
    Board_init(BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO | BOARD_INIT_ETH_PHY);

    /* Update PHY addresses */
    EMAC_socGetInitCfg(0, &cfg);
    cfg.numPorts = DRA7XX_EVM_NUM_PORTS;
    cfg.port[0].phy_addr = EMAC_CPSW_PORT0_PHY_ADDR_EVM;
    cfg.port[1].phy_addr = EMAC_CPSW_PORT1_PHY_ADDR_EVM;
    cfg.macModeFlags = EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
    EMAC_socSetInitCfg(0, &cfg);

    NIMUDeviceTable[index++].init = &CpswEmacInit;
#ifdef NIMU_DUAL_MAC_MODE
    NIMUDeviceTable[index++].init = &CpswEmacInit;
#endif
    NIMUDeviceTable[index].init = NULL;

    BIOS_start();

    return -1;
}

void netOpenHook(void)
{
    NIMU_log("netOpenHook: SYS/BIOS Ethernet/IP (CPSW) Sample application, EVM IP address: %s\n", LocalIPAddr);
#ifdef NIMU_DUAL_MAC_MODE
    NIMU_log("netOpenHook: SYS/BIOS Ethernet/IP (CPSW) Sample application, EVM IP address 2: %s\n", ip2Addr);
#endif
}

void netCloseHook(void)
{
    NIMU_log("netCloseHook\n");
}

/* Called from ti_nkd_config_Global_stackThread() to run user setup code */
void stackInitHook(void* hCfg)
{
#ifdef NIMU_DUAL_MAC_MODE
    CI_IPNET ipnet;
    CI_ROUTE route;

    /* Add IP address for interface 2 */
    ipnet.IPAddr = inet_addr(ip2Addr);
    ipnet.IPMask = inet_addr(ip2Mask);
    CfgAddEntry(hCfg, CFGTAG_IPNET, 2, 0, sizeof(CI_IPNET), (uint8_t *)&ipnet, 0);

    /* Add gateway for interface 2 */
    bzero(&route, sizeof(route));
    route.IPDestAddr = 0;
    route.IPDestMask = 0;
    route.IPGateAddr = inet_addr(ip2Gateway);
    CfgAddEntry(hCfg, CFGTAG_ROUTE, 0, 0, sizeof(CI_ROUTE), (uint8_t *)&route, 0);
#endif
}
