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
#ifndef CSLR_DWCAHSATA_H_
#define CSLR_DWCAHSATA_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for PortRegisters_block
**************************************************************************/
typedef struct {
    volatile Uint32 PXCLB;
    volatile Uint32 PXCLBU;
    volatile Uint32 PXFB;
    volatile Uint32 PXFBU;
    volatile Uint32 PXIS;
    volatile Uint32 PXIE;
    volatile Uint32 PXCMD;
    volatile Uint8  RSVD0[4];
    volatile Uint32 PXTFD;
    volatile Uint32 PXSIG;
    volatile Uint32 PXSSTS;
    volatile Uint32 PXSCTL;
    volatile Uint32 PXSERR;
    volatile Uint32 PXSACT;
    volatile Uint32 PXCI;
    volatile Uint32 PXSNTF;
    volatile Uint8  RSVD1[48];
    volatile Uint32 PXDMACR;
    volatile Uint8  RSVD2[12];
} CSL_DwcahsataPortregisters_blockRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 CAP;
    volatile Uint32 GHC;
    volatile Uint32 IS;
    volatile Uint32 PI;
    volatile Uint32 VS;
    volatile Uint32 CCC_CTL;
    volatile Uint32 CCC_PORTS;
    volatile Uint8  RSVD3[8];
    volatile Uint32 CAP2;
    volatile Uint8  RSVD4[120];
    volatile Uint32 BISTAFR;
    volatile Uint32 BISTCR;
    volatile Uint32 BISTFCTR;
    volatile Uint32 BISTSR;
    volatile Uint32 BISTDECR;
    volatile Uint8  RSVD5[8];
    volatile Uint32 OOBR;
    volatile Uint8  RSVD6[32];
    volatile Uint32 TIMER1MS;
    volatile Uint8  RSVD7[4];
    volatile Uint32 GPARAM1R;
    volatile Uint32 GPARAM2R;
    volatile Uint32 PPARAMR;
    volatile Uint32 TESTR;
    volatile Uint32 VERSIONR;
    volatile Uint32 IDR;
    CSL_DwcahsataPortregisters_blockRegs	PORTREGISTERS_BLOCK;
} CSL_DwcAhsataRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Capabilities register: Basic capabilities of the SATA AHCI core Some fields 
 * can be written once after reset, read-only */
#define CSL_DWCAHSATA_CAP                                       (0x0U)

/* Global HBA Control */
#define CSL_DWCAHSATA_GHC                                       (0x4U)

/* Interrupt Status Indicates which port has a pending interrupt. */
#define CSL_DWCAHSATA_IS                                        (0x8U)

/* Ports Implemented Indicates which ports are exposed by the SATA controller 
 * and are available for use. */
#define CSL_DWCAHSATA_PI                                        (0xCU)

/* AHCI Version Supported: 1.3 WARNING: Controller complies fully with AHCI 
 * version 1.10, and complies with AHCI version 1.3 except for FIS-based 
 * switching, which is not currently supported. */
#define CSL_DWCAHSATA_VS                                        (0x10U)

/* Command Completion Coalescing Control Used to configure the command 
 * completion coalescing (CCC) feature for the SATA controller. Reset upon 
 * Global Reset. */
#define CSL_DWCAHSATA_CCC_CTL                                   (0x14U)

/* Command Completion Coalescing Ports Specifies the Ports that are coalesced 
 * as part of the command completion coalescing (CCC) feature when 
 * CCC_CTL.EN=1. Reset upon Global Reset. */
#define CSL_DWCAHSATA_CCC_PORTS                                 (0x18U)

/* Built-In Self Test Activate FIS Register. Reset upon Global Reset or Port 
 * Reset. */
#define CSL_DWCAHSATA_BISTAFR                                   (0xA0U)

/* Built-In Self Test Control Register Reset upon Global Reset or Port Reset. */
#define CSL_DWCAHSATA_BISTCR                                    (0xA4U)

/* Built-In Self Test Frame-information-structure CounT Register Received BIST 
 * FIS count in the loopback initiator far-end retimed, far-end analog and 
 * near-end analog modes. Updated each time a new BIST FIS is received. Reset 
 * by Global Reset, Port Reset (COMRESET) or by writing 1 to BISTCR.CNTCLR. 
 * Does not roll over, and freezes when the FFFF_FFFFh value is reached. It 
 * takes approximately 65 hours of continuous BIST operation to reach this 
 * value. */
#define CSL_DWCAHSATA_BISTFCTR                                  (0xA8U)

/* Built-In Self Test Status Register Errors detected in the received BIST FIS 
 * in the loopback initiator far-end retimed, far-end analog and near-end 
 * analog modes. Updated each time a new BIST FIS is received. Reset upon 
 * Global Reset, Port Reset (COMRESET) or by writing 1 to BISTCR.CNTCLR */
#define CSL_DWCAHSATA_BISTSR                                    (0xACU)

/* Built-In Self Test Double-word Error Count Register Number of DWORD errors 
 * detected in the received BIST frame in the loopback initiator far-end 
 * retimed, far-end analog and near-end analog modes. Updated each time a new 
 * BIST frame is received, when the parameter BIST_MODE=“DWORD”. Reset upon 
 * Global Reset, Port Reset (COMRESET) or by writing 1 to BISTCR.CNTCLR. */
#define CSL_DWCAHSATA_BISTDECR                                  (0xB0U)

/* Out Of Band Register Controls the Link layer OOB detection counters. */
#define CSL_DWCAHSATA_OOBR                                      (0xBCU)

/* Timer 1ms Configuration to generate the 1ms tick for the command completion 
 * coalescing (CCC) logic. Must be initialized before using the CCC feature. 
 * Reset upon power up, not affected by Global Reset. */
#define CSL_DWCAHSATA_TIMER1MS                                  (0xE0U)

/* Global Parameters Register 1 HW configuration of the DWC AHCI SATA Core. */
#define CSL_DWCAHSATA_GPARAM1R                                  (0xE8U)

/* Global Parameters Register 2 HW configuration of the DWC AHCI SATA Core, 
 * continued. */
#define CSL_DWCAHSATA_GPARAM2R                                  (0xECU)

/* Port Parameter Register HW configuration of the DWC AHCI SATA Core port 
 * selected by TESTR.PSEL */
#define CSL_DWCAHSATA_PPARAMR                                   (0xF0U)

/* Test Register Puts the SATA controller slave interface into a test mode and 
 * selects a port for BIST operation. */
#define CSL_DWCAHSATA_TESTR                                     (0xF4U)

/* Version Register */
#define CSL_DWCAHSATA_VERSIONR                                  (0xF8U)

/* ID Register, contained the 32-bit Highlander (HL) revision. */
#define CSL_DWCAHSATA_IDR                                       (0xFCU)

/* Extended Capabilities */
#define CSL_DWCAHSATA_CAP2                                      (0x24U)

/* Port Command List Base address 32-bit base physical address for the command 
 * list for this Port. Used when fetching commands to execute. The structure 
 * pointed to by this address range is 1 KB in length. */
#define CSL_DWCAHSATA_PXCLB                                     (0x100U)

/* Port Frame-information-structure Base address 32-bit base physical address 
 * for received FISes for this port. The structure pointed to by this address 
 * range is 256 bytes in length. */
#define CSL_DWCAHSATA_PXFB                                      (0x108U)

/* Port Interrupt Status Bits are set by internal conditions, and cleared 
 * (when possible) by writing 1 to them. Reset upon Global Reset. */
#define CSL_DWCAHSATA_PXIS                                      (0x110U)

/* Port Interrupt Enable Enables and disables the reporting of the 
 * corresponding interrupt to system software. When a bit is set (1), 
 * GHC.IE=1, and the corresponding interrupt condition in PxIS is active, then 
 * the SATA controller interrupt output is asserted. When a bit is cleared 
 * (0), interrupt sources are still reflected in the status registers. Reset 
 * upon Global Reset. */
#define CSL_DWCAHSATA_PXIE                                      (0x114U)

/* Port Command */
#define CSL_DWCAHSATA_PXCMD                                     (0x118U)

/* Port Task File Data: copies specific fields of the task file when FISes are 
 * received */
#define CSL_DWCAHSATA_PXTFD                                     (0x120U)

/* Port Signature: signature received from a device on the first D2H Register 
 * FIS. Updated once after a reset sequence. */
#define CSL_DWCAHSATA_PXSIG                                     (0x124U)

/* Port SATA Status Current state of the interface and host. Updated 
 * continuously and asynchronously. When the Port transmits a COMRESET to the 
 * device, this register is updated to its reset values (i.e., Global Reset, 
 * Port Reset, or COMINIT from the device) */
#define CSL_DWCAHSATA_PXSSTS                                    (0x128U)

/* Port SATA Control Control of SATA interface capabilities. Writes to this 
 * register result in an action being taken by the Port PHY interface. Reads 
 * from the register return the last value written to it. Reset upon Global 
 * Reset. Wait for at least seven periods of the slower clock (OCP or parallel 
 * serdes clock) between writes, due to the internal clock domain crossing 
 * between the Transport (OCP) and Link (serdes i/f) Layers. */
#define CSL_DWCAHSATA_PXSCTL                                    (0x12CU)

/* Port SATA Error Detected interface errors accumulated since the last time 
 * it was cleared. When set, indicates that the corresponding error condition 
 * became true one or more times since the last time it was cleared. Write 1 
 * to a bit to clear it. Cleared by Global Reset or Port Reset (COMRESET). */
#define CSL_DWCAHSATA_PXSERR                                    (0x130U)

/* Port SATA Active (SActive): Indicates which command slots contain commands */
#define CSL_DWCAHSATA_PXSACT                                    (0x134U)

