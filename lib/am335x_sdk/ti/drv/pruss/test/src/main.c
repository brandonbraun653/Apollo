/**
 * \file      main.c
 *
 * \brief     This file contains pruss example application code.This will
 *             test the API's of the PRU0 of PRUICSS1, interrupt handling
 *             and event handling .



 * Copyright (c) 2015, Texas Instruments Incorporated
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
/** ============================================================================*/


#ifndef __LINUX_USER_SPACE
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#else
#include "mmap_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#endif

#include <ti/drv/pruss/test/src/test_pruss_intc_mapping.h>
#include <ti/drv/pruss/test/src/pru_firmware/pruss_test_pru0_bin.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/pruss/pruicss.h>


#include <ti/csl/soc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_pru_ctrl.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>

#include <ti/csl/hw_types.h>


#ifndef __LINUX_USER_SPACE
#include <ti/drv/uart/UART.h>
#ifdef __JAILHOUSE_INMATE
#include <ti/drv/uart/soc/UART_soc.h>
#endif
#include <ti/drv/uart/UART_stdio.h>
#include "ti/board/board.h"
#endif

#include <ti/osal/osal.h>

#ifdef __LINUX_USER_SPACE
#define PRINT printf

/* t is given in ms */
void linux_sleep_ms(int ms) {
	struct timespec ts;
	ts.tv_sec = (ms)/1000; \
    ts.tv_nsec = (ms*1000000)%1000000000; \
    nanosleep(&ts, NULL);
}
#define SLEEP(t) linux_sleep_ms(t)

#else
#define PRINT UART_printf
#define SLEEP Task_sleep

#endif


/*This will enable the PRINT through the UART. for this project
                      should include the UART driver library and UART_soc.c files*/
#define UART_PRINT

#define PRUSS_EVENT_COUNT 5

#define PRUSS_TEST_CONSTANT_TABLE_CHECK 0x00020001

static uint32_t pruEventCount = 0;
static int eventregistered = 0;
static int prueventsent = 0;

static int eventregistered2 = 0;
static int prueventsent2 = 0;
static uint32_t pruEventCount2 = 0;

/* Example/Board Header files */
#ifndef SOC_K2G
static void Board_initPruss(void);
#endif

#ifdef __LINUX_USER_SPACE
void *eventwait(void *a0);
void *eventwait2(void *a0);
#endif
void pruss_isr(void*);
void pruss_isr2(void*);

// Set parameters to change PRU [1 or 2] and PRU core [0 or 1]
int pru_num = 1, pru_core_num = 0;

#ifdef __LINUX_USER_SPACE
tprussdrv *pruss_drv_handle, *pruss_drv_handle2;
PRUICSS_HwAttrs linux_prussInitCfg[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_V1_Object linux_prussObjects[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_Config linux_pruss_config[PRUICCSS_INSTANCE_MAX] = {
	{
		&(linux_prussObjects[0]),
		&(linux_prussInitCfg[0])
	},
	{
		&(linux_prussObjects[1]),
		&(linux_prussInitCfg[1])
	},
	{NULL, NULL}
};
#endif

PRUICSS_Handle handle = NULL;
PRUICSS_Handle handle2 = NULL;



void pruss_isr(void * ptr)
{
    PRUICSS_pruClearEvent(handle,PRU0_ARM_EVENT);
}

void pruss_isr2(void * ptr)
{
    PRUICSS_pruClearEvent(handle2,PRU0_ARM_EVENT);
}

int32_t  prussTestVerifiyConstantTblUpdate(PRUICSS_Handle handle)
{
    uint32_t readval = 0;
    if (pru_core_num == 0)
    {
        PRUICSS_HwAttrs      const    *hwAttrs = handle->hwAttrs;
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC24, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC25, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru0CtrlRegBase + CSL_ICSSPRUCTRL_CTBIR0);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC26, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC27, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru0CtrlRegBase + CSL_ICSSPRUCTRL_CTBIR1);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC28, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC29, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru0CtrlRegBase + CSL_ICSSPRUCTRL_CTPPR0);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC30, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC31, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru0CtrlRegBase + CSL_ICSSPRUCTRL_CTPPR1);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }
    }
    else
    {
        PRUICSS_HwAttrs      const    *hwAttrs = handle->hwAttrs;
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC24, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC25, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru1CtrlRegBase + CSL_ICSSPRUCTRL_CTBIR0);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC26, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC27, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru1CtrlRegBase + CSL_ICSSPRUCTRL_CTBIR1);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC28, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC29, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru1CtrlRegBase + CSL_ICSSPRUCTRL_CTPPR0);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }

        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC30, 0x00000001U);
        PRUICSS_setConstantTblEntry(handle, pru_core_num,  PRUICCSS_ConstTblEntryC31, 0x00000002U);
        readval = HW_RD_REG32(hwAttrs->prussPru1CtrlRegBase + CSL_ICSSPRUCTRL_CTPPR1);
        if (readval != PRUSS_TEST_CONSTANT_TABLE_CHECK)
        {
            return 0;
        }
    }
    return 1;
}
uint32_t taskFxnDone = 0;
/*
 *  ======== taskFxn ========
 */
