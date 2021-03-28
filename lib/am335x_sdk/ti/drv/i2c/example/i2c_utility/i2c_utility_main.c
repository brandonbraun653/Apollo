/*
 *   Copyright (c) Texas Instruments Incorporated 2019 - 2020
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
 *  \file     i2c_utility_main.c.c
 *
 *  \brief    This file contains I2C Utility code.
 *
 *  \details  Provides basic utility APIs to read/write over I2C bus.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/src/devices/common/common.h>
#include <ti/board/board.h>
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/**< Set '1' to UART console for giving inputs.
     Set '0' to for getting input from CIO Console */
#define APP_USE_UART_CONSOLE                                (0U)

#if defined (SOC_AM65XX)
/**< Number of I2C channels */
#define APP_I2C_INST_MAX                                    ((uint32_t)4U)
#endif
#if defined (SOC_J721E) || defined (SOC_AM77X) || defined (SOC_J7200)
/**< Number of I2C channels */
#define APP_I2C_INST_MAX                                    ((uint32_t)9U)
#endif
/**< Number of addressing and data modes */
#define APP_I2C_MODES_MAX                                   ((uint32_t)4U)
/**< Maximum number of register read/write support in one go */
#define APP_I2C_MAX_REG_RD_WR                               ((uint32_t)0x100)
/**< Maximum length of imput string */
#define APP_I2C_MAX_IN_STRING                               (1024U)
/**< Number of byte ordering modes */
#define APP_BYTE_ORDER_MODES_MAX                            ((uint32_t)2U)
/**< File reading modes */
#define APP_FILE_READ_MODES_MAX                             ((uint32_t)2U)
/* Print buffer character limit for prints- UART or CCS Console */
#define APP_PRINT_BUFFER_SIZE                               ((uint32_t)4000)

/**< I2C transaction timeout */
#define APP_I2C_TRANSACTION_TIMEOUT                         ((uint32_t)2000U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static const char gAppMainMenu[] =
{
    " \r\n"
    " \r\n ================================================================="
    " \r\n Commands"
    " \r\n ================================================================="
    " \r\n menu                      - shows this screen"
    " \r\n show setting              - display current setting"
    " \r\n setting                   - change setting"
    " \r\n quit                      - exits utility"
    " \r\n probe                     - probes the I2C instance (0 or 1) for all possibly connected slaves"
    " \r\n file <FileName>           - execute I2C utility commands by reading from file <FileName>"
    " \r\n wait <time in msecs>      - introduce a delay of <time in msecs> msecs"
    " \r\n"
    " \r\n rd <dev addr in hex> <reg offset in hex> <num regs to read in hex> "
    " \r\n wr <dev addr in hex> <reg offset in hex> <value to write in hex> "
    " \r\n"
    " \r\n rd_raw <dev addr in hex> <num regs to read in hex>"
    " \r\n       - Reads the specified no. of registers from a desired IO expander kind "
    " \r\n         of slave, which doesn't have the register offset"
    " \r\n"
    " \r\n wr_raw <dev addr in hex> <reg value 1 in hex> <reg value 2 in hex> etc..."
    " \r\n       - Writes n bytes (max 100 bytes) at the desired slave."
    " \r\n         All bytes are transferred one after the other in the same I2C transfer"
    " \r\n"
    " \r\n rd      <reg offset in hex> can be 8 or 16 bits wide"
    " \r\n         <reg offset in hex> 8 bits for all other commands"
    " \r\n"
    " \r\n"
};

static const char gAppSettingSubMenu[] =
{
    " \r\n ================================================================="
    " \r\n Setting Menu:"
    " \r\n ================================================================="
    " \r\n 0: Change I2C Instance"
    " \r\n 1: Change Addressing/Data Mode"
    " \r\n 2: Byte Ordering Mode"
    " \r\n 3: File Read Mode"
    " \r\n 4: quit"
    " \r\n"
    " \r\n Enter option:"
};

