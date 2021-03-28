/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mcasp_poll_test.c
 *
 *  \brief  This file contains the Audio Loopback baremetal application
 *
 *  This test is intended to demonstrate baremetal functionality of McASP
 *  and I2C CSL modules without depending on the LLD libraries.
 *  It will be a good reference for the applications which need
 *  low footprint code base for audio usecase evaluation. Board library is
 *  not used by this test to avoid dependency on LLD libraries. This test
 *  runs in poll mode using CPU for accessing McASP registers. No Debug
 *  messages will be displayed by this test.
 *
 *  On-board audio codec functionality is excerisied by this test. Connect
 *  an audio source to audio input port and headset to audio ouput port of the EVM.
 *  Audio being played at the audio source should be played back at headset
 *  connected to audio output port while running the test.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include <stdbool.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mcasp.h>
#include <ti/csl/csl_edma.h>

#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/src/ip/arm_gic/V0/csl_armGicAux.h>

#ifdef SOC_AM65XX
#include "diag_common_cfg.h"
#include "board_internal.h"
#if defined (__aarch64__)
#include <ti/csl/arch/a53/interrupt.h>
#else
#include <ti/csl/arch/r5/interrupt.h>
#endif
#else
#include <ti/csl/arch/a15/interrupt.h>
#endif

#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/soc.h>
#include <ti/csl/csl_syscfg.h>
#include "aic31.h"
#include "codecif.h"
#include "mcasp_test.h"


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

CSL_ArmGicDistIntrf distrIntrf;
CSL_ArmGicCpuIntrf gCpuIntrf;
CSL_ArmGicIntrParams_t gMcaspIntrParams;

/* Function to initialize interrupt configurations */
static void BoardDiag_IntrInit(void)
{
#if !defined(SOC_AM65XX)
    gCpuIntrf.gicDist               = &distrIntrf;
    gCpuIntrf.cpuIntfBasePtr        = (void *)CSL_MPU_INTC_MPU_PHYS_CPU_IF_REGS;
    distrIntrf.distBasePtr          = (void *)CSL_MPU_INTC_MPU_DISTRIBUTOR_REGS;
    gCpuIntrf.initStatus            = FALSE;
    gCpuIntrf.gicDist->initStatus   = FALSE;
    gCpuIntrf.pDefaultIntrHandlers  = NULL;
    gCpuIntrf.pDefaultUserParameter = NULL;
	CSL_A15_INIT_copyVectorTable();
    CSL_armGicInit(&gCpuIntrf);
#endif
}

static void BoardDiag_AIC31I2SConfigure(uint32_t channel)
{
    volatile unsigned int delay = 0xFFF;

    BoardDiag_AIC31Reset(SOC_I2Cx_BASE);
    while(delay--);

    /* Configure the data format and sampling rate */
    BoardDiag_AIC31DataConfig(SOC_I2Cx_BASE, AIC31_DATATYPE_DSP, SLOT_SIZE, 0);
    BoardDiag_AIC31SampleRateConfig(SOC_I2Cx_BASE, AIC31_MODE_BOTH, SAMPLING_RATE);

    /* Initialize both ADC and DAC */
    BoardDiag_AIC31ADCInit(SOC_I2Cx_BASE);
    BoardDiag_AIC31DACInit(SOC_I2Cx_BASE,channel);
}
#if !defined(SOC_AM65XX)
void BoardDiag_SetupI2C(uint8_t addr)
{
    /* Put i2c in reset/disabled state */
    I2CMasterDisable(SOC_I2Cx_BASE);

    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(SOC_I2Cx_BASE, 24000000,
                        8000000, 100000);

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(SOC_I2Cx_BASE, addr);

    /* Bring i2c out of reset */
    I2CMasterEnable(SOC_I2Cx_BASE);
}

