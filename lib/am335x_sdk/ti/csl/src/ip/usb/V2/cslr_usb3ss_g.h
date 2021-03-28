/********************************************************************
* This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2003 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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

*********************************************************************
* file: cslr_usb3ss_g.h
*
* Brief: This file contains the Register Description for usb3ss_g
*
*********************************************************************/
#ifndef CSLR_USB3SS_G_H_
#define CSLR_USB3SS_G_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for __ALL__
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION; /* IP Revision Identifier (X.Y.R)
Used by software to track features, bugs, and compatibility */
    volatile Uint8 RSVD0[12];
    volatile Uint32 SYSCONFIG; /* Clock management configuration register. */
    volatile Uint8 RSVD1[4];
    volatile Uint32 IRQ_EOI_MAIN_0; /* Software End-Of-Interrupt: Allows the generation of further pulses on the interrupt line, if an new interrupt event is pending, when using the pulsed output.  Unused when using the level interrupt line (depending on module integration).

This register will reset the cycle after it has been written to; therefore, reading this register will always return 0x0000_0000. */
} CSL_Usb3ss_g__all__Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__0
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__0Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__1
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__1Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__2
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__2Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__3
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__3Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__4
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__4Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__5
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__5Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__6
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__6Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__7
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__7Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__8
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__8Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__9
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__9Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__10
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__10Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__11
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__11Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__12
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__12Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__13
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__13Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__14
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__14Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_HST_DEV_BUNDLE__15
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MAIN_Y; /* The IRQ_STATUS_RAW_MAIN_Y Register allows the USBSS interrupt sources to be manually
triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.

General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MAIN_Y; /* The IRQ_STATUS_MAIN_Y Register allows the USBSS interrupt sources to be manually
cleared when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. Parameter Y ranges from 0 to 15.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_MAIN_Y; /* Enable of main core interrupt request. Write 1 to set (i.e. to enable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MAIN_Y; /* Enable of main core interrupt request. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_hst_dev_bundle__15Regs;

/**************************************************************************\
* Register Overlay Structure for IRQ_EOI_MISC_BUNDLE
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_EOI_MISC; /* The End of Interrupt (EOI) MISC Register allows the CPU to acknowledge completion of an interrupt by writing to the EOI for MISC interrupt sources. An eoi_write signal will be generated and another interrupt will be triggered if interrupt sources remain.

This register will be reset one cycle after it has been written to. */
} CSL_Usb3ss_gIrq_eoi_misc_bundleRegs;

/**************************************************************************\
* Register Overlay Structure for IRQ_MISC_BUNDLE
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_STATUS_RAW_MISC; /* The IRQ_STATUS_RAW_MISC Register allows the USBSS interrupt sources to be manually triggered when writing a 1 to a specific bit. A read of this register returns the USBSS interrupt event pending value. 
General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_MISC; /* "regular" status of secondary interrupt requests. Set only when enabled.
Write 1 to clear after interrupt has been serviced (raw status also gets cleared). */
    volatile Uint32 IRQ_ENABLE_SET_MISC; /* Enable of secondary interrupt requests. Write 1 to set (i.e. to disable interrupt).
Readout is the same as corresponding _CLR register. */
    volatile Uint32 IRQ_ENABLE_CLR_MISC; /* Enable of secondary interrupt requests. Write 1 to clear (i.e. to disable interrupt).
Readout is the same as corresponding _SET register. */
} CSL_Usb3ss_gIrq_misc_bundleRegs;

/**************************************************************************\
* Register Overlay Structure for IRQ_OABS
\**************************************************************************/
typedef struct  {
    volatile Uint32 IRQ_EOI_OABS; /* The End of Interrupt (EOI) Register allows the CPU to acknowledge completion of an interrupt by writing to the EOI for OTG, ADP, BC, and SER interrupt sources. An eoi_write signal will be generated and another interrupt will be triggered if interrupt sources remain. 

This register will be reset one cycle after it has been written to. */
    volatile Uint32 IRQ_STATUS_RAW_OABS; /* The IRQ_STATUS_RAW_OABS Register allows the OTG, ADP, BC, and SER interrupt sources to be manually triggered when writing a 1 to a specific bit. A read of this register returns the USB0 interrupt event pending value.
General actions per bit:
Write 0: No action
Write 1: Set event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_STATUS_OABS; /* The IRQ_STATUS_OABS Register allows the OTG, ADP, BC, and SER interrupt sources to be manually triggered when writing a 1 to a specific bit. A read of this register returns the interrupt event pending value.
General actions per bit:
Write 0: No action
Write 1: Clear event
Read 0: No event pending
Read 1: Event pending */
    volatile Uint32 IRQ_ENABLE_SET_OABS; /* The IRQ_ENABLE_SET_OABS Register allows the OTG, ADP, BC, and SER interrupt sources to be manually enabled when writing a 1 to a specific bit. A read of this register returns the USB0 interrupt event pending value.
General actions per bit:
Write 0: No action
Write 1: Interrupt enabled
Read 0: Interrupt disabled
Read 1: Interrupt enabled */
    volatile Uint32 IRQ_ENABLE_CLR_OABS; /* The IRQ_ENABLE_CLR_OABS Register allows the OTG, ADP, BC, and SER interrupt
sources to be manually disabled when writing a 1 to a specific bit. A read of this register returns the USB0 interrupt event pending value.
General actions per bit:
Write 0: No action
Write 1: Disable enabled
Read 0: Interrupt disabled
Read 1: Interrupt enabled */
} CSL_Usb3ss_gIrq_oabsRegs;

/**************************************************************************\
* Register Overlay Structure for WBU_SPECIFIC
\**************************************************************************/
typedef struct  {
    volatile Uint32 UTMI_OTG_CTRL; /* The UTMI_OTG_CTL register provides information of the signals given by the controller to the PHY for implementations that use an external PMIC.

This register is not used in USB3SS_SR80LX implementations. */
    volatile Uint32 UTMI_OTG_STATUS; /* The UTMI_OTG_STATUS register is used to communicate via an external PMIC and the controller.  The PMIC signals the controller via an interrupt and software will update these register fields based on data from the external PMIC.

This register is not used in USB3SS_SR80LX implementations. */
} CSL_Usb3ss_gWbu_specificRegs;

