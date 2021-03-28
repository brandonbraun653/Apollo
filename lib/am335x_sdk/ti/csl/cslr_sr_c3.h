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
#ifndef CSLR_SRC3_H_
#define CSLR_SRC3_H_

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
    volatile Uint32 SRCONFIG;
    volatile Uint32 SRSTATUS;
    volatile Uint32 SENVAL;
    volatile Uint32 SENMIN;
    volatile Uint32 SENMAX;
    volatile Uint32 SENAVG;
    volatile Uint32 AVGWEIGHT;
    volatile Uint32 NVALUERECIPROCAL;
    volatile Uint32 IRQ_EOI;
    volatile Uint32 IRQSTATUS_RAW;
    volatile Uint32 IRQSTATUS;
    volatile Uint32 IRQENABLE_SET;
    volatile Uint32 IRQENABLE_CLR;
    volatile Uint32 SENERROR;
    volatile Uint32 ERRCONFIG;
    volatile Uint8  RSVD0[4];
    volatile Uint8  RSVD1[4];
    volatile Uint8  RSVD2[4];
    volatile Uint8  RSVD3[4];
    volatile Uint8  RSVD4[4];
} CSL_SrC3Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Configuration bits for the Sensor Core and the Digital Processing */
#define CSL_SRC3_SRCONFIG                                       (0x0U)

/* Status bits that indicate that the values in the register are valid or 
 * events have occurred */
#define CSL_SRC3_SRSTATUS                                       (0x4U)

/* The current sensor values from the Sensor Core(SVT) */
#define CSL_SRC3_SENVAL                                         (0x8U)

/* The minimum sensor values(SVT) */
#define CSL_SRC3_SENMIN                                         (0xCU)

/* The maximum sensor values(SVT) */
#define CSL_SRC3_SENMAX                                         (0x10U)

/* The average sensor values(SVT) */
#define CSL_SRC3_SENAVG                                         (0x14U)

/* The weighting factor in the average computation */
#define CSL_SRC3_AVGWEIGHT                                      (0x18U)

/* The reciprocal of the SenN and SenP values used in error generation(SVT) */
#define CSL_SRC3_NVALUERECIPROCAL                               (0x1CU)

/* EOI protocol re-trigger */
#define CSL_SRC3_IRQ_EOI                                        (0x20U)

/* MCU raw interrupt raw status and set */
#define CSL_SRC3_IRQSTATUS_RAW                                  (0x24U)

/* MCU masked interrupt status and clear */
#define CSL_SRC3_IRQSTATUS                                      (0x28U)

/* MCU interrupt enable flag & set */
#define CSL_SRC3_IRQENABLE_SET                                  (0x2CU)

/* MCU interrupt enable flag & clear */
#define CSL_SRC3_IRQENABLE_CLR                                  (0x30U)

/* The sensor error from the error generator */
#define CSL_SRC3_SENERROR                                       (0x34U)

/* The sensor error configuration */
#define CSL_SRC3_ERRCONFIG                                      (0x38U)

/* The current sensor values from the Sensor Core(LVT) */
#define CSL_SRC3_LVTSENVAL(i)                                   (0x3CU + ((i) * (0x4U)))

/* The minimum sensor values(LVT) */
#define CSL_SRC3_LVTSENMIN(i)                                   (0x40U + ((i) * (0x4U)))

/* The maximum sensor values(LVT) */
#define CSL_SRC3_LVTSENMAX(i)                                   (0x44U + ((i) * (0x4U)))

/* The average sensor values(LVT) */
#define CSL_SRC3_LVTSENAVG(i)                                   (0x48U + ((i) * (0x4U)))

/* The reciprocal of the SenN and SenP values used in error generation(LVT) */
#define CSL_SRC3_LVTNVALUERECIPROCAL(i)                         (0x4CU + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SRCONFIG */

