/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file   diag_common_cfg.c
 *
 *  \brief  Common functions used by diagnostic tests modules.
 *
 *  This file contains the utils functions which are common for different
 *  interfaces of given platform and used by diagnostic test modules.
 *
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/tistdtypes.h>
#include <ti/board/board.h>
#include <diag_common_cfg.h>
#include <ti/osal/osal.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#if defined (__aarch64__)
#include <ti/csl/arch/a53/interrupt.h>
#include <ti/csl/arch/a53/csl_a53v8cache.h>
#include <ti/csl/arch/a53/src/startup/aarch64/boot_defs.h>

extern void (*__init_array_start []) (void);
extern void (*__init_array_end []) (void);
extern unsigned int __bss_start__, __bss_end__;
extern unsigned int __bss_common_start__, __bss_common_end__;
extern unsigned int __data_load__, __data_start__, __data_end__;
extern int main();
uint32_t start_boot_diag(void);

__attribute__((aligned(4096))) uint64_t gCSLa53Mmulevel1TableDiag[CSL_a53Mmu_NUM_LEVEL1_ENTRIES];
__attribute__((aligned(4096))) uint64_t gCSLa53Mmulevel2TableDiag[CSL_a53Mmu_NUM_LEVEL1_ENTRIES];

static void BoardDiag_SetMAIR(uint8_t idx, uint16_t attr)
{
    CSL_a53v8SetMAIR(idx, attr);
    //CSL_a53v8InvTLB();
    return;
}