/* Port Command Issue: Indicates that a command has been constructed and may 
 * be carried out */
#define CSL_DWCAHSATA_PXCI                                      (0x138U)

/* Port SATA Notification: Used to determine if asynchronous notification 
 * events have occurred for directly connected devices and devices connected 
 * to a Port Multiplier. */
#define CSL_DWCAHSATA_PXSNTF                                    (0x13CU)

/* Port DMA Control Register. Not AHCI-standard. Writable only when PxCMD.ST=0 
 * Attempts to write a field value less than the minimum or more than the 
 * maximum cause the field to be set to the minimum or the maximum. Reset upon 
 * Global Reset and Port Reset (COMRESET). */
#define CSL_DWCAHSATA_PXDMACR                                   (0x170U)

/* Port Command List Base Upper address Upper half of the 64-bit base physical 
 * address for the command list for this Port. Used when fetching commands to 
 * execute. Remains all 0 when in 32-bit mode. Reserved & read-only when 
 * CAP.S64A=0 */
#define CSL_DWCAHSATA_PXCLBU                                    (0x104U)

/* FIS Base Upper Address Upper half of the 64-bit base physical address for 
 * received FISes for this port. Remains all 0 with a 32-bit SW driver. 
 * Reserved & read-only when CAP.S64A=0 */
#define CSL_DWCAHSATA_PXFBU                                     (0x10CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CAP */

#define CSL_DWCAHSATA_CAP_NP_MASK                               (0x0000001FU)
#define CSL_DWCAHSATA_CAP_NP_SHIFT                              (0U)
#define CSL_DWCAHSATA_CAP_NP_RESETVAL                           (0x00000000U)
#define CSL_DWCAHSATA_CAP_NP_MAX                                (0x0000001fU)

#define CSL_DWCAHSATA_CAP_SXS_MASK                              (0x00000020U)
#define CSL_DWCAHSATA_CAP_SXS_SHIFT                             (5U)
#define CSL_DWCAHSATA_CAP_SXS_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_CAP_SXS_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SXS_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_EMS_MASK                              (0x00000040U)
#define CSL_DWCAHSATA_CAP_EMS_SHIFT                             (6U)
#define CSL_DWCAHSATA_CAP_EMS_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_CAP_EMS_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_EMS_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_CCCS_MASK                             (0x00000080U)
#define CSL_DWCAHSATA_CAP_CCCS_SHIFT                            (7U)
#define CSL_DWCAHSATA_CAP_CCCS_RESETVAL                         (0x00000001U)
#define CSL_DWCAHSATA_CAP_CCCS_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_CCCS_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_NCS_MASK                              (0x00001F00U)
#define CSL_DWCAHSATA_CAP_NCS_SHIFT                             (8U)
#define CSL_DWCAHSATA_CAP_NCS_RESETVAL                          (0x0000001fU)
#define CSL_DWCAHSATA_CAP_NCS_MAX                               (0x0000001fU)

#define CSL_DWCAHSATA_CAP_PSC_MASK                              (0x00002000U)
#define CSL_DWCAHSATA_CAP_PSC_SHIFT                             (13U)
#define CSL_DWCAHSATA_CAP_PSC_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_PSC_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_PSC_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_SSC_MASK                              (0x00004000U)
#define CSL_DWCAHSATA_CAP_SSC_SHIFT                             (14U)
#define CSL_DWCAHSATA_CAP_SSC_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_SSC_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SSC_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_PMD_MASK                              (0x00008000U)
#define CSL_DWCAHSATA_CAP_PMD_SHIFT                             (15U)
#define CSL_DWCAHSATA_CAP_PMD_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_PMD_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_PMD_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_SPM_MASK                              (0x00020000U)
#define CSL_DWCAHSATA_CAP_SPM_SHIFT                             (17U)
#define CSL_DWCAHSATA_CAP_SPM_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_SPM_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SPM_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_SAM_MASK                              (0x00040000U)
#define CSL_DWCAHSATA_CAP_SAM_SHIFT                             (18U)
#define CSL_DWCAHSATA_CAP_SAM_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_SAM_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SAM_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_ISS_MASK                              (0x00F00000U)
#define CSL_DWCAHSATA_CAP_ISS_SHIFT                             (20U)
#define CSL_DWCAHSATA_CAP_ISS_RESETVAL                          (0x00000002U)
#define CSL_DWCAHSATA_CAP_ISS_MAX                               (0x0000000fU)

#define CSL_DWCAHSATA_CAP_SCLO_MASK                             (0x01000000U)
#define CSL_DWCAHSATA_CAP_SCLO_SHIFT                            (24U)
#define CSL_DWCAHSATA_CAP_SCLO_RESETVAL                         (0x00000001U)
#define CSL_DWCAHSATA_CAP_SCLO_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_SCLO_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_SAL_MASK                              (0x02000000U)
#define CSL_DWCAHSATA_CAP_SAL_SHIFT                             (25U)
#define CSL_DWCAHSATA_CAP_SAL_RESETVAL                          (0x00000001U)
#define CSL_DWCAHSATA_CAP_SAL_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SAL_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_SALP_MASK                             (0x04000000U)
#define CSL_DWCAHSATA_CAP_SALP_SHIFT                            (26U)
#define CSL_DWCAHSATA_CAP_SALP_RESETVAL                         (0x00000001U)
#define CSL_DWCAHSATA_CAP_SALP_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_SALP_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_SSS_MASK                              (0x08000000U)
#define CSL_DWCAHSATA_CAP_SSS_SHIFT                             (27U)
#define CSL_DWCAHSATA_CAP_SSS_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_CAP_SSS_NO                                (0x00000000U)
#define CSL_DWCAHSATA_CAP_SSS_YES                               (0x00000001U)

#define CSL_DWCAHSATA_CAP_SMPS_MASK                             (0x10000000U)
#define CSL_DWCAHSATA_CAP_SMPS_SHIFT                            (28U)
#define CSL_DWCAHSATA_CAP_SMPS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_CAP_SMPS_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_SMPS_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_SSNTF_MASK                            (0x20000000U)
#define CSL_DWCAHSATA_CAP_SSNTF_SHIFT                           (29U)
#define CSL_DWCAHSATA_CAP_SSNTF_RESETVAL                        (0x00000001U)
#define CSL_DWCAHSATA_CAP_SSNTF_NO                              (0x00000000U)
#define CSL_DWCAHSATA_CAP_SSNTF_YES                             (0x00000001U)

#define CSL_DWCAHSATA_CAP_SNCQ_MASK                             (0x40000000U)
#define CSL_DWCAHSATA_CAP_SNCQ_SHIFT                            (30U)
#define CSL_DWCAHSATA_CAP_SNCQ_RESETVAL                         (0x00000001U)
#define CSL_DWCAHSATA_CAP_SNCQ_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_SNCQ_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_S64A_MASK                             (0x80000000U)
#define CSL_DWCAHSATA_CAP_S64A_SHIFT                            (31U)
#define CSL_DWCAHSATA_CAP_S64A_RESETVAL                         (0x00000001U)
#define CSL_DWCAHSATA_CAP_S64A__32BIT                           (0x00000000U)
#define CSL_DWCAHSATA_CAP_S64A__64BIT                           (0x00000001U)

#define CSL_DWCAHSATA_CAP_FBSS_MASK                             (0x00010000U)
#define CSL_DWCAHSATA_CAP_FBSS_SHIFT                            (16U)
#define CSL_DWCAHSATA_CAP_FBSS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_CAP_FBSS_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_FBSS_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_SNZO_MASK                             (0x00080000U)
#define CSL_DWCAHSATA_CAP_SNZO_SHIFT                            (19U)
#define CSL_DWCAHSATA_CAP_SNZO_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_CAP_SNZO_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP_SNZO_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP_RESETVAL                              (0xe726ff80U)

/* GHC */

#define CSL_DWCAHSATA_GHC_HR_MASK                               (0x00000001U)
#define CSL_DWCAHSATA_GHC_HR_SHIFT                              (0U)
#define CSL_DWCAHSATA_GHC_HR_RESETVAL                           (0x00000000U)
#define CSL_DWCAHSATA_GHC_HR_NOACTION                           (0x00000000U)
#define CSL_DWCAHSATA_GHC_HR_RESET                              (0x00000001U)
#define CSL_DWCAHSATA_GHC_HR_DONE                               (0x00000000U)
#define CSL_DWCAHSATA_GHC_HR_ONGOING                            (0x00000001U)

#define CSL_DWCAHSATA_GHC_IE_MASK                               (0x00000002U)
#define CSL_DWCAHSATA_GHC_IE_SHIFT                              (1U)
#define CSL_DWCAHSATA_GHC_IE_RESETVAL                           (0x00000000U)
#define CSL_DWCAHSATA_GHC_IE_DIS                                (0x00000000U)
#define CSL_DWCAHSATA_GHC_IE_EN                                 (0x00000001U)

#define CSL_DWCAHSATA_GHC_AE_MASK                               (0x80000000U)
#define CSL_DWCAHSATA_GHC_AE_SHIFT                              (31U)
#define CSL_DWCAHSATA_GHC_AE_RESETVAL                           (0x00000001U)
#define CSL_DWCAHSATA_GHC_AE_MAX                                (0x00000001U)

#define CSL_DWCAHSATA_GHC_RESETVAL                              (0x80000000U)

/* IS */

#define CSL_DWCAHSATA_IS_IPS_MASK                               (0x00000001U)
#define CSL_DWCAHSATA_IS_IPS_SHIFT                              (0U)
#define CSL_DWCAHSATA_IS_IPS_RESETVAL                           (0x00000000U)
#define CSL_DWCAHSATA_IS_IPS_MAX                                (0x00000001U)

#define CSL_DWCAHSATA_IS_RESETVAL                               (0x00000000U)

