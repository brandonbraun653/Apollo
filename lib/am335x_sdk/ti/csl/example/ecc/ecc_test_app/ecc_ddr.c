/* =============================================================================
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
#include <stdint.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>

#include <ti/osal/osal.h>
#include "ecc_ddr.h"

/* ----------------- Constant definitions ----------------- */

#define EMIF_DDR_START_ADDR (0x80000000u)

/* Local variables */
volatile uint32_t testVal;

/* -------------------------------------------------------- */

/* ----------------- Function prototypes ------------------ */
static void DDREccInit(char option);
static int32_t DDREccConfig(uint32_t eccMemType);
static int32_t DDRSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
static int32_t DDRDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
static uintptr_t DDRGetTranslatedAddress(uintptr_t nonECCAddress);
/* -------------------------------------------------------- */

static volatile uint32_t gSecTestPass   = FALSE;
static volatile uint32_t gDedTestPass   = FALSE;

/* Function handles Emif test sub menu */
void mainSubMenuDDREccTest(char *pOption)
{
    char option;
    while (1)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\n\r\n**** DDR ECC TEST ****", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nMenu:", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\n1. DDR SEC ERR ECC test", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\n2. DDR DED ERR ECC test", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nx. Exit", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nSelect ECC TEST : ", -1);
        /* Get option */
        UARTConfigGets(gUartBaseAddr, pOption, 1);

        option = *pOption;
        if ( (DDR_ECC_SEC_ERR_TEST == option) ||
             (DDR_ECC_DED_ERR_TEST == option) ||
             (DDR_ECC_EXIT         == option) )
        {
            break;
        }
        else
        {
            UARTConfigPuts(gUartBaseAddr, "\r\nEnter Valid option\r\n", -1);
        }
    }
}

