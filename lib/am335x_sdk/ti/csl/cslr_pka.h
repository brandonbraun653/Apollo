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
#ifndef CSLR_PKA_H_
#define CSLR_PKA_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 STS;
    volatile Uint32 CTRL;
    volatile Uint8  RSVD0[24];
    volatile Uint32 NBASE;
    volatile Uint32 XBASE;
    volatile Uint32 YBASE;
    volatile Uint32 BBASE;
    volatile Uint32 NACC;
    volatile Uint32 NZERO;
    volatile Uint8  RSVD1[60];
    volatile Uint32 OPTIONS;
    volatile Uint8  RSVD2[4];
    volatile Uint32 REVSFT;
    volatile Uint8  RSVD3[7904];
    volatile Uint32 REVISION;
    volatile Uint8  RSVD4[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint32 SYSSTS;
    volatile Uint32 IRQSTS;
    volatile Uint32 IRQEN;
    volatile Uint32 RAM[1024];
} CSL_PkaRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Register PKA_STATUS */
#define CSL_PKA_STS                                             (0x80U)

/* Register PKA_CONTROL. This register must be written to start one of the
 * operations. It can also be used to abort a running operation and flush the
 * data pipeline and LNME FIFO. */
#define CSL_PKA_CTRL                                            (0x84U)

/* This register is double-buffered; it may be written with new values for the
 * next operation while an operation is being performed. The NBASE field
 * contains the base address of the N-Operand in the PKA RAM, given as 32-bit
 * word offset from the start of the PKA RAM area. The NYDIGITS field contains
 * number of 32-bit words minus 1 in the N/Y-Operands for MMM, MMMNEXT, MMM3A
 * and MMEXP operations. The length of N is given in 32-bit words, however the
 * words of N are read into the LNME unit in blocks of 64 bits. The address
 * should therefore be even (64 bits boundary). The NYDIGITS field contains
 * the number of 32-bit words minus 1 in the N/Y-Operands for MMM, MMMNEXT,
 * MMM3A and MMEXP operations. The length of N is given in 32-bit words;
 * however the words of N are read into the LNME unit in blocks of 64 bits.
 * The address should therefore be even (64-bit boundary). */
#define CSL_PKA_NBASE                                           (0xA0U)

/* This register is double-buffered, it may be written with new values for the
 * next operation while an operation is being performed. The XBASE field
 * contains the base address of the X-Operand in the PKA RAM. The XDIGITS
 * field contains the number of 32-bit words minus 1 in the X-Operand for MMM,
 * MMMNEXT and MMM3A operations. The length of X is given in 32-bit digits;
 * however the digits of X are read into the LNME unit in blocks of 64 bits.
 * The address should therefore be at an even 64-bit boundary. */
#define CSL_PKA_XBASE                                           (0xA4U)

/* This register is double-buffered, it may be written with new values for the
 * next operation while an operation is being performed. For MMM, MMMNEXT,
 * MMM3A and MMEXP operations the YBASE field contains the base address of the
 * Y-Operand in the PKA RAM. For MMM, MMMNEXT, MMM3A and MMEXP operations the
 * NPASSES field contains the number of passes minus 1 through the PE chain.
 * The length of Y is given in 32 bit words (in the ‘NYDIGITS’ field of the
 * LNME_NBASE register), however the words of Y are read into the LNME unit in
 * blocks of 64 bits. The address should therefore be even (64 bits boundary). */
#define CSL_PKA_YBASE                                           (0xA8U)

/* This register is double-buffered, it may be written with new values for the
 * next operation while an operation is being performed. For MMEXP operations
 * the BBASE field contains the base address of the B-Operand in the PKA RAM .
 * The words of B are read into the LNME unit in blocks of 64 bits. The
 * address should therefore be even (BBASE should lie on a 64 bits boundary).
 * For MMEXP operations the BCNTR field contains the number of bits minus 2 in
 * the B-Operand (only BCNTR + 1 bits need to be stored in memory, the
 * remaining most significant bit is generated in hardware as a constant ‘1’).
 * For MMM3A operations, the BBASE field contains the base address of the
 * result in the PKA RAM. The result words are written into the RAM in blocks
 * of 64 bits. The address should therefore be even (BBASE should lie on a
 * 64-bit boundary). */
