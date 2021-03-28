/**
 * @file   main_test.c
 *
 * @brief  This file tests the UART driver APIs in Blocking mode.
 */
/*
 * Copyright (c) 2014 - 2018, Texas Instruments Incorporated
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

#ifdef USE_BIOS
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#endif /* #ifdef USE_BIOS */

/* CSL Header files */
#include <ti/csl/csl_chip.h>
#include <ti/csl/soc.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include "UART_board.h"

#if defined(SOC_J721E) || defined(SOC_J7200)
#include <ti/csl/soc.h>
#endif

#if defined(SOC_J721E) || defined(SOC_AM65XX) || defined(SOC_J7200)
#include <ti/drv/sciclient/sciclient.h>
#endif

#include <ti/csl/csl_clec.h>

#if defined (__C7100__)
#include <ti/csl/arch/csl_arch.h>
#endif

void Uart_appC7xPreInit(void);

/* Define the UART test interface */
typedef struct UART_Tests_s
{
    bool     (*testFunc)(bool);
    bool     dmaMode;
    int16_t  testId;
    char     testDesc[80];

} UART_Tests;

/* UART test ID definitions */
#define UART_TEST_ID_DMA         0   /* UART DMA read write test in block mode */
#define UART_TEST_ID_INT         1   /* UART non-DMA read write test in block mode */
#define UART_TEST_ID_DMA_CB      2   /* UART DMA read write test in callback mode */
#define UART_TEST_ID_CB          3   /* UART non-DMA read write test in callback mode */
#define UART_TEST_ID_DMA_TO      4   /* UART DMA timeout test */
#define UART_TEST_ID_TO          5   /* UART non DMA timeout test */
#define UART_TEST_ID_DMA_RXERR   6   /* UART DMA RX error test */
#define UART_TEST_ID_RXERR       7   /* UART non-DMA RX error test */
#define UART_TEST_ID_DMA_CANCEL  8   /* UART DMA read write cancel test */
#define UART_TEST_ID_CANCEL      9   /* UART non-DMA read write cancel test */
#define UART_TEST_ID_DMA_RW      10  /* UART DMA simultaneous read write test */
#define UART_TEST_ID_RW          11  /* UART non-DMA simultaneous read write test */
#define UART_TEST_ID_DMA_TRGLVL  12  /* UART DMA TX/RX FIFO trigger level test */
#define UART_TEST_ID_PRINTF      13  /* UART stdio printf and scanf test */
#define UART_TEST_ID_TRGLVL      14  /* UART non-DMA TX/RX FIFO trigger level test */
#define UART_TEST_ID_POLL_TO     15  /* UART read write polling timeout test */
#define UART_TEST_ID_STDIOPARAMS 16  /* UART stdio printf and scanf test, with configurable params(Default params) */
#define UART_TEST_ID_INT_DISABLE 17  /* UART read write test with interrupt disabled */
#define UART_TEST_ID_RDVERIFY    18  /* UART non-DMA read API Test in loopback mode */
#define UART_TEST_ID_MULTI_INSTS 19  /* UART DMA multiple instances test in loopback mode */

/* Length of the input in number of characters */
#define UART_TEST_READ_LEN     (16U)
#define UART_RDVERIFY_READ_LEN (4U)

/* Timeout value of read and write */
#define UART_TEST_TIMEOUT      (5000U)

/* Max number of instances to test in multiple instance test case */
#define UART_TEST_NUM_INSTS    (2U)

#define UART_TEST_CACHE_LINE_SIZE (128U)
#if (defined(_TMS320C6X) || defined (__TI_ARM_V7M4__))
#pragma DATA_ALIGN (scanPrompt, UART_TEST_CACHE_LINE_SIZE)
char scanPrompt[256];
#else
char scanPrompt[256] __attribute__ ((aligned (UART_TEST_CACHE_LINE_SIZE)));
#endif
char echoPrompt[40] = "\n\r Data entered is as follows \r\n";
char dataPrint[40] = "\r\n enter the data of 16 character \r\n";
char readTimeoutPrompt[60] = "\r\n Read timed out \r\n";
char breakErrPrompt[60] = "\r\n Received a break condition error \r\n";
char rdCancelPrompt[60] = "\r\n Previous read canceled \r\n";
char wrCancelPrompt[60] = "\r\n Previous write canceled \r\n";
char fifoTrgLvlData[256] = "0123456789112345678921234567893123456789412345678951234567896123456789712345678981234567899123456789";

char stdioPrint[64] = "\r\n enter the data of 16 character and press ENTER \r\n";

UART_Transaction  callbackTransaction;
SemaphoreP_Handle callbackSem = NULL;

uint32_t uartTestInstance;

int16_t verifyLoopback = 0U;

UART_PAR uartParity = UART_PAR_NONE;

#if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#ifdef UART_DMA_ENABLE
/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_TEST_APP_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES * \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)

/**
 *  \brief UDMA host mode buffer descriptor memory size.
 *  Make it multiple of UART_TEST_CACHE_LINE_SIZE alignment
 */
#define UDMA_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (UART_TEST_CACHE_LINE_SIZE - sizeof(CSL_UdmapCppi5HMPD)))

/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj;
struct Udma_ChObj       gUdmaRxChObj;
struct Udma_EventObj    gUdmaTxCqEventObj;
struct Udma_EventObj    gUdmaRxCqEventObj;

Udma_DrvHandle          gDrvHandle = NULL;
/*
 * UDMA Memories
 */
static uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTdTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaTxHpdMem[UDMA_TEST_APP_DESC_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTdRxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaRxHpdMem[UDMA_TEST_APP_DESC_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static UART_dmaInfo gUdmaInfo;

Udma_DrvHandle UartApp_udmaInit(UART_HwAttrs *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    if (gDrvHandle == NULL)
    {
        /* UDMA driver init */
#if defined (BUILD_MCU1_0) || defined (BUILD_MCU1_1)
        instId = UDMA_INST_ID_MCU_0;
#else
        instId = UDMA_INST_ID_MAIN_0;
#endif

        UdmaInitPrms_init(instId, &initPrms);
#if defined(SOC_J721E) || defined(SOC_J7200)
        /*
         * Modify the default virtual interrupt configuration
         * in UDMA RM table to support DMA mode, since UART
         * DMA example uses more than two DMA events which
         * requires numVintr > 2
         */
#if defined (BUILD_MCU2_1)
    initPrms.rmInitPrms.startVintr = 226U;
    initPrms.rmInitPrms.numVintr = 18U;
#endif
#if (defined (BUILD_MCU1_1) || defined(BUILD_MCU1_0))
    initPrms.rmInitPrms.startVintr = 124U;
    initPrms.rmInitPrms.numVintr = 4U;
#endif
  
#endif
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
    }

    if(gDrvHandle != NULL)
    {
        gDrvHandle = &gUdmaDrvObj;

        gUdmaInfo.txChHandle     = (void *)&gUdmaTxChObj;
        gUdmaInfo.rxChHandle     = (void *)&gUdmaRxChObj;
        gUdmaInfo.txRingMem      = (void *)&gTxRingMem[0];
        gUdmaInfo.cqTxRingMem    = (void *)&gTxCompRingMem[0];
        gUdmaInfo.tdCqTxRingMem  = (void *)&gTdTxCompRingMem[0];
        gUdmaInfo.rxRingMem      = (void *)&gRxRingMem[0];
        gUdmaInfo.cqRxRingMem    = (void *)&gRxCompRingMem[0];
        gUdmaInfo.tdCqRxRingMem  = (void *)&gTdRxCompRingMem[0];
        gUdmaInfo.txHpdMem       = (void *)&gUdmaTxHpdMem[0];
        gUdmaInfo.rxHpdMem       = (void *)&gUdmaRxHpdMem[0];
        gUdmaInfo.txEventHandle  = (void *)&gUdmaTxCqEventObj;
        gUdmaInfo.rxEventHandle  = (void *)&gUdmaRxCqEventObj;
        cfg->dmaInfo             = &gUdmaInfo;
    }

    return (gDrvHandle);
}

int32_t UART_udma_deinit(void)
{
    int32_t         retVal = UDMA_SOK;

    if (gDrvHandle != NULL)
    {
        retVal = Udma_deinit(gDrvHandle);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = NULL;
        }
    }

    return (retVal);
}
#endif
#endif /* #if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) */

/*
 *  ======== UART init config ========
 */
static void UART_initConfig(bool dmaMode)
{
    UART_HwAttrs uart_cfg;

    /* Get the default UART init configurations */
    UART_socGetInitCfg(uartTestInstance, &uart_cfg);

#ifdef UART_DMA_ENABLE
    if (dmaMode == true)
    {
#if defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
        uart_cfg.edmaHandle = UartApp_udmaInit(&uart_cfg);
#else
        uart_cfg.edmaHandle = UartApp_edmaInit();
#endif
        uart_cfg.dmaMode    = TRUE;
    }
    else
#endif
    {
        uart_cfg.edmaHandle = NULL;
        uart_cfg.dmaMode    = FALSE;
    }

    if(verifyLoopback)
    {
        uart_cfg.loopback   = TRUE;
    }
    else
    {
        uart_cfg.loopback   = FALSE;
    }
    /* Set the DMA enabled UART init configurations */
    UART_socSetInitCfg(uartTestInstance, &uart_cfg);
}

void UART_getTestInstNum(uint32_t *instNum, bool *boardAM570x)
{
#if defined (idkAM571x)
    Board_STATUS  boardStatus;
    Board_IDInfo  id;
#endif

    *instNum = UART_INSTANCE;
    *boardAM570x = false;

#if defined (idkAM571x)
    boardStatus = Board_getIDInfo(&id);
    if (boardStatus != BOARD_SOK)
    {
        return;
    }

    /* Check if is DRA (AM570x) SoC */
    if ((id.boardName[0] == 'D') &&
        (id.boardName[1] == 'R') &&
        (id.boardName[2] == 'A'))
    {
        *boardAM570x = true;
        *instNum = 0;
    }
#endif
}

bool Board_initUART(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    bool          boardAM570x;

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK;
#endif

    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        return (false);
    }

    UART_getTestInstNum(&uartTestInstance, &boardAM570x);

/* --- TODO: move this into the board library --- */
/* For SYSBIOS only */
#ifndef BAREMETAL 
#if defined (SOC_J721E)
/* set up C7x CLEC for DMTimer0 */
#if defined (BUILD_C7X_1)
    CSL_ClecEventConfig   cfgClec;
    CSL_CLEC_EVTRegs     *clecBaseAddr = (CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;
    uint32_t input         = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_TIMER0_INTR_PEND_0 + 992; /* Used for Timer Interrupt */

    /* Configure CLEC for DMTimer0, SYS/BIOS uses interrupt 14 for DMTimer0 by default */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = TRUE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_CPU_ALL;
    cfgClec.extEvtNum         = 0;
    cfgClec.c7xEvtNum         = 14;
    CSL_clecConfigEvent(clecBaseAddr, input, &cfgClec);
#endif /* for C7X cores */

/* set up C66x Interrupt Router for DMTimer0 for C66x */
#if defined (BUILD_DSP_1) || defined (BUILD_DSP_2)
    int32_t                               retVal;
    struct tisci_msg_rm_irq_set_req      rmIrqReq;
    struct tisci_msg_rm_irq_set_resp     rmIrqResp;
    int32_t                              dst_id;

#if defined (BUILD_DSP_1)
    dst_id = TISCI_DEV_C66SS0_CORE0;
#endif
#if defined (BUILD_DSP_2)
    dst_id = TISCI_DEV_C66SS1_CORE0;
#endif

    /* Set up C66x interrupt router for DMTimer0 */
    memset (&rmIrqReq, 0, sizeof(rmIrqReq));
    rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
    rmIrqReq.src_id = TISCI_DEV_TIMER0;
    rmIrqReq.src_index = 0; /* set to 0 for non-event based interrupt */

    /* Set the destination interrupt */
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

    /* Set the destination based on the core */
    rmIrqReq.dst_id       = dst_id;
/* rmIrqReq.dst_host_irq has to match the DMTimer.timerSettings[0].eventId defined in sysbios_c66.cfg */
#if defined (BUILD_DSP_1)
    rmIrqReq.dst_host_irq = 21; /* DMSC dest event, input to C66x INTC  */
#endif
#if defined (BUILD_DSP_2)
    rmIrqReq.dst_host_irq = 20; /* DMSC dest event, input to C66x INTC  */
#endif

    /* Config event */
    retVal = Sciclient_rmIrqSet(
                (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq,
                &rmIrqResp,
                SCICLIENT_SERVICE_WAIT_FOREVER);
    if(0U != retVal)
    {
       return (false);
    }
#endif /* for C66X cores */
#endif /* for SOC_J721E || SOC_J7200 */
#endif /* for SYSBIOS */
/* --- TODO: move this into the board library --- */
	
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
    CSL_l4per_cm_core_componentRegs *l4PerCmReg =
        (CSL_l4per_cm_core_componentRegs *) CSL_MPU_L4PER_CM_CORE_REGS;

    if (boardAM570x)
    {
#if defined (_TMS320C6X)
        UART_HwAttrs cfg;

        /*
         * AM5 DSP does not have a default Xbar connection for UART
         * interrupt, need the following Xbar interrupt configuration
         */

        /* Use reserved DSP1_IRQ_34 */
        CSL_xbarDspIrqConfigure(1,
                                CSL_XBAR_INST_DSP1_IRQ_34,
                                CSL_XBAR_UART1_IRQ);

        /* configure Xbar for UART2 instance */
        CSL_xbarDspIrqConfigure(1,
                                CSL_XBAR_INST_DSP1_IRQ_35,
                                CSL_XBAR_UART2_IRQ);
        UART_socGetInitCfg(uartTestInstance + 1, &cfg);
        cfg.eventId = 35;
        UART_socSetInitCfg(uartTestInstance + 1, &cfg);
#endif

#if defined(__TI_ARM_V7M4__)
        UART_HwAttrs cfg;

        /*
         * AM571/AM570 IPU does not have a default Xbar connection for UART 1
         * interrupt, need to use a reserved IRQ Xbar instance for Xbar interrupt
         * configuration
         */

        /* Use reserved XBAR_INST_IPU1_IRQ_24 */
        CSL_xbarIpuIrqConfigure(1,
                                CSL_XBAR_INST_IPU1_IRQ_24,
                                CSL_XBAR_UART1_IRQ);

        /* configure Xbar for UART2 instance */
        CSL_xbarIpuIrqConfigure(1,
                                CSL_XBAR_INST_IPU1_IRQ_25,
                                CSL_XBAR_UART2_IRQ);
        UART_socGetInitCfg(uartTestInstance + 1, &cfg);
        cfg.intNum = 25;
        UART_socSetInitCfg(uartTestInstance + 1, &cfg);
#endif

        /* enable UART2 clock */
        CSL_FINST(l4PerCmReg->CM_L4PER_UART2_CLKCTRL_REG,
                  L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE,
                  ENABLE);

        while(CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_FUNC !=
              CSL_FEXT(l4PerCmReg->CM_L4PER_UART2_CLKCTRL_REG,
              L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST));
    }
    else
    {
#if defined (_TMS320C6X)
        UART_HwAttrs cfg;

        CSL_xbarDspIrqConfigure(1,
                                CSL_XBAR_INST_DSP1_IRQ_34,
                                CSL_XBAR_UART3_IRQ);

        /* configure Xbar for UART4 instance */
        CSL_xbarDspIrqConfigure(1,
                                CSL_XBAR_INST_DSP1_IRQ_35,
                                CSL_XBAR_UART4_IRQ);
        UART_socGetInitCfg(uartTestInstance + 1, &cfg);
        cfg.eventId = 35;
        UART_socSetInitCfg(uartTestInstance + 1, &cfg);
#endif

#if defined(__TI_ARM_V7M4__)
        /*
         * AM57x IPU does not have a default Xbar connection for UART 4
         * interrupt, need to use a reserved IRQ Xbar instance for Xbar interrupt
         * configuration
         */
        /* Use reserved XBAR_INST_IPU1_IRQ_24 */
        CSL_xbarIpuIrqConfigure(1,
                                CSL_XBAR_INST_IPU1_IRQ_24,
                                CSL_XBAR_UART4_IRQ);
#endif

        /* enable UART4 clock */
        CSL_FINST(l4PerCmReg->CM_L4PER_UART4_CLKCTRL_REG,
                  L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE,
                  ENABLE);

        while(CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_FUNC !=
              CSL_FEXT(l4PerCmReg->CM_L4PER_UART4_CLKCTRL_REG,
              L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST));
    }
#endif

#if defined (SOC_AM335X) || defined (SOC_AM437X)
    /* enable UART clock */
    PRCMModuleEnable(42U, uartTestInstance + 1U, 0U);
#endif
    return (true);
}

/**
 *  @b Description
 *  @n
 *      Utility function which converts a local GEM L2 memory address
 *      to global memory address.
 *
 *  @param[in]  addr
 *      Local address to be converted
 *
 *  @retval
 *      Computed L2 global Address
 */
static uintptr_t l2_global_address (uintptr_t addr)
{
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || \
    defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_K2G) || defined(DEVICE_C6678) || defined(DEVICE_C6657)
#ifdef _TMS320C6X
    uint32_t corenum;

    /* Get the core number. */
    corenum = CSL_chipReadReg (CSL_CHIP_DNUM);

    /* Compute the global address. */
    return (addr + (0x10000000 + (corenum * 0x1000000)));
#else
    return addr;
#endif
#else
    return addr;
#endif

}

void UART_callback(UART_Handle handle, void *buf, size_t count)
{
    UART_osalPostLock(callbackSem);
}

void UART_callback2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_osalPostLock(callbackSem);
}

