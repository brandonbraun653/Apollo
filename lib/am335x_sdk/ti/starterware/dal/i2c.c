/**
 *  \file   i2c.c
 *
 *  \brief  This file contains the device abstraction layer API implementation
 *          corresponding to I2C module.
 *
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "hw_types.h"
#include "hw_i2c.h"
#include "i2c.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void I2CClkConfig(uint32_t baseAddr,
                  uint32_t sysClk,
                  uint32_t internalClk,
                  uint32_t outputClk)
{
    uint32_t prescalar = 0U;
    uint32_t divider = 0U;

    /* Calculate prescalar value */
    prescalar = (sysClk / internalClk) - 1U;
    HW_WR_REG32((baseAddr + I2C_PSC), prescalar);

    divider = internalClk / outputClk;
    divider = divider / 2U;

    HW_WR_REG32((baseAddr + I2C_SCLL), (divider - 7U));
    HW_WR_REG32((baseAddr + I2C_SCLH), (divider - 5U));
}

void I2CModuleEnable(uint32_t baseAddr, uint32_t enableModule)
{
    if(TRUE == enableModule)
    {
        /* Bring the I2C module out of reset */
        HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_EN, I2C_CON_EN_ENABLED);
    }
    else
    {
        /* Put I2C module in reset */
        HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_EN, I2C_CON_EN_RESET);
    }
}

uint32_t I2CBusBusyStatus(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if((HW_RD_REG32(baseAddr + I2C_IRQSTS_RAW)) & (I2C_IRQSTS_RAW_BB_MASK))
    {
         status = TRUE;
    }

    return status;
}

uint32_t I2CErrStatus(uint32_t baseAddr)
{
    uint32_t err = 0U;

    err = ((HW_RD_REG32(baseAddr + I2C_IRQSTS_RAW)) & (I2C_IRQSTS_RAW_AL_MASK
         | I2C_IRQSTS_RAW_AERR_MASK | I2C_IRQSTS_RAW_NACK_MASK |
        I2C_IRQSTS_RAW_ROVR_MASK | I2C_IRQSTS_RAW_XUDF_MASK));

    return err;
}

void I2CSetMode(uint32_t baseAddr, uint32_t i2cMode)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + I2C_CON);

    /* Configure the I2C controller for different modes of operation */
    if(I2C_MODE_MASTER_TX == i2cMode)
    {
        HW_SET_FIELD(regVal, I2C_CON_MST, I2C_CON_MST_MASTER);

        HW_SET_FIELD(regVal, I2C_CON_TRX,
                        I2C_CON_TRX_TRANSMITTER);
    }
    else if(I2C_MODE_MASTER_RX == i2cMode)
    {
        HW_SET_FIELD(regVal, I2C_CON_MST, I2C_CON_MST_MASTER);

        HW_SET_FIELD(regVal, I2C_CON_TRX,
                        I2C_CON_TRX_RECEIVER);
    }
    else if(I2C_MODE_SLAVE == i2cMode)
    {
        HW_SET_FIELD(regVal, I2C_CON_MST, I2C_CON_MST_SLAVE);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Write the Mode of Operation */
    HW_WR_REG32((baseAddr + I2C_CON), regVal);
}

void I2CStartByteModeEnable(uint32_t baseAddr, uint32_t enableStartByte)
{
    if(TRUE == enableStartByte)
    {
        /* Configures the I2C in Master mode for enabling the Start Byte mode */
        HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_MST,
                        I2C_CON_MST_MASTER);
        /* Enable the Start Byte Mode */
        HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_STB,
                        I2C_CON_STB_START_BYTE);
    }
    else
    {
        /* Disable the Start Byte Mode */
        HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_STB, I2C_CON_STB_NORMAL);
    }
}


void I2CStart(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_STT,
                   I2C_CON_STT_START_CONDITION);
}


void I2CStop(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_STP,
                    I2C_CON_STP_STOP_CONDITION);
}

void I2CIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + I2C_IRQEN_SET);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + I2C_IRQEN_SET), regVal);
}


void I2CIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + I2C_IRQEN_CLR), intrMask);
}

