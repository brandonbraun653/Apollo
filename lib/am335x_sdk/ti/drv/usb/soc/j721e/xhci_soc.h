/******************************************************************************
*
* Register header file for xHCI registers
*
******************************************************************************
*/
/**
 *  Copyright (c) Texas Instruments Incorporated 2019
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



#ifndef PDK__HW_XHCI_INC_USB_H
#define PDK__HW_XHCI_INC_USB_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef SOC_J721E
#error "wrong SOC"
#endif

/**************************************************************************
* Register Definitions
**************************************************************************/
#define XHCI_USB_CAPLENGTH                                       (0x0u)
#define XHCI_USB_HCSPARAMS1                                      (0x4u)
#define XHCI_USB_HCSPARAMS2                                      (0x8u)
#define XHCI_USB_HCSPARAMS3                                      (0xCu)
#define XHCI_USB_HCCPARAMS                                       (0x10u)
#define XHCI_USB_DBOFF                                           (0x14u)
#define XHCI_USB_RTSOFF                                          (0x18u)
#define XHCI_USB_HCCPARAMS2                                      (0x1Cu)

#define XHCI_USB_USBCMD                                          (0x80u)
#define XHCI_USB_USBSTS                                          (0x84u)
#define XHCI_USB_PAGESIZE                                        (0x88u)

#define XHCI_USB_DNCTRL                                          (0x94u)
#define XHCI_USB_CRCR_LO                                         (0x98u)
#define XHCI_USB_CRCR_HI                                         (0x9Cu)

#define XHCI_USB_DCBAAP_LO                                       (0xB0u)
#define XHCI_USB_DCBAAP_HI                                       (0xB4u)
#define XHCI_USB_CONFIG                                          (0xB8u)

#define XHCI_USB_PORTSC1                                         (0x480u)
#define XHCI_USB_PORTPMSC1                                       (0x484u)
#define XHCI_USB_PORTHLPMC1                                      (0x48Cu)

#define XHCI_USB_PORTSC2                                         (0x490u)
#define XHCI_USB_PORTPMSC2                                       (0x494u)
#define XHCI_USB_PORTLI1                                         (0x498u)

#define XHCI_USB_MFINDEX                                         (0x2000u)

#define XHCI_USB_IMAN(n)                                         (0x2020U + ((n-1) * 0x20U))
#define XHCI_USB_IMOD(n)                                         (0x2024U + ((n-1) * 0x20U))

#define XHCI_USB_ERSTSZ(n)                                       (0x2028U + ((n-1) * 0x20U))

#define XHCI_USB_ERSTBA_LO(n)                                    (0x2030U + ((n-1) * 0x20U))
#define XHCI_USB_ERSTBA_HI(n)                                    (0x2034U + ((n-1) * 0x20U))
#define XHCI_USB_ERDP_LO(n)                                      (0x2038U + ((n-1) * 0x20U))
#define XHCI_USB_ERDP_HI(n)                                      (0x203CU + ((n-1) * 0x20U))

#define XHCI_USB_DB(n)                                           (0x3000U + ((n-1) * 0x4U))

#define XHCI_USB_USBLEGSUP                                       (0x8370u)
#define XHCI_USB_USBLEGCTLSTS                                    (0x8374u)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

#define XHCI_USB_CAPLENGTH_CAPLENGTH_SHIFT                       (0U)
#define XHCI_USB_CAPLENGTH_CAPLENGTH_MASK                        (0x000000ffU)

#define XHCI_USB_CAPLENGTH_HCIVERSION_SHIFT                      (16U)
#define XHCI_USB_CAPLENGTH_HCIVERSION_MASK                       (0xffff0000U)
#define XHCI_USB_CAPLENGTH_HCIVERSION_0_96                        (150U)
#define XHCI_USB_CAPLENGTH_HCIVERSION_1_00                        (256U)

#define XHCI_USB_HCSPARAMS1_MAXSLOTS_SHIFT                       (0U)
#define XHCI_USB_HCSPARAMS1_MAXSLOTS_MASK                        (0x000000ffU)

#define XHCI_USB_HCSPARAMS1_MAXINTRS_SHIFT                       (8U)
#define XHCI_USB_HCSPARAMS1_MAXINTRS_MASK                        (0x0007ff00U)

#define XHCI_USB_HCSPARAMS1_MAXPORTS_SHIFT                       (24U)
#define XHCI_USB_HCSPARAMS1_MAXPORTS_MASK                        (0xff000000U)

#define XHCI_USB_HCSPARAMS2_IST_SHIFT                            (0U)
#define XHCI_USB_HCSPARAMS2_IST_MASK                             (0x0000000fU)

#define XHCI_USB_HCSPARAMS2_ERSTMAX_SHIFT                        (4U)
#define XHCI_USB_HCSPARAMS2_ERSTMAX_MASK                         (0x000000f0U)

#define XHCI_USB_HCSPARAMS2_SPR_SHIFT                            (26U)
#define XHCI_USB_HCSPARAMS2_SPR_MASK                             (0x04000000U)
#define XHCI_USB_HCSPARAMS2_SPR_NO                                (0U)
#define XHCI_USB_HCSPARAMS2_SPR_YES                               (1U)

#define XHCI_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_SHIFT           (27U)
#define XHCI_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_MASK            (0xf8000000U)

#define XHCI_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT           (21U)
#define XHCI_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK            (0x03e00000U)

#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT             (0U)
#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK              (0x000000ffU)
#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_ZERO               (0U)
#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_1                  (1U)
#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_2                  (2U)
#define XHCI_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_10                 (10U)

#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT             (16U)
#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK              (0xffff0000U)
#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_ZERO               (0U)
#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_1                  (1U)
#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_2                  (2U)
#define XHCI_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_2047               (2047U)

#define XHCI_USB_HCCPARAMS_AC64_SHIFT                            (0U)
#define XHCI_USB_HCCPARAMS_AC64_MASK                             (0x00000001U)

#define XHCI_USB_HCCPARAMS_BNC_SHIFT                             (1U)
#define XHCI_USB_HCCPARAMS_BNC_MASK                              (0x00000002U)

#define XHCI_USB_HCCPARAMS_CSZ_SHIFT                             (2U)
#define XHCI_USB_HCCPARAMS_CSZ_MASK                              (0x00000004U)

