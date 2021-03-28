/*
* hw_icss_mii_mdio.h
*
* Register-level header file for HW_ICSS_MII_MDIO
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*
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
#ifndef HW_ICSS_MII_MDIO_H_
#define HW_ICSS_MII_MDIO_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_MII_MDIO_VER                                   (0x0U)
#define HW_ICSS_MII_MDIO_CONTROL                               (0x4U)
#define HW_ICSS_MII_MDIO_ALIVE                                 (0x8U)
#define HW_ICSS_MII_MDIO_LINK                                  (0xcU)
#define HW_ICSS_MII_MDIO_LINKINTRAW                            (0x10U)
#define HW_ICSS_MII_MDIO_LINKINTMASKED                         (0x14U)
#define HW_ICSS_MII_MDIO_USERINTRAW                            (0x20U)
#define HW_ICSS_MII_MDIO_USERINTMASKED                         (0x24U)
#define HW_ICSS_MII_MDIO_USERINTMASKSET                        (0x28U)
#define HW_ICSS_MII_MDIO_USERINTMASKCLR                        (0x2cU)
#define HW_ICSS_MII_MDIO_USERACCESS0                           (0x80U)
#define HW_ICSS_MII_MDIO_USERPHYSEL0                           (0x84U)
#define HW_ICSS_MII_MDIO_USERACCESS1                           (0x88U)
#define HW_ICSS_MII_MDIO_USERPHYSEL1                           (0x8cU)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_MII_MDIO_VER_REVMIN_SHIFT                      (0U)
#define HW_ICSS_MII_MDIO_VER_REVMIN_MASK                       (0x000000ffU)

#define HW_ICSS_MII_MDIO_VER_REVMAJ_SHIFT                      (8U)
#define HW_ICSS_MII_MDIO_VER_REVMAJ_MASK                       (0x0000ff00U)

#define HW_ICSS_MII_MDIO_VER_MODID_SHIFT                       (16U)
#define HW_ICSS_MII_MDIO_VER_MODID_MASK                        (0xffff0000U)

#define HW_ICSS_MII_MDIO_CONTROL_CLKDIV_SHIFT                  (0U)
#define HW_ICSS_MII_MDIO_CONTROL_CLKDIV_MASK                   (0x0000ffffU)

#define HW_ICSS_MII_MDIO_CONTROL_INT_TEST_ENABLE_SHIFT         (17U)
#define HW_ICSS_MII_MDIO_CONTROL_INT_TEST_ENABLE_MASK          (0x00020000U)

#define HW_ICSS_MII_MDIO_CONTROL_FAULT_DETECT_ENABLE_SHIFT     (18U)
#define HW_ICSS_MII_MDIO_CONTROL_FAULT_DETECT_ENABLE_MASK      (0x00040000U)

#define HW_ICSS_MII_MDIO_CONTROL_FAULT_SHIFT                   (19U)
#define HW_ICSS_MII_MDIO_CONTROL_FAULT_MASK                    (0x00080000U)

#define HW_ICSS_MII_MDIO_CONTROL_PREAMBLE_SHIFT                (20U)
#define HW_ICSS_MII_MDIO_CONTROL_PREAMBLE_MASK                 (0x00100000U)

#define HW_ICSS_MII_MDIO_CONTROL_HIGHEST_USER_CHANNEL_SHIFT    (24U)
#define HW_ICSS_MII_MDIO_CONTROL_HIGHEST_USER_CHANNEL_MASK     (0x1f000000U)

#define HW_ICSS_MII_MDIO_CONTROL_ENABLE_SHIFT                  (30U)
#define HW_ICSS_MII_MDIO_CONTROL_ENABLE_MASK                   (0x40000000U)

#define HW_ICSS_MII_MDIO_CONTROL_IDLE_SHIFT                    (31U)
#define HW_ICSS_MII_MDIO_CONTROL_IDLE_MASK                     (0x80000000U)

#define HW_ICSS_MII_MDIO_ALIVE_SHIFT                           (0U)
#define HW_ICSS_MII_MDIO_ALIVE_MASK                            (0xffffffffU)

#define HW_ICSS_MII_MDIO_LINK_SHIFT                            (0U)
#define HW_ICSS_MII_MDIO_LINK_MASK                             (0xffffffffU)

#define HW_ICSS_MII_MDIO_LINKINTRAW_SHIFT                      (0U)
#define HW_ICSS_MII_MDIO_LINKINTRAW_MASK                       (0x00000003U)

#define HW_ICSS_MII_MDIO_LINKINTMASKED_SHIFT                   (0U)
#define HW_ICSS_MII_MDIO_LINKINTMASKED_MASK                    (0x00000003U)

#define HW_ICSS_MII_MDIO_USERINTRAW_SHIFT                      (0U)
#define HW_ICSS_MII_MDIO_USERINTRAW_MASK                       (0x00000003U)

#define HW_ICSS_MII_MDIO_USERINTMASKED_SHIFT                   (0U)
#define HW_ICSS_MII_MDIO_USERINTMASKED_MASK                    (0x00000003U)

#define HW_ICSS_MII_MDIO_USERINTMASKSET_USERINTMASKEDSET_SHIFT  (0U)
#define HW_ICSS_MII_MDIO_USERINTMASKSET_USERINTMASKEDSET_MASK  (0x00000003U)

#define HW_ICSS_MII_MDIO_USERINTMASKCLR_USERINTMASKEDCLR_SHIFT  (0U)
#define HW_ICSS_MII_MDIO_USERINTMASKCLR_USERINTMASKEDCLR_MASK  (0x00000003U)

#define HW_ICSS_MII_MDIO_USERACCESS0_DATA_SHIFT                (0U)
#define HW_ICSS_MII_MDIO_USERACCESS0_DATA_MASK                 (0x0000ffffU)

#define HW_ICSS_MII_MDIO_USERACCESS0_PHYADR_SHIFT              (16U)
#define HW_ICSS_MII_MDIO_USERACCESS0_PHYADR_MASK               (0x001f0000U)

#define HW_ICSS_MII_MDIO_USERACCESS0_REGADR_SHIFT              (21U)
#define HW_ICSS_MII_MDIO_USERACCESS0_REGADR_MASK               (0x03e00000U)

#define HW_ICSS_MII_MDIO_USERACCESS0_ACK_SHIFT                 (29U)
#define HW_ICSS_MII_MDIO_USERACCESS0_ACK_MASK                  (0x20000000U)

#define HW_ICSS_MII_MDIO_USERACCESS0_WRITE_SHIFT               (30U)
#define HW_ICSS_MII_MDIO_USERACCESS0_WRITE_MASK                (0x40000000U)

#define HW_ICSS_MII_MDIO_USERACCESS0_GO_SHIFT                  (31U)
#define HW_ICSS_MII_MDIO_USERACCESS0_GO_MASK                   (0x80000000U)

#define HW_ICSS_MII_MDIO_USERPHYSEL0_PHYADR_MON_SHIFT          (0U)
#define HW_ICSS_MII_MDIO_USERPHYSEL0_PHYADR_MON_MASK           (0x0000001fU)

#define HW_ICSS_MII_MDIO_USERPHYSEL0_LINKINT_ENABLE_SHIFT      (6U)
#define HW_ICSS_MII_MDIO_USERPHYSEL0_LINKINT_ENABLE_MASK       (0x00000040U)

#define HW_ICSS_MII_MDIO_USERPHYSEL0_LINKSEL_SHIFT             (7U)
#define HW_ICSS_MII_MDIO_USERPHYSEL0_LINKSEL_MASK              (0x00000080U)

#define HW_ICSS_MII_MDIO_USERACCESS1_DATA_SHIFT                (0U)
#define HW_ICSS_MII_MDIO_USERACCESS1_DATA_MASK                 (0x0000ffffU)

#define HW_ICSS_MII_MDIO_USERACCESS1_PHYADR_SHIFT              (16U)
#define HW_ICSS_MII_MDIO_USERACCESS1_PHYADR_MASK               (0x001f0000U)

#define HW_ICSS_MII_MDIO_USERACCESS1_REGADR_SHIFT              (21U)
#define HW_ICSS_MII_MDIO_USERACCESS1_REGADR_MASK               (0x03e00000U)

#define HW_ICSS_MII_MDIO_USERACCESS1_ACK_SHIFT                 (29U)
#define HW_ICSS_MII_MDIO_USERACCESS1_ACK_MASK                  (0x20000000U)

#define HW_ICSS_MII_MDIO_USERACCESS1_WRITE_SHIFT               (30U)
#define HW_ICSS_MII_MDIO_USERACCESS1_WRITE_MASK                (0x40000000U)

#define HW_ICSS_MII_MDIO_USERACCESS1_GO_SHIFT                  (31U)
#define HW_ICSS_MII_MDIO_USERACCESS1_GO_MASK                   (0x80000000U)

#define HW_ICSS_MII_MDIO_USERPHYSEL1_PHYADR_MON_SHIFT          (0U)
#define HW_ICSS_MII_MDIO_USERPHYSEL1_PHYADR_MON_MASK           (0x0000001fU)

#define HW_ICSS_MII_MDIO_USERPHYSEL1_LINKINT_ENABLE_SHIFT      (6U)
#define HW_ICSS_MII_MDIO_USERPHYSEL1_LINKINT_ENABLE_MASK       (0x00000040U)

#define HW_ICSS_MII_MDIO_USERPHYSEL1_LINKSEL_SHIFT             (7U)
#define HW_ICSS_MII_MDIO_USERPHYSEL1_LINKSEL_MASK              (0x00000080U)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_MII_MDIO_H_ */
