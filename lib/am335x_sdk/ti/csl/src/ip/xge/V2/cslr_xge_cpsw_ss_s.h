/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_XGE_CPSW_SS_S_H_
#define CSLR_XGE_CPSW_SS_S_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 IDVER_REG;
    volatile Uint32 SYNCE_COUNT_REG;
    volatile Uint32 SYNCE_MUX_REG;
    volatile Uint32 CONTROL_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 RGMII_STATUS_REG;
    volatile Uint32 SUBSSYSTEM_STATUS_REG;
} CSL_Xge_cpsw_ss_sRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IDVER_REG */
#define CSL_XGE_CPSW_SS_S_IDVER_REG                             (0x0U)

/* SYNCE_COUNT_REG */
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG                       (0x4U)

/* SYNCE_MUX_REG */
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG                         (0x8U)

/* CONTROL_REG */
#define CSL_XGE_CPSW_SS_S_CONTROL_REG                           (0xCU)

/* RGMII_STATUS_REG */
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG                      (0x18U)

/* SUBSSYSTEM_STATUS_REG */
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG                 (0x1CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER_REG */

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_MASK              (0x000000FFU)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_SHIFT             (0U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_MAX               (0x000000ffU)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_MASK              (0x00000700U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_SHIFT             (8U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_RESETVAL          (0x00000000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_MAX               (0x00000007U)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_MASK                (0x0000F800U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_SHIFT               (11U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_RESETVAL            (0x00000000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_MAX                 (0x0000001fU)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_MASK                  (0xFFFF0000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_SHIFT                 (16U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_RESETVAL              (0x00000000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_MAX                   (0x0000ffffU)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_RESETVAL                    (0x00000000U)

/* SYNCE_COUNT_REG */

#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_MASK        (0xFFFFFFFFU)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_SHIFT       (0U)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_RESETVAL    (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_MAX         (0xffffffffU)

#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_RESETVAL              (0x00000000U)

/* SYNCE_MUX_REG */

#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_MASK          (0x00000007U)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_SHIFT         (0U)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_RESETVAL      (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_MAX           (0x00000007U)

#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_RESETVAL                (0x00000000U)

/* CONTROL_REG */

#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_MASK               (0x00000001U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_SHIFT              (0U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_RESETVAL           (0x00000000U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_MAX                (0x00000001U)

#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_MASK         (0x00000002U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_SHIFT        (1U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_RESETVAL     (0x00000000U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_MAX          (0x00000001U)

#define CSL_XGE_CPSW_SS_S_CONTROL_REG_RESETVAL                  (0x00000000U)

/* RGMII_STATUS_REG */

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_MASK            (0x00000001U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_SHIFT           (0U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_RESETVAL        (0x00000000U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_MAX             (0x00000001U)

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_MASK           (0x00000006U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_SHIFT          (1U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_RESETVAL       (0x00000000U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_MAX            (0x00000003U)

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_MASK      (0x00000008U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_SHIFT     (3U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_MAX       (0x00000001U)

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_RESETVAL             (0x00000000U)

/* SUBSSYSTEM_STATUS_REG */

#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MASK  (0x00000001U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_SHIFT  (0U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_RESETVAL  (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MAX  (0x00000001U)

#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_RESETVAL        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
