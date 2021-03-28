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
#ifndef CSLR_IME3_H_
#define CSLR_IME3_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for IME3_ErrTable
**************************************************************************/
typedef struct {
    volatile Uint32 ERRTBLLSB;
    volatile Uint32 ERRTBLMSB;
} CSL_Ime3Ime3_errtableRegs;


/**************************************************************************
* Register Overlay Structure for IME3_BestMatchTable0
**************************************************************************/
typedef struct {
    volatile Uint32 BMTBLLSB0;
    volatile Uint32 BMTBLMSB0;
} CSL_Ime3Ime3_bestmatchtable0Regs;


/**************************************************************************
* Register Overlay Structure for IME3_BestMatchTable1
**************************************************************************/
typedef struct {
    volatile Uint32 BMTBLLSB1;
    volatile Uint32 BMTBLMSB1;
} CSL_Ime3Ime3_bestmatchtable1Regs;


/**************************************************************************
* Register Overlay Structure for IME3_MVCT
**************************************************************************/
typedef struct {
    volatile Uint32 MVCT0_3;
    volatile Uint32 MVCT4_7;
    volatile Uint32 MVCT8_11;
    volatile Uint32 MVCT12_14;
} CSL_Ime3Ime3_mvctRegs;


/**************************************************************************
* Register Overlay Structure for IME3_VecVarHor
**************************************************************************/
typedef struct {
    volatile Uint32 VEC_VAR_HOR_LO;
    volatile Uint32 VEC_VAR_HOR_HI;
} CSL_Ime3Ime3_vecvarhorRegs;


/**************************************************************************
* Register Overlay Structure for IME3_VecVarVer
**************************************************************************/
typedef struct {
    volatile Uint32 VEC_VAR_VER_LO;
    volatile Uint32 VEC_VAR_VER_HI;
} CSL_Ime3Ime3_vecvarverRegs;


/**************************************************************************
* Register Overlay Structure for IME3_VecCycle
**************************************************************************/
typedef struct {
    volatile Uint32 VECABSMEANHOR;
    volatile Uint32 VECABSMEANVER;
    volatile Uint32 CIRCULAR_BUFFER_DESC0;
    volatile Uint32 CIRCULAR_BUFFER_DESC1;
    volatile Uint32 CPUSTSREG;
    volatile Uint32 CYCLECOUNT;
    volatile Uint8  RSVD0[8];
    volatile Uint32 CONDITIONREG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 MINERRORTHR;
    volatile Uint32 CIRCULAR_BUFFER_CURRENT_POSITION0;
    volatile Uint32 CIRCULAR_BUFFER_CURRENT_POSITION1;
} CSL_Ime3Ime3_veccycleRegs;


/**************************************************************************
* Register Overlay Structure for IME3_Valid_Area0
**************************************************************************/
typedef struct {
    volatile Uint32 VALID_AREA0_TOP_LEFT_COORDINATES;
    volatile Uint32 VALID_AREA0_BOTTOM_RIGHT_COORDINATES;
} CSL_Ime3Ime3_valid_area0Regs;


/**************************************************************************
* Register Overlay Structure for IME3_Valid_Area1
**************************************************************************/
typedef struct {
    volatile Uint32 VALID_AREA1_TOP_LEFT_COORDINATES;
    volatile Uint32 VALID_AREA1_BOTTOM_RIGHT_COORDINATES;
} CSL_Ime3Ime3_valid_area1Regs;


/**************************************************************************
* Register Overlay Structure for IME3_CircularBuf
**************************************************************************/
typedef struct {
    volatile Uint32 VECMEANHOR;
    volatile Uint32 VECMEANVER;
    volatile Uint32 INTERPOLATION_REFERENCE;
    volatile Uint32 CIRCULAR_BUFFER_SLIDING_POSITION0;
    volatile Uint32 CIRCULAR_BUFFER_SLIDING_POSITION1;
    volatile Uint8  RSVD0[7040];
    volatile Uint32 COMMANDREG;
    volatile Uint32 PROGRAMBUFFER[2048];
} CSL_Ime3Ime3_circularbufRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD1[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD2[12];
    volatile Uint32 IRQ_EOI;
    volatile Uint32 IRQSTS_RAW;
    volatile Uint32 IRQSTS;
    volatile Uint32 IRQEN_SET;
    volatile Uint32 IRQEN_CLR;
    volatile Uint8  RSVD3[12];
    volatile Uint32 INTERPOL_PARAMETER_STACK[4];
    volatile Uint8  RSVD4[48];
    volatile Uint32 PARAMETERSTACK[32];
    volatile Uint32 CURRENTBLOCK[64];
    CSL_Ime3Ime3_errtableRegs	IME3_ERRTABLE[32];
    CSL_Ime3Ime3_bestmatchtable0Regs	IME3_BESTMATCHTABLE0[16];
    CSL_Ime3Ime3_bestmatchtable1Regs	IME3_BESTMATCHTABLE1[16];
    CSL_Ime3Ime3_mvctRegs	IME3_MVCT;
    CSL_Ime3Ime3_vecvarhorRegs	IME3_VECVARHOR;
    CSL_Ime3Ime3_vecvarverRegs	IME3_VECVARVER;
    CSL_Ime3Ime3_veccycleRegs	IME3_VECCYCLE;
    CSL_Ime3Ime3_valid_area0Regs	IME3_VALID_AREA0;
    CSL_Ime3Ime3_valid_area1Regs	IME3_VALID_AREA1;
    CSL_Ime3Ime3_circularbufRegs	IME3_CIRCULARBUF;
} CSL_Ime3Regs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier (X.Y.R) Used by software to track features, bugs,
 * and compatibility */
#define CSL_IME3_REVISION                                       (0x0U)

/* Clock management configuration */
#define CSL_IME3_SYSCONFIG                                      (0x10U)

/* End Of Interrupt number specification */
#define CSL_IME3_IRQ_EOI                                        (0x20U)

/* Per-event raw interrupt status vector, line #0. Raw status is set even if
 * event is not enabled. Write 1 to set the (raw) status, mostly for debug. */
#define CSL_IME3_IRQSTS_RAW                                     (0x24U)

/* Per-event "enabled" interrupt status vector, line #0. Enabled status isn't
 * set unless event is enabled. Write 1 to clear the status after interrupt
 * has been serviced (raw status gets cleared, i.e. even if not enabled). */
#define CSL_IME3_IRQSTS                                         (0x28U)

/* Per-event interrupt enable bit vector, line #0. Write 1 to set (enable
 * interrupt). Readout equal to corresponding _CLR register. */
#define CSL_IME3_IRQEN_SET                                      (0x2CU)

/* Per-event interrupt enable bit vector, line #0. Write 1 to clear (disable
 * interrupt). Readout equal to corresponding _SET register. */
#define CSL_IME3_IRQEN_CLR                                      (0x30U)

/* Interpolation Filter Pass Configuration */
#define CSL_IME3_INTERPOL_PARAMETER_STACK(i)                    (0x40U + ((i) * (0x4U)))

/* Parameter Stack register 0 to 31 (32-bit wide). Contains parameters used by
 * program to control the iME units. */
#define CSL_IME3_PARAMETERSTACK(i)                              (0x80U + ((i) * (0x4U)))

/* Current Block : 16 lines of 16 bytes containing the Current MacroBlock for
 * SAD computation. */
#define CSL_IME3_CURRENTBLOCK(i)                                (0x100U + ((i) * (0x4U)))

/* Error Table : Register File for SAD computation final errors. Each entry
 * comprises a 16-bit error field, and 2 14-bit coordinate fields (dx and dy). */
#define CSL_IME3_ERRTBLLSB(n)                                   (0x200U + ((n) * (0x8U)))

