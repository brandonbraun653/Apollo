/**
 * \file  mcasp_audiodc_test.h
 * 
 * \brief The macro definitions and function prototypes for 
 *        configuring mcasp
 *
 */

/*
* Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
*/

#ifndef _MCASP_AUDIODC_TEST_H_
#define _MCASP_AUDIODC_TEST_H_

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*
 ** Pin Multiplexing masks for the mandatory pins to be used to operate
 ** McASP.
 */
#define PINMUX12_MCASP1_ACLKR_ENABLE    (CSL_SYSCFG_PINMUX12_PINMUX12_7_4_ACLKR1 << \
                                         CSL_SYSCFG_PINMUX12_PINMUX12_7_4_SHIFT)

#define PINMUX11_MCASP1_ACLKX_ENABLE    (CSL_SYSCFG_PINMUX11_PINMUX11_27_24_ACLKX1 << \
                                         CSL_SYSCFG_PINMUX11_PINMUX11_27_24_SHIFT)

#define PINMUX12_MCASP1_AFSR_ENABLE     (CSL_SYSCFG_PINMUX12_PINMUX12_11_8_AFSR1 << \
                                         CSL_SYSCFG_PINMUX12_PINMUX12_11_8_SHIFT)

#define PINMUX11_MCASP1_AFSX_ENABLE     (CSL_SYSCFG_PINMUX11_PINMUX11_31_28_AFSX1 << \
                                         CSL_SYSCFG_PINMUX11_PINMUX11_31_28_SHIFT)

#define PINMUX12_MCASP1_AHCLKR_ENABLE   (CSL_SYSCFG_PINMUX12_PINMUX12_3_0_AHCLKR1 << \
                                         CSL_SYSCFG_PINMUX12_PINMUX12_3_0_SHIFT)

#define PINMUX11_MCASP1_AHCLKX_ENABLE   (CSL_SYSCFG_PINMUX11_PINMUX11_23_20_AHCLKX1 << \
                                         CSL_SYSCFG_PINMUX11_PINMUX11_23_20_SHIFT)

#define PINMUX12_MCASP1_AMUTE_ENABLE    (CSL_SYSCFG_PINMUX12_PINMUX12_15_12_AMUTE1 << \
                                         CSL_SYSCFG_PINMUX12_PINMUX12_15_12_SHIFT)

/* Pin Multiplexing masks for AXR[5] and AXR[0]. */

#define PINMUX13_MCASP1_AXR5_ENABLE    (CSL_SYSCFG_PINMUX13_PINMUX13_7_4_AXR1_5 <<\
                                       CSL_SYSCFG_PINMUX13_PINMUX13_7_4_SHIFT)

#define PINMUX12_MCASP1_AXR0_ENABLE    (CSL_SYSCFG_PINMUX12_PINMUX12_19_16_AXR1_0 << \
                                       CSL_SYSCFG_PINMUX12_PINMUX12_19_16_SHIFT)

/* Pin multiplexing bit masks for SPI0 pins. */
#define PINMUX3_SPI0_CLK_ENABLE   (CSL_SYSCFG_PINMUX3_PINMUX3_3_0_EMB_D_23 << \
                                    CSL_SYSCFG_PINMUX3_PINMUX3_3_0_SHIFT)

#define PINMUX3_SPI0_SIMO_ENABLE  (CSL_SYSCFG_PINMUX3_PINMUX3_15_12_EMB_D_26 << \
                                    CSL_SYSCFG_PINMUX3_PINMUX3_15_12_SHIFT)

#define PINMUX3_SPI0_SOMI_ENABLE  (CSL_SYSCFG_PINMUX3_PINMUX3_11_8_EMB_D_25 << \
                                    CSL_SYSCFG_PINMUX3_PINMUX3_11_8_SHIFT)

#define PINMUX3_SPI0_ENA_ENABLE   (CSL_SYSCFG_PINMUX3_PINMUX3_7_4_EMB_D_24 << \
                                    CSL_SYSCFG_PINMUX3_PINMUX3_7_4_SHIFT)

/* Pin multiplexing bit masks for SPI1 pins. */

#define PINMUX8_SPI1_CLK_ENABLE   (CSL_SYSCFG_PINMUX8_PINMUX8_11_8_SPI1_CLK << \
                                   CSL_SYSCFG_PINMUX8_PINMUX8_11_8_SHIFT)

#define PINMUX8_SPI1_SIMO_ENABLE  (CSL_SYSCFG_PINMUX8_PINMUX8_7_4_SPI1_SIMO0 << \
                                   CSL_SYSCFG_PINMUX8_PINMUX8_7_4_SHIFT)

#define PINMUX8_SPI1_SOMI_ENABLE  (CSL_SYSCFG_PINMUX8_PINMUX8_3_0_SPI1_SOMI0 << \
                                   CSL_SYSCFG_PINMUX8_PINMUX8_3_0_SHIFT)

