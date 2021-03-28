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
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/starterware/include/soc_control.h>
#include <ti/starterware/include/chipdb.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <src/soc/timeSyncExampleSoC.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

void timeSync_example_configureInterrupts(uint32_t portNum, ICSSEMAC_InitConfig *switchEmacCfg)
{
    /* Interrupt configuration */
    /*ARM interrupt number 20 on AM3x, 20+32 on AM4x, 20+100+32 on AM5x*/
    switchEmacCfg->rxIntNum = TIMESYNC_APP_RX_INT_NUM;
    /*ARM interrupt number 26 on AM3x, 26+32 on AM4x, 26+100+32 on AM5x*/
    switchEmacCfg->linkIntNum = TIMESYNC_APP_LINK_INT_NUM;

    /*Configure Time Sync interrupts*/
    timeSyncHandle->timeSyncConfig.txIntNum = TIMESYNC_APP_TSTX_INT_NUM;

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
    switchEmacCfg->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
    switchEmacCfg->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
    switchEmacCfg->pacingThreshold = 100;
    switchEmacCfg->learningEn = 0;

    timeSync_example_socgetMACAddress(portNum,lclMac);
    switchEmacCfg->macId = lclMac;

}

void timeSync_example_socHwInit(void)
{
    PRCMModuleEnable(CHIPDB_MOD_ID_PWMSS, 0, 0);

    /* Clock source selection */
    SOCCtrlTimerClkSrcSelect(TIMESYNC_APP_TIMER_ID,
                             SOC_CTRL_DMTIMER_CLK_SRC_M_OSC_24M);
    PRCMModuleEnable(CHIPDB_MOD_ID_DMTIMER, TIMESYNC_APP_TIMER_ID , FALSE);
    PRCMModuleEnable(CHIPDB_MOD_ID_DMTIMER, TIMESYNC_APP_TIMER_ID + 2, FALSE);

    /*Pinmux for LatchO in AM437x IDK*/
    HWREG(0x44E10978) = 0x00050006;

}

icssVersion_t timeSync_exampleSoCGetIcssVersion(void)
{
   icssVersion_t ver = V1;
   return (ver);
}


void timeSync_example_socgetMACAddress(uint32_t portNum, uint8_t *macAddr)
{
    SOCCtrlGetPortMacAddr(1, macAddr);
    return;

}

uint8_t timeSync_example_loadFirmware(void)
{
    uint8_t   firmwareLoad_done = FALSE;
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);
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

    return( firmwareLoad_done);
}

/* Nothing past this point */
