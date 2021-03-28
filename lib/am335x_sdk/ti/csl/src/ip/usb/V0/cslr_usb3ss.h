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
#ifndef CSLR_USB3SS_H_
#define CSLR_USB3SS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for IRQ_EOI_MAIN
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI_MAIN;
} CSL_Usb3ssIrq_eoi_mainRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_OABS
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI_OABS;
    volatile Uint32 IRQ_STATUS_RAW_OABS;
    volatile Uint32 IRQ_STATUS_OABS;
    volatile Uint32 IRQ_ENABLE_SET_OABS;
    volatile Uint32 IRQ_ENABLE_CLR_OABS;
    volatile Uint8  RSVD0[4];
} CSL_Usb3ssIrq_oabsRegs;


/**************************************************************************
* Register Overlay Structure for WBU_SPECIFIC
**************************************************************************/
typedef struct {
    volatile Uint32 UTMI_OTG_CTRL;
    volatile Uint32 UTMI_OTG_STATUS;
    volatile Uint32 TXFIFO_DEPTH;
    volatile Uint32 RXFIFO_DEPTH;
    volatile Uint8  RSVD0[240];
} CSL_Usb3ssWbu_specificRegs;


/**************************************************************************
* Register Overlay Structure for MISC
**************************************************************************/
typedef struct {
    volatile Uint32 MMRAM_OFFSET;
    volatile Uint32 FLADJ;
    volatile Uint32 DEBUG_CFG;
    volatile Uint32 DEBUG_DATA;
    volatile Uint32 DEV_EBC_EN;
    volatile Uint32 HOST_HUB_CTRL;
    volatile Uint32 DEBUG_THR;
    volatile Uint8  RSVD0[228];
} CSL_Usb3ssMiscRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_MISC
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI_MISC;
    volatile Uint32 IRQ_STATUS_RAW_MISC;
    volatile Uint32 IRQ_STATUS_MISC;
    volatile Uint32 IRQ_ENABLE_SET_MISC;
    volatile Uint32 IRQ_ENABLE_CLR_MISC;
} CSL_Usb3ssIrq_miscRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_MAIN
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_STATUS_RAW_MAIN;
    volatile Uint32 IRQ_STATUS_MAIN;
    volatile Uint32 IRQ_ENABLE_SET_MAIN;
    volatile Uint32 IRQ_ENABLE_CLR_MAIN;
} CSL_Usb3ssIrq_mainRegs;


/**************************************************************************
* Register Overlay Structure for DSPS_SPECIFIC
**************************************************************************/
typedef struct {
    volatile Uint32 SER_CONTROL;
    volatile Uint32 SER_STATUS;
    volatile Uint32 SER_ADDRESS;
    volatile Uint32 PHY2CONFIG;
    volatile Uint32 PHY3CONFIG;
    volatile Uint32 USBCONFIG;
    volatile Uint8  RSVD0[232];
} CSL_Usb3ssDsps_specificRegs;


/**************************************************************************
* Register Overlay Structure for TRACE_RAM
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD0[4096];
} CSL_Usb3ssTrace_ramRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD1[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD2[4];
    CSL_Usb3ssIrq_eoi_mainRegs	IRQ_EOI_MAIN;
    volatile Uint8  RSVD3[4];
    CSL_Usb3ssIrq_mainRegs	IRQ_MAIN[16];
    volatile Uint8  RSVD4[780];
    CSL_Usb3ssIrq_miscRegs	IRQ_MISC;
    volatile Uint8  RSVD5[12];
    CSL_Usb3ssIrq_oabsRegs	IRQ_OABS;
    volatile Uint8  RSVD6[156];
    CSL_Usb3ssWbu_specificRegs	WBU_SPECIFIC;
    CSL_Usb3ssDsps_specificRegs	DSPS_SPECIFIC;
    CSL_Usb3ssMiscRegs	MISC;
    volatile Uint8  RSVD7[26624];
    CSL_Usb3ssTrace_ramRegs	TRACE_RAM;
} CSL_Usb3ssRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier (X.Y.R) Used by software to track features, bugs, 
 * and compatibility */
#define CSL_USB3SS_REVISION                                     (0x0U)

/* Controls various parameters of the master and slave interfaces. */
#define CSL_USB3SS_SYSCONFIG                                    (0x10U)

/* Software End-Of-Interrupt, MAIN lines: Flag the end current event to allow 
 * the generation of further pulses on the line. Write 1 to a bit to EOI the 
 * corresponding line. Unused when using the level interrupt line (depending 
 * on module integration). */
#define CSL_USB3SS_IRQ_EOI_MAIN                                 (0x18U)

/* Software End-Of-Interrupt, OABS line: Flag the end current event to allow 
 * the generation of further pulses on the line. Unused when using the level 
 * interrupt line (depending on module integration). */
#define CSL_USB3SS_IRQ_EOI_OABS                                 (0x44CU)

/* The IRQ_STATUS_RAW_OABS Register allows the OTG, ADP, BC, and SER interrupt 
 * sources to be manually triggered when writing a 1 to a specific bit. A read 
 * of this register returns the interrupt event pending value. General actions 
 * per bit: Write 0: No action Write 1: Set event Read 0: No event pending 
 * Read 1: Event pending */
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS                          (0x450U)

/* The IRQ_STATUS_OABS Register allows the OTG, ADP, BC, and SER interrupt 
 * sources to be manually cleared when writing a 1 to a specific bit. A read 
 * of this register returns the interrupt event pending value. General actions 
 * per bit: Write 0: No action Write 1: Clear event Read 0: No event pending 
 * Read 1: Event pending */
#define CSL_USB3SS_IRQ_STATUS_OABS                              (0x454U)

/* The IRQ_ENABLE_SET_OABS Register allows the OTG, ADP, BC, and SER interrupt 
 * sources to be manually enabled when writing a 1 to a specific bit. A read 
 * of this register returns the interrupt event pending value. General actions 
 * per bit: Write 0: No action Write 1: Interrupt enabled Read 0: Interrupt 
 * disabled Read 1: Interrupt enabled */
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS                          (0x458U)

/* The IRQ_ENABLE_CLR_OABS Register allows the OTG, ADP, BC, and SER interrupt 
 * sources to be manually disabled when writing a 1 to a specific bit. A read 
 * of this register returns the interrupt event pending value. General actions 
 * per bit: Write 0: No action Write 1: Disable the event Read 0: Interrupt 
 * disabled Read 1: Interrupt enabled */
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS                          (0x45CU)

/* The UTMI_OTG_CTL register provides information given by the controller to 
 * the PHY for implementations that might use an external PMIC. */
#define CSL_USB3SS_UTMI_OTG_CTRL                                (0x500U)

/* The UTMI_OTG_STATUS register is used to communicate via an external PMIC 
 * and the controller. The PMIC signals the controller via an interrupt and 
 * software will update these register fields based on data from the external 
 * PMIC. This register is available, but it has no function in USB2SS_SR80LX 
 * implementations. */
#define CSL_USB3SS_UTMI_OTG_STATUS                              (0x504U)

/* The controller configuration parameter DWC_USB3_RAM1_DEPTH indicates the 
 * USBSS configuration with the maximum number of addressable locations in the 
 * TxFIFO. Different USBSS configurations can be implemented with 
 * DWC_USB3_RAM1_DEPTH or less number of locations. The TXFIFO_DEPTH register 
 * needs to initialized at startup with the actual number of physical RAM 
 * locations for that specific configuration. Valid sizes can range from 1 to 
 * 65535 addressable locations. */
#define CSL_USB3SS_TXFIFO_DEPTH                                 (0x508U)

/* The controller configuration parameter DWC_USB3_RAM2_DEPTH indicates the 
 * USBSS configuration with the maximum number of addressable locations in the 
 * RxFIFO. Different USBSS configurations can be implemented with 
 * DWC_USB3_RAM2_DEPTH or less number of locations. The RXFIFO_DEPTH register 
 * needs to initialized at startup with the actual number of physical RAM 
 * locatiosn for that specific configuration. Valid sizes can range from 1 to 
 * 65535 addressable locations. */
#define CSL_USB3SS_RXFIFO_DEPTH                                 (0x50CU)

/* Offset of Memory-mapped RAM accesses. Page is remapped from 0x8000 to 
 * 0xFFFF (32 kbyte) */
#define CSL_USB3SS_MMRAM_OFFSET                                 (0x700U)

/* Jitter adjustment and other pseudo-static parameters */
#define CSL_USB3SS_FLADJ                                        (0x704U)

