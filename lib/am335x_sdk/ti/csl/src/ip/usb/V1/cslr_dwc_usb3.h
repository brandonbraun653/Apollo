/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_DWCUSB3_H_
#define CSLR_DWCUSB3_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for Host_Cntrl_Oper_Regs
**************************************************************************/
typedef struct {
    volatile Uint32 USBCMD;
    volatile Uint32 USBSTS;
    volatile Uint32 PAGESIZE;
    volatile Uint8  RSVD0[8];
    volatile Uint32 DNCTRL;
    volatile Uint32 CRCR_LO;
    volatile Uint32 CRCR_HI;
    volatile Uint8  RSVD1[16];
    volatile Uint32 DCBAAP_LO;
    volatile Uint32 DCBAAP_HI;
    volatile Uint32 CONFIG;
    volatile Uint8  RSVD2[964];
} CSL_Dwcusb3Host_cntrl_oper_regsRegs;


/**************************************************************************
* Register Overlay Structure for Host_Cntrl_Port_Reg_Set
**************************************************************************/
typedef struct {
    volatile Uint32 PORTSC1;
    volatile Uint32 PORTPMSC1;
    volatile Uint32 PORTLI1;
    volatile Uint32 PORTHLPMC1;
    volatile Uint32 PORTSC2;
    volatile Uint32 PORTPMSC2;
    volatile Uint32 PORTLI2;
    volatile Uint32 PORTHLPMC2;
} CSL_Dwcusb3Host_cntrl_port_reg_setRegs;


/**************************************************************************
* Register Overlay Structure for Host_Cntrl_Runtime_Regs
**************************************************************************/
typedef struct {
    volatile Uint32 MFINDEX;
    volatile Uint8  RSVD0[28];
} CSL_Dwcusb3Host_cntrl_runtime_regsRegs;


/**************************************************************************
* Register Overlay Structure for Interrupter_array
**************************************************************************/
typedef struct {
    volatile Uint32 IMAN;
    volatile Uint32 IMOD;
    volatile Uint32 ERSTSZ;
    volatile Uint8  RSVD0[4];
    volatile Uint32 ERSTBA_LO;
    volatile Uint32 ERSTBA_HI;
    volatile Uint32 ERDP_LO;
    volatile Uint32 ERDP_HI;
} CSL_Dwcusb3Interrupter_arrayRegs;


/**************************************************************************
* Register Overlay Structure for Doorbell_array
**************************************************************************/
typedef struct {
    volatile Uint32 DB;
} CSL_Dwcusb3Doorbell_arrayRegs;


/**************************************************************************
* Register Overlay Structure for Host_Cntrl_Extended_Cap_Regs
**************************************************************************/
typedef struct {
    volatile Uint32 USBLEGSUP;
    volatile Uint32 USBLEGCTLSTS;
    volatile Uint8  RSVD0[8];
    volatile Uint32 SUPTPRT2_DW0;
    volatile Uint32 SUPTPRT2_DW1;
    volatile Uint32 SUPTPRT2_DW2;
    volatile Uint32 SUPTPRT2_DW3;
    volatile Uint32 SUPTPRT3_DW0;
    volatile Uint32 SUPTPRT3_DW1;
    volatile Uint32 SUPTPRT3_DW2;
    volatile Uint32 SUPTPRT3_DW3;
} CSL_Dwcusb3Host_cntrl_extended_cap_regsRegs;


/**************************************************************************
* Register Overlay Structure for Host_Cntrl_Extended_Cap_Regs_DBC
**************************************************************************/
typedef struct {
    volatile Uint32 DCID;
    volatile Uint32 DCDB;
    volatile Uint32 DCERSTSZ;
    volatile Uint8  RSVD0[4];
    volatile Uint32 DCERSTBA_LO;
    volatile Uint32 DCERSTBA_HI;
    volatile Uint32 DCERDP_LO;
    volatile Uint32 DCERDP_HI;
    volatile Uint32 DCCTRL;
    volatile Uint32 DCST;
    volatile Uint32 DCPORTSC;
    volatile Uint8  RSVD1[4];
    volatile Uint32 DCCP_LO;
    volatile Uint32 DCCP_HI;
    volatile Uint32 DCDDI1;
    volatile Uint32 DCDDI2;
} CSL_Dwcusb3Host_cntrl_extended_cap_regs_dbcRegs;


/**************************************************************************
* Register Overlay Structure for gbl
**************************************************************************/
typedef struct {
    volatile Uint32 GSBUSCFG0;
    volatile Uint32 GSBUSCFG1;
    volatile Uint32 GTXTHRCFG;
    volatile Uint32 GRXTHRCFG;
    volatile Uint32 GCTL;
    volatile Uint8  RSVD0[4];
    volatile Uint32 GSTS;
    volatile Uint8  RSVD1[4];
    volatile Uint32 GSNPSID;
    volatile Uint32 GGPIO;
    volatile Uint32 GUID;
    volatile Uint32 GUCTL;
    volatile Uint32 GBUSERRADDRLO;
    volatile Uint32 GBUSERRADDRHI;
    volatile Uint32 GPRTBIMAPLO;
    volatile Uint32 GPRTBIMAPHI;
    volatile Uint32 GHWPARAMS0;
    volatile Uint32 GHWPARAMS1;
    volatile Uint32 GHWPARAMS2;
    volatile Uint32 GHWPARAMS3;
    volatile Uint32 GHWPARAMS4;
    volatile Uint32 GHWPARAMS5;
    volatile Uint32 GHWPARAMS6;
    volatile Uint32 GHWPARAMS7;
    volatile Uint32 GDBGFIFOSPACE;
    volatile Uint32 GDBGLTSSM;
    volatile Uint32 GDBGLNMCC;
    volatile Uint32 GDBGBMU;
    volatile Uint32 GDBGLSPMUX;
    volatile Uint32 GDBGLSP;
    volatile Uint32 GDBGEPINFO0;
    volatile Uint32 GDBGEPINFO1;
    volatile Uint32 GPRTBIMAP_HSLO;
    volatile Uint32 GPRTBIMAP_HSHI;
    volatile Uint32 GPRTBIMAP_FSLO;
    volatile Uint32 GPRTBIMAP_FSHI;
    volatile Uint8  RSVD2[112];
} CSL_Dwcusb3GblRegs;


/**************************************************************************
* Register Overlay Structure for gbl_usb2phycfg_array
**************************************************************************/
typedef struct {
    volatile Uint32 GUSB2PHYCFG;
} CSL_Dwcusb3Gbl_usb2phycfg_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl_usb2phyacc_array
**************************************************************************/
typedef struct {
    volatile Uint32 GUSB2PHYACC;
} CSL_Dwcusb3Gbl_usb2phyacc_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl_usb3pipectl_array
**************************************************************************/
typedef struct {
    volatile Uint32 GUSB3PIPECTL;
} CSL_Dwcusb3Gbl_usb3pipectl_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl_txfifo_array
**************************************************************************/
typedef struct {
    volatile Uint32 GTXFIFOSIZ0;
    volatile Uint32 GTXFIFOSIZ1;
    volatile Uint32 GTXFIFOSIZ2;
    volatile Uint32 GTXFIFOSIZ3;
    volatile Uint32 GTXFIFOSIZ4;
    volatile Uint32 GTXFIFOSIZ5;
    volatile Uint32 GTXFIFOSIZ6;
    volatile Uint32 GTXFIFOSIZ7;
    volatile Uint32 GTXFIFOSIZ8;
    volatile Uint32 GTXFIFOSIZ9;
    volatile Uint32 GTXFIFOSIZ10;
    volatile Uint32 GTXFIFOSIZ11;
    volatile Uint32 GTXFIFOSIZ12;
    volatile Uint32 GTXFIFOSIZ13;
    volatile Uint32 GTXFIFOSIZ14;
    volatile Uint32 GTXFIFOSIZ15;
} CSL_Dwcusb3Gbl_txfifo_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl_rxfifo_array
**************************************************************************/
typedef struct {
    volatile Uint32 GRXFIFOSIZ0;
    volatile Uint32 GRXFIFOSIZ1;
    volatile Uint32 GRXFIFOSIZ2;
} CSL_Dwcusb3Gbl_rxfifo_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl_evt_array
**************************************************************************/
typedef struct {
    volatile Uint32 GEVNTADRLO;
    volatile Uint32 GEVNTADRHI;
    volatile Uint32 GEVNTSIZ;
    volatile Uint32 GEVNTCOUNT;
} CSL_Dwcusb3Gbl_evt_arrayRegs;


/**************************************************************************
* Register Overlay Structure for gbl2
**************************************************************************/
typedef struct {
    volatile Uint32 GHWPARAMS8;
    volatile Uint32 GHWPARAMS9;
    volatile Uint8  RSVD0[248];
} CSL_Dwcusb3Gbl2Regs;


/**************************************************************************
* Register Overlay Structure for dev
**************************************************************************/
typedef struct {
    volatile Uint32 DCFG;
    volatile Uint32 DCTL;
    volatile Uint32 DEVTEN;
    volatile Uint32 DSTS;
    volatile Uint32 DGCMDPAR;
    volatile Uint32 DGCMD;
    volatile Uint8  RSVD0[8];
    volatile Uint32 DALEPENA;
    volatile Uint8  RSVD1[220];
} CSL_Dwcusb3DevRegs;


/**************************************************************************
* Register Overlay Structure for otg
**************************************************************************/
typedef struct {
    volatile Uint32 OCFG;
    volatile Uint32 OCTL;
    volatile Uint32 OEVT;
    volatile Uint32 OEVTEN;
    volatile Uint32 OSTS;
    volatile Uint8  RSVD0[12];
} CSL_Dwcusb3OtgRegs;


/**************************************************************************
* Register Overlay Structure for adp
**************************************************************************/
typedef struct {
    volatile Uint32 ADPCFG;
    volatile Uint32 ADPCTL;
    volatile Uint32 ADPEVT;
    volatile Uint32 ADPEVTEN;
} CSL_Dwcusb3AdpRegs;


/**************************************************************************
* Register Overlay Structure for bc
**************************************************************************/
typedef struct {
    volatile Uint32 BCFG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 BCEVT;
    volatile Uint32 BCEVTEN;
} CSL_Dwcusb3BcRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 CAPLENGTH;
    volatile Uint32 HCSPARAMS1;
    volatile Uint32 HCSPARAMS2;
    volatile Uint32 HCSPARAMS3;
    volatile Uint32 HCCPARAMS;
    volatile Uint32 DBOFF;
    volatile Uint32 RTSOFF;
    volatile Uint8  RSVD1[4];
    CSL_Dwcusb3Host_cntrl_oper_regsRegs	HOST_CNTRL_OPER_REGS;
    CSL_Dwcusb3Host_cntrl_port_reg_setRegs	HOST_CNTRL_PORT_REG_SET;
    CSL_Dwcusb3Host_cntrl_runtime_regsRegs	HOST_CNTRL_RUNTIME_REGS;
    CSL_Dwcusb3Interrupter_arrayRegs	INTERRUPTER_ARRAY;
    CSL_Dwcusb3Doorbell_arrayRegs	DOORBELL_ARRAY[64];
    volatile Uint8  RSVD2[768];
    CSL_Dwcusb3Host_cntrl_extended_cap_regsRegs	HOST_CNTRL_EXTENDED_CAP_REGS;
    volatile Uint8  RSVD3[47184];
    CSL_Dwcusb3GblRegs	GBL;
    CSL_Dwcusb3Gbl_usb2phycfg_arrayRegs	GBL_USB2PHYCFG_ARRAY;
    volatile Uint8  RSVD4[124];
    CSL_Dwcusb3Gbl_usb2phyacc_arrayRegs	GBL_USB2PHYACC_ARRAY;
    volatile Uint8  RSVD5[60];
    CSL_Dwcusb3Gbl_usb3pipectl_arrayRegs	GBL_USB3PIPECTL_ARRAY;
    volatile Uint8  RSVD6[60];
    CSL_Dwcusb3Gbl_txfifo_arrayRegs	GBL_TXFIFO_ARRAY;
    volatile Uint8  RSVD7[64];
    CSL_Dwcusb3Gbl_rxfifo_arrayRegs	GBL_RXFIFO_ARRAY;
    volatile Uint8  RSVD8[116];
    CSL_Dwcusb3Gbl_evt_arrayRegs	GBL_EVT_ARRAY;
    volatile Uint8  RSVD9[496];
    CSL_Dwcusb3Gbl2Regs	GBL2;
    CSL_Dwcusb3DevRegs	DEV;
    volatile Uint8  RSVD10[1024];
    CSL_Dwcusb3OtgRegs	OTG;
    volatile Uint8  RSVD11[16];
} CSL_DwcUsb3Regs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Capability Registers Length + Host Controller Interface Version number */
#define CSL_DWCUSB3_CAPLENGTH                                   (0x0U)

/* Host Controller Structural Parameters 1 (xHCI) */
#define CSL_DWCUSB3_HCSPARAMS1                                  (0x4U)

/* Host Controller Structural Parameters 2 (xHCI) */
#define CSL_DWCUSB3_HCSPARAMS2                                  (0x8U)

/* Host Controller Structural Parameters 3 (xHCI) */
#define CSL_DWCUSB3_HCSPARAMS3                                  (0xCU)

/* Host Controller Capability Parameters (xHCI) */
#define CSL_DWCUSB3_HCCPARAMS                                   (0x10U)

/* Doorbell Offset (xHCI): Byte offset of doorbell register array (DB[0:N]), 
 * with respect to xHCI base (i.e. CAPLENGTH register) */
#define CSL_DWCUSB3_DBOFF                                       (0x14U)

/* RunTime Space Offset (xHCI): Byte offset of runtime register bank (starting 
 * with MFINDEX), with respect to xHCI base (i.e. CAPLENGTH register) */
#define CSL_DWCUSB3_RTSOFF                                      (0x18U)

/* USB Command Register (xHCI) */
#define CSL_DWCUSB3_USBCMD                                      (0x20U)

/* USB Status Register (xHCI) */
#define CSL_DWCUSB3_USBSTS                                      (0x24U)

/* Page Size Register (xHCI) */
#define CSL_DWCUSB3_PAGESIZE                                    (0x28U)

/* Device Notification Control Register (xHCI) */
#define CSL_DWCUSB3_DNCTRL                                      (0x34U)

/* Command Ring Control Register, lower half (xHCI) */
#define CSL_DWCUSB3_CRCR_LO                                     (0x38U)

/* Command Ring Control Register, upper half (xHCI) */
#define CSL_DWCUSB3_CRCR_HI                                     (0x3CU)

/* Device Context Base Address Array Pointer, lower half (xHCI) */
#define CSL_DWCUSB3_DCBAAP_LO                                   (0x50U)

/* Device Context Base Address Array Pointer, upper half (xHCI) */
#define CSL_DWCUSB3_DCBAAP_HI                                   (0x54U)

/* Configure (xHCI) */
#define CSL_DWCUSB3_CONFIG                                      (0x58U)

/* Port 2 (USB3) Status and Control (xHCI) */
#define CSL_DWCUSB3_PORTSC2                                     (0x430U)

/* Port 2 (USB3) Power Management Status and Control (xHCI) Field structure is 
 * protocol-dependent (here: USB3) */
#define CSL_DWCUSB3_PORTPMSC2                                   (0x434U)

/* Port 2 (USB3) Link Info (xHCI) */
#define CSL_DWCUSB3_PORTLI2                                     (0x438U)

/* Port 2 (USB3) Hardware LPM Control (xHCI) Field structure is 
 * protocol-dependent (here: USB3) */
#define CSL_DWCUSB3_PORTHLPMC2                                  (0x43CU)

/* Port 1 (USB2) Status and Control (xHCI) */
#define CSL_DWCUSB3_PORTSC1                                     (0x420U)

/* Port 1 (USB2) Power Management (LPM) Status and Control (xHCI) Field 
 * structure is protocol-dependent (here: USB2) */
#define CSL_DWCUSB3_PORTPMSC1                                   (0x424U)

/* Port 1 (USB2) Link Info (xHCI) */
#define CSL_DWCUSB3_PORTLI1                                     (0x428U)

/* Port 1 (USB2) Hardware LPM Control (xHCI) Field structure is 
 * protocol-dependent (here: USB2) */
#define CSL_DWCUSB3_PORTHLPMC1                                  (0x42CU)

/* Microframe Index (xHCI) */
#define CSL_DWCUSB3_MFINDEX                                     (0x440U)

/* Interrupter Management (xHCI) */
#define CSL_DWCUSB3_IMAN                                        (0x460U)

/* Interrupter Moderation (xHCI) */
#define CSL_DWCUSB3_IMOD                                        (0x464U)

/* Event Ring Segment Table Size (xHCI) */
#define CSL_DWCUSB3_ERSTSZ                                      (0x468U)

/* Event Ring Segment Table Base Address, lower half (xHCI) */
#define CSL_DWCUSB3_ERSTBA_LO                                   (0x470U)

/* Event Ring Segment Table Base Address, upper half (xHCI) */
#define CSL_DWCUSB3_ERSTBA_HI                                   (0x474U)

/* Event Ring Dequeue Pointer, lower half (xHCI) */
#define CSL_DWCUSB3_ERDP_LO                                     (0x478U)

/* Event Ring Dequeue Pointer, upper half (xHCI) */
#define CSL_DWCUSB3_ERDP_HI                                     (0x47CU)

/* Doorbell (xHCI) */
#define CSL_DWCUSB3_DB(n)                                       (0x480U + ((n) * (0x4U)))

/* USB Legacy Support Capability */
#define CSL_DWCUSB3_USBLEGSUP                                   (0x880U)

/* USB Legacy Control / Status */
#define CSL_DWCUSB3_USBLEGCTLSTS                                (0x884U)

/* Supported protocol capability USB2, 32-bit dword #0 */
#define CSL_DWCUSB3_SUPTPRT2_DW0                                (0x890U)

/* Supported protocol capability USB2, 32-bit dword #1: Name String "USB " */
#define CSL_DWCUSB3_SUPTPRT2_DW1                                (0x894U)

/* Supported protocol capability USB2, 32-bit dword #2 */
#define CSL_DWCUSB3_SUPTPRT2_DW2                                (0x898U)

/* Supported protocol capability USB2, 32-bit dword #3 */
#define CSL_DWCUSB3_SUPTPRT2_DW3                                (0x89CU)

/* Supported protocol capability USB3, 32-bit dword #0 */
#define CSL_DWCUSB3_SUPTPRT3_DW0                                (0x8A0U)

/* Supported protocol capability USB3, 32-bit dword #1: Name String "USB " */
#define CSL_DWCUSB3_SUPTPRT3_DW1                                (0x8A4U)

/* Supported protocol capability USB3, 32-bit dword #2 */
#define CSL_DWCUSB3_SUPTPRT3_DW2                                (0x8A8U)

/* Supported protocol capability USB3, 32-bit dword #3 */
#define CSL_DWCUSB3_SUPTPRT3_DW3                                (0x8ACU)

/* Debug Capability ID (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCID(n)                                     (0x8B0U + ((n) * (0x40U)))

/* Debug Capability Door-Bell (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCDB(n)                                     (0x8B4U + ((n) * (0x40U)))

/* Debug Capability Event Ring Segment Table Size (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCERSTSZ(n)                                 (0x8B8U + ((n) * (0x40U)))

/* Debug Capability Event Ring Segment Table Base Address, low bits (cf. xHCI 
 * 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCERSTBA_LO(n)                              (0x8C0U + ((n) * (0x40U)))

/* Debug Capability Event Ring Segment Table Base Address, high bits (cf. xHCI 
 * 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCERSTBA_HI(n)                              (0x8C4U + ((n) * (0x40U)))

/* Debug Capability Event Ring Dequeue Pointer, low bits (cf. xHCI 1.0 
 * standard, DbC) */
#define CSL_DWCUSB3_DCERDP_LO(n)                                (0x8C8U + ((n) * (0x40U)))

/* Debug Capability Event Ring Dequeue Pointer, high bits (cf. xHCI 1.0 
 * standard, DbC) */
#define CSL_DWCUSB3_DCERDP_HI(n)                                (0x8CCU + ((n) * (0x40U)))

/* Debug Capability Control (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCCTRL(n)                                   (0x8D0U + ((n) * (0x40U)))

/* Debug Capability Status (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCST(n)                                     (0x8D4U + ((n) * (0x40U)))

/* Debug Capability Port Status & Control (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCPORTSC(n)                                 (0x8D8U + ((n) * (0x40U)))

/* Debug Capability Context Pointer, low bits (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCCP_LO(n)                                  (0x8E0U + ((n) * (0x40U)))

/* Debug Capability Context Pointer, high bits (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCCP_HI(n)                                  (0x8E4U + ((n) * (0x40U)))

/* Debug Capability Device Descriptor Info #1 (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCDDI1(n)                                   (0x8E8U + ((n) * (0x40U)))

/* Debug Capability Device Descriptor Info #2 (cf. xHCI 1.0 standard, DbC) */
#define CSL_DWCUSB3_DCDDI2(n)                                   (0x8ECU + ((n) * (0x40U)))

/* Global SoC Bus Configuration Register 0 */
#define CSL_DWCUSB3_GSBUSCFG0                                   (0xC100U)

/* Global SoC Bus Configuration Register 1 */
#define CSL_DWCUSB3_GSBUSCFG1                                   (0xC104U)

/* Global Tx Threshold Control Register. Valid only in Host mode. */
#define CSL_DWCUSB3_GTXTHRCFG                                   (0xC108U)

/* Global Rx Threshold Control Register. Valid only in Host mode. */
#define CSL_DWCUSB3_GRXTHRCFG                                   (0xC10CU)

/* Global Control Register */
#define CSL_DWCUSB3_GCTL                                        (0xC110U)

/* Global Status Register */
#define CSL_DWCUSB3_GSTS                                        (0xC118U)

/* Synopsys ID: Core Identification and Release number. Software uses this 
 * register to configure release-specific features in the driver. */
#define CSL_DWCUSB3_GSNPSID                                     (0xC120U)

/* Global General Purpose Input/Output Register */
#define CSL_DWCUSB3_GGPIO                                       (0xC124U)

/* Global User ID Register */
#define CSL_DWCUSB3_GUID                                        (0xC128U)

/* Global Bus Error (non-precise) Address, LSbits: Base address of the first 
 * system bus DMA transfer that got a bus error. Note that each DMA transfer 
 * can contain several bursts, each spanning several addresses. Valid when 
 * GSTS.BusErrAddrVld=1. Cleared upon core reset. */
#define CSL_DWCUSB3_GBUSERRADDRLO                               (0xC130U)

/* Global Bus Error (non-precise) Address, MSbits: Base address of the first 
 * system bus DMA transfer that got a bus error. Note that each DMA transfer 
 * can contain several bursts, each spanning several addresses. Valid when 
 * GSTS.BusErrAddrVld=1. Cleared upon core reset. */
#define CSL_DWCUSB3_GBUSERRADDRHI                               (0xC134U)

/* Global Port-to-SS USB Instance Mapping, low bits [31:0] */
#define CSL_DWCUSB3_GPRTBIMAPLO                                 (0xC138U)

/* Global Port-to-SS USB Instance Mapping, high bits [63:32] */
#define CSL_DWCUSB3_GPRTBIMAPHI                                 (0xC13CU)

/* Global hardware parameters #0 */
#define CSL_DWCUSB3_GHWPARAMS0                                  (0xC140U)

/* Global hardware parameters #1 */
#define CSL_DWCUSB3_GHWPARAMS1                                  (0xC144U)

/* Global hardware parameters #2 */
#define CSL_DWCUSB3_GHWPARAMS2                                  (0xC148U)

/* Global hardware parameters #3 */
#define CSL_DWCUSB3_GHWPARAMS3                                  (0xC14CU)

/* Global hardware parameters #4 */
#define CSL_DWCUSB3_GHWPARAMS4                                  (0xC150U)

/* Global hardware parameters #5 */
#define CSL_DWCUSB3_GHWPARAMS5                                  (0xC154U)

/* Global hardware parameters #6 */
#define CSL_DWCUSB3_GHWPARAMS6                                  (0xC158U)

/* Global hardware parameters #7 */
#define CSL_DWCUSB3_GHWPARAMS7                                  (0xC15CU)

/* Global Debug FIFO / Queue Space Available */
#define CSL_DWCUSB3_GDBGFIFOSPACE                               (0xC160U)

/* Global Debug LTSSM (Link Training Super-speed State Machine) Port number is 
 * defined by GDBGFIFOSPACE.PortSelect[3:0] */
#define CSL_DWCUSB3_GDBGLTSSM                                   (0xC164U)

/* Global User Control Register */
#define CSL_DWCUSB3_GUCTL                                       (0xC12CU)

/* Global Port to USB Instance Mapping Register, High-Speed, low bits [31:0] */
#define CSL_DWCUSB3_GPRTBIMAP_HSLO                              (0xC180U)

/* Global Port to USB Instance Mapping Register, High-Speed, high bits [63:32] */
#define CSL_DWCUSB3_GPRTBIMAP_HSHI                              (0xC184U)

/* Global Port to USB Instance Mapping Register, Full/low-Speed, low bits 
 * [31:0] */
#define CSL_DWCUSB3_GPRTBIMAP_FSLO                              (0xC188U)

/* Global Port to USB Instance Mapping Register, Full/low-Speed, high bits 
 * [63:32] */
#define CSL_DWCUSB3_GPRTBIMAP_FSHI                              (0xC18CU)

/* Global Debug LSP MUX, for internal use only */
#define CSL_DWCUSB3_GDBGLSPMUX                                  (0xC170U)

/* Global Debug LSP, for internal use only */
#define CSL_DWCUSB3_GDBGLSP                                     (0xC174U)

/* Global Debug Endpoint Information Register 0 */
#define CSL_DWCUSB3_GDBGEPINFO0                                 (0xC178U)

/* Global Debug Endpoint Information Register 1 */
#define CSL_DWCUSB3_GDBGEPINFO1                                 (0xC17CU)

/* Global Debug LNMCC (Link layer /MAC layer Control) */
#define CSL_DWCUSB3_GDBGLNMCC                                   (0xC168U)

/* Global Debug BMU (Buffer Management Unit) */
#define CSL_DWCUSB3_GDBGBMU                                     (0xC16CU)

