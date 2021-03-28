/**
 * \file       pixcir_tsc.c
 *
 * \brief      This file contains pixcir capacitive touch screen driver 
 *             API's implementation.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "prcm.h"
#include "pinmux.h"
#include "pixcir_tsc.h"
#include "console_utils.h"
#include "gpio.h"
#include "chipdb.h"
#include "interrupt.h"
#include "i2c_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** /brief Capacitive touch screen pen interrupt GPIO instance */
#define CAP_TSC_GPIO_INST           (3U)
/** /brief Capacitive touch screen pen interrupt GPIO pin number */
#define CAP_TSC_GPIO_PIN_NUM        (22U)
/** /brief Capacitive touch screen pen interrupt number */
#define SYS_INT_GPIO_3_INT          (94U)

/** /brief Capacitive touch screen interface (I2C) instance number */
#define CAP_TSC_I2C_INST            (1U)
/** /brief Capacitive touch screen (I2C) slave device address */
#define CAP_TSC_I2C_ADDR            (0x5CU)
/** /brief I2C time-out value while interacting with capacitive touch screen */
#define CAP_TSC_I2C_TIMEOUT_VAL     (10000U)

/** /brief Capacitive touch screen base address of finger ID */
#define CAP_TSC_FID_BASE            (6U)
/** /brief Capacitive touch screen base address of X coordinate */
#define CAP_TSC_XPOS_BASE           (2U)
/** /brief Capacitive touch screen base address of Y coordinate */
#define CAP_TSC_YPOS_BASE           (4U)
/** /brief Capacitive touch screen base address of finger strength */
#define CAP_TSC_FSTREN_BASE         (27U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** /brief GPIO module base address */
uint32_t gpioBaseAddr = 0U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PIXCIRTscInit(void (*pIntrHandler)(uint32_t intrId, uint32_t cpuId, 
                                                            void* pUserParam))
{
    int32_t status = S_PASS;
	i2cUtilsTxRxParams_t i2cRxParams;
	uint8_t offset;
	uint8_t intrStatus;
	uint16_t pinNum = CAP_TSC_GPIO_PIN_NUM;
    
    intcIntrParams_t intrParams;
    
    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;

    /****************************** GPIO config ******************************/
    /* GPIO3 clock enable  */
    PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, CAP_TSC_GPIO_INST, 0);

    /* PinMux Configuration */
    status = PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, CAP_TSC_GPIO_INST, &pinNum);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
    }
	else
	{
		gpioBaseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, CAP_TSC_GPIO_INST);
		
		if(CHIPDB_INVALID_ADDRESS != gpioBaseAddr)
		{
			/* Enabling the GPIO module. */
			GPIOModuleEnable(gpioBaseAddr, TRUE);
			
			/* Configure Pin as an Input/Output Pin. */
			GPIODirModeSet(gpioBaseAddr, CAP_TSC_GPIO_PIN_NUM, GPIO_DIRECTION_INPUT);
			
			/* Enable Debouncing feature for the GPIO Pin. */
			GPIODebounceFuncEnable(gpioBaseAddr, CAP_TSC_GPIO_PIN_NUM, FALSE);
			
			/* Configure interrupt trigger type */
			GPIOIntTypeSet(gpioBaseAddr, CAP_TSC_GPIO_PIN_NUM, GPIO_INTR_MASK_LEVEL_LOW);
			
			/* Enable interrupt for the specified GPIO Pin. */
			GPIOPinIntEnable(gpioBaseAddr, 0, CAP_TSC_GPIO_PIN_NUM);
		}
		else
		{
			CONSOLEUtilsPrintf("\n Invalid module base address !\n");
		}
	}

    /************************ Interrupt config *******************************/
    /* Perform initialization of Interrupt controller */
	if(S_PASS == status)
	{
		status = INTCInit(FALSE);
	}
    
    /* Configure timer interrupt */
    intrParams.triggerType    = INTC_TRIG_LOW_LEVEL;
    intrParams.priority       = 0x10U;
    intrParams.pFnIntrHandler = pIntrHandler;
    intrParams.pUserParam     = 0U;
    intrParams.isIntrSecure   = FALSE;

	if(S_PASS == status)
	{
		status = INTCConfigIntr(SYS_INT_GPIO_3_INT, &intrParams, FALSE);
	}

    if(S_PASS != status)
    {
        CONSOLEUtilsPuts("Interrupt configuration failed for timer interrupt.\r\n");
    }
	else
	{
		/************************** I2C Initialize *******************************/
		I2CUtilsInit(CAP_TSC_I2C_INST, &i2cUtilsParams);
		
		/* Read the Interrupt status from EEPROM */
		i2cRxParams.slaveAddr = CAP_TSC_I2C_ADDR;
		i2cRxParams.pOffset = &offset;
		i2cRxParams.offsetSize = (uint8_t)1; /* 1 byte */
		i2cRxParams.bufLen = (uint8_t)sizeof(intrStatus) + 1;
		offset = 0x33U;
		intrStatus = 0x05U;
		i2cRxParams.pBuffer = &intrStatus;
		status = I2CUtilsWrite(CAP_TSC_I2C_INST, &i2cRxParams, 
											CAP_TSC_I2C_TIMEOUT_VAL);
		status = I2CUtilsRead(CAP_TSC_I2C_INST, &i2cRxParams, 
											CAP_TSC_I2C_TIMEOUT_VAL);
											
		offset = 0x34U;
		intrStatus = 0x0AU;
		status = I2CUtilsWrite(CAP_TSC_I2C_INST, &i2cRxParams, 
											CAP_TSC_I2C_TIMEOUT_VAL);
		status = I2CUtilsRead(CAP_TSC_I2C_INST, &i2cRxParams, 
											CAP_TSC_I2C_TIMEOUT_VAL);
	}
	   
    return status;
}