#define XHCI_USB_HCCPARAMS_PPC_SHIFT                             (3U)
#define XHCI_USB_HCCPARAMS_PPC_MASK                              (0x00000008U)

#define XHCI_USB_HCCPARAMS_PIND_SHIFT                            (4U)
#define XHCI_USB_HCCPARAMS_PIND_MASK                             (0x00000010U)

#define XHCI_USB_HCCPARAMS_LHRC_SHIFT                            (5U)
#define XHCI_USB_HCCPARAMS_LHRC_MASK                             (0x00000020U)

#define XHCI_USB_HCCPARAMS_LTC_SHIFT                             (6U)
#define XHCI_USB_HCCPARAMS_LTC_MASK                              (0x00000040U)

#define XHCI_USB_HCCPARAMS_NSS_SHIFT                             (7U)
#define XHCI_USB_HCCPARAMS_NSS_MASK                              (0x00000080U)

#define XHCI_USB_HCCPARAMS_MAXPSASIZE_SHIFT                      (12U)
#define XHCI_USB_HCCPARAMS_MAXPSASIZE_MASK                       (0x0000f000U)

#define XHCI_USB_HCCPARAMS_XECP_SHIFT                            (16U)
#define XHCI_USB_HCCPARAMS_XECP_MASK                             (0xffff0000U)

#define XHCI_USB_HCCPARAMS_PAE_SHIFT                             (8U)
#define XHCI_USB_HCCPARAMS_PAE_MASK                              (0x00000100U)

#define XHCI_USB_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT               (2U)
#define XHCI_USB_DBOFF_DOORBELL_ARRAY_OFFSET_MASK                (0xfffffffcU)

#define XHCI_USB_DBOFF_ZERO_SHIFT                                (0U)
#define XHCI_USB_DBOFF_ZERO_MASK                                 (0x00000003U)

#define XHCI_USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT           (5U)
#define XHCI_USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK            (0xffffffe0U)

#define XHCI_USB_RTSOFF_ZERO_SHIFT                               (0U)
#define XHCI_USB_RTSOFF_ZERO_MASK                                (0x0000001fU)

#define XHCI_USB_USBCMD_R_S_SHIFT                                (0U)
#define XHCI_USB_USBCMD_R_S_MASK                                 (0x00000001U)

#define XHCI_USB_USBCMD_HCRST_SHIFT                              (1U)
#define XHCI_USB_USBCMD_HCRST_MASK                               (0x00000002U)

#define XHCI_USB_USBCMD_INTE_SHIFT                               (2U)
#define XHCI_USB_USBCMD_INTE_MASK                                (0x00000004U)

#define XHCI_USB_USBCMD_HSEE_SHIFT                               (3U)
#define XHCI_USB_USBCMD_HSEE_MASK                                (0x00000008U)

#define XHCI_USB_USBCMD_LHCRST_SHIFT                             (7U)
#define XHCI_USB_USBCMD_LHCRST_MASK                              (0x00000080U)

#define XHCI_USB_USBCMD_CSS_SHIFT                                (8U)
#define XHCI_USB_USBCMD_CSS_MASK                                 (0x00000100U)

#define XHCI_USB_USBCMD_CRS_SHIFT                                (9U)
#define XHCI_USB_USBCMD_CRS_MASK                                 (0x00000200U)

#define XHCI_USB_USBCMD_EWE_SHIFT                                (10U)
#define XHCI_USB_USBCMD_EWE_MASK                                 (0x00000400U)

#define XHCI_USB_USBCMD_EU3S_SHIFT                               (11U)
#define XHCI_USB_USBCMD_EU3S_MASK                                (0x00000800U)

#define XHCI_USB_USBSTS_HCH_SHIFT                                (0U)
#define XHCI_USB_USBSTS_HCH_MASK                                 (0x00000001U)

#define XHCI_USB_USBSTS_HSE_SHIFT                                (2U)
#define XHCI_USB_USBSTS_HSE_MASK                                 (0x00000004U)

#define XHCI_USB_USBSTS_EINT_SHIFT                               (3U)
#define XHCI_USB_USBSTS_EINT_MASK                                (0x00000008U)

#define XHCI_USB_USBSTS_PCD_SHIFT                                (4U)
#define XHCI_USB_USBSTS_PCD_MASK                                 (0x00000010U)

#define XHCI_USB_USBSTS_SSS_SHIFT                                (8U)
#define XHCI_USB_USBSTS_SSS_MASK                                 (0x00000100U)

#define XHCI_USB_USBSTS_RSS_SHIFT                                (9U)
#define XHCI_USB_USBSTS_RSS_MASK                                 (0x00000200U)

#define XHCI_USB_USBSTS_SRE_SHIFT                                (10U)
#define XHCI_USB_USBSTS_SRE_MASK                                 (0x00000400U)

#define XHCI_USB_USBSTS_CNR_SHIFT                                (11U)
#define XHCI_USB_USBSTS_CNR_MASK                                 (0x00000800U)
#define XHCI_USB_USBSTS_CNR_READY                                 (0U)
#define XHCI_USB_USBSTS_CNR_NOTREADY                              (1U)

#define XHCI_USB_USBSTS_HCE_SHIFT                                (12U)
#define XHCI_USB_USBSTS_HCE_MASK                                 (0x00001000U)

#define XHCI_USB_PAGESIZE_PAGE_SIZE_SHIFT                        (0U)
#define XHCI_USB_PAGESIZE_PAGE_SIZE_MASK                         (0x0000ffffU)
#define XHCI_USB_PAGESIZE_PAGE_SIZE_4KB                           (1U)

#define XHCI_USB_DNCTRL_N0_SHIFT                                 (0U)
#define XHCI_USB_DNCTRL_N0_MASK                                  (0x00000001U)

#define XHCI_USB_DNCTRL_N1_SHIFT                                 (1U)
#define XHCI_USB_DNCTRL_N1_MASK                                  (0x00000002U)

#define XHCI_USB_DNCTRL_N2_SHIFT                                 (2U)
#define XHCI_USB_DNCTRL_N2_MASK                                  (0x00000004U)

#define XHCI_USB_DNCTRL_N3_SHIFT                                 (3U)
#define XHCI_USB_DNCTRL_N3_MASK                                  (0x00000008U)

