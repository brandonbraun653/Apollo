/**
 * @file   main.c
 *
 * @brief  SORTE(Simple Open Real Time Ethernet) on PRU-ICSS
 *
 *  ARM source code responsible for:
 *  PRU-ICSS control register initialization, PRU shared memory init and config,
 *  CRC8 lookup table generation, loading and starting PRU firmware.
 */
/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <string.h>

#ifdef __LINUX_USER_SPACE
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include "mmap_helper.h"
#else
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/knl/Cache.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#endif

#include <ti/csl/hw_types.h>

#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_mii_rt.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_pru_ctrl.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_mii_mdio.h>

#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>

#ifdef __LINUX_USER_SPACE
/* ICSS EMAC  PHY address definitions */
#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (0U)
#if defined(icev2AM335x)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (3U)
#elif defined(idkAM437x) || defined(idkAM571x) || defined(idkAM572x) || defined(iceK2G) || defined(idkAM574x)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (1U)
#endif
#if defined(iceK2G)
#define BOARD_ICSS_EMAC_PORT2_PHY_ADDR       (2U)
#define BOARD_ICSS_EMAC_PORT3_PHY_ADDR       (3U)
#endif
#else
#include <ti/board/board.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#endif

#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/pruss/example/apps/sorte/src/ti_pruss_intc_mapping.h>
#include <ti/drv/pruss/example/apps/sorte/src/sorte_loc.h>

#if defined(icev2AM335x) || defined(idkAM437x)
extern uint8_t pru_imem0_rev1_start;
extern uint8_t pru_imem0_rev1_end;
extern uint8_t pru_imem1_rev1_start;
extern uint8_t pru_imem1_rev1_end;
#elif defined(idkAM571x) || defined(idkAM572x) || defined(iceK2G) || defined(idkAM574x)
extern uint8_t pru_imem0_rev2_start;
extern uint8_t pru_imem0_rev2_end;
extern uint8_t pru_imem1_rev2_start;
extern uint8_t pru_imem1_rev2_end;
#endif

#if defined(icev2AM335x)
uint32_t pruIcssInstance = PRUICCSS_INSTANCE_ONE;
#elif defined(idkAM437x) || defined(idkAM571x) || defined(idkAM572x) || defined(iceK2G) || defined(idkAM574x)
uint32_t pruIcssInstance = PRUICCSS_INSTANCE_TWO;
#endif

/* Handle to pru-icss instance */
PRUICSS_Handle pruIcss1Handle = NULL;

/* Compile time options in makefile determine if compiling for master or slave device */
#if defined (SORTE_MASTER)
uint32_t sorteDeviceType = SORTE_MASTER_DEVICE;
#endif

#if defined (SORTE_SLAVE)
uint32_t sorteDeviceType = SORTE_SLAVE_DEVICE;
#endif

