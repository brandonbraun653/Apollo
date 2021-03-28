/*
 * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/sysbios/family/arm/a8/Mmu.h>


/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

#include <ti/drv/emac/soc/emac_soc_v4.h>

/* Test application local header file */
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"
#include "ti/drv/emac/test/EmacLoopbackTest/test_utils.h"
#include <ti/starterware/include/types.h>
#include <ti/starterware/include/hw/hw_types.h>
#include <ti/starterware/include/hw/hw_control_am335x.h>
#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/starterware/include/ethernet.h>
#include <ti/starterware/include/soc_control.h>

#include <ti/board/board.h>


/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>




uint32_t emac_check_loopback_status(uint32_t port);

/* ========================================================================== */
/*                            Global Variables                                */
uint32_t linkStatus = 0;
EMAC_MAC_ADDR_T macTest ;

/**
*  @b Description
*  @n
*      Entry point for the application test code.
*
*  @retval
*      None.
*/
int main(void)
{
    /* Call board init functions */
    Task_Params taskParams;
    EMAC_HwAttrs_V4 emac_cfg;
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CONFIG_INFO_T cfg_info;
    EMAC_DRV_ERR_E open_ret;
    Board_STATUS boardInitStatus =0;
    Error_Block eb;
    Error_init(&eb);
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];
    uint8_t i;

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK;
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=0)
    {
        UART_printf("Board_init failure\n");
        return(0);
    }
    UART_printf("Board_init success\n");


    SOCCtrlCpswPortMacModeSelect(1, ETHERNET_MAC_TYPE_RGMII);
    SOCCtrlCpswPortMacModeSelect(2, ETHERNET_MAC_TYPE_RGMII);

    EMAC_socGetInitCfg(0, &emac_cfg);
    emac_cfg.macModeFlags = EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
    emac_cfg.numPorts = 1;
    EMAC_socSetInitCfg(0, &emac_cfg);
    app_init();

    open_cfg.hwAttrs = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb = app_alloc_pkt;
    open_cfg.free_pkt_cb = app_free_pkt;
    open_cfg.loop_back = 1;
    open_cfg.master_core_flag = 1;
    open_cfg.max_pkt_size = 1518; 
    open_cfg.mdio_flag = 1;
    open_cfg.num_of_chans = 1;
    open_cfg.num_of_rx_pkt_desc = 64;
    open_cfg.num_of_tx_pkt_desc = 64;
    open_cfg.phy_addr = 0;

    open_cfg.p_chan_mac_addr = &chan_cfg[0];
    
    open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;


    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    
    

    /* use any uni-cast MAC address */
    for (i=0;i<6;i++)
    {
        macTest.addr[i] = i + 2;
    }
     chan_cfg[0].p_mac_addr = & macTest;

    if ((open_ret = emac_open(0, &open_cfg)) == EMAC_DRV_RESULT_OPEN_PORT_ERR)
    {
        UART_printf("main: emac_open failure: %d\n", open_ret);
    }
    else
        UART_printf("main: emac_open sucess\n");

    cfg_info.mcast_cnt = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter = EMAC_PKTFLT_MULTICAST;
    emac_config(0, &cfg_info);

    if (emac_check_loopback_status(0) !=1)
    {
        UART_printf("Link not in loopback state, return error\n");
        return -1;
    }

    /* Create the  task to send packets for loopback.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacSendPkt";
    Task_create(app_test_task_send_pkts, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "EmacPktPkt";
    Task_create(app_test_task_poll_pkt, &taskParams, NULL);


    /* Start BIOS */
    BIOS_start();
    return 0;
}

uint32_t emac_check_loopback_status(uint32_t port)
{
    uint32_t retries;
    uint32_t phy_addr=0;
    uint32_t val16;//, debug_data;
    uint32_t loopbackState=0;
    ENETPHY_DEVICE phyDev;
    EMAC_HwAttrs_V4 emac_cfg;
    uint32_t macPort = port + 1;
    linkStatus = 0;
    retries = 2000;

    EMAC_socGetInitCfg(0, &emac_cfg);
    phyDev.miibase = emac_cfg.mdio_base;
    if(macPort==1)
    {
        phy_addr = emac_cfg.port[0].phy_addr;
    }
    else if(macPort==2)
    {
        phy_addr = emac_cfg.port[1].phy_addr;
    }
    else
    {
        return 0;
    }

    while (linkStatus == 0)
    {
        /* First read the BSR of the PHY */
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BSR, phy_addr, &val16);

        if(val16 & ENETPHY_LINK_STATUS)
        {
            linkStatus = 1;
        }
        app_delay(10000);
        retries--;
    }

    UART_printf("link status: %s    ", linkStatus?"Up":"Down\n");

    //determine if in loopback
    app_delay(1000);
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
    if(val16&(1<<14))
    {
        loopbackState=1;
        UART_printf("Link in loopback state\n");
        
    }
    else
    {
        loopbackState = 0;
         UART_printf("Link not in loopback state\n");
    }
    return loopbackState;
}
