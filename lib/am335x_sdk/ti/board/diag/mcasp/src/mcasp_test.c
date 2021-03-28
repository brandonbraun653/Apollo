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
 *  \file   mcasp_test.c
 *
 *  \brief  This file contains the Audio Loopback baremetal application
 *
 *  This test is intended to demonstrate baremetal functionality of McASP
 *  EDMA, and I2C CSL modules without depending on the LLD libraries.
 *  It will be a good reference for the applications which need
 *  low footprint code base for audio usecase evaluation. Board library is
 *  not used by this test to avoid dependency on LLD libraries.
 *  This test can be executed on both ARM and DSP cores.
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
#include <ti/csl/src/ip/i2c/V0/i2c.h>
#ifdef BUILD_DSP
#include <ti/csl/arch/c67x/interrupt.h>
#else
#include <ti/csl/arch/arm9/interrupt.h>
#endif
#include <ti/csl/soc.h>
#include <ti/csl/csl_syscfg.h>
#include "aic31.h"
#include "codecif.h"
#include "mcasp_test.h"
#include "uart_config.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Global counters to keep track of errors. Can be removed before releasing  */
uint32_t                       uartBaseAddr = CSL_UART_2_REGS;
uint32_t                       complInterruptCounter = 0x00;
uint32_t                       errInterruptCounter   = 0x00;

uint8_t                        dataToSlave;
uint8_t                        dataFromSlave;

static uint8_t loopBuf[NUM_SAMPLES_LOOP_BUF * BYTES_PER_SAMPLE] = {0};
/*
** Transmit buffers. If any new buffer is to be added, define it here and
** update the NUM_BUF.
*/
static uint8_t txBuf0[AUDIO_BUF_SIZE];
static uint8_t txBuf1[AUDIO_BUF_SIZE];
static uint8_t txBuf2[AUDIO_BUF_SIZE];

/*
** Receive buffers. If any new buffer is to be added, define it here and
** update the NUM_BUF.
*/
static uint8_t rxBuf0[AUDIO_BUF_SIZE];
static uint8_t rxBuf1[AUDIO_BUF_SIZE];
static uint8_t rxBuf2[AUDIO_BUF_SIZE];

/*
** Next buffer to receive data. The data will be received in this buffer.
*/
static volatile unsigned int nxtBufToRcv = 0;

/*
** The RX buffer which filled latest.
*/
static volatile unsigned int lastFullRxBuf = 0;

/*
** The offset of the paRAM ID, from the starting of the paRAM set.
*/
static volatile unsigned short parOffRcvd = 0;

/*
** The offset of the paRAM ID sent, from starting of the paRAM set.
*/
static volatile uint16_t       parOffSent = 0;

/*
** The offset of the paRAM ID to be sent next, from starting of the paRAM set.
*/
static volatile unsigned short parOffTxToSend = 0;

/*
** The transmit buffer which was sent last.
*/
static volatile unsigned int lastSentTxBuf = NUM_BUF - 1;

/* Array of receive buffer pointers */
static unsigned int const rxBufPtr[NUM_BUF] =
{
   (uint32_t) rxBuf0,
   (uint32_t) rxBuf1,
   (uint32_t) rxBuf2
};

/* Array of transmit buffer pointers */
static uint32_t const txBufPtr[NUM_BUF] =
{
    (uint32_t) txBuf0,
    (uint32_t) txBuf1,
    (uint32_t) txBuf2
};

/*
** Default paRAM for Transmit section. This will be transmitting from
** a loop buffer.
*/
static EDMA3CCPaRAMEntry const txDefaultPar =
{
    (uint32_t) (EDMA3CC_OPT_DAM | OPT_FIFO_WIDTH),               /* Opt field */
    (uint32_t) loopBuf,                         /* source address */
    (uint16_t) (BYTES_PER_SAMPLE),             /* aCnt */
    (uint16_t) (NUM_SAMPLES_LOOP_BUF),         /* bCnt */
    (uint32_t) (SOC_MCASP_BASE),               /* dest address */
    (uint16_t) (BYTES_PER_SAMPLE),             /* source bIdx */
    (uint16_t) (0),                            /* dest bIdx */
    (uint16_t) (PAR_TX_START * SIZE_PARAMSET), /* link address */
    (uint16_t) (0),                            /* bCnt reload value */
    (uint16_t) (0),                            /* source cIdx */
    (uint16_t) (0),                            /* dest cIdx */
    (uint16_t) 1                               /* cCnt */
};

