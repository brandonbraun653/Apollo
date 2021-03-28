/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017-2019
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
#include <stdint.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>

#include <ti/osal/osal.h>
#include <ti/csl/csl_cpIntcAux.h>
#include <ti/csl/arch/a15/V0/csl_a15.h>
#include "ecc_emif.h"

/* ----------------- Constant definitions ----------------- */

/* -------------------------------------------------------- */

/* ----------------- Function prototypes ------------------ */
static int32_t emifSecErrTest();
static int32_t emifDedErrTest();
static int32_t emifNonEccQuantaAlignAddrErrTest();
static int32_t emifByteCntWRAccessNotMultEccQuantaErrTest();

static void emifEccConfig();
static void emifEccInit(char option);

#if defined (_TMS320C6X)
HwiP_Handle enableCICIntrConfig();
void disableCICIntrConfig(HwiP_Handle handle);
#endif
/* -------------------------------------------------------- */


/* ----------------- Global variables ----------------- */
emifEccErrInfo_t   gEmifErrInfo;
/* ---------------------------------------------------- */

/* Interrupt handler for Emif Single bit error 
 * Just checks and clears error status as the correction happens
 * automatically
 */
void isrEmifSecErr()
{
    int32_t retVal = STW_SOK;
    gErrStatus = EMIFGetIntrStatus(EMIF_APP_INST);
    retVal     = EMIFConfigECCGetEccErrInfo(EMIF_APP_INST,
                                            EMIF_ERR_ECC_ONEBIT,
                                            &gEmifErrInfo);
    if (retVal != STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n NULL Pointer Detected : gEmifErrInfo", -1);
    }

    UARTConfigPuts(uartBaseAddr, "\r\n Strucked the ISR", -1);
    EMIFClearIntrStatus(
        EMIF_APP_INST,
        EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_ONEBIT_ECC_ERR_SYS_MASK);

#if defined (_TMS320C6X)
    MuxIntcP_clearInEvent(0,EMIF_MUX_INPUT_EVENT);
#else
    HwiP_clearInterrupt(EMIF_ECC_ERR_INT);
#endif
}

/* Interrupt handler for Emif Double bit error
 * This writes back the original pattern to fix error
 * NOTE: In real application this may need to be handled as a serious
 * error based on application needs.
 */
void isrEmifDedErr()
{
    int32_t retVal = STW_SOK;

    gTest_Addr = NULL;

    gErrStatus = EMIFGetIntrStatus(EMIF_APP_INST);
    retVal     = EMIFConfigECCGetEccErrInfo(EMIF_APP_INST,
                                            EMIF_ERR_ECC_TWOBIT,
                                            &gEmifErrInfo);
    if (retVal != STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n NULL Pointer Detected : gEmifErrInfo", -1);
    }

    UARTConfigPuts(uartBaseAddr, "\r\n Strucked the ISR", -1);
    EMIFClearIntrStatus(
        EMIF_APP_INST,
        EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_TWOBIT_ECC_ERR_SYS_MASK);
    EMIFConfigECCDisableEcc(EMIF_APP_INST);
    gTest_Addr    = (uint32_t *) (gEmifErrInfo.errAddr[0] + EMIF_START_ADDR);
    gTest_Addr[0] = PATTERN_DATA;
    EMIFConfigECCEnableEcc(EMIF_APP_INST);
 
#if defined (_TMS320C6X)
    MuxIntcP_clearInEvent(0,EMIF_MUX_INPUT_EVENT);
#else
    HwiP_clearInterrupt(EMIF_ECC_ERR_INT);
#endif
}

/* Interrupt handler for Non ECC Quanta align address error
 * Just checks error and clears error status
 */
void isrEmifNonEccQuantaAlignAddrErr()
{
    gErrStatus = EMIFGetIntrStatus(EMIF_APP_INST);
    EMIFClearIntrStatus(
        EMIF_APP_INST,
        EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_WR_ECC_ERR_SYS_MASK);

#if defined (_TMS320C6X)
    MuxIntcP_clearInEvent(0,EMIF_MUX_INPUT_EVENT);
#else
    HwiP_clearInterrupt(EMIF_ECC_ERR_INT);
#endif
}