static void BoardDiag_mmuStartup(void)
{
    uint32_t idx;
    uint64_t addr, desc;
    CSL_a53MmuDescAttrs attrs;

    /* Device memory attributes for 0x0 - 0x3FFFFFFF address space */
    attrs.type = CSL_a53Mmu_DescType_BLOCK;
    attrs.nsTable        = FALSE;
    attrs.apTable        = 0u;
    attrs.xnTable        = FALSE;
    attrs.pxnTable       = FALSE;
    attrs.noExecute      = TRUE;
    attrs.privNoExecute  = FALSE;
    attrs.contiguous     = FALSE;
    attrs.notGlobal      = FALSE;
    attrs.accessFlag     = TRUE;
    attrs.shareable      = 0x2; /* Outer shareable */
    attrs.accPerm        = 0x10; /* RW at EL1 only */
    attrs.nonSecure      = TRUE;
    attrs.attrIndx       = 0;
    attrs.reserved       = 0u;

    desc = CSL_mmuInitLevel1Desc(0x0, &attrs);
    gCSLa53Mmulevel1TableDiag[0] = desc;


    /* Table pointer for 0x40000000 - 0x7FFFFFFF address space */
    attrs.type = CSL_a53Mmu_DescType_TABLE;
    attrs.nsTable = FALSE;
    attrs.apTable = 0;
    attrs.xnTable = FALSE;
    attrs.pxnTable = FALSE;

    desc = CSL_mmuInitLevel1Desc((uint64_t)&gCSLa53Mmulevel2TableDiag[0], &attrs);
    gCSLa53Mmulevel1TableDiag[1] = desc;

    /* Normal memory attributes for 0x80000000 - 0xFFFFFFFF address space */
    attrs.type = CSL_a53Mmu_DescType_BLOCK;
    attrs.noExecute = TRUE;
    attrs.privNoExecute = FALSE;
    attrs.contiguous = FALSE;
    attrs.notGlobal = FALSE;
    attrs.accessFlag = TRUE;
    attrs.shareable = 0x2; /* Outer shareable */
    attrs.accPerm = 0x10; /* RW at EL1 only */
    attrs.nonSecure = TRUE;
    attrs.attrIndx = 1;

    desc = CSL_mmuInitLevel1Desc(0x80000000, &attrs);
    gCSLa53Mmulevel1TableDiag[2] = desc;
    desc = CSL_mmuInitLevel1Desc(0xC0000000, &attrs);
    gCSLa53Mmulevel1TableDiag[3] = desc;

    /* Device memory attributes for 0x40000000 - 0x6FFFFFFF address space */
    attrs.type = CSL_a53Mmu_DescType_BLOCK;
    attrs.noExecute = TRUE;
    attrs.privNoExecute = FALSE;
    attrs.contiguous = FALSE;
    attrs.notGlobal = FALSE;
    attrs.accessFlag = TRUE;
    attrs.shareable = 0x2; /* Outer shareable */
    attrs.accPerm = 0x10; /* RW at EL1 only */
    attrs.nonSecure = TRUE;
    attrs.attrIndx = 0;

    /* 1GB for FSS0 OSPI0 */
    desc = CSL_mmuInitLevel1Desc(0x400000000, &attrs);
    gCSLa53Mmulevel1TableDiag[16] = desc;
    /* 1GB for FSS0 OSPI1 */
    desc = CSL_mmuInitLevel1Desc(0x600000000, &attrs);
    gCSLa53Mmulevel1TableDiag[24] = desc;

    /* 4GB DDR memory for 64-bit access */
    desc = CSL_mmuInitLevel1Desc(0x900000000, &attrs);
    gCSLa53Mmulevel1TableDiag[36] = desc;
    desc = CSL_mmuInitLevel1Desc(0x940000000, &attrs);
    gCSLa53Mmulevel1TableDiag[37] = desc;
    desc = CSL_mmuInitLevel1Desc(0x980000000, &attrs);
    gCSLa53Mmulevel1TableDiag[38] = desc;
    desc = CSL_mmuInitLevel1Desc(0x9C0000000, &attrs);
    gCSLa53Mmulevel1TableDiag[39] = desc;

    for (idx = 0, addr = 0x40000000; addr < 0x70000000; idx++, addr+=0x200000) {
      desc = CSL_mmuInitLevel2Desc(addr, &attrs);
      gCSLa53Mmulevel2TableDiag[idx] = desc;
    }

    /* Normal memory attributes for 0x70000000 - 0x7FFFFFFF address space */
    attrs.type = CSL_a53Mmu_DescType_BLOCK;
    attrs.noExecute = TRUE;
    attrs.privNoExecute = FALSE;
    attrs.contiguous = FALSE;
    attrs.notGlobal = FALSE;
    attrs.accessFlag = TRUE;
    attrs.shareable = 0x2; /* Outer shareable */
    attrs.accPerm = 0x10; /* RW at EL1 only */
    attrs.nonSecure = TRUE;
    attrs.attrIndx = 1;

    for (; addr < 0x80000000; idx++, addr+=0x200000) {
      desc = CSL_mmuInitLevel2Desc(addr, &attrs);
      gCSLa53Mmulevel2TableDiag[idx] = desc;
    }

    BoardDiag_SetMAIR(0, 0x00);
    BoardDiag_SetMAIR(1, 0x44);

    CSL_mmuInit((uintptr_t)&gCSLa53Mmulevel1TableDiag[0]);
    CSL_a53v8WriteTCREL1(0x500000019);

    CSL_a53v8EnableMMUEl1();
}

uint32_t start_boot_diag(void)
{
    unsigned int * bs;
    unsigned int * be;
    unsigned int * dl;
    unsigned int * ds;
    unsigned int * de;
    uint64_t      cpuId;
    uint8_t       coreId;

    cpuId = CSL_a53v8GetCpuId();
    coreId = (uint8_t) cpuId & (uint8_t)0xFFU;

    /* initiailize .bss to zero */
    bs = & __bss_start__;
    be = & __bss_end__;
    while (bs < be) {
        *bs = 0;
        bs++;
    }

    /* initiailize .bss common to zero */
    bs = & __bss_common_start__;
    be = & __bss_common_end__;
    while (bs < be) {
        *bs = 0;
        bs++;
    }

    /* relocate the .data section */
    dl = & __data_load__;
    ds = & __data_start__;
    de = & __data_end__;
    if (dl != ds) {
        while (ds < de) {
            *ds = *dl;
            dl++;
            ds++;
        }
    }
    CSL_cacheEnable();
    BoardDiag_mmuStartup();

    /* Initialize the GIC V3 */
    Intc_Init(coreId);

    /* Calling the main */
    return(main());
}
#else
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/csl_arm_r5_mpu.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/osal/src/nonos/Nonos_config.h>