#define CSL_PKA_BBASE                                           (0xACU)

/* This register is double-buffered; it may be written with new values for the
 * next operation while an operation is being performed. For MMM, MMMNEXT,
 * MMM3A and MMEXP operations the NACC field contains the 8 least significant
 * bits of N’ in equation R * R^–1 – N * N’ = 1 where LSB NACC is LSB N’.
 * Writing the NZERO field in the PKA_NZERO register automatically performs
 * this calculation in 8 clock cycles. For MMEXP operations the EXPARRAY field
 * contains the number of pre-calculated odd powers minus 1 in the PKA RAM.
 * NOTE: NACC and EXPARRAY share a single register location. If NACC is
 * calculated externally, it can be written together with EXPARRAY into the
 * LNME unit with a single write action. If NACC is to be calculated within
 * the LNME unit, first set EXPARRAY (writing a dummy value to NACC), then
 * write the LNME_NZERO register to start the internal NACC calculation */
#define CSL_PKA_NACC                                            (0xB0U)

/* This register is double-buffered; it may be written with new values for the
 * next operation while an operation is being performed. Writing this
 * register’s NZERO field (with the lowest byte of the N vector) starts a
 * calculation of the correct NACC value, which takes 8 clock cycles (and is
 * indicated by the NACC_BUSY bit in PKA_NACC being set high). During this
 * time, no new operations can be started – writing a command (other than
 * ABORT) to the PKA_CONTROL register does not immediately set the MMMBusy bit
 * in the PKA_STATUS register. The MMMbusy bit will be set high (and the
 * operation started) in the clock cycle after the NACC_BUSY bit has been
 * reset and NACC has been setup. For correct operation, NACC must be odd –
 * this also means that the N vector and written NZERO value must be odd (bit
 * [0] must always be written with a ‘1’). */
#define CSL_PKA_NZERO                                           (0xB4U)

/* This register provides the Host with a means to determine the hardware
 * configuration implemented in this pka4keip29t – focused on options that
 * have an effect on software interacting with the module. */
#define CSL_PKA_OPTIONS                                         (0xF4U)

/* Revision (internal to PKA4KEIP29TP) */
#define CSL_PKA_REVSFT                                          (0xFCU)

/* The PKA revision is a read only register. */
#define CSL_PKA_REVISION                                        (0x1FE0U)

/* Sysconfig registers */
#define CSL_PKA_SYSCONFIG                                       (0x1FF0U)

/* Reset status */
#define CSL_PKA_SYSSTS                                          (0x1FF4U)

/* The PKA_IRQSTATUS is a read only register that returns the interrupt status
 * of the PKA pka4keip29t. */
#define CSL_PKA_IRQSTS                                          (0x1FF8U)

/* The PKA_IRQENABLE is a read write register that enables the reset of the
 * PKA pka4keip29t */
#define CSL_PKA_IRQEN                                           (0x1FFCU)

/* Register PKA_RAM */
#define CSL_PKA_RAM(i)                                          (0x2000U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* STS */

#define CSL_PKA_STS_OVERFLOW_MASK                               (0x00000001U)
#define CSL_PKA_STS_OVERFLOW_SHIFT                              (0U)
#define CSL_PKA_STS_OVERFLOW_RESETVAL                           (0x00000000U)
#define CSL_PKA_STS_OVERFLOW_MAX                                (0x00000001U)

#define CSL_PKA_STS_MMMBUSY_MASK                                (0x00000002U)
#define CSL_PKA_STS_MMMBUSY_SHIFT                               (1U)
#define CSL_PKA_STS_MMMBUSY_RESETVAL                            (0x00000000U)
#define CSL_PKA_STS_MMMBUSY_MAX                                 (0x00000001U)

#define CSL_PKA_STS_CMDERROR_MASK                               (0x00000004U)
#define CSL_PKA_STS_CMDERROR_SHIFT                              (2U)
#define CSL_PKA_STS_CMDERROR_RESETVAL                           (0x00000000U)
#define CSL_PKA_STS_CMDERROR_MAX                                (0x00000001U)

