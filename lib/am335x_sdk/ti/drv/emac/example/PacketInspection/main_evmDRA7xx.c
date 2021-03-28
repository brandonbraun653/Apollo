/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
 *  \brief    Packet Inspection example code for the EMAC driver. This
 *            example usees XDC/BIOS and showcases the usage of the EMAC
 *            Driver export API for sending and receiving Ethernet packets.
 *
 */

#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/utils/Load.h>

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

/* CSL Header Files */
#include <ti/csl/soc.h>
#include <ti/csl/csl_cpgmac_sl.h>
#include <ti/csl/csl_cpsw.h>

/* Number of MAC ports and their PHY addresses */
#if defined(evmDRA72x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     3
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     0 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#elif defined(evmDRA75x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     2
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     3
#define DRA7XX_EVM_NUM_PORTS             2
#elif defined(evmDRA78x)
#define EMAC_CPSW_PORT0_PHY_ADDR_EVM     0
#define EMAC_CPSW_PORT1_PHY_ADDR_EVM     1 /* Not populated */
#define DRA7XX_EVM_NUM_PORTS             1
#endif

struct ipv6_header {
    /* Destination and source MAC addresses */
    uint8_t dst_mac[6];               /* 6 bytes */
    uint8_t src_mac[6];               /* 6 bytes */

    /* Frame type */
    uint16_t ether_type;              /* 2 bytes */

    /* IPv6 header */
    uint32_t ipv_class_label;         /* 4 bytes */
    uint32_t paylength_nxthdr_hoplmt; /* 2 + 1 + 1 bytes */
    uint32_t src_ip[4U];              /* 16 bytes */
    uint32_t dst_ip[4U];              /* 16 bytes */
} __attribute__((packed));

typedef struct inspection_counters {
    uint32_t unmatched;               /* Unmatched EtherType */
    uint32_t ipv4;                    /* IPv4 packets */
    uint32_t ipv6_ip1;                /* Dest IP1 IPv6 packets */
    uint32_t ipv6_ip2;                /* Dest IP2 IPv6 packets*/
    uint32_t ipv6_unmatched;          /* Unmatched IPv6 packets */
    uint32_t total;                   /* All received packets */
    uint32_t cpu_load;
} inspection_counters;

struct inspection_counters counters;

static uint32_t dst_ip1[4] = { 0x5A5A5A5A, 0x5A5A5A5A, 0x5A5A5A5A, 0x5A5A5A5A };
static uint32_t dst_ip2[4] = { 0x3C3C3C3C, 0x3C3C3C3C, 0x3C3C3C3C, 0x3C3C3C3C };

/* Shared with the test utilities (test_utils.c) */
uint32_t linkStatus = 0;

/* MAC addresses */
EMAC_MAC_ADDR_T mac_addr_p1;
EMAC_MAC_ADDR_T mac_addr_p2;

/* Function prototypes */
void emac_poll_phy(uint32_t port);
void cpu_load_task(UArg arg0, UArg arg1);
void dra7xx_board_init_task(UArg arg0, UArg arg1);
void app_stats(UArg arg0, UArg arg1);
void app_recv_cb(Uint32 port_num, EMAC_PKT_DESC_T *p_desc);
void app_get_mac_addr(uint32_t port, EMAC_MAC_ADDR_T *mac_addr);
void emac_setup_ale(EMAC_MAC_ADDR_T *mac_addr);


int main(void)
{
    Task_Params taskParams;

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "BoardInit";
    Task_create(dra7xx_board_init_task, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.instance->name = "CPU_LOAD";
    taskParams.priority = 9;
    Task_create(cpu_load_task, &taskParams,NULL);

    /* Start BIOS */
    BIOS_start();
    return 0;
}

void cpu_load_task(UArg arg0, UArg arg1)
{
    UInt32 load;

    counters.cpu_load = 0;

    while(1) {
        load = Load_getCPULoad();
        if (load > counters.cpu_load)
            counters.cpu_load = load;

        Task_sleep(1000);
    }
}

EMAC_HwAttrs_V4 emac_cfg;
EMAC_OPEN_CONFIG_INFO_T open_cfg;
EMAC_CONFIG_INFO_T cfg_info;
EMAC_DRV_ERR_E ret;
EMAC_CHAN_MAC_ADDR_T chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];

