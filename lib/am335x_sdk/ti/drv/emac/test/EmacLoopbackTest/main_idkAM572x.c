/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2015-2016
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
 *  \file     main_idkAM572x.c
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
#include <xdc/cfg/global.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/utils/Load.h>

/* CSL Chip Functional Layer */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/soc.h>

/* I2C Driver Header Files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_v1.h>
/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

#include <ti/drv/emac/soc/emac_soc_v4.h>

/* Test application local header file */
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"
#include "ti/drv/emac/test/EmacLoopbackTest/test_utils.h"

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>


#ifdef __ARM_ARCH_7A__
#include <ti/sysbios/family/arm/a15/Cache.h>
#include <ti/sysbios/family/arm/a15/Mmu.h>
#endif


#define EMAC_TEST_NUM_HW_DESC 128U
#define EMAC_TEST_2MB_PAGE_SIZE 0x200000U

EMAC_MAC_ADDR_T macAddr1;


#ifdef __ARM_ARCH_7A__
/* structure used to define 2MB page as un-cached for cppi descriptors,
    sized for 128 descriptors*/
typedef struct uncached_s
{
    EMAC_Desc   emacCppiDesc[EMAC_TEST_NUM_HW_DESC];
    uint8_t pad[EMAC_TEST_2MB_PAGE_SIZE- (sizeof(EMAC_Desc)*EMAC_TEST_NUM_HW_DESC)];
} uncached_t;

uncached_t  testCppiDescBase __attribute__((aligned(EMAC_TEST_2MB_PAGE_SIZE)));
#endif

/* Function prototypes */
void emac_poll_phy(uint32_t port);
void app_get_mac_addr(uint32_t port, EMAC_MAC_ADDR_T *mac_addr);
void emac_setup_ale(EMAC_MAC_ADDR_T *mac_addr);


/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
uint32_t linkStatus = 0;

//#define EMAC_BENCHMARK

#ifdef EMAC_BENCHMARK

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

#define EMAC_TEST_BENCHMARK_RX_PKT_COUNT 100000U /* tunable */
#define EMAC_TEST_BENCHMARK_32K_COUNT 32000U        /* do not modify */

volatile uint32_t *counter_32khz = (uint32_t *) 0x4AE04030;

uint32_t cpu_load = 0;
uint32_t totalPktLength = 0;
uint32_t totalPktCount = 0;

void cpu_load_task(UArg arg0, UArg arg1);
void app_stats(UArg arg0, UArg arg1);
void app_recv_cb(Uint32 port_num, EMAC_PKT_DESC_T *p_desc);

/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/
void cpu_load_task(UArg arg0, UArg arg1)
{
    UInt32 load;

    cpu_load = 0;

    while(1)
    {
        load = Load_getCPULoad();
        if (load > cpu_load)
            cpu_load = load;
        Task_sleep(1000);
    }
}

void app_recv_cb(Uint32 port_num, EMAC_PKT_DESC_T *p_desc)
{
    uint32_t          packetLength;
    static uint32_t  start = 0;
    static uint32_t  end = 0;
    struct ipv6_header *pkt = (struct ipv6_header *)p_desc->pDataBuffer;
    
    if (totalPktCount == 0)
    {
        if (pkt->ether_type == 0x0608U)
        {
            start = *counter_32khz;
             totalPktCount++;
            UART_printf("starting timer using 32Khz clock\n");
        }
        else
             app_free_pkt(port_num, (EMAC_PKT_DESC_T *)p_desc->AppPrivate);
    }
    else
    {
        totalPktLength += p_desc->PktLength;
        if ((++totalPktCount) >=  EMAC_TEST_BENCHMARK_RX_PKT_COUNT)
        {
                end = *counter_32khz;
                UART_printf("num packets: %u, totalPktLen in bytes: %u, start counter: %u, end counter:%u\n",
                            totalPktCount, totalPktLength, start, end);
                start = 0;
                end = 0;
                totalPktCount = 0;
                totalPktLength = 0;
        }
        app_free_pkt(port_num, (EMAC_PKT_DESC_T *)p_desc->AppPrivate);
    }
}

