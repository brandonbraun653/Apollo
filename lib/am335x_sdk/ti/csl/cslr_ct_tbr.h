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
#ifndef CSLR_CT_TBR_H_
#define CSLR_CT_TBR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for CT_TBR
**************************************************************************/
typedef struct {
    volatile Uint32 RSVD;
    volatile Uint32 CT_TBR_RAMSZ;
    volatile Uint32 CT_TBR_FIFOSZ;
    volatile Uint32 CT_TBR_STAT;
    volatile Uint32 CT_TBR_RAMRDAT;
    volatile Uint32 CT_TBR_RAMRPTR;
    volatile Uint32 CT_TBR_RAMWPTR;
    volatile Uint32 CT_TBR_TRGCNT;
    volatile Uint32 CT_TBR_CTRL;
    volatile Uint32 CT_TBR_RAMWDAT;
    volatile Uint8  RSVD0[216];
    volatile Uint32 CT_TBR_OUTLVL;
    volatile Uint32 CT_TBR_SICTRL;
    volatile Uint32 CT_TBR_IDPERIOD;
    volatile Uint32 CT_TBR_SEQCNTL;
    volatile Uint8  RSVD1[16];
    volatile Uint32 CT_TBR_EOI;
    volatile Uint32 CT_TBR_IRQSTATUS_RAW;
    volatile Uint32 CT_TBR_IRQSTATUS;
    volatile Uint32 CT_TBR_IRQENABLE_SET;
    volatile Uint32 CT_TBR_IRQENABLE_CLR;
    volatile Uint8  RSVD2[460];
    volatile Uint32 CT_TBR_OPSTAT;
    volatile Uint32 CT_TBR_OPCTRL;
    volatile Uint8  RSVD3[3224];
    volatile Uint32 CLAIMSET;
    volatile Uint32 CLAIMCLR;
    volatile Uint8  RSVD4[8];
    volatile Uint32 LOCKACC;
    volatile Uint32 LOCKSTAT;
    volatile Uint32 AUTHSTAT;
    volatile Uint8  RSVD5[12];
    volatile Uint32 DEVID;
    volatile Uint32 DEVTYPE;
    volatile Uint32 PERIPHID4;
    volatile Uint32 PERIPHID5;
    volatile Uint32 PERIPHID6;
    volatile Uint32 PERIPHID7;
    volatile Uint32 PERIPHID0;
    volatile Uint32 PERIPHID1;
    volatile Uint32 PERIPHID2;
    volatile Uint32 PERIPHID3;
    volatile Uint32 COMPID0;
    volatile Uint32 COMPID1;
    volatile Uint32 COMPID2;
    volatile Uint32 COMPID3;
} CSL_Ct_tbrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* RSVD */
#define CSL_CT_TBR_RSVD                                         (0x0U)

/* CT-TBR RAM Size Register This register indicates the size of the local
 * memory buffer interfaced with the CT-TBR This register can be used to
 * determine if the CT_TBR is synthesized for System Bridge Mode only. It will
 * read 0x00000000 in this configuration. */
#define CSL_CT_TBR_CT_TBR_RAMSZ                                 (0x4U)

/* CT-TBR Output FIFO Size Register This register indicates the size of output
 * FIFO used to transfer data to the system slave interface */
#define CSL_CT_TBR_CT_TBR_FIFOSZ                                (0x8U)

/* TBR Status Register This register indicates status of various functions
 * performed by CT-TBR */
#define CSL_CT_TBR_CT_TBR_STAT                                  (0xCU)

/* RAM Read Data Register This register is used to transfer data from the
 * local memory to client This register is not present when CT-TBR is
 * synthesized for System Bridge Mode only. */
#define CSL_CT_TBR_CT_TBR_RAMRDAT                               (0x10U)

/* RAM Read Pointer Register Indexes into the local memory for reading 32-bit
 * values via RAMRDAT This register is not present when CT-TBR is synthesized
 * for System Bridge Mode only. */
#define CSL_CT_TBR_CT_TBR_RAMRPTR                               (0x14U)

/* This field designates the index of the 32-bit RAM location to be written
 * via RAMWDAT. Read: Returns the current value of the pointer Write: Sets the
 * value Writes will always force the bits 1:0 of write_value to 0. This
 * register should not be used when the data acquisition is enabled (results
 * are undefined). The actual width of the pointer field will be determined by
 * the buffer size1 */
#define CSL_CT_TBR_CT_TBR_RAMWPTR                               (0x18U)

/* Trigger Count Register This register controls the amount of data written to
 * the local memory after a trigger input is detected */
#define CSL_CT_TBR_CT_TBR_TRGCNT                                (0x1CU)

/* CT-TBR Control Register This register controls the global enable/disable
 * functions of the CT-TBR */
#define CSL_CT_TBR_CT_TBR_CTRL                                  (0x20U)

/* RAM Write Data Register This register is used to transfer data from the
 * client to local memory This register is not present when CT-TBR is
 * synthesized for System Bridge Mode only. */
#define CSL_CT_TBR_CT_TBR_RAMWDAT                               (0x24U)

/* Output FIFO Trigger Level Register This register controls the size of the
 * data blocks transferred through the output FIFO and across the system
 * interface */
#define CSL_CT_TBR_CT_TBR_OUTLVL                                (0x100U)

/* CT-TBR System Interface Control This register provides control and status
 * for the system interface of the CT-TBR */