#define CSL_SRC3_SRCONFIG_ACCUMDATA_MASK                        (0xFFC00000U)
#define CSL_SRC3_SRCONFIG_ACCUMDATA_SHIFT                       (22U)
#define CSL_SRC3_SRCONFIG_ACCUMDATA_RESETVAL                    (0x00000080U)
#define CSL_SRC3_SRCONFIG_ACCUMDATA_MAX                         (0x000003ffU)

#define CSL_SRC3_SRCONFIG_SRCLKLENGTH_MASK                      (0x003FF000U)
#define CSL_SRC3_SRCONFIG_SRCLKLENGTH_SHIFT                     (12U)
#define CSL_SRC3_SRCONFIG_SRCLKLENGTH_RESETVAL                  (0x00000200U)
#define CSL_SRC3_SRCONFIG_SRCLKLENGTH_MAX                       (0x000003ffU)

#define CSL_SRC3_SRCONFIG_SRENABLE_MASK                         (0x00000800U)
#define CSL_SRC3_SRCONFIG_SRENABLE_SHIFT                        (11U)
#define CSL_SRC3_SRCONFIG_SRENABLE_RESETVAL                     (0x00000000U)
#define CSL_SRC3_SRCONFIG_SRENABLE_MAX                          (0x00000001U)

#define CSL_SRC3_SRCONFIG_SENENABLE_MASK                        (0x00000400U)
#define CSL_SRC3_SRCONFIG_SENENABLE_SHIFT                       (10U)
#define CSL_SRC3_SRCONFIG_SENENABLE_RESETVAL                    (0x00000001U)
#define CSL_SRC3_SRCONFIG_SENENABLE_MAX                         (0x00000001U)

#define CSL_SRC3_SRCONFIG_ERRORGENERATORENABLE_MASK             (0x00000200U)
#define CSL_SRC3_SRCONFIG_ERRORGENERATORENABLE_SHIFT            (9U)
#define CSL_SRC3_SRCONFIG_ERRORGENERATORENABLE_RESETVAL         (0x00000000U)
#define CSL_SRC3_SRCONFIG_ERRORGENERATORENABLE_MAX              (0x00000001U)

#define CSL_SRC3_SRCONFIG_MINMAXAVGENABLE_MASK                  (0x00000100U)
#define CSL_SRC3_SRCONFIG_MINMAXAVGENABLE_SHIFT                 (8U)
#define CSL_SRC3_SRCONFIG_MINMAXAVGENABLE_RESETVAL              (0x00000000U)
#define CSL_SRC3_SRCONFIG_MINMAXAVGENABLE_MAX                   (0x00000001U)

#define CSL_SRC3_SRCONFIG_LVTSENENABLE_MASK                     (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENENABLE_SHIFT                    (4U)
#define CSL_SRC3_SRCONFIG_LVTSENENABLE_RESETVAL                 (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENENABLE_MAX                      (0x00000000U)

#define CSL_SRC3_SRCONFIG_LVTSENNENABLE_MASK                    (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENNENABLE_SHIFT                   (3U)
#define CSL_SRC3_SRCONFIG_LVTSENNENABLE_RESETVAL                (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENNENABLE_MAX                     (0x00000000U)

#define CSL_SRC3_SRCONFIG_LVTSENPENABLE_MASK                    (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENPENABLE_SHIFT                   (2U)
#define CSL_SRC3_SRCONFIG_LVTSENPENABLE_RESETVAL                (0x00000000U)
#define CSL_SRC3_SRCONFIG_LVTSENPENABLE_MAX                     (0x00000000U)

#define CSL_SRC3_SRCONFIG_SENNENABLE_MASK                       (0x00000002U)
#define CSL_SRC3_SRCONFIG_SENNENABLE_SHIFT                      (1U)
#define CSL_SRC3_SRCONFIG_SENNENABLE_RESETVAL                   (0x00000001U)
#define CSL_SRC3_SRCONFIG_SENNENABLE_MAX                        (0x00000001U)

#define CSL_SRC3_SRCONFIG_SENPENABLE_MASK                       (0x00000001U)
#define CSL_SRC3_SRCONFIG_SENPENABLE_SHIFT                      (0U)
#define CSL_SRC3_SRCONFIG_SENPENABLE_RESETVAL                   (0x00000000U)
#define CSL_SRC3_SRCONFIG_SENPENABLE_MAX                        (0x00000001U)

