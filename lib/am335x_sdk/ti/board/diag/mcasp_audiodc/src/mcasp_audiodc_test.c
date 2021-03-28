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
 *  \file   mcasp_audiodc_test.c
 *
 *  \brief  This file contains the Audio Loopback baremetal application
 *          for OMAPL137 multi-channel audio daughter card
 *
 *  This test is intended to demonstrate baremetal functionality of McASP
 *  EDMA, and I2C CSL modules without depending on the LLD libraries.
 *  It will be a good reference for the applications which need
 *  low footprint code base for audio usecase evaluation. Board library is
 *  not used by this test to avoid dependency on LLD libraries.
 *  This test can be executed on both ARM and DSP cores.
 *
 *  Multi-channel audio daughter card functionality is exercised by this test.
 *  Insert audio DC to OMAPL137 EVM audio expansion connector. Connect an audio 
 *  source to four audio input ports (J5, J6, J7 & J8) of the audio DC. Connect 
 *  headsets/speakers to four audio output ports (J9, J10, J11 & J12) of the 
 *  audio DC Audio being played at the audio source should be played back at 
 *  headsets/speakers connected to audio output ports while running the test.
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
#include <ti/csl/src/ip/mcspi/V1/spi.h>
#include <ti/csl/src/ip/gpio/V0/gpio.h>
#include <ti/csl/src/ip/i2c/V0/i2c.h>
#ifdef _TMS320C6X
#include <ti/csl/arch/c67x/interrupt.h>
#else
#include <ti/csl/arch/arm9/interrupt.h>
#endif
#include <ti/csl/soc.h>
#include <ti/csl/csl_syscfg.h>
#include <ti/csl/csl_syscfgAux.h>
#include "mcasp_audiodc_test.h"
#include "uart_config.h"

