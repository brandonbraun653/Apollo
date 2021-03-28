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
#include <ti/sysbios/family/arm/a8/Mmu.h>

#include <ti/ndk/inc/stkmain.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>

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

extern void cclink_thread (UArg a0, UArg a1);

extern char *LocalIPAddr;

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define NIMU_log                UART_printf
#else
#define NIMU_log                printf
#endif

/* ========================================================================== */
/*                             Macros                                  */
/* ========================================================================== */

/**Phy address of the CPSW port 1*/
#define CPSW_PORT0_PHY_ADDR_EVM     0
/**Phy address of the CPSW port 1*/
#define CPSW_PORT1_PHY_ADDR_EVM     1


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

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

	/* Chip configuration MII/RMII selection */
    SOCCtrlCpswPortMacModeSelect(1, ETHERNET_MAC_TYPE_RGMII);
    SOCCtrlCpswPortMacModeSelect(2, ETHERNET_MAC_TYPE_RGMII);



    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x1400;
    main_task = Task_create (cclink_thread, &taskParams, NULL);

    NIMUDeviceTable[nimu_device_index++].init =  &CpswEmacInit ;
    NIMUDeviceTable[nimu_device_index].init =  NULL ;

    BIOS_start();

    return -1;
}