/* Interrupt handler for access of byte count less than Quanta size
 * Just checks error and clears error status
 */
void isrEmifByteCntWRAccessNotMultEccQuantaErr()
{
    gErrStatus = EMIFGetIntrStatus(EMIF_APP_INST);
    EMIFClearIntrStatus(
        EMIF_APP_INST,
        EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_WR_ECC_ERR_SYS_MASK);

#if defined (_TMS320C6X)
    MuxIntcP_clearInEvent(0,EMIF_MUX_INPUT_EVENT);
#else
    HwiP_clearInterrupt(EMIF_ECC_ERR_INT);
#endif
}

/* Function handles Emif test sub menu */
void mainSubMenuEmifEccTest(char *option)
{
    while (1)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n\r\n**** EMIF ECC TEST ****", -1);
        UARTConfigPuts(uartBaseAddr, "\r\nMenu:", -1);
        UARTConfigPuts(uartBaseAddr, "\r\n1. EMIF NON ECC QUANTA ALIGNED ADDRESS test", -1);
        UARTConfigPuts(uartBaseAddr,
            "\r\n2. EMIF BYTE COUNT WRITE ACCESS NOT MULTIPLE OF ECC QUANTA test",
            -1);
        UARTConfigPuts(uartBaseAddr, "\r\n3. EMIF SEC ERR ECC test", -1);
        UARTConfigPuts(uartBaseAddr, "\r\n4. EMIF DED ERR ECC test", -1);
        UARTConfigPuts(uartBaseAddr, "\r\nx. Exit", -1);
        UARTConfigPuts(uartBaseAddr, "\r\nSelect EMIF ECC TEST : ", -1);
        /* Get option */
        UARTConfigGets(uartBaseAddr, option, 1);

        if (EMIF_ECC_SEC_ERR_TEST == *option ||
            EMIF_ECC_DED_ERR_TEST == *option ||
            EMIF_ECC_NON_QUANTA_ALIGN_ADDR_ERR_TEST == *option ||
            EMIF_ECC_BYTECOUNT_WRITEACCESS_NOTMULTIPLE_ECCQUANTA_ERR_TEST
            == *option || EXIT(*option))
        {
            break;
        }
        else
        {
            UARTConfigPuts(uartBaseAddr, "\r\nEnter Valid option\r\n", -1);
        }
    }
}

/* Function executes Emif ECC Test */
int32_t emifEccTest(void)
{
    int32_t retVal = STW_SOK;
    char    mainSubMenuOption;
    uint32_t skipEmifTest = FALSE;
#if defined (_TMS320C6X)
	gInterruptNum = (EMIF_ECC_ERR_INT);
#endif

#if defined (_TMS320C6X)
    HwiP_Handle intrhandle;
    intrhandle = enableCICIntrConfig();
#else
    CSL_a15DisableCache();
#endif

    while (1)
    {
        if (skipEmifTest == FALSE)
        {
            mainSubMenuEmifEccTest(&mainSubMenuOption);

            emifEccInit(mainSubMenuOption);
        }
        else
        {
            /* select exit option */
            mainSubMenuOption = 'x';
        }

        if (EMIF_ECC_NON_QUANTA_ALIGN_ADDR_ERR_TEST == mainSubMenuOption)
        {
            retVal = emifNonEccQuantaAlignAddrErrTest();
        }
        else if (EMIF_ECC_BYTECOUNT_WRITEACCESS_NOTMULTIPLE_ECCQUANTA_ERR_TEST
                 == mainSubMenuOption)
        {
            retVal = emifByteCntWRAccessNotMultEccQuantaErrTest();
        }
        else if (EMIF_ECC_SEC_ERR_TEST == mainSubMenuOption)
        {
            retVal = emifSecErrTest();
        }
        else if (EMIF_ECC_DED_ERR_TEST == mainSubMenuOption)
        {
            retVal = emifDedErrTest();
        }
        else
        {
#if defined (_TMS320C6X)
			disableCICIntrConfig(intrhandle);
#endif
            UARTConfigPuts(uartBaseAddr, "\r\nEMIF ECC test exiting...", -1);
            break;
        }
    }
    return retVal;
}

