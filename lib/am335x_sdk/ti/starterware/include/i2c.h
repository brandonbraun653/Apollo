/**
 *  \file       i2c.h
 *
 *  \brief      This file contains the function prototypes for the device
 *              abstraction layer for high speed I2C. It also contains some
 *              related macro definitions and some files to be included.
 *
 *  \details    Please find the below detailed description of i2c dal.
 *              -# I2C controller will basically operates in the following modes
 *                  -# Master Transmitter or Master Receiver.
 *                  -# Slave.
 *              -# Programming sequence for initializing the i2c controller in
 *                 master mode.
 *                  -# Perform Clock and pin mux configuration.
 *                  -# Disable the module through api #I2CModuleEnable.
 *                  -# Disable the auto idle mode through api
 *                     #I2CAutoIdleEnable
 *                  -# Configure the internal clock dividers of i2c controller
 *                     through api #I2CClkConfig
 *                  -# Configure the slave address through the api
 *                     #I2CMasterSetSlaveAddr
 *                  -# Enable the i2c module through api #I2CModuleEnable
 *              -# Programming sequence for setting up i2c write
 *                  -# Set the transfer length (number of bytes) through the api
 *                     #I2CSetDataCount
 *                  -# Configure the i2c controller in master transmitter mode
 *                     using the api #I2CSetMode
 *                  -# Enable necessary interrupts using the api
 *                     #I2CIntrEnable
 *                  -# Generate start condition using the api #I2CStart
 *                  -# Check for data completion either through interrupts or
 *                     through status checking.
 *              -# Programming sequence for setting up i2c read is same as write
 *                 except configuring the i2c controller in master receiver mode
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

#ifndef _I2C_H_
#define _I2C_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "misc.h"
#include "hw_i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define I2CMasterDataGet         I2CGetRxData
#define I2CMasterDataPut         I2CPutTxData
#define I2CSystemStatusGet       I2CSystemStatus
#define I2CWakeUpDisable         I2CWakeupDisable
#define I2CWakeUpEnable          I2CWakeupEnable
#define I2CActiveOwnAddressGet   I2CSlaveGetActiveOwnAddr
#define I2CBufferStatus          I2CBufStatus
#define I2CFIFOClear             I2CFifoFlush
#define I2CFIFOThresholdConfig   I2CFifoThresholdConfig
#define I2CDataCountGet          I2CGetDataCount
#define I2CMasterSlaveAddrGet    I2CMasterGetSlaveAddr
#define I2CMasterSlaveAddrSet    I2CMasterSetSlaveAddr
#define I2CMasterIntRawStatus    I2CIntrRawStatus
#define I2CMasterIntStatus       I2CIntrStatus
#define I2CMasterStop            I2CStop
#define I2CMasterStart           I2CStart
#define I2CMasterErr             I2CErrStatus
#define I2CMasterBusBusy         I2CBusBusyStatus
#define I2CMasterInitExpClk      I2CClkConfig

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Macro to identify the FIFO Size field */
#define I2C_FIFO_SIZE                                     (2U)

/** \brief System Clock used by the I2C module */
#define I2C_SYS_CLK                                       (48000000U)

/** \brief Internal Clock used by the I2C module for Standard/Fast Mode */
#define I2C_INT_CLK                                       (24000000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the different I2C Modes. */
typedef enum i2cMode
{
    I2C_MODE_MASTER_TX = 0U,
    /**< I2C controller is in master transmitter mode. */
    I2C_MODE_MASTER_RX = 1U,
    /**< I2C controller is in master receiver mode. */
    I2C_MODE_SLAVE = 2U,
    /**< I2C controller is in slave mode. */
}i2cMode_t;

/**
 *  \brief Enumerates the types of Addressing modes supported.
 */
typedef enum i2cAddrMode
{
    I2C_ADDRMODE_MIN = 0U,
    /**< Min Addressing mode of the I2C device */
    I2C_ADDRMODE_7BIT = I2C_ADDRMODE_MIN,
    /**< 7-bit Addressing mode of the I2C Slave device */
    I2C_ADDRMODE_10BIT,
    /**< 10-bit Addressing mode of the I2C Slave device */
    I2C_ADDRMODE_MAX = I2C_ADDRMODE_10BIT,
    /**< Max Addressing Type of the I2C Slave device */
}i2cAddrMode_t;