#define CSL_CT_TBR_CT_TBR_SICTRL                                (0x104U)

/* ID Repeat Period Register This register controls the number of frames
 * (without and ID change marker) that will be sent before the formatter
 * forces and ID marker */
#define CSL_CT_TBR_CT_TBR_IDPERIOD                              (0x108U)

/* CT_TBR SEQCNTL register */
#define CSL_CT_TBR_CT_TBR_SEQCNTL                               (0x10CU)

/* CT-TBR EOI register This register is the End of Interrupt used by SW to
 * signal HW that an interrupt service is complete and an interrupt can be
 * rearmed. */
#define CSL_CT_TBR_CT_TBR_EOI                                   (0x120U)

/* CT-TBR IRQ Status (Raw) register This register provides control and status
 * for the interrupt/event interface The IRQSTATUS_RAW register may be
 * modified while acquisition is enabled */
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW                         (0x124U)

/* CT-TBR IRQ Status register This register provides control and status for
 * the interrupt/event interface The IRQSTATUS register may be modified while
 * acquisition is enabled */
#define CSL_CT_TBR_CT_TBR_IRQSTATUS                             (0x128U)

/* CT-TBR IRQ Enable set register This register provides control for the
 * interrupt/event interface The IRQENABLE_SET register may be modified while
 * acquisition is enabled */
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET                         (0x12CU)

/* CT-TBR IRQ Enable clear register This register provides control for the
 * interrupt/event interface The IRQENABLE_CLR register may be modified while
 * acquisition is enabled */
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR                         (0x130U)

/* Operation Status Register This register provides information on the status
 * of various operations of the CT-TBR */
#define CSL_CT_TBR_CT_TBR_OPSTAT                                (0x300U)

/* CT_TBR_OPCTRL */
#define CSL_CT_TBR_CT_TBR_OPCTRL                                (0x304U)

/* The Claim Tag Set Register The register is used to manage handshakes
 * between application and tools SW using the CT-TBR */
#define CSL_CT_TBR_CLAIMSET                                     (0xFA0U)

/* The Claim Tag Clear Register The register is used to manage handshakes
 * between application and tools SW using the CT-TBR */
#define CSL_CT_TBR_CLAIMCLR                                     (0xFA4U)

/* The Lock Access Register The register is used to enabled application use of
 * the CT-TBR */
#define CSL_CT_TBR_LOCKACC                                      (0xFB0U)

/* The Lock Status Register The register is used to manage application use of
 * the CT-TBR */
#define CSL_CT_TBR_LOCKSTAT                                     (0xFB4U)

/* Authorization Status Register Indicates which security features (if any)
 * are implemented in the module. */
#define CSL_CT_TBR_AUTHSTAT                                     (0xFB8U)

/* Device Identification Register Defines the major and minor versions of this
 * implementation of the CT-TBR */
#define CSL_CT_TBR_DEVID                                        (0xFC8U)

/* Device Type Register Indicates the top-level function of the module */
#define CSL_CT_TBR_DEVTYPE                                      (0xFCCU)

/* Peripheral Identification Register Number 4 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID4                                    (0xFD0U)

/* Peripheral Identification Register Number 5 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID5                                    (0xFD4U)

/* Peripheral Identification Register Number 6 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID6                                    (0xFD8U)

/* Peripheral Identification Register Number 7 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID7                                    (0xFDCU)

/* Peripheral Identification Register Number 0 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID0                                    (0xFE0U)

/* Peripheral Identification Register Number 4 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID1                                    (0xFE4U)

/* Peripheral Identification Register Number 2 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID2                                    (0xFE8U)

/* Peripheral Identification Register Number 3 The Peripheral ID registers
 * indicate module specifics like manufacturer and part number */
#define CSL_CT_TBR_PERIPHID3                                    (0xFECU)

/* Component Identification Register Number 0 The Component ID registers
 * places a known bit pattern in memory that indicates that a 4K configuration
 * block is valid and supports a peripheral */
#define CSL_CT_TBR_COMPID0                                      (0xFF0U)

/* Component Identification Register Number 1 The Component ID registers
 * places a known bit pattern in memory that indicates that a 4K configuration
 * block is valid and supports a peripheral */
#define CSL_CT_TBR_COMPID1                                      (0xFF4U)

/* Component Identification Register Number 2 The Component ID registers
 * places a known bit pattern in memory that indicates that a 4K configuration
 * block is valid and supports a peripheral */
#define CSL_CT_TBR_COMPID2                                      (0xFF8U)

/* 2Component Identification Register Number 3 The Component ID registers
 * places a known bit pattern in memory that indicates that a 4K configuration
 * block is valid and supports a peripheral */
#define CSL_CT_TBR_COMPID3                                      (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* RSVD */

#define CSL_CT_TBR_RSVD_RESETVAL                                (0x00000000U)

/* CT_TBR_RAMSZ */

#define CSL_CT_TBR_CT_TBR_RAMSZ_RAM_SIZE_MASK                   (0x00000007U)
#define CSL_CT_TBR_CT_TBR_RAMSZ_RAM_SIZE_SHIFT                  (0U)
#define CSL_CT_TBR_CT_TBR_RAMSZ_RAM_SIZE_RESETVAL               (0x00000000U)
#define CSL_CT_TBR_CT_TBR_RAMSZ_RAM_SIZE_MAX                    (0x00000007U)