#ifdef __LINUX_USER_SPACE
tprussdrv *pruss_drv_handle;
PRUICSS_HwAttrs linux_prussHwAttrs[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_V1_Object linux_prussObjects[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_Config linux_pruss_config[PRUICCSS_INSTANCE_MAX] = {
                {
                        &(linux_prussObjects[0]),
                        &(linux_prussHwAttrs[0])
                },
                {
                        &(linux_prussObjects[1]),
                        &(linux_prussHwAttrs[1])
                },
                {NULL, NULL}
        };

static inline void linux_sleep_ms(unsigned long ms) {
    struct timespec ts;
    ts.tv_sec = (ms)/1000;
    ms = ms - ts.tv_sec*1000;
    ts.tv_nsec = (ms*1000000);
    nanosleep(&ts, NULL);
}
#define SLEEP(t) linux_sleep_ms(t)
#define PRINT printf
#else
#define SLEEP Task_sleep
#define PRINT UART_printf
#endif

void prussAppSorteInitCrc8Table(void);
void prussAppSorteRestartMaster(void);
void prussAppSorteDrvInit(void);
void prussAppSorteMdioInit(void);

/**
 *  @b Description
 *  @n
 *       Pre-compute 8 bit CRC table and store in pruss Pru0 Dram
 *       at offset SORTE_CRC8_TABLE_OFFSET
 *
 *  @param[in]  none
 *      none
 *
 *  @retval
 *      none
 */
void prussAppSorteInitCrc8Table(void)
{
    PRUICSS_HwAttrs      const    *hwAttrs;
    hwAttrs = pruIcss1Handle->hwAttrs;
    int32_t i,j;
    unsigned char crc;
    for (i=0; i<256; i++) {
        crc = i;
        for (j=0; j<8; j++)
            crc = (crc << 1) ^ ((crc & 0x80) ? 7 : 0);
        HWREGB(hwAttrs-> prussPru0DramBase + SORTE_CRC8_TABLE_OFFSET + i) = crc & 0xFF;
    }
}


/**
 *  @b Description
 *  @n
 *      Re-starts PRU0 for Master device
        - will restart continusly until slave devices are detected.
 *
 *  @param[in]  none
 *      none
 *
 *  @retval
 *      none
 */
void prussAppSorteRestartMaster(void)
{
    PRUICSS_pruDisable(pruIcss1Handle, PRUICCSS_PRU0);
    PRUICSS_pruReset(pruIcss1Handle, PRUICCSS_PRU0);
    PRUICSS_pruEnable(pruIcss1Handle, PRUICCSS_PRU0);
    
}

/**
 *  @b Description
 *  @n
 *      Initializes pru-icss subsystem for SORTE firmware
 *      - Clear pru-icss shared memory and pru 0/1 data ram memory
 *      - Configure pru-icss registers
 *      - initialize 8 bit crc table
 *
 *  @param[in]  none
 *      none
 *
 *  @retval
 *      none
 */

void prussAppSorteDrvInit(void)
{
    PRUICSS_HwAttrs      const    *hwAttrs = pruIcss1Handle->hwAttrs;

    /* clear TX RAM located in ICSS PRU0 data RAM */
    memset((void *)(hwAttrs-> prussPru0DramBase), 0, (8*1024));
    /* clear RX RAM located in ICSS PRU0 data RAM */
    memset((void *)(hwAttrs-> prussPru1DramBase), 0, (8*1024));
    /* clear ICSS shared RAM */
    memset((void *)(hwAttrs->prussSharedDramBase), 0, (12*1024));

    /* Enable OCP master ports for ICSS1 */
    PRUICSS_enableOCPMasterAccess(pruIcss1Handle);

#if defined(iceK2G)
    PRUICSS_setGpMuxSel(pruIcss1Handle, 0U, 2U);
    PRUICSS_setGpMuxSel(pruIcss1Handle, 1U, 2U);
#endif
    HWREG(hwAttrs->prussCfgRegBase + CSL_ICSSCFG_MII_RT) = 0 | \
            (1 << CSL_ICSSCFG_MII_RT_MII_RT_EVENT_EN_SHIFT);

    HWREG(hwAttrs->prussCfgRegBase + CSL_ICSSCFG_PIN_MX) = 0 | \
                 (0 << CSL_ICSSCFG_PIN_MX_PIN_MUX_SEL_SHIFT);

    HWREG(hwAttrs->prussCfgRegBase + CSL_ICSSCFG_SPP) = 0 | \
            (1 << CSL_ICSSCFG_SPP_XFR_SHIFT_EN_SHIFT);

    /* Enable PRU cycle counter for TX scheduler */
    HWREG(hwAttrs->prussPru0CtrlRegBase + CSL_ICSSPRUCTRL_CONTROL) |= (1 << 3);
    HWREG(hwAttrs->prussPru1CtrlRegBase + CSL_ICSSPRUCTRL_CONTROL) |= (1 << 3);

    /* set C28 to PRU-ICSS shared memory 0x10000 */
    HWREG(hwAttrs->prussPru0CtrlRegBase +  CSL_ICSSPRUCTRL_CTPPR0) = (0x0000<<16)| 0x0100;
    HWREG(hwAttrs->prussPru0CtrlRegBase +  CSL_ICSSPRUCTRL_CTPPR1) = (0x0000<<16)| 0x3000;
    /* set C30 to OCMC memory at 0x40300000 */
    HWREG(hwAttrs->prussPru1CtrlRegBase +  CSL_ICSSPRUCTRL_CTPPR0) = (0x0000<<16)| 0x0100;
    HWREG(hwAttrs->prussPru1CtrlRegBase +  CSL_ICSSPRUCTRL_CTPPR1) = (0x0000<<16)| 0x3000;

    /* EDIO configuration: sw_data_out_update in DIGIO_EXT_REG must be set for SW to set output. */
    HWREG(hwAttrs->prussIepRegBase + CSL_ICSSIEP_DIGIO_EXP_REG) |= 0x01;


    /* RXCFG and TXCFG configuration */
    HWREG(hwAttrs->prussMiiRtCfgRegBase + CSL_ICSSMIIRT_RXCFG0) =\
            (1<<CSL_ICSSMIIRT_RXCFG0_RX_ENABLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_RXCFG0_RX_CUT_PREAMBLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_RXCFG0_RX_MUX_SEL_SHIFT) |\
            (1<<CSL_ICSSMIIRT_RXCFG0_RX_L2_EN_SHIFT) |\
            (0<<CSL_ICSSMIIRT_RXCFG0_RX_AUTO_FWD_PRE_SHIFT);
    HWREG(hwAttrs->prussMiiRtCfgRegBase + CSL_ICSSMIIRT_RXCFG1) =\
            (1<<CSL_ICSSMIIRT_RXCFG1_RX_ENABLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_RXCFG1_RX_CUT_PREAMBLE_SHIFT) |\
            (1<<CSL_ICSSMIIRT_RXCFG1_RX_MUX_SEL_SHIFT) |\
            (1<<CSL_ICSSMIIRT_RXCFG1_RX_L2_EN_SHIFT) |\
            (0<<CSL_ICSSMIIRT_RXCFG1_RX_AUTO_FWD_PRE_SHIFT);
    HWREG(hwAttrs->prussMiiRtCfgRegBase + CSL_ICSSMIIRT_TXCFG0) =\
            (1<<CSL_ICSSMIIRT_TXCFG0_TX_ENABLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG0_TX_AUTO_PREAMBLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG0_TX_EN_MODE_SHIFT) |\
            (1<<CSL_ICSSMIIRT_TXCFG0_TX_EN_MODE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG0_PRE_TX_AUTO_SEQUENCE_SHIFT) |\
            (0x40<<CSL_ICSSMIIRT_TXCFG0_TX_START_DELAY_SHIFT);
    HWREG(hwAttrs->prussMiiRtCfgRegBase      + CSL_ICSSMIIRT_TXCFG1) =\
            (1<<CSL_ICSSMIIRT_TXCFG1_TX_ENABLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG1_TX_AUTO_PREAMBLE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG1_TX_EN_MODE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG1_TX_EN_MODE_SHIFT) |\
            (0<<CSL_ICSSMIIRT_TXCFG1_PRE_TX_AUTO_SEQUENCE_SHIFT) |\
            (0x40<<CSL_ICSSMIIRT_TXCFG1_TX_START_DELAY_SHIFT);

    prussAppSorteInitCrc8Table();
}


/**
 *  @b Description
 *  @n
 *      MDIO initialization routine
 *      - Updating pru shared memory with pru-icss PHY addresses
 *      - Enabling MDIO link interrupts for pru-icss PHYs
 *
 *  @param[in]  none
 *      none
 *
 *  @retval
 *      none
 */
void prussAppSorteMdioInit(void)
{

    PRUICSS_HwAttrs      const    *hwAttrs;
    hwAttrs = pruIcss1Handle->hwAttrs;

#if defined(iceK2G)
/*write MDIO configuration (phy addresses) to shadow area in pruss shared memory */ 
HWREG(hwAttrs->prussSharedDramBase+ CSL_MDIO_CONTROL_REG) = (uint32_t) \
        (BOARD_ICSS_EMAC_PORT2_PHY_ADDR | \
        (BOARD_ICSS_EMAC_PORT3_PHY_ADDR<<8) | \
        (0<<16) | \
        (0<<24));
/*Enable MDIO link interrupts for pru-icss PHY's, clear any pending interrupt */
PRINT("PHY2: %d, PHY3: %d\n", BOARD_ICSS_EMAC_PORT2_PHY_ADDR, BOARD_ICSS_EMAC_PORT3_PHY_ADDR);
HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERPHYSEL0) = 0x40 | BOARD_ICSS_EMAC_PORT2_PHY_ADDR; 
HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERPHYSEL1) = 0x40 | BOARD_ICSS_EMAC_PORT3_PHY_ADDR; 
HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERINTMASKED) = (1<<BOARD_ICSS_EMAC_PORT2_PHY_ADDR) | (1<<BOARD_ICSS_EMAC_PORT3_PHY_ADDR); 
#else
    /*write MDIO configuration (phy addresses) to shadow area in pruss shared memory */ 
    HWREG(hwAttrs->prussSharedDramBase+ CSL_MDIO_CONTROL_REG) = (uint32_t) \
            (BOARD_ICSS_EMAC_PORT0_PHY_ADDR | \
            (BOARD_ICSS_EMAC_PORT1_PHY_ADDR<<8) | \
            (0<<16) | \
            (0<<24));
    /*Enable MDIO link interrupts for pru-icss PHY's, clear any pending interrupt */
    PRINT("PHY0: %d, PHY1: %d\n", BOARD_ICSS_EMAC_PORT0_PHY_ADDR, BOARD_ICSS_EMAC_PORT1_PHY_ADDR);
    HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERPHYSEL0) = 0x40 | BOARD_ICSS_EMAC_PORT0_PHY_ADDR; 
    HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERPHYSEL1) = 0x40 | BOARD_ICSS_EMAC_PORT1_PHY_ADDR; 
    HWREG(hwAttrs->prussMiiMdioRegBase + CSL_ICSSMIIMDIO_USERINTMASKED) = (1<<BOARD_ICSS_EMAC_PORT0_PHY_ADDR) | (1<<BOARD_ICSS_EMAC_PORT1_PHY_ADDR); 