void dra7xx_board_init_task(UArg arg0, UArg arg1)
{
    Task_Params taskParams;
    EMAC_MAC_ADDR_T *mac_addr = &mac_addr_p1;

    /* Set pinmux, IRQ crossbar, GMII selection */
    Board_init(BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_ETH_PHY |
               BOARD_INIT_UART_STDIO);

    /* Set addresses of the two PHYs in the EVM */
    EMAC_socGetInitCfg(0, &emac_cfg);
    emac_cfg.numPorts = DRA7XX_EVM_NUM_PORTS;
    emac_cfg.port[0].phy_addr = EMAC_CPSW_PORT0_PHY_ADDR_EVM;
    emac_cfg.port[1].phy_addr = EMAC_CPSW_PORT1_PHY_ADDR_EVM;
    EMAC_socSetInitCfg(0, &emac_cfg);

    app_init();

    /* Set configuration parameters */
    open_cfg.hwAttrs = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb = app_alloc_pkt;
    open_cfg.free_pkt_cb = app_free_pkt;
    open_cfg.rx_pkt_cb = app_recv_cb;
    open_cfg.loop_back = 0;
    open_cfg.master_core_flag = 1;
    open_cfg.max_pkt_size = 1518;
    open_cfg.mdio_flag = 1;
    open_cfg.num_of_chans = 1;
    open_cfg.num_of_rx_pkt_desc = 256;
    open_cfg.num_of_tx_pkt_desc = 256;
    open_cfg.phy_addr = 0;
    open_cfg.p_chan_mac_addr = &chan_cfg[0];

    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    /* Port 1's MAC address */
    app_get_mac_addr(1, mac_addr);
    chan_cfg[0].p_mac_addr = mac_addr;
    UART_printf("MAC Addr: %02x:%02x:%02x:%02x:%02x:%02x\n",
                mac_addr->addr[0], mac_addr->addr[1], mac_addr->addr[2],
                mac_addr->addr[3], mac_addr->addr[4], mac_addr->addr[5]);

    /* Open the EMAC driver */
    ret = emac_open(0, &open_cfg);
    if (ret == EMAC_DRV_RESULT_OPEN_PORT_ERR) {
        UART_printf("Failed to open the EMAC driver: %d\n", ret);
        return;
    }

    UART_printf("EMAC driver open sucess\n");

    /* Populate basic entries into the ALE */
    emac_setup_ale(mac_addr);

    /* Poll for PHY to be up */
    emac_poll_phy(0);

    /* Pass EMAC driver configuration (no-op) */
    cfg_info.mcast_cnt = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter = EMAC_PKTFLT_MULTICAST;
    emac_config(0, &cfg_info);

    /* Create the task that continuously waits for packets */
    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "EmacRxPkt";
    Task_create(app_test_task_poll_pkt, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacStats";
    Task_create(app_stats, &taskParams, NULL);
}

void emac_setup_ale(EMAC_MAC_ADDR_T *mac_addr)
{
    EMAC_HwAttrs_V4 emac_cfg;
    CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
    CSL_CPSW_ALE_UNICASTADDR_ENTRY entry;

    EMAC_socGetInitCfg(0, &emac_cfg);

    /* Enable learning */
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 0, &pPortControlInfo);
    pPortControlInfo.noLearnModeEnable = 0x0;
    pPortControlInfo.portState = ALE_PORTSTATE_FORWARD;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 0, &pPortControlInfo);

    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 1, &pPortControlInfo);
    pPortControlInfo.noLearnModeEnable = 0x0;
    pPortControlInfo.portState = ALE_PORTSTATE_FORWARD;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 1, &pPortControlInfo);

    /* Add ale entries for port 0 and 1 */
    CSL_CPSW_setAleTableEntry((CSL_cpswHandle)emac_cfg.ss_base, 0, 0xffffffff, 0xffffffff, 0x0);
    CSL_CPSW_setAleTableEntry((CSL_cpswHandle)emac_cfg.ss_base, 1, 0xffffffff, 0xffffffff, 0x4);

    /* Add unicast address */
    memcpy(entry.macAddress, mac_addr->addr, 6);
    entry.ucastType    = ALE_UCASTTYPE_UCAST_NOAGE;
    entry.secureEnable = FALSE;
    entry.blockEnable  = FALSE;
    entry.portNumber   = 0;
    CSL_CPSW_setAleUnicastAddrEntry((CSL_cpswHandle)emac_cfg.ss_base, 3, &entry);

    CSL_CPSW_enableAle((CSL_cpswHandle)emac_cfg.ss_base);

    /* Port into forwarding mode */
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 0, &pPortControlInfo);
    pPortControlInfo.portState = ALE_PORTSTATE_FORWARD;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle)emac_cfg.ss_base, 0, &pPortControlInfo);
}

void emac_poll_phy(uint32_t port)
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
}

uint32_t ipv6_addr_cmp(uint32_t *addr1, uint32_t *addr2)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (addr1[i] != addr2[i])
            return FALSE;
    }

    return TRUE;
}

