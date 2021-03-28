/**
 *  \file       spi.h
 *
 *  \brief      This file contains the function prototypes for the device
 *              abstraction layer for Keystone SPI. It also contains some
 *              related macro definitions.
*/

/*
* Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef SPI_v0_H_
#define SPI_v0_H_

#include <ti/csl/cslr_spi.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
**                       MACRO DEFINITIONS
****************************************************************************/

/*
** Values of polarity and phase of SPICLK that are used to configure the clock
** value in various modes of operation.
*/
#define SPI_CLK_MODE_0              ((CSL_SPI_SPIFMT_POLARITY_LOW << \
                                        CSL_SPI_SPIFMT_POLARITY_SHIFT) | \
                                     (CSL_SPI_SPIFMT_PHASE_NO_DELAY << \
                                        CSL_SPI_SPIFMT_PHASE_SHIFT))
#define SPI_CLK_MODE_1              ((CSL_SPI_SPIFMT_POLARITY_LOW << \
                                        CSL_SPI_SPIFMT_POLARITY_SHIFT) | \
                                     (CSL_SPI_SPIFMT_PHASE_DELAY << \
                                        CSL_SPI_SPIFMT_PHASE_SHIFT))
#define SPI_CLK_MODE_2              ((CSL_SPI_SPIFMT_POLARITY_HIGH << \
                                        CSL_SPI_SPIFMT_POLARITY_SHIFT) | \
                                     (CSL_SPI_SPIFMT_PHASE_NO_DELAY << \
                                        CSL_SPI_SPIFMT_PHASE_SHIFT))
#define SPI_CLK_MODE_3              ((CSL_SPI_SPIFMT_POLARITY_HIGH << \
                                        CSL_SPI_SPIFMT_POLARITY_SHIFT) | \
                                     (CSL_SPI_SPIFMT_PHASE_DELAY << \
                                        CSL_SPI_SPIFMT_PHASE_SHIFT))

/*
** Values that can be passed to enable/disable/clear/map status of the various
** interrupts of SPI peripheral.
** These macros can also be used to check the status obtained from
** 'SPIIntStatusGet' API.
*/
#define SPI_INT_TX_EMPTY           (CSL_SPI_SPIFLG_TXINTFLG_MASK)
#define SPI_INT_RX_FULL            (CSL_SPI_SPIFLG_RXINTFLG_MASK)
#define SPI_INT_RX_OVERRUN         (CSL_SPI_SPIFLG_OVRNINTFLG_MASK)
#define SPI_INT_TX_BITERR          (CSL_SPI_SPIFLG_BITERRFLG_MASK)
#define SPI_INT_DMA_ENABLE         (CSL_SPI_SPIINT0_DMAREQEN_MASK)

/*
** Values used to configure the SPI Global Control Register 1 (SPIGCR1)
*/
#define SPI_ENABLE_ON        (CSL_SPI_SPIGCR1_ENABLE_ENABLE)
#define SPI_ENABLE_OFF       (CSL_SPI_SPIGCR1_ENABLE_DISABLE)
#define SPI_LOOPBACK_ON      (CSL_SPI_SPIGCR1_LOOPBACK_ENABLE)
#define SPI_LOOPBACK_OFF     (CSL_SPI_SPIGCR1_LOOPBACK_DISABLE)
#define SPI_POWERDOWN_ON     (CSL_SPI_SPIGCR1_POWERDOWN_ENABLE)
#define SPI_POWERDOWN_OFF    (CSL_SPI_SPIGCR1_POWERDOWN_DISABLE)
#define SPI_MASTER_MODE      (3U)    /* Master mode, SPICLK is an output */
#define SPI_SLAVE_MODE       (0U)    /* Slave mode, SPICLK is an input */

/*
** Values used to configure the SPI Pin Control Register 0 (SPIPC0)
*/
#define SPI_CHIP_SEL_MASK    (CSL_SPI_SPIPC0_SCS0FUN0_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN1_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN2_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN3_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN4_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN5_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN6_MASK | \
                              CSL_SPI_SPIPC0_SCS0FUN7_MASK)

/*
** Values used to configure the SPI Data Register 1 (SPIDAT1)
*/
#define SPI_DFSEL_0          (CSL_SPI_SPIDAT1_DFSEL_FORMAT0)
#define SPI_DFSEL_1          (CSL_SPI_SPIDAT1_DFSEL_FORMAT1)
#define SPI_DFSEL_2          (CSL_SPI_SPIDAT1_DFSEL_FORMAT2)
#define SPI_DFSEL_3          (CSL_SPI_SPIDAT1_DFSEL_FORMAT3)

