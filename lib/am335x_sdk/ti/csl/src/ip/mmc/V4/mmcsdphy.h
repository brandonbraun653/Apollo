/*
*  Copyright (C) 2017 Arasan Chip Systems Inc
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
 *    Neither the name of Arasan Chip Systems Incorporated nor the names of
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
*
*  Name             : mmcsdphy.h
*  Creation Date : May 12, 2019
*  Description     : This header file contains macros and functions to read/write the
*                          host controller phy registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  12-May-2019  PB              1.0              Added phy register macros and API prototypes
*
*********************************************************************/
/**
 *  \file mmcsdphy.h
 *
 *  \brief File with phy register macros and manipulation function prototypes.
 * Word (16-bit) register access is used to read / write to phy registers.
 *
**/
#ifndef SDHC_PHY_H_
#define SDHC_PHY_H_

#ifdef __cplusplus
extern "C" {
#endif

/*    Includes    */

#include <ti/csl/cslr_mmc.h>

/*   Typedefs and Defines    */

/*
* \brief Macros for passing the mode and driver type to phy configure api
* @{
*/
/* EMMC modes */
#define MODE_HS400								((uint32_t)1U)
#define MODE_HS200								((uint32_t)2U)
#define MODE_HSSDR50							((uint32_t)3U)
#define MODE_HSDDR50							((uint32_t)4U)
#define MODE_ENHANCED_STROBE					((uint32_t)5U)

/* SDR modes */
#define MODE_SDR104								((uint32_t)6U)
#define MODE_SDR50								((uint32_t)7U)
#define MODE_DDR50								((uint32_t)8U)
#define MODE_SDR25								((uint32_t)9U)
#define MODE_SDR12								((uint32_t)10U)
#define MODE_HS									((uint32_t)11U)
#define MODE_DS									((uint32_t)12U)



#define DRIVER_TYPE_A							((uint32_t)0x1U)
#define DRIVER_TYPE_B							((uint32_t)0x0U)
#define DRIVER_TYPE_C							((uint32_t)0x2U)
#define DRIVER_TYPE_D							((uint32_t)0x3U)
/* @} */

/*
* \brief Macros for Phy register address offsets
* @{
*/


/*
* \brief Macros for Phy address control 1 register (Base Addr + 0x100)
* @{
*/
#define MMC_PHY_CTRL1_REG_OFFSET  			        ((uint32_t)0U)

/* Bit 0 */
#define MMC_PHY_CTRL1_PDB_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL1_PDB_MASK  			    ((uint32_t)0x00000001U)

#define MMC_PHY_CTRL1_PDB_ENABLE			((uint32_t)0x1U)
#define MMC_PHY_CTRL1_PDB_DISABLE		    ((uint32_t)0x0U)

/* Bit 1 */
#define MMC_PHY_CTRL1_ENDLL_SHIFT  			    ((uint32_t)1U)
#define MMC_PHY_CTRL1_ENDLL_MASK  			    ((uint32_t)0x00000002U)

#define MMC_PHY_CTRL1_ENDLL_ENABLE		((uint32_t)0x1U)
#define MMC_PHY_CTRL1_ENDLL_DISABLE		((uint32_t)0x0U)


/* Bit 7:4 */
#define MMC_PHY_CTRL1_DLL_TRIM_ICP_SHIFT  			    ((uint32_t)4U)
#define MMC_PHY_CTRL1_DLL_TRIM_ICP_MASK  			    ((uint32_t)0x000000F0U)

#define PHY_DLL_TRIM_ICP_0						((uint32_t)0x0U)
#define PHY_DLL_TRIM_ICP_8						((uint32_t)0x8U)


/* Bit 16 */
#define MMC_PHY_CTRL1_EN_RTRIM_SHIFT  			    ((uint32_t)16U)
#define MMC_PHY_CTRL1_EN_RTRIM_MASK  			    ((uint32_t)0x00010000U)

/* Bit 17 */
#define MMC_PHY_CTRL1_RTRIM_SHIFT  			    ((uint32_t)17U)
#define MMC_PHY_CTRL1_RTRIM_MASK  			    ((uint32_t)0x00020000U)

/* Bit 22:20 */
#define MMC_PHY_CTRL1_DR_TY_SHIFT  			    ((uint32_t)20U)
#define MMC_PHY_CTRL1_DR_TY_MASK  			    ((uint32_t)0x00700000U)

/* Bit 31 */
#define MMC_PHY_CTRL1_IOMUX_ENABLE_SHIFT  			    ((uint32_t)31U)
#define MMC_PHY_CTRL1_IOMUX_ENABLE_MASK  			    ((uint32_t)0x80000000U)

/*
* \brief Macros for Phy address control 2 register (Base Addr + 0x104)
* @{
*/
#define MMC_PHY_CTRL2_REG_OFFSET  			        ((uint32_t)4U)

/* Bit 7:0 */
#define MMC_PHY_CTRL2_ODEN_DAT_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL2_ODEN_DAT_MASK  			    ((uint32_t)0x000000FFU)

/* Bit 12 */
#define MMC_PHY_CTRL2_ODEN_CMD_SHIFT  			    ((uint32_t)12U)
#define MMC_PHY_CTRL2_ODEN_CMD_MASK  			    ((uint32_t)0x00001000U)

/* Bit 13 */
#define MMC_PHY_CTRL2_ODEN_STRB_SHIFT  			    ((uint32_t)13U)
#define MMC_PHY_CTRL2_ODEN_STRB_MASK  			    ((uint32_t)0x00002000U)

/* Bit 23:16 */
#define MMC_PHY_CTRL2_OD_RELEASE_DAT_SHIFT  			((uint32_t)16U)
#define MMC_PHY_CTRL2_OD_RELEASE_DAT_MASK  			    ((uint32_t)0x00FF0000U)

/* Bit 28 */
#define MMC_PHY_CTRL2_OD_RELEASE_CMD_SHIFT  			((uint32_t)28U)
#define MMC_PHY_CTRL2_OD_RELEASE_CMD_MASK  			    ((uint32_t)0x10000000U)

/* Bit 29 */
#define MMC_PHY_CTRL2_OD_RELEASE_STRB_SHIFT  			((uint32_t)29U)
#define MMC_PHY_CTRL2_OD_RELEASE_STRB_MASK  			((uint32_t)0x20000000U)



/*
* \brief Macros for Phy address control 3 register (Base Addr + 0x108)
* @{
*/
#define MMC_PHY_CTRL3_REG_OFFSET  			        ((uint32_t)8U)

/* Bit 7:0 */
#define MMC_PHY_CTRL3_REN_DAT_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL3_REN_DAT_MASK  			    ((uint32_t)0x000000FFU)

/* Bit 12 */
#define MMC_PHY_CTRL3_REN_CMD_SHIFT  			    ((uint32_t)12U)
#define MMC_PHY_CTRL3_REN_CMD_MASK  			    ((uint32_t)0x00001000U)

/* Bit 13 */
#define MMC_PHY_CTRL3_REN_STRB_SHIFT  			    ((uint32_t)13U)
#define MMC_PHY_CTRL3_REN_STRB_MASK  			    ((uint32_t)0x00002000U)

/* Bit 23:16 */
#define MMC_PHY_CTRL3_PU_DAT_SHIFT  			((uint32_t)16U)
#define MMC_PHY_CTRL3_PU_DAT_MASK  			    ((uint32_t)0x00FF0000U)

/* Bit 28 */
#define MMC_PHY_CTRL3_PU_CMD_SHIFT  			((uint32_t)28U)
#define MMC_PHY_CTRL3_PU_CMD_MASK  			    ((uint32_t)0x10000000U)

/* Bit 29 */
#define MMC_PHY_CTRL3_PU_STRB_SHIFT  			((uint32_t)29U)
#define MMC_PHY_CTRL3_PU_STRB_MASK  			((uint32_t)0x20000000U)


/*
* \brief Macros for Phy address control 4 register (Base Addr + 0x10C)
* @{
*/

#define MMC_PHY_CTRL4_REG_OFFSET  			        ((uint32_t)0xCU)

/* Bit 4:0 */
#define MMC_PHY_CTRL4_ITAPDLY_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL4_ITAPDLY_MASK  			    ((uint32_t)0x0000001FU)

/* Bit 8 */
#define MMC_PHY_CTRL4_ITAPDLYENA_SHIFT  			((uint32_t)8U)
#define MMC_PHY_CTRL4_ITAPDLYENA_MASK  			    ((uint32_t)0x00000100U)

/* Bit 9 */
#define MMC_PHY_CTRL4_ITAPCHGWIN_SHIFT  			((uint32_t)9U)
#define MMC_PHY_CTRL4_ITAPCHGWIN_MASK  			    ((uint32_t)0x00000200U)

/* Bit 15:12 */
#define MMC_PHY_CTRL4_OTAPDLYSEL_SHIFT  			((uint32_t)12U)
#define MMC_PHY_CTRL4_OTAPDLYSEL_MASK  			    ((uint32_t)0x0000F000U)

#define PHY_OTAPDLY_CTRL_SEL_0				((uint32_t)0x0U)
#define PHY_OTAPDLY_CTRL_SEL_1				((uint32_t)0x1U)
#define PHY_OTAPDLY_CTRL_SEL_2				((uint32_t)0x2U)
#define PHY_OTAPDLY_CTRL_SEL_4				((uint32_t)0x4U)
#define PHY_OTAPDLY_CTRL_SEL_8				((uint32_t)0x8U)



/* Bit 20 */
#define MMC_PHY_CTRL4_OTAPDLYENA_SHIFT  			((uint32_t)20U)
#define MMC_PHY_CTRL4_OTAPDLYENA_MASK  			    ((uint32_t)0x00100000U)

#define MMC_PHY_CTRL4_OTAPDLYENA_ENABLED  			((uint32_t)1U)
#define MMC_PHY_CTRL4_OTAPDLYENA_DISABLED		    ((uint32_t)0U)

/* Bit 24-27 */
#define MMC_PHY_CTRL4_STRBSEL_SHIFT  			    ((uint32_t)24U)
#define MMC_PHY_CTRL4_STRBSEL_MASK  			    ((uint32_t)0xFF000000U)


/*
* \brief Macros for Phy address control 5 register (Base Addr + 0x110)
* @{
*/
#define MMC_PHY_CTRL5_REG_OFFSET  			        ((uint32_t)0x10U)

/* Bit 2:0 */
#define MMC_PHY_CTRL5_CLKBUFSEL_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL5_CLKBUFSEL_MASK  			    ((uint32_t)0x00000007U)

/* Bit 10:8 */
#define MMC_PHY_CTRL5_FRQSEL_SHIFT  			        ((uint32_t)8U)
#define MMC_PHY_CTRL5_FRQSEL_MASK  			        ((uint32_t)0x00000700U)

/* Bit 16 */
#define MMC_PHY_CTRL5_SELDLYRXCLK_SHIFT  			((uint32_t)16U)
#define MMC_PHY_CTRL5_SELDLYRXCLK_MASK  			((uint32_t)0x00010000U)

/* Bit 17 */
#define MMC_PHY_CTRL5_SELDLYTXCLK_SHIFT  			((uint32_t)17U)
#define MMC_PHY_CTRL5_SELDLYTXCLK_MASK  			((uint32_t)0x00020000U)

/*
* \brief Macros for Phy address control 6 register (Base Addr + 0x114)
* @{
*/

#define MMC_PHY_CTRL6_REG_OFFSET  			        ((uint32_t)0x14U)

/* Bit 7:0 */
#define MMC_PHY_CTRL6_TESTCTRL_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_CTRL6_TESTCTRL_MASK  			    ((uint32_t)0x000000FFU)

/* Bit 27:24 */
#define MMC_PHY_CTRL6_BISTMODE_SHIFT  			    ((uint32_t)24U)
#define MMC_PHY_CTRL6_BISTMODE_MASK  			    ((uint32_t)0x0F000000U)

/* Bit 30 */
#define MMC_PHY_CTRL6_BISTSTART_SHIFT  			    ((uint32_t)30U)
#define MMC_PHY_CTRL6_BISTSTART_MASK  			    ((uint32_t)0x40000000U)

/* Bit 31 */
#define MMC_PHY_CTRL6_BISTENABLE_SHIFT  			    ((uint32_t)31U)
#define MMC_PHY_CTRL6_BISTENABLE_MASK  			    ((uint32_t)0x80000000U)



/*
* \brief Macros for Phy status 1 register (Base Addr + 0x130)
* @{
*/

#define MMC_PHY_STS_1_REG_OFFSET  			        ((uint32_t)0x30U)

/* Bit 0 */
#define MMC_PHY_STS_1_DLLRDY_SHIFT  			    ((uint32_t)0U)
#define MMC_PHY_STS_1_DLLRDY_MASK  			    ((uint32_t)0x00000001U)

#define PHY_DLL_CTRL_STS_DLL_RDY_TRUE		((uint32_t)0x1U)
#define PHY_DLL_CTRL_STS_DLL_RDY_FALSE		((uint32_t)0x0U)


/* Bit 1 */
#define MMC_PHY_STS_1_CALDONE_SHIFT  			    ((uint32_t)1U)
#define MMC_PHY_STS_1_CALDONE_MASK  			    ((uint32_t)0x00000002U)

/* Bit 2 */
#define MMC_PHY_STS_1_EXR_NINST_SHIFT  			    ((uint32_t)2U)
#define MMC_PHY_STS_1_EXR_NINST_MASK  			    ((uint32_t)0x00000004U)

/* Bit 3 */
#define MMC_PHY_STS_1_BISTDONE_SHIFT  			    ((uint32_t)3U)
#define MMC_PHY_STS_1_BISTDONE_MASK  			    ((uint32_t)0x00000008U)

/* Bit 7:4 */
#define MMC_PHY_STS_1_RTRIM_SHIFT  			    ((uint32_t)4U)
#define MMC_PHY_STS_1_RTRIM_MASK  			    ((uint32_t)0x000000F0U)


/*
* \brief Macros for Phy status 1 register (Base Addr + 0x130)
* @{
*/

#define MMC_PHY_STS_2_REG_OFFSET  			        ((uint32_t)0x34U)

/* Bit 0 */
#define MMC_PHY_STS_2_BISTSTATUS_SHIFT  			((uint32_t)0U)
#define MMC_PHY_STS_2_BISTSTATUS_MASK  			    ((uint32_t)0xffffffffU)






/* @} */

#define PHY_DLL_CTRL_STS_FREQ_SEL_0			((uint32_t)0x0U)
#define PHY_DLL_CTRL_STS_FREQ_SEL_1			((uint32_t)0x1U)
#define PHY_DLL_CTRL_STS_FREQ_SEL_2			((uint32_t)0x2U)

#define PHY_IO_PADS_CTRL1_EXR_NINST_ENABLE	((uint32_t)0x1U)
#define PHY_IO_PADS_CTRL1_EXR_NINST_DISABLE	((uint32_t)0x0U)


#define  PHY_IO_PADS_CTRL1_DR_TYPE_A			((uint32_t)0x1U)
#define  PHY_IO_PADS_CTRL1_DR_TYPE_B			((uint32_t)0x0U)
#define  PHY_IO_PADS_CTRL1_DR_TYPE_C			((uint32_t)0x2U)
#define  PHY_IO_PADS_CTRL1_DR_TYPE_D			((uint32_t)0x3U)

#define PHY_IO_PADS_CTRL1_RET_ENB_ENABLE		((uint32_t)0x1U)
#define PHY_IO_PADS_CTRL1_RET_ENB_DISABLE	((uint32_t)0x0U)

#define PHY_IO_PADS_CTRL2_RETRIM_EN_ENABLE	((uint32_t)0x1U)
#define PHY_IO_PADS_CTRL2_RETRIM_EN_DISABLE	((uint32_t)0x0U)

#define PHY_IO_PADS_STATUS_CALDONE_ENABLE	((uint32_t)0x1U)
#define PHY_IO_PADS_STATUS_CALDONE_DISABLE	((uint32_t)0x0U)

#define PHY_IO_REN_CTRL1_STRB_ENABLE			((uint32_t)0x1U)
#define PHY_IO_REN_CTRL1_STRB_DISABLE			((uint32_t)0x0U)

#define PHY_IO_REN_CTRL1_CMD_ENABLE			((uint32_t)0x1U)
#define PHY_IO_REN_CTRL1_CMD_DISABLE			((uint32_t)0x0U)

#define PHY_IO_REN_CTRL2_DAT0_7_ENABLE		((uint32_t)0xFFU)
#define PHY_IO_REN_CTRL2_DAT0_7_DISABLE		((uint32_t)0x0U)

#define PHY_IO_PU_CTRL1_STRB_ENABLE			((uint32_t)0x1U)
#define PHY_IO_PU_CTRL1_STRB_DISABLE			((uint32_t)0x0U)

#define PHY_IO_PU_CTRL1_CMD_ENABLE			((uint32_t)0x1U)
#define PHY_IO_PU_CTRL1_CMD_DISABLE			((uint32_t)0x0U)
#define PHY_IO_PU_CTRL2_DAT0_7_ENABLE		((uint32_t)0xFFU)
#define PHY_IO_PU_CTRL2_DAT0_7_DISABLE		((uint32_t)0x0U)

#define PHY_ITAPDLY_CTRL_SEL_0					((uint32_t)0x0U)
#define PHY_ITAPDLY_CTRL_SEL_1					((uint32_t)0x1U)
#define PHY_ITAPDLY_CTRL_SEL_2					((uint32_t)0x2U)
#define PHY_ITAPDLY_CTRL_SEL_4					((uint32_t)0x4U)
#define PHY_ITAPDLY_CTRL_SEL_10				((uint32_t)0xAU)

#define PHY_OTAPDLY_CTRL_DLY_EN_ENABLE		((uint32_t)0x1U)
#define PHY_OTAPDLY_CTRL_DLY_EN_DISABLE		((uint32_t)0x0U)


#define PHY_CLK_BUF_SEL_CTRL_STRB_7			((uint32_t)0x7U)
#define PHY_CLK_BUF_SEL_CTRL_STRB_0			((uint32_t)0x0U)

#define PHY_MODE_CTRL_ENH_STRB_ENABLE		((uint32_t)0x1U)
#define PHY_MODE_CTRL_ENH_STRB_DISABLE		((uint32_t)0x0U)

#define PHY_MODE_CTRL_HS400_MODE_ENABLE		((uint32_t)0x1U)
#define PHY_MODE_CTRL_HS400_MODE_DISABLE	((uint32_t)0x0U)

#define PHY_MODE_CTRL_DEFAULT_MODE_ENABLE	((uint32_t)0x1U)
#define PHY_MODE_CTRL_DEFAULT_MODE_DISABLE	((uint32_t)0x0U)

#define PHY_MODE_CTRL_DDR50_MODE_ENABLE		((uint32_t)0x1U)
#define PHY_MODE_CTRL_DDR50_MODE_DISABLE	((uint32_t)0x0U)


#define PHY_LDO_CTRL_LDO_EN_ENABLE			((uint32_t)0x1U)
#define PHY_LDO_CTRL_LDO_EN_DISABLE			((uint32_t)0x0U)

#define PHY_CMD_CTRL_CMD_PDB_EN_ENABLE		((uint32_t)0x1U)
#define PHY_CMD_CTRL_CMD_PDB_EN_DISABLE		((uint32_t)0x0U)

#define PHY_DAT_CTRL_DAT_PDB_EN_ENABLE		((uint32_t)0xffU)
#define PHY_DAT_CTRL_DAT_PDB_EN_DISABLE		((uint32_t)0x0U)

#define PHY_STRB_CTRL_STRB_EN_ENABLE			((uint32_t)0x1U)
#define PHY_STRB_CTRL_STRB_EN_DISABLE		((uint32_t)0x0U)

#define PHY_CLK_CTRL_PDB_EN_ENABLE			((uint32_t)0x1U)
#define PHY_CLK_CTRL_PDB_EN_DISABLE			((uint32_t)0x0U)

#define PHY_CONTROL_CTRL_MODE_SEL_4BIT		((uint32_t)0x1U)
#define PHY_CONTROL_CTRL_MODE_SEL_8BIT		((uint32_t)0x0U)
/* @} */

/* ========================================================================== */
/*                          SOFT PHY                                          */
/* ========================================================================== */
/*
* \brief Macros for Phy address control 1 register (Base Addr + 0x100)
* @{
*/
#define MMC_SOFT_PHY_CTRL1_REG_OFFSET  			        ((uint32_t)0U)


/* Bit 31 */
#define MMC_SOFT_PHY_CTRL1_IOMUX_ENABLE_SHIFT  			    ((uint32_t)31U)
#define MMC_SOFT_PHY_CTRL1_IOMUX_ENABLE_MASK  			    ((uint32_t)0x80000000U)


/*
* \brief Macros for Phy address control 4 register (Base Addr + 0x10C)
* @{
*/

#define MMC_SOFT_PHY_CTRL4_REG_OFFSET  			        ((uint32_t)0xCU)

/* Bit 4:0 */
#define MMC_SOFT_PHY_CTRL4_ITAPDLY_SHIFT  			    ((uint32_t)0U)
#define MMC_SOFT_PHY_CTRL4_ITAPDLY_MASK  			    ((uint32_t)0x0000001FU)

/* Bit 8 */
#define MMC_SOFT_PHY_CTRL4_ITAPDLYENA_SHIFT  			((uint32_t)8U)
#define MMC_SOFT_PHY_CTRL4_ITAPDLYENA_MASK  			((uint32_t)0x00000100U)

/* Bit 9 */
#define MMC_SOFT_PHY_CTRL4_ITAPCHGWIN_SHIFT  			((uint32_t)9U)
#define MMC_SOFT_PHY_CTRL4_ITAPCHGWIN_MASK  			((uint32_t)0x00000200U)

/* Bit 15:12 */
#define MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_SHIFT  			((uint32_t)12U)
#define MMC_SOFT_PHY_CTRL4_OTAPDLYSEL_MASK  			((uint32_t)0x0000F000U)

#define PHY_SOFT_OTAPDLY_CTRL_SEL_0				((uint32_t)0x0U)
#define PHY_SOFT_OTAPDLY_CTRL_SEL_1				((uint32_t)0x1U)
#define PHY_SOFT_OTAPDLY_CTRL_SEL_2				((uint32_t)0x2U)
#define PHY_SOFT_OTAPDLY_CTRL_SEL_4				((uint32_t)0x4U)
#define PHY_SOFT_OTAPDLY_CTRL_SEL_8				((uint32_t)0x8U)



/* Bit 20 */
#define MMC_SOFT_PHY_CTRL4_OTAPDLYENA_SHIFT  			((uint32_t)20U)
#define MMC_SOFT_PHY_CTRL4_OTAPDLYENA_MASK  			((uint32_t)0x00100000U)

#define MMC_SOFT_PHY_CTRL4_OTAPDLYENA_ENABLED  			((uint32_t)1U)
#define MMC_SOFT_PHY_CTRL4_OTAPDLYENA_DISABLED		    ((uint32_t)0U)


/*
* \brief Macros for Phy address control 5 register (Base Addr + 0x110)
* @{
*/
#define MMC_SOFT_PHY_CTRL5_REG_OFFSET  			        ((uint32_t)0x10U)

/* Bit 2:0 */
#define MMC_SOFT_PHY_CTRL5_CLKBUFSEL_SHIFT  			 ((uint32_t)0U)
#define MMC_SOFT_PHY_CTRL5_CLKBUFSEL_MASK  			    ((uint32_t)0x00000007U)

/* Bit 10:8 */
#define MMC_SOFT_PHY_CTRL5_FRQSEL_SHIFT  			     ((uint32_t)8U)
#define MMC_SOFT_PHY_CTRL5_FRQSEL_MASK  			     ((uint32_t)0x00000700U)

/* Bit 16 */
#define MMC_SOFT_PHY_CTRL5_SELDLYRXCLK_SHIFT  			((uint32_t)16U)
#define MMC_SOFT_PHY_CTRL5_SELDLYRXCLK_MASK  			((uint32_t)0x00010000U)

/* Bit 17 */
#define MMC_SOFT_PHY_CTRL5_SELDLYTXCLK_SHIFT  			((uint32_t)17U)
#define MMC_SOFT_PHY_CTRL5_SELDLYTXCLK_MASK  			((uint32_t)0x00020000U)

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initializes Sdhc Phy
 *
 *	This API initializes the Sdhc Phy layer before any sd/emmc transactions are initiated.
 *    This should be the first API to be called by the application.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDPhyInit(uintptr_t baseAddr);

/**
 * \brief   Initializes Sdhc Soft Phy
 *
 *	This API initializes the Sdhc Soft Phy layer before any sd/emmc transactions are initiated.
 *    This should be the first API to be called by the application.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSoftPhyInit(uintptr_t baseAddr);


/**
 * \brief   Configure Sdhc Phy for setting mode
 *
 *	This API configures Sdhc Phy layer for the specified mode/speed of the card.
 *    This API should be called before any card initialization or data transactions are initiated.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   mode        Speed mode to be configured
 *
 * \param   clock         Host controller clock value
 *
 * \param   driverType     Type of driver
 *
 * \range   for mode: \n    MODE_HS400 \n
 *						MODE_HS200 \n
 *						MODE_DDR50 \n
 *						MODE_HS \n
 *						MODE_DS \n
 *						MODE_ENHANCED_STROBE
 *		  for driverType: \n   DRIVER_TYPE_A \n
 *						   DRIVER_TYPE_B \n
 *						   DRIVER_TYPE_C \n
 *						   DRIVER_TYPE_D
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDPhyConfigure(uintptr_t baseAddr, uint32_t mode, uint32_t clock, uint32_t driverType);


/**
 * \brief   Configure Soft Phy for setting mode
 *
 *	This API configures Sdhc Phy layer for the specified mode/speed of the card.
 *    This API should be called before any card initialization or data transactions are initiated.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   mode        Speed mode to be configured
 *
 * \param   clock         Host controller clock value
 *
 * \param   driverType     Type of driver
 *
 * \range   for mode: \n    MODE_HS400 \n
 *						MODE_HS200 \n
 *						MODE_DDR50 \n
 *						MODE_HS \n
 *						MODE_DS \n
 *						MODE_ENHANCED_STROBE
 *		  for driverType: \n   DRIVER_TYPE_A \n
 *						   DRIVER_TYPE_B \n
 *						   DRIVER_TYPE_C \n
 *						   DRIVER_TYPE_D
 *
 * \return   Success/Error code as defined by macro STW_xxxx.
 *
 **/
int32_t HSMMCSDSoftPhyConfigure(uintptr_t baseAddr, uint32_t mode, uint32_t clock, uint32_t driverType);
/**
 * \brief   Configure Phy LDO Control Register
 *
 *	This API is called after the host clock is set. This enables/disables the phy LDO.
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \param   state        Enable / Disable
 *
 * \range   for state: \n    PHY_LDO_CTRL_LDO_EN_ENABLE \n
 *						PHY_LDO_CTRL_LDO_EN_DISABLE
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/
int32_t HSMMCSDPhyLDOSet(uintptr_t baseAddr, uint32_t state);

/**
 * \brief   Disables the PHY DLL
 *
 *	This API is called before any DLL configuration , typically during speed switches
 *
 * \param   baseAddr      Host controller register set base address. This base address
 *							is platform specific and provided by the application.
 *
 * \return   Success/Error code as defined by macro STW_xxxx
 *
 **/

int32_t HSMMCSDPhyDisableDLL (uintptr_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif /*#ifndef SDHC_PHY_H_*/
