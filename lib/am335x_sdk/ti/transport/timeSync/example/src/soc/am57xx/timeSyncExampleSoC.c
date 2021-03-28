/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <xdc/std.h>
#include <ti/csl/soc.h>
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <src/soc/am57xx/timeSyncExampleSoC.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

void timeSync_example_enablePWMSS1Module()
{
    uint32_t    ctrlCoreIO;

    /* Setting the Control Core IO2 to enable PWMSS1_TBCLKEN */
    ctrlCoreIO = HWREG(CONTROL_CORE_IO);

    ctrlCoreIO |= 0x100000;
    HWREG(CONTROL_CORE_IO) = ctrlCoreIO;
    /*Enable PWMSS1 module*/
    /* Enable the module */

    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_PWMSS1_CLKCTRL, \
                CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_ENABLE);


    /* Check for module enable status */
    while(CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_ENABLE !=
            (HWREG(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_PWMSS1_CLKCTRL) &
            CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_MASK));


    /* Check clock activity - ungated */
    while(CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_MASK
            !=
            (HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS +
                         CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG)
             & CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_MASK));

    /* Check idle status value - should be in functional state */
    while((CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_FUNC <<
            CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_SHIFT) !=
            (HWREG(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_PWMSS1_CLKCTRL) &
            CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_MASK));

}

void timeSync_example_configureInterrupts(uint32_t portNum, ICSSEMAC_InitConfig *switchEmacCfg)
{
    /* Interrupt configuration */
#ifdef _TMS320C6X
    switchEmacCfg->linkIntNum=76;
    switchEmacCfg->rxIntNum = 77;
    switchEmacCfg->txIntNum = 79;
    /*Configure Time Sync interrupts*/
    timeSyncHandle->timeSyncConfig.txIntNum = 78;
    /* For PRU2 Eth0 */
#elif defined (__TI_ARM_V7M4__)
    switchEmacCfg->linkIntNum=27;
    switchEmacCfg->rxIntNum = 28;
    switchEmacCfg->txIntNum = 30;
    /*Configure Time Sync interrupts*/
    timeSyncHandle->timeSyncConfig.txIntNum = 29;
#elif defined(__ARM_ARCH_7A__)
    switchEmacCfg->linkIntNum=CSL_armGicGetGicIdForIrqInputLine(120);
    switchEmacCfg->rxIntNum = CSL_armGicGetGicIdForIrqInputLine(121);
    switchEmacCfg->txIntNum = CSL_armGicGetGicIdForIrqInputLine(124);

    /*Configure Time Sync interrupts*/
    timeSyncHandle->timeSyncConfig.txIntNum = CSL_armGicGetGicIdForIrqInputLine(123);
#endif

    /* Configure the other configurations */
    if (portNum == 0)
    {
        switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
        switchEmacCfg->phyAddr[0]=BOARD_ICSS_EMAC_PORT0_PHY_ADDR;
        switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE2;
    }
    else
    {
        switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC2;
        switchEmacCfg->phyAddr[0]=BOARD_ICSS_EMAC_PORT1_PHY_ADDR;
        switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE4;
    }
    switchEmacCfg->halfDuplexEnable = 1;
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_DISABLE_PACING;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;

    timeSync_example_socgetMACAddress(portNum,lclMac);
    switchEmacCfg->macId = lclMac;

}