/* Function initialized Emif ECC */
static void emifEccInit(char option)
{
    emifEccCfgPrm_t          cfgPrm;
    int32_t                  retVal = STW_SOK, i;
    emifEccAddrRangeCfgPrm_t addrRangeCfgPrm;

    cfgPrm.addrRangeCfgPrm = &addrRangeCfgPrm;

    cfgPrm.emifStartAddr = EMIF_START_ADDR;
    cfgPrm.addrRangeCfgPrm->startAddr       = EMIF_ECC_START_ADDR;
    cfgPrm.addrRangeCfgPrm->endAddr         = EMIF_ECC_END_ADDR;
    cfgPrm.addrRangeCfgPrm->addrRangeNum    = EMIF_ECC_ADDR_RANGE_NUM_1;
    cfgPrm.addrRangeCfgPrm->addrRangeType   = EMIF_ECC_ADDR_RANGE_WITHIN;
    cfgPrm.addrRangeCfgPrm->enableAddrRange = FALSE;
    cfgPrm.thresholdVal = EMIF_ECC_1B_ERR_THRSH_VAL;
    cfgPrm.enableRmw = 1;

    /* Clear older EMIF interrupts */

    EMIFClearIntrStatus(EMIF_APP_INST, EMIF_INTR_ALL);

    retVal = EMIFConfigECCInitECCParams(EMIF_APP_INST, &cfgPrm);
    if (retVal != STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n NULL Pointer Detected : cfgPrm", -1);
    }

    EMIFConfigECCDisableEcc(EMIF_APP_INST);

    for (i = 0; i < 4; i++)
    {
        gEmifErrInfo.errAddr[i] = 0;
    }
    gEmifErrInfo.numValidErrAddr = 0;
    gEmifErrInfo.errBitLoc       = 0;
}

/* Function configures Emif ECC
 * Also primes the memory area
 */
static void emifEccConfig()
{
    uint32_t                 i;
    int32_t                  retVal = STW_SOK;
    emifEccCfgPrm_t          cfgPrm;
    emifEccAddrRangeCfgPrm_t addrRangeCfgPrm;

    cfgPrm.addrRangeCfgPrm = &addrRangeCfgPrm;

    cfgPrm.emifStartAddr = EMIF_START_ADDR;
    cfgPrm.addrRangeCfgPrm->startAddr       = EMIF_ECC_START_ADDR;
    cfgPrm.addrRangeCfgPrm->endAddr         = EMIF_ECC_END_ADDR;
    cfgPrm.addrRangeCfgPrm->addrRangeNum    = EMIF_ECC_ADDR_RANGE_NUM_1;
    cfgPrm.addrRangeCfgPrm->addrRangeType   = EMIF_ECC_ADDR_RANGE_WITHIN;
    cfgPrm.addrRangeCfgPrm->enableAddrRange = TRUE;
    cfgPrm.thresholdVal = EMIF_ECC_1B_ERR_THRSH_VAL;

    if (EMIF_ECC_1B_ERR_THRSH_VAL > EMIF_ECC_FIFO_BUF_SIZE)
    {
        UARTConfigPuts(uartBaseAddr,
            "\r\nEMIF ECC FIFO Err address log buffer will get overflowed", -1);
    }

    /* Before configuring ECC EMIF, make sure ECC is enabled in
     * CTRL_WKUP_EMIF1_SDRAM_CONFIG_EXT ctrl module register as this will be
     * done in GEL files / SBL before doing EMIF configuration
     */

    for (i = EMIF_ECC_START_ADDR; i < EMIF_ECC_END_ADDR; i += 4)
        {
            *(uint32_t *) i = 0x0;
        }

    //EMIFConfigECCEnableEcc(EMIF_APP_INST);

    retVal = EMIFConfigECCInitECCParams(EMIF_APP_INST, &cfgPrm);

    if (retVal != STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n NULL Pointer Detected : cfgPrm", -1);
    }

    EMIFConfigECCEnableEcc(EMIF_APP_INST);

    /* Prime memory with known pattern */
    for (i = EMIF_ECC_START_ADDR; i < EMIF_ECC_END_ADDR; i += 4)
    {
        *(uint32_t *) i = PATTERN_DATA;
    }
#if defined (_TMS320C6X)
    /* Make sure the write is complete by writeback */
   CacheP_wbInv((const void *)EMIF_ECC_START_ADDR, (EMIF_ECC_END_ADDR-EMIF_ECC_START_ADDR));
#endif
}

