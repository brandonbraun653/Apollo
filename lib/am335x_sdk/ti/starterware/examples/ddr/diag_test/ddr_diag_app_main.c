/**
 * \file   ddr_diag_app_main.c
 *
 * \brief  Example application main source file, which does DDR
 *         diagnostics.
 *
 * \detail Application demonstrates the diagnostics for DDR by
 *         writing and reading the bit patterns to the DDR.
 *
 */

/*
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
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "example_utils_mmu.h"
#include "console_utils.h"
#include "dma_utils.h"

/* Application header files */
#include "ddr_diag_app.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets DDR size of the Board depending on Board ID
 *
 * \param   ddrDiagAppBoardId   board ID.
 */
static void DdrDiagAppGetMemSize (boardId_t ddrDiagAppBoardId);

/**
 * \brief   API for Diagnosing Address line failures.
 *
 * \param   startAddr   start address of DDR Memory for testing.
 * \param   size        total size of Memory being tested.
 */
static void DdrDiagAppAddrTest(uint32_t startAddr, uint32_t size);

/**
 * \brief   API for diagnosing Data line failures.
 *
 * \param   startAddr   start address of DDR Memory for testing.
 * \param   size        total size of Memory being tested.
 */
static void DdrDiagAppDataTest(uint32_t startAddr, uint32_t size);

/**
 * \brief   API for getting total memory to be tested.
 *
 * \retval  size        total size of Memory being tested.
 */
