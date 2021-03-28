/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation. 
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain 
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
 *
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
 *  \file   audio_evmInit.c
 *
 *  \brief  This file contains the board specific code for enabling the use of
 *          audio driver.
 *
 *  (C) Copyright 2018, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#include <stdio.h>
#define SW_I2C
#ifndef SW_I2C
#include <i2c/include/I2c.h>
#endif

#include <Audio_evmInit.h>
#include <mcasp_cfg.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_intr_router.h>
#include <ti/csl/csl_rat.h>
#include <ti/csl/soc.h>
#include <ti/board/board.h>
#include <ti/board/src/j721e_evm/include/board_control.h>
#include <ti/board/src/j721e_evm/include/board_utils.h>

/* I2C Driver Header Files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/udma/udma.h>
#include "MCASP_log.h"

/*============================================================================*/
/*                          MACRO DEFINITIONS                                 */
/*============================================================================*/

/* ========================================================================== */
/*                           MACRO DEFINTIONS                                 */
/* ========================================================================== */

uint32_t vaOffset = 0;

#if defined(AUDIO_DC_ANALOG_TEST)
uint32_t gAudioDCAnlogRxSerIndx[RX_NUM_SERIALIZER] = {Mcasp_SerializerNum_4,
                                                      Mcasp_SerializerNum_5,
                                                      Mcasp_SerializerNum_6,
                                                      Mcasp_SerializerNum_11,
                                                      Mcasp_SerializerNum_12,
                                                      Mcasp_SerializerNum_13};
uint32_t gAudioDCAnlogTxSerIndx[TX_NUM_SERIALIZER] = {Mcasp_SerializerNum_0,
                                                      Mcasp_SerializerNum_1,
                                                      Mcasp_SerializerNum_2,
                                                      Mcasp_SerializerNum_7,
                                                      Mcasp_SerializerNum_8,
                                                      Mcasp_SerializerNum_9};
extern Mcasp_ChanParams mcasp_chanparam[2];
#endif /* #if defined(AUDIO_DC_ANALOG_TEST) */

#if defined (SOC_J721E)
#if defined (_TMS320C6X)
#include <c6x.h>
static void C66x_intrConfig();
#endif
#endif

#if !defined (DEVICE_LOOPBACK)
void IoExpanderConfig(void);
#endif
/**
 *  \brief    Initializes platform specific modules
 *
 *  This function initializes the modules like PLL, DDR, I2C etc
 *  which are required for audio processing. Need to call this function
 *  before doing any HW related operations.
 *
 *  \return    Platform_EOK on Success or error code
 */

void McASP_Enable(void);

#if defined (SOC_J721E)
#if defined (_TMS320C6X)
void C66x_intrConfig(void)
{
    int32_t ret;
    struct tisci_msg_rm_irq_set_req irqSetReq;
    struct tisci_msg_rm_irq_set_resp irqSetResp;

    irqSetReq.valid_params = TISCI_MSG_VALUE_RM_DST_ID_VALID |
                             TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
    irqSetReq.src_id = TISCI_DEV_TIMER0;

    /* src_index 0 for TIMER0 is intr_pend signal */
    irqSetReq.src_index = 0;
    irqSetReq.dst_id = TISCI_DEV_C66SS0_CORE0;

    /* On C66x builds we define OS timer tick in the configuration file to
     * trigger event #21 or #20 for C66x_1 or C66x_2, respectively.
     */
#if defined (BUILD_C66X_1)
    irqSetReq.dst_host_irq = 21;
#elif defined (BUILD_C66X_2)
    irqSetReq.dst_host_irq = 20;
#endif

    ret = Sciclient_rmIrqSet(&irqSetReq, &irqSetResp, SCICLIENT_SERVICE_WAIT_FOREVER);

    if (ret != CSL_PASS)
    {
	    MCASP_log("Irq set failed\n");
    }
}
#endif
#endif