#define CSL_PKA_STS_RESETVAL                                    (0x00000000U)

/* CTRL */

#define CSL_PKA_CTRL_MMMOP_MASK                                 (0x00000003U)
#define CSL_PKA_CTRL_MMMOP_SHIFT                                (0U)
#define CSL_PKA_CTRL_MMMOP_RESETVAL                             (0x00000000U)
#define CSL_PKA_CTRL_MMMOP_NOOP                                 (0x00000000U)
#define CSL_PKA_CTRL_MMMOP_MMM                                  (0x00000001U)
#define CSL_PKA_CTRL_MMMOP_MMMEXT                               (0x00000002U)
#define CSL_PKA_CTRL_MMMOP_MMM3A                                (0x00000003U)

#define CSL_PKA_CTRL_MMEXP_MASK                                 (0x00000004U)
#define CSL_PKA_CTRL_MMEXP_SHIFT                                (2U)
#define CSL_PKA_CTRL_MMEXP_RESETVAL                             (0x00000000U)
#define CSL_PKA_CTRL_MMEXP_NOOP                                 (0x00000000U)
#define CSL_PKA_CTRL_MMEXP_MMEXP                                (0x00000001U)

#define CSL_PKA_CTRL_ABORT_MASK                                 (0x00000020U)
#define CSL_PKA_CTRL_ABORT_SHIFT                                (5U)
#define CSL_PKA_CTRL_ABORT_RESETVAL                             (0x00000000U)
#define CSL_PKA_CTRL_ABORT_NOOP                                 (0x00000000U)
#define CSL_PKA_CTRL_ABORT_ABORT                                (0x00000001U)

#define CSL_PKA_CTRL_RESETVAL                                   (0x00000000U)

/* NBASE */

#define CSL_PKA_NBASE_NBASE_MASK                                (0x000003FFU)
#define CSL_PKA_NBASE_NBASE_SHIFT                               (0U)
#define CSL_PKA_NBASE_NBASE_RESETVAL                            (0x00000000U)
#define CSL_PKA_NBASE_NBASE_MAX                                 (0x000003ffU)

#define CSL_PKA_NBASE_NYDIGITS_MASK                             (0x00FF0000U)
#define CSL_PKA_NBASE_NYDIGITS_SHIFT                            (16U)
#define CSL_PKA_NBASE_NYDIGITS_RESETVAL                         (0x00000000U)
#define CSL_PKA_NBASE_NYDIGITS_MAX                              (0x000000ffU)

#define CSL_PKA_NBASE_RESETVAL                                  (0x00000000U)

/* XBASE */

#define CSL_PKA_XBASE_XBASE_MASK                                (0x000003FFU)
#define CSL_PKA_XBASE_XBASE_SHIFT                               (0U)
#define CSL_PKA_XBASE_XBASE_RESETVAL                            (0x00000000U)
#define CSL_PKA_XBASE_XBASE_MAX                                 (0x000003ffU)

#define CSL_PKA_XBASE_XDIGITS_MASK                              (0x00FF0000U)
#define CSL_PKA_XBASE_XDIGITS_SHIFT                             (16U)
#define CSL_PKA_XBASE_XDIGITS_RESETVAL                          (0x00000000U)
#define CSL_PKA_XBASE_XDIGITS_MAX                               (0x000000ffU)

#define CSL_PKA_XBASE_RESETVAL                                  (0x00000000U)

/* YBASE */

#define CSL_PKA_YBASE_YBASE_MASK                                (0x000003FFU)
#define CSL_PKA_YBASE_YBASE_SHIFT                               (0U)
#define CSL_PKA_YBASE_YBASE_RESETVAL                            (0x00000000U)
#define CSL_PKA_YBASE_YBASE_MAX                                 (0x000003ffU)

#define CSL_PKA_YBASE_NPASSES_MASK                              (0x00FF0000U)
#define CSL_PKA_YBASE_NPASSES_SHIFT                             (16U)
#define CSL_PKA_YBASE_NPASSES_RESETVAL                          (0x00000000U)
#define CSL_PKA_YBASE_NPASSES_MAX                               (0x000000ffU)

#define CSL_PKA_YBASE_RESETVAL                                  (0x00000000U)