#define UART_NUM_TRIG_LVL           (4U)

/*
 *  ======== UART_initConfigTrgLvl ========
 */
static void UART_initConfigTrgLvl(uint32_t dmaMode,
                                  uint32_t txTrigLvl,
                                  uint32_t rxTrigLvl)
{
    UART_HwAttrs uart_cfg;

    /* Get the default UART init configurations */
    UART_socGetInitCfg(uartTestInstance, &uart_cfg);

#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) ||\
    defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_K2G) || defined(DEVICE_C6678) || defined(DEVICE_C6657) || defined(DEVICE_OMAPL137) || defined(DEVICE_OMAPL138)
    uart_cfg.txTrigLvl  = txTrigLvl;
#else
    uart_cfg.txTrigLvl  = (UART_TxTrigLvl)txTrigLvl;
#endif
    uart_cfg.rxTrigLvl  = (UART_RxTrigLvl)rxTrigLvl;
    uart_cfg.loopback   = TRUE;
#ifdef UART_DMA_ENABLE
    if (dmaMode == true)
    {
#if defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
        uart_cfg.edmaHandle = UartApp_udmaInit(&uart_cfg);
#else
        uart_cfg.edmaHandle = UartApp_edmaInit();
#endif
        uart_cfg.dmaMode    = TRUE;
    }
    else
#endif
    {
        uart_cfg.edmaHandle = NULL;
        uart_cfg.dmaMode    = FALSE;
    }

    /* Set the TX/RX FIFO trigger levels */
    UART_socSetInitCfg(uartTestInstance, &uart_cfg);
}

bool UART_test_trglvl_xfer(UART_Handle uart, uint32_t dmaMode, uint32_t xferSize)
{
    SemaphoreP_Params semParams;
    UART_Transaction  transaction;
    uintptr_t          addrFifoTrgLvlData, addrScanPrompt;
    uint32_t          i;
    bool              ret = false;

    if (xferSize == 0)
    {
        return true;
    }
    /* Create call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    callbackSem = UART_osalCreateBlockingLock(0, &semParams);

    if (dmaMode)
    {
        addrFifoTrgLvlData = l2_global_address((uintptr_t)fifoTrgLvlData);
        addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    }
    else
    {
        addrFifoTrgLvlData = (uintptr_t)fifoTrgLvlData;
        addrScanPrompt = (uintptr_t)scanPrompt;
    }

    /* Read in call back mode */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
        CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = xferSize;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Write in blocking mode */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrFifoTrgLvlData;
    transaction.count = xferSize;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Wait for read callback */
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    /* Check if read data matches with write data */
    for (i = 0; i < xferSize; i++)
    {
        if (scanPrompt[i] != fifoTrgLvlData[i])
        {
            goto Err;
        }
    }
    ret = true;

Err:
    if (callbackSem)
    {
	    UART_osalDeleteBlockingLock(callbackSem);
	    callbackSem = NULL;
    }
    return (ret);
}

bool UART_test_trglvl(uint32_t dmaMode,
                      int32_t txTrigLvl,
                      int32_t rxTrigLvl)
{
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    bool              ret = false;
    int32_t           i;

    /* UART SoC init configuration */
    UART_initConfigTrgLvl(dmaMode, (uint32_t)(uintptr_t)txTrigLvl, (uint32_t)(uintptr_t)rxTrigLvl);

    /* Read in callback mode and write in blocking mode */
    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    for ( i = -1; i < 2; i++)
    {
        uart = UART_open(uartTestInstance, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }
        if (UART_test_trglvl_xfer(uart, dmaMode, (uint32_t)(uintptr_t)(txTrigLvl + i)) == false)
        {
            goto Err;
        }
        if (uart)
        {
            UART_close(uart);
            uart = NULL;
        }

        uart = UART_open(uartTestInstance, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        if (UART_test_trglvl_xfer(uart, dmaMode, (uint32_t)(uintptr_t)(rxTrigLvl + i)) == false)
        {
            goto Err;
        }

        if (uart)
        {
            UART_close(uart);
            uart = NULL;
        }
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }
    return (ret);
}

/*
 *  ======== UART DMA TX/RX FIFO trigger level test ========
 */
static bool UART_test_fifo_trglvl(bool dmaMode)
{
    bool     ret = true;
    uint32_t i;
#if defined(SOC_AM574x) || defined(SOC_AM572x)|| defined(SOC_AM571x) || defined (SOC_DRA72x)  || defined (SOC_DRA75x) || defined (SOC_DRA78x) || defined (SOC_AM335X) || defined (SOC_AM437X) || defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
    UART_TxTrigLvl txTrgLvl[UART_NUM_TRIG_LVL] =
    {
        UART_TXTRIGLVL_8,
        UART_TXTRIGLVL_16,
        UART_TXTRIGLVL_32,
        UART_TXTRIGLVL_56
    };

    UART_RxTrigLvl rxTrgLvl[UART_NUM_TRIG_LVL] =
    {
        UART_RXTRIGLVL_8,
        UART_RXTRIGLVL_16,
        UART_RXTRIGLVL_56,
        UART_RXTRIGLVL_60
    };
#else
    uint32_t txTrgLvl[UART_NUM_TRIG_LVL] =
    {
        2,
        4,
        8,
        16
    };

    UART_RxTrigLvl rxTrgLvl[UART_NUM_TRIG_LVL] =
    {
        UART_RXTRIGLVL_1,
        UART_RXTRIGLVL_4,
        UART_RXTRIGLVL_8,
        UART_RXTRIGLVL_14
    };
#endif
    for (i = 0; i < UART_NUM_TRIG_LVL; i++)
    {
        if (UART_test_trglvl(dmaMode, (int32_t)txTrgLvl[i], (int32_t)rxTrgLvl[i]) == false)
        {
            ret = false;
            break;
        }
    }

    return (ret);
}

/*
 *  ======== UART stdio printf/scanf test ========
 *
 *  The test function tests stdio driver printf/scanf APIs
 */
static bool UART_test_printf_scanf(bool dmaMode)
{
    bool    ret = false;

    if (uartParity == UART_PAR_NONE)
    {
        /* UART SoC init configuration */
        UART_initConfig(dmaMode);

        UART_stdioInit(uartTestInstance);

        UART_printf(stdioPrint);

        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_scanFmt(scanPrompt) != S_PASS)
        {
            goto Err;
        }

        ret = true;

Err:
        UART_stdioDeInit();
    }
    else
    {
        /*
         * bypass this test if the parity is not the default setting
         * (UART_PAR_NONE), since UART_stdioInit() only allows default
         * UART parameter settings.
         */
        ret = true;
    }

    return (ret);
}