void app_recv_cb(Uint32 port_num, EMAC_PKT_DESC_T *p_desc)
{
    struct ipv6_header *pkt = (struct ipv6_header *)p_desc->pDataBuffer;

    if (pkt->ether_type == 0x0008U) {
        counters.ipv4++;
    } else if (pkt->ether_type == 0xdd86U) {
        if (ipv6_addr_cmp(pkt->dst_ip, dst_ip1)) {
            counters.ipv6_ip1++;
        } else if (ipv6_addr_cmp(pkt->dst_ip, dst_ip2)) {
            counters.ipv6_ip2++;
        } else {
            counters.ipv6_unmatched++;
        }
    } else {
        counters.unmatched++;
    }

    counters.total++;

    app_free_pkt(port_num, (EMAC_PKT_DESC_T *)p_desc->AppPrivate);
}

void app_get_mac_addr(uint32_t port, EMAC_MAC_ADDR_T *mac_addr)
{
    uint32_t val1 = 0;
    uint32_t val2 = 0;

    switch(port) {
    case 1:
        val1 = HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MAC_ID_SW_0);
        val2 = HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MAC_ID_SW_1);
        break;

    case 2:
        val1 = HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MAC_ID_SW_2);
        val2 = HW_RD_REG32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_MAC_ID_SW_3);
        break;

    default:
        UART_printf("Invalid port number: %d, can't read MAC address\n", port);
        break;
    }

    mac_addr->addr[0] = (val2 >> 16) & 0xFFU;
    mac_addr->addr[1] = (val2 >>  8) & 0xFFU;
    mac_addr->addr[2] = (val2 >>  0) & 0xFFU;
    mac_addr->addr[3] = (val1 >> 16) & 0xFFU;
    mac_addr->addr[4] = (val1 >>  8) & 0xFFU;
    mac_addr->addr[5] = (val1 >>  0) & 0xFFU;
}

void app_stats(UArg arg0, UArg arg1)
{
    EMAC_STATISTICS_T stats;
    EMAC_DRV_ERR_E ret;

    while (TRUE) {
        memset(&stats, 0, sizeof(EMAC_STATISTICS_T));

        /* Read EMAC statistics */
        ret = emac_get_statistics(0, &stats);
        if (ret != EMAC_DRV_RESULT_OK) {
            UART_printf("Failed to retrieve EMAC stats: %d\n", ret);
            continue;
        }

        UART_printf("--------------------------------------------------------------------------------------\n");
        UART_printf(" RX |     Good:%8d |   Bcast:%8d |    Mcast:%8d |    Oct:%12d |\n",
                    stats.RxGoodFrames,
                    stats.RxBCastFrames,
                    stats.RxMCastFrames,
                    stats.RxOctets);
        UART_printf(" RX |    Pause:%8d |     CRC:%8d | AlignErr:%8d | Oversz:%12d |\n",
                    stats.RxPauseFrames,
                    stats.RxCRCErrors,
                    stats.RxAlignCodeErrors,
                    stats.RxOversized);
        UART_printf(" RX |   Jabber:%8d | Undersz:%8d |     Frag:%8d |   Filt:%12d |\n",
                    stats.RxJabber,
                    stats.RxUndersized,
                    stats.RxFiltered);
        UART_printf(" RX |      QoS:%8d |  SOFOvr:%8d |   MOFOvr:%8d | DMAOvr:%12d |\n",
                    stats.RxQOSFiltered,
                    stats.RxSOFOverruns,
                    stats.RxMOFOverruns,
                    stats.RxDMAOverruns);
        UART_printf(" TX |     Good:%8d |   Bcast:%8d |    Mcast:%8d |    Oct:%12d |\n",
                    stats.TxGoodFrames,
                    stats.TxBCastFrames,
                    stats.TxMCastFrames,
                    stats.TxOctets);
        UART_printf(" TX |    Pause:%8d | Deferred:%7d |     Coll:%8d |   Udrn:%12d |\n",
                    stats.TxPauseFrames,
                    stats.TxDeferred,
                    stats.TxCollision,
                    stats.TxUnderrun);
        UART_printf("APP |  Unmatch:%8d |    IPv4:%8d | IPv6-ip1:%8d | IPv6-ip2:%10d |\n",
                    counters.unmatched,
                    counters.ipv4,
                    counters.ipv6_ip1,
                    counters.ipv6_ip2);
        UART_printf("APP | IPv6-Unm:%8d |   Total:%8d |      CPU:%7d%% |                     |\n",
                    counters.ipv6_unmatched,
                    counters.total,
                    counters.cpu_load);
        UART_printf("--------------------------------------------------------------------------------------\n");

        memset(&counters, 0, sizeof(struct inspection_counters));
        Task_sleep(20000);
    }
}
