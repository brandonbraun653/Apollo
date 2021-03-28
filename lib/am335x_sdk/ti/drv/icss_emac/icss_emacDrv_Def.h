/**
 *   @file  icss_emacDrv.h
 *
 *   @brief
 *      Include file for ICSS_EMAC RX/TX functions and queue structures
 */

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef ICSS_EMACDRV_DEF_H
#define ICSS_EMACDRV_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/hw_types.h>


#include <ti/drv/pruss/pruicss.h>


/**
 * @brief Alias for ICSS EMAC Handle containing base addresses and modules
 */
typedef struct  ICSS_EmacConfig_s        * ICSS_EmacHandle;
/**
 * @brief Alias for EMAC base addresses
 */

/* For  backward compatibility */
#define ICSSEMAC_Handle ICSS_EmacHandle

typedef struct  ICSS_EmacBaseAddrCfgParams_s *ICSS_EmacBaseAddressHandle_T;

/**
 * @brief ICSS_EMAC Base address configuration addresses required by low level driver
 */
typedef struct ICSS_EmacBaseAddrCfgParams_s {
    /*! MDIO Base register */
    uint32_t    prussMiiMdioRegs;
    /*! DataRam 0 Base Address */
    uint32_t    dataRam0BaseAddr;
    /*! DataRam 1 Base Address */
    uint32_t    dataRam1BaseAddr;
    /*! L3 OCMC Base Address */
    uint32_t    l3OcmcBaseAddr; /* for SOC_K2G, this is base address of MSMS_SRAM */
    /*! PRUSS Shared RAM Base Address */
    uint32_t    sharedDataRamBaseAddr;
    /*! Pruss INTC Register Base Address */
    uint32_t    prussIntcRegs;
    /*! PRU0 Control register Base Address */
    uint32_t    prussPru0CtrlRegs;
    /*! PRU1 Control register Base Address  */
    uint32_t    prussPru1CtrlRegs;
    /*! PRUSS IEP register Base Address */
    uint32_t    prussIepRegs;
    /*! Pruss CFG register Base Address */
    uint32_t    prussCfgRegs;
    /*! MII RT Config register Base Address */
    uint32_t    prussMiiRtCfgRegsBaseAddr;
    /*! DataRam 0 Size */
    uint32_t    dataRam0Size;
    /*! DataRam 1 Size */
    uint32_t    dataRam1Size;
    /*! L3 OCMCSize */
    uint32_t    l3OcmcSize; /* for SOC_K2G, this is size of  of MSMS_SRAM */
    /*! PRUSS Shared RAM Size */
    uint32_t    sharedDataRamSize;
#ifdef __LINUX_USER_SPACE
    /*! ECAP register Base Address */
    uint32_t    ecapBaseAddr;
    /* Needed for Linux use, where above base addresses are virtual addresses */
    /*! PRUSS Shared RAM Physical Address */
    uint32_t    sharedDataRamBaseAddr_phys;
    /*! L3 OCMC Physical Address */
    uint32_t    l3OcmcBaseAddr_phys;
#endif
} ICSS_EmacBaseAddrCfgParams;


#ifdef __cplusplus
}
#endif

#endif /* ICSS_EMACDRV_DEF_H */