int32_t PIXCIRTscCalibrate(PIXCIRCalibType_t calibType)
{
    i2cUtilsTxRxParams_t i2cRxParams;
    uint8_t offset;
    uint8_t calibMode;
    int32_t status = E_FAIL;

    /* One-time total calibration */
    if(PIXCIR_CALIB_CAP_OFFSETS == (calibType & PIXCIR_CALIB_CAP_OFFSETS))
    {
        offset = 0x3AU;
        calibMode = 0x03U;

        i2cRxParams.slaveAddr = CAP_TSC_I2C_ADDR;
        i2cRxParams.pOffset = &offset;
        i2cRxParams.offsetSize = (uint8_t)1; /* 1 byte */
        i2cRxParams.bufLen = (uint8_t)1;
        i2cRxParams.pBuffer = &calibMode;
        status = I2CUtilsWrite(CAP_TSC_I2C_INST, &i2cRxParams, 
                                        CAP_TSC_I2C_TIMEOUT_VAL);
    }
    
    /* Border tracking calibration */
    if(PIXCIR_CALIB_ENV_VAR == (calibType & PIXCIR_CALIB_ENV_VAR))
    {
        /* TODO: */
    }
    
    return status;
}

int32_t PIXCIRGetTouchData(PIXCIRTouchData_t *pTouchData)
{
    i2cUtilsTxRxParams_t i2cRxParams;
    uint8_t offset = 0x0U;
    uint8_t rawData[32U];
    uint8_t i, j;
    PIXCIRDataPoint_t dataPoint;
    int32_t status = E_FAIL;
    
    /* Read the Board data from EEPROM */
    i2cRxParams.slaveAddr = CAP_TSC_I2C_ADDR;
    i2cRxParams.pOffset = &offset;
    i2cRxParams.offsetSize = (uint8_t)1; /* 1 byte */
    i2cRxParams.bufLen = (uint8_t)sizeof(rawData);
    i2cRxParams.pBuffer = rawData;
    status = I2CUtilsRead(CAP_TSC_I2C_INST, &i2cRxParams, 
                                        CAP_TSC_I2C_TIMEOUT_VAL);
										
	if(S_PASS == status)
	{
		/* LSB 3 bits indicate number of fingers touching */
		pTouchData->numFingers = (uint16_t)rawData[0] & 0x7U;
		
		/* Fill the data in user buffer */
		for(i = 0; i < pTouchData->numFingers; i++)
		{
			pTouchData->dataPoint[i].fingerId = rawData[CAP_TSC_FID_BASE + (i*5)];
			pTouchData->dataPoint[i].strength = rawData[CAP_TSC_FSTREN_BASE + i];
			pTouchData->dataPoint[i].xPos = 
								(rawData[CAP_TSC_XPOS_BASE + (i*5) + 1] << 8) + 
									rawData[CAP_TSC_XPOS_BASE + (i*5)];
			pTouchData->dataPoint[i].yPos = 
								(rawData[CAP_TSC_YPOS_BASE + (i*5) + 1] << 8) + 
									rawData[CAP_TSC_YPOS_BASE + (i*5)];
		}
		   
		/* Sort (selection sort) the touch points based on finger ID */
		for(i = 1; i < pTouchData->numFingers; ++i)
		{
			dataPoint.fingerId = pTouchData->dataPoint[i].fingerId;
			dataPoint.strength = pTouchData->dataPoint[i].strength;
			dataPoint.xPos = pTouchData->dataPoint[i].xPos;
			dataPoint.yPos = pTouchData->dataPoint[i].yPos;
			
			for(j = i; (j > 0 && pTouchData->dataPoint[j-1].fingerId > 
													dataPoint.fingerId); j--)
			{
				pTouchData->dataPoint[j].fingerId = pTouchData->dataPoint[j-1].fingerId;
				pTouchData->dataPoint[j].strength = pTouchData->dataPoint[j-1].strength;
				pTouchData->dataPoint[j].xPos = pTouchData->dataPoint[j-1].xPos;
				pTouchData->dataPoint[j].yPos = pTouchData->dataPoint[j-1].yPos;
			}
			
			 pTouchData->dataPoint[j].fingerId = dataPoint.fingerId;
			 pTouchData->dataPoint[j].strength = dataPoint.strength;
			 pTouchData->dataPoint[j].xPos = dataPoint.xPos;
			 pTouchData->dataPoint[j].yPos = dataPoint.yPos;
		}
		
		GPIOPinIntClear(gpioBaseAddr, 0, CAP_TSC_GPIO_PIN_NUM);
	}
	
    return status;
}