#define PINMUX8_SPI1_ENA_ENABLE   (CSL_SYSCFG_PINMUX8_PINMUX8_31_28_SPI1_ENA << \
                                   CSL_SYSCFG_PINMUX8_PINMUX8_31_28_SHIFT)

/* Pin multiplexing bit masks for UART pins */
#define PINMUX8_UART_RX_ENABLE   (CSL_SYSCFG_PINMUX8_PINMUX8_31_28_UART2_RXD << \
                                  CSL_SYSCFG_PINMUX8_PINMUX8_31_28_SHIFT)
#define PINMUX9_UART_TX_ENABLE   (CSL_SYSCFG_PINMUX9_PINMUX9_3_0_UART2_TXD << \
                                  CSL_SYSCFG_PINMUX9_PINMUX9_3_0_SHIFT)

/* Pin Multiplexing bit mask to select GP3[10] pin. */
#define PINMUX11_GPIO3_10_ENABLE    (CSL_SYSCFG_PINMUX11_PINMUX11_15_12_GPIO3_10  << \
                                     CSL_SYSCFG_PINMUX11_PINMUX11_15_12_SHIFT)
/* Pin Multiplexing bit mask to select AMUTE0 */
#define PINMUX10_AMUTE0_ENABLE    (CSL_SYSCFG_PINMUX10_PINMUX10_3_0_AMUTE0  << \
                                   CSL_SYSCFG_PINMUX10_PINMUX10_3_0_SHIFT)

#define LOOP_BACK_BIT_VALUE         0U
#define POWER_DOWN_BIT_VALUE        0U
#define CLK_MST_BIT_VALUE           3U

#define ENAFUN_BIT_VALUE            1U

#define SPI_ENABLE_CHIP_SEL_0       0U

#define SOMIFUN_BIT_VALUE           1U
#define SIMOFUN_BIT_VALUE           1U
#define CLKFUN_BIT_VALUE  	        1U

#define SHIFTDIR_BIT_VALUE          0U

#define POLARITY_BIT_SHIFT_VALUE   (0 << 17)
#define PHASE_BIT_SHIFT_VALUE      (1 << 16)

#define CLOCK_MODE                 (POLARITY_BIT_SHIFT_VALUE | PHASE_BIT_SHIFT_VALUE)

#define PRESCALE_BIT_VALUE         19U
#define CHARLEN_BIT_VALUE           8U

#define DATA_FORMAT_SELECT_VALUE   03U

#define DATA_HOLD_VALUE             1U

#define CSNUM_BIT_VALUE             2U
#define WDEL_BIT_VALUE              0U

#define SPI1_BASE_ADDR              0x01E12000

#define C2TDELAY_BIT_FIELD_VALUE    8U
#define T2CDELAY_BIT_FIELD_VALUE    8U

#define SPI_INPUT_CLK_FREQ          4000000U/*4MHz*/

#define SPI_OUTPUT_CLK_FREQ         150000000U/*150MHz*/

#define SOC_EDMA3_CC_BASE CSL_EDMA3CC_0_REGS
#define SOC_MCASP_CFG_BASE CSL_MCASP_1_CFG_REGS
#define SOC_MCASP0_CFG_BASE CSL_MCASP_0_CFG_REGS

#define SOC_MCASP_BASE (CSL_MCASP_1_CFG_REGS + 0x00002000)
#define SOC_MCASP_1_FIFO_REGS CSL_MCASP_1_FIFO_CFG_REGS

#define MCASP_TX_FRAME_SYNC_MODE             2u
#define MCASP_TX_FRAME_SYNC_WIDTH            1u
#define MCASP_TX_FRAME_SYNC_POLARITY         2u
#define MCASP_TX_FRAM_SYNC_GENERATION        1u

#define SPI_SPIFMT_DF_SEL 0

#define MCASP_TX_FRAME_SYNC_SELECT          (MCASP_TX_FRAM_SYNC_GENERATION | \
                                             MCASP_TX_FRAME_SYNC_POLARITY)
#ifdef BUILD_ARM

#endif
/*
** Values which are configurable
*/
/* Slot size to send/receive data */
#define SLOT_SIZE                         (32u)

/* Word size to send/receive data. Word size <= Slot size */
#define WORD_SIZE                         (32u)

/* Number of channels, L & R */
#define NUM_I2S_CHANNELS                  (8U)

/* Sampling Rate which will be used by both transmit and receive sections */
#define SAMPLING_RATE                     (48000u)

/* Number of samples to be used per audio buffer */
#define NUM_SAMPLES_PER_AUDIO_BUF         (100u)

/* Number of buffers used per tx/rx */
#define NUM_BUF                           (2U)

/* Number of linked parameter set used per tx/rx */
#define NUM_PAR                           (2U)

