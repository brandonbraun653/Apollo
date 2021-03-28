/**
 * @file   main_am65xx.c
 *
 * @brief  This file tests the EMAC driver APIs using loopback mode of operation
 */
/*
 * Copyright (c) 2018, Texas Instruments Incorporated
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
 */


#include <stdio.h>
#include <string.h>


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/family/arm/v8a/Mmu.h>

/* CSL Header files */
#include <ti/csl/soc.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* BOARD Header files */
#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>

extern uint32_t app_test_recv_port;

/* UDMA Driver Header File. */
#include <ti/drv/udma/udma.h>
/* Test application local header file */
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"
#include "ti/drv/emac/test/EmacLoopbackTest/test_utils.h"


extern void app_test_task_verify_ut_dual_mac_cpsw(UArg arg0, UArg arg1);
extern void app_test_task_benchmark(UArg arg0, UArg arg1);
extern void app_test_task_verify_ut_switch(UArg arg0, UArg arg1);
/*
 *  ======== Globals========
 */

const char* rxTaskName[7] =  {"rxPort0","rxPort1","rxPort2","rxPort3","rxPort4","rxPort5","rxPort6"};
const char* rxMgmtTaskName[7] =  {"rxMgmtPort0","rxMgmtPort1","rxMgmtPort2","rxMgmtPort3","rxMgmtPort4","rxMgmtPort5","rxMgmtPort6"};

#ifdef EMAC_TEST_APP_ICSSG_SWITCH
int32_t port_en[EMAC_PORT_CPSW + 1] = {1, 1, 1, 1, 0, 0, 0};
#else
    #ifdef EMAC_TEST_APP_WITHOUT_DDR
    int32_t port_en[EMAC_PORT_CPSW + 1] = {1, 1, 0, 0, 0, 0, 0};
    #else
        #ifdef EMAC_BENCHMARK
            #ifdef EMAC_TEST_APP_ICSSG
                int32_t port_en[EMAC_PORT_CPSW + 1] = {0, 0, 0, 0, 1, 0, 0};
            #else /* CPSW use case */
                int32_t port_en[EMAC_PORT_CPSW + 1] = {0, 0, 0, 0, 0, 0, 1};
            #endif
        #else
            #ifdef EMAC_TEST_APP_ICSSG
                int32_t  port_en[EMAC_PORT_CPSW + 1] = {1, 1, 1, 1, 1, 1, 0};
            #else /* CPSW use case */
                int32_t port_en[EMAC_PORT_CPSW + 1] = {0, 0, 0, 0, 0, 0, 1};
            #endif
        #endif
    #endif
#endif

#ifdef EMAC_TEST_APP_CPSW
uint32_t portNum = EMAC_PORT_CPSW;
uint32_t endPort = EMAC_PORT_CPSW;
#else
/* ICSSG case */
#ifdef am65xx_idk
uint32_t portNum = EMAC_PORT_ICSS;
uint32_t endPort = EMAC_PORT_ICSS+5;
#else
uint32_t portNum = EMAC_PORT_ICSS + 4;
uint32_t endPort = EMAC_PORT_ICSS + 5;
#endif
#endif



void delay(unsigned int delayValue)
{
    volatile uint32_t delay = delayValue*100;
    while (delay--) ;
}

#ifdef BUILD_MCU
uint32_t AsmReadActlr(void);
void AsmWriteActlr(uint32_t);
#endif

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params     taskParams;
    Error_Block eb;
    Error_init(&eb);

#ifdef EMAC_TEST_APP_ICSSG_SWITCH
#ifndef EMAC_BENCHMARK
        /* Create the  task start the unit test.*/
        Task_Params_init(&taskParams);
        taskParams.priority = 10;
        taskParams.instance->name = "app_test_task_verify_ut_switch";
        Task_create( app_test_task_verify_ut_switch, &taskParams, NULL);
#else
        /* Create the  task to start BENCHMARK testing.*/
        Task_Params_init(&taskParams);
        taskParams.priority = 11;
        taskParams.arg0 = EMAC_SWITCH_PORT1;
        taskParams.instance->name = "app_test_task_benchmark";
        Task_create( app_test_task_benchmark, &taskParams, NULL);
#endif

#ifndef EMAC_CHECK_LINK_STATUS
    /* Create the  task to poll driver to rx pkts.*/
    /* set the priority to 10 for both polling tasks */
    taskParams.priority = 10;

    taskParams.arg0 = EMAC_SWITCH_PORT1;
    taskParams.instance->name = rxTaskName[0];
    Task_create(app_test_task_poll_ctrl, &taskParams, NULL);

    taskParams.arg0 = EMAC_SWITCH_PORT2;
    taskParams.instance->name = rxTaskName[2];
    Task_create(app_test_task_poll_ctrl, &taskParams, NULL);