#define CSL_CT_TBR_CT_TBR_RAMSZ_RESETVAL                        (0x00000000U)

/* CT_TBR_FIFOSZ */

#define CSL_CT_TBR_CT_TBR_FIFOSZ_FIFO_SIZE_MASK                 (0x00000007U)
#define CSL_CT_TBR_CT_TBR_FIFOSZ_FIFO_SIZE_SHIFT                (0U)
#define CSL_CT_TBR_CT_TBR_FIFOSZ_FIFO_SIZE_RESETVAL             (0x00000000U)
#define CSL_CT_TBR_CT_TBR_FIFOSZ_FIFO_SIZE_MAX                  (0x00000007U)

#define CSL_CT_TBR_CT_TBR_FIFOSZ_RESETVAL                       (0x00000000U)

/* CT_TBR_STAT */

#define CSL_CT_TBR_CT_TBR_STAT_WRAP_MASK                        (0x00000001U)
#define CSL_CT_TBR_CT_TBR_STAT_WRAP_SHIFT                       (0U)
#define CSL_CT_TBR_CT_TBR_STAT_WRAP_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_CT_TBR_STAT_WRAP_MAX                         (0x00000001U)

#define CSL_CT_TBR_CT_TBR_STAT_TRIG_MASK                        (0x00000002U)
#define CSL_CT_TBR_CT_TBR_STAT_TRIG_SHIFT                       (1U)
#define CSL_CT_TBR_CT_TBR_STAT_TRIG_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_CT_TBR_STAT_TRIG_MAX                         (0x00000001U)

#define CSL_CT_TBR_CT_TBR_STAT_CPT_DONE_MASK                    (0x00000004U)
#define CSL_CT_TBR_CT_TBR_STAT_CPT_DONE_SHIFT                   (2U)
#define CSL_CT_TBR_CT_TBR_STAT_CPT_DONE_RESETVAL                (0x00000001U)
#define CSL_CT_TBR_CT_TBR_STAT_CPT_DONE_MAX                     (0x00000001U)

#define CSL_CT_TBR_CT_TBR_STAT_FMT_DONE_MASK                    (0x00000008U)
#define CSL_CT_TBR_CT_TBR_STAT_FMT_DONE_SHIFT                   (3U)
#define CSL_CT_TBR_CT_TBR_STAT_FMT_DONE_RESETVAL                (0x00000001U)
#define CSL_CT_TBR_CT_TBR_STAT_FMT_DONE_MAX                     (0x00000001U)

#define CSL_CT_TBR_CT_TBR_STAT_DRAIN_DONE_MASK                  (0x00000010U)
#define CSL_CT_TBR_CT_TBR_STAT_DRAIN_DONE_SHIFT                 (4U)
#define CSL_CT_TBR_CT_TBR_STAT_DRAIN_DONE_RESETVAL              (0x00000001U)
#define CSL_CT_TBR_CT_TBR_STAT_DRAIN_DONE_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_STAT_RESETVAL                         (0x0000001cU)

/* CT_TBR_RAMRDAT */

#define CSL_CT_TBR_CT_TBR_RAMRDAT_DATA_MASK                     (0xFFFFFFFFU)
#define CSL_CT_TBR_CT_TBR_RAMRDAT_DATA_SHIFT                    (0U)
#define CSL_CT_TBR_CT_TBR_RAMRDAT_DATA_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_CT_TBR_RAMRDAT_DATA_MAX                      (0xffffffffU)

#define CSL_CT_TBR_CT_TBR_RAMRDAT_RESETVAL                      (0x00000000U)

/* CT_TBR_RAMRPTR */

#define CSL_CT_TBR_CT_TBR_RAMRPTR_PTR_MASK                      (0x003FFFFFU)
#define CSL_CT_TBR_CT_TBR_RAMRPTR_PTR_SHIFT                     (0U)
#define CSL_CT_TBR_CT_TBR_RAMRPTR_PTR_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_CT_TBR_RAMRPTR_PTR_MAX                       (0x003fffffU)

#define CSL_CT_TBR_CT_TBR_RAMRPTR_RESETVAL                      (0x00000000U)

/* CT_TBR_RAMWPTR */

#define CSL_CT_TBR_CT_TBR_RAMWPTR_PTR_MASK                      (0x003FFFFFU)
#define CSL_CT_TBR_CT_TBR_RAMWPTR_PTR_SHIFT                     (0U)
#define CSL_CT_TBR_CT_TBR_RAMWPTR_PTR_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_CT_TBR_RAMWPTR_PTR_MAX                       (0x003fffffU)

#define CSL_CT_TBR_CT_TBR_RAMWPTR_RESETVAL                      (0x00000000U)

/* CT_TBR_TRGCNT */

#define CSL_CT_TBR_CT_TBR_TRGCNT_COUNT_MASK                     (0x00000001U)
#define CSL_CT_TBR_CT_TBR_TRGCNT_COUNT_SHIFT                    (0U)
#define CSL_CT_TBR_CT_TBR_TRGCNT_COUNT_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_CT_TBR_TRGCNT_COUNT_MAX                      (0x00000001U)

#define CSL_CT_TBR_CT_TBR_TRGCNT_RESETVAL                       (0x00000000U)

/* CT_TBR_CTRL */

