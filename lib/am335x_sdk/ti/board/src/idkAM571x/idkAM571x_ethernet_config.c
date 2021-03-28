/**
 *   @file  idkAM571x_ethernet_config.c
 *
 *   @brief
 *      This file contains the ICSS EMAC PHY configurations for idkAM571x board
 *
 *      Board_icssEthConfig: This API configures 10/100 PHYs connected to two
 *      ICSS ports. Several configurations are needed for normal operation of
 *      the ICSS Ethernet PHYs which will be taken care by this function.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2018, Texas Instruments, Inc.
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
 *  \par
*/

#include <ti/csl/soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/soc/am571x/src/cslr_soc.h>
#include <ti/csl/cslr_icss.h>

#include "board_internal.h"
#include "board_cfg.h"

#define BOARD_MAX_ICSS_EMAC_PORTS     4

#define BOARD_SWITCH_DEFAULT_MDIOBUSFREQ      (2200000u)
#define BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ    (200000000u)

/* Structure holding gpio pin configuration parameters. */
typedef struct gpioPinCfg {
    uint32_t instance;      /**< GPIO instance number. */
    uint32_t pin;           /**< GPIO pin number. */
    uint32_t pinMux;
    uint32_t baseAddr;

} gpioPinCfg_t;


static gpioPinCfg_t phyResetInfo[BOARD_MAX_ICSS_EMAC_PORTS];
static gpioPinCfg_t phyIntInfo[BOARD_MAX_ICSS_EMAC_PORTS];


/**
 * \brief  Local Delay function
 *
 * \return  none
 */
static void Board_delay(uint32_t delay); /* for misra warning */
static void Board_delay(uint32_t delay)
{
    volatile uint32_t del = delay;
    while (del--) {}
}


/**
 * \brief  Resets the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void Board_phyReset(void); /* for misra warning */
static void Board_phyReset(void)
{
    int32_t i =0;
    int32_t startPort = 0;

    for(i=startPort;i<BOARD_MAX_ICSS_EMAC_PORTS-2U;i++)
    {
        /* Do GPIO pin mux for M4 only*/
#ifdef __TI_ARM_V7M4__
        HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + phyResetInfo[i].pinMux) = (0x20000 | 0x0E);
#endif
        GPIOModuleEnable(phyResetInfo[i].baseAddr);
        GPIODirModeSet(phyResetInfo[i].baseAddr, phyResetInfo[i].pin, GPIO_DIR_OUTPUT);


        GPIOPinWrite(phyResetInfo[i].baseAddr, phyResetInfo[i].pin, GPIO_PIN_HIGH);
        GPIOPinWrite(phyResetInfo[i].baseAddr, phyResetInfo[i].pin, GPIO_PIN_LOW);
        Board_delay(1000);
        GPIOPinWrite(phyResetInfo[i].baseAddr, phyResetInfo[i].pin, GPIO_PIN_HIGH);
        Board_delay(1000);
    }

}


/**
 * \brief  Configures  ICSS ethernet PHY  Interrupt pins configured as GPIO input in order to 
             disable the TLK105 phy powerdown
 *
 * \return  none
 */
static void Board_phyIntConfig(void); /* for misra warning */
static void Board_phyIntConfig(void)
{
  int32_t i =0;
  int32_t startPort=0;

    for(i=startPort;i<BOARD_MAX_ICSS_EMAC_PORTS;i++)
    {
#ifdef __TI_ARM_V7M4__
        HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + phyIntInfo[i].pinMux) = (0x20000 | 0x0E);
#endif
        GPIOModuleEnable(phyIntInfo[i].baseAddr);
        GPIODirModeSet(phyIntInfo[i].baseAddr, phyIntInfo[i].pin, GPIO_DIR_INPUT);
    }
}

/**
 * \brief   PHY setup routine for  ICSS  Ethernet PHYs.
 *     Setting the GPIOs for PHY reset, routing ICSS signals to PHYs,
 *     PHY interrupt lines.
 *
 * \return  none
 */
static void Board_phySetup(void); /* for misra warning */
static void Board_phySetup(void)
{
    //GPIO_PRU1_ETH_RESETn
    phyResetInfo[0].instance=5; //MCASP1_AXR6 - GPIO5_8
    phyResetInfo[0].pin=8;
    phyResetInfo[0].pinMux=  CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR6;
    phyResetInfo[0].baseAddr=SOC_GPIO5_BASE;

    //GPIO_PRU2_ETH_RESETn
    phyResetInfo[1].instance=5; //MCASP1_AXR7 - GPIO5_9
    phyResetInfo[1].pin=9;
    phyResetInfo[1].pinMux= CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR7;
    phyResetInfo[1].baseAddr=SOC_GPIO5_BASE;

    //PRU1_ETH0_INTn
     phyIntInfo[0].instance=3; //VIN2A_CLK0 - GPIO3_28 - Input
     phyIntInfo[0].pin=28;
     phyIntInfo[0].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_CLK0;
     phyIntInfo[0].baseAddr=CSL_MPU_GPIO3_REGS;
        
      //PRU1_ETH1_INTn
     phyIntInfo[1].instance=3; //VIN2A_DE0- GPIO3_29 - Input
     phyIntInfo[1].pin=29;
     phyIntInfo[1].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_DE0;
     phyIntInfo[1].baseAddr=CSL_MPU_GPIO3_REGS;

     //PRU2_ETH0_INTn
     phyIntInfo[2].instance=3; //VIN2A_FLD0- GPIO3_30 - Input
     phyIntInfo[2].pin=30;
     phyIntInfo[2].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_FLD0;
     phyIntInfo[2].baseAddr=CSL_MPU_GPIO3_REGS;
     
     //PRU2_ETH1_INTn
     phyIntInfo[3].instance=3; //VIN2A_HSYNC0- GPIO3_31 - Input
     phyIntInfo[3].pin=31;
     phyIntInfo[3].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_HSYNC0;
     phyIntInfo[3].baseAddr=CSL_MPU_GPIO3_REGS;

    Board_phyReset();

    Board_phyIntConfig();

}