/*
** Default paRAM for Receive section. This will be transmitting from
** a loop buffer.
*/
static EDMA3CCPaRAMEntry const rxDefaultPar =
{
    (uint32_t) (EDMA3CC_OPT_SAM | OPT_FIFO_WIDTH),               /* Opt field */
    (uint32_t) SOC_MCASP_BASE,                         /* source address */
    (uint16_t) (BYTES_PER_SAMPLE),             /* aCnt */
    (uint16_t) (1),         /* bCnt */
    (uint32_t) (rxBuf0),               /* dest address */
    (uint16_t) (0),             /* source bIdx */
    (uint16_t) (BYTES_PER_SAMPLE),                            /* dest bIdx */
    (uint16_t) (PAR_RX_START * SIZE_PARAMSET), /* link address */
    (uint16_t) (0),                            /* bCnt reload value */
    (uint16_t) (0),                            /* source cIdx */
    (uint16_t) (0),                            /* dest cIdx */
    (uint16_t) 1                               /* cCnt */
};

/*
** Assigns loop job for a parameter set
*/
static void BoardDiag_ParamTxLoopJobSet(unsigned short parId)
{
    EDMA3CCPaRAMEntry paramSet;

    memcpy(&paramSet, &txDefaultPar, SIZE_PARAMSET);

    /* link the paRAM to itself */
    paramSet.linkAddr = parId * SIZE_PARAMSET;

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, parId, &paramSet);
}

/*
** Activates the DMA transfer for a parameter set from the given buffer.
*/
static void BoardDiag_BufferRxDMAActivate(unsigned int rxBuf, unsigned short parId,
                                          unsigned short parLink)
{
    EDMA3CCPaRAMEntry paramSet;

    /* Copy the default paramset */
    memcpy(&paramSet, &rxDefaultPar, SIZE_PARAMSET - 2);

    /* Enable completion interrupt */
    paramSet.opt |= RX_DMA_INT_ENABLE;
    paramSet.destAddr =  rxBufPtr[rxBuf];
    paramSet.bCnt =  NUM_SAMPLES_PER_AUDIO_BUF;
    paramSet.linkAddr = parLink * SIZE_PARAMSET ;

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, parId, &paramSet);
}

/*
** This function will be called once receive DMA is completed
*/
static void BoardDiag_McASPRxDMAComplHandler(void)
{
    unsigned short nxtParToUpdate;

    /*
    ** Update lastFullRxBuf to indicate a new buffer reception
    ** is completed.
    */
    lastFullRxBuf = (lastFullRxBuf + 1) % NUM_BUF;
    nxtParToUpdate =  PAR_RX_START + parOffRcvd;
    parOffRcvd = (parOffRcvd + 1) % NUM_PAR;

    /*
    ** Update the DMA parameters for the received buffer to receive
    ** further data in proper buffer
    */
    BoardDiag_BufferRxDMAActivate(nxtBufToRcv, nxtParToUpdate,
                                  PAR_RX_START + parOffRcvd);

    /* update the next buffer to receive data */
    nxtBufToRcv = (nxtBufToRcv + 1) % NUM_BUF;
}

/*
** This function will be called once transmit DMA is completed
*/
static void BoardDiag_McASPTxDMAComplHandler(void)
{
    BoardDiag_ParamTxLoopJobSet((unsigned short)(PAR_TX_START + parOffSent));

    parOffSent = (parOffSent + 1) % NUM_PAR;
}