#ifdef __LINUX_USER_SPACE
void *taskFxn(void *a0)
#else
Void taskFxn(UArg a0, UArg a1)
#endif
{
    PRUICSS_IntcInitData pruss_intc_initdata = PRUICSS_INTC_INITDATA;
    PRUICSS_Config  *cfg;
    PRUICSS_IntrCfg intrCfg;

    pru_num = PRUICCSS_INSTANCE_ONE;

#ifdef __LINUX_USER_SPACE
    linux_init((void**)&pruss_drv_handle, linux_prussInitCfg, pru_num);
    cfg = linux_pruss_config;
#else
    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        return (ret);
    }
#endif

    handle = PRUICSS_create(cfg,pru_num);

    intrCfg.pruEvtoutNum = 2;
    intrCfg.waitEnable = 1;
    intrCfg.irqHandler = pruss_isr;
#ifdef SOC_K2G
#ifdef _TMS320C6X
    intrCfg.intNum = 8;
    intrCfg.eventId = CSL_C66X_COREPAC_CIC_0_OUT47;
    intrCfg.intcMuxNum =0;
    intrCfg.intcMuxInEvent = CSL_CIC_ICSSM0_HOST_INT0;
    intrCfg.intcMuxOutEvent = 47; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT47 */
#else
    intrCfg.intNum = CSL_ARM_GIC_ICSSM0_HOST_INT0 + 32;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#endif
#else
#ifdef _TMS320C6X
    intrCfg.intNum = 12;
    intrCfg.eventId = 92; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#elif __ARM_ARCH_7A__
    intrCfg.intNum = 134+32;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#else
    intrCfg.intNum = 48;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
    intrCfg.pruEvtoutNum = 2;
    intrCfg.waitEnable = 1;
    intrCfg.irqHandler = pruss_isr;
#endif
#endif
#ifdef __LINUX_USER_SPACE
    prussdrv_open(pruss_drv_handle, PRU_EVTOUT_0);
    prussdrv_start_irqthread(pruss_drv_handle, PRU_EVTOUT_0,
                                sched_get_priority_max(SCHED_FIFO)-10,
                                eventwait);
#else
    PRUICSS_registerIrqHandler2(handle,
                                                 &intrCfg);
