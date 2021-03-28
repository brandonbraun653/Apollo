/******************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

#include "board_internal.h"

/* Registers to enable or disable memory ECC for L1, L2 and MSMC memories */
#define L1PEDSTAT   0x01846404
#define L1PEDCMD    0x01846408
#define L1PEDADDR   0x0184640C
#define L2EDSTAT    0x01846004
#define L2EDCMD     0x01846008
#define L2EDADDR    0x0184600C
#define L2EDCPEC    0x01846018
#define L2EDCNEC    0x0184601C
#define L2EDCEN     0x01846030
#define SMCERRAR    0x0BC00008
#define SMCERRXR    0x0BC0000C
#define SMEDCC      0x0BC00010
#define SMCEA       0x0BC00014
#define SMSECC      0x0BC00018


/*Enable EDC on MSMC*/
/* Note: Once MSMC EDC is enabled, error correction stays enabled until
 * the MSMC is reset
 */
static int MSMC_enableEDC ()
{
    unsigned int status = 0;

    *(unsigned int *)(SMEDCC) &= 0x7FFFFFFF;    //Clear SEN(bit31)=0
    *(unsigned int *)(SMEDCC) |= 0x40000000;    //Set ECM(bit30)=1

    /* Check the status */
    status = *(unsigned int *)(SMEDCC);


    if ((status>>30)==0x1)
        /* Enabled */
        return 1;

    /* Failed */
    return 0;
}


/*Enable EDC on L1P*/
static int enableL1PEDC ()
{
    unsigned int status = 0;

    *(unsigned int *)(L1PEDCMD) = 0x1;  //Set EN(bit0)=1

    /* Check the status */
    status = *(unsigned int *)(L1PEDSTAT);

    if ((status<<28) == 0x10000000)
        /* Enabled */
        return 1;

    /* Failed */
    return 0;
}


/*Enable EDC on L2*/
static int enableL2EDC ()
{
    unsigned int status = 0;

    *(unsigned int *)(L2EDCMD) = 0x1;

    /* Check the status */
    status = *(unsigned int *)(L2EDSTAT);

    if ((status<<28) == 0x10000000)
        /* Enabled */
        return 1;

    /* Failed */
    return 0;
}

/*Enable all bits in L2EDCEN*/
static int enableEDCL2EDCEN ()
{
    /* Set DL2CEN(bit0),PL2CEN(bit1),DL2SEN(bit2),PL2SEN(bit3),SDMAEN(bit4)=1 */
    *(unsigned int *)(L2EDCEN) |= 0x1F;
    return 1;
}

Board_STATUS Board_eccInit()
{
    enableL1PEDC();
    enableEDCL2EDCEN();
    enableL2EDC();
    MSMC_enableEDC();
    return BOARD_SOK;
}