void app_stats(UArg arg0, UArg arg1)
{
    EMAC_STATISTICS_T stats;
    EMAC_DRV_ERR_E ret;

    while (TRUE) {
        memset(&stats, 0, sizeof(EMAC_STATISTICS_T));

        /* Read EMAC statistics */
        ret = emac_get_statistics(0, &stats);
        ret = EMAC_DRV_RESULT_OK;
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
        
        UART_printf("CPU:%7d%% |                     |\n",
                    cpu_load);
        UART_printf("--------------------------------------------------------------------------------------\n");

        //memset(&counters, 0, sizeof(struct inspection_counters));
        Task_sleep(10000);
    }
}
#endif
void app_get_mac_addr(uint32_t port, EMAC_MAC_ADDR_T *p)
{

    uint32_t val1;
    uint32_t val2;
    uint8_t i;
    CSL_control_coreRegs * tempAddr;
    tempAddr =   (CSL_control_coreRegs*)SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE;

    switch(port)
    {
        case 1U:
            val1 = tempAddr->MAC_ID_SW_0;
            val2 = tempAddr->MAC_ID_SW_1;
            break;

        case 2U:
            val1 = tempAddr->MAC_ID_SW_2;
            val2 = tempAddr->MAC_ID_SW_3;
            break;
        default:
            UART_printf("Invalid port number: %d, can't read MAC address\n", port);
            break;
    }
    p->addr[0U] = (uint8_t)((val2 >> 16U) & 0xFFU);
    p->addr[1U] = (uint8_t)((val2 >> 8U) & 0xFFU);
    p->addr[2U] = (uint8_t)(val2 & 0xFFU);

    p->addr[3U] = (uint8_t)((val1 >> 16U) & 0xFFU);
    p->addr[4U] = (uint8_t)((val1 >> 8U) & 0xFFU);
    p->addr[5U] = (uint8_t)((val1) & 0xFFU);
    /* check for zero mac address from  efuse  */
    for (i=0U;i<6U;i++)
    {
        if(p->addr[i] != 0U)
        {
            break;
        }
    }
    if (i == 6U)
    {
        /* use any uni-cast MAC address */
        for (i=0U;i<6U;i++)
        {
            p->addr[i] = i + 2U;
        }
    }

}