/** \brief Enumerates the type of i2c interrupts. */
typedef enum i2cIntr
{
    I2C_INTR_ARBITRATION_LOST  = I2C_IRQSTS_AL_MASK,
    /**< Arbitration lost interrupt. */
    I2C_INTR_NO_ACK            = I2C_IRQSTS_NACK_MASK,
    /**< No Acknowledgement interrupt. */
    I2C_INTR_REG_ACESS_RDY     = I2C_IRQSTS_ARDY_MASK,
    /**< I2C registers are ready to access interrupt. */
    I2C_INTR_RX_READY          = I2C_IRQSTS_RRDY_MASK,
    /**< Receive data ready interrupt. */
    I2C_INTR_TX_READY          = I2C_IRQSTS_XRDY_MASK,
    /**< Transmit data ready interrupt. */
    I2C_INTR_GENERAL_CALL      = I2C_IRQSTS_GC_MASK,
    /**< General call interrupt.*/
    I2C_INTR_START_CONDITION   = I2C_IRQSTS_STC_MASK,
    /**< Start condition interrupt. */
    I2C_INTR_ACCESS_ERR        = I2C_IRQSTS_AERR_MASK,
    /**< Access error interrupt. */
    I2C_INTR_STOP_CONDITION    = I2C_IRQSTS_BF_MASK,
    /**< Stop Condition/Bus Free interrupt.*/
    I2C_INTR_ADDR_AS_SLAVE     = I2C_IRQSTS_AAS_MASK,
    /**< Addressed as slave interrupt. */
    I2C_INTR_TX_UNDERFLOW      = I2C_IRQSTS_XUDF_MASK,
    /**< Transmit under flow interrupt. */
    I2C_INTR_RX_OVERRUN        = I2C_IRQSTS_ROVR_MASK,
    /**< Receive overrun interrupt. */
    I2C_INTR_BUS_BUSY          = I2C_IRQSTS_BB_MASK,
    /**< Bus busy interrupt.*/
    I2C_INTR_RX_DRAIN          = I2C_IRQSTS_RDR_MASK,
    /**< Receive draining interrupt. */
    I2C_INTR_TX_DRAIN          = I2C_IRQSTS_XDR_MASK,
    /**< Transmit draining interrupt. */
    I2C_INTR_ALL               = 0x7FFFU
    /**< Mask for all the I2C interrupt types. Used for enable/disable/status
         get of all the i2c interrupts at once. */
}i2cIntr_t;

/** \brief Enumerates the different fifo types supported by the module
           FIFO. */
typedef enum i2cFifo
{
    I2C_FIFO_TX  = 0U,
    /**< Flag to indicate Transmit FIFO of I2C module. */
    I2C_FIFO_RX,
    /**< Flag to indicate Receive FIFO of I2C module. */
}i2cFifo_t;

/** \brief Enumerates the index fields used to set the different address
           fields. */
typedef enum i2cOwnAddrIndex
{
    I2C_OWN_ADDR_INDEX_MIN = 0U,
    /**< Minimum Address index value. Used for input validation. */
    I2C_OWN_ADDR_INDEX_0 = I2C_OWN_ADDR_INDEX_MIN,
    /**< Address index 0 used to set address 0 field. */
    I2C_OWN_ADDR_INDEX_1,
    /**< Address index 0 used to set address 1 field. */
    I2C_OWN_ADDR_INDEX_2,
    /**< Address index 0 used to set address 2 field. */
    I2C_OWN_ADDR_INDEX_3,
    /**< Address index 0 used to set address 3 field. */
    I2C_OWN_ADDR_INDEX_MAX = I2C_OWN_ADDR_INDEX_3
    /**< Maximum Address index value. Used for input validation. */
}i2cOwnAddrIndex_t;

/** \brief Type of supported I2C idle modes. */
typedef enum i2cIdleMode
{
    I2C_IDLE_MODE_FORCE_IDLE   = I2C_SYSC_IDLEMODE_FORCE_IDLE,
    /**< Force Idle mode. */
    I2C_IDLE_MODE_NO_IDLE      = I2C_SYSC_IDLEMODE_NO_IDLE,
    /**< No idle mode. */
    I2C_IDLE_MODE_SMART_IDLE  = I2C_SYSC_IDLEMODE_SMART_IDLE
    /**< Smart idle mode. */
}i2cIdleMode_t;


