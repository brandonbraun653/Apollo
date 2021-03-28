/*
 *   Copyright (c) Texas Instruments Incorporated 2019-2020
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
 *  \file     lbist_test_func.c
 *
 *  \brief    This file contains LBIST functional test code. .
 *
 *  \details  LBIST Functional tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_lbist.h>
#include <ti/csl/soc.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/sciclient/sciclient.h>

/* Osal API header files */
#include <ti/osal/HwiP.h>
#include <ti/osal/TimerP.h>

/* #define DEBUG */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Lbist Parameters */
#define LBIST_DC_DEF         (0x3u)
#define LBIST_DIVIDE_RATIO   (0x02u)
#define LBIST_STATIC_PC_DEF  (0x3fffu)
#define LBIST_RESET_PC_DEF   (0x0fu)
#define LBIST_SET_PC_DEF     (0x00u)
#define LBIST_SCAN_PC_DEF    (0x08u)
#define LBIST_PRPG_DEF       (0x1fffffffffffffu)

/* Note this is just local test array index */
#define LBIST_MAIN_MCU0_INDEX         0
#define LBIST_MAIN_MCU1_INDEX         1
#define LBIST_C7X_CORE_INDEX          2
#define LBIST_VPAC_INDEX              3
#define LBIST_A72_CORE_INDEX          4
#define LBIST_DMPAC_INDEX             5

#define LBIST_NUM_CORES               (LBIST_VPAC_INDEX+1)

#define LBIST_MAX_CORE_INDEX          (LBIST_DMPAC_INDEX)

#define LBIST_MAX_TIMEOUT_VALUE    10000000u

typedef void (*LBIST_handlerPtr)(uint32_t coreIndex);

typedef struct LBIST_TestHandle_s
{
    /** Core name */
    char coreName[16];
    /** Indicate secondary core need to be handled */
    bool secondaryCoreNeeded;
    bool wfiCheckNeeded;
    /** Secondary core name */
    char secCoreName[16];
    /** Pointer to LBIST register map */
    CSL_LBIST_regMapType *pRegMap;
    /** Pointer to LBIST signature */
    uint32_t *pLBISTSig;
    /** Expected signature */
    uint32_t expectedMISR;
    /** Mask used to check CPU Status */
    uint32_t cpuStatusFlagMask;
    /** LBIST event handler function */
    LBIST_handlerPtr handler;
    /** Interrupt number for error event */
    uint32_t interruptNumber;
    /** Core Processor Id */
    uint32_t tisciProcId;
    /** Secondary Core Processor Id */
    uint32_t tisciSecProcId;
    /** Core Device Id */
    uint32_t tisciDeviceId;
    /** Secondary Core Device Id */
    uint32_t tisciSecDeviceId;
    /** PBIST Device id: needed to be on to keep power on to the cores */
    uint32_t tisciPBISTDeviceId;
    /** Flag to indicate test done, will be set when interrupt event comes */
    volatile bool doneFlag;
    /** Configuration for LBIST test */
    CSL_LBIST_config_t LBISTConfig;
} LBIST_TestHandle_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void LBIST_eventHandler(uint32_t coreIndex);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

