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
#ifndef CSLR_USB3SSDWC_H_
#define CSLR_USB3SSDWC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_gbl
**************************************************************************/
typedef struct {
    volatile Uint32 GSBUSCFG0;
    volatile Uint32 GSBUSCFG1;
    volatile Uint32 GTXTHRCFG;
    volatile Uint32 GRXTHRCFG;
    volatile Uint32 GCTL;
    volatile Uint32 GPMSTS;
    volatile Uint32 GSTS;
    volatile Uint32 GUCTL1;
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
    volatile Uint32 GDBGLSPMUX_HST;
    volatile Uint32 GDBGLSP;
    volatile Uint32 GDBGEPINFO0;
    volatile Uint32 GDBGEPINFO1;
    volatile Uint32 GPRTBIMAP_HSLO;
    volatile Uint32 GPRTBIMAP_HSHI;
    volatile Uint32 GPRTBIMAP_FSLO;
    volatile Uint32 GPRTBIMAP_FSHI;
    volatile Uint8  RSVD0[1136];
    volatile Uint32 GHWPARAMS8;
    volatile Uint8  RSVD1[12];
    volatile Uint32 GTXFIFOPRIDEV;
    volatile Uint8  RSVD2[4];
    volatile Uint32 GTXFIFOPRIHST;
    volatile Uint32 GRXFIFOPRIHST;
    volatile Uint32 GFIFOPRIDBC;
    volatile Uint32 GDMAHLRATIO;
    volatile Uint8  RSVD3[8];
    volatile Uint32 GFLADJ;
    volatile Uint8  RSVD4[204];
} CSL_Usb3ssdwcDwc_usb3_block_gblRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_dev
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
    volatile Uint8  RSVD1[988];
} CSL_Usb3ssdwcDwc_usb3_block_devRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_otg
**************************************************************************/
typedef struct {
    volatile Uint32 OCFG;
    volatile Uint32 OCTL;
    volatile Uint32 OEVT;
    volatile Uint32 OEVTEN;
    volatile Uint32 OSTS;
    volatile Uint8  RSVD0[12];
    volatile Uint32 ADPCFG;
    volatile Uint32 ADPCTL;
    volatile Uint32 ADPEVT;
    volatile Uint32 ADPEVTEN;
} CSL_Usb3ssdwcDwc_usb3_block_otgRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_bc
**************************************************************************/
typedef struct {
    volatile Uint32 BCFG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 BCEVT;
    volatile Uint32 BCEVTEN;
} CSL_Usb3ssdwcDwc_usb3_block_bcRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Host_Cntrl_Oper_Regs
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
} CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_oper_regsRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Host_Cntrl_Port_Reg_Set
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[32];
} CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_port_reg_setRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Host_Cntrl_Runtime_Regs
**************************************************************************/
typedef struct {
    volatile Uint32 MFINDEX;
    volatile Uint32 RSVDZ;
    volatile Uint8  RSVD0[24];
} CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_runtime_regsRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Interrupter_Regs
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[512];
} CSL_Usb3ssdwcDwc_usb3_block_interrupter_regsRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Doorbell_Register
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[260];
} CSL_Usb3ssdwcDwc_usb3_block_doorbell_registerRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_int_RAM0
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[12288];
} CSL_Usb3ssdwcDwc_usb3_block_int_ram0Regs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_int_RAM1
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[12288];
} CSL_Usb3ssdwcDwc_usb3_block_int_ram1Regs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_int_RAM2
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[12288];
} CSL_Usb3ssdwcDwc_usb3_block_int_ram2Regs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_HC_Extended_Capability_Register
**************************************************************************/
typedef struct {
    volatile Uint32 USBLEGSUP;
    volatile Uint32 USBLEGCTLSTS;
    volatile Uint8  RSVD0[8];
} CSL_Usb3ssdwcDwc_usb3_block_hc_extended_capability_registerRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_xHCI_Supt_USB20_Prt_Cap
**************************************************************************/
typedef struct {
    volatile Uint32 SUPTPRT2_DW0;
    volatile Uint32 SUPTPRT2_DW1;
    volatile Uint32 SUPTPRT2_DW2;
    volatile Uint32 SUPTPRT2_DW3;
} CSL_Usb3ssdwcDwc_usb3_block_xhci_supt_usb20_prt_capRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_xHCI_Supt_USB30_Prt_Cap
**************************************************************************/
typedef struct {
    volatile Uint32 SUPTPRT3_DW0;
    volatile Uint32 SUPTPRT3_DW1;
    volatile Uint32 SUPTPRT3_DW2;
    volatile Uint32 SUPTPRT3_DW3;
} CSL_Usb3ssdwcDwc_usb3_block_xhci_supt_usb30_prt_capRegs;


/**************************************************************************
* Register Overlay Structure for DWC_usb3_block_Debug_Capability_Structure
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
} CSL_Usb3ssdwcDwc_usb3_block_debug_capability_structureRegs;


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
    volatile Uint8  RSVD2[4];
    CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_oper_regsRegs	DWC_USB3_BLOCK_HOST_CNTRL_OPER_REGS;
    CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_port_reg_setRegs	DWC_USB3_BLOCK_HOST_CNTRL_PORT_REG_SET;
    CSL_Usb3ssdwcDwc_usb3_block_host_cntrl_runtime_regsRegs	DWC_USB3_BLOCK_HOST_CNTRL_RUNTIME_REGS;
    CSL_Usb3ssdwcDwc_usb3_block_interrupter_regsRegs	DWC_USB3_BLOCK_INTERRUPTER_REGS;
    CSL_Usb3ssdwcDwc_usb3_block_doorbell_registerRegs	DWC_USB3_BLOCK_DOORBELL_REGISTER;
    volatile Uint8  RSVD3[764];
    CSL_Usb3ssdwcDwc_usb3_block_hc_extended_capability_registerRegs	DWC_USB3_BLOCK_HC_EXTENDED_CAPABILITY_REGISTER;
    CSL_Usb3ssdwcDwc_usb3_block_xhci_supt_usb20_prt_capRegs	DWC_USB3_BLOCK_XHCI_SUPT_USB20_PRT_CAP;
    CSL_Usb3ssdwcDwc_usb3_block_xhci_supt_usb30_prt_capRegs	DWC_USB3_BLOCK_XHCI_SUPT_USB30_PRT_CAP;
    CSL_Usb3ssdwcDwc_usb3_block_debug_capability_structureRegs	DWC_USB3_BLOCK_DEBUG_CAPABILITY_STRUCTURE;
    volatile Uint8  RSVD4[46640];
    CSL_Usb3ssdwcDwc_usb3_block_gblRegs	DWC_USB3_BLOCK_GBL;
    CSL_Usb3ssdwcDwc_usb3_block_devRegs	DWC_USB3_BLOCK_DEV;
    volatile Uint8  RSVD5[256];
    CSL_Usb3ssdwcDwc_usb3_block_otgRegs	DWC_USB3_BLOCK_OTG;
    CSL_Usb3ssdwcDwc_usb3_block_bcRegs	DWC_USB3_BLOCK_BC;
    volatile Uint8  RSVD6[209856];
    CSL_Usb3ssdwcDwc_usb3_block_int_ram0Regs	DWC_USB3_BLOCK_INT_RAM0;
    volatile Uint8  RSVD7[249856];
    CSL_Usb3ssdwcDwc_usb3_block_int_ram1Regs	DWC_USB3_BLOCK_INT_RAM1;
    volatile Uint8  RSVD8[249856];
    CSL_Usb3ssdwcDwc_usb3_block_int_ram2Regs	DWC_USB3_BLOCK_INT_RAM2;
} CSL_Usb3ssDwcRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Global SoC Bus Configuration Register 0 */
#define CSL_USB3SSDWC_GSBUSCFG0                                 (0xC100U)

/* Global SoC Bus Configuration Register 1 */
#define CSL_USB3SSDWC_GSBUSCFG1                                 (0xC104U)

/* Global Tx Threshold Control Register */
#define CSL_USB3SSDWC_GTXTHRCFG                                 (0xC108U)

/* Global Rx Threshold Control Register */
#define CSL_USB3SSDWC_GRXTHRCFG                                 (0xC10CU)

/* Global Common Register */
#define CSL_USB3SSDWC_GCTL                                      (0xC110U)

/* Global Power Management Status Register */
#define CSL_USB3SSDWC_GPMSTS                                    (0xC114U)

/* Global Status Register */
#define CSL_USB3SSDWC_GSTS                                      (0xC118U)

/* Global User Control Register 1 */
#define CSL_USB3SSDWC_GUCTL1                                    (0xC11CU)

/* Global Synopsys ID Register */
#define CSL_USB3SSDWC_GSNPSID                                   (0xC120U)

/* Global General Purpose Input/Output Register */
#define CSL_USB3SSDWC_GGPIO                                     (0xC124U)

/* Global User ID Register */
#define CSL_USB3SSDWC_GUID                                      (0xC128U)

/* Global User Control Register */
#define CSL_USB3SSDWC_GUCTL                                     (0xC12CU)

/* Register GBUSERRADDRLO */
#define CSL_USB3SSDWC_GBUSERRADDRLO                             (0xC130U)

/* Register GBUSERRADDRHI */
#define CSL_USB3SSDWC_GBUSERRADDRHI                             (0xC134U)

/* Register R */
#define CSL_USB3SSDWC_GPRTBIMAPLO                               (0xC138U)

/* Register R */
#define CSL_USB3SSDWC_GPRTBIMAPHI                               (0xC13CU)

/* Global Hardware Parameters Register 0 */
#define CSL_USB3SSDWC_GHWPARAMS0                                (0xC140U)

/* Global Hardware Parameters Register 1 */
#define CSL_USB3SSDWC_GHWPARAMS1                                (0xC144U)

/* Global Hardware Parameters Register 2 */
#define CSL_USB3SSDWC_GHWPARAMS2                                (0xC148U)

/* Global Hardware Parameters Register 3 */
#define CSL_USB3SSDWC_GHWPARAMS3                                (0xC14CU)

/* Global Hardware Parameters Register 4 */
#define CSL_USB3SSDWC_GHWPARAMS4                                (0xC150U)

/* Global Hardware Parameters Register 5 */
#define CSL_USB3SSDWC_GHWPARAMS5                                (0xC154U)

/* Global Hardware Parameters Register 6 */
#define CSL_USB3SSDWC_GHWPARAMS6                                (0xC158U)

/* Global Hardware Parameters Register 7 */
#define CSL_USB3SSDWC_GHWPARAMS7                                (0xC15CU)

/* Global Debug Queue/FIFO Space Available Register */
#define CSL_USB3SSDWC_GDBGFIFOSPACE                             (0xC160U)

/* Global Debug LTSSM Register */
#define CSL_USB3SSDWC_GDBGLTSSM                                 (0xC164U)

/* Global Debug LNMCC Register */
#define CSL_USB3SSDWC_GDBGLNMCC                                 (0xC168U)

/* Global Debug BMU Register */
#define CSL_USB3SSDWC_GDBGBMU                                   (0xC16CU)

/* Internal Global Debug LSP MUX Register */
#define CSL_USB3SSDWC_GDBGLSPMUX_HST                            (0xC170U)

/* Global Debug LSP Register */
#define CSL_USB3SSDWC_GDBGLSP                                   (0xC174U)

/* Global Debug Endpoint Information Register 0 */
#define CSL_USB3SSDWC_GDBGEPINFO0                               (0xC178U)

/* Global Debug Endpoint Information Register 1 */
#define CSL_USB3SSDWC_GDBGEPINFO1                               (0xC17CU)

/* High Speed port to bus instance mapping */
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO                            (0xC180U)

/* High Speed port to bus instance mapping */
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI                            (0xC184U)

/* Register Full Speed port to bus instance mapping */
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO                            (0xC188U)

/* Register Full Speed port to bus instance mapping */
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI                            (0xC18CU)

/* Global Hardware Parameters Register 8 */
#define CSL_USB3SSDWC_GHWPARAMS8                                (0xC600U)

/* Global Device TX FIFO DMA Priority Register */
#define CSL_USB3SSDWC_GTXFIFOPRIDEV                             (0xC610U)

/* Global Host TX FIFO DMA Priority Register */
#define CSL_USB3SSDWC_GTXFIFOPRIHST                             (0xC618U)

/* Global Host RX FIFO DMA Priority Register */
#define CSL_USB3SSDWC_GRXFIFOPRIHST                             (0xC61CU)

/* Global Host Debug Capability DMA Priority Register */
#define CSL_USB3SSDWC_GFIFOPRIDBC                               (0xC620U)

/* Global Host FIFO DMA High-Low Priority Ratio Register */
#define CSL_USB3SSDWC_GDMAHLRATIO                               (0xC624U)

/* Global Frame Length Adjustment Register */
#define CSL_USB3SSDWC_GFLADJ                                    (0xC630U)

/* Device Configuration Register */
#define CSL_USB3SSDWC_DCFG                                      (0xC700U)

/* Device Control Register */
#define CSL_USB3SSDWC_DCTL                                      (0xC704U)

/* Device Event Enable Register */
#define CSL_USB3SSDWC_DEVTEN                                    (0xC708U)

/* Device Status Register */
#define CSL_USB3SSDWC_DSTS                                      (0xC70CU)

/* Device Generic Command Parameter Register */
#define CSL_USB3SSDWC_DGCMDPAR                                  (0xC710U)

/* Device Generic Command Register */
#define CSL_USB3SSDWC_DGCMD                                     (0xC714U)

/* Device Active USB Endpoint Enable Register */
#define CSL_USB3SSDWC_DALEPENA                                  (0xC720U)

/* OTG Configuration Register */
#define CSL_USB3SSDWC_OCFG                                      (0xCC00U)

/* OTG Control Register */
#define CSL_USB3SSDWC_OCTL                                      (0xCC04U)

/* OTG Events Register */
#define CSL_USB3SSDWC_OEVT                                      (0xCC08U)

/* OTG Events Enable Register */
#define CSL_USB3SSDWC_OEVTEN                                    (0xCC0CU)

/* OTG Status Register */
#define CSL_USB3SSDWC_OSTS                                      (0xCC10U)

/* ADP Configuration Register */
#define CSL_USB3SSDWC_ADPCFG                                    (0xCC20U)

/* ADP Control Register */
#define CSL_USB3SSDWC_ADPCTL                                    (0xCC24U)

/* ADP Event Register */
#define CSL_USB3SSDWC_ADPEVT                                    (0xCC28U)

/* ADP Event Enable Register */
#define CSL_USB3SSDWC_ADPEVTEN                                  (0xCC2CU)

/* BC Configuration Register */
#define CSL_USB3SSDWC_BCFG                                      (0xCC30U)

/* BC Event Register */
#define CSL_USB3SSDWC_BCEVT                                     (0xCC38U)

/* BC Event Enable Register */
#define CSL_USB3SSDWC_BCEVTEN                                   (0xCC3CU)

/* Capability Registers Length */
#define CSL_USB3SSDWC_CAPLENGTH                                 (0x0U)

/* Host Controller Structural Parameters 1 */
#define CSL_USB3SSDWC_HCSPARAMS1                                (0x4U)

/* Host Controller Structural Parameters 2 */
#define CSL_USB3SSDWC_HCSPARAMS2                                (0x8U)

/* Structural Parameters 3 Register */
#define CSL_USB3SSDWC_HCSPARAMS3                                (0xCU)

/* Capability Parameters Register */
#define CSL_USB3SSDWC_HCCPARAMS                                 (0x10U)

/* Doorbell Offset Register */
#define CSL_USB3SSDWC_DBOFF                                     (0x14U)

/* Runtime Register Space Offset Register */
#define CSL_USB3SSDWC_RTSOFF                                    (0x18U)

/* USB Command Register */
#define CSL_USB3SSDWC_USBCMD                                    (0x20U)

/* USB Status Register Bit Definitions. */
#define CSL_USB3SSDWC_USBSTS                                    (0x24U)

/* Page Size Register Bit Definitions. This register is used by software to 
 * enable or disable the reporting of the reception of specific USB Device 
 * Notification Transaction Packets. A Notification Enable (Nx, where x = 0 to 
 * 15) flag is defined for each of the 16 possible device notification types. 
 * If a flag is set for a specific notification type, a Device Notification 
 * Event shall be generated when the respective notification packet is 
 * received. After reset all notifications are disabled. Refer to section 
 * 6.4.2.7. This register shall be written as a Dword. Byte writes produce 
 * undefined results. */
#define CSL_USB3SSDWC_PAGESIZE                                  (0x28U)

/* Device Notification Register Bit Definitions. */
#define CSL_USB3SSDWC_DNCTRL                                    (0x34U)

/* Register CRCR_LO */
#define CSL_USB3SSDWC_CRCR_LO                                   (0x38U)

/* Register CRCR_HI */
#define CSL_USB3SSDWC_CRCR_HI                                   (0x3CU)

/* Register DCBAAP_LO */
#define CSL_USB3SSDWC_DCBAAP_LO                                 (0x50U)

/* Register DCBAAP_HI */
#define CSL_USB3SSDWC_DCBAAP_HI                                 (0x54U)

/* Configure Register Bit Definitions. This register is in the Aux Power well. 
 * It is only reset by platform hardware during a cold reset or in response to 
 * a Host Controller Reset (HCRST). The initial conditions of a port are 
 * described in section 4.19. */
#define CSL_USB3SSDWC_CONFIG                                    (0x58U)

/* Microframe Index Register Bit Definitions. */
#define CSL_USB3SSDWC_MFINDEX                                   (0x440U)

/* Register RsvdZ */
#define CSL_USB3SSDWC_RSVDZ                                     (0x444U)

/* Register USBLEGSUP */
#define CSL_USB3SSDWC_USBLEGSUP                                 (0xA60U)

/* Register USBLEGCTLSTS */
#define CSL_USB3SSDWC_USBLEGCTLSTS                              (0xA64U)

/* Register SUPTPRT2_DW0 */
#define CSL_USB3SSDWC_SUPTPRT2_DW0                              (0xA70U)

/* Register SUPTPRT2_DW1 */
#define CSL_USB3SSDWC_SUPTPRT2_DW1                              (0xA74U)

/* xHCI Supported Protocol Capability ? Data Word 2 */
#define CSL_USB3SSDWC_SUPTPRT2_DW2                              (0xA78U)

/* Register SUPTPRT2_DW3 */
#define CSL_USB3SSDWC_SUPTPRT2_DW3                              (0xA7CU)

/* Register SUPTPRT3_DW0 */
#define CSL_USB3SSDWC_SUPTPRT3_DW0                              (0xA80U)

/* Register SUPTPRT3_DW1 */
#define CSL_USB3SSDWC_SUPTPRT3_DW1                              (0xA84U)

/* Register SUPTPRT3_DW2 */
#define CSL_USB3SSDWC_SUPTPRT3_DW2                              (0xA88U)

/* Register SUPTPRT3_DW3 */
#define CSL_USB3SSDWC_SUPTPRT3_DW3                              (0xA8CU)

/* Register DCID */
#define CSL_USB3SSDWC_DCID                                      (0xA90U)

/* Register DCDB */
#define CSL_USB3SSDWC_DCDB                                      (0xA94U)

/* Register DCERSTSZ */
#define CSL_USB3SSDWC_DCERSTSZ                                  (0xA98U)

/* Register DCERSTBA_LO */
#define CSL_USB3SSDWC_DCERSTBA_LO                               (0xAA0U)