/** \brief Enumerates the types of i2c Clock activity modes. */
typedef enum i2cClkAct
{
    I2C_CLK_ACT_BOTH_CLK_OFF  = I2C_SYSC_CLKACTIVITY_BOTH_CUT_OFF,
    /**< Both System clock and OCP clocks are off. */
    I2C_CLK_ACT_SYS_CLK_OFF   = I2C_SYSC_CLKACTIVITY_INTERFACE_ACTIVE,
    /**< OCP clock is on and System clock is off. */
    I2C_CLK_ACT_OCP_CLK_OFF   = I2C_SYSC_CLKACTIVITY_SYSTEM_ACTIVE,
    /**< OCP clock is off and System clock is on. */
    I2C_CLK_ACT_BOTH_CLK_ON   = I2C_SYSC_CLKACTIVITY_BOTH_ACTIVE
    /**< Both System and OCP clocks are kept alive. */
}i2cClkAct_t;


/** \brief Enumerates the type of wake up events supported on i2c interface
           A specific (synchronous) IRQ request corresponding to below source
           will generate an asynchronous wakeup event
           (on the appropriate swakeup line). */
typedef enum i2cWakeupEvt
{
    I2C_WAKEUP_EVT_ARBITRATION_LOST  = I2C_WE_AL_MASK,
    /**< Arbitration lost. */
    I2C_WAKEUP_EVT_NO_ACK           = I2C_WE_NACK_MASK,
    /**< No acknowledgement. */
    I2C_WAKEUP_EVT_REG_ACCESS_RDY   = I2C_WE_ARDY_MASK,
    /**< i2c registers are ready for access. */
    I2C_WAKEUP_EVT_TX_RX_DATA_RDY   = I2C_WE_DRDY_MASK,
    /**< transmit/receive data is ready. */
    I2C_WAKEUP_EVT_GENERAL_CALL     = I2C_WE_GC_MASK,
    /**< general call. */
    I2C_WAKEUP_EVT_START_CONDITION  = I2C_WE_STC_MASK,
    /**< start condition occurrence. */
    I2C_WAKEUP_EVT_STOP_CONDITION   = I2C_WE_BF_MASK,
    /**< stop condition occurrence. */
    I2C_WAKEUP_EVT_ADDR_AS_SLAVE    = I2C_WE_AAS_MASK,
    /**< Addressed as slave. */
    I2C_WAKEUP_EVT_TX_UNDERFLOW     = I2C_WE_XUDF_MASK,
    /**< Transmit underflow. */
    I2C_WAKEUP_EVT_RX_OVERRUN       = I2C_WE_ROVR_MASK,
    /**< Receive overrun. */
    I2C_WAKEUP_EVT_RX_DRAIN         = I2C_WE_RDR_MASK,
    /**< Receive drain. */
    I2C_WAKEUP_EVT_TX_DRAIN         = I2C_WE_XDR_MASK,
    /**< Transmit drain. */
    I2C_WAKEUP_EVT_ALL              = 0xFFFFU
    /**< Mask for all the I2C Wakeup sources. Used to check the status
         of all wakeup event */
}i2cWakeupEvt_t;


/** \brief Enumerates the type of the wake up event source. */
typedef enum i2cWakeupSrc
{
    I2C_WAKEUP_SRC_MIN    = 0U,
    /**< Minimum Wakeup Source value used for input validation. */
    I2C_WAKEUP_SRC_IRQ    = I2C_WAKEUP_SRC_MIN,
    /**< Wake up source is IRQ interrupt. */
    I2C_WAKEUP_SRC_DMA_RX,
    /**< Wake up source is Dma receive . */
    I2C_WAKEUP_SRC_DMA_TX,
    /**< Wake up source is Dma transmit. */
    I2C_WAKEUP_SRC_MAX = I2C_WAKEUP_SRC_DMA_TX
    /**< Maximum Wakeup source value used for input validation. */
}i2cWakeupSrc_t;