/* Error Table : Register File for SAD computation final errors. Each entry
 * comprises a 16-bit error field, and 2 14-bit coordinate fields (dx and dy). */
#define CSL_IME3_ERRTBLMSB(n)                                   (0x204U + ((n) * (0x8U)))

/* Best Match Table : register file contain result of Error Table comparisson.
 * BestMatchTable0 is for List0 computation. BestMatchTable1 is for List1
 * computation. Each Best Match Table position correspond to one sub-partition
 * of the 16x16 MB. For 1-MV type computation, best match is stored in entry 0
 * For 16-MV stored computation, each entry correspond to one of the 16 4x4
 * partitions. Otherwise, entries 0 to 8 are used (see corresponding section
 * in IME3 functional spec) */
#define CSL_IME3_BMTBLLSB0(n)                                   (0x300U + ((n) * (0x8U)))

/* Best Match Table : register file contain result of Error Table comparisson.
 * BestMatchTable0 is for List0 computation. BestMatchTable1 is for List1
 * computation. Each Best Match Table position correspond to one sub-partition
 * of the 16x16 MB. For 1-MV type computation, best match is stored in entry 0
 * For 16-MV stored computation, each entry correspond to one of the 16 4x4
 * partitions. Otherwise, entries 0 to 8 are used (see corresponding section
 * in IME3 functional spec) */
#define CSL_IME3_BMTBLMSB0(n)                                   (0x304U + ((n) * (0x8U)))

/* Best Match Table : register file contain result of Error Table comparisson.
 * BestMatchTable0 is for List0 computation. BestMatchTable1 is for List1
 * computation. Each Best Match Table position correspond to one sub-partition
 * of the 16x16 MB. For 1-MV type computation, best match is stored in entry 0
 * For 16-MV stored computation, each entry correspond to one of the 16 4x4
 * partitions. Otherwise, entries 0 to 8 are used (see corresponding section
 * in IME3 functional spec) */
#define CSL_IME3_BMTBLLSB1(n)                                   (0x380U + ((n) * (0x8U)))

/* Best Match Table : register file contain result of Error Table comparisson.
 * BestMatchTable0 is for List0 computation. BestMatchTable1 is for List1
 * computation. Each Best Match Table position correspond to one sub-partition
 * of the 16x16 MB. For 1-MV type computation, best match is stored in entry 0
 * For 16-MV stored computation, each entry correspond to one of the 16 4x4
 * partitions. Otherwise, entries 0 to 8 are used (see corresponding section
 * in IME3 functional spec) */
#define CSL_IME3_BMTBLMSB1(n)                                   (0x384U + ((n) * (0x8U)))

/* MV Cost Table */
#define CSL_IME3_MVCT0_3                                        (0x400U)

/* MV Cost Table */
#define CSL_IME3_MVCT4_7                                        (0x404U)

/* MV Cost Table */
#define CSL_IME3_MVCT8_11                                       (0x408U)

/* MV Cost Table */
#define CSL_IME3_MVCT12_14                                      (0x40CU)

/* VEC_VAR_HOR_LO */
#define CSL_IME3_VEC_VAR_HOR_LO                                 (0x410U)

/* VEC_VAR_HOR_HI */
#define CSL_IME3_VEC_VAR_HOR_HI                                 (0x414U)

/* VEC_VAR_VER_LO */
#define CSL_IME3_VEC_VAR_VER_LO                                 (0x418U)

/* VEC_VAR_VER_HI */
#define CSL_IME3_VEC_VAR_VER_HI                                 (0x41CU)

/* VECABSMEANHOR */
#define CSL_IME3_VECABSMEANHOR                                  (0x420U)

/* VECABSMEANVER */
#define CSL_IME3_VECABSMEANVER                                  (0x424U)

/* CIRCULAR_BUFFER_DESC0 */
#define CSL_IME3_CIRCULAR_BUFFER_DESC0                          (0x428U)

/* CIRCULAR_BUFFER_DESC1 */
#define CSL_IME3_CIRCULAR_BUFFER_DESC1                          (0x42CU)

/* CPU Status Register provides information on the progress of the CPU
 * execution */
#define CSL_IME3_CPUSTSREG                                      (0x430U)

/* CYCLECOUNT */
#define CSL_IME3_CYCLECOUNT                                     (0x434U)

/* Absolute Minimum Reached bit register, used in Mcomp() operator. */
#define CSL_IME3_CONDITIONREG                                   (0x440U)

/* Minimum Error Threshold register, used in Mcomp() operator. */
#define CSL_IME3_MINERRORTHR                                    (0x44CU)

/* CIRCULAR_BUFFER_CURRENT_POSITION0 */
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0              (0x450U)

/* CIRCULAR_BUFFER_CURRENT_POSITION1 */
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1              (0x454U)

/* VALID_AREA0_TOP_LEFT_COORDINATES */
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES               (0x458U)

/* VALID_AREA0_BOTTOM_RIGHT_COORDINATES */
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES           (0x45CU)

/* VALID_AREA1_TOP_LEFT_COORDINATES */
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES               (0x460U)

/* VALID_AREA1_BOTTOM_RIGHT_COORDINATES */
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES           (0x464U)

/* VECMEANHOR */
#define CSL_IME3_VECMEANHOR                                     (0x468U)

/* VECMEANVER */
#define CSL_IME3_VECMEANVER                                     (0x46CU)

/* The Interpol Reference is the MV based on which the last interpolation has
 * been performed. This register is updated by the Interpol APIs, and is later
 * used for computing the MVCost and addresses when manipulating pixels from
 * the interpolated planes. */
#define CSL_IME3_INTERPOLATION_REFERENCE                        (0x470U)

/* CIRCULAR_BUFFER_SLIDING_POSITION0 */
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0              (0x474U)

/* CIRCULAR_BUFFER_SLIDING_POSITION1 */
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1              (0x478U)

/* iME3 command register: a write to this register decodes a command, a read
 * returns 0. 0x1 -> Step() 0x2 -> StopSeq() 0x3 -> DbgEnable() 0x4 ->
 * DbgDisable() */
#define CSL_IME3_COMMANDREG                                     (0x1FFCU)

/* Program Memory 32-bit word */
#define CSL_IME3_PROGRAMBUFFER(i)                               (0x2000U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_IME3_REVISION_Y_MINOR_MASK                          (0x0000003FU)
#define CSL_IME3_REVISION_Y_MINOR_SHIFT                         (0U)
#define CSL_IME3_REVISION_Y_MINOR_RESETVAL                      (0x00000000U)
#define CSL_IME3_REVISION_Y_MINOR_MAX                           (0x0000003fU)

#define CSL_IME3_REVISION_CUSTOM_MASK                           (0x000000C0U)
#define CSL_IME3_REVISION_CUSTOM_SHIFT                          (6U)
#define CSL_IME3_REVISION_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_IME3_REVISION_CUSTOM_STANDARD                       (0x00000000U)

#define CSL_IME3_REVISION_X_MAJOR_MASK                          (0x00000700U)
#define CSL_IME3_REVISION_X_MAJOR_SHIFT                         (8U)
#define CSL_IME3_REVISION_X_MAJOR_RESETVAL                      (0x00000000U)
#define CSL_IME3_REVISION_X_MAJOR_MAX                           (0x00000007U)

#define CSL_IME3_REVISION_R_RTL_MASK                            (0x0000F800U)
#define CSL_IME3_REVISION_R_RTL_SHIFT                           (11U)
#define CSL_IME3_REVISION_R_RTL_RESETVAL                        (0x00000000U)
#define CSL_IME3_REVISION_R_RTL_MAX                             (0x0000001fU)

