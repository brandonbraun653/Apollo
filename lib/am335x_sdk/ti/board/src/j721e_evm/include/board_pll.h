/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/
 
/**
 * \file   board_pll.h
 *
 * \brief  Board PLL configurations header file
 *
 * This file includes the structures, enums and register offsets
 * for PLL configurations
 *
 */

#ifndef BOARD_PLL_H
#define BOARD_PLL_H

#include "board_internal.h"
#include "board_pll.h"
#include "ti/csl/soc.h"
#include <ti/csl/hw_types.h>

#ifdef __cplusplus
extern "C" {
#endif

//Global definitions
#define DEBUG 	0 //turn on this for debugging messages

#define M3_MCU_OFFSET 		(0x20000000)
#define M3_MAIN_OFFSET 		(0x80000000)

#define KICK0_UNLOCK 	0x68EF3490
#define KICK1_UNLOCK 	0xD172BC5A
#define KICK_LOCK		0x00000000

#define MAIN_DOMAIN	0
#define MCU_DOMAIN	1

#define CENTER_SPREAD	0
#define DOWN_SPREAD		1

#define FRAC_PLL 		0
#define FRAC_F_PLL		1
#define DESKEW_PLL 		2

#define CSL_MAIN_PLL_MMR_CFG_PLL0_PID                                       (0x00000000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_MMR_CFG                                   (0x00000008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_LOCKKEY0                                  (0x00000010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_LOCKKEY1                                  (0x00000014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_CTRL                                      (0x00000020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_STAT                                      (0x00000024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_FREQ_CTRL0                                (0x00000030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_FREQ_CTRL1                                (0x00000034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_DIV_CTRL                                  (0x00000038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_SS_CTRL                                   (0x00000040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_SS_SPREAD                                 (0x00000044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL0                               (0x00000080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL1                               (0x00000084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL2                               (0x00000088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL3                               (0x0000008CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL4                               (0x00000090U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL5                               (0x00000094U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL6                               (0x00000098U)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL7                               (0x0000009CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL8                               (0x000000A0U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_PID                                       (0x00001000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_MMR_CFG                                   (0x00001008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_LOCKKEY0                                  (0x00001010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_LOCKKEY1                                  (0x00001014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_CTRL                                      (0x00001020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_STAT                                      (0x00001024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_FREQ_CTRL0                                (0x00001030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_FREQ_CTRL1                                (0x00001034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_DIV_CTRL                                  (0x00001038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_SS_CTRL                                   (0x00001040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_SS_SPREAD                                 (0x00001044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL0                               (0x00001080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL1                               (0x00001084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL2                               (0x00001088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL3                               (0x0000108CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL4                               (0x00001090U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL5                               (0x00001094U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL6                               (0x00001098U)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL7                               (0x0000109CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL1_HSDIV_CTRL8                               (0x000010A0U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_PID                                       (0x00002000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_MMR_CFG                                   (0x00002008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_LOCKKEY0                                  (0x00002010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_LOCKKEY1                                  (0x00002014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_CTRL                                      (0x00002020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_STAT                                      (0x00002024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_FREQ_CTRL0                                (0x00002030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_FREQ_CTRL1                                (0x00002034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_DIV_CTRL                                  (0x00002038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_SS_CTRL                                   (0x00002040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_SS_SPREAD                                 (0x00002044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL0                               (0x00002080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL1                               (0x00002084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL2                               (0x00002088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL3                               (0x0000208CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL4                               (0x00002090U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL5                               (0x00002094U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL6                               (0x00002098U)
#define CSL_MAIN_PLL_MMR_CFG_PLL2_HSDIV_CTRL7                               (0x0000209CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_PID                                       (0x00003000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_MMR_CFG                                   (0x00003008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_LOCKKEY0                                  (0x00003010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_LOCKKEY1                                  (0x00003014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_CTRL                                      (0x00003020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_STAT                                      (0x00003024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_FREQ_CTRL0                                (0x00003030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_FREQ_CTRL1                                (0x00003034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_DIV_CTRL                                  (0x00003038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_SS_CTRL                                   (0x00003040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_SS_SPREAD                                 (0x00003044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_HSDIV_CTRL0                               (0x00003080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_HSDIV_CTRL1                               (0x00003084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_HSDIV_CTRL2                               (0x00003088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_HSDIV_CTRL3                               (0x0000308CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL3_HSDIV_CTRL4                               (0x00003090U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_PID                                       (0x00004000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_MMR_CFG                                   (0x00004008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_LOCKKEY0                                  (0x00004010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_LOCKKEY1                                  (0x00004014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_CTRL                                      (0x00004020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_STAT                                      (0x00004024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_FREQ_CTRL0                                (0x00004030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_FREQ_CTRL1                                (0x00004034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_DIV_CTRL                                  (0x00004038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_SS_CTRL                                   (0x00004040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_SS_SPREAD                                 (0x00004044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_HSDIV_CTRL0                               (0x00004080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_HSDIV_CTRL1                               (0x00004084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_HSDIV_CTRL2                               (0x00004088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL4_HSDIV_CTRL3                               (0x0000408CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_PID                                       (0x00005000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_MMR_CFG                                   (0x00005008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_LOCKKEY0                                  (0x00005010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_LOCKKEY1                                  (0x00005014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_CTRL                                      (0x00005020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_STAT                                      (0x00005024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_FREQ_CTRL0                                (0x00005030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_FREQ_CTRL1                                (0x00005034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_DIV_CTRL                                  (0x00005038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_SS_CTRL                                   (0x00005040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_SS_SPREAD                                 (0x00005044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_HSDIV_CTRL0                               (0x00005080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_HSDIV_CTRL1                               (0x00005084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_HSDIV_CTRL2                               (0x00005088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL5_HSDIV_CTRL3                               (0x0000508CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_PID                                       (0x00006000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_MMR_CFG                                   (0x00006008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_LOCKKEY0                                  (0x00006010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_LOCKKEY1                                  (0x00006014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_CTRL                                      (0x00006020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_STAT                                      (0x00006024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_FREQ_CTRL0                                (0x00006030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_FREQ_CTRL1                                (0x00006034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_DIV_CTRL                                  (0x00006038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_SS_CTRL                                   (0x00006040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_SS_SPREAD                                 (0x00006044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL6_HSDIV_CTRL0                               (0x00006080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_PID                                       (0x00007000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_MMR_CFG                                   (0x00007008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_LOCKKEY0                                  (0x00007010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_LOCKKEY1                                  (0x00007014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_CTRL                                      (0x00007020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_STAT                                      (0x00007024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_FREQ_CTRL0                                (0x00007030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_FREQ_CTRL1                                (0x00007034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_DIV_CTRL                                  (0x00007038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_SS_CTRL                                   (0x00007040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_SS_SPREAD                                 (0x00007044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL7_HSDIV_CTRL0                               (0x00007080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_PID                                       (0x00008000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_MMR_CFG                                   (0x00008008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_LOCKKEY0                                  (0x00008010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_LOCKKEY1                                  (0x00008014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_CTRL                                      (0x00008020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_STAT                                      (0x00008024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_FREQ_CTRL0                                (0x00008030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_FREQ_CTRL1                                (0x00008034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_DIV_CTRL                                  (0x00008038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_SS_CTRL                                   (0x00008040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_SS_SPREAD                                 (0x00008044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL8_HSDIV_CTRL0                               (0x00008080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_PID                                       (0x00009000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_MMR_CFG                                   (0x00009008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_LOCKKEY0                                  (0x00009010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_LOCKKEY1                                  (0x00009014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_CTRL                                      (0x00009020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_STAT                                      (0x00009024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_FREQ_CTRL0                                (0x00009030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_FREQ_CTRL1                                (0x00009034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_DIV_CTRL                                  (0x00009038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_SS_CTRL                                   (0x00009040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_SS_SPREAD                                 (0x00009044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL9_HSDIV_CTRL0                               (0x00009080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_PID                                      (0x0000C000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_MMR_CFG                                  (0x0000C008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_LOCKKEY0                                 (0x0000C010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_LOCKKEY1                                 (0x0000C014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_CTRL                                     (0x0000C020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_STAT                                     (0x0000C024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_FREQ_CTRL0                               (0x0000C030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_FREQ_CTRL1                               (0x0000C034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_DIV_CTRL                                 (0x0000C038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_SS_CTRL                                  (0x0000C040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_SS_SPREAD                                (0x0000C044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_CAL_CTRL                                 (0x0000C060U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_CAL_STAT                                 (0x0000C064U)
#define CSL_MAIN_PLL_MMR_CFG_PLL12_HSDIV_CTRL0                              (0x0000C080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_PID                                      (0x0000D000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_MMR_CFG                                  (0x0000D008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_LOCKKEY0                                 (0x0000D010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_LOCKKEY1                                 (0x0000D014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_CTRL                                     (0x0000D020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_STAT                                     (0x0000D024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_FREQ_CTRL0                               (0x0000D030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_FREQ_CTRL1                               (0x0000D034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_DIV_CTRL                                 (0x0000D038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_SS_CTRL                                  (0x0000D040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_SS_SPREAD                                (0x0000D044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_HSDIV_CTRL0                              (0x0000D080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_HSDIV_CTRL1                              (0x0000D084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_HSDIV_CTRL2                              (0x0000D088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL13_HSDIV_CTRL3                              (0x0000D08CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_PID                                      (0x0000E000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_MMR_CFG                                  (0x0000E008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_LOCKKEY0                                 (0x0000E010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_LOCKKEY1                                 (0x0000E014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_CTRL                                     (0x0000E020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_STAT                                     (0x0000E024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_FREQ_CTRL0                               (0x0000E030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_FREQ_CTRL1                               (0x0000E034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_DIV_CTRL                                 (0x0000E038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_SS_CTRL                                  (0x0000E040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_SS_SPREAD                                (0x0000E044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_HSDIV_CTRL0                              (0x0000E080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL14_HSDIV_CTRL1                              (0x0000E084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_PID                                      (0x0000F000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_MMR_CFG                                  (0x0000F008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_LOCKKEY0                                 (0x0000F010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_LOCKKEY1                                 (0x0000F014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_CTRL                                     (0x0000F020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_STAT                                     (0x0000F024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_FREQ_CTRL0                               (0x0000F030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_FREQ_CTRL1                               (0x0000F034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_DIV_CTRL                                 (0x0000F038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_SS_CTRL                                  (0x0000F040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_SS_SPREAD                                (0x0000F044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_HSDIV_CTRL0                              (0x0000F080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_HSDIV_CTRL1                              (0x0000F084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_HSDIV_CTRL2                              (0x0000F088U)
#define CSL_MAIN_PLL_MMR_CFG_PLL15_HSDIV_CTRL3                              (0x0000F08CU)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_PID                                      (0x00010000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_MMR_CFG                                  (0x00010008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_LOCKKEY0                                 (0x00010010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_LOCKKEY1                                 (0x00010014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_CTRL                                     (0x00010020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_STAT                                     (0x00010024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_FREQ_CTRL0                               (0x00010030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_FREQ_CTRL1                               (0x00010034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_DIV_CTRL                                 (0x00010038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_SS_CTRL                                  (0x00010040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_SS_SPREAD                                (0x00010044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_HSDIV_CTRL0                              (0x00010080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL16_HSDIV_CTRL1                              (0x00010084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_PID                                      (0x00011000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_MMR_CFG                                  (0x00011008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_LOCKKEY0                                 (0x00011010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_LOCKKEY1                                 (0x00011014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_CTRL                                     (0x00011020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_STAT                                     (0x00011024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_FREQ_CTRL0                               (0x00011030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_FREQ_CTRL1                               (0x00011034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_DIV_CTRL                                 (0x00011038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_SS_CTRL                                  (0x00011040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_SS_SPREAD                                (0x00011044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_HSDIV_CTRL0                              (0x00011080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL17_HSDIV_CTRL1                              (0x00011084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_PID                                      (0x00012000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_MMR_CFG                                  (0x00012008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_LOCKKEY0                                 (0x00012010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_LOCKKEY1                                 (0x00012014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_CTRL                                     (0x00012020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_STAT                                     (0x00012024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_FREQ_CTRL0                               (0x00012030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_FREQ_CTRL1                               (0x00012034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_DIV_CTRL                                 (0x00012038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_SS_CTRL                                  (0x00012040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_SS_SPREAD                                (0x00012044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_HSDIV_CTRL0                              (0x00012080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL18_HSDIV_CTRL1                              (0x00012084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_PID                                      (0x00013000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_MMR_CFG                                  (0x00013008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_LOCKKEY0                                 (0x00013010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_LOCKKEY1                                 (0x00013014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_CTRL                                     (0x00013020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_STAT                                     (0x00013024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_FREQ_CTRL0                               (0x00013030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_FREQ_CTRL1                               (0x00013034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_DIV_CTRL                                 (0x00013038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_SS_CTRL                                  (0x00013040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_SS_SPREAD                                (0x00013044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_HSDIV_CTRL0                              (0x00013080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL19_HSDIV_CTRL1                              (0x00013084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_PID                                      (0x00014000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_MMR_CFG                                  (0x00014008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_LOCKKEY0                                 (0x00014010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_LOCKKEY1                                 (0x00014014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_CTRL                                     (0x00014020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_STAT                                     (0x00014024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_FREQ_CTRL0                               (0x00014030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_FREQ_CTRL1                               (0x00014034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_DIV_CTRL                                 (0x00014038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_SS_CTRL                                  (0x00014040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_SS_SPREAD                                (0x00014044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_HSDIV_CTRL0                              (0x00014080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL20_HSDIV_CTRL1                              (0x00014084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_PID                                      (0x00015000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_MMR_CFG                                  (0x00015008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_LOCKKEY0                                 (0x00015010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_LOCKKEY1                                 (0x00015014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_CTRL                                     (0x00015020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_STAT                                     (0x00015024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_FREQ_CTRL0                               (0x00015030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_FREQ_CTRL1                               (0x00015034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_DIV_CTRL                                 (0x00015038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_SS_CTRL                                  (0x00015040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_SS_SPREAD                                (0x00015044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_HSDIV_CTRL0                              (0x00015080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL21_HSDIV_CTRL1                              (0x00015084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_PID                                      (0x00016000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_MMR_CFG                                  (0x00016008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_LOCKKEY0                                 (0x00016010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_LOCKKEY1                                 (0x00016014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_CTRL                                     (0x00016020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_STAT                                     (0x00016024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_FREQ_CTRL0                               (0x00016030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_FREQ_CTRL1                               (0x00016034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_DIV_CTRL                                 (0x00016038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_SS_CTRL                                  (0x00016040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_SS_SPREAD                                (0x00016044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_HSDIV_CTRL0                              (0x00016080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL22_HSDIV_CTRL1                              (0x00016084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_PID                                      (0x00017000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_MMR_CFG                                  (0x00017008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_LOCKKEY0                                 (0x00017010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_LOCKKEY1                                 (0x00017014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_CTRL                                     (0x00017020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_STAT                                     (0x00017024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_FREQ_CTRL0                               (0x00017030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_FREQ_CTRL1                               (0x00017034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_DIV_CTRL                                 (0x00017038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_SS_CTRL                                  (0x00017040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_SS_SPREAD                                (0x00017044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_HSDIV_CTRL0                              (0x00017080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL23_HSDIV_CTRL1                              (0x00017084U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_PID                                      (0x00018000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_MMR_CFG                                  (0x00018008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_LOCKKEY0                                 (0x00018010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_LOCKKEY1                                 (0x00018014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_PLL_CTRL                                 (0x00018020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_DSPLL_STAT                               (0x00018024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_PLL_DIV_CTRL                             (0x00018038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_PLL_TEST_CTRL                            (0x00018050U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_DSCAL_CTRL                               (0x00018060U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_DSCAL_STAT                               (0x00018064U)
#define CSL_MAIN_PLL_MMR_CFG_PLL24_HSDIV_CTRL0                              (0x00018080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_PID                                      (0x00019000U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_MMR_CFG                                  (0x00019008U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_LOCKKEY0                                 (0x00019010U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_LOCKKEY1                                 (0x00019014U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_CTRL                                     (0x00019020U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_STAT                                     (0x00019024U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_FREQ_CTRL0                               (0x00019030U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_FREQ_CTRL1                               (0x00019034U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_DIV_CTRL                                 (0x00019038U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_SS_CTRL                                  (0x00019040U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_SS_SPREAD                                (0x00019044U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_HSDIV_CTRL0                              (0x00019080U)
#define CSL_MAIN_PLL_MMR_CFG_PLL25_HSDIV_CTRL1                              (0x00019084U)

//MCU PLL ---------------------------------------------------------------------

#define CSL_MCU_PLL_MMR_CFG_PLL0_PID                                        (0x00000000U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_MMR_CFG                                    (0x00000008U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_LOCKKEY0                                   (0x00000010U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_LOCKKEY1                                   (0x00000014U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_CTRL                                       (0x00000020U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_STAT                                       (0x00000024U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_FREQ_CTRL0                                 (0x00000030U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_FREQ_CTRL1                                 (0x00000034U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_DIV_CTRL                                   (0x00000038U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_SS_CTRL                                    (0x00000040U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_SS_SPREAD                                  (0x00000044U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_HSDIV_CTRL0                                (0x00000080U)
#define CSL_MCU_PLL_MMR_CFG_PLL0_HSDIV_CTRL1                                (0x00000084U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_PID                                        (0x00001000U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_MMR_CFG                                    (0x00001008U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_LOCKKEY0                                   (0x00001010U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_LOCKKEY1                                   (0x00001014U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_CTRL                                       (0x00001020U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_STAT                                       (0x00001024U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_FREQ_CTRL0                                 (0x00001030U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_FREQ_CTRL1                                 (0x00001034U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_DIV_CTRL                                   (0x00001038U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_SS_CTRL                                    (0x00001040U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_SS_SPREAD                                  (0x00001044U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL0                                (0x00001080U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL1                                (0x00001084U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL2                                (0x00001088U)
#define CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL3                                (0x0000108CU)
#define CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL4                                (0x00001090U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_PID                                        (0x00002000U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_MMR_CFG                                    (0x00002008U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_LOCKKEY0                                   (0x00002010U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_LOCKKEY1                                   (0x00002014U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_CTRL                                       (0x00002020U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_STAT                                       (0x00002024U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_FREQ_CTRL0                                 (0x00002030U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_FREQ_CTRL1                                 (0x00002034U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_DIV_CTRL                                   (0x00002038U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_SS_CTRL                                    (0x00002040U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_SS_SPREAD                                  (0x00002044U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_HSDIV_CTRL0                                (0x00002080U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_HSDIV_CTRL1                                (0x00002084U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_HSDIV_CTRL2                                (0x00002088U)
#define CSL_MCU_PLL_MMR_CFG_PLL2_HSDIV_CTRL3                                (0x0000208CU)
#define CSL_MCU_PLL_MMR_CFG_PLL2_HSDIV_CTRL4                                (0x00002090U)

//PLL controller register offsets
#define PLL_CTRL_PLLCTL_OFFSET      0x0100
#define PLL_CTRL_OCSEL_OFFSET       0x0104
#define PLL_CTRL_PREDIV_OFFSET      0x0114
#define PLL_CTRL_PLLDIV1_OFFSET     0x0118
#define PLL_CTRL_PLLDIV2_OFFSET     0x011C
#define PLL_CTRL_PLLDIV3_OFFSET     0x0120
#define PLL_CTRL_OSCDIV1_OFFSET     0x0124
#define PLL_CTRL_POSTDIV_OFFSET     0x0128
#define PLL_CTRL_BPDIV_OFFSET       0x012C
#define PLL_CTRL_PLLCMD_OFFSET      0x0138
#define PLL_CTRL_PLLSTAT_OFFSET     0x013C
#define PLL_CTRL_ALNCTL_OFFSET      0x0140
#define PLL_CTRL_CKEN_OFFSET        0x0148
#define PLL_CTRL_CKSTAT_OFFSET      0x014C
#define PLL_CTRL_SYSTAT_OFFSET      0x0150
#define PLL_CTRL_PLLDIV4_OFFSET     0x0160
#define PLL_CTRL_PLLDIV5_OFFSET     0x0164
#define PLL_CTRL_PLLDIV6_OFFSET     0x0168
#define PLL_CTRL_PLLDIV7_OFFSET     0x016C
#define PLL_CTRL_PLLDIV8_OFFSET     0x0170
#define PLL_CTRL_PLLDIV9_OFFSET     0x0174
#define PLL_CTRL_PLLDIV10_OFFSET    0x0178
#define PLL_CTRL_PLLDIV11_OFFSET    0x017C
#define PLL_CTRL_PLLDIV12_OFFSET    0x0180
#define PLL_CTRL_PLLDIV13_OFFSET    0x0184
#define PLL_CTRL_PLLDIV14_OFFSET    0x0188
#define PLL_CTRL_PLLDIV15_OFFSET    0x018C
#define PLL_CTRL_PLLDIV16_OFFSET    0x0190

//PLL Index Map
#define MAIN_PLL_INDEX		0
#define PER0_PLL_INDEX		1
#define PER1_PLL_INDEX		2
#define CPSW9_PLL_INDEX		3
#define AUDIO0_PLL_INDEX	4
#define VIDEO_PLL_INDEX		5
#define GPU_PLL_INDEX		6
#define C7X_PLL_INDEX		7
#define ARM0_PLL_INDEX		8
#define DDR_PLL_INDEX		12
#define C66_PLL_INDEX		13
#define MAIN_R5F_PLL_INDEX	14
#define AUDIO1_PLL_INDEX	15
#define DSS0_PLL_INDEX		16
#define DSS1_PLL_INDEX		17
#define DSS2_PLL_INDEX		18
#define DSS3_PLL_INDEX		19
#define DSS7_PLL_INDEX		23
#define MLB_PLL_INDEX		24
#define VISION_PLL_INDEX	25
#define MCU_R5F_PLL_INDEX	0
#define MCU_DOM_PLL_INDEX	1
#define MCU_CPSW_PLL_INDEX	2

//OFFSETS
#define PLL_PID 			(0x00)
#define PLL_CONFIG 			(0x08)
#define CONTROL 			(0x20)
#define STATUS				(0x24)
#define FREQ_CONTROL_0 		(0x30)
#define FREQ_CONTROL_1 		(0x34)
#define OUTPUT_DIV_CONTROL 	(0x38)
#define SSMOD_CONTROL 		(0x40)
#define SSMOD_SPREAD		(0x44)
#define HSDIV_0_CONTROL 	(0x80)
#define HSDIV_1_CONTROL 	(0x84)
#define HSDIV_2_CONTROL 	(0x88)
#define HSDIV_3_CONTROL 	(0x8C)
#define HSDIV_4_CONTROL 	(0x90)
#define HSDIV_5_CONTROL 	(0x94)
#define HSDIV_6_CONTROL 	(0x98)
#define HSDIV_7_CONTROL 	(0x9C)

//Special Programming Indices
#define OFC1 		0
#define ARM_250MHZ 	1
#define ARM_500MHZ 	2
#define ARM_1GHZ 	3
#define ARM_2GHZ 	4
#define VPAC_720	5
#define DMPAC_520	6
#define DDR_BYPASS  7
#define DDR_400     8
#define DDR_800     9
#define DDR_1066    10
#define DDR_1600    11
#define DDR_1866    12
#define DDR_2133    13
#define DDR_3200    14
#define DSS_2970 	15
#define DSS_2345 	16
#define DSS_2898 	17
#define DSS_2613 	18
#define DSS_2133 	19




/*  
Note: if the HSDIV value is -1 that means it's either nonexistent or not used. 
Note: if the mod_div value is -1 that means it isn't programmed beyond the default value of "1", which means the input divider is set to divide-by-1.
Note: the divider values here are directly programmed tothe HSDIV control MMR. They don't factor in the +1 that's added in the hardware. 
	Users should add +1 to the HSDIV divider values they add in here for any calculations they make outside of the GEL framework and the hardware.
Note: This is configured for OFC1 as defined by SOCDV + Venkat.
*/

#define FREF 20.0 	//20MHz HFOSC0 reference clock on QT
#define FREF_SVB 25.0 	//25MHz HFOSC0 reference clock on SVB

/*#define CLKINP_QT       20.0
#define CLKINP_SVB      25.0*/

//PLL0: Main PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2GHz
POSTDIV output: 	1GHz
HSDIV0 output: 		500MHz
HSDIV1 output: 		250MHz
HSDIV2 output: 		200MHz
HSDIV3 output: 		133.33MHz
HSDIV4 output: 		80MHz
HSDIV5 output: 		50MHz
HSDIV6 output: 		250MHz
HSDIV7 output: 		200MHz
HSDIV8 output: 		333.33MHz
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL0_FBDIV             100   //fbdiv
#define MAIN_PLL0_FRACDIV           -1    //fracdiv
#define MAIN_PLL0_PREDIV            1     //prediv
#define MAIN_PLL0_POSTDIV1          2     //postdiv1
#define MAIN_PLL0_POSTDIV2          1     //postdiv2
#define MAIN_PLL0_HSDIV0_DIV_VAL    3     //4
#define MAIN_PLL0_HSDIV1_DIV_VAL    7	//8
#define MAIN_PLL0_HSDIV2_DIV_VAL    9	//10
#define MAIN_PLL0_HSDIV3_DIV_VAL    14	//15
#define MAIN_PLL0_HSDIV4_DIV_VAL    24	//25
#define MAIN_PLL0_HSDIV5_DIV_VAL    19	//20
#define MAIN_PLL0_HSDIV6_DIV_VAL    3	//4
#define MAIN_PLL0_HSDIV7_DIV_VAL    4	//5
#define MAIN_PLL0_HSDIV8_DIV_VAL    2	//3
#define MAIN_PLL0_SSMOD_SPREAD      0x1F  //spread
#define MAIN_PLL0_SSMOD_MODDIV      -1    //mod_div
#define MAIN_PLL0_SSMOD_DOWNSPREAD  1     //downspread

//Main PLL0 PLL Controller Parameters
#define MAIN_CTRL_BPDIV  	0 //AUXCLK=BPCLK=REFCLK for controller
#define MAIN_CTRL_OD1 		0 //OBSCLK=REFCLK for controller
#define MAIN_CTRL_DIV1 		1 //500MHZ SYSCLK1 from HSDIV_CLKOUT1


//PLL1:  Peripheral 0 PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		1920MHz
POSTDIV output: 	960MHz
HSDIV0 output: 		192MHz
HSDIV1 output: 		320MHz
HSDIV2 output: 		192MHz
HSDIV3 output: 		192MHz
HSDIV4 output: 		N/A
HSDIV5 output: 		192MHz
HSDIV6 output: 		19.2MHz
HSDIV7 output: 		24MHz
HSDIV8 output: 		20MHz
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL1_FBDIV             96
#define MAIN_PLL1_FRACDIV           -1
#define MAIN_PLL1_PREDIV            1
#define MAIN_PLL1_POSTDIV1          2
#define MAIN_PLL1_POSTDIV2          1
#define MAIN_PLL1_HSDIV0_DIV_VAL    9	//10
#define MAIN_PLL1_HSDIV1_DIV_VAL    5	//6
#define MAIN_PLL1_HSDIV2_DIV_VAL    9	//10
#define MAIN_PLL1_HSDIV3_DIV_VAL    9	//10
#define MAIN_PLL1_HSDIV4_DIV_VAL    -1 //No HSDIV
#define MAIN_PLL1_HSDIV5_DIV_VAL    4	//5
#define MAIN_PLL1_HSDIV6_DIV_VAL    49	//50
#define MAIN_PLL1_HSDIV7_DIV_VAL    39	//40
#define MAIN_PLL1_HSDIV8_DIV_VAL    47	//48
#define MAIN_PLL1_SSMOD_SPREAD      0x1F
#define MAIN_PLL1_SSMOD_MODDIV      -1
#define MAIN_PLL1_SSMOD_DOWNSPREAD  1


//PLL2: Peripheral 1 PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		1800MHz
POSTDIV output: 	900MHz
HSDIV0 output: 		360MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		200MHz
HSDIV3 output: 		300MHz
HSDIV4 output: 		100MHz
HSDIV5 output: 		450MHz
HSDIV6 output: 		225MHz
HSDIV7 output: 		120MHz
HSDIV8 output:  	N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL2_FBDIV             90
#define MAIN_PLL2_FRACDIV           -1
#define MAIN_PLL2_PREDIV            1
#define MAIN_PLL2_POSTDIV1          2
#define MAIN_PLL2_POSTDIV2          1
#define MAIN_PLL2_HSDIV0_DIV_VAL    4	//5
#define MAIN_PLL2_HSDIV1_DIV_VAL    2	//3
#define MAIN_PLL2_HSDIV2_DIV_VAL    8	//9
#define MAIN_PLL2_HSDIV3_DIV_VAL    5	//6
#define MAIN_PLL2_HSDIV4_DIV_VAL    17	//18
#define MAIN_PLL2_HSDIV5_DIV_VAL    1	//2
#define MAIN_PLL2_HSDIV6_DIV_VAL    3	//4
#define MAIN_PLL2_HSDIV7_DIV_VAL    14 	//15
#define MAIN_PLL2_HSDIV8_DIV_VAL    -1 	//No HSDIV
#define MAIN_PLL2_SSMOD_SPREAD      0x1F
#define MAIN_PLL2_SSMOD_MODDIV      -1
#define MAIN_PLL2_SSMOD_DOWNSPREAD  1


//PLL3: CPSW9x PLL
/* Frequencies:

PLL input:		20MHz
VCO output:		2000MHz
POSTDIV output: 	2000MHz
HSDIV0 output: 		250MHz
HSDIV1 output: 		250MHz
HSDIV2 output: 		200MHz
HSDIV3 output: 		250MHz
HSDIV4 output: 		153MHz (approx 156.25MHz)
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL3_FBDIV             100
#define MAIN_PLL3_FRACDIV           -1
#define MAIN_PLL3_PREDIV            1
#define MAIN_PLL3_POSTDIV1          1
#define MAIN_PLL3_POSTDIV2          1
#define MAIN_PLL3_HSDIV0_DIV_VAL    7 //8
#define MAIN_PLL3_HSDIV1_DIV_VAL    7 //8
#define MAIN_PLL3_HSDIV2_DIV_VAL    9 //10
#define MAIN_PLL3_HSDIV3_DIV_VAL    7 //8
#define MAIN_PLL3_HSDIV4_DIV_VAL    12 //13
#define MAIN_PLL3_HSDIV5_DIV_VAL    -1
#define MAIN_PLL3_HSDIV6_DIV_VAL    -1
#define MAIN_PLL3_HSDIV7_DIV_VAL    -1
#define MAIN_PLL3_HSDIV8_DIV_VAL    -1
#define MAIN_PLL3_SSMOD_SPREAD      0x1F
#define MAIN_PLL3_SSMOD_MODDIV      -1
#define MAIN_PLL3_SSMOD_DOWNSPREAD  1


//PLL4: Audio PLL 0
/* Frequencies:

PLL input: 		20MHz
VCO output:		1180MHz
POSTDIV output: 	1180MHz
HSDIV0 output: 		196.67MHz
HSDIV1 output: 		295MHz
HSDIV2 output: 		196.67MHz
HSDIV3 output: 		12.292MHz
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output:  	N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL4_FBDIV             59
#define MAIN_PLL4_FRACDIV           -1
#define MAIN_PLL4_PREDIV            1
#define MAIN_PLL4_POSTDIV1          1
#define MAIN_PLL4_POSTDIV2          1
#define MAIN_PLL4_HSDIV0_DIV_VAL    5 //6
#define MAIN_PLL4_HSDIV1_DIV_VAL    3 //4
#define MAIN_PLL4_HSDIV2_DIV_VAL    5 //6
#define MAIN_PLL4_HSDIV3_DIV_VAL    95 //96
#define MAIN_PLL4_HSDIV4_DIV_VAL    -1
#define MAIN_PLL4_HSDIV5_DIV_VAL    -1
#define MAIN_PLL4_HSDIV6_DIV_VAL    -1
#define MAIN_PLL4_HSDIV7_DIV_VAL    -1
#define MAIN_PLL4_HSDIV8_DIV_VAL    -1
#define MAIN_PLL4_SSMOD_SPREAD      0x1F
#define MAIN_PLL4_SSMOD_MODDIV      -1
#define MAIN_PLL4_SSMOD_DOWNSPREAD  1


//PLL5: Video PLL
/* Frequencies:

PLL input:		20MHz
VCO output:		2750MHz
POSTDIV output: 	2750MHz
HSDIV0 output:		687.5MHz (approx)
HSDIV1 output: 		550MHz (approx)
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output:  	N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL5_FBDIV             137
#define MAIN_PLL5_FRACDIV           -1
#define MAIN_PLL5_PREDIV            1
#define MAIN_PLL5_POSTDIV1          1
#define MAIN_PLL5_POSTDIV2          1
#define MAIN_PLL5_HSDIV0_DIV_VAL    3 //4
#define MAIN_PLL5_HSDIV1_DIV_VAL    4 //5
#define MAIN_PLL5_HSDIV2_DIV_VAL    -1
#define MAIN_PLL5_HSDIV3_DIV_VAL    -1
#define MAIN_PLL5_HSDIV4_DIV_VAL    -1
#define MAIN_PLL5_HSDIV5_DIV_VAL    -1
#define MAIN_PLL5_HSDIV6_DIV_VAL    -1
#define MAIN_PLL5_HSDIV7_DIV_VAL    -1
#define MAIN_PLL5_HSDIV8_DIV_VAL    -1
#define MAIN_PLL5_SSMOD_SPREAD      0x1F
#define MAIN_PLL5_SSMOD_MODDIV      -1
#define MAIN_PLL5_SSMOD_DOWNSPREAD  1


//PLL6: GPU PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		750MHz
HSDIV1 output: 		N/A
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output:  	N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL6_FBDIV             150
#define MAIN_PLL6_FRACDIV           -1
#define MAIN_PLL6_PREDIV            1
#define MAIN_PLL6_POSTDIV1          1
#define MAIN_PLL6_POSTDIV2          1
#define MAIN_PLL6_HSDIV0_DIV_VAL    3 //4
#define MAIN_PLL6_HSDIV1_DIV_VAL    -1
#define MAIN_PLL6_HSDIV2_DIV_VAL    -1
#define MAIN_PLL6_HSDIV3_DIV_VAL    -1
#define MAIN_PLL6_HSDIV4_DIV_VAL    -1
#define MAIN_PLL6_HSDIV5_DIV_VAL    -1
#define MAIN_PLL6_HSDIV6_DIV_VAL    -1
#define MAIN_PLL6_HSDIV7_DIV_VAL    -1
#define MAIN_PLL6_HSDIV8_DIV_VAL    -1
#define MAIN_PLL6_SSMOD_SPREAD      0x1F
#define MAIN_PLL6_SSMOD_MODDIV      -1
#define MAIN_PLL6_SSMOD_DOWNSPREAD  1


//PLL7: C7x PLL
/* Frequencies:

PLL input:		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		1GHz
HSDIV1 output: 		N/A
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL7_FBDIV             150
#define MAIN_PLL7_FRACDIV           -1
#define MAIN_PLL7_PREDIV            1
#define MAIN_PLL7_POSTDIV1          1
#define MAIN_PLL7_POSTDIV2          1
#define MAIN_PLL7_HSDIV0_DIV_VAL    2 //3
#define MAIN_PLL7_HSDIV1_DIV_VAL    -1
#define MAIN_PLL7_HSDIV2_DIV_VAL    -1
#define MAIN_PLL7_HSDIV3_DIV_VAL    -1
#define MAIN_PLL7_HSDIV4_DIV_VAL    -1
#define MAIN_PLL7_HSDIV5_DIV_VAL    -1
#define MAIN_PLL7_HSDIV6_DIV_VAL    -1
#define MAIN_PLL7_HSDIV7_DIV_VAL    -1
#define MAIN_PLL7_HSDIV8_DIV_VAL    -1
#define MAIN_PLL7_SSMOD_SPREAD      0x1F
#define MAIN_PLL7_SSMOD_MODDIV      -1
#define MAIN_PLL7_SSMOD_DOWNSPREAD  1


//PLL8: ARM0 PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2000MHz
POSTDIV output: 	2000MHz
HSDIV0 output: 		2GHz
HSDIV1 output: 		N/A
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL8_FBDIV             100
#define MAIN_PLL8_FRACDIV           -1
#define MAIN_PLL8_PREDIV            1
#define MAIN_PLL8_POSTDIV1          1
#define MAIN_PLL8_POSTDIV2          1
#define MAIN_PLL8_HSDIV0_DIV_VAL    0 //1
#define MAIN_PLL8_HSDIV1_DIV_VAL    -1
#define MAIN_PLL8_HSDIV2_DIV_VAL    -1
#define MAIN_PLL8_HSDIV3_DIV_VAL    -1
#define MAIN_PLL8_HSDIV4_DIV_VAL    -1
#define MAIN_PLL8_HSDIV5_DIV_VAL    -1
#define MAIN_PLL8_HSDIV6_DIV_VAL    -1
#define MAIN_PLL8_HSDIV7_DIV_VAL    -1
#define MAIN_PLL8_HSDIV8_DIV_VAL    -1
#define MAIN_PLL8_SSMOD_SPREAD      0x1F
#define MAIN_PLL8_SSMOD_MODDIV      -1
#define MAIN_PLL8_SSMOD_DOWNSPREAD  1


//PLL9: Not Present **************************************
//PLL10: Not Present *************************************
//PLL11: Not Present *************************************


//PLL12: DDR FracF PLL
/* Frequencies:

PLL input:		20MHz
VCO output:		2130MHz
POSTDIV output: 	2130MHz
HSDIV0 output: 		1065MHz
HSDIV1 output: 		N/A
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL12_FBDIV            111
#define MAIN_PLL12_FRACDIV          1572864
#define MAIN_PLL12_PREDIV           1
#define MAIN_PLL12_POSTDIV1         1
#define MAIN_PLL12_POSTDIV2         1
#define MAIN_PLL12_HSDIV0_DIV_VAL   1 //2
#define MAIN_PLL12_HSDIV1_DIV_VAL   -1
#define MAIN_PLL12_HSDIV2_DIV_VAL   -1
#define MAIN_PLL12_HSDIV3_DIV_VAL   -1
#define MAIN_PLL12_HSDIV4_DIV_VAL   -1
#define MAIN_PLL12_HSDIV5_DIV_VAL   -1
#define MAIN_PLL12_HSDIV6_DIV_VAL   -1
#define MAIN_PLL12_HSDIV7_DIV_VAL   -1
#define MAIN_PLL12_HSDIV8_DIV_VAL   -1
#define MAIN_PLL12_SSMOD_SPREAD     -1
#define MAIN_PLL12_SSMOD_MODDIV     -1
#define MAIN_PLL12_SSMOD_DOWNSPREAD -1

#define MAIN_PLL12_FBDIV_DDR_1866    93
#define MAIN_PLL12_FRACDIV_DDR_1866  10066329

#define MAIN_PLL12_FBDIV_DDR_1600    80
#define MAIN_PLL12_FRACDIV_DDR_1600  0

#define MAIN_PLL12_FBDIV_DDR_3200    160
#define MAIN_PLL12_FRACDIV_DDR_3200  0


//PLL13: C66 PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2.7GHz
POSTDIV output: 	2.7GHz
HSDIV0 output: 		1.35GHz
HSDIV1 output: 		1.35GHz
HSDIV2 output: 		67.5MHz (not connected to anything)
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL13_FBDIV            135
#define MAIN_PLL13_FRACDIV          -1
#define MAIN_PLL13_PREDIV           1
#define MAIN_PLL13_POSTDIV1         1
#define MAIN_PLL13_POSTDIV2         1
#define MAIN_PLL13_HSDIV0_DIV_VAL   1 //2
#define MAIN_PLL13_HSDIV1_DIV_VAL   1 //2
#define MAIN_PLL13_HSDIV2_DIV_VAL   39 //40
#define MAIN_PLL13_HSDIV3_DIV_VAL   -1
#define MAIN_PLL13_HSDIV4_DIV_VAL   -1
#define MAIN_PLL13_HSDIV5_DIV_VAL   -1
#define MAIN_PLL13_HSDIV6_DIV_VAL   -1
#define MAIN_PLL13_HSDIV7_DIV_VAL   -1
#define MAIN_PLL13_HSDIV8_DIV_VAL   -1
#define MAIN_PLL13_SSMOD_SPREAD     0x1F
#define MAIN_PLL13_SSMOD_MODDIV     -1
#define MAIN_PLL13_SSMOD_DOWNSPREAD 1


//PLL14: Main Pulsar PLL
/* Frequencies:

PLL input:  	20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		1GHz
HSDIV1 output: 		1GHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL14_FBDIV            150
#define MAIN_PLL14_FRACDIV          -1
#define MAIN_PLL14_PREDIV           1
#define MAIN_PLL14_POSTDIV1         1
#define MAIN_PLL14_POSTDIV2         1
#define MAIN_PLL14_HSDIV0_DIV_VAL   2 //3
#define MAIN_PLL14_HSDIV1_DIV_VAL   2 //3
#define MAIN_PLL14_HSDIV2_DIV_VAL   -1
#define MAIN_PLL14_HSDIV3_DIV_VAL   -1
#define MAIN_PLL14_HSDIV4_DIV_VAL   -1
#define MAIN_PLL14_HSDIV5_DIV_VAL   -1
#define MAIN_PLL14_HSDIV6_DIV_VAL   -1
#define MAIN_PLL14_HSDIV7_DIV_VAL   -1
#define MAIN_PLL14_HSDIV8_DIV_VAL   -1
#define MAIN_PLL14_SSMOD_SPREAD     0x1F
#define MAIN_PLL14_SSMOD_MODDIV     -1
#define MAIN_PLL14_SSMOD_DOWNSPREAD 1


//PLL15: Audio PLL 1
/* Frequencies:

PLL input:		20MHz
VCO output:		1180MHz
POSTDIV output: 	1180MHz
HSDIV0 output: 		196.7MHz
HSDIV1 output: 		295MHz
HSDIV2 output: 		196.7MHz
HSDIV3 output: 		12.29MHz
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL15_FBDIV            59
#define MAIN_PLL15_FRACDIV          -1
#define MAIN_PLL15_PREDIV           1
#define MAIN_PLL15_POSTDIV1         1
#define MAIN_PLL15_POSTDIV2         1
#define MAIN_PLL15_HSDIV0_DIV_VAL   5 //6
#define MAIN_PLL15_HSDIV1_DIV_VAL   3 //4
#define MAIN_PLL15_HSDIV2_DIV_VAL   5 //6
#define MAIN_PLL15_HSDIV3_DIV_VAL   95 //96
#define MAIN_PLL15_HSDIV4_DIV_VAL   -1
#define MAIN_PLL15_HSDIV5_DIV_VAL   -1
#define MAIN_PLL15_HSDIV6_DIV_VAL   -1
#define MAIN_PLL15_HSDIV7_DIV_VAL   -1
#define MAIN_PLL15_HSDIV8_DIV_VAL   -1
#define MAIN_PLL15_SSMOD_SPREAD     0x1F
#define MAIN_PLL15_SSMOD_MODDIV     -1
#define MAIN_PLL15_SSMOD_DOWNSPREAD 1


//PLL16: DSS PLL0
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		600MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL16_FBDIV            150
#define MAIN_PLL16_FRACDIV          0
#define MAIN_PLL16_PREDIV           1
#define MAIN_PLL16_POSTDIV1         1
#define MAIN_PLL16_POSTDIV2         1
#define MAIN_PLL16_HSDIV0_DIV_VAL   4 //5
#define MAIN_PLL16_HSDIV1_DIV_VAL   4 //5
#define MAIN_PLL16_HSDIV2_DIV_VAL   -1
#define MAIN_PLL16_HSDIV3_DIV_VAL   -1
#define MAIN_PLL16_HSDIV4_DIV_VAL   -1
#define MAIN_PLL16_HSDIV5_DIV_VAL   -1
#define MAIN_PLL16_HSDIV6_DIV_VAL   -1
#define MAIN_PLL16_HSDIV7_DIV_VAL   -1
#define MAIN_PLL16_HSDIV8_DIV_VAL   -1
#define MAIN_PLL16_SSMOD_SPREAD     0x1F
#define MAIN_PLL16_SSMOD_MODDIV     -1
#define MAIN_PLL16_SSMOD_DOWNSPREAD 1

#define MAIN_PLL16_FBDIV_DSS_2970 		148
#define MAIN_PLL16_FRACDIV_DSS_2970 	8388608

#define MAIN_PLL16_FBDIV_DSS_2345  		117
#define MAIN_PLL16_FRACDIV_DSS_2345 	4949279

#define MAIN_PLL16_FBDIV_DSS_2898 		144
#define MAIN_PLL16_FRACDIV_DSS_2898 	15099494

#define MAIN_PLL16_FBDIV_DSS_2613 		130
#define MAIN_PLL16_FRACDIV_DSS_2613 	10963911

#define MAIN_PLL16_FBDIV_DSS_2133 		106
#define MAIN_PLL16_FRACDIV_DSS_2133     10905190


//PLL17: DSS PLL1
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		600MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL17_FBDIV            150
#define MAIN_PLL17_FRACDIV          0
#define MAIN_PLL17_PREDIV           1
#define MAIN_PLL17_POSTDIV1         1
#define MAIN_PLL17_POSTDIV2         1
#define MAIN_PLL17_HSDIV0_DIV_VAL   4 //5
#define MAIN_PLL17_HSDIV1_DIV_VAL   4 //5
#define MAIN_PLL17_HSDIV2_DIV_VAL   -1
#define MAIN_PLL17_HSDIV3_DIV_VAL   -1
#define MAIN_PLL17_HSDIV4_DIV_VAL   -1
#define MAIN_PLL17_HSDIV5_DIV_VAL   -1
#define MAIN_PLL17_HSDIV6_DIV_VAL   -1
#define MAIN_PLL17_HSDIV7_DIV_VAL   -1
#define MAIN_PLL17_HSDIV8_DIV_VAL   -1
#define MAIN_PLL17_SSMOD_SPREAD     0x1F
#define MAIN_PLL17_SSMOD_MODDIV     -1
#define MAIN_PLL17_SSMOD_DOWNSPREAD 1

#define MAIN_PLL17_FBDIV_DSS_2970 		148
#define MAIN_PLL17_FRACDIV_DSS_2970 	8388608

#define MAIN_PLL17_FBDIV_DSS_2345  		117
#define MAIN_PLL17_FRACDIV_DSS_2345 	4949279

#define MAIN_PLL17_FBDIV_DSS_2898 		144
#define MAIN_PLL17_FRACDIV_DSS_2898 	15099494

#define MAIN_PLL17_FBDIV_DSS_2613 		130
#define MAIN_PLL17_FRACDIV_DSS_2613 	10963911

#define MAIN_PLL17_FBDIV_DSS_2133 		106
#define MAIN_PLL17_FRACDIV_DSS_2133     10905190


//PLL18: DSS PLL2
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		600MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL18_FBDIV            150
#define MAIN_PLL18_FRACDIV          0
#define MAIN_PLL18_PREDIV           1
#define MAIN_PLL18_POSTDIV1         1
#define MAIN_PLL18_POSTDIV2         1
#define MAIN_PLL18_HSDIV0_DIV_VAL   4 //5
#define MAIN_PLL18_HSDIV1_DIV_VAL   4 //5
#define MAIN_PLL18_HSDIV2_DIV_VAL   -1
#define MAIN_PLL18_HSDIV3_DIV_VAL   -1
#define MAIN_PLL18_HSDIV4_DIV_VAL   -1
#define MAIN_PLL18_HSDIV5_DIV_VAL   -1
#define MAIN_PLL18_HSDIV6_DIV_VAL   -1
#define MAIN_PLL18_HSDIV7_DIV_VAL   -1
#define MAIN_PLL18_HSDIV8_DIV_VAL   -1
#define MAIN_PLL18_SSMOD_SPREAD     0x1F
#define MAIN_PLL18_SSMOD_MODDIV     -1
#define MAIN_PLL18_SSMOD_DOWNSPREAD 1

#define MAIN_PLL18_FBDIV_DSS_2970 		148
#define MAIN_PLL18_FRACDIV_DSS_2970 	8388608

#define MAIN_PLL18_FBDIV_DSS_2345  		117
#define MAIN_PLL18_FRACDIV_DSS_2345 	4949279

#define MAIN_PLL18_FBDIV_DSS_2898 		144
#define MAIN_PLL18_FRACDIV_DSS_2898 	15099494


//PLL19: DSS PLL3
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		600MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL19_FBDIV            150
#define MAIN_PLL19_FRACDIV          0
#define MAIN_PLL19_PREDIV           1
#define MAIN_PLL19_POSTDIV1         1
#define MAIN_PLL19_POSTDIV2         1
#define MAIN_PLL19_HSDIV0_DIV_VAL   4 //5
#define MAIN_PLL19_HSDIV1_DIV_VAL   4 //5
#define MAIN_PLL19_HSDIV2_DIV_VAL   -1
#define MAIN_PLL19_HSDIV3_DIV_VAL   -1
#define MAIN_PLL19_HSDIV4_DIV_VAL   -1
#define MAIN_PLL19_HSDIV5_DIV_VAL   -1
#define MAIN_PLL19_HSDIV6_DIV_VAL   -1
#define MAIN_PLL19_HSDIV7_DIV_VAL   -1
#define MAIN_PLL19_HSDIV8_DIV_VAL   -1
#define MAIN_PLL19_SSMOD_SPREAD     0x1F
#define MAIN_PLL19_SSMOD_MODDIV     -1
#define MAIN_PLL19_SSMOD_DOWNSPREAD 1

#define MAIN_PLL19_FBDIV_DSS_2970 		148
#define MAIN_PLL19_FRACDIV_DSS_2970 	8388608



//PLL20: Not Present *************************************
//PLL21: Not Present *************************************
//PLL22: Not Present *************************************


//PLL23: DSS PLL7
/* Frequencies:

PLL input: 		20MHz
VCO output:		3GHz
POSTDIV output: 	3GHz
HSDIV0 output: 		600MHz
HSDIV1 output: 		600MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread:

 */
#define MAIN_PLL23_FBDIV            150
#define MAIN_PLL23_FRACDIV          0
#define MAIN_PLL23_PREDIV           1
#define MAIN_PLL23_POSTDIV1         1
#define MAIN_PLL23_POSTDIV2         1
#define MAIN_PLL23_HSDIV0_DIV_VAL   4 //5
#define MAIN_PLL23_HSDIV1_DIV_VAL   4 //5
#define MAIN_PLL23_HSDIV2_DIV_VAL   -1
#define MAIN_PLL23_HSDIV3_DIV_VAL   -1
#define MAIN_PLL23_HSDIV4_DIV_VAL   -1
#define MAIN_PLL23_HSDIV5_DIV_VAL   -1
#define MAIN_PLL23_HSDIV6_DIV_VAL   -1
#define MAIN_PLL23_HSDIV7_DIV_VAL   -1
#define MAIN_PLL23_HSDIV8_DIV_VAL   -1
#define MAIN_PLL23_SSMOD_SPREAD     0x1F
#define MAIN_PLL23_SSMOD_MODDIV     -1
#define MAIN_PLL23_SSMOD_DOWNSPREAD 1

#define MAIN_PLL23_FBDIV_DSS_2970 		148
#define MAIN_PLL23_FRACDIV_DSS_2970 	8388608


//PLL25: Image Processing PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2880MHz
POSTDIV output: 	2880MHz
HSDIV0 output: 		480MHz
HSDIV1 output: 		720MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MAIN_PLL25_FBDIV            144
#define MAIN_PLL25_FRACDIV          -1
#define MAIN_PLL25_PREDIV           1
#define MAIN_PLL25_POSTDIV1         1
#define MAIN_PLL25_POSTDIV2         1
#define MAIN_PLL25_HSDIV0_DIV_VAL   5 //6
#define MAIN_PLL25_HSDIV1_DIV_VAL   3 //4
#define MAIN_PLL25_HSDIV2_DIV_VAL   -1
#define MAIN_PLL25_HSDIV3_DIV_VAL   -1
#define MAIN_PLL25_HSDIV4_DIV_VAL   -1
#define MAIN_PLL25_HSDIV5_DIV_VAL   -1
#define MAIN_PLL25_HSDIV6_DIV_VAL   -1
#define MAIN_PLL25_HSDIV7_DIV_VAL   -1
#define MAIN_PLL25_HSDIV8_DIV_VAL   -1
#define MAIN_PLL25_SSMOD_SPREAD     0x1F
#define MAIN_PLL25_SSMOD_MODDIV     -1
#define MAIN_PLL25_SSMOD_DOWNSPREAD 1

#define MAIN_PLL25_FBDIV_DMPAC_520 	130			// 2600MHz VCO output
#define MAIN_PLL25_FRACDIV_DMPAC_520 -1			// 2600MHz VCO output
#define MAIN_PLL25_HSDIV0_DMPAC_520_DIV_VAL 	4 //5 (this is going to DMPAC)
#define MAIN_PLL25_HSDIV1_DMPAC_520_DIV_VAL 	3 //4 (this is going to VPAC)


//MCU PLL0: MCU PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2000MHz
POSTDIV output: 	2GHz
HSDIV0 output: 		1GHz
HSDIV1 output: 		60.6MHz
HSDIV2 output: 		N/A
HSDIV3 output: 		N/A
HSDIV4 output: 		N/A
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MCU_PLL0_FBDIV              100
#define MCU_PLL0_FRACDIV            -1
#define MCU_PLL0_PREDIV             1
#define MCU_PLL0_POSTDIV1           1
#define MCU_PLL0_POSTDIV2           1
#define MCU_PLL0_HSDIV0_DIV_VAL     1 //2
#define MCU_PLL0_HSDIV1_DIV_VAL     32 //33
#define MCU_PLL0_HSDIV2_DIV_VAL     -1
#define MCU_PLL0_HSDIV3_DIV_VAL     -1
#define MCU_PLL0_HSDIV4_DIV_VAL     -1
#define MCU_PLL0_HSDIV5_DIV_VAL     -1
#define MCU_PLL0_HSDIV6_DIV_VAL     -1
#define MCU_PLL0_HSDIV7_DIV_VAL     -1
#define MCU_PLL0_HSDIV8_DIV_VAL     -1
#define MCU_PLL0_SSMOD_SPREAD       0x1F
#define MCU_PLL0_SSMOD_MODDIV       -1
#define MCU_PLL0_SSMOD_DOWNSPREAD   1

//MCU0 PLL PLL Controller Parameters
#define MCU_CTRL_BPDIV  0 //AUXCLK=BPCLK=REFCLK for controller
#define MCU_CTRL_OD1    0 //OBSCLK=REFCLK for controller
#define MCU_CTRL_DIV1   1 //1000MHZ SYSCLK1 from MCU PLL CLKOUT


//MCU PLL1: MCU Pulsar PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2400MHz
POSTDIV output: 	2400MHz
HSDIV0 output: 		400MHz
HSDIV1 output: 		60MHz
HSDIV2 output: 		80MHz
HSDIV3 output: 		96MHz
HSDIV4 output: 		400MHz
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MCU_PLL1_FBDIV              120
#define MCU_PLL1_FRACDIV            -1
#define MCU_PLL1_PREDIV             1
#define MCU_PLL1_POSTDIV1           1
#define MCU_PLL1_POSTDIV2           1
#define MCU_PLL1_HSDIV0_DIV_VAL     5 //6
#define MCU_PLL1_HSDIV1_DIV_VAL     39 //40
#define MCU_PLL1_HSDIV2_DIV_VAL     29 //30
#define MCU_PLL1_HSDIV3_DIV_VAL     24 //25
#define MCU_PLL1_HSDIV4_DIV_VAL     5 //6
#define MCU_PLL1_HSDIV5_DIV_VAL     -1
#define MCU_PLL1_HSDIV6_DIV_VAL     -1
#define MCU_PLL1_HSDIV7_DIV_VAL     -1
#define MCU_PLL1_HSDIV8_DIV_VAL     -1
#define MCU_PLL1_SSMOD_SPREAD       0x1F
#define MCU_PLL1_SSMOD_MODDIV       -1
#define MCU_PLL1_SSMOD_DOWNSPREAD   1


//MCU PLL2: MCU CPSW PLL
/* Frequencies:

PLL input: 		20MHz
VCO output:		2000MHz
POSTDIV output: 	2000MHz
HSDIV0 output: 		250MHz
HSDIV1 output: 		200MHz
HSDIV2 output: 		200MHz
HSDIV3 output: 		80MHz
HSDIV4 output: 		333.33MHz
HSDIV5 output: 		N/A
HSDIV6 output: 		N/A
HSDIV7 output: 		N/A
HSDIV8 output: 		N/A
MODSS configuration: 
- Spread: 3.125%
- Modulator Divider: %-by-1
- Downspread or centerspread: downspread

 */
#define MCU_PLL2_FBDIV              100
#define MCU_PLL2_FRACDIV            -1
#define MCU_PLL2_PREDIV             1
#define MCU_PLL2_POSTDIV1           1
#define MCU_PLL2_POSTDIV2           1
#define MCU_PLL2_HSDIV0_DIV_VAL     7 //8
#define MCU_PLL2_HSDIV1_DIV_VAL     9 //10
#define MCU_PLL2_HSDIV2_DIV_VAL     9 //10
#define MCU_PLL2_HSDIV3_DIV_VAL     24 //25
#define MCU_PLL2_HSDIV4_DIV_VAL     11 //5 //6
#define MCU_PLL2_HSDIV5_DIV_VAL     -1
#define MCU_PLL2_HSDIV6_DIV_VAL     -1
#define MCU_PLL2_HSDIV7_DIV_VAL     -1
#define MCU_PLL2_HSDIV8_DIV_VAL     -1
#define MCU_PLL2_SSMOD_SPREAD       0x1F
#define MCU_PLL2_SSMOD_MODDIV       -1
#define MCU_PLL2_SSMOD_DOWNSPREAD   1

typedef struct Board_PllClkCfg_s
{
    uint32_t tisciDevID;
    uint32_t tisciClkID;
    uint64_t clkRate;
    
} Board_PllClkCfg_t;

/* END OF FILE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* BOARD_PLL_H */
