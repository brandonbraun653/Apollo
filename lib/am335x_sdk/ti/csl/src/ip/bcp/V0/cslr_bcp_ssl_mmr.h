/********************************************************************
* Copyright (C) 2003-2018 Texas Instruments Incorporated.
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
/*********************************************************************
* file: cslr_bcp_ssl.h
*
* Brief: This file contains the Register Description for bcp_ssl
*
*********************************************************************/
#ifndef CSLR_BCP_SSL_MMR_H_
#define CSLR_BCP_SSL_MMR_H_

#include <ti/csl/cslr.h>

#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for SSL Interrupt Registers
\**************************************************************************/
typedef struct  {
    volatile Uint32 SSL_INTR_IRS; /* BCP Raw Status Register */
    volatile Uint32 SSL_INTR_IRS_SET; /* BCP Set Raw Status Register */
    volatile Uint32 SSL_INTR_IRS_CLR; /* BCP Clear Raw Status Register */
    volatile Uint32 SSL_INTR_EN; /* BCP Enable SSL_intr0 Register */
    volatile Uint32 SSL_INTR_EN_SET; /* BCP Set Enable SSL_intr0 Register */
    volatile Uint32 SSL_INTR_EN_CLR; /* BCP Clear Enable SSL_intr0 Register */
    volatile Uint32 SSL_INTR_EN_STS; /* BCP Enabled SSL_intr0 Register */
} CSL_Bcp_sslSsl_interrupt_registersRegs; /* SSL interrupt register group */

/**************************************************************************\
* Register Overlay Structure for SSL Data Logger
\**************************************************************************/
typedef struct  {
    volatile Uint32 SSL_DLG_GLOBAL_HDR; /* Data logger control Register */
    volatile Uint32 SSL_DLG_TM_SW_TIMESTAMP; /* Data logger control Register */
    volatile Uint32 SSL_DLG_HW_TIMESTAMP_ENG_ERR; /* Data logger control Register */
    volatile Uint8 RSVD0[4];
} CSL_Bcp_sslSsl_data_loggerRegs; /* Data Logger */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Bcp_sslSsl_interrupt_registersRegs SSL_INTERRUPT_REGISTERS[4];
    volatile Uint32 SSL_DATA_LOGGER_CTL; /* Data logger control Register */
    volatile Uint32 SSL_DATA_LOGGER_STATUS; /* Datalogger Status Register */
    volatile Uint32 SSL_GLOBAL_HDR; /* Submodule Global Header Register */
    volatile Uint8 RSVD1[34052];
    CSL_Bcp_sslSsl_data_loggerRegs SSL_DATA_LOGGER[256];
} CSL_Bcp_sslRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* SSL_intr_irs */

#define CSL_BCP_SSL_SSL_INTR_IRS_PPB_ERR_MASK (0x000000FFu)
#define CSL_BCP_SSL_SSL_INTR_IRS_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_IRS_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_IRS_RESETVAL (0x00000000u)

/* SSL_intr_irs_set */

#define CSL_BCP_SSL_SSL_INTR_IRS_SET_PPB_ERR_MASK (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_IRS_SET_DLG_DONE_INT_MASK (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_DLG_DONE_INT_SHIFT (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_DLG_DONE_INT_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_IRS_SET_ENG_ERROR_MASK (0x000001FCu)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_ENG_ERROR_SHIFT (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_IRS_SET_ENG_ERROR_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_INTR_IRS_SET_RESETVAL (0x00000000u)

/* SSL_intr_irs_clr */

#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_PPB_ERR_MASK (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_DLG_DONE_INT_MASK (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_DLG_DONE_INT_SHIFT (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_DLG_DONE_INT_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_ENG_ERROR_MASK (0x000001FCu)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_ENG_ERROR_SHIFT (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_ENG_ERROR_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_INTR_IRS_CLR_RESETVAL (0x00000000u)

/* SSL_intr_en */

#define CSL_BCP_SSL_SSL_INTR_EN_PPB_ERR_MASK (0x000000FFu)
#define CSL_BCP_SSL_SSL_INTR_EN_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_EN_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_RESETVAL (0x00000000u)

/* SSL_intr_en_set */