/*
 *  ======== UART stdio printf/scanf test with param config (default) ========
 *
 *  The test function tests stdio driver printf/scanf APIs with default params config.
 */
static bool UART_test_printf_scanf_stdio_params(bool dmaMode)
{
    bool    ret = false;
    UART_Params params;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* UART params */
    UART_Params_init(&params);
    params.parityType = uartParity;

    UART_stdioInit2(uartTestInstance,&params);

    UART_printf(stdioPrint);

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (UART_scanFmt(scanPrompt) != S_PASS)
    {
        goto Err;
    }

    ret = true;

Err:
    UART_stdioDeInit();
    return (ret);
}

#ifdef USE_BIOS
/* Use a global variable to sync the read task and the write task */
volatile bool taskSyncFlag;
Void UART_simultaneous_rw_write(UArg a0, UArg a1)
{
	UART_Handle      uart = (UART_Handle)a0;
	bool             dmaMode = (bool)a1;
    uintptr_t         addrDataPrint;
    UART_Transaction transaction;

	if (dmaMode)
    {
    	addrDataPrint = l2_global_address((uintptr_t)dataPrint);
    }
    else
    {
    	addrDataPrint = (uintptr_t)dataPrint;
    }

    UART_transactionInit(&transaction);

    while (taskSyncFlag == true)
	{
        transaction.buf = (void *)(uintptr_t)addrDataPrint;
	    transaction.count = sizeof(dataPrint);
	    UART_write2(uart, &transaction);
	    Osal_delay(100);
	}

    /* resume the read test task */
    taskSyncFlag = true;

    Task_exit ();
}

/*
 *  ======== UART simultaneous read/write test ========
 *
 *  The read task creates a write task which will continuously
 *  writes the data out to the console, while at the same time
 *  the read task reads the data from the console input.
 *
 *  Note:
 *  In blocking/interrupt mode, if the write size is less than
 *  the TX FIFO size (64 bytes), the driver will just copy
 *  the write data to the TX FIFO and will not use interrupt
 *  and write semaphore. The read task should have a higher
 *  priority than the write task to resume the task by the
 *  scheduler once it gets the read semaphore.
 *
 */
