/**
 * @file csl_gic.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the gic
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2017, Texas Instruments, Inc.
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
#ifndef CSL_GIC_H_
#define CSL_GIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_gic500.h>

/** \addtogroup CSL_GIC
 *  @{
 */

/** \brief GIC CSL_GicGrp0_t: Field value definitions for feature: Grp0 */
typedef enum {
	CSL_GIC_GRP0_DISABLED=0, /**< Disabled */
	CSL_GIC_GRP0_ENABLED=1, /**< Enabled */
	CSL_GIC_GRP0_DISABLE=0, /**< Disable */
	CSL_GIC_GRP0_ENABLE=1, /**< Enable */
} CSL_GicGrp0_t;

/** \brief GIC CSL_GicGrp1_NS_t: Field value definitions for feature: Grp1_NS */
typedef enum {
	CSL_GIC_GRP1_NS_DISABLED=0, /**< Disabled */
	CSL_GIC_GRP1_NS_ENABLED=1, /**< Enabled */
	CSL_GIC_GRP1_NS_DISABLE=0, /**< Disable */
	CSL_GIC_GRP1_NS_ENABLE=1, /**< Enable */
} CSL_GicGrp1_NS_t;

/** \brief GIC CSL_GicGrp1_S_t: Field value definitions for feature: Grp1_S */
typedef enum {
	CSL_GIC_GRP1_S_DISABLED=0, /**< Disabled */
	CSL_GIC_GRP1_S_ENABLED=1, /**< Enabled */
	CSL_GIC_GRP1_S_DISABLE=0, /**< Disable */
	CSL_GIC_GRP1_S_ENABLE=1, /**< Enable */
} CSL_GicGrp1_S_t;

/** \brief GIC CSL_GicARE_S_t: Field value definitions for feature: ARE_S */
typedef enum {
	CSL_GIC_ARE_S_DISABLED=0, /**< Disabled */
	CSL_GIC_ARE_S_ENABLED=1, /**< Enabled */
	CSL_GIC_ARE_S_DISABLE=0, /**< Disable */
	CSL_GIC_ARE_S_ENABLE=1, /**< Enable */
} CSL_GicARE_S_t;

/** \brief GIC CSL_GicARE_NS_t: Field value definitions for feature: ARE_NS */
typedef enum {
	CSL_GIC_ARE_NS_DISABLED=0, /**< Disabled */
	CSL_GIC_ARE_NS_ENABLED=1, /**< Enabled */
	CSL_GIC_ARE_NS_DISABLE=0, /**< Disable */
	CSL_GIC_ARE_NS_ENABLE=1, /**< Enable */
} CSL_GicARE_NS_t;

/** \brief GIC CSL_GicSecurity_t: Field value definitions for feature: Security */
typedef enum {
	CSL_GIC_SECURITY_DISABLED=0, /**< Disabled */
	CSL_GIC_SECURITY_ENABLED=1, /**< Enabled */
	CSL_GIC_SECURITY_DISABLE=0, /**< Disable */
	CSL_GIC_SECURITY_ENABLE=1, /**< Enable */
} CSL_GicSecurity_t;

/** \brief GIC CSL_GicRegisterWrite_t: Field value definitions for feature: RegisterWrite */
typedef enum {
	CSL_GIC_REGISTERWRITE_COMPLETE=0, /**< Complete */
	CSL_GIC_REGISTERWRITE_PENDING=1, /**< Pending */
} CSL_GicRegisterWrite_t;

/** \brief GIC CSL_GicReadReserved_t: Field value definitions for feature: ReadReserved */
typedef enum {
	CSL_GIC_READRESERVED_SET=1, /**< Set */
	CSL_GIC_READRESERVED_CLEARED=0, /**< Cleared */
	CSL_GIC_READRESERVED_CLEAR=1, /**< Clear */
} CSL_GicReadReserved_t;

/** \brief GIC CSL_GicWriteReserved_t: Field value definitions for feature: WriteReserved */
typedef enum {
	CSL_GIC_WRITERESERVED_SET=1, /**< Set */
	CSL_GIC_WRITERESERVED_CLEARED=0, /**< Cleared */
	CSL_GIC_WRITERESERVED_CLEAR=1, /**< Clear */
} CSL_GicWriteReserved_t;

/** \brief GIC CSL_GicReadToWriteOnly_t: Field value definitions for feature: ReadToWriteOnly */
typedef enum {
	CSL_GIC_READTOWRITEONLY_SET=1, /**< Set */
	CSL_GIC_READTOWRITEONLY_CLEARED=0, /**< Cleared */
	CSL_GIC_READTOWRITEONLY_CLEAR=1, /**< Clear */
} CSL_GicReadToWriteOnly_t;

/** \brief GIC CSL_GicWriteToReadOnly_t: Field value definitions for feature: WriteToReadOnly */
typedef enum {
	CSL_GIC_WRITETOREADONLY_SET=1, /**< Set */
	CSL_GIC_WRITETOREADONLY_CLEARED=0, /**< Cleared */
	CSL_GIC_WRITETOREADONLY_CLEAR=1, /**< Clear */
} CSL_GicWriteToReadOnly_t;

/** \brief GIC CSL_GicSgiPpiIntrGroupARE0_t: Field value definitions for feature: SgiPpiIntrGroupARE0 */
typedef enum {
	CSL_GIC_SGIPPIINTRGROUPARE0_CLEAR=0, /**< Clear */
	CSL_GIC_SGIPPIINTRGROUPARE0_SET=1, /**< Set */
} CSL_GicSgiPpiIntrGroupARE0_t;

/** \brief GIC CSL_GicSpiIntrGroup_t: Field value definitions for feature: SpiIntrGroup */
typedef enum {
	CSL_GIC_SPIINTRGROUP_CLEAR=0, /**< Clear */
	CSL_GIC_SPIINTRGROUP_SET=1, /**< Set */
} CSL_GicSpiIntrGroup_t;