#define CSL_SRC3_SRCONFIG_RESETVAL                              (0x20200402U)

/* SRSTATUS */

#define CSL_SRC3_SRSTATUS_MINMAXAVGACCUMVALID_MASK              (0x00000001U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGACCUMVALID_SHIFT             (0U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGACCUMVALID_RESETVAL          (0x00000000U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGACCUMVALID_MAX               (0x00000001U)

#define CSL_SRC3_SRSTATUS_ERRORGENERATORVALID_MASK              (0x00000002U)
#define CSL_SRC3_SRSTATUS_ERRORGENERATORVALID_SHIFT             (1U)
#define CSL_SRC3_SRSTATUS_ERRORGENERATORVALID_RESETVAL          (0x00000000U)
#define CSL_SRC3_SRSTATUS_ERRORGENERATORVALID_MAX               (0x00000001U)

#define CSL_SRC3_SRSTATUS_MINMAXAVGVALID_MASK                   (0x00000004U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGVALID_SHIFT                  (2U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGVALID_RESETVAL               (0x00000000U)
#define CSL_SRC3_SRSTATUS_MINMAXAVGVALID_MAX                    (0x00000001U)

#define CSL_SRC3_SRSTATUS_AVGERRVALID_MASK                      (0x00000008U)
#define CSL_SRC3_SRSTATUS_AVGERRVALID_SHIFT                     (3U)
#define CSL_SRC3_SRSTATUS_AVGERRVALID_RESETVAL                  (0x00000000U)
#define CSL_SRC3_SRSTATUS_AVGERRVALID_MAX                       (0x00000001U)

#define CSL_SRC3_SRSTATUS_RESETVAL                              (0x00000000U)

/* SENVAL */

#define CSL_SRC3_SENVAL_SENNVAL_MASK                            (0x0000FFFFU)
#define CSL_SRC3_SENVAL_SENNVAL_SHIFT                           (0U)
#define CSL_SRC3_SENVAL_SENNVAL_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENVAL_SENNVAL_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENVAL_SENPVAL_MASK                            (0xFFFF0000U)
#define CSL_SRC3_SENVAL_SENPVAL_SHIFT                           (16U)
#define CSL_SRC3_SENVAL_SENPVAL_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENVAL_SENPVAL_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENVAL_RESETVAL                                (0x00000000U)

/* SENMIN */

#define CSL_SRC3_SENMIN_SENNMIN_MASK                            (0x0000FFFFU)
#define CSL_SRC3_SENMIN_SENNMIN_SHIFT                           (0U)
#define CSL_SRC3_SENMIN_SENNMIN_RESETVAL                        (0x0000ffffU)
#define CSL_SRC3_SENMIN_SENNMIN_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENMIN_SENPMIN_MASK                            (0xFFFF0000U)
#define CSL_SRC3_SENMIN_SENPMIN_SHIFT                           (16U)
#define CSL_SRC3_SENMIN_SENPMIN_RESETVAL                        (0x0000ffffU)
#define CSL_SRC3_SENMIN_SENPMIN_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENMIN_RESETVAL                                (0xffffffffU)

/* SENMAX */

#define CSL_SRC3_SENMAX_SENNMAX_MASK                            (0x0000FFFFU)
#define CSL_SRC3_SENMAX_SENNMAX_SHIFT                           (0U)
#define CSL_SRC3_SENMAX_SENNMAX_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENMAX_SENNMAX_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENMAX_SENPMAX_MASK                            (0xFFFF0000U)
#define CSL_SRC3_SENMAX_SENPMAX_SHIFT                           (16U)
#define CSL_SRC3_SENMAX_SENPMAX_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENMAX_SENPMAX_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENMAX_RESETVAL                                (0x00000000U)

/* SENAVG */