#endif
}

/**
 *  @b Description
 *  @n
 *      Task function to load SORTE firmware for master and slave devices, enabled PRU's
 *      For master device, will keep on restarting the PRU until 
 *      SORTE_MIN_NUM_SLAVE_DEVICES is detected as which Parameterization state
 *      will be entered.
 *      For slave device, firmware statistics will be queried to determine pass criteria of test.
 *
 *  @param[in]  none
 *      none
 *
 *  @retval
 *      none
 */
#ifdef __LINUX_USER_SPACE
void *sorteTaskPRU(void *a0)
#else
void sorteTaskPRU(UArg a0, UArg a1)
#endif
{
    PRUICSS_HwAttrs      const    *hwAttrs = pruIcss1Handle->hwAttrs;

    PRUICSS_pinMuxConfig(pruIcss1Handle, 0x0); /* PRUSS pinmuxing */
    /*Disable PRUs - This is to ensure PRUs are not running when application is not initialized */
    PRUICSS_pruDisable(pruIcss1Handle, PRUICCSS_PRU0);
    PRUICSS_pruDisable(pruIcss1Handle, PRUICCSS_PRU1);

    PRINT("\n\rTI SORTE Demo Application\n");

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    PRUICSS_pruIntcInit(pruIcss1Handle, &pruss_intc_initdata);

    prussAppSorteDrvInit();

    prussAppSorteMdioInit();

    PRUICSS_pruReset(pruIcss1Handle, PRUICCSS_PRU0);
    PRUICSS_pruReset(pruIcss1Handle, PRUICCSS_PRU1);

    if(sorteDeviceType==SORTE_MASTER_DEVICE)  /* master device */
    {
#if defined(idkAM571x) || defined(idkAM572x) || defined(iceK2G) || defined(idkAM574x)
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(0) ,0,
                               (uint32_t *) &pru_imem0_rev2_start,
                               &pru_imem0_rev2_end - &pru_imem0_rev2_start);
#else
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(0) ,0,
                                   (uint32_t *) &pru_imem0_rev1_start,
                                   &pru_imem0_rev1_end - &pru_imem0_rev1_start);
