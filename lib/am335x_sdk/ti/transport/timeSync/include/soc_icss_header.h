/**
 * @file soc_icss_header.h
 *
*/
/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **/
#ifndef SOC_ICSS_HEADER_H
#define SOC_ICSS_HEADER_H

/*-----------------------------------------------------------------------------------------
------
------  Includes
------
-----------------------------------------------------------------------------------------*/

#include <ti/csl/hw_types.h>

#if  defined(SOC_AM335x) || defined(SOC_AM437x)
#include <ti/csl/src/ip/icss/V0/cslr_icssm_iep.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_mii_mdio.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_intc.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_cfg.h>

#else
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_mii_mdio.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_intc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>
#endif
#if defined(SOC_K2G)
#include <ti/csl/src/ip/mdio/V1/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V1/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V1/csl_mdioAux.h>
#elif defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM571x) || defined(SOC_AM335x) || defined(SOC_AM437x)
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
#endif

/*-----------------------------------------------------------------------------------------
------
------  Defines and Types
------
-----------------------------------------------------------------------------------------*/
#if  defined(SOC_AM335x) || defined(SOC_AM437x)
/**IEP macros*/
#undef CSL_ICSSIEP_COUNT_REG0
#define CSL_ICSSIEP_COUNT_REG0          CSL_ICSSM_IEP_COUNT
#undef CSL_ICSSIEP_DIGIO_CTRL_REG
#define CSL_ICSSIEP_DIGIO_CTRL_REG      CSL_ICSSM_IEP_DIGIO_CTRL
#undef CSL_ICSSIEP_DIGIO_EXP_REG
#define CSL_ICSSIEP_DIGIO_EXP_REG       CSL_ICSSM_IEP_DIGIO_EXP
#undef CSL_ICSSIEP_DIGIO_DATA_OUT_REG
#define CSL_ICSSIEP_DIGIO_DATA_OUT_REG  CSL_ICSSM_IEP_DIGIO_DATA_OUT
#undef CSL_ICSSIEP_CAP_CFG_REG
#define CSL_ICSSIEP_CAP_CFG_REG         CSL_ICSSM_IEP_CAP_CFG
#undef CSL_ICSSIEP_PD_WD_TIM_REG
#define CSL_ICSSIEP_PD_WD_TIM_REG       CSL_ICSSM_IEP_PD_WD_TIM
#undef CSL_ICSSIEP_WD_CTRL_REG
#define CSL_ICSSIEP_WD_CTRL_REG         CSL_ICSSM_IEP_WD_CTRL
#undef CSL_ICSSIEP_CAPR6_REG0
#define CSL_ICSSIEP_CAPR6_REG0          CSL_ICSSM_IEP_CAPR6
#undef CSL_ICSSIEP_CAPF6_REG0
#define CSL_ICSSIEP_CAPF6_REG0          CSL_ICSSM_IEP_CAPF6
#undef CSL_ICSSIEP_GLOBAL_CFG_REG_CNT_ENABLE_MAX
#define CSL_ICSSIEP_GLOBAL_CFG_REG_CNT_ENABLE_MAX    CSL_ICSSM_IEP_GLOBAL_CFG_CNT_ENABLE_MAX
#undef CSL_ICSSIEP_GLOBAL_CFG_REG_CMP_INC_SHIFT
#define CSL_ICSSIEP_GLOBAL_CFG_REG_CMP_INC_SHIFT     CSL_ICSSM_IEP_GLOBAL_CFG_CMP_INC_SHIFT
#undef CSL_ICSSIEP_CMP1_REG0
#define CSL_ICSSIEP_CMP1_REG0           CSL_ICSSM_IEP_CMP1
#undef CSL_ICSSIEP_CMP0_REG0
#define CSL_ICSSIEP_CMP0_REG0           CSL_ICSSM_IEP_CMP0
#undef CSL_ICSSIEP_SYNC_PWIDTH_REG
#define CSL_ICSSIEP_SYNC_PWIDTH_REG     CSL_ICSSM_IEP_SYNC_PWIDTH
#undef CSL_ICSSIEP_CMP_CFG_REG
#define CSL_ICSSIEP_CMP_CFG_REG         CSL_ICSSM_IEP_CMP_CFG
/**MDIO macros*/
#undef CSL_ICSSMIIMDIO_LINK
#define CSL_ICSSMIIMDIO_LINK            CSL_ICSSM_MII_MDIO_LINK
/**INTC macros*/
#undef CSL_ICSSINTC_SICR
#define CSL_ICSSINTC_SICR               CSL_ICSSM_INTC_SICR
#undef CSL_ICSSINTC_SRSR0
#define CSL_ICSSINTC_SRSR0              CSL_ICSSM_INTC_SRSR0

/**CFG macros*/
#define CSL_ICSSCFG_IEPCLK              CSL_ICSSM_CFG_IEPCLK
#endif

#endif /* _SOC_ICSS_HEADER_H_ */