#endif

    for (pru_core_num = PRUICCSS_PRU0; pru_core_num <= PRUICCSS_PRU1;pru_core_num++)
    {
        PRUICSS_pruDisable(handle,pru_core_num);
        /* Verification of PRUICSS_setConstantTblEntry API */
        if (prussTestVerifiyConstantTblUpdate(handle))
        {
            PRINT("passed verify constant tbl entry for instance %d: pruNum: %d\n", pru_num, pru_core_num);
            eventregistered = 1;
            PRUICSS_setPRUBuffer(handle,pru_core_num, (void*)XYZ, sizeof(XYZ));
            PRUICSS_pruIntcInit(handle,&pruss_intc_initdata);
            /* Test intc clear API and then init once again */
            PRUICSS_pruIntcClear(handle);
            PRUICSS_pruIntcInit(handle,&pruss_intc_initdata);
            PRUICSS_pruExecProgram(handle,pru_core_num);
            PRUICSS_pruEnable(handle,pru_core_num);
            SLEEP(1000);
            while(1)
            {
                if(prueventsent == 0 )
                {
                    if (pruEventCount == PRUSS_EVENT_COUNT)
                    {
                        PRINT("Testing for instance: %d, pru num: %d is complete\n", pru_num, pru_core_num);
                        pruEventCount = 0;
                        break;
                    }
                    PRINT("sending the INTC event to the PRU for instance: %d , pru num: %d\n", pru_num, pru_core_num);
                    prueventsent =1;
                    PRUICSS_pruSendEvent(handle,ARM_PRU0_EVENT);
                }
                else
                {
                    SLEEP(1000);
                }
            }
        }
        else
        {
            PRINT("All tests have failed\n");
        }
    }
    taskFxnDone = 1;
}