#endif
#else
#ifndef EMAC_BENCHMARK
    /* Create the  task start the unit test.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.instance->name = "app_test_task_verify_ut_dual_mac_cpsw";
    Task_create( app_test_task_verify_ut_dual_mac_cpsw, &taskParams, NULL);
#else
    /* Create the  task to start BENCHMARK testing.*/
    Task_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.arg0 = EMAC_PORT_ICSS + 4;
    taskParams.instance->name = "app_test_task_benchmark";
    Task_create( app_test_task_benchmark, &taskParams, NULL);
#endif

    int i;
    for (i = portNum; i <=endPort; i++)
    {
        /* will poll on app_test_recv_port */
#ifdef EMAC_BENCHMARK
        if ((!port_en[i]) || (i != app_test_recv_port))
#else
        if (!port_en[i])
#endif
            continue;
            /* Create the  task to poll driver to rx packets driver.*/
            Task_Params_init(&taskParams);
            taskParams.arg0 = i;
            taskParams.priority = 10;
            taskParams.instance->name = rxTaskName[i];
            Task_create(app_test_task_poll_pkt, &taskParams, NULL);

#ifndef EMAC_BENCHMARK
            /* Create the  task to poll driver to rx cfg responses.*/
            Task_Params_init(&taskParams);
            taskParams.arg0 = i;
            taskParams.priority = 10;
            taskParams.instance->name = rxMgmtTaskName[i];
            Task_create(app_test_task_poll_ctrl, &taskParams, NULL);
#endif
    }

#endif
    {
#ifdef BUILD_MCU
        uint32_t actlrRegVal = AsmReadActlr();
        actlrRegVal |= (1 << 13);
        AsmWriteActlr(actlrRegVal);
#endif
    }
    /* Start BIOS */
    BIOS_start();
    return 0;
}


#if defined (__aarch64__)
struct MmuCfg_t {
    uint64_t    vaddr;
    uint64_t    paddr;
    size_t      size;
    int         attrInd;
} MmuCfgTbl[] = {
    { 0x00100000, 0x00100000, 0x00900000, 0 }, /* Main MMR0     */
    { 0x00400000, 0x00400000, 0x00001000, 0 }, /* PSC0          */
    { 0x01800000, 0x01800000, 0x00100000, 0 }, /* gicv3         */
    { 0x02400000, 0x02400000, 0x000c0000, 0 }, /* dmtimer       */
    { 0x02800000, 0x02800000, 0x00001000, 0 }, /* uart          */
    { 0x02000000, 0x02000000, 0x00100000, 0 }, /* I2C           */
    { 0x02100000, 0x02100000, 0x00080000, 0 }, /* McSPI         */
    { 0x40F00000, 0x40F00000, 0x00020000, 0 }, /* MCU MMR0      */
    { 0x40d00000, 0x40d00000, 0x00002000, 0 }, /* PLL0          */
    { 0x43000000, 0x43000000, 0x00020000, 0 }, /* WKUP MMR0     */
    { 0x02C40000, 0x02C40000, 0x00100000, 0 }, /* pinmux ctrl   */
    { 0x30800000, 0x30800000, 0x0C000000, 0 }, /* main navss    */
    { 0x28380000, 0x28380000, 0x03880000, 0 }, /* mcu navss     */
    { 0x30000000, 0x30000000, 0x0F000000, 0 }, /* ctrcontrol0   */
    { CSL_MCU_CPSW0_NUSS_BASE, CSL_MCU_CPSW0_NUSS_BASE,
        (CSL_MCU_CPSW0_NUSS_SIZE*2), 0 },      /* for CPSW      */
    { 0x0b000000, 0x0b000000, 0x00100000, 0 }, /* ICSS-G 0      */
    { 0x0b100000, 0x0b100000, 0x00100000, 0 }, /* ICSS-G 1      */
    { 0x0b200000, 0x0b200000, 0x00100000, 0 }, /* ICSS-G 2      */
    { 0x42000000, 0x42000000, 0x00001000, 0 }, /* PSC WKUP      */
    { 0x03802000, 0x03802000, 0x00001000, 0 }, /* NB0_CFG_MMRS  */
    { 0x70000000, 0x70000000, 0x04000000, 7 }, /* msmc          */
    { 0x41C00000, 0x41C00000, 0x00080000, 7 }, /* ocmc          */
    { 0x80000000, 0x80000000, 0x10000000, 7 }, /* ddr_0          */
    { 0, 0, 0, 8 } /* attrInd = 8 -> end of table */
};

void InitMmu(void)
{
    bool        retVal = FALSE;
    uint32_t    j = 0;
    Mmu_MapAttrs attrs;
    Mmu_initMapAttrs(&attrs);
    while (MmuCfgTbl[j].attrInd < 8) {
        attrs.attrIndx = MmuCfgTbl[j].attrInd;
        retVal = Mmu_map(MmuCfgTbl[j].vaddr, MmuCfgTbl[j].paddr, MmuCfgTbl[j].size, &attrs);
        if(retVal == FALSE)
            break;
        j++;
    }

    if(retVal == FALSE) {
        UART_printf("Mmu_map idx %d returned error %d", j, retVal);
        while(1);
    }
}
#endif

