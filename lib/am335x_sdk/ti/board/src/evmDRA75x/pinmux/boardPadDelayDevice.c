/**
 * \file  boardPadDelayDevice.c
 *
 * \brief   This file contain run time configuration based on devices connected to SOC interfaces.
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

#include <stdio.h>
#include <stdint.h>
#include "boardPadDelay.h"

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1DsPlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1DsPlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1DsPlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_clk on W6 **/
    {0x358, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_cmd on Y6 **/
    {0x35C, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_dat0 on AA6 **/
    {0x360, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_dat1 on Y4 **/
    {0x364, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_dat2 on AA5 **/
    {0x368, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1DsPlb:MMC1_DEFAULT - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr12PlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr12PlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr12PlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_clk on W6 **/
    {0x358, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_cmd on Y6 **/
    {0x35C, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_dat0 on AA6 **/
    {0x360, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_dat1 on Y4 **/
    {0x364, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_dat2 on AA5 **/
    {0x368, 0x60000, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Sdr12Plb:MMC1_DEFAULT - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Ddr50PlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Ddr50PlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Ddr50PlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60100, {0x618, 1076, 330}, {0x0, 0, 0}, {0x620, 1271, 0}}, /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_clk on W6 **/
    {0x358, 0x60100, {0x624, 722, 0}, {0x628, 0, 0}, {0x62C, 0, 0}},     /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x60100, {0x630, 751, 0}, {0x634, 0, 0}, {0x638, 20, 0}},    /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x60100, {0x63C, 256, 0}, {0x640, 0, 0}, {0x644, 0, 0}},     /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x60100, {0x648, 263, 0}, {0x64C, 0, 0}, {0x650, 0, 0}},     /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x60100, {0x654, 0, 0}, {0x658, 0, 0}, {0x65C, 0, 0}} /** MMC1 - Mmc1Ddr50Plb:MMC1_DDR_MANUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr104Pinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr104Pinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr104Pinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60100, {0x0, 0, 0}, {0x0, 0, 0}, {0x620, 600, 400}}, /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_clk on W6 **/
    {0x358, 0x60100, {0x0, 0, 0}, {0x628, 0, 0}, {0x62C, 0, 0}},   /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x60100, {0x0, 0, 0}, {0x634, 0, 0}, {0x638, 30, 0}},  /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x60100, {0x0, 0, 0}, {0x640, 0, 0}, {0x644, 0, 0}},   /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x60100, {0x0, 0, 0}, {0x64C, 0, 0}, {0x650, 0, 0}},   /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x60100, {0x0, 0, 0}, {0x658, 0, 0}, {0x65C, 0, 0}} /** MMC1 - Mmc1Sdr104:MMC1_SDR104_MANUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1HsIlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1HsIlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1HsIlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_clk on W6 **/
    {0x358, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1HsIlb:MMC1_VIRTUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1HsPlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1HsPlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1HsPlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_clk on W6 **/
    {0x358, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1HsPlb:MMC1_VIRTUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr12IlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr12IlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr12IlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_clk on W6 **/
    {0x358, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Sdr12Ilb:MMC1_VIRTUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr25IlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr25IlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr25IlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_clk on W6 **/
    {0x358, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_cmd on Y6 **/
    {0x35C, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_dat0 on AA6 **/
    {0x360, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_dat1 on Y4 **/
    {0x364, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_dat2 on AA5 **/
    {0x368, 0x601B0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Sdr25Ilb:MMC1_VIRTUAL1 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr50PlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr50PlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr50PlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_clk on W6 **/
    {0x358, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_cmd on Y6 **/
    {0x35C, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_dat0 on AA6 **/
    {0x360, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_dat1 on Y4 **/
    {0x364, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_dat2 on AA5 **/
    {0x368, 0x601A0, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Sdr50Plb:MMC1_VIRTUAL2 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1DsIlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1DsIlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1DsIlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_clk on W6 **/
    {0x358, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_cmd on Y6 **/
    {0x35C, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_dat0 on AA6 **/
    {0x360, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_dat1 on Y4 **/
    {0x364, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_dat2 on AA5 **/
    {0x368, 0x60170, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1DsIlb:MMC1_VIRTUAL5 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Sdr50IlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Sdr50IlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Sdr50IlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_clk on W6 **/
    {0x358, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_cmd on Y6 **/
    {0x35C, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_dat0 on AA6 **/
    {0x360, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_dat1 on Y4 **/
    {0x364, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_dat2 on AA5 **/
    {0x368, 0x60160, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Sdr50Ilb:MMC1_VIRTUAL6 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc1Ddr50IlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc1Ddr50IlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc1Ddr50IlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x354, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_clk on W6 **/
    {0x358, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_cmd on Y6 **/
    {0x35C, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_dat0 on AA6 **/
    {0x360, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_dat1 on Y4 **/
    {0x364, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_dat2 on AA5 **/
    {0x368, 0x60150, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC1 - Mmc1Ddr50Ilb:MMC1_VIRTUAL7 - mmc1_dat3 on Y3 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2HsPlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2HsPlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2HsPlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_clk on J7 **/
    {0xB0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_cmd on H6 **/
    {0xA0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat0 on J4 **/
    {0xA4, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat1 on J6 **/
    {0xA8, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat2 on H4 **/
    {0xAC, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat3 on H5 **/
    {0x8C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat4 on K7 **/
    {0x90, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat5 on M7 **/
    {0x94, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat6 on J5 **/
    {0x98, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC2 - Mmc2HsPlb:MMC2_DEFAULT - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2StdPlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2StdPlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2StdPlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_clk on J7 **/
    {0xB0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_cmd on H6 **/
    {0xA0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat0 on J4 **/
    {0xA4, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat1 on J6 **/
    {0xA8, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat2 on H4 **/
    {0xAC, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat3 on H5 **/
    {0x8C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat4 on K7 **/
    {0x90, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat5 on M7 **/
    {0x94, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat6 on J5 **/
    {0x98, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC2 - Mmc2StdPlb:MMC2_DEFAULT - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2DdrPlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2DdrPlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2DdrPlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_clk on J7 **/
    {0xB0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_cmd on H6 **/
    {0xA0, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat0 on J4 **/
    {0xA4, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat1 on J6 **/
    {0xA8, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat2 on H4 **/
    {0xAC, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat3 on H5 **/
    {0x8C, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat4 on K7 **/
    {0x90, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat5 on M7 **/
    {0x94, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}}, /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat6 on J5 **/
    {0x98, 0x60001, {0x0, 0, 0}, {0x0, 0, 0}, {0x0, 0, 0}} /** MMC2 - Mmc2DdrPlb:MMC2_DEFAULT - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2DdrIlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2DdrIlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2DdrIlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60101, {0x1C8, 592, 2815}, {0x0, 0, 0}, {0x1D0, 422, 0}}, /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_clk on J7 **/
    {0xB0, 0x60101, {0x360, 0, 0}, {0x364, 0, 0}, {0x368, 0, 0}},      /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_cmd on H6 **/
    {0xA0, 0x60101, {0x1D4, 384, 0}, {0x1D8, 0, 0}, {0x1DC, 0, 0}},    /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat0 on J4 **/
    {0xA4, 0x60101, {0x1E0, 0, 0}, {0x1E4, 0, 0}, {0x1E8, 0, 0}},      /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat1 on J6 **/
    {0xA8, 0x60101, {0x1EC, 171, 0}, {0x1F0, 0, 0}, {0x1F4, 0, 0}},    /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat2 on H4 **/
    {0xAC, 0x60101, {0x1F8, 315, 0}, {0x1FC, 0, 0}, {0x200, 54, 0}},   /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat3 on H5 **/
    {0x8C, 0x60101, {0x18C, 49, 0}, {0x190, 0, 0}, {0x194, 170, 0}},   /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat4 on K7 **/
    {0x90, 0x60101, {0x1A4, 463, 0}, {0x1A8, 0, 0}, {0x1AC, 81, 0}},   /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat5 on M7 **/
    {0x94, 0x60101, {0x1B0, 8, 0}, {0x1B4, 0, 0}, {0x1B8, 123, 0}},    /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat6 on J5 **/
    {0x98, 0x60101, {0x1BC, 0, 102}, {0x1C0, 0, 0}, {0x1C4, 55, 0}} /** MMC2 - Mmc2DdrIlb:MMC2_DDR_LB_MANUAL1 - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2Hs200Pinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2Hs200Pinmux[] = {
#else
const boardPadDelayCfg_t gMmc2Hs200Pinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60101, {0x0, 0, 0}, {0x0, 0, 0}, {0x1D0, 935, 280}},   /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_clk on J7 **/
    {0xB0, 0x60101, {0x0, 0, 0}, {0x364, 684, 0}, {0x368, 76, 0}},  /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_cmd on H6 **/
    {0xA0, 0x60101, {0x0, 0, 0}, {0x1D8, 621, 0}, {0x1DC, 0, 0}},   /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat0 on J4 **/
    {0xA4, 0x60101, {0x0, 0, 0}, {0x1E4, 183, 0}, {0x1E8, 0, 0}},   /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat1 on J6 **/
    {0xA8, 0x60101, {0x0, 0, 0}, {0x1F0, 467, 0}, {0x1F4, 0, 0}},   /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat2 on H4 **/
    {0xAC, 0x60101, {0x0, 0, 0}, {0x1FC, 262, 0}, {0x200, 46, 0}},  /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat3 on H5 **/
    {0x8C, 0x60101, {0x0, 0, 0}, {0x190, 274, 0}, {0x194, 162, 0}}, /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat4 on K7 **/
    {0x90, 0x60101, {0x0, 0, 0}, {0x1A8, 401, 0}, {0x1AC, 73, 0}},  /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat5 on M7 **/
    {0x94, 0x60101, {0x0, 0, 0}, {0x1B4, 465, 0}, {0x1B8, 115, 0}}, /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat6 on J5 **/
    {0x98, 0x60101, {0x0, 0, 0}, {0x1C0, 633, 0}, {0x1C4, 47, 0}} /** MMC2 - Mmc2Hs200:MMC2_HS200_MANUAL1 - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2StdIlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2StdIlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2StdIlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60101, {0x1C8, 0, 2764}, {0x0, 0, 0}, {0x1D0, 0, 0}},   /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_clk on J7 **/
    {0xB0, 0x60101, {0x360, 250, 0}, {0x364, 0, 0}, {0x368, 0, 0}},  /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_cmd on H6 **/
    {0xA0, 0x60101, {0x1D4, 1185, 0}, {0x1D8, 0, 0}, {0x1DC, 0, 0}}, /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat0 on J4 **/
    {0xA4, 0x60101, {0x1E0, 670, 0}, {0x1E4, 0, 0}, {0x1E8, 0, 0}},  /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat1 on J6 **/
    {0xA8, 0x60101, {0x1EC, 972, 0}, {0x1F0, 0, 0}, {0x1F4, 0, 0}},  /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat2 on H4 **/
    {0xAC, 0x60101, {0x1F8, 1116, 0}, {0x1FC, 0, 0}, {0x200, 0, 0}}, /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat3 on H5 **/
    {0x8C, 0x60101, {0x18C, 850, 0}, {0x190, 0, 0}, {0x194, 0, 0}},  /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat4 on K7 **/
    {0x90, 0x60101, {0x1A4, 1264, 0}, {0x1A8, 0, 0}, {0x1AC, 0, 0}}, /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat5 on M7 **/
    {0x94, 0x60101, {0x1B0, 786, 0}, {0x1B4, 0, 0}, {0x1B8, 0, 0}},  /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat6 on J5 **/
    {0x98, 0x60101, {0x1BC, 902, 0}, {0x1C0, 0, 0}, {0x1C4, 0, 0}} /** MMC2 - Mmc2StdIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc2HsIlbPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc2HsIlbPinmux[] = {
#else
const boardPadDelayCfg_t gMmc2HsIlbPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x9C, 0x60101, {0x1C8, 0, 2764}, {0x0, 0, 0}, {0x1D0, 0, 0}},   /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_clk on J7 **/
    {0xB0, 0x60101, {0x360, 250, 0}, {0x364, 0, 0}, {0x368, 0, 0}},  /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_cmd on H6 **/
    {0xA0, 0x60101, {0x1D4, 1185, 0}, {0x1D8, 0, 0}, {0x1DC, 0, 0}}, /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat0 on J4 **/
    {0xA4, 0x60101, {0x1E0, 670, 0}, {0x1E4, 0, 0}, {0x1E8, 0, 0}},  /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat1 on J6 **/
    {0xA8, 0x60101, {0x1EC, 972, 0}, {0x1F0, 0, 0}, {0x1F4, 0, 0}},  /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat2 on H4 **/
    {0xAC, 0x60101, {0x1F8, 1116, 0}, {0x1FC, 0, 0}, {0x200, 0, 0}}, /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat3 on H5 **/
    {0x8C, 0x60101, {0x18C, 850, 0}, {0x190, 0, 0}, {0x194, 0, 0}},  /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat4 on K7 **/
    {0x90, 0x60101, {0x1A4, 1264, 0}, {0x1A8, 0, 0}, {0x1AC, 0, 0}}, /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat5 on M7 **/
    {0x94, 0x60101, {0x1B0, 786, 0}, {0x1B4, 0, 0}, {0x1B8, 0, 0}},  /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat6 on J5 **/
    {0x98, 0x60101, {0x1BC, 902, 0}, {0x1C0, 0, 0}, {0x1C4, 0, 0}} /** MMC2 - Mmc2HsIlb:MMC2_STD_HS_LB_MANUAL1 - mmc2_dat7 on K6 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc3DsPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc3DsPinmux[] = {
#else
const boardPadDelayCfg_t gMmc3DsPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x37C, 0x60100, {0x678, 0, 386}, {0x0, 0, 0}, {0x680, 605, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_clk on AD4 **/
    {0x380, 0x60100, {0x684, 0, 0}, {0x688, 0, 0}, {0x68C, 0, 0}},   /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_cmd on AC4 **/
    {0x384, 0x60100, {0x690, 171, 0}, {0x694, 0, 0}, {0x698, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat0 on AC7 **/
    {0x388, 0x60100, {0x69C, 221, 0}, {0x6A0, 0, 0}, {0x6A4, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat1 on AC6 **/
    {0x38C, 0x60100, {0x6A8, 0, 0}, {0x6AC, 0, 0}, {0x6B0, 0, 0}},   /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat2 on AC9 **/
    {0x390, 0x60100, {0x6B4, 474, 0}, {0x6B8, 0, 0}, {0x6BC, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat3 on AC3 **/
    {0x394, 0x60100, {0x6C0, 792, 0}, {0x6C4, 0, 0}, {0x6C8, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat4 on AC8 **/
    {0x398, 0x60100, {0x6CC, 782, 0}, {0x6D0, 0, 0}, {0x6D4, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat5 on AD6 **/
    {0x39C, 0x60100, {0x6D8, 942, 0}, {0x6DC, 0, 0}, {0x6E0, 0, 0}}, /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat6 on AB8 **/
    {0x3A0, 0x60100, {0x6E4, 636, 0}, {0x6E8, 0, 0}, {0x6EC, 0, 0}} /** MMC3 - Mmc3Ds:MMC3_MANUAL1 - mmc3_dat7 on AB5 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc3Sdr12Pinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc3Sdr12Pinmux[] = {
#else
const boardPadDelayCfg_t gMmc3Sdr12Pinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x37C, 0x60100, {0x678, 0, 386}, {0x0, 0, 0}, {0x680, 605, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_clk on AD4 **/
    {0x380, 0x60100, {0x684, 0, 0}, {0x688, 0, 0}, {0x68C, 0, 0}},   /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_cmd on AC4 **/
    {0x384, 0x60100, {0x690, 171, 0}, {0x694, 0, 0}, {0x698, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat0 on AC7 **/
    {0x388, 0x60100, {0x69C, 221, 0}, {0x6A0, 0, 0}, {0x6A4, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat1 on AC6 **/
    {0x38C, 0x60100, {0x6A8, 0, 0}, {0x6AC, 0, 0}, {0x6B0, 0, 0}},   /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat2 on AC9 **/
    {0x390, 0x60100, {0x6B4, 474, 0}, {0x6B8, 0, 0}, {0x6BC, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat3 on AC3 **/
    {0x394, 0x60100, {0x6C0, 792, 0}, {0x6C4, 0, 0}, {0x6C8, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat4 on AC8 **/
    {0x398, 0x60100, {0x6CC, 782, 0}, {0x6D0, 0, 0}, {0x6D4, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat5 on AD6 **/
    {0x39C, 0x60100, {0x6D8, 942, 0}, {0x6DC, 0, 0}, {0x6E0, 0, 0}}, /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat6 on AB8 **/
    {0x3A0, 0x60100, {0x6E4, 636, 0}, {0x6E8, 0, 0}, {0x6EC, 0, 0}} /** MMC3 - Mmc3Sdr12:MMC3_MANUAL1 - mmc3_dat7 on AB5 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc3HsPinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc3HsPinmux[] = {
#else
const boardPadDelayCfg_t gMmc3HsPinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x37C, 0x60100, {0x678, 0, 386}, {0x0, 0, 0}, {0x680, 605, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_clk on AD4 **/
    {0x380, 0x60100, {0x684, 0, 0}, {0x688, 0, 0}, {0x68C, 0, 0}},   /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_cmd on AC4 **/
    {0x384, 0x60100, {0x690, 171, 0}, {0x694, 0, 0}, {0x698, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat0 on AC7 **/
    {0x388, 0x60100, {0x69C, 221, 0}, {0x6A0, 0, 0}, {0x6A4, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat1 on AC6 **/
    {0x38C, 0x60100, {0x6A8, 0, 0}, {0x6AC, 0, 0}, {0x6B0, 0, 0}},   /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat2 on AC9 **/
    {0x390, 0x60100, {0x6B4, 474, 0}, {0x6B8, 0, 0}, {0x6BC, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat3 on AC3 **/
    {0x394, 0x60100, {0x6C0, 792, 0}, {0x6C4, 0, 0}, {0x6C8, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat4 on AC8 **/
    {0x398, 0x60100, {0x6CC, 782, 0}, {0x6D0, 0, 0}, {0x6D4, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat5 on AD6 **/
    {0x39C, 0x60100, {0x6D8, 942, 0}, {0x6DC, 0, 0}, {0x6E0, 0, 0}}, /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat6 on AB8 **/
    {0x3A0, 0x60100, {0x6E4, 636, 0}, {0x6E8, 0, 0}, {0x6EC, 0, 0}} /** MMC3 - Mmc3Hs:MMC3_MANUAL1 - mmc3_dat7 on AB5 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc3Sdr25Pinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc3Sdr25Pinmux[] = {
#else
const boardPadDelayCfg_t gMmc3Sdr25Pinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x37C, 0x60100, {0x678, 0, 386}, {0x0, 0, 0}, {0x680, 605, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_clk on AD4 **/
    {0x380, 0x60100, {0x684, 0, 0}, {0x688, 0, 0}, {0x68C, 0, 0}},   /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_cmd on AC4 **/
    {0x384, 0x60100, {0x690, 171, 0}, {0x694, 0, 0}, {0x698, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat0 on AC7 **/
    {0x388, 0x60100, {0x69C, 221, 0}, {0x6A0, 0, 0}, {0x6A4, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat1 on AC6 **/
    {0x38C, 0x60100, {0x6A8, 0, 0}, {0x6AC, 0, 0}, {0x6B0, 0, 0}},   /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat2 on AC9 **/
    {0x390, 0x60100, {0x6B4, 474, 0}, {0x6B8, 0, 0}, {0x6BC, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat3 on AC3 **/
    {0x394, 0x60100, {0x6C0, 792, 0}, {0x6C4, 0, 0}, {0x6C8, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat4 on AC8 **/
    {0x398, 0x60100, {0x6CC, 782, 0}, {0x6D0, 0, 0}, {0x6D4, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat5 on AD6 **/
    {0x39C, 0x60100, {0x6D8, 942, 0}, {0x6DC, 0, 0}, {0x6E0, 0, 0}}, /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat6 on AB8 **/
    {0x3A0, 0x60100, {0x6E4, 636, 0}, {0x6E8, 0, 0}, {0x6EC, 0, 0}} /** MMC3 - Mmc3Sdr25:MMC3_MANUAL1 - mmc3_dat7 on AB5 **/
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (gMmc3Sdr50Pinmux, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t gMmc3Sdr50Pinmux[] = {
#else
const boardPadDelayCfg_t gMmc3Sdr50Pinmux[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
    {0x37C, 0x60100, {0x678, 0, 386}, {0x0, 0, 0}, {0x680, 605, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_clk on AD4 **/
    {0x380, 0x60100, {0x684, 0, 0}, {0x688, 0, 0}, {0x68C, 0, 0}},   /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_cmd on AC4 **/
    {0x384, 0x60100, {0x690, 171, 0}, {0x694, 0, 0}, {0x698, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat0 on AC7 **/
    {0x388, 0x60100, {0x69C, 221, 0}, {0x6A0, 0, 0}, {0x6A4, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat1 on AC6 **/
    {0x38C, 0x60100, {0x6A8, 0, 0}, {0x6AC, 0, 0}, {0x6B0, 0, 0}},   /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat2 on AC9 **/
    {0x390, 0x60100, {0x6B4, 474, 0}, {0x6B8, 0, 0}, {0x6BC, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat3 on AC3 **/
    {0x394, 0x60100, {0x6C0, 792, 0}, {0x6C4, 0, 0}, {0x6C8, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat4 on AC8 **/
    {0x398, 0x60100, {0x6CC, 782, 0}, {0x6D0, 0, 0}, {0x6D4, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat5 on AD6 **/
    {0x39C, 0x60100, {0x6D8, 942, 0}, {0x6DC, 0, 0}, {0x6E0, 0, 0}}, /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat6 on AB8 **/
    {0x3A0, 0x60100, {0x6E4, 636, 0}, {0x6E8, 0, 0}, {0x6EC, 0, 0}} /** MMC3 - Mmc3Sdr50:MMC3_MANUAL1 - mmc3_dat7 on AB5 **/
};

/* Table containing the MMC pad to mode mapping for MMC1 instance. */
mmcBoardPadCfgTable_t gMmc1PinmuxTable[] = {
    {MMC1_DEFAULT_PLB, gMmc1DsPlbPinmux, 6},
    /**< Pad configuration for Default Pad Loopback mode of MMC1. */
    {MMC1_HS_ILB, gMmc1HsIlbPinmux, 6},
    /**< Pad configuration for High speed Internal Loopback mode of MMC1. */
    {MMC1_HS_PLB, gMmc1HsPlbPinmux, 6},
    /**< Pad configuration for High speed Pad Loopback mode of MMC1. */
    {MMC1_SDR12_PLB, gMmc1Sdr12PlbPinmux, 6},
    /**< Pad configuration for SDR12 Pad Loopback mode of MMC1. */
    {MMC1_SDR12_ILB, gMmc1Sdr12IlbPinmux, 6},
    /**< Pad configuration for SDR12 Internal Loopback mode of MMC1. */
    {MMC1_SDR25_ILB, gMmc1Sdr25IlbPinmux, 6},
    /**< Pad configuration for SDR25 Internal Loopback mode of MMC1. */
    {MMC1_SDR50_ILB, gMmc1Sdr50IlbPinmux, 6},
    /**< Pad configuration for SDR50 Internal Loopback mode of MMC1. */
    {MMC1_SDR50_PLB, gMmc1Sdr50PlbPinmux, 6},
    /**< Pad configuration for SDR50 Pad Loopback mode of MMC1. */
    {MMC1_DS_ILB, gMmc1DsIlbPinmux, 6},
    /**< Pad configuration for Default speed Internal Loopback mode of MMC1. */
    {MMC1_DDR50_ILB, gMmc1Ddr50IlbPinmux, 6},
    /**< Pad configuration for DDR50 Internal Loopback mode of MMC1. */
    {MMC1_DDR50_PLB, gMmc1Ddr50PlbPinmux, 6},
    /**< Pad configuration for DDR50 Pad Loopback mode of MMC1. */
    {MMC1_SDR104, gMmc1Sdr104Pinmux, 6},
    /**< Pad configuration for SDR104 mode of MMC1. */
    {MMC_MODE_INVALID, NULL, 0}
    /**< Invalid MMC Mode */
};
/* Table containing the MMC pad to mode mapping for MMC2 instance. */
mmcBoardPadCfgTable_t gMmc2PinmuxTable[] = {
    {MMC2_DEFAULT_HS_PLB, gMmc2HsPlbPinmux, 10},
    /**< Pad configuration for Default High Speed Pad Loopback mode of MMC2. */
    {MMC2_DEFAULT_STD_PLB, gMmc2StdPlbPinmux, 10},
    /**< Pad configuration for Default Standard Pad Loopback mode of MMC2. */
    {MMC2_DDR_ILB, gMmc2DdrIlbPinmux, 10},
    /**< Pad configuration for DDR Internal Loopback mode of MMC2. */
    {MMC2_DDR_PLB, gMmc2DdrPlbPinmux, 10},
    /**< Pad configuration for DDR Pad Loopback mode of MMC2. */
    {MMC2_HS200, gMmc2Hs200Pinmux, 10},
    /**< Pad configuration for HS200 mode of MMC2. */
    {MMC2_STD_ILB, gMmc2StdIlbPinmux, 10},
    /**< Pad configuration for Standard Internal Loopback mode of MMC2. */
    {MMC2_HS_ILB, gMmc2HsIlbPinmux, 10},
    /**< Pad configuration for High speed Internal Loopback mode of MMC2. */
    {MMC_MODE_INVALID, NULL, 0}
    /**< Invalid MMC Mode */
};
/* Table containing the MMC pad to mode mapping for MMC3 instance. */
mmcBoardPadCfgTable_t gMmc3PinmuxTable[] = {
    {MMC3_DS, gMmc3DsPinmux, 10},
    /**< Pad configuration for Default speed mode of MMC3. */
    {MMC3_HS, gMmc3HsPinmux, 10},
    /**< Pad configuration for High speed mode of MMC3. */
    {MMC3_SDR12, gMmc3Sdr12Pinmux, 10},
    /**< Pad configuration for SDR12 mode of MMC3. */
    {MMC3_SDR25, gMmc3Sdr25Pinmux, 10},
    /**< Pad configuration for SDR25 mode of MMC3. */
    {MMC3_SDR50, gMmc3Sdr50Pinmux, 10},
    /**< Pad configuration for SDR50 mode of MMC3. */
    {MMC_MODE_INVALID, NULL, 0}
    /**< Invalid MMC Mode */
};
/* Table containing the MMC pad to mode mapping for MMC4 instance. */
mmcBoardPadCfgTable_t gMmc4PinmuxTable[] = {
    {MMC4_DS, NULL, 0},
    /**< Pad configuration for Default speed mode of MMC4. */
    {MMC4_HS, NULL, 0},
    /**< Pad configuration for High speed mode of MMC4. */
    {MMC4_SDR12, NULL, 0},
    /**< Pad configuration for SDR12 mode of MMC4. */
    {MMC4_SDR25, NULL, 0},
    /**< Pad configuration for SDR25 mode of MMC4. */
    {MMC_MODE_INVALID, NULL, 0}
    /**< Invalid MMC Mode */
};
/* Look up Table containing the list of all Pad configuration structures for
   different operating modes defined for an instance of the MMC device. */
mmcBoardPadCfgTable_t *gMmcPadConfigTable[] = {
    gMmc1PinmuxTable,
    /**< Pointer to the Pad configuration structure of MMC1 instance. */
    gMmc2PinmuxTable,
    /**< Pointer to the Pad configuration structure of MMC2 instance. */
    gMmc3PinmuxTable,
    /**< Pointer to the Pad configuration structure of MMC3 instance. */
    gMmc4PinmuxTable
    /**< Pointer to the Pad configuration structure of MMC4 instance. */
};

mmcBoardPadCfgTable_t *BoardGetMmcCtrlPadPinmuxTable(uint32_t instance)
{
    return (gMmcPadConfigTable[instance]);
}