#define CSL_IME3_REVISION_FUNC_MASK                             (0x0FFF0000U)
#define CSL_IME3_REVISION_FUNC_SHIFT                            (16U)
#define CSL_IME3_REVISION_FUNC_RESETVAL                         (0x00000000U)
#define CSL_IME3_REVISION_FUNC_MAX                              (0x00000fffU)

#define CSL_IME3_REVISION_SCHEME_MASK                           (0xC0000000U)
#define CSL_IME3_REVISION_SCHEME_SHIFT                          (30U)
#define CSL_IME3_REVISION_SCHEME_RESETVAL                       (0x00000001U)
#define CSL_IME3_REVISION_SCHEME_H08                            (0x00000001U)
#define CSL_IME3_REVISION_SCHEME_LEGACY                         (0x00000000U)

#define CSL_IME3_REVISION_RESETVAL                              (0x40000000U)

/* SYSCONFIG */

#define CSL_IME3_SYSCONFIG_SOFTRESET_MASK                       (0x00000001U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_SHIFT                      (0U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_DONE                       (0x00000000U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_PENDING                    (0x00000001U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_NOACTION                   (0x00000000U)
#define CSL_IME3_SYSCONFIG_SOFTRESET_RESET                      (0x00000001U)

#define CSL_IME3_SYSCONFIG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_IME3_SYSCONFIG_IDLEMODE_SHIFT                       (2U)
#define CSL_IME3_SYSCONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_IME3_SYSCONFIG_IDLEMODE_FORCE                       (0x00000000U)
#define CSL_IME3_SYSCONFIG_IDLEMODE_NO                          (0x00000001U)
#define CSL_IME3_SYSCONFIG_IDLEMODE_SMART                       (0x00000002U)
#define CSL_IME3_SYSCONFIG_IDLEMODE_SMARTWAKEUP                 (0x00000003U)

#define CSL_IME3_SYSCONFIG_STANDBYMODE_MASK                     (0x00000030U)
#define CSL_IME3_SYSCONFIG_STANDBYMODE_SHIFT                    (4U)
#define CSL_IME3_SYSCONFIG_STANDBYMODE_RESETVAL                 (0x00000000U)
#define CSL_IME3_SYSCONFIG_STANDBYMODE_FORCE                    (0x00000000U)

#define CSL_IME3_SYSCONFIG_FREEEMU_MASK                         (0x00000002U)
#define CSL_IME3_SYSCONFIG_FREEEMU_SHIFT                        (1U)
#define CSL_IME3_SYSCONFIG_FREEEMU_RESETVAL                     (0x00000001U)
#define CSL_IME3_SYSCONFIG_FREEEMU_INSENSITIVE                  (0x00000001U)

#define CSL_IME3_SYSCONFIG_RESETVAL                             (0x0000000aU)

/* IRQ_EOI */

#define CSL_IME3_IRQ_EOI_RESETVAL                               (0x00000000U)

/* IRQSTS_RAW */

#define CSL_IME3_IRQSTS_RAW_EVT0_MASK                           (0x00000001U)
#define CSL_IME3_IRQSTS_RAW_EVT0_SHIFT                          (0U)
#define CSL_IME3_IRQSTS_RAW_EVT0_RESETVAL                       (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT0_NOACTION                       (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT0_SET                            (0x00000001U)
#define CSL_IME3_IRQSTS_RAW_EVT0_NOEVENT                        (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT0_PENDING                        (0x00000001U)

#define CSL_IME3_IRQSTS_RAW_EVT1_MASK                           (0x00000002U)
#define CSL_IME3_IRQSTS_RAW_EVT1_SHIFT                          (1U)
#define CSL_IME3_IRQSTS_RAW_EVT1_RESETVAL                       (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT1_NOACTION                       (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT1_SET                            (0x00000001U)
#define CSL_IME3_IRQSTS_RAW_EVT1_NOEVENT                        (0x00000000U)
#define CSL_IME3_IRQSTS_RAW_EVT1_PENDING                        (0x00000001U)

#define CSL_IME3_IRQSTS_RAW_RESETVAL                            (0x00000000U)

/* IRQSTS */

#define CSL_IME3_IRQSTS_EVT0_MASK                               (0x00000001U)
#define CSL_IME3_IRQSTS_EVT0_SHIFT                              (0U)
#define CSL_IME3_IRQSTS_EVT0_RESETVAL                           (0x00000000U)
#define CSL_IME3_IRQSTS_EVT0_NOACTION                           (0x00000000U)
#define CSL_IME3_IRQSTS_EVT0_CLEAR                              (0x00000001U)
#define CSL_IME3_IRQSTS_EVT0_NOEVENT                            (0x00000000U)
#define CSL_IME3_IRQSTS_EVT0_PENDING                            (0x00000001U)

#define CSL_IME3_IRQSTS_EVT1_MASK                               (0x00000002U)
#define CSL_IME3_IRQSTS_EVT1_SHIFT                              (1U)
#define CSL_IME3_IRQSTS_EVT1_RESETVAL                           (0x00000000U)
#define CSL_IME3_IRQSTS_EVT1_NOACTION                           (0x00000000U)
#define CSL_IME3_IRQSTS_EVT1_CLEAR                              (0x00000001U)
#define CSL_IME3_IRQSTS_EVT1_NOEVENT                            (0x00000000U)
#define CSL_IME3_IRQSTS_EVT1_PENDING                            (0x00000001U)

#define CSL_IME3_IRQSTS_RESETVAL                                (0x00000000U)

/* IRQEN_SET */

#define CSL_IME3_IRQEN_SET_EN0_MASK                             (0x00000001U)
#define CSL_IME3_IRQEN_SET_EN0_SHIFT                            (0U)
#define CSL_IME3_IRQEN_SET_EN0_RESETVAL                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN0_NOACTION                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN0_ENABLE                           (0x00000001U)
#define CSL_IME3_IRQEN_SET_EN0_DISABLED                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN0_ENABLED                          (0x00000001U)

#define CSL_IME3_IRQEN_SET_EN1_MASK                             (0x00000002U)
#define CSL_IME3_IRQEN_SET_EN1_SHIFT                            (1U)
#define CSL_IME3_IRQEN_SET_EN1_RESETVAL                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN1_NOACTION                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN1_ENABLE                           (0x00000001U)
#define CSL_IME3_IRQEN_SET_EN1_DISABLED                         (0x00000000U)
#define CSL_IME3_IRQEN_SET_EN1_ENABLED                          (0x00000001U)

#define CSL_IME3_IRQEN_SET_RESETVAL                             (0x00000000U)

/* IRQEN_CLR */

#define CSL_IME3_IRQEN_CLR_EN0_MASK                             (0x00000001U)
#define CSL_IME3_IRQEN_CLR_EN0_SHIFT                            (0U)
#define CSL_IME3_IRQEN_CLR_EN0_RESETVAL                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN0_NOACTION                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN0_DISABLE                          (0x00000001U)
#define CSL_IME3_IRQEN_CLR_EN0_DISABLED                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN0_ENABLED                          (0x00000001U)

#define CSL_IME3_IRQEN_CLR_EN1_MASK                             (0x00000002U)
#define CSL_IME3_IRQEN_CLR_EN1_SHIFT                            (1U)
#define CSL_IME3_IRQEN_CLR_EN1_RESETVAL                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN1_NOACTION                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN1_DISABLE                          (0x00000001U)
#define CSL_IME3_IRQEN_CLR_EN1_DISABLED                         (0x00000000U)
#define CSL_IME3_IRQEN_CLR_EN1_ENABLED                          (0x00000001U)

#define CSL_IME3_IRQEN_CLR_RESETVAL                             (0x00000000U)

/* INTERPOL_PARAMETER_STACK */