static const char gAppI2cInstNames[APP_I2C_INST_MAX][50U] =
{
#if defined (SOC_AM65XX)
    {" \r\n 0: Main Domain Inst0"},
    {" \r\n 1: Main Domain Inst1"},
    {" \r\n 2: MCU Domain Inst0"},
    {" \r\n 3: MCU Domain Inst1"},
#endif
#if defined (SOC_J721E) || defined (SOC_AM77X) || defined (SOC_J7200)
    {" \r\n 0: Main Domain Inst0"},
    {" \r\n 1: Main Domain Inst1"},
    {" \r\n 2: Main Domain Inst2"},
    {" \r\n 3: Main Domain Inst3"},
    {" \r\n 4: Main Domain Inst4"},
    {" \r\n 5: Main Domain Inst5"},
    {" \r\n 6: Main Domain Inst6"},
    {" \r\n 7: MCU Domain Inst0"},
    {" \r\n 8: MCU Domain Inst1"},
#endif
};

static const uint32_t gAppI2cInstIds[APP_I2C_INST_MAX] =
{
#if defined (SOC_AM65XX)
    0U,
    1U,
    0U,
    1U,
#endif
#if defined (SOC_J721E) || defined (SOC_AM77X) || (SOC_J7200)
    0U,
    1U,
    2U,
    3U,
    4U,
    5U,
    6U,
    0U,
    1U,
#endif
};

static const char gAppI2cSetting[APP_I2C_MODES_MAX][50U] =
{
    {" \r\n 0: 8 bits addresses and 8 bits data."},
    {" \r\n 1: 8 bits addresses and 16 bits data."},
    {" \r\n 2: 16 bits addresses and 8 bits data."},
    {" \r\n 3: 16 bits addresses and 16 bits data."},
};

static const char gAppByteOrderSetting[APP_BYTE_ORDER_MODES_MAX][50U] =
{
    {" \r\n 0: MSB First."},
    {" \r\n 1: LSB First."},
};

static const char gAppFileReadSetting[APP_FILE_READ_MODES_MAX][50U] =
{
    {" \r\n 0: Read from Host PC."},
    {" \r\n 1: Read from SD Card."},
};

/* Default mode is 8 bit addressing and 8 bit data */
uint32_t gAddrDataMode = 0U;
#if defined (SOC_AM65XX)
uint32_t gCurrInst = 1U;
#endif
#if defined (SOC_J721E) || defined (SOC_J7200)
uint32_t gCurrInst = 6U;
#endif
char gInputStr[APP_I2C_MAX_IN_STRING];
char *gInputArgs[128];
uint32_t gNumArgs;
Bool gInitDone = FALSE;
I2C_Handle gI2cHandle = NULL;
uint8_t gByteOrder = BOARD_I2C_REG_ADDR_MSB_FIRST;
uint8_t gFileReadLoc = 0U;
char gFileName[256];
char gLine[1024];
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static int32_t App_showMenu(void);
static int32_t App_showSetting(void);
static int32_t App_changeSetting(void);
static Bool App_exeCmd(Bool echoCmd);
static uint32_t App_tokenizeInput(char *inStr, char *argv[]);
static int32_t App_readRegs(void);
static int32_t App_writeReg(void);
static int32_t App_delay(void);
static int32_t App_file(void);
static int32_t App_writeRegN(void);
static int32_t App_readRegRaw(void);
static int32_t App_deviceI2cProbeAll(uint32_t inst);
static int xstrtoi(char *hex);
static int32_t HextoDec(char *hex, int32_t l);
static char xtod(char c);
static int32_t App_setupI2CInst(void);
int32_t App_deviceRawRead8(uint32_t i2cInstId,
                           uint32_t i2cDevAddr,
                           uint8_t *regValue,
                           uint32_t numRegs);
int32_t App_deviceRawWrite8(uint32_t i2cInstId,
                            uint32_t i2cDevAddr,
                            uint8_t *regValue,
                            uint32_t numRegs);
static void App_consolePrintf(const char *pcString, ...);
static int32_t App_getNum(uint32_t *num);
static int32_t App_gets(char *str);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t main(void)
{
    Bool done = FALSE;
    uint8_t index;
    I2C_HwAttrs i2cConfig;
    Board_STATUS status;
    Board_initCfg boardCfg;
    int32_t retVal = CSL_SOK;

    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        App_consolePrintf(" Board Init FAILED!!!\r\n");
    }

    /* Initialize I2C Driver */
    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    retVal = App_setupI2CInst();
    retVal = App_showSetting();
    retVal = App_showMenu();

    if (retVal == CSL_SOK)
    {
        while (!done)
        {
            App_consolePrintf("\n\r I2C-%d> ", gCurrInst);
            done = App_exeCmd(TRUE);
        }
    }

    if (gInitDone == TRUE)
    {
        I2C_close(gI2cHandle);
    }
    App_consolePrintf(" I2C: Bye Bye !!!\r\n");

    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static int32_t App_showMenu(void)
{
    int32_t retVal = CSL_SOK;

    App_consolePrintf("%s", gAppMainMenu);

    return (retVal);
}

