/**
 * \file   cap_tsc.c
 *
 * \brief  Example application which has test cases for capacitive touch screen.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "console_utils.h"
#include "pixcir_tsc.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

PIXCIRTouchData_t TouchData;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Touch screen pen interrupt handler. The touch coordinates will be 
 *          read and reported to the application.
 *
 * \param  intrId Touch pen interrupt number.
 * \param  cpuId  CPU core ID.
 * \param  pUserParam Optional user parameter.
 *
 **/
void TscIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = E_FAIL;

    status = BOARDInit(NULL);
        
    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare Capacitive Touch screen Application!!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
	if(S_PASS == status)
	{
		SOCPrintInfo();
		BOARDPrintInfo();
		
		status = PIXCIRTscInit(&TscIsr);
	}
	
	if(E_FAIL == status)
	{
		CONSOLEUtilsPrintf("\n Touch screen initialization failed !!!\n");
	}
	
    return (status);
}

void TscIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
	uint32_t index = 0;
	
	PIXCIRGetTouchData(&TouchData);

	CONSOLEUtilsPrintf("\nTouch Detected !!!\n");
	CONSOLEUtilsPrintf(" Number of Fingers: %d \n", TouchData.numFingers);
	for(index = 0; index < TouchData.numFingers; index++)
	{
		CONSOLEUtilsPrintf("  Coordinates(x%d, y%d): (%d, %d)\n", index, 
							index, TouchData.dataPoint[index].xPos, 
							TouchData.dataPoint[index].yPos);
	}
}