#define XHCI_USB_DNCTRL_N4_SHIFT                                 (4U)
#define XHCI_USB_DNCTRL_N4_MASK                                  (0x00000010U)

#define XHCI_USB_DNCTRL_N5_SHIFT                                 (5U)
#define XHCI_USB_DNCTRL_N5_MASK                                  (0x00000020U)

#define XHCI_USB_DNCTRL_N6_SHIFT                                 (6U)
#define XHCI_USB_DNCTRL_N6_MASK                                  (0x00000040U)

#define XHCI_USB_DNCTRL_N7_SHIFT                                 (7U)
#define XHCI_USB_DNCTRL_N7_MASK                                  (0x00000080U)

#define XHCI_USB_DNCTRL_N8_SHIFT                                 (8U)
#define XHCI_USB_DNCTRL_N8_MASK                                  (0x00000100U)

#define XHCI_USB_DNCTRL_N9_SHIFT                                 (9U)
#define XHCI_USB_DNCTRL_N9_MASK                                  (0x00000200U)

#define XHCI_USB_DNCTRL_N10_SHIFT                                (10U)
#define XHCI_USB_DNCTRL_N10_MASK                                 (0x00000400U)

#define XHCI_USB_DNCTRL_N11_SHIFT                                (11U)
#define XHCI_USB_DNCTRL_N11_MASK                                 (0x00000800U)

#define XHCI_USB_DNCTRL_N12_SHIFT                                (12U)
#define XHCI_USB_DNCTRL_N12_MASK                                 (0x00001000U)

#define XHCI_USB_DNCTRL_N13_SHIFT                                (13U)
#define XHCI_USB_DNCTRL_N13_MASK                                 (0x00002000U)

#define XHCI_USB_DNCTRL_N14_SHIFT                                (14U)
#define XHCI_USB_DNCTRL_N14_MASK                                 (0x00004000U)

#define XHCI_USB_DNCTRL_N15_SHIFT                                (15U)
#define XHCI_USB_DNCTRL_N15_MASK                                 (0x00008000U)

#define XHCI_USB_CRCR_LO_RCS_SHIFT                               (0U)
#define XHCI_USB_CRCR_LO_RCS_MASK                                (0x00000001U)

#define XHCI_USB_CRCR_LO_CS_SHIFT                                (1U)
#define XHCI_USB_CRCR_LO_CS_MASK                                 (0x00000002U)

#define XHCI_USB_CRCR_LO_CA_SHIFT                                (2U)
#define XHCI_USB_CRCR_LO_CA_MASK                                 (0x00000004U)

#define XHCI_USB_CRCR_LO_CRR_SHIFT                               (3U)
#define XHCI_USB_CRCR_LO_CRR_MASK                                (0x00000008U)

#define XHCI_USB_CRCR_LO_CMD_RING_PNTR_SHIFT                     (6U)
#define XHCI_USB_CRCR_LO_CMD_RING_PNTR_MASK                      (0xffffffc0U)

#define XHCI_USB_CRCR_HI_CMD_RING_PNTR_SHIFT                     (0U)
#define XHCI_USB_CRCR_HI_CMD_RING_PNTR_MASK                      (0xffffffffU)

#define XHCI_USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT             (6U)
#define XHCI_USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK              (0xffffffc0U)

#define XHCI_USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT             (0U)
#define XHCI_USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK              (0xffffffffU)

#define XHCI_USB_CONFIG_MAXSLOTSEN_SHIFT                         (0U)
#define XHCI_USB_CONFIG_MAXSLOTSEN_MASK                          (0x000000ffU)

#define XHCI_USB_PORTSC2_CCS_SHIFT                               (0U)
#define XHCI_USB_PORTSC2_CCS_MASK                                (0x00000001U)

#define XHCI_USB_PORTSC2_PED_SHIFT                               (1U)
#define XHCI_USB_PORTSC2_PED_MASK                                (0x00000002U)

#define XHCI_USB_PORTSC2_OCA_SHIFT                               (3U)
#define XHCI_USB_PORTSC2_OCA_MASK                                (0x00000008U)

#define XHCI_USB_PORTSC2_PR_SHIFT                                (4U)
#define XHCI_USB_PORTSC2_PR_MASK                                 (0x00000010U)

#define XHCI_USB_PORTSC2_PLS_SHIFT                               (5U)
#define XHCI_USB_PORTSC2_PLS_MASK                                (0x000001e0U)
#define XHCI_USB_PORTSC2_PLS_U0                                   (0U)
#define XHCI_USB_PORTSC2_PLS_U1                                   (1U)
#define XHCI_USB_PORTSC2_PLS_U2                                   (2U)
#define XHCI_USB_PORTSC2_PLS_U3                                   (3U)
#define XHCI_USB_PORTSC2_PLS_DISABLED                             (4U)
#define XHCI_USB_PORTSC2_PLS_RXDETECT                             (5U)
#define XHCI_USB_PORTSC2_PLS_INACTIVE                             (6U)
#define XHCI_USB_PORTSC2_PLS_POLLING                              (7U)
#define XHCI_USB_PORTSC2_PLS_RECOVERY                             (8U)
#define XHCI_USB_PORTSC2_PLS_HOTRESET                             (9U)
#define XHCI_USB_PORTSC2_PLS_COMPLIANCEMODE                       (10U)
#define XHCI_USB_PORTSC2_PLS_TESTMODE                             (11U)
#define XHCI_USB_PORTSC2_PLS_RESUME                               (15U)

#define XHCI_USB_PORTSC2_PP_SHIFT                                (9U)
#define XHCI_USB_PORTSC2_PP_MASK                                 (0x00000200U)

#define XHCI_USB_PORTSC2_PORTSPEED_SHIFT                         (10U)
#define XHCI_USB_PORTSC2_PORTSPEED_MASK                          (0x00003c00U)

#define XHCI_USB_PORTSC2_PIC_SHIFT                               (14U)
#define XHCI_USB_PORTSC2_PIC_MASK                                (0x0000c000U)

#define XHCI_USB_PORTSC2_LWS_SHIFT                               (16U)
#define XHCI_USB_PORTSC2_LWS_MASK                                (0x00010000U)

