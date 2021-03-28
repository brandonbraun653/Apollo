/*
 * \file     delay_utils.h
 *
 * \brief    This file contains prototypes of utility functionalities like delay
 *           and sleep. These APIs are platform independent and the 
 *           definitions/implementations are specific to the platform.
 *
 *           Note: Some of the functions in this file need timer to be 
 *           initialized as pre-requisite (by calling the API #TIMEUtilsInit()). 
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

#ifndef DELAY_UTILS_H_
#define DELAY_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* The delay API is deprecated. */
#define delay DELAYMsec 

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Structures and Enums                              */
/* ========================================================================== */

/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */

/**
 * \brief   This API delays the next statement execution for given micro seconds
 *          (minimum).
 *
 * Note1: The implementation of this API will be a tight loop, so exercise caution
 *        in calling this API with higher value.
 *
 * Note2: The clock for free running timer is assumed to be of the order of Mhz
 *        or higher, if this condition is not met the delay will be more than 
 *        requested.
 *
 * Note3: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *        API.
 *
 * \param  usec   Delay period in micro seconds.
 *
 * \retval S_PASS  Requested delay has elapsed
 * \retval E_NOT_INITIALIZED  #TIMEUtilsInit() has not been called before 
 *                            calling this API.
 **/
int32_t DELAYUsec(uint32_t usec);

/**
 * \brief   This API delays the next statement execution for given milli seconds.
 *          (minimum)
 *
 * Note1: The implementation of this API will be a tight loop, so exercise caution
 *        in calling this API with higher value.
 *
 * Note2: The clock for free running timer is assumed to be of the order of khz
 *        or higher, if this condition is not met the delay will be more than 
 *        requested.
 *
 * Note3: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *        API.
 *
 * \param  msec  Delay period in milli seconds.
 *
 * \retval S_PASS  Requested delay has elapsed
 * \retval E_NOT_INITIALIZED  #TIMEUtilsInit() has not been called before 
 *                            calling this API.
 **/
int32_t DELAYMsec(uint32_t msec);

/**
 * \brief   This API causes the CPU to sleep (CPU clock gate) for given
 *          milli seconds (minimum). If an interrupt occurs during the sleep
 *          period the CPU will wakeup and the sleep call will be returned 
 *          with remaining time.
 *
 * Note1: OS PORT: The implementation of this API will be based on tick timer. 
 *          In OS context the CPU can be switched to execute other tasks.
 *
 * Note2: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *        API.
 *
 * \param   msec   Sleep period in milli seconds.
 *
 * \retval  S_PASS - If slept for full time (passed in parameter)
 * \retval  Pending sleep time, if slept only for fraction of the time 
 *          (passed in parameter)
 **/
int32_t SLEEPMsec(uint32_t msec);

/**
 * \brief   This API causes the CPU to sleep (CPU clock gate) for given seconds
 *          (minimum). If an interrupt occurs during the sleep period the CPU
 *          will wakeup, but if the expected sleep time has not elapsed even after
 *          returning from interrupt the CPU will enter sleep again for the
 *          remaining amount of time.
 *
 * Note1:   With 32 bits, ~49days can be represented in milli sec. Since  
 *          typically the delay will be requested for few seconds, the below
 *          function calls SLEEPMsec multiple times to achieve its purpose. 
 *          This may introduce jitter and there will be little increase in 
 *          sleep time.
 *
 * Note2: Timer has to be initialized (#TIMEUtilsInit) as pre-requisite to call this
 *        API.
 *
 * Note3: OS PORT: The implementation of this API will be based on tick. In OS
 *          context the CPU can be switched to execute other tasks.
 *
 * \param   sec   Sleep period in seconds.
 *
 * \retval  S_PASS - If slept for full time (passed in parameter)
 * \retval  Pending sleep time, if slept only for fraction of the time 
 *          (passed in parameter)
 *
 **/
int32_t SLEEPSec(uint32_t sec);

/* ========================================================================== */
/*                           DEPRECATED MACROS                                */
/* ========================================================================== */

/* The delay API is deprecated. */
#define delay DELAYMsec 

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DELAY_H_ */
