/**
 * \file   board_am43xx.h
 *
 * \brief  This file provides interfaces for AM43xx specific board information,
 * including functions to get board revisions etc.
 *
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef BOARD_AM43XX_
#define BOARD_AM43XX_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <board.h>


#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  Initialize the AM43xx based board.
 *
 *  \param  pInitPrms   Board Initialization parameters.
 *                      Parameter pInitPrms is of type #boardInitParams_t
 *
 *  \retval S_PASS      On success
 */
int32_t BoardAm43xxInit(const boardInitParams_t *pInitPrms);

/**
 *  \brief  Probes returns board ID for the AM43xx based board.
 *
 *  \retval Board_ID        On success
 *  \retval BOARD_UNKNOWN   On failure, or if board ID is not known.
 */
boardId_t BoardGetIdAm43xx(void);

/**
 *  \brief  Returns the base board revision for the AM43xx based board.
 *
 *  \retval Base_board_revision     On success, returns the base board revision.
 *                                  Based on the type of board, the revision
 *                                  value returned needs to be interpreted.
 *  \retval BOARD_REV_UNKNOWN       On failure, or if board rev ID is not known.
 */
uint32_t BoardGetBaseBoardRevAm43xx(void);

/**
 *  \brief  Function to get the name of the base board revision in printable
 *          string.
 *
 *  \retval Board_rev_string    Returns a const pointer to the string. If the
 *                              board revision is not known, then it returns the
 *                              string as "UNKNOWN".
 */
const char * BoardGetBaseBoardRevNameAm43xx(void);

/**
 *  \brief  Returns the add-on or daughter card board revision for the AM43xx
 *          based board.
 *
 *  \retval DC_Revision     On success, returns the add-on or daughter card
 *                          revision. Based on the type of board, the revision
 *                          value returned needs to be interpreted.
 */
uint32_t BoardGetDcRevAm43xx(void);

/**
 *  \brief  Function to get the name of the daughter card revision in printable
 *          string for the AM43xx based board.
 *
 *  \retval Board_dcrev_string  Returns a const pointer to the string. If the
 *                              board daughter card revision is not known, then
 *                              it returns the string as "UNKNOWN".
 */
const char * BoardGetDcRevNameAm43xx(void);

/**
 *  \brief  Returns I2C data for the AM43xx based board.
 *
 *  \retval Board_I2C_Data      Board I2C data on success
 *  \retval NULL                On Failure
 */
const boardI2cData_t * BoardGetI2cDataAm43xx(void);

/**
 *  \brief  Returns board specific data for the AM43xx based board.
 *
 *  \retval Board_I2C_Data      Board data on success
 *  \retval NULL                On Failure
 */
const boardData_t * BoardGetDataAm43xx(void);

/**
 *  \brief  Perform Power On for the provided device through GPIO or I2C IO
 *          expander for the AM43xx based board. If Power On is not needed, this
 *          function returns success without reporting error.
 *
 *  \param  devId        Device ID to power-on.
 *  \param  devInstId    Device instance ID. Used when multiple devices are
 *                       present in a board.
 *  \param  powerOn      TRUE - power on, FALSE - power down
 *
 *  \retval S_PASS      On success
 */
int32_t BoardPowerOnDeviceAm43xx(uint32_t devId,
                                 uint32_t devInstId,
                                 uint32_t powerOn);

#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif  /* #ifndef BOARD_AM43XX_ */
