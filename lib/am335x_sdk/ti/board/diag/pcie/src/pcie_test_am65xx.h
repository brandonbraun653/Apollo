/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * \file pcie_test_am65xx.h
 *
 * \brief 
 *  Holds all the constants and API definitions required by the example
 *  application to run.  
 */

#ifndef _PCIE_TEST_AM65XX_H_
#define _PCIE_TEST_AM65XX_H_

/* Header files */
#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_serdes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_serdes_pcie.h>
#include <ti/csl/cslr_pcie.h>
#include "stdlib.h"
#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"
#include <ti/drv/uart/UART_stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function prototype */

/**
 * \brief Device configure function
 *
 * This function is used to configure the device as a root complex or end point
 *
 * \param   pcie_index  [IN] pcie instance
 *          device_type [IN] value to specify RC or EP
 *
 */
static void BoardDiag_configurePcieDeviceType(uint32_t pcie_index,
                                              uint32_t device_type);

/**
 * This function is used to enable Memory bus access
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_enableMemAndBusMaster(uint32_t base_address);

/**
 * \brief Configure EndPoint function
 *
 * This function is used to enable the BAR configurations,Inbound  and outbound  
 * configurations for Endpoint.
 * The PCIe core is configured to support 16x 64-bit outbound and 16x 64-bit
 * inbound address translation regions with each region being a minimum of 64KB
 * in size. If only 32-bit address translation is used, then a total of 32
 * regions can be supported in each direction
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_ConfigureIatuRc(uint32_t base_address);

/**
 * \brief Configure EndPoint function
 *
 * This function is used to enable the BAR configurations,Inbound  and outbound  
 * configurations for Endpoint.
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_ConfigureIatuEp(uint32_t base_address);

/**
 * \brief Outbound write function
 *
 * This function is used to write some data to the Outbound Address
 * Translation
 *
 * \param   pcie_index  [IN]  pcie instance
 *
 */
static void BoardDiag_testObWrite(uint32_t instance);

/**
 * \brief  BoardDiag_pcieTest function
 *
 * This function is used to test the pcie loopback mode
 * In this data sent to EP, RC waits for the loopback to be completed and
 * receive data back from EP
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
int8_t BoardDiag_pcieTest(void);


/* Typedef */
typedef enum
{
    pcie_EP_MODE = 0, /**< Required when setting the PCIe Mode to End Point using the @ref Pcie_setInterfaceMode function */
    pcie_LEGACY_EP_MODE, /**< Required when setting the PCIe Mode to Legacy End Point using the @ref Pcie_setInterfaceMode function */
    pcie_RC_MODE /**< Required when setting the PCIe Mode to Root Complex using the @ref Pcie_setInterfaceMode function */
} pcieMode_e;

typedef enum
{
    SERDES_DIAG_PCIE_GEN1 = 1,
    SERDES_DIAG_PCIE_GEN2 = 2,
    SERDES_DIAG_PCIE_GEN3 = 3
} SERDES_DIAG_PCIE_TYPE;

#if defined (am65xx_idk)
#define PCIE_BASE_ADDR          (CSL_SERDES0_BASE)
#else
#define PCIE_BASE_ADDR          (CSL_SERDES1_BASE)
#endif

#define PCIE_PCIE_GEN_TYPE      (SERDES_DIAG_PCIE_GEN3)  /* For running PCIe tests */

#define BUFFER_SIZE             (16)
#define BUFFER_ADDR             (0x41c00000)//Hard-coded region for testing, make sure it is unused
#define RC_OB_ADDRESS           (0x70000000)
#define EP_OB_ADDRESS           (0x90000000)
#define OB_REGION_0             (0x10000000)
#define OB_REGION_1             (0x10200000)
#define OB_CFG_SIZE             (0x8000)   //32KB
#define OB_MEM_SIZE             (0x10000) //64KB

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PCIE_TEST_AM65XX_H_ */