/* PI */

#define CSL_DWCAHSATA_PI_PI_MASK                                (0x00000001U)
#define CSL_DWCAHSATA_PI_PI_SHIFT                               (0U)
#define CSL_DWCAHSATA_PI_PI_RESETVAL                            (0x00000000U)
#define CSL_DWCAHSATA_PI_PI_MAX                                 (0x00000001U)

#define CSL_DWCAHSATA_PI_RESETVAL                               (0x00000000U)

/* VS */

#define CSL_DWCAHSATA_VS_MNR_MASK                               (0x0000FFFFU)
#define CSL_DWCAHSATA_VS_MNR_SHIFT                              (0U)
#define CSL_DWCAHSATA_VS_MNR_RESETVAL                           (0x00000300U)
#define CSL_DWCAHSATA_VS_MNR_MAX                                (0x0000ffffU)

#define CSL_DWCAHSATA_VS_MJR_MASK                               (0xFFFF0000U)
#define CSL_DWCAHSATA_VS_MJR_SHIFT                              (16U)
#define CSL_DWCAHSATA_VS_MJR_RESETVAL                           (0x00000001U)
#define CSL_DWCAHSATA_VS_MJR_MAX                                (0x0000ffffU)

#define CSL_DWCAHSATA_VS_RESETVAL                               (0x00010300U)

/* CCC_CTL */

#define CSL_DWCAHSATA_CCC_CTL_EN_MASK                           (0x00000001U)
#define CSL_DWCAHSATA_CCC_CTL_EN_SHIFT                          (0U)
#define CSL_DWCAHSATA_CCC_CTL_EN_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_CCC_CTL_EN_DIS                            (0x00000000U)
#define CSL_DWCAHSATA_CCC_CTL_EN_EN                             (0x00000001U)

#define CSL_DWCAHSATA_CCC_CTL_INT_MASK                          (0x000000F8U)
#define CSL_DWCAHSATA_CCC_CTL_INT_SHIFT                         (3U)
#define CSL_DWCAHSATA_CCC_CTL_INT_RESETVAL                      (0x00000001U)
#define CSL_DWCAHSATA_CCC_CTL_INT_MAX                           (0x0000001fU)

#define CSL_DWCAHSATA_CCC_CTL_CC_MASK                           (0x0000FF00U)
#define CSL_DWCAHSATA_CCC_CTL_CC_SHIFT                          (8U)
#define CSL_DWCAHSATA_CCC_CTL_CC_RESETVAL                       (0x00000001U)
#define CSL_DWCAHSATA_CCC_CTL_CC_MAX                            (0x000000ffU)

#define CSL_DWCAHSATA_CCC_CTL_TV_MASK                           (0xFFFF0000U)
#define CSL_DWCAHSATA_CCC_CTL_TV_SHIFT                          (16U)
#define CSL_DWCAHSATA_CCC_CTL_TV_RESETVAL                       (0x00000001U)
#define CSL_DWCAHSATA_CCC_CTL_TV_MAX                            (0x0000ffffU)

#define CSL_DWCAHSATA_CCC_CTL_RESETVAL                          (0x00010108U)

/* CCC_PORTS */

#define CSL_DWCAHSATA_CCC_PORTS_PRT_MASK                        (0x00000001U)
#define CSL_DWCAHSATA_CCC_PORTS_PRT_SHIFT                       (0U)
#define CSL_DWCAHSATA_CCC_PORTS_PRT_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_CCC_PORTS_PRT_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_CCC_PORTS_RESETVAL                        (0x00000000U)

/* BISTAFR */

#define CSL_DWCAHSATA_BISTAFR_PD_MASK                           (0x000000FFU)
#define CSL_DWCAHSATA_BISTAFR_PD_SHIFT                          (0U)
#define CSL_DWCAHSATA_BISTAFR_PD_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_BISTAFR_PD_MAX                            (0x000000ffU)

#define CSL_DWCAHSATA_BISTAFR_NCP_MASK                          (0x0000FF00U)
#define CSL_DWCAHSATA_BISTAFR_NCP_SHIFT                         (8U)
#define CSL_DWCAHSATA_BISTAFR_NCP_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_BISTAFR_NCP_MAX                           (0x000000ffU)

#define CSL_DWCAHSATA_BISTAFR_RESETVAL                          (0x00000000U)

/* BISTCR */

#define CSL_DWCAHSATA_BISTCR_PATTERN_MASK                       (0x0000000FU)
#define CSL_DWCAHSATA_BISTCR_PATTERN_SHIFT                      (0U)
#define CSL_DWCAHSATA_BISTCR_PATTERN_RESETVAL                   (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_PATTERN_MAX                        (0x0000000fU)

#define CSL_DWCAHSATA_BISTCR_PV_MASK                            (0x00000010U)
#define CSL_DWCAHSATA_BISTCR_PV_SHIFT                           (4U)
#define CSL_DWCAHSATA_BISTCR_PV_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_PV_SHORT                           (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_PV_LONG                            (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_FLIP_MASK                          (0x00000020U)
#define CSL_DWCAHSATA_BISTCR_FLIP_SHIFT                         (5U)
#define CSL_DWCAHSATA_BISTCR_FLIP_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_FLIP_MAX                           (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_ERREN_MASK                         (0x00000040U)
#define CSL_DWCAHSATA_BISTCR_ERREN_SHIFT                        (6U)
#define CSL_DWCAHSATA_BISTCR_ERREN_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_ERREN_FILTER                       (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_ERREN_ALLOW                        (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_LLC_SCRAM_MASK                     (0x00000100U)
#define CSL_DWCAHSATA_BISTCR_LLC_SCRAM_SHIFT                    (8U)
#define CSL_DWCAHSATA_BISTCR_LLC_SCRAM_RESETVAL                 (0x00000001U)
#define CSL_DWCAHSATA_BISTCR_LLC_SCRAM__0                       (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_LLC_SCRAM__1                       (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_SDFE_MASK                          (0x00001000U)
#define CSL_DWCAHSATA_BISTCR_SDFE_SHIFT                         (12U)
#define CSL_DWCAHSATA_BISTCR_SDFE_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_SDFE_DIS                           (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_SDFE_EN                            (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_NEALB_MASK                         (0x00010000U)
#define CSL_DWCAHSATA_BISTCR_NEALB_SHIFT                        (16U)
#define CSL_DWCAHSATA_BISTCR_NEALB_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_NEALB_NOACTION                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_NEALB_ACTION                       (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_CNTCLR_MASK                        (0x00020000U)
#define CSL_DWCAHSATA_BISTCR_CNTCLR_SHIFT                       (17U)
#define CSL_DWCAHSATA_BISTCR_CNTCLR_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_CNTCLR_NOACTION                    (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_CNTCLR_ACTION                      (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_TXO_MASK                           (0x00040000U)
#define CSL_DWCAHSATA_BISTCR_TXO_SHIFT                          (18U)
#define CSL_DWCAHSATA_BISTCR_TXO_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_TXO_NOACTION                       (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_TXO_ACTION                         (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_FERLB_MASK                         (0x00100000U)
#define CSL_DWCAHSATA_BISTCR_FERLB_SHIFT                        (20U)
#define CSL_DWCAHSATA_BISTCR_FERLB_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_FERLB_NOACTION                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_FERLB_ACTION                       (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_LLC_DESCRAM_MASK                   (0x00000200U)
#define CSL_DWCAHSATA_BISTCR_LLC_DESCRAM_SHIFT                  (9U)
#define CSL_DWCAHSATA_BISTCR_LLC_DESCRAM_RESETVAL               (0x00000001U)
#define CSL_DWCAHSATA_BISTCR_LLC_DESCRAM__0                     (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_LLC_DESCRAM__1                     (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_LLC_RPD_MASK                       (0x00000400U)
#define CSL_DWCAHSATA_BISTCR_LLC_RPD_SHIFT                      (10U)
#define CSL_DWCAHSATA_BISTCR_LLC_RPD_RESETVAL                   (0x00000001U)
#define CSL_DWCAHSATA_BISTCR_LLC_RPD__0                         (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_LLC_RPD__1                         (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_ERRLOSSEN_MASK                     (0x00002000U)
#define CSL_DWCAHSATA_BISTCR_ERRLOSSEN_SHIFT                    (13U)
#define CSL_DWCAHSATA_BISTCR_ERRLOSSEN_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_ERRLOSSEN_MAX                      (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_LLB_MASK                           (0x00008000U)
#define CSL_DWCAHSATA_BISTCR_LLB_SHIFT                          (15U)
#define CSL_DWCAHSATA_BISTCR_LLB_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_BISTCR_LLB_MAX                            (0x00000001U)

#define CSL_DWCAHSATA_BISTCR_RESETVAL                           (0x00000700U)

/* BISTFCTR */

#define CSL_DWCAHSATA_BISTFCTR_COUNT_MASK                       (0xFFFFFFFFU)
#define CSL_DWCAHSATA_BISTFCTR_COUNT_SHIFT                      (0U)
#define CSL_DWCAHSATA_BISTFCTR_COUNT_RESETVAL                   (0x00000000U)
#define CSL_DWCAHSATA_BISTFCTR_COUNT_MAX                        (0xffffffffU)

#define CSL_DWCAHSATA_BISTFCTR_RESETVAL                         (0x00000000U)

/* BISTSR */

#define CSL_DWCAHSATA_BISTSR_FRAMERR_MASK                       (0x0000FFFFU)
#define CSL_DWCAHSATA_BISTSR_FRAMERR_SHIFT                      (0U)
#define CSL_DWCAHSATA_BISTSR_FRAMERR_RESETVAL                   (0x00000000U)
#define CSL_DWCAHSATA_BISTSR_FRAMERR_MAX                        (0x0000ffffU)

