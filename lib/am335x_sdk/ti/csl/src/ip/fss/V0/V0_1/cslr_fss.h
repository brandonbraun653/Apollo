/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_fss.h
*/
#ifndef CSLR_FSS_H_
#define CSLR_FSS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_FSS_DAT_REG0_REGS_BASE                                             (0x00000000U)
#define CSL_FSS_DAT_REG1_REGS_BASE                                             (0x00000000U)
#define CSL_FSS_DAT_REG3_REGS_BASE                                             (0x00000000U)
#define CSL_FSS_ECC_AGGR_REGS_BASE                                             (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_REGS_BASE                                         (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_REGS_BASE                                       (0x00000000U)
#define CSL_FSS_GENREGS_REGS_BASE                                              (0x00000000U)
#define CSL_FSS_HYPERBUS_CORE_REGS_BASE                                        (0x00000000U)
#define CSL_FSS_HYPERBUS_SYSCFG_REGS_BASE                                      (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R0_MAP_REGS_BASE                           (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R1_MAP_REGS_BASE                           (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R3_MAP_REGS_BASE                           (0x00000000U)
#define CSL_FSS_OSPI_CFG_REGS_BASE                                             (0x00000000U)
#define CSL_FSS_OSPI_FLASH_CFG_REGS_BASE                                       (0x00000000U)


/**************************************************************************
* Hardware Region  : Global Control Registers, offset 0x00000000
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t EOI;                       /* IRQ_EOI */
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW */
    volatile uint32_t STATUS;                    /* IRQ_STATUS */
    volatile uint32_t ENABLE_SET;                /* IRQ_ENABLE_SET */
    volatile uint32_t ENABLE_CLR;                /* IRQ_ENABLE_CLR */
} CSL_fss_fsas_genregsRegs_IRQ;


typedef struct {
    volatile uint32_t ECC_RGSTRT;                /* RegionStart */
    volatile uint32_t ECC_RGSIZ;                 /* ECC RegionSize */
} CSL_fss_fsas_genregsRegs_ECC_REGCTRL;


typedef struct {
    volatile uint32_t ECC_BLOCK_ADR;             /* ERR_ECC_BLOCK_ADR */
    volatile uint32_t ECC_TYPE;                  /* ERR_ECC_TYPE */
    volatile uint32_t WRT_TYPE;                  /* ERR_WRT_TYPE */
    volatile uint8_t  Resv_16[4];
} CSL_fss_fsas_genregsRegs_ERR;