/** \brief GIC CSL_GicSgiPpiIntrARE0_t: Field value definitions for feature: SgiPpiIntrARE0 */
typedef enum {
	CSL_GIC_SGIPPIINTRARE0_ENABLED=1, /**< Enabled */
	CSL_GIC_SGIPPIINTRARE0_DISABLED=0, /**< Disabled */
	CSL_GIC_SGIPPIINTRARE0_ENABLE=1, /**< Enable */
	CSL_GIC_SGIPPIINTRARE0_DISABLE=1, /**< Disable */
	CSL_GIC_SGIPPIINTRARE0_PENDING=1, /**< Pending */
	CSL_GIC_SGIPPIINTRARE0_NOTPENDING=0, /**< Notpending */
	CSL_GIC_SGIPPIINTRARE0_SETPENDING=1, /**< Setpending */
	CSL_GIC_SGIPPIINTRARE0_CLEARPENDING=1, /**< Clearpending */
	CSL_GIC_SGIPPIINTRARE0_ACTIVE=1, /**< Active */
	CSL_GIC_SGIPPIINTRARE0_INACTIVE=0, /**< Inactive */
	CSL_GIC_SGIPPIINTRARE0_SETACTIVE=1, /**< Setactive */
	CSL_GIC_SGIPPIINTRARE0_DEACTIVATE=1, /**< Deactivate */
} CSL_GicSgiPpiIntrARE0_t;

/** \brief GIC CSL_GicSpiIntr_t: Field value definitions for feature: SpiIntr */
typedef enum {
	CSL_GIC_SPIINTR_ENABLED=1, /**< Enabled */
	CSL_GIC_SPIINTR_DISABLED=0, /**< Disabled */
	CSL_GIC_SPIINTR_ENABLE=1, /**< Enable */
	CSL_GIC_SPIINTR_DISABLE=1, /**< Disable */
	CSL_GIC_SPIINTR_PENDING=1, /**< Pending */
	CSL_GIC_SPIINTR_NOTPENDING=0, /**< Notpending */
	CSL_GIC_SPIINTR_SETPENDING=1, /**< Setpending */
	CSL_GIC_SPIINTR_CLEARPENDING=1, /**< Clearpending */
	CSL_GIC_SPIINTR_ACTIVE=1, /**< Active */
	CSL_GIC_SPIINTR_INACTIVE=0, /**< Inactive */
	CSL_GIC_SPIINTR_SETACTIVE=1, /**< Setactive */
	CSL_GIC_SPIINTR_DEACTIVATE=1, /**< Deactivate */
} CSL_GicSpiIntr_t;

/** \brief GIC CSL_GicSgiPpiDestCPU_t: Field value definitions for feature: SgiPpiDestCPU */
typedef enum {
	CSL_GIC_SGIPPIDESTCPU_CPU0=1, /**< Cpu0 */
	CSL_GIC_SGIPPIDESTCPU_CPU1=2, /**< Cpu1 */
	CSL_GIC_SGIPPIDESTCPU_CPU2=4, /**< Cpu2 */
	CSL_GIC_SGIPPIDESTCPU_CPU3=8, /**< Cpu3 */
} CSL_GicSgiPpiDestCPU_t;

/** \brief GIC CSL_GicSpiDestCPUList_t: Field value definitions for feature: SpiDestCPUList */
typedef enum {
	CSL_GIC_SPIDESTCPULIST_CPU0=1, /**< Cpu0 */
	CSL_GIC_SPIDESTCPULIST_CPU1=2, /**< Cpu1 */
	CSL_GIC_SPIDESTCPULIST_CPU2=4, /**< Cpu2 */
	CSL_GIC_SPIDESTCPULIST_CPU3=8, /**< Cpu3 */
} CSL_GicSpiDestCPUList_t;

/** \brief GIC CSL_GicSPIIntType_t: Field value definitions for feature: SPIIntType */
typedef enum {
	CSL_GIC_SPIINTTYPE_LEVEL=0, /**< Level */
	CSL_GIC_SPIINTTYPE_EDGE=3, /**< Edge */
	CSL_GIC_SPIINTTYPE_ASSIGNLEVEL=0, /**< Assignlevel */
	CSL_GIC_SPIINTTYPE_ASSIGNEDGE=3, /**< Assignedge */
} CSL_GicSPIIntType_t;

/** \brief GIC CSL_GicSgiPpiIntrGroupModifierARE0_t: Field value definitions for feature: SgiPpiIntrGroupModifierARE0 */
typedef enum {
	CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_CLEAR=0, /**< Clear */
	CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_SET=1, /**< Set */
} CSL_GicSgiPpiIntrGroupModifierARE0_t;

/** \brief GIC CSL_GicSpiIntrGroupModifier_t: Field value definitions for feature: SpiIntrGroupModifier */
typedef enum {
	CSL_GIC_SPIINTRGROUPMODIFIER_CLEAR=0, /**< Clear */
	CSL_GIC_SPIINTRGROUPMODIFIER_SET=1, /**< Set */
} CSL_GicSpiIntrGroupModifier_t;

/** \brief GIC CSL_GicComponentId_t: Structure definition for feature: ComponentId */
typedef struct {
	uint32_t                cIDR0; /**< Component Id0 Register */
	uint32_t                cIDR1; /**< Component Id1 Register */
	uint32_t                cIDR2; /**< Component Id2 Register */
	uint32_t                cIDR3; /**< Component Id3 Register */
} CSL_GicComponentId_t;

/** \brief GIC CSL_GicAffinity_t: Structure definition for feature: Affinity */
typedef struct {
	uint32_t                a0; /**< Uint32_T */
	uint32_t                a1; /**< Uint32_T */
	bool                    iRM; /**< Bool */
	uint32_t                a2; /**< Uint32_T */
	uint32_t                a3; /**< Uint32_T */
} CSL_GicAffinity_t;

