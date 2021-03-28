/*
 *  Copyright (C) 2008-2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_ctrl_wkup_pad.h
 *
 *  \brief  register-level header file for CTRL_WKUP
 *
**/
#ifndef HW_CTRL_WKUP_PAD_H_
#define HW_CTRL_WKUP_PAD_H_

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR                                                                  (0x4U)
#define CTRL_WKUP_CONTROL_CKOBUFFER                                                                        (0xcU)
#define CTRL_WKUP_EFUSE_1                                                                                  (0x20U)
#define CTRL_WKUP_EFUSE_2                                                                                  (0x24U)
#define CTRL_WKUP_EFUSE_3                                                                                  (0x28U)
#define CTRL_WKUP_EFUSE_4                                                                                  (0x2cU)
#define CTRL_WKUP_EFUSE_13                                                                                 (0x50U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_BOOST_SHIFT                                         (31U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_BOOST_MASK                                          (0x80000000U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_BOOST_ENABLE                                        (1U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_BOOST_DISABLE                                       (0U)

#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_OS_OUT_SHIFT                                        (30U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_OS_OUT_MASK                                         (0x40000000U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_OS_OUT_DISABLE                                      (1U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR0_OS_OUT_ENABLE                                       (0U)

#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_BOOST_SHIFT                                         (29U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_BOOST_MASK                                          (0x20000000U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_BOOST_ENABLE                                        (1U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_BOOST_DISABLE                                       (0U)

#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_OS_OUT_SHIFT                                        (28U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_OS_OUT_MASK                                         (0x10000000U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_OS_OUT_DISABLE                                      (1U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_OSCILLATOR1_OS_OUT_ENABLE                                       (0U)

#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_RESERVED_0_SHIFT                                                (0U)
#define CTRL_WKUP_CONTROL_XTAL_OSCILLATOR_RESERVED_0_MASK                                                 (0x0fffffffU)

#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_OUT_EN_SHIFT                                                (31U)
#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_OUT_EN_MASK                                                 (0x80000000U)

#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_ALTSEL_SHIFT                                                (30U)
#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_ALTSEL_MASK                                                 (0x40000000U)

#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_POLARITY_SHIFT                                              (29U)
#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_POLARITY_MASK                                               (0x20000000U)

#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_CLK_EN_SHIFT                                                (28U)
#define CTRL_WKUP_CONTROL_CKOBUFFER_CKOBUFFER_CLK_EN_MASK                                                 (0x10000000U)

#define CTRL_WKUP_CONTROL_CKOBUFFER_RESERVED_0_SHIFT                                                      (0U)
#define CTRL_WKUP_CONTROL_CKOBUFFER_RESERVED_0_MASK                                                       (0x0fffffffU)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N5_SHIFT                                                 (31U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N5_MASK                                                  (0x80000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N4_SHIFT                                                 (30U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N4_MASK                                                  (0x40000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N3_SHIFT                                                 (29U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N3_MASK                                                  (0x20000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N2_SHIFT                                                 (28U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N2_MASK                                                  (0x10000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N1_SHIFT                                                 (27U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N1_MASK                                                  (0x08000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N0_SHIFT                                                 (26U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_N0_MASK                                                  (0x04000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P5_SHIFT                                                 (25U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P5_MASK                                                  (0x02000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P4_SHIFT                                                 (24U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P4_MASK                                                  (0x01000000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P3_SHIFT                                                 (23U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P3_MASK                                                  (0x00800000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P2_SHIFT                                                 (22U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P2_MASK                                                  (0x00400000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P1_SHIFT                                                 (21U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P1_MASK                                                  (0x00200000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P0_SHIFT                                                 (20U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_NORTH_SIDE_P0_MASK                                                  (0x00100000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N5_SHIFT                                                  (19U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N5_MASK                                                   (0x00080000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N4_SHIFT                                                  (18U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N4_MASK                                                   (0x00040000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N3_SHIFT                                                  (17U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N3_MASK                                                   (0x00020000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N2_SHIFT                                                  (16U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N2_MASK                                                   (0x00010000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N1_SHIFT                                                  (15U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N1_MASK                                                   (0x00008000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N0_SHIFT                                                  (14U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_N0_MASK                                                   (0x00004000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P5_SHIFT                                                  (13U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P5_MASK                                                   (0x00002000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P4_SHIFT                                                  (12U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P4_MASK                                                   (0x00001000U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P3_SHIFT                                                  (11U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P3_MASK                                                   (0x00000800U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P2_SHIFT                                                  (10U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P2_MASK                                                   (0x00000400U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P1_SHIFT                                                  (9U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P1_MASK                                                   (0x00000200U)