/* Function performs Emif single bit error test
 * Configures ECC, Inserts single bit error
 * and waits for handler to finish
 */
static int32_t emifSecErrTest()
{
    uint32_t testVal, fifoIdx = 0;
    int32_t  retVal = STW_SOK;

    gErrStatus  = 0;
    gTest_Addr  = NULL;
    gTest_Addr1 = NULL;


#if defined (__ARM_ARCH_7A__)
    HwiP_Params hwiInputParams;
    HwiP_Handle handle;
    
    HwiP_Params_init(&hwiInputParams);
    
    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.priority = EMIF_COREPAC_PRIORITY;
    hwiInputParams.evtId = 0;
    hwiInputParams.arg = 0;
    hwiInputParams.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_EDGE;
    
    handle = HwiP_create(EMIF_ECC_ERR_INT, (HwiP_Fxn) isrEmifSecErr, &hwiInputParams);
    
    HwiP_enableInterrupt(EMIF_ECC_ERR_INT);
#else
    /* Enable The EMIF interrupt */
    Intc_Init();
    Intc_IntEnable(0);

    Intc_IntRegister(EMIF_ECC_ERR_INT, (IntrFuncPtr) isrEmifSecErr, NULL);

    Intc_IntPrioritySet(EMIF_ECC_ERR_INT, 1, 0);
    Intc_SystemEnable(EMIF_ECC_ERR_INT);
#endif
    emifEccConfig();

    gTest_Addr  = (uint32_t *) (EMIF_ECC_TEST_ADDR);
    gTest_Addr1 = (uint32_t *) (EMIF_ECC_TEST_ADDR_1);


    EMIFConfigECCDisableEcc(EMIF_APP_INST);
    EMIFEnableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_ONEBIT_ECC_ERR_SYS_MASK);


    EMIFConfigECCClrAllEccErrInfo(EMIF_APP_INST);



    testVal       = gTest_Addr[0];
    testVal       = testVal & 0xFFFEFFFF;
    gTest_Addr[0] = testVal;

    testVal        = gTest_Addr1[0];
    testVal        = testVal & 0xEFFFFFFF;
    gTest_Addr1[0] = testVal;

#if defined (_TMS320C6X)
    /* Make sure the values are written back */
    CacheP_wbInv((const void *)gTest_Addr, 4);
    CacheP_wbInv((const void *)gTest_Addr1, 4);
#endif

    EMIFConfigECCEnableEcc(EMIF_APP_INST);

    testVal = gTest_Addr[0];
    testVal = gTest_Addr1[0];

    while (gErrStatus == 0) ;

#if defined (__ARM_ARCH_7A__)

    EMIFWriteEOI(EMIF_ECC_ERR_INT);

    HwiP_disableInterrupt(EMIF_ECC_ERR_INT);

    HwiP_delete(handle);

    EMIFDisableIntr(EMIF_APP_INST,
                       EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET_ONEBIT_ECC_ERR_SYS_MASK);


    //HwiP_disable();
#else
    /* Disable the interrupt */
    Intc_SystemDisable(EMIF_ECC_ERR_INT);

    /* Unregister the interrupt */
    Intc_IntUnregister(EMIF_ECC_ERR_INT);

    Intc_IntDisable();
	