#define XHCI_USB_PORTSC2_CSC_SHIFT                               (17U)
#define XHCI_USB_PORTSC2_CSC_MASK                                (0x00020000U)

#define XHCI_USB_PORTSC2_PEC_SHIFT                               (18U)
#define XHCI_USB_PORTSC2_PEC_MASK                                (0x00040000U)

#define XHCI_USB_PORTSC2_WRC_SHIFT                               (19U)
#define XHCI_USB_PORTSC2_WRC_MASK                                (0x00080000U)

#define XHCI_USB_PORTSC2_OCC_SHIFT                               (20U)
#define XHCI_USB_PORTSC2_OCC_MASK                                (0x00100000U)

#define XHCI_USB_PORTSC2_PRC_SHIFT                               (21U)
#define XHCI_USB_PORTSC2_PRC_MASK                                (0x00200000U)

#define XHCI_USB_PORTSC2_PLC_SHIFT                               (22U)
#define XHCI_USB_PORTSC2_PLC_MASK                                (0x00400000U)

#define XHCI_USB_PORTSC2_CEC_SHIFT                               (23U)
#define XHCI_USB_PORTSC2_CEC_MASK                                (0x00800000U)

#define XHCI_USB_PORTSC2_WCE_SHIFT                               (25U)
#define XHCI_USB_PORTSC2_WCE_MASK                                (0x02000000U)

#define XHCI_USB_PORTSC2_WDE_SHIFT                               (26U)
#define XHCI_USB_PORTSC2_WDE_MASK                                (0x04000000U)

#define XHCI_USB_PORTSC2_WOE_SHIFT                               (27U)
#define XHCI_USB_PORTSC2_WOE_MASK                                (0x08000000U)

#define XHCI_USB_PORTSC2_DR_SHIFT                                (30U)
#define XHCI_USB_PORTSC2_DR_MASK                                 (0x40000000U)

#define XHCI_USB_PORTSC2_WPR_SHIFT                               (31U)
#define XHCI_USB_PORTSC2_WPR_MASK                                (0x80000000U)

#define XHCI_USB_PORTSC2_CAS_SHIFT                               (24U)
#define XHCI_USB_PORTSC2_CAS_MASK                                (0x01000000U)

#define XHCI_USB_PORTPMSC2_U1_TIMEOUT_SHIFT                      (0U)
#define XHCI_USB_PORTPMSC2_U1_TIMEOUT_MASK                       (0x000000ffU)

#define XHCI_USB_PORTPMSC2_U2_TIMEOUT_SHIFT                      (8U)
#define XHCI_USB_PORTPMSC2_U2_TIMEOUT_MASK                       (0x0000ff00U)

#define XHCI_USB_PORTPMSC2_FLA_SHIFT                             (16U)
#define XHCI_USB_PORTPMSC2_FLA_MASK                              (0x00010000U)

#define XHCI_USB_PORTLI2_LINK_ERROR_COUNT_SHIFT                  (0U)
#define XHCI_USB_PORTLI2_LINK_ERROR_COUNT_MASK                   (0x0000ffffU)

#define XHCI_USB_PORTSC1_CCS_SHIFT                               (0U)
#define XHCI_USB_PORTSC1_CCS_MASK                                (0x00000001U)

#define XHCI_USB_PORTSC1_PED_SHIFT                               (1U)
#define XHCI_USB_PORTSC1_PED_MASK                                (0x00000002U)

#define XHCI_USB_PORTSC1_OCA_SHIFT                               (3U)
#define XHCI_USB_PORTSC1_OCA_MASK                                (0x00000008U)

#define XHCI_USB_PORTSC1_PR_SHIFT                                (4U)
#define XHCI_USB_PORTSC1_PR_MASK                                 (0x00000010U)

#define XHCI_USB_PORTSC1_PLS_SHIFT                               (5U)
#define XHCI_USB_PORTSC1_PLS_MASK                                (0x000001e0U)
#define XHCI_USB_PORTSC1_PLS_U0                                   (0U)
#define XHCI_USB_PORTSC1_PLS_U1                                   (1U)
#define XHCI_USB_PORTSC1_PLS_U2                                   (2U)
#define XHCI_USB_PORTSC1_PLS_U3                                   (3U)
#define XHCI_USB_PORTSC1_PLS_DISABLED                             (4U)
#define XHCI_USB_PORTSC1_PLS_RXDETECT                             (5U)
#define XHCI_USB_PORTSC1_PLS_INACTIVE                             (6U)
#define XHCI_USB_PORTSC1_PLS_POLLING                              (7U)
#define XHCI_USB_PORTSC1_PLS_RECOVERY                             (8U)
#define XHCI_USB_PORTSC1_PLS_HOTRESET                             (9U)
#define XHCI_USB_PORTSC1_PLS_COMPLIANCEMODE                       (10U)
#define XHCI_USB_PORTSC1_PLS_TESTMODE                             (11U)
#define XHCI_USB_PORTSC1_PLS_RESUME                               (15U)

#define XHCI_USB_PORTSC1_PP_SHIFT                                (9U)
#define XHCI_USB_PORTSC1_PP_MASK                                 (0x00000200U)

#define XHCI_USB_PORTSC1_PORTSPEED_SHIFT                         (10U)
#define XHCI_USB_PORTSC1_PORTSPEED_MASK                          (0x00003c00U)

#define XHCI_USB_PORTSC1_PIC_SHIFT                               (14U)
#define XHCI_USB_PORTSC1_PIC_MASK                                (0x0000c000U)

#define XHCI_USB_PORTSC1_LWS_SHIFT                               (16U)
#define XHCI_USB_PORTSC1_LWS_MASK                                (0x00010000U)

#define XHCI_USB_PORTSC1_CSC_SHIFT                               (17U)
#define XHCI_USB_PORTSC1_CSC_MASK                                (0x00020000U)

#define XHCI_USB_PORTSC1_PEC_SHIFT                               (18U)
#define XHCI_USB_PORTSC1_PEC_MASK                                (0x00040000U)

#define XHCI_USB_PORTSC1_WRC_SHIFT                               (19U)
#define XHCI_USB_PORTSC1_WRC_MASK                                (0x00080000U)

#define XHCI_USB_PORTSC1_OCC_SHIFT                               (20U)
#define XHCI_USB_PORTSC1_OCC_MASK                                (0x00100000U)