#define CSL_IME3_INTERPOL_PARAMETER_STACK_SHIFT_MASK            (0x0000001FU)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_SHIFT_SHIFT           (0U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_SHIFT_RESETVAL        (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_SHIFT_MAX             (0x0000001fU)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_MANTISSA_MASK   (0x000007E0U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_MANTISSA_SHIFT  (5U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_MANTISSA_RESETVAL  (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_MANTISSA_MAX    (0x0000003fU)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_EXPONENT_MASK   (0x00003800U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_EXPONENT_SHIFT  (11U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_EXPONENT_RESETVAL  (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_ROUND_EXPONENT_MAX    (0x00000007U)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF2_MASK           (0x000FC000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF2_SHIFT          (14U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF2_RESETVAL       (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF2_MAX            (0x0000003fU)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF1_MASK           (0x03F00000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF1_SHIFT          (20U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF1_RESETVAL       (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF1_MAX            (0x0000003fU)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF0_MASK           (0xFC000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF0_SHIFT          (26U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF0_RESETVAL       (0x00000000U)
#define CSL_IME3_INTERPOL_PARAMETER_STACK_COEFF0_MAX            (0x0000003fU)

#define CSL_IME3_INTERPOL_PARAMETER_STACK_RESETVAL              (0x00000000U)

/* PARAMETERSTACK */

#define CSL_IME3_PARAMETERSTACK_PARAMSTACKN_MASK                (0xFFFFFFFFU)
#define CSL_IME3_PARAMETERSTACK_PARAMSTACKN_SHIFT               (0U)
#define CSL_IME3_PARAMETERSTACK_PARAMSTACKN_RESETVAL            (0x00000000U)
#define CSL_IME3_PARAMETERSTACK_PARAMSTACKN_MAX                 (0xffffffffU)

#define CSL_IME3_PARAMETERSTACK_RESETVAL                        (0x00000000U)

/* CURRENTBLOCK */

#define CSL_IME3_CURRENTBLOCK_CURRENTBLOCKWORD_MASK             (0xFFFFFFFFU)
#define CSL_IME3_CURRENTBLOCK_CURRENTBLOCKWORD_SHIFT            (0U)
#define CSL_IME3_CURRENTBLOCK_CURRENTBLOCKWORD_RESETVAL         (0x00000000U)
#define CSL_IME3_CURRENTBLOCK_CURRENTBLOCKWORD_MAX              (0xffffffffU)

#define CSL_IME3_CURRENTBLOCK_RESETVAL                          (0x00000000U)

/* ERRTBLLSB */

#define CSL_IME3_ERRTBLLSB_DX_MASK                              (0x00003FFFU)
#define CSL_IME3_ERRTBLLSB_DX_SHIFT                             (0U)
#define CSL_IME3_ERRTBLLSB_DX_RESETVAL                          (0x00000000U)
#define CSL_IME3_ERRTBLLSB_DX_MAX                               (0x00003fffU)

#define CSL_IME3_ERRTBLLSB_DY_MASK                              (0x3FFF0000U)
#define CSL_IME3_ERRTBLLSB_DY_SHIFT                             (16U)
#define CSL_IME3_ERRTBLLSB_DY_RESETVAL                          (0x00000000U)
#define CSL_IME3_ERRTBLLSB_DY_MAX                               (0x00003fffU)

#define CSL_IME3_ERRTBLLSB_FRM_FIELDTOP_FIELDBOTTOM_MASK        (0x0000C000U)
#define CSL_IME3_ERRTBLLSB_FRM_FIELDTOP_FIELDBOTTOM_SHIFT       (14U)
#define CSL_IME3_ERRTBLLSB_FRM_FIELDTOP_FIELDBOTTOM_RESETVAL    (0x00000000U)
#define CSL_IME3_ERRTBLLSB_FRM_FIELDTOP_FIELDBOTTOM_MAX         (0x00000003U)

#define CSL_IME3_ERRTBLLSB_RESETVAL                             (0x00000000U)

/* ERRTBLMSB */

#define CSL_IME3_ERRTBLMSB_ERRORVALUE_MASK                      (0x0000FFFFU)
#define CSL_IME3_ERRTBLMSB_ERRORVALUE_SHIFT                     (0U)
#define CSL_IME3_ERRTBLMSB_ERRORVALUE_RESETVAL                  (0x00000000U)
#define CSL_IME3_ERRTBLMSB_ERRORVALUE_MAX                       (0x0000ffffU)

#define CSL_IME3_ERRTBLMSB_MV_COST_MASK                         (0x1FFF0000U)
#define CSL_IME3_ERRTBLMSB_MV_COST_SHIFT                        (16U)
#define CSL_IME3_ERRTBLMSB_MV_COST_RESETVAL                     (0x00000000U)
#define CSL_IME3_ERRTBLMSB_MV_COST_MAX                          (0x00001fffU)

#define CSL_IME3_ERRTBLMSB_RESETVAL                             (0x00000000U)

/* BMTBLLSB0 */

#define CSL_IME3_BMTBLLSB0_DX_MASK                              (0x00003FFFU)
#define CSL_IME3_BMTBLLSB0_DX_SHIFT                             (0U)
#define CSL_IME3_BMTBLLSB0_DX_RESETVAL                          (0x00000000U)
#define CSL_IME3_BMTBLLSB0_DX_MAX                               (0x00003fffU)

#define CSL_IME3_BMTBLLSB0_DY_MASK                              (0x3FFF0000U)
#define CSL_IME3_BMTBLLSB0_DY_SHIFT                             (16U)
#define CSL_IME3_BMTBLLSB0_DY_RESETVAL                          (0x00000000U)
#define CSL_IME3_BMTBLLSB0_DY_MAX                               (0x00003fffU)

#define CSL_IME3_BMTBLLSB0_L0_L1_BI_MASK                        (0xC0000000U)
#define CSL_IME3_BMTBLLSB0_L0_L1_BI_SHIFT                       (30U)
#define CSL_IME3_BMTBLLSB0_L0_L1_BI_RESETVAL                    (0x00000000U)
#define CSL_IME3_BMTBLLSB0_L0_L1_BI_MAX                         (0x00000003U)

#define CSL_IME3_BMTBLLSB0_FRM_FIELDTOP_FIELDBOTTOM_MASK        (0x0000C000U)
#define CSL_IME3_BMTBLLSB0_FRM_FIELDTOP_FIELDBOTTOM_SHIFT       (14U)
#define CSL_IME3_BMTBLLSB0_FRM_FIELDTOP_FIELDBOTTOM_RESETVAL    (0x00000000U)
#define CSL_IME3_BMTBLLSB0_FRM_FIELDTOP_FIELDBOTTOM_MAX         (0x00000003U)

#define CSL_IME3_BMTBLLSB0_RESETVAL                             (0x00000000U)

/* BMTBLMSB0 */

#define CSL_IME3_BMTBLMSB0_ERRORVALUE_MASK                      (0x0000FFFFU)
#define CSL_IME3_BMTBLMSB0_ERRORVALUE_SHIFT                     (0U)
#define CSL_IME3_BMTBLMSB0_ERRORVALUE_RESETVAL                  (0x00000000U)
#define CSL_IME3_BMTBLMSB0_ERRORVALUE_MAX                       (0x0000ffffU)

#define CSL_IME3_BMTBLMSB0_MV_COST_MASK                         (0x1FFF0000U)
#define CSL_IME3_BMTBLMSB0_MV_COST_SHIFT                        (16U)
#define CSL_IME3_BMTBLMSB0_MV_COST_RESETVAL                     (0x00000000U)
#define CSL_IME3_BMTBLMSB0_MV_COST_MAX                          (0x00001fffU)