/* BBASE */

#define CSL_PKA_BBASE_BBASE_MASK                                (0x000007FFU)
#define CSL_PKA_BBASE_BBASE_SHIFT                               (0U)
#define CSL_PKA_BBASE_BBASE_RESETVAL                            (0x00000000U)
#define CSL_PKA_BBASE_BBASE_MAX                                 (0x000007ffU)

#define CSL_PKA_BBASE_BCNTR_MASK                                (0x1FFF0000U)
#define CSL_PKA_BBASE_BCNTR_SHIFT                               (16U)
#define CSL_PKA_BBASE_BCNTR_RESETVAL                            (0x00000000U)
#define CSL_PKA_BBASE_BCNTR_MAX                                 (0x00001fffU)

#define CSL_PKA_BBASE_RESETVAL                                  (0x00000000U)

/* NACC */

#define CSL_PKA_NACC_NACC_MASK                                  (0x000000FFU)
#define CSL_PKA_NACC_NACC_SHIFT                                 (0U)
#define CSL_PKA_NACC_NACC_RESETVAL                              (0x00000000U)
#define CSL_PKA_NACC_NACC_MAX                                   (0x000000ffU)

#define CSL_PKA_NACC_NACCBUSY_MASK                              (0x00000100U)
#define CSL_PKA_NACC_NACCBUSY_SHIFT                             (8U)
#define CSL_PKA_NACC_NACCBUSY_RESETVAL                          (0x00000000U)
#define CSL_PKA_NACC_NACCBUSY_MAX                               (0x00000001U)

#define CSL_PKA_NACC_EXPARRAY_MASK                              (0x001F0000U)
#define CSL_PKA_NACC_EXPARRAY_SHIFT                             (16U)
#define CSL_PKA_NACC_EXPARRAY_RESETVAL                          (0x00000000U)
#define CSL_PKA_NACC_EXPARRAY_MAX                               (0x0000001fU)

#define CSL_PKA_NACC_RESETVAL                                   (0x00000000U)

/* NZERO */

#define CSL_PKA_NZERO_NZERO_MASK                                (0x000000FFU)
#define CSL_PKA_NZERO_NZERO_SHIFT                               (0U)
#define CSL_PKA_NZERO_NZERO_RESETVAL                            (0x00000000U)
#define CSL_PKA_NZERO_NZERO_MAX                                 (0x000000ffU)

#define CSL_PKA_NZERO_RESETVAL                                  (0x00000000U)

/* OPTIONS */

#define CSL_PKA_OPTIONS_CONF_MASK                               (0x0000001CU)
#define CSL_PKA_OPTIONS_CONF_SHIFT                              (2U)
#define CSL_PKA_OPTIONS_CONF_RESETVAL                           (0x00000001U)
#define CSL_PKA_OPTIONS_CONF_MAX                                (0x00000007U)

#define CSL_PKA_OPTIONS_MMM3A_MASK                              (0x00001000U)
#define CSL_PKA_OPTIONS_MMM3A_SHIFT                             (12U)
#define CSL_PKA_OPTIONS_MMM3A_RESETVAL                          (0x00000001U)
#define CSL_PKA_OPTIONS_MMM3A_MAX                               (0x00000001U)

#define CSL_PKA_OPTIONS_PENUM_MASK                              (0x003F0000U)
#define CSL_PKA_OPTIONS_PENUM_SHIFT                             (16U)
#define CSL_PKA_OPTIONS_PENUM_RESETVAL                          (0x00000006U)
#define CSL_PKA_OPTIONS_PENUM_MAX                               (0x0000003fU)

#define CSL_PKA_OPTIONS_FIFO_MASK                               (0xFF000000U)
#define CSL_PKA_OPTIONS_FIFO_SHIFT                              (24U)
#define CSL_PKA_OPTIONS_FIFO_RESETVAL                           (0x00000086U)
#define CSL_PKA_OPTIONS_FIFO_MAX                                (0x000000ffU)

#define CSL_PKA_OPTIONS_RESETVAL                                (0x86061004U)

/* REVSFT */