/**
 * \brief   Clock setup for PRU ETH0 and ETH1
 *     This configures the two CDCE913 for 25MHz operation
 *
 * \return  none
 */
Board_STATUS Board_pruEthClockConfig()
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction transaction;
    int16_t transferStatus;
    I2C_Handle h1, i2c2Handle;
    uint32_t i2c2SDA, i2c2SCL;
    uint8_t out_buff[2] = {0x85, 0x00};
    I2C_Params i2cParams;
    int i;
    uint8_t flag = 0;

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }
    if (ret != BOARD_SOK)
        return ret;

    h1 = Board_obj.i2cHandle;

    /* Configure CDCE913 on I2C1 */
    I2C_transactionInit(&transaction);
    transaction.arg = NULL;
    transaction.nextPtr = NULL;
    transaction.readBuf = NULL;
    transaction.readCount = 0;
    transaction.slaveAddress = BOARD_I2C_CDCE913_ADDR;
    transaction.writeBuf = (uint8_t *)&out_buff[0];
    transaction.writeCount = 2;
    transferStatus = I2C_transfer(h1, &transaction);

    /* If CDCE913 on U23 write fails, record ret value but still attempt U25 */
    if(I2C_STS_SUCCESS != transferStatus)
        ret = BOARD_I2C_TRANSFER_FAIL;

    /* Configure pinmux for I2C2. Default MUX is configured for HDMI.
     * Direct write to MUX is safe given no DDR or delay values are written
     * and pins are not used.
     */
    i2c2SDA = HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SDA);
    i2c2SCL = HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SCL);
    HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SDA) &= 0xFFFFFFF0;
    HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SCL) &= 0xFFFFFFF0;

    /* Board i2c usage does not depend on interrupts */
    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        /* Check if interrupt set to true. Change it to false and raise a flag
            Note that number of i2c instances will not exceed 8 */
        if (((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr == true)
        {
            flag |= (1<<i);
            ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
        }
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    /* Temporary handle to I2C2 */
    i2c2Handle = I2C_open(BOARD_I2C_CDCE913_U25_INSTANCE, &i2cParams);
    if (i2c2Handle == NULL)
    {
        ret = BOARD_I2C_OPEN_FAIL; 
        return ret;
    }

    /* Configure CDCE913 on I2C2 */
    transaction.arg = NULL;
    transaction.nextPtr = NULL;
    transaction.readBuf = NULL;
    transaction.readCount = 0;
    transaction.slaveAddress = BOARD_I2C_CDCE913_ADDR;
    transaction.writeBuf = (uint8_t *)&out_buff[0];
    transaction.writeCount = 2;
    transferStatus = I2C_transfer(i2c2Handle, &transaction);

    if(I2C_STS_SUCCESS != transferStatus)
        ret = BOARD_I2C_TRANSFER_FAIL;

    I2C_close(i2c2Handle);

    /* Restore the original I2C_config table */
    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        if (flag & (1<<i))
            ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = true;
    }

    /* Revert pinmux to defaults */
    HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SDA) = i2c2SDA;
    HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + CSL_CONTROL_CORE_PAD_IO_PAD_I2C2_SCL) = i2c2SCL;

    return ret;
}

/**
 * \brief   MDIO peripheral initialization. Enables MDIO state machine.
 *
 * \return  none
 */
static void Board_mdioInit(void); /* for misra warning */
static void Board_mdioInit(void)
{
    CSL_MDIO_init(CSL_MPU_PRUSS1_U_MII_MDIO_REGS,
                                BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
                                BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);

    CSL_MDIO_init(CSL_MPU_PRUSS2_U_MII_MDIO_REGS,
                                BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
                                BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);
}

/**
 * \brief  Board specific configurations for ICSS  Ethernet PHYs
 *
 *  This function takes care of making several board level configurations
 *  required for ICSS EMAC PHY as listed below.
 *   - MDIO initialization
 *   - Setting the GPIOs for PHY reset, routing ICSS signals to PHYs,
 *     PHY interrupt lines.
 *   - Resetting the PHYs for proper address latching

 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void);
Board_STATUS Board_icssEthConfig(void)
{
    Board_pruEthClockConfig();
    /* MDIO initialization */
     Board_mdioInit();
    /* ICSS EMAC PHY setup */
     Board_phySetup();
    
    return BOARD_SOK;
}

