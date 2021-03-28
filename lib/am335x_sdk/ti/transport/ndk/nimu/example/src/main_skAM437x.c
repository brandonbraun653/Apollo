/*
 * Copyright (C) 2015 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/starterware/include/hw/hw_control_am43xx.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/ethernet.h>

#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

extern char *LocalIPAddr;
extern void app_stats(UArg arg0, UArg arg1);

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
#define EMAC_CPSW_PORT0_PHY_ADDR_SK 4
/**Phy address of the CPSW port 2*/
#define EMAC_CPSW_PORT1_PHY_ADDR_SK 5

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
int main()
{
    /* Call board init functions */
    Board_initCfg boardCfg;
    Task_Params taskParams;
    EMAC_HwAttrs_V4 cfg;

    SDKMMUInit(applMmuEntries);

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    /* Chip configuration MII/RMII selection */
    CpswPortMacModeSelect(1, ETHERNET_MAC_TYPE_RGMII);
    CpswPortMacModeSelect(2, ETHERNET_MAC_TYPE_RGMII);



    EMAC_socGetInitCfg(0, &cfg);
    cfg.port[0].phy_addr = EMAC_CPSW_PORT0_PHY_ADDR_SK;
    cfg.port[1].phy_addr = EMAC_CPSW_PORT1_PHY_ADDR_SK;
    EMAC_socSetInitCfg(0, &cfg);

    Task_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.stackSize = 0x1400;
    main_task = Task_create (TaskFxn, &taskParams, NULL);

    Task_Params_init(&taskParams);
    taskParams.priority = 9;
    taskParams.instance->name = "EmacStats";
    Task_create(app_stats, &taskParams, NULL);

    NIMUDeviceTable[nimu_device_index++].init =  &CpswEmacInit ;
    NIMUDeviceTable[nimu_device_index].init =  NULL ;

    BIOS_start();

    return -1;
}

/**
 *  \name TaskFxn
 *  \brief Task which do EIP initialization
 *  \param a0
 *  \param a1
 *  \return none
 *
 */
void TaskFxn(UArg a0, UArg a1)
{
 NIMU_log("\n\rSYS/BIOS Ethernet/IP (CPSW) Sample application, EVM IP address: %s\n\r", LocalIPAddr);
}