void BoardDiag_McASPErrorIsr(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint32_t     uartBaseAddr = CSL_UART_2_REGS;
unsigned int spidat1;
unsigned char cmd[8];

/* Global counters to keep track of errors. Can be removed before releasing  */
uint32_t complInterruptCounter = 0x00;
uint32_t errInterruptCounter = 0x00;

uint32_t intTriggerCount = 0;

uint8_t dataToSlave;
uint8_t dataFromSlave;

/*
 ** Transmit buffers. If any new buffer is to be added, define it here and
 ** update the NUM_BUF.
 */
static uint8_t txBuf0[AUDIO_BUF_SIZE];
static uint8_t txBuf1[AUDIO_BUF_SIZE];

/*
 ** Receive buffers. If any new buffer is to be added, define it here and
 ** update the NUM_BUF.
 */
static uint8_t rxBuf0[AUDIO_BUF_SIZE];
static uint8_t rxBuf1[AUDIO_BUF_SIZE];

uint32_t *chanPtrArrayRX[NUM_I2S_CHANNELS];
uint32_t *chanPtrArrayTX[NUM_I2S_CHANNELS];

static unsigned char rxBufTemp[AUDIO_BUF_SIZE];
static unsigned char txBufTemp[AUDIO_BUF_SIZE];

/*
 ** Next buffer to receive data. The data will be received in this buffer.
 */
static volatile uint32_t nxtBufToRcv = 0;

/*
 ** The RX buffer which filled latest.
 */
static volatile uint32_t lastFullRxBuf = 0;

/*
 ** The offset of the paRAM ID, from the starting of the paRAM set.
 */
static volatile uint16_t parOffRcvd = 0;

/*
 ** The offset of the paRAM ID sent, from starting of the paRAM set.
 */
static volatile uint16_t parOffSent = 0;

/*
 ** The offset of the paRAM ID to be sent next, from starting of the paRAM set.
 */
static volatile unsigned short parOffTxToSend = 0;

/*
 ** The transmit buffer which was sent last.
 */
static volatile unsigned int lastSentTxBuf = NUM_BUF - 1;

/* Array of receive buffer pointers */
static unsigned int const rxBufPtr[NUM_BUF] = { (uint32_t) rxBuf0,
                                                (uint32_t) rxBuf1 };

/* Array of transmit buffer pointers */
static uint32_t const txBufPtr[NUM_BUF] =
        { (uint32_t) txBuf0, (uint32_t) txBuf1 };

/*
 ** Default paRAM for Transmit section. This will be transmitting from
 ** a loop buffer.
 */
static EDMA3CCPaRAMEntry const txDefaultPar =
        { (uint32_t)((0x00 << 8u)), /* Opt field */
          (uint32_t) txBuf1, /* source address */
          (uint16_t)(BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER), /* aCnt */
          (uint16_t)(NUM_TIMESLOTS_PER_SERIALIZER), /* bCnt */
          (uint32_t) SOC_MCASP_BASE, /* dest address */
          (uint16_t)(AUDIO_BUF_SIZE / NUM_TIMESLOTS_PER_SERIALIZER), /* source bIdx */
          (uint16_t)(0), /* dest bIdx */
          (uint16_t)(PAR_TX_START * SIZE_PARAMSET), /* link address */
          (uint16_t)(NUM_TIMESLOTS_PER_SERIALIZER), /* bCnt reload value */
          (int16_t)((BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER) - 
                    (NUM_TIMESLOTS_PER_SERIALIZER - 1) *
                    (AUDIO_BUF_SIZE / NUM_TIMESLOTS_PER_SERIALIZER)), /* source cIdx */
          (uint16_t)(0), /* dest cIdx */
          (uint16_t) NUM_SAMPLES_PER_AUDIO_BUF /* cCnt */
        };

/*
 ** Default paRAM for Receive section. This will be transmitting from
 ** a loop buffer.
 */
static EDMA3CCPaRAMEntry const rxDefaultPar =
        { (uint32_t)(((EDMA3_CHA_MCASP_RX << EDMA3CC_OPT_TCC_SHIFT) & 
                       EDMA3CC_OPT_TCC) | (0x00 << 8u)),
          (uint32_t) SOC_MCASP_BASE, /* source address */
          (uint16_t)(BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER), /* aCnt */
          (uint16_t)(NUM_TIMESLOTS_PER_SERIALIZER), /* bCnt */
          (uint32_t) rxBuf0, /* dest address */
          (uint16_t)(0), /* source bIdx */
          (uint16_t)(AUDIO_BUF_SIZE / NUM_TIMESLOTS_PER_SERIALIZER), /* dest bIdx */
          (uint16_t)(PAR_RX_START * SIZE_PARAMSET), /* link address */
          (uint16_t)(NUM_TIMESLOTS_PER_SERIALIZER), /* bCnt reload value */
          (uint16_t)(0), /* source cIdx */
          (int16_t)((BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER) -
                    (NUM_TIMESLOTS_PER_SERIALIZER - 1) *
                    (AUDIO_BUF_SIZE / NUM_TIMESLOTS_PER_SERIALIZER)), /* dest cIdx */
          (uint16_t) NUM_SAMPLES_PER_AUDIO_BUF /* cCnt */
        };

/*
 ** Configures DMA Tx params
 */
static void BoardDiag_ParamTxSet(unsigned short parId)
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
static void BoardDiag_BufferRxDMAActivate(unsigned int rxBuf,
                                          unsigned short parId,
                                          unsigned short parLink)
{
    EDMA3CCPaRAMEntry paramSet;

    /* Copy the default paramset */
    memcpy(&paramSet, &rxDefaultPar, SIZE_PARAMSET);

    /* Enable completion interrupt */
    paramSet.opt     |= RX_DMA_INT_ENABLE;
    paramSet.destAddr = rxBufPtr[rxBuf];
    paramSet.linkAddr = parLink * SIZE_PARAMSET;

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, parId, &paramSet);
}

/*
 ** This function will be called once DMA receive is completed
 */