void timeSync_example_crossbarConfig(uint32_t portNum, uint8_t instance)
{
    CSL_XbarIrqCpuId cpuId = CSL_XBAR_IRQ_CPU_ID_IPU1;
    uint32_t xbarRxIsrInstance;
    uint32_t xbarLinkIsrInstance;
    uint32_t xbarPtpIsrInstance;
    uint32_t xbarTxIsrInstance;

#if defined (__TI_ARM_V7M4__)
    cpuId               = CSL_XBAR_IRQ_CPU_ID_IPU1;
    xbarRxIsrInstance   = CSL_XBAR_INST_IPU2_IRQ_28;
    xbarLinkIsrInstance = CSL_XBAR_INST_IPU2_IRQ_27;
    xbarPtpIsrInstance  = CSL_XBAR_INST_IPU2_IRQ_29;
    xbarTxIsrInstance   = CSL_XBAR_INST_IPU2_IRQ_30;
#endif

#if defined (_TMS320C6X) 
    cpuId               = CSL_XBAR_IRQ_CPU_ID_DSP1;
    xbarRxIsrInstance   = CSL_XBAR_INST_DSP1_IRQ_77;
    xbarLinkIsrInstance = CSL_XBAR_INST_DSP1_IRQ_76;
    xbarPtpIsrInstance  = CSL_XBAR_INST_DSP1_IRQ_78;
    xbarTxIsrInstance   = CSL_XBAR_INST_DSP1_IRQ_79;
#endif

#if defined (__ARM_ARCH_7A__)
    cpuId               = CSL_XBAR_IRQ_CPU_ID_MPU;
    xbarRxIsrInstance   = CSL_XBAR_INST_MPU_IRQ_121;
    xbarLinkIsrInstance = CSL_XBAR_INST_MPU_IRQ_120;
    xbarPtpIsrInstance  = CSL_XBAR_INST_MPU_IRQ_123;
    xbarTxIsrInstance   = CSL_XBAR_INST_MPU_IRQ_124;
#endif

    /*For AM57x, chip DB is not used .here it is hard coded to PRUSS instance 2*/
    if(instance == 2)
    {
        CSL_xbarIrqConfigure(cpuId,xbarPtpIsrInstance,
                                  CSL_XBAR_PRUSS2_IRQ_HOST6);   /* TS ISR */
        if (portNum == 0)
        {
            CSL_xbarIrqConfigure(cpuId, xbarRxIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST2);        /* RX ISR */
            CSL_xbarIrqConfigure(cpuId, xbarTxIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST4);        /* Tx ISR */
            CSL_xbarIrqConfigure(cpuId, xbarLinkIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST8);        /* LINK ISR */
        }
        else
        {
            CSL_xbarIrqConfigure(cpuId, xbarLinkIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST9);        /* LINK ISR */
            CSL_xbarIrqConfigure(cpuId, xbarRxIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST3);        /* RX ISR */
            CSL_xbarIrqConfigure(cpuId, xbarTxIsrInstance,
                                 CSL_XBAR_PRUSS2_IRQ_HOST5);        /* Tx ISR */
        }
    }

    /*Cross bar programming CTRL_CORE_DMA_EDMA_DREQ_38_39
     * to enable EDMA. This is required for Time Sync module*/
    HWREGB(0x4A002CC4) = 0xc9;

    /*Sync0 output pinmuxing. Write 0xa
     * into the first byte of CTRL_CORE_PAD_VOUT1_D7
     *
     * This is a workaround for the issue where PDK is
     * not doing default pinmuxing correctly
     * */
    HWREGB(0x4A0035F8) = 0xa;

}

void timeSync_example_socHwInit()
{
    /* Enable PWMSS1Module */
    timeSync_example_enablePWMSS1Module();
}

icssVersion_t timeSync_exampleSoCGetIcssVersion(void)
{
   icssVersion_t ver = V2;
   return (ver);
}


void timeSync_example_socgetMACAddress(uint32_t portNum, uint8_t *macAddr)
{
    Board_IDInfo info;
    portNum++;
    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);

    info.indEthMacID0[5] &= portNum;
    memcpy((void *) macAddr, (void *) info.indEthMacID0, BOARD_EEPROM_MACADDR_LENGTH);

    return;

}

uint8_t timeSync_example_loadFirmware(void)
{
	uint8_t   firmwareLoad_done = FALSE;
#if defined(idkAM572x)
	uint32_t pgVersion;
#endif
	PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);

#if defined(idkAM572x)
    pgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;

    if (pgVersion >= 2)
    {
        if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev2_start,
                              &pru_imem0_rev2_end - &pru_imem0_rev2_start))
        {
            if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                  (uint32_t *) &pru_imem1_rev2_start,
                                  &pru_imem1_rev2_end - &pru_imem1_rev2_start))
            {
                firmwareLoad_done = TRUE;
            }
        }
    }
     else
    {
        if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev1_start,
                              &pru_imem0_rev1_end - &pru_imem0_rev1_start))
        {
            if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                  (uint32_t *) &pru_imem1_rev1_start,
                                  &pru_imem1_rev1_end - &pru_imem1_rev1_start))
            {
                firmwareLoad_done = TRUE;
             }
        }
    }
#endif

#if defined(idkAM571x) || defined(iceK2G) || defined(idkAM574x)
     if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev2_start,
                          &pru_imem0_rev2_end - &pru_imem0_rev2_start))
    {
        if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                              (uint32_t *) &pru_imem1_rev2_start,
                              &pru_imem1_rev2_end - &pru_imem1_rev2_start))
        {
            firmwareLoad_done = TRUE;
        }
    }
#endif

    return (firmwareLoad_done);
}
