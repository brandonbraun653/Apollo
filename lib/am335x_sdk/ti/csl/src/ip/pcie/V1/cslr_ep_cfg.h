/********************************************************************
 * Copyright (C) 2013-2016 Texas Instruments Incorporated.
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
#ifndef CSLR_EPCFG_H
#define CSLR_EPCFG_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for PCIE_CAP_STRUC
**************************************************************************/
typedef struct {
    volatile Uint32 PCIE_CAP;
    volatile Uint32 DEV_CAP;
    volatile Uint32 DEV_CAS;
    volatile Uint32 LNK_CAP;
    volatile Uint32 LNK_CAS;
    volatile Uint8  RSVD0[16];
    volatile Uint32 DEV_CAP_2;
    volatile Uint32 DEV_CAS_2;
    volatile Uint32 LNK_CAP_2;
    volatile Uint32 LNK_CAS_2;
    volatile Uint8  RSVD1[12];
} CSL_EpcfgPcie_cap_strucRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 DEVICE_VENDORID;
    volatile Uint32 STATUS_COMMAND_REGISTER;
    volatile Uint32 CLASSCODE_REVISIONID;
    volatile Uint32 BIST_HEAD_LAT_CACH;
#ifdef CSL_MODIFICATION
    volatile Uint32 BAR0;
    volatile Uint32 BAR1;
    volatile Uint32 BAR2;
    volatile Uint32 BAR3;
    volatile Uint32 BAR4;
    volatile Uint32 BAR5;
#else
    volatile Uint32 BAR[6];
#endif
    volatile Uint32 CARDBUS_CIS_POINTER;
    volatile Uint32 SUBID_SUBVENDORID;
    volatile Uint32 EXPANSION_ROM_BAR;
    volatile Uint32 CAPPTR;
    volatile Uint8  RSVD2[4];
    volatile Uint32 INTERRUPT;
    volatile Uint8  RSVD3[48];
    CSL_EpcfgPcie_cap_strucRegs	PCIE_CAP_STRUC;
} CSL_EpCfgRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Device and Vendor ID */
#define CSL_EPCFG_DEVICE_VENDORID                               (0x0U)

/* Status and Command registers */
#define CSL_EPCFG_STATUS_COMMAND_REGISTER                       (0x4U)

/* Class code and Revision ID */
#define CSL_EPCFG_CLASSCODE_REVISIONID                          (0x8U)

/* BIST, Header Type, Latency Timer, Cache Line Size */
#define CSL_EPCFG_BIST_HEAD_LAT_CACH                            (0xCU)

#ifdef CSL_MODIFICATION
/* Base Address Register 0 Bit #0 is also a WO BAR enable (CS2) BAR Mask is
 * writable (CS2) */
#define CSL_EPCFG_BAR0                                          (0x10U)

/* Base Address Register 1 If BAR0.AS = 64-bit: upper half of BAR0 base
 * address If BAR0.AS = 32-bit: independent 32-bit BAR Bit #0 is also a WO BAR
 * enable (CS2) BAR Mask is writable (CS2) */
#define CSL_EPCFG_BAR1                                          (0x14U)

/* Base Address Register 2 Bit #0 is also a WO BAR enable (CS2) BAR Mask is
 * writable (CS2) */
#define CSL_EPCFG_BAR2                                          (0x18U)

/* Base Address Register 3 If BAR2.AS = 64-bit: upper half of BAR2 base
 * address If BAR2.AS = 32-bit: independent 32-bit BAR Bit #0 is also a WO BAR
 * enable (CS2) BAR Mask is writable (CS2) */
#define CSL_EPCFG_BAR3                                          (0x1CU)

/* Base Address Register 4 Bit #0 is also a WO BAR enable (CS2) BAR Mask is
 * writable (CS2) */
#define CSL_EPCFG_BAR4                                          (0x20U)

/* Base Address Register 5 If BAR4.AS = 64-bit: upper half of BAR4 base
 * address If BAR4.AS = 32-bit: independent 32-bit BAR Bit #0 is also a WO BAR
 * enable (CS2) BAR Mask is writable (CS2) */
#define CSL_EPCFG_BAR5                                          (0x24U)
#else
/* For 32-bit BAR: for all n Bit #0 is also a WO BAR enable (CS2) BAR Mask is
 * writable (CS2) 
 * For 64-bit BAR (BARN.AS): for all even n, BAR N's lower half
 *                           for all odd n, BAR N's upper half.
 */
#define CSL_EPCFG_BAR(n)                                   (0x10U + (0x4U*(n)))
#endif

/* CARDBUS_CIS_POINTER */
#define CSL_EPCFG_CARDBUS_CIS_POINTER                           (0x28U)

/* SUBID_SUBVENDORID */
#define CSL_EPCFG_SUBID_SUBVENDORID                             (0x2CU)

/* Expansion ROM Base Address Register */
#define CSL_EPCFG_EXPANSION_ROM_BAR                             (0x30U)

/* CapPtr */
#define CSL_EPCFG_CAPPTR                                        (0x34U)

/* Int Pin and line */
#define CSL_EPCFG_INTERRUPT                                     (0x3CU)

/* PCI Express Capability structure header */
#define CSL_EPCFG_PCIE_CAP                                      (0x70U)

/* PCIE Device Capabilities */
#define CSL_EPCFG_DEV_CAP                                       (0x74U)

/* PCIE Device Control and Status */
#define CSL_EPCFG_DEV_CAS                                       (0x78U)

/* PCIE Link Capabilities */
#define CSL_EPCFG_LNK_CAP                                       (0x7CU)

/* PCIE Link Control and Status */
#define CSL_EPCFG_LNK_CAS                                       (0x80U)

/* Device Capabilities 2 Register */
#define CSL_EPCFG_DEV_CAP_2                                     (0x94U)

/* Device Control 2 Register */
#define CSL_EPCFG_DEV_CAS_2                                     (0x98U)

/* PCIE Link Capabilities 2 Register */
#define CSL_EPCFG_LNK_CAP_2                                     (0x9CU)

/* Link Control and Status 2 Register (Sticky) */
#define CSL_EPCFG_LNK_CAS_2                                     (0xA0U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DEVICE_VENDORID */

#define CSL_EPCFG_DEVICE_VENDORID_VENDORID_MASK                 (0x0000FFFFU)
#define CSL_EPCFG_DEVICE_VENDORID_VENDORID_SHIFT                (0U)
#define CSL_EPCFG_DEVICE_VENDORID_VENDORID_RESETVAL             (0x0000104cU)
#define CSL_EPCFG_DEVICE_VENDORID_VENDORID_MAX                  (0x0000ffffU)

#define CSL_EPCFG_DEVICE_VENDORID_DEVICEID_MASK                 (0xFFFF0000U)
#define CSL_EPCFG_DEVICE_VENDORID_DEVICEID_SHIFT                (16U)
#define CSL_EPCFG_DEVICE_VENDORID_DEVICEID_RESETVAL             (0x00008888U)
#define CSL_EPCFG_DEVICE_VENDORID_DEVICEID_MAX                  (0x0000ffffU)

#define CSL_EPCFG_DEVICE_VENDORID_RESETVAL                      (0x8888104cU)