static bool UART_test_simultaneous_rw(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    uintptr_t         addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    Task_Handle      writeTask;
    Task_Params      writeTaskParams;
    Error_Block      eb;
    bool             ret = false;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* run the write teas when task is created */
    taskSyncFlag = true;

    Error_init(&eb);

    /* Initialize the task params */
    Task_Params_init(&writeTaskParams);
    writeTaskParams.arg0 = (UArg)uart;
    writeTaskParams.arg1 = (UArg)dmaMode;
#if defined (__C7100__)
    writeTaskParams.stackSize = 1024*16;
#else
    writeTaskParams.stackSize = 1024*8;
#endif
    /*
     * Set the write task priority to the default priority (1)
     * lower than the read task priority (2)
     */
    writeTaskParams.priority = 1;

    /* Create the UART write task */
    writeTask = Task_create((Task_FuncPtr)UART_simultaneous_rw_write, &writeTaskParams, &eb);
    if (writeTask == NULL)
    {
        System_abort("Task create failed");
        goto Err;
    }

    if (dmaMode)
    {
        addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
        addrEchoPrompt = l2_global_address((uintptr_t)echoPrompt);
    }
    else
    {
    	addrScanPrompt = (uintptr_t)scanPrompt;
        addrEchoPrompt = (uintptr_t)echoPrompt;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
    	taskSyncFlag = false;
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
    	taskSyncFlag = false;
        goto Err;
    }

    /* stop the write test task */
    taskSyncFlag = false;

    /* Wait for the write task complete and exit */
    while (taskSyncFlag == false)
    {
        Osal_delay(100);
    }
    taskSyncFlag = false;

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = sizeof(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    Osal_delay(5000);

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}
#endif

/*
 *  ======== UART read cancel test ========
 *
 *  The test function uses console intput to simulate/test the
 *  read cancel in callback mode. In a real use case, user can
 *  read a large file from the console and cancel the read before
 *  the read is complete.
 *
 */
static bool UART_test_read_write_cancel(bool dmaMode)
{
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    SemaphoreP_Params semParams;
    UART_Transaction  transaction;
    uintptr_t          addrRdCancelPrompt, addrWrCancelPrompt;
    uintptr_t          addrDataPrint, addrEchoPrompt, addrScanPrompt;
    bool              ret = false;

    /* Create call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    callbackSem = UART_osalCreateBlockingLock(0, &semParams);

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Set callback mode for read */
    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    if (dmaMode)
    {
    	addrRdCancelPrompt = l2_global_address((uintptr_t)rdCancelPrompt);
    	addrDataPrint = l2_global_address((uintptr_t)dataPrint);
    	addrEchoPrompt = l2_global_address((uintptr_t)echoPrompt);
    	addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    }
    else
    {
    	addrRdCancelPrompt = (uintptr_t)rdCancelPrompt;
    	addrDataPrint = (uintptr_t)dataPrint;
    	addrEchoPrompt = (uintptr_t)echoPrompt;
    	addrScanPrompt = (uintptr_t)scanPrompt;
    }

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test receive error */

    /* Perform the first read, which will be cancelled before completion */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Delay for 10 seconds to allow user to enter chars */
    Osal_delay(10000);

    /* Cancel the read before the read transfer is completed */
    UART_readCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    /* Print read cancelled prompt */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrRdCancelPrompt;
    transaction.count = sizeof(rdCancelPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = sizeof(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Perform the 2nd read, which will be completed */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = sizeof(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    /* Print the 2nd read chars, should NOT contain any chars
     * in the first cancelled read
     */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = sizeof(scanPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    UART_close(uart);

    /* write cancel test */

    /* Set callback mode for write */
    UART_Params_init(&uartParams);
    uartParams.writeCallback = UART_callback;
    uartParams.writeMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    if (dmaMode)
    {
        addrWrCancelPrompt = l2_global_address((uintptr_t)wrCancelPrompt);
    }
    else
    {
        addrWrCancelPrompt = (uintptr_t)wrCancelPrompt;
    }

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Perform the 1st write */
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrWrCancelPrompt;
    callbackTransaction.count = sizeof(wrCancelPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Cancel the 1st write */
    UART_writeCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    /* Perform the 2nd write */
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrWrCancelPrompt;
    callbackTransaction.count = sizeof(wrCancelPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    /* Cancel the write */
    UART_writeCancel(uart);
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }
    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    if (callbackSem)
    {
    	UART_osalDeleteBlockingLock(callbackSem);
    	callbackSem = NULL;
    }
    return (ret);
}

/*
 *  ======== UART receive error test ========
 *
 *  The test function tests receive error (e.g. break condition)
 */
static bool UART_test_rx_err(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    UART_Transaction transaction;
    uintptr_t         addrScanPrompt, addrBreakErrPrompt;
    bool             ret = false;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    if (dmaMode)
    {
    	addrBreakErrPrompt = l2_global_address((uintptr_t)breakErrPrompt);
    	addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    }
    else
    {
    	addrBreakErrPrompt = (uintptr_t)breakErrPrompt;
    	addrScanPrompt = (uintptr_t)scanPrompt;
    }

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test receive error */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
    	if (transaction.status == UART_TRANSFER_STATUS_ERROR_BI)
    	{
    	    UART_transactionInit(&transaction);
            transaction.buf = (void *)(uintptr_t)addrBreakErrPrompt;
            transaction.count = sizeof(breakErrPrompt);
            if (UART_write2(uart, &transaction) == UART_ERROR)
            {
                goto Err;
            }
    	}
    	else
        {
            goto Err;
        }
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART timeout test ========
 *
 *  The test function tests read/write with OS timeout
 */
static bool UART_test_timeout(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    UART_Transaction transaction;
    uintptr_t         addrScanPrompt, addrReadTimeoutPrompt;
    bool             ret = false;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    if (dmaMode)
    {
    	addrReadTimeoutPrompt = l2_global_address((uintptr_t)readTimeoutPrompt);
    	addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    }
    else
    {
    	addrReadTimeoutPrompt = (uintptr_t)readTimeoutPrompt;
    	addrScanPrompt = (uintptr_t)scanPrompt;
    }

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read timeout */
    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)scanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    transaction.timeout = UART_TEST_TIMEOUT;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        UART_transactionInit(&transaction);
        transaction.buf = (void *)(uintptr_t)addrReadTimeoutPrompt;
        transaction.count = sizeof(readTimeoutPrompt);
        transaction.timeout = UART_TEST_TIMEOUT;
        if (UART_write2(uart, &transaction) == UART_ERROR)
        {
            goto Err;
        }
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART polling timeout test ========
 *
 *  The test function tests read/write with OS timeout in polling mode
 */
static bool UART_test_polling_timeout(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    bool             ret = false;
    uint32_t         rdSize = UART_TEST_READ_LEN;
    uint32_t         wrSize = sizeof(readTimeoutPrompt);

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    /* timeout is 0 for both read and write */
    uartParams.readTimeout  = UART_NO_WAIT;
    uartParams.writeTimeout = UART_NO_WAIT;
    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
    {
        if (UART_writePolling(uart, (const void *)readTimeoutPrompt, wrSize) != wrSize)
        {
            ret = true;
        }
    }

    if (ret == true)
    {
        ret = false;

        UART_close(uart);

        /* timeout is 5 seconds for both read and write */
        uartParams.readTimeout  = UART_TEST_TIMEOUT;
        uartParams.writeTimeout = UART_TEST_TIMEOUT;
        uart = UART_open(uartTestInstance, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        /* Test read timeout */
        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
        {
            UART_writePolling(uart, (const void *)readTimeoutPrompt, wrSize);
            ret = true;
        }
    }

    if (ret == true)
    {
        ret = false;

        UART_close(uart);

        /* timeout is 5 seconds for both read and write */
        uartParams.readTimeout  = UART_WAIT_FOREVER;
        uartParams.writeTimeout = UART_WAIT_FOREVER;
        uart = UART_open(uartTestInstance, &uartParams);
        if (uart == NULL)
        {
            goto Err;
        }

        wrSize = sizeof(dataPrint);
        UART_writePolling(uart, (const void *)dataPrint, wrSize);

        memset(scanPrompt, 0, sizeof(scanPrompt));
        if (UART_readPolling(uart, (void *)(uintptr_t)scanPrompt, rdSize) != rdSize)
        {
            goto Err;
        }

        wrSize = sizeof(echoPrompt);
        UART_writePolling(uart, (const void *)echoPrompt, wrSize);
        UART_writePolling(uart, (const void *)scanPrompt, rdSize);

        ret = true;
    }

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}

/*
 *  ======== UART callback test ========
 *
 *  The test function tests the read/write in callback mode
 */
static bool UART_test_callback(bool dmaMode)
{
    UART_Handle       uart = NULL;
    UART_Params       uartParams;
    SemaphoreP_Params semParams;
    uintptr_t          addrScanPrompt, addrDataPrint, addrEchoPrompt;
    bool              ret = false;

    /* Create call back semaphore */
    UART_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    callbackSem = UART_osalCreateBlockingLock(0, &semParams);

    /* Test read/write API's in callback mode */

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Set callback mode for both read and write */
    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.writeCallback = UART_callback;
    uartParams.writeMode = UART_MODE_CALLBACK;
    uartParams.parityType = uartParity;

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    if (dmaMode)
    {
    	addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    	addrDataPrint = l2_global_address((uintptr_t)dataPrint);
    	addrEchoPrompt = l2_global_address((uintptr_t)echoPrompt);
    }
    else
    {
    	addrScanPrompt = (uintptr_t)scanPrompt;
    	addrDataPrint = (uintptr_t)dataPrint;
    	addrEchoPrompt = (uintptr_t)echoPrompt;
    }

    /* Write DMA or non-DMA test prompt */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, sizeof(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }

    if (UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.readTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, sizeof(echoPrompt)) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, uartParams.writeTimeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_close(uart);

    /* Test read2/write2 API's in callback mode */

    uartParams.readCallback2 = UART_callback2;
    uartParams.writeCallback2 = UART_callback2;
    uartParams.readCallback = NULL;
    uartParams.writeCallback = NULL;

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrDataPrint;
    callbackTransaction.count = sizeof(dataPrint);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    callbackTransaction.count = sizeof(echoPrompt);
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    UART_transactionInit(&callbackTransaction);
    callbackTransaction.buf = (void *)(uintptr_t)addrScanPrompt;
    callbackTransaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &callbackTransaction) == UART_ERROR)
    {
        goto Err;
    }
    if (UART_osalPendLock(callbackSem, callbackTransaction.timeout) != SemaphoreP_OK)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }
    if (callbackSem)
    {
    	UART_osalDeleteBlockingLock(callbackSem);
    	callbackSem = NULL;
    }
    return (ret);
}

/*
 *  ========== UART read API test ==========
 *
 *  The test function for UART_read API
 *  in loopback mode
 */
static bool UART_test_read_verify(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    int16_t          length = 0;
    bool             ret = false;
    uint8_t rBuff[UART_TEST_READ_LEN], tBuff[]="aaaabbbbccccddddeeee";

    verifyLoopback = 1;
    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    uart = UART_open(uartTestInstance, &uartParams);

    if (uart == NULL)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)&tBuff[0], UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }

    length = UART_read(uart, (void *)&rBuff[0], UART_RDVERIFY_READ_LEN);

    if (UART_write(uart, (void *)&tBuff[15], UART_RDVERIFY_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }

    length = UART_read(uart, (void *)&rBuff[4], UART_RDVERIFY_READ_LEN);
    length = UART_read(uart, (void *)&rBuff[8], UART_RDVERIFY_READ_LEN);
    length = UART_read(uart, (void *)&rBuff[12], UART_RDVERIFY_READ_LEN);

    ret = true;
    for(length=0; length<UART_TEST_READ_LEN; length++)
    {
        if(tBuff[length] != rBuff[length])
        {
            ret = false;
            break;
        }
    }
    UART_close(uart);

    /* stop bit loopback test */
    UART_Params_init(&uartParams);
    uartParams.stopBits = UART_STOP_TWO;
    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)&tBuff[0], UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }

    memset(rBuff, 0, UART_TEST_READ_LEN);
    UART_read(uart, (void *)&rBuff[0], UART_TEST_READ_LEN);
    for(length=0; length<UART_TEST_READ_LEN; length++)
    {
        if(tBuff[length] != rBuff[length])
        {
            ret = false;
            break;
        }
    }
    UART_close(uart);

    /* char length loopback test */
    UART_Params_init(&uartParams);
    uartParams.dataLength = UART_LEN_5;
    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)&tBuff[0], UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }

    memset(rBuff, 0, UART_TEST_READ_LEN);
    UART_read(uart, (void *)&rBuff[0], UART_TEST_READ_LEN);
    for(length=0; length<UART_TEST_READ_LEN; length++)
    {
        if ((tBuff[length] & ((1 << (uartParams.dataLength + 5)) - 1)) != rBuff[length])
        {
            ret = false;
            break;
        }
    }
    UART_close(uart);

    /* parity loopback test */
    UART_Params_init(&uartParams);
    uartParams.parityType = UART_PAR_EVEN;
    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    if (UART_write(uart, (void *)&tBuff[0], UART_TEST_READ_LEN) == UART_ERROR)
    {
        goto Err;
    }

    memset(rBuff, 0, UART_TEST_READ_LEN);
    UART_read(uart, (void *)&rBuff[0], UART_TEST_READ_LEN);
    for(length=0; length<UART_TEST_READ_LEN; length++)
    {
        if(tBuff[length] != rBuff[length])
        {
            ret = false;
            break;
        }
    }
    UART_close(uart);

Err:
    if (uart == NULL)
    {
        verifyLoopback = 0;
        UART_close(uart);
    }

    verifyLoopback = 0;
    return (ret);
}