#define CSL_SRC3_SENAVG_SENNAVG_MASK                            (0x0000FFFFU)
#define CSL_SRC3_SENAVG_SENNAVG_SHIFT                           (0U)
#define CSL_SRC3_SENAVG_SENNAVG_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENAVG_SENNAVG_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENAVG_SENPAVG_MASK                            (0xFFFF0000U)
#define CSL_SRC3_SENAVG_SENPAVG_SHIFT                           (16U)
#define CSL_SRC3_SENAVG_SENPAVG_RESETVAL                        (0x00000000U)
#define CSL_SRC3_SENAVG_SENPAVG_MAX                             (0x0000ffffU)

#define CSL_SRC3_SENAVG_RESETVAL                                (0x00000000U)

/* AVGWEIGHT */

#define CSL_SRC3_AVGWEIGHT_SENNAVGWEIGHT_MASK                   (0x0000FFFFU)
#define CSL_SRC3_AVGWEIGHT_SENNAVGWEIGHT_SHIFT                  (0U)
#define CSL_SRC3_AVGWEIGHT_SENNAVGWEIGHT_RESETVAL               (0x00000000U)
#define CSL_SRC3_AVGWEIGHT_SENNAVGWEIGHT_MAX                    (0x0000ffffU)

#define CSL_SRC3_AVGWEIGHT_SENPAVGWEIGHT1_MASK                  (0xFFFF0000U)
#define CSL_SRC3_AVGWEIGHT_SENPAVGWEIGHT1_SHIFT                 (16U)
#define CSL_SRC3_AVGWEIGHT_SENPAVGWEIGHT1_RESETVAL              (0x00000000U)
#define CSL_SRC3_AVGWEIGHT_SENPAVGWEIGHT1_MAX                   (0x0000ffffU)

#define CSL_SRC3_AVGWEIGHT_RESETVAL                             (0x00000000U)

/* NVALUERECIPROCAL */

#define CSL_SRC3_NVALUERECIPROCAL_SENNRN_MASK                   (0x000000FFU)
#define CSL_SRC3_NVALUERECIPROCAL_SENNRN_SHIFT                  (0U)
#define CSL_SRC3_NVALUERECIPROCAL_SENNRN_RESETVAL               (0x00000000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENNRN_MAX                    (0x000000ffU)

#define CSL_SRC3_NVALUERECIPROCAL_SENPRN_MASK                   (0x0000FF00U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPRN_SHIFT                  (8U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPRN_RESETVAL               (0x00000000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPRN_MAX                    (0x000000ffU)

#define CSL_SRC3_NVALUERECIPROCAL_SENNGAIN_MASK                 (0x000F0000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENNGAIN_SHIFT                (16U)
#define CSL_SRC3_NVALUERECIPROCAL_SENNGAIN_RESETVAL             (0x00000000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENNGAIN_MAX                  (0x0000000fU)

#define CSL_SRC3_NVALUERECIPROCAL_SENPGAIN_MASK                 (0x00F00000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPGAIN_SHIFT                (20U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPGAIN_RESETVAL             (0x00000000U)
#define CSL_SRC3_NVALUERECIPROCAL_SENPGAIN_MAX                  (0x0000000fU)

#define CSL_SRC3_NVALUERECIPROCAL_RESETVAL                      (0x00000000U)

/* IRQ_EOI */

#define CSL_SRC3_IRQ_EOI_EOI_MASK                               (0x00000001U)
#define CSL_SRC3_IRQ_EOI_EOI_SHIFT                              (0U)
#define CSL_SRC3_IRQ_EOI_EOI_RESETVAL                           (0x00000000U)
#define CSL_SRC3_IRQ_EOI_EOI_MAX                                (0x00000001U)

#define CSL_SRC3_IRQ_EOI_RESETVAL                               (0x00000000U)

/* IRQSTATUS_RAW */

#define CSL_SRC3_IRQSTATUS_RAW_MCUDISABLEACKINTSTATRAW_MASK     (0x00000001U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUDISABLEACKINTSTATRAW_SHIFT    (0U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUDISABLEACKINTSTATRAW_RESETVAL  (0x00000000U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUDISABLEACKINTSTATRAW_MAX      (0x00000001U)