/*
** Values used to configure the SPI Pin Control Register 0 (SPIPC0)
*/
#define SPI_SOMIFUN_ON       (CSL_SPI_SPIPC0_SOMIFUN_SPI)
#define SPI_SOMIFUN_OFF      (CSL_SPI_SPIPC0_SOMIFUN_RESETVAL)
#define SPI_SIMOFUN_ON       (CSL_SPI_SPIPC0_SIMOFUN_SPI)
#define SPI_SIMOFUN_OFF      (CSL_SPI_SPIPC0_SIMOFUNN_RESETVAL)
#define SPI_CLKFUN_ON        (CSL_SPI_SPIPC0_CLKFUN_SPI)
#define SPI_CLKFUN_OFF       (CSL_SPI_SPIPC0_CLKFUN_RESETVAL)

/*
** Values used to configure the SPI Delay Register (SPIDELAY)
*/
#define SPI_C2TDELAY(x)      (x)
#define SPI_T2CDELAY(x)      (x)

/*
** Values used to configure the SPI Data1 Register (SPIDAT1)
*/
#define SPI_CSHOLD_ON        (CSL_SPI_SPIDAT1_CSHOLD_ENABLE)
#define SPI_CSHOLD_OFF       (CSL_SPI_SPIDAT1_CSHOLD_DISABLE)
#define SPI_DELAY_ON         (CSL_SPI_SPIDAT1_WDEL_ENABLE)
#define SPI_DELAY_OFF        (CSL_SPI_SPIDAT1_WDEL_DISABLE)

#define SPI_INT_LINE_INT0     (0U)
#define SPI_INT_LINE_INT1     (1U)
#define SPI_INT_LEVEL_INT0    (0U)
#define SPI_INT_LEVEL_INT1    (0x3FFU)
#define SPI_INT_MASK          (SPI_INT_TX_EMPTY   | \
                               SPI_INT_RX_FULL    | \
                               SPI_INT_RX_OVERRUN | \
                               SPI_INT_TX_BITERR)

extern void SPICSEnable(uint32_t baseAdd, uint32_t cs);
extern void SPICSDisable(uint32_t baseAdd, uint32_t cs);

extern void SPIReset(uint32_t baseAdd);
extern void SPIIntInit(uint32_t baseAdd);
extern void SPIIntInit2(uint32_t baseAdd, uint32_t intrLine);
extern void SPIIntEnable(uint32_t baseAdd, uint32_t intFlags);
extern void SPIIntDisable(uint32_t baseAdd, uint32_t intFlags);
extern uint32_t SPIIntStatusGet(uint32_t baseAdd);
extern void SPIIntStatusClear(uint32_t baseAdd, uint32_t intFlags);
extern void SPITransmitData(uint32_t baseAdd, uint32_t csHold, uint32_t txData);
extern uint32_t SPIReceiveData(uint32_t baseAdd);

extern void SPIGlobalControlSetup(uint32_t baseAdd, uint32_t loopback,
                                  uint32_t powerdown, uint32_t clk_master);
extern void SPIPinControlSetup(uint32_t baseAdd, uint32_t somiFun,
                         uint32_t simoFun, uint32_t clkFun);
extern void SPIDataFormatSetup(uint32_t baseAdd, uint32_t df_sel, uint32_t inputClkFreq,
                         uint32_t spiOutClk, uint32_t clockMode, uint32_t charLen);
extern void SPIDataFormatSetupSlave(uint32_t baseAdd, uint32_t df_sel, uint32_t charLen);
extern void SPIClockModeSetup(uint32_t baseAdd, uint32_t df_sel, uint32_t clockMode);
extern void SPIDelaySetup(uint32_t baseAdd, uint32_t c2tDelay, uint32_t t2cDelay);
extern void SPIData1Setup(uint32_t baseAdd, uint32_t delay_enable, uint32_t cs);
extern Bool SPIRxFull(uint32_t baseAdd);
extern Bool SPITxEmpty(uint32_t baseAdd);
extern void SPIXferEnable(uint32_t baseAdd);
extern void SPIXferDisable(uint32_t baseAdd);
extern void SPILoopbackEnable(uint32_t baseAdd);
extern void SPILoopbackDisable(uint32_t baseAdd);
extern void SPISetShiftDir(uint32_t baseAdd, uint32_t shift_dir);
extern void SPIPwrDownEnable(uint32_t baseAdd);
extern void SPIPwrDownDisable(uint32_t baseAdd);
#ifdef __cplusplus
}
#endif

#endif