uint32_t I2CIntrStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + I2C_IRQSTS));
}

uint32_t I2CIntrRawStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + I2C_IRQSTS_RAW));
}

void I2CIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + I2C_IRQSTS), intrMask);
}


void I2CIntrTrigger(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + I2C_IRQSTS_RAW), intrMask);
}


void I2CMasterSetSlaveAddr(uint32_t baseAddr,
                           uint32_t slaveAddr,
                           uint32_t addrMode)
{
    /*Sets the address of the slave with which the master will communicate.*/
    HW_WR_REG32((baseAddr + I2C_SA), slaveAddr);

     /* Set the address mode for the own address */
     if(I2C_ADDRMODE_7BIT == addrMode)
     {
         /* Set the 7-bit address mode for the own address */
         HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XSA,
                         I2C_CON_XSA_MODE_7);
     }
     else
     {
          /* Set the 10-bit address mode for the own address */
          HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XSA,
                          I2C_CON_XSA_MODE_10);
     }
}


uint32_t I2CMasterGetSlaveAddr(uint32_t baseAddr)
{
    /* Returns the address of the slave with which master will communicate. */
    return (HW_RD_FIELD32(baseAddr + I2C_SA, I2C_SA));
}


void I2CSetDataCount(uint32_t baseAddr, uint32_t count)
{
    HW_WR_FIELD32((baseAddr + I2C_CNT), I2C_CNT_DCOUNT, count);
}


uint32_t I2CGetDataCount(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + I2C_CNT, I2C_CNT_DCOUNT));
}


void I2CFifoThresholdConfig(uint32_t baseAddr,
                            uint32_t thresholdVal,
                            uint32_t fifoType)
{
    if(I2C_FIFO_TX == fifoType)
    {
         HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_TXTRSH, thresholdVal);
    }
    else
    {
         HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_RXTRSH, thresholdVal);
    }
}


void I2CFifoFlush(uint32_t baseAddr, uint32_t fifoType)
{
    if(I2C_FIFO_TX == fifoType)
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF),
            I2C_BUF_TXFIFO_CLR, I2C_BUF_TXFIFO_CLR_RESET);
    }
    else if(I2C_FIFO_RX == fifoType)
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF),
            I2C_BUF_RXFIFO_CLR, I2C_BUF_RXFIFO_CLR_RESET);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_TXFIFO_CLR,
                        I2C_BUF_TXFIFO_CLR_RESET);

        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_RXFIFO_CLR,
                        I2C_BUF_RXFIFO_CLR_RESET);
    }
}

void I2CDmaTxEventEnable(uint32_t baseAddr, uint32_t enableTxDmaEvent)
{
    if(TRUE == enableTxDmaEvent)
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_XDMA_EN,
                       I2C_BUF_XDMA_EN_ENABLED);

        HW_WR_FIELD32((baseAddr + I2C_DMATXEN_SET), I2C_DMATXEN_SET_DMATX_TRANSMIT,
                        I2C_DMATXEN_SET_DMATX_TRANSMIT_MASK);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_XDMA_EN,
                       I2C_BUF_XDMA_EN_DISABLED);

        HW_WR_FIELD32((baseAddr + I2C_DMATXEN_CLR), I2C_DMATXEN_CLR_DMATX_EN,
                        I2C_DMATXEN_CLR_DMATX_EN_MASK);
    }
}

void I2CDmaRxEventEnable(uint32_t baseAddr, uint32_t enableRxDmaEvent)
{
    if(TRUE == enableRxDmaEvent)
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_RDMA_EN,
                       I2C_BUF_RDMA_EN_ENABLED);

        HW_WR_FIELD32((baseAddr + I2C_DMARXEN_SET), I2C_DMARXEN_SET_DMARX_EN,
                       I2C_DMARXEN_SET_DMARX_EN_MASK);

    }
    else
    {
        HW_WR_FIELD32((baseAddr + I2C_BUF), I2C_BUF_RDMA_EN,
                       I2C_BUF_RDMA_EN_DISABLED);

        HW_WR_FIELD32((baseAddr + I2C_DMARXEN_CLR), I2C_DMARXEN_CLR_DMARX_EN,
                       I2C_DMARXEN_CLR_DMARX_EN_MASK);

    }
}

