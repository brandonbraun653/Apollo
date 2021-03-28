/**
 * \file  interrupt.h
 *
 * \brief Contains DSP interrupt related API declarations and system interrupt
 *        event numbers. (Note: event numbers are device-specific.)
 */

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

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
** 							INTERNAL TYPE DEFINITIONS
******************************************************************************/
typedef void (*c674xISR)(void);


/******************************************************************************
** 							EXTERNAL MACRO DEFINITIONS
******************************************************************************/
/* API Parameter: cpuINT, ecmINTx
 *
 * Brief: Used to select DSP CPU maskable interrupt.
 *
 * Functions:
 *		IntRegister
 *		IntUnRegister
 *		IntEventMap
 *		IntEventCombineInit
 *		IntEnable
 *		IntDisable */
#define C674X_MASK_INT4 4
#define C674X_MASK_INT5 5
#define C674X_MASK_INT6 6
#define C674X_MASK_INT7 7
#define C674X_MASK_INT8 8
#define C674X_MASK_INT9 9
#define C674X_MASK_INT10 10
#define C674X_MASK_INT11 11
#define C674X_MASK_INT12 12
#define C674X_MASK_INT13 13
#define C674X_MASK_INT14 14
#define C674X_MASK_INT15 15
/* Functions:
 *		IntRegister
 *		IntUnRegister  */
#define C674X_MASK_NMI 1
#define C674X_MASK_EXC 1
#define C674X_MASK_RSV2 2
#define C674X_MASK_RSV3 3

/* API Parameter: ecmINTx ONLY
 *
 * Brief: Used to specify unused Event Combiner system events
 *
 * Functions:
 * 		IntEventCombineInit */
#define ECM0_UNUSED -1
#define ECM1_UNUSED -1
#define ECM2_UNUSED -1
#define ECM3_UNUSED -1

/* API Parameter: sysINT
 *
 * Brief: Used to select system interrupts.
 *
 * Functions:
 * 		IntEventMap
 * 		IntEventSet
 * 		IntEventClear
 * 		IntEventCombineAdd
 * 		IntEventCombineRemove
 * 		IntEventCombineRegister
 * 		ExcCombineAdd
 * 		ExcCombineRemove */

/*			Event Combiners */
#define SYS_INT_EVT0 				0
#define SYS_INT_EVT1 				1
#define SYS_INT_EVT2 				2
#define SYS_INT_EVT3 				3

/******************************************************************************
** 							FUNCTION DEFINITIONS
******************************************************************************/
extern void Intc_Init (void);
extern void Intc_IntRegister (unsigned int cpuINT, void (*userISR)(void));
extern void Intc_IntUnregister (unsigned int cpuINT);
extern void IntEventMap (unsigned int cpuINT, unsigned int sysINT);
extern void IntEventSet (unsigned int sysINT);
extern void IntEventClear(unsigned int sysINT);
extern void IntEventCombineInit(int ecmINT0, int ecmINT1, int ecmINT2, int ecmINT3);
extern void IntEventCombineAdd(unsigned int sysINT);
extern void IntEventCombineRemove(unsigned int sysINT);
extern void IntEventCombineRegister(unsigned int sysINT, void (*userISR)(void));
extern void Intc_IntEnable (unsigned int cpuINT);
extern void Intc_IntDisable (unsigned int cpuINT);
extern void IntReset (void);
extern void Intc_SystemEnable (void);
extern unsigned int Intc_SystemDisable (void);
extern void IntGlobalRestore (unsigned int restoreValue);
extern void ExcGlobalEnable (void);
extern void ExcCombineAdd(unsigned int sysINT);
extern void ExcCombineRemove(unsigned int sysINT);

#ifdef __cplusplus
}
#endif

#endif /* INTERRUPT_H_ */