#define CSL_PKA_REVSFT_EIPNUM_MASK                              (0x000000FFU)
#define CSL_PKA_REVSFT_EIPNUM_SHIFT                             (0U)
#define CSL_PKA_REVSFT_EIPNUM_RESETVAL                          (0x0000001dU)
#define CSL_PKA_REVSFT_EIPNUM_MAX                               (0x000000ffU)

#define CSL_PKA_REVSFT_EIPNUM1_MASK                             (0x0000FF00U)
#define CSL_PKA_REVSFT_EIPNUM1_SHIFT                            (8U)
#define CSL_PKA_REVSFT_EIPNUM1_RESETVAL                         (0x000000e2U)
#define CSL_PKA_REVSFT_EIPNUM1_MAX                              (0x000000ffU)

#define CSL_PKA_REVSFT_PATCH_MASK                               (0x000F0000U)
#define CSL_PKA_REVSFT_PATCH_SHIFT                              (16U)
#define CSL_PKA_REVSFT_PATCH_RESETVAL                           (0x00000000U)
#define CSL_PKA_REVSFT_PATCH_MAX                                (0x0000000fU)

#define CSL_PKA_REVSFT_REVMIN_MASK                              (0x00F00000U)
#define CSL_PKA_REVSFT_REVMIN_SHIFT                             (20U)
#define CSL_PKA_REVSFT_REVMIN_RESETVAL                          (0x00000000U)
#define CSL_PKA_REVSFT_REVMIN_MAX                               (0x0000000fU)

#define CSL_PKA_REVSFT_REVMAX_MASK                              (0x0F000000U)
#define CSL_PKA_REVSFT_REVMAX_SHIFT                             (24U)
#define CSL_PKA_REVSFT_REVMAX_RESETVAL                          (0x00000002U)
#define CSL_PKA_REVSFT_REVMAX_MAX                               (0x0000000fU)

#define CSL_PKA_REVSFT_RESETVAL                                 (0x0200e21dU)

/* REVISION */

#define CSL_PKA_REVISION_Y_MINOR_MASK                           (0x0000003FU)
#define CSL_PKA_REVISION_Y_MINOR_SHIFT                          (0U)
#define CSL_PKA_REVISION_Y_MINOR_RESETVAL                       (0x00000000U)
#define CSL_PKA_REVISION_Y_MINOR_MAX                            (0x0000003fU)

#define CSL_PKA_REVISION_CUSTOM_MASK                            (0x000000C0U)
#define CSL_PKA_REVISION_CUSTOM_SHIFT                           (6U)
#define CSL_PKA_REVISION_CUSTOM_RESETVAL                        (0x00000000U)
#define CSL_PKA_REVISION_CUSTOM_STANDARD                        (0x00000000U)

#define CSL_PKA_REVISION_X_MAJOR_MASK                           (0x00000700U)
#define CSL_PKA_REVISION_X_MAJOR_SHIFT                          (8U)
#define CSL_PKA_REVISION_X_MAJOR_RESETVAL                       (0x00000000U)
#define CSL_PKA_REVISION_X_MAJOR_MAX                            (0x00000007U)

#define CSL_PKA_REVISION_R_RTL_MASK                             (0x0000F800U)
#define CSL_PKA_REVISION_R_RTL_SHIFT                            (11U)
#define CSL_PKA_REVISION_R_RTL_RESETVAL                         (0x00000000U)
#define CSL_PKA_REVISION_R_RTL_MAX                              (0x0000001fU)

#define CSL_PKA_REVISION_FUNC_MASK                              (0x0FFF0000U)
#define CSL_PKA_REVISION_FUNC_SHIFT                             (16U)
#define CSL_PKA_REVISION_FUNC_RESETVAL                          (0x00000000U)
#define CSL_PKA_REVISION_FUNC_MAX                               (0x00000fffU)

#define CSL_PKA_REVISION_SCHEME_MASK                            (0xC0000000U)
#define CSL_PKA_REVISION_SCHEME_SHIFT                           (30U)
#define CSL_PKA_REVISION_SCHEME_RESETVAL                        (0x00000000U)
#define CSL_PKA_REVISION_SCHEME_H08                             (0x00000001U)
#define CSL_PKA_REVISION_SCHEME_LEGACY                          (0x00000000U)