#endif

    if (gErrStatus != 0)
    {
        retVal = STW_SOK;
    }
    else
    {
        retVal = STW_EFAIL;
    }

    if (retVal == STW_EFAIL)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n EMIF ECC -- SEC ERR Test Fail!! ", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\r\nEMIF ECC -- SEC ERR Test Pass!! ", -1);
        UARTConfigPuts(uartBaseAddr, "\r\nEMIF ECC -- SEC ERR Occured at Address \r\n ", -1);
        UARTConfigPuts(uartBaseAddr, "\r\nNumber of Error Addresses \r\n ", -1);
        UARTConfigPutHexNum(uartBaseAddr, gEmifErrInfo.numValidErrAddr);
        UARTConfigPuts(uartBaseAddr, "\r\n", -1);
        while (gEmifErrInfo.numValidErrAddr--)
        {
            UARTConfigPutHexNum(uartBaseAddr, (gEmifErrInfo.errAddr[fifoIdx] + EMIF_START_ADDR));
            UARTConfigPuts(uartBaseAddr, "\r\n", -1);
            fifoIdx++;
        }
        UARTConfigPuts(uartBaseAddr, "\r\n EMIF ECC -- SEC ERR Occured at Bit Mask : ", -1);
        UARTConfigPutHexNum(uartBaseAddr, gEmifErrInfo.errBitLoc);
        UARTConfigPuts(uartBaseAddr, "\r\n", -1);
    }

    return retVal;
}

/* Function performs Emif double bit error test
 * Inserts double bit error and waits for handler to finish
 */
static int32_t emifDedErrTest()
{
    uint32_t testVal;
    int32_t  retVal = STW_SOK;

    gErrStatus = 0;
    gTest_Addr = NULL;

#if defined (__ARM_ARCH_7A__)
    HwiP_Params hwiInputParams;
    HwiP_Handle handle;
    
    HwiP_Params_init(&hwiInputParams);
    
    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.priority = EMIF_COREPAC_PRIORITY;
    hwiInputParams.evtId = 0;
    hwiInputParams.arg = 0;
    hwiInputParams.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_EDGE;
    
    handle = HwiP_create(160U, (HwiP_Fxn) isrEmifDedErr, &hwiInputParams);
    
    HwiP_enableInterrupt(160U);
#else
    Intc_Init();
    Intc_IntEnable(0);

    Intc_IntRegister(gInterruptNum, (IntrFuncPtr) isrEmifDedErr, NULL);
    Intc_IntPrioritySet(gInterruptNum, 1, 0);
    Intc_SystemEnable(gInterruptNum);
#endif


    emifEccConfig();

    gTest_Addr = (uint32_t *) (EMIF_ECC_TEST_ADDR);

    EMIFEnableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_TWOBIT_ECC_ERR_SYS_MASK);

    EMIFConfigECCClrAllEccErrInfo(EMIF_APP_INST);

    EMIFConfigECCDisableEcc(EMIF_APP_INST);
    testVal       = gTest_Addr[0];
    testVal       = testVal & 0xFFFCFFFF;
    gTest_Addr[0] = testVal;
#if defined (_TMS320C6X)
    /* Make sure the values are written back */
    CacheP_wbInv((const void *)gTest_Addr, 4);
#endif

    EMIFConfigECCEnableEcc(EMIF_APP_INST);
    testVal = gTest_Addr[0];

    while (gErrStatus == 0) ;

#if defined (__ARM_ARCH_7A__)

    EMIFDisableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_TWOBIT_ECC_ERR_SYS_MASK);
    HwiP_disableInterrupt(160U);

    HwiP_delete(handle);

   // HwiP_disable();
#else
    /* Unregister the interrupt */
    Intc_IntUnregister(gInterruptNum);

    Intc_IntDisable();