/*
 *  ======== UART read/write test ========
 *
 *  The test function tests read/write in blocking mode
 */
static bool UART_test_read_write(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    int              length = 0;
    uintptr_t         addrDataPrint, addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    bool             ret = false;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    uart = UART_open(uartTestInstance, &uartParams);

    if (uart == NULL)
    {
        goto Err;
    }

    if (dmaMode)
    {
    	addrDataPrint = l2_global_address((uintptr_t)dataPrint);
    	addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
    	addrEchoPrompt = l2_global_address((uintptr_t)echoPrompt);
    }
    else
    {
    	addrDataPrint = (uintptr_t)dataPrint;
    	addrScanPrompt = (uintptr_t)scanPrompt;
    	addrEchoPrompt = (uintptr_t)echoPrompt;
    }

    /* Test read/write API's in blocking mode */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, sizeof(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    length = UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN);
    if (length != UART_TEST_READ_LEN)
    {
    	goto Err;
    }

    UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, sizeof(echoPrompt));

    UART_write(uart, (void *)(uintptr_t)addrScanPrompt, length);
    UART_close(uart);

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read2/write2 API's in blocking mode */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = sizeof(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
    	CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = sizeof(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    return (ret);
}


/*
 *  ======== UART read/write test with interrupt disabled ========
 *
 *  The test function tests read/write with interrupt disabled
 */
static bool UART_test_read_write_int_disable(bool dmaMode)
{
    UART_Handle      uart = NULL;
    UART_Params      uartParams;
    int              length = 0;
    uintptr_t         addrDataPrint, addrScanPrompt, addrEchoPrompt;
    UART_Transaction transaction;
    bool             ret = false;
    UART_HwAttrs uart_cfg;

    /* UART SoC init configuration */
    UART_initConfig(dmaMode);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;

    /* Get the default UART init configurations */
    UART_socGetInitCfg(uartTestInstance, &uart_cfg);

    uart_cfg.enableInterrupt=0; /* Disabling interrupt forcefully */

    /* Get the default UART init configurations */
    UART_socSetInitCfg(uartTestInstance, &uart_cfg);

    uart = UART_open(uartTestInstance, &uartParams);

    if (uart == NULL)
    {
        goto Err;
    }

    if (dmaMode)
    {
        addrDataPrint = l2_global_address((uintptr_t)dataPrint);
        addrScanPrompt = l2_global_address((uintptr_t)scanPrompt);
        addrEchoPrompt = l2_global_address((uintptr_t)echoPrompt);
    }
    else
    {
        addrDataPrint = (uintptr_t)dataPrint;
        addrScanPrompt = (uintptr_t)scanPrompt;
        addrEchoPrompt = (uintptr_t)echoPrompt;
    }

    /* Test read/write API's in blocking mode */
    if (UART_write(uart, (void *)(uintptr_t)addrDataPrint, sizeof(dataPrint)) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
        CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    length = UART_read(uart, (void *)(uintptr_t)addrScanPrompt, UART_TEST_READ_LEN);
    if (length != UART_TEST_READ_LEN)
    {
        goto Err;
    }

    UART_write(uart, (void *)(uintptr_t)addrEchoPrompt, sizeof(echoPrompt));

    UART_write(uart, (void *)(uintptr_t)addrScanPrompt, length);
    UART_close(uart);

    uart = UART_open(uartTestInstance, &uartParams);
    if (uart == NULL)
    {
        goto Err;
    }

    /* Test read2/write2 API's in blocking mode */
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrDataPrint;
    transaction.count = sizeof(dataPrint);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    memset(scanPrompt, 0, sizeof(scanPrompt));
    if (dmaMode)
    {
        CacheP_wbInv((void *)(uintptr_t)addrScanPrompt, (int32_t)sizeof(scanPrompt));
    }
    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_read2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }
    if ((transaction.status != UART_TRANSFER_STATUS_SUCCESS) ||
        (transaction.count != UART_TEST_READ_LEN))
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrEchoPrompt;
    transaction.count = sizeof(echoPrompt);
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    UART_transactionInit(&transaction);
    transaction.buf = (void *)(uintptr_t)addrScanPrompt;
    transaction.count = UART_TEST_READ_LEN;
    if (UART_write2(uart, &transaction) == UART_ERROR)
    {
        goto Err;
    }

    ret = true;

Err:
    if (uart)
    {
        UART_close(uart);
    }

    /* Get the default UART init configurations */
    UART_socGetInitCfg(uartTestInstance, &uart_cfg);
    uart_cfg.enableInterrupt=1; /* Re-enabling interrupt for the remaining the tests */
    /* Get the default UART init configurations */
    UART_socSetInitCfg(uartTestInstance, &uart_cfg);

    return (ret);
}

#ifdef UART_DMA_ENABLE
static uint32_t UART_getMaxNumInst(uint32_t numInst)
{
    uint32_t     i = 0;
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x) || defined (SOC_AM335X) || defined (SOC_AM437X)
    UART_HwAttrs uart_cfg;

    for (i = 0; i < numInst; i++)
    {
        memset(&uart_cfg, 0, sizeof(UART_HwAttrs));
        UART_socGetInitCfg(i, &uart_cfg);

        if (uart_cfg.baseAddr == 0)
        {
            break;
        }
    }
#endif
    return (i);
}

SemaphoreP_Handle MiCbSem[UART_TEST_NUM_INSTS] = {NULL, };
UART_Handle       MiUartHandle[UART_TEST_NUM_INSTS] = {NULL, };
void UART_miCallback(UART_Handle handle, void *buf, size_t count)
{
    uint32_t i;

    for (i = 0; i < UART_TEST_NUM_INSTS; i++)
    {
        if (MiUartHandle[i] == handle)
        {
            UART_osalPostLock(MiCbSem[i]);
            break;
        }
    }
}