#define CSL_IME3_BMTBLMSB0_REF_IDX_MASK                         (0xE0000000U)
#define CSL_IME3_BMTBLMSB0_REF_IDX_SHIFT                        (29U)
#define CSL_IME3_BMTBLMSB0_REF_IDX_RESETVAL                     (0x00000000U)
#define CSL_IME3_BMTBLMSB0_REF_IDX_MAX                          (0x00000007U)

#define CSL_IME3_BMTBLMSB0_RESETVAL                             (0x00000000U)

/* BMTBLLSB1 */

#define CSL_IME3_BMTBLLSB1_DX_MASK                              (0x00003FFFU)
#define CSL_IME3_BMTBLLSB1_DX_SHIFT                             (0U)
#define CSL_IME3_BMTBLLSB1_DX_RESETVAL                          (0x00000000U)
#define CSL_IME3_BMTBLLSB1_DX_MAX                               (0x00003fffU)

#define CSL_IME3_BMTBLLSB1_DY_MASK                              (0x3FFF0000U)
#define CSL_IME3_BMTBLLSB1_DY_SHIFT                             (16U)
#define CSL_IME3_BMTBLLSB1_DY_RESETVAL                          (0x00000000U)
#define CSL_IME3_BMTBLLSB1_DY_MAX                               (0x00003fffU)

#define CSL_IME3_BMTBLLSB1_FRM_FIELDTOP_FIELDBOTTOM_MASK        (0x0000C000U)
#define CSL_IME3_BMTBLLSB1_FRM_FIELDTOP_FIELDBOTTOM_SHIFT       (14U)
#define CSL_IME3_BMTBLLSB1_FRM_FIELDTOP_FIELDBOTTOM_RESETVAL    (0x00000000U)
#define CSL_IME3_BMTBLLSB1_FRM_FIELDTOP_FIELDBOTTOM_MAX         (0x00000003U)

#define CSL_IME3_BMTBLLSB1_RESETVAL                             (0x00000000U)

/* BMTBLMSB1 */

#define CSL_IME3_BMTBLMSB1_ERRORVALUE_MASK                      (0x0000FFFFU)
#define CSL_IME3_BMTBLMSB1_ERRORVALUE_SHIFT                     (0U)
#define CSL_IME3_BMTBLMSB1_ERRORVALUE_RESETVAL                  (0x00000000U)
#define CSL_IME3_BMTBLMSB1_ERRORVALUE_MAX                       (0x0000ffffU)

#define CSL_IME3_BMTBLMSB1_MV_COST_MASK                         (0x1FFF0000U)
#define CSL_IME3_BMTBLMSB1_MV_COST_SHIFT                        (16U)
#define CSL_IME3_BMTBLMSB1_MV_COST_RESETVAL                     (0x00000000U)
#define CSL_IME3_BMTBLMSB1_MV_COST_MAX                          (0x00001fffU)

#define CSL_IME3_BMTBLMSB1_REF_IDX_MASK                         (0xE0000000U)
#define CSL_IME3_BMTBLMSB1_REF_IDX_SHIFT                        (29U)
#define CSL_IME3_BMTBLMSB1_REF_IDX_RESETVAL                     (0x00000000U)
#define CSL_IME3_BMTBLMSB1_REF_IDX_MAX                          (0x00000007U)

#define CSL_IME3_BMTBLMSB1_RESETVAL                             (0x00000000U)

/* MVCT0_3 */

#define CSL_IME3_MVCT0_3_MVCT_0_MASK                            (0x0000001FU)
#define CSL_IME3_MVCT0_3_MVCT_0_SHIFT                           (0U)
#define CSL_IME3_MVCT0_3_MVCT_0_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT0_3_MVCT_0_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT0_3_MVCT_1_MASK                            (0x00001F00U)
#define CSL_IME3_MVCT0_3_MVCT_1_SHIFT                           (8U)
#define CSL_IME3_MVCT0_3_MVCT_1_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT0_3_MVCT_1_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT0_3_MVCT_2_MASK                            (0x001F0000U)
#define CSL_IME3_MVCT0_3_MVCT_2_SHIFT                           (16U)
#define CSL_IME3_MVCT0_3_MVCT_2_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT0_3_MVCT_2_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT0_3_MVCT_3_MASK                            (0x1F000000U)
#define CSL_IME3_MVCT0_3_MVCT_3_SHIFT                           (24U)
#define CSL_IME3_MVCT0_3_MVCT_3_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT0_3_MVCT_3_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT0_3_RESETVAL                               (0x00000000U)

/* MVCT4_7 */

#define CSL_IME3_MVCT4_7_MVCT_4_MASK                            (0x0000001FU)
#define CSL_IME3_MVCT4_7_MVCT_4_SHIFT                           (0U)
#define CSL_IME3_MVCT4_7_MVCT_4_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT4_7_MVCT_4_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT4_7_MVCT_5_MASK                            (0x00001F00U)
#define CSL_IME3_MVCT4_7_MVCT_5_SHIFT                           (8U)
#define CSL_IME3_MVCT4_7_MVCT_5_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT4_7_MVCT_5_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT4_7_MVCT_6_MASK                            (0x001F0000U)
#define CSL_IME3_MVCT4_7_MVCT_6_SHIFT                           (16U)
#define CSL_IME3_MVCT4_7_MVCT_6_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT4_7_MVCT_6_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT4_7_MVCT_7_MASK                            (0x1F000000U)
#define CSL_IME3_MVCT4_7_MVCT_7_SHIFT                           (24U)
#define CSL_IME3_MVCT4_7_MVCT_7_RESETVAL                        (0x00000000U)
#define CSL_IME3_MVCT4_7_MVCT_7_MAX                             (0x0000001fU)

#define CSL_IME3_MVCT4_7_RESETVAL                               (0x00000000U)

/* MVCT8_11 */

#define CSL_IME3_MVCT8_11_MVCT_8_MASK                           (0x0000001FU)
#define CSL_IME3_MVCT8_11_MVCT_8_SHIFT                          (0U)
#define CSL_IME3_MVCT8_11_MVCT_8_RESETVAL                       (0x00000000U)
#define CSL_IME3_MVCT8_11_MVCT_8_MAX                            (0x0000001fU)

#define CSL_IME3_MVCT8_11_MVCT_9_MASK                           (0x00001F00U)
#define CSL_IME3_MVCT8_11_MVCT_9_SHIFT                          (8U)
#define CSL_IME3_MVCT8_11_MVCT_9_RESETVAL                       (0x00000000U)
#define CSL_IME3_MVCT8_11_MVCT_9_MAX                            (0x0000001fU)

#define CSL_IME3_MVCT8_11_MVCT_10_MASK                          (0x001F0000U)
#define CSL_IME3_MVCT8_11_MVCT_10_SHIFT                         (16U)
#define CSL_IME3_MVCT8_11_MVCT_10_RESETVAL                      (0x00000000U)
#define CSL_IME3_MVCT8_11_MVCT_10_MAX                           (0x0000001fU)

#define CSL_IME3_MVCT8_11_MVCT_11_MASK                          (0x1F000000U)
#define CSL_IME3_MVCT8_11_MVCT_11_SHIFT                         (24U)
#define CSL_IME3_MVCT8_11_MVCT_11_RESETVAL                      (0x00000000U)
#define CSL_IME3_MVCT8_11_MVCT_11_MAX                           (0x0000001fU)

#define CSL_IME3_MVCT8_11_RESETVAL                              (0x00000000U)

/* MVCT12_14 */

#define CSL_IME3_MVCT12_14_MVCT_12_MASK                         (0x0000001FU)
#define CSL_IME3_MVCT12_14_MVCT_12_SHIFT                        (0U)
#define CSL_IME3_MVCT12_14_MVCT_12_RESETVAL                     (0x00000000U)
#define CSL_IME3_MVCT12_14_MVCT_12_MAX                          (0x0000001fU)