/*
** EDMA transfer completion ISR
*/
static void BoardDiag_EDMA3CCComplIsr(void)
{
#ifdef BUILD_DSP
	IntEventClear(CSL_INTC_EVENTID_EDMA3CC_INT1);
#else
	IntSystemStatusClear(SYS_INT_CCINT0);
#endif

    /* Check if receive DMA completed */
    if(EDMA3GetIntrStatus(SOC_EDMA3_CC_BASE) & (1 << EDMA3_CHA_MCASP_RX))
    {
        /* Clear the interrupt status for the 0th channel */
        EDMA3ClrIntr(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_RX);
        BoardDiag_McASPRxDMAComplHandler();
    }

    /* Check if transmit DMA completed */
    if(EDMA3GetIntrStatus(SOC_EDMA3_CC_BASE) & (1 << EDMA3_CHA_MCASP_TX))
    {
        /* Clear the interrupt status for the first channel */
        EDMA3ClrIntr(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX);
        BoardDiag_McASPTxDMAComplHandler();
    }
}

static void BoardDiag_AIC31I2SConfigure(void)
{
    volatile unsigned int delay = 0xFFF;

    BoardDiag_AIC31Reset(SOC_I2Cx_BASE);
    while(delay--);

    /* Configure the data format and sampling rate */
    BoardDiag_AIC31DataConfig(SOC_I2Cx_BASE, AIC31_DATATYPE_I2S, SLOT_SIZE, 0);
    BoardDiag_AIC31SampleRateConfig(SOC_I2Cx_BASE, AIC31_MODE_BOTH, SAMPLING_RATE);

    /* Initialize both ADC and DAC */
    BoardDiag_AIC31ADCInit(SOC_I2Cx_BASE);
    BoardDiag_AIC31DACInit(SOC_I2Cx_BASE,HEADPHONE_LR);
}

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

/*
** Initializes the DMA parameters.
** The TX basic paRAM set (channel) is 12.
**
** The TX paRAM sets will be initialized to transmit from the loop buffer.
** The size of the loop buffer can be configured.
** The transfer completion interrupt will not be enabled for paRAM set 1;
** paRAM set 1 will be linked to linked paRAM set starting (PAR_TX_START) of TX.
** All other paRAM sets will be linked to itself.
** and further transmission only happens via linked paRAM set.
** For example, if the PAR_TX_START value is 72, and the number of paRAMS is 2,
** So transmission paRAM set linking will be initialized as 1-->72-->73, 73->73.
*/
static void BoardDiag_I2SDMAParamInit(void)
{
    EDMA3CCPaRAMEntry paramSet;
    int idx = 0;


    /* Initialize the 0th paRAM set for receive */
        memcpy(&paramSet, &rxDefaultPar, SIZE_PARAMSET);

        EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_RX, &paramSet);

        /* further paramsets, enable interrupt */
        paramSet.opt |= RX_DMA_INT_ENABLE;

        for(idx = 0 ; idx < NUM_PAR; idx++)
        {
            paramSet.destAddr = rxBufPtr[idx];

            paramSet.linkAddr = (PAR_RX_START + ((idx + 1) % NUM_PAR))
                                 * (SIZE_PARAMSET);

            paramSet.bCnt =  NUM_SAMPLES_PER_AUDIO_BUF;

            /*
            ** for the first linked paRAM set, start receiving the second
            ** sample only since the first sample is already received in
            ** rx buffer 0 itself.
            */
            if( 0 == idx)
            {
                paramSet.destAddr += BYTES_PER_SAMPLE;
                paramSet.bCnt -= BYTES_PER_SAMPLE;
            }

            EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, (PAR_RX_START + idx), &paramSet);
        }

        /* Initialize the required variables for reception */
        nxtBufToRcv = idx % NUM_BUF;
        lastFullRxBuf = NUM_BUF - 1;
        parOffRcvd = 0;

        /* Initialize the 1st paRAM set for transmit */
        memcpy(&paramSet, &txDefaultPar, SIZE_PARAMSET);

        EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX, &paramSet);

        /* rest of the params, enable loop job */
        for(idx = 0 ; idx < NUM_PAR; idx++)
        {
            BoardDiag_ParamTxLoopJobSet(PAR_TX_START + idx);
        }

        /* Initialize the variables for transmit */
        parOffSent = 0;
        lastSentTxBuf = NUM_BUF - 1;
}

