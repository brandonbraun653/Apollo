/********************************************************************
*
* ICSS BASEADDRESS header file
*
* Copyright (C) 2015-2018 Texas Instruments Incorporated.
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
#ifndef CSLR_ICSS_BASEADDRESS_H_
#define CSLR_ICSS_BASEADDRESS_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

#define CSL_PRU_ICSSG_RAT_REGION0_BASE                                                         (0x40000ul)
#define CSL_PRU_ICSSG_RAT_REGION0_SIZE                                                         (0xfffc0000ul)
#define CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE                                                      (0xb000000ul)
#define CSL_PRU_ICSSG0_DRAM0_SLV_RAM_SIZE                                                      (0x2000ul)
#define CSL_PRU_ICSSG0_DRAM1_SLV_RAM_BASE                                                      (0xb002000ul)
#define CSL_PRU_ICSSG0_DRAM1_SLV_RAM_SIZE                                                      (0x2000ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_RAM_BASE                                         (0xb004000ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_RAM_SIZE                                         (0x2000ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_RAM_BASE                                         (0xb006000ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_RAM_SIZE                                         (0x2000ul)
#define CSL_PRU_ICSSG0_RAT_SLICE0_CFG_BASE                                                     (0xb008000ul)
#define CSL_PRU_ICSSG0_RAT_SLICE0_CFG_SIZE                                                     (0x1000ul)
#define CSL_PRU_ICSSG0_RAT_SLICE1_CFG_BASE                                                     (0xb009000ul)
#define CSL_PRU_ICSSG0_RAT_SLICE1_CFG_SIZE                                                     (0x1000ul)
#define CSL_PRU_ICSSG0_RAM_SLV_RAM_BASE                                                        (0xb010000ul)
#define CSL_PRU_ICSSG0_RAM_SLV_RAM_SIZE                                                        (0x10000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_INTC_INTC_SLV_BASE                                             (0xb020000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_INTC_INTC_SLV_SIZE                                             (0x2000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_BASE                                                     (0xb022000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_SIZE                                                     (0x100ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_DEBUG_BASE                                               (0xb022400ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_DEBUG_SIZE                                               (0x100ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_BASE                                             (0xb023000ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_SIZE                                             (0x100ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_DEBUG_BASE                                       (0xb023400ul)
#define CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_DEBUG_SIZE                                       (0x100ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_BASE                                             (0xb023800ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_SIZE                                             (0x100ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_DEBUG_BASE                                       (0xb023c00ul)
#define CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_DEBUG_SIZE                                       (0x100ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_BASE                                                     (0xb024000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_SIZE                                                     (0x100ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_DEBUG_BASE                                               (0xb024400ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_DEBUG_SIZE                                               (0x100ul)
#define CSL_PRU_ICSSG0_PR1_PROT_SLV_BASE                                                       (0xb024c00ul)
#define CSL_PRU_ICSSG0_PR1_PROT_SLV_SIZE                                                       (0x100ul)
#define CSL_PRU_ICSSG0_PR1_CFG_SLV_BASE                                                        (0xb026000ul)
#define CSL_PRU_ICSSG0_PR1_CFG_SLV_SIZE                                                        (0x200ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_QSTAT_BASE                                          (0xb027000ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_QSTAT_SIZE                                          (0x1000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_UART_UART_SLV_BASE                                             (0xb028000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_UART_UART_SLV_SIZE                                             (0x40ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_BASE                          (0xb02a000ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_PRU0_PR1_TASKS_MGR_PRU0_MMR_SIZE                          (0x100ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_BASE                          (0xb02a100ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_RTU0_PR1_TASKS_MGR_RTU0_MMR_SIZE                          (0x100ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_PRU1_PR1_TASKS_MGR_PRU1_MMR_BASE                          (0xb02a200ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_PRU1_PR1_TASKS_MGR_PRU1_MMR_SIZE                          (0x100ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_RTU1_PR1_TASKS_MGR_RTU1_MMR_BASE                          (0xb02a300ul)
#define CSL_PRU_ICSSG0_PR1_TASKS_MGR_RTU1_PR1_TASKS_MGR_RTU1_MMR_SIZE                          (0x100ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_CSTAT_BASE                                          (0xb02c000ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_CSTAT_SIZE                                          (0x1000ul)
#define CSL_PRU_ICSSG0_IEP0_BASE                                                               (0xb02e000ul)
#define CSL_PRU_ICSSG0_IEP0_SIZE                                                               (0x1000ul)
#define CSL_PRU_ICSSG0_IEP1_BASE                                                               (0xb02f000ul)
#define CSL_PRU_ICSSG0_IEP1_SIZE                                                               (0x1000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_ECAP0_ECAP_SLV_BASE                                            (0xb030000ul)
#define CSL_PRU_ICSSG0_PR1_ICSS_ECAP0_ECAP_SLV_SIZE                                            (0x100ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_BASE                                          (0xb032000ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_SIZE                                          (0x100ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_SGMII0_CFG_SGMII0_BASE                                   (0xb032100ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_SGMII0_CFG_SGMII0_SIZE                                   (0x100ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_SGMII1_CFG_SGMII1_BASE                                   (0xb032200ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_SGMII1_CFG_SGMII1_SIZE                                   (0x100ul)
#define CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_BASE                                                 (0xb032400ul)
#define CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_SIZE                                                 (0x100ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE                                 (0xb033000ul)
#define CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_SIZE                                 (0x1000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_RAM_BASE                                                 (0xb034000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_RAM_SIZE                                                 (0x4000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_RAM_BASE                                                 (0xb038000ul)
#define CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_RAM_SIZE                                                 (0x4000ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_BASE                                                (0xb03c000ul)
#define CSL_PRU_ICSSG0_PA_STAT_WRAP_PA_SLV_SIZE                                                (0x100ul)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_ICSS_MEMORYMAP_H_ */