#define CSL_CT_TBR_CT_TBR_CTRL_ENBL_MASK                        (0x00000001U)
#define CSL_CT_TBR_CT_TBR_CTRL_ENBL_SHIFT                       (0U)
#define CSL_CT_TBR_CT_TBR_CTRL_ENBL_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_CT_TBR_CTRL_ENBL_MAX                         (0x00000001U)

#define CSL_CT_TBR_CT_TBR_CTRL_MODE_MASK                        (0x00000002U)
#define CSL_CT_TBR_CT_TBR_CTRL_MODE_SHIFT                       (1U)
#define CSL_CT_TBR_CT_TBR_CTRL_MODE_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_CT_TBR_CTRL_MODE_MAX                         (0x00000001U)

#define CSL_CT_TBR_CT_TBR_CTRL_RESETVAL                         (0x00000000U)

/* CT_TBR_RAMWDAT */

#define CSL_CT_TBR_CT_TBR_RAMWDAT_DATA_MASK                     (0xFFFFFFFFU)
#define CSL_CT_TBR_CT_TBR_RAMWDAT_DATA_SHIFT                    (0U)
#define CSL_CT_TBR_CT_TBR_RAMWDAT_DATA_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_CT_TBR_RAMWDAT_DATA_MAX                      (0xffffffffU)

#define CSL_CT_TBR_CT_TBR_RAMWDAT_RESETVAL                      (0x00000000U)

/* CT_TBR_OUTLVL */

#define CSL_CT_TBR_CT_TBR_OUTLVL_OUTLEVEL_MASK                  (0x0000003FU)
#define CSL_CT_TBR_CT_TBR_OUTLVL_OUTLEVEL_SHIFT                 (0U)
#define CSL_CT_TBR_CT_TBR_OUTLVL_OUTLEVEL_RESETVAL              (0x0000003fU)
#define CSL_CT_TBR_CT_TBR_OUTLVL_OUTLEVEL_MAX                   (0x0000003fU)

#define CSL_CT_TBR_CT_TBR_OUTLVL_RESETVAL                       (0x0000003fU)

/* CT_TBR_SICTRL */

#define CSL_CT_TBR_CT_TBR_SICTRL_DATA_WIDTH_MASK                (0x00000001U)
#define CSL_CT_TBR_CT_TBR_SICTRL_DATA_WIDTH_SHIFT               (0U)
#define CSL_CT_TBR_CT_TBR_SICTRL_DATA_WIDTH_RESETVAL            (0x00000000U)
#define CSL_CT_TBR_CT_TBR_SICTRL_DATA_WIDTH_MAX                 (0x00000001U)

#define CSL_CT_TBR_CT_TBR_SICTRL_REQ_PEND_MASK                  (0x00000002U)
#define CSL_CT_TBR_CT_TBR_SICTRL_REQ_PEND_SHIFT                 (1U)
#define CSL_CT_TBR_CT_TBR_SICTRL_REQ_PEND_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_SICTRL_REQ_PEND_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_SICTRL_ERR_MASK                       (0x00000004U)
#define CSL_CT_TBR_CT_TBR_SICTRL_ERR_SHIFT                      (2U)
#define CSL_CT_TBR_CT_TBR_SICTRL_ERR_RESETVAL                   (0x00000000U)
#define CSL_CT_TBR_CT_TBR_SICTRL_ERR_MAX                        (0x00000001U)

#define CSL_CT_TBR_CT_TBR_SICTRL_IDLE_MODE_MASK                 (0x00000030U)
#define CSL_CT_TBR_CT_TBR_SICTRL_IDLE_MODE_SHIFT                (4U)
#define CSL_CT_TBR_CT_TBR_SICTRL_IDLE_MODE_RESETVAL             (0x00000002U)
#define CSL_CT_TBR_CT_TBR_SICTRL_IDLE_MODE_MAX                  (0x00000003U)

#define CSL_CT_TBR_CT_TBR_SICTRL_RESETVAL                       (0x00000020U)

/* CT_TBR_IDPERIOD */

#define CSL_CT_TBR_CT_TBR_IDPERIOD_PERIOD_MASK                  (0x000003FFU)
#define CSL_CT_TBR_CT_TBR_IDPERIOD_PERIOD_SHIFT                 (0U)
#define CSL_CT_TBR_CT_TBR_IDPERIOD_PERIOD_RESETVAL              (0x00000008U)
#define CSL_CT_TBR_CT_TBR_IDPERIOD_PERIOD_MAX                   (0x000003ffU)

#define CSL_CT_TBR_CT_TBR_IDPERIOD_RESETVAL                     (0x00000008U)

/* CT_TBR_SEQCNTL */

#define CSL_CT_TBR_CT_TBR_SEQCNTL_SEQCNTL_MASK                  (0xFFFFFFFFU)
#define CSL_CT_TBR_CT_TBR_SEQCNTL_SEQCNTL_SHIFT                 (0U)
#define CSL_CT_TBR_CT_TBR_SEQCNTL_SEQCNTL_RESETVAL              (0x006f0000U)
#define CSL_CT_TBR_CT_TBR_SEQCNTL_SEQCNTL_MAX                   (0xffffffffU)

#define CSL_CT_TBR_CT_TBR_SEQCNTL_RESETVAL                      (0x006f0000U)

/* CT_TBR_EOI */