/*
** Configures the McASP Transmit Section in I2S mode.
*/
static void BoardDiag_McASPI2SConfigure(void)
{
	McASPRxReset(SOC_MCASP_CFG_BASE);
	McASPTxReset(SOC_MCASP_CFG_BASE);

	/* Enable the FIFOs for DMA transfer */
	McASPReadFifoEnable(SOC_MCASP_CFG_BASE, 1, 1);
	McASPWriteFifoEnable(SOC_MCASP_CFG_BASE, 1, 1);



    /* Set I2S format in the transmitter/receiver format units */
    McASPRxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,
                         MCASP_RX_MODE_DMA);
    McASPTxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,\
    		MCASP_TX_MODE_DMA);

    McASPRxFrameSyncCfg(SOC_MCASP_CFG_BASE, 2, MCASP_RX_FS_WIDTH_WORD,
                            MCASP_RX_FS_EXT_BEGIN_ON_RIS_EDGE);
    McASPTxFrameSyncCfg(SOC_MCASP_CFG_BASE, 2, MCASP_TX_FS_WIDTH_WORD,
                            MCASP_TX_FS_EXT_BEGIN_ON_RIS_EDGE);

    /* configure the clock for receiver */
	McASPRxClkCfg(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_EXTERNAL, 0, 0);
	McASPRxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_POL_RIS_EDGE);
	McASPRxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_RX_CLKCHCK_DIV32,
						  0x00, 0xFF);

    /* configure the clock for transmitter */
    McASPTxClkCfg(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_EXTERNAL, 0, 0);
    McASPTxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_POL_FALL_EDGE);
    McASPTxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_TX_CLKCHCK_DIV32,
                          0x00, 0xFF);

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
   McASPPinDirOutputSet(SOC_MCASP_CFG_BASE, MCASP_PIN_AXR(MCASP_XSER_TX));
   McASPPinDirInputSet(SOC_MCASP_CFG_BASE, MCASP_PIN_AFSX
											  | MCASP_PIN_ACLKX
											  | MCASP_PIN_AFSR
											  | MCASP_PIN_ACLKR
											  | MCASP_PIN_AXR(MCASP_XSER_RX));

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
    McASPRxClkStart(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_EXTERNAL);
    McASPTxClkStart(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_EXTERNAL);

    /* Enable EDMA for the transfer */
    EDMA3EnableTransfer(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_RX,
                            EDMA3_TRIG_MODE_EVENT);
    EDMA3EnableTransfer(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX,
                        EDMA3_TRIG_MODE_EVENT);

    /* Activate the  serializers */
    McASPTxSerActivate(SOC_MCASP_CFG_BASE);
    McASPRxSerActivate(SOC_MCASP_CFG_BASE);

    /* make sure that the XDATA bit is cleared to zero */
    while (!McASPTxStatusGet(SOC_MCASP_CFG_BASE) & MCASP_TX_STAT_DATAREADY) ;

    /* Activate the state machines */
    McASPTxEnable(SOC_MCASP_CFG_BASE);
    McASPRxEnable(SOC_MCASP_CFG_BASE);
}