uint32_t I2CBufStatus(uint32_t baseAddr, uint32_t bufType)
{
    uint32_t status = 0U;
    uint32_t regVal = HW_RD_REG32(baseAddr + I2C_BUFSTAT);

    switch(bufType)
    {
        case I2C_FIFO_TX:
        {
            status = HW_GET_FIELD(regVal, I2C_BUFSTAT_TXSTAT);
            break;
        }

        case I2C_FIFO_RX:
        {
            status = HW_GET_FIELD(regVal, I2C_BUFSTAT_RXSTAT);
            break;
        }

        case I2C_FIFO_SIZE:
        {
            status = HW_GET_FIELD(regVal, I2C_BUFSTAT_FIFODEPTH);
            break;
        }

        default:
        break;
    }

    return status;
}


uint32_t I2CSlaveGetActiveOwnAddr(uint32_t baseAddr)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + I2C_ACTOA);

    if (1U == ((regVal) & (I2C_ACTOA_OA0_ACT_MASK)))
    {
        regVal = HW_RD_FIELD32((baseAddr + I2C_OA), I2C_OA);
    }
    else if(1U == ((regVal) & (I2C_ACTOA_OA1_ACT_MASK)))
    {
        regVal = HW_RD_FIELD32((baseAddr + I2C_OA1), I2C_OA);
    }
    else if(1U == ((regVal) & (I2C_ACTOA_OA2_ACT_MASK)))
    {
        regVal = HW_RD_FIELD32((baseAddr + I2C_OA2), I2C_OA);
    }
    else if(1U == ((regVal) & (I2C_ACTOA_OA3_ACT_MASK)))
    {
        regVal = HW_RD_FIELD32((baseAddr + I2C_OA3), I2C_OA);
    }
    else
    {
        /* This error doesn't happen because of check done already */
    }

    return regVal;
}

void I2CSlaveSetOwnAddr(uint32_t baseAddr,
                         uint32_t ownAddr,
                         uint32_t addrMode,
                         uint32_t addrIndex)
{
    /*
    ** Set the address index field to highlight one among
    ** the four own addresses set.
    */
    switch(addrIndex)
    {
        case I2C_OWN_ADDR_INDEX_0:
        {
            /* Set the own address field for the I2C controller */
            HW_WR_FIELD32((baseAddr + I2C_OA), I2C_OA, ownAddr);

            /* Set the address mode for the own address */
            if(I2C_ADDRMODE_7BIT == addrMode)
            {
                /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA0,
                                 I2C_CON_XOA0_MODE_7);
            }
            else
            {
                /* Set the 10-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA0,
                                 I2C_CON_XOA0_MODE_10);
            }
            break;
        }

        case I2C_OWN_ADDR_INDEX_1:
        {
            /* Set the own address field for the I2C controller */
            HW_WR_FIELD32((baseAddr + I2C_OA1), I2C_OA1, ownAddr);

            /* Set the address mode for the own address */
            if(I2C_ADDRMODE_7BIT == addrMode)
            {
                /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA1,
                                 I2C_CON_XOA1_MODE_7);
            }
            else
            {
                /* Set the 10-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA1,
                                 I2C_CON_XOA1_MODE_10);
            }
            break;
        }

        case I2C_OWN_ADDR_INDEX_2:
        {
            /* Set the own address field for the I2C controller */
            HW_WR_FIELD32((baseAddr + I2C_OA2), I2C_OA2, ownAddr);

            /* Set the address mode for the own address */
            if(I2C_ADDRMODE_7BIT == addrMode)
            {
                 /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA2,
                                 I2C_CON_XOA2_MODE_7);
            }
            else
            {
                 /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA2,
                                 I2C_CON_XOA2_MODE_10);
            }
            break;
        }

        case I2C_OWN_ADDR_INDEX_3:
        {
            /* Set the own address field for the I2C controller */
            HW_WR_FIELD32((baseAddr + I2C_OA3), I2C_OA3, ownAddr);

            /* Set the address mode for the own address */
            if(I2C_ADDRMODE_7BIT == addrMode)
            {
                 /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA3,
                                 I2C_CON_XOA2_MODE_7);
            }
            else
            {
                 /* Set the 7-bit address mode for the own address */
                HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_XOA3,
                                 I2C_CON_XOA2_MODE_10);
            }
            break;
        }
        default:
        break;
    }
}