static void BoardDiag_McASPRxDMAComplHandler(void)
{
    unsigned short nxtParToUpdate;
    
    intTriggerCount++;
    
    /*
     ** Update lastFullRxBuf to indicate a new buffer reception
     ** is completed.
     */
    lastFullRxBuf  = (lastFullRxBuf + 1) % NUM_BUF;
    nxtParToUpdate = PAR_RX_START + parOffRcvd;
    parOffRcvd     = (parOffRcvd + 1) % NUM_PAR;

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
 ** This function will be called once DMA transmit is completed
 */
static void BoardDiag_McASPTxDMAComplHandler(void)
{
    BoardDiag_ParamTxSet((unsigned short) (PAR_TX_START + parOffSent));

    parOffSent = (parOffSent + 1) % NUM_PAR;
}

/*
 ** EDMA transfer completion ISR
 */
static void BoardDiag_EDMA3CCComplIsr(void)
{
#ifdef _TMS320C6X
    IntEventClear(CSL_INTC_EVENTID_EDMA3CC_INT1);
#else
    IntSystemStatusClear (SYS_INT_CCINT0);
#endif

    /* Check if receive DMA completed */
    if (EDMA3GetIntrStatus(SOC_EDMA3_CC_BASE) & (1 << EDMA3_CHA_MCASP_RX))
    {
        /* Clear the interrupt status for the 0th channel */
        EDMA3ClrIntr(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_RX);
        BoardDiag_McASPRxDMAComplHandler();
    }

    /* Check if transmit DMA completed */
    if (EDMA3GetIntrStatus(SOC_EDMA3_CC_BASE) & (1 << EDMA3_CHA_MCASP_TX))
    {
        /* Clear the interrupt status for the first channel */
        EDMA3ClrIntr(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX);
        BoardDiag_McASPTxDMAComplHandler();
    }
}

/*
 ** Sets up the interrupts for EDMA
 */
static void BoardDiag_EDMA3IntSetup(void)
{
#ifdef _TMS320C6X
    Intc_IntRegister(C674X_MASK_INT5, BoardDiag_EDMA3CCComplIsr);
    IntEventMap(C674X_MASK_INT5, CSL_INTC_EVENTID_EDMA3CC_INT1);
    Intc_IntEnable(C674X_MASK_INT5);
#else
    Intc_IntRegister(SYS_INT_CCINT0, BoardDiag_EDMA3CCComplIsr);
    IntChannelSet(SYS_INT_CCINT0, INT_CHANNEL_EDMACC);
    Intc_SystemEnable (SYS_INT_CCINT0);
#endif
}

/*
 ** Sets up the error interrupts for McASP
 */
static void BoardDiag_McASPErrorIntSetup(void)
{
    /* Register the error ISR for McASP */
#ifdef _TMS320C6X
    Intc_IntRegister(C674X_MASK_INT6, BoardDiag_McASPErrorIsr);
    IntEventMap(C674X_MASK_INT6, CSL_INTC_EVENTID_AXRINT);
    Intc_IntEnable(C674X_MASK_INT6);
#else
    Intc_IntRegister(SYS_INT_MCASPINT, BoardDiag_McASPErrorIsr);
    IntChannelSet(SYS_INT_MCASPINT, INT_CHANNEL_MCASP);
    Intc_SystemEnable (SYS_INT_MCASPINT);
#endif
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

    for (idx = 0; idx < NUM_PAR; idx++)
    {
        paramSet.destAddr = rxBufPtr[idx];

        paramSet.linkAddr = (PAR_RX_START + ((idx + 1) % NUM_PAR)) * 
                            (SIZE_PARAMSET);

        paramSet.bCnt = NUM_TIMESLOTS_PER_SERIALIZER;
        paramSet.cCnt = (NUM_SAMPLES_PER_AUDIO_BUF);

        EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, (PAR_RX_START + idx), &paramSet);
    }

    /* Initialize the required variables for reception */
    nxtBufToRcv   = idx % NUM_BUF;
    lastFullRxBuf = NUM_BUF - 1;
    parOffRcvd    = 0;

    /* Initialize the 1st paRAM set for transmit */
    memcpy(&paramSet, &txDefaultPar, SIZE_PARAMSET);

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX, &paramSet);

    /* rest of the params, enable loop job */
    for (idx = 0; idx < NUM_PAR; idx++)
    {
        BoardDiag_ParamTxSet(PAR_TX_START + idx);
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
	McASPRxReset (SOC_MCASP_CFG_BASE);
    McASPTxReset(SOC_MCASP_CFG_BASE);

    /* Enable the FIFOs for DMA transfer */
    McASPReadFifoEnable(SOC_MCASP_CFG_BASE, NUM_RX_SERIALIZERS, 1);
    McASPWriteFifoEnable(SOC_MCASP_CFG_BASE, NUM_TX_SERIALIZERS, 1);

    /* Set I2S format in the transmitter/receiver format units */
    McASPRxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,
                     MCASP_RX_MODE_DMA);
    McASPTxFmtI2SSet(SOC_MCASP_CFG_BASE, WORD_SIZE, SLOT_SIZE,
                     MCASP_TX_MODE_DMA);

    McASPRxFrameSyncCfg(SOC_MCASP_CFG_BASE, NUM_TIMESLOTS_PER_SERIALIZER,
                        1, 3);

    McASPTxFrameSyncCfg(SOC_MCASP_CFG_BASE, MCASP_TX_FRAME_SYNC_MODE,
                        MCASP_TX_FRAME_SYNC_WIDTH,
                        MCASP_TX_FRAME_SYNC_SELECT);

    /* Configure the clock for receiver */
    McASPRxHClkCfg(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_INTERNAL,
                   MCASP_RX_CLK_EXTERNAL, 7, 0);
    McASPRxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_POL_RIS_EDGE);
    McASPRxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_RX_CLKCHCK_DIV8, 
                          0x00, 0xFF);

    /* Configure the clock for transmitter */
    McASPTxHClkCfg(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL,
                   MCASP_RX_CLK_EXTERNAL, 7, 0);

    McASPTxRxClkSyncEnable(SOC_MCASP_CFG_BASE);
    McASPTxClkPolaritySet(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_POL_FALL_EDGE);
    McASPTxClkCheckConfig(SOC_MCASP_CFG_BASE, MCASP_TX_CLKCHCK_DIV8, 0x00,
                          0xFF);

    /* Disable synchronization of RX and TX sections  */
    McASPTxRxClkSyncDisable(SOC_MCASP_CFG_BASE);

    /* Enable the transmitter/receiver slots. I2S uses 2 slots */
    McASPRxTimeSlotSet(SOC_MCASP_CFG_BASE, I2S_SLOTS);
    McASPTxTimeSlotSet(SOC_MCASP_CFG_BASE, I2S_SLOTS);

    /*
     ** Set the serializers
     */
    McASPSerializerRxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_RX1);
    McASPSerializerRxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_RX2);
    McASPSerializerRxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_RX3);
    McASPSerializerRxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_RX4);
    McASPSerializerTxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_TX1);
    McASPSerializerTxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_TX2);
    McASPSerializerTxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_TX3);
    McASPSerializerTxSet(SOC_MCASP_CFG_BASE, MCASP_XSER_TX4);

    /*
     ** Configure the McASP pins
     ** Output - Frame Sync, Clock, Serializer Rx and Serializer Tx
     **          (Clocks generated internally)
     */
    McASPPinDirOutputSet(SOC_MCASP0_CFG_BASE, MCASP_PIN_AMUTE);
    McASPPinMcASPSet(SOC_MCASP0_CFG_BASE, ~MCASP_PIN_AMUTE);
    McASPPinGPIOSet(SOC_MCASP0_CFG_BASE, MCASP_PIN_AMUTE);

    McASPPinDirOutputSet(
                      SOC_MCASP_CFG_BASE,
					  MCASP_PIN_AXR(MCASP_XSER_TX1)
					| MCASP_PIN_AXR(MCASP_XSER_TX2)
                    | MCASP_PIN_AXR(MCASP_XSER_TX3)
                    | MCASP_PIN_AXR(MCASP_XSER_TX4)
					| MCASP_PIN_ACLKX
                    | MCASP_PIN_AFSX | MCASP_PIN_AFSR | MCASP_PIN_ACLKR);

    McASPPinDirInputSet(
            SOC_MCASP_CFG_BASE,
            MCASP_PIN_AXR(MCASP_XSER_RX1) | MCASP_PIN_AXR(MCASP_XSER_RX2)
                    | MCASP_PIN_AXR(MCASP_XSER_RX3)
                    | MCASP_PIN_AXR(MCASP_XSER_RX4));

    /* Enable error interrupts for McASP */
    McASPTxIntEnable(
            SOC_MCASP_CFG_BASE,
            MCASP_TX_DMAERROR | MCASP_TX_CLKFAIL | MCASP_TX_SYNCERROR
                    | MCASP_TX_UNDERRUN);

    McASPRxIntEnable(
            SOC_MCASP_CFG_BASE,
            MCASP_RX_DMAERROR | MCASP_RX_CLKFAIL | MCASP_RX_SYNCERROR
                    | MCASP_RX_OVERRUN);
}

