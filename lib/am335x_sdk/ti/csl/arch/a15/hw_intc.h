/*
 *  Copyright (c) Texas Instruments Incorporated 2013
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
 *  \file  hw_intc.h
 *
 *  \brief This file contains the MACROS definitions used by interrupt
 *         controller module.
 */

#ifndef HW_INTC_H_
#define HW_INTC_H_

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C"
{
#endif

/************/

#define INTC_MPU_CPU_IF_IAR_OFFSET (0x000CU)
#define INTC_MPU_CPU_IF_EOI_OFFSET (0x0010U)

#define IAR_INT_ID_MASK (0x000000FF)
#define PPI_SGI_MASK    (0x20)

#define ADDR_IAR        (SOC_INTC_MPU_PHYS_CPU_IF_BASE + \
                         INTC_MPU_CPU_IF_IAR_OFFSET)
#define ADDR_EOI        (SOC_INTC_MPU_PHYS_CPU_IF_BASE + \
                         INTC_MPU_CPU_IF_EOI_OFFSET)

#define MASK_SVC_NUM    (0xFF000000)
#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
}
#endif

#endif