void I2CSlaveClockBlockingEnable(uint32_t baseAddr,
                                  uint32_t enableClkBlock,
                                  uint32_t addrIndex)
{
    switch(addrIndex)
    {
        case I2C_OWN_ADDR_INDEX_0:
        {
            HW_WR_FIELD32((baseAddr + I2C_SBLOCK), I2C_SBLOCK_OA0_EN,
                           enableClkBlock);
            break;
        }
        case I2C_OWN_ADDR_INDEX_1:
        {
            HW_WR_FIELD32((baseAddr + I2C_SBLOCK), I2C_SBLOCK_OA1_EN,
                           enableClkBlock);
            break;
        }
        case I2C_OWN_ADDR_INDEX_2:
        {
            HW_WR_FIELD32((baseAddr + I2C_SBLOCK), I2C_SBLOCK_OA2_EN,
                           enableClkBlock);
            break;
        }
        case I2C_OWN_ADDR_INDEX_3:
        {
            HW_WR_FIELD32((baseAddr + I2C_SBLOCK), I2C_SBLOCK_OA3_EN,
                           enableClkBlock);
            break;
        }
        default:
        break;
    }
}

void I2CSoftReset(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_SRST, I2C_SYSC_SRST_RESET);
}

void I2CAutoIdleEnable(uint32_t baseAddr, uint32_t enableIdleMode)
{
    if(TRUE == enableIdleMode)
    {
        HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_AUTOIDLE,
                        I2C_SYSC_AUTOIDLE_ENABLE);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_AUTOIDLE,
                        I2C_SYSC_AUTOIDLE_DISABLE);
    }
}

void I2CIdleModeSelect(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_IDLEMODE, idleMode);
}

void I2CClockActivitySelect(uint32_t baseAddr, uint32_t clkActSelect)
{
    HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_CLKACTIVITY, clkActSelect);
}

void I2CWakeupEnable(uint32_t baseAddr,
                     uint32_t wakeupEvent,
                     uint32_t wakeupSrc)
{
    uint32_t regVal = 0U;
    uint32_t regOffset = 0U;

    regVal = HW_RD_FIELD32(baseAddr + I2C_SYSC, I2C_SYSC_ENAWAKEUP);

    /* Check if the Wakeup mechanism is enabled if not then enable it */
    if(1U != (regVal & I2C_SYSC_ENAWAKEUP_ENABLE))
    {
        HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_ENAWAKEUP,
                        I2C_SYSC_ENAWAKEUP_ENABLE);
    }

    if (I2C_WAKEUP_SRC_IRQ == wakeupSrc)
    {
        /* Set the offset for Interrupt wake source register */
        regOffset = I2C_WE;
    }
    else if (I2C_WAKEUP_SRC_DMA_RX == wakeupSrc)
    {
        /* Set the offset for Interrupt wake source register */
        regOffset = I2C_DMARXWAKE_EN;
    }
    else if (I2C_WAKEUP_SRC_DMA_TX == wakeupSrc)
    {
        /* Set the offset for Interrupt wake source register */
        regOffset = I2C_DMATXWAKE_EN;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Enable the Wakeup Sources */
    regVal = HW_RD_REG32(baseAddr + regOffset);
    regVal |= wakeupEvent;
    HW_WR_REG32((baseAddr + regOffset), regVal);

}