/** \brief GIC CSL_GicCore_t: Field value definitions for feature: Core */
typedef enum {
	CSL_GIC_CORE_ACTIVE=0, /**< Active */
	CSL_GIC_CORE_INACTIVE=1, /**< Inactive */
	CSL_GIC_CORE_POWERUP=0, /**< Powerup */
	CSL_GIC_CORE_POWERDOWN=1, /**< Powerdown */
} CSL_GicCore_t;

/** \brief GIC CSL_GicCoreChildIf_t: Field value definitions for feature: CoreChildIf */
typedef enum {
	CSL_GIC_CORECHILDIF_ACTIVE=0, /**< Active */
	CSL_GIC_CORECHILDIF_INACTIVE=1, /**< Inactive */
} CSL_GicCoreChildIf_t;

/** \brief GIC CSL_GicSgiPpiIntrGroup_t: Field value definitions for feature: SgiPpiIntrGroup */
typedef enum {
	CSL_GIC_SGIPPIINTRGROUP_CLEAR=0, /**< Clear */
} CSL_GicSgiPpiIntrGroup_t;

/** \brief GIC CSL_GicSgiPpiIntr_t: Field value definitions for feature: SgiPpiIntr */
typedef enum {
	CSL_GIC_SGIPPIINTR_ENABLED=1, /**< Enabled */
	CSL_GIC_SGIPPIINTR_DISABLED=0, /**< Disabled */
	CSL_GIC_SGIPPIINTR_ENABLE=1, /**< Enable */
	CSL_GIC_SGIPPIINTR_DISABLE=1, /**< Disable */
	CSL_GIC_SGIPPIINTR_PENDING=1, /**< Pending */
	CSL_GIC_SGIPPIINTR_NOTPENDING=0, /**< Notpending */
	CSL_GIC_SGIPPIINTR_SETPENDING=1, /**< Setpending */
	CSL_GIC_SGIPPIINTR_CLEARPENDING=1, /**< Clearpending */
	CSL_GIC_SGIPPIINTR_ACTIVE=1, /**< Active */
	CSL_GIC_SGIPPIINTR_INACTIVE=0, /**< Inactive */
	CSL_GIC_SGIPPIINTR_SETACTIVE=1, /**< Setactive */
	CSL_GIC_SGIPPIINTR_DEACTIVATE=1, /**< Deactivate */
} CSL_GicSgiPpiIntr_t;

/** \brief GIC CSL_GicSGIIntType_t: Field value definitions for feature: SGIIntType */
typedef enum {
	CSL_GIC_SGIINTTYPE_LEVEL=0, /**< Level */
	CSL_GIC_SGIINTTYPE_EDGE=3, /**< Edge */
} CSL_GicSGIIntType_t;

/** \brief GIC CSL_GicPPIIntType_t: Field value definitions for feature: PPIIntType */
typedef enum {
	CSL_GIC_PPIINTTYPE_LEVEL=0, /**< Level */
	CSL_GIC_PPIINTTYPE_EDGE=3, /**< Edge */
	CSL_GIC_PPIINTTYPE_ASSIGNLEVEL=0, /**< Assignlevel */
	CSL_GIC_PPIINTTYPE_ASSIGNEDGE=3, /**< Assignedge */
} CSL_GicPPIIntType_t;

/** \brief GIC CSL_GicSgiPpiIntrGroupModifier_t: Field value definitions for feature: SgiPpiIntrGroupModifier */
typedef enum {
	CSL_GIC_SGIPPIINTRGROUPMODIFIER_SET=1, /**< Set */
} CSL_GicSgiPpiIntrGroupModifier_t;


/* Array Size Definition Macros */
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE       16u
#define CSL_GIC_NUM_GICD_IGROUPR_SPI_GROUP                  960u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICPENDR0_PEND         32u
#define CSL_GIC_NUM_GICD_IGRPMODR_SPI_GROUP                 960u
#define CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID               960u
#define CSL_GIC_NUM_TRANSLATER_TRANSLATER                   1048576u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP    32u
#define CSL_GIC_NUM_GICD_ICACTIVER_SGI_PPI_SET              32u
#define CSL_GIC_NUM_GICD_IGROUPR_SGI_PPI_GROUP              32u
#define CSL_GIC_NUM_GICD_IPRIORITYR_SPI_PRIO                960u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR0_INT_TYPE       16u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP 32u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICENABLER0_ENABLE     32u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE     32u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISPENDR0_PEND         32u
#define CSL_GIC_NUM_GICD_ISENABLER_SGI_PPI_ENABLE           32u
#define CSL_GIC_NUM_GICD_SPISR                              30u
#define CSL_GIC_NUM_GICD_ICENABLER_SGI_PPI_ENABLE           32u
#define CSL_GIC_NUM_GICD_IROUTER                            960u
#define CSL_GIC_NUM_GICD_ICENABLER_SPI_ENABLE               960u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISACTIVER0_SET        32u
#define CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI                  8u
#define CSL_GIC_NUM_GICD_ISPENDR_SGI_PPI_PEND               32u
#define CSL_GIC_NUM_GICD_ISENABLER_SPI_ENABLE               960u
#define CSL_GIC_NUM_GICD_CPENDSGIR                          4u
#define CSL_GIC_NUM_GICD_NSACR                              62u
#define CSL_GIC_NUM_GICD_ISACTIVER_SGI_PPI_SET              32u
#define CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI_CPU_ID           4u
#define CSL_GIC_NUM_GICD_ICFGR_SPI_INT_TYPE                 960u
#define CSL_GIC_NUM_GICR_CORE                               4u
#define CSL_GIC_NUM_GICR_CORE_IPRIORITYR_SET                32u
#define CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI_PRIO            4u
#define CSL_GIC_NUM_GICD_ISACTIVER_SPI_SET                  960u
#define CSL_GIC_NUM_GICD_ISPENDR_SPI_PEND                   960u
#define CSL_GIC_NUM_GICD_IGRPMODR_SGI_PPI_GROUP             32u
#define CSL_GIC_NUM_GICD_ICFGR_SGI_PPI_INT_TYPE             16u
#define CSL_GIC_NUM_GICD_ICFGR_SGI_PPI                      2u
#define CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI                 8u
#define CSL_GIC_NUM_GICD_ICACTIVER_SPI_SET                  960u
#define CSL_GIC_NUM_GICD_ICPENDR_SPI_PEND                   960u
#define CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICACTIVER0_SET        32u
#define CSL_GIC_NUM_GICD_ICPENDR_SGI_PPI_PEND               32u
#define CSL_GIC_NUM_GICD_SPENDSGIR                          4u

