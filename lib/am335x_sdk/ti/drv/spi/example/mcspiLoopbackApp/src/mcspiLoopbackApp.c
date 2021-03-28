 /*
 *  Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mcspiLoopbackApp.c
 *
 *  \brief This file contains the application which demonstrates McSPI loopback
 *         which transfers some data pattern from data I/O signal & receives
 *         the data from same data I/O signal.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include "stdint.h"
#include <stdio.h>
#include <ti/csl/example/utils/common/inc/app_utils.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>

#include <ti/board/board.h>

#include <ti/osal/osal.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>

/* SPI Header files */
#include <ti/drv/spi/SPI.h>
#include <ti/csl/csl_mcspi.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#if defined SOC_AM335x
#include "am335x_pinmux.h"
#endif
#if defined SOC_AM437x
#include "am43xx_pinmux.h"
#endif
#if defined(SOC_AM335x) || defined(SOC_AM437x)
#include "chipdb_defs.h"
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define McSPI_DATA_COUNT            50U // Data Count Transaction

#if defined(SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
#define UART_INSTANCE 2
#else
#define UART_INSTANCE 0
#endif

#define MCSPI_INSTANCE 0

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint8_t           gRxBuffer[McSPI_DATA_COUNT];
uint8_t           gTxBuffer[McSPI_DATA_COUNT];

UART_Handle gUartHandle;

SPI_Handle gSpiHandle;

/* UART parameters structure*/
const UART_Params gUserParams = {
    UART_MODE_BLOCKING,     /* readMode */
    UART_MODE_BLOCKING,     /* writeMode */
    SemaphoreP_WAIT_FOREVER,/* readTimeout */
    SemaphoreP_WAIT_FOREVER,/* writeTimeout */
    NULL,                  /* readCallback */
    NULL,                 /* writeCallback */
    UART_RETURN_NEWLINE,  /* readReturnMode */
    UART_DATA_TEXT,       /* readDataMode */
    UART_DATA_TEXT,       /* writeDataMode */
    UART_ECHO_ON,         /* readEcho */
    115200,               /* baudRate */
    UART_LEN_8,           /* dataLength */
    UART_STOP_ONE,        /* stopBits */
    UART_PAR_NONE         /* parityType */
};

/* SPI parameters structure Master mode*/
SPI_Params gSpiParams = {
    SPI_MODE_BLOCKING,  /* transferMode */
    SemaphoreP_WAIT_FOREVER,/* transferTimeout */
    NULL,               /* transferCallbackFxn */
    SPI_MASTER,         /* mode */
    1000000,            /* bitRate */
    8,                  /* dataSize */
    SPI_POL0_PHA0,      /* frameFormat */
    NULL                /* custom */
};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static void McSPIInitializeBuffers(void);
void padConfig_prcmEnable();
void spi_test(UArg arg0, UArg arg1);
static int32_t McSPIVerifyData(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void padConfig_prcmEnable()
{
#if defined (SOC_DRA72x) || (SOC_DRA75x) || defined (SOC_DRA78x)
    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK;

    Board_init(boardCfg);
#endif
    /* Loopback mode is not available for MCSPI. To test Loopback on McSPI,
     * Receive Bit is enabled on both Tx and Rx pins of McSPI
     */
#if defined(SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART2_CTSN, 0x00050002);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART2_RTSN, 0x00010001);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_SPI1_SCLK,0x000C0000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_SPI1_D1,0x000C0000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_SPI1_D0,0x000C0000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_SPI1_CS0,0x00060000);
#if defined (_TMS320C6X)
    /*
     * AM57x DSP does not have a default Xbar connection for UART
     * interrupts, need to use a reserved IRQ Xbar instance for Xbar
     * interrupt configuration
     */
     /* Use reserved XBAR_INST_DSP1_IRQ_34 */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_34, CSL_XBAR_UART3_IRQ);
#endif
#if defined (SOC_AM572x) || defined(SOC_AM574x)
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_SPI1_CS1,0x00060000);
#endif
#endif
#if defined (SOC_TDA2XX) || defined(SOC_TDA2PX) || defined (SOC_TDA2EX)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_SPI1_SCLK,0x000C0000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_SPI1_D1,0x000C0000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_SPI1_D0,0x000C0000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_SPI1_CS0,0x00060000);
#if defined (SOC_TDA2XX) || defined(SOC_TDA2PX)
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_SPI1_CS1,0x00060000);
#endif
    /* IPU1 Crossbar */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_44, CSL_XBAR_UART1_IRQ);
#endif
#if defined(SOC_TDA3XX)
    /*MCSPI1 prcm*/
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MCSPI1_CLKCTRL, 0x02);
    while (HW_RD_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MCSPI1_CLKCTRL) !=
            0x02U)
        {
            ;
        }
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_UART1_TXD,0x00000000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_D0,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_D1,0x00040000);

    /* IPU1 crossbar */
