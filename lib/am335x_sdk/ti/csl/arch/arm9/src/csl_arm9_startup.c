/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
*/
#include <ti/csl/tistdtypes.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/arch/arm9/csl_arm9_startup.h>
#include <ti/csl/arch/arm9/V0/csl_arm9_cpu.h>


/***********************************************************************
**                     EXTERNAL FUNCTION PROTOTYPES
***********************************************************************/
extern void Entry(void);
extern void UndefInstHandler(void);
extern void SWIHandler(void);
extern void AbortHandler(void);
extern void IRQHandler(void);
extern void FIQHandler(void);
extern int main(void);

/******************************************************************************
**                      INTERNAL VARIABLE DEFINITIONS
*******************************************************************************/
static unsigned int const vecTbl[14]=
{
    0xE59FF018,
    0xE59FF018,
    0xE59FF018,
    0xE59FF018,
    0xE59FF014,
    0xE24FF008,
    0xE59FF010,
    0xE59FF010,
    (unsigned int)Entry,
    (unsigned int)UndefInstHandler,
    (unsigned int)SWIHandler,
    (unsigned int)AbortHandler,
    (unsigned int)IRQHandler,
    (unsigned int)FIQHandler
};


/******************************************************************************
**                          FUNCTION DEFINITIONS
*******************************************************************************/

/**
 * \brief   Boot strap function which enables the PLL(s) and PSC(s) for basic
 *          module(s)
 *
 * \param   none
 *
 * \return  None.
 *
 * This function is the first function that needs to be called in a system.
 * This should be set as the entry point in the linker script if loading the
 * elf binary via a debugger, on the target. This function never returns, but
 * gives control to the application entry point
 **/
unsigned int start_boot(void)
{
    /* Initialize the vector table with opcodes */
    CopyVectorTable();

   /* Calling the main */
    main();

    while(1);
}


void CopyVectorTable(void)
{
    unsigned int *dest = (unsigned int *)0xFFFF0000;
    unsigned int *src =  (unsigned int *)vecTbl;
    unsigned int count;

    for(count = 0; count < sizeof(vecTbl)/sizeof(vecTbl[0]); count++)
    {
        dest[count] = src[count];
    }
}


void BootAbort(void)
{
    while (1);
}

/***************************** End Of File ***********************************/