#define CSL_SRC3_IRQSTATUS_RAW_MCUVALIDINTSTATRAW_MASK          (0x00000004U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUVALIDINTSTATRAW_SHIFT         (2U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUVALIDINTSTATRAW_RESETVAL      (0x00000000U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUVALIDINTSTATRAW_MAX           (0x00000001U)

#define CSL_SRC3_IRQSTATUS_RAW_MCUBOUNDSINTSTATRAW_MASK         (0x00000002U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUBOUNDSINTSTATRAW_SHIFT        (1U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUBOUNDSINTSTATRAW_RESETVAL     (0x00000000U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUBOUNDSINTSTATRAW_MAX          (0x00000001U)

#define CSL_SRC3_IRQSTATUS_RAW_MCUACCUMINTSTATRAW_MASK          (0x00000008U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUACCUMINTSTATRAW_SHIFT         (3U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUACCUMINTSTATRAW_RESETVAL      (0x00000000U)
#define CSL_SRC3_IRQSTATUS_RAW_MCUACCUMINTSTATRAW_MAX           (0x00000001U)

#define CSL_SRC3_IRQSTATUS_RAW_RESETVAL                         (0x00000000U)

/* IRQSTATUS */

#define CSL_SRC3_IRQSTATUS_MCUDISABLEACKINTSTATENA_MASK         (0x00000001U)
#define CSL_SRC3_IRQSTATUS_MCUDISABLEACKINTSTATENA_SHIFT        (0U)
#define CSL_SRC3_IRQSTATUS_MCUDISABLEACKINTSTATENA_RESETVAL     (0x00000000U)
#define CSL_SRC3_IRQSTATUS_MCUDISABLEACKINTSTATENA_MAX          (0x00000001U)

#define CSL_SRC3_IRQSTATUS_MCUBOUNDSINTSTATENA_MASK             (0x00000002U)
#define CSL_SRC3_IRQSTATUS_MCUBOUNDSINTSTATENA_SHIFT            (1U)
#define CSL_SRC3_IRQSTATUS_MCUBOUNDSINTSTATENA_RESETVAL         (0x00000000U)
#define CSL_SRC3_IRQSTATUS_MCUBOUNDSINTSTATENA_MAX              (0x00000001U)

#define CSL_SRC3_IRQSTATUS_MCUVALIDINTSTATENA_MASK              (0x00000004U)
#define CSL_SRC3_IRQSTATUS_MCUVALIDINTSTATENA_SHIFT             (2U)
#define CSL_SRC3_IRQSTATUS_MCUVALIDINTSTATENA_RESETVAL          (0x00000000U)
#define CSL_SRC3_IRQSTATUS_MCUVALIDINTSTATENA_MAX               (0x00000001U)

#define CSL_SRC3_IRQSTATUS_MCUACCUMINTSTATENA_MASK              (0x00000008U)
#define CSL_SRC3_IRQSTATUS_MCUACCUMINTSTATENA_SHIFT             (3U)
#define CSL_SRC3_IRQSTATUS_MCUACCUMINTSTATENA_RESETVAL          (0x00000000U)
#define CSL_SRC3_IRQSTATUS_MCUACCUMINTSTATENA_MAX               (0x00000001U)

#define CSL_SRC3_IRQSTATUS_RESETVAL                             (0x00000000U)

/* IRQENABLE_SET */

#define CSL_SRC3_IRQENABLE_SET_MCUDISABLEACKINTENASET_MASK      (0x00000001U)
#define CSL_SRC3_IRQENABLE_SET_MCUDISABLEACKINTENASET_SHIFT     (0U)
#define CSL_SRC3_IRQENABLE_SET_MCUDISABLEACKINTENASET_RESETVAL  (0x00000000U)
#define CSL_SRC3_IRQENABLE_SET_MCUDISABLEACKINTENASET_MAX       (0x00000001U)