typedef struct {
    volatile uint8_t  Resv_4[4];
    volatile uint32_t SYSCONFIG;                 /* SYSCONFIG */
    volatile uint32_t FRAG_ADR;                  /* FRAG_ADR */
    volatile uint32_t FRAG_CTL;                  /* FRAG_CTL */
    CSL_fss_fsas_genregsRegs_IRQ IRQ;
    volatile uint8_t  Resv_48[12];
    CSL_fss_fsas_genregsRegs_ECC_REGCTRL ECC_REGCTRL[4];
    volatile uint8_t  Resv_112[32];
    CSL_fss_fsas_genregsRegs_ERR ERR;
} CSL_fss_fsas_genregsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG                                         (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_FRAG_ADR                                          (0x00000008U)
#define CSL_FSS_FSAS_GENREGS_FRAG_CTL                                          (0x0000000CU)
#define CSL_FSS_FSAS_GENREGS_IRQ_EOI                                           (0x00000010U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW                                    (0x00000014U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS                                        (0x00000018U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET                                    (0x0000001CU)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR                                    (0x00000020U)
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSTRT(ECC_REGCTRL)               (0x00000030U+((ECC_REGCTRL)*0x8U))
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSIZ(ECC_REGCTRL)                (0x00000034U+((ECC_REGCTRL)*0x8U))
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_BLOCK_ADR                                 (0x00000070U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE                                      (0x00000074U)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE                                      (0x00000078U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* EOI */

#define CSL_FSS_FSAS_GENREGS_IRQ_EOI_EOI_VECTOR_MASK                           (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_EOI_EOI_VECTOR_SHIFT                          (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_IRQ_EOI_EOI_VECTOR_MAX                            (0x00000001U)

/* STATUS_RAW */

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_MASK            (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_SHIFT           (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_MAX             (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_MASK                (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_SHIFT               (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_MAX                 (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_MASK                (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_SHIFT               (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_MAX                 (0x00000001U)

/* STATUS */

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_MASK                (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_SHIFT               (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_MAX                 (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_MASK                    (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_SHIFT                   (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_MAX                     (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_MASK                    (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_SHIFT                   (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_MAX                     (0x00000001U)

/* ENABLE_SET */

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_MASK            (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_SHIFT           (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_MAX             (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_MASK                (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_SHIFT               (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_MAX                 (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_MASK                (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_SHIFT               (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_MAX                 (0x00000001U)

/* ENABLE_CLR */

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_MASK            (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_SHIFT           (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_MAX             (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_MASK                (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_SHIFT               (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_MAX                 (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_MASK                (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_SHIFT               (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_MAX                 (0x00000001U)

/* ECC_RGSTRT */

#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_MASK               (0x000FFFFFU)
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_SHIFT              (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_MAX                (0x000FFFFFU)

/* ECC_RGSIZ */

#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_MASK                 (0x000FFFFFU)
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_SHIFT                (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_MAX                  (0x000FFFFFU)

/* ECC_BLOCK_ADR */

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_MASK       (0xFFFFFFE0U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_SHIFT      (0x00000005U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_MAX        (0x07FFFFFFU)

/* ECC_TYPE */

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_MASK                   (0x80000000U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_SHIFT                  (0x0000001FU)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_MAX                    (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_MASK                     (0x00000020U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_SHIFT                    (0x00000005U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_MASK                     (0x00000010U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_SHIFT                    (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_MASK                     (0x00000008U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_SHIFT                    (0x00000003U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_MASK                     (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_SHIFT                    (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_MASK                     (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_SHIFT                    (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_MASK                     (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_SHIFT                    (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_MAX                      (0x00000001U)

/* WRT_TYPE */

#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_MASK                   (0x80000000U)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_SHIFT                  (0x0000001FU)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_MAX                    (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_MASK                     (0x00001000U)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_SHIFT                    (0x0000000CU)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_MASK                     (0x00002000U)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_SHIFT                    (0x0000000DU)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_MAX                      (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_MASK                 (0x00000FFFU)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_SHIFT                (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_MAX                  (0x00000FFFU)

/* SYSCONFIG */

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_DISXIP_MASK                             (0x00000080U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_DISXIP_SHIFT                            (0x00000007U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_DISXIP_MAX                              (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_MASK              (0x00000100U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_SHIFT             (0x00000008U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_MAX               (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_MASK              (0x00000040U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_SHIFT             (0x00000006U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_MAX               (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_MASK                    (0x00000008U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_SHIFT                   (0x00000003U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_MAX                     (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_MASK                   (0x00000004U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_SHIFT                  (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_MAX                    (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_EN_MASK                             (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_EN_SHIFT                            (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_SYSCONFIG_ECC_EN_MAX                              (0x00000001U)

/* FRAG_ADR */

#define CSL_FSS_FSAS_GENREGS_FRAG_ADR_FRAG_ADDR_MASK                           (0xFFFFFFFFU)
#define CSL_FSS_FSAS_GENREGS_FRAG_ADR_FRAG_ADDR_SHIFT                          (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_FRAG_ADR_FRAG_ADDR_MAX                            (0xFFFFFFFFU)

/* FRAG_CTL */

#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_HI_MASK                             (0x00000002U)
#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_HI_SHIFT                            (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_HI_MAX                              (0x00000001U)

#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_LO_MASK                             (0x00000001U)
#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_LO_SHIFT                            (0x00000000U)
#define CSL_FSS_FSAS_GENREGS_FRAG_CTL_FRAG_LO_MAX                              (0x00000001U)

/**************************************************************************
* Hardware Region  : OTFA Control Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REVID;                     /* Revision */
    volatile uint32_t SCFG;                      /* SysConfig */
    volatile uint32_t ISR;                       /* IRQSTATUS_RAW */
    volatile uint32_t IS;                        /* IRQSTATUS  */
    volatile uint32_t IES;                       /* IRQENABLE_SET  */
    volatile uint32_t IEC;                       /* IRQENABLE_CLR */
    volatile uint32_t CCFG;                      /* CryptoCfg  */
    volatile uint32_t CSTATUS;                   /* CryptoStatus */
    volatile uint32_t RGCFG0;                    /* RegionCfg0  */
    volatile uint32_t RGMACST0;                  /* RegionMacStart0  */
    volatile uint32_t RGST0;                     /* RegionStart0  */
    volatile uint32_t RGSI0;                     /* RegionSize0  */
    volatile uint32_t RKEYE00;                   /* RegionKeyE00  */
    volatile uint32_t RKEYE01;                   /* RegionKeyE01  */
    volatile uint32_t RKEYE02;                   /* RegionKeyE02  */
    volatile uint32_t RKEYE03;                   /* RegionKeyE03  */
    volatile uint32_t RKEYE04;                   /* RegionKeyE04  */
    volatile uint32_t RKEYE05;                   /* RegionKeyE05  */
    volatile uint32_t RKEYE06;                   /* RegionKeyE06  */
    volatile uint32_t RKEYE07;                   /* RegionKeyE07  */
    volatile uint32_t RKEYEP00;                  /* RegionKeyEP00  */
    volatile uint32_t RKEYEP01;                  /* RegionKeyEP01  */
    volatile uint32_t RKEYEP02;                  /* RegionKeyEP02  */
    volatile uint32_t RKEYEP03;                  /* RegionKeyEP03  */
    volatile uint32_t RKEYEP04;                  /* RegionKeyEP04  */
    volatile uint32_t RKEYEP05;                  /* RegionKeyEP05  */
    volatile uint32_t RKEYEP06;                  /* RegionKeyEP06  */
    volatile uint32_t RKEYEP07;                  /* RegionKeyEP07  */
    volatile uint32_t RKEYA00;                   /* RegionKeyA00  */
    volatile uint32_t RKEYA01;                   /* RegionKeyA01  */
    volatile uint32_t RKEYA02;                   /* RegionKeyA02  */
    volatile uint32_t RKEYA03;                   /* RegionKeyA03  */
    volatile uint32_t RKEYAP00;                  /* RegionKeyAP00  */
    volatile uint32_t RKEYAP01;                  /* RegionKeyAP01  */
    volatile uint32_t RKEYAP02;                  /* RegionKeyAP02  */
    volatile uint32_t RKEYAP03;                  /* RegionKeyAP03  */
    volatile uint32_t RIV00;                     /* RegionIV00  */
    volatile uint32_t RIV01;                     /* RegionIV01  */
    volatile uint32_t RIV02;                     /* RegionIV02  */
    volatile uint32_t RIV03;                     /* RegionIV03  */
    volatile uint32_t RGCFG1;                    /* RegionCfg1  */
    volatile uint32_t RGMACST1;                  /* RegionMacStart1  */
    volatile uint32_t RGST1;                     /* RegionStart1  */
    volatile uint32_t RGSI1;                     /* RegionSize1  */
    volatile uint32_t RKEYE10;                   /* RegionKeyE10  */
    volatile uint32_t RKEYE11;                   /* RegionKeyE11  */
    volatile uint32_t RKEYE12;                   /* RegionKeyE12  */
    volatile uint32_t RKEYE13;                   /* RegionKeyE13  */
    volatile uint32_t RKEYE14;                   /* RegionKeyE14  */
    volatile uint32_t RKEYE15;                   /* RegionKeyE15  */
    volatile uint32_t RKEYE16;                   /* RegionKeyE16  */
    volatile uint32_t RKEYE17;                   /* RegionKeyE17  */
    volatile uint32_t RKEYEP10;                  /* RegionKeyEP10  */
    volatile uint32_t RKEYEP11;                  /* RegionKeyEP11  */
    volatile uint32_t RKEYEP12;                  /* RegionKeyEP12  */
    volatile uint32_t RKEYEP13;                  /* RegionKeyEP13  */
    volatile uint32_t RKEYEP14;                  /* RegionKeyEP14  */
    volatile uint32_t RKEYEP15;                  /* RegionKeyEP15  */
    volatile uint32_t RKEYEP16;                  /* RegionKeyEP16  */
    volatile uint32_t RKEYEP17;                  /* RegionKeyEP17  */
    volatile uint32_t RKEYA10;                   /* RegionKeyA10  */
    volatile uint32_t RKEYA11;                   /* RegionKeyA11  */
    volatile uint32_t RKEYA12;                   /* RegionKeyA12  */
    volatile uint32_t RKEYA13;                   /* RegionKeyA13  */
    volatile uint32_t RKEYAP10;                  /* RegionKeyAP10  */
    volatile uint32_t RKEYAP11;                  /* RegionKeyAP11  */
    volatile uint32_t RKEYAP12;                  /* RegionKeyAP12  */
    volatile uint32_t RKEYAP13;                  /* RegionKeyAP13  */
    volatile uint32_t RIV10;                     /* RegionIV10  */
    volatile uint32_t RIV11;                     /* RegionIV11  */
    volatile uint32_t RIV12;                     /* RegionIV12  */
    volatile uint32_t RIV13;                     /* RegionIV13  */
    volatile uint32_t RGCFG2;                    /* RegionCfg2  */
    volatile uint32_t RGMACST2;                  /* RegionMacStart2  */
    volatile uint32_t RGST2;                     /* RegionStart2  */
    volatile uint32_t RGSI2;                     /* RegionSize2  */
    volatile uint32_t RKEYE20;                   /* RegionKeyE20  */
    volatile uint32_t RKEYE21;                   /* RegionKeyE21  */
    volatile uint32_t RKEYE22;                   /* RegionKeyE22  */
    volatile uint32_t RKEYE23;                   /* RegionKeyE23  */
    volatile uint32_t RKEYE24;                   /* RegionKeyE24  */
    volatile uint32_t RKEYE25;                   /* RegionKeyE25  */
    volatile uint32_t RKEYE26;                   /* RegionKeyE26  */
    volatile uint32_t RKEYE27;                   /* RegionKeyE27  */
    volatile uint32_t RKEYEP20;                  /* RegionKeyEP20  */
    volatile uint32_t RKEYEP21;                  /* RegionKeyEP21  */
    volatile uint32_t RKEYEP22;                  /* RegionKeyEP22  */
    volatile uint32_t RKEYEP23;                  /* RegionKeyEP23  */
    volatile uint32_t RKEYEP24;                  /* RegionKeyEP24  */
    volatile uint32_t RKEYEP25;                  /* RegionKeyEP25  */
    volatile uint32_t RKEYEP26;                  /* RegionKeyEP26  */
    volatile uint32_t RKEYEP27;                  /* RegionKeyEP27  */
    volatile uint32_t RKEYA20;                   /* RegionKeyA20  */
    volatile uint32_t RKEYA21;                   /* RegionKeyA21  */
    volatile uint32_t RKEYA22;                   /* RegionKeyA22  */
    volatile uint32_t RKEYA23;                   /* RegionKeyA23  */
    volatile uint32_t RKEYAP20;                  /* RegionKeyAP20  */
    volatile uint32_t RKEYAP21;                  /* RegionKeyAP21  */
    volatile uint32_t RKEYAP22;                  /* RegionKeyAP22  */
    volatile uint32_t RKEYAP23;                  /* RegionKeyAP23  */
    volatile uint32_t RIV20;                     /* RegionIV20  */
    volatile uint32_t RIV21;                     /* RegionIV21  */
    volatile uint32_t RIV22;                     /* RegionIV22  */
    volatile uint32_t RIV23;                     /* RegionIV23  */
    volatile uint32_t RGCFG3;                    /* RegionCfg3  */
    volatile uint32_t RGMACST3;                  /* RegionMacStart3  */
    volatile uint32_t RGST3;                     /* RegionStart3  */
    volatile uint32_t RGSI3;                     /* RegionSize3  */
    volatile uint32_t RKEYE30;                   /* RegionKeyE30  */
    volatile uint32_t RKEYE31;                   /* RegionKeyE31  */
    volatile uint32_t RKEYE32;                   /* RegionKeyE32  */
    volatile uint32_t RKEYE33;                   /* RegionKeyE33  */
    volatile uint32_t RKEYE34;                   /* RegionKeyE34  */
    volatile uint32_t RKEYE35;                   /* RegionKeyE35  */
    volatile uint32_t RKEYE36;                   /* RegionKeyE36  */
    volatile uint32_t RKEYE37;                   /* RegionKeyE37  */
    volatile uint32_t RKEYEP30;                  /* RegionKeyEP30  */
    volatile uint32_t RKEYEP31;                  /* RegionKeyEP31  */
    volatile uint32_t RKEYEP32;                  /* RegionKeyEP32  */
    volatile uint32_t RKEYEP33;                  /* RegionKeyEP33  */
    volatile uint32_t RKEYEP34;                  /* RegionKeyEP34  */
    volatile uint32_t RKEYEP35;                  /* RegionKeyEP35  */
    volatile uint32_t RKEYEP36;                  /* RegionKeyEP36  */
    volatile uint32_t RKEYEP37;                  /* RegionKeyEP37  */
    volatile uint32_t RKEYA30;                   /* RegionKeyA30  */
    volatile uint32_t RKEYA31;                   /* RegionKeyA31  */
    volatile uint32_t RKEYA32;                   /* RegionKeyA32  */
    volatile uint32_t RKEYA33;                   /* RegionKeyA33  */
    volatile uint32_t RKEYAP30;                  /* RegionKeyAP30  */
    volatile uint32_t RKEYAP31;                  /* RegionKeyAP31  */
    volatile uint32_t RKEYAP32;                  /* RegionKeyAP32  */
    volatile uint32_t RKEYAP33;                  /* RegionKeyAP33  */
    volatile uint32_t RIV30;                     /* RegionIV30  */
    volatile uint32_t RIV31;                     /* RegionIV31  */
    volatile uint32_t RIV32;                     /* RegionIV32  */
    volatile uint32_t RIV33;                     /* RegionIV33  */
    volatile uint32_t IRQADDINFO0;               /* IRQAdditionalInfo0  */
    volatile uint32_t IRQADDINFO1;               /* IRQAdditionalInfo1  */
    volatile uint32_t MACCACHEINFO;              /* MACCacheInfo  */
    volatile uint32_t RMWRMCNT;                  /* RMWRMCnt  */
} CSL_fss_fsas_otfa_regsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_FSAS_OTFA_REGS_REVID                                               (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_SCFG                                                (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR                                                 (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_IS                                                  (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_IES                                                 (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC                                                 (0x00000014U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG                                                (0x00000018U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS                                             (0x0000001CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0                                              (0x00000020U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST0                                            (0x00000024U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST0                                               (0x00000028U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI0                                               (0x0000002CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE00                                             (0x00000030U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE01                                             (0x00000034U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE02                                             (0x00000038U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE03                                             (0x0000003CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE04                                             (0x00000040U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE05                                             (0x00000044U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE06                                             (0x00000048U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE07                                             (0x0000004CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP00                                            (0x00000050U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP01                                            (0x00000054U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP02                                            (0x00000058U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP03                                            (0x0000005CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP04                                            (0x00000060U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP05                                            (0x00000064U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP06                                            (0x00000068U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP07                                            (0x0000006CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA00                                             (0x00000070U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA01                                             (0x00000074U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA02                                             (0x00000078U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA03                                             (0x0000007CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP00                                            (0x00000080U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP01                                            (0x00000084U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP02                                            (0x00000088U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP03                                            (0x0000008CU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV00                                               (0x00000090U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV01                                               (0x00000094U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV02                                               (0x00000098U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV03                                               (0x0000009CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1                                              (0x000000A0U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST1                                            (0x000000A4U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST1                                               (0x000000A8U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI1                                               (0x000000ACU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE10                                             (0x000000B0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE11                                             (0x000000B4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE12                                             (0x000000B8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE13                                             (0x000000BCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE14                                             (0x000000C0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE15                                             (0x000000C4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE16                                             (0x000000C8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE17                                             (0x000000CCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP10                                            (0x000000D0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP11                                            (0x000000D4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP12                                            (0x000000D8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP13                                            (0x000000DCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP14                                            (0x000000E0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP15                                            (0x000000E4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP16                                            (0x000000E8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP17                                            (0x000000ECU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA10                                             (0x000000F0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA11                                             (0x000000F4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA12                                             (0x000000F8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA13                                             (0x000000FCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP10                                            (0x00000100U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP11                                            (0x00000104U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP12                                            (0x00000108U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP13                                            (0x0000010CU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV10                                               (0x00000110U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV11                                               (0x00000114U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV12                                               (0x00000118U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV13                                               (0x0000011CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2                                              (0x00000120U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST2                                            (0x00000124U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST2                                               (0x00000128U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI2                                               (0x0000012CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE20                                             (0x00000130U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE21                                             (0x00000134U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE22                                             (0x00000138U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE23                                             (0x0000013CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE24                                             (0x00000140U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE25                                             (0x00000144U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE26                                             (0x00000148U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE27                                             (0x0000014CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP20                                            (0x00000150U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP21                                            (0x00000154U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP22                                            (0x00000158U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP23                                            (0x0000015CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP24                                            (0x00000160U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP25                                            (0x00000164U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP26                                            (0x00000168U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP27                                            (0x0000016CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA20                                             (0x00000170U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA21                                             (0x00000174U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA22                                             (0x00000178U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA23                                             (0x0000017CU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP20                                            (0x00000180U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP21                                            (0x00000184U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP22                                            (0x00000188U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP23                                            (0x0000018CU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV20                                               (0x00000190U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV21                                               (0x00000194U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV22                                               (0x00000198U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV23                                               (0x0000019CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3                                              (0x000001A0U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST3                                            (0x000001A4U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST3                                               (0x000001A8U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI3                                               (0x000001ACU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE30                                             (0x000001B0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE31                                             (0x000001B4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE32                                             (0x000001B8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE33                                             (0x000001BCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE34                                             (0x000001C0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE35                                             (0x000001C4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE36                                             (0x000001C8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE37                                             (0x000001CCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP30                                            (0x000001D0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP31                                            (0x000001D4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP32                                            (0x000001D8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP33                                            (0x000001DCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP34                                            (0x000001E0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP35                                            (0x000001E4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP36                                            (0x000001E8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP37                                            (0x000001ECU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA30                                             (0x000001F0U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA31                                             (0x000001F4U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA32                                             (0x000001F8U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA33                                             (0x000001FCU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP30                                            (0x00000200U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP31                                            (0x00000204U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP32                                            (0x00000208U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP33                                            (0x0000020CU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV30                                               (0x00000210U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV31                                               (0x00000214U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV32                                               (0x00000218U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV33                                               (0x0000021CU)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO0                                         (0x00000220U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1                                         (0x00000224U)
#define CSL_FSS_FSAS_OTFA_REGS_MACCACHEINFO                                        (0x00000228U)
#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT                                            (0x0000022CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REVID */

#define CSL_FSS_FSAS_OTFA_REGS_REVID_REVID_MASK                                    (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_REVID_REVID_SHIFT                                   (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_REVID_REVID_MAX                                     (0xFFFFFFFFU)

/* SCFG */

#define CSL_FSS_FSAS_OTFA_REGS_SCFG_IDLE_MODE_MASK                                 (0x00000003U)
#define CSL_FSS_FSAS_OTFA_REGS_SCFG_IDLE_MODE_SHIFT                                (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_SCFG_IDLE_MODE_MAX                                  (0x00000003U)

/* ISR */

#define CSL_FSS_FSAS_OTFA_REGS_ISR_CTR_WKV_MASK                                    (0x0000000FU)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_CTR_WKV_SHIFT                                   (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_CTR_WKV_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_ISR_REGION_BV_MASK                                  (0x000000F0U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_REGION_BV_SHIFT                                 (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_REGION_BV_MAX                                   (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_ISR_WRT_ERR_MASK                                    (0x00000F00U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_WRT_ERR_SHIFT                                   (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_WRT_ERR_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_ISR_MAC_ERR_MASK                                    (0x0000F000U)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_MAC_ERR_SHIFT                                   (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_ISR_MAC_ERR_MAX                                     (0x0000000FU)

/* IS */

#define CSL_FSS_FSAS_OTFA_REGS_IS_CTR_WKV_MASK                                     (0x0000000FU)
#define CSL_FSS_FSAS_OTFA_REGS_IS_CTR_WKV_SHIFT                                    (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_CTR_WKV_MAX                                      (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IS_REGION_BV_MASK                                   (0x000000F0U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_REGION_BV_SHIFT                                  (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_REGION_BV_MAX                                    (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IS_WRT_ERR_MASK                                     (0x00000F00U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_WRT_ERR_SHIFT                                    (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_WRT_ERR_MAX                                      (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IS_MAC_ERR_MASK                                     (0x0000F000U)
#define CSL_FSS_FSAS_OTFA_REGS_IS_MAC_ERR_SHIFT                                    (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_IS_MAC_ERR_MAX                                      (0x0000000FU)

/* IES */

#define CSL_FSS_FSAS_OTFA_REGS_IES_CTR_WKV_MASK                                    (0x0000000FU)
#define CSL_FSS_FSAS_OTFA_REGS_IES_CTR_WKV_SHIFT                                   (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_CTR_WKV_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IES_REGION_BV_MASK                                  (0x000000F0U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_REGION_BV_SHIFT                                 (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_REGION_BV_MAX                                   (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IES_WRT_ERR_MASK                                    (0x00000F00U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_WRT_ERR_SHIFT                                   (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_WRT_ERR_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IES_MAC_ERR_MASK                                    (0x0000F000U)
#define CSL_FSS_FSAS_OTFA_REGS_IES_MAC_ERR_SHIFT                                   (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_IES_MAC_ERR_MAX                                     (0x0000000FU)

/* IEC */

#define CSL_FSS_FSAS_OTFA_REGS_IEC_CTR_WKV_MASK                                    (0x0000000FU)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_CTR_WKV_SHIFT                                   (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_CTR_WKV_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IEC_REGION_BV_MASK                                  (0x000000F0U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_REGION_BV_SHIFT                                 (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_REGION_BV_MAX                                   (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IEC_WRT_ERR_MASK                                    (0x00000F00U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_WRT_ERR_SHIFT                                   (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_WRT_ERR_MAX                                     (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_IEC_MAC_ERR_MASK                                    (0x0000F000U)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_MAC_ERR_SHIFT                                   (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_IEC_MAC_ERR_MAX                                     (0x0000000FU)

/* CCFG */

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_RD_WRT_OPT_MASK                                (0x0000000FU)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_RD_WRT_OPT_SHIFT                               (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_RD_WRT_OPT_MAX                                 (0x0000000FU)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_KEY_SIZE_MASK                                  (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_KEY_SIZE_SHIFT                                 (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_KEY_SIZE_MAX                                   (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_EVICT_MODE_MASK                          (0x00000020U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_EVICT_MODE_SHIFT                         (0x00000005U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_EVICT_MODE_MAX                           (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_ENABLE_MASK                              (0x00000040U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_ENABLE_SHIFT                             (0x00000006U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_CACHE_ENABLE_MAX                               (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_OTFA_WAIT_MASK                                 (0x00000100U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_OTFA_WAIT_SHIFT                                (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_OTFA_WAIT_MAX                                  (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_ERROR_RESP_EN_MASK                             (0x00000200U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_ERROR_RESP_EN_SHIFT                            (0x00000009U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_ERROR_RESP_EN_MAX                              (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD_MASK                              (0x80000000U)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD_SHIFT                             (0x0000001FU)
#define CSL_FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD_MAX                               (0x00000001U)

/* CSTATUS */

#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_WRT_STALL_EVENT_CNT_MASK                    (0x00003FFFU)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_WRT_STALL_EVENT_CNT_SHIFT                   (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_WRT_STALL_EVENT_CNT_MAX                     (0x00003FFFU)

#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_RD_STALL_EVENT_CNT_MASK                     (0x3FFF0000U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_RD_STALL_EVENT_CNT_SHIFT                    (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_RD_STALL_EVENT_CNT_MAX                      (0x00003FFFU)

#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_CRYPTO_BUSY_MASK                            (0x40000000U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_CRYPTO_BUSY_SHIFT                           (0x0000001EU)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_CRYPTO_BUSY_MAX                             (0x00000001U)

#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_BUSY_MASK                                   (0x80000000U)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_BUSY_SHIFT                                  (0x0000001FU)
#define CSL_FSS_FSAS_OTFA_REGS_CSTATUS_BUSY_MAX                                    (0x00000001U)

/* RGCFG0 */

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_AES_MODE0_MASK                               (0x00000003U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_AES_MODE0_SHIFT                              (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_AES_MODE0_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_MAC_MODE0_MASK                               (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_MAC_MODE0_SHIFT                              (0x00000002U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_MAC_MODE0_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_WRT_PROTECT0_MASK                            (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_WRT_PROTECT0_SHIFT                           (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG0_WRT_PROTECT0_MAX                             (0x00000001U)

/* RGMACST0 */

#define CSL_FSS_FSAS_OTFA_REGS_RGMACST0_M_START0_MASK                              (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST0_M_START0_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST0_M_START0_MAX                               (0x000FFFFFU)

/* RGST0 */

#define CSL_FSS_FSAS_OTFA_REGS_RGST0_R_START0_MASK                                 (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGST0_R_START0_SHIFT                                (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST0_R_START0_MAX                                  (0x000FFFFFU)

/* RGSI0 */

#define CSL_FSS_FSAS_OTFA_REGS_RGSI0_R_SIZE0_MASK                                  (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI0_R_SIZE0_SHIFT                                 (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI0_R_SIZE0_MAX                                   (0x000FFFFFU)

/* RKEYE00 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE00_R_KEY_E00_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE00_R_KEY_E00_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE00_R_KEY_E00_MAX                               (0xFFFFFFFFU)

/* RKEYE01 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE01_R_KEY_E01_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE01_R_KEY_E01_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE01_R_KEY_E01_MAX                               (0xFFFFFFFFU)

/* RKEYE02 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE02_R_KEY_E02_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE02_R_KEY_E02_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE02_R_KEY_E02_MAX                               (0xFFFFFFFFU)

/* RKEYE03 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE03_R_KEY_E03_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE03_R_KEY_E03_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE03_R_KEY_E03_MAX                               (0xFFFFFFFFU)

/* RKEYE04 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE04_R_KEY_E04_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE04_R_KEY_E04_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE04_R_KEY_E04_MAX                               (0xFFFFFFFFU)

/* RKEYE05 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE05_R_KEY_E05_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE05_R_KEY_E05_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE05_R_KEY_E05_MAX                               (0xFFFFFFFFU)

/* RKEYE06 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE06_R_KEY_E06_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE06_R_KEY_E06_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE06_R_KEY_E06_MAX                               (0xFFFFFFFFU)

/* RKEYE07 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE07_R_KEY_E07_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE07_R_KEY_E07_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE07_R_KEY_E07_MAX                               (0xFFFFFFFFU)

/* RKEYEP00 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP00_R_KEY_EP00_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP00_R_KEY_EP00_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP00_R_KEY_EP00_MAX                             (0xFFFFFFFFU)

/* RKEYEP01 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP01_R_KEY_EP01_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP01_R_KEY_EP01_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP01_R_KEY_EP01_MAX                             (0xFFFFFFFFU)

/* RKEYEP02 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP02_R_KEY_EP02_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP02_R_KEY_EP02_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP02_R_KEY_EP02_MAX                             (0xFFFFFFFFU)

/* RKEYEP03 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP03_R_KEY_EP03_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP03_R_KEY_EP03_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP03_R_KEY_EP03_MAX                             (0xFFFFFFFFU)

/* RKEYEP04 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP04_R_KEY_EP04_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP04_R_KEY_EP04_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP04_R_KEY_EP04_MAX                             (0xFFFFFFFFU)

/* RKEYEP05 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP05_R_KEY_EP05_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP05_R_KEY_EP05_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP05_R_KEY_EP05_MAX                             (0xFFFFFFFFU)

/* RKEYEP06 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP06_R_KEY_EP06_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP06_R_KEY_EP06_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP06_R_KEY_EP06_MAX                             (0xFFFFFFFFU)

/* RKEYEP07 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP07_R_KEY_EP07_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP07_R_KEY_EP07_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP07_R_KEY_EP07_MAX                             (0xFFFFFFFFU)

/* RKEYA00 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA00_R_KEY_A00_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA00_R_KEY_A00_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA00_R_KEY_A00_MAX                               (0xFFFFFFFFU)

/* RKEYA01 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA01_R_KEY_A01_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA01_R_KEY_A01_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA01_R_KEY_A01_MAX                               (0xFFFFFFFFU)

/* RKEYA02 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA02_R_KEY_A02_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA02_R_KEY_A02_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA02_R_KEY_A02_MAX                               (0xFFFFFFFFU)

/* RKEYA03 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA03_R_KEY_A03_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA03_R_KEY_A03_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA03_R_KEY_A03_MAX                               (0xFFFFFFFFU)

/* RKEYAP00 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP00_R_KEY_AP00_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP00_R_KEY_AP00_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP00_R_KEY_AP00_MAX                             (0xFFFFFFFFU)

/* RKEYAP01 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP01_R_KEY_AP01_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP01_R_KEY_AP01_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP01_R_KEY_AP01_MAX                             (0xFFFFFFFFU)

/* RKEYAP02 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP02_R_KEY_AP02_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP02_R_KEY_AP02_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP02_R_KEY_AP02_MAX                             (0xFFFFFFFFU)

/* RKEYAP03 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP03_R_KEY_AP03_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP03_R_KEY_AP03_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP03_R_KEY_AP03_MAX                             (0xFFFFFFFFU)

/* RIV00 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV00_R_IV00_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV00_R_IV00_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV00_R_IV00_MAX                                    (0xFFFFFFFFU)

/* RIV01 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV01_R_IV01_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV01_R_IV01_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV01_R_IV01_MAX                                    (0xFFFFFFFFU)

/* RIV02 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV02_R_IV02_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV02_R_IV02_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV02_R_IV02_MAX                                    (0xFFFFFFFFU)

/* RIV03 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV03_R_IV03_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV03_R_IV03_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV03_R_IV03_MAX                                    (0xFFFFFFFFU)

/* RGCFG1 */

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_AES_MODE1_MASK                               (0x00000003U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_AES_MODE1_SHIFT                              (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_AES_MODE1_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_MAC_MODE1_MASK                               (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_MAC_MODE1_SHIFT                              (0x00000002U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_MAC_MODE1_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_WRT_PROTECT1_MASK                            (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_WRT_PROTECT1_SHIFT                           (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG1_WRT_PROTECT1_MAX                             (0x00000001U)

/* RGMACST1 */

#define CSL_FSS_FSAS_OTFA_REGS_RGMACST1_M_START1_MASK                              (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST1_M_START1_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST1_M_START1_MAX                               (0x000FFFFFU)

/* RGST1 */

#define CSL_FSS_FSAS_OTFA_REGS_RGST1_R_START1_MASK                                 (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGST1_R_START1_SHIFT                                (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST1_R_START1_MAX                                  (0x000FFFFFU)

/* RGSI1 */

#define CSL_FSS_FSAS_OTFA_REGS_RGSI1_R_SIZE1_MASK                                  (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI1_R_SIZE1_SHIFT                                 (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI1_R_SIZE1_MAX                                   (0x000FFFFFU)

/* RKEYE10 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE10_R_KEY_E10_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE10_R_KEY_E10_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE10_R_KEY_E10_MAX                               (0xFFFFFFFFU)

/* RKEYE11 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE11_R_KEY_E11_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE11_R_KEY_E11_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE11_R_KEY_E11_MAX                               (0xFFFFFFFFU)

/* RKEYE12 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE12_R_KEY_E12_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE12_R_KEY_E12_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE12_R_KEY_E12_MAX                               (0xFFFFFFFFU)

/* RKEYE13 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE13_R_KEY_E13_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE13_R_KEY_E13_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE13_R_KEY_E13_MAX                               (0xFFFFFFFFU)

/* RKEYE14 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE14_R_KEY_E14_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE14_R_KEY_E14_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE14_R_KEY_E14_MAX                               (0xFFFFFFFFU)

/* RKEYE15 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE15_R_KEY_E15_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE15_R_KEY_E15_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE15_R_KEY_E15_MAX                               (0xFFFFFFFFU)

/* RKEYE16 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE16_R_KEY_E16_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE16_R_KEY_E16_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE16_R_KEY_E16_MAX                               (0xFFFFFFFFU)

/* RKEYE17 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE17_R_KEY_E17_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE17_R_KEY_E17_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE17_R_KEY_E17_MAX                               (0xFFFFFFFFU)

/* RKEYEP10 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP10_R_KEY_EP10_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP10_R_KEY_EP10_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP10_R_KEY_EP10_MAX                             (0xFFFFFFFFU)

/* RKEYEP11 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP11_R_KEY_EP11_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP11_R_KEY_EP11_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP11_R_KEY_EP11_MAX                             (0xFFFFFFFFU)

/* RKEYEP12 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP12_R_KEY_EP12_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP12_R_KEY_EP12_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP12_R_KEY_EP12_MAX                             (0xFFFFFFFFU)

/* RKEYEP13 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP13_R_KEY_EP13_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP13_R_KEY_EP13_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP13_R_KEY_EP13_MAX                             (0xFFFFFFFFU)

/* RKEYEP14 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP14_R_KEY_EP14_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP14_R_KEY_EP14_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP14_R_KEY_EP14_MAX                             (0xFFFFFFFFU)

/* RKEYEP15 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP15_R_KEY_EP15_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP15_R_KEY_EP15_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP15_R_KEY_EP15_MAX                             (0xFFFFFFFFU)

/* RKEYEP16 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP16_R_KEY_EP16_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP16_R_KEY_EP16_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP16_R_KEY_EP16_MAX                             (0xFFFFFFFFU)

/* RKEYEP17 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP17_R_KEY_EP17_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP17_R_KEY_EP17_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP17_R_KEY_EP17_MAX                             (0xFFFFFFFFU)

/* RKEYA10 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA10_R_KEY_A10_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA10_R_KEY_A10_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA10_R_KEY_A10_MAX                               (0xFFFFFFFFU)

/* RKEYA11 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA11_R_KEY_A11_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA11_R_KEY_A11_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA11_R_KEY_A11_MAX                               (0xFFFFFFFFU)

/* RKEYA12 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA12_R_KEY_A12_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA12_R_KEY_A12_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA12_R_KEY_A12_MAX                               (0xFFFFFFFFU)

/* RKEYA13 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA13_R_KEY_A13_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA13_R_KEY_A13_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA13_R_KEY_A13_MAX                               (0xFFFFFFFFU)

/* RKEYAP10 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP10_R_KEY_AP10_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP10_R_KEY_AP10_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP10_R_KEY_AP10_MAX                             (0xFFFFFFFFU)

/* RKEYAP11 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP11_R_KEY_AP11_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP11_R_KEY_AP11_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP11_R_KEY_AP11_MAX                             (0xFFFFFFFFU)

/* RKEYAP12 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP12_R_KEY_AP12_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP12_R_KEY_AP12_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP12_R_KEY_AP12_MAX                             (0xFFFFFFFFU)

/* RKEYAP13 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP13_R_KEY_AP13_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP13_R_KEY_AP13_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP13_R_KEY_AP13_MAX                             (0xFFFFFFFFU)

/* RIV10 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV10_R_IV10_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV10_R_IV10_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV10_R_IV10_MAX                                    (0xFFFFFFFFU)

/* RIV11 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV11_R_IV11_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV11_R_IV11_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV11_R_IV11_MAX                                    (0xFFFFFFFFU)

/* RIV12 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV12_R_IV12_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV12_R_IV12_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV12_R_IV12_MAX                                    (0xFFFFFFFFU)

/* RIV13 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV13_R_IV13_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV13_R_IV13_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV13_R_IV13_MAX                                    (0xFFFFFFFFU)

/* RGCFG2 */

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_AES_MODE2_MASK                               (0x00000003U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_AES_MODE2_SHIFT                              (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_AES_MODE2_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_MAC_MODE2_MASK                               (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_MAC_MODE2_SHIFT                              (0x00000002U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_MAC_MODE2_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_WRT_PROTECT2_MASK                            (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_WRT_PROTECT2_SHIFT                           (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG2_WRT_PROTECT2_MAX                             (0x00000001U)

/* RGMACST2 */

#define CSL_FSS_FSAS_OTFA_REGS_RGMACST2_M_START2_MASK                              (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST2_M_START2_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST2_M_START2_MAX                               (0x000FFFFFU)

/* RGST2 */

#define CSL_FSS_FSAS_OTFA_REGS_RGST2_R_START2_MASK                                 (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGST2_R_START2_SHIFT                                (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST2_R_START2_MAX                                  (0x000FFFFFU)

/* RGSI2 */

#define CSL_FSS_FSAS_OTFA_REGS_RGSI2_R_SIZE2_MASK                                  (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI2_R_SIZE2_SHIFT                                 (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI2_R_SIZE2_MAX                                   (0x000FFFFFU)

/* RKEYE20 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE20_R_KEY_E20_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE20_R_KEY_E20_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE20_R_KEY_E20_MAX                               (0xFFFFFFFFU)

/* RKEYE21 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE21_R_KEY_E21_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE21_R_KEY_E21_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE21_R_KEY_E21_MAX                               (0xFFFFFFFFU)

/* RKEYE22 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE22_R_KEY_E22_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE22_R_KEY_E22_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE22_R_KEY_E22_MAX                               (0xFFFFFFFFU)

/* RKEYE23 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE23_R_KEY_E23_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE23_R_KEY_E23_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE23_R_KEY_E23_MAX                               (0xFFFFFFFFU)

/* RKEYE24 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE24_R_KEY_E24_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE24_R_KEY_E24_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE24_R_KEY_E24_MAX                               (0xFFFFFFFFU)

/* RKEYE25 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE25_R_KEY_E25_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE25_R_KEY_E25_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE25_R_KEY_E25_MAX                               (0xFFFFFFFFU)

/* RKEYE26 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE26_R_KEY_E26_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE26_R_KEY_E26_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE26_R_KEY_E26_MAX                               (0xFFFFFFFFU)

/* RKEYE27 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE27_R_KEY_E27_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE27_R_KEY_E27_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE27_R_KEY_E27_MAX                               (0xFFFFFFFFU)

/* RKEYEP20 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP20_R_KEY_EP20_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP20_R_KEY_EP20_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP20_R_KEY_EP20_MAX                             (0xFFFFFFFFU)

/* RKEYEP21 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP21_R_KEY_EP21_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP21_R_KEY_EP21_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP21_R_KEY_EP21_MAX                             (0xFFFFFFFFU)

/* RKEYEP22 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP22_R_KEY_EP22_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP22_R_KEY_EP22_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP22_R_KEY_EP22_MAX                             (0xFFFFFFFFU)

/* RKEYEP23 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP23_R_KEY_EP23_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP23_R_KEY_EP23_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP23_R_KEY_EP23_MAX                             (0xFFFFFFFFU)

/* RKEYEP24 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP24_R_KEY_EP24_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP24_R_KEY_EP24_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP24_R_KEY_EP24_MAX                             (0xFFFFFFFFU)

/* RKEYEP25 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP25_R_KEY_EP25_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP25_R_KEY_EP25_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP25_R_KEY_EP25_MAX                             (0xFFFFFFFFU)

/* RKEYEP26 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP26_R_KEY_EP26_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP26_R_KEY_EP26_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP26_R_KEY_EP26_MAX                             (0xFFFFFFFFU)

/* RKEYEP27 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP27_R_KEY_EP27_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP27_R_KEY_EP27_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP27_R_KEY_EP27_MAX                             (0xFFFFFFFFU)

/* RKEYA20 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA20_R_KEY_A20_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA20_R_KEY_A20_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA20_R_KEY_A20_MAX                               (0xFFFFFFFFU)

/* RKEYA21 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA21_R_KEY_A21_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA21_R_KEY_A21_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA21_R_KEY_A21_MAX                               (0xFFFFFFFFU)

/* RKEYA22 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA22_R_KEY_A22_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA22_R_KEY_A22_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA22_R_KEY_A22_MAX                               (0xFFFFFFFFU)

/* RKEYA23 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA23_R_KEY_A23_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA23_R_KEY_A23_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA23_R_KEY_A23_MAX                               (0xFFFFFFFFU)

/* RKEYAP20 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP20_R_KEY_AP20_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP20_R_KEY_AP20_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP20_R_KEY_AP20_MAX                             (0xFFFFFFFFU)

/* RKEYAP21 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP21_R_KEY_AP21_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP21_R_KEY_AP21_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP21_R_KEY_AP21_MAX                             (0xFFFFFFFFU)

/* RKEYAP22 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP22_R_KEY_AP22_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP22_R_KEY_AP22_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP22_R_KEY_AP22_MAX                             (0xFFFFFFFFU)

/* RKEYAP23 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP23_R_KEY_AP23_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP23_R_KEY_AP23_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP23_R_KEY_AP23_MAX                             (0xFFFFFFFFU)

/* RIV20 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV20_R_IV20_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV20_R_IV20_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV20_R_IV20_MAX                                    (0xFFFFFFFFU)

/* RIV21 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV21_R_IV21_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV21_R_IV21_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV21_R_IV21_MAX                                    (0xFFFFFFFFU)

/* RIV22 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV22_R_IV22_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV22_R_IV22_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV22_R_IV22_MAX                                    (0xFFFFFFFFU)

/* RIV23 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV23_R_IV23_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV23_R_IV23_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV23_R_IV23_MAX                                    (0xFFFFFFFFU)

/* RGCFG3 */

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_AES_MODE3_MASK                               (0x00000003U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_AES_MODE3_SHIFT                              (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_AES_MODE3_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_MAC_MODE3_MASK                               (0x0000000CU)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_MAC_MODE3_SHIFT                              (0x00000002U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_MAC_MODE3_MAX                                (0x00000003U)

#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_WRT_PROTECT3_MASK                            (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_WRT_PROTECT3_SHIFT                           (0x00000004U)
#define CSL_FSS_FSAS_OTFA_REGS_RGCFG3_WRT_PROTECT3_MAX                             (0x00000001U)

/* RGMACST3 */

#define CSL_FSS_FSAS_OTFA_REGS_RGMACST3_M_START3_MASK                              (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST3_M_START3_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGMACST3_M_START3_MAX                               (0x000FFFFFU)

/* RGST3 */

#define CSL_FSS_FSAS_OTFA_REGS_RGST3_R_START3_MASK                                 (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGST3_R_START3_SHIFT                                (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGST3_R_START3_MAX                                  (0x000FFFFFU)

/* RGSI3 */

#define CSL_FSS_FSAS_OTFA_REGS_RGSI3_R_SIZE3_MASK                                  (0x000FFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI3_R_SIZE3_SHIFT                                 (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RGSI3_R_SIZE3_MAX                                   (0x000FFFFFU)

/* RKEYE30 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE30_R_KEY_E30_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE30_R_KEY_E30_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE30_R_KEY_E30_MAX                               (0xFFFFFFFFU)

/* RKEYE31 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE31_R_KEY_E31_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE31_R_KEY_E31_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE31_R_KEY_E31_MAX                               (0xFFFFFFFFU)

/* RKEYE32 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE32_R_KEY_E32_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE32_R_KEY_E32_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE32_R_KEY_E32_MAX                               (0xFFFFFFFFU)

/* RKEYE33 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE33_R_KEY_E33_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE33_R_KEY_E33_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE33_R_KEY_E33_MAX                               (0xFFFFFFFFU)

/* RKEYE34 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE34_R_KEY_E34_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE34_R_KEY_E34_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE34_R_KEY_E34_MAX                               (0xFFFFFFFFU)

/* RKEYE35 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE35_R_KEY_E35_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE35_R_KEY_E35_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE35_R_KEY_E35_MAX                               (0xFFFFFFFFU)

/* RKEYE36 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE36_R_KEY_E36_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE36_R_KEY_E36_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE36_R_KEY_E36_MAX                               (0xFFFFFFFFU)

/* RKEYE37 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYE37_R_KEY_E37_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE37_R_KEY_E37_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYE37_R_KEY_E37_MAX                               (0xFFFFFFFFU)

/* RKEYEP30 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP30_R_KEY_EP30_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP30_R_KEY_EP30_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP30_R_KEY_EP30_MAX                             (0xFFFFFFFFU)

/* RKEYEP31 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP31_R_KEY_EP31_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP31_R_KEY_EP31_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP31_R_KEY_EP31_MAX                             (0xFFFFFFFFU)

/* RKEYEP32 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP32_R_KEY_EP32_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP32_R_KEY_EP32_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP32_R_KEY_EP32_MAX                             (0xFFFFFFFFU)

/* RKEYEP33 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP33_R_KEY_EP33_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP33_R_KEY_EP33_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP33_R_KEY_EP33_MAX                             (0xFFFFFFFFU)

/* RKEYEP34 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP34_R_KEY_EP34_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP34_R_KEY_EP34_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP34_R_KEY_EP34_MAX                             (0xFFFFFFFFU)

/* RKEYEP35 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP35_R_KEY_EP35_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP35_R_KEY_EP35_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP35_R_KEY_EP35_MAX                             (0xFFFFFFFFU)

/* RKEYEP36 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP36_R_KEY_EP36_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP36_R_KEY_EP36_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP36_R_KEY_EP36_MAX                             (0xFFFFFFFFU)

/* RKEYEP37 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP37_R_KEY_EP37_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP37_R_KEY_EP37_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYEP37_R_KEY_EP37_MAX                             (0xFFFFFFFFU)

/* RKEYA30 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA30_R_KEY_A30_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA30_R_KEY_A30_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA30_R_KEY_A30_MAX                               (0xFFFFFFFFU)

/* RKEYA31 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA31_R_KEY_A31_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA31_R_KEY_A31_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA31_R_KEY_A31_MAX                               (0xFFFFFFFFU)

/* RKEYA32 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA32_R_KEY_A32_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA32_R_KEY_A32_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA32_R_KEY_A32_MAX                               (0xFFFFFFFFU)

/* RKEYA33 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYA33_R_KEY_A33_MASK                              (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA33_R_KEY_A33_SHIFT                             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYA33_R_KEY_A33_MAX                               (0xFFFFFFFFU)

/* RKEYAP30 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP30_R_KEY_AP30_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP30_R_KEY_AP30_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP30_R_KEY_AP30_MAX                             (0xFFFFFFFFU)

/* RKEYAP31 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP31_R_KEY_AP31_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP31_R_KEY_AP31_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP31_R_KEY_AP31_MAX                             (0xFFFFFFFFU)

/* RKEYAP32 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP32_R_KEY_AP32_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP32_R_KEY_AP32_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP32_R_KEY_AP32_MAX                             (0xFFFFFFFFU)

/* RKEYAP33 */

#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP33_R_KEY_AP33_MASK                            (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP33_R_KEY_AP33_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RKEYAP33_R_KEY_AP33_MAX                             (0xFFFFFFFFU)

/* RIV30 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV30_R_IV30_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV30_R_IV30_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV30_R_IV30_MAX                                    (0xFFFFFFFFU)

/* RIV31 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV31_R_IV31_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV31_R_IV31_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV31_R_IV31_MAX                                    (0xFFFFFFFFU)

/* RIV32 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV32_R_IV32_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV32_R_IV32_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV32_R_IV32_MAX                                    (0xFFFFFFFFU)

/* RIV33 */

#define CSL_FSS_FSAS_OTFA_REGS_RIV33_R_IV33_MASK                                   (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RIV33_R_IV33_SHIFT                                  (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RIV33_R_IV33_MAX                                    (0xFFFFFFFFU)

/* IRQADDINFO0 */

#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO0_IRQ_MADDR_MASK                          (0xFFFFFFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO0_IRQ_MADDR_SHIFT                         (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO0_IRQ_MADDR_MAX                           (0xFFFFFFFFU)

/* IRQADDINFO1 */

#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MID_MASK                            (0x000000FFU)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MID_SHIFT                           (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MID_MAX                             (0x000000FFU)

#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MCMD_MASK                           (0x00000700U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MCMD_SHIFT                          (0x00000008U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MCMD_MAX                            (0x00000007U)

#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MSEQ_MASK                           (0x00003800U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MSEQ_SHIFT                          (0x0000000BU)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MSEQ_MAX                            (0x00000007U)

#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MLEN_MASK                           (0x0003C000U)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MLEN_SHIFT                          (0x0000000EU)
#define CSL_FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MLEN_MAX                            (0x0000000FU)

/* MACCACHEINFO */

#define CSL_FSS_FSAS_OTFA_REGS_MACCACHEINFO_CACHE_MISS_EVENT_CNT_MASK              (0x0000FFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_MACCACHEINFO_CACHE_MISS_EVENT_CNT_SHIFT             (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_MACCACHEINFO_CACHE_MISS_EVENT_CNT_MAX               (0x0000FFFFU)

/* RMWRMCNT */

#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RMW_EVENT_CNT_MASK                         (0x0000FFFFU)
#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RMW_EVENT_CNT_SHIFT                        (0x00000000U)
#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RMW_EVENT_CNT_MAX                          (0x0000FFFFU)

#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RM_EVENT_CNT_MASK                          (0xFFFF0000U)
#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RM_EVENT_CNT_SHIFT                         (0x00000010U)
#define CSL_FSS_FSAS_OTFA_REGS_RMWRMCNT_RM_EVENT_CNT_MAX                           (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : Global Control Registers, offset 0x00000000
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t EOI;                       /* IRQ_EOI */
    volatile uint32_t STATUS_RAW;                /* IRQ_STATUS_RAW */
    volatile uint32_t STATUS;                    /* IRQ_STATUS */
    volatile uint32_t ENABLE_SET;                /* IRQ_ENABLE_SET */
    volatile uint32_t ENABLE_CLR;                /* IRQ_ENABLE_CLR */
} CSL_fss_genregsRegs_IRQ;


typedef struct {
    volatile uint32_t ECC_RGSTRT;                /* RegionStart */
    volatile uint32_t ECC_RGSIZ;                 /* ECC RegionSize */
} CSL_fss_genregsRegs_ECC_REGCTRL;


typedef struct {
    volatile uint32_t ECC_BLOCK_ADR;             /* ERR_ECC_BLOCK_ADR */
    volatile uint32_t ECC_TYPE;                  /* ERR_ECC_TYPE */
    volatile uint32_t WRT_TYPE;                  /* ERR_WRT_TYPE */
    volatile uint8_t  Resv_16[4];
} CSL_fss_genregsRegs_ERR;


typedef struct {
    volatile uint32_t REVISION;                  /* REVISION */
    volatile uint32_t SYSCONFIG;                 /* SYSCONFIG */
    volatile uint8_t  Resv_16[8];
    CSL_fss_genregsRegs_IRQ IRQ;
    volatile uint8_t  Resv_48[12];
    CSL_fss_genregsRegs_ECC_REGCTRL ECC_REGCTRL[4];
    volatile uint8_t  Resv_112[32];
    CSL_fss_genregsRegs_ERR ERR;
} CSL_fss_genregsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_GENREGS_REVISION                                               (0x00000000U)
#define CSL_FSS_GENREGS_SYSCONFIG                                              (0x00000004U)
#define CSL_FSS_GENREGS_IRQ_EOI                                                (0x00000010U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW                                         (0x00000014U)
#define CSL_FSS_GENREGS_IRQ_STATUS                                             (0x00000018U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET                                         (0x0000001CU)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR                                         (0x00000020U)
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSTRT(ECC_REGCTRL)                    (0x00000030U+((ECC_REGCTRL)*0x8U))
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSIZ(ECC_REGCTRL)                     (0x00000034U+((ECC_REGCTRL)*0x8U))
#define CSL_FSS_GENREGS_ERR_ECC_BLOCK_ADR                                      (0x00000070U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE                                           (0x00000074U)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE                                           (0x00000078U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* EOI */

#define CSL_FSS_GENREGS_IRQ_EOI_EOI_VECTOR_MASK                                (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_EOI_EOI_VECTOR_SHIFT                               (0x00000000U)
#define CSL_FSS_GENREGS_IRQ_EOI_EOI_VECTOR_MAX                                 (0x00000001U)

/* STATUS_RAW */

#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_MASK                 (0x00000004U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_SHIFT                (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_WRITE_NONALIGN_MAX                  (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_MASK                     (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_SHIFT                    (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_2BIT_MAX                      (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_MASK                     (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_SHIFT                    (0x00000000U)
#define CSL_FSS_GENREGS_IRQ_STATUS_RAW_ECC_ERROR_1BIT_MAX                      (0x00000001U)

/* STATUS */

#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_MASK                     (0x00000004U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_SHIFT                    (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_WRITE_NONALIGN_MAX                      (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_MASK                         (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_SHIFT                        (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_2BIT_MAX                          (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_MASK                         (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_SHIFT                        (0x00000000U)
#define CSL_FSS_GENREGS_IRQ_STATUS_ECC_ERROR_1BIT_MAX                          (0x00000001U)

/* ENABLE_SET */

#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_MASK                 (0x00000004U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_SHIFT                (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_WRITE_NONALIGN_MAX                  (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_MASK                     (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_SHIFT                    (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_2BIT_MAX                      (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_MASK                     (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_SHIFT                    (0x00000000U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_SET_ECC_ERROR_1BIT_MAX                      (0x00000001U)

/* ENABLE_CLR */

#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_MASK                 (0x00000004U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_SHIFT                (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_WRITE_NONALIGN_MAX                  (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_MASK                     (0x00000002U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_SHIFT                    (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_2BIT_MAX                      (0x00000001U)

#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_MASK                     (0x00000001U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_SHIFT                    (0x00000000U)
#define CSL_FSS_GENREGS_IRQ_ENABLE_CLR_ECC_ERROR_1BIT_MAX                      (0x00000001U)

/* ECC_RGSTRT */

#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_MASK                    (0x000FFFFFU)
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_SHIFT                   (0x00000000U)
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START_MAX                     (0x000FFFFFU)

/* ECC_RGSIZ */

#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_MASK                      (0x000FFFFFU)
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_SHIFT                     (0x00000000U)
#define CSL_FSS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE_MAX                       (0x000FFFFFU)

/* ECC_BLOCK_ADR */

#define CSL_FSS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_MASK            (0xFFFFFFE0U)
#define CSL_FSS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_SHIFT           (0x00000005U)
#define CSL_FSS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR_MAX             (0x07FFFFFFU)

/* ECC_TYPE */

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_MASK                        (0x80000000U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_SHIFT                       (0x0000001FU)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID_MAX                         (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_MASK                          (0x00000020U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_SHIFT                         (0x00000005U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_MASK                          (0x00000010U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_SHIFT                         (0x00000004U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_MASK                          (0x00000008U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_SHIFT                         (0x00000003U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_MASK                          (0x00000004U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_SHIFT                         (0x00000002U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_MASK                          (0x00000002U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_SHIFT                         (0x00000001U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_MASK                          (0x00000001U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_SHIFT                         (0x00000000U)
#define CSL_FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC_MAX                           (0x00000001U)

/* WRT_TYPE */

#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_MASK                        (0x80000000U)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_SHIFT                       (0x0000001FU)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID_MAX                         (0x00000001U)

#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_MASK                          (0x00001000U)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_SHIFT                         (0x0000000CU)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_MASK                          (0x00002000U)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_SHIFT                         (0x0000000DU)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN_MAX                           (0x00000001U)

#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_MASK                      (0x00000FFFU)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_SHIFT                     (0x00000000U)
#define CSL_FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID_MAX                       (0x00000FFFU)

/* REVISION */

#define CSL_FSS_GENREGS_REVISION_MODID_MASK                                    (0xFFFF0000U)
#define CSL_FSS_GENREGS_REVISION_MODID_SHIFT                                   (0x00000010U)
#define CSL_FSS_GENREGS_REVISION_MODID_MAX                                     (0x0000FFFFU)

#define CSL_FSS_GENREGS_REVISION_REVRTL_MASK                                   (0x0000F800U)
#define CSL_FSS_GENREGS_REVISION_REVRTL_SHIFT                                  (0x0000000BU)
#define CSL_FSS_GENREGS_REVISION_REVRTL_MAX                                    (0x0000001FU)

#define CSL_FSS_GENREGS_REVISION_REVMAJ_MASK                                   (0x00000700U)
#define CSL_FSS_GENREGS_REVISION_REVMAJ_SHIFT                                  (0x00000008U)
#define CSL_FSS_GENREGS_REVISION_REVMAJ_MAX                                    (0x00000007U)

#define CSL_FSS_GENREGS_REVISION_CUSTOM_MASK                                   (0x000000C0U)
#define CSL_FSS_GENREGS_REVISION_CUSTOM_SHIFT                                  (0x00000006U)
#define CSL_FSS_GENREGS_REVISION_CUSTOM_MAX                                    (0x00000003U)

#define CSL_FSS_GENREGS_REVISION_REVMIN_MASK                                   (0x0000003FU)
#define CSL_FSS_GENREGS_REVISION_REVMIN_SHIFT                                  (0x00000000U)
#define CSL_FSS_GENREGS_REVISION_REVMIN_MAX                                    (0x0000003FU)

/* SYSCONFIG */

#define CSL_FSS_GENREGS_SYSCONFIG_DISXIP_MASK                                  (0x00000080U)
#define CSL_FSS_GENREGS_SYSCONFIG_DISXIP_SHIFT                                 (0x00000007U)
#define CSL_FSS_GENREGS_SYSCONFIG_DISXIP_MAX                                   (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_MASK                   (0x00000100U)
#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_SHIFT                  (0x00000008U)
#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_32B_DISABLE_MODE_MAX                    (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_MASK                   (0x00000040U)
#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_SHIFT                  (0x00000006U)
#define CSL_FSS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_MAX                    (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_MASK                         (0x00000008U)
#define CSL_FSS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_SHIFT                        (0x00000003U)
#define CSL_FSS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR_MAX                          (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_MASK                        (0x00000004U)
#define CSL_FSS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_SHIFT                       (0x00000002U)
#define CSL_FSS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG_MAX                         (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_HB_OSPI_MASK                                 (0x00000002U)
#define CSL_FSS_GENREGS_SYSCONFIG_HB_OSPI_SHIFT                                (0x00000001U)
#define CSL_FSS_GENREGS_SYSCONFIG_HB_OSPI_MAX                                  (0x00000001U)

#define CSL_FSS_GENREGS_SYSCONFIG_ECC_EN_MASK                                  (0x00000001U)
#define CSL_FSS_GENREGS_SYSCONFIG_ECC_EN_SHIFT                                 (0x00000000U)
#define CSL_FSS_GENREGS_SYSCONFIG_ECC_EN_MAX                                   (0x00000001U)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t OSPI_CORE_MEM[1];   /* OSPI Core memory. */
} CSL_fss_ospi_data_vbp_r0_mapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_OSPI_DATA_VBP_R0_MAP_OSPI_CORE_MEM(OSPI_CORE_MEM)            (0x00000000U+((OSPI_CORE_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* OSPI_CORE_MEM */

#define CSL_FSS_OSPI_DATA_VBP_R0_MAP_OSPI_CORE_MEM_OSPI_MEM_MASK             (0xFFFFFFFFU)
#define CSL_FSS_OSPI_DATA_VBP_R0_MAP_OSPI_CORE_MEM_OSPI_MEM_SHIFT            (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R0_MAP_OSPI_CORE_MEM_OSPI_MEM_MAX              (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t OSPI_CORE_MEM[1];   /* OSPI Core memory. */
} CSL_fss_ospi_data_vbp_r1_mapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_OSPI_DATA_VBP_R1_MAP_OSPI_CORE_MEM(OSPI_CORE_MEM)            (0x00000000U+((OSPI_CORE_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* OSPI_CORE_MEM */

#define CSL_FSS_OSPI_DATA_VBP_R1_MAP_OSPI_CORE_MEM_OSPI_MEM_MASK             (0xFFFFFFFFU)
#define CSL_FSS_OSPI_DATA_VBP_R1_MAP_OSPI_CORE_MEM_OSPI_MEM_SHIFT            (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R1_MAP_OSPI_CORE_MEM_OSPI_MEM_MAX              (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t OSPI_CORE_MEM[1];   /* OSPI Core memory. */
} CSL_fss_ospi_data_vbp_r3_mapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_OSPI_DATA_VBP_R3_MAP_OSPI_CORE_MEM(OSPI_CORE_MEM)            (0x00000000U+((OSPI_CORE_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* OSPI_CORE_MEM */

#define CSL_FSS_OSPI_DATA_VBP_R3_MAP_OSPI_CORE_MEM_OSPI_MEM_MASK             (0xFFFFFFFFU)
#define CSL_FSS_OSPI_DATA_VBP_R3_MAP_OSPI_CORE_MEM_OSPI_MEM_SHIFT            (0x00000000U)
#define CSL_FSS_OSPI_DATA_VBP_R3_MAP_OSPI_CORE_MEM_OSPI_MEM_MAX              (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : FSAS data region0
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t HPB_DATA_MEM[1];   /* FSAS data region0 */
} CSL_fss_dat_reg0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_DAT_REG0_HPB_DATA_MEM(HPB_DATA_MEM)                                (0x00000000U+((HPB_DATA_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* HPB_DATA_MEM */

#define CSL_FSS_DAT_REG0_HPB_DATA_MEM_HPB_DATA_MASK                                (0xFFFFFFFFU)
#define CSL_FSS_DAT_REG0_HPB_DATA_MEM_HPB_DATA_SHIFT                               (0x00000000U)
#define CSL_FSS_DAT_REG0_HPB_DATA_MEM_HPB_DATA_MAX                                 (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : FSAS data region1
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t HPB_DATA_MEM[1];   /* FSAS data region1 */
} CSL_fss_dat_reg1Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_DAT_REG1_HPB_DATA_MEM(HPB_DATA_MEM)                                (0x00000000U+((HPB_DATA_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* HPB_DATA_MEM */

#define CSL_FSS_DAT_REG1_HPB_DATA_MEM_HPB_DATA_MASK                                (0xFFFFFFFFU)
#define CSL_FSS_DAT_REG1_HPB_DATA_MEM_HPB_DATA_SHIFT                               (0x00000000U)
#define CSL_FSS_DAT_REG1_HPB_DATA_MEM_HPB_DATA_MAX                                 (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  : FSAS data region3
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t HPB_DATA_MEM[1];   /* FSAS data region3 */
} CSL_fss_dat_reg3Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_FSS_DAT_REG3_HPB_DATA_MEM(HPB_DATA_MEM)                                (0x00000000U+((HPB_DATA_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* HPB_DATA_MEM */

#define CSL_FSS_DAT_REG3_HPB_DATA_MEM_HPB_DATA_MASK                                (0xFFFFFFFFU)
#define CSL_FSS_DAT_REG3_HPB_DATA_MEM_HPB_DATA_SHIFT                               (0x00000000U)
#define CSL_FSS_DAT_REG3_HPB_DATA_MEM_HPB_DATA_MAX                                 (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