/*
 ** Activates the data transmission/reception
 ** The DMA parameters shall be ready before calling this function.
 */
static void BoardDiag_I2SDataTxRxActivate(void)
{
    /* Start the clocks */
    McASPRxClkStart(SOC_MCASP_CFG_BASE, MCASP_RX_CLK_INTERNAL);
    McASPTxClkStart(SOC_MCASP_CFG_BASE, MCASP_TX_CLK_INTERNAL);

    /* Enable EDMA for the transfer */
    EDMA3EnableTransfer(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_RX,
                        EDMA3_TRIG_MODE_EVENT);
    EDMA3EnableTransfer(SOC_EDMA3_CC_BASE, EDMA3_CHA_MCASP_TX,
                        EDMA3_TRIG_MODE_EVENT);

    /* Activate the  serializers */
    McASPTxSerActivate (SOC_MCASP_CFG_BASE);
    McASPRxSerActivate(SOC_MCASP_CFG_BASE);

    /* make sure that the XDATA bit is cleared to zero */
    while (!McASPTxStatusGet(SOC_MCASP_CFG_BASE) & MCASP_TX_STAT_DATAREADY);

    /* Activate the state machines */
    McASPTxEnable(SOC_MCASP_CFG_BASE);
    McASPRxEnable(SOC_MCASP_CFG_BASE);
}