void cslAppChkIsExpectedEvent(uint32_t eventId)
{
    int32_t   cslRet;
    CSL_ECCErrorInfo ECCErrorInfo;
    volatile uint32_t *translatedMemPtr;
    
    switch( eventId ) 
    {
        case DDR_ECC_AGGR0_DED_ERR_EVENT:
            /* Read ECC registers and double check address */
            cslRet = CSL_emifGetECCErrorInfo((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                              &ECCErrorInfo);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifGetECCErrorInfo Failed ", -1);
                /* TODO: Need to add assert */
                break;
            }
            if ((ECCErrorInfo.doublebitErrorAddress & (~0x7u))
                == ((DDR_ECC_TEST_ADDR- EMIF_DDR_START_ADDR) & (~0x7u)))
            {
                gDedTestPass = TRUE;
            }

            /* NOTE: The following section is test code only cannot be used in real application */
            /* ================================================================================ */
            /* Temporarily disable ECC */
            CSL_emifDisableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

            /* Calculate translated address */
            translatedMemPtr = (volatile uint32_t *)(DDRGetTranslatedAddress((uintptr_t)gTest_Addr));

            /* Now replace location with original value */
            *(translatedMemPtr) = testVal;

            /* Write back any pending writes */
            CacheP_wbInv((const void *)translatedMemPtr, 4);

            /* Enable back ECC */
            CSL_emifEnableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

            /* ================================================================================ */

            /* Clear specific error */
            cslRet = CSL_emifClearECCError((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                           CSL_EMIF_ECC_ERROR_TYPE_DOUBLE_BIT);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifClearECCErrors  failed ", -1);
                /* TODO: Need to add assert */
                break;
            }

            /* Clear ECC interrupt bits */
            cslRet = CSL_emifClearECCInterruptStatus((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                                     CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC2BERR_EN_MASK);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifClearECCInterruptStatus Failed ", -1);
                /* TODO: Need to add assert */
                break;
            }

            break;
            
        case DDR_ECC_AGGR0_SEC_ERR_EVENT:
            /* Read ECC registers and double check address */
            cslRet = CSL_emifGetECCErrorInfo((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                              &ECCErrorInfo);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifConfig ", -1);
                /* TODO: Need to add assert */                
                break;
            }

            if ((ECCErrorInfo.singlebitErrorAddress & (~0x7u))
                == ((DDR_ECC_TEST_ADDR- EMIF_DDR_START_ADDR) & (~0x7u)))            
            {
                gSecTestPass = TRUE;
            }

            /* Clear Specific ECC error */
            cslRet = CSL_emifClearECCError((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                           CSL_EMIF_ECC_ERROR_TYPE_SINGLE_BIT);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifClearECCErrors  failed ", -1);
                /* TODO: Need to add assert */
                break;
            }

            /* Clear ECC interupt bits */
            cslRet = CSL_emifClearECCInterruptStatus((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                                     CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                                     | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK);
            if (cslRet != CSL_PASS)
            {
                UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifClearECCInterruptStatus Failed ", -1);
                /* TODO: Need to add assert */
                break;
            }

            break;
            
        default:
            break;
    }

    return;
}

/* Function executes Emif ECC Test */
int32_t DDREccTest(void)
{
    int32_t retVal;
    char    mainSubMenuOption;
    uint32_t skipDDRTest;
    uint32_t   ramId = ECC_AGGR_UNKNOWN_RAM_ID;

    /* initialize the ESM */
    retVal = cslAppEsmSetup((uint32_t) ESM_CFG_BASE );

    if (retVal == CSL_PASS)
    {
        skipDDRTest = FALSE;
    }
    else
    {
        /* Skip the test as ESM setup Failed */
        skipDDRTest = TRUE;
        UARTConfigPuts(gUartBaseAddr, "\r\n ESM Setup Failed...", -1);
    }


    while (1)
    {
        if (skipDDRTest == FALSE)
        {
            mainSubMenuDDREccTest(&mainSubMenuOption);
            DDREccInit(mainSubMenuOption);
        }
        else
        {
            /* select exit option */
            mainSubMenuOption = 'x';
        }

        if (DDR_ECC_SEC_ERR_TEST == mainSubMenuOption)
        {
            retVal = DDRSecErrTest(NULL, ramId);
        }
        else if (DDR_ECC_DED_ERR_TEST == mainSubMenuOption)
        {
            retVal = DDRDedErrTest(NULL, ramId);
        }
        else
        {
            UARTConfigPuts(gUartBaseAddr, "\r\nDDR ECC test exiting...", -1);
            break;
        }
    }

    if (gSecTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nDDR ECC SEC ECC TESTS PASSED", -1);
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nDDR ECC SEC ECC TESTS FAILED", -1);
    }

    if (gDedTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nDDR ECC DED ECC TESTS PASSED", -1);
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nDDR ECC DED ECC TESTS FAILED", -1);
    }
    if (gDedTestPass & gSecTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nALL TESTS PASS", -1);
    }
    return retVal;
}

/* Function initialized DDR ECC */
static void DDREccInit(char option)
{
    int32_t cslRet;

    /* Ecc config */
    cslRet = DDREccConfig(APP_ECC_MEMTYPE_DDR);

    if (cslRet != CSL_PASS)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nECC Config failed...", -1);
    }
    return;
}

static uintptr_t DDRGetTranslatedAddress(uintptr_t memAddress)
{
    uint32_t memIndex;
    uintptr_t translatedMemAddr; 
       
    memIndex = (memAddress-0x80000000u)/0x200u;
    if ((memIndex & 0x1u) == 0)
    {
        translatedMemAddr = memAddress + (memIndex/2u)*0x80u;
    }
    else
    {
        translatedMemAddr = memAddress + ((memIndex+1u)/2u)*0x80u;
    }
    return  translatedMemAddr;
}

/* Function configures DDR ECC
 * Also primes the memory area
 */