#endif

    if (gErrStatus != 0)
    {
        retVal = STW_SOK;
    }
    else
    {
        retVal = STW_EFAIL;
    }

    if (retVal == STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr, "\r\n EMIF ECC -- DED ERR Test Pass!! ", -1);
        UARTConfigPuts(uartBaseAddr, "\r\n EMIF ECC -- DED ERR Occured at Address : \r\n ", -1);
        UARTConfigPutHexNum(uartBaseAddr, gEmifErrInfo.errAddr[0] + EMIF_START_ADDR);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\r\n EMIF ECC -- DED ERR Test Fail!! ", -1);
    }

    return retVal;
}

/* Function performs Emif non ECC Quanta align Address error test
 * Does non ECC quanta align addresss access and waits for handler to finish
 */
static int32_t emifNonEccQuantaAlignAddrErrTest()
{
    int32_t  retVal  = STW_SOK;
    uint32_t testVal = 0;

    gErrStatus = 0;
    gTest_Addr = NULL;

#if defined (__ARM_ARCH_7A__)
    HwiP_Params hwiInputParams;
    HwiP_Handle handle;
    
    HwiP_Params_init(&hwiInputParams);
    
    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.priority = EMIF_COREPAC_PRIORITY;
    hwiInputParams.evtId = 0;
    hwiInputParams.arg = 0;
    hwiInputParams.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_EDGE;
    
    handle = HwiP_create(EMIF_ECC_ERR_INT, (HwiP_Fxn) isrEmifNonEccQuantaAlignAddrErr, 
                                              &hwiInputParams);
    
    HwiP_enableInterrupt(EMIF_ECC_ERR_INT);
#else
    Intc_Init();
    Intc_IntEnable(0);

    Intc_IntRegister(EMIF_ECC_ERR_INT,
                     (IntrFuncPtr) isrEmifNonEccQuantaAlignAddrErr,
                     NULL);
    Intc_IntPrioritySet(EMIF_ECC_ERR_INT, 1, 0);
    Intc_SystemEnable(EMIF_ECC_ERR_INT);
#endif

    emifEccConfig();

    EMIFEnableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_WR_ECC_ERR_SYS_MASK);

    EMIFConfigECCClrAllEccErrInfo(EMIF_APP_INST);

    gTest_Addr = (volatile uint32_t *) (EMIF_ECC_TEST_ADDR_2);
    testVal    = 0xFFFFFFFF;

    *(uint8_t *) (gTest_Addr) = testVal;

    while (gErrStatus == 0) ;

#if defined (__ARM_ARCH_7A__)

    EMIFDisableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_WR_ECC_ERR_SYS_MASK);

    HwiP_disableInterrupt(EMIF_ECC_ERR_INT);

    HwiP_delete(handle);

   // HwiP_disable();
#else
    /* Disable the interrupt */
    //Intc_SystemDisable(EMIF_ECC_ERR_INT);

    /* Unregister the interrupt */
    Intc_IntUnregister(EMIF_ECC_ERR_INT);

    Intc_IntDisable();
#endif
	

    if (gErrStatus != 0)
    {
        retVal = STW_SOK;
    }
    else
    {
        retVal = STW_EFAIL;
    }

    if (retVal == STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr,
            "\r\n EMIF ECC -- Non EccQuanta Align Address Err Test Pass!! ",
            -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr,
            "\r\n EMIF ECC -- Non EccQuanta Align Address Err Test Fail!! ",
            -1);
    }

    return retVal;
}

/* Function performs Emif Byte count Not ECC quanta Write access error test
 * Does sub ECC quanta address access and waits for handler to finish
 */
