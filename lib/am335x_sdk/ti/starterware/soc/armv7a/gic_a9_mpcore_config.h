/**
 *  \file   gic_config.h
 *
 *  \brief  GIC Configurations. The GIC architecture leaves certain paramters 
 *          to be implementation defined. Such parameters are defined here, 
 *          so that when the same driver is used in a different system the 
 *          configurations can be modified in this file.
 *
 *          For "A9 MPCore" 
 *               SGI             -   (0-15) 
 *               PPI Reserved    -   (16-26) 
 *               PPI Read-Only   -   (27-31) 
 *               SPI             -   (32-255)
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

#ifndef GIC_CONFIG_H_
#define GIC_CONFIG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_types.h"
/* TODO: Remove soc specific header file inclusion and use chipdb API to get 
   required info. */
#include "am437x.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* Device specific macros */
/* TODO: Use chipdb API's and remove these macros. */
#define SOC_GIC_CPU_INTF_BASE               (SOC_MPU_SCU_REG + 0x0100)
#define SOC_GIC_DIST_BASE                   (SOC_MPU_SCU_REG + 0x1000)

/*  These macros provide the address with byte alignment */
#define GIC_DIST_PRIORITY_REG_B(REG)        (0x0400 + REG)
#define GIC_DIST_PROC_TARGET_REG_B(REG)     (0x0800 + REG)


/*  GIC Implementation defined parameters   */

/*  CPU ID of this CPU */
#define GIC_CPU_ID                          (0)

/*  Number of GIC instances implemented in the device */
#define GIC_INSTANCE_USED                   (0)

/*  Number of CPU interfaces used */
#define GIC_NO_CPU_INTF_USED                (1)

/*  Enable PM support routines */
#define GIC_CONFIG_GIC_PM                   (1)    

/* 
    Configure the priority mask to lowest value, so that all the priorities 
    can be used. Based on the application need this can be modified 
    apprioriately.
*/
#define GIC_CPU_INTF_MIN_PRI                (0xff)

/*  Enable SMP support in the GIC */
#define SMP_ENABLED                         (0)

/*  PPI trigger type configurable */
#define GIC_PPI_TRIG_WRITABLE               (0)

/* Follow as configured in target list filter */
#define GIC_SGI_TARGET_LIST                 (0U)

/** Send interrupt only if the target interrupt (security) configuration 
    matches with this configuration. */
#define GIC_SGI_SATT_SECURE                 (0U)
#define GIC_SGI_SATT_NON_SECURE             (1U)

/* ========================================================================== */
/*                                Inline Functions                            */
/* ========================================================================== */

/* API's to get SoC specific information. */

static inline uint32_t GicInstGet()
{
    return GIC_INSTANCE_USED;
}

static inline uint32_t isPpiTriggerConfigurable()
{
    return GIC_PPI_TRIG_WRITABLE;
}

static inline uint32_t *GicDistBaseGet()
{
    return (uint32_t *)SOC_GIC_DIST_BASE;
}

static inline uint32_t *GicCpuIntfBaseGet()
{
    return (uint32_t *)SOC_GIC_CPU_INTF_BASE;
}

/*
    This API abstracts configuration of GIC. Users can modify the 
    configuration according to their need.
*/
static inline uint32_t GicNsBinaryPointGet()
{
    return 0;
}


#ifdef __cplusplus
}
#endif

#endif