static int32_t App_showSetting(void)
{
    int32_t retVal = CSL_SOK;

    App_consolePrintf(" \r\n Current Setting");
    App_consolePrintf
    (" \r\n =================================================================");
    App_consolePrintf(" \r\n Current I2C Instance: %s",
                gAppI2cInstNames[gCurrInst]);
    App_consolePrintf(" \r\n Addressing and Address Mode: %s",
                gAppI2cSetting[gAddrDataMode]);
    App_consolePrintf(" \r\n Byte Ordering Mode: %s",
                gAppByteOrderSetting[gByteOrder]);
    App_consolePrintf(" \r\n File Read Mode: %s",
                gAppFileReadSetting[gFileReadLoc]);


    return (retVal);
}

static int32_t App_changeSetting(void)
{
    int32_t retVal = CSL_SOK;
    uint32_t mode = 0U, loopCnt = 0U;

    App_consolePrintf("%s", &gAppSettingSubMenu[0U]);
    retVal = App_getNum(&mode);
    if (retVal == CSL_SOK)
    {
        switch (mode)
        {
            case 0:
                /* Change instance */
                App_consolePrintf(" \r\n Available Instances:");
                App_consolePrintf
                (" \r\n =================================================================");
                for (loopCnt = 0U ; loopCnt < APP_I2C_INST_MAX ; loopCnt++)
                {
                    App_consolePrintf("%s:", &gAppI2cInstNames[loopCnt]);
                }
                App_consolePrintf(" \r\n Enter I2C Instance ID:");
                retVal = App_getNum(&mode);
                if (retVal == CSL_SOK)
                {
                    /* Close older I2C instance */
                    if (gInitDone == TRUE)
                    {
                        I2C_close(gI2cHandle);
                        gI2cHandle = NULL;
                    }
                    gCurrInst = gAppI2cInstIds[mode];
                    /* Open new instance */
                    App_setupI2CInst();
                }
            break;
            case 1:
                /* Change addressing and data mode */
                App_consolePrintf(" \r\n Available Modes:");
                App_consolePrintf
                (" \r\n =================================================================");
                for (loopCnt = 0U ; loopCnt < APP_I2C_MODES_MAX ; loopCnt++)
                {
                    App_consolePrintf("%s:", &gAppI2cSetting[loopCnt]);
                }
                App_consolePrintf(" \r\n Enter I2C Mode ID:");
                retVal = App_getNum(&mode);
                if (retVal == CSL_SOK)
                {
                    gAddrDataMode = mode;
                }
            case 2:
                /* Change byte ordering mode */
                App_consolePrintf(" \r\n Available Modes:");
                App_consolePrintf
                (" \r\n =================================================================");
                for (loopCnt = 0U ; loopCnt < APP_BYTE_ORDER_MODES_MAX ; loopCnt++)
                {
                    App_consolePrintf("%s:", &gAppByteOrderSetting[loopCnt]);
                }
                App_consolePrintf(" \r\n Enter Byte Ordering Mode ID:");
                retVal = App_getNum(&mode);
                if (retVal == CSL_SOK)
                {
                    gByteOrder = mode;
                }
            break;
            case 3:
                /* Change file read mode */
                App_consolePrintf(" \r\n Available Modes:");
                App_consolePrintf
                (" \r\n =================================================================");
                for (loopCnt = 0U ; loopCnt < APP_FILE_READ_MODES_MAX ; loopCnt++)
                {
                    App_consolePrintf("%s:", &gAppFileReadSetting[loopCnt]);
                }
                App_consolePrintf(" \r\n Enter File Read Mode ID:");
                retVal = App_getNum(&mode);
                if (retVal == CSL_SOK)
                {
                    gFileReadLoc = mode;
                }
            break;
            default:
                retVal = CSL_EFAIL;
            break;
        }
    }

    return (retVal);
}