static int32_t emifByteCntWRAccessNotMultEccQuantaErrTest()
{
    int32_t  retVal = STW_SOK;
    uint8_t  testVal;

    gErrStatus = 0;
    gTest_Addr = NULL;

#if defined (__ARM_ARCH_7A__)
    HwiP_Params hwiInputParams;
    HwiP_Handle handle;
    
    HwiP_Params_init(&hwiInputParams);
    
    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.priority = EMIF_COREPAC_PRIORITY;
    hwiInputParams.evtId = 0;
    hwiInputParams.arg = 0;
    hwiInputParams.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_EDGE;
    
    handle = HwiP_create(EMIF_ECC_ERR_INT, (HwiP_Fxn) isrEmifByteCntWRAccessNotMultEccQuantaErr, &hwiInputParams);
    
    HwiP_enableInterrupt(EMIF_ECC_ERR_INT);
#else
    Intc_Init();
    Intc_IntEnable(0);

    Intc_IntRegister(EMIF_ECC_ERR_INT,
                     (IntrFuncPtr) isrEmifByteCntWRAccessNotMultEccQuantaErr,
                     NULL);
    Intc_IntPrioritySet(EMIF_ECC_ERR_INT, 1, 0);
    Intc_SystemEnable(EMIF_ECC_ERR_INT);
#endif

    emifEccConfig();

    EMIFEnableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_WR_ECC_ERR_SYS_MASK);

    EMIFConfigECCClrAllEccErrInfo(EMIF_APP_INST);

    gTest_Addr = (uint32_t *) (EMIF_ECC_TEST_ADDR);
    testVal    = 0xFF;

    *(uint8_t *) gTest_Addr = testVal;

    while (gErrStatus == 0) ;

#if defined (__ARM_ARCH_7A__)

    EMIFDisableIntr(EMIF_APP_INST,
                   EMIF_SYSTEM_OCP_INTERRUPT_STATUS_WR_ECC_ERR_SYS_MASK);
				   
    HwiP_disableInterrupt(EMIF_ECC_ERR_INT);

    HwiP_delete(handle);

    //HwiP_disable();
#else
    /* Disable the interrupt */
    //Intc_SystemDisable(EMIF_ECC_ERR_INT);

    /* Unregister the interrupt */
    Intc_IntUnregister(EMIF_ECC_ERR_INT);

    Intc_IntDisable();
#endif

    if (gErrStatus != 1)
    {
        retVal = STW_SOK;
    }
    else
    {
        retVal = STW_EFAIL;
    }

    if (retVal == STW_SOK)
    {
        UARTConfigPuts(uartBaseAddr,
            "\r\nEMIF ECC-ByteCnt WRAccess Not Multiple of EccQuanta Err Test Pass!!",
            -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr,
            "\r\nEMIF ECC-ByteCnt WRAccess Not Multiple of EccQuanta Err Test Fail!!",
            -1);
    }

    return retVal;
}

#if defined (_TMS320C6X)
HwiP_Handle enableCICIntrConfig()
{
	HwiP_Handle intrhandle;
    OsalRegisterIntrParams_t interruptRegParams;
    MuxIntcP_inParams        muxInParams;
    MuxIntcP_outParams       muxOutParams;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Setup the mux */
    muxInParams.arg         = (uintptr_t)0;
    muxInParams.muxNum      = 0;
    muxInParams.muxInEvent  = EMIF_MUX_INPUT_EVENT;
    muxInParams.muxOutEvent = EMIF_MUX_OUTPUT_EVENT;
    muxInParams.muxIntcFxn  = NULL;

	MuxIntcP_create(&muxInParams, &muxOutParams);
    
    interruptRegParams.corepacConfig.isrRoutine         =  NULL;

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.arg                =  (uintptr_t)0;
    interruptRegParams.corepacConfig.name               =  NULL;
    interruptRegParams.corepacConfig.isrRoutine         =  NULL;
    interruptRegParams.corepacConfig.priority           =  EMIF_COREPAC_PRIORITY;
	interruptRegParams.corepacConfig.corepacEventNum    =  EMIF_ECC_ERR_INT;
	interruptRegParams.corepacConfig.intVecNum          =  OSAL_REGINT_INTVEC_EVENT_COMBINER;

    /* Register interrupts */
	Osal_RegisterInterrupt(&interruptRegParams,&intrhandle);
	if(intrhandle != NULL)
	{
		return intrhandle;
	}
	else
	{
		return 0;
	}
}

void disableCICIntrConfig(HwiP_Handle intrhandle)
{
    Osal_DeleteInterrupt(intrhandle, EMIF_ECC_ERR_INT);
}
#endif
