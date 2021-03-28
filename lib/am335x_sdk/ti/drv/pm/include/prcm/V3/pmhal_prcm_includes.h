/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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

/**
 *  \file      pmhal_prcm_includes.h
 *
 *  \brief     This file contains header files to be used by StarterWare PRCM
 *             (internal) implementation.
 */

#ifndef PMHAL_PRCM_INCLUDES_H_
#define PMHAL_PRCM_INCLUDES_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

/* All SOC files */
#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/starterware/include/hw/hw_control_am335x.h>
#include <ti/starterware/include/am335x/hw_prm_device.h>
#include <ti/starterware/include/am335x/hw_prm_cefuse.h>
#include <ti/starterware/include/am335x/hw_prm_gfx.h>
#include <ti/starterware/include/am335x/hw_prm_mpu.h>
#include <ti/starterware/include/am335x/hw_prm_rtc.h>
#include <ti/starterware/include/am335x/hw_prm_wkup.h>
#include <ti/starterware/include/am335x/hw_prm_per.h>
#include <ti/starterware/include/am335x/hw_prm_ocp_socket.h>
#include <ti/starterware/include/am335x/hw_cm_per.h>
#include <ti/starterware/include/am335x/hw_cm_wkup.h>
#include <ti/starterware/include/am335x/hw_cm_mpu.h>
#include <ti/starterware/include/am335x/hw_cm_rtc.h>
#include <ti/starterware/include/am335x/hw_cm_gfx.h>
#include <ti/starterware/include/am335x/hw_cm_cefuse.h>
#include <ti/starterware/include/am335x/hw_cm_dpll.h>
#include <ti/starterware/include/am335x/hw_cm_device.h>

/* IP files */
#include <ti/starterware/include/hw/hw_gpmc.h>
#include <ti/starterware/include/hw/hw_elm.h>
#include <ti/starterware/include/hw/hw_edma_tpcc.h>
#include <ti/starterware/include/hw/hw_edma3tc.h>
#include <ti/starterware/include/hw/hw_tsc_adc_ss.h>
#include <ti/starterware/include/hw/hw_lcdc.h>
#include <ti/starterware/include/hw/hw_pwmss.h>
#include <ti/starterware/include/hw/hw_usbss.h>
#include <ti/starterware/include/hw/hw_mailbox.h>
#include <ti/starterware/include/hw/hw_spinlock.h>
#include <ti/starterware/include/hw/hw_hs_mmcsd.h>
#include <ti/starterware/include/hw/hw_rtc.h>
#include <ti/starterware/include/hw/hw_mcasp.h>
#include <ti/starterware/include/hw/hw_mcspi.h>
#include <ti/starterware/include/hw/hw_gpio.h>
#include <ti/starterware/include/hw/hw_i2c.h>
#include <ti/starterware/include/hw/hw_uart.h>

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* None */

#endif /* PMHAL_PRCM_INCLUDES_H_ */