/**************************************************************************\
* Register Overlay Structure for FIFO_DEPTHS
\**************************************************************************/
typedef struct  {
    volatile Uint32 TXFIFO_DEPTH; /* The controller configuration parameter DWC_USB3_RAM1_DEPTH indicates the USBSS
configuration with the maximum number of addressable locations in the TxFIFO. Different USBSS configurations can be implemented with DWC_USB3_RAM1_DEPTH or less number of locations. The TXFIFO_DEPTH register needs to initialized at startup with the actual number of physical RAM locations for that specific configuration.

Valid sizes can range from 1 to 65535 addressable locations. */
    volatile Uint32 RXFIFO_DEPTH; /* The controller configuration parameter DWC_USB3_RAM2_DEPTH indicates the USBSS
configuration with the maximum number of addressable locations in the RxFIFO. Different USBSS configurations can be implemented with DWC_USB3_RAM2_DEPTH or less number of locations. The RXFIFO_DEPTH register needs to initialized at startup with the actual number of physical RAM locatiosn for that specific configuration.

Valid sizes can range from 1 to 65535 addressable locations. */
} CSL_Usb3ss_gFifo_depthsRegs;

/**************************************************************************\
* Register Overlay Structure for DSPS_SPECIFIC
\**************************************************************************/
typedef struct  {
    volatile Uint32 SER_CONTROL; /* The SER_CONTROL register sets the enable bits for their respective error correction and/or detection functions.  Depending on the application the system may or may not need error detection and/or error correction for each IP. These bits give the option to either enable or disable these features.

The USB3SS_SR80LX does not use the parameter PAR_EN. */
    volatile Uint32 SER_STATUS; /* The SER Status Register contains many important status fields for the system to diagnose the SER event.

If par_err is set high, then the parity check detection logic has determined that the parity stored in the RAM does not match the parity that was generated by the read transaction.

If bec_err is set high, then the block error correction has a non-zero syndrome value. This means that an error has been detected. Single bit errors will be corrected and double bit errors will be detected.

The type of error will be shown in the type_err field. A value of 0 indicates no error has been detected and/or corrected. A value of 1 or 2 indicates either a single or double error has been detected. Values of 1 and 2 will only be valid if a block coder has been implemented (m>3). A value of 3 indicates that the parity detection logic has detected an error event.

The byte_pos field indicates which p byte of the RAM that had the parity detection error event for designs with p>1. The position of the byte will be in little Endian. This status is optional and it only supports RAMs that have 8 bytes or less.

The addr_valid field indicates whether the address of the RAM with the error event can be determined. A value of 1 indicates that the address in the SER Address Register is valid. A value of 0 indicates that the address can not be determined. If the address can not be determined, then the system will assume that the entire RAM is corrupted.

The ram_err field indicates which RAM had the error event. This field will be specific to the IP that supports SER and will need to be defined in the respective IP memory map. Each IP can have up to 4096 individual RAMs.

The USB3SS_SR80LX does not use the parameter PAR_ERR or BYTE_POS. */
    volatile Uint32 SER_ADDRESS; /* The SER Address Register indicates the address of the RAM that had the error event. */
    volatile Uint32 PHY2CONFIG; /* USB2 PHY configuration

This register is not used in usb3ss_sr80lx implementations. */
    volatile Uint32 PHY3CONFIG; /* USB3 PHY configuration

This register is not used in usb3ss_sr80lx implementations. */
} CSL_Usb3ss_gDsps_specificRegs;

/**************************************************************************\
* Register Overlay Structure for MISC
\**************************************************************************/
typedef struct  {
    volatile Uint32 MMRAM_OFFSET; /* The MMRAM_OFFSET Register is the address offset of Memory Mapped RAM accesses.
The offset_msb parameter is the page offset.
â¢ 0x00 = page offset for core MMR set, lower half: DO NOT USE: use static access at
offset 0x10_000+ instead
â¢ 0x01 = page offset for core MMR set, upper half: DO NOT USE: use static access at
offset 0x10_000+ instead
â¢ 0x08 = base page offset for RAM0 (equal to core byte address 0x4_0000): descriptor
RAM. The RAM shall fit inside this page for up to 32 Kbyte = 8192 x 64-bit words
â¢ 0x10 = base page offset for lower half of RAM1 (equal to core byte address 0x8_0000):
Tx FIFO RAM.
â¢ 0x11 = base page offset for upper half of RAM1 (equal to core byte address 0x8_8000):
Tx FIFO RAM.
â¢ 0x18 = base page offset for RAM2 (equal to core byte address 0xC_0000): Rx FIFO
RAM. The RAM shall fit inside this page for up to 32 Kbyte = 8192 x 64-bit words. */
    volatile Uint32 FLADJ; /* The FLADJ Register has the jitter adjustment parameters for the USB3 port and the USB2 port. It
also has the HS jitter adjustment value. */
    volatile Uint32 DEBUG_CFG; /* The DEBUG_CFG Register controls the selection of debug signals on the debug interface.

0x0 = debug outputs are tied low
0x1 = debug outputs are UTMI interface signals
0x2 = debug outputs are PIPE3 interface signals
0x3 = debug outputs are xHC internal signals
0x4 = debug outputs are controller logic_analyzer_trace[31:0]
0x5 = debug outputs are controller logic_analyzer_trace[63:32] */
    volatile Uint32 DEBUG_DATA; /* The DEBUG_DATA Register allows visibility into various internal signals which have been
synchronized with the bus_clk. The DEBUG_CFG register sel parameter selects which signals
that are observed by this register. If sel is equal to a 0, then all the debug signals will be zeros. */
    volatile Uint32 DEV_EBC_EN; /* The DEV_EBC_EN register enables the External Buffer Control for IN EP 15 and OUT EP 15.
0 = disable
1 = enable */
} CSL_Usb3ss_gMiscRegs;