#define XHCI_USB_PORTSC1_PRC_SHIFT                               (21U)
#define XHCI_USB_PORTSC1_PRC_MASK                                (0x00200000U)

#define XHCI_USB_PORTSC1_PLC_SHIFT                               (22U)
#define XHCI_USB_PORTSC1_PLC_MASK                                (0x00400000U)

#define XHCI_USB_PORTSC1_CEC_SHIFT                               (23U)
#define XHCI_USB_PORTSC1_CEC_MASK                                (0x00800000U)

#define XHCI_USB_PORTSC1_WCE_SHIFT                               (25U)
#define XHCI_USB_PORTSC1_WCE_MASK                                (0x02000000U)

#define XHCI_USB_PORTSC1_WDE_SHIFT                               (26U)
#define XHCI_USB_PORTSC1_WDE_MASK                                (0x04000000U)

#define XHCI_USB_PORTSC1_WOE_SHIFT                               (27U)
#define XHCI_USB_PORTSC1_WOE_MASK                                (0x08000000U)

#define XHCI_USB_PORTSC1_DR_SHIFT                                (30U)
#define XHCI_USB_PORTSC1_DR_MASK                                 (0x40000000U)

#define XHCI_USB_PORTSC1_WPR_SHIFT                               (31U)
#define XHCI_USB_PORTSC1_WPR_MASK                                (0x80000000U)

#define XHCI_USB_PORTSC1_CAS_SHIFT                               (24U)
#define XHCI_USB_PORTSC1_CAS_MASK                                (0x01000000U)

#define XHCI_USB_PORTPMSC1_L1S_SHIFT                             (0U)
#define XHCI_USB_PORTPMSC1_L1S_MASK                              (0x00000007U)

#define XHCI_USB_PORTPMSC1_RWE_SHIFT                             (3U)
#define XHCI_USB_PORTPMSC1_RWE_MASK                              (0x00000008U)

#define XHCI_USB_PORTPMSC1_L1_DEVICE_SLOT_SHIFT                  (8U)
#define XHCI_USB_PORTPMSC1_L1_DEVICE_SLOT_MASK                   (0x0000ff00U)

#define XHCI_USB_PORTPMSC1_PORT_TEST_CTRL_SHIFT                  (28U)
#define XHCI_USB_PORTPMSC1_PORT_TEST_CTRL_MASK                   (0xf0000000U)

#define XHCI_USB_PORTPMSC1_HLE_SHIFT                             (16U)
#define XHCI_USB_PORTPMSC1_HLE_MASK                              (0x00010000U)

#define XHCI_USB_PORTPMSC1_BESL_SHIFT                            (4U)
#define XHCI_USB_PORTPMSC1_BESL_MASK                             (0x000000f0U)

#define XHCI_USB_PORTLI1_LINK_ERROR_COUNT_SHIFT                  (0U)
#define XHCI_USB_PORTLI1_LINK_ERROR_COUNT_MASK                   (0x0000ffffU)

#define XHCI_USB_PORTHLPMC1_HIRDM_SHIFT                          (0U)
#define XHCI_USB_PORTHLPMC1_HIRDM_MASK                           (0x00000003U)

#define XHCI_USB_PORTHLPMC1_L1_TIMEOUT_SHIFT                     (2U)
#define XHCI_USB_PORTHLPMC1_L1_TIMEOUT_MASK                      (0x000003fcU)

#define XHCI_USB_PORTHLPMC1_BESLD_SHIFT                          (10U)
#define XHCI_USB_PORTHLPMC1_BESLD_MASK                           (0x00003c00U)

#define XHCI_USB_MFINDEX_MICROFRM_IDX_SHIFT                      (0U)
#define XHCI_USB_MFINDEX_MICROFRM_IDX_MASK                       (0x00003fffU)

#define XHCI_USB_IMAN_IP_SHIFT                                   (0U)
#define XHCI_USB_IMAN_IP_MASK                                    (0x00000001U)
#define XHCI_USB_IMAN_IP_PENDING                                  (1U)
#define XHCI_USB_IMAN_IP_IDLE                                     (0U)

#define XHCI_USB_IMAN_IE_SHIFT                                   (1U)
#define XHCI_USB_IMAN_IE_MASK                                    (0x00000002U)
#define XHCI_USB_IMAN_IE_DIS                                      (0U)
#define XHCI_USB_IMAN_IE_EN                                       (1U)

#define XHCI_USB_IMOD_IMODI_SHIFT                                (0U)
#define XHCI_USB_IMOD_IMODI_MASK                                 (0x0000ffffU)
#define XHCI_USB_IMOD_IMODI_DIS                                   (0U)
#define XHCI_USB_IMOD_IMODI_250NS                                 (1U)
#define XHCI_USB_IMOD_IMODI_1MS1                                  (4000U)

#define XHCI_USB_IMOD_IMODC_SHIFT                                (16U)
#define XHCI_USB_IMOD_IMODC_MASK                                 (0xffff0000U)

#define XHCI_USB_ERSTSZ_ERS_TBL_SIZE_SHIFT                       (0U)
#define XHCI_USB_ERSTSZ_ERS_TBL_SIZE_MASK                        (0x0000ffffU)

#define XHCI_USB_ERSTBA_LO_ERS_TBL_BAR_SHIFT                     (6U)
#define XHCI_USB_ERSTBA_LO_ERS_TBL_BAR_MASK                      (0xffffffc0U)

#define XHCI_USB_ERSTBA_HI_ERS_TBL_BAR_SHIFT                     (0U)
#define XHCI_USB_ERSTBA_HI_ERS_TBL_BAR_MASK                      (0xffffffffU)

#define XHCI_USB_ERDP_LO_DESI_SHIFT                              (0U)
#define XHCI_USB_ERDP_LO_DESI_MASK                               (0x00000007U)

#define XHCI_USB_ERDP_LO_EHB_SHIFT                               (3U)
#define XHCI_USB_ERDP_LO_EHB_MASK                                (0x00000008U)

#define XHCI_USB_ERDP_LO_ERD_PNTR_SHIFT                          (4U)
#define XHCI_USB_ERDP_LO_ERD_PNTR_MASK                           (0xfffffff0U)