/**
 *  \brief GIC Query value of Grp0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp0 field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsGrp0Disabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of Grp0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp0 field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsGrp0Enabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp0
 *
 * This function set the value of the EnableGrp0 field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableGrp0(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp0
 *
 * This function set the value of the EnableGrp0 field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableGrp0(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of Grp1_NS
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp1_NS field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsGrp1_NSDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of Grp1_NS
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp1_NS field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsGrp1_NSEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp1_NS
 *
 * This function set the value of the EnableGrp1_NS field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableGrp1_NS(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp1_NS
 *
 * This function set the value of the EnableGrp1_NS field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableGrp1_NS(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of Grp1_S
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp1_S field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsGrp1_SDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of Grp1_S
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the EnableGrp1_S field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsGrp1_SEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp1_S
 *
 * This function set the value of the EnableGrp1_S field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableGrp1_S(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Grp1_S
 *
 * This function set the value of the EnableGrp1_S field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableGrp1_S(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of ARE_S
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the ARE field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsARE_SDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of ARE_S
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the ARE field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsARE_SEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ARE_S
 *
 * This function set the value of the ARE field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableARE_S(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ARE_S
 *
 * This function set the value of the ARE field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableARE_S(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of ARE_NS
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the ARE_NS field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsARE_NSDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of ARE_NS
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the ARE_NS field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsARE_NSEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ARE_NS
 *
 * This function set the value of the ARE_NS field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableARE_NS(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ARE_NS
 *
 * This function set the value of the ARE_NS field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableARE_NS(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of Security
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the DS field inside the CTLR register matches the value: Disabled
 */
extern bool CSL_gicIsSecurityDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of Security
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the DS field inside the CTLR register matches the value: Enabled
 */
