/******************************************************************************
 * Copyright (c) 2016-2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/


/**  
 * @file pcie_test.h
 *
 * @brief 
 *  Holds all the constants and API definitions required by the example
 *  application to run.  
 */

#ifndef _PCIE_TEST_H_
#define _PCIE_TEST_H_

/* C Standard library include */
#include <string.h>

/* CSL include */
#include <ti/csl/cslr_device.h>

/* PCIE LLD include */
#include <ti/drv/pcie/pcie.h>
#include <ti/drv/uart/UART_stdio.h>
/* Do gen2 on all devices -- remove or -U for GEN1 */


#define Console_printf printf
#define Console_scanf scanf


#ifndef IO_CONSOLE
#include <ti/drv/uart/UART_stdio.h>
#define PCIE_logPrintf  UART_printf
#define PCIE_logScanf   UART_scanFmt
#else
#define PCIE_logPrintf  Console_printf
#define PCIE_logScanf   Console_scanf
#endif


/* Size of application buffers */
#define PCIE_BUFSIZE_APP 40 

/* Number of each type of interrupt to send */
#define PCIE_NUM_INTS   10

/* Write pattern */
#define PCIE_WR_PATTERN 0xFACEFACE

/* In this example all addresses are 32bit */
/* Outbound Base Address for PCIe RC */
#define PCIE_OB_LO_ADDR_RC   0x70000000
#define PCIE_OB_HI_ADDR_RC   0

/* Inbound  Base Address for PCIe RC */
#define PCIE_IB_LO_ADDR_RC   0x90000000
#define PCIE_IB_HI_ADDR_RC   0

/* Outbound Base Address for PCIe EP */
#define PCIE_OB_LO_ADDR_EP   PCIE_IB_LO_ADDR_RC
#define PCIE_OB_HI_ADDR_EP   0

/* Inbound  Base Address for PCIe EP */
#define PCIE_IB_LO_ADDR_EP   PCIE_OB_LO_ADDR_RC
#define PCIE_IB_HI_ADDR_EP   0

/* Data area offset relative to PCIe base (only used rev 1) */
#define PCIE_WINDOW_MEM_BASE 0x01000000U
#define PCIE_WINDOW_MEM_MASK 0x00FFFFFFU

/* Cfg area offset relative to PCIe base (only used rev 1) */
/* This MUST agree Pciev1_DeviceCfgBaseAddrs.bases! */
#define PCIE_WINDOW_CFG_BASE 0x00001000U
#define PCIE_WINDOW_CFG_MASK 0x00000FFFU

/* MSI address in PCIE data window */
#define PCIE_WINDOW_MSI_ADDR 0x02000000U
#define PCIE_WINDOW_MSI_DATA 0x00000000U

/* Inbound limit (only used rev 1) */
#define PCIE_INBOUND_MASK    0x0FFFFFFFU

/* BAR mask */
#define PCIE_BAR_MASK         0x0FFFFFFF

/* BAR Index PCie*/
#define PCIE_BAR_IDX_RC        1
#define PCIE_BAR_IDX_EP        1


/* PCIe Regions used in the example */
#define PCIE_IB_REGION_RC   0
#define PCIE_OB_REGION_RC   0
#define PCIE_IB_REGION_EP   0
#define PCIE_OB_REGION_EP   0

#endif /* _PCIE_TEST_H_ */