#define CSL_CT_TBR_CT_TBR_EOI_EOI_VECT_MASK                     (0x00000001U)
#define CSL_CT_TBR_CT_TBR_EOI_EOI_VECT_SHIFT                    (0U)
#define CSL_CT_TBR_CT_TBR_EOI_EOI_VECT_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_CT_TBR_EOI_EOI_VECT_MAX                      (0x00000001U)

#define CSL_CT_TBR_CT_TBR_EOI_RESETVAL                          (0x00000000U)

/* CT_TBR_IRQSTATUS_RAW */

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_DAV_IRQ_MASK            (0x00000001U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_DAV_IRQ_SHIFT           (0U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_DAV_IRQ_RESETVAL        (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_DAV_IRQ_MAX             (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_AQCMP_IRQ_MASK          (0x00000002U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_AQCMP_IRQ_SHIFT         (1U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_AQCMP_IRQ_RESETVAL      (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_AQCMP_IRQ_MAX           (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RAW_RESETVAL                (0x00000000U)

/* CT_TBR_IRQSTATUS */

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_DAV_IE_MASK                 (0x00000001U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_DAV_IE_SHIFT                (0U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_DAV_IE_RESETVAL             (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_DAV_IE_MAX                  (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_AQCMP_IE_MASK               (0x00000002U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_AQCMP_IE_SHIFT              (1U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_AQCMP_IE_RESETVAL           (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQSTATUS_AQCMP_IE_MAX                (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQSTATUS_RESETVAL                    (0x00000000U)

/* CT_TBR_IRQENABLE_SET */

#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_DAV_IES_MASK            (0x00000001U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_DAV_IES_SHIFT           (0U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_DAV_IES_RESETVAL        (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_DAV_IES_MAX             (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_AQCMP_IES_MASK          (0x00000002U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_AQCMP_IES_SHIFT         (1U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_AQCMP_IES_RESETVAL      (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_AQCMP_IES_MAX           (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQENABLE_SET_RESETVAL                (0x00000000U)

/* CT_TBR_IRQENABLE_CLR */

#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_DAV_IEC_MASK            (0x00000001U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_DAV_IEC_SHIFT           (0U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_DAV_IEC_RESETVAL        (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_DAV_IEC_MAX             (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_AQCMP_IEC_MASK          (0x00000002U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_AQCMP_IEC_SHIFT         (1U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_AQCMP_IEC_RESETVAL      (0x00000000U)
#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_AQCMP_IEC_MAX           (0x00000001U)

#define CSL_CT_TBR_CT_TBR_IRQENABLE_CLR_RESETVAL                (0x00000000U)

/* CT_TBR_OPSTAT */

#define CSL_CT_TBR_CT_TBR_OPSTAT_FLSH_ACT_MASK                  (0x00000001U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FLSH_ACT_SHIFT                 (0U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FLSH_ACT_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FLSH_ACT_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPSTAT_FMT_HALTED_MASK                (0x00000002U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FMT_HALTED_SHIFT               (1U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FMT_HALTED_RESETVAL            (0x00000001U)
#define CSL_CT_TBR_CT_TBR_OPSTAT_FMT_HALTED_MAX                 (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPSTAT_RESETVAL                       (0x00000002U)

/* CT_TBR_OPCTRL */

#define CSL_CT_TBR_CT_TBR_OPCTRL_FMT_ENBL_MASK                  (0x00000001U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FMT_ENBL_SHIFT                 (0U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FMT_ENBL_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FMT_ENBL_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_INSRT_TRG_MASK                 (0x00000002U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_INSRT_TRG_SHIFT                (1U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_INSRT_TRG_RESETVAL             (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_INSRT_TRG_MAX                  (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_FLSHIN_MASK               (0x00000010U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_FLSHIN_SHIFT              (4U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_FLSHIN_RESETVAL           (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_FLSHIN_MAX                (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_TRG_MASK                  (0x00000020U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_TRG_SHIFT                 (5U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_TRG_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLSH_TRG_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_FLUSH_MASK                     (0x00000040U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLUSH_SHIFT                    (6U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLUSH_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_FLUSH_MAX                      (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_TRGIN_MASK                 (0x00000100U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_TRGIN_SHIFT                (8U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_TRGIN_RESETVAL             (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_TRGIN_MAX                  (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_EVT_MASK                   (0x00000200U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_EVT_SHIFT                  (9U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_EVT_RESETVAL               (0x00000001U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_EVT_MAX                    (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_FLSH_MASK                  (0x00000400U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_FLSH_SHIFT                 (10U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_FLSH_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_TRG_FLSH_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FLSH_MASK                  (0x00001000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FLSH_SHIFT                 (12U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FLSH_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FLSH_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_TRG_MASK                   (0x00002000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_TRG_SHIFT                  (13U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_TRG_RESETVAL               (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_TRG_MAX                    (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FULL_MASK                  (0x00008000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FULL_SHIFT                 (15U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FULL_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_STP_FULL_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_OUTFLUSH_MASK                  (0x00010000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_OUTFLUSH_SHIFT                 (16U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_OUTFLUSH_RESETVAL              (0x00000000U)
#define CSL_CT_TBR_CT_TBR_OPCTRL_OUTFLUSH_MAX                   (0x00000001U)

#define CSL_CT_TBR_CT_TBR_OPCTRL_RESETVAL                       (0x00000200U)

/* CLAIMSET */

#define CSL_CT_TBR_CLAIMSET_CTSET_MASK                          (0x0000000FU)
#define CSL_CT_TBR_CLAIMSET_CTSET_SHIFT                         (0U)
#define CSL_CT_TBR_CLAIMSET_CTSET_RESETVAL                      (0x0000000fU)
#define CSL_CT_TBR_CLAIMSET_CTSET_MAX                           (0x0000000fU)

#define CSL_CT_TBR_CLAIMSET_RESETVAL                            (0x0000000fU)

/* CLAIMCLR */

#define CSL_CT_TBR_CLAIMCLR_CTCLR_MASK                          (0x0000000FU)
#define CSL_CT_TBR_CLAIMCLR_CTCLR_SHIFT                         (0U)
#define CSL_CT_TBR_CLAIMCLR_CTCLR_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_CLAIMCLR_CTCLR_MAX                           (0x0000000fU)

#define CSL_CT_TBR_CLAIMCLR_RESETVAL                            (0x00000000U)

/* LOCKACC */

#define CSL_CT_TBR_LOCKACC_CODE_MASK                            (0xFFFFFFFFU)
#define CSL_CT_TBR_LOCKACC_CODE_SHIFT                           (0U)
#define CSL_CT_TBR_LOCKACC_CODE_RESETVAL                        (0x00000000U)
#define CSL_CT_TBR_LOCKACC_CODE_MAX                             (0xffffffffU)

#define CSL_CT_TBR_LOCKACC_RESETVAL                             (0x00000000U)

/* LOCKSTAT */

#define CSL_CT_TBR_LOCKSTAT_LOCKIMP_MASK                        (0x00000001U)
#define CSL_CT_TBR_LOCKSTAT_LOCKIMP_SHIFT                       (0U)
#define CSL_CT_TBR_LOCKSTAT_LOCKIMP_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_LOCKSTAT_LOCKIMP_MAX                         (0x00000001U)

#define CSL_CT_TBR_LOCKSTAT_STAT_MASK                           (0x00000002U)
#define CSL_CT_TBR_LOCKSTAT_STAT_SHIFT                          (1U)
#define CSL_CT_TBR_LOCKSTAT_STAT_RESETVAL                       (0x00000001U)
#define CSL_CT_TBR_LOCKSTAT_STAT_MAX                            (0x00000001U)

#define CSL_CT_TBR_LOCKSTAT_LOCKSZ_MASK                         (0x00000004U)
#define CSL_CT_TBR_LOCKSTAT_LOCKSZ_SHIFT                        (2U)
#define CSL_CT_TBR_LOCKSTAT_LOCKSZ_RESETVAL                     (0x00000000U)
#define CSL_CT_TBR_LOCKSTAT_LOCKSZ_MAX                          (0x00000001U)

#define CSL_CT_TBR_LOCKSTAT_RESETVAL                            (0x00000002U)

/* AUTHSTAT */

#define CSL_CT_TBR_AUTHSTAT_NS_I_STAT_MASK                      (0x00000003U)
#define CSL_CT_TBR_AUTHSTAT_NS_I_STAT_SHIFT                     (0U)
#define CSL_CT_TBR_AUTHSTAT_NS_I_STAT_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_AUTHSTAT_NS_I_STAT_MAX                       (0x00000003U)

#define CSL_CT_TBR_AUTHSTAT_NS_NI_STAT_MASK                     (0x0000000CU)
#define CSL_CT_TBR_AUTHSTAT_NS_NI_STAT_SHIFT                    (2U)
#define CSL_CT_TBR_AUTHSTAT_NS_NI_STAT_RESETVAL                 (0x00000000U)
#define CSL_CT_TBR_AUTHSTAT_NS_NI_STAT_MAX                      (0x00000003U)

#define CSL_CT_TBR_AUTHSTAT_S_I_STAT_MASK                       (0x00000030U)
#define CSL_CT_TBR_AUTHSTAT_S_I_STAT_SHIFT                      (4U)
#define CSL_CT_TBR_AUTHSTAT_S_I_STAT_RESETVAL                   (0x00000000U)
#define CSL_CT_TBR_AUTHSTAT_S_I_STAT_MAX                        (0x00000003U)

#define CSL_CT_TBR_AUTHSTAT_S_NI_STAT_MASK                      (0x000000C0U)
#define CSL_CT_TBR_AUTHSTAT_S_NI_STAT_SHIFT                     (6U)
#define CSL_CT_TBR_AUTHSTAT_S_NI_STAT_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_AUTHSTAT_S_NI_STAT_MAX                       (0x00000003U)

#define CSL_CT_TBR_AUTHSTAT_RESETVAL                            (0x00000000U)

/* DEVID */

#define CSL_CT_TBR_DEVID_REV_MIN_MASK                           (0x0000000FU)
#define CSL_CT_TBR_DEVID_REV_MIN_SHIFT                          (0U)
#define CSL_CT_TBR_DEVID_REV_MIN_RESETVAL                       (0x00000000U)
#define CSL_CT_TBR_DEVID_REV_MIN_MAX                            (0x0000000fU)

#define CSL_CT_TBR_DEVID_REV_MAJOR_MASK                         (0x00000010U)
#define CSL_CT_TBR_DEVID_REV_MAJOR_SHIFT                        (4U)
#define CSL_CT_TBR_DEVID_REV_MAJOR_RESETVAL                     (0x00000001U)
#define CSL_CT_TBR_DEVID_REV_MAJOR_MAX                          (0x00000001U)

#define CSL_CT_TBR_DEVID_RESETVAL                               (0x00000010U)

/* DEVTYPE */

#define CSL_CT_TBR_DEVTYPE_MAIN_CLASS_MASK                      (0x0000000FU)
#define CSL_CT_TBR_DEVTYPE_MAIN_CLASS_SHIFT                     (0U)
#define CSL_CT_TBR_DEVTYPE_MAIN_CLASS_RESETVAL                  (0x00000001U)
#define CSL_CT_TBR_DEVTYPE_MAIN_CLASS_MAX                       (0x0000000fU)

#define CSL_CT_TBR_DEVTYPE_SUB_TYPE_MASK                        (0x000000F0U)
#define CSL_CT_TBR_DEVTYPE_SUB_TYPE_SHIFT                       (4U)
#define CSL_CT_TBR_DEVTYPE_SUB_TYPE_RESETVAL                    (0x00000002U)
#define CSL_CT_TBR_DEVTYPE_SUB_TYPE_MAX                         (0x0000000fU)

#define CSL_CT_TBR_DEVTYPE_RESETVAL                             (0x00000021U)

/* PERIPHID4 */

#define CSL_CT_TBR_PERIPHID4_JEP_CONT_MASK                      (0x0000000FU)
#define CSL_CT_TBR_PERIPHID4_JEP_CONT_SHIFT                     (0U)
#define CSL_CT_TBR_PERIPHID4_JEP_CONT_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_PERIPHID4_JEP_CONT_MAX                       (0x0000000fU)

#define CSL_CT_TBR_PERIPHID4_KB_COUNT_MASK                      (0x000000F0U)
#define CSL_CT_TBR_PERIPHID4_KB_COUNT_SHIFT                     (4U)
#define CSL_CT_TBR_PERIPHID4_KB_COUNT_RESETVAL                  (0x00000000U)
#define CSL_CT_TBR_PERIPHID4_KB_COUNT_MAX                       (0x0000000fU)

#define CSL_CT_TBR_PERIPHID4_RESETVAL                           (0x00000000U)

/* PERIPHID5 */

#define CSL_CT_TBR_PERIPHID5_PID5_MASK                          (0x000000FFU)
#define CSL_CT_TBR_PERIPHID5_PID5_SHIFT                         (0U)
#define CSL_CT_TBR_PERIPHID5_PID5_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_PERIPHID5_PID5_MAX                           (0x000000ffU)

#define CSL_CT_TBR_PERIPHID5_RESETVAL                           (0x00000000U)

/* PERIPHID6 */

#define CSL_CT_TBR_PERIPHID6_PID6_MASK                          (0x000000FFU)
#define CSL_CT_TBR_PERIPHID6_PID6_SHIFT                         (0U)
#define CSL_CT_TBR_PERIPHID6_PID6_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_PERIPHID6_PID6_MAX                           (0x000000ffU)

#define CSL_CT_TBR_PERIPHID6_PID7_MASK                          (0xFFFFFF00U)
#define CSL_CT_TBR_PERIPHID6_PID7_SHIFT                         (8U)
#define CSL_CT_TBR_PERIPHID6_PID7_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_PERIPHID6_PID7_MAX                           (0x00ffffffU)

#define CSL_CT_TBR_PERIPHID6_RESETVAL                           (0x00000000U)

/* PERIPHID7 */

#define CSL_CT_TBR_PERIPHID7_PID7_MASK                          (0x000000FFU)
#define CSL_CT_TBR_PERIPHID7_PID7_SHIFT                         (0U)
#define CSL_CT_TBR_PERIPHID7_PID7_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_PERIPHID7_PID7_MAX                           (0x000000ffU)

#define CSL_CT_TBR_PERIPHID7_RESETVAL                           (0x00000000U)

/* PERIPHID0 */

#define CSL_CT_TBR_PERIPHID0_PART_ML_MASK                       (0x000000FFU)
#define CSL_CT_TBR_PERIPHID0_PART_ML_SHIFT                      (0U)
#define CSL_CT_TBR_PERIPHID0_PART_ML_RESETVAL                   (0x000000dfU)
#define CSL_CT_TBR_PERIPHID0_PART_ML_MAX                        (0x000000ffU)

#define CSL_CT_TBR_PERIPHID0_RESETVAL                           (0x000000dfU)

/* PERIPHID1 */

#define CSL_CT_TBR_PERIPHID1_PART_U_MASK                        (0x0000000FU)
#define CSL_CT_TBR_PERIPHID1_PART_U_SHIFT                       (0U)
#define CSL_CT_TBR_PERIPHID1_PART_U_RESETVAL                    (0x0000000eU)
#define CSL_CT_TBR_PERIPHID1_PART_U_MAX                         (0x0000000fU)

#define CSL_CT_TBR_PERIPHID1_JEPID_L_MASK                       (0x000000F0U)
#define CSL_CT_TBR_PERIPHID1_JEPID_L_SHIFT                      (4U)
#define CSL_CT_TBR_PERIPHID1_JEPID_L_RESETVAL                   (0x00000007U)
#define CSL_CT_TBR_PERIPHID1_JEPID_L_MAX                        (0x0000000fU)

#define CSL_CT_TBR_PERIPHID1_RESETVAL                           (0x0000007eU)

/* PERIPHID2 */

#define CSL_CT_TBR_PERIPHID2_JEPID_H_MASK                       (0x00000007U)
#define CSL_CT_TBR_PERIPHID2_JEPID_H_SHIFT                      (0U)
#define CSL_CT_TBR_PERIPHID2_JEPID_H_RESETVAL                   (0x00000001U)
#define CSL_CT_TBR_PERIPHID2_JEPID_H_MAX                        (0x00000007U)

#define CSL_CT_TBR_PERIPHID2_JEDEC_MASK                         (0x00000008U)
#define CSL_CT_TBR_PERIPHID2_JEDEC_SHIFT                        (3U)
#define CSL_CT_TBR_PERIPHID2_JEDEC_RESETVAL                     (0x00000001U)
#define CSL_CT_TBR_PERIPHID2_JEDEC_MAX                          (0x00000001U)

#define CSL_CT_TBR_PERIPHID2_REVNUM_MASK                        (0x000000F0U)
#define CSL_CT_TBR_PERIPHID2_REVNUM_SHIFT                       (4U)
#define CSL_CT_TBR_PERIPHID2_REVNUM_RESETVAL                    (0x00000001U)
#define CSL_CT_TBR_PERIPHID2_REVNUM_MAX                         (0x0000000fU)

#define CSL_CT_TBR_PERIPHID2_RESETVAL                           (0x00000019U)

/* PERIPHID3 */

#define CSL_CT_TBR_PERIPHID3_CUSTMOD_MASK                       (0x0000000FU)
#define CSL_CT_TBR_PERIPHID3_CUSTMOD_SHIFT                      (0U)
#define CSL_CT_TBR_PERIPHID3_CUSTMOD_RESETVAL                   (0x00000000U)
#define CSL_CT_TBR_PERIPHID3_CUSTMOD_MAX                        (0x0000000fU)

#define CSL_CT_TBR_PERIPHID3_REVAND_MASK                        (0x000000F0U)
#define CSL_CT_TBR_PERIPHID3_REVAND_SHIFT                       (4U)
#define CSL_CT_TBR_PERIPHID3_REVAND_RESETVAL                    (0x00000000U)
#define CSL_CT_TBR_PERIPHID3_REVAND_MAX                         (0x0000000fU)

#define CSL_CT_TBR_PERIPHID3_RESETVAL                           (0x00000000U)

/* COMPID0 */

#define CSL_CT_TBR_COMPID0_CID0_MASK                            (0x000000FFU)
#define CSL_CT_TBR_COMPID0_CID0_SHIFT                           (0U)
#define CSL_CT_TBR_COMPID0_CID0_RESETVAL                        (0x0000000dU)
#define CSL_CT_TBR_COMPID0_CID0_MAX                             (0x000000ffU)

#define CSL_CT_TBR_COMPID0_CID1_MASK                            (0xFFFFFF00U)
#define CSL_CT_TBR_COMPID0_CID1_SHIFT                           (8U)
#define CSL_CT_TBR_COMPID0_CID1_RESETVAL                        (0x00000000U)
#define CSL_CT_TBR_COMPID0_CID1_MAX                             (0x00ffffffU)

#define CSL_CT_TBR_COMPID0_RESETVAL                             (0x0000000dU)

/* COMPID1 */

#define CSL_CT_TBR_COMPID1_CID1_MASK                            (0x0000000FU)
#define CSL_CT_TBR_COMPID1_CID1_SHIFT                           (0U)
#define CSL_CT_TBR_COMPID1_CID1_RESETVAL                        (0x00000000U)
#define CSL_CT_TBR_COMPID1_CID1_MAX                             (0x0000000fU)

#define CSL_CT_TBR_COMPID1_CLASS_MASK                           (0x000000F0U)
#define CSL_CT_TBR_COMPID1_CLASS_SHIFT                          (4U)
#define CSL_CT_TBR_COMPID1_CLASS_RESETVAL                       (0x00000009U)
#define CSL_CT_TBR_COMPID1_CLASS_MAX                            (0x0000000fU)

#define CSL_CT_TBR_COMPID1_CLASS1_MASK                          (0xFFFFFF00U)
#define CSL_CT_TBR_COMPID1_CLASS1_SHIFT                         (8U)
#define CSL_CT_TBR_COMPID1_CLASS1_RESETVAL                      (0x00000000U)
#define CSL_CT_TBR_COMPID1_CLASS1_MAX                           (0x00ffffffU)

#define CSL_CT_TBR_COMPID1_RESETVAL                             (0x00000090U)

/* COMPID2 */

#define CSL_CT_TBR_COMPID2_CID2_MASK                            (0x000000FFU)
#define CSL_CT_TBR_COMPID2_CID2_SHIFT                           (0U)
#define CSL_CT_TBR_COMPID2_CID2_RESETVAL                        (0x00000005U)
#define CSL_CT_TBR_COMPID2_CID2_MAX                             (0x000000ffU)

#define CSL_CT_TBR_COMPID2_RESETVAL                             (0x00000005U)

/* COMPID3 */

#define CSL_CT_TBR_COMPID3_CID3_MASK                            (0x000000FFU)
#define CSL_CT_TBR_COMPID3_CID3_SHIFT                           (0U)
#define CSL_CT_TBR_COMPID3_CID3_RESETVAL                        (0x000000b1U)
#define CSL_CT_TBR_COMPID3_CID3_MAX                             (0x000000ffU)

#define CSL_CT_TBR_COMPID3_RESETVAL                             (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