#define CSL_IME3_MVCT12_14_MVCT_13_MASK                         (0x00001F00U)
#define CSL_IME3_MVCT12_14_MVCT_13_SHIFT                        (8U)
#define CSL_IME3_MVCT12_14_MVCT_13_RESETVAL                     (0x00000000U)
#define CSL_IME3_MVCT12_14_MVCT_13_MAX                          (0x0000001fU)

#define CSL_IME3_MVCT12_14_MVCT_14_MASK                         (0x001F0000U)
#define CSL_IME3_MVCT12_14_MVCT_14_SHIFT                        (16U)
#define CSL_IME3_MVCT12_14_MVCT_14_RESETVAL                     (0x00000000U)
#define CSL_IME3_MVCT12_14_MVCT_14_MAX                          (0x0000001fU)

#define CSL_IME3_MVCT12_14_RESETVAL                             (0x00000000U)

/* VEC_VAR_HOR_LO */

#define CSL_IME3_VEC_VAR_HOR_LO_VEC_VAR_LO_MASK                 (0xFFFFFFFFU)
#define CSL_IME3_VEC_VAR_HOR_LO_VEC_VAR_LO_SHIFT                (0U)
#define CSL_IME3_VEC_VAR_HOR_LO_VEC_VAR_LO_RESETVAL             (0x00000000U)
#define CSL_IME3_VEC_VAR_HOR_LO_VEC_VAR_LO_MAX                  (0xffffffffU)

#define CSL_IME3_VEC_VAR_HOR_LO_RESETVAL                        (0x00000000U)

/* VEC_VAR_HOR_HI */

#define CSL_IME3_VEC_VAR_HOR_HI_VEC_VAR_HI_MASK                 (0x0000007FU)
#define CSL_IME3_VEC_VAR_HOR_HI_VEC_VAR_HI_SHIFT                (0U)
#define CSL_IME3_VEC_VAR_HOR_HI_VEC_VAR_HI_RESETVAL             (0x00000000U)
#define CSL_IME3_VEC_VAR_HOR_HI_VEC_VAR_HI_MAX                  (0x0000007fU)

#define CSL_IME3_VEC_VAR_HOR_HI_RESETVAL                        (0x00000000U)

/* VEC_VAR_VER_LO */

#define CSL_IME3_VEC_VAR_VER_LO_VEC_VAR_LO_MASK                 (0xFFFFFFFFU)
#define CSL_IME3_VEC_VAR_VER_LO_VEC_VAR_LO_SHIFT                (0U)
#define CSL_IME3_VEC_VAR_VER_LO_VEC_VAR_LO_RESETVAL             (0x00000000U)
#define CSL_IME3_VEC_VAR_VER_LO_VEC_VAR_LO_MAX                  (0xffffffffU)

#define CSL_IME3_VEC_VAR_VER_LO_RESETVAL                        (0x00000000U)

/* VEC_VAR_VER_HI */

#define CSL_IME3_VEC_VAR_VER_HI_VEC_VAR_HI_MASK                 (0x0000007FU)
#define CSL_IME3_VEC_VAR_VER_HI_VEC_VAR_HI_SHIFT                (0U)
#define CSL_IME3_VEC_VAR_VER_HI_VEC_VAR_HI_RESETVAL             (0x00000000U)
#define CSL_IME3_VEC_VAR_VER_HI_VEC_VAR_HI_MAX                  (0x0000007fU)

#define CSL_IME3_VEC_VAR_VER_HI_RESETVAL                        (0x00000000U)

/* VECABSMEANHOR */

#define CSL_IME3_VECABSMEANHOR_VEC_ABS_MEAN_HOR_MASK            (0x1FFFFFFFU)
#define CSL_IME3_VECABSMEANHOR_VEC_ABS_MEAN_HOR_SHIFT           (0U)
#define CSL_IME3_VECABSMEANHOR_VEC_ABS_MEAN_HOR_RESETVAL        (0x00000000U)
#define CSL_IME3_VECABSMEANHOR_VEC_ABS_MEAN_HOR_MAX             (0x1fffffffU)

#define CSL_IME3_VECABSMEANHOR_RESETVAL                         (0x00000000U)

/* VECABSMEANVER */

#define CSL_IME3_VECABSMEANVER_VEC_ABS_MEAN_VER_MASK            (0x1FFFFFFFU)
#define CSL_IME3_VECABSMEANVER_VEC_ABS_MEAN_VER_SHIFT           (0U)
#define CSL_IME3_VECABSMEANVER_VEC_ABS_MEAN_VER_RESETVAL        (0x00000000U)
#define CSL_IME3_VECABSMEANVER_VEC_ABS_MEAN_VER_MAX             (0x1fffffffU)

#define CSL_IME3_VECABSMEANVER_RESETVAL                         (0x00000000U)

/* CIRCULAR_BUFFER_DESC0 */

#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBH_MASK                 (0x000000FFU)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBH_SHIFT                (0U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBH_RESETVAL             (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBH_MAX                  (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBW_MASK                 (0x0000FF00U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBW_SHIFT                (8U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBW_RESETVAL             (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_CBW_MAX                  (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC0_OFFSET_MASK              (0x00FF0000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_OFFSET_SHIFT             (16U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_OFFSET_RESETVAL          (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_OFFSET_MAX               (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC0_DIRECTION_MASK           (0x01000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_DIRECTION_SHIFT          (24U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_DIRECTION_RESETVAL       (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC0_DIRECTION_MAX            (0x00000001U)

#define CSL_IME3_CIRCULAR_BUFFER_DESC0_RESETVAL                 (0x00000000U)

/* CIRCULAR_BUFFER_DESC1 */

#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBH_MASK                 (0x000000FFU)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBH_SHIFT                (0U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBH_RESETVAL             (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBH_MAX                  (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBW_MASK                 (0x0000FF00U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBW_SHIFT                (8U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBW_RESETVAL             (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_CBW_MAX                  (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC1_OFFSET_MASK              (0x00FF0000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_OFFSET_SHIFT             (16U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_OFFSET_RESETVAL          (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_OFFSET_MAX               (0x000000ffU)

#define CSL_IME3_CIRCULAR_BUFFER_DESC1_DIRECTION_MASK           (0x01000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_DIRECTION_SHIFT          (24U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_DIRECTION_RESETVAL       (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_DESC1_DIRECTION_MAX            (0x00000001U)

#define CSL_IME3_CIRCULAR_BUFFER_DESC1_RESETVAL                 (0x00000000U)

/* CPUSTSREG */

#define CSL_IME3_CPUSTSREG_DETECTEDSTOP_MASK                    (0x20000000U)
#define CSL_IME3_CPUSTSREG_DETECTEDSTOP_SHIFT                   (29U)
#define CSL_IME3_CPUSTSREG_DETECTEDSTOP_RESETVAL                (0x00000000U)
#define CSL_IME3_CPUSTSREG_DETECTEDSTOP_MAX                     (0x00000001U)

#define CSL_IME3_CPUSTSREG_DETECTEDENDOFPGM_MASK                (0x40000000U)
#define CSL_IME3_CPUSTSREG_DETECTEDENDOFPGM_SHIFT               (30U)
#define CSL_IME3_CPUSTSREG_DETECTEDENDOFPGM_RESETVAL            (0x00000000U)
#define CSL_IME3_CPUSTSREG_DETECTEDENDOFPGM_MAX                 (0x00000001U)