void BoardDiag_ConfigMcaspPinMux(void)
{


	 /* Write to the pinmux registers to enable the mcasp1 and i2c0            */
	    hSysCfg->PINMUX8 &= (~(CSL_SYSCFG_PINMUX8_PINMUX8_23_20_MASK | \
	                         CSL_SYSCFG_PINMUX8_PINMUX8_27_24_MASK  | \
                             CSL_SYSCFG_PINMUX8_PINMUX8_31_28_MASK));
	    hSysCfg->PINMUX8  |= 0x21100000u;  /* Mcasp1, UART Rx and I2c0 */

	    hSysCfg->PINMUX9 &= ~(CSL_SYSCFG_PINMUX9_PINMUX9_3_0_MASK);
	    hSysCfg->PINMUX9 |= 0x2;  /* UART Tx */

	    hSysCfg->PINMUX11 &= (~(CSL_SYSCFG_PINMUX11_PINMUX11_23_20_MASK |\
	                          CSL_SYSCFG_PINMUX11_PINMUX11_27_24_MASK |\
	                          CSL_SYSCFG_PINMUX11_PINMUX11_31_28_MASK));
	    hSysCfg->PINMUX11 |= 0x11100000u;  /* Mcasp1          */

	    hSysCfg->PINMUX12 &= (~(CSL_SYSCFG_PINMUX12_PINMUX12_31_28_MASK |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_27_24_MASK |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_23_20_MASK |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_19_16_MASK |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_15_12_MASK |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_11_8_MASK  |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_7_4_MASK   |\
	                          CSL_SYSCFG_PINMUX12_PINMUX12_3_0_MASK));
	    hSysCfg->PINMUX12 |= 0x11111111u;  /* Mcasp1          */

	    hSysCfg->PINMUX13 &= (~(CSL_SYSCFG_PINMUX13_PINMUX13_3_0_MASK   |\
	                   CSL_SYSCFG_PINMUX13_PINMUX13_7_4_MASK   |\
	                   CSL_SYSCFG_PINMUX13_PINMUX13_11_8_MASK  |\
	                   CSL_SYSCFG_PINMUX13_PINMUX13_15_12_MASK |\
	                   CSL_SYSCFG_PINMUX13_PINMUX13_19_16_MASK |\
	                   CSL_SYSCFG_PINMUX13_PINMUX13_23_20_MASK));
	    hSysCfg->PINMUX13 |= 0x00111111u;  /* Mcasp1*/
}

/*
** Error ISR for McASP
*/
static void BoardDiag_McASPErrorIsr(void)
{
#ifdef BUILD_DSP
	IntEventClear(CSL_INTC_EVENTID_AXRINT);
    ; /* Perform any error handling here.*/
#else
    IntSystemStatusClear(SYS_INT_MCASPINT);
#endif
}

/*
** Sets up the interrupts for EDMA in AINTC
*/
static void BoardDiag_EDMA3IntSetup(void)
{
#ifdef BUILD_DSP
	Intc_IntRegister(C674X_MASK_INT5, BoardDiag_EDMA3CCComplIsr);
	IntEventMap(C674X_MASK_INT5, CSL_INTC_EVENTID_EDMA3CC_INT1);
	Intc_IntEnable(C674X_MASK_INT5);
#else
	Intc_IntRegister(SYS_INT_CCINT0, BoardDiag_EDMA3CCComplIsr);
	IntChannelSet(SYS_INT_CCINT0, INT_CHANNEL_EDMACC);
	Intc_SystemEnable(SYS_INT_CCINT0);
#endif
}

/*
** Sets up the error interrupts for McASP in AINTC
*/
static void BoardDiag_McASPErrorIntSetup(void)
{
	/* Register the error ISR for McASP */
#ifdef BUILD_DSP
	Intc_IntRegister(C674X_MASK_INT6, BoardDiag_McASPErrorIsr);
	IntEventMap(C674X_MASK_INT6, CSL_INTC_EVENTID_AXRINT);
	Intc_IntEnable(C674X_MASK_INT6);
#else
	Intc_IntRegister(SYS_INT_MCASPINT, BoardDiag_McASPErrorIsr);
	IntChannelSet(SYS_INT_MCASPINT, INT_CHANNEL_MCASP);
	Intc_SystemEnable(SYS_INT_MCASPINT);
#endif
}

/*
** Activates the DMA transfer for a parameterset from the given buffer.
*/
void BoardDiag_BufferTxDMAActivate(unsigned int txBuf, unsigned short numSamples,
                                   unsigned short parId, unsigned short linkPar)
{
    EDMA3CCPaRAMEntry paramSet;

    /* Copy the default paramset */
    memcpy(&paramSet, &txDefaultPar, SIZE_PARAMSET - 2);

    /* Enable completion interrupt */
    paramSet.opt |= TX_DMA_INT_ENABLE;
    paramSet.srcAddr =  txBufPtr[txBuf];
    paramSet.linkAddr = linkPar * SIZE_PARAMSET;
    paramSet.bCnt = numSamples;

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, parId, &paramSet);
}

