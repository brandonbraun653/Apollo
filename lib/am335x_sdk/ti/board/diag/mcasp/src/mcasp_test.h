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

/**
 * \file  mcasp_test.h
 *
 * \brief The macro definitions and function prototypes for
 *        configuring mcasp
 *
 */

#ifndef _MCASP_TEST_H_
#define _MCASP_TEST_H_

#if defined(SOC_AM65XX) || defined(SOC_K2G)
#include <ti/board/board.h>
#include "board.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#ifdef  SOC_K2G
#define SOC_EDMA3_CC_BASE        (CSL_EDMACC_1_REGS)
#define SOC_MCASP_CFG_BASE       (CSL_MCASP_2_CFG_REGS)
#define SOC_MCASP_BASE           (CSL_MCASP_2_SLV_REGS)
#define SOC_MCASP_2_FIFO_REGS    (CSL_MCASP_2_FIFO_CFG_REGS)
/*
** Values which are configurable
*/
/* Slot size to send/receive data */
#define SLOT_SIZE                         (32U)
/* Word size to send/receive data. Word size <= Slot size */
#define WORD_SIZE                         (32U)
/* Number of channels, L & R */
#define NUM_I2S_CHANNELS                  (1U)
/* McASP Serializer 0 for Transmit */
#define MCASP_XSER_TX                     (2U)
/* McASP Serializer 1 for Transmit */
#define MCASP_XSER_RX                     (3U)
#define EDMA3_CHA_MCASP_RX                (CSL_EDMACC_1_McASP_2_REVT)
#define EDMA3_CHA_MCASP_TX                (CSL_EDMACC_1_McASP_2_XEVT)
#define SOC_I2Cx_BASE                     (CSL_I2C_1_DATA_CFG_REGS)
#define I2C_SLAVE_CODEC_AIC31             (0x1B)

#elif defined (SOC_AM65XX)
#define SOC_I2Cx_BASE                     (CSL_I2C0_CFG_BASE)
#define SOC_MCASP_BASE                    (CSL_MCASP0_CFG_BASE)
#define SOC_MCASP_CFG_BASE                (CSL_MCASP0_CFG_BASE)
#define I2C_SLAVE_CODEC_AIC31             (0x1Bu)
/* McASP Serializer 0 for Transmit */
#define MCASP_XSER_TX                     (0)
/* McASP Serializer 1 for Receive */
#define MCASP_XSER_RX                     (1U)

/*
** Values which are configurable
*/
/* Slot size to send/receive data */
#define SLOT_SIZE                         (32U)
/* Word size to send/receive data. Word size <= Slot size */
#define WORD_SIZE                         (32U)
/* Number of channels, L & R */
#define NUM_I2S_CHANNELS                  (1U)

#else /* #ifdef SOC_K2G */

#define SOC_EDMA3_CC_BASE         (CSL_EDMA3CC_0_REGS)
#define SOC_MCASP_CFG_BASE        (CSL_MCASP_1_CFG_REGS)
#define SOC_MCASP_BASE            (CSL_MCASP_1_CFG_REGS + 0x00002000)
#define SOC_MCASP_1_FIFO_REGS     (CSL_MCASP_1_FIFO_CFG_REGS)

/*
** Values which are configurable
*/
/* Slot size to send/receive data */
#define SLOT_SIZE                         (16U)
/* Word size to send/receive data. Word size <= Slot size */
#define WORD_SIZE                         (16U)
/* Number of channels, L & R */
#define NUM_I2S_CHANNELS                  (2U)
/* McASP Serializer 0 for Transmit */
#define MCASP_XSER_TX                     (5U)
/* McASP Serializer 1 for Transmit */
#define MCASP_XSER_RX                     (0U)

#define EDMA3_CHA_MCASP_RX                (2U)
#define EDMA3_CHA_MCASP_TX                (3U)

#define SOC_I2Cx_BASE                     (CSL_I2C_0_DATA_CFG)

#define I2C_SLAVE_CODEC_AIC31             (0x18u)

#endif   /* #ifdef SOC_K2G */

/* Sampling Rate which will be used by both transmit and receive sections */
#define SAMPLING_RATE                     (48000u)
#define SAMPLING_RATE_192KHZ              (192000u)
#define SAMPLING_RATE_48KHZ               (48000u)



/* Number of samples to be used per audio buffer */
#define NUM_SAMPLES_PER_AUDIO_BUF         (500U)

/* Audio Loopback test duration in secs */
/* Test runs for 6 hours in stress mode. 3 hours at 48KHz and 3 hours at 192KHz */
#ifdef DIAG_STRESS_TEST
#define TEST_DURATION_SECS                (3 * 60 * 60)
#else
#define TEST_DURATION_SECS                (15)
#endif
/* Total number of samples received during the test */
#define TEST_SAMPLE_COUNT                 ((TEST_DURATION_SECS) * (SAMPLING_RATE) * NUM_I2S_CHANNELS)


/* Number of buffers used per tx/rx */
#define NUM_BUF                           (3U)

/* Number of linked parameter set used per tx/rx */
#define NUM_PAR                           (2U)

/* Specify where the parameter set starting is */
#define PAR_ID_START                      (40U)

/* Number of samples in loop buffer */
#define NUM_SAMPLES_LOOP_BUF              (10U)

/*
** Below Macros are calculated based on the above inputs
*/

#define I2S_SLOTS                         ((1 << NUM_I2S_CHANNELS) - 1)

#define BYTES_PER_SAMPLE                  ((WORD_SIZE >> 3) \
                                           * NUM_I2S_CHANNELS)

#define AUDIO_BUF_SIZE                    (NUM_SAMPLES_PER_AUDIO_BUF \
                                           * BYTES_PER_SAMPLE)
#define TCC_NUM								1

#define TX_DMA_INT_ENABLE                ((((EDMA_TPCC_OPT_TCC_MASK >> EDMA_TPCC_OPT_TCC_SHIFT ) & EDMA3_CHA_MCASP_TX) << EDMA_TPCC_OPT_TCC_SHIFT) | \
											(1 << EDMA_TPCC_OPT_TCINTEN_SHIFT))

#define RX_DMA_INT_ENABLE                ((((EDMA_TPCC_OPT_TCC_MASK >> EDMA_TPCC_OPT_TCC_SHIFT ) & EDMA3_CHA_MCASP_RX) << EDMA_TPCC_OPT_TCC_SHIFT) | \
											(1 << EDMA_TPCC_OPT_TCINTEN_SHIFT))

#define PAR_RX_START                     (PAR_ID_START)
#define PAR_TX_START                     (PAR_ID_START + NUM_PAR)

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

/* Interrupt channels to map in AINTC */
#if defined(SOC_AM65XX)
#define INT_CHANNEL_I2C                       (0u)
#define INT_CHANNEL_MCASP                     (0u)
#else
#define INT_CHANNEL_I2C                       (2u)
#define INT_CHANNEL_MCASP                     (2u)
#endif /* SOC_AM65XX */
#define INT_CHANNEL_EDMACC                    (7u)

#define PIN_MASK                          (0xF)


/* ========================================================================== */
/*                          Function prototypes                              */
/* ========================================================================== */
#endif //_MCASP_TEST_H