/* Data that is observable and/or data used for thresholds with trace RAM. 
 * Observable data is selected via DEBUG_CFG.sel_dbg , shown only for sel_dbg 
 * = (1,2,3,4) Data used for thresholds via DEBUG_CFG.sel_thr , shown only for 
 * sel_thr = (1,2,3,4) */
#define CSL_USB3SS_DEBUG_DATA                                   (0x70CU)

/* Configuration of debug data for observation and for control. 0x0 = debug 
 * outputs are tied low 0x1 = debug outputs are UTMI interface signals 1 0x2 = 
 * debug outputs are UTMI interface signals 2 0x3 = debug outputs are PIPE3 
 * interface signals 0x4 = debug outputs are xHC internal signals 0x5 = debug 
 * outputs are controller logic_analyzer_trace[31:0] 0x6 = debug outputs are 
 * controller logic_analyzer_trace[63:32] SEL_DBG and SEL_THR can be the same 
 * value or they can be different. */
#define CSL_USB3SS_DEBUG_CFG                                    (0x708U)

/* The HOST_HUB_CTRL Register is a collection of various input signals that 
 * control the xHC controllers Host or Hub interfaces. These signals are used 
 * regardless if a Host or Hub is implemented or not. */
#define CSL_USB3SS_HOST_HUB_CTRL                                (0x714U)

/* The DEBUG_THR register contains the index, value, and enable for 4 data 
 * signals which are used to trigger the start of a trace. If all the enabled 
 * data match their triggered values at the same clock cycle, then the trace 
 * RAM will start storing the next 1024 samples. Each of the 4 possible 
 * signals must be located within the same group (choice of 32 signals) that 
 * is defined by DEBUG_CFG.sel_thr. Each of the 4 possiblie thresholds is 
 * defined as follows: Index of the data, binary value of the data which is 
 * used as a trigger, and enable of the data. This register is only used if 
 * DEBUG_CFG.EXT_TRIG_EN=0. */
#define CSL_USB3SS_DEBUG_THR                                    (0x718U)

/* Enable External Buffer Control (EBC) for selected endpoints. Works for both 
 * Device and Host modes. INEP[x] Enable EBC HW throttling for IN EP (USB 
 * transmit). To enable logical EP IN #i, set DEV_EBC_EN[x]. In DEPCFG command 
 * for this EP, DEPCMDPAR1[x] = LimitOutstandingTxDMA should then also be set 
 * to 1 OUTEP[x] Enable EBC HW throttling for OUT EP, per bit (USB receive). 
 * To enable logical OUT EP #i, set DEV_EBC_EN[x+16] In DEPCFG command for 
 * this EP, DEPCMDPAR1[x] = LimitOutstandingTxDMA should then also be set to 1 
 * x ranges from 15 downto 14 */
#define CSL_USB3SS_DEV_EBC_EN                                   (0x710U)

/* The End of Interrupt (EOI) MISC Register allows the CPU to acknowledge 
 * completion of an interrupt by writing to the EOI for MISC interrupt 
 * sources. An eoi_write signal will be generated and another interrupt will 
 * be triggered if interrupt sources remain. This register will be reset one 
 * cycle after it has been written to. */
#define CSL_USB3SS_IRQ_EOI_MISC                                 (0x42CU)

/* The IRQ_STATUS_RAW_MISC register allows the usbss interrupt sources to be 
 * manually set when writing a 1 to a specific bit. Write 0: No action Write 
 * 1: Set event Read 0: No event pending Read 1: Event pending */
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC                          (0x430U)

/* The IRQ_STATUS_MISC register allows the usbss interrupt sources to be 
 * manually cleared when writing a 1 to a specific bit. Write 0: No action 
 * Write 1: Clear event Read 0: No event pending Read 1: Event pending */
#define CSL_USB3SS_IRQ_STATUS_MISC                              (0x434U)

/* The IRQ_ENABLE_SET_MISC register allows the usbss interrupt sources to be 
 * manually enabled when writing a 1 to a specific bit. Write 0: No action 
 * Write 1: Enable event Read 0: Event is disabled Read 1: Event is enabled */
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC                          (0x438U)

/* The IRQ_ENABLE_CLR_MISC register allows the usbss interrupt sources to be 
 * manually disabled when writing a 1 to a specific bit. Write 0: No action 
 * Write 1: Disable event Read 0: Event is disabled Read 1: Event is enabled */
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC                          (0x43CU)

/* The IRQ_STATUS_RAW_MAIN_Y register allows the usbss interrupt sources to be 
 * manually set when writing a 1 to a specific bit. Parameter Y ranges from 0 
 * to 15. */
#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN(n)                       (0x20U + ((n) * (0x10U)))

/* The IRQ_STATUS_MAIN_Y register allows the usbss interrupt sources to be 
 * manually cleared when writing a 1 to a specific bit. Parameter Y ranges 
 * from 0 to 15. */
#define CSL_USB3SS_IRQ_STATUS_MAIN(n)                           (0x24U + ((n) * (0x10U)))

/* The IRQ_ENABLE_SET_MAIN_Y register allows the usbss interrupt sources to be 
 * manually enabled when writing a 1 to a specific bit. Parameter Y ranges 
 * from 0 to 15. */
#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN(n)                       (0x28U + ((n) * (0x10U)))

/* The IRQ_ENABLE_SET_MAIN_Y register allows the usbss interrupt sources to be 
 * manually disabled when writing a 1 to a specific bit. Parameter Y ranges 
 * from 0 to 15. */
#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN(n)                       (0x2CU + ((n) * (0x10U)))

/* The SER_CONTROL register sets the enable bits for their respective error 
 * correction and/or detection functions. Depending on the application the 
 * system may or may not need error detection and/or error correction for each 
 * IP. These bits give the option to either enable or disable these features. 
 * The USB2SS_SR80LX does not use the parameter PAR_EN. */
#define CSL_USB3SS_SER_CONTROL                                  (0x600U)

/* The SER Status Register contains many important status fields for the 
 * system to diagnose the SER event. If par_err is set high, then the parity 
 * check detection logic has determined that the parity stored in the RAM does 
 * not match the parity that was generated by the read transaction. If bec_err 
 * is set high, then the block error correction has a non-zero syndrome value. 
 * This means that an error has been detected. Single bit errors will be 
 * corrected and double bit errors will be detected. The type of error will be 
 * shown in the type_err field. A value of 0 indicates no error has been 
 * detected and/or corrected. A value of 1 or 2 indicates either a single or 
 * double error has been detected. Values of 1 and 2 will only be valid if a 
 * block coder has been implemented (m>3). A value of 3 indicates that the 
 * parity detection logic has detected an error event. The byte_pos field 
 * indicates which p byte of the RAM that had the parity detection error event 
 * for designs with p>1. The position of the byte will be in little Endian. 
 * This status is optional and it only supports RAMs that have 8 bytes or 
 * less. The addr_valid field indicates whether the address of the RAM with 
 * the error event can be determined. A value of 1 indicates that the address 
 * in the SER Address Register is valid. A value of 0 indicates that the 
 * address can not be determined. If the address can not be determined, then 
 * the system will assume that the entire RAM is corrupted. The ram_err field 
 * indicates which RAM had the error event. This field will be specific to the 
 * IP that supports SER and will need to be defined in the respective IP 
 * memory map. Each IP can have up to 4096 individual RAMs. The USB2SS_SR80LX 
 * does not use the parameter PAR_ERR or BYTE_POS. */
#define CSL_USB3SS_SER_STATUS                                   (0x604U)

/* The SER Address Register indicates the address of the RAM that had the 
 * error event. */
#define CSL_USB3SS_SER_ADDRESS                                  (0x608U)

/* USB2 PHY configuration */
#define CSL_USB3SS_PHY2CONFIG                                   (0x60CU)

/* USB3 PHY configuration */
#define CSL_USB3SS_PHY3CONFIG                                   (0x610U)

/* USB configuration register */
#define CSL_USB3SS_USBCONFIG                                    (0x614U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_USB3SS_REVISION_Y_MINOR_MASK                        (0x0000003FU)
#define CSL_USB3SS_REVISION_Y_MINOR_SHIFT                       (0U)
#define CSL_USB3SS_REVISION_Y_MINOR_RESETVAL                    (0x00000000U)
#define CSL_USB3SS_REVISION_Y_MINOR_MAX                         (0x0000003fU)