static Bool App_exeCmd(Bool echoCmd)
{
    Bool  done = FALSE;
    int32_t retVal = CSL_SOK;

    retVal = App_gets(&gInputStr[0U]);
    if (retVal != CSL_SOK)
    {
        done = TRUE;
    }

    else
    {
        if (echoCmd)
        {
            App_consolePrintf(" \r\n");
            App_consolePrintf(" I2C: CMD: %s\r\n", gInputStr);
        }

        gNumArgs = App_tokenizeInput(gInputStr, gInputArgs);
        if (gNumArgs)
        {
            if (strcmp(gInputArgs[0U], "quit") == 0)
            {
                done = TRUE;
            }
            else if (strcmp(gInputArgs[0U], "menu") == 0)
            {
                retVal = App_showMenu();
            }
            else if ((strcmp(gInputArgs[0U], "show") == 0) &&
                     (strcmp(gInputArgs[1U], "setting") == 0))
            {
                retVal = App_showSetting();
            }
            else if (strcmp(gInputArgs[0U], "setting") == 0)
            {
                retVal = App_changeSetting();
                if (retVal != CSL_SOK)
                {
                    done = TRUE;
                }
            }
            else if (strcmp(gInputArgs[0U], "help") == 0)
            {
                retVal = App_showMenu();
            }
            else if (strcmp(gInputArgs[0U], "rd") == 0)
            {
                retVal = App_readRegs();
            }
            else if (strcmp(gInputArgs[0U], "wr") == 0)
            {
                retVal = App_writeReg();
            }
            else if (strcmp(gInputArgs[0U], "wait") == 0)
            {
                retVal = App_delay();
            }
            else if (strcmp(gInputArgs[0U], "file") == 0)
            {
                retVal = App_file();
            }
            else if (strcmp(gInputArgs[0U], "wr_raw") == 0)
            {
                retVal = App_writeRegN();
            }
            else if (strcmp(gInputArgs[0U], "rd_raw") == 0)
            {
                retVal = App_readRegRaw();
            }
            else if (strcmp(gInputArgs[0U], "probe") == 0)
            {
                retVal = App_deviceI2cProbeAll(gCurrInst);
            }
        }
    }

    return (done);
}

static uint32_t App_tokenizeInput(char *inStr, char *argv[])
{
    char   delimiters[] = " \r\n";
    char  *token;
    uint32_t argc = 0;

    token = strtok(inStr, delimiters);
    while (token != NULL)
    {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, delimiters);
    }

    return (argc);
}

static int32_t App_readRegs(void)
{
    int8_t ret = 0;
    uint32_t devAddr;
    uint32_t regAddr, regVal = 0U;
    uint32_t numRegs, loopCnt = 0U;
    int32_t  retVal   = CSL_SOK;
    //uint32_t currTime = 0, timeElapsed = 0;

    if (gNumArgs == 4)
    {
        devAddr = xstrtoi(gInputArgs[1]);
        regAddr = xstrtoi(gInputArgs[2]);
        numRegs = xstrtoi(gInputArgs[3]);

        if (numRegs < APP_I2C_MAX_REG_RD_WR)
        {
            App_consolePrintf(
            "\n\r I2C: Reading 0x%02x registers starting from REG 0x%02x of device 0x%02x ... !!!\r\n",
            numRegs,
            regAddr,
            devAddr);
            for (loopCnt = 0U ; loopCnt < numRegs ; loopCnt++)
            {
                regVal = 0U;
                switch (gAddrDataMode)
                {
                    case 0U:
                        ret = Board_i2c8BitRegRd(gI2cHandle,
                                                 (uint8_t)devAddr,
                                                 (uint8_t)(regAddr + loopCnt),
                                                 (uint8_t *)&regVal,
                                                 1U,
                                                 APP_I2C_TRANSACTION_TIMEOUT);
                    break;
                    case 1U:
                        ret = Board_i2c8BitRegRd(gI2cHandle,
                                                 (uint8_t)devAddr,
                                                 (uint8_t)(regAddr + loopCnt),
                                                 (uint8_t *)&regVal,
                                                 2U,
                                                 APP_I2C_TRANSACTION_TIMEOUT);
                    break;
                    case 2U:
                        ret = Board_i2c16BitRegRd(gI2cHandle,
                                                  (uint8_t)devAddr,
                                                  (uint16_t)(regAddr + loopCnt),
                                                  (uint8_t *)&regVal,
                                                  1U,
                                                  gByteOrder,
                                                  APP_I2C_TRANSACTION_TIMEOUT);
                    break;
                    case 3U:
                        ret = Board_i2c16BitRegRd(gI2cHandle,
                                                  (uint8_t)devAddr,
                                                  (uint16_t)(regAddr + loopCnt),
                                                  (uint8_t *)&regVal,
                                                  2U,
                                                  gByteOrder,
                                                  APP_I2C_TRANSACTION_TIMEOUT);
                    break;
                    default:
                    break;
                }
                if(ret == 0)
                {
                    App_consolePrintf(" I2C: 0x%x = 0x%x\r\n",
                                (regAddr + loopCnt),
                                regVal);
                }
                else
                {
                    App_consolePrintf(" I2C: Read ERROR !!!\r\n");
                    retVal = CSL_EFAIL;
                    break;
                }
            }
        }
    }
    else
    {
        App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
    }

    return (retVal);
}