#ifdef __LINUX_USER_SPACE
void *taskFxn2(void *a0)
#else
Void taskFxn2(UArg a0, UArg a1)
#endif
{
    PRUICSS_IntcInitData pruss_intc_initdata = PRUICSS_INTC_INITDATA;
    PRUICSS_Config  *cfg;
    PRUICSS_IntrCfg intrCfg;
    PRUICSS_HwAttrs      const    *hwAttrs;
    uint32_t clkSource;
    while(taskFxnDone == 0)
        SLEEP(1000);

    pru_num = PRUICCSS_INSTANCE_TWO;

#ifdef __LINUX_USER_SPACE
    linux_init((void**)&pruss_drv_handle2, linux_prussInitCfg, pru_num);
    cfg = linux_pruss_config;
#else
    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
    {
        return (ret);
    }
#endif

    handle2 = PRUICSS_create(cfg,pru_num);

    /* Test  instance 2 using OCP as IEP clock source */
    PRINT("testing instance 2 using OCP as IEP clock source\n");
    hwAttrs = (PRUICSS_HwAttrs*)handle2->hwAttrs;
    PRUICSS_setIepClkSrc(handle2,1U);
    clkSource = HW_RD_REG32(hwAttrs->prussCfgRegBase+ CSL_ICSSCFG_IEPCLK);

     if (clkSource == 1U)
     {
        PRINT("correct IEP clock source setting\n");
     }
     else
     {
     
        PRINT("incorrect IEP clock source setting,. test failed\n");
        while(1);
     }
    intrCfg.pruEvtoutNum = 2;
    intrCfg.waitEnable = 1;
    intrCfg.irqHandler = pruss_isr2;
#ifdef SOC_K2G
#ifdef _TMS320C6X
    intrCfg.intNum = 9;
    intrCfg.eventId = CSL_C66X_COREPAC_CIC_0_OUT48;
    intrCfg.intcMuxNum =0;
    intrCfg.intcMuxInEvent = CSL_CIC_ICSSM1_HOST_INT0;
    intrCfg.intcMuxOutEvent = 48; /* correlates to CSL_C66X_COREPAC_CIC_0_OUT48 */
#else
    intrCfg.intNum = CSL_ARM_GIC_ICSSM1_HOST_INT0 + 32;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#endif
#else
#ifdef _TMS320C6X
    intrCfg.intNum = 15;
    intrCfg.eventId = 93; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#elif __ARM_ARCH_7A__
    intrCfg.intNum = 135+32;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
#else
    intrCfg.intNum = 49;
    intrCfg.eventId = 0; /* not applicable for ARM; */
    intrCfg.intcMuxNum =PRUSS_INVALID_INTC_MUX_NUM; /* not applicable for ARM; */
    intrCfg.intcMuxInEvent = 0;/* not applicable for ARM; */
    intrCfg.intcMuxOutEvent = 0; /* not applicable for ARM; */
    intrCfg.pruEvtoutNum = 2;
    intrCfg.waitEnable = 1;
    intrCfg.irqHandler = pruss_isr2;
#endif
#endif
#ifdef __LINUX_USER_SPACE
    prussdrv_open(pruss_drv_handle2, PRU_EVTOUT_0);
    prussdrv_start_irqthread(pruss_drv_handle2, PRU_EVTOUT_0,
                                sched_get_priority_max(SCHED_FIFO)-10,
                                eventwait2);
#else
    PRUICSS_registerIrqHandler2(handle2,
                                                 &intrCfg);
#endif

    for (pru_core_num = PRUICCSS_PRU0; pru_core_num <= PRUICCSS_PRU1;pru_core_num++)
    {
        PRUICSS_pruDisable(handle2,pru_core_num);
        /* Verification of PRUICSS_setConstantTblEntry API */
        if (prussTestVerifiyConstantTblUpdate(handle2))
        {
            PRINT("passed verify constant tbl entry for instance %d: pruNum: %d\n", pru_num, pru_core_num);
            eventregistered2 = 1;
            PRUICSS_setPRUBuffer(handle2,pru_core_num, (void*)XYZ, sizeof(XYZ));
            PRUICSS_pruIntcInit(handle2,&pruss_intc_initdata);
            /* Test intc clear API and then init once again */
            PRUICSS_pruIntcClear(handle2);
            PRUICSS_pruIntcInit(handle2,&pruss_intc_initdata);
            PRUICSS_pruExecProgram(handle2,pru_core_num);
            PRUICSS_pruEnable(handle2,pru_core_num);
            SLEEP(1000);
            while(1)
            {
                if(prueventsent2 == 0 )
                {
                    if (pruEventCount2 == PRUSS_EVENT_COUNT)
                    {
                        PRINT("Testing for instance: %d, pru num: %d is complete\n", pru_num, pru_core_num);
                        if(pru_core_num == PRUICCSS_PRU1)
                        {
                            PRINT("All tests have passed\n");
                        }
                        pruEventCount2 = 0;
                        break;
                    }
                    PRINT("sending the INTC event to the PRU for instance: %d , pru num: %d\n", pru_num, pru_core_num);
                    prueventsent2 =1;
                    PRUICSS_pruSendEvent(handle2,ARM_PRU0_EVENT);
                }
                else
                {
                    SLEEP(1000);
                }
            }
        }
        else
        {
            PRINT("All tests have failed\n");
        }
    }
}


#ifdef __LINUX_USER_SPACE
void *eventwait(void *a0)
#else
void eventwait (UArg a0, UArg a1)
#endif
{
    static int32_t pruEventCountTotal = 0;
    /*wait for the event registration*/
    while(eventregistered == 0)
    {
        SLEEP(1000);
    }
    while (1)
    {
        PRINT("eventwait: waiting for the INTC event from PRU\n");
#ifdef __LINUX_USER_SPACE
        prussdrv_pru_wait_event(pruss_drv_handle, PRU_EVTOUT_0);
        PRUICSS_pruClearEvent(handle,PRU0_ARM_EVENT);
#else
        PRUICSS_pruWaitEvent(handle,2);
#endif
        pruEventCountTotal++;
        prueventsent=0;
        pruEventCount++;
        PRINT("eventwait: got the INTC event from PRU, count: %d\n", pruEventCount);
        if (pruEventCountTotal == PRUSS_EVENT_COUNT*2)
        {
            break;
        }
    }
}