void BoardDiag_SetupI2CTransmit(void)
{
    /* Set data count */
    I2CSetDataCount(SOC_I2Cx_BASE, 2);

    /*
    ** Configure i2c as master-transmitter and to generate stop condition
    */
    I2CMasterControl(SOC_I2Cx_BASE,
            I2C_CFG_MASK_TX | I2C_CFG_MASK_REPEAT_MODE,
            I2C_CFG_CMD_TX | I2C_CFG_CMD_REPEAT_MODE_OFF);

    /*Enable transmit ready and stop condition interrupt*/
    I2CMasterIntEnableEx(SOC_I2Cx_BASE,
                         I2C_INT_TRANSMIT_READY | I2C_INT_STOP_CONDITION);

    /*Generate start conndition*/
    I2CMasterStart(SOC_I2Cx_BASE);

    /*Wait for transmit interrupt to occur*/
    while (I2CMasterIntStatusEx(SOC_I2Cx_BASE, I2C_INT_TRANSMIT_READY) != 0x10) ;

    /*Disable transmit ready and stop condition interrupt*/
    I2CMasterIntDisableEx(SOC_I2Cx_BASE, I2C_INT_TRANSMIT_READY);

    I2CMasterIntDisableEx(SOC_I2Cx_BASE, I2C_INT_STOP_CONDITION);

    /* Send first command word and then the data */
    I2CMasterDataPut(SOC_I2Cx_BASE, 0x00);
    I2CMasterDataPut(SOC_I2Cx_BASE, 0x00);
}
#endif
/*
** Configures the McASP Transmit Section in I2S mode.
*/
static void BoardDiag_McASPI2SConfigure(uint32_t sampleRate)
{

	uint32_t RFMT_DATA;
	uint32_t XFMT_DATA;
	uint32_t mcasp2_rfmt_mask = 0x00030000;
	uint32_t mcasp2_xfmt_mask = 0x00030000;

	McASPRxReset(SOC_MCASP_CFG_BASE);
	McASPTxReset(SOC_MCASP_CFG_BASE);

    /* Set I2S format in the transmitter/receiver format units */
    McASPRxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,
                         MCASP_RX_MODE_NON_DMA);

    McASPTxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,\
                     MCASP_TX_MODE_NON_DMA);

	/* Set 0-bit delay */
	RFMT_DATA = McASPRxFmtGet(SOC_MCASP_CFG_BASE);
	RFMT_DATA &= (~mcasp2_rfmt_mask);
	McASPRxFmtSet(SOC_MCASP_CFG_BASE,(uint32_t)RFMT_DATA);

	XFMT_DATA = McASPTxFmtGet(SOC_MCASP_CFG_BASE);
	XFMT_DATA &= (~mcasp2_xfmt_mask);
	McASPTxFmtSet(SOC_MCASP_CFG_BASE,(uint32_t)XFMT_DATA);

#if defined(SOC_AM65XX)
    McASPTxFmtMaskSet(SOC_MCASP_CFG_BASE, 0xFFFFFFFF);
    McASPRxFmtMaskSet(SOC_MCASP_CFG_BASE, 0xFFFFFFFF);
#endif

    McASPRxFrameSyncCfg(SOC_MCASP_CFG_BASE, 0, MCASP_RX_FS_WIDTH_BIT,
                            MCASP_RX_FS_INT_BEGIN_ON_RIS_EDGE);

    McASPTxFrameSyncCfg(SOC_MCASP_CFG_BASE, 0, MCASP_RX_FS_WIDTH_BIT,
                            MCASP_TX_FS_INT_BEGIN_ON_RIS_EDGE);

	/* configure the clock for receiver */
	McASPRxClkCfg(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_INTERNAL, 0, 1);
	McASPRxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_POL_FALL_EDGE);
	McASPRxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_TX_CLKCHCK_DIV1,
                          0x00, 0xFF);

    if(sampleRate == SAMPLING_RATE_192KHZ)
    {
        /* configure the clock for transmitter */
        McASPTxClkCfg(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL, 1, 1);
        McASPTxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_POL_RIS_EDGE);
        McASPTxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_TX_CLKCHCK_DIV1,
                              0x00, 0xFF);
    }
    else
    {
        /* configure the clock for transmitter 48KHz */
        McASPTxClkCfg(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL, 7, 1);
        McASPTxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_POL_RIS_EDGE);
        McASPTxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_TX_CLKCHCK_DIV1,
                              0x00, 0xFF);
    }

    /* Enable synchronization of RX and TX sections  */
    McASPTxRxClkSyncEnable(SOC_MCASP_CFG_BASE);
    /* Enable the transmitter/receiver slots. I2S uses 2 slots */
    McASPRxTimeSlotSet(SOC_MCASP_CFG_BASE, I2S_SLOTS);
    McASPTxTimeSlotSet(SOC_MCASP_CFG_BASE, I2S_SLOTS);

    /*
    ** Set the serializers
    */
    McASPSerializerTxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_TX);
    McASPSerializerRxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_RX);

    /*
    ** Configure the McASP pins
    ** Output - Frame Sync, Clock, Serializer Rx and Serializer Tx
    **          (Clocks generated internally)
    */
   McASPPinMcASPSet(SOC_MCASP_CFG_BASE, 0xFFFFFFFF);

   McASPPinDirOutputSet(SOC_MCASP_CFG_BASE, MCASP_PIN_AFSX
                                              | MCASP_PIN_ACLKX
                                              | MCASP_PIN_AFSR
                                              | MCASP_PIN_ACLKR
                                              | MCASP_PIN_AHCLKX
                                              | MCASP_PIN_AXR(MCASP_XSER_TX));
   McASPPinDirInputSet(SOC_MCASP_CFG_BASE, MCASP_PIN_AXR(MCASP_XSER_RX));


   /* Enable error interrupts for McASP */
   McASPTxIntEnable(SOC_MCASP_CFG_BASE, MCASP_TX_DMAERROR
                                           | MCASP_TX_CLKFAIL
                                           | MCASP_TX_SYNCERROR
                                           | MCASP_TX_UNDERRUN);

   McASPRxIntEnable(SOC_MCASP_CFG_BASE, MCASP_RX_DMAERROR
                                           | MCASP_RX_CLKFAIL
                                           | MCASP_RX_SYNCERROR
                                           | MCASP_RX_OVERRUN);

}
/*
** Activates the data transmission/reception
** The DMA parameters shall be ready before calling this function.
*/
static void BoardDiag_I2SDataTxRxActivate(void)
{
	/* Start the clocks */
    McASPRxClkStart(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL);
    McASPTxClkStart(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL);

	/* Activate the  serializers */
    McASPTxSerActivate(SOC_MCASP_CFG_BASE);
    McASPRxSerActivate(SOC_MCASP_CFG_BASE);

    /* make sure that the XDATA bit is cleared to zero */
    while (!(McASPTxStatusGet(SOC_MCASP_CFG_BASE) & MCASP_TX_STAT_DATAREADY)) ;

    /* Activate the state machines */
    McASPTxEnable(SOC_MCASP_CFG_BASE);
    McASPRxEnable(SOC_MCASP_CFG_BASE);
}

