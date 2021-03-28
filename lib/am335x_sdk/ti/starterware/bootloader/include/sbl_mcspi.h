/**
 *  \file  sbl_mcspi.h
 *
 *  \brief This file contains the prototypes of the function to configure
 *         platform for performing copy of boot image.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
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

#ifndef SBL_MCSPI_H_
#define SBL_MCSPI_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */
/** \brief Structure holding MCSPI configuration parameters. */
typedef struct sblMcspiCfg
{
    uint32_t channel;
    /**< Single/Multi channel of operation. */
    uint32_t txRxMode;
    /**< Transmit/receive mode. */
    uint32_t pinMode;
    /**< Pin configuration of data lines. */
    uint32_t clkMode;
    /**< phase and polarity configuration of clock. */
    uint32_t wordLength;
    /**< Word length to be used for SPI transfer. */
    uint32_t csPolarity;
    /**< Polarity of chip select. */
    uint32_t txFifoCfg;
    /**< Configure Tx FIFO. */
    uint32_t rxFifoCfg;
    /**< Configure Rx FIFO. */
    uint32_t intrMask;
    /**< Mask to configure MCSPI interrupts. */
}sblMcspiCfg_t;

typedef struct sblMcspiFlag
{
    uint32_t csFlag;
    /**< Enable/Disable chip select . */
    uint32_t modeFlag;
    /**< Master/Slave mode of operation. */
}sblMcspiFlag_t;

/**< \brief Structure holding the MCSPI object data structure. */
typedef struct sblMcspiCfgObj
{
    uint32_t instNum;
    /**< MCSPI instance number. */
    uint32_t instAddr;
    /**< MCSPI instance address. */
    uint32_t inClk;
    /**< Input clock to MCSPI in MHz. */
    uint32_t outClk;
    /**< Output clock on the bus in MHz. */
    uint32_t channelNum;
    /**< MCSPI channel number. */
    uint32_t dataLength;
    /**< Data transfer length. */
    uint8_t *pTx;
    /**< Pointer to Tx buffer. */
    uint8_t *pRx;
    /**< Pointer to Rx buffer. */
    sblMcspiCfg_t pSblMcspiCfg;
    /**< MCSPI configuration structure.*/
    sblMcspiFlag_t pSblMcspiFlag;
    /**< MCSPI flag structure which shall allow user to
         1) Enable/disable chip select.
         2) Configure Master/Slave mode.
         3) Configure Interrupt/DMA mode
    */
}sblMcspiCfgObj_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function copies the image from Serial flash to DDR.
 *
 * \param   pEntryPoint  Entry address read fronm the TI image header.
 * \param   instNum      MCSPI instance number.
 *
 * \retVal  TRUE         Application image successfully copied.
 * \retVal  FALSE        Application image copy failed.
 */
uint32_t SBLMcspiCopy(uint32_t *pEntryPoint, uint32_t instNum);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef SBL_MCSPI_H_ */