#define XHCI_USB_ERDP_HI_ERD_PNTR_SHIFT                          (0U)
#define XHCI_USB_ERDP_HI_ERD_PNTR_MASK                           (0xffffffffU)

#define XHCI_USB_DB_DB_TARGET_SHIFT                              (0U)
#define XHCI_USB_DB_DB_TARGET_MASK                               (0x000000ffU)

#define XHCI_USB_DB_DB_STREAM_ID_SHIFT                           (16U)
#define XHCI_USB_DB_DB_STREAM_ID_MASK                            (0xffff0000U)

#define XHCI_USB_USBLEGSUP_ECID_SHIFT                            (0U)
#define XHCI_USB_USBLEGSUP_ECID_MASK                             (0x000000ffU)
#define XHCI_USB_USBLEGSUP_ECID_LEGACY                            (1U)
#define XHCI_USB_USBLEGSUP_ECID_PROT                              (2U)
#define XHCI_USB_USBLEGSUP_ECID_DBC                               (10U)

#define XHCI_USB_USBLEGSUP_NCP_SHIFT                             (8U)
#define XHCI_USB_USBLEGSUP_NCP_MASK                              (0x0000ff00U)
#define XHCI_USB_USBLEGSUP_NCP_EOL                                (0U)

#define XHCI_USB_USBLEGSUP_HCBOS_SHIFT                           (16U)
#define XHCI_USB_USBLEGSUP_HCBOS_MASK                            (0x00010000U)

#define XHCI_USB_USBLEGSUP_HCOOS_SHIFT                           (24U)
#define XHCI_USB_USBLEGSUP_HCOOS_MASK                            (0x01000000U)

#define XHCI_USB_USBLEGCTLSTS_USE_SHIFT                          (0U)
#define XHCI_USB_USBLEGCTLSTS_USE_MASK                           (0x00000001U)

#define XHCI_USB_USBLEGCTLSTS_SHSEE_SHIFT                        (4U)
#define XHCI_USB_USBLEGCTLSTS_SHSEE_MASK                         (0x00000010U)

#define XHCI_USB_USBLEGCTLSTS_SOOE_SHIFT                         (13U)
#define XHCI_USB_USBLEGCTLSTS_SOOE_MASK                          (0x00002000U)

#define XHCI_USB_USBLEGCTLSTS_SPCE_SHIFT                         (14U)
#define XHCI_USB_USBLEGCTLSTS_SPCE_MASK                          (0x00004000U)

#define XHCI_USB_USBLEGCTLSTS_SBE_SHIFT                          (15U)
#define XHCI_USB_USBLEGCTLSTS_SBE_MASK                           (0x00008000U)

#define XHCI_USB_USBLEGCTLSTS_SEI_SHIFT                          (16U)
#define XHCI_USB_USBLEGCTLSTS_SEI_MASK                           (0x00010000U)

#define XHCI_USB_USBLEGCTLSTS_SHSE_SHIFT                         (20U)
#define XHCI_USB_USBLEGCTLSTS_SHSE_MASK                          (0x00100000U)

#define XHCI_USB_USBLEGCTLSTS_SOOC_SHIFT                         (29U)
#define XHCI_USB_USBLEGCTLSTS_SOOC_MASK                          (0x20000000U)

#define XHCI_USB_USBLEGCTLSTS_SPC_SHIFT                          (30U)
#define XHCI_USB_USBLEGCTLSTS_SPC_MASK                           (0x40000000U)

#define XHCI_USB_USBLEGCTLSTS_SB_SHIFT                           (31U)
#define XHCI_USB_USBLEGCTLSTS_SB_MASK                            (0x80000000U)

#define XHCI_USB_SUPTPRT2_DW0_ECID_SHIFT                         (0U)
#define XHCI_USB_SUPTPRT2_DW0_ECID_MASK                          (0x000000ffU)
#define XHCI_USB_SUPTPRT2_DW0_ECID_LEGACY                         (1U)
#define XHCI_USB_SUPTPRT2_DW0_ECID_PROT                           (2U)
#define XHCI_USB_SUPTPRT2_DW0_ECID_DBC                            (10U)

#define XHCI_USB_SUPTPRT2_DW0_NCP_SHIFT                          (8U)
#define XHCI_USB_SUPTPRT2_DW0_NCP_MASK                           (0x0000ff00U)
#define XHCI_USB_SUPTPRT2_DW0_NCP_EOL                             (0U)

#define XHCI_USB_SUPTPRT2_DW0_MINREV_SHIFT                       (16U)
#define XHCI_USB_SUPTPRT2_DW0_MINREV_MASK                        (0x00ff0000U)

#define XHCI_USB_SUPTPRT2_DW0_MAJREV_SHIFT                       (24U)
#define XHCI_USB_SUPTPRT2_DW0_MAJREV_MASK                        (0xff000000U)

#define XHCI_USB_SUPTPRT2_DW1_CHAR0_SHIFT                        (0U)
#define XHCI_USB_SUPTPRT2_DW1_CHAR0_MASK                         (0x000000ffU)

#define XHCI_USB_SUPTPRT2_DW1_CHAR1_SHIFT                        (8U)
#define XHCI_USB_SUPTPRT2_DW1_CHAR1_MASK                         (0x0000ff00U)

#define XHCI_USB_SUPTPRT2_DW1_CHAR2_SHIFT                        (16U)
#define XHCI_USB_SUPTPRT2_DW1_CHAR2_MASK                         (0x00ff0000U)

#define XHCI_USB_SUPTPRT2_DW1_CHAR3_SHIFT                        (24U)
#define XHCI_USB_SUPTPRT2_DW1_CHAR3_MASK                         (0xff000000U)

#define XHCI_USB_SUPTPRT2_DW2_CPO_SHIFT                          (0U)
#define XHCI_USB_SUPTPRT2_DW2_CPO_MASK                           (0x000000ffU)

#define XHCI_USB_SUPTPRT2_DW2_CPC_SHIFT                          (8U)
#define XHCI_USB_SUPTPRT2_DW2_CPC_MASK                           (0x0000ff00U)

#define XHCI_USB_SUPTPRT2_DW2_PSIC_SHIFT                         (28U)
#define XHCI_USB_SUPTPRT2_DW2_PSIC_MASK                          (0xf0000000U)
#define XHCI_USB_SUPTPRT2_DW2_PSIC_ALL                            (0U)

