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
    {CSL_PSC_PD_ALWAYSON,       CSL_PSC_LPSC_EMAC_SS},
    {CSL_PSC_PD_DEBUG_TRC,      CSL_PSC_LPSC_DEBUGSS_TRC},
    {CSL_PSC_PD_DEBUG_TRC,      CSL_PSC_LPSC_TETB_TRC},
    {CSL_PSC_PD_PCIEX,          CSL_PSC_LPSC_PCIEX},
    {CSL_PSC_PD_SRIO,           CSL_PSC_LPSC_SRIO},
    {CSL_PSC_PD_HYPERBRIDGE,    CSL_PSC_LPSC_HYPERBRIDGE},
    {CSL_PSC_PD_MSMCSRAM,       CSL_PSC_LPSC_MSMCSRAM},
    {CSL_PSC_PD_TCP3D_A,        CSL_PSC_LPSC_TCP3D_A},
    {CSL_PSC_PD_PD_VCP_BCD,     CSL_PSC_LPSC_VCP2_A},
    {CSL_PSC_PD_PD_VCP_BCD,     CSL_PSC_LPSC_VCP2_B}
};

uint32_t Board_getNumPSCconfigs()
{
    return (sizeof(pscConfigs) / sizeof(pscConfig));
}