static uint32_t DdrDiagAppTestSize(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief     Data patterns to be written to DDR */
static const uint32_t gDdrDiagAppPattern[25U]  =
{
    0x55555555U, 0xaaaaaaaaU, 0x33333333U, 0xccccccccU,
    0x0f0f0f0fU, 0xf0f0f0f0U, 0x00ff00ffU, 0xff00ff00U,
    0x0000ffffU, 0xffff0000U, 0x00000000U, 0xffffffffU,
    0x00000000U, 0x55555555U, 0xaaaaaaaaU, 0x33333333U,
    0xccccccccU, 0x0f0f0f0fU, 0xf0f0f0f0U, 0x00ff00ffU,
    0xff00ff00U, 0x0000ffffU, 0xffff0000U, 0x00000000U,
    0xffffffffU,
};

/** \brief    DDR Memory size */
static uint32_t gDdrDiagAppMemSize;

/** \brief    Variable for Number of patterns to be tested */
static int32_t gDDrDiagAppMultiPattern = FALSE;

/** \brief    Success/Failure status of tests */
static int32_t gFail = FALSE;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    int32_t status = S_PASS;
    uint32_t testAddr;
    uint32_t testSize;
    boardId_t ddrDiagAppBoardId;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();

    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    CONSOLEUtilsPrintf("\n***************************\n");
    CONSOLEUtilsPrintf(  "*       Memory Test       *\n");
    CONSOLEUtilsPrintf(  "***************************\n");

    /* Get board Id to find the Size of DDR */
    ddrDiagAppBoardId = BOARDGetId();
    /* Get the size of DDR */
    DdrDiagAppGetMemSize(ddrDiagAppBoardId);
    /* Test */
    CONSOLEUtilsPrintf("Test\t\t\tStatus\t    Info\n");
    CONSOLEUtilsPrintf("----------------\t------    --------------------\n");

    /* Test size */
    testSize = DdrDiagAppTestSize();
    if(testSize != 0U)
    {
      testSize -= 0x100000U;
      testAddr = START_ADDR_DDR + 0x100000U;
      DdrDiagAppAddrTest(testAddr, testSize);
      DdrDiagAppDataTest(testAddr, testSize);
    }

    CACHEDisable(CACHE_DCACHE, CACHE_INNER);

    CONSOLEUtilsPrintf("\n  Exiting\n");

    return (gFail);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void DdrDiagAppGetMemSize (boardId_t ddrDiagAppBoardId)
{
    /** TBD: Detect the size based on the Board ID.
     *       If the memory size is greter than 128MB update the
     *       Number of sections of DDR Memory in MMU utils to
     *       the appropriate value to eliminate aborts
     */
    gDdrDiagAppMemSize = 128*1024*1024U;
}

static void DdrDiagAppAddrTest(uint32_t startAddr, uint32_t size)
{
    uint32_t *addr = (uint32_t *)(startAddr);
    uint32_t data=(startAddr);
    uint32_t expectedData;
    uint32_t index1;
    uint32_t fAddrFail=FALSE;
    char symbol = '|';

    /* write memory */
    CONSOLEUtilsPrintf("Address Test\t\tWrite\t\t%c", symbol);
    for(index1 = 0U; index1 < size; index1 += 4U)
    {
        *addr = data;
        addr++;
        data += 4U;
        if((index1 % 0x1000000U) == 0U)
        {
            switch(symbol)
            {
                case '|':
                {
                    symbol = '/';
                    break;
                }
                case '/':
                {
                    symbol = '-';
                    break;
                }
                case '-':
                {
                    symbol = '\\';
                    break;
                }
                case '\\':
                {
                    symbol = '|';
                    break;
                }
                default:
                {
                    break;
                }
            }
            CONSOLEUtilsPrintf("\rAddress Test\t\tWrite\t\t%c", symbol);
        }
    }
    CACHEDataCleanInvRange((uint32_t *)startAddr, size);

    /* verify */
    CONSOLEUtilsPrintf("\rAddress Test\t\tRead \t\t%c", symbol);
    addr = (uint32_t *)(startAddr);
    for(index1 = 0U; index1 < size; index1 += 4U)
    {
        data = *addr;
        expectedData = (uint32_t)addr;
        if((index1 % 0x1000000U) == 0U && (fAddrFail != FALSE))
        {
            switch(symbol)
            {
                case '|':
                {
                    symbol = '/';
                    break;
                }
                case '/':
                {
                    symbol = '-';
                    break;
                }
                case '-':
                {
                    symbol = '\\';
                    break;
                }
                case '\\':
                {
                    symbol = '|';
                    break;
                }
                default:
                {
                    break;
                }
            }
            CONSOLEUtilsPrintf("\rAddress Test\t\tRead \t\t%c", symbol);
        }
        if(data != expectedData)
        {
            if(fAddrFail != FALSE)
            {
                CONSOLEUtilsPrintf("\rAddress Test\t\tFAIL\t\n");
                fAddrFail = TRUE;
            }
            CONSOLEUtilsPrintf(
                "\tFailure at 0x%08x:  Expected=0x%08x  Actual=0x%08x\n"
                , addr, expectedData, data);
            gFail = TRUE;
        }
        addr++;
    }

    if(!fAddrFail)
        CONSOLEUtilsPrintf("\rAddress Test\t\t PASS                \n");
}

static void DdrDiagAppDataTest(uint32_t startAddr, uint32_t size)
{
    uint32_t *addr=(uint32_t *)(startAddr);
    uint32_t data;
    uint32_t expectedData;
    uint32_t index1;
    uint32_t index2;
    uint32_t index3;
    uint32_t offset = 0U;
    uint32_t offsetMax = 0U;
    uint32_t fDataFail = FALSE;
    char symbol = '|';

    if(gDDrDiagAppMultiPattern != FALSE)
    {
        offsetMax = 12U;
    }
    for(offset = 0U; offset <= offsetMax; offset++)
    {
        fDataFail = FALSE;
        CONSOLEUtilsPrintf("Data Test %02d\t\tWrite\t\t%c", offset, symbol);
        if(gDDrDiagAppMultiPattern != FALSE)
        {
            addr=(uint32_t *)(startAddr);
        }

        /* write patterns */
        index2 = 0U;
        for(index1 = 0U; index1 < size;index1 += 4U)
        {
            data = gDdrDiagAppPattern[(index2 + offset) % 13U];
            *addr = data;
            addr++;
            index2++;
            if((index1 % 0x1000000U) == 0U)
            {
                switch(symbol)
                {
                    case '|':
                    {
                        symbol='/';
                        break;
                    }
                    case '/':
                    {
                        symbol='-';
                        break;
                    }
                    case '-':
                    {
                        symbol='\\';
                        break;
                    }
                    case '\\':
                    {
                        symbol='|';
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                CONSOLEUtilsPrintf("\rData Test %02d\t\tWrite\t\t%c", offset, symbol);
            }
        }
        CACHEDataCleanInvRange((uint32_t *)startAddr, size);

        /* verify */
        for(index3 = 0U; index3 < 1U; index3++)
        {
            CONSOLEUtilsPrintf("\rData Test %02d\t\tRead \t\t%c", index3, symbol);
            addr = (uint32_t *)(startAddr);
            index2 = 0U;
            for(index1 = 0U; index1 < size; index1 += 4U)
            {
                data = *addr;
                expectedData = gDdrDiagAppPattern[(index2 + offset)% 13U];
                if((index1 % 0x1000000U) == 0U && (fDataFail != FALSE))
                {
                    switch(symbol)
                    {
                        case '|':
                        {
                            symbol = '/';
                            break;
                        }
                        case '/':
                        {
                            symbol = '-';
                            break;
                        }
                        case '-':
                        {
                            symbol = '\\';
                            break;
                        }
                        case '\\':
                        {
                            symbol = '|';
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    CONSOLEUtilsPrintf("\rData Test %02d\t\tRead \t\t%c", index3, symbol);
                }
                if(data != expectedData)
                {
                    if(fDataFail != FALSE)
                    {
                        CONSOLEUtilsPrintf("\rData Test %02d\t\tFAIL \t\t\n", index3);
                        fDataFail = TRUE;
                    }
                    CONSOLEUtilsPrintf(
                        "\tFailure at 0x%08x:  Expected=0x%08x  Actual=0x%08x\n"
                        , addr, expectedData, data);
                    gFail = TRUE;
                }
                addr++;
                index2++;
            }
            if(!fDataFail)
            {
                CONSOLEUtilsPrintf("\rData Test %02d\t\t PASS              \n", index3);
            }
        }
    }
}

static uint32_t DdrDiagAppTestSize(void)
{
    uint32_t *addr = (uint32_t *)(START_ADDR_DDR);
    uint32_t data = START_ADDR_DDR;
    uint32_t expectedData;
    uint32_t tempData;
    uint32_t size = 0x20000U;

    CONSOLEUtilsPrintf("Memory test size\t");

    /* save data at START_ADDR_DDR in a variable */
    tempData = *addr;

    /* single write and read to start test and set expected data */
    *addr = data;
    CACHEDataCleanInvRange((uint32_t *)START_ADDR_DDR, 1U);
    expectedData = *addr;
    if(data != expectedData)
    {
        CONSOLEUtilsPrintf("FAIL\t Basic read/write test failed\n");
        return 0U;
    }

    /* perform wrap test to detect size */
    while(size < MAX_DDR_SIZE)
    {
        addr = (uint32_t *)(START_ADDR_DDR+size);
        *addr = size;
        CACHEDataCleanInvRange((uint32_t *)START_ADDR_DDR, 1U);
        CACHEDataCleanInvRange((uint32_t *)addr, 1U);
        data = *(uint32_t *)(START_ADDR_DDR);
        if(data != expectedData)
        break;
        size *= 2U;
    }

    /* restore START_ADDR_DDR */
    addr = (uint32_t *)(START_ADDR_DDR);
    *addr = tempData;
    CACHEDataCleanInvRange((uint32_t *)START_ADDR_DDR, 1U);

    if(size != gDdrDiagAppMemSize)
    {
        CONSOLEUtilsPrintf("FAIL      ");
        gFail = TRUE;
    }
    else
    {
        CONSOLEUtilsPrintf(" PASS     ");
    }
    if(size >= (1024U * 1024U * 1024U))
    {
        CONSOLEUtilsPrintf("Accessed memory size: %dGB\n",
                              size/(1024U * 1024U * 1024U));
    }
    else if(size >= (1024U * 1024U))
    {
        CONSOLEUtilsPrintf("Accessed memory size: %dMB\n", size/(1024U * 1024U));
    }
    else
    {
        CONSOLEUtilsPrintf("Accessed memory size: %dKB\n", size/(1024U));
    }
    return size;
}