#endif
        PRUICSS_pruEnable(pruIcss1Handle, PRUICCSS_PRU0);
        SLEEP(1000);
        /* check to see if there are atleast 2 slaves  before downloading firmware */
        while((HW_RD_REG16(hwAttrs->prussPru0DramBase + SORTE_DISCOV_NUM_SLAVE_OFFSET)) <SORTE_MIN_NUM_SLAVE_DEVICES)
        {
            PRINT("sorte master: waiting for atleast 2 SLAVE devices connected\n");
            prussAppSorteRestartMaster();
            SLEEP(1000);
            
        }
        PRINT("sorte master: 2 SLAVE devices connected\n");
    }
    else   /* slave device */
    {
#if defined(idkAM571x) || defined(idkAM572x) || defined(iceK2G) || defined(idkAM574x)
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(0) ,0,
                                   (uint32_t *) &pru_imem0_rev2_start,
                                   &pru_imem0_rev2_end - &pru_imem0_rev2_start);
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(1) ,0,
                                   (uint32_t *) &pru_imem1_rev2_start,
                                   &pru_imem1_rev2_end - &pru_imem1_rev2_start);
#else
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(0) ,0,
                                   (uint32_t *) &pru_imem0_rev1_start,
                                   &pru_imem0_rev1_end - &pru_imem0_rev1_start);
        PRUICSS_pruWriteMemory(pruIcss1Handle,PRU_ICSS_IRAM(1) ,0,
                                   (uint32_t *) &pru_imem1_rev1_start,
                                   &pru_imem1_rev1_end - &pru_imem1_rev1_start);
