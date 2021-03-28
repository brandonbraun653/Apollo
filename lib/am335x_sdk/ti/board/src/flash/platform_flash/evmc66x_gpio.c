/*
 * Copyright (c) 2010-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file   evmc66x_gpio.c
 *
 * \brief  This file contains the lower level functions to access GPIO
 *
 *****************************************************************************/

/************************
 * Include Files
 ************************/
#include "platform_internal.h"

#if (PLATFORM_GPIO_IN)

/**
 * \brief  This function performs different control operations on GPIO
 *
 * \param   gpioPortNumber [IN]     GPIO port number
 * \param   pinNum         [IN]     GPIO pin number
 * \param   ctrlCmd        [IN]     Command to indicate action to perform
 * \n                               Use below macros as input for 'ctrlCmd'
 * \n        GPIO_CTRL_SET_DIR       - Command to set GPIO pin direction
 * \n        GPIO_CTRL_SET_OUTPUT    - Command to set GPIO pin output
 * \n        GPIO_CTRL_CLEAR_OUTPUT  - Command to clear GPIO pin output
 * \n        GPIO_CTRL_READ_INPUT    - Command to read GPIO pin input
 * \n        GPIO_CTRL_SET_RE_INTR   - Command to set rising edge interrupt
 * \n        GPIO_CTRL_CLEAR_RE_INTR - Command to clear rising edge interrupt
 * \n        GPIO_CTRL_SET_FE_INTR   - Command to set falling edge interrupt
 * \n        GPIO_CTRL_CLEAR_FE_INTR - Command to clear falling edge interrupt
 *
 * \param   ctrlData       [IN/OUT] Data to be manipulated by the command
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
static GPIO_RET gpio_ctrl(uint8_t gpioPortNumber, uint8_t pinNum,
                          uint8_t ctrlCmd, void *ctrlData)
{
	GPIO_RET       retVal;
    uint8_t        bankIndex;
    uint8_t        bitPos;
    CSL_GpioHandle hGpio;
    GpioDirection  direction;

    retVal = GPIO_RET_OK;

    if(pinNum < GPIO_MAX_NUMBER)
    {
		hGpio = gpioGetRegBaseAddr(gpioPortNumber);
		if(hGpio != NULL)
		{
			bankIndex = pinNum / GPIO_PINS_PER_BANK;
			bitPos    = pinNum % GPIO_PINS_PER_BANK;

			switch(ctrlCmd)
			{
				/* Command to set GPIO pin direction */
                case GPIO_CTRL_SET_DIR:
                	 direction = *((GpioDirection*)ctrlData);
					 if	(direction == GPIO_IN)
					 {
					 	hGpio->BANK_REGISTERS[bankIndex].DIR |= 1 << bitPos;
					 }
					 else
					 {
						hGpio->BANK_REGISTERS[bankIndex].DIR &= ~(1 << bitPos);
					 }
                	 break;

				/* Command to set GPIO pin output */
                case GPIO_CTRL_SET_OUTPUT:
                	 hGpio->BANK_REGISTERS[bankIndex].SET_DATA = 1 << bitPos;
                	 break;

				/* Command to clear GPIO pin output */
                case GPIO_CTRL_CLEAR_OUTPUT:
                	 hGpio->BANK_REGISTERS[bankIndex].CLR_DATA = 1 << bitPos;
                	 break;

				/* Command to read GPIO pin input */
                case GPIO_CTRL_READ_INPUT:
                	 *(uint8_t*)ctrlData =
                	       CSL_FEXTR (hGpio->BANK_REGISTERS[bankIndex].IN_DATA,
                	                  bitPos, bitPos);
                	 break;

				/* Command to set rising edge interrupt */
                case GPIO_CTRL_SET_RE_INTR:
                	 CSL_FINSR (hGpio->BANK_REGISTERS[bankIndex].SET_RIS_TRIG,
                	            bitPos, bitPos, 1);
                	 break;

				/* Command to clear rising edge interrupt */
                case GPIO_CTRL_CLEAR_RE_INTR:
                	 hGpio->BANK_REGISTERS[bankIndex].CLR_RIS_TRIG |= 1 << pinNum;
                	 break;

				/* Command to set falling edge interrupt */
                case GPIO_CTRL_SET_FE_INTR:
                	 CSL_FINSR (hGpio->BANK_REGISTERS[bankIndex].SET_FAL_TRIG,
                	            bitPos, bitPos, 1);
                	 break;

				/* Command to clear falling edge interrupt */
                case GPIO_CTRL_CLEAR_FE_INTR:
                	 hGpio->BANK_REGISTERS[bankIndex].CLR_FAL_TRIG |=  1 << pinNum;
                	 break;

                default:
                	 retVal = GPIO_RET_FAIL;
                	 break;
			}
		}
		else
		{
			retVal = INVALID_GPIO_PORT;
		}
	}
	else
	{
		retVal = INVALID_GPIO_NUMBER;
	}

	return (retVal);

} //gpio_ctrl

/**
 * \brief  Returns base address of given GPIO port number.
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 *
 * \return CSL_GpioHandle\n
 *
 */
CSL_GpioHandle gpioGetRegBaseAddr(uint8_t gpioPortNumber)
{
	CSL_GpioHandle addr;

	switch(gpioPortNumber)
	{
		case GPIO_PORT_0:
			addr = (CSL_GpioHandle)CSL_GPIO_0_REGS;
			break;

		case GPIO_PORT_1:
			addr = (CSL_GpioHandle)CSL_GPIO_1_REGS;
			break;

		default :
			addr = NULL;
			break;
	}

	return (addr);

}  //gpioGetRegBaseAddr

