/**
 * \file   pixcir_tsc.h
 *
 * \brief  This file contains API's interfaces to initialize and use the PIXCIR 
 *         capacitive touch screen.
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

#ifndef PIXCIR_TSC_H_
#define PIXCIR_TSC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Number of fingers - max number of touch that can be reported by the 
           touch controller */
#define TSC_NO_OF_FINGERS                        (5U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enum defining the calibration types for touch screen. */
typedef enum PIXCIRCalibType
{
    PIXCIR_CALIB_MECH_ASSEMBLY = 1,
    /**< Calibrate the touch screen to correct the error due to mechanical 
         alignment with the LCD. */
    PIXCIR_CALIB_CAP_OFFSETS = 2,
    /**< Calibrate the touch screen to correct the error due to capacitance 
         offsets. This calibration need to be done only once before the product 
         is packaged. */    
    PIXCIR_CALIB_ENV_VAR = 4,
    /**< Calibrate the touch screen to correct the error due to environmental 
         variations like temperature & humidity.  */
    PIXCIR_CALIB_DRIFT_COMP = 8
    /**< Calibrate the touch screen to correct the error due to time (Ageing)*/
}PIXCIRCalibType_t;

/** \brief Enum defining the low power modes of PIXCIR touch controller. */
typedef enum PIXCIRLowPowerMode
{
    PIXCIR_LOW_POWER_ACTIVE_MODE = 0,
    /**< Active mode, no power saving in this mode. */
    PIXCIR_LOW_POWER_IDLE_MODE,
    /**< Idle mode - shallow sleep mode with little saving in power and less 
         wakeup latency. Clock will run at lower rate.  */
    PIXCIR_LOW_POWER_SLEEP_MODE
    /**< Sleep mode - deep sleep mode with high saving in power and high 
         wakeup latency. Clock will be gated.  */
}PIXCIRLowPowerMode_t;

/** \brief Structure defining the configuration parameters of the touch screen 
          controller. */
typedef struct PIXCIRConfigVal
{
    uint8_t idleDelayTime;
    /**< Time for which if no touch is detected the controller will enter 
         idle mode. */
    uint8_t intrPulsewidth;
    /**< Width of the interrupt pulse. */
    uint8_t numSamples;
    /**< Number of samples to be read, from which the median value will be 
         calculated and reported. */    
    uint8_t fingerSize;
    /**< Size of the finger. */

}PIXCIRConfigVal_t;

/** \brief Structure defining the properties of touch point. */
typedef struct
{
    uint8_t fingerId;
    /**< Finger id of the touch report. */
    uint8_t strength;
    /**< Amount of pressure detected while the touch is detected. */
    uint16_t xPos;
    /**< x-coordinate. */
    uint16_t yPos;
    /**< y-coordinate. */
}PIXCIRDataPoint_t;

/** \brief Touch report from touch screen. */
typedef struct PIXCIRTouchData
{
    uint8_t numFingers;
    /**< Number of valid touch data (fingers). */
    PIXCIRDataPoint_t dataPoint[TSC_NO_OF_FINGERS];
    /**< Touch report from capacitive touch screen giving coordinates of all 
         the fingers detected. #PIXCIRDataPoint_t */
}PIXCIRTouchData_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initialize the pixcir touch screen controller. The touch screen 
 *          controller will be reset and interrupts will be enabled from touch 
 *          controller. The cpu interacts with the touch controller via I2C 
 *          interface.
 *
 * \param  pIntrHandler Touch interrupt handler. Set an event or read touch 
 *                      coordinates in call back function.
 * \retval S_PASS   Touch controller initialization is completed successfully.
 * \retval E_FAIL   Touch controller init failed.
 **/
int32_t PIXCIRTscInit(void (*pIntrHandler)(uint32_t intrId, uint32_t cpuId, 
                                                            void* pUserParam));

/**
 * \brief  Configure the pixcir touch screen controller for various correction 
 *         factors as defined in #PIXCIRConfigVal_t.
 *
 * \param  pConfigVal   Touch controller configuration values.
 *                      #PIXCIRConfigVal_t
 *
 * \retval S_PASS   Touch controller is configured successfully.
 * \retval E_FAIL   Touch controller configuration failed.
 **/
int32_t PIXCIRTscConfig(PIXCIRConfigVal_t *pConfigVal);

/**
 * \brief  Calibrate the touch screen. The calibration is of different types 
 *         which is indicated by the parameter.
 *
 * \param  calibType   TCalibration type. #PIXCIRCalibType_t
 *
 * \retval S_PASS   Touch controller is calibrated successfully.
 * \retval E_FAIL   Touch controller calibration failed.
 * \retval E_INVALID_PARAM   Parameter passed is invalid.
 **/
int32_t PIXCIRTscCalibrate(PIXCIRCalibType_t calibType);

/**
 * \brief  This API gets the touch data (#PIXCIRTouchData_t)
 *
 * \param  pTouchData  Pointer where touch data can be stored. 
 *                     #PIXCIRTouchData_t
 *
 * \retval S_PASS   Data read successfully and pTouchData contains valid data.
 * \retval E_FAIL   Data read failed and pTouchData has invalid data. 
 *                  #PIXCIRTouchData_t
 **/
int32_t PIXCIRGetTouchData(PIXCIRTouchData_t *pTouchData);

/**
 * \brief  Configure pixcir to go to low power mode forcefully. Wakeup is 
 *         automatic on a touch detection.
 *
 * \param  lpMode   Low power mode type. #PIXCIRLowPowerMode_t
 *
 * \retval S_PASS   pixcir controller is configured to low power mode
 * \retval E_FAIL   Low power mode configuration failed
 **/
int32_t PIXCIREnterLowPowerMode(PIXCIRLowPowerMode_t lpMode);

#ifdef __cplusplus
}
#endif

#endif /* PIXCIR_TSC_H_ */