/* Register DCERSTBA_HI */
#define CSL_USB3SSDWC_DCERSTBA_HI                               (0xAA4U)

/* Register DCERDP_LO */
#define CSL_USB3SSDWC_DCERDP_LO                                 (0xAA8U)

/* Register DCERDP_HI */
#define CSL_USB3SSDWC_DCERDP_HI                                 (0xAACU)

/* Register DCCTRL */
#define CSL_USB3SSDWC_DCCTRL                                    (0xAB0U)

/* Register DCST */
#define CSL_USB3SSDWC_DCST                                      (0xAB4U)

/* Register DCPORTSC */
#define CSL_USB3SSDWC_DCPORTSC                                  (0xAB8U)

/* Register DCCP_LO */
#define CSL_USB3SSDWC_DCCP_LO                                   (0xAC0U)

/* Register DCCP_HI */
#define CSL_USB3SSDWC_DCCP_HI                                   (0xAC4U)

/* Register DCDDI1 */
#define CSL_USB3SSDWC_DCDDI1                                    (0xAC8U)

/* Register DCDDI2 */
#define CSL_USB3SSDWC_DCDDI2                                    (0xACCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* GSBUSCFG0 */

#define CSL_USB3SSDWC_GSBUSCFG0_INCRBRSTENA_MASK                (0x00000001U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCRBRSTENA_SHIFT               (0U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCRBRSTENA_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCRBRSTENA_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR4BRSTENA_MASK               (0x00000002U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR4BRSTENA_SHIFT              (1U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR4BRSTENA_RESETVAL           (0x00000001U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR4BRSTENA_MAX                (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR8BRSTENA_MASK               (0x00000004U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR8BRSTENA_SHIFT              (2U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR8BRSTENA_RESETVAL           (0x00000001U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR8BRSTENA_MAX                (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR16BRSTENA_MASK              (0x00000008U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR16BRSTENA_SHIFT             (3U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR16BRSTENA_RESETVAL          (0x00000001U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR16BRSTENA_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR32BRSTENA_MASK              (0x00000010U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR32BRSTENA_SHIFT             (4U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR32BRSTENA_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR32BRSTENA_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR64BRSTENA_MASK              (0x00000020U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR64BRSTENA_SHIFT             (5U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR64BRSTENA_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR64BRSTENA_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR128BRSTENA_MASK             (0x00000040U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR128BRSTENA_SHIFT            (6U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR128BRSTENA_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR128BRSTENA_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_INCR256BRSTENA_MASK             (0x00000080U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR256BRSTENA_SHIFT            (7U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR256BRSTENA_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_INCR256BRSTENA_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_DESBIGEND_MASK                  (0x00000400U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESBIGEND_SHIFT                 (10U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESBIGEND_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESBIGEND_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_DATBIGEND_MASK                  (0x00000800U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATBIGEND_SHIFT                 (11U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATBIGEND_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATBIGEND_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_STOREANDFORWARD_MASK            (0x00001000U)
#define CSL_USB3SSDWC_GSBUSCFG0_STOREANDFORWARD_SHIFT           (12U)
#define CSL_USB3SSDWC_GSBUSCFG0_STOREANDFORWARD_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_STOREANDFORWARD_MAX             (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_SINGREQ_MASK                    (0x00004000U)
#define CSL_USB3SSDWC_GSBUSCFG0_SINGREQ_SHIFT                   (14U)
#define CSL_USB3SSDWC_GSBUSCFG0_SINGREQ_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_SINGREQ_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG0_DESWRREQINFO_MASK               (0x000F0000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESWRREQINFO_SHIFT              (16U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESWRREQINFO_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESWRREQINFO_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG0_DATWRREQINFO_MASK               (0x00F00000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATWRREQINFO_SHIFT              (20U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATWRREQINFO_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATWRREQINFO_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG0_DESRDREQINFO_MASK               (0x0F000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESRDREQINFO_SHIFT              (24U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESRDREQINFO_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DESRDREQINFO_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG0_DATRDREQINFO_MASK               (0xF0000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATRDREQINFO_SHIFT              (28U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATRDREQINFO_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG0_DATRDREQINFO_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG0_RESETVAL                        (0x0000000eU)

/* GSBUSCFG1 */

#define CSL_USB3SSDWC_GSBUSCFG1_DESADRSPC_MASK                  (0x0000000FU)
#define CSL_USB3SSDWC_GSBUSCFG1_DESADRSPC_SHIFT                 (0U)
#define CSL_USB3SSDWC_GSBUSCFG1_DESADRSPC_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG1_DESADRSPC_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG1_DATADRSPC_MASK                  (0x000000F0U)
#define CSL_USB3SSDWC_GSBUSCFG1_DATADRSPC_SHIFT                 (4U)
#define CSL_USB3SSDWC_GSBUSCFG1_DATADRSPC_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG1_DATADRSPC_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG1_PIPETRANSLIMIT_MASK             (0x00000F00U)
#define CSL_USB3SSDWC_GSBUSCFG1_PIPETRANSLIMIT_SHIFT            (8U)
#define CSL_USB3SSDWC_GSBUSCFG1_PIPETRANSLIMIT_RESETVAL         (0x0000000fU)
#define CSL_USB3SSDWC_GSBUSCFG1_PIPETRANSLIMIT_MAX              (0x0000000fU)

#define CSL_USB3SSDWC_GSBUSCFG1_EN1KPAGE_MASK                   (0x00001000U)
#define CSL_USB3SSDWC_GSBUSCFG1_EN1KPAGE_SHIFT                  (12U)
#define CSL_USB3SSDWC_GSBUSCFG1_EN1KPAGE_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GSBUSCFG1_EN1KPAGE_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_GSBUSCFG1_RESETVAL                        (0x00000f00U)

/* GTXTHRCFG */

#define CSL_USB3SSDWC_GTXTHRCFG_SBUSISOTHREN_MASK               (0x00008000U)
#define CSL_USB3SSDWC_GTXTHRCFG_SBUSISOTHREN_SHIFT              (15U)
#define CSL_USB3SSDWC_GTXTHRCFG_SBUSISOTHREN_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_SBUSISOTHREN_MAX                (0x00000001U)

#define CSL_USB3SSDWC_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK          (0x00FF0000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT         (16U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBMAXTXBURSTSIZE_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBMAXTXBURSTSIZE_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNT_MASK                (0x0F000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNT_SHIFT               (24U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNT_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNT_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNTSEL_MASK             (0x20000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT            (29U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNTSEL_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBTXPKTCNTSEL_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GTXTHRCFG_USBISOTHREN_MASK                (0x80000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBISOTHREN_SHIFT               (31U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBISOTHREN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GTXTHRCFG_USBISOTHREN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GTXTHRCFG_RESETVAL                        (0x00000000U)

/* GRXTHRCFG */

#define CSL_USB3SSDWC_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK          (0x00F80000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT         (19U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBMAXRXBURSTSIZE_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBMAXRXBURSTSIZE_MAX           (0x0000001fU)

#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNT_MASK                (0x0F000000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNT_SHIFT               (24U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNT_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNT_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNTSEL_MASK             (0x20000000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT            (29U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNTSEL_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GRXTHRCFG_USBRXPKTCNTSEL_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GRXTHRCFG_RESETVAL                        (0x00000000U)

/* GCTL */

#define CSL_USB3SSDWC_GCTL_DSBLCLKGTNG_MASK                     (0x00000001U)
#define CSL_USB3SSDWC_GCTL_DSBLCLKGTNG_SHIFT                    (0U)
#define CSL_USB3SSDWC_GCTL_DSBLCLKGTNG_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GCTL_DSBLCLKGTNG_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GCTL_GBLHIBERNATIONEN_MASK                (0x00000002U)
#define CSL_USB3SSDWC_GCTL_GBLHIBERNATIONEN_SHIFT               (1U)
#define CSL_USB3SSDWC_GCTL_GBLHIBERNATIONEN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GCTL_GBLHIBERNATIONEN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GCTL_U2EXIT_LFPS_MASK                     (0x00000004U)
#define CSL_USB3SSDWC_GCTL_U2EXIT_LFPS_SHIFT                    (2U)
#define CSL_USB3SSDWC_GCTL_U2EXIT_LFPS_RESETVAL                 (0x00000001U)
#define CSL_USB3SSDWC_GCTL_U2EXIT_LFPS_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GCTL_DISSCRAMBLE_MASK                     (0x00000008U)
#define CSL_USB3SSDWC_GCTL_DISSCRAMBLE_SHIFT                    (3U)
#define CSL_USB3SSDWC_GCTL_DISSCRAMBLE_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GCTL_DISSCRAMBLE_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GCTL_SCALEDOWN_MASK                       (0x00000030U)
#define CSL_USB3SSDWC_GCTL_SCALEDOWN_SHIFT                      (4U)
#define CSL_USB3SSDWC_GCTL_SCALEDOWN_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GCTL_SCALEDOWN_MAX                        (0x00000003U)

#define CSL_USB3SSDWC_GCTL_RAMCLKSEL_MASK                       (0x000000C0U)
#define CSL_USB3SSDWC_GCTL_RAMCLKSEL_SHIFT                      (6U)
#define CSL_USB3SSDWC_GCTL_RAMCLKSEL_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GCTL_RAMCLKSEL_MAX                        (0x00000003U)

#define CSL_USB3SSDWC_GCTL_DEBUGATTACH_MASK                     (0x00000100U)
#define CSL_USB3SSDWC_GCTL_DEBUGATTACH_SHIFT                    (8U)
#define CSL_USB3SSDWC_GCTL_DEBUGATTACH_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GCTL_DEBUGATTACH_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GCTL_U1U2TIMERSCALE_MASK                  (0x00000200U)
#define CSL_USB3SSDWC_GCTL_U1U2TIMERSCALE_SHIFT                 (9U)
#define CSL_USB3SSDWC_GCTL_U1U2TIMERSCALE_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GCTL_U1U2TIMERSCALE_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_GCTL_SOFITPSYNC_MASK                      (0x00000400U)
#define CSL_USB3SSDWC_GCTL_SOFITPSYNC_SHIFT                     (10U)
#define CSL_USB3SSDWC_GCTL_SOFITPSYNC_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GCTL_SOFITPSYNC_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_GCTL_CORESOFTRESET_MASK                   (0x00000800U)
#define CSL_USB3SSDWC_GCTL_CORESOFTRESET_SHIFT                  (11U)
#define CSL_USB3SSDWC_GCTL_CORESOFTRESET_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GCTL_CORESOFTRESET_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_GCTL_PRTCAPDIR_MASK                       (0x00003000U)
#define CSL_USB3SSDWC_GCTL_PRTCAPDIR_SHIFT                      (12U)
#define CSL_USB3SSDWC_GCTL_PRTCAPDIR_RESETVAL                   (0x00000003U)
#define CSL_USB3SSDWC_GCTL_PRTCAPDIR_MAX                        (0x00000003U)

#define CSL_USB3SSDWC_GCTL_FRMSCLDWN_MASK                       (0x0000C000U)
#define CSL_USB3SSDWC_GCTL_FRMSCLDWN_SHIFT                      (14U)
#define CSL_USB3SSDWC_GCTL_FRMSCLDWN_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GCTL_FRMSCLDWN_MAX                        (0x00000003U)

#define CSL_USB3SSDWC_GCTL_U2RSTECN_MASK                        (0x00010000U)
#define CSL_USB3SSDWC_GCTL_U2RSTECN_SHIFT                       (16U)
#define CSL_USB3SSDWC_GCTL_U2RSTECN_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_GCTL_U2RSTECN_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_GCTL_BYPSSETADDR_MASK                     (0x00020000U)
#define CSL_USB3SSDWC_GCTL_BYPSSETADDR_SHIFT                    (17U)
#define CSL_USB3SSDWC_GCTL_BYPSSETADDR_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GCTL_BYPSSETADDR_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GCTL_MASTERFILTBYPASS_MASK                (0x00040000U)
#define CSL_USB3SSDWC_GCTL_MASTERFILTBYPASS_SHIFT               (18U)
#define CSL_USB3SSDWC_GCTL_MASTERFILTBYPASS_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GCTL_MASTERFILTBYPASS_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GCTL_PWRDNSCALE_MASK                      (0xFFF80000U)
#define CSL_USB3SSDWC_GCTL_PWRDNSCALE_SHIFT                     (19U)
#define CSL_USB3SSDWC_GCTL_PWRDNSCALE_RESETVAL                  (0x000004b0U)
#define CSL_USB3SSDWC_GCTL_PWRDNSCALE_MAX                       (0x00001fffU)

#define CSL_USB3SSDWC_GCTL_RESETVAL                             (0x25803004U)

/* GPMSTS */

#define CSL_USB3SSDWC_GPMSTS_U2WAKEUP_MASK                      (0x000001FFU)
#define CSL_USB3SSDWC_GPMSTS_U2WAKEUP_SHIFT                     (0U)
#define CSL_USB3SSDWC_GPMSTS_U2WAKEUP_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GPMSTS_U2WAKEUP_MAX                       (0x000001ffU)

#define CSL_USB3SSDWC_GPMSTS_U3WAKEUP_MASK                      (0x0000F000U)
#define CSL_USB3SSDWC_GPMSTS_U3WAKEUP_SHIFT                     (12U)
#define CSL_USB3SSDWC_GPMSTS_U3WAKEUP_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GPMSTS_U3WAKEUP_MAX                       (0x0000000fU)

#define CSL_USB3SSDWC_GPMSTS_PORTSEL_MASK                       (0xF0000000U)
#define CSL_USB3SSDWC_GPMSTS_PORTSEL_SHIFT                      (28U)
#define CSL_USB3SSDWC_GPMSTS_PORTSEL_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GPMSTS_PORTSEL_MAX                        (0x0000000fU)

#define CSL_USB3SSDWC_GPMSTS_RESETVAL                           (0x00000000U)

/* GSTS */

#define CSL_USB3SSDWC_GSTS_CURMOD_MASK                          (0x00000003U)
#define CSL_USB3SSDWC_GSTS_CURMOD_SHIFT                         (0U)
#define CSL_USB3SSDWC_GSTS_CURMOD_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_GSTS_CURMOD_MAX                           (0x00000003U)

#define CSL_USB3SSDWC_GSTS_BUSERRADDRVLD_MASK                   (0x00000010U)
#define CSL_USB3SSDWC_GSTS_BUSERRADDRVLD_SHIFT                  (4U)
#define CSL_USB3SSDWC_GSTS_BUSERRADDRVLD_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GSTS_BUSERRADDRVLD_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_GSTS_CSRTIMEOUT_MASK                      (0x00000020U)
#define CSL_USB3SSDWC_GSTS_CSRTIMEOUT_SHIFT                     (5U)
#define CSL_USB3SSDWC_GSTS_CSRTIMEOUT_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GSTS_CSRTIMEOUT_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_GSTS_DEVICE_IP_MASK                       (0x00000040U)
#define CSL_USB3SSDWC_GSTS_DEVICE_IP_SHIFT                      (6U)
#define CSL_USB3SSDWC_GSTS_DEVICE_IP_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GSTS_DEVICE_IP_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_GSTS_HOST_IP_MASK                         (0x00000080U)
#define CSL_USB3SSDWC_GSTS_HOST_IP_SHIFT                        (7U)
#define CSL_USB3SSDWC_GSTS_HOST_IP_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_GSTS_HOST_IP_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_GSTS_ADP_IP_MASK                          (0x00000100U)
#define CSL_USB3SSDWC_GSTS_ADP_IP_SHIFT                         (8U)
#define CSL_USB3SSDWC_GSTS_ADP_IP_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_GSTS_ADP_IP_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_GSTS_BC_IP_MASK                           (0x00000200U)
#define CSL_USB3SSDWC_GSTS_BC_IP_SHIFT                          (9U)
#define CSL_USB3SSDWC_GSTS_BC_IP_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_GSTS_BC_IP_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_GSTS_OTG_IP_MASK                          (0x00000400U)
#define CSL_USB3SSDWC_GSTS_OTG_IP_SHIFT                         (10U)
#define CSL_USB3SSDWC_GSTS_OTG_IP_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_GSTS_OTG_IP_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_GSTS_SSIC_IP_MASK                         (0x00000800U)
#define CSL_USB3SSDWC_GSTS_SSIC_IP_SHIFT                        (11U)
#define CSL_USB3SSDWC_GSTS_SSIC_IP_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_GSTS_SSIC_IP_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_GSTS_CBELT_MASK                           (0xFFF00000U)
#define CSL_USB3SSDWC_GSTS_CBELT_SHIFT                          (20U)
#define CSL_USB3SSDWC_GSTS_CBELT_RESETVAL                       (0x000003e8U)
#define CSL_USB3SSDWC_GSTS_CBELT_MAX                            (0x00000fffU)

#define CSL_USB3SSDWC_GSTS_RESETVAL                             (0x3e800000U)

/* GUCTL1 */

#define CSL_USB3SSDWC_GUCTL1_LOA_FILTER_EN_MASK                 (0x00000001U)
#define CSL_USB3SSDWC_GUCTL1_LOA_FILTER_EN_SHIFT                (0U)
#define CSL_USB3SSDWC_GUCTL1_LOA_FILTER_EN_RESETVAL             (0x00000001U)
#define CSL_USB3SSDWC_GUCTL1_LOA_FILTER_EN_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_GUCTL1_OVRLD_L1_SUSP_COM_MASK             (0x00000002U)
#define CSL_USB3SSDWC_GUCTL1_OVRLD_L1_SUSP_COM_SHIFT            (1U)
#define CSL_USB3SSDWC_GUCTL1_OVRLD_L1_SUSP_COM_RESETVAL         (0x00000001U)
#define CSL_USB3SSDWC_GUCTL1_OVRLD_L1_SUSP_COM_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GUCTL1_HC_PARCHK_DISABLE_MASK             (0x00000004U)
#define CSL_USB3SSDWC_GUCTL1_HC_PARCHK_DISABLE_SHIFT            (2U)
#define CSL_USB3SSDWC_GUCTL1_HC_PARCHK_DISABLE_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GUCTL1_HC_PARCHK_DISABLE_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GUCTL1_HC_ERRATA_ENABLE_MASK              (0x00000008U)
#define CSL_USB3SSDWC_GUCTL1_HC_ERRATA_ENABLE_SHIFT             (3U)
#define CSL_USB3SSDWC_GUCTL1_HC_ERRATA_ENABLE_RESETVAL          (0x00000001U)
#define CSL_USB3SSDWC_GUCTL1_HC_ERRATA_ENABLE_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MASK        (0x000000F0U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_FOR_HOST_SHIFT       (4U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_FOR_HOST_RESETVAL    (0x00000008U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MAX         (0x0000000fU)

#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MASK     (0x00000100U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_SHIFT    (8U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_RESETVAL  (0x00000001U)
#define CSL_USB3SSDWC_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MAX      (0x00000001U)

#define CSL_USB3SSDWC_GUCTL1_RESETVAL                           (0x0000018bU)

/* GSNPSID */

#define CSL_USB3SSDWC_GSNPSID_SYNOPSYSID_MASK                   (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GSNPSID_SYNOPSYSID_SHIFT                  (0U)
#define CSL_USB3SSDWC_GSNPSID_SYNOPSYSID_RESETVAL               (0x5533260aU)
#define CSL_USB3SSDWC_GSNPSID_SYNOPSYSID_MAX                    (0xffffffffU)

#define CSL_USB3SSDWC_GSNPSID_RESETVAL                          (0x5533260aU)