#define CSL_IME3_CPUSTSREG_PC_MASK                              (0x0000FFFFU)
#define CSL_IME3_CPUSTSREG_PC_SHIFT                             (0U)
#define CSL_IME3_CPUSTSREG_PC_RESETVAL                          (0x00000000U)
#define CSL_IME3_CPUSTSREG_PC_MAX                               (0x0000ffffU)

#define CSL_IME3_CPUSTSREG_EXECSTATE_MASK                       (0x03000000U)
#define CSL_IME3_CPUSTSREG_EXECSTATE_SHIFT                      (24U)
#define CSL_IME3_CPUSTSREG_EXECSTATE_RESETVAL                   (0x00000000U)
#define CSL_IME3_CPUSTSREG_EXECSTATE_MAX                        (0x00000003U)

#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL0_MASK                (0x00010000U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL0_SHIFT               (16U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL0_RESETVAL            (0x00000000U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL0_MAX                 (0x00000001U)

#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL1_MASK                (0x00040000U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL1_SHIFT               (18U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL1_RESETVAL            (0x00000000U)
#define CSL_IME3_CPUSTSREG_WAITINGONSIGNAL1_MAX                 (0x00000001U)

#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL0_MASK                 (0x00020000U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL0_SHIFT                (17U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL0_RESETVAL             (0x00000000U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL0_MAX                  (0x00000001U)

#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL1_MASK                 (0x00080000U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL1_SHIFT                (19U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL1_RESETVAL             (0x00000000U)
#define CSL_IME3_CPUSTSREG_RECEIVEDSIGNAL1_MAX                  (0x00000001U)

#define CSL_IME3_CPUSTSREG_DBGMODESTS_MASK                      (0x00100000U)
#define CSL_IME3_CPUSTSREG_DBGMODESTS_SHIFT                     (20U)
#define CSL_IME3_CPUSTSREG_DBGMODESTS_RESETVAL                  (0x00000000U)
#define CSL_IME3_CPUSTSREG_DBGMODESTS_MAX                       (0x00000001U)

#define CSL_IME3_CPUSTSREG_START_OR_STEP_TAKEN_MASK             (0x80000000U)
#define CSL_IME3_CPUSTSREG_START_OR_STEP_TAKEN_SHIFT            (31U)
#define CSL_IME3_CPUSTSREG_START_OR_STEP_TAKEN_RESETVAL         (0x00000000U)
#define CSL_IME3_CPUSTSREG_START_OR_STEP_TAKEN_MAX              (0x00000001U)

#define CSL_IME3_CPUSTSREG_REJECTED_OCP_ACCESS_MASK             (0x10000000U)
#define CSL_IME3_CPUSTSREG_REJECTED_OCP_ACCESS_SHIFT            (28U)
#define CSL_IME3_CPUSTSREG_REJECTED_OCP_ACCESS_RESETVAL         (0x00000000U)
#define CSL_IME3_CPUSTSREG_REJECTED_OCP_ACCESS_MAX              (0x00000001U)

#define CSL_IME3_CPUSTSREG_RESETVAL                             (0x00000000U)

/* CYCLECOUNT */

#define CSL_IME3_CYCLECOUNT_CYCLECOUNT_MASK                     (0x0000FFFFU)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNT_SHIFT                    (0U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNT_RESETVAL                 (0x00000000U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNT_MAX                      (0x0000ffffU)

#define CSL_IME3_CYCLECOUNT_CYCLECOUNTRESET_MASK                (0x40000000U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTRESET_SHIFT               (30U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTRESET_RESETVAL            (0x00000000U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTRESET_MAX                 (0x00000001U)

#define CSL_IME3_CYCLECOUNT_CYCLECOUNTEN_MASK                   (0x80000000U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTEN_SHIFT                  (31U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTEN_RESETVAL               (0x00000000U)
#define CSL_IME3_CYCLECOUNT_CYCLECOUNTEN_MAX                    (0x00000001U)

#define CSL_IME3_CYCLECOUNT_RESETVAL                            (0x00000000U)

/* CONDITIONREG */

#define CSL_IME3_CONDITIONREG_ABSMINREACHED_MASK                (0x00000001U)
#define CSL_IME3_CONDITIONREG_ABSMINREACHED_SHIFT               (0U)
#define CSL_IME3_CONDITIONREG_ABSMINREACHED_RESETVAL            (0x00000000U)
#define CSL_IME3_CONDITIONREG_ABSMINREACHED_MAX                 (0x00000001U)

#define CSL_IME3_CONDITIONREG_PARTITIONTYPE_MASK                (0x00000006U)
#define CSL_IME3_CONDITIONREG_PARTITIONTYPE_SHIFT               (1U)
#define CSL_IME3_CONDITIONREG_PARTITIONTYPE_RESETVAL            (0x00000000U)
#define CSL_IME3_CONDITIONREG_PARTITIONTYPE_MAX                 (0x00000003U)

#define CSL_IME3_CONDITIONREG_TOPLEFTREFERENCE_MASK             (0x00000018U)
#define CSL_IME3_CONDITIONREG_TOPLEFTREFERENCE_SHIFT            (3U)
#define CSL_IME3_CONDITIONREG_TOPLEFTREFERENCE_RESETVAL         (0x00000000U)
#define CSL_IME3_CONDITIONREG_TOPLEFTREFERENCE_MAX              (0x00000003U)

#define CSL_IME3_CONDITIONREG_TOPRIGHTREFERENCE_MASK            (0x00000060U)
#define CSL_IME3_CONDITIONREG_TOPRIGHTREFERENCE_SHIFT           (5U)
#define CSL_IME3_CONDITIONREG_TOPRIGHTREFERENCE_RESETVAL        (0x00000000U)
#define CSL_IME3_CONDITIONREG_TOPRIGHTREFERENCE_MAX             (0x00000003U)

#define CSL_IME3_CONDITIONREG_BOTTOMLEFTREFERENCE_MASK          (0x00000180U)
#define CSL_IME3_CONDITIONREG_BOTTOMLEFTREFERENCE_SHIFT         (7U)
#define CSL_IME3_CONDITIONREG_BOTTOMLEFTREFERENCE_RESETVAL      (0x00000000U)
#define CSL_IME3_CONDITIONREG_BOTTOMLEFTREFERENCE_MAX           (0x00000003U)

#define CSL_IME3_CONDITIONREG_BOTTOMRIGHTREFERENCE_MASK         (0x00000600U)
#define CSL_IME3_CONDITIONREG_BOTTOMRIGHTREFERENCE_SHIFT        (9U)
#define CSL_IME3_CONDITIONREG_BOTTOMRIGHTREFERENCE_RESETVAL     (0x00000000U)
#define CSL_IME3_CONDITIONREG_BOTTOMRIGHTREFERENCE_MAX          (0x00000003U)

#define CSL_IME3_CONDITIONREG_PARTITIONVALID_MASK               (0x00000800U)
#define CSL_IME3_CONDITIONREG_PARTITIONVALID_SHIFT              (11U)
#define CSL_IME3_CONDITIONREG_PARTITIONVALID_RESETVAL           (0x00000000U)
#define CSL_IME3_CONDITIONREG_PARTITIONVALID_MAX                (0x00000001U)

#define CSL_IME3_CONDITIONREG_APPLICATIONCTR0_MASK              (0x00FF0000U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR0_SHIFT             (16U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR0_RESETVAL          (0x00000000U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR0_MAX               (0x000000ffU)

#define CSL_IME3_CONDITIONREG_APPLICATIONCTR1_MASK              (0xFF000000U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR1_SHIFT             (24U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR1_RESETVAL          (0x00000000U)
#define CSL_IME3_CONDITIONREG_APPLICATIONCTR1_MAX               (0x000000ffU)

#define CSL_IME3_CONDITIONREG_RESETVAL                          (0x00000000U)