void delay(unsigned int delayValue)
{
    volatile uint32_t delay = delayValue*100;
    while (delay--) ;
}
uint32_t ClockSynthesizerSetup(void)
{
/* I2C Instance Controlling Clock Synthesizer */
#define EMAC_TEST_CLOCK_SYNTHESIZER_I2C_INST_NUM  0

/* Clock Synthesizer Device Address */
#define EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR      0x65

#define EMAC_TEST_CLOCK_SYNTHESIZER_ID_REG        0

/* Crystal load capacitor selection */
#define EMAC_TEST_CLOCK_SYNTHESIZER_XCSEL         0x05

/* PLL1 Configuration Register */
#define EMAC_TEST_CLOCK_SYNTHESIZER_MUX_REG       0x14

/* PDIV2 */
#define EMAC_TEST_CLOCK_SYNTHESIZER_PDIV2_REG     0x16

/* PDIV3 */
#define EMAC_TEST_CLOCK_SYNTHESIZER_PDIV3_REG     0x17

#define EMAC_TEST_TX_LENGTH              (2U)
#define EMAC_TEST_RX_LENGTH              (10U)
#define EMAC_TEST_TIMEOUT_VAL           (100U)

    uint32_t status = TRUE;
    uint32_t regValue = 0U;
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Transaction i2cTransaction;
    char txBuf[EMAC_TEST_TX_LENGTH] = {0x00, 0x01};
    char rxBuf[EMAC_TEST_RX_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                             0x00, 0x00};

    I2C_HwAttrs i2cCfg;
        
    I2C_init();

    I2C_Params_init(&i2cParams);

    I2C_socGetInitCfg(EMAC_TEST_CLOCK_SYNTHESIZER_I2C_INST_NUM, &i2cCfg);

    i2cCfg.enableIntr = false;

    I2C_socSetInitCfg(EMAC_TEST_CLOCK_SYNTHESIZER_I2C_INST_NUM, &i2cCfg);

    handle = I2C_open(EMAC_TEST_CLOCK_SYNTHESIZER_I2C_INST_NUM, &i2cParams);

/* Read - EMAC_TEST_CLOCK_SYNTHESIZER_ID_REG */

    if (FALSE != status)
    {
        txBuf[0] = EMAC_TEST_CLOCK_SYNTHESIZER_ID_REG | 0x80U;
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 1U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 0U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_ID_REG: Data Write failed. \n");
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if (FALSE != status)
    {
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 0U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 1U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_ID_REG: Data Read failed. \n");
        }
        else
        {
            regValue = rxBuf[0];
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if((regValue & 0x81U)!= 0x81U)
    {
        UART_printf("\n Clock synthesizer: Read: Failed");
        status = FALSE;
    }

    /** CDCE913 Clock Synthesizer configuration for RMII Clock = 50 MHz
     * fout = fin/Pdiv x N/M
     * fout = 50 MHz
     * fin  = 25 MHz
     * Pdiv = 2
     * N    = 4
     * M    = 1
     */

    /* Crystal load Capacitor Selection - 18pF: 0x12h(bits 7:3) */

/* Write - EMAC_TEST_CLOCK_SYNTHESIZER_XCSEL */

    if (FALSE != status)
    {
        txBuf[0] = EMAC_TEST_CLOCK_SYNTHESIZER_XCSEL | 0x80U;
        txBuf[1] = 0x90U;
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 2U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 0U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_XCSEL: Data Write failed. \n");
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if (FALSE == status)
    {
        UART_printf("\n Clock synthesizer: Write: Failed");
    }

    /* PLL1 Multiplexer b7:0 (PLL1) */

/* Write - EMAC_TEST_CLOCK_SYNTHESIZER_MUX_REG */

    if (FALSE != status)
    {
        txBuf[0] = EMAC_TEST_CLOCK_SYNTHESIZER_MUX_REG | 0x80U;
        txBuf[1] = 0x6DU;
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 2U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 0U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_MUX_REG: Data Write failed. \n");
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if (FALSE == status)
    {
        UART_printf("\n Clock synthesizer: Write: Failed");
    }

    /** b7-0(PLL1 SSC down selection by default),
     *  b6:0-0x02h(7-bit Y2-Output-Divider Pdiv2)
     */

/* Write - EMAC_TEST_CLOCK_SYNTHESIZER_PDIV2_REG */

    if (FALSE != status)
    {
        txBuf[0] = EMAC_TEST_CLOCK_SYNTHESIZER_PDIV2_REG | 0x80U;
        txBuf[1] = 0x02U;
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 2U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 0U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_PDIV2_REG: Data Write failed. \n");
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if (FALSE == status)
    {
        UART_printf("\n Clock synthesizer: Write: Failed");
    }

    /* b6:0-0x02h(7-bit Y3-Output-Divider Pdiv3) */

/* Write - EMAC_TEST_CLOCK_SYNTHESIZER_PDIV3_REG */

    if (FALSE != status)
    {
        txBuf[0] = EMAC_TEST_CLOCK_SYNTHESIZER_PDIV3_REG | 0x80U;
        txBuf[1] = 0x02U;
        i2cTransaction.slaveAddress = EMAC_TEST_CLOCK_SYNTHESIZER_I2C_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 2U;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 0U;
        status = I2C_transfer(handle, &i2cTransaction);

        if(FALSE == status)
        {
            UART_printf("\n EMAC_TEST_CLOCK_SYNTHESIZER_PDIV3_REG: Data Write failed. \n");
        }
    }

    delay(EMAC_TEST_TIMEOUT_VAL);

    if (FALSE == status)
    {
        UART_printf("\n Clock synthesizer: Write: Failed");
    }

    I2C_close(handle);

    return status;
}

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
    Task_Params     taskParams;
    EMAC_HwAttrs_V4 emac_cfg;
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_DRV_ERR_E open_ret;
    Board_STATUS boardInitStatus =0;
    Error_Block eb;
    Error_init(&eb);
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];

#ifdef __ARM_ARCH_7A__
    uint64_t physicalAddr = (uint64_t)(uint32_t)&testCppiDescBase;
    
    Mmu_DescriptorAttrs attrs;
    Mmu_initDescAttrs(&attrs);
    attrs.type = Mmu_DescriptorType_BLOCK;
    attrs.shareable = 0;            // non-shareable
    attrs.accPerm = 1;              // read/write at any privelege level
    attrs.attrIndx = 0;             // un-cached
    Mmu_setSecondLevelDesc((Ptr)&testCppiDescBase, (UInt64)physicalAddr, &attrs);
#endif

    Board_initCfg cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK;
    boardInitStatus = Board_init(cfg);
    if (boardInitStatus !=0)
    {
        return(0);
    }
    UART_printf("Board_init success\n");

    ClockSynthesizerSetup();

#ifdef _TMS320C6X
    CSL_xbarDspIrqConfigure(1,CSL_XBAR_INST_DSP1_IRQ_75, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarDspIrqConfigure(1,CSL_XBAR_INST_DSP1_IRQ_76, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#elif defined (__TI_ARM_V7M4__)
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_60, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_61, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#elif defined(__ARM_ARCH_7A__)
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_92, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_93, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#endif


    /* Select RGMII 2 ports GMIIx_SEL = 2 for RGMII*/
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
          CONTROL_CORE_CONTROL_IO_1_GMII1_SEL, 2U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
          CONTROL_CORE_CONTROL_IO_1_GMII2_SEL, 2U);

    /*GMAC RESET ISOLATION Enable*/
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
          CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 0U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
          CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 1U);

    EMAC_socGetInitCfg(0, &emac_cfg);

#ifdef __ARM_ARCH_7A__
   emac_cfg.cppi_ram_base = &testCppiDescBase;
#endif
   EMAC_socSetInitCfg(0, &emac_cfg);
    app_init();

    open_cfg.hwAttrs = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb = app_alloc_pkt;
    open_cfg.free_pkt_cb = app_free_pkt;
#ifndef EMAC_BENCHMARK
    open_cfg.loop_back = 1;
    open_cfg.rx_pkt_cb = app_test_rx_pkt_cb;
#else
    open_cfg.loop_back = 0;
     open_cfg.rx_pkt_cb = app_recv_cb;
#endif

    open_cfg.master_core_flag = 1;
    open_cfg.max_pkt_size = 1518; 
    open_cfg.mdio_flag = 1;
    open_cfg.num_of_chans = 1;
    open_cfg.num_of_rx_pkt_desc = 64U;
    open_cfg.num_of_tx_pkt_desc = 64U;
    open_cfg.phy_addr = 0;

    open_cfg.p_chan_mac_addr = &chan_cfg[0];

    /* Set the channel configuration */
    chan_cfg[0].chan_num = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    app_get_mac_addr(1, &macAddr1);

     chan_cfg[0].p_mac_addr = & macAddr1;

    if ((open_ret = emac_open(0, &open_cfg)) == EMAC_DRV_RESULT_OPEN_PORT_ERR)
    {
        UART_printf("main: emac_open failure: %d\n", open_ret);
    }
    else
        UART_printf("main: emac_open sucess\n");

        emac_setup_ale(&macAddr1);

    emac_poll_phy(0);

    Task_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.instance->name = "EmacRxPkt";
    Task_create(app_test_task_poll_pkt, &taskParams, NULL);

    

#ifndef EMAC_BENCHMARK
    /* Create the  task to send packets for loopback.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "EmacSendPkt";
    Task_create(app_test_task_send_pkts, &taskParams, NULL);
#else
    Task_Params_init(&taskParams);
    taskParams.instance->name = "CPU_LOAD";
    taskParams.priority = 9;
    Task_create(cpu_load_task, &taskParams,NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 9;
    taskParams.instance->name = "EmacStats";
    Task_create(app_stats, &taskParams, NULL);
#endif

    /* Start BIOS */
    BIOS_start();
    return 0;
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
         delay(10000);
    }

    UART_printf("Link status: %s\n", linkStatus?"Up":"Down\n");

    /* Determine if in loopback */
    delay(100);
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val);
    if (val & (1<<14)) {
        loopbackState = 1;
    } else {
        loopbackState = 0;
    }

    UART_printf("Link is%s in loopback state\n", loopbackState?"":" not");
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



