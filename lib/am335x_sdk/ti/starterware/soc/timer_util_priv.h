/*
 * \file     timer_util_priv.h
 *
 * \brief    This file contains prototypes of timer utility functions which 
 *           are IP/SoC specific. The implementations will be kept in 
 *           corresponding SoC folder.
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

#ifndef TIMER_UTIL_PRIV_H_
#define TIMER_UTIL_PRIV_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */

/**
 * \brief  This API initializes the 64-bit free running timer.
 *
 * \param  pFreeRunTimer   Pointer to timer object. Refer #timeUtilsObj_t
 *
 * \retval S_PASS Timer initialization succeeded
 * \retval E_FAIL Timer initialization failed
 *
 **/
int32_t TIMERUtilFreeRunInit(timeUtilsObj_t *pFreeRunTimer);

/**
 * \brief  This API sets the time-stamp in the free running timer.
 *
 * \param  nanoSec Time-stamp to be set in nano seconds.
 **/
void TIMERUtilSetTimeStamp(uint64_t nanoSec);

/**
 * \brief  This API gets the time-stamp from the free running timer.
 *
 * \retval Time-stamp in nano seconds.
 **/
uint64_t TIMERUtilGetTimeStamp(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TIMER_UTIL_PRIV_H_ */