/* STATUS_COMMAND_REGISTER */

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IO_SPACE_EN_MASK      (0x00000001U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IO_SPACE_EN_SHIFT     (0U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IO_SPACE_EN_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IO_SPACE_EN_MAX       (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEM_SPACE_EN_MASK     (0x00000002U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEM_SPACE_EN_SHIFT    (1U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEM_SPACE_EN_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEM_SPACE_EN_MAX      (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_BUSMASTER_EN_MASK     (0x00000004U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_BUSMASTER_EN_SHIFT    (2U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_BUSMASTER_EN_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_BUSMASTER_EN_MAX      (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SPEC_CYCLE_EN_MASK    (0x00000008U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SPEC_CYCLE_EN_SHIFT   (3U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SPEC_CYCLE_EN_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SPEC_CYCLE_EN_MAX     (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEMWR_INVA_MASK       (0x00000010U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEMWR_INVA_SHIFT      (4U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEMWR_INVA_RESETVAL   (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MEMWR_INVA_MAX        (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_VGA_SNOOP_MASK        (0x00000020U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_VGA_SNOOP_SHIFT       (5U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_VGA_SNOOP_RESETVAL    (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_VGA_SNOOP_MAX         (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_PARITYERRRESP_MASK    (0x00000040U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_PARITYERRRESP_SHIFT   (6U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_PARITYERRRESP_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_PARITYERRRESP_MAX     (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IDSEL_CTRL_MASK       (0x00000080U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IDSEL_CTRL_SHIFT      (7U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IDSEL_CTRL_RESETVAL   (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_IDSEL_CTRL_MAX        (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SERR_EN_MASK          (0x00000100U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SERR_EN_SHIFT         (8U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SERR_EN_RESETVAL      (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SERR_EN_MAX           (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_BBEN_MASK        (0x00000200U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_BBEN_SHIFT       (9U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_BBEN_RESETVAL    (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_BBEN_MAX         (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_ASSER_DIS_MASK   (0x00000400U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_ASSER_DIS_SHIFT  (10U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_ASSER_DIS_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_ASSER_DIS_MAX    (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_STATUS_MASK      (0x00080000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_STATUS_SHIFT     (19U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_STATUS_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_INTX_STATUS_MAX       (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_CAP_LIST_MASK         (0x00100000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_CAP_LIST_SHIFT        (20U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_CAP_LIST_RESETVAL     (0x00000001U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_CAP_LIST_MAX          (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_C66MHZ_CAP_MASK       (0x00200000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_C66MHZ_CAP_SHIFT      (21U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_C66MHZ_CAP_RESETVAL   (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_C66MHZ_CAP_MAX        (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RESERV3_MASK          (0x00400000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RESERV3_SHIFT         (22U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RESERV3_RESETVAL      (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RESERV3_MAX           (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_B2B_MASK         (0x00800000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_B2B_SHIFT        (23U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_B2B_RESETVAL     (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_FAST_B2B_MAX          (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MASTERDATA_PARERR_MASK  (0x01000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MASTERDATA_PARERR_SHIFT  (24U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MASTERDATA_PARERR_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_MASTERDATA_PARERR_MAX  (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DEVSEL_TIME_MASK      (0x06000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DEVSEL_TIME_SHIFT     (25U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DEVSEL_TIME_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DEVSEL_TIME_MAX       (0x00000003U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_TRGTABORT_MASK  (0x08000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_TRGTABORT_SHIFT  (27U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_TRGTABORT_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_TRGTABORT_MAX  (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_TRGTABORT_MASK   (0x10000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_TRGTABORT_SHIFT  (28U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_TRGTABORT_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_TRGTABORT_MAX    (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_MASTERABORT_MASK  (0x20000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_MASTERABORT_SHIFT  (29U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_MASTERABORT_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RCVD_MASTERABORT_MAX  (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_SYSERR_MASK    (0x40000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_SYSERR_SHIFT   (30U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_SYSERR_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_SIGNAL_SYSERR_MAX     (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DETECT_PARERR_MASK    (0x80000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DETECT_PARERR_SHIFT   (31U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DETECT_PARERR_RESETVAL  (0x00000000U)
#define CSL_EPCFG_STATUS_COMMAND_REGISTER_DETECT_PARERR_MAX     (0x00000001U)

#define CSL_EPCFG_STATUS_COMMAND_REGISTER_RESETVAL              (0x00100000U)

/* CLASSCODE_REVISIONID */

#define CSL_EPCFG_CLASSCODE_REVISIONID_REVID_MASK               (0x000000FFU)
#define CSL_EPCFG_CLASSCODE_REVISIONID_REVID_SHIFT              (0U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_REVID_RESETVAL           (0x00000001U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_REVID_MAX                (0x000000ffU)

#define CSL_EPCFG_CLASSCODE_REVISIONID_PROG_IF_CODE_MASK        (0x0000FF00U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_PROG_IF_CODE_SHIFT       (8U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_PROG_IF_CODE_RESETVAL    (0x00000000U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_PROG_IF_CODE_MAX         (0x000000ffU)

#define CSL_EPCFG_CLASSCODE_REVISIONID_SUBCLS_CD_MASK           (0x00FF0000U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_SUBCLS_CD_SHIFT          (16U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_SUBCLS_CD_RESETVAL       (0x00000000U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_SUBCLS_CD_MAX            (0x000000ffU)

#define CSL_EPCFG_CLASSCODE_REVISIONID_BASE_CLS_CD_MASK         (0xFF000000U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_BASE_CLS_CD_SHIFT        (24U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_BASE_CLS_CD_RESETVAL     (0x00000000U)
#define CSL_EPCFG_CLASSCODE_REVISIONID_BASE_CLS_CD_MAX          (0x000000ffU)

#define CSL_EPCFG_CLASSCODE_REVISIONID_RESETVAL                 (0x00000001U)

/* BIST_HEAD_LAT_CACH */

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_CACH_LN_SZE_MASK           (0x000000FFU)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_CACH_LN_SZE_SHIFT          (0U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_CACH_LN_SZE_RESETVAL       (0x00000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_CACH_LN_SZE_MAX            (0x000000ffU)

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MSTR_LAT_TIM_MASK          (0x0000FF00U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MSTR_LAT_TIM_SHIFT         (8U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MSTR_LAT_TIM_RESETVAL      (0x00000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MSTR_LAT_TIM_MAX           (0x000000ffU)

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_HEAD_TYP_MASK              (0x007F0000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_HEAD_TYP_SHIFT             (16U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_HEAD_TYP_RESETVAL          (0x00000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_HEAD_TYP_MAX               (0x0000007fU)

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MFD_MASK                   (0x00800000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MFD_SHIFT                  (23U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MFD_RESETVAL               (0x00000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_MFD_MAX                    (0x00000001U)

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_BIST_MASK                  (0xFF000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_BIST_SHIFT                 (24U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_BIST_RESETVAL              (0x00000000U)
#define CSL_EPCFG_BIST_HEAD_LAT_CACH_BIST_MAX                   (0x000000ffU)

#define CSL_EPCFG_BIST_HEAD_LAT_CACH_RESETVAL                   (0x00000000U)

#ifdef CSL_MODIFICATION
/* BAR0 */

#define CSL_EPCFG_BAR0_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR0_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR0_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR0_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR0_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR0_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR0_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR0_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR0_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR0_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR0_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR0_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR0_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR0_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR0_BASE_ADDR_RO_MASK                        (0x000FFFF0U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RO_MAX                         (0x0000ffffU)

#define CSL_EPCFG_BAR0_BASE_ADDR_RW_MASK                        (0xFFF00000U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RW_SHIFT                       (20U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR0_BASE_ADDR_RW_MAX                         (0x00000fffU)

#define CSL_EPCFG_BAR0_RESETVAL                                 (0x00000008U)

/* BAR1 */

#define CSL_EPCFG_BAR1_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR1_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR1_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR1_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR1_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR1_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR1_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR1_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR1_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR1_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR1_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR1_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR1_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR1_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR1_BASE_ADDR_RO_MASK                        (0x000FFFF0U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RO_MAX                         (0x0000ffffU)

#define CSL_EPCFG_BAR1_BASE_ADDR_RW_MASK                        (0xFFF00000U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RW_SHIFT                       (20U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR1_BASE_ADDR_RW_MAX                         (0x00000fffU)

#define CSL_EPCFG_BAR1_RESETVAL                                 (0x00000008U)

/* BAR2 */

#define CSL_EPCFG_BAR2_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR2_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR2_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR2_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR2_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR2_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR2_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR2_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR2_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR2_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR2_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR2_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR2_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR2_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR2_BASE_ADDR_RW_MASK                        (0xFFF00000U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RW_SHIFT                       (20U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RW_MAX                         (0x00000fffU)

#define CSL_EPCFG_BAR2_BASE_ADDR_RO_MASK                        (0x000FFFF0U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR2_BASE_ADDR_RO_MAX                         (0x0000ffffU)

#define CSL_EPCFG_BAR2_RESETVAL                                 (0x00000008U)

/* BAR3 */

#define CSL_EPCFG_BAR3_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR3_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR3_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR3_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR3_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR3_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR3_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR3_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR3_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR3_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR3_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR3_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR3_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR3_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR3_BASE_ADDR_RO_MASK                        (0x000FFFF0U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RO_MAX                         (0x0000ffffU)

#define CSL_EPCFG_BAR3_BASE_ADDR_RW_MASK                        (0xFFF00000U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RW_SHIFT                       (20U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR3_BASE_ADDR_RW_MAX                         (0x00000fffU)

#define CSL_EPCFG_BAR3_RESETVAL                                 (0x00000008U)

/* BAR4 */

#define CSL_EPCFG_BAR4_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR4_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR4_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR4_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR4_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR4_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR4_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR4_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR4_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR4_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR4_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR4_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR4_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR4_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR4_BASE_ADDR_RW_MASK                        (0xFFFFF000U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RW_SHIFT                       (12U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RW_MAX                         (0x000fffffU)

#define CSL_EPCFG_BAR4_BASE_ADDR_RO_MASK                        (0x00000FF0U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR4_BASE_ADDR_RO_MAX                         (0x000000ffU)

#define CSL_EPCFG_BAR4_RESETVAL                                 (0x00000008U)

/* BAR5 */

#define CSL_EPCFG_BAR5_SPACE_INDICATOR_MASK                     (0x00000001U)
#define CSL_EPCFG_BAR5_SPACE_INDICATOR_SHIFT                    (0U)
#define CSL_EPCFG_BAR5_SPACE_INDICATOR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_BAR5_SPACE_INDICATOR_MEM                      (0x00000000U)
#define CSL_EPCFG_BAR5_SPACE_INDICATOR_IO                       (0x00000001U)

#define CSL_EPCFG_BAR5_AS_MASK                                  (0x00000006U)
#define CSL_EPCFG_BAR5_AS_SHIFT                                 (1U)
#define CSL_EPCFG_BAR5_AS_RESETVAL                              (0x00000000U)
#define CSL_EPCFG_BAR5_AS__32BIT                                (0x00000000U)
#define CSL_EPCFG_BAR5_AS__64BIT                                (0x00000002U)

#define CSL_EPCFG_BAR5_PREFETCHABLE_MASK                        (0x00000008U)
#define CSL_EPCFG_BAR5_PREFETCHABLE_SHIFT                       (3U)
#define CSL_EPCFG_BAR5_PREFETCHABLE_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_BAR5_PREFETCHABLE_MAX                         (0x00000001U)

#define CSL_EPCFG_BAR5_BASE_ADDR_RO_MASK                        (0x000FFFF0U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RO_SHIFT                       (4U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RO_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RO_MAX                         (0x0000ffffU)

#define CSL_EPCFG_BAR5_BASE_ADDR_RW_MASK                        (0xFFF00000U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RW_SHIFT                       (20U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RW_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_BAR5_BASE_ADDR_RW_MAX                         (0x00000fffU)

#define CSL_EPCFG_BAR5_RESETVAL                                 (0x00000008U)
#else

#define CSL_EPCFG_BAR_SPACE_INDICATOR_MASK                      (0x00000001U)
#define CSL_EPCFG_BAR_SPACE_INDICATOR_SHIFT                     (0U)
#define CSL_EPCFG_BAR_SPACE_INDICATOR_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_BAR_SPACE_INDICATOR_MEM                       (0x00000000U)
#define CSL_EPCFG_BAR_SPACE_INDICATOR_IO                        (0x00000001U)

#define CSL_EPCFG_BAR_AS_MASK                                   (0x00000006U)
#define CSL_EPCFG_BAR_AS_SHIFT                                  (1U)
#define CSL_EPCFG_BAR_AS_RESETVAL                               (0x00000000U)
#define CSL_EPCFG_BAR_AS__32BIT                                 (0x00000000U)
#define CSL_EPCFG_BAR_AS__64BIT                                 (0x00000002U)

#define CSL_EPCFG_BAR_PREFETCHABLE_MASK                         (0x00000008U)
#define CSL_EPCFG_BAR_PREFETCHABLE_SHIFT                        (3U)
#define CSL_EPCFG_BAR_PREFETCHABLE_RESETVAL                     (0x00000001U)
#define CSL_EPCFG_BAR_PREFETCHABLE_MAX                          (0x00000001U)

#define CSL_EPCFG_BAR_BASE_ADDR_RO_MASK                         (0x000FFFF0U)
#define CSL_EPCFG_BAR_BASE_ADDR_RO_SHIFT                        (4U)
#define CSL_EPCFG_BAR_BASE_ADDR_RO_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_BAR_BASE_ADDR_RO_MAX                          (0x0000ffffU)

#define CSL_EPCFG_BAR_BASE_ADDR_RW_MASK                         (0xFFF00000U)
#define CSL_EPCFG_BAR_BASE_ADDR_RW_SHIFT                        (20U)
#define CSL_EPCFG_BAR_BASE_ADDR_RW_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_BAR_BASE_ADDR_RW_MAX                          (0x00000fffU)

#define CSL_EPCFG_BAR_RESETVAL                                 (0x00000008U)
#endif

/* CARDBUS_CIS_POINTER */

#define CSL_EPCFG_CARDBUS_CIS_POINTER_CARDBUS_CIS_PTR_N_MASK    (0xFFFFFFFFU)
#define CSL_EPCFG_CARDBUS_CIS_POINTER_CARDBUS_CIS_PTR_N_SHIFT   (0U)
#define CSL_EPCFG_CARDBUS_CIS_POINTER_CARDBUS_CIS_PTR_N_RESETVAL  (0x00000000U)
#define CSL_EPCFG_CARDBUS_CIS_POINTER_CARDBUS_CIS_PTR_N_MAX     (0xffffffffU)

#define CSL_EPCFG_CARDBUS_CIS_POINTER_RESETVAL                  (0x00000000U)

/* SUBID_SUBVENDORID */

#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_VENDOR_ID_N_MASK     (0x0000FFFFU)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_VENDOR_ID_N_SHIFT    (0U)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_VENDOR_ID_N_RESETVAL  (0x00000000U)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_VENDOR_ID_N_MAX      (0x0000ffffU)

#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_DEV_ID_N_MASK        (0xFFFF0000U)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_DEV_ID_N_SHIFT       (16U)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_DEV_ID_N_RESETVAL    (0x00000001U)
#define CSL_EPCFG_SUBID_SUBVENDORID_SUBSYS_DEV_ID_N_MAX         (0x0000ffffU)

#define CSL_EPCFG_SUBID_SUBVENDORID_RESETVAL                    (0x00010000U)

/* EXPANSION_ROM_BAR */

#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_EN_MASK               (0x00000001U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_EN_SHIFT              (0U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_EN_RESETVAL           (0x00000000U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_EN_MAX                (0x00000001U)

#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_RO_MASK       (0x0000F800U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_RO_SHIFT      (11U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_RO_RESETVAL   (0x00000000U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_RO_MAX        (0x0000001fU)

#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_MASK          (0xFFFF0000U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_SHIFT         (16U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_RESETVAL      (0x00000000U)
#define CSL_EPCFG_EXPANSION_ROM_BAR_EXROM_ADDRESS_MAX           (0x0000ffffU)

#define CSL_EPCFG_EXPANSION_ROM_BAR_RESETVAL                    (0x00000000U)

/* CAPPTR */

#define CSL_EPCFG_CAPPTR_CAPTR_MASK                             (0x000000FFU)
#define CSL_EPCFG_CAPPTR_CAPTR_SHIFT                            (0U)
#define CSL_EPCFG_CAPPTR_CAPTR_RESETVAL                         (0x00000040U)
#define CSL_EPCFG_CAPPTR_CAPTR_MAX                              (0x000000ffU)

#define CSL_EPCFG_CAPPTR_RESETVAL                               (0x00000040U)

/* INTERRUPT */

#define CSL_EPCFG_INTERRUPT_INT_LIN_MASK                        (0x000000FFU)
#define CSL_EPCFG_INTERRUPT_INT_LIN_SHIFT                       (0U)
#define CSL_EPCFG_INTERRUPT_INT_LIN_RESETVAL                    (0x000000ffU)
#define CSL_EPCFG_INTERRUPT_INT_LIN_MAX                         (0x000000ffU)

#define CSL_EPCFG_INTERRUPT_INT_PIN_MASK                        (0x0000FF00U)
#define CSL_EPCFG_INTERRUPT_INT_PIN_SHIFT                       (8U)
#define CSL_EPCFG_INTERRUPT_INT_PIN_RESETVAL                    (0x00000001U)
#define CSL_EPCFG_INTERRUPT_INT_PIN_MAX                         (0x000000ffU)

#define CSL_EPCFG_INTERRUPT_RESETVAL                            (0x000001ffU)

/* PCIE_CAP */

#define CSL_EPCFG_PCIE_CAP_CAP_ID_MASK                          (0x000000FFU)
#define CSL_EPCFG_PCIE_CAP_CAP_ID_SHIFT                         (0U)
#define CSL_EPCFG_PCIE_CAP_CAP_ID_RESETVAL                      (0x00000010U)
#define CSL_EPCFG_PCIE_CAP_CAP_ID_MAX                           (0x000000ffU)

#define CSL_EPCFG_PCIE_CAP_PCIE_NX_PTR_MASK                     (0x0000FF00U)
#define CSL_EPCFG_PCIE_CAP_PCIE_NX_PTR_SHIFT                    (8U)
#define CSL_EPCFG_PCIE_CAP_PCIE_NX_PTR_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_PCIE_CAP_PCIE_NX_PTR_MAX                      (0x000000ffU)

#define CSL_EPCFG_PCIE_CAP_PCIE_VER_MASK                        (0x000F0000U)
#define CSL_EPCFG_PCIE_CAP_PCIE_VER_SHIFT                       (16U)
#define CSL_EPCFG_PCIE_CAP_PCIE_VER_RESETVAL                    (0x00000002U)
#define CSL_EPCFG_PCIE_CAP_PCIE_VER_MAX                         (0x0000000fU)

#define CSL_EPCFG_PCIE_CAP_DEV_TYPE_MASK                        (0x00F00000U)
#define CSL_EPCFG_PCIE_CAP_DEV_TYPE_SHIFT                       (20U)
#define CSL_EPCFG_PCIE_CAP_DEV_TYPE_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_PCIE_CAP_DEV_TYPE_MAX                         (0x0000000fU)

#define CSL_EPCFG_PCIE_CAP_SLOT_MASK                            (0x01000000U)
#define CSL_EPCFG_PCIE_CAP_SLOT_SHIFT                           (24U)
#define CSL_EPCFG_PCIE_CAP_SLOT_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_PCIE_CAP_SLOT_MAX                             (0x00000001U)

#define CSL_EPCFG_PCIE_CAP_IM_NUM_MASK                          (0x3E000000U)
#define CSL_EPCFG_PCIE_CAP_IM_NUM_SHIFT                         (25U)
#define CSL_EPCFG_PCIE_CAP_IM_NUM_RESETVAL                      (0x00000000U)
#define CSL_EPCFG_PCIE_CAP_IM_NUM_MAX                           (0x0000001fU)

#define CSL_EPCFG_PCIE_CAP_RESETVAL                             (0x00020010U)

/* DEV_CAP */

#define CSL_EPCFG_DEV_CAP_MAX_PAYLOAD_SIZE_MASK                 (0x00000007U)
#define CSL_EPCFG_DEV_CAP_MAX_PAYLOAD_SIZE_SHIFT                (0U)
#define CSL_EPCFG_DEV_CAP_MAX_PAYLOAD_SIZE_RESETVAL             (0x00000001U)
#define CSL_EPCFG_DEV_CAP_MAX_PAYLOAD_SIZE__256_BYTE            (0x00000001U)

#define CSL_EPCFG_DEV_CAP_PHANTOMFUNC_MASK                      (0x00000018U)
#define CSL_EPCFG_DEV_CAP_PHANTOMFUNC_SHIFT                     (3U)
#define CSL_EPCFG_DEV_CAP_PHANTOMFUNC_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_DEV_CAP_PHANTOMFUNC_MAX                       (0x00000003U)

#define CSL_EPCFG_DEV_CAP_EXTTAGFIELD_SUPPORT_MASK              (0x00000020U)
#define CSL_EPCFG_DEV_CAP_EXTTAGFIELD_SUPPORT_SHIFT             (5U)
#define CSL_EPCFG_DEV_CAP_EXTTAGFIELD_SUPPORT_RESETVAL          (0x00000000U)
#define CSL_EPCFG_DEV_CAP_EXTTAGFIELD_SUPPORT_MAX               (0x00000001U)

#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L0S_ACCPT_LATENCY_MASK     (0x000001C0U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L0S_ACCPT_LATENCY_SHIFT    (6U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L0S_ACCPT_LATENCY_RESETVAL  (0x00000004U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L0S_ACCPT_LATENCY_MAX      (0x00000007U)

#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L1_ACCPT_LATENCY_MASK      (0x00000E00U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L1_ACCPT_LATENCY_SHIFT     (9U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L1_ACCPT_LATENCY_RESETVAL  (0x00000003U)
#define CSL_EPCFG_DEV_CAP_DEFAULT_EP_L1_ACCPT_LATENCY_MAX       (0x00000007U)

#define CSL_EPCFG_DEV_CAP_UNDEFINED_MASK                        (0x00007000U)
#define CSL_EPCFG_DEV_CAP_UNDEFINED_SHIFT                       (12U)
#define CSL_EPCFG_DEV_CAP_UNDEFINED_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_DEV_CAP_UNDEFINED_MAX                         (0x00000007U)

#define CSL_EPCFG_DEV_CAP_ROLEBASED_ERRRPT_MASK                 (0x00008000U)
#define CSL_EPCFG_DEV_CAP_ROLEBASED_ERRRPT_SHIFT                (15U)
#define CSL_EPCFG_DEV_CAP_ROLEBASED_ERRRPT_RESETVAL             (0x00000001U)
#define CSL_EPCFG_DEV_CAP_ROLEBASED_ERRRPT_MAX                  (0x00000001U)

#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_VALUE_MASK         (0x03FC0000U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_VALUE_SHIFT        (18U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_VALUE_RESETVAL     (0x00000000U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_VALUE_MAX          (0x000000ffU)

#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_SCALE_MASK         (0x0C000000U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_SCALE_SHIFT        (26U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_SCALE_RESETVAL     (0x00000000U)
#define CSL_EPCFG_DEV_CAP_CAPT_SLOW_PWRLIMIT_SCALE_MAX          (0x00000003U)

#define CSL_EPCFG_DEV_CAP_FLR_EN_MASK                           (0x10000000U)
#define CSL_EPCFG_DEV_CAP_FLR_EN_SHIFT                          (28U)
#define CSL_EPCFG_DEV_CAP_FLR_EN_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_DEV_CAP_FLR_EN_MAX                            (0x00000001U)

#define CSL_EPCFG_DEV_CAP_RESETVAL                              (0x00008701U)

/* DEV_CAS */

#define CSL_EPCFG_DEV_CAS_COR_RE_MASK                           (0x00000001U)
#define CSL_EPCFG_DEV_CAS_COR_RE_SHIFT                          (0U)
#define CSL_EPCFG_DEV_CAS_COR_RE_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_DEV_CAS_COR_RE_MAX                            (0x00000001U)

#define CSL_EPCFG_DEV_CAS_NFT_RE_MASK                           (0x00000002U)
#define CSL_EPCFG_DEV_CAS_NFT_RE_SHIFT                          (1U)
#define CSL_EPCFG_DEV_CAS_NFT_RE_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_DEV_CAS_NFT_RE_MAX                            (0x00000001U)

#define CSL_EPCFG_DEV_CAS_FT_RE_MASK                            (0x00000004U)
#define CSL_EPCFG_DEV_CAS_FT_RE_SHIFT                           (2U)
#define CSL_EPCFG_DEV_CAS_FT_RE_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_DEV_CAS_FT_RE_MAX                             (0x00000001U)

#define CSL_EPCFG_DEV_CAS_UR_RE_MASK                            (0x00000008U)
#define CSL_EPCFG_DEV_CAS_UR_RE_SHIFT                           (3U)
#define CSL_EPCFG_DEV_CAS_UR_RE_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_DEV_CAS_UR_RE_MAX                             (0x00000001U)

#define CSL_EPCFG_DEV_CAS_EN_RO_MASK                            (0x00000010U)
#define CSL_EPCFG_DEV_CAS_EN_RO_SHIFT                           (4U)
#define CSL_EPCFG_DEV_CAS_EN_RO_RESETVAL                        (0x00000001U)
#define CSL_EPCFG_DEV_CAS_EN_RO_MAX                             (0x00000001U)

#define CSL_EPCFG_DEV_CAS_MPS_MASK                              (0x000000E0U)
#define CSL_EPCFG_DEV_CAS_MPS_SHIFT                             (5U)
#define CSL_EPCFG_DEV_CAS_MPS_RESETVAL                          (0x00000000U)
#define CSL_EPCFG_DEV_CAS_MPS_MAX                               (0x00000007U)

#define CSL_EPCFG_DEV_CAS_EXTAG_EN_MASK                         (0x00000100U)
#define CSL_EPCFG_DEV_CAS_EXTAG_EN_SHIFT                        (8U)
#define CSL_EPCFG_DEV_CAS_EXTAG_EN_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_EXTAG_EN_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_PHFUN_EN_MASK                         (0x00000200U)
#define CSL_EPCFG_DEV_CAS_PHFUN_EN_SHIFT                        (9U)
#define CSL_EPCFG_DEV_CAS_PHFUN_EN_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_PHFUN_EN_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_AUXPM_EN_MASK                         (0x00000400U)
#define CSL_EPCFG_DEV_CAS_AUXPM_EN_SHIFT                        (10U)
#define CSL_EPCFG_DEV_CAS_AUXPM_EN_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_AUXPM_EN_DIS                          (0x00000000U)
#define CSL_EPCFG_DEV_CAS_AUXPM_EN_EN                           (0x00000001U)

#define CSL_EPCFG_DEV_CAS_NOSNP_EN_MASK                         (0x00000800U)
#define CSL_EPCFG_DEV_CAS_NOSNP_EN_SHIFT                        (11U)
#define CSL_EPCFG_DEV_CAS_NOSNP_EN_RESETVAL                     (0x00000001U)
#define CSL_EPCFG_DEV_CAS_NOSNP_EN_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_MRRS_MASK                             (0x00007000U)
#define CSL_EPCFG_DEV_CAS_MRRS_SHIFT                            (12U)
#define CSL_EPCFG_DEV_CAS_MRRS_RESETVAL                         (0x00000002U)
#define CSL_EPCFG_DEV_CAS_MRRS_MAX                              (0x00000007U)

#define CSL_EPCFG_DEV_CAS_INIT_FLR_MASK                         (0x00008000U)
#define CSL_EPCFG_DEV_CAS_INIT_FLR_SHIFT                        (15U)
#define CSL_EPCFG_DEV_CAS_INIT_FLR_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_INIT_FLR_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_COR_DET_MASK                          (0x00010000U)
#define CSL_EPCFG_DEV_CAS_COR_DET_SHIFT                         (16U)
#define CSL_EPCFG_DEV_CAS_COR_DET_RESETVAL                      (0x00000000U)
#define CSL_EPCFG_DEV_CAS_COR_DET_MAX                           (0x00000001U)

#define CSL_EPCFG_DEV_CAS_NFT_DET_MASK                          (0x00020000U)
#define CSL_EPCFG_DEV_CAS_NFT_DET_SHIFT                         (17U)
#define CSL_EPCFG_DEV_CAS_NFT_DET_RESETVAL                      (0x00000000U)
#define CSL_EPCFG_DEV_CAS_NFT_DET_MAX                           (0x00000001U)

#define CSL_EPCFG_DEV_CAS_FT_DET_MASK                           (0x00040000U)
#define CSL_EPCFG_DEV_CAS_FT_DET_SHIFT                          (18U)
#define CSL_EPCFG_DEV_CAS_FT_DET_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_DEV_CAS_FT_DET_MAX                            (0x00000001U)

#define CSL_EPCFG_DEV_CAS_UR_DET_MASK                           (0x00080000U)
#define CSL_EPCFG_DEV_CAS_UR_DET_SHIFT                          (19U)
#define CSL_EPCFG_DEV_CAS_UR_DET_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_DEV_CAS_UR_DET_MAX                            (0x00000001U)

#define CSL_EPCFG_DEV_CAS_AUXP_DET_MASK                         (0x00100000U)
#define CSL_EPCFG_DEV_CAS_AUXP_DET_SHIFT                        (20U)
#define CSL_EPCFG_DEV_CAS_AUXP_DET_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_AUXP_DET_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_TRANS_PEND_MASK                       (0x00200000U)
#define CSL_EPCFG_DEV_CAS_TRANS_PEND_SHIFT                      (21U)
#define CSL_EPCFG_DEV_CAS_TRANS_PEND_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_DEV_CAS_TRANS_PEND_MAX                        (0x00000001U)

#define CSL_EPCFG_DEV_CAS_RESETVAL                              (0x00002810U)

/* LNK_CAP */

#define CSL_EPCFG_LNK_CAP_MAX_LINK_SPEEDS_MASK                  (0x0000000FU)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_SPEEDS_SHIFT                 (0U)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_SPEEDS_RESETVAL              (0x00000002U)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_SPEEDS_MAX                   (0x0000000fU)

#define CSL_EPCFG_LNK_CAP_MAX_LINK_WIDTH_MASK                   (0x000003F0U)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_WIDTH_SHIFT                  (4U)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_WIDTH_RESETVAL               (0x00000002U)
#define CSL_EPCFG_LNK_CAP_MAX_LINK_WIDTH_MAX                    (0x0000003fU)

#define CSL_EPCFG_LNK_CAP_AS_LINK_PM_SUPPORT_MASK               (0x00000C00U)
#define CSL_EPCFG_LNK_CAP_AS_LINK_PM_SUPPORT_SHIFT              (10U)
#define CSL_EPCFG_LNK_CAP_AS_LINK_PM_SUPPORT_RESETVAL           (0x00000003U)
#define CSL_EPCFG_LNK_CAP_AS_LINK_PM_SUPPORT_MAX                (0x00000003U)

#define CSL_EPCFG_LNK_CAP_L0S_EXIT_LAT_MASK                     (0x00007000U)
#define CSL_EPCFG_LNK_CAP_L0S_EXIT_LAT_SHIFT                    (12U)
#define CSL_EPCFG_LNK_CAP_L0S_EXIT_LAT_RESETVAL                 (0x00000003U)
#define CSL_EPCFG_LNK_CAP_L0S_EXIT_LAT_MAX                      (0x00000007U)

#define CSL_EPCFG_LNK_CAP_L1_EXIT_LAT_MASK                      (0x00038000U)
#define CSL_EPCFG_LNK_CAP_L1_EXIT_LAT_SHIFT                     (15U)
#define CSL_EPCFG_LNK_CAP_L1_EXIT_LAT_RESETVAL                  (0x00000006U)
#define CSL_EPCFG_LNK_CAP_L1_EXIT_LAT_MAX                       (0x00000007U)

#define CSL_EPCFG_LNK_CAP_CLK_PWR_MGMT_MASK                     (0x00040000U)
#define CSL_EPCFG_LNK_CAP_CLK_PWR_MGMT_SHIFT                    (18U)
#define CSL_EPCFG_LNK_CAP_CLK_PWR_MGMT_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_LNK_CAP_CLK_PWR_MGMT_MAX                      (0x00000001U)

#define CSL_EPCFG_LNK_CAP_UNSUP_MASK                            (0x00080000U)
#define CSL_EPCFG_LNK_CAP_UNSUP_SHIFT                           (19U)
#define CSL_EPCFG_LNK_CAP_UNSUP_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_LNK_CAP_UNSUP_MAX                             (0x00000001U)

#define CSL_EPCFG_LNK_CAP_DLL_ACTRPT_CAP_MASK                   (0x00100000U)
#define CSL_EPCFG_LNK_CAP_DLL_ACTRPT_CAP_SHIFT                  (20U)
#define CSL_EPCFG_LNK_CAP_DLL_ACTRPT_CAP_RESETVAL               (0x00000000U)
#define CSL_EPCFG_LNK_CAP_DLL_ACTRPT_CAP_MAX                    (0x00000001U)

#define CSL_EPCFG_LNK_CAP_LNK_BW_NOT_CAP_MASK                   (0x00200000U)
#define CSL_EPCFG_LNK_CAP_LNK_BW_NOT_CAP_SHIFT                  (21U)
#define CSL_EPCFG_LNK_CAP_LNK_BW_NOT_CAP_RESETVAL               (0x00000000U)
#define CSL_EPCFG_LNK_CAP_LNK_BW_NOT_CAP_MAX                    (0x00000001U)

#define CSL_EPCFG_LNK_CAP_ASPM_OPT_COMP_MASK                    (0x00400000U)
#define CSL_EPCFG_LNK_CAP_ASPM_OPT_COMP_SHIFT                   (22U)
#define CSL_EPCFG_LNK_CAP_ASPM_OPT_COMP_RESETVAL                (0x00000001U)
#define CSL_EPCFG_LNK_CAP_ASPM_OPT_COMP_MAX                     (0x00000001U)

#define CSL_EPCFG_LNK_CAP_PORT_NUM_MASK                         (0xFF000000U)
#define CSL_EPCFG_LNK_CAP_PORT_NUM_SHIFT                        (24U)
#define CSL_EPCFG_LNK_CAP_PORT_NUM_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_LNK_CAP_PORT_NUM_MAX                          (0x000000ffU)

#define CSL_EPCFG_LNK_CAP_RESETVAL                              (0x00433c22U)

/* LNK_CAS */

#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_MASK                        (0x00000003U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_SHIFT                       (0U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_DISABLED                    (0x00000000U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_L0S_ENABLED                 (0x00000001U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_L1_ENABLED                  (0x00000002U)
#define CSL_EPCFG_LNK_CAS_ASPM_CTRL_L0S_AND_L1_ENABLED          (0x00000003U)

#define CSL_EPCFG_LNK_CAS_RCB_MASK                              (0x00000008U)
#define CSL_EPCFG_LNK_CAS_RCB_SHIFT                             (3U)
#define CSL_EPCFG_LNK_CAS_RCB_RESETVAL                          (0x00000000U)
#define CSL_EPCFG_LNK_CAS_RCB__64_BYTE                          (0x00000000U)
#define CSL_EPCFG_LNK_CAS_RCB__128_BYTE                         (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LINK_DIS_MASK                         (0x00000010U)
#define CSL_EPCFG_LNK_CAS_LINK_DIS_SHIFT                        (4U)
#define CSL_EPCFG_LNK_CAS_LINK_DIS_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LINK_DIS_MAX                          (0x00000001U)

#define CSL_EPCFG_LNK_CAS_RETRAIN_LINK_MASK                     (0x00000020U)
#define CSL_EPCFG_LNK_CAS_RETRAIN_LINK_SHIFT                    (5U)
#define CSL_EPCFG_LNK_CAS_RETRAIN_LINK_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_LNK_CAS_RETRAIN_LINK_MAX                      (0x00000001U)

#define CSL_EPCFG_LNK_CAS_COM_CLK_CFG_MASK                      (0x00000040U)
#define CSL_EPCFG_LNK_CAS_COM_CLK_CFG_SHIFT                     (6U)
#define CSL_EPCFG_LNK_CAS_COM_CLK_CFG_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_LNK_CAS_COM_CLK_CFG_MAX                       (0x00000001U)

#define CSL_EPCFG_LNK_CAS_EXT_SYN_MASK                          (0x00000080U)
#define CSL_EPCFG_LNK_CAS_EXT_SYN_SHIFT                         (7U)
#define CSL_EPCFG_LNK_CAS_EXT_SYN_RESETVAL                      (0x00000000U)
#define CSL_EPCFG_LNK_CAS_EXT_SYN_MAX                           (0x00000001U)

#define CSL_EPCFG_LNK_CAS_EN_CPM_MASK                           (0x00000100U)
#define CSL_EPCFG_LNK_CAS_EN_CPM_SHIFT                          (8U)
#define CSL_EPCFG_LNK_CAS_EN_CPM_RESETVAL                       (0x00000000U)
#define CSL_EPCFG_LNK_CAS_EN_CPM_MAX                            (0x00000001U)

#define CSL_EPCFG_LNK_CAS_HAWD_MASK                             (0x00000200U)
#define CSL_EPCFG_LNK_CAS_HAWD_SHIFT                            (9U)
#define CSL_EPCFG_LNK_CAS_HAWD_RESETVAL                         (0x00000000U)
#define CSL_EPCFG_LNK_CAS_HAWD_MAX                              (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LBMIE_MASK                            (0x00000400U)
#define CSL_EPCFG_LNK_CAS_LBMIE_SHIFT                           (10U)
#define CSL_EPCFG_LNK_CAS_LBMIE_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LBMIE_MAX                             (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LABIE_MASK                            (0x00000800U)
#define CSL_EPCFG_LNK_CAS_LABIE_SHIFT                           (11U)
#define CSL_EPCFG_LNK_CAS_LABIE_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LABIE_MAX                             (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LINK_SPEED_MASK                       (0x000F0000U)
#define CSL_EPCFG_LNK_CAS_LINK_SPEED_SHIFT                      (16U)
#define CSL_EPCFG_LNK_CAS_LINK_SPEED_RESETVAL                   (0x00000001U)
#define CSL_EPCFG_LNK_CAS_LINK_SPEED_MAX                        (0x0000000fU)

#define CSL_EPCFG_LNK_CAS_NEG_LW_MASK                           (0x03F00000U)
#define CSL_EPCFG_LNK_CAS_NEG_LW_SHIFT                          (20U)
#define CSL_EPCFG_LNK_CAS_NEG_LW_RESETVAL                       (0x00000001U)
#define CSL_EPCFG_LNK_CAS_NEG_LW_MAX                            (0x0000003fU)

#define CSL_EPCFG_LNK_CAS_UNDEF_MASK                            (0x04000000U)
#define CSL_EPCFG_LNK_CAS_UNDEF_SHIFT                           (26U)
#define CSL_EPCFG_LNK_CAS_UNDEF_RESETVAL                        (0x00000000U)
#define CSL_EPCFG_LNK_CAS_UNDEF_MAX                             (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LINK_TRAIN_MASK                       (0x08000000U)
#define CSL_EPCFG_LNK_CAS_LINK_TRAIN_SHIFT                      (27U)
#define CSL_EPCFG_LNK_CAS_LINK_TRAIN_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LINK_TRAIN_MAX                        (0x00000001U)

#define CSL_EPCFG_LNK_CAS_SLOT_CLK_CONFIG_MASK                  (0x10000000U)
#define CSL_EPCFG_LNK_CAS_SLOT_CLK_CONFIG_SHIFT                 (28U)
#define CSL_EPCFG_LNK_CAS_SLOT_CLK_CONFIG_RESETVAL              (0x00000001U)
#define CSL_EPCFG_LNK_CAS_SLOT_CLK_CONFIG_MAX                   (0x00000001U)

#define CSL_EPCFG_LNK_CAS_DLL_ACT_MASK                          (0x20000000U)
#define CSL_EPCFG_LNK_CAS_DLL_ACT_SHIFT                         (29U)
#define CSL_EPCFG_LNK_CAS_DLL_ACT_RESETVAL                      (0x00000000U)
#define CSL_EPCFG_LNK_CAS_DLL_ACT_MAX                           (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LBW_STATUS_MASK                       (0x40000000U)
#define CSL_EPCFG_LNK_CAS_LBW_STATUS_SHIFT                      (30U)
#define CSL_EPCFG_LNK_CAS_LBW_STATUS_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LBW_STATUS_MAX                        (0x00000001U)

#define CSL_EPCFG_LNK_CAS_LAB_STATUS_MASK                       (0x80000000U)
#define CSL_EPCFG_LNK_CAS_LAB_STATUS_SHIFT                      (31U)
#define CSL_EPCFG_LNK_CAS_LAB_STATUS_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_LNK_CAS_LAB_STATUS_MAX                        (0x00000001U)

#define CSL_EPCFG_LNK_CAS_RESETVAL                              (0x10110000U)

/* DEV_CAP_2 */

#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_RNG_SUPPORTED_MASK      (0x0000000FU)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_RNG_SUPPORTED_SHIFT     (0U)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_RNG_SUPPORTED_RESETVAL  (0x0000000fU)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_RNG_SUPPORTED_MAX       (0x0000000fU)

#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_DIS_SUPPORTED_MASK      (0x00000010U)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_DIS_SUPPORTED_SHIFT     (4U)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_DIS_SUPPORTED_RESETVAL  (0x00000001U)
#define CSL_EPCFG_DEV_CAP_2_CPL_TIMEOUT_DIS_SUPPORTED_MAX       (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_ARI_FWD_SP_MASK                     (0x00000020U)
#define CSL_EPCFG_DEV_CAP_2_ARI_FWD_SP_SHIFT                    (5U)
#define CSL_EPCFG_DEV_CAP_2_ARI_FWD_SP_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_ARI_FWD_SP_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_AOR_SP_MASK                         (0x00000040U)
#define CSL_EPCFG_DEV_CAP_2_AOR_SP_SHIFT                        (6U)
#define CSL_EPCFG_DEV_CAP_2_AOR_SP_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_AOR_SP_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_AOC32_SP_MASK                       (0x00000080U)
#define CSL_EPCFG_DEV_CAP_2_AOC32_SP_SHIFT                      (7U)
#define CSL_EPCFG_DEV_CAP_2_AOC32_SP_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_AOC32_SP_MAX                        (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_AOC64_SP_MASK                       (0x00000100U)
#define CSL_EPCFG_DEV_CAP_2_AOC64_SP_SHIFT                      (8U)
#define CSL_EPCFG_DEV_CAP_2_AOC64_SP_RESETVAL                   (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_AOC64_SP_MAX                        (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_CASC128_SP_MASK                     (0x00000200U)
#define CSL_EPCFG_DEV_CAP_2_CASC128_SP_SHIFT                    (9U)
#define CSL_EPCFG_DEV_CAP_2_CASC128_SP_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_CASC128_SP_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_NOROPR_MASK                         (0x00000400U)
#define CSL_EPCFG_DEV_CAP_2_NOROPR_SHIFT                        (10U)
#define CSL_EPCFG_DEV_CAP_2_NOROPR_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_NOROPR_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAP_2_TPHC_SP_MASK                        (0x00003000U)
#define CSL_EPCFG_DEV_CAP_2_TPHC_SP_SHIFT                       (12U)
#define CSL_EPCFG_DEV_CAP_2_TPHC_SP_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_DEV_CAP_2_TPHC_SP_MAX                         (0x00000003U)

#define CSL_EPCFG_DEV_CAP_2_RESETVAL                            (0x0000001fU)

/* DEV_CAS_2 */

#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_VALUE_MASK              (0x0000000FU)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_VALUE_SHIFT             (0U)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_VALUE_RESETVAL          (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_VALUE_MAX               (0x0000000fU)

#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_DIS_MASK                (0x00000010U)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_DIS_SHIFT               (4U)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_DIS_RESETVAL            (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_CPL_TIMEOUT_DIS_MAX                 (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_ARI_FWD_SP_MASK                     (0x00000020U)
#define CSL_EPCFG_DEV_CAS_2_ARI_FWD_SP_SHIFT                    (5U)
#define CSL_EPCFG_DEV_CAS_2_ARI_FWD_SP_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_ARI_FWD_SP_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_AOP_REQ_EN_MASK                     (0x00000040U)
#define CSL_EPCFG_DEV_CAS_2_AOP_REQ_EN_SHIFT                    (6U)
#define CSL_EPCFG_DEV_CAS_2_AOP_REQ_EN_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_AOP_REQ_EN_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_AOP_EG_BLK_MASK                     (0x00000080U)
#define CSL_EPCFG_DEV_CAS_2_AOP_EG_BLK_SHIFT                    (7U)
#define CSL_EPCFG_DEV_CAS_2_AOP_EG_BLK_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_AOP_EG_BLK_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_IDO_REQ_EN_MASK                     (0x00000100U)
#define CSL_EPCFG_DEV_CAS_2_IDO_REQ_EN_SHIFT                    (8U)
#define CSL_EPCFG_DEV_CAS_2_IDO_REQ_EN_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_IDO_REQ_EN_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_IDO_CPL_EN_MASK                     (0x00000200U)
#define CSL_EPCFG_DEV_CAS_2_IDO_CPL_EN_SHIFT                    (9U)
#define CSL_EPCFG_DEV_CAS_2_IDO_CPL_EN_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_IDO_CPL_EN_MAX                      (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_LTR_EN_MASK                         (0x00000400U)
#define CSL_EPCFG_DEV_CAS_2_LTR_EN_SHIFT                        (10U)
#define CSL_EPCFG_DEV_CAS_2_LTR_EN_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_LTR_EN_MAX                          (0x00000001U)

#define CSL_EPCFG_DEV_CAS_2_OBFF_EN_MASK                        (0x00006000U)
#define CSL_EPCFG_DEV_CAS_2_OBFF_EN_SHIFT                       (13U)
#define CSL_EPCFG_DEV_CAS_2_OBFF_EN_RESETVAL                    (0x00000000U)
#define CSL_EPCFG_DEV_CAS_2_OBFF_EN_MAX                         (0x00000003U)

#define CSL_EPCFG_DEV_CAS_2_RESETVAL                            (0x00000000U)

/* LNK_CAP_2 */

#define CSL_EPCFG_LNK_CAP_2_SP_LS_VEC_MASK                      (0x000000FEU)
#define CSL_EPCFG_LNK_CAP_2_SP_LS_VEC_SHIFT                     (1U)
#define CSL_EPCFG_LNK_CAP_2_SP_LS_VEC_RESETVAL                  (0x00000003U)
#define CSL_EPCFG_LNK_CAP_2_SP_LS_VEC_MAX                       (0x0000007fU)

#define CSL_EPCFG_LNK_CAP_2_CROSSLINK_SP_MASK                   (0x00000100U)
#define CSL_EPCFG_LNK_CAP_2_CROSSLINK_SP_SHIFT                  (8U)
#define CSL_EPCFG_LNK_CAP_2_CROSSLINK_SP_RESETVAL               (0x00000000U)
#define CSL_EPCFG_LNK_CAP_2_CROSSLINK_SP_MAX                    (0x00000001U)

#define CSL_EPCFG_LNK_CAP_2_RESETVAL                            (0x00000006U)

/* LNK_CAS_2 */

#define CSL_EPCFG_LNK_CAS_2_TRGT_LINK_SPEED_MASK                (0x0000000FU)
#define CSL_EPCFG_LNK_CAS_2_TRGT_LINK_SPEED_SHIFT               (0U)
#define CSL_EPCFG_LNK_CAS_2_TRGT_LINK_SPEED_RESETVAL            (0x00000001U)
#define CSL_EPCFG_LNK_CAS_2_TRGT_LINK_SPEED_MAX                 (0x0000000fU)

#define CSL_EPCFG_LNK_CAS_2_ENTR_COMPL_MASK                     (0x00000010U)
#define CSL_EPCFG_LNK_CAS_2_ENTR_COMPL_SHIFT                    (4U)
#define CSL_EPCFG_LNK_CAS_2_ENTR_COMPL_RESETVAL                 (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_ENTR_COMPL_MAX                      (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_HW_AUTO_SP_DIS_MASK                 (0x00000020U)
#define CSL_EPCFG_LNK_CAS_2_HW_AUTO_SP_DIS_SHIFT                (5U)
#define CSL_EPCFG_LNK_CAS_2_HW_AUTO_SP_DIS_RESETVAL             (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_HW_AUTO_SP_DIS_MAX                  (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_SEL_DEEMP_MASK                      (0x00000040U)
#define CSL_EPCFG_LNK_CAS_2_SEL_DEEMP_SHIFT                     (6U)
#define CSL_EPCFG_LNK_CAS_2_SEL_DEEMP_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_SEL_DEEMP_MAX                       (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_TX_MARGIN_MASK                      (0x00000380U)
#define CSL_EPCFG_LNK_CAS_2_TX_MARGIN_SHIFT                     (7U)
#define CSL_EPCFG_LNK_CAS_2_TX_MARGIN_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_TX_MARGIN_MAX                       (0x00000007U)

#define CSL_EPCFG_LNK_CAS_2_ENT_MOD_COMPL_MASK                  (0x00000400U)
#define CSL_EPCFG_LNK_CAS_2_ENT_MOD_COMPL_SHIFT                 (10U)
#define CSL_EPCFG_LNK_CAS_2_ENT_MOD_COMPL_RESETVAL              (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_ENT_MOD_COMPL_MAX                   (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_COMPL_SOS_MASK                      (0x00000800U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_SOS_SHIFT                     (11U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_SOS_RESETVAL                  (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_SOS_MAX                       (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_COMPL_PRST_DEEPH_MASK               (0x0000F000U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_PRST_DEEPH_SHIFT              (12U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_PRST_DEEPH_RESETVAL           (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_COMPL_PRST_DEEPH_MAX                (0x0000000fU)

#define CSL_EPCFG_LNK_CAS_2_DEEMPH_LEVEL_MASK                   (0x00010000U)
#define CSL_EPCFG_LNK_CAS_2_DEEMPH_LEVEL_SHIFT                  (16U)
#define CSL_EPCFG_LNK_CAS_2_DEEMPH_LEVEL_RESETVAL               (0x00000001U)
#define CSL_EPCFG_LNK_CAS_2_DEEMPH_LEVEL_MAX                    (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_EQ_COMPLETE_MASK                    (0x00020000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_COMPLETE_SHIFT                   (17U)
#define CSL_EPCFG_LNK_CAS_2_EQ_COMPLETE_RESETVAL                (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_COMPLETE_MAX                     (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_EQ_PH1_MASK                         (0x00040000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH1_SHIFT                        (18U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH1_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH1_MAX                          (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_EQ_PH2_MASK                         (0x00080000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH2_SHIFT                        (19U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH2_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH2_MAX                          (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_EQ_PH3_MASK                         (0x00100000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH3_SHIFT                        (20U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH3_RESETVAL                     (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_EQ_PH3_MAX                          (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_LINK_EQ_REQ_MASK                    (0x00200000U)
#define CSL_EPCFG_LNK_CAS_2_LINK_EQ_REQ_SHIFT                   (21U)
#define CSL_EPCFG_LNK_CAS_2_LINK_EQ_REQ_RESETVAL                (0x00000000U)
#define CSL_EPCFG_LNK_CAS_2_LINK_EQ_REQ_MAX                     (0x00000001U)

#define CSL_EPCFG_LNK_CAS_2_RESETVAL                            (0x00010001U)

#ifdef __cplusplus
}
#endif
#endif