static int32_t App_writeReg(void)
{
    int8_t ret = 0;
    uint32_t devAddr;
    uint32_t regAddr;
    uint32_t regVal;
    int32_t  retVal = CSL_SOK;

    if (gNumArgs == 4)
    {
        devAddr = xstrtoi(gInputArgs[1]);
        regAddr = xstrtoi(gInputArgs[2]);
        regVal = xstrtoi(gInputArgs[3]);
        switch (gAddrDataMode)
        {
            case 0U:
                ret = Board_i2c8BitRegWr(gI2cHandle,
                                         (uint8_t)devAddr,
                                         (uint8_t)(regAddr),
                                         (uint8_t *)&regVal,
                                         1U,
                                         APP_I2C_TRANSACTION_TIMEOUT);
                regVal = 0U;
                ret += Board_i2c8BitRegRd(gI2cHandle,
                                          (uint8_t)devAddr,
                                          (uint8_t)(regAddr),
                                          (uint8_t *)&regVal,
                                          1U,
                                          APP_I2C_TRANSACTION_TIMEOUT);
            break;
            case 1U:
                ret = Board_i2c8BitRegWr(gI2cHandle,
                                         (uint8_t)devAddr,
                                         (uint8_t)(regAddr),
                                         (uint8_t *)&regVal,
                                         2U,
                                         APP_I2C_TRANSACTION_TIMEOUT);
                regVal = 0U;
                ret += Board_i2c8BitRegRd(gI2cHandle,
                                          (uint8_t)devAddr,
                                          (uint8_t)(regAddr),
                                          (uint8_t *)&regVal,
                                          2U,
                                          APP_I2C_TRANSACTION_TIMEOUT);
            break;
            case 2U:
                ret = Board_i2c16BitRegWr(gI2cHandle,
                                          (uint8_t)devAddr,
                                          (uint16_t)(regAddr),
                                          (uint8_t *)&regVal,
                                          1U,
                                          gByteOrder,
                                          APP_I2C_TRANSACTION_TIMEOUT);
                regVal = 0U;
                ret += Board_i2c16BitRegRd(gI2cHandle,
                                           (uint8_t)devAddr,
                                           (uint16_t)(regAddr),
                                           (uint8_t *)&regVal,
                                           1U,
                                           gByteOrder,
                                           APP_I2C_TRANSACTION_TIMEOUT);
            break;
            case 3U:
                ret = Board_i2c16BitRegWr(gI2cHandle,
                                          (uint8_t)devAddr,
                                          (uint16_t)(regAddr),
                                          (uint8_t *)&regVal,
                                          2U,
                                          gByteOrder,
                                          APP_I2C_TRANSACTION_TIMEOUT);
                regVal = 0U;
                ret += Board_i2c16BitRegRd(gI2cHandle,
                                           (uint8_t)devAddr,
                                           (uint16_t)(regAddr),
                                           (uint8_t *)&regVal,
                                           2U,
                                           gByteOrder,
                                           APP_I2C_TRANSACTION_TIMEOUT);
            break;
            default:
            break;
        }
        if(ret == 0)
        {
            App_consolePrintf(" I2C Read back value: 0x%x = 0x%x\r\n",
                        (regAddr),
                        regVal);
        }
        else
        {
            App_consolePrintf(" I2C: Write/Read ERROR !!!\r\n");
            retVal = CSL_EFAIL;
        }
    }
    else
    {
        App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
    }

    return (retVal);
}