/* Global USB2 (UTMI/ULPI) PHY configuration */
#define CSL_DWCUSB3_GUSB2PHYCFG                                 (0xC200U)

/* Global USB2 PHY Access */
#define CSL_DWCUSB3_GUSB2PHYACC                                 (0xC280U)

/* Global USB3 PIPE Control */
#define CSL_DWCUSB3_GUSB3PIPECTL                                (0xC2C0U)

/* Global Transmit FIFO Size #0: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ0                                 (0xC300U)

/* Global Transmit FIFO Size #1: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ1                                 (0xC304U)

/* Global Transmit FIFO Size #2: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ2                                 (0xC308U)

/* Global Transmit FIFO Size #3: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ3                                 (0xC30CU)

/* Global Transmit FIFO Size #4: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ4                                 (0xC310U)

/* Global Transmit FIFO Size #5: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ5                                 (0xC314U)

/* Global Transmit FIFO Size #6: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ6                                 (0xC318U)

/* Global Transmit FIFO Size #7: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ7                                 (0xC31CU)

/* Global Transmit FIFO Size #8: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ8                                 (0xC320U)

/* Global Transmit FIFO Size #9: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ9                                 (0xC324U)

/* Global Transmit FIFO Size #10: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ10                                (0xC328U)

/* Global Transmit FIFO Size #11: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ11                                (0xC32CU)

/* Global Transmit FIFO Size #12: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ12                                (0xC330U)

/* Global Transmit FIFO Size #13: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ13                                (0xC334U)

/* Global Transmit FIFO Size #14: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ14                                (0xC338U)

/* Global Transmit FIFO Size #15: FIFO mapping in RAM1, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GTXFIFOSIZ15                                (0xC33CU)

/* Global Receive FIFO Size #0: FIFO mapping in RAM0, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GRXFIFOSIZ0                                 (0xC380U)

/* Global Receive FIFO Size #1: FIFO mapping in RAM0, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GRXFIFOSIZ1                                 (0xC384U)

/* Global Receive FIFO Size #2: FIFO mapping in RAM0, from staddr to 
 * (staddr+dep-1) */
#define CSL_DWCUSB3_GRXFIFOSIZ2                                 (0xC388U)

/* Global Event Address: Lower 32 bits of start address of the external memory 
 * for the Event Buffer. During operation, hardware does not update this 
 * address. */
#define CSL_DWCUSB3_GEVNTADRLO                                  (0xC400U)

/* Global Event Address: Upper 32 bits of start address of the external memory 
 * for the Event Buffer. During operation, hardware does not update this 
 * address. */
#define CSL_DWCUSB3_GEVNTADRHI                                  (0xC404U)

/* Global Event Buffer Size */
#define CSL_DWCUSB3_GEVNTSIZ                                    (0xC408U)

/* Global Event Buffer Count */
#define CSL_DWCUSB3_GEVNTCOUNT                                  (0xC40CU)

/* Global hardware parameters #8 */
#define CSL_DWCUSB3_GHWPARAMS8                                  (0xC600U)

/* Global hardware parameters #9 */
#define CSL_DWCUSB3_GHWPARAMS9                                  (0xC604U)

/* Device Configuration: configures the core in Device mode after power-on or 
 * after certain control commands or enumeration. Do not change after initial 
 * programming. */
#define CSL_DWCUSB3_DCFG                                        (0xC700U)

/* Device Control. */
#define CSL_DWCUSB3_DCTL                                        (0xC704U)

/* Device Event Enable: enables the generation of Device-Specific events (see 
 * DEVT) */
#define CSL_DWCUSB3_DEVTEN                                      (0xC708U)

/* Device Status: */
#define CSL_DWCUSB3_DSTS                                        (0xC70CU)

/* Device Generic Command Parameter: To be programmed before or along with the 
 * device command itself. */
#define CSL_DWCUSB3_DGCMDPAR                                    (0xC710U)

/* Device Generic Command: generic command interface to send link management 
 * packets and notifications. */
#define CSL_DWCUSB3_DGCMD                                       (0xC714U)

/* Device Active USB Endpoint Enable. Set each bit (1) to enable the 
 * corresponding endpoint. Bits 0 and 1 shall be set after USB reset, as they 
 * enable the control endpoint. All other bits shall be set according to 
 * enumeration, and cleared upon a USB reset. */
#define CSL_DWCUSB3_DALEPENA                                    (0xC720U)

/* OTG Event: OTG interrupt status. All writable bits are cleared by writing a 
 * 1. */
#define CSL_DWCUSB3_OEVT                                        (0xCC08U)

/* OTG Event Enable: OTG interrupt event enable. */
#define CSL_DWCUSB3_OEVTEN                                      (0xCC0CU)

/* OTG status. */
#define CSL_DWCUSB3_OSTS                                        (0xCC10U)

/* OTG configuration. */
#define CSL_DWCUSB3_OCFG                                        (0xCC00U)

/* OTG control. IMPORTANT NOTE: register is reinitialized upon ID change, but 
 * is not affected by a software reset. */
#define CSL_DWCUSB3_OCTL                                        (0xCC04U)

/* ADP Configuration Register */
#define CSL_DWCUSB3_ADPCFG(n)                                   (0xCC20U + ((n) * (0x10U)))

/* ADP Control Register */
#define CSL_DWCUSB3_ADPCTL(n)                                   (0xCC24U + ((n) * (0x10U)))

/* ADP Event Register Writing 1 to the info bit in this register clears the 
 * register bit and associated ADP interrupt */
#define CSL_DWCUSB3_ADPEVT(n)                                   (0xCC28U + ((n) * (0x10U)))

/* ADP Event Enable Register */
#define CSL_DWCUSB3_ADPEVTEN(n)                                 (0xCC2CU + ((n) * (0x10U)))

/* Battery Charger Control Register Writing 1 to the control bit in this 
 * register sets the corresponding register bit */
#define CSL_DWCUSB3_BCFG(n)                                     (0xCC30U + ((n) * (0x10U)))

/* Battery Charger Event Register Writing 1 to the info bit in this register 
 * clears the register bit and associated interrupt */
#define CSL_DWCUSB3_BCEVT(n)                                    (0xCC38U + ((n) * (0x10U)))

/* Battery Charger Event Enable Register */
#define CSL_DWCUSB3_BCEVTEN(n)                                  (0xCC3CU + ((n) * (0x10U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CAPLENGTH */

#define CSL_DWCUSB3_CAPLENGTH_CAPLENGTH_MASK                    (0x000000FFU)
#define CSL_DWCUSB3_CAPLENGTH_CAPLENGTH_SHIFT                   (0U)
#define CSL_DWCUSB3_CAPLENGTH_CAPLENGTH_RESETVAL                (0x00000020U)
#define CSL_DWCUSB3_CAPLENGTH_CAPLENGTH_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_CAPLENGTH_HCIVERSION_MASK                   (0xFFFF0000U)
#define CSL_DWCUSB3_CAPLENGTH_HCIVERSION_SHIFT                  (16U)
#define CSL_DWCUSB3_CAPLENGTH_HCIVERSION_RESETVAL               (0x00000100U)
#define CSL_DWCUSB3_CAPLENGTH_HCIVERSION_MAX                    (0x0000ffffU)

#define CSL_DWCUSB3_CAPLENGTH_RESETVAL                          (0x01000020U)

/* HCSPARAMS1 */

#define CSL_DWCUSB3_HCSPARAMS1_MAXSLOTS_MASK                    (0x000000FFU)
#define CSL_DWCUSB3_HCSPARAMS1_MAXSLOTS_SHIFT                   (0U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXSLOTS_RESETVAL                (0x00000040U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXSLOTS_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_HCSPARAMS1_MAXINTRS_MASK                    (0x0007FF00U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXINTRS_SHIFT                   (8U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXINTRS_RESETVAL                (0x00000001U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXINTRS_MAX                     (0x000007ffU)

#define CSL_DWCUSB3_HCSPARAMS1_MAXPORTS_MASK                    (0xFF000000U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXPORTS_SHIFT                   (24U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXPORTS_RESETVAL                (0x00000002U)
#define CSL_DWCUSB3_HCSPARAMS1_MAXPORTS_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_HCSPARAMS1_RESETVAL                         (0x02000140U)

/* HCSPARAMS2 */

#define CSL_DWCUSB3_HCSPARAMS2_IST_MASK                         (0x0000000FU)
#define CSL_DWCUSB3_HCSPARAMS2_IST_SHIFT                        (0U)
#define CSL_DWCUSB3_HCSPARAMS2_IST_RESETVAL                     (0x00000001U)
#define CSL_DWCUSB3_HCSPARAMS2_IST_MAX                          (0x0000000fU)

#define CSL_DWCUSB3_HCSPARAMS2_ERSTMAX_MASK                     (0x000000F0U)
#define CSL_DWCUSB3_HCSPARAMS2_ERSTMAX_SHIFT                    (4U)
#define CSL_DWCUSB3_HCSPARAMS2_ERSTMAX_RESETVAL                 (0x0000000fU)
#define CSL_DWCUSB3_HCSPARAMS2_ERSTMAX_MAX                      (0x0000000fU)

#define CSL_DWCUSB3_HCSPARAMS2_SPR_MASK                         (0x04000000U)
#define CSL_DWCUSB3_HCSPARAMS2_SPR_SHIFT                        (26U)
#define CSL_DWCUSB3_HCSPARAMS2_SPR_RESETVAL                     (0x00000001U)
#define CSL_DWCUSB3_HCSPARAMS2_SPR_NO                           (0x00000000U)
#define CSL_DWCUSB3_HCSPARAMS2_SPR_YES                          (0x00000001U)

#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_MASK        (0xF8000000U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_SHIFT       (27U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_RESETVAL    (0x00000001U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_MAX         (0x0000001fU)

#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK        (0x03E00000U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT       (21U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_RESETVAL    (0x00000000U)
#define CSL_DWCUSB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MAX         (0x0000001fU)

#define CSL_DWCUSB3_HCSPARAMS2_RESETVAL                         (0x0c0000f1U)

/* HCSPARAMS3 */

#define CSL_DWCUSB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK          (0x000000FFU)
#define CSL_DWCUSB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT         (0U)
#define CSL_DWCUSB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_RESETVAL      (0x0000000aU)
#define CSL_DWCUSB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MAX           (0x000000ffU)

#define CSL_DWCUSB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK          (0xFFFF0000U)
#define CSL_DWCUSB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT         (16U)
#define CSL_DWCUSB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_RESETVAL      (0x000007ffU)
#define CSL_DWCUSB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MAX           (0x0000ffffU)

#define CSL_DWCUSB3_HCSPARAMS3_RESETVAL                         (0x07ff000aU)

/* HCCPARAMS */

#define CSL_DWCUSB3_HCCPARAMS_AC64_MASK                         (0x00000001U)
#define CSL_DWCUSB3_HCCPARAMS_AC64_SHIFT                        (0U)
#define CSL_DWCUSB3_HCCPARAMS_AC64_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_AC64_MAX                          (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_BNC_MASK                          (0x00000002U)
#define CSL_DWCUSB3_HCCPARAMS_BNC_SHIFT                         (1U)
#define CSL_DWCUSB3_HCCPARAMS_BNC_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_BNC_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_CSZ_MASK                          (0x00000004U)
#define CSL_DWCUSB3_HCCPARAMS_CSZ_SHIFT                         (2U)
#define CSL_DWCUSB3_HCCPARAMS_CSZ_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_HCCPARAMS_CSZ_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_PPC_MASK                          (0x00000008U)
#define CSL_DWCUSB3_HCCPARAMS_PPC_SHIFT                         (3U)
#define CSL_DWCUSB3_HCCPARAMS_PPC_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_HCCPARAMS_PPC_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_PIND_MASK                         (0x00000010U)
#define CSL_DWCUSB3_HCCPARAMS_PIND_SHIFT                        (4U)
#define CSL_DWCUSB3_HCCPARAMS_PIND_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_PIND_MAX                          (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_LHRC_MASK                         (0x00000020U)
#define CSL_DWCUSB3_HCCPARAMS_LHRC_SHIFT                        (5U)
#define CSL_DWCUSB3_HCCPARAMS_LHRC_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_LHRC_MAX                          (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_LTC_MASK                          (0x00000040U)
#define CSL_DWCUSB3_HCCPARAMS_LTC_SHIFT                         (6U)
#define CSL_DWCUSB3_HCCPARAMS_LTC_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_HCCPARAMS_LTC_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_NSS_MASK                          (0x00000080U)
#define CSL_DWCUSB3_HCCPARAMS_NSS_SHIFT                         (7U)
#define CSL_DWCUSB3_HCCPARAMS_NSS_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_NSS_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_MAXPSASIZE_MASK                   (0x0000F000U)
#define CSL_DWCUSB3_HCCPARAMS_MAXPSASIZE_SHIFT                  (12U)
#define CSL_DWCUSB3_HCCPARAMS_MAXPSASIZE_RESETVAL               (0x0000000fU)
#define CSL_DWCUSB3_HCCPARAMS_MAXPSASIZE_MAX                    (0x0000000fU)

#define CSL_DWCUSB3_HCCPARAMS_XECP_MASK                         (0xFFFF0000U)
#define CSL_DWCUSB3_HCCPARAMS_XECP_SHIFT                        (16U)
#define CSL_DWCUSB3_HCCPARAMS_XECP_RESETVAL                     (0x00000220U)
#define CSL_DWCUSB3_HCCPARAMS_XECP_MAX                          (0x0000ffffU)

#define CSL_DWCUSB3_HCCPARAMS_PAE_MASK                          (0x00000100U)
#define CSL_DWCUSB3_HCCPARAMS_PAE_SHIFT                         (8U)
#define CSL_DWCUSB3_HCCPARAMS_PAE_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_HCCPARAMS_PAE_MAX                           (0x00000001U)

#define CSL_DWCUSB3_HCCPARAMS_RESETVAL                          (0x0220f04cU)

/* DBOFF */

#define CSL_DWCUSB3_DBOFF_DOORBELL_ARRAY_OFFSET_MASK            (0xFFFFFFFCU)
#define CSL_DWCUSB3_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT           (2U)
#define CSL_DWCUSB3_DBOFF_DOORBELL_ARRAY_OFFSET_RESETVAL        (0x00000120U)
#define CSL_DWCUSB3_DBOFF_DOORBELL_ARRAY_OFFSET_MAX             (0x3fffffffU)

#define CSL_DWCUSB3_DBOFF_ZERO_MASK                             (0x00000003U)
#define CSL_DWCUSB3_DBOFF_ZERO_SHIFT                            (0U)
#define CSL_DWCUSB3_DBOFF_ZERO_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DBOFF_ZERO_MAX                              (0x00000003U)

#define CSL_DWCUSB3_DBOFF_RESETVAL                              (0x00000480U)

/* RTSOFF */

#define CSL_DWCUSB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK        (0xFFFFFFE0U)
#define CSL_DWCUSB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT       (5U)
#define CSL_DWCUSB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_RESETVAL    (0x00000022U)
#define CSL_DWCUSB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MAX         (0x07ffffffU)

#define CSL_DWCUSB3_RTSOFF_ZERO_MASK                            (0x0000001FU)
#define CSL_DWCUSB3_RTSOFF_ZERO_SHIFT                           (0U)
#define CSL_DWCUSB3_RTSOFF_ZERO_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_RTSOFF_ZERO_MAX                             (0x0000001fU)

#define CSL_DWCUSB3_RTSOFF_RESETVAL                             (0x00000440U)

/* USBCMD */

#define CSL_DWCUSB3_USBCMD_R_S_MASK                             (0x00000001U)
#define CSL_DWCUSB3_USBCMD_R_S_SHIFT                            (0U)
#define CSL_DWCUSB3_USBCMD_R_S_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBCMD_R_S_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBCMD_HCRST_MASK                           (0x00000002U)
#define CSL_DWCUSB3_USBCMD_HCRST_SHIFT                          (1U)
#define CSL_DWCUSB3_USBCMD_HCRST_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_USBCMD_HCRST_MAX                            (0x00000001U)

#define CSL_DWCUSB3_USBCMD_INTE_MASK                            (0x00000004U)
#define CSL_DWCUSB3_USBCMD_INTE_SHIFT                           (2U)
#define CSL_DWCUSB3_USBCMD_INTE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_USBCMD_INTE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_USBCMD_HSEE_MASK                            (0x00000008U)
#define CSL_DWCUSB3_USBCMD_HSEE_SHIFT                           (3U)
#define CSL_DWCUSB3_USBCMD_HSEE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_USBCMD_HSEE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_USBCMD_LHCRST_MASK                          (0x00000080U)
#define CSL_DWCUSB3_USBCMD_LHCRST_SHIFT                         (7U)
#define CSL_DWCUSB3_USBCMD_LHCRST_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_USBCMD_LHCRST_MAX                           (0x00000001U)

#define CSL_DWCUSB3_USBCMD_CSS_MASK                             (0x00000100U)
#define CSL_DWCUSB3_USBCMD_CSS_SHIFT                            (8U)
#define CSL_DWCUSB3_USBCMD_CSS_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBCMD_CSS_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBCMD_CRS_MASK                             (0x00000200U)
#define CSL_DWCUSB3_USBCMD_CRS_SHIFT                            (9U)
#define CSL_DWCUSB3_USBCMD_CRS_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBCMD_CRS_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBCMD_EWE_MASK                             (0x00000400U)
#define CSL_DWCUSB3_USBCMD_EWE_SHIFT                            (10U)
#define CSL_DWCUSB3_USBCMD_EWE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBCMD_EWE_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBCMD_EU3S_MASK                            (0x00000800U)
#define CSL_DWCUSB3_USBCMD_EU3S_SHIFT                           (11U)
#define CSL_DWCUSB3_USBCMD_EU3S_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_USBCMD_EU3S_MAX                             (0x00000001U)

#define CSL_DWCUSB3_USBCMD_RESETVAL                             (0x00000000U)

/* USBSTS */

#define CSL_DWCUSB3_USBSTS_HCH_MASK                             (0x00000001U)
#define CSL_DWCUSB3_USBSTS_HCH_SHIFT                            (0U)
#define CSL_DWCUSB3_USBSTS_HCH_RESETVAL                         (0x00000001U)
#define CSL_DWCUSB3_USBSTS_HCH_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_HSE_MASK                             (0x00000004U)
#define CSL_DWCUSB3_USBSTS_HSE_SHIFT                            (2U)
#define CSL_DWCUSB3_USBSTS_HSE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_HSE_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_EINT_MASK                            (0x00000008U)
#define CSL_DWCUSB3_USBSTS_EINT_SHIFT                           (3U)
#define CSL_DWCUSB3_USBSTS_EINT_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_USBSTS_EINT_MAX                             (0x00000001U)

#define CSL_DWCUSB3_USBSTS_PCD_MASK                             (0x00000010U)
#define CSL_DWCUSB3_USBSTS_PCD_SHIFT                            (4U)
#define CSL_DWCUSB3_USBSTS_PCD_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_PCD_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_SSS_MASK                             (0x00000100U)
#define CSL_DWCUSB3_USBSTS_SSS_SHIFT                            (8U)
#define CSL_DWCUSB3_USBSTS_SSS_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_SSS_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_RSS_MASK                             (0x00000200U)
#define CSL_DWCUSB3_USBSTS_RSS_SHIFT                            (9U)
#define CSL_DWCUSB3_USBSTS_RSS_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_RSS_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_SRE_MASK                             (0x00000400U)
#define CSL_DWCUSB3_USBSTS_SRE_SHIFT                            (10U)
#define CSL_DWCUSB3_USBSTS_SRE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_SRE_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_CNR_MASK                             (0x00000800U)
#define CSL_DWCUSB3_USBSTS_CNR_SHIFT                            (11U)
#define CSL_DWCUSB3_USBSTS_CNR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_CNR_READY                            (0x00000000U)
#define CSL_DWCUSB3_USBSTS_CNR_NOTREADY                         (0x00000001U)

#define CSL_DWCUSB3_USBSTS_HCE_MASK                             (0x00001000U)
#define CSL_DWCUSB3_USBSTS_HCE_SHIFT                            (12U)
#define CSL_DWCUSB3_USBSTS_HCE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_USBSTS_HCE_MAX                              (0x00000001U)

#define CSL_DWCUSB3_USBSTS_RESETVAL                             (0x00000001U)

/* PAGESIZE */

#define CSL_DWCUSB3_PAGESIZE_PAGE_SIZE_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_PAGESIZE_PAGE_SIZE_SHIFT                    (0U)
#define CSL_DWCUSB3_PAGESIZE_PAGE_SIZE_RESETVAL                 (0x00000001U)
#define CSL_DWCUSB3_PAGESIZE_PAGE_SIZE_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_PAGESIZE_RESETVAL                           (0x00000001U)

/* DNCTRL */

#define CSL_DWCUSB3_DNCTRL_N0_MASK                              (0x00000001U)
#define CSL_DWCUSB3_DNCTRL_N0_SHIFT                             (0U)
#define CSL_DWCUSB3_DNCTRL_N0_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N0_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N1_MASK                              (0x00000002U)
#define CSL_DWCUSB3_DNCTRL_N1_SHIFT                             (1U)
#define CSL_DWCUSB3_DNCTRL_N1_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N1_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N2_MASK                              (0x00000004U)
#define CSL_DWCUSB3_DNCTRL_N2_SHIFT                             (2U)
#define CSL_DWCUSB3_DNCTRL_N2_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N2_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N3_MASK                              (0x00000008U)
#define CSL_DWCUSB3_DNCTRL_N3_SHIFT                             (3U)
#define CSL_DWCUSB3_DNCTRL_N3_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N3_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N4_MASK                              (0x00000010U)
#define CSL_DWCUSB3_DNCTRL_N4_SHIFT                             (4U)
#define CSL_DWCUSB3_DNCTRL_N4_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N4_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N5_MASK                              (0x00000020U)
#define CSL_DWCUSB3_DNCTRL_N5_SHIFT                             (5U)
#define CSL_DWCUSB3_DNCTRL_N5_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N5_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N6_MASK                              (0x00000040U)
#define CSL_DWCUSB3_DNCTRL_N6_SHIFT                             (6U)
#define CSL_DWCUSB3_DNCTRL_N6_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N6_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N7_MASK                              (0x00000080U)
#define CSL_DWCUSB3_DNCTRL_N7_SHIFT                             (7U)
#define CSL_DWCUSB3_DNCTRL_N7_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N7_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N8_MASK                              (0x00000100U)
#define CSL_DWCUSB3_DNCTRL_N8_SHIFT                             (8U)
#define CSL_DWCUSB3_DNCTRL_N8_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N8_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N9_MASK                              (0x00000200U)
#define CSL_DWCUSB3_DNCTRL_N9_SHIFT                             (9U)
#define CSL_DWCUSB3_DNCTRL_N9_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N9_MAX                               (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N10_MASK                             (0x00000400U)
#define CSL_DWCUSB3_DNCTRL_N10_SHIFT                            (10U)
#define CSL_DWCUSB3_DNCTRL_N10_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N10_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N11_MASK                             (0x00000800U)
#define CSL_DWCUSB3_DNCTRL_N11_SHIFT                            (11U)
#define CSL_DWCUSB3_DNCTRL_N11_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N11_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N12_MASK                             (0x00001000U)
#define CSL_DWCUSB3_DNCTRL_N12_SHIFT                            (12U)
#define CSL_DWCUSB3_DNCTRL_N12_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N12_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N13_MASK                             (0x00002000U)
#define CSL_DWCUSB3_DNCTRL_N13_SHIFT                            (13U)
#define CSL_DWCUSB3_DNCTRL_N13_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N13_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N14_MASK                             (0x00004000U)
#define CSL_DWCUSB3_DNCTRL_N14_SHIFT                            (14U)
#define CSL_DWCUSB3_DNCTRL_N14_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N14_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_N15_MASK                             (0x00008000U)
#define CSL_DWCUSB3_DNCTRL_N15_SHIFT                            (15U)
#define CSL_DWCUSB3_DNCTRL_N15_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DNCTRL_N15_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DNCTRL_RESETVAL                             (0x00000000U)

/* CRCR_LO */

#define CSL_DWCUSB3_CRCR_LO_RCS_MASK                            (0x00000001U)
#define CSL_DWCUSB3_CRCR_LO_RCS_SHIFT                           (0U)
#define CSL_DWCUSB3_CRCR_LO_RCS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_CRCR_LO_RCS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_CRCR_LO_CS_MASK                             (0x00000002U)
#define CSL_DWCUSB3_CRCR_LO_CS_SHIFT                            (1U)
#define CSL_DWCUSB3_CRCR_LO_CS_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_CRCR_LO_CS_MAX                              (0x00000001U)

#define CSL_DWCUSB3_CRCR_LO_CA_MASK                             (0x00000004U)
#define CSL_DWCUSB3_CRCR_LO_CA_SHIFT                            (2U)
#define CSL_DWCUSB3_CRCR_LO_CA_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_CRCR_LO_CA_MAX                              (0x00000001U)

#define CSL_DWCUSB3_CRCR_LO_CRR_MASK                            (0x00000008U)
#define CSL_DWCUSB3_CRCR_LO_CRR_SHIFT                           (3U)
#define CSL_DWCUSB3_CRCR_LO_CRR_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_CRCR_LO_CRR_MAX                             (0x00000001U)

#define CSL_DWCUSB3_CRCR_LO_CMD_RING_PNTR_MASK                  (0xFFFFFFC0U)
#define CSL_DWCUSB3_CRCR_LO_CMD_RING_PNTR_SHIFT                 (6U)
#define CSL_DWCUSB3_CRCR_LO_CMD_RING_PNTR_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_CRCR_LO_CMD_RING_PNTR_MAX                   (0x03ffffffU)

#define CSL_DWCUSB3_CRCR_LO_RESETVAL                            (0x00000000U)

/* CRCR_HI */

#define CSL_DWCUSB3_CRCR_HI_CMD_RING_PNTR_MASK                  (0xFFFFFFFFU)
#define CSL_DWCUSB3_CRCR_HI_CMD_RING_PNTR_SHIFT                 (0U)
#define CSL_DWCUSB3_CRCR_HI_CMD_RING_PNTR_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_CRCR_HI_CMD_RING_PNTR_MAX                   (0xffffffffU)

#define CSL_DWCUSB3_CRCR_HI_RESETVAL                            (0x00000000U)

