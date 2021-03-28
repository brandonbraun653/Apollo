/**
 * \file   debug.h
 *
 * \brief  This file contains the debug utility macros and prototypes.
 *
 * \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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

#ifndef DEBUG_H__
#define DEBUG_H__

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

//*****************************************************************************
//
// The ASSERT macro, which does the actual assertion checking.  Typically, this
// will be for procedure arguments.
//
//*****************************************************************************
/**
 * \brief The ASSERT macro, which does the actual assertion checking. Typically,
 *        this will be for procedure arguments.
 */
#ifdef _DEBUG_

extern   void consolePrintf(const char* str, ...);

#ifdef DEBUG_PRINT_EN
/* Enable debug print. Note that this debug_printf() is also called from code that 
   is in ISR. It can be problematic and cause crash that can be hard to debug.
   To use it, make sure UART is in poll mode instead of the default interrupt mode
   If UART cannot be changed to poll mode or if we need to support high speed debug
   please consider changing the consolePrintf() or vconsolePrint() in usb_osal.c 
   to print to a memory buffer */
#define  debug_printf(x...) consolePrintf(x)
#else
#define  debug_printf(x...) do {} while (0)
#endif

#define ASSERT(expr) {                                      \
                         if(!(expr))                        \
                         {                                  \
                             while(1);                      \
                         }                                  \
                     }
#else
#define ASSERT(expr)
#define  debug_printf(x...) do {} while (0)
#endif

/**
 * \brief   Print the status
 *
 * \details The input to the below macro are the macros which are defined above.
 *          For e.g. usage of PRINT_STATUS() will be PRINT_STATUS(E_FAIL) or
 *          PRINT_STATUS(S_PASS)
 */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Prototype for the function that is called when an invalid argument is
 *        passed to an API.  This is only used when doing a DEBUG build.
 */
void __error__(char *pcFilename, unsigned int ulLine);

#ifdef __cplusplus
}
#endif

#endif // DEBUG_H__
