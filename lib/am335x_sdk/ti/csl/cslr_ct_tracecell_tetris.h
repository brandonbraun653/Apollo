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
#ifndef CSLR_CT_TRACECELL_TETRIS_H_
#define CSLR_CT_TRACECELL_TETRIS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for cxatbfunnel_regs
**************************************************************************/
typedef struct {
    volatile Uint32 CTRL_REG;
    volatile Uint32 PRIORITY_CTRL_REG;
    volatile Uint8  RSVD0[3812];
    volatile Uint32 ITATBDATA0;
    volatile Uint32 ITATBCTR2;
    volatile Uint32 CXATBFUNNEL_REGS_ITATBCTR1;
    volatile Uint32 CXATBFUNNEL_REGS_ITATBCTR0;
    volatile Uint8  RSVD1[4];
    volatile Uint32 CXATBFUNNEL_REGS_ITCTRL;
    volatile Uint8  RSVD2[156];
    volatile Uint32 CXATBFUNNEL_REGS_CLAIMSET;
    volatile Uint32 CXATBFUNNEL_REGS_CLAIMCLR;
    volatile Uint8  RSVD3[8];
    volatile Uint32 LOCKACCESS;
    volatile Uint32 LOCKSTATUS;
    volatile Uint32 CXATBFUNNEL_REGS_AUTHSTATUS;
    volatile Uint8  RSVD4[12];
    volatile Uint32 CXATBFUNNEL_REGS_DEVID;
    volatile Uint32 CXATBFUNNEL_REGS_DEVTYPE;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID4;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID5;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID6;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID7;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID0;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID1;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID2;
    volatile Uint32 CXATBFUNNEL_REGS_PERIPHID3;
    volatile Uint32 CXATBFUNNEL_REGS_COMPID0;
    volatile Uint32 CXATBFUNNEL_REGS_COMPID1;
    volatile Uint32 CXATBFUNNEL_REGS_COMPID2;
    volatile Uint32 CXATBFUNNEL_REGS_COMPID3;
} CSL_Ct_tracecell_tetrisCxatbfunnel_regsRegs;


/**************************************************************************
* Register Overlay Structure for cscti_regs
**************************************************************************/
typedef struct {
    volatile Uint32 CTICONTROL;
    volatile Uint8  RSVD0[12];
    volatile Uint32 CTIINTACK;
    volatile Uint32 CTIAPPSET;
    volatile Uint32 CTIAPPCLEAR;
    volatile Uint32 CTIAPPPULSE;
    volatile Uint32 CTIINEN0;
    volatile Uint32 CTIINEN1;
    volatile Uint32 CTIINEN2;
    volatile Uint32 CTIINEN3;
    volatile Uint32 CTIINEN4;
    volatile Uint32 CTIINEN5;
    volatile Uint32 CTIINEN6;
    volatile Uint32 CTIINEN7;
    volatile Uint8  RSVD1[96];
    volatile Uint32 CTIOUTEN0;
    volatile Uint32 CTIOUTEN1;
    volatile Uint32 CTIOUTEN2;
    volatile Uint32 CTIOUTEN3;
    volatile Uint32 CTIOUTEN4;
    volatile Uint32 CTIOUTEN5;
    volatile Uint32 CTIOUTEN6;
    volatile Uint32 CTIOUTEN7;
    volatile Uint8  RSVD2[112];
    volatile Uint32 CTITRIGINSTATUS;
    volatile Uint32 CTITRIGOUTSTATUS;
    volatile Uint32 CTICHINSTATUS;
    volatile Uint32 CTICHOUTSTATUS;
    volatile Uint32 CTIGATE;
    volatile Uint32 ASICCTL;
    volatile Uint8  RSVD3[3476];
    volatile Uint32 ITCHINACK;
    volatile Uint32 ITTRIGINACK;
    volatile Uint32 ITCHOUT;
    volatile Uint32 ITTRIGOUT;
    volatile Uint32 ITCHOUTACK;
    volatile Uint32 ITTRIGOUTACK;
    volatile Uint32 ITCHIN;
    volatile Uint32 ITTRIGIN;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CSCTI_REGS_ITCTRL;
    volatile Uint8  RSVD5[156];
    volatile Uint32 CSCTI_REGS_CLAIMSET;
    volatile Uint32 CSCTI_REGS_CLAIMCLR;
    volatile Uint8  RSVD6[8];
    volatile Uint32 CSCTI_REGS_LAR;
    volatile Uint32 CSCTI_REGS_LSR;
    volatile Uint32 CSCTI_REGS_AUTHSTATUS;
    volatile Uint8  RSVD7[12];
    volatile Uint32 CSCTI_REGS_DEVID;
    volatile Uint32 CSCTI_REGS_DEVTYPE;
    volatile Uint32 CSCTI_REGS_PERIPHID4;
    volatile Uint32 CSCTI_REGS_PERIPHID5;
    volatile Uint32 CSCTI_REGS_PERIPHID6;
    volatile Uint32 CSCTI_REGS_PERIPHID7;
    volatile Uint32 CSCTI_REGS_PERIPHID0;
    volatile Uint32 CSCTI_REGS_PERIPHID1;
    volatile Uint32 CSCTI_REGS_PERIPHID2;
    volatile Uint32 CSCTI_REGS_PERIPHID3;
    volatile Uint32 CSCTI_REGS_COMPID0;
    volatile Uint32 CSCTI_REGS_COMPID1;
    volatile Uint32 CSCTI_REGS_COMPID2;
    volatile Uint32 CSCTI_REGS_COMPID3;
} CSL_Ct_tracecell_tetrisCscti_regsRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 IDFILTER0;
    volatile Uint32 IDFILTER1;
    volatile Uint8  RSVD8[3824];
    volatile Uint32 CXATBREPLICATOR_REGISTERSITATBCTR1;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_ITATBCTR0;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_ITCTRL;
    volatile Uint8  RSVD9[156];
    volatile Uint32 CXATBREPLICATOR_REGISTERS_CLAIMSET;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_CLAIMCLR;
    volatile Uint8  RSVD10[8];
    volatile Uint32 CXATBREPLICATOR_REGISTERS_LAR;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_LSR;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_AUTHSTATUS;
    volatile Uint8  RSVD11[12];
    volatile Uint32 CXATBREPLICATOR_REGISTERS_DEVID;
    volatile Uint32 CXATBREPLICATOR_REGISTERS_DEVTYPE;
    volatile Uint32 PIDR4;
    volatile Uint32 PIDR5;
    volatile Uint32 PIDR6;
    volatile Uint32 PIDR7;
    volatile Uint32 PIDR0;
    volatile Uint32 PIDR1;
    volatile Uint32 PIDR2;
    volatile Uint32 PIDR3;
    volatile Uint32 CIDR0;
    volatile Uint32 CIDR1;
    volatile Uint32 CIDR2;
    volatile Uint32 CIDR3;
    CSL_Ct_tracecell_tetrisCxatbfunnel_regsRegs	CXATBFUNNEL_REGS;
    CSL_Ct_tracecell_tetrisCscti_regsRegs	CSCTI_REGS;
} CSL_Ct_tracecell_tetrisRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Allows the setting of ID filter for Master 0. */
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0                       (0x0U)