#define CSL_DWCAHSATA_BISTSR_BRSTERR_MASK                       (0x00FF0000U)
#define CSL_DWCAHSATA_BISTSR_BRSTERR_SHIFT                      (16U)
#define CSL_DWCAHSATA_BISTSR_BRSTERR_RESETVAL                   (0x00000000U)
#define CSL_DWCAHSATA_BISTSR_BRSTERR_MAX                        (0x000000ffU)

#define CSL_DWCAHSATA_BISTSR_RESETVAL                           (0x00000000U)

/* BISTDECR */

#define CSL_DWCAHSATA_BISTDECR_DWERR_MASK                       (0xFFFFFFFFU)
#define CSL_DWCAHSATA_BISTDECR_DWERR_SHIFT                      (0U)
#define CSL_DWCAHSATA_BISTDECR_DWERR_RESETVAL                   (0x00000000U)
#define CSL_DWCAHSATA_BISTDECR_DWERR_MAX                        (0xffffffffU)

#define CSL_DWCAHSATA_BISTDECR_RESETVAL                         (0x00000000U)

/* OOBR */

#define CSL_DWCAHSATA_OOBR_CIMAX_MASK                           (0x000000FFU)
#define CSL_DWCAHSATA_OOBR_CIMAX_SHIFT                          (0U)
#define CSL_DWCAHSATA_OOBR_CIMAX_RESETVAL                       (0x00000040U)
#define CSL_DWCAHSATA_OOBR_CIMAX_MAX                            (0x000000ffU)

#define CSL_DWCAHSATA_OOBR_CIMIN_MASK                           (0x0000FF00U)
#define CSL_DWCAHSATA_OOBR_CIMIN_SHIFT                          (8U)
#define CSL_DWCAHSATA_OOBR_CIMIN_RESETVAL                       (0x00000024U)
#define CSL_DWCAHSATA_OOBR_CIMIN_MAX                            (0x000000ffU)

#define CSL_DWCAHSATA_OOBR_CWMAX_MASK                           (0x00FF0000U)
#define CSL_DWCAHSATA_OOBR_CWMAX_SHIFT                          (16U)
#define CSL_DWCAHSATA_OOBR_CWMAX_RESETVAL                       (0x00000015U)
#define CSL_DWCAHSATA_OOBR_CWMAX_MAX                            (0x000000ffU)

#define CSL_DWCAHSATA_OOBR_CWMIN_MASK                           (0x7F000000U)
#define CSL_DWCAHSATA_OOBR_CWMIN_SHIFT                          (24U)
#define CSL_DWCAHSATA_OOBR_CWMIN_RESETVAL                       (0x0000000bU)
#define CSL_DWCAHSATA_OOBR_CWMIN_MAX                            (0x0000007fU)

#define CSL_DWCAHSATA_OOBR_WE_MASK                              (0x80000000U)
#define CSL_DWCAHSATA_OOBR_WE_SHIFT                             (31U)
#define CSL_DWCAHSATA_OOBR_WE_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_OOBR_WE_NO                                (0x00000000U)
#define CSL_DWCAHSATA_OOBR_WE_YES                               (0x00000001U)

#define CSL_DWCAHSATA_OOBR_RESETVAL                             (0x0b152440U)

/* TIMER1MS */

#define CSL_DWCAHSATA_TIMER1MS_TIMV_MASK                        (0x000FFFFFU)
#define CSL_DWCAHSATA_TIMER1MS_TIMV_SHIFT                       (0U)
#define CSL_DWCAHSATA_TIMER1MS_TIMV_RESETVAL                    (0x000186a0U)
#define CSL_DWCAHSATA_TIMER1MS_TIMV_MAX                         (0x000fffffU)

#define CSL_DWCAHSATA_TIMER1MS_RESETVAL                         (0x000186a0U)

/* GPARAM1R */

#define CSL_DWCAHSATA_GPARAM1R_M_HADDR_MASK                     (0x00000040U)
#define CSL_DWCAHSATA_GPARAM1R_M_HADDR_SHIFT                    (6U)
#define CSL_DWCAHSATA_GPARAM1R_M_HADDR_RESETVAL                 (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_M_HADDR__32BIT                   (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_M_HADDR__64BIT                   (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_S_HADDR_MASK                     (0x00000080U)
#define CSL_DWCAHSATA_GPARAM1R_S_HADDR_SHIFT                    (7U)
#define CSL_DWCAHSATA_GPARAM1R_S_HADDR_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_S_HADDR__32BIT                   (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_S_HADDR__64BIT                   (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_MASK                  (0x00000300U)
#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_SHIFT                 (8U)
#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_RESETVAL              (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_LITTLE                (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_BIG                   (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_AHB_ENDIAN_CONF                  (0x00000002U)

#define CSL_DWCAHSATA_GPARAM1R_RETURN_ERR_MASK                  (0x00000400U)
#define CSL_DWCAHSATA_GPARAM1R_RETURN_ERR_SHIFT                 (10U)
#define CSL_DWCAHSATA_GPARAM1R_RETURN_ERR_RESETVAL              (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_RETURN_ERR_NO                    (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_RETURN_ERR_YES                   (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_PHY_TYPE_MASK                    (0x00001800U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_TYPE_SHIFT                   (11U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_TYPE_RESETVAL                (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_TYPE_CONFIG                  (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_TYPE_SNPS                    (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_BIST_M_MASK                      (0x00002000U)
#define CSL_DWCAHSATA_GPARAM1R_BIST_M_SHIFT                     (13U)
#define CSL_DWCAHSATA_GPARAM1R_BIST_M_RESETVAL                  (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_BIST_M_DWORD                     (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_BIST_M_FIS                       (0x00000000U)

#define CSL_DWCAHSATA_GPARAM1R_LATCH_M_MASK                     (0x00004000U)
#define CSL_DWCAHSATA_GPARAM1R_LATCH_M_SHIFT                    (14U)
#define CSL_DWCAHSATA_GPARAM1R_LATCH_M_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_LATCH_M_NO                       (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_LATCH_M_YES                      (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_PHY_STAT_MASK                    (0x001F8000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_STAT_SHIFT                   (15U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_STAT_RESETVAL                (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_STAT_MAX                     (0x0000003fU)

#define CSL_DWCAHSATA_GPARAM1R_PHY_CTRL_MASK                    (0x07E00000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_CTRL_SHIFT                   (21U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_CTRL_RESETVAL                (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_CTRL_MAX                     (0x0000003fU)

#define CSL_DWCAHSATA_GPARAM1R_PHY_RST_MASK                     (0x08000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_RST_SHIFT                    (27U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_RST_RESETVAL                 (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_RST_LO                       (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_RST_HI                       (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA_MASK                    (0x30000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA_SHIFT                   (28U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA_RESETVAL                (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA__1                      (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA__2                      (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_PHY_DATA__4                      (0x00000002U)

#define CSL_DWCAHSATA_GPARAM1R_RX_BUFFER_MASK                   (0x40000000U)
#define CSL_DWCAHSATA_GPARAM1R_RX_BUFFER_SHIFT                  (30U)
#define CSL_DWCAHSATA_GPARAM1R_RX_BUFFER_RESETVAL               (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_RX_BUFFER_NO                     (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_RX_BUFFER_YES                    (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_ALIGN_M_MASK                     (0x80000000U)
#define CSL_DWCAHSATA_GPARAM1R_ALIGN_M_SHIFT                    (31U)
#define CSL_DWCAHSATA_GPARAM1R_ALIGN_M_RESETVAL                 (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_ALIGN_M_NO                       (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_ALIGN_M_YES                      (0x00000001U)

#define CSL_DWCAHSATA_GPARAM1R_M_HDATA_MASK                     (0x00000007U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA_SHIFT                    (0U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA__32_BIT                  (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA__64_BIT                  (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA__128_BIT                 (0x00000002U)
#define CSL_DWCAHSATA_GPARAM1R_M_HDATA__256_BIT                 (0x00000003U)

#define CSL_DWCAHSATA_GPARAM1R_S_HDATA_MASK                     (0x00000038U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA_SHIFT                    (3U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA__32_BIT                  (0x00000000U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA__64_BIT                  (0x00000001U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA__128_BIT                 (0x00000002U)
#define CSL_DWCAHSATA_GPARAM1R_S_HDATA__256_BIT                 (0x00000003U)

#define CSL_DWCAHSATA_GPARAM1R_RESETVAL                         (0xc8000040U)

/* GPARAM2R */

#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_MASK                   (0x000001FFU)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_SHIFT                  (0U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_RESETVAL               (0x00000096U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_MAX                    (0x000001ffU)

#define CSL_DWCAHSATA_GPARAM2R_TX_OOB_M_MASK                    (0x00000200U)
#define CSL_DWCAHSATA_GPARAM2R_TX_OOB_M_SHIFT                   (9U)
#define CSL_DWCAHSATA_GPARAM2R_TX_OOB_M_RESETVAL                (0x00000001U)
#define CSL_DWCAHSATA_GPARAM2R_TX_OOB_M_NO                      (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_TX_OOB_M_YES                     (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_RX_OOB_M_MASK                    (0x00000400U)
#define CSL_DWCAHSATA_GPARAM2R_RX_OOB_M_SHIFT                   (10U)
#define CSL_DWCAHSATA_GPARAM2R_RX_OOB_M_RESETVAL                (0x00000001U)
#define CSL_DWCAHSATA_GPARAM2R_RX_OOB_M_NO                      (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_RX_OOB_M_YES                     (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_M_MASK                 (0x00000800U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_M_SHIFT                (11U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_M_RESETVAL             (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_M_RX                   (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_RXOOB_CLK_M_SEP                  (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_ENCODE_M_MASK                    (0x00001000U)
#define CSL_DWCAHSATA_GPARAM2R_ENCODE_M_SHIFT                   (12U)
#define CSL_DWCAHSATA_GPARAM2R_ENCODE_M_RESETVAL                (0x00000001U)
#define CSL_DWCAHSATA_GPARAM2R_ENCODE_M_NO                      (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_ENCODE_M_YES                     (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_DEV_MP_MASK                      (0x00002000U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_MP_SHIFT                     (13U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_MP_RESETVAL                  (0x00000001U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_MP_NO                        (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_MP_YES                       (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_DEV_CP_MASK                      (0x00004000U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_CP_SHIFT                     (14U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_CP_RESETVAL                  (0x00000001U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_CP_NO                        (0x00000000U)
#define CSL_DWCAHSATA_GPARAM2R_DEV_CP_YES                       (0x00000001U)