extern bool CSL_gicIsSecurityEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Security
 *
 * This function set the value of the DS field of the CTLR register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableSecurity(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of Security
 *
 * This function set the value of the DS field of the CTLR register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableSecurity(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of RegisterWrite
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RWP field inside the CTLR register matches the value: Complete
 */
extern bool CSL_gicIsRegisterWriteComplete(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of RegisterWrite
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RWP field inside the CTLR register matches the value: Pending
 */
extern bool CSL_gicIsRegisterWritePending(CSL_gic500_gicdRegs *pGic500GicdRegs);

/* Functions to access the feature: ImplementerID*/

/**
 *  \brief GIC Read ImplementerID
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return value of IIDR register
 */
extern uint32_t CSL_gicGetImplementerID(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of ReadReserved
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RRD field inside the STATUSR register matches the value: Set
 */
extern bool CSL_gicIsReadReservedSet(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of ReadReserved
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RRD field inside the STATUSR register matches the value: Cleared
 */
extern bool CSL_gicIsReadReservedCleared(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ReadReserved
 *
 * This function set the value of the RRD field of the STATUSR register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearReadReserved(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of WriteReserved
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the WRD field inside the STATUSR register matches the value: Set
 */
extern bool CSL_gicIsWriteReservedSet(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of WriteReserved
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the WRD field inside the STATUSR register matches the value: Cleared
 */
extern bool CSL_gicIsWriteReservedCleared(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of WriteReserved
 *
 * This function set the value of the WRD field of the STATUSR register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearWriteReserved(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of ReadToWriteOnly
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RWOD field inside the STATUSR register matches the value: Set
 */
extern bool CSL_gicIsReadToWriteOnlySet(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of ReadToWriteOnly
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the RWOD field inside the STATUSR register matches the value: Cleared
 */
extern bool CSL_gicIsReadToWriteOnlyCleared(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of ReadToWriteOnly
 *
 * This function set the value of the RWOD field of the STATUSR register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearReadToWriteOnly(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of WriteToReadOnly
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the WROD field inside the STATUSR register matches the value: Set
 */
extern bool CSL_gicIsWriteToReadOnlySet(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Query value of WriteToReadOnly
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return true if value of the WROD field inside the STATUSR register matches the value: Cleared
 */
extern bool CSL_gicIsWriteToReadOnlyCleared(CSL_gic500_gicdRegs *pGic500GicdRegs);
/**
 *  \brief GIC Set the value of WriteToReadOnly
 *
 * This function set the value of the WROD field of the STATUSR register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearWriteToReadOnly(CSL_gic500_gicdRegs *pGic500GicdRegs);

/**
 *  \brief GIC Query value of SgiPpiIntrGroupARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupARE0Index [IN] group index
 *
\return true if value of the group field inside the IGROUPR_SGI_PPI register matches the value: Clear
 */
extern bool CSL_gicIsSgiPpiIntrGroupARE0Clear(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrGroupARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupARE0Index [IN] group index
 *
\return true if value of the group field inside the IGROUPR_SGI_PPI register matches the value: Set
 */
extern bool CSL_gicIsSgiPpiIntrGroupARE0Set(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroupARE0
 *
 * This function set the value of the group field of the IGROUPR_SGI_PPI register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupARE0Index [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearSgiPpiIntrGroupARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroupARE0
 *
 * This function set the value of the group field of the IGROUPR_SGI_PPI register to the value: Set
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupARE0Index [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSgiPpiIntrGroupARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index);

/**
 *  \brief GIC Query value of SpiIntrGroup
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupIndex [IN] IGROUPR_SPI index Note: Index starts from 32
 *
\return true if value of the group field inside the IGROUPR_SPI register matches the value: Clear
 */
extern bool CSL_gicIsSpiIntrGroupClear(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex);
/**
 *  \brief GIC Query value of SpiIntrGroup
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupIndex [IN] IGROUPR_SPI index Note: Index starts from 32
 *
\return true if value of the group field inside the IGROUPR_SPI register matches the value: Set
 */
extern bool CSL_gicIsSpiIntrGroupSet(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex);
/**
 *  \brief GIC Set the value of SpiIntrGroup
 *
 * This function set the value of the group field of the IGROUPR_SPI register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupIndex [IN] IGROUPR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearSpiIntrGroup(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex);
/**
 *  \brief GIC Set the value of SpiIntrGroup
 *
 * This function set the value of the group field of the IGROUPR_SPI register to the value: Set
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupIndex [IN] IGROUPR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSpiIntrGroup(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex);

/* Functions to access the feature: SgiPpiIntrARE0*/

/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] enable index
 *
\return true if value of the enable field inside the ISENABLER_SGI_PPI register matches the value: Enabled
 */
extern bool CSL_gicIsSgiPpiIntrARE0Enabled(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] enable index
 *
\return true if value of the enable field inside the ISENABLER_SGI_PPI register matches the value: Disabled
 */
extern bool CSL_gicIsSgiPpiIntrARE0Disabled(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] pend index
 *
\return true if value of the pend field inside the ISPENDR_SGI_PPI register matches the value: Pending
 */
extern bool CSL_gicIsSgiPpiIntrARE0Pending(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] pend index
 *
\return true if value of the pend field inside the ISPENDR_SGI_PPI register matches the value: NotPending
 */
extern bool CSL_gicIsSgiPpiIntrARE0NotPending(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] set index
 *
\return true if value of the set field inside the ISACTIVER_SGI_PPI register matches the value: Active
 */
extern bool CSL_gicIsSgiPpiIntrARE0Active(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] set index
 *
\return true if value of the set field inside the ISACTIVER_SGI_PPI register matches the value: Inactive
 */
extern bool CSL_gicIsSgiPpiIntrARE0Inactive(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the enable field of the ISENABLER_SGI_PPI register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] enable index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the enable field of the ICENABLER_SGI_PPI register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] enable index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the pend field of the ISPENDR_SGI_PPI register to the value: SetPending
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] pend index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetPendingSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the pend field of the ICPENDR_SGI_PPI register to the value: ClearPending
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] pend index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearPendingSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the set field of the ISACTIVER_SGI_PPI register to the value: SetActive
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] set index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetActiveSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrARE0
 *
 * This function set the value of the set field of the ICACTIVER_SGI_PPI register to the value: Deactivate
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrARE0Index [IN] set index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDeactivateSgiPpiIntrARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index);

/* Functions to access the feature: SpiIntr*/

/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISENABLER_SPI index Note: Index starts from 32
 *
\return true if value of the enable field inside the ISENABLER_SPI register matches the value: Enabled
 */
extern bool CSL_gicIsSpiIntrEnabled(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISENABLER_SPI index Note: Index starts from 32
 *
\return true if value of the enable field inside the ISENABLER_SPI register matches the value: Disabled
 */
extern bool CSL_gicIsSpiIntrDisabled(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISPENDR_SPI index Note: Index starts from 32
 *
\return true if value of the pend field inside the ISPENDR_SPI register matches the value: Pending
 */
extern bool CSL_gicIsSpiIntrPending(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISPENDR_SPI index Note: Index starts from 32
 *
\return true if value of the pend field inside the ISPENDR_SPI register matches the value: NotPending
 */
extern bool CSL_gicIsSpiIntrNotPending(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISACTIVER_SPI index Note: Index starts from 32
 *
\return true if value of the set field inside the ISACTIVER_SPI register matches the value: Active
 */
extern bool CSL_gicIsSpiIntrActive(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Query value of SpiIntr
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISACTIVER_SPI index Note: Index starts from 32
 *
\return true if value of the set field inside the ISACTIVER_SPI register matches the value: Inactive
 */
extern bool CSL_gicIsSpiIntrInactive(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the enable field of the ISENABLER_SPI register to the value: Enable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISENABLER_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the enable field of the ICENABLER_SPI register to the value: Disable
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ICENABLER_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the pend field of the ISPENDR_SPI register to the value: SetPending
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISPENDR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetPendingSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the pend field of the ICPENDR_SPI register to the value: ClearPending
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ICPENDR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearPendingSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the set field of the ISACTIVER_SPI register to the value: SetActive
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ISACTIVER_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetActiveSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);
/**
 *  \brief GIC Set the value of SpiIntr
 *
 * This function set the value of the set field of the ICACTIVER_SPI register to the value: Deactivate
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrIndex [IN] ICACTIVER_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDeactivateSpiIntr(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex);

/* Functions to access the feature: SgiPpiIntrPriorityARE0*/

/**
 *  \brief GIC Read SgiPpiIntrPriorityARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex [IN] IPRIORITYR_SGI_PPI index
 * \param sgiPpiIntrPriorityARE0PrioIndex [IN] prio index
 *
\return value of prio bit-field.
 */
extern uint32_t CSL_gicGetSgiPpiIntrPriorityARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex, uint32_t sgiPpiIntrPriorityARE0PrioIndex);
/**
 *  \brief GIC Write SgiPpiIntrPriorityARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex [IN] IPRIORITYR_SGI_PPI index
 * \param sgiPpiIntrPriorityARE0PrioIndex [IN] prio index
 * \param value [IN]  Value to be written to the prio field
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSgiPpiIntrPriorityARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex, uint32_t sgiPpiIntrPriorityARE0PrioIndex, uint32_t value);

/* Functions to access the feature: SpiIntrPriority*/

/**
 *  \brief GIC Read SpiIntrPriority
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrPriorityIndex [IN] IPRIORITYR_SPI index Note: Index starts from 32
 *
\return value of prio bit-field.
 */
extern uint32_t CSL_gicGetSpiIntrPriority(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrPriorityIndex);
/**
 *  \brief GIC Write SpiIntrPriority
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrPriorityIndex [IN] IPRIORITYR_SPI index Note: Index starts from 32
 * \param value [IN]  Value to be written to the prio field
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSpiIntrPriority(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrPriorityIndex, uint32_t value);

/* Functions to access the feature: SgiPpiDestCPU*/

/**
 *  \brief GIC Query value of SgiPpiDestCPU
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiDestCPUItargetsrSgiPpiIndex [IN] ITARGETSR_SGI_PPI index
 * \param sgiPpiDestCPUCpuIdIndex [IN] cpu_id index
 *
\return true if value of the cpu_id field inside the ITARGETSR_SGI_PPI register matches the value: CPU0
 */
extern bool CSL_gicIsCPU0BitSetInSgiPpiDestCPU(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex);
/**
 *  \brief GIC Query value of SgiPpiDestCPU
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiDestCPUItargetsrSgiPpiIndex [IN] ITARGETSR_SGI_PPI index
 * \param sgiPpiDestCPUCpuIdIndex [IN] cpu_id index
 *
\return true if value of the cpu_id field inside the ITARGETSR_SGI_PPI register matches the value: CPU1
 */
extern bool CSL_gicIsCPU1BitSetInSgiPpiDestCPU(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex);
/**
 *  \brief GIC Query value of SgiPpiDestCPU
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiDestCPUItargetsrSgiPpiIndex [IN] ITARGETSR_SGI_PPI index
 * \param sgiPpiDestCPUCpuIdIndex [IN] cpu_id index
 *
\return true if value of the cpu_id field inside the ITARGETSR_SGI_PPI register matches the value: CPU2
 */
extern bool CSL_gicIsCPU2BitSetInSgiPpiDestCPU(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex);
/**
 *  \brief GIC Query value of SgiPpiDestCPU
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiDestCPUItargetsrSgiPpiIndex [IN] ITARGETSR_SGI_PPI index
 * \param sgiPpiDestCPUCpuIdIndex [IN] cpu_id index
 *
\return true if value of the cpu_id field inside the ITARGETSR_SGI_PPI register matches the value: CPU3
 */
extern bool CSL_gicIsCPU3BitSetInSgiPpiDestCPU(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex);

/* Functions to access the feature: SpiDestCPUList*/

/**
 *  \brief GIC Query value of SpiDestCPUList
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiDestCPUListIndex [IN] ITARGETSR_SPI index Note: Index starts from 32
 *
\return true if value of the cpu_id field inside the ITARGETSR_SPI register matches the value: CPU0
 */
extern bool CSL_gicIsCPU0BitSetInSpiDestCPUList(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex);
/**
 *  \brief GIC Query value of SpiDestCPUList
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiDestCPUListIndex [IN] ITARGETSR_SPI index Note: Index starts from 32
 *
\return true if value of the cpu_id field inside the ITARGETSR_SPI register matches the value: CPU1
 */
extern bool CSL_gicIsCPU1BitSetInSpiDestCPUList(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex);
/**
 *  \brief GIC Query value of SpiDestCPUList
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiDestCPUListIndex [IN] ITARGETSR_SPI index Note: Index starts from 32
 *
\return true if value of the cpu_id field inside the ITARGETSR_SPI register matches the value: CPU2
 */
extern bool CSL_gicIsCPU2BitSetInSpiDestCPUList(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex);
/**
 *  \brief GIC Query value of SpiDestCPUList
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiDestCPUListIndex [IN] ITARGETSR_SPI index Note: Index starts from 32
 *
\return true if value of the cpu_id field inside the ITARGETSR_SPI register matches the value: CPU3
 */
extern bool CSL_gicIsCPU3BitSetInSpiDestCPUList(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex);
/**
 *  \brief GIC Write SpiDestCPUList
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiDestCPUListIndex [IN] ITARGETSR_SPI index Note: Index starts from 32
 * \param value [IN]  Value to be written to the cpu_id field
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSpiDestCPUList(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex, uint32_t value);

/* Functions to access the feature: SPIIntType*/

/**
 *  \brief GIC Query value of SPIIntType
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sPIIntTypeIndex [IN] ICFGR_SPI index Note: Index starts from 32
 *
\return true if value of the int_type field inside the ICFGR_SPI register matches the value: Level
 */
extern bool CSL_gicIsSPIIntTypeLevel(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex);
/**
 *  \brief GIC Query value of SPIIntType
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sPIIntTypeIndex [IN] ICFGR_SPI index Note: Index starts from 32
 *
\return true if value of the int_type field inside the ICFGR_SPI register matches the value: Edge
 */
extern bool CSL_gicIsSPIIntTypeEdge(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex);
/**
 *  \brief GIC Set the value of SPIIntType
 *
 * This function set the value of the int_type field of the ICFGR_SPI register to the value: assignLevel
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sPIIntTypeIndex [IN] ICFGR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicAssignLevelSPIIntType(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex);
/**
 *  \brief GIC Set the value of SPIIntType
 *
 * This function set the value of the int_type field of the ICFGR_SPI register to the value: assignEdge
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sPIIntTypeIndex [IN] ICFGR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicAssignEdgeSPIIntType(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex);

/**
 *  \brief GIC Query value of SgiPpiIntrGroupModifierARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierARE0Index [IN] group index
 *
\return true if value of the group field inside the IGRPMODR_SGI_PPI register matches the value: Clear
 */
extern bool CSL_gicIsSgiPpiIntrGroupModifierARE0Clear(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index);
/**
 *  \brief GIC Query value of SgiPpiIntrGroupModifierARE0
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierARE0Index [IN] group index
 *
\return true if value of the group field inside the IGRPMODR_SGI_PPI register matches the value: Set
 */
extern bool CSL_gicIsSgiPpiIntrGroupModifierARE0Set(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroupModifierARE0
 *
 * This function set the value of the group field of the IGRPMODR_SGI_PPI register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierARE0Index [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearSgiPpiIntrGroupModifierARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroupModifierARE0
 *
 * This function set the value of the group field of the IGRPMODR_SGI_PPI register to the value: Set
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierARE0Index [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSgiPpiIntrGroupModifierARE0(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index);

/**
 *  \brief GIC Query value of SpiIntrGroupModifier
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupModifierIndex [IN] IGRPMODR_SPI index Note: Index starts from 32
 *
\return true if value of the group field inside the IGRPMODR_SPI register matches the value: Clear
 */
extern bool CSL_gicIsSpiIntrGroupModifierClear(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex);
/**
 *  \brief GIC Query value of SpiIntrGroupModifier
 *
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupModifierIndex [IN] IGRPMODR_SPI index Note: Index starts from 32
 *
\return true if value of the group field inside the IGRPMODR_SPI register matches the value: Set
 */
extern bool CSL_gicIsSpiIntrGroupModifierSet(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex);
/**
 *  \brief GIC Set the value of SpiIntrGroupModifier
 *
 * This function set the value of the group field of the IGRPMODR_SPI register to the value: Clear
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupModifierIndex [IN] IGRPMODR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearSpiIntrGroupModifier(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex);
/**
 *  \brief GIC Set the value of SpiIntrGroupModifier
 *
 * This function set the value of the group field of the IGRPMODR_SPI register to the value: Set
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param spiIntrGroupModifierIndex [IN] IGRPMODR_SPI index Note: Index starts from 32
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSpiIntrGroupModifier(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex);

/* Functions to access the feature: ComponentId*/

/**
 *  \brief GIC Read the attributes of ComponentId
 *
 * This function reads the attributes of the ComponentId feature and fills out the user-supplied structure pCSL_GicComponentId_t
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param pCSL_GicComponentId_t [OUT] Pointer to user-supplied structure to be populated from register overlay.
 *
\return int32_t. CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicGetComponentId(CSL_gic500_gicdRegs *pGic500GicdRegs, CSL_GicComponentId_t *pCSL_GicComponentId_t);
/* Functions to access the feature: Affinity*/

/**
 *  \brief GIC Read the attributes of Affinity
 *
 * This function reads the attributes of the Affinity feature and fills out the user-supplied structure pCSL_GicAffinity_t
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param affinityIndex [IN] IROUTER index
 * \param pCSL_GicAffinity_t [OUT] Pointer to user-supplied structure to be populated from register overlay.
 *
\return int32_t. CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicGetAffinity(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t affinityIndex, CSL_GicAffinity_t *pCSL_GicAffinity_t);
/**
 *  \brief GIC Set up the attributes of Affinity
 *
 * This function sets up the attributes of the Affinity feature by reading the user-supplied structure pCSL_GicAffinity_t
 *
 * \param pGic500GicdRegs [IN]  Pointer to IP Register Overlay
 * \param affinityIndex [IN] IROUTER index
 * \param pCSL_GicAffinity_t [IN] Pointer to user-supplied structure whose contents are used to set up the register overlay.
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetAffinity(CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t affinityIndex, CSL_GicAffinity_t *pCSL_GicAffinity_t);
/**
 *  \brief GIC Query value of Core
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreIndex [IN] core index
 *
\return true if value of the ProcessorSleep field inside the WAKER register matches the value: Active
 */
extern bool CSL_gicIsCoreActive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex);
/**
 *  \brief GIC Query value of Core
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreIndex [IN] core index
 *
\return true if value of the ProcessorSleep field inside the WAKER register matches the value: Inactive
 */
extern bool CSL_gicIsCoreInactive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex);
/**
 *  \brief GIC Set the value of Core
 *
 * This function set the value of the ProcessorSleep field of the WAKER register to the value: PowerUp
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreIndex [IN] core index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicPowerUpCore(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex);
/**
 *  \brief GIC Set the value of Core
 *
 * This function set the value of the ProcessorSleep field of the WAKER register to the value: PowerDown
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreIndex [IN] core index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicPowerDownCore(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex);

/**
 *  \brief GIC Query value of CoreChildIf
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreChildIfIndex [IN] core index
 *
\return true if value of the ChildrenAsleep field inside the WAKER register matches the value: Active
 */
extern bool CSL_gicIsCoreChildIfActive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreChildIfIndex);
/**
 *  \brief GIC Query value of CoreChildIf
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param coreChildIfIndex [IN] core index
 *
\return true if value of the ChildrenAsleep field inside the WAKER register matches the value: Inactive
 */
extern bool CSL_gicIsCoreChildIfInactive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreChildIfIndex);

/**
 *  \brief GIC Query value of SgiPpiIntrGroup
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupCoreIndex [IN] core index
 * \param sgiPpiIntrGroupGroupIndex [IN] group index
 *
\return true if value of the group field inside the IGROUPR_SGI_PPI register matches the value: Clear
 */
extern bool CSL_gicIsSgiPpiIntrGroupClear(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupCoreIndex, uint32_t sgiPpiIntrGroupGroupIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroup
 *
 * This function set the value of the group field of the IGROUPR_SGI_PPI register to the value: Clear
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupCoreIndex [IN] core index
 * \param sgiPpiIntrGroupGroupIndex [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearSgiPpiIntrGroup(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupCoreIndex, uint32_t sgiPpiIntrGroupGroupIndex);

/* Functions to access the feature: SgiPpiIntr*/

/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrEnableIndex [IN] enable index
 *
\return true if value of the enable field inside the ISENABLER0 register matches the value: Enabled
 */
extern bool CSL_gicIsSgiPpiIntrEnabled(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex);
/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrEnableIndex [IN] enable index
 *
\return true if value of the enable field inside the ISENABLER0 register matches the value: Disabled
 */
extern bool CSL_gicIsSgiPpiIntrDisabled(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex);
/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrPendIndex [IN] pend index
 *
\return true if value of the pend field inside the ISPENDR0 register matches the value: Pending
 */
extern bool CSL_gicIsSgiPpiIntrPending(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex);
/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrPendIndex [IN] pend index
 *
\return true if value of the pend field inside the ISPENDR0 register matches the value: NotPending
 */
extern bool CSL_gicIsSgiPpiIntrNotPending(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex);
/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrSetIndex [IN] set index
 *
\return true if value of the set field inside the ISACTIVER0 register matches the value: Active
 */
extern bool CSL_gicIsSgiPpiIntrActive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex);
/**
 *  \brief GIC Query value of SgiPpiIntr
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrSetIndex [IN] set index
 *
\return true if value of the set field inside the ISACTIVER0 register matches the value: Inactive
 */
extern bool CSL_gicIsSgiPpiIntrInactive(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the enable field of the ISENABLER0 register to the value: Enable
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrEnableIndex [IN] enable index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicEnableSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the enable field of the ICENABLER0 register to the value: Disable
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrEnableIndex [IN] enable index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDisableSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the pend field of the ISPENDR0 register to the value: SetPending
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrPendIndex [IN] pend index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetPendingSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the pend field of the ICPENDR0 register to the value: ClearPending
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrPendIndex [IN] pend index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicClearPendingSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the set field of the ISACTIVER0 register to the value: SetActive
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrSetIndex [IN] set index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetActiveSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntr
 *
 * This function set the value of the set field of the ICACTIVER0 register to the value: Deactivate
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrCoreIndex [IN] core index
 * \param sgiPpiIntrSetIndex [IN] set index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicDeactivateSgiPpiIntr(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex);

/* Functions to access the feature: SgiPpiIntrPriority*/

/**
 *  \brief GIC Read SgiPpiIntrPriority
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrPriorityCoreIndex [IN] core index
 * \param sgiPpiIntrPriorityIpriorityrIndex [IN] IPRIORITYR index
 *
\return value of prio bit-field.
 */
extern uint32_t CSL_gicGetSgiPpiIntrPriority(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrPriorityCoreIndex, uint32_t sgiPpiIntrPriorityIpriorityrIndex);
/**
 *  \brief GIC Write SgiPpiIntrPriority
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrPriorityCoreIndex [IN] core index
 * \param sgiPpiIntrPriorityIpriorityrIndex [IN] IPRIORITYR index
 * \param value [IN]  Value to be written to the prio field
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSgiPpiIntrPriority(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrPriorityCoreIndex, uint32_t sgiPpiIntrPriorityIpriorityrIndex, uint32_t value);

/* Functions to access the feature: SGIIntType*/

/**
 *  \brief GIC Query value of SGIIntType
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sGIIntTypeCoreIndex [IN] core index
 * \param sGIIntTypeIntTypeIndex [IN] int_type index
 *
\return true if value of the int_type field inside the ICFGR0 register matches the value: Level
 */
extern bool CSL_gicIsSGIIntTypeLevel(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sGIIntTypeCoreIndex, uint32_t sGIIntTypeIntTypeIndex);
/**
 *  \brief GIC Query value of SGIIntType
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sGIIntTypeCoreIndex [IN] core index
 * \param sGIIntTypeIntTypeIndex [IN] int_type index
 *
\return true if value of the int_type field inside the ICFGR0 register matches the value: Edge
 */
extern bool CSL_gicIsSGIIntTypeEdge(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sGIIntTypeCoreIndex, uint32_t sGIIntTypeIntTypeIndex);

/* Functions to access the feature: PPIIntType*/

/**
 *  \brief GIC Query value of PPIIntType
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param pPIIntTypeCoreIndex [IN] core index
 * \param pPIIntTypeIntTypeIndex [IN] int_type index
 *
\return true if value of the int_type field inside the ICFGR1 register matches the value: Level
 */
extern bool CSL_gicIsPPIIntTypeLevel(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex);
/**
 *  \brief GIC Query value of PPIIntType
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param pPIIntTypeCoreIndex [IN] core index
 * \param pPIIntTypeIntTypeIndex [IN] int_type index
 *
\return true if value of the int_type field inside the ICFGR1 register matches the value: Edge
 */
extern bool CSL_gicIsPPIIntTypeEdge(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex);
/**
 *  \brief GIC Set the value of PPIIntType
 *
 * This function set the value of the int_type field of the ICFGR1 register to the value: assignLevel
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param pPIIntTypeCoreIndex [IN] core index
 * \param pPIIntTypeIntTypeIndex [IN] int_type index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicAssignLevelPPIIntType(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex);
/**
 *  \brief GIC Set the value of PPIIntType
 *
 * This function set the value of the int_type field of the ICFGR1 register to the value: assignEdge
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param pPIIntTypeCoreIndex [IN] core index
 * \param pPIIntTypeIntTypeIndex [IN] int_type index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicAssignEdgePPIIntType(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex);

/**
 *  \brief GIC Query value of SgiPpiIntrGroupModifier
 *
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierCoreIndex [IN] core index
 * \param sgiPpiIntrGroupModifierGroupIndex [IN] group index
 *
\return true if value of the group field inside the IGRPMODR_SGI_PPI register matches the value: Set
 */
extern bool CSL_gicIsSgiPpiIntrGroupModifierSet(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupModifierCoreIndex, uint32_t sgiPpiIntrGroupModifierGroupIndex);
/**
 *  \brief GIC Set the value of SgiPpiIntrGroupModifier
 *
 * This function set the value of the group field of the IGRPMODR_SGI_PPI register to the value: Set
 *
 * \param pGic500GicrRegs [IN]  Pointer to IP Register Overlay
 * \param sgiPpiIntrGroupModifierCoreIndex [IN] core index
 * \param sgiPpiIntrGroupModifierGroupIndex [IN] group index
 *
\return CSL_OK if successful, CSL_ERR otherwise.
 */
extern int32_t CSL_gicSetSgiPpiIntrGroupModifier(CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupModifierCoreIndex, uint32_t sgiPpiIntrGroupModifierGroupIndex);

/** @}*/


#ifdef __cplusplus
}
#endif
#endif
/* Nothing past this point */
