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
    {CSL_PSC_PD_DEBUG_TRC,      CSL_PSC_LPSC_DEBUGSS_TRC},
    {CSL_PSC_PD_DEBUG_TRC,      CSL_PSC_LPSC_TETB_TRC},
    {CSL_PSC_PD_NETCP,          CSL_PSC_LPSC_PA},
    {CSL_PSC_PD_NETCP,          CSL_PSC_LPSC_CPGMAC},
    {CSL_PSC_PD_NETCP,          CSL_PSC_LPSC_SA},
    {CSL_PSC_PD_PCIE,           CSL_PSC_LPSC_PCIE},
    {CSL_PSC_PD_SRIO,           CSL_PSC_LPSC_SRIO},
    {CSL_PSC_PD_HYPERLINK_0,    CSL_PSC_LPSC_HYPERLINK_0},
    {CSL_PSC_PD_SR,             CSL_PSC_LPSC_SR},
    {CSL_PSC_PD_MSMCSRAM,       CSL_PSC_LPSC_MSMCSRAM},
    {CSL_PSC_PD_C66X_COREPAC_0, CSL_PSC_LPSC_C66X_COREPAC_0},
    {CSL_PSC_PD_C66X_COREPAC_1, CSL_PSC_LPSC_C66X_COREPAC_1},
    {CSL_PSC_PD_C66X_COREPAC_2, CSL_PSC_LPSC_C66X_COREPAC_2},
    {CSL_PSC_PD_C66X_COREPAC_3, CSL_PSC_LPSC_C66X_COREPAC_3},
    {CSL_PSC_PD_C66X_COREPAC_4, CSL_PSC_LPSC_C66X_COREPAC_4},
    {CSL_PSC_PD_C66X_COREPAC_5, CSL_PSC_LPSC_C66X_COREPAC_5},
    {CSL_PSC_PD_C66X_COREPAC_6, CSL_PSC_LPSC_C66X_COREPAC_6},
    {CSL_PSC_PD_C66X_COREPAC_7, CSL_PSC_LPSC_C66X_COREPAC_7},
    {CSL_PSC_PD_DDR,            CSL_PSC_LPSC_DDR3_0},
    {CSL_PSC_PD_DDR,            CSL_PSC_LPSC_DDR3_1},
    {CSL_PSC_PD_TAC_RAC_01,     CSL_PSC_LPSC_TAC},
    {CSL_PSC_PD_TAC_RAC_01,     CSL_PSC_LPSC_RAC_01},
    {CSL_PSC_PD_RAC_23,         CSL_PSC_LPSC_RAC_23},
    {CSL_PSC_PD_FFTC_01,        CSL_PSC_LPSC_FFTC_0},
    {CSL_PSC_PD_FFTC_01,        CSL_PSC_LPSC_FFTC_1},
    {CSL_PSC_PD_FFTC_2345,      CSL_PSC_LPSC_FFTC_2},
    {CSL_PSC_PD_FFTC_2345,      CSL_PSC_LPSC_FFTC_3},
    {CSL_PSC_PD_FFTC_2345,      CSL_PSC_LPSC_FFTC_4},
    {CSL_PSC_PD_FFTC_2345,      CSL_PSC_LPSC_FFTC_5},
    {CSL_PSC_PD_AIF,            CSL_PSC_LPSC_AIF},
    {CSL_PSC_PD_TCP3D_01,       CSL_PSC_LPSC_TCP3D_0},
    {CSL_PSC_PD_TCP3D_01,       CSL_PSC_LPSC_TCP3D_1},
    {CSL_PSC_PD_TCP3D_23,       CSL_PSC_LPSC_TCP3D_2},
    {CSL_PSC_PD_TCP3D_23,       CSL_PSC_LPSC_TCP3D_3},
    {CSL_PSC_PD_VCP_0123,       CSL_PSC_LPSC_VCP_0},
    {CSL_PSC_PD_VCP_0123,       CSL_PSC_LPSC_VCP_1},
    {CSL_PSC_PD_VCP_0123,       CSL_PSC_LPSC_VCP_2},
    {CSL_PSC_PD_VCP_0123,       CSL_PSC_LPSC_VCP_3},
    {CSL_PSC_PD_VCP_4567,       CSL_PSC_LPSC_VCP_4},
    {CSL_PSC_PD_VCP_4567,       CSL_PSC_LPSC_VCP_5},
    {CSL_PSC_PD_VCP_4567,       CSL_PSC_LPSC_VCP_6},
    {CSL_PSC_PD_VCP_4567,       CSL_PSC_LPSC_VCP_7},
    {CSL_PSC_PD_BCP,            CSL_PSC_PD_BCP},
    {CSL_PSC_PD_DXB,            CSL_PSC_LPSC_DXB},
    {CSL_PSC_PD_HYPERLINK_1,    CSL_PSC_LPSC_HYPERLINK_1},
    {CSL_PSC_PD_XGE,            CSL_PSC_LPSC_XGE},
    {CSL_PSC_PD_ARM,            CSL_PSC_LPSC_ARM}
};

uint32_t Board_getNumPSCconfigs()
{
    return (sizeof(pscConfigs) / sizeof(pscConfig));
}

