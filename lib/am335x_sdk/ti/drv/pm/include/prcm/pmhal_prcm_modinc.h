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
 *  \file      pmhal_prcm_modinc.h
 *
 *  \brief     Contains the list of modules to be included for compilation
 *
 *  \warning   This file is auto generated. So avoid manual changes.
 *              If manual changes are required the implications of the
 *              change in this and other auto generated files has to be
 *              completely understood.
 */

#ifndef PMHAL_PRCM_MODINC_TOP_H_
#define PMHAL_PRCM_MODINC_TOP_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#if defined(SOC_TDA2XX) || defined(SOC_AM572x) || defined(SOC_DRA75x)
#include <ti/drv/pm/include/prcm/V0/pmhal_prcm_modinc.h>
#endif

#if defined(SOC_TDA2EX) || defined(SOC_AM571x)
#include <ti/drv/pm/include/prcm/V1/pmhal_prcm_modinc.h>
#endif

#if defined(SOC_TDA3XX) || defined(SOC_DRA78x)
#include <ti/drv/pm/include/prcm/V2/pmhal_prcm_modinc.h>
#endif

#if defined(SOC_AM335x)
#include <ti/drv/pm/include/prcm/V3/pmhal_prcm_modinc.h>
#endif

#if defined(SOC_AM437x)
#include <ti/drv/pm/include/prcm/V4/pmhal_prcm_modinc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

#if defined(SOC_AM571x)
#undef BUILDCFG_PMHAL_PRCM_MOD_I2C6
#undef BUILDCFG_PMHAL_PRCM_MOD_LVDSRX
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* PMHAL_PRCM_MODINC_TOP_H_ */

