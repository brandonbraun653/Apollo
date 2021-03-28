/*
 *  Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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
/***************************************************************************
*
*  Description     : This header file contains macros to read/write the host controller
*                          registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017   PB              0.1                 File structure creation
*  12-July-2017    PB              0.2                 Added macro definitions for CQ registers
*  19-July-2017    PB              0.3                 Added macro definitions for SD registers
*  28-July-2017    PB              1.0                 Modifications done for 64bit addressing
*  29-Aug-2017    PB              1.1                 Added comments in file for greater clarity
*
***************************************************************************/
/**
 *  \file hw_mmc.h
 *
 *  \brief Register-level header file for MMC
 *
**/

#ifndef HW_MMC_H_
#define HW_MMC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*
* \brief Macros for sd/emmc host controller register offset
* @{
*/
#define MMC_SDMASA                                                                                          ((uintptr_t)0x000U)
#define MMC_BLK                                                                                             ((uintptr_t)0x004U)
#define MMC_ARG                                                                                             ((uintptr_t)0x008U)
#define MMC_CMD                                                                                             ((uintptr_t)0x00cU)
#define MMC_RSP10                                                                                           ((uintptr_t)0x010U)
#define MMC_RSP32                                                                                           ((uintptr_t)0x014U)
#define MMC_RSP54                                                                                           ((uintptr_t)0x018U)
#define MMC_RSP76                                                                                           ((uintptr_t)0x01cU)
#define MMC_DATA                                                                                            ((uintptr_t)0x020U)
#define MMC_PSTATE                                                                                          ((uintptr_t)0x024U)
#define MMC_HCTL                                                                                            ((uintptr_t)0x028U)
#define MMC_SYSCTL                                                                                          ((uintptr_t)0x02cU)
#define MMC_STAT                                                                                            ((uintptr_t)0x030U)
#define MMC_IE                                                                                              ((uintptr_t)0x034U)
#define MMC_ISE                                                                                            ((uintptr_t)0x038U)
#define MMC_AC12                                                                                         ((uintptr_t)0x03cU)
#define MMC_CAPA                                                                                         ((uintptr_t)0x040U)
#define MMC_CAPA2                                                                                       ((uintptr_t)0x044U)
#define MMC_CUR_CAPA                                                                                 ((uintptr_t)0x048U)
#define MMC_FE                                                                                              ((uintptr_t)0x050U)
#define MMC_ADMAES                                                                                    ((uintptr_t)0x054U)
#define MMC_ADMASAL                                                                                  ((uintptr_t)0x058U)
#define MMC_ADMASAL2                                                                                ((uintptr_t)0x05cU)
#define MMC_PVINITSD                                                                                  ((uintptr_t)0x060U)
#define MMC_PVHSSDR12                                                                               ((uintptr_t)0x064U)
#define MMC_PVSDR25SDR50                                                                         ((uintptr_t)0x068U)
#define MMC_PVSDR104DDR50                                                                       ((uintptr_t)0x06cU)
#define MMC_BTCR                                                                                          ((uintptr_t)0x070U)
#define MMC_PVHS400                                                                                    ((uintptr_t)0x074U)
#define MMC_VREG                                                                                          ((uintptr_t)0x078U)
#define MMC_SHAREDBUSCONTROL                                                                 ((uintptr_t)0x0e0U)
#define MMC_REV                                                                                             ((uintptr_t)0x0fcU)
/* @} */

/*
* \brief Macros for emmc host controller register offset for Command Queuing
* @{
*/
#define MMC_CQBASE                                                                      ((uintptr_t)0x200)
#define MMC_CQVER                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x00)
#define MMC_CQCAP                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x04)
#define MMC_CQCFG                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x08)
#define MMC_CQCTL                                                                         ((uintptr_t)MMC_CQBASE+(uintptr_t)0x0C)
#define MMC_CQIS                                                                           ((uintptr_t)MMC_CQBASE+(uintptr_t)0x10)
#define MMC_CQISTE                                                                       ((uintptr_t)MMC_CQBASE+(uintptr_t)0x14)
#define MMC_CQISGE                                                                       ((uintptr_t)MMC_CQBASE+(uintptr_t)0x18)
#define MMC_CQIC                                                                           ((uintptr_t)MMC_CQBASE+(uintptr_t)0x1C)
#define MMC_CQTDLBA                                                                    ((uintptr_t)MMC_CQBASE+(uintptr_t)0x20)
#define MMC_CQTDLBAU                                                                  ((uintptr_t)MMC_CQBASE+(uintptr_t)0x24)
#define MMC_CQTDBR                                                                      ((uintptr_t)MMC_CQBASE+(uintptr_t)0x28)
#define MMC_CQTCN                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x2C)
#define MMC_CQDQS                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x30)
#define MMC_CQDPT                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x34)
#define MMC_CQTCLR                                                                       ((uintptr_t)MMC_CQBASE+(uintptr_t)0x38)
#define MMC_CQSSC1                                                                      ((uintptr_t)MMC_CQBASE+(uintptr_t)0x40)
#define MMC_CQSSC2                                                                      ((uintptr_t)MMC_CQBASE+(uintptr_t)0x44)
#define MMC_CQCRDCT                                                                    ((uintptr_t)MMC_CQBASE+(uintptr_t)0x48)
#define MMC_CQRMEM                                                                     ((uintptr_t)MMC_CQBASE+(uintptr_t)0x50)
#define MMC_CQTERRI                                                                     ((uintptr_t)MMC_CQBASE+(uintptr_t)0x54)
#define MMC_CQCRI                                                                         ((uintptr_t)MMC_CQBASE+(uintptr_t)0x58)
#define MMC_CQCRA                                                                        ((uintptr_t)MMC_CQBASE+(uintptr_t)0x5C)
/* @} */

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

/*
* \brief Macros for SDHC MMC_SDMASA (0x000h)
* @{
*/
#define MMC_SDMASA_SDMA_ADDR_SHIFT                                                                    ((uint32_t)0U)
#define MMC_SDMASA_SDMA_ADDR_MASK                                                                     ((uint32_t)0xffffffffU)
#define MMC_SDMASA_SDMA_ARG2_SHIFT                                                                           ((uint32_t)0U)
#define MMC_SDMASA_SDMA_ARG2_MASK                                                                            ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_BLK (0x004h)
* @{
*/
#define MMC_BLK_BLEN_SHIFT                                                                                   ((uint32_t)0U)
#define MMC_BLK_BLEN_MASK                                                                                    ((uint32_t)0x00000fffU)
#define MMC_BLK_BLEN_1BYTELEN                                                                                ((uint32_t)1U)
#define MMC_BLK_BLEN_2048BYTESLEN                                                                            ((uint32_t)2048U)
#define MMC_BLK_BLEN_3BYTESLEN                                                                               ((uint32_t)3U)
#define MMC_BLK_BLEN_2047BYTESLEN                                                                            ((uint32_t)2047U)
#define MMC_BLK_BLEN_2BYTESLEN                                                                               ((uint32_t)2U)
#define MMC_BLK_BLEN_511BYTESLEN                                                                             ((uint32_t)511U)
#define MMC_BLK_BLEN_512BYTESLEN                                                                             ((uint32_t)512U)
#define MMC_BLK_BLEN_NOTRANSFER                                                                              ((uint32_t)0U)

#define MMC_BLK_HSBB_SHIFT                                                                               ((uint32_t)12U)
#define MMC_BLK_HSBB_MASK                                                                                ((uint32_t)0x00007000U)
#define MMC_BLK_HSBB_4KBYTES                                                                           ((uint32_t)0U)
#define MMC_BLK_HSBB_8KBYTES                                                                           ((uint32_t)1U)
#define MMC_BLK_HSBB_16KBYTES                                                                           ((uint32_t)2U)
#define MMC_BLK_HSBB_32KBYTES                                                                           ((uint32_t)3U)
#define MMC_BLK_HSBB_64KBYTES                                                                           ((uint32_t)4U)
#define MMC_BLK_HSBB_128KBYTES                                                                           ((uint32_t)5U)
#define MMC_BLK_HSBB_256KBYTES                                                                           ((uint32_t)6U)
#define MMC_BLK_HSBB_512KBYTES                                                                           ((uint32_t)7U)

#define MMC_BLK_NBLK_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_BLK_NBLK_MASK                                                                                    ((uint32_t)0xffff0000U)
#define MMC_BLK_NBLK_1BLK                                                                                    ((uint32_t)1U)
#define MMC_BLK_NBLK_2BLKS                                                                                   ((uint32_t)2U)
#define MMC_BLK_NBLK_65535BLKS                                                                               ((uint32_t)65535U)
#define MMC_BLK_NBLK_STPCNT                                                                                  ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_ARG (0x008h)
* @{
*/
#define MMC_ARG_ARG_SHIFT                                                                                    ((uint32_t)0U)
#define MMC_ARG_ARG_MASK                                                                                     ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_CMD (0x00Ch)
* @{
*/
#define MMC_CMD_DE_SHIFT                                                                                     ((uint32_t)0U)
#define MMC_CMD_DE_MASK                                                                                      ((uint32_t)0x00000001U)
#define MMC_CMD_DE_DISABLE                                                                                   ((uint32_t)0U)
#define MMC_CMD_DE_ENABLE                                                                                    ((uint32_t)1U)

#define MMC_CMD_BCE_SHIFT                                                                                    ((uint32_t)1U)
#define MMC_CMD_BCE_MASK                                                                                     ((uint32_t)0x00000002U)
#define MMC_CMD_BCE_DISABLE                                                                                  ((uint32_t)0U)
#define MMC_CMD_BCE_ENABLE                                                                                   ((uint32_t)1U)

#define MMC_CMD_ACEN_SHIFT                                                                                   ((uint32_t)2U)
#define MMC_CMD_ACEN_MASK                                                                                    ((uint32_t)0x0000000cU)
#define MMC_CMD_ACEN_DISABLE                                                                                 ((uint32_t)0U)
#define MMC_CMD_ACEN_ENABLECMD12                                                                             ((uint32_t)1U)
#define MMC_CMD_ACEN_ENABLECMD23                                                                             ((uint32_t)2U)
#define MMC_CMD_ACEN_RESERVED                                                                                ((uint32_t)3U)

#define MMC_CMD_DDIR_SHIFT                                                                                   ((uint32_t)4U)
#define MMC_CMD_DDIR_MASK                                                                                    ((uint32_t)0x00000010U)
#define MMC_CMD_DDIR_READ                                                                                    ((uint32_t)1U)
#define MMC_CMD_DDIR_WRITE                                                                                   ((uint32_t)0U)

#define MMC_CMD_MSBS_SHIFT                                                                                   ((uint32_t)5U)
#define MMC_CMD_MSBS_MASK                                                                                    ((uint32_t)0x00000020U)
#define MMC_CMD_MSBS_MULTIBLK                                                                                ((uint32_t)1U)
#define MMC_CMD_MSBS_SGLEBLK                                                                                 ((uint32_t)0U)

#define MMC_CMD_RESERVED_SHIFT                                                                               ((uint32_t)6U)
#define MMC_CMD_RESERVED_MASK                                                                                ((uint32_t)0x0000ffc0U)

#define MMC_CMD_RSP_TYPE_SHIFT                                                                               ((uint32_t)16U)
#define MMC_CMD_RSP_TYPE_MASK                                                                                ((uint32_t)0x00030000U)
#define MMC_CMD_RSP_TYPE_NORSP                                                                               ((uint32_t)0U)
#define MMC_CMD_RSP_TYPE_LGHT36                                                                              ((uint32_t)1U)
#define MMC_CMD_RSP_TYPE_LGHT48                                                                              ((uint32_t)2U)
#define MMC_CMD_RSP_TYPE_LGHT48B                                                                             ((uint32_t)3U)

#define MMC_CMD_RESERVED1_SHIFT                                                                              ((uint32_t)18U)
#define MMC_CMD_RESERVED1_MASK                                                                               ((uint32_t)0x00040000U)

#define MMC_CMD_CCCE_SHIFT                                                                                   ((uint32_t)19U)
#define MMC_CMD_CCCE_MASK                                                                                    ((uint32_t)0x00080000U)
#define MMC_CMD_CCCE_NOCHECK                                                                                 ((uint32_t)0U)
#define MMC_CMD_CCCE_CHECK                                                                                   ((uint32_t)1U)

#define MMC_CMD_CICE_SHIFT                                                                                   ((uint32_t)20U)
#define MMC_CMD_CICE_MASK                                                                                    ((uint32_t)0x00100000U)
#define MMC_CMD_CICE_CHECK                                                                                   ((uint32_t)1U)
#define MMC_CMD_CICE_NOCHECK                                                                                 ((uint32_t)0U)

#define MMC_CMD_DP_SHIFT                                                                                     ((uint32_t)21U)
#define MMC_CMD_DP_MASK                                                                                      ((uint32_t)0x00200000U)
#define MMC_CMD_DP_NODATA                                                                                    ((uint32_t)0U)
#define MMC_CMD_DP_DATA                                                                                      ((uint32_t)1U)

#define MMC_CMD_CMD_TYPE_SHIFT                                                                               ((uint32_t)22U)
#define MMC_CMD_CMD_TYPE_MASK                                                                                ((uint32_t)0x00c00000U)
#define MMC_CMD_CMD_TYPE_NORMAL                                                                              ((uint32_t)0U)
#define MMC_CMD_CMD_TYPE_SUSPEND                                                                             ((uint32_t)1U)
#define MMC_CMD_CMD_TYPE_RESUME                                                                              ((uint32_t)2U)
#define MMC_CMD_CMD_TYPE_ABORT                                                                               ((uint32_t)3U)

#define MMC_CMD_INDX_SHIFT                                                                                   ((uint32_t)24U)
#define MMC_CMD_INDX_MASK                                                                                    ((uint32_t)0x3f000000U)
#define MMC_CMD_INDX_CMD0                                                                                    ((uint32_t)0U)
#define MMC_CMD_INDX_CMD1                                                                                    ((uint32_t)1U)
#define MMC_CMD_INDX_CMD2                                                                                    ((uint32_t)2U)
#define MMC_CMD_INDX_CMD3                                                                                    ((uint32_t)3U)
#define MMC_CMD_INDX_CMD4                                                                                    ((uint32_t)4U)
#define MMC_CMD_INDX_CMD5                                                                                    ((uint32_t)5U)
#define MMC_CMD_INDX_CMD6                                                                                    ((uint32_t)6U)
#define MMC_CMD_INDX_CMD7                                                                                    ((uint32_t)7U)
#define MMC_CMD_INDX_CMD8                                                                                    ((uint32_t)8U)
#define MMC_CMD_INDX_CMD9                                                                                    ((uint32_t)9U)
#define MMC_CMD_INDX_CMD10                                                                                   ((uint32_t)10U)
#define MMC_CMD_INDX_CMD11                                                                                   ((uint32_t)11U)
#define MMC_CMD_INDX_CMD12                                                                                   ((uint32_t)12U)
#define MMC_CMD_INDX_CMD13                                                                                   ((uint32_t)13U)
#define MMC_CMD_INDX_CMD14                                                                                   ((uint32_t)14U)
#define MMC_CMD_INDX_CMD15                                                                                   ((uint32_t)15U)
#define MMC_CMD_INDX_CMD16                                                                                   ((uint32_t)16U)
#define MMC_CMD_INDX_CMD17                                                                                   ((uint32_t)17U)
#define MMC_CMD_INDX_CMD18                                                                                   ((uint32_t)18U)
#define MMC_CMD_INDX_CMD19                                                                                   ((uint32_t)19U)
#define MMC_CMD_INDX_CMD20                                                                                   ((uint32_t)20U)
#define MMC_CMD_INDX_CMD21                                                                                   ((uint32_t)21U)
#define MMC_CMD_INDX_CMD22                                                                                   ((uint32_t)22U)
#define MMC_CMD_INDX_CMD23                                                                                   ((uint32_t)23U)
#define MMC_CMD_INDX_CMD24                                                                                   ((uint32_t)24U)
#define MMC_CMD_INDX_CMD25                                                                                   ((uint32_t)25U)
#define MMC_CMD_INDX_CMD26                                                                                   ((uint32_t)26U)
#define MMC_CMD_INDX_CMD27                                                                                   ((uint32_t)27U)
#define MMC_CMD_INDX_CMD28                                                                                   ((uint32_t)28U)
#define MMC_CMD_INDX_CMD29                                                                                   ((uint32_t)29U)
#define MMC_CMD_INDX_CMD30                                                                                   ((uint32_t)30U)
#define MMC_CMD_INDX_CMD31                                                                                   ((uint32_t)31U)
#define MMC_CMD_INDX_CMD32                                                                                   ((uint32_t)32U)
#define MMC_CMD_INDX_CMD33                                                                                   ((uint32_t)33U)
#define MMC_CMD_INDX_CMD34                                                                                   ((uint32_t)34U)
#define MMC_CMD_INDX_CMD35                                                                                   ((uint32_t)35U)
#define MMC_CMD_INDX_CMD36                                                                                   ((uint32_t)36U)
#define MMC_CMD_INDX_CMD37                                                                                   ((uint32_t)37U)
#define MMC_CMD_INDX_CMD38                                                                                   ((uint32_t)38U)
#define MMC_CMD_INDX_CMD39                                                                                   ((uint32_t)39U)
#define MMC_CMD_INDX_CMD40                                                                                   ((uint32_t)40U)
#define MMC_CMD_INDX_CMD41                                                                                   ((uint32_t)41U)
#define MMC_CMD_INDX_CMD42                                                                                   ((uint32_t)42U)
#define MMC_CMD_INDX_CMD43                                                                                   ((uint32_t)43U)
#define MMC_CMD_INDX_CMD44                                                                                   ((uint32_t)44U)
#define MMC_CMD_INDX_CMD45                                                                                   ((uint32_t)45U)
#define MMC_CMD_INDX_CMD46                                                                                   ((uint32_t)46U)
#define MMC_CMD_INDX_CMD47                                                                                   ((uint32_t)47U)
#define MMC_CMD_INDX_CMD48                                                                                   ((uint32_t)48U)
#define MMC_CMD_INDX_CMD49                                                                                   ((uint32_t)49U)
#define MMC_CMD_INDX_CMD50                                                                                   ((uint32_t)50U)
#define MMC_CMD_INDX_CMD51                                                                                   ((uint32_t)51U)
#define MMC_CMD_INDX_CMD52                                                                                   ((uint32_t)52U)
#define MMC_CMD_INDX_CMD53                                                                                   ((uint32_t)53U)
#define MMC_CMD_INDX_CMD54                                                                                   ((uint32_t)54U)
#define MMC_CMD_INDX_CMD55                                                                                   ((uint32_t)55U)
#define MMC_CMD_INDX_CMD56                                                                                   ((uint32_t)56U)
#define MMC_CMD_INDX_CMD57                                                                                   ((uint32_t)57U)
#define MMC_CMD_INDX_CMD58                                                                                   ((uint32_t)58U)
#define MMC_CMD_INDX_CMD59                                                                                   ((uint32_t)59U)
#define MMC_CMD_INDX_CMD60                                                                                   ((uint32_t)60U)
#define MMC_CMD_INDX_CMD61                                                                                   ((uint32_t)61U)
#define MMC_CMD_INDX_CMD62                                                                                   ((uint32_t)62U)
#define MMC_CMD_INDX_CMD63                                                                                   ((uint32_t)63U)

#define MMC_CMD_RESERVED2_SHIFT                                                                          ((uint32_t)30U)
#define MMC_CMD_RESERVED2_MASK                                                                           ((uint32_t)0xc0000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_RSP10 (0x010h)
* @{
*/
#define MMC_RSP10_RSP1_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_RSP10_RSP1_MASK                                                                                  ((uint32_t)0xffff0000U)

#define MMC_RSP10_RSP0_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_RSP10_RSP0_MASK                                                                                  ((uint32_t)0x0000ffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_RSP32 (0x014h)
* @{
*/
#define MMC_RSP32_RSP3_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_RSP32_RSP3_MASK                                                                                  ((uint32_t)0xffff0000U)

#define MMC_RSP32_RSP2_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_RSP32_RSP2_MASK                                                                                  ((uint32_t)0x0000ffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_RSP54 (0x018h)
* @{
*/
#define MMC_RSP54_RSP5_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_RSP54_RSP5_MASK                                                                                  ((uint32_t)0xffff0000U)

#define MMC_RSP54_RSP4_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_RSP54_RSP4_MASK                                                                                  ((uint32_t)0x0000ffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_RSP76 (0x01Ch)
* @{
*/
#define MMC_RSP76_RSP6_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_RSP76_RSP6_MASK                                                                                  ((uint32_t)0x0000ffffU)

#define MMC_RSP76_RSP7_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_RSP76_RSP7_MASK                                                                                  ((uint32_t)0xffff0000U)
/* @} */

/*
* \brief Macros for SDHC MMC_DATA (0x020h)
* @{
*/
#define MMC_DATA_DATA_SHIFT                                                                                  ((uint32_t)0U)
#define MMC_DATA_DATA_MASK                                                                                   ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_PSTATE (0x024h)
* @{
*/
#define MMC_PSTATE_CMDI_SHIFT                                                                                ((uint32_t)0U)
#define MMC_PSTATE_CMDI_MASK                                                                                 ((uint32_t)0x00000001U)
#define MMC_PSTATE_CMDI_CMDDIS                                                                               ((uint32_t)1U)
#define MMC_PSTATE_CMDI_CMDEN                                                                                ((uint32_t)0U)

#define MMC_PSTATE_DATI_SHIFT                                                                                ((uint32_t)1U)
#define MMC_PSTATE_DATI_MASK                                                                                 ((uint32_t)0x00000002U)
#define MMC_PSTATE_DATI_CMDDIS                                                                               ((uint32_t)1U)
#define MMC_PSTATE_DATI_CMDEN                                                                                ((uint32_t)0U)

#define MMC_PSTATE_DLA_SHIFT                                                                                 ((uint32_t)2U)
#define MMC_PSTATE_DLA_MASK                                                                                  ((uint32_t)0x00000004U)
#define MMC_PSTATE_DLA_ZERO                                                                                  ((uint32_t)0U)
#define MMC_PSTATE_DLA_ONE                                                                                   ((uint32_t)1U)

#define MMC_PSTATE_RTR_SHIFT                                                                                 ((uint32_t)3U)
#define MMC_PSTATE_RTR_MASK                                                                                  ((uint32_t)0x00000008U)
#define MMC_PSTATE_RTR_NOTUNING                                                                              ((uint32_t)0U)
#define MMC_PSTATE_RTR_TUNING                                                                                ((uint32_t)1U)

#define MMC_PSTATE_RESERVED_SHIFT                                                                            ((uint32_t)4U)
#define MMC_PSTATE_RESERVED_MASK                                                                             ((uint32_t)0x000000f0U)

#define MMC_PSTATE_WTA_SHIFT                                                                                 ((uint32_t)8U)
#define MMC_PSTATE_WTA_MASK                                                                                  ((uint32_t)0x00000100U)
#define MMC_PSTATE_WTA_NOTRANSFER                                                                            ((uint32_t)0U)
#define MMC_PSTATE_WTA_TRANSFER                                                                              ((uint32_t)1U)

#define MMC_PSTATE_RTA_SHIFT                                                                                 ((uint32_t)9U)
#define MMC_PSTATE_RTA_MASK                                                                                  ((uint32_t)0x00000200U)
#define MMC_PSTATE_RTA_TRANSFER                                                                              ((uint32_t)1U)
#define MMC_PSTATE_RTA_NOTRANSFER                                                                            ((uint32_t)0U)

#define MMC_PSTATE_BWE_SHIFT                                                                                 ((uint32_t)10U)
#define MMC_PSTATE_BWE_MASK                                                                                  ((uint32_t)0x00000400U)
#define MMC_PSTATE_BWE_WRENABLE                                                                              ((uint32_t)1U)
#define MMC_PSTATE_BWE_WRDISABLE                                                                             ((uint32_t)0U)

#define MMC_PSTATE_BRE_SHIFT                                                                                 ((uint32_t)11U)
#define MMC_PSTATE_BRE_MASK                                                                                  ((uint32_t)0x00000800U)
#define MMC_PSTATE_BRE_RDDISABLE                                                                             ((uint32_t)0U)
#define MMC_PSTATE_BRE_RDENABLE                                                                              ((uint32_t)1U)

#define MMC_PSTATE_RESERVED1_SHIFT                                                                           ((uint32_t)12U)
#define MMC_PSTATE_RESERVED1_MASK                                                                            ((uint32_t)0x0000f000U)

#define MMC_PSTATE_CINS_SHIFT                                                                                ((uint32_t)16U)
#define MMC_PSTATE_CINS_MASK                                                                                 ((uint32_t)0x00010000U)
#define MMC_PSTATE_CINS_ZERO                                                                                 ((uint32_t)0U)
#define MMC_PSTATE_CINS_ONE                                                                                  ((uint32_t)1U)

#define MMC_PSTATE_CSS_SHIFT                                                                                 ((uint32_t)17U)
#define MMC_PSTATE_CSS_MASK                                                                                  ((uint32_t)0x00020000U)
#define MMC_PSTATE_CSS_STABLE                                                                                ((uint32_t)1U)
#define MMC_PSTATE_CSS_DEBOUNCING                                                                            ((uint32_t)0U)

#define MMC_PSTATE_CDPL_SHIFT                                                                                ((uint32_t)18U)
#define MMC_PSTATE_CDPL_MASK                                                                                 ((uint32_t)0x00040000U)
#define MMC_PSTATE_CDPL_ZERO                                                                                 ((uint32_t)0U)
#define MMC_PSTATE_CDPL_ONE                                                                                  ((uint32_t)1U)

#define MMC_PSTATE_WP_SHIFT                                                                                  ((uint32_t)19U)
#define MMC_PSTATE_WP_MASK                                                                                   ((uint32_t)0x00080000U)
#define MMC_PSTATE_WP_ONE                                                                                    ((uint32_t)1U)
#define MMC_PSTATE_WP_ZERO                                                                                   ((uint32_t)0U)

#define MMC_PSTATE_DLEV_SHIFT                                                                                ((uint32_t)20U)
#define MMC_PSTATE_DLEV_MASK                                                                                 ((uint32_t)0x00f00000U)

#define MMC_PSTATE_CLEV_SHIFT                                                                                ((uint32_t)24U)
#define MMC_PSTATE_CLEV_MASK                                                                                 ((uint32_t)0x01000000U)
#define MMC_PSTATE_CLEV_ZERO                                                                                 ((uint32_t)0U)
#define MMC_PSTATE_CLEV_ONE                                                                                  ((uint32_t)1U)

#define MMC_PSTATE_RESERVED2_SHIFT                                                                           ((uint32_t)25U)
#define MMC_PSTATE_RESERVED2_MASK                                                                            ((uint32_t)0xfe000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_HCTL (0x028h)
* @{
*/
#define MMC_HCTL_LED_SHIFT                                                                                   ((uint32_t)0U)
#define MMC_HCTL_LED_MASK                                                                                    ((uint32_t)0x00000001U)

#define MMC_HCTL_DTW_SHIFT                                                                                   ((uint32_t)1U)
#define MMC_HCTL_DTW_MASK                                                                                    ((uint32_t)0x00000002U)
#define MMC_HCTL_DTW_1_BITMODE                                                                          ((uint32_t)0U)
#define MMC_HCTL_DTW_4_BITMODE                                                                          ((uint32_t)1U)

#define MMC_HCTL_HSPE_SHIFT                                                                                  ((uint32_t)2U)
#define MMC_HCTL_HSPE_MASK                                                                                   ((uint32_t)0x00000004U)
#define MMC_HCTL_HSPE_NORMALSPEED                                                                    ((uint32_t)0U)
#define MMC_HCTL_HSPE_HIGHSPEED                                                                         ((uint32_t)1U)

#define MMC_HCTL_DMAS_SHIFT                                                                              ((uint32_t)3U)
#define MMC_HCTL_DMAS_MASK                                                                               ((uint32_t)0x00000018U)
#define MMC_HCTL_DMAS_SDMA                                                                               ((uint32_t)0U)
#define MMC_HCTL_DMAS_RESERVED1                                                                      ((uint32_t)1U)
#define MMC_HCTL_DMAS_ADMA2_32BIT                                                                  ((uint32_t)2U)
#define MMC_HCTL_DMAS_ADMA2_64BIT                                                                  ((uint32_t)3U)

#define MMC_HCTL_EDTW_SHIFT                                                                              ((uint32_t)5U)
#define MMC_HCTL_EDTW_MASK                                                                               ((uint32_t)0x00000020U)
#define MMC_HCTL_EDTW_8BIT_ENABLE                                                                  ((uint32_t)1U)
#define MMC_HCTL_EDTW_8BIT_DISABLE                                                                 ((uint32_t)0U)

#define MMC_HCTL_CDTL_SHIFT                                                                                  ((uint32_t)6U)
#define MMC_HCTL_CDTL_MASK                                                                                   ((uint32_t)0x00000040U)
#define MMC_HCTL_CDTL_NOCARD                                                                                 ((uint32_t)0U)
#define MMC_HCTL_CDTL_CARDINS                                                                                ((uint32_t)1U)

#define MMC_HCTL_CDSS_SHIFT                                                                                  ((uint32_t)7U)
#define MMC_HCTL_CDSS_MASK                                                                                   ((uint32_t)0x00000080U)
#define MMC_HCTL_CDSS_SDCDSEL                                                                                ((uint32_t)0U)
#define MMC_HCTL_CDSS_CDTLSEL                                                                                ((uint32_t)1U)

#define MMC_HCTL_SDBP_SHIFT                                                                                  ((uint32_t)8U)
#define MMC_HCTL_SDBP_MASK                                                                                   ((uint32_t)0x00000100U)
#define MMC_HCTL_SDBP_PWROFF                                                                                 ((uint32_t)0U)
#define MMC_HCTL_SDBP_PWRON                                                                                  ((uint32_t)1U)

#define MMC_HCTL_SDVS_SHIFT                                                                                  ((uint32_t)9U)
#define MMC_HCTL_SDVS_MASK                                                                                   ((uint32_t)0x00000e00U)
#define MMC_HCTL_SDVS_1V8                                                                                    ((uint32_t)5U)
#define MMC_HCTL_SDVS_3V0                                                                                    ((uint32_t)6U)
#define MMC_HCTL_SDVS_3V3                                                                                    ((uint32_t)7U)

#define MMC_HCTL_EMMC_HW_RST_SHIFT                                                                 ((uint32_t)12U)
#define MMC_HCTL_EMMC_HW_RST_MASK                                                                  ((uint32_t)0x00001000U)
#define MMC_HCTL_EMMC_HW_RST_SET                                                                     ((uint32_t)1U)
#define MMC_HCTL_EMMC_HW_RST_CLEAR                                                                 ((uint32_t)0U)

#define MMC_HCTL_RESERVED1_SHIFT                                                                             ((uint32_t)13U)
#define MMC_HCTL_RESERVED1_MASK                                                                              ((uint32_t)0x0000e000U)

#define MMC_HCTL_SBGR_SHIFT                                                                                  ((uint32_t)16U)
#define MMC_HCTL_SBGR_MASK                                                                                   ((uint32_t)0x00010000U)
#define MMC_HCTL_SBGR_TRANSFER                                                                               ((uint32_t)0U)
#define MMC_HCTL_SBGR_STPBLK                                                                                 ((uint32_t)1U)

#define MMC_HCTL_CR_SHIFT                                                                                    ((uint32_t)17U)
#define MMC_HCTL_CR_MASK                                                                                     ((uint32_t)0x00020000U)
#define MMC_HCTL_CR_NONE                                                                                     ((uint32_t)0U)
#define MMC_HCTL_CR_RESTART                                                                                  ((uint32_t)1U)

#define MMC_HCTL_RWC_SHIFT                                                                                   ((uint32_t)18U)
#define MMC_HCTL_RWC_MASK                                                                                    ((uint32_t)0x00040000U)
#define MMC_HCTL_RWC_RW                                                                                      ((uint32_t)1U)
#define MMC_HCTL_RWC_NORW                                                                                    ((uint32_t)0U)

#define MMC_HCTL_IBG_SHIFT                                                                                   ((uint32_t)19U)
#define MMC_HCTL_IBG_MASK                                                                                    ((uint32_t)0x00080000U)
#define MMC_HCTL_IBG_ITDIABLE                                                                                ((uint32_t)0U)
#define MMC_HCTL_IBG_ITENABLE                                                                                ((uint32_t)1U)

#define MMC_HCTL_SPI_MODE_SHIFT                                                                           ((uint32_t)20U)
#define MMC_HCTL_SPI_MODE_MASK                                                                            ((uint32_t)0x00100000U)
#define MMC_HCTL_SPI_MODE                                                                                   ((uint32_t)1U)
#define MMC_HCTL_SD_MODE                                                                                   ((uint32_t)0U)

#define MMC_HCTL_BOOTEN_SHIFT                                                                           ((uint32_t)21U)
#define MMC_HCTL_BOOTEN_MASK                                                                            ((uint32_t)0x00200000U)
#define MMC_HCTL_START_BOOT_ACCESS                                                                 ((uint32_t)1U)
#define MMC_HCTL_STOP_BOOT_ACCESS                                                                   ((uint32_t)0U)

#define MMC_HCTL_ALTBOOTEN_SHIFT                                                                     ((uint32_t)22U)
#define MMC_HCTL_ALTBOOTEN_MASK                                                                      ((uint32_t)0x00400000U)
#define MMC_HCTL_START_ALTBOOT_ACCESS                                                                 ((uint32_t)1U)
#define MMC_HCTL_STOP_ALTBOOT_ACCESS                                                                   ((uint32_t)0U)

#define MMC_HCTL_BOOTACK_SHIFT                                                                             ((uint32_t)23U)
#define MMC_HCTL_BOOTACK_MASK                                                                              ((uint32_t)0x00800000U)
#define MMC_HCTL_WAIT_BOOT_ACK                                                                         ((uint32_t)1U)
#define MMC_HCTL_NOWAIT_BOOT_ACK                                                                    ((uint32_t)0U)

#define MMC_HCTL_IWE_SHIFT                                                                                   ((uint32_t)24U)
#define MMC_HCTL_IWE_MASK                                                                                    ((uint32_t)0x01000000U)
#define MMC_HCTL_IWE_ENABLE                                                                                  ((uint32_t)1U)
#define MMC_HCTL_IWE_DISABLE                                                                                 ((uint32_t)0U)

#define MMC_HCTL_INS_SHIFT                                                                                   ((uint32_t)25U)
#define MMC_HCTL_INS_MASK                                                                                    ((uint32_t)0x02000000U)
#define MMC_HCTL_INS_ENABLE                                                                                  ((uint32_t)1U)
#define MMC_HCTL_INS_DISABLE                                                                                 ((uint32_t)0U)

#define MMC_HCTL_REM_SHIFT                                                                                   ((uint32_t)26U)
#define MMC_HCTL_REM_MASK                                                                                    ((uint32_t)0x04000000U)
#define MMC_HCTL_REM_ENABLE                                                                                  ((uint32_t)1U)
#define MMC_HCTL_REM_DISABLE                                                                                 ((uint32_t)0U)

#define MMC_HCTL_RESERVED3_SHIFT                                                                             ((uint32_t)27U)
#define MMC_HCTL_RESERVED3_MASK                                                                              ((uint32_t)0xf8000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_SYSCTL (0x02Ch)
* @{
*/
#define MMC_SYSCTL_ICE_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_SYSCTL_ICE_MASK                                                                                  ((uint32_t)0x00000001U)
#define MMC_SYSCTL_ICE_OSCILLATE                                                                         ((uint32_t)1U)
#define MMC_SYSCTL_ICE_STOP                                                                                  ((uint32_t)0U)

#define MMC_SYSCTL_ICS_SHIFT                                                                                 ((uint32_t)1U)
#define MMC_SYSCTL_ICS_MASK                                                                                  ((uint32_t)0x00000002U)
#define MMC_SYSCTL_ICS_NOTREADY                                                                           ((uint32_t)0U)
#define MMC_SYSCTL_ICS_READY                                                                                 ((uint32_t)1U)

#define MMC_SYSCTL_CEN_SHIFT                                                                                 ((uint32_t)2U)
#define MMC_SYSCTL_CEN_MASK                                                                                  ((uint32_t)0x00000004U)
#define MMC_SYSCTL_CEN_ENABLE                                                                                ((uint32_t)1U)
#define MMC_SYSCTL_CEN_DISABLE                                                                               ((uint32_t)0U)

#define MMC_SYSCTL_RESERVED1_SHIFT                                                                            ((uint32_t)3U)
#define MMC_SYSCTL_RESERVED1_MASK                                                                             ((uint32_t)0x00000018U)

#define MMC_SYSCTL_CGS_SHIFT                                                                                 ((uint32_t)5U)
#define MMC_SYSCTL_CGS_MASK                                                                                  ((uint32_t)0x00000020U)

#define MMC_SYSCTL_CLKD_SHIFT                                                                                ((uint32_t)6U)
#define MMC_SYSCTL_CLKD_MASK                                                                                 ((uint32_t)0x0000ffc0U)
#define MMC_SYSCTL_CLKD_BYPASS1                                                                              ((uint32_t)1U)
#define MMC_SYSCTL_CLKD_DIV2                                                                                 ((uint32_t)2U)
#define MMC_SYSCTL_CLKD_DIV3                                                                                 ((uint32_t)3U)
#define MMC_SYSCTL_CLKD_BYPASS0                                                                              ((uint32_t)0U)
#define MMC_SYSCTL_CLKD_DIV1023                                                                              ((uint32_t)1023U)

#define MMC_SYSCTL_DTO_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_SYSCTL_DTO_MASK                                                                                  ((uint32_t)0x000f0000U)
#define MMC_SYSCTL_DTO_15THDTO                                                                               ((uint32_t)14U)
#define MMC_SYSCTL_DTO_RSVD                                                                                  ((uint32_t)15U)
#define MMC_SYSCTL_DTO_1STDTO                                                                                ((uint32_t)0U)
#define MMC_SYSCTL_DTO_2NDDTO                                                                                ((uint32_t)1U)

#define MMC_SYSCTL_RESERVED2_SHIFT                                                                           ((uint32_t)20U)
#define MMC_SYSCTL_RESERVED2_MASK                                                                            ((uint32_t)0x00f00000U)

#define MMC_SYSCTL_SRA_SHIFT                                                                                 ((uint32_t)24U)
#define MMC_SYSCTL_SRA_MASK                                                                                  ((uint32_t)0x01000000U)
#define MMC_SYSCTL_SRA_WORK                                                                                  ((uint32_t)0U)
#define MMC_SYSCTL_SRA_RESET                                                                                 ((uint32_t)1U)

#define MMC_SYSCTL_SRC_SHIFT                                                                                 ((uint32_t)25U)
#define MMC_SYSCTL_SRC_MASK                                                                                  ((uint32_t)0x02000000U)
#define MMC_SYSCTL_SRC_WORK                                                                                  ((uint32_t)0U)
#define MMC_SYSCTL_SRC_RESET                                                                                 ((uint32_t)1U)

#define MMC_SYSCTL_SRD_SHIFT                                                                                 ((uint32_t)26U)
#define MMC_SYSCTL_SRD_MASK                                                                                  ((uint32_t)0x04000000U)
#define MMC_SYSCTL_SRD_WORK                                                                                  ((uint32_t)0U)
#define MMC_SYSCTL_SRD_RESET                                                                                 ((uint32_t)1U)

#define MMC_SYSCTL_RESERVED3_SHIFT                                                                           ((uint32_t)27U)
#define MMC_SYSCTL_RESERVED3_MASK                                                                            ((uint32_t)0xf8000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_SDMASA (0x030h)
* @{
*/
#define MMC_STAT_CC_SHIFT                                                                                    ((uint32_t)0U)
#define MMC_STAT_CC_MASK                                                                                     ((uint32_t)0x00000001U)
#define MMC_STAT_CC_IRQ_TRU_R                                                                                ((uint32_t)1U)
#define MMC_STAT_CC_ST_RST_W                                                                                 ((uint32_t)1U)
#define MMC_STAT_CC_IRQ_FAL_R                                                                                ((uint32_t)0U)
#define MMC_STAT_CC_ST_UN_W                                                                                  ((uint32_t)0U)

#define MMC_STAT_TC_SHIFT                                                                                    ((uint32_t)1U)
#define MMC_STAT_TC_MASK                                                                                     ((uint32_t)0x00000002U)
#define MMC_STAT_TC_IRQ_TRU_R                                                                                ((uint32_t)1U)
#define MMC_STAT_TC_ST_RST_W                                                                                 ((uint32_t)1U)
#define MMC_STAT_TC_IRQ_FAL_R                                                                                ((uint32_t)0U)
#define MMC_STAT_TC_ST_UN_W                                                                                  ((uint32_t)0U)

#define MMC_STAT_BGE_SHIFT                                                                                   ((uint32_t)2U)
#define MMC_STAT_BGE_MASK                                                                                    ((uint32_t)0x00000004U)
#define MMC_STAT_BGE_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_BGE_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_BGE_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_BGE_ST_RST_W                                                                                ((uint32_t)1U)

#define MMC_STAT_DMA_SHIFT                                                                                   ((uint32_t)3U)
#define MMC_STAT_DMA_MASK                                                                                    ((uint32_t)0x00000008U)
#define MMC_STAT_DMA_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_DMA_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_DMA_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_DMA_ST_RST_W                                                                                ((uint32_t)1U)

#define MMC_STAT_BWR_SHIFT                                                                                   ((uint32_t)4U)
#define MMC_STAT_BWR_MASK                                                                                    ((uint32_t)0x00000010U)
#define MMC_STAT_BWR_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_BWR_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_BWR_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_BWR_ST_UN_W                                                                                 ((uint32_t)0U)

#define MMC_STAT_BRR_SHIFT                                                                                   ((uint32_t)5U)
#define MMC_STAT_BRR_MASK                                                                                    ((uint32_t)0x00000020U)
#define MMC_STAT_BRR_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_BRR_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_BRR_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_BRR_IRQ_TRU_R                                                                               ((uint32_t)1U)

#define MMC_STAT_CINS_SHIFT                                                                                  ((uint32_t)6U)
#define MMC_STAT_CINS_MASK                                                                                   ((uint32_t)0x00000040U)
#define MMC_STAT_CINS_IRQ_TRU_R                                                                              ((uint32_t)1U)
#define MMC_STAT_CINS_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_CINS_ST_UN_W                                                                                ((uint32_t)0U)
#define MMC_STAT_CINS_ST_RST_W                                                                               ((uint32_t)1U)

#define MMC_STAT_CREM_SHIFT                                                                                  ((uint32_t)7U)
#define MMC_STAT_CREM_MASK                                                                                   ((uint32_t)0x00000080U)
#define MMC_STAT_CREM_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_CREM_ST_UN_W                                                                                ((uint32_t)0U)
#define MMC_STAT_CREM_ST_RST_W                                                                               ((uint32_t)1U)
#define MMC_STAT_CREM_IRQ_TRU_R                                                                              ((uint32_t)1U)

#define MMC_STAT_CIRQ_SHIFT                                                                                  ((uint32_t)8U)
#define MMC_STAT_CIRQ_MASK                                                                                   ((uint32_t)0x00000100U)
#define MMC_STAT_CIRQ_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_CIRQ_IRQ_TRU_R                                                                              ((uint32_t)1U)

#define MMC_STAT_INTA_SHIFT                                                                                   ((uint32_t)9U)
#define MMC_STAT_INTA_MASK                                                                                    ((uint32_t)0x00000200U)
#define MMC_STAT_INTA_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_INTA_IRQ_TRU_R                                                                               ((uint32_t)1U)

#define MMC_STAT_INTB_SHIFT                                                                                   ((uint32_t)10U)
#define MMC_STAT_INTB_MASK                                                                                    ((uint32_t)0x00000400U)
#define MMC_STAT_INTB_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_INTB_IRQ_FAL_R                                                                               ((uint32_t)0U)

#define MMC_STAT_INTC_SHIFT                                                                                   ((uint32_t)11U)
#define MMC_STAT_INTC_MASK                                                                                    ((uint32_t)0x00000800U)
#define MMC_STAT_INTC_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_INTC_IRQ_FAL_R                                                                               ((uint32_t)0U)

#define MMC_STAT_RTE_SHIFT                                                                                   ((uint32_t)12U)
#define MMC_STAT_RTE_MASK                                                                                    ((uint32_t)0x00001000U)
#define MMC_STAT_RTE_IRQ_TRU_R                                                                                   ((uint32_t)1U)
#define MMC_STAT_RTE_IRQ_FAL_R                                                                                   ((uint32_t)0U)

#define MMC_STAT_BAR_SHIFT                                                                              ((uint32_t)13U)
#define MMC_STAT_BAR_MASK                                                                               ((uint32_t)0x00002000U)
#define MMC_STAT_BAR_IRQ_TRU_R                                                                                   ((uint32_t)1U)
#define MMC_STAT_BAR_IRQ_FAL_R                                                                                   ((uint32_t)0U)
#define MMC_STAT_BAR_ST_RST_W                                                                                   ((uint32_t)1U)
#define MMC_STAT_BAR_ST_UN_W                                                                                   ((uint32_t)0U)

#define MMC_STAT_BTI_SHIFT                                                                              ((uint32_t)14U)
#define MMC_STAT_BTI_MASK                                                                               ((uint32_t)0x00004000U)
#define MMC_STAT_BTI_IRQ_TRU_R                                                                                   ((uint32_t)1U)
#define MMC_STAT_BTI_IRQ_FAL_R                                                                                   ((uint32_t)0U)
#define MMC_STAT_BTI_ST_RST_W                                                                                   ((uint32_t)1U)
#define MMC_STAT_BTI_ST_UN_W                                                                                   ((uint32_t)0U)

#define MMC_STAT_ERRI_SHIFT                                                                                  ((uint32_t)15U)
#define MMC_STAT_ERRI_MASK                                                                                   ((uint32_t)0x00008000U)
#define MMC_STAT_ERRI_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_ERRI_IRQ_TRU_R                                                                              ((uint32_t)1U)

#define MMC_STAT_CTO_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_STAT_CTO_MASK                                                                                    ((uint32_t)0x00010000U)
#define MMC_STAT_CTO_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_CTO_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_CTO_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_CTO_ST_UN_W                                                                                 ((uint32_t)0U)

#define MMC_STAT_CCRC_SHIFT                                                                                  ((uint32_t)17U)
#define MMC_STAT_CCRC_MASK                                                                                   ((uint32_t)0x00020000U)
#define MMC_STAT_CCRC_IRQ_TRU_R                                                                              ((uint32_t)1U)
#define MMC_STAT_CCRC_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_CCRC_ST_UN_W                                                                                ((uint32_t)0U)
#define MMC_STAT_CCRC_ST_RST_W                                                                               ((uint32_t)1U)

#define MMC_STAT_CEB_SHIFT                                                                                   ((uint32_t)18U)
#define MMC_STAT_CEB_MASK                                                                                    ((uint32_t)0x00040000U)
#define MMC_STAT_CEB_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_CEB_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_CEB_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_CEB_ST_UN_W                                                                                 ((uint32_t)0U)

#define MMC_STAT_CIE_SHIFT                                                                                   ((uint32_t)19U)
#define MMC_STAT_CIE_MASK                                                                                    ((uint32_t)0x00080000U)
#define MMC_STAT_CIE_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_CIE_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_CIE_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_CIE_IRQ_FAL_R                                                                               ((uint32_t)0U)

#define MMC_STAT_DTO_SHIFT                                                                                   ((uint32_t)20U)
#define MMC_STAT_DTO_MASK                                                                                    ((uint32_t)0x00100000U)
#define MMC_STAT_DTO_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_DTO_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_DTO_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_DTO_ST_RST_W                                                                                ((uint32_t)1U)

#define MMC_STAT_DCRC_SHIFT                                                                                  ((uint32_t)21U)
#define MMC_STAT_DCRC_MASK                                                                                   ((uint32_t)0x00200000U)
#define MMC_STAT_DCRC_ST_RST_W                                                                               ((uint32_t)1U)
#define MMC_STAT_DCRC_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_DCRC_ST_UN_W                                                                                ((uint32_t)0U)
#define MMC_STAT_DCRC_IRQ_TRU_R                                                                              ((uint32_t)1U)

#define MMC_STAT_DEB_SHIFT                                                                                   ((uint32_t)22U)
#define MMC_STAT_DEB_MASK                                                                                    ((uint32_t)0x00400000U)
#define MMC_STAT_DEB_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_DEB_IRQ_TRU_R                                                                               ((uint32_t)1U)
#define MMC_STAT_DEB_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_DEB_ST_RST_W                                                                                ((uint32_t)1U)

#define MMC_STAT_RESERVED1_SHIFT                                                                             ((uint32_t)23U)
#define MMC_STAT_RESERVED1_MASK                                                                              ((uint32_t)0x00800000U)

#define MMC_STAT_ACE_SHIFT                                                                                   ((uint32_t)24U)
#define MMC_STAT_ACE_MASK                                                                                    ((uint32_t)0x01000000U)
#define MMC_STAT_ACE_IRQ_FAL_R                                                                               ((uint32_t)0U)
#define MMC_STAT_ACE_ST_UN_W                                                                                 ((uint32_t)0U)
#define MMC_STAT_ACE_ST_RST_W                                                                                ((uint32_t)1U)
#define MMC_STAT_ACE_IRQ_TRU_R                                                                               ((uint32_t)1U)

#define MMC_STAT_ADMAE_SHIFT                                                                                 ((uint32_t)25U)
#define MMC_STAT_ADMAE_MASK                                                                                  ((uint32_t)0x02000000U)
#define MMC_STAT_ADMAE_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_STAT_ADMAE_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_STAT_ADMAE_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_STAT_ADMAE_ST_UN_W                                                                               ((uint32_t)0U)

#define MMC_STAT_TE_SHIFT                                                                                    ((uint32_t)26U)
#define MMC_STAT_TE_MASK                                                                                     ((uint32_t)0x04000000U)
#define MMC_STAT_TE_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_STAT_TE_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_STAT_TE_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_STAT_TE_ST_UN_W                                                                               ((uint32_t)0U)

#define MMC_STAT_RESERVED2_SHIFT                                                                             ((uint32_t)27U)
#define MMC_STAT_RESERVED2_MASK                                                                              ((uint32_t)0x08000000U)

#define MMC_STAT_TRERR_SHIFT                                                                                  ((uint32_t)28U)
#define MMC_STAT_TRERR_MASK                                                                                   ((uint32_t)0x10000000U)
#define MMC_STAT_TRERR_ST_RST_W                                                                               ((uint32_t)1U)
#define MMC_STAT_TRERR_IRQ_FAL_R                                                                              ((uint32_t)0U)
#define MMC_STAT_TRERR_IRQ_TRU_R                                                                              ((uint32_t)1U)
#define MMC_STAT_TRERR_ST_UN_W                                                                                ((uint32_t)0U)

#define MMC_STAT_RESERVED3_SHIFT                                                                             ((uint32_t)29U)
#define MMC_STAT_RESERVED3_MASK                                                                              ((uint32_t)0xe0000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_IE (0x034h)
* @{
*/
#define MMC_IE_CC_ENABLE_SHIFT                                                                               ((uint32_t)0U)
#define MMC_IE_CC_ENABLE_MASK                                                                                ((uint32_t)0x00000001U)
#define MMC_IE_CC_ENABLE_MASKED                                                                              ((uint32_t)0U)
#define MMC_IE_CC_ENABLE_ENABLED                                                                             ((uint32_t)1U)

#define MMC_IE_TC_ENABLE_SHIFT                                                                               ((uint32_t)1U)
#define MMC_IE_TC_ENABLE_MASK                                                                                ((uint32_t)0x00000002U)
#define MMC_IE_TC_ENABLE_ENABLED                                                                             ((uint32_t)1U)
#define MMC_IE_TC_ENABLE_MASKED                                                                              ((uint32_t)0U)

#define MMC_IE_BGE_ENABLE_SHIFT                                                                              ((uint32_t)2U)
#define MMC_IE_BGE_ENABLE_MASK                                                                               ((uint32_t)0x00000004U)
#define MMC_IE_BGE_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_BGE_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_DMA_ENABLE_SHIFT                                                                              ((uint32_t)3U)
#define MMC_IE_DMA_ENABLE_MASK                                                                               ((uint32_t)0x00000008U)
#define MMC_IE_DMA_ENABLE_MASKED                                                                             ((uint32_t)0U)
#define MMC_IE_DMA_ENABLE_ENABLED                                                                            ((uint32_t)1U)

#define MMC_IE_BWR_ENABLE_SHIFT                                                                              ((uint32_t)4U)
#define MMC_IE_BWR_ENABLE_MASK                                                                               ((uint32_t)0x00000010U)
#define MMC_IE_BWR_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_BWR_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_BRR_ENABLE_SHIFT                                                                              ((uint32_t)5U)
#define MMC_IE_BRR_ENABLE_MASK                                                                               ((uint32_t)0x00000020U)
#define MMC_IE_BRR_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_BRR_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_CINS_ENABLE_SHIFT                                                                             ((uint32_t)6U)
#define MMC_IE_CINS_ENABLE_MASK                                                                              ((uint32_t)0x00000040U)
#define MMC_IE_CINS_ENABLE_ENABLED                                                                           ((uint32_t)1U)
#define MMC_IE_CINS_ENABLE_MASKED                                                                            ((uint32_t)0U)

#define MMC_IE_CREM_ENABLE_SHIFT                                                                             ((uint32_t)7U)
#define MMC_IE_CREM_ENABLE_MASK                                                                              ((uint32_t)0x00000080U)
#define MMC_IE_CREM_ENABLE_MASKED                                                                            ((uint32_t)0U)
#define MMC_IE_CREM_ENABLE_ENABLED                                                                           ((uint32_t)1U)

#define MMC_IE_CIRQ_ENABLE_SHIFT                                                                             ((uint32_t)8U)
#define MMC_IE_CIRQ_ENABLE_MASK                                                                              ((uint32_t)0x00000100U)
#define MMC_IE_CIRQ_ENABLE_MASKED                                                                            ((uint32_t)0U)
#define MMC_IE_CIRQ_ENABLE_ENABLED                                                                           ((uint32_t)1U)

#define MMC_IE_INTA_ENABLE_SHIFT                                                                              ((uint32_t)9U)
#define MMC_IE_INTA_ENABLE_MASK                                                                               ((uint32_t)0x00000200U)
#define MMC_IE_INTA_ENABLE_MASKED                                                                             ((uint32_t)0U)
#define MMC_IE_INTA_ENABLE_ENABLED                                                                            ((uint32_t)1U)

#define MMC_IE_INTB_ENABLE_SHIFT                                                                              ((uint32_t)10U)
#define MMC_IE_INTB_ENABLE_MASK                                                                               ((uint32_t)0x00000400U)
#define MMC_IE_INTB_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_INTB_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_INTC_ENABLE_SHIFT                                                                              ((uint32_t)11U)
#define MMC_IE_INTC_ENABLE_MASK                                                                               ((uint32_t)0x00000800U)
#define MMC_IE_INTC_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_INTC_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_RTE_ENABLE_SHIFT                                                                              ((uint32_t)12U)
#define MMC_IE_RTE_ENABLE_MASK                                                                               ((uint32_t)0x00001000U)
#define MMC_IE_RTE_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_RTE_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_BAR_ENABLE_SHIFT                                                                              ((uint32_t)13U)
#define MMC_IE_BAR_ENABLE_MASK                                                                               ((uint32_t)0x00002000U)
#define MMC_IE_BAR_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_BAR_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_BTI_ENABLE_SHIFT                                                                              ((uint32_t)14U)
#define MMC_IE_BTI_ENABLE_MASK                                                                               ((uint32_t)0x00004000U)
#define MMC_IE_BTI_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_BTI_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_NULL_SHIFT                                                                                    ((uint32_t)15U)
#define MMC_IE_NULL_MASK                                                                                     ((uint32_t)0x00008000U)

#define MMC_IE_CTO_ENABLE_SHIFT                                                                              ((uint32_t)16U)
#define MMC_IE_CTO_ENABLE_MASK                                                                               ((uint32_t)0x00010000U)
#define MMC_IE_CTO_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_CTO_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_CCRC_ENABLE_SHIFT                                                                             ((uint32_t)17U)
#define MMC_IE_CCRC_ENABLE_MASK                                                                              ((uint32_t)0x00020000U)
#define MMC_IE_CCRC_ENABLE_MASKED                                                                            ((uint32_t)0U)
#define MMC_IE_CCRC_ENABLE_ENABLED                                                                           ((uint32_t)1U)

#define MMC_IE_CEB_ENABLE_SHIFT                                                                              ((uint32_t)18U)
#define MMC_IE_CEB_ENABLE_MASK                                                                               ((uint32_t)0x00040000U)
#define MMC_IE_CEB_ENABLE_MASKED                                                                             ((uint32_t)0U)
#define MMC_IE_CEB_ENABLE_ENABLED                                                                            ((uint32_t)1U)

#define MMC_IE_CIE_ENABLE_SHIFT                                                                              ((uint32_t)19U)
#define MMC_IE_CIE_ENABLE_MASK                                                                               ((uint32_t)0x00080000U)
#define MMC_IE_CIE_ENABLE_MASKED                                                                             ((uint32_t)0U)
#define MMC_IE_CIE_ENABLE_ENABLED                                                                            ((uint32_t)1U)

#define MMC_IE_DTO_ENABLE_SHIFT                                                                              ((uint32_t)20U)
#define MMC_IE_DTO_ENABLE_MASK                                                                               ((uint32_t)0x00100000U)
#define MMC_IE_DTO_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_DTO_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_DCRC_ENABLE_SHIFT                                                                             ((uint32_t)21U)
#define MMC_IE_DCRC_ENABLE_MASK                                                                              ((uint32_t)0x00200000U)
#define MMC_IE_DCRC_ENABLE_ENABLED                                                                           ((uint32_t)1U)
#define MMC_IE_DCRC_ENABLE_MASKED                                                                            ((uint32_t)0U)

#define MMC_IE_DEB_ENABLE_SHIFT                                                                              ((uint32_t)22U)
#define MMC_IE_DEB_ENABLE_MASK                                                                               ((uint32_t)0x00400000U)
#define MMC_IE_DEB_ENABLE_ENABLED                                                                            ((uint32_t)1U)
#define MMC_IE_DEB_ENABLE_MASKED                                                                             ((uint32_t)0U)

#define MMC_IE_RESERVED1_SHIFT                                                                               ((uint32_t)23U)
#define MMC_IE_RESERVED1_MASK                                                                                ((uint32_t)0x00800000U)

#define MMC_IE_ACE_ENABLE_SHIFT                                                                              ((uint32_t)24U)
#define MMC_IE_ACE_ENABLE_MASK                                                                               ((uint32_t)0x01000000U)
#define MMC_IE_ACE_ENABLE_MASKED                                                                             ((uint32_t)0U)
#define MMC_IE_ACE_ENABLE_ENABLED                                                                            ((uint32_t)1U)

#define MMC_IE_ADMAE_ENABLE_SHIFT                                                                            ((uint32_t)25U)
#define MMC_IE_ADMAE_ENABLE_MASK                                                                             ((uint32_t)0x02000000U)
#define MMC_IE_ADMAE_ENABLE_ENABLED                                                                          ((uint32_t)1U)
#define MMC_IE_ADMAE_ENABLE_MASKED                                                                           ((uint32_t)0U)

#define MMC_IE_TE_ENABLE_SHIFT                                                                               ((uint32_t)26U)
#define MMC_IE_TE_ENABLE_MASK                                                                                ((uint32_t)0x04000000U)
#define MMC_IE_TE_ENABLE_MASKED                                                                              ((uint32_t)0U)
#define MMC_IE_TE_ENABLE_ENABLED                                                                             ((uint32_t)1U)

#define MMC_IE_RESERVED2_SHIFT                                                                               ((uint32_t)27U)
#define MMC_IE_RESERVED2_MASK                                                                                ((uint32_t)0x08000000U)

#define MMC_IE_TRERR_ENABLE_SHIFT                                                                             ((uint32_t)28U)
#define MMC_IE_TRERR_ENABLE_MASK                                                                              ((uint32_t)0x10000000U)
#define MMC_IE_TRERR_ENABLE_ENABLED                                                                           ((uint32_t)1U)
#define MMC_IE_TRERR_ENABLE_MASKED                                                                            ((uint32_t)0U)

#define MMC_IE_RESERVED3_SHIFT                                                                               ((uint32_t)29U)
#define MMC_IE_RESERVED3_MASK                                                                                ((uint32_t)0xe0000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_ISE (0x038h)
* @{
*/
#define MMC_ISE_CC_SIGEN_SHIFT                                                                               ((uint32_t)0U)
#define MMC_ISE_CC_SIGEN_MASK                                                                                ((uint32_t)0x00000001U)
#define MMC_ISE_CC_SIGEN_MASKED                                                                              ((uint32_t)0U)
#define MMC_ISE_CC_SIGEN_ENABLED                                                                             ((uint32_t)1U)

#define MMC_ISE_TC_SIGEN_SHIFT                                                                               ((uint32_t)1U)
#define MMC_ISE_TC_SIGEN_MASK                                                                                ((uint32_t)0x00000002U)
#define MMC_ISE_TC_SIGEN_MASKED                                                                              ((uint32_t)0U)
#define MMC_ISE_TC_SIGEN_ENABLED                                                                             ((uint32_t)1U)

#define MMC_ISE_BGE_SIGEN_SHIFT                                                                              ((uint32_t)2U)
#define MMC_ISE_BGE_SIGEN_MASK                                                                               ((uint32_t)0x00000004U)
#define MMC_ISE_BGE_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_BGE_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_DMA_SIGEN_SHIFT                                                                              ((uint32_t)3U)
#define MMC_ISE_DMA_SIGEN_MASK                                                                               ((uint32_t)0x00000008U)
#define MMC_ISE_DMA_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_DMA_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_BWR_SIGEN_SHIFT                                                                              ((uint32_t)4U)
#define MMC_ISE_BWR_SIGEN_MASK                                                                               ((uint32_t)0x00000010U)
#define MMC_ISE_BWR_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_BWR_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_BRR_SIGEN_SHIFT                                                                              ((uint32_t)5U)
#define MMC_ISE_BRR_SIGEN_MASK                                                                               ((uint32_t)0x00000020U)
#define MMC_ISE_BRR_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_BRR_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_CINS_SIGEN_SHIFT                                                                             ((uint32_t)6U)
#define MMC_ISE_CINS_SIGEN_MASK                                                                              ((uint32_t)0x00000040U)
#define MMC_ISE_CINS_SIGEN_ENABLED                                                                           ((uint32_t)1U)
#define MMC_ISE_CINS_SIGEN_MASKED                                                                            ((uint32_t)0U)

#define MMC_ISE_CREM_SIGEN_SHIFT                                                                             ((uint32_t)7U)
#define MMC_ISE_CREM_SIGEN_MASK                                                                              ((uint32_t)0x00000080U)
#define MMC_ISE_CREM_SIGEN_MASKED                                                                            ((uint32_t)0U)
#define MMC_ISE_CREM_SIGEN_ENABLED                                                                           ((uint32_t)1U)

#define MMC_ISE_CIRQ_SIGEN_SHIFT                                                                             ((uint32_t)8U)
#define MMC_ISE_CIRQ_SIGEN_MASK                                                                              ((uint32_t)0x00000100U)
#define MMC_ISE_CIRQ_SIGEN_ENABLED                                                                           ((uint32_t)1U)
#define MMC_ISE_CIRQ_SIGEN_MASKED                                                                            ((uint32_t)0U)

#define MMC_ISE_INTA_SIGEN_SHIFT                                                                              ((uint32_t)9U)
#define MMC_ISE_INTA_SIGEN_MASK                                                                               ((uint32_t)0x00000200U)
#define MMC_ISE_INTA_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_INTA_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_INTB_SIGEN_SHIFT                                                                              ((uint32_t)10U)
#define MMC_ISE_INTB_SIGEN_MASK                                                                               ((uint32_t)0x00000400U)
#define MMC_ISE_INTB_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_INTB_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_INTC_SIGEN_SHIFT                                                                              ((uint32_t)11U)
#define MMC_ISE_INTC_SIGEN_MASK                                                                               ((uint32_t)0x00000800U)
#define MMC_ISE_INTC_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_INTC_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_RTE_SIGEN_SHIFT                                                                              ((uint32_t)12U)
#define MMC_ISE_RTE_SIGEN_MASK                                                                               ((uint32_t)0x00001000U)
#define MMC_ISE_RTE_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_RTE_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_BAR_SIGEN_SHIFT                                                                              ((uint32_t)13U)
#define MMC_ISE_BAR_SIGEN_MASK                                                                               ((uint32_t)0x00002000U)
#define MMC_ISE_BAR_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_BAR_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_BTI_SIGEN_SHIFT                                                                              ((uint32_t)14U)
#define MMC_ISE_BTI_SIGEN_MASK                                                                               ((uint32_t)0x00004000U)
#define MMC_ISE_BTI_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_BTI_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_NULL_SHIFT                                                                                   ((uint32_t)15U)
#define MMC_ISE_NULL_MASK                                                                                    ((uint32_t)0x00008000U)

#define MMC_ISE_CTO_SIGEN_SHIFT                                                                              ((uint32_t)16U)
#define MMC_ISE_CTO_SIGEN_MASK                                                                               ((uint32_t)0x00010000U)
#define MMC_ISE_CTO_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_CTO_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_CCRC_SIGEN_SHIFT                                                                             ((uint32_t)17U)
#define MMC_ISE_CCRC_SIGEN_MASK                                                                              ((uint32_t)0x00020000U)
#define MMC_ISE_CCRC_SIGEN_MASKED                                                                            ((uint32_t)0U)
#define MMC_ISE_CCRC_SIGEN_ENABLED                                                                           ((uint32_t)1U)

#define MMC_ISE_CEB_SIGEN_SHIFT                                                                              ((uint32_t)18U)
#define MMC_ISE_CEB_SIGEN_MASK                                                                               ((uint32_t)0x00040000U)
#define MMC_ISE_CEB_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_CEB_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_CIE_SIGEN_SHIFT                                                                              ((uint32_t)19U)
#define MMC_ISE_CIE_SIGEN_MASK                                                                               ((uint32_t)0x00080000U)
#define MMC_ISE_CIE_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_CIE_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_DTO_SIGEN_SHIFT                                                                              ((uint32_t)20U)
#define MMC_ISE_DTO_SIGEN_MASK                                                                               ((uint32_t)0x00100000U)
#define MMC_ISE_DTO_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_DTO_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_DCRC_SIGEN_SHIFT                                                                             ((uint32_t)21U)
#define MMC_ISE_DCRC_SIGEN_MASK                                                                              ((uint32_t)0x00200000U)
#define MMC_ISE_DCRC_SIGEN_MASKED                                                                            ((uint32_t)0U)
#define MMC_ISE_DCRC_SIGEN_ENABLED                                                                           ((uint32_t)1U)

#define MMC_ISE_DEB_SIGEN_SHIFT                                                                              ((uint32_t)22U)
#define MMC_ISE_DEB_SIGEN_MASK                                                                               ((uint32_t)0x00400000U)
#define MMC_ISE_DEB_SIGEN_ENABLED                                                                            ((uint32_t)1U)
#define MMC_ISE_DEB_SIGEN_MASKED                                                                             ((uint32_t)0U)

#define MMC_ISE_RESERVED1_SHIFT                                                                              ((uint32_t)23U)
#define MMC_ISE_RESERVED1_MASK                                                                               ((uint32_t)0x00800000U)

#define MMC_ISE_ACE_SIGEN_SHIFT                                                                              ((uint32_t)24U)
#define MMC_ISE_ACE_SIGEN_MASK                                                                               ((uint32_t)0x01000000U)
#define MMC_ISE_ACE_SIGEN_MASKED                                                                             ((uint32_t)0U)
#define MMC_ISE_ACE_SIGEN_ENABLED                                                                            ((uint32_t)1U)

#define MMC_ISE_ADMAE_SIGEN_SHIFT                                                                            ((uint32_t)25U)
#define MMC_ISE_ADMAE_SIGEN_MASK                                                                             ((uint32_t)0x02000000U)
#define MMC_ISE_ADMAE_SIGEN_ENABLED                                                                          ((uint32_t)1U)
#define MMC_ISE_ADMAE_SIGEN_MASKED                                                                           ((uint32_t)0U)

#define MMC_ISE_TE_SIGEN_SHIFT                                                                               ((uint32_t)26U)
#define MMC_ISE_TE_SIGEN_MASK                                                                                ((uint32_t)0x04000000U)
#define MMC_ISE_TE_SIGEN_MASKED                                                                              ((uint32_t)0U)
#define MMC_ISE_TE_SIGEN_ENABLED                                                                             ((uint32_t)1U)

#define MMC_ISE_RESERVED2_SHIFT                                                                              ((uint32_t)27U)
#define MMC_ISE_RESERVED2_MASK                                                                               ((uint32_t)0x08000000U)

#define MMC_ISE_TRERR_SIGEN_SHIFT                                                                             ((uint32_t)28U)
#define MMC_ISE_TRERR_SIGEN_MASK                                                                              ((uint32_t)0x10000000U)
#define MMC_ISE_TRERR_SIGEN_MASKED                                                                            ((uint32_t)0U)
#define MMC_ISE_TRERR_SIGEN_ENABLED                                                                           ((uint32_t)1U)

#define MMC_ISE_RESERVED3_SHIFT                                                                              ((uint32_t)29U)
#define MMC_ISE_RESERVED3_MASK                                                                               ((uint32_t)0xe0000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_AC12 (0x03Ch)
* @{
*/
#define MMC_AC12_ACNE_SHIFT                                                                                  ((uint32_t)0U)
#define MMC_AC12_ACNE_MASK                                                                                   ((uint32_t)0x00000001U)
#define MMC_AC12_ACNE_EXE                                                                                    ((uint32_t)0U)
#define MMC_AC12_ACNE_NOTEXE                                                                                 ((uint32_t)1U)

#define MMC_AC12_ACTO_SHIFT                                                                                  ((uint32_t)1U)
#define MMC_AC12_ACTO_MASK                                                                                   ((uint32_t)0x00000002U)
#define MMC_AC12_ACTO_TIMEOUT                                                                                ((uint32_t)1U)
#define MMC_AC12_ACTO_NOERR                                                                                  ((uint32_t)0U)

#define MMC_AC12_ACCE_SHIFT                                                                                  ((uint32_t)2U)
#define MMC_AC12_ACCE_MASK                                                                                   ((uint32_t)0x00000004U)
#define MMC_AC12_ACCE_NOERR                                                                                  ((uint32_t)0U)
#define MMC_AC12_ACCE_ERR                                                                                    ((uint32_t)1U)

#define MMC_AC12_ACEB_SHIFT                                                                                  ((uint32_t)3U)
#define MMC_AC12_ACEB_MASK                                                                                   ((uint32_t)0x00000008U)
#define MMC_AC12_ACEB_ERR                                                                                    ((uint32_t)1U)
#define MMC_AC12_ACEB_NOERR                                                                                  ((uint32_t)0U)

#define MMC_AC12_ACIE_SHIFT                                                                                  ((uint32_t)4U)
#define MMC_AC12_ACIE_MASK                                                                                   ((uint32_t)0x00000010U)
#define MMC_AC12_ACIE_NOERR                                                                                  ((uint32_t)0U)
#define MMC_AC12_ACIE_ERR                                                                                    ((uint32_t)1U)

#define MMC_AC12_RESERVED1_SHIFT                                                                              ((uint32_t)5U)
#define MMC_AC12_RESERVED1_MASK                                                                               ((uint32_t)0x00000060U)

#define MMC_AC12_CNI_SHIFT                                                                                   ((uint32_t)7U)
#define MMC_AC12_CNI_MASK                                                                                    ((uint32_t)0x00000080U)
#define MMC_AC12_CNI_CMDNI                                                                                   ((uint32_t)1U)
#define MMC_AC12_CNI_NOERR                                                                                   ((uint32_t)0U)

#define MMC_AC12_RESERVED2_SHIFT                                                                             ((uint32_t)8U)
#define MMC_AC12_RESERVED2_MASK                                                                              ((uint32_t)0x0000ff00U)

#define MMC_AC12_UHSMS_SHIFT                                                                                 ((uint32_t)16U)
#define MMC_AC12_UHSMS_MASK                                                                                  ((uint32_t)0x00070000U)
#define MMC_AC12_UHSMS_SDR12                                                                                 ((uint32_t)0U)
#define MMC_AC12_UHSMS_SDR25                                                                                 ((uint32_t)1U)
#define MMC_AC12_UHSMS_SDR50                                                                                 ((uint32_t)2U)
#define MMC_AC12_UHSMS_SDR104                                                                                ((uint32_t)3U)
#define MMC_AC12_UHSMS_DDR50                                                                                 ((uint32_t)4U)
#define MMC_AC12_UHSMS_HS400                                                                                  ((uint32_t)5U)
#define MMC_AC12_UHSMS_RESERVED1                                                                             ((uint32_t)6U)
#define MMC_AC12_UHSMS_RESERVED2                                                                             ((uint32_t)7U)

#define MMC_AC12_V1V8_SIGEN_SHIFT                                                                            ((uint32_t)19U)
#define MMC_AC12_V1V8_SIGEN_MASK                                                                             ((uint32_t)0x00080000U)
#define MMC_AC12_V1V8_SIGEN_1V8                                                                              ((uint32_t)1U)
#define MMC_AC12_V1V8_SIGEN_3V3                                                                              ((uint32_t)0U)

#define MMC_AC12_DS_SEL_SHIFT                                                                                ((uint32_t)20U)
#define MMC_AC12_DS_SEL_MASK                                                                                 ((uint32_t)0x00300000U)
#define MMC_AC12_DS_SEL_DTB                                                                                  ((uint32_t)0U)
#define MMC_AC12_DS_SEL_DTA                                                                                  ((uint32_t)1U)
#define MMC_AC12_DS_SEL_DTC                                                                                  ((uint32_t)2U)
#define MMC_AC12_DS_SEL_DTD                                                                                  ((uint32_t)3U)

#define MMC_AC12_ET_SHIFT                                                                                    ((uint32_t)22U)
#define MMC_AC12_ET_MASK                                                                                     ((uint32_t)0x00400000U)
#define MMC_AC12_ET_EXECUTE                                                                                  ((uint32_t)1U)
#define MMC_AC12_ET_COMPLETED                                                                                ((uint32_t)0U)

#define MMC_AC12_SCLK_SEL_SHIFT                                                                              ((uint32_t)23U)
#define MMC_AC12_SCLK_SEL_MASK                                                                               ((uint32_t)0x00800000U)
#define MMC_AC12_SCLK_SEL_TUNED                                                                              ((uint32_t)1U)
#define MMC_AC12_SCLK_SEL_FIXED                                                                              ((uint32_t)0U)

#define MMC_AC12_RESERVED3_SHIFT                                                                             ((uint32_t)24U)
#define MMC_AC12_RESERVED3_MASK                                                                              ((uint32_t)0x01000000U)

#define MMC_AC12_DRV_STRENGTH_SHIFT                                                                       ((uint32_t)25U)
#define MMC_AC12_DRV_STRENGTH_MASK                                                                        ((uint32_t)0x02000000U)

#define MMC_ADMA2_LENGTH_MODE_SHIFT                                                                          ((uint32_t)26U)
#define MMC_ADMA2_LENGTH_MODE_MASK                                                                           ((uint32_t)0x04000000U)
#define MMC_ADMA2_LENGTH_MODE_16BIT                                                                          ((uint32_t)0U)
#define MMC_ADMA2_LENGTH_MODE_26BIT                                                                          ((uint32_t)1U)

#define MMC_AC12_HOSTVER4_ENABLE_SHIFT                                                                          ((uint32_t)27U)
#define MMC_AC12_HOSTVER4_ENABLE_MASK                                                                           ((uint32_t)0x08000000U)
#define MMC_AC12_HOSTVER4_DISABLE                                                                               ((uint32_t)0U)
#define MMC_AC12_HOSTVER4_ENABLE                                                                                ((uint32_t)1U)


#define MMC_AC12_RESERVED4_SHIFT                                                                             ((uint32_t)27U)
#define MMC_AC12_RESERVED4_MASK                                                                              ((uint32_t)0x38000000U)

#define MMC_AC12_AI_ENABLE_SHIFT                                                                             ((uint32_t)30U)
#define MMC_AC12_AI_ENABLE_MASK                                                                              ((uint32_t)0x40000000U)
#define MMC_AC12_AI_ENABLE_ENABLED                                                                           ((uint32_t)1U)
#define MMC_AC12_AI_ENABLE_DISABLED                                                                          ((uint32_t)0U)

#define MMC_AC12_PV_ENABLE_SHIFT                                                                             ((uint32_t)31U)
#define MMC_AC12_PV_ENABLE_MASK                                                                              ((uint32_t)0x80000000U)
#define MMC_AC12_PV_ENABLE_ENABLED                                                                           ((uint32_t)1U)
#define MMC_AC12_PV_ENABLE_DISABLED                                                                          ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CAPA (0x040h)
* @{
*/
#define MMC_CAPA_TCF_SHIFT                                                                                   ((uint32_t)0U)
#define MMC_CAPA_TCF_MASK                                                                                    ((uint32_t)0x0000003fU)
#define MMC_CAPA_TCF_OMETH                                                                                   ((uint32_t)0U)

#define MMC_CAPA_RESERVED1_SHIFT                                                                              ((uint32_t)6U)
#define MMC_CAPA_RESERVED1_MASK                                                                               ((uint32_t)0x00000040U)

#define MMC_CAPA_TCU_SHIFT                                                                                   ((uint32_t)7U)
#define MMC_CAPA_TCU_MASK                                                                                    ((uint32_t)0x00000080U)
#define MMC_CAPA_TCU_MHZ                                                                                     ((uint32_t)0U)
#define MMC_CAPA_TCU_KHZ                                                                                     ((uint32_t)1U)

#define MMC_CAPA_BCF_SHIFT                                                                                   ((uint32_t)8U)
#define MMC_CAPA_BCF_MASK                                                                                    ((uint32_t)0x0000ff00U)
#define MMC_CAPA_BCF_OMETH                                                                                   ((uint32_t)0U)

#define MMC_CAPA_MBL_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_CAPA_MBL_MASK                                                                                    ((uint32_t)0x00030000U)
#define MMC_CAPA_MBL_512                                                                                     ((uint32_t)0U)
#define MMC_CAPA_MBL_1024                                                                                    ((uint32_t)1U)
#define MMC_CAPA_MBL_2048                                                                                    ((uint32_t)2U)

#define MMC_CAPA_EMBS_SHIFT                                                                             ((uint32_t)18U)
#define MMC_CAPA_EMBS_MASK                                                                              ((uint32_t)0x00040000U)
#define MMC_CAPA_EMBS_SUPPORTED                                                                    ((uint32_t)1U)
#define MMC_CAPA_EMBS_NOTSUPPORTED                                                              ((uint32_t)0U)

#define MMC_CAPA_AD2S_SHIFT                                                                                  ((uint32_t)19U)
#define MMC_CAPA_AD2S_MASK                                                                                   ((uint32_t)0x00080000U)
#define MMC_CAPA_AD2S_ADMA2NOTSUPPORTED                                                                      ((uint32_t)0U)
#define MMC_CAPA_AD2S_ADMA2SUPPORTED                                                                         ((uint32_t)1U)

#define MMC_CAPA_RESERVED2_SHIFT                                                                             ((uint32_t)20U)
#define MMC_CAPA_RESERVED2_MASK                                                                              ((uint32_t)0x00100000U)

#define MMC_CAPA_HSS_SHIFT                                                                                   ((uint32_t)21U)
#define MMC_CAPA_HSS_MASK                                                                                    ((uint32_t)0x00200000U)
#define MMC_CAPA_HSS_NOTSUPPORTED                                                                            ((uint32_t)0U)
#define MMC_CAPA_HSS_SUPPORTED                                                                               ((uint32_t)1U)

#define MMC_CAPA_SDMAS_SHIFT                                                                                    ((uint32_t)22U)
#define MMC_CAPA_SDMAS_MASK                                                                                     ((uint32_t)0x00400000U)
#define MMC_CAPA_SDMAS_NOTSUPPORTED                                                                             ((uint32_t)0U)
#define MMC_CAPA_SDMAS_SUPPORTED                                                                                ((uint32_t)1U)

#define MMC_CAPA_SRS_SHIFT                                                                                   ((uint32_t)23U)
#define MMC_CAPA_SRS_MASK                                                                                    ((uint32_t)0x00800000U)
#define MMC_CAPA_SRS_NOTSUPPORTED                                                                            ((uint32_t)0U)
#define MMC_CAPA_SRS_SUPPORTED                                                                               ((uint32_t)1U)

#define MMC_CAPA_VS33_SHIFT                                                                                  ((uint32_t)24U)
#define MMC_CAPA_VS33_MASK                                                                                   ((uint32_t)0x01000000U)
#define MMC_CAPA_VS33_ST_3V3SUP_W                                                                            ((uint32_t)1U)
#define MMC_CAPA_VS33_ST_3V3NOTSUP_W                                                                         ((uint32_t)0U)
#define MMC_CAPA_VS33_3V3_SUP_R                                                                              ((uint32_t)1U)
#define MMC_CAPA_VS33_3V3_NOTSUP_R                                                                           ((uint32_t)0U)

#define MMC_CAPA_VS30_SHIFT                                                                                  ((uint32_t)25U)
#define MMC_CAPA_VS30_MASK                                                                                   ((uint32_t)0x02000000U)
#define MMC_CAPA_VS30_ST_3V0NOTSUP_W                                                                         ((uint32_t)0U)
#define MMC_CAPA_VS30_3V0_NOTSUP_R                                                                           ((uint32_t)0U)
#define MMC_CAPA_VS30_3V0_SUP_R                                                                              ((uint32_t)1U)
#define MMC_CAPA_VS30_ST_3V0SUP_W                                                                            ((uint32_t)1U)

#define MMC_CAPA_VS18_SHIFT                                                                                  ((uint32_t)26U)
#define MMC_CAPA_VS18_MASK                                                                                   ((uint32_t)0x04000000U)
#define MMC_CAPA_VS18_ST_1V8SUP_W                                                                            ((uint32_t)1U)
#define MMC_CAPA_VS18_1V8_SUP_R                                                                              ((uint32_t)1U)
#define MMC_CAPA_VS18_1V8_NOTSUP_R                                                                           ((uint32_t)0U)
#define MMC_CAPA_VS18_ST_1V8NOTSUP_W                                                                         ((uint32_t)0U)

#define MMC_CAPA_RESERVED3_SHIFT                                                                             ((uint32_t)27U)
#define MMC_CAPA_RESERVED3_MASK                                                                              ((uint32_t)0x08000000U)

#define MMC_CAPA_BIT64_SHIFT                                                                                 ((uint32_t)28U)
#define MMC_CAPA_BIT64_MASK                                                                                  ((uint32_t)0x10000000U)
#define MMC_CAPA_BIT64_SYSADDR32B                                                                            ((uint32_t)0U)
#define MMC_CAPA_BIT64_SYSADDR64B                                                                            ((uint32_t)1U)

#define MMC_CAPA_AIS_SHIFT                                                                                   ((uint32_t)29U)
#define MMC_CAPA_AIS_MASK                                                                                    ((uint32_t)0x20000000U)
#define MMC_CAPA_AIS_AIS_SUP                                                                                 ((uint32_t)1U)
#define MMC_CAPA_AIS_AIS_NOTSUP                                                                              ((uint32_t)0U)

#define MMC_CAPA_SLOT_TYPE_SHIFT                                                                             ((uint32_t)30U)
#define MMC_CAPA_SLOT_TYPE_MASK                                                                              ((uint32_t)0xc0000000U)
#define MMC_CAPA_REMOVABLE_SLOT                                                                            ((uint32_t)0U)
#define MMC_CAPA_EMBEDDED_SLOT                                                                             ((uint32_t)1U)
#define MMC_CAPA_SHARED_SLOT                                                                                  ((uint32_t)2U)
/* @} */

/*
* \brief Macros for SDHC MMC_CAPA2 (0x044h)
* @{
*/
#define MMC_CAPA2_SDR50_SHIFT                                                                                ((uint32_t)0U)
#define MMC_CAPA2_SDR50_MASK                                                                                 ((uint32_t)0x00000001U)
#define MMC_CAPA2_SDR50_SUPPORTED                                                                            ((uint32_t)1U)
#define MMC_CAPA2_SDR50_NOTSUPPORTED                                                                         ((uint32_t)0U)

#define MMC_CAPA2_SDR104_SHIFT                                                                               ((uint32_t)1U)
#define MMC_CAPA2_SDR104_MASK                                                                                ((uint32_t)0x00000002U)
#define MMC_CAPA2_SDR104_SUPPORTED                                                                           ((uint32_t)1U)
#define MMC_CAPA2_SDR104_NOTSUPPORTED                                                                        ((uint32_t)0U)

#define MMC_CAPA2_DDR50_SHIFT                                                                                ((uint32_t)2U)
#define MMC_CAPA2_DDR50_MASK                                                                                 ((uint32_t)0x00000004U)
#define MMC_CAPA2_DDR50_SUPPORTED                                                                            ((uint32_t)1U)
#define MMC_CAPA2_DDR50_NOTSUPPORTED                                                                         ((uint32_t)0U)

#define MMC_CAPA2_RESERVED1_SHIFT                                                                             ((uint32_t)3U)
#define MMC_CAPA2_RESERVED1_MASK                                                                              ((uint32_t)0x00000008U)

#define MMC_CAPA2_DTA_SHIFT                                                                                  ((uint32_t)4U)
#define MMC_CAPA2_DTA_MASK                                                                                   ((uint32_t)0x00000010U)
#define MMC_CAPA2_DTA_SUPPORTED                                                                              ((uint32_t)1U)
#define MMC_CAPA2_DTA_NOTSUPPORTED                                                                           ((uint32_t)0U)

#define MMC_CAPA2_DTC_SHIFT                                                                                  ((uint32_t)5U)
#define MMC_CAPA2_DTC_MASK                                                                                   ((uint32_t)0x00000020U)
#define MMC_CAPA2_DTC_SUPPORTED                                                                              ((uint32_t)1U)
#define MMC_CAPA2_DTC_NOTSUPPORTED                                                                           ((uint32_t)0U)

#define MMC_CAPA2_DTD_SHIFT                                                                                  ((uint32_t)6U)
#define MMC_CAPA2_DTD_MASK                                                                                   ((uint32_t)0x00000040U)
#define MMC_CAPA2_DTD_SUPPORTED                                                                              ((uint32_t)1U)
#define MMC_CAPA2_DTD_NOTSUPPORTED                                                                           ((uint32_t)0U)

#define MMC_CAPA2_DT4_SHIFT                                                                                  ((uint32_t)7U)
#define MMC_CAPA2_DT4_MASK                                                                                   ((uint32_t)0x00000080U)
#define MMC_CAPA2_DT4_SUPPORTED                                                                              ((uint32_t)1U)
#define MMC_CAPA2_DT4_NOTSUPPORTED                                                                           ((uint32_t)0U)

#define MMC_CAPA2_TCRT_SHIFT                                                                                 ((uint32_t)8U)
#define MMC_CAPA2_TCRT_MASK                                                                                  ((uint32_t)0x00000f00U)
#define MMC_CAPA2_TCRT_DISABLED                                                                              ((uint32_t)0U)
#define MMC_CAPA2_TCRT_1                                                                                     ((uint32_t)1U)
#define MMC_CAPA2_TCRT_2                                                                                     ((uint32_t)2U)
#define MMC_CAPA2_TCRT_3                                                                                     ((uint32_t)3U)
#define MMC_CAPA2_TCRT_4                                                                                     ((uint32_t)4U)
#define MMC_CAPA2_TCRT_5                                                                                     ((uint32_t)5U)
#define MMC_CAPA2_TCRT_6                                                                                     ((uint32_t)6U)
#define MMC_CAPA2_TCRT_7                                                                                     ((uint32_t)7U)
#define MMC_CAPA2_TCRT_8                                                                                     ((uint32_t)8U)
#define MMC_CAPA2_TCRT_9                                                                                     ((uint32_t)9U)
#define MMC_CAPA2_TCRT_10                                                                                    ((uint32_t)10U)
#define MMC_CAPA2_TCRT_11                                                                                    ((uint32_t)11U)
#define MMC_CAPA2_TCRT_RESERVED1                                                                             ((uint32_t)12U)
#define MMC_CAPA2_TCRT_RESERVED2                                                                             ((uint32_t)13U)
#define MMC_CAPA2_TCRT_RESERVED3                                                                             ((uint32_t)14U)
#define MMC_CAPA2_TCRT_OTHERSOURCE                                                                           ((uint32_t)15U)

#define MMC_CAPA2_RESERVED2_SHIFT                                                                            ((uint32_t)12U)
#define MMC_CAPA2_RESERVED2_MASK                                                                             ((uint32_t)0x00001000U)

#define MMC_CAPA2_TSDR50_SHIFT                                                                               ((uint32_t)13U)
#define MMC_CAPA2_TSDR50_MASK                                                                                ((uint32_t)0x00002000U)
#define MMC_CAPA2_TSDR50_REQUIRED                                                                            ((uint32_t)1U)
#define MMC_CAPA2_TSDR50_NOTREQUIRED                                                                         ((uint32_t)0U)

#define MMC_CAPA2_RTM_SHIFT                                                                                  ((uint32_t)14U)
#define MMC_CAPA2_RTM_MASK                                                                                   ((uint32_t)0x0000c000U)
#define MMC_CAPA2_RTM_MODE1                                                                                  ((uint32_t)0U)
#define MMC_CAPA2_RTM_MODE2                                                                                  ((uint32_t)1U)
#define MMC_CAPA2_RTM_MODE3                                                                                  ((uint32_t)2U)
#define MMC_CAPA2_RTM_RESERVED                                                                               ((uint32_t)3U)

#define MMC_CAPA2_CM_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_CAPA2_CM_MASK                                                                                    ((uint32_t)0x00ff0000U)

#define MMC_CAPA2_SPI_MODE_SHIFT                                                                            ((uint32_t)24U)
#define MMC_CAPA2_SPI_MODE_MASK                                                                             ((uint32_t)0x01000000U)
#define MMC_CAPA2_SPI_MODE_SUPPORTED                                                                   ((uint32_t)1U)
#define MMC_CAPA2_SPI_MODE_NOTSUPPORTED                                                             ((uint32_t)0U)

#define MMC_CAPA2_SPI_BMODE_SHIFT                                                                            ((uint32_t)25U)
#define MMC_CAPA2_SPI_BMODE_MASK                                                                             ((uint32_t)0x02000000U)
#define MMC_CAPA2_SPI_BMODE_SUPPORTED                                                                   ((uint32_t)1U)
#define MMC_CAPA2_SPI_BMODE_NOTSUPPORTED                                                             ((uint32_t)0U)

#define MMC_CAPA2_RESERVED3_SHIFT                                                                             ((uint32_t)26U)
#define MMC_CAPA2_RESERVED3_MASK                                                                              ((uint32_t)0x7c000000U)

#define MMC_CAPA2_HS400S_SHIFT                                                                                    ((uint32_t)31U)
#define MMC_CAPA2_HS400S_MASK                                                                                     ((uint32_t)0x80000000U)
#define MMC_CAPA2_HS400S_SUPPORTED                                                                           ((uint32_t)1U)
#define MMC_CAPA2_HS400S_NOTSUPPORTED                                                                     ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CUR_CAPA (0x048h)
* @{
*/
#define MMC_CUR_CAPA_CUR_3V3_SHIFT                                                                           ((uint32_t)0U)
#define MMC_CUR_CAPA_CUR_3V3_MASK                                                                            ((uint32_t)0x000000ffU)
#define MMC_CUR_CAPA_CUR_3V3_OMETH                                                                           ((uint32_t)0U)

#define MMC_CUR_CAPA_CUR_1V8_SHIFT                                                                           ((uint32_t)16U)
#define MMC_CUR_CAPA_CUR_1V8_MASK                                                                            ((uint32_t)0x00ff0000U)
#define MMC_CUR_CAPA_CUR_1V8_OMETH                                                                           ((uint32_t)0U)

#define MMC_CUR_CAPA_CUR_3V0_SHIFT                                                                           ((uint32_t)8U)
#define MMC_CUR_CAPA_CUR_3V0_MASK                                                                            ((uint32_t)0x0000ff00U)
#define MMC_CUR_CAPA_CUR_3V0_OMETH                                                                           ((uint32_t)0U)

#define MMC_CUR_CAPA_RESERVED_SHIFT                                                                          ((uint32_t)24U)
#define MMC_CUR_CAPA_RESERVED_MASK                                                                           ((uint32_t)0xff000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_FE (0x050h)
* @{
*/
#define MMC_FE_FE_CEB_SHIFT                                                                                  ((uint32_t)18U)
#define MMC_FE_FE_CEB_MASK                                                                                   ((uint32_t)0x00040000U)
#define MMC_FE_FE_CEB_NOACTION                                                                               ((uint32_t)0U)
#define MMC_FE_FE_CEB_INTFORCED                                                                              ((uint32_t)1U)

#define MMC_FE_FE_CTO_SHIFT                                                                                  ((uint32_t)16U)
#define MMC_FE_FE_CTO_MASK                                                                                   ((uint32_t)0x00010000U)
#define MMC_FE_FE_CTO_ST_UN_W                                                                                ((uint32_t)0U)
#define MMC_FE_FE_CTO_ST_RST_W                                                                               ((uint32_t)1U)

#define MMC_FE_FE_DCRC_SHIFT                                                                                 ((uint32_t)21U)
#define MMC_FE_FE_DCRC_MASK                                                                                  ((uint32_t)0x00200000U)
#define MMC_FE_FE_DCRC_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_DCRC_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_FE_BADA_SHIFT                                                                                 ((uint32_t)29U)
#define MMC_FE_FE_BADA_MASK                                                                                  ((uint32_t)0x20000000U)
#define MMC_FE_FE_BADA_NOACTION                                                                              ((uint32_t)0U)
#define MMC_FE_FE_BADA_INTFORCED                                                                             ((uint32_t)1U)

#define MMC_FE_FE_CCRC_SHIFT                                                                                 ((uint32_t)17U)
#define MMC_FE_FE_CCRC_MASK                                                                                  ((uint32_t)0x00020000U)
#define MMC_FE_FE_CCRC_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_CCRC_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_FE_ACE_SHIFT                                                                                  ((uint32_t)24U)
#define MMC_FE_FE_ACE_MASK                                                                                   ((uint32_t)0x01000000U)
#define MMC_FE_FE_ACE_INTFORCED                                                                              ((uint32_t)1U)
#define MMC_FE_FE_ACE_NOACTION                                                                               ((uint32_t)0U)

#define MMC_FE_FE_DEB_SHIFT                                                                                  ((uint32_t)22U)
#define MMC_FE_FE_DEB_MASK                                                                                   ((uint32_t)0x00400000U)
#define MMC_FE_FE_DEB_NOACTION                                                                               ((uint32_t)0U)
#define MMC_FE_FE_DEB_INTFORCED                                                                              ((uint32_t)1U)

#define MMC_FE_FE_CIE_SHIFT                                                                                  ((uint32_t)19U)
#define MMC_FE_FE_CIE_MASK                                                                                   ((uint32_t)0x00080000U)
#define MMC_FE_FE_CIE_INTFORCED                                                                              ((uint32_t)1U)
#define MMC_FE_FE_CIE_NOACTION                                                                               ((uint32_t)0U)

#define MMC_FE_FE_DTO_SHIFT                                                                                  ((uint32_t)20U)
#define MMC_FE_FE_DTO_MASK                                                                                   ((uint32_t)0x00100000U)
#define MMC_FE_FE_DTO_NOACTION                                                                               ((uint32_t)0U)
#define MMC_FE_FE_DTO_INTFORCED                                                                              ((uint32_t)1U)

#define MMC_FE_FE_CERR_SHIFT                                                                                 ((uint32_t)28U)
#define MMC_FE_FE_CERR_MASK                                                                                  ((uint32_t)0x10000000U)
#define MMC_FE_FE_CERR_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_CERR_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_RESERVED4_SHIFT                                                                               ((uint32_t)23U)
#define MMC_FE_RESERVED4_MASK                                                                                ((uint32_t)0x00800000U)

#define MMC_FE_FE_ADMAE_SHIFT                                                                                ((uint32_t)25U)
#define MMC_FE_FE_ADMAE_MASK                                                                                 ((uint32_t)0x02000000U)
#define MMC_FE_FE_ADMAE_NOACTION                                                                             ((uint32_t)0U)
#define MMC_FE_FE_ADMAE_INTFORCED                                                                            ((uint32_t)1U)

#define MMC_FE_FE_ACNE_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_FE_FE_ACNE_MASK                                                                                  ((uint32_t)0x00000001U)
#define MMC_FE_FE_ACNE_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_ACNE_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_FE_ACCE_SHIFT                                                                                 ((uint32_t)2U)
#define MMC_FE_FE_ACCE_MASK                                                                                  ((uint32_t)0x00000004U)
#define MMC_FE_FE_ACCE_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_ACCE_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_FE_ACIE_SHIFT                                                                                 ((uint32_t)4U)
#define MMC_FE_FE_ACIE_MASK                                                                                  ((uint32_t)0x00000010U)
#define MMC_FE_FE_ACIE_INTFORCED                                                                             ((uint32_t)1U)
#define MMC_FE_FE_ACIE_NOACTION                                                                              ((uint32_t)0U)

#define MMC_FE_FE_ACEB_SHIFT                                                                                 ((uint32_t)3U)
#define MMC_FE_FE_ACEB_MASK                                                                                  ((uint32_t)0x00000008U)
#define MMC_FE_FE_ACEB_NOACTION                                                                              ((uint32_t)0U)
#define MMC_FE_FE_ACEB_INTFORCED                                                                             ((uint32_t)1U)

#define MMC_FE_FE_ACTO_SHIFT                                                                                 ((uint32_t)1U)
#define MMC_FE_FE_ACTO_MASK                                                                                  ((uint32_t)0x00000002U)
#define MMC_FE_FE_ACTO_NOACTION                                                                              ((uint32_t)0U)
#define MMC_FE_FE_ACTO_INTFORCED                                                                             ((uint32_t)1U)

#define MMC_FE_FE_CNI_SHIFT                                                                                  ((uint32_t)7U)
#define MMC_FE_FE_CNI_MASK                                                                                   ((uint32_t)0x00000080U)
#define MMC_FE_FE_CNI_NOACTION                                                                               ((uint32_t)0U)
#define MMC_FE_FE_CNI_INTFORCED                                                                              ((uint32_t)1U)

#define MMC_FE_RESERVED_SHIFT                                                                                ((uint32_t)5U)
#define MMC_FE_RESERVED_MASK                                                                                 ((uint32_t)0x00000060U)

#define MMC_FE_RESERVED1_SHIFT                                                                               ((uint32_t)8U)
#define MMC_FE_RESERVED1_MASK                                                                                ((uint32_t)0x0000ff00U)

#define MMC_FE_RESERVED2_SHIFT                                                                               ((uint32_t)26U)
#define MMC_FE_RESERVED2_MASK                                                                                ((uint32_t)0x0c000000U)

#define MMC_FE_RESERVED3_SHIFT                                                                               ((uint32_t)30U)
#define MMC_FE_RESERVED3_MASK                                                                                ((uint32_t)0xc0000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_ADMAES (0x054h)
* @{
*/
#define MMC_ADMAES_LME_SHIFT                                                                                 ((uint32_t)2U)
#define MMC_ADMAES_LME_MASK                                                                                  ((uint32_t)0x00000004U)
#define MMC_ADMAES_LME_NOERROR                                                                               ((uint32_t)0U)
#define MMC_ADMAES_LME_ERROR                                                                                 ((uint32_t)1U)

#define MMC_ADMAES_AES_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_ADMAES_AES_MASK                                                                                  ((uint32_t)0x00000003U)
#define MMC_ADMAES_AES_SYSSDR                                                                                ((uint32_t)0U)
#define MMC_ADMAES_AES_LINKDESC                                                                              ((uint32_t)1U)
#define MMC_ADMAES_AES_RESERVED                                                                              ((uint32_t)2U)
#define MMC_ADMAES_AES_TRANSDATA                                                                             ((uint32_t)3U)

#define MMC_ADMAES_RESERVED_SHIFT                                                                            ((uint32_t)3U)
#define MMC_ADMAES_RESERVED_MASK                                                                             ((uint32_t)0xfffffff8U)
/* @} */

/*
* \brief Macros for SDHC MMC_ADMASAL (0x058h)
* @{
*/
#define MMC_ADMASAL_ADMA_A32B_SHIFT                                                                          ((uint32_t)0U)
#define MMC_ADMASAL_ADMA_A32B_MASK                                                                           ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_ADMASAL2 (0x05Ch)
* @{
*/
#define MMC_ADMASAL2_ADMA_A64B_SHIFT                                                                          ((uint32_t)0U)
#define MMC_ADMASAL2_ADMA_A64B_MASK                                                                           ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_PVINITSD (0x060h)
* @{
*/
#define MMC_PVINITSD_INITSDCLK_SHIFT                                                                     ((uint32_t)0U)
#define MMC_PVINITSD_INITSDCLK_MASK                                                                      ((uint32_t)0x000003ffU)

#define MMC_PVINITSD_INITCGEN_SHIFT                                                                    ((uint32_t)10U)
#define MMC_PVINITSD_INITCGEN_MASK                                                                     ((uint32_t)0x00000400U)
#define MMC_PVINITSD_INITCGEN_PROG                                                                     ((uint32_t)1U)
#define MMC_PVINITSD_INITCGEN_HOST                                                                     ((uint32_t)0U)

#define MMC_PVINITSD_INITDS_SHIFT                                                                        ((uint32_t)14U)
#define MMC_PVINITSD_INITDS_MASK                                                                         ((uint32_t)0x0000c000U)
#define MMC_PVINITSD_INITDS_DTD                                                                          ((uint32_t)3U)
#define MMC_PVINITSD_INITDS_DTC                                                                          ((uint32_t)2U)
#define MMC_PVINITSD_INITDS_DTA                                                                          ((uint32_t)1U)
#define MMC_PVINITSD_INITDS_DTB                                                                          ((uint32_t)0U)

#define MMC_PVINITSD_DSSDCLK_SHIFT                                                                       ((uint32_t)16U)
#define MMC_PVINITSD_DSSDCLK_MASK                                                                        ((uint32_t)0x03ff0000U)

#define MMC_PVINITSD_DSCGEN_SHIFT                                                                      ((uint32_t)26U)
#define MMC_PVINITSD_DSCGEN_MASK                                                                       ((uint32_t)0x04000000U)
#define MMC_PVINITSD_DSCGEN_PROG                                                                       ((uint32_t)1U)
#define MMC_PVINITSD_DSCGEN_HOST                                                                       ((uint32_t)0U)

#define MMC_PVINITSD_DSDS_SHIFT                                                                          ((uint32_t)30U)
#define MMC_PVINITSD_DSDS_MASK                                                                           ((uint32_t)0xc0000000U)
#define MMC_PVINITSD_DSDS_DTD                                                                            ((uint32_t)3U)
#define MMC_PVINITSD_DSDS_DTC                                                                            ((uint32_t)2U)
#define MMC_PVINITSD_DSDS_DTA                                                                            ((uint32_t)1U)
#define MMC_PVINITSD_DSDS_DTB                                                                            ((uint32_t)0U)

#define MMC_PVINITSD_RESERVED_SHIFT                                                                          ((uint32_t)11U)
#define MMC_PVINITSD_RESERVED_MASK                                                                           ((uint32_t)0x00003800U)

#define MMC_PVINITSD_RESERVED1_SHIFT                                                                         ((uint32_t)27U)
#define MMC_PVINITSD_RESERVED1_MASK                                                                          ((uint32_t)0x38000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_PVHSSDR12 (0x064h)
* @{
*/
#define MMC_PVHSSDR12_HSSDCLK_SHIFT                                                                      ((uint32_t)0U)
#define MMC_PVHSSDR12_HSSDCLK_MASK                                                                       ((uint32_t)0x000003ffU)

#define MMC_PVHSSDR12_HSCGEN_SHIFT                                                                     ((uint32_t)10U)
#define MMC_PVHSSDR12_HSCGEN_MASK                                                                      ((uint32_t)0x00000400U)
#define MMC_PVHSSDR12_HSCGEN_PROG                                                                      ((uint32_t)1U)
#define MMC_PVHSSDR12_HSCGEN_HOST                                                                      ((uint32_t)0U)

#define MMC_PVHSSDR12_HSDS_SHIFT                                                                         ((uint32_t)14U)
#define MMC_PVHSSDR12_HSDS_MASK                                                                          ((uint32_t)0x0000c000U)
#define MMC_PVHSSDR12_HSDS_DTB                                                                           ((uint32_t)0U)
#define MMC_PVHSSDR12_HSDS_DTA                                                                           ((uint32_t)1U)
#define MMC_PVHSSDR12_HSDS_DTC                                                                           ((uint32_t)2U)
#define MMC_PVHSSDR12_HSDS_DTD                                                                           ((uint32_t)3U)

#define MMC_PVHSSDR12_SDR12SDCLK_SHIFT                                                                   ((uint32_t)16U)
#define MMC_PVHSSDR12_SDR12SDCLK_MASK                                                                    ((uint32_t)0x03ff0000U)

#define MMC_PVHSSDR12_SDR12CGEN_SHIFT                                                                  ((uint32_t)26U)
#define MMC_PVHSSDR12_SDR12CGEN_MASK                                                                   ((uint32_t)0x04000000U)
#define MMC_PVHSSDR12_SDR12CGEN_PROG                                                                   ((uint32_t)1U)
#define MMC_PVHSSDR12_SDR12CGEN_HOST                                                                   ((uint32_t)0U)

#define MMC_PVHSSDR12_SDR12DS_SHIFT                                                                      ((uint32_t)30U)
#define MMC_PVHSSDR12_SDR12DS_MASK                                                                       ((uint32_t)0xc0000000U)
#define MMC_PVHSSDR12_SDR12DS_DTD                                                                        ((uint32_t)3U)
#define MMC_PVHSSDR12_SDR12DS_DTC                                                                        ((uint32_t)2U)
#define MMC_PVHSSDR12_SDR12DS_DTA                                                                        ((uint32_t)1U)
#define MMC_PVHSSDR12_SDR12DS_DTB                                                                        ((uint32_t)0U)

#define MMC_PVHSSDR12_RESERVED_SHIFT                                                                         ((uint32_t)11U)
#define MMC_PVHSSDR12_RESERVED_MASK                                                                          ((uint32_t)0x00003800U)

#define MMC_PVHSSDR12_RESERVED1_SHIFT                                                                        ((uint32_t)27U)
#define MMC_PVHSSDR12_RESERVED1_MASK                                                                         ((uint32_t)0x38000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_PVSDR25SDR50 (0x068h)
* @{
*/
#define MMC_PVSDR25SDR50_SDR25SDCLK_SHIFT                                                                ((uint32_t)0U)
#define MMC_PVSDR25SDR50_SDR25SDCLK_MASK                                                                 ((uint32_t)0x000003ffU)

#define MMC_PVSDR25SDR50_SDR25CGEN_SHIFT                                                               ((uint32_t)10U)
#define MMC_PVSDR25SDR50_SDR25CGEN_MASK                                                                ((uint32_t)0x00000400U)
#define MMC_PVSDR25SDR50_SDR25CGEN_PROG                                                                ((uint32_t)1U)
#define MMC_PVSDR25SDR50_SDR25CGEN_HOST                                                                ((uint32_t)0U)

#define MMC_PVSDR25SDR50_SDR25DS_SHIFT                                                                   ((uint32_t)14U)
#define MMC_PVSDR25SDR50_SDR25DS_MASK                                                                    ((uint32_t)0x0000c000U)
#define MMC_PVSDR25SDR50_SDR25DS_DTD                                                                     ((uint32_t)3U)
#define MMC_PVSDR25SDR50_SDR25DS_DTC                                                                     ((uint32_t)2U)
#define MMC_PVSDR25SDR50_SDR25DS_DTA                                                                     ((uint32_t)1U)
#define MMC_PVSDR25SDR50_SDR25DS_DTB                                                                     ((uint32_t)0U)

#define MMC_PVSDR25SDR50_SDR50SDCLK_SHIFT                                                                ((uint32_t)16U)
#define MMC_PVSDR25SDR50_SDR50SDCLK_MASK                                                                 ((uint32_t)0x03ff0000U)

#define MMC_PVSDR25SDR50_SDR50CGEN_SHIFT                                                               ((uint32_t)26U)
#define MMC_PVSDR25SDR50_SDR50CGEN_MASK                                                                ((uint32_t)0x04000000U)
#define MMC_PVSDR25SDR50_SDR50CGEN_PROG                                                                ((uint32_t)1U)
#define MMC_PVSDR25SDR50_SDR50CGEN_HOST                                                                ((uint32_t)0U)

#define MMC_PVSDR25SDR50_SDR50DS_SHIFT                                                                   ((uint32_t)30U)
#define MMC_PVSDR25SDR50_SDR50DS_MASK                                                                    ((uint32_t)0xc0000000U)
#define MMC_PVSDR25SDR50_SDR50DS_DTD                                                                     ((uint32_t)3U)
#define MMC_PVSDR25SDR50_SDR50DS_DTC                                                                     ((uint32_t)2U)
#define MMC_PVSDR25SDR50_SDR50DS_DTA                                                                     ((uint32_t)1U)
#define MMC_PVSDR25SDR50_SDR50DS_DTB                                                                     ((uint32_t)0U)

#define MMC_PVSDR25SDR50_RESERVED_SHIFT                                                                      ((uint32_t)11U)
#define MMC_PVSDR25SDR50_RESERVED_MASK                                                                       ((uint32_t)0x00003800U)

#define MMC_PVSDR25SDR50_RESERVED1_SHIFT                                                                     ((uint32_t)27U)
#define MMC_PVSDR25SDR50_RESERVED1_MASK                                                                      ((uint32_t)0x38000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_PVSDR104DDR50 (0x06Ch)
* @{
*/
#define MMC_PVSDR104DDR50_SDR104SDCLK_SHIFT                                                              ((uint32_t)0U)
#define MMC_PVSDR104DDR50_SDR104SDCLK_MASK                                                               ((uint32_t)0x000003ffU)

#define MMC_PVSDR104DDR50_SDR104CGEN_SHIFT                                                             ((uint32_t)10U)
#define MMC_PVSDR104DDR50_SDR104CGEN_MASK                                                              ((uint32_t)0x00000400U)
#define MMC_PVSDR104DDR50_SDR104CGEN_PROG                                                              ((uint32_t)1U)
#define MMC_PVSDR104DDR50_SDR104CGEN_HOST                                                              ((uint32_t)0U)

#define MMC_PVSDR104DDR50_SDR104DS_SHIFT                                                                 ((uint32_t)14U)
#define MMC_PVSDR104DDR50_SDR104DS_MASK                                                                  ((uint32_t)0x0000c000U)
#define MMC_PVSDR104DDR50_SDR104DS_DTD                                                                   ((uint32_t)3U)
#define MMC_PVSDR104DDR50_SDR104DS_DTC                                                                   ((uint32_t)2U)
#define MMC_PVSDR104DDR50_SDR104DS_DTA                                                                   ((uint32_t)1U)
#define MMC_PVSDR104DDR50_SDR104DS_DTB                                                                   ((uint32_t)0U)

#define MMC_PVSDR104DDR50_DDR50SDCLK_SHIFT                                                               ((uint32_t)16U)
#define MMC_PVSDR104DDR50_DDR50SDCLK_MASK                                                                ((uint32_t)0x03ff0000U)

#define MMC_PVSDR104DDR50_DDR50CGEN_SHIFT                                                              ((uint32_t)26U)
#define MMC_PVSDR104DDR50_DDR50CGEN_MASK                                                               ((uint32_t)0x04000000U)
#define MMC_PVSDR104DDR50_DDR50CGEN_PROG                                                               ((uint32_t)1U)
#define MMC_PVSDR104DDR50_DDR50CGEN_HOST                                                               ((uint32_t)0U)

#define MMC_PVSDR104DDR50_DDR50DS_SHIFT                                                                  ((uint32_t)30U)
#define MMC_PVSDR104DDR50_DDR50DS_MASK                                                                   ((uint32_t)0xc0000000U)
#define MMC_PVSDR104DDR50_DDR50DS_DTD                                                                    ((uint32_t)3U)
#define MMC_PVSDR104DDR50_DDR50DS_DTC                                                                    ((uint32_t)2U)
#define MMC_PVSDR104DDR50_DDR50DS_DTA                                                                    ((uint32_t)1U)
#define MMC_PVSDR104DDR50_DDR50DS_DTB                                                                    ((uint32_t)0U)

#define MMC_PVSDR104DDR50_RESERVED_SHIFT                                                                     ((uint32_t)11U)
#define MMC_PVSDR104DDR50_RESERVED_MASK                                                                      ((uint32_t)0x00003800U)

#define MMC_PVSDR104DDR50_RESERVED1_SHIFT                                                                    ((uint32_t)27U)
#define MMC_PVSDR104DDR50_RESERVED1_MASK                                                                     ((uint32_t)0x38000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_BTCR (0x070h)
* @{
*/
#define MMC_BTCR_COUNTER_SHIFT                                                                         ((uint32_t)0U)
#define MMC_BTCR_COUNTER_MASK                                                                          ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_PVHS400 (0x074h)
* @{
*/
#define MMC_PVHS400_HS400SDCLK_SHIFT                                                              ((uint32_t)0U)
#define MMC_PVHS400_HS400SDCLK_MASK                                                               ((uint32_t)0x000003ffU)

#define MMC_PVHS400_HS400CGEN_SHIFT                                                             ((uint32_t)10U)
#define MMC_PVHS400_HS400CGEN_MASK                                                              ((uint32_t)0x00000400U)
#define MMC_PVHS400_HS400CGEN_PROG                                                              ((uint32_t)1U)
#define MMC_PVHS400_HS400CGEN_HOST                                                              ((uint32_t)0U)

#define MMC_PVHS400_HS400DS_SHIFT                                                                 ((uint32_t)14U)
#define MMC_PVHS400_HS400DS_MASK                                                                  ((uint32_t)0x0000c000U)
#define MMC_PVHS400_HS400DS_DTD                                                                   ((uint32_t)3U)
#define MMC_PVHS400_HS400DS_DTC                                                                   ((uint32_t)2U)
#define MMC_PVHS400_HS400DS_DTA                                                                   ((uint32_t)1U)
#define MMC_PVHS400_HS400DS_DTB                                                                   ((uint32_t)0U)

#define MMC_PVHS400_RESERVED_SHIFT                                                             ((uint32_t)11U)
#define MMC_PVHS400_RESERVED_MASK                                                              ((uint32_t)0x00003800U)
/* @} */

/*
* \brief Macros for SDHC MMC_VREG (0x078h)
* @{
*/
#define MMC_VREG_STROBE_SHIFT                                                                           ((uint32_t)0U)
#define MMC_VREG_STROBE_MASK                                                                            ((uint32_t)0x00000001U)
#define MMC_VREG_STROBE_ENABLE                                                                         ((uint32_t)1U)
#define MMC_VREG_STROBE_DISABLE                                                                        ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_REV (0x0FCh)
* @{
*/
#define MMC_REV_SIS_SHIFT                                                                                    ((uint32_t)0U)
#define MMC_REV_SIS_MASK                                                                                     ((uint32_t)0x00000001U)

#define MMC_REV_RESERVED_SHIFT                                                                         ((uint32_t)1U)
#define MMC_REV_RESERVED_MASK                                                                          ((uint32_t)0x0000fffeU)

#define MMC_REV_SREV_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_REV_SREV_MASK                                                                                    ((uint32_t)0x00ff0000U)
#define MMC_REV_SREV_VER1                                                                                    ((uint32_t)0U)
#define MMC_REV_SREV_VER2                                                                                    ((uint32_t)1U)
#define MMC_REV_SREV_VER3                                                                                    ((uint32_t)2U)
#define MMC_REV_SREV_OTHER                                                                                   ((uint32_t)3U)

#define MMC_REV_VREV_SHIFT                                                                                   ((uint32_t)24U)
#define MMC_REV_VREV_MASK                                                                                    ((uint32_t)0xff000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQVER (0x200h)
* @{
*/
#define MMC_CQVER_VER_SUFFIX_SHIFT                                                                 ((uint32_t)0U)
#define MMC_CQVER_VER_SUFFIX_MASK                                                                  ((uint32_t)0x0000000fU)
#define MMC_CQVER_VER_MINOR_SHIFT                                                                  ((uint32_t)4U)
#define MMC_CQVER_VER_MINOR_MASK                                                                   ((uint32_t)0x000000f0U)
#define MMC_CQVER_VER_MAJOR_SHIFT                                                                  ((uint32_t)8U)
#define MMC_CQVER_VER_MAJOR_MASK                                                                   ((uint32_t)0x00000f00U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQCAP (0x204h)
* @{
*/
#define MMC_CQCAP_ITCFVAL_SHIFT                                                                         ((uint32_t)0U)
#define MMC_CQCAP_ITCFVAL_MASK                                                                          ((uint32_t)0x000003ffU)

#define MMC_CQCAP_ITCFMUL_SHIFT                                                                         ((uint32_t)12U)
#define MMC_CQCAP_ITCFMUL_MASK                                                                          ((uint32_t)0x0000F000U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQCFG (0x208h)
* @{
*/
#define MMC_CQCFG_CQEN_SHIFT                                                                               ((uint32_t)0U)
#define MMC_CQCFG_CQEN_MASK                                                                                ((uint32_t)0x00000001U)
#define MMC_CQCFG_CQEN_ENABLE                                                                             ((uint32_t)1U)
#define MMC_CQCFG_CQEN_DISABLE                                                                            ((uint32_t)0U)

#define MMC_CQCFG_TDS_SHIFT                                                                                  ((uint32_t)8U)
#define MMC_CQCFG_TDS_MASK                                                                                   ((uint32_t)0x00000100U)
#define MMC_CQCFG_TDS_128BIT                                                                                ((uint32_t)1U)
#define MMC_CQCFG_TDS_64BIT                                                                                  ((uint32_t)0U)

#define MMC_CQCFG_DCMD_EN_SHIFT                                                                         ((uint32_t)12U)
#define MMC_CQCFG_DCMD_EN_MASK                                                                          ((uint32_t)0x00001000U)
#define MMC_CQCFG_DCMD_ENABLE                                                                             ((uint32_t)1U)
#define MMC_CQCFG_DCMD_DISABLE                                                                           ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQCTL (0x20Ch)
* @{
*/
#define MMC_CQCTL_HALT_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_CQCTL_HALT_MASK                                                                                  ((uint32_t)0x00000001U)
#define MMC_CQCTL_HALT_ON                                                                                      ((uint32_t)1U)
#define MMC_CQCTL_HALT_CLEAR                                                                                ((uint32_t)0U)

#define MMC_CQCTL_CLR_TASK_SHIFT                                                                         ((uint32_t)8U)
#define MMC_CQCTL_CLR_TASK_MASK                                                                          ((uint32_t)0x00000100U)
#define MMC_CQCTL_CLR_ALL_TASKS_EN                                                                     ((uint32_t)1U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQIS (0x210h)
* @{
*/
#define MMC_CQIS_HAC_SHIFT                                                                                     ((uint32_t)0U)
#define MMC_CQIS_HAC_MASK                                                                                      ((uint32_t)0x00000001U)
#define MMC_CQIS_HAC_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_CQIS_HAC_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_CQIS_HAC_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_CQIS_HAC_ST_UN_W                                                                               ((uint32_t)0U)

#define MMC_CQIS_TCC_SHIFT                                                                                     ((uint32_t)1U)
#define MMC_CQIS_TCC_MASK                                                                                      ((uint32_t)0x00000002U)
#define MMC_CQIS_TCC_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_CQIS_TCC_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_CQIS_TCC_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_CQIS_TCC_ST_UN_W                                                                               ((uint32_t)0U)

#define MMC_CQIS_RED_SHIFT                                                                                     ((uint32_t)2U)
#define MMC_CQIS_RED_MASK                                                                                      ((uint32_t)0x00000004U)
#define MMC_CQIS_RED_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_CQIS_RED_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_CQIS_RED_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_CQIS_RED_ST_UN_W                                                                               ((uint32_t)0U)

#define MMC_CQIS_TCL_SHIFT                                                                                      ((uint32_t)3U)
#define MMC_CQIS_TCL_MASK                                                                                       ((uint32_t)0x00000008U)
#define MMC_CQIS_TCL_IRQ_TRU_R                                                                             ((uint32_t)1U)
#define MMC_CQIS_TCL_IRQ_FAL_R                                                                             ((uint32_t)0U)
#define MMC_CQIS_TCL_ST_RST_W                                                                              ((uint32_t)1U)
#define MMC_CQIS_TCL_ST_UN_W                                                                               ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQISTE (0x214h)
* @{
*/
#define MMC_CQISTE_HAC_SHIFT                                                                                 ((uint32_t)0U)
#define MMC_CQISTE_HAC_MASK                                                                                  ((uint32_t)0x00000001U)
#define MMC_CQISTE_HAC_ENABLE_ENABLED                                                              ((uint32_t)1U)
#define MMC_CQISTE_HAC_ENABLE_MASKED                                                               ((uint32_t)0U)

#define MMC_CQISTE_TCC_SHIFT                                                                                 ((uint32_t)1U)
#define MMC_CQISTE_TCC_MASK                                                                                  ((uint32_t)0x00000002U)
#define MMC_CQISTE_TCC_ENABLE_ENABLED                                                              ((uint32_t)1U)
#define MMC_CQISTE_TCC_ENABLE_MASKED                                                                ((uint32_t)0U)

#define MMC_CQISTE_RED_SHIFT                                                                                 ((uint32_t)2U)
#define MMC_CQISTE_RED_MASK                                                                                  ((uint32_t)0x00000004U)
#define MMC_CQISTE_RED_ENABLE_ENABLED                                                              ((uint32_t)1U)
#define MMC_CQISTE_RED_ENABLE_MASKED                                                                ((uint32_t)0U)

#define MMC_CQISTE_TCL_SHIFT                                                                                  ((uint32_t)3U)
#define MMC_CQISTE_TCL_MASK                                                                                   ((uint32_t)0x00000008U)
#define MMC_CQISTE_TCL_ENABLE_ENABLED                                                               ((uint32_t)1U)
#define MMC_CQISTE_TCL_ENABLE_MASKED                                                                ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQISGE (0x218h)
* @{
*/
#define MMC_CQISGE_HAC_SIGEN_SHIFT                                                                     ((uint32_t)0U)
#define MMC_CQISGE_HAC_SIGEN_MASK                                                                      ((uint32_t)0x00000001U)
#define MMC_CQISGE_HAC_SIGEN_ENABLED                                                                ((uint32_t)1U)
#define MMC_CQISGE_HAC_SIGEN_MASKED                                                                  ((uint32_t)0U)

#define MMC_CQISGE_TCC_SIGEN_SHIFT                                                                     ((uint32_t)1U)
#define MMC_CQISGE_TCC_SIGEN_MASK                                                                      ((uint32_t)0x00000002U)
#define MMC_CQISGE_TCC_SIGEN_ENABLED                                                                ((uint32_t)1U)
#define MMC_CQISGE_TCC_SIGEN_MASKED                                                                  ((uint32_t)0U)

#define MMC_CQISGE_RED_SIGEN_SHIFT                                                                     ((uint32_t)2U)
#define MMC_CQISGE_RED_SIGEN_MASK                                                                      ((uint32_t)0x00000004U)
#define MMC_CQISGE_RED_SIGEN_ENABLED                                                                ((uint32_t)1U)
#define MMC_CQISGE_RED_SIGEN_MASKED                                                                  ((uint32_t)0U)

#define MMC_CQISGE_TCL_SIGEN_SHIFT                                                                     ((uint32_t)3U)
#define MMC_CQISGE_TCL_SIGEN_MASK                                                                      ((uint32_t)0x00000008U)
#define MMC_CQISGE_TCL_SIGEN_ENABLED                                                                ((uint32_t)1U)
#define MMC_CQISGE_TCL_SIGEN_MASKED                                                                  ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQIC (0x21Ch)
* @{
*/
#define MMC_CQIC_ICTOVAL_SHIFT                                                                             ((uint32_t)0U)
#define MMC_CQIC_ICTOVAL_MASK                                                                              ((uint32_t)0x0000007fU)
#define MMC_CQIC_ICTOVALWEN_SHIFT                                                                      ((uint32_t)7U)
#define MMC_CQIC_ICTOVALWEN_MASK                                                                       ((uint32_t)0x00000080U)
#define MMC_CQIC_ICCTH_SHIFT                                                                                 ((uint32_t)8U)
#define MMC_CQIC_ICCTH_MASK                                                                                  ((uint32_t)0x00001F00U)
#define MMC_CQIC_ICCTHWEN_SHIFT                                                                          ((uint32_t)15U)
#define MMC_CQIC_ICCTHWEN_MASK                                                                           ((uint32_t)0x00008000U)
#define MMC_CQIC_ICCTR_SHIFT                                                                                  ((uint32_t)16U)
#define MMC_CQIC_ICCTR_MASK                                                                                   ((uint32_t)0x00010000U)
#define MMC_CQIC_ICCTR_RESET                                                                                  ((uint32_t)1U)
#define MMC_CQIC_ICSB_SHIFT                                                                                    ((uint32_t)20U)
#define MMC_CQIC_ICSB_MASK                                                                                     ((uint32_t)0x00100000U)
#define MMC_CQIC_ICEN_SHIFT                                                                                    ((uint32_t)31U)
#define MMC_CQIC_ICEN_MASK                                                                                     ((uint32_t)0x80000000U)
#define MMC_CQIC_ICEN_ENABLE                                                                                  ((uint32_t)1U)
#define MMC_CQIC_ICEN_DISABLE                                                                                 ((uint32_t)0U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQTDLBA (0x220h)
* @{
*/
#define MMC_CQTDLBA_TDLBA_SHIFT                                                                           ((uint32_t)0U)
#define MMC_CQTDLBA_TDLBA_MASK                                                                            ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_CQTDLBAU (0x224h)
* @{
*/
#define MMC_CQTDLBAU_TDLBA_SHIFT                                                                         ((uint32_t)0U)
#define MMC_CQTDLBAU_TDLBA_MASK                                                                          ((uint32_t)0xffffffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_CQSSC1 (0x240h)
* @{
*/
#define MMC_CQSSC1_CIT_SHIFT                                                                                   ((uint32_t)0U)
#define MMC_CQSSC1_CIT_MASK                                                                                    ((uint32_t)0x0000ffffU)

#define MMC_CQSSC1_CBC_SHIFT                                                                                   ((uint32_t)16U)
#define MMC_CQSSC1_CBC_MASK                                                                                    ((uint32_t)0x000f0000U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQSSC2 (0x244h)
* @{
*/
#define MMC_CQSSC2_SQSRCA_SHIFT                                                                             ((uint32_t)0U)
#define MMC_CQSSC2_SQSRCA_MASK                                                                              ((uint32_t)0x0000ffffU)
/* @} */

/*
* \brief Macros for SDHC MMC_CQTERRI (0x254h)
* @{
*/
#define MMC_CQTERRI_RMECI_SHIFT                                                                              ((uint32_t)0U)
#define MMC_CQTERRI_RMECI_MASK                                                                               ((uint32_t)0x0000003fU)
#define MMC_CQTERRI_RMETI_SHIFT                                                                              ((uint32_t)8U)
#define MMC_CQTERRI_RMETI_MASK                                                                               ((uint32_t)0x00001f00U)
#define MMC_CQTERRI_RMEFV_SHIFT                                                                              ((uint32_t)15U)
#define MMC_CQTERRI_RMEFV_MASK                                                                               ((uint32_t)0x00008000U)
#define MMC_CQTERRI_DTECI_SHIFT                                                                               ((uint32_t)16U)
#define MMC_CQTERRI_DTECI_MASK                                                                                ((uint32_t)0x003f0000U)
#define MMC_CQTERRI_DTETI_SHIFT                                                                               ((uint32_t)24U)
#define MMC_CQTERRI_DTETI_MASK                                                                                ((uint32_t)0x1f000000U)
#define MMC_CQTERRI_DTEFV_SHIFT                                                                               ((uint32_t)31U)
#define MMC_CQTERRI_DTEFV_MASK                                                                                ((uint32_t)0x80000000U)
/* @} */

/*
* \brief Macros for SDHC MMC_CQCRI (0x258h)
* @{
*/
#define MMC_CQCRI_LCRI_SHIFT                                                                                      ((uint32_t)0U)
#define MMC_CQCRI_LCRI_MASK                                                                                       ((uint32_t)0x0000003fU)
/* @} */

/*
* \brief Macros for SDHC MMC_CQCRA (0x25Ch)
* @{
*/
#define MMC_CQCRA_LCRA_SHIFT                                                                                    ((uint32_t)0U)
#define MMC_CQCRA_LCRA_MASK                                                                                     ((uint32_t)0xffffffffU)
/* @} */



#ifdef __cplusplus
}
#endif
#endif  /* HW_MMC_H_ */