static int32_t App_delay(void)
{
    int32_t retVal = CSL_SOK;
    uint32_t timeInMsecs;

    if (gNumArgs > 1)
    {
        timeInMsecs = atoi(gInputArgs[1]);

        App_consolePrintf(" I2C: Waiting for %d msecs ... \r\n", timeInMsecs);
        /* Add delay here */
        App_consolePrintf(" I2C: Wait Done !!!\r\n");
    }
    else
    {
        retVal = CSL_EFAIL;
        App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
    }

    return (retVal);
}

static int32_t App_file(void)
{
    int32_t retVal = CSL_SOK;

    if (gFileReadLoc == 0U)
    {
        FILE *fp;

        if (gNumArgs > 1U)
        {
            strncpy(gFileName, gInputArgs[1], (sizeof (gFileName) - 1U));
            gFileName[sizeof (gFileName) - 1] = '\0';

            fp = fopen(gFileName, "r");
            if (fp == NULL)
            {
                retVal = CSL_EFAIL;
                App_consolePrintf(" I2C: Unable to open file [%s] for reading!!! \r\n", gFileName);
            }
            if (retVal == CSL_SOK)
            {
                App_consolePrintf("\n\r I2C: Reading from file [%s] !!! \r\n", gFileName);
                /* Read from file line by line */
                while ( fgets(gLine, sizeof(gLine), fp) != NULL )
                {
                   /* parse read line here */
                   App_consolePrintf("\n\r Parsing for the line: %s", gLine);
                   gNumArgs = App_tokenizeInput(gLine, gInputArgs);
                   if (gNumArgs)
                   {
                       /* Ignore return types of the function call for file read*/
                       if (strcmp(gInputArgs[0U], "rd") == 0)
                        {
                            (void)App_readRegs();
                        }
                        else if (strcmp(gInputArgs[0U], "wr") == 0)
                        {
                            (void)App_writeReg();
                        }
                        else if (strcmp(gInputArgs[0U], "wait") == 0)
                        {
                            (void)App_delay();
                        }
                        else if (strcmp(gInputArgs[0U], "wr_raw") == 0)
                        {
                            (void)App_writeRegN();
                        }
                        else if (strcmp(gInputArgs[0U], "rd_raw") == 0)
                        {
                            (void)App_readRegRaw();
                        }
                        else if (strcmp(gInputArgs[0U], "probe") == 0)
                        {
                            (void)App_deviceI2cProbeAll(gCurrInst);
                        }
                        else
                        {
                            /* Do nothing here */
                        }
                   }

                }
            }
            if (fp != NULL)
            {
                fclose(fp);
                App_consolePrintf(" I2C: File closed [%s] !!! \r\n", gFileName);
            }
        }
        else
        {
            retVal = CSL_EFAIL;
            App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
        }
    }
    else if (gFileReadLoc == 1U)
    {
        App_consolePrintf("\r\n This feature is not supported currently. Checkout other exciting features!!!\r\n");
    }
    else
    {
        App_consolePrintf("\n\rInvalid File Read Mode Provided!!!\r\n");
    }

    return (retVal);
}

static int32_t App_writeRegN(void)
{
    int32_t retVal = CSL_SOK;
    uint32_t slaveAddr, numWrites, loopCnt;
    uint8_t regVal[APP_I2C_MAX_REG_RD_WR];

    numWrites = gNumArgs - 2;
    if ((gNumArgs > 2) && (numWrites <= APP_I2C_MAX_REG_RD_WR))
    {
        slaveAddr = xstrtoi(gInputArgs[1]);
        if (gAddrDataMode == 0U)
        {
            App_consolePrintf("\n\r I2C: Writing device 0x%02x:\r\n", slaveAddr);
            for (loopCnt = 0U ; loopCnt < numWrites ; loopCnt++)
            {
                regVal[loopCnt] = xstrtoi(gInputArgs[2 + loopCnt]);
                App_consolePrintf(" 0x%x\r\n", regVal[loopCnt]);
            }
            retVal += App_deviceRawWrite8(gCurrInst,
                                          slaveAddr,
                                          &regVal[0U],
                                          numWrites);
            if (retVal != CSL_SOK)
            {
                App_consolePrintf(" I2C: Write ERROR !!!\r\n");
            }
        }
        else
        {
            App_consolePrintf("\n\r I2C: Illegal Device address (0x%x) specified !!!\r\n",
                        slaveAddr);
            App_consolePrintf("Only 8 bit addressing is supported.\r\n");
        }
    }
    else
    {
        App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
    }

    return(retVal);
}