/*
 ** Configures McASP pin muxing
 */
void BoardDiag_ConfigMcaspPinMux(void)
{
    // Pinmux settings for SPI1
    /* Clearing the bits in context and retaining the other bit values
     * of PINMUX8 register. */
    hSysCfg->PINMUX8 &= (~(CSL_SYSCFG_PINMUX8_PINMUX8_3_0_MASK
            | CSL_SYSCFG_PINMUX8_PINMUX8_7_4_MASK
            | CSL_SYSCFG_PINMUX8_PINMUX8_11_8_MASK
            | CSL_SYSCFG_PINMUX8_PINMUX8_31_28_MASK));

    /* Write to the pinmux registers to enable spi instance1. */
    hSysCfg->PINMUX8 |= (PINMUX8_SPI1_CLK_ENABLE | PINMUX8_SPI1_SIMO_ENABLE |
                         PINMUX8_SPI1_SOMI_ENABLE | PINMUX8_UART_RX_ENABLE);

    hSysCfg->PINMUX9 &= ~(CSL_SYSCFG_PINMUX9_PINMUX9_3_0_MASK);
    hSysCfg->PINMUX9 |= PINMUX9_UART_TX_ENABLE;

    // Pinmux settings for SPI1 Chip Select
    hSysCfg->PINMUX11 &= (~(CSL_SYSCFG_PINMUX11_PINMUX11_15_12_MASK));
    hSysCfg->PINMUX11 |= (CSL_SYSCFG_PINMUX11_PINMUX11_15_12_GPIO3_10
            << CSL_SYSCFG_PINMUX11_PINMUX11_15_12_SHIFT);

    // Pinmux settings for for McASP1
    /*
     ** Clearing the bits in context and retaining the other bit values
     ** of PINMUX11 register.
     */
    hSysCfg->PINMUX11 &= (~(CSL_SYSCFG_PINMUX11_PINMUX11_31_28_MASK
            | CSL_SYSCFG_PINMUX11_PINMUX11_27_24_MASK
            | CSL_SYSCFG_PINMUX11_PINMUX11_23_20_MASK));

    /*
     ** Performing the actual Pin Multiplexing to select mandatory pins in
     ** PINMUX11  register.
     */
    hSysCfg->PINMUX11 |= (PINMUX11_MCASP1_AFSX_ENABLE
            | PINMUX11_MCASP1_ACLKX_ENABLE |
            PINMUX11_MCASP1_AHCLKX_ENABLE);

    /*
     ** Clearing the bits in context and retaining the other bit values
     ** of PINMUX12 register.
     */
    hSysCfg->PINMUX12 &= (~(CSL_SYSCFG_PINMUX12_PINMUX12_19_16_MASK
            | CSL_SYSCFG_PINMUX12_PINMUX12_15_12_MASK
            | CSL_SYSCFG_PINMUX12_PINMUX12_11_8_MASK
            | CSL_SYSCFG_PINMUX12_PINMUX12_7_4_MASK
            | CSL_SYSCFG_PINMUX12_PINMUX12_3_0_MASK));

    /*
     ** Performing the actual Pin Multiplexing to select mandatory pins in
     ** PINMUX12 register.
     */
    hSysCfg->PINMUX12 |= (PINMUX12_MCASP1_AXR0_ENABLE
            | PINMUX12_MCASP1_AMUTE_ENABLE | PINMUX12_MCASP1_AFSR_ENABLE |
            PINMUX12_MCASP1_ACLKR_ENABLE | PINMUX12_MCASP1_AHCLKR_ENABLE);

    /*
     ** Clearing the bits in context and retaining the other bit values
     ** of PINMUX13 register.
     */
    hSysCfg->PINMUX13 &= (~(CSL_SYSCFG_PINMUX13_PINMUX13_7_4_MASK));

    /*
     ** Performing the actual Pin Multiplexing to select mandatory pins in
     ** PINMUX13 register.
     */
    hSysCfg->PINMUX13 |= (PINMUX13_MCASP1_AXR5_ENABLE);

    // Pinmux settings for enable AMUTE0
    /*
     ** Clearing the bits in context and retaining the other bit values
     ** of PINMUX10 register.
     */
    hSysCfg->PINMUX10 &= (~(CSL_SYSCFG_PINMUX10_PINMUX10_3_0_MASK));

    /*
     ** Performing the actual Pin Multiplexing to select mandatory pins in
     ** PINMUX10 register.
     */
    hSysCfg->PINMUX10 |= (PINMUX10_AMUTE0_ENABLE);
}