/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
void configureAudio(void)
{
	Board_STATUS stat = BOARD_SOK;
	Board_initCfg arg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;
    Sciclient_ConfigPrms_t sciClientCfg;

	stat = Board_init(arg);
	if(stat != BOARD_SOK)
    {
	    MCASP_log("Board init failed!!");
	}

#if defined (SOC_J721E)
#if defined (_TMS320C6X)
    C66x_intrConfig();
#endif
#endif

#if !defined (DEVICE_LOOPBACK)
    IoExpanderConfig();
#endif

    Sciclient_configPrmsInit(&sciClientCfg);
    Sciclient_init(&sciClientCfg);

    McASP_Enable();

	MCASP_log("\n Pinmux Config complete");
}

#if defined(AUDIO_DC_ANALOG_TEST)
/* Configures the serializers for McASP audio daughter card Beta and above */
void configureAudioDCSer(void)
{
    uint32_t index;

    /* Configure the Rx serializers */
    for (index = 0; index < RX_NUM_SERIALIZER; index++)
    {
        mcasp_chanparam[0].indexOfSersRequested[index] = gAudioDCAnlogRxSerIndx[index];
    }

    /* Configure the Tx serializers */
    for (index = 0; index < TX_NUM_SERIALIZER; index++)
    {
        mcasp_chanparam[1].indexOfSersRequested[index] = gAudioDCAnlogTxSerIndx[index];
    }

    /* Select AUDIO_EXT_REFCLK0 input to use McASP0_AHCLKX signal, and set
     * AUDIO_EXT_REFCLK0 as output */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                   TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK0_IN,
                                   TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK0_IN_PARENT_MCASP_MAIN_0_MCASP_AHCLKX_POUT_0,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);
}
#endif /* #if defined(AUDIO_DC_ANALOG_TEST) */

void McASP_Enable(void)
{
#if defined(AUDIO_DC_ANALOG_TEST)
    /* McASP0 AUXCLK selects MAIN_PLL4_HSDIV0_CLKOUT */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_MCASP0,
                                   TISCI_DEV_MCASP0_AUX_CLK,
                                   TISCI_DEV_MCASP0_AUX_CLK_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    if(Board_isAlpha(BOARD_ID_INFOTAINMENT))
    {
        /* Select AUDIO_EXT_REFCLK2 input to use McASP0_AHCLKX signal, and set
         * AUDIO_EXT_REFCLK2 as output */
        Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                       TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK2_IN,
                                       TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK2_IN_PARENT_MCASP_MAIN_0_MCASP_AHCLKX_POUT_0,
                                       SCICLIENT_SERVICE_WAIT_FOREVER);
    }
    else
    {
        /* Do the additional configurations for Beta board */
        configureAudioDCSer();
    }

    /* Send AUDIO_REFCLK2 OBSCLK0 for debug purposes */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                   TISCI_DEV_BOARD0_OBSCLK0_IN,
                                   TISCI_DEV_BOARD0_OBSCLK0_IN_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);
#elif defined(AUDIO_DC_DIGITAL_TEST)
    /* McASP2 AUXCLK selects MAIN_PLL4_HSDIV0_CLKOUT */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_MCASP2,
                                   TISCI_DEV_MCASP2_AUX_CLK,
                                   TISCI_DEV_MCASP2_AUX_CLK_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);
    /* McASP2 AHCLKX selects AUDIO_EXT_REFCLK1 */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_MCASP2,
                                   TISCI_DEV_MCASP2_MCASP_AHCLKX_PIN_0,
                                   TISCI_DEV_MCASP2_MCASP_AHCLKX_PIN_0_PARENT_MCASP_AHCLKO_MUX_OUT1 ,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    /* McASP6 AUXCLK selects MAIN_PLL4_HSDIV0_CLKOUT */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_MCASP6,
                                   TISCI_DEV_MCASP6_AUX_CLK,
                                   TISCI_DEV_MCASP6_AUX_CLK_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    /* Select McASP6_AHCLKR to use AUDIO_EXT_REFCLK1 */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                   TISCI_DEV_MCASP6_MCASP_AHCLKR_PIN_0,
                                   TISCI_DEV_MCASP6_MCASP_AHCLKR_PIN_0_PARENT_MCASP_AHCLKO_MUX_OUT1,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    /* Enable Frame sync for McASP6 which is used as REFCLK for McASP0 by default */
    Board_pinmuxSetReg(BOARD_SOC_DOMAIN_MAIN, PIN_PRG1_PRU0_GPO6, 0x5000D);
