/*
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     pbist_test_func.c
 *
 *  \brief    This file contains PBIST Functional test code.
 *
 *  \details  PBIST Functional tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_pbist.h>
#include <ti/csl/csl_rat.h>
#include <ti/csl/csl_clec.h>
#include <ti/csl/cslr_vpac.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_cbass.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/sciclient/sciclient.h>

/* Osal API header files */
#include <ti/osal/HwiP.h>
#include <ti/osal/TimerP.h>

/* #define DEBUG */

#define POWERUP_CORES

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Note the following are array indexes into the test config array */
#define PBIST_INSTANCE_MCU                (0U)
#define PBIST_INSTANCE_MAIN_PULSAR_0      (1U)
#define PBIST_INSTANCE_MAIN_PULSAR_1      (2U)
#define PBIST_INSTANCE_C7X                (3U)
#define PBIST_INSTANCE_A72                (4U)
#define PBIST_INSTANCE_VPAC               (5U)
#define PBIST_INSTANCE_DMPAC              (6U)
#define PBIST_INSTANCE_MAIN_NAVSS         (7U)
#define PBIST_INSTANCE_HC                 (8U)
#define PBIST_INSTANCE_C66X_0             (9U)
#define PBIST_INSTANCE_C66X_1             (10U)

#define PBIST_MAX_INSTANCE                (18U)

#define PBIST_NUM_INSTANCE                (PBIST_INSTANCE_HC+1U)

#define PBIST_MAX_TIMEOUT_VALUE           (100000000u)

#define PBIST_REGION_LOCAL_BASE           (0x60000000u)

#define PBIST_RAT_REGION_INDEX            0

#define PBIST_REG_REGION_SIZE             (0x400u)

#define PBIST_INSTANCE_NAME_MAX_LENGTH    16

/* Firewall definitions */
#define FW_REGION_ENABLE (0xAU)
#define FW_MCU_R5F0_PRIVID (96U)

typedef void (*PBIST_handlerPtr)(uint32_t instanceId);

typedef struct PBIST_TestHandle_s
{
    char     testName[PBIST_INSTANCE_NAME_MAX_LENGTH];
    uint64_t PBISTRegsHiAddress;
    CSL_pbistRegs *pPBISTRegs;
    CSL_PBIST_config_t PBISTConfig;
    uint32_t tisciPBISTDeviceId;
    uint32_t interruptNumber;
    bool procRstNeeded;
    bool secondaryCoreNeeded;
    char coreName[16];
    char secCoreName[16];
    uint32_t tisciProcId;
    uint32_t tisciSecProcId;
    uint32_t tisciDeviceId;
    uint32_t tisciSecDeviceId;
    volatile bool doneFlag;
} PBIST_TestHandle_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void PBIST_eventHandler( uint32_t instanceId );

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