/* DCBAAP_LO */

#define CSL_DWCUSB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK          (0xFFFFFFC0U)
#define CSL_DWCUSB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT         (6U)
#define CSL_DWCUSB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_RESETVAL      (0x00000000U)
#define CSL_DWCUSB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MAX           (0x03ffffffU)

#define CSL_DWCUSB3_DCBAAP_LO_RESETVAL                          (0x00000000U)

/* DCBAAP_HI */

#define CSL_DWCUSB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK          (0xFFFFFFFFU)
#define CSL_DWCUSB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT         (0U)
#define CSL_DWCUSB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_RESETVAL      (0x00000000U)
#define CSL_DWCUSB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MAX           (0xffffffffU)

#define CSL_DWCUSB3_DCBAAP_HI_RESETVAL                          (0x00000000U)

/* CONFIG */

#define CSL_DWCUSB3_CONFIG_MAXSLOTSEN_MASK                      (0x000000FFU)
#define CSL_DWCUSB3_CONFIG_MAXSLOTSEN_SHIFT                     (0U)
#define CSL_DWCUSB3_CONFIG_MAXSLOTSEN_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_CONFIG_MAXSLOTSEN_MAX                       (0x000000ffU)

#define CSL_DWCUSB3_CONFIG_RESETVAL                             (0x00000000U)

/* PORTSC2 */

#define CSL_DWCUSB3_PORTSC2_CCS_MASK                            (0x00000001U)
#define CSL_DWCUSB3_PORTSC2_CCS_SHIFT                           (0U)
#define CSL_DWCUSB3_PORTSC2_CCS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_CCS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PED_MASK                            (0x00000002U)
#define CSL_DWCUSB3_PORTSC2_PED_SHIFT                           (1U)
#define CSL_DWCUSB3_PORTSC2_PED_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PED_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_OCA_MASK                            (0x00000008U)
#define CSL_DWCUSB3_PORTSC2_OCA_SHIFT                           (3U)
#define CSL_DWCUSB3_PORTSC2_OCA_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_OCA_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PR_MASK                             (0x00000010U)
#define CSL_DWCUSB3_PORTSC2_PR_SHIFT                            (4U)
#define CSL_DWCUSB3_PORTSC2_PR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PR_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PLS_MASK                            (0x000001E0U)
#define CSL_DWCUSB3_PORTSC2_PLS_SHIFT                           (5U)
#define CSL_DWCUSB3_PORTSC2_PLS_RESETVAL                        (0x00000004U)
#define CSL_DWCUSB3_PORTSC2_PLS_MAX                             (0x0000000fU)

#define CSL_DWCUSB3_PORTSC2_PP_MASK                             (0x00000200U)
#define CSL_DWCUSB3_PORTSC2_PP_SHIFT                            (9U)
#define CSL_DWCUSB3_PORTSC2_PP_RESETVAL                         (0x00000001U)
#define CSL_DWCUSB3_PORTSC2_PP_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PORTSPEED_MASK                      (0x00003C00U)
#define CSL_DWCUSB3_PORTSC2_PORTSPEED_SHIFT                     (10U)
#define CSL_DWCUSB3_PORTSC2_PORTSPEED_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PORTSPEED_MAX                       (0x0000000fU)

#define CSL_DWCUSB3_PORTSC2_PIC_MASK                            (0x0000C000U)
#define CSL_DWCUSB3_PORTSC2_PIC_SHIFT                           (14U)
#define CSL_DWCUSB3_PORTSC2_PIC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PIC_MAX                             (0x00000003U)

#define CSL_DWCUSB3_PORTSC2_LWS_MASK                            (0x00010000U)
#define CSL_DWCUSB3_PORTSC2_LWS_SHIFT                           (16U)
#define CSL_DWCUSB3_PORTSC2_LWS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_LWS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_CSC_MASK                            (0x00020000U)
#define CSL_DWCUSB3_PORTSC2_CSC_SHIFT                           (17U)
#define CSL_DWCUSB3_PORTSC2_CSC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_CSC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PEC_MASK                            (0x00040000U)
#define CSL_DWCUSB3_PORTSC2_PEC_SHIFT                           (18U)
#define CSL_DWCUSB3_PORTSC2_PEC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PEC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_WRC_MASK                            (0x00080000U)
#define CSL_DWCUSB3_PORTSC2_WRC_SHIFT                           (19U)
#define CSL_DWCUSB3_PORTSC2_WRC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_WRC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_OCC_MASK                            (0x00100000U)
#define CSL_DWCUSB3_PORTSC2_OCC_SHIFT                           (20U)
#define CSL_DWCUSB3_PORTSC2_OCC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_OCC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PRC_MASK                            (0x00200000U)
#define CSL_DWCUSB3_PORTSC2_PRC_SHIFT                           (21U)
#define CSL_DWCUSB3_PORTSC2_PRC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PRC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_PLC_MASK                            (0x00400000U)
#define CSL_DWCUSB3_PORTSC2_PLC_SHIFT                           (22U)
#define CSL_DWCUSB3_PORTSC2_PLC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_PLC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_CEC_MASK                            (0x00800000U)
#define CSL_DWCUSB3_PORTSC2_CEC_SHIFT                           (23U)
#define CSL_DWCUSB3_PORTSC2_CEC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_CEC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_WCE_MASK                            (0x02000000U)
#define CSL_DWCUSB3_PORTSC2_WCE_SHIFT                           (25U)
#define CSL_DWCUSB3_PORTSC2_WCE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_WCE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_WDE_MASK                            (0x04000000U)
#define CSL_DWCUSB3_PORTSC2_WDE_SHIFT                           (26U)
#define CSL_DWCUSB3_PORTSC2_WDE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_WDE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_WOE_MASK                            (0x08000000U)
#define CSL_DWCUSB3_PORTSC2_WOE_SHIFT                           (27U)
#define CSL_DWCUSB3_PORTSC2_WOE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_WOE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_DR_MASK                             (0x40000000U)
#define CSL_DWCUSB3_PORTSC2_DR_SHIFT                            (30U)
#define CSL_DWCUSB3_PORTSC2_DR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_DR_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_WPR_MASK                            (0x80000000U)
#define CSL_DWCUSB3_PORTSC2_WPR_SHIFT                           (31U)
#define CSL_DWCUSB3_PORTSC2_WPR_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_WPR_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_CAS_MASK                            (0x01000000U)
#define CSL_DWCUSB3_PORTSC2_CAS_SHIFT                           (24U)
#define CSL_DWCUSB3_PORTSC2_CAS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC2_CAS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC2_RESETVAL                            (0x00000280U)

/* PORTPMSC2 */

#define CSL_DWCUSB3_PORTPMSC2_U1_TIMEOUT_MASK                   (0x000000FFU)
#define CSL_DWCUSB3_PORTPMSC2_U1_TIMEOUT_SHIFT                  (0U)
#define CSL_DWCUSB3_PORTPMSC2_U1_TIMEOUT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC2_U1_TIMEOUT_MAX                    (0x000000ffU)

#define CSL_DWCUSB3_PORTPMSC2_U2_TIMEOUT_MASK                   (0x0000FF00U)
#define CSL_DWCUSB3_PORTPMSC2_U2_TIMEOUT_SHIFT                  (8U)
#define CSL_DWCUSB3_PORTPMSC2_U2_TIMEOUT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC2_U2_TIMEOUT_MAX                    (0x000000ffU)

#define CSL_DWCUSB3_PORTPMSC2_FLA_MASK                          (0x00010000U)
#define CSL_DWCUSB3_PORTPMSC2_FLA_SHIFT                         (16U)
#define CSL_DWCUSB3_PORTPMSC2_FLA_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC2_FLA_MAX                           (0x00000001U)

#define CSL_DWCUSB3_PORTPMSC2_RESETVAL                          (0x00000000U)

/* PORTLI2 */

#define CSL_DWCUSB3_PORTLI2_LINK_ERROR_COUNT_MASK               (0x0000FFFFU)
#define CSL_DWCUSB3_PORTLI2_LINK_ERROR_COUNT_SHIFT              (0U)
#define CSL_DWCUSB3_PORTLI2_LINK_ERROR_COUNT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_PORTLI2_LINK_ERROR_COUNT_MAX                (0x0000ffffU)

#define CSL_DWCUSB3_PORTLI2_RESETVAL                            (0x00000000U)

/* PORTHLPMC2 */

#define CSL_DWCUSB3_PORTHLPMC2_RESETVAL                         (0x00000000U)

/* PORTSC1 */

#define CSL_DWCUSB3_PORTSC1_CCS_MASK                            (0x00000001U)
#define CSL_DWCUSB3_PORTSC1_CCS_SHIFT                           (0U)
#define CSL_DWCUSB3_PORTSC1_CCS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_CCS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PED_MASK                            (0x00000002U)
#define CSL_DWCUSB3_PORTSC1_PED_SHIFT                           (1U)
#define CSL_DWCUSB3_PORTSC1_PED_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PED_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_OCA_MASK                            (0x00000008U)
#define CSL_DWCUSB3_PORTSC1_OCA_SHIFT                           (3U)
#define CSL_DWCUSB3_PORTSC1_OCA_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_OCA_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PR_MASK                             (0x00000010U)
#define CSL_DWCUSB3_PORTSC1_PR_SHIFT                            (4U)
#define CSL_DWCUSB3_PORTSC1_PR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PR_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PLS_MASK                            (0x000001E0U)
#define CSL_DWCUSB3_PORTSC1_PLS_SHIFT                           (5U)
#define CSL_DWCUSB3_PORTSC1_PLS_RESETVAL                        (0x00000004U)
#define CSL_DWCUSB3_PORTSC1_PLS_MAX                             (0x0000000fU)

#define CSL_DWCUSB3_PORTSC1_PP_MASK                             (0x00000200U)
#define CSL_DWCUSB3_PORTSC1_PP_SHIFT                            (9U)
#define CSL_DWCUSB3_PORTSC1_PP_RESETVAL                         (0x00000001U)
#define CSL_DWCUSB3_PORTSC1_PP_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PORTSPEED_MASK                      (0x00003C00U)
#define CSL_DWCUSB3_PORTSC1_PORTSPEED_SHIFT                     (10U)
#define CSL_DWCUSB3_PORTSC1_PORTSPEED_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PORTSPEED_MAX                       (0x0000000fU)

#define CSL_DWCUSB3_PORTSC1_PIC_MASK                            (0x0000C000U)
#define CSL_DWCUSB3_PORTSC1_PIC_SHIFT                           (14U)
#define CSL_DWCUSB3_PORTSC1_PIC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PIC_MAX                             (0x00000003U)

#define CSL_DWCUSB3_PORTSC1_LWS_MASK                            (0x00010000U)
#define CSL_DWCUSB3_PORTSC1_LWS_SHIFT                           (16U)
#define CSL_DWCUSB3_PORTSC1_LWS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_LWS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_CSC_MASK                            (0x00020000U)
#define CSL_DWCUSB3_PORTSC1_CSC_SHIFT                           (17U)
#define CSL_DWCUSB3_PORTSC1_CSC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_CSC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PEC_MASK                            (0x00040000U)
#define CSL_DWCUSB3_PORTSC1_PEC_SHIFT                           (18U)
#define CSL_DWCUSB3_PORTSC1_PEC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PEC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_WRC_MASK                            (0x00080000U)
#define CSL_DWCUSB3_PORTSC1_WRC_SHIFT                           (19U)
#define CSL_DWCUSB3_PORTSC1_WRC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_WRC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_OCC_MASK                            (0x00100000U)
#define CSL_DWCUSB3_PORTSC1_OCC_SHIFT                           (20U)
#define CSL_DWCUSB3_PORTSC1_OCC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_OCC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PRC_MASK                            (0x00200000U)
#define CSL_DWCUSB3_PORTSC1_PRC_SHIFT                           (21U)
#define CSL_DWCUSB3_PORTSC1_PRC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PRC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_PLC_MASK                            (0x00400000U)
#define CSL_DWCUSB3_PORTSC1_PLC_SHIFT                           (22U)
#define CSL_DWCUSB3_PORTSC1_PLC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_PLC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_CEC_MASK                            (0x00800000U)
#define CSL_DWCUSB3_PORTSC1_CEC_SHIFT                           (23U)
#define CSL_DWCUSB3_PORTSC1_CEC_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_CEC_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_WCE_MASK                            (0x02000000U)
#define CSL_DWCUSB3_PORTSC1_WCE_SHIFT                           (25U)
#define CSL_DWCUSB3_PORTSC1_WCE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_WCE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_WDE_MASK                            (0x04000000U)
#define CSL_DWCUSB3_PORTSC1_WDE_SHIFT                           (26U)
#define CSL_DWCUSB3_PORTSC1_WDE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_WDE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_WOE_MASK                            (0x08000000U)
#define CSL_DWCUSB3_PORTSC1_WOE_SHIFT                           (27U)
#define CSL_DWCUSB3_PORTSC1_WOE_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_WOE_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_DR_MASK                             (0x40000000U)
#define CSL_DWCUSB3_PORTSC1_DR_SHIFT                            (30U)
#define CSL_DWCUSB3_PORTSC1_DR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_DR_MAX                              (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_WPR_MASK                            (0x80000000U)
#define CSL_DWCUSB3_PORTSC1_WPR_SHIFT                           (31U)
#define CSL_DWCUSB3_PORTSC1_WPR_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_WPR_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_CAS_MASK                            (0x01000000U)
#define CSL_DWCUSB3_PORTSC1_CAS_SHIFT                           (24U)
#define CSL_DWCUSB3_PORTSC1_CAS_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_PORTSC1_CAS_MAX                             (0x00000001U)

#define CSL_DWCUSB3_PORTSC1_RESETVAL                            (0x00000280U)

/* PORTPMSC1 */

#define CSL_DWCUSB3_PORTPMSC1_L1S_MASK                          (0x00000007U)
#define CSL_DWCUSB3_PORTPMSC1_L1S_SHIFT                         (0U)
#define CSL_DWCUSB3_PORTPMSC1_L1S_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_L1S_MAX                           (0x00000007U)

#define CSL_DWCUSB3_PORTPMSC1_RWE_MASK                          (0x00000008U)
#define CSL_DWCUSB3_PORTPMSC1_RWE_SHIFT                         (3U)
#define CSL_DWCUSB3_PORTPMSC1_RWE_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_RWE_MAX                           (0x00000001U)

#define CSL_DWCUSB3_PORTPMSC1_L1_DEVICE_SLOT_MASK               (0x0000FF00U)
#define CSL_DWCUSB3_PORTPMSC1_L1_DEVICE_SLOT_SHIFT              (8U)
#define CSL_DWCUSB3_PORTPMSC1_L1_DEVICE_SLOT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_L1_DEVICE_SLOT_MAX                (0x000000ffU)

#define CSL_DWCUSB3_PORTPMSC1_PORT_TEST_CONTROL_MASK            (0xF0000000U)
#define CSL_DWCUSB3_PORTPMSC1_PORT_TEST_CONTROL_SHIFT           (28U)
#define CSL_DWCUSB3_PORTPMSC1_PORT_TEST_CONTROL_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_PORT_TEST_CONTROL_MAX             (0x0000000fU)

#define CSL_DWCUSB3_PORTPMSC1_HLE_MASK                          (0x00010000U)
#define CSL_DWCUSB3_PORTPMSC1_HLE_SHIFT                         (16U)
#define CSL_DWCUSB3_PORTPMSC1_HLE_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_HLE_MAX                           (0x00000001U)

#define CSL_DWCUSB3_PORTPMSC1_BESL_MASK                         (0x000000F0U)
#define CSL_DWCUSB3_PORTPMSC1_BESL_SHIFT                        (4U)
#define CSL_DWCUSB3_PORTPMSC1_BESL_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_PORTPMSC1_BESL_MAX                          (0x0000000fU)

#define CSL_DWCUSB3_PORTPMSC1_RESETVAL                          (0x00000000U)

/* PORTLI1 */

#define CSL_DWCUSB3_PORTLI1_LINK_ERROR_COUNT_MASK               (0x0000FFFFU)
#define CSL_DWCUSB3_PORTLI1_LINK_ERROR_COUNT_SHIFT              (0U)
#define CSL_DWCUSB3_PORTLI1_LINK_ERROR_COUNT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_PORTLI1_LINK_ERROR_COUNT_MAX                (0x0000ffffU)

#define CSL_DWCUSB3_PORTLI1_RESETVAL                            (0x00000000U)

/* PORTHLPMC1 */

#define CSL_DWCUSB3_PORTHLPMC1_HIRDM_MASK                       (0x00000003U)
#define CSL_DWCUSB3_PORTHLPMC1_HIRDM_SHIFT                      (0U)
#define CSL_DWCUSB3_PORTHLPMC1_HIRDM_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_PORTHLPMC1_HIRDM_MAX                        (0x00000003U)

#define CSL_DWCUSB3_PORTHLPMC1_L1_TIMEOUT_MASK                  (0x000003FCU)
#define CSL_DWCUSB3_PORTHLPMC1_L1_TIMEOUT_SHIFT                 (2U)
#define CSL_DWCUSB3_PORTHLPMC1_L1_TIMEOUT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_PORTHLPMC1_L1_TIMEOUT_MAX                   (0x000000ffU)

#define CSL_DWCUSB3_PORTHLPMC1_BESLD_MASK                       (0x00003C00U)
#define CSL_DWCUSB3_PORTHLPMC1_BESLD_SHIFT                      (10U)
#define CSL_DWCUSB3_PORTHLPMC1_BESLD_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_PORTHLPMC1_BESLD_MAX                        (0x0000000fU)

#define CSL_DWCUSB3_PORTHLPMC1_RESETVAL                         (0x00000000U)

/* MFINDEX */

#define CSL_DWCUSB3_MFINDEX_MICROFRAME_INDEX_MASK               (0x00003FFFU)
#define CSL_DWCUSB3_MFINDEX_MICROFRAME_INDEX_SHIFT              (0U)
#define CSL_DWCUSB3_MFINDEX_MICROFRAME_INDEX_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_MFINDEX_MICROFRAME_INDEX_MAX                (0x00003fffU)

#define CSL_DWCUSB3_MFINDEX_RESETVAL                            (0x00000000U)

/* IMAN */

#define CSL_DWCUSB3_IMAN_IP_MASK                                (0x00000001U)
#define CSL_DWCUSB3_IMAN_IP_SHIFT                               (0U)
#define CSL_DWCUSB3_IMAN_IP_RESETVAL                            (0x00000000U)
#define CSL_DWCUSB3_IMAN_IP_PENDING                             (0x00000001U)
#define CSL_DWCUSB3_IMAN_IP_IDLE                                (0x00000000U)

#define CSL_DWCUSB3_IMAN_IE_MASK                                (0x00000002U)
#define CSL_DWCUSB3_IMAN_IE_SHIFT                               (1U)
#define CSL_DWCUSB3_IMAN_IE_RESETVAL                            (0x00000000U)
#define CSL_DWCUSB3_IMAN_IE_DIS                                 (0x00000000U)
#define CSL_DWCUSB3_IMAN_IE_EN                                  (0x00000001U)

#define CSL_DWCUSB3_IMAN_RESETVAL                               (0x00000000U)

/* IMOD */

#define CSL_DWCUSB3_IMOD_IMODI_MASK                             (0x0000FFFFU)
#define CSL_DWCUSB3_IMOD_IMODI_SHIFT                            (0U)
#define CSL_DWCUSB3_IMOD_IMODI_RESETVAL                         (0x00000fa0U)
#define CSL_DWCUSB3_IMOD_IMODI_MAX                              (0x0000ffffU)

#define CSL_DWCUSB3_IMOD_IMODC_MASK                             (0xFFFF0000U)
#define CSL_DWCUSB3_IMOD_IMODC_SHIFT                            (16U)
#define CSL_DWCUSB3_IMOD_IMODC_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_IMOD_IMODC_MAX                              (0x0000ffffU)

#define CSL_DWCUSB3_IMOD_RESETVAL                               (0x00000fa0U)

/* ERSTSZ */

#define CSL_DWCUSB3_ERSTSZ_ERS_TABLE_SIZE_MASK                  (0x0000FFFFU)
#define CSL_DWCUSB3_ERSTSZ_ERS_TABLE_SIZE_SHIFT                 (0U)
#define CSL_DWCUSB3_ERSTSZ_ERS_TABLE_SIZE_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_ERSTSZ_ERS_TABLE_SIZE_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_ERSTSZ_RESETVAL                             (0x00000000U)

/* ERSTBA_LO */

#define CSL_DWCUSB3_ERSTBA_LO_ERS_TABLE_BAR_MASK                (0xFFFFFFC0U)
#define CSL_DWCUSB3_ERSTBA_LO_ERS_TABLE_BAR_SHIFT               (6U)
#define CSL_DWCUSB3_ERSTBA_LO_ERS_TABLE_BAR_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_ERSTBA_LO_ERS_TABLE_BAR_MAX                 (0x03ffffffU)

#define CSL_DWCUSB3_ERSTBA_LO_RESETVAL                          (0x00000000U)

/* ERSTBA_HI */

#define CSL_DWCUSB3_ERSTBA_HI_ERS_TABLE_BAR_MASK                (0xFFFFFFFFU)
#define CSL_DWCUSB3_ERSTBA_HI_ERS_TABLE_BAR_SHIFT               (0U)
#define CSL_DWCUSB3_ERSTBA_HI_ERS_TABLE_BAR_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_ERSTBA_HI_ERS_TABLE_BAR_MAX                 (0xffffffffU)

#define CSL_DWCUSB3_ERSTBA_HI_RESETVAL                          (0x00000000U)

/* ERDP_LO */

#define CSL_DWCUSB3_ERDP_LO_DESI_MASK                           (0x00000007U)
#define CSL_DWCUSB3_ERDP_LO_DESI_SHIFT                          (0U)
#define CSL_DWCUSB3_ERDP_LO_DESI_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_ERDP_LO_DESI_MAX                            (0x00000007U)

#define CSL_DWCUSB3_ERDP_LO_EHB_MASK                            (0x00000008U)
#define CSL_DWCUSB3_ERDP_LO_EHB_SHIFT                           (3U)
#define CSL_DWCUSB3_ERDP_LO_EHB_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_ERDP_LO_EHB_MAX                             (0x00000001U)

#define CSL_DWCUSB3_ERDP_LO_ERD_PNTR_MASK                       (0xFFFFFFF0U)
#define CSL_DWCUSB3_ERDP_LO_ERD_PNTR_SHIFT                      (4U)
#define CSL_DWCUSB3_ERDP_LO_ERD_PNTR_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_ERDP_LO_ERD_PNTR_MAX                        (0x0fffffffU)

#define CSL_DWCUSB3_ERDP_LO_RESETVAL                            (0x00000000U)

/* ERDP_HI */

#define CSL_DWCUSB3_ERDP_HI_ERD_PNTR_MASK                       (0xFFFFFFFFU)
#define CSL_DWCUSB3_ERDP_HI_ERD_PNTR_SHIFT                      (0U)
#define CSL_DWCUSB3_ERDP_HI_ERD_PNTR_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_ERDP_HI_ERD_PNTR_MAX                        (0xffffffffU)

#define CSL_DWCUSB3_ERDP_HI_RESETVAL                            (0x00000000U)

/* DB */

#define CSL_DWCUSB3_DB_DB_TARGET_MASK                           (0x000000FFU)
#define CSL_DWCUSB3_DB_DB_TARGET_SHIFT                          (0U)
#define CSL_DWCUSB3_DB_DB_TARGET_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DB_DB_TARGET_MAX                            (0x000000ffU)

#define CSL_DWCUSB3_DB_DB_STREAM_ID_MASK                        (0xFFFF0000U)
#define CSL_DWCUSB3_DB_DB_STREAM_ID_SHIFT                       (16U)
#define CSL_DWCUSB3_DB_DB_STREAM_ID_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_DB_DB_STREAM_ID_MAX                         (0x0000ffffU)

#define CSL_DWCUSB3_DB_RESETVAL                                 (0x00000000U)

/* USBLEGSUP */

#define CSL_DWCUSB3_USBLEGSUP_ECID_MASK                         (0x000000FFU)
#define CSL_DWCUSB3_USBLEGSUP_ECID_SHIFT                        (0U)
#define CSL_DWCUSB3_USBLEGSUP_ECID_RESETVAL                     (0x00000001U)
#define CSL_DWCUSB3_USBLEGSUP_ECID_MAX                          (0x000000ffU)

#define CSL_DWCUSB3_USBLEGSUP_NCP_MASK                          (0x0000FF00U)
#define CSL_DWCUSB3_USBLEGSUP_NCP_SHIFT                         (8U)
#define CSL_DWCUSB3_USBLEGSUP_NCP_RESETVAL                      (0x00000004U)
#define CSL_DWCUSB3_USBLEGSUP_NCP_MAX                           (0x000000ffU)

#define CSL_DWCUSB3_USBLEGSUP_HCBOS_MASK                        (0x00010000U)
#define CSL_DWCUSB3_USBLEGSUP_HCBOS_SHIFT                       (16U)
#define CSL_DWCUSB3_USBLEGSUP_HCBOS_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_USBLEGSUP_HCBOS_MAX                         (0x00000001U)

#define CSL_DWCUSB3_USBLEGSUP_HCOOS_MASK                        (0x01000000U)
#define CSL_DWCUSB3_USBLEGSUP_HCOOS_SHIFT                       (24U)
#define CSL_DWCUSB3_USBLEGSUP_HCOOS_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_USBLEGSUP_HCOOS_MAX                         (0x00000001U)

#define CSL_DWCUSB3_USBLEGSUP_RESETVAL                          (0x00000401U)

/* USBLEGCTLSTS */