int BoardDiag_audioLoopbackTest(uint32_t channel,uint32_t samplingRate)
{
    uint32_t rec_buf = 0;
    uint8_t  serailizerXmtStatus;
    uint8_t  serailizerRcvStatus;
    uint32_t sampleCnt  = 0;
    uint32_t maxSamples = 0;

    BoardDiag_AIC31I2SConfigure(channel);
    /* Configure the McASP for I2S */
    BoardDiag_McASPI2SConfigure(samplingRate);
    /* Activate the audio transmission and reception */
    BoardDiag_I2SDataTxRxActivate();

    maxSamples = (TEST_DURATION_SECS * samplingRate);

    while(1)
    {

        serailizerRcvStatus = McASPIsSerializerRcvReady(SOC_MCASP_CFG_BASE,MCASP_XSER_RX);
        if(serailizerRcvStatus)
        {
            rec_buf = McASPRxBufRead(SOC_MCASP_CFG_BASE,MCASP_XSER_RX);
        }

        serailizerXmtStatus = McASPIsSerializerXmtReady(SOC_MCASP_CFG_BASE,MCASP_XSER_TX);
        if(serailizerXmtStatus)
        {
            sampleCnt++;
            McASPTxBufWrite(SOC_MCASP_CFG_BASE,MCASP_XSER_TX,rec_buf);
        }

        if(sampleCnt > maxSamples)
        {
            break;
        }
    }

    return 0;
}

/*
** The main function. Application starts here.
*/
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
#ifdef SOC_AM65XX
    Board_IDInfo_v2 boardInfo;
    bool isBoardConnected = FALSE;
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

#ifdef SOC_AM65XX
    BoardDiag_enableI2C(0, CSL_WKUP_I2C0_CFG_BASE);
    /* Check if GP application card is detected */
    /* Test exits if there is no application card connected.
       However, no error is reported to the caller. */
    if(Board_detectBoard(APP_CARD_DETECT))
    {
        /* Application card connected, confirm that it is a GP App card */
        if(Board_getIDInfo_v2(&boardInfo, BOARD_APP_EEPROM_ADDR) == BOARD_SOK)
        {
            if(strcmp(boardInfo.boardInfo.boardName, "AM6-GPAPPEVM") == 0)
            {
                isBoardConnected = TRUE;
            }
        }
    }
    BoardDiag_enableI2C(0, CSL_I2C0_CFG_BASE);

    if(isBoardConnected == FALSE)
    {
        UART_printf("\nApplication Card not Connected!!\n");
        UART_printf("Exiting the Test...\n");
        return 0;
    }
#endif

    BoardDiag_IntrInit();

    /* Initialize the I2C 0 interface for the codec AIC31 */
    BoardDiag_I2CCodecIfInit(SOC_I2Cx_BASE, INT_CHANNEL_I2C, I2C_SLAVE_CODEC_AIC31);

#ifdef DIAG_STRESS_TEST
    UART_printf("\n*********************************************\n");
    UART_printf  ("*         AUDIO Loopback Stress Test        *\n");
    UART_printf  ("*********************************************\n");

    UART_printf  ("\n Audio codec is configured for 48KHz sampling rate");
	BoardDiag_audioLoopbackTest(HEADPHONE_LR,SAMPLING_RATE_48KHZ);
	UART_printf  ("\n Audio codec is configured for 192KHz sampling rate");
	BoardDiag_audioLoopbackTest(HEADPHONE_LR,SAMPLING_RATE_192KHZ);
#else
    UART_printf("\n*********************************************\n");
    UART_printf  ("*         AUDIO Loopback Test               *\n");
    UART_printf  ("*********************************************\n");

    UART_printf  ("\nPlaying Audio on left channel \n");
	BoardDiag_audioLoopbackTest(HEADPHONE_L,SAMPLING_RATE_48KHZ);
	UART_printf  ("\nPlaying Audio on right channel \n");
	BoardDiag_audioLoopbackTest(HEADPHONE_R,SAMPLING_RATE_48KHZ);
	UART_printf  ("\nPlaying Audio on both left and right\n");
	BoardDiag_audioLoopbackTest(HEADPHONE_LR,SAMPLING_RATE_48KHZ);
#endif

	UART_printf  ("\nAudio Loopback test completed\n");

	return 0;
}