#define CSL_SRC3_IRQENABLE_SET_MCUBOUNDSINTENASET_MASK          (0x00000002U)
#define CSL_SRC3_IRQENABLE_SET_MCUBOUNDSINTENASET_SHIFT         (1U)
#define CSL_SRC3_IRQENABLE_SET_MCUBOUNDSINTENASET_RESETVAL      (0x00000000U)
#define CSL_SRC3_IRQENABLE_SET_MCUBOUNDSINTENASET_MAX           (0x00000001U)

#define CSL_SRC3_IRQENABLE_SET_MCUVALIDINTENASET_MASK           (0x00000004U)
#define CSL_SRC3_IRQENABLE_SET_MCUVALIDINTENASET_SHIFT          (2U)
#define CSL_SRC3_IRQENABLE_SET_MCUVALIDINTENASET_RESETVAL       (0x00000000U)
#define CSL_SRC3_IRQENABLE_SET_MCUVALIDINTENASET_MAX            (0x00000001U)

#define CSL_SRC3_IRQENABLE_SET_MCUACCUMINTENASET_MASK           (0x00000008U)
#define CSL_SRC3_IRQENABLE_SET_MCUACCUMINTENASET_SHIFT          (3U)
#define CSL_SRC3_IRQENABLE_SET_MCUACCUMINTENASET_RESETVAL       (0x00000000U)
#define CSL_SRC3_IRQENABLE_SET_MCUACCUMINTENASET_MAX            (0x00000001U)

#define CSL_SRC3_IRQENABLE_SET_RESETVAL                         (0x00000000U)

/* IRQENABLE_CLR */

#define CSL_SRC3_IRQENABLE_CLR_MCUDISABLEACKINTENACLR_MASK      (0x00000001U)
#define CSL_SRC3_IRQENABLE_CLR_MCUDISABLEACKINTENACLR_SHIFT     (0U)
#define CSL_SRC3_IRQENABLE_CLR_MCUDISABLEACKINTENACLR_RESETVAL  (0x00000000U)
#define CSL_SRC3_IRQENABLE_CLR_MCUDISABLEACKINTENACLR_MAX       (0x00000001U)

#define CSL_SRC3_IRQENABLE_CLR_MCUBOUNDSINTENACLR_MASK          (0x00000002U)
#define CSL_SRC3_IRQENABLE_CLR_MCUBOUNDSINTENACLR_SHIFT         (1U)
#define CSL_SRC3_IRQENABLE_CLR_MCUBOUNDSINTENACLR_RESETVAL      (0x00000000U)
#define CSL_SRC3_IRQENABLE_CLR_MCUBOUNDSINTENACLR_MAX           (0x00000001U)

#define CSL_SRC3_IRQENABLE_CLR_MCUVALIDINTENACLR_MASK           (0x00000004U)
#define CSL_SRC3_IRQENABLE_CLR_MCUVALIDINTENACLR_SHIFT          (2U)
#define CSL_SRC3_IRQENABLE_CLR_MCUVALIDINTENACLR_RESETVAL       (0x00000000U)
#define CSL_SRC3_IRQENABLE_CLR_MCUVALIDINTENACLR_MAX            (0x00000001U)

#define CSL_SRC3_IRQENABLE_CLR_MCUACCUMINTENACLR_MASK           (0x00000008U)
#define CSL_SRC3_IRQENABLE_CLR_MCUACCUMINTENACLR_SHIFT          (3U)
#define CSL_SRC3_IRQENABLE_CLR_MCUACCUMINTENACLR_RESETVAL       (0x00000000U)
#define CSL_SRC3_IRQENABLE_CLR_MCUACCUMINTENACLR_MAX            (0x00000001U)

#define CSL_SRC3_IRQENABLE_CLR_RESETVAL                         (0x00000000U)

/* SENERROR */

#define CSL_SRC3_SENERROR_SENERROR_MASK                         (0x000000FFU)
#define CSL_SRC3_SENERROR_SENERROR_SHIFT                        (0U)
#define CSL_SRC3_SENERROR_SENERROR_RESETVAL                     (0x00000000U)
#define CSL_SRC3_SENERROR_SENERROR_MAX                          (0x000000ffU)