#define XHCI_USB_SUPTPRT2_DW2_HSO_SHIFT                          (17U)
#define XHCI_USB_SUPTPRT2_DW2_HSO_MASK                           (0x00020000U)

#define XHCI_USB_SUPTPRT2_DW2_IHI_SHIFT                          (18U)
#define XHCI_USB_SUPTPRT2_DW2_IHI_MASK                           (0x00040000U)

#define XHCI_USB_SUPTPRT2_DW2_HLC_SHIFT                          (19U)
#define XHCI_USB_SUPTPRT2_DW2_HLC_MASK                           (0x00080000U)

#define XHCI_USB_SUPTPRT2_DW2_BESLD_SHIFT                        (20U)
#define XHCI_USB_SUPTPRT2_DW2_BESLD_MASK                         (0x00100000U)

#define XHCI_USB_SUPTPRT2_DW3_PST_SHIFT                          (0U)
#define XHCI_USB_SUPTPRT2_DW3_PST_MASK                           (0x0000001fU)

#define XHCI_USB_SUPTPRT3_DW0_ECID_SHIFT                         (0U)
#define XHCI_USB_SUPTPRT3_DW0_ECID_MASK                          (0x000000ffU)
#define XHCI_USB_SUPTPRT3_DW0_ECID_LEGACY                         (1U)
#define XHCI_USB_SUPTPRT3_DW0_ECID_PROT                           (2U)
#define XHCI_USB_SUPTPRT3_DW0_ECID_DBC                            (10U)

#define XHCI_USB_SUPTPRT3_DW0_MINREV_SHIFT                       (16U)
#define XHCI_USB_SUPTPRT3_DW0_MINREV_MASK                        (0x00ff0000U)

#define XHCI_USB_SUPTPRT3_DW0_MAJREV_SHIFT                       (24U)
#define XHCI_USB_SUPTPRT3_DW0_MAJREV_MASK                        (0xff000000U)

#define XHCI_USB_SUPTPRT3_DW0_NCP_SHIFT                          (8U)
#define XHCI_USB_SUPTPRT3_DW0_NCP_MASK                           (0x0000ff00U)
#define XHCI_USB_SUPTPRT3_DW0_NCP_EOL                             (0U)

#define XHCI_USB_SUPTPRT3_DW1_CHAR0_SHIFT                        (0U)
#define XHCI_USB_SUPTPRT3_DW1_CHAR0_MASK                         (0x000000ffU)

#define XHCI_USB_SUPTPRT3_DW1_CHAR1_SHIFT                        (8U)
#define XHCI_USB_SUPTPRT3_DW1_CHAR1_MASK                         (0x0000ff00U)

#define XHCI_USB_SUPTPRT3_DW1_CHAR2_SHIFT                        (16U)
#define XHCI_USB_SUPTPRT3_DW1_CHAR2_MASK                         (0x00ff0000U)

#define XHCI_USB_SUPTPRT3_DW1_CHAR3_SHIFT                        (24U)
#define XHCI_USB_SUPTPRT3_DW1_CHAR3_MASK                         (0xff000000U)

#define XHCI_USB_SUPTPRT3_DW2_CPO_SHIFT                          (0U)
#define XHCI_USB_SUPTPRT3_DW2_CPO_MASK                           (0x000000ffU)

#define XHCI_USB_SUPTPRT3_DW2_CPC_SHIFT                          (8U)
#define XHCI_USB_SUPTPRT3_DW2_CPC_MASK                           (0x0000ff00U)

#define XHCI_USB_SUPTPRT3_DW2_PSIC_SHIFT                         (28U)
#define XHCI_USB_SUPTPRT3_DW2_PSIC_MASK                          (0xf0000000U)
#define XHCI_USB_SUPTPRT3_DW2_PSIC_SS                             (0U)

#define XHCI_USB_SUPTPRT3_DW3_PST_SHIFT                          (0U)
#define XHCI_USB_SUPTPRT3_DW3_PST_MASK                           (0x0000001fU)

#define XHCI_USB_DCID_DCERSTMAX_SHIFT                            (16U)
#define XHCI_USB_DCID_DCERSTMAX_MASK                             (0x001f0000U)
#define XHCI_USB_DCID_DCERSTMAX_MIN                               (0U)
#define XHCI_USB_DCID_DCERSTMAX_MAX                               (15U)

#define XHCI_USB_DCID_NCP_SHIFT                                  (8U)
#define XHCI_USB_DCID_NCP_MASK                                   (0x0000ff00U)
#define XHCI_USB_DCID_NCP_EOL                                     (0U)

#define XHCI_USB_DCID_ECID_SHIFT                                 (0U)
#define XHCI_USB_DCID_ECID_MASK                                  (0x000000ffU)
#define XHCI_USB_DCID_ECID_LEGACY                                 (1U)
#define XHCI_USB_DCID_ECID_PROT                                   (2U)
#define XHCI_USB_DCID_ECID_DBC                                    (10U)

#define XHCI_USB_DCDB_DBTARGET_SHIFT                             (8U)
#define XHCI_USB_DCDB_DBTARGET_MASK                              (0x0000ff00U)
#define XHCI_USB_DCDB_DBTARGET_OUT                                (0U)
#define XHCI_USB_DCDB_DBTARGET_IN                                 (1U)

#define XHCI_USB_DCERSTSZ_TBLSIZE_SHIFT                          (0U)
#define XHCI_USB_DCERSTSZ_TBLSIZE_MASK                           (0x0000ffffU)

#define XHCI_USB_DCERSTBA_LO_BASEADDR_SHIFT                      (4U)
#define XHCI_USB_DCERSTBA_LO_BASEADDR_MASK                       (0xfffffff0U)

#define XHCI_USB_DCERSTBA_HI_BASEADDR_SHIFT                      (0U)
#define XHCI_USB_DCERSTBA_HI_BASEADDR_MASK                       (0xffffffffU)

#define XHCI_USB_DCERDP_LO_DEQUEUEPOINTER_SHIFT                  (4U)
#define XHCI_USB_DCERDP_LO_DEQUEUEPOINTER_MASK                   (0xfffffff0U)