#define CSL_DWCAHSATA_GPARAM2R_RESETVAL                         (0x00007696U)

/* PPARAMR */

#define CSL_DWCAHSATA_PPARAMR_RXFIFO_DEPTH_MASK                 (0x0000000FU)
#define CSL_DWCAHSATA_PPARAMR_RXFIFO_DEPTH_SHIFT                (0U)
#define CSL_DWCAHSATA_PPARAMR_RXFIFO_DEPTH_RESETVAL             (0x00000007U)
#define CSL_DWCAHSATA_PPARAMR_RXFIFO_DEPTH_MAX                  (0x0000000fU)

#define CSL_DWCAHSATA_PPARAMR_TXFIFO_DEPTH_MASK                 (0x000000F0U)
#define CSL_DWCAHSATA_PPARAMR_TXFIFO_DEPTH_SHIFT                (4U)
#define CSL_DWCAHSATA_PPARAMR_TXFIFO_DEPTH_RESETVAL             (0x00000006U)
#define CSL_DWCAHSATA_PPARAMR_TXFIFO_DEPTH_MAX                  (0x0000000fU)

#define CSL_DWCAHSATA_PPARAMR_RX_MEM_S_MASK                     (0x00000100U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_S_SHIFT                    (8U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_S_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_S_EXT                      (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_S_INT                      (0x00000001U)

#define CSL_DWCAHSATA_PPARAMR_RX_MEM_M_MASK                     (0x00000200U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_M_SHIFT                    (9U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_M_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_M_ASYNC                    (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_RX_MEM_M_SYNC                     (0x00000001U)

#define CSL_DWCAHSATA_PPARAMR_TX_MEM_S_MASK                     (0x00000400U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_S_SHIFT                    (10U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_S_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_S_EXT                      (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_S_INT                      (0x00000001U)

#define CSL_DWCAHSATA_PPARAMR_TX_MEM_M_MASK                     (0x00000800U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_M_SHIFT                    (11U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_M_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_M_ASYNC                    (0x00000000U)
#define CSL_DWCAHSATA_PPARAMR_TX_MEM_M_SYNC                     (0x00000001U)

#define CSL_DWCAHSATA_PPARAMR_RESETVAL                          (0x00000067U)

/* TESTR */

#define CSL_DWCAHSATA_TESTR_TEST_IF_MASK                        (0x00000001U)
#define CSL_DWCAHSATA_TESTR_TEST_IF_SHIFT                       (0U)
#define CSL_DWCAHSATA_TESTR_TEST_IF_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_TESTR_TEST_IF_DEFAULT                     (0x00000000U)
#define CSL_DWCAHSATA_TESTR_TEST_IF_TEST                        (0x00000001U)

#define CSL_DWCAHSATA_TESTR_PSEL_MASK                           (0x00070000U)
#define CSL_DWCAHSATA_TESTR_PSEL_SHIFT                          (16U)
#define CSL_DWCAHSATA_TESTR_PSEL_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_TESTR_PSEL__0                             (0x00000000U)

#define CSL_DWCAHSATA_TESTR_RESETVAL                            (0x00000000U)

/* VERSIONR */

#define CSL_DWCAHSATA_VERSIONR_VERSION_MASK                     (0xFFFFFFFFU)
#define CSL_DWCAHSATA_VERSIONR_VERSION_SHIFT                    (0U)
#define CSL_DWCAHSATA_VERSIONR_VERSION_RESETVAL                 (0x00000000U)
#define CSL_DWCAHSATA_VERSIONR_VERSION_MAX                      (0xffffffffU)

#define CSL_DWCAHSATA_VERSIONR_RESETVAL                         (0x3333302aU)

/* IDR */

#define CSL_DWCAHSATA_IDR_Y_MINOR_MASK                          (0x0000003FU)
#define CSL_DWCAHSATA_IDR_Y_MINOR_SHIFT                         (0U)
#define CSL_DWCAHSATA_IDR_Y_MINOR_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_IDR_Y_MINOR_MAX                           (0x0000003fU)

#define CSL_DWCAHSATA_IDR_CUSTOM_MASK                           (0x000000C0U)
#define CSL_DWCAHSATA_IDR_CUSTOM_SHIFT                          (6U)
#define CSL_DWCAHSATA_IDR_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_IDR_CUSTOM_STANDARD                       (0x00000000U)

#define CSL_DWCAHSATA_IDR_X_MAJOR_MASK                          (0x00000700U)
#define CSL_DWCAHSATA_IDR_X_MAJOR_SHIFT                         (8U)
#define CSL_DWCAHSATA_IDR_X_MAJOR_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_IDR_X_MAJOR_MAX                           (0x00000007U)

#define CSL_DWCAHSATA_IDR_R_RTL_MASK                            (0x0000F800U)
#define CSL_DWCAHSATA_IDR_R_RTL_SHIFT                           (11U)
#define CSL_DWCAHSATA_IDR_R_RTL_RESETVAL                        (0x00000002U)
#define CSL_DWCAHSATA_IDR_R_RTL_MAX                             (0x0000001fU)

#define CSL_DWCAHSATA_IDR_FUNC_MASK                             (0x0FFF0000U)
#define CSL_DWCAHSATA_IDR_FUNC_SHIFT                            (16U)
#define CSL_DWCAHSATA_IDR_FUNC_RESETVAL                         (0x00000e41U)
#define CSL_DWCAHSATA_IDR_FUNC_MAX                              (0x00000fffU)

#define CSL_DWCAHSATA_IDR_BU_MASK                               (0x30000000U)
#define CSL_DWCAHSATA_IDR_BU_SHIFT                              (28U)
#define CSL_DWCAHSATA_IDR_BU_RESETVAL                           (0x00000001U)
#define CSL_DWCAHSATA_IDR_BU_WTBU                               (0x00000001U)
#define CSL_DWCAHSATA_IDR_BU_DSPS                               (0x00000000U)

#define CSL_DWCAHSATA_IDR_SCHEME_MASK                           (0xC0000000U)
#define CSL_DWCAHSATA_IDR_SCHEME_SHIFT                          (30U)
#define CSL_DWCAHSATA_IDR_SCHEME_RESETVAL                       (0x00000001U)
#define CSL_DWCAHSATA_IDR_SCHEME_H08                            (0x00000001U)
#define CSL_DWCAHSATA_IDR_SCHEME_LEGACY                         (0x00000000U)

#define CSL_DWCAHSATA_IDR_RESETVAL                              (0x5e411000U)

/* CAP2 */

#define CSL_DWCAHSATA_CAP2_APST_MASK                            (0x00000004U)
#define CSL_DWCAHSATA_CAP2_APST_SHIFT                           (2U)
#define CSL_DWCAHSATA_CAP2_APST_RESETVAL                        (0x00000001U)
#define CSL_DWCAHSATA_CAP2_APST_NO                              (0x00000000U)
#define CSL_DWCAHSATA_CAP2_APST_YES                             (0x00000001U)

#define CSL_DWCAHSATA_CAP2_BOH_MASK                             (0x00000001U)
#define CSL_DWCAHSATA_CAP2_BOH_SHIFT                            (0U)
#define CSL_DWCAHSATA_CAP2_BOH_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_CAP2_BOH_NO                               (0x00000000U)
#define CSL_DWCAHSATA_CAP2_BOH_YES                              (0x00000001U)

#define CSL_DWCAHSATA_CAP2_NVMP_MASK                            (0x00000002U)
#define CSL_DWCAHSATA_CAP2_NVMP_SHIFT                           (1U)
#define CSL_DWCAHSATA_CAP2_NVMP_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_CAP2_NVMP_NO                              (0x00000000U)
#define CSL_DWCAHSATA_CAP2_NVMP_YES                             (0x00000001U)

#define CSL_DWCAHSATA_CAP2_RESETVAL                             (0x00000004U)

/* PXCLB */

#define CSL_DWCAHSATA_PXCLB_CLB_MASK                            (0xFFFFFC00U)
#define CSL_DWCAHSATA_PXCLB_CLB_SHIFT                           (10U)
#define CSL_DWCAHSATA_PXCLB_CLB_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCLB_CLB_MAX                             (0x003fffffU)

#define CSL_DWCAHSATA_PXCLB_ZERO_MASK                           (0x000003FFU)
#define CSL_DWCAHSATA_PXCLB_ZERO_SHIFT                          (0U)
#define CSL_DWCAHSATA_PXCLB_ZERO_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCLB_ZERO_MAX                            (0x000003ffU)

#define CSL_DWCAHSATA_PXCLB_RESETVAL                            (0x00000000U)

/* PXFB */

#define CSL_DWCAHSATA_PXFB_FB_MASK                              (0xFFFFFF00U)
#define CSL_DWCAHSATA_PXFB_FB_SHIFT                             (8U)
#define CSL_DWCAHSATA_PXFB_FB_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_PXFB_FB_MAX                               (0x00ffffffU)

