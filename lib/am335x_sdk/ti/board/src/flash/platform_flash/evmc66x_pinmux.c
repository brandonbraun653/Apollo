/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file    evmc66x_pinmux.c
 *
 * \brief   This contains C66x specific pin muxing configuration functions.
 *
 ******************************************************************************/

#include "platform_internal.h"

static uint32_t gPinMuxDefault[PADCONFIG_MAX_COUNT] =
{
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG0 default mux mode - GPMCAD0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG1 default mux mode	- GPMCAD1
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG2 default mux mode	- GPMCAD2
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG3 default mux mode	- GPMCAD3
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG4 default mux mode	- GPMCAD4
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG5 default mux mode	- GPMCAD5
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG6 default mux mode	- GPMCAD6
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG7 default mux mode	- GPMCAD7
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG8 default mux mode	- GPMCAD8
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG9 default mux mode	- GPMCAD9
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG10 default mux mode - GPMCAD10
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG11 default mux mode - GPMCAD11
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG12 default mux mode - GPMCAD12
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG13 default mux mode - GPMCAD13
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG14 default mux mode - GPMCAD14
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG15 default mux mode - GPMCAD15
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG16 default mux mode - GPIO0_16 (PRSNT1#)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG17 default mux mode - GPMCADVNALE
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG18 default mux mode - GPMCOENREN
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG19 default mux mode - GPMCWEN
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG20 default mux mode - GPMCBE0NCLE
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG21 default mux mode - GPIO0_21 (DC_BRD_DET)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG22 default mux mode - GPMCWAIT0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG23 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG24 default mux mode - GPMCWPN
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG25 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG26 default mux mode - GPMCCSN0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG27 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG28 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG29 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG30 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG31 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG32 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG33 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG34 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG35 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG36 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG37 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG38 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG39 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG40 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG41 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG42 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG43 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG44 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG45 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG46 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG47 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG48 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG49 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG50 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG51 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG52 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG53 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG54 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG55 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG56 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG57 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG58 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG59 default mux mode - MMC1DAT7
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG60 default mux mode - MMC1DAT6
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG61 default mux mode - MMC1DAT5
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG62 default mux mode - MMC1DAT4
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG63 default mux mode - MMC1DAT3
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG64 default mux mode - MMC1DAT2
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG65 default mux mode - MMC1DAT1
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG66 default mux mode - MMC1DAT0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG67 default mux mode - MMC1CLK
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG68 default mux mode - MMC1CMD
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG69 default mux mode - MMC1SDCD
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG70 default mux mode - MMC1SDWP
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG71 default mux mode - MMC1POW
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG72 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG73 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG74 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG75 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG76 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG77 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG78 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG79 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG80 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG81 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG82 default mux mode - GPIO0_82 (TPS_INT1)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG83 default mux mode - GPIO0_83 (TPS_SLEEP)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG84 default mux mode - GPIO0_84 (SEL_HDMIn_GPIO)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG85 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG86 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG87 default mux mode - GPIO0_87 (SD_LP2996A)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG88 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG89 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG90 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG91 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG92 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG93 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG94 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG95 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG96 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG97 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG98 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG99 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG100 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG101 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG102 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG103 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG104 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG105 default mux mode - SPI1SCS0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG106 default mux mode - SPI1SCS1; Note: This signal (GPIO0_100) is also used as SOC_INT
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG107 default mux mode - SPI1CLK
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG108 default mux mode - SPI1DIN
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG109 default mux mode - SPI1DOUT
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG110 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG111 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG112 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG113 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG114 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG115 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG116 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG117 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG118 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG119 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG120 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG121 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG122 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG123 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG124 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG125 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG126 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG127 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG128 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG129 default mux mode - QSPICLK
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG130 default mux mode - QSPIRCLK
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG131 default mux mode - QSPID0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG132 default mux mode - QSPID1
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG133 default mux mode - QSPID2
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG134 default mux mode - QSPID3
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG135 default mux mode - QSPICSN0
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG136 default mux mode - QSPICSN1
    PADCONFIG_MUX_MODE_SECONDARY,  // PADCONFIG137 default mux mode
    PADCONFIG_MUX_MODE_SECONDARY,  // PADCONFIG138 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG139 default mux mode - GPIO0_108 (SOC_LED0)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG140 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG141 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG142 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG143 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG144 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG145 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG146 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG147 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG148 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG149 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG150 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG151 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG152 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG153 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG154 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG155 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG156 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG157 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG158 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG159 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG160 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG161 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG162 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG163 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG164 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG165 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG166 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG167 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG168 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG169 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG170 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG171 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG172 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG173 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG174 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG175 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG176 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG177 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG178 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG179 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG180 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG181 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG182 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG183 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG184 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG185 default mux mode - GPIO1_11 (SOC_LED1)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG186 default mux mode
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG187 default mux mode - MMC0SDCD (mux: MMC0SDCD/GPIO1_12/MCASP0AXR11)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG188 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG189 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG190 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG191 default mux mode
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG192 default mux mode - MMC0DAT3
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG193 default mux mode - MMC0DAT2
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG194 default mux mode - MMC0DAT1
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG195 default mux mode - MMC0DAT0
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG196 default mux mode - MMC0CLK
    PADCONFIG_MUX_MODE_TERTIARY,  // PADCONFIG197 default mux mode - MMC0CMD
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG198 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG199 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG200 default mux mode
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG201 default mux mode - GPIO1_26 (GPIO_EXP_INT)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG202 default mux mode - GPIO1_27 (SEL_LCDn_GPIO)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG203 default mux mode - GPIO1_28 (SOC_MLB_GPIO2)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG204 default mux mode - GPIO1_29 (SOC_PCIE_WAKEn)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG205 default mux mode - GPIO1_30 (BMC_INT1)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG206 default mux mode - GPIO1_31 (HDMI_INTn)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG207 default mux mode - GPIO1_32 (CS2000_AUX_OUT)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG208 default mux mode - GPIO1_33 (TEMP_INT)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG209 default mux mode - GPIO1_34 (WLAN_IRQ)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG210 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG211 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG212 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG213 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG214 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG215 default mux mode
    //PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG216 default mux mode - GPIO1_41 (FLASH_HOLD)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG216 default mux mode - GPIO1_41 (FLASH_HOLD)
    PADCONFIG_MUX_MODE_QUATERNARY,  // PADCONFIG217 default mux mode - GPIO1_42 (TOUCH_INTn)
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG218 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG219 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG220 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG221 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG222 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG223 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG224 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG225 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG226 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG227 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG228 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG229 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG230 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG231 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG232 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG233 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG234 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG235 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG236 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG237 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG238 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG239 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG240 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG241 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG242 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG243 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG244 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG245 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG246 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG247 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG248 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG249 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG250 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG251 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG252 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG253 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG254 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG255 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG256 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG257 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY,  // PADCONFIG258 default mux mode
    PADCONFIG_MUX_MODE_PRIMARY   // PADCONFIG259 default mux mode
};

/**
 * \brief  Configures default mode for pin muxing in pad config registers
 *
 * \return  none
 */
void pinMuxInit(void)
{
	uint16_t count;

    for (count = 0; count < PADCONFIG_MAX_COUNT; count++)
    {
        plat_pinMuxSetMode(count, (PadCfgMuxMode)gPinMuxDefault[count]);
	}

} //pinMuxInit

/**
 * \brief  Configures pin mux mode of a pad config register
 *
 * \param   padCfgId [IN]    Pad config register Id; 0 - 259
 * \param   muxMode  [IN]    Pad config mux mode
 *
 * \return
 * \n       0  - Mux mode configuration is successful
 * \n      -1  - Invalid parameter
 */
int32_t plat_pinMuxSetMode(uint16_t padCfgId, PadCfgMuxMode muxMode)
{
	volatile Uint32 *padCfgBase;

	if((padCfgId < PADCONFIG_MAX_COUNT) &&
	    (muxMode <= PADCONFIG_MUX_MODE_SENARY))
    {
		/* Unlock the Boot Config */
        CSL_BootCfgUnlockKicker();

	    padCfgBase = &hBootCfg->PADCONFIG0;
	    CSL_FINS(*(padCfgBase + padCfgId), BOOTCFG_PADCONFIG0_MUXMODE, muxMode);

	    return (0);
    }
    else
    {
	    return (-1);
	}

} //plat_pinMuxSetMode

/* Nothing past this point */