/**************************************************************************\
* Register Overlay Structure for NG_SPECIFIC
\**************************************************************************/
typedef struct  {
    volatile Uint32 HOST_HUB_CTRL; /* The HOST_HUB_CTRL Register is a collection of various input signals that control the xHC controllerâs Host or Hub interfaces. These signals are used regardless if a Host or Hub is
implemented or not. */
} CSL_Usb3ss_gNg_specificRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Usb3ss_g__all__Regs __ALL__;
    volatile Uint8 RSVD0[4];
    CSL_Usb3ss_gIrq_hst_dev_bundle__0Regs IRQ_HST_DEV_BUNDLE__0;
    CSL_Usb3ss_gIrq_hst_dev_bundle__1Regs IRQ_HST_DEV_BUNDLE__1;
    CSL_Usb3ss_gIrq_hst_dev_bundle__2Regs IRQ_HST_DEV_BUNDLE__2;
    CSL_Usb3ss_gIrq_hst_dev_bundle__3Regs IRQ_HST_DEV_BUNDLE__3;
    CSL_Usb3ss_gIrq_hst_dev_bundle__4Regs IRQ_HST_DEV_BUNDLE__4;
    CSL_Usb3ss_gIrq_hst_dev_bundle__5Regs IRQ_HST_DEV_BUNDLE__5;
    CSL_Usb3ss_gIrq_hst_dev_bundle__6Regs IRQ_HST_DEV_BUNDLE__6;
    CSL_Usb3ss_gIrq_hst_dev_bundle__7Regs IRQ_HST_DEV_BUNDLE__7;
    CSL_Usb3ss_gIrq_hst_dev_bundle__8Regs IRQ_HST_DEV_BUNDLE__8;
    CSL_Usb3ss_gIrq_hst_dev_bundle__9Regs IRQ_HST_DEV_BUNDLE__9;
    CSL_Usb3ss_gIrq_hst_dev_bundle__10Regs IRQ_HST_DEV_BUNDLE__10;
    CSL_Usb3ss_gIrq_hst_dev_bundle__11Regs IRQ_HST_DEV_BUNDLE__11;
    CSL_Usb3ss_gIrq_hst_dev_bundle__12Regs IRQ_HST_DEV_BUNDLE__12;
    CSL_Usb3ss_gIrq_hst_dev_bundle__13Regs IRQ_HST_DEV_BUNDLE__13;
    CSL_Usb3ss_gIrq_hst_dev_bundle__14Regs IRQ_HST_DEV_BUNDLE__14;
    CSL_Usb3ss_gIrq_hst_dev_bundle__15Regs IRQ_HST_DEV_BUNDLE__15;
    volatile Uint8 RSVD1[780];
    CSL_Usb3ss_gIrq_eoi_misc_bundleRegs IRQ_EOI_MISC_BUNDLE;
    CSL_Usb3ss_gIrq_misc_bundleRegs IRQ_MISC_BUNDLE;
    volatile Uint8 RSVD2[12];
    CSL_Usb3ss_gIrq_oabsRegs IRQ_OABS;
    volatile Uint8 RSVD3[160];
    CSL_Usb3ss_gWbu_specificRegs WBU_SPECIFIC;
    CSL_Usb3ss_gFifo_depthsRegs FIFO_DEPTHS;
    volatile Uint8 RSVD4[240];
    CSL_Usb3ss_gDsps_specificRegs DSPS_SPECIFIC;
    volatile Uint8 RSVD5[236];
    CSL_Usb3ss_gMiscRegs MISC;
    CSL_Usb3ss_gNg_specificRegs NG_SPECIFIC;
} CSL_Usb3ss_gRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION */

#define CSL_USB3SS_G_REVISION_Y_MINOR_MASK (0x0000003Fu)
#define CSL_USB3SS_G_REVISION_Y_MINOR_SHIFT (0x00000000u)
#define CSL_USB3SS_G_REVISION_Y_MINOR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_REVISION_CUSTOM_MASK (0x000000C0u)
#define CSL_USB3SS_G_REVISION_CUSTOM_SHIFT (0x00000006u)
#define CSL_USB3SS_G_REVISION_CUSTOM_RESETVAL (0x00000000u)
/*----CUSTOM Tokens----*/
#define CSL_USB3SS_G_REVISION_CUSTOM_STANDARD (0x00000000u)

#define CSL_USB3SS_G_REVISION_X_MAJOR_MASK (0x00000700u)
#define CSL_USB3SS_G_REVISION_X_MAJOR_SHIFT (0x00000008u)
#define CSL_USB3SS_G_REVISION_X_MAJOR_RESETVAL (0x00000000u)
/*----X_MAJOR Tokens----*/
#define CSL_USB3SS_G_REVISION_X_MAJOR_V10 (0x00000001u)
#define CSL_USB3SS_G_REVISION_X_MAJOR_V20 (0x00000002u)
#define CSL_USB3SS_G_REVISION_X_MAJOR_3  (0x00000003u)
#define CSL_USB3SS_G_REVISION_X_MAJOR_4  (0x00000004u)

#define CSL_USB3SS_G_REVISION_R_RTL_MASK (0x0000F800u)
#define CSL_USB3SS_G_REVISION_R_RTL_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_REVISION_R_RTL_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_REVISION_FUNC_MASK  (0x0FFF0000u)
#define CSL_USB3SS_G_REVISION_FUNC_SHIFT (0x00000010u)
#define CSL_USB3SS_G_REVISION_FUNC_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_USB3SS_G_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_USB3SS_G_REVISION_SCHEME_RESETVAL (0x00000000u)
/*----SCHEME Tokens----*/
#define CSL_USB3SS_G_REVISION_SCHEME_H08 (0x00000001u)
#define CSL_USB3SS_G_REVISION_SCHEME_LEGACY (0x00000000u)

#define CSL_USB3SS_G_REVISION_BU_MASK    (0x30000000u)
#define CSL_USB3SS_G_REVISION_BU_SHIFT   (0x0000001Cu)
#define CSL_USB3SS_G_REVISION_BU_RESETVAL (0x00000000u)
/*----BU Tokens----*/
#define CSL_USB3SS_G_REVISION_BU_WBU     (0x00000001u)
#define CSL_USB3SS_G_REVISION_BU_DSPS    (0x00000000u)

#define CSL_USB3SS_G_REVISION_RESETVAL   (0x00000000u)

/* SYSCONFIG */