#define CSL_DWCUSB3_USBLEGCTLSTS_USE_MASK                       (0x00000001U)
#define CSL_DWCUSB3_USBLEGCTLSTS_USE_SHIFT                      (0U)
#define CSL_DWCUSB3_USBLEGCTLSTS_USE_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_USE_MAX                        (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SHSEE_MASK                     (0x00000010U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSEE_SHIFT                    (4U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSEE_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSEE_MAX                      (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SOOE_MASK                      (0x00002000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOE_SHIFT                     (13U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOE_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOE_MAX                       (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SPCE_MASK                      (0x00004000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPCE_SHIFT                     (14U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPCE_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPCE_MAX                       (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SBE_MASK                       (0x00008000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SBE_SHIFT                      (15U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SBE_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SBE_MAX                        (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SEI_MASK                       (0x00010000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SEI_SHIFT                      (16U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SEI_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SEI_MAX                        (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SHSE_MASK                      (0x00100000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSE_SHIFT                     (20U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSE_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SHSE_MAX                       (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SOOC_MASK                      (0x20000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOC_SHIFT                     (29U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOC_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SOOC_MAX                       (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SPC_MASK                       (0x40000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPC_SHIFT                      (30U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPC_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SPC_MAX                        (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_SB_MASK                        (0x80000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SB_SHIFT                       (31U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SB_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_USBLEGCTLSTS_SB_MAX                         (0x00000001U)

#define CSL_DWCUSB3_USBLEGCTLSTS_RESETVAL                       (0x00000000U)

/* SUPTPRT2_DW0 */

#define CSL_DWCUSB3_SUPTPRT2_DW0_ECID_MASK                      (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT2_DW0_ECID_SHIFT                     (0U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_ECID_RESETVAL                  (0x00000002U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_ECID_MAX                       (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW0_NCP_MASK                       (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_NCP_SHIFT                      (8U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_NCP_RESETVAL                   (0x00000004U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_NCP_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW0_MINREV_MASK                    (0x00FF0000U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MINREV_SHIFT                   (16U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MINREV_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MINREV_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW0_MAJREV_MASK                    (0xFF000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MAJREV_SHIFT                   (24U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MAJREV_RESETVAL                (0x00000002U)
#define CSL_DWCUSB3_SUPTPRT2_DW0_MAJREV_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW0_RESETVAL                       (0x02000402U)

/* SUPTPRT2_DW1 */

#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR0_MASK                     (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR0_SHIFT                    (0U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR0_RESETVAL                 (0x00000055U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR0_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR1_MASK                     (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR1_SHIFT                    (8U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR1_RESETVAL                 (0x00000053U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR1_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR2_MASK                     (0x00FF0000U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR2_SHIFT                    (16U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR2_RESETVAL                 (0x00000042U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR2_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR3_MASK                     (0xFF000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR3_SHIFT                    (24U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR3_RESETVAL                 (0x00000020U)
#define CSL_DWCUSB3_SUPTPRT2_DW1_CHAR3_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW1_RESETVAL                       (0x20425355U)

/* SUPTPRT2_DW2 */

#define CSL_DWCUSB3_SUPTPRT2_DW2_CPO_MASK                       (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPO_SHIFT                      (0U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPO_RESETVAL                   (0x00000001U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPO_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW2_CPC_MASK                       (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPC_SHIFT                      (8U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPC_RESETVAL                   (0x00000001U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_CPC_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT2_DW2_PSIC_MASK                      (0xF0000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_PSIC_SHIFT                     (28U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_PSIC_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_PSIC_MAX                       (0x0000000fU)

#define CSL_DWCUSB3_SUPTPRT2_DW2_HSO_MASK                       (0x00020000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HSO_SHIFT                      (17U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HSO_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HSO_MAX                        (0x00000001U)

#define CSL_DWCUSB3_SUPTPRT2_DW2_IHI_MASK                       (0x00040000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_IHI_SHIFT                      (18U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_IHI_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_IHI_MAX                        (0x00000001U)

#define CSL_DWCUSB3_SUPTPRT2_DW2_HLC_MASK                       (0x00080000U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HLC_SHIFT                      (19U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HLC_RESETVAL                   (0x00000001U)
#define CSL_DWCUSB3_SUPTPRT2_DW2_HLC_MAX                        (0x00000001U)

#define CSL_DWCUSB3_SUPTPRT2_DW2_RESETVAL                       (0x00090101U)

/* SUPTPRT2_DW3 */

#define CSL_DWCUSB3_SUPTPRT2_DW3_PST_MASK                       (0x0000001FU)
#define CSL_DWCUSB3_SUPTPRT2_DW3_PST_SHIFT                      (0U)
#define CSL_DWCUSB3_SUPTPRT2_DW3_PST_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT2_DW3_PST_MAX                        (0x0000001fU)

#define CSL_DWCUSB3_SUPTPRT2_DW3_RESETVAL                       (0x00000000U)

/* SUPTPRT3_DW0 */

#define CSL_DWCUSB3_SUPTPRT3_DW0_ECID_MASK                      (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT3_DW0_ECID_SHIFT                     (0U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_ECID_RESETVAL                  (0x00000002U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_ECID_MAX                       (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW0_NCP_MASK                       (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_NCP_SHIFT                      (8U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_NCP_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_NCP_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW0_MINREV_MASK                    (0x00FF0000U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MINREV_SHIFT                   (16U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MINREV_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MINREV_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW0_MAJREV_MASK                    (0xFF000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MAJREV_SHIFT                   (24U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MAJREV_RESETVAL                (0x00000003U)
#define CSL_DWCUSB3_SUPTPRT3_DW0_MAJREV_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW0_RESETVAL                       (0x03000002U)

/* SUPTPRT3_DW1 */

#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR0_MASK                     (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR0_SHIFT                    (0U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR0_RESETVAL                 (0x00000055U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR0_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR1_MASK                     (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR1_SHIFT                    (8U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR1_RESETVAL                 (0x00000053U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR1_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR2_MASK                     (0x00FF0000U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR2_SHIFT                    (16U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR2_RESETVAL                 (0x00000042U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR2_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR3_MASK                     (0xFF000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR3_SHIFT                    (24U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR3_RESETVAL                 (0x00000020U)
#define CSL_DWCUSB3_SUPTPRT3_DW1_CHAR3_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW1_RESETVAL                       (0x20425355U)

/* SUPTPRT3_DW2 */

#define CSL_DWCUSB3_SUPTPRT3_DW2_CPO_MASK                       (0x000000FFU)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPO_SHIFT                      (0U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPO_RESETVAL                   (0x00000002U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPO_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW2_CPC_MASK                       (0x0000FF00U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPC_SHIFT                      (8U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPC_RESETVAL                   (0x00000001U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_CPC_MAX                        (0x000000ffU)

#define CSL_DWCUSB3_SUPTPRT3_DW2_PSIC_MASK                      (0xF0000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_PSIC_SHIFT                     (28U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_PSIC_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW2_PSIC_MAX                       (0x0000000fU)

#define CSL_DWCUSB3_SUPTPRT3_DW2_RESETVAL                       (0x00000102U)

/* SUPTPRT3_DW3 */

#define CSL_DWCUSB3_SUPTPRT3_DW3_PST_MASK                       (0x0000001FU)
#define CSL_DWCUSB3_SUPTPRT3_DW3_PST_SHIFT                      (0U)
#define CSL_DWCUSB3_SUPTPRT3_DW3_PST_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_SUPTPRT3_DW3_PST_MAX                        (0x0000001fU)

#define CSL_DWCUSB3_SUPTPRT3_DW3_RESETVAL                       (0x00000000U)

/* DCID */

#define CSL_DWCUSB3_DCID_DCERSTMAX_MASK                         (0x001F0000U)
#define CSL_DWCUSB3_DCID_DCERSTMAX_SHIFT                        (16U)
#define CSL_DWCUSB3_DCID_DCERSTMAX_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_DCID_DCERSTMAX_MAX                          (0x0000001fU)

#define CSL_DWCUSB3_DCID_NCP_MASK                               (0x0000FF00U)
#define CSL_DWCUSB3_DCID_NCP_SHIFT                              (8U)
#define CSL_DWCUSB3_DCID_NCP_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DCID_NCP_MAX                                (0x000000ffU)

#define CSL_DWCUSB3_DCID_ECID_MASK                              (0x000000FFU)
#define CSL_DWCUSB3_DCID_ECID_SHIFT                             (0U)
#define CSL_DWCUSB3_DCID_ECID_RESETVAL                          (0x0000000aU)
#define CSL_DWCUSB3_DCID_ECID_MAX                               (0x000000ffU)

#define CSL_DWCUSB3_DCID_RESETVAL                               (0x0000000aU)

/* DCDB */

#define CSL_DWCUSB3_DCDB_DBTARGET_MASK                          (0x0000FF00U)
#define CSL_DWCUSB3_DCDB_DBTARGET_SHIFT                         (8U)
#define CSL_DWCUSB3_DCDB_DBTARGET_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_DCDB_DBTARGET_MAX                           (0x000000ffU)

#define CSL_DWCUSB3_DCDB_RESETVAL                               (0x00000000U)

/* DCERSTSZ */

#define CSL_DWCUSB3_DCERSTSZ_TABLESIZE_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_DCERSTSZ_TABLESIZE_SHIFT                    (0U)
#define CSL_DWCUSB3_DCERSTSZ_TABLESIZE_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_DCERSTSZ_TABLESIZE_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_DCERSTSZ_RESETVAL                           (0x00000000U)

/* DCERSTBA_LO */

#define CSL_DWCUSB3_DCERSTBA_LO_BASEADDRESS_MASK                (0xFFFFFFF0U)
#define CSL_DWCUSB3_DCERSTBA_LO_BASEADDRESS_SHIFT               (4U)
#define CSL_DWCUSB3_DCERSTBA_LO_BASEADDRESS_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DCERSTBA_LO_BASEADDRESS_MAX                 (0x0fffffffU)

#define CSL_DWCUSB3_DCERSTBA_LO_RESETVAL                        (0x00000000U)

/* DCERSTBA_HI */

#define CSL_DWCUSB3_DCERSTBA_HI_BASEADDRESS_MASK                (0xFFFFFFFFU)
#define CSL_DWCUSB3_DCERSTBA_HI_BASEADDRESS_SHIFT               (0U)
#define CSL_DWCUSB3_DCERSTBA_HI_BASEADDRESS_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DCERSTBA_HI_BASEADDRESS_MAX                 (0xffffffffU)

#define CSL_DWCUSB3_DCERSTBA_HI_RESETVAL                        (0x00000000U)

/* DCERDP_LO */

#define CSL_DWCUSB3_DCERDP_LO_DEQUEUEPOINTER_MASK               (0xFFFFFFF0U)
#define CSL_DWCUSB3_DCERDP_LO_DEQUEUEPOINTER_SHIFT              (4U)
#define CSL_DWCUSB3_DCERDP_LO_DEQUEUEPOINTER_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_DCERDP_LO_DEQUEUEPOINTER_MAX                (0x0fffffffU)

#define CSL_DWCUSB3_DCERDP_LO_DESI_MASK                         (0x00000007U)
#define CSL_DWCUSB3_DCERDP_LO_DESI_SHIFT                        (0U)
#define CSL_DWCUSB3_DCERDP_LO_DESI_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_DCERDP_LO_DESI_MAX                          (0x00000007U)

#define CSL_DWCUSB3_DCERDP_LO_RESETVAL                          (0x00000000U)

/* DCERDP_HI */

#define CSL_DWCUSB3_DCERDP_HI_DEQUEUEPOINTER_MASK               (0xFFFFFFFFU)
#define CSL_DWCUSB3_DCERDP_HI_DEQUEUEPOINTER_SHIFT              (0U)
#define CSL_DWCUSB3_DCERDP_HI_DEQUEUEPOINTER_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_DCERDP_HI_DEQUEUEPOINTER_MAX                (0xffffffffU)

#define CSL_DWCUSB3_DCERDP_HI_RESETVAL                          (0x00000000U)

/* DCCTRL */

#define CSL_DWCUSB3_DCCTRL_DCR_MASK                             (0x00000001U)
#define CSL_DWCUSB3_DCCTRL_DCR_SHIFT                            (0U)
#define CSL_DWCUSB3_DCCTRL_DCR_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DCR_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_LSE_MASK                             (0x00000002U)
#define CSL_DWCUSB3_DCCTRL_LSE_SHIFT                            (1U)
#define CSL_DWCUSB3_DCCTRL_LSE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_LSE_DISABLED                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_LSE_ENABLED                          (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_HOT_MASK                             (0x00000004U)
#define CSL_DWCUSB3_DCCTRL_HOT_SHIFT                            (2U)
#define CSL_DWCUSB3_DCCTRL_HOT_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_HOT_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_HIT_MASK                             (0x00000008U)
#define CSL_DWCUSB3_DCCTRL_HIT_SHIFT                            (3U)
#define CSL_DWCUSB3_DCCTRL_HIT_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_HIT_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_DEBUG_MAX_BURST_SIZE_MASK            (0x00FF0000U)
#define CSL_DWCUSB3_DCCTRL_DEBUG_MAX_BURST_SIZE_SHIFT           (16U)
#define CSL_DWCUSB3_DCCTRL_DEBUG_MAX_BURST_SIZE_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DEBUG_MAX_BURST_SIZE_MAX             (0x000000ffU)

#define CSL_DWCUSB3_DCCTRL_DEVICE_ADDRESS_MASK                  (0x7F000000U)
#define CSL_DWCUSB3_DCCTRL_DEVICE_ADDRESS_SHIFT                 (24U)
#define CSL_DWCUSB3_DCCTRL_DEVICE_ADDRESS_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DEVICE_ADDRESS_MAX                   (0x0000007fU)

#define CSL_DWCUSB3_DCCTRL_DCE_MASK                             (0x80000000U)
#define CSL_DWCUSB3_DCCTRL_DCE_SHIFT                            (31U)
#define CSL_DWCUSB3_DCCTRL_DCE_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DCE_DISABLED                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DCE_ENABLED                          (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_DRC_MASK                             (0x00000010U)
#define CSL_DWCUSB3_DCCTRL_DRC_SHIFT                            (4U)
#define CSL_DWCUSB3_DCCTRL_DRC_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DCCTRL_DRC_MAX                              (0x00000001U)

#define CSL_DWCUSB3_DCCTRL_RESETVAL                             (0x00000000U)

/* DCST */

#define CSL_DWCUSB3_DCST_ER_MASK                                (0x00000001U)
#define CSL_DWCUSB3_DCST_ER_SHIFT                               (0U)
#define CSL_DWCUSB3_DCST_ER_RESETVAL                            (0x00000000U)
#define CSL_DWCUSB3_DCST_ER_MAX                                 (0x00000001U)

#define CSL_DWCUSB3_DCST_DEBUG_PORT_NUMBER_MASK                 (0xFF000000U)
#define CSL_DWCUSB3_DCST_DEBUG_PORT_NUMBER_SHIFT                (24U)
#define CSL_DWCUSB3_DCST_DEBUG_PORT_NUMBER_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DCST_DEBUG_PORT_NUMBER_MAX                  (0x000000ffU)

#define CSL_DWCUSB3_DCST_RESETVAL                               (0x00000000U)

/* DCPORTSC */

#define CSL_DWCUSB3_DCPORTSC_CCS_MASK                           (0x00000001U)
#define CSL_DWCUSB3_DCPORTSC_CCS_SHIFT                          (0U)
#define CSL_DWCUSB3_DCPORTSC_CCS_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_CCS_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_PED_MASK                           (0x00000002U)
#define CSL_DWCUSB3_DCPORTSC_PED_SHIFT                          (1U)
#define CSL_DWCUSB3_DCPORTSC_PED_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PED_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_PR_MASK                            (0x00000010U)
#define CSL_DWCUSB3_DCPORTSC_PR_SHIFT                           (4U)
#define CSL_DWCUSB3_DCPORTSC_PR_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PR_MAX                             (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_PLS_MASK                           (0x000001E0U)
#define CSL_DWCUSB3_DCPORTSC_PLS_SHIFT                          (5U)
#define CSL_DWCUSB3_DCPORTSC_PLS_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PLS_MAX                            (0x0000000fU)

#define CSL_DWCUSB3_DCPORTSC_PORTSPEED_MASK                     (0x00003C00U)
#define CSL_DWCUSB3_DCPORTSC_PORTSPEED_SHIFT                    (10U)
#define CSL_DWCUSB3_DCPORTSC_PORTSPEED_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PORTSPEED_MAX                      (0x0000000fU)

#define CSL_DWCUSB3_DCPORTSC_CSC_MASK                           (0x00020000U)
#define CSL_DWCUSB3_DCPORTSC_CSC_SHIFT                          (17U)
#define CSL_DWCUSB3_DCPORTSC_CSC_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_CSC_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_PRC_MASK                           (0x00200000U)
#define CSL_DWCUSB3_DCPORTSC_PRC_SHIFT                          (21U)
#define CSL_DWCUSB3_DCPORTSC_PRC_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PRC_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_PLC_MASK                           (0x00400000U)
#define CSL_DWCUSB3_DCPORTSC_PLC_SHIFT                          (22U)
#define CSL_DWCUSB3_DCPORTSC_PLC_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_PLC_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_CEC_MASK                           (0x00800000U)
#define CSL_DWCUSB3_DCPORTSC_CEC_SHIFT                          (23U)
#define CSL_DWCUSB3_DCPORTSC_CEC_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCPORTSC_CEC_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DCPORTSC_RESETVAL                           (0x00000000U)

/* DCCP_LO */

#define CSL_DWCUSB3_DCCP_LO_CONTEXTPOINTER_MASK                 (0xFFFFFFF0U)
#define CSL_DWCUSB3_DCCP_LO_CONTEXTPOINTER_SHIFT                (4U)
#define CSL_DWCUSB3_DCCP_LO_CONTEXTPOINTER_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DCCP_LO_CONTEXTPOINTER_MAX                  (0x0fffffffU)

#define CSL_DWCUSB3_DCCP_LO_RESETVAL                            (0x00000000U)

/* DCCP_HI */

#define CSL_DWCUSB3_DCCP_HI_CONTEXTPOINTER_MASK                 (0xFFFFFFFFU)
#define CSL_DWCUSB3_DCCP_HI_CONTEXTPOINTER_SHIFT                (0U)
#define CSL_DWCUSB3_DCCP_HI_CONTEXTPOINTER_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DCCP_HI_CONTEXTPOINTER_MAX                  (0xffffffffU)

#define CSL_DWCUSB3_DCCP_HI_RESETVAL                            (0x00000000U)

/* DCDDI1 */

#define CSL_DWCUSB3_DCDDI1_DBCPROTOCOL_MASK                     (0x000000FFU)
#define CSL_DWCUSB3_DCDDI1_DBCPROTOCOL_SHIFT                    (0U)
#define CSL_DWCUSB3_DCDDI1_DBCPROTOCOL_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_DCDDI1_DBCPROTOCOL_MAX                      (0x000000ffU)

#define CSL_DWCUSB3_DCDDI1_VENDORID_MASK                        (0xFFFF0000U)
#define CSL_DWCUSB3_DCDDI1_VENDORID_SHIFT                       (16U)
#define CSL_DWCUSB3_DCDDI1_VENDORID_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_DCDDI1_VENDORID_MAX                         (0x0000ffffU)

#define CSL_DWCUSB3_DCDDI1_RESETVAL                             (0x00000000U)

/* DCDDI2 */

#define CSL_DWCUSB3_DCDDI2_PRODUCTID_MASK                       (0x0000FFFFU)
#define CSL_DWCUSB3_DCDDI2_PRODUCTID_SHIFT                      (0U)
#define CSL_DWCUSB3_DCDDI2_PRODUCTID_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCDDI2_PRODUCTID_MAX                        (0x0000ffffU)

#define CSL_DWCUSB3_DCDDI2_DEVICEREVISION_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_DCDDI2_DEVICEREVISION_SHIFT                 (16U)
#define CSL_DWCUSB3_DCDDI2_DEVICEREVISION_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DCDDI2_DEVICEREVISION_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_DCDDI2_RESETVAL                             (0x00000000U)

/* GSBUSCFG0 */

#define CSL_DWCUSB3_GSBUSCFG0_INCRBRSTENA_MASK                  (0x00000001U)
#define CSL_DWCUSB3_GSBUSCFG0_INCRBRSTENA_SHIFT                 (0U)
#define CSL_DWCUSB3_GSBUSCFG0_INCRBRSTENA_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_INCRBRSTENA_MAX                   (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR4BRSTENA_MASK                 (0x00000002U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR4BRSTENA_SHIFT                (1U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR4BRSTENA_RESETVAL             (0x00000001U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR4BRSTENA_MAX                  (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR8BRSTENA_MASK                 (0x00000004U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR8BRSTENA_SHIFT                (2U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR8BRSTENA_RESETVAL             (0x00000001U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR8BRSTENA_MAX                  (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR16BRSTENA_MASK                (0x00000008U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR16BRSTENA_SHIFT               (3U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR16BRSTENA_RESETVAL            (0x00000001U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR16BRSTENA_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR32BRSTENA_MASK                (0x00000010U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR32BRSTENA_SHIFT               (4U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR32BRSTENA_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR32BRSTENA_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR64BRSTENA_MASK                (0x00000020U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR64BRSTENA_SHIFT               (5U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR64BRSTENA_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR64BRSTENA_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR128BRSTENA_MASK               (0x00000040U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR128BRSTENA_SHIFT              (6U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR128BRSTENA_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR128BRSTENA_MAX                (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_INCR256BRSTENA_MASK               (0x00000080U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR256BRSTENA_SHIFT              (7U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR256BRSTENA_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_INCR256BRSTENA_MAX                (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_DATBIGEND_MASK                    (0x00000800U)
#define CSL_DWCUSB3_GSBUSCFG0_DATBIGEND_SHIFT                   (11U)
#define CSL_DWCUSB3_GSBUSCFG0_DATBIGEND_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_DATBIGEND_LITTLE                  (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_DATBIGEND_BIG                     (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_DESCBIGEND_MASK                   (0x00001000U)
#define CSL_DWCUSB3_GSBUSCFG0_DESCBIGEND_SHIFT                  (12U)
#define CSL_DWCUSB3_GSBUSCFG0_DESCBIGEND_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_DESCBIGEND_LITTLE                 (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG0_DESCBIGEND_BIG                    (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG0_RESETVAL                          (0x0000000eU)

/* GSBUSCFG1 */

#define CSL_DWCUSB3_GSBUSCFG1_PIPETRANSLIMIT_MASK               (0x00000F00U)
#define CSL_DWCUSB3_GSBUSCFG1_PIPETRANSLIMIT_SHIFT              (8U)
#define CSL_DWCUSB3_GSBUSCFG1_PIPETRANSLIMIT_RESETVAL           (0x0000000fU)
#define CSL_DWCUSB3_GSBUSCFG1_PIPETRANSLIMIT_MAX                (0x0000000fU)

#define CSL_DWCUSB3_GSBUSCFG1_EN1KPAGE_MASK                     (0x00001000U)
#define CSL_DWCUSB3_GSBUSCFG1_EN1KPAGE_SHIFT                    (12U)
#define CSL_DWCUSB3_GSBUSCFG1_EN1KPAGE_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG1_EN1KPAGE_DIS                      (0x00000000U)
#define CSL_DWCUSB3_GSBUSCFG1_EN1KPAGE_EN                       (0x00000001U)

#define CSL_DWCUSB3_GSBUSCFG1_RESETVAL                          (0x00000f00U)

/* GTXTHRCFG */

#define CSL_DWCUSB3_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK            (0x00FF0000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT           (16U)
#define CSL_DWCUSB3_GTXTHRCFG_USBMAXTXBURSTSIZE_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBMAXTXBURSTSIZE_MAX             (0x000000ffU)

#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNTSEL_MASK               (0x20000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT              (29U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNTSEL_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNTSEL_DIS                (0x00000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNTSEL_EN                 (0x00000001U)

#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNT_MASK                  (0x0F000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNT_SHIFT                 (24U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GTXTHRCFG_USBTXPKTCNT_MAX                   (0x0000000fU)

#define CSL_DWCUSB3_GTXTHRCFG_RESETVAL                          (0x00000000U)

/* GRXTHRCFG */

#define CSL_DWCUSB3_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK            (0x00F80000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT           (19U)
#define CSL_DWCUSB3_GRXTHRCFG_USBMAXRXBURSTSIZE_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBMAXRXBURSTSIZE_MAX             (0x0000001fU)

#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNT_MASK                  (0x0F000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNT_SHIFT                 (24U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNT_MAX                   (0x0000000fU)

#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNTSEL_MASK               (0x20000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT              (29U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNTSEL_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNTSEL_DIS                (0x00000000U)
#define CSL_DWCUSB3_GRXTHRCFG_USBRXPKTCNTSEL_EN                 (0x00000001U)

#define CSL_DWCUSB3_GRXTHRCFG_RESETVAL                          (0x00000000U)

/* GCTL */

#define CSL_DWCUSB3_GCTL_DSBLCLKGTNG_MASK                       (0x00000001U)
#define CSL_DWCUSB3_GCTL_DSBLCLKGTNG_SHIFT                      (0U)
#define CSL_DWCUSB3_GCTL_DSBLCLKGTNG_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_GCTL_DSBLCLKGTNG_MAX                        (0x00000001U)

#define CSL_DWCUSB3_GCTL_DISSCRAMBLE_MASK                       (0x00000008U)
#define CSL_DWCUSB3_GCTL_DISSCRAMBLE_SHIFT                      (3U)
#define CSL_DWCUSB3_GCTL_DISSCRAMBLE_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_GCTL_DISSCRAMBLE_MAX                        (0x00000001U)

#define CSL_DWCUSB3_GCTL_SCALEDOWN_MASK                         (0x00000030U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN_SHIFT                        (4U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN_NONE                         (0x00000000U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN__1                           (0x00000001U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN__2                           (0x00000002U)
#define CSL_DWCUSB3_GCTL_SCALEDOWN__3                           (0x00000003U)

#define CSL_DWCUSB3_GCTL_RAMCLKSEL_MASK                         (0x000000C0U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_SHIFT                        (6U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_BUS                          (0x00000000U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_PIPE                         (0x00000001U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_PIPE_50                      (0x00000002U)
#define CSL_DWCUSB3_GCTL_RAMCLKSEL_MAC                          (0x00000003U)

#define CSL_DWCUSB3_GCTL_DEBUGATTACH_MASK                       (0x00000100U)
#define CSL_DWCUSB3_GCTL_DEBUGATTACH_SHIFT                      (8U)
#define CSL_DWCUSB3_GCTL_DEBUGATTACH_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_GCTL_DEBUGATTACH_MAX                        (0x00000001U)

