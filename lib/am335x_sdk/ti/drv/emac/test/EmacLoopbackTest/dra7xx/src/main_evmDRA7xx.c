/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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

/**
 *  \file     main_evmDRA7xx.c
 *
 *  \brief    This is the Loopback test code for the EMAC Driver. The test code uses
 *      XDC/BIOS and showcases usage of the EMAC Driver exported API
 *      for sending/receiving Ethernet packets.
 *
 */


#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* EMAC Driver Header Files */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

/* UART Driver Header Files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* Board Level Header Files */
#include <ti/board/board.h>

/* Test Application Local Header Files */
#include <ti/drv/emac/test/EmacLoopbackTest/test_loc.h>
#include <ti/drv/emac/test/EmacLoopbackTest/test_utils.h>


/* Number of MAC ports and their PHY addressese */
#if defined(evmDRA72x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     3
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     0 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#elif defined(evmDRA75x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     2
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     3 /* Populated, but not supported in
                                            * this test.
                                            */
#define DRA7XX_EVM_NUM_PORTS             1 /* Only for the sake of this test.
                                            * Would otherwise be set to 2.
                                            */
#elif defined(evmDRA78x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     0
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     1 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#endif


uint32_t linkStatus = 0;
EMAC_MAC_ADDR_T macTest;
int32_t emac_check_loopback_status(uint32_t port);
void dra7xx_board_init_task(UArg arg0, UArg arg1);


/*
 *  @b Description
 *  @n
 *      Entry point for the application test code.
 *
 *  @retval
 *      None.
 */
int main(void)
{
    Task_Params taskParams;

    /* Board initialization requires to be run on a task context (due to I2C) */
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "BoardInit";
    Task_create(dra7xx_board_init_task, &taskParams, NULL);

    /* Start BIOS */
    BIOS_start();
    return 0;
}

EMAC_HwAttrs_V4 emac_cfg;
EMAC_OPEN_CONFIG_INFO_T open_cfg;
EMAC_CONFIG_INFO_T cfg_info;
EMAC_DRV_ERR_E ret;
EMAC_CHAN_MAC_ADDR_T chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];

void app_test_task_init_emac(UArg arg0, UArg arg1)
{
    int32_t i;
    EMAC_DRV_ERR_E ret;
    app_init();
    EMAC_socGetInitCfg(0, &emac_cfg);

    /* Set configuration parameters for loopback */
    open_cfg.hwAttrs = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb = app_alloc_pkt;
    open_cfg.free_pkt_cb = app_free_pkt;
    open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;
    open_cfg.loop_back = 1;
    open_cfg.master_core_flag = 1;
    open_cfg.max_pkt_size = 1518;
    open_cfg.mdio_flag = 1;
    open_cfg.num_of_chans = 1;
    open_cfg.num_of_rx_pkt_desc = 64;
    open_cfg.num_of_tx_pkt_desc = 64;
    open_cfg.phy_addr = 0;
    open_cfg.p_chan_mac_addr = &chan_cfg[0];

    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    /* Use any uni-cast MAC address */
    for (i = 0; i < 6; i++) {
        macTest.addr[i] = i + 2;
    }
    chan_cfg[0].p_mac_addr = &macTest;

    /* Open the EMAC driver */
    ret = emac_open(0, &open_cfg);
    if (ret == EMAC_DRV_RESULT_OPEN_PORT_ERR) {
        UART_printf("Failed to open the EMAC driver: %d\n", ret);
        return;
    }

    UART_printf("EMAC driver open sucess\n");

    emac_check_loopback_status(0);
}

void dra7xx_board_init_task(UArg arg0, UArg arg1)
{
    Task_Params taskParams;
    uint8_t i;

    /* Set pinmux, IRQ crossbar, GMII selection */
    Board_init(BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_ETH_PHY |
               BOARD_INIT_UART_STDIO);

    /* Set addresses of the two PHYs in the EVM */
    EMAC_socGetInitCfg(0, &emac_cfg);
    emac_cfg.numPorts = DRA7XX_EVM_NUM_PORTS;
    emac_cfg.port[0].phy_addr = EMAC_CPSW_PORT0_PHY_ADDR_EVM;
    emac_cfg.port[1].phy_addr = EMAC_CPSW_PORT1_PHY_ADDR_EVM;
    emac_cfg.macModeFlags = EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
    EMAC_socSetInitCfg(0, &emac_cfg);

    /* Pass EMAC driver configuration (no-op) */
    cfg_info.mcast_cnt = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter = EMAC_PKTFLT_MULTICAST;
    emac_config(0, &cfg_info);

    /* Create the task to send packets for loopback */
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacSendPkt";
    Task_create(app_test_task_send_pkts, &taskParams, NULL);

    /* Create the  task to init app and open driver.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "InitEmac";
    Task_create(app_test_task_init_emac, &taskParams, NULL);

    /* Create the  task to poll driver to rx packets driver.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "EmacRxPkt";
    Task_create(app_test_task_poll_pkt, &taskParams, NULL);
}

int32_t emac_check_loopback_status(uint32_t port)
{
    ENETPHY_DEVICE phyDev;
    EMAC_HwAttrs_V4 emac_cfg;
    uint32_t phy_addr;
    uint32_t loopbackState;
    uint32_t val;

    EMAC_socGetInitCfg(0, &emac_cfg);
    phyDev.miibase = emac_cfg.mdio_base;
    phy_addr = emac_cfg.port[port].phy_addr;

    linkStatus = 0;
    while (!linkStatus) {
        /* First read the BSR of the PHY */
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BSR, phy_addr, &val);

        if (val & ENETPHY_LINK_STATUS) {
            linkStatus = 1;
        }
        Task_sleep(1);
    }

    UART_printf("Link status: %s\n", linkStatus?"Up":"Down\n");

    /* Determine if in loopback */
    Task_sleep(10);
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val);
    if (val & (1<<14)) {
        loopbackState = 1;
    } else {
        loopbackState = 0;
    }

    UART_printf("Link is%s in loopback state\n", loopbackState?"":" not");

    return loopbackState;
}
