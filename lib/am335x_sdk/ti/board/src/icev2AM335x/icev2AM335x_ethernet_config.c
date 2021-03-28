/**
 *   @file  icev2AM335x_ethernet_config.c
 *
 *   @brief
 *      This file contains the ICSS EMAC PHY configurations for icev2AM335x board
 *
 *      Board_icssEthConfig: This API configures 10/100 PHYs connected to two
 *      ICSS ports. Several configurations are needed for normal operation of
 *      the ICSS Ethernet PHYs which will be taken care by this function.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
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

#include "board_internal.h"
#include "board_cfg.h"

#include <ti/starterware/include/device.h>
#include <ti/starterware/include/hw/hw_icss_mii_mdio.h>

/* Structure holding gpio pin configuration parameters. */
typedef struct gpioPinCfg
{
    uint32_t dir;
    /**< pin direction . */
    uint32_t debounceEnable;
    /**< Enable/disable debounce feature. */
    uint32_t debounceTime;
    /**< deboune timing control. */
    uint32_t intrEnable;
    /**< Interrupt enable/disable. */
    uint32_t intrType;
    /**< Interrupt type edge or level . */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t wakeEnable;
    /**< Wake up enable/disable control. */
    uint32_t wakeLine;
    /**< Wakeup line number. */
}gpioPinCfg_t;

/* Structure holding the GPIO pin object data structure. */
typedef struct gpioPinObj
{
    uint32_t     pinNum;
    /**< GPIO pin number. */
    uint32_t     instNum;
    /**< GPIO instance number. */
    uint32_t     instAddr;
    /**< GPIO instance address. */
    gpioPinCfg_t pinCfg;
    /**< GPIO pin configuration structure.*/
}gpioPinObj_t;


/* Global structure holding the default GPIO IP configuration values. */
gpioPinObj_t gpioPinObjDefault =
{
    0U,  /* pin number */
    0U,  /* Instance number */
    0U,  /* Instance Address */
    {
        GPIO_DIR_OUTPUT, /* dir */
        FALSE,  /* debounceEnable */
        0U,     /* debounceTime */
        FALSE,  /* intrEnable */
        0U,     /* intrType */
        0U,     /* intrLine */
        FALSE,  /* wakeEnable */
        0U,     /* wakeLine */
    }
};



/**
 * \brief  Local Delay function
 *
 * \return  none
 */
static void Board_delay(uint32_t ix);/* for misra warning */
static void Board_delay(uint32_t ix)
{
    while (ix--) {
        asm("   NOP");
    }
}

/**
 * \brief Wrapper for GPIO pin configuration
            Such as direction, debounce, wakeup, interrupt.
 *
 * \return  none
 */