PBIST_TestHandle_t PBIST_TestHandleArray[PBIST_MAX_INSTANCE+1] =
{
    /* MCU PBIST */
    {
        .testName           = "MCU PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_MCU_PBIST0_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x00002000u,          /* Choose Algorithm 13  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* NOTE: As the MCU R5f is running this code override bit cannot be set to enable all memory test */
            .memoryGroupsBitMap = 0x0080000000000000u,  /* Choose ADC RAM */
            .scrambleValue      = 0xFEDCBA9876543210U,  /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_MCU_PBIST0, /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0,
        .procRstNeeded          = false,
        .secondaryCoreNeeded    = false,                /* Secondary core needed */
        .doneFlag               = false,                /* Initialize done flag */
    },
    /* Main R5F 0 */
    {
        .testName           = "Main R5F 0 PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST9_BASE, /* PBIST9: Main R5F 0 */
        .PBISTConfig = {
            .algorithmsBitMap   = 0x003fffffu,              /* Choose Algorithms 1-22 */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not functional currently */
            .memoryGroupsBitMap = 0x000000000000011u,       /* Memory group 1 & 4 */
            .scrambleValue      = 0xFEDCBA9876543210U,      /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST9,    /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST9_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = true,                /* Secondary core needed */
        .coreName               = "Main R5F0 core0",   /* Primary core   */
        .secCoreName            = "Main R5F0 core1",   /* Secondary core */
        .tisciProcId            = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_0_CPU0, /* Main R5F core 0 Proc Id */
        .tisciSecProcId         = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_0_CPU1, /* Main R5F core 1 Proc Id */
        .tisciDeviceId          = TISCI_DEV_R5FSS0_CORE0,   /* Main R5F core 0 Device Id */
        .tisciSecDeviceId       = TISCI_DEV_R5FSS0_CORE1,   /* Main R5F core 1 Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* Main MCU 1 */
    {
        .testName           = "Main R5F 1 PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST10_BASE, /* PBIST10: Main MCU 1 */
        .PBISTConfig = {
            .algorithmsBitMap   = 0x003fffffu,              /* Choose Algorithms 1-22 */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not functional currently */
            .memoryGroupsBitMap = 0x00000011u,              /* Memory group 1 & 4 */
            .scrambleValue      = 0xFEDCBA9876543210U,      /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST10,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = true,                /* Secondary core needed */
        .coreName               = "Main R5F1 core0",   /* Primary core   */
        .secCoreName            = "Main R5F1 core1",   /* Secondary core */
        .tisciProcId            = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_1_CPU0, /* Main R5F core 0 Proc Id */
        .tisciSecProcId         = SCICLIENT_PROC_ID_PULSAR_SL_MAIN_1_CPU1, /* Main R5F core 1 Proc Id */
        .tisciDeviceId          = TISCI_DEV_R5FSS1_CORE0,  /* Main R5F core 0 Device id */
        .tisciSecDeviceId       = TISCI_DEV_R5FSS1_CORE1,  /* Main R5F core 1 Device id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* C7X */
    {
        .testName           = "C7X PBIST",
        .PBISTRegsHiAddress = CSL_COMPUTE_CLUSTER0_C71SS0_PBIST_BASE,
        .pPBISTRegs         = (CSL_pbistRegs *)PBIST_REGION_LOCAL_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x00003fffu,          /* Choose Algorithm 1-14  */
            .override           = (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT),
            /* Override bit set to 1 to use all memory */
            .memoryGroupsBitMap = 0x000000000fffffffu,  /* Memory groups 1-28 */
            .scrambleValue      = 0xFEDCBA9876543210U,  /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_C71X_0_PBIST_VD,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_CLEC_SOC_EVENTS_OUT_LEVEL_12,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = false,               /* Secondary core needed */
        .coreName               = "C7x ",
        .tisciProcId            = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P4_C711_512KB,  /* C7x Proc Id */
        .tisciDeviceId          = TISCI_DEV_C71SS0,    /* C7x Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* A72 */
    {
        .testName           = "A72 PBIST",
        .PBISTRegsHiAddress = CSL_COMPUTE_CLUSTER0_A72SS0_PBIST0_BASE,
        .pPBISTRegs         = (CSL_pbistRegs *)PBIST_REGION_LOCAL_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x003fffffu,         /* Choose Algorithm 1-22  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not functional currently */
            .memoryGroupsBitMap = 0x0000000000000001u, /* Memory group 1 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_COMPUTE_CLUSTER0_PBIST_WRAP, /* Device Id for A72 PBIST */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_CLEC_SOC_EVENTS_OUT_LEVEL_8 /*CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_DFT_PBIST_CPU_0*/,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = true,                /* Secondary core needed */
        .coreName               = "A72 core 0",        /* Primary core   */
        .secCoreName            = "A72 core 1",        /* Secondary core */
        .tisciProcId            = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P0_A72_DUAL_1MB,            /* A72 core 0 Proc Id */
        .tisciSecProcId         = SCICLIENT_PROC_ID_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0_P0_A72_DUAL_1MB_1,          /* A72 core 1 Proc Id */
        .tisciDeviceId          = TISCI_DEV_A72SS0_CORE0,  /* A72 core 0 Device Id */
        .tisciSecDeviceId       = TISCI_DEV_A72SS0_CORE1,  /* A72 core 1 Device Id */
        .doneFlag               = false,                   /* Initialize done flag */
    },
    /* VPAC */
    {
        .testName           = "VPAC PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST3_BASE,
        .PBISTConfig = {
            //.algorithmsBitMap   = 0x0fffffffu, /* Choose Algorithm 1-28  */
            .algorithmsBitMap   = 0x05555555u,   /* Choose Algorithm 1,3,5,7,9,11,13,15,17,19,21,23,25,27  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            /* Memory Group 12 is officially not supported from design team */
            //.memoryGroupsBitMap = 0x0000000000007fffu, /* Memory groups 1-15 */
            .memoryGroupsBitMap = 0x0000000000000077fu,  /* Memory groups 1-7, 9, 10, 11 */
            .scrambleValue      = 0xFEDCBA9876543210U,   /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST3,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = false,                /* Secondary core needed */
        .coreName               = "VPAC core",          /* Primary core   */
        .tisciProcId            = 0x0u,                 /* No ProcId for VPAC */
        .tisciDeviceId          = TISCI_DEV_VPAC_TOP_MAIN_0, /* VPAC core Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* DMPAC */
    {
        .testName           = "DMPAC PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST1_BASE,
        .PBISTConfig = {
            //.algorithmsBitMap   = 0x3fffffffu,         /* Choose Algorithms 1-30  */
            .algorithmsBitMap   =   0x00000001u,         /* Choose Algorithm 1  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x0000000000000fffu, /* Memory groups 1-12 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST1,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = true,                       /* Secondary core needed */
        .coreName               = "DMPAC core",               /* Primary core   */
        .secCoreName            = "DMPAC SDE core",           /* Secondary core */
        .tisciProcId            = 0x0u,                       /* No ProcId for DMPAC */
        .tisciSecProcId         = 0x0u,                       /* No Sec ProcId for DMPAC */
        .tisciDeviceId          = TISCI_DEV_DMPAC_TOP_MAIN_0, /* DMPAC Core Device Id */
        .tisciSecDeviceId       = TISCI_DEV_DMPAC0_SDE_0,     /* DMPAC_SDE Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* NAVSS */
    {
        .testName           = "NAVSS PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST7_BASE,
        .PBISTConfig = {
            //.algorithmsBitMap   = 0x0fffffffu,  /* Choose Algorithms 1-28  */
            .algorithmsBitMap   = 0x05555555u,    /* Choose Algorithms 1,3,5,7,9,11,13,15,17,19,21,23,25,27  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x0000001fffffffffu, /* Memory groups 1-37 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST7,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = false,                /* Secondary core needed */
        .coreName               = "NAVSS",              /* Primary core   */
        .tisciProcId            = 0x0u,                 /* No ProcId for NAVSS */
        .tisciDeviceId          = TISCI_DEV_NAVSS0,     /* NAVSS Device Id */
        .doneFlag               = false,                /* Initialize done flag */
    },
    /* HC */
    {
        .testName           = "HC PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST5_BASE,
        .PBISTConfig = {
            //.algorithmsBitMap   = 0x0fffffffu, /* Choose Algorithms 1-28  */
            .algorithmsBitMap   = 0x01555555u,   /* Choose Algorithms 1,3,5,7,9,11,13,15,17,19,21,23,25 */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x00000000000000780u, /* Only Memory groups 8-11 supported */
            .scrambleValue      = 0xFEDCBA9876543210U,  /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST5, /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0,
        .procRstNeeded          = false,
        .secondaryCoreNeeded    = false,            /* Secondary core needed */
        .coreName               = 0x0u,             /* No coreName   */
        .tisciProcId            = 0x0u,             /* No ProcId for HC */
        .tisciDeviceId          = 0x0u,             /* No Device Id */
        .doneFlag               = false,            /* Initialize done flag */
    },
    /* C6X core 0 */
    {
        .testName           = "C6x core 0 PBIST",
        .PBISTRegsHiAddress = CSL_C66SS0_VBUSP_CFG_PBISTCFG_BASE,
        .pPBISTRegs         = (CSL_pbistRegs *)PBIST_REGION_LOCAL_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x00003fffu,         /* Choose Algorithm 1-14  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x0000000003fc1fe0u, /* Memory groups excludes 1-5, 14-18 */
            .scrambleValue      = 0xDCBA9876543210FEU, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_C66SS0_PBIST0,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_C66SS0_PBIST0_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = true,                /* Secondary core needed */
        .coreName               = "C6x core 0",        /* Primary core   */
        .secCoreName            = "C6x core 1",        /* Secondary core */
        .tisciProcId            = SCICLIENT_PROC_ID_K3_C66_COREPAC_MAIN_0_K3_C66_CGEM_288KB_0,  /* C6x core0 Proc Id */
        .tisciSecProcId         = SCICLIENT_PROC_ID_K3_C66_COREPAC_MAIN_1_K3_C66_CGEM_288KB_0,  /* C6x core1 Proc Id */
        .tisciDeviceId          = TISCI_DEV_K3_C66_COREPAC_MAIN_0,        /* C6x Core 0 Device Id */
        .tisciSecDeviceId       = TISCI_DEV_K3_C66_COREPAC_MAIN_1,        /* C6x Core 1 Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* C6X core 1 */
    {
        .testName           = "C6x core 1 PBIST",
        .PBISTRegsHiAddress = CSL_C66SS1_VBUSP_CFG_PBISTCFG_BASE,
        .pPBISTRegs         = (CSL_pbistRegs *)PBIST_REGION_LOCAL_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x00003fffu,         /* Choose Algorithm 1-14  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x000000000003e01fu, /* Memory groups 1-5, 14-18 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_C66SS1_PBIST0,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_C66SS1_PBIST0_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,              /* Initialize done flag */
        .secondaryCoreNeeded    = true,              /* Secondary core needed */
        .coreName               = "C6x core 1",      /* Primary core   */
        .secCoreName            = "C6x core 0",      /* Secondary core */
        .tisciProcId            = SCICLIENT_PROC_ID_K3_C66_COREPAC_MAIN_1_K3_C66_CGEM_288KB_0,  /* C6x core0 Proc Id */
        .tisciSecProcId         = SCICLIENT_PROC_ID_K3_C66_COREPAC_MAIN_0_K3_C66_CGEM_288KB_0,  /* C6x core1 Proc Id */
        .tisciDeviceId          = TISCI_DEV_K3_C66_COREPAC_MAIN_1,        /* C6x Core 0 Device Id */
        .tisciSecDeviceId       = TISCI_DEV_K3_C66_COREPAC_MAIN_0,        /* C6x Core 1 Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* MSMC */
    {
        .testName           = "MSMC PBIST",
        .PBISTRegsHiAddress = CSL_COMPUTE_CLUSTER0_MSMC_PBIST_BASE,
        .pPBISTRegs         = (CSL_pbistRegs *)PBIST_REGION_LOCAL_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x0fffffffu,         /* Choose Algorithm 1-28  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x001fffffffffffffu, /* Memory groups 1-53 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST7,   /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0,
        .procRstNeeded          = true,
        .secondaryCoreNeeded    = false,                /* Secondary core needed */
        .coreName               = "MSMC",               /* Primary core   */
        .tisciProcId            = 0x0u,                 /* No ProcId for MSMC */
        .tisciDeviceId          = TISCI_DEV_COMPUTE_CLUSTER0_EN_MSMC_DOMAIN, /* MSMC Device Id */
        .doneFlag               = false,               /* Initialize done flag */
    },
    /* Main Infra */
    {
        .testName           = "Main Infra PBIST",
        .PBISTRegsHiAddress = 0u,
        .pPBISTRegs         = (CSL_pbistRegs *)CSL_PBIST6_BASE,
        .PBISTConfig = {
            .algorithmsBitMap   = 0x1fffffffu,         /* Choose Algorithm 1-29  */
            .override           = 0x0u,
            /* Override bit set to 0 to use memoryGroupsBitMap */
            /* Can be set to (CSL_PBIST_OVER_RINFO_MASK << CSL_PBIST_OVER_RINFO_SHIFT) to enable all memory */
            /* NOTE: override set to 1 is not tested */
            .memoryGroupsBitMap = 0x000003ffffffffffu, /* Memory groups 1-42 */
            .scrambleValue      = 0xFEDCBA9876543210U, /* Scramble Value */
        },
        .tisciPBISTDeviceId     = TISCI_DEV_PBIST6,    /* PBIST device id  */
        .interruptNumber        = CSLR_MCU_R5FSS0_CORE0_INTR_PBIST6_DFT_PBIST_CPU_0,
        .procRstNeeded          = false,
        .secondaryCoreNeeded    = false,               /* Secondary core needed */
        .coreName               = 0x0u,                /* No coreName   */
        .tisciProcId            = 0x0u,                /* No Proc Id needed for Main Intrastructure */
        .tisciDeviceId          = 0x0u,                /* No Device Id needed for Main infrastructure */
        .doneFlag               = false,               /* Initialize done flag */
    },
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void PBIST_eventHandler( uint32_t instanceId)
{
    CSL_pbistRegs *pPBISTRegs = PBIST_TestHandleArray[instanceId].pPBISTRegs;
    CSL_ErrType_t status;

    /* Switch to Functional mode */
    CSL_PBIST_releaseTestMode( pPBISTRegs );

    if (instanceId == PBIST_INSTANCE_C7X)
    {
        /* Clear C7x PBIST interrupt event in CLEC */
        status = CSL_clecClearEvent((CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE,
                       CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_12);
        if (status != CSL_PASS) {
            /* This is really not expected in normal operation:
               Add exception if needed
            */
        }
    }
    if (instanceId == PBIST_INSTANCE_A72)
    {
        /* Clear A72 PBIST interrupt event in CLEC*/
        status = CSL_clecClearEvent((CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE,
                       CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_8);
        if (status != CSL_PASS) {
            /* This is really not expected in normal operation:
               Add exception if needed
            */
        }
    }

    PBIST_TestHandleArray[instanceId].doneFlag = true;

    return;
}

/* PBIST_setFirewall: Sets firewall settings to be able to access CLEC registers */
static int32_t PBIST_setFirewall(void)
{
    int32_t retVal = CSL_PASS;
    uint32_t reqFlag = TISCI_MSG_FLAG_AOP | TISCI_MSG_FLAG_DEVICE_EXCLUSIVE;
    uint32_t timeout =  SCICLIENT_SERVICE_WAIT_FOREVER;
    struct  tisci_msg_fwl_set_firewall_region_req request;
    Sciclient_ReqPrm_t reqParam;
    Sciclient_RespPrm_t respParam;

    request.fwl_id       = (uint32_t)CSL_STD_FW_NAVSS0_NAV_SRAM0_ID;
    request.region = (uint32_t) 0U; /* Pick up any unused region : 0 */
    request.n_permission_regs = CSL_FW_NUM_CBASS_FW_EP_REGION_PERMISSION;
    request.control = (FW_REGION_ENABLE & CSL_CBASS_ISC_EP_REGION_CONTROL_ENABLE_MASK);
    request.permissions[0] = (FW_MCU_R5F0_PRIVID << CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_SHIFT);
    request.permissions[1] = (FW_MCU_R5F0_PRIVID << CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_SHIFT);
    request.permissions[2] = (FW_MCU_R5F0_PRIVID << CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_SHIFT)
                             | (0U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_SHIFT)
                             | (1U << CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_SHIFT);
    request.start_address = CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;
    request.end_address = CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE + CSL_COMPUTE_CLUSTER0_CLEC_REGS_SIZE;

    reqParam.messageType    = (uint16_t) TISCI_MSG_SET_FWL_REGION;
    reqParam.flags          = (uint32_t) reqFlag;
    reqParam.pReqPayload    = (const uint8_t *) &request;
    reqParam.reqPayloadSize = (uint32_t) sizeof (request);
    reqParam.timeout        = (uint32_t) timeout;

    respParam.flags           = (uint32_t) 0;   /* Populated by the API */
    respParam.pRespPayload    = (uint8_t *) 0;
    respParam.respPayloadSize = (uint32_t) 0;


    if (((reqFlag & TISCI_MSG_FLAG_AOP) != TISCI_MSG_FLAG_AOP)&&
        (reqFlag != 0U))
    {
        retVal = CSL_EFAIL;
    }
    if (retVal == CSL_PASS)
    {
        retVal = Sciclient_service(&reqParam, &respParam);
    }
    if ((retVal != CSL_PASS) ||
        ((reqFlag != 0U) &&
        ((respParam.flags & TISCI_MSG_FLAG_ACK) != TISCI_MSG_FLAG_ACK)))
    {
        retVal = CSL_EFAIL;
    }
    return retVal;
}

/* Captures common Initialization: currently initializes CLEC interrupt routing
   for C7x & A72 */
int32_t PBIST_commonInit(void)
{
    CSL_ErrType_t status;
    int32_t retValue = 0;
    CSL_ClecEventConfig evtCfg;

    /* Add firewall entry to gain access to CLEC registers */
    status = PBIST_setFirewall();
    if (status != CSL_PASS)
    {
        UART_printf(" PBIST_setFirewall failed \n");
        retValue = -1;
    }

    if (retValue == 0)
    {
        evtCfg.secureClaimEnable = 1U;
        evtCfg.evtSendEnable = 1U;
        evtCfg.extEvtNum = CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_12;
        evtCfg.rtMap = 2U;
        evtCfg.c7xEvtNum = 0U;

        /* Configure interrupt router to take care of routing C7x PBIST interrupt event */
        status =  CSL_clecConfigEvent((CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE,
                                      CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_12,
                                      &evtCfg);
        if (status != CSL_PASS)
        {
            UART_printf(" CSL_clecConfigEvent C7x failed \n");
            retValue = -1;
        }
    }

    if (retValue == 0)
    {
        evtCfg.extEvtNum = CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_8;
        /* Configure interrupt router to take care of routing A72 PBIST interrupt event */
        status =  CSL_clecConfigEvent((CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE,
                                      CSLR_COMPUTE_CLUSTER0_CLEC_MSMC_EVENT_IN_COMPUTE_CLUSTER0_CORE_CORE_MSMC_INTR_8,
                                      &evtCfg);
        if (status != CSL_PASS)
        {
            UART_printf(" CSL_clecConfigEvent A72 failed \n");
            retValue = -1;
        }
    }
    return status;
}

int32_t PBIST_runTest(uint32_t instanceId)
{
    int32_t testResult = 0;
    CSL_ErrType_t status;
    HwiP_Params hwiParams;
    HwiP_Handle PBIST_hwiPHandle;
    CSL_pbistRegs *pPBISTRegs;
    Bool PBISTResult;
    uint32_t timeoutCount = 0;
    uint64_t startTime , testStartTime,  testEndTime, endTime;
    uint64_t prepTime, diffTime, restoreTime;
    CSL_RatTranslationCfgInfo translationCfg;
    bool result;
#ifdef DEBUG
    char inputChar;
#endif

    UART_printf("\n Starting PBIST test on %s, index %d...\n",
                PBIST_TestHandleArray[instanceId].testName,
                instanceId);

#ifdef DEBUG
    UART_printf("\n Press any key to continue...");
    inputChar = UART_getc();

    if (inputChar == 'n')
    {
        UART_printf("\n Skipping this test. on request \n");
        return 0;
    }
#endif

    /* Disable interrupt */
    HwiP_disableInterrupt(PBIST_TestHandleArray[instanceId].interruptNumber);

    /* Default parameter initialization */
    HwiP_Params_init(&hwiParams);

    /* Pass core Index as argument to handler*/
    hwiParams.arg = instanceId;
#ifdef DEBUG
    UART_printf("\n HwiP_Params_init complete \n");
#endif
    /* Register call back function for PBIST Interrupt */
    PBIST_hwiPHandle = HwiP_create(PBIST_TestHandleArray[instanceId].interruptNumber,
                                       (HwiP_Fxn)PBIST_eventHandler,
                                       (void *)&hwiParams);
    if (PBIST_hwiPHandle == NULL)
    {
        UART_printf(" Interrupt registration failed \n");
        testResult = -1;
    }

    /* Get start time of test */
    startTime = TimerP_getTimeInUsecs();

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        if (PBIST_TestHandleArray[instanceId].tisciProcId != 0u)
        {
#ifdef DEBUG
            UART_printf("  Primary core: %s: Requesting processor \n",
                        PBIST_TestHandleArray[instanceId].coreName);
#endif
            /* Request Primary core */
            status = Sciclient_procBootRequestProcessor(PBIST_TestHandleArray[instanceId].tisciProcId,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Primary core: Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                            PBIST_TestHandleArray[instanceId].tisciProcId);
                testResult = -1;
            }
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        if ((PBIST_TestHandleArray[instanceId].secondaryCoreNeeded)
            && (PBIST_TestHandleArray[instanceId].tisciSecProcId != 0u))
        {

#ifdef DEBUG
            UART_printf("  Secondary core: %s: Requesting processor \n",
                    PBIST_TestHandleArray[instanceId].secCoreName);
#endif
            /* Request secondary core */
            status = Sciclient_procBootRequestProcessor(PBIST_TestHandleArray[instanceId].tisciSecProcId,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                            PBIST_TestHandleArray[instanceId].tisciSecProcId);
                testResult = -1;
            }
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        if (PBIST_TestHandleArray[instanceId].tisciDeviceId != 0u)
        {
            /* Set Module reset for Primary core */
#ifdef DEBUG
            UART_printf("  %s: Primary core: Set module reset \n",
                        PBIST_TestHandleArray[instanceId].coreName);
#endif
            status =  Sciclient_pmSetModuleRst(PBIST_TestHandleArray[instanceId].tisciDeviceId,
                                                 0x1,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Primary core: Sciclient_pmSetModuleRst...FAILED \n");
                testResult = -1;
            }
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        if ((PBIST_TestHandleArray[instanceId].secondaryCoreNeeded)
            && (PBIST_TestHandleArray[instanceId].tisciSecDeviceId != 0u))
        {
            /* Set Module reset for Secondary core */
#ifdef DEBUG
            UART_printf("  %s: Secondary core: Set Module reset \n",
                        PBIST_TestHandleArray[instanceId].secCoreName);
#endif
            status =  Sciclient_pmSetModuleRst(PBIST_TestHandleArray[instanceId].tisciSecDeviceId,
                                                 0x1,
                                                 SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_pmSetModuleRst...FAILED \n");
                testResult = -1;
            }
        }
    }
#ifdef POWERUP_CORES
    /* The following sequence is needed to restore core to normal operation */
    /* Some cores also need to be explicitly powered up, such as DMPAC */
    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded)
                          && (PBIST_TestHandleArray[instanceId].tisciDeviceId != NULL))
    {
        /* power on Primary core*/
#ifdef DEBUG
        UART_printf("  Primary core: Powering on %s \n",
                    PBIST_TestHandleArray[instanceId].coreName);
#endif
        status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciDeviceId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            TISCI_MSG_FLAG_AOP,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);

        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_pmSetModuleState 0x%x ...FAILED \n",
                        PBIST_TestHandleArray[instanceId].tisciDeviceId);
            testResult = -1;
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded)
                          && (PBIST_TestHandleArray[instanceId].tisciSecDeviceId != NULL))
    {
        if (PBIST_TestHandleArray[instanceId].secondaryCoreNeeded)
        {
            /* power on Secondary core*/
#ifdef DEBUG
            UART_printf("  Secondary core: Powering on %s \n",
                        PBIST_TestHandleArray[instanceId].secCoreName);
#endif
            status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciSecDeviceId,
                                                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                                TISCI_MSG_FLAG_AOP,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_pmSetModuleState 0x%x ...FAILED \n",
                            PBIST_TestHandleArray[instanceId].tisciSecDeviceId);
                testResult = -1;
                return testResult;
            }
        }
    }
#endif /* #ifdef POWERUP_CORES */

    /* Power up PBIST */
    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId != 0u))
    {
#ifdef DEBUG
        UART_printf("  Powering on PBIST %d \n",
                    PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId);
#endif
        status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            TISCI_MSG_FLAG_AOP,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);

        if (status != CSL_PASS)
        {
            UART_printf("   PBIST Sciclient_pmSetModuleState 0x%x ...FAILED: retValue %d\n",
                        PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId, status);
            testResult = -1;
        }
    }

    /* Get PBIST register space Pointer */
    pPBISTRegs = PBIST_TestHandleArray[instanceId].pPBISTRegs;

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].PBISTRegsHiAddress != 0u))
    {
        /* Add RAT configuration to access address > 32bit address range */
        translationCfg.translatedAddress = PBIST_TestHandleArray[instanceId].PBISTRegsHiAddress;
        translationCfg.sizeInBytes = PBIST_REG_REGION_SIZE;
        translationCfg.baseAddress = (uint32_t)pPBISTRegs;

        /* Set up RAT translation */
        result = CSL_ratConfigRegionTranslation((CSL_ratRegs *)CSL_MCU_ARMSS_RAT_CFG_BASE,
                                                PBIST_RAT_REGION_INDEX, &translationCfg);
        if (result == false) {
            UART_printf("   CSL_ratConfigRegionTranslation...FAILED \n");
            testResult = -1;
        }
    }
    PBIST_TestHandleArray[instanceId].doneFlag = false;

    /* Get start time for PBIST test */
    testStartTime = TimerP_getTimeInUsecs();

    if (testResult == 0)
    {
#ifdef DEBUG
        UART_printf("\n Starting CSL_PBIST_softReset \n");
#endif

        /* Run PBIST test */
        status = CSL_PBIST_softReset(pPBISTRegs);
        if (status != CSL_PASS)
        {
            UART_printf(" CSL_PBIST_softReset failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
#ifdef DEBUG
        UART_printf("\n Starting CSL_PBIST_start \n");
#endif
        status = CSL_PBIST_start(pPBISTRegs, &PBIST_TestHandleArray[instanceId].PBISTConfig);
        if (status != CSL_PASS)
        {
            UART_printf(" CSL_PBIST_start failed\n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        /* Timeout if exceeds time */
        while ((!PBIST_TestHandleArray[instanceId].doneFlag)
               && (timeoutCount++ < PBIST_MAX_TIMEOUT_VALUE));

        if (!(PBIST_TestHandleArray[instanceId].doneFlag))
        {
            UART_printf(" PBIST test timed out \n");
            testResult = -1;
        }
        /* reset Done flag so we can run again */
        PBIST_TestHandleArray[instanceId].doneFlag = false;
    }

    if (testResult == 0)
    {
#ifdef DEBUG
        UART_printf("\n Starting CSL_PBIST_checkResult \n");
#endif
        status = CSL_PBIST_checkResult(pPBISTRegs, &PBISTResult);
        if (status != CSL_PASS)
        {
            UART_printf(" CSL_PBIST_checkResult failed\n");
            testResult = -1;
        }
        else
        {
            /* Check the PBIST result */
            if (PBISTResult != true)
            {
                UART_printf("\n PBIST test failed\n");
                testResult = -1;
            }
        }
    }

    /* Record test end time */
    testEndTime = TimerP_getTimeInUsecs();

#ifdef POWERUP_CORES
    /* The following sequence is needed to restore core to normal operation */
    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].tisciProcId != 0u)
                    && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        /* power on Primary core*/
#ifdef DEBUG
        UART_printf("  Primary core: Powering on %s \n",
                    PBIST_TestHandleArray[instanceId].coreName);
#endif
        status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciDeviceId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            TISCI_MSG_FLAG_AOP,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);

        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_pmSetModuleState Power on 0x%x ...FAILED \n",
                        PBIST_TestHandleArray[instanceId].tisciDeviceId);
            testResult = -1;
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        if (PBIST_TestHandleArray[instanceId].secondaryCoreNeeded)
        {
            /* power on Secondary core*/
#ifdef DEBUG
            UART_printf("  Secondary core: Powering on %s \n",
                        PBIST_TestHandleArray[instanceId].secCoreName);
#endif
            status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciSecDeviceId,
                                                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                                TISCI_MSG_FLAG_AOP,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_pmSetModuleState Power on 0x%x ...FAILED \n",
                            PBIST_TestHandleArray[instanceId].tisciSecDeviceId);
                testResult = -1;
                return testResult;
            }
        }
    }
#endif
    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].PBISTRegsHiAddress != 0u))
    {
        /* Disable RAT translation */
        result = CSL_ratDisableRegionTranslation((CSL_ratRegs *)CSL_MCU_ARMSS_RAT_CFG_BASE,
                                                PBIST_RAT_REGION_INDEX);
        if (result == false) {
            UART_printf("   CSL_ratDisableRegionTranslation...FAILED \n");
            testResult = -1;
        }
    }

    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].tisciProcId != 0u)
            && (PBIST_TestHandleArray[instanceId].procRstNeeded))
    {
        /* release processor Primary core */
#ifdef DEBUG
        UART_printf("  Primary core: Releasing %s \n",
                    PBIST_TestHandleArray[instanceId].coreName);
#endif

        status = Sciclient_procBootReleaseProcessor(PBIST_TestHandleArray[instanceId].tisciProcId,
                                                    TISCI_MSG_FLAG_AOP,
                                                    SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status != CSL_PASS)
        {
            UART_printf("   Primary core: Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                        PBIST_TestHandleArray[instanceId].tisciProcId);
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        if ((PBIST_TestHandleArray[instanceId].secondaryCoreNeeded)
            && (PBIST_TestHandleArray[instanceId].tisciSecProcId != 0u)
            && (PBIST_TestHandleArray[instanceId].procRstNeeded))
        {
            /* release processor Secondary core */
#ifdef DEBUG
            UART_printf("  Secondary core: Releasing %s \n",
                        PBIST_TestHandleArray[instanceId].secCoreName);
#endif
            status = Sciclient_procBootReleaseProcessor(PBIST_TestHandleArray[instanceId].tisciSecProcId,
                                                        TISCI_MSG_FLAG_AOP,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                UART_printf("   Secondary core: Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                            PBIST_TestHandleArray[instanceId].tisciSecProcId);
                testResult = -1;
            }
        }
    }
    /* Power off PBIST */
    if ((testResult == 0) && (PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId != 0u))
    {
#ifdef DEBUG
        UART_printf("  Powering off PBIST %d \n",
                    PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId);
#endif
        status = Sciclient_pmSetModuleState(PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                            TISCI_MSG_FLAG_AOP,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);

        if (status != CSL_PASS)
        {
            UART_printf("   PBIST Sciclient_pmSetModuleState 0x%x ...FAILED \n",
                        PBIST_TestHandleArray[instanceId].tisciPBISTDeviceId);
            testResult = -1;
        }
    }

    /* Record end time */
    endTime = TimerP_getTimeInUsecs();

    prepTime = testStartTime - startTime;
    diffTime = testEndTime - testStartTime;
    restoreTime = endTime - testEndTime;
    UART_printf("  Delta Cores prep time in micro secs %d \n", (uint32_t)prepTime );
    UART_printf("  Delta PBIST execution time in micro secs %d \n", (uint32_t)diffTime );
    UART_printf("  Delta Cores restore time in micro secs %d \n", (uint32_t)restoreTime );
    UART_printf(" PBIST complete %s, test index %d\n",
                PBIST_TestHandleArray[instanceId].testName,
                instanceId);

    return (testResult);
}

/* PBIST Functional test */
int32_t PBIST_funcTest(void)
{
    int32_t    testResult = 0;
    int i;

    testResult = PBIST_commonInit();

    if (testResult != 0)
    {
        UART_printf("  PBIST_commonInit ...FAILED \n");
    }
    else
    {
        for (i = 0; i < PBIST_NUM_INSTANCE; i++)
        {
            /* Run test on selected instance */
            testResult = PBIST_runTest(i);
            if ( testResult != 0)
            {
                break;
            }
        }
    }

    return (testResult);
}

/* Nothing past this point */