#define CSL_BCP_SSL_SSL_INTR_EN_SET_PPB_ERR_MASK (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_SET_DLG_DONE_INT_MASK (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_DLG_DONE_INT_SHIFT (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_DLG_DONE_INT_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_SET_ENG_ERROR_MASK (0x000001FCu)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_ENG_ERROR_SHIFT (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_EN_SET_ENG_ERROR_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_INTR_EN_SET_RESETVAL (0x00000000u)

/* SSL_intr_en_clr */

#define CSL_BCP_SSL_SSL_INTR_EN_CLR_PPB_ERR_MASK (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_CLR_DLG_DONE_INT_MASK (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_DLG_DONE_INT_SHIFT (0x00000001u)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_DLG_DONE_INT_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_CLR_ENG_ERROR_MASK (0x000001FCu)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_ENG_ERROR_SHIFT (0x00000002u)
#define CSL_BCP_SSL_SSL_INTR_EN_CLR_ENG_ERROR_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_INTR_EN_CLR_RESETVAL (0x00000000u)

/* SSL_intr_en_sts */

#define CSL_BCP_SSL_SSL_INTR_EN_STS_PPB_ERR_MASK (0x000000FFu)
#define CSL_BCP_SSL_SSL_INTR_EN_STS_PPB_ERR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_INTR_EN_STS_PPB_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_INTR_EN_STS_RESETVAL (0x00000000u)

/* SSL_dlg_global_hdr */

#define CSL_BCP_SSL_SSL_DLG_GLOBAL_HDR_GLOBAL_HDR_MASK (0xFFFFFFFFu)
#define CSL_BCP_SSL_SSL_DLG_GLOBAL_HDR_GLOBAL_HDR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_DLG_GLOBAL_HDR_GLOBAL_HDR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DLG_GLOBAL_HDR_RESETVAL (0x00000000u)

/* SSL_dlg_tm_sw_timestamp */

#define CSL_BCP_SSL_SSL_DLG_TM_SW_TIMESTAMP_TM_SW_TIMESTAMP_MASK (0xFFFFFFFFu)
#define CSL_BCP_SSL_SSL_DLG_TM_SW_TIMESTAMP_TM_SW_TIMESTAMP_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_DLG_TM_SW_TIMESTAMP_TM_SW_TIMESTAMP_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DLG_TM_SW_TIMESTAMP_RESETVAL (0x00000000u)

/* SSL_dlg_hw_timestamp_eng_err */

#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_ENG_ERR_MASK (0xFF000000u)
#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_ENG_ERR_SHIFT (0x00000018u)
#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_ENG_ERR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_TM_HW_TIMESTAMP_MASK (0x00FFFFFFu)
#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_TM_HW_TIMESTAMP_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_TM_HW_TIMESTAMP_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DLG_HW_TIMESTAMP_ENG_ERR_RESETVAL (0x00000000u)

/* SSL_data_logger_ctl */

#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_CTL_MASK (0x00000007u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_CTL_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_CTL_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_ERR_MASK_MASK (0x01FF0000u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_ERR_MASK_SHIFT (0x00000010u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_DLG_ERR_MASK_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_DATA_LOGGER_CTL_RESETVAL (0x00000000u)

/* SSL_data_logger_status */

#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_PTR_MASK (0x000000FFu)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_PTR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_PTR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_WRAP_MASK (0x0000FF00u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_WRAP_SHIFT (0x00000008u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_WR_WRAP_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_MEM_HAS_ERROR_MASK (0x00010000u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_MEM_HAS_ERROR_SHIFT (0x00000010u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_MEM_HAS_ERROR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_RUNNING_MASK (0x00020000u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_RUNNING_SHIFT (0x00000011u)
#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_DLG_RUNNING_RESETVAL (0x00000000u)


#define CSL_BCP_SSL_SSL_DATA_LOGGER_STATUS_RESETVAL (0x00000000u)

/* SSL_global_hdr */

#define CSL_BCP_SSL_SSL_GLOBAL_HDR_GLOBAL_HDR_MASK (0xFFFFFFFFu)
#define CSL_BCP_SSL_SSL_GLOBAL_HDR_GLOBAL_HDR_SHIFT (0x00000000u)
#define CSL_BCP_SSL_SSL_GLOBAL_HDR_GLOBAL_HDR_RESETVAL (0x00000000u)

#define CSL_BCP_SSL_SSL_GLOBAL_HDR_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