LBIST_TestHandle_t LBIST_TestHandleArray[LBIST_MAX_CORE_INDEX+1] =
{
 /* Main R5F 0 */
 {
  .coreName = "Main R5F0-0",
  .secondaryCoreNeeded    = true,             /* Secondary core needed */
  .wfiCheckNeeded         = false,            /* wfi check needed */
  .secCoreName            = "Main R5F1-0",    /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MCU0_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MCU0_LBIST_SIG),
  .expectedMISR           = 0xad7f4501,    /* Expected signature for main R5 0*/
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,       /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0, /* BIST DONE interrupt number */
  .tisciProcId            = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_0_CPU0, /* Main R5F core 0 Proc Id */
  .tisciSecProcId         = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_0_CPU1, /* Main R5F core 1 Proc Id */
  .tisciDeviceId          = TISCI_DEV_R5FSS0_CORE0,   /* Main R5F core 0 Device Id */
  .tisciSecDeviceId       = TISCI_DEV_R5FSS0_CORE1,   /* Main R5F core 1 Device Id */
  .tisciPBISTDeviceId     = TISCI_DEV_PBIST9,         /* PBIST device id  */
  .doneFlag               = false,                    /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },
 /* Main R5F 1 */
 {
  .coreName               = "Main R5F1-0",
  .secondaryCoreNeeded    = true,            /* Secondary core needed */
  .wfiCheckNeeded         = false,           /* wfi check needed */
  .secCoreName            = "Main R5F1-1",   /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MCU1_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MCU1_LBIST_SIG),
  .expectedMISR           = 0xad7f4501,              /* Expected signature Main R5 1*/
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,      /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0,/* BIST DONE interrupt number */
  .tisciProcId            = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_1_CPU0, /* Main R5F core 0 Proc Id */
  .tisciSecProcId         = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_1_CPU1, /* Main R5F core 1 Proc Id */
  .tisciDeviceId          = TISCI_DEV_R5FSS1_CORE0,  /* Main R5F core 0 Device id */
  .tisciSecDeviceId       = TISCI_DEV_R5FSS1_CORE1,  /* Main R5F core 1 Device id */
  .tisciPBISTDeviceId     = TISCI_DEV_PBIST10,       /* PBIST device id  */
  .doneFlag               = false,                   /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },
 /* C7x */
 {
  .coreName               = "C7x ",
  .secondaryCoreNeeded    = false,  /* Secondary core needed */
  .wfiCheckNeeded         = false,  /* wfi check needed */
  .secCoreName            = "None",   /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->DSP0_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->DSP0_LBIST_SIG),
  .expectedMISR           = 0x13e0a961,              /* Expected signature for C7x*/
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,      /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_C7X_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0,/* BIST DONE interrupt number */
  .tisciProcId            = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P4_C711_512KB,  /* C7x Proc Id */
  .tisciSecProcId         = 0,
  .tisciDeviceId          = TISCI_DEV_C71SS0,        /* C7x Device Id */
  .tisciSecDeviceId       = 0,
  .tisciPBISTDeviceId     = TISCI_DEV_C71X_0_PBIST_VD,   /* PBIST device id  */
  .doneFlag               = false,                       /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },

 /* VPAC */
 {
  .coreName               = "VPAC",
  .secondaryCoreNeeded    = false,           /* Secondary core needed */
  .wfiCheckNeeded         = false,           /* wfi check needed */
  .secCoreName            = "None",          /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->VPAC_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->VPAC_LBIST_SIG),
  .expectedMISR           = 0x7059de32,                                 /* Expected signature for C6x*/
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,                         /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0,/* BIST DONE interrupt number */
  .tisciProcId            = 0,  /* No proc id */
  .tisciSecProcId         = 0,  /* No Proc Id */
  .tisciDeviceId          = TISCI_DEV_VPAC_TOP_MAIN_0,             /* VPAC Device Id */
  .tisciSecDeviceId       = 0,
  .tisciPBISTDeviceId     = TISCI_DEV_PBIST3,                      /* Device Id for VPAC PBIST */
  .doneFlag               = false,                                 /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },

 /* A72 */
 {
  .coreName               = "A72 core 0",
  .secondaryCoreNeeded    = true,           /* Secondary core needed */
  .wfiCheckNeeded         = false,          /* wfi check needed */
  .secCoreName            = "A72 core 1",   /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MPU0_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->MPU0_LBIST_SIG),
  .expectedMISR           = 0x7ed8d1af,                                 /* Expected signature for A72 */
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,                         /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0,/* BIST DONE interrupt number */
  .tisciProcId            = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P0_A72_DUAL_1MB,            /* A72 core 0 Proc Id */
  .tisciSecProcId         = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P0_A72_DUAL_1MB_1,          /* A72 core 1 Proc Id */
  .tisciDeviceId          = TISCI_DEV_A72SS0_CORE0,  /* A72 core 0 Device Id */
  .tisciSecDeviceId       = TISCI_DEV_A72SS0_CORE0,  /* A72 core 1 Device Id */
  .tisciPBISTDeviceId     = TISCI_DEV_COMPUTE_CLUSTER0_PBIST_WRAP, /* Device Id for A72 PBIST */
  .doneFlag               = false,                   /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },


 /* DMPAC */
 {
  .coreName               = "DMPAC",
  .secondaryCoreNeeded    = false,           /* Secondary core needed */
  .wfiCheckNeeded         = false,           /* wfi check needed */
  .secCoreName            = "None",          /* Secondary core */
  .pRegMap                = (CSL_LBIST_regMapType *)(&(((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->DMPAC_LBIST_CTRL)),
  .pLBISTSig              = (uint32_t *)(&((CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE)->DMPAC_LBIST_SIG),
  .expectedMISR           = 0x1306bd91,                                 /* Expected signature for C6x*/
  .cpuStatusFlagMask      = TISCI_MSG_VAL_PROC_BOOT_STATUS_FLAG_R5_WFI, /* Expected boot status value for wfi */
  .handler                = LBIST_eventHandler,                         /* LBIST event handler */
  .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0,/* BIST DONE interrupt number */
  .tisciProcId            = 0,  /* No proc id */
  .tisciSecProcId         = 0,  /* No Proc Id */
  .tisciDeviceId          = TISCI_DEV_DMPAC_TOP_MAIN_0,             /* DMPAC Device Id */
  .tisciSecDeviceId       = 0,
  .tisciPBISTDeviceId     = TISCI_DEV_PBIST1,                       /* Device Id for DMPAC PBIST */
  .doneFlag               = false,                                  /* Initialize done flag */
  .LBISTConfig = {
      .dc_def        = LBIST_DC_DEF,
      .divide_ratio  = LBIST_DIVIDE_RATIO,
      .static_pc_def = LBIST_STATIC_PC_DEF,
      .set_pc_def    = LBIST_SET_PC_DEF,
      .reset_pc_def  = LBIST_RESET_PC_DEF,
      .scan_pc_def   = LBIST_SCAN_PC_DEF,
      .prpg_def      = LBIST_PRPG_DEF,
  },
 },

};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void LBIST_eventHandler( uint32_t coreIndex )
{
    int32_t status;
    Bool isLBISTDone = CSL_FALSE;
    CSL_LBIST_regMapType *pRegMap = LBIST_TestHandleArray[coreIndex].pRegMap;

    /* Double check if the LBIST done flag is set */
    status = CSL_LBIST_isDone(pRegMap, &isLBISTDone);
    if ((status == CSL_PASS) && (isLBISTDone == CSL_TRUE))
    {
        LBIST_TestHandleArray[coreIndex].doneFlag = true;
        /* Need to pull run down to low to clear the done interrupt */
        CSL_LBIST_stop( pRegMap );
    }
    return;

}

int32_t LBIST_runTest(uint32_t coreIndex)
{
    int32_t testResult = 0;
    int32_t status;
    uint32_t calculatedMISR;
    uint32_t expectedMISR;
    Bool isLBISTRunning = CSL_FALSE;
    CSL_LBIST_regMapType *pRegMap;
    uint32_t *pLBISTSig;
    HwiP_Params       hwiParams;
    HwiP_Handle LBIST_hwiPHandle;
    struct tisci_msg_proc_get_status_resp cpuStatus;
    uint64_t startTime , testStartTime,  testEndTime, endTime;
    uint64_t prepTime, diffTime, restoreTime;
    uint32_t timeoutCount = 0;

    UART_printf("\n Starting LBIST test on %s, index %d...",
                LBIST_TestHandleArray[coreIndex].coreName,
                coreIndex);
#ifdef DEBUG
    char inputChar;

    UART_printf("\n Press 'n' to skip..Press any key to continue...");
    inputChar = UART_getc();

    if (inputChar == 'n')
    {
        UART_printf("   Skipping this test. on request \n");
        return 0;
    }
#endif
    /* Populate local variables from instance structure */
    pRegMap = LBIST_TestHandleArray[coreIndex].pRegMap;
    pLBISTSig = LBIST_TestHandleArray[coreIndex].pLBISTSig;

    /* Disable interrupt */
    HwiP_disableInterrupt(LBIST_TestHandleArray[coreIndex].interruptNumber);

    /* Default parameter initialization */
    HwiP_Params_init(&hwiParams);

    /* Pass core Index as argument to handler*/
    hwiParams.arg = coreIndex;
#ifdef DEBUG
    UART_printf("\n  HwiP_Params_init complete \n");
#endif
    /* Register call back function for LBIST Interrupt */
    LBIST_hwiPHandle = HwiP_create(LBIST_TestHandleArray[coreIndex].interruptNumber,
                                       (HwiP_Fxn)LBIST_TestHandleArray[coreIndex].handler,
                                       (void *)&hwiParams);
    if (LBIST_hwiPHandle == NULL)
    {
        UART_printf("   Interrupt registration failed \n");
        testResult = -1;
    }

    /* Initialize done flag */
    LBIST_TestHandleArray[coreIndex].doneFlag = false;

    /* Get start time of test */
    startTime = TimerP_getTimeInUsecs();

    if (testResult == 0)
    {
        if (LBIST_TestHandleArray[coreIndex].tisciProcId != 0u)
        {
#ifdef DEBUG
            UART_printf("  Primary core: %s: Requesting processor \n",
                        LBIST_TestHandleArray[coreIndex].coreName);
#endif
            /* Request Primary core */
            status = Sciclient_procBootRequestProcessor(LBIST_TestHandleArray[coreIndex].tisciProcId,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Primary core: Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                            LBIST_TestHandleArray[coreIndex].tisciProcId);
                testResult = -1;
            }
        }
    }

    if (testResult == 0)
    {
        if ((LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
            && (LBIST_TestHandleArray[coreIndex].tisciSecProcId != 0u))
        {

#ifdef DEBUG
            UART_printf("  Secondary core: %s: Requesting processor \n",
                    LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            /* Request secondary core */
            status = Sciclient_procBootRequestProcessor(LBIST_TestHandleArray[coreIndex].tisciSecProcId,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                            LBIST_TestHandleArray[coreIndex].tisciSecProcId);
                testResult = -1;
            }
        }
    }

    /* Assumption is that the processor on which LBIST is run is executing wfi instruction */

    if ((testResult == 0)  && (LBIST_TestHandleArray[coreIndex].wfiCheckNeeded))
    {
        /* Wait for for primary core wfi */
#ifdef DEBUG
        UART_printf("  Primary core: Waiting for Wfi for %s \n",
                    LBIST_TestHandleArray[coreIndex].coreName);
#endif
        do
        {
#ifdef DEBUG
            bool firstCheck = false;
#endif

            status = Sciclient_procBootGetProcessorState(LBIST_TestHandleArray[coreIndex].tisciProcId,
                                                         &cpuStatus, SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Primary core: Sciclient_procBootGetProcessorState 0x%x...FAILED \n",
                            LBIST_TestHandleArray[coreIndex].tisciProcId);
                testResult = -1;
            }
#ifdef DEBUG
            else
            {
                if (firstCheck == false)
                {
                     UART_printf("  Primary core: cpuStatus flag for %s: %x \n",
                                 LBIST_TestHandleArray[coreIndex].coreName,
                                 cpuStatus.status_flags_1 );
                     firstCheck = true;
                }
            }
#endif
        } while ((cpuStatus.status_flags_1 & LBIST_TestHandleArray[coreIndex].cpuStatusFlagMask)
                 != LBIST_TestHandleArray[coreIndex].cpuStatusFlagMask);
    }

    if ((testResult == 0)  && (LBIST_TestHandleArray[coreIndex].wfiCheckNeeded))
    {
        if (LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
        {
            /* Wait for for secondary core wfi */
#ifdef DEBUG
            UART_printf("  Secondary core: Waiting for Wfi for %s \n",
                    LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            do
            {
#ifdef DEBUG
                bool firstCheck = false;
#endif
                status = Sciclient_procBootGetProcessorState(LBIST_TestHandleArray[coreIndex].tisciSecProcId,
                                                             &cpuStatus, SCICLIENT_SERVICE_WAIT_FOREVER);
                if (status != CSL_PASS)
                {
                    UART_printf("   Secondary core: Sciclient_procBootGetProcessorState 0x%x...FAILED \n",
                                LBIST_TestHandleArray[coreIndex].tisciSecProcId);
                    testResult = -1;
                }
#ifdef DEBUG
                else
                {
                    if (firstCheck == false)
                    {
                         UART_printf("  Secondary core: cpuStatus flag for %s: %x \n",
                                     LBIST_TestHandleArray[coreIndex].coreName,
                                     cpuStatus.status_flags_1 );
                         firstCheck = true;
                    }
                }
#endif
            } while ((cpuStatus.status_flags_1 & LBIST_TestHandleArray[coreIndex].cpuStatusFlagMask)
                     != LBIST_TestHandleArray[coreIndex].cpuStatusFlagMask);
        }
    }

    if (testResult == 0)
    {
        if ((LBIST_TestHandleArray[coreIndex].tisciDeviceId != 0u)
            && (LBIST_TestHandleArray[coreIndex].tisciPBISTDeviceId != 0u))
        {
            /* Power up PBIST module so that the cores are powered up, when setting  */
#ifdef DEBUG
            UART_printf("  Power up PBIST module to keep power for the cores  \n");
#endif
            status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciPBISTDeviceId,
                                                 TISCI_MSG_VALUE_DEVICE_SW_STATE_RETENTION,
                                                 TISCI_MSG_FLAG_AOP | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   PBIST module: Sciclient_pmSetModuleState...FAILED \n");
                testResult = -1;
            }
        }
    }
    if (testResult == 0)
    {
        if (LBIST_TestHandleArray[coreIndex].tisciDeviceId != 0u)
        {
            /* Set Software Reset Disable State for Primary core */
#ifdef DEBUG
            UART_printf("  %s: Primary core: Put in Software Reset Disable \n",
                        LBIST_TestHandleArray[coreIndex].coreName);
#endif
            status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciDeviceId,
                                                 TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                                 TISCI_MSG_FLAG_AOP | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Primary core: Sciclient_pmSetModuleState...FAILED \n");
                testResult = -1;
            }
        }
    }

    if (testResult == 0)
    {
        if ((LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
            && (LBIST_TestHandleArray[coreIndex].tisciSecDeviceId != 0u))
        {
            /* Set Software Reset Disable State for Secondary core */
#ifdef DEBUG
            UART_printf("  %s: Secondary Core Put in Software Reset Disable \n",
                        LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciSecDeviceId,
                                                 TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                                 TISCI_MSG_FLAG_AOP  | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core Sciclient_pmSetModuleState...FAILED \n");
                testResult = -1;
            }
        }
    }

    if (testResult == 0)
    {
        /* Configure LBIST */

        status = CSL_LBIST_programConfig(pRegMap, &LBIST_TestHandleArray[coreIndex].LBISTConfig);
        if (status != CSL_PASS)
        {
            UART_printf("    LBIST program config failed \n");
            testResult = -1;
        }
    }
    /* Get start time for LBIST test */
    testStartTime = TimerP_getTimeInUsecs();

    if (testResult == 0)
    {

        /* Call CSL API */
        status = CSL_LBIST_enableIsolation(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_enableIsolation...FAILED \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_reset(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_reset...FAILED \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        status = CSL_LBIST_enableRunBISTMode(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_enableRunBISTMode...FAILED \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_start(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_start...FAILED \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_isRunning(pRegMap, &isLBISTRunning);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_isRunning...FAILED \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        /* Just checking if LBIST in running state */
        if ( isLBISTRunning != CSL_TRUE )
        {
#ifdef DEBUG
            UART_printf("   LBIST not running \n");
#endif
        }

        /* Timeout if exceeds time */
        while ((!LBIST_TestHandleArray[coreIndex].doneFlag)
               && (timeoutCount++ < LBIST_MAX_TIMEOUT_VALUE));

        if (!(LBIST_TestHandleArray[coreIndex].doneFlag))
        {
            UART_printf("   LBIST test timed out \n");
            testResult = -1;
        }
        /* reset Done flag so we can run again */
        LBIST_TestHandleArray[coreIndex].doneFlag = false;
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_getMISR(pRegMap, &calculatedMISR);
        if (status != CSL_PASS)
        {
            UART_printf("   Get MISR failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_getExpectedMISR(pLBISTSig, &expectedMISR);
        if ( status != CSL_PASS)
        {
            UART_printf("   Get Expected MISR failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_clearRunBISTMode(pRegMap);
        if ( status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_clearRunBISTMode failed \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        status = CSL_LBIST_stop(pRegMap);
        if ( status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_stop failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_reset(pRegMap);
        if ( status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_reset failed \n");
            testResult = -1;
        }
    }
    /* Here LBIST test is complete , get end time of test */
    testEndTime = TimerP_getTimeInUsecs();

    /* The following sequence is needed to restore core to normal operation */
    if (testResult == 0)
    {
        if ((LBIST_TestHandleArray[coreIndex].tisciDeviceId != 0u)
            && (LBIST_TestHandleArray[coreIndex].tisciPBISTDeviceId != 0u))
        {
            /* Power down PBIST module so that the cores can now be powered down  */
#ifdef DEBUG
            UART_printf("  Power down PBIST  \n");
#endif
            status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciPBISTDeviceId,
                                                 TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                                 TISCI_MSG_FLAG_AOP | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   PBIST: Sciclient_pmSetModuleState...FAILED \n");
                testResult = -1;
            }
        }
    }
    if (testResult == 0)
    {
        /* Power off Primary core */
#ifdef DEBUG
        UART_printf("  Primary core: Powering off %s \n",
                    LBIST_TestHandleArray[coreIndex].coreName);
#endif
        status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciDeviceId,
                                             TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                             TISCI_MSG_FLAG_AOP  | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                             SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_pmSetModuleState: Power off FAILED \n");
        }
    }

    if (testResult == 0)
    {
        if (LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
        {
            /* Power off Secondary core */
#ifdef DEBUG
            UART_printf("  Secondary core: Powering off %s \n",
                        LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            status =  Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciSecDeviceId,
                                                 TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                                 TISCI_MSG_FLAG_AOP  | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_pmSetModuleState:  Power off FAILED \n");
                testResult = -1;
            }
        }
    }

    if (testResult == 0)
    {
#ifdef DEBUG
        UART_printf("  Disabling isolation \n");
#endif
        status = CSL_LBIST_disableIsolation(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("   CSL_LBIST_disableIsolation ...FAILED \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        /* power on Primary core*/
#ifdef DEBUG
        UART_printf("  Primary core: Powering on %s \n",
                    LBIST_TestHandleArray[coreIndex].coreName);
#endif
        status = Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciDeviceId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            TISCI_MSG_FLAG_AOP,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);

        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_pmSetModuleState 0x%x ...FAILED \n",
                        LBIST_TestHandleArray[coreIndex].tisciDeviceId);
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        if (LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
        {
            /* power on Secondary core*/
#ifdef DEBUG
            UART_printf("  Secondary core: Powering on %s \n",
                        LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            status = Sciclient_pmSetModuleState(LBIST_TestHandleArray[coreIndex].tisciSecDeviceId,
                                                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                                TISCI_MSG_FLAG_AOP,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_pmSetModuleState 0x%x ...FAILED \n",
                            LBIST_TestHandleArray[coreIndex].tisciSecDeviceId);
                testResult = -1;
                return testResult;
            }
        }
    }

    if (testResult == 0)
    {
        /* Check to make sure LBIST is not running */
        status = CSL_LBIST_isRunning(pRegMap, &isLBISTRunning);
        if ( status != CSL_PASS )
        {
            UART_printf("\n CSL_LBIST_isRunning failed \n");
            testResult = -1;
        }
    }

    if ((testResult == 0) && (LBIST_TestHandleArray[coreIndex].tisciProcId !=0))
    {
        /* release processor Primary core */
#ifdef DEBUG
        UART_printf("  Primary core: Releasing %s \n",
                    LBIST_TestHandleArray[coreIndex].coreName);
#endif

        status = Sciclient_procBootReleaseProcessor(LBIST_TestHandleArray[coreIndex].tisciProcId,
                                                    TISCI_MSG_FLAG_AOP,
                                                    SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                        LBIST_TestHandleArray[coreIndex].tisciProcId);
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        if ((LBIST_TestHandleArray[coreIndex].secondaryCoreNeeded)
            && (LBIST_TestHandleArray[coreIndex].tisciSecDeviceId != 0u))
        {
            /* release processor Secondary core */
#ifdef DEBUG
            UART_printf("  Secondary core: Releasing %s \n",
                        LBIST_TestHandleArray[coreIndex].secCoreName);
#endif
            status = Sciclient_procBootReleaseProcessor(LBIST_TestHandleArray[coreIndex].tisciSecProcId,
                                                        TISCI_MSG_FLAG_AOP,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                            LBIST_TestHandleArray[coreIndex].tisciSecProcId);
                testResult = -1;
            }
        }
    }

    if (testResult == 0)
    {
        status = CSL_LBIST_isRunning(pRegMap, &isLBISTRunning);
        if (status != CSL_PASS)
        {
            UART_printf("    CSL_LBIST_isRunning failed\n");
            testResult = -1;
        }
        else
        {
            /* Make sure that the LBIST is not running */
            if (isLBISTRunning == CSL_TRUE)
            {
                UART_printf("\n   LBIST is found to be still running at the end of the test\n");
                testResult = -1;
            }
        }
    }

    /* Here LBIST test is complete , get end time of test */
    endTime = TimerP_getTimeInUsecs();

    if (testResult == 0)
    {
        /* TODO: Temporarily hard coding to expected MISR */
        expectedMISR = LBIST_TestHandleArray[coreIndex].expectedMISR;
        if (calculatedMISR != expectedMISR)
        {
            UART_printf("\n   LBIST failed with MISR mismatch: Expected 0x%x got 0x%x \n",
                        expectedMISR, calculatedMISR);
            testResult = -1;
        }
        else
        {
            UART_printf("\n   LBIST MISR matched \n");
        }
    }

    prepTime = testStartTime - startTime;
    diffTime = testEndTime - testStartTime;
    restoreTime = endTime - testEndTime;
    UART_printf("  Delta Cores prep time in micro secs %d \n", (uint32_t)prepTime );
    UART_printf("  Delta LBIST execution time in micro secs %d \n", (uint32_t)diffTime );
    UART_printf("  Delta Cores restore time in micro secs %d \n", (uint32_t)restoreTime );
    UART_printf("  LBIST complete for %s \n",
                LBIST_TestHandleArray[coreIndex].coreName);

    return (testResult);
}

/* Run all APIs not exercised by functional test */
int32_t LBIST_apiTest(uint32_t coreIndex)
{
    int32_t testResult = 0;
    int32_t status;
    CSL_LBIST_regMapType *pRegMap;

    pRegMap = LBIST_TestHandleArray[coreIndex].pRegMap;

    /* Call CSL APIs not used by functional test */
    status = CSL_LBIST_clearRunBISTMode(pRegMap);
    if (status != CSL_PASS)
    {
        UART_printf("    CSL_LBIST_clearRunBISTMode failed\n");
        testResult = -1;
    }

    if (testResult == CSL_PASS)
    {
        status = CSL_LBIST_stop(pRegMap);
        if (status != CSL_PASS)
        {
            UART_printf("    CSL_LBIST_stop failed\n");
            testResult = -1;
        }
    }

    return (testResult);
}

/* LBIST Functional test */
int32_t LBIST_funcTest(void)
{
    int32_t    testResult = 0;
    int i;

    for ( i = 0; i < LBIST_NUM_CORES; i++)
    {
        testResult = LBIST_runTest(i);

        if (testResult != 0)
        {
            UART_printf("   LBIST functional test failed %d\n", i);
            break;
        }
    }

    if (testResult == 0)
    {
        /* API test is enough to be run on one instance */
        testResult = LBIST_apiTest(0);
        if (testResult != 0)
        {
            UART_printf("   LBIST API test failed \n");
        }
    }

    return (testResult);
}

/* Nothing past this point */