#if defined (__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_44, CSL_XBAR_UART1_IRQ);
#elif defined(_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_44, CSL_XBAR_UART1_IRQ);
#endif
#endif
#if defined(SOC_AM335x) || defined(SOC_AM437x)
    uint32_t ctrlModBase;

    /* UART */
    ctrlModBase = CHIPDBBaseAddress(CHIPDB_MOD_ID_CONTROL_MODULE, UART_INSTANCE);
    HW_WR_REG32(ctrlModBase+PIN_UART0_TXD, PIN_MODE(0));
    HW_WR_REG32(ctrlModBase+PIN_UART0_RXD, PIN_MODE(0) | PIN_RX_ACTIVE);
    /* SPI0 */
    ctrlModBase = CHIPDBBaseAddress(CHIPDB_MOD_ID_CONTROL_MODULE, MCSPI_INSTANCE);
    HW_WR_REG32(ctrlModBase+PIN_SPI0_SCLK, PIN_MODE(0) | PIN_RX_ACTIVE);
    HW_WR_REG32(ctrlModBase+PIN_SPI0_D0, PIN_MODE(0) | PIN_RX_ACTIVE);
    HW_WR_REG32(ctrlModBase+PIN_SPI0_D1, PIN_MODE(0) | PIN_RX_ACTIVE);
    HW_WR_REG32(ctrlModBase+PIN_SPI0_CS0, PIN_MODE(0) | PIN_RX_ACTIVE);
#endif
}

void spi_initConfig(void)
{
    SPI_v1_HWAttrs spi_cfg;

    /* Get the default UART init configurations */
    SPI_socGetInitCfg(MCSPI_INSTANCE, &spi_cfg);

    /* Modify the default SPI configurations if necessary */
    spi_cfg.chnCfg[spi_cfg.chNum].dataLineCommMode = MCSPI_DATA_LINE_COMM_MODE_4;

    /* Set the default UART init configurations */
    SPI_socSetInitCfg(MCSPI_INSTANCE, &spi_cfg);
}

int main(void)
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(spi_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Do the necessary set up configurations for McSPI.*/
    SPI_init();

    /* Start BIOS */
    BIOS_start();
    return (0);
}

void spi_test(UArg arg0, UArg arg1)
{
    UART_Params      params;
    int32_t retVal;
    SPI_Transaction transaction;
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
    Board_initCfg boardCfg;
#endif

    char echoPrompt[] = "\nMcSPI Internal Loopback test app started";
    char echoPrompt1[] = "\nThe Mode of transfer is Interrupt Mode";
    char echoPrompt2[] = "\nMcSPI Data Transmission is successful";
    char echoPrompt3[] = "\nMcSPI Data Transmission is Failed";

#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
    boardCfg =   BOARD_INIT_MODULE_CLOCK;
    Board_init(boardCfg);
#endif
/*Pad configuration and PRCM enable*/
    padConfig_prcmEnable();

#if defined(SOC_TDA3XX)
    AppUtils_defaultInit();
#endif
    /* Set the UART Parameters */
    UART_init();
    params = gUserParams;

    gUartHandle = UART_open(UART_INSTANCE, &params);
    if(gUartHandle == NULL)
    {
        printf("\nError opening UART driver\n");
    }

    UART_write(gUartHandle,echoPrompt,sizeof(echoPrompt));
    UART_write(gUartHandle,echoPrompt1,sizeof(echoPrompt1));

    /* Modify the default SPI configurations if necessary */
    spi_initConfig();

    /* Open MCSPI instance 1 driver */
    gSpiHandle = SPI_open(MCSPI_INSTANCE, &gSpiParams);
    if(gSpiHandle == NULL)
    {
        printf("\nError opening MCSPI driver\n");
    }

    McSPIInitializeBuffers();

    transaction.count = McSPI_DATA_COUNT;
    transaction.txBuf = gTxBuffer;
    transaction.rxBuf = gRxBuffer;
    SPI_transfer(gSpiHandle, &transaction);

    retVal = McSPIVerifyData();

    if(retVal != 0)
    {
        UART_write(gUartHandle,echoPrompt3,sizeof(echoPrompt3));
    }
    else
    {
        UART_write(gUartHandle,echoPrompt2,sizeof(echoPrompt2));
    }

    SPI_close(gSpiHandle);
}

static void McSPIInitializeBuffers(void)
{
    uint32_t index = 0;

    for (index = 0; index < McSPI_DATA_COUNT; index++)
    {
        /* Initialize the gTxBuffer McSPI1 with a known pattern of data */
            gTxBuffer[index] = index;
        /* Initialize the gRxBuffer McSPI1 with 0 */
        gRxBuffer[index] = (uint32_t) 0;
    }
}

static int32_t McSPIVerifyData(void)
{
    uint32_t index = 0;
    int32_t retVal = 0;

    for (index = 0; index < McSPI_DATA_COUNT; index++)
    {
        if(gRxBuffer[index] !=  gTxBuffer[index])
        {
            retVal = -1;
            break;
        }
    }

    return retVal;
}
/********************************* End Of File ******************************/