#define CSL_DWCUSB3_GCTL_CORESOFTRESET_MASK                     (0x00000800U)
#define CSL_DWCUSB3_GCTL_CORESOFTRESET_SHIFT                    (11U)
#define CSL_DWCUSB3_GCTL_CORESOFTRESET_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GCTL_CORESOFTRESET_NO                       (0x00000000U)
#define CSL_DWCUSB3_GCTL_CORESOFTRESET_RESET                    (0x00000001U)

#define CSL_DWCUSB3_GCTL_PRTCAPDIR_MASK                         (0x00003000U)
#define CSL_DWCUSB3_GCTL_PRTCAPDIR_SHIFT                        (12U)
#define CSL_DWCUSB3_GCTL_PRTCAPDIR_RESETVAL                     (0x00000003U)
#define CSL_DWCUSB3_GCTL_PRTCAPDIR_HST                          (0x00000001U)
#define CSL_DWCUSB3_GCTL_PRTCAPDIR_DEV                          (0x00000002U)
#define CSL_DWCUSB3_GCTL_PRTCAPDIR_DRD                          (0x00000003U)

#define CSL_DWCUSB3_GCTL_FRMSCLDWN_MASK                         (0x0000C000U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN_SHIFT                        (14U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN__0                           (0x00000000U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN__1                           (0x00000001U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN__2                           (0x00000002U)
#define CSL_DWCUSB3_GCTL_FRMSCLDWN__3                           (0x00000003U)

#define CSL_DWCUSB3_GCTL_U2RSTECN_MASK                          (0x00010000U)
#define CSL_DWCUSB3_GCTL_U2RSTECN_SHIFT                         (16U)
#define CSL_DWCUSB3_GCTL_U2RSTECN_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_GCTL_U2RSTECN_MAX                           (0x00000001U)

#define CSL_DWCUSB3_GCTL_PWRDNSCALE_MASK                        (0xFFF80000U)
#define CSL_DWCUSB3_GCTL_PWRDNSCALE_SHIFT                       (19U)
#define CSL_DWCUSB3_GCTL_PWRDNSCALE_RESETVAL                    (0x000004b0U)
#define CSL_DWCUSB3_GCTL_PWRDNSCALE_MAX                         (0x00001fffU)

#define CSL_DWCUSB3_GCTL_MASTERFILTBYPASS_MASK                  (0x00040000U)
#define CSL_DWCUSB3_GCTL_MASTERFILTBYPASS_SHIFT                 (18U)
#define CSL_DWCUSB3_GCTL_MASTERFILTBYPASS_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GCTL_MASTERFILTBYPASS_MAX                   (0x00000001U)

#define CSL_DWCUSB3_GCTL_BYPSSETADDR_MASK                       (0x00020000U)
#define CSL_DWCUSB3_GCTL_BYPSSETADDR_SHIFT                      (17U)
#define CSL_DWCUSB3_GCTL_BYPSSETADDR_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_GCTL_BYPSSETADDR_FUNC                       (0x00000000U)
#define CSL_DWCUSB3_GCTL_BYPSSETADDR_BYPASS                     (0x00000001U)

#define CSL_DWCUSB3_GCTL_RESETVAL                               (0x25803000U)

/* GSTS */

#define CSL_DWCUSB3_GSTS_CURMOD_MASK                            (0x00000003U)
#define CSL_DWCUSB3_GSTS_CURMOD_SHIFT                           (0U)
#define CSL_DWCUSB3_GSTS_CURMOD_RESETVAL                        (0x00000002U)
#define CSL_DWCUSB3_GSTS_CURMOD_DEV                             (0x00000000U)
#define CSL_DWCUSB3_GSTS_CURMOD_HOST                            (0x00000001U)
#define CSL_DWCUSB3_GSTS_CURMOD_DRD                             (0x00000002U)

#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_MASK                     (0x00000010U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_SHIFT                    (4U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_NOEVENT                  (0x00000000U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_SET                      (0x00000001U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_CLEAR                    (0x00000001U)
#define CSL_DWCUSB3_GSTS_BUSERRADDRVLD_NOACTION                 (0x00000000U)

#define CSL_DWCUSB3_GSTS_CBELT_MASK                             (0xFFF00000U)
#define CSL_DWCUSB3_GSTS_CBELT_SHIFT                            (20U)
#define CSL_DWCUSB3_GSTS_CBELT_RESETVAL                         (0x000003e8U)
#define CSL_DWCUSB3_GSTS_CBELT_MAX                              (0x00000fffU)

#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_MASK                        (0x00000020U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_SHIFT                       (5U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_NOEVENT                     (0x00000000U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_SET                         (0x00000001U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_CLEAR                       (0x00000001U)
#define CSL_DWCUSB3_GSTS_CSRTIMEOUT_NOACTION                    (0x00000000U)

#define CSL_DWCUSB3_GSTS_DEVICE_IP_MASK                         (0x00000040U)
#define CSL_DWCUSB3_GSTS_DEVICE_IP_SHIFT                        (6U)
#define CSL_DWCUSB3_GSTS_DEVICE_IP_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_GSTS_DEVICE_IP_NONE                         (0x00000000U)
#define CSL_DWCUSB3_GSTS_DEVICE_IP_PEND                         (0x00000001U)

#define CSL_DWCUSB3_GSTS_HOST_IP_MASK                           (0x00000080U)
#define CSL_DWCUSB3_GSTS_HOST_IP_SHIFT                          (7U)
#define CSL_DWCUSB3_GSTS_HOST_IP_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_GSTS_HOST_IP_NONE                           (0x00000000U)
#define CSL_DWCUSB3_GSTS_HOST_IP_PEND                           (0x00000001U)

#define CSL_DWCUSB3_GSTS_ADP_IP_MASK                            (0x00000100U)
#define CSL_DWCUSB3_GSTS_ADP_IP_SHIFT                           (8U)
#define CSL_DWCUSB3_GSTS_ADP_IP_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_GSTS_ADP_IP_MAX                             (0x00000001U)

#define CSL_DWCUSB3_GSTS_BC_IP_MASK                             (0x00000200U)
#define CSL_DWCUSB3_GSTS_BC_IP_SHIFT                            (9U)
#define CSL_DWCUSB3_GSTS_BC_IP_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_GSTS_BC_IP_MAX                              (0x00000001U)

#define CSL_DWCUSB3_GSTS_OTG_IP_MASK                            (0x00000400U)
#define CSL_DWCUSB3_GSTS_OTG_IP_SHIFT                           (10U)
#define CSL_DWCUSB3_GSTS_OTG_IP_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_GSTS_OTG_IP_NONE                            (0x00000000U)
#define CSL_DWCUSB3_GSTS_OTG_IP_PEND                            (0x00000001U)

#define CSL_DWCUSB3_GSTS_RESETVAL                               (0x3e800002U)

/* GSNPSID */

#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_CORE_MASK                (0xFFFF0000U)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_CORE_SHIFT               (16U)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_CORE_RESETVAL            (0x00005533U)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_CORE_MAX                 (0x0000ffffU)

#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_REL_MASK                 (0x0000FFFFU)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_REL_SHIFT                (0U)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_REL_RESETVAL             (0x0000202aU)
#define CSL_DWCUSB3_GSNPSID_SYNOPSYSID_REL_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GSNPSID_RESETVAL                            (0x5533202aU)

/* GGPIO */

#define CSL_DWCUSB3_GGPIO_GPI_MASK                              (0x0000FFFFU)
#define CSL_DWCUSB3_GGPIO_GPI_SHIFT                             (0U)
#define CSL_DWCUSB3_GGPIO_GPI_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_GGPIO_GPI_MAX                               (0x0000ffffU)

#define CSL_DWCUSB3_GGPIO_GPO_MASK                              (0xFFFF0000U)
#define CSL_DWCUSB3_GGPIO_GPO_SHIFT                             (16U)
#define CSL_DWCUSB3_GGPIO_GPO_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_GGPIO_GPO_MAX                               (0x0000ffffU)

#define CSL_DWCUSB3_GGPIO_RESETVAL                              (0x00000000U)

/* GUID */

#define CSL_DWCUSB3_GUID_USERID_MASK                            (0xFFFFFFFFU)
#define CSL_DWCUSB3_GUID_USERID_SHIFT                           (0U)
#define CSL_DWCUSB3_GUID_USERID_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_GUID_USERID_MAX                             (0xffffffffU)

#define CSL_DWCUSB3_GUID_RESETVAL                               (0x00000000U)

/* GBUSERRADDRLO */

#define CSL_DWCUSB3_GBUSERRADDRLO_BUSERRADDRLO_MASK             (0xFFFFFFFFU)
#define CSL_DWCUSB3_GBUSERRADDRLO_BUSERRADDRLO_SHIFT            (0U)
#define CSL_DWCUSB3_GBUSERRADDRLO_BUSERRADDRLO_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GBUSERRADDRLO_BUSERRADDRLO_MAX              (0xffffffffU)

#define CSL_DWCUSB3_GBUSERRADDRLO_RESETVAL                      (0x00000000U)

/* GBUSERRADDRHI */

#define CSL_DWCUSB3_GBUSERRADDRHI_BUSERRADDRHI_MASK             (0xFFFFFFFFU)
#define CSL_DWCUSB3_GBUSERRADDRHI_BUSERRADDRHI_SHIFT            (0U)
#define CSL_DWCUSB3_GBUSERRADDRHI_BUSERRADDRHI_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GBUSERRADDRHI_BUSERRADDRHI_MAX              (0xffffffffU)

#define CSL_DWCUSB3_GBUSERRADDRHI_RESETVAL                      (0x00000000U)

/* GPRTBIMAPLO */

#define CSL_DWCUSB3_GPRTBIMAPLO_BINUM1_MASK                     (0x0000000FU)
#define CSL_DWCUSB3_GPRTBIMAPLO_BINUM1_SHIFT                    (0U)
#define CSL_DWCUSB3_GPRTBIMAPLO_BINUM1_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GPRTBIMAPLO_BINUM1_MAX                      (0x0000000fU)

#define CSL_DWCUSB3_GPRTBIMAPLO_RESETVAL                        (0x00000000U)

/* GPRTBIMAPHI */

#define CSL_DWCUSB3_GPRTBIMAPHI_RESETVAL                        (0x00000000U)