#define XHCI_USB_DCERDP_LO_DESI_SHIFT                            (0U)
#define XHCI_USB_DCERDP_LO_DESI_MASK                             (0x00000007U)

#define XHCI_USB_DCERDP_HI_DEQUEUEPOINTER_SHIFT                  (0U)
#define XHCI_USB_DCERDP_HI_DEQUEUEPOINTER_MASK                   (0xffffffffU)

#define XHCI_USB_DCCTRL_DCR_SHIFT                                (0U)
#define XHCI_USB_DCCTRL_DCR_MASK                                 (0x00000001U)

#define XHCI_USB_DCCTRL_LSE_SHIFT                                (1U)
#define XHCI_USB_DCCTRL_LSE_MASK                                 (0x00000002U)
#define XHCI_USB_DCCTRL_LSE_DISABLED                              (0U)
#define XHCI_USB_DCCTRL_LSE_ENABLED                               (1U)

#define XHCI_USB_DCCTRL_HOT_SHIFT                                (2U)
#define XHCI_USB_DCCTRL_HOT_MASK                                 (0x00000004U)

#define XHCI_USB_DCCTRL_HIT_SHIFT                                (3U)
#define XHCI_USB_DCCTRL_HIT_MASK                                 (0x00000008U)

#define XHCI_USB_DCCTRL_DBG_MAX_BURST_SIZE_SHIFT                 (16U)
#define XHCI_USB_DCCTRL_DBG_MAX_BURST_SIZE_MASK                  (0x00ff0000U)

#define XHCI_USB_DCCTRL_DEVICE_ADDR_SHIFT                        (24U)
#define XHCI_USB_DCCTRL_DEVICE_ADDR_MASK                         (0x7f000000U)

#define XHCI_USB_DCCTRL_DCE_SHIFT                                (31U)
#define XHCI_USB_DCCTRL_DCE_MASK                                 (0x80000000U)
#define XHCI_USB_DCCTRL_DCE_DISABLED                              (0U)
#define XHCI_USB_DCCTRL_DCE_ENABLED                               (1U)

#define XHCI_USB_DCCTRL_DRC_SHIFT                                (4U)
#define XHCI_USB_DCCTRL_DRC_MASK                                 (0x00000010U)

#define XHCI_USB_DCST_ER_SHIFT                                   (0U)
#define XHCI_USB_DCST_ER_MASK                                    (0x00000001U)

#define XHCI_USB_DCST_DBG_PORT_NUMBER_SHIFT                      (24U)
#define XHCI_USB_DCST_DBG_PORT_NUMBER_MASK                       (0xff000000U)

#define XHCI_USB_DCPORTSC_CCS_SHIFT                              (0U)
#define XHCI_USB_DCPORTSC_CCS_MASK                               (0x00000001U)

#define XHCI_USB_DCPORTSC_PED_SHIFT                              (1U)
#define XHCI_USB_DCPORTSC_PED_MASK                               (0x00000002U)

#define XHCI_USB_DCPORTSC_PR_SHIFT                               (4U)
#define XHCI_USB_DCPORTSC_PR_MASK                                (0x00000010U)

#define XHCI_USB_DCPORTSC_PLS_SHIFT                              (5U)
#define XHCI_USB_DCPORTSC_PLS_MASK                               (0x000001e0U)
#define XHCI_USB_DCPORTSC_PLS_U0                                  (0U)
#define XHCI_USB_DCPORTSC_PLS_U1                                  (1U)
#define XHCI_USB_DCPORTSC_PLS_U2                                  (2U)
#define XHCI_USB_DCPORTSC_PLS_U3                                  (3U)
#define XHCI_USB_DCPORTSC_PLS_DISABLED                            (4U)
#define XHCI_USB_DCPORTSC_PLS_RXDETECT                            (5U)
#define XHCI_USB_DCPORTSC_PLS_INACTIVE                            (6U)
#define XHCI_USB_DCPORTSC_PLS_POLLING                             (7U)
#define XHCI_USB_DCPORTSC_PLS_RECOVERY                            (8U)
#define XHCI_USB_DCPORTSC_PLS_HOTRESET                            (9U)

#define XHCI_USB_DCPORTSC_PORTSPEED_SHIFT                        (10U)
#define XHCI_USB_DCPORTSC_PORTSPEED_MASK                         (0x00003c00U)

#define XHCI_USB_DCPORTSC_CSC_SHIFT                              (17U)
#define XHCI_USB_DCPORTSC_CSC_MASK                               (0x00020000U)

#define XHCI_USB_DCPORTSC_PRC_SHIFT                              (21U)
#define XHCI_USB_DCPORTSC_PRC_MASK                               (0x00200000U)

#define XHCI_USB_DCPORTSC_PLC_SHIFT                              (22U)
#define XHCI_USB_DCPORTSC_PLC_MASK                               (0x00400000U)

#define XHCI_USB_DCPORTSC_CEC_SHIFT                              (23U)
#define XHCI_USB_DCPORTSC_CEC_MASK                               (0x00800000U)

#define XHCI_USB_DCCP_LO_CONTEXTPOINTER_SHIFT                    (4U)
#define XHCI_USB_DCCP_LO_CONTEXTPOINTER_MASK                     (0xfffffff0U)

#define XHCI_USB_DCCP_HI_CONTEXTPOINTER_SHIFT                    (0U)
#define XHCI_USB_DCCP_HI_CONTEXTPOINTER_MASK                     (0xffffffffU)

#define XHCI_USB_DCDDI1_DBCPROTOCOL_SHIFT                        (0U)
#define XHCI_USB_DCDDI1_DBCPROTOCOL_MASK                         (0x000000ffU)

#define XHCI_USB_DCDDI1_VENDORID_SHIFT                           (16U)
#define XHCI_USB_DCDDI1_VENDORID_MASK                            (0xffff0000U)

#define XHCI_USB_DCDDI2_PRODUCTID_SHIFT                          (0U)
#define XHCI_USB_DCDDI2_PRODUCTID_MASK                           (0x0000ffffU)

#define XHCI_USB_DCDDI2_DEVICEREVISION_SHIFT                     (16U)
#define XHCI_USB_DCDDI2_DEVICEREVISION_MASK                      (0xffff0000U)


#ifdef __cplusplus
}
#endif
#endif /* PDK__HW_XHCI_USB_H */