#define CSL_SRC3_SENERROR_AVGERROR_MASK                         (0x0000FF00U)
#define CSL_SRC3_SENERROR_AVGERROR_SHIFT                        (8U)
#define CSL_SRC3_SENERROR_AVGERROR_RESETVAL                     (0x00000000U)
#define CSL_SRC3_SENERROR_AVGERROR_MAX                          (0x000000ffU)

#define CSL_SRC3_SENERROR_RESETVAL                              (0x00000000U)

/* ERRCONFIG */

#define CSL_SRC3_ERRCONFIG_ERRMINLIMIT_MASK                     (0x000000FFU)
#define CSL_SRC3_ERRCONFIG_ERRMINLIMIT_SHIFT                    (0U)
#define CSL_SRC3_ERRCONFIG_ERRMINLIMIT_RESETVAL                 (0x00000080U)
#define CSL_SRC3_ERRCONFIG_ERRMINLIMIT_MAX                      (0x000000ffU)

#define CSL_SRC3_ERRCONFIG_ERRWEIGHT_MASK                       (0x00070000U)
#define CSL_SRC3_ERRCONFIG_ERRWEIGHT_SHIFT                      (16U)
#define CSL_SRC3_ERRCONFIG_ERRWEIGHT_RESETVAL                   (0x00000000U)
#define CSL_SRC3_ERRCONFIG_ERRWEIGHT_MAX                        (0x00000007U)

#define CSL_SRC3_ERRCONFIG_ERRMAXLIMIT_MASK                     (0x0000FF00U)
#define CSL_SRC3_ERRCONFIG_ERRMAXLIMIT_SHIFT                    (8U)
#define CSL_SRC3_ERRCONFIG_ERRMAXLIMIT_RESETVAL                 (0x0000007fU)
#define CSL_SRC3_ERRCONFIG_ERRMAXLIMIT_MAX                      (0x000000ffU)

#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTENABLE_MASK               (0x00400000U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTENABLE_SHIFT              (22U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTENABLE_RESETVAL           (0x00000000U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTENABLE_MAX                (0x00000001U)

#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTSTATENA_MASK              (0x00800000U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTSTATENA_SHIFT             (23U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTSTATENA_RESETVAL          (0x00000000U)
#define CSL_SRC3_ERRCONFIG_VPBOUNDSINTSTATENA_MAX               (0x00000001U)

#define CSL_SRC3_ERRCONFIG_IDLEMODE_MASK                        (0x03000000U)
#define CSL_SRC3_ERRCONFIG_IDLEMODE_SHIFT                       (24U)
#define CSL_SRC3_ERRCONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_SRC3_ERRCONFIG_IDLEMODE_MAX                         (0x00000003U)

#define CSL_SRC3_ERRCONFIG_WAKEUPENABLE_MASK                    (0x04000000U)
#define CSL_SRC3_ERRCONFIG_WAKEUPENABLE_SHIFT                   (26U)
#define CSL_SRC3_ERRCONFIG_WAKEUPENABLE_RESETVAL                (0x00000000U)
#define CSL_SRC3_ERRCONFIG_WAKEUPENABLE_MAX                     (0x00000001U)

#define CSL_SRC3_ERRCONFIG_RESETVAL                             (0x02007f80U)

/* LVTSENVAL */

#define CSL_SRC3_LVTSENVAL_LVSENNVAL_MASK                       (0x0000FFFFU)
#define CSL_SRC3_LVTSENVAL_LVSENNVAL_SHIFT                      (0U)
#define CSL_SRC3_LVTSENVAL_LVSENNVAL_RESETVAL                   (0x00000000U)
#define CSL_SRC3_LVTSENVAL_LVSENNVAL_MAX                        (0x0000ffffU)

#define CSL_SRC3_LVTSENVAL_LVSENPVAL_MASK                       (0xFFFF0000U)
#define CSL_SRC3_LVTSENVAL_LVSENPVAL_SHIFT                      (16U)
#define CSL_SRC3_LVTSENVAL_LVSENPVAL_RESETVAL                   (0x00000000U)
#define CSL_SRC3_LVTSENVAL_LVSENPVAL_MAX                        (0x0000ffffU)