static void Board_GPIOPinConfig(uint32_t baseAddr, uint32_t pinNum, gpioPinCfg_t *pGpioPinConfig); /* for misra warning */
static void Board_GPIOPinConfig(uint32_t baseAddr, uint32_t pinNum, gpioPinCfg_t *pGpioPinConfig)
{
    /* Configure Pin as an Input/Output Pin. */
    GPIODirModeSet(baseAddr, pinNum, pGpioPinConfig->dir);

    /* Enable Debouncing feature for the GPIO Pin. */
    GPIODebounceFuncControl(baseAddr, pinNum, GPIO_DEBOUNCE_FUNC_ENABLE);

    if(TRUE == pGpioPinConfig->debounceEnable)
    {
        /*
         * Configure the Debouncing Time for all the input pins of
         * the selected GPIO instance.
         */
        GPIODebounceTimeConfig(baseAddr, pGpioPinConfig->debounceTime);
    }

    if(FALSE == pGpioPinConfig->intrEnable)
    {
        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /*
         * Configure interrupt generation on detection of a logic HIGH or
         * LOW levels or a rising or a falling edge.
         */
        GPIOIntTypeSet(baseAddr, pinNum, pGpioPinConfig->intrType);

        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }

    if(FALSE == pGpioPinConfig->wakeEnable)
    {
        /* Enable wakeup generation for GPIO Module */
        GPIOWakeupGlobalDisable(baseAddr);

        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
}

/**
 * \brief Initializes GPIO instance as specified by object passed in.
 *
 * \return  none
 */
static void Board_initGPIO(gpioPinObj_t *pGpioObj);  /* for misra warning */
static void Board_initGPIO(gpioPinObj_t *pGpioObj)
{
   /* Enabling the GPIO module. */
    GPIOModuleEnable(pGpioObj->instAddr);

    /* GPIO pin characteristics configuration */
    Board_GPIOPinConfig(pGpioObj->instAddr, pGpioObj->pinNum, &pGpioObj->pinCfg);
}

/**
 * \brief  Resets the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void Board_phyReset(void);  /* for misra warning */
static void Board_phyReset(void)
{
    gpioPinObj_t gpioPhyReset = gpioPinObjDefault;

    gpioPhyReset.instAddr = SOC_GPIO_2_REGS;
    gpioPhyReset.instNum = 2;
    gpioPhyReset.pinNum = 5;

    Board_initGPIO( &gpioPhyReset);
    GPIOPinWrite(gpioPhyReset.instAddr, gpioPhyReset.pinNum ,0);
    Board_delay(3000);
    GPIOPinWrite(gpioPhyReset.instAddr, gpioPhyReset.pinNum ,1);
    
}


/**
 * \brief   MDIO peripheral initialization. Enables MDIO state machine.
 *
 * \return  none
 */
static void Board_mdioInit(void);  /* for misra warning */
static void Board_mdioInit(void)
{
    uint32_t temp32 = 0;
    HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_CONTROL) = 0x4000009F;

    // PHY1 configure FD in parallel detect mode
    while(HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS0) & (1<<31));
    HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS0) = 0x00 |\
            (1<<31) |\
            (0<<30) |\
            (0<<29) |\
            (0xA<<21) |\
            ((BOARD_ICSS_EMAC_PORT0_PHY_ADDR)<<16) |\
            (0x0<<0);
    while((temp32 = HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS0)) & (1<<31));
    temp32 |= 1<<5;    // set Force Full-Duplex while working with link partner in forced 100B-TX
    temp32 &= 0xFFFF;
    HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS0) = 0x00 |\
            (1<<31) |\
            (1<<30) |\
            (0<<29) |\
            (0xA<<21) |\
            ((BOARD_ICSS_EMAC_PORT0_PHY_ADDR)<<16) |\
            (temp32<<0);

    // PHY2 configure FD in parallel detect mode
    while(HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS1) & (1<<31));
    HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS1) = 0x00 |\
            (1<<31) |\
            (0<<30) |\
            (0<<29) |\
            (0xA<<21) |\
            ((BOARD_ICSS_EMAC_PORT1_PHY_ADDR)<<16) |\
            (0x0<<0);
    while((temp32 = HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS1)) & (1<<31));
    temp32 |= 1<<5;    // set Force Full-Duplex while working with link partner in forced 100B-TX
    temp32 &= 0xFFFF;
    HWREG(SOC_PRU_ICSS_MII_MDIO_REG + HW_ICSS_MII_MDIO_USERACCESS1) = 0x00 |\
            (1<<31) |\
            (1<<30) |\
            (0<<29) |\
            (0xA<<21) |\
            ((BOARD_ICSS_EMAC_PORT1_PHY_ADDR)<<16) |\
            (temp32<<0);
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
Board_STATUS Board_icssEthConfig(void);  /* for misra warning */
Board_STATUS Board_icssEthConfig(void)
{
    gpioPinObj_t gpioMii2Mux = gpioPinObjDefault;

    gpioMii2Mux.instAddr = SOC_GPIO_3_REGS;
    gpioMii2Mux.instNum = 3;
    gpioMii2Mux.pinNum =  4;
    Board_initGPIO(&gpioMii2Mux);
    GPIOPinWrite(gpioMii2Mux.instAddr, gpioMii2Mux.pinNum ,GPIO_PIN_HIGH);
    Board_mdioInit();
    Board_phyReset();
    

    return BOARD_SOK;
}