#define CSL_DWCAHSATA_PXFB_ZERO_MASK                            (0x000000FFU)
#define CSL_DWCAHSATA_PXFB_ZERO_SHIFT                           (0U)
#define CSL_DWCAHSATA_PXFB_ZERO_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXFB_ZERO_MAX                             (0x000000ffU)

#define CSL_DWCAHSATA_PXFB_RESETVAL                             (0x00000000U)

/* PXIS */

#define CSL_DWCAHSATA_PXIS_DHRS_MASK                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DHRS_SHIFT                           (0U)
#define CSL_DWCAHSATA_PXIS_DHRS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DHRS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DHRS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DHRS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DHRS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_PSS_MASK                             (0x00000002U)
#define CSL_DWCAHSATA_PXIS_PSS_SHIFT                            (1U)
#define CSL_DWCAHSATA_PXIS_PSS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_PSS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_PSS_EVENT                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_PSS_CLEAR                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_PSS_NOACTION                         (0x00000000U)

#define CSL_DWCAHSATA_PXIS_DSS_MASK                             (0x00000004U)
#define CSL_DWCAHSATA_PXIS_DSS_SHIFT                            (2U)
#define CSL_DWCAHSATA_PXIS_DSS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DSS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DSS_EVENT                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DSS_CLEAR                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DSS_NOACTION                         (0x00000000U)

#define CSL_DWCAHSATA_PXIS_SDBS_MASK                            (0x00000008U)
#define CSL_DWCAHSATA_PXIS_SDBS_SHIFT                           (3U)
#define CSL_DWCAHSATA_PXIS_SDBS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_SDBS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_SDBS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_SDBS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_SDBS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_UFS_MASK                             (0x00000010U)
#define CSL_DWCAHSATA_PXIS_UFS_SHIFT                            (4U)
#define CSL_DWCAHSATA_PXIS_UFS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_UFS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_UFS_EVENT                            (0x00000001U)

#define CSL_DWCAHSATA_PXIS_DPS_MASK                             (0x00000020U)
#define CSL_DWCAHSATA_PXIS_DPS_SHIFT                            (5U)
#define CSL_DWCAHSATA_PXIS_DPS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DPS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DPS_EVENT                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DPS_CLEAR                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DPS_NOACTION                         (0x00000000U)

#define CSL_DWCAHSATA_PXIS_PCS_MASK                             (0x00000040U)
#define CSL_DWCAHSATA_PXIS_PCS_SHIFT                            (6U)
#define CSL_DWCAHSATA_PXIS_PCS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_PCS_NOCHANGE                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_PCS_CHANGE                           (0x00000001U)

#define CSL_DWCAHSATA_PXIS_DMPS_MASK                            (0x00000080U)
#define CSL_DWCAHSATA_PXIS_DMPS_SHIFT                           (7U)
#define CSL_DWCAHSATA_PXIS_DMPS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DMPS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_DMPS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DMPS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_DMPS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_PRCS_MASK                            (0x00400000U)
#define CSL_DWCAHSATA_PXIS_PRCS_SHIFT                           (22U)
#define CSL_DWCAHSATA_PXIS_PRCS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_PRCS_CHANGE                          (0x00000001U)
#define CSL_DWCAHSATA_PXIS_PRCS_NOCHANGE                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_IPMS_MASK                            (0x00800000U)
#define CSL_DWCAHSATA_PXIS_IPMS_SHIFT                           (23U)
#define CSL_DWCAHSATA_PXIS_IPMS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_IPMS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_IPMS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_IPMS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_IPMS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_OFS_MASK                             (0x01000000U)
#define CSL_DWCAHSATA_PXIS_OFS_SHIFT                            (24U)
#define CSL_DWCAHSATA_PXIS_OFS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_OFS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_OFS_EVENT                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_OFS_CLEAR                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_OFS_NOACTION                         (0x00000000U)

#define CSL_DWCAHSATA_PXIS_INFS_MASK                            (0x04000000U)
#define CSL_DWCAHSATA_PXIS_INFS_SHIFT                           (26U)
#define CSL_DWCAHSATA_PXIS_INFS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_INFS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_INFS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_INFS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_INFS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_IFS_MASK                             (0x08000000U)
#define CSL_DWCAHSATA_PXIS_IFS_SHIFT                            (27U)
#define CSL_DWCAHSATA_PXIS_IFS_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_IFS_NOEVENT                          (0x00000000U)
#define CSL_DWCAHSATA_PXIS_IFS_EVENT                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_IFS_CLEAR                            (0x00000001U)
#define CSL_DWCAHSATA_PXIS_IFS_NOACTION                         (0x00000000U)

#define CSL_DWCAHSATA_PXIS_HBDS_MASK                            (0x10000000U)
#define CSL_DWCAHSATA_PXIS_HBDS_SHIFT                           (28U)
#define CSL_DWCAHSATA_PXIS_HBDS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_HBDS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_HBDS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_HBDS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_HBDS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_HBFS_MASK                            (0x20000000U)
#define CSL_DWCAHSATA_PXIS_HBFS_SHIFT                           (29U)
#define CSL_DWCAHSATA_PXIS_HBFS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_HBFS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_HBFS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_HBFS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_HBFS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_TFES_MASK                            (0x40000000U)
#define CSL_DWCAHSATA_PXIS_TFES_SHIFT                           (30U)
#define CSL_DWCAHSATA_PXIS_TFES_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_TFES_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_TFES_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_TFES_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_TFES_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_CPDS_MASK                            (0x80000000U)
#define CSL_DWCAHSATA_PXIS_CPDS_SHIFT                           (31U)
#define CSL_DWCAHSATA_PXIS_CPDS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIS_CPDS_NOEVENT                         (0x00000000U)
#define CSL_DWCAHSATA_PXIS_CPDS_EVENT                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_CPDS_CLEAR                           (0x00000001U)
#define CSL_DWCAHSATA_PXIS_CPDS_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXIS_RESETVAL                             (0x00000000U)

/* PXIE */

#define CSL_DWCAHSATA_PXIE_DHRE_MASK                            (0x00000001U)
#define CSL_DWCAHSATA_PXIE_DHRE_SHIFT                           (0U)
#define CSL_DWCAHSATA_PXIE_DHRE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DHRE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DHRE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_PSE_MASK                             (0x00000002U)
#define CSL_DWCAHSATA_PXIE_PSE_SHIFT                            (1U)
#define CSL_DWCAHSATA_PXIE_PSE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PSE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PSE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_DSE_MASK                             (0x00000004U)
#define CSL_DWCAHSATA_PXIE_DSE_SHIFT                            (2U)
#define CSL_DWCAHSATA_PXIE_DSE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DSE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DSE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_SDBE_MASK                            (0x00000008U)
#define CSL_DWCAHSATA_PXIE_SDBE_SHIFT                           (3U)
#define CSL_DWCAHSATA_PXIE_SDBE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_SDBE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_SDBE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_UFE_MASK                             (0x00000010U)
#define CSL_DWCAHSATA_PXIE_UFE_SHIFT                            (4U)
#define CSL_DWCAHSATA_PXIE_UFE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_UFE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_UFE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_DPE_MASK                             (0x00000020U)
#define CSL_DWCAHSATA_PXIE_DPE_SHIFT                            (5U)
#define CSL_DWCAHSATA_PXIE_DPE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DPE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DPE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_PCE_MASK                             (0x00000040U)
#define CSL_DWCAHSATA_PXIE_PCE_SHIFT                            (6U)
#define CSL_DWCAHSATA_PXIE_PCE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PCE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PCE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_DMPE_MASK                            (0x00000080U)
#define CSL_DWCAHSATA_PXIE_DMPE_SHIFT                           (7U)
#define CSL_DWCAHSATA_PXIE_DMPE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DMPE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_DMPE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_PRCE_MASK                            (0x00400000U)
#define CSL_DWCAHSATA_PXIE_PRCE_SHIFT                           (22U)
#define CSL_DWCAHSATA_PXIE_PRCE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PRCE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_PRCE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_IPME_MASK                            (0x00800000U)
#define CSL_DWCAHSATA_PXIE_IPME_SHIFT                           (23U)
#define CSL_DWCAHSATA_PXIE_IPME_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_IPME_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_IPME_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_OFE_MASK                             (0x01000000U)
#define CSL_DWCAHSATA_PXIE_OFE_SHIFT                            (24U)
#define CSL_DWCAHSATA_PXIE_OFE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_OFE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_OFE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_INFE_MASK                            (0x04000000U)
#define CSL_DWCAHSATA_PXIE_INFE_SHIFT                           (26U)
#define CSL_DWCAHSATA_PXIE_INFE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_INFE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_INFE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_IFE_MASK                             (0x08000000U)
#define CSL_DWCAHSATA_PXIE_IFE_SHIFT                            (27U)
#define CSL_DWCAHSATA_PXIE_IFE_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXIE_IFE_DIS                              (0x00000000U)
#define CSL_DWCAHSATA_PXIE_IFE_EN                               (0x00000001U)

#define CSL_DWCAHSATA_PXIE_HBDE_MASK                            (0x10000000U)
#define CSL_DWCAHSATA_PXIE_HBDE_SHIFT                           (28U)
#define CSL_DWCAHSATA_PXIE_HBDE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_HBDE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_HBDE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_HBFE_MASK                            (0x20000000U)
#define CSL_DWCAHSATA_PXIE_HBFE_SHIFT                           (29U)
#define CSL_DWCAHSATA_PXIE_HBFE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_HBFE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_HBFE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_TFEE_MASK                            (0x40000000U)
#define CSL_DWCAHSATA_PXIE_TFEE_SHIFT                           (30U)
#define CSL_DWCAHSATA_PXIE_TFEE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_TFEE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_TFEE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_CPDE_MASK                            (0x80000000U)
#define CSL_DWCAHSATA_PXIE_CPDE_SHIFT                           (31U)
#define CSL_DWCAHSATA_PXIE_CPDE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXIE_CPDE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXIE_CPDE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXIE_RESETVAL                             (0x00000000U)