/**
 * \brief  Initializes the GPIO peripheral
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 *
 */
GPIO_RET gpioInit(uint8_t gpioPortNumber)
{
	GPIO_RET    retVal;
    uint8_t     bankNum;
    uint8_t     pinNum;

	retVal = GPIO_RET_OK;

    if (gpioPortNumber <= GPIO_PORT_1)
    {
		/* Disable the GPIO global interrupts */
		for (bankNum = 0; bankNum < GPIO_MAX_BANKS; bankNum++)
		{
			gpioDisableGlobalInterrupt(gpioPortNumber, bankNum);
		}

	    /* Clear all falling edge trigger and rising edge trigger */
	    for (pinNum = 0; pinNum < GPIO_MAX_NUMBER; pinNum++)
	    {
            gpioClearFallingEdgeInterrupt(gpioPortNumber, pinNum);
            gpioClearRisingEdgeInterrupt(gpioPortNumber, pinNum);
        }
	}
	else
	{
		retVal = INVALID_GPIO_PORT;
	}

	return (retVal);

} //gpioInit

/**
 * \brief  This function configures the specified GPIO's direction
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 * \param   direction      [IN]    GPIO pin direction
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioSetDirection(uint8_t gpioPortNumber, uint8_t pinNum,
                          GpioDirection direction)
{
	GPIO_RET    retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_SET_DIR, &direction);

	return (retVal);

} //gpioSetDirection

/**
 * \brief  This function sets the specified GPIO's pin state to 1
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioSetOutput(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_SET_OUTPUT, NULL);

	return (retVal);

} //gpioSetOutput

/**
 * \brief  This function Clears the specified GPIO's pin state to 0
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioClearOutput(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_CLEAR_OUTPUT, NULL);

	return (retVal);

} //gpioClearOutput

/**
 * \brief  This function gets the specified GPIO's pin state
 *
 * The specified GPIO should be configured as input
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      uint32_t - Input state of GPIO if success
 * \n				- else GPIO status
 */
uint32_t gpioReadInput(uint8_t gpioPortNumber, uint8_t pinNum)
{
    uint8_t  inData = 0;
    uint32_t retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_READ_INPUT, &inData);
	if(GPIO_RET_OK == retVal)
	{
		if( ( inData & GPIO_HIGH ) == GPIO_HIGH )
		{
			retVal = GPIO_HIGH;
		}
		else
		{
			retVal = GPIO_LOW;
		}
	}

	return(retVal);

} //gpioReadInput

/**
 * \brief  This function Enables GPIO interrupts to CPU
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   bankNum        [IN]    GPIO bank number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO bank number
 */
GPIO_RET gpioEnableGlobalInterrupt(uint8_t gpioPortNumber, uint8_t bankNum)
{
	GPIO_RET       retVal;
	CSL_GpioHandle hGpio;

	retVal = GPIO_RET_OK;

	if(bankNum <= GPIO_MAX_BANKS)
	{
		hGpio = gpioGetRegBaseAddr(gpioPortNumber);
		if(hGpio != NULL)
		{
			CSL_GPIO_bankInterruptEnable(hGpio, bankNum);
		}
		else
		{
			retVal = INVALID_GPIO_PORT;
		}
	}
	else
	{
		retVal = INVALID_GPIO_NUMBER;
	}

	return (retVal);

} //gpioEnableGlobalInterrupt

/**
 * \brief  This function Disables GPIO interrupts to CPU
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   bankNum        [IN]    GPIO bank number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO bank number
 */
GPIO_RET gpioDisableGlobalInterrupt(uint8_t gpioPortNumber, uint8_t bankNum)
{
	GPIO_RET       retVal;
	CSL_GpioHandle hGpio;

	retVal = GPIO_RET_OK;

	if(bankNum <= GPIO_MAX_BANKS)
	{
		hGpio = gpioGetRegBaseAddr(gpioPortNumber);
		if(hGpio != NULL)
		{
			CSL_GPIO_bankInterruptDisable(hGpio, bankNum);
		}
		else
		{
			retVal = INVALID_GPIO_PORT;
		}
	}
	else
	{
		retVal = INVALID_GPIO_NUMBER;
	}

	return (retVal);

} //gpioDisableGlobalInterrupt

/**
 * \brief  This function sets specified GPIO's rising edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioSetRisingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_SET_RE_INTR, NULL);

	return (retVal);

} //gpioSetRisingEdgeInterrupt

/**
 * \brief  This function clears specified GPIO's rising edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioClearRisingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_CLEAR_RE_INTR, NULL);

	return (retVal);

} //gpioClearRisingEdgeInterrupt

/**
 * \brief  This function sets specified GPIO's falling edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioSetFallingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_SET_FE_INTR, NULL);

	return (retVal);

} //gpioSetFallingEdgeInterrupt

/**
 * \brief  This function clears specified GPIO's falling edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioClearFallingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum)
{
	GPIO_RET retVal;

    retVal = gpio_ctrl(gpioPortNumber, pinNum, GPIO_CTRL_CLEAR_FE_INTR, NULL);

	return (retVal);
}

#endif /* #if PLATFORM_GPIO_IN */

/* Nothing past this point */