/*
 ** Configures SPI modules for codec control
 */
void SPI1Mode4WireMode()
{
	// Enable AK4588 chip select as output
	GPIOSetDirMode_v0(CSL_GPIO_0_REGS, 58, GPIO_DIRECTION_OUTPUT);
	// Drive AK4588 chip select high
	GPIOPinWrite_v0(CSL_GPIO_0_REGS, 58, GPIO_PIN_HIGH);

	/*Put the SPI in reset and bring it out of reset*/
	SPIReset(CSL_SPI_1_SLV_REGS);

	SPIGlobalControlSetup(CSL_SPI_1_SLV_REGS, LOOP_BACK_BIT_VALUE, 
                          POWER_DOWN_BIT_VALUE, CLK_MST_BIT_VALUE);

	SPIPinControlSetup(CSL_SPI_1_SLV_REGS, SOMIFUN_BIT_VALUE, 
                       SIMOFUN_BIT_VALUE, CLKFUN_BIT_VALUE);

	SPICSEnable(CSL_SPI_1_SLV_REGS, SPI_ENABLE_CHIP_SEL_0);

	SPISetShiftDir(CSL_SPI_1_SLV_REGS, SHIFTDIR_BIT_VALUE);

	SPIDataFormatSetup(CSL_SPI_1_SLV_REGS, SPI_SPIFMT_DF_SEL, 
                       SPI_INPUT_CLK_FREQ, SPI_OUTPUT_CLK_FREQ, 
                       CLOCK_MODE, CHARLEN_BIT_VALUE);

	SPITransmitData(CSL_SPI_1_SLV_REGS, DATA_HOLD_VALUE, 0x0000);/*The Transmit DATA is set to zero initially*/

	SPIData1Setup(CSL_SPI_1_SLV_REGS, CSNUM_BIT_VALUE, WDEL_BIT_VALUE);

	SPIDelaySetup(CSL_SPI_1_SLV_REGS, C2TDELAY_BIT_FIELD_VALUE, 
                  T2CDELAY_BIT_FIELD_VALUE);

	SPIXferEnable(CSL_SPI_1_SLV_REGS);
}

/*                                                                               
 *  Execute a SPI 1 data buffer transfer operation.  Each byte in buf is shifted
 *  out and replaced with data coming back from the SPI 1.                     
 */
void SPI1WriteBuf(unsigned char *buf, unsigned short len)
{
    unsigned short i;

	GPIOPinWrite_v0(CSL_GPIO_0_REGS, 58, GPIO_PIN_LOW);

	/* Clear any old data */
	SPIReceiveData(CSL_SPI_1_SLV_REGS);

	/* SPI 1 access cycle */
	for (i = 0; i <= len; i++)
	{
		// Wait for transmit ready
		while(SPIReceiveData(CSL_SPI_1_SLV_REGS) & (0x30000000));
		if (i == len )
			SPITransmitData(CSL_SPI_1_SLV_REGS, DATA_HOLD_VALUE, (uint32_t)buf[i]);
		else
			SPITransmitData(CSL_SPI_1_SLV_REGS, DATA_HOLD_VALUE, (uint32_t)buf[i]);

		// Wait for receive data ready
		while(SPIReceiveData(CSL_SPI_1_SLV_REGS) & (0x80000000));

        /* Read 1 byte */
		buf[i] = SPIReceiveData(CSL_SPI_1_SLV_REGS);

	}

	GPIOPinWrite_v0(CSL_GPIO_0_REGS, 58, GPIO_PIN_HIGH);
}

/* Function to set a register in AK4588 codec */
unsigned short ak4588_rset(unsigned short id, unsigned short regnum, unsigned short regval)
{
    cmd[0] = ((id & 0x3) << 6) | (1 << 5) | (regnum & 0x1f);
	cmd[1] = regval;

	SPI1WriteBuf(cmd, 1);

	return 0;
}

