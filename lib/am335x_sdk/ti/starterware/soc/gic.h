/**
 *  \file   gic.h
 *
 *  \brief  GIC related declarations. This file contains enumerations, 
 *          structure and the API prototypes for configuring 
 *          Generic Interrupt Controller (GIC).
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/**
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

#ifndef GIC_H_
#define GIC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "misc.h"
#include "gic_a9_mpcore_config.h"
#include "hw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*  Maximum number of interrupts supported by GIC */
#define GIC_MAX_INTR_NO         (1024U)

/*  Maximum number of CPU supported by GIC */
#define GIC_MAX_CPU_NO          (8U)

/*  Trigger type for interrupts */
#define GIC_LEVEL_SENSITIVE     (1U)
#define GIC_EDGE_SENSITIVE      (3U)

/*  CPU bit mask in a multi processor system */
#define GIC_CPU0                (0x1U)
#define GIC_CPU1                (0x2U)
#define GIC_CPU2                (0x4U)
#define GIC_CPU3                (0x8U)
#define GIC_CPU4                (0x10U)
#define GIC_CPU5                (0x20U)
#define GIC_CPU6                (0x40U)
#define GIC_CPU7                (0x80U)

/* Interrupt type - secure mode only */
#define GIC_SECURE_INT          (1U)
#define GIC_NON_SECURE_INT      (2U)
#define GIC_SEC_NS_INT          (3U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** Binary point value for priority grouping. */
typedef enum
{
    BPVAL0 = 0U,
    BPVAL1 = 1U,
    BPVAL2 = 2U,
    BPVAL3 = 3U,
    BPVAL4 = 4U,
    BPVAL5 = 5U,
    BPVAL6 = 6U,
    BPVAL7 = 7U
} binPointVal_t;

/** Interrupt support cases. */
typedef enum
{
    GIC_INTR_NOT_SUPP            = 0U,
    GIC_INTR_SUPP                = 1U,
    GIC_INTR_SUPP_ENABLED_ALWAYS = 2U
} intrSupport_t;

/** GIC secure configurations. */
typedef struct
{
    /** Secure binary point for secure priority group configuration. */
    binPointVal_t secureBinaryPoint;

    /** Use the Secure Binary Point Register for preempting NS interrupts. */
    uint32_t isSecBpForNonSec;

    /** Secure interrupt to be signalled to - FIQ or IRQ. */
    uint32_t coreIntSel;

    /** Acknowledge NS interrupt from secure mode. */
    uint32_t ackNonSecIntr;

    /** Enable/disable NS interrupts in secure mode. Secure intr will be enabled
       by default. To disable secure intr call API GicGlobalIntrDisable. */
    uint32_t enableNonSecurIntr;

} tGicSecConfig;

/** GIC user configurations. */
typedef struct
{
    /** Pointer to distributor sub-module base address. */
    void *distBasePtr;

    /** Pointer to CPU Interface sub-module base address. */
    void *cpuIntfBasePtr;

#if SMP_ENABLED
    /** Memorymap offset per CPU. */
    uint32_t perCpuOffset;
#endif

    /** NS binary point for NS priority group configuration. */
    binPointVal_t nonSecureBinaryPoint;

} tGicConfig;

/** GIC Data Structure. */
typedef struct
{
    /** Maximum number of interrupts supported. */
    uint32_t maxValidIntr;

    /** Number of CPU interfaces implemented in GIC. */
    uint32_t noCpuIntf;

    /** Number of priority levels implemented. */
    uint32_t noPriorityStep;

    /** User configurable parameters. */
    tGicConfig gicConfig;

    /** Is secure extn supported by the GIC. */
    uint32_t isSecExtnSupp;

    /** Maximum number of implemented lockable SPIs (secure mode only). */
    uint32_t maxLockableSpi;

    /** Parameters to define the secure configurations of an interrupt. */
    tGicSecConfig secureConfig;

#ifdef CONFIG_GIC_PM
    /** Variables to store GIC register context. */
    uint32_t spiEnable[DIV_CEIL(GIC_MAX_INTR_NO, 32)];
    uint32_t spiConf[DIV_CEIL(GIC_MAX_INTR_NO, 16)];
    uint32_t spiTarget[DIV_CEIL(GIC_MAX_INTR_NO, 4)];
    uint32_t ppiEnable[GIC_NO_CPU_INTF_USED][16];
    uint32_t ppiConf[GIC_NO_CPU_INTF_USED][16];
#endif

} gicData_t;

#ifdef __cplusplus
}
#endif

#endif