/** \brief Structure holding the I2C register context .*/
typedef struct i2cCtx
{
    uint32_t prescalar;
    /**< Pre-scalar register value.*/
    uint32_t lowDivider;
    /**< SCL low time register value.*/
    uint32_t highDivider;
    /**< SCL high time register value.*/
    uint32_t ownAddr;
    /**< Own address register value. */
}i2cCtx_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API will divide the system clock fed to I2C module between
 *          12 MHz and 100 MHz. It will also configure the I2C bus clock
 *          frequency.
 *
 * \param   baseAddr    It is the Memory address of the I2C instance used.
 * \param   sysClk      It is the System clock fed to I2C module.
 * \param   internalClk It is the internal clock used by I2C module.Which is
 *                      obtained by scaling System clock fed to I2C module.
 * \param   outputClk   It is the required I2C bus speed or frequency.
 */
void I2CClkConfig(uint32_t baseAddr,
                  uint32_t sysClk,
                  uint32_t internalClk,
                  uint32_t outputClk);

/**
 * \brief   Enables the I2C module. This will bring the I2C module out of reset.
 *
 * \param   baseAddr      It is the Memory address of the I2C instance used.
 * \param   enableModule  Flag to control the enabling/disabling of a module.
 */
void I2CModuleEnable(uint32_t baseAddr, uint32_t enableModule);

/**
 * \brief   This API determines whether bus is busy or not.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 *
 * \retval  TRUE  If Bus is busy.
 * \retval  FALSE If Bus is Free.
 */
uint32_t I2CBusBusyStatus(uint32_t baseAddr);

/**
 * \brief   This API returns the error Status if any of the error conditions are
 *          set during the I2C operation.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 *
 * \retval  errorStatus If error has occurred it returns a non zero value(mask
 *                      of error interrupts). If no error has occurred then
 *                      return status will be zero.
 *
 * \note    This API checks the following errors during I2C operation
 *          -# arbitration lost.
 *          -# access error.
 *          -# No acknowledgement.
 *          -# receive overrun.
 *          -# transmit underrun.
 */
uint32_t I2CErrStatus(uint32_t baseAddr);

/**
 * \brief   This API configures the I2C controller to different modes
 *          according to the flags passed by the user.
 *
 * \param   baseAddr  Base address of I2C instance.
 * \param   i2cMode   Is the flag which enables configuration of the controller
 *                    in any of the folowing modes master-transmit, master-receive,
 *                    and slave mode.
 *          i2cMode can take any of the values from the following enum
 *          - #i2cMode_t
 */
void I2CSetMode(uint32_t baseAddr, uint32_t i2cMode);

/**
 * \brief   This API starts a I2C transaction on the bus. This API must
 *          be called after all the configuration for the i2c module is
 *          done and after bringing I2C out of local reset.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 */
void I2CStart(uint32_t baseAddr);

/**
 * \brief  This API stops a I2C transaction on the bus. This API is used to
 *         configure the Controller to generate a STOP condition on the bus.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 */
void I2CStop(uint32_t baseAddr);

/**
 * \brief  This API enables the Start Byte mode of the I2C.
 *
 * \param  baseAddr         It is the Memory address of the I2C instance used.
 * \param  enableStartByte  value to control enabling/disabling of the
 *                          StartByte mode.
 */
void I2CStartByteModeEnable(uint32_t baseAddr, uint32_t enableStartByte);

/**
 * \brief  This API enables the specified I2C interrupts.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 * \param  intrMask  Flag specifying the interrupts that are required to be
 *                   enabled.
 *         intrMask will be one of the macros from the following enum
 *         - #i2cIntr_t.
 *
 * \note   The enable all the interrupts once the intrMask should be passed
 *         - #I2C_INTR_ALL.
 */
void I2CIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief  This API disables the specified I2C interrupts.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 * \param  intrMask  Flag specifying the interrupts that are required to be
 *                   disabled.
 *         intrMask will be one of the macros from the following enum
 *         - #i2cIntr_t.
 *
 * \note   The disable all the interrupts at once the intrMask should be passed
 *         - #I2C_INTR_ALL.
 */
void I2CIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief  This API returns the status of all active and enabled interrupts.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 *
 * \retval status    The status of all the active and enabled Interrupts.
 *
 * \note   To Check the status of a specific interrupt AND the return value
 *         of the API with specific interrupt mask from the following enum.
 *         - #i2cIntr_t.
 */
uint32_t I2CIntrStatus(uint32_t baseAddr);

/**
 * \brief  This API returns the raw interrupt status of the module.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 *
 * \retval rawStatus Raw interrupt status of all the interrupts.
 *
 * \note   To Check the status of a specific interrupt AND the return value
 *         of the API with specific interrupt mask from the following enum.
 *         - #i2cIntr_t.
 */