/*
 ** Function to configure the codec for I2S mode
 */
static void AK4588I2SConfigure(void)
{
    /* Configure AK4588 registers */
    ak4588_rset(1, 0, 0x0C);    // 24-bit I2S mode
    ak4588_rset(1, 1, 0x80);
    ak4588_rset(1, 9, 0x01);    // Take AK4588 DAC out of reset
    ak4588_rset(0, 0, 0x4B);    // Double AHCLKX1 frequency
}

/*
 ** Activates the DMA transfer for a parameterset from the given buffer.
 */
void BoardDiag_BufferTxDMAActivate(unsigned int txBuf,
                                   unsigned short numSamples,
                                   unsigned short parId, unsigned short linkPar)
{
    EDMA3CCPaRAMEntry paramSet;

    /* Copy the default paramset */
    memcpy(&paramSet, &txDefaultPar, SIZE_PARAMSET - 2);

    /* Enable completion interrupt */
    paramSet.opt |= TX_DMA_INT_ENABLE;
    paramSet.srcAddr = txBufPtr[txBuf];
    paramSet.linkAddr = linkPar * SIZE_PARAMSET;
    paramSet.cCnt = numSamples;
    paramSet.srcBIdx = numSamples * (BYTES_PER_SAMPLE / 
                                     NUM_TIMESLOTS_PER_SERIALIZER);
    paramSet.srcCIdx = ((BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER) -
                        (NUM_TIMESLOTS_PER_SERIALIZER - 1) * numSamples * 
                        (BYTES_PER_SAMPLE / NUM_TIMESLOTS_PER_SERIALIZER));

    EDMA3SetPaRAM(SOC_EDMA3_CC_BASE, parId, &paramSet);
}

/*
 ** The main function. Application starts here.
 */
int main(void)
{
    uint16_t parToSend;
    uint16_t parToLink;
    uint32_t *srcPtr, *dstPtr;
    int i, j;
    uint32_t sampleCnt = 0;

    BoardDiag_ConfigMcaspPinMux();

    Intc_Init();

    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
                   UART_STOP_BIT_1, UART_PARITY_NONE,
                   UART16x_OPER_MODE);
    UARTConfigPrintf(uartBaseAddr,"\n*******************************************\n");
    UARTConfigPrintf(uartBaseAddr,  "*         Audio DC Loopback Test          *\n");
    UARTConfigPrintf(uartBaseAddr,  "*******************************************\n");

    // configure SPI1 to 4 wire mode
    SPI1Mode4WireMode();
    // configure AK4588 via SPI1
    AK4588I2SConfigure();

    /* Initialize txBuf2 used as loop buffer */
    memset(txBuf1, 0, AUDIO_BUF_SIZE);

    /*Using same as mcasp_test for onboard*/
    EDMAsetRegion (EDMA3_CC_REGION);
    EDMA3Init(SOC_EDMA3_CC_BASE, EDMA3_CC_QUEUE);
    BoardDiag_EDMA3IntSetup();

    BoardDiag_McASPErrorIntSetup();

    /* Enable the interrupts generation at global level */
#ifdef _TMS320C6X
    Intc_SystemEnable();
#else
    IntMasterIRQEnable();
    IntGlobalEnable();
    IntIRQEnable();
