/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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



#include <ti/csl/soc.h>
#include <ti/csl/cslr_device.h>
#if defined (SOC_AM574x)
#include <ti/csl/soc/am574x/src/csl_device_xbar.h>
#else
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>
#endif

#include <ti/ndk/inc/stkmain.h>
#include <ti/board/board.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

#ifdef NIMU_FTP_APP
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>
#endif

extern void cclink_thread (UArg a0, UArg a1);

extern char *LocalIPAddr;

/* ========================================================================== */
/*                             Macros                                  */
/* ========================================================================== */
/* Enable the below macro to have prints on the IO Console */

//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define NIMU_log                UART_printf
#else
#define NIMU_log                printf
#endif

#define MAX_TABLE_ENTRIES   3

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**Task handle for EIP*/
Task_Handle main_task;

static int nimu_device_index = 0U;


NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[MAX_TABLE_ENTRIES];

void TaskFxn(UArg a0, UArg a1);
extern int CpswEmacInit (STKEVENT_Handle hEvent);


/**
 *  \name main
 *  \brief Main Function
 *  \param none
 *  \return none
 *
 */
int main()
{
    /* Call board init functions */
    Board_initCfg boardCfg;
    Task_Params taskParams;

    boardCfg =  BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

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

#ifdef evmAM572x
    EMAC_HwAttrs_V4 cfg;
    EMAC_socGetInitCfg(0, &cfg);
    cfg.port[0].phy_addr = GMAC_PORT1_ETHERNET_PHY_ADRESS;
    cfg.port[1].phy_addr = GMAC_PORT2_ETHERNET_PHY_ADRESS;
    EMAC_socSetInitCfg(0, &cfg);
#endif
    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x1400;
    main_task = Task_create (cclink_thread, &taskParams, NULL);

    NIMUDeviceTable[nimu_device_index++].init =  &CpswEmacInit ;
    NIMUDeviceTable[nimu_device_index].init =  NULL ;

    BIOS_start();

    return -1;
}