#define CSL_SRC3_LVTSENVAL_RESETVAL                             (0x00000000U)

/* LVTSENMIN */

#define CSL_SRC3_LVTSENMIN_LVTSENNMIN_MASK                      (0x0000FFFFU)
#define CSL_SRC3_LVTSENMIN_LVTSENNMIN_SHIFT                     (0U)
#define CSL_SRC3_LVTSENMIN_LVTSENNMIN_RESETVAL                  (0x0000ffffU)
#define CSL_SRC3_LVTSENMIN_LVTSENNMIN_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENMIN_LVTSENPMIN_MASK                      (0xFFFF0000U)
#define CSL_SRC3_LVTSENMIN_LVTSENPMIN_SHIFT                     (16U)
#define CSL_SRC3_LVTSENMIN_LVTSENPMIN_RESETVAL                  (0x0000ffffU)
#define CSL_SRC3_LVTSENMIN_LVTSENPMIN_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENMIN_RESETVAL                             (0xffffffffU)

/* LVTSENMAX */

#define CSL_SRC3_LVTSENMAX_LVTSENNMAX_MASK                      (0x0000FFFFU)
#define CSL_SRC3_LVTSENMAX_LVTSENNMAX_SHIFT                     (0U)
#define CSL_SRC3_LVTSENMAX_LVTSENNMAX_RESETVAL                  (0x00000000U)
#define CSL_SRC3_LVTSENMAX_LVTSENNMAX_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENMAX_LVTSENPMAX_MASK                      (0xFFFF0000U)
#define CSL_SRC3_LVTSENMAX_LVTSENPMAX_SHIFT                     (16U)
#define CSL_SRC3_LVTSENMAX_LVTSENPMAX_RESETVAL                  (0x00000000U)
#define CSL_SRC3_LVTSENMAX_LVTSENPMAX_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENMAX_RESETVAL                             (0x00000000U)

/* LVTSENAVG */

#define CSL_SRC3_LVTSENAVG_LVTSENNAVG_MASK                      (0x0000FFFFU)
#define CSL_SRC3_LVTSENAVG_LVTSENNAVG_SHIFT                     (0U)
#define CSL_SRC3_LVTSENAVG_LVTSENNAVG_RESETVAL                  (0x00000000U)
#define CSL_SRC3_LVTSENAVG_LVTSENNAVG_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENAVG_LVTSENPAVG_MASK                      (0xFFFF0000U)
#define CSL_SRC3_LVTSENAVG_LVTSENPAVG_SHIFT                     (16U)
#define CSL_SRC3_LVTSENAVG_LVTSENPAVG_RESETVAL                  (0x00000000U)
#define CSL_SRC3_LVTSENAVG_LVTSENPAVG_MAX                       (0x0000ffffU)

#define CSL_SRC3_LVTSENAVG_RESETVAL                             (0x00000000U)

/* LVTNVALUERECIPROCAL */

#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNRN_MASK             (0x000000FFU)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNRN_SHIFT            (0U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNRN_RESETVAL         (0x00000000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNRN_MAX              (0x000000ffU)

#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPRN_MASK             (0x0000FF00U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPRN_SHIFT            (8U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPRN_RESETVAL         (0x00000000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPRN_MAX              (0x000000ffU)

#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNGAIN_MASK           (0x000F0000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNGAIN_SHIFT          (16U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNGAIN_RESETVAL       (0x00000000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENNGAIN_MAX            (0x0000000fU)

#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPGAIN_MASK           (0x00F00000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPGAIN_SHIFT          (20U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPGAIN_RESETVAL       (0x00000000U)
#define CSL_SRC3_LVTNVALUERECIPROCAL_LVTSENPGAIN_MAX            (0x0000000fU)

#define CSL_SRC3_LVTNVALUERECIPROCAL_RESETVAL                   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