#endif

    /* Request EDMA channels */
    EDMA3RequestChannel(SOC_EDMA3_CC_BASE, EDMA3_CHANNEL_TYPE_DMA,
                        EDMA3_CHA_MCASP_TX, EDMA3_CHA_MCASP_TX, EDMA3_CC_QUEUE);

    EDMA3RequestChannel(SOC_EDMA3_CC_BASE, EDMA3_CHANNEL_TYPE_DMA,
                        EDMA3_CHA_MCASP_RX, EDMA3_CHA_MCASP_RX, EDMA3_CC_QUEUE); /* Configure the McASP for I2S */

    /* Initialize the DMA parameters */
    BoardDiag_I2SDMAParamInit();

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
    while (1)
    {
        if (lastFullRxBuf != lastSentTxBuf)
        {
            if(sampleCnt > TEST_SAMPLE_COUNT)
            {
                /* Reset Audio codec */
                ak4588_rset(1, 9, 0x00);
                break;
            }

            /*
             ** Start the transmission from the link paramset. The param set
             ** 1 will be linked to param set at PAR_TX_START. So do not
             ** update paRAM set1.
             */
            parToSend = PAR_TX_START + (parOffTxToSend % NUM_PAR);
            parOffTxToSend = (parOffTxToSend + 1) % NUM_PAR;
            parToLink = PAR_TX_START + parOffTxToSend;

            lastSentTxBuf = (lastSentTxBuf + 1) % NUM_BUF;

            srcPtr = (uint32_t *) rxBufPtr[lastFullRxBuf];
            dstPtr = (uint32_t *) rxBufTemp;

            for (j = 0; j < NUM_RX_SERIALIZERS; j++)
            {
                for (i = 0; i < NUM_SAMPLES_PER_AUDIO_BUF; i++)
                {
                    // de-interleave the first half frame (LF, LS, C, LB interleaved)
                    dstPtr[(j * NUM_TIMESLOTS_PER_SERIALIZER)
                            * NUM_SAMPLES_PER_AUDIO_BUF + i] = srcPtr[i
                            * NUM_RX_SERIALIZERS + j];
                    // de-interleave the second half frame (RF, RS, SW, RB interleaved)
                    dstPtr[(j * NUM_TIMESLOTS_PER_SERIALIZER + 1)
                            * NUM_SAMPLES_PER_AUDIO_BUF + i] =
                            srcPtr[NUM_SAMPLES_PER_AUDIO_BUF
                                    * NUM_RX_SERIALIZERS
                                    + i * (NUM_RX_SERIALIZERS) + j];
                }
            }

            for (i = 0; i < NUM_I2S_CHANNELS; i++)
            {
                chanPtrArrayRX[i] = (uint32_t *) (&rxBufTemp[i
                        * (AUDIO_BUF_SIZE / NUM_I2S_CHANNELS)]);
                chanPtrArrayTX[i] = (uint32_t *) (&txBufTemp[i
                        * (AUDIO_BUF_SIZE / NUM_I2S_CHANNELS)]);
            }
            
            /* Loopback the audio */
            for (i = 0; i < NUM_I2S_CHANNELS; i++)
            {
                for (j = 0; j < NUM_SAMPLES_PER_AUDIO_BUF; j++)
                {
                    chanPtrArrayTX[i][j] = chanPtrArrayRX[i][j];
                }
            }

            // interleave the transmit frame
            srcPtr = (uint32_t *) txBufTemp;
            dstPtr = (uint32_t *) txBufPtr[lastSentTxBuf];

            for (j = 0; j < NUM_TX_SERIALIZERS; j++)
            {
                for (i = 0; i < NUM_SAMPLES_PER_AUDIO_BUF; i++)
                {
                    // interleave the first half frame (LF, LS, C, LB interleaved) and invert TX channel order
                    dstPtr[i * NUM_TX_SERIALIZERS + (NUM_TX_SERIALIZERS - j - 1)] =
                            srcPtr[(j * NUM_TIMESLOTS_PER_SERIALIZER)
                                    * NUM_SAMPLES_PER_AUDIO_BUF + i];
                    // interleave the second half frame (RF, RS, SW, RB interleaved) and invert TX channel order
                    dstPtr[NUM_SAMPLES_PER_AUDIO_BUF * NUM_TX_SERIALIZERS
                            + i * NUM_TX_SERIALIZERS
                            + (NUM_TX_SERIALIZERS - j - 1)] = srcPtr[(j
                            * NUM_TIMESLOTS_PER_SERIALIZER + 1)
                            * NUM_SAMPLES_PER_AUDIO_BUF + i];
                }
            }

            /*
             ** Send the buffer by setting the DMA params accordingly.
             ** Here the buffer to send and number of samples are passed as
             ** parameters. This is important, if only transmit section
             ** is to be used.
             */
            BoardDiag_BufferTxDMAActivate(lastSentTxBuf,
                                          NUM_SAMPLES_PER_AUDIO_BUF,
                                          (uint32_t) parToSend,
                                          (uint32_t) parToLink);
            sampleCnt += NUM_SAMPLES_PER_AUDIO_BUF;
        }
    }

    UARTConfigPrintf(uartBaseAddr,"\nAudio DC Loopback Test Completed!\n");
    UARTConfigPrintf(uartBaseAddr,"Audio DC Loopback Test Passed!!\n");
}

/*
** Error ISR for McASP
*/
void BoardDiag_McASPErrorIsr(void)
{
#ifdef _TMS320C6X
	IntEventClear(C674X_MASK_INT6);
#else
    IntSystemStatusClear(SYS_INT_MCASPINT);
#endif
}