uint32_t I2CIntrRawStatus(uint32_t baseAddr);

/**
 * \brief  This API Clears the status of specified interrupts.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 * \param  intrMask  It specifies the interrupts whose status needs to be
 *         cleared intrMask will be one of the macros from the following enum
 *         - #i2cIntr_t.
 *
 * \note   To clear the status of all the interrupts intrMask should be passed
 *         as below.
 *         - #I2C_INTR_ALL.
 */
void I2CIntrClear(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief  This API triggers an interrupt request for the specified event.
 *
 * \param  baseAddr  It is the Memory address of the I2C instance used.
 * \param  intrMask  It specifies the spcific interrupt which has to be triggered.
 *         intrMask will take one of the macros from the following enum
 *         - #i2cIntr_t.
 *
 * \note   Here an interrupt request is manually triggered by writing to a
 *         specified bit. As a prerequisite, the interrupt generation should
 *         be enabled for the given instance.
 */
void I2CIntrTrigger(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This API sets the address of the slave device with which I2C wants
 *          to communicate.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 * \param   slaveAddr  Slave address.
 * \param   addrMode   It specifies the address mode of either 7 bit or 10 bit.
 *          addrMode can take any of the macto values from following enum
 *          - #i2cAddrMode_t
 */
void I2CMasterSetSlaveAddr(uint32_t baseAddr,
                           uint32_t slaveAddr,
                           uint32_t addrMode);

/**
 * \brief   This API returns the address of the slave device with which I2C
 *          wants to communicate.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 *
 * \retval  slaveAddr  Address of the slave device.
 */
uint32_t I2CMasterGetSlaveAddr(uint32_t baseAddr);

/**
 * \brief   This API configure I2C data count register with a value.
 *          The value in the I2C data count register indicate how many data
 *          bytes to transfer when the I2C is configured as a master-transmitter
 *          and repeat mode is off.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 * \param   count    It is value which is set to I2C data count register.
 */
void I2CSetDataCount(uint32_t baseAddr, uint32_t count);

/**
 * \brief   This API returns the number of bytes that are yet to be received or
 *          sent.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 *
 * \retval  byteCount Number of bytes transferred over the I2C bus.
 */
uint32_t I2CGetDataCount(uint32_t baseAddr);

/**
 * \brief   This API configures the threshold value for FIFO buffer.
 *
 * \param   baseAddr      It is the Memory address of the I2C instance used.
 * \param   thresholdVal  It is the threshold value for FIFO buffer, which is
 *                        used to specify the trigger level for data transmit or
 *                        data receive transfers.
 * \param   fifoType     It specifies the I2C transfer direction.
 *          fifoType can take one of the macros from the enum.
 *          - #i2cFifo_t
 */
void I2CFifoThresholdConfig(uint32_t baseAddr,
                            uint32_t thresholdVal,
                            uint32_t fifoType);

/**
 * \brief   This API Clears the Transmit and Receive FIFOs based on the
 *          choice made by the user.
 *
 * \param   baseAddr     It is the Memory address of the I2C instance used..
 * \param   fifoType     It specifies Transmit FIFO or Receive FIFO.
 *          fifoType can take following macro values from the following enum
 *          - #i2cFifo_t
 *
 * \note  To clear multiple FIFOs pass the OR of the two macro values from
 *        the enum - #i2cFifo_t
 */
void I2CFifoFlush(uint32_t baseAddr, uint32_t fifoType);

/**
 * \brief   This API Enables/Disables the transmit DMA channel according to the
 *          control flag passed by the user. This will enable the
 *          generation of transmit DMA event when i2c data register is empty.
 *
 * \param   baseAddr          It is the Memory address of the I2C instance used.
 * \param   enableTxDmaEvent  Flag to control the TX DMA event feature.
 */
void I2CDmaTxEventEnable(uint32_t baseAddr, uint32_t enableTxDmaEvent);

/**
 * \brief   This API Enables/Disables the received DMA channel.
 *          This will enable the generation of Receive DMA Event,
 *          when i2c data register is full.
 *
 * \param   baseAddr          It is the Memory address of the I2C instance used.
 * \param   enableRxDmaEvent  Flag to control the RX DMA event feature.
 */
void I2CDmaRxEventEnable(uint32_t baseAddr, uint32_t enableRxDmaEvent);

/**
 * \brief   This API returns the status of the internal buffers.
 *
 * \details Transmit buffer status indicates, the number of data bytes still
 *          left to be write in the TX FIFO. Receive buffer status indicates,
 *          number of bytes to be transferred from FIFO at the end of I2C
 *          transfer. FIFO status indicates the internal FIFO buffer width.
 *
 * \param   baseAddr     It is the Memory address of the I2C instance used..
 * \param   bufType      It specifies required status field.
 *          bufType can take macro values from the following enum
 *          - #i2cFifo_t to get the FIFO status.
 *          to get the depth of the FIFO the following macro needs to be passed
 *          - #I2C_FIFO_SIZE
 *
 * \retval bufferStatus Status of internal buffers.
 */
uint32_t I2CBufStatus(uint32_t baseAddr, uint32_t bufType);

/**
 * \brief   This API returns one of the module's four own addresses, which
 *          external master used when addressing the module.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 *
 * \retval  ownAddr   I2C controller's address(One of the module's four own
 *                    addresses which the external master uses when addressing
 *                    the module)
 */
uint32_t I2CSlaveGetActiveOwnAddr(uint32_t baseAddr);

/**
 * \brief   This API configures any one of the own address field out of four
 *          present in I2C controller. This own address will be used in slave
 *          mode. When external master wants to communicate with the controller,
 *          it uses the own address as the slave address.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 * \param   ownAddr    Own address to be set for the controller.
 * \param   addrMode   It specifies the address mode of either 7 bit or 10 bit.
 *          addrMode can take any of the macto values from following enum
 *          - #i2cAddrMode_t
 * \param   addrIndex  It specifies any of the four possible own address fields
 *                     which have to be set.
 *          addrIndex can take any of the macro values from following enum
 *          - #i2cOwnAddrIndex_t
 */
void I2CSlaveSetOwnAddr(uint32_t baseAddr,
                        uint32_t ownAddr,
                        uint32_t addrMode,
                        uint32_t addrIndex);

/**
 * \brief   This API blocks or unblocks the clock for any of the module's four
 *          own addresses.
 *
 * \param   baseAddr        It is the Memory address of the I2C instance used.
 * \param   enableClkBlock  Flag to check whether clock needs to be blocked
 *          enableClkBlock  can take any of the two macro values below
 *          -TRUE to indicate Clock blocking
 *          -FALSE to indicate releasing the clock.
 * \param   addrIndex  It indicates the address for which clock needs
 *                     to be blocked.
 *          addrIndex takes one of the following values from the enum
 *          - #i2cOwnAddrIndex_t
 */
void I2CSlaveClockBlockingEnable(uint32_t baseAddr,
                                  uint32_t enableClkBlock,
                                  uint32_t addrIndex);

/**
 * \brief   This API resets the entire I2C module. On reset, all the registers
 *          are set to power up reset values.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 */
void I2CSoftReset(uint32_t baseAddr);

/**
 * \brief   This API controls enabling/disabling of the auto-idle mechanism
 *
 * \param   baseAddr        It is the Memory address of the I2C instance used.
 * \param   enableIdleMode  Value to indicate the enabling/disabling Auto-Idle
 *          mechanism. It can take any of the two macro values below
 *          - TRUE to indicate enabling Auto-Idle mode
 *          - FALSE to indicate disabling Auto-Idle mode
 */
void I2CAutoIdleEnable(uint32_t baseAddr, uint32_t enableIdleMode);

/**
 * \brief   This API selects one of the idle modes.
 *
 * \param   baseAddr    It is the Memory address of the I2C instance used.
 * \param   idleMode    It is the flag which determines the type of idle
 *                      mode operation.
 *          idleMode can take macros from the following enum
 *          - #i2cIdleMode_t.
 */
void I2CIdleModeSelect(uint32_t baseAddr, uint32_t idleMode);

/**
 * \brief   This API disables external clock gating mechanism by selecting
 *          appropriate type of clock activity.
 *
 * \param   baseAddr      It is the Memory address of the I2C instance used.
 * \param   clkActSelect  It is the value which determines the type of clock
 *                        activity.
 *          clkActSelect can take values from the following enum
 *          - #i2cClkAct_t
 */
void I2CClockActivitySelect(uint32_t baseAddr, uint32_t clkActSelect);

/**
 * \brief  This API Enables a specific IRQ/DMA request source to generate an
 *         asynchronous wakeup signal. If the wakeup mechanism is not enabled
 *         then this API enables the wakeup mechanism before selecting the
 *         wakeup source. A wakeup is signalled to the local host if the
 *         corresponding event is captured by the core of the I2C controller.
 *
 * \param  baseAddr     It is the Memory address of the I2C instance used.
 * \param  wakeupEvent  It specifies for which event wakeup signal has to
 *                      enabled.
 *         wakeupEvent can take values from the following enum
 *         - #i2cWakeupEvt_t.
 *
 * \param  wakeupSrc   It specifies IRQ or DMA Transmit or DMA receive
 *                     request source to generate asynchronous wake up
 *                     signal.
 *         wakeupSrc can take values from the following enum
 *         - #i2cWakeupSrc_t.
 */
void I2CWakeupEnable(uint32_t baseAddr,
                     uint32_t wakeupEvent,
                     uint32_t wakeupSrc);

/**
 * \brief  This API Disables a specific IRQ/DMA request source to generate an
 *         asynchronous wakeup signal. If all the wakeup sources are disabled,
 *         then it disables the wakeup mechanism. A wakeup is signalled to the
 *         local host if the corresponding event is captured by the core of
 *         the I2C controller.
 *
 * \param  baseAddr     It is the Memory address of the I2C instance used.
 * \param  wakeupEvent  It specifies for which event wakeup signal has to
 *                      disabled.
 *         wakeupEvent  can take values from the following enum
 *         - #i2cWakeupEvt_t.
 *
 * \param  wakeupSrc    It specifies IRQ or DMA Transmit or DMA receive request
 *                      source to generate asynchronous wake up signal.
 *         wakeupSrc can take values from the following enum
 *         - #i2cWakeupSrc_t.
 */
void I2CWakeupDisable(uint32_t baseAddr,
                      uint32_t wakeupEvent,
                      uint32_t wakeupSrc);

/**
 * \brief   This API indicates the state of the reset in case of hardware reset,
 *          global reset or partial reset.
 *
 * \param   baseAddr  It is the Memory address of the I2C instance used.
 *
 * \retval  TRUE   If Reset is completed.
 * \retval  FALSE  If Internal module reset is ongoing.
 */
uint32_t I2CSystemStatus(uint32_t baseAddr);

/**
 * \brief  This function Transmits a byte from the I2C in Master mode.
 *
 * \param  baseAddr  Memory address of the I2C instance used.
 * \param  txData    Data byte that has to be transmitted from the I2C controller
 */
void I2CPutTxData(uint32_t baseAddr, uint8_t txData);

/**
 * \brief  This Receives a byte that has been sent to the I2C in Master mode.
 *
 * \param  baseAddr It is the Memory address of the I2C instance used.
 *
 * \retval rxData   The byte received from by the I2C in Master mode.
 */
uint8_t I2CGetRxData(uint32_t baseAddr);

/**
 * \brief   This API Enables the I2C free run mode.
 *
 * \param   baseAddr      It is the Memory address of the I2C instance used.
 * \param   enableFreeRun Value to control enabling/disabling the free run mode.
 */
void I2CFreeRunEnable(uint32_t baseAddr, uint32_t enableFreeRun);

/**
 * \brief   This API can be used to save the register context of I2C.
 *
 * \param   baseAddr Base address of I2C instance
 * \param   pCtx     Pointer to the structure where I2C register context need
 *                   to be saved.
 */
void I2CContextSave(uint32_t baseAddr, i2cCtx_t *pCtx);

/**
 * \brief   This API can be used to restore the register context of I2C
 *
 * \param   baseAddr  Base address of I2C instance
 * \param   pCtx      Pointer to the structure where I2C register context need
 *                    to be saved.
 */
void I2CContextRestore(uint32_t baseAddr, i2cCtx_t *pCtx);

/* ========================================================================== */
/*                   Deprecated Function Declarations                         */
/* ========================================================================== */

/**
 * \brief   This API determines whether Master is busy or not.
 *
 * \param   baseAddr   It is the Memory address of the I2C instance used.
 *
 * \retval  TRUE if bus is busy.
 * \retval  FALSE if bus is free.
 */
uint32_t I2CMasterBusy(uint32_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif
