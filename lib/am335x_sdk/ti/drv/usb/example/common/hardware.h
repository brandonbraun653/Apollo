/**
 * \copyright  Copyright (C) 2016-2019 Texas Instruments Incorporated -
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
 */

#ifndef __USB_HARDWARE_H__
#define  __USB_HARDWARE_H__


#if defined (evmAM437x)
#define SYS_INT_USB0                    200
#define SYS_INT_USB1                    206
#endif

#if (defined (evmAM335x)|| defined (bbbAM335x))
#define SYS_INT_USBSSINT                17
#define SYS_INT_USB0                    18
#define SYS_INT_USB1                    19
#endif

#if (defined(idkAM572x) || defined(idkAM571x) ||  \
     defined(evmAM572x) || defined(evmAM571x) ||  \
     defined(idkAM574x) || defined(SOC_DRA72x) || \
     defined(SOC_DRA75x))
#if defined(ARM_M4_BUILD)
#define SYS_INT_USB0                    72
#define SYS_INT_USB1                    74
#else /* A15 Build */
#define SYS_INT_USB0                    108
#define SYS_INT_USB1                    110
#endif /* ARM_M4_BUILD */
#endif /* Board/SOC defined */

#if defined (evmK2G)
#define SYS_INT_USB0                    (128 + 32)
#define SYS_INT_USB1                    (144 + 32)
#endif

#if (defined(evmOMAPL137) || defined(lcdkOMAPL138) || \
     defined(lcdkC6748))
#if defined (__TI_ARM_V5__)
#define SYS_INT_USB0					(58)
#else
#define SYS_INT_USB0					(19)
#endif
#endif
#endif


#if (defined (SOC_AM65XX) || defined(SOC_AM65xx))
#include <ti/csl/soc.h>
#if defined(BUILD_MPU)
#define SYS_INT_USB0    (CSL_GIC0_INTR_USB3SS0_BUS_I00_LVL) /* 132 */
#define SYS_INT_USB1    (CSL_GIC0_INTR_USB3SS1_BUS_I00_LVL) /* 152 */
#elif defined(BUILD_MCU)
/* R5(MCU) uses interrupt router.
   This is the output number from the MAIN2MCU LVL interrupt router. We pick 
   pick arbitrarily CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_20 as this router output. 
   system integrator can pick any other interrupt that fits their systems */
#define SYS_INT_USB0    (CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_20)  /* 180 */
#define SYS_INT_USB1    (CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_20)  /* 180 */

#else
#warn "unknown build for AM65xx"
#endif
#endif

#if (defined (SOC_J721E))
#include <ti/csl/soc.h>
#if defined(BUILD_MPU)
#define SYS_INT_USB0        (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_USB0_IRQ_6) /* 134 - device controller IRQ*/
#define SYS_INT_USB0_HOST   (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_USB0_IRQ_0) /* 128 - host controller IRQ */

#define SYS_INT_USB1        (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_USB1_IRQ_6) /* 142 - device controller IRQ */
#define SYS_INT_USB1_HOST   (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_USB1_IRQ_0) /* 136 - host controller IRQ */


#elif defined(BUILD_MCU)

/* R5(MCU) uses interrupt router.
   This is the output number from the MAIN2MCU LVL interrupt router. We pick 
   pick arbitrarily CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 
   as this router output. 
   system integrator can pick any other interrupt that fits their systems */

#define SYS_INT_USB0    (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0)  /* 160 */
#define SYS_INT_USB1    (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0)  /* 160 */

#define SYS_INT_USB0_HOST (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_1)  /* 161 */
#define SYS_INT_USB1_HOST (CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_1)  /* 161 */

#else
#warn "unknown / unsupported build for J7"
#endif


#define SYS_INT_USB0_ASF_FATAL      (CSLR_ESM0_ESM_LVL_EVENT_USB0_ASF_INT_FATAL_0)
#define SYS_INT_USB1_ASF_FATAL      (CSLR_ESM0_ESM_LVL_EVENT_USB1_ASF_INT_FATAL_0)

#define SYS_INT_USB0_ASF_NON_FATAL  (CSLR_ESM0_ESM_LVL_EVENT_USB0_ASF_INT_NON_FATAL_0)
#define SYS_INT_USB1_ASF_NON_FATAL  (CSLR_ESM0_ESM_LVL_EVENT_USB1_ASF_INT_NON_FATAL_0)

#endif