/* Allows the setting of ID filter for Master 1. */
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1                       (0x4U)

/* Controls the value of the ATVALIDM0, ATVALIDM1 and ATREADYS outputs in
 * integration mode. */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0  (0xEFCU)

/* Returns the value of the ATREADYM0, ATREADYM1 and ATVALIDS inputs in
 * integration mode. */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1  (0xEF8U)

/* CXATBREPLICATOR_REGISTERS_ITCTRL */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL  (0xF00U)

/* CXATBREPLICATOR_REGISTERS_CLAIMSET */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET  (0xFA0U)

/* CXATBREPLICATOR_REGISTERS_CLAIMCLR */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR  (0xFA4U)

/* CXATBREPLICATOR_REGISTERS_LAR */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR   (0xFB0U)

/* CXATBREPLICATOR_REGISTERS_LSR */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR   (0xFB4U)

/* Reports the required security level and current status of those enables.
 * Where functionality changes on a given security level then this change in
 * status must be reported in this register */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS  (0xFB8U)

/* CXATBREPLICATOR_REGISTERS_DEVID */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID  (0xFC8U)

/* CXATBREPLICATOR_REGISTERS_DEVTYPE */
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE  (0xFCCU)

/* PIDR0 */
#define CSL_CT_TRACECELL_TETRIS_PIDR0                           (0xFE0U)

/* PIDR1 */
#define CSL_CT_TRACECELL_TETRIS_PIDR1                           (0xFE4U)

/* PIDR2 */
#define CSL_CT_TRACECELL_TETRIS_PIDR2                           (0xFE8U)

/* PIDR3 */
#define CSL_CT_TRACECELL_TETRIS_PIDR3                           (0xFECU)

/* PIDR4 */
#define CSL_CT_TRACECELL_TETRIS_PIDR4                           (0xFD0U)

/* PIDR5 */
#define CSL_CT_TRACECELL_TETRIS_PIDR5                           (0xFD4U)

/* PIDR6 */
#define CSL_CT_TRACECELL_TETRIS_PIDR6                           (0xFD8U)

/* PIDR7 */
#define CSL_CT_TRACECELL_TETRIS_PIDR7                           (0xFDCU)

/* CIDR0 */
#define CSL_CT_TRACECELL_TETRIS_CIDR0                           (0xFF0U)

/* CIDR1 */
#define CSL_CT_TRACECELL_TETRIS_CIDR1                           (0xFF4U)

/* CIDR2 */
#define CSL_CT_TRACECELL_TETRIS_CIDR2                           (0xFF8U)

/* CIDR3 */
#define CSL_CT_TRACECELL_TETRIS_CIDR3                           (0xFFCU)

/* The Funnel Control Register enables the slave ports and defines the hold
 * time of the slave ports. Hold time refers to the number of transactions
 * that are output on the funnel master port from the same slave while that
 * slave port atvalidsx is HIGH. Hold time does not refer to clock cycles in
 * this context */
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG                        (0x1000U)

/* The Priority Control Register defines the order in which inputs are
 * selected. Each 3-bit field represents a priority for each particular slave
 * interface. Location 0 has the priority value for the first slave port.
 * Location 1 is the priority value for the second slave port, Location 2 is
 * the third, down to location 7, which has the priority value of the eighth
 * slave port. Values represent the priority value for each port number. If
 * you want to give highest priority to a particular slave port, the
 * corresponding port must be programmed with the lowest value. Typically this
 * is likely to be a port that has more important data or that has a small
 * FIFO and is therefore likely to overflow. If you want to give lowest
 * priority to a particular slave port, the corresponding slave port must be
 * programmed with the highest value. Typically this is likely to be a device
 * that has a large FIFO that is less likely to overflow or a source that has
 * information that is of lower importance. */
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG               (0x1004U)

/* The Integration Test ATB Data 0 Register performs different functions
 * depending on whether the access is a read or a write: A write outputs data
 * on byte boundaries of ATDATAM. A read returns the data from ATDATASn, where
 * n is defined by the status of the Funnel Control register at 0x000. The
 * read data is only valid when ATVALIDSn is HIGH. */
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0                      (0x1EECU)

/* The Integration Test ATB Control 2 Register performs different functions
 * depending on whether the access is a read or a write: * A write outputs
 * data on atreadysn, where n is defined by the status of the ATB Funnel
 * Control Register at 0x000 * A read returns the data from atreadym. */
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2                       (0x1EF0U)

/* The Integration Test ATB Control 1 Register performs different functions
 * depending on whether the access is a read or a write: * a write sets the
 * value of the atidm. * a read returns the value of the atidmn signals, where
 * n is defined by the status of the Control register at 0x000. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1      (0x1EF4U)

/* The Integration Test ATB Control 0 Register performs different functions
 * depending on whether the access is a read or a write: * a write sets the
 * value of the atvalidm. * a read returns the value of the atvalidsn signals,
 * where n is defined by the status of the Control register at 0x000. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0      (0x1EF8U)

/* This register is used to enable topology detection. For more information
 * see the CoreSight Architecture Specification. This register enables the
 * component to switch from a functional mode, the default behavior, to
 * integration mode where the inputs and outputs of the component can be
 * directly controlled for the purpose of integration testing and topology
 * solving Note When a device has been in integration mode, it might not
 * function with the original behavior. After performing integration or
 * topology detection, you must reset the system to ensure correct behavior of
 * CoreSight and other connected system components that are affected by the
 * integration or topology detection. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL         (0x1F00U)

/* This is used in conjunction with Claim Tag Clear Register, CLAIMCLR. This
 * register forms one half of the Claim Tag value. This location allows
 * individual bits to be set, write, and returns the number of bits that can
 * be set, read. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET       (0x1FA0U)

/* This register is used in conjunction with Claim Tag Set Register, CLAIMSET.
 * This register forms one half of the Claim Tag value. This location enables
 * individual bits to be cleared, write, and returns the current Claim Tag
 * value, read. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR       (0x1FA4U)

/* This is used to enable write access to device registers. */
#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS                      (0x1FB0U)

/* This indicates the status of the Lock control mechanism. This lock prevents
 * accidental writes by code under debug. This register must always be present
 * although there might not be any lock-access control mechanism. The lock
 * mechanism, where present and locked, must block write accesses to any
 * control register, except the Lock Access Register. For most components this
 * covers all registers except for the Lock Access Register 0xFB0 */
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS                      (0x1FB4U)

