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
 */
/** ============================================================================
 *  @file       pruicss_v1.h
 *
 *  @brief      PRUICSS driver implementation for a am57x PRUICSS controller
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_pruss_PRUICSSv1_include
#define ti_drivers_pruss_PRUICSSv1_include
#include <ti/drv/pruss/pruicss.h>

#ifdef __cplusplus
extern "C" {
#endif


#if defined(SOC_J721E)
/* temporary until these are available in CSL for J7, being tracked by PRSDK-7682 */
#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_RAM_BASE                                                   (0xb00a000u)
#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_RAM_SIZE                                                   (0x1800u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_RAM_BASE                                                   (0xb00c000u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_RAM_SIZE                                                   (0x1800u)

#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_BASE                                                       (0xb025000u)
#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_SIZE                                                       (0x100u)
#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_DEBUG_BASE                                                 (0xb025400u)
#define CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_DEBUG_SIZE                                                 (0x100u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_BASE                                                       (0xb025800u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_SIZE                                                       (0x100u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_DEBUG_BASE                                                 (0xb025c00u)
#define CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_DEBUG_SIZE                                                 (0x100u)

#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_RAM_BASE                                                   (0xb10a000u)
#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_RAM_SIZE                                                   (0x1800u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_RAM_BASE                                                   (0xb10c000u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_RAM_SIZE                                                   (0x1800u)

#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_BASE                                                       (0xb125000u)
#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_SIZE                                                       (0x100u)
#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_DEBUG_BASE                                                 (0xb125400u)
#define CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_DEBUG_SIZE                                                 (0x100u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_BASE                                                       (0xb125800u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_SIZE                                                       (0x100u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_DEBUG_BASE                                                 (0xb125c00u)
#define CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_DEBUG_SIZE                                                 (0x100u)
#endif

typedef enum PRUSS_PruCores_s
{
    PRUICCSS_PRU0,
    PRUICCSS_PRU1,
    PRUICCSS_RTU0,
    PRUICCSS_RTU1,
    PRUICCSS_TPRU0,
    PRUICCSS_TPRU1,
    PRUICSS_MAX_PRU
}PRUSS_PruCores;
/*!
 *  @brief      PRUICSS Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PRUICSS_V1_Object_s
{

    uint32_t            pruicss_version;
    int32_t             instance;         /* PRUICSS write semaphore*/
    void*               pruBinBuff[PRUICSS_MAX_PRU];         /* Buffer data pointer */
    uint32_t            buffLen[PRUICSS_MAX_PRU];
    PRUICSS_IrqFunMap   pruEvntOutFnMapArray[PRUICSS_MAX_WAIT_EVENTS];

 }PRUICSS_V1_Object;

/*!
 *  @brief      PRUICSS hardware attributes
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PRUICSS_HWAttrs {
    /*PRUICSS Peripheral's base address for each PRUICSS instance*/
    uintptr_t   baseAddr;
    uint32_t    version;
    uintptr_t   prussPru0CtrlRegBase;
    uintptr_t   prussPru1CtrlRegBase;
    uintptr_t   prussIntcRegBase;
    uintptr_t   prussCfgRegBase;
    uintptr_t   prussUartRegBase;
    uintptr_t   prussIepRegBase;
    uintptr_t   prussEcapRegBase;
    uintptr_t   prussMiiRtCfgRegBase;
    uintptr_t   prussMiiMdioRegBase;
    uintptr_t   prussPru0DramBase;
    uintptr_t   prussPru1DramBase;
    uintptr_t   prussPru0IramBase;
    uintptr_t   prussPru1IramBase;
    uintptr_t   prussSharedDramBase; //16
    uintptr_t   prussRtu0IramBase;
    uintptr_t   prussRtu1IramBase;
    uintptr_t   prussRtu0CtrlRegBase;
    uintptr_t   prussRtu1CtrlRegBase;
    uintptr_t   prussTxPru0CtrlRegBase;
    uintptr_t   prussTxPru1CtrlRegBase;
    uintptr_t   prussTxPru0IramBase;
    uintptr_t   prussTxPru1IramBase;
    uint32_t    prussPru0DramSize;
    uint32_t    prussPru1DramSize;
    uint32_t    prussPru0IramSize;
    uint32_t    prussPru1IramSize;
    uint32_t    prussSharedDramSize;
    uint32_t    prussRtu0IramSize;
    uint32_t    prussRtu1IramSize;
    uint32_t    prussTxPru0IramSize;
    uint32_t    prussTxPru1IramSize;
} PRUICSS_HwAttrs;


#define PRU_ICSS_DATARAM(n)             (0x00000U + ((n) * 0x02000U))
#define PRU_ICSS_SHARED_RAM             (0x10000U)
#define PRU_ICSS_IRAM(n)                (((n) < 2U) ? (0x34000U + ((n) * 0x04000U)) : (0x4000U + ((n)-2U) * 0x2000U))

#define PRU_ICSS_IRAM_PRU(n)                (0x34000U + ((n) * 0x04000U))
#define PRU_ICSS_IRAM_RTU(n)                (0x04000 + ((n) * 0x02000U))
#define PRU_ICSS_IRAM_TXPRU(n)              (0x0A000 + ((n) * 0x02000U))

#define PRU_ICSS_REVISION_MAJOR_MASK            (0x00000700)
#define PRU_ICSS_REVISION_MINOR_MASK            (0x0000003F)

/***********************************************************************
  Macros representing Interrupt-Channel-Host sizes
***********************************************************************/

/***********************************************************************
  Macros to support dynamic chip detecting feature
***********************************************************************/

typedef struct PRUSS_MemInfo_s {
    uintptr_t   addr;
    uint32_t   size;
} PRUSS_MemInfo;


#ifdef __cplusplus
}
#endif

#endif