/*
 *  ========== UART multiple instances test ==========
 *
 *  The test function for UART read/write on multiple instances
 *  in loopback mode
 */
#if (defined(_TMS320C6X) || defined (__TI_ARM_V7M4__))
#pragma DATA_ALIGN (MiRxBuf, UART_TEST_CACHE_LINE_SIZE)
char MiRxBuf[UART_TEST_NUM_INSTS][UART_TEST_CACHE_LINE_SIZE];
#pragma DATA_ALIGN (MiTxBuf, UART_TEST_CACHE_LINE_SIZE)
char MiTxBuf[UART_TEST_CACHE_LINE_SIZE];
#else
char MiRxBuf[UART_TEST_NUM_INSTS][UART_TEST_CACHE_LINE_SIZE] __attribute__ ((aligned (UART_TEST_CACHE_LINE_SIZE)));
char MiTxBuf[UART_TEST_CACHE_LINE_SIZE] __attribute__ ((aligned (UART_TEST_CACHE_LINE_SIZE)));
#endif
static bool UART_test_multiple_instances(bool dmaMode)
{
    UART_Params       uartParams;
    bool              ret = false;
    uint32_t          i, j;
    uintptr_t          bufAddr;
    uint32_t          uartTestStartInst = uartTestInstance;
    uint32_t          numUartTestInstances;
    SemaphoreP_Params semParams;

    /* enable the loopback */
    verifyLoopback = 1;

    /* Get the max number of instances for testing */
    numUartTestInstances = UART_getMaxNumInst(UART_TEST_NUM_INSTS);

    for (i = 0; i < numUartTestInstances; i++)
    {
        /* UART SoC init configuration */
        UART_initConfig(dmaMode);

        /* Create call back semaphores */
        UART_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        MiCbSem[i] = UART_osalCreateBlockingLock(0, &semParams);

        /* Set callback mode for read */
        UART_Params_init(&uartParams);
        uartParams.readCallback = UART_miCallback;
        uartParams.readMode = UART_MODE_CALLBACK;
        uartParams.parityType = uartParity;

        MiUartHandle[i] = UART_open(uartTestInstance, &uartParams);
        if (MiUartHandle[i] == NULL)
        {
            goto Err;
        }
        uartTestInstance++;
    }

    for (i = 0; i < numUartTestInstances; i++)
    {
        memset(MiRxBuf[i], 0, UART_TEST_CACHE_LINE_SIZE);
        if (dmaMode)
        {
            bufAddr = l2_global_address((uintptr_t)MiRxBuf[i]);
            CacheP_wbInv((void *)(uintptr_t)bufAddr, UART_TEST_CACHE_LINE_SIZE);
        }
        else
        {
            bufAddr = (uintptr_t)MiRxBuf[i];
        }

        UART_read(MiUartHandle[i], (void *)(uintptr_t)bufAddr, UART_TEST_READ_LEN);
    }

    for (i = 0; i < numUartTestInstances; i++)
    {
        for (j = 0; j < UART_TEST_READ_LEN; j++)
        {
            MiTxBuf[j] = fifoTrgLvlData[j] + (char)i;
        }
        if (dmaMode)
        {
            bufAddr = l2_global_address((uintptr_t)MiTxBuf);
            CacheP_wbInv((void *)(uintptr_t)bufAddr, UART_TEST_CACHE_LINE_SIZE);
        }
        else
        {
            bufAddr = (uintptr_t)MiTxBuf;
        }

        if (UART_write(MiUartHandle[i], (void *)(uintptr_t)bufAddr, UART_TEST_READ_LEN) == UART_ERROR)
        {
            goto Err;
        }
    }

    /* add delay for the read semaphore calback */
    Osal_delay(100);

    for (i = 0; i < numUartTestInstances; i++)
    {
        for (j = 0; j < UART_TEST_READ_LEN; j++)
        {
            if ((fifoTrgLvlData[j] + (char)i) != MiRxBuf[i][j])
            {
                goto Err;
            }
        }
    }

    ret = true;

Err:
    for (i = 0; i < numUartTestInstances; i++)
    {
        if (MiUartHandle[i] != NULL)
        {
            UART_close(MiUartHandle[i]);
            MiUartHandle[i] = NULL;
        }
    }

    verifyLoopback = 0;
    uartTestInstance = uartTestStartInst;
    return (ret);
}
#endif

UART_Tests Uart_tests[] =
{
#ifdef UART_DMA_ENABLE
    {UART_test_read_write, true, UART_TEST_ID_DMA, "\r\n UART DMA read write test in block mode"},
#endif
    {UART_test_read_write, false, UART_TEST_ID_INT, "\r\n UART non-DMA read write test in block mode"},
#ifdef UART_DMA_ENABLE
    {UART_test_callback, true, UART_TEST_ID_DMA_CB, "\r\n UART DMA read write test in callback mode"},
#endif
    {UART_test_callback, false, UART_TEST_ID_CB, "\r\n UART non-DMA read write test in callback mode"},
#ifdef UART_DMA_ENABLE
    {UART_test_timeout, true, UART_TEST_ID_DMA_TO, "\r\n UART DMA timeout test, wait for 10 seconds to timeout read"},
#endif
    {UART_test_timeout, false, UART_TEST_ID_TO, "\r\n UART non-DMA timeout test, wait for 10 seconds to timeout read"},
#ifdef UART_DMA_ENABLE
    {UART_test_rx_err, true, UART_TEST_ID_DMA_RXERR, "\r\n UART DMA RX error test, enter a break"},
#endif
    {UART_test_rx_err, false, UART_TEST_ID_RXERR, "\r\n UART non-DMA RX error test, enter a break"},
#ifdef UART_DMA_ENABLE
    {UART_test_read_write_cancel, true, UART_TEST_ID_DMA_CANCEL, "\r\n UART DMA read write cancel test, enter less than 16 chars"},
#endif
    {UART_test_read_write_cancel, false, UART_TEST_ID_CANCEL, "\r\n UART non-DMA read write cancel test, enter less than 16 chars"},
#ifdef USE_BIOS
#ifdef UART_DMA_ENABLE
    {UART_test_simultaneous_rw, true, UART_TEST_ID_DMA_RW, "\r\n UART DMA simultaneous read write test "},
#endif
    {UART_test_simultaneous_rw, false, UART_TEST_ID_RW, "\r\n UART non-DMA simultaneous read write test "},
#endif
#ifdef UART_DMA_ENABLE
    {UART_test_fifo_trglvl, true, UART_TEST_ID_DMA_TRGLVL, "\r\n UART DMA TX/RX FIFO trigger level test "},
#endif
    {UART_test_printf_scanf, false, UART_TEST_ID_PRINTF, "\r\n UART stdio printf and scanf test "},
    {UART_test_fifo_trglvl, false, UART_TEST_ID_TRGLVL, "\r\n UART non-DMA TX/RX FIFO trigger level test "},
    {UART_test_polling_timeout, false, UART_TEST_ID_POLL_TO, "\r\n UART polling timeout test, wait for 10 seconds to timeout read"},
    {UART_test_printf_scanf_stdio_params, false, UART_TEST_ID_STDIOPARAMS, "\r\n UART stdio printf and scanf test with STDIO params(Default) "},
    {UART_test_read_write_int_disable, false, UART_TEST_ID_INT_DISABLE, "\r\n UART read write test with interrupt disabled"},
    {UART_test_read_verify, false, UART_TEST_ID_RDVERIFY, "\r\n UART non-DMA read API test in loopback mode"},
#ifdef UART_DMA_ENABLE
    {UART_test_multiple_instances, true, UART_TEST_ID_MULTI_INSTS, "\r\n UART DMA multiple instances loopback test "},
#endif
    {NULL, }
};

