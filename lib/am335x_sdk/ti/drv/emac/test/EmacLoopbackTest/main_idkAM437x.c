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
#include <ti/starterware/include/hw/hw_control_am43xx.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/ethernet.h>

#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>





uint32_t emac_check_loopback_status(uint32_t port);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
 uint32_t linkStatus = 0;

EMAC_MAC_ADDR_T macTest;





uint32_t emac_check_loopback_status(uint32_t port);


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void CpswPortMacModeSelect(uint32_t portNum, uint32_t macMode)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_GMII_SEL);

    switch(macMode)
    {
        case ETHERNET_MAC_TYPE_MII:
        case ETHERNET_MAC_TYPE_GMII:
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RMII: /* RMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 1U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 1U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RGMII: /* RGMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 2U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 2U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_GMII_SEL), regVal);
}


#define SYS_MMU_BUFFERABLE      1
#define SYS_MMU_CACHEABLE       2
#define SYS_MMU_SHAREABLE       4
#define SYS_MMU_NO_EXECUTE      8
typedef struct _sys_mmu_entry
{

    void* address;
    /**< Address to be entered in MMU table. */
    unsigned int attributes;
    /**< Attributes of the memory. */
}SYS_MMU_ENTRY;


SYS_MMU_ENTRY applMmuEntries[] = {
    {(void*)0x30000000,SYS_MMU_CACHEABLE},  //QSPI CS0 Maddr1space - Cacheable
    {(void*)0x30100000,SYS_MMU_CACHEABLE},  //QSPI CS0 Maddr1space - Cacheable
    {(void*)0x30200000,SYS_MMU_CACHEABLE},  //QSPI CS0 Maddr1space - Cacheable
    {(void*)0x30300000,SYS_MMU_CACHEABLE},  //QSPI CS0 Maddr1space - Cacheable
    {(void*)0x40300000,0},  //OCMCRAM  - Cacheable
    {(void*)0x44D00000, SYS_MMU_BUFFERABLE},  //PRCM - Non bufferable| Non Cacheable
    {(void*)0x44E00000, SYS_MMU_BUFFERABLE},  //Clock Module, PRM, GPIO0, UART0, I2C0, - Non bufferable| Non Cacheable
    {(void*)0x47900000,SYS_MMU_BUFFERABLE},  //QSPI MMR Maddr0space
    {(void*)0x48000000, SYS_MMU_BUFFERABLE},  //UART1,UART2,I2C1,McSPI0,McASP0 CFG,McASP1 CFG,DMTIMER,GPIO1 -Non bufferable| Non Cacheable
    {(void*)0x48100000,0},  //I2C2,McSPI1,UART3,UART4,UART5, GPIO2,GPIO3,MMC1 - Non bufferable| Non Cacheable
    {(void*)0x48200000, SYS_MMU_BUFFERABLE},  //
    {(void*)0x48300000, SYS_MMU_BUFFERABLE},  //PWM - Non bufferable| Non Cacheable
    {(void*)0x49000000, SYS_MMU_BUFFERABLE},   //EDMA3CC - Non bufferable| Non Cacheable
    {(void*)0x4A000000, SYS_MMU_BUFFERABLE},  //L4 FAST CFG- Non bufferable| Non Cacheable
    {(void*)0x4A100000, SYS_MMU_BUFFERABLE},  //CPSW - Non bufferable| Non Cacheable
    {(void*)0x54400000, SYS_MMU_BUFFERABLE},  //PRU-ICSS0/1 -Bufferable| Non Cacheable | Shareable
    {(void*)0x80000000,SYS_MMU_CACHEABLE},  //QSPI CS0 Maddr1space - Non bufferable| Non Cacheable
    {(void*)0xFFFFFFFF,0xFFFFFFFF}
};
int SDKMMUInit(SYS_MMU_ENTRY mmuEntries[])
{
    unsigned short itr = 0;
    Mmu_FirstLevelDescAttrs attrs;

    if(NULL == mmuEntries)
        return -1;

    Mmu_disable();

    Mmu_initDescAttrs(&attrs);

    attrs.type = Mmu_FirstLevelDesc_SECTION;
    attrs.domain = 0;
    attrs.imp = 1;
    attrs.accPerm = 3;


    for(itr = 0 ; mmuEntries[itr].address != (void*)0xFFFFFFFF ; itr++)
    {
        attrs.bufferable = ((mmuEntries[itr].attributes) & SYS_MMU_BUFFERABLE) && 1 ;
        attrs.cacheable  = ((mmuEntries[itr].attributes) & SYS_MMU_CACHEABLE) && 1;
        if (!attrs.bufferable && !attrs.cacheable)
            attrs.tex = 0; //tex is initialized to 1 and need this to force strongly ordered
        attrs.shareable  = ((mmuEntries[itr].attributes) & SYS_MMU_SHAREABLE) && 1;
        attrs.noexecute  = ((mmuEntries[itr].attributes) & SYS_MMU_NO_EXECUTE) && 1;
        Mmu_setFirstLevelDesc((Ptr)(mmuEntries[itr].address), (Ptr)(mmuEntries[itr].address) , &attrs);  // PWM
    }
    Mmu_enable();
    return 0;
}

/**
 *  \name main
 *  \brief Main Function
 *  \param none
 *  \return none
 *
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;
    Task_Params taskParams;
    EMAC_HwAttrs_V4 emac_cfg;
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CONFIG_INFO_T cfg_info;
    EMAC_DRV_ERR_E open_ret;
    EMAC_LINK_INFO_T linkInfo;
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];
    uint32_t i;
    SDKMMUInit(applMmuEntries);

    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    /* Chip configuration MII/RMII selection */
    CpswPortMacModeSelect(1, ETHERNET_MAC_TYPE_RGMII);
    CpswPortMacModeSelect(2, ETHERNET_MAC_TYPE_RGMII);

    EMAC_socGetInitCfg(0, &emac_cfg);
   
    emac_cfg.macModeFlags = EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
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
    linkInfo.link_status = 0;
    linkInfo.link_status_change = 0;
    while(linkInfo.link_status != EMAC_LINKSTATUS_FD100)
    {
        emac_poll(0 , &linkInfo);
        app_delay(100000);
        UART_printf("plug in 100Mbps loopback cable\n");
    }
    UART_printf("link status change: %d, link status: %d\n", linkInfo.link_status_change, linkInfo.link_status);

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
        app_delay(100);
        retries--;
    }

    UART_printf("link status: %s    ", linkStatus?"Up":"Down\n");

    //determine if in loopback
    app_delay(100);
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