#endif
        PRUICSS_pruEnable(pruIcss1Handle, PRUICCSS_PRU0);
        PRUICSS_pruEnable(pruIcss1Handle, PRUICCSS_PRU1);
    }
    do
    {
        /* Stats currently available on slave devices only */
        if (sorteDeviceType == SORTE_SLAVE_DEVICE)
        {
            uint16_t rxPkts = HW_RD_REG16(hwAttrs->prussSharedDramBase + SORTE_RX_NO_CRC_ERR_PKT_OFFSET);
            if(rxPkts >= SORT_SLAVE_PASS_CRITERIA)
            {
                PRINT("sorte slave: receive packet count: %d\n", rxPkts);
                PRINT("All tests have passed\n");
                break;
            }
            else
            {
                PRINT("sorte slave: test in progress: current receive packet count: %d\n", rxPkts);
            }
        }
        SLEEP(1000);
    }
    while(1);
}

/*
 *  ======== main ========
 */
#ifdef __LINUX_USER_SPACE
int main(int argc, char **argv)
{

    PRUICSS_Config  *pruIcssCfg;
    int status;
    int priority = 20;
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;
    pthread_t sorte_task_th;

    linux_init((void**)&pruss_drv_handle, linux_prussHwAttrs, pruIcssInstance);
    pruIcssCfg = linux_pruss_config;

    pruIcss1Handle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg, pruIcssInstance);

    pthread_attr_init(&pthread_attr);
    sched_param.sched_priority = priority;
    pthread_attr_setschedparam(&pthread_attr, &sched_param);

    if ((status = pthread_create(&sorte_task_th, &pthread_attr, sorteTaskPRU, NULL))) {
        printf("ERROR: \"sorteTaskPRU\" task-create failed (%d)\n", status);
        return (-1);
    }

    pthread_join(sorte_task_th, NULL);

    return(0);
}
#else // RTOS
int main()
{ 
    Board_initCfg cfg;
    int32_t ret;
    PRUICSS_Config  *pruIcssCfg;
    Task_Params taskParams;
#if defined(icev2AM335x) || defined(idkAM437x)
    cfg = BOARD_INIT_PLL| BOARD_INIT_MODULE_CLOCK |  BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
#else
    cfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_ICSS_ETH_PHY;
#endif

    ret = Board_init(cfg);

    if (ret != BOARD_SOK)
    {
	return -1;
    }
    else
    {
        PRINT("main: BOARD_init success\n");
    }
    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        return (ret);
    }
    pruIcss1Handle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg, pruIcssInstance);

    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = (char*)"sorteTaskPRU";
    taskParams.stackSize = 0x1000;
    Task_create((ti_sysbios_knl_Task_FuncPtr)sorteTaskPRU, &taskParams, NULL);

    BIOS_start();
    return(0);
}

#endif