void UART_test_print_test_desc(UART_Tests *test)
{
    UART_Handle uart = NULL;
    UART_Params uartParams;
    char        testIdPrompt[16] = "\r\n UART UT ";
	char        crPrompt[16] = "\r\n";
    char        testId[16] = {0, };

    /* UART SoC init configuration */
    UART_initConfig(false);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;
    uart = UART_open(uartTestInstance, &uartParams);

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
    UART_write(uart, (void *)(uintptr_t)crPrompt, sizeof(crPrompt));
    UART_write(uart, (void *)(uintptr_t)testIdPrompt, sizeof(testIdPrompt));
    UART_write(uart, (void *)(uintptr_t)testId, sizeof(testId));
    UART_write(uart, (void *)(uintptr_t)crPrompt, sizeof(crPrompt));

    /* Print test description */
    UART_write(uart, (void *)(uintptr_t)test->testDesc, sizeof(test->testDesc));
    UART_write(uart, (void *)(uintptr_t)crPrompt, sizeof(crPrompt));

    UART_close(uart);
}

void UART_test_print_test_result(UART_Tests *test, bool pass)
{
    UART_Handle uart = NULL;
    UART_Params uartParams;
    char        testIdPrompt[16] = "\r\n UART UT ";
    char        crPrompt[16] = "\r\n";
    char        testId[16] = {0, };
    char        resultPass[16] = " PASSED";
    char        resultFail[16] = " FAILED";

    /* UART SoC init configuration */
    UART_initConfig(false);

    /* Initialize the default configuration params. */
    UART_Params_init(&uartParams);
    uartParams.parityType = uartParity;
    uart = UART_open(uartTestInstance, &uartParams);

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
    UART_write(uart, (void *)(uintptr_t)crPrompt, sizeof(crPrompt));
    UART_write(uart, (void *)(uintptr_t)testIdPrompt, sizeof(testIdPrompt));
    UART_write(uart, (void *)(uintptr_t)testId, sizeof(testId));
    if (pass == true)
    {
        UART_write(uart, (void *)(uintptr_t)resultPass, sizeof(resultPass));
    }
    else
    {
        UART_write(uart, (void *)(uintptr_t)resultFail, sizeof(resultFail));
    }

    UART_write(uart, (void *)(uintptr_t)crPrompt, sizeof(crPrompt));

    UART_close(uart);
}

void UART_test_print_test_results(bool pass)
{
    const char  resultPass[32] = "\r\n All tests have passed. \r\n";
    const char  resultFail[32] = "\r\n Some tests have failed. \r\n";

    /* UART SoC init configuration */
    UART_initConfig(false);

    UART_stdioInit(uartTestInstance);

    if (pass == true)
    {
        UART_printStatus(resultPass);
    }
    else
    {
        UART_printStatus(resultFail);
    }

    UART_stdioDeInit();
}

#ifdef USE_BIOS
/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
#else
int main(void)
#endif /* #ifdef USE_BIOS */
{
    bool testResult = false;
    uint32_t i;

#ifndef USE_BIOS
    if (Board_initUART() == false)
    {
        return(0);
    }
#endif

    UART_init();

    for (i = 0; ; i++)
    {
        if (Uart_tests[i].testFunc == NULL)
        {
            break;
        }
        UART_test_print_test_desc(&Uart_tests[i]);
        testResult = Uart_tests[i].testFunc(Uart_tests[i].dmaMode);
        UART_test_print_test_result(&Uart_tests[i], testResult);

        if (testResult == false)
        {
            break;
        }
    }

    UART_test_print_test_results(testResult);

    while (1)
    {
    }
}

#ifdef USE_BIOS
/*
 *  ======== main ========
 */
Int main()
{
    Task_Handle task;
    Error_Block eb;
    Task_Params taskParams;

	Uart_appC7xPreInit();

    if (Board_initUART() == false)
    {
        System_printf("\nBoard_initUART failed!\n");
        return(0);
    }

    Error_init(&eb);

    /* Initialize the task params */
    Task_Params_init(&taskParams);

    /* Set the task priority higher than the default priority (1) */
    taskParams.priority = 2;
    taskParams.stackSize = 0x6000;

    task = Task_create(taskFxn, &taskParams, &eb);
    if (task == NULL) {

        BIOS_exit(0);
    }
        BIOS_start();    /* does not return */
    return(0);
}
#endif /* #ifdef USE_BIOS */

#ifdef UART_DMA_ENABLE
#if !(defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200))
EDMA3_RM_Handle gEdmaHandle = NULL;

/*
 * Initialize the edma driver and get the handle to the edma driver;
 */
static EDMA3_RM_Handle UartApp_edmaInit(void)
{
    EDMA3_DRV_Result edmaResult = EDMA3_DRV_E_INVALID_PARAM;
    uint32_t edma3Id;

#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) ||\
    defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_K2G) || defined(DEVICE_C6678) || defined(DEVICE_C6657) || defined(DEVICE_OMAPL137) || defined(DEVICE_OMAPL138)
    uint32_t edmaEvent[2], i, chnMapping, chnMappingIdx;

    /* For Keystone devices, edm3Id is UART instance and SoC specific */
    UART_getEdmaInfo(uartTestInstance, &edma3Id, edmaEvent);

    /* Set the RX/TX ownDmaChannels and dmaChannelHwEvtMap */
    for (i = 0; i < 2; i++)
    {
        chnMapping = edmaEvent[i];
        if (chnMapping < 32)
            chnMappingIdx = 0;
        else
        {
            chnMapping -= 32;
            chnMappingIdx = 1;
        }
        sampleInstInitConfig[edma3Id][0].ownDmaChannels[chnMappingIdx] |= (1 << chnMapping);
        sampleInstInitConfig[edma3Id][0].ownTccs[chnMappingIdx] |= (1 << chnMapping);
        sampleInstInitConfig[edma3Id][0].ownPaRAMSets[chnMappingIdx] |= (1 << chnMapping);
        sampleEdma3GblCfgParams[edma3Id].dmaChannelHwEvtMap[chnMappingIdx] |= (1 << chnMapping);
    }
#endif

    if (gEdmaHandle != NULL)
    {
        return(gEdmaHandle);
    }

#if defined (SOC_AM574x) || defined(SOC_AM572x)|| defined(SOC_AM571x) || defined (SOC_DRA72x)  || defined (SOC_DRA75x) || defined (SOC_DRA78x) || defined (SOC_AM335X) || defined (SOC_AM437X)
    edma3Id = 0;
#endif
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(edma3Id, &edmaResult);
#ifdef USE_BIOS
    if (edmaResult != EDMA3_DRV_SOK)
    {
        /* Report EDMA Error */
        System_printf("\nEDMA driver initialization FAIL\n");
    }
    else
    {
        System_printf("\nEDMA driver initialization PASS.\n");
    }
#endif
    return(gEdmaHandle);
}
#endif
#endif

#if defined(BUILD_MPU) || defined (__C7100__)
extern void Osal_initMmuDefault(void);
void InitMmu(void)
{
    Osal_initMmuDefault();
}
#endif

void Uart_appC7xPreInit(void)
{
#if defined (__C7100__) && !defined (SOC_J7200) 
    CSL_ClecEventConfig cfgClec;
	CSL_CLEC_EVTRegs   *clecBaseAddr = (CSL_CLEC_EVTRegs*) CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;

    uint32_t            i, maxInputs = 2048U;

    /* make secure claim bit to FALSE so that after we switch to non-secure mode
     * we can program the CLEC MMRs
     */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = FALSE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_DISABLE;
    cfgClec.extEvtNum         = 0U;
    cfgClec.c7xEvtNum         = 0U;
    for(i = 0U; i < maxInputs; i++)
    {
        CSL_clecConfigEvent(clecBaseAddr, i, &cfgClec);
    }
#endif

    return;
}
