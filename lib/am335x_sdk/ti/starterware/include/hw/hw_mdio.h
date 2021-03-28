/*
* hw_mdio.h
*
* Register-level header file for MDIO
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef HW_MDIO_H_
#define HW_MDIO_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define MDIO_USERINTMASKSET                                    (0x28U)
#define MDIO_USERINTRAW                                        (0x20U)
#define MDIO_USERPHYSEL(n)                                     (0x84U + ((n) * 0x8U))
#define MDIO_CTRL                                              (0x4U)
#define MDIO_LINKINTRAW                                        (0x10U)
#define MDIO_USERINTMASKED                                     (0x24U)
#define MDIO_LINK                                              (0xcU)
#define MDIO_ALIVE                                             (0x8U)
#define MDIO_VER                                               (0x0U)
#define MDIO_USERACCESS(n)                                     (0x80U + ((n) * 0x8U))
#define MDIO_LINKINTMASKED                                     (0x14U)
#define MDIO_USERINTMASKCLR                                    (0x2cU)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define MDIO_USERINTMASKSET_SHIFT                                                  (0U)
#define MDIO_USERINTMASKSET_MASK                                                   (0x00000003U)

#define MDIO_USERINTRAW_SHIFT                                                      (0U)
#define MDIO_USERINTRAW_MASK                                                       (0x00000003U)

#define MDIO_USERPHYSEL_PHYADDRMON_SHIFT                                           (0U)
#define MDIO_USERPHYSEL_PHYADDRMON_MASK                                            (0x0000001fU)

#define MDIO_USERPHYSEL_LINKINTENB_SHIFT                                           (6U)
#define MDIO_USERPHYSEL_LINKINTENB_MASK                                            (0x00000040U)
#define MDIO_USERPHYSEL_LINKINTENB_EN_0X1                                           (1U)
#define MDIO_USERPHYSEL_LINKINTENB_EN_0X0                                           (0U)

#define MDIO_USERPHYSEL_LINKSEL_SHIFT                                              (7U)
#define MDIO_USERPHYSEL_LINKSEL_MASK                                               (0x00000080U)

#define MDIO_CTRL_CLKDIV_SHIFT                                                     (0U)
#define MDIO_CTRL_CLKDIV_MASK                                                      (0x0000ffffU)

#define MDIO_CTRL_INTTESTENB_SHIFT                                                 (17U)
#define MDIO_CTRL_INTTESTENB_MASK                                                  (0x00020000U)
#define MDIO_CTRL_INTTESTENB_EN_0X1                                                 (1U)
#define MDIO_CTRL_INTTESTENB_EN_0X0                                                 (0U)

#define MDIO_CTRL_FAULTENB_SHIFT                                                   (18U)
#define MDIO_CTRL_FAULTENB_MASK                                                    (0x00040000U)
#define MDIO_CTRL_FAULTENB_EN_0X1                                                   (1U)
#define MDIO_CTRL_FAULTENB_EN_0X0                                                   (0U)

#define MDIO_CTRL_FAULT_SHIFT                                                      (19U)
#define MDIO_CTRL_FAULT_MASK                                                       (0x00080000U)
#define MDIO_CTRL_FAULT_EN_0X1                                                      (1U)
#define MDIO_CTRL_FAULT_EN_0X0                                                      (0U)

#define MDIO_CTRL_PREAMBLE_SHIFT                                                   (20U)
#define MDIO_CTRL_PREAMBLE_MASK                                                    (0x00100000U)
#define MDIO_CTRL_PREAMBLE_EN_0X0                                                   (0U)
#define MDIO_CTRL_PREAMBLE_EN_0X1                                                   (1U)

#define MDIO_CTRL_HIGHEST_USER_CHANNEL_SHIFT                                       (24U)
#define MDIO_CTRL_HIGHEST_USER_CHANNEL_MASK                                        (0x1f000000U)

#define MDIO_CTRL_EN_SHIFT                                                         (30U)
#define MDIO_CTRL_EN_MASK                                                          (0x40000000U)
#define MDIO_CTRL_EN_0X0                                                            (0U)
#define MDIO_CTRL_EN_0X1                                                            (1U)

#define MDIO_CTRL_IDLE_SHIFT                                                       (31U)
#define MDIO_CTRL_IDLE_MASK                                                        (0x80000000U)
#define MDIO_CTRL_IDLE_EN_0X0                                                       (0U)
#define MDIO_CTRL_IDLE_EN_0X1                                                       (1U)

#define MDIO_LINKINTRAW_SHIFT                                                      (0U)
#define MDIO_LINKINTRAW_MASK                                                       (0x00000003U)

#define MDIO_USERINTMASKED_SHIFT                                                   (0U)
#define MDIO_USERINTMASKED_MASK                                                    (0x00000003U)

#define MDIO_LINK_SHIFT                                                            (0U)
#define MDIO_LINK_MASK                                                             (0xffffffffU)

#define MDIO_ALIVE_SHIFT                                                           (0U)
#define MDIO_ALIVE_MASK                                                            (0xffffffffU)

#define MDIO_VER_REVMIN_SHIFT                                                      (0U)
#define MDIO_VER_REVMIN_MASK                                                       (0x000000ffU)

#define MDIO_VER_REVMAJ_SHIFT                                                      (8U)
#define MDIO_VER_REVMAJ_MASK                                                       (0x0000ff00U)

#define MDIO_VER_MODID_SHIFT                                                       (16U)
#define MDIO_VER_MODID_MASK                                                        (0xffff0000U)

#define MDIO_USERACCESS_DATA_SHIFT                                                 (0U)
#define MDIO_USERACCESS_DATA_MASK                                                  (0x0000ffffU)

#define MDIO_USERACCESS_PHYADR_SHIFT                                               (16U)
#define MDIO_USERACCESS_PHYADR_MASK                                                (0x001f0000U)

#define MDIO_USERACCESS_REGADR_SHIFT                                               (21U)
#define MDIO_USERACCESS_REGADR_MASK                                                (0x03e00000U)

#define MDIO_USERACCESS_ACK_SHIFT                                                  (29U)
#define MDIO_USERACCESS_ACK_MASK                                                   (0x20000000U)
#define MDIO_USERACCESS_ACK_PASS                                                    (1U)
#define MDIO_USERACCESS_ACK_FAIL                                                    (0U)

#define MDIO_USERACCESS_WRITE_SHIFT                                                (30U)
#define MDIO_USERACCESS_WRITE_MASK                                                 (0x40000000U)
#define MDIO_USERACCESS_WRITE                                                       (1U)
#define MDIO_USERACCESS_READ                                                        (0U)

#define MDIO_USERACCESS_GO_SHIFT                                                   (31U)
#define MDIO_USERACCESS_GO_MASK                                                    (0x80000000U)
#define MDIO_USERACCESS_GO_EN_0x1                                                   (1U)
#define MDIO_USERACCESS_GO_EN_0x0                                                   (0U)

#define MDIO_LINKINTMASKED_SHIFT                                                   (0U)
#define MDIO_LINKINTMASKED_MASK                                                    (0x00000003U)

#define MDIO_USERINTMASKCLR_SHIFT                                                  (0U)
#define MDIO_USERINTMASKCLR_MASK                                                   (0x00000003U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_MDIO_H_ */