static int32_t DDREccConfig(uint32_t eccMemType)
{
    int32_t    cslResult = CSL_PASS;
    uintptr_t  memPtr;
    int32_t    retVal = 0;
    CSL_EmifConfig emifCfg;

    /* Configure ECC addresses and other configuration */
    emifCfg.bEnableMemoryECC = true;
    emifCfg.bReadModifyWriteEnable = true;
    emifCfg.bECCCheck = true;
    emifCfg.bWriteAlloc = true;
    emifCfg.ECCThreshold = 1U;
    emifCfg.pMemEccCfg.startAddr[0] = DDR_ECC_START_ADDR-EMIF_DDR_START_ADDR;
    emifCfg.pMemEccCfg.endAddr[0] = DDR_ECC_END_ADDR-EMIF_DDR_START_ADDR;    
    emifCfg.pMemEccCfg.startAddr[1] = DDR_ECC_START_ADDR1-EMIF_DDR_START_ADDR;
    emifCfg.pMemEccCfg.endAddr[1] = DDR_ECC_END_ADDR1-EMIF_DDR_START_ADDR;   
    emifCfg.pMemEccCfg.startAddr[2] = DDR_ECC_START_ADDR2-EMIF_DDR_START_ADDR;
    emifCfg.pMemEccCfg.endAddr[2] = DDR_ECC_END_ADDR2-EMIF_DDR_START_ADDR;   
    cslResult = CSL_emifConfig((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                               &emifCfg);
    if (cslResult != CSL_PASS)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifConfig failed", -1);
        retVal = -1;
    }

    if ( retVal == 0 )
    {
        /* Prime memory section 1 with known pattern */
        for (memPtr = DDR_ECC_START_ADDR; memPtr < DDR_ECC_END_ADDR; memPtr += 4)
        {
            *((uint32_t *) memPtr) = memPtr;
        }

        /* Prime memory section 2 with known pattern */
        for (memPtr = DDR_ECC_START_ADDR1; memPtr < DDR_ECC_END_ADDR1; memPtr += 4)
        {
            *((uint32_t *) memPtr) = memPtr;
        }

        /* Prime memory section 3 with known pattern */
        for (memPtr = DDR_ECC_START_ADDR2; memPtr < DDR_ECC_END_ADDR2; memPtr += 4)
        {
            *((uint32_t *) memPtr) = memPtr;
        }
        /* Make sure the write is complete by writeback */
        CacheP_wbInv((const void *)DDR_ECC_START_ADDR, DDR_ECC_END_ADDR-DDR_ECC_START_ADDR);
        CacheP_wbInv((const void *)DDR_ECC_START_ADDR1, DDR_ECC_END_ADDR1-DDR_ECC_START_ADDR1);
        CacheP_wbInv((const void *)DDR_ECC_START_ADDR2, DDR_ECC_END_ADDR2-DDR_ECC_START_ADDR2);
 
        /* Clear any residual ECC errors */
        cslResult = CSL_emifClearAllECCErrors((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);
        if (cslResult != CSL_PASS)
        {
            UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifClearECCErrors  failed ", -1);
            retVal = -1;
        }
    }

    if ( retVal == 0 )
    {
        /* clear interrupt status */
        cslResult = CSL_emifClearECCInterruptStatus((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                                CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC2BERR_EN_MASK);
        if (cslResult != CSL_PASS)
        {
            UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifEnableECCInterrupts  failed ", -1);
            retVal = -1;
        }
    }

    if ( retVal == 0 )
    {
        /* Configure ECC interrupts : 1 bit error , 1 bit error multiple and 2 bit errors */
        cslResult = CSL_emifEnableECCInterrupts((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE,
                                                CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC2BERR_EN_MASK);
        if (cslResult != CSL_PASS)
        {
            UARTConfigPuts(gUartBaseAddr, "\r\n CSL_emifEnableECCInterrupts  failed ", -1);
            retVal = -1;
        }
    }

    if ( retVal != 0 )
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nECC AGGR Configuration failed...", -1);
    }

    return (retVal);
}

/* Function performs DDR single bit error test
 * Configures ECC, Inserts single bit error
 * and waits for handler to finish
 */
int32_t DDRSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
    int32_t  retVal = CSL_EFAIL;
    volatile uint32_t testVal2, testVal3;
    volatile uint32_t *translatedMemPtr;
    uint32_t waitCount = 0;

    /* set the test status to false */
    gSecTestPass = FALSE;

    /* Clear any residual ECC errors */
    CSL_emifClearAllECCErrors((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    /* Inject error */
    gTest_Addr = (uint32_t *) (DDR_ECC_TEST_ADDR);

    /* Write back any pending writes */
    CacheP_wbInv((const void *)gTest_Addr, 4);

    /* Read value from test location */
    testVal = gTest_Addr[0];

    /* Flip one bit to introduce error */
    testVal2       = testVal ^ 0x00010000u;

    /* Calculate translated address */
    translatedMemPtr = (volatile uint32_t *)(DDRGetTranslatedAddress((uintptr_t)gTest_Addr));

    /* NOTE: The following section is test code only cannot be used in real application */
    /* ================================================================================ */

    /* Temporarily disable ECC */
    CSL_emifDisableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    /* Now corrupt the value */
    *(translatedMemPtr) = testVal2;
    CacheP_wbInv((const void *)translatedMemPtr, 4);

    /* Enable back ECC */
    CSL_emifEnableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    /* ================================================================================ */

    /* Invalidate cache */
    CacheP_Inv((const void *)gTest_Addr, 4);

    /* Read value to trigger error */
    testVal3 = gTest_Addr[0];

    /* wait until the test passes */
    UARTConfigPuts(gUartBaseAddr, "\r\n Waiting on SEC Interrupt...", -1);

    while ((gSecTestPass == FALSE) && (waitCount++ < 10u)) {
        Osal_delay(1000);
    }
    if (gSecTestPass == TRUE) {
        UARTConfigPuts(gUartBaseAddr, "\r\n Got it (test pass)...", -1);        
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\n Test failed timedout ...", -1);         
    }

    /* Restore original value */
    gTest_Addr[0] = testVal;

    /* Write back any pending writes */
    CacheP_wbInv((const void *)gTest_Addr, 4);

    /* return the test status */
    return retVal;
}

/* Function performs DDR double bit error test
 * Inserts double bit error and waits for handler to finish
 */
static int32_t DDRDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
    int32_t  retVal = CSL_EFAIL;
    volatile uint32_t testVal;
    volatile uint32_t testVal2, testVal3;    
    volatile uint32_t *translatedMemPtr;
    uint32_t waitCount = 0;
    
    gDedTestPass = FALSE;

    /* Clear any residual ECC errors */
    CSL_emifClearAllECCErrors((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    gTest_Addr = (uint32_t *) (DDR_ECC_TEST_ADDR);
        
    CacheP_wbInv((const void *)gTest_Addr, 4);
     /* Read reference value */
    testVal       = gTest_Addr[0];
    /* flip 2 bits */
    testVal2       = testVal ^ 0x00101000u;
    /* Calculate translated address */
    translatedMemPtr = (volatile uint32_t *)(DDRGetTranslatedAddress((uintptr_t)gTest_Addr));

    /* Temporarily disable ECC */
    CSL_emifDisableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    /* Now corrupt the value */
    *(translatedMemPtr) = testVal2;

    /* Make sure the values are written back */
    CacheP_wbInv((const void *)translatedMemPtr, 4);

    /* Enable back ECC */
    CSL_emifEnableECC((CSL_emif_sscfgRegs *)CSL_COMPUTE_CLUSTER0_SS_CFG_BASE);

    /* Invalidate cache */
    CacheP_Inv((const void *)gTest_Addr, 4);

    /* Read value to trigger error */
    testVal3 = gTest_Addr[0];

    /* wait until the test passes */
    UARTConfigPuts(gUartBaseAddr, "\r\n Waiting on DED interrupt...", -1);
    while ((gDedTestPass == FALSE) && (waitCount++ < 10u)) {
        Osal_delay(1000);
    }

    if (gDedTestPass == TRUE) {
        UARTConfigPuts(gUartBaseAddr, "\r\n Got it (test pass)...", -1);        
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\n Test failed timedout ...", -1);         
    }

    /* Restore original value */
    gTest_Addr[0] = testVal;
    
    /* return the test status */
    return retVal;
}

/* Nothing past this point */