#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P0_SHIFT                                                  (8U)
#define CTRL_WKUP_EFUSE_1_DDRDIFF_PTV_EAST_SIDE_P0_MASK                                                   (0x00000100U)

#define CTRL_WKUP_EFUSE_1_RESERVED_0_SHIFT                                                                (0U)
#define CTRL_WKUP_EFUSE_1_RESERVED_0_MASK                                                                 (0x000000ffU)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N5_SHIFT                                                 (31U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N5_MASK                                                  (0x80000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N4_SHIFT                                                 (30U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N4_MASK                                                  (0x40000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N3_SHIFT                                                 (29U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N3_MASK                                                  (0x20000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N2_SHIFT                                                 (28U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N2_MASK                                                  (0x10000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N1_SHIFT                                                 (27U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N1_MASK                                                  (0x08000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N0_SHIFT                                                 (26U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_N0_MASK                                                  (0x04000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P5_SHIFT                                                 (25U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P5_MASK                                                  (0x02000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P4_SHIFT                                                 (24U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P4_MASK                                                  (0x01000000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P3_SHIFT                                                 (23U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P3_MASK                                                  (0x00800000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P2_SHIFT                                                 (22U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P2_MASK                                                  (0x00400000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P1_SHIFT                                                 (21U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P1_MASK                                                  (0x00200000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P0_SHIFT                                                 (20U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_SOUTH_SIDE_P0_MASK                                                  (0x00100000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N5_SHIFT                                                  (19U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N5_MASK                                                   (0x00080000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N4_SHIFT                                                  (18U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N4_MASK                                                   (0x00040000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N3_SHIFT                                                  (17U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N3_MASK                                                   (0x00020000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N2_SHIFT                                                  (16U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N2_MASK                                                   (0x00010000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N1_SHIFT                                                  (15U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N1_MASK                                                   (0x00008000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N0_SHIFT                                                  (14U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_N0_MASK                                                   (0x00004000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P5_SHIFT                                                  (13U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P5_MASK                                                   (0x00002000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P4_SHIFT                                                  (12U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P4_MASK                                                   (0x00001000U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P3_SHIFT                                                  (11U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P3_MASK                                                   (0x00000800U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P2_SHIFT                                                  (10U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P2_MASK                                                   (0x00000400U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P1_SHIFT                                                  (9U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P1_MASK                                                   (0x00000200U)

#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P0_SHIFT                                                  (8U)
#define CTRL_WKUP_EFUSE_2_DDRDIFF_PTV_WEST_SIDE_P0_MASK                                                   (0x00000100U)

#define CTRL_WKUP_EFUSE_2_RESERVED_0_SHIFT                                                                (0U)
#define CTRL_WKUP_EFUSE_2_RESERVED_0_MASK                                                                 (0x000000ffU)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N5_SHIFT                                                   (31U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N5_MASK                                                    (0x80000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N4_SHIFT                                                   (30U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N4_MASK                                                    (0x40000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N3_SHIFT                                                   (29U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N3_MASK                                                    (0x20000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N2_SHIFT                                                   (28U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N2_MASK                                                    (0x10000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N1_SHIFT                                                   (27U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N1_MASK                                                    (0x08000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N0_SHIFT                                                   (26U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_N0_MASK                                                    (0x04000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P5_SHIFT                                                   (25U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P5_MASK                                                    (0x02000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P4_SHIFT                                                   (24U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P4_MASK                                                    (0x01000000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P3_SHIFT                                                   (23U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P3_MASK                                                    (0x00800000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P2_SHIFT                                                   (22U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P2_MASK                                                    (0x00400000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P1_SHIFT                                                   (21U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P1_MASK                                                    (0x00200000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P0_SHIFT                                                   (20U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_NORTH_SIDE_P0_MASK                                                    (0x00100000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N5_SHIFT                                                    (19U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N5_MASK                                                     (0x00080000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N4_SHIFT                                                    (18U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N4_MASK                                                     (0x00040000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N3_SHIFT                                                    (17U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N3_MASK                                                     (0x00020000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N2_SHIFT                                                    (16U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N2_MASK                                                     (0x00010000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N1_SHIFT                                                    (15U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N1_MASK                                                     (0x00008000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N0_SHIFT                                                    (14U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_N0_MASK                                                     (0x00004000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P5_SHIFT                                                    (13U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P5_MASK                                                     (0x00002000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P4_SHIFT                                                    (12U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P4_MASK                                                     (0x00001000U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P3_SHIFT                                                    (11U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P3_MASK                                                     (0x00000800U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P2_SHIFT                                                    (10U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P2_MASK                                                     (0x00000400U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P1_SHIFT                                                    (9U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P1_MASK                                                     (0x00000200U)