#define CSL_USB3SS_REVISION_CUSTOM_MASK                         (0x000000C0U)
#define CSL_USB3SS_REVISION_CUSTOM_SHIFT                        (6U)
#define CSL_USB3SS_REVISION_CUSTOM_RESETVAL                     (0x00000000U)
#define CSL_USB3SS_REVISION_CUSTOM_STANDARD                     (0x00000000U)

#define CSL_USB3SS_REVISION_X_MAJOR_MASK                        (0x00000700U)
#define CSL_USB3SS_REVISION_X_MAJOR_SHIFT                       (8U)
#define CSL_USB3SS_REVISION_X_MAJOR_RESETVAL                    (0x00000004U)
#define CSL_USB3SS_REVISION_X_MAJOR_V10                         (0x00000001U)
#define CSL_USB3SS_REVISION_X_MAJOR_V20                         (0x00000002U)
#define CSL_USB3SS_REVISION_X_MAJOR_V30                         (0x00000003U)
#define CSL_USB3SS_REVISION_X_MAJOR_V40                         (0x00000004U)

#define CSL_USB3SS_REVISION_R_RTL_MASK                          (0x0000F800U)
#define CSL_USB3SS_REVISION_R_RTL_SHIFT                         (11U)
#define CSL_USB3SS_REVISION_R_RTL_RESETVAL                      (0x00000001U)
#define CSL_USB3SS_REVISION_R_RTL_MAX                           (0x0000001fU)

#define CSL_USB3SS_REVISION_FUNC_MASK                           (0x0FFF0000U)
#define CSL_USB3SS_REVISION_FUNC_SHIFT                          (16U)
#define CSL_USB3SS_REVISION_FUNC_RESETVAL                       (0x00000792U)
#define CSL_USB3SS_REVISION_FUNC_MAX                            (0x00000fffU)

#define CSL_USB3SS_REVISION_SCHEME_MASK                         (0xC0000000U)
#define CSL_USB3SS_REVISION_SCHEME_SHIFT                        (30U)
#define CSL_USB3SS_REVISION_SCHEME_RESETVAL                     (0x00000001U)
#define CSL_USB3SS_REVISION_SCHEME_H08                          (0x00000001U)
#define CSL_USB3SS_REVISION_SCHEME_LEGACY                       (0x00000000U)

#define CSL_USB3SS_REVISION_BU_MASK                             (0x30000000U)
#define CSL_USB3SS_REVISION_BU_SHIFT                            (28U)
#define CSL_USB3SS_REVISION_BU_RESETVAL                         (0x00000000U)
#define CSL_USB3SS_REVISION_BU_WBU                              (0x00000001U)
#define CSL_USB3SS_REVISION_BU_DSPS                             (0x00000000U)

#define CSL_USB3SS_REVISION_RESETVAL                            (0x47920c00U)

/* SYSCONFIG */

#define CSL_USB3SS_SYSCONFIG_DMADISABLE_MASK                    (0x00010000U)
#define CSL_USB3SS_SYSCONFIG_DMADISABLE_SHIFT                   (16U)
#define CSL_USB3SS_SYSCONFIG_DMADISABLE_RESETVAL                (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_DMADISABLE_DISABLE                 (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_DMADISABLE_ENABLE                  (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_SOFT_RESET_MASK                    (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_SOFT_RESET_SHIFT                   (0U)
#define CSL_USB3SS_SYSCONFIG_SOFT_RESET_RESETVAL                (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_SOFT_RESET_RESET                   (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_SOFT_RESET_NOOP                    (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_BUSCLKEN_N_MASK                    (0x00000100U)
#define CSL_USB3SS_SYSCONFIG_BUSCLKEN_N_SHIFT                   (8U)
#define CSL_USB3SS_SYSCONFIG_BUSCLKEN_N_RESETVAL                (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_BUSCLKEN_N_DISABLE                 (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_BUSCLKEN_N_ENABLE                  (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_PHYMMRCLKEN_N_MASK                 (0x00000200U)
#define CSL_USB3SS_SYSCONFIG_PHYMMRCLKEN_N_SHIFT                (9U)
#define CSL_USB3SS_SYSCONFIG_PHYMMRCLKEN_N_RESETVAL             (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_PHYMMRCLKEN_N_DISABLE              (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_PHYMMRCLKEN_N_ENABLE               (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_UTMICLKEN_N_MASK                   (0x00000400U)
#define CSL_USB3SS_SYSCONFIG_UTMICLKEN_N_SHIFT                  (10U)
#define CSL_USB3SS_SYSCONFIG_UTMICLKEN_N_RESETVAL               (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_UTMICLKEN_N_DISABLE                (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_UTMICLKEN_N_ENABLE                 (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_ULPICLKEN_N_MASK                   (0x00000800U)
#define CSL_USB3SS_SYSCONFIG_ULPICLKEN_N_SHIFT                  (11U)
#define CSL_USB3SS_SYSCONFIG_ULPICLKEN_N_RESETVAL               (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_ULPICLKEN_N_DISABLE                (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_ULPICLKEN_N_ENABLE                 (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_PIPECLKEN_N_MASK                   (0x00001000U)
#define CSL_USB3SS_SYSCONFIG_PIPECLKEN_N_SHIFT                  (12U)
#define CSL_USB3SS_SYSCONFIG_PIPECLKEN_N_RESETVAL               (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_PIPECLKEN_N_DISABLE                (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_PIPECLKEN_N_ENABLE                 (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_SUSPCLKEN_N_MASK                   (0x00002000U)
#define CSL_USB3SS_SYSCONFIG_SUSPCLKEN_N_SHIFT                  (13U)
#define CSL_USB3SS_SYSCONFIG_SUSPCLKEN_N_RESETVAL               (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_SUSPCLKEN_N_DISABLE                (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_SUSPCLKEN_N_ENABLE                 (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_REFCLKEN_N_MASK                    (0x00004000U)
#define CSL_USB3SS_SYSCONFIG_REFCLKEN_N_SHIFT                   (14U)
#define CSL_USB3SS_SYSCONFIG_REFCLKEN_N_RESETVAL                (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_REFCLKEN_N_DISABLE                 (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_REFCLKEN_N_ENABLE                  (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_WRAPRESET_MASK                     (0x00020000U)
#define CSL_USB3SS_SYSCONFIG_WRAPRESET_SHIFT                    (17U)
#define CSL_USB3SS_SYSCONFIG_WRAPRESET_RESETVAL                 (0x00000000U)
#define CSL_USB3SS_SYSCONFIG_WRAPRESET_RESET                    (0x00000001U)
#define CSL_USB3SS_SYSCONFIG_WRAPRESET_NOOP                     (0x00000000U)

#define CSL_USB3SS_SYSCONFIG_RESETVAL                           (0x00010000U)