#ifdef __LINUX_USER_SPACE
void *eventwait2(void *a0)
#else
void eventwait2 (UArg a0, UArg a1)
#endif
{
    static int32_t pruEventCountTotal = 0;
    /*wait for the event registration*/
    while(eventregistered2 == 0)
    {
        SLEEP(1000);
    }
    while (1)
    {
        PRINT("eventwait2: waiting for the INTC event from PRU\n");
#ifdef __LINUX_USER_SPACE
        prussdrv_pru_wait_event(pruss_drv_handle2, PRU_EVTOUT_0);
        PRUICSS_pruClearEvent(handle2,PRU0_ARM_EVENT);
#else
        PRUICSS_pruWaitEvent(handle2,2);
#endif

        pruEventCountTotal++;
        prueventsent2=0;
        pruEventCount2++;
        PRINT("eventwait2: got the INTC event from PRU, count: %d\n", pruEventCount2);
        if (pruEventCountTotal == PRUSS_EVENT_COUNT*2)
        {
            break;
        }
    }
}




/*
 *  ======== main ========
 */
#ifndef __LINUX_USER_SPACE
Int main()
{
    Task_Handle task;
    Error_Block eb;
    Task_Params taskParams;

    Task_Handle task2;
    Error_Block eb2;
    Task_Params taskParams2;

#ifdef __JAILHOUSE_INMATE
#define BOARD_UART_INSTANCE 2
    UART_HwAttrs uart_hwAttrs;

    /* Make sure non-interrupt mode is used for UART */
    /* Get the UART default configuration */
    UART_socGetInitCfg(BOARD_UART_INSTANCE, &uart_hwAttrs);
    /* Disabling interrupt mode, forcing UART to use the polling mode */
    uart_hwAttrs.enableInterrupt = 0;
    /* Write back the config */
    UART_socSetInitCfg(BOARD_UART_INSTANCE, &uart_hwAttrs);
#endif

    Board_initCfg cfg = BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO |BOARD_INIT_PINMUX_CONFIG;
    Board_init(cfg);

#ifndef SOC_K2G
    Board_initPruss();
#endif

    Error_init(&eb);
    Task_Params_init(&taskParams);
    taskParams.instance->name = (char*)"taskFxn";
    
    task = Task_create(taskFxn, &taskParams, &eb);
    if (task == NULL) {

        BIOS_exit(0);
    }

    Error_init(&eb2);
    Task_Params_init(&taskParams2);
    taskParams2.instance->name = (char*)"taskFxn2";

    task2 = Task_create(taskFxn2, &taskParams2, &eb2);
    if (task2 == NULL) {
            BIOS_exit(0);
    }

    BIOS_start();    /* does not return */
    return(0);
}
#else // __LINUX_USER_SPACE

int main(int argc, char *argv[]) {
    int status;
    pthread_t test_th, test_th2;

    if ((status = pthread_create(&test_th, NULL, taskFxn, NULL))) {
        printf("ERROR: \"taskFxn\" task-create failed (%d)\n", status);
        return (-1);
    }

    if ((status = pthread_create(&test_th2, NULL, taskFxn2, NULL))) {
        printf("ERROR: \"taskFxn\" task-create failed (%d)\n", status);
        return (-1);
    }

    pthread_join(test_th, NULL);
    pthread_join(test_th2, NULL);

    return(0);
}
#endif // __LINUX_USER_SPACE


#ifndef SOC_K2G
void Board_initPruss(void)
{
#ifdef __ARM_ARCH_7A__
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_134, CSL_XBAR_PRUSS1_IRQ_HOST2);
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_135, CSL_XBAR_PRUSS2_IRQ_HOST2);
#elif _TMS320C6X
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_92, CSL_XBAR_PRUSS1_IRQ_HOST2);
    CSL_xbarDspIrqConfigure(1, CSL_XBAR_INST_DSP1_IRQ_93, CSL_XBAR_PRUSS2_IRQ_HOST2);
#else
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_48, CSL_XBAR_PRUSS1_IRQ_HOST2);
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_49, CSL_XBAR_PRUSS2_IRQ_HOST2);
#endif
}
#endif