/* PXCMD */

#define CSL_DWCAHSATA_PXCMD_ST_MASK                             (0x00000001U)
#define CSL_DWCAHSATA_PXCMD_ST_SHIFT                            (0U)
#define CSL_DWCAHSATA_PXCMD_ST_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ST_NEWENUM1                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ST_START                            (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_SUD_MASK                            (0x00000002U)
#define CSL_DWCAHSATA_PXCMD_SUD_SHIFT                           (1U)
#define CSL_DWCAHSATA_PXCMD_SUD_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_SUD_NOACTION                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_SUD_NEWENUM2                        (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_POD_MASK                            (0x00000004U)
#define CSL_DWCAHSATA_PXCMD_POD_SHIFT                           (2U)
#define CSL_DWCAHSATA_PXCMD_POD_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_POD_NO                              (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_POD_YES                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_CLO_MASK                            (0x00000008U)
#define CSL_DWCAHSATA_PXCMD_CLO_SHIFT                           (3U)
#define CSL_DWCAHSATA_PXCMD_CLO_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CLO_IDLE                            (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CLO_ACTIVE                          (0x00000001U)
#define CSL_DWCAHSATA_PXCMD_CLO_OVERRIDE                        (0x00000001U)
#define CSL_DWCAHSATA_PXCMD_CLO_NOACTION                        (0x00000000U)

#define CSL_DWCAHSATA_PXCMD_FRE_MASK                            (0x00000010U)
#define CSL_DWCAHSATA_PXCMD_FRE_SHIFT                           (4U)
#define CSL_DWCAHSATA_PXCMD_FRE_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FRE_DIS                             (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FRE_EN                              (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_CCS_MASK                            (0x00001F00U)
#define CSL_DWCAHSATA_PXCMD_CCS_SHIFT                           (8U)
#define CSL_DWCAHSATA_PXCMD_CCS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CCS_MAX                             (0x0000001fU)

#define CSL_DWCAHSATA_PXCMD_MPSS_MASK                           (0x00002000U)
#define CSL_DWCAHSATA_PXCMD_MPSS_SHIFT                          (13U)
#define CSL_DWCAHSATA_PXCMD_MPSS_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_MPSS_CLOSED                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_MPSS_OPEN                           (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_FR_MASK                             (0x00004000U)
#define CSL_DWCAHSATA_PXCMD_FR_SHIFT                            (14U)
#define CSL_DWCAHSATA_PXCMD_FR_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FR_STOPPED                          (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FR_RUNNING                          (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_CR_MASK                             (0x00008000U)
#define CSL_DWCAHSATA_PXCMD_CR_SHIFT                            (15U)
#define CSL_DWCAHSATA_PXCMD_CR_RESETVAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CR_STOPPED                          (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CR_RUNNING                          (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_CPS_MASK                            (0x00010000U)
#define CSL_DWCAHSATA_PXCMD_CPS_SHIFT                           (16U)
#define CSL_DWCAHSATA_PXCMD_CPS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CPS_NO                              (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CPS_YES                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_PMA_MASK                            (0x00020000U)
#define CSL_DWCAHSATA_PXCMD_PMA_SHIFT                           (17U)
#define CSL_DWCAHSATA_PXCMD_PMA_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_PMA_NO                              (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_PMA_YES                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_HPCP_MASK                           (0x00040000U)
#define CSL_DWCAHSATA_PXCMD_HPCP_SHIFT                          (18U)
#define CSL_DWCAHSATA_PXCMD_HPCP_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_HPCP_NO                             (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_HPCP_YES                            (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_MPSP_MASK                           (0x00080000U)
#define CSL_DWCAHSATA_PXCMD_MPSP_SHIFT                          (19U)
#define CSL_DWCAHSATA_PXCMD_MPSP_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_MPSP_NO                             (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_MPSP_YES                            (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_CPD_MASK                            (0x00100000U)
#define CSL_DWCAHSATA_PXCMD_CPD_SHIFT                           (20U)
#define CSL_DWCAHSATA_PXCMD_CPD_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CPD_NO                              (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_CPD_YES                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_ESP_MASK                            (0x00200000U)
#define CSL_DWCAHSATA_PXCMD_ESP_SHIFT                           (21U)
#define CSL_DWCAHSATA_PXCMD_ESP_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ESP_INT                             (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ESP_EXT                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_APSTE_MASK                          (0x00800000U)
#define CSL_DWCAHSATA_PXCMD_APSTE_SHIFT                         (23U)
#define CSL_DWCAHSATA_PXCMD_APSTE_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_APSTE_DIS                           (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_APSTE_EN                            (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_ATAPI_MASK                          (0x01000000U)
#define CSL_DWCAHSATA_PXCMD_ATAPI_SHIFT                         (24U)
#define CSL_DWCAHSATA_PXCMD_ATAPI_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ATAPI_NO                            (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ATAPI_YES                           (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_DLAE_MASK                           (0x02000000U)
#define CSL_DWCAHSATA_PXCMD_DLAE_SHIFT                          (25U)
#define CSL_DWCAHSATA_PXCMD_DLAE_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_DLAE_DIS                            (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_DLAE_EN                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_ALPE_MASK                           (0x04000000U)
#define CSL_DWCAHSATA_PXCMD_ALPE_SHIFT                          (26U)
#define CSL_DWCAHSATA_PXCMD_ALPE_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ALPE_DIS                            (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ALPE_EN                             (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_ASP_MASK                            (0x08000000U)
#define CSL_DWCAHSATA_PXCMD_ASP_SHIFT                           (27U)
#define CSL_DWCAHSATA_PXCMD_ASP_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ASP_PARTIAL                         (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ASP_SLUMBER                         (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_ICC_MASK                            (0xF0000000U)
#define CSL_DWCAHSATA_PXCMD_ICC_SHIFT                           (28U)
#define CSL_DWCAHSATA_PXCMD_ICC_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_ICC_MAX                             (0x0000000fU)

#define CSL_DWCAHSATA_PXCMD_FBSCP_MASK                          (0x00400000U)
#define CSL_DWCAHSATA_PXCMD_FBSCP_SHIFT                         (22U)
#define CSL_DWCAHSATA_PXCMD_FBSCP_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FBSCP_NOTCAP                        (0x00000000U)
#define CSL_DWCAHSATA_PXCMD_FBSCP_CAP                           (0x00000001U)

#define CSL_DWCAHSATA_PXCMD_RESETVAL                            (0x00000000U)

/* PXTFD */

#define CSL_DWCAHSATA_PXTFD_STS_BSY_MASK                        (0x00000080U)
#define CSL_DWCAHSATA_PXTFD_STS_BSY_SHIFT                       (7U)
#define CSL_DWCAHSATA_PXTFD_STS_BSY_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXTFD_STS_BSY_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXTFD_ERR_MASK                            (0x0000FF00U)
#define CSL_DWCAHSATA_PXTFD_ERR_SHIFT                           (8U)
#define CSL_DWCAHSATA_PXTFD_ERR_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXTFD_ERR_MAX                             (0x000000ffU)

#define CSL_DWCAHSATA_PXTFD_STS_ERR_MASK                        (0x00000001U)
#define CSL_DWCAHSATA_PXTFD_STS_ERR_SHIFT                       (0U)
#define CSL_DWCAHSATA_PXTFD_STS_ERR_RESETVAL                    (0x00000001U)
#define CSL_DWCAHSATA_PXTFD_STS_ERR_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXTFD_STS_DRQ_MASK                        (0x00000008U)
#define CSL_DWCAHSATA_PXTFD_STS_DRQ_SHIFT                       (3U)
#define CSL_DWCAHSATA_PXTFD_STS_DRQ_RESETVAL                    (0x00000001U)
#define CSL_DWCAHSATA_PXTFD_STS_DRQ_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXTFD_STS_CS_MASK                         (0x00000006U)
#define CSL_DWCAHSATA_PXTFD_STS_CS_SHIFT                        (1U)
#define CSL_DWCAHSATA_PXTFD_STS_CS_RESETVAL                     (0x00000003U)
#define CSL_DWCAHSATA_PXTFD_STS_CS_MAX                          (0x00000003U)

#define CSL_DWCAHSATA_PXTFD_STS_CS2_MASK                        (0x00000070U)
#define CSL_DWCAHSATA_PXTFD_STS_CS2_SHIFT                       (4U)
#define CSL_DWCAHSATA_PXTFD_STS_CS2_RESETVAL                    (0x00000007U)
#define CSL_DWCAHSATA_PXTFD_STS_CS2_MAX                         (0x00000007U)

#define CSL_DWCAHSATA_PXTFD_RESETVAL                            (0x0000007fU)

/* PXSIG */

#define CSL_DWCAHSATA_PXSIG_SIG_LBAH_MASK                       (0xFF000000U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAH_SHIFT                      (24U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAH_RESETVAL                   (0x000000ffU)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAH_MAX                        (0x000000ffU)

#define CSL_DWCAHSATA_PXSIG_SIG_LBAM_MASK                       (0x00FF0000U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAM_SHIFT                      (16U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAM_RESETVAL                   (0x000000ffU)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAM_MAX                        (0x000000ffU)

#define CSL_DWCAHSATA_PXSIG_SIG_LBAL_MASK                       (0x0000FF00U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAL_SHIFT                      (8U)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAL_RESETVAL                   (0x000000ffU)
#define CSL_DWCAHSATA_PXSIG_SIG_LBAL_MAX                        (0x000000ffU)