/*
** The main function. Application starts here.
*/
int main(void)
{
   uint16_t parToSend;
   uint16_t parToLink;
   uint32_t sampleCnt = 0;

   BoardDiag_ConfigMcaspPinMux();

   Intc_Init();

   UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
                  UART_STOP_BIT_1, UART_PARITY_NONE,
                  UART16x_OPER_MODE);
   UARTConfigPrintf(uartBaseAddr,"\n*******************************************\n");
   UARTConfigPrintf(uartBaseAddr,  "*         Audio Loopback Test             *\n");
   UARTConfigPrintf(uartBaseAddr,  "*******************************************\n");

   /* Initialize the I2C 0 interface for the codec AIC31 */
   BoardDiag_I2CCodecIfInit(SOC_I2Cx_BASE, INT_CHANNEL_I2C, I2C_SLAVE_CODEC_AIC31);

   EDMAsetRegion(EDMA3_CC_REGION);
   EDMA3Init(SOC_EDMA3_CC_BASE, EDMA3_CC_QUEUE);
   BoardDiag_EDMA3IntSetup();

   BoardDiag_McASPErrorIntSetup();

#ifdef BUILD_DSP
   Intc_SystemEnable();
#else
   IntMasterIRQEnable();
   IntGlobalEnable();
   IntIRQEnable();
#endif

   /* Request EDMA channels */
   EDMA3RequestChannel(SOC_EDMA3_CC_BASE,
					   EDMA3_CHANNEL_TYPE_DMA,
					   EDMA3_CHA_MCASP_TX,
					   EDMA3_CHA_MCASP_TX,
					   EDMA3_CC_QUEUE);

   EDMA3RequestChannel(SOC_EDMA3_CC_BASE,
   					   EDMA3_CHANNEL_TYPE_DMA,
   					   EDMA3_CHA_MCASP_RX,
   					   EDMA3_CHA_MCASP_RX,
   					   EDMA3_CC_QUEUE);

   /* Initialize the DMA parameters */
   BoardDiag_I2SDMAParamInit();

   BoardDiag_AIC31I2SConfigure();

   /* Configure the McASP for I2S */
   BoardDiag_McASPI2SConfigure();

   UARTConfigPrintf(uartBaseAddr,  "Starting Audio Loopback...\n");
   UARTConfigPrintf(uartBaseAddr,  "Check the Headset/Speaker Audio Output\n");
   /* Activate the audio transmission and reception */
   BoardDiag_I2SDataTxRxActivate();

   /*
      ** Loop forever. if a new buffer is received, the lastFullRxBuf will be
      ** updated in the rx completion ISR. if it is not the lastSentTxBuf,
      ** buffer is to be sent. This has to be mapped to proper paRAM set.
      */
      while(1)
      {
          if(lastFullRxBuf != lastSentTxBuf)
          {
              if(sampleCnt > TEST_SAMPLE_COUNT)
              {
                 break;
              }

              /*
              ** Start the transmission from the link paramset. The param set
              ** 1 will be linked to param set at PAR_TX_START. So do not
              ** update paRAM set1.
              */
              parToSend =  PAR_TX_START + (parOffTxToSend % NUM_PAR);
              parOffTxToSend = (parOffTxToSend + 1) % NUM_PAR;
              parToLink  = PAR_TX_START + parOffTxToSend;

              lastSentTxBuf = (lastSentTxBuf + 1) % NUM_BUF;

              /* Copy the buffer */
              memcpy((void *)txBufPtr[lastSentTxBuf],
                     (void *)rxBufPtr[lastFullRxBuf],
                     AUDIO_BUF_SIZE);

              /*
              ** Send the buffer by setting the DMA params accordingly.
              ** Here the buffer to send and number of samples are passed as
              ** parameters. This is important, if only transmit section
              ** is to be used.
              */
              BoardDiag_BufferTxDMAActivate(lastSentTxBuf, NUM_SAMPLES_PER_AUDIO_BUF,
                                           (unsigned short)parToSend,
                                           (unsigned short)parToLink);
              sampleCnt += NUM_SAMPLES_PER_AUDIO_BUF;
          }
      }

      UARTConfigPrintf(uartBaseAddr,"\nAudio Loopback Test Completed!\n");
      UARTConfigPrintf(uartBaseAddr,"Audio Loopback Test Passed!!\n");

      return 0;
}
