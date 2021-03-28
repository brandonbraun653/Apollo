/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated
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

#ifndef CSLR_SOC_IN_H
#define CSLR_SOC_IN_H

#include <ti/csl/soc/j721e/src/csl_psilcfg_thread_map.h>
#include <ti/csl/soc/j721e/src/csl_soc_isc.h>
#include <ti/csl/soc/j721e/src/csl_soc_qos.h>
#include <ti/csl/soc/j721e/src/cslr_soc_intr.h>
#include <ti/csl/soc/j721e/src/cslr_navss_defines.h>
#include <ti/csl/soc/j721e/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/j721e/src/cslr_soc_c66_baseaddress.h>
#include <ti/csl/soc/j721e/src/cslr_soc_defines.h>
#include <ti/csl/soc/j721e/src/cslr_soc_mcu_r5_baseaddress.h>
#include <ti/csl/soc/j721e/src/cslr_soc_main_r5_baseaddress.h>
#include <ti/csl/soc/j721e/src/cslr_main_ctrl_mmr.h>
#include <ti/csl/soc/j721e/src/cslr_mcu_ctrl_mmr.h>
#include <ti/csl/soc/j721e/src/csl_soc_firewalls.h>

/* Temp changes needed to get osal_nonos to build for J721E/C66x.  Obviously this
 * is not the right thing to do and needs to be replaced with suitable CSL
 * update to support the C66x definitions.  Tracked in PDK-2934.
 */
#define CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS                                  (0x1800000U)
#define SOC_DSP_XMC_CTRL_BASE                                                   (0x8000000U)
#define CSL_DSP_DSP_XMC_CTRL_REGS                                               (SOC_DSP_XMC_CTRL_BASE)
#define CSL_COMPUTE_CLUSTER0_DRU_BASE                                           (0x6d000000UL)
#define CSL_COMPUTE_CLUSTER0_DRU_SIZE                                           (0x1000000UL)


#ifndef CSL_MODIFICATION
#define SOC_DSP_L1P_BASE               (CSL_C66X_COREPAC_LOCAL_L1P_SRAM_REGS)
#define SOC_DSP_L1D_BASE               (CSL_C66X_COREPAC_LOCAL_L1D_SRAM_REGS)
#define SOC_DSP_L2_BASE                (CSL_C66X_COREPAC_LOCAL_L2_SRAM_REGS)
#define SOC_DSP_ICFG_BASE              (CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS - 0x800000U)
#define CSL_C66X_COREPAC_LOCAL_L2_SRAM_REGS  (0x00800000)
#define CSL_C66X_COREPAC_LOCAL_L1P_SRAM_REGS  (0x00E00000)
#define CSL_C66X_COREPAC_LOCAL_L1D_SRAM_REGS  (0x00F00000)
#endif

#endif /* CSLR_SOC_IN_H */