/* Reports the required security level and current status of those enables.
 * Where functionality changes on a given security level then this change in
 * status must be reported in this register */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS     (0x1FB8U)

/* This indicates the capabilities of the CoreSight Funnel. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID          (0x1FC8U)

/* It provides a debugger with information about the component when the Part
 * Number field is not recognized. The debugger can then report this
 * information. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE        (0x1FCCU)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer specific part number. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0      (0x1FE0U)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer specific part number and part of the designer identity. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1      (0x1FE4U)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer identity and the product revision. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2      (0x1FE8U)

/* Part of the set of Peripheral Identification registers. Contains the RevAnd
 * and Customer Modified fields. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3      (0x1FECU)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer identity and the memory footprint indicator. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4      (0x1FD0U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID5      (0x1FD4U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID6      (0x1FD8U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID7      (0x1FDCU)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0        (0x1FF0U)

/* A component identification register, that indicates that the identification
 * registers are present. This register also indicates the component class. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1        (0x1FF4U)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2        (0x1FF8U)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3        (0x1FFCU)

/* CTICONTROL */
#define CSL_CT_TRACECELL_TETRIS_CTICONTROL                      (0x2000U)

/* CTIINTACK */
#define CSL_CT_TRACECELL_TETRIS_CTIINTACK                       (0x2010U)

/* CTIAPPSET */
#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET                       (0x2014U)

/* CTIAPPCLEAR */
#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR                     (0x2018U)

/* CTIAPPPULSE */
#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE                     (0x201CU)

/* CTIINEN0 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN0                        (0x2020U)

/* CTIINEN1 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN1                        (0x2024U)

/* CTIINEN2 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN2                        (0x2028U)

/* CTIINEN3 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN3                        (0x202CU)

/* CTIINEN4 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN4                        (0x2030U)

/* CTIINEN5 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN5                        (0x2034U)

/* CTIINEN6 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN6                        (0x2038U)

/* CTIINEN7 */
#define CSL_CT_TRACECELL_TETRIS_CTIINEN7                        (0x203CU)

/* CTIOUTEN0 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0                       (0x20A0U)

/* CTIOUTEN1 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1                       (0x20A4U)

/* CTIOUTEN2 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2                       (0x20A8U)

/* CTIOUTEN3 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3                       (0x20ACU)

/* CTIOUTEN4 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4                       (0x20B0U)

/* CTIOUTEN5 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5                       (0x20B4U)

/* CTIOUTEN6 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6                       (0x20B8U)

/* CTIOUTEN7 */
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7                       (0x20BCU)

/* CTITRIGINSTATUS */
#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS                 (0x2130U)

/* CTITRIGOUTSTATUS */
#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS                (0x2134U)

/* CTICHINSTATUS */
#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS                   (0x2138U)

/* CTICHOUTSTATUS */
#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS                  (0x213CU)

/* CTIGATE */
#define CSL_CT_TRACECELL_TETRIS_CTIGATE                         (0x2140U)

/* ASICCTL */
#define CSL_CT_TRACECELL_TETRIS_ASICCTL                         (0x2144U)

/* ITCHINACK */
#define CSL_CT_TRACECELL_TETRIS_ITCHINACK                       (0x2EDCU)

/* ITTRIGINACK */
#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK                     (0x2EE0U)

/* ITCHOUT */
#define CSL_CT_TRACECELL_TETRIS_ITCHOUT                         (0x2EE4U)

/* ITTRIGOUT */
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT                       (0x2EE8U)

/* ITCHOUTACK */
#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK                      (0x2EECU)

/* ITTRIGOUTACK */
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK                    (0x2EF0U)

/* ITCHIN */
#define CSL_CT_TRACECELL_TETRIS_ITCHIN                          (0x2EF4U)

/* ITTRIGIN */
#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN                        (0x2EF8U)

/* CSCTI_REGS_ITCTRL */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL               (0x2F00U)

/* This is used in conjunction with Claim Tag Clear Register, CLAIMCLR. This
 * register forms one half of the Claim Tag value. This location allows
 * individual bits to be set, write, and returns the number of bits that can
 * be set, read. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET             (0x2FA0U)

/* This register is used in conjunction with Claim Tag Set Register, CLAIMSET.
 * This register forms one half of the Claim Tag value. This location enables
 * individual bits to be cleared, write, and returns the current Claim Tag
 * value, read. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR             (0x2FA4U)

/* CSCTI_REGS_LAR */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR                  (0x2FB0U)

/* CSCTI_REGS_LSR */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR                  (0x2FB4U)

/* Reports what functionality is currently permitted by the authentication
 * interface. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS           (0x2FB8U)

/* This register indicates the capabilities of the CTI. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID                (0x2FC8U)

/* It provides a debugger with information about the component when the Part
 * Number field is not recognized. The debugger can then report this
 * information. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE              (0x2FCCU)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer specific part number. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0            (0x2FE0U)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer specific part number and part of the designer identity. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1            (0x2FE4U)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer identity and the product revision. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2            (0x2FE8U)

/* Part of the set of Peripheral Identification registers. Contains the RevAnd
 * and Customer Modified fields. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3            (0x2FECU)

/* Part of the set of Peripheral Identification registers. Contains part of
 * the designer identity and the memory footprint indicator. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4            (0x2FD0U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID5            (0x2FD4U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID6            (0x2FD8U)

/* Reserved */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID7            (0x2FDCU)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0              (0x2FF0U)