#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_MASK (0x00010000u)
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_SHIFT (0x00000010u)
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_RESETVAL (0x00000000u)
/*----DMADISABLE Tokens----*/
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_DISABLED (0x00000001u)
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_ENABLED (0x00000000u)
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_DISABLE (0x00000001u)
#define CSL_USB3SS_G_SYSCONFIG_DMADISABLE_ENABLE (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_BUSCLKEN_N_MASK (0x00000100u)
#define CSL_USB3SS_G_SYSCONFIG_BUSCLKEN_N_SHIFT (0x00000008u)
#define CSL_USB3SS_G_SYSCONFIG_BUSCLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_RESERVED1_MASK (0x00008000u)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED1_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_RESERVED2_MASK (0xFFFE0000u)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED2_SHIFT (0x00000011u)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_RESERVED_MASK (0x000000FEu)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_SYSCONFIG_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_PHYMMRCLKEN_N_MASK (0x00000200u)
#define CSL_USB3SS_G_SYSCONFIG_PHYMMRCLKEN_N_SHIFT (0x00000009u)
#define CSL_USB3SS_G_SYSCONFIG_PHYMMRCLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_UTMICLKEN_N_MASK (0x00000400u)
#define CSL_USB3SS_G_SYSCONFIG_UTMICLKEN_N_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_SYSCONFIG_UTMICLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_ULPICLKEN_N_MASK (0x00000800u)
#define CSL_USB3SS_G_SYSCONFIG_ULPICLKEN_N_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_SYSCONFIG_ULPICLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_PIPECLKEN_N_MASK (0x00001000u)
#define CSL_USB3SS_G_SYSCONFIG_PIPECLKEN_N_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_SYSCONFIG_PIPECLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_SUSPCLKEN_N_MASK (0x00002000u)
#define CSL_USB3SS_G_SYSCONFIG_SUSPCLKEN_N_SHIFT (0x0000000Du)
#define CSL_USB3SS_G_SYSCONFIG_SUSPCLKEN_N_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_SOFT_RESET_MASK (0x00000001u)
#define CSL_USB3SS_G_SYSCONFIG_SOFT_RESET_SHIFT (0x00000000u)
#define CSL_USB3SS_G_SYSCONFIG_SOFT_RESET_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_REFCLKEN_N1_MASK (0x00004000u)
#define CSL_USB3SS_G_SYSCONFIG_REFCLKEN_N1_SHIFT (0x0000000Eu)
#define CSL_USB3SS_G_SYSCONFIG_REFCLKEN_N1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SYSCONFIG_RESETVAL  (0x00000000u)