static int32_t App_readRegRaw(void)
{
    int32_t retVal = CSL_SOK;
    uint32_t slaveAddr;
    uint32_t numRegs, loopCnt;
    uint8_t regVal[APP_I2C_MAX_REG_RD_WR];

    if (gNumArgs == 3U)
    {
        slaveAddr = xstrtoi(gInputArgs[1]);
        if (gAddrDataMode == 0U)
        {
            numRegs = xstrtoi(gInputArgs[2]);
            if (numRegs < APP_I2C_MAX_REG_RD_WR)
            {
                App_consolePrintf("\n\r I2C: Reading 0x%02x registers of device 0x%02x ...\r\n",
                            numRegs,
                            slaveAddr);
                for (loopCnt = 0U ; loopCnt < numRegs ; loopCnt++)
                {
                    regVal[loopCnt] = 0;
                }

                retVal += App_deviceRawRead8(gCurrInst,
                                             slaveAddr,
                                             &regVal[0U],
                                             numRegs);
                for (loopCnt = 0U ; loopCnt < numRegs ; loopCnt++)
                {
                    App_consolePrintf(" I2C: 0x%02x = 0x%02x\r\n",
                               (0x0 + loopCnt),
                               regVal[loopCnt]);
                }

                if (retVal != CSL_SOK)
                {
                    App_consolePrintf(" I2C: Read ERROR !!!\r\n");
                }
            }
            else
            {
                App_consolePrintf(
                " I2C: Illegal number of registers to read (0x%x) specified !!!\r\n");
            }
        }
        else
        {
            App_consolePrintf("\n\r I2C: Illegal Device address (0x%x) specified !!!\r\n",
                        slaveAddr);
            App_consolePrintf("Only 8 bit addressing is supported.\r\n");
        }

    }
    else
    {
        retVal = CSL_EFAIL;
        App_consolePrintf(" I2C: Insufficient arguments specified !!!\r\n");
    }

    return (retVal);
}

static int32_t App_deviceI2cProbeAll(uint32_t inst)
{
    int32_t retVal = CSL_SOK;
    uint16_t slaveAddr;

    App_consolePrintf("\n\rProbing for %d is in progress...\r\n", inst);
    /* I2C_open() should have been called for this instance
     * for its proper initialization. */
    if (NULL != gI2cHandle)
    {
        for (slaveAddr = 0U; slaveAddr < 128U; slaveAddr++)
        {
            if (I2C_control(gI2cHandle, I2C_CMD_PROBE, &slaveAddr) ==
                            I2C_STATUS_SUCCESS)
            {
                App_consolePrintf("I2C%d: Passed for address 0x%x !!! \r\n",
                            inst,
                            slaveAddr);
            }
        }
    }

    return (retVal);
}

static int32_t xstrtoi(char *hex)      // hex string to integer
{
    return HextoDec(hex, 0);
}

static int32_t HextoDec(char *hex, int32_t l)
{
    if (*hex == 0)
    {
        return (l);
    }

    return HextoDec(hex + 1, l * 16 + xtod(*hex)); // hex+1?
}

static char xtod(char c)
{
    if ((c >= '0') && (c <= '9'))
    {
        return (c - '0');
    }
    if ((c >= 'A') && (c <= 'F'))
    {
        return (c - 'A' + 10);
    }
    if ((c >= 'a') && (c <= 'f'))
    {
        return (c - 'a' + 10);
    }

    return (c = 0);        // not Hex digit
}

static int32_t App_setupI2CInst(void)
{
    int32_t retVal = CSL_SOK;
    uint8_t i2cInst = 0U;
    /*uint8_t slaveAddr;*/
    I2C_Params i2cParams;

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz; /* 400KHz */

    i2cInst = (uint8_t)gCurrInst;
    /* Configures the I2C instance with the passed parameters*/
    gI2cHandle = I2C_open(i2cInst, &i2cParams);
    if(gI2cHandle == NULL)
	{
		App_consolePrintf("\nI2C Open failed!\n");
        retVal = CSL_EFAIL;
	}
    else
    {
        gInitDone = TRUE;
    }

    return retVal;
}