#define CSL_DWCAHSATA_PXSIG_SIG_SCR_MASK                        (0x000000FFU)
#define CSL_DWCAHSATA_PXSIG_SIG_SCR_SHIFT                       (0U)
#define CSL_DWCAHSATA_PXSIG_SIG_SCR_RESETVAL                    (0x000000ffU)
#define CSL_DWCAHSATA_PXSIG_SIG_SCR_MAX                         (0x000000ffU)

#define CSL_DWCAHSATA_PXSIG_RESETVAL                            (0xffffffffU)

/* PXSSTS */

#define CSL_DWCAHSATA_PXSSTS_DET_MASK                           (0x0000000FU)
#define CSL_DWCAHSATA_PXSSTS_DET_SHIFT                          (0U)
#define CSL_DWCAHSATA_PXSSTS_DET_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSSTS_DET_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSSTS_SPD_MASK                           (0x000000F0U)
#define CSL_DWCAHSATA_PXSSTS_SPD_SHIFT                          (4U)
#define CSL_DWCAHSATA_PXSSTS_SPD_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSSTS_SPD_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSSTS_IPM_MASK                           (0x00000F00U)
#define CSL_DWCAHSATA_PXSSTS_IPM_SHIFT                          (8U)
#define CSL_DWCAHSATA_PXSSTS_IPM_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSSTS_IPM_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSSTS_RESETVAL                           (0x00000000U)

/* PXSCTL */

#define CSL_DWCAHSATA_PXSCTL_DET_MASK                           (0x0000000FU)
#define CSL_DWCAHSATA_PXSCTL_DET_SHIFT                          (0U)
#define CSL_DWCAHSATA_PXSCTL_DET_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSCTL_DET_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSCTL_SPD_MASK                           (0x000000F0U)
#define CSL_DWCAHSATA_PXSCTL_SPD_SHIFT                          (4U)
#define CSL_DWCAHSATA_PXSCTL_SPD_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSCTL_SPD_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSCTL_IPM_MASK                           (0x00000F00U)
#define CSL_DWCAHSATA_PXSCTL_IPM_SHIFT                          (8U)
#define CSL_DWCAHSATA_PXSCTL_IPM_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSCTL_IPM_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSCTL_SPM_MASK                           (0x0000F000U)
#define CSL_DWCAHSATA_PXSCTL_SPM_SHIFT                          (12U)
#define CSL_DWCAHSATA_PXSCTL_SPM_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSCTL_SPM_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSCTL_PMP_MASK                           (0x000F0000U)
#define CSL_DWCAHSATA_PXSCTL_PMP_SHIFT                          (16U)
#define CSL_DWCAHSATA_PXSCTL_PMP_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSCTL_PMP_MAX                            (0x0000000fU)

#define CSL_DWCAHSATA_PXSCTL_RESETVAL                           (0x00000000U)

/* PXSERR */

#define CSL_DWCAHSATA_PXSERR_ERR_I_MASK                         (0x00000001U)
#define CSL_DWCAHSATA_PXSERR_ERR_I_SHIFT                        (0U)
#define CSL_DWCAHSATA_PXSERR_ERR_I_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_I_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_ERR_M_MASK                         (0x00000002U)
#define CSL_DWCAHSATA_PXSERR_ERR_M_SHIFT                        (1U)
#define CSL_DWCAHSATA_PXSERR_ERR_M_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_M_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_ERR_T_MASK                         (0x00000100U)
#define CSL_DWCAHSATA_PXSERR_ERR_T_SHIFT                        (8U)
#define CSL_DWCAHSATA_PXSERR_ERR_T_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_T_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_ERR_C_MASK                         (0x00000200U)
#define CSL_DWCAHSATA_PXSERR_ERR_C_SHIFT                        (9U)
#define CSL_DWCAHSATA_PXSERR_ERR_C_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_C_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_ERR_P_MASK                         (0x00000400U)
#define CSL_DWCAHSATA_PXSERR_ERR_P_SHIFT                        (10U)
#define CSL_DWCAHSATA_PXSERR_ERR_P_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_P_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_ERR_E_MASK                         (0x00000800U)
#define CSL_DWCAHSATA_PXSERR_ERR_E_SHIFT                        (11U)
#define CSL_DWCAHSATA_PXSERR_ERR_E_RESETVAL                     (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_ERR_E_MAX                          (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_N_MASK                        (0x00010000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_N_SHIFT                       (16U)
#define CSL_DWCAHSATA_PXSERR_DIAG_N_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_N_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_I_MASK                        (0x00020000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_I_SHIFT                       (17U)
#define CSL_DWCAHSATA_PXSERR_DIAG_I_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_I_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_W_MASK                        (0x00040000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_W_SHIFT                       (18U)
#define CSL_DWCAHSATA_PXSERR_DIAG_W_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_W_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_B_MASK                        (0x00080000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_B_SHIFT                       (19U)
#define CSL_DWCAHSATA_PXSERR_DIAG_B_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_B_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_D_MASK                        (0x00100000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_D_SHIFT                       (20U)
#define CSL_DWCAHSATA_PXSERR_DIAG_D_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_D_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_C_MASK                        (0x00200000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_C_SHIFT                       (21U)
#define CSL_DWCAHSATA_PXSERR_DIAG_C_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_C_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_H_MASK                        (0x00400000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_H_SHIFT                       (22U)
#define CSL_DWCAHSATA_PXSERR_DIAG_H_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_H_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_S_MASK                        (0x00800000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_S_SHIFT                       (23U)
#define CSL_DWCAHSATA_PXSERR_DIAG_S_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_S_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_T_MASK                        (0x01000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_T_SHIFT                       (24U)
#define CSL_DWCAHSATA_PXSERR_DIAG_T_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_T_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_F_MASK                        (0x02000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_F_SHIFT                       (25U)
#define CSL_DWCAHSATA_PXSERR_DIAG_F_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_F_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_DIAG_X_MASK                        (0x04000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_X_SHIFT                       (26U)
#define CSL_DWCAHSATA_PXSERR_DIAG_X_RESETVAL                    (0x00000000U)
#define CSL_DWCAHSATA_PXSERR_DIAG_X_MAX                         (0x00000001U)

#define CSL_DWCAHSATA_PXSERR_RESETVAL                           (0x00000000U)

/* PXSACT */

#define CSL_DWCAHSATA_PXSACT_DS_MASK                            (0xFFFFFFFFU)
#define CSL_DWCAHSATA_PXSACT_DS_SHIFT                           (0U)
#define CSL_DWCAHSATA_PXSACT_DS_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXSACT_DS_MAX                             (0xffffffffU)

#define CSL_DWCAHSATA_PXSACT_RESETVAL                           (0x00000000U)

/* PXCI */

#define CSL_DWCAHSATA_PXCI_CI_MASK                              (0xFFFFFFFFU)
#define CSL_DWCAHSATA_PXCI_CI_SHIFT                             (0U)
#define CSL_DWCAHSATA_PXCI_CI_RESETVAL                          (0x00000000U)
#define CSL_DWCAHSATA_PXCI_CI_MAX                               (0xffffffffU)

#define CSL_DWCAHSATA_PXCI_RESETVAL                             (0x00000000U)

/* PXSNTF */

#define CSL_DWCAHSATA_PXSNTF_PMN_MASK                           (0x0000FFFFU)
#define CSL_DWCAHSATA_PXSNTF_PMN_SHIFT                          (0U)
#define CSL_DWCAHSATA_PXSNTF_PMN_RESETVAL                       (0x00000000U)
#define CSL_DWCAHSATA_PXSNTF_PMN_MAX                            (0x0000ffffU)

#define CSL_DWCAHSATA_PXSNTF_RESETVAL                           (0x00000000U)

/* PXDMACR */

#define CSL_DWCAHSATA_PXDMACR_TXTS_MASK                         (0x0000000FU)
#define CSL_DWCAHSATA_PXDMACR_TXTS_SHIFT                        (0U)
#define CSL_DWCAHSATA_PXDMACR_TXTS_RESETVAL                     (0x00000005U)
#define CSL_DWCAHSATA_PXDMACR_TXTS_MAX                          (0x0000000fU)

#define CSL_DWCAHSATA_PXDMACR_RXTS_MASK                         (0x000000F0U)
#define CSL_DWCAHSATA_PXDMACR_RXTS_SHIFT                        (4U)
#define CSL_DWCAHSATA_PXDMACR_RXTS_RESETVAL                     (0x00000006U)
#define CSL_DWCAHSATA_PXDMACR_RXTS_MAX                          (0x0000000fU)

#define CSL_DWCAHSATA_PXDMACR_RESETVAL                          (0x00000065U)

/* PXCLBU */

#define CSL_DWCAHSATA_PXCLBU_CLBU_MASK                          (0xFFFFFFFFU)
#define CSL_DWCAHSATA_PXCLBU_CLBU_SHIFT                         (0U)
#define CSL_DWCAHSATA_PXCLBU_CLBU_RESETVAL                      (0x00000000U)
#define CSL_DWCAHSATA_PXCLBU_CLBU_MAX                           (0xffffffffU)

#define CSL_DWCAHSATA_PXCLBU_RESETVAL                           (0x00000000U)

/* PXFBU */

#define CSL_DWCAHSATA_PXFBU_FBU_MASK                            (0xFFFFFFFFU)
#define CSL_DWCAHSATA_PXFBU_FBU_SHIFT                           (0U)
#define CSL_DWCAHSATA_PXFBU_FBU_RESETVAL                        (0x00000000U)
#define CSL_DWCAHSATA_PXFBU_FBU_MAX                             (0xffffffffU)

#define CSL_DWCAHSATA_PXFBU_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
