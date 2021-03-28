/**
 * \file  boardPadDelayTable.h
 *
 * \brief   This file contain manual/virtual iodelay mode definitions
 *
 * \copyright Copyright (CU) 2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

#include <ti/board/src/evmDRA72x/pinmux/boardPadDelayTune.h>

/** {PADCONF_REG_OFFSET, PADCONF_VALUE, {CFG_X_IN offset, aDelay, gDelay}, {CFG_X_OEN offset, aDelay, gDelay}, {CFG_X_OUT offset, aDelay, gDelay}} **/
    /* qspi1_rtclk */
    {0x74, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A13, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_d3 */
    {0x78, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A14, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_d2 */
    {0x7C, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A15, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_d0 */
    {0x80, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A16, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_d1 */
    {0x84, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A17, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_sclk */
    {0x88, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A18, 0x70001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat4 */
    {0x8C, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A19, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat5 */
    {0x90, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A20, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat6 */
    {0x94, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A21, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat7 */
    {0x98, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A22, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_clk */
    {0x9C, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A23, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat0 */
    {0xA0, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A24, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat1 */
    {0xA4, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A25, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat2 */
    {0xA8, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A26, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_dat3 */
    {0xAC, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_A27, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* mmc2_cmd */
    {0xB0, 0x60001,
      {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_CS1, 0x60001, {N/A}, {N/A}, {N/A}} **/
    /* qspi1_cs0 */
    {0xB8, 0x70001,
     {0x0,  0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_GPMC_CS2, 0x70001, {N/A}, {N/A}, {N/A}} **/
