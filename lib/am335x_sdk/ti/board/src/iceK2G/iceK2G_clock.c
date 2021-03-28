/******************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_clock.h"

const pscConfig pscConfigs[] =
{
    {CSL_PSC_PD_DEBUG,          CSL_PSC_LPSC_PMMC},
    {CSL_PSC_PD_DEBUG,          CSL_PSC_LPSC_DEBUG},
    {CSL_PSC_PD_NSS,            CSL_PSC_LPSC_NSS},
    {CSL_PSC_PD_SA,             CSL_PSC_LPSC_SA},
    {CSL_PSC_PD_TERANET,        CSL_PSC_LPSC_TERANET},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_SYS_COMP},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_QSPI},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_MMC},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_GPMC},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_MLB},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_EHRPWM},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_EQEP},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_ECAP},
    {CSL_PSC_PD_SYS_COMP,       CSL_PSC_LPSC_MCASP},
    {CSL_PSC_PD_SR,             CSL_PSC_LPSC_SR},
    {CSL_PSC_PD_MSMC,           CSL_PSC_LPSC_MSMC},
    {CSL_PSC_PD_C66X_COREPAC_0, CSL_PSC_LPSC_C66X_COREPAC_0},
    {CSL_PSC_PD_ARM,            CSL_PSC_LPSC_ARM},
    {CSL_PSC_PD_ASRC,           CSL_PSC_LPSC_ASRC},
    {CSL_PSC_PD_ICSS,           CSL_PSC_LPSC_ICSS},
    {CSL_PSC_PD_DSS,            CSL_PSC_LPSC_DSS},
    {CSL_PSC_PD_PCIE,           CSL_PSC_LPSC_PCIE},
    {CSL_PSC_PD_USB,            CSL_PSC_LPSC_USB_0},
    {CSL_PSC_PD_USB,            CSL_PSC_LPSC_USB_1},
    {CSL_PSC_PD_DDR3,           CSL_PSC_LPSC_DDR3}
};

uint32_t Board_getNumPSCconfigs()
{
    return (sizeof(pscConfigs) / sizeof(pscConfig));
}