extern TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices];

/* Below srtucture overrides the default MPU configurations in CSL to disable
 * caching for memory used by diagnostic tests
 */
const CSL_ArmR5MpuRegionCfg  gCslR5MpuCfg[CSL_ARM_R5F_MPU_REGIONS_MAX] = 
{
    {
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 0U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_4GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 1U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,
        .memAttr          = 0U,
    },
    {
        /* Region 1 configuration: 128 bytes memory for exception vector execution */
        .regionId         = 1U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_128B,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 2 configuration: 512 KB OCMS RAM */
        .regionId         = 2U,
        .enable           = 1U,
        .baseAddr         = 0x41C00000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_512KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 4U,
    },
    {
        /* Region 3 configuration: 2 MB MCMS3 RAM */
        .regionId         = 3U,
        .enable           = 1U,
        .baseAddr         = 0x70000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_8MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 4U,
    },
    {
        /* Region 4 configuration: 2 GB DDR RAM */
        .regionId         = 4U,
        .enable           = 1U,
        .baseAddr         = 0x80000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_2GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 5 configuration: 32 KB BTCM */
        /* Address of ATCM/BTCM are configured via MCU_SEC_MMR registers
           It can either be '0x0' or '0x41010000'. Application/Boot-loader shall
           take care this configurations and linker command file shall be
           in sync with this. For either of the above configurations,
           MPU configurations will not changes as both regions will have same
           set of permissions in almost all scenarios.
           Application can chose to overwrite this MPU configuration if needed.
           The same is true for the region corresponding to ATCM. */
        .regionId         = 5U,
        .enable           = 1U,
        .baseAddr         = 0x41010000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
        .memAttr          = 0U,
    },
    {
        /* Region 6 configuration: 128 MB FSS DAT */
        .regionId         = 6U,
        .enable           = 0U,
        .baseAddr         = 0x50000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_128MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
    {
        /* Region 7 configuration: 32 KB ATCM */
        .regionId         = 7U,
        .enable           = 1U,
        .baseAddr         = 0x0,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
        .memAttr          = 0U,
    },
};

/**
 * \brief  Function to disable timer interrupts
 *
 * OSAL uses timer interrupt to track the timestamp overflow.
 * Timer interrupts triggered while diagnostic test is invoked from
 * framework are causing exception. This function disables timer interrupts.
 * All the diagnostic tests should call this function befor main
 * to avoid exceptions while executing on R5 core.
 *
 */
void BoardDiag_timerIntrDisable(void)
{
    uint32_t timerCnt;

    /* Call OSAL delay function to trigger the timer
     * configurations inside OSAL.
     */
    Osal_delay(1);

    /* Disable all the timer interrupts */
    for (timerCnt = 0; timerCnt < TimerP_numTimerDevices; timerCnt++)
    {
        Intc_IntDisable(gDmTimerPInfoTbl[timerCnt].intNum);
    }
}
#endif

/**
 * \brief  Diagnostic init function
 *
 * This function includes the common initialization sequence for 
 * diagnostic tests.
 *
 * \return
 *          1  - In case of success
 *          0  - In case of failure
 *
 */
Board_STATUS DIAG_init(void)
{
    Board_initCfg boardCfg;
    Board_STATUS status;
    
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_DEFAULT;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    
    return(status);
}

/**
 * \brief  Compares two data buffers
 *
 * This function verifies the data in two buffers passed as parameters and
 * returns the result. 'failIndex' contains the index of the first mismatch
 * when buffer comparision fails.
 *
 * \param   buf1      [IN]   Data buffer 1
 * \param   buf2      [IN]   Data buffer 2
 * \param   length    [IN]   Length of the buffers
 * \param   failIndex [OUT]  Index of first data mismatch
 *
 * \return
 *          1  - In case of success
 *          0  - In case of failure
 *
 */
bool BoardDiag_memCompare(uint8_t *buf1, uint8_t *buf2, uint32_t length,  
                          uint32_t *failIndex)
{
    uint32_t idx = 0;
    bool match   = 1;
    
    for(idx = 0; ((idx < length) && (match == 1)); idx++)
    {
        if(buf1[idx] != buf2[idx])
        {
            match      = 0;
            *failIndex = idx;
        }            
    }

    return (match);
}

/**
 * \brief  Generate test pattern function
 *
 * This function fills the data buffer passed as input parameter with
 * different test patterns as indicated by 'flag' parameter.
 * Below are the different test patterns supported
 *
 * BOARD_DIAG_TEST_PATTERN_FF     - Fills the buffer with 0xFF
 * BOARD_DIAG_TEST_PATTERN_AA     - Fills the buffer with 0xAA
 * BOARD_DIAG_TEST_PATTERN_55     - Fills the buffer with 0x55
 * BOARD_DIAG_TEST_PATTERN_NULL   - Fills buffer with 0
 * BOARD_DIAG_TEST_PATTERN_RANDOM - Fills the buffer with randon pattern
 * BOARD_DIAG_TEST_PATTERN_INC    - Fills the buffer with increment pattern
 *                                  starting from 0
 * BOARD_DIAG_TEST_PATTERN_AA_55  - Fills the buffer with 0xAA in even locations
 *                                  0x55 in odd locations
 *
 * If 'flag' does match with any of the above values, buffer will be filled
 * with 0 by default.
 *
 * \param   buf    [IN]   Buffer to fill with the test pattern
 * \param   length [IN]   Length of the buffer
 * \param   flag   [IN]   Flag to set the test pattern
 *
 */
void BoardDiag_genPattern(uint8_t *buf, uint32_t length, uint8_t flag)
{
    uint8_t data         = 0;
    uint8_t incFlag      = 0;
    uint8_t randFlag     = 0;
    uint8_t checkerBoard = 0;
    uint32_t idx;

    switch(flag)
    {
        case BOARD_DIAG_TEST_PATTERN_FF:
        case BOARD_DIAG_TEST_PATTERN_AA:
        case BOARD_DIAG_TEST_PATTERN_55:
        case BOARD_DIAG_TEST_PATTERN_NULL:
             data = flag;
             break;
        case BOARD_DIAG_TEST_PATTERN_INC:
             data    = 0;
             incFlag = 1;
             break;
        case BOARD_DIAG_TEST_PATTERN_RANDOM:
             data     = rand();
             randFlag = 1;
        case BOARD_DIAG_TEST_PATTERN_AA_55:
             data         = 0xAA;
             checkerBoard = 1;
             break;
        default:
             data = flag;
             break;
    }

    for(idx = 0; idx < length; idx++)
    {
        buf[idx] = data;
        
        if(incFlag)
            data++;
        
        if(randFlag)
            data = rand();

        if(checkerBoard)
            data = ~data;
    }
}

/**
 * \brief    This API reads a byte from the Receiver Buffer Register
 *           (RBR). It checks once if any character is ready to be read.
 *
 * Note: When UART driver is used through STDIO interface,it is not possible
 * to read the data without waiting forever. This API will be useful in such 
 * cases.
 *
 * \param    instance     Memory address of the UART instance being used.
 *
 * \return   value of RHR register
 */

int8_t BoardDiag_getUserInput(uint8_t instance)
{
    uint32_t baseAddr = uartInitCfg[instance].baseAddr;

    return UARTCharGetNonBlocking(baseAddr);
}

/**
 * \brief    This API Enables the main I2C instances
 *
 * \param    instance [IN] I2C instance number.
 * \param    baseAddr [IN] Register base address of the I2C instance.
 */
void enableMAINI2C(uint8_t instance, uint32_t baseAddr)
{
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(instance, &i2cCfg);

    i2cCfg.baseAddr = baseAddr;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(instance, &i2cCfg);
}

/**
 * \brief    This API Enables the I2C instances
 *
 * \param    baseAddr [IN] Register base address of the I2C instance.
 */
void enableI2C(uint32_t baseAddr)
{
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(0, &i2cCfg);

    i2cCfg.baseAddr = baseAddr;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(0, &i2cCfg);
}