/* MINERRORTHR */

#define CSL_IME3_MINERRORTHR_MINTHR_MASK                        (0x0000FFFFU)
#define CSL_IME3_MINERRORTHR_MINTHR_SHIFT                       (0U)
#define CSL_IME3_MINERRORTHR_MINTHR_RESETVAL                    (0x00000000U)
#define CSL_IME3_MINERRORTHR_MINTHR_MAX                         (0x0000ffffU)

#define CSL_IME3_MINERRORTHR_RESETVAL                           (0x00000000U)

/* CIRCULAR_BUFFER_CURRENT_POSITION0 */

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_X0_MASK      (0x0000FFFCU)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_X0_SHIFT     (2U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_X0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_X0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_Y0_MASK      (0xFFFC0000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_Y0_SHIFT     (18U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_Y0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_Y0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION0_RESETVAL     (0x00000000U)

/* CIRCULAR_BUFFER_CURRENT_POSITION1 */

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_X0_MASK      (0x0000FFFCU)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_X0_SHIFT     (2U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_X0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_X0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_Y0_MASK      (0xFFFC0000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_Y0_SHIFT     (18U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_Y0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_Y0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_CURRENT_POSITION1_RESETVAL     (0x00000000U)

/* VALID_AREA0_TOP_LEFT_COORDINATES */

#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_X_MASK        (0x0000FFFFU)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_X_SHIFT       (0U)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_X_RESETVAL    (0x00000000U)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_X_MAX         (0x0000ffffU)

#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_Y_MASK        (0xFFFF0000U)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_Y_SHIFT       (16U)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_Y_RESETVAL    (0x00000000U)
#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_Y_MAX         (0x0000ffffU)

#define CSL_IME3_VALID_AREA0_TOP_LEFT_COORDINATES_RESETVAL      (0x00000000U)

/* VALID_AREA0_BOTTOM_RIGHT_COORDINATES */

#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_X_MASK    (0x0000FFFFU)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_X_SHIFT   (0U)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_X_RESETVAL  (0x00000000U)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_X_MAX     (0x0000ffffU)

#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_Y_MASK    (0xFFFF0000U)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_Y_SHIFT   (16U)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_Y_RESETVAL  (0x00000000U)
#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_Y_MAX     (0x0000ffffU)

#define CSL_IME3_VALID_AREA0_BOTTOM_RIGHT_COORDINATES_RESETVAL  (0x00000000U)

/* VALID_AREA1_TOP_LEFT_COORDINATES */

#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_X_MASK        (0x0000FFFFU)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_X_SHIFT       (0U)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_X_RESETVAL    (0x00000000U)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_X_MAX         (0x0000ffffU)

#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_Y_MASK        (0xFFFF0000U)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_Y_SHIFT       (16U)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_Y_RESETVAL    (0x00000000U)
#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_Y_MAX         (0x0000ffffU)

#define CSL_IME3_VALID_AREA1_TOP_LEFT_COORDINATES_RESETVAL      (0x00000000U)

/* VALID_AREA1_BOTTOM_RIGHT_COORDINATES */

#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_X_MASK    (0x0000FFFFU)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_X_SHIFT   (0U)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_X_RESETVAL  (0x00000000U)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_X_MAX     (0x0000ffffU)

#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_Y_MASK    (0xFFFF0000U)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_Y_SHIFT   (16U)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_Y_RESETVAL  (0x00000000U)
#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_Y_MAX     (0x0000ffffU)

#define CSL_IME3_VALID_AREA1_BOTTOM_RIGHT_COORDINATES_RESETVAL  (0x00000000U)

/* VECMEANHOR */

#define CSL_IME3_VECMEANHOR_VEC_MEAN_HOR_MASK                   (0x1FFFFFFFU)
#define CSL_IME3_VECMEANHOR_VEC_MEAN_HOR_SHIFT                  (0U)
#define CSL_IME3_VECMEANHOR_VEC_MEAN_HOR_RESETVAL               (0x00000000U)
#define CSL_IME3_VECMEANHOR_VEC_MEAN_HOR_MAX                    (0x1fffffffU)

#define CSL_IME3_VECMEANHOR_RESETVAL                            (0x00000000U)

/* VECMEANVER */

#define CSL_IME3_VECMEANVER_VEC_MEAN_VER_MASK                   (0x1FFFFFFFU)
#define CSL_IME3_VECMEANVER_VEC_MEAN_VER_SHIFT                  (0U)
#define CSL_IME3_VECMEANVER_VEC_MEAN_VER_RESETVAL               (0x00000000U)
#define CSL_IME3_VECMEANVER_VEC_MEAN_VER_MAX                    (0x1fffffffU)

#define CSL_IME3_VECMEANVER_RESETVAL                            (0x00000000U)

/* INTERPOLATION_REFERENCE */

#define CSL_IME3_INTERPOLATION_REFERENCE_X_MASK                 (0x0000FFFFU)
#define CSL_IME3_INTERPOLATION_REFERENCE_X_SHIFT                (0U)
#define CSL_IME3_INTERPOLATION_REFERENCE_X_RESETVAL             (0x00000000U)
#define CSL_IME3_INTERPOLATION_REFERENCE_X_MAX                  (0x0000ffffU)

#define CSL_IME3_INTERPOLATION_REFERENCE_Y_MASK                 (0xFFFF0000U)
#define CSL_IME3_INTERPOLATION_REFERENCE_Y_SHIFT                (16U)
#define CSL_IME3_INTERPOLATION_REFERENCE_Y_RESETVAL             (0x00000000U)
#define CSL_IME3_INTERPOLATION_REFERENCE_Y_MAX                  (0x0000ffffU)

#define CSL_IME3_INTERPOLATION_REFERENCE_RESETVAL               (0x00000000U)

/* CIRCULAR_BUFFER_SLIDING_POSITION0 */

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_X0_MASK      (0x0000FFFCU)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_X0_SHIFT     (2U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_X0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_X0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_Y0_MASK      (0xFFFC0000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_Y0_SHIFT     (18U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_Y0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_Y0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION0_RESETVAL     (0x00000000U)

/* CIRCULAR_BUFFER_SLIDING_POSITION1 */

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_X0_MASK      (0x0000FFFCU)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_X0_SHIFT     (2U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_X0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_X0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_Y0_MASK      (0xFFFC0000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_Y0_SHIFT     (18U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_Y0_RESETVAL  (0x00000000U)
#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_Y0_MAX       (0x00003fffU)

#define CSL_IME3_CIRCULAR_BUFFER_SLIDING_POSITION1_RESETVAL     (0x00000000U)

/* COMMANDREG */

#define CSL_IME3_COMMANDREG_COMMAND_MASK                        (0xFFFFFFFFU)
#define CSL_IME3_COMMANDREG_COMMAND_SHIFT                       (0U)
#define CSL_IME3_COMMANDREG_COMMAND_RESETVAL                    (0x00000000U)
#define CSL_IME3_COMMANDREG_COMMAND_MAX                         (0xffffffffU)

#define CSL_IME3_COMMANDREG_RESETVAL                            (0x00000000U)

/* PROGRAMBUFFER */

#define CSL_IME3_PROGRAMBUFFER_PROGRAM_MEMORY_WORD_MASK         (0xFFFFFFFFU)
#define CSL_IME3_PROGRAMBUFFER_PROGRAM_MEMORY_WORD_SHIFT        (0U)
#define CSL_IME3_PROGRAMBUFFER_PROGRAM_MEMORY_WORD_RESETVAL     (0x00000000U)
#define CSL_IME3_PROGRAMBUFFER_PROGRAM_MEMORY_WORD_MAX          (0xffffffffU)

#define CSL_IME3_PROGRAMBUFFER_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