/* Specify where the parameter set starting is */
#define PAR_ID_START                      (40U)

/* Number of samples in loop buffer */
#define NUM_SAMPLES_LOOP_BUF              (10U)

/* McASP Serializer 0 for Transmit */
#define MCASP_XSER_TX                   (5U)

/* McASP Serializer 1 for Transmit */
#define MCASP_XSER_RX                   (0U)

/*
** Below Macros are calculated based on the above inputs
*/

#define I2S_SLOTS                         ((1 << NUM_TIMESLOTS_PER_SERIALIZER) - 1)

#define BYTES_PER_SAMPLE                  ((WORD_SIZE >> 3) \
                                           * NUM_I2S_CHANNELS)

#define AUDIO_BUF_SIZE                    (NUM_SAMPLES_PER_AUDIO_BUF \
                                           * BYTES_PER_SAMPLE)

#define EDMA3_CHA_MCASP_RX               (2U)

#define EDMA3_CHA_MCASP_TX               (3U)

#if 0
#define TX_DMA_INT_ENABLE                ((((EDMA_TPCC_OPT_TCC_MASK >> EDMA_TPCC_OPT_TCC_SHIFT ) & EDMA3_CHA_MCASP_TX) << EDMA_TPCC_OPT_TCC_SHIFT) | \
											(1 << EDMA_TPCC_OPT_TCINTEN_SHIFT))

#define RX_DMA_INT_ENABLE                ((((EDMA_TPCC_OPT_TCC_MASK >> EDMA_TPCC_OPT_TCC_SHIFT ) & EDMA3_CHA_MCASP_RX) << EDMA_TPCC_OPT_TCC_SHIFT) | \
											(1 << EDMA_TPCC_OPT_TCINTEN_SHIFT))

#else

#define EDMA3CC_OPT_TCINTEN_SHIFT        (0x00000014u)
	
#define TX_DMA_INT_ENABLE                (EDMA3CC_OPT_TCC_SET(1) | (1 \
                                               << EDMA3CC_OPT_TCINTEN_SHIFT))
#define RX_DMA_INT_ENABLE                     (EDMA3CC_OPT_TCC_SET(0) | (1 \
                                               << EDMA3CC_OPT_TCINTEN_SHIFT))
#endif	

#define PAR_RX_START                     (PAR_ID_START)
#define PAR_TX_START                     (PAR_ID_START + NUM_PAR)

#define NUM_TIMESLOTS_PER_SERIALIZER		(2u)

/*
** Below Macros are calculated based on the above inputs
*/
#define NUM_TX_SERIALIZERS                    (NUM_I2S_CHANNELS >> 1)
#define NUM_RX_SERIALIZERS                    (NUM_I2S_CHANNELS >> 1)

/* McASP Serializers for Receive */
#define MCASP_XSER_RX1                         (0u)
#define MCASP_XSER_RX2                         (1u)
#define MCASP_XSER_RX3                         (2u)
#define MCASP_XSER_RX4                         (10u)

/* McASP Serializers for Transmit */
#define MCASP_XSER_TX1                         (5u)
#define MCASP_XSER_TX2                         (6u)
#define MCASP_XSER_TX3                         (7u)
#define MCASP_XSER_TX4                         (8u)
#define MCASP_XSER_TX5                         (9u)

#define EDMA3CC_OPT_TCC (0x0003F000u)

#define EDMA3CC_OPT_TCC_SHIFT (0x0000000Cu)

/*
** Definitions which are not configurable
*/
#define EDMA3CC_OPT_DAM 				(0x00000002u)
#define EDMA3CC_OPT_SAM 				(0x00000001u)

#define SIZE_PARAMSET                     (32U)
#define OPT_FIFO_WIDTH                    (0x02 << 8U)

/*
** Definitions which are configurable depending on the core to be used(ARM or DSP)
*/
#ifdef BUILD_DSP
#define EDMA3_CC_REGION		             (1U)
#else
#define EDMA3_CC_REGION		             (0U)
#endif

#define EDMA3_CC_QUEUE                   (0U)

#define SOC_I2Cx_BASE                  	 (CSL_I2C_0_DATA_CFG)

/* Interrupt channels to map in AINTC */
#define INT_CHANNEL_I2C                       (2u)
#define INT_CHANNEL_MCASP                     (2u)
#define INT_CHANNEL_EDMACC                    (2u)


/* AIC3106 codec address */
#define I2C_SLAVE_CODEC_AIC31                 (0x18u)

/* Audio Loopback test duration in secs */
#define TEST_DURATION_SECS                (15)
/* Total number of samples received during the test */
#define TEST_SAMPLE_COUNT                 ((TEST_DURATION_SECS) * (SAMPLING_RATE))

/* ========================================================================== */
/*                          Function prototypes                              */
/* ========================================================================== */
#endif //_MCASP_AUDIODC_TEST_H_