#else
    /* McASP10 AUXCLK selects MAIN_PLL4_HSDIV0_CLKOUT */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_MCASP10,
                                   TISCI_DEV_MCASP10_AUX_CLK,
                                   TISCI_DEV_MCASP10_AUX_CLK_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    /* Select AUDIO_EXT_REFCLK2 input to use McASP10_AHCLKX signal, and set
     * AUDIO_EXT_REFCLK2 as output */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                   TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK2_IN,
                                   TISCI_DEV_BOARD0_AUDIO_EXT_REFCLK2_IN_PARENT_MCASP_MAIN_10_MCASP_AHCLKX_POUT_0,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);

    /* Send AUDIO_REFCLK2 OBSCLK0 for debug purposes */
    Sciclient_pmSetModuleClkParent(TISCI_DEV_BOARD0,
                                   TISCI_DEV_BOARD0_OBSCLK0_IN,
                                   TISCI_DEV_BOARD0_OBSCLK0_IN_PARENT_HSDIV3_16FFT_MAIN_4_HSDIVOUT0_CLK,
                                   SCICLIENT_SERVICE_WAIT_FOREVER);
#endif
}

extern I2C_Handle gIoExpI2cHandle;

void IoExpanderConfig(void)
{
    Board_IoExpCfg_t ioExpCfg;

    /* Set MCASP/TRACE_MUX_S1 to HIGH */
    ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE2_ADDR;
    ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.enableIntr  = false;
    ioExpCfg.ioExpType   = THREE_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_1;
    ioExpCfg.pinNum      = PIN_NUM_2;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;

    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);

    /* Set MCASP/TRACE_MUX_S0 to LOW */
    ioExpCfg.pinNum      = PIN_NUM_1;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;
    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);

#if defined(AUDIO_DC_ANALOG_TEST)
    /* Bring the codec out of reset */
    ioExpCfg.slaveAddr   = BOARD_I2C_AUDIO_IOEXP_DEVICE_ADDR;
    ioExpCfg.i2cInst     = BOARD_I2C_AUDIO_IOEXP_DEVICE_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.enableIntr  = false;
    ioExpCfg.ioExpType   = TWO_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_0;
    ioExpCfg.pinNum      = PIN_NUM_0;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;

    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);
#elif defined(AUDIO_DC_DIGITAL_TEST)
    /* Bring the DIR out of reset */
    ioExpCfg.slaveAddr   = BOARD_I2C_AUDIO_IOEXP_DEVICE_ADDR;
    ioExpCfg.i2cInst     = BOARD_I2C_AUDIO_IOEXP_DEVICE_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.enableIntr  = false;
    ioExpCfg.ioExpType   = TWO_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_1;
    ioExpCfg.pinNum      = PIN_NUM_0;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;

    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);

    ioExpCfg.pinNum      = PIN_NUM_7;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;

    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);
#else
    /* Bring the codec out of reset */
    ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE3_ADDR;
    ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE3_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.enableIntr  = false;
    ioExpCfg.ioExpType   = ONE_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_0;
    ioExpCfg.pinNum      = PIN_NUM_0;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;

    Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);
#endif
}

/*
 * Function to configure SOC specific parameters. This includes SOC
 * specific parameters such as interrupt configuration using Muxes,
 * interrupt configuration etc.
 */
void configMcASP_SocHwInfo()
{
  /* Configure the interrupts for the McASP Instance MCASP_NUM */
  /* ON Keystone, it involves CIC programming as well.
   * The McASP does that internally, if configured with the correct parameters.
   * Such as muxNum, muxInEvent, muxOutEvent,
   * cpuInEventNum, cpuIntNum
  */
    Mcasp_HwInfo hwInfo;

    Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);

     /* Write back */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}
/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