/* GGPIO */

#define CSL_USB3SSDWC_GGPIO_GPI_MASK                            (0x0000FFFFU)
#define CSL_USB3SSDWC_GGPIO_GPI_SHIFT                           (0U)
#define CSL_USB3SSDWC_GGPIO_GPI_RESETVAL                        (0x00000000U)
#define CSL_USB3SSDWC_GGPIO_GPI_MAX                             (0x0000ffffU)

#define CSL_USB3SSDWC_GGPIO_GPO_MASK                            (0xFFFF0000U)
#define CSL_USB3SSDWC_GGPIO_GPO_SHIFT                           (16U)
#define CSL_USB3SSDWC_GGPIO_GPO_RESETVAL                        (0x00000000U)
#define CSL_USB3SSDWC_GGPIO_GPO_MAX                             (0x0000ffffU)

#define CSL_USB3SSDWC_GGPIO_RESETVAL                            (0x00000000U)

/* GUID */

#define CSL_USB3SSDWC_GUID_USERID_MASK                          (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GUID_USERID_SHIFT                         (0U)
#define CSL_USB3SSDWC_GUID_USERID_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_GUID_USERID_MAX                           (0xffffffffU)

#define CSL_USB3SSDWC_GUID_RESETVAL                             (0x00000000U)

/* GUCTL */

#define CSL_USB3SSDWC_GUCTL_DTFT_MASK                           (0x000001FFU)
#define CSL_USB3SSDWC_GUCTL_DTFT_SHIFT                          (0U)
#define CSL_USB3SSDWC_GUCTL_DTFT_RESETVAL                       (0x00000010U)
#define CSL_USB3SSDWC_GUCTL_DTFT_MAX                            (0x000001ffU)

#define CSL_USB3SSDWC_GUCTL_DTCT_MASK                           (0x00000600U)
#define CSL_USB3SSDWC_GUCTL_DTCT_SHIFT                          (9U)
#define CSL_USB3SSDWC_GUCTL_DTCT_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_DTCT_MAX                            (0x00000003U)

#define CSL_USB3SSDWC_GUCTL_INSRTEXTRFSBODI_MASK                (0x00000800U)
#define CSL_USB3SSDWC_GUCTL_INSRTEXTRFSBODI_SHIFT               (11U)
#define CSL_USB3SSDWC_GUCTL_INSRTEXTRFSBODI_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_INSRTEXTRFSBODI_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_EXTCAPSUPPTEN_MASK                  (0x00001000U)
#define CSL_USB3SSDWC_GUCTL_EXTCAPSUPPTEN_SHIFT                 (12U)
#define CSL_USB3SSDWC_GUCTL_EXTCAPSUPPTEN_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_EXTCAPSUPPTEN_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_ENOVERLAPCHK_MASK                   (0x00002000U)
#define CSL_USB3SSDWC_GUCTL_ENOVERLAPCHK_SHIFT                  (13U)
#define CSL_USB3SSDWC_GUCTL_ENOVERLAPCHK_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_ENOVERLAPCHK_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_USBHSTINAUTORETRYEN_MASK            (0x00004000U)
#define CSL_USB3SSDWC_GUCTL_USBHSTINAUTORETRYEN_SHIFT           (14U)
#define CSL_USB3SSDWC_GUCTL_USBHSTINAUTORETRYEN_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_USBHSTINAUTORETRYEN_MAX             (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_CMDEVADDR_MASK                      (0x00008000U)
#define CSL_USB3SSDWC_GUCTL_CMDEVADDR_SHIFT                     (15U)
#define CSL_USB3SSDWC_GUCTL_CMDEVADDR_RESETVAL                  (0x00000001U)
#define CSL_USB3SSDWC_GUCTL_CMDEVADDR_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_RESBWHSEPS_MASK                     (0x00010000U)
#define CSL_USB3SSDWC_GUCTL_RESBWHSEPS_SHIFT                    (16U)
#define CSL_USB3SSDWC_GUCTL_RESBWHSEPS_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_RESBWHSEPS_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_SPRSCTRLTRANSEN_MASK                (0x00020000U)
#define CSL_USB3SSDWC_GUCTL_SPRSCTRLTRANSEN_SHIFT               (17U)
#define CSL_USB3SSDWC_GUCTL_SPRSCTRLTRANSEN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_SPRSCTRLTRANSEN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_PSQEXTRRESSP_MASK                   (0x001C0000U)
#define CSL_USB3SSDWC_GUCTL_PSQEXTRRESSP_SHIFT                  (18U)
#define CSL_USB3SSDWC_GUCTL_PSQEXTRRESSP_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_PSQEXTRRESSP_MAX                    (0x00000007U)

#define CSL_USB3SSDWC_GUCTL_NOEXTRDL_MASK                       (0x00200000U)
#define CSL_USB3SSDWC_GUCTL_NOEXTRDL_SHIFT                      (21U)
#define CSL_USB3SSDWC_GUCTL_NOEXTRDL_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_GUCTL_NOEXTRDL_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_GUCTL_REFCLKPER_MASK                      (0xFFC00000U)
#define CSL_USB3SSDWC_GUCTL_REFCLKPER_SHIFT                     (22U)
#define CSL_USB3SSDWC_GUCTL_REFCLKPER_RESETVAL                  (0x00000008U)
#define CSL_USB3SSDWC_GUCTL_REFCLKPER_MAX                       (0x000003ffU)

#define CSL_USB3SSDWC_GUCTL_RESETVAL                            (0x02008010U)

/* GBUSERRADDRLO */

#define CSL_USB3SSDWC_GBUSERRADDRLO_BUSERRADDR_MASK             (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GBUSERRADDRLO_BUSERRADDR_SHIFT            (0U)
#define CSL_USB3SSDWC_GBUSERRADDRLO_BUSERRADDR_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GBUSERRADDRLO_BUSERRADDR_MAX              (0xffffffffU)

#define CSL_USB3SSDWC_GBUSERRADDRLO_RESETVAL                    (0x00000000U)

/* GBUSERRADDRHI */

#define CSL_USB3SSDWC_GBUSERRADDRHI_BUSERRADDR_MASK             (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GBUSERRADDRHI_BUSERRADDR_SHIFT            (0U)
#define CSL_USB3SSDWC_GBUSERRADDRHI_BUSERRADDR_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GBUSERRADDRHI_BUSERRADDR_MAX              (0xffffffffU)

#define CSL_USB3SSDWC_GBUSERRADDRHI_RESETVAL                    (0x00000000U)