void I2CWakeupDisable(uint32_t baseAddr,
                       uint32_t wakeupEvent,
                       uint32_t wakeupSrc)
{
    uint32_t regVal = 0U;
    uint32_t regOffset = 0U;

    if(I2C_WAKEUP_SRC_IRQ == wakeupSrc)
    {
        /* Set the offset for Interrupt wake source register */
        regOffset = I2C_WE;
    }
    else if(I2C_WAKEUP_SRC_DMA_RX == wakeupSrc)
    {
        /* Set the offset for RX DMA wake source register */
        regOffset = I2C_DMARXWAKE_EN;
    }
    else if(I2C_WAKEUP_SRC_DMA_TX == wakeupSrc)
    {
        /* Set the offset for TX DMA wake source register */
        regOffset = I2C_DMATXWAKE_EN;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Disable the wakeup source event */
    regVal = HW_RD_REG32(baseAddr + regOffset);
    regVal &= ~wakeupEvent;
    HW_WR_REG32((baseAddr + regOffset), regVal);

    regVal = HW_RD_REG32(baseAddr + regOffset);

    /* Check if all wakeup events are disabled */
    if(1U != (regVal & I2C_WAKEUP_EVT_ALL))
    {
        /* Disable the wakeup mechanism for the module */
        HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_ENAWAKEUP,
                    I2C_SYSC_ENAWAKEUP_DISABLE);
    }
}

uint32_t I2CSystemStatus(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(1U == HW_RD_FIELD32(baseAddr + I2C_SYSS, I2C_SYSS_RDONE))
    {
        status = TRUE;
    }

    return status;
}

void I2CPutTxData(uint32_t baseAddr, uint8_t txData)
{
     /*write data to be transmitted to Data transmit register */
    HW_WR_REG32((baseAddr + I2C_DATA), txData);
}

uint8_t I2CGetRxData(uint32_t baseAddr)
{
    uint8_t rxData;

    rxData = (uint8_t)HW_RD_REG32(baseAddr + I2C_DATA);

    return rxData;
}

void I2CFreeRunEnable(uint32_t baseAddr, uint32_t enableFreeRun)
{
    if(TRUE == enableFreeRun)
    {
        /* Enable the Free Run mode */
        HW_WR_FIELD32(baseAddr + I2C_SYSTEST, I2C_SYSTEST_FREE,
                         I2C_SYSTEST_FREE_RUNNING);
    }
    else
    {
        /* Disable the Free Run mode */
        HW_WR_FIELD32(baseAddr + I2C_SYSTEST, I2C_SYSTEST_FREE,
                         I2C_SYSTEST_FREE_STOP);
    }

}

void I2CContextSave(uint32_t baseAddrr, i2cCtx_t *pCtx)
{
    pCtx->prescalar   = HW_RD_REG32(baseAddrr + I2C_PSC);
    pCtx->lowDivider  = HW_RD_REG32(baseAddrr + I2C_SCLL);
    pCtx->highDivider = HW_RD_REG32(baseAddrr + I2C_SCLH);
    pCtx->ownAddr     = HW_RD_REG32(baseAddrr + I2C_OA);
}


void I2CContextRestore(uint32_t baseAddr, i2cCtx_t *pCtx)
{
    /* Disable module */
    HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_EN, I2C_CON_EN_RESET);

    HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_SRST,
                   I2C_SYSC_SRST_RESET);
    HW_WR_FIELD32((baseAddr + I2C_SYSC), I2C_SYSC_AUTOIDLE,
                   I2C_SYSC_AUTOIDLE_DISABLE);

    HW_WR_REG32((baseAddr + I2C_PSC), pCtx->prescalar);
    HW_WR_REG32((baseAddr + I2C_SCLL), pCtx->lowDivider);
    HW_WR_REG32((baseAddr + I2C_SCLH), pCtx->highDivider);
    HW_WR_REG32((baseAddr + I2C_OA), pCtx->ownAddr);

    /* Enable module */
    HW_WR_FIELD32((baseAddr + I2C_CON), I2C_CON_EN, I2C_CON_EN_ENABLED);

    /* Wait till reset is complete. */
    while((!HW_RD_REG32(baseAddr + I2C_SYSS) & I2C_SYSS_RDONE_MASK));
}

/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */

uint32_t I2CMasterBusy(uint32_t baseAddr)
{
    return(HW_RD_FIELD32((baseAddr + I2C_CON), I2C_CON_MST)
             & I2C_CON_MST_MASK);
}