#define CSL_PKA_REVISION_RESETVAL                               (0x00000000U)

/* SYSCONFIG */

#define CSL_PKA_SYSCONFIG_SOFTRESET_MASK                        (0x00000002U)
#define CSL_PKA_SYSCONFIG_SOFTRESET_SHIFT                       (1U)
#define CSL_PKA_SYSCONFIG_SOFTRESET_RESETVAL                    (0x00000000U)
#define CSL_PKA_SYSCONFIG_SOFTRESET_NOOP                        (0x00000000U)
#define CSL_PKA_SYSCONFIG_SOFTRESET_SOFRESET                    (0x00000001U)

#define CSL_PKA_SYSCONFIG_AUTOIDLE_MASK                         (0x00000001U)
#define CSL_PKA_SYSCONFIG_AUTOIDLE_SHIFT                        (0U)
#define CSL_PKA_SYSCONFIG_AUTOIDLE_RESETVAL                     (0x00000001U)
#define CSL_PKA_SYSCONFIG_AUTOIDLE_CLOCKS_ON                    (0x00000000U)
#define CSL_PKA_SYSCONFIG_AUTOIDLE_CLOCKS_OFF                   (0x00000001U)

#define CSL_PKA_SYSCONFIG_SIDLE_MASK                            (0x00000030U)
#define CSL_PKA_SYSCONFIG_SIDLE_SHIFT                           (4U)
#define CSL_PKA_SYSCONFIG_SIDLE_RESETVAL                        (0x00000000U)
#define CSL_PKA_SYSCONFIG_SIDLE_FORCEIDLE                       (0x00000000U)
#define CSL_PKA_SYSCONFIG_SIDLE_NOIDLE                          (0x00000001U)
#define CSL_PKA_SYSCONFIG_SIDLE_RESERVED1                       (0x00000002U)
#define CSL_PKA_SYSCONFIG_SIDLE_RESERVED                        (0x00000003U)

#define CSL_PKA_SYSCONFIG_RESETVAL                              (0x00000001U)

/* SYSSTS */

#define CSL_PKA_SYSSTS_RESETDONE_MASK                           (0x00000001U)
#define CSL_PKA_SYSSTS_RESETDONE_SHIFT                          (0U)
#define CSL_PKA_SYSSTS_RESETDONE_RESETVAL                       (0x00000001U)
#define CSL_PKA_SYSSTS_RESETDONE_MAX                            (0x00000001U)

#define CSL_PKA_SYSSTS_RESETVAL                                 (0x00000001U)

/* IRQSTS */

#define CSL_PKA_IRQSTS_PKAIRQSTAT_MASK                          (0x00000001U)
#define CSL_PKA_IRQSTS_PKAIRQSTAT_SHIFT                         (0U)
#define CSL_PKA_IRQSTS_PKAIRQSTAT_RESETVAL                      (0x00000001U)
#define CSL_PKA_IRQSTS_PKAIRQSTAT_MAX                           (0x00000001U)

#define CSL_PKA_IRQSTS_RESETVAL                                 (0x00000001U)

/* IRQEN */

#define CSL_PKA_IRQEN_PKAIRQEN_MASK                             (0x00000001U)
#define CSL_PKA_IRQEN_PKAIRQEN_SHIFT                            (0U)
#define CSL_PKA_IRQEN_PKAIRQEN_RESETVAL                         (0x00000000U)
#define CSL_PKA_IRQEN_PKAIRQEN_IRQENABLE                        (0x00000001U)
#define CSL_PKA_IRQEN_PKAIRQEN_NOIRQENABLE                      (0x00000000U)

#define CSL_PKA_IRQEN_RESETVAL                                  (0x00000000U)

/* RAM */

#define CSL_PKA_RAM_DATARAM_MASK                                (0xFFFFFFFFU)
#define CSL_PKA_RAM_DATARAM_SHIFT                               (0U)
#define CSL_PKA_RAM_DATARAM_RESETVAL                            (0x00000000U)
#define CSL_PKA_RAM_DATARAM_MAX                                 (0xffffffffU)

#define CSL_PKA_RAM_RESETVAL                                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