int32_t App_deviceRawRead8(uint32_t i2cInstId,
                           uint32_t i2cDevAddr,
                           uint8_t *regValue,
                           uint32_t numRegs)
{
    int32_t retVal = CSL_SOK;
    bool status;
    I2C_Transaction i2cXferPrms;

    if ((regValue == NULL) || (numRegs == 0U))
    {
        App_consolePrintf(" I2C%d: DEV 0x%02x: Illegal Params ... ERROR !!!\n",
                  i2cInstId,
                  i2cDevAddr);
        retVal = CSL_EFAIL;
    }
    else
    {
        if (gI2cHandle != NULL)
        {
            /* I2C transfer parameter default initializations */
            I2C_transactionInit(&i2cXferPrms);
            i2cXferPrms.slaveAddress = i2cDevAddr;
            i2cXferPrms.writeBuf     = NULL;
            i2cXferPrms.writeCount   = 0U;
            i2cXferPrms.readBuf      = regValue;
            i2cXferPrms.readCount    = numRegs;
            i2cXferPrms.timeout     = 5000U;

            status = I2C_transfer(gI2cHandle, &i2cXferPrms);
            if (status == FALSE)
            {
                retVal = CSL_EFAIL;
                App_consolePrintf(" I2C%d: DEV 0x%02x: RD ERROR !!!\n",
                            i2cInstId,
                            i2cDevAddr);
            }
        }
        else
        {
            retVal = CSL_EFAIL;
            App_consolePrintf("\n\rI2C instance is not initialized!!! \r\n");
        }
    }

    return (retVal);
}

int32_t App_deviceRawWrite8(uint32_t i2cInstId,
                            uint32_t i2cDevAddr,
                            uint8_t *regValue,
                            uint32_t numRegs)
{
    int32_t retVal = CSL_SOK;
    bool status;
    I2C_Transaction i2cXferPrms;

    if ((regValue == NULL) || (numRegs == 0U))
    {
        App_consolePrintf("I2C%d: DEV 0x%02x: Illegal Params ... ERROR !!!\n",
                    i2cInstId,
                    i2cDevAddr);
        retVal = CSL_EFAIL;
    }
    else
    {
        if (gI2cHandle != NULL)
        {
            /* I2C transfer parameter default initializations */
            I2C_transactionInit(&i2cXferPrms);

            i2cXferPrms.slaveAddress = i2cDevAddr;
            i2cXferPrms.writeBuf     = regValue;
            i2cXferPrms.writeCount   = numRegs;
            i2cXferPrms.readBuf      = NULL;
            i2cXferPrms.readCount    = 0U;
            i2cXferPrms.timeout      = 5000U;

            status = I2C_transfer(gI2cHandle, &i2cXferPrms);
            if (status == FALSE)
            {
                retVal = CSL_EFAIL;
                App_consolePrintf(" I2C%d: DEV 0x%x: ERROR !!! \n",
                            i2cInstId,
                            i2cDevAddr);
            }
        }
        else
        {
            retVal = CSL_EFAIL;
            App_consolePrintf("\n\rI2C instance is not initialized!!! \r\n");
        }
    }

    return (retVal);
}

static void App_consolePrintf(const char *pcString, ...)
{
    char printBuffer[APP_PRINT_BUFFER_SIZE];
    va_list arguments;

    /* Start the var args processing. */
    va_start(arguments, pcString);
    vsnprintf (printBuffer, sizeof(printBuffer), pcString, arguments);
    printf(printBuffer);
    /* Bypassing UART for initial bring up */
#if 0
    App_consolePrintf(printBuffer);
#endif
    /* End the var args processing. */
    va_end(arguments);
}

static int32_t App_getNum(uint32_t *num)
{
    int32_t retVal = CSL_SOK;

    *num = 0U;
#if (APP_USE_UART_CONSOLE == 0U)
    scanf("%d", num);
#else
    if (UART_scanFmt("%d", num) != S_PASS)
    {
        App_consolePrintf("Read from UART Console failed\n");
        retVal = CSL_EFAIL;
    }
#endif

    return (retVal);
}

static int32_t App_gets(char *str)
{
    int32_t retVal = CSL_SOK;

    *str = '\0';
#if (APP_USE_UART_CONSOLE == 0U)
    gets(str);
#else
    if (UART_gets(str, APP_I2C_MAX_IN_STRING) == 0U)
    {
        App_consolePrintf("Read from UART Console failed\n");
        retVal = CSL_EFAIL;
    }
#endif

    return (retVal);
}
