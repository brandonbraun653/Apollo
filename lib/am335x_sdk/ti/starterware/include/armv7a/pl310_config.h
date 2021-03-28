/**
 *  \file   pl310_config.h
 *
 *  \brief  This file contains the configurations for pl310 cache. These are 
 *          one-time configurations for which API's are not provided. Any 
 *          change needed to these configurations has to be modified in this 
 *          file.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/*
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

#ifndef PL310_CONFIG_H_
#define PL310_CONFIG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_pl310.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** PL310 Cache line size */
#define PL310_LINE_SIZE                       (32U)
/** PL310 Lock way bit value */
#define PL310_LOCK_WAY(WAY)                   (1U << WAY)
/** PL310 cache memory size */
#define PL310_AM43XX_L2_CACHE_SIZE            (256U * MEM_SIZE_KB)

/** TAG RAM Read Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_TAG_RAM_READ_LAT_VAL            (0x0U)
/** TAG RAM Write Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_TAG_RAM_WRITE_LAT_VAL           (0x0U)
/** TAG RAM Setup Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_TAG_RAM_SETUP_LAT_VAL           (0x0U)

/** DATA RAM Read Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_DATA_RAM_READ_LAT_VAL           (0x1U)
/** DATA RAM Write Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_DATA_RAM_WRITE_LAT_VAL          (0x1U)
/** DATA RAM Setup Latency. 0x0- 1 cycle, 0x1- 2 cycles. */
#define PL310_DATA_RAM_SETUP_LAT_VAL          (0x0U)


/** The macro indicates whether software can reconfigure the default
    filter settings. */
#define PL310_ADDR_FILTERING_EN               (0x0U)
/** PL310 Address filtering start address */
#define PL310_ADDR_FILTERING_START_ADDR       (0x0U)
/** PL310 Address filtering end address */
#define PL310_ADDR_FILTERING_END_ADDR         (0x0U)

/** Pre-fetch configurations. From the spec bit[27] = 0 and bit[23] = 0, gives 
    burst length of 8x64-bit in all cases. */
#define PL310_PREFETCH_CONFIG                                                 \
    (                                                                         \
        (                                                                     \
                        (PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_EN_MASK)     | \
                        (PL310_PREFETCH_OFFSET_INSTR_EN_MASK)               | \
                        (PL310_PREFETCH_OFFSET_DATA_EN_MASK)                | \
                        (PL310_PREFETCH_OFFSET_DROP_EN_MASK)                  \
        )                                                                   & \
        ~(                                                                    \
          (PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_ON_WRAP_READ_DISABLE_MASK) | \
          (PL310_PREFETCH_OFFSET_INCR_DOUBLE_LINEFILL_EN_MASK)              | \
          (PL310_PREFETCH_OFFSET_NOT_SAME_ID_ON_EXCLUSIVE_SEQUENCE_EN_MASK) | \
          (PL310_PREFETCH_OFFSET_VALUE_MASK)                                  \
        )                                                                     \
    )

/** Auxiliary control configurations */
#define PL310_AUX_CTRL_VAL                                                    \
    (                                                                         \
        ((                                                                    \
            PL310_AUX_CTRL_INSTR_PREFETCH_EN_MASK                  | \
            PL310_AUX_CTRL_DATA_PREFETCH_EN_MASK                  | \
            PL310_AUX_CTRL_NS_INTR_ACCESS_MASK    | \
            PL310_AUX_CTRL_NS_LOCKDOWN_EN_MASK             | \
            PL310_AUX_CTRL_SHARED_ATTR_OVERRIDE_EN_MASK      | \
            PL310_AUX_CTRL_ASSOCIATIVITY_MASK                         | \
            PL310_AUX_CTRL_SHARED_BUFFER_DEVICE_LIMITATION_EN_MASK      \
        )                                                                   & \
        (                                                                     \
               ((~PL310_AUX_CTRL_WAY_SIZE_MASK)                       | \
               (1 << PL310_AUX_CTRL_WAY_SIZE_SHIFT))                    \
        ))                                                                  & \
        ~(                                                                    \
            PL310_AUX_CTRL_EARLY_BRESP_EN_MASK                    | \
            PL310_AUX_CTRL_FORCE_WRITE_ALLOCATE_MASK                  | \
            PL310_AUX_CTRL_PARITY_EN_MASK                         | \
            PL310_AUX_CTRL_EVT_MONITOR_BUS_EN_MASK              | \
            PL310_AUX_CTRL_CACHE_REPLACEMENT_POLICY_MASK              | \
            PL310_AUX_CTRL_EXCLUSIVE_CACHE_CONFIG_MASK         | \
            PL310_AUX_CTRL_STORE_BUFFER_DEVICE_LIMITATION_EN_MASK     | \
            PL310_AUX_CTRL_HIGH_PRIORITY_SO_AND_DEV_READS_EN_MASK     | \
            PL310_AUX_CTRL_FULL_LINE_OF_ZERO_EN_MASK                \
        )                                                                     \
    )                                                                         \

/** Power control configurations. */
#define PL310_POWER_CTRL_CONFIG                                               \
                    (PL310_POWER_CTRL_DYNAMIC_CLK_GATING_EN_MASK &            \
                                ~PL310_POWER_CTRL_STANDBY_MODE_EN_MASK)       \

/** Interrupt clear mask */
#define PL310_INTR_CLR_MASK                                                   \
       (PL310_INTR_CLR_ECNTR_MASK | PL310_INTR_CLR_PARRT_MASK               | \
        PL310_INTR_CLR_PARRD_MASK | PL310_INTR_CLR_ERRWT_MASK               | \
        PL310_INTR_CLR_ERRWD_MASK | PL310_INTR_CLR_ERRRT_MASK               | \
        PL310_INTR_CLR_ERRRD_MASK | PL310_INTR_CLR_SLVERR_MASK              | \
        PL310_INTR_CLR_DECERR_MASK)

/** Interrupt mask */
#define PL310_INTR_MASK_CONFIG                                                \
       (PL310_INTR_MASK_ECNTR_MASK  | PL310_INTR_MASK_PARRT_MASK            | \
        PL310_INTR_MASK_PARRD_MASK  | PL310_INTR_MASK_ERRWT_MASK            | \
        PL310_INTR_MASK_ERRWD_MASK  | PL310_INTR_MASK_ERRRT_MASK            | \
        PL310_INTR_MASK_ERRRD_MASK  | PL310_INTR_MASK_SLVERR_MASK           | \
        PL310_INTR_MASK_DECERR_MASK)


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* PL310_CONFIG_H_ */