/* GHWPARAMS0 */

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_MASK               (0x00000007U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_SHIFT              (0U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_RESETVAL           (0x00000002U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_DEV                (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_HST                (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MODE_DRD                (0x00000002U)

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MBUS_TYPE_MASK          (0x00000038U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MBUS_TYPE_SHIFT         (3U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MBUS_TYPE_RESETVAL      (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MBUS_TYPE_AXI           (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SBUS_TYPE_MASK          (0x000000C0U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SBUS_TYPE_SHIFT         (6U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SBUS_TYPE_RESETVAL      (0x00000003U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SBUS_TYPE_NATIVE        (0x00000000U)

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MDWIDTH_MASK            (0x0000FF00U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MDWIDTH_SHIFT           (8U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MDWIDTH_RESETVAL        (0x00000040U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_MDWIDTH_MAX             (0x000000ffU)

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SDWIDTH_MASK            (0x00FF0000U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SDWIDTH_SHIFT           (16U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SDWIDTH_RESETVAL        (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_SDWIDTH_MAX             (0x000000ffU)

#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_AWIDTH_MASK             (0xFF000000U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_AWIDTH_SHIFT            (24U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_AWIDTH_RESETVAL         (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS0_DWC_USB3_AWIDTH_MAX              (0x000000ffU)

#define CSL_DWCUSB3_GHWPARAMS0_RESETVAL                         (0x202040caU)

/* GHWPARAMS1 */

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_IDWIDTH_MASK            (0x00000007U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_IDWIDTH_SHIFT           (0U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_IDWIDTH_RESETVAL        (0x00000003U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_IDWIDTH_MAX             (0x00000007U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_BURSTWIDTH_MASK         (0x00000038U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_BURSTWIDTH_SHIFT        (3U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_BURSTWIDTH_RESETVAL     (0x00000007U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_BURSTWIDTH_MAX          (0x00000007U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_MASK      (0x000001C0U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_SHIFT     (6U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_RESETVAL  (0x00000004U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_MAX       (0x00000007U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_MASK        (0x00007000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_SHIFT       (12U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_RESETVAL    (0x00000004U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_MAX         (0x00000007U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_MASK     (0x001F8000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_SHIFT    (15U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_RESETVAL  (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS_MASK           (0x00600000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS_SHIFT          (21U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS_RESETVAL       (0x00000002U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS__1             (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS__2             (0x00000002U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_NUM_RAMS__3             (0x00000003U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_SPRAM_TYP_MASK          (0x00800000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_SPRAM_TYP_SHIFT         (23U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_SPRAM_TYP_RESETVAL      (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_SPRAM_TYP_SP            (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_MASK          (0x03000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_SHIFT         (24U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_RESETVAL      (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_NONE          (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_CLOCK         (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_EN_PWROPT_CLOCK_HIBERNATION  (0x00000002U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_MASK  (0x04000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_SHIFT  (26U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_NO    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_YES   (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_MASK  (0x08000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_SHIFT  (27U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_NO    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_YES   (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_MASK  (0x10000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_SHIFT  (28U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_NO    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_YES   (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_MASK    (0x40000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_SHIFT   (30U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_NO      (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_YES     (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_MASK       (0x00000E00U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_SHIFT      (9U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_RESETVAL   (0x00000004U)
#define CSL_DWCUSB3_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_MAX        (0x00000007U)

#define CSL_DWCUSB3_GHWPARAMS1_RESETVAL                         (0x01c0c93bU)

/* GHWPARAMS2 */

#define CSL_DWCUSB3_GHWPARAMS2_DWC_USB3_USERID_MASK             (0xFFFFFFFFU)
#define CSL_DWCUSB3_GHWPARAMS2_DWC_USB3_USERID_SHIFT            (0U)
#define CSL_DWCUSB3_GHWPARAMS2_DWC_USB3_USERID_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS2_DWC_USB3_USERID_MAX              (0xffffffffU)

#define CSL_DWCUSB3_GHWPARAMS2_RESETVAL                         (0x00000000U)

/* GHWPARAMS3 */

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_MASK    (0x00000003U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_SHIFT   (0U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_RESETVAL  (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_NONE    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_PIPE    (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_MASK    (0x0000000CU)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_SHIFT   (2U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_RESETVAL  (0x00000003U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_NONE    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_UTMI    (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_ULPI    (0x00000002U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_BOTH    (0x00000003U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_MASK    (0x00000030U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_SHIFT   (4U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_NONE    (0x00000000U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH_MASK       (0x000000C0U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH_SHIFT      (6U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH_RESETVAL   (0x00000002U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH__8         (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH__16        (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH__8_16      (0x00000002U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_MASK  (0x00000400U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_SHIFT  (10U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_NO  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_VC  (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_MASK        (0x00000800U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_SHIFT       (11U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_RESETVAL    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_NO          (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_VC          (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_EPS_MASK            (0x0003F000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_EPS_SHIFT           (12U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_EPS_RESETVAL        (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_EPS_MAX             (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_MASK         (0x007C0000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_SHIFT        (18U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_RESETVAL     (0x00000010U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_MAX          (0x0000001fU)

#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_MASK  (0x7F800000U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_SHIFT  (23U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_RESETVAL  (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_MAX  (0x000000ffU)

#define CSL_DWCUSB3_GHWPARAMS3_RESETVAL                         (0x1042008dU)

/* GHWPARAMS4 */

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_MASK  (0x0000003FU)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_SHIFT  (0U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_RESETVAL  (0x00000004U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_MAX  (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_NUM_SS_USB_INSTANCES_MASK  (0x001E0000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_NUM_SS_USB_INSTANCES_SHIFT  (17U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_NUM_SS_USB_INSTANCES_RESETVAL  (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_NUM_SS_USB_INSTANCES_MAX  (0x0000000fU)

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_MASK       (0x00800000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_SHIFT      (23U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_RESETVAL   (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_NONE       (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_ISO        (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_MASK      (0x0F000000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_SHIFT     (24U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_RESETVAL  (0x00000008U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_MAX       (0x0000000fU)

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_MASK      (0xF0000000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_SHIFT     (28U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_RESETVAL  (0x00000004U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_MAX       (0x0000000fU)

#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_MASK  (0x0001E000U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_SHIFT  (13U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_RESETVAL  (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_MAX   (0x0000000fU)

#define CSL_DWCUSB3_GHWPARAMS4_RESETVAL                         (0x48822004U)

/* GHWPARAMS5 */

#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_MASK    (0x0000000FU)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_SHIFT   (0U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_RESETVAL  (0x00000008U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_MAX     (0x0000000fU)

#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_MASK     (0x000003F0U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_SHIFT    (4U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_RESETVAL  (0x00000008U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_MASK     (0x0000FC00U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_SHIFT    (10U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_RESETVAL  (0x00000008U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_MASK     (0x003F0000U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_SHIFT    (16U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_RESETVAL  (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_MASK     (0x0FC00000U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_SHIFT    (22U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_RESETVAL  (0x00000010U)
#define CSL_DWCUSB3_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS5_RESETVAL                         (0x04202088U)

/* GHWPARAMS6 */

#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_MASK         (0xFFFF0000U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_SHIFT        (16U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_RESETVAL     (0x00000b00U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_MAX          (0x0000ffffU)

#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_EN_FPGA_MASK            (0x00000080U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_EN_FPGA_SHIFT           (7U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_EN_FPGA_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_EN_FPGA_MAX             (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_MASK     (0x0000003FU)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_SHIFT    (0U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_RESETVAL  (0x00000020U)
#define CSL_DWCUSB3_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_MAX      (0x0000003fU)

#define CSL_DWCUSB3_GHWPARAMS6_SRPSUPPORT_MASK                  (0x00000400U)
#define CSL_DWCUSB3_GHWPARAMS6_SRPSUPPORT_SHIFT                 (10U)
#define CSL_DWCUSB3_GHWPARAMS6_SRPSUPPORT_RESETVAL              (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS6_SRPSUPPORT_NO                    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_SRPSUPPORT_SUPPORT               (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_HNPSUPPORT_MASK                  (0x00000800U)
#define CSL_DWCUSB3_GHWPARAMS6_HNPSUPPORT_SHIFT                 (11U)
#define CSL_DWCUSB3_GHWPARAMS6_HNPSUPPORT_RESETVAL              (0x00000001U)
#define CSL_DWCUSB3_GHWPARAMS6_HNPSUPPORT_NO                    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_HNPSUPPORT_SUPPORT               (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_ADPSUPPORT_MASK                  (0x00001000U)
#define CSL_DWCUSB3_GHWPARAMS6_ADPSUPPORT_SHIFT                 (12U)
#define CSL_DWCUSB3_GHWPARAMS6_ADPSUPPORT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_ADPSUPPORT_NO                    (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_ADPSUPPORT_IMP                   (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_OTGSSSUPPORT_MASK                (0x00002000U)
#define CSL_DWCUSB3_GHWPARAMS6_OTGSSSUPPORT_SHIFT               (13U)
#define CSL_DWCUSB3_GHWPARAMS6_OTGSSSUPPORT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_OTGSSSUPPORT_NO                  (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_OTGSSSUPPORT_YES                 (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_BCSUPPORT_MASK                   (0x00004000U)
#define CSL_DWCUSB3_GHWPARAMS6_BCSUPPORT_SHIFT                  (14U)
#define CSL_DWCUSB3_GHWPARAMS6_BCSUPPORT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_BCSUPPORT_NO                     (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_BCSUPPORT_IMP                    (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_BUSFLTRSSUPPORT_MASK             (0x00008000U)
#define CSL_DWCUSB3_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT            (15U)
#define CSL_DWCUSB3_GHWPARAMS6_BUSFLTRSSUPPORT_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_BUSFLTRSSUPPORT_NO               (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS6_BUSFLTRSSUPPORT_IMP              (0x00000001U)

#define CSL_DWCUSB3_GHWPARAMS6_RESETVAL                         (0x0b000c20U)

/* GHWPARAMS7 */

#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_MASK         (0x0000FFFFU)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_SHIFT        (0U)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_RESETVAL     (0x00000780U)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_MAX          (0x0000ffffU)

#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_MASK         (0xFFFF0000U)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_SHIFT        (16U)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_RESETVAL     (0x00000308U)
#define CSL_DWCUSB3_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_MAX          (0x0000ffffU)

#define CSL_DWCUSB3_GHWPARAMS7_RESETVAL                         (0x03080780U)

/* GDBGFIFOSPACE */

#define CSL_DWCUSB3_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_MASK  (0x000000FFU)
#define CSL_DWCUSB3_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_SHIFT  (0U)
#define CSL_DWCUSB3_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_MAX  (0x000000ffU)

#define CSL_DWCUSB3_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK          (0xFFFF0000U)
#define CSL_DWCUSB3_GDBGFIFOSPACE_SPACE_AVAILABLE_SHIFT         (16U)
#define CSL_DWCUSB3_GDBGFIFOSPACE_SPACE_AVAILABLE_RESETVAL      (0x00000042U)
#define CSL_DWCUSB3_GDBGFIFOSPACE_SPACE_AVAILABLE_MAX           (0x0000ffffU)

#define CSL_DWCUSB3_GDBGFIFOSPACE_RESETVAL                      (0x00420000U)

/* GDBGLTSSM */

#define CSL_DWCUSB3_GDBGLTSSM_TXONESZEROS_MASK                  (0x00000001U)
#define CSL_DWCUSB3_GDBGLTSSM_TXONESZEROS_SHIFT                 (0U)
#define CSL_DWCUSB3_GDBGLTSSM_TXONESZEROS_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_TXONESZEROS_MAX                   (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_RXTERMINATION_MASK                (0x00000002U)
#define CSL_DWCUSB3_GDBGLTSSM_RXTERMINATION_SHIFT               (1U)
#define CSL_DWCUSB3_GDBGLTSSM_RXTERMINATION_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_RXTERMINATION_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_TXSWING_MASK                      (0x00000004U)
#define CSL_DWCUSB3_GDBGLTSSM_TXSWING_SHIFT                     (2U)
#define CSL_DWCUSB3_GDBGLTSSM_TXSWING_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_TXSWING_MAX                       (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_MASK                 (0x00000038U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_SHIFT                (3U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_NORM             (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_WAIT1            (0x00000002U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_P3               (0x00000003U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_TO_P0            (0x00000004U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_WAIT2            (0x00000005U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBCLKSTATE_CLK_TO_P3            (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_TXDEEMPHASIS_MASK                 (0x000000C0U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDEEMPHASIS_SHIFT                (6U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDEEMPHASIS_RESETVAL             (0x00000001U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDEEMPHASIS_MAX                  (0x00000003U)

#define CSL_DWCUSB3_GDBGLTSSM_RXEQTRAIN_MASK                    (0x00000100U)
#define CSL_DWCUSB3_GDBGLTSSM_RXEQTRAIN_SHIFT                   (8U)
#define CSL_DWCUSB3_GDBGLTSSM_RXEQTRAIN_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_RXEQTRAIN_MAX                     (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_POWERDOWN_MASK                    (0x00000600U)
#define CSL_DWCUSB3_GDBGLTSSM_POWERDOWN_SHIFT                   (9U)
#define CSL_DWCUSB3_GDBGLTSSM_POWERDOWN_RESETVAL                (0x00000002U)
#define CSL_DWCUSB3_GDBGLTSSM_POWERDOWN_MAX                     (0x00000003U)

#define CSL_DWCUSB3_GDBGLTSSM_TXDETRXLOOPBACK_MASK              (0x00004000U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDETRXLOOPBACK_SHIFT             (14U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDETRXLOOPBACK_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_TXDETRXLOOPBACK_MAX               (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_RXPOLARITY_MASK                   (0x00008000U)
#define CSL_DWCUSB3_GDBGLTSSM_RXPOLARITY_SHIFT                  (15U)
#define CSL_DWCUSB3_GDBGLTSSM_RXPOLARITY_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_RXPOLARITY_MAX                    (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_TXELECIDLE_MASK                   (0x00010000U)
#define CSL_DWCUSB3_GDBGLTSSM_TXELECIDLE_SHIFT                  (16U)
#define CSL_DWCUSB3_GDBGLTSSM_TXELECIDLE_RESETVAL               (0x00000001U)
#define CSL_DWCUSB3_GDBGLTSSM_TXELECIDLE_MAX                    (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_ELASTICBUFFERMODE_MASK            (0x00020000U)
#define CSL_DWCUSB3_GDBGLTSSM_ELASTICBUFFERMODE_SHIFT           (17U)
#define CSL_DWCUSB3_GDBGLTSSM_ELASTICBUFFERMODE_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_ELASTICBUFFERMODE_MAX             (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_LTDBSUBSTATE_MASK                 (0x003C0000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBSUBSTATE_SHIFT                (18U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBSUBSTATE_RESETVAL             (0x00000002U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBSUBSTATE_MAX                  (0x0000000fU)

#define CSL_DWCUSB3_GDBGLTSSM_LTDBLINKSTATE_MASK                (0x03C00000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBLINKSTATE_SHIFT               (22U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBLINKSTATE_RESETVAL            (0x00000004U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBLINKSTATE_MAX                 (0x0000000fU)

#define CSL_DWCUSB3_GDBGLTSSM_LTDBTIMEOUT_MASK                  (0x04000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBTIMEOUT_SHIFT                 (26U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBTIMEOUT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBTIMEOUT_MAX                   (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_MASK              (0x00003800U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_SHIFT             (11U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_IDLE          (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_DET           (0x00000001U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_DET_3         (0x00000002U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_DLY       (0x00000003U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_A         (0x00000004U)
#define CSL_DWCUSB3_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_B         (0x00000005U)

#define CSL_DWCUSB3_GDBGLTSSM_PORTDIRECTION_MASK                (0x08000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTDIRECTION_SHIFT               (27U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTDIRECTION_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTDIRECTION_US                  (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTDIRECTION_DS                  (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_PORTSWAPPING_MASK                 (0x10000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSWAPPING_SHIFT                (28U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSWAPPING_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSWAPPING_MAX                  (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_PORTSHUTDOWN_MASK                 (0x20000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSHUTDOWN_SHIFT                (29U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSHUTDOWN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GDBGLTSSM_PORTSHUTDOWN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_GDBGLTSSM_RESETVAL                          (0x01090440U)

/* GUCTL */

#define CSL_DWCUSB3_GUCTL_DTFT_MASK                             (0x000001FFU)
#define CSL_DWCUSB3_GUCTL_DTFT_SHIFT                            (0U)
#define CSL_DWCUSB3_GUCTL_DTFT_RESETVAL                         (0x00000010U)
#define CSL_DWCUSB3_GUCTL_DTFT_MAX                              (0x000001ffU)

#define CSL_DWCUSB3_GUCTL_DTCT_MASK                             (0x00000600U)
#define CSL_DWCUSB3_GUCTL_DTCT_SHIFT                            (9U)
#define CSL_DWCUSB3_GUCTL_DTCT_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_GUCTL_DTCT_FINE                             (0x00000000U)
#define CSL_DWCUSB3_GUCTL_DTCT__0M5                             (0x00000001U)
#define CSL_DWCUSB3_GUCTL_DTCT__1M5                             (0x00000002U)
#define CSL_DWCUSB3_GUCTL_DTCT__5MS                             (0x00000003U)

#define CSL_DWCUSB3_GUCTL_USBHSTINAUTORETRYEN_MASK              (0x00004000U)
#define CSL_DWCUSB3_GUCTL_USBHSTINAUTORETRYEN_SHIFT             (14U)
#define CSL_DWCUSB3_GUCTL_USBHSTINAUTORETRYEN_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_GUCTL_USBHSTINAUTORETRYEN_DIS               (0x00000000U)
#define CSL_DWCUSB3_GUCTL_USBHSTINAUTORETRYEN_EN                (0x00000001U)

#define CSL_DWCUSB3_GUCTL_CMDEVADDR_MASK                        (0x00008000U)
#define CSL_DWCUSB3_GUCTL_CMDEVADDR_SHIFT                       (15U)
#define CSL_DWCUSB3_GUCTL_CMDEVADDR_RESETVAL                    (0x00000001U)
#define CSL_DWCUSB3_GUCTL_CMDEVADDR_EQ                          (0x00000000U)
#define CSL_DWCUSB3_GUCTL_CMDEVADDR_DIFF                        (0x00000001U)

#define CSL_DWCUSB3_GUCTL_RESBWHSEPS_MASK                       (0x00010000U)
#define CSL_DWCUSB3_GUCTL_RESBWHSEPS_SHIFT                      (16U)
#define CSL_DWCUSB3_GUCTL_RESBWHSEPS_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_GUCTL_RESBWHSEPS__80                        (0x00000000U)
#define CSL_DWCUSB3_GUCTL_RESBWHSEPS__85                        (0x00000001U)

#define CSL_DWCUSB3_GUCTL_SPRSCTRLTRANSEN_MASK                  (0x00020000U)
#define CSL_DWCUSB3_GUCTL_SPRSCTRLTRANSEN_SHIFT                 (17U)
#define CSL_DWCUSB3_GUCTL_SPRSCTRLTRANSEN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GUCTL_SPRSCTRLTRANSEN_DIS                   (0x00000000U)
#define CSL_DWCUSB3_GUCTL_SPRSCTRLTRANSEN_EN                    (0x00000001U)

#define CSL_DWCUSB3_GUCTL_PSQEXTRRESSP_MASK                     (0x001C0000U)
#define CSL_DWCUSB3_GUCTL_PSQEXTRRESSP_SHIFT                    (18U)
#define CSL_DWCUSB3_GUCTL_PSQEXTRRESSP_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GUCTL_PSQEXTRRESSP_DIS                      (0x00000000U)
#define CSL_DWCUSB3_GUCTL_PSQEXTRRESSP_EN                       (0x00000001U)

#define CSL_DWCUSB3_GUCTL_NOEXTRDL_MASK                         (0x00200000U)
#define CSL_DWCUSB3_GUCTL_NOEXTRDL_SHIFT                        (21U)
#define CSL_DWCUSB3_GUCTL_NOEXTRDL_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_GUCTL_NOEXTRDL_DIS                          (0x00000000U)
#define CSL_DWCUSB3_GUCTL_NOEXTRDL_EN                           (0x00000001U)

#define CSL_DWCUSB3_GUCTL_RESETVAL                              (0x00008010U)

/* GPRTBIMAP_HSLO */

#define CSL_DWCUSB3_GPRTBIMAP_HSLO_BINUM1_MASK                  (0x0000000FU)
#define CSL_DWCUSB3_GPRTBIMAP_HSLO_BINUM1_SHIFT                 (0U)
#define CSL_DWCUSB3_GPRTBIMAP_HSLO_BINUM1_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GPRTBIMAP_HSLO_BINUM1_MAX                   (0x0000000fU)

#define CSL_DWCUSB3_GPRTBIMAP_HSLO_RESETVAL                     (0x00000000U)

/* GPRTBIMAP_HSHI */

#define CSL_DWCUSB3_GPRTBIMAP_HSHI_RESETVAL                     (0x00000000U)

/* GPRTBIMAP_FSLO */

#define CSL_DWCUSB3_GPRTBIMAP_FSLO_BINUM1_MASK                  (0x0000000FU)
#define CSL_DWCUSB3_GPRTBIMAP_FSLO_BINUM1_SHIFT                 (0U)
#define CSL_DWCUSB3_GPRTBIMAP_FSLO_BINUM1_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GPRTBIMAP_FSLO_BINUM1_MAX                   (0x0000000fU)

#define CSL_DWCUSB3_GPRTBIMAP_FSLO_RESETVAL                     (0x00000000U)

/* GPRTBIMAP_FSHI */

#define CSL_DWCUSB3_GPRTBIMAP_FSHI_RESETVAL                     (0x00000000U)

/* GDBGLSPMUX */

#define CSL_DWCUSB3_GDBGLSPMUX_EPSELECT_MASK                    (0x0000000FU)
#define CSL_DWCUSB3_GDBGLSPMUX_EPSELECT_SHIFT                   (0U)
#define CSL_DWCUSB3_GDBGLSPMUX_EPSELECT_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GDBGLSPMUX_EPSELECT_MAX                     (0x0000000fU)

#define CSL_DWCUSB3_GDBGLSPMUX_DEVSELECT_MASK                   (0x000000F0U)
#define CSL_DWCUSB3_GDBGLSPMUX_DEVSELECT_SHIFT                  (4U)
#define CSL_DWCUSB3_GDBGLSPMUX_DEVSELECT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GDBGLSPMUX_DEVSELECT_MAX                    (0x0000000fU)

#define CSL_DWCUSB3_GDBGLSPMUX_HOSTSELECT_MASK                  (0x00003F00U)
#define CSL_DWCUSB3_GDBGLSPMUX_HOSTSELECT_SHIFT                 (8U)
#define CSL_DWCUSB3_GDBGLSPMUX_HOSTSELECT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GDBGLSPMUX_HOSTSELECT_MAX                   (0x0000003fU)

#define CSL_DWCUSB3_GDBGLSPMUX_TRACEPORTMUXSEL_MASK             (0x003F0000U)
#define CSL_DWCUSB3_GDBGLSPMUX_TRACEPORTMUXSEL_SHIFT            (16U)
#define CSL_DWCUSB3_GDBGLSPMUX_TRACEPORTMUXSEL_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GDBGLSPMUX_TRACEPORTMUXSEL_MAX              (0x0000003fU)

#define CSL_DWCUSB3_GDBGLSPMUX_RESETVAL                         (0x00000000U)

/* GDBGLSP */

#define CSL_DWCUSB3_GDBGLSP_DEBUG_MASK                          (0xFFFFFFFFU)
#define CSL_DWCUSB3_GDBGLSP_DEBUG_SHIFT                         (0U)
#define CSL_DWCUSB3_GDBGLSP_DEBUG_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_GDBGLSP_DEBUG_MAX                           (0xffffffffU)

#define CSL_DWCUSB3_GDBGLSP_RESETVAL                            (0x00000000U)

/* GDBGEPINFO0 */

#define CSL_DWCUSB3_GDBGEPINFO0_DEBUG_MASK                      (0xFFFFFFFFU)
#define CSL_DWCUSB3_GDBGEPINFO0_DEBUG_SHIFT                     (0U)
#define CSL_DWCUSB3_GDBGEPINFO0_DEBUG_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GDBGEPINFO0_DEBUG_MAX                       (0xffffffffU)

#define CSL_DWCUSB3_GDBGEPINFO0_RESETVAL                        (0x00000000U)

/* GDBGEPINFO1 */

#define CSL_DWCUSB3_GDBGEPINFO1_DEBUG_MASK                      (0xFFFFFFFFU)
#define CSL_DWCUSB3_GDBGEPINFO1_DEBUG_SHIFT                     (0U)
#define CSL_DWCUSB3_GDBGEPINFO1_DEBUG_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GDBGEPINFO1_DEBUG_MAX                       (0xffffffffU)

#define CSL_DWCUSB3_GDBGEPINFO1_RESETVAL                        (0x00000000U)

/* GDBGLNMCC */

#define CSL_DWCUSB3_GDBGLNMCC_LNMCC_BERC_MASK                   (0x000001FFU)
#define CSL_DWCUSB3_GDBGLNMCC_LNMCC_BERC_SHIFT                  (0U)
#define CSL_DWCUSB3_GDBGLNMCC_LNMCC_BERC_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GDBGLNMCC_LNMCC_BERC_MAX                    (0x000001ffU)

#define CSL_DWCUSB3_GDBGLNMCC_RESETVAL                          (0x00000000U)

/* GDBGBMU */

#define CSL_DWCUSB3_GDBGBMU_BMU_CCU_MASK                        (0x0000000FU)
#define CSL_DWCUSB3_GDBGBMU_BMU_CCU_SHIFT                       (0U)
#define CSL_DWCUSB3_GDBGBMU_BMU_CCU_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_GDBGBMU_BMU_CCU_MAX                         (0x0000000fU)

#define CSL_DWCUSB3_GDBGBMU_BMU_DCU_MASK                        (0x000000F0U)
#define CSL_DWCUSB3_GDBGBMU_BMU_DCU_SHIFT                       (4U)
#define CSL_DWCUSB3_GDBGBMU_BMU_DCU_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_GDBGBMU_BMU_DCU_MAX                         (0x0000000fU)

#define CSL_DWCUSB3_GDBGBMU_BMU_BCU_MASK                        (0xFFFFFF00U)
#define CSL_DWCUSB3_GDBGBMU_BMU_BCU_SHIFT                       (8U)
#define CSL_DWCUSB3_GDBGBMU_BMU_BCU_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_GDBGBMU_BMU_BCU_MAX                         (0x00ffffffU)

#define CSL_DWCUSB3_GDBGBMU_RESETVAL                            (0x00000000U)

/* GUSB2PHYCFG */

#define CSL_DWCUSB3_GUSB2PHYCFG_TOUTCAL_MASK                    (0x00000007U)
#define CSL_DWCUSB3_GUSB2PHYCFG_TOUTCAL_SHIFT                   (0U)
#define CSL_DWCUSB3_GUSB2PHYCFG_TOUTCAL_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_TOUTCAL_MAX                     (0x00000007U)

#define CSL_DWCUSB3_GUSB2PHYCFG_PHYIF_MASK                      (0x00000008U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYIF_SHIFT                     (3U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYIF_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYIF_ZERO                      (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYIF_ONE                       (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK              (0x00000010U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPI_UTMI_SEL_SHIFT             (4U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPI_UTMI_SEL_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPI_UTMI_SEL_UTMI              (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPI_UTMI_SEL_ULPI              (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_FSINTF_MASK                     (0x00000020U)
#define CSL_DWCUSB3_GUSB2PHYCFG_FSINTF_SHIFT                    (5U)
#define CSL_DWCUSB3_GUSB2PHYCFG_FSINTF_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_FSINTF_MAX                      (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_SUSPHY_MASK                     (0x00000040U)
#define CSL_DWCUSB3_GUSB2PHYCFG_SUSPHY_SHIFT                    (6U)
#define CSL_DWCUSB3_GUSB2PHYCFG_SUSPHY_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_SUSPHY__0                       (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_SUSPHY__1                       (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSEL_MASK                     (0x00000080U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSEL_SHIFT                    (7U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSEL_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSEL_MAX                      (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_ENBLSLPM_MASK                   (0x00000100U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ENBLSLPM_SHIFT                  (8U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ENBLSLPM_RESETVAL               (0x00000001U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ENBLSLPM_NO                     (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ENBLSLPM_YES                    (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_USBTRDTIM_MASK                  (0x00003C00U)
#define CSL_DWCUSB3_GUSB2PHYCFG_USBTRDTIM_SHIFT                 (10U)
#define CSL_DWCUSB3_GUSB2PHYCFG_USBTRDTIM_RESETVAL              (0x00000009U)
#define CSL_DWCUSB3_GUSB2PHYCFG_USBTRDTIM_MAX                   (0x0000000fU)

#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIAUTORES_MASK                (0x00008000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIAUTORES_SHIFT               (15U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIAUTORES_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIAUTORES_NO                  (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIAUTORES_AUTO                (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_ULPICLKSUSM_MASK                (0x00010000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPICLKSUSM_SHIFT               (16U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPICLKSUSM_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPICLKSUSM_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK             (0x00020000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_SHIFT            (17U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_INT              (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_EXT              (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_MASK       (0x00040000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_SHIFT      (18U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_RESETVAL   (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_INT        (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_EXT        (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSOFTRST_MASK                 (0x80000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSOFTRST_SHIFT                (31U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSOFTRST_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSOFTRST_INACTIVE             (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYCFG_PHYSOFTRST_ACTIVE               (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYCFG_RESETVAL                        (0x00002500U)

/* GUSB2PHYACC */

#define CSL_DWCUSB3_GUSB2PHYACC_REGDATA_MASK                    (0x000000FFU)
#define CSL_DWCUSB3_GUSB2PHYACC_REGDATA_SHIFT                   (0U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGDATA_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGDATA_MAX                     (0x000000ffU)

#define CSL_DWCUSB3_GUSB2PHYACC_EXTREGADDR_MASK                 (0x00003F00U)
#define CSL_DWCUSB3_GUSB2PHYACC_EXTREGADDR_SHIFT                (8U)
#define CSL_DWCUSB3_GUSB2PHYACC_EXTREGADDR_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_EXTREGADDR_MAX                  (0x0000003fU)

#define CSL_DWCUSB3_GUSB2PHYACC_REGADDR_MASK                    (0x003F0000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGADDR_SHIFT                   (16U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGADDR_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGADDR_MAX                     (0x0000003fU)

#define CSL_DWCUSB3_GUSB2PHYACC_REGWR_MASK                      (0x00400000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGWR_SHIFT                     (22U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGWR_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGWR_RD                        (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_REGWR_WR                        (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYACC_VSTSBSY_MASK                    (0x00800000U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSBSY_SHIFT                   (23U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSBSY_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSBSY_DONE                    (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSBSY_BUSY                    (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYACC_VSTSDONE_MASK                   (0x01000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSDONE_SHIFT                  (24U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSDONE_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSDONE_DONE                   (0x00000001U)
#define CSL_DWCUSB3_GUSB2PHYACC_VSTSDONE_NOTDONE                (0x00000000U)

#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_MASK                  (0x02000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_SHIFT                 (25U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_NEW                   (0x00000001U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_NONE                  (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_ACTIVE                (0x00000001U)
#define CSL_DWCUSB3_GUSB2PHYACC_NEWREGREQ_IDLE                  (0x00000000U)

#define CSL_DWCUSB3_GUSB2PHYACC_DISULPIDRVR_MASK                (0x04000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_DISULPIDRVR_SHIFT               (26U)
#define CSL_DWCUSB3_GUSB2PHYACC_DISULPIDRVR_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB2PHYACC_DISULPIDRVR_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GUSB2PHYACC_RESETVAL                        (0x00000000U)

/* GUSB3PIPECTL */

#define CSL_DWCUSB3_GUSB3PIPECTL_ELASTICBUFFERMODE_MASK         (0x00000001U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ELASTICBUFFERMODE_SHIFT        (0U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ELASTICBUFFERMODE_RESETVAL     (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ELASTICBUFFERMODE_MAX          (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_TXDEEMPHASIS_MASK              (0x00000006U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXDEEMPHASIS_SHIFT             (1U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXDEEMPHASIS_RESETVAL          (0x00000001U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXDEEMPHASIS_MAX               (0x00000003U)

#define CSL_DWCUSB3_GUSB3PIPECTL_TXMARGIN_MASK                  (0x00000038U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXMARGIN_SHIFT                 (3U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXMARGIN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXMARGIN_MAX                   (0x00000007U)

#define CSL_DWCUSB3_GUSB3PIPECTL_TXSWING_MASK                   (0x00000040U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXSWING_SHIFT                  (6U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXSWING_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_TXSWING_MAX                    (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSFILT_MASK                  (0x00000200U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSFILT_SHIFT                 (9U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSFILT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSFILT_MAX                   (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_P3P2TRANOK_MASK                (0x00000800U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3P2TRANOK_SHIFT               (11U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3P2TRANOK_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3P2TRANOK_NOTSET              (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3P2TRANOK_SET                 (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSP0ALGN_MASK                (0x00001000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSP0ALGN_SHIFT               (12U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSP0ALGN_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSP0ALGN_DEF                 (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_LFPSP0ALGN_ALIGN               (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_SKIPRXDET_MASK                 (0x00002000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SKIPRXDET_SHIFT                (13U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SKIPRXDET_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SKIPRXDET_MAX                  (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH_MASK                  (0x00018000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH_SHIFT                 (15U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH__32                   (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH__16                   (0x00000001U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DATWIDTH__8                    (0x00000002U)

#define CSL_DWCUSB3_GUSB3PIPECTL_SUSPENDENABLE_MASK             (0x00020000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SUSPENDENABLE_SHIFT            (17U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SUSPENDENABLE_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SUSPENDENABLE__0               (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_SUSPENDENABLE__1               (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_ABORTRXDETINU2_MASK            (0x00004000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ABORTRXDETINU2_SHIFT           (14U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ABORTRXDETINU2_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ABORTRXDETINU2_NO_ABORT        (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_ABORTRXDETINU2_ABORT           (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_DELAYP0TOP1P2P3_MASK           (0x00040000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DELAYP0TOP1P2P3_SHIFT          (18U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DELAYP0TOP1P2P3_RESETVAL       (0x00000001U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DELAYP0TOP1P2P3_DIS            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DELAYP0TOP1P2P3_EN             (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_PHYSOFTRST_MASK                (0x80000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PHYSOFTRST_SHIFT               (31U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PHYSOFTRST_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PHYSOFTRST_INACTIVE            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PHYSOFTRST_ACTIVE              (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_DISRXDETU3RXDET_MASK           (0x00400000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DISRXDETU3RXDET_SHIFT          (22U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DISRXDETU3RXDET_RESETVAL       (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DISRXDETU3RXDET_AUTO           (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_DISRXDETU3RXDET_MANUAL         (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK         (0x00800000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_STARTRXDETU3RXDET_SHIFT        (23U)
#define CSL_DWCUSB3_GUSB3PIPECTL_STARTRXDETU3RXDET_RESETVAL     (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_STARTRXDETU3RXDET_NOOP         (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_STARTRXDETU3RXDET_DETECT       (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_P1P2P3DELAY_MASK               (0x00380000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P1P2P3DELAY_SHIFT              (19U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P1P2P3DELAY_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P1P2P3DELAY_MAX                (0x00000007U)

#define CSL_DWCUSB3_GUSB3PIPECTL_REQUEST_P1P2P3_MASK            (0x01000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_REQUEST_P1P2P3_SHIFT           (24U)
#define CSL_DWCUSB3_GUSB3PIPECTL_REQUEST_P1P2P3_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_REQUEST_P1P2P3_NONE            (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_REQUEST_P1P2P3_ALWAYS          (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK     (0x02000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_SHIFT    (25U)
#define CSL_DWCUSB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_RESETVAL  (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_DEFAULT  (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_ENHANCED  (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK       (0x04000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_SHIFT      (26U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_RESETVAL   (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_DEFAULT    (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN__500       (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK             (0x08000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_UX_EXIT_IN_PX_SHIFT            (27U)
#define CSL_DWCUSB3_GUSB3PIPECTL_UX_EXIT_IN_PX_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_UX_EXIT_IN_PX_DEFAULT          (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_UX_EXIT_IN_PX_WA               (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_P3EXSIGP2_MASK                 (0x00000400U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3EXSIGP2_SHIFT                (10U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3EXSIGP2_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3EXSIGP2_DEFAULT              (0x00000000U)
#define CSL_DWCUSB3_GUSB3PIPECTL_P3EXSIGP2_P2                   (0x00000001U)

#define CSL_DWCUSB3_GUSB3PIPECTL_RESETVAL                       (0x00040002U)

/* GTXFIFOSIZ0 */

#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFDEP_RESETVAL                 (0x00000042U)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFSTADDR_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GTXFIFOSIZ0_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ0_RESETVAL                        (0x00000042U)

/* GTXFIFOSIZ1 */

#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFDEP_RESETVAL                 (0x00000184U)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFSTADDR_RESETVAL              (0x00000042U)
#define CSL_DWCUSB3_GTXFIFOSIZ1_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ1_RESETVAL                        (0x00420184U)

/* GTXFIFOSIZ2 */

#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFDEP_RESETVAL                 (0x00000184U)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFSTADDR_RESETVAL              (0x000001c6U)
#define CSL_DWCUSB3_GTXFIFOSIZ2_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ2_RESETVAL                        (0x01c60184U)

/* GTXFIFOSIZ3 */

#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFDEP_RESETVAL                 (0x00000184U)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFSTADDR_RESETVAL              (0x0000034aU)
#define CSL_DWCUSB3_GTXFIFOSIZ3_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ3_RESETVAL                        (0x034a0184U)

/* GTXFIFOSIZ4 */

#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFDEP_RESETVAL                 (0x00000184U)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFSTADDR_RESETVAL              (0x000004ceU)
#define CSL_DWCUSB3_GTXFIFOSIZ4_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ4_RESETVAL                        (0x04ce0184U)

/* GTXFIFOSIZ5 */

#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFDEP_RESETVAL                 (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFSTADDR_RESETVAL              (0x00000652U)
#define CSL_DWCUSB3_GTXFIFOSIZ5_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ5_RESETVAL                        (0x06520013U)

/* GTXFIFOSIZ6 */

#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFDEP_RESETVAL                 (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFSTADDR_RESETVAL              (0x00000665U)
#define CSL_DWCUSB3_GTXFIFOSIZ6_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ6_RESETVAL                        (0x06650013U)

/* GTXFIFOSIZ7 */

#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFDEP_RESETVAL                 (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFSTADDR_RESETVAL              (0x00000678U)
#define CSL_DWCUSB3_GTXFIFOSIZ7_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ7_RESETVAL                        (0x06780013U)

/* GTXFIFOSIZ8 */

#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFDEP_RESETVAL                 (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFSTADDR_RESETVAL              (0x0000068bU)
#define CSL_DWCUSB3_GTXFIFOSIZ8_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ8_RESETVAL                        (0x068b0013U)

/* GTXFIFOSIZ9 */

#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFDEP_RESETVAL                 (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFSTADDR_RESETVAL              (0x0000069eU)
#define CSL_DWCUSB3_GTXFIFOSIZ9_TXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ9_RESETVAL                        (0x069e0013U)

/* GTXFIFOSIZ10 */

#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFSTADDR_RESETVAL             (0x000006b1U)
#define CSL_DWCUSB3_GTXFIFOSIZ10_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ10_RESETVAL                       (0x06b10013U)

/* GTXFIFOSIZ11 */

#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFSTADDR_RESETVAL             (0x000006c4U)
#define CSL_DWCUSB3_GTXFIFOSIZ11_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ11_RESETVAL                       (0x06c40013U)

/* GTXFIFOSIZ12 */

#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFSTADDR_RESETVAL             (0x000006d7U)
#define CSL_DWCUSB3_GTXFIFOSIZ12_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ12_RESETVAL                       (0x06d70013U)

/* GTXFIFOSIZ13 */

#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFSTADDR_RESETVAL             (0x000006eaU)
#define CSL_DWCUSB3_GTXFIFOSIZ13_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ13_RESETVAL                       (0x06ea0013U)

/* GTXFIFOSIZ14 */

#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFSTADDR_RESETVAL             (0x000006fdU)
#define CSL_DWCUSB3_GTXFIFOSIZ14_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ14_RESETVAL                       (0x06fd0013U)

/* GTXFIFOSIZ15 */

#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFDEP_MASK                    (0x0000FFFFU)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFDEP_SHIFT                   (0U)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFDEP_RESETVAL                (0x00000013U)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFDEP_MAX                     (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFSTADDR_MASK                 (0xFFFF0000U)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFSTADDR_SHIFT                (16U)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFSTADDR_RESETVAL             (0x00000710U)
#define CSL_DWCUSB3_GTXFIFOSIZ15_TXFSTADDR_MAX                  (0x0000ffffU)

#define CSL_DWCUSB3_GTXFIFOSIZ15_RESETVAL                       (0x07100013U)

/* GRXFIFOSIZ0 */

#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFDEP_RESETVAL                 (0x00000185U)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFSTADDR_RESETVAL              (0x0000071eU)
#define CSL_DWCUSB3_GRXFIFOSIZ0_RXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ0_RESETVAL                        (0x071e0185U)

/* GRXFIFOSIZ1 */

#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFDEP_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFSTADDR_RESETVAL              (0x000008a3U)
#define CSL_DWCUSB3_GRXFIFOSIZ1_RXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ1_RESETVAL                        (0x08a30000U)

/* GRXFIFOSIZ2 */

#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFDEP_MASK                     (0x0000FFFFU)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFDEP_SHIFT                    (0U)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFDEP_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFDEP_MAX                      (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFSTADDR_MASK                  (0xFFFF0000U)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFSTADDR_SHIFT                 (16U)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFSTADDR_RESETVAL              (0x000008a3U)
#define CSL_DWCUSB3_GRXFIFOSIZ2_RXFSTADDR_MAX                   (0x0000ffffU)

#define CSL_DWCUSB3_GRXFIFOSIZ2_RESETVAL                        (0x08a30000U)

/* GEVNTADRLO */

#define CSL_DWCUSB3_GEVNTADRLO_EVNTADRLO_MASK                   (0xFFFFFFFFU)
#define CSL_DWCUSB3_GEVNTADRLO_EVNTADRLO_SHIFT                  (0U)
#define CSL_DWCUSB3_GEVNTADRLO_EVNTADRLO_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GEVNTADRLO_EVNTADRLO_MAX                    (0xffffffffU)

#define CSL_DWCUSB3_GEVNTADRLO_RESETVAL                         (0x00000000U)

/* GEVNTADRHI */

#define CSL_DWCUSB3_GEVNTADRHI_EVNTADRHI_MASK                   (0xFFFFFFFFU)
#define CSL_DWCUSB3_GEVNTADRHI_EVNTADRHI_SHIFT                  (0U)
#define CSL_DWCUSB3_GEVNTADRHI_EVNTADRHI_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GEVNTADRHI_EVNTADRHI_MAX                    (0xffffffffU)

#define CSL_DWCUSB3_GEVNTADRHI_RESETVAL                         (0x00000000U)

/* GEVNTSIZ */

#define CSL_DWCUSB3_GEVNTSIZ_EVENTSIZ_MASK                      (0x0000FFFFU)
#define CSL_DWCUSB3_GEVNTSIZ_EVENTSIZ_SHIFT                     (0U)
#define CSL_DWCUSB3_GEVNTSIZ_EVENTSIZ_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_GEVNTSIZ_EVENTSIZ_MAX                       (0x0000ffffU)

#define CSL_DWCUSB3_GEVNTSIZ_EVNTINTRPTMASK_MASK                (0x80000000U)
#define CSL_DWCUSB3_GEVNTSIZ_EVNTINTRPTMASK_SHIFT               (31U)
#define CSL_DWCUSB3_GEVNTSIZ_EVNTINTRPTMASK_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_GEVNTSIZ_EVNTINTRPTMASK_MAX                 (0x00000001U)

#define CSL_DWCUSB3_GEVNTSIZ_RESETVAL                           (0x00000000U)

/* GEVNTCOUNT */

#define CSL_DWCUSB3_GEVNTCOUNT_EVNTCOUNT_MASK                   (0x0000FFFFU)
#define CSL_DWCUSB3_GEVNTCOUNT_EVNTCOUNT_SHIFT                  (0U)
#define CSL_DWCUSB3_GEVNTCOUNT_EVNTCOUNT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_GEVNTCOUNT_EVNTCOUNT_MAX                    (0x0000ffffU)

#define CSL_DWCUSB3_GEVNTCOUNT_RESETVAL                         (0x00000000U)

/* GHWPARAMS8 */

#define CSL_DWCUSB3_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_MASK  (0xFFFFFFFFU)
#define CSL_DWCUSB3_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_SHIFT  (0U)
#define CSL_DWCUSB3_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_RESETVAL  (0x0000071eU)
#define CSL_DWCUSB3_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_MAX   (0xffffffffU)

#define CSL_DWCUSB3_GHWPARAMS8_RESETVAL                         (0x0000071eU)

/* GHWPARAMS9 */

#define CSL_DWCUSB3_GHWPARAMS9_GHWPARAMS9_MASK                  (0xFFFFFFFFU)
#define CSL_DWCUSB3_GHWPARAMS9_GHWPARAMS9_SHIFT                 (0U)
#define CSL_DWCUSB3_GHWPARAMS9_GHWPARAMS9_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_GHWPARAMS9_GHWPARAMS9_MAX                   (0xffffffffU)

#define CSL_DWCUSB3_GHWPARAMS9_RESETVAL                         (0x00000000U)

/* DCFG */

#define CSL_DWCUSB3_DCFG_DEVSPD_MASK                            (0x00000007U)
#define CSL_DWCUSB3_DCFG_DEVSPD_SHIFT                           (0U)
#define CSL_DWCUSB3_DCFG_DEVSPD_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_DCFG_DEVSPD_HS                              (0x00000000U)
#define CSL_DWCUSB3_DCFG_DEVSPD_FS                              (0x00000001U)
#define CSL_DWCUSB3_DCFG_DEVSPD_SS                              (0x00000004U)
#define CSL_DWCUSB3_DCFG_DEVSPD_LS_SERIAL                       (0x00000002U)
#define CSL_DWCUSB3_DCFG_DEVSPD_FS_SERIAL                       (0x00000003U)

#define CSL_DWCUSB3_DCFG_DEVADDR_MASK                           (0x000003F8U)
#define CSL_DWCUSB3_DCFG_DEVADDR_SHIFT                          (3U)
#define CSL_DWCUSB3_DCFG_DEVADDR_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCFG_DEVADDR_MAX                            (0x0000007fU)

#define CSL_DWCUSB3_DCFG_PERFRINT_MASK                          (0x00000C00U)
#define CSL_DWCUSB3_DCFG_PERFRINT_SHIFT                         (10U)
#define CSL_DWCUSB3_DCFG_PERFRINT_RESETVAL                      (0x00000002U)
#define CSL_DWCUSB3_DCFG_PERFRINT__80                           (0x00000000U)
#define CSL_DWCUSB3_DCFG_PERFRINT__85                           (0x00000001U)
#define CSL_DWCUSB3_DCFG_PERFRINT__90                           (0x00000002U)
#define CSL_DWCUSB3_DCFG_PERFRINT__95                           (0x00000003U)

#define CSL_DWCUSB3_DCFG_INTRNUM_MASK                           (0x0001F000U)
#define CSL_DWCUSB3_DCFG_INTRNUM_SHIFT                          (12U)
#define CSL_DWCUSB3_DCFG_INTRNUM_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCFG_INTRNUM_MAX                            (0x0000001fU)

#define CSL_DWCUSB3_DCFG_NUMP_MASK                              (0x003E0000U)
#define CSL_DWCUSB3_DCFG_NUMP_SHIFT                             (17U)
#define CSL_DWCUSB3_DCFG_NUMP_RESETVAL                          (0x00000004U)
#define CSL_DWCUSB3_DCFG_NUMP_MAX                               (0x0000001fU)

#define CSL_DWCUSB3_DCFG_LPMCAP_MASK                            (0x00400000U)
#define CSL_DWCUSB3_DCFG_LPMCAP_SHIFT                           (22U)
#define CSL_DWCUSB3_DCFG_LPMCAP_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_DCFG_LPMCAP_NO                              (0x00000000U)
#define CSL_DWCUSB3_DCFG_LPMCAP_YES                             (0x00000001U)

#define CSL_DWCUSB3_DCFG_IGNORESTREAMPP_MASK                    (0x00800000U)
#define CSL_DWCUSB3_DCFG_IGNORESTREAMPP_SHIFT                   (23U)
#define CSL_DWCUSB3_DCFG_IGNORESTREAMPP_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_DCFG_IGNORESTREAMPP_NOCHANGE                (0x00000000U)
#define CSL_DWCUSB3_DCFG_IGNORESTREAMPP_IGNORE                  (0x00000001U)

#define CSL_DWCUSB3_DCFG_RESETVAL                               (0x00080800U)

/* DCTL */

#define CSL_DWCUSB3_DCTL_TSTCTL_MASK                            (0x0000001EU)
#define CSL_DWCUSB3_DCTL_TSTCTL_SHIFT                           (1U)
#define CSL_DWCUSB3_DCTL_TSTCTL_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_DCTL_TSTCTL_MAX                             (0x0000000fU)

#define CSL_DWCUSB3_DCTL_ULSTCHNGREQ_MASK                       (0x000001E0U)
#define CSL_DWCUSB3_DCTL_ULSTCHNGREQ_SHIFT                      (5U)
#define CSL_DWCUSB3_DCTL_ULSTCHNGREQ_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_ULSTCHNGREQ_MAX                        (0x0000000fU)

#define CSL_DWCUSB3_DCTL_ACCEPTU1ENA_MASK                       (0x00000200U)
#define CSL_DWCUSB3_DCTL_ACCEPTU1ENA_SHIFT                      (9U)
#define CSL_DWCUSB3_DCTL_ACCEPTU1ENA_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_ACCEPTU1ENA_NO                         (0x00000000U)
#define CSL_DWCUSB3_DCTL_ACCEPTU1ENA_YES                        (0x00000001U)

#define CSL_DWCUSB3_DCTL_INITU1ENA_MASK                         (0x00000400U)
#define CSL_DWCUSB3_DCTL_INITU1ENA_SHIFT                        (10U)
#define CSL_DWCUSB3_DCTL_INITU1ENA_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_DCTL_INITU1ENA_NO                           (0x00000000U)
#define CSL_DWCUSB3_DCTL_INITU1ENA_YES                          (0x00000001U)

#define CSL_DWCUSB3_DCTL_ACCEPTU2ENA_MASK                       (0x00000800U)
#define CSL_DWCUSB3_DCTL_ACCEPTU2ENA_SHIFT                      (11U)
#define CSL_DWCUSB3_DCTL_ACCEPTU2ENA_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_ACCEPTU2ENA_NO                         (0x00000000U)
#define CSL_DWCUSB3_DCTL_ACCEPTU2ENA_YES                        (0x00000001U)

#define CSL_DWCUSB3_DCTL_INITU2ENA_MASK                         (0x00001000U)
#define CSL_DWCUSB3_DCTL_INITU2ENA_SHIFT                        (12U)
#define CSL_DWCUSB3_DCTL_INITU2ENA_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_DCTL_INITU2ENA_NEWENUM1                     (0x00000000U)
#define CSL_DWCUSB3_DCTL_INITU2ENA_NEWENUM2                     (0x00000001U)

#define CSL_DWCUSB3_DCTL_APPL1RES_MASK                          (0x00800000U)
#define CSL_DWCUSB3_DCTL_APPL1RES_SHIFT                         (23U)
#define CSL_DWCUSB3_DCTL_APPL1RES_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_DCTL_APPL1RES_CAN_NYET                      (0x00000000U)
#define CSL_DWCUSB3_DCTL_APPL1RES_ACK                           (0x00000001U)

#define CSL_DWCUSB3_DCTL_HIRDTHRES_TIME_MASK                    (0x0F000000U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_TIME_SHIFT                   (24U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_TIME_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_TIME_MAX                     (0x0000000fU)

#define CSL_DWCUSB3_DCTL_CSFTRST_MASK                           (0x40000000U)
#define CSL_DWCUSB3_DCTL_CSFTRST_SHIFT                          (30U)
#define CSL_DWCUSB3_DCTL_CSFTRST_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCTL_CSFTRST_IDLE                           (0x00000000U)
#define CSL_DWCUSB3_DCTL_CSFTRST_ACTIVE                         (0x00000001U)
#define CSL_DWCUSB3_DCTL_CSFTRST_RESET                          (0x00000001U)

#define CSL_DWCUSB3_DCTL_RUNSTOP_MASK                           (0x80000000U)
#define CSL_DWCUSB3_DCTL_RUNSTOP_SHIFT                          (31U)
#define CSL_DWCUSB3_DCTL_RUNSTOP_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DCTL_RUNSTOP_STOP                           (0x00000000U)
#define CSL_DWCUSB3_DCTL_RUNSTOP_START                          (0x00000001U)

#define CSL_DWCUSB3_DCTL_HIRDTHRES_4_MASK                       (0x10000000U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_4_SHIFT                      (28U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_4_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_HIRDTHRES_4_MAX                        (0x00000001U)

#define CSL_DWCUSB3_DCTL_CSS_MASK                               (0x00010000U)
#define CSL_DWCUSB3_DCTL_CSS_SHIFT                              (16U)
#define CSL_DWCUSB3_DCTL_CSS_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DCTL_CSS_SAVE                               (0x00000000U)
#define CSL_DWCUSB3_DCTL_CSS_NOACTION                           (0x00000001U)

#define CSL_DWCUSB3_DCTL_CRS_MASK                               (0x00020000U)
#define CSL_DWCUSB3_DCTL_CRS_SHIFT                              (17U)
#define CSL_DWCUSB3_DCTL_CRS_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DCTL_CRS_RESTORE                            (0x00000000U)
#define CSL_DWCUSB3_DCTL_CRS_NOACTION                           (0x00000001U)

#define CSL_DWCUSB3_DCTL_L1HIBERNATIONEN_MASK                   (0x00040000U)
#define CSL_DWCUSB3_DCTL_L1HIBERNATIONEN_SHIFT                  (18U)
#define CSL_DWCUSB3_DCTL_L1HIBERNATIONEN_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_DCTL_L1HIBERNATIONEN_MAX                    (0x00000001U)

#define CSL_DWCUSB3_DCTL_KEEPCONNECT_MASK                       (0x00080000U)
#define CSL_DWCUSB3_DCTL_KEEPCONNECT_SHIFT                      (19U)
#define CSL_DWCUSB3_DCTL_KEEPCONNECT_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_KEEPCONNECT_NOACTION                   (0x00000000U)
#define CSL_DWCUSB3_DCTL_KEEPCONNECT_KEEP                       (0x00000001U)

#define CSL_DWCUSB3_DCTL_RESETVAL                               (0x00000000U)

/* DEVTEN */

#define CSL_DWCUSB3_DEVTEN_DISCONNEVTEN_MASK                    (0x00000001U)
#define CSL_DWCUSB3_DEVTEN_DISCONNEVTEN_SHIFT                   (0U)
#define CSL_DWCUSB3_DEVTEN_DISCONNEVTEN_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_DISCONNEVTEN_MAX                     (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_USBRSTEN_MASK                        (0x00000002U)
#define CSL_DWCUSB3_DEVTEN_USBRSTEN_SHIFT                       (1U)
#define CSL_DWCUSB3_DEVTEN_USBRSTEN_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_USBRSTEN_MAX                         (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_CONNECTDONEEN_MASK                   (0x00000004U)
#define CSL_DWCUSB3_DEVTEN_CONNECTDONEEN_SHIFT                  (2U)
#define CSL_DWCUSB3_DEVTEN_CONNECTDONEEN_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_CONNECTDONEEN_MAX                    (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_ULSTCNGEN_MASK                       (0x00000008U)
#define CSL_DWCUSB3_DEVTEN_ULSTCNGEN_SHIFT                      (3U)
#define CSL_DWCUSB3_DEVTEN_ULSTCNGEN_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_ULSTCNGEN_MAX                        (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_WKUPEVTEN_MASK                       (0x00000010U)
#define CSL_DWCUSB3_DEVTEN_WKUPEVTEN_SHIFT                      (4U)
#define CSL_DWCUSB3_DEVTEN_WKUPEVTEN_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_WKUPEVTEN_MAX                        (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_EOPFEN_MASK                          (0x00000040U)
#define CSL_DWCUSB3_DEVTEN_EOPFEN_SHIFT                         (6U)
#define CSL_DWCUSB3_DEVTEN_EOPFEN_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_EOPFEN_MAX                           (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_SOFEN_MASK                           (0x00000080U)
#define CSL_DWCUSB3_DEVTEN_SOFEN_SHIFT                          (7U)
#define CSL_DWCUSB3_DEVTEN_SOFEN_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_SOFEN_MAX                            (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_ERRTICERREN_MASK                     (0x00000200U)
#define CSL_DWCUSB3_DEVTEN_ERRTICERREN_SHIFT                    (9U)
#define CSL_DWCUSB3_DEVTEN_ERRTICERREN_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_ERRTICERREN_MAX                      (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_CMDCMPLTEN_MASK                      (0x00000400U)
#define CSL_DWCUSB3_DEVTEN_CMDCMPLTEN_SHIFT                     (10U)
#define CSL_DWCUSB3_DEVTEN_CMDCMPLTEN_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_CMDCMPLTEN_MAX                       (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_EVNTOVERFLOWEN_MASK                  (0x00000800U)
#define CSL_DWCUSB3_DEVTEN_EVNTOVERFLOWEN_SHIFT                 (11U)
#define CSL_DWCUSB3_DEVTEN_EVNTOVERFLOWEN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_EVNTOVERFLOWEN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_VNDRDEVTSTRCVEDEN_MASK               (0x00001000U)
#define CSL_DWCUSB3_DEVTEN_VNDRDEVTSTRCVEDEN_SHIFT              (12U)
#define CSL_DWCUSB3_DEVTEN_VNDRDEVTSTRCVEDEN_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_VNDRDEVTSTRCVEDEN_MAX                (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_INACTTIMEOUTRCVEDEN_MASK             (0x00002000U)
#define CSL_DWCUSB3_DEVTEN_INACTTIMEOUTRCVEDEN_SHIFT            (13U)
#define CSL_DWCUSB3_DEVTEN_INACTTIMEOUTRCVEDEN_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_INACTTIMEOUTRCVEDEN_MAX              (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_HIBERNATIONREQEVTEN_MASK             (0x00000020U)
#define CSL_DWCUSB3_DEVTEN_HIBERNATIONREQEVTEN_SHIFT            (5U)
#define CSL_DWCUSB3_DEVTEN_HIBERNATIONREQEVTEN_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_DEVTEN_HIBERNATIONREQEVTEN_MAX              (0x00000001U)

#define CSL_DWCUSB3_DEVTEN_RESETVAL                             (0x00000000U)

/* DSTS */

#define CSL_DWCUSB3_DSTS_CONNECTSPD_MASK                        (0x00000007U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_SHIFT                       (0U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_RESETVAL                    (0x00000004U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_HS                          (0x00000000U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_FS                          (0x00000001U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_SS                          (0x00000004U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_LS_SERIAL                   (0x00000002U)
#define CSL_DWCUSB3_DSTS_CONNECTSPD_FS_SERIAL                   (0x00000003U)

#define CSL_DWCUSB3_DSTS_SOFFN_MASK                             (0x0001FFF8U)
#define CSL_DWCUSB3_DSTS_SOFFN_SHIFT                            (3U)
#define CSL_DWCUSB3_DSTS_SOFFN_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DSTS_SOFFN_MAX                              (0x00003fffU)

#define CSL_DWCUSB3_DSTS_RXFIFOEMPTY_MASK                       (0x00020000U)
#define CSL_DWCUSB3_DSTS_RXFIFOEMPTY_SHIFT                      (17U)
#define CSL_DWCUSB3_DSTS_RXFIFOEMPTY_RESETVAL                   (0x00000001U)
#define CSL_DWCUSB3_DSTS_RXFIFOEMPTY_NOTEMPTY                   (0x00000000U)
#define CSL_DWCUSB3_DSTS_RXFIFOEMPTY_EMPTY                      (0x00000001U)

#define CSL_DWCUSB3_DSTS_USBLNKST_MASK                          (0x003C0000U)
#define CSL_DWCUSB3_DSTS_USBLNKST_SHIFT                         (18U)
#define CSL_DWCUSB3_DSTS_USBLNKST_RESETVAL                      (0x00000004U)
#define CSL_DWCUSB3_DSTS_USBLNKST_MAX                           (0x0000000fU)

#define CSL_DWCUSB3_DSTS_DEVCTRLHLT_MASK                        (0x00400000U)
#define CSL_DWCUSB3_DSTS_DEVCTRLHLT_SHIFT                       (22U)
#define CSL_DWCUSB3_DSTS_DEVCTRLHLT_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_DSTS_DEVCTRLHLT_MAX                         (0x00000001U)

#define CSL_DWCUSB3_DSTS_COREIDLE_MASK                          (0x00800000U)
#define CSL_DWCUSB3_DSTS_COREIDLE_SHIFT                         (23U)
#define CSL_DWCUSB3_DSTS_COREIDLE_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_DSTS_COREIDLE_IDLE                          (0x00000001U)
#define CSL_DWCUSB3_DSTS_COREIDLE_ACTIVE                        (0x00000000U)

#define CSL_DWCUSB3_DSTS_SSS_MASK                               (0x01000000U)
#define CSL_DWCUSB3_DSTS_SSS_SHIFT                              (24U)
#define CSL_DWCUSB3_DSTS_SSS_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DSTS_SSS_IDLE                               (0x00000000U)
#define CSL_DWCUSB3_DSTS_SSS_SAVING                             (0x00000001U)

#define CSL_DWCUSB3_DSTS_RSS_MASK                               (0x02000000U)
#define CSL_DWCUSB3_DSTS_RSS_SHIFT                              (25U)
#define CSL_DWCUSB3_DSTS_RSS_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DSTS_RSS_IDLE                               (0x00000000U)
#define CSL_DWCUSB3_DSTS_RSS_RESTORING                          (0x00000001U)

#define CSL_DWCUSB3_DSTS_SRE_MASK                               (0x10000000U)
#define CSL_DWCUSB3_DSTS_SRE_SHIFT                              (28U)
#define CSL_DWCUSB3_DSTS_SRE_RESETVAL                           (0x00000000U)
#define CSL_DWCUSB3_DSTS_SRE_MAX                                (0x00000001U)

#define CSL_DWCUSB3_DSTS_DCNRD_MASK                             (0x20000000U)
#define CSL_DWCUSB3_DSTS_DCNRD_SHIFT                            (29U)
#define CSL_DWCUSB3_DSTS_DCNRD_RESETVAL                         (0x00000000U)
#define CSL_DWCUSB3_DSTS_DCNRD_WAIT                             (0x00000001U)
#define CSL_DWCUSB3_DSTS_DCNRD_RDY                              (0x00000000U)

#define CSL_DWCUSB3_DSTS_RESETVAL                               (0x00920004U)

/* DGCMDPAR */

#define CSL_DWCUSB3_DGCMDPAR_PARAMETER_MASK                     (0xFFFFFFFFU)
#define CSL_DWCUSB3_DGCMDPAR_PARAMETER_SHIFT                    (0U)
#define CSL_DWCUSB3_DGCMDPAR_PARAMETER_RESETVAL                 (0x00000000U)
#define CSL_DWCUSB3_DGCMDPAR_PARAMETER_MAX                      (0xffffffffU)

#define CSL_DWCUSB3_DGCMDPAR_RESETVAL                           (0x00000000U)

/* DGCMD */

#define CSL_DWCUSB3_DGCMD_CMDTYP_MASK                           (0x000000FFU)
#define CSL_DWCUSB3_DGCMD_CMDTYP_SHIFT                          (0U)
#define CSL_DWCUSB3_DGCMD_CMDTYP_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDTYP_MAX                            (0x000000ffU)

#define CSL_DWCUSB3_DGCMD_CMDIOC_MASK                           (0x00000100U)
#define CSL_DWCUSB3_DGCMD_CMDIOC_SHIFT                          (8U)
#define CSL_DWCUSB3_DGCMD_CMDIOC_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDIOC_IOC                            (0x00000001U)

#define CSL_DWCUSB3_DGCMD_CMDACT_MASK                           (0x00000400U)
#define CSL_DWCUSB3_DGCMD_CMDACT_SHIFT                          (10U)
#define CSL_DWCUSB3_DGCMD_CMDACT_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDACT_IDLE                           (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDACT_ACTIVE                         (0x00000001U)
#define CSL_DWCUSB3_DGCMD_CMDACT_START                          (0x00000001U)

#define CSL_DWCUSB3_DGCMD_CMDSTATUS_MASK                        (0x00008000U)
#define CSL_DWCUSB3_DGCMD_CMDSTATUS_SHIFT                       (15U)
#define CSL_DWCUSB3_DGCMD_CMDSTATUS_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDSTATUS_NONE                        (0x00000000U)
#define CSL_DWCUSB3_DGCMD_CMDSTATUS_NEWENUM2                    (0x00000001U)

#define CSL_DWCUSB3_DGCMD_RESETVAL                              (0x00000000U)

/* DALEPENA */

#define CSL_DWCUSB3_DALEPENA_USBACTEP0_OUT_MASK                 (0x00000001U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_OUT_SHIFT                (0U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP0_IN_MASK                  (0x00000002U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_IN_SHIFT                 (1U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP0_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP1_OUT_MASK                 (0x00000004U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_OUT_SHIFT                (2U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP1_IN_MASK                  (0x00000008U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_IN_SHIFT                 (3U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP1_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP2_OUT_MASK                 (0x00000010U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_OUT_SHIFT                (4U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP2_IN_MASK                  (0x00000020U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_IN_SHIFT                 (5U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP2_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP3_OUT_MASK                 (0x00000040U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_OUT_SHIFT                (6U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP3_IN_MASK                  (0x00000080U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_IN_SHIFT                 (7U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP3_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP4_OUT_MASK                 (0x00000100U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_OUT_SHIFT                (8U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP4_IN_MASK                  (0x00000200U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_IN_SHIFT                 (9U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP4_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP5_OUT_MASK                 (0x00000400U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_OUT_SHIFT                (10U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP5_IN_MASK                  (0x00000800U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_IN_SHIFT                 (11U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP5_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP6_OUT_MASK                 (0x00001000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_OUT_SHIFT                (12U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP6_IN_MASK                  (0x00002000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_IN_SHIFT                 (13U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP6_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP7_OUT_MASK                 (0x00004000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_OUT_SHIFT                (14U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP7_IN_MASK                  (0x00008000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_IN_SHIFT                 (15U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP7_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP8_OUT_MASK                 (0x00010000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_OUT_SHIFT                (16U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP8_IN_MASK                  (0x00020000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_IN_SHIFT                 (17U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP8_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP9_OUT_MASK                 (0x00040000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_OUT_SHIFT                (18U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_OUT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_OUT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP9_IN_MASK                  (0x00080000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_IN_SHIFT                 (19U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_IN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP9_IN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP10_OUT_MASK                (0x00100000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_OUT_SHIFT               (20U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP10_IN_MASK                 (0x00200000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_IN_SHIFT                (21U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP10_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP11_OUT_MASK                (0x00400000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_OUT_SHIFT               (22U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP11_IN_MASK                 (0x00800000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_IN_SHIFT                (23U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP11_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP12_OUT_MASK                (0x01000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_OUT_SHIFT               (24U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP12_IN_MASK                 (0x02000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_IN_SHIFT                (25U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP12_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP13_OUT_MASK                (0x04000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_OUT_SHIFT               (26U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP13_IN_MASK                 (0x08000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_IN_SHIFT                (27U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP13_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP14_OUT_MASK                (0x10000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_OUT_SHIFT               (28U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP14_IN_MASK                 (0x20000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_IN_SHIFT                (29U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP14_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP15_OUT_MASK                (0x40000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_OUT_SHIFT               (30U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_OUT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_OUT_MAX                 (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_USBACTEP15_IN_MASK                 (0x80000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_IN_SHIFT                (31U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_IN_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_DALEPENA_USBACTEP15_IN_MAX                  (0x00000001U)

#define CSL_DWCUSB3_DALEPENA_RESETVAL                           (0x00000000U)

/* OEVT */

#define CSL_DWCUSB3_OEVT_DEVICEMODE_MASK                        (0x80000000U)
#define CSL_DWCUSB3_OEVT_DEVICEMODE_SHIFT                       (31U)
#define CSL_DWCUSB3_OEVT_DEVICEMODE_RESETVAL                    (0x00000001U)
#define CSL_DWCUSB3_OEVT_DEVICEMODE_A                           (0x00000000U)
#define CSL_DWCUSB3_OEVT_DEVICEMODE_B                           (0x00000001U)

#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_MASK               (0x01000000U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_SHIFT              (24U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_NOEVT              (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_EVT                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_CLR                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGCONIDSTSCHNGEVNT_NOOP               (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_MASK             (0x00010000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_SHIFT            (16U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_NOEVT            (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_EVT              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_CLR              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVSESSENDDETEVNT_NOOP             (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_MASK                 (0x00020000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_SHIFT                (17U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_NOEVT                (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_EVT                  (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_CLR                  (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVSRPDETEVNT_NOOP                 (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_MASK             (0x00040000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_SHIFT            (18U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_NOEVT            (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_EVT              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_CLR              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVHNPCHNGDETEVNT_NOOP             (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_MASK                   (0x00080000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_SHIFT                  (19U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_NOEVT                  (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_EVT                    (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_CLR                    (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVHOSTEVNT_NOOP                   (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_MASK               (0x00100000U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_SHIFT              (20U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_NOEVT              (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_EVT                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_CLR                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVBHOSTENDEVNT_NOOP               (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_MASK               (0x00000100U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_SHIFT              (8U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_NOEVT              (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_EVT                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_CLR                (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVVBUSCHNGEVNT_NOOP               (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_MASK             (0x00000200U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_SHIFT            (9U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_NOEVT            (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_EVT              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_CLR              (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVSESSVLDDETEVNT_NOOP             (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_MASK                (0x00000400U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_SHIFT               (10U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_NOEVT               (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_EVT                 (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_CLR                 (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHNPCHNGEVNT_NOOP                (0x00000000U)

#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_MASK                (0x00000800U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_SHIFT               (11U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_NOEVT               (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_EVT                 (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_CLR                 (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGBDEVHOSTENDEVNT_NOOP                (0x00000000U)

#define CSL_DWCUSB3_OEVT_OEVTERROR_MASK                         (0x00000001U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_SHIFT                        (0U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_NOEVT                        (0x00000000U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_EVT                          (0x00000001U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_CLR                          (0x00000001U)
#define CSL_DWCUSB3_OEVT_OEVTERROR_NOOP                         (0x00000000U)

#define CSL_DWCUSB3_OEVT_SESREQSTS_MASK                         (0x00000002U)
#define CSL_DWCUSB3_OEVT_SESREQSTS_SHIFT                        (1U)
#define CSL_DWCUSB3_OEVT_SESREQSTS_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_OEVT_SESREQSTS_NOSRP                        (0x00000000U)
#define CSL_DWCUSB3_OEVT_SESREQSTS_SRP                          (0x00000001U)

#define CSL_DWCUSB3_OEVT_HSTNEGSTS_MASK                         (0x00000004U)
#define CSL_DWCUSB3_OEVT_HSTNEGSTS_SHIFT                        (2U)
#define CSL_DWCUSB3_OEVT_HSTNEGSTS_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_OEVT_HSTNEGSTS_FAILURE                      (0x00000000U)
#define CSL_DWCUSB3_OEVT_HSTNEGSTS_SUCCESS                      (0x00000001U)

#define CSL_DWCUSB3_OEVT_BSESVLD_MASK                           (0x00000008U)
#define CSL_DWCUSB3_OEVT_BSESVLD_SHIFT                          (3U)
#define CSL_DWCUSB3_OEVT_BSESVLD_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_OEVT_BSESVLD_INVALID                        (0x00000000U)
#define CSL_DWCUSB3_OEVT_BSESVLD_VALID                          (0x00000001U)

#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_MASK                   (0x00200000U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_SHIFT                  (21U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_RESETVAL               (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_NOEVT                  (0x00000000U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_EVT                    (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_CLR                    (0x00000001U)
#define CSL_DWCUSB3_OEVT_OTGADEVIDLEEVNT_NOOP                   (0x00000000U)

#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_MASK                  (0x00800000U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_SHIFT                 (23U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_NOEVT                 (0x00000000U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_EVT                   (0x00000001U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_CLR                   (0x00000001U)
#define CSL_DWCUSB3_OEVT_HRRCONFNOTIFEVNT_NOOP                  (0x00000000U)

#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_MASK                  (0x00400000U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_SHIFT                 (22U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_NOEVT                 (0x00000000U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_EVT                   (0x00000001U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_CLR                   (0x00000001U)
#define CSL_DWCUSB3_OEVT_HRRINITNOTIFEVNT_NOOP                  (0x00000000U)

#define CSL_DWCUSB3_OEVT_RESETVAL                               (0x80000000U)

/* OEVTEN */

#define CSL_DWCUSB3_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MASK           (0x01000000U)
#define CSL_DWCUSB3_OEVTEN_OTGCONIDSTSCHNGEVNTEN_SHIFT          (24U)
#define CSL_DWCUSB3_OEVTEN_OTGCONIDSTSCHNGEVNTEN_RESETVAL       (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGCONIDSTSCHNGEVNTEN_DIS            (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGCONIDSTSCHNGEVNTEN_EN             (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVSESSENDDETEVNTEN_MASK         (0x00010000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSESSENDDETEVNTEN_SHIFT        (16U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSESSENDDETEVNTEN_RESETVAL     (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSESSENDDETEVNTEN_DIS          (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSESSENDDETEVNTEN_EN           (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVSRPDETEVNTEN_MASK             (0x00020000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSRPDETEVNTEN_SHIFT            (17U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSRPDETEVNTEN_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSRPDETEVNTEN_DIS              (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVSRPDETEVNTEN_EN               (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_MASK         (0x00040000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_SHIFT        (18U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_RESETVAL     (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_DIS          (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_EN           (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVHOSTEVNTEN_MASK               (0x00080000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHOSTEVNTEN_SHIFT              (19U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHOSTEVNTEN_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHOSTEVNTEN_DIS                (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVHOSTEVNTEN_EN                 (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVBHOSTENDEVNTEN_MASK           (0x00100000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVBHOSTENDEVNTEN_SHIFT          (20U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVBHOSTENDEVNTEN_RESETVAL       (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVBHOSTENDEVNTEN_DIS            (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVBHOSTENDEVNTEN_EN             (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MASK           (0x00000100U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_SHIFT          (8U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_RESETVAL       (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_DIS            (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_EN             (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MASK         (0x00000200U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_SHIFT        (9U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_RESETVAL     (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_DIS          (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_EN           (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MASK            (0x00000400U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHNPCHNGEVNTEN_SHIFT           (10U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHNPCHNGEVNTEN_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHNPCHNGEVNTEN_DIS             (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHNPCHNGEVNTEN_EN              (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGBDEVHOSTENDEVNTEN_MASK            (0x00000800U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHOSTENDEVNTEN_SHIFT           (11U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHOSTENDEVNTEN_RESETVAL        (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHOSTENDEVNTEN_DIS             (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGBDEVHOSTENDEVNTEN_EN              (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_OTGADEVIDLEEVNTEN_MASK               (0x00200000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVIDLEEVNTEN_SHIFT              (21U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVIDLEEVNTEN_RESETVAL           (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVIDLEEVNTEN_DIS                (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_OTGADEVIDLEEVNTEN_EN                 (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_HRRINITNOTIFEVNTEN_MASK              (0x00400000U)
#define CSL_DWCUSB3_OEVTEN_HRRINITNOTIFEVNTEN_SHIFT             (22U)
#define CSL_DWCUSB3_OEVTEN_HRRINITNOTIFEVNTEN_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_HRRINITNOTIFEVNTEN_DIS               (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_HRRINITNOTIFEVNTEN_EN                (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_HRRCONFNOTIFEVNTEN_MASK              (0x00800000U)
#define CSL_DWCUSB3_OEVTEN_HRRCONFNOTIFEVNTEN_SHIFT             (23U)
#define CSL_DWCUSB3_OEVTEN_HRRCONFNOTIFEVNTEN_RESETVAL          (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_HRRCONFNOTIFEVNTEN_DIS               (0x00000000U)
#define CSL_DWCUSB3_OEVTEN_HRRCONFNOTIFEVNTEN_EN                (0x00000001U)

#define CSL_DWCUSB3_OEVTEN_RESETVAL                             (0x00000000U)

/* OSTS */

#define CSL_DWCUSB3_OSTS_CONIDSTS_MASK                          (0x00000001U)
#define CSL_DWCUSB3_OSTS_CONIDSTS_SHIFT                         (0U)
#define CSL_DWCUSB3_OSTS_CONIDSTS_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_OSTS_CONIDSTS_A                             (0x00000000U)
#define CSL_DWCUSB3_OSTS_CONIDSTS_B                             (0x00000001U)

#define CSL_DWCUSB3_OSTS_VBUSVLD_MASK                           (0x00000002U)
#define CSL_DWCUSB3_OSTS_VBUSVLD_SHIFT                          (1U)
#define CSL_DWCUSB3_OSTS_VBUSVLD_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_OSTS_VBUSVLD_NO                             (0x00000000U)
#define CSL_DWCUSB3_OSTS_VBUSVLD_YES                            (0x00000001U)

#define CSL_DWCUSB3_OSTS_BSESVLD_MASK                           (0x00000004U)
#define CSL_DWCUSB3_OSTS_BSESVLD_SHIFT                          (2U)
#define CSL_DWCUSB3_OSTS_BSESVLD_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_OSTS_BSESVLD_NO                             (0x00000000U)
#define CSL_DWCUSB3_OSTS_BSESVLD_YES                            (0x00000001U)

#define CSL_DWCUSB3_OSTS_OTGSTATE_MASK                          (0x00000F00U)
#define CSL_DWCUSB3_OSTS_OTGSTATE_SHIFT                         (8U)
#define CSL_DWCUSB3_OSTS_OTGSTATE_RESETVAL                      (0x00000008U)
#define CSL_DWCUSB3_OSTS_OTGSTATE_MAX                           (0x0000000fU)

#define CSL_DWCUSB3_OSTS_XHCIPRTPOWER_MASK                      (0x00000008U)
#define CSL_DWCUSB3_OSTS_XHCIPRTPOWER_SHIFT                     (3U)
#define CSL_DWCUSB3_OSTS_XHCIPRTPOWER_RESETVAL                  (0x00000001U)
#define CSL_DWCUSB3_OSTS_XHCIPRTPOWER_MAX                       (0x00000001U)

#define CSL_DWCUSB3_OSTS_PERIPHERALSTATE_MASK                   (0x00000010U)
#define CSL_DWCUSB3_OSTS_PERIPHERALSTATE_SHIFT                  (4U)
#define CSL_DWCUSB3_OSTS_PERIPHERALSTATE_RESETVAL               (0x00000001U)
#define CSL_DWCUSB3_OSTS_PERIPHERALSTATE_HOST                   (0x00000000U)
#define CSL_DWCUSB3_OSTS_PERIPHERALSTATE_PERIPH                 (0x00000001U)

#define CSL_DWCUSB3_OSTS_RESETVAL                               (0x00000819U)

/* OCFG */

#define CSL_DWCUSB3_OCFG_SRPCAP_MASK                            (0x00000001U)
#define CSL_DWCUSB3_OCFG_SRPCAP_SHIFT                           (0U)
#define CSL_DWCUSB3_OCFG_SRPCAP_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_OCFG_SRPCAP_NO                              (0x00000000U)
#define CSL_DWCUSB3_OCFG_SRPCAP_YES                             (0x00000001U)

#define CSL_DWCUSB3_OCFG_HNPCAP_MASK                            (0x00000002U)
#define CSL_DWCUSB3_OCFG_HNPCAP_SHIFT                           (1U)
#define CSL_DWCUSB3_OCFG_HNPCAP_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_OCFG_HNPCAP_NO                              (0x00000000U)
#define CSL_DWCUSB3_OCFG_HNPCAP_YES                             (0x00000001U)

#define CSL_DWCUSB3_OCFG_OTGVERSION_MASK                        (0x00000004U)
#define CSL_DWCUSB3_OCFG_OTGVERSION_SHIFT                       (2U)
#define CSL_DWCUSB3_OCFG_OTGVERSION_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_OCFG_OTGVERSION_MAX                         (0x00000001U)

#define CSL_DWCUSB3_OCFG_OTGSFTRSTMSK_MASK                      (0x00000008U)
#define CSL_DWCUSB3_OCFG_OTGSFTRSTMSK_SHIFT                     (3U)
#define CSL_DWCUSB3_OCFG_OTGSFTRSTMSK_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_OCFG_OTGSFTRSTMSK_DEFAULT                   (0x00000000U)
#define CSL_DWCUSB3_OCFG_OTGSFTRSTMSK_BITMASK                   (0x00000001U)

#define CSL_DWCUSB3_OCFG_RESETVAL                               (0x00000000U)

/* OCTL */

#define CSL_DWCUSB3_OCTL_SESREQ_MASK                            (0x00000008U)
#define CSL_DWCUSB3_OCTL_SESREQ_SHIFT                           (3U)
#define CSL_DWCUSB3_OCTL_SESREQ_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_OCTL_SESREQ_SRP                             (0x00000001U)
#define CSL_DWCUSB3_OCTL_SESREQ_NOOP                            (0x00000000U)
#define CSL_DWCUSB3_OCTL_SESREQ_ZERO                            (0x00000000U)

#define CSL_DWCUSB3_OCTL_HNPREQ_MASK                            (0x00000010U)
#define CSL_DWCUSB3_OCTL_HNPREQ_SHIFT                           (4U)
#define CSL_DWCUSB3_OCTL_HNPREQ_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_OCTL_HNPREQ_ONGOING                         (0x00000001U)
#define CSL_DWCUSB3_OCTL_HNPREQ_DONE                            (0x00000000U)

#define CSL_DWCUSB3_OCTL_PRTPWRCTL_MASK                         (0x00000020U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_SHIFT                        (5U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_REQ                          (0x00000001U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_ON                           (0x00000001U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_OFF                          (0x00000000U)
#define CSL_DWCUSB3_OCTL_PRTPWRCTL_SWOFF                        (0x00000000U)

#define CSL_DWCUSB3_OCTL_DEVSETHNPEN_MASK                       (0x00000002U)
#define CSL_DWCUSB3_OCTL_DEVSETHNPEN_SHIFT                      (1U)
#define CSL_DWCUSB3_OCTL_DEVSETHNPEN_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_OCTL_DEVSETHNPEN_DIS                        (0x00000000U)
#define CSL_DWCUSB3_OCTL_DEVSETHNPEN_EN                         (0x00000001U)

#define CSL_DWCUSB3_OCTL_HSTSETHNPEN_MASK                       (0x00000001U)
#define CSL_DWCUSB3_OCTL_HSTSETHNPEN_SHIFT                      (0U)
#define CSL_DWCUSB3_OCTL_HSTSETHNPEN_RESETVAL                   (0x00000000U)
#define CSL_DWCUSB3_OCTL_HSTSETHNPEN_DIS                        (0x00000000U)
#define CSL_DWCUSB3_OCTL_HSTSETHNPEN_EN                         (0x00000001U)

#define CSL_DWCUSB3_OCTL_TERMSELDLPULSE_MASK                    (0x00000004U)
#define CSL_DWCUSB3_OCTL_TERMSELDLPULSE_SHIFT                   (2U)
#define CSL_DWCUSB3_OCTL_TERMSELDLPULSE_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_OCTL_TERMSELDLPULSE_NEWENUM1                (0x00000000U)
#define CSL_DWCUSB3_OCTL_TERMSELDLPULSE_NEWENUM2                (0x00000001U)

#define CSL_DWCUSB3_OCTL_PERIMODE_MASK                          (0x00000040U)
#define CSL_DWCUSB3_OCTL_PERIMODE_SHIFT                         (6U)
#define CSL_DWCUSB3_OCTL_PERIMODE_RESETVAL                      (0x00000001U)
#define CSL_DWCUSB3_OCTL_PERIMODE_NO                            (0x00000000U)
#define CSL_DWCUSB3_OCTL_PERIMODE_YES                           (0x00000001U)

#define CSL_DWCUSB3_OCTL_OTG3_GOERR_MASK                        (0x00000080U)
#define CSL_DWCUSB3_OCTL_OTG3_GOERR_SHIFT                       (7U)
#define CSL_DWCUSB3_OCTL_OTG3_GOERR_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_OCTL_OTG3_GOERR_GO                          (0x00000001U)
#define CSL_DWCUSB3_OCTL_OTG3_GOERR_PENDING                     (0x00000001U)
#define CSL_DWCUSB3_OCTL_OTG3_GOERR_NOOP                        (0x00000000U)

#define CSL_DWCUSB3_OCTL_RESETVAL                               (0x00000040U)

/* ADPCFG */

#define CSL_DWCUSB3_ADPCFG_PRBDSCHG_MASK                        (0x0C000000U)
#define CSL_DWCUSB3_ADPCFG_PRBDSCHG_SHIFT                       (26U)
#define CSL_DWCUSB3_ADPCFG_PRBDSCHG_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_ADPCFG_PRBDSCHG_MAX                         (0x00000003U)

#define CSL_DWCUSB3_ADPCFG_PRBDELTA_MASK                        (0x30000000U)
#define CSL_DWCUSB3_ADPCFG_PRBDELTA_SHIFT                       (28U)
#define CSL_DWCUSB3_ADPCFG_PRBDELTA_RESETVAL                    (0x00000000U)
#define CSL_DWCUSB3_ADPCFG_PRBDELTA_MAX                         (0x00000003U)

#define CSL_DWCUSB3_ADPCFG_PRBPER_MASK                          (0xC0000000U)
#define CSL_DWCUSB3_ADPCFG_PRBPER_SHIFT                         (30U)
#define CSL_DWCUSB3_ADPCFG_PRBPER_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_ADPCFG_PRBPER_MAX                           (0x00000003U)

#define CSL_DWCUSB3_ADPCFG_RESETVAL                             (0x00000000U)

/* ADPCTL */

#define CSL_DWCUSB3_ADPCTL_WB_MASK                              (0x01000000U)
#define CSL_DWCUSB3_ADPCTL_WB_SHIFT                             (24U)
#define CSL_DWCUSB3_ADPCTL_WB_RESETVAL                          (0x00000000U)
#define CSL_DWCUSB3_ADPCTL_WB_MAX                               (0x00000001U)

#define CSL_DWCUSB3_ADPCTL_ADPRES_MASK                          (0x02000000U)
#define CSL_DWCUSB3_ADPCTL_ADPRES_SHIFT                         (25U)
#define CSL_DWCUSB3_ADPCTL_ADPRES_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_ADPCTL_ADPRES_MAX                           (0x00000001U)

#define CSL_DWCUSB3_ADPCTL_ADPEN_MASK                           (0x04000000U)
#define CSL_DWCUSB3_ADPCTL_ADPEN_SHIFT                          (26U)
#define CSL_DWCUSB3_ADPCTL_ADPEN_RESETVAL                       (0x00000000U)
#define CSL_DWCUSB3_ADPCTL_ADPEN_MAX                            (0x00000001U)

#define CSL_DWCUSB3_ADPCTL_ENASNS_MASK                          (0x08000000U)
#define CSL_DWCUSB3_ADPCTL_ENASNS_SHIFT                         (27U)
#define CSL_DWCUSB3_ADPCTL_ENASNS_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_ADPCTL_ENASNS_MAX                           (0x00000001U)

#define CSL_DWCUSB3_ADPCTL_ENAPRB_MASK                          (0x10000000U)
#define CSL_DWCUSB3_ADPCTL_ENAPRB_SHIFT                         (28U)
#define CSL_DWCUSB3_ADPCTL_ENAPRB_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_ADPCTL_ENAPRB_MAX                           (0x00000001U)

#define CSL_DWCUSB3_ADPCTL_RESETVAL                             (0x00000000U)

/* ADPEVT */

#define CSL_DWCUSB3_ADPEVT_RTIM_MASK                            (0x000007FFU)
#define CSL_DWCUSB3_ADPEVT_RTIM_SHIFT                           (0U)
#define CSL_DWCUSB3_ADPEVT_RTIM_RESETVAL                        (0x00000000U)
#define CSL_DWCUSB3_ADPEVT_RTIM_MAX                             (0x000007ffU)

#define CSL_DWCUSB3_ADPEVT_ADPRSTCMPLTEVNT_MASK                 (0x02000000U)
#define CSL_DWCUSB3_ADPEVT_ADPRSTCMPLTEVNT_SHIFT                (25U)
#define CSL_DWCUSB3_ADPEVT_ADPRSTCMPLTEVNT_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_ADPEVT_ADPRSTCMPLTEVNT_MAX                  (0x00000001U)

#define CSL_DWCUSB3_ADPEVT_ADPTMOUTEVNT_MASK                    (0x04000000U)
#define CSL_DWCUSB3_ADPEVT_ADPTMOUTEVNT_SHIFT                   (26U)
#define CSL_DWCUSB3_ADPEVT_ADPTMOUTEVNT_RESETVAL                (0x00000000U)
#define CSL_DWCUSB3_ADPEVT_ADPTMOUTEVNT_MAX                     (0x00000001U)

#define CSL_DWCUSB3_ADPEVT_ADPSNSEVNT_MASK                      (0x08000000U)
#define CSL_DWCUSB3_ADPEVT_ADPSNSEVNT_SHIFT                     (27U)
#define CSL_DWCUSB3_ADPEVT_ADPSNSEVNT_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_ADPEVT_ADPSNSEVNT_MAX                       (0x00000001U)

#define CSL_DWCUSB3_ADPEVT_ADPPRBEVNT_MASK                      (0x10000000U)
#define CSL_DWCUSB3_ADPEVT_ADPPRBEVNT_SHIFT                     (28U)
#define CSL_DWCUSB3_ADPEVT_ADPPRBEVNT_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_ADPEVT_ADPPRBEVNT_MAX                       (0x00000001U)

#define CSL_DWCUSB3_ADPEVT_RESETVAL                             (0x00000000U)

/* ADPEVTEN */

#define CSL_DWCUSB3_ADPEVTEN_ADPRSTCMPLTEVNTEN_MASK             (0x02000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPRSTCMPLTEVNTEN_SHIFT            (25U)
#define CSL_DWCUSB3_ADPEVTEN_ADPRSTCMPLTEVNTEN_RESETVAL         (0x00000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPRSTCMPLTEVNTEN_MAX              (0x00000001U)

#define CSL_DWCUSB3_ADPEVTEN_ADPTMOUTEVNTEN_MASK                (0x04000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPTMOUTEVNTEN_SHIFT               (26U)
#define CSL_DWCUSB3_ADPEVTEN_ADPTMOUTEVNTEN_RESETVAL            (0x00000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPTMOUTEVNTEN_MAX                 (0x00000001U)

#define CSL_DWCUSB3_ADPEVTEN_ADPSNSEVNTEN_MASK                  (0x08000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPSNSEVNTEN_SHIFT                 (27U)
#define CSL_DWCUSB3_ADPEVTEN_ADPSNSEVNTEN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPSNSEVNTEN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_ADPEVTEN_ADPPRBEVNTEN_MASK                  (0x10000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPPRBEVNTEN_SHIFT                 (28U)
#define CSL_DWCUSB3_ADPEVTEN_ADPPRBEVNTEN_RESETVAL              (0x00000000U)
#define CSL_DWCUSB3_ADPEVTEN_ADPPRBEVNTEN_MAX                   (0x00000001U)

#define CSL_DWCUSB3_ADPEVTEN_RESETVAL                           (0x00000000U)

/* BCFG */

#define CSL_DWCUSB3_BCFG_CHIRP_EN_MASK                          (0x00000001U)
#define CSL_DWCUSB3_BCFG_CHIRP_EN_SHIFT                         (0U)
#define CSL_DWCUSB3_BCFG_CHIRP_EN_RESETVAL                      (0x00000000U)
#define CSL_DWCUSB3_BCFG_CHIRP_EN_MAX                           (0x00000001U)

#define CSL_DWCUSB3_BCFG_IDDIG_SEL_MASK                         (0x00000002U)
#define CSL_DWCUSB3_BCFG_IDDIG_SEL_SHIFT                        (1U)
#define CSL_DWCUSB3_BCFG_IDDIG_SEL_RESETVAL                     (0x00000000U)
#define CSL_DWCUSB3_BCFG_IDDIG_SEL_MAX                          (0x00000001U)

#define CSL_DWCUSB3_BCFG_RESETVAL                               (0x00000000U)

/* BCEVT */

#define CSL_DWCUSB3_BCEVT_MULTVALIDBC_MASK                      (0x0000001FU)
#define CSL_DWCUSB3_BCEVT_MULTVALIDBC_SHIFT                     (0U)
#define CSL_DWCUSB3_BCEVT_MULTVALIDBC_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_BCEVT_MULTVALIDBC_MAX                       (0x0000001fU)

#define CSL_DWCUSB3_BCEVT_MV_CHNGEVNT_MASK                      (0x01000000U)
#define CSL_DWCUSB3_BCEVT_MV_CHNGEVNT_SHIFT                     (24U)
#define CSL_DWCUSB3_BCEVT_MV_CHNGEVNT_RESETVAL                  (0x00000000U)
#define CSL_DWCUSB3_BCEVT_MV_CHNGEVNT_MAX                       (0x00000001U)

#define CSL_DWCUSB3_BCEVT_RESETVAL                              (0x00000000U)

/* BCEVTEN */

#define CSL_DWCUSB3_BCEVTEN_MV_CHNGEVNTENA_MASK                 (0x01000000U)
#define CSL_DWCUSB3_BCEVTEN_MV_CHNGEVNTENA_SHIFT                (24U)
#define CSL_DWCUSB3_BCEVTEN_MV_CHNGEVNTENA_RESETVAL             (0x00000000U)
#define CSL_DWCUSB3_BCEVTEN_MV_CHNGEVNTENA_MAX                  (0x00000001U)

#define CSL_DWCUSB3_BCEVTEN_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