/* GPRTBIMAPLO */

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM1_MASK                   (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM1_SHIFT                  (0U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM1_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM1_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM2_MASK                   (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM2_SHIFT                  (4U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM2_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM2_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM3_MASK                   (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM3_SHIFT                  (8U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM3_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM3_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM4_MASK                   (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM4_SHIFT                  (12U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM4_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM4_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM5_MASK                   (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM5_SHIFT                  (16U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM5_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM5_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM6_MASK                   (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM6_SHIFT                  (20U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM6_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM6_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM7_MASK                   (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM7_SHIFT                  (24U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM7_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM7_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM8_MASK                   (0xF0000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM8_SHIFT                  (28U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM8_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPLO_BINUM8_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPLO_RESETVAL                      (0x00000000U)

/* GPRTBIMAPHI */

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM9_MASK                   (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM9_SHIFT                  (0U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM9_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM9_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM10_MASK                  (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM10_SHIFT                 (4U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM10_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM10_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM11_MASK                  (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM11_SHIFT                 (8U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM11_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM11_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM12_MASK                  (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM12_SHIFT                 (12U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM12_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM12_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM13_MASK                  (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM13_SHIFT                 (16U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM13_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM13_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM14_MASK                  (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM14_SHIFT                 (20U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM14_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM14_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM15_MASK                  (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM15_SHIFT                 (24U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM15_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAPHI_BINUM15_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAPHI_RESETVAL                      (0x00000000U)

/* GHWPARAMS0 */

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_2_0_MASK            (0x00000007U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_2_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_2_0_RESETVAL        (0x00000002U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_2_0_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_5_3_MASK            (0x00000038U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_5_3_SHIFT           (3U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_5_3_RESETVAL        (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_5_3_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_7_6_MASK            (0x000000C0U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_7_6_SHIFT           (6U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_7_6_RESETVAL        (0x00000003U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_7_6_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_15_8_MASK           (0x0000FF00U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_15_8_SHIFT          (8U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_15_8_RESETVAL       (0x00000040U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_15_8_MAX            (0x000000ffU)

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_23_16_MASK          (0x00FF0000U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_23_16_SHIFT         (16U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_23_16_RESETVAL      (0x00000020U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_23_16_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_31_24_MASK          (0xFF000000U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_31_24_SHIFT         (24U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_31_24_RESETVAL      (0x00000040U)
#define CSL_USB3SSDWC_GHWPARAMS0_GHWPARAMS0_31_24_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_GHWPARAMS0_RESETVAL                       (0x402040caU)

/* GHWPARAMS1 */

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_2_0_MASK            (0x00000007U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_2_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_2_0_RESETVAL        (0x00000003U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_2_0_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_5_3_MASK            (0x00000038U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_5_3_SHIFT           (3U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_5_3_RESETVAL        (0x00000007U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_5_3_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_8_6_MASK            (0x000001C0U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_8_6_SHIFT           (6U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_8_6_RESETVAL        (0x00000004U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_8_6_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_11_9_MASK           (0x00000E00U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_11_9_SHIFT          (9U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_11_9_RESETVAL       (0x00000004U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_11_9_MAX            (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_14_12_MASK          (0x00007000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_14_12_SHIFT         (12U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_14_12_RESETVAL      (0x00000004U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_14_12_MAX           (0x00000007U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_20_15_MASK          (0x001F8000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_20_15_SHIFT         (15U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_20_15_RESETVAL      (0x00000010U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_20_15_MAX           (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_22_21_MASK          (0x00600000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_22_21_SHIFT         (21U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_22_21_RESETVAL      (0x00000003U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_22_21_MAX           (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_23_MASK             (0x00800000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_23_SHIFT            (23U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_23_RESETVAL         (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_23_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_25_24_MASK          (0x03000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_25_24_SHIFT         (24U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_25_24_RESETVAL      (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_25_24_MAX           (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_26_MASK             (0x04000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_26_SHIFT            (26U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_26_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_26_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_27_MASK             (0x08000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_27_SHIFT            (27U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_27_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_27_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_28_MASK             (0x10000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_28_SHIFT            (28U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_28_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_28_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_29_MASK             (0x20000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_29_SHIFT            (29U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_29_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_29_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_30_MASK             (0x40000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_30_SHIFT            (30U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_30_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_30_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_31_MASK             (0x80000000U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_31_SHIFT            (31U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_31_RESETVAL         (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS1_GHWPARAMS1_31_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS1_RESETVAL                       (0x81e8493bU)

/* GHWPARAMS2 */

#define CSL_USB3SSDWC_GHWPARAMS2_GHWPARAMS2_31_0_MASK           (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GHWPARAMS2_GHWPARAMS2_31_0_SHIFT          (0U)
#define CSL_USB3SSDWC_GHWPARAMS2_GHWPARAMS2_31_0_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS2_GHWPARAMS2_31_0_MAX            (0xffffffffU)

#define CSL_USB3SSDWC_GHWPARAMS2_RESETVAL                       (0x00000000U)

/* GHWPARAMS3 */

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_1_0_MASK            (0x00000003U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_1_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_1_0_RESETVAL        (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_1_0_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_3_2_MASK            (0x0000000CU)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_3_2_SHIFT           (2U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_3_2_RESETVAL        (0x00000003U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_3_2_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_5_4_MASK            (0x00000030U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_5_4_SHIFT           (4U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_5_4_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_5_4_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_7_6_MASK            (0x000000C0U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_7_6_SHIFT           (6U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_7_6_RESETVAL        (0x00000002U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_7_6_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_9_8_MASK            (0x00000300U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_9_8_SHIFT           (8U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_9_8_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_9_8_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_10_MASK             (0x00000400U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_10_SHIFT            (10U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_10_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_10_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_11_MASK             (0x00000800U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_11_SHIFT            (11U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_11_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_11_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_17_12_MASK          (0x0003F000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_17_12_SHIFT         (12U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_17_12_RESETVAL      (0x00000020U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_17_12_MAX           (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_22_18_MASK          (0x007C0000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_22_18_SHIFT         (18U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_22_18_RESETVAL      (0x00000010U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_22_18_MAX           (0x0000001fU)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_30_23_MASK          (0x7F800000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_30_23_SHIFT         (23U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_30_23_RESETVAL      (0x00000020U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_30_23_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_31_MASK             (0x80000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_31_SHIFT            (31U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_31_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS3_GHWPARAMS3_31_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS3_RESETVAL                       (0x1042008dU)

/* GHWPARAMS4 */

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_5_0_MASK            (0x0000003FU)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_5_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_5_0_RESETVAL        (0x00000004U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_5_0_MAX             (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_6_MASK              (0x00000040U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_6_SHIFT             (6U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_6_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_6_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_8_7_MASK            (0x00000180U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_8_7_SHIFT           (7U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_8_7_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_8_7_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_10_9_MASK           (0x00000600U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_10_9_SHIFT          (9U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_10_9_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_10_9_MAX            (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_11_MASK             (0x00000800U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_11_SHIFT            (11U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_11_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_11_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_12_MASK             (0x00001000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_12_SHIFT            (12U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_12_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_12_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_16_13_MASK          (0x0001E000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_16_13_SHIFT         (13U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_16_13_RESETVAL      (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_16_13_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_20_17_MASK          (0x001E0000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_20_17_SHIFT         (17U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_20_17_RESETVAL      (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_20_17_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_21_MASK             (0x00200000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_21_SHIFT            (21U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_21_RESETVAL         (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_21_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_22_MASK             (0x00400000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_22_SHIFT            (22U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_22_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_22_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_23_MASK             (0x00800000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_23_SHIFT            (23U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_23_RESETVAL         (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_23_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_27_24_MASK          (0x0F000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_27_24_SHIFT         (24U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_27_24_RESETVAL      (0x00000007U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_27_24_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_31_28_MASK          (0xF0000000U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_31_28_SHIFT         (28U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_31_28_RESETVAL      (0x00000004U)
#define CSL_USB3SSDWC_GHWPARAMS4_GHWPARAMS4_31_28_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS4_RESETVAL                       (0x47a22004U)

/* GHWPARAMS5 */

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_3_0_MASK            (0x0000000FU)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_3_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_3_0_RESETVAL        (0x00000008U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_3_0_MAX             (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_9_4_MASK            (0x000003F0U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_9_4_SHIFT           (4U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_9_4_RESETVAL        (0x00000008U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_9_4_MAX             (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_15_10_MASK          (0x0000FC00U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_15_10_SHIFT         (10U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_15_10_RESETVAL      (0x00000008U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_15_10_MAX           (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_21_16_MASK          (0x003F0000U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_21_16_SHIFT         (16U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_21_16_RESETVAL      (0x00000020U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_21_16_MAX           (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_27_22_MASK          (0x0FC00000U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_27_22_SHIFT         (22U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_27_22_RESETVAL      (0x00000010U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_27_22_MAX           (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_31_28_MASK          (0xF0000000U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_31_28_SHIFT         (28U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_31_28_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS5_GHWPARAMS5_31_28_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GHWPARAMS5_RESETVAL                       (0x04202088U)

/* GHWPARAMS6 */

#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_5_0_MASK            (0x0000003FU)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_5_0_SHIFT           (0U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_5_0_RESETVAL        (0x00000020U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_5_0_MAX             (0x0000003fU)

#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_6_MASK              (0x00000040U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_6_SHIFT             (6U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_6_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_6_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_7_MASK              (0x00000080U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_7_SHIFT             (7U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_7_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_7_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_9_8_MASK            (0x00000300U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_9_8_SHIFT           (8U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_9_8_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_9_8_MAX             (0x00000003U)

#define CSL_USB3SSDWC_GHWPARAMS6_SRPSUPPORT_MASK                (0x00000400U)
#define CSL_USB3SSDWC_GHWPARAMS6_SRPSUPPORT_SHIFT               (10U)
#define CSL_USB3SSDWC_GHWPARAMS6_SRPSUPPORT_RESETVAL            (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS6_SRPSUPPORT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_HNPSUPPORT_MASK                (0x00000800U)
#define CSL_USB3SSDWC_GHWPARAMS6_HNPSUPPORT_SHIFT               (11U)
#define CSL_USB3SSDWC_GHWPARAMS6_HNPSUPPORT_RESETVAL            (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS6_HNPSUPPORT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_ADPSUPPORT_MASK                (0x00001000U)
#define CSL_USB3SSDWC_GHWPARAMS6_ADPSUPPORT_SHIFT               (12U)
#define CSL_USB3SSDWC_GHWPARAMS6_ADPSUPPORT_RESETVAL            (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS6_ADPSUPPORT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_OTG_SS_SUPPORT_MASK            (0x00002000U)
#define CSL_USB3SSDWC_GHWPARAMS6_OTG_SS_SUPPORT_SHIFT           (13U)
#define CSL_USB3SSDWC_GHWPARAMS6_OTG_SS_SUPPORT_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GHWPARAMS6_OTG_SS_SUPPORT_MAX             (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_BCSUPPORT_MASK                 (0x00004000U)
#define CSL_USB3SSDWC_GHWPARAMS6_BCSUPPORT_SHIFT                (14U)
#define CSL_USB3SSDWC_GHWPARAMS6_BCSUPPORT_RESETVAL             (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS6_BCSUPPORT_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_BUSFLTRSSUPPORT_MASK           (0x00008000U)
#define CSL_USB3SSDWC_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT          (15U)
#define CSL_USB3SSDWC_GHWPARAMS6_BUSFLTRSSUPPORT_RESETVAL       (0x00000001U)
#define CSL_USB3SSDWC_GHWPARAMS6_BUSFLTRSSUPPORT_MAX            (0x00000001U)

#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_31_16_MASK          (0xFFFF0000U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_31_16_SHIFT         (16U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_31_16_RESETVAL      (0x00000b00U)
#define CSL_USB3SSDWC_GHWPARAMS6_GHWPARAMS6_31_16_MAX           (0x0000ffffU)

#define CSL_USB3SSDWC_GHWPARAMS6_RESETVAL                       (0x0b00dc20U)

/* GHWPARAMS7 */

#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_15_0_MASK           (0x0000FFFFU)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_15_0_SHIFT          (0U)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_15_0_RESETVAL       (0x00001700U)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_15_0_MAX            (0x0000ffffU)

#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_31_16_MASK          (0xFFFF0000U)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_31_16_SHIFT         (16U)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_31_16_RESETVAL      (0x00000400U)
#define CSL_USB3SSDWC_GHWPARAMS7_GHWPARAMS7_31_16_MAX           (0x0000ffffU)

#define CSL_USB3SSDWC_GHWPARAMS7_RESETVAL                       (0x04001700U)

/* GDBGFIFOSPACE */

#define CSL_USB3SSDWC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MASK      (0x000000FFU)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_SHIFT     (0U)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_RESETVAL  (0x00000000U)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MAX       (0x000000ffU)

#define CSL_USB3SSDWC_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK        (0xFFFF0000U)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_SPACE_AVAILABLE_SHIFT       (16U)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_SPACE_AVAILABLE_RESETVAL    (0x00000042U)
#define CSL_USB3SSDWC_GDBGFIFOSPACE_SPACE_AVAILABLE_MAX         (0x0000ffffU)

#define CSL_USB3SSDWC_GDBGFIFOSPACE_RESETVAL                    (0x00420000U)

/* GDBGLTSSM */

#define CSL_USB3SSDWC_GDBGLTSSM_TXONESZEROS_MASK                (0x00000001U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXONESZEROS_SHIFT               (0U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXONESZEROS_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXONESZEROS_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_RXTERMINATION_MASK              (0x00000002U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXTERMINATION_SHIFT             (1U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXTERMINATION_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXTERMINATION_MAX               (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_TXSWING_MASK                    (0x00000004U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXSWING_SHIFT                   (2U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXSWING_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXSWING_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_LTDBCLKSTATE_MASK               (0x00000038U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBCLKSTATE_SHIFT              (3U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBCLKSTATE_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBCLKSTATE_MAX                (0x00000007U)

#define CSL_USB3SSDWC_GDBGLTSSM_TXDEEMPHASIS_MASK               (0x000000C0U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDEEMPHASIS_SHIFT              (6U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDEEMPHASIS_RESETVAL           (0x00000001U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDEEMPHASIS_MAX                (0x00000003U)

#define CSL_USB3SSDWC_GDBGLTSSM_RXEQTRAIN_MASK                  (0x00000100U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXEQTRAIN_SHIFT                 (8U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXEQTRAIN_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXEQTRAIN_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_POWERDOWN_MASK                  (0x00000600U)
#define CSL_USB3SSDWC_GDBGLTSSM_POWERDOWN_SHIFT                 (9U)
#define CSL_USB3SSDWC_GDBGLTSSM_POWERDOWN_RESETVAL              (0x00000002U)
#define CSL_USB3SSDWC_GDBGLTSSM_POWERDOWN_MAX                   (0x00000003U)

#define CSL_USB3SSDWC_GDBGLTSSM_LTDBPHYCMDSTATE_MASK            (0x00003800U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBPHYCMDSTATE_SHIFT           (11U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBPHYCMDSTATE_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBPHYCMDSTATE_MAX             (0x00000007U)

#define CSL_USB3SSDWC_GDBGLTSSM_TXDETRXLOOPBACK_MASK            (0x00004000U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDETRXLOOPBACK_SHIFT           (14U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDETRXLOOPBACK_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXDETRXLOOPBACK_MAX             (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_RXPOLARITY_MASK                 (0x00008000U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXPOLARITY_SHIFT                (15U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXPOLARITY_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_RXPOLARITY_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_TXELECLDLE_MASK                 (0x00010000U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXELECLDLE_SHIFT                (16U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXELECLDLE_RESETVAL             (0x00000001U)
#define CSL_USB3SSDWC_GDBGLTSSM_TXELECLDLE_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_ELASTICBUFFERMODE_MASK          (0x00020000U)
#define CSL_USB3SSDWC_GDBGLTSSM_ELASTICBUFFERMODE_SHIFT         (17U)
#define CSL_USB3SSDWC_GDBGLTSSM_ELASTICBUFFERMODE_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_ELASTICBUFFERMODE_MAX           (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_LTDBSUBSTATE_MASK               (0x003C0000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBSUBSTATE_SHIFT              (18U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBSUBSTATE_RESETVAL           (0x00000002U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBSUBSTATE_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GDBGLTSSM_LTDBLINKSTATE_MASK              (0x03C00000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBLINKSTATE_SHIFT             (22U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBLINKSTATE_RESETVAL          (0x00000004U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBLINKSTATE_MAX               (0x0000000fU)

#define CSL_USB3SSDWC_GDBGLTSSM_LTDBTIMEOUT_MASK                (0x04000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBTIMEOUT_SHIFT               (26U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBTIMEOUT_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_LTDBTIMEOUT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_PRTDIRECTION_MASK               (0x08000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_PRTDIRECTION_SHIFT              (27U)
#define CSL_USB3SSDWC_GDBGLTSSM_PRTDIRECTION_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_PRTDIRECTION_MAX                (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_MASK        (0x10000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_SHIFT       (28U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_RESETVAL    (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_DS_HOST_SHUTDOWN_MAX         (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_X3_XS_SWAPPING_MASK             (0x20000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_XS_SWAPPING_SHIFT            (29U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_XS_SWAPPING_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_GDBGLTSSM_X3_XS_SWAPPING_MAX              (0x00000001U)

#define CSL_USB3SSDWC_GDBGLTSSM_RESETVAL                        (0x01090440U)

/* GDBGLNMCC */

#define CSL_USB3SSDWC_GDBGLNMCC_LNMCC_BERC_MASK                 (0x000001FFU)
#define CSL_USB3SSDWC_GDBGLNMCC_LNMCC_BERC_SHIFT                (0U)
#define CSL_USB3SSDWC_GDBGLNMCC_LNMCC_BERC_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_GDBGLNMCC_LNMCC_BERC_MAX                  (0x000001ffU)

#define CSL_USB3SSDWC_GDBGLNMCC_RESETVAL                        (0x00000000U)

/* GDBGBMU */

#define CSL_USB3SSDWC_GDBGBMU_BMU_CCU_MASK                      (0x0000000FU)
#define CSL_USB3SSDWC_GDBGBMU_BMU_CCU_SHIFT                     (0U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_CCU_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_CCU_MAX                       (0x0000000fU)

#define CSL_USB3SSDWC_GDBGBMU_BMU_DCU_MASK                      (0x000000F0U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_DCU_SHIFT                     (4U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_DCU_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_DCU_MAX                       (0x0000000fU)

#define CSL_USB3SSDWC_GDBGBMU_BMU_BCU_MASK                      (0xFFFFFF00U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_BCU_SHIFT                     (8U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_BCU_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_GDBGBMU_BMU_BCU_MAX                       (0x00ffffffU)

#define CSL_USB3SSDWC_GDBGBMU_RESETVAL                          (0x00000000U)

/* GDBGLSPMUX_HST */

#define CSL_USB3SSDWC_GDBGLSPMUX_HST_HOSTSELECT_MASK            (0x00003FFFU)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_HOSTSELECT_SHIFT           (0U)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_HOSTSELECT_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_HOSTSELECT_MAX             (0x00003fffU)

#define CSL_USB3SSDWC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_MASK  (0x00FF0000U)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_SHIFT  (16U)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_RESETVAL  (0x00000000U)
#define CSL_USB3SSDWC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_MAX   (0x000000ffU)

#define CSL_USB3SSDWC_GDBGLSPMUX_HST_RESETVAL                   (0x00000000U)

/* GDBGLSP */

#define CSL_USB3SSDWC_GDBGLSP_LSPDEBUG_MASK                     (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GDBGLSP_LSPDEBUG_SHIFT                    (0U)
#define CSL_USB3SSDWC_GDBGLSP_LSPDEBUG_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_GDBGLSP_LSPDEBUG_MAX                      (0xffffffffU)

#define CSL_USB3SSDWC_GDBGLSP_RESETVAL                          (0x00000000U)

/* GDBGEPINFO0 */

#define CSL_USB3SSDWC_GDBGEPINFO0_EPDEBUG_MASK                  (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GDBGEPINFO0_EPDEBUG_SHIFT                 (0U)
#define CSL_USB3SSDWC_GDBGEPINFO0_EPDEBUG_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GDBGEPINFO0_EPDEBUG_MAX                   (0xffffffffU)

#define CSL_USB3SSDWC_GDBGEPINFO0_RESETVAL                      (0x00000000U)

/* GDBGEPINFO1 */

#define CSL_USB3SSDWC_GDBGEPINFO1_EPDEBUG_MASK                  (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GDBGEPINFO1_EPDEBUG_SHIFT                 (0U)
#define CSL_USB3SSDWC_GDBGEPINFO1_EPDEBUG_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GDBGEPINFO1_EPDEBUG_MAX                   (0xffffffffU)

#define CSL_USB3SSDWC_GDBGEPINFO1_RESETVAL                      (0x00000000U)

/* GPRTBIMAP_HSLO */

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM1_MASK                (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM1_SHIFT               (0U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM1_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM1_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM2_MASK                (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM2_SHIFT               (4U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM2_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM2_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM3_MASK                (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM3_SHIFT               (8U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM3_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM3_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM4_MASK                (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM4_SHIFT               (12U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM4_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM4_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM5_MASK                (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM5_SHIFT               (16U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM5_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM5_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM6_MASK                (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM6_SHIFT               (20U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM6_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM6_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM7_MASK                (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM7_SHIFT               (24U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM7_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM7_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM8_MASK                (0xF0000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM8_SHIFT               (28U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM8_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_BINUM8_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSLO_RESETVAL                   (0x00000000U)

/* GPRTBIMAP_HSHI */

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM9_MASK                (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM9_SHIFT               (0U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM9_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM9_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM10_MASK               (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM10_SHIFT              (4U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM10_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM10_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM11_MASK               (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM11_SHIFT              (8U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM11_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM11_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM12_MASK               (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM12_SHIFT              (12U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM12_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM12_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM13_MASK               (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM13_SHIFT              (16U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM13_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM13_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM14_MASK               (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM14_SHIFT              (20U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM14_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM14_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM15_MASK               (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM15_SHIFT              (24U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM15_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_BINUM15_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_HSHI_RESETVAL                   (0x00000000U)

/* GPRTBIMAP_FSLO */

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM1_MASK                (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM1_SHIFT               (0U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM1_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM1_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM2_MASK                (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM2_SHIFT               (4U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM2_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM2_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM3_MASK                (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM3_SHIFT               (8U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM3_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM3_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM4_MASK                (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM4_SHIFT               (12U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM4_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM4_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM5_MASK                (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM5_SHIFT               (16U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM5_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM5_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM6_MASK                (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM6_SHIFT               (20U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM6_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM6_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM7_MASK                (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM7_SHIFT               (24U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM7_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM7_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM8_MASK                (0xF0000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM8_SHIFT               (28U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM8_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_BINUM8_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSLO_RESETVAL                   (0x00000000U)

/* GPRTBIMAP_FSHI */

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM9_MASK                (0x0000000FU)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM9_SHIFT               (0U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM9_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM9_MAX                 (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM10_MASK               (0x000000F0U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM10_SHIFT              (4U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM10_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM10_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM11_MASK               (0x00000F00U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM11_SHIFT              (8U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM11_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM11_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM12_MASK               (0x0000F000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM12_SHIFT              (12U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM12_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM12_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM13_MASK               (0x000F0000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM13_SHIFT              (16U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM13_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM13_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM14_MASK               (0x00F00000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM14_SHIFT              (20U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM14_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM14_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM15_MASK               (0x0F000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM15_SHIFT              (24U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM15_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_BINUM15_MAX                (0x0000000fU)

#define CSL_USB3SSDWC_GPRTBIMAP_FSHI_RESETVAL                   (0x00000000U)

#define CSL_USB3SSDWC_RESERVED_94_RESETVAL                      (0x00000000U)

#define CSL_USB3SSDWC_RESERVED_98_RESETVAL                      (0x00000000U)

/* GHWPARAMS8 */

#define CSL_USB3SSDWC_GHWPARAMS8_GHWPARAMS8_32_0_MASK           (0xFFFFFFFFU)
#define CSL_USB3SSDWC_GHWPARAMS8_GHWPARAMS8_32_0_SHIFT          (0U)
#define CSL_USB3SSDWC_GHWPARAMS8_GHWPARAMS8_32_0_RESETVAL       (0x00000970U)
#define CSL_USB3SSDWC_GHWPARAMS8_GHWPARAMS8_32_0_MAX            (0xffffffffU)

#define CSL_USB3SSDWC_GHWPARAMS8_RESETVAL                       (0x00000970U)

/* GTXFIFOPRIDEV */

#define CSL_USB3SSDWC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK          (0x0000FFFFU)
#define CSL_USB3SSDWC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_SHIFT         (0U)
#define CSL_USB3SSDWC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MAX           (0x0000ffffU)

#define CSL_USB3SSDWC_GTXFIFOPRIDEV_RESETVAL                    (0x00000000U)

/* GTXFIFOPRIHST */

#define CSL_USB3SSDWC_GTXFIFOPRIHST_GTXFIFOPRIHST_MASK          (0x0000000FU)
#define CSL_USB3SSDWC_GTXFIFOPRIHST_GTXFIFOPRIHST_SHIFT         (0U)
#define CSL_USB3SSDWC_GTXFIFOPRIHST_GTXFIFOPRIHST_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GTXFIFOPRIHST_GTXFIFOPRIHST_MAX           (0x0000000fU)

#define CSL_USB3SSDWC_GTXFIFOPRIHST_RESETVAL                    (0x00000000U)

/* GRXFIFOPRIHST */

#define CSL_USB3SSDWC_GRXFIFOPRIHST_GRXFIFOPRIHST_MASK          (0x00000007U)
#define CSL_USB3SSDWC_GRXFIFOPRIHST_GRXFIFOPRIHST_SHIFT         (0U)
#define CSL_USB3SSDWC_GRXFIFOPRIHST_GRXFIFOPRIHST_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_GRXFIFOPRIHST_GRXFIFOPRIHST_MAX           (0x00000007U)

#define CSL_USB3SSDWC_GRXFIFOPRIHST_RESETVAL                    (0x00000000U)

/* GFIFOPRIDBC */

#define CSL_USB3SSDWC_GFIFOPRIDBC_GFIFOPRIDBC_MASK              (0x00000003U)
#define CSL_USB3SSDWC_GFIFOPRIDBC_GFIFOPRIDBC_SHIFT             (0U)
#define CSL_USB3SSDWC_GFIFOPRIDBC_GFIFOPRIDBC_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_GFIFOPRIDBC_GFIFOPRIDBC_MAX               (0x00000003U)

#define CSL_USB3SSDWC_GFIFOPRIDBC_RESETVAL                      (0x00000000U)

/* GDMAHLRATIO */

#define CSL_USB3SSDWC_GDMAHLRATIO_HSTTXFIFO_MASK                (0x0000001FU)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTTXFIFO_SHIFT               (0U)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTTXFIFO_RESETVAL            (0x00000004U)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTTXFIFO_MAX                 (0x0000001fU)

#define CSL_USB3SSDWC_GDMAHLRATIO_HSTRXFIFO_MASK                (0x00001F00U)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTRXFIFO_SHIFT               (8U)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTRXFIFO_RESETVAL            (0x00000004U)
#define CSL_USB3SSDWC_GDMAHLRATIO_HSTRXFIFO_MAX                 (0x0000001fU)

#define CSL_USB3SSDWC_GDMAHLRATIO_RESETVAL                      (0x00000404U)

/* GFLADJ */

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_MASK                  (0x0000003FU)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_SHIFT                 (0U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_MAX                   (0x0000003fU)

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MASK        (0x00000080U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_SHIFT       (7U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_RESETVAL    (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MAX         (0x00000001U)

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK           (0x003FFF00U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_FLADJ_SHIFT          (8U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_FLADJ_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_FLADJ_MAX            (0x00003fffU)

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MASK         (0x00800000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_SHIFT        (23U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MAX          (0x00000001U)

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MASK     (0x7F000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_SHIFT    (24U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_RESETVAL  (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MAX      (0x0000007fU)

#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MASK  (0x80000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_SHIFT  (31U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_RESETVAL  (0x00000000U)
#define CSL_USB3SSDWC_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MAX  (0x00000001U)

#define CSL_USB3SSDWC_GFLADJ_RESETVAL                           (0x00000000U)

/* DCFG */

#define CSL_USB3SSDWC_DCFG_DEVSPD_MASK                          (0x00000007U)
#define CSL_USB3SSDWC_DCFG_DEVSPD_SHIFT                         (0U)
#define CSL_USB3SSDWC_DCFG_DEVSPD_RESETVAL                      (0x00000004U)
#define CSL_USB3SSDWC_DCFG_DEVSPD_MAX                           (0x00000007U)

#define CSL_USB3SSDWC_DCFG_DEVADDR_MASK                         (0x000003F8U)
#define CSL_USB3SSDWC_DCFG_DEVADDR_SHIFT                        (3U)
#define CSL_USB3SSDWC_DCFG_DEVADDR_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCFG_DEVADDR_MAX                          (0x0000007fU)

#define CSL_USB3SSDWC_DCFG_PERFRINT_MASK                        (0x00000C00U)
#define CSL_USB3SSDWC_DCFG_PERFRINT_SHIFT                       (10U)
#define CSL_USB3SSDWC_DCFG_PERFRINT_RESETVAL                    (0x00000002U)
#define CSL_USB3SSDWC_DCFG_PERFRINT_MAX                         (0x00000003U)

#define CSL_USB3SSDWC_DCFG_INTRNUM_MASK                         (0x0001F000U)
#define CSL_USB3SSDWC_DCFG_INTRNUM_SHIFT                        (12U)
#define CSL_USB3SSDWC_DCFG_INTRNUM_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCFG_INTRNUM_MAX                          (0x0000001fU)

#define CSL_USB3SSDWC_DCFG_NUMP_MASK                            (0x003E0000U)
#define CSL_USB3SSDWC_DCFG_NUMP_SHIFT                           (17U)
#define CSL_USB3SSDWC_DCFG_NUMP_RESETVAL                        (0x00000004U)
#define CSL_USB3SSDWC_DCFG_NUMP_MAX                             (0x0000001fU)

#define CSL_USB3SSDWC_DCFG_LPMCAP_MASK                          (0x00400000U)
#define CSL_USB3SSDWC_DCFG_LPMCAP_SHIFT                         (22U)
#define CSL_USB3SSDWC_DCFG_LPMCAP_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_DCFG_LPMCAP_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_DCFG_IGNSTRMPP_MASK                       (0x00800000U)
#define CSL_USB3SSDWC_DCFG_IGNSTRMPP_SHIFT                      (23U)
#define CSL_USB3SSDWC_DCFG_IGNSTRMPP_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_DCFG_IGNSTRMPP_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_DCFG_RESETVAL                             (0x00080804U)

/* DCTL */

#define CSL_USB3SSDWC_DCTL_TSTCTL_MASK                          (0x0000001EU)
#define CSL_USB3SSDWC_DCTL_TSTCTL_SHIFT                         (1U)
#define CSL_USB3SSDWC_DCTL_TSTCTL_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_DCTL_TSTCTL_MAX                           (0x0000000fU)

#define CSL_USB3SSDWC_DCTL_ULSTCHNGREQ_MASK                     (0x000001E0U)
#define CSL_USB3SSDWC_DCTL_ULSTCHNGREQ_SHIFT                    (5U)
#define CSL_USB3SSDWC_DCTL_ULSTCHNGREQ_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DCTL_ULSTCHNGREQ_MAX                      (0x0000000fU)

#define CSL_USB3SSDWC_DCTL_ACCEPTU1ENA_MASK                     (0x00000200U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU1ENA_SHIFT                    (9U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU1ENA_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU1ENA_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DCTL_INITU1ENA_MASK                       (0x00000400U)
#define CSL_USB3SSDWC_DCTL_INITU1ENA_SHIFT                      (10U)
#define CSL_USB3SSDWC_DCTL_INITU1ENA_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_DCTL_INITU1ENA_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_DCTL_ACCEPTU2ENA_MASK                     (0x00000800U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU2ENA_SHIFT                    (11U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU2ENA_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DCTL_ACCEPTU2ENA_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DCTL_INITU2ENA_MASK                       (0x00001000U)
#define CSL_USB3SSDWC_DCTL_INITU2ENA_SHIFT                      (12U)
#define CSL_USB3SSDWC_DCTL_INITU2ENA_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_DCTL_INITU2ENA_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_DCTL_CSS_MASK                             (0x00010000U)
#define CSL_USB3SSDWC_DCTL_CSS_SHIFT                            (16U)
#define CSL_USB3SSDWC_DCTL_CSS_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DCTL_CSS_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DCTL_CRS_MASK                             (0x00020000U)
#define CSL_USB3SSDWC_DCTL_CRS_SHIFT                            (17U)
#define CSL_USB3SSDWC_DCTL_CRS_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DCTL_CRS_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DCTL_LPM_NYET_THRES_MASK                  (0x00F00000U)
#define CSL_USB3SSDWC_DCTL_LPM_NYET_THRES_SHIFT                 (20U)
#define CSL_USB3SSDWC_DCTL_LPM_NYET_THRES_RESETVAL              (0x0000000fU)
#define CSL_USB3SSDWC_DCTL_LPM_NYET_THRES_MAX                   (0x0000000fU)

#define CSL_USB3SSDWC_DCTL_HIRDTHRES_MASK                       (0x1F000000U)
#define CSL_USB3SSDWC_DCTL_HIRDTHRES_SHIFT                      (24U)
#define CSL_USB3SSDWC_DCTL_HIRDTHRES_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_DCTL_HIRDTHRES_MAX                        (0x0000001fU)

#define CSL_USB3SSDWC_DCTL_CSFTRST_MASK                         (0x40000000U)
#define CSL_USB3SSDWC_DCTL_CSFTRST_SHIFT                        (30U)
#define CSL_USB3SSDWC_DCTL_CSFTRST_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCTL_CSFTRST_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCTL_RUN_STOP_MASK                        (0x80000000U)
#define CSL_USB3SSDWC_DCTL_RUN_STOP_SHIFT                       (31U)
#define CSL_USB3SSDWC_DCTL_RUN_STOP_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DCTL_RUN_STOP_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_DCTL_RESETVAL                             (0x00f00000U)

/* DEVTEN */

#define CSL_USB3SSDWC_DEVTEN_DISSCONNEVTEN_MASK                 (0x00000001U)
#define CSL_USB3SSDWC_DEVTEN_DISSCONNEVTEN_SHIFT                (0U)
#define CSL_USB3SSDWC_DEVTEN_DISSCONNEVTEN_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_DISSCONNEVTEN_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_USBRSTEVTEN_MASK                   (0x00000002U)
#define CSL_USB3SSDWC_DEVTEN_USBRSTEVTEN_SHIFT                  (1U)
#define CSL_USB3SSDWC_DEVTEN_USBRSTEVTEN_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_USBRSTEVTEN_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_CONNECTDONEEVTEN_MASK              (0x00000004U)
#define CSL_USB3SSDWC_DEVTEN_CONNECTDONEEVTEN_SHIFT             (2U)
#define CSL_USB3SSDWC_DEVTEN_CONNECTDONEEVTEN_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_CONNECTDONEEVTEN_MAX               (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_ULSTCNGEN_MASK                     (0x00000008U)
#define CSL_USB3SSDWC_DEVTEN_ULSTCNGEN_SHIFT                    (3U)
#define CSL_USB3SSDWC_DEVTEN_ULSTCNGEN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_ULSTCNGEN_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_WKUPEVTEN_MASK                     (0x00000010U)
#define CSL_USB3SSDWC_DEVTEN_WKUPEVTEN_SHIFT                    (4U)
#define CSL_USB3SSDWC_DEVTEN_WKUPEVTEN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_WKUPEVTEN_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_HIBERNATIONREQEVTEN_MASK           (0x00000020U)
#define CSL_USB3SSDWC_DEVTEN_HIBERNATIONREQEVTEN_SHIFT          (5U)
#define CSL_USB3SSDWC_DEVTEN_HIBERNATIONREQEVTEN_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_HIBERNATIONREQEVTEN_MAX            (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_U3L2L1SUSPEN_MASK                  (0x00000040U)
#define CSL_USB3SSDWC_DEVTEN_U3L2L1SUSPEN_SHIFT                 (6U)
#define CSL_USB3SSDWC_DEVTEN_U3L2L1SUSPEN_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_U3L2L1SUSPEN_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_SOFTEVTEN_MASK                     (0x00000080U)
#define CSL_USB3SSDWC_DEVTEN_SOFTEVTEN_SHIFT                    (7U)
#define CSL_USB3SSDWC_DEVTEN_SOFTEVTEN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_SOFTEVTEN_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_ERRTICERREVTEN_MASK                (0x00000200U)
#define CSL_USB3SSDWC_DEVTEN_ERRTICERREVTEN_SHIFT               (9U)
#define CSL_USB3SSDWC_DEVTEN_ERRTICERREVTEN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_ERRTICERREVTEN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_VENDEVTSTRCVDEN_MASK               (0x00001000U)
#define CSL_USB3SSDWC_DEVTEN_VENDEVTSTRCVDEN_SHIFT              (12U)
#define CSL_USB3SSDWC_DEVTEN_VENDEVTSTRCVDEN_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_DEVTEN_VENDEVTSTRCVDEN_MAX                (0x00000001U)

#define CSL_USB3SSDWC_DEVTEN_RESETVAL                           (0x00000000U)

/* DSTS */

#define CSL_USB3SSDWC_DSTS_CONNECTSPD_MASK                      (0x00000007U)
#define CSL_USB3SSDWC_DSTS_CONNECTSPD_SHIFT                     (0U)
#define CSL_USB3SSDWC_DSTS_CONNECTSPD_RESETVAL                  (0x00000004U)
#define CSL_USB3SSDWC_DSTS_CONNECTSPD_MAX                       (0x00000007U)

#define CSL_USB3SSDWC_DSTS_SOFFN_MASK                           (0x0001FFF8U)
#define CSL_USB3SSDWC_DSTS_SOFFN_SHIFT                          (3U)
#define CSL_USB3SSDWC_DSTS_SOFFN_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DSTS_SOFFN_MAX                            (0x00003fffU)

#define CSL_USB3SSDWC_DSTS_RXFIFOEMPTY_MASK                     (0x00020000U)
#define CSL_USB3SSDWC_DSTS_RXFIFOEMPTY_SHIFT                    (17U)
#define CSL_USB3SSDWC_DSTS_RXFIFOEMPTY_RESETVAL                 (0x00000001U)
#define CSL_USB3SSDWC_DSTS_RXFIFOEMPTY_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_DSTS_USBLNKST_MASK                        (0x003C0000U)
#define CSL_USB3SSDWC_DSTS_USBLNKST_SHIFT                       (18U)
#define CSL_USB3SSDWC_DSTS_USBLNKST_RESETVAL                    (0x00000004U)
#define CSL_USB3SSDWC_DSTS_USBLNKST_MAX                         (0x0000000fU)

#define CSL_USB3SSDWC_DSTS_DEVCTRLHLT_MASK                      (0x00400000U)
#define CSL_USB3SSDWC_DSTS_DEVCTRLHLT_SHIFT                     (22U)
#define CSL_USB3SSDWC_DSTS_DEVCTRLHLT_RESETVAL                  (0x00000001U)
#define CSL_USB3SSDWC_DSTS_DEVCTRLHLT_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_DSTS_COREIDLE_MASK                        (0x00800000U)
#define CSL_USB3SSDWC_DSTS_COREIDLE_SHIFT                       (23U)
#define CSL_USB3SSDWC_DSTS_COREIDLE_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DSTS_COREIDLE_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_DSTS_SSS_MASK                             (0x01000000U)
#define CSL_USB3SSDWC_DSTS_SSS_SHIFT                            (24U)
#define CSL_USB3SSDWC_DSTS_SSS_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DSTS_SSS_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DSTS_RSS_MASK                             (0x02000000U)
#define CSL_USB3SSDWC_DSTS_RSS_SHIFT                            (25U)
#define CSL_USB3SSDWC_DSTS_RSS_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DSTS_RSS_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DSTS_CSC_MASK                             (0x04000000U)
#define CSL_USB3SSDWC_DSTS_CSC_SHIFT                            (26U)
#define CSL_USB3SSDWC_DSTS_CSC_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DSTS_CSC_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DSTS_PLC_MASK                             (0x08000000U)
#define CSL_USB3SSDWC_DSTS_PLC_SHIFT                            (27U)
#define CSL_USB3SSDWC_DSTS_PLC_RESETVAL                         (0x00000000U)
#define CSL_USB3SSDWC_DSTS_PLC_MAX                              (0x00000001U)

#define CSL_USB3SSDWC_DSTS_DCNRD_MASK                           (0x20000000U)
#define CSL_USB3SSDWC_DSTS_DCNRD_SHIFT                          (29U)
#define CSL_USB3SSDWC_DSTS_DCNRD_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DSTS_DCNRD_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DSTS_RESETVAL                             (0x00520004U)

/* DGCMDPAR */

#define CSL_USB3SSDWC_DGCMDPAR_PARAMETER_MASK                   (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DGCMDPAR_PARAMETER_SHIFT                  (0U)
#define CSL_USB3SSDWC_DGCMDPAR_PARAMETER_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_DGCMDPAR_PARAMETER_MAX                    (0xffffffffU)

#define CSL_USB3SSDWC_DGCMDPAR_RESETVAL                         (0x00000000U)

/* DGCMD */

#define CSL_USB3SSDWC_DGCMD_CMDTYP_MASK                         (0x000000FFU)
#define CSL_USB3SSDWC_DGCMD_CMDTYP_SHIFT                        (0U)
#define CSL_USB3SSDWC_DGCMD_CMDTYP_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DGCMD_CMDTYP_MAX                          (0x000000ffU)

#define CSL_USB3SSDWC_DGCMD_CMDIOC_MASK                         (0x00000100U)
#define CSL_USB3SSDWC_DGCMD_CMDIOC_SHIFT                        (8U)
#define CSL_USB3SSDWC_DGCMD_CMDIOC_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DGCMD_CMDIOC_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DGCMD_CMDACT_MASK                         (0x00000400U)
#define CSL_USB3SSDWC_DGCMD_CMDACT_SHIFT                        (10U)
#define CSL_USB3SSDWC_DGCMD_CMDACT_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DGCMD_CMDACT_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DGCMD_CMDSTATUS_MASK                      (0x0000F000U)
#define CSL_USB3SSDWC_DGCMD_CMDSTATUS_SHIFT                     (12U)
#define CSL_USB3SSDWC_DGCMD_CMDSTATUS_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_DGCMD_CMDSTATUS_MAX                       (0x0000000fU)

#define CSL_USB3SSDWC_DGCMD_RESETVAL                            (0x00000000U)

/* DALEPENA */

#define CSL_USB3SSDWC_DALEPENA_USBACTEP_MASK                    (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DALEPENA_USBACTEP_SHIFT                   (0U)
#define CSL_USB3SSDWC_DALEPENA_USBACTEP_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_DALEPENA_USBACTEP_MAX                     (0xffffffffU)

#define CSL_USB3SSDWC_DALEPENA_RESETVAL                         (0x00000000U)

/* OCFG */

#define CSL_USB3SSDWC_OCFG_SRPCAP_MASK                          (0x00000001U)
#define CSL_USB3SSDWC_OCFG_SRPCAP_SHIFT                         (0U)
#define CSL_USB3SSDWC_OCFG_SRPCAP_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_OCFG_SRPCAP_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_OCFG_HNPCAP_MASK                          (0x00000002U)
#define CSL_USB3SSDWC_OCFG_HNPCAP_SHIFT                         (1U)
#define CSL_USB3SSDWC_OCFG_HNPCAP_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_OCFG_HNPCAP_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_OCFG_OTG_VERSION_MASK                     (0x00000004U)
#define CSL_USB3SSDWC_OCFG_OTG_VERSION_SHIFT                    (2U)
#define CSL_USB3SSDWC_OCFG_OTG_VERSION_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_OCFG_OTG_VERSION_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_OCFG_OTGSFTRSTMSK_MASK                    (0x00000008U)
#define CSL_USB3SSDWC_OCFG_OTGSFTRSTMSK_SHIFT                   (3U)
#define CSL_USB3SSDWC_OCFG_OTGSFTRSTMSK_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_OCFG_OTGSFTRSTMSK_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_OCFG_OTGHIBDISMASK_MASK                   (0x00000010U)
#define CSL_USB3SSDWC_OCFG_OTGHIBDISMASK_SHIFT                  (4U)
#define CSL_USB3SSDWC_OCFG_OTGHIBDISMASK_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_OCFG_OTGHIBDISMASK_MAX                    (0x00000001U)

#define CSL_USB3SSDWC_OCFG_DISPRTPWRCUTOFF_MASK                 (0x00000020U)
#define CSL_USB3SSDWC_OCFG_DISPRTPWRCUTOFF_SHIFT                (5U)
#define CSL_USB3SSDWC_OCFG_DISPRTPWRCUTOFF_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_OCFG_DISPRTPWRCUTOFF_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_OCFG_RESETVAL                             (0x00000000U)

/* OCTL */

#define CSL_USB3SSDWC_OCTL_HSTSETHNPEN_MASK                     (0x00000001U)
#define CSL_USB3SSDWC_OCTL_HSTSETHNPEN_SHIFT                    (0U)
#define CSL_USB3SSDWC_OCTL_HSTSETHNPEN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_OCTL_HSTSETHNPEN_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_OCTL_DEVSETHNPEN_MASK                     (0x00000002U)
#define CSL_USB3SSDWC_OCTL_DEVSETHNPEN_SHIFT                    (1U)
#define CSL_USB3SSDWC_OCTL_DEVSETHNPEN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_OCTL_DEVSETHNPEN_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_OCTL_TERMSELDLPULSE_MASK                  (0x00000004U)
#define CSL_USB3SSDWC_OCTL_TERMSELDLPULSE_SHIFT                 (2U)
#define CSL_USB3SSDWC_OCTL_TERMSELDLPULSE_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_OCTL_TERMSELDLPULSE_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_OCTL_SESREQ_MASK                          (0x00000008U)
#define CSL_USB3SSDWC_OCTL_SESREQ_SHIFT                         (3U)
#define CSL_USB3SSDWC_OCTL_SESREQ_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_OCTL_SESREQ_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_OCTL_HNPREQ_MASK                          (0x00000010U)
#define CSL_USB3SSDWC_OCTL_HNPREQ_SHIFT                         (4U)
#define CSL_USB3SSDWC_OCTL_HNPREQ_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_OCTL_HNPREQ_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_OCTL_PRTPWRCTL_MASK                       (0x00000020U)
#define CSL_USB3SSDWC_OCTL_PRTPWRCTL_SHIFT                      (5U)
#define CSL_USB3SSDWC_OCTL_PRTPWRCTL_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_OCTL_PRTPWRCTL_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_OCTL_PERIMODE_MASK                        (0x00000040U)
#define CSL_USB3SSDWC_OCTL_PERIMODE_SHIFT                       (6U)
#define CSL_USB3SSDWC_OCTL_PERIMODE_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_OCTL_PERIMODE_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_OCTL_OTG3_GOERR_MASK                      (0x00000080U)
#define CSL_USB3SSDWC_OCTL_OTG3_GOERR_SHIFT                     (7U)
#define CSL_USB3SSDWC_OCTL_OTG3_GOERR_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_OCTL_OTG3_GOERR_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_OCTL_RESETVAL                             (0x00000040U)

/* OEVT */

#define CSL_USB3SSDWC_OEVT_OEVTERROR_MASK                       (0x00000001U)
#define CSL_USB3SSDWC_OEVT_OEVTERROR_SHIFT                      (0U)
#define CSL_USB3SSDWC_OEVT_OEVTERROR_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OEVTERROR_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_OEVT_SESREQSTS_MASK                       (0x00000002U)
#define CSL_USB3SSDWC_OEVT_SESREQSTS_SHIFT                      (1U)
#define CSL_USB3SSDWC_OEVT_SESREQSTS_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_OEVT_SESREQSTS_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_OEVT_HSTNEGSTS_MASK                       (0x00000004U)
#define CSL_USB3SSDWC_OEVT_HSTNEGSTS_SHIFT                      (2U)
#define CSL_USB3SSDWC_OEVT_HSTNEGSTS_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_OEVT_HSTNEGSTS_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_OEVT_BSESVLD_MASK                         (0x00000008U)
#define CSL_USB3SSDWC_OEVT_BSESVLD_SHIFT                        (3U)
#define CSL_USB3SSDWC_OEVT_BSESVLD_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_OEVT_BSESVLD_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGBDEVVBUSCHNGEVNT_MASK             (0x00000100U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVVBUSCHNGEVNT_SHIFT            (8U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVVBUSCHNGEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVVBUSCHNGEVNT_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGBDEVSESSVLDDETEVNT_MASK           (0x00000200U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVSESSVLDDETEVNT_SHIFT          (9U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVSESSVLDDETEVNT_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVSESSVLDDETEVNT_MAX            (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGBDEVHNPCHNGEVNT_MASK              (0x00000400U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVHNPCHNGEVNT_SHIFT             (10U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVHNPCHNGEVNT_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVHNPCHNGEVNT_MAX               (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGBDEVBHOSTENDEVNT_MASK             (0x00000800U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVBHOSTENDEVNT_SHIFT            (11U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVBHOSTENDEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGBDEVBHOSTENDEVNT_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVSESSENDDETEVNT_MASK           (0x00010000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSESSENDDETEVNT_SHIFT          (16U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSESSENDDETEVNT_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSESSENDDETEVNT_MAX            (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVSRPDETEVNT_MASK               (0x00020000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSRPDETEVNT_SHIFT              (17U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSRPDETEVNT_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVSRPDETEVNT_MAX                (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVHNPCHNGEVNT_MASK              (0x00040000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHNPCHNGEVNT_SHIFT             (18U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHNPCHNGEVNT_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHNPCHNGEVNT_MAX               (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVHOSTEVNT_MASK                 (0x00080000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHOSTEVNT_SHIFT                (19U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHOSTEVNT_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVHOSTEVNT_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVBHOSTENDEVNT_MASK             (0x00100000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVBHOSTENDEVNT_SHIFT            (20U)
#define CSL_USB3SSDWC_OEVT_OTGADEVBHOSTENDEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVBHOSTENDEVNT_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGADEVIDLEEVNT_MASK                 (0x00200000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVIDLEEVNT_SHIFT                (21U)
#define CSL_USB3SSDWC_OEVT_OTGADEVIDLEEVNT_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGADEVIDLEEVNT_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_OEVT_HRRINITNOTIFEVNT_MASK                (0x00400000U)
#define CSL_USB3SSDWC_OEVT_HRRINITNOTIFEVNT_SHIFT               (22U)
#define CSL_USB3SSDWC_OEVT_HRRINITNOTIFEVNT_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_OEVT_HRRINITNOTIFEVNT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_OEVT_HRRCONFNOTIFEVNT_MASK                (0x00800000U)
#define CSL_USB3SSDWC_OEVT_HRRCONFNOTIFEVNT_SHIFT               (23U)
#define CSL_USB3SSDWC_OEVT_HRRCONFNOTIFEVNT_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_OEVT_HRRCONFNOTIFEVNT_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGCONIDSTSCHNGEVNT_MASK             (0x01000000U)
#define CSL_USB3SSDWC_OEVT_OTGCONIDSTSCHNGEVNT_SHIFT            (24U)
#define CSL_USB3SSDWC_OEVT_OTGCONIDSTSCHNGEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGCONIDSTSCHNGEVNT_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGHIBENTRYEVNT_MASK                 (0x02000000U)
#define CSL_USB3SSDWC_OEVT_OTGHIBENTRYEVNT_SHIFT                (25U)
#define CSL_USB3SSDWC_OEVT_OTGHIBENTRYEVNT_RESETVAL             (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGHIBENTRYEVNT_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGDEVRUNSTPSETEVNT_MASK             (0x04000000U)
#define CSL_USB3SSDWC_OEVT_OTGDEVRUNSTPSETEVNT_SHIFT            (26U)
#define CSL_USB3SSDWC_OEVT_OTGDEVRUNSTPSETEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGDEVRUNSTPSETEVNT_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVT_OTGXHCIRUNSTPSETEVNT_MASK            (0x08000000U)
#define CSL_USB3SSDWC_OEVT_OTGXHCIRUNSTPSETEVNT_SHIFT           (27U)
#define CSL_USB3SSDWC_OEVT_OTGXHCIRUNSTPSETEVNT_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_OEVT_OTGXHCIRUNSTPSETEVNT_MAX             (0x00000001U)

#define CSL_USB3SSDWC_OEVT_DEVICEMODE_MASK                      (0x80000000U)
#define CSL_USB3SSDWC_OEVT_DEVICEMODE_SHIFT                     (31U)
#define CSL_USB3SSDWC_OEVT_DEVICEMODE_RESETVAL                  (0x00000001U)
#define CSL_USB3SSDWC_OEVT_DEVICEMODE_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_OEVT_RESETVAL                             (0x80000000U)

/* OEVTEN */

#define CSL_USB3SSDWC_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MASK         (0x00000100U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_SHIFT        (8U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MAX          (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MASK       (0x00000200U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_SHIFT      (9U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_RESETVAL   (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MAX        (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MASK          (0x00000400U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVHNPCHNGEVNTEN_SHIFT         (10U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVHNPCHNGEVNTEN_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MAX           (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGBDEVBHOSTENDEVNTEN_MASK         (0x00000800U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVBHOSTENDEVNTEN_SHIFT        (11U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVBHOSTENDEVNTEN_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGBDEVBHOSTENDEVNTEN_MAX          (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVSESSENDDETEVNTEN_MASK       (0x00010000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSESSENDDETEVNTEN_SHIFT      (16U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSESSENDDETEVNTEN_RESETVAL   (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSESSENDDETEVNTEN_MAX        (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVSRPDETEVNTEN_MASK           (0x00020000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSRPDETEVNTEN_SHIFT          (17U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSRPDETEVNTEN_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVSRPDETEVNTEN_MAX            (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVHNPCHNGEVNTEN_MASK          (0x00040000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHNPCHNGEVNTEN_SHIFT         (18U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHNPCHNGEVNTEN_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHNPCHNGEVNTEN_MAX           (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVHOSTEVNTEN_MASK             (0x00080000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHOSTEVNTEN_SHIFT            (19U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHOSTEVNTEN_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVHOSTEVNTEN_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVBHOSTENDEVNTEN_MASK         (0x00100000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVBHOSTENDEVNTEN_SHIFT        (20U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVBHOSTENDEVNTEN_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVBHOSTENDEVNTEN_MAX          (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGADEVIDLEEVNTEN_MASK             (0x00200000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVIDLEEVNTEN_SHIFT            (21U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVIDLEEVNTEN_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGADEVIDLEEVNTEN_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_HRRINITNOTIFEVNTEN_MASK            (0x00400000U)
#define CSL_USB3SSDWC_OEVTEN_HRRINITNOTIFEVNTEN_SHIFT           (22U)
#define CSL_USB3SSDWC_OEVTEN_HRRINITNOTIFEVNTEN_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_HRRINITNOTIFEVNTEN_MAX             (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_HRRCONFNOTIFEVNTEN_MASK            (0x00800000U)
#define CSL_USB3SSDWC_OEVTEN_HRRCONFNOTIFEVNTEN_SHIFT           (23U)
#define CSL_USB3SSDWC_OEVTEN_HRRCONFNOTIFEVNTEN_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_HRRCONFNOTIFEVNTEN_MAX             (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MASK         (0x01000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGCONIDSTSCHNGEVNTEN_SHIFT        (24U)
#define CSL_USB3SSDWC_OEVTEN_OTGCONIDSTSCHNGEVNTEN_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MAX          (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGHIBENTRYEVNTEN_MASK             (0x02000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGHIBENTRYEVNTEN_SHIFT            (25U)
#define CSL_USB3SSDWC_OEVTEN_OTGHIBENTRYEVNTEN_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGHIBENTRYEVNTEN_MAX              (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGDEVRUNSTPSETEVNTEN_MASK         (0x04000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGDEVRUNSTPSETEVNTEN_SHIFT        (26U)
#define CSL_USB3SSDWC_OEVTEN_OTGDEVRUNSTPSETEVNTEN_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGDEVRUNSTPSETEVNTEN_MAX          (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_MASK        (0x08000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_SHIFT       (27U)
#define CSL_USB3SSDWC_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_RESETVAL    (0x00000000U)
#define CSL_USB3SSDWC_OEVTEN_OTGXHCIRUNSTPSETEVNTEN_MAX         (0x00000001U)

#define CSL_USB3SSDWC_OEVTEN_RESETVAL                           (0x00000000U)

/* OSTS */

#define CSL_USB3SSDWC_OSTS_CONIDSTS_MASK                        (0x00000001U)
#define CSL_USB3SSDWC_OSTS_CONIDSTS_SHIFT                       (0U)
#define CSL_USB3SSDWC_OSTS_CONIDSTS_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_OSTS_CONIDSTS_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_OSTS_ASESVLD_MASK                         (0x00000002U)
#define CSL_USB3SSDWC_OSTS_ASESVLD_SHIFT                        (1U)
#define CSL_USB3SSDWC_OSTS_ASESVLD_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_OSTS_ASESVLD_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_OSTS_BSESVLD_MASK                         (0x00000004U)
#define CSL_USB3SSDWC_OSTS_BSESVLD_SHIFT                        (2U)
#define CSL_USB3SSDWC_OSTS_BSESVLD_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_OSTS_BSESVLD_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_OSTS_XHCIPRTPOWER_MASK                    (0x00000008U)
#define CSL_USB3SSDWC_OSTS_XHCIPRTPOWER_SHIFT                   (3U)
#define CSL_USB3SSDWC_OSTS_XHCIPRTPOWER_RESETVAL                (0x00000001U)
#define CSL_USB3SSDWC_OSTS_XHCIPRTPOWER_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_OSTS_PERIPHERALSTATE_MASK                 (0x00000010U)
#define CSL_USB3SSDWC_OSTS_PERIPHERALSTATE_SHIFT                (4U)
#define CSL_USB3SSDWC_OSTS_PERIPHERALSTATE_RESETVAL             (0x00000001U)
#define CSL_USB3SSDWC_OSTS_PERIPHERALSTATE_MAX                  (0x00000001U)

#define CSL_USB3SSDWC_OSTS_OTGSTATE_MASK                        (0x00000F00U)
#define CSL_USB3SSDWC_OSTS_OTGSTATE_SHIFT                       (8U)
#define CSL_USB3SSDWC_OSTS_OTGSTATE_RESETVAL                    (0x00000008U)
#define CSL_USB3SSDWC_OSTS_OTGSTATE_MAX                         (0x0000000fU)

#define CSL_USB3SSDWC_OSTS_XHCIRUNSTP_MASK                      (0x00001000U)
#define CSL_USB3SSDWC_OSTS_XHCIRUNSTP_SHIFT                     (12U)
#define CSL_USB3SSDWC_OSTS_XHCIRUNSTP_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_OSTS_XHCIRUNSTP_MAX                       (0x00000001U)

#define CSL_USB3SSDWC_OSTS_DEVRUNSTP_MASK                       (0x00002000U)
#define CSL_USB3SSDWC_OSTS_DEVRUNSTP_SHIFT                      (13U)
#define CSL_USB3SSDWC_OSTS_DEVRUNSTP_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_OSTS_DEVRUNSTP_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_OSTS_RESETVAL                             (0x00000819U)

/* ADPCFG */

#define CSL_USB3SSDWC_ADPCFG_PRBDSCHG_MASK                      (0x0C000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBDSCHG_SHIFT                     (26U)
#define CSL_USB3SSDWC_ADPCFG_PRBDSCHG_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBDSCHG_MAX                       (0x00000003U)

#define CSL_USB3SSDWC_ADPCFG_PRBDELTA_MASK                      (0x30000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBDELTA_SHIFT                     (28U)
#define CSL_USB3SSDWC_ADPCFG_PRBDELTA_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBDELTA_MAX                       (0x00000003U)

#define CSL_USB3SSDWC_ADPCFG_PRBPER_MASK                        (0xC0000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBPER_SHIFT                       (30U)
#define CSL_USB3SSDWC_ADPCFG_PRBPER_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_ADPCFG_PRBPER_MAX                         (0x00000003U)

#define CSL_USB3SSDWC_ADPCFG_RESETVAL                           (0x00000000U)

/* ADPCTL */

#define CSL_USB3SSDWC_ADPCTL_WB_MASK                            (0x01000000U)
#define CSL_USB3SSDWC_ADPCTL_WB_SHIFT                           (24U)
#define CSL_USB3SSDWC_ADPCTL_WB_RESETVAL                        (0x00000000U)
#define CSL_USB3SSDWC_ADPCTL_WB_MAX                             (0x00000001U)

#define CSL_USB3SSDWC_ADPCTL_ADPRES_MASK                        (0x02000000U)
#define CSL_USB3SSDWC_ADPCTL_ADPRES_SHIFT                       (25U)
#define CSL_USB3SSDWC_ADPCTL_ADPRES_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_ADPCTL_ADPRES_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_ADPCTL_ADPEN_MASK                         (0x04000000U)
#define CSL_USB3SSDWC_ADPCTL_ADPEN_SHIFT                        (26U)
#define CSL_USB3SSDWC_ADPCTL_ADPEN_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_ADPCTL_ADPEN_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_ADPCTL_ENASNS_MASK                        (0x08000000U)
#define CSL_USB3SSDWC_ADPCTL_ENASNS_SHIFT                       (27U)
#define CSL_USB3SSDWC_ADPCTL_ENASNS_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_ADPCTL_ENASNS_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_ADPCTL_ENAPRB_MASK                        (0x10000000U)
#define CSL_USB3SSDWC_ADPCTL_ENAPRB_SHIFT                       (28U)
#define CSL_USB3SSDWC_ADPCTL_ENAPRB_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_ADPCTL_ENAPRB_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_ADPCTL_RESETVAL                           (0x00000000U)

/* ADPEVT */

#define CSL_USB3SSDWC_ADPEVT_RTIM_MASK                          (0x0000FFFFU)
#define CSL_USB3SSDWC_ADPEVT_RTIM_SHIFT                         (0U)
#define CSL_USB3SSDWC_ADPEVT_RTIM_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_ADPEVT_RTIM_MAX                           (0x0000ffffU)

#define CSL_USB3SSDWC_ADPEVT_ADPRSTCMPLTEVNT_MASK               (0x02000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPRSTCMPLTEVNT_SHIFT              (25U)
#define CSL_USB3SSDWC_ADPEVT_ADPRSTCMPLTEVNT_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPRSTCMPLTEVNT_MAX                (0x00000001U)

#define CSL_USB3SSDWC_ADPEVT_ADPTMOUTEVNT_MASK                  (0x04000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPTMOUTEVNT_SHIFT                 (26U)
#define CSL_USB3SSDWC_ADPEVT_ADPTMOUTEVNT_RESETVAL              (0x00000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPTMOUTEVNT_MAX                   (0x00000001U)

#define CSL_USB3SSDWC_ADPEVT_ADPSNSEVNT_MASK                    (0x08000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPSNSEVNT_SHIFT                   (27U)
#define CSL_USB3SSDWC_ADPEVT_ADPSNSEVNT_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPSNSEVNT_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_ADPEVT_ADPPRBEVNT_MASK                    (0x10000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPPRBEVNT_SHIFT                   (28U)
#define CSL_USB3SSDWC_ADPEVT_ADPPRBEVNT_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_ADPEVT_ADPPRBEVNT_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_ADPEVT_RESETVAL                           (0x00000000U)

/* ADPEVTEN */

#define CSL_USB3SSDWC_ADPEVTEN_ADPRSTCMPLTEVNTEN_MASK           (0x02000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPRSTCMPLTEVNTEN_SHIFT          (25U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPRSTCMPLTEVNTEN_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPRSTCMPLTEVNTEN_MAX            (0x00000001U)

#define CSL_USB3SSDWC_ADPEVTEN_ADPTMOUTEVNTEN_MASK              (0x04000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPTMOUTEVNTEN_SHIFT             (26U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPTMOUTEVNTEN_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPTMOUTEVNTEN_MAX               (0x00000001U)

#define CSL_USB3SSDWC_ADPEVTEN_ADPSNSEVNTEN_MASK                (0x08000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPSNSEVNTEN_SHIFT               (27U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPSNSEVNTEN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPSNSEVNTEN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_ADPEVTEN_ADPPRBEVNTEN_MASK                (0x10000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPPRBEVNTEN_SHIFT               (28U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPPRBEVNTEN_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_ADPEVTEN_ADPPRBEVNTEN_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_ADPEVTEN_RESETVAL                         (0x00000000U)

/* BCFG */

#define CSL_USB3SSDWC_BCFG_CHIRP_EN_MASK                        (0x00000001U)
#define CSL_USB3SSDWC_BCFG_CHIRP_EN_SHIFT                       (0U)
#define CSL_USB3SSDWC_BCFG_CHIRP_EN_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_BCFG_CHIRP_EN_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_BCFG_IDDIG_SEL_MASK                       (0x00000002U)
#define CSL_USB3SSDWC_BCFG_IDDIG_SEL_SHIFT                      (1U)
#define CSL_USB3SSDWC_BCFG_IDDIG_SEL_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_BCFG_IDDIG_SEL_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_BCFG_RESETVAL                             (0x00000000U)

/* BCEVT */

#define CSL_USB3SSDWC_BCEVT_MULTVALIDBC_MASK                    (0x0000001FU)
#define CSL_USB3SSDWC_BCEVT_MULTVALIDBC_SHIFT                   (0U)
#define CSL_USB3SSDWC_BCEVT_MULTVALIDBC_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_BCEVT_MULTVALIDBC_MAX                     (0x0000001fU)

#define CSL_USB3SSDWC_BCEVT_MV_CHNGEVNT_MASK                    (0x01000000U)
#define CSL_USB3SSDWC_BCEVT_MV_CHNGEVNT_SHIFT                   (24U)
#define CSL_USB3SSDWC_BCEVT_MV_CHNGEVNT_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_BCEVT_MV_CHNGEVNT_MAX                     (0x00000001U)

#define CSL_USB3SSDWC_BCEVT_RESETVAL                            (0x00000000U)

/* BCEVTEN */

#define CSL_USB3SSDWC_BCEVTEN_MV_CHNGEVNTENA_MASK               (0x01000000U)
#define CSL_USB3SSDWC_BCEVTEN_MV_CHNGEVNTENA_SHIFT              (24U)
#define CSL_USB3SSDWC_BCEVTEN_MV_CHNGEVNTENA_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_BCEVTEN_MV_CHNGEVNTENA_MAX                (0x00000001U)

#define CSL_USB3SSDWC_BCEVTEN_RESETVAL                          (0x00000000U)

/* CAPLENGTH */

#define CSL_USB3SSDWC_CAPLENGTH_CAPLENGTH_MASK                  (0x000000FFU)
#define CSL_USB3SSDWC_CAPLENGTH_CAPLENGTH_SHIFT                 (0U)
#define CSL_USB3SSDWC_CAPLENGTH_CAPLENGTH_RESETVAL              (0x00000020U)
#define CSL_USB3SSDWC_CAPLENGTH_CAPLENGTH_MAX                   (0x000000ffU)

#define CSL_USB3SSDWC_CAPLENGTH_HCIVERSION_MASK                 (0xFFFF0000U)
#define CSL_USB3SSDWC_CAPLENGTH_HCIVERSION_SHIFT                (16U)
#define CSL_USB3SSDWC_CAPLENGTH_HCIVERSION_RESETVAL             (0x00000100U)
#define CSL_USB3SSDWC_CAPLENGTH_HCIVERSION_MAX                  (0x0000ffffU)

#define CSL_USB3SSDWC_CAPLENGTH_RESETVAL                        (0x01000020U)

/* HCSPARAMS1 */

#define CSL_USB3SSDWC_HCSPARAMS1_MAXSLOTS_MASK                  (0x000000FFU)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXSLOTS_SHIFT                 (0U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXSLOTS_RESETVAL              (0x00000040U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXSLOTS_MAX                   (0x000000ffU)

#define CSL_USB3SSDWC_HCSPARAMS1_MAXINTRS_MASK                  (0x0007FF00U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXINTRS_SHIFT                 (8U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXINTRS_RESETVAL              (0x00000010U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXINTRS_MAX                   (0x000007ffU)

#define CSL_USB3SSDWC_HCSPARAMS1_MAXPORTS_MASK                  (0xFF000000U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXPORTS_SHIFT                 (24U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXPORTS_RESETVAL              (0x00000002U)
#define CSL_USB3SSDWC_HCSPARAMS1_MAXPORTS_MAX                   (0x000000ffU)

#define CSL_USB3SSDWC_HCSPARAMS1_RESETVAL                       (0x02001040U)

/* HCSPARAMS2 */

#define CSL_USB3SSDWC_HCSPARAMS2_IST_MASK                       (0x0000000FU)
#define CSL_USB3SSDWC_HCSPARAMS2_IST_SHIFT                      (0U)
#define CSL_USB3SSDWC_HCSPARAMS2_IST_RESETVAL                   (0x00000001U)
#define CSL_USB3SSDWC_HCSPARAMS2_IST_MAX                        (0x0000000fU)

#define CSL_USB3SSDWC_HCSPARAMS2_ERSTMAX_MASK                   (0x000000F0U)
#define CSL_USB3SSDWC_HCSPARAMS2_ERSTMAX_SHIFT                  (4U)
#define CSL_USB3SSDWC_HCSPARAMS2_ERSTMAX_RESETVAL               (0x0000000fU)
#define CSL_USB3SSDWC_HCSPARAMS2_ERSTMAX_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK      (0x03E00000U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT     (21U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_RESETVAL  (0x00000000U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MAX       (0x0000001fU)

#define CSL_USB3SSDWC_HCSPARAMS2_SPR_MASK                       (0x04000000U)
#define CSL_USB3SSDWC_HCSPARAMS2_SPR_SHIFT                      (26U)
#define CSL_USB3SSDWC_HCSPARAMS2_SPR_RESETVAL                   (0x00000001U)
#define CSL_USB3SSDWC_HCSPARAMS2_SPR_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_MASK         (0xF8000000U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_SHIFT        (27U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_RESETVAL     (0x00000002U)
#define CSL_USB3SSDWC_HCSPARAMS2_MAXSCRATCHPADBUFS_MAX          (0x0000001fU)

#define CSL_USB3SSDWC_HCSPARAMS2_RESETVAL                       (0x140000f1U)

/* HCSPARAMS3 */

#define CSL_USB3SSDWC_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK        (0x000000FFU)
#define CSL_USB3SSDWC_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT       (0U)
#define CSL_USB3SSDWC_HCSPARAMS3_U1_DEVICE_EXIT_LAT_RESETVAL    (0x0000000aU)
#define CSL_USB3SSDWC_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MAX         (0x000000ffU)

#define CSL_USB3SSDWC_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK        (0xFFFF0000U)
#define CSL_USB3SSDWC_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT       (16U)
#define CSL_USB3SSDWC_HCSPARAMS3_U2_DEVICE_EXIT_LAT_RESETVAL    (0x000007ffU)
#define CSL_USB3SSDWC_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MAX         (0x0000ffffU)

#define CSL_USB3SSDWC_HCSPARAMS3_RESETVAL                       (0x07ff000aU)

/* HCCPARAMS */

#define CSL_USB3SSDWC_HCCPARAMS_AC64_MASK                       (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_AC64_SHIFT                      (0U)
#define CSL_USB3SSDWC_HCCPARAMS_AC64_RESETVAL                   (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_AC64_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_BNC_MASK                        (0x00000002U)
#define CSL_USB3SSDWC_HCCPARAMS_BNC_SHIFT                       (1U)
#define CSL_USB3SSDWC_HCCPARAMS_BNC_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_HCCPARAMS_BNC_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_CSZ_MASK                        (0x00000004U)
#define CSL_USB3SSDWC_HCCPARAMS_CSZ_SHIFT                       (2U)
#define CSL_USB3SSDWC_HCCPARAMS_CSZ_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_CSZ_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_PPC_MASK                        (0x00000008U)
#define CSL_USB3SSDWC_HCCPARAMS_PPC_SHIFT                       (3U)
#define CSL_USB3SSDWC_HCCPARAMS_PPC_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_PPC_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_PIND_MASK                       (0x00000010U)
#define CSL_USB3SSDWC_HCCPARAMS_PIND_SHIFT                      (4U)
#define CSL_USB3SSDWC_HCCPARAMS_PIND_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_HCCPARAMS_PIND_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_LHRC_MASK                       (0x00000020U)
#define CSL_USB3SSDWC_HCCPARAMS_LHRC_SHIFT                      (5U)
#define CSL_USB3SSDWC_HCCPARAMS_LHRC_RESETVAL                   (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_LHRC_MAX                        (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_LTC_MASK                        (0x00000040U)
#define CSL_USB3SSDWC_HCCPARAMS_LTC_SHIFT                       (6U)
#define CSL_USB3SSDWC_HCCPARAMS_LTC_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_LTC_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_NSS_MASK                        (0x00000080U)
#define CSL_USB3SSDWC_HCCPARAMS_NSS_SHIFT                       (7U)
#define CSL_USB3SSDWC_HCCPARAMS_NSS_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_HCCPARAMS_NSS_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_PAE_MASK                        (0x00000100U)
#define CSL_USB3SSDWC_HCCPARAMS_PAE_SHIFT                       (8U)
#define CSL_USB3SSDWC_HCCPARAMS_PAE_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_HCCPARAMS_PAE_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_SPC_MASK                        (0x00000200U)
#define CSL_USB3SSDWC_HCCPARAMS_SPC_SHIFT                       (9U)
#define CSL_USB3SSDWC_HCCPARAMS_SPC_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_SPC_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_SEC_MASK                        (0x00000400U)
#define CSL_USB3SSDWC_HCCPARAMS_SEC_SHIFT                       (10U)
#define CSL_USB3SSDWC_HCCPARAMS_SEC_RESETVAL                    (0x00000001U)
#define CSL_USB3SSDWC_HCCPARAMS_SEC_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_HCCPARAMS_MAXPSASIZE_MASK                 (0x0000F000U)
#define CSL_USB3SSDWC_HCCPARAMS_MAXPSASIZE_SHIFT                (12U)
#define CSL_USB3SSDWC_HCCPARAMS_MAXPSASIZE_RESETVAL             (0x0000000fU)
#define CSL_USB3SSDWC_HCCPARAMS_MAXPSASIZE_MAX                  (0x0000000fU)

#define CSL_USB3SSDWC_HCCPARAMS_XECP_MASK                       (0xFFFF0000U)
#define CSL_USB3SSDWC_HCCPARAMS_XECP_SHIFT                      (16U)
#define CSL_USB3SSDWC_HCCPARAMS_XECP_RESETVAL                   (0x00000298U)
#define CSL_USB3SSDWC_HCCPARAMS_XECP_MAX                        (0x0000ffffU)

#define CSL_USB3SSDWC_HCCPARAMS_RESETVAL                        (0x0298f66dU)

/* DBOFF */

#define CSL_USB3SSDWC_DBOFF_DOORBELL_ARRAY_OFFSET_MASK          (0xFFFFFFFCU)
#define CSL_USB3SSDWC_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT         (2U)
#define CSL_USB3SSDWC_DBOFF_DOORBELL_ARRAY_OFFSET_RESETVAL      (0x00000198U)
#define CSL_USB3SSDWC_DBOFF_DOORBELL_ARRAY_OFFSET_MAX           (0x3fffffffU)

#define CSL_USB3SSDWC_DBOFF_RESETVAL                            (0x00000660U)

/* RTSOFF */

#define CSL_USB3SSDWC_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK      (0xFFFFFFE0U)
#define CSL_USB3SSDWC_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT     (5U)
#define CSL_USB3SSDWC_RTSOFF_RUNTIME_REG_SPACE_OFFSET_RESETVAL  (0x00000022U)
#define CSL_USB3SSDWC_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MAX       (0x07ffffffU)

#define CSL_USB3SSDWC_RTSOFF_RESETVAL                           (0x00000440U)

/* USBCMD */

#define CSL_USB3SSDWC_USBCMD_R_S_MASK                           (0x00000001U)
#define CSL_USB3SSDWC_USBCMD_R_S_SHIFT                          (0U)
#define CSL_USB3SSDWC_USBCMD_R_S_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_R_S_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_HCRST_MASK                         (0x00000002U)
#define CSL_USB3SSDWC_USBCMD_HCRST_SHIFT                        (1U)
#define CSL_USB3SSDWC_USBCMD_HCRST_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_HCRST_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_INTE_MASK                          (0x00000004U)
#define CSL_USB3SSDWC_USBCMD_INTE_SHIFT                         (2U)
#define CSL_USB3SSDWC_USBCMD_INTE_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_INTE_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_HSEE_MASK                          (0x00000008U)
#define CSL_USB3SSDWC_USBCMD_HSEE_SHIFT                         (3U)
#define CSL_USB3SSDWC_USBCMD_HSEE_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_HSEE_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_LHCRST_MASK                        (0x00000080U)
#define CSL_USB3SSDWC_USBCMD_LHCRST_SHIFT                       (7U)
#define CSL_USB3SSDWC_USBCMD_LHCRST_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_LHCRST_MAX                         (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_CSS_MASK                           (0x00000100U)
#define CSL_USB3SSDWC_USBCMD_CSS_SHIFT                          (8U)
#define CSL_USB3SSDWC_USBCMD_CSS_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_CSS_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_CRS_MASK                           (0x00000200U)
#define CSL_USB3SSDWC_USBCMD_CRS_SHIFT                          (9U)
#define CSL_USB3SSDWC_USBCMD_CRS_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_CRS_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_EWE_MASK                           (0x00000400U)
#define CSL_USB3SSDWC_USBCMD_EWE_SHIFT                          (10U)
#define CSL_USB3SSDWC_USBCMD_EWE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_EWE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_EU3S_MASK                          (0x00000800U)
#define CSL_USB3SSDWC_USBCMD_EU3S_SHIFT                         (11U)
#define CSL_USB3SSDWC_USBCMD_EU3S_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_EU3S_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_SPE_MASK                           (0x00001000U)
#define CSL_USB3SSDWC_USBCMD_SPE_SHIFT                          (12U)
#define CSL_USB3SSDWC_USBCMD_SPE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBCMD_SPE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBCMD_RESETVAL                           (0x00000000U)

/* USBSTS */

#define CSL_USB3SSDWC_USBSTS_HCH_MASK                           (0x00000001U)
#define CSL_USB3SSDWC_USBSTS_HCH_SHIFT                          (0U)
#define CSL_USB3SSDWC_USBSTS_HCH_RESETVAL                       (0x00000001U)
#define CSL_USB3SSDWC_USBSTS_HCH_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_HSE_MASK                           (0x00000004U)
#define CSL_USB3SSDWC_USBSTS_HSE_SHIFT                          (2U)
#define CSL_USB3SSDWC_USBSTS_HSE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_HSE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_EINT_MASK                          (0x00000008U)
#define CSL_USB3SSDWC_USBSTS_EINT_SHIFT                         (3U)
#define CSL_USB3SSDWC_USBSTS_EINT_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_EINT_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_PCD_MASK                           (0x00000010U)
#define CSL_USB3SSDWC_USBSTS_PCD_SHIFT                          (4U)
#define CSL_USB3SSDWC_USBSTS_PCD_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_PCD_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_SSS_MASK                           (0x00000100U)
#define CSL_USB3SSDWC_USBSTS_SSS_SHIFT                          (8U)
#define CSL_USB3SSDWC_USBSTS_SSS_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_SSS_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_RSS_MASK                           (0x00000200U)
#define CSL_USB3SSDWC_USBSTS_RSS_SHIFT                          (9U)
#define CSL_USB3SSDWC_USBSTS_RSS_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_RSS_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_SRE_MASK                           (0x00000400U)
#define CSL_USB3SSDWC_USBSTS_SRE_SHIFT                          (10U)
#define CSL_USB3SSDWC_USBSTS_SRE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_SRE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_CNR_MASK                           (0x00000800U)
#define CSL_USB3SSDWC_USBSTS_CNR_SHIFT                          (11U)
#define CSL_USB3SSDWC_USBSTS_CNR_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_CNR_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_HCE_MASK                           (0x00001000U)
#define CSL_USB3SSDWC_USBSTS_HCE_SHIFT                          (12U)
#define CSL_USB3SSDWC_USBSTS_HCE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_USBSTS_HCE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_USBSTS_RESETVAL                           (0x00000001U)

/* PAGESIZE */

#define CSL_USB3SSDWC_PAGESIZE_PAGE_SIZE_MASK                   (0x0000FFFFU)
#define CSL_USB3SSDWC_PAGESIZE_PAGE_SIZE_SHIFT                  (0U)
#define CSL_USB3SSDWC_PAGESIZE_PAGE_SIZE_RESETVAL               (0x00000001U)
#define CSL_USB3SSDWC_PAGESIZE_PAGE_SIZE_MAX                    (0x0000ffffU)

#define CSL_USB3SSDWC_PAGESIZE_RESETVAL                         (0x00000001U)

/* DNCTRL */

#define CSL_USB3SSDWC_DNCTRL_N0_N15_MASK                        (0x0000FFFFU)
#define CSL_USB3SSDWC_DNCTRL_N0_N15_SHIFT                       (0U)
#define CSL_USB3SSDWC_DNCTRL_N0_N15_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DNCTRL_N0_N15_MAX                         (0x0000ffffU)

#define CSL_USB3SSDWC_DNCTRL_RESETVAL                           (0x00000000U)

/* CRCR_LO */

#define CSL_USB3SSDWC_CRCR_LO_RCS_MASK                          (0x00000001U)
#define CSL_USB3SSDWC_CRCR_LO_RCS_SHIFT                         (0U)
#define CSL_USB3SSDWC_CRCR_LO_RCS_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_CRCR_LO_RCS_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_CRCR_LO_CS_MASK                           (0x00000002U)
#define CSL_USB3SSDWC_CRCR_LO_CS_SHIFT                          (1U)
#define CSL_USB3SSDWC_CRCR_LO_CS_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_CRCR_LO_CS_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_CRCR_LO_CA_MASK                           (0x00000004U)
#define CSL_USB3SSDWC_CRCR_LO_CA_SHIFT                          (2U)
#define CSL_USB3SSDWC_CRCR_LO_CA_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_CRCR_LO_CA_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_CRCR_LO_CRR_MASK                          (0x00000008U)
#define CSL_USB3SSDWC_CRCR_LO_CRR_SHIFT                         (3U)
#define CSL_USB3SSDWC_CRCR_LO_CRR_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_CRCR_LO_CRR_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_CRCR_LO_CMD_RING_PNTR_MASK                (0xFFFFFFC0U)
#define CSL_USB3SSDWC_CRCR_LO_CMD_RING_PNTR_SHIFT               (6U)
#define CSL_USB3SSDWC_CRCR_LO_CMD_RING_PNTR_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_CRCR_LO_CMD_RING_PNTR_MAX                 (0x03ffffffU)

#define CSL_USB3SSDWC_CRCR_LO_RESETVAL                          (0x00000000U)

/* CRCR_HI */

#define CSL_USB3SSDWC_CRCR_HI_CMD_RING_PNTR_MASK                (0xFFFFFFFFU)
#define CSL_USB3SSDWC_CRCR_HI_CMD_RING_PNTR_SHIFT               (0U)
#define CSL_USB3SSDWC_CRCR_HI_CMD_RING_PNTR_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_CRCR_HI_CMD_RING_PNTR_MAX                 (0xffffffffU)

#define CSL_USB3SSDWC_CRCR_HI_RESETVAL                          (0x00000000U)

/* DCBAAP_LO */

#define CSL_USB3SSDWC_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK        (0xFFFFFFC0U)
#define CSL_USB3SSDWC_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT       (6U)
#define CSL_USB3SSDWC_DCBAAP_LO_DEVICE_CONTEXT_BAAP_RESETVAL    (0x00000000U)
#define CSL_USB3SSDWC_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MAX         (0x03ffffffU)

#define CSL_USB3SSDWC_DCBAAP_LO_RESETVAL                        (0x00000000U)

/* DCBAAP_HI */

#define CSL_USB3SSDWC_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK        (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT       (0U)
#define CSL_USB3SSDWC_DCBAAP_HI_DEVICE_CONTEXT_BAAP_RESETVAL    (0x00000000U)
#define CSL_USB3SSDWC_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MAX         (0xffffffffU)

#define CSL_USB3SSDWC_DCBAAP_HI_RESETVAL                        (0x00000000U)

/* CONFIG */

#define CSL_USB3SSDWC_CONFIG_MAXSLOTSEN_MASK                    (0x000000FFU)
#define CSL_USB3SSDWC_CONFIG_MAXSLOTSEN_SHIFT                   (0U)
#define CSL_USB3SSDWC_CONFIG_MAXSLOTSEN_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_CONFIG_MAXSLOTSEN_MAX                     (0x000000ffU)

#define CSL_USB3SSDWC_CONFIG_RESETVAL                           (0x00000000U)

/* MFINDEX */

#define CSL_USB3SSDWC_MFINDEX_MICROFRAME_INDEX_MASK             (0x00003FFFU)
#define CSL_USB3SSDWC_MFINDEX_MICROFRAME_INDEX_SHIFT            (0U)
#define CSL_USB3SSDWC_MFINDEX_MICROFRAME_INDEX_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_MFINDEX_MICROFRAME_INDEX_MAX              (0x00003fffU)

#define CSL_USB3SSDWC_MFINDEX_RESETVAL                          (0x00000000U)

/* RSVDZ */

#define CSL_USB3SSDWC_RSVDZ_RESETVAL                            (0x00000000U)

/* USBLEGSUP */

#define CSL_USB3SSDWC_USBLEGSUP_CAPABILITY_ID_MASK              (0x000000FFU)
#define CSL_USB3SSDWC_USBLEGSUP_CAPABILITY_ID_SHIFT             (0U)
#define CSL_USB3SSDWC_USBLEGSUP_CAPABILITY_ID_RESETVAL          (0x00000001U)
#define CSL_USB3SSDWC_USBLEGSUP_CAPABILITY_ID_MAX               (0x000000ffU)

#define CSL_USB3SSDWC_USBLEGSUP_NEXT_CAPABILITY_POINTER_MASK    (0x0000FF00U)
#define CSL_USB3SSDWC_USBLEGSUP_NEXT_CAPABILITY_POINTER_SHIFT   (8U)
#define CSL_USB3SSDWC_USBLEGSUP_NEXT_CAPABILITY_POINTER_RESETVAL  (0x00000004U)
#define CSL_USB3SSDWC_USBLEGSUP_NEXT_CAPABILITY_POINTER_MAX     (0x000000ffU)

#define CSL_USB3SSDWC_USBLEGSUP_HC_BIOS_OWNED_MASK              (0x00010000U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_BIOS_OWNED_SHIFT             (16U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_BIOS_OWNED_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_BIOS_OWNED_MAX               (0x00000001U)

#define CSL_USB3SSDWC_USBLEGSUP_HC_OS_OWNED_MASK                (0x01000000U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_OS_OWNED_SHIFT               (24U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_OS_OWNED_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_USBLEGSUP_HC_OS_OWNED_MAX                 (0x00000001U)

#define CSL_USB3SSDWC_USBLEGSUP_RESETVAL                        (0x00000401U)

/* USBLEGCTLSTS */

#define CSL_USB3SSDWC_USBLEGCTLSTS_USB_SMI_ENABLE_MASK          (0x00000001U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_USB_SMI_ENABLE_SHIFT         (0U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_USB_SMI_ENABLE_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_USB_SMI_ENABLE_MAX           (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_E_MASK           (0x00000010U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_E_SHIFT          (4U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_E_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_E_MAX            (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_E_MASK             (0x00002000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_E_SHIFT            (13U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_E_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_E_MAX              (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_E_MASK            (0x00004000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_E_SHIFT           (14U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_E_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_E_MAX             (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_E_MASK            (0x00008000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_E_SHIFT           (15U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_E_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_E_MAX             (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_EVENT_MASK            (0x00010000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_EVENT_SHIFT           (16U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_EVENT_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_EVENT_MAX             (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_MASK             (0x00100000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_SHIFT            (20U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_RESETVAL         (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_HOST_MAX              (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_MASK               (0x20000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_SHIFT              (29U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_OS_MAX                (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_MASK              (0x40000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_SHIFT             (30U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_PCI_MAX               (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_MASK              (0x80000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_SHIFT             (31U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_USBLEGCTLSTS_SMI_ON_BAR_MAX               (0x00000001U)

#define CSL_USB3SSDWC_USBLEGCTLSTS_RESETVAL                     (0x00000000U)

/* SUPTPRT2_DW0 */

#define CSL_USB3SSDWC_SUPTPRT2_DW0_CAPABILITY_ID_MASK           (0x000000FFU)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_CAPABILITY_ID_SHIFT          (0U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_CAPABILITY_ID_RESETVAL       (0x00000002U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_CAPABILITY_ID_MAX            (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MASK  (0x0000FF00U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_SHIFT  (8U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_RESETVAL  (0x00000004U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MAX  (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW0_MINOR_REVISION_MASK          (0x00FF0000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MINOR_REVISION_SHIFT         (16U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MINOR_REVISION_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MINOR_REVISION_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW0_MAJOR_REVISION_MASK          (0xFF000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MAJOR_REVISION_SHIFT         (24U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MAJOR_REVISION_RESETVAL      (0x00000002U)
#define CSL_USB3SSDWC_SUPTPRT2_DW0_MAJOR_REVISION_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW0_RESETVAL                     (0x02000402U)

/* SUPTPRT2_DW1 */

#define CSL_USB3SSDWC_SUPTPRT2_DW1_NAME_STRING_MASK             (0xFFFFFFFFU)
#define CSL_USB3SSDWC_SUPTPRT2_DW1_NAME_STRING_SHIFT            (0U)
#define CSL_USB3SSDWC_SUPTPRT2_DW1_NAME_STRING_RESETVAL         (0x20425355U)
#define CSL_USB3SSDWC_SUPTPRT2_DW1_NAME_STRING_MAX              (0xffffffffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW1_RESETVAL                     (0x20425355U)

/* SUPTPRT2_DW2 */

#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MASK  (0x000000FFU)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_SHIFT  (0U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_RESETVAL  (0x00000001U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MAX   (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MASK   (0x0000FF00U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_SHIFT  (8U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_RESETVAL  (0x00000001U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MAX    (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_HSO_MASK                     (0x00020000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HSO_SHIFT                    (17U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HSO_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HSO_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_IHI_MASK                     (0x00040000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_IHI_SHIFT                    (18U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_IHI_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_IHI_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_HLC_MASK                     (0x00080000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HLC_SHIFT                    (19U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HLC_RESETVAL                 (0x00000001U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_HLC_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_BLC_MASK                     (0x00100000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_BLC_SHIFT                    (20U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_BLC_RESETVAL                 (0x00000001U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_BLC_MAX                      (0x00000001U)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_MHD_MASK                     (0x0E000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_MHD_SHIFT                    (25U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_MHD_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_MHD_MAX                      (0x00000007U)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_PSIC_MASK                    (0xF0000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_PSIC_SHIFT                   (28U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_PSIC_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW2_PSIC_MAX                     (0x0000000fU)

#define CSL_USB3SSDWC_SUPTPRT2_DW2_RESETVAL                     (0x00180101U)

/* SUPTPRT2_DW3 */

#define CSL_USB3SSDWC_SUPTPRT2_DW3_PROTCL_SLT_TY_MASK           (0x0000001FU)
#define CSL_USB3SSDWC_SUPTPRT2_DW3_PROTCL_SLT_TY_SHIFT          (0U)
#define CSL_USB3SSDWC_SUPTPRT2_DW3_PROTCL_SLT_TY_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT2_DW3_PROTCL_SLT_TY_MAX            (0x0000001fU)

#define CSL_USB3SSDWC_SUPTPRT2_DW3_RESETVAL                     (0x00000000U)

/* SUPTPRT3_DW0 */

#define CSL_USB3SSDWC_SUPTPRT3_DW0_CAPABILITY_ID_MASK           (0x000000FFU)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_CAPABILITY_ID_SHIFT          (0U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_CAPABILITY_ID_RESETVAL       (0x00000002U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_CAPABILITY_ID_MAX            (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MASK  (0x0000FF00U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_SHIFT  (8U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_RESETVAL  (0x00000004U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MAX  (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW0_MINOR_REVISION_MASK          (0x00FF0000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MINOR_REVISION_SHIFT         (16U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MINOR_REVISION_RESETVAL      (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MINOR_REVISION_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW0_MAJOR_REVISION_MASK          (0xFF000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MAJOR_REVISION_SHIFT         (24U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MAJOR_REVISION_RESETVAL      (0x00000003U)
#define CSL_USB3SSDWC_SUPTPRT3_DW0_MAJOR_REVISION_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW0_RESETVAL                     (0x03000402U)

/* SUPTPRT3_DW1 */

#define CSL_USB3SSDWC_SUPTPRT3_DW1_NAME_STRING_MASK             (0xFFFFFFFFU)
#define CSL_USB3SSDWC_SUPTPRT3_DW1_NAME_STRING_SHIFT            (0U)
#define CSL_USB3SSDWC_SUPTPRT3_DW1_NAME_STRING_RESETVAL         (0x20425355U)
#define CSL_USB3SSDWC_SUPTPRT3_DW1_NAME_STRING_MAX              (0xffffffffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW1_RESETVAL                     (0x20425355U)

/* SUPTPRT3_DW2 */

#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MASK  (0x000000FFU)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_SHIFT  (0U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_RESETVAL  (0x00000002U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MAX   (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MASK   (0x0000FF00U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_SHIFT  (8U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_RESETVAL  (0x00000001U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MAX    (0x000000ffU)

#define CSL_USB3SSDWC_SUPTPRT3_DW2_MHD_MASK                     (0x0E000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_MHD_SHIFT                    (25U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_MHD_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_MHD_MAX                      (0x00000007U)

#define CSL_USB3SSDWC_SUPTPRT3_DW2_PSIC_MASK                    (0xF0000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_PSIC_SHIFT                   (28U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_PSIC_RESETVAL                (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW2_PSIC_MAX                     (0x0000000fU)

#define CSL_USB3SSDWC_SUPTPRT3_DW2_RESETVAL                     (0x00000102U)

/* SUPTPRT3_DW3 */

#define CSL_USB3SSDWC_SUPTPRT3_DW3_PROTCL_SLT_TY_MASK           (0x0000001FU)
#define CSL_USB3SSDWC_SUPTPRT3_DW3_PROTCL_SLT_TY_SHIFT          (0U)
#define CSL_USB3SSDWC_SUPTPRT3_DW3_PROTCL_SLT_TY_RESETVAL       (0x00000000U)
#define CSL_USB3SSDWC_SUPTPRT3_DW3_PROTCL_SLT_TY_MAX            (0x0000001fU)

#define CSL_USB3SSDWC_SUPTPRT3_DW3_RESETVAL                     (0x00000000U)

/* DCID */

#define CSL_USB3SSDWC_DCID_CAPABILITY_ID_MASK                   (0x000000FFU)
#define CSL_USB3SSDWC_DCID_CAPABILITY_ID_SHIFT                  (0U)
#define CSL_USB3SSDWC_DCID_CAPABILITY_ID_RESETVAL               (0x0000000aU)
#define CSL_USB3SSDWC_DCID_CAPABILITY_ID_MAX                    (0x000000ffU)

#define CSL_USB3SSDWC_DCID_NEXT_CAPABILITY_POINTER_MASK         (0x0000FF00U)
#define CSL_USB3SSDWC_DCID_NEXT_CAPABILITY_POINTER_SHIFT        (8U)
#define CSL_USB3SSDWC_DCID_NEXT_CAPABILITY_POINTER_RESETVAL     (0x00000000U)
#define CSL_USB3SSDWC_DCID_NEXT_CAPABILITY_POINTER_MAX          (0x000000ffU)

#define CSL_USB3SSDWC_DCID_DCERSTMAX_MASK                       (0x001F0000U)
#define CSL_USB3SSDWC_DCID_DCERSTMAX_SHIFT                      (16U)
#define CSL_USB3SSDWC_DCID_DCERSTMAX_RESETVAL                   (0x0000000fU)
#define CSL_USB3SSDWC_DCID_DCERSTMAX_MAX                        (0x0000001fU)

#define CSL_USB3SSDWC_DCID_RESETVAL                             (0x000f000aU)

/* DCDB */

#define CSL_USB3SSDWC_DCDB_DBTARGET_MASK                        (0x0000FF00U)
#define CSL_USB3SSDWC_DCDB_DBTARGET_SHIFT                       (8U)
#define CSL_USB3SSDWC_DCDB_DBTARGET_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DCDB_DBTARGET_MAX                         (0x000000ffU)

#define CSL_USB3SSDWC_DCDB_RESETVAL                             (0x00000000U)

/* DCERSTSZ */

#define CSL_USB3SSDWC_DCERSTSZ_ERS_TABLE_SIZE_MASK              (0x0000FFFFU)
#define CSL_USB3SSDWC_DCERSTSZ_ERS_TABLE_SIZE_SHIFT             (0U)
#define CSL_USB3SSDWC_DCERSTSZ_ERS_TABLE_SIZE_RESETVAL          (0x00000000U)
#define CSL_USB3SSDWC_DCERSTSZ_ERS_TABLE_SIZE_MAX               (0x0000ffffU)

#define CSL_USB3SSDWC_DCERSTSZ_RESETVAL                         (0x00000000U)

/* DCERSTBA_LO */

#define CSL_USB3SSDWC_DCERSTBA_LO_ERS_TABLE_BAR_MASK            (0xFFFFFFF0U)
#define CSL_USB3SSDWC_DCERSTBA_LO_ERS_TABLE_BAR_SHIFT           (4U)
#define CSL_USB3SSDWC_DCERSTBA_LO_ERS_TABLE_BAR_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_DCERSTBA_LO_ERS_TABLE_BAR_MAX             (0x0fffffffU)

#define CSL_USB3SSDWC_DCERSTBA_LO_RESETVAL                      (0x00000000U)

/* DCERSTBA_HI */

#define CSL_USB3SSDWC_DCERSTBA_HI_ERS_TABLE_BAR_MASK            (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DCERSTBA_HI_ERS_TABLE_BAR_SHIFT           (0U)
#define CSL_USB3SSDWC_DCERSTBA_HI_ERS_TABLE_BAR_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_DCERSTBA_HI_ERS_TABLE_BAR_MAX             (0xffffffffU)

#define CSL_USB3SSDWC_DCERSTBA_HI_RESETVAL                      (0x00000000U)

/* DCERDP_LO */

#define CSL_USB3SSDWC_DCERDP_LO_DESI_MASK                       (0x00000007U)
#define CSL_USB3SSDWC_DCERDP_LO_DESI_SHIFT                      (0U)
#define CSL_USB3SSDWC_DCERDP_LO_DESI_RESETVAL                   (0x00000000U)
#define CSL_USB3SSDWC_DCERDP_LO_DESI_MAX                        (0x00000007U)

#define CSL_USB3SSDWC_DCERDP_LO_DEQUEUE_POINTER_MASK            (0xFFFFFFF0U)
#define CSL_USB3SSDWC_DCERDP_LO_DEQUEUE_POINTER_SHIFT           (4U)
#define CSL_USB3SSDWC_DCERDP_LO_DEQUEUE_POINTER_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_DCERDP_LO_DEQUEUE_POINTER_MAX             (0x0fffffffU)

#define CSL_USB3SSDWC_DCERDP_LO_RESETVAL                        (0x00000000U)

/* DCERDP_HI */

#define CSL_USB3SSDWC_DCERDP_HI_DEQUEUE_POINTER_MASK            (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DCERDP_HI_DEQUEUE_POINTER_SHIFT           (0U)
#define CSL_USB3SSDWC_DCERDP_HI_DEQUEUE_POINTER_RESETVAL        (0x00000000U)
#define CSL_USB3SSDWC_DCERDP_HI_DEQUEUE_POINTER_MAX             (0xffffffffU)

#define CSL_USB3SSDWC_DCERDP_HI_RESETVAL                        (0x00000000U)

/* DCCTRL */

#define CSL_USB3SSDWC_DCCTRL_DCR_MASK                           (0x00000001U)
#define CSL_USB3SSDWC_DCCTRL_DCR_SHIFT                          (0U)
#define CSL_USB3SSDWC_DCCTRL_DCR_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_DCR_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_LSE_MASK                           (0x00000002U)
#define CSL_USB3SSDWC_DCCTRL_LSE_SHIFT                          (1U)
#define CSL_USB3SSDWC_DCCTRL_LSE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_LSE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_HOT_MASK                           (0x00000004U)
#define CSL_USB3SSDWC_DCCTRL_HOT_SHIFT                          (2U)
#define CSL_USB3SSDWC_DCCTRL_HOT_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_HOT_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_HIT_MASK                           (0x00000008U)
#define CSL_USB3SSDWC_DCCTRL_HIT_SHIFT                          (3U)
#define CSL_USB3SSDWC_DCCTRL_HIT_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_HIT_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_DRC_MASK                           (0x00000010U)
#define CSL_USB3SSDWC_DCCTRL_DRC_SHIFT                          (4U)
#define CSL_USB3SSDWC_DCCTRL_DRC_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_DRC_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_DEBUG_MAX_BURST_SIZE_MASK          (0x00FF0000U)
#define CSL_USB3SSDWC_DCCTRL_DEBUG_MAX_BURST_SIZE_SHIFT         (16U)
#define CSL_USB3SSDWC_DCCTRL_DEBUG_MAX_BURST_SIZE_RESETVAL      (0x0000000fU)
#define CSL_USB3SSDWC_DCCTRL_DEBUG_MAX_BURST_SIZE_MAX           (0x000000ffU)

#define CSL_USB3SSDWC_DCCTRL_DEVICE_ADDRESS_MASK                (0x7F000000U)
#define CSL_USB3SSDWC_DCCTRL_DEVICE_ADDRESS_SHIFT               (24U)
#define CSL_USB3SSDWC_DCCTRL_DEVICE_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_DEVICE_ADDRESS_MAX                 (0x0000007fU)

#define CSL_USB3SSDWC_DCCTRL_DCE_MASK                           (0x80000000U)
#define CSL_USB3SSDWC_DCCTRL_DCE_SHIFT                          (31U)
#define CSL_USB3SSDWC_DCCTRL_DCE_RESETVAL                       (0x00000000U)
#define CSL_USB3SSDWC_DCCTRL_DCE_MAX                            (0x00000001U)

#define CSL_USB3SSDWC_DCCTRL_RESETVAL                           (0x000f0000U)

/* DCST */

#define CSL_USB3SSDWC_DCST_ER_MASK                              (0x00000001U)
#define CSL_USB3SSDWC_DCST_ER_SHIFT                             (0U)
#define CSL_USB3SSDWC_DCST_ER_RESETVAL                          (0x00000000U)
#define CSL_USB3SSDWC_DCST_ER_MAX                               (0x00000001U)

#define CSL_USB3SSDWC_DCST_DEBUG_PORT_NUMBER_MASK               (0xFF000000U)
#define CSL_USB3SSDWC_DCST_DEBUG_PORT_NUMBER_SHIFT              (24U)
#define CSL_USB3SSDWC_DCST_DEBUG_PORT_NUMBER_RESETVAL           (0x00000000U)
#define CSL_USB3SSDWC_DCST_DEBUG_PORT_NUMBER_MAX                (0x000000ffU)

#define CSL_USB3SSDWC_DCST_RESETVAL                             (0x00000000U)

/* DCPORTSC */

#define CSL_USB3SSDWC_DCPORTSC_CCS_MASK                         (0x00000001U)
#define CSL_USB3SSDWC_DCPORTSC_CCS_SHIFT                        (0U)
#define CSL_USB3SSDWC_DCPORTSC_CCS_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_CCS_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_PED_MASK                         (0x00000002U)
#define CSL_USB3SSDWC_DCPORTSC_PED_SHIFT                        (1U)
#define CSL_USB3SSDWC_DCPORTSC_PED_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_PED_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_PR_MASK                          (0x00000010U)
#define CSL_USB3SSDWC_DCPORTSC_PR_SHIFT                         (4U)
#define CSL_USB3SSDWC_DCPORTSC_PR_RESETVAL                      (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_PR_MAX                           (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_PLS_MASK                         (0x000001E0U)
#define CSL_USB3SSDWC_DCPORTSC_PLS_SHIFT                        (5U)
#define CSL_USB3SSDWC_DCPORTSC_PLS_RESETVAL                     (0x00000005U)
#define CSL_USB3SSDWC_DCPORTSC_PLS_MAX                          (0x0000000fU)

#define CSL_USB3SSDWC_DCPORTSC_PORTSPEED_MASK                   (0x00003C00U)
#define CSL_USB3SSDWC_DCPORTSC_PORTSPEED_SHIFT                  (10U)
#define CSL_USB3SSDWC_DCPORTSC_PORTSPEED_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_PORTSPEED_MAX                    (0x0000000fU)

#define CSL_USB3SSDWC_DCPORTSC_CSC_MASK                         (0x00020000U)
#define CSL_USB3SSDWC_DCPORTSC_CSC_SHIFT                        (17U)
#define CSL_USB3SSDWC_DCPORTSC_CSC_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_CSC_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_PRC_MASK                         (0x00200000U)
#define CSL_USB3SSDWC_DCPORTSC_PRC_SHIFT                        (21U)
#define CSL_USB3SSDWC_DCPORTSC_PRC_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_PRC_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_PLC_MASK                         (0x00400000U)
#define CSL_USB3SSDWC_DCPORTSC_PLC_SHIFT                        (22U)
#define CSL_USB3SSDWC_DCPORTSC_PLC_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_PLC_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_CEC_MASK                         (0x00800000U)
#define CSL_USB3SSDWC_DCPORTSC_CEC_SHIFT                        (23U)
#define CSL_USB3SSDWC_DCPORTSC_CEC_RESETVAL                     (0x00000000U)
#define CSL_USB3SSDWC_DCPORTSC_CEC_MAX                          (0x00000001U)

#define CSL_USB3SSDWC_DCPORTSC_RESETVAL                         (0x000000a0U)

/* DCCP_LO */

#define CSL_USB3SSDWC_DCCP_LO_DCCPR_MASK                        (0xFFFFFFF0U)
#define CSL_USB3SSDWC_DCCP_LO_DCCPR_SHIFT                       (4U)
#define CSL_USB3SSDWC_DCCP_LO_DCCPR_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DCCP_LO_DCCPR_MAX                         (0x0fffffffU)

#define CSL_USB3SSDWC_DCCP_LO_RESETVAL                          (0x00000000U)

/* DCCP_HI */

#define CSL_USB3SSDWC_DCCP_HI_DCCPR_MASK                        (0xFFFFFFFFU)
#define CSL_USB3SSDWC_DCCP_HI_DCCPR_SHIFT                       (0U)
#define CSL_USB3SSDWC_DCCP_HI_DCCPR_RESETVAL                    (0x00000000U)
#define CSL_USB3SSDWC_DCCP_HI_DCCPR_MAX                         (0xffffffffU)

#define CSL_USB3SSDWC_DCCP_HI_RESETVAL                          (0x00000000U)

/* DCDDI1 */

#define CSL_USB3SSDWC_DCDDI1_DBCPROTOCOL_MASK                   (0x000000FFU)
#define CSL_USB3SSDWC_DCDDI1_DBCPROTOCOL_SHIFT                  (0U)
#define CSL_USB3SSDWC_DCDDI1_DBCPROTOCOL_RESETVAL               (0x00000000U)
#define CSL_USB3SSDWC_DCDDI1_DBCPROTOCOL_MAX                    (0x000000ffU)

#define CSL_USB3SSDWC_DCDDI1_VENDORID_MASK                      (0xFFFF0000U)
#define CSL_USB3SSDWC_DCDDI1_VENDORID_SHIFT                     (16U)
#define CSL_USB3SSDWC_DCDDI1_VENDORID_RESETVAL                  (0x00000000U)
#define CSL_USB3SSDWC_DCDDI1_VENDORID_MAX                       (0x0000ffffU)

#define CSL_USB3SSDWC_DCDDI1_RESETVAL                           (0x00000000U)

/* DCDDI2 */

#define CSL_USB3SSDWC_DCDDI2_PRODUCTID_MASK                     (0x0000FFFFU)
#define CSL_USB3SSDWC_DCDDI2_PRODUCTID_SHIFT                    (0U)
#define CSL_USB3SSDWC_DCDDI2_PRODUCTID_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DCDDI2_PRODUCTID_MAX                      (0x0000ffffU)

#define CSL_USB3SSDWC_DCDDI2_DEVICEREV_MASK                     (0xFFFF0000U)
#define CSL_USB3SSDWC_DCDDI2_DEVICEREV_SHIFT                    (16U)
#define CSL_USB3SSDWC_DCDDI2_DEVICEREV_RESETVAL                 (0x00000000U)
#define CSL_USB3SSDWC_DCDDI2_DEVICEREV_MAX                      (0x0000ffffU)

#define CSL_USB3SSDWC_DCDDI2_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