/* IRQ_EOI_MAIN_0 */

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_RESETVAL (0x00000000u)
/*----EOI_0 Tokens----*/
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_READ0 (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_EOI0 (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_0_EOI1 (0x00000001u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_1_MASK (0x00000002u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_1_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_2_MASK (0x00000004u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_2_SHIFT (0x00000002u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_3_MASK (0x00000008u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_3_SHIFT (0x00000003u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_4_MASK (0x00000010u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_4_SHIFT (0x00000004u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_4_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_5_MASK (0x00000020u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_5_SHIFT (0x00000005u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_5_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_6_MASK (0x00000040u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_6_SHIFT (0x00000006u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_6_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_7_MASK (0x00000080u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_7_SHIFT (0x00000007u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_7_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_8_MASK (0x00000100u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_8_SHIFT (0x00000008u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_8_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_9_MASK (0x00000200u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_9_SHIFT (0x00000009u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_9_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_10_MASK (0x00000400u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_10_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_10_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_11_MASK (0x00000800u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_11_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_11_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_12_MASK (0x00001000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_12_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_12_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_13_MASK (0x00002000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_13_SHIFT (0x0000000Du)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_13_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_14_MASK (0x00004000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_14_SHIFT (0x0000000Eu)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_14_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_15_MASK (0x00008000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_15_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_EOI_15_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_RESERVED_MASK (0xFFFF0000u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_RESERVED_SHIFT (0x00000010u)
#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MAIN_0_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_EVENTRINGY_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_STATUS_MAIN_Y */

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_RESETVAL (0x00000000u)
/*----EVENTRINGY Tokens----*/
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NONE (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_PENDING (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_EVENTRINGY_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_COREIRQ_EN_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MAIN_Y */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_RESETVAL (0x00000000u)
/*----COREIRQ_EN Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_COREIRQ_EN_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MAIN_Y_RESETVAL (0x00000000u)

/* IRQ_EOI_MISC */

#define CSL_USB3SS_G_IRQ_EOI_MISC_EOI_FOR_USBSS_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_MISC_EOI_FOR_USBSS_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_MISC_EOI_FOR_USBSS_RESETVAL (0x00000000u)
/*----EOI_FOR_USBSS Tokens----*/
#define CSL_USB3SS_G_IRQ_EOI_MISC_EOI_FOR_USBSS_READ0 (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_MISC_EOI_FOR_USBSS_EOI_MISC (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MISC_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_EOI_MISC_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_MISC_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_MISC_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_MISC */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED_MASK (0x0001FFFFu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_DMADISABLECLR_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_DMADISABLECLR_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_DMADISABLECLR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED1_MASK (0xFFFC0000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED1_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_MISC_RESETVAL (0x00000000u)

/* IRQ_STATUS_MISC */

#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED_MASK (0x0001FFFFu)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MISC_DMADISABLECLR_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_DMADISABLECLR_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_DMADISABLECLR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED1_MASK (0xFFFC0000u)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED1_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_MISC_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_MISC */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED_MASK (0x0001FFFFu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_RESETVAL (0x00000000u)
/*----DMADISABLECLR Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_DMADISABLECLR_SET (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED1_MASK (0xFFFC0000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED1_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_MISC_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_MISC */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED_MASK (0x0001FFFFu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_RESETVAL (0x00000000u)
/*----DMADISABLECLR Tokens----*/
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_DISABLED (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_ENABLED (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_NOACTION (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_CLEAR (0x00000001u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED1_MASK (0xFFFC0000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED1_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_MISC_RESETVAL (0x00000000u)

/* IRQ_EOI_OABS */

#define CSL_USB3SS_G_IRQ_EOI_OABS_EOI_FOR_USBSS_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_OABS_EOI_FOR_USBSS_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_OABS_EOI_FOR_USBSS_RESETVAL (0x00000000u)
/*----EOI_FOR_USBSS Tokens----*/
#define CSL_USB3SS_G_IRQ_EOI_OABS_EOI_FOR_USBSS_READ0 (0x00000000u)
#define CSL_USB3SS_G_IRQ_EOI_OABS_EOI_FOR_USBSS_EOI_OABS (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_OABS_RESERVED_MASK (0xFFFFFFFEu)
#define CSL_USB3SS_G_IRQ_EOI_OABS_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_EOI_OABS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_EOI_OABS_RESETVAL (0x00000000u)

/* IRQ_STATUS_RAW_OABS */

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_SER_EVNT_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_SER_EVNT_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_SER_EVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_MASK (0x00000080u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_SHIFT (0x00000007u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_MASK (0x00000004u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_SHIFT (0x00000002u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_MASK (0x00000010u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_SHIFT (0x00000004u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_MASK (0x00000020u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_SHIFT (0x00000005u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_MASK (0x00000040u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_SHIFT (0x00000006u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED_MASK (0x00000002u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_MASK (0x00000100u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT (0x00000008u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_MASK (0x00000200u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT (0x00000009u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_MASK (0x00000400u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_MASK (0x00000800u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED1_MASK (0x0000F000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED1_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_MASK (0x00010000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_SHIFT (0x00000010u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_MASK (0x00040000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_MASK (0x00080000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_SHIFT (0x00000013u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_MASK (0x00100000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_SHIFT (0x00000014u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_MASK (0x01000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_SHIFT (0x00000018u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED3_MASK (0xF0000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED3_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED4_MASK (0x00000008u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED4_SHIFT (0x00000003u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESERVED4_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_MASK (0x00200000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_SHIFT (0x00000015u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_MASK (0x00400000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_SHIFT (0x00000016u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_MASK (0x00800000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_SHIFT (0x00000017u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_MASK (0x02000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_SHIFT (0x00000019u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_MASK (0x04000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_SHIFT (0x0000001Au)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_MASK (0x08000000u)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_RAW_OABS_RESETVAL (0x00000000u)

/* IRQ_STATUS_OABS */

#define CSL_USB3SS_G_IRQ_STATUS_OABS_SER_EVNT_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_SER_EVNT_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_SER_EVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPPRBEVNT_MASK (0x00000080u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPPRBEVNT_SHIFT (0x00000007u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPPRBEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_MV_CHNGEVNT_MASK (0x00000004u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_MV_CHNGEVNT_SHIFT (0x00000002u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_MV_CHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_MASK (0x00000010u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_SHIFT (0x00000004u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPTMOUTEVNT_MASK (0x00000020u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPTMOUTEVNT_SHIFT (0x00000005u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPTMOUTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPSNSEVNT_MASK (0x00000040u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPSNSEVNT_SHIFT (0x00000006u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_ADPSNSEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED_MASK (0x00000002u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_MASK (0x00000100u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT (0x00000008u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_MASK (0x00000200u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT (0x00000009u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_MASK (0x00000400u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_MASK (0x00000800u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED1_MASK (0x0000F000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED1_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_MASK (0x00010000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_SHIFT (0x00000010u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_MASK (0x00040000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_MASK (0x00080000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_SHIFT (0x00000013u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_MASK (0x00100000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_SHIFT (0x00000014u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_MASK (0x01000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_SHIFT (0x00000018u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED3_MASK (0xF0000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED3_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_MASK (0x02000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_SHIFT (0x00000019u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_MASK (0x04000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_SHIFT (0x0000001Au)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_MASK (0x08000000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_MASK (0x00200000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_SHIFT (0x00000015u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_MASK (0x00400000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_SHIFT (0x00000016u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_MASK (0x00800000u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_SHIFT (0x00000017u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED2_MASK (0x00000008u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED2_SHIFT (0x00000003u)
#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESERVED2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_STATUS_OABS_RESETVAL (0x00000000u)

/* IRQ_ENABLE_SET_OABS */

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_SER_EVNT_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_SER_EVNT_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_SER_EVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_MASK (0x00000080u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_SHIFT (0x00000007u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_MASK (0x00000004u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_SHIFT (0x00000002u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_MASK (0x00000010u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_SHIFT (0x00000004u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_MASK (0x00000020u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_SHIFT (0x00000005u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_MASK (0x00000040u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_SHIFT (0x00000006u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED_MASK (0x00000002u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_MASK (0x00000100u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT (0x00000008u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_MASK (0x00000200u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT (0x00000009u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_MASK (0x00000400u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_MASK (0x00000800u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED1_MASK (0x0000F000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED1_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_MASK (0x00010000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_SHIFT (0x00000010u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_MASK (0x00040000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_MASK (0x00080000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_SHIFT (0x00000013u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_MASK (0x00100000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_SHIFT (0x00000014u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_MASK (0x01000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_SHIFT (0x00000018u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED3_MASK (0xF0000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED3_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED4_MASK (0x00000008u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED4_SHIFT (0x00000003u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESERVED4_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_MASK (0x00200000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_SHIFT (0x00000015u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_MASK (0x00400000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_SHIFT (0x00000016u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_MASK (0x00800000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_SHIFT (0x00000017u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_MASK (0x02000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_SHIFT (0x00000019u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_MASK (0x04000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_SHIFT (0x0000001Au)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_MASK (0x08000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_SET_OABS_RESETVAL (0x00000000u)

/* IRQ_ENABLE_CLR_OABS */

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_SER_EVNT_MASK (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_SER_EVNT_SHIFT (0x00000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_SER_EVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_MASK (0x00000080u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_SHIFT (0x00000007u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_MASK (0x00000004u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_SHIFT (0x00000002u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_MASK (0x00000010u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_SHIFT (0x00000004u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_MASK (0x00000020u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_SHIFT (0x00000005u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_MASK (0x00000040u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_SHIFT (0x00000006u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED_MASK (0x00000002u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_MASK (0x00000100u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT (0x00000008u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_MASK (0x00000200u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT (0x00000009u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_MASK (0x00000400u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_MASK (0x00000800u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED1_MASK (0x0000F000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED1_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_MASK (0x00010000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_SHIFT (0x00000010u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_MASK (0x00020000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_SHIFT (0x00000011u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_MASK (0x00040000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_SHIFT (0x00000012u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_MASK (0x00080000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_SHIFT (0x00000013u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_MASK (0x00100000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_SHIFT (0x00000014u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_MASK (0x01000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_SHIFT (0x00000018u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED3_MASK (0xF0000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED3_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED4_MASK (0x00000008u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED4_SHIFT (0x00000003u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESERVED4_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_MASK (0x00200000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_SHIFT (0x00000015u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_MASK (0x00400000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_SHIFT (0x00000016u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_MASK (0x00800000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_SHIFT (0x00000017u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_MASK (0x02000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_SHIFT (0x00000019u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_MASK (0x04000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_SHIFT (0x0000001Au)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_MASK (0x08000000u)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_IRQ_ENABLE_CLR_OABS_RESETVAL (0x00000000u)

/* UTMI_OTG_CTRL */

#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED_MASK (0x00000006u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED_SHIFT (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_IDPULLUP_MASK (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_IDPULLUP_SHIFT (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_IDPULLUP_RESETVAL (0x00000000u)
/*----IDPULLUP Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_CTRL_IDPULLUP_DISABLE (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_IDPULLUP_ENABLE (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_DISCHRGVBUS_MASK (0x00000008u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DISCHRGVBUS_SHIFT (0x00000003u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DISCHRGVBUS_RESETVAL (0x00000000u)
/*----DISCHRGVBUS Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DISCHRGVBUS_DISCHARGE (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DISCHRGVBUS_NOACTION (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_CHRGVBUS_MASK (0x00000010u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_CHRGVBUS_SHIFT (0x00000004u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_CHRGVBUS_RESETVAL (0x00000000u)
/*----CHRGVBUS Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_CTRL_CHRGVBUS_CHARGE (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_CHRGVBUS_NOACTION (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_DRVVBUS_MASK (0x00000020u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DRVVBUS_SHIFT (0x00000005u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DRVVBUS_RESETVAL (0x00000000u)
/*----DRVVBUS Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DRVVBUS_DRIVE (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_DRVVBUS_NOACTION (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED1_MASK (0xFFFFFFC0u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED1_SHIFT (0x00000006u)
#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_CTRL_RESETVAL (0x00000000u)

/* UTMI_OTG_STATUS */

#define CSL_USB3SS_G_UTMI_OTG_STATUS_SW_MODE_MASK (0x80000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SW_MODE_SHIFT (0x0000001Fu)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SW_MODE_RESETVAL (0x00000000u)
/*----SW_MODE Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SW_MODE_IO (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SW_MODE_SW (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED_MASK (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_VBUSVALID_MASK (0x00000002u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_VBUSVALID_SHIFT (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_VBUSVALID_RESETVAL (0x00000000u)
/*----VBUSVALID Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_VBUSVALID_VALID (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_VBUSVALID_NOTVALID (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSVALID_MASK (0x00000004u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSVALID_SHIFT (0x00000002u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSVALID_RESETVAL (0x00000000u)
/*----SESSVALID Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSVALID_NOTVALID (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSVALID_VALID (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSEND_MASK (0x00000008u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSEND_SHIFT (0x00000003u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSEND_RESETVAL (0x00000000u)
/*----SESSEND Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSEND_ENDED (0x00000001u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_SESSEND_NOTENDED (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_IDDIG_MASK (0x00000010u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_IDDIG_SHIFT (0x00000004u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_IDDIG_RESETVAL (0x00000000u)
/*----IDDIG Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_IDDIG_IDA (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_IDDIG_IDB (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_TXBITSTUFFENABLE_MASK (0x00000100u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_TXBITSTUFFENABLE_SHIFT (0x00000008u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_TXBITSTUFFENABLE_RESETVAL (0x00000000u)
/*----TXBITSTUFFENABLE Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_TXBITSTUFFENABLE_NOBS (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_TXBITSTUFFENABLE_BS (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED1_MASK (0x000000E0u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED1_SHIFT (0x00000005u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED2_MASK (0x7FFFF800u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED2_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESERVED2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_POWERPRESENT_MASK (0x00000200u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_POWERPRESENT_SHIFT (0x00000009u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_POWERPRESENT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_PORT_OVERCURRENT_MASK (0x00000400u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_PORT_OVERCURRENT_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_PORT_OVERCURRENT_RESETVAL (0x00000000u)
/*----PORT_OVERCURRENT Tokens----*/
#define CSL_USB3SS_G_UTMI_OTG_STATUS_PORT_OVERCURRENT_NONE (0x00000000u)
#define CSL_USB3SS_G_UTMI_OTG_STATUS_PORT_OVERCURRENT_OC (0x00000001u)

#define CSL_USB3SS_G_UTMI_OTG_STATUS_RESETVAL (0x00000000u)

/* TXFIFO_DEPTH */

#define CSL_USB3SS_G_TXFIFO_DEPTH_TXFIFOSIZE_MASK (0x0000FFFFu)
#define CSL_USB3SS_G_TXFIFO_DEPTH_TXFIFOSIZE_SHIFT (0x00000000u)
#define CSL_USB3SS_G_TXFIFO_DEPTH_TXFIFOSIZE_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_TXFIFO_DEPTH_RESERVED_MASK (0xFFFF0000u)
#define CSL_USB3SS_G_TXFIFO_DEPTH_RESERVED_SHIFT (0x00000010u)
#define CSL_USB3SS_G_TXFIFO_DEPTH_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_TXFIFO_DEPTH_RESETVAL (0x00000000u)

/* RXFIFO_DEPTH */

#define CSL_USB3SS_G_RXFIFO_DEPTH_RXFIFOSIZE_MASK (0x0000FFFFu)
#define CSL_USB3SS_G_RXFIFO_DEPTH_RXFIFOSIZE_SHIFT (0x00000000u)
#define CSL_USB3SS_G_RXFIFO_DEPTH_RXFIFOSIZE_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_RXFIFO_DEPTH_RESERVED_MASK (0xFFFF0000u)
#define CSL_USB3SS_G_RXFIFO_DEPTH_RESERVED_SHIFT (0x00000010u)
#define CSL_USB3SS_G_RXFIFO_DEPTH_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_RXFIFO_DEPTH_RESETVAL (0x00000000u)

/* SER_CONTROL */

#define CSL_USB3SS_G_SER_CONTROL_PAR_EN_MASK (0x00000001u)
#define CSL_USB3SS_G_SER_CONTROL_PAR_EN_SHIFT (0x00000000u)
#define CSL_USB3SS_G_SER_CONTROL_PAR_EN_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_CONTROL_BEC_EN_MASK (0x00000006u)
#define CSL_USB3SS_G_SER_CONTROL_BEC_EN_SHIFT (0x00000001u)
#define CSL_USB3SS_G_SER_CONTROL_BEC_EN_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_CONTROL_RESERVED_MASK (0xFFFFFFF8u)
#define CSL_USB3SS_G_SER_CONTROL_RESERVED_SHIFT (0x00000003u)
#define CSL_USB3SS_G_SER_CONTROL_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_CONTROL_RESETVAL (0x00000000u)

/* SER_STATUS */

#define CSL_USB3SS_G_SER_STATUS_PAR_ERR_MASK (0x00000001u)
#define CSL_USB3SS_G_SER_STATUS_PAR_ERR_SHIFT (0x00000000u)
#define CSL_USB3SS_G_SER_STATUS_PAR_ERR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_BEC_ERR_MASK (0x00000002u)
#define CSL_USB3SS_G_SER_STATUS_BEC_ERR_SHIFT (0x00000001u)
#define CSL_USB3SS_G_SER_STATUS_BEC_ERR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_TYPE_ERR_MASK (0x0000000Cu)
#define CSL_USB3SS_G_SER_STATUS_TYPE_ERR_SHIFT (0x00000002u)
#define CSL_USB3SS_G_SER_STATUS_TYPE_ERR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_BYTE_POS_MASK (0x00000700u)
#define CSL_USB3SS_G_SER_STATUS_BYTE_POS_SHIFT (0x00000008u)
#define CSL_USB3SS_G_SER_STATUS_BYTE_POS_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RESERVED_MASK (0x000000F0u)
#define CSL_USB3SS_G_SER_STATUS_RESERVED_SHIFT (0x00000004u)
#define CSL_USB3SS_G_SER_STATUS_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_ADDR_VALID_MASK (0x00004000u)
#define CSL_USB3SS_G_SER_STATUS_ADDR_VALID_SHIFT (0x0000000Eu)
#define CSL_USB3SS_G_SER_STATUS_ADDR_VALID_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RAM_ERR_MASK (0x0FFF0000u)
#define CSL_USB3SS_G_SER_STATUS_RAM_ERR_SHIFT (0x00000010u)
#define CSL_USB3SS_G_SER_STATUS_RAM_ERR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RESERVED1_MASK (0x00003800u)
#define CSL_USB3SS_G_SER_STATUS_RESERVED1_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_SER_STATUS_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RESERVED3_MASK (0xF0000000u)
#define CSL_USB3SS_G_SER_STATUS_RESERVED3_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_SER_STATUS_RESERVED3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RESERVED2_MASK (0x00008000u)
#define CSL_USB3SS_G_SER_STATUS_RESERVED2_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_SER_STATUS_RESERVED2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_STATUS_RESETVAL (0x00000000u)

/* SER_ADDRESS */

#define CSL_USB3SS_G_SER_ADDRESS_ADDR_ERR_MASK (0xFFFFFFFFu)
#define CSL_USB3SS_G_SER_ADDRESS_ADDR_ERR_SHIFT (0x00000000u)
#define CSL_USB3SS_G_SER_ADDRESS_ADDR_ERR_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_SER_ADDRESS_RESETVAL (0x00000000u)

/* PHY2CONFIG */

#define CSL_USB3SS_G_PHY2CONFIG_PHY2CONFIG_MASK (0xFFFFFFFFu)
#define CSL_USB3SS_G_PHY2CONFIG_PHY2CONFIG_SHIFT (0x00000000u)
#define CSL_USB3SS_G_PHY2CONFIG_PHY2CONFIG_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_PHY2CONFIG_RESETVAL (0x00000000u)

/* PHY3CONFIG */

#define CSL_USB3SS_G_PHY3CONFIG_PHY3CONFIG_MASK (0xFFFFFFFFu)
#define CSL_USB3SS_G_PHY3CONFIG_PHY3CONFIG_SHIFT (0x00000000u)
#define CSL_USB3SS_G_PHY3CONFIG_PHY3CONFIG_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_PHY3CONFIG_RESETVAL (0x00000000u)

/* MMRAM_OFFSET */

#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_MASK (0x000F8000u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_RESETVAL (0x00000000u)
/*----OFFSET_MSB Tokens----*/
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_RAM0_BASE (0x00000008u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_RAM1_BASE (0x00000010u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_RAM2_BASE (0x00000018u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_CORE_BOT (0x00000000u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_MSB_CORE_TOP (0x00000001u)

#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_LSB_MASK (0x00007FFFu)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_LSB_SHIFT (0x00000000u)
#define CSL_USB3SS_G_MMRAM_OFFSET_OFFSET_LSB_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_MMRAM_OFFSET_RESERVED_MASK (0xFFF00000u)
#define CSL_USB3SS_G_MMRAM_OFFSET_RESERVED_SHIFT (0x00000014u)
#define CSL_USB3SS_G_MMRAM_OFFSET_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_MMRAM_OFFSET_RESETVAL (0x00000000u)

/* FLADJ */

#define CSL_USB3SS_G_FLADJ_FLADJ_30MHZ_MASK (0x07E00000u)
#define CSL_USB3SS_G_FLADJ_FLADJ_30MHZ_SHIFT (0x00000015u)
#define CSL_USB3SS_G_FLADJ_FLADJ_30MHZ_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_FLADJ_RESERVED_MASK (0x001FFFFFu)
#define CSL_USB3SS_G_FLADJ_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_FLADJ_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_FLADJ_HOST_U2_PORT_DISABLE_MASK (0x08000000u)
#define CSL_USB3SS_G_FLADJ_HOST_U2_PORT_DISABLE_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_FLADJ_HOST_U2_PORT_DISABLE_RESETVAL (0x00000000u)
/*----HOST_U2_PORT_DISABLE Tokens----*/
#define CSL_USB3SS_G_FLADJ_HOST_U2_PORT_DISABLE_EN (0x00000000u)
#define CSL_USB3SS_G_FLADJ_HOST_U2_PORT_DISABLE_DIS (0x00000001u)

#define CSL_USB3SS_G_FLADJ_HOST_U3_PORT_DISABLE_MASK (0x10000000u)
#define CSL_USB3SS_G_FLADJ_HOST_U3_PORT_DISABLE_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_FLADJ_HOST_U3_PORT_DISABLE_RESETVAL (0x00000000u)
/*----HOST_U3_PORT_DISABLE Tokens----*/
#define CSL_USB3SS_G_FLADJ_HOST_U3_PORT_DISABLE_EN (0x00000000u)
#define CSL_USB3SS_G_FLADJ_HOST_U3_PORT_DISABLE_DIS (0x00000001u)

#define CSL_USB3SS_G_FLADJ_RESERVED1_MASK (0x40000000u)
#define CSL_USB3SS_G_FLADJ_RESERVED1_SHIFT (0x0000001Eu)
#define CSL_USB3SS_G_FLADJ_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_FLADJ_SOFT_RESET_MASK (0x80000000u)
#define CSL_USB3SS_G_FLADJ_SOFT_RESET_SHIFT (0x0000001Fu)
#define CSL_USB3SS_G_FLADJ_SOFT_RESET_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_FLADJ_XHCI_REVISION_MASK (0x20000000u)
#define CSL_USB3SS_G_FLADJ_XHCI_REVISION_SHIFT (0x0000001Du)
#define CSL_USB3SS_G_FLADJ_XHCI_REVISION_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_FLADJ_RESETVAL      (0x00000000u)

/* DEBUG_CFG */

#define CSL_USB3SS_G_DEBUG_CFG_SEL_MASK  (0x00000007u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_SHIFT (0x00000000u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_RESETVAL (0x00000000u)
/*----SEL Tokens----*/
#define CSL_USB3SS_G_DEBUG_CFG_SEL_TIELO (0x00000000u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_UTMI  (0x00000001u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_PIPE  (0x00000002u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_CORE  (0x00000003u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_TRACE_LO (0x00000004u)
#define CSL_USB3SS_G_DEBUG_CFG_SEL_TRACE_HI (0x00000005u)

#define CSL_USB3SS_G_DEBUG_CFG_RESERVED_MASK (0xFFFFFFF8u)
#define CSL_USB3SS_G_DEBUG_CFG_RESERVED_SHIFT (0x00000003u)
#define CSL_USB3SS_G_DEBUG_CFG_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_CFG_RESETVAL  (0x00000000u)

/* DEBUG_DATA */

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG0_MASK (0x00000001u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG0_SHIFT (0x00000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG0_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG1_MASK (0x00000002u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG1_SHIFT (0x00000001u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG2_MASK (0x00000004u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG2_SHIFT (0x00000002u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG2_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG3_MASK (0x00000008u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG3_SHIFT (0x00000003u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG3_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG4_MASK (0x00000010u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG4_SHIFT (0x00000004u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG4_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG5_MASK (0x00000020u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG5_SHIFT (0x00000005u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG5_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG6_MASK (0x00000040u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG6_SHIFT (0x00000006u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG6_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG7_MASK (0x00000080u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG7_SHIFT (0x00000007u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG7_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG8_MASK (0x00000100u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG8_SHIFT (0x00000008u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG8_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG9_MASK (0x00000200u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG9_SHIFT (0x00000009u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG9_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG10_MASK (0x00000400u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG10_SHIFT (0x0000000Au)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG10_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG11_MASK (0x00000800u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG11_SHIFT (0x0000000Bu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG11_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG12_MASK (0x00001000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG12_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG12_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG13_MASK (0x00002000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG13_SHIFT (0x0000000Du)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG13_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG14_MASK (0x00004000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG14_SHIFT (0x0000000Eu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG14_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG15_MASK (0x00008000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG15_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG15_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG16_MASK (0x00010000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG16_SHIFT (0x00000010u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG16_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG17_MASK (0x00020000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG17_SHIFT (0x00000011u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG17_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG18_MASK (0x00040000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG18_SHIFT (0x00000012u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG18_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG19_MASK (0x00080000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG19_SHIFT (0x00000013u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG19_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG20_MASK (0x00100000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG20_SHIFT (0x00000014u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG20_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG21_MASK (0x00200000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG21_SHIFT (0x00000015u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG21_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG22_MASK (0x00400000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG22_SHIFT (0x00000016u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG22_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG23_MASK (0x00800000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG23_SHIFT (0x00000017u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG23_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG24_MASK (0x01000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG24_SHIFT (0x00000018u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG24_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG25_MASK (0x02000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG25_SHIFT (0x00000019u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG25_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG26_MASK (0x04000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG26_SHIFT (0x0000001Au)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG26_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG27_MASK (0x08000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG27_SHIFT (0x0000001Bu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG27_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG28_MASK (0x10000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG28_SHIFT (0x0000001Cu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG28_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG29_MASK (0x20000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG29_SHIFT (0x0000001Du)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG29_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG30_MASK (0x40000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG30_SHIFT (0x0000001Eu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG30_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_DEBUG31_MASK (0x80000000u)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG31_SHIFT (0x0000001Fu)
#define CSL_USB3SS_G_DEBUG_DATA_DEBUG31_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEBUG_DATA_RESETVAL (0x00000000u)

/* DEV_EBC_EN */

#define CSL_USB3SS_G_DEV_EBC_EN_INEP15_MASK (0x00008000u)
#define CSL_USB3SS_G_DEV_EBC_EN_INEP15_SHIFT (0x0000000Fu)
#define CSL_USB3SS_G_DEV_EBC_EN_INEP15_RESETVAL (0x00000000u)
/*----INEP15 Tokens----*/
#define CSL_USB3SS_G_DEV_EBC_EN_INEP15_DIS (0x00000000u)
#define CSL_USB3SS_G_DEV_EBC_EN_INEP15_EN (0x00000001u)

#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED_MASK (0x00007FFFu)
#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED_SHIFT (0x00000000u)
#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED1_MASK (0x7FFF0000u)
#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED1_SHIFT (0x00000010u)
#define CSL_USB3SS_G_DEV_EBC_EN_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_DEV_EBC_EN_OUTEP15_MASK (0x80000000u)
#define CSL_USB3SS_G_DEV_EBC_EN_OUTEP15_SHIFT (0x0000001Fu)
#define CSL_USB3SS_G_DEV_EBC_EN_OUTEP15_RESETVAL (0x00000000u)
/*----OUTEP15 Tokens----*/
#define CSL_USB3SS_G_DEV_EBC_EN_OUTEP15_DIS (0x00000000u)
#define CSL_USB3SS_G_DEV_EBC_EN_OUTEP15_EN (0x00000001u)

#define CSL_USB3SS_G_DEV_EBC_EN_RESETVAL (0x00000000u)

/* HOST_HUB_CTRL */

#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_MASK (0x00000003u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_SHIFT (0x00000000u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_MASK (0x00000004u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_SHIFT (0x00000002u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_MSI_ENABLE_MASK (0x00000008u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_MSI_ENABLE_SHIFT (0x00000003u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HOST_MSI_ENABLE_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_XHC_BME_MASK (0x00000020u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_XHC_BME_SHIFT (0x00000005u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_XHC_BME_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_MASK (0x000000C0u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_SHIFT (0x00000006u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_BUS_FILTER_BYPASS_MASK (0x00000F00u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_BUS_FILTER_BYPASS_SHIFT (0x00000008u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_BUS_FILTER_BYPASS_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED_MASK (0xFFFFF000u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED_SHIFT (0x0000000Cu)
#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED1_MASK (0x00000010u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED1_SHIFT (0x00000004u)
#define CSL_USB3SS_G_HOST_HUB_CTRL_RESERVED1_RESETVAL (0x00000000u)

#define CSL_USB3SS_G_HOST_HUB_CTRL_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