/* A component identification register, that indicates that the identification
 * registers are present. This register also indicates the component class. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1              (0x2FF4U)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2              (0x2FF8U)

/* A component identification register, that indicates that the identification
 * registers are present. */
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3              (0x2FFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDFILTER0 */

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_0_F_MASK          (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_0_F_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_0_F_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_0_F_HIGH          (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_0_F_LOW           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_10_1F_MASK        (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_10_1F_SHIFT       (1U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_10_1F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_10_1F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_10_1F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_20_2F_MASK        (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_20_2F_SHIFT       (2U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_20_2F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_20_2F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_20_2F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_30_3F_MASK        (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_30_3F_SHIFT       (3U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_30_3F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_30_3F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_30_3F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_40_4F_MASK        (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_40_4F_SHIFT       (4U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_40_4F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_40_4F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_40_4F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_50_5F_MASK        (0x00000020U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_50_5F_SHIFT       (5U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_50_5F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_50_5F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_50_5F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_60_6F_MASK        (0x00000040U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_60_6F_SHIFT       (6U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_60_6F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_60_6F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_60_6F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_70_7F_MASK        (0x00000080U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_70_7F_SHIFT       (7U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_70_7F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_70_7F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_ID0_70_7F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER0_RESETVAL              (0x00000000U)

/* IDFILTER1 */

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_0_F_MASK          (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_0_F_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_0_F_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_0_F_HIGH          (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_0_F_LOW           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_10_1F_MASK        (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_10_1F_SHIFT       (1U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_10_1F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_10_1F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_10_1F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_20_2F_MASK        (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_20_2F_SHIFT       (2U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_20_2F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_20_2F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_20_2F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_30_3F_MASK        (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_30_3F_SHIFT       (3U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_30_3F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_30_3F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_30_3F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_40_4F_MASK        (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_40_4F_SHIFT       (4U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_40_4F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_40_4F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_40_4F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_50_5F_MASK        (0x00000020U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_50_5F_SHIFT       (5U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_50_5F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_50_5F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_50_5F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_60_6F_MASK        (0x00000040U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_60_6F_SHIFT       (6U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_60_6F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_60_6F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_60_6F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_70_7F_MASK        (0x00000080U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_70_7F_SHIFT       (7U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_70_7F_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_70_7F_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_ID1_70_7F_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_IDFILTER1_RESETVAL              (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_ITATBCTR0 */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM0_W_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM0_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM0_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM0_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM0_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM1_W_MASK  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM1_W_SHIFT  (2U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM1_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM1_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATVALIDM1_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATREADYS_W_MASK  (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATREADYS_W_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATREADYS_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATREADYS_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_ATREADYS_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITATBCTR0_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERSITATBCTR1 */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM0_R_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM0_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM0_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM0_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM0_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM1_R_MASK  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM1_R_SHIFT  (1U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM1_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM1_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATREADYM1_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATVALIDS_R_MASK  (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATVALIDS_R_SHIFT  (3U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATVALIDS_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATVALIDS_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_ATVALIDS_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERSITATBCTR1_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_ITCTRL */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_INTEGRATION_MODE_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_INTEGRATION_MODE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_INTEGRATION_MODE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_INTEGRATION_MODE_INTEGRATIONMODE  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_INTEGRATION_MODE_FUNCTIONALMODE  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_ITCTRL_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_CLAIMSET */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_R_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_W_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_CLAIMSET_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMSET_RESETVAL  (0x0000000fU)

/* CXATBREPLICATOR_REGISTERS_CLAIMCLR */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_CLAIMCLR_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_CLAIMCLR_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_LAR */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR_ACCESS_W_MASK  (0xFFFFFFFFU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR_ACCESS_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR_ACCESS_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR_ACCESS_W_MAX  (0xffffffffU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LAR_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_LSR */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKEXIST_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKEXIST_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKEXIST_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKEXIST_LOCKNOTPRESENT  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKEXIST_LOCKPRESENT  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKGRANT_MASK  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKGRANT_SHIFT  (1U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKGRANT_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKGRANT_ACCESSPERMITTED  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKGRANT_DEVICELOCKED  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKTYPE_MASK  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKTYPE_SHIFT  (2U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKTYPE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_LOCKTYPE_REG32BIT  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_LSR_RESETVAL  (0x00000003U)

/* CXATBREPLICATOR_REGISTERS_AUTHSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSID_MASK  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSID_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSNID_MASK  (0x0000000CU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSNID_SHIFT  (2U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSNID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_NSNID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SID_MASK  (0x00000030U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SID_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SNID_MASK  (0x000000C0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SNID_SHIFT  (6U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SNID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_SNID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_AUTHSTATUS_RESETVAL  (0x00000000U)

/* CXATBREPLICATOR_REGISTERS_DEVID */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID_PORTNUM_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID_PORTNUM_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID_PORTNUM_RESETVAL  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID_PORTNUM_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVID_RESETVAL  (0x00000002U)

/* CXATBREPLICATOR_REGISTERS_DEVTYPE */

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_MAJOR_TYPE_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_MAJOR_TYPE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_MAJOR_TYPE_RESETVAL  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_MAJOR_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_SUB_TYPE_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_SUB_TYPE_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_SUB_TYPE_RESETVAL  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_SUB_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBREPLICATOR_REGISTERS_DEVTYPE_RESETVAL  (0x00000022U)

/* PIDR0 */

#define CSL_CT_TRACECELL_TETRIS_PIDR0_PART_NUMBER_BITS7TO0_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_PIDR0_PART_NUMBER_BITS7TO0_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR0_PART_NUMBER_BITS7TO0_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_PIDR0_PART_NUMBER_BITS7TO0_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_PIDR0_RESETVAL                  (0x00000009U)

/* PIDR1 */

#define CSL_CT_TRACECELL_TETRIS_PIDR1_PART_NUMBER_BITS11TO8_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_PART_NUMBER_BITS11TO8_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_PART_NUMBER_BITS11TO8_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_PART_NUMBER_BITS11TO8_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR1_JEP106_BITS3TO0_MASK      (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_JEP106_BITS3TO0_SHIFT     (4U)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_JEP106_BITS3TO0_RESETVAL  (0x0000000bU)
#define CSL_CT_TRACECELL_TETRIS_PIDR1_JEP106_BITS3TO0_MAX       (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR1_RESETVAL                  (0x000000b9U)

/* PIDR2 */

#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEP106_BITS6TO4_MASK      (0x00000007U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEP106_BITS6TO4_SHIFT     (0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEP106_BITS6TO4_RESETVAL  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEP106_BITS6TO4_ARMJEP106IDENTITYCODE64  (0x00000003U)

#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEDEC_MASK                (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEDEC_SHIFT               (3U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEDEC_RESETVAL            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_JEDEC_JEDECIDENTITY       (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_PIDR2_REVISION_MASK             (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_REVISION_SHIFT            (4U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_REVISION_RESETVAL         (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PIDR2_REVISION_MAX              (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR2_RESETVAL                  (0x0000001bU)

/* PIDR3 */

#define CSL_CT_TRACECELL_TETRIS_PIDR3_CUSTOMER_MODIFIED_MASK    (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_CUSTOMER_MODIFIED_SHIFT   (0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_CUSTOMER_MODIFIED_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_CUSTOMER_MODIFIED_MAX     (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR3_REVAND_MASK               (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_REVAND_SHIFT              (4U)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_REVAND_RESETVAL           (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PIDR3_REVAND_MAX                (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR3_RESETVAL                  (0x00000000U)

/* PIDR4 */

#define CSL_CT_TRACECELL_TETRIS_PIDR4_JEP106_CONT_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_JEP106_CONT_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_JEP106_CONT_RESETVAL      (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_JEP106_CONT_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR4_FOURKB_COUNT_MASK         (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_FOURKB_COUNT_SHIFT        (4U)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_FOURKB_COUNT_RESETVAL     (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PIDR4_FOURKB_COUNT_MAX          (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_PIDR4_RESETVAL                  (0x00000004U)

/* PIDR5 */

#define CSL_CT_TRACECELL_TETRIS_PIDR5_RESETVAL                  (0x00000000U)

/* PIDR6 */

#define CSL_CT_TRACECELL_TETRIS_PIDR6_RESETVAL                  (0x00000000U)

/* PIDR7 */

#define CSL_CT_TRACECELL_TETRIS_PIDR7_RESETVAL                  (0x00000000U)

/* CIDR0 */

#define CSL_CT_TRACECELL_TETRIS_CIDR0_PREAMBLE_MASK             (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CIDR0_PREAMBLE_SHIFT            (0U)
#define CSL_CT_TRACECELL_TETRIS_CIDR0_PREAMBLE_RESETVAL         (0x0000000dU)
#define CSL_CT_TRACECELL_TETRIS_CIDR0_PREAMBLE_MAX              (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CIDR0_RESETVAL                  (0x0000000dU)

/* CIDR1 */

#define CSL_CT_TRACECELL_TETRIS_CIDR1_PREAMBLE_MASK             (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_PREAMBLE_SHIFT            (0U)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_PREAMBLE_RESETVAL         (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_PREAMBLE_MAX              (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CIDR1_CLASS_MASK                (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_CLASS_SHIFT               (4U)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_CLASS_RESETVAL            (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_CIDR1_CLASS_MAX                 (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CIDR1_RESETVAL                  (0x00000090U)

/* CIDR2 */

#define CSL_CT_TRACECELL_TETRIS_CIDR2_PREAMBLE_MASK             (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CIDR2_PREAMBLE_SHIFT            (0U)
#define CSL_CT_TRACECELL_TETRIS_CIDR2_PREAMBLE_RESETVAL         (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_CIDR2_PREAMBLE_MAX              (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CIDR2_RESETVAL                  (0x00000005U)

/* CIDR3 */

#define CSL_CT_TRACECELL_TETRIS_CIDR3_PREAMBLE_MASK             (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CIDR3_PREAMBLE_SHIFT            (0U)
#define CSL_CT_TRACECELL_TETRIS_CIDR3_PREAMBLE_RESETVAL         (0x000000b1U)
#define CSL_CT_TRACECELL_TETRIS_CIDR3_PREAMBLE_MAX              (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CIDR3_RESETVAL                  (0x000000b1U)

/* CTRL_REG */

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_HT_MASK                (0x00000F00U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_HT_SHIFT               (8U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_HT_RESETVAL            (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_HT_MAX                 (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS4_MASK              (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS4_SHIFT             (4U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS4_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS4_ENABLE            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS4_DISABLE           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS3_MASK              (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS3_SHIFT             (3U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS3_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS3_ENABLE            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS3_DISABLE           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS2_MASK              (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS2_SHIFT             (2U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS2_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS2_ENABLE            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS2_DISABLE           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS1_MASK              (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS1_SHIFT             (1U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS1_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS1_ENABLE            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS1_DISABLE           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS0_MASK              (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS0_SHIFT             (0U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS0_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS0_ENABLE            (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_ENS0_DISABLE           (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTRL_REG_RESETVAL               (0x00000300U)

/* PRIORITY_CTRL_REG */

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_MASK  (0x00007000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_SHIFT  (12U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL0  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL1  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL2  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL3  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL4  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL5  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL6  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT4_PRORITYLEVEL7  (0x00000007U)

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_MASK  (0x00000E00U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_SHIFT  (9U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL0  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL1  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL2  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL3  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL4  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL5  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL6  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT3_PRORITYLEVEL7  (0x00000007U)

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_MASK  (0x000001C0U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_SHIFT  (6U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL0  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL1  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL2  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL3  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL4  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL5  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL6  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT2_PRORITYLEVEL7  (0x00000007U)

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_MASK  (0x00000038U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_SHIFT  (3U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL0  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL1  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL2  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL3  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL4  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL5  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL6  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT1_PRORITYLEVEL7  (0x00000007U)

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_MASK  (0x00000007U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL0  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL1  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL2  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL3  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL4  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL5  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL6  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_PRIPORT0_PRORITYLEVEL7  (0x00000007U)

#define CSL_CT_TRACECELL_TETRIS_PRIORITY_CTRL_REG_RESETVAL      (0x00000000U)

/* ITATBDATA0 */

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_W_MASK       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_W_SHIFT      (0U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_W_RESETVAL   (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_W_HIGH       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_W_LOW        (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_W_MASK       (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_W_SHIFT      (1U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_W_RESETVAL   (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_W_HIGH       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_W_LOW        (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_W_MASK      (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_W_SHIFT     (2U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATAM23_W_MASK     (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATAM23_W_SHIFT    (3U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATAM23_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATAM23_W_HIGH     (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATAM23_W_LOW      (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_W_MASK      (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_W_SHIFT     (4U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_W_MASK      (0x00000020U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_W_SHIFT     (5U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_W_MASK      (0x00000040U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_W_SHIFT     (6U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_W_MASK      (0x00000080U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_W_SHIFT     (7U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_W_MASK      (0x00000100U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_W_SHIFT     (8U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_W_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_W_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_R_MASK       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_R_SHIFT      (0U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_R_RESETVAL   (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_R_HIGH       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA0_R_LOW        (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_R_MASK       (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_R_SHIFT      (1U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_R_RESETVAL   (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_R_HIGH       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA7_R_LOW        (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_R_MASK      (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_R_SHIFT     (2U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA15_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA23_R_MASK      (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA23_R_SHIFT     (3U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA23_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA23_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA23_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_R_MASK      (0x00000010U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_R_SHIFT     (4U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA31_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_R_MASK      (0x00000020U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_R_SHIFT     (5U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA39_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_R_MASK      (0x00000040U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_R_SHIFT     (6U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA47_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_R_MASK      (0x00000080U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_R_SHIFT     (7U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA55_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_R_MASK      (0x00000100U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_R_SHIFT     (8U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_R_HIGH      (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_ATDATA63_R_LOW       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBDATA0_RESETVAL             (0x00000000U)

/* ITATBCTR2 */

#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_W_MASK        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_W_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_W_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_W_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_W_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_R_MASK        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_R_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_R_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_R_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_ATREADY_R_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_W_MASK        (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_W_SHIFT       (1U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_W_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_W_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_W_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_R_MASK        (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_R_SHIFT       (1U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_R_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_R_HIGH        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_AFVALID_R_LOW         (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_ITATBCTR2_RESETVAL              (0x00000000U)

/* CXATBFUNNEL_REGS_ITATBCTR1 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_W_MASK  (0x0000007FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_W_MAX  (0x0000007fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_R_MASK  (0x0000007FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_ATID_R_MAX  (0x0000007fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR1_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_ITATBCTR0 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_R_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_W_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATVALID_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_R_MASK  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_R_SHIFT  (1U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_W_MASK  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_W_SHIFT  (1U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_AFREADY_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_R_MASK  (0x00000700U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_R_SHIFT  (8U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_R_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_R_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_W_MASK  (0x00000700U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_W_SHIFT  (8U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_W_HIGH  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_ATBYTES_W_LOW  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITATBCTR0_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_ITCTRL */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_INTEGRATION_MODE_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_INTEGRATION_MODE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_INTEGRATION_MODE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_INTEGRATION_MODE_INTEGRATIONMODE  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_INTEGRATION_MODE_FUNCTIONALMODE  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_ITCTRL_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_CLAIMSET */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_R_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_W_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_CLAIMSET_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMSET_RESETVAL  (0x0000000fU)

/* CXATBFUNNEL_REGS_CLAIMCLR */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_CLAIMCLR_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_CLAIMCLR_RESETVAL  (0x00000000U)

/* LOCKACCESS */

#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS_ACCESS_W_MASK        (0xFFFFFFFFU)
#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS_ACCESS_W_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS_ACCESS_W_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS_ACCESS_W_MAX         (0xffffffffU)

#define CSL_CT_TRACECELL_TETRIS_LOCKACCESS_RESETVAL             (0x00000000U)

/* LOCKSTATUS */

#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKEXIST_MASK       (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKEXIST_SHIFT      (0U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKEXIST_RESETVAL   (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKEXIST_LOCKNOTPRESENT  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKEXIST_LOCKPRESENT  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKGRANT_MASK       (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKGRANT_SHIFT      (1U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKGRANT_RESETVAL   (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKGRANT_ACCESSPERMITTED  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKGRANT_DEVICELOCKED  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKTYPE_MASK        (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKTYPE_SHIFT       (2U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKTYPE_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_LOCKTYPE_LAR32BIT    (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_LOCKSTATUS_RESETVAL             (0x00000003U)

/* CXATBFUNNEL_REGS_AUTHSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSID_MASK  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSID_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSNID_MASK  (0x0000000CU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSNID_SHIFT  (2U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSNID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_NSNID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SID_MASK  (0x00000030U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SID_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SNID_MASK  (0x000000C0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SNID_SHIFT  (6U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SNID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_SNID_L2B00  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_AUTHSTATUS_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_DEVID */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_PORTCOUNT_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_PORTCOUNT_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_PORTCOUNT_RESETVAL  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_PORTCOUNT_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_SCHEME_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_SCHEME_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_SCHEME_RESETVAL  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_SCHEME_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVID_RESETVAL  (0x00000035U)

/* CXATBFUNNEL_REGS_DEVTYPE */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_SUB_TYPE_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_SUB_TYPE_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_SUB_TYPE_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_SUB_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_MAJOR_TYPE_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_MAJOR_TYPE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_MAJOR_TYPE_RESETVAL  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_MAJOR_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_DEVTYPE_RESETVAL  (0x00000012U)

/* CXATBFUNNEL_REGS_PERIPHID0 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0_PART_NUMBER_BITS7TO0_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0_PART_NUMBER_BITS7TO0_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0_PART_NUMBER_BITS7TO0_RESETVAL  (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0_PART_NUMBER_BITS7TO0_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID0_RESETVAL  (0x00000008U)

/* CXATBFUNNEL_REGS_PERIPHID1 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_JEP106_BITS3TO0_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_JEP106_BITS3TO0_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_JEP106_BITS3TO0_RESETVAL  (0x0000000bU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_JEP106_BITS3TO0_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_PART_NUMBER_BITS11TO8_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_PART_NUMBER_BITS11TO8_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_PART_NUMBER_BITS11TO8_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_PART_NUMBER_BITS11TO8_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID1_RESETVAL  (0x000000b9U)

/* CXATBFUNNEL_REGS_PERIPHID2 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_REVISION_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_REVISION_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_REVISION_RESETVAL  (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_REVISION_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEDEC_MASK  (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEDEC_SHIFT  (3U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEDEC_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEDEC_JEDECIDENTITY  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEP106_BITS6TO4_MASK  (0x00000007U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEP106_BITS6TO4_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEP106_BITS6TO4_RESETVAL  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_JEP106_BITS6TO4_ARMJEP106IDENTITYCODE64  (0x00000003U)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID2_RESETVAL  (0x0000002bU)

/* CXATBFUNNEL_REGS_PERIPHID3 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_REVAND_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_REVAND_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_REVAND_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_REVAND_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_CUSTOMER_MODIFIED_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_CUSTOMER_MODIFIED_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_CUSTOMER_MODIFIED_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_CUSTOMER_MODIFIED_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID3_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_PERIPHID4 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_FOURKB_COUNT_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_FOURKB_COUNT_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_FOURKB_COUNT_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_FOURKB_COUNT_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_JEP106_CONT_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_JEP106_CONT_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_JEP106_CONT_RESETVAL  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_JEP106_CONT_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID4_RESETVAL  (0x00000004U)

/* CXATBFUNNEL_REGS_PERIPHID5 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID5_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_PERIPHID6 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID6_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_PERIPHID7 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_PERIPHID7_RESETVAL  (0x00000000U)

/* CXATBFUNNEL_REGS_COMPID0 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0_PREAMBLE_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0_PREAMBLE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0_PREAMBLE_RESETVAL  (0x0000000dU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0_PREAMBLE_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID0_RESETVAL  (0x0000000dU)

/* CXATBFUNNEL_REGS_COMPID1 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_CLASS_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_CLASS_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_CLASS_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_CLASS_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_PREAMBLE_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_PREAMBLE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_PREAMBLE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_PREAMBLE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID1_RESETVAL  (0x00000090U)

/* CXATBFUNNEL_REGS_COMPID2 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2_PREAMBLE_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2_PREAMBLE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2_PREAMBLE_RESETVAL  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2_PREAMBLE_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID2_RESETVAL  (0x00000005U)

/* CXATBFUNNEL_REGS_COMPID3 */

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3_PREAMBLE_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3_PREAMBLE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3_PREAMBLE_RESETVAL  (0x000000b1U)
#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3_PREAMBLE_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CXATBFUNNEL_REGS_COMPID3_RESETVAL  (0x000000b1U)

/* CTICONTROL */

#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_GLBEN_MASK           (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_GLBEN_SHIFT          (0U)
#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_GLBEN_RESETVAL       (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_GLBEN_ENABLED        (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_GLBEN_DISABLED       (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CTICONTROL_RESETVAL             (0x00000000U)

/* CTIINTACK */

#define CSL_CT_TRACECELL_TETRIS_CTIINTACK_INTACK_MASK           (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CTIINTACK_INTACK_SHIFT          (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINTACK_INTACK_RESETVAL       (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINTACK_INTACK_MAX            (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CTIINTACK_RESETVAL              (0x00000000U)

/* CTIAPPSET */

#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET_APPSET_MASK           (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET_APPSET_SHIFT          (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET_APPSET_RESETVAL       (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET_APPSET_MAX            (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CTIAPPSET_RESETVAL              (0x00000000U)

/* CTIAPPCLEAR */

#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR_APPCLEAR_MASK       (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR_APPCLEAR_SHIFT      (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR_APPCLEAR_RESETVAL   (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR_APPCLEAR_MAX        (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIAPPCLEAR_RESETVAL            (0x00000000U)

/* CTIAPPPULSE */

#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE_APPULSE_MASK        (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE_APPULSE_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE_APPULSE_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE_APPULSE_MAX         (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CTIAPPPULSE_RESETVAL            (0x00000000U)

/* CTIINEN0 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN0_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN0_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN0_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN0_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN0_RESETVAL               (0x00000000U)

/* CTIINEN1 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN1_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN1_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN1_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN1_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN1_RESETVAL               (0x00000000U)

/* CTIINEN2 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN2_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN2_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN2_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN2_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN2_RESETVAL               (0x00000000U)

/* CTIINEN3 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN3_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN3_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN3_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN3_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN3_RESETVAL               (0x00000000U)

/* CTIINEN4 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN4_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN4_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN4_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN4_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN4_RESETVAL               (0x00000000U)

/* CTIINEN5 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN5_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN5_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN5_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN5_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN5_RESETVAL               (0x00000000U)

/* CTIINEN6 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN6_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN6_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN6_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN6_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN6_RESETVAL               (0x00000000U)

/* CTIINEN7 */

#define CSL_CT_TRACECELL_TETRIS_CTIINEN7_TRIGINEN_MASK          (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN7_TRIGINEN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN7_TRIGINEN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIINEN7_TRIGINEN_MAX           (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIINEN7_RESETVAL               (0x00000000U)

/* CTIOUTEN0 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN0_RESETVAL              (0x00000000U)

/* CTIOUTEN1 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN1_RESETVAL              (0x00000000U)

/* CTIOUTEN2 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN2_RESETVAL              (0x00000000U)

/* CTIOUTEN3 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN3_RESETVAL              (0x00000000U)

/* CTIOUTEN4 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN4_RESETVAL              (0x00000000U)

/* CTIOUTEN5 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN5_RESETVAL              (0x00000000U)

/* CTIOUTEN6 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN6_RESETVAL              (0x00000000U)

/* CTIOUTEN7 */

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7_TRIGOUTEN_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7_TRIGOUTEN_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7_TRIGOUTEN_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7_TRIGOUTEN_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTIOUTEN7_RESETVAL              (0x00000000U)

/* CTITRIGINSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS_TRIGINSTATUS_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS_TRIGINSTATUS_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS_TRIGINSTATUS_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS_TRIGINSTATUS_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CTITRIGINSTATUS_RESETVAL        (0x00000000U)

/* CTITRIGOUTSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS_TRIGOUTSTATUS_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS_TRIGOUTSTATUS_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS_TRIGOUTSTATUS_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS_TRIGOUTSTATUS_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CTITRIGOUTSTATUS_RESETVAL       (0x00000000U)

/* CTICHINSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS_CTICHINSTATUS_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS_CTICHINSTATUS_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS_CTICHINSTATUS_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS_CTICHINSTATUS_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTICHINSTATUS_RESETVAL          (0x00000000U)

/* CTICHOUTSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS_CTICHOUTSTATUS_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS_CTICHOUTSTATUS_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS_CTICHOUTSTATUS_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS_CTICHOUTSTATUS_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CTICHOUTSTATUS_RESETVAL         (0x00000000U)

/* CTIGATE */

#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN0_MASK         (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN0_SHIFT        (0U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN0_RESETVAL     (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN0_MAX          (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN1_MASK         (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN1_SHIFT        (1U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN1_RESETVAL     (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN1_MAX          (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN2_MASK         (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN2_SHIFT        (2U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN2_RESETVAL     (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN2_MAX          (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN3_MASK         (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN3_SHIFT        (3U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN3_RESETVAL     (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CTIGATE_CTIGATEEN3_MAX          (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CTIGATE_RESETVAL                (0x0000000fU)

/* ASICCTL */

#define CSL_CT_TRACECELL_TETRIS_ASICCTL_ASICCTL_MASK            (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_ASICCTL_ASICCTL_SHIFT           (0U)
#define CSL_CT_TRACECELL_TETRIS_ASICCTL_ASICCTL_RESETVAL        (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ASICCTL_ASICCTL_MAX             (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_ASICCTL_RESETVAL                (0x00000000U)

/* ITCHINACK */

#define CSL_CT_TRACECELL_TETRIS_ITCHINACK_CTCHINACK_MASK        (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_ITCHINACK_CTCHINACK_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_ITCHINACK_CTCHINACK_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITCHINACK_CTCHINACK_MAX         (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_ITCHINACK_RESETVAL              (0x00000000U)

/* ITTRIGINACK */

#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK_CTTRIGINACK_MASK    (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK_CTTRIGINACK_SHIFT   (0U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK_CTTRIGINACK_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK_CTTRIGINACK_MAX     (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_ITTRIGINACK_RESETVAL            (0x00000000U)

/* ITCHOUT */

#define CSL_CT_TRACECELL_TETRIS_ITCHOUT_CTCHOUT_MASK            (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUT_CTCHOUT_SHIFT           (0U)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUT_CTCHOUT_RESETVAL        (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUT_CTCHOUT_MAX             (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_ITCHOUT_RESETVAL                (0x00000000U)

/* ITTRIGOUT */

#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT_CTTRIGOUT_MASK        (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT_CTTRIGOUT_SHIFT       (0U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT_CTTRIGOUT_RESETVAL    (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT_CTTRIGOUT_MAX         (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUT_RESETVAL              (0x00000000U)

/* ITCHOUTACK */

#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK_CTCHOUTACK_MASK      (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK_CTCHOUTACK_SHIFT     (0U)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK_CTCHOUTACK_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK_CTCHOUTACK_MAX       (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_ITCHOUTACK_RESETVAL             (0x00000000U)

/* ITTRIGOUTACK */

#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK_CTTRIGOUTACK_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK_CTTRIGOUTACK_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK_CTTRIGOUTACK_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK_CTTRIGOUTACK_MAX   (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_ITTRIGOUTACK_RESETVAL           (0x00000000U)

/* ITCHIN */

#define CSL_CT_TRACECELL_TETRIS_ITCHIN_CTCHIN_MASK              (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_ITCHIN_CTCHIN_SHIFT             (0U)
#define CSL_CT_TRACECELL_TETRIS_ITCHIN_CTCHIN_RESETVAL          (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITCHIN_CTCHIN_MAX               (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_ITCHIN_RESETVAL                 (0x00000000U)

/* ITTRIGIN */

#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN_CTTRIGIN_MASK          (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN_CTTRIGIN_SHIFT         (0U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN_CTTRIGIN_RESETVAL      (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN_CTTRIGIN_MAX           (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_ITTRIGIN_RESETVAL               (0x00000000U)

/* CSCTI_REGS_ITCTRL */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_INTEGRATION_MODE_MASK  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_INTEGRATION_MODE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_INTEGRATION_MODE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_INTEGRATION_MODE_INTEGRATIONMODE  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_INTEGRATION_MODE_FUNCTIONALMODE  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_ITCTRL_RESETVAL      (0x00000000U)

/* CSCTI_REGS_CLAIMSET */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_R_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_W_RESETVAL  (0x0000000fU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_CLAIMSET_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMSET_RESETVAL    (0x0000000fU)

/* CSCTI_REGS_CLAIMCLR */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_R_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_R_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_R_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_R_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_W_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_W_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_CLAIMCLR_W_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_CLAIMCLR_RESETVAL    (0x00000000U)

/* CSCTI_REGS_LAR */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR_ACCESS_W_MASK    (0xFFFFFFFFU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR_ACCESS_W_SHIFT   (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR_ACCESS_W_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR_ACCESS_W_MAX     (0xffffffffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LAR_RESETVAL         (0x00000000U)

/* CSCTI_REGS_LSR */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKEXIST_MASK   (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKEXIST_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKEXIST_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKEXIST_LOCKNOTPRESENT  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKEXIST_LOCKPRESENT  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKGRANT_MASK   (0x00000002U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKGRANT_SHIFT  (1U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKGRANT_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKGRANT_ACCESSPERMITTED  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKGRANT_DEVICELOCKED  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKTYPE_MASK    (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKTYPE_SHIFT   (2U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKTYPE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_LOCKTYPE_LAR32BIT  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_LSR_RESETVAL         (0x00000003U)

/* CSCTI_REGS_AUTHSTATUS */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSID_MASK  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSID_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSID_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSID_DISABLED  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSID_ENABLED  (0x00000003U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSNID_MASK  (0x0000000CU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSNID_SHIFT  (2U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSNID_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSNID_DISABLED  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_NSNID_ENABLED  (0x00000003U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SID_MASK  (0x00000030U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SID_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SID_NOTIMPLEMENTED  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SNID_MASK  (0x000000C0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SNID_SHIFT  (6U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SNID_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_SNID_NOTIMPLEMENTED  (0x00000000U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_AUTHSTATUS_RESETVAL  (0x00000005U)

/* CSCTI_REGS_DEVID */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_EXTMUXNUM_MASK  (0x0000001FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_EXTMUXNUM_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_EXTMUXNUM_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_EXTMUXNUM_MAX  (0x0000001fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMTRIG_MASK   (0x0000FF00U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMTRIG_SHIFT  (8U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMTRIG_RESETVAL  (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMTRIG_MAX    (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMCH_MASK     (0x000F0000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMCH_SHIFT    (16U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMCH_RESETVAL  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_NUMCH_MAX      (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVID_RESETVAL       (0x00040800U)

/* CSCTI_REGS_DEVTYPE */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_MAJOR_TYPE_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_MAJOR_TYPE_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_MAJOR_TYPE_RESETVAL  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_MAJOR_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_SUB_TYPE_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_SUB_TYPE_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_SUB_TYPE_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_SUB_TYPE_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_DEVTYPE_RESETVAL     (0x00000014U)

/* CSCTI_REGS_PERIPHID0 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0_PART_0_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0_PART_0_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0_PART_0_RESETVAL  (0x00000006U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0_PART_0_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID0_RESETVAL   (0x00000006U)

/* CSCTI_REGS_PERIPHID1 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_PART_1_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_PART_1_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_PART_1_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_PART_1_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_DES_0_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_DES_0_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_DES_0_RESETVAL  (0x0000000bU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_DES_0_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID1_RESETVAL   (0x000000b9U)

/* CSCTI_REGS_PERIPHID2 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_DES_1_MASK  (0x00000007U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_DES_1_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_DES_1_RESETVAL  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_DES_1_ARMJEP106IDENTITYCODE64  (0x00000003U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_JEDEC_MASK  (0x00000008U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_JEDEC_SHIFT  (3U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_JEDEC_RESETVAL  (0x00000001U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_JEDEC_JEDECIDENTITY  (0x00000001U)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_REVISION_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_REVISION_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_REVISION_RESETVAL  (0x00000003U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_REVISION_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID2_RESETVAL   (0x0000003bU)

/* CSCTI_REGS_PERIPHID3 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_REVAND_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_REVAND_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_REVAND_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_REVAND_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_CMOD_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_CMOD_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_CMOD_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_CMOD_MAX   (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID3_RESETVAL   (0x00000000U)

/* CSCTI_REGS_PERIPHID4 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_DES_2_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_DES_2_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_DES_2_RESETVAL  (0x00000004U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_DES_2_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_SIZE_MASK  (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_SIZE_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_SIZE_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_SIZE_MAX   (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID4_RESETVAL   (0x00000004U)

/* CSCTI_REGS_PERIPHID5 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID5_RESETVAL   (0x00000000U)

/* CSCTI_REGS_PERIPHID6 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID6_RESETVAL   (0x00000000U)

/* CSCTI_REGS_PERIPHID7 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_PERIPHID7_RESETVAL   (0x00000000U)

/* CSCTI_REGS_COMPID0 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0_PRMBL_0_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0_PRMBL_0_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0_PRMBL_0_RESETVAL  (0x0000000dU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0_PRMBL_0_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID0_RESETVAL     (0x0000000dU)

/* CSCTI_REGS_COMPID1 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_CLASS_MASK   (0x000000F0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_CLASS_SHIFT  (4U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_CLASS_RESETVAL  (0x00000009U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_CLASS_MAX    (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_PRMBL_1_MASK  (0x0000000FU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_PRMBL_1_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_PRMBL_1_RESETVAL  (0x00000000U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_PRMBL_1_MAX  (0x0000000fU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID1_RESETVAL     (0x00000090U)

/* CSCTI_REGS_COMPID2 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2_PRMBL_2_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2_PRMBL_2_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2_PRMBL_2_RESETVAL  (0x00000005U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2_PRMBL_2_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID2_RESETVAL     (0x00000005U)

/* CSCTI_REGS_COMPID3 */

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3_PRMBL_3_MASK  (0x000000FFU)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3_PRMBL_3_SHIFT  (0U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3_PRMBL_3_RESETVAL  (0x000000b1U)
#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3_PRMBL_3_MAX  (0x000000ffU)

#define CSL_CT_TRACECELL_TETRIS_CSCTI_REGS_COMPID3_RESETVAL     (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