/* IRQ_EOI_MAIN */

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI0_MASK                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI0_SHIFT                      (0U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI0_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI0_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI0_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI1_MASK                       (0x00000002U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI1_SHIFT                      (1U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI1_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI1_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI1_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI2_MASK                       (0x00000004U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI2_SHIFT                      (2U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI2_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI2_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI2_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI3_MASK                       (0x00000008U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI3_SHIFT                      (3U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI3_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI3_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI3_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI4_MASK                       (0x00000010U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI4_SHIFT                      (4U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI4_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI4_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI4_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI5_MASK                       (0x00000020U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI5_SHIFT                      (5U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI5_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI5_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI5_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI6_MASK                       (0x00000040U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI6_SHIFT                      (6U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI6_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI6_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI6_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI7_MASK                       (0x00000080U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI7_SHIFT                      (7U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI7_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI7_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI7_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI8_MASK                       (0x00000100U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI8_SHIFT                      (8U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI8_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI8_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI8_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI9_MASK                       (0x00000200U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI9_SHIFT                      (9U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI9_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI9_EOI                        (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI9_NOOP                       (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI10_MASK                      (0x00000400U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI10_SHIFT                     (10U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI10_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI10_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI10_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI11_MASK                      (0x00000800U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI11_SHIFT                     (11U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI11_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI11_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI11_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI12_MASK                      (0x00001000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI12_SHIFT                     (12U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI12_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI12_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI12_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI13_MASK                      (0x00002000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI13_SHIFT                     (13U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI13_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI13_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI13_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI14_MASK                      (0x00004000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI14_SHIFT                     (14U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI14_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI14_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI14_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_EOI15_MASK                      (0x00008000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI15_SHIFT                     (15U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI15_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI15_EOI                       (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MAIN_EOI15_NOOP                      (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MAIN_RESETVAL                        (0x00000000U)

/* IRQ_EOI_OABS */

#define CSL_USB3SS_IRQ_EOI_OABS_EOI_OABS_MASK                   (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_OABS_EOI_OABS_SHIFT                  (0U)
#define CSL_USB3SS_IRQ_EOI_OABS_EOI_OABS_RESETVAL               (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_OABS_EOI_OABS_EOI                    (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_OABS_EOI_OABS_NOOP                   (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_OABS_RESETVAL                        (0x00000000U)

/* IRQ_STATUS_RAW_OABS */

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_SER_EVENT_MASK           (0x00000001U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_SER_EVENT_SHIFT          (0U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_SER_EVENT_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_SER_EVENT_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_MASK         (0x00000004U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_SHIFT        (2U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_MV_CHNGEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_MASK     (0x00000010U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_SHIFT    (4U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPRSTCMPLTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_MASK        (0x00000020U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_SHIFT       (5U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPTMOUTEVNT_MAX         (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_MASK          (0x00000040U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_SHIFT         (6U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPSNSEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_MASK          (0x00000080U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_SHIFT         (7U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_ADPPRBEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_MASK  (0x00000100U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT  (8U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVVBUSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_MASK  (0x00000200U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT  (9U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVSESSVLDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_MASK  (0x00000400U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_SHIFT  (10U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_MASK  (0x00000800U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_SHIFT  (11U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGBDEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_MASK  (0x00010000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_SHIFT  (16U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSESSENDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_MASK   (0x00020000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_SHIFT  (17U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVSRPDETEVNT_MAX    (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_MASK  (0x00040000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_SHIFT  (18U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_MASK     (0x00080000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_SHIFT    (19U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVHOSTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_MASK  (0x00100000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_SHIFT  (20U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_MASK     (0x00200000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_SHIFT    (21U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGADEVIDLEEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_MASK    (0x00400000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_SHIFT   (22U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRINITNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_MASK    (0x00800000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_SHIFT   (23U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_HRRCONFNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_MASK  (0x01000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_SHIFT  (24U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGCONIDSTSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_MASK     (0x02000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_SHIFT    (25U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGHIBENTRYEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_MASK  (0x04000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_SHIFT  (26U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGDEVRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_MASK  (0x08000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT  (27U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_OTGXHCIRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_OABS_RESETVAL                 (0x00000000U)

/* IRQ_STATUS_OABS */

#define CSL_USB3SS_IRQ_STATUS_OABS_SER_EVENT_MASK               (0x00000001U)
#define CSL_USB3SS_IRQ_STATUS_OABS_SER_EVENT_SHIFT              (0U)
#define CSL_USB3SS_IRQ_STATUS_OABS_SER_EVENT_RESETVAL           (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_SER_EVENT_MAX                (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_MV_CHNGEVNT_MASK             (0x00000004U)
#define CSL_USB3SS_IRQ_STATUS_OABS_MV_CHNGEVNT_SHIFT            (2U)
#define CSL_USB3SS_IRQ_STATUS_OABS_MV_CHNGEVNT_RESETVAL         (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_MV_CHNGEVNT_MAX              (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_MASK         (0x00000010U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_SHIFT        (4U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPRSTCMPLTEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_ADPTMOUTEVNT_MASK            (0x00000020U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPTMOUTEVNT_SHIFT           (5U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPTMOUTEVNT_RESETVAL        (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPTMOUTEVNT_MAX             (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_ADPSNSEVNT_MASK              (0x00000040U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPSNSEVNT_SHIFT             (6U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPSNSEVNT_RESETVAL          (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPSNSEVNT_MAX               (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_ADPPRBEVNT_MASK              (0x00000080U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPPRBEVNT_SHIFT             (7U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPPRBEVNT_RESETVAL          (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_ADPPRBEVNT_MAX               (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_MASK     (0x00000100U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT    (8U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVVBUSCHNGEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_MASK   (0x00000200U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT  (9U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVSESSVLDDETEVNT_MAX    (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_MASK      (0x00000400U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_SHIFT     (10U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVHNPCHNGEVNT_MAX       (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_MASK     (0x00000800U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_SHIFT    (11U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGBDEVBHOSTENDEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_MASK   (0x00010000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_SHIFT  (16U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSESSENDDETEVNT_MAX    (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_MASK       (0x00020000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_SHIFT      (17U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_RESETVAL   (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVSRPDETEVNT_MAX        (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_MASK      (0x00040000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_SHIFT     (18U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHNPCHNGEVNT_MAX       (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_MASK         (0x00080000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_SHIFT        (19U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVHOSTEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_MASK     (0x00100000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_SHIFT    (20U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVBHOSTENDEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_MASK         (0x00200000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_SHIFT        (21U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGADEVIDLEEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_MASK        (0x00400000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_SHIFT       (22U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRINITNOTIFEVNT_MAX         (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_MASK        (0x00800000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_SHIFT       (23U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_HRRCONFNOTIFEVNT_MAX         (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_MASK     (0x01000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_SHIFT    (24U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGCONIDSTSCHNGEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_MASK         (0x02000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_SHIFT        (25U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGHIBENTRYEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_MASK     (0x04000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_SHIFT    (26U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGDEVRUNSTPSETEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_MASK    (0x08000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT   (27U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_OABS_OTGXHCIRUNSTPSETEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_OABS_RESETVAL                     (0x00000000U)

/* IRQ_ENABLE_SET_OABS */

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_SER_EVENT_MASK           (0x00000001U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_SER_EVENT_SHIFT          (0U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_SER_EVENT_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_SER_EVENT_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_MASK         (0x00000004U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_SHIFT        (2U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_MV_CHNGEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_MASK     (0x00000010U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_SHIFT    (4U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPRSTCMPLTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_MASK        (0x00000020U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_SHIFT       (5U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPTMOUTEVNT_MAX         (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_MASK          (0x00000040U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_SHIFT         (6U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPSNSEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_MASK          (0x00000080U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_SHIFT         (7U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_ADPPRBEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_MASK  (0x00000100U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT  (8U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVVBUSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_MASK  (0x00000200U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT  (9U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVSESSVLDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_MASK  (0x00000400U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_SHIFT  (10U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_MASK  (0x00000800U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_SHIFT  (11U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGBDEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_MASK  (0x00010000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_SHIFT  (16U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSESSENDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_MASK   (0x00020000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_SHIFT  (17U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVSRPDETEVNT_MAX    (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_MASK  (0x00040000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_SHIFT  (18U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_MASK     (0x00080000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_SHIFT    (19U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVHOSTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_MASK  (0x00100000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_SHIFT  (20U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_MASK     (0x00200000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_SHIFT    (21U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGADEVIDLEEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_MASK    (0x00400000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_SHIFT   (22U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRINITNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_MASK    (0x00800000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_SHIFT   (23U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_HRRCONFNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_MASK  (0x01000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_SHIFT  (24U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGCONIDSTSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_MASK     (0x02000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_SHIFT    (25U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGHIBENTRYEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_MASK  (0x04000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_SHIFT  (26U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGDEVRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_MASK  (0x08000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT  (27U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_OTGXHCIRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_OABS_RESETVAL                 (0x00000000U)

/* IRQ_ENABLE_CLR_OABS */

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_SER_EVENT_MASK           (0x00000001U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_SER_EVENT_SHIFT          (0U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_SER_EVENT_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_SER_EVENT_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_MASK         (0x00000004U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_SHIFT        (2U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_MV_CHNGEVNT_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_MASK     (0x00000010U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_SHIFT    (4U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPRSTCMPLTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_MASK        (0x00000020U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_SHIFT       (5U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPTMOUTEVNT_MAX         (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_MASK          (0x00000040U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_SHIFT         (6U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPSNSEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_MASK          (0x00000080U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_SHIFT         (7U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_ADPPRBEVNT_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_MASK  (0x00000100U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_SHIFT  (8U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVVBUSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_MASK  (0x00000200U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_SHIFT  (9U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVSESSVLDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_MASK  (0x00000400U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_SHIFT  (10U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_MASK  (0x00000800U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_SHIFT  (11U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGBDEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_MASK  (0x00010000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_SHIFT  (16U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSESSENDDETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_MASK   (0x00020000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_SHIFT  (17U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVSRPDETEVNT_MAX    (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_MASK  (0x00040000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_SHIFT  (18U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHNPCHNGEVNT_MAX   (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_MASK     (0x00080000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_SHIFT    (19U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVHOSTEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_MASK  (0x00100000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_SHIFT  (20U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVBHOSTENDEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_MASK     (0x00200000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_SHIFT    (21U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGADEVIDLEEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_MASK    (0x00400000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_SHIFT   (22U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRINITNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_MASK    (0x00800000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_SHIFT   (23U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_HRRCONFNOTIFEVNT_MAX     (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_MASK  (0x01000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_SHIFT  (24U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGCONIDSTSCHNGEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_MASK     (0x02000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_SHIFT    (25U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGHIBENTRYEVNT_MAX      (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_MASK  (0x04000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_SHIFT  (26U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGDEVRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_MASK  (0x08000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_SHIFT  (27U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_OTGXHCIRUNSTPSETEVNT_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_OABS_RESETVAL                 (0x00000000U)

/* UTMI_OTG_CTRL */

#define CSL_USB3SS_UTMI_OTG_CTRL_IDPULLUP_MASK                  (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_CTRL_IDPULLUP_SHIFT                 (0U)
#define CSL_USB3SS_UTMI_OTG_CTRL_IDPULLUP_RESETVAL              (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_CTRL_IDPULLUP_DISABLE               (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_CTRL_IDPULLUP_ENABLE                (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_CTRL_DISCHRGVBUS_MASK               (0x00000008U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DISCHRGVBUS_SHIFT              (3U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DISCHRGVBUS_RESETVAL           (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DISCHRGVBUS_DISCHARGE          (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DISCHRGVBUS_NOACTION           (0x00000000U)

#define CSL_USB3SS_UTMI_OTG_CTRL_CHRGVBUS_MASK                  (0x00000010U)
#define CSL_USB3SS_UTMI_OTG_CTRL_CHRGVBUS_SHIFT                 (4U)
#define CSL_USB3SS_UTMI_OTG_CTRL_CHRGVBUS_RESETVAL              (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_CTRL_CHRGVBUS_CHARGE                (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_CTRL_CHRGVBUS_NOACTION              (0x00000000U)

#define CSL_USB3SS_UTMI_OTG_CTRL_DRVVBUS_MASK                   (0x00000020U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DRVVBUS_SHIFT                  (5U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DRVVBUS_RESETVAL               (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DRVVBUS_DRIVE                  (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_CTRL_DRVVBUS_NOACTION               (0x00000000U)

#define CSL_USB3SS_UTMI_OTG_CTRL_RESETVAL                       (0x00000001U)

/* UTMI_OTG_STATUS */

#define CSL_USB3SS_UTMI_OTG_STATUS_SW_MODE_MASK                 (0x80000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SW_MODE_SHIFT                (31U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SW_MODE_RESETVAL             (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SW_MODE_IO                   (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SW_MODE_SW                   (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_VBUSVALID_MASK               (0x00000002U)
#define CSL_USB3SS_UTMI_OTG_STATUS_VBUSVALID_SHIFT              (1U)
#define CSL_USB3SS_UTMI_OTG_STATUS_VBUSVALID_RESETVAL           (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_VBUSVALID_VALID              (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_STATUS_VBUSVALID_NOTVALID           (0x00000000U)

#define CSL_USB3SS_UTMI_OTG_STATUS_SESSVALID_MASK               (0x00000004U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSVALID_SHIFT              (2U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSVALID_RESETVAL           (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSVALID_NOTVALID           (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSVALID_VALID              (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_SESSEND_MASK                 (0x00000008U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSEND_SHIFT                (3U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSEND_RESETVAL             (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSEND_ENDED                (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_STATUS_SESSEND_NOTENDED             (0x00000000U)

#define CSL_USB3SS_UTMI_OTG_STATUS_IDDIG_MASK                   (0x00000010U)
#define CSL_USB3SS_UTMI_OTG_STATUS_IDDIG_SHIFT                  (4U)
#define CSL_USB3SS_UTMI_OTG_STATUS_IDDIG_RESETVAL               (0x00000001U)
#define CSL_USB3SS_UTMI_OTG_STATUS_IDDIG_IDA                    (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_IDDIG_IDB                    (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_TXBITSTUFFENABLE_MASK        (0x00000100U)
#define CSL_USB3SS_UTMI_OTG_STATUS_TXBITSTUFFENABLE_SHIFT       (8U)
#define CSL_USB3SS_UTMI_OTG_STATUS_TXBITSTUFFENABLE_RESETVAL    (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_TXBITSTUFFENABLE_NOBS        (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_TXBITSTUFFENABLE_BS          (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_POWERPRESENT_MASK            (0x00000200U)
#define CSL_USB3SS_UTMI_OTG_STATUS_POWERPRESENT_SHIFT           (9U)
#define CSL_USB3SS_UTMI_OTG_STATUS_POWERPRESENT_RESETVAL        (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_POWERPRESENT_MAX             (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_PORT_OVERCURRENT_MASK        (0x00000400U)
#define CSL_USB3SS_UTMI_OTG_STATUS_PORT_OVERCURRENT_SHIFT       (10U)
#define CSL_USB3SS_UTMI_OTG_STATUS_PORT_OVERCURRENT_RESETVAL    (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_PORT_OVERCURRENT_NONE        (0x00000000U)
#define CSL_USB3SS_UTMI_OTG_STATUS_PORT_OVERCURRENT_OC          (0x00000001U)

#define CSL_USB3SS_UTMI_OTG_STATUS_RESETVAL                     (0x80000018U)

/* TXFIFO_DEPTH */

#define CSL_USB3SS_TXFIFO_DEPTH_TXFIFOSIZE_MASK                 (0x0000FFFFU)
#define CSL_USB3SS_TXFIFO_DEPTH_TXFIFOSIZE_SHIFT                (0U)
#define CSL_USB3SS_TXFIFO_DEPTH_TXFIFOSIZE_RESETVAL             (0x00001700U)
#define CSL_USB3SS_TXFIFO_DEPTH_TXFIFOSIZE_MAX                  (0x0000ffffU)

#define CSL_USB3SS_TXFIFO_DEPTH_RESETVAL                        (0x00001700U)

/* RXFIFO_DEPTH */

#define CSL_USB3SS_RXFIFO_DEPTH_RXFIFOSIZE_MASK                 (0x0000FFFFU)
#define CSL_USB3SS_RXFIFO_DEPTH_RXFIFOSIZE_SHIFT                (0U)
#define CSL_USB3SS_RXFIFO_DEPTH_RXFIFOSIZE_RESETVAL             (0x00000400U)
#define CSL_USB3SS_RXFIFO_DEPTH_RXFIFOSIZE_MAX                  (0x0000ffffU)

#define CSL_USB3SS_RXFIFO_DEPTH_RESETVAL                        (0x00000400U)

/* MMRAM_OFFSET */

#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_MASK                 (0x000F8000U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_SHIFT                (15U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_RESETVAL             (0x00000008U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_RAM0_BASE            (0x00000008U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_RAM1_BASE            (0x00000010U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_RAM2_BASE            (0x00000018U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_CORE_BOT             (0x00000000U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_CORE_TOP             (0x00000001U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_MSB_MAX                  (0x0000001fU)

#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_LSB_MASK                 (0x00007FFFU)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_LSB_SHIFT                (0U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_LSB_RESETVAL             (0x00000000U)
#define CSL_USB3SS_MMRAM_OFFSET_OFFSET_LSB_MAX                  (0x00007fffU)

#define CSL_USB3SS_MMRAM_OFFSET_RESETVAL                        (0x00040000U)

/* FLADJ */

#define CSL_USB3SS_FLADJ_FLADJ_30MHZ_MASK                       (0x07E00000U)
#define CSL_USB3SS_FLADJ_FLADJ_30MHZ_SHIFT                      (21U)
#define CSL_USB3SS_FLADJ_FLADJ_30MHZ_RESETVAL                   (0x00000020U)
#define CSL_USB3SS_FLADJ_FLADJ_30MHZ_MAX                        (0x0000003fU)

#define CSL_USB3SS_FLADJ_HOST_U2_PORT_DISABLE_MASK              (0x08000000U)
#define CSL_USB3SS_FLADJ_HOST_U2_PORT_DISABLE_SHIFT             (27U)
#define CSL_USB3SS_FLADJ_HOST_U2_PORT_DISABLE_RESETVAL          (0x00000000U)
#define CSL_USB3SS_FLADJ_HOST_U2_PORT_DISABLE_EN                (0x00000000U)
#define CSL_USB3SS_FLADJ_HOST_U2_PORT_DISABLE_DIS               (0x00000001U)

#define CSL_USB3SS_FLADJ_HOST_U3_PORT_DISABLE_MASK              (0x10000000U)
#define CSL_USB3SS_FLADJ_HOST_U3_PORT_DISABLE_SHIFT             (28U)
#define CSL_USB3SS_FLADJ_HOST_U3_PORT_DISABLE_RESETVAL          (0x00000000U)
#define CSL_USB3SS_FLADJ_HOST_U3_PORT_DISABLE_EN                (0x00000000U)
#define CSL_USB3SS_FLADJ_HOST_U3_PORT_DISABLE_DIS               (0x00000001U)

#define CSL_USB3SS_FLADJ_XHCI_REVISION_MASK                     (0x20000000U)
#define CSL_USB3SS_FLADJ_XHCI_REVISION_SHIFT                    (29U)
#define CSL_USB3SS_FLADJ_XHCI_REVISION_RESETVAL                 (0x00000001U)
#define CSL_USB3SS_FLADJ_XHCI_REVISION__0_96                    (0x00000000U)
#define CSL_USB3SS_FLADJ_XHCI_REVISION__1_0                     (0x00000001U)

#define CSL_USB3SS_FLADJ_CORE_SW_RESET_MASK                     (0x80000000U)
#define CSL_USB3SS_FLADJ_CORE_SW_RESET_SHIFT                    (31U)
#define CSL_USB3SS_FLADJ_CORE_SW_RESET_RESETVAL                 (0x00000000U)
#define CSL_USB3SS_FLADJ_CORE_SW_RESET_NORESET                  (0x00000000U)
#define CSL_USB3SS_FLADJ_CORE_SW_RESET_RESET                    (0x00000001U)

#define CSL_USB3SS_FLADJ_RESETVAL                               (0x24000000U)

/* DEBUG_DATA */

#define CSL_USB3SS_DEBUG_DATA_DEBUG0_MASK                       (0x00000001U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG0_SHIFT                      (0U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG0_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG0_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG1_MASK                       (0x00000002U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG1_SHIFT                      (1U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG1_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG1_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG2_MASK                       (0x00000004U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG2_SHIFT                      (2U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG2_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG2_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG3_MASK                       (0x00000008U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG3_SHIFT                      (3U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG3_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG3_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG4_MASK                       (0x00000010U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG4_SHIFT                      (4U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG4_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG4_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG5_MASK                       (0x00000020U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG5_SHIFT                      (5U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG5_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG5_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG6_MASK                       (0x00000040U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG6_SHIFT                      (6U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG6_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG6_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG7_MASK                       (0x00000080U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG7_SHIFT                      (7U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG7_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG7_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG8_MASK                       (0x00000100U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG8_SHIFT                      (8U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG8_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG8_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG9_MASK                       (0x00000200U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG9_SHIFT                      (9U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG9_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG9_MAX                        (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG10_MASK                      (0x00000400U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG10_SHIFT                     (10U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG10_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG10_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG11_MASK                      (0x00000800U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG11_SHIFT                     (11U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG11_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG11_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG12_MASK                      (0x00001000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG12_SHIFT                     (12U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG12_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG12_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG13_MASK                      (0x00002000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG13_SHIFT                     (13U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG13_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG13_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG14_MASK                      (0x00004000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG14_SHIFT                     (14U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG14_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG14_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG15_MASK                      (0x00008000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG15_SHIFT                     (15U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG15_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG15_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG16_MASK                      (0x00010000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG16_SHIFT                     (16U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG16_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG16_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG17_MASK                      (0x00020000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG17_SHIFT                     (17U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG17_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG17_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG18_MASK                      (0x00040000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG18_SHIFT                     (18U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG18_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG18_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG19_MASK                      (0x00080000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG19_SHIFT                     (19U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG19_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG19_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG20_MASK                      (0x00100000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG20_SHIFT                     (20U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG20_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG20_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG21_MASK                      (0x00200000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG21_SHIFT                     (21U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG21_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG21_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG22_MASK                      (0x00400000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG22_SHIFT                     (22U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG22_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG22_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG23_MASK                      (0x00800000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG23_SHIFT                     (23U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG23_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG23_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG24_MASK                      (0x01000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG24_SHIFT                     (24U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG24_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG24_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG25_MASK                      (0x02000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG25_SHIFT                     (25U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG25_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG25_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG26_MASK                      (0x04000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG26_SHIFT                     (26U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG26_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG26_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG27_MASK                      (0x08000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG27_SHIFT                     (27U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG27_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG27_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG28_MASK                      (0x10000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG28_SHIFT                     (28U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG28_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG28_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG29_MASK                      (0x20000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG29_SHIFT                     (29U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG29_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG29_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG30_MASK                      (0x40000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG30_SHIFT                     (30U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG30_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG30_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_DEBUG31_MASK                      (0x80000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG31_SHIFT                     (31U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG31_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEBUG_DATA_DEBUG31_MAX                       (0x00000001U)

#define CSL_USB3SS_DEBUG_DATA_RESETVAL                          (0x00000000U)

/* DEBUG_CFG */

#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_MASK                       (0x00000007U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_SHIFT                      (0U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_TIELO                      (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_UTMI1                      (0x00000001U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_PIPE                       (0x00000003U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_CORE                       (0x00000004U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_TRACE_LO                   (0x00000005U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_TRACE_HI                   (0x00000006U)
#define CSL_USB3SS_DEBUG_CFG_SEL_DBG_UTMI2                      (0x00000002U)

#define CSL_USB3SS_DEBUG_CFG_SEL_THR_MASK                       (0x00000038U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_SHIFT                      (3U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_TIELO                      (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_UTMI1                      (0x00000001U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_PIPE                       (0x00000003U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_CORE                       (0x00000004U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_TRACE_LO                   (0x00000005U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_TRACE_HI                   (0x00000006U)
#define CSL_USB3SS_DEBUG_CFG_SEL_THR_UTMI2                      (0x00000002U)

#define CSL_USB3SS_DEBUG_CFG_EXT_TRIG_EN_MASK                   (0x00000100U)
#define CSL_USB3SS_DEBUG_CFG_EXT_TRIG_EN_SHIFT                  (8U)
#define CSL_USB3SS_DEBUG_CFG_EXT_TRIG_EN_RESETVAL               (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_EXT_TRIG_EN_MAX                    (0x00000001U)

#define CSL_USB3SS_DEBUG_CFG_TRIG_DATA_AVAL_MASK                (0x00000200U)
#define CSL_USB3SS_DEBUG_CFG_TRIG_DATA_AVAL_SHIFT               (9U)
#define CSL_USB3SS_DEBUG_CFG_TRIG_DATA_AVAL_RESETVAL            (0x00000000U)
#define CSL_USB3SS_DEBUG_CFG_TRIG_DATA_AVAL_MAX                 (0x00000001U)

#define CSL_USB3SS_DEBUG_CFG_RESETVAL                           (0x00000000U)

/* HOST_HUB_CTRL */

#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_MASK      (0x00000003U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_SHIFT     (0U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_RESETVAL  (0x00000000U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_OVERCURRENT_MAX       (0x00000003U)

#define CSL_USB3SS_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_MASK  (0x00000004U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_SHIFT  (2U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_RESETVAL  (0x00000001U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_PORT_POWER_CONTROL_PRESENT_MAX  (0x00000001U)

#define CSL_USB3SS_HOST_HUB_CTRL_HOST_MSI_ENABLE_MASK           (0x00000008U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_MSI_ENABLE_SHIFT          (3U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_MSI_ENABLE_RESETVAL       (0x00000001U)
#define CSL_USB3SS_HOST_HUB_CTRL_HOST_MSI_ENABLE_MAX            (0x00000001U)

#define CSL_USB3SS_HOST_HUB_CTRL_XHC_BME_MASK                   (0x00000020U)
#define CSL_USB3SS_HOST_HUB_CTRL_XHC_BME_SHIFT                  (5U)
#define CSL_USB3SS_HOST_HUB_CTRL_XHC_BME_RESETVAL               (0x00000001U)
#define CSL_USB3SS_HOST_HUB_CTRL_XHC_BME_MAX                    (0x00000001U)

#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_MASK      (0x000000C0U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_SHIFT     (6U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_RESETVAL  (0x00000000U)
#define CSL_USB3SS_HOST_HUB_CTRL_HUB_PORT_PERM_ATTACH_MAX       (0x00000003U)

#define CSL_USB3SS_HOST_HUB_CTRL_BUS_FILTER_BYPASS_MASK         (0x00000F00U)
#define CSL_USB3SS_HOST_HUB_CTRL_BUS_FILTER_BYPASS_SHIFT        (8U)
#define CSL_USB3SS_HOST_HUB_CTRL_BUS_FILTER_BYPASS_RESETVAL     (0x00000000U)
#define CSL_USB3SS_HOST_HUB_CTRL_BUS_FILTER_BYPASS_MAX          (0x0000000fU)

#define CSL_USB3SS_HOST_HUB_CTRL_RESETVAL                       (0x0000002cU)

/* DEBUG_THR */

#define CSL_USB3SS_DEBUG_THR_INDEX0_MASK                        (0x0000001FU)
#define CSL_USB3SS_DEBUG_THR_INDEX0_SHIFT                       (0U)
#define CSL_USB3SS_DEBUG_THR_INDEX0_RESETVAL                    (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_INDEX0_MAX                         (0x0000001fU)

#define CSL_USB3SS_DEBUG_THR_VAL0_MASK                          (0x00000020U)
#define CSL_USB3SS_DEBUG_THR_VAL0_SHIFT                         (5U)
#define CSL_USB3SS_DEBUG_THR_VAL0_RESETVAL                      (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_VAL0_MAX                           (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_EN0_MASK                           (0x00000040U)
#define CSL_USB3SS_DEBUG_THR_EN0_SHIFT                          (6U)
#define CSL_USB3SS_DEBUG_THR_EN0_RESETVAL                       (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_EN0_MAX                            (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_INDEX1_MASK                        (0x00001F00U)
#define CSL_USB3SS_DEBUG_THR_INDEX1_SHIFT                       (8U)
#define CSL_USB3SS_DEBUG_THR_INDEX1_RESETVAL                    (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_INDEX1_MAX                         (0x0000001fU)

#define CSL_USB3SS_DEBUG_THR_VAL1_MASK                          (0x00002000U)
#define CSL_USB3SS_DEBUG_THR_VAL1_SHIFT                         (13U)
#define CSL_USB3SS_DEBUG_THR_VAL1_RESETVAL                      (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_VAL1_MAX                           (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_EN1_MASK                           (0x00004000U)
#define CSL_USB3SS_DEBUG_THR_EN1_SHIFT                          (14U)
#define CSL_USB3SS_DEBUG_THR_EN1_RESETVAL                       (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_EN1_MAX                            (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_INDEX2_MASK                        (0x001F0000U)
#define CSL_USB3SS_DEBUG_THR_INDEX2_SHIFT                       (16U)
#define CSL_USB3SS_DEBUG_THR_INDEX2_RESETVAL                    (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_INDEX2_MAX                         (0x0000001fU)

#define CSL_USB3SS_DEBUG_THR_VAL2_MASK                          (0x00200000U)
#define CSL_USB3SS_DEBUG_THR_VAL2_SHIFT                         (21U)
#define CSL_USB3SS_DEBUG_THR_VAL2_RESETVAL                      (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_VAL2_MAX                           (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_EN2_MASK                           (0x00400000U)
#define CSL_USB3SS_DEBUG_THR_EN2_SHIFT                          (22U)
#define CSL_USB3SS_DEBUG_THR_EN2_RESETVAL                       (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_EN2_MAX                            (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_INDEX3_MASK                        (0x1F000000U)
#define CSL_USB3SS_DEBUG_THR_INDEX3_SHIFT                       (24U)
#define CSL_USB3SS_DEBUG_THR_INDEX3_RESETVAL                    (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_INDEX3_MAX                         (0x0000001fU)

#define CSL_USB3SS_DEBUG_THR_VAL3_MASK                          (0x20000000U)
#define CSL_USB3SS_DEBUG_THR_VAL3_SHIFT                         (29U)
#define CSL_USB3SS_DEBUG_THR_VAL3_RESETVAL                      (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_VAL3_MAX                           (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_EN3_MASK                           (0x40000000U)
#define CSL_USB3SS_DEBUG_THR_EN3_SHIFT                          (30U)
#define CSL_USB3SS_DEBUG_THR_EN3_RESETVAL                       (0x00000000U)
#define CSL_USB3SS_DEBUG_THR_EN3_MAX                            (0x00000001U)

#define CSL_USB3SS_DEBUG_THR_RESETVAL                           (0x00000000U)

/* DEV_EBC_EN */

#define CSL_USB3SS_DEV_EBC_EN_INEP14_MASK                       (0x00004000U)
#define CSL_USB3SS_DEV_EBC_EN_INEP14_SHIFT                      (14U)
#define CSL_USB3SS_DEV_EBC_EN_INEP14_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEV_EBC_EN_INEP14_MAX                        (0x00000001U)

#define CSL_USB3SS_DEV_EBC_EN_INEP15_MASK                       (0x00008000U)
#define CSL_USB3SS_DEV_EBC_EN_INEP15_SHIFT                      (15U)
#define CSL_USB3SS_DEV_EBC_EN_INEP15_RESETVAL                   (0x00000000U)
#define CSL_USB3SS_DEV_EBC_EN_INEP15_MAX                        (0x00000001U)

#define CSL_USB3SS_DEV_EBC_EN_OUTEP14_MASK                      (0x40000000U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP14_SHIFT                     (30U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP14_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP14_MAX                       (0x00000001U)

#define CSL_USB3SS_DEV_EBC_EN_OUTEP15_MASK                      (0x80000000U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP15_SHIFT                     (31U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP15_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_DEV_EBC_EN_OUTEP15_MAX                       (0x00000001U)

#define CSL_USB3SS_DEV_EBC_EN_RESETVAL                          (0x00000000U)

/* IRQ_EOI_MISC */

#define CSL_USB3SS_IRQ_EOI_MISC_EOI_MISC_MASK                   (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MISC_EOI_MISC_SHIFT                  (0U)
#define CSL_USB3SS_IRQ_EOI_MISC_EOI_MISC_RESETVAL               (0x00000000U)
#define CSL_USB3SS_IRQ_EOI_MISC_EOI_MISC_EOI                    (0x00000001U)
#define CSL_USB3SS_IRQ_EOI_MISC_EOI_MISC_NOOP                   (0x00000000U)

#define CSL_USB3SS_IRQ_EOI_MISC_RESETVAL                        (0x00000000U)

/* IRQ_STATUS_RAW_MISC */

#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_DMADISABLECLR_MASK       (0x00020000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_DMADISABLECLR_SHIFT      (17U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_DMADISABLECLR_RESETVAL   (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_DMADISABLECLR_MAX        (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_AXI_ERROR_MASK           (0x00040000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_AXI_ERROR_SHIFT          (18U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_AXI_ERROR_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_AXI_ERROR_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_TRACE_CMPL_MASK          (0x00080000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_TRACE_CMPL_SHIFT         (19U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_TRACE_CMPL_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_TRACE_CMPL_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_MISC_RESETVAL                 (0x00000000U)

/* IRQ_STATUS_MISC */

#define CSL_USB3SS_IRQ_STATUS_MISC_DMADISABLECLR_MASK           (0x00020000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_DMADISABLECLR_SHIFT          (17U)
#define CSL_USB3SS_IRQ_STATUS_MISC_DMADISABLECLR_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_DMADISABLECLR_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_MISC_AXI_ERROR_MASK               (0x00040000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_AXI_ERROR_SHIFT              (18U)
#define CSL_USB3SS_IRQ_STATUS_MISC_AXI_ERROR_RESETVAL           (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_AXI_ERROR_MAX                (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_MISC_TRACE_CMPL_MASK              (0x00080000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_TRACE_CMPL_SHIFT             (19U)
#define CSL_USB3SS_IRQ_STATUS_MISC_TRACE_CMPL_RESETVAL          (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_MISC_TRACE_CMPL_MAX               (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_MISC_RESETVAL                     (0x00000000U)

/* IRQ_ENABLE_SET_MISC */

#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_DMADISABLECLR_MASK       (0x00020000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_DMADISABLECLR_SHIFT      (17U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_DMADISABLECLR_RESETVAL   (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_DMADISABLECLR_MAX        (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_AXI_ERROR_MASK           (0x00040000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_AXI_ERROR_SHIFT          (18U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_AXI_ERROR_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_AXI_ERROR_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_TRACE_CMPL_MASK          (0x00080000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_TRACE_CMPL_SHIFT         (19U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_TRACE_CMPL_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_TRACE_CMPL_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_MISC_RESETVAL                 (0x00000000U)

/* IRQ_ENABLE_CLR_MISC */

#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_MASK       (0x00020000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_SHIFT      (17U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_RESETVAL   (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_DMADISABLECLR_MAX        (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_AXI_ERROR_MASK           (0x00040000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_AXI_ERROR_SHIFT          (18U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_AXI_ERROR_RESETVAL       (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_AXI_ERROR_MAX            (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_TRACE_CMPL_MASK          (0x00080000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_TRACE_CMPL_SHIFT         (19U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_TRACE_CMPL_RESETVAL      (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_TRACE_CMPL_MAX           (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_MISC_RESETVAL                 (0x00000000U)

/* IRQ_STATUS_RAW_MAIN */

#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN_IRQ_STATUS_RAW_MAIN_MASK  (0x00000001U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN_IRQ_STATUS_RAW_MAIN_SHIFT  (0U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN_IRQ_STATUS_RAW_MAIN_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN_IRQ_STATUS_RAW_MAIN_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_RAW_MAIN_RESETVAL                 (0x00000000U)

/* IRQ_STATUS_MAIN */

#define CSL_USB3SS_IRQ_STATUS_MAIN_IRQ_STATUS_MAIN_MASK         (0x00000001U)
#define CSL_USB3SS_IRQ_STATUS_MAIN_IRQ_STATUS_MAIN_SHIFT        (0U)
#define CSL_USB3SS_IRQ_STATUS_MAIN_IRQ_STATUS_MAIN_RESETVAL     (0x00000000U)
#define CSL_USB3SS_IRQ_STATUS_MAIN_IRQ_STATUS_MAIN_MAX          (0x00000001U)

#define CSL_USB3SS_IRQ_STATUS_MAIN_RESETVAL                     (0x00000000U)

/* IRQ_ENABLE_SET_MAIN */

#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN_IRQ_ENABLE_SET_MAIN_MASK  (0x00000001U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN_IRQ_ENABLE_SET_MAIN_SHIFT  (0U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN_IRQ_ENABLE_SET_MAIN_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN_IRQ_ENABLE_SET_MAIN_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_SET_MAIN_RESETVAL                 (0x00000000U)

/* IRQ_ENABLE_CLR_MAIN */

#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_IRQ_ENABLE_CLR_MAIN_MASK  (0x00000001U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_IRQ_ENABLE_CLR_MAIN_SHIFT  (0U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_IRQ_ENABLE_CLR_MAIN_RESETVAL  (0x00000000U)
#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_IRQ_ENABLE_CLR_MAIN_MAX  (0x00000001U)

#define CSL_USB3SS_IRQ_ENABLE_CLR_MAIN_RESETVAL                 (0x00000000U)

/* SER_CONTROL */

#define CSL_USB3SS_SER_CONTROL_PAR_EN_MASK                      (0x00000001U)
#define CSL_USB3SS_SER_CONTROL_PAR_EN_SHIFT                     (0U)
#define CSL_USB3SS_SER_CONTROL_PAR_EN_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_SER_CONTROL_PAR_EN_MAX                       (0x00000001U)

#define CSL_USB3SS_SER_CONTROL_BEC_EN_MASK                      (0x00000006U)
#define CSL_USB3SS_SER_CONTROL_BEC_EN_SHIFT                     (1U)
#define CSL_USB3SS_SER_CONTROL_BEC_EN_RESETVAL                  (0x00000002U)
#define CSL_USB3SS_SER_CONTROL_BEC_EN_MAX                       (0x00000003U)

#define CSL_USB3SS_SER_CONTROL_RESETVAL                         (0x00000004U)

/* SER_STATUS */

#define CSL_USB3SS_SER_STATUS_PAR_ERR_MASK                      (0x00000001U)
#define CSL_USB3SS_SER_STATUS_PAR_ERR_SHIFT                     (0U)
#define CSL_USB3SS_SER_STATUS_PAR_ERR_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_SER_STATUS_PAR_ERR_MAX                       (0x00000001U)

#define CSL_USB3SS_SER_STATUS_BEC_ERR_MASK                      (0x00000002U)
#define CSL_USB3SS_SER_STATUS_BEC_ERR_SHIFT                     (1U)
#define CSL_USB3SS_SER_STATUS_BEC_ERR_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_SER_STATUS_BEC_ERR_MAX                       (0x00000001U)

#define CSL_USB3SS_SER_STATUS_TYPE_ERR_MASK                     (0x0000000CU)
#define CSL_USB3SS_SER_STATUS_TYPE_ERR_SHIFT                    (2U)
#define CSL_USB3SS_SER_STATUS_TYPE_ERR_RESETVAL                 (0x00000000U)
#define CSL_USB3SS_SER_STATUS_TYPE_ERR_MAX                      (0x00000003U)

#define CSL_USB3SS_SER_STATUS_BYTE_POS_MASK                     (0x00000700U)
#define CSL_USB3SS_SER_STATUS_BYTE_POS_SHIFT                    (8U)
#define CSL_USB3SS_SER_STATUS_BYTE_POS_RESETVAL                 (0x00000000U)
#define CSL_USB3SS_SER_STATUS_BYTE_POS_MAX                      (0x00000007U)

#define CSL_USB3SS_SER_STATUS_ADDR_VALID_MASK                   (0x00004000U)
#define CSL_USB3SS_SER_STATUS_ADDR_VALID_SHIFT                  (14U)
#define CSL_USB3SS_SER_STATUS_ADDR_VALID_RESETVAL               (0x00000000U)
#define CSL_USB3SS_SER_STATUS_ADDR_VALID_MAX                    (0x00000001U)

#define CSL_USB3SS_SER_STATUS_RAM_ERR_MASK                      (0x0FFF0000U)
#define CSL_USB3SS_SER_STATUS_RAM_ERR_SHIFT                     (16U)
#define CSL_USB3SS_SER_STATUS_RAM_ERR_RESETVAL                  (0x00000000U)
#define CSL_USB3SS_SER_STATUS_RAM_ERR_MAX                       (0x00000fffU)

#define CSL_USB3SS_SER_STATUS_RESETVAL                          (0x00000000U)

/* SER_ADDRESS */

#define CSL_USB3SS_SER_ADDRESS_ADDR_ERR_MASK                    (0xFFFFFFFFU)
#define CSL_USB3SS_SER_ADDRESS_ADDR_ERR_SHIFT                   (0U)
#define CSL_USB3SS_SER_ADDRESS_ADDR_ERR_RESETVAL                (0x00000000U)
#define CSL_USB3SS_SER_ADDRESS_ADDR_ERR_MAX                     (0xffffffffU)

#define CSL_USB3SS_SER_ADDRESS_RESETVAL                         (0x00000000U)

/* PHY2CONFIG */

#define CSL_USB3SS_PHY2CONFIG_ULPI_UTMI_MODE_MASK               (0x00000010U)
#define CSL_USB3SS_PHY2CONFIG_ULPI_UTMI_MODE_SHIFT              (4U)
#define CSL_USB3SS_PHY2CONFIG_ULPI_UTMI_MODE_RESETVAL           (0x00000000U)
#define CSL_USB3SS_PHY2CONFIG_ULPI_UTMI_MODE_MAX                (0x00000001U)

#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_EN_MASK                  (0x00000001U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_EN_SHIFT                 (0U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_EN_RESETVAL              (0x00000000U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_EN_MAX                   (0x00000001U)

#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_VAL_MASK                 (0x00000002U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_VAL_SHIFT                (1U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_VAL_RESETVAL             (0x00000000U)
#define CSL_USB3SS_PHY2CONFIG_IDPULLUP_VAL_MAX                  (0x00000001U)

#define CSL_USB3SS_PHY2CONFIG_RESETVAL                          (0x00000000U)

/* PHY3CONFIG */

#define CSL_USB3SS_PHY3CONFIG_PHY3CONFIG_MASK                   (0xFFFFFFFFU)
#define CSL_USB3SS_PHY3CONFIG_PHY3CONFIG_SHIFT                  (0U)
#define CSL_USB3SS_PHY3CONFIG_PHY3CONFIG_RESETVAL               (0x00000000U)
#define CSL_USB3SS_PHY3CONFIG_PHY3CONFIG_MAX                    (0xffffffffU)

#define CSL_USB3SS_PHY3CONFIG_RESETVAL                          (0x00000000U)

/* USBCONFIG */

#define CSL_USB3SS_USBCONFIG_ENDIANMODE_MASK                    (0x00000003U)
#define CSL_USB3SS_USBCONFIG_ENDIANMODE_SHIFT                   (0U)
#define CSL_USB3SS_USBCONFIG_ENDIANMODE_RESETVAL                (0x00000002U)
#define CSL_USB3SS_USBCONFIG_ENDIANMODE_MAX                     (0x00000003U)

#define CSL_USB3SS_USBCONFIG_RESETVAL                           (0x00000002U)

#ifdef __cplusplus
}
#endif
#endif
