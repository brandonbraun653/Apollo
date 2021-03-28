/*
 * Copyright (C) 2010-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/*******************************************************************************
* FILE PURPOSE: EMAC Hardware Platform Configuration
*
********************************************************************************
* FILE NAME:    emac_hwcfg.h
*
* DESCRIPTION:  This file contains definitions of hardware platform specific
*               configuration
*******************************************************************************/
#ifndef __EMACHWCFG_H__
#define __EMACHWCFG_H__

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************
 ******************** Platform Specific Definitions *******************
 **********************************************************************/

/*************************** C6657 Platform ***************************/
#ifdef SOC_C6657

/**
 * @brief   Single core device
 */
#define  MULTI_CORE_DEV
#undef  TWO_PORT_DEV
#endif /* SOC_C6657 */

/**
 * @brief   Maximum number of EMAC ports
 */
#define MAX_NUM_EMAC_PORTS      1

#ifdef __cplusplus
}
#endif

#endif /* __EMACHWCFG_H__*/