#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P0_SHIFT                                                    (8U)
#define CTRL_WKUP_EFUSE_3_DDRSE_PTV_EAST_SIDE_P0_MASK                                                     (0x00000100U)

#define CTRL_WKUP_EFUSE_3_RESERVED_0_SHIFT                                                                (0U)
#define CTRL_WKUP_EFUSE_3_RESERVED_0_MASK                                                                 (0x000000ffU)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N5_SHIFT                                                   (31U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N5_MASK                                                    (0x80000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N4_SHIFT                                                   (30U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N4_MASK                                                    (0x40000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N3_SHIFT                                                   (29U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N3_MASK                                                    (0x20000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N2_SHIFT                                                   (28U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N2_MASK                                                    (0x10000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N1_SHIFT                                                   (27U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N1_MASK                                                    (0x08000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N0_SHIFT                                                   (26U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_N0_MASK                                                    (0x04000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P5_SHIFT                                                   (25U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P5_MASK                                                    (0x02000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P4_SHIFT                                                   (24U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P4_MASK                                                    (0x01000000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P3_SHIFT                                                   (23U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P3_MASK                                                    (0x00800000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P2_SHIFT                                                   (22U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P2_MASK                                                    (0x00400000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P1_SHIFT                                                   (21U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P1_MASK                                                    (0x00200000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P0_SHIFT                                                   (20U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_SOUTH_SIDE_P0_MASK                                                    (0x00100000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N5_SHIFT                                                    (19U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N5_MASK                                                     (0x00080000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N4_SHIFT                                                    (18U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N4_MASK                                                     (0x00040000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N3_SHIFT                                                    (17U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N3_MASK                                                     (0x00020000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N2_SHIFT                                                    (16U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N2_MASK                                                     (0x00010000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N1_SHIFT                                                    (15U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N1_MASK                                                     (0x00008000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N0_SHIFT                                                    (14U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_N0_MASK                                                     (0x00004000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P5_SHIFT                                                    (13U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P5_MASK                                                     (0x00002000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P4_SHIFT                                                    (12U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P4_MASK                                                     (0x00001000U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P3_SHIFT                                                    (11U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P3_MASK                                                     (0x00000800U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P2_SHIFT                                                    (10U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P2_MASK                                                     (0x00000400U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P1_SHIFT                                                    (9U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P1_MASK                                                     (0x00000200U)

#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P0_SHIFT                                                    (8U)
#define CTRL_WKUP_EFUSE_4_DDRSE_PTV_WEST_SIDE_P0_MASK                                                     (0x00000100U)

#define CTRL_WKUP_EFUSE_4_RESERVED_0_SHIFT                                                                (0U)
#define CTRL_WKUP_EFUSE_4_RESERVED_0_MASK                                                                 (0x000000ffU)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N5_SHIFT                                                          (31U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N5_MASK                                                           (0x80000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N4_SHIFT                                                          (30U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N4_MASK                                                           (0x40000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N3_SHIFT                                                          (29U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N3_MASK                                                           (0x20000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N2_SHIFT                                                          (28U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N2_MASK                                                           (0x10000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N1_SHIFT                                                          (27U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N1_MASK                                                           (0x08000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N0_SHIFT                                                          (26U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_N0_MASK                                                           (0x04000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P5_SHIFT                                                          (25U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P5_MASK                                                           (0x02000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P4_SHIFT                                                          (24U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P4_MASK                                                           (0x01000000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P3_SHIFT                                                          (23U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P3_MASK                                                           (0x00800000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P2_SHIFT                                                          (22U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P2_MASK                                                           (0x00400000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P1_SHIFT                                                          (21U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P1_MASK                                                           (0x00200000U)

#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P0_SHIFT                                                          (20U)
#define CTRL_WKUP_EFUSE_13_SDIO1833_PTV_P0_MASK                                                           (0x00100000U)

#define CTRL_WKUP_EFUSE_13_RESERVED_0_SHIFT                                                               (0U)
#define CTRL_WKUP_EFUSE_13_RESERVED_0_MASK                                                                (0x000fffffU)

#ifdef __cplusplus
}
#endif
#endif  /* _HW_CTRL_WKUP_PAD_H_ */
